// #include "declaration.h"


int InitQueue(SeqQueue * Q)
{
	if (!Q)
		return 1;
	Q->tag = Empty;
	Q->front = Q->rear = 0;
	Q->length = 0;

	return 0;
}

int InputQueue(SeqQueue * Q, char x)
{
	if (Q->front == Q->rear && Q->tag == SOME)
		return FULL;

	Q->elem[Q->rear] = x;
	Q->rear = (Q->rear + 1) % Maxsize;
	Q->length++;
	Q->tag = SOME;
	return SOME;
}

int OutputQueue(SeqQueue * Q, char *x)
{
	if (Q->tag == Empty)
		return Empty;

	*x = Q->elem[Q->front];
	Q->length--;
	Q->front = (Q->front + 1) % Maxsize;

	if (Q->front == Q->rear)
		Q->tag = Empty;

	return SOME;
}

int SizeQueue(SeqQueue * Q) {
    return Q->length;
}