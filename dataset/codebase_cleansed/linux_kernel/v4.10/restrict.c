static int __init ca_keys_setup(char *str)
{
if (!str)
return 1;
if (strncmp(str, "id:", 3) == 0) {
struct asymmetric_key_id *p = &cakey.id;
size_t hexlen = (strlen(str) - 3) / 2;
int ret;
if (hexlen == 0 || hexlen > sizeof(cakey.data)) {
pr_err("Missing or invalid ca_keys id\n");
return 1;
}
ret = __asymmetric_key_hex_to_key_id(str + 3, p, hexlen);
if (ret < 0)
pr_err("Unparsable ca_keys id hex string\n");
else
ca_keyid = p;
} else if (strcmp(str, "builtin") == 0) {
use_builtin_keys = true;
}
return 1;
}
int restrict_link_by_signature(struct key *trust_keyring,
const struct key_type *type,
const union key_payload *payload)
{
const struct public_key_signature *sig;
struct key *key;
int ret;
pr_devel("==>%s()\n", __func__);
if (!trust_keyring)
return -ENOKEY;
if (type != &key_type_asymmetric)
return -EOPNOTSUPP;
sig = payload->data[asym_auth];
if (!sig->auth_ids[0] && !sig->auth_ids[1])
return -ENOKEY;
if (ca_keyid && !asymmetric_key_id_partial(sig->auth_ids[1], ca_keyid))
return -EPERM;
key = find_asymmetric_key(trust_keyring,
sig->auth_ids[0], sig->auth_ids[1],
false);
if (IS_ERR(key))
return -ENOKEY;
if (use_builtin_keys && !test_bit(KEY_FLAG_BUILTIN, &key->flags))
ret = -ENOKEY;
else
ret = verify_signature(key, sig);
key_put(key);
return ret;
}
