int dibusb_dib3000mc_frontend_attach(struct dvb_usb_adapter *adap)
{
if (le16_to_cpu(adap->dev->udev->descriptor.idVendor) == USB_VID_LITEON &&
le16_to_cpu(adap->dev->udev->descriptor.idProduct) ==
USB_PID_LITEON_DVB_T_WARM) {
msleep(1000);
}
adap->fe_adap[0].fe = dvb_attach(dib3000mc_attach,
&adap->dev->i2c_adap,
DEFAULT_DIB3000P_I2C_ADDRESS,
&mod3000p_dib3000p_config);
if ((adap->fe_adap[0].fe) == NULL)
adap->fe_adap[0].fe = dvb_attach(dib3000mc_attach,
&adap->dev->i2c_adap,
DEFAULT_DIB3000MC_I2C_ADDRESS,
&mod3000p_dib3000p_config);
if ((adap->fe_adap[0].fe) != NULL) {
if (adap->priv != NULL) {
struct dibusb_state *st = adap->priv;
st->ops.pid_parse = dib3000mc_pid_parse;
st->ops.pid_ctrl = dib3000mc_pid_control;
}
return 0;
}
return -ENODEV;
}
int dibusb_dib3000mc_tuner_attach(struct dvb_usb_adapter *adap)
{
struct dibusb_state *st = adap->priv;
u8 a,b;
u16 if1 = 1220;
struct i2c_adapter *tun_i2c;
if (le16_to_cpu(adap->dev->udev->descriptor.idVendor) == USB_VID_LITEON &&
le16_to_cpu(adap->dev->udev->descriptor.idProduct) == USB_PID_LITEON_DVB_T_WARM) {
dibusb_read_eeprom_byte(adap->dev,0x7E,&a);
dibusb_read_eeprom_byte(adap->dev,0x7F,&b);
if (a == 0x00)
if1 += b;
else if (a == 0x80)
if1 -= b;
else
warn("LITE-ON DVB-T: Strange IF1 calibration :%2X %2X\n", a, b);
} else if (le16_to_cpu(adap->dev->udev->descriptor.idVendor) == USB_VID_DIBCOM &&
le16_to_cpu(adap->dev->udev->descriptor.idProduct) == USB_PID_DIBCOM_MOD3001_WARM) {
u8 desc;
dibusb_read_eeprom_byte(adap->dev, 7, &desc);
if (desc == 2) {
a = 127;
do {
dibusb_read_eeprom_byte(adap->dev, a, &desc);
a--;
} while (a > 7 && (desc == 0xff || desc == 0x00));
if (desc & 0x80)
if1 -= (0xff - desc);
else
if1 += desc;
}
}
tun_i2c = dib3000mc_get_tuner_i2c_master(adap->fe_adap[0].fe, 1);
if (dvb_attach(mt2060_attach, adap->fe_adap[0].fe, tun_i2c, &stk3000p_mt2060_config, if1) == NULL) {
if (dvb_attach(dvb_pll_attach, adap->fe_adap[0].fe, 0x60, tun_i2c, DVB_PLL_ENV57H1XD5) == NULL)
return -ENOMEM;
} else {
st->mt2060_present = 1;
dib3000mc_set_config(adap->fe_adap[0].fe, &stk3000p_dib3000p_config);
}
return 0;
}
