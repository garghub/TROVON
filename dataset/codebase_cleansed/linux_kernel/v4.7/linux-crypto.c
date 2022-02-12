static int cfs_crypto_hash_alloc(enum cfs_crypto_hash_alg hash_alg,
const struct cfs_crypto_hash_type **type,
struct ahash_request **req,
unsigned char *key,
unsigned int key_len)
{
struct crypto_ahash *tfm;
int err = 0;
*type = cfs_crypto_hash_type(hash_alg);
if (!*type) {
CWARN("Unsupported hash algorithm id = %d, max id is %d\n",
hash_alg, CFS_HASH_ALG_MAX);
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
cfs_crypto_hash_speeds[hash_alg]);
err = crypto_ahash_init(*req);
if (err) {
ahash_request_free(*req);
crypto_free_ahash(tfm);
}
return err;
}
int cfs_crypto_hash_digest(enum cfs_crypto_hash_alg hash_alg,
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
err = cfs_crypto_hash_alloc(hash_alg, &type, &req, key, key_len);
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
cfs_crypto_hash_init(enum cfs_crypto_hash_alg hash_alg,
unsigned char *key, unsigned int key_len)
{
struct ahash_request *req;
int err;
const struct cfs_crypto_hash_type *type;
err = cfs_crypto_hash_alloc(hash_alg, &type, &req, key, key_len);
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
sg_set_page(&sl, page, len, offset & ~PAGE_MASK);
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
if (!hash || !hash_len) {
err = 0;
goto free_ahash;
}
if (*hash_len < size) {
err = -EOVERFLOW;
goto free_ahash;
}
ahash_request_set_crypt(req, NULL, hash, 0);
err = crypto_ahash_final(req);
if (!err)
*hash_len = size;
free_ahash:
crypto_free_ahash(crypto_ahash_reqtfm(req));
ahash_request_free(req);
return err;
}
static void cfs_crypto_performance_test(enum cfs_crypto_hash_alg hash_alg)
{
int buf_len = max(PAGE_SIZE, 1048576UL);
void *buf;
unsigned long start, end;
int bcount, err = 0;
struct page *page;
unsigned char hash[CFS_CRYPTO_HASH_DIGESTSIZE_MAX];
unsigned int hash_len = sizeof(hash);
page = alloc_page(GFP_KERNEL);
if (!page) {
err = -ENOMEM;
goto out_err;
}
buf = kmap(page);
memset(buf, 0xAD, PAGE_SIZE);
kunmap(page);
for (start = jiffies, end = start + msecs_to_jiffies(MSEC_PER_SEC),
bcount = 0; time_before(jiffies, end); bcount++) {
struct cfs_crypto_hash_desc *hdesc;
int i;
hdesc = cfs_crypto_hash_init(hash_alg, NULL, 0);
if (IS_ERR(hdesc)) {
err = PTR_ERR(hdesc);
break;
}
for (i = 0; i < buf_len / PAGE_SIZE; i++) {
err = cfs_crypto_hash_update_page(hdesc, page, 0,
PAGE_SIZE);
if (err)
break;
}
err = cfs_crypto_hash_final(hdesc, hash, &hash_len);
if (err)
break;
}
end = jiffies;
__free_page(page);
out_err:
if (err) {
cfs_crypto_hash_speeds[hash_alg] = err;
CDEBUG(D_INFO, "Crypto hash algorithm %s test error: rc = %d\n",
cfs_crypto_hash_name(hash_alg), err);
} else {
unsigned long tmp;
tmp = ((bcount * buf_len / jiffies_to_msecs(end - start)) *
1000) / (1024 * 1024);
cfs_crypto_hash_speeds[hash_alg] = (int)tmp;
CDEBUG(D_CONFIG, "Crypto hash algorithm %s speed = %d MB/s\n",
cfs_crypto_hash_name(hash_alg),
cfs_crypto_hash_speeds[hash_alg]);
}
}
int cfs_crypto_hash_speed(enum cfs_crypto_hash_alg hash_alg)
{
if (hash_alg < CFS_HASH_ALG_MAX)
return cfs_crypto_hash_speeds[hash_alg];
return -ENOENT;
}
static int cfs_crypto_test_hashes(void)
{
enum cfs_crypto_hash_alg hash_alg;
for (hash_alg = 0; hash_alg < CFS_HASH_ALG_MAX; hash_alg++)
cfs_crypto_performance_test(hash_alg);
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
