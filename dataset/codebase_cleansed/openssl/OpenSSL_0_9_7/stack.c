STACK *sk_new(int (*c)(const char * const *, const char * const *))
{
STACK *ret;
int i;
if ((ret=(STACK *)OPENSSL_malloc(sizeof(STACK))) == NULL)
goto err;
if ((ret->data=(char **)OPENSSL_malloc(sizeof(char *)*MIN_NODES)) == NULL)
goto err;
for (i=0; i<MIN_NODES; i++)
ret->data[i]=NULL;
ret->comp=c;
ret->num_alloc=MIN_NODES;
ret->num=0;
ret->sorted=0;
return(ret);
err:
if(ret)
OPENSSL_free(ret);
return(NULL);
}
int sk_insert(STACK *st, char *data, int loc)
{
char **s;
if(st == NULL) return 0;
if (st->num_alloc <= st->num+1)
{
s=(char **)OPENSSL_realloc((char *)st->data,
(unsigned int)sizeof(char *)*st->num_alloc*2);
if (s == NULL)
return(0);
st->data=s;
st->num_alloc*=2;
}
if ((loc >= (int)st->num) || (loc < 0))
st->data[st->num]=data;
else
{
int i;
char **f,**t;
f=(char **)st->data;
t=(char **)&(st->data[1]);
for (i=st->num; i>=loc; i--)
t[i]=f[i];
#ifdef undef
memmove( (char *)&(st->data[loc+1]),
(char *)&(st->data[loc]),
sizeof(char *)*(st->num-loc));
#endif
st->data[loc]=data;
}
st->num++;
st->sorted=0;
return(st->num);
}
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
int (*comp_func)(const void *,const void *);
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
comp_func=(int (*)(const void *,const void *))(st->comp);
r=(char **)bsearch(&data,(char *)st->data,
st->num,sizeof(char *), comp_func);
if (r == NULL) return(-1);
i=(int)(r-st->data);
for ( ; i>0; i--)
if ((*st->comp)((const char * const *)&(st->data[i-1]),
(const char * const *)&data) < 0)
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
void sk_pop_free(STACK *st, void (*func)(void *))
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
if (st->data != NULL) OPENSSL_free(st->data);
OPENSSL_free(st);
}
int sk_num(const STACK *st)
{
if(st == NULL) return -1;
return st->num;
}
char *sk_value(const STACK *st, int i)
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
if (st && !st->sorted)
{
int (*comp_func)(const void *,const void *);
comp_func=(int (*)(const void *,const void *))(st->comp);
qsort(st->data,st->num,sizeof(char *), comp_func);
st->sorted=1;
}
}
