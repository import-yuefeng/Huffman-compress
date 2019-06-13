// #include "declaration.h"
// #include "haffman.c"
// #include "queue.c"

void Compress(char desFile[80], char rename[])
{
	MyType maxLen, minLen, ch, bits, n, finalLength;
	int i;
	short LeafNum, codeNum;
	WeightType count = 0, Length = 0, FileLength;
	FILE *fp, *compressFile;
	SeqQueue *Q;
	HTNode *ht = NULL;
	char **hc = NULL, **Map = NULL, *p;

	printf("Compressed filename: ");
	scanf("%s", rename);
	if ('\0' == rename[0]) {
		printf("Enter is null!");
		exit(1);
	}

	compressFile = fopen(rename, "wb");
	fp = fopen(desFile, "rb");

	if (!fp || !compressFile) {
		printf("Cannot open file.");
		exit(1);
	}

	ht = CreatHFM(fp, &LeafNum, &FileLength);
	if (!FileLength) {
		fclose(fp);
		fclose(compressFile);
		free(ht);
		return;
	}
	Q = (SeqQueue *) malloc(sizeof(SeqQueue));
	InitQueue(Q);
	// SEEK_SET:文件开头 
	// SEEK_CUR:当前位置 
	// SEEK_END:文件结尾
	hc = CrtHuffmanCode(ht, LeafNum);
	Map = (char **)malloc(N * sizeof(char *));
	if (!Map) {
		printf("MemoryError");
		exit(1);
	}

	for (i = 0; i < N; i++)
		Map[i] = NULL;

	for (i = 0; i < LeafNum; i++)
		Map[(int)(ht[i].ch)] = hc[i];

	fseek(compressFile, sizeof(WeightType) + sizeof(short) + 6 * sizeof(MyType), SEEK_SET);
	MaxMinLength(compressFile, ht, hc, LeafNum, &maxLen, &minLen);

	free(ht);
	codeNum = CodeToFile(compressFile, hc, LeafNum, Q, &finalLength);

	rewind(compressFile);
	fseek(compressFile, sizeof(WeightType) + sizeof(MyType), SEEK_SET);
	fwrite(&LeafNum, sizeof(short), 1, compressFile);
	// LeafNum sum
	fwrite(&maxLen, sizeof(MyType), 1, compressFile);
	// maxLength
	fwrite(&minLen, sizeof(MyType), 1, compressFile);
	// minLength
	fwrite(&codeNum, sizeof(short), 1, compressFile);	
	// 填写叶子编码压多少个
	fwrite(&finalLength, sizeof(MyType), 1, compressFile);
	// finalLength
	//printf("叶子共压：%d个,最后剩%d个\n\n",codeNum,finalLength);

	fseek(compressFile, 2 * LeafNum * sizeof(MyType) + codeNum, SEEK_CUR);
	fseek(fp, 0, SEEK_SET);
	while (count < FileLength) {
		ch = fgetc(fp);    
		++count;
		for (p = Map[ch]; *p != '\0'; p++)
			InputQueue(Q, *p);
		while (Q->length > 8)
		{
			bits = GetBits(Q);
			fputc(bits, compressFile);   
			Length++;
		}
	}
	//最后一个bits ;
	finalLength = Q->length;
	n = 8 - finalLength;
	bits = GetBits(Q);
	for (i = 0; i < n; i++)
		bits = bits << 1;
	fwrite(&bits, sizeof(MyType), 1, compressFile);
	Length++;

	rewind(compressFile);
	fwrite(&Length, sizeof(WeightType), 1, compressFile);
	fwrite(&finalLength, sizeof(char), 1, compressFile);

	fclose(fp);
	fclose(compressFile);
	free(Q);
	free(hc);
	free(Map);
}
