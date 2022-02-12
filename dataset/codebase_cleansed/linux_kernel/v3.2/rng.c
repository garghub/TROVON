static int rngapi_reset(struct crypto_rng *tfm, u8 *seed, unsigned int slen)
{
u8 *buf = NULL;
int err;
if (!seed && slen) {
buf = kmalloc(slen, GFP_KERNEL);
if (!buf)
return -ENOMEM;
get_random_bytes(buf, slen);
seed = buf;
}
err = crypto_rng_alg(tfm)->rng_reset(tfm, seed, slen);
kfree(buf);
return err;
}
static int crypto_init_rng_ops(struct crypto_tfm *tfm, u32 type, u32 mask)
{
struct rng_alg *alg = &tfm->__crt_alg->cra_rng;
struct rng_tfm *ops = &tfm->crt_rng;
ops->rng_gen_random = alg->rng_make_random;
ops->rng_reset = rngapi_reset;
return 0;
}
static int crypto_rng_report(struct sk_buff *skb, struct crypto_alg *alg)
{
struct crypto_report_rng rrng;
snprintf(rrng.type, CRYPTO_MAX_ALG_NAME, "%s", "rng");
rrng.seedsize = alg->cra_rng.seedsize;
NLA_PUT(skb, CRYPTOCFGA_REPORT_RNG,
sizeof(struct crypto_report_rng), &rrng);
return 0;
nla_put_failure:
return -EMSGSIZE;
}
static int crypto_rng_report(struct sk_buff *skb, struct crypto_alg *alg)
{
return -ENOSYS;
}
static void crypto_rng_show(struct seq_file *m, struct crypto_alg *alg)
{
seq_printf(m, "type : rng\n");
seq_printf(m, "seedsize : %u\n", alg->cra_rng.seedsize);
}
static unsigned int crypto_rng_ctxsize(struct crypto_alg *alg, u32 type,
u32 mask)
{
return alg->cra_ctxsize;
}
int crypto_get_default_rng(void)
{
struct crypto_rng *rng;
int err;
mutex_lock(&crypto_default_rng_lock);
if (!crypto_default_rng) {
rng = crypto_alloc_rng("stdrng", 0, 0);
err = PTR_ERR(rng);
if (IS_ERR(rng))
goto unlock;
err = crypto_rng_reset(rng, NULL, crypto_rng_seedsize(rng));
if (err) {
crypto_free_rng(rng);
goto unlock;
}
crypto_default_rng = rng;
}
crypto_default_rng_refcnt++;
err = 0;
unlock:
mutex_unlock(&crypto_default_rng_lock);
return err;
}
void crypto_put_default_rng(void)
{
mutex_lock(&crypto_default_rng_lock);
if (!--crypto_default_rng_refcnt) {
crypto_free_rng(crypto_default_rng);
crypto_default_rng = NULL;
}
mutex_unlock(&crypto_default_rng_lock);
}
