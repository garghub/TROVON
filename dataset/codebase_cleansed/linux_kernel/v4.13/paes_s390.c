static inline int __paes_convert_key(struct pkey_seckey *sk,
struct pkey_protkey *pk)
{
int i, ret;
for (i = 0; i < 3; i++) {
ret = pkey_skey2pkey(sk, pk);
if (ret == 0)
break;
}
return ret;
}
static int __paes_set_key(struct s390_paes_ctx *ctx)
{
unsigned long fc;
if (__paes_convert_key(&ctx->sk, &ctx->pk))
return -EINVAL;
fc = (ctx->pk.type == PKEY_KEYTYPE_AES_128) ? CPACF_KM_PAES_128 :
(ctx->pk.type == PKEY_KEYTYPE_AES_192) ? CPACF_KM_PAES_192 :
(ctx->pk.type == PKEY_KEYTYPE_AES_256) ? CPACF_KM_PAES_256 : 0;
ctx->fc = (fc && cpacf_test_func(&km_functions, fc)) ? fc : 0;
return ctx->fc ? 0 : -EINVAL;
}
static int ecb_paes_set_key(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct s390_paes_ctx *ctx = crypto_tfm_ctx(tfm);
if (key_len != SECKEYBLOBSIZE)
return -EINVAL;
memcpy(ctx->sk.seckey, in_key, SECKEYBLOBSIZE);
if (__paes_set_key(ctx)) {
tfm->crt_flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
return 0;
}
static int ecb_paes_crypt(struct blkcipher_desc *desc,
unsigned long modifier,
struct blkcipher_walk *walk)
{
struct s390_paes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
unsigned int nbytes, n, k;
int ret;
ret = blkcipher_walk_virt(desc, walk);
while ((nbytes = walk->nbytes) >= AES_BLOCK_SIZE) {
n = nbytes & ~(AES_BLOCK_SIZE - 1);
k = cpacf_km(ctx->fc | modifier, ctx->pk.protkey,
walk->dst.virt.addr, walk->src.virt.addr, n);
if (k)
ret = blkcipher_walk_done(desc, walk, nbytes - k);
if (k < n) {
if (__paes_set_key(ctx) != 0)
return blkcipher_walk_done(desc, walk, -EIO);
}
}
return ret;
}
static int ecb_paes_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ecb_paes_crypt(desc, CPACF_ENCRYPT, &walk);
}
static int ecb_paes_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ecb_paes_crypt(desc, CPACF_DECRYPT, &walk);
}
static int __cbc_paes_set_key(struct s390_paes_ctx *ctx)
{
unsigned long fc;
if (__paes_convert_key(&ctx->sk, &ctx->pk))
return -EINVAL;
fc = (ctx->pk.type == PKEY_KEYTYPE_AES_128) ? CPACF_KMC_PAES_128 :
(ctx->pk.type == PKEY_KEYTYPE_AES_192) ? CPACF_KMC_PAES_192 :
(ctx->pk.type == PKEY_KEYTYPE_AES_256) ? CPACF_KMC_PAES_256 : 0;
ctx->fc = (fc && cpacf_test_func(&kmc_functions, fc)) ? fc : 0;
return ctx->fc ? 0 : -EINVAL;
}
static int cbc_paes_set_key(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct s390_paes_ctx *ctx = crypto_tfm_ctx(tfm);
memcpy(ctx->sk.seckey, in_key, SECKEYBLOBSIZE);
if (__cbc_paes_set_key(ctx)) {
tfm->crt_flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
return 0;
}
static int cbc_paes_crypt(struct blkcipher_desc *desc, unsigned long modifier,
struct blkcipher_walk *walk)
{
struct s390_paes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
unsigned int nbytes, n, k;
int ret;
struct {
u8 iv[AES_BLOCK_SIZE];
u8 key[MAXPROTKEYSIZE];
} param;
ret = blkcipher_walk_virt(desc, walk);
memcpy(param.iv, walk->iv, AES_BLOCK_SIZE);
memcpy(param.key, ctx->pk.protkey, MAXPROTKEYSIZE);
while ((nbytes = walk->nbytes) >= AES_BLOCK_SIZE) {
n = nbytes & ~(AES_BLOCK_SIZE - 1);
k = cpacf_kmc(ctx->fc | modifier, &param,
walk->dst.virt.addr, walk->src.virt.addr, n);
if (k)
ret = blkcipher_walk_done(desc, walk, nbytes - k);
if (n < k) {
if (__cbc_paes_set_key(ctx) != 0)
return blkcipher_walk_done(desc, walk, -EIO);
memcpy(param.key, ctx->pk.protkey, MAXPROTKEYSIZE);
}
}
memcpy(walk->iv, param.iv, AES_BLOCK_SIZE);
return ret;
}
static int cbc_paes_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return cbc_paes_crypt(desc, 0, &walk);
}
static int cbc_paes_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return cbc_paes_crypt(desc, CPACF_DECRYPT, &walk);
}
static int __xts_paes_set_key(struct s390_pxts_ctx *ctx)
{
unsigned long fc;
if (__paes_convert_key(&ctx->sk[0], &ctx->pk[0]) ||
__paes_convert_key(&ctx->sk[1], &ctx->pk[1]))
return -EINVAL;
if (ctx->pk[0].type != ctx->pk[1].type)
return -EINVAL;
fc = (ctx->pk[0].type == PKEY_KEYTYPE_AES_128) ? CPACF_KM_PXTS_128 :
(ctx->pk[0].type == PKEY_KEYTYPE_AES_256) ?
CPACF_KM_PXTS_256 : 0;
ctx->fc = (fc && cpacf_test_func(&km_functions, fc)) ? fc : 0;
return ctx->fc ? 0 : -EINVAL;
}
static int xts_paes_set_key(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct s390_pxts_ctx *ctx = crypto_tfm_ctx(tfm);
u8 ckey[2 * AES_MAX_KEY_SIZE];
unsigned int ckey_len;
memcpy(ctx->sk[0].seckey, in_key, SECKEYBLOBSIZE);
memcpy(ctx->sk[1].seckey, in_key + SECKEYBLOBSIZE, SECKEYBLOBSIZE);
if (__xts_paes_set_key(ctx)) {
tfm->crt_flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
ckey_len = (ctx->pk[0].type == PKEY_KEYTYPE_AES_128) ?
AES_KEYSIZE_128 : AES_KEYSIZE_256;
memcpy(ckey, ctx->pk[0].protkey, ckey_len);
memcpy(ckey + ckey_len, ctx->pk[1].protkey, ckey_len);
return xts_check_key(tfm, ckey, 2*ckey_len);
}
static int xts_paes_crypt(struct blkcipher_desc *desc, unsigned long modifier,
struct blkcipher_walk *walk)
{
struct s390_pxts_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
unsigned int keylen, offset, nbytes, n, k;
int ret;
struct {
u8 key[MAXPROTKEYSIZE];
u8 tweak[16];
u8 block[16];
u8 bit[16];
u8 xts[16];
} pcc_param;
struct {
u8 key[MAXPROTKEYSIZE];
u8 init[16];
} xts_param;
ret = blkcipher_walk_virt(desc, walk);
keylen = (ctx->pk[0].type == PKEY_KEYTYPE_AES_128) ? 48 : 64;
offset = (ctx->pk[0].type == PKEY_KEYTYPE_AES_128) ? 16 : 0;
retry:
memset(&pcc_param, 0, sizeof(pcc_param));
memcpy(pcc_param.tweak, walk->iv, sizeof(pcc_param.tweak));
memcpy(pcc_param.key + offset, ctx->pk[1].protkey, keylen);
cpacf_pcc(ctx->fc, pcc_param.key + offset);
memcpy(xts_param.key + offset, ctx->pk[0].protkey, keylen);
memcpy(xts_param.init, pcc_param.xts, 16);
while ((nbytes = walk->nbytes) >= AES_BLOCK_SIZE) {
n = nbytes & ~(AES_BLOCK_SIZE - 1);
k = cpacf_km(ctx->fc | modifier, xts_param.key + offset,
walk->dst.virt.addr, walk->src.virt.addr, n);
if (k)
ret = blkcipher_walk_done(desc, walk, nbytes - k);
if (k < n) {
if (__xts_paes_set_key(ctx) != 0)
return blkcipher_walk_done(desc, walk, -EIO);
goto retry;
}
}
return ret;
}
static int xts_paes_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return xts_paes_crypt(desc, 0, &walk);
}
static int xts_paes_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return xts_paes_crypt(desc, CPACF_DECRYPT, &walk);
}
static int __ctr_paes_set_key(struct s390_paes_ctx *ctx)
{
unsigned long fc;
if (__paes_convert_key(&ctx->sk, &ctx->pk))
return -EINVAL;
fc = (ctx->pk.type == PKEY_KEYTYPE_AES_128) ? CPACF_KMCTR_PAES_128 :
(ctx->pk.type == PKEY_KEYTYPE_AES_192) ? CPACF_KMCTR_PAES_192 :
(ctx->pk.type == PKEY_KEYTYPE_AES_256) ?
CPACF_KMCTR_PAES_256 : 0;
ctx->fc = (fc && cpacf_test_func(&kmctr_functions, fc)) ? fc : 0;
return ctx->fc ? 0 : -EINVAL;
}
static int ctr_paes_set_key(struct crypto_tfm *tfm, const u8 *in_key,
unsigned int key_len)
{
struct s390_paes_ctx *ctx = crypto_tfm_ctx(tfm);
memcpy(ctx->sk.seckey, in_key, key_len);
if (__ctr_paes_set_key(ctx)) {
tfm->crt_flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
return 0;
}
static unsigned int __ctrblk_init(u8 *ctrptr, u8 *iv, unsigned int nbytes)
{
unsigned int i, n;
memcpy(ctrptr, iv, AES_BLOCK_SIZE);
n = (nbytes > PAGE_SIZE) ? PAGE_SIZE : nbytes & ~(AES_BLOCK_SIZE - 1);
for (i = (n / AES_BLOCK_SIZE) - 1; i > 0; i--) {
memcpy(ctrptr + AES_BLOCK_SIZE, ctrptr, AES_BLOCK_SIZE);
crypto_inc(ctrptr + AES_BLOCK_SIZE, AES_BLOCK_SIZE);
ctrptr += AES_BLOCK_SIZE;
}
return n;
}
static int ctr_paes_crypt(struct blkcipher_desc *desc, unsigned long modifier,
struct blkcipher_walk *walk)
{
struct s390_paes_ctx *ctx = crypto_blkcipher_ctx(desc->tfm);
u8 buf[AES_BLOCK_SIZE], *ctrptr;
unsigned int nbytes, n, k;
int ret, locked;
locked = spin_trylock(&ctrblk_lock);
ret = blkcipher_walk_virt_block(desc, walk, AES_BLOCK_SIZE);
while ((nbytes = walk->nbytes) >= AES_BLOCK_SIZE) {
n = AES_BLOCK_SIZE;
if (nbytes >= 2*AES_BLOCK_SIZE && locked)
n = __ctrblk_init(ctrblk, walk->iv, nbytes);
ctrptr = (n > AES_BLOCK_SIZE) ? ctrblk : walk->iv;
k = cpacf_kmctr(ctx->fc | modifier, ctx->pk.protkey,
walk->dst.virt.addr, walk->src.virt.addr,
n, ctrptr);
if (k) {
if (ctrptr == ctrblk)
memcpy(walk->iv, ctrptr + k - AES_BLOCK_SIZE,
AES_BLOCK_SIZE);
crypto_inc(walk->iv, AES_BLOCK_SIZE);
ret = blkcipher_walk_done(desc, walk, nbytes - n);
}
if (k < n) {
if (__ctr_paes_set_key(ctx) != 0) {
if (locked)
spin_unlock(&ctrblk_lock);
return blkcipher_walk_done(desc, walk, -EIO);
}
}
}
if (locked)
spin_unlock(&ctrblk_lock);
if (nbytes) {
while (1) {
if (cpacf_kmctr(ctx->fc | modifier,
ctx->pk.protkey, buf,
walk->src.virt.addr, AES_BLOCK_SIZE,
walk->iv) == AES_BLOCK_SIZE)
break;
if (__ctr_paes_set_key(ctx) != 0)
return blkcipher_walk_done(desc, walk, -EIO);
}
memcpy(walk->dst.virt.addr, buf, nbytes);
crypto_inc(walk->iv, AES_BLOCK_SIZE);
ret = blkcipher_walk_done(desc, walk, 0);
}
return ret;
}
static int ctr_paes_encrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ctr_paes_crypt(desc, 0, &walk);
}
static int ctr_paes_decrypt(struct blkcipher_desc *desc,
struct scatterlist *dst, struct scatterlist *src,
unsigned int nbytes)
{
struct blkcipher_walk walk;
blkcipher_walk_init(&walk, dst, src, nbytes);
return ctr_paes_crypt(desc, CPACF_DECRYPT, &walk);
}
static inline void __crypto_unregister_alg(struct crypto_alg *alg)
{
if (!list_empty(&alg->cra_list))
crypto_unregister_alg(alg);
}
static void paes_s390_fini(void)
{
if (ctrblk)
free_page((unsigned long) ctrblk);
__crypto_unregister_alg(&ctr_paes_alg);
__crypto_unregister_alg(&xts_paes_alg);
__crypto_unregister_alg(&cbc_paes_alg);
__crypto_unregister_alg(&ecb_paes_alg);
}
static int __init paes_s390_init(void)
{
int ret;
cpacf_query(CPACF_KM, &km_functions);
cpacf_query(CPACF_KMC, &kmc_functions);
cpacf_query(CPACF_KMCTR, &kmctr_functions);
if (cpacf_test_func(&km_functions, CPACF_KM_PAES_128) ||
cpacf_test_func(&km_functions, CPACF_KM_PAES_192) ||
cpacf_test_func(&km_functions, CPACF_KM_PAES_256)) {
ret = crypto_register_alg(&ecb_paes_alg);
if (ret)
goto out_err;
}
if (cpacf_test_func(&kmc_functions, CPACF_KMC_PAES_128) ||
cpacf_test_func(&kmc_functions, CPACF_KMC_PAES_192) ||
cpacf_test_func(&kmc_functions, CPACF_KMC_PAES_256)) {
ret = crypto_register_alg(&cbc_paes_alg);
if (ret)
goto out_err;
}
if (cpacf_test_func(&km_functions, CPACF_KM_PXTS_128) ||
cpacf_test_func(&km_functions, CPACF_KM_PXTS_256)) {
ret = crypto_register_alg(&xts_paes_alg);
if (ret)
goto out_err;
}
if (cpacf_test_func(&kmctr_functions, CPACF_KMCTR_PAES_128) ||
cpacf_test_func(&kmctr_functions, CPACF_KMCTR_PAES_192) ||
cpacf_test_func(&kmctr_functions, CPACF_KMCTR_PAES_256)) {
ret = crypto_register_alg(&ctr_paes_alg);
if (ret)
goto out_err;
ctrblk = (u8 *) __get_free_page(GFP_KERNEL);
if (!ctrblk) {
ret = -ENOMEM;
goto out_err;
}
}
return 0;
out_err:
paes_s390_fini();
return ret;
}
