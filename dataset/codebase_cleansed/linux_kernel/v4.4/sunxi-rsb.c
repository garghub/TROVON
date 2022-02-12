static int sunxi_rsb_device_match(struct device *dev, struct device_driver *drv)
{
return of_driver_match_device(dev, drv);
}
static int sunxi_rsb_device_probe(struct device *dev)
{
const struct sunxi_rsb_driver *drv = to_sunxi_rsb_driver(dev->driver);
struct sunxi_rsb_device *rdev = to_sunxi_rsb_device(dev);
int ret;
if (!drv->probe)
return -ENODEV;
if (!rdev->irq) {
int irq = -ENOENT;
if (dev->of_node)
irq = of_irq_get(dev->of_node, 0);
if (irq == -EPROBE_DEFER)
return irq;
if (irq < 0)
irq = 0;
rdev->irq = irq;
}
ret = of_clk_set_defaults(dev->of_node, false);
if (ret < 0)
return ret;
return drv->probe(rdev);
}
static int sunxi_rsb_device_remove(struct device *dev)
{
const struct sunxi_rsb_driver *drv = to_sunxi_rsb_driver(dev->driver);
return drv->remove(to_sunxi_rsb_device(dev));
}
static void sunxi_rsb_dev_release(struct device *dev)
{
struct sunxi_rsb_device *rdev = to_sunxi_rsb_device(dev);
kfree(rdev);
}
static struct sunxi_rsb_device *sunxi_rsb_device_create(struct sunxi_rsb *rsb,
struct device_node *node, u16 hwaddr, u8 rtaddr)
{
int err;
struct sunxi_rsb_device *rdev;
rdev = kzalloc(sizeof(*rdev), GFP_KERNEL);
if (!rdev)
return ERR_PTR(-ENOMEM);
rdev->rsb = rsb;
rdev->hwaddr = hwaddr;
rdev->rtaddr = rtaddr;
rdev->dev.bus = &sunxi_rsb_bus;
rdev->dev.parent = rsb->dev;
rdev->dev.of_node = node;
rdev->dev.release = sunxi_rsb_dev_release;
dev_set_name(&rdev->dev, "%s-%x", RSB_CTRL_NAME, hwaddr);
err = device_register(&rdev->dev);
if (err < 0) {
dev_err(&rdev->dev, "Can't add %s, status %d\n",
dev_name(&rdev->dev), err);
goto err_device_add;
}
dev_dbg(&rdev->dev, "device %s registered\n", dev_name(&rdev->dev));
err_device_add:
put_device(&rdev->dev);
return ERR_PTR(err);
}
static void sunxi_rsb_device_unregister(struct sunxi_rsb_device *rdev)
{
device_unregister(&rdev->dev);
}
static int sunxi_rsb_remove_devices(struct device *dev, void *data)
{
struct sunxi_rsb_device *rdev = to_sunxi_rsb_device(dev);
if (dev->bus == &sunxi_rsb_bus)
sunxi_rsb_device_unregister(rdev);
return 0;
}
int sunxi_rsb_driver_register(struct sunxi_rsb_driver *rdrv)
{
rdrv->driver.bus = &sunxi_rsb_bus;
return driver_register(&rdrv->driver);
}
static int _sunxi_rsb_run_xfer(struct sunxi_rsb *rsb)
{
if (readl(rsb->regs + RSB_CTRL) & RSB_CTRL_START_TRANS) {
dev_dbg(rsb->dev, "RSB transfer still in progress\n");
return -EBUSY;
}
reinit_completion(&rsb->complete);
writel(RSB_INTS_LOAD_BSY | RSB_INTS_TRANS_ERR | RSB_INTS_TRANS_OVER,
rsb->regs + RSB_INTE);
writel(RSB_CTRL_START_TRANS | RSB_CTRL_GLOBAL_INT_ENB,
rsb->regs + RSB_CTRL);
if (!wait_for_completion_io_timeout(&rsb->complete,
msecs_to_jiffies(100))) {
dev_dbg(rsb->dev, "RSB timeout\n");
writel(RSB_CTRL_ABORT_TRANS, rsb->regs + RSB_CTRL);
writel(readl(rsb->regs + RSB_INTS), rsb->regs + RSB_INTS);
return -ETIMEDOUT;
}
if (rsb->status & RSB_INTS_LOAD_BSY) {
dev_dbg(rsb->dev, "RSB busy\n");
return -EBUSY;
}
if (rsb->status & RSB_INTS_TRANS_ERR) {
if (rsb->status & RSB_INTS_TRANS_ERR_ACK) {
dev_dbg(rsb->dev, "RSB slave nack\n");
return -EINVAL;
}
if (rsb->status & RSB_INTS_TRANS_ERR_DATA) {
dev_dbg(rsb->dev, "RSB transfer data error\n");
return -EIO;
}
}
return 0;
}
static int sunxi_rsb_read(struct sunxi_rsb *rsb, u8 rtaddr, u8 addr,
u32 *buf, size_t len)
{
u32 cmd;
int ret;
if (!buf)
return -EINVAL;
switch (len) {
case 1:
cmd = RSB_CMD_RD8;
break;
case 2:
cmd = RSB_CMD_RD16;
break;
case 4:
cmd = RSB_CMD_RD32;
break;
default:
dev_err(rsb->dev, "Invalid access width: %d\n", len);
return -EINVAL;
}
mutex_lock(&rsb->lock);
writel(addr, rsb->regs + RSB_ADDR);
writel(RSB_DAR_RTA(rtaddr), rsb->regs + RSB_DAR);
writel(cmd, rsb->regs + RSB_CMD);
ret = _sunxi_rsb_run_xfer(rsb);
if (ret)
goto unlock;
*buf = readl(rsb->regs + RSB_DATA);
unlock:
mutex_unlock(&rsb->lock);
return ret;
}
static int sunxi_rsb_write(struct sunxi_rsb *rsb, u8 rtaddr, u8 addr,
const u32 *buf, size_t len)
{
u32 cmd;
int ret;
if (!buf)
return -EINVAL;
switch (len) {
case 1:
cmd = RSB_CMD_WR8;
break;
case 2:
cmd = RSB_CMD_WR16;
break;
case 4:
cmd = RSB_CMD_WR32;
break;
default:
dev_err(rsb->dev, "Invalid access width: %d\n", len);
return -EINVAL;
}
mutex_lock(&rsb->lock);
writel(addr, rsb->regs + RSB_ADDR);
writel(RSB_DAR_RTA(rtaddr), rsb->regs + RSB_DAR);
writel(*buf, rsb->regs + RSB_DATA);
writel(cmd, rsb->regs + RSB_CMD);
ret = _sunxi_rsb_run_xfer(rsb);
mutex_unlock(&rsb->lock);
return ret;
}
static int regmap_sunxi_rsb_reg_read(void *context, unsigned int reg,
unsigned int *val)
{
struct sunxi_rsb_ctx *ctx = context;
struct sunxi_rsb_device *rdev = ctx->rdev;
if (reg > 0xff)
return -EINVAL;
return sunxi_rsb_read(rdev->rsb, rdev->rtaddr, reg, val, ctx->size);
}
static int regmap_sunxi_rsb_reg_write(void *context, unsigned int reg,
unsigned int val)
{
struct sunxi_rsb_ctx *ctx = context;
struct sunxi_rsb_device *rdev = ctx->rdev;
return sunxi_rsb_write(rdev->rsb, rdev->rtaddr, reg, &val, ctx->size);
}
static void regmap_sunxi_rsb_free_ctx(void *context)
{
struct sunxi_rsb_ctx *ctx = context;
kfree(ctx);
}
static struct sunxi_rsb_ctx *regmap_sunxi_rsb_init_ctx(struct sunxi_rsb_device *rdev,
const struct regmap_config *config)
{
struct sunxi_rsb_ctx *ctx;
switch (config->val_bits) {
case 8:
case 16:
case 32:
break;
default:
return ERR_PTR(-EINVAL);
}
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return ERR_PTR(-ENOMEM);
ctx->rdev = rdev;
ctx->size = config->val_bits / 8;
return ctx;
}
struct regmap *__devm_regmap_init_sunxi_rsb(struct sunxi_rsb_device *rdev,
const struct regmap_config *config,
struct lock_class_key *lock_key,
const char *lock_name)
{
struct sunxi_rsb_ctx *ctx = regmap_sunxi_rsb_init_ctx(rdev, config);
if (IS_ERR(ctx))
return ERR_CAST(ctx);
return __devm_regmap_init(&rdev->dev, &regmap_sunxi_rsb, ctx, config,
lock_key, lock_name);
}
static irqreturn_t sunxi_rsb_irq(int irq, void *dev_id)
{
struct sunxi_rsb *rsb = dev_id;
u32 status;
status = readl(rsb->regs + RSB_INTS);
rsb->status = status;
status &= (RSB_INTS_LOAD_BSY | RSB_INTS_TRANS_ERR |
RSB_INTS_TRANS_OVER);
writel(status, rsb->regs + RSB_INTS);
complete(&rsb->complete);
return IRQ_HANDLED;
}
static int sunxi_rsb_init_device_mode(struct sunxi_rsb *rsb)
{
int ret = 0;
u32 reg;
writel(RSB_DMCR_DEVICE_START | RSB_DMCR_MODE_DATA |
RSB_DMCR_MODE_REG | RSB_DMCR_DEV_ADDR, rsb->regs + RSB_DMCR);
readl_poll_timeout(rsb->regs + RSB_DMCR, reg,
!(reg & RSB_DMCR_DEVICE_START), 100, 250000);
if (reg & RSB_DMCR_DEVICE_START)
ret = -ETIMEDOUT;
writel(readl(rsb->regs + RSB_INTS), rsb->regs + RSB_INTS);
return ret;
}
static u8 sunxi_rsb_get_rtaddr(u16 hwaddr)
{
int i;
for (i = 0; i < ARRAY_SIZE(sunxi_rsb_addr_maps); i++)
if (hwaddr == sunxi_rsb_addr_maps[i].hwaddr)
return sunxi_rsb_addr_maps[i].rtaddr;
return 0;
}
static int of_rsb_register_devices(struct sunxi_rsb *rsb)
{
struct device *dev = rsb->dev;
struct device_node *child, *np = dev->of_node;
u32 hwaddr;
u8 rtaddr;
int ret;
if (!np)
return -EINVAL;
for_each_available_child_of_node(np, child) {
dev_dbg(dev, "setting child %s runtime address\n",
child->full_name);
ret = of_property_read_u32(child, "reg", &hwaddr);
if (ret) {
dev_err(dev, "%s: invalid 'reg' property: %d\n",
child->full_name, ret);
continue;
}
rtaddr = sunxi_rsb_get_rtaddr(hwaddr);
if (!rtaddr) {
dev_err(dev, "%s: unknown hardware device address\n",
child->full_name);
continue;
}
writel(RSB_CMD_STRA, rsb->regs + RSB_CMD);
writel(RSB_DAR_RTA(rtaddr) | RSB_DAR_DA(hwaddr),
rsb->regs + RSB_DAR);
ret = _sunxi_rsb_run_xfer(rsb);
if (ret)
dev_warn(dev, "%s: set runtime address failed: %d\n",
child->full_name, ret);
}
for_each_available_child_of_node(np, child) {
struct sunxi_rsb_device *rdev;
dev_dbg(dev, "adding child %s\n", child->full_name);
ret = of_property_read_u32(child, "reg", &hwaddr);
if (ret)
continue;
rtaddr = sunxi_rsb_get_rtaddr(hwaddr);
if (!rtaddr)
continue;
rdev = sunxi_rsb_device_create(rsb, child, hwaddr, rtaddr);
if (IS_ERR(rdev))
dev_err(dev, "failed to add child device %s: %ld\n",
child->full_name, PTR_ERR(rdev));
}
return 0;
}
static int sunxi_rsb_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct resource *r;
struct sunxi_rsb *rsb;
unsigned long p_clk_freq;
u32 clk_delay, clk_freq = 3000000;
int clk_div, irq, ret;
u32 reg;
of_property_read_u32(np, "clock-frequency", &clk_freq);
if (clk_freq > RSB_MAX_FREQ) {
dev_err(dev,
"clock-frequency (%u Hz) is too high (max = 20MHz)\n",
clk_freq);
return -EINVAL;
}
rsb = devm_kzalloc(dev, sizeof(*rsb), GFP_KERNEL);
if (!rsb)
return -ENOMEM;
rsb->dev = dev;
platform_set_drvdata(pdev, rsb);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rsb->regs = devm_ioremap_resource(dev, r);
if (IS_ERR(rsb->regs))
return PTR_ERR(rsb->regs);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "failed to retrieve irq: %d\n", irq);
return irq;
}
rsb->clk = devm_clk_get(dev, NULL);
if (IS_ERR(rsb->clk)) {
ret = PTR_ERR(rsb->clk);
dev_err(dev, "failed to retrieve clk: %d\n", ret);
return ret;
}
ret = clk_prepare_enable(rsb->clk);
if (ret) {
dev_err(dev, "failed to enable clk: %d\n", ret);
return ret;
}
p_clk_freq = clk_get_rate(rsb->clk);
rsb->rstc = devm_reset_control_get(dev, NULL);
if (IS_ERR(rsb->rstc)) {
ret = PTR_ERR(rsb->rstc);
dev_err(dev, "failed to retrieve reset controller: %d\n", ret);
goto err_clk_disable;
}
ret = reset_control_deassert(rsb->rstc);
if (ret) {
dev_err(dev, "failed to deassert reset line: %d\n", ret);
goto err_clk_disable;
}
init_completion(&rsb->complete);
mutex_init(&rsb->lock);
writel(RSB_CTRL_SOFT_RST, rsb->regs + RSB_CTRL);
readl_poll_timeout(rsb->regs + RSB_CTRL, reg,
!(reg & RSB_CTRL_SOFT_RST), 1000, 100000);
clk_div = p_clk_freq / clk_freq / 2;
if (!clk_div)
clk_div = 1;
else if (clk_div > RSB_CCR_MAX_CLK_DIV + 1)
clk_div = RSB_CCR_MAX_CLK_DIV + 1;
clk_delay = clk_div >> 1;
if (!clk_delay)
clk_delay = 1;
dev_info(dev, "RSB running at %lu Hz\n", p_clk_freq / clk_div / 2);
writel(RSB_CCR_SDA_OUT_DELAY(clk_delay) | RSB_CCR_CLK_DIV(clk_div - 1),
rsb->regs + RSB_CCR);
ret = devm_request_irq(dev, irq, sunxi_rsb_irq, 0, RSB_CTRL_NAME, rsb);
if (ret) {
dev_err(dev, "can't register interrupt handler irq %d: %d\n",
irq, ret);
goto err_reset_assert;
}
ret = sunxi_rsb_init_device_mode(rsb);
if (ret)
dev_warn(dev, "Initialize device mode failed: %d\n", ret);
of_rsb_register_devices(rsb);
return 0;
err_reset_assert:
reset_control_assert(rsb->rstc);
err_clk_disable:
clk_disable_unprepare(rsb->clk);
return ret;
}
static int sunxi_rsb_remove(struct platform_device *pdev)
{
struct sunxi_rsb *rsb = platform_get_drvdata(pdev);
device_for_each_child(rsb->dev, NULL, sunxi_rsb_remove_devices);
reset_control_assert(rsb->rstc);
clk_disable_unprepare(rsb->clk);
return 0;
}
static int __init sunxi_rsb_init(void)
{
int ret;
ret = bus_register(&sunxi_rsb_bus);
if (ret) {
pr_err("failed to register sunxi sunxi_rsb bus: %d\n", ret);
return ret;
}
return platform_driver_register(&sunxi_rsb_driver);
}
static void __exit sunxi_rsb_exit(void)
{
platform_driver_unregister(&sunxi_rsb_driver);
bus_unregister(&sunxi_rsb_bus);
}
