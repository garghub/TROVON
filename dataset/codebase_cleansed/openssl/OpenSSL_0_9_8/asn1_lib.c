static int _asn1_check_infinite_end(const unsigned char **p, long len)
{
if (len <= 0)
return(1);
else if ((len >= 2) && ((*p)[0] == 0) && ((*p)[1] == 0))
{
(*p)+=2;
return(1);
}
return(0);
}
int ASN1_check_infinite_end(unsigned char **p, long len)
{
return _asn1_check_infinite_end((const unsigned char **)p, len);
}
int ASN1_const_check_infinite_end(const unsigned char **p, long len)
{
return _asn1_check_infinite_end(p, len);
}
int ASN1_get_object(const unsigned char **pp, long *plength, int *ptag,
int *pclass, long omax)
{
int i,ret;
long l;
const unsigned char *p= *pp;
int tag,xclass,inf;
long max=omax;
if (!max) goto err;
ret=(*p&V_ASN1_CONSTRUCTED);
xclass=(*p&V_ASN1_PRIVATE);
i= *p&V_ASN1_PRIMITIVE_TAG;
if (i == V_ASN1_PRIMITIVE_TAG)
{
p++;
if (--max == 0) goto err;
l=0;
while (*p&0x80)
{
l<<=7L;
l|= *(p++)&0x7f;
if (--max == 0) goto err;
if (l > (INT_MAX >> 7L)) goto err;
}
l<<=7L;
l|= *(p++)&0x7f;
tag=(int)l;
if (--max == 0) goto err;
}
else
{
tag=i;
p++;
if (--max == 0) goto err;
}
*ptag=tag;
*pclass=xclass;
if (!asn1_get_length(&p,&inf,plength,(int)max)) goto err;
#if 0
fprintf(stderr,"p=%d + *plength=%ld > omax=%ld + *pp=%d (%d > %d)\n",
(int)p,*plength,omax,(int)*pp,(int)(p+ *plength),
(int)(omax+ *pp));
#endif
if (*plength > (omax - (p - *pp)))
{
ASN1err(ASN1_F_ASN1_GET_OBJECT,ASN1_R_TOO_LONG);
ret|=0x80;
}
*pp=p;
return(ret|inf);
err:
ASN1err(ASN1_F_ASN1_GET_OBJECT,ASN1_R_HEADER_TOO_LONG);
return(0x80);
}
static int asn1_get_length(const unsigned char **pp, int *inf, long *rl, int max)
{
const unsigned char *p= *pp;
unsigned long ret=0;
unsigned int i;
if (max-- < 1) return(0);
if (*p == 0x80)
{
*inf=1;
ret=0;
p++;
}
else
{
*inf=0;
i= *p&0x7f;
if (*(p++) & 0x80)
{
if (i > sizeof(long))
return 0;
if (max-- == 0) return(0);
while (i-- > 0)
{
ret<<=8L;
ret|= *(p++);
if (max-- == 0) return(0);
}
}
else
ret=i;
}
if (ret > LONG_MAX)
return 0;
*pp=p;
*rl=(long)ret;
return(1);
}
void ASN1_put_object(unsigned char **pp, int constructed, int length, int tag,
int xclass)
{
unsigned char *p= *pp;
int i, ttag;
i=(constructed)?V_ASN1_CONSTRUCTED:0;
i|=(xclass&V_ASN1_PRIVATE);
if (tag < 31)
*(p++)=i|(tag&V_ASN1_PRIMITIVE_TAG);
else
{
*(p++)=i|V_ASN1_PRIMITIVE_TAG;
for(i = 0, ttag = tag; ttag > 0; i++) ttag >>=7;
ttag = i;
while(i-- > 0)
{
p[i] = tag & 0x7f;
if(i != (ttag - 1)) p[i] |= 0x80;
tag >>= 7;
}
p += ttag;
}
if (constructed == 2)
*(p++)=0x80;
else
asn1_put_length(&p,length);
*pp=p;
}
int ASN1_put_eoc(unsigned char **pp)
{
unsigned char *p = *pp;
*p++ = 0;
*p++ = 0;
*pp = p;
return 2;
}
static void asn1_put_length(unsigned char **pp, int length)
{
unsigned char *p= *pp;
int i,l;
if (length <= 127)
*(p++)=(unsigned char)length;
else
{
l=length;
for (i=0; l > 0; i++)
l>>=8;
*(p++)=i|0x80;
l=i;
while (i-- > 0)
{
p[i]=length&0xff;
length>>=8;
}
p+=l;
}
*pp=p;
}
int ASN1_object_size(int constructed, int length, int tag)
{
int ret;
ret=length;
ret++;
if (tag >= 31)
{
while (tag > 0)
{
tag>>=7;
ret++;
}
}
if (constructed == 2)
return ret + 3;
ret++;
if (length > 127)
{
while (length > 0)
{
length>>=8;
ret++;
}
}
return(ret);
}
static int _asn1_Finish(ASN1_const_CTX *c)
{
if ((c->inf == (1|V_ASN1_CONSTRUCTED)) && (!c->eos))
{
if (!ASN1_const_check_infinite_end(&c->p,c->slen))
{
c->error=ERR_R_MISSING_ASN1_EOS;
return(0);
}
}
if ( ((c->slen != 0) && !(c->inf & 1)) ||
((c->slen < 0) && (c->inf & 1)))
{
c->error=ERR_R_ASN1_LENGTH_MISMATCH;
return(0);
}
return(1);
}
int asn1_Finish(ASN1_CTX *c)
{
return _asn1_Finish((ASN1_const_CTX *)c);
}
int asn1_const_Finish(ASN1_const_CTX *c)
{
return _asn1_Finish(c);
}
int asn1_GetSequence(ASN1_const_CTX *c, long *length)
{
const unsigned char *q;
q=c->p;
c->inf=ASN1_get_object(&(c->p),&(c->slen),&(c->tag),&(c->xclass),
*length);
if (c->inf & 0x80)
{
c->error=ERR_R_BAD_GET_ASN1_OBJECT_CALL;
return(0);
}
if (c->tag != V_ASN1_SEQUENCE)
{
c->error=ERR_R_EXPECTING_AN_ASN1_SEQUENCE;
return(0);
}
(*length)-=(c->p-q);
if (c->max && (*length < 0))
{
c->error=ERR_R_ASN1_LENGTH_MISMATCH;
return(0);
}
if (c->inf == (1|V_ASN1_CONSTRUCTED))
c->slen= *length+ *(c->pp)-c->p;
c->eos=0;
return(1);
}
ASN1_STRING *ASN1_STRING_dup(ASN1_STRING *str)
{
ASN1_STRING *ret;
if (str == NULL) return(NULL);
if ((ret=ASN1_STRING_type_new(str->type)) == NULL)
return(NULL);
if (!ASN1_STRING_set(ret,str->data,str->length))
{
ASN1_STRING_free(ret);
return(NULL);
}
ret->flags = str->flags;
return(ret);
}
int ASN1_STRING_set(ASN1_STRING *str, const void *_data, int len)
{
unsigned char *c;
const char *data=_data;
if (len < 0)
{
if (data == NULL)
return(0);
else
len=strlen(data);
}
if ((str->length < len) || (str->data == NULL))
{
c=str->data;
if (c == NULL)
str->data=OPENSSL_malloc(len+1);
else
str->data=OPENSSL_realloc(c,len+1);
if (str->data == NULL)
{
ASN1err(ASN1_F_ASN1_STRING_SET,ERR_R_MALLOC_FAILURE);
str->data=c;
return(0);
}
}
str->length=len;
if (data != NULL)
{
memcpy(str->data,data,len);
str->data[len]='\0';
}
return(1);
}
ASN1_STRING *ASN1_STRING_new(void)
{
return(ASN1_STRING_type_new(V_ASN1_OCTET_STRING));
}
ASN1_STRING *ASN1_STRING_type_new(int type)
{
ASN1_STRING *ret;
ret=(ASN1_STRING *)OPENSSL_malloc(sizeof(ASN1_STRING));
if (ret == NULL)
{
ASN1err(ASN1_F_ASN1_STRING_TYPE_NEW,ERR_R_MALLOC_FAILURE);
return(NULL);
}
ret->length=0;
ret->type=type;
ret->data=NULL;
ret->flags=0;
return(ret);
}
void ASN1_STRING_free(ASN1_STRING *a)
{
if (a == NULL) return;
if (a->data != NULL) OPENSSL_free(a->data);
OPENSSL_free(a);
}
int ASN1_STRING_cmp(ASN1_STRING *a, ASN1_STRING *b)
{
int i;
i=(a->length-b->length);
if (i == 0)
{
i=memcmp(a->data,b->data,a->length);
if (i == 0)
return(a->type-b->type);
else
return(i);
}
else
return(i);
}
void asn1_add_error(const unsigned char *address, int offset)
{
char buf1[DECIMAL_SIZE(address)+1],buf2[DECIMAL_SIZE(offset)+1];
BIO_snprintf(buf1,sizeof buf1,"%lu",(unsigned long)address);
BIO_snprintf(buf2,sizeof buf2,"%d",offset);
ERR_add_error_data(4,"address=",buf1," offset=",buf2);
}
int ASN1_STRING_length(ASN1_STRING *x)
{ return M_ASN1_STRING_length(x); }
void ASN1_STRING_length_set(ASN1_STRING *x, int len)
{ M_ASN1_STRING_length_set(x, len); return; }
int ASN1_STRING_type(ASN1_STRING *x)
{ return M_ASN1_STRING_type(x); }
unsigned char * ASN1_STRING_data(ASN1_STRING *x)
{ return M_ASN1_STRING_data(x); }
