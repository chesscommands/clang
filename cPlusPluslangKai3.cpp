#include <iostream>

using namespace std;

void addPointer(int &phoge, int hoge){
	int boo = 200;
//	phoge = boo;	ok
//	phoge = &boo;	err
//	phoge = *boo;	err
//	*phoge = boo;	err
//	*phoge = &boo;	err
//	*phoge = *boo;	err
//	&phoge = boo;	err
//	&phoge = &boo;	err
//	&phoge = *boo;	err
	int *pboo = &boo;
	cout << "*pboo=" << *pboo << endl;
	cout << " pboo=" << pboo << endl;
//	phoge = *pboo;	ok	当たり前
//	&phoge = *pboo;	err
//	*phoge = *pboo;	err
//	phoge = pboo;	err
//	&phoge = pboo;	err
//	*phoge = pboo;	err
//	phoge = &pboo;	err
//	&phoge = &pboo;	err
//	*phoge = &pboo;	err

	cout << " phoge=" << phoge << endl;
	phoge = 300;
	cout << "&phoge=" << &phoge << endl;
	phoge = boo;
}

int main( void ){
	int hoge = 5;

	addPointer( hoge, hoge);
	cout << "main=" << hoge << endl;

	return 0;
}


