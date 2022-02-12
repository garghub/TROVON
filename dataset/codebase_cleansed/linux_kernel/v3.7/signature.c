int verify_signature(const struct key *key,
const struct public_key_signature *sig)
{
const struct asymmetric_key_subtype *subtype;
int ret;
pr_devel("==>%s()\n", __func__);
if (key->type != &key_type_asymmetric)
return -EINVAL;
subtype = asymmetric_key_subtype(key);
if (!subtype ||
!key->payload.data)
return -EINVAL;
if (!subtype->verify_signature)
return -ENOTSUPP;
ret = subtype->verify_signature(key, sig);
pr_devel("<==%s() = %d\n", __func__, ret);
return ret;
}
