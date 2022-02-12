static int pkcs7_digest(struct pkcs7_message *pkcs7,
struct pkcs7_signed_info *sinfo)
{
struct public_key_signature *sig = sinfo->sig;
struct crypto_shash *tfm;
struct shash_desc *desc;
size_t desc_size;
int ret;
kenter(",%u,%s", sinfo->index, sinfo->sig->hash_algo);
if (!sinfo->sig->hash_algo)
return -ENOPKG;
tfm = crypto_alloc_shash(sinfo->sig->hash_algo, 0, 0);
if (IS_ERR(tfm))
return (PTR_ERR(tfm) == -ENOENT) ? -ENOPKG : PTR_ERR(tfm);
desc_size = crypto_shash_descsize(tfm) + sizeof(*desc);
sig->digest_size = crypto_shash_digestsize(tfm);
ret = -ENOMEM;
sig->digest = kmalloc(sig->digest_size, GFP_KERNEL);
if (!sig->digest)
goto error_no_desc;
desc = kzalloc(desc_size, GFP_KERNEL);
if (!desc)
goto error_no_desc;
desc->tfm = tfm;
desc->flags = CRYPTO_TFM_REQ_MAY_SLEEP;
ret = crypto_shash_init(desc);
if (ret < 0)
goto error;
ret = crypto_shash_finup(desc, pkcs7->data, pkcs7->data_len,
sig->digest);
if (ret < 0)
goto error;
pr_devel("MsgDigest = [%*ph]\n", 8, sig->digest);
if (sinfo->authattrs) {
u8 tag;
if (!sinfo->msgdigest) {
pr_warn("Sig %u: No messageDigest\n", sinfo->index);
ret = -EKEYREJECTED;
goto error;
}
if (sinfo->msgdigest_len != sig->digest_size) {
pr_debug("Sig %u: Invalid digest size (%u)\n",
sinfo->index, sinfo->msgdigest_len);
ret = -EBADMSG;
goto error;
}
if (memcmp(sig->digest, sinfo->msgdigest,
sinfo->msgdigest_len) != 0) {
pr_debug("Sig %u: Message digest doesn't match\n",
sinfo->index);
ret = -EKEYREJECTED;
goto error;
}
memset(sig->digest, 0, sig->digest_size);
ret = crypto_shash_init(desc);
if (ret < 0)
goto error;
tag = ASN1_CONS_BIT | ASN1_SET;
ret = crypto_shash_update(desc, &tag, 1);
if (ret < 0)
goto error;
ret = crypto_shash_finup(desc, sinfo->authattrs,
sinfo->authattrs_len, sig->digest);
if (ret < 0)
goto error;
pr_devel("AADigest = [%*ph]\n", 8, sig->digest);
}
error:
kfree(desc);
error_no_desc:
crypto_free_shash(tfm);
kleave(" = %d", ret);
return ret;
}
static int pkcs7_find_key(struct pkcs7_message *pkcs7,
struct pkcs7_signed_info *sinfo)
{
struct x509_certificate *x509;
unsigned certix = 1;
kenter("%u", sinfo->index);
for (x509 = pkcs7->certs; x509; x509 = x509->next, certix++) {
if (!asymmetric_key_id_same(x509->id, sinfo->sig->auth_ids[0]))
continue;
pr_devel("Sig %u: Found cert serial match X.509[%u]\n",
sinfo->index, certix);
if (x509->pub->pkey_algo != sinfo->sig->pkey_algo) {
pr_warn("Sig %u: X.509 algo and PKCS#7 sig algo don't match\n",
sinfo->index);
continue;
}
sinfo->signer = x509;
return 0;
}
pr_debug("Sig %u: Issuing X.509 cert not found (#%*phN)\n",
sinfo->index,
sinfo->sig->auth_ids[0]->len, sinfo->sig->auth_ids[0]->data);
return 0;
}
static int pkcs7_verify_sig_chain(struct pkcs7_message *pkcs7,
struct pkcs7_signed_info *sinfo)
{
struct public_key_signature *sig;
struct x509_certificate *x509 = sinfo->signer, *p;
struct asymmetric_key_id *auth;
int ret;
kenter("");
for (p = pkcs7->certs; p; p = p->next)
p->seen = false;
for (;;) {
pr_debug("verify %s: %*phN\n",
x509->subject,
x509->raw_serial_size, x509->raw_serial);
x509->seen = true;
if (x509->blacklisted) {
sinfo->blacklisted = true;
for (p = sinfo->signer; p != x509; p = p->signer)
p->blacklisted = true;
pr_debug("- blacklisted\n");
return 0;
}
if (x509->unsupported_key)
goto unsupported_crypto_in_x509;
pr_debug("- issuer %s\n", x509->issuer);
sig = x509->sig;
if (sig->auth_ids[0])
pr_debug("- authkeyid.id %*phN\n",
sig->auth_ids[0]->len, sig->auth_ids[0]->data);
if (sig->auth_ids[1])
pr_debug("- authkeyid.skid %*phN\n",
sig->auth_ids[1]->len, sig->auth_ids[1]->data);
if (x509->self_signed) {
if (x509->unsupported_sig)
goto unsupported_crypto_in_x509;
x509->signer = x509;
pr_debug("- self-signed\n");
return 0;
}
auth = sig->auth_ids[0];
if (auth) {
pr_debug("- want %*phN\n", auth->len, auth->data);
for (p = pkcs7->certs; p; p = p->next) {
pr_debug("- cmp [%u] %*phN\n",
p->index, p->id->len, p->id->data);
if (asymmetric_key_id_same(p->id, auth))
goto found_issuer_check_skid;
}
} else if (sig->auth_ids[1]) {
auth = sig->auth_ids[1];
pr_debug("- want %*phN\n", auth->len, auth->data);
for (p = pkcs7->certs; p; p = p->next) {
if (!p->skid)
continue;
pr_debug("- cmp [%u] %*phN\n",
p->index, p->skid->len, p->skid->data);
if (asymmetric_key_id_same(p->skid, auth))
goto found_issuer;
}
}
pr_debug("- top\n");
return 0;
found_issuer_check_skid:
if (sig->auth_ids[1] &&
!asymmetric_key_id_same(p->skid, sig->auth_ids[1])) {
pr_warn("Sig %u: X.509 chain contains auth-skid nonmatch (%u->%u)\n",
sinfo->index, x509->index, p->index);
return -EKEYREJECTED;
}
found_issuer:
pr_debug("- subject %s\n", p->subject);
if (p->seen) {
pr_warn("Sig %u: X.509 chain contains loop\n",
sinfo->index);
return 0;
}
ret = public_key_verify_signature(p->pub, p->sig);
if (ret < 0)
return ret;
x509->signer = p;
if (x509 == p) {
pr_debug("- self-signed\n");
return 0;
}
x509 = p;
might_sleep();
}
unsupported_crypto_in_x509:
return 0;
}
static int pkcs7_verify_one(struct pkcs7_message *pkcs7,
struct pkcs7_signed_info *sinfo)
{
int ret;
kenter(",%u", sinfo->index);
ret = pkcs7_digest(pkcs7, sinfo);
if (ret < 0)
return ret;
ret = pkcs7_find_key(pkcs7, sinfo);
if (ret < 0)
return ret;
if (!sinfo->signer)
return 0;
pr_devel("Using X.509[%u] for sig %u\n",
sinfo->signer->index, sinfo->index);
if (test_bit(sinfo_has_signing_time, &sinfo->aa_set)) {
if (sinfo->signing_time < sinfo->signer->valid_from ||
sinfo->signing_time > sinfo->signer->valid_to) {
pr_warn("Message signed outside of X.509 validity window\n");
return -EKEYREJECTED;
}
}
ret = public_key_verify_signature(sinfo->signer->pub, sinfo->sig);
if (ret < 0)
return ret;
pr_devel("Verified signature %u\n", sinfo->index);
return pkcs7_verify_sig_chain(pkcs7, sinfo);
}
int pkcs7_verify(struct pkcs7_message *pkcs7,
enum key_being_used_for usage)
{
struct pkcs7_signed_info *sinfo;
int actual_ret = -ENOPKG;
int ret;
kenter("");
switch (usage) {
case VERIFYING_MODULE_SIGNATURE:
if (pkcs7->data_type != OID_data) {
pr_warn("Invalid module sig (not pkcs7-data)\n");
return -EKEYREJECTED;
}
if (pkcs7->have_authattrs) {
pr_warn("Invalid module sig (has authattrs)\n");
return -EKEYREJECTED;
}
break;
case VERIFYING_FIRMWARE_SIGNATURE:
if (pkcs7->data_type != OID_data) {
pr_warn("Invalid firmware sig (not pkcs7-data)\n");
return -EKEYREJECTED;
}
if (!pkcs7->have_authattrs) {
pr_warn("Invalid firmware sig (missing authattrs)\n");
return -EKEYREJECTED;
}
break;
case VERIFYING_KEXEC_PE_SIGNATURE:
if (pkcs7->data_type != OID_msIndirectData) {
pr_warn("Invalid kexec sig (not Authenticode)\n");
return -EKEYREJECTED;
}
break;
case VERIFYING_UNSPECIFIED_SIGNATURE:
if (pkcs7->data_type != OID_data) {
pr_warn("Invalid unspecified sig (not pkcs7-data)\n");
return -EKEYREJECTED;
}
break;
default:
return -EINVAL;
}
for (sinfo = pkcs7->signed_infos; sinfo; sinfo = sinfo->next) {
ret = pkcs7_verify_one(pkcs7, sinfo);
if (sinfo->blacklisted && actual_ret == -ENOPKG)
actual_ret = -EKEYREJECTED;
if (ret < 0) {
if (ret == -ENOPKG) {
sinfo->unsupported_crypto = true;
continue;
}
kleave(" = %d", ret);
return ret;
}
actual_ret = 0;
}
kleave(" = %d", actual_ret);
return actual_ret;
}
int pkcs7_supply_detached_data(struct pkcs7_message *pkcs7,
const void *data, size_t datalen)
{
if (pkcs7->data) {
pr_debug("Data already supplied\n");
return -EINVAL;
}
pkcs7->data = data;
pkcs7->data_len = datalen;
return 0;
}
