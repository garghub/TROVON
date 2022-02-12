static inline int lin11_to_val(int data)
{
s16 e = ((s16)data) >> 11;
s32 m = (((s16)(data << 5)) >> 5);
e += 6;
return (e < 0 ? m >> -e : m << e);
}
static int ltc2978_read_word_data_common(struct i2c_client *client, int page,
int reg)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
struct ltc2978_data *data = to_ltc2978_data(info);
int ret;
switch (reg) {
case PMBUS_VIRT_READ_VIN_MAX:
ret = pmbus_read_word_data(client, page, LTC2978_MFR_VIN_PEAK);
if (ret >= 0) {
if (lin11_to_val(ret) > lin11_to_val(data->vin_max))
data->vin_max = ret;
ret = data->vin_max;
}
break;
case PMBUS_VIRT_READ_VOUT_MAX:
ret = pmbus_read_word_data(client, page, LTC2978_MFR_VOUT_PEAK);
if (ret >= 0) {
if (ret > data->vout_max[page])
data->vout_max[page] = ret;
ret = data->vout_max[page];
}
break;
case PMBUS_VIRT_READ_TEMP_MAX:
ret = pmbus_read_word_data(client, page,
LTC2978_MFR_TEMPERATURE_PEAK);
if (ret >= 0) {
if (lin11_to_val(ret) > lin11_to_val(data->temp_max))
data->temp_max = ret;
ret = data->temp_max;
}
break;
case PMBUS_VIRT_RESET_VOUT_HISTORY:
case PMBUS_VIRT_RESET_VIN_HISTORY:
case PMBUS_VIRT_RESET_TEMP_HISTORY:
ret = 0;
break;
default:
ret = -ENODATA;
break;
}
return ret;
}
static int ltc2978_read_word_data(struct i2c_client *client, int page, int reg)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
struct ltc2978_data *data = to_ltc2978_data(info);
int ret;
switch (reg) {
case PMBUS_VIRT_READ_VIN_MIN:
ret = pmbus_read_word_data(client, page, LTC2978_MFR_VIN_MIN);
if (ret >= 0) {
if (lin11_to_val(ret) < lin11_to_val(data->vin_min))
data->vin_min = ret;
ret = data->vin_min;
}
break;
case PMBUS_VIRT_READ_VOUT_MIN:
ret = pmbus_read_word_data(client, page, LTC2978_MFR_VOUT_MIN);
if (ret >= 0) {
if (data->vout_max[page] && ret > data->vout_max[page])
ret = data->vout_max[page];
if (ret < data->vout_min[page])
data->vout_min[page] = ret;
ret = data->vout_min[page];
}
break;
case PMBUS_VIRT_READ_TEMP_MIN:
ret = pmbus_read_word_data(client, page,
LTC2978_MFR_TEMPERATURE_MIN);
if (ret >= 0) {
if (lin11_to_val(ret)
< lin11_to_val(data->temp_min))
data->temp_min = ret;
ret = data->temp_min;
}
break;
case PMBUS_VIRT_READ_IOUT_MAX:
case PMBUS_VIRT_RESET_IOUT_HISTORY:
case PMBUS_VIRT_READ_TEMP2_MAX:
case PMBUS_VIRT_RESET_TEMP2_HISTORY:
ret = -ENXIO;
break;
default:
ret = ltc2978_read_word_data_common(client, page, reg);
break;
}
return ret;
}
static int ltc3880_read_word_data(struct i2c_client *client, int page, int reg)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
struct ltc2978_data *data = to_ltc2978_data(info);
int ret;
switch (reg) {
case PMBUS_VIRT_READ_IOUT_MAX:
ret = pmbus_read_word_data(client, page, LTC3880_MFR_IOUT_PEAK);
if (ret >= 0) {
if (lin11_to_val(ret)
> lin11_to_val(data->iout_max[page]))
data->iout_max[page] = ret;
ret = data->iout_max[page];
}
break;
case PMBUS_VIRT_READ_TEMP2_MAX:
ret = pmbus_read_word_data(client, page,
LTC3880_MFR_TEMPERATURE2_PEAK);
if (ret >= 0) {
if (lin11_to_val(ret)
> lin11_to_val(data->temp2_max[page]))
data->temp2_max[page] = ret;
ret = data->temp2_max[page];
}
break;
case PMBUS_VIRT_READ_VIN_MIN:
case PMBUS_VIRT_READ_VOUT_MIN:
case PMBUS_VIRT_READ_TEMP_MIN:
ret = -ENXIO;
break;
case PMBUS_VIRT_RESET_IOUT_HISTORY:
case PMBUS_VIRT_RESET_TEMP2_HISTORY:
ret = 0;
break;
default:
ret = ltc2978_read_word_data_common(client, page, reg);
break;
}
return ret;
}
static int ltc2978_clear_peaks(struct i2c_client *client, int page,
enum chips id)
{
int ret;
if (id == ltc2978)
ret = pmbus_write_byte(client, page, PMBUS_CLEAR_FAULTS);
else
ret = pmbus_write_byte(client, 0, LTC3880_MFR_CLEAR_PEAKS);
return ret;
}
static int ltc2978_write_word_data(struct i2c_client *client, int page,
int reg, u16 word)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
struct ltc2978_data *data = to_ltc2978_data(info);
int ret;
switch (reg) {
case PMBUS_VIRT_RESET_IOUT_HISTORY:
data->iout_max[page] = 0x7fff;
ret = ltc2978_clear_peaks(client, page, data->id);
break;
case PMBUS_VIRT_RESET_TEMP2_HISTORY:
data->temp2_max[page] = 0x7fff;
ret = ltc2978_clear_peaks(client, page, data->id);
break;
case PMBUS_VIRT_RESET_VOUT_HISTORY:
data->vout_min[page] = 0xffff;
data->vout_max[page] = 0;
ret = ltc2978_clear_peaks(client, page, data->id);
break;
case PMBUS_VIRT_RESET_VIN_HISTORY:
data->vin_min = 0x7bff;
data->vin_max = 0;
ret = ltc2978_clear_peaks(client, page, data->id);
break;
case PMBUS_VIRT_RESET_TEMP_HISTORY:
data->temp_min = 0x7bff;
data->temp_max = 0x7fff;
ret = ltc2978_clear_peaks(client, page, data->id);
break;
default:
ret = -ENODATA;
break;
}
return ret;
}
static int ltc2978_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int chip_id, i;
struct ltc2978_data *data;
struct pmbus_driver_info *info;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_WORD_DATA))
return -ENODEV;
data = devm_kzalloc(&client->dev, sizeof(struct ltc2978_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
chip_id = i2c_smbus_read_word_data(client, LTC2978_MFR_SPECIAL_ID);
if (chip_id < 0)
return chip_id;
if (chip_id == LTC2978_ID_REV1 || chip_id == LTC2978_ID_REV2) {
data->id = ltc2978;
} else if ((chip_id & LTC3880_ID_MASK) == LTC3880_ID) {
data->id = ltc3880;
} else {
dev_err(&client->dev, "Unsupported chip ID 0x%x\n", chip_id);
return -ENODEV;
}
if (data->id != id->driver_data)
dev_warn(&client->dev,
"Device mismatch: Configured %s, detected %s\n",
id->name,
ltc2978_id[data->id].name);
info = &data->info;
info->write_word_data = ltc2978_write_word_data;
data->vout_min[0] = 0xffff;
data->vin_min = 0x7bff;
data->temp_min = 0x7bff;
data->temp_max = 0x7fff;
switch (id->driver_data) {
case ltc2978:
info->read_word_data = ltc2978_read_word_data;
info->pages = 8;
info->func[0] = PMBUS_HAVE_VIN | PMBUS_HAVE_STATUS_INPUT
| PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT
| PMBUS_HAVE_TEMP | PMBUS_HAVE_STATUS_TEMP;
for (i = 1; i < 8; i++) {
info->func[i] = PMBUS_HAVE_VOUT
| PMBUS_HAVE_STATUS_VOUT;
data->vout_min[i] = 0xffff;
}
break;
case ltc3880:
info->read_word_data = ltc3880_read_word_data;
info->pages = 2;
info->func[0] = PMBUS_HAVE_VIN | PMBUS_HAVE_IIN
| PMBUS_HAVE_STATUS_INPUT
| PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT
| PMBUS_HAVE_IOUT | PMBUS_HAVE_STATUS_IOUT
| PMBUS_HAVE_POUT | PMBUS_HAVE_TEMP
| PMBUS_HAVE_TEMP2 | PMBUS_HAVE_STATUS_TEMP;
info->func[1] = PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT
| PMBUS_HAVE_IOUT | PMBUS_HAVE_STATUS_IOUT
| PMBUS_HAVE_POUT
| PMBUS_HAVE_TEMP | PMBUS_HAVE_STATUS_TEMP;
data->vout_min[1] = 0xffff;
break;
default:
return -ENODEV;
}
return pmbus_do_probe(client, id, info);
}
