#include <iostream>
using namespace std;
void LCS(string String1,string String2, int String1Length, int String2Length) {
    int Table[String1Length + 1][String2Length + 1];
    for (int i = 0; i <= String1Length; i++) {
        for (int j = 0; j <= String2Length; j++) {
            if (i == 0 || j == 0)
                Table[i][j] = 0;
            else if (String1[i - 1] == String2[j - 1])
                Table[i][j] = Table[i - 1][j - 1] + 1;
            else
                Table[i][j] = max(Table[i - 1][j], Table[i][j - 1]);
        }
    }
    int index = Table[String1Length][String2Length];
    int max=index;
    char lcs[index + 1];
    int i = String1Length, j = String2Length;
    while (i > 0 && j > 0) {
        if (String1[i - 1] == String2[j - 1]) {
            lcs[index - 1] = String1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (Table[i - 1][j] > Table[i][j - 1])
            i--;
        else
            j--;
    }
    cout << "STRING 1 : " << String1 << "\nSTRING 2 : " << String2 << "\nMax Length: "<<max<<"\nLCS: " << lcs << "\n";
}
int main() {
    string String1;
    string String2;
    cout<<"STRING 1 Enter Your Input: ";
    cin>>String1;
    cout<<"STRING 2 Enter Your Input: ";
    cin>>String2;
    LCS(String1, String2, String1.size(), String2.size());
}
