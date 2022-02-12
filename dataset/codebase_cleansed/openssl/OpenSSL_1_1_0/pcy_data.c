void policy_data_free(X509_POLICY_DATA *data)
{
if (!data)
return;
ASN1_OBJECT_free(data->valid_policy);
if (!(data->flags & POLICY_DATA_FLAG_SHARED_QUALIFIERS))
sk_POLICYQUALINFO_pop_free(data->qualifier_set, POLICYQUALINFO_free);
sk_ASN1_OBJECT_pop_free(data->expected_policy_set, ASN1_OBJECT_free);
OPENSSL_free(data);
}
X509_POLICY_DATA *policy_data_new(POLICYINFO *policy,
const ASN1_OBJECT *cid, int crit)
{
X509_POLICY_DATA *ret;
ASN1_OBJECT *id;
if (!policy && !cid)
return NULL;
if (cid) {
id = OBJ_dup(cid);
if (!id)
return NULL;
} else
id = NULL;
ret = OPENSSL_zalloc(sizeof(*ret));
if (ret == NULL)
return NULL;
ret->expected_policy_set = sk_ASN1_OBJECT_new_null();
if (ret->expected_policy_set == NULL) {
OPENSSL_free(ret);
ASN1_OBJECT_free(id);
return NULL;
}
if (crit)
ret->flags = POLICY_DATA_FLAG_CRITICAL;
if (id)
ret->valid_policy = id;
else {
ret->valid_policy = policy->policyid;
policy->policyid = NULL;
}
if (policy) {
ret->qualifier_set = policy->qualifiers;
policy->qualifiers = NULL;
}
return ret;
}
