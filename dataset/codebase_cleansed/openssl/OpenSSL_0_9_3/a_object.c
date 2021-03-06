int i2d_ASN1_OBJECT(ASN1_OBJECT *a, unsigned char **pp)
{
unsigned char *p;
if ((a == NULL) || (a->data == NULL)) return(0);
if (pp == NULL)
return(ASN1_object_size(0,a->length,V_ASN1_OBJECT));
p= *pp;
ASN1_put_object(&p,0,a->length,V_ASN1_OBJECT,V_ASN1_UNIVERSAL);
memcpy(p,a->data,a->length);
p+=a->length;
*pp=p;
return(a->length);
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
int i,idx=0,n=0,len,nid;
unsigned long l;
unsigned char *p;
const char *s;
char tbuf[32];
if (buf_len <= 0) return(0);
if ((a == NULL) || (a->data == NULL))
{
buf[0]='\0';
return(0);
}
nid=OBJ_obj2nid(a);
if (nid == NID_undef)
{
len=a->length;
p=a->data;
idx=0;
l=0;
while (idx < a->length)
{
l|=(p[idx]&0x7f);
if (!(p[idx] & 0x80)) break;
l<<=7L;
idx++;
}
idx++;
i=(int)(l/40);
if (i > 2) i=2;
l-=(long)(i*40);
sprintf(tbuf,"%d.%ld",i,l);
i=strlen(tbuf);
strncpy(buf,tbuf,buf_len);
buf_len-=i;
buf+=i;
n+=i;
l=0;
for (; idx<len; idx++)
{
l|=p[idx]&0x7f;
if (!(p[idx] & 0x80))
{
sprintf(tbuf,".%ld",l);
i=strlen(tbuf);
if (buf_len > 0)
strncpy(buf,tbuf,buf_len);
buf_len-=i;
buf+=i;
n+=i;
l=0;
}
l<<=7L;
}
}
else
{
s=OBJ_nid2ln(nid);
if (s == NULL)
s=OBJ_nid2sn(nid);
strncpy(buf,s,buf_len);
n=strlen(s);
}
buf[buf_len-1]='\0';
return(n);
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
ASN1_OBJECT *ret=NULL;
unsigned char *p;
long len;
int tag,xclass;
int inf,i;
if ((a == NULL) || ((*a) == NULL) ||
!((*a)->flags & ASN1_OBJECT_FLAG_DYNAMIC))
{
if ((ret=ASN1_OBJECT_new()) == NULL) return(NULL);
}
else ret=(*a);
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
if ((ret->data == NULL) || (ret->length < len))
{
if (ret->data != NULL) Free((char *)ret->data);
ret->data=(unsigned char *)Malloc((int)len);
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
ret=(ASN1_OBJECT *)Malloc(sizeof(ASN1_OBJECT));
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
if (a->sn != NULL) Free((void *)a->sn);
if (a->ln != NULL) Free((void *)a->ln);
#endif
a->sn=a->ln=NULL;
}
if (a->flags & ASN1_OBJECT_FLAG_DYNAMIC_DATA)
{
if (a->data != NULL) Free(a->data);
a->data=NULL;
a->length=0;
}
if (a->flags & ASN1_OBJECT_FLAG_DYNAMIC)
Free(a);
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
