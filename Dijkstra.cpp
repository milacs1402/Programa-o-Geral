#include <bits/stdc++.h>

using namespace std;

int main(){
    map<int,vector<pair<int,int>>> grafo;
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
    vector<bool> visited;
    int n=1, peso, nf=1, vt, vi, vf, resp=0;
    
    
    cout << "Insira as informacoes do grafo. Quando quiser parar, coloque o vertice n como 0." << endl;
    
    cout << "Insira o numero de vertices:";
    cin >> vt;
    cout << endl;
    visited.resize(vt+1, false);
    
    while(n!=0){
    	cout << "Vertice n:";
    	cin >>n;
    	cout << endl;
    	if(n!=0){
	    	cout << "Vertice ao qual n se liga:";
    		cin >> nf;
    		cout << endl;
    		cout << "Peso da aresta:";
	    	cin >> peso;
	    	system("cls");
	    	grafo[n].push_back({peso,nf});
	    	grafo[nf].push_back({peso,n});
		}
	}
	system("cls");
	cout << "Que beleza de grafo!" << endl;
	cout << "Agora digite qual seu vertice inicial:";
	cin >> vi;
	cout << endl << "E para onde voce quer ir? ";
	cin >> vf;
	cout << endl;
	
	fila.push({0, vi});
	
	while(!fila.empty()){
		pair<int,int> aux = fila.top();
		fila.pop();
		
		if(!visited[aux.second]){
			
			if(aux.second == vf){
				
				resp = aux.first;
				break;
			}
			
			visited[aux.second] = true;
			
			for(auto x: grafo[aux.second]){
				if(!visited[x.second]){	
					fila.push({aux.first + x.first, x.second});
				}
			}
			
		}
		
	}
	
	cout << "O caminho mais curto de " << vi << " ate " << vf << " tem custo " << resp << endl;
	cout << "Muito obrigada por usar o Dijkstra!";
	
}
