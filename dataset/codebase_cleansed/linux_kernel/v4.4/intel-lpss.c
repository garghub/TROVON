static int intel_lpss_request_dma_module(const char *name)
{
static bool intel_lpss_dma_requested;
if (intel_lpss_dma_requested)
return 0;
intel_lpss_dma_requested = true;
return request_module("%s", name);
}
static void intel_lpss_cache_ltr(struct intel_lpss *lpss)
{
lpss->active_ltr = readl(lpss->priv + LPSS_PRIV_ACTIVELTR);
lpss->idle_ltr = readl(lpss->priv + LPSS_PRIV_IDLELTR);
}
static int intel_lpss_debugfs_add(struct intel_lpss *lpss)
{
struct dentry *dir;
dir = debugfs_create_dir(dev_name(lpss->dev), intel_lpss_debugfs);
if (IS_ERR(dir))
return PTR_ERR(dir);
intel_lpss_cache_ltr(lpss);
debugfs_create_x32("capabilities", S_IRUGO, dir, &lpss->caps);
debugfs_create_x32("active_ltr", S_IRUGO, dir, &lpss->active_ltr);
debugfs_create_x32("idle_ltr", S_IRUGO, dir, &lpss->idle_ltr);
lpss->debugfs = dir;
return 0;
}
static void intel_lpss_debugfs_remove(struct intel_lpss *lpss)
{
debugfs_remove_recursive(lpss->debugfs);
}
static void intel_lpss_ltr_set(struct device *dev, s32 val)
{
struct intel_lpss *lpss = dev_get_drvdata(dev);
u32 ltr;
ltr = readl(lpss->priv + LPSS_PRIV_ACTIVELTR);
if (val == PM_QOS_LATENCY_ANY || val < 0) {
ltr &= ~LPSS_PRIV_LTR_REQ;
} else {
ltr |= LPSS_PRIV_LTR_REQ;
ltr &= ~LPSS_PRIV_LTR_SCALE_MASK;
ltr &= ~LPSS_PRIV_LTR_VALUE_MASK;
if (val > LPSS_PRIV_LTR_VALUE_MASK)
ltr |= LPSS_PRIV_LTR_SCALE_32US | val >> 5;
else
ltr |= LPSS_PRIV_LTR_SCALE_1US | val;
}
if (ltr == lpss->active_ltr)
return;
writel(ltr, lpss->priv + LPSS_PRIV_ACTIVELTR);
writel(ltr, lpss->priv + LPSS_PRIV_IDLELTR);
intel_lpss_cache_ltr(lpss);
}
static void intel_lpss_ltr_expose(struct intel_lpss *lpss)
{
lpss->dev->power.set_latency_tolerance = intel_lpss_ltr_set;
dev_pm_qos_expose_latency_tolerance(lpss->dev);
}
static void intel_lpss_ltr_hide(struct intel_lpss *lpss)
{
dev_pm_qos_hide_latency_tolerance(lpss->dev);
lpss->dev->power.set_latency_tolerance = NULL;
}
static int intel_lpss_assign_devs(struct intel_lpss *lpss)
{
unsigned int type;
type = lpss->caps & LPSS_PRIV_CAPS_TYPE_MASK;
type >>= LPSS_PRIV_CAPS_TYPE_SHIFT;
switch (type) {
case LPSS_DEV_I2C:
lpss->cell = &intel_lpss_i2c_cell;
break;
case LPSS_DEV_UART:
lpss->cell = &intel_lpss_uart_cell;
break;
case LPSS_DEV_SPI:
lpss->cell = &intel_lpss_spi_cell;
break;
default:
return -ENODEV;
}
lpss->type = type;
return 0;
}
static bool intel_lpss_has_idma(const struct intel_lpss *lpss)
{
return (lpss->caps & LPSS_PRIV_CAPS_NO_IDMA) == 0;
}
static void intel_lpss_set_remap_addr(const struct intel_lpss *lpss)
{
resource_size_t addr = lpss->info->mem->start;
lo_hi_writeq(addr, lpss->priv + LPSS_PRIV_REMAP_ADDR);
}
static void intel_lpss_deassert_reset(const struct intel_lpss *lpss)
{
u32 value = LPSS_PRIV_RESETS_FUNC | LPSS_PRIV_RESETS_IDMA;
writel(value, lpss->priv + LPSS_PRIV_RESETS);
}
static void intel_lpss_init_dev(const struct intel_lpss *lpss)
{
u32 value = LPSS_PRIV_SSP_REG_DIS_DMA_FIN;
intel_lpss_deassert_reset(lpss);
if (!intel_lpss_has_idma(lpss))
return;
intel_lpss_set_remap_addr(lpss);
if (lpss->type == LPSS_DEV_SPI)
writel(value, lpss->priv + LPSS_PRIV_SSP_REG);
}
static void intel_lpss_unregister_clock_tree(struct clk *clk)
{
struct clk *parent;
while (clk) {
parent = clk_get_parent(clk);
clk_unregister(clk);
clk = parent;
}
}
static int intel_lpss_register_clock_divider(struct intel_lpss *lpss,
const char *devname,
struct clk **clk)
{
char name[32];
struct clk *tmp = *clk;
snprintf(name, sizeof(name), "%s-enable", devname);
tmp = clk_register_gate(NULL, name, __clk_get_name(tmp), 0,
lpss->priv, 0, 0, NULL);
if (IS_ERR(tmp))
return PTR_ERR(tmp);
snprintf(name, sizeof(name), "%s-div", devname);
tmp = clk_register_fractional_divider(NULL, name, __clk_get_name(tmp),
0, lpss->priv, 1, 15, 16, 15, 0,
NULL);
if (IS_ERR(tmp))
return PTR_ERR(tmp);
*clk = tmp;
snprintf(name, sizeof(name), "%s-update", devname);
tmp = clk_register_gate(NULL, name, __clk_get_name(tmp),
CLK_SET_RATE_PARENT, lpss->priv, 31, 0, NULL);
if (IS_ERR(tmp))
return PTR_ERR(tmp);
*clk = tmp;
return 0;
}
static int intel_lpss_register_clock(struct intel_lpss *lpss)
{
const struct mfd_cell *cell = lpss->cell;
struct clk *clk;
char devname[24];
int ret;
if (!lpss->info->clk_rate)
return 0;
clk = clk_register_fixed_rate(NULL, dev_name(lpss->dev), NULL,
CLK_IS_ROOT, lpss->info->clk_rate);
if (IS_ERR(clk))
return PTR_ERR(clk);
snprintf(devname, sizeof(devname), "%s.%d", cell->name, lpss->devid);
if (lpss->type != LPSS_DEV_I2C) {
ret = intel_lpss_register_clock_divider(lpss, devname, &clk);
if (ret)
goto err_clk_register;
}
ret = -ENOMEM;
lpss->clock = clkdev_create(clk, lpss->info->clk_con_id, "%s", devname);
if (!lpss->clock)
goto err_clk_register;
lpss->clk = clk;
return 0;
err_clk_register:
intel_lpss_unregister_clock_tree(clk);
return ret;
}
static void intel_lpss_unregister_clock(struct intel_lpss *lpss)
{
if (IS_ERR_OR_NULL(lpss->clk))
return;
clkdev_drop(lpss->clock);
intel_lpss_unregister_clock_tree(lpss->clk);
}
int intel_lpss_probe(struct device *dev,
const struct intel_lpss_platform_info *info)
{
struct intel_lpss *lpss;
int ret;
if (!info || !info->mem || info->irq <= 0)
return -EINVAL;
lpss = devm_kzalloc(dev, sizeof(*lpss), GFP_KERNEL);
if (!lpss)
return -ENOMEM;
lpss->priv = devm_ioremap(dev, info->mem->start + LPSS_PRIV_OFFSET,
LPSS_PRIV_SIZE);
if (!lpss->priv)
return -ENOMEM;
lpss->info = info;
lpss->dev = dev;
lpss->caps = readl(lpss->priv + LPSS_PRIV_CAPS);
dev_set_drvdata(dev, lpss);
ret = intel_lpss_assign_devs(lpss);
if (ret)
return ret;
intel_lpss_init_dev(lpss);
lpss->devid = ida_simple_get(&intel_lpss_devid_ida, 0, 0, GFP_KERNEL);
if (lpss->devid < 0)
return lpss->devid;
ret = intel_lpss_register_clock(lpss);
if (ret)
goto err_clk_register;
intel_lpss_ltr_expose(lpss);
ret = intel_lpss_debugfs_add(lpss);
if (ret)
dev_warn(dev, "Failed to create debugfs entries\n");
if (intel_lpss_has_idma(lpss)) {
intel_lpss_request_dma_module(LPSS_IDMA64_DRIVER_NAME);
ret = mfd_add_devices(dev, lpss->devid, &intel_lpss_idma64_cell,
1, info->mem, info->irq, NULL);
if (ret)
dev_warn(dev, "Failed to add %s, fallback to PIO\n",
LPSS_IDMA64_DRIVER_NAME);
}
ret = mfd_add_devices(dev, lpss->devid, lpss->cell,
1, info->mem, info->irq, NULL);
if (ret)
goto err_remove_ltr;
return 0;
err_remove_ltr:
intel_lpss_debugfs_remove(lpss);
intel_lpss_ltr_hide(lpss);
err_clk_register:
ida_simple_remove(&intel_lpss_devid_ida, lpss->devid);
return ret;
}
void intel_lpss_remove(struct device *dev)
{
struct intel_lpss *lpss = dev_get_drvdata(dev);
mfd_remove_devices(dev);
intel_lpss_debugfs_remove(lpss);
intel_lpss_ltr_hide(lpss);
intel_lpss_unregister_clock(lpss);
ida_simple_remove(&intel_lpss_devid_ida, lpss->devid);
}
static int resume_lpss_device(struct device *dev, void *data)
{
pm_runtime_resume(dev);
return 0;
}
int intel_lpss_prepare(struct device *dev)
{
device_for_each_child_reverse(dev, NULL, resume_lpss_device);
return 0;
}
int intel_lpss_suspend(struct device *dev)
{
return 0;
}
int intel_lpss_resume(struct device *dev)
{
struct intel_lpss *lpss = dev_get_drvdata(dev);
intel_lpss_init_dev(lpss);
return 0;
}
static int __init intel_lpss_init(void)
{
intel_lpss_debugfs = debugfs_create_dir("intel_lpss", NULL);
return 0;
}
static void __exit intel_lpss_exit(void)
{
debugfs_remove(intel_lpss_debugfs);
}
