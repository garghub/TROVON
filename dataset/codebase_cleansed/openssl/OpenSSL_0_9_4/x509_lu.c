X509_LOOKUP *X509_LOOKUP_new(X509_LOOKUP_METHOD *method)
{
X509_LOOKUP *ret;
ret=(X509_LOOKUP *)Malloc(sizeof(X509_LOOKUP));
if (ret == NULL) return(NULL);
ret->init=0;
ret->skip=0;
ret->method=method;
ret->method_data=NULL;
ret->store_ctx=NULL;
if ((method->new_item != NULL) && !method->new_item(ret))
{
Free(ret);
return(NULL);
}
return(ret);
}
void X509_LOOKUP_free(X509_LOOKUP *ctx)
{
if (ctx == NULL) return;
if ( (ctx->method != NULL) &&
(ctx->method->free != NULL))
ctx->method->free(ctx);
Free(ctx);
}
int X509_LOOKUP_init(X509_LOOKUP *ctx)
{
if (ctx->method == NULL) return(0);
if (ctx->method->init != NULL)
return(ctx->method->init(ctx));
else
return(1);
}
int X509_LOOKUP_shutdown(X509_LOOKUP *ctx)
{
if (ctx->method == NULL) return(0);
if (ctx->method->shutdown != NULL)
return(ctx->method->shutdown(ctx));
else
return(1);
}
int X509_LOOKUP_ctrl(X509_LOOKUP *ctx, int cmd, const char *argc, long argl,
char **ret)
{
if (ctx->method == NULL) return(-1);
if (ctx->method->ctrl != NULL)
return(ctx->method->ctrl(ctx,cmd,argc,argl,ret));
else
return(1);
}
int X509_LOOKUP_by_subject(X509_LOOKUP *ctx, int type, X509_NAME *name,
X509_OBJECT *ret)
{
if ((ctx->method == NULL) || (ctx->method->get_by_subject == NULL))
return(X509_LU_FAIL);
if (ctx->skip) return(0);
return(ctx->method->get_by_subject(ctx,type,name,ret));
}
int X509_LOOKUP_by_issuer_serial(X509_LOOKUP *ctx, int type, X509_NAME *name,
ASN1_INTEGER *serial, X509_OBJECT *ret)
{
if ((ctx->method == NULL) ||
(ctx->method->get_by_issuer_serial == NULL))
return(X509_LU_FAIL);
return(ctx->method->get_by_issuer_serial(ctx,type,name,serial,ret));
}
int X509_LOOKUP_by_fingerprint(X509_LOOKUP *ctx, int type,
unsigned char *bytes, int len, X509_OBJECT *ret)
{
if ((ctx->method == NULL) || (ctx->method->get_by_fingerprint == NULL))
return(X509_LU_FAIL);
return(ctx->method->get_by_fingerprint(ctx,type,bytes,len,ret));
}
int X509_LOOKUP_by_alias(X509_LOOKUP *ctx, int type, char *str, int len,
X509_OBJECT *ret)
{
if ((ctx->method == NULL) || (ctx->method->get_by_alias == NULL))
return(X509_LU_FAIL);
return(ctx->method->get_by_alias(ctx,type,str,len,ret));
}
static unsigned long x509_object_hash(X509_OBJECT *a)
{
unsigned long h;
switch (a->type)
{
case X509_LU_X509:
h=X509_NAME_hash(a->data.x509->cert_info->subject);
break;
case X509_LU_CRL:
h=X509_NAME_hash(a->data.crl->crl->issuer);
break;
default:
abort();
}
return(h);
}
static int x509_object_cmp(X509_OBJECT *a, X509_OBJECT *b)
{
int ret;
ret=(a->type - b->type);
if (ret) return(ret);
switch (a->type)
{
case X509_LU_X509:
ret=X509_subject_name_cmp(a->data.x509,b->data.x509);
break;
case X509_LU_CRL:
ret=X509_CRL_cmp(a->data.crl,b->data.crl);
break;
default:
abort();
}
return(ret);
}
X509_STORE *X509_STORE_new(void)
{
X509_STORE *ret;
if ((ret=(X509_STORE *)Malloc(sizeof(X509_STORE))) == NULL)
return(NULL);
ret->certs=lh_new(x509_object_hash,x509_object_cmp);
ret->cache=1;
ret->get_cert_methods=sk_X509_LOOKUP_new_null();
ret->verify=NULL;
ret->verify_cb=NULL;
memset(&ret->ex_data,0,sizeof(CRYPTO_EX_DATA));
ret->references=1;
ret->depth=0;
return(ret);
}
static void cleanup(X509_OBJECT *a)
{
if (a->type == X509_LU_X509)
{
X509_free(a->data.x509);
}
else if (a->type == X509_LU_CRL)
{
X509_CRL_free(a->data.crl);
}
else
abort();
Free(a);
}
void X509_STORE_free(X509_STORE *vfy)
{
int i;
STACK_OF(X509_LOOKUP) *sk;
X509_LOOKUP *lu;
if(vfy == NULL)
return;
sk=vfy->get_cert_methods;
for (i=0; i<sk_X509_LOOKUP_num(sk); i++)
{
lu=sk_X509_LOOKUP_value(sk,i);
X509_LOOKUP_shutdown(lu);
X509_LOOKUP_free(lu);
}
sk_X509_LOOKUP_free(sk);
CRYPTO_free_ex_data(x509_store_meth,(char *)vfy,&vfy->ex_data);
lh_doall(vfy->certs,cleanup);
lh_free(vfy->certs);
Free(vfy);
}
X509_LOOKUP *X509_STORE_add_lookup(X509_STORE *v, X509_LOOKUP_METHOD *m)
{
int i;
STACK_OF(X509_LOOKUP) *sk;
X509_LOOKUP *lu;
sk=v->get_cert_methods;
for (i=0; i<sk_X509_LOOKUP_num(sk); i++)
{
lu=sk_X509_LOOKUP_value(sk,i);
if (m == lu->method)
{
return(lu);
}
}
lu=X509_LOOKUP_new(m);
if (lu == NULL)
return(NULL);
else
{
lu->store_ctx=v;
if (sk_X509_LOOKUP_push(v->get_cert_methods,lu))
return(lu);
else
{
X509_LOOKUP_free(lu);
return(NULL);
}
}
}
int X509_STORE_get_by_subject(X509_STORE_CTX *vs, int type, X509_NAME *name,
X509_OBJECT *ret)
{
X509_STORE *ctx=vs->ctx;
X509_LOOKUP *lu;
X509_OBJECT stmp,*tmp;
int i,j;
tmp=X509_OBJECT_retrieve_by_subject(ctx->certs,type,name);
if (tmp == NULL)
{
for (i=vs->current_method; i<sk_X509_LOOKUP_num(ctx->get_cert_methods); i++)
{
lu=sk_X509_LOOKUP_value(ctx->get_cert_methods,i);
j=X509_LOOKUP_by_subject(lu,type,name,&stmp);
if (j < 0)
{
vs->current_method=j;
return(j);
}
else if (j)
{
tmp= &stmp;
break;
}
}
vs->current_method=0;
if (tmp == NULL)
return(0);
}
ret->type=tmp->type;
ret->data.ptr=tmp->data.ptr;
X509_OBJECT_up_ref_count(ret);
return(1);
}
void X509_OBJECT_up_ref_count(X509_OBJECT *a)
{
switch (a->type)
{
case X509_LU_X509:
CRYPTO_add(&a->data.x509->references,1,CRYPTO_LOCK_X509);
break;
case X509_LU_CRL:
CRYPTO_add(&a->data.crl->references,1,CRYPTO_LOCK_X509_CRL);
break;
}
}
void X509_OBJECT_free_contents(X509_OBJECT *a)
{
switch (a->type)
{
case X509_LU_X509:
X509_free(a->data.x509);
break;
case X509_LU_CRL:
X509_CRL_free(a->data.crl);
break;
}
}
X509_OBJECT *X509_OBJECT_retrieve_by_subject(LHASH *h, int type,
X509_NAME *name)
{
X509_OBJECT stmp,*tmp;
X509 x509_s;
X509_CINF cinf_s;
X509_CRL crl_s;
X509_CRL_INFO crl_info_s;
stmp.type=type;
switch (type)
{
case X509_LU_X509:
stmp.data.x509= &x509_s;
x509_s.cert_info= &cinf_s;
cinf_s.subject=name;
break;
case X509_LU_CRL:
stmp.data.crl= &crl_s;
crl_s.crl= &crl_info_s;
crl_info_s.issuer=name;
break;
default:
abort();
}
tmp=(X509_OBJECT *)lh_retrieve(h,(char *)&stmp);
return(tmp);
}
void X509_STORE_CTX_cleanup(X509_STORE_CTX *ctx)
{
if (ctx->chain != NULL)
{
sk_X509_pop_free(ctx->chain,X509_free);
ctx->chain=NULL;
}
CRYPTO_free_ex_data(x509_store_ctx_meth,(char *)ctx,&(ctx->ex_data));
memset(&ctx->ex_data,0,sizeof(CRYPTO_EX_DATA));
}
