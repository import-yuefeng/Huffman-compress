
MyType GetBits(SeqQueue * Q)
{
	MyType i, bits = 0;
	char x;

	for (i = 0; i < 8; i++) {
		if (OutputQueue(Q, &x) != Empty) {
			if ('0' == x)
				bits = bits << 1;
			else
				bits = (bits << 1) | 1;
		} else
			break;
	}
	return bits;
}

void
MaxMinLength(FILE * File, HTNode * ht, char **hc, short NLeaf, MyType * Max,
	     MyType * Min)
{
	int i;
	MyType length;

	*Max = *Min = strlen(hc[0]);
	for (i = 0; i < NLeaf; i++) {
		length = strlen(hc[i]);
		fwrite(&ht[i].ch, sizeof(MyType), 1, File);
		fwrite(&length, sizeof(MyType), 1, File);
		if (length > *Max)
			*Max = length;
		if (length < *Min)
			*Min = length;
	}
}

short CodeToFile(FILE * fp, char **hc, short n, SeqQueue * Q, MyType * length)
{
	int i;
	char *p;
	MyType j, bits;
	short count = 0;

	for (i = 0; i < n; i++)	// 将n个叶子压缩并写入文件
	{
		for (p = hc[i]; '\0' != *p; p++)
			InputQueue(Q, *p);

		while (Q->length > 8) {
			bits = GetBits(Q);
			fputc(bits, fp);
			count++;
		}
	}

	*length = Q->length;
	i = 8 - *length;
	bits = GetBits(Q);
	for (j = 0; j < i; j++)
		bits = bits << 1;
	fputc(bits, fp);
	count++;
	InitQueue(Q);
	return count;
}
