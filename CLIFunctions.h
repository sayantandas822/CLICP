#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
class CLIFunctions{
    private:
    // These are default path values
    string path_def = "C:\\Users\\Sayantan\\OneDrive\\Documents\\CP\\Template";
    string path_destination = "C:\\Users\\Sayantan\\OneDrive\\Documents\\CP";
    public:
    void init_path(){
        ifstream file("configsrc.txt");
        string path;
        getline(file, path);
        if(path.length() > 0){
            path_def = path;
        }
        string path2;
        ifstream file2("configdest.txt");
        getline(file2, path2);
        if(path2.length() > 0){
            path_destination = path2;
        }
    }
    void help(){
        // Implements the help function
        cout << "COPY \t";
        cout << "Copies the content of file in the specified directory" << endl << endl;
        cout << "CPASTE \t";
        cout << "Takes one file from specified source and one file from specified destination" << endl;
        cout << "and copies content of the source to the destination" << endl << endl;
        cout << "SET_DIR \t";
        cout << "sets the destination directory" << endl << endl;
        cout << "SET_TEMPLATE PATH \t";
        cout << "Sets the source directory" << endl << endl;
        cout << "SHOW_SOURCE_PATH \t";
        cout << "Shows the current source path" << endl << endl;
        cout << "SHOW_TEMPLATE_PATH \t";
        cout << "Shows the current destination path" << endl << endl;
        cout << "There might also other functions available. Check the documentation for more information." << endl;
        cout << "How to use it?" << endl;
        cout << "cpy -[command name] [-args]" << endl;
    }
    void Invalid(){
        cout << "Invalid Command" << endl;
    }
    void CopyToClipboard(string& text){
        OpenClipboard(0);
        EmptyClipboard();
        const size_t len = text.length() + 1;
        HGLOBAL h = GlobalAlloc(GMEM_MOVEABLE, len);
        memcpy(GlobalLock(h), text.c_str(), len);
        GlobalUnlock(h);
        SetClipboardData(CF_TEXT, h);
        CloseClipboard();
    }
    string get(string& path){
        // This impelemets the 2nd goal in mentioned in the outline
        ifstream file(path);
        string res, s;
        while(getline(file, s)){
            res += s;
            res.push_back('\n');
        }
        return res;
    }
    string buildpath(string& filename,bool dest=0){
        string res = (dest ? path_destination : path_def) + "\\" + filename;
        return res;
    }

    // Pastes the clipboard data into a file
    void PasteFromClipboard(string& despath){
        OpenClipboard(0);
        HANDLE in = GetClipboardData(CF_TEXT);
        ofstream out(despath);
        out << (char*)in;
        out.close();
        CloseClipboard();
    }    

    // shows the current directory
    void show_source_path(){
        cout << path_def << endl;
    }

    // sets the directory to the specified directory path
    void set_dir(){
        cout << "Enter the destination directory path:" << endl;
        string s;
        cin >> s;
        ofstream out("configdest.txt");
        out << s;
        init_path();
    }

    void set_template_path(){
        cout << "Enter Template path: " << endl;
        string s;
        cin >> s;
        ofstream out("configsrc.txt");
        out << s;
        init_path();
    }

    void show_destination_path(){
        cout << path_destination << endl;
    }
};