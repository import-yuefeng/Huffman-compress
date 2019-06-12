// @File:haffman.c
// @Date:2019/04/11
// @Update:2019/05/14
// @Update:2019/06/02
// @Update:2019/06/09
// Author:Cat.1


// #include "declaration.h"

void SelectMinTree(HTNode * ht, int n, int *k)
{
	int i, temp;
	WeightType min;

	for (i = 0; i <= n; i++) {
		if (0 == ht[i].parent) {
			min = ht[i].weight;
			temp = i;
			break;
		}
	}
	for (i++; i <= n; i++) {
		if (0 == ht[i].parent && ht[i].weight < min) {
			min = ht[i].weight;
			temp = i;
		}
	}
	*k = temp;
}

int SortTree(HTNode * ht)
{
	short i, j;
	HTNode tmp;

	for (i = N - 1; i >= 0; i--) {
		for (j = 0; j < i; j++)
			if (ht[j].weight < ht[j + 1].weight) {
				tmp = ht[j];
				ht[j] = ht[j + 1];
				ht[j + 1] = tmp;
			}
	}
	for (i = 0; i < N; i++)
		if (0 == ht[i].weight)
			return i;
	return i;
}

//求哈夫曼0-1字符编码表
char **CrtHuffmanCode(HTNode * ht, short LeafNum)
/*从叶子结点到根，逆向求每个叶子结点对应的哈夫曼编码*/
{
	char *cd, **hc;
	int i, start, p, last;

	hc = (char **)malloc((LeafNum) * sizeof(char *));	/*分配n个编码的头指针 */

	if (1 == LeafNum)	//只有一个叶子节点时 
	{
		hc[0] = (char *)malloc((LeafNum + 1) * sizeof(char));
		strcpy(hc[0], "0");
		return hc;
	}

	cd = (char *)malloc((LeafNum + 1) * sizeof(char));
	cd[LeafNum] = '\0';	/*从右向左逐位存放编码，首先存放编码结束符 */
	for (i = 0; i < LeafNum; i++) {
		start = LeafNum;
		last = i;
		for (p = ht[i].parent; p != 0; p = ht[p].parent) {
			if (ht[p].LChild == last)
				cd[--start] = '0';	/*左分支标0 */
			else
				cd[--start] = '1';	/*右分支标1 */
			last = p;
		}
		hc[i] = (char *)malloc((LeafNum - start) * sizeof(char));
		strcpy(hc[i], &cd[start]);
		//
		printf("%3d号 %3c 码长:%2d;编码:%s\n", ht[i].ch, ht[i].ch,
		       LeafNum - start, &cd[start]);
	}
	free(cd);
	return hc;
}

HTNode *CreatHFM(FILE * fp, short *n, WeightType * FileLength)
{
	HTNode *ht = NULL;
	int i, m, s1, s2;
	MyType ch;

	ht = (HTNode *) malloc(2 * N * sizeof(HTNode));
	if (!ht)
		exit(1);

	for (i = 0; i < N; i++) {
		ht[i].weight = 0;
		ht[i].ch = (MyType) i;
	}

	for (*FileLength = 0; !feof(fp); ++(*FileLength)) {
		ch = fgetc(fp);	
		ht[ch].weight++;
	}
	--(*FileLength);
	*n = SortTree(ht);
	m = *n * 2 - 1;
	if (1 == *n) {
		ht[0].parent = 1;
		return ht;
	} else if (0 > *n)
		return NULL;

	for (i = m - 1; i >= 0; i--) {
		ht[i].LChild = 0;
		ht[i].parent = 0;
		ht[i].RChild = 0;
	}

	for (i = *n; i < m; i++)
	{
		SelectMinTree(ht, i - 1, &s1);
		ht[s1].parent = i;
		ht[i].LChild = s1;

		SelectMinTree(ht, i - 1, &s2);
		ht[s2].parent = i;
		ht[i].RChild = s2;

		ht[i].weight = ht[s1].weight + ht[s2].weight;
	}

	return ht;
}


