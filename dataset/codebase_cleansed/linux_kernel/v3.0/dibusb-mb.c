static int dib3000mb_i2c_gate_ctrl(struct dvb_frontend* fe, int enable)
{
struct dvb_usb_adapter *adap = fe->dvb->priv;
struct dibusb_state *st = adap->priv;
return st->ops.tuner_pass_ctrl(fe, enable, st->tuner_addr);
}
static int dibusb_dib3000mb_frontend_attach(struct dvb_usb_adapter *adap)
{
struct dib3000_config demod_cfg;
struct dibusb_state *st = adap->priv;
demod_cfg.demod_address = 0x8;
if ((adap->fe = dvb_attach(dib3000mb_attach, &demod_cfg,
&adap->dev->i2c_adap, &st->ops)) == NULL)
return -ENODEV;
adap->fe->ops.i2c_gate_ctrl = dib3000mb_i2c_gate_ctrl;
return 0;
}
static int dibusb_thomson_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dibusb_state *st = adap->priv;
st->tuner_addr = 0x61;
dvb_attach(dvb_pll_attach, adap->fe, 0x61, &adap->dev->i2c_adap,
DVB_PLL_TUA6010XS);
return 0;
}
static int dibusb_panasonic_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dibusb_state *st = adap->priv;
st->tuner_addr = 0x60;
dvb_attach(dvb_pll_attach, adap->fe, 0x60, &adap->dev->i2c_adap,
DVB_PLL_TDA665X);
return 0;
}
static int dibusb_tuner_probe_and_attach(struct dvb_usb_adapter *adap)
{
u8 b[2] = { 0,0 }, b2[1];
int ret = 0;
struct i2c_msg msg[2] = {
{ .flags = 0, .buf = b, .len = 2 },
{ .flags = I2C_M_RD, .buf = b2, .len = 1 },
};
struct dibusb_state *st = adap->priv;
msg[0].addr = msg[1].addr = st->tuner_addr = 0x60;
if (adap->fe->ops.i2c_gate_ctrl)
adap->fe->ops.i2c_gate_ctrl(adap->fe,1);
if (i2c_transfer(&adap->dev->i2c_adap, msg, 2) != 2) {
err("tuner i2c write failed.");
ret = -EREMOTEIO;
}
if (adap->fe->ops.i2c_gate_ctrl)
adap->fe->ops.i2c_gate_ctrl(adap->fe,0);
if (b2[0] == 0xfe) {
info("This device has the Thomson Cable onboard. Which is default.");
ret = dibusb_thomson_tuner_attach(adap);
} else {
info("This device has the Panasonic ENV77H11D5 onboard.");
ret = dibusb_panasonic_tuner_attach(adap);
}
return ret;
}
static int dibusb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
if (0 == dvb_usb_device_init(intf, &dibusb1_1_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &dibusb1_1_an2235_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &dibusb2_0b_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &artec_t1_usb2_properties,
THIS_MODULE, NULL, adapter_nr))
return 0;
return -EINVAL;
}
static int __init dibusb_module_init(void)
{
int result;
if ((result = usb_register(&dibusb_driver))) {
err("usb_register failed. Error number %d",result);
return result;
}
return 0;
}
static void __exit dibusb_module_exit(void)
{
usb_deregister(&dibusb_driver);
}
