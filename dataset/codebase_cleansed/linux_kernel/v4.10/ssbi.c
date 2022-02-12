static inline u32 ssbi_readl(struct ssbi *ssbi, u32 reg)
{
return readl(ssbi->base + reg);
}
static inline void ssbi_writel(struct ssbi *ssbi, u32 val, u32 reg)
{
writel(val, ssbi->base + reg);
}
static int ssbi_wait_mask(struct ssbi *ssbi, u32 set_mask, u32 clr_mask)
{
u32 timeout = SSBI_TIMEOUT_US;
u32 val;
while (timeout--) {
val = ssbi_readl(ssbi, SSBI2_STATUS);
if (((val & set_mask) == set_mask) && ((val & clr_mask) == 0))
return 0;
udelay(1);
}
return -ETIMEDOUT;
}
static int
ssbi_read_bytes(struct ssbi *ssbi, u16 addr, u8 *buf, int len)
{
u32 cmd = SSBI_CMD_RDWRN | ((addr & 0xff) << 16);
int ret = 0;
if (ssbi->controller_type == MSM_SBI_CTRL_SSBI2) {
u32 mode2 = ssbi_readl(ssbi, SSBI2_MODE2);
mode2 = SET_SSBI_MODE2_REG_ADDR_15_8(mode2, addr);
ssbi_writel(ssbi, mode2, SSBI2_MODE2);
}
while (len) {
ret = ssbi_wait_mask(ssbi, SSBI_STATUS_READY, 0);
if (ret)
goto err;
ssbi_writel(ssbi, cmd, SSBI2_CMD);
ret = ssbi_wait_mask(ssbi, SSBI_STATUS_RD_READY, 0);
if (ret)
goto err;
*buf++ = ssbi_readl(ssbi, SSBI2_RD) & 0xff;
len--;
}
err:
return ret;
}
static int
ssbi_write_bytes(struct ssbi *ssbi, u16 addr, const u8 *buf, int len)
{
int ret = 0;
if (ssbi->controller_type == MSM_SBI_CTRL_SSBI2) {
u32 mode2 = ssbi_readl(ssbi, SSBI2_MODE2);
mode2 = SET_SSBI_MODE2_REG_ADDR_15_8(mode2, addr);
ssbi_writel(ssbi, mode2, SSBI2_MODE2);
}
while (len) {
ret = ssbi_wait_mask(ssbi, SSBI_STATUS_READY, 0);
if (ret)
goto err;
ssbi_writel(ssbi, ((addr & 0xff) << 16) | *buf, SSBI2_CMD);
ret = ssbi_wait_mask(ssbi, 0, SSBI_STATUS_MCHN_BUSY);
if (ret)
goto err;
buf++;
len--;
}
err:
return ret;
}
static inline int
ssbi_pa_transfer(struct ssbi *ssbi, u32 cmd, u8 *data)
{
u32 timeout = SSBI_TIMEOUT_US;
u32 rd_status = 0;
ssbi_writel(ssbi, cmd, SSBI_PA_CMD);
while (timeout--) {
rd_status = ssbi_readl(ssbi, SSBI_PA_RD_STATUS);
if (rd_status & SSBI_PA_RD_STATUS_TRANS_DENIED)
return -EPERM;
if (rd_status & SSBI_PA_RD_STATUS_TRANS_DONE) {
if (data)
*data = rd_status & 0xff;
return 0;
}
udelay(1);
}
return -ETIMEDOUT;
}
static int
ssbi_pa_read_bytes(struct ssbi *ssbi, u16 addr, u8 *buf, int len)
{
u32 cmd;
int ret = 0;
cmd = SSBI_PA_CMD_RDWRN | (addr & SSBI_PA_CMD_ADDR_MASK) << 8;
while (len) {
ret = ssbi_pa_transfer(ssbi, cmd, buf);
if (ret)
goto err;
buf++;
len--;
}
err:
return ret;
}
static int
ssbi_pa_write_bytes(struct ssbi *ssbi, u16 addr, const u8 *buf, int len)
{
u32 cmd;
int ret = 0;
while (len) {
cmd = (addr & SSBI_PA_CMD_ADDR_MASK) << 8 | *buf;
ret = ssbi_pa_transfer(ssbi, cmd, NULL);
if (ret)
goto err;
buf++;
len--;
}
err:
return ret;
}
int ssbi_read(struct device *dev, u16 addr, u8 *buf, int len)
{
struct ssbi *ssbi = to_ssbi(dev);
unsigned long flags;
int ret;
spin_lock_irqsave(&ssbi->lock, flags);
ret = ssbi->read(ssbi, addr, buf, len);
spin_unlock_irqrestore(&ssbi->lock, flags);
return ret;
}
int ssbi_write(struct device *dev, u16 addr, const u8 *buf, int len)
{
struct ssbi *ssbi = to_ssbi(dev);
unsigned long flags;
int ret;
spin_lock_irqsave(&ssbi->lock, flags);
ret = ssbi->write(ssbi, addr, buf, len);
spin_unlock_irqrestore(&ssbi->lock, flags);
return ret;
}
static int ssbi_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct resource *mem_res;
struct ssbi *ssbi;
const char *type;
ssbi = devm_kzalloc(&pdev->dev, sizeof(*ssbi), GFP_KERNEL);
if (!ssbi)
return -ENOMEM;
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ssbi->base = devm_ioremap_resource(&pdev->dev, mem_res);
if (IS_ERR(ssbi->base))
return PTR_ERR(ssbi->base);
platform_set_drvdata(pdev, ssbi);
type = of_get_property(np, "qcom,controller-type", NULL);
if (type == NULL) {
dev_err(&pdev->dev, "Missing qcom,controller-type property\n");
return -EINVAL;
}
dev_info(&pdev->dev, "SSBI controller type: '%s'\n", type);
if (strcmp(type, "ssbi") == 0)
ssbi->controller_type = MSM_SBI_CTRL_SSBI;
else if (strcmp(type, "ssbi2") == 0)
ssbi->controller_type = MSM_SBI_CTRL_SSBI2;
else if (strcmp(type, "pmic-arbiter") == 0)
ssbi->controller_type = MSM_SBI_CTRL_PMIC_ARBITER;
else {
dev_err(&pdev->dev, "Unknown qcom,controller-type\n");
return -EINVAL;
}
if (ssbi->controller_type == MSM_SBI_CTRL_PMIC_ARBITER) {
ssbi->read = ssbi_pa_read_bytes;
ssbi->write = ssbi_pa_write_bytes;
} else {
ssbi->read = ssbi_read_bytes;
ssbi->write = ssbi_write_bytes;
}
spin_lock_init(&ssbi->lock);
return of_platform_populate(np, NULL, NULL, &pdev->dev);
}
