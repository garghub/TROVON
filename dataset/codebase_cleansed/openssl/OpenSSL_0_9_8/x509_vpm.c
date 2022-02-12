static void x509_verify_param_zero(X509_VERIFY_PARAM *param)
{
if (!param)
return;
param->name = NULL;
param->purpose = 0;
param->trust = 0;
param->inh_flags = X509_VP_FLAG_DEFAULT;
param->flags = 0;
param->depth = -1;
if (param->policies)
{
sk_ASN1_OBJECT_pop_free(param->policies, ASN1_OBJECT_free);
param->policies = NULL;
}
}
X509_VERIFY_PARAM *X509_VERIFY_PARAM_new(void)
{
X509_VERIFY_PARAM *param;
param = OPENSSL_malloc(sizeof(X509_VERIFY_PARAM));
memset(param, 0, sizeof(X509_VERIFY_PARAM));
x509_verify_param_zero(param);
return param;
}
void X509_VERIFY_PARAM_free(X509_VERIFY_PARAM *param)
{
x509_verify_param_zero(param);
OPENSSL_free(param);
}
int X509_VERIFY_PARAM_inherit(X509_VERIFY_PARAM *dest,
const X509_VERIFY_PARAM *src)
{
unsigned long inh_flags;
int to_default, to_overwrite;
if (!src)
return 1;
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
if (inh_flags & X509_VP_FLAG_RESET_FLAGS)
dest->flags = 0;
dest->flags |= src->flags;
if (test_x509_verify_param_copy(policies, NULL))
{
if (!X509_VERIFY_PARAM_set1_policies(dest, src->policies))
return 0;
}
return 1;
}
int X509_VERIFY_PARAM_set1(X509_VERIFY_PARAM *to,
const X509_VERIFY_PARAM *from)
{
to->inh_flags |= X509_VP_FLAG_DEFAULT;
return X509_VERIFY_PARAM_inherit(to, from);
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
int X509_VERIFY_PARAM_add0_policy(X509_VERIFY_PARAM *param, ASN1_OBJECT *policy)
{
if (!param->policies)
{
param->policies = sk_ASN1_OBJECT_new_null();
if (!param->policies)
return 0;
}
if (!sk_ASN1_OBJECT_push(param->policies, policy))
return 0;
return 1;
}
int X509_VERIFY_PARAM_get_depth(const X509_VERIFY_PARAM *param)
{
return param->depth;
}
static int table_cmp(const void *pa, const void *pb)
{
const X509_VERIFY_PARAM *a = pa, *b = pb;
return strcmp(a->name, b->name);
}
static int param_cmp(const X509_VERIFY_PARAM * const *a,
const X509_VERIFY_PARAM * const *b)
{
return strcmp((*a)->name, (*b)->name);
}
int X509_VERIFY_PARAM_add0_table(X509_VERIFY_PARAM *param)
{
int idx;
X509_VERIFY_PARAM *ptmp;
if (!param_table)
{
param_table = sk_X509_VERIFY_PARAM_new(param_cmp);
if (!param_table)
return 0;
}
else
{
idx = sk_X509_VERIFY_PARAM_find(param_table, param);
if (idx != -1)
{
ptmp = sk_X509_VERIFY_PARAM_value(param_table, idx);
X509_VERIFY_PARAM_free(ptmp);
sk_X509_VERIFY_PARAM_delete(param_table, idx);
}
}
if (!sk_X509_VERIFY_PARAM_push(param_table, param))
return 0;
return 1;
}
const X509_VERIFY_PARAM *X509_VERIFY_PARAM_lookup(const char *name)
{
int idx;
X509_VERIFY_PARAM pm;
pm.name = (char *)name;
if (param_table)
{
idx = sk_X509_VERIFY_PARAM_find(param_table, &pm);
if (idx != -1)
return sk_X509_VERIFY_PARAM_value(param_table, idx);
}
return (const X509_VERIFY_PARAM *) OBJ_bsearch((char *)&pm,
(char *)&default_table,
sizeof(default_table)/sizeof(X509_VERIFY_PARAM),
sizeof(X509_VERIFY_PARAM),
table_cmp);
}
void X509_VERIFY_PARAM_table_cleanup(void)
{
if (param_table)
sk_X509_VERIFY_PARAM_pop_free(param_table,
X509_VERIFY_PARAM_free);
param_table = NULL;
}
