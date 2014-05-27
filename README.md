webscanner
==========

###Descriptioin

A simple website scanning tool.

###How to install

```
	make
	make clean
```

###How to use

* Scanning a website using the default dictionary
```
./webscanner -url [url]
```
* Scanning a website using a designated dictionary
```
./webscanner -url [url] -dict [filepath of the dictionary]
```
* Abort the scanning mission
	press ctrl+c

###Result of the scanning mission

The output file would be saving as a text file named webscanner.out
Of course, you can set the name of the file as you wish.
