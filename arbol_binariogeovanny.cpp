#include <iostream>
using namespace std;

struct Rama {
    int valor;
    Rama* izquierda;
    Rama* derecha;
};

void mostrarPreorden(Rama* actual) {
    if (actual == NULL) {
        return;
    }

    cout << actual->valor << " ";
    mostrarPreorden(actual->izquierda);
    mostrarPreorden(actual->derecha);
}

void mostrarInorden(Rama* actual) {
    if (actual == NULL) {
        return;
    }

    mostrarInorden(actual->izquierda);
    cout << actual->valor << " ";
    mostrarInorden(actual->derecha);
}

void mostrarPostorden(Rama* actual) {
    if (actual == NULL) {
        return;
    }

    mostrarPostorden(actual->izquierda);
    mostrarPostorden(actual->derecha);
    cout << actual->valor << " ";
}

int main() {

    Rama a = {55, NULL, NULL};
    Rama b = {30, NULL, NULL};
    Rama c = {80, NULL, NULL};
    Rama d = {18, NULL, NULL};
    Rama e = {42, NULL, NULL};
    Rama f = {65, NULL, NULL};
    Rama g = {92, NULL, NULL};
    Rama h = {12, NULL, NULL};
    Rama i = {36, NULL, NULL};

    a.izquierda = &b;
    a.derecha = &c;

    b.izquierda = &d;
    b.derecha = &e;

    c.izquierda = &f;
    c.derecha = &g;

    d.izquierda = &h;
    e.izquierda = &i;

    cout << "ARBOL BINARIO DE 4 NIVELES" << endl;
    cout << endl;

    cout << "            55" << endl;
    cout << "          /    \\" << endl;
    cout << "        30      80" << endl;
    cout << "       /  \\    /  \\" << endl;
    cout << "     18   42  65   92" << endl;
    cout << "    /     /" << endl;
    cout << "  12     36" << endl;

    cout << endl;

    cout << "RECORRIDO PREORDEN: ";
    mostrarPreorden(&a);

    cout << endl;

    cout << "RECORRIDO INORDEN: ";
    mostrarInorden(&a);

    cout << endl;

    cout << "RECORRIDO POSTORDEN: ";
    mostrarPostorden(&a);

    cout << endl;

    return 0;
}