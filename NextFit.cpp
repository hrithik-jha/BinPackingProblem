#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

struct genome{
	float fitness;
	int bind[33];
	int pos;
}bing[33];

void insertVal(int weight[]){
	// Change file here // Use dynamic variables
	ifstream f2("N1C1W1_N.BPP");
	int val, i = 0, k = 0;
	while(f2 >> val){
		if(i >= 2){
			weight[k] = (int)val;
			//cout << weight[i] << endl;
			k++;
		}
		i++;
	}
	return;
}

int nextfit(int weight[]){
    int c = 0;
    int j = 0;
    int binr = 100;
    int bins[50][50];
	for(int i = 0; i < 50; i++){
        if(binr < weight[i]){
            binr = 100;
			binr = binr - weight[i];
			cout << endl;
			bins[c][j] = 0;
			j = 0;
			cout << weight[i] << "  ";
            ++c;
            bins[c][j] = weight[i];
        }
        else{
            binr = binr - weight[i];
            cout << weight[i] << "  ";
            bins[c][j] = weight[i];
            ++j;
        }
    }
	++c;
	return c;
}

int main(){
    int weight[50];
    int c = 0;
    cout << "Getting values from: " << "N1C1W1_N.BPP";
    insertVal(weight);
	cout << endl;
	for(int i = 0; i < 50; i++){
		c = c + weight[i];
	}
    int binn = c / 100;
    cout << "Bin wise distribution of items in them: \n";
    int binnf = nextfit(weight);
    cout << "\nThe ideal best case is: " << ++binn << endl;
    cout << "The result we get is: " << binnf;
	return 0;
}

