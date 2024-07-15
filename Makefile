install:./source
	make -C ./Mod
	make -C ./source

clean:
	make clean -C ./Mod
	make clean -C ./source
