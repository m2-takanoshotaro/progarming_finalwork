#include<iostream>
#include<string>
#include<vector>

using namespace std;

string str;
vector<int> v1(7);

template <typename T>
int total(T first, T last) {
	int sum = 0;
	for (T p = first; p != last; ++p) sum += *p;
	return sum;
}


struct Answer {
	int number;
	string answer;
	void answershow();
};

void Answer::answershow(){
	cout << "あなたはパターン" << number << "の" <<answer << "型です。" << endl;
}


//共通の質問1～2
void Q1_2 (int n) {
	auto it = v1.begin();
	if (str == "Yes") {
		*(it + n - 1) = 1;
	}
	else if (str == "No") {
		*(it + n - 1 )= 0;
	}
	else cout << "不正な入力です。最初からやり直してください。\n";
}

//パチンコの質問3～4
void P3_4(int n) {
	auto it = v1.begin();
	if (str == "Yes") {
		*(it + n - 1) = 3;
	}
	else if (str == "No") {
		*(it + n - 1) = 0;
	}
	else cout << "不正な入力です。最初からやり直してください。\n";
}

//競馬の質問5～6
void K5_6(int n) {
	auto it = v1.begin();
	if (str == "Yes") {
		*(it + n - 1) = 12;
	}
	else if (str == "No") {
		*(it + n - 1) = 0;
	}
	else cout << "不正な入力です。最初からやり直してください。\n";
}


int main() {
	Answer A1{ 1,"ギャンブル不向き" };
	Answer A2{ 2,"パチンコ、スロット" };
	Answer A3{ 3,"競馬" };
	Answer A4{ 4,"ギャンブル不向きなお金持ち" };
	Answer A5{ 5,"パチンコ、競馬の両刀" };
	cout << "大学生向けギャンブル適正診断\n";
	//質問1
	cout << "あなたは、感情を抑えるのが苦手ですか。YesかNoで回答し，Enterキーを押してください。\n";
	cin >> str;
	Q1_2(1);
	cout << "次の質問にいきます。\n";
	//質問2
	cout << "あなたは勝負事が好き，または負けず嫌いですか。どちらかでも当てはまっている場合はYes、当てはまらない場合はNoと回答し，Enterキーを押してください。\n";
	cin >> str;
	Q1_2(2);
	cout << "次の質問にいきます。\n";
	//質問3
	cout << "アニメをよく見ますか。YesかNoで回答し，Enterキーを押してください。\n";
	cin >> str;
	P3_4(3);
	cout << "次の質問にいきます。\n";
	//質問4
	cout << "身近にパチンコ、またはスロットが好きな人はいますか。YesかNoで回答し，Enterキーを押してください。\n"; 
	cin >> str;
	P3_4(4);
	cout << "次の質問にいきます。\n";
	//質問5
	cout << "論理的に物事を判断しますか。YesかNoで回答し，Enterキーを押してください。\n";
	cin >> str;
	K5_6(5);
	cout << "次の質問にいきます。\n";
	//質問6
	cout << "身近に競馬が好きな人はいますか。YesかNoで回答し，Enterキーを押してください。\n";
	cin >> str;
	K5_6(6);
	cout << "次の質問にいきます。\n";
	//質問7
	cout << "もし、ギャンブルをするとして，月に使えるお金はいくらくらいですか。数字のみで回答し，Enterキーを押してください。\n";
	int m;
	auto it = v1.begin();
	cin >> m;
	if (m <= 10000) {
		*(it + 6) = 0;
	}
	else if (m > 10000 && m <= 99999) {
		*(it + 6) = 3;
	}
	else if (m > 99999) {
		*(it + 6) = 100;
	}
	else cout << "不正な入力です。最初からやり直してください。\n";
	//結果
	cout << "結果を表示します。\n";
	if (total(v1.begin(), v1.end()) <= 2) {
		A1.answershow();
	}
	else if (total(v1.begin(), v1.end()) > 2 && total(v1.begin(), v1.end()) <= 11) {
		A2.answershow();
	}
	else if (total(v1.begin(), v1.end()) > 11 && total(v1.begin(), v1.end()) < 100) {
		A3.answershow();
	}
	else if (total(v1.begin(), v1.end()) == 100) {
		A4.answershow();
	}
	else if (total(v1.begin(), v1.end()) > 100) {
		A5.answershow();
	}
	else cout << "エラーが発生しました。\n";
	return 0;
}