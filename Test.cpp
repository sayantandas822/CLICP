#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
int main(){
    string path;
    cin >> path;
    ifstream file(path);
    string s;
    while(getline(file, s)){
        cout << s << endl;
    }
    return 0;
}
/* void CopyToClipboard(string& text){
    OpenClipboard(0);
    EmptyClipboard();
    const size_t len = text.length() + 1;
    HGLOBAL h = GlobalAlloc(GMEM_MOVEABLE, len);
    memcpy(GlobalLock(h), text.c_str(), len);
    GlobalUnlock(h);
    SetClipboardData(CF_TEXT, h);
    CloseClipboard();
}
int main(){
    string text="My name is Sayantan";
    CopyToClipboard(text);
    return 0;
} */