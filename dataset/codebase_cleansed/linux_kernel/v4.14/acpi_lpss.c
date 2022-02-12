static void lpss_uart_setup(struct lpss_private_data *pdata)
{
unsigned int offset;
u32 val;
offset = pdata->dev_desc->prv_offset + LPSS_TX_INT;
val = readl(pdata->mmio_base + offset);
writel(val | LPSS_TX_INT_MASK, pdata->mmio_base + offset);
val = readl(pdata->mmio_base + LPSS_UART_CPR);
if (!(val & LPSS_UART_CPR_AFCE)) {
offset = pdata->dev_desc->prv_offset + LPSS_GENERAL;
val = readl(pdata->mmio_base + offset);
val |= LPSS_GENERAL_UART_RTS_OVRD;
writel(val, pdata->mmio_base + offset);
}
}
static void lpss_deassert_reset(struct lpss_private_data *pdata)
{
unsigned int offset;
u32 val;
offset = pdata->dev_desc->prv_offset + LPSS_RESETS;
val = readl(pdata->mmio_base + offset);
val |= LPSS_RESETS_RESET_APB | LPSS_RESETS_RESET_FUNC;
writel(val, pdata->mmio_base + offset);
}
static void byt_pwm_setup(struct lpss_private_data *pdata)
{
struct acpi_device *adev = pdata->adev;
if (!adev->pnp.unique_id || strcmp(adev->pnp.unique_id, "1"))
return;
if (!acpi_dev_present("INT33FD", NULL, -1))
pwm_add_table(byt_pwm_lookup, ARRAY_SIZE(byt_pwm_lookup));
}
static void byt_i2c_setup(struct lpss_private_data *pdata)
{
lpss_deassert_reset(pdata);
if (readl(pdata->mmio_base + pdata->dev_desc->prv_offset))
pdata->fixed_clk_rate = 133000000;
writel(0, pdata->mmio_base + LPSS_I2C_ENABLE);
}
static void bsw_pwm_setup(struct lpss_private_data *pdata)
{
struct acpi_device *adev = pdata->adev;
if (!adev->pnp.unique_id || strcmp(adev->pnp.unique_id, "1"))
return;
pwm_add_table(bsw_pwm_lookup, ARRAY_SIZE(bsw_pwm_lookup));
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
clk = clk_data->clk;
if (!pdata->mmio_base
|| pdata->mmio_size < dev_desc->prv_offset + LPSS_CLK_SIZE)
return -ENODATA;
parent = clk_data->name;
prv_base = pdata->mmio_base + dev_desc->prv_offset;
if (pdata->fixed_clk_rate) {
clk = clk_register_fixed_rate(NULL, devname, parent, 0,
pdata->fixed_clk_rate);
goto out;
}
if (dev_desc->flags & LPSS_CLK_GATE) {
clk = clk_register_gate(NULL, devname, parent, 0,
prv_base, 0, 0, NULL);
parent = devname;
}
if (dev_desc->flags & LPSS_CLK_DIVIDER) {
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
out:
if (IS_ERR(clk))
return PTR_ERR(clk);
pdata->clk = clk;
clk_register_clkdev(clk, dev_desc->clk_con_id, devname);
return 0;
}
static int acpi_lpss_create_device(struct acpi_device *adev,
const struct acpi_device_id *id)
{
const struct lpss_device_desc *dev_desc;
struct lpss_private_data *pdata;
struct resource_entry *rentry;
struct list_head resource_list;
struct platform_device *pdev;
int ret;
dev_desc = (const struct lpss_device_desc *)id->driver_data;
if (!dev_desc) {
pdev = acpi_create_platform_device(adev, NULL);
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
if (resource_type(rentry->res) == IORESOURCE_MEM) {
if (dev_desc->prv_size_override)
pdata->mmio_size = dev_desc->prv_size_override;
else
pdata->mmio_size = resource_size(rentry->res);
pdata->mmio_base = ioremap(rentry->res->start,
pdata->mmio_size);
break;
}
acpi_dev_free_resource_list(&resource_list);
if (!pdata->mmio_base) {
ret = 0;
goto err_out;
}
pdata->adev = adev;
pdata->dev_desc = dev_desc;
if (dev_desc->setup)
dev_desc->setup(pdata);
if (dev_desc->flags & LPSS_CLK) {
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
adev->driver_data = pdata;
pdev = acpi_create_platform_device(adev, dev_desc->properties);
if (!IS_ERR_OR_NULL(pdev)) {
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
static void acpi_lpss_save_ctx(struct device *dev,
struct lpss_private_data *pdata)
{
unsigned int i;
for (i = 0; i < LPSS_PRV_REG_COUNT; i++) {
unsigned long offset = i * sizeof(u32);
pdata->prv_reg_ctx[i] = __lpss_reg_read(pdata, offset);
dev_dbg(dev, "saving 0x%08x from LPSS reg at offset 0x%02lx\n",
pdata->prv_reg_ctx[i], offset);
}
}
static void acpi_lpss_restore_ctx(struct device *dev,
struct lpss_private_data *pdata)
{
unsigned int i;
for (i = 0; i < LPSS_PRV_REG_COUNT; i++) {
unsigned long offset = i * sizeof(u32);
__lpss_reg_write(pdata->prv_reg_ctx[i], pdata, offset);
dev_dbg(dev, "restoring 0x%08x to LPSS reg at offset 0x%02lx\n",
pdata->prv_reg_ctx[i], offset);
}
}
static void acpi_lpss_d3_to_d0_delay(struct lpss_private_data *pdata)
{
unsigned int delay = 10;
if (pdata->dev_desc->flags & LPSS_NO_D3_DELAY)
delay = 0;
msleep(delay);
}
static int acpi_lpss_activate(struct device *dev)
{
struct lpss_private_data *pdata = acpi_driver_data(ACPI_COMPANION(dev));
int ret;
ret = acpi_dev_runtime_resume(dev);
if (ret)
return ret;
acpi_lpss_d3_to_d0_delay(pdata);
if (pdata->dev_desc->flags & LPSS_SAVE_CTX)
lpss_deassert_reset(pdata);
return 0;
}
static void acpi_lpss_dismiss(struct device *dev)
{
acpi_dev_runtime_suspend(dev);
}
static int acpi_lpss_suspend_late(struct device *dev)
{
struct lpss_private_data *pdata = acpi_driver_data(ACPI_COMPANION(dev));
int ret;
ret = pm_generic_suspend_late(dev);
if (ret)
return ret;
if (pdata->dev_desc->flags & LPSS_SAVE_CTX)
acpi_lpss_save_ctx(dev, pdata);
return acpi_dev_suspend_late(dev);
}
static int acpi_lpss_resume_early(struct device *dev)
{
struct lpss_private_data *pdata = acpi_driver_data(ACPI_COMPANION(dev));
int ret;
ret = acpi_dev_resume_early(dev);
if (ret)
return ret;
acpi_lpss_d3_to_d0_delay(pdata);
if (pdata->dev_desc->flags & LPSS_SAVE_CTX)
acpi_lpss_restore_ctx(dev, pdata);
return pm_generic_resume_early(dev);
}
static void lpss_iosf_enter_d3_state(void)
{
u32 value1 = 0;
u32 mask1 = LPSS_GPIODEF0_DMA_D3_MASK | LPSS_GPIODEF0_DMA_LLP;
u32 value2 = LPSS_PMCSR_D3hot;
u32 mask2 = LPSS_PMCSR_Dx_MASK;
u32 func_dis, d3_sts_0, pmc_status, pmc_mask = 0xfe000ffe;
int ret;
ret = pmc_atom_read(PMC_FUNC_DIS, &func_dis);
if (ret)
return;
mutex_lock(&lpss_iosf_mutex);
ret = pmc_atom_read(PMC_D3_STS_0, &d3_sts_0);
if (ret)
goto exit;
pmc_status = (~(d3_sts_0 | func_dis)) & pmc_mask;
if (pmc_status)
goto exit;
iosf_mbi_modify(LPSS_IOSF_UNIT_LPIO1, MBI_CFG_WRITE,
LPSS_IOSF_PMCSR, value2, mask2);
iosf_mbi_modify(LPSS_IOSF_UNIT_LPIO2, MBI_CFG_WRITE,
LPSS_IOSF_PMCSR, value2, mask2);
iosf_mbi_modify(LPSS_IOSF_UNIT_LPIOEP, MBI_CR_WRITE,
LPSS_IOSF_GPIODEF0, value1, mask1);
exit:
mutex_unlock(&lpss_iosf_mutex);
}
static void lpss_iosf_exit_d3_state(void)
{
u32 value1 = LPSS_GPIODEF0_DMA1_D3 | LPSS_GPIODEF0_DMA2_D3 |
LPSS_GPIODEF0_DMA_LLP;
u32 mask1 = LPSS_GPIODEF0_DMA_D3_MASK | LPSS_GPIODEF0_DMA_LLP;
u32 value2 = LPSS_PMCSR_D0;
u32 mask2 = LPSS_PMCSR_Dx_MASK;
mutex_lock(&lpss_iosf_mutex);
iosf_mbi_modify(LPSS_IOSF_UNIT_LPIOEP, MBI_CR_WRITE,
LPSS_IOSF_GPIODEF0, value1, mask1);
iosf_mbi_modify(LPSS_IOSF_UNIT_LPIO2, MBI_CFG_WRITE,
LPSS_IOSF_PMCSR, value2, mask2);
iosf_mbi_modify(LPSS_IOSF_UNIT_LPIO1, MBI_CFG_WRITE,
LPSS_IOSF_PMCSR, value2, mask2);
mutex_unlock(&lpss_iosf_mutex);
}
static int acpi_lpss_runtime_suspend(struct device *dev)
{
struct lpss_private_data *pdata = acpi_driver_data(ACPI_COMPANION(dev));
int ret;
ret = pm_generic_runtime_suspend(dev);
if (ret)
return ret;
if (pdata->dev_desc->flags & LPSS_SAVE_CTX)
acpi_lpss_save_ctx(dev, pdata);
ret = acpi_dev_runtime_suspend(dev);
if (lpss_quirks & LPSS_QUIRK_ALWAYS_POWER_ON && iosf_mbi_available())
lpss_iosf_enter_d3_state();
return ret;
}
static int acpi_lpss_runtime_resume(struct device *dev)
{
struct lpss_private_data *pdata = acpi_driver_data(ACPI_COMPANION(dev));
int ret;
if (lpss_quirks & LPSS_QUIRK_ALWAYS_POWER_ON && iosf_mbi_available())
lpss_iosf_exit_d3_state();
ret = acpi_dev_runtime_resume(dev);
if (ret)
return ret;
acpi_lpss_d3_to_d0_delay(pdata);
if (pdata->dev_desc->flags & LPSS_SAVE_CTX)
acpi_lpss_restore_ctx(dev, pdata);
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
if (!pdata)
return 0;
if (pdata->mmio_base &&
pdata->mmio_size < pdata->dev_desc->prv_offset + LPSS_LTR_SIZE) {
dev_err(&pdev->dev, "MMIO size insufficient to access LTR\n");
return 0;
}
switch (action) {
case BUS_NOTIFY_BIND_DRIVER:
dev_pm_domain_set(&pdev->dev, &acpi_lpss_pm_domain);
break;
case BUS_NOTIFY_DRIVER_NOT_BOUND:
case BUS_NOTIFY_UNBOUND_DRIVER:
dev_pm_domain_set(&pdev->dev, NULL);
break;
case BUS_NOTIFY_ADD_DEVICE:
dev_pm_domain_set(&pdev->dev, &acpi_lpss_pm_domain);
if (pdata->dev_desc->flags & LPSS_LTR)
return sysfs_create_group(&pdev->dev.kobj,
&lpss_attr_group);
break;
case BUS_NOTIFY_DEL_DEVICE:
if (pdata->dev_desc->flags & LPSS_LTR)
sysfs_remove_group(&pdev->dev.kobj, &lpss_attr_group);
dev_pm_domain_set(&pdev->dev, NULL);
break;
default:
break;
}
return 0;
}
static void acpi_lpss_bind(struct device *dev)
{
struct lpss_private_data *pdata = acpi_driver_data(ACPI_COMPANION(dev));
if (!pdata || !pdata->mmio_base || !(pdata->dev_desc->flags & LPSS_LTR))
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
const struct x86_cpu_id *id;
int ret;
ret = lpt_clk_init();
if (ret)
return;
id = x86_match_cpu(lpss_cpu_ids);
if (id)
lpss_quirks |= LPSS_QUIRK_ALWAYS_POWER_ON;
bus_register_notifier(&platform_bus_type, &acpi_lpss_nb);
acpi_scan_add_handler(&lpss_handler);
}
void __init acpi_lpss_init(void)
{
acpi_scan_add_handler(&lpss_handler);
}
