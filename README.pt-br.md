# Hufzip

![Licença](https://img.shields.io/github/license/davidsonbrsilva/hufzip.svg) ![Tamanho do Código](https://img.shields.io/github/languages/code-size/davidsonbrsilva/hufzip) ![Project Status](https://img.shields.io/badge/status-stopped-red.svg)

[[See in English](README.md)]

**Hufzip** é um compressor de arquivos de texto baseado no algoritmo de Huffman. Possui caráter didático e foi construído com o único propósito de aprendizado sobre métodos de compressão de arquivos. Arquivos comprimidos com Hufzip possuem a extensão `.hfz`.

## Guia rápido

Este é um guia rápido de como executar Hufzip no Replit.

### Compactando um arquivo

1. Acesse o [repl do projeto](https://repl.it/@davidsonbrsilva/hufzip);
2. Clique em "Run";
3. Com o editor de código em foco, pressione `Ctrl` + `Shift` + `P` no Windows e no Linux ou com `Cmd` + `Shift` + `P` no Mac. Uma caixa de texto deve abrir;
4. Pesquise por "Open Shell" e clique na opção que aparecer. Um terminal deve abrir no canto inferior direito;
5. Digite o seguinte comando no terminal:
```
$ ./main -c "sample/long.txt"
```
Pronto! Se ocorreu tudo bem, um arquivo `long.hfz` foi criado na pasta `sample`.

### Descompactando um arquivo

1. Acesse o [repl do projeto](https://repl.it/@davidsonbrsilva/hufzip);
2. Clique em "Run";
3. Com o editor de código em foco, pressione `Ctrl` + `Shift` + `P` no Windows e no Linux ou `Cmd` + `Shift` + `P` no Mac. Uma caixa de texto deve abrir;
4. Pesquise por "Open Shell" e clique na opção que aparecer. Um terminal deve abrir no canto inferior direito;
5. Digite o seguinte comando no terminal:
```
$ ./main -d "sample/long.hfz"
```
Tudo certo! Se ocorreu tudo bem, um arquivo `long.txt` foi criado na pasta `sample`.

## Construindo arquivos binários

Não foi provido nenhum Makefile para o projeto. Porém, ele pode ser compilado sem maiores complicações. O teste foi realizado com MinGW para Windows 64 bits.

## Uso

### Compactando arquivo

Utilize o parâmetro `-c`, seguido do caminho do arquivo, para compactá-lo. Por exemplo:
```
$ hufzip -c "sample/long.txt"
```

### Descompactando arquivo

Utilize o parâmetro `-d`, seguido do caminho do arquivo, para descompactá-lo. Por exemplo:
```
$ hufzip -d "sample/long.hfz"
```

## Suporte

Envie e-mail para <davidsonbruno@outlook.com>.

## Licença

[MIT](LICENSE.md) Copyright (c) 2019, Davidson Bruno.
