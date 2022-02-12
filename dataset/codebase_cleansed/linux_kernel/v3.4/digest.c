static void init(struct crypto_tfm *tfm)
{
tfm->__crt_alg->cra_digest.dia_init(crypto_tfm_ctx(tfm));
}
static void update(struct crypto_tfm *tfm,
struct scatterlist *sg, unsigned int nsg)
{
unsigned int i;
for (i = 0; i < nsg; i++) {
struct page *pg = sg[i].page;
unsigned int offset = sg[i].offset;
unsigned int l = sg[i].length;
do {
unsigned int bytes_from_page = min(l, ((unsigned int)
(PAGE_SIZE)) -
offset);
char *p = kmap_atomic(pg) + offset;
tfm->__crt_alg->cra_digest.dia_update
(crypto_tfm_ctx(tfm), p,
bytes_from_page);
kunmap_atomic(p);
crypto_yield(tfm);
offset = 0;
pg++;
l -= bytes_from_page;
} while (l > 0);
}
}
static void final(struct crypto_tfm *tfm, u8 *out)
{
tfm->__crt_alg->cra_digest.dia_final(crypto_tfm_ctx(tfm), out);
}
static int setkey(struct crypto_tfm *tfm, const u8 *key, unsigned int keylen)
{
u32 flags;
if (tfm->__crt_alg->cra_digest.dia_setkey == NULL)
return -ENOSYS;
return tfm->__crt_alg->cra_digest.dia_setkey(crypto_tfm_ctx(tfm),
key, keylen, &flags);
}
static void digest(struct crypto_tfm *tfm,
struct scatterlist *sg, unsigned int nsg, u8 *out)
{
unsigned int i;
tfm->crt_digest.dit_init(tfm);
for (i = 0; i < nsg; i++) {
char *p = kmap_atomic(sg[i].page) + sg[i].offset;
tfm->__crt_alg->cra_digest.dia_update(crypto_tfm_ctx(tfm),
p, sg[i].length);
kunmap_atomic(p);
crypto_yield(tfm);
}
crypto_digest_final(tfm, out);
}
int crypto_init_digest_flags(struct crypto_tfm *tfm, u32 flags)
{
return flags ? -EINVAL : 0;
}
int crypto_init_digest_ops(struct crypto_tfm *tfm)
{
struct digest_tfm *ops = &tfm->crt_digest;
ops->dit_init = init;
ops->dit_update = update;
ops->dit_final = final;
ops->dit_digest = digest;
ops->dit_setkey = setkey;
return crypto_alloc_hmac_block(tfm);
}
void crypto_exit_digest_ops(struct crypto_tfm *tfm)
{
crypto_free_hmac_block(tfm);
}
