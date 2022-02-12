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
if (lin11_to_val(ret)
> lin11_to_val(data->temp_max[page]))
data->temp_max[page] = ret;
ret = data->temp_max[page];
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
< lin11_to_val(data->temp_min[page]))
data->temp_min[page] = ret;
ret = data->temp_min[page];
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
static int ltc2974_read_word_data(struct i2c_client *client, int page, int reg)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
struct ltc2978_data *data = to_ltc2978_data(info);
int ret;
switch (reg) {
case PMBUS_VIRT_READ_IOUT_MAX:
ret = pmbus_read_word_data(client, page, LTC2974_MFR_IOUT_PEAK);
if (ret >= 0) {
if (lin11_to_val(ret)
> lin11_to_val(data->iout_max[page]))
data->iout_max[page] = ret;
ret = data->iout_max[page];
}
break;
case PMBUS_VIRT_READ_IOUT_MIN:
ret = pmbus_read_word_data(client, page, LTC2974_MFR_IOUT_MIN);
if (ret >= 0) {
if (lin11_to_val(ret)
< lin11_to_val(data->iout_min[page]))
data->iout_min[page] = ret;
ret = data->iout_min[page];
}
break;
case PMBUS_VIRT_RESET_IOUT_HISTORY:
ret = 0;
break;
default:
ret = ltc2978_read_word_data(client, page, reg);
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
if (lin11_to_val(ret) > lin11_to_val(data->temp2_max))
data->temp2_max = ret;
ret = data->temp2_max;
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
static int ltc3883_read_word_data(struct i2c_client *client, int page, int reg)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
struct ltc2978_data *data = to_ltc2978_data(info);
int ret;
switch (reg) {
case PMBUS_VIRT_READ_IIN_MAX:
ret = pmbus_read_word_data(client, page, LTC3883_MFR_IIN_PEAK);
if (ret >= 0) {
if (lin11_to_val(ret)
> lin11_to_val(data->iin_max))
data->iin_max = ret;
ret = data->iin_max;
}
break;
case PMBUS_VIRT_RESET_IIN_HISTORY:
ret = 0;
break;
default:
ret = ltc3880_read_word_data(client, page, reg);
break;
}
return ret;
}
static int ltc2978_clear_peaks(struct i2c_client *client, int page,
enum chips id)
{
int ret;
if (id == ltc3880 || id == ltc3883)
ret = pmbus_write_byte(client, 0, LTC3880_MFR_CLEAR_PEAKS);
else
ret = pmbus_write_byte(client, page, PMBUS_CLEAR_FAULTS);
return ret;
}
static int ltc2978_write_word_data(struct i2c_client *client, int page,
int reg, u16 word)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
struct ltc2978_data *data = to_ltc2978_data(info);
int ret;
switch (reg) {
case PMBUS_VIRT_RESET_IIN_HISTORY:
data->iin_max = 0x7c00;
ret = ltc2978_clear_peaks(client, page, data->id);
break;
case PMBUS_VIRT_RESET_IOUT_HISTORY:
data->iout_max[page] = 0x7c00;
data->iout_min[page] = 0xfbff;
ret = ltc2978_clear_peaks(client, page, data->id);
break;
case PMBUS_VIRT_RESET_TEMP2_HISTORY:
data->temp2_max = 0x7c00;
ret = ltc2978_clear_peaks(client, page, data->id);
break;
case PMBUS_VIRT_RESET_VOUT_HISTORY:
data->vout_min[page] = 0xffff;
data->vout_max[page] = 0;
ret = ltc2978_clear_peaks(client, page, data->id);
break;
case PMBUS_VIRT_RESET_VIN_HISTORY:
data->vin_min = 0x7bff;
data->vin_max = 0x7c00;
ret = ltc2978_clear_peaks(client, page, data->id);
break;
case PMBUS_VIRT_RESET_TEMP_HISTORY:
data->temp_min[page] = 0x7bff;
data->temp_max[page] = 0x7c00;
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
if (chip_id == LTC2974_ID_REV1 || chip_id == LTC2974_ID_REV2) {
data->id = ltc2974;
} else if (chip_id == LTC2977_ID) {
data->id = ltc2977;
} else if (chip_id == LTC2978_ID_REV1 || chip_id == LTC2978_ID_REV2 ||
chip_id == LTC2978A_ID) {
data->id = ltc2978;
} else if ((chip_id & LTC3880_ID_MASK) == LTC3880_ID) {
data->id = ltc3880;
} else if ((chip_id & LTC3883_ID_MASK) == LTC3883_ID) {
data->id = ltc3883;
} else if ((chip_id & LTM4676_ID_MASK) == LTM4676_ID) {
data->id = ltm4676;
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
data->vin_min = 0x7bff;
data->vin_max = 0x7c00;
for (i = 0; i < ARRAY_SIZE(data->vout_min); i++)
data->vout_min[i] = 0xffff;
for (i = 0; i < ARRAY_SIZE(data->iout_min); i++)
data->iout_min[i] = 0xfbff;
for (i = 0; i < ARRAY_SIZE(data->iout_max); i++)
data->iout_max[i] = 0x7c00;
for (i = 0; i < ARRAY_SIZE(data->temp_min); i++)
data->temp_min[i] = 0x7bff;
for (i = 0; i < ARRAY_SIZE(data->temp_max); i++)
data->temp_max[i] = 0x7c00;
data->temp2_max = 0x7c00;
switch (data->id) {
case ltc2974:
info->read_word_data = ltc2974_read_word_data;
info->pages = LTC2974_NUM_PAGES;
info->func[0] = PMBUS_HAVE_VIN | PMBUS_HAVE_STATUS_INPUT
| PMBUS_HAVE_TEMP2;
for (i = 0; i < info->pages; i++) {
info->func[i] |= PMBUS_HAVE_VOUT
| PMBUS_HAVE_STATUS_VOUT | PMBUS_HAVE_POUT
| PMBUS_HAVE_TEMP | PMBUS_HAVE_STATUS_TEMP
| PMBUS_HAVE_IOUT | PMBUS_HAVE_STATUS_IOUT;
}
break;
case ltc2977:
case ltc2978:
info->read_word_data = ltc2978_read_word_data;
info->pages = LTC2978_NUM_PAGES;
info->func[0] = PMBUS_HAVE_VIN | PMBUS_HAVE_STATUS_INPUT
| PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT
| PMBUS_HAVE_TEMP | PMBUS_HAVE_STATUS_TEMP;
for (i = 1; i < LTC2978_NUM_PAGES; i++) {
info->func[i] = PMBUS_HAVE_VOUT
| PMBUS_HAVE_STATUS_VOUT;
}
break;
case ltc3880:
case ltm4676:
info->read_word_data = ltc3880_read_word_data;
info->pages = LTC3880_NUM_PAGES;
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
break;
case ltc3883:
info->read_word_data = ltc3883_read_word_data;
info->pages = LTC3883_NUM_PAGES;
info->func[0] = PMBUS_HAVE_VIN | PMBUS_HAVE_IIN
| PMBUS_HAVE_STATUS_INPUT
| PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT
| PMBUS_HAVE_IOUT | PMBUS_HAVE_STATUS_IOUT
| PMBUS_HAVE_PIN | PMBUS_HAVE_POUT | PMBUS_HAVE_TEMP
| PMBUS_HAVE_TEMP2 | PMBUS_HAVE_STATUS_TEMP;
break;
default:
return -ENODEV;
}
#if IS_ENABLED(CONFIG_SENSORS_LTC2978_REGULATOR)
info->num_regulators = info->pages;
info->reg_desc = ltc2978_reg_desc;
if (info->num_regulators > ARRAY_SIZE(ltc2978_reg_desc)) {
dev_err(&client->dev, "num_regulators too large!");
info->num_regulators = ARRAY_SIZE(ltc2978_reg_desc);
}
#endif
return pmbus_do_probe(client, id, info);
}
