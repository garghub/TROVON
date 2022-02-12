static int dvb_buf_setup(struct videobuf_queue *q,
unsigned int *count, unsigned int *size)
{
struct cx23885_tsport *port = q->priv_data;
port->ts_packet_size = 188 * 4;
port->ts_packet_count = 32;
*size = port->ts_packet_size * port->ts_packet_count;
*count = 32;
return 0;
}
static int dvb_buf_prepare(struct videobuf_queue *q,
struct videobuf_buffer *vb, enum v4l2_field field)
{
struct cx23885_tsport *port = q->priv_data;
return cx23885_buf_prepare(q, port, (struct cx23885_buffer *)vb, field);
}
static void dvb_buf_queue(struct videobuf_queue *q, struct videobuf_buffer *vb)
{
struct cx23885_tsport *port = q->priv_data;
cx23885_buf_queue(port, (struct cx23885_buffer *)vb);
}
static void dvb_buf_release(struct videobuf_queue *q,
struct videobuf_buffer *vb)
{
cx23885_free_buffer(q, (struct cx23885_buffer *)vb);
}
static void cx23885_dvb_gate_ctrl(struct cx23885_tsport *port, int open)
{
struct videobuf_dvb_frontends *f;
struct videobuf_dvb_frontend *fe;
f = &port->frontends;
if (f->gate <= 1)
fe = videobuf_dvb_get_frontend(f, 1);
else
fe = videobuf_dvb_get_frontend(f, f->gate);
if (fe && fe->dvb.frontend && fe->dvb.frontend->ops.i2c_gate_ctrl)
fe->dvb.frontend->ops.i2c_gate_ctrl(fe->dvb.frontend, open);
}
static int p8000_set_voltage(struct dvb_frontend *fe, fe_sec_voltage_t voltage)
{
struct cx23885_tsport *port = fe->dvb->priv;
struct cx23885_dev *dev = port->dev;
if (voltage == SEC_VOLTAGE_18)
cx_write(MC417_RWD, 0x00001e00);
else if (voltage == SEC_VOLTAGE_13)
cx_write(MC417_RWD, 0x00001a00);
else
cx_write(MC417_RWD, 0x00001800);
return 0;
}
static int cx23885_dvb_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct cx23885_tsport *port = fe->dvb->priv;
struct cx23885_dev *dev = port->dev;
switch (dev->board) {
case CX23885_BOARD_HAUPPAUGE_HVR1275:
switch (p->modulation) {
case VSB_8:
cx23885_gpio_clear(dev, GPIO_5);
break;
case QAM_64:
case QAM_256:
default:
cx23885_gpio_set(dev, GPIO_5);
break;
}
break;
case CX23885_BOARD_MYGICA_X8506:
case CX23885_BOARD_MYGICA_X8507:
case CX23885_BOARD_MAGICPRO_PROHDTVE2:
cx23885_gpio_set(dev, GPIO_0);
break;
}
if (port->set_frontend)
return port->set_frontend(fe);
return 0;
}
static void cx23885_set_frontend_hook(struct cx23885_tsport *port,
struct dvb_frontend *fe)
{
port->set_frontend = fe->ops.set_frontend;
fe->ops.set_frontend = cx23885_dvb_set_frontend;
}
static int netup_altera_fpga_rw(void *device, int flag, int data, int read)
{
struct cx23885_dev *dev = (struct cx23885_dev *)device;
unsigned long timeout = jiffies + msecs_to_jiffies(1);
uint32_t mem = 0;
mem = cx_read(MC417_RWD);
if (read)
cx_set(MC417_OEN, ALT_DATA);
else {
cx_clear(MC417_OEN, ALT_DATA);
mem &= ~ALT_DATA;
mem |= (data & ALT_DATA);
}
if (flag)
mem |= ALT_AD_RG;
else
mem &= ~ALT_AD_RG;
mem &= ~ALT_CS;
if (read)
mem = (mem & ~ALT_RD) | ALT_WR;
else
mem = (mem & ~ALT_WR) | ALT_RD;
cx_write(MC417_RWD, mem);
for (;;) {
mem = cx_read(MC417_RWD);
if ((mem & ALT_RDY) == 0)
break;
if (time_after(jiffies, timeout))
break;
udelay(1);
}
cx_set(MC417_RWD, ALT_RD | ALT_WR | ALT_CS);
if (read)
return mem & ALT_DATA;
return 0;
}
static int dib7070_tuner_reset(struct dvb_frontend *fe, int onoff)
{
struct dib7000p_ops *dib7000p_ops = fe->sec_priv;
return dib7000p_ops->set_gpio(fe, 8, 0, !onoff);
}
static int dib7070_tuner_sleep(struct dvb_frontend *fe, int onoff)
{
return 0;
}
static int dvb_register(struct cx23885_tsport *port)
{
struct dib7000p_ops dib7000p_ops;
struct cx23885_dev *dev = port->dev;
struct cx23885_i2c *i2c_bus = NULL, *i2c_bus2 = NULL;
struct videobuf_dvb_frontend *fe0, *fe1 = NULL;
int mfe_shared = 0;
int ret;
fe0 = videobuf_dvb_get_frontend(&port->frontends, 1);
if (!fe0)
return -EINVAL;
fe0->dvb.name = dev->name;
port->frontends.gate = 0;
port->gate_ctrl = cx23885_dvb_gate_ctrl;
switch (dev->board) {
case CX23885_BOARD_HAUPPAUGE_HVR1250:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(s5h1409_attach,
&hauppauge_generic_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
dvb_attach(mt2131_attach, fe0->dvb.frontend,
&i2c_bus->i2c_adap,
&hauppauge_generic_tunerconfig, 0);
}
break;
case CX23885_BOARD_HAUPPAUGE_HVR1270:
case CX23885_BOARD_HAUPPAUGE_HVR1275:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(lgdt3305_attach,
&hauppauge_lgdt3305_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
dvb_attach(tda18271_attach, fe0->dvb.frontend,
0x60, &dev->i2c_bus[1].i2c_adap,
&hauppauge_hvr127x_config);
}
if (dev->board == CX23885_BOARD_HAUPPAUGE_HVR1275)
cx23885_set_frontend_hook(port, fe0->dvb.frontend);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1255:
case CX23885_BOARD_HAUPPAUGE_HVR1255_22111:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(s5h1411_attach,
&hcw_s5h1411_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
dvb_attach(tda18271_attach, fe0->dvb.frontend,
0x60, &dev->i2c_bus[1].i2c_adap,
&hauppauge_tda18271_config);
}
tda18271_attach(&dev->ts1.analog_fe,
0x60, &dev->i2c_bus[1].i2c_adap,
&hauppauge_tda18271_config);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1800:
i2c_bus = &dev->i2c_bus[0];
switch (alt_tuner) {
case 1:
fe0->dvb.frontend =
dvb_attach(s5h1409_attach,
&hauppauge_ezqam_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
dvb_attach(tda829x_attach, fe0->dvb.frontend,
&dev->i2c_bus[1].i2c_adap, 0x42,
&tda829x_no_probe);
dvb_attach(tda18271_attach, fe0->dvb.frontend,
0x60, &dev->i2c_bus[1].i2c_adap,
&hauppauge_tda18271_config);
}
break;
case 0:
default:
fe0->dvb.frontend =
dvb_attach(s5h1409_attach,
&hauppauge_generic_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL)
dvb_attach(mt2131_attach, fe0->dvb.frontend,
&i2c_bus->i2c_adap,
&hauppauge_generic_tunerconfig, 0);
break;
}
break;
case CX23885_BOARD_HAUPPAUGE_HVR1800lp:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(s5h1409_attach,
&hauppauge_hvr1800lp_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
dvb_attach(mt2131_attach, fe0->dvb.frontend,
&i2c_bus->i2c_adap,
&hauppauge_generic_tunerconfig, 0);
}
break;
case CX23885_BOARD_DVICO_FUSIONHDTV_5_EXP:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(lgdt330x_attach,
&fusionhdtv_5_express,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
dvb_attach(simple_tuner_attach, fe0->dvb.frontend,
&i2c_bus->i2c_adap, 0x61,
TUNER_LG_TDVS_H06XF);
}
break;
case CX23885_BOARD_HAUPPAUGE_HVR1500Q:
i2c_bus = &dev->i2c_bus[1];
fe0->dvb.frontend = dvb_attach(s5h1409_attach,
&hauppauge_hvr1500q_config,
&dev->i2c_bus[0].i2c_adap);
if (fe0->dvb.frontend != NULL)
dvb_attach(xc5000_attach, fe0->dvb.frontend,
&i2c_bus->i2c_adap,
&hauppauge_hvr1500q_tunerconfig);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1500:
i2c_bus = &dev->i2c_bus[1];
fe0->dvb.frontend = dvb_attach(s5h1409_attach,
&hauppauge_hvr1500_config,
&dev->i2c_bus[0].i2c_adap);
if (fe0->dvb.frontend != NULL) {
struct dvb_frontend *fe;
struct xc2028_config cfg = {
.i2c_adap = &i2c_bus->i2c_adap,
.i2c_addr = 0x61,
};
static struct xc2028_ctrl ctl = {
.fname = XC2028_DEFAULT_FIRMWARE,
.max_len = 64,
.demod = XC3028_FE_OREN538,
};
fe = dvb_attach(xc2028_attach,
fe0->dvb.frontend, &cfg);
if (fe != NULL && fe->ops.tuner_ops.set_config != NULL)
fe->ops.tuner_ops.set_config(fe, &ctl);
}
break;
case CX23885_BOARD_HAUPPAUGE_HVR1200:
case CX23885_BOARD_HAUPPAUGE_HVR1700:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(tda10048_attach,
&hauppauge_hvr1200_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
dvb_attach(tda829x_attach, fe0->dvb.frontend,
&dev->i2c_bus[1].i2c_adap, 0x42,
&tda829x_no_probe);
dvb_attach(tda18271_attach, fe0->dvb.frontend,
0x60, &dev->i2c_bus[1].i2c_adap,
&hauppauge_hvr1200_tuner_config);
}
break;
case CX23885_BOARD_HAUPPAUGE_HVR1210:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(tda10048_attach,
&hauppauge_hvr1210_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
dvb_attach(tda18271_attach, fe0->dvb.frontend,
0x60, &dev->i2c_bus[1].i2c_adap,
&hauppauge_hvr1210_tuner_config);
}
break;
case CX23885_BOARD_HAUPPAUGE_HVR1400:
i2c_bus = &dev->i2c_bus[0];
if (!dvb_attach(dib7000p_attach, &dib7000p_ops))
return -ENODEV;
fe0->dvb.frontend = dib7000p_ops.init(&i2c_bus->i2c_adap,
0x12, &hauppauge_hvr1400_dib7000_config);
if (fe0->dvb.frontend != NULL) {
struct dvb_frontend *fe;
struct xc2028_config cfg = {
.i2c_adap = &dev->i2c_bus[1].i2c_adap,
.i2c_addr = 0x64,
};
static struct xc2028_ctrl ctl = {
.fname = XC3028L_DEFAULT_FIRMWARE,
.max_len = 64,
.demod = XC3028_FE_DIBCOM52,
.type = XC2028_D2633,
};
fe = dvb_attach(xc2028_attach,
fe0->dvb.frontend, &cfg);
if (fe != NULL && fe->ops.tuner_ops.set_config != NULL)
fe->ops.tuner_ops.set_config(fe, &ctl);
}
break;
case CX23885_BOARD_DVICO_FUSIONHDTV_7_DUAL_EXP:
i2c_bus = &dev->i2c_bus[port->nr - 1];
fe0->dvb.frontend = dvb_attach(s5h1409_attach,
&dvico_s5h1409_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend == NULL)
fe0->dvb.frontend = dvb_attach(s5h1411_attach,
&dvico_s5h1411_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL)
dvb_attach(xc5000_attach, fe0->dvb.frontend,
&i2c_bus->i2c_adap,
&dvico_xc5000_tunerconfig);
break;
case CX23885_BOARD_DVICO_FUSIONHDTV_DVB_T_DUAL_EXP: {
i2c_bus = &dev->i2c_bus[port->nr - 1];
fe0->dvb.frontend = dvb_attach(zl10353_attach,
&dvico_fusionhdtv_xc3028,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
struct dvb_frontend *fe;
struct xc2028_config cfg = {
.i2c_adap = &i2c_bus->i2c_adap,
.i2c_addr = 0x61,
};
static struct xc2028_ctrl ctl = {
.fname = XC2028_DEFAULT_FIRMWARE,
.max_len = 64,
.demod = XC3028_FE_ZARLINK456,
};
fe = dvb_attach(xc2028_attach, fe0->dvb.frontend,
&cfg);
if (fe != NULL && fe->ops.tuner_ops.set_config != NULL)
fe->ops.tuner_ops.set_config(fe, &ctl);
}
break;
}
case CX23885_BOARD_DVICO_FUSIONHDTV_DVB_T_DUAL_EXP2: {
i2c_bus = &dev->i2c_bus[port->nr - 1];
if (!dvb_attach(dib7000p_attach, &dib7000p_ops))
return -ENODEV;
if (dib7000p_ops.i2c_enumeration(&i2c_bus->i2c_adap, 1, 0x12, &dib7070p_dib7000p_config) < 0) {
printk(KERN_WARNING "Unable to enumerate dib7000p\n");
return -ENODEV;
}
fe0->dvb.frontend = dib7000p_ops.init(&i2c_bus->i2c_adap, 0x80, &dib7070p_dib7000p_config);
if (fe0->dvb.frontend != NULL) {
struct i2c_adapter *tun_i2c;
fe0->dvb.frontend->sec_priv = kmalloc(sizeof(dib7000p_ops), GFP_KERNEL);
memcpy(fe0->dvb.frontend->sec_priv, &dib7000p_ops, sizeof(dib7000p_ops));
tun_i2c = dib7000p_ops.get_i2c_master(fe0->dvb.frontend, DIBX000_I2C_INTERFACE_TUNER, 1);
if (!dvb_attach(dib0070_attach, fe0->dvb.frontend, tun_i2c, &dib7070p_dib0070_config))
return -ENODEV;
}
break;
}
case CX23885_BOARD_LEADTEK_WINFAST_PXDVR3200_H:
case CX23885_BOARD_COMPRO_VIDEOMATE_E650F:
case CX23885_BOARD_COMPRO_VIDEOMATE_E800:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(zl10353_attach,
&dvico_fusionhdtv_xc3028,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
struct dvb_frontend *fe;
struct xc2028_config cfg = {
.i2c_adap = &dev->i2c_bus[1].i2c_adap,
.i2c_addr = 0x61,
};
static struct xc2028_ctrl ctl = {
.fname = XC2028_DEFAULT_FIRMWARE,
.max_len = 64,
.demod = XC3028_FE_ZARLINK456,
};
fe = dvb_attach(xc2028_attach, fe0->dvb.frontend,
&cfg);
if (fe != NULL && fe->ops.tuner_ops.set_config != NULL)
fe->ops.tuner_ops.set_config(fe, &ctl);
}
break;
case CX23885_BOARD_LEADTEK_WINFAST_PXDVR3200_H_XC4000:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(zl10353_attach,
&dvico_fusionhdtv_xc3028,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
struct dvb_frontend *fe;
struct xc4000_config cfg = {
.i2c_address = 0x61,
.default_pm = 0,
.dvb_amplitude = 134,
.set_smoothedcvbs = 1,
.if_khz = 4560
};
fe = dvb_attach(xc4000_attach, fe0->dvb.frontend,
&dev->i2c_bus[1].i2c_adap, &cfg);
if (!fe) {
printk(KERN_ERR "%s/2: xc4000 attach failed\n",
dev->name);
goto frontend_detach;
}
}
break;
case CX23885_BOARD_TBS_6920:
i2c_bus = &dev->i2c_bus[1];
fe0->dvb.frontend = dvb_attach(cx24116_attach,
&tbs_cx24116_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL)
fe0->dvb.frontend->ops.set_voltage = f300_set_voltage;
break;
case CX23885_BOARD_TBS_6980:
case CX23885_BOARD_TBS_6981:
i2c_bus = &dev->i2c_bus[1];
switch (port->nr) {
case 1:
fe0->dvb.frontend = dvb_attach(cx24117_attach,
&tbs_cx24117_config,
&i2c_bus->i2c_adap);
break;
case 2:
fe0->dvb.frontend = dvb_attach(cx24117_attach,
&tbs_cx24117_config,
&i2c_bus->i2c_adap);
break;
}
break;
case CX23885_BOARD_TEVII_S470:
i2c_bus = &dev->i2c_bus[1];
fe0->dvb.frontend = dvb_attach(ds3000_attach,
&tevii_ds3000_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
dvb_attach(ts2020_attach, fe0->dvb.frontend,
&tevii_ts2020_config, &i2c_bus->i2c_adap);
fe0->dvb.frontend->ops.set_voltage = f300_set_voltage;
}
break;
case CX23885_BOARD_DVBWORLD_2005:
i2c_bus = &dev->i2c_bus[1];
fe0->dvb.frontend = dvb_attach(cx24116_attach,
&dvbworld_cx24116_config,
&i2c_bus->i2c_adap);
break;
case CX23885_BOARD_NETUP_DUAL_DVBS2_CI:
i2c_bus = &dev->i2c_bus[0];
switch (port->nr) {
case 1:
fe0->dvb.frontend = dvb_attach(stv0900_attach,
&netup_stv0900_config,
&i2c_bus->i2c_adap, 0);
if (fe0->dvb.frontend != NULL) {
if (dvb_attach(stv6110_attach,
fe0->dvb.frontend,
&netup_stv6110_tunerconfig_a,
&i2c_bus->i2c_adap)) {
if (!dvb_attach(lnbh24_attach,
fe0->dvb.frontend,
&i2c_bus->i2c_adap,
LNBH24_PCL | LNBH24_TTX,
LNBH24_TEN, 0x09))
printk(KERN_ERR
"No LNBH24 found!\n");
}
}
break;
case 2:
fe0->dvb.frontend = dvb_attach(stv0900_attach,
&netup_stv0900_config,
&i2c_bus->i2c_adap, 1);
if (fe0->dvb.frontend != NULL) {
if (dvb_attach(stv6110_attach,
fe0->dvb.frontend,
&netup_stv6110_tunerconfig_b,
&i2c_bus->i2c_adap)) {
if (!dvb_attach(lnbh24_attach,
fe0->dvb.frontend,
&i2c_bus->i2c_adap,
LNBH24_PCL | LNBH24_TTX,
LNBH24_TEN, 0x0a))
printk(KERN_ERR
"No LNBH24 found!\n");
}
}
break;
}
break;
case CX23885_BOARD_MYGICA_X8506:
i2c_bus = &dev->i2c_bus[0];
i2c_bus2 = &dev->i2c_bus[1];
fe0->dvb.frontend = dvb_attach(lgs8gxx_attach,
&mygica_x8506_lgs8gl5_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
dvb_attach(xc5000_attach,
fe0->dvb.frontend,
&i2c_bus2->i2c_adap,
&mygica_x8506_xc5000_config);
}
cx23885_set_frontend_hook(port, fe0->dvb.frontend);
break;
case CX23885_BOARD_MYGICA_X8507:
i2c_bus = &dev->i2c_bus[0];
i2c_bus2 = &dev->i2c_bus[1];
fe0->dvb.frontend = dvb_attach(mb86a20s_attach,
&mygica_x8507_mb86a20s_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
dvb_attach(xc5000_attach,
fe0->dvb.frontend,
&i2c_bus2->i2c_adap,
&mygica_x8507_xc5000_config);
}
cx23885_set_frontend_hook(port, fe0->dvb.frontend);
break;
case CX23885_BOARD_MAGICPRO_PROHDTVE2:
i2c_bus = &dev->i2c_bus[0];
i2c_bus2 = &dev->i2c_bus[1];
fe0->dvb.frontend = dvb_attach(lgs8gxx_attach,
&magicpro_prohdtve2_lgs8g75_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
dvb_attach(xc5000_attach,
fe0->dvb.frontend,
&i2c_bus2->i2c_adap,
&magicpro_prohdtve2_xc5000_config);
}
cx23885_set_frontend_hook(port, fe0->dvb.frontend);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1850:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(s5h1411_attach,
&hcw_s5h1411_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL)
dvb_attach(tda18271_attach, fe0->dvb.frontend,
0x60, &dev->i2c_bus[0].i2c_adap,
&hauppauge_tda18271_config);
tda18271_attach(&dev->ts1.analog_fe,
0x60, &dev->i2c_bus[1].i2c_adap,
&hauppauge_tda18271_config);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1290:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(s5h1411_attach,
&hcw_s5h1411_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL)
dvb_attach(tda18271_attach, fe0->dvb.frontend,
0x60, &dev->i2c_bus[0].i2c_adap,
&hauppauge_tda18271_config);
break;
case CX23885_BOARD_MYGICA_X8558PRO:
switch (port->nr) {
case 1:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(atbm8830_attach,
&mygica_x8558pro_atbm8830_cfg1,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
dvb_attach(max2165_attach,
fe0->dvb.frontend,
&i2c_bus->i2c_adap,
&mygic_x8558pro_max2165_cfg1);
}
break;
case 2:
i2c_bus = &dev->i2c_bus[1];
fe0->dvb.frontend = dvb_attach(atbm8830_attach,
&mygica_x8558pro_atbm8830_cfg2,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
dvb_attach(max2165_attach,
fe0->dvb.frontend,
&i2c_bus->i2c_adap,
&mygic_x8558pro_max2165_cfg2);
}
break;
}
break;
case CX23885_BOARD_NETUP_DUAL_DVB_T_C_CI_RF:
i2c_bus = &dev->i2c_bus[0];
mfe_shared = 1;
port->frontends.gate = 0;
fe0->dvb.frontend = dvb_attach(stv0367ter_attach,
&netup_stv0367_config[port->nr - 1],
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (NULL == dvb_attach(xc5000_attach,
fe0->dvb.frontend,
&i2c_bus->i2c_adap,
&netup_xc5000_config[port->nr - 1]))
goto frontend_detach;
fe0->dvb.frontend->ops.tuner_ops.init(fe0->dvb.frontend);
}
fe1 = videobuf_dvb_get_frontend(&port->frontends, 2);
if (fe1 == NULL)
goto frontend_detach;
fe1->dvb.frontend = dvb_attach(stv0367cab_attach,
&netup_stv0367_config[port->nr - 1],
&i2c_bus->i2c_adap);
if (fe1->dvb.frontend != NULL) {
fe1->dvb.frontend->id = 1;
if (NULL == dvb_attach(xc5000_attach,
fe1->dvb.frontend,
&i2c_bus->i2c_adap,
&netup_xc5000_config[port->nr - 1]))
goto frontend_detach;
}
break;
case CX23885_BOARD_TERRATEC_CINERGY_T_PCIE_DUAL:
i2c_bus = &dev->i2c_bus[0];
i2c_bus2 = &dev->i2c_bus[1];
switch (port->nr) {
case 1:
fe0->dvb.frontend = dvb_attach(drxk_attach,
&terratec_drxk_config[0],
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(mt2063_attach,
fe0->dvb.frontend,
&terratec_mt2063_config[0],
&i2c_bus2->i2c_adap))
goto frontend_detach;
}
break;
case 2:
fe0->dvb.frontend = dvb_attach(drxk_attach,
&terratec_drxk_config[1],
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(mt2063_attach,
fe0->dvb.frontend,
&terratec_mt2063_config[1],
&i2c_bus2->i2c_adap))
goto frontend_detach;
}
break;
}
break;
case CX23885_BOARD_TEVII_S471:
i2c_bus = &dev->i2c_bus[1];
fe0->dvb.frontend = dvb_attach(ds3000_attach,
&tevii_ds3000_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
dvb_attach(ts2020_attach, fe0->dvb.frontend,
&tevii_ts2020_config, &i2c_bus->i2c_adap);
}
break;
case CX23885_BOARD_PROF_8000:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(stv090x_attach,
&prof_8000_stv090x_config,
&i2c_bus->i2c_adap,
STV090x_DEMODULATOR_0);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(stb6100_attach,
fe0->dvb.frontend,
&prof_8000_stb6100_config,
&i2c_bus->i2c_adap))
goto frontend_detach;
fe0->dvb.frontend->ops.set_voltage = p8000_set_voltage;
}
break;
case CX23885_BOARD_HAUPPAUGE_HVR4400:
i2c_bus = &dev->i2c_bus[0];
i2c_bus2 = &dev->i2c_bus[1];
switch (port->nr) {
case 1:
fe0->dvb.frontend = dvb_attach(tda10071_attach,
&hauppauge_tda10071_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(a8293_attach, fe0->dvb.frontend,
&i2c_bus->i2c_adap,
&hauppauge_a8293_config))
goto frontend_detach;
}
break;
case 2:
fe0->dvb.frontend = dvb_attach(si2165_attach,
&hauppauge_hvr4400_si2165_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend != NULL) {
fe0->dvb.frontend->ops.i2c_gate_ctrl = 0;
if (!dvb_attach(tda18271_attach,
fe0->dvb.frontend,
0x60, &i2c_bus2->i2c_adap,
&hauppauge_hvr4400_tuner_config))
goto frontend_detach;
}
break;
}
break;
default:
printk(KERN_INFO "%s: The frontend of your DVB/ATSC card "
" isn't supported yet\n",
dev->name);
break;
}
if ((NULL == fe0->dvb.frontend) || (fe1 && NULL == fe1->dvb.frontend)) {
printk(KERN_ERR "%s: frontend initialization failed\n",
dev->name);
goto frontend_detach;
}
fe0->dvb.frontend->callback = cx23885_tuner_callback;
if (fe1)
fe1->dvb.frontend->callback = cx23885_tuner_callback;
#if 0
fe0->dvb.frontend->ops.ts_bus_ctrl = cx23885_dvb_bus_ctrl;
if (fe1)
fe1->dvb.frontend->ops.ts_bus_ctrl = cx23885_dvb_bus_ctrl;
#endif
call_all(dev, core, s_power, 0);
if (fe0->dvb.frontend->ops.analog_ops.standby)
fe0->dvb.frontend->ops.analog_ops.standby(fe0->dvb.frontend);
ret = videobuf_dvb_register_bus(&port->frontends, THIS_MODULE, port,
&dev->pci->dev, adapter_nr, mfe_shared);
if (ret)
goto frontend_detach;
switch (dev->board) {
case CX23885_BOARD_NETUP_DUAL_DVBS2_CI: {
static struct netup_card_info cinfo;
netup_get_card_info(&dev->i2c_bus[0].i2c_adap, &cinfo);
memcpy(port->frontends.adapter.proposed_mac,
cinfo.port[port->nr - 1].mac, 6);
printk(KERN_INFO "NetUP Dual DVB-S2 CI card port%d MAC=%pM\n",
port->nr, port->frontends.adapter.proposed_mac);
netup_ci_init(port);
break;
}
case CX23885_BOARD_NETUP_DUAL_DVB_T_C_CI_RF: {
struct altera_ci_config netup_ci_cfg = {
.dev = dev,
.adapter = &port->frontends.adapter,
.demux = &fe0->dvb.demux,
.fpga_rw = netup_altera_fpga_rw,
};
altera_ci_init(&netup_ci_cfg, port->nr);
break;
}
case CX23885_BOARD_TEVII_S470: {
u8 eeprom[256];
if (port->nr != 1)
break;
dev->i2c_bus[0].i2c_client.addr = 0xa0 >> 1;
tveeprom_read(&dev->i2c_bus[0].i2c_client, eeprom, sizeof(eeprom));
printk(KERN_INFO "TeVii S470 MAC= %pM\n", eeprom + 0xa0);
memcpy(port->frontends.adapter.proposed_mac, eeprom + 0xa0, 6);
break;
}
}
return ret;
frontend_detach:
port->gate_ctrl = NULL;
videobuf_dvb_dealloc_frontends(&port->frontends);
return -EINVAL;
}
int cx23885_dvb_register(struct cx23885_tsport *port)
{
struct videobuf_dvb_frontend *fe0;
struct cx23885_dev *dev = port->dev;
int err, i;
printk(KERN_INFO "%s() allocating %d frontend(s)\n", __func__,
port->num_frontends);
for (i = 1; i <= port->num_frontends; i++) {
if (videobuf_dvb_alloc_frontend(
&port->frontends, i) == NULL) {
printk(KERN_ERR "%s() failed to alloc\n", __func__);
return -ENOMEM;
}
fe0 = videobuf_dvb_get_frontend(&port->frontends, i);
if (!fe0)
err = -EINVAL;
dprintk(1, "%s\n", __func__);
dprintk(1, " ->probed by Card=%d Name=%s, PCI %02x:%02x\n",
dev->board,
dev->name,
dev->pci_bus,
dev->pci_slot);
err = -ENODEV;
printk(KERN_INFO "%s: cx23885 based dvb card\n", dev->name);
videobuf_queue_sg_init(&fe0->dvb.dvbq, &dvb_qops,
&dev->pci->dev, &port->slock,
V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_TOP,
sizeof(struct cx23885_buffer), port, NULL);
}
err = dvb_register(port);
if (err != 0)
printk(KERN_ERR "%s() dvb_register failed err = %d\n",
__func__, err);
return err;
}
int cx23885_dvb_unregister(struct cx23885_tsport *port)
{
struct videobuf_dvb_frontend *fe0;
fe0 = videobuf_dvb_get_frontend(&port->frontends, 1);
if (fe0 && fe0->dvb.frontend)
videobuf_dvb_unregister_bus(&port->frontends);
switch (port->dev->board) {
case CX23885_BOARD_NETUP_DUAL_DVBS2_CI:
netup_ci_exit(port);
break;
case CX23885_BOARD_NETUP_DUAL_DVB_T_C_CI_RF:
altera_ci_release(port->dev, port->nr);
break;
}
port->gate_ctrl = NULL;
return 0;
}
