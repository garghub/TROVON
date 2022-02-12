static int sn_cmp(const void *a, const void *b)
{
const ASN1_OBJECT * const *ap = a, * const *bp = b;
return(strcmp((*ap)->sn,(*bp)->sn));
}
static int ln_cmp(const void *a, const void *b)
{
const ASN1_OBJECT * const *ap = a, * const *bp = b;
return(strcmp((*ap)->ln,(*bp)->ln));
}
static unsigned long add_hash(const void *ca_void)
{
const ASN1_OBJECT *a;
int i;
unsigned long ret=0;
unsigned char *p;
const ADDED_OBJ *ca = (const ADDED_OBJ *)ca_void;
a=ca->obj;
switch (ca->type)
{
case ADDED_DATA:
ret=a->length<<20L;
p=(unsigned char *)a->data;
for (i=0; i<a->length; i++)
ret^=p[i]<<((i*3)%24);
break;
case ADDED_SNAME:
ret=lh_strhash(a->sn);
break;
case ADDED_LNAME:
ret=lh_strhash(a->ln);
break;
case ADDED_NID:
ret=a->nid;
break;
default:
return 0;
}
ret&=0x3fffffffL;
ret|=ca->type<<30L;
return(ret);
}
static int add_cmp(const void *ca_void, const void *cb_void)
{
ASN1_OBJECT *a,*b;
int i;
const ADDED_OBJ *ca = (const ADDED_OBJ *)ca_void;
const ADDED_OBJ *cb = (const ADDED_OBJ *)cb_void;
i=ca->type-cb->type;
if (i) return(i);
a=ca->obj;
b=cb->obj;
switch (ca->type)
{
case ADDED_DATA:
i=(a->length - b->length);
if (i) return(i);
return(memcmp(a->data,b->data,(size_t)a->length));
case ADDED_SNAME:
if (a->sn == NULL) return(-1);
else if (b->sn == NULL) return(1);
else return(strcmp(a->sn,b->sn));
case ADDED_LNAME:
if (a->ln == NULL) return(-1);
else if (b->ln == NULL) return(1);
else return(strcmp(a->ln,b->ln));
case ADDED_NID:
return(a->nid-b->nid);
default:
return 0;
}
}
static int init_added(void)
{
if (added != NULL) return(1);
added=lh_new(add_hash,add_cmp);
return(added != NULL);
}
static void cleanup1(ADDED_OBJ *a)
{
a->obj->nid=0;
a->obj->flags|=ASN1_OBJECT_FLAG_DYNAMIC|
ASN1_OBJECT_FLAG_DYNAMIC_STRINGS|
ASN1_OBJECT_FLAG_DYNAMIC_DATA;
}
static void cleanup2(ADDED_OBJ *a)
{ a->obj->nid++; }
static void cleanup3(ADDED_OBJ *a)
{
if (--a->obj->nid == 0)
ASN1_OBJECT_free(a->obj);
OPENSSL_free(a);
}
int OBJ_add_object(const ASN1_OBJECT *obj)
{
ASN1_OBJECT *o;
ADDED_OBJ *ao[4]={NULL,NULL,NULL,NULL},*aop;
int i;
if (added == NULL)
if (!init_added()) return(0);
if ((o=OBJ_dup(obj)) == NULL) goto err;
if (!(ao[ADDED_NID]=(ADDED_OBJ *)OPENSSL_malloc(sizeof(ADDED_OBJ)))) goto err2;
if ((o->length != 0) && (obj->data != NULL))
if (!(ao[ADDED_DATA]=(ADDED_OBJ *)OPENSSL_malloc(sizeof(ADDED_OBJ)))) goto err2;
if (o->sn != NULL)
if (!(ao[ADDED_SNAME]=(ADDED_OBJ *)OPENSSL_malloc(sizeof(ADDED_OBJ)))) goto err2;
if (o->ln != NULL)
if (!(ao[ADDED_LNAME]=(ADDED_OBJ *)OPENSSL_malloc(sizeof(ADDED_OBJ)))) goto err2;
for (i=ADDED_DATA; i<=ADDED_NID; i++)
{
if (ao[i] != NULL)
{
ao[i]->type=i;
ao[i]->obj=o;
aop=(ADDED_OBJ *)lh_insert(added,ao[i]);
if (aop != NULL)
OPENSSL_free(aop);
}
}
o->flags&= ~(ASN1_OBJECT_FLAG_DYNAMIC|ASN1_OBJECT_FLAG_DYNAMIC_STRINGS|
ASN1_OBJECT_FLAG_DYNAMIC_DATA);
return(o->nid);
err2:
OBJerr(OBJ_F_OBJ_ADD_OBJECT,ERR_R_MALLOC_FAILURE);
err:
for (i=ADDED_DATA; i<=ADDED_NID; i++)
if (ao[i] != NULL) OPENSSL_free(ao[i]);
if (o != NULL) OPENSSL_free(o);
return(NID_undef);
}
ASN1_OBJECT *OBJ_nid2obj(int n)
{
ADDED_OBJ ad,*adp;
ASN1_OBJECT ob;
if ((n >= 0) && (n < NUM_NID))
{
if ((n != NID_undef) && (nid_objs[n].nid == NID_undef))
{
OBJerr(OBJ_F_OBJ_NID2OBJ,OBJ_R_UNKNOWN_NID);
return(NULL);
}
return((ASN1_OBJECT *)&(nid_objs[n]));
}
else if (added == NULL)
return(NULL);
else
{
ad.type=ADDED_NID;
ad.obj= &ob;
ob.nid=n;
adp=(ADDED_OBJ *)lh_retrieve(added,&ad);
if (adp != NULL)
return(adp->obj);
else
{
OBJerr(OBJ_F_OBJ_NID2OBJ,OBJ_R_UNKNOWN_NID);
return(NULL);
}
}
}
const char *OBJ_nid2sn(int n)
{
ADDED_OBJ ad,*adp;
ASN1_OBJECT ob;
if ((n >= 0) && (n < NUM_NID))
{
if ((n != NID_undef) && (nid_objs[n].nid == NID_undef))
{
OBJerr(OBJ_F_OBJ_NID2SN,OBJ_R_UNKNOWN_NID);
return(NULL);
}
return(nid_objs[n].sn);
}
else if (added == NULL)
return(NULL);
else
{
ad.type=ADDED_NID;
ad.obj= &ob;
ob.nid=n;
adp=(ADDED_OBJ *)lh_retrieve(added,&ad);
if (adp != NULL)
return(adp->obj->sn);
else
{
OBJerr(OBJ_F_OBJ_NID2SN,OBJ_R_UNKNOWN_NID);
return(NULL);
}
}
}
const char *OBJ_nid2ln(int n)
{
ADDED_OBJ ad,*adp;
ASN1_OBJECT ob;
if ((n >= 0) && (n < NUM_NID))
{
if ((n != NID_undef) && (nid_objs[n].nid == NID_undef))
{
OBJerr(OBJ_F_OBJ_NID2LN,OBJ_R_UNKNOWN_NID);
return(NULL);
}
return(nid_objs[n].ln);
}
else if (added == NULL)
return(NULL);
else
{
ad.type=ADDED_NID;
ad.obj= &ob;
ob.nid=n;
adp=(ADDED_OBJ *)lh_retrieve(added,&ad);
if (adp != NULL)
return(adp->obj->ln);
else
{
OBJerr(OBJ_F_OBJ_NID2LN,OBJ_R_UNKNOWN_NID);
return(NULL);
}
}
}
int OBJ_obj2nid(const ASN1_OBJECT *a)
{
ASN1_OBJECT **op;
ADDED_OBJ ad,*adp;
if (a == NULL)
return(NID_undef);
if (a->nid != 0)
return(a->nid);
if (added != NULL)
{
ad.type=ADDED_DATA;
ad.obj=(ASN1_OBJECT *)a;
adp=(ADDED_OBJ *)lh_retrieve(added,&ad);
if (adp != NULL) return (adp->obj->nid);
}
op=(ASN1_OBJECT **)OBJ_bsearch((const char *)&a,(const char *)obj_objs,
NUM_OBJ, sizeof(ASN1_OBJECT *),obj_cmp);
if (op == NULL)
return(NID_undef);
return((*op)->nid);
}
ASN1_OBJECT *OBJ_txt2obj(const char *s, int no_name)
{
int nid = NID_undef;
ASN1_OBJECT *op=NULL;
unsigned char *buf;
unsigned char *p;
const unsigned char *cp;
int i, j;
if(!no_name) {
if( ((nid = OBJ_sn2nid(s)) != NID_undef) ||
((nid = OBJ_ln2nid(s)) != NID_undef) )
return OBJ_nid2obj(nid);
}
i=a2d_ASN1_OBJECT(NULL,0,s,-1);
if (i <= 0) {
ERR_clear_error();
return NULL;
}
j = ASN1_object_size(0,i,V_ASN1_OBJECT);
if((buf=(unsigned char *)OPENSSL_malloc(j)) == NULL) return NULL;
p = buf;
ASN1_put_object(&p,0,i,V_ASN1_OBJECT,V_ASN1_UNIVERSAL);
a2d_ASN1_OBJECT(p,i,s,-1);
cp=buf;
op=d2i_ASN1_OBJECT(NULL,&cp,j);
OPENSSL_free(buf);
return op;
}
int OBJ_obj2txt(char *buf, int buf_len, const ASN1_OBJECT *a, int no_name)
{
int i,idx=0,n=0,len,nid;
unsigned long l;
unsigned char *p;
const char *s;
char tbuf[DECIMAL_SIZE(i)+DECIMAL_SIZE(l)+2];
if (buf_len <= 0) return(0);
if ((a == NULL) || (a->data == NULL)) {
buf[0]='\0';
return(0);
}
if (no_name || (nid=OBJ_obj2nid(a)) == NID_undef) {
len=a->length;
p=a->data;
idx=0;
l=0;
while (idx < a->length) {
l|=(p[idx]&0x7f);
if (!(p[idx] & 0x80)) break;
l<<=7L;
idx++;
}
idx++;
i=(int)(l/40);
if (i > 2) i=2;
l-=(long)(i*40);
BIO_snprintf(tbuf,sizeof tbuf,"%d.%lu",i,l);
i=strlen(tbuf);
BUF_strlcpy(buf,tbuf,buf_len);
buf_len-=i;
buf+=i;
n+=i;
l=0;
for (; idx<len; idx++) {
l|=p[idx]&0x7f;
if (!(p[idx] & 0x80)) {
BIO_snprintf(tbuf,sizeof tbuf,".%lu",l);
i=strlen(tbuf);
if (buf_len > 0)
BUF_strlcpy(buf,tbuf,buf_len);
buf_len-=i;
buf+=i;
n+=i;
l=0;
}
l<<=7L;
}
} else {
s=OBJ_nid2ln(nid);
if (s == NULL)
s=OBJ_nid2sn(nid);
BUF_strlcpy(buf,s,buf_len);
n=strlen(s);
}
return(n);
}
int OBJ_txt2nid(const char *s)
{
ASN1_OBJECT *obj;
int nid;
obj = OBJ_txt2obj(s, 0);
nid = OBJ_obj2nid(obj);
ASN1_OBJECT_free(obj);
return nid;
}
int OBJ_ln2nid(const char *s)
{
ASN1_OBJECT o,*oo= &o,**op;
ADDED_OBJ ad,*adp;
o.ln=s;
if (added != NULL)
{
ad.type=ADDED_LNAME;
ad.obj= &o;
adp=(ADDED_OBJ *)lh_retrieve(added,&ad);
if (adp != NULL) return (adp->obj->nid);
}
op=(ASN1_OBJECT **)OBJ_bsearch((char *)&oo,(char *)ln_objs, NUM_LN,
sizeof(ASN1_OBJECT *),ln_cmp);
if (op == NULL) return(NID_undef);
return((*op)->nid);
}
int OBJ_sn2nid(const char *s)
{
ASN1_OBJECT o,*oo= &o,**op;
ADDED_OBJ ad,*adp;
o.sn=s;
if (added != NULL)
{
ad.type=ADDED_SNAME;
ad.obj= &o;
adp=(ADDED_OBJ *)lh_retrieve(added,&ad);
if (adp != NULL) return (adp->obj->nid);
}
op=(ASN1_OBJECT **)OBJ_bsearch((char *)&oo,(char *)sn_objs,NUM_SN,
sizeof(ASN1_OBJECT *),sn_cmp);
if (op == NULL) return(NID_undef);
return((*op)->nid);
}
static int obj_cmp(const void *ap, const void *bp)
{
int j;
const ASN1_OBJECT *a= *(ASN1_OBJECT * const *)ap;
const ASN1_OBJECT *b= *(ASN1_OBJECT * const *)bp;
j=(a->length - b->length);
if (j) return(j);
return(memcmp(a->data,b->data,a->length));
}
const char *OBJ_bsearch(const char *key, const char *base, int num, int size,
int (*cmp)(const void *, const void *))
{
return OBJ_bsearch_ex(key, base, num, size, cmp, 0);
}
const char *OBJ_bsearch_ex(const char *key, const char *base, int num,
int size, int (*cmp)(const void *, const void *), int flags)
{
int l,h,i=0,c=0;
const char *p = NULL;
if (num == 0) return(NULL);
l=0;
h=num;
while (l < h)
{
i=(l+h)/2;
p= &(base[i*size]);
c=(*cmp)(key,p);
if (c < 0)
h=i;
else if (c > 0)
l=i+1;
else
break;
}
#ifdef CHARSET_EBCDIC
if (c != 0)
{
for (i=0; i<num; ++i)
{
p= &(base[i*size]);
c = (*cmp)(key,p);
if (c == 0 || (c < 0 && (flags & OBJ_BSEARCH_VALUE_ON_NOMATCH)))
return p;
}
}
#endif
if (c != 0 && !(flags & OBJ_BSEARCH_VALUE_ON_NOMATCH))
p = NULL;
else if (c == 0 && (flags & OBJ_BSEARCH_FIRST_VALUE_ON_MATCH))
{
while(i > 0 && (*cmp)(key,&(base[(i-1)*size])) == 0)
i--;
p = &(base[i*size]);
}
return(p);
}
int OBJ_create_objects(BIO *in)
{
MS_STATIC char buf[512];
int i,num=0;
char *o,*s,*l=NULL;
for (;;)
{
s=o=NULL;
i=BIO_gets(in,buf,512);
if (i <= 0) return(num);
buf[i-1]='\0';
if (!isalnum((unsigned char)buf[0])) return(num);
o=s=buf;
while (isdigit((unsigned char)*s) || (*s == '.'))
s++;
if (*s != '\0')
{
*(s++)='\0';
while (isspace((unsigned char)*s))
s++;
if (*s == '\0')
s=NULL;
else
{
l=s;
while ((*l != '\0') && !isspace((unsigned char)*l))
l++;
if (*l != '\0')
{
*(l++)='\0';
while (isspace((unsigned char)*l))
l++;
if (*l == '\0') l=NULL;
}
else
l=NULL;
}
}
else
s=NULL;
if ((o == NULL) || (*o == '\0')) return(num);
if (!OBJ_create(o,s,l)) return(num);
num++;
}
}
int OBJ_create(const char *oid, const char *sn, const char *ln)
{
int ok=0;
ASN1_OBJECT *op=NULL;
unsigned char *buf;
int i;
i=a2d_ASN1_OBJECT(NULL,0,oid,-1);
if (i <= 0) return(0);
if ((buf=(unsigned char *)OPENSSL_malloc(i)) == NULL)
{
OBJerr(OBJ_F_OBJ_CREATE,ERR_R_MALLOC_FAILURE);
return(0);
}
i=a2d_ASN1_OBJECT(buf,i,oid,-1);
if (i == 0)
goto err;
op=(ASN1_OBJECT *)ASN1_OBJECT_create(OBJ_new_nid(1),buf,i,sn,ln);
if (op == NULL)
goto err;
ok=OBJ_add_object(op);
err:
ASN1_OBJECT_free(op);
OPENSSL_free(buf);
return(ok);
}
