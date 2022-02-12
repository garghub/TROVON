static int bq20z75_read_word_data(struct i2c_client *client, u8 address)
{
struct bq20z75_info *bq20z75_device = i2c_get_clientdata(client);
s32 ret = 0;
int retries = 1;
if (bq20z75_device->pdata)
retries = max(bq20z75_device->pdata->i2c_retry_count + 1, 1);
while (retries > 0) {
ret = i2c_smbus_read_word_data(client, address);
if (ret >= 0)
break;
retries--;
}
if (ret < 0) {
dev_dbg(&client->dev,
"%s: i2c read at address 0x%x failed\n",
__func__, address);
return ret;
}
return le16_to_cpu(ret);
}
static int bq20z75_write_word_data(struct i2c_client *client, u8 address,
u16 value)
{
struct bq20z75_info *bq20z75_device = i2c_get_clientdata(client);
s32 ret = 0;
int retries = 1;
if (bq20z75_device->pdata)
retries = max(bq20z75_device->pdata->i2c_retry_count + 1, 1);
while (retries > 0) {
ret = i2c_smbus_write_word_data(client, address,
le16_to_cpu(value));
if (ret >= 0)
break;
retries--;
}
if (ret < 0) {
dev_dbg(&client->dev,
"%s: i2c write to address 0x%x failed\n",
__func__, address);
return ret;
}
return 0;
}
static int bq20z75_get_battery_presence_and_health(
struct i2c_client *client, enum power_supply_property psp,
union power_supply_propval *val)
{
s32 ret;
struct bq20z75_info *bq20z75_device = i2c_get_clientdata(client);
if (psp == POWER_SUPPLY_PROP_PRESENT &&
bq20z75_device->gpio_detect) {
ret = gpio_get_value(
bq20z75_device->pdata->battery_detect);
if (ret == bq20z75_device->pdata->battery_detect_present)
val->intval = 1;
else
val->intval = 0;
bq20z75_device->is_present = val->intval;
return ret;
}
ret = bq20z75_write_word_data(client,
bq20z75_data[REG_MANUFACTURER_DATA].addr,
MANUFACTURER_ACCESS_STATUS);
if (ret < 0) {
if (psp == POWER_SUPPLY_PROP_PRESENT)
val->intval = 0;
return ret;
}
ret = bq20z75_read_word_data(client,
bq20z75_data[REG_MANUFACTURER_DATA].addr);
if (ret < 0)
return ret;
if (ret < bq20z75_data[REG_MANUFACTURER_DATA].min_value ||
ret > bq20z75_data[REG_MANUFACTURER_DATA].max_value) {
val->intval = 0;
return 0;
}
ret &= 0x0F00;
ret >>= 8;
if (psp == POWER_SUPPLY_PROP_PRESENT) {
if (ret == 0x0F)
val->intval = 0;
else
val->intval = 1;
} else if (psp == POWER_SUPPLY_PROP_HEALTH) {
if (ret == 0x09)
val->intval = POWER_SUPPLY_HEALTH_UNSPEC_FAILURE;
else if (ret == 0x0B)
val->intval = POWER_SUPPLY_HEALTH_OVERHEAT;
else if (ret == 0x0C)
val->intval = POWER_SUPPLY_HEALTH_DEAD;
else
val->intval = POWER_SUPPLY_HEALTH_GOOD;
}
return 0;
}
static int bq20z75_get_battery_property(struct i2c_client *client,
int reg_offset, enum power_supply_property psp,
union power_supply_propval *val)
{
s32 ret;
ret = bq20z75_read_word_data(client,
bq20z75_data[reg_offset].addr);
if (ret < 0)
return ret;
if (bq20z75_data[reg_offset].min_value < 0)
ret = (s16)ret;
if (ret >= bq20z75_data[reg_offset].min_value &&
ret <= bq20z75_data[reg_offset].max_value) {
val->intval = ret;
if (psp == POWER_SUPPLY_PROP_STATUS) {
if (ret & BATTERY_FULL_CHARGED)
val->intval = POWER_SUPPLY_STATUS_FULL;
else if (ret & BATTERY_FULL_DISCHARGED)
val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
else if (ret & BATTERY_DISCHARGING)
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
else
val->intval = POWER_SUPPLY_STATUS_CHARGING;
}
} else {
if (psp == POWER_SUPPLY_PROP_STATUS)
val->intval = POWER_SUPPLY_STATUS_UNKNOWN;
else
val->intval = 0;
}
return 0;
}
static void bq20z75_unit_adjustment(struct i2c_client *client,
enum power_supply_property psp, union power_supply_propval *val)
{
#define BASE_UNIT_CONVERSION 1000
#define BATTERY_MODE_CAP_MULT_WATT (10 * BASE_UNIT_CONVERSION)
#define TIME_UNIT_CONVERSION 60
#define TEMP_KELVIN_TO_CELSIUS 2731
switch (psp) {
case POWER_SUPPLY_PROP_ENERGY_NOW:
case POWER_SUPPLY_PROP_ENERGY_FULL:
case POWER_SUPPLY_PROP_ENERGY_FULL_DESIGN:
val->intval *= BATTERY_MODE_CAP_MULT_WATT;
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
case POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN:
case POWER_SUPPLY_PROP_CURRENT_NOW:
case POWER_SUPPLY_PROP_CHARGE_NOW:
case POWER_SUPPLY_PROP_CHARGE_FULL:
case POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN:
val->intval *= BASE_UNIT_CONVERSION;
break;
case POWER_SUPPLY_PROP_TEMP:
val->intval -= TEMP_KELVIN_TO_CELSIUS;
break;
case POWER_SUPPLY_PROP_TIME_TO_EMPTY_AVG:
case POWER_SUPPLY_PROP_TIME_TO_FULL_AVG:
val->intval *= TIME_UNIT_CONVERSION;
break;
default:
dev_dbg(&client->dev,
"%s: no need for unit conversion %d\n", __func__, psp);
}
}
static enum bq20z75_battery_mode
bq20z75_set_battery_mode(struct i2c_client *client,
enum bq20z75_battery_mode mode)
{
int ret, original_val;
original_val = bq20z75_read_word_data(client, BATTERY_MODE_OFFSET);
if (original_val < 0)
return original_val;
if ((original_val & BATTERY_MODE_MASK) == mode)
return mode;
if (mode == BATTERY_MODE_AMPS)
ret = original_val & ~BATTERY_MODE_MASK;
else
ret = original_val | BATTERY_MODE_MASK;
ret = bq20z75_write_word_data(client, BATTERY_MODE_OFFSET, ret);
if (ret < 0)
return ret;
return original_val & BATTERY_MODE_MASK;
}
static int bq20z75_get_battery_capacity(struct i2c_client *client,
int reg_offset, enum power_supply_property psp,
union power_supply_propval *val)
{
s32 ret;
enum bq20z75_battery_mode mode = BATTERY_MODE_WATTS;
if (power_supply_is_amp_property(psp))
mode = BATTERY_MODE_AMPS;
mode = bq20z75_set_battery_mode(client, mode);
if (mode < 0)
return mode;
ret = bq20z75_read_word_data(client, bq20z75_data[reg_offset].addr);
if (ret < 0)
return ret;
if (psp == POWER_SUPPLY_PROP_CAPACITY) {
val->intval = min(ret, 100);
} else
val->intval = ret;
ret = bq20z75_set_battery_mode(client, mode);
if (ret < 0)
return ret;
return 0;
}
static int bq20z75_get_battery_serial_number(struct i2c_client *client,
union power_supply_propval *val)
{
int ret;
ret = bq20z75_read_word_data(client,
bq20z75_data[REG_SERIAL_NUMBER].addr);
if (ret < 0)
return ret;
ret = sprintf(bq20z75_serial, "%04x", ret);
val->strval = bq20z75_serial;
return 0;
}
static int bq20z75_get_property_index(struct i2c_client *client,
enum power_supply_property psp)
{
int count;
for (count = 0; count < ARRAY_SIZE(bq20z75_data); count++)
if (psp == bq20z75_data[count].psp)
return count;
dev_warn(&client->dev,
"%s: Invalid Property - %d\n", __func__, psp);
return -EINVAL;
}
static int bq20z75_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
int ret = 0;
struct bq20z75_info *bq20z75_device = container_of(psy,
struct bq20z75_info, power_supply);
struct i2c_client *client = bq20z75_device->client;
switch (psp) {
case POWER_SUPPLY_PROP_PRESENT:
case POWER_SUPPLY_PROP_HEALTH:
ret = bq20z75_get_battery_presence_and_health(client, psp, val);
if (psp == POWER_SUPPLY_PROP_PRESENT)
return 0;
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = POWER_SUPPLY_TECHNOLOGY_LION;
break;
case POWER_SUPPLY_PROP_ENERGY_NOW:
case POWER_SUPPLY_PROP_ENERGY_FULL:
case POWER_SUPPLY_PROP_ENERGY_FULL_DESIGN:
case POWER_SUPPLY_PROP_CHARGE_NOW:
case POWER_SUPPLY_PROP_CHARGE_FULL:
case POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN:
case POWER_SUPPLY_PROP_CAPACITY:
ret = bq20z75_get_property_index(client, psp);
if (ret < 0)
break;
ret = bq20z75_get_battery_capacity(client, ret, psp, val);
break;
case POWER_SUPPLY_PROP_SERIAL_NUMBER:
ret = bq20z75_get_battery_serial_number(client, val);
break;
case POWER_SUPPLY_PROP_STATUS:
case POWER_SUPPLY_PROP_CYCLE_COUNT:
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
case POWER_SUPPLY_PROP_CURRENT_NOW:
case POWER_SUPPLY_PROP_TEMP:
case POWER_SUPPLY_PROP_TIME_TO_EMPTY_AVG:
case POWER_SUPPLY_PROP_TIME_TO_FULL_AVG:
case POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN:
ret = bq20z75_get_property_index(client, psp);
if (ret < 0)
break;
ret = bq20z75_get_battery_property(client, ret, psp, val);
break;
default:
dev_err(&client->dev,
"%s: INVALID property\n", __func__);
return -EINVAL;
}
if (!bq20z75_device->enable_detection)
goto done;
if (!bq20z75_device->gpio_detect &&
bq20z75_device->is_present != (ret >= 0)) {
bq20z75_device->is_present = (ret >= 0);
power_supply_changed(&bq20z75_device->power_supply);
}
done:
if (!ret) {
bq20z75_unit_adjustment(client, psp, val);
}
dev_dbg(&client->dev,
"%s: property = %d, value = %x\n", __func__, psp, val->intval);
if (ret && bq20z75_device->is_present)
return ret;
if (ret)
return -ENODATA;
return 0;
}
static irqreturn_t bq20z75_irq(int irq, void *devid)
{
struct power_supply *battery = devid;
power_supply_changed(battery);
return IRQ_HANDLED;
}
static int __devinit bq20z75_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct bq20z75_info *bq20z75_device;
struct bq20z75_platform_data *pdata = client->dev.platform_data;
int rc;
int irq;
bq20z75_device = kzalloc(sizeof(struct bq20z75_info), GFP_KERNEL);
if (!bq20z75_device)
return -ENOMEM;
bq20z75_device->client = client;
bq20z75_device->enable_detection = false;
bq20z75_device->gpio_detect = false;
bq20z75_device->power_supply.name = "battery";
bq20z75_device->power_supply.type = POWER_SUPPLY_TYPE_BATTERY;
bq20z75_device->power_supply.properties = bq20z75_properties;
bq20z75_device->power_supply.num_properties =
ARRAY_SIZE(bq20z75_properties);
bq20z75_device->power_supply.get_property = bq20z75_get_property;
if (pdata) {
bq20z75_device->gpio_detect =
gpio_is_valid(pdata->battery_detect);
bq20z75_device->pdata = pdata;
}
i2c_set_clientdata(client, bq20z75_device);
if (!bq20z75_device->gpio_detect)
goto skip_gpio;
rc = gpio_request(pdata->battery_detect, dev_name(&client->dev));
if (rc) {
dev_warn(&client->dev, "Failed to request gpio: %d\n", rc);
bq20z75_device->gpio_detect = false;
goto skip_gpio;
}
rc = gpio_direction_input(pdata->battery_detect);
if (rc) {
dev_warn(&client->dev, "Failed to get gpio as input: %d\n", rc);
gpio_free(pdata->battery_detect);
bq20z75_device->gpio_detect = false;
goto skip_gpio;
}
irq = gpio_to_irq(pdata->battery_detect);
if (irq <= 0) {
dev_warn(&client->dev, "Failed to get gpio as irq: %d\n", irq);
gpio_free(pdata->battery_detect);
bq20z75_device->gpio_detect = false;
goto skip_gpio;
}
rc = request_irq(irq, bq20z75_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
dev_name(&client->dev), &bq20z75_device->power_supply);
if (rc) {
dev_warn(&client->dev, "Failed to request irq: %d\n", rc);
gpio_free(pdata->battery_detect);
bq20z75_device->gpio_detect = false;
goto skip_gpio;
}
bq20z75_device->irq = irq;
skip_gpio:
rc = power_supply_register(&client->dev, &bq20z75_device->power_supply);
if (rc) {
dev_err(&client->dev,
"%s: Failed to register power supply\n", __func__);
goto exit_psupply;
}
dev_info(&client->dev,
"%s: battery gas gauge device registered\n", client->name);
return 0;
exit_psupply:
if (bq20z75_device->irq)
free_irq(bq20z75_device->irq, &bq20z75_device->power_supply);
if (bq20z75_device->gpio_detect)
gpio_free(pdata->battery_detect);
kfree(bq20z75_device);
return rc;
}
static int __devexit bq20z75_remove(struct i2c_client *client)
{
struct bq20z75_info *bq20z75_device = i2c_get_clientdata(client);
if (bq20z75_device->irq)
free_irq(bq20z75_device->irq, &bq20z75_device->power_supply);
if (bq20z75_device->gpio_detect)
gpio_free(bq20z75_device->pdata->battery_detect);
power_supply_unregister(&bq20z75_device->power_supply);
kfree(bq20z75_device);
bq20z75_device = NULL;
return 0;
}
static int bq20z75_suspend(struct i2c_client *client,
pm_message_t state)
{
struct bq20z75_info *bq20z75_device = i2c_get_clientdata(client);
s32 ret;
ret = bq20z75_write_word_data(client,
bq20z75_data[REG_MANUFACTURER_DATA].addr,
MANUFACTURER_ACCESS_SLEEP);
if (bq20z75_device->is_present && ret < 0)
return ret;
return 0;
}
static int __init bq20z75_battery_init(void)
{
return i2c_add_driver(&bq20z75_battery_driver);
}
static void __exit bq20z75_battery_exit(void)
{
i2c_del_driver(&bq20z75_battery_driver);
}
