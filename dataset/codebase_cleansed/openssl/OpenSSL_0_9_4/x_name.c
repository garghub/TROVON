int i2d_X509_NAME_ENTRY(X509_NAME_ENTRY *a, unsigned char **pp)
{
M_ASN1_I2D_vars(a);
M_ASN1_I2D_len(a->object,i2d_ASN1_OBJECT);
M_ASN1_I2D_len(a->value,i2d_ASN1_PRINTABLE);
M_ASN1_I2D_seq_total();
M_ASN1_I2D_put(a->object,i2d_ASN1_OBJECT);
M_ASN1_I2D_put(a->value,i2d_ASN1_PRINTABLE);
M_ASN1_I2D_finish();
}
X509_NAME_ENTRY *d2i_X509_NAME_ENTRY(X509_NAME_ENTRY **a, unsigned char **pp,
long length)
{
M_ASN1_D2I_vars(a,X509_NAME_ENTRY *,X509_NAME_ENTRY_new);
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
M_ASN1_D2I_get(ret->object,d2i_ASN1_OBJECT);
M_ASN1_D2I_get(ret->value,d2i_ASN1_PRINTABLE);
ret->set=0;
M_ASN1_D2I_Finish(a,X509_NAME_ENTRY_free,ASN1_F_D2I_X509_NAME_ENTRY);
}
int i2d_X509_NAME(X509_NAME *a, unsigned char **pp)
{
int ret;
if (a == NULL) return(0);
if (a->modified)
{
ret=i2d_X509_NAME_entries(a);
if (ret < 0) return(ret);
}
ret=a->bytes->length;
if (pp != NULL)
{
memcpy(*pp,a->bytes->data,ret);
*pp+=ret;
}
return(ret);
}
static int i2d_X509_NAME_entries(X509_NAME *a)
{
X509_NAME_ENTRY *ne,*fe=NULL;
STACK_OF(X509_NAME_ENTRY) *sk;
BUF_MEM *buf=NULL;
int set=0,r,ret=0;
int i;
unsigned char *p;
int size=0;
sk=a->entries;
for (i=0; i<sk_X509_NAME_ENTRY_num(sk); i++)
{
ne=sk_X509_NAME_ENTRY_value(sk,i);
if (fe == NULL)
{
fe=ne;
size=0;
}
if (ne->set != set)
{
ret+=ASN1_object_size(1,size,V_ASN1_SET);
fe->size=size;
fe=ne;
size=0;
set=ne->set;
}
size+=i2d_X509_NAME_ENTRY(ne,NULL);
}
ret+=ASN1_object_size(1,size,V_ASN1_SET);
if (fe != NULL)
fe->size=size;
r=ASN1_object_size(1,ret,V_ASN1_SEQUENCE);
buf=a->bytes;
if (!BUF_MEM_grow(buf,r)) goto err;
p=(unsigned char *)buf->data;
ASN1_put_object(&p,1,ret,V_ASN1_SEQUENCE,V_ASN1_UNIVERSAL);
set= -1;
for (i=0; i<sk_X509_NAME_ENTRY_num(sk); i++)
{
ne=sk_X509_NAME_ENTRY_value(sk,i);
if (set != ne->set)
{
set=ne->set;
ASN1_put_object(&p,1,ne->size,
V_ASN1_SET,V_ASN1_UNIVERSAL);
}
i2d_X509_NAME_ENTRY(ne,&p);
}
a->modified=0;
return(r);
err:
return(-1);
}
X509_NAME *d2i_X509_NAME(X509_NAME **a, unsigned char **pp, long length)
{
int set=0,i;
int idx=0;
unsigned char *orig;
M_ASN1_D2I_vars(a,X509_NAME *,X509_NAME_new);
orig= *pp;
if (sk_X509_NAME_ENTRY_num(ret->entries) > 0)
{
while (sk_X509_NAME_ENTRY_num(ret->entries) > 0)
X509_NAME_ENTRY_free(
sk_X509_NAME_ENTRY_pop(ret->entries));
}
M_ASN1_D2I_Init();
M_ASN1_D2I_start_sequence();
for (;;)
{
if (M_ASN1_D2I_end_sequence()) break;
M_ASN1_D2I_get_set_type(X509_NAME_ENTRY,ret->entries,
d2i_X509_NAME_ENTRY,
X509_NAME_ENTRY_free);
for (; idx < sk_X509_NAME_ENTRY_num(ret->entries); idx++)
{
sk_X509_NAME_ENTRY_value(ret->entries,idx)->set=set;
}
set++;
}
i=(int)(c.p-orig);
if (!BUF_MEM_grow(ret->bytes,i)) goto err;
memcpy(ret->bytes->data,orig,i);
ret->bytes->length=i;
ret->modified=0;
M_ASN1_D2I_Finish(a,X509_NAME_free,ASN1_F_D2I_X509_NAME);
}
X509_NAME *X509_NAME_new(void)
{
X509_NAME *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,X509_NAME);
if ((ret->entries=sk_X509_NAME_ENTRY_new(NULL)) == NULL)
{ c.line=__LINE__; goto err2; }
M_ASN1_New(ret->bytes,BUF_MEM_new);
ret->modified=1;
return(ret);
M_ASN1_New_Error(ASN1_F_X509_NAME_NEW);
}
X509_NAME_ENTRY *X509_NAME_ENTRY_new(void)
{
X509_NAME_ENTRY *ret=NULL;
ASN1_CTX c;
M_ASN1_New_Malloc(ret,X509_NAME_ENTRY);
ret->object=NULL;
ret->set=0;
M_ASN1_New(ret->value,ASN1_STRING_new);
return(ret);
M_ASN1_New_Error(ASN1_F_X509_NAME_ENTRY_NEW);
}
void X509_NAME_free(X509_NAME *a)
{
if(a == NULL)
return;
BUF_MEM_free(a->bytes);
sk_X509_NAME_ENTRY_pop_free(a->entries,X509_NAME_ENTRY_free);
Free(a);
}
void X509_NAME_ENTRY_free(X509_NAME_ENTRY *a)
{
if (a == NULL) return;
ASN1_OBJECT_free(a->object);
ASN1_BIT_STRING_free(a->value);
Free(a);
}
int X509_NAME_set(X509_NAME **xn, X509_NAME *name)
{
X509_NAME *in;
if (*xn == NULL) return(0);
if (*xn != name)
{
in=X509_NAME_dup(name);
if (in != NULL)
{
X509_NAME_free(*xn);
*xn=in;
}
}
return(*xn != NULL);
}
