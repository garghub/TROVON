ASN1_INTEGER *ASN1_INTEGER_dup(const ASN1_INTEGER *x)
{ return M_ASN1_INTEGER_dup(x);}
int ASN1_INTEGER_cmp(const ASN1_INTEGER *x, const ASN1_INTEGER *y)
{
int neg, ret;
neg = x->type & V_ASN1_NEG;
if (neg != (y->type & V_ASN1_NEG))
{
if (neg)
return -1;
else
return 1;
}
ret = ASN1_STRING_cmp(x, y);
if (neg)
return -ret;
else
return ret;
}
int i2c_ASN1_INTEGER(ASN1_INTEGER *a, unsigned char **pp)
{
int pad=0,ret,i,neg;
unsigned char *p,*n,pb=0;
if ((a == NULL) || (a->data == NULL)) return(0);
neg=a->type & V_ASN1_NEG;
if (a->length == 0)
ret=1;
else
{
ret=a->length;
i=a->data[0];
if (!neg && (i > 127)) {
pad=1;
pb=0;
} else if(neg) {
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
if (pp == NULL) return(ret);
p= *pp;
if (pad) *(p++)=pb;
if (a->length == 0) *(p++)=0;
else if (!neg) memcpy(p,a->data,(unsigned int)a->length);
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
}
*pp+=ret;
return(ret);
}
ASN1_INTEGER *c2i_ASN1_INTEGER(ASN1_INTEGER **a, const unsigned char **pp,
long len)
{
ASN1_INTEGER *ret=NULL;
const unsigned char *p, *pend;
unsigned char *to,*s;
int i;
if ((a == NULL) || ((*a) == NULL))
{
if ((ret=M_ASN1_INTEGER_new()) == NULL) return(NULL);
ret->type=V_ASN1_INTEGER;
}
else
ret=(*a);
p= *pp;
pend = p + len;
s=(unsigned char *)OPENSSL_malloc((int)len+1);
if (s == NULL)
{
i=ERR_R_MALLOC_FAILURE;
goto err;
}
to=s;
if(!len) {
ret->type=V_ASN1_INTEGER;
} else if (*p & 0x80)
{
ret->type=V_ASN1_NEG_INTEGER;
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
len++;
} else {
*(to--) = (*(p--) ^ 0xff) + 1;
i--;
for(;i > 0; i--) *(to--) = *(p--) ^ 0xff;
}
} else {
ret->type=V_ASN1_INTEGER;
if ((*p == 0) && (len != 1))
{
p++;
len--;
}
memcpy(s,p,(int)len);
}
if (ret->data != NULL) OPENSSL_free(ret->data);
ret->data=s;
ret->length=(int)len;
if (a != NULL) (*a)=ret;
*pp=pend;
return(ret);
err:
ASN1err(ASN1_F_C2I_ASN1_INTEGER,i);
if ((ret != NULL) && ((a == NULL) || (*a != ret)))
M_ASN1_INTEGER_free(ret);
return(NULL);
}
ASN1_INTEGER *d2i_ASN1_UINTEGER(ASN1_INTEGER **a, const unsigned char **pp,
long length)
{
ASN1_INTEGER *ret=NULL;
const unsigned char *p;
unsigned char *s;
long len;
int inf,tag,xclass;
int i;
if ((a == NULL) || ((*a) == NULL))
{
if ((ret=M_ASN1_INTEGER_new()) == NULL) return(NULL);
ret->type=V_ASN1_INTEGER;
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
if (tag != V_ASN1_INTEGER)
{
i=ASN1_R_EXPECTING_AN_INTEGER;
goto err;
}
s=(unsigned char *)OPENSSL_malloc((int)len+1);
if (s == NULL)
{
i=ERR_R_MALLOC_FAILURE;
goto err;
}
ret->type=V_ASN1_INTEGER;
if(len) {
if ((*p == 0) && (len != 1))
{
p++;
len--;
}
memcpy(s,p,(int)len);
p+=len;
}
if (ret->data != NULL) OPENSSL_free(ret->data);
ret->data=s;
ret->length=(int)len;
if (a != NULL) (*a)=ret;
*pp=p;
return(ret);
err:
ASN1err(ASN1_F_D2I_ASN1_UINTEGER,i);
if ((ret != NULL) && ((a == NULL) || (*a != ret)))
M_ASN1_INTEGER_free(ret);
return(NULL);
}
int ASN1_INTEGER_set(ASN1_INTEGER *a, long v)
{
int j,k;
unsigned int i;
unsigned char buf[sizeof(long)+1];
long d;
a->type=V_ASN1_INTEGER;
if (a->length < (int)(sizeof(long)+1))
{
if (a->data != NULL)
OPENSSL_free(a->data);
if ((a->data=(unsigned char *)OPENSSL_malloc(sizeof(long)+1)) != NULL)
memset((char *)a->data,0,sizeof(long)+1);
}
if (a->data == NULL)
{
ASN1err(ASN1_F_ASN1_INTEGER_SET,ERR_R_MALLOC_FAILURE);
return(0);
}
d=v;
if (d < 0)
{
d= -d;
a->type=V_ASN1_NEG_INTEGER;
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
long ASN1_INTEGER_get(const ASN1_INTEGER *a)
{
int neg=0,i;
long r=0;
if (a == NULL) return(0L);
i=a->type;
if (i == V_ASN1_NEG_INTEGER)
neg=1;
else if (i != V_ASN1_INTEGER)
return -1;
if (a->length > (int)sizeof(long))
{
return -1;
}
if (a->data == NULL)
return 0;
for (i=0; i<a->length; i++)
{
r<<=8;
r|=(unsigned char)a->data[i];
}
if (neg) r= -r;
return(r);
}
ASN1_INTEGER *BN_to_ASN1_INTEGER(const BIGNUM *bn, ASN1_INTEGER *ai)
{
ASN1_INTEGER *ret;
int len,j;
if (ai == NULL)
ret=M_ASN1_INTEGER_new();
else
ret=ai;
if (ret == NULL)
{
ASN1err(ASN1_F_BN_TO_ASN1_INTEGER,ERR_R_NESTED_ASN1_ERROR);
goto err;
}
if (BN_is_negative(bn))
ret->type = V_ASN1_NEG_INTEGER;
else ret->type=V_ASN1_INTEGER;
j=BN_num_bits(bn);
len=((j == 0)?0:((j/8)+1));
if (ret->length < len+4)
{
unsigned char *new_data=OPENSSL_realloc(ret->data, len+4);
if (!new_data)
{
ASN1err(ASN1_F_BN_TO_ASN1_INTEGER,ERR_R_MALLOC_FAILURE);
goto err;
}
ret->data=new_data;
}
ret->length=BN_bn2bin(bn,ret->data);
if(!ret->length)
{
ret->data[0] = 0;
ret->length = 1;
}
return(ret);
err:
if (ret != ai) M_ASN1_INTEGER_free(ret);
return(NULL);
}
BIGNUM *ASN1_INTEGER_to_BN(const ASN1_INTEGER *ai, BIGNUM *bn)
{
BIGNUM *ret;
if ((ret=BN_bin2bn(ai->data,ai->length,bn)) == NULL)
ASN1err(ASN1_F_ASN1_INTEGER_TO_BN,ASN1_R_BN_LIB);
else if(ai->type == V_ASN1_NEG_INTEGER)
BN_set_negative(ret, 1);
return(ret);
}
