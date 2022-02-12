static int max8688_read_byte_data(struct i2c_client *client, int page, int reg)
{
int ret = 0;
int mfg_status;
if (page)
return -EINVAL;
switch (reg) {
case PMBUS_STATUS_VOUT:
mfg_status = pmbus_read_word_data(client, 0,
MAX8688_MFG_STATUS);
if (mfg_status < 0)
return mfg_status;
if (mfg_status & MAX8688_STATUS_UV_WARNING)
ret |= PB_VOLTAGE_UV_WARNING;
if (mfg_status & MAX8688_STATUS_UV_FAULT)
ret |= PB_VOLTAGE_UV_FAULT;
if (mfg_status & MAX8688_STATUS_OV_WARNING)
ret |= PB_VOLTAGE_OV_WARNING;
if (mfg_status & MAX8688_STATUS_OV_FAULT)
ret |= PB_VOLTAGE_OV_FAULT;
break;
case PMBUS_STATUS_IOUT:
mfg_status = pmbus_read_word_data(client, 0,
MAX8688_MFG_STATUS);
if (mfg_status < 0)
return mfg_status;
if (mfg_status & MAX8688_STATUS_UC_FAULT)
ret |= PB_IOUT_UC_FAULT;
if (mfg_status & MAX8688_STATUS_OC_WARNING)
ret |= PB_IOUT_OC_WARNING;
if (mfg_status & MAX8688_STATUS_OC_FAULT)
ret |= PB_IOUT_OC_FAULT;
break;
case PMBUS_STATUS_TEMPERATURE:
mfg_status = pmbus_read_word_data(client, 0,
MAX8688_MFG_STATUS);
if (mfg_status < 0)
return mfg_status;
if (mfg_status & MAX8688_STATUS_OT_WARNING)
ret |= PB_TEMP_OT_WARNING;
if (mfg_status & MAX8688_STATUS_OT_FAULT)
ret |= PB_TEMP_OT_FAULT;
break;
default:
ret = -ENODATA;
break;
}
return ret;
}
static int max8688_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
return pmbus_do_probe(client, id, &max8688_info);
}
static int max8688_remove(struct i2c_client *client)
{
return pmbus_do_remove(client);
}
static int __init max8688_init(void)
{
return i2c_add_driver(&max8688_driver);
}
static void __exit max8688_exit(void)
{
i2c_del_driver(&max8688_driver);
}
