static int mxs_ocotp_wait(struct mxs_ocotp *otp)
{
int timeout = OCOTP_TIMEOUT;
unsigned int status = 0;
while (timeout--) {
status = readl(otp->base);
if (!(status & (BM_OCOTP_CTRL_BUSY | BM_OCOTP_CTRL_ERROR)))
break;
cpu_relax();
}
if (status & BM_OCOTP_CTRL_BUSY)
return -EBUSY;
else if (status & BM_OCOTP_CTRL_ERROR)
return -EIO;
return 0;
}
static int mxs_ocotp_read(void *context, unsigned int offset,
void *val, size_t bytes)
{
struct mxs_ocotp *otp = context;
u32 *buf = val;
int ret;
ret = clk_enable(otp->clk);
if (ret)
return ret;
writel(BM_OCOTP_CTRL_ERROR, otp->base + STMP_OFFSET_REG_CLR);
ret = mxs_ocotp_wait(otp);
if (ret)
goto disable_clk;
writel(BM_OCOTP_CTRL_RD_BANK_OPEN, otp->base + STMP_OFFSET_REG_SET);
udelay(1);
ret = mxs_ocotp_wait(otp);
if (ret)
goto close_banks;
while (bytes) {
if ((offset < OCOTP_DATA_OFFSET) || (offset % 16)) {
*buf++ = 0;
} else {
*buf++ = readl(otp->base + offset);
}
bytes -= 4;
offset += 4;
}
close_banks:
writel(BM_OCOTP_CTRL_RD_BANK_OPEN, otp->base + STMP_OFFSET_REG_CLR);
disable_clk:
clk_disable(otp->clk);
return ret;
}
static int mxs_ocotp_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct mxs_data *data;
struct mxs_ocotp *otp;
struct resource *res;
const struct of_device_id *match;
int ret;
match = of_match_device(dev->driver->of_match_table, dev);
if (!match || !match->data)
return -EINVAL;
otp = devm_kzalloc(dev, sizeof(*otp), GFP_KERNEL);
if (!otp)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
otp->base = devm_ioremap_resource(dev, res);
if (IS_ERR(otp->base))
return PTR_ERR(otp->base);
otp->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(otp->clk))
return PTR_ERR(otp->clk);
ret = clk_prepare(otp->clk);
if (ret < 0) {
dev_err(dev, "failed to prepare clk: %d\n", ret);
return ret;
}
data = match->data;
ocotp_config.size = data->size;
ocotp_config.priv = otp;
ocotp_config.dev = dev;
otp->nvmem = nvmem_register(&ocotp_config);
if (IS_ERR(otp->nvmem)) {
ret = PTR_ERR(otp->nvmem);
goto err_clk;
}
platform_set_drvdata(pdev, otp);
return 0;
err_clk:
clk_unprepare(otp->clk);
return ret;
}
static int mxs_ocotp_remove(struct platform_device *pdev)
{
struct mxs_ocotp *otp = platform_get_drvdata(pdev);
clk_unprepare(otp->clk);
return nvmem_unregister(otp->nvmem);
}
