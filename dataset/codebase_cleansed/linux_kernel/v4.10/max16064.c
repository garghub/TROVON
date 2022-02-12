static int max16064_read_word_data(struct i2c_client *client, int page, int reg)
{
int ret;
switch (reg) {
case PMBUS_VIRT_READ_VOUT_MAX:
ret = pmbus_read_word_data(client, page,
MAX16064_MFR_VOUT_PEAK);
break;
case PMBUS_VIRT_READ_TEMP_MAX:
ret = pmbus_read_word_data(client, page,
MAX16064_MFR_TEMPERATURE_PEAK);
break;
case PMBUS_VIRT_RESET_VOUT_HISTORY:
case PMBUS_VIRT_RESET_TEMP_HISTORY:
ret = 0;
break;
default:
ret = -ENODATA;
break;
}
return ret;
}
static int max16064_write_word_data(struct i2c_client *client, int page,
int reg, u16 word)
{
int ret;
switch (reg) {
case PMBUS_VIRT_RESET_VOUT_HISTORY:
ret = pmbus_write_word_data(client, page,
MAX16064_MFR_VOUT_PEAK, 0);
break;
case PMBUS_VIRT_RESET_TEMP_HISTORY:
ret = pmbus_write_word_data(client, page,
MAX16064_MFR_TEMPERATURE_PEAK,
0xffff);
break;
default:
ret = -ENODATA;
break;
}
return ret;
}
static int max16064_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
return pmbus_do_probe(client, id, &max16064_info);
}
