static void lpss_uart_setup(struct lpss_private_data *pdata)
{
unsigned int offset;
u32 reg;
offset = pdata->dev_desc->prv_offset + LPSS_TX_INT;
reg = readl(pdata->mmio_base + offset);
writel(reg | LPSS_TX_INT_MASK, pdata->mmio_base + offset);
offset = pdata->dev_desc->prv_offset + LPSS_GENERAL;
reg = readl(pdata->mmio_base + offset);
writel(reg | LPSS_GENERAL_UART_RTS_OVRD, pdata->mmio_base + offset);
}
static void lpss_i2c_setup(struct lpss_private_data *pdata)
{
unsigned int offset;
u32 val;
offset = pdata->dev_desc->prv_offset + LPSS_RESETS;
val = readl(pdata->mmio_base + offset);
val |= LPSS_RESETS_RESET_APB | LPSS_RESETS_RESET_FUNC;
writel(val, pdata->mmio_base + offset);
}
static int is_memory(struct acpi_resource *res, void *not_used)
{
struct resource r;
return !acpi_dev_resource_memory(res, &r);
}
static inline void lpt_register_clock_device(void)
{
lpss_clk_dev = platform_device_register_simple("clk-lpt", -1, NULL, 0);
}
static int register_device_clock(struct acpi_device *adev,
struct lpss_private_data *pdata)
{
const struct lpss_device_desc *dev_desc = pdata->dev_desc;
struct lpss_shared_clock *shared_clock = dev_desc->shared_clock;
const char *devname = dev_name(&adev->dev);
struct clk *clk = ERR_PTR(-ENODEV);
struct lpss_clk_data *clk_data;
const char *parent, *clk_name;
void __iomem *prv_base;
if (!lpss_clk_dev)
lpt_register_clock_device();
clk_data = platform_get_drvdata(lpss_clk_dev);
if (!clk_data)
return -ENODEV;
if (dev_desc->clkdev_name) {
clk_register_clkdev(clk_data->clk, dev_desc->clkdev_name,
devname);
return 0;
}
if (!pdata->mmio_base
|| pdata->mmio_size < dev_desc->prv_offset + LPSS_CLK_SIZE)
return -ENODATA;
parent = clk_data->name;
prv_base = pdata->mmio_base + dev_desc->prv_offset;
if (shared_clock) {
clk = shared_clock->clk;
if (!clk) {
clk = clk_register_fixed_rate(NULL, shared_clock->name,
"lpss_clk", 0,
shared_clock->rate);
shared_clock->clk = clk;
}
parent = shared_clock->name;
}
if (dev_desc->clk_gate) {
clk = clk_register_gate(NULL, devname, parent, 0,
prv_base, 0, 0, NULL);
parent = devname;
}
if (dev_desc->clk_divider) {
if (!readl(prv_base))
writel(LPSS_CLK_DIVIDER_DEF_MASK, prv_base);
clk_name = kasprintf(GFP_KERNEL, "%s-div", devname);
if (!clk_name)
return -ENOMEM;
clk = clk_register_fractional_divider(NULL, clk_name, parent,
0, prv_base,
1, 15, 16, 15, 0, NULL);
parent = clk_name;
clk_name = kasprintf(GFP_KERNEL, "%s-update", devname);
if (!clk_name) {
kfree(parent);
return -ENOMEM;
}
clk = clk_register_gate(NULL, clk_name, parent,
CLK_SET_RATE_PARENT | CLK_SET_RATE_GATE,
prv_base, 31, 0, NULL);
kfree(parent);
kfree(clk_name);
}
if (IS_ERR(clk))
return PTR_ERR(clk);
pdata->clk = clk;
clk_register_clkdev(clk, NULL, devname);
return 0;
}
static int acpi_lpss_create_device(struct acpi_device *adev,
const struct acpi_device_id *id)
{
struct lpss_device_desc *dev_desc;
struct lpss_private_data *pdata;
struct resource_list_entry *rentry;
struct list_head resource_list;
struct platform_device *pdev;
int ret;
dev_desc = (struct lpss_device_desc *)id->driver_data;
if (!dev_desc) {
pdev = acpi_create_platform_device(adev);
return IS_ERR_OR_NULL(pdev) ? PTR_ERR(pdev) : 1;
}
pdata = kzalloc(sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
INIT_LIST_HEAD(&resource_list);
ret = acpi_dev_get_resources(adev, &resource_list, is_memory, NULL);
if (ret < 0)
goto err_out;
list_for_each_entry(rentry, &resource_list, node)
if (resource_type(&rentry->res) == IORESOURCE_MEM) {
if (dev_desc->prv_size_override)
pdata->mmio_size = dev_desc->prv_size_override;
else
pdata->mmio_size = resource_size(&rentry->res);
pdata->mmio_base = ioremap(rentry->res.start,
pdata->mmio_size);
break;
}
acpi_dev_free_resource_list(&resource_list);
pdata->dev_desc = dev_desc;
if (dev_desc->clk_required) {
ret = register_device_clock(adev, pdata);
if (ret) {
ret = 0;
goto err_out;
}
}
ret = acpi_device_fix_up_power(adev);
if (ret) {
ret = 0;
goto err_out;
}
if (dev_desc->setup)
dev_desc->setup(pdata);
adev->driver_data = pdata;
pdev = acpi_create_platform_device(adev);
if (!IS_ERR_OR_NULL(pdev)) {
device_enable_async_suspend(&pdev->dev);
return 1;
}
ret = PTR_ERR(pdev);
adev->driver_data = NULL;
err_out:
kfree(pdata);
return ret;
}
static u32 __lpss_reg_read(struct lpss_private_data *pdata, unsigned int reg)
{
return readl(pdata->mmio_base + pdata->dev_desc->prv_offset + reg);
}
static void __lpss_reg_write(u32 val, struct lpss_private_data *pdata,
unsigned int reg)
{
writel(val, pdata->mmio_base + pdata->dev_desc->prv_offset + reg);
}
static int lpss_reg_read(struct device *dev, unsigned int reg, u32 *val)
{
struct acpi_device *adev;
struct lpss_private_data *pdata;
unsigned long flags;
int ret;
ret = acpi_bus_get_device(ACPI_HANDLE(dev), &adev);
if (WARN_ON(ret))
return ret;
spin_lock_irqsave(&dev->power.lock, flags);
if (pm_runtime_suspended(dev)) {
ret = -EAGAIN;
goto out;
}
pdata = acpi_driver_data(adev);
if (WARN_ON(!pdata || !pdata->mmio_base)) {
ret = -ENODEV;
goto out;
}
*val = __lpss_reg_read(pdata, reg);
out:
spin_unlock_irqrestore(&dev->power.lock, flags);
return ret;
}
static ssize_t lpss_ltr_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
u32 ltr_value = 0;
unsigned int reg;
int ret;
reg = strcmp(attr->attr.name, "auto_ltr") ? LPSS_SW_LTR : LPSS_AUTO_LTR;
ret = lpss_reg_read(dev, reg, &ltr_value);
if (ret)
return ret;
return snprintf(buf, PAGE_SIZE, "%08x\n", ltr_value);
}
static ssize_t lpss_ltr_mode_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
u32 ltr_mode = 0;
char *outstr;
int ret;
ret = lpss_reg_read(dev, LPSS_GENERAL, &ltr_mode);
if (ret)
return ret;
outstr = (ltr_mode & LPSS_GENERAL_LTR_MODE_SW) ? "sw" : "auto";
return sprintf(buf, "%s\n", outstr);
}
static void acpi_lpss_set_ltr(struct device *dev, s32 val)
{
struct lpss_private_data *pdata = acpi_driver_data(ACPI_COMPANION(dev));
u32 ltr_mode, ltr_val;
ltr_mode = __lpss_reg_read(pdata, LPSS_GENERAL);
if (val < 0) {
if (ltr_mode & LPSS_GENERAL_LTR_MODE_SW) {
ltr_mode &= ~LPSS_GENERAL_LTR_MODE_SW;
__lpss_reg_write(ltr_mode, pdata, LPSS_GENERAL);
}
return;
}
ltr_val = __lpss_reg_read(pdata, LPSS_SW_LTR) & ~LPSS_LTR_SNOOP_MASK;
if (val >= LPSS_LTR_SNOOP_LAT_CUTOFF) {
ltr_val |= LPSS_LTR_SNOOP_LAT_32US;
val = LPSS_LTR_MAX_VAL;
} else if (val > LPSS_LTR_MAX_VAL) {
ltr_val |= LPSS_LTR_SNOOP_LAT_32US | LPSS_LTR_SNOOP_REQ;
val >>= LPSS_LTR_SNOOP_LAT_SHIFT;
} else {
ltr_val |= LPSS_LTR_SNOOP_LAT_1US | LPSS_LTR_SNOOP_REQ;
}
ltr_val |= val;
__lpss_reg_write(ltr_val, pdata, LPSS_SW_LTR);
if (!(ltr_mode & LPSS_GENERAL_LTR_MODE_SW)) {
ltr_mode |= LPSS_GENERAL_LTR_MODE_SW;
__lpss_reg_write(ltr_mode, pdata, LPSS_GENERAL);
}
}
static void acpi_lpss_save_ctx(struct device *dev)
{
struct lpss_private_data *pdata = acpi_driver_data(ACPI_COMPANION(dev));
unsigned int i;
for (i = 0; i < LPSS_PRV_REG_COUNT; i++) {
unsigned long offset = i * sizeof(u32);
pdata->prv_reg_ctx[i] = __lpss_reg_read(pdata, offset);
dev_dbg(dev, "saving 0x%08x from LPSS reg at offset 0x%02lx\n",
pdata->prv_reg_ctx[i], offset);
}
}
static void acpi_lpss_restore_ctx(struct device *dev)
{
struct lpss_private_data *pdata = acpi_driver_data(ACPI_COMPANION(dev));
unsigned int i;
msleep(10);
for (i = 0; i < LPSS_PRV_REG_COUNT; i++) {
unsigned long offset = i * sizeof(u32);
__lpss_reg_write(pdata->prv_reg_ctx[i], pdata, offset);
dev_dbg(dev, "restoring 0x%08x to LPSS reg at offset 0x%02lx\n",
pdata->prv_reg_ctx[i], offset);
}
}
static int acpi_lpss_suspend_late(struct device *dev)
{
int ret = pm_generic_suspend_late(dev);
if (ret)
return ret;
acpi_lpss_save_ctx(dev);
return acpi_dev_suspend_late(dev);
}
static int acpi_lpss_restore_early(struct device *dev)
{
int ret = acpi_dev_resume_early(dev);
if (ret)
return ret;
acpi_lpss_restore_ctx(dev);
return pm_generic_resume_early(dev);
}
static int acpi_lpss_runtime_suspend(struct device *dev)
{
int ret = pm_generic_runtime_suspend(dev);
if (ret)
return ret;
acpi_lpss_save_ctx(dev);
return acpi_dev_runtime_suspend(dev);
}
static int acpi_lpss_runtime_resume(struct device *dev)
{
int ret = acpi_dev_runtime_resume(dev);
if (ret)
return ret;
acpi_lpss_restore_ctx(dev);
return pm_generic_runtime_resume(dev);
}
static int acpi_lpss_platform_notify(struct notifier_block *nb,
unsigned long action, void *data)
{
struct platform_device *pdev = to_platform_device(data);
struct lpss_private_data *pdata;
struct acpi_device *adev;
const struct acpi_device_id *id;
id = acpi_match_device(acpi_lpss_device_ids, &pdev->dev);
if (!id || !id->driver_data)
return 0;
if (acpi_bus_get_device(ACPI_HANDLE(&pdev->dev), &adev))
return 0;
pdata = acpi_driver_data(adev);
if (!pdata || !pdata->mmio_base)
return 0;
if (pdata->mmio_size < pdata->dev_desc->prv_offset + LPSS_LTR_SIZE) {
dev_err(&pdev->dev, "MMIO size insufficient to access LTR\n");
return 0;
}
switch (action) {
case BUS_NOTIFY_BOUND_DRIVER:
if (pdata->dev_desc->save_ctx)
pdev->dev.pm_domain = &acpi_lpss_pm_domain;
break;
case BUS_NOTIFY_UNBOUND_DRIVER:
if (pdata->dev_desc->save_ctx)
pdev->dev.pm_domain = NULL;
break;
case BUS_NOTIFY_ADD_DEVICE:
if (pdata->dev_desc->ltr_required)
return sysfs_create_group(&pdev->dev.kobj,
&lpss_attr_group);
case BUS_NOTIFY_DEL_DEVICE:
if (pdata->dev_desc->ltr_required)
sysfs_remove_group(&pdev->dev.kobj, &lpss_attr_group);
default:
break;
}
return 0;
}
static void acpi_lpss_bind(struct device *dev)
{
struct lpss_private_data *pdata = acpi_driver_data(ACPI_COMPANION(dev));
if (!pdata || !pdata->mmio_base || !pdata->dev_desc->ltr_required)
return;
if (pdata->mmio_size >= pdata->dev_desc->prv_offset + LPSS_LTR_SIZE)
dev->power.set_latency_tolerance = acpi_lpss_set_ltr;
else
dev_err(dev, "MMIO size insufficient to access LTR\n");
}
static void acpi_lpss_unbind(struct device *dev)
{
dev->power.set_latency_tolerance = NULL;
}
void __init acpi_lpss_init(void)
{
if (!lpt_clk_init()) {
bus_register_notifier(&platform_bus_type, &acpi_lpss_nb);
acpi_scan_add_handler(&lpss_handler);
}
}
void __init acpi_lpss_init(void)
{
acpi_scan_add_handler(&lpss_handler);
}
