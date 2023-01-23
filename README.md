# Hufzip

![License](https://img.shields.io/github/license/davidsonbrsilva/hufzip.svg) ![Code Size](https://img.shields.io/github/languages/code-size/davidsonbrsilva/hufzip) ![Project Status](https://img.shields.io/badge/status-stopped-red.svg)

[[Ver em Português](README.pt-br.md)]

**Hufzip** is a text file compressor based on Huffman algorithm. It has a didatic character and was built for the sole purpose of learning about file compressing methods. Files compressed with Huffzip have `.hfz` extension.

## Quick Guide

This is a quick guide to how to run Hufzip on Replit.

### Compressing a file

1. Open the [project repl](https://repl.it/@davidsonbrsilva/hufzip);
2. Click "Run" button;
3. With the editor on focus, press `Ctrl` + `Shift` + `P` on Windows and Linux or `Cmd` + `Shift` + `P` on Mac. A text box should open;
4. Search "Open Shell" and click the option that appears.
5. Type the following command on terminal:
```
$ ./main -c "sample/long.txt"
```
Done! If everything went well, a `long.hfz` file was created on `sample` folder.

### Decompressing a file


1. Open the [project repl](https://repl.it/@davidsonbrsilva/hufzip);
2. Click "Run" button;
3. With the editor on focus, press `Ctrl` + `Shift` + `P` on Windows and Linux or `Cmd` + `Shift` + `P` on Mac. A text box should open;
4. Search "Open Shell" and click the option that appears.
5. Type the following command on terminal:
```
$ ./main -c "sample/long.txt"
```
All right! If everything went well, a `long.txt` file was created on `sample` folder.

## Building

No makefile was provided for the project. However, it can be built without major complications. The test was performed with MinGW for Windows 64 bits.

## Usage

### Compressing file

Use `-c` parameter, followed by filepath, to compress it. For instance:
```
$ hufzip -c "sample/long.txt"
```

### Decompressing file

Use `-d` parameter, followed by filepath, to decompress it. For instance:
```
$ hufzip -d "sample/long.hfz"
```

## Support

Send email to <davidsonbruno@outlook.com>.

## License

[MIT](LICENSE.md) Copyright (c) 2019, Davidson Bruno.
