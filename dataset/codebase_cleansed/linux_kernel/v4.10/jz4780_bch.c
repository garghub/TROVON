static void jz4780_bch_init(struct jz4780_bch *bch,
struct jz4780_bch_params *params, bool encode)
{
u32 reg;
writel(readl(bch->base + BCH_BHINT), bch->base + BCH_BHINT);
reg = params->size << BCH_BHCNT_BLOCKSIZE_SHIFT;
reg |= params->bytes << BCH_BHCNT_PARITYSIZE_SHIFT;
writel(reg, bch->base + BCH_BHCNT);
reg = BCH_BHCR_BCHE | BCH_BHCR_INIT;
reg |= params->strength << BCH_BHCR_BSEL_SHIFT;
if (encode)
reg |= BCH_BHCR_ENCE;
writel(reg, bch->base + BCH_BHCR);
}
static void jz4780_bch_disable(struct jz4780_bch *bch)
{
writel(readl(bch->base + BCH_BHINT), bch->base + BCH_BHINT);
writel(BCH_BHCR_BCHE, bch->base + BCH_BHCCR);
}
static void jz4780_bch_write_data(struct jz4780_bch *bch, const void *buf,
size_t size)
{
size_t size32 = size / sizeof(u32);
size_t size8 = size % sizeof(u32);
const u32 *src32;
const u8 *src8;
src32 = (const u32 *)buf;
while (size32--)
writel(*src32++, bch->base + BCH_BHDR);
src8 = (const u8 *)src32;
while (size8--)
writeb(*src8++, bch->base + BCH_BHDR);
}
static void jz4780_bch_read_parity(struct jz4780_bch *bch, void *buf,
size_t size)
{
size_t size32 = size / sizeof(u32);
size_t size8 = size % sizeof(u32);
u32 *dest32;
u8 *dest8;
u32 val, offset = 0;
dest32 = (u32 *)buf;
while (size32--) {
*dest32++ = readl(bch->base + BCH_BHPAR0 + offset);
offset += sizeof(u32);
}
dest8 = (u8 *)dest32;
val = readl(bch->base + BCH_BHPAR0 + offset);
switch (size8) {
case 3:
dest8[2] = (val >> 16) & 0xff;
case 2:
dest8[1] = (val >> 8) & 0xff;
case 1:
dest8[0] = val & 0xff;
break;
}
}
static bool jz4780_bch_wait_complete(struct jz4780_bch *bch, unsigned int irq,
u32 *status)
{
u32 reg;
int ret;
ret = readl_poll_timeout(bch->base + BCH_BHINT, reg,
(reg & irq) == irq, 0, BCH_TIMEOUT_US);
if (ret)
return false;
if (status)
*status = reg;
writel(reg, bch->base + BCH_BHINT);
return true;
}
int jz4780_bch_calculate(struct jz4780_bch *bch, struct jz4780_bch_params *params,
const u8 *buf, u8 *ecc_code)
{
int ret = 0;
mutex_lock(&bch->lock);
jz4780_bch_init(bch, params, true);
jz4780_bch_write_data(bch, buf, params->size);
if (jz4780_bch_wait_complete(bch, BCH_BHINT_ENCF, NULL)) {
jz4780_bch_read_parity(bch, ecc_code, params->bytes);
} else {
dev_err(bch->dev, "timed out while calculating ECC\n");
ret = -ETIMEDOUT;
}
jz4780_bch_disable(bch);
mutex_unlock(&bch->lock);
return ret;
}
int jz4780_bch_correct(struct jz4780_bch *bch, struct jz4780_bch_params *params,
u8 *buf, u8 *ecc_code)
{
u32 reg, mask, index;
int i, ret, count;
mutex_lock(&bch->lock);
jz4780_bch_init(bch, params, false);
jz4780_bch_write_data(bch, buf, params->size);
jz4780_bch_write_data(bch, ecc_code, params->bytes);
if (!jz4780_bch_wait_complete(bch, BCH_BHINT_DECF, &reg)) {
dev_err(bch->dev, "timed out while correcting data\n");
ret = -ETIMEDOUT;
goto out;
}
if (reg & BCH_BHINT_UNCOR) {
dev_warn(bch->dev, "uncorrectable ECC error\n");
ret = -EBADMSG;
goto out;
}
if (reg & BCH_BHINT_ERR) {
count = (reg & BCH_BHINT_ERRC_MASK) >> BCH_BHINT_ERRC_SHIFT;
ret = (reg & BCH_BHINT_TERRC_MASK) >> BCH_BHINT_TERRC_SHIFT;
for (i = 0; i < count; i++) {
reg = readl(bch->base + BCH_BHERR0 + (i * 4));
mask = (reg & BCH_BHERR_MASK_MASK) >>
BCH_BHERR_MASK_SHIFT;
index = (reg & BCH_BHERR_INDEX_MASK) >>
BCH_BHERR_INDEX_SHIFT;
buf[(index * 2) + 0] ^= mask;
buf[(index * 2) + 1] ^= mask >> 8;
}
} else {
ret = 0;
}
out:
jz4780_bch_disable(bch);
mutex_unlock(&bch->lock);
return ret;
}
static struct jz4780_bch *jz4780_bch_get(struct device_node *np)
{
struct platform_device *pdev;
struct jz4780_bch *bch;
pdev = of_find_device_by_node(np);
if (!pdev || !platform_get_drvdata(pdev))
return ERR_PTR(-EPROBE_DEFER);
get_device(&pdev->dev);
bch = platform_get_drvdata(pdev);
clk_prepare_enable(bch->clk);
return bch;
}
struct jz4780_bch *of_jz4780_bch_get(struct device_node *of_node)
{
struct jz4780_bch *bch = NULL;
struct device_node *np;
np = of_parse_phandle(of_node, "ingenic,bch-controller", 0);
if (np) {
bch = jz4780_bch_get(np);
of_node_put(np);
}
return bch;
}
void jz4780_bch_release(struct jz4780_bch *bch)
{
clk_disable_unprepare(bch->clk);
put_device(bch->dev);
}
static int jz4780_bch_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct jz4780_bch *bch;
struct resource *res;
bch = devm_kzalloc(dev, sizeof(*bch), GFP_KERNEL);
if (!bch)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
bch->base = devm_ioremap_resource(dev, res);
if (IS_ERR(bch->base))
return PTR_ERR(bch->base);
jz4780_bch_disable(bch);
bch->clk = devm_clk_get(dev, NULL);
if (IS_ERR(bch->clk)) {
dev_err(dev, "failed to get clock: %ld\n", PTR_ERR(bch->clk));
return PTR_ERR(bch->clk);
}
clk_set_rate(bch->clk, BCH_CLK_RATE);
mutex_init(&bch->lock);
bch->dev = dev;
platform_set_drvdata(pdev, bch);
return 0;
}
