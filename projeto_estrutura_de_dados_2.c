#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRESTADORES 100
#define MAX_CONSUMIDORES 100
#define MAX_SERVICOS 100

// Criacao das structs

typedef struct
{
    char nome[50];
    char endereco_eletronico[100];
    char email[50];
    int telefone;
    char endereco[100];
    char uf[3];
} Prestador;

typedef struct
{
    char nome[50];
    int idade;
    char email[50];
    int telefone;
    char endereco[100];
    char uf[3];
} Consumidor;

typedef struct
{
    char descricao[200];
    char data[30];
    float preco;
} Servico;

Prestador prestadores[MAX_PRESTADORES];
Consumidor consumidores[MAX_CONSUMIDORES];
Servico servicos[MAX_SERVICOS];
int numPrestadores = 0;
int numConsumidores = 0;
int numServicos = 0;

// Dados de exemplo para Consumidores
Consumidor consumidores_exemplo[10] = {
    {"Fabiano", 30, "fabiano22@email.com", 123456789, "72006-552", "SP"},
    {"Hialy", 25, "hialy30@email.com", 987654321, "72006-555", "RJ"},
    {"OSMAN", 40, "osman_lenda20@email.com", 111222333, "72006-777", "MG"},
    {"Matheus", 20, "matheus_danadinho@gmail.com", 121121121, "72006-888", "SP"},
    {"Jose", 10, "jose223@gmail.com", 212212212, "72006-545", "BA"},
    {"Aliodas", 20, "aliodasssz@gmail.com", 321321321, "72006-444", "MG"},
    {"Carlos", 33, "carlos909@gmail.com", 890098890, "72006-111", "DF"},
    {"Cesar", 44, "cesar_corno@gmail.com", 77788899, "72006-898", "RJ"},
    {"Baylao", 23, "baylao002@gmail.com", 456456456, "72006-361", "SP"},
    {"Joao", 21, "jg_infiel@gmail.com", 678678678, "72006-043", "DF"}};

// Dados de exemplo para Prestadores
Prestador prestadores_exemplo[10] = {
    {"Yago", "www.Yagosaliente.com", "yago2@email.com", 933767633, "72006-355", "SP"},
    {"Vinicius", "www.vinivini.com", "vinivini@email.com", 933768987, "72006-235", "RJ"},
    {"Thigas", "www.thigasdoforro.com", "thigasdoforro@email.com", 921213376, "72006-099", "DF"},
    {"Guto_Max", "www.gutomax.com", "gutomax@email.com", 339999330, "72006-211", "BA"},
    {"Joao Marcelo", "www.joaomarcelo2.com", "joaomarcelo2@email.com", 322320099, "72006-122", "MG"},
    {"Lula", "www.lula13.com", "lula13@email.com", 766707667, "72006-331", "MG"},
    {"Bolsonaro", "www.bolsonaro22.com", "bolsonaro22@email.com", 989922234, "72006-565", "TO"},
    {"Jesus", "www.jesus777.com", "jesus777@email.com", 887990022, "72002-552", "RJ"},
    {"Satanas", "www.satanas666.com", "satanas666@email.com", 619921122, "71006-552", "DF"},
    {"Pedro Lucas", "www.pedro3.com", "pedro333@email.com", 923328769, "62006-552", "BA"}
    // Adicione mais dados de exemplo aqui
};

// Dados de exemplo para Servi�os
Servico servicos_exemplo[10] = {
    {"Lava Jato", "01/01/2023", 100.0},
    {"Diarista", "02/01/2023", 150.0},
    {"Jardineiro", "03/01/2023", 120.0},
    {"Piscineiro", "04/01/2023", 200.0},
    {"Motorista", "05/01/2023", 350.0},
    {"Atendente", "06/01/2023", 220.0},
    {"Mecanico", "07/01/2023", 510.0},
    {"Limpador", "08/01/2023", 200.0},
    {"Dev", "09/01/2023", 620.0},
    {"Cientista de Dados", "10/01/2023", 720.0}
    // Adicione mais dados de exemplo aqui
};

// Fun��es
// Listar todos os tipos de servi�os.
void tiposDeServicos()
{
    int i;
    printf("Tipos de Servicos:\n");
    for (i = 0; i < numServicos; i++)
    {
        printf("%s\n", servicos[i].descricao);
    }
}

// Listar todas os clientes.
void todosOsClientes()
{
    int i;
    printf("Clientes:\n");
    for (i = 0; i < numConsumidores; i++)
    {
        printf("%s\n", consumidores[i].nome);
    }
}

// Listar todos os prestadores de servi�os.
void todosOsPrestadores()
{
    int i;
    printf("Prestadores de Servicos:\n");
    for (i = 0; i < numPrestadores; i++)
    {
        printf("%s\n", prestadores[i].nome);
    }
}

