void *ASN1_dup(i2d_of_void *i2d, d2i_of_void *d2i, void *x)
{
unsigned char *b,*p;
const unsigned char *p2;
int i;
char *ret;
if (x == NULL) return(NULL);
i=i2d(x,NULL);
b=OPENSSL_malloc(i+10);
if (b == NULL)
{ ASN1err(ASN1_F_ASN1_DUP,ERR_R_MALLOC_FAILURE); return(NULL); }
p= b;
i=i2d(x,&p);
p2= b;
ret=d2i(NULL,&p2,i);
OPENSSL_free(b);
return(ret);
}
void *ASN1_item_dup(const ASN1_ITEM *it, void *x)
{
unsigned char *b = NULL;
const unsigned char *p;
long i;
void *ret;
if (x == NULL) return(NULL);
i=ASN1_item_i2d(x,&b,it);
if (b == NULL)
{ ASN1err(ASN1_F_ASN1_ITEM_DUP,ERR_R_MALLOC_FAILURE); return(NULL); }
p= b;
ret=ASN1_item_d2i(NULL,&p,i, it);
OPENSSL_free(b);
return(ret);
}
