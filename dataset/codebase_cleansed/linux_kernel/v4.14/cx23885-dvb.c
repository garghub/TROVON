static int queue_setup(struct vb2_queue *q,
unsigned int *num_buffers, unsigned int *num_planes,
unsigned int sizes[], struct device *alloc_devs[])
{
struct cx23885_tsport *port = q->drv_priv;
port->ts_packet_size = 188 * 4;
port->ts_packet_count = 32;
*num_planes = 1;
sizes[0] = port->ts_packet_size * port->ts_packet_count;
*num_buffers = 32;
return 0;
}
static int buffer_prepare(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct cx23885_tsport *port = vb->vb2_queue->drv_priv;
struct cx23885_buffer *buf =
container_of(vbuf, struct cx23885_buffer, vb);
return cx23885_buf_prepare(buf, port);
}
static void buffer_finish(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct cx23885_tsport *port = vb->vb2_queue->drv_priv;
struct cx23885_dev *dev = port->dev;
struct cx23885_buffer *buf = container_of(vbuf,
struct cx23885_buffer, vb);
cx23885_free_buffer(dev, buf);
}
static void buffer_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct cx23885_tsport *port = vb->vb2_queue->drv_priv;
struct cx23885_buffer *buf = container_of(vbuf,
struct cx23885_buffer, vb);
cx23885_buf_queue(port, buf);
}
static void cx23885_dvb_gate_ctrl(struct cx23885_tsport *port, int open)
{
struct vb2_dvb_frontends *f;
struct vb2_dvb_frontend *fe;
f = &port->frontends;
if (f->gate <= 1)
fe = vb2_dvb_get_frontend(f, 1);
else
fe = vb2_dvb_get_frontend(f, f->gate);
if (fe && fe->dvb.frontend && fe->dvb.frontend->ops.i2c_gate_ctrl)
fe->dvb.frontend->ops.i2c_gate_ctrl(fe->dvb.frontend, open);
}
static int cx23885_start_streaming(struct vb2_queue *q, unsigned int count)
{
struct cx23885_tsport *port = q->drv_priv;
struct cx23885_dmaqueue *dmaq = &port->mpegq;
struct cx23885_buffer *buf = list_entry(dmaq->active.next,
struct cx23885_buffer, queue);
cx23885_start_dma(port, dmaq, buf);
return 0;
}
static void cx23885_stop_streaming(struct vb2_queue *q)
{
struct cx23885_tsport *port = q->drv_priv;
cx23885_cancel_buffers(port);
}
static int p8000_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage voltage)
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
static int dvbsky_t9580_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage voltage)
{
struct cx23885_tsport *port = fe->dvb->priv;
struct cx23885_dev *dev = port->dev;
cx23885_gpio_enable(dev, GPIO_0 | GPIO_1, 1);
switch (voltage) {
case SEC_VOLTAGE_13:
cx23885_gpio_set(dev, GPIO_1);
cx23885_gpio_clear(dev, GPIO_0);
break;
case SEC_VOLTAGE_18:
cx23885_gpio_set(dev, GPIO_1);
cx23885_gpio_set(dev, GPIO_0);
break;
case SEC_VOLTAGE_OFF:
cx23885_gpio_clear(dev, GPIO_1);
cx23885_gpio_clear(dev, GPIO_0);
break;
}
port->fe_set_voltage(fe, voltage);
return 0;
}
static int dvbsky_s952_portc_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage voltage)
{
struct cx23885_tsport *port = fe->dvb->priv;
struct cx23885_dev *dev = port->dev;
cx23885_gpio_enable(dev, GPIO_12 | GPIO_13, 1);
switch (voltage) {
case SEC_VOLTAGE_13:
cx23885_gpio_set(dev, GPIO_13);
cx23885_gpio_clear(dev, GPIO_12);
break;
case SEC_VOLTAGE_18:
cx23885_gpio_set(dev, GPIO_13);
cx23885_gpio_set(dev, GPIO_12);
break;
case SEC_VOLTAGE_OFF:
cx23885_gpio_clear(dev, GPIO_13);
cx23885_gpio_clear(dev, GPIO_12);
break;
}
return port->fe_set_voltage(fe, voltage);
}
static int cx23885_sp2_ci_ctrl(void *priv, u8 read, int addr,
u8 data, int *mem)
{
#define SP2_DATA 0x000000ff
#define SP2_WR 0x00008000
#define SP2_RD 0x00004000
#define SP2_ACK 0x00001000
#define SP2_ADHI 0x00000800
#define SP2_ADLO 0x00000400
#define SP2_CS1 0x00000200
#define SP2_CS0 0x00000100
#define SP2_EN_ALL 0x00001000
#define SP2_CTRL_OFF (SP2_CS1 | SP2_CS0 | SP2_WR | SP2_RD)
struct cx23885_tsport *port = priv;
struct cx23885_dev *dev = port->dev;
int ret;
int tmp = 0;
unsigned long timeout;
mutex_lock(&dev->gpio_lock);
cx_write(MC417_OEN, SP2_EN_ALL);
cx_write(MC417_RWD, SP2_CTRL_OFF |
SP2_ADLO | (0xff & addr));
cx_clear(MC417_RWD, SP2_ADLO);
cx_write(MC417_RWD, SP2_CTRL_OFF |
SP2_ADHI | (0xff & (addr >> 8)));
cx_clear(MC417_RWD, SP2_ADHI);
if (read)
cx_write(MC417_OEN, SP2_EN_ALL | SP2_DATA);
else
cx_write(MC417_RWD, SP2_CTRL_OFF | data);
cx_clear(MC417_RWD, SP2_CS0);
cx_clear(MC417_RWD, (read) ? SP2_RD : SP2_WR);
timeout = jiffies + msecs_to_jiffies(1);
while (!time_after(jiffies, timeout)) {
tmp = cx_read(MC417_RWD);
if ((tmp & SP2_ACK) == 0)
break;
usleep_range(50, 100);
}
cx_set(MC417_RWD, SP2_CTRL_OFF);
*mem = tmp & 0xff;
mutex_unlock(&dev->gpio_lock);
if (!read) {
if (*mem < 0) {
ret = -EREMOTEIO;
goto err;
}
}
return 0;
err:
return ret;
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
static int dvb_register_ci_mac(struct cx23885_tsport *port)
{
struct cx23885_dev *dev = port->dev;
struct i2c_client *client_ci = NULL;
struct vb2_dvb_frontend *fe0;
fe0 = vb2_dvb_get_frontend(&port->frontends, 1);
if (!fe0)
return -EINVAL;
switch (dev->board) {
case CX23885_BOARD_NETUP_DUAL_DVBS2_CI: {
static struct netup_card_info cinfo;
netup_get_card_info(&dev->i2c_bus[0].i2c_adap, &cinfo);
memcpy(port->frontends.adapter.proposed_mac,
cinfo.port[port->nr - 1].mac, 6);
pr_info("NetUP Dual DVB-S2 CI card port%d MAC=%pM\n",
port->nr, port->frontends.adapter.proposed_mac);
netup_ci_init(port);
return 0;
}
case CX23885_BOARD_NETUP_DUAL_DVB_T_C_CI_RF: {
struct altera_ci_config netup_ci_cfg = {
.dev = dev,
.adapter = &port->frontends.adapter,
.demux = &fe0->dvb.demux,
.fpga_rw = netup_altera_fpga_rw,
};
altera_ci_init(&netup_ci_cfg, port->nr);
return 0;
}
case CX23885_BOARD_TEVII_S470: {
u8 eeprom[256];
if (port->nr != 1)
return 0;
dev->i2c_bus[0].i2c_client.addr = 0xa0 >> 1;
tveeprom_read(&dev->i2c_bus[0].i2c_client, eeprom, sizeof(eeprom));
pr_info("TeVii S470 MAC= %pM\n", eeprom + 0xa0);
memcpy(port->frontends.adapter.proposed_mac, eeprom + 0xa0, 6);
return 0;
}
case CX23885_BOARD_DVBSKY_T9580:
case CX23885_BOARD_DVBSKY_S950:
case CX23885_BOARD_DVBSKY_S952:
case CX23885_BOARD_DVBSKY_T982: {
u8 eeprom[256];
if (port->nr > 2)
return 0;
dev->i2c_bus[0].i2c_client.addr = 0xa0 >> 1;
tveeprom_read(&dev->i2c_bus[0].i2c_client, eeprom,
sizeof(eeprom));
pr_info("%s port %d MAC address: %pM\n",
cx23885_boards[dev->board].name, port->nr,
eeprom + 0xc0 + (port->nr-1) * 8);
memcpy(port->frontends.adapter.proposed_mac, eeprom + 0xc0 +
(port->nr-1) * 8, 6);
return 0;
}
case CX23885_BOARD_DVBSKY_S950C:
case CX23885_BOARD_DVBSKY_T980C:
case CX23885_BOARD_TT_CT2_4500_CI: {
u8 eeprom[256];
struct sp2_config sp2_config;
struct i2c_board_info info;
struct cx23885_i2c *i2c_bus = &dev->i2c_bus[0];
memset(&sp2_config, 0, sizeof(sp2_config));
sp2_config.dvb_adap = &port->frontends.adapter;
sp2_config.priv = port;
sp2_config.ci_control = cx23885_sp2_ci_ctrl;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "sp2", I2C_NAME_SIZE);
info.addr = 0x40;
info.platform_data = &sp2_config;
request_module(info.type);
client_ci = i2c_new_device(&i2c_bus->i2c_adap, &info);
if (client_ci == NULL || client_ci->dev.driver == NULL)
return -ENODEV;
if (!try_module_get(client_ci->dev.driver->owner)) {
i2c_unregister_device(client_ci);
return -ENODEV;
}
port->i2c_client_ci = client_ci;
if (port->nr != 1)
return 0;
dev->i2c_bus[0].i2c_client.addr = 0xa0 >> 1;
tveeprom_read(&dev->i2c_bus[0].i2c_client, eeprom,
sizeof(eeprom));
pr_info("%s MAC address: %pM\n",
cx23885_boards[dev->board].name, eeprom + 0xc0);
memcpy(port->frontends.adapter.proposed_mac, eeprom + 0xc0, 6);
return 0;
}
}
return 0;
}
static int dvb_register(struct cx23885_tsport *port)
{
struct dib7000p_ops dib7000p_ops;
struct cx23885_dev *dev = port->dev;
struct cx23885_i2c *i2c_bus = NULL, *i2c_bus2 = NULL;
struct vb2_dvb_frontend *fe0, *fe1 = NULL;
struct si2168_config si2168_config;
struct si2165_platform_data si2165_pdata;
struct si2157_config si2157_config;
struct ts2020_config ts2020_config;
struct m88ds3103_platform_data m88ds3103_pdata;
struct i2c_board_info info;
struct i2c_adapter *adapter;
struct i2c_client *client_demod = NULL, *client_tuner = NULL;
struct i2c_client *client_sec = NULL;
int (*p_set_voltage)(struct dvb_frontend *fe,
enum fe_sec_voltage voltage) = NULL;
int mfe_shared = 0;
int ret;
fe0 = vb2_dvb_get_frontend(&port->frontends, 1);
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
if (fe0->dvb.frontend == NULL)
break;
dvb_attach(mt2131_attach, fe0->dvb.frontend,
&i2c_bus->i2c_adap,
&hauppauge_generic_tunerconfig, 0);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1270:
case CX23885_BOARD_HAUPPAUGE_HVR1275:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(lgdt3305_attach,
&hauppauge_lgdt3305_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend == NULL)
break;
dvb_attach(tda18271_attach, fe0->dvb.frontend,
0x60, &dev->i2c_bus[1].i2c_adap,
&hauppauge_hvr127x_config);
if (dev->board == CX23885_BOARD_HAUPPAUGE_HVR1275)
cx23885_set_frontend_hook(port, fe0->dvb.frontend);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1255:
case CX23885_BOARD_HAUPPAUGE_HVR1255_22111:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(s5h1411_attach,
&hcw_s5h1411_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend == NULL)
break;
dvb_attach(tda18271_attach, fe0->dvb.frontend,
0x60, &dev->i2c_bus[1].i2c_adap,
&hauppauge_tda18271_config);
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
if (fe0->dvb.frontend == NULL)
break;
dvb_attach(tda829x_attach, fe0->dvb.frontend,
&dev->i2c_bus[1].i2c_adap, 0x42,
&tda829x_no_probe);
dvb_attach(tda18271_attach, fe0->dvb.frontend,
0x60, &dev->i2c_bus[1].i2c_adap,
&hauppauge_tda18271_config);
break;
case 0:
default:
fe0->dvb.frontend =
dvb_attach(s5h1409_attach,
&hauppauge_generic_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend == NULL)
break;
dvb_attach(mt2131_attach, fe0->dvb.frontend,
&i2c_bus->i2c_adap,
&hauppauge_generic_tunerconfig, 0);
}
break;
case CX23885_BOARD_HAUPPAUGE_HVR1800lp:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(s5h1409_attach,
&hauppauge_hvr1800lp_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend == NULL)
break;
dvb_attach(mt2131_attach, fe0->dvb.frontend,
&i2c_bus->i2c_adap,
&hauppauge_generic_tunerconfig, 0);
break;
case CX23885_BOARD_DVICO_FUSIONHDTV_5_EXP:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(lgdt330x_attach,
&fusionhdtv_5_express,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend == NULL)
break;
dvb_attach(simple_tuner_attach, fe0->dvb.frontend,
&i2c_bus->i2c_adap, 0x61,
TUNER_LG_TDVS_H06XF);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1500Q:
i2c_bus = &dev->i2c_bus[1];
fe0->dvb.frontend = dvb_attach(s5h1409_attach,
&hauppauge_hvr1500q_config,
&dev->i2c_bus[0].i2c_adap);
if (fe0->dvb.frontend == NULL)
break;
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
if (fe0->dvb.frontend == NULL)
break;
dvb_attach(tda829x_attach, fe0->dvb.frontend,
&dev->i2c_bus[1].i2c_adap, 0x42,
&tda829x_no_probe);
dvb_attach(tda18271_attach, fe0->dvb.frontend,
0x60, &dev->i2c_bus[1].i2c_adap,
&hauppauge_hvr1200_tuner_config);
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
pr_warn("Unable to enumerate dib7000p\n");
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
pr_err("%s/2: xc4000 attach failed\n",
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
pr_err("No LNBH24 found!\n");
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
pr_err("No LNBH24 found!\n");
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
if (fe0->dvb.frontend == NULL)
break;
dvb_attach(xc5000_attach, fe0->dvb.frontend,
&i2c_bus2->i2c_adap, &mygica_x8506_xc5000_config);
cx23885_set_frontend_hook(port, fe0->dvb.frontend);
break;
case CX23885_BOARD_MYGICA_X8507:
i2c_bus = &dev->i2c_bus[0];
i2c_bus2 = &dev->i2c_bus[1];
fe0->dvb.frontend = dvb_attach(mb86a20s_attach,
&mygica_x8507_mb86a20s_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend == NULL)
break;
dvb_attach(xc5000_attach, fe0->dvb.frontend,
&i2c_bus2->i2c_adap,
&mygica_x8507_xc5000_config);
cx23885_set_frontend_hook(port, fe0->dvb.frontend);
break;
case CX23885_BOARD_MAGICPRO_PROHDTVE2:
i2c_bus = &dev->i2c_bus[0];
i2c_bus2 = &dev->i2c_bus[1];
fe0->dvb.frontend = dvb_attach(lgs8gxx_attach,
&magicpro_prohdtve2_lgs8g75_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend == NULL)
break;
dvb_attach(xc5000_attach, fe0->dvb.frontend,
&i2c_bus2->i2c_adap,
&magicpro_prohdtve2_xc5000_config);
cx23885_set_frontend_hook(port, fe0->dvb.frontend);
break;
case CX23885_BOARD_HAUPPAUGE_HVR1850:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(s5h1411_attach,
&hcw_s5h1411_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend == NULL)
break;
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
if (fe0->dvb.frontend == NULL)
break;
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
if (fe0->dvb.frontend == NULL)
break;
dvb_attach(max2165_attach, fe0->dvb.frontend,
&i2c_bus->i2c_adap,
&mygic_x8558pro_max2165_cfg1);
break;
case 2:
i2c_bus = &dev->i2c_bus[1];
fe0->dvb.frontend = dvb_attach(atbm8830_attach,
&mygica_x8558pro_atbm8830_cfg2,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend == NULL)
break;
dvb_attach(max2165_attach, fe0->dvb.frontend,
&i2c_bus->i2c_adap,
&mygic_x8558pro_max2165_cfg2);
}
break;
case CX23885_BOARD_NETUP_DUAL_DVB_T_C_CI_RF:
if (port->nr > 2)
return 0;
i2c_bus = &dev->i2c_bus[0];
mfe_shared = 1;
port->frontends.gate = 0;
fe0->dvb.frontend = dvb_attach(stv0367ter_attach,
&netup_stv0367_config[port->nr - 1],
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend == NULL)
break;
if (NULL == dvb_attach(xc5000_attach, fe0->dvb.frontend,
&i2c_bus->i2c_adap,
&netup_xc5000_config[port->nr - 1]))
goto frontend_detach;
fe0->dvb.frontend->ops.tuner_ops.init(fe0->dvb.frontend);
fe1 = vb2_dvb_get_frontend(&port->frontends, 2);
if (fe1 == NULL)
goto frontend_detach;
fe1->dvb.frontend = dvb_attach(stv0367cab_attach,
&netup_stv0367_config[port->nr - 1],
&i2c_bus->i2c_adap);
if (fe1->dvb.frontend == NULL)
break;
fe1->dvb.frontend->id = 1;
if (NULL == dvb_attach(xc5000_attach,
fe1->dvb.frontend,
&i2c_bus->i2c_adap,
&netup_xc5000_config[port->nr - 1]))
goto frontend_detach;
break;
case CX23885_BOARD_TERRATEC_CINERGY_T_PCIE_DUAL:
i2c_bus = &dev->i2c_bus[0];
i2c_bus2 = &dev->i2c_bus[1];
switch (port->nr) {
case 1:
fe0->dvb.frontend = dvb_attach(drxk_attach,
&terratec_drxk_config[0],
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend == NULL)
break;
if (!dvb_attach(mt2063_attach,
fe0->dvb.frontend,
&terratec_mt2063_config[0],
&i2c_bus2->i2c_adap))
goto frontend_detach;
break;
case 2:
fe0->dvb.frontend = dvb_attach(drxk_attach,
&terratec_drxk_config[1],
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend == NULL)
break;
if (!dvb_attach(mt2063_attach,
fe0->dvb.frontend,
&terratec_mt2063_config[1],
&i2c_bus2->i2c_adap))
goto frontend_detach;
break;
}
break;
case CX23885_BOARD_TEVII_S471:
i2c_bus = &dev->i2c_bus[1];
fe0->dvb.frontend = dvb_attach(ds3000_attach,
&tevii_ds3000_config,
&i2c_bus->i2c_adap);
if (fe0->dvb.frontend == NULL)
break;
dvb_attach(ts2020_attach, fe0->dvb.frontend,
&tevii_ts2020_config, &i2c_bus->i2c_adap);
break;
case CX23885_BOARD_PROF_8000:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(stv090x_attach,
&prof_8000_stv090x_config,
&i2c_bus->i2c_adap,
STV090x_DEMODULATOR_0);
if (fe0->dvb.frontend == NULL)
break;
if (!dvb_attach(stb6100_attach,
fe0->dvb.frontend,
&prof_8000_stb6100_config,
&i2c_bus->i2c_adap))
goto frontend_detach;
fe0->dvb.frontend->ops.set_voltage = p8000_set_voltage;
break;
case CX23885_BOARD_HAUPPAUGE_HVR4400: {
struct tda10071_platform_data tda10071_pdata = hauppauge_tda10071_pdata;
struct a8293_platform_data a8293_pdata = {};
i2c_bus = &dev->i2c_bus[0];
i2c_bus2 = &dev->i2c_bus[1];
switch (port->nr) {
case 1:
memset(&info, 0, sizeof(info));
strlcpy(info.type, "tda10071_cx24118", I2C_NAME_SIZE);
info.addr = 0x05;
info.platform_data = &tda10071_pdata;
request_module("tda10071");
client_demod = i2c_new_device(&i2c_bus->i2c_adap, &info);
if (!client_demod || !client_demod->dev.driver)
goto frontend_detach;
if (!try_module_get(client_demod->dev.driver->owner)) {
i2c_unregister_device(client_demod);
goto frontend_detach;
}
fe0->dvb.frontend = tda10071_pdata.get_dvb_frontend(client_demod);
port->i2c_client_demod = client_demod;
a8293_pdata.dvb_frontend = fe0->dvb.frontend;
memset(&info, 0, sizeof(info));
strlcpy(info.type, "a8293", I2C_NAME_SIZE);
info.addr = 0x0b;
info.platform_data = &a8293_pdata;
request_module("a8293");
client_sec = i2c_new_device(&i2c_bus->i2c_adap, &info);
if (!client_sec || !client_sec->dev.driver)
goto frontend_detach;
if (!try_module_get(client_sec->dev.driver->owner)) {
i2c_unregister_device(client_sec);
goto frontend_detach;
}
port->i2c_client_sec = client_sec;
break;
case 2:
memset(&si2165_pdata, 0, sizeof(si2165_pdata));
si2165_pdata.fe = &fe0->dvb.frontend;
si2165_pdata.chip_mode = SI2165_MODE_PLL_XTAL,
si2165_pdata.ref_freq_Hz = 16000000,
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2165", I2C_NAME_SIZE);
info.addr = 0x64;
info.platform_data = &si2165_pdata;
request_module(info.type);
client_demod = i2c_new_device(&i2c_bus->i2c_adap, &info);
if (client_demod == NULL ||
client_demod->dev.driver == NULL)
goto frontend_detach;
if (!try_module_get(client_demod->dev.driver->owner)) {
i2c_unregister_device(client_demod);
goto frontend_detach;
}
port->i2c_client_demod = client_demod;
if (fe0->dvb.frontend == NULL)
break;
fe0->dvb.frontend->ops.i2c_gate_ctrl = NULL;
if (!dvb_attach(tda18271_attach,
fe0->dvb.frontend,
0x60, &i2c_bus2->i2c_adap,
&hauppauge_hvr4400_tuner_config))
goto frontend_detach;
break;
}
break;
}
case CX23885_BOARD_HAUPPAUGE_STARBURST: {
struct tda10071_platform_data tda10071_pdata = hauppauge_tda10071_pdata;
struct a8293_platform_data a8293_pdata = {};
i2c_bus = &dev->i2c_bus[0];
memset(&info, 0, sizeof(info));
strlcpy(info.type, "tda10071_cx24118", I2C_NAME_SIZE);
info.addr = 0x05;
info.platform_data = &tda10071_pdata;
request_module("tda10071");
client_demod = i2c_new_device(&i2c_bus->i2c_adap, &info);
if (!client_demod || !client_demod->dev.driver)
goto frontend_detach;
if (!try_module_get(client_demod->dev.driver->owner)) {
i2c_unregister_device(client_demod);
goto frontend_detach;
}
fe0->dvb.frontend = tda10071_pdata.get_dvb_frontend(client_demod);
port->i2c_client_demod = client_demod;
a8293_pdata.dvb_frontend = fe0->dvb.frontend;
memset(&info, 0, sizeof(info));
strlcpy(info.type, "a8293", I2C_NAME_SIZE);
info.addr = 0x0b;
info.platform_data = &a8293_pdata;
request_module("a8293");
client_sec = i2c_new_device(&i2c_bus->i2c_adap, &info);
if (!client_sec || !client_sec->dev.driver)
goto frontend_detach;
if (!try_module_get(client_sec->dev.driver->owner)) {
i2c_unregister_device(client_sec);
goto frontend_detach;
}
port->i2c_client_sec = client_sec;
break;
}
case CX23885_BOARD_DVBSKY_T9580:
case CX23885_BOARD_DVBSKY_S950:
i2c_bus = &dev->i2c_bus[0];
i2c_bus2 = &dev->i2c_bus[1];
switch (port->nr) {
case 1:
fe0->dvb.frontend = dvb_attach(m88ds3103_attach,
&dvbsky_t9580_m88ds3103_config,
&i2c_bus2->i2c_adap, &adapter);
if (fe0->dvb.frontend == NULL)
break;
memset(&ts2020_config, 0, sizeof(ts2020_config));
ts2020_config.fe = fe0->dvb.frontend;
ts2020_config.get_agc_pwm = m88ds3103_get_agc_pwm;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "ts2020", I2C_NAME_SIZE);
info.addr = 0x60;
info.platform_data = &ts2020_config;
request_module(info.type);
client_tuner = i2c_new_device(adapter, &info);
if (client_tuner == NULL ||
client_tuner->dev.driver == NULL)
goto frontend_detach;
if (!try_module_get(client_tuner->dev.driver->owner)) {
i2c_unregister_device(client_tuner);
goto frontend_detach;
}
fe0->dvb.frontend->ops.read_signal_strength =
fe0->dvb.frontend->ops.tuner_ops.get_rf_strength;
port->fe_set_voltage =
fe0->dvb.frontend->ops.set_voltage;
fe0->dvb.frontend->ops.set_voltage =
dvbsky_t9580_set_voltage;
port->i2c_client_tuner = client_tuner;
break;
case 2:
memset(&si2168_config, 0, sizeof(si2168_config));
si2168_config.i2c_adapter = &adapter;
si2168_config.fe = &fe0->dvb.frontend;
si2168_config.ts_mode = SI2168_TS_SERIAL;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2168", I2C_NAME_SIZE);
info.addr = 0x64;
info.platform_data = &si2168_config;
request_module(info.type);
client_demod = i2c_new_device(&i2c_bus->i2c_adap, &info);
if (client_demod == NULL ||
client_demod->dev.driver == NULL)
goto frontend_detach;
if (!try_module_get(client_demod->dev.driver->owner)) {
i2c_unregister_device(client_demod);
goto frontend_detach;
}
port->i2c_client_demod = client_demod;
memset(&si2157_config, 0, sizeof(si2157_config));
si2157_config.fe = fe0->dvb.frontend;
si2157_config.if_port = 1;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2157", I2C_NAME_SIZE);
info.addr = 0x60;
info.platform_data = &si2157_config;
request_module(info.type);
client_tuner = i2c_new_device(adapter, &info);
if (client_tuner == NULL ||
client_tuner->dev.driver == NULL)
goto frontend_detach;
if (!try_module_get(client_tuner->dev.driver->owner)) {
i2c_unregister_device(client_tuner);
goto frontend_detach;
}
port->i2c_client_tuner = client_tuner;
break;
}
break;
case CX23885_BOARD_DVBSKY_T980C:
case CX23885_BOARD_TT_CT2_4500_CI:
i2c_bus = &dev->i2c_bus[0];
i2c_bus2 = &dev->i2c_bus[1];
memset(&si2168_config, 0, sizeof(si2168_config));
si2168_config.i2c_adapter = &adapter;
si2168_config.fe = &fe0->dvb.frontend;
si2168_config.ts_mode = SI2168_TS_PARALLEL;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2168", I2C_NAME_SIZE);
info.addr = 0x64;
info.platform_data = &si2168_config;
request_module(info.type);
client_demod = i2c_new_device(&i2c_bus2->i2c_adap, &info);
if (client_demod == NULL || client_demod->dev.driver == NULL)
goto frontend_detach;
if (!try_module_get(client_demod->dev.driver->owner)) {
i2c_unregister_device(client_demod);
goto frontend_detach;
}
port->i2c_client_demod = client_demod;
memset(&si2157_config, 0, sizeof(si2157_config));
si2157_config.fe = fe0->dvb.frontend;
si2157_config.if_port = 1;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2157", I2C_NAME_SIZE);
info.addr = 0x60;
info.platform_data = &si2157_config;
request_module(info.type);
client_tuner = i2c_new_device(adapter, &info);
if (client_tuner == NULL ||
client_tuner->dev.driver == NULL)
goto frontend_detach;
if (!try_module_get(client_tuner->dev.driver->owner)) {
i2c_unregister_device(client_tuner);
goto frontend_detach;
}
port->i2c_client_tuner = client_tuner;
break;
case CX23885_BOARD_DVBSKY_S950C:
i2c_bus = &dev->i2c_bus[0];
i2c_bus2 = &dev->i2c_bus[1];
fe0->dvb.frontend = dvb_attach(m88ds3103_attach,
&dvbsky_s950c_m88ds3103_config,
&i2c_bus2->i2c_adap, &adapter);
if (fe0->dvb.frontend == NULL)
break;
memset(&ts2020_config, 0, sizeof(ts2020_config));
ts2020_config.fe = fe0->dvb.frontend;
ts2020_config.get_agc_pwm = m88ds3103_get_agc_pwm;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "ts2020", I2C_NAME_SIZE);
info.addr = 0x60;
info.platform_data = &ts2020_config;
request_module(info.type);
client_tuner = i2c_new_device(adapter, &info);
if (client_tuner == NULL || client_tuner->dev.driver == NULL)
goto frontend_detach;
if (!try_module_get(client_tuner->dev.driver->owner)) {
i2c_unregister_device(client_tuner);
goto frontend_detach;
}
fe0->dvb.frontend->ops.read_signal_strength =
fe0->dvb.frontend->ops.tuner_ops.get_rf_strength;
port->i2c_client_tuner = client_tuner;
break;
case CX23885_BOARD_DVBSKY_S952:
memset(&m88ds3103_pdata, 0, sizeof(m88ds3103_pdata));
m88ds3103_pdata.clk = 27000000;
m88ds3103_pdata.i2c_wr_max = 33;
m88ds3103_pdata.agc = 0x99;
m88ds3103_pdata.clk_out = M88DS3103_CLOCK_OUT_DISABLED;
m88ds3103_pdata.lnb_en_pol = 1;
switch (port->nr) {
case 1:
i2c_bus = &dev->i2c_bus[1];
m88ds3103_pdata.ts_mode = M88DS3103_TS_PARALLEL;
m88ds3103_pdata.ts_clk = 16000;
m88ds3103_pdata.ts_clk_pol = 1;
p_set_voltage = dvbsky_t9580_set_voltage;
break;
case 2:
i2c_bus = &dev->i2c_bus[0];
m88ds3103_pdata.ts_mode = M88DS3103_TS_SERIAL;
m88ds3103_pdata.ts_clk = 96000;
m88ds3103_pdata.ts_clk_pol = 0;
p_set_voltage = dvbsky_s952_portc_set_voltage;
break;
default:
return 0;
}
memset(&info, 0, sizeof(info));
strlcpy(info.type, "m88ds3103", I2C_NAME_SIZE);
info.addr = 0x68;
info.platform_data = &m88ds3103_pdata;
request_module(info.type);
client_demod = i2c_new_device(&i2c_bus->i2c_adap, &info);
if (client_demod == NULL || client_demod->dev.driver == NULL)
goto frontend_detach;
if (!try_module_get(client_demod->dev.driver->owner)) {
i2c_unregister_device(client_demod);
goto frontend_detach;
}
port->i2c_client_demod = client_demod;
adapter = m88ds3103_pdata.get_i2c_adapter(client_demod);
fe0->dvb.frontend = m88ds3103_pdata.get_dvb_frontend(client_demod);
memset(&ts2020_config, 0, sizeof(ts2020_config));
ts2020_config.fe = fe0->dvb.frontend;
ts2020_config.get_agc_pwm = m88ds3103_get_agc_pwm;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "ts2020", I2C_NAME_SIZE);
info.addr = 0x60;
info.platform_data = &ts2020_config;
request_module(info.type);
client_tuner = i2c_new_device(adapter, &info);
if (client_tuner == NULL || client_tuner->dev.driver == NULL)
goto frontend_detach;
if (!try_module_get(client_tuner->dev.driver->owner)) {
i2c_unregister_device(client_tuner);
goto frontend_detach;
}
fe0->dvb.frontend->ops.read_signal_strength =
fe0->dvb.frontend->ops.tuner_ops.get_rf_strength;
port->fe_set_voltage =
fe0->dvb.frontend->ops.set_voltage;
fe0->dvb.frontend->ops.set_voltage = p_set_voltage;
port->i2c_client_tuner = client_tuner;
break;
case CX23885_BOARD_DVBSKY_T982:
memset(&si2168_config, 0, sizeof(si2168_config));
switch (port->nr) {
case 1:
i2c_bus = &dev->i2c_bus[1];
si2168_config.ts_mode = SI2168_TS_PARALLEL;
break;
case 2:
i2c_bus = &dev->i2c_bus[0];
si2168_config.ts_mode = SI2168_TS_SERIAL;
break;
}
si2168_config.i2c_adapter = &adapter;
si2168_config.fe = &fe0->dvb.frontend;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2168", I2C_NAME_SIZE);
info.addr = 0x64;
info.platform_data = &si2168_config;
request_module(info.type);
client_demod = i2c_new_device(&i2c_bus->i2c_adap, &info);
if (client_demod == NULL || client_demod->dev.driver == NULL)
goto frontend_detach;
if (!try_module_get(client_demod->dev.driver->owner)) {
i2c_unregister_device(client_demod);
goto frontend_detach;
}
port->i2c_client_demod = client_demod;
memset(&si2157_config, 0, sizeof(si2157_config));
si2157_config.fe = fe0->dvb.frontend;
si2157_config.if_port = 1;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2157", I2C_NAME_SIZE);
info.addr = 0x60;
info.platform_data = &si2157_config;
request_module(info.type);
client_tuner = i2c_new_device(adapter, &info);
if (client_tuner == NULL ||
client_tuner->dev.driver == NULL)
goto frontend_detach;
if (!try_module_get(client_tuner->dev.driver->owner)) {
i2c_unregister_device(client_tuner);
goto frontend_detach;
}
port->i2c_client_tuner = client_tuner;
break;
case CX23885_BOARD_HAUPPAUGE_HVR5525: {
struct m88rs6000t_config m88rs6000t_config;
struct a8293_platform_data a8293_pdata = {};
switch (port->nr) {
case 1:
fe0->dvb.frontend = dvb_attach(m88ds3103_attach,
&hauppauge_hvr5525_m88ds3103_config,
&dev->i2c_bus[0].i2c_adap, &adapter);
if (fe0->dvb.frontend == NULL)
break;
a8293_pdata.dvb_frontend = fe0->dvb.frontend;
memset(&info, 0, sizeof(info));
strlcpy(info.type, "a8293", I2C_NAME_SIZE);
info.addr = 0x0b;
info.platform_data = &a8293_pdata;
request_module("a8293");
client_sec = i2c_new_device(&dev->i2c_bus[0].i2c_adap, &info);
if (!client_sec || !client_sec->dev.driver)
goto frontend_detach;
if (!try_module_get(client_sec->dev.driver->owner)) {
i2c_unregister_device(client_sec);
goto frontend_detach;
}
port->i2c_client_sec = client_sec;
memset(&m88rs6000t_config, 0, sizeof(m88rs6000t_config));
m88rs6000t_config.fe = fe0->dvb.frontend;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "m88rs6000t", I2C_NAME_SIZE);
info.addr = 0x21;
info.platform_data = &m88rs6000t_config;
request_module("%s", info.type);
client_tuner = i2c_new_device(adapter, &info);
if (!client_tuner || !client_tuner->dev.driver)
goto frontend_detach;
if (!try_module_get(client_tuner->dev.driver->owner)) {
i2c_unregister_device(client_tuner);
goto frontend_detach;
}
port->i2c_client_tuner = client_tuner;
fe0->dvb.frontend->ops.read_signal_strength =
fe0->dvb.frontend->ops.tuner_ops.get_rf_strength;
break;
case 2:
memset(&si2168_config, 0, sizeof(si2168_config));
si2168_config.i2c_adapter = &adapter;
si2168_config.fe = &fe0->dvb.frontend;
si2168_config.ts_mode = SI2168_TS_SERIAL;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2168", I2C_NAME_SIZE);
info.addr = 0x64;
info.platform_data = &si2168_config;
request_module("%s", info.type);
client_demod = i2c_new_device(&dev->i2c_bus[0].i2c_adap, &info);
if (!client_demod || !client_demod->dev.driver)
goto frontend_detach;
if (!try_module_get(client_demod->dev.driver->owner)) {
i2c_unregister_device(client_demod);
goto frontend_detach;
}
port->i2c_client_demod = client_demod;
memset(&si2157_config, 0, sizeof(si2157_config));
si2157_config.fe = fe0->dvb.frontend;
si2157_config.if_port = 1;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2157", I2C_NAME_SIZE);
info.addr = 0x60;
info.platform_data = &si2157_config;
request_module("%s", info.type);
client_tuner = i2c_new_device(&dev->i2c_bus[1].i2c_adap, &info);
if (!client_tuner || !client_tuner->dev.driver) {
module_put(client_demod->dev.driver->owner);
i2c_unregister_device(client_demod);
port->i2c_client_demod = NULL;
goto frontend_detach;
}
if (!try_module_get(client_tuner->dev.driver->owner)) {
i2c_unregister_device(client_tuner);
module_put(client_demod->dev.driver->owner);
i2c_unregister_device(client_demod);
port->i2c_client_demod = NULL;
goto frontend_detach;
}
port->i2c_client_tuner = client_tuner;
break;
}
break;
}
case CX23885_BOARD_HAUPPAUGE_QUADHD_DVB:
switch (port->nr) {
case 1:
memset(&si2168_config, 0, sizeof(si2168_config));
si2168_config.i2c_adapter = &adapter;
si2168_config.fe = &fe0->dvb.frontend;
si2168_config.ts_mode = SI2168_TS_SERIAL;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2168", I2C_NAME_SIZE);
info.addr = 0x64;
info.platform_data = &si2168_config;
request_module("%s", info.type);
client_demod = i2c_new_device(&dev->i2c_bus[0].i2c_adap, &info);
if (!client_demod || !client_demod->dev.driver)
goto frontend_detach;
if (!try_module_get(client_demod->dev.driver->owner)) {
i2c_unregister_device(client_demod);
goto frontend_detach;
}
port->i2c_client_demod = client_demod;
memset(&si2157_config, 0, sizeof(si2157_config));
si2157_config.fe = fe0->dvb.frontend;
si2157_config.if_port = 1;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2157", I2C_NAME_SIZE);
info.addr = 0x60;
info.platform_data = &si2157_config;
request_module("%s", info.type);
client_tuner = i2c_new_device(&dev->i2c_bus[1].i2c_adap, &info);
if (!client_tuner || !client_tuner->dev.driver) {
module_put(client_demod->dev.driver->owner);
i2c_unregister_device(client_demod);
port->i2c_client_demod = NULL;
goto frontend_detach;
}
if (!try_module_get(client_tuner->dev.driver->owner)) {
i2c_unregister_device(client_tuner);
module_put(client_demod->dev.driver->owner);
i2c_unregister_device(client_demod);
port->i2c_client_demod = NULL;
goto frontend_detach;
}
port->i2c_client_tuner = client_tuner;
break;
case 2:
memset(&si2168_config, 0, sizeof(si2168_config));
si2168_config.i2c_adapter = &adapter;
si2168_config.fe = &fe0->dvb.frontend;
si2168_config.ts_mode = SI2168_TS_SERIAL;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2168", I2C_NAME_SIZE);
info.addr = 0x66;
info.platform_data = &si2168_config;
request_module("%s", info.type);
client_demod = i2c_new_device(&dev->i2c_bus[0].i2c_adap, &info);
if (!client_demod || !client_demod->dev.driver)
goto frontend_detach;
if (!try_module_get(client_demod->dev.driver->owner)) {
i2c_unregister_device(client_demod);
goto frontend_detach;
}
port->i2c_client_demod = client_demod;
memset(&si2157_config, 0, sizeof(si2157_config));
si2157_config.fe = fe0->dvb.frontend;
si2157_config.if_port = 1;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2157", I2C_NAME_SIZE);
info.addr = 0x62;
info.platform_data = &si2157_config;
request_module("%s", info.type);
client_tuner = i2c_new_device(&dev->i2c_bus[1].i2c_adap, &info);
if (!client_tuner || !client_tuner->dev.driver) {
module_put(client_demod->dev.driver->owner);
i2c_unregister_device(client_demod);
port->i2c_client_demod = NULL;
goto frontend_detach;
}
if (!try_module_get(client_tuner->dev.driver->owner)) {
i2c_unregister_device(client_tuner);
module_put(client_demod->dev.driver->owner);
i2c_unregister_device(client_demod);
port->i2c_client_demod = NULL;
goto frontend_detach;
}
port->i2c_client_tuner = client_tuner;
break;
}
break;
case CX23885_BOARD_HAUPPAUGE_QUADHD_ATSC:
switch (port->nr) {
case 1:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(lgdt3306a_attach,
&hauppauge_quadHD_ATSC_a_config, &i2c_bus->i2c_adap);
if (fe0->dvb.frontend == NULL)
break;
memset(&si2157_config, 0, sizeof(si2157_config));
si2157_config.fe = fe0->dvb.frontend;
si2157_config.if_port = 1;
si2157_config.inversion = 1;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2157", I2C_NAME_SIZE);
info.addr = 0x60;
info.platform_data = &si2157_config;
request_module("%s", info.type);
client_tuner = i2c_new_device(&dev->i2c_bus[1].i2c_adap, &info);
if (!client_tuner || !client_tuner->dev.driver) {
module_put(client_demod->dev.driver->owner);
i2c_unregister_device(client_demod);
port->i2c_client_demod = NULL;
goto frontend_detach;
}
if (!try_module_get(client_tuner->dev.driver->owner)) {
i2c_unregister_device(client_tuner);
module_put(client_demod->dev.driver->owner);
i2c_unregister_device(client_demod);
port->i2c_client_demod = NULL;
goto frontend_detach;
}
port->i2c_client_tuner = client_tuner;
break;
case 2:
i2c_bus = &dev->i2c_bus[0];
fe0->dvb.frontend = dvb_attach(lgdt3306a_attach,
&hauppauge_quadHD_ATSC_b_config, &i2c_bus->i2c_adap);
if (fe0->dvb.frontend == NULL)
break;
memset(&si2157_config, 0, sizeof(si2157_config));
si2157_config.fe = fe0->dvb.frontend;
si2157_config.if_port = 1;
si2157_config.inversion = 1;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2157", I2C_NAME_SIZE);
info.addr = 0x62;
info.platform_data = &si2157_config;
request_module("%s", info.type);
client_tuner = i2c_new_device(&dev->i2c_bus[1].i2c_adap, &info);
if (!client_tuner || !client_tuner->dev.driver) {
module_put(client_demod->dev.driver->owner);
i2c_unregister_device(client_demod);
port->i2c_client_demod = NULL;
goto frontend_detach;
}
if (!try_module_get(client_tuner->dev.driver->owner)) {
i2c_unregister_device(client_tuner);
module_put(client_demod->dev.driver->owner);
i2c_unregister_device(client_demod);
port->i2c_client_demod = NULL;
goto frontend_detach;
}
port->i2c_client_tuner = client_tuner;
break;
}
break;
default:
pr_info("%s: The frontend of your DVB/ATSC card isn't supported yet\n",
dev->name);
break;
}
if ((NULL == fe0->dvb.frontend) || (fe1 && NULL == fe1->dvb.frontend)) {
pr_err("%s: frontend initialization failed\n",
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
ret = vb2_dvb_register_bus(&port->frontends, THIS_MODULE, port,
&dev->pci->dev, NULL,
adapter_nr, mfe_shared);
if (ret)
goto frontend_detach;
ret = dvb_register_ci_mac(port);
if (ret)
goto frontend_detach;
return 0;
frontend_detach:
client_sec = port->i2c_client_sec;
if (client_sec) {
module_put(client_sec->dev.driver->owner);
i2c_unregister_device(client_sec);
port->i2c_client_sec = NULL;
}
client_tuner = port->i2c_client_tuner;
if (client_tuner) {
module_put(client_tuner->dev.driver->owner);
i2c_unregister_device(client_tuner);
port->i2c_client_tuner = NULL;
}
client_demod = port->i2c_client_demod;
if (client_demod) {
module_put(client_demod->dev.driver->owner);
i2c_unregister_device(client_demod);
port->i2c_client_demod = NULL;
}
port->gate_ctrl = NULL;
vb2_dvb_dealloc_frontends(&port->frontends);
return -EINVAL;
}
int cx23885_dvb_register(struct cx23885_tsport *port)
{
struct vb2_dvb_frontend *fe0;
struct cx23885_dev *dev = port->dev;
int err, i;
pr_info("%s() allocating %d frontend(s)\n", __func__,
port->num_frontends);
for (i = 1; i <= port->num_frontends; i++) {
struct vb2_queue *q;
if (vb2_dvb_alloc_frontend(
&port->frontends, i) == NULL) {
pr_err("%s() failed to alloc\n", __func__);
return -ENOMEM;
}
fe0 = vb2_dvb_get_frontend(&port->frontends, i);
if (!fe0)
return -EINVAL;
dprintk(1, "%s\n", __func__);
dprintk(1, " ->probed by Card=%d Name=%s, PCI %02x:%02x\n",
dev->board,
dev->name,
dev->pci_bus,
dev->pci_slot);
err = -ENODEV;
pr_info("%s: cx23885 based dvb card\n", dev->name);
q = &fe0->dvb.dvbq;
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF | VB2_READ;
q->gfp_flags = GFP_DMA32;
q->min_buffers_needed = 2;
q->drv_priv = port;
q->buf_struct_size = sizeof(struct cx23885_buffer);
q->ops = &dvb_qops;
q->mem_ops = &vb2_dma_sg_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->lock = &dev->lock;
q->dev = &dev->pci->dev;
err = vb2_queue_init(q);
if (err < 0)
return err;
}
err = dvb_register(port);
if (err != 0)
pr_err("%s() dvb_register failed err = %d\n",
__func__, err);
return err;
}
int cx23885_dvb_unregister(struct cx23885_tsport *port)
{
struct vb2_dvb_frontend *fe0;
struct i2c_client *client;
fe0 = vb2_dvb_get_frontend(&port->frontends, 1);
if (fe0 && fe0->dvb.frontend)
vb2_dvb_unregister_bus(&port->frontends);
client = port->i2c_client_ci;
if (client) {
module_put(client->dev.driver->owner);
i2c_unregister_device(client);
}
client = port->i2c_client_sec;
if (client) {
module_put(client->dev.driver->owner);
i2c_unregister_device(client);
}
client = port->i2c_client_tuner;
if (client) {
module_put(client->dev.driver->owner);
i2c_unregister_device(client);
}
client = port->i2c_client_demod;
if (client) {
module_put(client->dev.driver->owner);
i2c_unregister_device(client);
}
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