// Listar os clientes de um determinado estado.
void clientesEstados(char uf[])
{
    int i;
    printf("Clientes do estado %s:\n", uf);
    for (i = 0; i < numConsumidores; i++)
    {
        if (strcmp(consumidores[i].uf, uf) == 0)
        {
            printf("%s\n", consumidores[i].nome);
        }
    }
}

// Listar os prestadores servi�o de um determinado tipo.
void prestadoresDeTipo(char tipo[])
{
    int i;
    printf("Prestadores de servicos do tipo %s:\n", tipo);
    for (i = 0; i < numPrestadores; i++)
    {
        // Compara��o agora � feita com o campo 'descricao' na estrutura 'Servico'
        if (strcmp(servicos[i].descricao, tipo) == 0)
        {
            printf("Prestador: %s\n", prestadores[i].nome);
            printf("Servico: %s\n", servicos[i].descricao);
            printf("Data: %s\n", servicos[i].data);
            printf("Preco: R$%.2f\n", servicos[i].preco);
            printf("\n");
        }
    }
}

// Apresentar o(s) estado(s) onde est� registrado o servi�o mais caro.
void servicoMaisCaro()
{
    float max_preco = 0;
    char estados[100][3];
    int numEstados = 0, i;
    for (i = 0; i < numServicos; i++)
    {
        if (servicos[i].preco > max_preco)
        {
            max_preco = servicos[i].preco;
            numEstados = 0;
            strcpy(estados[numEstados], prestadores[i].uf);
            numEstados++;
        }
        else if (servicos[i].preco == max_preco)
        {
            strcpy(estados[numEstados], prestadores[i].uf);
            numEstados++;
        }
    }
    printf("Estado(s) com servico mais caro:\n");
    for (i = 0; i < numEstados; i++)
    {
        printf("%s\n", estados[i]);
    }
}

// Listar todos os servi�os em ordem crescente de valor.
void servicoCrescenteValor()
{
    int i, j;

    printf("Servicos em ordem crescente de valor:\n");
    for (i = 0; i < numServicos; i++)
    {
        for (j = i + 1; j < numServicos; j++)
        {
            if (servicos[i].preco > servicos[j].preco)
            {
                Servico temp = servicos[i];
                servicos[i] = servicos[j];
                servicos[j] = temp;
            }
        }
        printf("%s - R$%.2f\n", servicos[i].descricao, servicos[i].preco);
    }
}

// Listar todos os clientes em ordem crescente de nome.
void clientesCrescentenome()
{
    int i, j;
    printf("Clientes em ordem crescente de nome:\n");
    for (i = 0; i < numConsumidores; i++)
    {
        for (j = i + 1; j < numConsumidores; j++)
        {
            if (strcmp(consumidores[i].nome, consumidores[j].nome) > 0)
            {
                Consumidor temp = consumidores[i];
                consumidores[i] = consumidores[j];
                consumidores[j] = temp;
            }
        }
        printf("%s\n", consumidores[i].nome);
    }
}

int main()
{
    // Inser��o dos dados de exemplo nas structs
    memcpy(consumidores, consumidores_exemplo, sizeof(consumidores_exemplo));
    memcpy(prestadores, prestadores_exemplo, sizeof(prestadores_exemplo));
    memcpy(servicos, servicos_exemplo, sizeof(servicos_exemplo));

    // Atualiza��o do n�mero de elementos nas structs
    numConsumidores = sizeof(consumidores_exemplo) / sizeof(consumidores_exemplo[0]);
    numPrestadores = sizeof(prestadores_exemplo) / sizeof(prestadores_exemplo[0]);
    numServicos = sizeof(servicos_exemplo) / sizeof(servicos_exemplo[0]);

    int opcao;
    do
    {
        printf("\nMenu:\n");
        printf("1 - Listar todos os tipos de servicos\n");
        printf("2 - Listar todas os clientes\n");
        printf("3 - Listar todos os prestadores de servicos\n");
        printf("4 - Listar os clientes de um determinado estado\n");
        printf("5 - Listar os prestadores de servico de um determinado tipo\n");
        printf("6 - Apresentar o(s) estado(s) onde esta registrado o servico mais caro\n");
        printf("7 - Listar todos os servicos em ordem crescente de valor\n");
        printf("8 - Listar todos os clientes em ordem crescente de nome\n");
        printf("0 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            tiposDeServicos();
            break;
        case 2:
            todosOsClientes();
            break;
        case 3:
            todosOsPrestadores();
            break;
        case 4:
            printf("Digite o estado: ");
            char uf[3];
            scanf("%s", uf);
            clientesEstados(uf);
            break;
        case 5:
            printf("Digite o tipo de servico: ");
            char tipo[100];
            scanf("%s", tipo);
            prestadoresDeTipo(tipo);
            break;
        case 6:
            servicoMaisCaro();
            break;
        case 7:
            servicoCrescenteValor();
            break;
        case 8:
            clientesCrescentenome();
            break;
        case 0:
            printf("Fechando programa\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (opcao != 0);

    return 0;
}
