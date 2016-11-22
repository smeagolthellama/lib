#ifndef STDKARLANC_HPP_INCLUDED
#define STDKARLANC_HPP_INCLUDED


///size of a char*
#define CHAR_STAR_SIZE 256

//#define DEBUG

#include <iostream>
#include <cstring>
#include <cstdlib>
#ifdef __linux__
#include "itoa.hpp"
#endif // __linux__
#define gt(n) fgets(n,CHAR_STAR_SIZE,stdin)

using namespace std;

///x eleme [a,b]?
///
bool kozott(int x, int a, int b)
{
	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}

	return(b >= x && x >= a);
}

///a karakterlanc hosszat kuldi vissza.
///
inline int hossz(const char* t)
{
	return strlen(t);
}

///torol a t-bol [pos]...[pos+num]
///
void torles(char*t, const int pos, const int num)
{
	char tmp[CHAR_STAR_SIZE];
	strncpy(tmp, t + pos + num, CHAR_STAR_SIZE);
	strncpy(t + pos, tmp, CHAR_STAR_SIZE);
}

void torles(char*t, const int pos, const int num, int tsize)
{
	char tmp[CHAR_STAR_SIZE];
	strncpy(tmp, t + pos + num, CHAR_STAR_SIZE);
	strncpy(t + pos, tmp, tsize - pos);
}
///beszurja a t-be az in-t, a pos-tol kezdve.
///
void beszur(char* t, const char* in, const int pos)
{
#ifdef DEBUG
	cout << "degug in beszur: t=\"" <<t<<"\" , in=\""<<in<<"\" ,pos="<<pos<<endl;
#endif // DEBUG
		 char c[CHAR_STAR_SIZE];
	strncpy(c, t, pos+1);
#ifdef DEBUG
	cout << "degug in beszur: c\"" <<c<<"\""<<endl;
#endif // DEBUG
		 strncpy(c + pos, in, strlen(in));
#ifdef DEBUG
	cout << "degug in beszur: c\"" <<c<<"\""<<endl;
#endif // DEBUG
		 strncpy(c + pos + strlen(in), t + pos, strlen(t + pos));
#ifdef DEBUG
cout << "degug in beszur: c\"" <<c<<"\""<<endl;
#endif // DEBUG
		 t[strlen(t) + strlen(in)] = 0;
#ifdef DEBUG
cout << "degug in beszur: c\"" <<c<<"\""<<endl;
#endif // DEBUG
		 t[strlen(t) + strlen(in) + 1] = 0;
#ifdef DEBUG
	cout << "degug in beszur: c\"" <<c<<"\""<<endl;
#endif // DEBUG
		 strncpy(t, c, strlen(t) + strlen(in));
#ifdef DEBUG
	cout << "degug in beszur: c\"" <<c<<"\",t:\""<<t<<"\""<<endl;
#endif // DEBUG
}

///keres egy karaktert.
///
int kereschar(const char* t1, const char c)
{
	if(strchr(t1, c) == NULL) {
		return -1;
	}

	return strchr(t1, c) - t1;
}

int keres(char* t1, const char* t2)
{
	int j = 0, i;
	i = kereschar(t1, t2[j]);

	for(j = 0; j < hossz(t2) && i < hossz(t1);) {
		if(kereschar(t1 + i, t2[j + 1]) != i + 1) {
			i++;
			j++;
		} else {
			j = 0;
			i = kereschar(t1 + i, t2[j]);
		}
	}

	if(j == hossz(t2)) {
		return (i - j);
	} else {
		return -1;
	}
}

bool isvowel(const char c)
{
	return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U');
}

///bemasolja a t1be a t2t
///
void atmasol(char * t1, const char * t2)
{
	strcpy(t1, t2);
}
///bemasolja a t1be a t2 elso h karakteret.
void atmasol(char * t1, const char * t2, const int h)
{
	strncpy(t1, t2, h);
	t1[h] = 0;
}

void szavakrabont(int & len, char* c, char szavak[][CHAR_STAR_SIZE], char koz)
{
	int i = 0, j = 0, k = 0;

	while(i < CHAR_STAR_SIZE && j < CHAR_STAR_SIZE && k <= hossz(c)) { //this loop is suposed to put each word in a separate line of szavak
		szavak[i][j] = c[k++];
		j++;

		if(c[k] == koz) {
			szavak[i][j] = 0;
			i++;
			j = 0;
			k++;
		}
	}

	len = j;
}
void szavakrabont(int & len, char* c, char szavak[][CHAR_STAR_SIZE])
{
	szavakrabont(len, c, szavak, ' ');
}


int szavak(char* c, char szok[][CHAR_STAR_SIZE])
{
	int i = 0, k;
	char c1[CHAR_STAR_SIZE];
#ifdef DEBUG
	std::cout << "start of szavak(char *c\"" << c << "\" , char szok[][])\n" << std::endl;
#endif // DEBUG

	while(hossz(c)) {
#ifdef DEBUG
		std::cout << hossz(c) << std::endl;
#endif // DEBUG
		k = kereschar(c, ' ');
#ifdef DEBUG
		std::cout << k << std::endl;
#endif // DEBUG

		if(k == -1) {
			k = hossz(c);
		} else {
			k++;
		}

#ifdef DEBUG
		std::cout << "k: " << k << std::endl;
#endif // DEBUG
		atmasol(c1, c, k);
#ifdef DEBUG
		std::cout << "c1: \"" << c1 << "\",\"" << c << "\"" << std::endl;
#endif // DEBUG
		torles(c, 0, k);
#ifdef DEBUG
		std::cout << k << ' ' << c << std::endl;
#endif // DEBUG
		beszur(szok[i++], c1, 0);
	}

	return i;
}


void crop(char * t){
	torles(t,0,1);
	t[strlen(t)-1]=0;
}


#endif // STDKARLANC_HPP_INCLUDED
