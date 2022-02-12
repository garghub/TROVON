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
struct pm860x_chip *chip = irq_data_get_irq_chip_data(data);
pm860x_irqs[data->irq - chip->irq_base].enable
= pm860x_irqs[data->irq - chip->irq_base].offs;
}
static void pm860x_irq_disable(struct irq_data *data)
{
struct pm860x_chip *chip = irq_data_get_irq_chip_data(data);
pm860x_irqs[data->irq - chip->irq_base].enable = 0;
}
static int __devinit device_gpadc_init(struct pm860x_chip *chip,
struct pm860x_platform_data *pdata)
{
struct i2c_client *i2c = (chip->id == CHIP_PM8607) ? chip->client \
: chip->companion;
int data;
int ret;
if (!pdata || !pdata->touch)
return -EINVAL;
data = 0;
data |= (pdata->touch->gpadc_prebias << 1) & PM8607_GPADC_PREBIAS_MASK;
data |= (pdata->touch->slot_cycle << 3) & PM8607_GPADC_SLOT_CYCLE_MASK;
data |= (pdata->touch->off_scale << 5) & PM8607_GPADC_OFF_SCALE_MASK;
data |= (pdata->touch->sw_cal << 7) & PM8607_GPADC_SW_CAL_MASK;
if (data) {
ret = pm860x_reg_write(i2c, PM8607_GPADC_MISC1, data);
if (ret < 0)
goto out;
}
if (pdata->touch->tsi_prebias) {
data = pdata->touch->tsi_prebias;
ret = pm860x_reg_write(i2c, PM8607_TSI_PREBIAS, data);
if (ret < 0)
goto out;
}
data = 0;
data |= pdata->touch->pen_prebias & PM8607_PD_PREBIAS_MASK;
data |= (pdata->touch->pen_prechg << 5) & PM8607_PD_PRECHG_MASK;
if (data) {
ret = pm860x_reg_write(i2c, PM8607_PD_PREBIAS, data);
if (ret < 0)
goto out;
}
ret = pm860x_set_bits(i2c, PM8607_GPADC_MISC1,
PM8607_GPADC_EN, PM8607_GPADC_EN);
out:
return ret;
}
static int __devinit device_irq_init(struct pm860x_chip *chip,
struct pm860x_platform_data *pdata)
{
struct i2c_client *i2c = (chip->id == CHIP_PM8607) ? chip->client \
: chip->companion;
unsigned char status_buf[INT_STATUS_NUM];
unsigned long flags = IRQF_TRIGGER_FALLING | IRQF_ONESHOT;
int i, data, mask, ret = -EINVAL;
int __irq;
if (!pdata || !pdata->irq_base) {
dev_warn(chip->dev, "No interrupt support on IRQ base\n");
return -EINVAL;
}
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
chip->irq_base = pdata->irq_base;
chip->core_irq = i2c->irq;
if (!chip->core_irq)
goto out;
for (i = 0; i < ARRAY_SIZE(pm860x_irqs); i++) {
__irq = i + chip->irq_base;
irq_set_chip_data(__irq, chip);
irq_set_chip_and_handler(__irq, &pm860x_irq_chip,
handle_edge_irq);
irq_set_nested_thread(__irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(__irq, IRQF_VALID);
#else
irq_set_noprobe(__irq);
#endif
}
ret = request_threaded_irq(chip->core_irq, NULL, pm860x_irq, flags,
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
int ret;
int i, j, id;
if ((pdata == NULL) || (pdata->backlight == NULL))
return;
if (pdata->num_backlights > ARRAY_SIZE(bk_devs))
pdata->num_backlights = ARRAY_SIZE(bk_devs);
for (i = 0; i < pdata->num_backlights; i++) {
bk_devs[i].platform_data = &pdata->backlight[i];
bk_devs[i].pdata_size = sizeof(struct pm860x_backlight_pdata);
for (j = 0; j < ARRAY_SIZE(bk_devs); j++) {
id = bk_resources[j].start;
if (pdata->backlight[i].flags != id)
continue;
bk_devs[i].num_resources = 1;
bk_devs[i].resources = &bk_resources[j];
ret = mfd_add_devices(chip->dev, 0,
&bk_devs[i], 1,
&bk_resources[j], 0);
if (ret < 0) {
dev_err(chip->dev, "Failed to add "
"backlight subdev\n");
return;
}
}
}
}
static void __devinit device_led_init(struct pm860x_chip *chip,
struct pm860x_platform_data *pdata)
{
int ret;
int i, j, id;
if ((pdata == NULL) || (pdata->led == NULL))
return;
if (pdata->num_leds > ARRAY_SIZE(led_devs))
pdata->num_leds = ARRAY_SIZE(led_devs);
for (i = 0; i < pdata->num_leds; i++) {
led_devs[i].platform_data = &pdata->led[i];
led_devs[i].pdata_size = sizeof(struct pm860x_led_pdata);
for (j = 0; j < ARRAY_SIZE(led_devs); j++) {
id = led_resources[j].start;
if (pdata->led[i].flags != id)
continue;
led_devs[i].num_resources = 1;
led_devs[i].resources = &led_resources[j],
ret = mfd_add_devices(chip->dev, 0,
&led_devs[i], 1,
&led_resources[j], 0);
if (ret < 0) {
dev_err(chip->dev, "Failed to add "
"led subdev\n");
return;
}
}
}
}
static void __devinit device_regulator_init(struct pm860x_chip *chip,
struct pm860x_platform_data *pdata)
{
struct regulator_init_data *initdata;
int ret;
int i, seq;
if ((pdata == NULL) || (pdata->regulator == NULL))
return;
if (pdata->num_regulators > ARRAY_SIZE(regulator_devs))
pdata->num_regulators = ARRAY_SIZE(regulator_devs);
for (i = 0, seq = -1; i < pdata->num_regulators; i++) {
initdata = &pdata->regulator[i];
seq = *(unsigned int *)initdata->driver_data;
if ((seq < 0) || (seq > PM8607_ID_RG_MAX)) {
dev_err(chip->dev, "Wrong ID(%d) on regulator(%s)\n",
seq, initdata->constraints.name);
goto out;
}
regulator_devs[i].platform_data = &pdata->regulator[i];
regulator_devs[i].pdata_size = sizeof(struct regulator_init_data);
regulator_devs[i].num_resources = 1;
regulator_devs[i].resources = &regulator_resources[seq];
ret = mfd_add_devices(chip->dev, 0, &regulator_devs[i], 1,
&regulator_resources[seq], 0);
if (ret < 0) {
dev_err(chip->dev, "Failed to add regulator subdev\n");
goto out;
}
}
out:
return;
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
chip->irq_base);
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
chip->irq_base);
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
&battery_resources[0], chip->irq_base);
if (ret < 0)
dev_err(chip->dev, "Failed to add battery subdev\n");
power_devs[1].platform_data = pdata->power;
power_devs[1].pdata_size = sizeof(struct pm860x_power_pdata);
power_devs[1].num_resources = ARRAY_SIZE(charger_resources);
power_devs[1].resources = &charger_resources[0],
ret = mfd_add_devices(chip->dev, 0, &power_devs[1], 1,
&charger_resources[0], chip->irq_base);
if (ret < 0)
dev_err(chip->dev, "Failed to add charger subdev\n");
}
static void __devinit device_onkey_init(struct pm860x_chip *chip,
struct pm860x_platform_data *pdata)
{
int ret;
onkey_devs[0].num_resources = ARRAY_SIZE(onkey_resources);
onkey_devs[0].resources = &onkey_resources[0],
ret = mfd_add_devices(chip->dev, 0, &onkey_devs[0],
ARRAY_SIZE(onkey_devs), &onkey_resources[0],
chip->irq_base);
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
ARRAY_SIZE(codec_devs), &codec_resources[0], 0);
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
ret = device_gpadc_init(chip, pdata);
if (ret < 0)
goto out;
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
int __devinit pm860x_device_init(struct pm860x_chip *chip,
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
void __devexit pm860x_device_exit(struct pm860x_chip *chip)
{
device_irq_exit(chip);
mfd_remove_devices(chip->dev);
}
