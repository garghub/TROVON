static int lm25066_read_word_data(struct i2c_client *client, int page, int reg)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
const struct lm25066_data *data = to_lm25066_data(info);
int ret;
if (page > 1)
return -ENXIO;
if (page == 1) {
switch (reg) {
case PMBUS_READ_VOUT:
ret = pmbus_read_word_data(client, 0,
LM25066_READ_VAUX);
if (ret < 0)
break;
switch (data->id) {
case lm25066:
ret = DIV_ROUND_CLOSEST(ret * 2832, 45400);
break;
case lm5064:
ret = DIV_ROUND_CLOSEST(ret * 70, 453);
break;
case lm5066:
ret = DIV_ROUND_CLOSEST(ret * 725, 2180);
break;
}
break;
default:
ret = -ENXIO;
break;
}
goto done;
}
switch (reg) {
case PMBUS_READ_IIN:
ret = pmbus_read_word_data(client, 0, LM25066_MFR_READ_IIN);
break;
case PMBUS_READ_PIN:
ret = pmbus_read_word_data(client, 0, LM25066_MFR_READ_PIN);
break;
case PMBUS_IIN_OC_WARN_LIMIT:
ret = pmbus_read_word_data(client, 0,
LM25066_MFR_IIN_OC_WARN_LIMIT);
break;
case PMBUS_PIN_OP_WARN_LIMIT:
ret = pmbus_read_word_data(client, 0,
LM25066_MFR_PIN_OP_WARN_LIMIT);
break;
case PMBUS_VIRT_READ_VIN_AVG:
ret = pmbus_read_word_data(client, 0, LM25066_READ_AVG_VIN);
break;
case PMBUS_VIRT_READ_VOUT_AVG:
ret = pmbus_read_word_data(client, 0, LM25066_READ_AVG_VOUT);
break;
case PMBUS_VIRT_READ_IIN_AVG:
ret = pmbus_read_word_data(client, 0, LM25066_READ_AVG_IIN);
break;
case PMBUS_VIRT_READ_PIN_AVG:
ret = pmbus_read_word_data(client, 0, LM25066_READ_AVG_PIN);
break;
case PMBUS_VIRT_READ_PIN_MAX:
ret = pmbus_read_word_data(client, 0, LM25066_READ_PIN_PEAK);
break;
case PMBUS_VIRT_RESET_PIN_HISTORY:
ret = 0;
break;
default:
ret = -ENODATA;
break;
}
done:
return ret;
}
static int lm25066_write_word_data(struct i2c_client *client, int page, int reg,
u16 word)
{
int ret;
if (page > 1)
return -ENXIO;
switch (reg) {
case PMBUS_IIN_OC_WARN_LIMIT:
ret = pmbus_write_word_data(client, 0,
LM25066_MFR_IIN_OC_WARN_LIMIT,
word);
break;
case PMBUS_PIN_OP_WARN_LIMIT:
ret = pmbus_write_word_data(client, 0,
LM25066_MFR_PIN_OP_WARN_LIMIT,
word);
break;
case PMBUS_VIRT_RESET_PIN_HISTORY:
ret = pmbus_write_byte(client, 0, LM25066_CLEAR_PIN_PEAK);
break;
default:
ret = -ENODATA;
break;
}
return ret;
}
static int lm25066_write_byte(struct i2c_client *client, int page, u8 value)
{
if (page > 1)
return -ENXIO;
if (page <= 0)
return pmbus_write_byte(client, page, value);
return 0;
}
static int lm25066_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int config;
int ret;
struct lm25066_data *data;
struct pmbus_driver_info *info;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_BYTE_DATA))
return -ENODEV;
data = kzalloc(sizeof(struct lm25066_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
config = i2c_smbus_read_byte_data(client, LM25066_DEVICE_SETUP);
if (config < 0) {
ret = config;
goto err_mem;
}
data->id = id->driver_data;
info = &data->info;
info->pages = 2;
info->format[PSC_VOLTAGE_IN] = direct;
info->format[PSC_VOLTAGE_OUT] = direct;
info->format[PSC_CURRENT_IN] = direct;
info->format[PSC_TEMPERATURE] = direct;
info->format[PSC_POWER] = direct;
info->m[PSC_TEMPERATURE] = 16;
info->b[PSC_TEMPERATURE] = 0;
info->R[PSC_TEMPERATURE] = 0;
info->func[0] = PMBUS_HAVE_VIN | PMBUS_HAVE_VOUT
| PMBUS_HAVE_STATUS_VOUT | PMBUS_HAVE_PIN | PMBUS_HAVE_IIN
| PMBUS_HAVE_STATUS_INPUT | PMBUS_HAVE_TEMP | PMBUS_HAVE_STATUS_TEMP;
info->func[1] = PMBUS_HAVE_VOUT;
info->read_word_data = lm25066_read_word_data;
info->write_word_data = lm25066_write_word_data;
info->write_byte = lm25066_write_byte;
switch (id->driver_data) {
case lm25066:
info->m[PSC_VOLTAGE_IN] = 22070;
info->b[PSC_VOLTAGE_IN] = 0;
info->R[PSC_VOLTAGE_IN] = -2;
info->m[PSC_VOLTAGE_OUT] = 22070;
info->b[PSC_VOLTAGE_OUT] = 0;
info->R[PSC_VOLTAGE_OUT] = -2;
if (config & LM25066_DEV_SETUP_CL) {
info->m[PSC_CURRENT_IN] = 6852;
info->b[PSC_CURRENT_IN] = 0;
info->R[PSC_CURRENT_IN] = -2;
info->m[PSC_POWER] = 369;
info->b[PSC_POWER] = 0;
info->R[PSC_POWER] = -2;
} else {
info->m[PSC_CURRENT_IN] = 13661;
info->b[PSC_CURRENT_IN] = 0;
info->R[PSC_CURRENT_IN] = -2;
info->m[PSC_POWER] = 736;
info->b[PSC_POWER] = 0;
info->R[PSC_POWER] = -2;
}
break;
case lm5064:
info->m[PSC_VOLTAGE_IN] = 22075;
info->b[PSC_VOLTAGE_IN] = 0;
info->R[PSC_VOLTAGE_IN] = -2;
info->m[PSC_VOLTAGE_OUT] = 22075;
info->b[PSC_VOLTAGE_OUT] = 0;
info->R[PSC_VOLTAGE_OUT] = -2;
if (config & LM25066_DEV_SETUP_CL) {
info->m[PSC_CURRENT_IN] = 6713;
info->b[PSC_CURRENT_IN] = 0;
info->R[PSC_CURRENT_IN] = -2;
info->m[PSC_POWER] = 3619;
info->b[PSC_POWER] = 0;
info->R[PSC_POWER] = -3;
} else {
info->m[PSC_CURRENT_IN] = 13426;
info->b[PSC_CURRENT_IN] = 0;
info->R[PSC_CURRENT_IN] = -2;
info->m[PSC_POWER] = 7238;
info->b[PSC_POWER] = 0;
info->R[PSC_POWER] = -3;
}
break;
case lm5066:
info->m[PSC_VOLTAGE_IN] = 4587;
info->b[PSC_VOLTAGE_IN] = 0;
info->R[PSC_VOLTAGE_IN] = -2;
info->m[PSC_VOLTAGE_OUT] = 4587;
info->b[PSC_VOLTAGE_OUT] = 0;
info->R[PSC_VOLTAGE_OUT] = -2;
if (config & LM25066_DEV_SETUP_CL) {
info->m[PSC_CURRENT_IN] = 10753;
info->b[PSC_CURRENT_IN] = 0;
info->R[PSC_CURRENT_IN] = -2;
info->m[PSC_POWER] = 1204;
info->b[PSC_POWER] = 0;
info->R[PSC_POWER] = -3;
} else {
info->m[PSC_CURRENT_IN] = 5405;
info->b[PSC_CURRENT_IN] = 0;
info->R[PSC_CURRENT_IN] = -2;
info->m[PSC_POWER] = 605;
info->b[PSC_POWER] = 0;
info->R[PSC_POWER] = -3;
}
break;
default:
ret = -ENODEV;
goto err_mem;
}
ret = pmbus_do_probe(client, id, info);
if (ret)
goto err_mem;
return 0;
err_mem:
kfree(data);
return ret;
}
static int lm25066_remove(struct i2c_client *client)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
const struct lm25066_data *data = to_lm25066_data(info);
pmbus_do_remove(client);
kfree(data);
return 0;
}
static int __init lm25066_init(void)
{
return i2c_add_driver(&lm25066_driver);
}
static void __exit lm25066_exit(void)
{
i2c_del_driver(&lm25066_driver);
}
