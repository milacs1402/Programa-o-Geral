#include <bits/stdc++.h>

using namespace std;

int main(){
    map<int,vector<pair<int,int>>> grafo;
    priority_queue<tuple<int,int,vector<int>>, vector<tuple<int,int,vector<int>>>, greater<tuple<int,int,vector<int>>>> fila;
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
	
	fila.push(make_tuple(0,vi,vector<int>{vi}));
    vector<int> path;
	
	while(!fila.empty()){
		tuple<int,int,vector<int>> aux = fila.top();
		fila.pop();

        vector<int> cur_path = get<2>(aux);
		
		
		if(!visited[get<1>(aux)]){

			if(get<1>(aux) == vf){
				
				resp = get<0>(aux);
                path = cur_path;
				break;
			}
			
			visited[get<1>(aux)] = true;
			
			for(auto x: grafo[get<1>(aux)]){
				if(!visited[x.second]){	
                    vector<int> new_path = cur_path; 
                    new_path.push_back(x.second);
					fila.push({get<0>(aux) + x.first, x.second, new_path});
				}
			}
			
			
		}
		
	}
	
	cout << "O caminho mais curto de " << vi << " ate " << vf << " eh ";
    for (size_t i = 0; i < path.size(); ++i) {
		if (i != path.size() - 1) {
			cout << path[i] << "->";
		} else {
			cout << path[i];
    	}
	}
    cout << " e tem custo " << resp << endl;
	cout << endl;
	cout << "Muito obrigada por usar o Dijkstra!";
	
	}

