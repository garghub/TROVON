static int ref_cmp(const X509_POLICY_REF * const *a,
const X509_POLICY_REF * const *b)
{
return OBJ_cmp((*a)->subjectDomainPolicy, (*b)->subjectDomainPolicy);
}
static void policy_map_free(X509_POLICY_REF *map)
{
if (map->subjectDomainPolicy)
ASN1_OBJECT_free(map->subjectDomainPolicy);
OPENSSL_free(map);
}
static X509_POLICY_REF *policy_map_find(X509_POLICY_CACHE *cache, ASN1_OBJECT *id)
{
X509_POLICY_REF tmp;
int idx;
tmp.subjectDomainPolicy = id;
idx = sk_X509_POLICY_REF_find(cache->maps, &tmp);
if (idx == -1)
return NULL;
return sk_X509_POLICY_REF_value(cache->maps, idx);
}
int policy_cache_set_mapping(X509 *x, POLICY_MAPPINGS *maps)
{
POLICY_MAPPING *map;
X509_POLICY_REF *ref = NULL;
X509_POLICY_DATA *data;
X509_POLICY_CACHE *cache = x->policy_cache;
int i;
int ret = 0;
if (sk_POLICY_MAPPING_num(maps) == 0)
{
ret = -1;
goto bad_mapping;
}
cache->maps = sk_X509_POLICY_REF_new(ref_cmp);
for (i = 0; i < sk_POLICY_MAPPING_num(maps); i++)
{
map = sk_POLICY_MAPPING_value(maps, i);
if ((OBJ_obj2nid(map->subjectDomainPolicy) == NID_any_policy)
|| (OBJ_obj2nid(map->issuerDomainPolicy) == NID_any_policy))
{
ret = -1;
goto bad_mapping;
}
if (policy_map_find(cache, map->subjectDomainPolicy) != NULL)
{
ret = -1;
goto bad_mapping;
}
data = policy_cache_find_data(cache, map->issuerDomainPolicy);
if (!data && !cache->anyPolicy)
continue;
if (!data)
{
data = policy_data_new(NULL, map->issuerDomainPolicy,
cache->anyPolicy->flags
& POLICY_DATA_FLAG_CRITICAL);
if (!data)
goto bad_mapping;
data->qualifier_set = cache->anyPolicy->qualifier_set;
map->issuerDomainPolicy = NULL;
data->flags |= POLICY_DATA_FLAG_MAPPED_ANY;
data->flags |= POLICY_DATA_FLAG_SHARED_QUALIFIERS;
if (!sk_X509_POLICY_DATA_push(cache->data, data))
{
policy_data_free(data);
goto bad_mapping;
}
}
else
data->flags |= POLICY_DATA_FLAG_MAPPED;
if (!sk_ASN1_OBJECT_push(data->expected_policy_set,
map->subjectDomainPolicy))
goto bad_mapping;
ref = OPENSSL_malloc(sizeof(X509_POLICY_REF));
if (!ref)
goto bad_mapping;
ref->subjectDomainPolicy = map->subjectDomainPolicy;
map->subjectDomainPolicy = NULL;
ref->data = data;
if (!sk_X509_POLICY_REF_push(cache->maps, ref))
goto bad_mapping;
ref = NULL;
}
ret = 1;
bad_mapping:
if (ret == -1)
x->ex_flags |= EXFLAG_INVALID_POLICY;
if (ref)
policy_map_free(ref);
if (ret <= 0)
{
sk_X509_POLICY_REF_pop_free(cache->maps, policy_map_free);
cache->maps = NULL;
}
sk_POLICY_MAPPING_pop_free(maps, POLICY_MAPPING_free);
return ret;
}
