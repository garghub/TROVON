static u32 gisb_read(struct brcmstb_gisb_arb_device *gdev, int reg)
{
int offset = gdev->gisb_offsets[reg];
if (offset < 0) {
if (reg == ARB_ERR_CAP_MASTER)
return 1;
else
return 0;
}
if (gdev->big_endian)
return ioread32be(gdev->base + offset);
else
return ioread32(gdev->base + offset);
}
static u64 gisb_read_address(struct brcmstb_gisb_arb_device *gdev)
{
u64 value;
value = gisb_read(gdev, ARB_ERR_CAP_ADDR);
value |= (u64)gisb_read(gdev, ARB_ERR_CAP_HI_ADDR) << 32;
return value;
}
static void gisb_write(struct brcmstb_gisb_arb_device *gdev, u32 val, int reg)
{
int offset = gdev->gisb_offsets[reg];
if (offset == -1)
return;
if (gdev->big_endian)
iowrite32be(val, gdev->base + offset);
else
iowrite32(val, gdev->base + offset);
}
static ssize_t gisb_arb_get_timeout(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct platform_device *pdev = to_platform_device(dev);
struct brcmstb_gisb_arb_device *gdev = platform_get_drvdata(pdev);
u32 timeout;
mutex_lock(&gdev->lock);
timeout = gisb_read(gdev, ARB_TIMER);
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
gisb_write(gdev, val, ARB_TIMER);
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
u64 arb_addr;
u32 master;
const char *m_name;
char m_fmt[11];
cap_status = gisb_read(gdev, ARB_ERR_CAP_STATUS);
if (!(cap_status & ARB_ERR_CAP_STATUS_VALID))
return 1;
arb_addr = gisb_read_address(gdev);
master = gisb_read(gdev, ARB_ERR_CAP_MASTER);
m_name = brcmstb_gisb_master_to_str(gdev, master);
if (!m_name) {
snprintf(m_fmt, sizeof(m_fmt), "0x%08x", master);
m_name = m_fmt;
}
pr_crit("%s: %s at 0x%llx [%c %s], core: %s\n",
__func__, reason, arb_addr,
cap_status & ARB_ERR_CAP_STATUS_WRITE ? 'W' : 'R',
cap_status & ARB_ERR_CAP_STATUS_TIMEOUT ? "timeout" : "",
m_name);
gisb_write(gdev, ARB_ERR_CAP_CLEAR, ARB_ERR_CAP_CLR);
return 0;
}
static int brcmstb_bus_error_handler(struct pt_regs *regs, int is_fixup)
{
int ret = 0;
struct brcmstb_gisb_arb_device *gdev;
u32 cap_status;
list_for_each_entry(gdev, &brcmstb_gisb_arb_device_list, next) {
cap_status = gisb_read(gdev, ARB_ERR_CAP_STATUS);
if (!(cap_status & ARB_ERR_CAP_STATUS_VALID)) {
is_fixup = 1;
goto out;
}
ret |= brcmstb_gisb_arb_decode_addr(gdev, "bus error");
}
out:
return is_fixup ? MIPS_BE_FIXUP : MIPS_BE_FATAL;
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
static int dump_gisb_error(struct notifier_block *self, unsigned long v,
void *p)
{
struct brcmstb_gisb_arb_device *gdev;
const char *reason = "panic";
if (self == &gisb_die_notifier)
reason = "die";
list_for_each_entry(gdev, &brcmstb_gisb_arb_device_list, next)
brcmstb_gisb_arb_decode_addr(gdev, reason);
return NOTIFY_DONE;
}
static int __init brcmstb_gisb_arb_probe(struct platform_device *pdev)
{
struct device_node *dn = pdev->dev.of_node;
struct brcmstb_gisb_arb_device *gdev;
const struct of_device_id *of_id;
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
of_id = of_match_node(brcmstb_gisb_arb_of_match, dn);
if (!of_id) {
pr_err("failed to look up compatible string\n");
return -EINVAL;
}
gdev->gisb_offsets = of_id->data;
gdev->big_endian = of_device_is_big_endian(dn);
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
#ifdef CONFIG_MIPS
board_be_handler = brcmstb_bus_error_handler;
#endif
if (list_is_singular(&brcmstb_gisb_arb_device_list)) {
register_die_notifier(&gisb_die_notifier);
atomic_notifier_chain_register(&panic_notifier_list,
&gisb_panic_notifier);
}
dev_info(&pdev->dev, "registered mem: %p, irqs: %d, %d\n",
gdev->base, timeout_irq, tea_irq);
return 0;
}
static int brcmstb_gisb_arb_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct brcmstb_gisb_arb_device *gdev = platform_get_drvdata(pdev);
gdev->saved_timeout = gisb_read(gdev, ARB_TIMER);
return 0;
}
static int brcmstb_gisb_arb_resume_noirq(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct brcmstb_gisb_arb_device *gdev = platform_get_drvdata(pdev);
gisb_write(gdev, gdev->saved_timeout, ARB_TIMER);
return 0;
}
static int __init brcm_gisb_driver_init(void)
{
return platform_driver_probe(&brcmstb_gisb_arb_driver,
brcmstb_gisb_arb_probe);
}
