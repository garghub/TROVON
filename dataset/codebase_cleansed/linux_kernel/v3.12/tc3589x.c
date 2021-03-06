int tc3589x_reg_read(struct tc3589x *tc3589x, u8 reg)
{
int ret;
ret = i2c_smbus_read_byte_data(tc3589x->i2c, reg);
if (ret < 0)
dev_err(tc3589x->dev, "failed to read reg %#x: %d\n",
reg, ret);
return ret;
}
int tc3589x_reg_write(struct tc3589x *tc3589x, u8 reg, u8 data)
{
int ret;
ret = i2c_smbus_write_byte_data(tc3589x->i2c, reg, data);
if (ret < 0)
dev_err(tc3589x->dev, "failed to write reg %#x: %d\n",
reg, ret);
return ret;
}
int tc3589x_block_read(struct tc3589x *tc3589x, u8 reg, u8 length, u8 *values)
{
int ret;
ret = i2c_smbus_read_i2c_block_data(tc3589x->i2c, reg, length, values);
if (ret < 0)
dev_err(tc3589x->dev, "failed to read regs %#x: %d\n",
reg, ret);
return ret;
}
int tc3589x_block_write(struct tc3589x *tc3589x, u8 reg, u8 length,
const u8 *values)
{
int ret;
ret = i2c_smbus_write_i2c_block_data(tc3589x->i2c, reg, length,
values);
if (ret < 0)
dev_err(tc3589x->dev, "failed to write regs %#x: %d\n",
reg, ret);
return ret;
}
int tc3589x_set_bits(struct tc3589x *tc3589x, u8 reg, u8 mask, u8 val)
{
int ret;
mutex_lock(&tc3589x->lock);
ret = tc3589x_reg_read(tc3589x, reg);
if (ret < 0)
goto out;
ret &= ~mask;
ret |= val;
ret = tc3589x_reg_write(tc3589x, reg, ret);
out:
mutex_unlock(&tc3589x->lock);
return ret;
}
static irqreturn_t tc3589x_irq(int irq, void *data)
{
struct tc3589x *tc3589x = data;
int status;
again:
status = tc3589x_reg_read(tc3589x, TC3589x_IRQST);
if (status < 0)
return IRQ_NONE;
while (status) {
int bit = __ffs(status);
int virq = irq_create_mapping(tc3589x->domain, bit);
handle_nested_irq(virq);
status &= ~(1 << bit);
}
status = tc3589x_reg_read(tc3589x, TC3589x_IRQST);
if (status)
goto again;
return IRQ_HANDLED;
}
static int tc3589x_irq_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hwirq)
{
struct tc3589x *tc3589x = d->host_data;
irq_set_chip_data(virq, tc3589x);
irq_set_chip_and_handler(virq, &dummy_irq_chip,
handle_edge_irq);
irq_set_nested_thread(virq, 1);
#ifdef CONFIG_ARM
set_irq_flags(virq, IRQF_VALID);
#else
irq_set_noprobe(virq);
#endif
return 0;
}
static void tc3589x_irq_unmap(struct irq_domain *d, unsigned int virq)
{
#ifdef CONFIG_ARM
set_irq_flags(virq, 0);
#endif
irq_set_chip_and_handler(virq, NULL, NULL);
irq_set_chip_data(virq, NULL);
}
static int tc3589x_irq_init(struct tc3589x *tc3589x, struct device_node *np)
{
int base = tc3589x->irq_base;
tc3589x->domain = irq_domain_add_simple(
np, TC3589x_NR_INTERNAL_IRQS, base,
&tc3589x_irq_ops, tc3589x);
if (!tc3589x->domain) {
dev_err(tc3589x->dev, "Failed to create irqdomain\n");
return -ENOSYS;
}
return 0;
}
static int tc3589x_chip_init(struct tc3589x *tc3589x)
{
int manf, ver, ret;
manf = tc3589x_reg_read(tc3589x, TC3589x_MANFCODE);
if (manf < 0)
return manf;
ver = tc3589x_reg_read(tc3589x, TC3589x_VERSION);
if (ver < 0)
return ver;
if (manf != TC3589x_MANFCODE_MAGIC) {
dev_err(tc3589x->dev, "unknown manufacturer: %#x\n", manf);
return -EINVAL;
}
dev_info(tc3589x->dev, "manufacturer: %#x, version: %#x\n", manf, ver);
ret = tc3589x_reg_write(tc3589x, TC3589x_RSTCTRL,
TC3589x_RSTCTRL_TIMRST
| TC3589x_RSTCTRL_ROTRST
| TC3589x_RSTCTRL_KBDRST);
if (ret < 0)
return ret;
return tc3589x_reg_write(tc3589x, TC3589x_RSTINTCLR, 0x1);
}
static int tc3589x_device_init(struct tc3589x *tc3589x)
{
int ret = 0;
unsigned int blocks = tc3589x->pdata->block;
if (blocks & TC3589x_BLOCK_GPIO) {
ret = mfd_add_devices(tc3589x->dev, -1, tc3589x_dev_gpio,
ARRAY_SIZE(tc3589x_dev_gpio), NULL,
tc3589x->irq_base, tc3589x->domain);
if (ret) {
dev_err(tc3589x->dev, "failed to add gpio child\n");
return ret;
}
dev_info(tc3589x->dev, "added gpio block\n");
}
if (blocks & TC3589x_BLOCK_KEYPAD) {
ret = mfd_add_devices(tc3589x->dev, -1, tc3589x_dev_keypad,
ARRAY_SIZE(tc3589x_dev_keypad), NULL,
tc3589x->irq_base, tc3589x->domain);
if (ret) {
dev_err(tc3589x->dev, "failed to keypad child\n");
return ret;
}
dev_info(tc3589x->dev, "added keypad block\n");
}
return ret;
}
static int tc3589x_of_probe(struct device_node *np,
struct tc3589x_platform_data *pdata)
{
struct device_node *child;
for_each_child_of_node(np, child) {
if (!strcmp(child->name, "tc3589x_gpio")) {
pdata->block |= TC3589x_BLOCK_GPIO;
}
if (!strcmp(child->name, "tc3589x_keypad")) {
pdata->block |= TC3589x_BLOCK_KEYPAD;
}
}
return 0;
}
static int tc3589x_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct tc3589x_platform_data *pdata = dev_get_platdata(&i2c->dev);
struct device_node *np = i2c->dev.of_node;
struct tc3589x *tc3589x;
int ret;
if (!pdata) {
if (np) {
pdata = devm_kzalloc(&i2c->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
ret = tc3589x_of_probe(np, pdata);
if (ret)
return ret;
}
else {
dev_err(&i2c->dev, "No platform data or DT found\n");
return -EINVAL;
}
}
if (!i2c_check_functionality(i2c->adapter, I2C_FUNC_SMBUS_BYTE_DATA
| I2C_FUNC_SMBUS_I2C_BLOCK))
return -EIO;
tc3589x = devm_kzalloc(&i2c->dev, sizeof(struct tc3589x),
GFP_KERNEL);
if (!tc3589x)
return -ENOMEM;
mutex_init(&tc3589x->lock);
tc3589x->dev = &i2c->dev;
tc3589x->i2c = i2c;
tc3589x->pdata = pdata;
tc3589x->irq_base = pdata->irq_base;
tc3589x->num_gpio = id->driver_data;
i2c_set_clientdata(i2c, tc3589x);
ret = tc3589x_chip_init(tc3589x);
if (ret)
return ret;
ret = tc3589x_irq_init(tc3589x, np);
if (ret)
return ret;
ret = request_threaded_irq(tc3589x->i2c->irq, NULL, tc3589x_irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"tc3589x", tc3589x);
if (ret) {
dev_err(tc3589x->dev, "failed to request IRQ: %d\n", ret);
return ret;
}
ret = tc3589x_device_init(tc3589x);
if (ret) {
dev_err(tc3589x->dev, "failed to add child devices\n");
return ret;
}
return 0;
}
static int tc3589x_remove(struct i2c_client *client)
{
struct tc3589x *tc3589x = i2c_get_clientdata(client);
mfd_remove_devices(tc3589x->dev);
return 0;
}
static int tc3589x_suspend(struct device *dev)
{
struct tc3589x *tc3589x = dev_get_drvdata(dev);
struct i2c_client *client = tc3589x->i2c;
int ret = 0;
if (!device_may_wakeup(&client->dev))
ret = tc3589x_reg_write(tc3589x, TC3589x_CLKMODE,
TC3589x_CLKMODE_MODCTL_SLEEP);
return ret;
}
static int tc3589x_resume(struct device *dev)
{
struct tc3589x *tc3589x = dev_get_drvdata(dev);
struct i2c_client *client = tc3589x->i2c;
int ret = 0;
if (!device_may_wakeup(&client->dev))
ret = tc3589x_reg_write(tc3589x, TC3589x_CLKMODE,
TC3589x_CLKMODE_MODCTL_OPERATION);
return ret;
}
static int __init tc3589x_init(void)
{
return i2c_add_driver(&tc3589x_driver);
}
static void __exit tc3589x_exit(void)
{
i2c_del_driver(&tc3589x_driver);
}
