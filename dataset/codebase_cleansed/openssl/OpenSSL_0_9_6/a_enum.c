ASN1_ENUMERATED *ASN1_ENUMERATED_new(void)
{ return M_ASN1_ENUMERATED_new(); }
void ASN1_ENUMERATED_free(ASN1_ENUMERATED *x)
{ M_ASN1_ENUMERATED_free(x); }
int i2d_ASN1_ENUMERATED(ASN1_ENUMERATED *a, unsigned char **pp)
{
int len, ret;
if(!a) return 0;
len = i2c_ASN1_INTEGER(a, NULL);
ret=ASN1_object_size(0,len,V_ASN1_ENUMERATED);
if(pp) {
ASN1_put_object(pp,0,len,V_ASN1_ENUMERATED,V_ASN1_UNIVERSAL);
i2c_ASN1_INTEGER(a, pp);
}
return ret;
}
ASN1_ENUMERATED *d2i_ASN1_ENUMERATED(ASN1_ENUMERATED **a, unsigned char **pp,
long length)
{
unsigned char *p;
long len;
int i;
int inf,tag,xclass;
ASN1_ENUMERATED *ret;
p= *pp;
inf=ASN1_get_object(&p,&len,&tag,&xclass,length);
if (inf & 0x80)
{
i=ASN1_R_BAD_OBJECT_HEADER;
goto err;
}
if (tag != V_ASN1_ENUMERATED)
{
i=ASN1_R_EXPECTING_AN_ENUMERATED;
goto err;
}
ret = c2i_ASN1_INTEGER(a, &p, len);
if(ret) {
ret->type = (V_ASN1_NEG & ret->type) | V_ASN1_ENUMERATED;
*pp = p;
}
return ret;
err:
ASN1err(ASN1_F_D2I_ASN1_ENUMERATED,i);
return(NULL);
}
int ASN1_ENUMERATED_set(ASN1_ENUMERATED *a, long v)
{
int i,j,k;
unsigned char buf[sizeof(long)+1];
long d;
a->type=V_ASN1_ENUMERATED;
if (a->length < (sizeof(long)+1))
{
if (a->data != NULL)
OPENSSL_free(a->data);
if ((a->data=(unsigned char *)OPENSSL_malloc(sizeof(long)+1)) != NULL)
memset((char *)a->data,0,sizeof(long)+1);
}
if (a->data == NULL)
{
ASN1err(ASN1_F_ASN1_ENUMERATED_SET,ERR_R_MALLOC_FAILURE);
return(0);
}
d=v;
if (d < 0)
{
d= -d;
a->type=V_ASN1_NEG_ENUMERATED;
}
for (i=0; i<sizeof(long); i++)
{
if (d == 0) break;
buf[i]=(int)d&0xff;
d>>=8;
}
j=0;
for (k=i-1; k >=0; k--)
a->data[j++]=buf[k];
a->length=j;
return(1);
}
long ASN1_ENUMERATED_get(ASN1_ENUMERATED *a)
{
int neg=0,i;
long r=0;
if (a == NULL) return(0L);
i=a->type;
if (i == V_ASN1_NEG_ENUMERATED)
neg=1;
else if (i != V_ASN1_ENUMERATED)
return(0);
if (a->length > sizeof(long))
{
return(0xffffffffL);
}
if (a->data == NULL)
return(0);
for (i=0; i<a->length; i++)
{
r<<=8;
r|=(unsigned char)a->data[i];
}
if (neg) r= -r;
return(r);
}
ASN1_ENUMERATED *BN_to_ASN1_ENUMERATED(BIGNUM *bn, ASN1_ENUMERATED *ai)
{
ASN1_ENUMERATED *ret;
int len,j;
if (ai == NULL)
ret=M_ASN1_ENUMERATED_new();
else
ret=ai;
if (ret == NULL)
{
ASN1err(ASN1_F_BN_TO_ASN1_ENUMERATED,ERR_R_NESTED_ASN1_ERROR);
goto err;
}
if(bn->neg) ret->type = V_ASN1_NEG_ENUMERATED;
else ret->type=V_ASN1_ENUMERATED;
j=BN_num_bits(bn);
len=((j == 0)?0:((j/8)+1));
ret->data=(unsigned char *)OPENSSL_malloc(len+4);
ret->length=BN_bn2bin(bn,ret->data);
return(ret);
err:
if (ret != ai) M_ASN1_ENUMERATED_free(ret);
return(NULL);
}
BIGNUM *ASN1_ENUMERATED_to_BN(ASN1_ENUMERATED *ai, BIGNUM *bn)
{
BIGNUM *ret;
if ((ret=BN_bin2bn(ai->data,ai->length,bn)) == NULL)
ASN1err(ASN1_F_ASN1_ENUMERATED_TO_BN,ASN1_R_BN_LIB);
else if(ai->type == V_ASN1_NEG_ENUMERATED) ret->neg = 1;
return(ret);
}
