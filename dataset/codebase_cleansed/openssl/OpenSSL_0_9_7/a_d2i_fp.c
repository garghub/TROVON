char *ASN1_d2i_fp(char *(*xnew)(), char *(*d2i)(), FILE *in,
unsigned char **x)
{
BIO *b;
char *ret;
if ((b=BIO_new(BIO_s_file())) == NULL)
{
ASN1err(ASN1_F_ASN1_D2I_FP,ERR_R_BUF_LIB);
return(NULL);
}
BIO_set_fp(b,in,BIO_NOCLOSE);
ret=ASN1_d2i_bio(xnew,d2i,b,x);
BIO_free(b);
return(ret);
}
char *ASN1_d2i_bio(char *(*xnew)(), char *(*d2i)(), BIO *in,
unsigned char **x)
{
BUF_MEM *b = NULL;
unsigned char *p;
char *ret=NULL;
int len;
len = asn1_d2i_read_bio(in, &b);
if(len < 0) goto err;
p=(unsigned char *)b->data;
ret=d2i(x,&p,len);
err:
if (b != NULL) BUF_MEM_free(b);
return(ret);
}
void *ASN1_item_d2i_bio(const ASN1_ITEM *it, BIO *in, void *x)
{
BUF_MEM *b = NULL;
unsigned char *p;
void *ret=NULL;
int len;
len = asn1_d2i_read_bio(in, &b);
if(len < 0) goto err;
p=(unsigned char *)b->data;
ret=ASN1_item_d2i(x,&p,len, it);
err:
if (b != NULL) BUF_MEM_free(b);
return(ret);
}
void *ASN1_item_d2i_fp(const ASN1_ITEM *it, FILE *in, void *x)
{
BIO *b;
char *ret;
if ((b=BIO_new(BIO_s_file())) == NULL)
{
ASN1err(ASN1_F_ASN1_D2I_FP,ERR_R_BUF_LIB);
return(NULL);
}
BIO_set_fp(b,in,BIO_NOCLOSE);
ret=ASN1_item_d2i_bio(it,b,x);
BIO_free(b);
return(ret);
}
static int asn1_d2i_read_bio(BIO *in, BUF_MEM **pb)
{
BUF_MEM *b;
unsigned char *p;
int i;
int ret=-1;
ASN1_CTX c;
int want=HEADER_SIZE;
int eos=0;
#if defined(__GNUC__) && defined(__ia64)
long off=0;
#else
int off=0;
#endif
int len=0;
b=BUF_MEM_new();
if (b == NULL)
{
ASN1err(ASN1_F_ASN1_D2I_BIO,ERR_R_MALLOC_FAILURE);
return -1;
}
ERR_clear_error();
for (;;)
{
if (want >= (len-off))
{
want-=(len-off);
if (!BUF_MEM_grow_clean(b,len+want))
{
ASN1err(ASN1_F_ASN1_D2I_BIO,ERR_R_MALLOC_FAILURE);
goto err;
}
i=BIO_read(in,&(b->data[len]),want);
if ((i < 0) && ((len-off) == 0))
{
ASN1err(ASN1_F_ASN1_D2I_BIO,ASN1_R_NOT_ENOUGH_DATA);
goto err;
}
if (i > 0)
len+=i;
}
p=(unsigned char *)&(b->data[off]);
c.p=p;
c.inf=ASN1_get_object(&(c.p),&(c.slen),&(c.tag),&(c.xclass),
len-off);
if (c.inf & 0x80)
{
unsigned long e;
e=ERR_GET_REASON(ERR_peek_error());
if (e != ASN1_R_TOO_LONG)
goto err;
else
ERR_get_error();
}
i=c.p-p;
off+=i;
if (c.inf & 1)
{
eos++;
want=HEADER_SIZE;
}
else if (eos && (c.slen == 0) && (c.tag == V_ASN1_EOC))
{
eos--;
if (eos <= 0)
break;
else
want=HEADER_SIZE;
}
else
{
want=(int)c.slen;
if (want > (len-off))
{
want-=(len-off);
if (!BUF_MEM_grow_clean(b,len+want))
{
ASN1err(ASN1_F_ASN1_D2I_BIO,ERR_R_MALLOC_FAILURE);
goto err;
}
while (want > 0)
{
i=BIO_read(in,&(b->data[len]),want);
if (i <= 0)
{
ASN1err(ASN1_F_ASN1_D2I_BIO,
ASN1_R_NOT_ENOUGH_DATA);
goto err;
}
len+=i;
want -= i;
}
}
off+=(int)c.slen;
if (eos <= 0)
{
break;
}
else
want=HEADER_SIZE;
}
}
*pb = b;
return off;
err:
if (b != NULL) BUF_MEM_free(b);
return(ret);
}
