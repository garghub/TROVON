static int _rsa_enc(const struct rsa_key *key, MPI c, MPI m)
{
if (mpi_cmp_ui(m, 0) < 0 || mpi_cmp(m, key->n) >= 0)
return -EINVAL;
return mpi_powm(c, m, key->e, key->n);
}
static int _rsa_dec(const struct rsa_key *key, MPI m, MPI c)
{
if (mpi_cmp_ui(c, 0) < 0 || mpi_cmp(c, key->n) >= 0)
return -EINVAL;
return mpi_powm(m, c, key->d, key->n);
}
static int _rsa_sign(const struct rsa_key *key, MPI s, MPI m)
{
if (mpi_cmp_ui(m, 0) < 0 || mpi_cmp(m, key->n) >= 0)
return -EINVAL;
return mpi_powm(s, m, key->d, key->n);
}
static int _rsa_verify(const struct rsa_key *key, MPI m, MPI s)
{
if (mpi_cmp_ui(s, 0) < 0 || mpi_cmp(s, key->n) >= 0)
return -EINVAL;
return mpi_powm(m, s, key->e, key->n);
}
static inline struct rsa_key *rsa_get_key(struct crypto_akcipher *tfm)
{
return akcipher_tfm_ctx(tfm);
}
static int rsa_enc(struct akcipher_request *req)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
const struct rsa_key *pkey = rsa_get_key(tfm);
MPI m, c = mpi_alloc(0);
int ret = 0;
int sign;
if (!c)
return -ENOMEM;
if (unlikely(!pkey->n || !pkey->e)) {
ret = -EINVAL;
goto err_free_c;
}
ret = -ENOMEM;
m = mpi_read_raw_from_sgl(req->src, req->src_len);
if (!m)
goto err_free_c;
ret = _rsa_enc(pkey, c, m);
if (ret)
goto err_free_m;
ret = mpi_write_to_sgl(c, req->dst, &req->dst_len, &sign);
if (ret)
goto err_free_m;
if (sign < 0)
ret = -EBADMSG;
err_free_m:
mpi_free(m);
err_free_c:
mpi_free(c);
return ret;
}
static int rsa_dec(struct akcipher_request *req)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
const struct rsa_key *pkey = rsa_get_key(tfm);
MPI c, m = mpi_alloc(0);
int ret = 0;
int sign;
if (!m)
return -ENOMEM;
if (unlikely(!pkey->n || !pkey->d)) {
ret = -EINVAL;
goto err_free_m;
}
ret = -ENOMEM;
c = mpi_read_raw_from_sgl(req->src, req->src_len);
if (!c)
goto err_free_m;
ret = _rsa_dec(pkey, m, c);
if (ret)
goto err_free_c;
ret = mpi_write_to_sgl(m, req->dst, &req->dst_len, &sign);
if (ret)
goto err_free_c;
if (sign < 0)
ret = -EBADMSG;
err_free_c:
mpi_free(c);
err_free_m:
mpi_free(m);
return ret;
}
static int rsa_sign(struct akcipher_request *req)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
const struct rsa_key *pkey = rsa_get_key(tfm);
MPI m, s = mpi_alloc(0);
int ret = 0;
int sign;
if (!s)
return -ENOMEM;
if (unlikely(!pkey->n || !pkey->d)) {
ret = -EINVAL;
goto err_free_s;
}
ret = -ENOMEM;
m = mpi_read_raw_from_sgl(req->src, req->src_len);
if (!m)
goto err_free_s;
ret = _rsa_sign(pkey, s, m);
if (ret)
goto err_free_m;
ret = mpi_write_to_sgl(s, req->dst, &req->dst_len, &sign);
if (ret)
goto err_free_m;
if (sign < 0)
ret = -EBADMSG;
err_free_m:
mpi_free(m);
err_free_s:
mpi_free(s);
return ret;
}
static int rsa_verify(struct akcipher_request *req)
{
struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
const struct rsa_key *pkey = rsa_get_key(tfm);
MPI s, m = mpi_alloc(0);
int ret = 0;
int sign;
if (!m)
return -ENOMEM;
if (unlikely(!pkey->n || !pkey->e)) {
ret = -EINVAL;
goto err_free_m;
}
ret = -ENOMEM;
s = mpi_read_raw_from_sgl(req->src, req->src_len);
if (!s) {
ret = -ENOMEM;
goto err_free_m;
}
ret = _rsa_verify(pkey, m, s);
if (ret)
goto err_free_s;
ret = mpi_write_to_sgl(m, req->dst, &req->dst_len, &sign);
if (ret)
goto err_free_s;
if (sign < 0)
ret = -EBADMSG;
err_free_s:
mpi_free(s);
err_free_m:
mpi_free(m);
return ret;
}
static int rsa_check_key_length(unsigned int len)
{
switch (len) {
case 512:
case 1024:
case 1536:
case 2048:
case 3072:
case 4096:
return 0;
}
return -EINVAL;
}
static int rsa_set_pub_key(struct crypto_akcipher *tfm, const void *key,
unsigned int keylen)
{
struct rsa_key *pkey = akcipher_tfm_ctx(tfm);
int ret;
ret = rsa_parse_pub_key(pkey, key, keylen);
if (ret)
return ret;
if (rsa_check_key_length(mpi_get_size(pkey->n) << 3)) {
rsa_free_key(pkey);
ret = -EINVAL;
}
return ret;
}
static int rsa_set_priv_key(struct crypto_akcipher *tfm, const void *key,
unsigned int keylen)
{
struct rsa_key *pkey = akcipher_tfm_ctx(tfm);
int ret;
ret = rsa_parse_priv_key(pkey, key, keylen);
if (ret)
return ret;
if (rsa_check_key_length(mpi_get_size(pkey->n) << 3)) {
rsa_free_key(pkey);
ret = -EINVAL;
}
return ret;
}
static int rsa_max_size(struct crypto_akcipher *tfm)
{
struct rsa_key *pkey = akcipher_tfm_ctx(tfm);
return pkey->n ? mpi_get_size(pkey->n) : -EINVAL;
}
static void rsa_exit_tfm(struct crypto_akcipher *tfm)
{
struct rsa_key *pkey = akcipher_tfm_ctx(tfm);
rsa_free_key(pkey);
}
static int rsa_init(void)
{
int err;
err = crypto_register_akcipher(&rsa);
if (err)
return err;
err = crypto_register_template(&rsa_pkcs1pad_tmpl);
if (err) {
crypto_unregister_akcipher(&rsa);
return err;
}
return 0;
}
static void rsa_exit(void)
{
crypto_unregister_template(&rsa_pkcs1pad_tmpl);
crypto_unregister_akcipher(&rsa);
}
