static int max34440_read_byte_data(struct i2c_client *client, int page, int reg)
{
int ret;
int mfg_status;
ret = pmbus_set_page(client, page);
if (ret < 0)
return ret;
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
return pmbus_do_probe(client, id, &max34440_info[id->driver_data]);
}
static int max34440_remove(struct i2c_client *client)
{
return pmbus_do_remove(client);
}
static int __init max34440_init(void)
{
return i2c_add_driver(&max34440_driver);
}
static void __exit max34440_exit(void)
{
i2c_del_driver(&max34440_driver);
}
