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
ret = i2c_smbus_read_byte_data(stmpe->i2c, reg);
if (ret < 0)
dev_err(stmpe->dev, "failed to read reg %#x: %d\n",
reg, ret);
dev_vdbg(stmpe->dev, "rd: reg %#x => data %#x\n", reg, ret);
return ret;
}
static int __stmpe_reg_write(struct stmpe *stmpe, u8 reg, u8 val)
{
int ret;
dev_vdbg(stmpe->dev, "wr: reg %#x <= %#x\n", reg, val);
ret = i2c_smbus_write_byte_data(stmpe->i2c, reg, val);
if (ret < 0)
dev_err(stmpe->dev, "failed to write reg %#x: %d\n",
reg, ret);
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
ret = i2c_smbus_read_i2c_block_data(stmpe->i2c, reg, length, values);
if (ret < 0)
dev_err(stmpe->dev, "failed to read regs %#x: %d\n",
reg, ret);
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
ret = i2c_smbus_write_i2c_block_data(stmpe->i2c, reg, length,
values);
if (ret < 0)
dev_err(stmpe->dev, "failed to write regs %#x: %d\n",
reg, ret);
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
int afperreg = 8 / af_bits;
int mask = (1 << af_bits) - 1;
u8 regs[numregs];
int af;
int ret;
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
u8 israddr = stmpe->regs[STMPE_IDX_ISR_MSB];
u8 isr[num];
int ret;
int i;
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
handle_nested_irq(stmpe->irq_base + line);
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
int offset = data->irq - stmpe->irq_base;
int regoffset = offset / 8;
int mask = 1 << (offset % 8);
stmpe->ier[regoffset] &= ~mask;
}
static void stmpe_irq_unmask(struct irq_data *data)
{
struct stmpe *stmpe = irq_data_get_irq_chip_data(data);
int offset = data->irq - stmpe->irq_base;
int regoffset = offset / 8;
int mask = 1 << (offset % 8);
stmpe->ier[regoffset] |= mask;
}
static int __devinit stmpe_irq_init(struct stmpe *stmpe)
{
int num_irqs = stmpe->variant->num_irqs;
int base = stmpe->irq_base;
int irq;
for (irq = base; irq < base + num_irqs; irq++) {
irq_set_chip_data(irq, stmpe);
irq_set_chip_and_handler(irq, &stmpe_irq_chip,
handle_edge_irq);
irq_set_nested_thread(irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(irq, IRQF_VALID);
#else
irq_set_noprobe(irq);
#endif
}
return 0;
}
static void stmpe_irq_remove(struct stmpe *stmpe)
{
int num_irqs = stmpe->variant->num_irqs;
int base = stmpe->irq_base;
int irq;
for (irq = base; irq < base + num_irqs; irq++) {
#ifdef CONFIG_ARM
set_irq_flags(irq, 0);
#endif
irq_set_chip_and_handler(irq, NULL, NULL);
irq_set_chip_data(irq, NULL);
}
}
static int __devinit stmpe_chip_init(struct stmpe *stmpe)
{
unsigned int irq_trigger = stmpe->pdata->irq_trigger;
int autosleep_timeout = stmpe->pdata->autosleep_timeout;
struct stmpe_variant_info *variant = stmpe->variant;
u8 icr = STMPE_ICR_LSB_GIM;
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
if (irq_trigger == IRQF_TRIGGER_FALLING ||
irq_trigger == IRQF_TRIGGER_RISING)
icr |= STMPE_ICR_LSB_EDGE;
if (irq_trigger == IRQF_TRIGGER_RISING ||
irq_trigger == IRQF_TRIGGER_HIGH)
icr |= STMPE_ICR_LSB_HIGH;
if (stmpe->pdata->irq_invert_polarity)
icr ^= STMPE_ICR_LSB_HIGH;
if (stmpe->pdata->autosleep) {
ret = stmpe_autosleep(stmpe, autosleep_timeout);
if (ret)
return ret;
}
return stmpe_reg_write(stmpe, stmpe->regs[STMPE_IDX_ICR_LSB], icr);
}
static int __devinit stmpe_add_device(struct stmpe *stmpe,
struct mfd_cell *cell, int irq)
{
return mfd_add_devices(stmpe->dev, stmpe->pdata->id, cell, 1,
NULL, stmpe->irq_base + irq);
}
static int __devinit stmpe_devices_init(struct stmpe *stmpe)
{
struct stmpe_variant_info *variant = stmpe->variant;
unsigned int platform_blocks = stmpe->pdata->blocks;
int ret = -EINVAL;
int i;
for (i = 0; i < variant->num_blocks; i++) {
struct stmpe_variant_block *block = &variant->blocks[i];
if (!(platform_blocks & block->block))
continue;
platform_blocks &= ~block->block;
ret = stmpe_add_device(stmpe, block->cell, block->irq);
if (ret)
return ret;
}
if (platform_blocks)
dev_warn(stmpe->dev,
"platform wants blocks (%#x) not present on variant",
platform_blocks);
return ret;
}
static int stmpe_suspend(struct device *dev)
{
struct i2c_client *i2c = to_i2c_client(dev);
if (device_may_wakeup(&i2c->dev))
enable_irq_wake(i2c->irq);
return 0;
}
static int stmpe_resume(struct device *dev)
{
struct i2c_client *i2c = to_i2c_client(dev);
if (device_may_wakeup(&i2c->dev))
disable_irq_wake(i2c->irq);
return 0;
}
static int __devinit stmpe_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct stmpe_platform_data *pdata = i2c->dev.platform_data;
struct stmpe *stmpe;
int ret;
if (!pdata)
return -EINVAL;
stmpe = kzalloc(sizeof(struct stmpe), GFP_KERNEL);
if (!stmpe)
return -ENOMEM;
mutex_init(&stmpe->irq_lock);
mutex_init(&stmpe->lock);
stmpe->dev = &i2c->dev;
stmpe->i2c = i2c;
stmpe->pdata = pdata;
stmpe->irq_base = pdata->irq_base;
stmpe->partnum = id->driver_data;
stmpe->variant = stmpe_variant_info[stmpe->partnum];
stmpe->regs = stmpe->variant->regs;
stmpe->num_gpios = stmpe->variant->num_gpios;
i2c_set_clientdata(i2c, stmpe);
ret = stmpe_chip_init(stmpe);
if (ret)
goto out_free;
ret = stmpe_irq_init(stmpe);
if (ret)
goto out_free;
ret = request_threaded_irq(stmpe->i2c->irq, NULL, stmpe_irq,
pdata->irq_trigger | IRQF_ONESHOT,
"stmpe", stmpe);
if (ret) {
dev_err(stmpe->dev, "failed to request IRQ: %d\n", ret);
goto out_removeirq;
}
ret = stmpe_devices_init(stmpe);
if (ret) {
dev_err(stmpe->dev, "failed to add children\n");
goto out_removedevs;
}
return 0;
out_removedevs:
mfd_remove_devices(stmpe->dev);
free_irq(stmpe->i2c->irq, stmpe);
out_removeirq:
stmpe_irq_remove(stmpe);
out_free:
kfree(stmpe);
return ret;
}
static int __devexit stmpe_remove(struct i2c_client *client)
{
struct stmpe *stmpe = i2c_get_clientdata(client);
mfd_remove_devices(stmpe->dev);
free_irq(stmpe->i2c->irq, stmpe);
stmpe_irq_remove(stmpe);
kfree(stmpe);
return 0;
}
static int __init stmpe_init(void)
{
return i2c_add_driver(&stmpe_driver);
}
static void __exit stmpe_exit(void)
{
i2c_del_driver(&stmpe_driver);
}
