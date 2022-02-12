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
ret = mutex_lock_interruptible(&ab8500->lock);
if (ret)
return ret;
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
struct ab8500 *ab8500 = dev_get_drvdata(dev->parent);
return set_register_interruptible(ab8500, bank, reg, value);
}
static int get_register_interruptible(struct ab8500 *ab8500, u8 bank,
u8 reg, u8 *value)
{
int ret;
u16 addr = ((u16)bank) << 8 | reg;
ret = mutex_lock_interruptible(&ab8500->lock);
if (ret)
return ret;
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
struct ab8500 *ab8500 = dev_get_drvdata(dev->parent);
return get_register_interruptible(ab8500, bank, reg, value);
}
static int mask_and_set_register_interruptible(struct ab8500 *ab8500, u8 bank,
u8 reg, u8 bitmask, u8 bitvalues)
{
int ret;
u8 data;
u16 addr = ((u16)bank) << 8 | reg;
ret = mutex_lock_interruptible(&ab8500->lock);
if (ret)
return ret;
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
dev_vdbg(ab8500->dev, "mask: addr %#x => data %#x\n", addr, data);
out:
mutex_unlock(&ab8500->lock);
return ret;
}
static int ab8500_mask_and_set_register(struct device *dev,
u8 bank, u8 reg, u8 bitmask, u8 bitvalues)
{
struct ab8500 *ab8500 = dev_get_drvdata(dev->parent);
return mask_and_set_register_interruptible(ab8500, bank, reg,
bitmask, bitvalues);
}
static void ab8500_irq_lock(struct irq_data *data)
{
struct ab8500 *ab8500 = irq_data_get_irq_chip_data(data);
mutex_lock(&ab8500->irq_lock);
}
static void ab8500_irq_sync_unlock(struct irq_data *data)
{
struct ab8500 *ab8500 = irq_data_get_irq_chip_data(data);
int i;
for (i = 0; i < AB8500_NUM_IRQ_REGS; i++) {
u8 old = ab8500->oldmask[i];
u8 new = ab8500->mask[i];
int reg;
if (new == old)
continue;
if (ab8500_irq_regoffset[i] == 11 &&
ab8500->chip_id < AB8500_CUT2P0)
continue;
ab8500->oldmask[i] = new;
reg = AB8500_IT_MASK1_REG + ab8500_irq_regoffset[i];
set_register_interruptible(ab8500, AB8500_INTERRUPT, reg, new);
}
mutex_unlock(&ab8500->irq_lock);
}
static void ab8500_irq_mask(struct irq_data *data)
{
struct ab8500 *ab8500 = irq_data_get_irq_chip_data(data);
int offset = data->irq - ab8500->irq_base;
int index = offset / 8;
int mask = 1 << (offset % 8);
ab8500->mask[index] |= mask;
}
static void ab8500_irq_unmask(struct irq_data *data)
{
struct ab8500 *ab8500 = irq_data_get_irq_chip_data(data);
int offset = data->irq - ab8500->irq_base;
int index = offset / 8;
int mask = 1 << (offset % 8);
ab8500->mask[index] &= ~mask;
}
static irqreturn_t ab8500_irq(int irq, void *dev)
{
struct ab8500 *ab8500 = dev;
int i;
dev_vdbg(ab8500->dev, "interrupt\n");
for (i = 0; i < AB8500_NUM_IRQ_REGS; i++) {
int regoffset = ab8500_irq_regoffset[i];
int status;
u8 value;
if (regoffset == 11 && ab8500->chip_id < AB8500_CUT2P0)
continue;
status = get_register_interruptible(ab8500, AB8500_INTERRUPT,
AB8500_IT_LATCH1_REG + regoffset, &value);
if (status < 0 || value == 0)
continue;
do {
int bit = __ffs(value);
int line = i * 8 + bit;
handle_nested_irq(ab8500->irq_base + line);
value &= ~(1 << bit);
} while (value);
}
return IRQ_HANDLED;
}
static int ab8500_irq_init(struct ab8500 *ab8500)
{
int base = ab8500->irq_base;
int irq;
for (irq = base; irq < base + AB8500_NR_IRQS; irq++) {
irq_set_chip_data(irq, ab8500);
irq_set_chip_and_handler(irq, &ab8500_irq_chip,
handle_simple_irq);
irq_set_nested_thread(irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(irq, IRQF_VALID);
#else
irq_set_noprobe(irq);
#endif
}
return 0;
}
static void ab8500_irq_remove(struct ab8500 *ab8500)
{
int base = ab8500->irq_base;
int irq;
for (irq = base; irq < base + AB8500_NR_IRQS; irq++) {
#ifdef CONFIG_ARM
set_irq_flags(irq, 0);
#endif
irq_set_chip_and_handler(irq, NULL, NULL);
irq_set_chip_data(irq, NULL);
}
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
int __devinit ab8500_init(struct ab8500 *ab8500)
{
struct ab8500_platform_data *plat = dev_get_platdata(ab8500->dev);
int ret;
int i;
u8 value;
if (plat)
ab8500->irq_base = plat->irq_base;
mutex_init(&ab8500->lock);
mutex_init(&ab8500->irq_lock);
ret = get_register_interruptible(ab8500, AB8500_MISC,
AB8500_REV_REG, &value);
if (ret < 0)
return ret;
switch (value) {
case AB8500_CUTEARLY:
case AB8500_CUT1P0:
case AB8500_CUT1P1:
case AB8500_CUT2P0:
case AB8500_CUT3P0:
dev_info(ab8500->dev, "detected chip, revision: %#x\n", value);
break;
default:
dev_err(ab8500->dev, "unknown chip, revision: %#x\n", value);
return -EINVAL;
}
ab8500->chip_id = value;
ret = get_register_interruptible(ab8500, AB8500_RTC,
AB8500_SWITCH_OFF_STATUS, &value);
if (ret < 0)
return ret;
dev_info(ab8500->dev, "switch off status: %#x", value);
if (plat && plat->init)
plat->init(ab8500);
for (i = 0; i < AB8500_NUM_IRQ_REGS; i++) {
if (ab8500_irq_regoffset[i] == 11 &&
ab8500->chip_id < AB8500_CUT2P0)
continue;
get_register_interruptible(ab8500, AB8500_INTERRUPT,
AB8500_IT_LATCH1_REG + ab8500_irq_regoffset[i],
&value);
set_register_interruptible(ab8500, AB8500_INTERRUPT,
AB8500_IT_MASK1_REG + ab8500_irq_regoffset[i], 0xff);
}
ret = abx500_register_ops(ab8500->dev, &ab8500_ops);
if (ret)
return ret;
for (i = 0; i < AB8500_NUM_IRQ_REGS; i++)
ab8500->mask[i] = ab8500->oldmask[i] = 0xff;
if (ab8500->irq_base) {
ret = ab8500_irq_init(ab8500);
if (ret)
return ret;
ret = request_threaded_irq(ab8500->irq, NULL, ab8500_irq,
IRQF_ONESHOT | IRQF_NO_SUSPEND,
"ab8500", ab8500);
if (ret)
goto out_removeirq;
}
ret = mfd_add_devices(ab8500->dev, 0, ab8500_devs,
ARRAY_SIZE(ab8500_devs), NULL,
ab8500->irq_base);
if (ret)
goto out_freeirq;
ret = sysfs_create_group(&ab8500->dev->kobj, &ab8500_attr_group);
if (ret)
dev_err(ab8500->dev, "error creating sysfs entries\n");
return ret;
out_freeirq:
if (ab8500->irq_base) {
free_irq(ab8500->irq, ab8500);
out_removeirq:
ab8500_irq_remove(ab8500);
}
return ret;
}
int __devexit ab8500_exit(struct ab8500 *ab8500)
{
sysfs_remove_group(&ab8500->dev->kobj, &ab8500_attr_group);
mfd_remove_devices(ab8500->dev);
if (ab8500->irq_base) {
free_irq(ab8500->irq, ab8500);
ab8500_irq_remove(ab8500);
}
return 0;
}
