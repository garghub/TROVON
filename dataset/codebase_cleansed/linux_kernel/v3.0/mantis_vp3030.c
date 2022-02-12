static int vp3030_frontend_init(struct mantis_pci *mantis, struct dvb_frontend *fe)
{
struct i2c_adapter *adapter = &mantis->adapter;
struct mantis_hwconfig *config = mantis->hwconfig;
int err = 0;
mantis_gpio_set_bits(mantis, config->reset, 0);
msleep(100);
err = mantis_frontend_power(mantis, POWER_ON);
msleep(100);
mantis_gpio_set_bits(mantis, config->reset, 1);
if (err == 0) {
msleep(250);
dprintk(MANTIS_ERROR, 1, "Probing for 10353 (DVB-T)");
fe = dvb_attach(zl10353_attach, &mantis_vp3030_config, adapter);
if (!fe)
return -1;
dvb_attach(tda665x_attach, fe, &env57h12d5_config, adapter);
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
