static u32 exynos_rng_readl(struct exynos_rng_dev *rng, u32 offset)
{
return readl_relaxed(rng->mem + offset);
}
static void exynos_rng_writel(struct exynos_rng_dev *rng, u32 val, u32 offset)
{
writel_relaxed(val, rng->mem + offset);
}
static int exynos_rng_set_seed(struct exynos_rng_dev *rng,
const u8 *seed, unsigned int slen)
{
u32 val;
int i;
slen = ALIGN_DOWN(slen, 4);
if (slen < EXYNOS_RNG_SEED_SIZE)
return -EINVAL;
for (i = 0; i < slen ; i += 4) {
unsigned int seed_reg = (i / 4) % EXYNOS_RNG_SEED_REGS;
val = seed[i] << 24;
val |= seed[i + 1] << 16;
val |= seed[i + 2] << 8;
val |= seed[i + 3] << 0;
exynos_rng_writel(rng, val, EXYNOS_RNG_SEED(seed_reg));
}
val = exynos_rng_readl(rng, EXYNOS_RNG_STATUS);
if (!(val & EXYNOS_RNG_STATUS_SEED_SETTING_DONE)) {
dev_warn(rng->dev, "Seed setting not finished\n");
return -EIO;
}
rng->last_seeding = jiffies;
return 0;
}
static unsigned int exynos_rng_copy_random(struct exynos_rng_dev *rng,
u8 *dst, unsigned int dlen)
{
unsigned int cnt = 0;
int i, j;
u32 val;
for (j = 0; j < EXYNOS_RNG_SEED_REGS; j++) {
val = exynos_rng_readl(rng, EXYNOS_RNG_OUT(j));
for (i = 0; i < 4; i++) {
dst[cnt] = val & 0xff;
val >>= 8;
if (++cnt >= dlen)
return cnt;
}
}
return cnt;
}
static int exynos_rng_get_random(struct exynos_rng_dev *rng,
u8 *dst, unsigned int dlen,
unsigned int *read)
{
int retry = EXYNOS_RNG_WAIT_RETRIES;
exynos_rng_writel(rng, EXYNOS_RNG_CONTROL_START,
EXYNOS_RNG_CONTROL);
while (!(exynos_rng_readl(rng,
EXYNOS_RNG_STATUS) & EXYNOS_RNG_STATUS_RNG_DONE) && --retry)
cpu_relax();
if (!retry)
return -ETIMEDOUT;
exynos_rng_writel(rng, EXYNOS_RNG_STATUS_RNG_DONE,
EXYNOS_RNG_STATUS);
*read = exynos_rng_copy_random(rng, dst, dlen);
return 0;
}
static void exynos_rng_reseed(struct exynos_rng_dev *rng)
{
unsigned long next_seeding = rng->last_seeding + \
msecs_to_jiffies(EXYNOS_RNG_RESEED_TIME);
unsigned long now = jiffies;
unsigned int read = 0;
u8 seed[EXYNOS_RNG_SEED_SIZE];
if (time_before(now, next_seeding))
return;
if (exynos_rng_get_random(rng, seed, sizeof(seed), &read))
return;
exynos_rng_set_seed(rng, seed, read);
}
static int exynos_rng_generate(struct crypto_rng *tfm,
const u8 *src, unsigned int slen,
u8 *dst, unsigned int dlen)
{
struct exynos_rng_ctx *ctx = crypto_rng_ctx(tfm);
struct exynos_rng_dev *rng = ctx->rng;
unsigned int read = 0;
int ret;
ret = clk_prepare_enable(rng->clk);
if (ret)
return ret;
do {
ret = exynos_rng_get_random(rng, dst, dlen, &read);
if (ret)
break;
dlen -= read;
dst += read;
exynos_rng_reseed(rng);
} while (dlen > 0);
clk_disable_unprepare(rng->clk);
return ret;
}
static int exynos_rng_seed(struct crypto_rng *tfm, const u8 *seed,
unsigned int slen)
{
struct exynos_rng_ctx *ctx = crypto_rng_ctx(tfm);
struct exynos_rng_dev *rng = ctx->rng;
int ret;
ret = clk_prepare_enable(rng->clk);
if (ret)
return ret;
ret = exynos_rng_set_seed(ctx->rng, seed, slen);
clk_disable_unprepare(rng->clk);
return ret;
}
static int exynos_rng_kcapi_init(struct crypto_tfm *tfm)
{
struct exynos_rng_ctx *ctx = crypto_tfm_ctx(tfm);
ctx->rng = exynos_rng_dev;
return 0;
}
static int exynos_rng_probe(struct platform_device *pdev)
{
struct exynos_rng_dev *rng;
struct resource *res;
int ret;
if (exynos_rng_dev)
return -EEXIST;
rng = devm_kzalloc(&pdev->dev, sizeof(*rng), GFP_KERNEL);
if (!rng)
return -ENOMEM;
rng->dev = &pdev->dev;
rng->clk = devm_clk_get(&pdev->dev, "secss");
if (IS_ERR(rng->clk)) {
dev_err(&pdev->dev, "Couldn't get clock.\n");
return PTR_ERR(rng->clk);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rng->mem = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rng->mem))
return PTR_ERR(rng->mem);
platform_set_drvdata(pdev, rng);
exynos_rng_dev = rng;
ret = crypto_register_rng(&exynos_rng_alg);
if (ret) {
dev_err(&pdev->dev,
"Couldn't register rng crypto alg: %d\n", ret);
exynos_rng_dev = NULL;
}
return ret;
}
static int exynos_rng_remove(struct platform_device *pdev)
{
crypto_unregister_rng(&exynos_rng_alg);
exynos_rng_dev = NULL;
return 0;
}
static int __maybe_unused exynos_rng_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct exynos_rng_dev *rng = platform_get_drvdata(pdev);
int ret;
if (!rng->last_seeding)
return 0;
rng->seed_save_len = 0;
ret = clk_prepare_enable(rng->clk);
if (ret)
return ret;
exynos_rng_get_random(rng, rng->seed_save, sizeof(rng->seed_save),
&(rng->seed_save_len));
dev_dbg(rng->dev, "Stored %u bytes for seeding on system resume\n",
rng->seed_save_len);
clk_disable_unprepare(rng->clk);
return 0;
}
static int __maybe_unused exynos_rng_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct exynos_rng_dev *rng = platform_get_drvdata(pdev);
int ret;
if (!rng->last_seeding)
return 0;
ret = clk_prepare_enable(rng->clk);
if (ret)
return ret;
ret = exynos_rng_set_seed(rng, rng->seed_save, rng->seed_save_len);
clk_disable_unprepare(rng->clk);
return ret;
}
