//Lucas Gonçalves e Silva
//11811EAU016
//Trabalho 02- Resolução da Torre de Hanoi

//Bibliotecas
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

//Definições 
#define PRINT_HANOI 1
#define ONLY_LETERS 2

class Hanoi {
public:
    std::vector<int> a;
    std::vector<int> b;
    std::vector<int> c;
    int n;

    Hanoi(int n) : n(n) {
        for (int i = n; i > 0; i--) {
            a.push_back(i);
        }
    }

    std::string to_string() {
        std::string s = "";
        unsigned int mx = a.size() > b.size() ? a.size() : b.size();
        mx = mx > c.size() ? mx : c.size();
        for (int i = mx - 1; i >= 0; --i) {
            s += ((i < a.size()) ? std::to_string(a[i]) : " ");
            s += "\t" + ((i < b.size()) ? std::to_string(b[i]) : " ");
            s += "\t" + ((i < c.size()) ? std::to_string(c[i]) : " ");

            s += "\n";
        }
        s += "a\tb\tc";
        return s;
    }

    friend std::ostream &operator<<(std::ostream &os, Hanoi obj) {
        return os << obj.to_string();

    }

    std::string move(char from, char to) {
        from = tolower(from);
        to = tolower(to);
        int aux;
        std::vector<int> *f, *t;
        if (from == to) return "Não é possível mover para o mesmo pino";
        switch (from) {
            case 'a':
                f = &a;
                break;
            case 'b':
                f = &b;
                break;
            case 'c':
                f = &c;
                break;
            default:
                return "Pino nao identificado";

        }
        switch (to) {
            case 'a':
                t = &a;
                break;
            case 'b':
                t = &b;
                break;
            case 'c':
                t = &c;
                break;
            default:
                return "Pino nao identificado";

        }
        if (f->empty())return "Pino sem discos" + std::to_string(from);
        aux = f->at(f->size() - 1);
        if (!t->empty() && aux > t->at(t->size() - 1)) {
            return "Não é possível realizar esse movimento";
        }
        f->pop_back();
        t->push_back(aux);
        char buff[50];
        snprintf(buff, 50, "%% move %c to %c", from, to);
        return std::string(buff);
    }

    bool runing() {
        return c.size() != n;
    }

};

int flags = 0;

void resolveHanoi(Hanoi &h, int altura, char from, char to, char intermediario) {
    if (altura >= 1) {
        resolveHanoi(h, altura - 1, from, intermediario, to);
        if (flags & PRINT_HANOI)
            std::cout << h << std::endl;
        std::string r = h.move(from, to);

        if (flags & ONLY_LETERS)
            std::cout <<r[7]<<" "<<r[12]<< std::endl;
        else
            std::cout << r << std::endl;
        resolveHanoi(h, altura - 1, intermediario, to, from);
    }

}

//Main: execução das funções

int main(int nargs, char **args) {
    int n=0;
    if(nargs >= 2){
        n = atoi(args[1]);
    }else {
        std::cout<<"invalid args\n";
        std::cout<<"call Hanoi n -p -l";
        return -1;
    }
    for(int i=2;i<nargs;i++){
        if(!strcmp(args[i],"-p")){
            flags |= PRINT_HANOI;
        }else if(!strcmp(args[i],"-l")) {
            flags |= ONLY_LETERS;
        }
    }
    Hanoi b(n);
    resolveHanoi(b, b.n, 'a',  'c','b');
    if (flags & PRINT_HANOI)
        std::cout << b << std::endl;

    return 0;
}
