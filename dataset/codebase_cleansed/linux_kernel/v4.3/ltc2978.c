static int ltc_wait_ready(struct i2c_client *client)
{
unsigned long timeout = jiffies + msecs_to_jiffies(LTC_POLL_TIMEOUT);
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
struct ltc2978_data *data = to_ltc2978_data(info);
int status;
u8 mask;
if (!needs_polling(data))
return 0;
mask = LTC_NOT_BUSY;
if (data->id != ltc3883)
mask |= LTC_NOT_PENDING;
do {
status = pmbus_read_byte_data(client, 0, LTC2978_MFR_COMMON);
if (status == -EBADMSG || status == -ENXIO) {
usleep_range(50, 100);
continue;
}
if (status < 0)
return status;
if ((status & mask) == mask)
return 0;
usleep_range(50, 100);
} while (time_before(jiffies, timeout));
return -ETIMEDOUT;
}
static int ltc_read_word_data(struct i2c_client *client, int page, int reg)
{
int ret;
ret = ltc_wait_ready(client);
if (ret < 0)
return ret;
return pmbus_read_word_data(client, page, reg);
}
static int ltc_read_byte_data(struct i2c_client *client, int page, int reg)
{
int ret;
ret = ltc_wait_ready(client);
if (ret < 0)
return ret;
return pmbus_read_byte_data(client, page, reg);
}
static int ltc_write_byte(struct i2c_client *client, int page, u8 byte)
{
int ret;
ret = ltc_wait_ready(client);
if (ret < 0)
return ret;
return pmbus_write_byte(client, page, byte);
}
static inline int lin11_to_val(int data)
{
s16 e = ((s16)data) >> 11;
s32 m = (((s16)(data << 5)) >> 5);
e += 6;
return (e < 0 ? m >> -e : m << e);
}
static int ltc_get_max(struct ltc2978_data *data, struct i2c_client *client,
int page, int reg, u16 *pmax)
{
int ret;
ret = ltc_read_word_data(client, page, reg);
if (ret >= 0) {
if (lin11_to_val(ret) > lin11_to_val(*pmax))
*pmax = ret;
ret = *pmax;
}
return ret;
}
static int ltc_get_min(struct ltc2978_data *data, struct i2c_client *client,
int page, int reg, u16 *pmin)
{
int ret;
ret = ltc_read_word_data(client, page, reg);
if (ret >= 0) {
if (lin11_to_val(ret) < lin11_to_val(*pmin))
*pmin = ret;
ret = *pmin;
}
return ret;
}
static int ltc2978_read_word_data_common(struct i2c_client *client, int page,
int reg)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
struct ltc2978_data *data = to_ltc2978_data(info);
int ret;
switch (reg) {
case PMBUS_VIRT_READ_VIN_MAX:
ret = ltc_get_max(data, client, page, LTC2978_MFR_VIN_PEAK,
&data->vin_max);
break;
case PMBUS_VIRT_READ_VOUT_MAX:
ret = ltc_read_word_data(client, page, LTC2978_MFR_VOUT_PEAK);
if (ret >= 0) {
if (ret > data->vout_max[page])
data->vout_max[page] = ret;
ret = data->vout_max[page];
}
break;
case PMBUS_VIRT_READ_TEMP_MAX:
ret = ltc_get_max(data, client, page,
LTC2978_MFR_TEMPERATURE_PEAK,
&data->temp_max[page]);
break;
case PMBUS_VIRT_RESET_VOUT_HISTORY:
case PMBUS_VIRT_RESET_VIN_HISTORY:
case PMBUS_VIRT_RESET_TEMP_HISTORY:
ret = 0;
break;
default:
ret = ltc_wait_ready(client);
if (ret < 0)
return ret;
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
ret = ltc_get_min(data, client, page, LTC2978_MFR_VIN_MIN,
&data->vin_min);
break;
case PMBUS_VIRT_READ_VOUT_MIN:
ret = ltc_read_word_data(client, page, LTC2978_MFR_VOUT_MIN);
if (ret >= 0) {
if (data->vout_max[page] && ret > data->vout_max[page])
ret = data->vout_max[page];
if (ret < data->vout_min[page])
data->vout_min[page] = ret;
ret = data->vout_min[page];
}
break;
case PMBUS_VIRT_READ_TEMP_MIN:
ret = ltc_get_min(data, client, page,
LTC2978_MFR_TEMPERATURE_MIN,
&data->temp_min[page]);
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
ret = ltc_get_max(data, client, page, LTC2974_MFR_IOUT_PEAK,
&data->iout_max[page]);
break;
case PMBUS_VIRT_READ_IOUT_MIN:
ret = ltc_get_min(data, client, page, LTC2974_MFR_IOUT_MIN,
&data->iout_min[page]);
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
static int ltc2975_read_word_data(struct i2c_client *client, int page, int reg)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
struct ltc2978_data *data = to_ltc2978_data(info);
int ret;
switch (reg) {
case PMBUS_VIRT_READ_IIN_MAX:
ret = ltc_get_max(data, client, page, LTC2975_MFR_IIN_PEAK,
&data->iin_max);
break;
case PMBUS_VIRT_READ_IIN_MIN:
ret = ltc_get_min(data, client, page, LTC2975_MFR_IIN_MIN,
&data->iin_min);
break;
case PMBUS_VIRT_READ_PIN_MAX:
ret = ltc_get_max(data, client, page, LTC2975_MFR_PIN_PEAK,
&data->pin_max);
break;
case PMBUS_VIRT_READ_PIN_MIN:
ret = ltc_get_min(data, client, page, LTC2975_MFR_PIN_MIN,
&data->pin_min);
break;
case PMBUS_VIRT_RESET_IIN_HISTORY:
case PMBUS_VIRT_RESET_PIN_HISTORY:
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
ret = ltc_get_max(data, client, page, LTC3880_MFR_IOUT_PEAK,
&data->iout_max[page]);
break;
case PMBUS_VIRT_READ_TEMP2_MAX:
ret = ltc_get_max(data, client, page,
LTC3880_MFR_TEMPERATURE2_PEAK,
&data->temp2_max);
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
ret = ltc_get_max(data, client, page, LTC3883_MFR_IIN_PEAK,
&data->iin_max);
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
static int ltc2978_clear_peaks(struct ltc2978_data *data,
struct i2c_client *client, int page)
{
int ret;
if (has_clear_peaks(data))
ret = ltc_write_byte(client, 0, LTC3880_MFR_CLEAR_PEAKS);
else
ret = ltc_write_byte(client, page, PMBUS_CLEAR_FAULTS);
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
data->iin_min = 0x7bff;
ret = ltc2978_clear_peaks(data, client, 0);
break;
case PMBUS_VIRT_RESET_PIN_HISTORY:
data->pin_max = 0x7c00;
data->pin_min = 0x7bff;
ret = ltc2978_clear_peaks(data, client, 0);
break;
case PMBUS_VIRT_RESET_IOUT_HISTORY:
data->iout_max[page] = 0x7c00;
data->iout_min[page] = 0xfbff;
ret = ltc2978_clear_peaks(data, client, page);
break;
case PMBUS_VIRT_RESET_TEMP2_HISTORY:
data->temp2_max = 0x7c00;
ret = ltc2978_clear_peaks(data, client, page);
break;
case PMBUS_VIRT_RESET_VOUT_HISTORY:
data->vout_min[page] = 0xffff;
data->vout_max[page] = 0;
ret = ltc2978_clear_peaks(data, client, page);
break;
case PMBUS_VIRT_RESET_VIN_HISTORY:
data->vin_min = 0x7bff;
data->vin_max = 0x7c00;
ret = ltc2978_clear_peaks(data, client, page);
break;
case PMBUS_VIRT_RESET_TEMP_HISTORY:
data->temp_min[page] = 0x7bff;
data->temp_max[page] = 0x7c00;
ret = ltc2978_clear_peaks(data, client, page);
break;
default:
ret = ltc_wait_ready(client);
if (ret < 0)
return ret;
ret = -ENODATA;
break;
}
return ret;
}
static int ltc2978_get_id(struct i2c_client *client)
{
int chip_id;
chip_id = i2c_smbus_read_word_data(client, LTC2978_MFR_SPECIAL_ID);
if (chip_id < 0) {
const struct i2c_device_id *id;
u8 buf[I2C_SMBUS_BLOCK_MAX];
int ret;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_BLOCK_DATA))
return -ENODEV;
ret = i2c_smbus_read_block_data(client, PMBUS_MFR_ID, buf);
if (ret < 0)
return ret;
if (ret < 3 || strncmp(buf, "LTC", 3))
return -ENODEV;
ret = i2c_smbus_read_block_data(client, PMBUS_MFR_MODEL, buf);
if (ret < 0)
return ret;
for (id = &ltc2978_id[0]; strlen(id->name); id++) {
if (!strncasecmp(id->name, buf, strlen(id->name)))
return (int)id->driver_data;
}
return -ENODEV;
}
chip_id &= LTC2978_ID_MASK;
if (chip_id == LTC2974_ID)
return ltc2974;
else if (chip_id == LTC2975_ID)
return ltc2975;
else if (chip_id == LTC2977_ID)
return ltc2977;
else if (chip_id == LTC2978_ID_REV1 || chip_id == LTC2978_ID_REV2)
return ltc2978;
else if (chip_id == LTC2980_ID_A || chip_id == LTC2980_ID_B)
return ltc2980;
else if (chip_id == LTC3880_ID)
return ltc3880;
else if (chip_id == LTC3882_ID || chip_id == LTC3882_ID_D1)
return ltc3882;
else if (chip_id == LTC3883_ID)
return ltc3883;
else if (chip_id == LTC3886_ID)
return ltc3886;
else if (chip_id == LTC3887_ID)
return ltc3887;
else if (chip_id == LTM2987_ID_A || chip_id == LTM2987_ID_B)
return ltm2987;
else if (chip_id == LTM4675_ID)
return ltm4675;
else if (chip_id == LTM4676_ID_REV1 || chip_id == LTM4676_ID_REV2 ||
chip_id == LTM4676A_ID)
return ltm4676;
dev_err(&client->dev, "Unsupported chip ID 0x%x\n", chip_id);
return -ENODEV;
}
static int ltc2978_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int i, chip_id;
struct ltc2978_data *data;
struct pmbus_driver_info *info;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_WORD_DATA))
return -ENODEV;
data = devm_kzalloc(&client->dev, sizeof(struct ltc2978_data),
GFP_KERNEL);
if (!data)
return -ENOMEM;
chip_id = ltc2978_get_id(client);
if (chip_id < 0)
return chip_id;
data->id = chip_id;
if (data->id != id->driver_data)
dev_warn(&client->dev,
"Device mismatch: Configured %s, detected %s\n",
id->name,
ltc2978_id[data->id].name);
info = &data->info;
info->write_word_data = ltc2978_write_word_data;
info->write_byte = ltc_write_byte;
info->read_word_data = ltc_read_word_data;
info->read_byte_data = ltc_read_byte_data;
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
case ltc2975:
info->read_word_data = ltc2975_read_word_data;
info->pages = LTC2974_NUM_PAGES;
info->func[0] = PMBUS_HAVE_IIN | PMBUS_HAVE_PIN
| PMBUS_HAVE_VIN | PMBUS_HAVE_STATUS_INPUT
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
case ltc2980:
case ltm2987:
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
case ltc3887:
case ltm4675:
case ltm4676:
data->features |= FEAT_CLEAR_PEAKS | FEAT_NEEDS_POLLING;
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
case ltc3882:
data->features |= FEAT_CLEAR_PEAKS | FEAT_NEEDS_POLLING;
info->read_word_data = ltc3880_read_word_data;
info->pages = LTC3880_NUM_PAGES;
info->func[0] = PMBUS_HAVE_VIN
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
data->features |= FEAT_CLEAR_PEAKS | FEAT_NEEDS_POLLING;
info->read_word_data = ltc3883_read_word_data;
info->pages = LTC3883_NUM_PAGES;
info->func[0] = PMBUS_HAVE_VIN | PMBUS_HAVE_IIN
| PMBUS_HAVE_STATUS_INPUT
| PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT
| PMBUS_HAVE_IOUT | PMBUS_HAVE_STATUS_IOUT
| PMBUS_HAVE_PIN | PMBUS_HAVE_POUT | PMBUS_HAVE_TEMP
| PMBUS_HAVE_TEMP2 | PMBUS_HAVE_STATUS_TEMP;
break;
case ltc3886:
data->features |= FEAT_CLEAR_PEAKS | FEAT_NEEDS_POLLING;
info->read_word_data = ltc3883_read_word_data;
info->pages = LTC3880_NUM_PAGES;
info->func[0] = PMBUS_HAVE_VIN | PMBUS_HAVE_IIN
| PMBUS_HAVE_STATUS_INPUT
| PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT
| PMBUS_HAVE_IOUT | PMBUS_HAVE_STATUS_IOUT
| PMBUS_HAVE_PIN | PMBUS_HAVE_POUT | PMBUS_HAVE_TEMP
| PMBUS_HAVE_TEMP2 | PMBUS_HAVE_STATUS_TEMP;
info->func[1] = PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT
| PMBUS_HAVE_IOUT | PMBUS_HAVE_STATUS_IOUT
| PMBUS_HAVE_POUT
| PMBUS_HAVE_TEMP | PMBUS_HAVE_STATUS_TEMP;
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
