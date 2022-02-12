static int tr_cmp(const X509_TRUST *const *a, const X509_TRUST *const *b)
{
return (*a)->trust - (*b)->trust;
}
int X509_check_trust(X509 *x, int id, int flags)
{
X509_TRUST *pt;
int idx;
if (id == X509_TRUST_DEFAULT)
return obj_trust(NID_anyExtendedKeyUsage, x,
flags | X509_TRUST_DO_SS_COMPAT);
idx = X509_TRUST_get_by_id(id);
if (idx == -1)
return default_trust(id, x, flags);
pt = X509_TRUST_get0(idx);
return pt->check_trust(pt, x, flags);
}
int X509_TRUST_get_count(void)
{
if (!trtable)
return X509_TRUST_COUNT;
return sk_X509_TRUST_num(trtable) + X509_TRUST_COUNT;
}
X509_TRUST *X509_TRUST_get0(int idx)
{
if (idx < 0)
return NULL;
if (idx < (int)X509_TRUST_COUNT)
return trstandard + idx;
return sk_X509_TRUST_value(trtable, idx - X509_TRUST_COUNT);
}
int X509_TRUST_get_by_id(int id)
{
X509_TRUST tmp;
int idx;
if ((id >= X509_TRUST_MIN) && (id <= X509_TRUST_MAX))
return id - X509_TRUST_MIN;
tmp.trust = id;
if (!trtable)
return -1;
idx = sk_X509_TRUST_find(trtable, &tmp);
if (idx == -1)
return -1;
return idx + X509_TRUST_COUNT;
}
int X509_TRUST_set(int *t, int trust)
{
if (X509_TRUST_get_by_id(trust) == -1) {
X509err(X509_F_X509_TRUST_SET, X509_R_INVALID_TRUST);
return 0;
}
*t = trust;
return 1;
}
int X509_TRUST_add(int id, int flags, int (*ck) (X509_TRUST *, X509 *, int),
const char *name, int arg1, void *arg2)
{
int idx;
X509_TRUST *trtmp;
flags &= ~X509_TRUST_DYNAMIC;
flags |= X509_TRUST_DYNAMIC_NAME;
idx = X509_TRUST_get_by_id(id);
if (idx == -1) {
if ((trtmp = OPENSSL_malloc(sizeof(*trtmp))) == NULL) {
X509err(X509_F_X509_TRUST_ADD, ERR_R_MALLOC_FAILURE);
return 0;
}
trtmp->flags = X509_TRUST_DYNAMIC;
} else
trtmp = X509_TRUST_get0(idx);
if (trtmp->flags & X509_TRUST_DYNAMIC_NAME)
OPENSSL_free(trtmp->name);
if ((trtmp->name = OPENSSL_strdup(name)) == NULL) {
X509err(X509_F_X509_TRUST_ADD, ERR_R_MALLOC_FAILURE);
goto err;
}
trtmp->flags &= X509_TRUST_DYNAMIC;
trtmp->flags |= flags;
trtmp->trust = id;
trtmp->check_trust = ck;
trtmp->arg1 = arg1;
trtmp->arg2 = arg2;
if (idx == -1) {
if (trtable == NULL
&& (trtable = sk_X509_TRUST_new(tr_cmp)) == NULL) {
X509err(X509_F_X509_TRUST_ADD, ERR_R_MALLOC_FAILURE);
goto err;;
}
if (!sk_X509_TRUST_push(trtable, trtmp)) {
X509err(X509_F_X509_TRUST_ADD, ERR_R_MALLOC_FAILURE);
goto err;
}
}
return 1;
err:
if (idx == -1) {
OPENSSL_free(trtmp->name);
OPENSSL_free(trtmp);
}
return 0;
}
static void trtable_free(X509_TRUST *p)
{
if (!p)
return;
if (p->flags & X509_TRUST_DYNAMIC) {
if (p->flags & X509_TRUST_DYNAMIC_NAME)
OPENSSL_free(p->name);
OPENSSL_free(p);
}
}
void X509_TRUST_cleanup(void)
{
sk_X509_TRUST_pop_free(trtable, trtable_free);
trtable = NULL;
}
int X509_TRUST_get_flags(const X509_TRUST *xp)
{
return xp->flags;
}
char *X509_TRUST_get0_name(const X509_TRUST *xp)
{
return xp->name;
}
int X509_TRUST_get_trust(const X509_TRUST *xp)
{
return xp->trust;
}
static int trust_1oidany(X509_TRUST *trust, X509 *x, int flags)
{
flags |= X509_TRUST_DO_SS_COMPAT | X509_TRUST_OK_ANY_EKU;
return obj_trust(trust->arg1, x, flags);
}
static int trust_1oid(X509_TRUST *trust, X509 *x, int flags)
{
flags &= ~(X509_TRUST_DO_SS_COMPAT | X509_TRUST_OK_ANY_EKU);
return obj_trust(trust->arg1, x, flags);
}
static int trust_compat(X509_TRUST *trust, X509 *x, int flags)
{
X509_check_purpose(x, -1, 0);
if ((flags & X509_TRUST_NO_SS_COMPAT) == 0 && x->ex_flags & EXFLAG_SS)
return X509_TRUST_TRUSTED;
else
return X509_TRUST_UNTRUSTED;
}
static int obj_trust(int id, X509 *x, int flags)
{
X509_CERT_AUX *ax = x->aux;
int i;
if (ax && ax->reject) {
for (i = 0; i < sk_ASN1_OBJECT_num(ax->reject); i++) {
ASN1_OBJECT *obj = sk_ASN1_OBJECT_value(ax->reject, i);
int nid = OBJ_obj2nid(obj);
if (nid == id || (nid == NID_anyExtendedKeyUsage &&
(flags & X509_TRUST_OK_ANY_EKU)))
return X509_TRUST_REJECTED;
}
}
if (ax && ax->trust) {
for (i = 0; i < sk_ASN1_OBJECT_num(ax->trust); i++) {
ASN1_OBJECT *obj = sk_ASN1_OBJECT_value(ax->trust, i);
int nid = OBJ_obj2nid(obj);
if (nid == id || (nid == NID_anyExtendedKeyUsage &&
(flags & X509_TRUST_OK_ANY_EKU)))
return X509_TRUST_TRUSTED;
}
return X509_TRUST_REJECTED;
}
if ((flags & X509_TRUST_DO_SS_COMPAT) == 0)
return X509_TRUST_UNTRUSTED;
return trust_compat(NULL, x, flags);
}
