#include "fecha.h"

void fecha(char f[11]){
    time_t t = time(NULL);
    struct tm tiempoLocal = *localtime(&t);
    char fechaHora[11];
    char *formato = "%d/%m/%Y";
    int bytesEscritos = strftime(fechaHora, sizeof fechaHora, formato, &tiempoLocal);
    strcpy(f, fechaHora);
}
