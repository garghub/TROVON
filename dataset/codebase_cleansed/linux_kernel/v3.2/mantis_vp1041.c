static int vp1041_frontend_init(struct mantis_pci *mantis, struct dvb_frontend *fe)
{
struct i2c_adapter *adapter = &mantis->adapter;
int err = 0;
err = mantis_frontend_power(mantis, POWER_ON);
if (err == 0) {
mantis_frontend_soft_reset(mantis);
msleep(250);
mantis->fe = dvb_attach(stb0899_attach, &vp1041_stb0899_config, adapter);
if (mantis->fe) {
dprintk(MANTIS_ERROR, 1,
"found STB0899 DVB-S/DVB-S2 frontend @0x%02x",
vp1041_stb0899_config.demod_address);
if (dvb_attach(stb6100_attach, mantis->fe, &vp1041_stb6100_config, adapter)) {
if (!dvb_attach(lnbp21_attach, mantis->fe, adapter, 0, 0))
dprintk(MANTIS_ERROR, 1, "No LNBP21 found!");
}
} else {
return -EREMOTEIO;
}
} else {
dprintk(MANTIS_ERROR, 1, "Frontend on <%s> POWER ON failed! <%d>",
adapter->name,
err);
return -EIO;
}
dprintk(MANTIS_ERROR, 1, "Done!");
return 0;
}
