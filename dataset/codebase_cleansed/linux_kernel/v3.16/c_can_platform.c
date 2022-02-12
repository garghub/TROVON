static u16 c_can_plat_read_reg_aligned_to_16bit(const struct c_can_priv *priv,
enum reg index)
{
return readw(priv->base + priv->regs[index]);
}
static void c_can_plat_write_reg_aligned_to_16bit(const struct c_can_priv *priv,
enum reg index, u16 val)
{
writew(val, priv->base + priv->regs[index]);
}
static u16 c_can_plat_read_reg_aligned_to_32bit(const struct c_can_priv *priv,
enum reg index)
{
return readw(priv->base + 2 * priv->regs[index]);
}
static void c_can_plat_write_reg_aligned_to_32bit(const struct c_can_priv *priv,
enum reg index, u16 val)
{
writew(val, priv->base + 2 * priv->regs[index]);
}
static void c_can_hw_raminit_wait_ti(const struct c_can_priv *priv, u32 mask,
u32 val)
{
val &= mask;
while ((readl(priv->raminit_ctrlreg) & mask) != val)
udelay(1);
}
static void c_can_hw_raminit_ti(const struct c_can_priv *priv, bool enable)
{
u32 mask = CAN_RAMINIT_ALL_MASK(priv->instance);
u32 ctrl;
spin_lock(&raminit_lock);
ctrl = readl(priv->raminit_ctrlreg);
ctrl &= ~CAN_RAMINIT_START_MASK(priv->instance);
ctrl |= CAN_RAMINIT_DONE_MASK(priv->instance);
writel(ctrl, priv->raminit_ctrlreg);
ctrl &= ~CAN_RAMINIT_DONE_MASK(priv->instance);
c_can_hw_raminit_wait_ti(priv, ctrl, mask);
if (enable) {
ctrl |= CAN_RAMINIT_START_MASK(priv->instance);
writel(ctrl, priv->raminit_ctrlreg);
ctrl |= CAN_RAMINIT_DONE_MASK(priv->instance);
c_can_hw_raminit_wait_ti(priv, ctrl, mask);
}
spin_unlock(&raminit_lock);
}
static u32 c_can_plat_read_reg32(const struct c_can_priv *priv, enum reg index)
{
u32 val;
val = priv->read_reg(priv, index);
val |= ((u32) priv->read_reg(priv, index + 1)) << 16;
return val;
}
static void c_can_plat_write_reg32(const struct c_can_priv *priv, enum reg index,
u32 val)
{
priv->write_reg(priv, index + 1, val >> 16);
priv->write_reg(priv, index, val);
}
static u32 d_can_plat_read_reg32(const struct c_can_priv *priv, enum reg index)
{
return readl(priv->base + priv->regs[index]);
}
static void d_can_plat_write_reg32(const struct c_can_priv *priv, enum reg index,
u32 val)
{
writel(val, priv->base + priv->regs[index]);
}
static void c_can_hw_raminit_wait(const struct c_can_priv *priv, u32 mask)
{
while (priv->read_reg32(priv, C_CAN_FUNCTION_REG) & mask)
udelay(1);
}
static void c_can_hw_raminit(const struct c_can_priv *priv, bool enable)
{
u32 ctrl;
ctrl = priv->read_reg32(priv, C_CAN_FUNCTION_REG);
ctrl &= ~DCAN_RAM_INIT_BIT;
priv->write_reg32(priv, C_CAN_FUNCTION_REG, ctrl);
c_can_hw_raminit_wait(priv, ctrl);
if (enable) {
ctrl |= DCAN_RAM_INIT_BIT;
priv->write_reg32(priv, C_CAN_FUNCTION_REG, ctrl);
c_can_hw_raminit_wait(priv, ctrl);
}
}
static int c_can_plat_probe(struct platform_device *pdev)
{
int ret;
void __iomem *addr;
struct net_device *dev;
struct c_can_priv *priv;
const struct of_device_id *match;
const struct platform_device_id *id;
struct resource *mem, *res;
int irq;
struct clk *clk;
if (pdev->dev.of_node) {
match = of_match_device(c_can_of_table, &pdev->dev);
if (!match) {
dev_err(&pdev->dev, "Failed to find matching dt id\n");
ret = -EINVAL;
goto exit;
}
id = match->data;
} else {
id = platform_get_device_id(pdev);
}
clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "no clock defined\n");
ret = -ENODEV;
goto exit;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!mem || irq <= 0) {
ret = -ENODEV;
goto exit_free_clk;
}
if (!request_mem_region(mem->start, resource_size(mem),
KBUILD_MODNAME)) {
dev_err(&pdev->dev, "resource unavailable\n");
ret = -ENODEV;
goto exit_free_clk;
}
addr = ioremap(mem->start, resource_size(mem));
if (!addr) {
dev_err(&pdev->dev, "failed to map can port\n");
ret = -ENOMEM;
goto exit_release_mem;
}
dev = alloc_c_can_dev();
if (!dev) {
ret = -ENOMEM;
goto exit_iounmap;
}
priv = netdev_priv(dev);
switch (id->driver_data) {
case BOSCH_C_CAN:
priv->regs = reg_map_c_can;
switch (mem->flags & IORESOURCE_MEM_TYPE_MASK) {
case IORESOURCE_MEM_32BIT:
priv->read_reg = c_can_plat_read_reg_aligned_to_32bit;
priv->write_reg = c_can_plat_write_reg_aligned_to_32bit;
priv->read_reg32 = c_can_plat_read_reg32;
priv->write_reg32 = c_can_plat_write_reg32;
break;
case IORESOURCE_MEM_16BIT:
default:
priv->read_reg = c_can_plat_read_reg_aligned_to_16bit;
priv->write_reg = c_can_plat_write_reg_aligned_to_16bit;
priv->read_reg32 = c_can_plat_read_reg32;
priv->write_reg32 = c_can_plat_write_reg32;
break;
}
break;
case BOSCH_D_CAN:
priv->regs = reg_map_d_can;
priv->can.ctrlmode_supported |= CAN_CTRLMODE_3_SAMPLES;
priv->read_reg = c_can_plat_read_reg_aligned_to_16bit;
priv->write_reg = c_can_plat_write_reg_aligned_to_16bit;
priv->read_reg32 = d_can_plat_read_reg32;
priv->write_reg32 = d_can_plat_write_reg32;
if (pdev->dev.of_node)
priv->instance = of_alias_get_id(pdev->dev.of_node, "d_can");
else
priv->instance = pdev->id;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res) {
priv->raminit = c_can_hw_raminit;
break;
}
priv->raminit_ctrlreg = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (IS_ERR(priv->raminit_ctrlreg) || priv->instance < 0)
dev_info(&pdev->dev, "control memory is not used for raminit\n");
else
priv->raminit = c_can_hw_raminit_ti;
break;
default:
ret = -EINVAL;
goto exit_free_device;
}
dev->irq = irq;
priv->base = addr;
priv->device = &pdev->dev;
priv->can.clock.freq = clk_get_rate(clk);
priv->priv = clk;
priv->type = id->driver_data;
platform_set_drvdata(pdev, dev);
SET_NETDEV_DEV(dev, &pdev->dev);
ret = register_c_can_dev(dev);
if (ret) {
dev_err(&pdev->dev, "registering %s failed (err=%d)\n",
KBUILD_MODNAME, ret);
goto exit_free_device;
}
dev_info(&pdev->dev, "%s device registered (regs=%p, irq=%d)\n",
KBUILD_MODNAME, priv->base, dev->irq);
return 0;
exit_free_device:
free_c_can_dev(dev);
exit_iounmap:
iounmap(addr);
exit_release_mem:
release_mem_region(mem->start, resource_size(mem));
exit_free_clk:
clk_put(clk);
exit:
dev_err(&pdev->dev, "probe failed\n");
return ret;
}
static int c_can_plat_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct c_can_priv *priv = netdev_priv(dev);
struct resource *mem;
unregister_c_can_dev(dev);
free_c_can_dev(dev);
iounmap(priv->base);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(mem->start, resource_size(mem));
clk_put(priv->priv);
return 0;
}
static int c_can_suspend(struct platform_device *pdev, pm_message_t state)
{
int ret;
struct net_device *ndev = platform_get_drvdata(pdev);
struct c_can_priv *priv = netdev_priv(ndev);
if (priv->type != BOSCH_D_CAN) {
dev_warn(&pdev->dev, "Not supported\n");
return 0;
}
if (netif_running(ndev)) {
netif_stop_queue(ndev);
netif_device_detach(ndev);
}
ret = c_can_power_down(ndev);
if (ret) {
netdev_err(ndev, "failed to enter power down mode\n");
return ret;
}
priv->can.state = CAN_STATE_SLEEPING;
return 0;
}
static int c_can_resume(struct platform_device *pdev)
{
int ret;
struct net_device *ndev = platform_get_drvdata(pdev);
struct c_can_priv *priv = netdev_priv(ndev);
if (priv->type != BOSCH_D_CAN) {
dev_warn(&pdev->dev, "Not supported\n");
return 0;
}
ret = c_can_power_up(ndev);
if (ret) {
netdev_err(ndev, "Still in power down mode\n");
return ret;
}
priv->can.state = CAN_STATE_ERROR_ACTIVE;
if (netif_running(ndev)) {
netif_device_attach(ndev);
netif_start_queue(ndev);
}
return 0;
}
