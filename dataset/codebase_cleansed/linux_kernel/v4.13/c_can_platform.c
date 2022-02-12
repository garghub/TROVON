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
static void c_can_hw_raminit_wait_syscon(const struct c_can_priv *priv,
u32 mask, u32 val)
{
const struct c_can_raminit *raminit = &priv->raminit_sys;
int timeout = 0;
u32 ctrl = 0;
val &= mask;
do {
udelay(1);
timeout++;
regmap_read(raminit->syscon, raminit->reg, &ctrl);
if (timeout == 1000) {
dev_err(&priv->dev->dev, "%s: time out\n", __func__);
break;
}
} while ((ctrl & mask) != val);
}
static void c_can_hw_raminit_syscon(const struct c_can_priv *priv, bool enable)
{
const struct c_can_raminit *raminit = &priv->raminit_sys;
u32 ctrl = 0;
u32 mask;
spin_lock(&raminit_lock);
mask = 1 << raminit->bits.start | 1 << raminit->bits.done;
regmap_read(raminit->syscon, raminit->reg, &ctrl);
ctrl &= ~mask;
regmap_update_bits(raminit->syscon, raminit->reg, mask, ctrl);
c_can_hw_raminit_wait_syscon(priv, 1 << raminit->bits.start, ctrl);
if (enable) {
ctrl |= 1 << raminit->bits.start;
ctrl |= 1 << raminit->bits.done;
regmap_update_bits(raminit->syscon, raminit->reg, mask, ctrl);
ctrl &= ~(1 << raminit->bits.done);
if (raminit->needs_pulse) {
ctrl &= ~(1 << raminit->bits.start);
regmap_update_bits(raminit->syscon, raminit->reg,
mask, ctrl);
}
ctrl |= 1 << raminit->bits.done;
c_can_hw_raminit_wait_syscon(priv, mask, ctrl);
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
struct resource *mem;
int irq;
struct clk *clk;
const struct c_can_driver_data *drvdata;
struct device_node *np = pdev->dev.of_node;
match = of_match_device(c_can_of_table, &pdev->dev);
if (match) {
drvdata = match->data;
} else if (pdev->id_entry->driver_data) {
drvdata = (struct c_can_driver_data *)
platform_get_device_id(pdev)->driver_data;
} else {
return -ENODEV;
}
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
ret = PTR_ERR(clk);
goto exit;
}
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
ret = -ENODEV;
goto exit;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
addr = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(addr)) {
ret = PTR_ERR(addr);
goto exit;
}
dev = alloc_c_can_dev();
if (!dev) {
ret = -ENOMEM;
goto exit;
}
priv = netdev_priv(dev);
switch (drvdata->id) {
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
if (np && of_property_read_bool(np, "syscon-raminit")) {
u32 id;
struct c_can_raminit *raminit = &priv->raminit_sys;
ret = -EINVAL;
raminit->syscon = syscon_regmap_lookup_by_phandle(np,
"syscon-raminit");
if (IS_ERR(raminit->syscon)) {
ret = PTR_ERR(raminit->syscon);
free_c_can_dev(dev);
return ret;
}
if (of_property_read_u32_index(np, "syscon-raminit", 1,
&raminit->reg)) {
dev_err(&pdev->dev,
"couldn't get the RAMINIT reg. offset!\n");
goto exit_free_device;
}
if (of_property_read_u32_index(np, "syscon-raminit", 2,
&id)) {
dev_err(&pdev->dev,
"couldn't get the CAN instance ID\n");
goto exit_free_device;
}
if (id >= drvdata->raminit_num) {
dev_err(&pdev->dev,
"Invalid CAN instance ID\n");
goto exit_free_device;
}
raminit->bits = drvdata->raminit_bits[id];
raminit->needs_pulse = drvdata->raminit_pulse;
priv->raminit = c_can_hw_raminit_syscon;
} else {
priv->raminit = c_can_hw_raminit;
}
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
priv->type = drvdata->id;
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
exit:
dev_err(&pdev->dev, "probe failed\n");
return ret;
}
static int c_can_plat_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
unregister_c_can_dev(dev);
free_c_can_dev(dev);
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
