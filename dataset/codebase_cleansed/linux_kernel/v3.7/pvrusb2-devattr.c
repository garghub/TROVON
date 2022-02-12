static int pvr2_lgdt3303_attach(struct pvr2_dvb_adapter *adap)
{
adap->fe = dvb_attach(lgdt330x_attach, &pvr2_lgdt3303_config,
&adap->channel.hdw->i2c_adap);
if (adap->fe)
return 0;
return -EIO;
}
static int pvr2_lgh06xf_attach(struct pvr2_dvb_adapter *adap)
{
dvb_attach(simple_tuner_attach, adap->fe,
&adap->channel.hdw->i2c_adap, 0x61,
TUNER_LG_TDVS_H06XF);
return 0;
}
static int pvr2_lgdt3302_attach(struct pvr2_dvb_adapter *adap)
{
adap->fe = dvb_attach(lgdt330x_attach, &pvr2_lgdt3302_config,
&adap->channel.hdw->i2c_adap);
if (adap->fe)
return 0;
return -EIO;
}
static int pvr2_fcv1236d_attach(struct pvr2_dvb_adapter *adap)
{
dvb_attach(simple_tuner_attach, adap->fe,
&adap->channel.hdw->i2c_adap, 0x61,
TUNER_PHILIPS_FCV1236D);
return 0;
}
static int pvr2_tda10048_attach(struct pvr2_dvb_adapter *adap)
{
adap->fe = dvb_attach(tda10048_attach, &hauppauge_tda10048_config,
&adap->channel.hdw->i2c_adap);
if (adap->fe)
return 0;
return -EIO;
}
static int pvr2_73xxx_tda18271_8295_attach(struct pvr2_dvb_adapter *adap)
{
dvb_attach(tda829x_attach, adap->fe,
&adap->channel.hdw->i2c_adap, 0x42,
&tda829x_no_probe);
dvb_attach(tda18271_attach, adap->fe, 0x60,
&adap->channel.hdw->i2c_adap,
&hauppauge_tda18271_dvb_config);
return 0;
}
static int pvr2_s5h1409_attach(struct pvr2_dvb_adapter *adap)
{
adap->fe = dvb_attach(s5h1409_attach, &pvr2_s5h1409_config,
&adap->channel.hdw->i2c_adap);
if (adap->fe)
return 0;
return -EIO;
}
static int pvr2_s5h1411_attach(struct pvr2_dvb_adapter *adap)
{
adap->fe = dvb_attach(s5h1411_attach, &pvr2_s5h1411_config,
&adap->channel.hdw->i2c_adap);
if (adap->fe)
return 0;
return -EIO;
}
static int pvr2_tda18271_8295_attach(struct pvr2_dvb_adapter *adap)
{
dvb_attach(tda829x_attach, adap->fe,
&adap->channel.hdw->i2c_adap, 0x42,
&tda829x_no_probe);
dvb_attach(tda18271_attach, adap->fe, 0x60,
&adap->channel.hdw->i2c_adap,
&hauppauge_tda18271_config);
return 0;
}
