#include <stdio.h>

#define ESTUDIANTES 5
#define ASIGNATURAS 3

int main() {
    float calificaciones[ESTUDIANTES][ASIGNATURAS];
    float promedioEstudiante[ESTUDIANTES], promedioAsignatura[ASIGNATURAS];
    float maxEstudiante[ESTUDIANTES], minEstudiante[ESTUDIANTES];
    float maxAsignatura[ASIGNATURAS], minAsignatura[ASIGNATURAS];
    int aprobados[ASIGNATURAS] = {0};
   
    const char *materias[ASIGNATURAS] = {"Algebra", "Calculo", "Fisica"};
   
    for (int i = 0; i < ESTUDIANTES; i++) {
        for (int j = 0; j < ASIGNATURAS; j++) {
            do {
                printf("Nota estudiante %d en %s (0-10): ", i + 1, materias[j]);
                scanf("%f", &calificaciones[i][j]);
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
    }

    for (int i = 0; i < ESTUDIANTES; i++) {
        float suma = 0;
        maxEstudiante[i] = calificaciones[i][0];
        minEstudiante[i] = calificaciones[i][0];
       
        for (int j = 0; j < ASIGNATURAS; j++) {
            suma += calificaciones[i][j];
            if (calificaciones[i][j] > maxEstudiante[i]) maxEstudiante[i] = calificaciones[i][j];
            if (calificaciones[i][j] < minEstudiante[i]) minEstudiante[i] = calificaciones[i][j];
        }
        promedioEstudiante[i] = suma / ASIGNATURAS;
    }

    for (int j = 0; j < ASIGNATURAS; j++) {
        float suma = 0;
        maxAsignatura[j] = calificaciones[0][j];
        minAsignatura[j] = calificaciones[0][j];
       
        for (int i = 0; i < ESTUDIANTES; i++) {
            suma += calificaciones[i][j];
            if (calificaciones[i][j] > maxAsignatura[j]) maxAsignatura[j] = calificaciones[i][j];
            if (calificaciones[i][j] < minAsignatura[j]) minAsignatura[j] = calificaciones[i][j];
            if (calificaciones[i][j] >= 6) aprobados[j]++;
        }
        promedioAsignatura[j] = suma / ESTUDIANTES;
    }

    printf("\nPromedio por estudiante:\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, promedioEstudiante[i]);
    }

    printf("\nPromedio por asignatura:\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("%s: %.2f\n", materias[j], promedioAsignatura[j]);
    }

    printf("\nCalificaciones mas altas y bajas por estudiante:\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("Estudiante %d - Maxima: %.2f, Minima: %.2f\n", i + 1, maxEstudiante[i], minEstudiante[i]);
    }

    printf("\nCalificaciones mas altas y bajas por asignatura:\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("%s - Maxima: %.2f, Minima: %.2f\n", materias[j], maxAsignatura[j], minAsignatura[j]);
    }

    printf("\nAprobados por asignatura:\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("%s - Aprobados: %d\n", materias[j], aprobados[j]);
    }

    return 0;
}