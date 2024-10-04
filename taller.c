#include <stdio.h>
#include <string.h>

#define ESTUDIANTES 5
#define ASIGNATURAS 3
#define NOMBRE_MAX 50

int main() {
    float calificaciones[ESTUDIANTES][ASIGNATURAS];
    float promedioEstudiante[ESTUDIANTES], promedioAsignatura[ASIGNATURAS];
    float maxEstudiante[ESTUDIANTES], minEstudiante[ESTUDIANTES];
    float maxAsignatura[ASIGNATURAS], minAsignatura[ASIGNATURAS];
    int aprobados[ASIGNATURAS] = {0};

    char nombresEstudiantes[ESTUDIANTES][NOMBRE_MAX];
    char nombresMaterias[ASIGNATURAS][NOMBRE_MAX];

    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        fgets(nombresEstudiantes[i], NOMBRE_MAX, stdin);
        nombresEstudiantes[i][strcspn(nombresEstudiantes[i], "\n")] = 0;  
    }

    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("Ingrese el nombre de la materia %d: ", j + 1);
        fgets(nombresMaterias[j], NOMBRE_MAX, stdin);
        nombresMaterias[j][strcspn(nombresMaterias[j], "\n")] = 0;  
    }

    for (int i = 0; i < ESTUDIANTES; i++) {
        for (int j = 0; j < ASIGNATURAS; j++) {
            do {
                printf("Nota de %s en %s (0-10): ", nombresEstudiantes[i], nombresMaterias[j]);
                scanf("%f", &calificaciones[i][j]);
                if (calificaciones[i][j] < 0 || calificaciones[i][j] > 10) {
                    printf("Error: la nota debe estar entre 0 y 10. Ingrese nuevamente.\n");
                }
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
        printf("%s: %.2f\n", nombresEstudiantes[i], promedioEstudiante[i]);
    }

    printf("\nPromedio por asignatura:\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("%s: %.2f\n", nombresMaterias[j], promedioAsignatura[j]);
    }

    printf("\nCalificaciones mas altas y bajas por estudiante:\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("%s - Maxima: %.2f, Minima: %.2f\n", nombresEstudiantes[i], maxEstudiante[i], minEstudiante[i]);
    }

    printf("\nCalificaciones mas altas y bajas por asignatura:\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("%s - Maxima: %.2f, Minima: %.2f\n", nombresMaterias[j], maxAsignatura[j], minAsignatura[j]);
    }

    printf("\nAprobados por asignatura:\n");
    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("%s - Aprobados: %d\n", nombresMaterias[j], aprobados[j]);
    }

    printf("\nEstudiantes Aprobados y Reprobados:\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        if (promedioEstudiante[i] >= 6) {
            printf("%s: Aprobado (%.2f)\n", nombresEstudiantes[i], promedioEstudiante[i]);
        } else {
            printf("%s: Reprobado (%.2f)\n", nombresEstudiantes[i], promedioEstudiante[i]);
        }
    }

    return 0;
}