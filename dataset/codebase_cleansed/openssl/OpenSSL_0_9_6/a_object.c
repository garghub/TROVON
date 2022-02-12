int i2d_ASN1_OBJECT(ASN1_OBJECT *a, unsigned char **pp)
{
unsigned char *p;
int objsize;
if ((a == NULL) || (a->data == NULL)) return(0);
objsize = ASN1_object_size(0,a->length,V_ASN1_OBJECT);
if (pp == NULL) return objsize;
p= *pp;
ASN1_put_object(&p,0,a->length,V_ASN1_OBJECT,V_ASN1_UNIVERSAL);
memcpy(p,a->data,a->length);
p+=a->length;
*pp=p;
return(objsize);
}
int a2d_ASN1_OBJECT(unsigned char *out, int olen, const char *buf, int num)
{
int i,first,len=0,c;
char tmp[24];
const char *p;
unsigned long l;
if (num == 0)
return(0);
else if (num == -1)
num=strlen(buf);
p=buf;
c= *(p++);
num--;
if ((c >= '0') && (c <= '2'))
{
first=(c-'0')*40;
}
else
{
ASN1err(ASN1_F_A2D_ASN1_OBJECT,ASN1_R_FIRST_NUM_TOO_LARGE);
goto err;
}
if (num <= 0)
{
ASN1err(ASN1_F_A2D_ASN1_OBJECT,ASN1_R_MISSING_SECOND_NUMBER);
goto err;
}
c= *(p++);
num--;
for (;;)
{
if (num <= 0) break;
if ((c != '.') && (c != ' '))
{
ASN1err(ASN1_F_A2D_ASN1_OBJECT,ASN1_R_INVALID_SEPARATOR);
goto err;
}
l=0;
for (;;)
{
if (num <= 0) break;
num--;
c= *(p++);
if ((c == ' ') || (c == '.'))
break;
if ((c < '0') || (c > '9'))
{
ASN1err(ASN1_F_A2D_ASN1_OBJECT,ASN1_R_INVALID_DIGIT);
goto err;
}
l=l*10L+(long)(c-'0');
}
if (len == 0)
{
if ((first < 2) && (l >= 40))
{
ASN1err(ASN1_F_A2D_ASN1_OBJECT,ASN1_R_SECOND_NUMBER_TOO_LARGE);
goto err;
}
l+=(long)first;
}
i=0;
for (;;)
{
tmp[i++]=(unsigned char)l&0x7f;
l>>=7L;
if (l == 0L) break;
}
if (out != NULL)
{
if (len+i > olen)
{
ASN1err(ASN1_F_A2D_ASN1_OBJECT,ASN1_R_BUFFER_TOO_SMALL);
goto err;
}
while (--i > 0)
out[len++]=tmp[i]|0x80;
out[len++]=tmp[0];
}
else
len+=i;
}
return(len);
err:
return(0);
}
int i2t_ASN1_OBJECT(char *buf, int buf_len, ASN1_OBJECT *a)
{
return OBJ_obj2txt(buf, buf_len, a, 0);
}
int i2a_ASN1_OBJECT(BIO *bp, ASN1_OBJECT *a)
{
char buf[80];
int i;
if ((a == NULL) || (a->data == NULL))
return(BIO_write(bp,"NULL",4));
i=i2t_ASN1_OBJECT(buf,80,a);
if (i > 80) i=80;
BIO_write(bp,buf,i);
return(i);
}
ASN1_OBJECT *d2i_ASN1_OBJECT(ASN1_OBJECT **a, unsigned char **pp,
long length)
{
unsigned char *p;
long len;
int tag,xclass;
int inf,i;
ASN1_OBJECT *ret = NULL;
p= *pp;
inf=ASN1_get_object(&p,&len,&tag,&xclass,length);
if (inf & 0x80)
{
i=ASN1_R_BAD_OBJECT_HEADER;
goto err;
}
if (tag != V_ASN1_OBJECT)
{
i=ASN1_R_EXPECTING_AN_OBJECT;
goto err;
}
ret = c2i_ASN1_OBJECT(a, &p, len);
if(ret) *pp = p;
return ret;
err:
ASN1err(ASN1_F_D2I_ASN1_OBJECT,i);
if ((ret != NULL) && ((a == NULL) || (*a != ret)))
ASN1_OBJECT_free(ret);
return(NULL);
}
ASN1_OBJECT *c2i_ASN1_OBJECT(ASN1_OBJECT **a, unsigned char **pp,
long len)
{
ASN1_OBJECT *ret=NULL;
unsigned char *p;
int i;
if ((a == NULL) || ((*a) == NULL) ||
!((*a)->flags & ASN1_OBJECT_FLAG_DYNAMIC))
{
if ((ret=ASN1_OBJECT_new()) == NULL) return(NULL);
}
else ret=(*a);
p= *pp;
if ((ret->data == NULL) || (ret->length < len))
{
if (ret->data != NULL) OPENSSL_free(ret->data);
ret->data=(unsigned char *)OPENSSL_malloc(len ? (int)len : 1);
ret->flags|=ASN1_OBJECT_FLAG_DYNAMIC_DATA;
if (ret->data == NULL)
{ i=ERR_R_MALLOC_FAILURE; goto err; }
}
memcpy(ret->data,p,(int)len);
ret->length=(int)len;
ret->sn=NULL;
ret->ln=NULL;
p+=len;
if (a != NULL) (*a)=ret;
*pp=p;
return(ret);
err:
ASN1err(ASN1_F_D2I_ASN1_OBJECT,i);
if ((ret != NULL) && ((a == NULL) || (*a != ret)))
ASN1_OBJECT_free(ret);
return(NULL);
}
ASN1_OBJECT *ASN1_OBJECT_new(void)
{
ASN1_OBJECT *ret;
ret=(ASN1_OBJECT *)OPENSSL_malloc(sizeof(ASN1_OBJECT));
if (ret == NULL)
{
ASN1err(ASN1_F_ASN1_OBJECT_NEW,ERR_R_MALLOC_FAILURE);
return(NULL);
}
ret->length=0;
ret->data=NULL;
ret->nid=0;
ret->sn=NULL;
ret->ln=NULL;
ret->flags=ASN1_OBJECT_FLAG_DYNAMIC;
return(ret);
}
void ASN1_OBJECT_free(ASN1_OBJECT *a)
{
if (a == NULL) return;
if (a->flags & ASN1_OBJECT_FLAG_DYNAMIC_STRINGS)
{
#ifndef CONST_STRICT
if (a->sn != NULL) OPENSSL_free((void *)a->sn);
if (a->ln != NULL) OPENSSL_free((void *)a->ln);
#endif
a->sn=a->ln=NULL;
}
if (a->flags & ASN1_OBJECT_FLAG_DYNAMIC_DATA)
{
if (a->data != NULL) OPENSSL_free(a->data);
a->data=NULL;
a->length=0;
}
if (a->flags & ASN1_OBJECT_FLAG_DYNAMIC)
OPENSSL_free(a);
}
ASN1_OBJECT *ASN1_OBJECT_create(int nid, unsigned char *data, int len,
char *sn, char *ln)
{
ASN1_OBJECT o;
o.sn=sn;
o.ln=ln;
o.data=data;
o.nid=nid;
o.length=len;
o.flags=ASN1_OBJECT_FLAG_DYNAMIC|ASN1_OBJECT_FLAG_DYNAMIC_STRINGS|
ASN1_OBJECT_FLAG_DYNAMIC_DATA;
return(OBJ_dup(&o));
}
