# Color Print
This is a command line project for those who want to add some color to their
bash scripts.  
Colors are referenced from [this post](https://jonasjacek.github.io/colors/)
## Getting Started
### prerequisites
cmake boost_1.66.0
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
--rgb <r> <g> <b> : take in integer rgb values
```
future versions:
```
--rgbn <r_norm> <g_norm> <b_norm> : take in normalized rgb values
--hsl <h> <s> <l> : takes in hsl values. Where h is hue in degrees,  
  s and l are numbers between 0 and 1
--name "<xterm_color_name>" : converts color names into color
--hex <hex>
```
## Contributing
It's currently not for pull requests
## Author
microARC
