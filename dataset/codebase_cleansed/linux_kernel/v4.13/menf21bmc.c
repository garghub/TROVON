static int menf21bmc_wdt_exit_prod_mode(struct i2c_client *client)
{
int val, ret;
val = i2c_smbus_read_byte_data(client, BMC_CMD_WDT_PROD_STAT);
if (val < 0)
return val;
if (val == 0x00) {
dev_info(&client->dev,
"BMC in production mode. Exit production mode\n");
ret = i2c_smbus_write_byte(client, BMC_CMD_WDT_EXIT_PROD);
if (ret < 0)
return ret;
}
return 0;
}
static int
menf21bmc_probe(struct i2c_client *client, const struct i2c_device_id *ids)
{
int rev_major, rev_minor, rev_main;
int ret;
ret = i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_BYTE_DATA |
I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_BYTE);
if (!ret)
return -ENODEV;
rev_major = i2c_smbus_read_word_data(client, BMC_CMD_REV_MAJOR);
if (rev_major < 0) {
dev_err(&client->dev, "failed to get BMC major revision\n");
return rev_major;
}
rev_minor = i2c_smbus_read_word_data(client, BMC_CMD_REV_MINOR);
if (rev_minor < 0) {
dev_err(&client->dev, "failed to get BMC minor revision\n");
return rev_minor;
}
rev_main = i2c_smbus_read_word_data(client, BMC_CMD_REV_MAIN);
if (rev_main < 0) {
dev_err(&client->dev, "failed to get BMC main revision\n");
return rev_main;
}
dev_info(&client->dev, "FW Revision: %02d.%02d.%02d\n",
rev_major, rev_minor, rev_main);
ret = menf21bmc_wdt_exit_prod_mode(client);
if (ret < 0) {
dev_err(&client->dev, "failed to leave production mode\n");
return ret;
}
ret = devm_mfd_add_devices(&client->dev, 0, menf21bmc_cell,
ARRAY_SIZE(menf21bmc_cell), NULL, 0, NULL);
if (ret < 0) {
dev_err(&client->dev, "failed to add BMC sub-devices\n");
return ret;
}
return 0;
}
