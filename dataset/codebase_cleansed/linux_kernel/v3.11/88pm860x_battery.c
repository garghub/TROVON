static int measure_12bit_voltage(struct pm860x_battery_info *info,
int offset, int *data)
{
unsigned char buf[2];
int ret;
ret = pm860x_bulk_read(info->i2c, offset, 2, buf);
if (ret < 0)
return ret;
*data = ((buf[0] & 0xff) << 4) | (buf[1] & 0x0f);
*data = ((*data & 0xfff) * 9 * 25) >> 9;
return 0;
}
static int measure_vbatt(struct pm860x_battery_info *info, int state,
int *data)
{
unsigned char buf[5];
int ret;
switch (state) {
case OCV_MODE_ACTIVE:
ret = measure_12bit_voltage(info, PM8607_VBAT_MEAS1, data);
if (ret)
return ret;
*data *= 3;
break;
case OCV_MODE_SLEEP:
ret = pm860x_bulk_read(info->i2c, PM8607_LDO5, 5, buf);
if (ret < 0)
return ret;
ret = ((buf[4] >> 6) << 10) | ((buf[3] >> 6) << 8)
| ((buf[2] >> 6) << 6) | ((buf[1] >> 6) << 4)
| (buf[0] >> 4);
*data = ((*data & 0xff) * 27 * 25) >> 9;
break;
default:
return -EINVAL;
}
return 0;
}
static int measure_current(struct pm860x_battery_info *info, int *data)
{
unsigned char buf[2];
short s;
int ret;
ret = pm860x_bulk_read(info->i2c, PM8607_IBAT_MEAS1, 2, buf);
if (ret < 0)
return ret;
s = ((buf[0] & 0xff) << 8) | (buf[1] & 0xff);
*data = s >> 3;
return 0;
}
static int set_charger_current(struct pm860x_battery_info *info, int data,
int *old)
{
int ret;
if (data < 50 || data > 1600 || !old)
return -EINVAL;
data = ((data - 50) / 50) & 0x1f;
*old = pm860x_reg_read(info->i2c, PM8607_CHG_CTRL2);
*old = (*old & 0x1f) * 50 + 50;
ret = pm860x_set_bits(info->i2c, PM8607_CHG_CTRL2, 0x1f, data);
if (ret < 0)
return ret;
return 0;
}
static int read_ccnt(struct pm860x_battery_info *info, int offset,
int *ccnt)
{
unsigned char buf[2];
int ret;
ret = pm860x_set_bits(info->i2c, PM8607_CCNT, 7, offset & 7);
if (ret < 0)
goto out;
ret = pm860x_bulk_read(info->i2c, PM8607_CCNT_MEAS1, 2, buf);
if (ret < 0)
goto out;
*ccnt = ((buf[0] & 0xff) << 8) | (buf[1] & 0xff);
return 0;
out:
return ret;
}
static int calc_ccnt(struct pm860x_battery_info *info, struct ccnt *ccnt)
{
unsigned int sum;
int ret;
int data;
ret = read_ccnt(info, CCNT_POS1, &data);
if (ret)
goto out;
sum = data & 0xffff;
ret = read_ccnt(info, CCNT_POS2, &data);
if (ret)
goto out;
sum |= (data & 0xffff) << 16;
ccnt->pos += sum;
ret = read_ccnt(info, CCNT_NEG1, &data);
if (ret)
goto out;
sum = data & 0xffff;
ret = read_ccnt(info, CCNT_NEG2, &data);
if (ret)
goto out;
sum |= (data & 0xffff) << 16;
sum = ~sum + 1;
ccnt->neg += sum;
ret = read_ccnt(info, CCNT_SPOS, &data);
if (ret)
goto out;
ccnt->spos += data;
ret = read_ccnt(info, CCNT_SNEG, &data);
if (ret)
goto out;
ccnt->total_chg = (int) ((ccnt->pos * 18236) >> 40);
ccnt->total_dischg = (int) ((ccnt->neg * 18236) >> 40);
return 0;
out:
return ret;
}
static int clear_ccnt(struct pm860x_battery_info *info, struct ccnt *ccnt)
{
int data;
memset(ccnt, 0, sizeof(*ccnt));
read_ccnt(info, CCNT_POS1, &data);
read_ccnt(info, CCNT_POS2, &data);
read_ccnt(info, CCNT_NEG1, &data);
read_ccnt(info, CCNT_NEG2, &data);
read_ccnt(info, CCNT_SPOS, &data);
read_ccnt(info, CCNT_SNEG, &data);
return 0;
}
static int calc_ocv(struct pm860x_battery_info *info, int *ocv)
{
int ret;
int i;
int data;
int vbatt_avg;
int vbatt_sum;
int ibatt_avg;
int ibatt_sum;
if (!ocv)
return -EINVAL;
for (i = 0, ibatt_sum = 0, vbatt_sum = 0; i < 10; i++) {
ret = measure_vbatt(info, OCV_MODE_ACTIVE, &data);
if (ret)
goto out;
vbatt_sum += data;
ret = measure_current(info, &data);
if (ret)
goto out;
ibatt_sum += data;
}
vbatt_avg = vbatt_sum / 10;
ibatt_avg = ibatt_sum / 10;
mutex_lock(&info->lock);
if (info->present)
*ocv = vbatt_avg - ibatt_avg * info->resistor / 1000;
else
*ocv = vbatt_avg;
mutex_unlock(&info->lock);
dev_dbg(info->dev, "VBAT average:%d, OCV:%d\n", vbatt_avg, *ocv);
return 0;
out:
return ret;
}
static int calc_soc(struct pm860x_battery_info *info, int state, int *soc)
{
int i;
int ocv;
int count;
int ret = -EINVAL;
if (!soc)
return -EINVAL;
switch (state) {
case OCV_MODE_ACTIVE:
ret = calc_ocv(info, &ocv);
break;
case OCV_MODE_SLEEP:
ret = measure_vbatt(info, OCV_MODE_SLEEP, &ocv);
break;
}
if (ret)
return ret;
count = ARRAY_SIZE(array_soc);
if (ocv < array_soc[count - 1][0]) {
*soc = 0;
return 0;
}
for (i = 0; i < count; i++) {
if (ocv >= array_soc[i][0]) {
*soc = array_soc[i][1];
break;
}
}
return 0;
}
static irqreturn_t pm860x_coulomb_handler(int irq, void *data)
{
struct pm860x_battery_info *info = data;
calc_ccnt(info, &ccnt_data);
return IRQ_HANDLED;
}
static irqreturn_t pm860x_batt_handler(int irq, void *data)
{
struct pm860x_battery_info *info = data;
int ret;
mutex_lock(&info->lock);
ret = pm860x_reg_read(info->i2c, PM8607_STATUS_2);
if (ret & STATUS2_BAT) {
info->present = 1;
info->temp_type = PM860X_TEMP_TBAT;
} else {
info->present = 0;
info->temp_type = PM860X_TEMP_TINT;
}
mutex_unlock(&info->lock);
clear_ccnt(info, &ccnt_data);
return IRQ_HANDLED;
}
static void pm860x_init_battery(struct pm860x_battery_info *info)
{
unsigned char buf[2];
int ret;
int data;
int bat_remove;
int soc;
data = MEAS1_GP1;
if (info->temp_type == PM860X_TEMP_TINT)
data |= MEAS1_TINT;
ret = pm860x_set_bits(info->i2c, PM8607_MEAS_EN1, data, data);
if (ret)
goto out;
data = MEAS3_IBAT | MEAS3_BAT_DET | MEAS3_CC;
ret = pm860x_set_bits(info->i2c, PM8607_MEAS_EN3, data, data);
if (ret)
goto out;
ret = pm860x_reg_write(info->i2c, PM8607_MEAS_OFF_TIME1, 0x82);
if (ret)
goto out;
ret = pm860x_reg_write(info->i2c, PM8607_MEAS_OFF_TIME2, 0x6c);
if (ret)
goto out;
ret = pm860x_set_bits(info->i2c, PM8607_GPADC_MISC1,
GPMISC1_GPADC_EN, GPMISC1_GPADC_EN);
if (ret < 0)
goto out;
ret = pm860x_set_bits(info->i2c, PM8607_CHG_CTRL6,
CC6_BAT_DET_GPADC1, CC6_BAT_DET_GPADC1);
if (ret < 0)
goto out;
ret = pm860x_set_bits(info->i2c, PM8607_CCNT, 7 << 3,
CCNT_AVG_SEL);
if (ret < 0)
goto out;
ret = pm860x_set_bits(info->i2c, PM8607_GP_BIAS2, 0xF << 4,
GPBIAS2_GPADC1_SET);
if (ret < 0)
goto out;
mutex_lock(&info->lock);
ret = pm860x_reg_read(info->i2c, PM8607_STATUS_2);
if (ret < 0) {
mutex_unlock(&info->lock);
goto out;
}
if (ret & STATUS2_BAT) {
info->present = 1;
info->temp_type = PM860X_TEMP_TBAT;
} else {
info->present = 0;
info->temp_type = PM860X_TEMP_TINT;
}
mutex_unlock(&info->lock);
calc_soc(info, OCV_MODE_ACTIVE, &soc);
data = pm860x_reg_read(info->i2c, PM8607_POWER_UP_LOG);
bat_remove = data & BAT_WU_LOG;
dev_dbg(info->dev, "battery wake up? %s\n",
bat_remove != 0 ? "yes" : "no");
if (bat_remove == 0) {
buf[0] = pm860x_reg_read(info->i2c, PM8607_RTC_MISC2);
buf[1] = pm860x_reg_read(info->i2c, PM8607_RTC1);
data = ((buf[1] & 0x3) << 5) | ((buf[0] >> 3) & 0x1F);
if (data > soc + 15)
info->start_soc = soc;
else if (data < soc - 15)
info->start_soc = soc;
else
info->start_soc = data;
dev_dbg(info->dev, "soc_rtc %d, soc_ocv :%d\n", data, soc);
} else {
pm860x_set_bits(info->i2c, PM8607_POWER_UP_LOG,
BAT_WU_LOG, BAT_WU_LOG);
info->start_soc = soc;
}
info->last_capacity = info->start_soc;
dev_dbg(info->dev, "init soc : %d\n", info->last_capacity);
out:
return;
}
static void set_temp_threshold(struct pm860x_battery_info *info,
int min, int max)
{
int data;
if (min <= 0)
data = 0;
else
data = (min << 8) / 1800;
pm860x_reg_write(info->i2c, PM8607_GPADC1_HIGHTH, data);
dev_dbg(info->dev, "TEMP_HIGHTH : min: %d, 0x%x\n", min, data);
if (max <= 0)
data = 0xff;
else
data = (max << 8) / 1800;
pm860x_reg_write(info->i2c, PM8607_GPADC1_LOWTH, data);
dev_dbg(info->dev, "TEMP_LOWTH:max : %d, 0x%x\n", max, data);
}
static int measure_temp(struct pm860x_battery_info *info, int *data)
{
int ret;
int temp;
int min;
int max;
if (info->temp_type == PM860X_TEMP_TINT) {
ret = measure_12bit_voltage(info, PM8607_TINT_MEAS1, data);
if (ret)
return ret;
*data = (*data - 884) * 1000 / 3611;
} else {
ret = measure_12bit_voltage(info, PM8607_GPADC1_MEAS1, data);
if (ret)
return ret;
*data = (*data * 1000) / GPBIAS2_GPADC1_UA;
if (*data > TBAT_NEG_25D) {
temp = -30;
max = TBAT_NEG_10D * GPBIAS2_GPADC1_UA / 1000;
set_temp_threshold(info, 0, max);
} else if (*data > TBAT_NEG_10D) {
temp = -15;
max = TBAT_NEG_10D * GPBIAS2_GPADC1_UA / 1000;
set_temp_threshold(info, 0, max);
} else if (*data > TBAT_0D) {
temp = -5;
min = TBAT_NEG_10D * GPBIAS2_GPADC1_UA / 1000;
max = TBAT_40D * GPBIAS2_GPADC1_UA / 1000;
set_temp_threshold(info, min, max);
} else if (*data > TBAT_10D) {
temp = 5;
min = TBAT_NEG_10D * GPBIAS2_GPADC1_UA / 1000;
max = TBAT_40D * GPBIAS2_GPADC1_UA / 1000;
set_temp_threshold(info, min, max);
} else if (*data > TBAT_20D) {
temp = 15;
min = TBAT_NEG_10D * GPBIAS2_GPADC1_UA / 1000;
max = TBAT_40D * GPBIAS2_GPADC1_UA / 1000;
set_temp_threshold(info, min, max);
} else if (*data > TBAT_30D) {
temp = 25;
min = TBAT_NEG_10D * GPBIAS2_GPADC1_UA / 1000;
max = TBAT_40D * GPBIAS2_GPADC1_UA / 1000;
set_temp_threshold(info, min, max);
} else if (*data > TBAT_40D) {
temp = 35;
min = TBAT_NEG_10D * GPBIAS2_GPADC1_UA / 1000;
max = TBAT_40D * GPBIAS2_GPADC1_UA / 1000;
set_temp_threshold(info, min, max);
} else {
min = TBAT_40D * GPBIAS2_GPADC1_UA / 1000;
set_temp_threshold(info, min, 0);
temp = 45;
}
dev_dbg(info->dev, "temp_C:%d C,temp_mv:%d mv\n", temp, *data);
*data = temp;
}
return 0;
}
static int calc_resistor(struct pm860x_battery_info *info)
{
int vbatt_sum1;
int vbatt_sum2;
int chg_current;
int ibatt_sum1;
int ibatt_sum2;
int data;
int ret;
int i;
ret = measure_current(info, &data);
if (ret || data < 0)
goto out;
ret = measure_vbatt(info, OCV_MODE_ACTIVE, &data);
if (ret)
goto out;
if (data < VBATT_RESISTOR_MIN || data > VBATT_RESISTOR_MAX)
goto out;
if (set_charger_current(info, 500, &chg_current))
goto out;
msleep(500);
for (i = 0, vbatt_sum1 = 0, ibatt_sum1 = 0; i < 10; i++) {
ret = measure_vbatt(info, OCV_MODE_ACTIVE, &data);
if (ret)
goto out_meas;
vbatt_sum1 += data;
ret = measure_current(info, &data);
if (ret)
goto out_meas;
if (data < 0)
ibatt_sum1 = ibatt_sum1 - data;
else
ibatt_sum1 = ibatt_sum1 + data;
}
if (set_charger_current(info, 100, &ret))
goto out_meas;
msleep(500);
for (i = 0, vbatt_sum2 = 0, ibatt_sum2 = 0; i < 10; i++) {
ret = measure_vbatt(info, OCV_MODE_ACTIVE, &data);
if (ret)
goto out_meas;
vbatt_sum2 += data;
ret = measure_current(info, &data);
if (ret)
goto out_meas;
if (data < 0)
ibatt_sum2 = ibatt_sum2 - data;
else
ibatt_sum2 = ibatt_sum2 + data;
}
if (set_charger_current(info, chg_current, &ret))
goto out_meas;
if ((vbatt_sum1 > vbatt_sum2) && (ibatt_sum1 > ibatt_sum2) &&
(ibatt_sum2 > 0)) {
data = 1000 * (vbatt_sum1 - vbatt_sum2)
/ (ibatt_sum1 - ibatt_sum2);
if ((data - info->resistor > 0) &&
(data - info->resistor < info->resistor))
info->resistor = data;
if ((info->resistor - data > 0) &&
(info->resistor - data < data))
info->resistor = data;
}
return 0;
out_meas:
set_charger_current(info, chg_current, &ret);
out:
return -EINVAL;
}
static int calc_capacity(struct pm860x_battery_info *info, int *cap)
{
int ret;
int data;
int ibat;
int cap_ocv = 0;
int cap_cc = 0;
ret = calc_ccnt(info, &ccnt_data);
if (ret)
goto out;
soc:
data = info->max_capacity * info->start_soc / 100;
if (ccnt_data.total_dischg - ccnt_data.total_chg <= data) {
cap_cc =
data + ccnt_data.total_chg - ccnt_data.total_dischg;
} else {
clear_ccnt(info, &ccnt_data);
calc_soc(info, OCV_MODE_ACTIVE, &info->start_soc);
dev_dbg(info->dev, "restart soc = %d !\n",
info->start_soc);
goto soc;
}
cap_cc = cap_cc * 100 / info->max_capacity;
if (cap_cc < 0)
cap_cc = 0;
else if (cap_cc > 100)
cap_cc = 100;
dev_dbg(info->dev, "%s, last cap : %d", __func__,
info->last_capacity);
ret = measure_current(info, &ibat);
if (ret)
goto out;
if (ibat < 0) {
ret = calc_soc(info, OCV_MODE_ACTIVE, &cap_ocv);
if (ret)
cap_ocv = info->last_capacity;
ret = measure_vbatt(info, OCV_MODE_ACTIVE, &data);
if (ret)
goto out;
if (data <= LOW_BAT_THRESHOLD) {
*cap = min(cap_ocv, cap_cc);
} else {
if (cap_cc < 15 && cap_ocv - cap_cc > 10)
*cap = cap_ocv;
else
*cap = cap_cc;
}
if (*cap > info->last_capacity)
*cap = info->last_capacity;
} else {
*cap = cap_cc;
}
info->last_capacity = *cap;
dev_dbg(info->dev, "%s, cap_ocv:%d cap_cc:%d, cap:%d\n",
(ibat < 0) ? "discharging" : "charging",
cap_ocv, cap_cc, *cap);
pm860x_set_bits(info->i2c, PM8607_RTC_MISC2, RTC_SOC_5LSB,
(*cap & 0x1F) << 3);
pm860x_set_bits(info->i2c, PM8607_RTC1, RTC_SOC_3MSB,
((*cap >> 5) & 0x3));
return 0;
out:
return ret;
}
static void pm860x_external_power_changed(struct power_supply *psy)
{
struct pm860x_battery_info *info;
info = container_of(psy, struct pm860x_battery_info, battery);
calc_resistor(info);
}
static int pm860x_batt_get_prop(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct pm860x_battery_info *info = dev_get_drvdata(psy->dev->parent);
int data;
int ret;
switch (psp) {
case POWER_SUPPLY_PROP_PRESENT:
val->intval = info->present;
break;
case POWER_SUPPLY_PROP_CAPACITY:
ret = calc_capacity(info, &data);
if (ret)
return ret;
if (data < 0)
data = 0;
else if (data > 100)
data = 100;
if (!info->present)
data = 100;
val->intval = data;
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = POWER_SUPPLY_TECHNOLOGY_LION;
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
ret = measure_vbatt(info, OCV_MODE_ACTIVE, &data);
if (ret)
return ret;
val->intval = data * 1000;
break;
case POWER_SUPPLY_PROP_VOLTAGE_AVG:
ret = calc_ocv(info, &data);
if (ret)
return ret;
val->intval = data * 1000;
break;
case POWER_SUPPLY_PROP_CURRENT_NOW:
ret = measure_current(info, &data);
if (ret)
return ret;
val->intval = data;
break;
case POWER_SUPPLY_PROP_TEMP:
if (info->present) {
ret = measure_temp(info, &data);
if (ret)
return ret;
data *= 10;
} else {
data = 250;
}
val->intval = data;
break;
default:
return -ENODEV;
}
return 0;
}
static int pm860x_batt_set_prop(struct power_supply *psy,
enum power_supply_property psp,
const union power_supply_propval *val)
{
struct pm860x_battery_info *info = dev_get_drvdata(psy->dev->parent);
switch (psp) {
case POWER_SUPPLY_PROP_CHARGE_FULL:
clear_ccnt(info, &ccnt_data);
info->start_soc = 100;
dev_dbg(info->dev, "chg done, update soc = %d\n",
info->start_soc);
break;
default:
return -EPERM;
}
return 0;
}
static int pm860x_battery_probe(struct platform_device *pdev)
{
struct pm860x_chip *chip = dev_get_drvdata(pdev->dev.parent);
struct pm860x_battery_info *info;
struct pm860x_power_pdata *pdata;
int ret;
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->irq_cc = platform_get_irq(pdev, 0);
if (info->irq_cc <= 0) {
dev_err(&pdev->dev, "No IRQ resource!\n");
return -EINVAL;
}
info->irq_batt = platform_get_irq(pdev, 1);
if (info->irq_batt <= 0) {
dev_err(&pdev->dev, "No IRQ resource!\n");
return -EINVAL;
}
info->chip = chip;
info->i2c =
(chip->id == CHIP_PM8607) ? chip->client : chip->companion;
info->dev = &pdev->dev;
info->status = POWER_SUPPLY_STATUS_UNKNOWN;
pdata = pdev->dev.platform_data;
mutex_init(&info->lock);
platform_set_drvdata(pdev, info);
pm860x_init_battery(info);
info->battery.name = "battery-monitor";
info->battery.type = POWER_SUPPLY_TYPE_BATTERY;
info->battery.properties = pm860x_batt_props;
info->battery.num_properties = ARRAY_SIZE(pm860x_batt_props);
info->battery.get_property = pm860x_batt_get_prop;
info->battery.set_property = pm860x_batt_set_prop;
info->battery.external_power_changed = pm860x_external_power_changed;
if (pdata && pdata->max_capacity)
info->max_capacity = pdata->max_capacity;
else
info->max_capacity = 1500;
if (pdata && pdata->resistor)
info->resistor = pdata->resistor;
else
info->resistor = 300;
ret = power_supply_register(&pdev->dev, &info->battery);
if (ret)
return ret;
info->battery.dev->parent = &pdev->dev;
ret = request_threaded_irq(info->irq_cc, NULL,
pm860x_coulomb_handler, IRQF_ONESHOT,
"coulomb", info);
if (ret < 0) {
dev_err(chip->dev, "Failed to request IRQ: #%d: %d\n",
info->irq_cc, ret);
goto out_reg;
}
ret = request_threaded_irq(info->irq_batt, NULL, pm860x_batt_handler,
IRQF_ONESHOT, "battery", info);
if (ret < 0) {
dev_err(chip->dev, "Failed to request IRQ: #%d: %d\n",
info->irq_batt, ret);
goto out_coulomb;
}
return 0;
out_coulomb:
free_irq(info->irq_cc, info);
out_reg:
power_supply_unregister(&info->battery);
return ret;
}
static int pm860x_battery_remove(struct platform_device *pdev)
{
struct pm860x_battery_info *info = platform_get_drvdata(pdev);
free_irq(info->irq_batt, info);
free_irq(info->irq_cc, info);
power_supply_unregister(&info->battery);
return 0;
}
static int pm860x_battery_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct pm860x_chip *chip = dev_get_drvdata(pdev->dev.parent);
if (device_may_wakeup(dev))
chip->wakeup_flag |= 1 << PM8607_IRQ_CC;
return 0;
}
static int pm860x_battery_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct pm860x_chip *chip = dev_get_drvdata(pdev->dev.parent);
if (device_may_wakeup(dev))
chip->wakeup_flag &= ~(1 << PM8607_IRQ_CC);
return 0;
}
