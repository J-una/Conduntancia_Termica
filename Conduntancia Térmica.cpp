#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float convert_w_to_k(float k) {
    return k;
}

float convert_k_to_w(float k) {
    return k;
}

float convert_btuf_to_w(float k){
    return k * 1.730735;
}

float convert_w_to_btuf(float k) {
    return k / 1.8 * 3600 / 1055;
}

float convert_w_to_c(float k) {
    return k;
}

float convert_c_to_w(float k) {
    return k;
}

float convert_btuf_to_c(float k) {
    return k * 1.730735;
}

float convert_c_to_btuf(float k) {
    return k *1.8 * 3600 / 1055;
}
int main() {
	setlocale(LC_ALL, "Portuguese");
    float k, k_new;
    int unit_from, unit_to;

    printf("Digite o valor da condutância térmica: ");
    scanf("%f", &k);

    printf("Selecione a unidade de medida de partida:\n");
    printf("1 - W/K\n");
    printf("2 - W/°C\n");
    printf("3 - BTU/°F·h\n");
    scanf("%d", &unit_from);

    printf("Selecione a unidade de medida de destino:\n");
    printf("1 - W/K\n");
    printf("2 - W/°C\n");
    printf("3 - BTU/°F·h\n");
    scanf("%d", &unit_to);

    if (unit_from == unit_to) {
        printf("O valor é igual em ambas as unidades\n");
        return 0;
    }

    switch (unit_from) {
        case 1:
            switch (unit_to) {
                case 2:
                    k_new = convert_w_to_c(k);
                    printf("%.2f W/K equivale a %.2f W/°C\n", k, k_new);
                    break;
                case 3:
                    k_new = convert_w_to_btuf(k);
                    printf("%.2f W/K equivale a %.2f BTU/°F·h\n", k, k_new);
                    break;
                default:
                    printf("Unidade de medida de destino inválida\n");
                    break;
            }
            break;
        case 2:
            switch (unit_to) {
                case 1:
                    k_new = convert_c_to_w(k);
                    printf("%.2f W/°C equivale a %.2f W/K\n", k, k_new);
                    break;
                case 3:
                    k_new = convert_c_to_w(k);
                    k_new = convert_w_to_btuf(k_new);
                    printf("%.2f W/°C equivale a %.2f BTU/°F·h\n", k, k_new);
                    break;
                default:
                    printf("Unidade de medida de destino inválida\n");
                    break;
            }
            break;
        case 3:
            switch (unit_to) {
                case 1:
                    k_new = convert_btuf_to_w(k);
                    printf("%.2f BTU/°F·h equivale a %.2f W/K\n", k, k_new);
                    break;
                case 2:
                    k_new = convert_btuf_to_w(k);
                    k_new = convert_w_to_c(k_new);
                    printf("%.2f BTU/°F·h equivale a %.2f W/°C\n", k, k_new);
                    break;
                default:
                    printf("Unidade de medida de destino inválida\n");
                    break;
            }
            break;
        default:
            printf("Unidade de medida de partida inválida\n");
            break;
    }

    return 0;
}


                
                
            
    
