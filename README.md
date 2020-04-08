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
