static irqreturn_t pm860x_irq(int irq, void *data)
{
struct pm860x_chip *chip = data;
struct pm860x_irq_data *irq_data;
struct i2c_client *i2c;
int read_reg = -1, value = 0;
int i;
i2c = (chip->id == CHIP_PM8607) ? chip->client : chip->companion;
for (i = 0; i < ARRAY_SIZE(pm860x_irqs); i++) {
irq_data = &pm860x_irqs[i];
if (read_reg != irq_data->reg) {
read_reg = irq_data->reg;
value = pm860x_reg_read(i2c, irq_data->reg);
}
if (value & irq_data->enable)
handle_nested_irq(chip->irq_base + i);
}
return IRQ_HANDLED;
}
static void pm860x_irq_lock(struct irq_data *data)
{
struct pm860x_chip *chip = irq_data_get_irq_chip_data(data);
mutex_lock(&chip->irq_lock);
}
static void pm860x_irq_sync_unlock(struct irq_data *data)
{
struct pm860x_chip *chip = irq_data_get_irq_chip_data(data);
struct pm860x_irq_data *irq_data;
struct i2c_client *i2c;
static unsigned char cached[3] = {0x0, 0x0, 0x0};
unsigned char mask[3];
int i;
i2c = (chip->id == CHIP_PM8607) ? chip->client : chip->companion;
for (i = 0; i < 3; i++)
mask[i] = cached[i];
for (i = 0; i < ARRAY_SIZE(pm860x_irqs); i++) {
irq_data = &pm860x_irqs[i];
switch (irq_data->mask_reg) {
case PM8607_INT_MASK_1:
mask[0] &= ~irq_data->offs;
mask[0] |= irq_data->enable;
break;
case PM8607_INT_MASK_2:
mask[1] &= ~irq_data->offs;
mask[1] |= irq_data->enable;
break;
case PM8607_INT_MASK_3:
mask[2] &= ~irq_data->offs;
mask[2] |= irq_data->enable;
break;
default:
dev_err(chip->dev, "wrong IRQ\n");
break;
}
}
for (i = 0; i < 3; i++) {
if (mask[i] != cached[i]) {
cached[i] = mask[i];
pm860x_reg_write(i2c, PM8607_INT_MASK_1 + i, mask[i]);
}
}
mutex_unlock(&chip->irq_lock);
}
static void pm860x_irq_enable(struct irq_data *data)
{
pm860x_irqs[data->hwirq].enable = pm860x_irqs[data->hwirq].offs;
}
static void pm860x_irq_disable(struct irq_data *data)
{
pm860x_irqs[data->hwirq].enable = 0;
}
static int pm860x_irq_domain_map(struct irq_domain *d, unsigned int virq,
irq_hw_number_t hw)
{
irq_set_chip_data(virq, d->host_data);
irq_set_chip_and_handler(virq, &pm860x_irq_chip, handle_edge_irq);
irq_set_nested_thread(virq, 1);
#ifdef CONFIG_ARM
set_irq_flags(virq, IRQF_VALID);
#else
irq_set_noprobe(virq);
#endif
return 0;
}
static int __devinit device_irq_init(struct pm860x_chip *chip,
struct pm860x_platform_data *pdata)
{
struct i2c_client *i2c = (chip->id == CHIP_PM8607) ? chip->client \
: chip->companion;
unsigned char status_buf[INT_STATUS_NUM];
unsigned long flags = IRQF_TRIGGER_FALLING | IRQF_ONESHOT;
int data, mask, ret = -EINVAL;
int nr_irqs, irq_base = -1;
struct device_node *node = i2c->dev.of_node;
mask = PM8607_B0_MISC1_INV_INT | PM8607_B0_MISC1_INT_CLEAR
| PM8607_B0_MISC1_INT_MASK;
data = 0;
chip->irq_mode = 0;
if (pdata && pdata->irq_mode) {
data |= PM8607_B0_MISC1_INT_CLEAR;
chip->irq_mode = 1;
}
ret = pm860x_set_bits(i2c, PM8607_B0_MISC1, mask, data);
if (ret < 0)
goto out;
memset(status_buf, 0, INT_STATUS_NUM);
ret = pm860x_bulk_write(i2c, PM8607_INT_MASK_1,
INT_STATUS_NUM, status_buf);
if (ret < 0)
goto out;
if (chip->irq_mode) {
memset(status_buf, 0xFF, INT_STATUS_NUM);
ret = pm860x_bulk_write(i2c, PM8607_INT_STATUS1,
INT_STATUS_NUM, status_buf);
} else {
ret = pm860x_bulk_read(i2c, PM8607_INT_STATUS1,
INT_STATUS_NUM, status_buf);
}
if (ret < 0)
goto out;
mutex_init(&chip->irq_lock);
if (pdata && pdata->irq_base)
irq_base = pdata->irq_base;
nr_irqs = ARRAY_SIZE(pm860x_irqs);
chip->irq_base = irq_alloc_descs(irq_base, 0, nr_irqs, 0);
if (chip->irq_base < 0) {
dev_err(&i2c->dev, "Failed to allocate interrupts, ret:%d\n",
chip->irq_base);
ret = -EBUSY;
goto out;
}
irq_domain_add_legacy(node, nr_irqs, chip->irq_base, 0,
&pm860x_irq_domain_ops, chip);
chip->core_irq = i2c->irq;
if (!chip->core_irq)
goto out;
ret = request_threaded_irq(chip->core_irq, NULL, pm860x_irq, flags | IRQF_ONESHOT,
"88pm860x", chip);
if (ret) {
dev_err(chip->dev, "Failed to request IRQ: %d\n", ret);
chip->core_irq = 0;
}
return 0;
out:
chip->core_irq = 0;
return ret;
}
static void device_irq_exit(struct pm860x_chip *chip)
{
if (chip->core_irq)
free_irq(chip->core_irq, chip);
}
int pm8606_osc_enable(struct pm860x_chip *chip, unsigned short client)
{
int ret = -EIO;
struct i2c_client *i2c = (chip->id == CHIP_PM8606) ?
chip->client : chip->companion;
dev_dbg(chip->dev, "%s(B): client=0x%x\n", __func__, client);
dev_dbg(chip->dev, "%s(B): vote=0x%x status=%d\n",
__func__, chip->osc_vote,
chip->osc_status);
mutex_lock(&chip->osc_lock);
chip->osc_vote |= client;
if (chip->osc_status != PM8606_REF_GP_OSC_ON) {
chip->osc_status = PM8606_REF_GP_OSC_UNKNOWN;
if (pm860x_set_bits(i2c, PM8606_VSYS,
PM8606_VSYS_EN, PM8606_VSYS_EN))
goto out;
if (pm860x_set_bits(i2c, PM8606_MISC,
PM8606_MISC_OSC_EN, PM8606_MISC_OSC_EN))
goto out;
chip->osc_status = PM8606_REF_GP_OSC_ON;
}
mutex_unlock(&chip->osc_lock);
dev_dbg(chip->dev, "%s(A): vote=0x%x status=%d ret=%d\n",
__func__, chip->osc_vote,
chip->osc_status, ret);
return 0;
out:
mutex_unlock(&chip->osc_lock);
return ret;
}
int pm8606_osc_disable(struct pm860x_chip *chip, unsigned short client)
{
int ret = -EIO;
struct i2c_client *i2c = (chip->id == CHIP_PM8606) ?
chip->client : chip->companion;
dev_dbg(chip->dev, "%s(B): client=0x%x\n", __func__, client);
dev_dbg(chip->dev, "%s(B): vote=0x%x status=%d\n",
__func__, chip->osc_vote,
chip->osc_status);
mutex_lock(&chip->osc_lock);
chip->osc_vote &= ~(client);
if ((chip->osc_status != PM8606_REF_GP_OSC_OFF) &&
(chip->osc_vote == REF_GP_NO_CLIENTS)) {
chip->osc_status = PM8606_REF_GP_OSC_UNKNOWN;
if (pm860x_set_bits(i2c, PM8606_VSYS, PM8606_VSYS_EN, 0))
goto out;
if (pm860x_set_bits(i2c, PM8606_MISC, PM8606_MISC_OSC_EN, 0))
goto out;
chip->osc_status = PM8606_REF_GP_OSC_OFF;
}
mutex_unlock(&chip->osc_lock);
dev_dbg(chip->dev, "%s(A): vote=0x%x status=%d ret=%d\n",
__func__, chip->osc_vote,
chip->osc_status, ret);
return 0;
out:
mutex_unlock(&chip->osc_lock);
return ret;
}
static void __devinit device_osc_init(struct i2c_client *i2c)
{
struct pm860x_chip *chip = i2c_get_clientdata(i2c);
mutex_init(&chip->osc_lock);
pm860x_set_bits(i2c, PM8606_VSYS, PM8606_VSYS_EN, 0);
pm860x_set_bits(i2c, PM8606_MISC, PM8606_MISC_OSC_EN, 0);
chip->osc_vote = REF_GP_NO_CLIENTS;
chip->osc_status = PM8606_REF_GP_OSC_OFF;
}
static void __devinit device_bk_init(struct pm860x_chip *chip,
struct pm860x_platform_data *pdata)
{
int ret, i;
if (pdata && pdata->backlight) {
if (pdata->num_backlights > ARRAY_SIZE(bk_devs))
pdata->num_backlights = ARRAY_SIZE(bk_devs);
for (i = 0; i < pdata->num_backlights; i++) {
bk_devs[i].platform_data = &pdata->backlight[i];
bk_devs[i].pdata_size =
sizeof(struct pm860x_backlight_pdata);
}
}
ret = mfd_add_devices(chip->dev, 0, bk_devs,
ARRAY_SIZE(bk_devs), NULL, 0, NULL);
if (ret < 0)
dev_err(chip->dev, "Failed to add backlight subdev\n");
}
static void __devinit device_led_init(struct pm860x_chip *chip,
struct pm860x_platform_data *pdata)
{
int ret, i;
if (pdata && pdata->led) {
if (pdata->num_leds > ARRAY_SIZE(led_devs))
pdata->num_leds = ARRAY_SIZE(led_devs);
for (i = 0; i < pdata->num_leds; i++) {
led_devs[i].platform_data = &pdata->led[i];
led_devs[i].pdata_size =
sizeof(struct pm860x_led_pdata);
}
}
ret = mfd_add_devices(chip->dev, 0, led_devs,
ARRAY_SIZE(led_devs), NULL, 0, NULL);
if (ret < 0) {
dev_err(chip->dev, "Failed to add led subdev\n");
return;
}
}
static void __devinit device_regulator_init(struct pm860x_chip *chip,
struct pm860x_platform_data *pdata)
{
int ret;
if (pdata == NULL)
return;
if (pdata->buck1) {
reg_devs[0].platform_data = pdata->buck1;
reg_devs[0].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->buck2) {
reg_devs[1].platform_data = pdata->buck2;
reg_devs[1].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->buck3) {
reg_devs[2].platform_data = pdata->buck3;
reg_devs[2].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo1) {
reg_devs[3].platform_data = pdata->ldo1;
reg_devs[3].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo2) {
reg_devs[4].platform_data = pdata->ldo2;
reg_devs[4].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo3) {
reg_devs[5].platform_data = pdata->ldo3;
reg_devs[5].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo4) {
reg_devs[6].platform_data = pdata->ldo4;
reg_devs[6].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo5) {
reg_devs[7].platform_data = pdata->ldo5;
reg_devs[7].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo6) {
reg_devs[8].platform_data = pdata->ldo6;
reg_devs[8].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo7) {
reg_devs[9].platform_data = pdata->ldo7;
reg_devs[9].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo8) {
reg_devs[10].platform_data = pdata->ldo8;
reg_devs[10].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo9) {
reg_devs[11].platform_data = pdata->ldo9;
reg_devs[11].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo10) {
reg_devs[12].platform_data = pdata->ldo10;
reg_devs[12].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo12) {
reg_devs[13].platform_data = pdata->ldo12;
reg_devs[13].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo_vibrator) {
reg_devs[14].platform_data = pdata->ldo_vibrator;
reg_devs[14].pdata_size = sizeof(struct regulator_init_data);
}
if (pdata->ldo14) {
reg_devs[15].platform_data = pdata->ldo14;
reg_devs[15].pdata_size = sizeof(struct regulator_init_data);
}
ret = mfd_add_devices(chip->dev, 0, reg_devs,
ARRAY_SIZE(reg_devs), NULL, 0, NULL);
if (ret < 0) {
dev_err(chip->dev, "Failed to add regulator subdev\n");
return;
}
}
static void __devinit device_rtc_init(struct pm860x_chip *chip,
struct pm860x_platform_data *pdata)
{
int ret;
if ((pdata == NULL))
return;
rtc_devs[0].platform_data = pdata->rtc;
rtc_devs[0].pdata_size = sizeof(struct pm860x_rtc_pdata);
rtc_devs[0].num_resources = ARRAY_SIZE(rtc_resources);
rtc_devs[0].resources = &rtc_resources[0];
ret = mfd_add_devices(chip->dev, 0, &rtc_devs[0],
ARRAY_SIZE(rtc_devs), &rtc_resources[0],
chip->irq_base, NULL);
if (ret < 0)
dev_err(chip->dev, "Failed to add rtc subdev\n");
}
static void __devinit device_touch_init(struct pm860x_chip *chip,
struct pm860x_platform_data *pdata)
{
int ret;
if (pdata == NULL)
return;
touch_devs[0].platform_data = pdata->touch;
touch_devs[0].pdata_size = sizeof(struct pm860x_touch_pdata);
touch_devs[0].num_resources = ARRAY_SIZE(touch_resources);
touch_devs[0].resources = &touch_resources[0];
ret = mfd_add_devices(chip->dev, 0, &touch_devs[0],
ARRAY_SIZE(touch_devs), &touch_resources[0],
chip->irq_base, NULL);
if (ret < 0)
dev_err(chip->dev, "Failed to add touch subdev\n");
}
static void __devinit device_power_init(struct pm860x_chip *chip,
struct pm860x_platform_data *pdata)
{
int ret;
if (pdata == NULL)
return;
power_devs[0].platform_data = pdata->power;
power_devs[0].pdata_size = sizeof(struct pm860x_power_pdata);
power_devs[0].num_resources = ARRAY_SIZE(battery_resources);
power_devs[0].resources = &battery_resources[0],
ret = mfd_add_devices(chip->dev, 0, &power_devs[0], 1,
&battery_resources[0], chip->irq_base, NULL);
if (ret < 0)
dev_err(chip->dev, "Failed to add battery subdev\n");
power_devs[1].platform_data = pdata->power;
power_devs[1].pdata_size = sizeof(struct pm860x_power_pdata);
power_devs[1].num_resources = ARRAY_SIZE(charger_resources);
power_devs[1].resources = &charger_resources[0],
ret = mfd_add_devices(chip->dev, 0, &power_devs[1], 1,
&charger_resources[0], chip->irq_base, NULL);
if (ret < 0)
dev_err(chip->dev, "Failed to add charger subdev\n");
power_devs[2].platform_data = &preg_init_data;
power_devs[2].pdata_size = sizeof(struct regulator_init_data);
ret = mfd_add_devices(chip->dev, 0, &power_devs[2], 1,
NULL, chip->irq_base, NULL);
if (ret < 0)
dev_err(chip->dev, "Failed to add preg subdev\n");
if (pdata->chg_desc) {
pdata->chg_desc->charger_regulators =
&chg_desc_regulator_data[0];
pdata->chg_desc->num_charger_regulators =
ARRAY_SIZE(chg_desc_regulator_data),
power_devs[3].platform_data = pdata->chg_desc;
power_devs[3].pdata_size = sizeof(*pdata->chg_desc);
ret = mfd_add_devices(chip->dev, 0, &power_devs[3], 1,
NULL, chip->irq_base, NULL);
if (ret < 0)
dev_err(chip->dev, "Failed to add chg-manager subdev\n");
}
}
static void __devinit device_onkey_init(struct pm860x_chip *chip,
struct pm860x_platform_data *pdata)
{
int ret;
onkey_devs[0].num_resources = ARRAY_SIZE(onkey_resources);
onkey_devs[0].resources = &onkey_resources[0],
ret = mfd_add_devices(chip->dev, 0, &onkey_devs[0],
ARRAY_SIZE(onkey_devs), &onkey_resources[0],
chip->irq_base, NULL);
if (ret < 0)
dev_err(chip->dev, "Failed to add onkey subdev\n");
}
static void __devinit device_codec_init(struct pm860x_chip *chip,
struct pm860x_platform_data *pdata)
{
int ret;
codec_devs[0].num_resources = ARRAY_SIZE(codec_resources);
codec_devs[0].resources = &codec_resources[0],
ret = mfd_add_devices(chip->dev, 0, &codec_devs[0],
ARRAY_SIZE(codec_devs), &codec_resources[0], 0,
NULL);
if (ret < 0)
dev_err(chip->dev, "Failed to add codec subdev\n");
}
static void __devinit device_8607_init(struct pm860x_chip *chip,
struct i2c_client *i2c,
struct pm860x_platform_data *pdata)
{
int data, ret;
ret = pm860x_reg_read(i2c, PM8607_CHIP_ID);
if (ret < 0) {
dev_err(chip->dev, "Failed to read CHIP ID: %d\n", ret);
goto out;
}
switch (ret & PM8607_VERSION_MASK) {
case 0x40:
case 0x50:
dev_info(chip->dev, "Marvell 88PM8607 (ID: %02x) detected\n",
ret);
break;
default:
dev_err(chip->dev, "Failed to detect Marvell 88PM8607. "
"Chip ID: %02x\n", ret);
goto out;
}
ret = pm860x_reg_read(i2c, PM8607_BUCK3);
if (ret < 0) {
dev_err(chip->dev, "Failed to read BUCK3 register: %d\n", ret);
goto out;
}
if (ret & PM8607_BUCK3_DOUBLE)
chip->buck3_double = 1;
ret = pm860x_reg_read(i2c, PM8607_B0_MISC1);
if (ret < 0) {
dev_err(chip->dev, "Failed to read MISC1 register: %d\n", ret);
goto out;
}
if (pdata && (pdata->i2c_port == PI2C_PORT))
data = PM8607_B0_MISC1_PI2C;
else
data = 0;
ret = pm860x_set_bits(i2c, PM8607_B0_MISC1, PM8607_B0_MISC1_PI2C, data);
if (ret < 0) {
dev_err(chip->dev, "Failed to access MISC1:%d\n", ret);
goto out;
}
ret = device_irq_init(chip, pdata);
if (ret < 0)
goto out;
device_regulator_init(chip, pdata);
device_rtc_init(chip, pdata);
device_onkey_init(chip, pdata);
device_touch_init(chip, pdata);
device_power_init(chip, pdata);
device_codec_init(chip, pdata);
out:
return;
}
static void __devinit device_8606_init(struct pm860x_chip *chip,
struct i2c_client *i2c,
struct pm860x_platform_data *pdata)
{
device_osc_init(i2c);
device_bk_init(chip, pdata);
device_led_init(chip, pdata);
}
static int __devinit pm860x_device_init(struct pm860x_chip *chip,
struct pm860x_platform_data *pdata)
{
chip->core_irq = 0;
switch (chip->id) {
case CHIP_PM8606:
device_8606_init(chip, chip->client, pdata);
break;
case CHIP_PM8607:
device_8607_init(chip, chip->client, pdata);
break;
}
if (chip->companion) {
switch (chip->id) {
case CHIP_PM8607:
device_8606_init(chip, chip->companion, pdata);
break;
case CHIP_PM8606:
device_8607_init(chip, chip->companion, pdata);
break;
}
}
return 0;
}
static void __devexit pm860x_device_exit(struct pm860x_chip *chip)
{
device_irq_exit(chip);
mfd_remove_devices(chip->dev);
}
static int verify_addr(struct i2c_client *i2c)
{
unsigned short addr_8607[] = {0x30, 0x34};
unsigned short addr_8606[] = {0x10, 0x11};
int size, i;
if (i2c == NULL)
return 0;
size = ARRAY_SIZE(addr_8606);
for (i = 0; i < size; i++) {
if (i2c->addr == *(addr_8606 + i))
return CHIP_PM8606;
}
size = ARRAY_SIZE(addr_8607);
for (i = 0; i < size; i++) {
if (i2c->addr == *(addr_8607 + i))
return CHIP_PM8607;
}
return 0;
}
static int __devinit pm860x_dt_init(struct device_node *np,
struct device *dev,
struct pm860x_platform_data *pdata)
{
int ret;
if (of_get_property(np, "marvell,88pm860x-irq-read-clr", NULL))
pdata->irq_mode = 1;
ret = of_property_read_u32(np, "marvell,88pm860x-slave-addr",
&pdata->companion_addr);
if (ret) {
dev_err(dev, "Not found \"marvell,88pm860x-slave-addr\" "
"property\n");
pdata->companion_addr = 0;
}
return 0;
}
static int __devinit pm860x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct pm860x_platform_data *pdata = client->dev.platform_data;
struct device_node *node = client->dev.of_node;
struct pm860x_chip *chip;
int ret;
if (node && !pdata) {
pdata = devm_kzalloc(&client->dev,
sizeof(struct pm860x_platform_data),
GFP_KERNEL);
if (!pdata)
return -ENOMEM;
ret = pm860x_dt_init(node, &client->dev, pdata);
if (ret)
goto err;
} else if (!pdata) {
pr_info("No platform data in %s!\n", __func__);
return -EINVAL;
}
chip = kzalloc(sizeof(struct pm860x_chip), GFP_KERNEL);
if (chip == NULL) {
ret = -ENOMEM;
goto err;
}
chip->id = verify_addr(client);
chip->regmap = regmap_init_i2c(client, &pm860x_regmap_config);
if (IS_ERR(chip->regmap)) {
ret = PTR_ERR(chip->regmap);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
ret);
kfree(chip);
return ret;
}
chip->client = client;
i2c_set_clientdata(client, chip);
chip->dev = &client->dev;
dev_set_drvdata(chip->dev, chip);
if (pdata->companion_addr && (pdata->companion_addr != client->addr)) {
chip->companion_addr = pdata->companion_addr;
chip->companion = i2c_new_dummy(chip->client->adapter,
chip->companion_addr);
chip->regmap_companion = regmap_init_i2c(chip->companion,
&pm860x_regmap_config);
if (IS_ERR(chip->regmap_companion)) {
ret = PTR_ERR(chip->regmap_companion);
dev_err(&chip->companion->dev,
"Failed to allocate register map: %d\n", ret);
return ret;
}
i2c_set_clientdata(chip->companion, chip);
}
pm860x_device_init(chip, pdata);
return 0;
err:
if (node)
devm_kfree(&client->dev, pdata);
return ret;
}
static int __devexit pm860x_remove(struct i2c_client *client)
{
struct pm860x_chip *chip = i2c_get_clientdata(client);
pm860x_device_exit(chip);
if (chip->companion) {
regmap_exit(chip->regmap_companion);
i2c_unregister_device(chip->companion);
}
regmap_exit(chip->regmap);
kfree(chip);
return 0;
}
static int pm860x_suspend(struct device *dev)
{
struct i2c_client *client = container_of(dev, struct i2c_client, dev);
struct pm860x_chip *chip = i2c_get_clientdata(client);
if (device_may_wakeup(dev) && chip->wakeup_flag)
enable_irq_wake(chip->core_irq);
return 0;
}
static int pm860x_resume(struct device *dev)
{
struct i2c_client *client = container_of(dev, struct i2c_client, dev);
struct pm860x_chip *chip = i2c_get_clientdata(client);
if (device_may_wakeup(dev) && chip->wakeup_flag)
disable_irq_wake(chip->core_irq);
return 0;
}
static int __init pm860x_i2c_init(void)
{
int ret;
ret = i2c_add_driver(&pm860x_driver);
if (ret != 0)
pr_err("Failed to register 88PM860x I2C driver: %d\n", ret);
return ret;
}
static void __exit pm860x_i2c_exit(void)
{
i2c_del_driver(&pm860x_driver);
}
