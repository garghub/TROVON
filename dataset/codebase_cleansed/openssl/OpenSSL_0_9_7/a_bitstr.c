int ASN1_BIT_STRING_set(ASN1_BIT_STRING *x, unsigned char *d, int len)
{ return M_ASN1_BIT_STRING_set(x, d, len); }
int i2c_ASN1_BIT_STRING(ASN1_BIT_STRING *a, unsigned char **pp)
{
int ret,j,bits,len;
unsigned char *p,*d;
if (a == NULL) return(0);
len=a->length;
if (len > 0)
{
if (a->flags & ASN1_STRING_FLAG_BITS_LEFT)
{
bits=(int)a->flags&0x07;
}
else
{
for ( ; len > 0; len--)
{
if (a->data[len-1]) break;
}
j=a->data[len-1];
if (j & 0x01) bits=0;
else if (j & 0x02) bits=1;
else if (j & 0x04) bits=2;
else if (j & 0x08) bits=3;
else if (j & 0x10) bits=4;
else if (j & 0x20) bits=5;
else if (j & 0x40) bits=6;
else if (j & 0x80) bits=7;
else bits=0;
}
}
else
bits=0;
ret=1+len;
if (pp == NULL) return(ret);
p= *pp;
*(p++)=(unsigned char)bits;
d=a->data;
memcpy(p,d,len);
p+=len;
if (len > 0) p[-1]&=(0xff<<bits);
*pp=p;
return(ret);
}
ASN1_BIT_STRING *c2i_ASN1_BIT_STRING(ASN1_BIT_STRING **a, unsigned char **pp,
long len)
{
ASN1_BIT_STRING *ret=NULL;
unsigned char *p,*s;
int i;
if (len < 1)
{
i=ASN1_R_STRING_TOO_SHORT;
goto err;
}
if ((a == NULL) || ((*a) == NULL))
{
if ((ret=M_ASN1_BIT_STRING_new()) == NULL) return(NULL);
}
else
ret=(*a);
p= *pp;
i= *(p++);
ret->flags&= ~(ASN1_STRING_FLAG_BITS_LEFT|0x07);
ret->flags|=(ASN1_STRING_FLAG_BITS_LEFT|(i&0x07));
if (len-- > 1)
{
s=(unsigned char *)OPENSSL_malloc((int)len);
if (s == NULL)
{
i=ERR_R_MALLOC_FAILURE;
goto err;
}
memcpy(s,p,(int)len);
s[len-1]&=(0xff<<i);
p+=len;
}
else
s=NULL;
ret->length=(int)len;
if (ret->data != NULL) OPENSSL_free(ret->data);
ret->data=s;
ret->type=V_ASN1_BIT_STRING;
if (a != NULL) (*a)=ret;
*pp=p;
return(ret);
err:
ASN1err(ASN1_F_D2I_ASN1_BIT_STRING,i);
if ((ret != NULL) && ((a == NULL) || (*a != ret)))
M_ASN1_BIT_STRING_free(ret);
return(NULL);
}
int ASN1_BIT_STRING_set_bit(ASN1_BIT_STRING *a, int n, int value)
{
int w,v,iv;
unsigned char *c;
w=n/8;
v=1<<(7-(n&0x07));
iv= ~v;
if (!value) v=0;
a->flags&= ~(ASN1_STRING_FLAG_BITS_LEFT|0x07);
if (a == NULL) return(0);
if ((a->length < (w+1)) || (a->data == NULL))
{
if (!value) return(1);
if (a->data == NULL)
c=(unsigned char *)OPENSSL_malloc(w+1);
else
c=(unsigned char *)OPENSSL_realloc_clean(a->data,
a->length,
w+1);
if (c == NULL) return(0);
if (w+1-a->length > 0) memset(c+a->length, 0, w+1-a->length);
a->data=c;
a->length=w+1;
}
a->data[w]=((a->data[w])&iv)|v;
while ((a->length > 0) && (a->data[a->length-1] == 0))
a->length--;
return(1);
}
int ASN1_BIT_STRING_get_bit(ASN1_BIT_STRING *a, int n)
{
int w,v;
w=n/8;
v=1<<(7-(n&0x07));
if ((a == NULL) || (a->length < (w+1)) || (a->data == NULL))
return(0);
return((a->data[w]&v) != 0);
}
