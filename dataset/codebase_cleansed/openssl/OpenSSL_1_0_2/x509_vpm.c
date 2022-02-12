static char *str_copy(const char *s)
{
return OPENSSL_strdup(s);
}
static void str_free(char *s)
{
OPENSSL_free(s);
}
static int int_x509_param_set_hosts(X509_VERIFY_PARAM_ID *id, int mode,
const char *name, size_t namelen)
{
char *copy;
if (namelen == 0)
namelen = name ? strlen(name) : 0;
else if (name && memchr(name, '\0', namelen > 1 ? namelen - 1 : namelen))
return 0;
if (name && name[namelen - 1] == '\0')
--namelen;
if (mode == SET_HOST && id->hosts) {
string_stack_free(id->hosts);
id->hosts = NULL;
}
if (name == NULL || namelen == 0)
return 1;
copy = BUF_strndup(name, namelen);
if (copy == NULL)
return 0;
if (id->hosts == NULL &&
(id->hosts = sk_OPENSSL_STRING_new_null()) == NULL) {
OPENSSL_free(copy);
return 0;
}
if (!sk_OPENSSL_STRING_push(id->hosts, copy)) {
OPENSSL_free(copy);
if (sk_OPENSSL_STRING_num(id->hosts) == 0) {
sk_OPENSSL_STRING_free(id->hosts);
id->hosts = NULL;
}
return 0;
}
return 1;
}
static void x509_verify_param_zero(X509_VERIFY_PARAM *param)
{
X509_VERIFY_PARAM_ID *paramid;
if (!param)
return;
param->name = NULL;
param->purpose = 0;
param->trust = 0;
param->inh_flags = 0;
param->flags = 0;
param->depth = -1;
if (param->policies) {
sk_ASN1_OBJECT_pop_free(param->policies, ASN1_OBJECT_free);
param->policies = NULL;
}
paramid = param->id;
if (paramid->hosts) {
string_stack_free(paramid->hosts);
paramid->hosts = NULL;
}
if (paramid->peername)
OPENSSL_free(paramid->peername);
if (paramid->email) {
OPENSSL_free(paramid->email);
paramid->email = NULL;
paramid->emaillen = 0;
}
if (paramid->ip) {
OPENSSL_free(paramid->ip);
paramid->ip = NULL;
paramid->iplen = 0;
}
}
X509_VERIFY_PARAM *X509_VERIFY_PARAM_new(void)
{
X509_VERIFY_PARAM *param;
X509_VERIFY_PARAM_ID *paramid;
param = OPENSSL_malloc(sizeof(X509_VERIFY_PARAM));
if (!param)
return NULL;
paramid = OPENSSL_malloc(sizeof(X509_VERIFY_PARAM));
if (!paramid) {
OPENSSL_free(param);
return NULL;
}
memset(param, 0, sizeof(X509_VERIFY_PARAM));
memset(paramid, 0, sizeof(X509_VERIFY_PARAM_ID));
param->id = paramid;
x509_verify_param_zero(param);
return param;
}
void X509_VERIFY_PARAM_free(X509_VERIFY_PARAM *param)
{
x509_verify_param_zero(param);
OPENSSL_free(param->id);
OPENSSL_free(param);
}
int X509_VERIFY_PARAM_inherit(X509_VERIFY_PARAM *dest,
const X509_VERIFY_PARAM *src)
{
unsigned long inh_flags;
int to_default, to_overwrite;
X509_VERIFY_PARAM_ID *id;
if (!src)
return 1;
id = src->id;
inh_flags = dest->inh_flags | src->inh_flags;
if (inh_flags & X509_VP_FLAG_ONCE)
dest->inh_flags = 0;
if (inh_flags & X509_VP_FLAG_LOCKED)
return 1;
if (inh_flags & X509_VP_FLAG_DEFAULT)
to_default = 1;
else
to_default = 0;
if (inh_flags & X509_VP_FLAG_OVERWRITE)
to_overwrite = 1;
else
to_overwrite = 0;
x509_verify_param_copy(purpose, 0);
x509_verify_param_copy(trust, 0);
x509_verify_param_copy(depth, -1);
if (to_overwrite || !(dest->flags & X509_V_FLAG_USE_CHECK_TIME)) {
dest->check_time = src->check_time;
dest->flags &= ~X509_V_FLAG_USE_CHECK_TIME;
}
if (inh_flags & X509_VP_FLAG_RESET_FLAGS)
dest->flags = 0;
dest->flags |= src->flags;
if (test_x509_verify_param_copy(policies, NULL)) {
if (!X509_VERIFY_PARAM_set1_policies(dest, src->policies))
return 0;
}
if (test_x509_verify_param_copy_id(hosts, NULL)) {
if (dest->id->hosts) {
string_stack_free(dest->id->hosts);
dest->id->hosts = NULL;
}
if (id->hosts) {
dest->id->hosts =
sk_OPENSSL_STRING_deep_copy(id->hosts, str_copy, str_free);
if (dest->id->hosts == NULL)
return 0;
dest->id->hostflags = id->hostflags;
}
}
if (test_x509_verify_param_copy_id(email, NULL)) {
if (!X509_VERIFY_PARAM_set1_email(dest, id->email, id->emaillen))
return 0;
}
if (test_x509_verify_param_copy_id(ip, NULL)) {
if (!X509_VERIFY_PARAM_set1_ip(dest, id->ip, id->iplen))
return 0;
}
return 1;
}
int X509_VERIFY_PARAM_set1(X509_VERIFY_PARAM *to,
const X509_VERIFY_PARAM *from)
{
unsigned long save_flags = to->inh_flags;
int ret;
to->inh_flags |= X509_VP_FLAG_DEFAULT;
ret = X509_VERIFY_PARAM_inherit(to, from);
to->inh_flags = save_flags;
return ret;
}
static int int_x509_param_set1(char **pdest, size_t *pdestlen,
const char *src, size_t srclen)
{
void *tmp;
if (src) {
if (srclen == 0) {
tmp = BUF_strdup(src);
srclen = strlen(src);
} else
tmp = BUF_memdup(src, srclen);
if (!tmp)
return 0;
} else {
tmp = NULL;
srclen = 0;
}
if (*pdest)
OPENSSL_free(*pdest);
*pdest = tmp;
if (pdestlen)
*pdestlen = srclen;
return 1;
}
int X509_VERIFY_PARAM_set1_name(X509_VERIFY_PARAM *param, const char *name)
{
if (param->name)
OPENSSL_free(param->name);
param->name = BUF_strdup(name);
if (param->name)
return 1;
return 0;
}
int X509_VERIFY_PARAM_set_flags(X509_VERIFY_PARAM *param, unsigned long flags)
{
param->flags |= flags;
if (flags & X509_V_FLAG_POLICY_MASK)
param->flags |= X509_V_FLAG_POLICY_CHECK;
return 1;
}
int X509_VERIFY_PARAM_clear_flags(X509_VERIFY_PARAM *param,
unsigned long flags)
{
param->flags &= ~flags;
return 1;
}
unsigned long X509_VERIFY_PARAM_get_flags(X509_VERIFY_PARAM *param)
{
return param->flags;
}
int X509_VERIFY_PARAM_set_purpose(X509_VERIFY_PARAM *param, int purpose)
{
return X509_PURPOSE_set(&param->purpose, purpose);
}
int X509_VERIFY_PARAM_set_trust(X509_VERIFY_PARAM *param, int trust)
{
return X509_TRUST_set(&param->trust, trust);
}
void X509_VERIFY_PARAM_set_depth(X509_VERIFY_PARAM *param, int depth)
{
param->depth = depth;
}
void X509_VERIFY_PARAM_set_time(X509_VERIFY_PARAM *param, time_t t)
{
param->check_time = t;
param->flags |= X509_V_FLAG_USE_CHECK_TIME;
}
int X509_VERIFY_PARAM_add0_policy(X509_VERIFY_PARAM *param,
ASN1_OBJECT *policy)
{
if (!param->policies) {
param->policies = sk_ASN1_OBJECT_new_null();
if (!param->policies)
return 0;
}
if (!sk_ASN1_OBJECT_push(param->policies, policy))
return 0;
return 1;
}
int X509_VERIFY_PARAM_set1_host(X509_VERIFY_PARAM *param,
const char *name, size_t namelen)
{
return int_x509_param_set_hosts(param->id, SET_HOST, name, namelen);
}
int X509_VERIFY_PARAM_add1_host(X509_VERIFY_PARAM *param,
const char *name, size_t namelen)
{
return int_x509_param_set_hosts(param->id, ADD_HOST, name, namelen);
}
void X509_VERIFY_PARAM_set_hostflags(X509_VERIFY_PARAM *param,
unsigned int flags)
{
param->id->hostflags = flags;
}
char *X509_VERIFY_PARAM_get0_peername(X509_VERIFY_PARAM *param)
{
return param->id->peername;
}
int X509_VERIFY_PARAM_set1_email(X509_VERIFY_PARAM *param,
const char *email, size_t emaillen)
{
return int_x509_param_set1(&param->id->email, &param->id->emaillen,
email, emaillen);
}
int X509_VERIFY_PARAM_set1_ip(X509_VERIFY_PARAM *param,
const unsigned char *ip, size_t iplen)
{
if (iplen != 0 && iplen != 4 && iplen != 16)
return 0;
return int_x509_param_set1((char **)&param->id->ip, &param->id->iplen,
(char *)ip, iplen);
}
int X509_VERIFY_PARAM_set1_ip_asc(X509_VERIFY_PARAM *param, const char *ipasc)
{
unsigned char ipout[16];
size_t iplen;
iplen = (size_t)a2i_ipadd(ipout, ipasc);
if (iplen == 0)
return 0;
return X509_VERIFY_PARAM_set1_ip(param, ipout, iplen);
}
int X509_VERIFY_PARAM_get_depth(const X509_VERIFY_PARAM *param)
{
return param->depth;
}
const char *X509_VERIFY_PARAM_get0_name(const X509_VERIFY_PARAM *param)
{
return param->name;
}
static int table_cmp(const X509_VERIFY_PARAM *a, const X509_VERIFY_PARAM *b)
{
return strcmp(a->name, b->name);
}
static int param_cmp(const X509_VERIFY_PARAM *const *a,
const X509_VERIFY_PARAM *const *b)
{
return strcmp((*a)->name, (*b)->name);
}
int X509_VERIFY_PARAM_add0_table(X509_VERIFY_PARAM *param)
{
int idx;
X509_VERIFY_PARAM *ptmp;
if (!param_table) {
param_table = sk_X509_VERIFY_PARAM_new(param_cmp);
if (!param_table)
return 0;
} else {
idx = sk_X509_VERIFY_PARAM_find(param_table, param);
if (idx != -1) {
ptmp = sk_X509_VERIFY_PARAM_value(param_table, idx);
X509_VERIFY_PARAM_free(ptmp);
(void)sk_X509_VERIFY_PARAM_delete(param_table, idx);
}
}
if (!sk_X509_VERIFY_PARAM_push(param_table, param))
return 0;
return 1;
}
int X509_VERIFY_PARAM_get_count(void)
{
int num = sizeof(default_table) / sizeof(X509_VERIFY_PARAM);
if (param_table)
num += sk_X509_VERIFY_PARAM_num(param_table);
return num;
}
const X509_VERIFY_PARAM *X509_VERIFY_PARAM_get0(int id)
{
int num = sizeof(default_table) / sizeof(X509_VERIFY_PARAM);
if (id < num)
return default_table + id;
return sk_X509_VERIFY_PARAM_value(param_table, id - num);
}
const X509_VERIFY_PARAM *X509_VERIFY_PARAM_lookup(const char *name)
{
int idx;
X509_VERIFY_PARAM pm;
pm.name = (char *)name;
if (param_table) {
idx = sk_X509_VERIFY_PARAM_find(param_table, &pm);
if (idx != -1)
return sk_X509_VERIFY_PARAM_value(param_table, idx);
}
return OBJ_bsearch_table(&pm, default_table,
sizeof(default_table) /
sizeof(X509_VERIFY_PARAM));
}
void X509_VERIFY_PARAM_table_cleanup(void)
{
if (param_table)
sk_X509_VERIFY_PARAM_pop_free(param_table, X509_VERIFY_PARAM_free);
param_table = NULL;
}
