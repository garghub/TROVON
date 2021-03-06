static int ab8500_prcmu_write(struct ab8500 *ab8500, u16 addr, u8 data)
{
int ret;
ret = prcmu_abb_write((u8)(addr >> 8), (u8)(addr & 0xFF), &data, 1);
if (ret < 0)
dev_err(ab8500->dev, "prcmu i2c error %d\n", ret);
return ret;
}
static int ab8500_prcmu_write_masked(struct ab8500 *ab8500, u16 addr, u8 mask,
u8 data)
{
int ret;
ret = prcmu_abb_write_masked((u8)(addr >> 8), (u8)(addr & 0xFF), &data,
&mask, 1);
if (ret < 0)
dev_err(ab8500->dev, "prcmu i2c error %d\n", ret);
return ret;
}
static int ab8500_prcmu_read(struct ab8500 *ab8500, u16 addr)
{
int ret;
u8 data;
ret = prcmu_abb_read((u8)(addr >> 8), (u8)(addr & 0xFF), &data, 1);
if (ret < 0) {
dev_err(ab8500->dev, "prcmu i2c error %d\n", ret);
return ret;
}
return (int)data;
}
static int ab8500_get_chip_id(struct device *dev)
{
struct ab8500 *ab8500;
if (!dev)
return -EINVAL;
ab8500 = dev_get_drvdata(dev->parent);
return ab8500 ? (int)ab8500->chip_id : -EINVAL;
}
static int set_register_interruptible(struct ab8500 *ab8500, u8 bank,
u8 reg, u8 data)
{
int ret;
u16 addr = ((u16)bank) << 8 | reg;
dev_vdbg(ab8500->dev, "wr: addr %#x <= %#x\n", addr, data);
mutex_lock(&ab8500->lock);
ret = ab8500->write(ab8500, addr, data);
if (ret < 0)
dev_err(ab8500->dev, "failed to write reg %#x: %d\n",
addr, ret);
mutex_unlock(&ab8500->lock);
return ret;
}
static int ab8500_set_register(struct device *dev, u8 bank,
u8 reg, u8 value)
{
int ret;
struct ab8500 *ab8500 = dev_get_drvdata(dev->parent);
atomic_inc(&ab8500->transfer_ongoing);
ret = set_register_interruptible(ab8500, bank, reg, value);
atomic_dec(&ab8500->transfer_ongoing);
return ret;
}
static int get_register_interruptible(struct ab8500 *ab8500, u8 bank,
u8 reg, u8 *value)
{
int ret;
u16 addr = ((u16)bank) << 8 | reg;
mutex_lock(&ab8500->lock);
ret = ab8500->read(ab8500, addr);
if (ret < 0)
dev_err(ab8500->dev, "failed to read reg %#x: %d\n",
addr, ret);
else
*value = ret;
mutex_unlock(&ab8500->lock);
dev_vdbg(ab8500->dev, "rd: addr %#x => data %#x\n", addr, ret);
return ret;
}
static int ab8500_get_register(struct device *dev, u8 bank,
u8 reg, u8 *value)
{
int ret;
struct ab8500 *ab8500 = dev_get_drvdata(dev->parent);
atomic_inc(&ab8500->transfer_ongoing);
ret = get_register_interruptible(ab8500, bank, reg, value);
atomic_dec(&ab8500->transfer_ongoing);
return ret;
}
static int mask_and_set_register_interruptible(struct ab8500 *ab8500, u8 bank,
u8 reg, u8 bitmask, u8 bitvalues)
{
int ret;
u16 addr = ((u16)bank) << 8 | reg;
mutex_lock(&ab8500->lock);
if (ab8500->write_masked == NULL) {
u8 data;
ret = ab8500->read(ab8500, addr);
if (ret < 0) {
dev_err(ab8500->dev, "failed to read reg %#x: %d\n",
addr, ret);
goto out;
}
data = (u8)ret;
data = (~bitmask & data) | (bitmask & bitvalues);
ret = ab8500->write(ab8500, addr, data);
if (ret < 0)
dev_err(ab8500->dev, "failed to write reg %#x: %d\n",
addr, ret);
dev_vdbg(ab8500->dev, "mask: addr %#x => data %#x\n", addr,
data);
goto out;
}
ret = ab8500->write_masked(ab8500, addr, bitmask, bitvalues);
if (ret < 0)
dev_err(ab8500->dev, "failed to modify reg %#x: %d\n", addr,
ret);
out:
mutex_unlock(&ab8500->lock);
return ret;
}
static int ab8500_mask_and_set_register(struct device *dev,
u8 bank, u8 reg, u8 bitmask, u8 bitvalues)
{
int ret;
struct ab8500 *ab8500 = dev_get_drvdata(dev->parent);
atomic_inc(&ab8500->transfer_ongoing);
ret= mask_and_set_register_interruptible(ab8500, bank, reg,
bitmask, bitvalues);
atomic_dec(&ab8500->transfer_ongoing);
return ret;
}
static void ab8500_irq_lock(struct irq_data *data)
{
struct ab8500 *ab8500 = irq_data_get_irq_chip_data(data);
mutex_lock(&ab8500->irq_lock);
atomic_inc(&ab8500->transfer_ongoing);
}
static void ab8500_irq_sync_unlock(struct irq_data *data)
{
struct ab8500 *ab8500 = irq_data_get_irq_chip_data(data);
int i;
for (i = 0; i < ab8500->mask_size; i++) {
u8 old = ab8500->oldmask[i];
u8 new = ab8500->mask[i];
int reg;
if (new == old)
continue;
if (ab8500->irq_reg_offset[i] == 11 &&
is_ab8500_1p1_or_earlier(ab8500))
continue;
ab8500->oldmask[i] = new;
reg = AB8500_IT_MASK1_REG + ab8500->irq_reg_offset[i];
set_register_interruptible(ab8500, AB8500_INTERRUPT, reg, new);
}
atomic_dec(&ab8500->transfer_ongoing);
mutex_unlock(&ab8500->irq_lock);
}
static void ab8500_irq_mask(struct irq_data *data)
{
struct ab8500 *ab8500 = irq_data_get_irq_chip_data(data);
int offset = data->hwirq;
int index = offset / 8;
int mask = 1 << (offset % 8);
ab8500->mask[index] |= mask;
if (offset >= AB8500_INT_GPIO6R && offset <= AB8500_INT_GPIO41R)
ab8500->mask[index + 2] |= mask;
if (offset >= AB9540_INT_GPIO50R && offset <= AB9540_INT_GPIO54R)
ab8500->mask[index + 1] |= mask;
if (offset == AB8540_INT_GPIO43R || offset == AB8540_INT_GPIO44R)
ab8500->mask[index] |= (mask << 1);
}
static void ab8500_irq_unmask(struct irq_data *data)
{
struct ab8500 *ab8500 = irq_data_get_irq_chip_data(data);
unsigned int type = irqd_get_trigger_type(data);
int offset = data->hwirq;
int index = offset / 8;
int mask = 1 << (offset % 8);
if (type & IRQ_TYPE_EDGE_RISING)
ab8500->mask[index] &= ~mask;
if (type & IRQ_TYPE_EDGE_FALLING) {
if (offset >= AB8500_INT_GPIO6R && offset <= AB8500_INT_GPIO41R)
ab8500->mask[index + 2] &= ~mask;
else if (offset >= AB9540_INT_GPIO50R && offset <= AB9540_INT_GPIO54R)
ab8500->mask[index + 1] &= ~mask;
else if (offset == AB8540_INT_GPIO43R || offset == AB8540_INT_GPIO44R)
ab8500->mask[index] &= ~(mask << 1);
else
ab8500->mask[index] &= ~mask;
} else {
ab8500->mask[index] &= ~mask;
}
}
static int ab8500_irq_set_type(struct irq_data *data, unsigned int type)
{
return 0;
}
static int ab8500_handle_hierarchical_line(struct ab8500 *ab8500,
int latch_offset, u8 latch_val)
{
int int_bit = __ffs(latch_val);
int line, i;
do {
int_bit = __ffs(latch_val);
for (i = 0; i < ab8500->mask_size; i++)
if (ab8500->irq_reg_offset[i] == latch_offset)
break;
if (i >= ab8500->mask_size) {
dev_err(ab8500->dev, "Register offset 0x%2x not declared\n",
latch_offset);
return -ENXIO;
}
line = (i << 3) + int_bit;
latch_val &= ~(1 << int_bit);
if (line >= AB8500_INT_GPIO6F && line <= AB8500_INT_GPIO41F)
line -= 16;
if (line >= AB9540_INT_GPIO50F && line <= AB9540_INT_GPIO54F)
line -= 8;
if (line == AB8540_INT_GPIO43F || line == AB8540_INT_GPIO44F)
line += 1;
handle_nested_irq(ab8500->irq_base + line);
} while (latch_val);
return 0;
}
static int ab8500_handle_hierarchical_latch(struct ab8500 *ab8500,
int hier_offset, u8 hier_val)
{
int latch_bit, status;
u8 latch_offset, latch_val;
do {
latch_bit = __ffs(hier_val);
latch_offset = (hier_offset << 3) + latch_bit;
if (unlikely(latch_offset == 17))
latch_offset = 24;
status = get_register_interruptible(ab8500,
AB8500_INTERRUPT,
AB8500_IT_LATCH1_REG + latch_offset,
&latch_val);
if (status < 0 || latch_val == 0)
goto discard;
status = ab8500_handle_hierarchical_line(ab8500,
latch_offset, latch_val);
if (status < 0)
return status;
discard:
hier_val &= ~(1 << latch_bit);
} while (hier_val);
return 0;
}
static irqreturn_t ab8500_hierarchical_irq(int irq, void *dev)
{
struct ab8500 *ab8500 = dev;
u8 i;
dev_vdbg(ab8500->dev, "interrupt\n");
for (i = 0; i < AB8500_IT_LATCHHIER_NUM; i++) {
int status;
u8 hier_val;
status = get_register_interruptible(ab8500, AB8500_INTERRUPT,
AB8500_IT_LATCHHIER1_REG + i, &hier_val);
if (status < 0 || hier_val == 0)
continue;
status = ab8500_handle_hierarchical_latch(ab8500, i, hier_val);
if (status < 0)
break;
}
return IRQ_HANDLED;
}
static int ab8500_irq_get_virq(struct ab8500 *ab8500, int irq)
{
if (!ab8500)
return -EINVAL;
return irq_create_mapping(ab8500->domain, irq);
}
static irqreturn_t ab8500_irq(int irq, void *dev)
{
struct ab8500 *ab8500 = dev;
int i;
dev_vdbg(ab8500->dev, "interrupt\n");
atomic_inc(&ab8500->transfer_ongoing);
for (i = 0; i < ab8500->mask_size; i++) {
int regoffset = ab8500->irq_reg_offset[i];
int status;
u8 value;
if (regoffset == 11 && is_ab8500_1p1_or_earlier(ab8500))
continue;
status = get_register_interruptible(ab8500, AB8500_INTERRUPT,
AB8500_IT_LATCH1_REG + regoffset, &value);
if (status < 0 || value == 0)
continue;
do {
int bit = __ffs(value);
int line = i * 8 + bit;
int virq = ab8500_irq_get_virq(ab8500, line);
handle_nested_irq(virq);
ab8500_debug_register_interrupt(line);
value &= ~(1 << bit);
} while (value);
}
atomic_dec(&ab8500->transfer_ongoing);
return IRQ_HANDLED;
}
static int ab8500_irq_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hwirq)
{
struct ab8500 *ab8500 = d->host_data;
if (!ab8500)
return -EINVAL;
irq_set_chip_data(virq, ab8500);
irq_set_chip_and_handler(virq, &ab8500_irq_chip,
handle_simple_irq);
irq_set_nested_thread(virq, 1);
#ifdef CONFIG_ARM
set_irq_flags(virq, IRQF_VALID);
#else
irq_set_noprobe(virq);
#endif
return 0;
}
static int ab8500_irq_init(struct ab8500 *ab8500, struct device_node *np)
{
int num_irqs;
if (is_ab9540(ab8500))
num_irqs = AB9540_NR_IRQS;
else if (is_ab8505(ab8500))
num_irqs = AB8505_NR_IRQS;
else
num_irqs = AB8500_NR_IRQS;
ab8500->domain = irq_domain_add_simple(NULL,
num_irqs, ab8500->irq_base,
&ab8500_irq_ops, ab8500);
if (!ab8500->domain) {
dev_err(ab8500->dev, "Failed to create irqdomain\n");
return -ENOSYS;
}
return 0;
}
int ab8500_suspend(struct ab8500 *ab8500)
{
if (atomic_read(&ab8500->transfer_ongoing))
return -EINVAL;
else
return 0;
}
static ssize_t show_chip_id(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ab8500 *ab8500;
ab8500 = dev_get_drvdata(dev);
return sprintf(buf, "%#x\n", ab8500 ? ab8500->chip_id : -EINVAL);
}
static ssize_t show_switch_off_status(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ret;
u8 value;
struct ab8500 *ab8500;
ab8500 = dev_get_drvdata(dev);
ret = get_register_interruptible(ab8500, AB8500_RTC,
AB8500_SWITCH_OFF_STATUS, &value);
if (ret < 0)
return ret;
return sprintf(buf, "%#x\n", value);
}
static ssize_t show_turn_on_status(struct device *dev,
struct device_attribute *attr, char *buf)
{
int ret;
u8 value;
struct ab8500 *ab8500;
ab8500 = dev_get_drvdata(dev);
ret = get_register_interruptible(ab8500, AB8500_SYS_CTRL1_BLOCK,
AB8500_TURN_ON_STATUS, &value);
if (ret < 0)
return ret;
return sprintf(buf, "%#x\n", value);
}
static ssize_t show_ab9540_dbbrstn(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ab8500 *ab8500;
int ret;
u8 value;
ab8500 = dev_get_drvdata(dev);
ret = get_register_interruptible(ab8500, AB8500_REGU_CTRL2,
AB9540_MODEM_CTRL2_REG, &value);
if (ret < 0)
return ret;
return sprintf(buf, "%d\n",
(value & AB9540_MODEM_CTRL2_SWDBBRSTN_BIT) ? 1 : 0);
}
static ssize_t store_ab9540_dbbrstn(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct ab8500 *ab8500;
int ret = count;
int err;
u8 bitvalues;
ab8500 = dev_get_drvdata(dev);
if (count > 0) {
switch (buf[0]) {
case '0':
bitvalues = 0;
break;
case '1':
bitvalues = AB9540_MODEM_CTRL2_SWDBBRSTN_BIT;
break;
default:
goto exit;
}
err = mask_and_set_register_interruptible(ab8500,
AB8500_REGU_CTRL2, AB9540_MODEM_CTRL2_REG,
AB9540_MODEM_CTRL2_SWDBBRSTN_BIT, bitvalues);
if (err)
dev_info(ab8500->dev,
"Failed to set DBBRSTN %c, err %#x\n",
buf[0], err);
}
exit:
return ret;
}
static int ab8500_probe(struct platform_device *pdev)
{
static char *switch_off_status[] = {
"Swoff bit programming",
"Thermal protection activation",
"Vbat lower then BattOk falling threshold",
"Watchdog expired",
"Non presence of 32kHz clock",
"Battery level lower than power on reset threshold",
"Power on key 1 pressed longer than 10 seconds",
"DB8500 thermal shutdown"};
struct ab8500_platform_data *plat = dev_get_platdata(&pdev->dev);
const struct platform_device_id *platid = platform_get_device_id(pdev);
enum ab8500_version version = AB8500_VERSION_UNDEFINED;
struct device_node *np = pdev->dev.of_node;
struct ab8500 *ab8500;
struct resource *resource;
int ret;
int i;
u8 value;
ab8500 = devm_kzalloc(&pdev->dev, sizeof *ab8500, GFP_KERNEL);
if (!ab8500)
return -ENOMEM;
if (plat)
ab8500->irq_base = plat->irq_base;
ab8500->dev = &pdev->dev;
resource = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!resource)
return -ENODEV;
ab8500->irq = resource->start;
ab8500->read = ab8500_prcmu_read;
ab8500->write = ab8500_prcmu_write;
ab8500->write_masked = ab8500_prcmu_write_masked;
mutex_init(&ab8500->lock);
mutex_init(&ab8500->irq_lock);
atomic_set(&ab8500->transfer_ongoing, 0);
platform_set_drvdata(pdev, ab8500);
if (platid)
version = platid->driver_data;
if (version != AB8500_VERSION_UNDEFINED)
ab8500->version = version;
else {
ret = get_register_interruptible(ab8500, AB8500_MISC,
AB8500_IC_NAME_REG, &value);
if (ret < 0)
return ret;
ab8500->version = value;
}
ret = get_register_interruptible(ab8500, AB8500_MISC,
AB8500_REV_REG, &value);
if (ret < 0)
return ret;
ab8500->chip_id = value;
dev_info(ab8500->dev, "detected chip, %s rev. %1x.%1x\n",
ab8500_version_str[ab8500->version],
ab8500->chip_id >> 4,
ab8500->chip_id & 0x0F);
if (is_ab9540(ab8500) || is_ab8505(ab8500)) {
ab8500->mask_size = AB9540_NUM_IRQ_REGS;
ab8500->irq_reg_offset = ab9540_irq_regoffset;
} else {
ab8500->mask_size = AB8500_NUM_IRQ_REGS;
ab8500->irq_reg_offset = ab8500_irq_regoffset;
}
ab8500->mask = devm_kzalloc(&pdev->dev, ab8500->mask_size, GFP_KERNEL);
if (!ab8500->mask)
return -ENOMEM;
ab8500->oldmask = devm_kzalloc(&pdev->dev, ab8500->mask_size, GFP_KERNEL);
if (!ab8500->oldmask)
return -ENOMEM;
ret = get_register_interruptible(ab8500, AB8500_RTC,
AB8500_SWITCH_OFF_STATUS, &value);
if (ret < 0)
return ret;
dev_info(ab8500->dev, "switch off cause(s) (%#x): ", value);
if (value) {
for (i = 0; i < ARRAY_SIZE(switch_off_status); i++) {
if (value & 1)
printk(KERN_CONT " \"%s\"",
switch_off_status[i]);
value = value >> 1;
}
printk(KERN_CONT "\n");
} else {
printk(KERN_CONT " None\n");
}
if (plat && plat->init)
plat->init(ab8500);
for (i = 0; i < ab8500->mask_size; i++) {
if (ab8500->irq_reg_offset[i] == 11 &&
is_ab8500_1p1_or_earlier(ab8500))
continue;
get_register_interruptible(ab8500, AB8500_INTERRUPT,
AB8500_IT_LATCH1_REG + ab8500->irq_reg_offset[i],
&value);
set_register_interruptible(ab8500, AB8500_INTERRUPT,
AB8500_IT_MASK1_REG + ab8500->irq_reg_offset[i], 0xff);
}
ret = abx500_register_ops(ab8500->dev, &ab8500_ops);
if (ret)
return ret;
for (i = 0; i < ab8500->mask_size; i++)
ab8500->mask[i] = ab8500->oldmask[i] = 0xff;
ret = ab8500_irq_init(ab8500, np);
if (ret)
return ret;
if (is_ab9540(ab8500)) {
ret = devm_request_threaded_irq(&pdev->dev, ab8500->irq, NULL,
ab8500_hierarchical_irq,
IRQF_ONESHOT | IRQF_NO_SUSPEND,
"ab8500", ab8500);
}
else {
ret = devm_request_threaded_irq(&pdev->dev, ab8500->irq, NULL,
ab8500_irq,
IRQF_ONESHOT | IRQF_NO_SUSPEND,
"ab8500", ab8500);
if (ret)
return ret;
}
ret = mfd_add_devices(ab8500->dev, 0, abx500_common_devs,
ARRAY_SIZE(abx500_common_devs), NULL,
ab8500->irq_base, ab8500->domain);
if (ret)
return ret;
if (is_ab9540(ab8500))
ret = mfd_add_devices(ab8500->dev, 0, ab9540_devs,
ARRAY_SIZE(ab9540_devs), NULL,
ab8500->irq_base, ab8500->domain);
else
ret = mfd_add_devices(ab8500->dev, 0, ab8500_devs,
ARRAY_SIZE(ab8500_devs), NULL,
ab8500->irq_base, ab8500->domain);
if (ret)
return ret;
if (is_ab9540(ab8500) || is_ab8505(ab8500))
ret = mfd_add_devices(ab8500->dev, 0, ab9540_ab8505_devs,
ARRAY_SIZE(ab9540_ab8505_devs), NULL,
ab8500->irq_base, ab8500->domain);
if (ret)
return ret;
if (!no_bm) {
ret = mfd_add_devices(ab8500->dev, 0, ab8500_bm_devs,
ARRAY_SIZE(ab8500_bm_devs), NULL,
ab8500->irq_base, ab8500->domain);
if (ret)
dev_err(ab8500->dev, "error adding bm devices\n");
}
if (is_ab9540(ab8500))
ret = sysfs_create_group(&ab8500->dev->kobj,
&ab9540_attr_group);
else
ret = sysfs_create_group(&ab8500->dev->kobj,
&ab8500_attr_group);
if (ret)
dev_err(ab8500->dev, "error creating sysfs entries\n");
return ret;
}
static int ab8500_remove(struct platform_device *pdev)
{
struct ab8500 *ab8500 = platform_get_drvdata(pdev);
if (is_ab9540(ab8500))
sysfs_remove_group(&ab8500->dev->kobj, &ab9540_attr_group);
else
sysfs_remove_group(&ab8500->dev->kobj, &ab8500_attr_group);
mfd_remove_devices(ab8500->dev);
return 0;
}
static int __init ab8500_core_init(void)
{
return platform_driver_register(&ab8500_core_driver);
}
static void __exit ab8500_core_exit(void)
{
platform_driver_unregister(&ab8500_core_driver);
}
