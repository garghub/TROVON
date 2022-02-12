int vp1034_set_voltage(struct dvb_frontend *fe, fe_sec_voltage_t voltage)
{
struct mantis_pci *mantis = fe->dvb->priv;
switch (voltage) {
case SEC_VOLTAGE_13:
dprintk(MANTIS_ERROR, 1, "Polarization=[13V]");
mantis_gpio_set_bits(mantis, 13, 1);
mantis_gpio_set_bits(mantis, 14, 0);
break;
case SEC_VOLTAGE_18:
dprintk(MANTIS_ERROR, 1, "Polarization=[18V]");
mantis_gpio_set_bits(mantis, 13, 1);
mantis_gpio_set_bits(mantis, 14, 1);
break;
case SEC_VOLTAGE_OFF:
dprintk(MANTIS_ERROR, 1, "Frontend (dummy) POWERDOWN");
break;
default:
dprintk(MANTIS_ERROR, 1, "Invalid = (%d)", (u32) voltage);
return -EINVAL;
}
mmwrite(0x00, MANTIS_GPIF_DOUT);
return 0;
}
static int vp1034_frontend_init(struct mantis_pci *mantis, struct dvb_frontend *fe)
{
struct i2c_adapter *adapter = &mantis->adapter;
int err = 0;
err = mantis_frontend_power(mantis, POWER_ON);
if (err == 0) {
mantis_frontend_soft_reset(mantis);
msleep(250);
dprintk(MANTIS_ERROR, 1, "Probing for MB86A16 (DVB-S/DSS)");
fe = dvb_attach(mb86a16_attach, &vp1034_mb86a16_config, adapter);
if (fe) {
dprintk(MANTIS_ERROR, 1,
"found MB86A16 DVB-S/DSS frontend @0x%02x",
vp1034_mb86a16_config.demod_address);
} else {
return -1;
}
} else {
dprintk(MANTIS_ERROR, 1, "Frontend on <%s> POWER ON failed! <%d>",
adapter->name,
err);
return -EIO;
}
mantis->fe = fe;
dprintk(MANTIS_ERROR, 1, "Done!");
return 0;
}
