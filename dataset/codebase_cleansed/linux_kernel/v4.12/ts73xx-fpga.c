static enum fpga_mgr_states ts73xx_fpga_state(struct fpga_manager *mgr)
{
return FPGA_MGR_STATE_UNKNOWN;
}
static int ts73xx_fpga_write_init(struct fpga_manager *mgr,
struct fpga_image_info *info,
const char *buf, size_t count)
{
struct ts73xx_fpga_priv *priv = mgr->priv;
writeb(0, priv->io_base + TS73XX_FPGA_CONFIG_REG);
udelay(TS73XX_FPGA_RESET_LOW_DELAY);
writeb(TS73XX_FPGA_RESET, priv->io_base + TS73XX_FPGA_CONFIG_REG);
udelay(TS73XX_FPGA_RESET_HIGH_DELAY);
return 0;
}
static int ts73xx_fpga_write(struct fpga_manager *mgr, const char *buf,
size_t count)
{
struct ts73xx_fpga_priv *priv = mgr->priv;
size_t i = 0;
int ret;
u8 reg;
while (count--) {
ret = readb_poll_timeout(priv->io_base + TS73XX_FPGA_CONFIG_REG,
reg, !(reg & TS73XX_FPGA_WRITE_DONE),
1, TS73XX_FPGA_WRITE_DONE_TIMEOUT);
if (ret < 0)
return ret;
writeb(buf[i], priv->io_base + TS73XX_FPGA_DATA_REG);
i++;
}
return 0;
}
static int ts73xx_fpga_write_complete(struct fpga_manager *mgr,
struct fpga_image_info *info)
{
struct ts73xx_fpga_priv *priv = mgr->priv;
u8 reg;
usleep_range(1000, 2000);
reg = readb(priv->io_base + TS73XX_FPGA_CONFIG_REG);
reg |= TS73XX_FPGA_CONFIG_LOAD;
writeb(reg, priv->io_base + TS73XX_FPGA_CONFIG_REG);
usleep_range(1000, 2000);
reg = readb(priv->io_base + TS73XX_FPGA_CONFIG_REG);
reg &= ~TS73XX_FPGA_CONFIG_LOAD;
writeb(reg, priv->io_base + TS73XX_FPGA_CONFIG_REG);
reg = readb(priv->io_base + TS73XX_FPGA_CONFIG_REG);
if ((reg & TS73XX_FPGA_LOAD_OK) != TS73XX_FPGA_LOAD_OK)
return -ETIMEDOUT;
return 0;
}
static int ts73xx_fpga_probe(struct platform_device *pdev)
{
struct device *kdev = &pdev->dev;
struct ts73xx_fpga_priv *priv;
struct resource *res;
priv = devm_kzalloc(kdev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->dev = kdev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->io_base = devm_ioremap_resource(kdev, res);
if (IS_ERR(priv->io_base)) {
dev_err(kdev, "unable to remap registers\n");
return PTR_ERR(priv->io_base);
}
return fpga_mgr_register(kdev, "TS-73xx FPGA Manager",
&ts73xx_fpga_ops, priv);
}
static int ts73xx_fpga_remove(struct platform_device *pdev)
{
fpga_mgr_unregister(&pdev->dev);
return 0;
}
