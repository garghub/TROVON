static inline struct tps6586x *dev_to_tps6586x(struct device *dev)
{
return i2c_get_clientdata(to_i2c_client(dev));
}
int tps6586x_write(struct device *dev, int reg, uint8_t val)
{
struct tps6586x *tps6586x = dev_to_tps6586x(dev);
return regmap_write(tps6586x->regmap, reg, val);
}
int tps6586x_writes(struct device *dev, int reg, int len, uint8_t *val)
{
struct tps6586x *tps6586x = dev_to_tps6586x(dev);
return regmap_bulk_write(tps6586x->regmap, reg, val, len);
}
int tps6586x_read(struct device *dev, int reg, uint8_t *val)
{
struct tps6586x *tps6586x = dev_to_tps6586x(dev);
unsigned int rval;
int ret;
ret = regmap_read(tps6586x->regmap, reg, &rval);
if (!ret)
*val = rval;
return ret;
}
int tps6586x_reads(struct device *dev, int reg, int len, uint8_t *val)
{
struct tps6586x *tps6586x = dev_to_tps6586x(dev);
return regmap_bulk_read(tps6586x->regmap, reg, val, len);
}
int tps6586x_set_bits(struct device *dev, int reg, uint8_t bit_mask)
{
struct tps6586x *tps6586x = dev_to_tps6586x(dev);
return regmap_update_bits(tps6586x->regmap, reg, bit_mask, bit_mask);
}
int tps6586x_clr_bits(struct device *dev, int reg, uint8_t bit_mask)
{
struct tps6586x *tps6586x = dev_to_tps6586x(dev);
return regmap_update_bits(tps6586x->regmap, reg, bit_mask, 0);
}
int tps6586x_update(struct device *dev, int reg, uint8_t val, uint8_t mask)
{
struct tps6586x *tps6586x = dev_to_tps6586x(dev);
return regmap_update_bits(tps6586x->regmap, reg, mask, val);
}
static int __remove_subdev(struct device *dev, void *unused)
{
platform_device_unregister(to_platform_device(dev));
return 0;
}
static int tps6586x_remove_subdevs(struct tps6586x *tps6586x)
{
return device_for_each_child(tps6586x->dev, NULL, __remove_subdev);
}
static void tps6586x_irq_lock(struct irq_data *data)
{
struct tps6586x *tps6586x = irq_data_get_irq_chip_data(data);
mutex_lock(&tps6586x->irq_lock);
}
static void tps6586x_irq_enable(struct irq_data *irq_data)
{
struct tps6586x *tps6586x = irq_data_get_irq_chip_data(irq_data);
unsigned int __irq = irq_data->irq - tps6586x->irq_base;
const struct tps6586x_irq_data *data = &tps6586x_irqs[__irq];
tps6586x->mask_reg[data->mask_reg] &= ~data->mask_mask;
tps6586x->irq_en |= (1 << __irq);
}
static void tps6586x_irq_disable(struct irq_data *irq_data)
{
struct tps6586x *tps6586x = irq_data_get_irq_chip_data(irq_data);
unsigned int __irq = irq_data->irq - tps6586x->irq_base;
const struct tps6586x_irq_data *data = &tps6586x_irqs[__irq];
tps6586x->mask_reg[data->mask_reg] |= data->mask_mask;
tps6586x->irq_en &= ~(1 << __irq);
}
static void tps6586x_irq_sync_unlock(struct irq_data *data)
{
struct tps6586x *tps6586x = irq_data_get_irq_chip_data(data);
int i;
for (i = 0; i < ARRAY_SIZE(tps6586x->mask_reg); i++) {
int ret;
ret = tps6586x_write(tps6586x->dev,
TPS6586X_INT_MASK1 + i,
tps6586x->mask_reg[i]);
WARN_ON(ret);
}
mutex_unlock(&tps6586x->irq_lock);
}
static irqreturn_t tps6586x_irq(int irq, void *data)
{
struct tps6586x *tps6586x = data;
u32 acks;
int ret = 0;
ret = tps6586x_reads(tps6586x->dev, TPS6586X_INT_ACK1,
sizeof(acks), (uint8_t *)&acks);
if (ret < 0) {
dev_err(tps6586x->dev, "failed to read interrupt status\n");
return IRQ_NONE;
}
acks = le32_to_cpu(acks);
while (acks) {
int i = __ffs(acks);
if (tps6586x->irq_en & (1 << i))
handle_nested_irq(tps6586x->irq_base + i);
acks &= ~(1 << i);
}
return IRQ_HANDLED;
}
static int __devinit tps6586x_irq_init(struct tps6586x *tps6586x, int irq,
int irq_base)
{
int i, ret;
u8 tmp[4];
if (!irq_base) {
dev_warn(tps6586x->dev, "No interrupt support on IRQ base\n");
return -EINVAL;
}
mutex_init(&tps6586x->irq_lock);
for (i = 0; i < 5; i++) {
tps6586x->mask_reg[i] = 0xff;
tps6586x_write(tps6586x->dev, TPS6586X_INT_MASK1 + i, 0xff);
}
tps6586x_reads(tps6586x->dev, TPS6586X_INT_ACK1, sizeof(tmp), tmp);
tps6586x->irq_base = irq_base;
tps6586x->irq_chip.name = "tps6586x";
tps6586x->irq_chip.irq_enable = tps6586x_irq_enable;
tps6586x->irq_chip.irq_disable = tps6586x_irq_disable;
tps6586x->irq_chip.irq_bus_lock = tps6586x_irq_lock;
tps6586x->irq_chip.irq_bus_sync_unlock = tps6586x_irq_sync_unlock;
for (i = 0; i < ARRAY_SIZE(tps6586x_irqs); i++) {
int __irq = i + tps6586x->irq_base;
irq_set_chip_data(__irq, tps6586x);
irq_set_chip_and_handler(__irq, &tps6586x->irq_chip,
handle_simple_irq);
irq_set_nested_thread(__irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(__irq, IRQF_VALID);
#endif
}
ret = request_threaded_irq(irq, NULL, tps6586x_irq, IRQF_ONESHOT,
"tps6586x", tps6586x);
if (!ret) {
device_init_wakeup(tps6586x->dev, 1);
enable_irq_wake(irq);
}
return ret;
}
static int __devinit tps6586x_add_subdevs(struct tps6586x *tps6586x,
struct tps6586x_platform_data *pdata)
{
struct tps6586x_subdev_info *subdev;
struct platform_device *pdev;
int i, ret = 0;
for (i = 0; i < pdata->num_subdevs; i++) {
subdev = &pdata->subdevs[i];
pdev = platform_device_alloc(subdev->name, subdev->id);
if (!pdev) {
ret = -ENOMEM;
goto failed;
}
pdev->dev.parent = tps6586x->dev;
pdev->dev.platform_data = subdev->platform_data;
pdev->dev.of_node = subdev->of_node;
ret = platform_device_add(pdev);
if (ret) {
platform_device_put(pdev);
goto failed;
}
}
return 0;
failed:
tps6586x_remove_subdevs(tps6586x);
return ret;
}
static struct tps6586x_platform_data *tps6586x_parse_dt(struct i2c_client *client)
{
const unsigned int num = ARRAY_SIZE(tps6586x_matches);
struct device_node *np = client->dev.of_node;
struct tps6586x_platform_data *pdata;
struct tps6586x_subdev_info *devs;
struct device_node *regs;
const char *sys_rail_name = NULL;
unsigned int count;
unsigned int i, j;
int err;
regs = of_find_node_by_name(np, "regulators");
if (!regs)
return NULL;
err = of_regulator_match(&client->dev, regs, tps6586x_matches, num);
if (err < 0) {
of_node_put(regs);
return NULL;
}
of_node_put(regs);
count = err;
devs = devm_kzalloc(&client->dev, count * sizeof(*devs), GFP_KERNEL);
if (!devs)
return NULL;
for (i = 0, j = 0; i < num && j < count; i++) {
struct regulator_init_data *reg_idata;
if (!tps6586x_matches[i].init_data)
continue;
reg_idata = tps6586x_matches[i].init_data;
devs[j].name = "tps6586x-regulator";
devs[j].platform_data = tps6586x_matches[i].init_data;
devs[j].id = (int)tps6586x_matches[i].driver_data;
if (devs[j].id == TPS6586X_ID_SYS)
sys_rail_name = reg_idata->constraints.name;
if ((devs[j].id == TPS6586X_ID_LDO_5) ||
(devs[j].id == TPS6586X_ID_LDO_RTC))
reg_idata->supply_regulator = sys_rail_name;
devs[j].of_node = tps6586x_matches[i].of_node;
j++;
}
pdata = devm_kzalloc(&client->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return NULL;
pdata->num_subdevs = count;
pdata->subdevs = devs;
pdata->gpio_base = -1;
pdata->irq_base = -1;
pdata->pm_off = of_property_read_bool(np, "ti,system-power-controller");
return pdata;
}
static struct tps6586x_platform_data *tps6586x_parse_dt(struct i2c_client *client)
{
return NULL;
}
static bool is_volatile_reg(struct device *dev, unsigned int reg)
{
if ((reg >= TPS6586X_INT_MASK1) && (reg <= TPS6586X_INT_MASK5))
return false;
return true;
}
static void tps6586x_power_off(void)
{
if (tps6586x_clr_bits(tps6586x_dev, TPS6586X_SUPPLYENE, EXITSLREQ_BIT))
return;
tps6586x_set_bits(tps6586x_dev, TPS6586X_SUPPLYENE, SLEEP_MODE_BIT);
}
static int __devinit tps6586x_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tps6586x_platform_data *pdata = client->dev.platform_data;
struct tps6586x *tps6586x;
int ret;
if (!pdata && client->dev.of_node)
pdata = tps6586x_parse_dt(client);
if (!pdata) {
dev_err(&client->dev, "tps6586x requires platform data\n");
return -ENOTSUPP;
}
ret = i2c_smbus_read_byte_data(client, TPS6586X_VERSIONCRC);
if (ret < 0) {
dev_err(&client->dev, "Chip ID read failed: %d\n", ret);
return -EIO;
}
dev_info(&client->dev, "VERSIONCRC is %02x\n", ret);
tps6586x = devm_kzalloc(&client->dev, sizeof(*tps6586x), GFP_KERNEL);
if (tps6586x == NULL) {
dev_err(&client->dev, "memory for tps6586x alloc failed\n");
return -ENOMEM;
}
tps6586x->client = client;
tps6586x->dev = &client->dev;
i2c_set_clientdata(client, tps6586x);
tps6586x->regmap = devm_regmap_init_i2c(client,
&tps6586x_regmap_config);
if (IS_ERR(tps6586x->regmap)) {
ret = PTR_ERR(tps6586x->regmap);
dev_err(&client->dev, "regmap init failed: %d\n", ret);
return ret;
}
if (client->irq) {
ret = tps6586x_irq_init(tps6586x, client->irq,
pdata->irq_base);
if (ret) {
dev_err(&client->dev, "IRQ init failed: %d\n", ret);
return ret;
}
}
ret = mfd_add_devices(tps6586x->dev, -1,
tps6586x_cell, ARRAY_SIZE(tps6586x_cell),
NULL, 0, NULL);
if (ret < 0) {
dev_err(&client->dev, "mfd_add_devices failed: %d\n", ret);
goto err_mfd_add;
}
ret = tps6586x_add_subdevs(tps6586x, pdata);
if (ret) {
dev_err(&client->dev, "add devices failed: %d\n", ret);
goto err_add_devs;
}
if (pdata->pm_off && !pm_power_off) {
tps6586x_dev = &client->dev;
pm_power_off = tps6586x_power_off;
}
return 0;
err_add_devs:
mfd_remove_devices(tps6586x->dev);
err_mfd_add:
if (client->irq)
free_irq(client->irq, tps6586x);
return ret;
}
static int __devexit tps6586x_i2c_remove(struct i2c_client *client)
{
struct tps6586x *tps6586x = i2c_get_clientdata(client);
tps6586x_remove_subdevs(tps6586x);
mfd_remove_devices(tps6586x->dev);
if (client->irq)
free_irq(client->irq, tps6586x);
return 0;
}
static int __init tps6586x_init(void)
{
return i2c_add_driver(&tps6586x_driver);
}
static void __exit tps6586x_exit(void)
{
i2c_del_driver(&tps6586x_driver);
}
