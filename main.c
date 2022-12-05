#include <stdio.h>

// i = cliente
// j = pedido

int opcao();
int montante();
float calcularFrete(float peso, int cidade, int pacotes);
float calcularPeso(int quantidade, int tipo);

void main(void) {
    int quantidade[2][10], i, j = 0, k, produto[2][10], repetir, tipoRelatorio;
    int numCliente, numPedido, cidade[2], totalPedidos[2], menos1t[2][10];
    float frete[2][10], peso[2][10], pesoTotal, pesoCliente[2];

    for (i = 0; i < 2; i++) {
        printf("Cliente %d\n", i + 1);
        printf("\nPara qual cidade o pacote deve ser enviado?");
        printf("\n1 - Palmas");
        printf("\n2 - Porto Nacional\n");
        scanf("%d", &cidade[i]);
        pesoCliente[i] = 0;
        k = 1;
        while(k == 1) {
            printf("\nPedido %d", j + 1);
            produto[i][j] = opcao();
            if(produto[i][j] != 1 && produto[i][j] != 2 && produto[i][j] != 3) {
                printf("\nProduto inválido!");
                break;
            }
            quantidade[i][j] = montante();
            peso[i][j] = calcularPeso(quantidade[i][j], produto[i][j]);
            if (peso[i][j] > 0 && peso[i][j] < 1000) {
                menos1t[i][j] = 1;
            }
            pesoCliente[i] = pesoCliente[i] + peso[i][j];
            frete[i][j] = calcularFrete(peso[i][j], cidade[i], quantidade[i][j]);
            printf("\n\nDeseja realizar mais um pedido?");
            printf("\n1 - Sim");
            printf("\n2 - Não\n");
            scanf("%d", &k);
            if(j == 9) {
                k = 2;
                printf("\nLimite de pedidos atingido!");
                totalPedidos[i] = j + 1;
            } else {
                j++;
            } 
        }
    }

    while (repetir) {
        printf("\n\nDeseja imprimir qual relatorio?");
        printf("\n1 - Por pedido");
        printf("\n2 - Por cliente");
        printf("\n3 - Geral \n");
        scanf("%d", &tipoRelatorio);
        if(tipoRelatorio == 1) {
            printf("\nInsira o numero do cliente e do pedido (na mesma ordem) \n");
            scanf("%d %d", &numCliente, &numPedido);
            if(numCliente > 2 || numPedido > 10) {
                printf("\nCliente ou pedido Invalido!");
                break;
            } else {
                printf("\nCliente %d", numCliente);
                printf("\nPedido %d", numPedido);
                switch (produto[numCliente - 1][numPedido - 1])
                {
                case 1:
                    printf("\nProduto: Argamassa AC3 (20kg)");
                    break;
                case 2:
                    printf("\nProduto: Argamassa AC2 (20kg)");
                    break;
                case 3:
                    printf("\nProduto: Rejunte (5kg)");
                    break;
                default:
                    printf("\nProduto inválido!");
                    break;
                }
                printf("\nQuantidade %d", quantidade[numCliente - 1][numPedido - 1]);
                printf("\nFrete %.2f", frete[numCliente - 1][numPedido - 1]);
            }
        }   
        if (tipoRelatorio == 2) {
                printf("\nInsira o numero do cliente \n");
                scanf("%d", &numCliente);
                if(numCliente > 2) {
                    printf("\nCLiente Invalido!");
                    break;
                } else {
                    printf("\nCliente %d", numCliente);
                    printf("\nMedia de pedidos %.2f", pesoCliente[numCliente - 1] / totalPedidos[numCliente - 1]);
                    printf("\nTotal de pedidos do cliente %d", totalPedidos[numCliente - 1]);
                }
        }
        if(tipoRelatorio == 3) {
            pesoTotal = 0;
            for (i = 0; i < 2; i++) {
                pesoTotal = pesoTotal + pesoCliente[i];
            }
            printf("\nVendidos %.2fkg de produtos", pesoTotal);
            for (i = 0; i < 2; i++) {
                for(j = 0; j < 10; j++) {
                    if(menos1t[i][j] == 1) {
                        printf("\nO pedido %d do Cliente %d tem menos de 1000kg", j + 1, i + 1);
                    }
                }
            }
        }

        printf("\n\nDeseja imprimir outro relatorio?");
        printf("\n1 - Sim");
        printf("\n2 - Não\n");
        scanf("%d", &repetir);
        if(repetir != 1) {
            break;
        }
    } 
}

int opcao() {
    int opcao;

    printf("\nEscolha o produto: ");
    printf("\n1 - Argamassa AC3 (20kg)");
    printf("\n2 - Argamassa AC2 (20kg)");
    printf("\n3 - Rejunte (5kg)\n");
    scanf("%d", &opcao);

    return opcao;
}

int montante() {
    int quantidade;

    printf("\nInforme a quantidade: ");
    scanf("%d", &quantidade);

    return quantidade;
}

float calcularFrete(float peso, int cidade, int pacotes) {
    float frete;
    if(peso <= 1000) {
        if(peso > 2000) {
            frete = 2 * pacotes;
        } else {
            if(cidade == 1) {
                frete = 100;
            } else {
                frete = 200;
            }
        }
    } else {
        frete = 0;
    }

    return frete;
}

float calcularPeso(int quantidade, int tipo) {
    float peso;
    if(tipo == 1 || tipo == 2) {
        peso = quantidade * 20;
    } else {
        peso = quantidade * 5;
    }
    return peso;
}