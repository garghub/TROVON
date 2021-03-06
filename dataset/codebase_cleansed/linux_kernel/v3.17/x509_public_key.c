static int __init ca_keys_setup(char *str)
{
if (!str)
return 1;
if (strncmp(str, "id:", 3) == 0)
ca_keyid = str;
else if (strcmp(str, "builtin") == 0)
use_builtin_keys = true;
return 1;
}
struct key *x509_request_asymmetric_key(struct key *keyring,
const char *subject,
const char *key_id)
{
key_ref_t key;
size_t subject_len = strlen(subject), key_id_len = strlen(key_id);
char *id;
id = kmalloc(subject_len + 2 + key_id_len + 1, GFP_KERNEL);
if (!id)
return ERR_PTR(-ENOMEM);
memcpy(id, subject, subject_len);
id[subject_len + 0] = ':';
id[subject_len + 1] = ' ';
memcpy(id + subject_len + 2, key_id, key_id_len);
id[subject_len + 2 + key_id_len] = 0;
pr_debug("Look up: \"%s\"\n", id);
key = keyring_search(make_key_ref(keyring, 1),
&key_type_asymmetric, id);
if (IS_ERR(key))
pr_debug("Request for key '%s' err %ld\n", id, PTR_ERR(key));
kfree(id);
if (IS_ERR(key)) {
switch (PTR_ERR(key)) {
case -EACCES:
case -ENOTDIR:
case -EAGAIN:
return ERR_PTR(-ENOKEY);
default:
return ERR_CAST(key);
}
}
pr_devel("<==%s() = 0 [%x]\n", __func__,
key_serial(key_ref_to_ptr(key)));
return key_ref_to_ptr(key);
}
int x509_get_sig_params(struct x509_certificate *cert)
{
struct crypto_shash *tfm;
struct shash_desc *desc;
size_t digest_size, desc_size;
void *digest;
int ret;
pr_devel("==>%s()\n", __func__);
if (cert->sig.rsa.s)
return 0;
cert->sig.rsa.s = mpi_read_raw_data(cert->raw_sig, cert->raw_sig_size);
if (!cert->sig.rsa.s)
return -ENOMEM;
cert->sig.nr_mpi = 1;
tfm = crypto_alloc_shash(hash_algo_name[cert->sig.pkey_hash_algo], 0, 0);
if (IS_ERR(tfm))
return (PTR_ERR(tfm) == -ENOENT) ? -ENOPKG : PTR_ERR(tfm);
desc_size = crypto_shash_descsize(tfm) + sizeof(*desc);
digest_size = crypto_shash_digestsize(tfm);
ret = -ENOMEM;
digest = kzalloc(digest_size + desc_size, GFP_KERNEL);
if (!digest)
goto error;
cert->sig.digest = digest;
cert->sig.digest_size = digest_size;
desc = digest + digest_size;
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
if (ca_keyid && !asymmetric_keyid_match(cert->authority, ca_keyid))
return -EPERM;
key = x509_request_asymmetric_key(trust_keyring,
cert->issuer, cert->authority);
if (!IS_ERR(key)) {
if (!use_builtin_keys
|| test_bit(KEY_FLAG_BUILTIN, &key->flags))
ret = x509_check_signature(key->payload.data, cert);
key_put(key);
}
return ret;
}
static int x509_key_preparse(struct key_preparsed_payload *prep)
{
struct x509_certificate *cert;
size_t srlen, sulen;
char *desc = NULL;
int ret;
cert = x509_cert_parse(prep->data, prep->datalen);
if (IS_ERR(cert))
return PTR_ERR(cert);
pr_devel("Cert Issuer: %s\n", cert->issuer);
pr_devel("Cert Subject: %s\n", cert->subject);
if (cert->pub->pkey_algo >= PKEY_ALGO__LAST ||
cert->sig.pkey_algo >= PKEY_ALGO__LAST ||
cert->sig.pkey_hash_algo >= PKEY_HASH__LAST ||
!pkey_algo[cert->pub->pkey_algo] ||
!pkey_algo[cert->sig.pkey_algo] ||
!hash_algo_name[cert->sig.pkey_hash_algo]) {
ret = -ENOPKG;
goto error_free_cert;
}
pr_devel("Cert Key Algo: %s\n", pkey_algo_name[cert->pub->pkey_algo]);
pr_devel("Cert Valid From: %04ld-%02d-%02d %02d:%02d:%02d\n",
cert->valid_from.tm_year + 1900, cert->valid_from.tm_mon + 1,
cert->valid_from.tm_mday, cert->valid_from.tm_hour,
cert->valid_from.tm_min, cert->valid_from.tm_sec);
pr_devel("Cert Valid To: %04ld-%02d-%02d %02d:%02d:%02d\n",
cert->valid_to.tm_year + 1900, cert->valid_to.tm_mon + 1,
cert->valid_to.tm_mday, cert->valid_to.tm_hour,
cert->valid_to.tm_min, cert->valid_to.tm_sec);
pr_devel("Cert Signature: %s + %s\n",
pkey_algo_name[cert->sig.pkey_algo],
hash_algo_name[cert->sig.pkey_hash_algo]);
if (!cert->fingerprint) {
pr_warn("Cert for '%s' must have a SubjKeyId extension\n",
cert->subject);
ret = -EKEYREJECTED;
goto error_free_cert;
}
cert->pub->algo = pkey_algo[cert->pub->pkey_algo];
cert->pub->id_type = PKEY_ID_X509;
if (!cert->authority ||
strcmp(cert->fingerprint, cert->authority) == 0) {
ret = x509_check_signature(cert->pub, cert);
if (ret < 0)
goto error_free_cert;
} else if (!prep->trusted) {
ret = x509_validate_trust(cert, get_system_trusted_keyring());
if (!ret)
prep->trusted = 1;
}
sulen = strlen(cert->subject);
srlen = strlen(cert->fingerprint);
ret = -ENOMEM;
desc = kmalloc(sulen + 2 + srlen + 1, GFP_KERNEL);
if (!desc)
goto error_free_cert;
memcpy(desc, cert->subject, sulen);
desc[sulen] = ':';
desc[sulen + 1] = ' ';
memcpy(desc + sulen + 2, cert->fingerprint, srlen);
desc[sulen + 2 + srlen] = 0;
__module_get(public_key_subtype.owner);
prep->type_data[0] = &public_key_subtype;
prep->type_data[1] = cert->fingerprint;
prep->payload[0] = cert->pub;
prep->description = desc;
prep->quotalen = 100;
cert->pub = NULL;
cert->fingerprint = NULL;
desc = NULL;
ret = 0;
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
