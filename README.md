# MAP3121 - Métodos Numéricos e Aplicações (2020)
  
**Instruções de compilação**

 1. Instale o compilador de linguagem C/C++ disponível em [MINGW](https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/).
 2. No instalador, selecione os seguintes pacotes:

	 ![](https://i.imgur.com/7jGYs1n.png)
 3. Clique em *Installation* e selecione *Apply Changes*.
 4. Para adicionar o compilador no PATH do Windows, siga as instruções do [link](https://terminaldeinformacao.com/2015/10/08/como-instalar-e-configurar-o-gcc-no-windows-mingw/).
 5. Coloque os seguintes arquivos em um mesmo diretório:
    - main.cpp
    - Tarefa.h
    - Tarefa.cpp

6. Abra a janela de comando no caminho do diretório.
7. Execute o seguinte comando:  
    `g++ -O2 -std=c++14 main.cpp Tarefa.cpp -o EP1.exe`
---
**Instruções de uso**

Para todos os itens, exceto o 2A, o programa recebe os valores de N e M. Após execução,
serão gerados arquivos texto com as saídas.

Para o item **2A**, considere um sistema linear na forma matricial **`Ax=b`**, onde **A** é uma matriz simétrica tridiagonal, positiva definida, de tamanho *N-1 x N-1*, **b** é um vetor coluna de dimensão *N-1* e **x** é a solução do sistema. O programa recebe A e b e devolve a solução em um arquivo, para isso, siga os passos abaixo:
- Crie um arquivo de nome `entrada.txt`
- A primeira linha do arquivo deverá conter *N-1* elementos do vetor que representa a diagonal principal da matriz **A**.
- A segunda linha do arquivo deverá conter *N-2* elementos do vetor que representa a subdiagonal principal da matriz **A**.
- A terceira linha do arquivo deverá conter *N-1* elementos do vetor que representa o lado direito da equação, ou seja, o vetor coluna **b**.

Exemplo de um arquivo `entrada.txt`, que representa a equação: 

![](https://i.imgur.com/xBBF5Au.png)

    2 2 2
    -1 -1
    1 0 0
        
