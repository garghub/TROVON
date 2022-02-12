static inline int ds278x_read_reg(struct ds278x_info *info, int reg, u8 *val)
{
int ret;
ret = i2c_smbus_read_byte_data(info->client, reg);
if (ret < 0) {
dev_err(&info->client->dev, "register read failed\n");
return ret;
}
*val = ret;
return 0;
}
static inline int ds278x_read_reg16(struct ds278x_info *info, int reg_msb,
s16 *val)
{
int ret;
ret = swab16(i2c_smbus_read_word_data(info->client, reg_msb));
if (ret < 0) {
dev_err(&info->client->dev, "register read failed\n");
return ret;
}
*val = ret;
return 0;
}
static int ds278x_get_temp(struct ds278x_info *info, int *temp)
{
s16 raw;
int err;
err = ds278x_read_reg16(info, DS278x_REG_TEMP_MSB, &raw);
if (err)
return err;
*temp = ((raw / 32) * 125) / 100;
return 0;
}
static int ds2782_get_current(struct ds278x_info *info, int *current_uA)
{
int sense_res;
int err;
u8 sense_res_raw;
s16 raw;
err = ds278x_read_reg(info, DS2782_REG_RSNSP, &sense_res_raw);
if (err)
return err;
if (sense_res_raw == 0) {
dev_err(&info->client->dev, "sense resistor value is 0\n");
return -ENXIO;
}
sense_res = 1000 / sense_res_raw;
dev_dbg(&info->client->dev, "sense resistor = %d milli-ohms\n",
sense_res);
err = ds278x_read_reg16(info, DS278x_REG_CURRENT_MSB, &raw);
if (err)
return err;
*current_uA = raw * (DS2782_CURRENT_UNITS / sense_res);
return 0;
}
static int ds2782_get_voltage(struct ds278x_info *info, int *voltage_uV)
{
s16 raw;
int err;
err = ds278x_read_reg16(info, DS278x_REG_VOLT_MSB, &raw);
if (err)
return err;
*voltage_uV = (raw / 32) * 4800;
return 0;
}
static int ds2782_get_capacity(struct ds278x_info *info, int *capacity)
{
int err;
u8 raw;
err = ds278x_read_reg(info, DS2782_REG_RARC, &raw);
if (err)
return err;
*capacity = raw;
return 0;
}
static int ds2786_get_current(struct ds278x_info *info, int *current_uA)
{
int err;
s16 raw;
err = ds278x_read_reg16(info, DS278x_REG_CURRENT_MSB, &raw);
if (err)
return err;
*current_uA = (raw / 16) * (DS2786_CURRENT_UNITS / info->rsns);
return 0;
}
static int ds2786_get_voltage(struct ds278x_info *info, int *voltage_uV)
{
s16 raw;
int err;
err = ds278x_read_reg16(info, DS278x_REG_VOLT_MSB, &raw);
if (err)
return err;
*voltage_uV = (raw / 8) * 1220;
return 0;
}
static int ds2786_get_capacity(struct ds278x_info *info, int *capacity)
{
int err;
u8 raw;
err = ds278x_read_reg(info, DS2786_REG_RARC, &raw);
if (err)
return err;
*capacity = raw/2 ;
return 0;
}
static int ds278x_get_status(struct ds278x_info *info, int *status)
{
int err;
int current_uA;
int capacity;
err = info->ops->get_battery_current(info, &current_uA);
if (err)
return err;
err = info->ops->get_battery_capacity(info, &capacity);
if (err)
return err;
if (capacity == 100)
*status = POWER_SUPPLY_STATUS_FULL;
else if (current_uA == 0)
*status = POWER_SUPPLY_STATUS_NOT_CHARGING;
else if (current_uA < 0)
*status = POWER_SUPPLY_STATUS_DISCHARGING;
else
*status = POWER_SUPPLY_STATUS_CHARGING;
return 0;
}
static int ds278x_battery_get_property(struct power_supply *psy,
enum power_supply_property prop,
union power_supply_propval *val)
{
struct ds278x_info *info = to_ds278x_info(psy);
int ret;
switch (prop) {
case POWER_SUPPLY_PROP_STATUS:
ret = ds278x_get_status(info, &val->intval);
break;
case POWER_SUPPLY_PROP_CAPACITY:
ret = info->ops->get_battery_capacity(info, &val->intval);
break;
case POWER_SUPPLY_PROP_VOLTAGE_NOW:
ret = info->ops->get_battery_voltage(info, &val->intval);
break;
case POWER_SUPPLY_PROP_CURRENT_NOW:
ret = info->ops->get_battery_current(info, &val->intval);
break;
case POWER_SUPPLY_PROP_TEMP:
ret = ds278x_get_temp(info, &val->intval);
break;
default:
ret = -EINVAL;
}
return ret;
}
static void ds278x_power_supply_init(struct power_supply *battery)
{
battery->type = POWER_SUPPLY_TYPE_BATTERY;
battery->properties = ds278x_battery_props;
battery->num_properties = ARRAY_SIZE(ds278x_battery_props);
battery->get_property = ds278x_battery_get_property;
battery->external_power_changed = NULL;
}
static int ds278x_battery_remove(struct i2c_client *client)
{
struct ds278x_info *info = i2c_get_clientdata(client);
power_supply_unregister(&info->battery);
kfree(info->battery.name);
mutex_lock(&battery_lock);
idr_remove(&battery_id, info->id);
mutex_unlock(&battery_lock);
kfree(info);
return 0;
}
static int ds278x_battery_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ds278x_platform_data *pdata = client->dev.platform_data;
struct ds278x_info *info;
int ret;
int num;
if (id->driver_data == DS2786 && !pdata) {
dev_err(&client->dev, "missing platform data for ds2786\n");
return -EINVAL;
}
ret = idr_pre_get(&battery_id, GFP_KERNEL);
if (ret == 0) {
ret = -ENOMEM;
goto fail_id;
}
mutex_lock(&battery_lock);
ret = idr_get_new(&battery_id, client, &num);
mutex_unlock(&battery_lock);
if (ret < 0)
goto fail_id;
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info) {
ret = -ENOMEM;
goto fail_info;
}
info->battery.name = kasprintf(GFP_KERNEL, "%s-%d", client->name, num);
if (!info->battery.name) {
ret = -ENOMEM;
goto fail_name;
}
if (id->driver_data == DS2786)
info->rsns = pdata->rsns;
i2c_set_clientdata(client, info);
info->client = client;
info->id = num;
info->ops = &ds278x_ops[id->driver_data];
ds278x_power_supply_init(&info->battery);
ret = power_supply_register(&client->dev, &info->battery);
if (ret) {
dev_err(&client->dev, "failed to register battery\n");
goto fail_register;
}
return 0;
fail_register:
kfree(info->battery.name);
fail_name:
kfree(info);
fail_info:
mutex_lock(&battery_lock);
idr_remove(&battery_id, num);
mutex_unlock(&battery_lock);
fail_id:
return ret;
}
