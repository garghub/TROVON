char *sk_delete_ptr(STACK *st, char *p)
{
int i;
for (i=0; i<st->num; i++)
if (st->data[i] == p)
return(sk_delete(st,i));
return(NULL);
}
char *sk_delete(STACK *st, int loc)
{
char *ret;
int i,j;
if ((st == NULL) || (st->num == 0) || (loc < 0)
|| (loc >= st->num)) return(NULL);
ret=st->data[loc];
if (loc != st->num-1)
{
j=st->num-1;
for (i=loc; i<j; i++)
st->data[i]=st->data[i+1];
}
st->num--;
return(ret);
}
int sk_find(STACK *st, char *data)
{
char **r;
int i;
int (*comp_func)();
if(st == NULL) return -1;
if (st->comp == NULL)
{
for (i=0; i<st->num; i++)
if (st->data[i] == data)
return(i);
return(-1);
}
sk_sort(st);
if (data == NULL) return(-1);
comp_func=(int (*)())st->comp;
r=(char **)bsearch(&data,(char *)st->data,
st->num,sizeof(char *),FP_ICC comp_func);
if (r == NULL) return(-1);
i=(int)(r-st->data);
for ( ; i>0; i--)
if ((*st->comp)(&(st->data[i-1]),&data) < 0)
break;
return(i);
}
int sk_push(STACK *st, char *data)
{
return(sk_insert(st,data,st->num));
}
int sk_unshift(STACK *st, char *data)
{
return(sk_insert(st,data,0));
}
char *sk_shift(STACK *st)
{
if (st == NULL) return(NULL);
if (st->num <= 0) return(NULL);
return(sk_delete(st,0));
}
char *sk_pop(STACK *st)
{
if (st == NULL) return(NULL);
if (st->num <= 0) return(NULL);
return(sk_delete(st,st->num-1));
}
void sk_zero(STACK *st)
{
if (st == NULL) return;
if (st->num <= 0) return;
memset((char *)st->data,0,sizeof(st->data)*st->num);
st->num=0;
}
void sk_pop_free(STACK *st, void (*func)())
{
int i;
if (st == NULL) return;
for (i=0; i<st->num; i++)
if (st->data[i] != NULL)
func(st->data[i]);
sk_free(st);
}
void sk_free(STACK *st)
{
if (st == NULL) return;
if (st->data != NULL) Free(st->data);
Free(st);
}
int sk_num(STACK *st)
{
if(st == NULL) return -1;
return st->num;
}
char *sk_value(STACK *st, int i)
{
if(st == NULL) return NULL;
return st->data[i];
}
char *sk_set(STACK *st, int i, char *value)
{
if(st == NULL) return NULL;
return (st->data[i] = value);
}
void sk_sort(STACK *st)
{
if (!st->sorted)
{
int (*comp_func)();
comp_func=(int (*)())st->comp;
qsort(st->data,st->num,sizeof(char *),FP_ICC comp_func);
st->sorted=1;
}
}
