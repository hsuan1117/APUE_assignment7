#!/bin/bash
cd /code
xelatex -synctex=1 -interaction=nonstopmode "template.tex"
mv template.pdf Group_20.pdf
rm *.synctex.gz *.out *.log *.aux *.bcf *.run.xml