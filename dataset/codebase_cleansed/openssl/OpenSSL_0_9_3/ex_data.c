int CRYPTO_get_ex_new_index(int idx, STACK **skp, long argl, char *argp,
int (*new_func)(), int (*dup_func)(), void (*free_func)())
{
int ret= -1;
CRYPTO_EX_DATA_FUNCS *a;
MemCheck_off();
if (*skp == NULL)
*skp=sk_new_null();
if (*skp == NULL)
{
CRYPTOerr(CRYPTO_F_CRYPTO_GET_EX_NEW_INDEX,ERR_R_MALLOC_FAILURE);
goto err;
}
a=(CRYPTO_EX_DATA_FUNCS *)Malloc(sizeof(CRYPTO_EX_DATA_FUNCS));
if (a == NULL)
{
CRYPTOerr(CRYPTO_F_CRYPTO_GET_EX_NEW_INDEX,ERR_R_MALLOC_FAILURE);
goto err;
}
a->argl=argl;
a->argp=argp;
a->new_func=new_func;
a->dup_func=dup_func;
a->free_func=free_func;
while (sk_num(*skp) <= idx)
{
if (!sk_push(*skp,NULL))
{
CRYPTOerr(CRYPTO_F_CRYPTO_GET_EX_NEW_INDEX,ERR_R_MALLOC_FAILURE);
Free(a);
goto err;
}
}
sk_set(*skp,idx, (char *)a);
ret=idx;
err:
MemCheck_on();
return(idx);
}
int CRYPTO_set_ex_data(CRYPTO_EX_DATA *ad, int idx, char *val)
{
int i;
if (ad->sk == NULL)
{
if ((ad->sk=sk_new_null()) == NULL)
{
CRYPTOerr(CRYPTO_F_CRYPTO_SET_EX_DATA,ERR_R_MALLOC_FAILURE);
return(0);
}
}
i=sk_num(ad->sk);
while (i <= idx)
{
if (!sk_push(ad->sk,NULL))
{
CRYPTOerr(CRYPTO_F_CRYPTO_SET_EX_DATA,ERR_R_MALLOC_FAILURE);
return(0);
}
i++;
}
sk_set(ad->sk,idx,val);
return(1);
}
char *CRYPTO_get_ex_data(CRYPTO_EX_DATA *ad, int idx)
{
if (ad->sk == NULL)
return(0);
else if (idx >= sk_num(ad->sk))
return(0);
else
return(sk_value(ad->sk,idx));
}
int CRYPTO_dup_ex_data(STACK *meth, CRYPTO_EX_DATA *to,
CRYPTO_EX_DATA *from)
{
int i,j,m,r;
CRYPTO_EX_DATA_FUNCS *mm;
char *from_d;
if (meth == NULL) return(1);
if (from->sk == NULL) return(1);
m=sk_num(meth);
j=sk_num(from->sk);
for (i=0; i<j; i++)
{
from_d=CRYPTO_get_ex_data(from,i);
if (i < m)
{
mm=(CRYPTO_EX_DATA_FUNCS *)sk_value(meth,i);
if (mm->dup_func != NULL)
r=mm->dup_func(to,from,(char **)&from_d,i,
mm->argl,mm->argp);
}
CRYPTO_set_ex_data(to,i,from_d);
}
return(1);
}
void CRYPTO_free_ex_data(STACK *meth, char *obj, CRYPTO_EX_DATA *ad)
{
CRYPTO_EX_DATA_FUNCS *m;
char *ptr;
int i,max;
if (meth != NULL)
{
max=sk_num(meth);
for (i=0; i<max; i++)
{
m=(CRYPTO_EX_DATA_FUNCS *)sk_value(meth,i);
if ((m != NULL) && (m->free_func != NULL))
{
ptr=CRYPTO_get_ex_data(ad,i);
m->free_func(obj,ptr,ad,i,m->argl,m->argp);
}
}
}
if (ad->sk != NULL)
{
sk_free(ad->sk);
ad->sk=NULL;
}
}
void CRYPTO_new_ex_data(STACK *meth, char *obj, CRYPTO_EX_DATA *ad)
{
CRYPTO_EX_DATA_FUNCS *m;
char *ptr;
int i,max;
ad->sk=NULL;
if (meth != NULL)
{
max=sk_num(meth);
for (i=0; i<max; i++)
{
m=(CRYPTO_EX_DATA_FUNCS *)sk_value(meth,i);
if ((m != NULL) && (m->new_func != NULL))
{
ptr=CRYPTO_get_ex_data(ad,i);
m->new_func(obj,ptr,ad,i,m->argl,m->argp);
}
}
}
}
