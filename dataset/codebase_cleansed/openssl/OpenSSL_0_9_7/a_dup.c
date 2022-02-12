char *ASN1_dup(int (*i2d)(), char *(*d2i)(), char *x)
{
unsigned char *b,*p;
long i;
char *ret;
if (x == NULL) return(NULL);
i=(long)i2d(x,NULL);
b=(unsigned char *)OPENSSL_malloc((unsigned int)i+10);
if (b == NULL)
{ ASN1err(ASN1_F_ASN1_DUP,ERR_R_MALLOC_FAILURE); return(NULL); }
p= b;
i=i2d(x,&p);
p= b;
ret=d2i(NULL,&p,i);
OPENSSL_free(b);
return(ret);
}
void *ASN1_item_dup(const ASN1_ITEM *it, void *x)
{
unsigned char *b = NULL, *p;
long i;
void *ret;
if (x == NULL) return(NULL);
i=ASN1_item_i2d(x,&b,it);
if (b == NULL)
{ ASN1err(ASN1_F_ASN1_DUP,ERR_R_MALLOC_FAILURE); return(NULL); }
p= b;
ret=ASN1_item_d2i(NULL,&p,i, it);
OPENSSL_free(b);
return(ret);
}
