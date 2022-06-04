#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>
using namespace std;
int main(){
    string textToCopy;
    char commandString[100];
    char commandString2[100];
    
    string result;
    char namec[150];
    char ennamec[150];
    char stnumc[150];
    int c=0;
    char yn=0;
    FILE *data = fopen("file.txt", "a");
    ifstream fin("file.txt");
    fin.get(yn);
    if(fin.eof()) {
        fin.close();
        ofstream fout("file.txt");
        cout << "hello there. This is Automated Mail Format Formation System for Handong." << endl;
        cout << "Input your Korean name :";
        cin >> namec;
        fout << namec;
        fout << " ";
        cout << "Input your English name :";
        cin >>  ennamec;
        fout << ennamec;
        fout << " ";
        cout << "Input your student number :";
        cin >> stnumc;
        fout << stnumc;
        fout << " ";
        fout.close();
    }
    fclose(data);
    FILE *fp = fopen("file.txt", "r");
    fscanf(fp, "%s %s %s", namec, ennamec, stnumc);
    string name(namec);
    string enname(ennamec);
    string stnumber(stnumc);
    string mail;
    string cname;
    string section;
    string all;
    int i=0;
    char cnameall[15][150]={""};
    char csectionall[15][150]={""};
    char cmailall[15][150]={""};
    printf("hello %s(%s). This is Automated Mail Format Formation System for Handong.\n", name.c_str(), enname.c_str());
    while(1) {
        cout << "1. add data 2. choose data 3. delete data 4. quit : ";
        cin >> c;
        if(c == 1) {
            ofstream fout("impo.txt", ios::app);
            cout << "input mail of professor: ";
            cin >> mail;
	    cin.ignore();
            cout << "input class name: ";
            cin >> cname;
	    cin.ignore();
            cout << "input section of the class: ";
            cin >> section;
	    cin.ignore();
            all = cname + " " + section + " " + mail + "\n";
            fout << all;
            fout.close();
        }
        if(c == 2) {
            FILE* file = fopen("impo.txt", "r");
            i=0;
            cout << "Is it English? (y/n):";
            cin >> yn;
            int what;
            while(feof(file)==0) {
                fscanf(file, "%s %s %s", cnameall[i], csectionall[i], cmailall[i]);
                i++;
            }
            for(int j=0;j<i-1;j++) {
                printf("%d. %s ", j+1, cnameall[j]);
            }
            cout << "\n";
            while(1) {
                cout << "Choose the class :";
                cin >> what;
                cin.ignore();
                string classname(cnameall[what-1]);
                if(what > i-1 || what <= 0) {
                    cout << "No class" << endl;
                    break;
                }
                string email(cmailall[what-1]);
                string section(csectionall[what-1]);
                sprintf(commandString, "echo '%s' | xclip -selection clipboard", email.c_str());
                system(commandString);
                cout << "email copied";
                cin.get();
                if(yn == 'y') {
                    all = "Hello, professor. Im " + stnumber + " " + enname + " of " + classname + " " + section + " class.";
                    
                    
                }
                else if(yn == 'n') {
                    all = "안녕하세요 " + classname + " " + section + "분반 " + stnumber +  " " + name + "입니다.";
                } 
                cout << "Title Format Copied\n";
                sprintf(commandString2, "echo '%s' | xclip -selection clipboard", all.c_str());
                system(commandString2);
                break;
            }
        fclose(file);
        }
        if(c == 3) {
            cout << "what data will you delete? (1. your information, 2. lecture information) :";
            int who=0;
            cin >> who;
            if(who == 1) {
                cout << "really want to delete the data?(y/n) :";
                cin >> yn;
                if(yn =='y') {
                    FILE *de = fopen("file.txt", "w");
                    cout << "data deleted" << endl;
                    fclose(de);
                    return 0;
                }
            }
            if(who == 2) {
                cout << "really want to delete the data?(y/n) :";
                cin >> yn;
                if(yn =='y') {
                    FILE *da = fopen("impo.txt", "w");
                    cout << "data deleted" << endl;
                    fclose(da);
                }
            }
        }
        if(c == 4) return 0;
        if(c < 1 || c > 4) cout << "input again" << endl;
    }    
    fclose(fp);
    return 0;
}
