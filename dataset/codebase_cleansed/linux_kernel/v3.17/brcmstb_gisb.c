static ssize_t gisb_arb_get_timeout(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct brcmstb_gisb_arb_device *gdev = platform_get_drvdata(pdev);
u32 timeout;
mutex_lock(&gdev->lock);
timeout = ioread32(gdev->base + ARB_TIMER);
mutex_unlock(&gdev->lock);
return sprintf(buf, "%d", timeout);
}
static ssize_t gisb_arb_set_timeout(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct platform_device *pdev = to_platform_device(dev);
struct brcmstb_gisb_arb_device *gdev = platform_get_drvdata(pdev);
int val, ret;
ret = kstrtoint(buf, 10, &val);
if (ret < 0)
return ret;
if (val == 0 || val >= 0xffffffff)
return -EINVAL;
mutex_lock(&gdev->lock);
iowrite32(val, gdev->base + ARB_TIMER);
mutex_unlock(&gdev->lock);
return count;
}
static const char *
brcmstb_gisb_master_to_str(struct brcmstb_gisb_arb_device *gdev,
u32 masters)
{
u32 mask = gdev->valid_mask & masters;
if (hweight_long(mask) != 1)
return NULL;
return gdev->master_names[ffs(mask) - 1];
}
static int brcmstb_gisb_arb_decode_addr(struct brcmstb_gisb_arb_device *gdev,
const char *reason)
{
u32 cap_status;
unsigned long arb_addr;
u32 master;
const char *m_name;
char m_fmt[11];
cap_status = ioread32(gdev->base + ARB_ERR_CAP_STATUS);
if (!(cap_status & ARB_ERR_CAP_STATUS_VALID))
return 1;
arb_addr = ioread32(gdev->base + ARB_ERR_CAP_ADDR) & 0xffffffff;
#if (IS_ENABLED(CONFIG_PHYS_ADDR_T_64BIT))
arb_addr |= (u64)ioread32(gdev->base + ARB_ERR_CAP_HI_ADDR) << 32;
#endif
master = ioread32(gdev->base + ARB_ERR_CAP_MASTER);
m_name = brcmstb_gisb_master_to_str(gdev, master);
if (!m_name) {
snprintf(m_fmt, sizeof(m_fmt), "0x%08x", master);
m_name = m_fmt;
}
pr_crit("%s: %s at 0x%lx [%c %s], core: %s\n",
__func__, reason, arb_addr,
cap_status & ARB_ERR_CAP_STATUS_WRITE ? 'W' : 'R',
cap_status & ARB_ERR_CAP_STATUS_TIMEOUT ? "timeout" : "",
m_name);
iowrite32(ARB_ERR_CAP_CLEAR, gdev->base + ARB_ERR_CAP_CLR);
return 0;
}
static int brcmstb_bus_error_handler(unsigned long addr, unsigned int fsr,
struct pt_regs *regs)
{
int ret = 0;
struct brcmstb_gisb_arb_device *gdev;
list_for_each_entry(gdev, &brcmstb_gisb_arb_device_list, next)
ret |= brcmstb_gisb_arb_decode_addr(gdev, "bus error");
if (fsr & (1 << 10))
regs->ARM_pc += 4;
return ret;
}
void __init brcmstb_hook_fault_code(void)
{
hook_fault_code(22, brcmstb_bus_error_handler, SIGBUS, 0,
"imprecise external abort");
}
static irqreturn_t brcmstb_gisb_timeout_handler(int irq, void *dev_id)
{
brcmstb_gisb_arb_decode_addr(dev_id, "timeout");
return IRQ_HANDLED;
}
static irqreturn_t brcmstb_gisb_tea_handler(int irq, void *dev_id)
{
brcmstb_gisb_arb_decode_addr(dev_id, "target abort");
return IRQ_HANDLED;
}
static int brcmstb_gisb_arb_probe(struct platform_device *pdev)
{
struct device_node *dn = pdev->dev.of_node;
struct brcmstb_gisb_arb_device *gdev;
struct resource *r;
int err, timeout_irq, tea_irq;
unsigned int num_masters, j = 0;
int i, first, last;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
timeout_irq = platform_get_irq(pdev, 0);
tea_irq = platform_get_irq(pdev, 1);
gdev = devm_kzalloc(&pdev->dev, sizeof(*gdev), GFP_KERNEL);
if (!gdev)
return -ENOMEM;
mutex_init(&gdev->lock);
INIT_LIST_HEAD(&gdev->next);
gdev->base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(gdev->base))
return PTR_ERR(gdev->base);
err = devm_request_irq(&pdev->dev, timeout_irq,
brcmstb_gisb_timeout_handler, 0, pdev->name,
gdev);
if (err < 0)
return err;
err = devm_request_irq(&pdev->dev, tea_irq,
brcmstb_gisb_tea_handler, 0, pdev->name,
gdev);
if (err < 0)
return err;
if (of_property_read_u32(dn, "brcm,gisb-arb-master-mask",
&gdev->valid_mask))
gdev->valid_mask = 0xffffffff;
num_masters = of_property_count_strings(dn,
"brcm,gisb-arb-master-names");
if (hweight_long(gdev->valid_mask) == num_masters) {
first = ffs(gdev->valid_mask) - 1;
last = fls(gdev->valid_mask) - 1;
for (i = first; i < last; i++) {
if (!(gdev->valid_mask & BIT(i)))
continue;
of_property_read_string_index(dn,
"brcm,gisb-arb-master-names", j,
&gdev->master_names[i]);
j++;
}
}
err = sysfs_create_group(&pdev->dev.kobj, &gisb_arb_sysfs_attr_group);
if (err)
return err;
platform_set_drvdata(pdev, gdev);
list_add_tail(&gdev->next, &brcmstb_gisb_arb_device_list);
dev_info(&pdev->dev, "registered mem: %p, irqs: %d, %d\n",
gdev->base, timeout_irq, tea_irq);
return 0;
}
static int __init brcm_gisb_driver_init(void)
{
return platform_driver_register(&brcmstb_gisb_arb_driver);
}
