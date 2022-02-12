static int __stmpe_enable(struct stmpe *stmpe, unsigned int blocks)
{
return stmpe->variant->enable(stmpe, blocks, true);
}
static int __stmpe_disable(struct stmpe *stmpe, unsigned int blocks)
{
return stmpe->variant->enable(stmpe, blocks, false);
}
static int __stmpe_reg_read(struct stmpe *stmpe, u8 reg)
{
int ret;
ret = stmpe->ci->read_byte(stmpe, reg);
if (ret < 0)
dev_err(stmpe->dev, "failed to read reg %#x: %d\n", reg, ret);
dev_vdbg(stmpe->dev, "rd: reg %#x => data %#x\n", reg, ret);
return ret;
}
static int __stmpe_reg_write(struct stmpe *stmpe, u8 reg, u8 val)
{
int ret;
dev_vdbg(stmpe->dev, "wr: reg %#x <= %#x\n", reg, val);
ret = stmpe->ci->write_byte(stmpe, reg, val);
if (ret < 0)
dev_err(stmpe->dev, "failed to write reg %#x: %d\n", reg, ret);
return ret;
}
static int __stmpe_set_bits(struct stmpe *stmpe, u8 reg, u8 mask, u8 val)
{
int ret;
ret = __stmpe_reg_read(stmpe, reg);
if (ret < 0)
return ret;
ret &= ~mask;
ret |= val;
return __stmpe_reg_write(stmpe, reg, ret);
}
static int __stmpe_block_read(struct stmpe *stmpe, u8 reg, u8 length,
u8 *values)
{
int ret;
ret = stmpe->ci->read_block(stmpe, reg, length, values);
if (ret < 0)
dev_err(stmpe->dev, "failed to read regs %#x: %d\n", reg, ret);
dev_vdbg(stmpe->dev, "rd: reg %#x (%d) => ret %#x\n", reg, length, ret);
stmpe_dump_bytes("stmpe rd: ", values, length);
return ret;
}
static int __stmpe_block_write(struct stmpe *stmpe, u8 reg, u8 length,
const u8 *values)
{
int ret;
dev_vdbg(stmpe->dev, "wr: regs %#x (%d)\n", reg, length);
stmpe_dump_bytes("stmpe wr: ", values, length);
ret = stmpe->ci->write_block(stmpe, reg, length, values);
if (ret < 0)
dev_err(stmpe->dev, "failed to write regs %#x: %d\n", reg, ret);
return ret;
}
int stmpe_enable(struct stmpe *stmpe, unsigned int blocks)
{
int ret;
mutex_lock(&stmpe->lock);
ret = __stmpe_enable(stmpe, blocks);
mutex_unlock(&stmpe->lock);
return ret;
}
int stmpe_disable(struct stmpe *stmpe, unsigned int blocks)
{
int ret;
mutex_lock(&stmpe->lock);
ret = __stmpe_disable(stmpe, blocks);
mutex_unlock(&stmpe->lock);
return ret;
}
int stmpe_reg_read(struct stmpe *stmpe, u8 reg)
{
int ret;
mutex_lock(&stmpe->lock);
ret = __stmpe_reg_read(stmpe, reg);
mutex_unlock(&stmpe->lock);
return ret;
}
int stmpe_reg_write(struct stmpe *stmpe, u8 reg, u8 val)
{
int ret;
mutex_lock(&stmpe->lock);
ret = __stmpe_reg_write(stmpe, reg, val);
mutex_unlock(&stmpe->lock);
return ret;
}
int stmpe_set_bits(struct stmpe *stmpe, u8 reg, u8 mask, u8 val)
{
int ret;
mutex_lock(&stmpe->lock);
ret = __stmpe_set_bits(stmpe, reg, mask, val);
mutex_unlock(&stmpe->lock);
return ret;
}
int stmpe_block_read(struct stmpe *stmpe, u8 reg, u8 length, u8 *values)
{
int ret;
mutex_lock(&stmpe->lock);
ret = __stmpe_block_read(stmpe, reg, length, values);
mutex_unlock(&stmpe->lock);
return ret;
}
int stmpe_block_write(struct stmpe *stmpe, u8 reg, u8 length,
const u8 *values)
{
int ret;
mutex_lock(&stmpe->lock);
ret = __stmpe_block_write(stmpe, reg, length, values);
mutex_unlock(&stmpe->lock);
return ret;
}
int stmpe_set_altfunc(struct stmpe *stmpe, u32 pins, enum stmpe_block block)
{
struct stmpe_variant_info *variant = stmpe->variant;
u8 regaddr = stmpe->regs[STMPE_IDX_GPAFR_U_MSB];
int af_bits = variant->af_bits;
int numregs = DIV_ROUND_UP(stmpe->num_gpios * af_bits, 8);
int mask = (1 << af_bits) - 1;
u8 regs[numregs];
int af, afperreg, ret;
if (!variant->get_altfunc)
return 0;
afperreg = 8 / af_bits;
mutex_lock(&stmpe->lock);
ret = __stmpe_enable(stmpe, STMPE_BLOCK_GPIO);
if (ret < 0)
goto out;
ret = __stmpe_block_read(stmpe, regaddr, numregs, regs);
if (ret < 0)
goto out;
af = variant->get_altfunc(stmpe, block);
while (pins) {
int pin = __ffs(pins);
int regoffset = numregs - (pin / afperreg) - 1;
int pos = (pin % afperreg) * (8 / afperreg);
regs[regoffset] &= ~(mask << pos);
regs[regoffset] |= af << pos;
pins &= ~(1 << pin);
}
ret = __stmpe_block_write(stmpe, regaddr, numregs, regs);
out:
mutex_unlock(&stmpe->lock);
return ret;
}
static int stmpe801_enable(struct stmpe *stmpe, unsigned int blocks,
bool enable)
{
if (blocks & STMPE_BLOCK_GPIO)
return 0;
else
return -EINVAL;
}
static int stmpe811_enable(struct stmpe *stmpe, unsigned int blocks,
bool enable)
{
unsigned int mask = 0;
if (blocks & STMPE_BLOCK_GPIO)
mask |= STMPE811_SYS_CTRL2_GPIO_OFF;
if (blocks & STMPE_BLOCK_ADC)
mask |= STMPE811_SYS_CTRL2_ADC_OFF;
if (blocks & STMPE_BLOCK_TOUCHSCREEN)
mask |= STMPE811_SYS_CTRL2_TSC_OFF;
return __stmpe_set_bits(stmpe, STMPE811_REG_SYS_CTRL2, mask,
enable ? 0 : mask);
}
static int stmpe811_get_altfunc(struct stmpe *stmpe, enum stmpe_block block)
{
return block != STMPE_BLOCK_TOUCHSCREEN;
}
static int stmpe_round_timeout(int timeout)
{
int i;
for (i = 0; i < ARRAY_SIZE(stmpe_autosleep_delay); i++) {
if (stmpe_autosleep_delay[i] >= timeout)
return i;
}
return -EINVAL;
}
static int stmpe_autosleep(struct stmpe *stmpe, int autosleep_timeout)
{
int ret;
if (!stmpe->variant->enable_autosleep)
return -ENOSYS;
mutex_lock(&stmpe->lock);
ret = stmpe->variant->enable_autosleep(stmpe, autosleep_timeout);
mutex_unlock(&stmpe->lock);
return ret;
}
static int stmpe1601_autosleep(struct stmpe *stmpe,
int autosleep_timeout)
{
int ret, timeout;
timeout = stmpe_round_timeout(autosleep_timeout);
if (timeout < 0) {
dev_err(stmpe->dev, "invalid timeout\n");
return timeout;
}
ret = __stmpe_set_bits(stmpe, STMPE1601_REG_SYS_CTRL2,
STMPE1601_AUTOSLEEP_TIMEOUT_MASK,
timeout);
if (ret < 0)
return ret;
return __stmpe_set_bits(stmpe, STMPE1601_REG_SYS_CTRL2,
STPME1601_AUTOSLEEP_ENABLE,
STPME1601_AUTOSLEEP_ENABLE);
}
static int stmpe1601_enable(struct stmpe *stmpe, unsigned int blocks,
bool enable)
{
unsigned int mask = 0;
if (blocks & STMPE_BLOCK_GPIO)
mask |= STMPE1601_SYS_CTRL_ENABLE_GPIO;
if (blocks & STMPE_BLOCK_KEYPAD)
mask |= STMPE1601_SYS_CTRL_ENABLE_KPC;
return __stmpe_set_bits(stmpe, STMPE1601_REG_SYS_CTRL, mask,
enable ? mask : 0);
}
static int stmpe1601_get_altfunc(struct stmpe *stmpe, enum stmpe_block block)
{
switch (block) {
case STMPE_BLOCK_PWM:
return 2;
case STMPE_BLOCK_KEYPAD:
return 1;
case STMPE_BLOCK_GPIO:
default:
return 0;
}
}
static int stmpe1801_enable(struct stmpe *stmpe, unsigned int blocks,
bool enable)
{
unsigned int mask = 0;
if (blocks & STMPE_BLOCK_GPIO)
mask |= STMPE1801_MSK_INT_EN_GPIO;
if (blocks & STMPE_BLOCK_KEYPAD)
mask |= STMPE1801_MSK_INT_EN_KPC;
return __stmpe_set_bits(stmpe, STMPE1801_REG_INT_EN_MASK_LOW, mask,
enable ? mask : 0);
}
static int stmpe1801_reset(struct stmpe *stmpe)
{
unsigned long timeout;
int ret = 0;
ret = __stmpe_set_bits(stmpe, STMPE1801_REG_SYS_CTRL,
STMPE1801_MSK_SYS_CTRL_RESET, STMPE1801_MSK_SYS_CTRL_RESET);
if (ret < 0)
return ret;
timeout = jiffies + msecs_to_jiffies(100);
while (time_before(jiffies, timeout)) {
ret = __stmpe_reg_read(stmpe, STMPE1801_REG_SYS_CTRL);
if (ret < 0)
return ret;
if (!(ret & STMPE1801_MSK_SYS_CTRL_RESET))
return 0;
usleep_range(100, 200);
};
return -EIO;
}
static int stmpe24xx_enable(struct stmpe *stmpe, unsigned int blocks,
bool enable)
{
unsigned int mask = 0;
if (blocks & STMPE_BLOCK_GPIO)
mask |= STMPE24XX_SYS_CTRL_ENABLE_GPIO;
if (blocks & STMPE_BLOCK_KEYPAD)
mask |= STMPE24XX_SYS_CTRL_ENABLE_KPC;
return __stmpe_set_bits(stmpe, STMPE24XX_REG_SYS_CTRL, mask,
enable ? mask : 0);
}
static int stmpe24xx_get_altfunc(struct stmpe *stmpe, enum stmpe_block block)
{
switch (block) {
case STMPE_BLOCK_ROTATOR:
return 2;
case STMPE_BLOCK_KEYPAD:
return 1;
case STMPE_BLOCK_GPIO:
default:
return 0;
}
}
static irqreturn_t stmpe_irq(int irq, void *data)
{
struct stmpe *stmpe = data;
struct stmpe_variant_info *variant = stmpe->variant;
int num = DIV_ROUND_UP(variant->num_irqs, 8);
u8 israddr;
u8 isr[num];
int ret;
int i;
if (variant->id_val == STMPE801_ID) {
int base = irq_create_mapping(stmpe->domain, 0);
handle_nested_irq(base);
return IRQ_HANDLED;
}
if (variant->id_val == STMPE1801_ID)
israddr = stmpe->regs[STMPE_IDX_ISR_LSB];
else
israddr = stmpe->regs[STMPE_IDX_ISR_MSB];
ret = stmpe_block_read(stmpe, israddr, num, isr);
if (ret < 0)
return IRQ_NONE;
for (i = 0; i < num; i++) {
int bank = num - i - 1;
u8 status = isr[i];
u8 clear;
status &= stmpe->ier[bank];
if (!status)
continue;
clear = status;
while (status) {
int bit = __ffs(status);
int line = bank * 8 + bit;
int nestedirq = irq_create_mapping(stmpe->domain, line);
handle_nested_irq(nestedirq);
status &= ~(1 << bit);
}
stmpe_reg_write(stmpe, israddr + i, clear);
}
return IRQ_HANDLED;
}
static void stmpe_irq_lock(struct irq_data *data)
{
struct stmpe *stmpe = irq_data_get_irq_chip_data(data);
mutex_lock(&stmpe->irq_lock);
}
static void stmpe_irq_sync_unlock(struct irq_data *data)
{
struct stmpe *stmpe = irq_data_get_irq_chip_data(data);
struct stmpe_variant_info *variant = stmpe->variant;
int num = DIV_ROUND_UP(variant->num_irqs, 8);
int i;
for (i = 0; i < num; i++) {
u8 new = stmpe->ier[i];
u8 old = stmpe->oldier[i];
if (new == old)
continue;
stmpe->oldier[i] = new;
stmpe_reg_write(stmpe, stmpe->regs[STMPE_IDX_IER_LSB] - i, new);
}
mutex_unlock(&stmpe->irq_lock);
}
static void stmpe_irq_mask(struct irq_data *data)
{
struct stmpe *stmpe = irq_data_get_irq_chip_data(data);
int offset = data->hwirq;
int regoffset = offset / 8;
int mask = 1 << (offset % 8);
stmpe->ier[regoffset] &= ~mask;
}
static void stmpe_irq_unmask(struct irq_data *data)
{
struct stmpe *stmpe = irq_data_get_irq_chip_data(data);
int offset = data->hwirq;
int regoffset = offset / 8;
int mask = 1 << (offset % 8);
stmpe->ier[regoffset] |= mask;
}
static int stmpe_irq_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hwirq)
{
struct stmpe *stmpe = d->host_data;
struct irq_chip *chip = NULL;
if (stmpe->variant->id_val != STMPE801_ID)
chip = &stmpe_irq_chip;
irq_set_chip_data(virq, stmpe);
irq_set_chip_and_handler(virq, chip, handle_edge_irq);
irq_set_nested_thread(virq, 1);
#ifdef CONFIG_ARM
set_irq_flags(virq, IRQF_VALID);
#else
irq_set_noprobe(virq);
#endif
return 0;
}
static void stmpe_irq_unmap(struct irq_domain *d, unsigned int virq)
{
#ifdef CONFIG_ARM
set_irq_flags(virq, 0);
#endif
irq_set_chip_and_handler(virq, NULL, NULL);
irq_set_chip_data(virq, NULL);
}
static int stmpe_irq_init(struct stmpe *stmpe, struct device_node *np)
{
int base = 0;
int num_irqs = stmpe->variant->num_irqs;
if (!np)
base = stmpe->irq_base;
stmpe->domain = irq_domain_add_simple(np, num_irqs, base,
&stmpe_irq_ops, stmpe);
if (!stmpe->domain) {
dev_err(stmpe->dev, "Failed to create irqdomain\n");
return -ENOSYS;
}
return 0;
}
static int stmpe_chip_init(struct stmpe *stmpe)
{
unsigned int irq_trigger = stmpe->pdata->irq_trigger;
int autosleep_timeout = stmpe->pdata->autosleep_timeout;
struct stmpe_variant_info *variant = stmpe->variant;
u8 icr = 0;
unsigned int id;
u8 data[2];
int ret;
ret = stmpe_block_read(stmpe, stmpe->regs[STMPE_IDX_CHIP_ID],
ARRAY_SIZE(data), data);
if (ret < 0)
return ret;
id = (data[0] << 8) | data[1];
if ((id & variant->id_mask) != variant->id_val) {
dev_err(stmpe->dev, "unknown chip id: %#x\n", id);
return -EINVAL;
}
dev_info(stmpe->dev, "%s detected, chip id: %#x\n", variant->name, id);
ret = stmpe_disable(stmpe, ~0);
if (ret)
return ret;
if (id == STMPE1801_ID) {
ret = stmpe1801_reset(stmpe);
if (ret < 0)
return ret;
}
if (stmpe->irq >= 0) {
if (id == STMPE801_ID)
icr = STMPE801_REG_SYS_CTRL_INT_EN;
else
icr = STMPE_ICR_LSB_GIM;
if (id != STMPE801_ID) {
if (irq_trigger == IRQF_TRIGGER_FALLING ||
irq_trigger == IRQF_TRIGGER_RISING)
icr |= STMPE_ICR_LSB_EDGE;
}
if (irq_trigger == IRQF_TRIGGER_RISING ||
irq_trigger == IRQF_TRIGGER_HIGH) {
if (id == STMPE801_ID)
icr |= STMPE801_REG_SYS_CTRL_INT_HI;
else
icr |= STMPE_ICR_LSB_HIGH;
}
}
if (stmpe->pdata->autosleep) {
ret = stmpe_autosleep(stmpe, autosleep_timeout);
if (ret)
return ret;
}
return stmpe_reg_write(stmpe, stmpe->regs[STMPE_IDX_ICR_LSB], icr);
}
static int stmpe_add_device(struct stmpe *stmpe, struct mfd_cell *cell)
{
return mfd_add_devices(stmpe->dev, stmpe->pdata->id, cell, 1,
NULL, stmpe->irq_base, stmpe->domain);
}
static int stmpe_devices_init(struct stmpe *stmpe)
{
struct stmpe_variant_info *variant = stmpe->variant;
unsigned int platform_blocks = stmpe->pdata->blocks;
int ret = -EINVAL;
int i, j;
for (i = 0; i < variant->num_blocks; i++) {
struct stmpe_variant_block *block = &variant->blocks[i];
if (!(platform_blocks & block->block))
continue;
for (j = 0; j < block->cell->num_resources; j++) {
struct resource *res =
(struct resource *) &block->cell->resources[j];
if (res->flags & IORESOURCE_IRQ)
res->start = res->end = block->irq + j;
}
platform_blocks &= ~block->block;
ret = stmpe_add_device(stmpe, block->cell);
if (ret)
return ret;
}
if (platform_blocks)
dev_warn(stmpe->dev,
"platform wants blocks (%#x) not present on variant",
platform_blocks);
return ret;
}
void stmpe_of_probe(struct stmpe_platform_data *pdata, struct device_node *np)
{
struct device_node *child;
pdata->id = of_alias_get_id(np, "stmpe-i2c");
if (pdata->id < 0)
pdata->id = -1;
pdata->irq_trigger = IRQF_TRIGGER_NONE;
of_property_read_u32(np, "st,autosleep-timeout",
&pdata->autosleep_timeout);
pdata->autosleep = (pdata->autosleep_timeout) ? true : false;
for_each_child_of_node(np, child) {
if (!strcmp(child->name, "stmpe_gpio")) {
pdata->blocks |= STMPE_BLOCK_GPIO;
} else if (!strcmp(child->name, "stmpe_keypad")) {
pdata->blocks |= STMPE_BLOCK_KEYPAD;
} else if (!strcmp(child->name, "stmpe_touchscreen")) {
pdata->blocks |= STMPE_BLOCK_TOUCHSCREEN;
} else if (!strcmp(child->name, "stmpe_adc")) {
pdata->blocks |= STMPE_BLOCK_ADC;
} else if (!strcmp(child->name, "stmpe_pwm")) {
pdata->blocks |= STMPE_BLOCK_PWM;
} else if (!strcmp(child->name, "stmpe_rotator")) {
pdata->blocks |= STMPE_BLOCK_ROTATOR;
}
}
}
int stmpe_probe(struct stmpe_client_info *ci, int partnum)
{
struct stmpe_platform_data *pdata = dev_get_platdata(ci->dev);
struct device_node *np = ci->dev->of_node;
struct stmpe *stmpe;
int ret;
if (!pdata) {
if (!np)
return -EINVAL;
pdata = devm_kzalloc(ci->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
stmpe_of_probe(pdata, np);
if (of_find_property(np, "interrupts", NULL) == NULL)
ci->irq = -1;
}
stmpe = devm_kzalloc(ci->dev, sizeof(struct stmpe), GFP_KERNEL);
if (!stmpe)
return -ENOMEM;
mutex_init(&stmpe->irq_lock);
mutex_init(&stmpe->lock);
stmpe->dev = ci->dev;
stmpe->client = ci->client;
stmpe->pdata = pdata;
stmpe->irq_base = pdata->irq_base;
stmpe->ci = ci;
stmpe->partnum = partnum;
stmpe->variant = stmpe_variant_info[partnum];
stmpe->regs = stmpe->variant->regs;
stmpe->num_gpios = stmpe->variant->num_gpios;
dev_set_drvdata(stmpe->dev, stmpe);
if (ci->init)
ci->init(stmpe);
if (pdata->irq_over_gpio) {
ret = devm_gpio_request_one(ci->dev, pdata->irq_gpio,
GPIOF_DIR_IN, "stmpe");
if (ret) {
dev_err(stmpe->dev, "failed to request IRQ GPIO: %d\n",
ret);
return ret;
}
stmpe->irq = gpio_to_irq(pdata->irq_gpio);
} else {
stmpe->irq = ci->irq;
}
if (stmpe->irq < 0) {
dev_info(stmpe->dev,
"%s configured in no-irq mode by platform data\n",
stmpe->variant->name);
if (!stmpe_noirq_variant_info[stmpe->partnum]) {
dev_err(stmpe->dev,
"%s does not support no-irq mode!\n",
stmpe->variant->name);
return -ENODEV;
}
stmpe->variant = stmpe_noirq_variant_info[stmpe->partnum];
} else if (pdata->irq_trigger == IRQF_TRIGGER_NONE) {
pdata->irq_trigger =
irqd_get_trigger_type(irq_get_irq_data(stmpe->irq));
}
ret = stmpe_chip_init(stmpe);
if (ret)
return ret;
if (stmpe->irq >= 0) {
ret = stmpe_irq_init(stmpe, np);
if (ret)
return ret;
ret = devm_request_threaded_irq(ci->dev, stmpe->irq, NULL,
stmpe_irq, pdata->irq_trigger | IRQF_ONESHOT,
"stmpe", stmpe);
if (ret) {
dev_err(stmpe->dev, "failed to request IRQ: %d\n",
ret);
return ret;
}
}
ret = stmpe_devices_init(stmpe);
if (!ret)
return 0;
dev_err(stmpe->dev, "failed to add children\n");
mfd_remove_devices(stmpe->dev);
return ret;
}
int stmpe_remove(struct stmpe *stmpe)
{
mfd_remove_devices(stmpe->dev);
return 0;
}
static int stmpe_suspend(struct device *dev)
{
struct stmpe *stmpe = dev_get_drvdata(dev);
if (stmpe->irq >= 0 && device_may_wakeup(dev))
enable_irq_wake(stmpe->irq);
return 0;
}
static int stmpe_resume(struct device *dev)
{
struct stmpe *stmpe = dev_get_drvdata(dev);
if (stmpe->irq >= 0 && device_may_wakeup(dev))
disable_irq_wake(stmpe->irq);
return 0;
}
