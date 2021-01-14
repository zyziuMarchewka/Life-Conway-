#include <iostream>
#include <vector>
using namespace std;

const int BUFFOR = 2;

struct Cartograph {
  int nmost;
  int smost;
  int wmost;
  int emost;

  Cartograph(int n, int m) {
    nmost = n;
    smost = 0;

    wmost = m;
    emost = 0;
  }

  void reset(int n, int m){
    nmost = n;
    smost = 0;

    wmost = m;
    emost = 0;
  }

  void update(int i, int j, int difY, int difX){
    if(i<(nmost+difY)) nmost=i;
    if(i>(smost+difY)) smost=i;
    if(j<(wmost+difX)) wmost=j;
    if(j>(emost+difX)) emost=j;
  }
};

int main() {

  int C;
  cin >> C;
  while(C--){
    int n, m;
    cin >> n >> m;
    vector <vector <bool> > map(n+2*BUFFOR, vector <bool> (m+2*BUFFOR, false));
    int suma = 0;

    Cartograph cartograph(n+2*BUFFOR, m+2*BUFFOR);
    for(int i=BUFFOR; i<=n+1; i++){
      string input;
      cin >> input;
      for(int j=BUFFOR; j<=m+1; j++){
        if(input[j-BUFFOR] == 'o'){
          map[i][j] = true;
          cartograph.update(i, j, 0, 0);
        }
      }
    }
    n+=2*BUFFOR;
    m+=2*BUFFOR;

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
      int difY = (cartograph.nmost-2)*(-1);
      int difX = (cartograph.wmost-2)*(-1);

      int nNew = cartograph.smost-cartograph.nmost+1+2*BUFFOR;
      int mNew = cartograph.emost-cartograph.wmost+1+2*BUFFOR;

      cartograph.reset(nNew, mNew);

      vector <vector <bool> > newMap(nNew, vector <bool> (mNew, false));

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
            newMap[i+difY][j+difX] = true;
            cartograph.update(i, j, difY, difX);
            count ++;
          }
        }
      }

      n = nNew;
      m = mNew;
      map = newMap;
      // DEBUG CHECK //
      for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
          if(map[i][j]) cerr << 'o';
          else cerr << '-';
        }
        cerr << endl;
      } ///////////////
      cout << count << "\n";
    }
  } 
}
