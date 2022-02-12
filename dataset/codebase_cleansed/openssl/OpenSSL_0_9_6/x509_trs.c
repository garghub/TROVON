static int tr_cmp(const X509_TRUST * const *a,
const X509_TRUST * const *b)
{
return (*a)->trust - (*b)->trust;
}
int X509_check_trust(X509 *x, int id, int flags)
{
X509_TRUST *pt;
int idx;
if(id == -1) return 1;
idx = X509_TRUST_get_by_id(id);
if(idx == -1) return default_trust(id, x, flags);
pt = X509_TRUST_get0(idx);
return pt->check_trust(pt, x, flags);
}
int X509_TRUST_get_count(void)
{
if(!trtable) return X509_TRUST_COUNT;
return sk_X509_TRUST_num(trtable) + X509_TRUST_COUNT;
}
X509_TRUST * X509_TRUST_get0(int idx)
{
if(idx < 0) return NULL;
if(idx < X509_TRUST_COUNT) return trstandard + idx;
return sk_X509_TRUST_value(trtable, idx - X509_TRUST_COUNT);
}
int X509_TRUST_get_by_id(int id)
{
X509_TRUST tmp;
int idx;
if((id >= X509_TRUST_MIN) && (id <= X509_TRUST_MAX))
return id - X509_TRUST_MIN;
tmp.trust = id;
if(!trtable) return -1;
idx = sk_X509_TRUST_find(trtable, &tmp);
if(idx == -1) return -1;
return idx + X509_TRUST_COUNT;
}
int X509_TRUST_add(int id, int flags, int (*ck)(X509_TRUST *, X509 *, int),
char *name, int arg1, void *arg2)
{
int idx;
X509_TRUST *trtmp;
flags &= ~X509_TRUST_DYNAMIC;
flags |= X509_TRUST_DYNAMIC_NAME;
idx = X509_TRUST_get_by_id(id);
if(idx == -1) {
if(!(trtmp = OPENSSL_malloc(sizeof(X509_TRUST)))) {
X509err(X509_F_X509_TRUST_ADD,ERR_R_MALLOC_FAILURE);
return 0;
}
trtmp->flags = X509_TRUST_DYNAMIC;
} else trtmp = X509_TRUST_get0(idx);
if(trtmp->flags & X509_TRUST_DYNAMIC_NAME) OPENSSL_free(trtmp->name);
if(!(trtmp->name = BUF_strdup(name))) {
X509err(X509_F_X509_TRUST_ADD,ERR_R_MALLOC_FAILURE);
return 0;
}
trtmp->flags &= X509_TRUST_DYNAMIC;
trtmp->flags |= flags;
trtmp->trust = id;
trtmp->check_trust = ck;
trtmp->arg1 = arg1;
trtmp->arg2 = arg2;
if(idx == -1) {
if(!trtable && !(trtable = sk_X509_TRUST_new(tr_cmp))) {
X509err(X509_F_X509_TRUST_ADD,ERR_R_MALLOC_FAILURE);
return 0;
}
if (!sk_X509_TRUST_push(trtable, trtmp)) {
X509err(X509_F_X509_TRUST_ADD,ERR_R_MALLOC_FAILURE);
return 0;
}
}
return 1;
}
static void trtable_free(X509_TRUST *p)
{
if(!p) return;
if (p->flags & X509_TRUST_DYNAMIC)
{
if (p->flags & X509_TRUST_DYNAMIC_NAME)
OPENSSL_free(p->name);
OPENSSL_free(p);
}
}
void X509_TRUST_cleanup(void)
{
int i;
for(i = 0; i < X509_TRUST_COUNT; i++) trtable_free(trstandard + i);
sk_X509_TRUST_pop_free(trtable, trtable_free);
trtable = NULL;
}
int X509_TRUST_get_flags(X509_TRUST *xp)
{
return xp->flags;
}
char *X509_TRUST_get0_name(X509_TRUST *xp)
{
return xp->name;
}
int X509_TRUST_get_trust(X509_TRUST *xp)
{
return xp->trust;
}
static int trust_1oidany(X509_TRUST *trust, X509 *x, int flags)
{
if(x->aux) return obj_trust(trust->arg1, x, flags);
return trust_compat(trust, x, flags);
}
static int trust_compat(X509_TRUST *trust, X509 *x, int flags)
{
X509_check_purpose(x, -1, 0);
if(x->ex_flags & EXFLAG_SS) return X509_TRUST_TRUSTED;
else return X509_TRUST_UNTRUSTED;
}
static int obj_trust(int id, X509 *x, int flags)
{
ASN1_OBJECT *obj;
int i;
X509_CERT_AUX *ax;
ax = x->aux;
if(!ax) return X509_TRUST_UNTRUSTED;
if(ax->reject) {
for(i = 0; i < sk_ASN1_OBJECT_num(ax->reject); i++) {
obj = sk_ASN1_OBJECT_value(ax->reject, i);
if(OBJ_obj2nid(obj) == id) return X509_TRUST_REJECTED;
}
}
if(ax->trust) {
for(i = 0; i < sk_ASN1_OBJECT_num(ax->trust); i++) {
obj = sk_ASN1_OBJECT_value(ax->trust, i);
if(OBJ_obj2nid(obj) == id) return X509_TRUST_TRUSTED;
}
}
return X509_TRUST_UNTRUSTED;
}
