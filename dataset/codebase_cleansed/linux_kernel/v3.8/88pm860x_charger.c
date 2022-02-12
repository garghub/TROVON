static int measure_vchg(struct pm860x_charger_info *info, int *data)
{
unsigned char buf[2];
int ret = 0;
ret = pm860x_bulk_read(info->i2c, PM8607_VCHG_MEAS1, 2, buf);
if (ret < 0)
return ret;
*data = ((buf[0] & 0xff) << 4) | (buf[1] & 0x0f);
*data = ((*data & 0xfff) * 9 * 125) >> 9;
dev_dbg(info->dev, "%s, vchg: %d mv\n", __func__, *data);
return ret;
}
static void set_vchg_threshold(struct pm860x_charger_info *info,
int min, int max)
{
int data;
if (min <= 0)
data = 0;
else
data = (min << 5) / 1125;
pm860x_reg_write(info->i2c, PM8607_VCHG_LOWTH, data);
dev_dbg(info->dev, "VCHG_LOWTH:%dmv, 0x%x\n", min, data);
if (max <= 0)
data = 0xff;
else
data = (max << 5) / 1125;
pm860x_reg_write(info->i2c, PM8607_VCHG_HIGHTH, data);
dev_dbg(info->dev, "VCHG_HIGHTH:%dmv, 0x%x\n", max, data);
}
static void set_vbatt_threshold(struct pm860x_charger_info *info,
int min, int max)
{
int data;
if (min <= 0)
data = 0;
else
data = (min << 5) / 675;
pm860x_reg_write(info->i2c, PM8607_VBAT_LOWTH, data);
dev_dbg(info->dev, "VBAT Min:%dmv, LOWTH:0x%x\n", min, data);
if (max <= 0)
data = 0xff;
else
data = (max << 5) / 675;
pm860x_reg_write(info->i2c, PM8607_VBAT_HIGHTH, data);
dev_dbg(info->dev, "VBAT Max:%dmv, HIGHTH:0x%x\n", max, data);
return;
}
static int start_precharge(struct pm860x_charger_info *info)
{
int ret;
dev_dbg(info->dev, "Start Pre-charging!\n");
set_vbatt_threshold(info, 0, 0);
ret = pm860x_reg_write(info->i2c_8606, PM8606_PREREGULATORA,
PREREG1_1350MA | PREREG1_VSYS_4_5V);
if (ret < 0)
goto out;
ret = pm860x_set_bits(info->i2c, PM8607_CHG_CTRL1, 3,
CC1_MODE_OFF);
if (ret < 0)
goto out;
ret = pm860x_set_bits(info->i2c, PM8607_CHG_CTRL3, (0xf << 4),
CC3_270MIN_TIMEOUT);
if (ret < 0)
goto out;
ret = pm860x_reg_write(info->i2c, PM8607_CHG_CTRL4,
CC4_IPRE_40MA | CC4_VPCHG_3_2V |
CC4_IFCHG_MON_EN | CC4_BTEMP_MON_EN);
if (ret < 0)
goto out;
ret = pm860x_set_bits(info->i2c, PM8607_CHG_CTRL7,
CC7_BAT_REM_EN | CC7_IFSM_EN,
CC7_BAT_REM_EN | CC7_IFSM_EN);
if (ret < 0)
goto out;
ret = pm860x_set_bits(info->i2c, PM8607_CHG_CTRL1, 3,
CC1_MODE_PRECHARGE);
out:
return ret;
}
static int start_fastcharge(struct pm860x_charger_info *info)
{
int ret;
dev_dbg(info->dev, "Start Fast-charging!\n");
ret = pm860x_reg_write(info->i2c, PM8607_CHG_CTRL1,
CC1_MODE_OFF | CC1_ITERM_60MA |
CC1_VFCHG_4_2V);
if (ret < 0)
goto out;
ret = pm860x_reg_write(info->i2c_8606, PM8606_PREREGULATORA,
PREREG1_540MA | PREREG1_VSYS_4_5V);
if (ret < 0)
goto out;
ret = pm860x_set_bits(info->i2c, PM8607_CHG_CTRL2, 0x1f,
CC2_ICHG_500MA);
if (ret < 0)
goto out;
ret = pm860x_set_bits(info->i2c, PM8607_CHG_CTRL3, (0xf << 4),
CC3_270MIN_TIMEOUT);
if (ret < 0)
goto out;
ret = pm860x_set_bits(info->i2c, PM8607_CHG_CTRL4,
CC4_IFCHG_MON_EN | CC4_BTEMP_MON_EN,
CC4_IFCHG_MON_EN | CC4_BTEMP_MON_EN);
if (ret < 0)
goto out;
ret = pm860x_set_bits(info->i2c, PM8607_CHG_CTRL6,
CC6_BAT_OV_EN | CC6_BAT_UV_EN |
CC6_UV_VBAT_SET,
CC6_BAT_OV_EN | CC6_BAT_UV_EN |
CC6_UV_VBAT_SET);
if (ret < 0)
goto out;
ret = pm860x_set_bits(info->i2c, PM8607_CHG_CTRL7,
CC7_BAT_REM_EN | CC7_IFSM_EN,
CC7_BAT_REM_EN | CC7_IFSM_EN);
if (ret < 0)
goto out;
ret = pm860x_set_bits(info->i2c, PM8607_CHG_CTRL1, 3,
CC1_MODE_FASTCHARGE);
set_vchg_threshold(info, VCHG_NORMAL_LOW, VCHG_NORMAL_HIGH);
out:
return ret;
}
static void stop_charge(struct pm860x_charger_info *info, int vbatt)
{
dev_dbg(info->dev, "Stop charging!\n");
pm860x_set_bits(info->i2c, PM8607_CHG_CTRL1, 3, CC1_MODE_OFF);
if (vbatt > CHARGE_THRESHOLD && info->online)
set_vbatt_threshold(info, CHARGE_THRESHOLD, 0);
}
static void power_off_notification(struct pm860x_charger_info *info)
{
dev_dbg(info->dev, "Power-off notification!\n");
}
static int set_charging_fsm(struct pm860x_charger_info *info)
{
struct power_supply *psy;
union power_supply_propval data;
unsigned char fsm_state[][16] = { "init", "discharge", "precharge",
"fastcharge",
};
int ret;
int vbatt;
psy = power_supply_get_by_name(pm860x_supplied_to[0]);
if (!psy)
return -EINVAL;
ret = psy->get_property(psy, POWER_SUPPLY_PROP_VOLTAGE_NOW, &data);
if (ret)
return ret;
vbatt = data.intval / 1000;
ret = psy->get_property(psy, POWER_SUPPLY_PROP_PRESENT, &data);
if (ret)
return ret;
mutex_lock(&info->lock);
info->present = data.intval;
dev_dbg(info->dev, "Entering FSM:%s, Charger:%s, Battery:%s, "
"Allowed:%d\n",
&fsm_state[info->state][0],
(info->online) ? "online" : "N/A",
(info->present) ? "present" : "N/A", info->allowed);
dev_dbg(info->dev, "set_charging_fsm:vbatt:%d(mV)\n", vbatt);
switch (info->state) {
case FSM_INIT:
if (info->online && info->present && info->allowed) {
if (vbatt < PRECHARGE_THRESHOLD) {
info->state = FSM_PRECHARGE;
start_precharge(info);
} else if (vbatt > DISCHARGE_THRESHOLD) {
info->state = FSM_DISCHARGE;
stop_charge(info, vbatt);
} else if (vbatt < DISCHARGE_THRESHOLD) {
info->state = FSM_FASTCHARGE;
start_fastcharge(info);
}
} else {
if (vbatt < POWEROFF_THRESHOLD) {
power_off_notification(info);
} else {
info->state = FSM_DISCHARGE;
stop_charge(info, vbatt);
}
}
break;
case FSM_PRECHARGE:
if (info->online && info->present && info->allowed) {
if (vbatt > PRECHARGE_THRESHOLD) {
info->state = FSM_FASTCHARGE;
start_fastcharge(info);
}
} else {
info->state = FSM_DISCHARGE;
stop_charge(info, vbatt);
}
break;
case FSM_FASTCHARGE:
if (info->online && info->present && info->allowed) {
if (vbatt < PRECHARGE_THRESHOLD) {
info->state = FSM_PRECHARGE;
start_precharge(info);
}
} else {
info->state = FSM_DISCHARGE;
stop_charge(info, vbatt);
}
break;
case FSM_DISCHARGE:
if (info->online && info->present && info->allowed) {
if (vbatt < PRECHARGE_THRESHOLD) {
info->state = FSM_PRECHARGE;
start_precharge(info);
} else if (vbatt < DISCHARGE_THRESHOLD) {
info->state = FSM_FASTCHARGE;
start_fastcharge(info);
}
} else {
if (vbatt < POWEROFF_THRESHOLD)
power_off_notification(info);
else if (vbatt > CHARGE_THRESHOLD && info->online)
set_vbatt_threshold(info, CHARGE_THRESHOLD, 0);
}
break;
default:
dev_warn(info->dev, "FSM meets wrong state:%d\n",
info->state);
break;
}
dev_dbg(info->dev,
"Out FSM:%s, Charger:%s, Battery:%s, Allowed:%d\n",
&fsm_state[info->state][0],
(info->online) ? "online" : "N/A",
(info->present) ? "present" : "N/A", info->allowed);
mutex_unlock(&info->lock);
return 0;
}
static irqreturn_t pm860x_charger_handler(int irq, void *data)
{
struct pm860x_charger_info *info = data;
int ret;
mutex_lock(&info->lock);
ret = pm860x_reg_read(info->i2c, PM8607_STATUS_2);
if (ret < 0) {
mutex_unlock(&info->lock);
goto out;
}
if (ret & STATUS2_CHG) {
info->online = 1;
info->allowed = 1;
} else {
info->online = 0;
info->allowed = 0;
}
mutex_unlock(&info->lock);
dev_dbg(info->dev, "%s, Charger:%s, Allowed:%d\n", __func__,
(info->online) ? "online" : "N/A", info->allowed);
set_charging_fsm(info);
power_supply_changed(&info->usb);
out:
return IRQ_HANDLED;
}
static irqreturn_t pm860x_temp_handler(int irq, void *data)
{
struct power_supply *psy;
struct pm860x_charger_info *info = data;
union power_supply_propval temp;
int value;
int ret;
psy = power_supply_get_by_name(pm860x_supplied_to[0]);
if (!psy)
goto out;
ret = psy->get_property(psy, POWER_SUPPLY_PROP_TEMP, &temp);
if (ret)
goto out;
value = temp.intval / 10;
mutex_lock(&info->lock);
if (value < -10 || value > 40)
info->allowed = 0;
else
info->allowed = 1;
dev_dbg(info->dev, "%s, Allowed: %d\n", __func__, info->allowed);
mutex_unlock(&info->lock);
set_charging_fsm(info);
out:
return IRQ_HANDLED;
}
static irqreturn_t pm860x_exception_handler(int irq, void *data)
{
struct pm860x_charger_info *info = data;
mutex_lock(&info->lock);
info->allowed = 0;
mutex_unlock(&info->lock);
dev_dbg(info->dev, "%s, irq: %d\n", __func__, irq);
set_charging_fsm(info);
return IRQ_HANDLED;
}
static irqreturn_t pm860x_done_handler(int irq, void *data)
{
struct pm860x_charger_info *info = data;
struct power_supply *psy;
union power_supply_propval val;
int ret;
int vbatt;
mutex_lock(&info->lock);
if (info->state == FSM_PRECHARGE) {
info->allowed = 1;
goto out;
}
mdelay(5);
info->allowed = 0;
psy = power_supply_get_by_name(pm860x_supplied_to[0]);
if (!psy)
goto out;
ret = psy->get_property(psy, POWER_SUPPLY_PROP_VOLTAGE_NOW, &val);
if (ret)
goto out;
vbatt = val.intval / 1000;
ret = pm860x_reg_read(info->i2c, PM8607_STATUS_2);
if (ret < 0)
goto out;
if (vbatt > CHARGE_THRESHOLD && ret & STATUS2_CHG)
psy->set_property(psy, POWER_SUPPLY_PROP_CHARGE_FULL, &val);
out:
mutex_unlock(&info->lock);
dev_dbg(info->dev, "%s, Allowed: %d\n", __func__, info->allowed);
set_charging_fsm(info);
return IRQ_HANDLED;
}
static irqreturn_t pm860x_vbattery_handler(int irq, void *data)
{
struct pm860x_charger_info *info = data;
mutex_lock(&info->lock);
set_vbatt_threshold(info, 0, 0);
if (info->present && info->online)
info->allowed = 1;
else
info->allowed = 0;
mutex_unlock(&info->lock);
dev_dbg(info->dev, "%s, Allowed: %d\n", __func__, info->allowed);
set_charging_fsm(info);
return IRQ_HANDLED;
}
static irqreturn_t pm860x_vchg_handler(int irq, void *data)
{
struct pm860x_charger_info *info = data;
int vchg = 0;
if (info->present)
goto out;
measure_vchg(info, &vchg);
mutex_lock(&info->lock);
if (!info->online) {
int status;
status = pm860x_reg_read(info->i2c_8606, PM8606_FLAGS);
if (status & OVER_TEMP_FLAG) {
pm860x_set_bits(info->i2c_8606, PM8606_FLAGS,
OVER_TEMP_FLAG, OVER_TEMP_FLAG);
pm860x_set_bits(info->i2c_8606,
PM8606_VSYS,
OVTEMP_AUTORECOVER,
OVTEMP_AUTORECOVER);
dev_dbg(info->dev,
"%s, pm8606 over-temp occure\n", __func__);
}
}
if (vchg > VCHG_NORMAL_CHECK) {
set_vchg_threshold(info, VCHG_OVP_LOW, 0);
info->allowed = 0;
dev_dbg(info->dev,
"%s,pm8607 over-vchg occure,vchg = %dmv\n",
__func__, vchg);
} else if (vchg < VCHG_OVP_LOW) {
set_vchg_threshold(info, VCHG_NORMAL_LOW,
VCHG_NORMAL_HIGH);
info->allowed = 1;
dev_dbg(info->dev,
"%s,pm8607 over-vchg recover,vchg = %dmv\n",
__func__, vchg);
}
mutex_unlock(&info->lock);
dev_dbg(info->dev, "%s, Allowed: %d\n", __func__, info->allowed);
set_charging_fsm(info);
out:
return IRQ_HANDLED;
}
static int pm860x_usb_get_prop(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
struct pm860x_charger_info *info =
dev_get_drvdata(psy->dev->parent);
switch (psp) {
case POWER_SUPPLY_PROP_STATUS:
if (info->state == FSM_FASTCHARGE ||
info->state == FSM_PRECHARGE)
val->intval = POWER_SUPPLY_STATUS_CHARGING;
else
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
break;
case POWER_SUPPLY_PROP_ONLINE:
val->intval = info->online;
break;
default:
return -ENODEV;
}
return 0;
}
static int pm860x_init_charger(struct pm860x_charger_info *info)
{
int ret;
ret = pm860x_reg_read(info->i2c, PM8607_STATUS_2);
if (ret < 0)
return ret;
mutex_lock(&info->lock);
info->state = FSM_INIT;
if (ret & STATUS2_CHG) {
info->online = 1;
info->allowed = 1;
} else {
info->online = 0;
info->allowed = 0;
}
mutex_unlock(&info->lock);
set_charging_fsm(info);
return 0;
}
static int pm860x_charger_probe(struct platform_device *pdev)
{
struct pm860x_chip *chip = dev_get_drvdata(pdev->dev.parent);
struct pm860x_charger_info *info;
int ret;
int count;
int i;
int j;
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
count = pdev->num_resources;
for (i = 0, j = 0; i < count; i++) {
info->irq[j] = platform_get_irq(pdev, i);
if (info->irq[j] < 0)
continue;
j++;
}
info->irq_nums = j;
info->chip = chip;
info->i2c =
(chip->id == CHIP_PM8607) ? chip->client : chip->companion;
info->i2c_8606 =
(chip->id == CHIP_PM8607) ? chip->companion : chip->client;
if (!info->i2c_8606) {
dev_err(&pdev->dev, "Missed I2C address of 88PM8606!\n");
ret = -EINVAL;
goto out;
}
info->dev = &pdev->dev;
set_vchg_threshold(info, VCHG_NORMAL_LOW, VCHG_OVP_LOW);
mutex_init(&info->lock);
platform_set_drvdata(pdev, info);
info->usb.name = "usb";
info->usb.type = POWER_SUPPLY_TYPE_USB;
info->usb.supplied_to = pm860x_supplied_to;
info->usb.num_supplicants = ARRAY_SIZE(pm860x_supplied_to);
info->usb.properties = pm860x_usb_props;
info->usb.num_properties = ARRAY_SIZE(pm860x_usb_props);
info->usb.get_property = pm860x_usb_get_prop;
ret = power_supply_register(&pdev->dev, &info->usb);
if (ret)
goto out;
pm860x_init_charger(info);
for (i = 0; i < ARRAY_SIZE(info->irq); i++) {
ret = request_threaded_irq(info->irq[i], NULL,
pm860x_irq_descs[i].handler,
IRQF_ONESHOT, pm860x_irq_descs[i].name, info);
if (ret < 0) {
dev_err(chip->dev, "Failed to request IRQ: #%d: %d\n",
info->irq[i], ret);
goto out_irq;
}
}
return 0;
out_irq:
while (--i >= 0)
free_irq(info->irq[i], info);
out:
kfree(info);
return ret;
}
static int pm860x_charger_remove(struct platform_device *pdev)
{
struct pm860x_charger_info *info = platform_get_drvdata(pdev);
int i;
platform_set_drvdata(pdev, NULL);
power_supply_unregister(&info->usb);
free_irq(info->irq[0], info);
for (i = 0; i < info->irq_nums; i++)
free_irq(info->irq[i], info);
kfree(info);
return 0;
}
