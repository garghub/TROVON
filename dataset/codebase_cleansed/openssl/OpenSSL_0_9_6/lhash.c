void lh_free(LHASH *lh)
{
unsigned int i;
LHASH_NODE *n,*nn;
if (lh == NULL)
return;
for (i=0; i<lh->num_nodes; i++)
{
n=lh->b[i];
while (n != NULL)
{
nn=n->next;
OPENSSL_free(n);
n=nn;
}
}
OPENSSL_free(lh->b);
OPENSSL_free(lh);
}
void *lh_insert(LHASH *lh, void *data)
{
unsigned long hash;
LHASH_NODE *nn,**rn;
void *ret;
lh->error=0;
if (lh->up_load <= (lh->num_items*LH_LOAD_MULT/lh->num_nodes))
expand(lh);
rn=getrn(lh,data,&hash);
if (*rn == NULL)
{
if ((nn=(LHASH_NODE *)OPENSSL_malloc(sizeof(LHASH_NODE))) == NULL)
{
lh->error++;
return(NULL);
}
nn->data=data;
nn->next=NULL;
#ifndef NO_HASH_COMP
nn->hash=hash;
#endif
*rn=nn;
ret=NULL;
lh->num_insert++;
lh->num_items++;
}
else
{
ret= (*rn)->data;
(*rn)->data=data;
lh->num_replace++;
}
return(ret);
}
void *lh_delete(LHASH *lh, void *data)
{
unsigned long hash;
LHASH_NODE *nn,**rn;
void *ret;
lh->error=0;
rn=getrn(lh,data,&hash);
if (*rn == NULL)
{
lh->num_no_delete++;
return(NULL);
}
else
{
nn= *rn;
*rn=nn->next;
ret=nn->data;
OPENSSL_free(nn);
lh->num_delete++;
}
lh->num_items--;
if ((lh->num_nodes > MIN_NODES) &&
(lh->down_load >= (lh->num_items*LH_LOAD_MULT/lh->num_nodes)))
contract(lh);
return(ret);
}
void *lh_retrieve(LHASH *lh, void *data)
{
unsigned long hash;
LHASH_NODE **rn;
void *ret;
lh->error=0;
rn=getrn(lh,data,&hash);
if (*rn == NULL)
{
lh->num_retrieve_miss++;
return(NULL);
}
else
{
ret= (*rn)->data;
lh->num_retrieve++;
}
return(ret);
}
void lh_doall(LHASH *lh, void (*func)())
{
lh_doall_arg(lh,func,NULL);
}
void lh_doall_arg(LHASH *lh, void (*func)(), void *arg)
{
int i;
LHASH_NODE *a,*n;
for (i=lh->num_nodes-1; i>=0; i--)
{
a=lh->b[i];
while (a != NULL)
{
n=a->next;
func(a->data,arg);
a=n;
}
}
}
static void expand(LHASH *lh)
{
LHASH_NODE **n,**n1,**n2,*np;
unsigned int p,i,j;
unsigned long hash,nni;
lh->num_nodes++;
lh->num_expands++;
p=(int)lh->p++;
n1= &(lh->b[p]);
n2= &(lh->b[p+(int)lh->pmax]);
*n2=NULL;
nni=lh->num_alloc_nodes;
for (np= *n1; np != NULL; )
{
#ifndef NO_HASH_COMP
hash=np->hash;
#else
hash=(*(lh->hash))(np->data);
lh->num_hash_calls++;
#endif
if ((hash%nni) != p)
{
*n1= (*n1)->next;
np->next= *n2;
*n2=np;
}
else
n1= &((*n1)->next);
np= *n1;
}
if ((lh->p) >= lh->pmax)
{
j=(int)lh->num_alloc_nodes*2;
n=(LHASH_NODE **)OPENSSL_realloc(lh->b,
(unsigned int)sizeof(LHASH_NODE *)*j);
if (n == NULL)
{
lh->error++;
lh->p=0;
return;
}
for (i=(int)lh->num_alloc_nodes; i<j; i++)
n[i]=NULL;
lh->pmax=lh->num_alloc_nodes;
lh->num_alloc_nodes=j;
lh->num_expand_reallocs++;
lh->p=0;
lh->b=n;
}
}
static void contract(LHASH *lh)
{
LHASH_NODE **n,*n1,*np;
np=lh->b[lh->p+lh->pmax-1];
lh->b[lh->p+lh->pmax-1]=NULL;
if (lh->p == 0)
{
n=(LHASH_NODE **)OPENSSL_realloc(lh->b,
(unsigned int)(sizeof(LHASH_NODE *)*lh->pmax));
if (n == NULL)
{
lh->error++;
return;
}
lh->num_contract_reallocs++;
lh->num_alloc_nodes/=2;
lh->pmax/=2;
lh->p=lh->pmax-1;
lh->b=n;
}
else
lh->p--;
lh->num_nodes--;
lh->num_contracts++;
n1=lh->b[(int)lh->p];
if (n1 == NULL)
lh->b[(int)lh->p]=np;
else
{
while (n1->next != NULL)
n1=n1->next;
n1->next=np;
}
}
static LHASH_NODE **getrn(LHASH *lh, void *data, unsigned long *rhash)
{
LHASH_NODE **ret,*n1;
unsigned long hash,nn;
int (*cf)();
hash=(*(lh->hash))(data);
lh->num_hash_calls++;
*rhash=hash;
nn=hash%lh->pmax;
if (nn < lh->p)
nn=hash%lh->num_alloc_nodes;
cf=lh->comp;
ret= &(lh->b[(int)nn]);
for (n1= *ret; n1 != NULL; n1=n1->next)
{
#ifndef NO_HASH_COMP
lh->num_hash_comps++;
if (n1->hash != hash)
{
ret= &(n1->next);
continue;
}
#endif
lh->num_comp_calls++;
if ((*cf)(n1->data,data) == 0)
break;
ret= &(n1->next);
}
return(ret);
}
unsigned long lh_strhash(const char *c)
{
unsigned long ret=0;
long n;
unsigned long v;
int r;
if ((c == NULL) || (*c == '\0'))
return(ret);
n=0x100;
while (*c)
{
v=n|(*c);
n+=0x100;
r= (int)((v>>2)^v)&0x0f;
ret=(ret<<r)|(ret>>(32-r));
ret&=0xFFFFFFFFL;
ret^=v*v;
c++;
}
return((ret>>16)^ret);
}
unsigned long lh_num_items(LHASH *lh)
{
return lh ? lh->num_items : 0;
}
