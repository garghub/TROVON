static int SetBlobCmp(const void *elem1, const void *elem2 )
{
const MYBLOB *b1 = (const MYBLOB *)elem1;
const MYBLOB *b2 = (const MYBLOB *)elem2;
int r;
r = memcmp(b1->pbData, b2->pbData,
b1->cbData < b2->cbData ? b1->cbData : b2->cbData);
if(r != 0)
return r;
return b1->cbData-b2->cbData;
}
int i2d_ASN1_SET(STACK *a, unsigned char **pp, int (*func)(), int ex_tag,
int ex_class, int is_set)
{
int ret=0,r;
int i;
unsigned char *p;
unsigned char *pStart, *pTempMem;
MYBLOB *rgSetBlob;
int totSize;
if (a == NULL) return(0);
for (i=sk_num(a)-1; i>=0; i--)
ret+=func(sk_value(a,i),NULL);
r=ASN1_object_size(1,ret,ex_tag);
if (pp == NULL) return(r);
p= *pp;
ASN1_put_object(&p,1,ret,ex_tag,ex_class);
if(!is_set || (sk_num(a) < 2))
{
for (i=0; i<sk_num(a); i++)
func(sk_value(a,i),&p);
*pp=p;
return(r);
}
pStart = p;
rgSetBlob = (MYBLOB *)OPENSSL_malloc( sk_num(a) * sizeof(MYBLOB));
for (i=0; i<sk_num(a); i++)
{
rgSetBlob[i].pbData = p;
func(sk_value(a,i),&p);
rgSetBlob[i].cbData = p - rgSetBlob[i].pbData;
}
*pp=p;
totSize = p - pStart;
qsort( rgSetBlob, sk_num(a), sizeof(MYBLOB), SetBlobCmp);
pTempMem = OPENSSL_malloc(totSize);
p = pTempMem;
for(i=0; i<sk_num(a); ++i)
{
memcpy(p, rgSetBlob[i].pbData, rgSetBlob[i].cbData);
p += rgSetBlob[i].cbData;
}
memcpy(pStart, pTempMem, totSize);
OPENSSL_free(pTempMem);
OPENSSL_free(rgSetBlob);
return(r);
}
STACK *d2i_ASN1_SET(STACK **a, unsigned char **pp, long length,
char *(*func)(), void (*free_func)(void *), int ex_tag, int ex_class)
{
ASN1_CTX c;
STACK *ret=NULL;
if ((a == NULL) || ((*a) == NULL))
{ if ((ret=sk_new_null()) == NULL) goto err; }
else
ret=(*a);
c.p= *pp;
c.max=(length == 0)?0:(c.p+length);
c.inf=ASN1_get_object(&c.p,&c.slen,&c.tag,&c.xclass,c.max-c.p);
if (c.inf & 0x80) goto err;
if (ex_class != c.xclass)
{
ASN1err(ASN1_F_D2I_ASN1_SET,ASN1_R_BAD_CLASS);
goto err;
}
if (ex_tag != c.tag)
{
ASN1err(ASN1_F_D2I_ASN1_SET,ASN1_R_BAD_TAG);
goto err;
}
if ((c.slen+c.p) > c.max)
{
ASN1err(ASN1_F_D2I_ASN1_SET,ASN1_R_LENGTH_ERROR);
goto err;
}
if (c.inf == (V_ASN1_CONSTRUCTED+1))
c.slen=length+ *pp-c.p;
c.max=c.p+c.slen;
while (c.p < c.max)
{
char *s;
if (M_ASN1_D2I_end_sequence()) break;
if ((s=func(NULL,&c.p,c.slen,c.max-c.p)) == NULL)
{
ASN1err(ASN1_F_D2I_ASN1_SET,ASN1_R_ERROR_PARSING_SET_ELEMENT);
asn1_add_error(*pp,(int)(c.q- *pp));
goto err;
}
if (!sk_push(ret,s)) goto err;
}
if (a != NULL) (*a)=ret;
*pp=c.p;
return(ret);
err:
if ((ret != NULL) && ((a == NULL) || (*a != ret)))
{
if (free_func != NULL)
sk_pop_free(ret,free_func);
else
sk_free(ret);
}
return(NULL);
}
