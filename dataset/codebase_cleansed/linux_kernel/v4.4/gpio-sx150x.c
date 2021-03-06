struct sx150x_chip *to_sx150x(struct gpio_chip *gc)
{
return container_of(gc, struct sx150x_chip, gpio_chip);
}
static s32 sx150x_i2c_write(struct i2c_client *client, u8 reg, u8 val)
{
s32 err = i2c_smbus_write_byte_data(client, reg, val);
if (err < 0)
dev_warn(&client->dev,
"i2c write fail: can't write %02x to %02x: %d\n",
val, reg, err);
return err;
}
static s32 sx150x_i2c_read(struct i2c_client *client, u8 reg, u8 *val)
{
s32 err = i2c_smbus_read_byte_data(client, reg);
if (err >= 0)
*val = err;
else
dev_warn(&client->dev,
"i2c read fail: can't read from %02x: %d\n",
reg, err);
return err;
}
static inline bool offset_is_oscio(struct sx150x_chip *chip, unsigned offset)
{
return (chip->dev_cfg->ngpios == offset);
}
static inline void sx150x_find_cfg(u8 offset, u8 width,
u8 *reg, u8 *mask, u8 *shift)
{
*reg -= offset * width / 8;
*mask = (1 << width) - 1;
*shift = (offset * width) % 8;
*mask <<= *shift;
}
static s32 sx150x_write_cfg(struct sx150x_chip *chip,
u8 offset, u8 width, u8 reg, u8 val)
{
u8 mask;
u8 data;
u8 shift;
s32 err;
sx150x_find_cfg(offset, width, &reg, &mask, &shift);
err = sx150x_i2c_read(chip->client, reg, &data);
if (err < 0)
return err;
data &= ~mask;
data |= (val << shift) & mask;
return sx150x_i2c_write(chip->client, reg, data);
}
static int sx150x_get_io(struct sx150x_chip *chip, unsigned offset)
{
u8 reg = chip->dev_cfg->reg_data;
u8 mask;
u8 data;
u8 shift;
s32 err;
sx150x_find_cfg(offset, 1, &reg, &mask, &shift);
err = sx150x_i2c_read(chip->client, reg, &data);
if (err >= 0)
err = (data & mask) != 0 ? 1 : 0;
return err;
}
static void sx150x_set_oscio(struct sx150x_chip *chip, int val)
{
sx150x_i2c_write(chip->client,
chip->dev_cfg->pri.x789.reg_clock,
(val ? 0x1f : 0x10));
}
static void sx150x_set_io(struct sx150x_chip *chip, unsigned offset, int val)
{
sx150x_write_cfg(chip,
offset,
1,
chip->dev_cfg->reg_data,
(val ? 1 : 0));
}
static int sx150x_io_input(struct sx150x_chip *chip, unsigned offset)
{
return sx150x_write_cfg(chip,
offset,
1,
chip->dev_cfg->reg_dir,
1);
}
static int sx150x_io_output(struct sx150x_chip *chip, unsigned offset, int val)
{
int err;
err = sx150x_write_cfg(chip,
offset,
1,
chip->dev_cfg->reg_data,
(val ? 1 : 0));
if (err >= 0)
err = sx150x_write_cfg(chip,
offset,
1,
chip->dev_cfg->reg_dir,
0);
return err;
}
static int sx150x_gpio_get(struct gpio_chip *gc, unsigned offset)
{
struct sx150x_chip *chip = to_sx150x(gc);
int status = -EINVAL;
if (!offset_is_oscio(chip, offset)) {
mutex_lock(&chip->lock);
status = sx150x_get_io(chip, offset);
mutex_unlock(&chip->lock);
}
return status;
}
static void sx150x_gpio_set(struct gpio_chip *gc, unsigned offset, int val)
{
struct sx150x_chip *chip = to_sx150x(gc);
mutex_lock(&chip->lock);
if (offset_is_oscio(chip, offset))
sx150x_set_oscio(chip, val);
else
sx150x_set_io(chip, offset, val);
mutex_unlock(&chip->lock);
}
static int sx150x_gpio_direction_input(struct gpio_chip *gc, unsigned offset)
{
struct sx150x_chip *chip = to_sx150x(gc);
int status = -EINVAL;
if (!offset_is_oscio(chip, offset)) {
mutex_lock(&chip->lock);
status = sx150x_io_input(chip, offset);
mutex_unlock(&chip->lock);
}
return status;
}
static int sx150x_gpio_direction_output(struct gpio_chip *gc,
unsigned offset,
int val)
{
struct sx150x_chip *chip = to_sx150x(gc);
int status = 0;
if (!offset_is_oscio(chip, offset)) {
mutex_lock(&chip->lock);
status = sx150x_io_output(chip, offset, val);
mutex_unlock(&chip->lock);
}
return status;
}
static void sx150x_irq_mask(struct irq_data *d)
{
struct sx150x_chip *chip = to_sx150x(irq_data_get_irq_chip_data(d));
unsigned n = d->hwirq;
chip->irq_masked |= (1 << n);
chip->irq_update = n;
}
static void sx150x_irq_unmask(struct irq_data *d)
{
struct sx150x_chip *chip = to_sx150x(irq_data_get_irq_chip_data(d));
unsigned n = d->hwirq;
chip->irq_masked &= ~(1 << n);
chip->irq_update = n;
}
static int sx150x_irq_set_type(struct irq_data *d, unsigned int flow_type)
{
struct sx150x_chip *chip = to_sx150x(irq_data_get_irq_chip_data(d));
unsigned n, val = 0;
if (flow_type & (IRQ_TYPE_LEVEL_HIGH | IRQ_TYPE_LEVEL_LOW))
return -EINVAL;
n = d->hwirq;
if (flow_type & IRQ_TYPE_EDGE_RISING)
val |= 0x1;
if (flow_type & IRQ_TYPE_EDGE_FALLING)
val |= 0x2;
chip->irq_sense &= ~(3UL << (n * 2));
chip->irq_sense |= val << (n * 2);
chip->irq_update = n;
return 0;
}
static irqreturn_t sx150x_irq_thread_fn(int irq, void *dev_id)
{
struct sx150x_chip *chip = (struct sx150x_chip *)dev_id;
unsigned nhandled = 0;
unsigned sub_irq;
unsigned n;
s32 err;
u8 val;
int i;
for (i = (chip->dev_cfg->ngpios / 8) - 1; i >= 0; --i) {
err = sx150x_i2c_read(chip->client,
chip->dev_cfg->reg_irq_src - i,
&val);
if (err < 0)
continue;
sx150x_i2c_write(chip->client,
chip->dev_cfg->reg_irq_src - i,
val);
for (n = 0; n < 8; ++n) {
if (val & (1 << n)) {
sub_irq = irq_find_mapping(
chip->gpio_chip.irqdomain,
(i * 8) + n);
handle_nested_irq(sub_irq);
++nhandled;
}
}
}
return (nhandled > 0 ? IRQ_HANDLED : IRQ_NONE);
}
static void sx150x_irq_bus_lock(struct irq_data *d)
{
struct sx150x_chip *chip = to_sx150x(irq_data_get_irq_chip_data(d));
mutex_lock(&chip->lock);
}
static void sx150x_irq_bus_sync_unlock(struct irq_data *d)
{
struct sx150x_chip *chip = to_sx150x(irq_data_get_irq_chip_data(d));
unsigned n;
if (chip->irq_update == NO_UPDATE_PENDING)
goto out;
n = chip->irq_update;
chip->irq_update = NO_UPDATE_PENDING;
if (chip->dev_sense == chip->irq_sense &&
chip->dev_masked == chip->irq_masked)
goto out;
chip->dev_sense = chip->irq_sense;
chip->dev_masked = chip->irq_masked;
if (chip->irq_masked & (1 << n)) {
sx150x_write_cfg(chip, n, 1, chip->dev_cfg->reg_irq_mask, 1);
sx150x_write_cfg(chip, n, 2, chip->dev_cfg->reg_sense, 0);
} else {
sx150x_write_cfg(chip, n, 1, chip->dev_cfg->reg_irq_mask, 0);
sx150x_write_cfg(chip, n, 2, chip->dev_cfg->reg_sense,
chip->irq_sense >> (n * 2));
}
out:
mutex_unlock(&chip->lock);
}
static void sx150x_init_chip(struct sx150x_chip *chip,
struct i2c_client *client,
kernel_ulong_t driver_data,
struct sx150x_platform_data *pdata)
{
mutex_init(&chip->lock);
chip->client = client;
chip->dev_cfg = &sx150x_devices[driver_data];
chip->gpio_chip.dev = &client->dev;
chip->gpio_chip.label = client->name;
chip->gpio_chip.direction_input = sx150x_gpio_direction_input;
chip->gpio_chip.direction_output = sx150x_gpio_direction_output;
chip->gpio_chip.get = sx150x_gpio_get;
chip->gpio_chip.set = sx150x_gpio_set;
chip->gpio_chip.base = pdata->gpio_base;
chip->gpio_chip.can_sleep = true;
chip->gpio_chip.ngpio = chip->dev_cfg->ngpios;
#ifdef CONFIG_OF_GPIO
chip->gpio_chip.of_node = client->dev.of_node;
chip->gpio_chip.of_gpio_n_cells = 2;
#endif
if (pdata->oscio_is_gpo)
++chip->gpio_chip.ngpio;
chip->irq_chip.name = client->name;
chip->irq_chip.irq_mask = sx150x_irq_mask;
chip->irq_chip.irq_unmask = sx150x_irq_unmask;
chip->irq_chip.irq_set_type = sx150x_irq_set_type;
chip->irq_chip.irq_bus_lock = sx150x_irq_bus_lock;
chip->irq_chip.irq_bus_sync_unlock = sx150x_irq_bus_sync_unlock;
chip->irq_summary = -1;
chip->irq_base = -1;
chip->irq_masked = ~0;
chip->irq_sense = 0;
chip->dev_masked = ~0;
chip->dev_sense = 0;
chip->irq_update = NO_UPDATE_PENDING;
}
static int sx150x_init_io(struct sx150x_chip *chip, u8 base, u16 cfg)
{
int err = 0;
unsigned n;
for (n = 0; err >= 0 && n < (chip->dev_cfg->ngpios / 8); ++n)
err = sx150x_i2c_write(chip->client, base - n, cfg >> (n * 8));
return err;
}
static int sx150x_reset(struct sx150x_chip *chip)
{
int err;
err = i2c_smbus_write_byte_data(chip->client,
chip->dev_cfg->pri.x789.reg_reset,
0x12);
if (err < 0)
return err;
err = i2c_smbus_write_byte_data(chip->client,
chip->dev_cfg->pri.x789.reg_reset,
0x34);
return err;
}
static int sx150x_init_hw(struct sx150x_chip *chip,
struct sx150x_platform_data *pdata)
{
int err = 0;
if (pdata->reset_during_probe) {
err = sx150x_reset(chip);
if (err < 0)
return err;
}
if (chip->dev_cfg->model == SX150X_789)
err = sx150x_i2c_write(chip->client,
chip->dev_cfg->pri.x789.reg_misc,
0x01);
else
err = sx150x_i2c_write(chip->client,
chip->dev_cfg->pri.x456.reg_advance,
0x04);
if (err < 0)
return err;
err = sx150x_init_io(chip, chip->dev_cfg->reg_pullup,
pdata->io_pullup_ena);
if (err < 0)
return err;
err = sx150x_init_io(chip, chip->dev_cfg->reg_pulldn,
pdata->io_pulldn_ena);
if (err < 0)
return err;
if (chip->dev_cfg->model == SX150X_789) {
err = sx150x_init_io(chip,
chip->dev_cfg->pri.x789.reg_drain,
pdata->io_open_drain_ena);
if (err < 0)
return err;
err = sx150x_init_io(chip,
chip->dev_cfg->pri.x789.reg_polarity,
pdata->io_polarity);
if (err < 0)
return err;
} else {
err = sx150x_init_io(chip,
chip->dev_cfg->pri.x456.reg_pld_mode,
0);
if (err < 0)
return err;
}
if (pdata->oscio_is_gpo)
sx150x_set_oscio(chip, 0);
return err;
}
static int sx150x_install_irq_chip(struct sx150x_chip *chip,
int irq_summary,
int irq_base)
{
int err;
chip->irq_summary = irq_summary;
chip->irq_base = irq_base;
err = gpiochip_irqchip_add(&chip->gpio_chip,
&chip->irq_chip, chip->irq_base,
handle_edge_irq, IRQ_TYPE_EDGE_BOTH);
if (err) {
dev_err(&chip->client->dev,
"could not connect irqchip to gpiochip\n");
return err;
}
err = devm_request_threaded_irq(&chip->client->dev,
irq_summary, NULL, sx150x_irq_thread_fn,
IRQF_ONESHOT | IRQF_SHARED | IRQF_TRIGGER_FALLING,
chip->irq_chip.name, chip);
if (err < 0) {
chip->irq_summary = -1;
chip->irq_base = -1;
}
return err;
}
static int sx150x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
static const u32 i2c_funcs = I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WRITE_WORD_DATA;
struct sx150x_platform_data *pdata;
struct sx150x_chip *chip;
int rc;
pdata = dev_get_platdata(&client->dev);
if (!pdata)
return -EINVAL;
if (!i2c_check_functionality(client->adapter, i2c_funcs))
return -ENOSYS;
chip = devm_kzalloc(&client->dev,
sizeof(struct sx150x_chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
sx150x_init_chip(chip, client, id->driver_data, pdata);
rc = sx150x_init_hw(chip, pdata);
if (rc < 0)
return rc;
rc = gpiochip_add(&chip->gpio_chip);
if (rc)
return rc;
if (pdata->irq_summary >= 0) {
rc = sx150x_install_irq_chip(chip,
pdata->irq_summary,
pdata->irq_base);
if (rc < 0)
goto probe_fail_post_gpiochip_add;
}
i2c_set_clientdata(client, chip);
return 0;
probe_fail_post_gpiochip_add:
gpiochip_remove(&chip->gpio_chip);
return rc;
}
static int sx150x_remove(struct i2c_client *client)
{
struct sx150x_chip *chip;
chip = i2c_get_clientdata(client);
gpiochip_remove(&chip->gpio_chip);
return 0;
}
static int __init sx150x_init(void)
{
return i2c_add_driver(&sx150x_driver);
}
static void __exit sx150x_exit(void)
{
return i2c_del_driver(&sx150x_driver);
}
