static int des_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int key_len)
{
struct s390_des_ctx *ctx = crypto_tfm_ctx(tfm);
u32 *flags = &tfm->crt_flags;
u32 tmp[DES_EXPKEY_WORDS];
if (!des_ekey(tmp, key) && (*flags & CRYPTO_TFM_REQ_WEAK_KEY)) {
*flags |= CRYPTO_TFM_RES_WEAK_KEY;
return -EINVAL;
}
memcpy(ctx->key, key, key_len);
return 0;
}
static void des_encrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
struct s390_des_ctx *ctx = crypto_tfm_ctx(tfm);
cpacf_km(CPACF_KM_DEA_ENC, ctx->key, out, in, DES_BLOCK_SIZE);
}
static void des_decrypt(struct crypto_tfm *tfm, u8 *out, const u8 *in)
{
struct s390_des_ctx *ctx = crypto_tfm_ctx(tfm);
cpacf_km(CPACF_KM_DEA_DEC, ctx->key, out, in, DES_BLOCK_SIZE);
}
static int ecb_desall_crypt(struct blkcipher_desc *desc, long func,
u8 *key, struct blkcipher_walk *walk)
{
int ret = blkcipher_walk_virt(desc, walk);
unsigned int nbytes;
while ((nbytes = walk->nbytes)) {
unsigned int n = nbytes & ~(DES_BLOCK_SIZE - 1);
u8 *out = walk->dst.virt.addr;
u8 *in = walk->src.virt.addr;
ret = cpacf_km(func, key, out, in, n);
if (ret < 0 || ret != n)
return -EIO;
nbytes &= DES_BLOCK_SIZE - 1;
ret = blkcipher_walk_done(desc, walk, nbytes);
}
return ret;
}
static int cbc_desall_crypt(struct blkcipher_desc *desc, long func,
struct blkcipher_walk *walk)
{
struct s390_des_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
int ret = blkcipher_walk_virt(desc, walk);
unsigned int nbytes = walk->nbytes;
struct {
u8 iv[DES_BLOCK_SIZE];
u8 key[DES3_KEY_SIZE];
} param;
if (!nbytes)
goto out;
memcpy(param.iv, walk->iv, DES_BLOCK_SIZE);
memcpy(param.key, ctx->key, DES3_KEY_SIZE);
do {
unsigned int n = nbytes & ~(DES_BLOCK_SIZE - 1);
u8 *out = walk->dst.virt.addr;
u8 *in = walk->src.virt.addr;
ret = cpacf_kmc(func, &param, out, in, n);
if (ret < 0 || ret != n)
return -EIO;
nbytes &= DES_BLOCK_SIZE - 1;
ret = blkcipher_walk_done(desc, walk, nbytes);
} while ((nbytes = walk->nbytes));
memcpy(walk->iv, param.iv, DES_BLOCK_SIZE);
out:
return ret;
}
static int ecb_des_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct s390_des_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ecb_desall_crypt(desc, CPACF_KM_DEA_ENC, ctx->key, &walk);
}
static int ecb_des_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct s390_des_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ecb_desall_crypt(desc, CPACF_KM_DEA_DEC, ctx->key, &walk);
}
static int cbc_des_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return cbc_desall_crypt(desc, CPACF_KMC_DEA_ENC, &walk);
}
static int cbc_des_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return cbc_desall_crypt(desc, CPACF_KMC_DEA_DEC, &walk);
}
static int des3_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int key_len)
{
struct s390_des_ctx *ctx = crypto_tfm_ctx(tfm);
u32 *flags = &tfm->crt_flags;
if (!(crypto_memneq(key, &key[DES_KEY_SIZE], DES_KEY_SIZE) &&
crypto_memneq(&key[DES_KEY_SIZE], &key[DES_KEY_SIZE * 2],
DES_KEY_SIZE)) &&
(*flags & CRYPTO_TFM_REQ_WEAK_KEY)) {
*flags |= CRYPTO_TFM_RES_WEAK_KEY;
return -EINVAL;
}
memcpy(ctx->key, key, key_len);
return 0;
}
static void des3_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct s390_des_ctx *ctx = crypto_tfm_ctx(tfm);
cpacf_km(CPACF_KM_TDEA_192_ENC, ctx->key, dst, src, DES_BLOCK_SIZE);
}
static void des3_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct s390_des_ctx *ctx = crypto_tfm_ctx(tfm);
cpacf_km(CPACF_KM_TDEA_192_DEC, ctx->key, dst, src, DES_BLOCK_SIZE);
}
static int ecb_des3_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct s390_des_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ecb_desall_crypt(desc, CPACF_KM_TDEA_192_ENC, ctx->key, &walk);
}
static int ecb_des3_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct s390_des_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ecb_desall_crypt(desc, CPACF_KM_TDEA_192_DEC, ctx->key, &walk);
}
static int cbc_des3_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return cbc_desall_crypt(desc, CPACF_KMC_TDEA_192_ENC, &walk);
}
static int cbc_des3_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return cbc_desall_crypt(desc, CPACF_KMC_TDEA_192_DEC, &walk);
}
static unsigned int __ctrblk_init(u8 *ctrptr, unsigned int nbytes)
{
unsigned int i, n;
n = (nbytes > PAGE_SIZE) ? PAGE_SIZE : nbytes & ~(DES_BLOCK_SIZE - 1);
for (i = DES_BLOCK_SIZE; i < n; i += DES_BLOCK_SIZE) {
memcpy(ctrptr + i, ctrptr + i - DES_BLOCK_SIZE, DES_BLOCK_SIZE);
crypto_inc(ctrptr + i, DES_BLOCK_SIZE);
}
return n;
}
static int ctr_desall_crypt(struct blkcipher_desc *desc, long func,
struct s390_des_ctx *ctx,
struct blkcipher_walk *walk)
{
int ret = blkcipher_walk_virt_block(desc, walk, DES_BLOCK_SIZE);
unsigned int n, nbytes;
u8 buf[DES_BLOCK_SIZE], ctrbuf[DES_BLOCK_SIZE];
u8 *out, *in, *ctrptr = ctrbuf;
if (!walk->nbytes)
return ret;
if (spin_trylock(&ctrblk_lock))
ctrptr = ctrblk;
memcpy(ctrptr, walk->iv, DES_BLOCK_SIZE);
while ((nbytes = walk->nbytes) >= DES_BLOCK_SIZE) {
out = walk->dst.virt.addr;
in = walk->src.virt.addr;
while (nbytes >= DES_BLOCK_SIZE) {
if (ctrptr == ctrblk)
n = __ctrblk_init(ctrptr, nbytes);
else
n = DES_BLOCK_SIZE;
ret = cpacf_kmctr(func, ctx->key, out, in, n, ctrptr);
if (ret < 0 || ret != n) {
if (ctrptr == ctrblk)
spin_unlock(&ctrblk_lock);
return -EIO;
}
if (n > DES_BLOCK_SIZE)
memcpy(ctrptr, ctrptr + n - DES_BLOCK_SIZE,
DES_BLOCK_SIZE);
crypto_inc(ctrptr, DES_BLOCK_SIZE);
out += n;
in += n;
nbytes -= n;
}
ret = blkcipher_walk_done(desc, walk, nbytes);
}
if (ctrptr == ctrblk) {
if (nbytes)
memcpy(ctrbuf, ctrptr, DES_BLOCK_SIZE);
else
memcpy(walk->iv, ctrptr, DES_BLOCK_SIZE);
spin_unlock(&ctrblk_lock);
} else {
if (!nbytes)
memcpy(walk->iv, ctrptr, DES_BLOCK_SIZE);
}
if (nbytes) {
out = walk->dst.virt.addr;
in = walk->src.virt.addr;
ret = cpacf_kmctr(func, ctx->key, buf, in,
DES_BLOCK_SIZE, ctrbuf);
if (ret < 0 || ret != DES_BLOCK_SIZE)
return -EIO;
memcpy(out, buf, nbytes);
crypto_inc(ctrbuf, DES_BLOCK_SIZE);
ret = blkcipher_walk_done(desc, walk, 0);
memcpy(walk->iv, ctrbuf, DES_BLOCK_SIZE);
}
return ret;
}
static int ctr_des_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct s390_des_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ctr_desall_crypt(desc, CPACF_KMCTR_DEA_ENC, ctx, &walk);
}
static int ctr_des_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct s390_des_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ctr_desall_crypt(desc, CPACF_KMCTR_DEA_DEC, ctx, &walk);
}
static int ctr_des3_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct s390_des_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ctr_desall_crypt(desc, CPACF_KMCTR_TDEA_192_ENC, ctx, &walk);
}
static int ctr_des3_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct s390_des_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ctr_desall_crypt(desc, CPACF_KMCTR_TDEA_192_DEC, ctx, &walk);
}
static int __init des_s390_init(void)
{
int ret;
if (!cpacf_query(CPACF_KM, CPACF_KM_DEA_ENC) ||
!cpacf_query(CPACF_KM, CPACF_KM_TDEA_192_ENC))
return -EOPNOTSUPP;
ret = crypto_register_alg(&des_alg);
if (ret)
goto des_err;
ret = crypto_register_alg(&ecb_des_alg);
if (ret)
goto ecb_des_err;
ret = crypto_register_alg(&cbc_des_alg);
if (ret)
goto cbc_des_err;
ret = crypto_register_alg(&des3_alg);
if (ret)
goto des3_err;
ret = crypto_register_alg(&ecb_des3_alg);
if (ret)
goto ecb_des3_err;
ret = crypto_register_alg(&cbc_des3_alg);
if (ret)
goto cbc_des3_err;
if (cpacf_query(CPACF_KMCTR, CPACF_KMCTR_DEA_ENC) &&
cpacf_query(CPACF_KMCTR, CPACF_KMCTR_TDEA_192_ENC)) {
ret = crypto_register_alg(&ctr_des_alg);
if (ret)
goto ctr_des_err;
ret = crypto_register_alg(&ctr_des3_alg);
if (ret)
goto ctr_des3_err;
ctrblk = (u8 *) __get_free_page(GFP_KERNEL);
if (!ctrblk) {
ret = -ENOMEM;
goto ctr_mem_err;
}
}
out:
return ret;
ctr_mem_err:
crypto_unregister_alg(&ctr_des3_alg);
ctr_des3_err:
crypto_unregister_alg(&ctr_des_alg);
ctr_des_err:
crypto_unregister_alg(&cbc_des3_alg);
cbc_des3_err:
crypto_unregister_alg(&ecb_des3_alg);
ecb_des3_err:
crypto_unregister_alg(&des3_alg);
des3_err:
crypto_unregister_alg(&cbc_des_alg);
cbc_des_err:
crypto_unregister_alg(&ecb_des_alg);
ecb_des_err:
crypto_unregister_alg(&des_alg);
des_err:
goto out;
}
static void __exit des_s390_exit(void)
{
if (ctrblk) {
crypto_unregister_alg(&ctr_des_alg);
crypto_unregister_alg(&ctr_des3_alg);
free_page((unsigned long) ctrblk);
}
crypto_unregister_alg(&cbc_des3_alg);
crypto_unregister_alg(&ecb_des3_alg);
crypto_unregister_alg(&des3_alg);
crypto_unregister_alg(&cbc_des_alg);
crypto_unregister_alg(&ecb_des_alg);
crypto_unregister_alg(&des_alg);
}
