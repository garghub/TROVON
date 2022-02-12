int i2d_ASN1_BIT_STRING(ASN1_BIT_STRING *a, unsigned char **pp)
{
int ret,j,r,bits,len;
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
r=ASN1_object_size(0,ret,V_ASN1_BIT_STRING);
if (pp == NULL) return(r);
p= *pp;
ASN1_put_object(&p,0,ret,V_ASN1_BIT_STRING,V_ASN1_UNIVERSAL);
*(p++)=(unsigned char)bits;
d=a->data;
memcpy(p,d,len);
p+=len;
if (len > 0) p[-1]&=(0xff<<bits);
*pp=p;
return(r);
}
ASN1_BIT_STRING *d2i_ASN1_BIT_STRING(ASN1_BIT_STRING **a, unsigned char **pp,
long length)
{
ASN1_BIT_STRING *ret=NULL;
unsigned char *p,*s;
long len;
int inf,tag,xclass;
int i;
if ((a == NULL) || ((*a) == NULL))
{
if ((ret=ASN1_BIT_STRING_new()) == NULL) return(NULL);
}
else
ret=(*a);
p= *pp;
inf=ASN1_get_object(&p,&len,&tag,&xclass,length);
if (inf & 0x80)
{
i=ASN1_R_BAD_OBJECT_HEADER;
goto err;
}
if (tag != V_ASN1_BIT_STRING)
{
i=ASN1_R_EXPECTING_A_BIT_STRING;
goto err;
}
if (len < 1) { i=ASN1_R_STRING_TOO_SHORT; goto err; }
i= *(p++);
ret->flags&= ~(ASN1_STRING_FLAG_BITS_LEFT|0x07);
ret->flags|=(ASN1_STRING_FLAG_BITS_LEFT|(i&0x07));
if (len-- > 1)
{
s=(unsigned char *)Malloc((int)len);
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
if (ret->data != NULL) Free((char *)ret->data);
ret->data=s;
ret->type=V_ASN1_BIT_STRING;
if (a != NULL) (*a)=ret;
*pp=p;
return(ret);
err:
ASN1err(ASN1_F_D2I_ASN1_BIT_STRING,i);
if ((ret != NULL) && ((a == NULL) || (*a != ret)))
ASN1_BIT_STRING_free(ret);
return(NULL);
}
int ASN1_BIT_STRING_set_bit(ASN1_BIT_STRING *a, int n, int value)
{
int w,v,iv;
unsigned char *c;
w=n/8;
v=1<<(7-(n&0x07));
iv= ~v;
a->flags&= ~(ASN1_STRING_FLAG_BITS_LEFT|0x07);
if (a == NULL) return(0);
if ((a->length < (w+1)) || (a->data == NULL))
{
if (!value) return(1);
if (a->data == NULL)
c=(unsigned char *)Malloc(w+1);
else
c=(unsigned char *)Realloc(a->data,w+1);
if (c == NULL) return(0);
a->data=c;
a->length=w+1;
c[w]=0;
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
