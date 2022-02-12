static void lpss_uart_setup(struct lpss_private_data *pdata)
{
unsigned int tx_int_offset = pdata->dev_desc->prv_offset + LPSS_TX_INT;
u32 reg;
reg = readl(pdata->mmio_base + tx_int_offset);
writel(reg | LPSS_TX_INT_MASK, pdata->mmio_base + tx_int_offset);
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
struct clk *clk = ERR_PTR(-ENODEV);
struct lpss_clk_data *clk_data;
const char *parent;
if (!lpss_clk_dev)
lpt_register_clock_device();
clk_data = platform_get_drvdata(lpss_clk_dev);
if (!clk_data)
return -ENODEV;
if (dev_desc->clkdev_name) {
clk_register_clkdev(clk_data->clk, dev_desc->clkdev_name,
dev_name(&adev->dev));
return 0;
}
if (!pdata->mmio_base
|| pdata->mmio_size < dev_desc->prv_offset + LPSS_CLK_SIZE)
return -ENODATA;
parent = clk_data->name;
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
clk = clk_register_gate(NULL, dev_name(&adev->dev), parent, 0,
pdata->mmio_base + dev_desc->prv_offset,
0, 0, NULL);
pdata->clk = clk;
}
if (IS_ERR(clk))
return PTR_ERR(clk);
clk_register_clkdev(clk, NULL, dev_name(&adev->dev));
return 0;
}
static int acpi_lpss_create_device(struct acpi_device *adev,
const struct acpi_device_id *id)
{
struct lpss_device_desc *dev_desc;
struct lpss_private_data *pdata;
struct resource_list_entry *rentry;
struct list_head resource_list;
int ret;
dev_desc = (struct lpss_device_desc *)id->driver_data;
if (!dev_desc)
return acpi_create_platform_device(adev, id);
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
pdata->dev_desc = dev_desc;
break;
}
acpi_dev_free_resource_list(&resource_list);
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
ret = acpi_create_platform_device(adev, id);
if (ret > 0)
return ret;
adev->driver_data = NULL;
err_out:
kfree(pdata);
return ret;
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
*val = readl(pdata->mmio_base + pdata->dev_desc->prv_offset + reg);
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
static int acpi_lpss_platform_notify(struct notifier_block *nb,
unsigned long action, void *data)
{
struct platform_device *pdev = to_platform_device(data);
struct lpss_private_data *pdata;
struct acpi_device *adev;
const struct acpi_device_id *id;
int ret = 0;
id = acpi_match_device(acpi_lpss_device_ids, &pdev->dev);
if (!id || !id->driver_data)
return 0;
if (acpi_bus_get_device(ACPI_HANDLE(&pdev->dev), &adev))
return 0;
pdata = acpi_driver_data(adev);
if (!pdata || !pdata->mmio_base || !pdata->dev_desc->ltr_required)
return 0;
if (pdata->mmio_size < pdata->dev_desc->prv_offset + LPSS_LTR_SIZE) {
dev_err(&pdev->dev, "MMIO size insufficient to access LTR\n");
return 0;
}
if (action == BUS_NOTIFY_ADD_DEVICE)
ret = sysfs_create_group(&pdev->dev.kobj, &lpss_attr_group);
else if (action == BUS_NOTIFY_DEL_DEVICE)
sysfs_remove_group(&pdev->dev.kobj, &lpss_attr_group);
return ret;
}
void __init acpi_lpss_init(void)
{
if (!lpt_clk_init()) {
bus_register_notifier(&platform_bus_type, &acpi_lpss_nb);
acpi_scan_add_handler(&lpss_handler);
}
}
