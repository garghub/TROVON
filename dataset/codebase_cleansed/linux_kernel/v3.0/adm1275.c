static int adm1275_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int config;
int ret;
struct pmbus_driver_info *info;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_BYTE_DATA))
return -ENODEV;
info = kzalloc(sizeof(struct pmbus_driver_info), GFP_KERNEL);
if (!info)
return -ENOMEM;
config = i2c_smbus_read_byte_data(client, ADM1275_PMON_CONFIG);
if (config < 0) {
ret = config;
goto err_mem;
}
info->pages = 1;
info->direct[PSC_VOLTAGE_IN] = true;
info->direct[PSC_VOLTAGE_OUT] = true;
info->direct[PSC_CURRENT_OUT] = true;
info->m[PSC_CURRENT_OUT] = 807;
info->b[PSC_CURRENT_OUT] = 20475;
info->R[PSC_CURRENT_OUT] = -1;
info->func[0] = PMBUS_HAVE_IOUT | PMBUS_HAVE_STATUS_IOUT;
if (config & ADM1275_VRANGE) {
info->m[PSC_VOLTAGE_IN] = 19199;
info->b[PSC_VOLTAGE_IN] = 0;
info->R[PSC_VOLTAGE_IN] = -2;
info->m[PSC_VOLTAGE_OUT] = 19199;
info->b[PSC_VOLTAGE_OUT] = 0;
info->R[PSC_VOLTAGE_OUT] = -2;
} else {
info->m[PSC_VOLTAGE_IN] = 6720;
info->b[PSC_VOLTAGE_IN] = 0;
info->R[PSC_VOLTAGE_IN] = -1;
info->m[PSC_VOLTAGE_OUT] = 6720;
info->b[PSC_VOLTAGE_OUT] = 0;
info->R[PSC_VOLTAGE_OUT] = -1;
}
if (config & ADM1275_VIN_VOUT_SELECT)
info->func[0] |= PMBUS_HAVE_VOUT | PMBUS_HAVE_STATUS_VOUT;
else
info->func[0] |= PMBUS_HAVE_VIN | PMBUS_HAVE_STATUS_INPUT;
ret = pmbus_do_probe(client, id, info);
if (ret)
goto err_mem;
return 0;
err_mem:
kfree(info);
return ret;
}
static int adm1275_remove(struct i2c_client *client)
{
const struct pmbus_driver_info *info = pmbus_get_driver_info(client);
int ret;
ret = pmbus_do_remove(client);
kfree(info);
return ret;
}
static int __init adm1275_init(void)
{
return i2c_add_driver(&adm1275_driver);
}
static void __exit adm1275_exit(void)
{
i2c_del_driver(&adm1275_driver);
}
