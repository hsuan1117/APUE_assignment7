CC = gcc
CFLAG = -std=c11 -O2 -Wall
TARGET = assignment4
SRCS = assignment4.c
OBJS = assignment4.o

RPT_FILES := report.tex
PDF_FILES := report.pdf

all: clean $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAG) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

- pdf:
	docker run -v $(shell pwd):/code -it --rm --name xelatex-build lfswang/xelatex:latest sh /code/run.sh

clean:
	rm -f $(OBJS) $(TARGET) *.toc *.synctex.gz *.out *.log *.aux *.lot *.lof *.bcf *.run.xml *.pdf