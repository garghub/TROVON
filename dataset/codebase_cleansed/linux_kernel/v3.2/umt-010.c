static int umt_mt352_demod_init(struct dvb_frontend *fe)
{
static u8 mt352_clock_config[] = { 0x89, 0xb8, 0x2d };
static u8 mt352_reset[] = { 0x50, 0x80 };
static u8 mt352_mclk_ratio[] = { 0x8b, 0x00 };
static u8 mt352_adc_ctl_1_cfg[] = { 0x8E, 0x40 };
static u8 mt352_agc_cfg[] = { 0x67, 0x10, 0xa0 };
static u8 mt352_sec_agc_cfg1[] = { 0x6a, 0xff };
static u8 mt352_sec_agc_cfg2[] = { 0x6d, 0xff };
static u8 mt352_sec_agc_cfg3[] = { 0x70, 0x40 };
static u8 mt352_sec_agc_cfg4[] = { 0x7b, 0x03 };
static u8 mt352_sec_agc_cfg5[] = { 0x7d, 0x0f };
static u8 mt352_acq_ctl[] = { 0x53, 0x50 };
static u8 mt352_input_freq_1[] = { 0x56, 0x31, 0x06 };
mt352_write(fe, mt352_clock_config, sizeof(mt352_clock_config));
udelay(2000);
mt352_write(fe, mt352_reset, sizeof(mt352_reset));
mt352_write(fe, mt352_mclk_ratio, sizeof(mt352_mclk_ratio));
mt352_write(fe, mt352_adc_ctl_1_cfg, sizeof(mt352_adc_ctl_1_cfg));
mt352_write(fe, mt352_agc_cfg, sizeof(mt352_agc_cfg));
mt352_write(fe, mt352_sec_agc_cfg1, sizeof(mt352_sec_agc_cfg1));
mt352_write(fe, mt352_sec_agc_cfg2, sizeof(mt352_sec_agc_cfg2));
mt352_write(fe, mt352_sec_agc_cfg3, sizeof(mt352_sec_agc_cfg3));
mt352_write(fe, mt352_sec_agc_cfg4, sizeof(mt352_sec_agc_cfg4));
mt352_write(fe, mt352_sec_agc_cfg5, sizeof(mt352_sec_agc_cfg5));
mt352_write(fe, mt352_acq_ctl, sizeof(mt352_acq_ctl));
mt352_write(fe, mt352_input_freq_1, sizeof(mt352_input_freq_1));
return 0;
}
static int umt_mt352_frontend_attach(struct dvb_usb_adapter *adap)
{
struct mt352_config umt_config;
memset(&umt_config,0,sizeof(struct mt352_config));
umt_config.demod_init = umt_mt352_demod_init;
umt_config.demod_address = 0xf;
adap->fe_adap[0].fe = dvb_attach(mt352_attach, &umt_config, &adap->dev->i2c_adap);
return 0;
}
static int umt_tuner_attach (struct dvb_usb_adapter *adap)
{
dvb_attach(dvb_pll_attach, adap->fe_adap[0].fe, 0x61, NULL, DVB_PLL_TUA6034);
return 0;
}
static int umt_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
if (0 == dvb_usb_device_init(intf, &umt_properties,
THIS_MODULE, NULL, adapter_nr))
return 0;
return -EINVAL;
}
static int __init umt_module_init(void)
{
int result;
if ((result = usb_register(&umt_driver))) {
err("usb_register failed. Error number %d",result);
return result;
}
return 0;
}
static void __exit umt_module_exit(void)
{
usb_deregister(&umt_driver);
}
