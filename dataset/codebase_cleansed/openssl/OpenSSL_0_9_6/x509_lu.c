X509_LOOKUP *X509_LOOKUP_new(X509_LOOKUP_METHOD *method)
{
X509_LOOKUP *ret;
ret=(X509_LOOKUP *)OPENSSL_malloc(sizeof(X509_LOOKUP));
if (ret == NULL) return NULL;
ret->init=0;
ret->skip=0;
ret->method=method;
ret->method_data=NULL;
ret->store_ctx=NULL;
if ((method->new_item != NULL) && !method->new_item(ret))
{
OPENSSL_free(ret);
return NULL;
}
return ret;
}
void X509_LOOKUP_free(X509_LOOKUP *ctx)
{
if (ctx == NULL) return;
if ( (ctx->method != NULL) &&
(ctx->method->free != NULL))
ctx->method->free(ctx);
OPENSSL_free(ctx);
}
int X509_LOOKUP_init(X509_LOOKUP *ctx)
{
if (ctx->method == NULL) return 0;
if (ctx->method->init != NULL)
return ctx->method->init(ctx);
else
return 1;
}
int X509_LOOKUP_shutdown(X509_LOOKUP *ctx)
{
if (ctx->method == NULL) return 0;
if (ctx->method->shutdown != NULL)
return ctx->method->shutdown(ctx);
else
return 1;
}
int X509_LOOKUP_ctrl(X509_LOOKUP *ctx, int cmd, const char *argc, long argl,
char **ret)
{
if (ctx->method == NULL) return -1;
if (ctx->method->ctrl != NULL)
return ctx->method->ctrl(ctx,cmd,argc,argl,ret);
else
return 1;
}
int X509_LOOKUP_by_subject(X509_LOOKUP *ctx, int type, X509_NAME *name,
X509_OBJECT *ret)
{
if ((ctx->method == NULL) || (ctx->method->get_by_subject == NULL))
return X509_LU_FAIL;
if (ctx->skip) return 0;
return ctx->method->get_by_subject(ctx,type,name,ret);
}
int X509_LOOKUP_by_issuer_serial(X509_LOOKUP *ctx, int type, X509_NAME *name,
ASN1_INTEGER *serial, X509_OBJECT *ret)
{
if ((ctx->method == NULL) ||
(ctx->method->get_by_issuer_serial == NULL))
return X509_LU_FAIL;
return ctx->method->get_by_issuer_serial(ctx,type,name,serial,ret);
}
int X509_LOOKUP_by_fingerprint(X509_LOOKUP *ctx, int type,
unsigned char *bytes, int len, X509_OBJECT *ret)
{
if ((ctx->method == NULL) || (ctx->method->get_by_fingerprint == NULL))
return X509_LU_FAIL;
return ctx->method->get_by_fingerprint(ctx,type,bytes,len,ret);
}
int X509_LOOKUP_by_alias(X509_LOOKUP *ctx, int type, char *str, int len,
X509_OBJECT *ret)
{
if ((ctx->method == NULL) || (ctx->method->get_by_alias == NULL))
return X509_LU_FAIL;
return ctx->method->get_by_alias(ctx,type,str,len,ret);
}
static int x509_object_cmp(const X509_OBJECT * const *a, const X509_OBJECT * const *b)
{
int ret;
ret=((*a)->type - (*b)->type);
if (ret) return ret;
switch ((*a)->type)
{
case X509_LU_X509:
ret=X509_subject_name_cmp((*a)->data.x509,(*b)->data.x509);
break;
case X509_LU_CRL:
ret=X509_CRL_cmp((*a)->data.crl,(*b)->data.crl);
break;
default:
return 0;
}
return ret;
}
X509_STORE *X509_STORE_new(void)
{
X509_STORE *ret;
if ((ret=(X509_STORE *)OPENSSL_malloc(sizeof(X509_STORE))) == NULL)
return NULL;
ret->objs = sk_X509_OBJECT_new(x509_object_cmp);
ret->cache=1;
ret->get_cert_methods=sk_X509_LOOKUP_new_null();
ret->verify=NULL;
ret->verify_cb=NULL;
memset(&ret->ex_data,0,sizeof(CRYPTO_EX_DATA));
ret->references=1;
ret->depth=0;
return ret;
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
{
}
OPENSSL_free(a);
}
void X509_STORE_free(X509_STORE *vfy)
{
int i;
STACK_OF(X509_LOOKUP) *sk;
X509_LOOKUP *lu;
if (vfy == NULL)
return;
sk=vfy->get_cert_methods;
for (i=0; i<sk_X509_LOOKUP_num(sk); i++)
{
lu=sk_X509_LOOKUP_value(sk,i);
X509_LOOKUP_shutdown(lu);
X509_LOOKUP_free(lu);
}
sk_X509_LOOKUP_free(sk);
sk_X509_OBJECT_pop_free(vfy->objs, cleanup);
CRYPTO_free_ex_data(x509_store_meth,vfy,&vfy->ex_data);
OPENSSL_free(vfy);
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
return lu;
}
}
lu=X509_LOOKUP_new(m);
if (lu == NULL)
return NULL;
else
{
lu->store_ctx=v;
if (sk_X509_LOOKUP_push(v->get_cert_methods,lu))
return lu;
else
{
X509_LOOKUP_free(lu);
return NULL;
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
tmp=X509_OBJECT_retrieve_by_subject(ctx->objs,type,name);
if (tmp == NULL)
{
for (i=vs->current_method; i<sk_X509_LOOKUP_num(ctx->get_cert_methods); i++)
{
lu=sk_X509_LOOKUP_value(ctx->get_cert_methods,i);
j=X509_LOOKUP_by_subject(lu,type,name,&stmp);
if (j < 0)
{
vs->current_method=j;
return j;
}
else if (j)
{
tmp= &stmp;
break;
}
}
vs->current_method=0;
if (tmp == NULL)
return 0;
}
ret->type=tmp->type;
ret->data.ptr=tmp->data.ptr;
X509_OBJECT_up_ref_count(ret);
return 1;
}
int X509_STORE_add_cert(X509_STORE *ctx, X509 *x)
{
X509_OBJECT *obj;
int ret=1;
if (x == NULL) return 0;
obj=(X509_OBJECT *)OPENSSL_malloc(sizeof(X509_OBJECT));
if (obj == NULL)
{
X509err(X509_F_X509_STORE_ADD_CERT,ERR_R_MALLOC_FAILURE);
return 0;
}
obj->type=X509_LU_X509;
obj->data.x509=x;
CRYPTO_w_lock(CRYPTO_LOCK_X509_STORE);
X509_OBJECT_up_ref_count(obj);
if (X509_OBJECT_retrieve_match(ctx->objs, obj))
{
X509_OBJECT_free_contents(obj);
OPENSSL_free(obj);
X509err(X509_F_X509_STORE_ADD_CERT,X509_R_CERT_ALREADY_IN_HASH_TABLE);
ret=0;
}
else sk_X509_OBJECT_push(ctx->objs, obj);
CRYPTO_w_unlock(CRYPTO_LOCK_X509_STORE);
return ret;
}
int X509_STORE_add_crl(X509_STORE *ctx, X509_CRL *x)
{
X509_OBJECT *obj;
int ret=1;
if (x == NULL) return 0;
obj=(X509_OBJECT *)OPENSSL_malloc(sizeof(X509_OBJECT));
if (obj == NULL)
{
X509err(X509_F_X509_STORE_ADD_CRL,ERR_R_MALLOC_FAILURE);
return 0;
}
obj->type=X509_LU_CRL;
obj->data.crl=x;
CRYPTO_w_lock(CRYPTO_LOCK_X509_STORE);
X509_OBJECT_up_ref_count(obj);
if (X509_OBJECT_retrieve_match(ctx->objs, obj))
{
X509_OBJECT_free_contents(obj);
OPENSSL_free(obj);
X509err(X509_F_X509_STORE_ADD_CRL,X509_R_CERT_ALREADY_IN_HASH_TABLE);
ret=0;
}
else sk_X509_OBJECT_push(ctx->objs, obj);
CRYPTO_w_unlock(CRYPTO_LOCK_X509_STORE);
return ret;
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
int X509_STORE_CTX_get1_issuer(X509 **issuer, X509_STORE_CTX *ctx, X509 *x)
{
X509_NAME *xn;
X509_OBJECT obj, *pobj;
int i, ok, idx;
xn=X509_get_issuer_name(x);
ok=X509_STORE_get_by_subject(ctx,X509_LU_X509,xn,&obj);
if (ok != X509_LU_X509)
{
if (ok == X509_LU_RETRY)
{
X509_OBJECT_free_contents(&obj);
X509err(X509_F_X509_VERIFY_CERT,X509_R_SHOULD_RETRY);
return -1;
}
else if (ok != X509_LU_FAIL)
{
X509_OBJECT_free_contents(&obj);
return -1;
}
return 0;
}
if (ctx->check_issued(ctx, x, obj.data.x509))
{
*issuer = obj.data.x509;
return 1;
}
X509_OBJECT_free_contents(&obj);
idx = X509_OBJECT_idx_by_subject(ctx->ctx->objs, X509_LU_X509, xn);
if (idx == -1) return 0;
for (i = idx; i < sk_X509_OBJECT_num(ctx->ctx->objs); i++)
{
pobj = sk_X509_OBJECT_value(ctx->ctx->objs, i);
if (pobj->type != X509_LU_X509) return 0;
if (X509_NAME_cmp(xn, X509_get_subject_name(pobj->data.x509))) return 0;
if (ctx->check_issued(ctx, x, pobj->data.x509))
{
*issuer = pobj->data.x509;
X509_OBJECT_up_ref_count(pobj);
return 1;
}
}
return 0;
}
