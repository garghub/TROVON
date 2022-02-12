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
struct key *x509_request_asymmetric_key(struct key *keyring,
const struct asymmetric_key_id *id,
const struct asymmetric_key_id *skid,
bool partial)
{
struct key *key;
key_ref_t ref;
const char *lookup;
char *req, *p;
int len;
if (id) {
lookup = id->data;
len = id->len;
} else {
lookup = skid->data;
len = skid->len;
}
p = req = kmalloc(2 + 1 + len * 2 + 1, GFP_KERNEL);
if (!req)
return ERR_PTR(-ENOMEM);
if (partial) {
*p++ = 'i';
*p++ = 'd';
} else {
*p++ = 'e';
*p++ = 'x';
}
*p++ = ':';
p = bin2hex(p, lookup, len);
*p = 0;
pr_debug("Look up: \"%s\"\n", req);
ref = keyring_search(make_key_ref(keyring, 1),
&key_type_asymmetric, req);
if (IS_ERR(ref))
pr_debug("Request for key '%s' err %ld\n", req, PTR_ERR(ref));
kfree(req);
if (IS_ERR(ref)) {
switch (PTR_ERR(ref)) {
case -EACCES:
case -ENOTDIR:
case -EAGAIN:
return ERR_PTR(-ENOKEY);
default:
return ERR_CAST(ref);
}
}
key = key_ref_to_ptr(ref);
if (id && skid) {
const struct asymmetric_key_ids *kids = asymmetric_key_ids(key);
if (!kids->id[1]) {
pr_debug("issuer+serial match, but expected SKID missing\n");
goto reject;
}
if (!asymmetric_key_id_same(skid, kids->id[1])) {
pr_debug("issuer+serial match, but SKID does not\n");
goto reject;
}
}
pr_devel("<==%s() = 0 [%x]\n", __func__, key_serial(key));
return key;
reject:
key_put(key);
return ERR_PTR(-EKEYREJECTED);
}
int x509_get_sig_params(struct x509_certificate *cert)
{
struct crypto_shash *tfm;
struct shash_desc *desc;
size_t digest_size, desc_size;
void *digest;
int ret;
pr_devel("==>%s()\n", __func__);
if (cert->unsupported_crypto)
return -ENOPKG;
if (cert->sig.s)
return 0;
cert->sig.s = kmemdup(cert->raw_sig, cert->raw_sig_size,
GFP_KERNEL);
if (!cert->sig.s)
return -ENOMEM;
cert->sig.s_size = cert->raw_sig_size;
tfm = crypto_alloc_shash(cert->sig.hash_algo, 0, 0);
if (IS_ERR(tfm)) {
if (PTR_ERR(tfm) == -ENOENT) {
cert->unsupported_crypto = true;
return -ENOPKG;
}
return PTR_ERR(tfm);
}
desc_size = crypto_shash_descsize(tfm) + sizeof(*desc);
digest_size = crypto_shash_digestsize(tfm);
ret = -ENOMEM;
digest = kzalloc(ALIGN(digest_size, __alignof__(*desc)) + desc_size,
GFP_KERNEL);
if (!digest)
goto error;
cert->sig.digest = digest;
cert->sig.digest_size = digest_size;
desc = PTR_ALIGN(digest + digest_size, __alignof__(*desc));
desc->tfm = tfm;
desc->flags = CRYPTO_TFM_REQ_MAY_SLEEP;
ret = crypto_shash_init(desc);
if (ret < 0)
goto error;
might_sleep();
ret = crypto_shash_finup(desc, cert->tbs, cert->tbs_size, digest);
error:
crypto_free_shash(tfm);
pr_devel("<==%s() = %d\n", __func__, ret);
return ret;
}
int x509_check_signature(const struct public_key *pub,
struct x509_certificate *cert)
{
int ret;
pr_devel("==>%s()\n", __func__);
ret = x509_get_sig_params(cert);
if (ret < 0)
return ret;
ret = public_key_verify_signature(pub, &cert->sig);
if (ret == -ENOPKG)
cert->unsupported_crypto = true;
pr_debug("Cert Verification: %d\n", ret);
return ret;
}
static int x509_validate_trust(struct x509_certificate *cert,
struct key *trust_keyring)
{
struct key *key;
int ret = 1;
if (!trust_keyring)
return -EOPNOTSUPP;
if (ca_keyid && !asymmetric_key_id_partial(cert->akid_skid, ca_keyid))
return -EPERM;
key = x509_request_asymmetric_key(trust_keyring,
cert->akid_id, cert->akid_skid,
false);
if (!IS_ERR(key)) {
if (!use_builtin_keys
|| test_bit(KEY_FLAG_BUILTIN, &key->flags))
ret = x509_check_signature(key->payload.data[asym_crypto],
cert);
key_put(key);
}
return ret;
}
static int x509_key_preparse(struct key_preparsed_payload *prep)
{
struct asymmetric_key_ids *kids;
struct x509_certificate *cert;
const char *q;
size_t srlen, sulen;
char *desc = NULL, *p;
int ret;
cert = x509_cert_parse(prep->data, prep->datalen);
if (IS_ERR(cert))
return PTR_ERR(cert);
pr_devel("Cert Issuer: %s\n", cert->issuer);
pr_devel("Cert Subject: %s\n", cert->subject);
if (!cert->pub->pkey_algo ||
!cert->sig.pkey_algo ||
!cert->sig.hash_algo) {
ret = -ENOPKG;
goto error_free_cert;
}
pr_devel("Cert Key Algo: %s\n", cert->pub->pkey_algo);
pr_devel("Cert Valid period: %lld-%lld\n", cert->valid_from, cert->valid_to);
pr_devel("Cert Signature: %s + %s\n",
cert->sig.pkey_algo,
cert->sig.hash_algo);
cert->pub->id_type = "X509";
if ((!cert->akid_skid && !cert->akid_id) ||
asymmetric_key_id_same(cert->skid, cert->akid_skid) ||
asymmetric_key_id_same(cert->id, cert->akid_id)) {
ret = x509_check_signature(cert->pub, cert);
if (ret < 0)
goto error_free_cert;
} else if (!prep->trusted) {
ret = x509_validate_trust(cert, get_system_trusted_keyring());
if (ret)
ret = x509_validate_trust(cert, get_ima_mok_keyring());
if (!ret)
prep->trusted = 1;
}
sulen = strlen(cert->subject);
if (cert->raw_skid) {
srlen = cert->raw_skid_size;
q = cert->raw_skid;
} else {
srlen = cert->raw_serial_size;
q = cert->raw_serial;
}
ret = -ENOMEM;
desc = kmalloc(sulen + 2 + srlen * 2 + 1, GFP_KERNEL);
if (!desc)
goto error_free_cert;
p = memcpy(desc, cert->subject, sulen);
p += sulen;
*p++ = ':';
*p++ = ' ';
p = bin2hex(p, q, srlen);
*p = 0;
kids = kmalloc(sizeof(struct asymmetric_key_ids), GFP_KERNEL);
if (!kids)
goto error_free_desc;
kids->id[0] = cert->id;
kids->id[1] = cert->skid;
__module_get(public_key_subtype.owner);
prep->payload.data[asym_subtype] = &public_key_subtype;
prep->payload.data[asym_key_ids] = kids;
prep->payload.data[asym_crypto] = cert->pub;
prep->description = desc;
prep->quotalen = 100;
cert->pub = NULL;
cert->id = NULL;
cert->skid = NULL;
desc = NULL;
ret = 0;
error_free_desc:
kfree(desc);
error_free_cert:
x509_free_certificate(cert);
return ret;
}
static int __init x509_key_init(void)
{
return register_asymmetric_key_parser(&x509_key_parser);
}
static void __exit x509_key_exit(void)
{
unregister_asymmetric_key_parser(&x509_key_parser);
}
