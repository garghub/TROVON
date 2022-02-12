static int pca953x_read_single(struct pca953x_chip *chip, int reg, u32 *val,
int off)
{
int ret;
int bank_shift = fls((chip->gpio_chip.ngpio - 1) / BANK_SZ);
int offset = off / BANK_SZ;
ret = i2c_smbus_read_byte_data(chip->client,
(reg << bank_shift) + offset);
*val = ret;
if (ret < 0) {
dev_err(&chip->client->dev, "failed reading register\n");
return ret;
}
return 0;
}
static int pca953x_write_single(struct pca953x_chip *chip, int reg, u32 val,
int off)
{
int ret;
int bank_shift = fls((chip->gpio_chip.ngpio - 1) / BANK_SZ);
int offset = off / BANK_SZ;
ret = i2c_smbus_write_byte_data(chip->client,
(reg << bank_shift) + offset, val);
if (ret < 0) {
dev_err(&chip->client->dev, "failed writing register\n");
return ret;
}
return 0;
}
static int pca953x_write_regs_8(struct pca953x_chip *chip, int reg, u8 *val)
{
return i2c_smbus_write_byte_data(chip->client, reg, *val);
}
static int pca953x_write_regs_16(struct pca953x_chip *chip, int reg, u8 *val)
{
u16 word = get_unaligned((u16 *)val);
return i2c_smbus_write_word_data(chip->client, reg << 1, word);
}
static int pca957x_write_regs_16(struct pca953x_chip *chip, int reg, u8 *val)
{
int ret;
ret = i2c_smbus_write_byte_data(chip->client, reg << 1, val[0]);
if (ret < 0)
return ret;
return i2c_smbus_write_byte_data(chip->client, (reg << 1) + 1, val[1]);
}
static int pca953x_write_regs_24(struct pca953x_chip *chip, int reg, u8 *val)
{
int bank_shift = fls((chip->gpio_chip.ngpio - 1) / BANK_SZ);
return i2c_smbus_write_i2c_block_data(chip->client,
(reg << bank_shift) | REG_ADDR_AI,
NBANK(chip), val);
}
static int pca953x_write_regs(struct pca953x_chip *chip, int reg, u8 *val)
{
int ret = 0;
ret = chip->write_regs(chip, reg, val);
if (ret < 0) {
dev_err(&chip->client->dev, "failed writing register\n");
return ret;
}
return 0;
}
static int pca953x_read_regs_8(struct pca953x_chip *chip, int reg, u8 *val)
{
int ret;
ret = i2c_smbus_read_byte_data(chip->client, reg);
*val = ret;
return ret;
}
static int pca953x_read_regs_16(struct pca953x_chip *chip, int reg, u8 *val)
{
int ret;
ret = i2c_smbus_read_word_data(chip->client, reg << 1);
put_unaligned(ret, (u16 *)val);
return ret;
}
static int pca953x_read_regs_24(struct pca953x_chip *chip, int reg, u8 *val)
{
int bank_shift = fls((chip->gpio_chip.ngpio - 1) / BANK_SZ);
return i2c_smbus_read_i2c_block_data(chip->client,
(reg << bank_shift) | REG_ADDR_AI,
NBANK(chip), val);
}
static int pca953x_read_regs(struct pca953x_chip *chip, int reg, u8 *val)
{
int ret;
ret = chip->read_regs(chip, reg, val);
if (ret < 0) {
dev_err(&chip->client->dev, "failed reading register\n");
return ret;
}
return 0;
}
static int pca953x_gpio_direction_input(struct gpio_chip *gc, unsigned off)
{
struct pca953x_chip *chip = gpiochip_get_data(gc);
u8 reg_val;
int ret;
mutex_lock(&chip->i2c_lock);
reg_val = chip->reg_direction[off / BANK_SZ] | (1u << (off % BANK_SZ));
ret = pca953x_write_single(chip, chip->regs->direction, reg_val, off);
if (ret)
goto exit;
chip->reg_direction[off / BANK_SZ] = reg_val;
exit:
mutex_unlock(&chip->i2c_lock);
return ret;
}
static int pca953x_gpio_direction_output(struct gpio_chip *gc,
unsigned off, int val)
{
struct pca953x_chip *chip = gpiochip_get_data(gc);
u8 reg_val;
int ret;
mutex_lock(&chip->i2c_lock);
if (val)
reg_val = chip->reg_output[off / BANK_SZ]
| (1u << (off % BANK_SZ));
else
reg_val = chip->reg_output[off / BANK_SZ]
& ~(1u << (off % BANK_SZ));
ret = pca953x_write_single(chip, chip->regs->output, reg_val, off);
if (ret)
goto exit;
chip->reg_output[off / BANK_SZ] = reg_val;
reg_val = chip->reg_direction[off / BANK_SZ] & ~(1u << (off % BANK_SZ));
ret = pca953x_write_single(chip, chip->regs->direction, reg_val, off);
if (ret)
goto exit;
chip->reg_direction[off / BANK_SZ] = reg_val;
exit:
mutex_unlock(&chip->i2c_lock);
return ret;
}
static int pca953x_gpio_get_value(struct gpio_chip *gc, unsigned off)
{
struct pca953x_chip *chip = gpiochip_get_data(gc);
u32 reg_val;
int ret;
mutex_lock(&chip->i2c_lock);
ret = pca953x_read_single(chip, chip->regs->input, &reg_val, off);
mutex_unlock(&chip->i2c_lock);
if (ret < 0) {
return 0;
}
return (reg_val & (1u << (off % BANK_SZ))) ? 1 : 0;
}
static void pca953x_gpio_set_value(struct gpio_chip *gc, unsigned off, int val)
{
struct pca953x_chip *chip = gpiochip_get_data(gc);
u8 reg_val;
int ret;
mutex_lock(&chip->i2c_lock);
if (val)
reg_val = chip->reg_output[off / BANK_SZ]
| (1u << (off % BANK_SZ));
else
reg_val = chip->reg_output[off / BANK_SZ]
& ~(1u << (off % BANK_SZ));
ret = pca953x_write_single(chip, chip->regs->output, reg_val, off);
if (ret)
goto exit;
chip->reg_output[off / BANK_SZ] = reg_val;
exit:
mutex_unlock(&chip->i2c_lock);
}
static int pca953x_gpio_get_direction(struct gpio_chip *gc, unsigned off)
{
struct pca953x_chip *chip = gpiochip_get_data(gc);
u32 reg_val;
int ret;
mutex_lock(&chip->i2c_lock);
ret = pca953x_read_single(chip, chip->regs->direction, &reg_val, off);
mutex_unlock(&chip->i2c_lock);
if (ret < 0)
return ret;
return !!(reg_val & (1u << (off % BANK_SZ)));
}
static void pca953x_gpio_set_multiple(struct gpio_chip *gc,
unsigned long *mask, unsigned long *bits)
{
struct pca953x_chip *chip = gpiochip_get_data(gc);
unsigned int bank_mask, bank_val;
int bank_shift, bank;
u8 reg_val[MAX_BANK];
int ret;
bank_shift = fls((chip->gpio_chip.ngpio - 1) / BANK_SZ);
mutex_lock(&chip->i2c_lock);
memcpy(reg_val, chip->reg_output, NBANK(chip));
for (bank = 0; bank < NBANK(chip); bank++) {
bank_mask = mask[bank / sizeof(*mask)] >>
((bank % sizeof(*mask)) * 8);
if (bank_mask) {
bank_val = bits[bank / sizeof(*bits)] >>
((bank % sizeof(*bits)) * 8);
bank_val &= bank_mask;
reg_val[bank] = (reg_val[bank] & ~bank_mask) | bank_val;
}
}
ret = i2c_smbus_write_i2c_block_data(chip->client,
chip->regs->output << bank_shift,
NBANK(chip), reg_val);
if (ret)
goto exit;
memcpy(chip->reg_output, reg_val, NBANK(chip));
exit:
mutex_unlock(&chip->i2c_lock);
}
static void pca953x_setup_gpio(struct pca953x_chip *chip, int gpios)
{
struct gpio_chip *gc;
gc = &chip->gpio_chip;
gc->direction_input = pca953x_gpio_direction_input;
gc->direction_output = pca953x_gpio_direction_output;
gc->get = pca953x_gpio_get_value;
gc->set = pca953x_gpio_set_value;
gc->get_direction = pca953x_gpio_get_direction;
gc->set_multiple = pca953x_gpio_set_multiple;
gc->can_sleep = true;
gc->base = chip->gpio_start;
gc->ngpio = gpios;
gc->label = chip->client->name;
gc->parent = &chip->client->dev;
gc->owner = THIS_MODULE;
gc->names = chip->names;
}
static void pca953x_irq_mask(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct pca953x_chip *chip = gpiochip_get_data(gc);
chip->irq_mask[d->hwirq / BANK_SZ] &= ~(1 << (d->hwirq % BANK_SZ));
}
static void pca953x_irq_unmask(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct pca953x_chip *chip = gpiochip_get_data(gc);
chip->irq_mask[d->hwirq / BANK_SZ] |= 1 << (d->hwirq % BANK_SZ);
}
static void pca953x_irq_bus_lock(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct pca953x_chip *chip = gpiochip_get_data(gc);
mutex_lock(&chip->irq_lock);
}
static void pca953x_irq_bus_sync_unlock(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct pca953x_chip *chip = gpiochip_get_data(gc);
u8 new_irqs;
int level, i;
u8 invert_irq_mask[MAX_BANK];
if (chip->driver_data & PCA_PCAL) {
pca953x_write_regs(chip, PCAL953X_IN_LATCH, chip->irq_mask);
for (i = 0; i < NBANK(chip); i++)
invert_irq_mask[i] = ~chip->irq_mask[i];
pca953x_write_regs(chip, PCAL953X_INT_MASK, invert_irq_mask);
}
for (i = 0; i < NBANK(chip); i++) {
new_irqs = chip->irq_trig_fall[i] | chip->irq_trig_raise[i];
new_irqs &= ~chip->reg_direction[i];
while (new_irqs) {
level = __ffs(new_irqs);
pca953x_gpio_direction_input(&chip->gpio_chip,
level + (BANK_SZ * i));
new_irqs &= ~(1 << level);
}
}
mutex_unlock(&chip->irq_lock);
}
static int pca953x_irq_set_type(struct irq_data *d, unsigned int type)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct pca953x_chip *chip = gpiochip_get_data(gc);
int bank_nb = d->hwirq / BANK_SZ;
u8 mask = 1 << (d->hwirq % BANK_SZ);
if (!(type & IRQ_TYPE_EDGE_BOTH)) {
dev_err(&chip->client->dev, "irq %d: unsupported type %d\n",
d->irq, type);
return -EINVAL;
}
if (type & IRQ_TYPE_EDGE_FALLING)
chip->irq_trig_fall[bank_nb] |= mask;
else
chip->irq_trig_fall[bank_nb] &= ~mask;
if (type & IRQ_TYPE_EDGE_RISING)
chip->irq_trig_raise[bank_nb] |= mask;
else
chip->irq_trig_raise[bank_nb] &= ~mask;
return 0;
}
static bool pca953x_irq_pending(struct pca953x_chip *chip, u8 *pending)
{
u8 cur_stat[MAX_BANK];
u8 old_stat[MAX_BANK];
bool pending_seen = false;
bool trigger_seen = false;
u8 trigger[MAX_BANK];
int ret, i;
if (chip->driver_data & PCA_PCAL) {
ret = pca953x_read_regs(chip, PCAL953X_INT_STAT, trigger);
if (ret)
return false;
ret = pca953x_read_regs(chip, PCA953X_INPUT, cur_stat);
if (ret)
return false;
for (i = 0; i < NBANK(chip); i++) {
pending[i] = (~cur_stat[i] & chip->irq_trig_fall[i]) |
(cur_stat[i] & chip->irq_trig_raise[i]);
pending[i] &= trigger[i];
if (pending[i])
pending_seen = true;
}
return pending_seen;
}
ret = pca953x_read_regs(chip, chip->regs->input, cur_stat);
if (ret)
return false;
for (i = 0; i < NBANK(chip); i++)
cur_stat[i] &= chip->reg_direction[i];
memcpy(old_stat, chip->irq_stat, NBANK(chip));
for (i = 0; i < NBANK(chip); i++) {
trigger[i] = (cur_stat[i] ^ old_stat[i]) & chip->irq_mask[i];
if (trigger[i])
trigger_seen = true;
}
if (!trigger_seen)
return false;
memcpy(chip->irq_stat, cur_stat, NBANK(chip));
for (i = 0; i < NBANK(chip); i++) {
pending[i] = (old_stat[i] & chip->irq_trig_fall[i]) |
(cur_stat[i] & chip->irq_trig_raise[i]);
pending[i] &= trigger[i];
if (pending[i])
pending_seen = true;
}
return pending_seen;
}
static irqreturn_t pca953x_irq_handler(int irq, void *devid)
{
struct pca953x_chip *chip = devid;
u8 pending[MAX_BANK];
u8 level;
unsigned nhandled = 0;
int i;
if (!pca953x_irq_pending(chip, pending))
return IRQ_NONE;
for (i = 0; i < NBANK(chip); i++) {
while (pending[i]) {
level = __ffs(pending[i]);
handle_nested_irq(irq_find_mapping(chip->gpio_chip.irqdomain,
level + (BANK_SZ * i)));
pending[i] &= ~(1 << level);
nhandled++;
}
}
return (nhandled > 0) ? IRQ_HANDLED : IRQ_NONE;
}
static int pca953x_irq_setup(struct pca953x_chip *chip,
int irq_base)
{
struct i2c_client *client = chip->client;
int ret, i;
if (client->irq && irq_base != -1
&& (chip->driver_data & PCA_INT)) {
ret = pca953x_read_regs(chip,
chip->regs->input, chip->irq_stat);
if (ret)
return ret;
for (i = 0; i < NBANK(chip); i++)
chip->irq_stat[i] &= chip->reg_direction[i];
mutex_init(&chip->irq_lock);
ret = devm_request_threaded_irq(&client->dev,
client->irq,
NULL,
pca953x_irq_handler,
IRQF_TRIGGER_LOW | IRQF_ONESHOT |
IRQF_SHARED,
dev_name(&client->dev), chip);
if (ret) {
dev_err(&client->dev, "failed to request irq %d\n",
client->irq);
return ret;
}
ret = gpiochip_irqchip_add_nested(&chip->gpio_chip,
&pca953x_irq_chip,
irq_base,
handle_simple_irq,
IRQ_TYPE_NONE);
if (ret) {
dev_err(&client->dev,
"could not connect irqchip to gpiochip\n");
return ret;
}
gpiochip_set_nested_irqchip(&chip->gpio_chip,
&pca953x_irq_chip,
client->irq);
}
return 0;
}
static int pca953x_irq_setup(struct pca953x_chip *chip,
int irq_base)
{
struct i2c_client *client = chip->client;
if (irq_base != -1 && (chip->driver_data & PCA_INT))
dev_warn(&client->dev, "interrupt support not compiled in\n");
return 0;
}
static int device_pca953x_init(struct pca953x_chip *chip, u32 invert)
{
int ret;
u8 val[MAX_BANK];
chip->regs = &pca953x_regs;
ret = pca953x_read_regs(chip, chip->regs->output, chip->reg_output);
if (ret)
goto out;
ret = pca953x_read_regs(chip, chip->regs->direction,
chip->reg_direction);
if (ret)
goto out;
if (invert)
memset(val, 0xFF, NBANK(chip));
else
memset(val, 0, NBANK(chip));
ret = pca953x_write_regs(chip, PCA953X_INVERT, val);
out:
return ret;
}
static int device_pca957x_init(struct pca953x_chip *chip, u32 invert)
{
int ret;
u8 val[MAX_BANK];
chip->regs = &pca957x_regs;
ret = pca953x_read_regs(chip, chip->regs->output, chip->reg_output);
if (ret)
goto out;
ret = pca953x_read_regs(chip, chip->regs->direction,
chip->reg_direction);
if (ret)
goto out;
if (invert)
memset(val, 0xFF, NBANK(chip));
else
memset(val, 0, NBANK(chip));
ret = pca953x_write_regs(chip, PCA957X_INVRT, val);
if (ret)
goto out;
memset(val, 0x02, NBANK(chip));
ret = pca953x_write_regs(chip, PCA957X_BKEN, val);
if (ret)
goto out;
return 0;
out:
return ret;
}
static int pca953x_probe(struct i2c_client *client,
const struct i2c_device_id *i2c_id)
{
struct pca953x_platform_data *pdata;
struct pca953x_chip *chip;
int irq_base = 0;
int ret;
u32 invert = 0;
struct regulator *reg;
chip = devm_kzalloc(&client->dev,
sizeof(struct pca953x_chip), GFP_KERNEL);
if (chip == NULL)
return -ENOMEM;
pdata = dev_get_platdata(&client->dev);
if (pdata) {
irq_base = pdata->irq_base;
chip->gpio_start = pdata->gpio_base;
invert = pdata->invert;
chip->names = pdata->names;
} else {
struct gpio_desc *reset_gpio;
chip->gpio_start = -1;
irq_base = 0;
reset_gpio = devm_gpiod_get_optional(&client->dev, "reset",
GPIOD_OUT_LOW);
if (IS_ERR(reset_gpio))
return PTR_ERR(reset_gpio);
}
chip->client = client;
reg = devm_regulator_get(&client->dev, "vcc");
if (IS_ERR(reg)) {
ret = PTR_ERR(reg);
if (ret != -EPROBE_DEFER)
dev_err(&client->dev, "reg get err: %d\n", ret);
return ret;
}
ret = regulator_enable(reg);
if (ret) {
dev_err(&client->dev, "reg en err: %d\n", ret);
return ret;
}
chip->regulator = reg;
if (i2c_id) {
chip->driver_data = i2c_id->driver_data;
} else {
const struct acpi_device_id *acpi_id;
const struct of_device_id *match;
match = of_match_device(pca953x_dt_ids, &client->dev);
if (match) {
chip->driver_data = (int)(uintptr_t)match->data;
} else {
acpi_id = acpi_match_device(pca953x_acpi_ids, &client->dev);
if (!acpi_id) {
ret = -ENODEV;
goto err_exit;
}
chip->driver_data = acpi_id->driver_data;
}
}
mutex_init(&chip->i2c_lock);
lockdep_set_subclass(&chip->i2c_lock,
i2c_adapter_depth(client->adapter));
pca953x_setup_gpio(chip, chip->driver_data & PCA_GPIO_MASK);
if (chip->gpio_chip.ngpio <= 8) {
chip->write_regs = pca953x_write_regs_8;
chip->read_regs = pca953x_read_regs_8;
} else if (chip->gpio_chip.ngpio >= 24) {
chip->write_regs = pca953x_write_regs_24;
chip->read_regs = pca953x_read_regs_24;
} else {
if (PCA_CHIP_TYPE(chip->driver_data) == PCA953X_TYPE)
chip->write_regs = pca953x_write_regs_16;
else
chip->write_regs = pca957x_write_regs_16;
chip->read_regs = pca953x_read_regs_16;
}
if (PCA_CHIP_TYPE(chip->driver_data) == PCA953X_TYPE)
ret = device_pca953x_init(chip, invert);
else
ret = device_pca957x_init(chip, invert);
if (ret)
goto err_exit;
ret = devm_gpiochip_add_data(&client->dev, &chip->gpio_chip, chip);
if (ret)
goto err_exit;
ret = pca953x_irq_setup(chip, irq_base);
if (ret)
goto err_exit;
if (pdata && pdata->setup) {
ret = pdata->setup(client, chip->gpio_chip.base,
chip->gpio_chip.ngpio, pdata->context);
if (ret < 0)
dev_warn(&client->dev, "setup failed, %d\n", ret);
}
i2c_set_clientdata(client, chip);
return 0;
err_exit:
regulator_disable(chip->regulator);
return ret;
}
static int pca953x_remove(struct i2c_client *client)
{
struct pca953x_platform_data *pdata = dev_get_platdata(&client->dev);
struct pca953x_chip *chip = i2c_get_clientdata(client);
int ret;
if (pdata && pdata->teardown) {
ret = pdata->teardown(client, chip->gpio_chip.base,
chip->gpio_chip.ngpio, pdata->context);
if (ret < 0)
dev_err(&client->dev, "%s failed, %d\n",
"teardown", ret);
} else {
ret = 0;
}
regulator_disable(chip->regulator);
return ret;
}
static int __init pca953x_init(void)
{
return i2c_add_driver(&pca953x_driver);
}
static void __exit pca953x_exit(void)
{
i2c_del_driver(&pca953x_driver);
}
