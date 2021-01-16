#include <iostream>
#include <vector>
using namespace std;

const int BUFFOR = 2;

int main() {

  int C;
  cin >> C;
  while(C--){
    int n, m;
    cin >> n >> m;
    vector <vector <bool> > map(n+2*BUFFOR, vector <bool> (m+2*BUFFOR, false));
    int suma = 0;

    for(int i=BUFFOR; i<=n+1; i++){
      string input;
      cin >> input;
      for(int j=BUFFOR; j<=m+1; j++){
        if(input[j-BUFFOR] == 'o'){
          map[i][j] = true;
        }
      }
    }
    n+=2*BUFFOR;
    m+=2*BUFFOR;

    int T;
    cin >> T;
    //for(int t=0; t<T; t++){
    while(T--){
      vector <vector <bool> > newMap(n+2, vector <bool> (m+2, false));
      int count = 0;

      for(int i=1; i<(n-1); i++){
        for(int j=1; j<(m-1); j++){
          
          int neighbors = 0;

          for(int y=-1; y<2; y++){
            for(int x=-1; x<2; x++){
              neighbors += map[i+y][j+x];
            }
          }
          neighbors -= map[i][j];

          if(neighbors == 3 || (map[i][j] && neighbors==2)){
            newMap[i+1][j+1] = true;
            count ++;
          }
        }
      }

      n += 2;
      m += 2;
      map = newMap;
      // // DEBUG CHECK //
      // for(int i=0; i<n; i++){
      //   for(int j=0; j<m; j++){
      //     if(map[i][j]) cerr << 'o';
      //     else cerr << '-';
      //   }
      //   cerr << endl;
      // } ///////////////
      cout << count << "\n";
      if(count == 0){
        //for(int i=t; i<T; i++) cout << 0 << "\n";
        while(T--) cout << 0 << "\n";
      }
    }
  } 
}
