static inline struct crypto_rng *__crypto_rng_cast(struct crypto_tfm *tfm)
{
return container_of(tfm, struct crypto_rng, base);
}
int crypto_rng_reset(struct crypto_rng *tfm, const u8 *seed, unsigned int slen)
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
err = crypto_rng_alg(tfm)->seed(tfm, seed, slen);
kzfree(buf);
return err;
}
static int crypto_rng_init_tfm(struct crypto_tfm *tfm)
{
return 0;
}
static unsigned int seedsize(struct crypto_alg *alg)
{
struct rng_alg *ralg = container_of(alg, struct rng_alg, base);
return ralg->seedsize;
}
static int crypto_rng_report(struct sk_buff *skb, struct crypto_alg *alg)
{
struct crypto_report_rng rrng;
strncpy(rrng.type, "rng", sizeof(rrng.type));
rrng.seedsize = seedsize(alg);
if (nla_put(skb, CRYPTOCFGA_REPORT_RNG,
sizeof(struct crypto_report_rng), &rrng))
goto nla_put_failure;
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
seq_printf(m, "seedsize : %u\n", seedsize(alg));
}
struct crypto_rng *crypto_alloc_rng(const char *alg_name, u32 type, u32 mask)
{
return crypto_alloc_tfm(alg_name, &crypto_rng_type, type, mask);
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
crypto_default_rng_refcnt--;
mutex_unlock(&crypto_default_rng_lock);
}
int crypto_del_default_rng(void)
{
int err = -EBUSY;
mutex_lock(&crypto_default_rng_lock);
if (crypto_default_rng_refcnt)
goto out;
crypto_free_rng(crypto_default_rng);
crypto_default_rng = NULL;
err = 0;
out:
mutex_unlock(&crypto_default_rng_lock);
return err;
}
int crypto_register_rng(struct rng_alg *alg)
{
struct crypto_alg *base = &alg->base;
if (alg->seedsize > PAGE_SIZE / 8)
return -EINVAL;
base->cra_type = &crypto_rng_type;
base->cra_flags &= ~CRYPTO_ALG_TYPE_MASK;
base->cra_flags |= CRYPTO_ALG_TYPE_RNG;
return crypto_register_alg(base);
}
void crypto_unregister_rng(struct rng_alg *alg)
{
crypto_unregister_alg(&alg->base);
}
int crypto_register_rngs(struct rng_alg *algs, int count)
{
int i, ret;
for (i = 0; i < count; i++) {
ret = crypto_register_rng(algs + i);
if (ret)
goto err;
}
return 0;
err:
for (--i; i >= 0; --i)
crypto_unregister_rng(algs + i);
return ret;
}
void crypto_unregister_rngs(struct rng_alg *algs, int count)
{
int i;
for (i = count - 1; i >= 0; --i)
crypto_unregister_rng(algs + i);
}
