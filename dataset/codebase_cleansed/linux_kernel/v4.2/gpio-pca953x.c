static inline struct pca953x_chip *to_pca(struct gpio_chip *gc)
{
return container_of(gc, struct pca953x_chip, gpio_chip);
}
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
int ret = 0;
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
static int pca953x_write_regs(struct pca953x_chip *chip, int reg, u8 *val)
{
int ret = 0;
if (chip->gpio_chip.ngpio <= 8)
ret = i2c_smbus_write_byte_data(chip->client, reg, *val);
else if (chip->gpio_chip.ngpio >= 24) {
int bank_shift = fls((chip->gpio_chip.ngpio - 1) / BANK_SZ);
ret = i2c_smbus_write_i2c_block_data(chip->client,
(reg << bank_shift) | REG_ADDR_AI,
NBANK(chip), val);
} else {
switch (chip->chip_type) {
case PCA953X_TYPE:
ret = i2c_smbus_write_word_data(chip->client,
reg << 1, (u16) *val);
break;
case PCA957X_TYPE:
ret = i2c_smbus_write_byte_data(chip->client, reg << 1,
val[0]);
if (ret < 0)
break;
ret = i2c_smbus_write_byte_data(chip->client,
(reg << 1) + 1,
val[1]);
break;
}
}
if (ret < 0) {
dev_err(&chip->client->dev, "failed writing register\n");
return ret;
}
return 0;
}
static int pca953x_read_regs(struct pca953x_chip *chip, int reg, u8 *val)
{
int ret;
if (chip->gpio_chip.ngpio <= 8) {
ret = i2c_smbus_read_byte_data(chip->client, reg);
*val = ret;
} else if (chip->gpio_chip.ngpio >= 24) {
int bank_shift = fls((chip->gpio_chip.ngpio - 1) / BANK_SZ);
ret = i2c_smbus_read_i2c_block_data(chip->client,
(reg << bank_shift) | REG_ADDR_AI,
NBANK(chip), val);
} else {
ret = i2c_smbus_read_word_data(chip->client, reg << 1);
val[0] = (u16)ret & 0xFF;
val[1] = (u16)ret >> 8;
}
if (ret < 0) {
dev_err(&chip->client->dev, "failed reading register\n");
return ret;
}
return 0;
}
static int pca953x_gpio_direction_input(struct gpio_chip *gc, unsigned off)
{
struct pca953x_chip *chip = to_pca(gc);
u8 reg_val;
int ret, offset = 0;
mutex_lock(&chip->i2c_lock);
reg_val = chip->reg_direction[off / BANK_SZ] | (1u << (off % BANK_SZ));
switch (chip->chip_type) {
case PCA953X_TYPE:
offset = PCA953X_DIRECTION;
break;
case PCA957X_TYPE:
offset = PCA957X_CFG;
break;
}
ret = pca953x_write_single(chip, offset, reg_val, off);
if (ret)
goto exit;
chip->reg_direction[off / BANK_SZ] = reg_val;
ret = 0;
exit:
mutex_unlock(&chip->i2c_lock);
return ret;
}
static int pca953x_gpio_direction_output(struct gpio_chip *gc,
unsigned off, int val)
{
struct pca953x_chip *chip = to_pca(gc);
u8 reg_val;
int ret, offset = 0;
mutex_lock(&chip->i2c_lock);
if (val)
reg_val = chip->reg_output[off / BANK_SZ]
| (1u << (off % BANK_SZ));
else
reg_val = chip->reg_output[off / BANK_SZ]
& ~(1u << (off % BANK_SZ));
switch (chip->chip_type) {
case PCA953X_TYPE:
offset = PCA953X_OUTPUT;
break;
case PCA957X_TYPE:
offset = PCA957X_OUT;
break;
}
ret = pca953x_write_single(chip, offset, reg_val, off);
if (ret)
goto exit;
chip->reg_output[off / BANK_SZ] = reg_val;
reg_val = chip->reg_direction[off / BANK_SZ] & ~(1u << (off % BANK_SZ));
switch (chip->chip_type) {
case PCA953X_TYPE:
offset = PCA953X_DIRECTION;
break;
case PCA957X_TYPE:
offset = PCA957X_CFG;
break;
}
ret = pca953x_write_single(chip, offset, reg_val, off);
if (ret)
goto exit;
chip->reg_direction[off / BANK_SZ] = reg_val;
ret = 0;
exit:
mutex_unlock(&chip->i2c_lock);
return ret;
}
static int pca953x_gpio_get_value(struct gpio_chip *gc, unsigned off)
{
struct pca953x_chip *chip = to_pca(gc);
u32 reg_val;
int ret, offset = 0;
mutex_lock(&chip->i2c_lock);
switch (chip->chip_type) {
case PCA953X_TYPE:
offset = PCA953X_INPUT;
break;
case PCA957X_TYPE:
offset = PCA957X_IN;
break;
}
ret = pca953x_read_single(chip, offset, &reg_val, off);
mutex_unlock(&chip->i2c_lock);
if (ret < 0) {
return 0;
}
return (reg_val & (1u << (off % BANK_SZ))) ? 1 : 0;
}
static void pca953x_gpio_set_value(struct gpio_chip *gc, unsigned off, int val)
{
struct pca953x_chip *chip = to_pca(gc);
u8 reg_val;
int ret, offset = 0;
mutex_lock(&chip->i2c_lock);
if (val)
reg_val = chip->reg_output[off / BANK_SZ]
| (1u << (off % BANK_SZ));
else
reg_val = chip->reg_output[off / BANK_SZ]
& ~(1u << (off % BANK_SZ));
switch (chip->chip_type) {
case PCA953X_TYPE:
offset = PCA953X_OUTPUT;
break;
case PCA957X_TYPE:
offset = PCA957X_OUT;
break;
}
ret = pca953x_write_single(chip, offset, reg_val, off);
if (ret)
goto exit;
chip->reg_output[off / BANK_SZ] = reg_val;
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
gc->can_sleep = true;
gc->base = chip->gpio_start;
gc->ngpio = gpios;
gc->label = chip->client->name;
gc->dev = &chip->client->dev;
gc->owner = THIS_MODULE;
gc->names = chip->names;
}
static void pca953x_irq_mask(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct pca953x_chip *chip = to_pca(gc);
chip->irq_mask[d->hwirq / BANK_SZ] &= ~(1 << (d->hwirq % BANK_SZ));
}
static void pca953x_irq_unmask(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct pca953x_chip *chip = to_pca(gc);
chip->irq_mask[d->hwirq / BANK_SZ] |= 1 << (d->hwirq % BANK_SZ);
}
static void pca953x_irq_bus_lock(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct pca953x_chip *chip = to_pca(gc);
mutex_lock(&chip->irq_lock);
}
static void pca953x_irq_bus_sync_unlock(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct pca953x_chip *chip = to_pca(gc);
u8 new_irqs;
int level, i;
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
struct pca953x_chip *chip = to_pca(gc);
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
int ret, i, offset = 0;
switch (chip->chip_type) {
case PCA953X_TYPE:
offset = PCA953X_INPUT;
break;
case PCA957X_TYPE:
offset = PCA957X_IN;
break;
}
ret = pca953x_read_regs(chip, offset, cur_stat);
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
const struct i2c_device_id *id,
int irq_base)
{
struct i2c_client *client = chip->client;
int ret, i, offset = 0;
if (client->irq && irq_base != -1
&& (id->driver_data & PCA_INT)) {
switch (chip->chip_type) {
case PCA953X_TYPE:
offset = PCA953X_INPUT;
break;
case PCA957X_TYPE:
offset = PCA957X_IN;
break;
}
ret = pca953x_read_regs(chip, offset, chip->irq_stat);
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
ret = gpiochip_irqchip_add(&chip->gpio_chip,
&pca953x_irq_chip,
irq_base,
handle_simple_irq,
IRQ_TYPE_NONE);
if (ret) {
dev_err(&client->dev,
"could not connect irqchip to gpiochip\n");
return ret;
}
gpiochip_set_chained_irqchip(&chip->gpio_chip,
&pca953x_irq_chip,
client->irq, NULL);
}
return 0;
}
static int pca953x_irq_setup(struct pca953x_chip *chip,
const struct i2c_device_id *id,
int irq_base)
{
struct i2c_client *client = chip->client;
if (irq_base != -1 && (id->driver_data & PCA_INT))
dev_warn(&client->dev, "interrupt support not compiled in\n");
return 0;
}
static int device_pca953x_init(struct pca953x_chip *chip, u32 invert)
{
int ret;
u8 val[MAX_BANK];
ret = pca953x_read_regs(chip, PCA953X_OUTPUT, chip->reg_output);
if (ret)
goto out;
ret = pca953x_read_regs(chip, PCA953X_DIRECTION,
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
ret = pca953x_read_regs(chip, PCA957X_OUT, chip->reg_output);
if (ret)
goto out;
ret = pca953x_read_regs(chip, PCA957X_CFG, chip->reg_direction);
if (ret)
goto out;
if (invert)
memset(val, 0xFF, NBANK(chip));
else
memset(val, 0, NBANK(chip));
pca953x_write_regs(chip, PCA957X_INVRT, val);
memset(val, 0x02, NBANK(chip));
pca953x_write_regs(chip, PCA957X_BKEN, val);
return 0;
out:
return ret;
}
static int pca953x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct pca953x_platform_data *pdata;
struct pca953x_chip *chip;
int irq_base = 0;
int ret;
u32 invert = 0;
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
chip->gpio_start = -1;
irq_base = 0;
}
chip->client = client;
chip->chip_type = id->driver_data & (PCA953X_TYPE | PCA957X_TYPE);
mutex_init(&chip->i2c_lock);
pca953x_setup_gpio(chip, id->driver_data & PCA_GPIO_MASK);
if (chip->chip_type == PCA953X_TYPE)
ret = device_pca953x_init(chip, invert);
else
ret = device_pca957x_init(chip, invert);
if (ret)
return ret;
ret = gpiochip_add(&chip->gpio_chip);
if (ret)
return ret;
ret = pca953x_irq_setup(chip, id, irq_base);
if (ret)
return ret;
if (pdata && pdata->setup) {
ret = pdata->setup(client, chip->gpio_chip.base,
chip->gpio_chip.ngpio, pdata->context);
if (ret < 0)
dev_warn(&client->dev, "setup failed, %d\n", ret);
}
i2c_set_clientdata(client, chip);
return 0;
}
static int pca953x_remove(struct i2c_client *client)
{
struct pca953x_platform_data *pdata = dev_get_platdata(&client->dev);
struct pca953x_chip *chip = i2c_get_clientdata(client);
int ret = 0;
if (pdata && pdata->teardown) {
ret = pdata->teardown(client, chip->gpio_chip.base,
chip->gpio_chip.ngpio, pdata->context);
if (ret < 0) {
dev_err(&client->dev, "%s failed, %d\n",
"teardown", ret);
return ret;
}
}
gpiochip_remove(&chip->gpio_chip);
return 0;
}
static int __init pca953x_init(void)
{
return i2c_add_driver(&pca953x_driver);
}
static void __exit pca953x_exit(void)
{
i2c_del_driver(&pca953x_driver);
}
