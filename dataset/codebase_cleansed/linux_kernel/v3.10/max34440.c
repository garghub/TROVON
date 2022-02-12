static int max34440_read_word_data(struct i2c_client *client, int page, int reg)
{
int ret;
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
const struct max34440_data *data = to_max34440_data(info);
switch (reg) {
case PMBUS_VIRT_READ_VOUT_MIN:
ret = pmbus_read_word_data(client, page,
MAX34440_MFR_VOUT_MIN);
break;
case PMBUS_VIRT_READ_VOUT_MAX:
ret = pmbus_read_word_data(client, page,
MAX34440_MFR_VOUT_PEAK);
break;
case PMBUS_VIRT_READ_IOUT_AVG:
if (data->id != max34446)
return -ENXIO;
ret = pmbus_read_word_data(client, page,
MAX34446_MFR_IOUT_AVG);
break;
case PMBUS_VIRT_READ_IOUT_MAX:
ret = pmbus_read_word_data(client, page,
MAX34440_MFR_IOUT_PEAK);
break;
case PMBUS_VIRT_READ_POUT_AVG:
if (data->id != max34446)
return -ENXIO;
ret = pmbus_read_word_data(client, page,
MAX34446_MFR_POUT_AVG);
break;
case PMBUS_VIRT_READ_POUT_MAX:
if (data->id != max34446)
return -ENXIO;
ret = pmbus_read_word_data(client, page,
MAX34446_MFR_POUT_PEAK);
break;
case PMBUS_VIRT_READ_TEMP_AVG:
if (data->id != max34446 && data->id != max34460 &&
data->id != max34461)
return -ENXIO;
ret = pmbus_read_word_data(client, page,
MAX34446_MFR_TEMPERATURE_AVG);
break;
case PMBUS_VIRT_READ_TEMP_MAX:
ret = pmbus_read_word_data(client, page,
MAX34440_MFR_TEMPERATURE_PEAK);
break;
case PMBUS_VIRT_RESET_POUT_HISTORY:
if (data->id != max34446)
return -ENXIO;
ret = 0;
break;
case PMBUS_VIRT_RESET_VOUT_HISTORY:
case PMBUS_VIRT_RESET_IOUT_HISTORY:
case PMBUS_VIRT_RESET_TEMP_HISTORY:
ret = 0;
break;
default:
ret = -ENODATA;
break;
}
return ret;
}
static int max34440_write_word_data(struct i2c_client *client, int page,
int reg, u16 word)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
const struct max34440_data *data = to_max34440_data(info);
int ret;
switch (reg) {
case PMBUS_VIRT_RESET_POUT_HISTORY:
ret = pmbus_write_word_data(client, page,
MAX34446_MFR_POUT_PEAK, 0);
if (ret)
break;
ret = pmbus_write_word_data(client, page,
MAX34446_MFR_POUT_AVG, 0);
break;
case PMBUS_VIRT_RESET_VOUT_HISTORY:
ret = pmbus_write_word_data(client, page,
MAX34440_MFR_VOUT_MIN, 0x7fff);
if (ret)
break;
ret = pmbus_write_word_data(client, page,
MAX34440_MFR_VOUT_PEAK, 0);
break;
case PMBUS_VIRT_RESET_IOUT_HISTORY:
ret = pmbus_write_word_data(client, page,
MAX34440_MFR_IOUT_PEAK, 0);
if (!ret && data->id == max34446)
ret = pmbus_write_word_data(client, page,
MAX34446_MFR_IOUT_AVG, 0);
break;
case PMBUS_VIRT_RESET_TEMP_HISTORY:
ret = pmbus_write_word_data(client, page,
MAX34440_MFR_TEMPERATURE_PEAK,
0x8000);
if (!ret && data->id == max34446)
ret = pmbus_write_word_data(client, page,
MAX34446_MFR_TEMPERATURE_AVG, 0);
break;
default:
ret = -ENODATA;
break;
}
return ret;
}
static int max34440_read_byte_data(struct i2c_client *client, int page, int reg)
{
int ret = 0;
int mfg_status;
if (page >= 0) {
ret = pmbus_set_page(client, page);
if (ret < 0)
return ret;
}
switch (reg) {
case PMBUS_STATUS_IOUT:
mfg_status = pmbus_read_word_data(client, 0,
PMBUS_STATUS_MFR_SPECIFIC);
if (mfg_status < 0)
return mfg_status;
if (mfg_status & MAX34440_STATUS_OC_WARN)
ret |= PB_IOUT_OC_WARNING;
if (mfg_status & MAX34440_STATUS_OC_FAULT)
ret |= PB_IOUT_OC_FAULT;
break;
case PMBUS_STATUS_TEMPERATURE:
mfg_status = pmbus_read_word_data(client, 0,
PMBUS_STATUS_MFR_SPECIFIC);
if (mfg_status < 0)
return mfg_status;
if (mfg_status & MAX34440_STATUS_OT_WARN)
ret |= PB_TEMP_OT_WARNING;
if (mfg_status & MAX34440_STATUS_OT_FAULT)
ret |= PB_TEMP_OT_FAULT;
break;
default:
ret = -ENODATA;
break;
}
return ret;
}
static int max34440_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct max34440_data *data;
data = devm_kzalloc(&client->dev, sizeof(struct max34440_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
data->id = id->driver_data;
data->info = max34440_info[id->driver_data];
return pmbus_do_probe(client, id, &data->info);
}
