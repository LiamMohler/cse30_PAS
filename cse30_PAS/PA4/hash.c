extern unsigned long hashFun(unsigned long, unsigned long);

unsigned long hash(char *str) {
	unsigned long hash = 0;
	unsigned int c;
	while ((c = (unsigned char)*str++) != '\0')
		hash = hashFun((unsigned long)c, hash);
		// hash = c + (hash << 6) + (hash << 16) - hash;
		//
		// comment out one of the lines above depending on
		// whether you want to call the assembly function 
		// or use the C code
	return hash;
}
