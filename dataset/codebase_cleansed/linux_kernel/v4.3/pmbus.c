static void pmbus_find_sensor_groups(struct i2c_client *client,
struct pmbus_driver_info *info)
{
int page;
if (pmbus_check_word_register(client, 0, PMBUS_READ_VIN))
info->func[0] |= PMBUS_HAVE_VIN;
if (pmbus_check_word_register(client, 0, PMBUS_READ_VCAP))
info->func[0] |= PMBUS_HAVE_VCAP;
if (pmbus_check_word_register(client, 0, PMBUS_READ_IIN))
info->func[0] |= PMBUS_HAVE_IIN;
if (pmbus_check_word_register(client, 0, PMBUS_READ_PIN))
info->func[0] |= PMBUS_HAVE_PIN;
if (info->func[0]
&& pmbus_check_byte_register(client, 0, PMBUS_STATUS_INPUT))
info->func[0] |= PMBUS_HAVE_STATUS_INPUT;
if (pmbus_check_byte_register(client, 0, PMBUS_FAN_CONFIG_12) &&
pmbus_check_word_register(client, 0, PMBUS_READ_FAN_SPEED_1)) {
info->func[0] |= PMBUS_HAVE_FAN12;
if (pmbus_check_byte_register(client, 0, PMBUS_STATUS_FAN_12))
info->func[0] |= PMBUS_HAVE_STATUS_FAN12;
}
if (pmbus_check_byte_register(client, 0, PMBUS_FAN_CONFIG_34) &&
pmbus_check_word_register(client, 0, PMBUS_READ_FAN_SPEED_3)) {
info->func[0] |= PMBUS_HAVE_FAN34;
if (pmbus_check_byte_register(client, 0, PMBUS_STATUS_FAN_34))
info->func[0] |= PMBUS_HAVE_STATUS_FAN34;
}
if (pmbus_check_word_register(client, 0, PMBUS_READ_TEMPERATURE_1))
info->func[0] |= PMBUS_HAVE_TEMP;
if (pmbus_check_word_register(client, 0, PMBUS_READ_TEMPERATURE_2))
info->func[0] |= PMBUS_HAVE_TEMP2;
if (pmbus_check_word_register(client, 0, PMBUS_READ_TEMPERATURE_3))
info->func[0] |= PMBUS_HAVE_TEMP3;
if (info->func[0] & (PMBUS_HAVE_TEMP | PMBUS_HAVE_TEMP2
| PMBUS_HAVE_TEMP3)
&& pmbus_check_byte_register(client, 0,
PMBUS_STATUS_TEMPERATURE))
info->func[0] |= PMBUS_HAVE_STATUS_TEMP;
for (page = 0; page < info->pages; page++) {
if (pmbus_check_word_register(client, page, PMBUS_READ_VOUT)) {
info->func[page] |= PMBUS_HAVE_VOUT;
if (pmbus_check_byte_register(client, page,
PMBUS_STATUS_VOUT))
info->func[page] |= PMBUS_HAVE_STATUS_VOUT;
}
if (pmbus_check_word_register(client, page, PMBUS_READ_IOUT)) {
info->func[page] |= PMBUS_HAVE_IOUT;
if (pmbus_check_byte_register(client, 0,
PMBUS_STATUS_IOUT))
info->func[page] |= PMBUS_HAVE_STATUS_IOUT;
}
if (pmbus_check_word_register(client, page, PMBUS_READ_POUT))
info->func[page] |= PMBUS_HAVE_POUT;
}
}
static int pmbus_identify(struct i2c_client *client,
struct pmbus_driver_info *info)
{
int ret = 0;
if (!info->pages) {
if (pmbus_check_byte_register(client, 0, PMBUS_PAGE)) {
int page;
for (page = 1; page < PMBUS_PAGES; page++) {
if (pmbus_set_page(client, page) < 0)
break;
}
pmbus_set_page(client, 0);
info->pages = page;
} else {
info->pages = 1;
}
}
if (pmbus_check_byte_register(client, 0, PMBUS_VOUT_MODE)) {
int vout_mode;
vout_mode = pmbus_read_byte_data(client, 0, PMBUS_VOUT_MODE);
if (vout_mode >= 0 && vout_mode != 0xff) {
switch (vout_mode >> 5) {
case 0:
break;
case 1:
info->format[PSC_VOLTAGE_OUT] = vid;
info->vrm_version = vr11;
break;
case 2:
info->format[PSC_VOLTAGE_OUT] = direct;
break;
default:
ret = -ENODEV;
goto abort;
}
}
}
if (info->format[PSC_VOLTAGE_OUT] == direct) {
ret = -ENODEV;
goto abort;
}
pmbus_find_sensor_groups(client, info);
abort:
return ret;
}
static int pmbus_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct pmbus_driver_info *info;
info = devm_kzalloc(&client->dev, sizeof(struct pmbus_driver_info),
GFP_KERNEL);
if (!info)
return -ENOMEM;
info->pages = id->driver_data;
info->identify = pmbus_identify;
return pmbus_do_probe(client, id, info);
}
