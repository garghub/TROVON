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
