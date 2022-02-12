static int imx_ocotp_wait_for_busy(void __iomem *base, u32 flags)
{
int count;
u32 c, mask;
mask = IMX_OCOTP_BM_CTRL_BUSY | IMX_OCOTP_BM_CTRL_ERROR | flags;
for (count = 10000; count >= 0; count--) {
c = readl(base + IMX_OCOTP_ADDR_CTRL);
if (!(c & mask))
break;
cpu_relax();
}
if (count < 0) {
if (c & IMX_OCOTP_BM_CTRL_ERROR)
return -EPERM;
return -ETIMEDOUT;
}
return 0;
}
static void imx_ocotp_clr_err_if_set(void __iomem *base)
{
u32 c;
c = readl(base + IMX_OCOTP_ADDR_CTRL);
if (!(c & IMX_OCOTP_BM_CTRL_ERROR))
return;
writel(IMX_OCOTP_BM_CTRL_ERROR, base + IMX_OCOTP_ADDR_CTRL_CLR);
}
static int imx_ocotp_read(void *context, unsigned int offset,
void *val, size_t bytes)
{
struct ocotp_priv *priv = context;
unsigned int count;
u32 *buf = val;
int i, ret;
u32 index;
index = offset >> 2;
count = bytes >> 2;
if (count > (priv->nregs - index))
count = priv->nregs - index;
mutex_lock(&ocotp_mutex);
ret = clk_prepare_enable(priv->clk);
if (ret < 0) {
mutex_unlock(&ocotp_mutex);
dev_err(priv->dev, "failed to prepare/enable ocotp clk\n");
return ret;
}
ret = imx_ocotp_wait_for_busy(priv->base, 0);
if (ret < 0) {
dev_err(priv->dev, "timeout during read setup\n");
goto read_end;
}
for (i = index; i < (index + count); i++) {
*buf++ = readl(priv->base + IMX_OCOTP_OFFSET_B0W0 +
i * IMX_OCOTP_OFFSET_PER_WORD);
if (*(buf - 1) == IMX_OCOTP_READ_LOCKED_VAL)
imx_ocotp_clr_err_if_set(priv->base);
}
ret = 0;
read_end:
clk_disable_unprepare(priv->clk);
mutex_unlock(&ocotp_mutex);
return ret;
}
static int imx_ocotp_write(void *context, unsigned int offset, void *val,
size_t bytes)
{
struct ocotp_priv *priv = context;
u32 *buf = val;
int ret;
unsigned long clk_rate = 0;
unsigned long strobe_read, relax, strobe_prog;
u32 timing = 0;
u32 ctrl;
u8 waddr;
if ((bytes != priv->config->word_size) ||
(offset % priv->config->word_size))
return -EINVAL;
mutex_lock(&ocotp_mutex);
ret = clk_prepare_enable(priv->clk);
if (ret < 0) {
mutex_unlock(&ocotp_mutex);
dev_err(priv->dev, "failed to prepare/enable ocotp clk\n");
return ret;
}
clk_rate = clk_get_rate(priv->clk);
relax = clk_rate / (1000000000 / DEF_RELAX) - 1;
strobe_prog = clk_rate / (1000000000 / 10000) + 2 * (DEF_RELAX + 1) - 1;
strobe_read = clk_rate / (1000000000 / 40) + 2 * (DEF_RELAX + 1) - 1;
timing = strobe_prog & 0x00000FFF;
timing |= (relax << 12) & 0x0000F000;
timing |= (strobe_read << 16) & 0x003F0000;
writel(timing, priv->base + IMX_OCOTP_ADDR_TIMING);
ret = imx_ocotp_wait_for_busy(priv->base, 0);
if (ret < 0) {
dev_err(priv->dev, "timeout during timing setup\n");
goto write_end;
}
waddr = offset / 4;
ctrl = readl(priv->base + IMX_OCOTP_ADDR_CTRL);
ctrl &= ~IMX_OCOTP_BM_CTRL_ADDR;
ctrl |= waddr & IMX_OCOTP_BM_CTRL_ADDR;
ctrl |= IMX_OCOTP_WR_UNLOCK;
writel(ctrl, priv->base + IMX_OCOTP_ADDR_CTRL);
writel(*buf, priv->base + IMX_OCOTP_ADDR_DATA);
ret = imx_ocotp_wait_for_busy(priv->base, 0);
if (ret < 0) {
if (ret == -EPERM) {
dev_err(priv->dev, "failed write to locked region");
imx_ocotp_clr_err_if_set(priv->base);
} else {
dev_err(priv->dev, "timeout during data write\n");
}
goto write_end;
}
udelay(2);
writel(IMX_OCOTP_BM_CTRL_REL_SHADOWS,
priv->base + IMX_OCOTP_ADDR_CTRL_SET);
ret = imx_ocotp_wait_for_busy(priv->base,
IMX_OCOTP_BM_CTRL_REL_SHADOWS);
if (ret < 0) {
dev_err(priv->dev, "timeout during shadow register reload\n");
goto write_end;
}
write_end:
clk_disable_unprepare(priv->clk);
mutex_unlock(&ocotp_mutex);
if (ret < 0)
return ret;
return bytes;
}
static int imx_ocotp_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id;
struct device *dev = &pdev->dev;
struct resource *res;
struct ocotp_priv *priv;
struct nvmem_device *nvmem;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->base))
return PTR_ERR(priv->base);
priv->clk = devm_clk_get(dev, NULL);
if (IS_ERR(priv->clk))
return PTR_ERR(priv->clk);
of_id = of_match_device(imx_ocotp_dt_ids, dev);
priv->nregs = (unsigned long)of_id->data;
imx_ocotp_nvmem_config.size = 4 * priv->nregs;
imx_ocotp_nvmem_config.dev = dev;
imx_ocotp_nvmem_config.priv = priv;
priv->config = &imx_ocotp_nvmem_config;
nvmem = nvmem_register(&imx_ocotp_nvmem_config);
if (IS_ERR(nvmem))
return PTR_ERR(nvmem);
platform_set_drvdata(pdev, nvmem);
return 0;
}
static int imx_ocotp_remove(struct platform_device *pdev)
{
struct nvmem_device *nvmem = platform_get_drvdata(pdev);
return nvmem_unregister(nvmem);
}
