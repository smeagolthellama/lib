#ifndef NUMSTR_HPP_INCLUDED
#define NUMSTR_HPP_INCLUDED
int flip(int a)
{
    int n=0;
    while(a) {
        n=n*10+a%10;
        a/=10;
    }
    return n;
}

int count_str(const char * t,char c)
{
    int i=0,n=0;
    for(i=0; i<strlen(t); i++) {
        if(t[i]==c) {
            n++;
        }
    }
    return n;
}

int bintodec(int a)
{
    int n=0,m=flip(a*10+2);
    while(m!=2) {
        n=n*2+m%10;
        m/=10;
    }
    return n;
}



#endif // NUMSTR_HPP_INCLUDED
