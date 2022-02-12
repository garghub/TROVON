int i2d_ASN1_ENUMERATED(ASN1_ENUMERATED *a, unsigned char **pp)
{
int pad=0,ret,r,i,t;
unsigned char *p,*n,pb=0;
if ((a == NULL) || (a->data == NULL)) return(0);
t=a->type;
if (a->length == 0)
ret=1;
else
{
ret=a->length;
i=a->data[0];
if ((t == V_ASN1_ENUMERATED) && (i > 127)) {
pad=1;
pb=0;
} else if(t == V_ASN1_NEG_ENUMERATED) {
if(i>128) {
pad=1;
pb=0xFF;
} else if(i == 128) {
for(i = 1; i < a->length; i++) if(a->data[i]) {
pad=1;
pb=0xFF;
break;
}
}
}
ret+=pad;
}
r=ASN1_object_size(0,ret,V_ASN1_ENUMERATED);
if (pp == NULL) return(r);
p= *pp;
ASN1_put_object(&p,0,ret,V_ASN1_ENUMERATED,V_ASN1_UNIVERSAL);
if (pad) *(p++)=pb;
if (a->length == 0)
*(p++)=0;
else if (t == V_ASN1_ENUMERATED)
{
memcpy(p,a->data,(unsigned int)a->length);
p+=a->length;
}
else {
n=a->data + a->length - 1;
p += a->length - 1;
i = a->length;
while(!*n) {
*(p--) = 0;
n--;
i--;
}
*(p--) = ((*(n--)) ^ 0xff) + 1;
i--;
for(;i > 0; i--) *(p--) = *(n--) ^ 0xff;
p += a->length;
}
*pp=p;
return(r);
}
ASN1_ENUMERATED *d2i_ASN1_ENUMERATED(ASN1_ENUMERATED **a, unsigned char **pp,
long length)
{
ASN1_ENUMERATED *ret=NULL;
unsigned char *p,*to,*s;
long len;
int inf,tag,xclass;
int i;
if ((a == NULL) || ((*a) == NULL))
{
if ((ret=ASN1_ENUMERATED_new()) == NULL) return(NULL);
ret->type=V_ASN1_ENUMERATED;
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
if (tag != V_ASN1_ENUMERATED)
{
i=ASN1_R_EXPECTING_AN_ENUMERATED;
goto err;
}
s=(unsigned char *)Malloc((int)len+1);
if (s == NULL)
{
i=ERR_R_MALLOC_FAILURE;
goto err;
}
to=s;
if (*p & 0x80)
{
ret->type=V_ASN1_NEG_ENUMERATED;
if ((*p == 0xff) && (len != 1)) {
p++;
len--;
}
i = len;
p += i - 1;
to += i - 1;
while((!*p) && i) {
*(to--) = 0;
i--;
p--;
}
if(!i) {
*s = 1;
s[len] = 0;
p += len;
len++;
} else {
*(to--) = (*(p--) ^ 0xff) + 1;
i--;
for(;i > 0; i--) *(to--) = *(p--) ^ 0xff;
p += len;
}
} else {
ret->type=V_ASN1_ENUMERATED;
if ((*p == 0) && (len != 1))
{
p++;
len--;
}
memcpy(s,p,(int)len);
p+=len;
}
if (ret->data != NULL) Free((char *)ret->data);
ret->data=s;
ret->length=(int)len;
if (a != NULL) (*a)=ret;
*pp=p;
return(ret);
err:
ASN1err(ASN1_F_D2I_ASN1_ENUMERATED,i);
if ((ret != NULL) && ((a == NULL) || (*a != ret)))
ASN1_ENUMERATED_free(ret);
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
Free((char *)a->data);
if ((a->data=(unsigned char *)Malloc(sizeof(long)+1)) != NULL)
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
ret=ASN1_ENUMERATED_new();
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
ret->data=(unsigned char *)Malloc(len+4);
ret->length=BN_bn2bin(bn,ret->data);
return(ret);
err:
if (ret != ai) ASN1_ENUMERATED_free(ret);
return(NULL);
}
BIGNUM *ASN1_ENUMERATED_to_BN(ASN1_ENUMERATED *ai, BIGNUM *bn)
{
BIGNUM *ret;
if ((ret=BN_bin2bn(ai->data,ai->length,bn)) == NULL)
ASN1err(ASN1_F_ASN1_ENUMERATED_TO_BN,ASN1_R_BN_LIB);
if(ai->type == V_ASN1_NEG_ENUMERATED) bn->neg = 1;
return(ret);
}
