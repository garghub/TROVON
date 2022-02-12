static void tps65217_irq_lock(struct irq_data *data)
{
struct tps65217 *tps = irq_data_get_irq_chip_data(data);
mutex_lock(&tps->irq_lock);
}
static void tps65217_irq_sync_unlock(struct irq_data *data)
{
struct tps65217 *tps = irq_data_get_irq_chip_data(data);
int ret;
ret = tps65217_reg_write(tps, TPS65217_REG_INT, tps->irq_mask,
TPS65217_PROTECT_NONE);
if (ret != 0)
dev_err(tps->dev, "Failed to sync IRQ masks\n");
mutex_unlock(&tps->irq_lock);
}
static inline const struct tps65217_irq *
irq_to_tps65217_irq(struct tps65217 *tps, struct irq_data *data)
{
return &tps65217_irqs[data->hwirq];
}
static void tps65217_irq_enable(struct irq_data *data)
{
struct tps65217 *tps = irq_data_get_irq_chip_data(data);
const struct tps65217_irq *irq_data = irq_to_tps65217_irq(tps, data);
tps->irq_mask &= ~irq_data->mask;
}
static void tps65217_irq_disable(struct irq_data *data)
{
struct tps65217 *tps = irq_data_get_irq_chip_data(data);
const struct tps65217_irq *irq_data = irq_to_tps65217_irq(tps, data);
tps->irq_mask |= irq_data->mask;
}
static irqreturn_t tps65217_irq_thread(int irq, void *data)
{
struct tps65217 *tps = data;
unsigned int status;
bool handled = false;
int i;
int ret;
ret = tps65217_reg_read(tps, TPS65217_REG_INT, &status);
if (ret < 0) {
dev_err(tps->dev, "Failed to read IRQ status: %d\n",
ret);
return IRQ_NONE;
}
for (i = 0; i < ARRAY_SIZE(tps65217_irqs); i++) {
if (status & tps65217_irqs[i].interrupt) {
handle_nested_irq(irq_find_mapping(tps->irq_domain, i));
handled = true;
}
}
if (handled)
return IRQ_HANDLED;
return IRQ_NONE;
}
static int tps65217_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct tps65217 *tps = h->host_data;
irq_set_chip_data(virq, tps);
irq_set_chip_and_handler(virq, &tps65217_irq_chip, handle_edge_irq);
irq_set_nested_thread(virq, 1);
irq_set_parent(virq, tps->irq);
irq_set_noprobe(virq);
return 0;
}
static int tps65217_irq_init(struct tps65217 *tps, int irq)
{
int ret;
mutex_init(&tps->irq_lock);
tps->irq = irq;
tps->irq_mask = (TPS65217_INT_RESERVEDM | TPS65217_INT_PBM
| TPS65217_INT_ACM | TPS65217_INT_USBM);
tps65217_reg_write(tps, TPS65217_REG_INT, tps->irq_mask,
TPS65217_PROTECT_NONE);
tps->irq_domain = irq_domain_add_linear(tps->dev->of_node,
TPS65217_NUM_IRQ, &tps65217_irq_domain_ops, tps);
if (!tps->irq_domain) {
dev_err(tps->dev, "Could not create IRQ domain\n");
return -ENOMEM;
}
ret = devm_request_threaded_irq(tps->dev, irq, NULL,
tps65217_irq_thread, IRQF_ONESHOT,
"tps65217-irq", tps);
if (ret) {
dev_err(tps->dev, "Failed to request IRQ %d: %d\n",
irq, ret);
return ret;
}
return 0;
}
int tps65217_reg_read(struct tps65217 *tps, unsigned int reg,
unsigned int *val)
{
return regmap_read(tps->regmap, reg, val);
}
int tps65217_reg_write(struct tps65217 *tps, unsigned int reg,
unsigned int val, unsigned int level)
{
int ret;
unsigned int xor_reg_val;
switch (level) {
case TPS65217_PROTECT_NONE:
return regmap_write(tps->regmap, reg, val);
case TPS65217_PROTECT_L1:
xor_reg_val = reg ^ TPS65217_PASSWORD_REGS_UNLOCK;
ret = regmap_write(tps->regmap, TPS65217_REG_PASSWORD,
xor_reg_val);
if (ret < 0)
return ret;
return regmap_write(tps->regmap, reg, val);
case TPS65217_PROTECT_L2:
xor_reg_val = reg ^ TPS65217_PASSWORD_REGS_UNLOCK;
ret = regmap_write(tps->regmap, TPS65217_REG_PASSWORD,
xor_reg_val);
if (ret < 0)
return ret;
ret = regmap_write(tps->regmap, reg, val);
if (ret < 0)
return ret;
ret = regmap_write(tps->regmap, TPS65217_REG_PASSWORD,
xor_reg_val);
if (ret < 0)
return ret;
return regmap_write(tps->regmap, reg, val);
default:
return -EINVAL;
}
}
static int tps65217_update_bits(struct tps65217 *tps, unsigned int reg,
unsigned int mask, unsigned int val, unsigned int level)
{
int ret;
unsigned int data;
ret = tps65217_reg_read(tps, reg, &data);
if (ret) {
dev_err(tps->dev, "Read from reg 0x%x failed\n", reg);
return ret;
}
data &= ~mask;
data |= val & mask;
ret = tps65217_reg_write(tps, reg, data, level);
if (ret)
dev_err(tps->dev, "Write for reg 0x%x failed\n", reg);
return ret;
}
int tps65217_set_bits(struct tps65217 *tps, unsigned int reg,
unsigned int mask, unsigned int val, unsigned int level)
{
return tps65217_update_bits(tps, reg, mask, val, level);
}
int tps65217_clear_bits(struct tps65217 *tps, unsigned int reg,
unsigned int mask, unsigned int level)
{
return tps65217_update_bits(tps, reg, mask, 0, level);
}
static bool tps65217_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case TPS65217_REG_INT:
return true;
default:
return false;
}
}
static int tps65217_probe(struct i2c_client *client,
const struct i2c_device_id *ids)
{
struct tps65217 *tps;
unsigned int version;
unsigned long chip_id = ids->driver_data;
const struct of_device_id *match;
bool status_off = false;
int ret;
if (client->dev.of_node) {
match = of_match_device(tps65217_of_match, &client->dev);
if (!match) {
dev_err(&client->dev,
"Failed to find matching dt id\n");
return -EINVAL;
}
chip_id = (unsigned long)match->data;
status_off = of_property_read_bool(client->dev.of_node,
"ti,pmic-shutdown-controller");
}
if (!chip_id) {
dev_err(&client->dev, "id is null.\n");
return -ENODEV;
}
tps = devm_kzalloc(&client->dev, sizeof(*tps), GFP_KERNEL);
if (!tps)
return -ENOMEM;
i2c_set_clientdata(client, tps);
tps->dev = &client->dev;
tps->id = chip_id;
tps->regmap = devm_regmap_init_i2c(client, &tps65217_regmap_config);
if (IS_ERR(tps->regmap)) {
ret = PTR_ERR(tps->regmap);
dev_err(tps->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
if (client->irq) {
tps65217_irq_init(tps, client->irq);
} else {
int i;
for (i = 0; i < ARRAY_SIZE(tps65217s); i++)
tps65217s[i].num_resources = 0;
}
ret = devm_mfd_add_devices(tps->dev, -1, tps65217s,
ARRAY_SIZE(tps65217s), NULL, 0,
tps->irq_domain);
if (ret < 0) {
dev_err(tps->dev, "mfd_add_devices failed: %d\n", ret);
return ret;
}
ret = tps65217_reg_read(tps, TPS65217_REG_CHIPID, &version);
if (ret < 0) {
dev_err(tps->dev, "Failed to read revision register: %d\n",
ret);
return ret;
}
if (status_off) {
ret = tps65217_set_bits(tps, TPS65217_REG_STATUS,
TPS65217_STATUS_OFF, TPS65217_STATUS_OFF,
TPS65217_PROTECT_NONE);
if (ret)
dev_warn(tps->dev, "unable to set the status OFF\n");
}
dev_info(tps->dev, "TPS65217 ID %#x version 1.%d\n",
(version & TPS65217_CHIPID_CHIP_MASK) >> 4,
version & TPS65217_CHIPID_REV_MASK);
return 0;
}
static int __init tps65217_init(void)
{
return i2c_add_driver(&tps65217_driver);
}
static void __exit tps65217_exit(void)
{
i2c_del_driver(&tps65217_driver);
}
