static int sbs_read_word_data(struct i2c_client *client, u8 address)
{
struct sbs_info *chip = i2c_get_clientdata(client);
s32 ret = 0;
int retries = 1;
if (chip->pdata)
retries = max(chip->pdata->i2c_retry_count + 1, 1);
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
static int sbs_read_string_data(struct i2c_client *client, u8 address,
char *values)
{
struct sbs_info *chip = i2c_get_clientdata(client);
s32 ret = 0, block_length = 0;
int retries_length = 1, retries_block = 1;
u8 block_buffer[I2C_SMBUS_BLOCK_MAX + 1];
if (chip->pdata) {
retries_length = max(chip->pdata->i2c_retry_count + 1, 1);
retries_block = max(chip->pdata->i2c_retry_count + 1, 1);
}
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_I2C_BLOCK)){
return -ENODEV;
}
while (retries_length > 0) {
ret = i2c_smbus_read_byte_data(client, address);
if (ret >= 0)
break;
retries_length--;
}
if (ret < 0) {
dev_dbg(&client->dev,
"%s: i2c read at address 0x%x failed\n",
__func__, address);
return ret;
}
block_length = ret;
if (block_length > I2C_SMBUS_BLOCK_MAX) {
dev_err(&client->dev,
"%s: Returned block_length is longer than 0x%x\n",
__func__, I2C_SMBUS_BLOCK_MAX);
return -EINVAL;
}
while (retries_block > 0) {
ret = i2c_smbus_read_i2c_block_data(
client, address,
block_length + 1, block_buffer);
if (ret >= 0)
break;
retries_block--;
}
if (ret < 0) {
dev_dbg(&client->dev,
"%s: i2c read at address 0x%x failed\n",
__func__, address);
return ret;
}
memcpy(values, block_buffer + 1, block_length);
values[block_length] = '\0';
return le16_to_cpu(ret);
}
static int sbs_write_word_data(struct i2c_client *client, u8 address,
u16 value)
{
struct sbs_info *chip = i2c_get_clientdata(client);
s32 ret = 0;
int retries = 1;
if (chip->pdata)
retries = max(chip->pdata->i2c_retry_count + 1, 1);
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
static int sbs_get_battery_presence_and_health(
struct i2c_client *client, enum power_supply_property psp,
union power_supply_propval *val)
{
s32 ret;
struct sbs_info *chip = i2c_get_clientdata(client);
if (psp == POWER_SUPPLY_PROP_PRESENT &&
chip->gpio_detect) {
ret = gpio_get_value(chip->pdata->battery_detect);
if (ret == chip->pdata->battery_detect_present)
val->intval = 1;
else
val->intval = 0;
chip->is_present = val->intval;
return ret;
}
ret = sbs_write_word_data(client, sbs_data[REG_MANUFACTURER_DATA].addr,
MANUFACTURER_ACCESS_STATUS);
if (ret < 0) {
if (psp == POWER_SUPPLY_PROP_PRESENT)
val->intval = 0;
return ret;
}
ret = sbs_read_word_data(client, sbs_data[REG_MANUFACTURER_DATA].addr);
if (ret < 0)
return ret;
if (ret < sbs_data[REG_MANUFACTURER_DATA].min_value ||
ret > sbs_data[REG_MANUFACTURER_DATA].max_value) {
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
static int sbs_get_battery_property(struct i2c_client *client,
int reg_offset, enum power_supply_property psp,
union power_supply_propval *val)
{
struct sbs_info *chip = i2c_get_clientdata(client);
s32 ret;
ret = sbs_read_word_data(client, sbs_data[reg_offset].addr);
if (ret < 0)
return ret;
if (sbs_data[reg_offset].min_value < 0)
ret = (s16)ret;
if (ret >= sbs_data[reg_offset].min_value &&
ret <= sbs_data[reg_offset].max_value) {
val->intval = ret;
if (psp != POWER_SUPPLY_PROP_STATUS)
return 0;
if (ret & BATTERY_FULL_CHARGED)
val->intval = POWER_SUPPLY_STATUS_FULL;
else if (ret & BATTERY_FULL_DISCHARGED)
val->intval = POWER_SUPPLY_STATUS_NOT_CHARGING;
else if (ret & BATTERY_DISCHARGING)
val->intval = POWER_SUPPLY_STATUS_DISCHARGING;
else
val->intval = POWER_SUPPLY_STATUS_CHARGING;
if (chip->poll_time == 0)
chip->last_state = val->intval;
else if (chip->last_state != val->intval) {
cancel_delayed_work_sync(&chip->work);
power_supply_changed(chip->power_supply);
chip->poll_time = 0;
}
} else {
if (psp == POWER_SUPPLY_PROP_STATUS)
val->intval = POWER_SUPPLY_STATUS_UNKNOWN;
else
val->intval = 0;
}
return 0;
}
static int sbs_get_battery_string_property(struct i2c_client *client,
int reg_offset, enum power_supply_property psp, char *val)
{
s32 ret;
ret = sbs_read_string_data(client, sbs_data[reg_offset].addr, val);
if (ret < 0)
return ret;
return 0;
}
static void sbs_unit_adjustment(struct i2c_client *client,
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
case POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN:
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
static enum sbs_battery_mode sbs_set_battery_mode(struct i2c_client *client,
enum sbs_battery_mode mode)
{
int ret, original_val;
original_val = sbs_read_word_data(client, BATTERY_MODE_OFFSET);
if (original_val < 0)
return original_val;
if ((original_val & BATTERY_MODE_MASK) == mode)
return mode;
if (mode == BATTERY_MODE_AMPS)
ret = original_val & ~BATTERY_MODE_MASK;
else
ret = original_val | BATTERY_MODE_MASK;
ret = sbs_write_word_data(client, BATTERY_MODE_OFFSET, ret);
if (ret < 0)
return ret;
return original_val & BATTERY_MODE_MASK;
}
static int sbs_get_battery_capacity(struct i2c_client *client,
int reg_offset, enum power_supply_property psp,
union power_supply_propval *val)
{
s32 ret;
enum sbs_battery_mode mode = BATTERY_MODE_WATTS;
if (power_supply_is_amp_property(psp))
mode = BATTERY_MODE_AMPS;
mode = sbs_set_battery_mode(client, mode);
if (mode < 0)
return mode;
ret = sbs_read_word_data(client, sbs_data[reg_offset].addr);
if (ret < 0)
return ret;
if (psp == POWER_SUPPLY_PROP_CAPACITY) {
val->intval = min(ret, 100);
} else
val->intval = ret;
ret = sbs_set_battery_mode(client, mode);
if (ret < 0)
return ret;
return 0;
}
static int sbs_get_battery_serial_number(struct i2c_client *client,
union power_supply_propval *val)
{
int ret;
ret = sbs_read_word_data(client, sbs_data[REG_SERIAL_NUMBER].addr);
if (ret < 0)
return ret;
ret = sprintf(sbs_serial, "%04x", ret);
val->strval = sbs_serial;
return 0;
}
static int sbs_get_property_index(struct i2c_client *client,
enum power_supply_property psp)
{
int count;
for (count = 0; count < ARRAY_SIZE(sbs_data); count++)
if (psp == sbs_data[count].psp)
return count;
dev_warn(&client->dev,
"%s: Invalid Property - %d\n", __func__, psp);
return -EINVAL;
}
static int sbs_get_property(struct power_supply *psy,
enum power_supply_property psp,
union power_supply_propval *val)
{
int ret = 0;
struct sbs_info *chip = power_supply_get_drvdata(psy);
struct i2c_client *client = chip->client;
switch (psp) {
case POWER_SUPPLY_PROP_PRESENT:
case POWER_SUPPLY_PROP_HEALTH:
ret = sbs_get_battery_presence_and_health(client, psp, val);
if (psp == POWER_SUPPLY_PROP_PRESENT)
return 0;
break;
case POWER_SUPPLY_PROP_TECHNOLOGY:
val->intval = POWER_SUPPLY_TECHNOLOGY_LION;
goto done;
case POWER_SUPPLY_PROP_ENERGY_NOW:
case POWER_SUPPLY_PROP_ENERGY_FULL:
case POWER_SUPPLY_PROP_ENERGY_FULL_DESIGN:
case POWER_SUPPLY_PROP_CHARGE_NOW:
case POWER_SUPPLY_PROP_CHARGE_FULL:
case POWER_SUPPLY_PROP_CHARGE_FULL_DESIGN:
case POWER_SUPPLY_PROP_CAPACITY:
ret = sbs_get_property_index(client, psp);
if (ret < 0)
break;
ret = sbs_get_battery_capacity(client, ret, psp, val);
break;
case POWER_SUPPLY_PROP_SERIAL_NUMBER:
ret = sbs_get_battery_serial_number(client, val);
break;
case POWER_SUPPLY_PROP_STATUS:
case POWER_SUPPLY_PROP_CYCLE_COUNT:
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
case POWER_SUPPLY_PROP_CURRENT_NOW:
case POWER_SUPPLY_PROP_TEMP:
case POWER_SUPPLY_PROP_TIME_TO_EMPTY_AVG:
case POWER_SUPPLY_PROP_TIME_TO_FULL_AVG:
case POWER_SUPPLY_PROP_VOLTAGE_MIN_DESIGN:
case POWER_SUPPLY_PROP_VOLTAGE_MAX_DESIGN:
ret = sbs_get_property_index(client, psp);
if (ret < 0)
break;
ret = sbs_get_battery_property(client, ret, psp, val);
break;
case POWER_SUPPLY_PROP_MODEL_NAME:
ret = sbs_get_property_index(client, psp);
if (ret < 0)
break;
ret = sbs_get_battery_string_property(client, ret, psp,
model_name);
val->strval = model_name;
break;
case POWER_SUPPLY_PROP_MANUFACTURER:
ret = sbs_get_property_index(client, psp);
if (ret < 0)
break;
ret = sbs_get_battery_string_property(client, ret, psp,
manufacturer);
val->strval = manufacturer;
break;
default:
dev_err(&client->dev,
"%s: INVALID property\n", __func__);
return -EINVAL;
}
if (!chip->enable_detection)
goto done;
if (!chip->gpio_detect &&
chip->is_present != (ret >= 0)) {
chip->is_present = (ret >= 0);
power_supply_changed(chip->power_supply);
}
done:
if (!ret) {
sbs_unit_adjustment(client, psp, val);
}
dev_dbg(&client->dev,
"%s: property = %d, value = %x\n", __func__, psp, val->intval);
if (ret && chip->is_present)
return ret;
if (ret)
return -ENODATA;
return 0;
}
static irqreturn_t sbs_irq(int irq, void *devid)
{
struct power_supply *battery = devid;
power_supply_changed(battery);
return IRQ_HANDLED;
}
static void sbs_external_power_changed(struct power_supply *psy)
{
struct sbs_info *chip = power_supply_get_drvdata(psy);
if (chip->ignore_changes > 0) {
chip->ignore_changes--;
return;
}
cancel_delayed_work_sync(&chip->work);
schedule_delayed_work(&chip->work, HZ);
chip->poll_time = chip->pdata->poll_retry_count;
}
static void sbs_delayed_work(struct work_struct *work)
{
struct sbs_info *chip;
s32 ret;
chip = container_of(work, struct sbs_info, work.work);
ret = sbs_read_word_data(chip->client, sbs_data[REG_STATUS].addr);
if (ret < 0) {
chip->poll_time = 0;
return;
}
if (ret & BATTERY_FULL_CHARGED)
ret = POWER_SUPPLY_STATUS_FULL;
else if (ret & BATTERY_FULL_DISCHARGED)
ret = POWER_SUPPLY_STATUS_NOT_CHARGING;
else if (ret & BATTERY_DISCHARGING)
ret = POWER_SUPPLY_STATUS_DISCHARGING;
else
ret = POWER_SUPPLY_STATUS_CHARGING;
if (chip->last_state != ret) {
chip->poll_time = 0;
power_supply_changed(chip->power_supply);
return;
}
if (chip->poll_time > 0) {
schedule_delayed_work(&chip->work, HZ);
chip->poll_time--;
return;
}
}
static struct sbs_platform_data *sbs_of_populate_pdata(
struct i2c_client *client)
{
struct device_node *of_node = client->dev.of_node;
struct sbs_platform_data *pdata = client->dev.platform_data;
enum of_gpio_flags gpio_flags;
int rc;
u32 prop;
if (!of_node)
return NULL;
if (pdata)
return pdata;
if (!of_get_property(of_node, "sbs,i2c-retry-count", NULL) &&
!of_get_property(of_node, "sbs,poll-retry-count", NULL) &&
!of_get_property(of_node, "sbs,battery-detect-gpios", NULL))
goto of_out;
pdata = devm_kzalloc(&client->dev, sizeof(struct sbs_platform_data),
GFP_KERNEL);
if (!pdata)
goto of_out;
rc = of_property_read_u32(of_node, "sbs,i2c-retry-count", &prop);
if (!rc)
pdata->i2c_retry_count = prop;
rc = of_property_read_u32(of_node, "sbs,poll-retry-count", &prop);
if (!rc)
pdata->poll_retry_count = prop;
if (!of_get_property(of_node, "sbs,battery-detect-gpios", NULL)) {
pdata->battery_detect = -1;
goto of_out;
}
pdata->battery_detect = of_get_named_gpio_flags(of_node,
"sbs,battery-detect-gpios", 0, &gpio_flags);
if (gpio_flags & OF_GPIO_ACTIVE_LOW)
pdata->battery_detect_present = 0;
else
pdata->battery_detect_present = 1;
of_out:
return pdata;
}
static struct sbs_platform_data *sbs_of_populate_pdata(
struct i2c_client *client)
{
return client->dev.platform_data;
}
static int sbs_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct sbs_info *chip;
struct power_supply_desc *sbs_desc;
struct sbs_platform_data *pdata = client->dev.platform_data;
struct power_supply_config psy_cfg = {};
int rc;
int irq;
sbs_desc = devm_kmemdup(&client->dev, &sbs_default_desc,
sizeof(*sbs_desc), GFP_KERNEL);
if (!sbs_desc)
return -ENOMEM;
sbs_desc->name = devm_kasprintf(&client->dev, GFP_KERNEL, "sbs-%s",
dev_name(&client->dev));
if (!sbs_desc->name)
return -ENOMEM;
chip = kzalloc(sizeof(struct sbs_info), GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->client = client;
chip->enable_detection = false;
chip->gpio_detect = false;
psy_cfg.of_node = client->dev.of_node;
psy_cfg.drv_data = chip;
chip->ignore_changes = 1;
chip->last_state = POWER_SUPPLY_STATUS_UNKNOWN;
pdata = sbs_of_populate_pdata(client);
if (pdata) {
chip->gpio_detect = gpio_is_valid(pdata->battery_detect);
chip->pdata = pdata;
}
i2c_set_clientdata(client, chip);
if (!chip->gpio_detect)
goto skip_gpio;
rc = gpio_request(pdata->battery_detect, dev_name(&client->dev));
if (rc) {
dev_warn(&client->dev, "Failed to request gpio: %d\n", rc);
chip->gpio_detect = false;
goto skip_gpio;
}
rc = gpio_direction_input(pdata->battery_detect);
if (rc) {
dev_warn(&client->dev, "Failed to get gpio as input: %d\n", rc);
gpio_free(pdata->battery_detect);
chip->gpio_detect = false;
goto skip_gpio;
}
irq = gpio_to_irq(pdata->battery_detect);
if (irq <= 0) {
dev_warn(&client->dev, "Failed to get gpio as irq: %d\n", irq);
gpio_free(pdata->battery_detect);
chip->gpio_detect = false;
goto skip_gpio;
}
rc = request_irq(irq, sbs_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
dev_name(&client->dev), chip->power_supply);
if (rc) {
dev_warn(&client->dev, "Failed to request irq: %d\n", rc);
gpio_free(pdata->battery_detect);
chip->gpio_detect = false;
goto skip_gpio;
}
chip->irq = irq;
skip_gpio:
rc = sbs_read_word_data(client, sbs_data[REG_STATUS].addr);
if (rc < 0) {
dev_err(&client->dev, "%s: Failed to get device status\n",
__func__);
goto exit_psupply;
}
chip->power_supply = power_supply_register(&client->dev, sbs_desc,
&psy_cfg);
if (IS_ERR(chip->power_supply)) {
dev_err(&client->dev,
"%s: Failed to register power supply\n", __func__);
rc = PTR_ERR(chip->power_supply);
goto exit_psupply;
}
dev_info(&client->dev,
"%s: battery gas gauge device registered\n", client->name);
INIT_DELAYED_WORK(&chip->work, sbs_delayed_work);
chip->enable_detection = true;
return 0;
exit_psupply:
if (chip->irq)
free_irq(chip->irq, chip->power_supply);
if (chip->gpio_detect)
gpio_free(pdata->battery_detect);
kfree(chip);
return rc;
}
static int sbs_remove(struct i2c_client *client)
{
struct sbs_info *chip = i2c_get_clientdata(client);
if (chip->irq)
free_irq(chip->irq, chip->power_supply);
if (chip->gpio_detect)
gpio_free(chip->pdata->battery_detect);
power_supply_unregister(chip->power_supply);
cancel_delayed_work_sync(&chip->work);
kfree(chip);
chip = NULL;
return 0;
}
static int sbs_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct sbs_info *chip = i2c_get_clientdata(client);
s32 ret;
if (chip->poll_time > 0)
cancel_delayed_work_sync(&chip->work);
ret = sbs_write_word_data(client, sbs_data[REG_MANUFACTURER_DATA].addr,
MANUFACTURER_ACCESS_SLEEP);
if (chip->is_present && ret < 0)
return ret;
return 0;
}
