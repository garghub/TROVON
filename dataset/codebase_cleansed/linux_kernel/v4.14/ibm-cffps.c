static int ibm_cffps_read_byte_data(struct i2c_client *client, int page,
int reg)
{
int rc, mfr;
switch (reg) {
case PMBUS_STATUS_VOUT:
case PMBUS_STATUS_IOUT:
case PMBUS_STATUS_TEMPERATURE:
case PMBUS_STATUS_FAN_12:
rc = pmbus_read_byte_data(client, page, reg);
if (rc < 0)
return rc;
mfr = pmbus_read_byte_data(client, page,
PMBUS_STATUS_MFR_SPECIFIC);
if (mfr < 0)
return rc;
if (reg == PMBUS_STATUS_FAN_12) {
if (mfr & CFFPS_MFR_FAN_FAULT)
rc |= PB_FAN_FAN1_FAULT;
} else if (reg == PMBUS_STATUS_TEMPERATURE) {
if (mfr & CFFPS_MFR_THERMAL_FAULT)
rc |= PB_TEMP_OT_FAULT;
} else if (reg == PMBUS_STATUS_VOUT) {
if (mfr & (CFFPS_MFR_OV_FAULT | CFFPS_MFR_VAUX_FAULT))
rc |= PB_VOLTAGE_OV_FAULT;
if (mfr & CFFPS_MFR_UV_FAULT)
rc |= PB_VOLTAGE_UV_FAULT;
} else if (reg == PMBUS_STATUS_IOUT) {
if (mfr & CFFPS_MFR_OC_FAULT)
rc |= PB_IOUT_OC_FAULT;
if (mfr & CFFPS_MFR_CURRENT_SHARE_WARNING)
rc |= PB_CURRENT_SHARE_FAULT;
}
break;
default:
rc = -ENODATA;
break;
}
return rc;
}
static int ibm_cffps_read_word_data(struct i2c_client *client, int page,
int reg)
{
int rc, mfr;
switch (reg) {
case PMBUS_STATUS_WORD:
rc = pmbus_read_word_data(client, page, reg);
if (rc < 0)
return rc;
mfr = pmbus_read_byte_data(client, page,
PMBUS_STATUS_MFR_SPECIFIC);
if (mfr < 0)
return rc;
if (mfr & CFFPS_MFR_PS_KILL)
rc |= PB_STATUS_OFF;
break;
default:
rc = -ENODATA;
break;
}
return rc;
}
static int ibm_cffps_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
return pmbus_do_probe(client, id, &ibm_cffps_info);
}
