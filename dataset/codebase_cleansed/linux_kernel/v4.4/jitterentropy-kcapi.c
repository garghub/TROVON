__u64 jent_rol64(__u64 word, unsigned int shift)
{
return rol64(word, shift);
}
void *jent_zalloc(unsigned int len)
{
return kzalloc(len, GFP_KERNEL);
}
void jent_zfree(void *ptr)
{
kzfree(ptr);
}
int jent_fips_enabled(void)
{
return fips_enabled;
}
void jent_panic(char *s)
{
panic("%s", s);
}
void jent_memcpy(void *dest, const void *src, unsigned int n)
{
memcpy(dest, src, n);
}
void jent_get_nstime(__u64 *out)
{
struct timespec ts;
__u64 tmp = 0;
tmp = random_get_entropy();
if ((0 == tmp) &&
(0 == __getnstimeofday(&ts))) {
tmp = ts.tv_sec;
tmp = tmp << 32;
tmp = tmp | ts.tv_nsec;
}
*out = tmp;
}
static int jent_kcapi_init(struct crypto_tfm *tfm)
{
struct jitterentropy *rng = crypto_tfm_ctx(tfm);
int ret = 0;
rng->entropy_collector = jent_entropy_collector_alloc(1, 0);
if (!rng->entropy_collector)
ret = -ENOMEM;
spin_lock_init(&rng->jent_lock);
return ret;
}
static void jent_kcapi_cleanup(struct crypto_tfm *tfm)
{
struct jitterentropy *rng = crypto_tfm_ctx(tfm);
spin_lock(&rng->jent_lock);
if (rng->entropy_collector)
jent_entropy_collector_free(rng->entropy_collector);
rng->entropy_collector = NULL;
spin_unlock(&rng->jent_lock);
}
static int jent_kcapi_random(struct crypto_rng *tfm,
const u8 *src, unsigned int slen,
u8 *rdata, unsigned int dlen)
{
struct jitterentropy *rng = crypto_rng_ctx(tfm);
int ret = 0;
spin_lock(&rng->jent_lock);
ret = jent_read_entropy(rng->entropy_collector, rdata, dlen);
spin_unlock(&rng->jent_lock);
return ret;
}
static int jent_kcapi_reset(struct crypto_rng *tfm,
const u8 *seed, unsigned int slen)
{
return 0;
}
static int __init jent_mod_init(void)
{
int ret = 0;
ret = jent_entropy_init();
if (ret) {
pr_info("jitterentropy: Initialization failed with host not compliant with requirements: %d\n", ret);
return -EFAULT;
}
return crypto_register_rng(&jent_alg);
}
static void __exit jent_mod_exit(void)
{
crypto_unregister_rng(&jent_alg);
}
