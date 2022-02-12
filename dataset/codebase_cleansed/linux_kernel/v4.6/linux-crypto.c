static int cfs_crypto_hash_alloc(unsigned char alg_id,
const struct cfs_crypto_hash_type **type,
struct ahash_request **req,
unsigned char *key,
unsigned int key_len)
{
struct crypto_ahash *tfm;
int err = 0;
*type = cfs_crypto_hash_type(alg_id);
if (!*type) {
CWARN("Unsupported hash algorithm id = %d, max id is %d\n",
alg_id, CFS_HASH_ALG_MAX);
return -EINVAL;
}
tfm = crypto_alloc_ahash((*type)->cht_name, 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(tfm)) {
CDEBUG(D_INFO, "Failed to alloc crypto hash %s\n",
(*type)->cht_name);
return PTR_ERR(tfm);
}
*req = ahash_request_alloc(tfm, GFP_KERNEL);
if (!*req) {
CDEBUG(D_INFO, "Failed to alloc ahash_request for %s\n",
(*type)->cht_name);
crypto_free_ahash(tfm);
return -ENOMEM;
}
ahash_request_set_callback(*req, 0, NULL, NULL);
if (key)
err = crypto_ahash_setkey(tfm, key, key_len);
else if ((*type)->cht_key != 0)
err = crypto_ahash_setkey(tfm,
(unsigned char *)&((*type)->cht_key),
(*type)->cht_size);
if (err != 0) {
crypto_free_ahash(tfm);
return err;
}
CDEBUG(D_INFO, "Using crypto hash: %s (%s) speed %d MB/s\n",
crypto_ahash_alg_name(tfm), crypto_ahash_driver_name(tfm),
cfs_crypto_hash_speeds[alg_id]);
err = crypto_ahash_init(*req);
if (err) {
ahash_request_free(*req);
crypto_free_ahash(tfm);
}
return err;
}
int cfs_crypto_hash_digest(unsigned char alg_id,
const void *buf, unsigned int buf_len,
unsigned char *key, unsigned int key_len,
unsigned char *hash, unsigned int *hash_len)
{
struct scatterlist sl;
struct ahash_request *req;
int err;
const struct cfs_crypto_hash_type *type;
if (!buf || buf_len == 0 || !hash_len)
return -EINVAL;
err = cfs_crypto_hash_alloc(alg_id, &type, &req, key, key_len);
if (err != 0)
return err;
if (!hash || *hash_len < type->cht_size) {
*hash_len = type->cht_size;
crypto_free_ahash(crypto_ahash_reqtfm(req));
ahash_request_free(req);
return -ENOSPC;
}
sg_init_one(&sl, buf, buf_len);
ahash_request_set_crypt(req, &sl, hash, sl.length);
err = crypto_ahash_digest(req);
crypto_free_ahash(crypto_ahash_reqtfm(req));
ahash_request_free(req);
return err;
}
struct cfs_crypto_hash_desc *
cfs_crypto_hash_init(unsigned char alg_id,
unsigned char *key, unsigned int key_len)
{
struct ahash_request *req;
int err;
const struct cfs_crypto_hash_type *type;
err = cfs_crypto_hash_alloc(alg_id, &type, &req, key, key_len);
if (err)
return ERR_PTR(err);
return (struct cfs_crypto_hash_desc *)req;
}
int cfs_crypto_hash_update_page(struct cfs_crypto_hash_desc *hdesc,
struct page *page, unsigned int offset,
unsigned int len)
{
struct ahash_request *req = (void *)hdesc;
struct scatterlist sl;
sg_init_table(&sl, 1);
sg_set_page(&sl, page, len, offset & ~CFS_PAGE_MASK);
ahash_request_set_crypt(req, &sl, NULL, sl.length);
return crypto_ahash_update(req);
}
int cfs_crypto_hash_update(struct cfs_crypto_hash_desc *hdesc,
const void *buf, unsigned int buf_len)
{
struct ahash_request *req = (void *)hdesc;
struct scatterlist sl;
sg_init_one(&sl, buf, buf_len);
ahash_request_set_crypt(req, &sl, NULL, sl.length);
return crypto_ahash_update(req);
}
int cfs_crypto_hash_final(struct cfs_crypto_hash_desc *hdesc,
unsigned char *hash, unsigned int *hash_len)
{
int err;
struct ahash_request *req = (void *)hdesc;
int size = crypto_ahash_digestsize(crypto_ahash_reqtfm(req));
if (!hash_len) {
crypto_free_ahash(crypto_ahash_reqtfm(req));
ahash_request_free(req);
return 0;
}
if (!hash || *hash_len < size) {
*hash_len = size;
return -ENOSPC;
}
ahash_request_set_crypt(req, NULL, hash, 0);
err = crypto_ahash_final(req);
if (err < 0) {
return err;
}
crypto_free_ahash(crypto_ahash_reqtfm(req));
ahash_request_free(req);
return err;
}
static void cfs_crypto_performance_test(unsigned char alg_id,
const unsigned char *buf,
unsigned int buf_len)
{
unsigned long start, end;
int bcount, err = 0;
int sec = 1;
unsigned char hash[64];
unsigned int hash_len = 64;
for (start = jiffies, end = start + sec * HZ, bcount = 0;
time_before(jiffies, end); bcount++) {
err = cfs_crypto_hash_digest(alg_id, buf, buf_len, NULL, 0,
hash, &hash_len);
if (err)
break;
}
end = jiffies;
if (err) {
cfs_crypto_hash_speeds[alg_id] = -1;
CDEBUG(D_INFO, "Crypto hash algorithm %s, err = %d\n",
cfs_crypto_hash_name(alg_id), err);
} else {
unsigned long tmp;
tmp = ((bcount * buf_len / jiffies_to_msecs(end - start)) *
1000) / (1024 * 1024);
cfs_crypto_hash_speeds[alg_id] = (int)tmp;
}
CDEBUG(D_INFO, "Crypto hash algorithm %s speed = %d MB/s\n",
cfs_crypto_hash_name(alg_id), cfs_crypto_hash_speeds[alg_id]);
}
int cfs_crypto_hash_speed(unsigned char hash_alg)
{
if (hash_alg < CFS_HASH_ALG_MAX)
return cfs_crypto_hash_speeds[hash_alg];
return -1;
}
static int cfs_crypto_test_hashes(void)
{
unsigned char i;
unsigned char *data;
unsigned int j;
unsigned int data_len = 1 * 128 * 1024;
data = kmalloc(data_len, 0);
if (!data)
return -ENOMEM;
for (j = 0; j < data_len; j++)
data[j] = j & 0xff;
for (i = 0; i < CFS_HASH_ALG_MAX; i++)
cfs_crypto_performance_test(i, data, data_len);
kfree(data);
return 0;
}
int cfs_crypto_register(void)
{
request_module("crc32c");
adler32 = cfs_crypto_adler32_register();
cfs_crypto_test_hashes();
return 0;
}
void cfs_crypto_unregister(void)
{
if (adler32 == 0)
cfs_crypto_adler32_unregister();
}
