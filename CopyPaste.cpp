#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include"CLIFunctions.h"
using namespace std;

/*
    outline:
    For the main copy command there are 3 baisc things things that we need to workout: 
    1. Reading the command
    2. Extract the content of the file from the specified file
    3. Paste the content into clipboard

    Commands:
    For the time being there is only one command called copy
*/

int main(int argc, char* argv[]){
    string s;
    CLIFunctions C;
    if(argc > 1){
        s = argv[1];
    }
    if(argc == 1 || s == "help"){
        C.help();
    }
    else{
        for(char& c: s){
            c=tolower(c);
        }
        if(s == "copy"){
            int n = argc;
            if(n != 3){
                C.Invalid();
            }
            else{
                string filename = argv[n-1];
                string filepath = C.buildpath(filename);
                // no need to check existence of path
                string text = C.get(filepath);
                C.CopyToClipboard(text);
            }
        }
        else if(s == "cpaste"){
            if(argc != 4){
                C.Invalid();
            }
            else{
                string src = argv[2];
                string destination = argv[3];
                string srcpath = C.buildpath(src);
                string despath = C.buildpath(destination, true);
                string text = C.get(srcpath);
                C.CopyToClipboard(text);
                C.PasteFromClipboard(despath);
            }
        }
        else if(s == "set_dir"){
            C.set_dir();
        }
        else if(s == "set_template_path"){
            C.set_template_path();
        }
        else if(s == "show_source_path"){
            if(argc != 2){
                C.Invalid();
            }
            else{
                C.show_source_path();
            }
        }
        else if(s == "show_template_path"){
            if(argc != 2){
                C.Invalid();
            }
            else{
                C.show_template_path();
            }
        }
        // else if here for more commands
        else{
            cout << "No such command found" << endl;
        }
    }
}