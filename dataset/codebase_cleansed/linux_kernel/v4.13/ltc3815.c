static int ltc3815_read_byte_data(struct i2c_client *client, int page, int reg)
{
int ret;
switch (reg) {
case PMBUS_VOUT_MODE:
ret = 0x40;
break;
default:
ret = -ENODATA;
break;
}
return ret;
}
static int ltc3815_write_byte(struct i2c_client *client, int page, u8 reg)
{
int ret;
switch (reg) {
case PMBUS_CLEAR_FAULTS:
ret = pmbus_read_word_data(client, 0, PMBUS_STATUS_WORD);
if (ret > 0) {
pmbus_write_word_data(client, 0, PMBUS_STATUS_WORD,
ret);
ret = 0;
}
break;
default:
ret = -ENODATA;
break;
}
return ret;
}
static int ltc3815_read_word_data(struct i2c_client *client, int page, int reg)
{
int ret;
switch (reg) {
case PMBUS_VIRT_READ_VIN_MAX:
ret = pmbus_read_word_data(client, page, LTC3815_MFR_VIN_PEAK);
break;
case PMBUS_VIRT_READ_VOUT_MAX:
ret = pmbus_read_word_data(client, page, LTC3815_MFR_VOUT_PEAK);
break;
case PMBUS_VIRT_READ_TEMP_MAX:
ret = pmbus_read_word_data(client, page, LTC3815_MFR_TEMP_PEAK);
break;
case PMBUS_VIRT_READ_IOUT_MAX:
ret = pmbus_read_word_data(client, page, LTC3815_MFR_IOUT_PEAK);
break;
case PMBUS_VIRT_READ_IIN_MAX:
ret = pmbus_read_word_data(client, page, LTC3815_MFR_IIN_PEAK);
break;
case PMBUS_VIRT_RESET_VOUT_HISTORY:
case PMBUS_VIRT_RESET_VIN_HISTORY:
case PMBUS_VIRT_RESET_TEMP_HISTORY:
case PMBUS_VIRT_RESET_IOUT_HISTORY:
case PMBUS_VIRT_RESET_IIN_HISTORY:
ret = 0;
break;
default:
ret = -ENODATA;
break;
}
return ret;
}
static int ltc3815_write_word_data(struct i2c_client *client, int page,
int reg, u16 word)
{
int ret;
switch (reg) {
case PMBUS_VIRT_RESET_IIN_HISTORY:
ret = pmbus_write_word_data(client, page,
LTC3815_MFR_IIN_PEAK, 0);
break;
case PMBUS_VIRT_RESET_IOUT_HISTORY:
ret = pmbus_write_word_data(client, page,
LTC3815_MFR_IOUT_PEAK, 0);
break;
case PMBUS_VIRT_RESET_VOUT_HISTORY:
ret = pmbus_write_word_data(client, page,
LTC3815_MFR_VOUT_PEAK, 0);
break;
case PMBUS_VIRT_RESET_VIN_HISTORY:
ret = pmbus_write_word_data(client, page,
LTC3815_MFR_VIN_PEAK, 0);
break;
case PMBUS_VIRT_RESET_TEMP_HISTORY:
ret = pmbus_write_word_data(client, page,
LTC3815_MFR_TEMP_PEAK, 0);
break;
default:
ret = -ENODATA;
break;
}
return ret;
}
static int ltc3815_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int chip_id;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_WORD_DATA))
return -ENODEV;
chip_id = i2c_smbus_read_word_data(client, LTC3815_MFR_SPECIAL_ID);
if (chip_id < 0)
return chip_id;
if ((chip_id & LTC3815_ID_MASK) != LTC3815_ID)
return -ENODEV;
return pmbus_do_probe(client, id, &ltc3815_info);
}
