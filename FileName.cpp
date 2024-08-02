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
	cout << "���Ȃ��̓p�^�[��" << number << "��" <<answer << "�^�ł��B" << endl;
}


//���ʂ̎���1�`2
void Q1_2 (int n) {
	auto it = v1.begin();
	if (str == "Yes") {
		*(it + n - 1) = 1;
	}
	else if (str == "No") {
		*(it + n - 1 )= 0;
	}
	else cout << "�s���ȓ��͂ł��B�ŏ������蒼���Ă��������B\n";
}

//�p�`���R�̎���3�`4
void P3_4(int n) {
	auto it = v1.begin();
	if (str == "Yes") {
		*(it + n - 1) = 3;
	}
	else if (str == "No") {
		*(it + n - 1) = 0;
	}
	else cout << "�s���ȓ��͂ł��B�ŏ������蒼���Ă��������B\n";
}

//���n�̎���5�`6
void K5_6(int n) {
	auto it = v1.begin();
	if (str == "Yes") {
		*(it + n - 1) = 12;
	}
	else if (str == "No") {
		*(it + n - 1) = 0;
	}
	else cout << "�s���ȓ��͂ł��B�ŏ������蒼���Ă��������B\n";
}


int main() {
	Answer A1{ 1,"�M�����u���s����" };
	Answer A2{ 2,"�p�`���R�A�X���b�g" };
	Answer A3{ 3,"���n" };
	Answer A4{ 4,"�M�����u���s�����Ȃ�������" };
	Answer A5{ 5,"�p�`���R�A���n�̗���" };
	cout << "��w�������M�����u���K���f�f\n";
	//����1
	cout << "���Ȃ��́A�����}����̂����ł����BYes��No�ŉ񓚂��CEnter�L�[�������Ă��������B\n";
	cin >> str;
	Q1_2(1);
	cout << "���̎���ɂ����܂��B\n";
	//����2
	cout << "���Ȃ��͏��������D���C�܂��͕����������ł����B�ǂ��炩�ł����Ă͂܂��Ă���ꍇ��Yes�A���Ă͂܂�Ȃ��ꍇ��No�Ɖ񓚂��CEnter�L�[�������Ă��������B\n";
	cin >> str;
	Q1_2(2);
	cout << "���̎���ɂ����܂��B\n";
	//����3
	cout << "�A�j�����悭���܂����BYes��No�ŉ񓚂��CEnter�L�[�������Ă��������B\n";
	cin >> str;
	P3_4(3);
	cout << "���̎���ɂ����܂��B\n";
	//����4
	cout << "�g�߂Ƀp�`���R�A�܂��̓X���b�g���D���Ȑl�͂��܂����BYes��No�ŉ񓚂��CEnter�L�[�������Ă��������B\n"; 
	cin >> str;
	P3_4(4);
	cout << "���̎���ɂ����܂��B\n";
	//����5
	cout << "�_���I�ɕ����𔻒f���܂����BYes��No�ŉ񓚂��CEnter�L�[�������Ă��������B\n";
	cin >> str;
	K5_6(5);
	cout << "���̎���ɂ����܂��B\n";
	//����6
	cout << "�g�߂ɋ��n���D���Ȑl�͂��܂����BYes��No�ŉ񓚂��CEnter�L�[�������Ă��������B\n";
	cin >> str;
	K5_6(6);
	cout << "���̎���ɂ����܂��B\n";
	//����7
	cout << "�����A�M�����u��������Ƃ��āC���Ɏg���邨���͂����炭�炢�ł����B�����݂̂ŉ񓚂��CEnter�L�[�������Ă��������B\n";
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
	else cout << "�s���ȓ��͂ł��B�ŏ������蒼���Ă��������B\n";
	//����
	cout << "���ʂ�\�����܂��B\n";
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
	else cout << "�G���[���������܂����B\n";
	return 0;
}