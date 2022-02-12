X509_LOOKUP *X509_LOOKUP_new(X509_LOOKUP_METHOD *method)
{
X509_LOOKUP *ret;
ret = OPENSSL_zalloc(sizeof(*ret));
if (ret == NULL)
return NULL;
ret->method = method;
if ((method->new_item != NULL) && !method->new_item(ret)) {
OPENSSL_free(ret);
return NULL;
}
return ret;
}
void X509_LOOKUP_free(X509_LOOKUP *ctx)
{
if (ctx == NULL)
return;
if ((ctx->method != NULL) && (ctx->method->free != NULL))
(*ctx->method->free) (ctx);
OPENSSL_free(ctx);
}
int X509_STORE_lock(X509_STORE *s)
{
return CRYPTO_THREAD_write_lock(s->lock);
}
int X509_STORE_unlock(X509_STORE *s)
{
return CRYPTO_THREAD_unlock(s->lock);
}
int X509_LOOKUP_init(X509_LOOKUP *ctx)
{
if (ctx->method == NULL)
return 0;
if (ctx->method->init != NULL)
return ctx->method->init(ctx);
else
return 1;
}
int X509_LOOKUP_shutdown(X509_LOOKUP *ctx)
{
if (ctx->method == NULL)
return 0;
if (ctx->method->shutdown != NULL)
return ctx->method->shutdown(ctx);
else
return 1;
}
int X509_LOOKUP_ctrl(X509_LOOKUP *ctx, int cmd, const char *argc, long argl,
char **ret)
{
if (ctx->method == NULL)
return -1;
if (ctx->method->ctrl != NULL)
return ctx->method->ctrl(ctx, cmd, argc, argl, ret);
else
return 1;
}
int X509_LOOKUP_by_subject(X509_LOOKUP *ctx, X509_LOOKUP_TYPE type,
X509_NAME *name, X509_OBJECT *ret)
{
if ((ctx->method == NULL) || (ctx->method->get_by_subject == NULL))
return 0;
if (ctx->skip)
return 0;
return ctx->method->get_by_subject(ctx, type, name, ret);
}
int X509_LOOKUP_by_issuer_serial(X509_LOOKUP *ctx, X509_LOOKUP_TYPE type,
X509_NAME *name, ASN1_INTEGER *serial,
X509_OBJECT *ret)
{
if ((ctx->method == NULL) || (ctx->method->get_by_issuer_serial == NULL))
return 0;
return ctx->method->get_by_issuer_serial(ctx, type, name, serial, ret);
}
int X509_LOOKUP_by_fingerprint(X509_LOOKUP *ctx, X509_LOOKUP_TYPE type,
const unsigned char *bytes, int len,
X509_OBJECT *ret)
{
if ((ctx->method == NULL) || (ctx->method->get_by_fingerprint == NULL))
return 0;
return ctx->method->get_by_fingerprint(ctx, type, bytes, len, ret);
}
int X509_LOOKUP_by_alias(X509_LOOKUP *ctx, X509_LOOKUP_TYPE type,
const char *str, int len, X509_OBJECT *ret)
{
if ((ctx->method == NULL) || (ctx->method->get_by_alias == NULL))
return 0;
return ctx->method->get_by_alias(ctx, type, str, len, ret);
}
static int x509_object_cmp(const X509_OBJECT *const *a,
const X509_OBJECT *const *b)
{
int ret;
ret = ((*a)->type - (*b)->type);
if (ret)
return ret;
switch ((*a)->type) {
case X509_LU_X509:
ret = X509_subject_name_cmp((*a)->data.x509, (*b)->data.x509);
break;
case X509_LU_CRL:
ret = X509_CRL_cmp((*a)->data.crl, (*b)->data.crl);
break;
default:
return 0;
}
return ret;
}
X509_STORE *X509_STORE_new(void)
{
X509_STORE *ret;
if ((ret = OPENSSL_zalloc(sizeof(*ret))) == NULL)
return NULL;
if ((ret->objs = sk_X509_OBJECT_new(x509_object_cmp)) == NULL)
goto err;
ret->cache = 1;
if ((ret->get_cert_methods = sk_X509_LOOKUP_new_null()) == NULL)
goto err;
if ((ret->param = X509_VERIFY_PARAM_new()) == NULL)
goto err;
if (!CRYPTO_new_ex_data(CRYPTO_EX_INDEX_X509_STORE, ret, &ret->ex_data))
goto err;
ret->lock = CRYPTO_THREAD_lock_new();
if (ret->lock == NULL)
goto err;
ret->references = 1;
return ret;
err:
X509_VERIFY_PARAM_free(ret->param);
sk_X509_OBJECT_free(ret->objs);
sk_X509_LOOKUP_free(ret->get_cert_methods);
OPENSSL_free(ret);
return NULL;
}
static void cleanup(X509_OBJECT *a)
{
if (!a)
return;
if (a->type == X509_LU_X509) {
X509_free(a->data.x509);
} else if (a->type == X509_LU_CRL) {
X509_CRL_free(a->data.crl);
} else {
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
CRYPTO_atomic_add(&vfy->references, -1, &i, vfy->lock);
REF_PRINT_COUNT("X509_STORE", vfy);
if (i > 0)
return;
REF_ASSERT_ISNT(i < 0);
sk = vfy->get_cert_methods;
for (i = 0; i < sk_X509_LOOKUP_num(sk); i++) {
lu = sk_X509_LOOKUP_value(sk, i);
X509_LOOKUP_shutdown(lu);
X509_LOOKUP_free(lu);
}
sk_X509_LOOKUP_free(sk);
sk_X509_OBJECT_pop_free(vfy->objs, cleanup);
CRYPTO_free_ex_data(CRYPTO_EX_INDEX_X509_STORE, vfy, &vfy->ex_data);
X509_VERIFY_PARAM_free(vfy->param);
CRYPTO_THREAD_lock_free(vfy->lock);
OPENSSL_free(vfy);
}
int X509_STORE_up_ref(X509_STORE *vfy)
{
int i;
if (CRYPTO_atomic_add(&vfy->references, 1, &i, vfy->lock) <= 0)
return 0;
REF_PRINT_COUNT("X509_STORE", a);
REF_ASSERT_ISNT(i < 2);
return ((i > 1) ? 1 : 0);
}
X509_LOOKUP *X509_STORE_add_lookup(X509_STORE *v, X509_LOOKUP_METHOD *m)
{
int i;
STACK_OF(X509_LOOKUP) *sk;
X509_LOOKUP *lu;
sk = v->get_cert_methods;
for (i = 0; i < sk_X509_LOOKUP_num(sk); i++) {
lu = sk_X509_LOOKUP_value(sk, i);
if (m == lu->method) {
return lu;
}
}
lu = X509_LOOKUP_new(m);
if (lu == NULL)
return NULL;
else {
lu->store_ctx = v;
if (sk_X509_LOOKUP_push(v->get_cert_methods, lu))
return lu;
else {
X509_LOOKUP_free(lu);
return NULL;
}
}
}
X509_OBJECT *X509_STORE_CTX_get_obj_by_subject(X509_STORE_CTX *vs,
X509_LOOKUP_TYPE type,
X509_NAME *name)
{
X509_OBJECT *ret = X509_OBJECT_new();
if (ret == NULL)
return NULL;
if (!X509_STORE_CTX_get_by_subject(vs, type, name, ret)) {
X509_OBJECT_free(ret);
return NULL;
}
return ret;
}
int X509_STORE_CTX_get_by_subject(X509_STORE_CTX *vs, X509_LOOKUP_TYPE type,
X509_NAME *name, X509_OBJECT *ret)
{
X509_STORE *ctx = vs->ctx;
X509_LOOKUP *lu;
X509_OBJECT stmp, *tmp;
int i, j;
CRYPTO_THREAD_write_lock(ctx->lock);
tmp = X509_OBJECT_retrieve_by_subject(ctx->objs, type, name);
CRYPTO_THREAD_unlock(ctx->lock);
if (tmp == NULL || type == X509_LU_CRL) {
for (i = 0; i < sk_X509_LOOKUP_num(ctx->get_cert_methods); i++) {
lu = sk_X509_LOOKUP_value(ctx->get_cert_methods, i);
j = X509_LOOKUP_by_subject(lu, type, name, &stmp);
if (j) {
tmp = &stmp;
break;
}
}
if (tmp == NULL)
return 0;
}
ret->type = tmp->type;
ret->data.ptr = tmp->data.ptr;
X509_OBJECT_up_ref_count(ret);
return 1;
}
int X509_STORE_add_cert(X509_STORE *ctx, X509 *x)
{
X509_OBJECT *obj;
int ret = 1, added = 1;
if (x == NULL)
return 0;
obj = X509_OBJECT_new();
if (obj == NULL)
return 0;
obj->type = X509_LU_X509;
obj->data.x509 = x;
X509_OBJECT_up_ref_count(obj);
CRYPTO_THREAD_write_lock(ctx->lock);
if (X509_OBJECT_retrieve_match(ctx->objs, obj)) {
X509err(X509_F_X509_STORE_ADD_CERT,
X509_R_CERT_ALREADY_IN_HASH_TABLE);
ret = 0;
} else {
added = sk_X509_OBJECT_push(ctx->objs, obj);
ret = added != 0;
}
CRYPTO_THREAD_unlock(ctx->lock);
if (!ret)
X509_OBJECT_free(obj);
if (!added)
X509err(X509_F_X509_STORE_ADD_CERT, ERR_R_MALLOC_FAILURE);
return ret;
}
int X509_STORE_add_crl(X509_STORE *ctx, X509_CRL *x)
{
X509_OBJECT *obj;
int ret = 1, added = 1;
if (x == NULL)
return 0;
obj = X509_OBJECT_new();
if (obj == NULL)
return 0;
obj->type = X509_LU_CRL;
obj->data.crl = x;
X509_OBJECT_up_ref_count(obj);
CRYPTO_THREAD_write_lock(ctx->lock);
if (X509_OBJECT_retrieve_match(ctx->objs, obj)) {
X509err(X509_F_X509_STORE_ADD_CRL, X509_R_CERT_ALREADY_IN_HASH_TABLE);
ret = 0;
} else {
added = sk_X509_OBJECT_push(ctx->objs, obj);
ret = added != 0;
}
CRYPTO_THREAD_unlock(ctx->lock);
if (!ret)
X509_OBJECT_free(obj);
if (!added)
X509err(X509_F_X509_STORE_ADD_CRL, ERR_R_MALLOC_FAILURE);
return ret;
}
int X509_OBJECT_up_ref_count(X509_OBJECT *a)
{
switch (a->type) {
default:
break;
case X509_LU_X509:
return X509_up_ref(a->data.x509);
case X509_LU_CRL:
return X509_CRL_up_ref(a->data.crl);
}
return 1;
}
X509 *X509_OBJECT_get0_X509(const X509_OBJECT *a)
{
if (a == NULL || a->type != X509_LU_X509)
return NULL;
return a->data.x509;
}
X509_CRL *X509_OBJECT_get0_X509_CRL(X509_OBJECT *a)
{
if (a == NULL || a->type != X509_LU_CRL)
return NULL;
return a->data.crl;
}
X509_LOOKUP_TYPE X509_OBJECT_get_type(const X509_OBJECT *a)
{
return a->type;
}
X509_OBJECT *X509_OBJECT_new()
{
X509_OBJECT *ret = OPENSSL_zalloc(sizeof(*ret));
if (ret == NULL) {
X509err(X509_F_X509_OBJECT_NEW, ERR_R_MALLOC_FAILURE);
return NULL;
}
ret->type = X509_LU_NONE;
return ret;
}
void X509_OBJECT_free(X509_OBJECT *a)
{
if (a == NULL)
return;
switch (a->type) {
default:
break;
case X509_LU_X509:
X509_free(a->data.x509);
break;
case X509_LU_CRL:
X509_CRL_free(a->data.crl);
break;
}
OPENSSL_free(a);
}
int X509_STORE_set_flags(X509_STORE *ctx, unsigned long flags)
{
return X509_VERIFY_PARAM_set_flags(ctx->param, flags);
}
int X509_STORE_set_depth(X509_STORE *ctx, int depth)
{
X509_VERIFY_PARAM_set_depth(ctx->param, depth);
return 1;
}
int X509_STORE_set_purpose(X509_STORE *ctx, int purpose)
{
return X509_VERIFY_PARAM_set_purpose(ctx->param, purpose);
}
int X509_STORE_set_trust(X509_STORE *ctx, int trust)
{
return X509_VERIFY_PARAM_set_trust(ctx->param, trust);
}
int X509_STORE_set1_param(X509_STORE *ctx, X509_VERIFY_PARAM *param)
{
return X509_VERIFY_PARAM_set1(ctx->param, param);
}
X509_VERIFY_PARAM *X509_STORE_get0_param(X509_STORE *ctx)
{
return ctx->param;
}
void X509_STORE_set_verify(X509_STORE *ctx, X509_STORE_CTX_verify_fn verify)
{
ctx->verify = verify;
}
X509_STORE_CTX_verify_fn X509_STORE_get_verify(X509_STORE *ctx)
{
return ctx->verify;
}
void X509_STORE_set_verify_cb(X509_STORE *ctx,
X509_STORE_CTX_verify_cb verify_cb)
{
ctx->verify_cb = verify_cb;
}
X509_STORE_CTX_verify_cb X509_STORE_get_verify_cb(X509_STORE *ctx)
{
return ctx->verify_cb;
}
void X509_STORE_set_get_issuer(X509_STORE *ctx,
X509_STORE_CTX_get_issuer_fn get_issuer)
{
ctx->get_issuer = get_issuer;
}
X509_STORE_CTX_get_issuer_fn X509_STORE_get_get_issuer(X509_STORE *ctx)
{
return ctx->get_issuer;
}
void X509_STORE_set_check_issued(X509_STORE *ctx,
X509_STORE_CTX_check_issued_fn check_issued)
{
ctx->check_issued = check_issued;
}
X509_STORE_CTX_check_issued_fn X509_STORE_get_check_issued(X509_STORE *ctx)
{
return ctx->check_issued;
}
void X509_STORE_set_check_revocation(X509_STORE *ctx,
X509_STORE_CTX_check_revocation_fn check_revocation)
{
ctx->check_revocation = check_revocation;
}
X509_STORE_CTX_check_revocation_fn X509_STORE_get_check_revocation(X509_STORE *ctx)
{
return ctx->check_revocation;
}
void X509_STORE_set_get_crl(X509_STORE *ctx,
X509_STORE_CTX_get_crl_fn get_crl)
{
ctx->get_crl = get_crl;
}
X509_STORE_CTX_get_crl_fn X509_STORE_get_get_crl(X509_STORE *ctx)
{
return ctx->get_crl;
}
void X509_STORE_set_check_crl(X509_STORE *ctx,
X509_STORE_CTX_check_crl_fn check_crl)
{
ctx->check_crl = check_crl;
}
X509_STORE_CTX_check_crl_fn X509_STORE_get_check_crl(X509_STORE *ctx)
{
return ctx->check_crl;
}
void X509_STORE_set_cert_crl(X509_STORE *ctx,
X509_STORE_CTX_cert_crl_fn cert_crl)
{
ctx->cert_crl = cert_crl;
}
X509_STORE_CTX_cert_crl_fn X509_STORE_get_cert_crl(X509_STORE *ctx)
{
return ctx->cert_crl;
}
void X509_STORE_set_check_policy(X509_STORE *ctx,
X509_STORE_CTX_check_policy_fn check_policy)
{
ctx->check_policy = check_policy;
}
X509_STORE_CTX_check_policy_fn X509_STORE_get_check_policy(X509_STORE *ctx)
{
return ctx->check_policy;
}
void X509_STORE_set_lookup_certs(X509_STORE *ctx,
X509_STORE_CTX_lookup_certs_fn lookup_certs)
{
ctx->lookup_certs = lookup_certs;
}
X509_STORE_CTX_lookup_certs_fn X509_STORE_get_lookup_certs(X509_STORE *ctx)
{
return ctx->lookup_certs;
}
void X509_STORE_set_lookup_crls(X509_STORE *ctx,
X509_STORE_CTX_lookup_crls_fn lookup_crls)
{
ctx->lookup_crls = lookup_crls;
}
X509_STORE_CTX_lookup_crls_fn X509_STORE_get_lookup_crls(X509_STORE *ctx)
{
return ctx->lookup_crls;
}
void X509_STORE_set_cleanup(X509_STORE *ctx,
X509_STORE_CTX_cleanup_fn ctx_cleanup)
{
ctx->cleanup = ctx_cleanup;
}
X509_STORE_CTX_cleanup_fn X509_STORE_get_cleanup(X509_STORE *ctx)
{
return ctx->cleanup;
}
int X509_STORE_set_ex_data(X509_STORE *ctx, int idx, void *data)
{
return CRYPTO_set_ex_data(&ctx->ex_data, idx, data);
}
void *X509_STORE_get_ex_data(X509_STORE *ctx, int idx)
{
return CRYPTO_get_ex_data(&ctx->ex_data, idx);
}
X509_STORE *X509_STORE_CTX_get0_store(X509_STORE_CTX *ctx)
{
return ctx->ctx;
}
