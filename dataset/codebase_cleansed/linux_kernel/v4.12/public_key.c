static void public_key_describe(const struct key *asymmetric_key,
struct seq_file *m)
{
struct public_key *key = asymmetric_key->payload.data[asym_crypto];
if (key)
seq_printf(m, "%s.%s", key->id_type, key->pkey_algo);
}
void public_key_free(struct public_key *key)
{
if (key) {
kfree(key->key);
kfree(key);
}
}
static void public_key_destroy(void *payload0, void *payload3)
{
public_key_free(payload0);
public_key_signature_free(payload3);
}
static void public_key_verify_done(struct crypto_async_request *req, int err)
{
struct public_key_completion *compl = req->data;
if (err == -EINPROGRESS)
return;
compl->err = err;
complete(&compl->completion);
}
int public_key_verify_signature(const struct public_key *pkey,
const struct public_key_signature *sig)
{
struct public_key_completion compl;
struct crypto_akcipher *tfm;
struct akcipher_request *req;
struct scatterlist sig_sg, digest_sg;
const char *alg_name;
char alg_name_buf[CRYPTO_MAX_ALG_NAME];
void *output;
unsigned int outlen;
int ret = -ENOMEM;
pr_devel("==>%s()\n", __func__);
BUG_ON(!pkey);
BUG_ON(!sig);
BUG_ON(!sig->digest);
BUG_ON(!sig->s);
alg_name = sig->pkey_algo;
if (strcmp(sig->pkey_algo, "rsa") == 0) {
if (snprintf(alg_name_buf, CRYPTO_MAX_ALG_NAME,
"pkcs1pad(rsa,%s)", sig->hash_algo
) >= CRYPTO_MAX_ALG_NAME)
return -EINVAL;
alg_name = alg_name_buf;
}
tfm = crypto_alloc_akcipher(alg_name, 0, 0);
if (IS_ERR(tfm))
return PTR_ERR(tfm);
req = akcipher_request_alloc(tfm, GFP_KERNEL);
if (!req)
goto error_free_tfm;
ret = crypto_akcipher_set_pub_key(tfm, pkey->key, pkey->keylen);
if (ret)
goto error_free_req;
ret = -ENOMEM;
outlen = crypto_akcipher_maxsize(tfm);
output = kmalloc(outlen, GFP_KERNEL);
if (!output)
goto error_free_req;
sg_init_one(&sig_sg, sig->s, sig->s_size);
sg_init_one(&digest_sg, output, outlen);
akcipher_request_set_crypt(req, &sig_sg, &digest_sg, sig->s_size,
outlen);
init_completion(&compl.completion);
akcipher_request_set_callback(req, CRYPTO_TFM_REQ_MAY_BACKLOG |
CRYPTO_TFM_REQ_MAY_SLEEP,
public_key_verify_done, &compl);
ret = crypto_akcipher_verify(req);
if ((ret == -EINPROGRESS) || (ret == -EBUSY)) {
wait_for_completion(&compl.completion);
ret = compl.err;
}
if (ret < 0)
goto out_free_output;
if (req->dst_len != sig->digest_size ||
memcmp(sig->digest, output, sig->digest_size) != 0)
ret = -EKEYREJECTED;
out_free_output:
kfree(output);
error_free_req:
akcipher_request_free(req);
error_free_tfm:
crypto_free_akcipher(tfm);
pr_devel("<==%s() = %d\n", __func__, ret);
return ret;
}
static int public_key_verify_signature_2(const struct key *key,
const struct public_key_signature *sig)
{
const struct public_key *pk = key->payload.data[asym_crypto];
return public_key_verify_signature(pk, sig);
}
