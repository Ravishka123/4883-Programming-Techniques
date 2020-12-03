#include<string>
#include<iostream>
#include<algorithm>

using namespace std;
struct Competitors{
	int win, tie, loss;
	string name;
	int Score;
	int Against;
	
};
bool Comparison(struct Competitors A, struct Competitors B){
	int pointsA, pointsB;
	pointsA = A.win * 3 + A.tie;
	pointsB = B.win * 3 + B.tie;
	if (pointsA > pointsB)
		return true;
	if (pointsB > pointsA)	
	return false;
	if (A.win > B.win)	
	return true;
	if (A.win < B.win)	
	return false;
	if (A.Score - A.Against>B.Score - B.Against)	
	return true;
	if (A.Score - A.Against<B.Score - B.Against)
		return false;
	if (A.Score > B.Score)
		return true;
	if (A.Score < B.Score)
		return false;
	pointsA = A.win + A.tie + A.loss;
	pointsB = B.win + B.tie + B.loss;
	if (pointsA > pointsB)
		return false;
	if (pointsA < pointsB)
		return true;
	for (int i = 0; i < n; i++){ 
		char a = A.name[i];
		char b = B.name[i];
		if (a >= 'A'&&a <= 'Z')
			a += 32;
		if (b >= 'A'&&b <= 'Z')
			b += 32;
		if (a == '\0')
			return true;
		if (b == '\0')	
		return false;
		if (a > b)	
		return false;
		if (a < b)	
		return true;
	}
}
int main(){
	int t;
	cin >> t;
	(void)getchar();
	while (t--){
		struct Competitors T[30];
		string Tournament;
		getline(cin, Tournament);
		int n, g;
		cin >> n;
		(void)getchar();
		for (int i = 0; i < n; i++){
			getline(cin, T[i].name);
			T[i].Against = 0;
			T[i].Score = 0;
			T[i].loss = T[i].tie = T[i].win = 0;
		}
		cin >> g;
		(void)getchar();
		for (int j = 0; j < g; j++){
			int a, AS = 0, BS = 0;
			string R, A, B;
			getline(cin, R);
			for (a = 0; R[a] != '#'; a++)
				A.push_back(R[a]);
			for (a++; R[a] != '@'; a++)	
			AS = AS * 10 + R[a] - '0';
			for (a++; R[a] != '#'; a++)	
			BS = BS * 10 + R[a] - '0';
			for (a++; R[a] != '\0'; a++)
				B.push_back(R[a]);
			for (int k = 0; k < n; k++){
				if (T[k].name == A){
					T[k].Score += AS;
					T[k].Against += BS;
					if (AS > BS)
						T[k].win++;
					if (AS == BS)
						T[k].tie++;
					if (AS < BS)
						T[k].loss++;
				}
				if (T[k].name == B){
					T[k].Score += BS;
					T[k].Against += AS;
					if (AS < BS)
						T[k].win++;
					if (AS == BS)
						T[k].tie++;
					if (AS > BS)
						T[k].loss++;
				}
			}
		}
		sort(T, T + n, Comparison);
		cout << Tournament << endl;
		for (int i = 0; i < n; i++){
			cout << i + 1 << ") " << T[i].name << " " << T[i].win * 3 + T[i].tie << "p, ";
			cout << T[i].win + T[i].loss + T[i].tie << "g (" << T[i].win << "-" << T[i].tie << "-" << T[i].loss << "), ";
			cout << T[i].Score - T[i].Against << "gd (" << T[i].Score << "-" << T[i].Against << ")" << endl;
		}
		if (t != 0)
			cout << endl;
	}
	return 0;
}

