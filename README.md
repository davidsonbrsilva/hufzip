# Hufzip
![Project Status](https://img.shields.io/badge/status-stopped-red.svg?style=popout-square)  

**Hufzip** é um compressor de arquivos de texto baseado no algoritmo de Huffman. Possui caráter didático e foi construído com o único propósito de aprendizado sobre métodos de compressão de arquivos. Arquivos comprimidos com Hufzip possuem a extensão `.hfz`.

## Índice

* [Guia rápido](#qg)
	* [Compactando um arquivo](#qg-compressing)
	* [Descompactando um arquivo](#qg-decompressing)
* [Obtendo cópia local](#lc)
* [Construindo arquivos binários](#bf)
	* [Pré-requisitos](#bf-requirements)
		* [Linux](#bf-requirements-linux)
		* [Windows](#bf-requirements-windows)
	* [Compilando o projeto](#bf-building)
		* [Linux](#bf-building-linux)
		* [Windows](#bf-building-windows)
* [Executando](#rn)
	* [Compactando arquivo](#rn-compressing)
	* [Descompactando arquivo](#rn-decompressing)
* [Suporte](#sp)
* [Contribuição](#ct)
* [Licença](#ls)

## <a name="qg"></a>Guia rápido

Este é um guia rápido de como executar Hufzip no Repl<span>.</span>it.

### <a name="qg-compressing"></a>Compactando um arquivo

1. Acesse o [repl do projeto](https://repl.it/@davidsonbrsilva/hufzip);
2. Com o editor de código em foco, pressione `Ctrl` + `Shift` + `P` no Windows e no Linux ou com `Cmd` + `Shift` + `P` no Mac. Uma caixa de texto deve abrir;
3. Pesquise por "Open Shell" e clique na opção que aparecer. Um terminal deve abrir no canto inferior direito;
4. Digite o seguinte comando no terminal:
```
$ ./main -c "sample/long.txt"
```
Pronto! Se ocorreu tudo bem, um arquivo `long.hfz` foi criado na pasta `sample`.

> **Nota:** '$' é apenas uma convenção que usamos no início de uma linha de comando e não deve ser inserido junto ao comando.

### <a name="qg-decompressing"></a>Descompactando um arquivo

1. Acesse o [repl do projeto](https://repl.it/@davidsonbrsilva/hufzip);
2. Com o editor de código em foco, pressione `Ctrl` + `Shift` + `P` no Windows e no Linux ou com `Cmd` + `Shift` + `P` no Mac. Uma caixa de texto deve abrir;
3. Pesquise por "Open Shell" e clique na opção que aparecer. Um terminal deve abrir no canto inferior direito;
4. Digite o seguinte comando no terminal.
```
$ ./main -d "sample/long.hfz"
```
Tudo certo! Se ocorreu tudo bem, um arquivo `long.txt` foi criado na pasta `sample`.

## <a name="lc"></a>Obtendo cópia local

Considerando que você tem [Git](https://br.atlassian.com/git/tutorials/install-git) instalado em sua máquina, abra o terminal, navegue até a pasta que deseja armazenar o projeto e digite o comando:
```
$ git clone https://github.com/davidsonbrsilva/hufzip.git
```
Caso não use Git, não se preocupe, você também pode clonar este repositório através do botão _Clone or Download_ acima.

## <a name="bf"></a>Construindo arquivos binários

### <a name="bf-requirements"></a>Pré-requisitos

Para construir os arquivos binários do projeto, é necessário baixar um compilador para sua plataforma. Será mostrado aqui o processo de instalação do GCC.

#### <a name="bf-requirements-linux"></a>Linux

Geralmente as distribuições do Linux já vem com o GCC instalado nativamente, então antes de prosseguir, verifique se já não está instalado em seu sistema. Para isso, digite `gcc` no terminal. Você deverá ver uma saída tal como essa:
```
gcc: fatal error: no input files
compilation terminated.
```
Se isso ocorreu, pule essa parte. Do contrário, prossiga com a instalação do GCC no Linux:
```
$ sudo apt-get install gcc
```
Em seguida, instale o compilador de códigos para a linguagem C++:
```
$ sudo apt-get install g++
```

#### <a name="bf-requirements-windows"></a>Windows

[MinGW](http://www.mingw.org) é o pacote de instalação do GCC para Windows. Você pode fazer o download da [versão que preferir](https://sourceforge.net/projects/mingw-w64/files/Toolchain%20sources/Personal%20Builds/mingw-builds/), porém, o processo a seguir mostra como você pode obter a versão [8.1.0](https://sourceforge.net/projects/mingw-w64/files/Toolchain%20sources/Personal%20Builds/mingw-builds/8.1.0/). Ressalta-se que o teste só foi realizado para esta versão.

##### Download

1. Faça o download da versão em [32 bits](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/8.1.0/threads-posix/dwarf/i686-8.1.0-release-posix-dwarf-rt_v6-rev0.7z) ou [64 bits](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/8.1.0/threads-posix/seh/x86_64-8.1.0-release-posix-seh-rt_v6-rev0.7z), conforme o seu sistema operacional;

2. Extraia os arquivos baixados em uma pasta de sua escolha. Sugerimos `C:\MinGW`;

##### Configuração das Variáveis de Ambiente

1. Clique com o botão direito do mouse em *Meu Computador* e em seguida em *Propriedades*;
2. No meu lateral esquerdo, vá até *Configurações Avançadas do Sistema* e depois em *Variáveis de Ambiente...*;
3. Em *Variáveis do Sistema*, selecione a variável *Path* e clique em *Editar...*;
4. Em *Valor da Variável*, posicione o cursor ao final, digite `;` e informe o caminho onde você extraiu o MinGW seguido de `\bin`. Se você seguiu à risca nossas orientações, o caminho completo deve ser `C:\MinGW\bin`;
5. Confirme as alterações clicando em *Ok*.

##### Verificando instalação

No Terminal, digite `gcc` e aperte `Enter`;
```
gcc: fatal error: no input files
compilation terminated.
```
Se estiver vendo algo semelhante à mensagem acima, MinGW foi instalado com sucesso. Senão, repita o processo de instalação.

### <a name="bf-building"></a>Compilando o projeto

Com o Terminal aberto, navegue até a pasta do projeto (a que foi criada dentro do caminho que você especificou quando clonou este repositório, de nome `hufzip`). Compile o projeto com o comando abaixo, dependendo de sua plataforma:

#### <a name="bf-building-linux"></a>Linux
```
$ g++ main.cpp -o hufzip node.cpp list.cpp huff.cpp
```

#### <a name="bf-building-windows"></a>Windows
```
$ g++ main.cpp -o hufzip.exe node.cpp list.cpp huff.cpp
```

## <a name="rn"></a>Executando

No terminal, digite `./hufzip` se estiver no Linux ou `hufzip` no Windows. Se ocorreu tudo bem até agora, você deverá ver a seguinte saída:
```
------------
 Hufzip
 v1.0.0
------------
-h              Show help and exit.
-c (filename)   Compress the specified file.
-d (filename)   Decompress the specified file.
```

### <a name="rn-compressing"></a>Compactando arquivo

Utilize o parâmetro `-c`, seguido do caminho do arquivo, para compactá-lo. Por exemplo:
```
$ hufzip -c "sample/long.txt"
```

### <a name="rn-decompressing"></a>Descompactando arquivo

Utilize o parâmetro `-d`, seguido do caminho do arquivo, para descompactá-lo. Por exemplo:
```
$ hufzip -d "sample/long.hfz"
```

## <a name="sp"></a>Suporte

Envie e-mail para <davidsonbruno@outlook.com>.

## <a name="ct"></a>Contribuição

Por favor, verifique o [Guia de Contribuição](CONTRIBUTING.md).

## <a name="ls"></a>Licença

[MIT](LICENSE.md) Copyright (c) 2019, Davidson Bruno.
