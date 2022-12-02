#include <stdio.h>

// i = cliente
// j = pedido

void main(void) {
    int cliente[2][10][1], i, j = 0, k, l, produto[2][10], quantidade, repetir, tipoRelatorio;
    int numCliente, numPedido, cidade[2], totalPedidos[2], menos1t;
    float frete[2][10], peso[2][10], mediaPedidos, pesoTotal, pesoCliente[2];

    for (i = 0; i < 2; i++) {
        printf("Cliente %d\n", i + 1);
        printf("\nPara qual cidade o pacote deve ser enviado?");
        printf("\n1 - Palmas");
        printf("\n2 - Porto Nacional\n");
        scanf("%d", &cidade[i]);
        pesoCliente[i] = 0;
        while(k = 1) {
            printf("\nPedido %d", j + 1);
            produto[i][j] = opcao();
            if(produto[i][j] != 1 && produto[i][j] != 2 && produto[i][j] != 3) {
                printf("\nProduto inválido!");
                break;
            }
            quantidade = montante();
            cliente[i][j][0] = quantidade;
            peso[i][j] = calcularPeso(produto[i][j], quantidade);
            pesoCliente[i] = pesoCliente[i] + peso[i][j];
            frete[i][j] = calcularFrete(peso[i][j], cidade[i], cliente[i][j][0]);
            printf("\n\nDeseja realizar mais um pedido?");
            printf("\n1 - Sim");
            printf("\n2 - Não\n");
            scanf("%d", &k);
            if(j = 9) {
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
                printf("\nProduto %d", produto[numCliente - 1][numPedido - 1]);
                printf("\nQuantidade %d", cliente[numCliente - 1][numPedido - 1][0]);
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
                    if(peso[i][j] < 1000) {
                        printf("\nO pedido %d do Cliente %d tem menos de 1000kg", j + 1, i + 1);
                    }
                }
            }
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
    if(peso >= 1000) {
        if(peso > 2000) {
            frete = 2 * pacotes;
        } else {
            if(cidade = 1) {
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
    if(tipo == 1 || tipo == 2) {
        return quantidade * 20;
    } else {
        return quantidade * 5;
    }
}