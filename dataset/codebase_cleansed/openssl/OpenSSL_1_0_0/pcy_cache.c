static int policy_cache_create(X509 *x,
CERTIFICATEPOLICIES *policies, int crit)
{
int i;
int ret = 0;
X509_POLICY_CACHE *cache = x->policy_cache;
X509_POLICY_DATA *data = NULL;
POLICYINFO *policy;
if (sk_POLICYINFO_num(policies) == 0)
goto bad_policy;
cache->data = sk_X509_POLICY_DATA_new(policy_data_cmp);
if (!cache->data)
goto bad_policy;
for (i = 0; i < sk_POLICYINFO_num(policies); i++)
{
policy = sk_POLICYINFO_value(policies, i);
data = policy_data_new(policy, NULL, crit);
if (!data)
goto bad_policy;
if (OBJ_obj2nid(data->valid_policy) == NID_any_policy)
{
if (cache->anyPolicy)
{
ret = -1;
goto bad_policy;
}
cache->anyPolicy = data;
}
else if (sk_X509_POLICY_DATA_find(cache->data, data) != -1)
{
ret = -1;
goto bad_policy;
}
else if (!sk_X509_POLICY_DATA_push(cache->data, data))
goto bad_policy;
data = NULL;
}
ret = 1;
bad_policy:
if (ret == -1)
x->ex_flags |= EXFLAG_INVALID_POLICY;
if (data)
policy_data_free(data);
sk_POLICYINFO_pop_free(policies, POLICYINFO_free);
if (ret <= 0)
{
sk_X509_POLICY_DATA_pop_free(cache->data, policy_data_free);
cache->data = NULL;
}
return ret;
}
static int policy_cache_new(X509 *x)
{
X509_POLICY_CACHE *cache;
ASN1_INTEGER *ext_any = NULL;
POLICY_CONSTRAINTS *ext_pcons = NULL;
CERTIFICATEPOLICIES *ext_cpols = NULL;
POLICY_MAPPINGS *ext_pmaps = NULL;
int i;
cache = OPENSSL_malloc(sizeof(X509_POLICY_CACHE));
if (!cache)
return 0;
cache->anyPolicy = NULL;
cache->data = NULL;
cache->any_skip = -1;
cache->explicit_skip = -1;
cache->map_skip = -1;
x->policy_cache = cache;
ext_pcons = X509_get_ext_d2i(x, NID_policy_constraints, &i, NULL);
if (!ext_pcons)
{
if (i != -1)
goto bad_cache;
}
else
{
if (!ext_pcons->requireExplicitPolicy
&& !ext_pcons->inhibitPolicyMapping)
goto bad_cache;
if (!policy_cache_set_int(&cache->explicit_skip,
ext_pcons->requireExplicitPolicy))
goto bad_cache;
if (!policy_cache_set_int(&cache->map_skip,
ext_pcons->inhibitPolicyMapping))
goto bad_cache;
}
ext_cpols = X509_get_ext_d2i(x, NID_certificate_policies, &i, NULL);
if (!ext_cpols)
{
if (i != -1)
goto bad_cache;
return 1;
}
i = policy_cache_create(x, ext_cpols, i);
if (i <= 0)
return i;
ext_pmaps = X509_get_ext_d2i(x, NID_policy_mappings, &i, NULL);
if (!ext_pmaps)
{
if (i != -1)
goto bad_cache;
}
else
{
i = policy_cache_set_mapping(x, ext_pmaps);
if (i <= 0)
goto bad_cache;
}
ext_any = X509_get_ext_d2i(x, NID_inhibit_any_policy, &i, NULL);
if (!ext_any)
{
if (i != -1)
goto bad_cache;
}
else if (!policy_cache_set_int(&cache->any_skip, ext_any))
goto bad_cache;
if (0)
{
bad_cache:
x->ex_flags |= EXFLAG_INVALID_POLICY;
}
if(ext_pcons)
POLICY_CONSTRAINTS_free(ext_pcons);
if (ext_any)
ASN1_INTEGER_free(ext_any);
return 1;
}
void policy_cache_free(X509_POLICY_CACHE *cache)
{
if (!cache)
return;
if (cache->anyPolicy)
policy_data_free(cache->anyPolicy);
if (cache->data)
sk_X509_POLICY_DATA_pop_free(cache->data, policy_data_free);
OPENSSL_free(cache);
}
const X509_POLICY_CACHE *policy_cache_set(X509 *x)
{
if (x->policy_cache == NULL)
{
CRYPTO_w_lock(CRYPTO_LOCK_X509);
policy_cache_new(x);
CRYPTO_w_unlock(CRYPTO_LOCK_X509);
}
return x->policy_cache;
}
X509_POLICY_DATA *policy_cache_find_data(const X509_POLICY_CACHE *cache,
const ASN1_OBJECT *id)
{
int idx;
X509_POLICY_DATA tmp;
tmp.valid_policy = (ASN1_OBJECT *)id;
idx = sk_X509_POLICY_DATA_find(cache->data, &tmp);
if (idx == -1)
return NULL;
return sk_X509_POLICY_DATA_value(cache->data, idx);
}
static int policy_data_cmp(const X509_POLICY_DATA * const *a,
const X509_POLICY_DATA * const *b)
{
return OBJ_cmp((*a)->valid_policy, (*b)->valid_policy);
}
static int policy_cache_set_int(long *out, ASN1_INTEGER *value)
{
if (value == NULL)
return 1;
if (value->type == V_ASN1_NEG_INTEGER)
return 0;
*out = ASN1_INTEGER_get(value);
return 1;
}
