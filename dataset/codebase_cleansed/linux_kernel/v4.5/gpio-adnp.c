static int adnp_read(struct adnp *adnp, unsigned offset, uint8_t *value)
{
int err;
err = i2c_smbus_read_byte_data(adnp->client, offset);
if (err < 0) {
dev_err(adnp->gpio.parent, "%s failed: %d\n",
"i2c_smbus_read_byte_data()", err);
return err;
}
*value = err;
return 0;
}
static int adnp_write(struct adnp *adnp, unsigned offset, uint8_t value)
{
int err;
err = i2c_smbus_write_byte_data(adnp->client, offset, value);
if (err < 0) {
dev_err(adnp->gpio.parent, "%s failed: %d\n",
"i2c_smbus_write_byte_data()", err);
return err;
}
return 0;
}
static int adnp_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct adnp *adnp = gpiochip_get_data(chip);
unsigned int reg = offset >> adnp->reg_shift;
unsigned int pos = offset & 7;
u8 value;
int err;
err = adnp_read(adnp, GPIO_PLR(adnp) + reg, &value);
if (err < 0)
return err;
return (value & BIT(pos)) ? 1 : 0;
}
static void __adnp_gpio_set(struct adnp *adnp, unsigned offset, int value)
{
unsigned int reg = offset >> adnp->reg_shift;
unsigned int pos = offset & 7;
int err;
u8 val;
err = adnp_read(adnp, GPIO_PLR(adnp) + reg, &val);
if (err < 0)
return;
if (value)
val |= BIT(pos);
else
val &= ~BIT(pos);
adnp_write(adnp, GPIO_PLR(adnp) + reg, val);
}
static void adnp_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct adnp *adnp = gpiochip_get_data(chip);
mutex_lock(&adnp->i2c_lock);
__adnp_gpio_set(adnp, offset, value);
mutex_unlock(&adnp->i2c_lock);
}
static int adnp_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct adnp *adnp = gpiochip_get_data(chip);
unsigned int reg = offset >> adnp->reg_shift;
unsigned int pos = offset & 7;
u8 value;
int err;
mutex_lock(&adnp->i2c_lock);
err = adnp_read(adnp, GPIO_DDR(adnp) + reg, &value);
if (err < 0)
goto out;
value &= ~BIT(pos);
err = adnp_write(adnp, GPIO_DDR(adnp) + reg, value);
if (err < 0)
goto out;
err = adnp_read(adnp, GPIO_DDR(adnp) + reg, &value);
if (err < 0)
goto out;
if (err & BIT(pos))
err = -EACCES;
err = 0;
out:
mutex_unlock(&adnp->i2c_lock);
return err;
}
static int adnp_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
struct adnp *adnp = gpiochip_get_data(chip);
unsigned int reg = offset >> adnp->reg_shift;
unsigned int pos = offset & 7;
int err;
u8 val;
mutex_lock(&adnp->i2c_lock);
err = adnp_read(adnp, GPIO_DDR(adnp) + reg, &val);
if (err < 0)
goto out;
val |= BIT(pos);
err = adnp_write(adnp, GPIO_DDR(adnp) + reg, val);
if (err < 0)
goto out;
err = adnp_read(adnp, GPIO_DDR(adnp) + reg, &val);
if (err < 0)
goto out;
if (!(val & BIT(pos))) {
err = -EPERM;
goto out;
}
__adnp_gpio_set(adnp, offset, value);
err = 0;
out:
mutex_unlock(&adnp->i2c_lock);
return err;
}
static void adnp_gpio_dbg_show(struct seq_file *s, struct gpio_chip *chip)
{
struct adnp *adnp = gpiochip_get_data(chip);
unsigned int num_regs = 1 << adnp->reg_shift, i, j;
int err;
for (i = 0; i < num_regs; i++) {
u8 ddr, plr, ier, isr;
mutex_lock(&adnp->i2c_lock);
err = adnp_read(adnp, GPIO_DDR(adnp) + i, &ddr);
if (err < 0) {
mutex_unlock(&adnp->i2c_lock);
return;
}
err = adnp_read(adnp, GPIO_PLR(adnp) + i, &plr);
if (err < 0) {
mutex_unlock(&adnp->i2c_lock);
return;
}
err = adnp_read(adnp, GPIO_IER(adnp) + i, &ier);
if (err < 0) {
mutex_unlock(&adnp->i2c_lock);
return;
}
err = adnp_read(adnp, GPIO_ISR(adnp) + i, &isr);
if (err < 0) {
mutex_unlock(&adnp->i2c_lock);
return;
}
mutex_unlock(&adnp->i2c_lock);
for (j = 0; j < 8; j++) {
unsigned int bit = (i << adnp->reg_shift) + j;
const char *direction = "input ";
const char *level = "low ";
const char *interrupt = "disabled";
const char *pending = "";
if (ddr & BIT(j))
direction = "output";
if (plr & BIT(j))
level = "high";
if (ier & BIT(j))
interrupt = "enabled ";
if (isr & BIT(j))
pending = "pending";
seq_printf(s, "%2u: %s %s IRQ %s %s\n", bit,
direction, level, interrupt, pending);
}
}
}
static int adnp_gpio_setup(struct adnp *adnp, unsigned int num_gpios)
{
struct gpio_chip *chip = &adnp->gpio;
int err;
adnp->reg_shift = get_count_order(num_gpios) - 3;
chip->direction_input = adnp_gpio_direction_input;
chip->direction_output = adnp_gpio_direction_output;
chip->get = adnp_gpio_get;
chip->set = adnp_gpio_set;
chip->can_sleep = true;
if (IS_ENABLED(CONFIG_DEBUG_FS))
chip->dbg_show = adnp_gpio_dbg_show;
chip->base = -1;
chip->ngpio = num_gpios;
chip->label = adnp->client->name;
chip->parent = &adnp->client->dev;
chip->of_node = chip->parent->of_node;
chip->owner = THIS_MODULE;
err = gpiochip_add_data(chip, adnp);
if (err)
return err;
return 0;
}
static irqreturn_t adnp_irq(int irq, void *data)
{
struct adnp *adnp = data;
unsigned int num_regs, i;
num_regs = 1 << adnp->reg_shift;
for (i = 0; i < num_regs; i++) {
unsigned int base = i << adnp->reg_shift, bit;
u8 changed, level, isr, ier;
unsigned long pending;
int err;
mutex_lock(&adnp->i2c_lock);
err = adnp_read(adnp, GPIO_PLR(adnp) + i, &level);
if (err < 0) {
mutex_unlock(&adnp->i2c_lock);
continue;
}
err = adnp_read(adnp, GPIO_ISR(adnp) + i, &isr);
if (err < 0) {
mutex_unlock(&adnp->i2c_lock);
continue;
}
err = adnp_read(adnp, GPIO_IER(adnp) + i, &ier);
if (err < 0) {
mutex_unlock(&adnp->i2c_lock);
continue;
}
mutex_unlock(&adnp->i2c_lock);
changed = level ^ adnp->irq_level[i];
pending = changed & ((adnp->irq_fall[i] & ~level) |
(adnp->irq_rise[i] & level));
pending |= (adnp->irq_high[i] & level) |
(adnp->irq_low[i] & ~level);
pending &= isr & ier;
for_each_set_bit(bit, &pending, 8) {
unsigned int child_irq;
child_irq = irq_find_mapping(adnp->gpio.irqdomain,
base + bit);
handle_nested_irq(child_irq);
}
}
return IRQ_HANDLED;
}
static void adnp_irq_mask(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct adnp *adnp = gpiochip_get_data(gc);
unsigned int reg = d->hwirq >> adnp->reg_shift;
unsigned int pos = d->hwirq & 7;
adnp->irq_enable[reg] &= ~BIT(pos);
}
static void adnp_irq_unmask(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct adnp *adnp = gpiochip_get_data(gc);
unsigned int reg = d->hwirq >> adnp->reg_shift;
unsigned int pos = d->hwirq & 7;
adnp->irq_enable[reg] |= BIT(pos);
}
static int adnp_irq_set_type(struct irq_data *d, unsigned int type)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct adnp *adnp = gpiochip_get_data(gc);
unsigned int reg = d->hwirq >> adnp->reg_shift;
unsigned int pos = d->hwirq & 7;
if (type & IRQ_TYPE_EDGE_RISING)
adnp->irq_rise[reg] |= BIT(pos);
else
adnp->irq_rise[reg] &= ~BIT(pos);
if (type & IRQ_TYPE_EDGE_FALLING)
adnp->irq_fall[reg] |= BIT(pos);
else
adnp->irq_fall[reg] &= ~BIT(pos);
if (type & IRQ_TYPE_LEVEL_HIGH)
adnp->irq_high[reg] |= BIT(pos);
else
adnp->irq_high[reg] &= ~BIT(pos);
if (type & IRQ_TYPE_LEVEL_LOW)
adnp->irq_low[reg] |= BIT(pos);
else
adnp->irq_low[reg] &= ~BIT(pos);
return 0;
}
static void adnp_irq_bus_lock(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct adnp *adnp = gpiochip_get_data(gc);
mutex_lock(&adnp->irq_lock);
}
static void adnp_irq_bus_unlock(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct adnp *adnp = gpiochip_get_data(gc);
unsigned int num_regs = 1 << adnp->reg_shift, i;
mutex_lock(&adnp->i2c_lock);
for (i = 0; i < num_regs; i++)
adnp_write(adnp, GPIO_IER(adnp) + i, adnp->irq_enable[i]);
mutex_unlock(&adnp->i2c_lock);
mutex_unlock(&adnp->irq_lock);
}
static int adnp_irq_setup(struct adnp *adnp)
{
unsigned int num_regs = 1 << adnp->reg_shift, i;
struct gpio_chip *chip = &adnp->gpio;
int err;
mutex_init(&adnp->irq_lock);
adnp->irq_enable = devm_kzalloc(chip->parent, num_regs * 6,
GFP_KERNEL);
if (!adnp->irq_enable)
return -ENOMEM;
adnp->irq_level = adnp->irq_enable + (num_regs * 1);
adnp->irq_rise = adnp->irq_enable + (num_regs * 2);
adnp->irq_fall = adnp->irq_enable + (num_regs * 3);
adnp->irq_high = adnp->irq_enable + (num_regs * 4);
adnp->irq_low = adnp->irq_enable + (num_regs * 5);
for (i = 0; i < num_regs; i++) {
err = adnp_read(adnp, GPIO_PLR(adnp) + i, &adnp->irq_level[i]);
if (err < 0)
return err;
err = adnp_write(adnp, GPIO_IER(adnp) + i, 0);
if (err < 0)
return err;
adnp->irq_enable[i] = 0x00;
}
err = devm_request_threaded_irq(chip->parent, adnp->client->irq,
NULL, adnp_irq,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
dev_name(chip->parent), adnp);
if (err != 0) {
dev_err(chip->parent, "can't request IRQ#%d: %d\n",
adnp->client->irq, err);
return err;
}
err = gpiochip_irqchip_add(chip,
&adnp_irq_chip,
0,
handle_simple_irq,
IRQ_TYPE_NONE);
if (err) {
dev_err(chip->parent,
"could not connect irqchip to gpiochip\n");
return err;
}
return 0;
}
static int adnp_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device_node *np = client->dev.of_node;
struct adnp *adnp;
u32 num_gpios;
int err;
err = of_property_read_u32(np, "nr-gpios", &num_gpios);
if (err < 0)
return err;
client->irq = irq_of_parse_and_map(np, 0);
if (!client->irq)
return -EPROBE_DEFER;
adnp = devm_kzalloc(&client->dev, sizeof(*adnp), GFP_KERNEL);
if (!adnp)
return -ENOMEM;
mutex_init(&adnp->i2c_lock);
adnp->client = client;
err = adnp_gpio_setup(adnp, num_gpios);
if (err)
return err;
if (of_find_property(np, "interrupt-controller", NULL)) {
err = adnp_irq_setup(adnp);
if (err)
return err;
}
i2c_set_clientdata(client, adnp);
return 0;
}
static int adnp_i2c_remove(struct i2c_client *client)
{
struct adnp *adnp = i2c_get_clientdata(client);
gpiochip_remove(&adnp->gpio);
return 0;
}
