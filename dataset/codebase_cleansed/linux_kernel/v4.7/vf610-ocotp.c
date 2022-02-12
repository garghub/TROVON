static int vf610_ocotp_wait_busy(void __iomem *base)
{
int timeout = VF610_OCOTP_TIMEOUT;
while ((readl(base) & OCOTP_CTRL_BUSY) && --timeout)
udelay(10);
if (!timeout) {
writel(OCOTP_CTRL_ERR, base + OCOTP_CTRL_CLR);
return -ETIMEDOUT;
}
udelay(10);
return 0;
}
static int vf610_ocotp_calculate_timing(struct vf610_ocotp *ocotp_dev)
{
u32 clk_rate;
u32 relax, strobe_read, strobe_prog;
u32 timing;
clk_rate = clk_get_rate(ocotp_dev->clk);
relax = clk_rate / (1000000000 / DEF_RELAX) - 1;
strobe_prog = clk_rate / (1000000000 / 10000) + 2 * (DEF_RELAX + 1) - 1;
strobe_read = clk_rate / (1000000000 / 40) + 2 * (DEF_RELAX + 1) - 1;
timing = BF(relax, OCOTP_TIMING_RELAX);
timing |= BF(strobe_read, OCOTP_TIMING_STROBE_READ);
timing |= BF(strobe_prog, OCOTP_TIMING_STROBE_PROG);
return timing;
}
static int vf610_get_fuse_address(int base_addr_offset)
{
int i;
for (i = 0; i < ARRAY_SIZE(base_to_fuse_addr_mappings); i++) {
if (base_to_fuse_addr_mappings[i][0] == base_addr_offset)
return base_to_fuse_addr_mappings[i][1];
}
return -EINVAL;
}
static int vf610_ocotp_read(void *context, unsigned int offset,
void *val, size_t bytes)
{
struct vf610_ocotp *ocotp = context;
void __iomem *base = ocotp->base;
u32 reg, *buf = val;
int fuse_addr;
int ret;
while (bytes > 0) {
fuse_addr = vf610_get_fuse_address(offset);
if (fuse_addr > 0) {
writel(ocotp->timing, base + OCOTP_TIMING);
ret = vf610_ocotp_wait_busy(base + OCOTP_CTRL_REG);
if (ret)
return ret;
reg = readl(base + OCOTP_CTRL_REG);
reg &= ~OCOTP_CTRL_ADDR_MASK;
reg &= ~OCOTP_CTRL_WR_UNLOCK_MASK;
reg |= BF(fuse_addr, OCOTP_CTRL_ADDR);
writel(reg, base + OCOTP_CTRL_REG);
writel(OCOTP_READ_CTRL_READ_FUSE,
base + OCOTP_READ_CTRL_REG);
ret = vf610_ocotp_wait_busy(base + OCOTP_CTRL_REG);
if (ret)
return ret;
if (readl(base) & OCOTP_CTRL_ERR) {
dev_dbg(ocotp->dev, "Error reading from fuse address %x\n",
fuse_addr);
writel(OCOTP_CTRL_ERR, base + OCOTP_CTRL_CLR);
}
*buf = readl(base + OCOTP_READ_FUSE_DATA);
} else {
*buf = 0;
}
buf++;
bytes -= 4;
offset += 4;
}
return 0;
}
static int vf610_ocotp_remove(struct platform_device *pdev)
{
struct vf610_ocotp *ocotp_dev = platform_get_drvdata(pdev);
return nvmem_unregister(ocotp_dev->nvmem);
}
static int vf610_ocotp_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct vf610_ocotp *ocotp_dev;
ocotp_dev = devm_kzalloc(&pdev->dev,
sizeof(struct vf610_ocotp), GFP_KERNEL);
if (!ocotp_dev)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ocotp_dev->base = devm_ioremap_resource(dev, res);
if (IS_ERR(ocotp_dev->base))
return PTR_ERR(ocotp_dev->base);
ocotp_dev->clk = devm_clk_get(dev, NULL);
if (IS_ERR(ocotp_dev->clk)) {
dev_err(dev, "failed getting clock, err = %ld\n",
PTR_ERR(ocotp_dev->clk));
return PTR_ERR(ocotp_dev->clk);
}
ocotp_config.size = resource_size(res);
ocotp_config.priv = ocotp_dev;
ocotp_config.dev = dev;
ocotp_dev->nvmem = nvmem_register(&ocotp_config);
if (IS_ERR(ocotp_dev->nvmem))
return PTR_ERR(ocotp_dev->nvmem);
ocotp_dev->dev = dev;
platform_set_drvdata(pdev, ocotp_dev);
ocotp_dev->timing = vf610_ocotp_calculate_timing(ocotp_dev);
return 0;
}
