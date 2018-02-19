# Color Print
This is a command line project for those who want to add some color to their
bash scripts.
## Getting Started
### prerequisites
cmake
### installation
```
mkdir build
cd build
cmake ../
make
make install # if you want global installation (might need sudo privileges)
```
### basic usage
```
echo "INFO: check this out" | clrprint -rgb 255 230 20
```
### options
current supported options:
```
-rgb <r> <g> <b> : take in integer rgb values
```
future versions:
```
-rgbn <r_norm> <g_norm> <b_norm> : take in normalized rgb values
-hsl <h> <s> <l> : takes in hsl values
-name "<xterm_color_name>" : converts color names into color
-hex <hex>
```
## Contributing
It's currently not for pull requests
## Author
microARC
