# MAP3121 - Métodos Numéricos e Aplicações (2020)
  
**Instruções de compilação**

 1. Instale o compilador de linguagem C/C++ disponível em [MINGW](https://osdn.net/projects/mingw/downloads/68260/mingw-get-setup.exe/).
 2. No instalador, selecione os seguintes pacotes:

<div align="center">
	 <img width="752" height="458" src="https://i.imgur.com/7jGYs1n.png">
</div>	 

	 
 3. Clique em *Installation* e selecione *Apply Changes*.
 4. Para adicionar o compilador no PATH do Windows, siga as instruções do [link](https://terminaldeinformacao.com/2015/10/08/como-instalar-e-configurar-o-gcc-no-windows-mingw/).
 5. Coloque os seguintes arquivos em um mesmo diretório:
    - main.cpp
    - Tarefa.h
    - Tarefa.cpp

6. Abra a janela de comando no caminho do diretório.
7. Execute o seguinte comando:  

        g++ -O2 -std=c++14 main.cpp Tarefa.cpp -o EP1.exe
---
**Instruções de uso**

Para todos os itens o programa recebe os valores de N e M. Após execução, serão gerados arquivos texto com as saídas.

<table>
<tr><th>Tarefa 1 </th><th>Tarefa 2</th></tr>
<tr><td>

|   Item   | Arquivos de saída                                                    | 
|:--------:|----------------------------------------------------------------------|
| 1A       | Output1A.txt<br>Output1ATeste.txt<br>Erro1A.txt<br>Erro1ATeste.txt   |
| 1B       | Output1B.txt<br>Erro1B.txt                                           |
| 1C       | Output1C.txt                                                         |

</td><td>

|   Item   | Arquivos de saída                                                    |
|:--------:|----------------------------------------------------------------------|
| 2A  (*)  | Output2A.txt                                                         |
| 2B       | Output2B.txt<br>Erro2B.txt                                           |
| 2C       | Output2C.txt<br>Erro2C.txt                                           |

</td></tr> </table>

(*)
Para o item **2A**, considere um sistema linear na forma matricial **`Ax=b`**, onde **A** é uma matriz simétrica tridiagonal, positiva definida, de tamanho *N-1 x N-1*, **b** é um vetor coluna de dimensão *N-1* e **x** é a solução do sistema. O programa recebe A e b e devolve a solução em um arquivo, para isso, siga os passos abaixo:
- Crie um arquivo de nome `entrada.txt`
- A primeira linha do arquivo deverá conter *N-1* elementos do vetor que representa a diagonal principal da matriz **A**.
- A segunda linha do arquivo deverá conter *N-2* elementos do vetor que representa a subdiagonal principal da matriz **A**.
- A terceira linha do arquivo deverá conter *N-1* elementos do vetor que representa o lado direito da equação, ou seja, o vetor coluna **b**.

Por exemplo, caso queira resolver o seguinte sistema 3x3, deve-se inserir o valor N = 4, e preencher o arquivo de entrada do modo descrito acima. O vetor resposta **x** será impresso no arquivo `Output2A.txt`

<div align="center">
	 <img src="https://i.imgur.com/xBBF5Au.png">
</div>	 

*entrada.txt*

    2 2 2
    -1 -1
    1 0 0

 *Output2A.txt*
 
    7.500000e-001 5.000000e-001 2.500000e-001 