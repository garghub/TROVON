static int queue_setup(struct vb2_queue *q, const struct v4l2_format *fmt,
unsigned int *num_buffers, unsigned int *num_planes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct cx8802_dev *dev = q->drv_priv;
*num_planes = 1;
dev->ts_packet_size = 188 * 4;
dev->ts_packet_count = dvb_buf_tscnt;
sizes[0] = dev->ts_packet_size * dev->ts_packet_count;
alloc_ctxs[0] = dev->alloc_ctx;
*num_buffers = dvb_buf_tscnt;
return 0;
}
static int buffer_prepare(struct vb2_buffer *vb)
{
struct cx8802_dev *dev = vb->vb2_queue->drv_priv;
struct cx88_buffer *buf = container_of(vb, struct cx88_buffer, vb);
return cx8802_buf_prepare(vb->vb2_queue, dev, buf);
}
static void buffer_finish(struct vb2_buffer *vb)
{
struct cx8802_dev *dev = vb->vb2_queue->drv_priv;
struct cx88_buffer *buf = container_of(vb, struct cx88_buffer, vb);
struct cx88_riscmem *risc = &buf->risc;
if (risc->cpu)
pci_free_consistent(dev->pci, risc->size, risc->cpu, risc->dma);
memset(risc, 0, sizeof(*risc));
}
static void buffer_queue(struct vb2_buffer *vb)
{
struct cx8802_dev *dev = vb->vb2_queue->drv_priv;
struct cx88_buffer *buf = container_of(vb, struct cx88_buffer, vb);
cx8802_buf_queue(dev, buf);
}
static int start_streaming(struct vb2_queue *q, unsigned int count)
{
struct cx8802_dev *dev = q->drv_priv;
struct cx88_dmaqueue *dmaq = &dev->mpegq;
struct cx88_buffer *buf;
buf = list_entry(dmaq->active.next, struct cx88_buffer, list);
cx8802_start_dma(dev, dmaq, buf);
return 0;
}
static void stop_streaming(struct vb2_queue *q)
{
struct cx8802_dev *dev = q->drv_priv;
struct cx88_dmaqueue *dmaq = &dev->mpegq;
unsigned long flags;
cx8802_cancel_buffers(dev);
spin_lock_irqsave(&dev->slock, flags);
while (!list_empty(&dmaq->active)) {
struct cx88_buffer *buf = list_entry(dmaq->active.next,
struct cx88_buffer, list);
list_del(&buf->list);
vb2_buffer_done(&buf->vb, VB2_BUF_STATE_ERROR);
}
spin_unlock_irqrestore(&dev->slock, flags);
}
static int cx88_dvb_bus_ctrl(struct dvb_frontend* fe, int acquire)
{
struct cx8802_dev *dev= fe->dvb->priv;
struct cx8802_driver *drv = NULL;
int ret = 0;
int fe_id;
fe_id = vb2_dvb_find_frontend(&dev->frontends, fe);
if (!fe_id) {
printk(KERN_ERR "%s() No frontend found\n", __func__);
return -EINVAL;
}
mutex_lock(&dev->core->lock);
drv = cx8802_get_driver(dev, CX88_MPEG_DVB);
if (drv) {
if (acquire){
dev->frontends.active_fe_id = fe_id;
ret = drv->request_acquire(drv);
} else {
ret = drv->request_release(drv);
dev->frontends.active_fe_id = 0;
}
}
mutex_unlock(&dev->core->lock);
return ret;
}
static void cx88_dvb_gate_ctrl(struct cx88_core *core, int open)
{
struct vb2_dvb_frontends *f;
struct vb2_dvb_frontend *fe;
if (!core->dvbdev)
return;
f = &core->dvbdev->frontends;
if (!f)
return;
if (f->gate <= 1)
fe = vb2_dvb_get_frontend(f, 1);
else
fe = vb2_dvb_get_frontend(f, f->gate);
if (fe && fe->dvb.frontend && fe->dvb.frontend->ops.i2c_gate_ctrl)
fe->dvb.frontend->ops.i2c_gate_ctrl(fe->dvb.frontend, open);
}
static int dvico_fusionhdtv_demod_init(struct dvb_frontend* fe)
{
static const u8 clock_config [] = { CLOCK_CTL, 0x38, 0x39 };
static const u8 reset [] = { RESET, 0x80 };
static const u8 adc_ctl_1_cfg [] = { ADC_CTL_1, 0x40 };
static const u8 agc_cfg [] = { AGC_TARGET, 0x24, 0x20 };
static const u8 gpp_ctl_cfg [] = { GPP_CTL, 0x33 };
static const u8 capt_range_cfg[] = { CAPT_RANGE, 0x32 };
mt352_write(fe, clock_config, sizeof(clock_config));
udelay(200);
mt352_write(fe, reset, sizeof(reset));
mt352_write(fe, adc_ctl_1_cfg, sizeof(adc_ctl_1_cfg));
mt352_write(fe, agc_cfg, sizeof(agc_cfg));
mt352_write(fe, gpp_ctl_cfg, sizeof(gpp_ctl_cfg));
mt352_write(fe, capt_range_cfg, sizeof(capt_range_cfg));
return 0;
}
static int dvico_dual_demod_init(struct dvb_frontend *fe)
{
static const u8 clock_config [] = { CLOCK_CTL, 0x38, 0x38 };
static const u8 reset [] = { RESET, 0x80 };
static const u8 adc_ctl_1_cfg [] = { ADC_CTL_1, 0x40 };
static const u8 agc_cfg [] = { AGC_TARGET, 0x28, 0x20 };
static const u8 gpp_ctl_cfg [] = { GPP_CTL, 0x33 };
static const u8 capt_range_cfg[] = { CAPT_RANGE, 0x32 };
mt352_write(fe, clock_config, sizeof(clock_config));
udelay(200);
mt352_write(fe, reset, sizeof(reset));
mt352_write(fe, adc_ctl_1_cfg, sizeof(adc_ctl_1_cfg));
mt352_write(fe, agc_cfg, sizeof(agc_cfg));
mt352_write(fe, gpp_ctl_cfg, sizeof(gpp_ctl_cfg));
mt352_write(fe, capt_range_cfg, sizeof(capt_range_cfg));
return 0;
}
static int dntv_live_dvbt_demod_init(struct dvb_frontend* fe)
{
static const u8 clock_config [] = { 0x89, 0x38, 0x39 };
static const u8 reset [] = { 0x50, 0x80 };
static const u8 adc_ctl_1_cfg [] = { 0x8E, 0x40 };
static const u8 agc_cfg [] = { 0x67, 0x10, 0x23, 0x00, 0xFF, 0xFF,
0x00, 0xFF, 0x00, 0x40, 0x40 };
static const u8 dntv_extra[] = { 0xB5, 0x7A };
static const u8 capt_range_cfg[] = { 0x75, 0x32 };
mt352_write(fe, clock_config, sizeof(clock_config));
udelay(2000);
mt352_write(fe, reset, sizeof(reset));
mt352_write(fe, adc_ctl_1_cfg, sizeof(adc_ctl_1_cfg));
mt352_write(fe, agc_cfg, sizeof(agc_cfg));
udelay(2000);
mt352_write(fe, dntv_extra, sizeof(dntv_extra));
mt352_write(fe, capt_range_cfg, sizeof(capt_range_cfg));
return 0;
}
static int dntv_live_dvbt_pro_demod_init(struct dvb_frontend* fe)
{
static const u8 clock_config [] = { 0x89, 0x38, 0x38 };
static const u8 reset [] = { 0x50, 0x80 };
static const u8 adc_ctl_1_cfg [] = { 0x8E, 0x40 };
static const u8 agc_cfg [] = { 0x67, 0x10, 0x20, 0x00, 0xFF, 0xFF,
0x00, 0xFF, 0x00, 0x40, 0x40 };
static const u8 dntv_extra[] = { 0xB5, 0x7A };
static const u8 capt_range_cfg[] = { 0x75, 0x32 };
mt352_write(fe, clock_config, sizeof(clock_config));
udelay(2000);
mt352_write(fe, reset, sizeof(reset));
mt352_write(fe, adc_ctl_1_cfg, sizeof(adc_ctl_1_cfg));
mt352_write(fe, agc_cfg, sizeof(agc_cfg));
udelay(2000);
mt352_write(fe, dntv_extra, sizeof(dntv_extra));
mt352_write(fe, capt_range_cfg, sizeof(capt_range_cfg));
return 0;
}
static int or51132_set_ts_param(struct dvb_frontend* fe, int is_punctured)
{
struct cx8802_dev *dev= fe->dvb->priv;
dev->ts_gen_cntrl = is_punctured ? 0x04 : 0x00;
return 0;
}
static int lgdt330x_pll_rf_set(struct dvb_frontend* fe, int index)
{
struct cx8802_dev *dev= fe->dvb->priv;
struct cx88_core *core = dev->core;
dprintk(1, "%s: index = %d\n", __func__, index);
if (index == 0)
cx_clear(MO_GP0_IO, 8);
else
cx_set(MO_GP0_IO, 8);
return 0;
}
static int lgdt330x_set_ts_param(struct dvb_frontend* fe, int is_punctured)
{
struct cx8802_dev *dev= fe->dvb->priv;
if (is_punctured)
dev->ts_gen_cntrl |= 0x04;
else
dev->ts_gen_cntrl &= ~0x04;
return 0;
}
static int nxt200x_set_ts_param(struct dvb_frontend* fe, int is_punctured)
{
struct cx8802_dev *dev= fe->dvb->priv;
dev->ts_gen_cntrl = is_punctured ? 0x04 : 0x00;
return 0;
}
static int cx24123_set_ts_param(struct dvb_frontend* fe,
int is_punctured)
{
struct cx8802_dev *dev= fe->dvb->priv;
dev->ts_gen_cntrl = 0x02;
return 0;
}
static int kworld_dvbs_100_set_voltage(struct dvb_frontend* fe,
enum fe_sec_voltage voltage)
{
struct cx8802_dev *dev= fe->dvb->priv;
struct cx88_core *core = dev->core;
if (voltage == SEC_VOLTAGE_OFF)
cx_write(MO_GP0_IO, 0x000006fb);
else
cx_write(MO_GP0_IO, 0x000006f9);
if (core->prev_set_voltage)
return core->prev_set_voltage(fe, voltage);
return 0;
}
static int geniatech_dvbs_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage voltage)
{
struct cx8802_dev *dev= fe->dvb->priv;
struct cx88_core *core = dev->core;
if (voltage == SEC_VOLTAGE_OFF) {
dprintk(1,"LNB Voltage OFF\n");
cx_write(MO_GP0_IO, 0x0000efff);
}
if (core->prev_set_voltage)
return core->prev_set_voltage(fe, voltage);
return 0;
}
static int tevii_dvbs_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage voltage)
{
struct cx8802_dev *dev= fe->dvb->priv;
struct cx88_core *core = dev->core;
cx_set(MO_GP0_IO, 0x6040);
switch (voltage) {
case SEC_VOLTAGE_13:
cx_clear(MO_GP0_IO, 0x20);
break;
case SEC_VOLTAGE_18:
cx_set(MO_GP0_IO, 0x20);
break;
case SEC_VOLTAGE_OFF:
cx_clear(MO_GP0_IO, 0x20);
break;
}
if (core->prev_set_voltage)
return core->prev_set_voltage(fe, voltage);
return 0;
}
static int vp1027_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage voltage)
{
struct cx8802_dev *dev = fe->dvb->priv;
struct cx88_core *core = dev->core;
switch (voltage) {
case SEC_VOLTAGE_13:
dprintk(1, "LNB SEC Voltage=13\n");
cx_write(MO_GP0_IO, 0x00001220);
break;
case SEC_VOLTAGE_18:
dprintk(1, "LNB SEC Voltage=18\n");
cx_write(MO_GP0_IO, 0x00001222);
break;
case SEC_VOLTAGE_OFF:
dprintk(1, "LNB Voltage OFF\n");
cx_write(MO_GP0_IO, 0x00001230);
break;
}
if (core->prev_set_voltage)
return core->prev_set_voltage(fe, voltage);
return 0;
}
static int attach_xc3028(u8 addr, struct cx8802_dev *dev)
{
struct dvb_frontend *fe;
struct vb2_dvb_frontend *fe0 = NULL;
struct xc2028_ctrl ctl;
struct xc2028_config cfg = {
.i2c_adap = &dev->core->i2c_adap,
.i2c_addr = addr,
.ctrl = &ctl,
};
fe0 = vb2_dvb_get_frontend(&dev->frontends, 1);
if (!fe0)
return -EINVAL;
if (!fe0->dvb.frontend) {
printk(KERN_ERR "%s/2: dvb frontend not attached. "
"Can't attach xc3028\n",
dev->core->name);
return -EINVAL;
}
cx88_setup_xc3028(dev->core, &ctl);
fe = dvb_attach(xc2028_attach, fe0->dvb.frontend, &cfg);
if (!fe) {
printk(KERN_ERR "%s/2: xc3028 attach failed\n",
dev->core->name);
dvb_frontend_detach(fe0->dvb.frontend);
dvb_unregister_frontend(fe0->dvb.frontend);
fe0->dvb.frontend = NULL;
return -EINVAL;
}
printk(KERN_INFO "%s/2: xc3028 attached\n",
dev->core->name);
return 0;
}
static int attach_xc4000(struct cx8802_dev *dev, struct xc4000_config *cfg)
{
struct dvb_frontend *fe;
struct vb2_dvb_frontend *fe0 = NULL;
fe0 = vb2_dvb_get_frontend(&dev->frontends, 1);
if (!fe0)
return -EINVAL;
if (!fe0->dvb.frontend) {
printk(KERN_ERR "%s/2: dvb frontend not attached. "
"Can't attach xc4000\n",
dev->core->name);
return -EINVAL;
}
fe = dvb_attach(xc4000_attach, fe0->dvb.frontend, &dev->core->i2c_adap,
cfg);
if (!fe) {
printk(KERN_ERR "%s/2: xc4000 attach failed\n",
dev->core->name);
dvb_frontend_detach(fe0->dvb.frontend);
dvb_unregister_frontend(fe0->dvb.frontend);
fe0->dvb.frontend = NULL;
return -EINVAL;
}
printk(KERN_INFO "%s/2: xc4000 attached\n", dev->core->name);
return 0;
}
static int cx24116_set_ts_param(struct dvb_frontend *fe,
int is_punctured)
{
struct cx8802_dev *dev = fe->dvb->priv;
dev->ts_gen_cntrl = 0x2;
return 0;
}
static int stv0900_set_ts_param(struct dvb_frontend *fe,
int is_punctured)
{
struct cx8802_dev *dev = fe->dvb->priv;
dev->ts_gen_cntrl = 0;
return 0;
}
static int cx24116_reset_device(struct dvb_frontend *fe)
{
struct cx8802_dev *dev = fe->dvb->priv;
struct cx88_core *core = dev->core;
cx_write(MO_SRST_IO, 0);
msleep(10);
cx_write(MO_SRST_IO, 1);
msleep(10);
return 0;
}
static int ds3000_set_ts_param(struct dvb_frontend *fe,
int is_punctured)
{
struct cx8802_dev *dev = fe->dvb->priv;
dev->ts_gen_cntrl = 4;
return 0;
}
static int cx8802_alloc_frontends(struct cx8802_dev *dev)
{
struct cx88_core *core = dev->core;
struct vb2_dvb_frontend *fe = NULL;
int i;
mutex_init(&dev->frontends.lock);
INIT_LIST_HEAD(&dev->frontends.felist);
if (!core->board.num_frontends)
return -ENODEV;
printk(KERN_INFO "%s() allocating %d frontend(s)\n", __func__,
core->board.num_frontends);
for (i = 1; i <= core->board.num_frontends; i++) {
fe = vb2_dvb_alloc_frontend(&dev->frontends, i);
if (!fe) {
printk(KERN_ERR "%s() failed to alloc\n", __func__);
vb2_dvb_dealloc_frontends(&dev->frontends);
return -ENOMEM;
}
}
return 0;
}
static int samsung_smt_7020_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct cx8802_dev *dev = fe->dvb->priv;
u8 buf[4];
u32 div;
struct i2c_msg msg = {
.addr = 0x61,
.flags = 0,
.buf = buf,
.len = sizeof(buf) };
div = c->frequency / 125;
buf[0] = (div >> 8) & 0x7f;
buf[1] = div & 0xff;
buf[2] = 0x84;
buf[3] = 0x00;
if (c->frequency < 1500000)
buf[3] |= 0x10;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&dev->core->i2c_adap, &msg, 1) != 1)
return -EIO;
return 0;
}
static int samsung_smt_7020_set_tone(struct dvb_frontend *fe,
enum fe_sec_tone_mode tone)
{
struct cx8802_dev *dev = fe->dvb->priv;
struct cx88_core *core = dev->core;
cx_set(MO_GP0_IO, 0x0800);
switch (tone) {
case SEC_TONE_ON:
cx_set(MO_GP0_IO, 0x08);
break;
case SEC_TONE_OFF:
cx_clear(MO_GP0_IO, 0x08);
break;
default:
return -EINVAL;
}
return 0;
}
static int samsung_smt_7020_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage voltage)
{
struct cx8802_dev *dev = fe->dvb->priv;
struct cx88_core *core = dev->core;
u8 data;
struct i2c_msg msg = {
.addr = 8,
.flags = 0,
.buf = &data,
.len = sizeof(data) };
cx_set(MO_GP0_IO, 0x8000);
switch (voltage) {
case SEC_VOLTAGE_OFF:
break;
case SEC_VOLTAGE_13:
data = ISL6421_EN1 | ISL6421_LLC1;
cx_clear(MO_GP0_IO, 0x80);
break;
case SEC_VOLTAGE_18:
data = ISL6421_EN1 | ISL6421_LLC1 | ISL6421_VSEL1;
cx_clear(MO_GP0_IO, 0x80);
break;
default:
return -EINVAL;
}
return (i2c_transfer(&dev->core->i2c_adap, &msg, 1) == 1) ? 0 : -EIO;
}
static int samsung_smt_7020_stv0299_set_symbol_rate(struct dvb_frontend *fe,
u32 srate, u32 ratio)
{
u8 aclk = 0;
u8 bclk = 0;
if (srate < 1500000) {
aclk = 0xb7;
bclk = 0x47;
} else if (srate < 3000000) {
aclk = 0xb7;
bclk = 0x4b;
} else if (srate < 7000000) {
aclk = 0xb7;
bclk = 0x4f;
} else if (srate < 14000000) {
aclk = 0xb7;
bclk = 0x53;
} else if (srate < 30000000) {
aclk = 0xb6;
bclk = 0x53;
} else if (srate < 45000000) {
aclk = 0xb4;
bclk = 0x51;
}
stv0299_writereg(fe, 0x13, aclk);
stv0299_writereg(fe, 0x14, bclk);
stv0299_writereg(fe, 0x1f, (ratio >> 16) & 0xff);
stv0299_writereg(fe, 0x20, (ratio >> 8) & 0xff);
stv0299_writereg(fe, 0x21, ratio & 0xf0);
return 0;
}
static int dvb_register(struct cx8802_dev *dev)
{
struct cx88_core *core = dev->core;
struct vb2_dvb_frontend *fe0, *fe1 = NULL;
int mfe_shared = 0;
int res = -EINVAL;
if (0 != core->i2c_rc) {
printk(KERN_ERR "%s/2: no i2c-bus available, cannot attach dvb drivers\n", core->name);
goto frontend_detach;
}
fe0 = vb2_dvb_get_frontend(&dev->frontends, 1);
if (!fe0)
goto frontend_detach;
dev->frontends.gate = 0;
core->gate_ctrl = cx88_dvb_gate_ctrl;
switch (core->boardnr) {
case CX88_BOARD_HAUPPAUGE_DVB_T1:
fe0->dvb.frontend = dvb_attach(cx22702_attach,
&connexant_refboard_config,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(dvb_pll_attach, fe0->dvb.frontend,
0x61, &core->i2c_adap,
DVB_PLL_THOMSON_DTT759X))
goto frontend_detach;
}
break;
case CX88_BOARD_TERRATEC_CINERGY_1400_DVB_T1:
case CX88_BOARD_CONEXANT_DVB_T1:
case CX88_BOARD_KWORLD_DVB_T_CX22702:
case CX88_BOARD_WINFAST_DTV1000:
fe0->dvb.frontend = dvb_attach(cx22702_attach,
&connexant_refboard_config,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(dvb_pll_attach, fe0->dvb.frontend,
0x60, &core->i2c_adap,
DVB_PLL_THOMSON_DTT7579))
goto frontend_detach;
}
break;
case CX88_BOARD_WINFAST_DTV2000H:
case CX88_BOARD_HAUPPAUGE_HVR1100:
case CX88_BOARD_HAUPPAUGE_HVR1100LP:
case CX88_BOARD_HAUPPAUGE_HVR1300:
fe0->dvb.frontend = dvb_attach(cx22702_attach,
&hauppauge_hvr_config,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(simple_tuner_attach, fe0->dvb.frontend,
&core->i2c_adap, 0x61,
TUNER_PHILIPS_FMD1216ME_MK3))
goto frontend_detach;
}
break;
case CX88_BOARD_WINFAST_DTV2000H_J:
fe0->dvb.frontend = dvb_attach(cx22702_attach,
&hauppauge_hvr_config,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(simple_tuner_attach, fe0->dvb.frontend,
&core->i2c_adap, 0x61,
TUNER_PHILIPS_FMD1216MEX_MK3))
goto frontend_detach;
}
break;
case CX88_BOARD_HAUPPAUGE_HVR3000:
mfe_shared = 1;
dev->frontends.gate = 2;
fe0->dvb.frontend = dvb_attach(cx24123_attach,
&hauppauge_novas_config,
&dev->core->i2c_adap);
if (fe0->dvb.frontend) {
if (!dvb_attach(isl6421_attach,
fe0->dvb.frontend,
&dev->core->i2c_adap,
0x08, ISL6421_DCL, 0x00, false))
goto frontend_detach;
}
fe1 = vb2_dvb_get_frontend(&dev->frontends, 2);
if (!fe1)
goto frontend_detach;
fe1->dvb.frontend = dvb_attach(cx22702_attach,
&hauppauge_hvr_config,
&dev->core->i2c_adap);
if (fe1->dvb.frontend) {
fe1->dvb.frontend->id = 1;
if (!dvb_attach(simple_tuner_attach,
fe1->dvb.frontend,
&dev->core->i2c_adap,
0x61, TUNER_PHILIPS_FMD1216ME_MK3))
goto frontend_detach;
}
break;
case CX88_BOARD_DVICO_FUSIONHDTV_DVB_T_PLUS:
fe0->dvb.frontend = dvb_attach(mt352_attach,
&dvico_fusionhdtv,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(dvb_pll_attach, fe0->dvb.frontend,
0x60, NULL, DVB_PLL_THOMSON_DTT7579))
goto frontend_detach;
break;
}
fe0->dvb.frontend = dvb_attach(zl10353_attach,
&dvico_fusionhdtv_plus_v1_1,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(dvb_pll_attach, fe0->dvb.frontend,
0x60, NULL, DVB_PLL_THOMSON_DTT7579))
goto frontend_detach;
}
break;
case CX88_BOARD_DVICO_FUSIONHDTV_DVB_T_DUAL:
fe0->dvb.frontend = dvb_attach(mt352_attach,
&dvico_fusionhdtv_dual,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(dvb_pll_attach, fe0->dvb.frontend,
0x61, NULL, DVB_PLL_THOMSON_DTT7579))
goto frontend_detach;
break;
}
fe0->dvb.frontend = dvb_attach(zl10353_attach,
&dvico_fusionhdtv_plus_v1_1,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(dvb_pll_attach, fe0->dvb.frontend,
0x61, NULL, DVB_PLL_THOMSON_DTT7579))
goto frontend_detach;
}
break;
case CX88_BOARD_DVICO_FUSIONHDTV_DVB_T1:
fe0->dvb.frontend = dvb_attach(mt352_attach,
&dvico_fusionhdtv,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(dvb_pll_attach, fe0->dvb.frontend,
0x61, NULL, DVB_PLL_LG_Z201))
goto frontend_detach;
}
break;
case CX88_BOARD_KWORLD_DVB_T:
case CX88_BOARD_DNTV_LIVE_DVB_T:
case CX88_BOARD_ADSTECH_DVB_T_PCI:
fe0->dvb.frontend = dvb_attach(mt352_attach,
&dntv_live_dvbt_config,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(dvb_pll_attach, fe0->dvb.frontend,
0x61, NULL, DVB_PLL_UNKNOWN_1))
goto frontend_detach;
}
break;
case CX88_BOARD_DNTV_LIVE_DVB_T_PRO:
#if IS_ENABLED(CONFIG_VIDEO_CX88_VP3054)
fe0->dvb.frontend = dvb_attach(mt352_attach, &dntv_live_dvbt_pro_config,
&dev->vp3054->adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(simple_tuner_attach, fe0->dvb.frontend,
&core->i2c_adap, 0x61,
TUNER_PHILIPS_FMD1216ME_MK3))
goto frontend_detach;
}
#else
printk(KERN_ERR "%s/2: built without vp3054 support\n",
core->name);
#endif
break;
case CX88_BOARD_DVICO_FUSIONHDTV_DVB_T_HYBRID:
fe0->dvb.frontend = dvb_attach(zl10353_attach,
&dvico_fusionhdtv_hybrid,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(simple_tuner_attach, fe0->dvb.frontend,
&core->i2c_adap, 0x61,
TUNER_THOMSON_FE6600))
goto frontend_detach;
}
break;
case CX88_BOARD_DVICO_FUSIONHDTV_DVB_T_PRO:
fe0->dvb.frontend = dvb_attach(zl10353_attach,
&dvico_fusionhdtv_xc3028,
&core->i2c_adap);
if (fe0->dvb.frontend == NULL)
fe0->dvb.frontend = dvb_attach(mt352_attach,
&dvico_fusionhdtv_mt352_xc3028,
&core->i2c_adap);
if (fe0->dvb.frontend)
fe0->dvb.frontend->ops.i2c_gate_ctrl = NULL;
if (attach_xc3028(0x61, dev) < 0)
goto frontend_detach;
break;
case CX88_BOARD_PCHDTV_HD3000:
fe0->dvb.frontend = dvb_attach(or51132_attach, &pchdtv_hd3000,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(simple_tuner_attach, fe0->dvb.frontend,
&core->i2c_adap, 0x61,
TUNER_THOMSON_DTT761X))
goto frontend_detach;
}
break;
case CX88_BOARD_DVICO_FUSIONHDTV_3_GOLD_Q:
dev->ts_gen_cntrl = 0x08;
cx_clear(MO_GP0_IO, 1);
mdelay(100);
cx_set(MO_GP0_IO, 1);
mdelay(200);
fusionhdtv_3_gold.pll_rf_set = lgdt330x_pll_rf_set;
fe0->dvb.frontend = dvb_attach(lgdt330x_attach,
&fusionhdtv_3_gold,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(simple_tuner_attach, fe0->dvb.frontend,
&core->i2c_adap, 0x61,
TUNER_MICROTUNE_4042FI5))
goto frontend_detach;
}
break;
case CX88_BOARD_DVICO_FUSIONHDTV_3_GOLD_T:
dev->ts_gen_cntrl = 0x08;
cx_clear(MO_GP0_IO, 1);
mdelay(100);
cx_set(MO_GP0_IO, 9);
mdelay(200);
fe0->dvb.frontend = dvb_attach(lgdt330x_attach,
&fusionhdtv_3_gold,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(simple_tuner_attach, fe0->dvb.frontend,
&core->i2c_adap, 0x61,
TUNER_THOMSON_DTT761X))
goto frontend_detach;
}
break;
case CX88_BOARD_DVICO_FUSIONHDTV_5_GOLD:
dev->ts_gen_cntrl = 0x08;
cx_clear(MO_GP0_IO, 1);
mdelay(100);
cx_set(MO_GP0_IO, 1);
mdelay(200);
fe0->dvb.frontend = dvb_attach(lgdt330x_attach,
&fusionhdtv_5_gold,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(simple_tuner_attach, fe0->dvb.frontend,
&core->i2c_adap, 0x61,
TUNER_LG_TDVS_H06XF))
goto frontend_detach;
if (!dvb_attach(tda9887_attach, fe0->dvb.frontend,
&core->i2c_adap, 0x43))
goto frontend_detach;
}
break;
case CX88_BOARD_PCHDTV_HD5500:
dev->ts_gen_cntrl = 0x08;
cx_clear(MO_GP0_IO, 1);
mdelay(100);
cx_set(MO_GP0_IO, 1);
mdelay(200);
fe0->dvb.frontend = dvb_attach(lgdt330x_attach,
&pchdtv_hd5500,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(simple_tuner_attach, fe0->dvb.frontend,
&core->i2c_adap, 0x61,
TUNER_LG_TDVS_H06XF))
goto frontend_detach;
if (!dvb_attach(tda9887_attach, fe0->dvb.frontend,
&core->i2c_adap, 0x43))
goto frontend_detach;
}
break;
case CX88_BOARD_ATI_HDTVWONDER:
fe0->dvb.frontend = dvb_attach(nxt200x_attach,
&ati_hdtvwonder,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(simple_tuner_attach, fe0->dvb.frontend,
&core->i2c_adap, 0x61,
TUNER_PHILIPS_TUV1236D))
goto frontend_detach;
}
break;
case CX88_BOARD_HAUPPAUGE_NOVASPLUS_S1:
case CX88_BOARD_HAUPPAUGE_NOVASE2_S1:
fe0->dvb.frontend = dvb_attach(cx24123_attach,
&hauppauge_novas_config,
&core->i2c_adap);
if (fe0->dvb.frontend) {
bool override_tone;
if (core->model == 92001)
override_tone = true;
else
override_tone = false;
if (!dvb_attach(isl6421_attach, fe0->dvb.frontend,
&core->i2c_adap, 0x08, ISL6421_DCL, 0x00,
override_tone))
goto frontend_detach;
}
break;
case CX88_BOARD_KWORLD_DVBS_100:
fe0->dvb.frontend = dvb_attach(cx24123_attach,
&kworld_dvbs_100_config,
&core->i2c_adap);
if (fe0->dvb.frontend) {
core->prev_set_voltage = fe0->dvb.frontend->ops.set_voltage;
fe0->dvb.frontend->ops.set_voltage = kworld_dvbs_100_set_voltage;
}
break;
case CX88_BOARD_GENIATECH_DVBS:
fe0->dvb.frontend = dvb_attach(cx24123_attach,
&geniatech_dvbs_config,
&core->i2c_adap);
if (fe0->dvb.frontend) {
core->prev_set_voltage = fe0->dvb.frontend->ops.set_voltage;
fe0->dvb.frontend->ops.set_voltage = geniatech_dvbs_set_voltage;
}
break;
case CX88_BOARD_PINNACLE_PCTV_HD_800i:
fe0->dvb.frontend = dvb_attach(s5h1409_attach,
&pinnacle_pctv_hd_800i_config,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(xc5000_attach, fe0->dvb.frontend,
&core->i2c_adap,
&pinnacle_pctv_hd_800i_tuner_config))
goto frontend_detach;
}
break;
case CX88_BOARD_DVICO_FUSIONHDTV_5_PCI_NANO:
fe0->dvb.frontend = dvb_attach(s5h1409_attach,
&dvico_hdtv5_pci_nano_config,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
struct dvb_frontend *fe;
struct xc2028_config cfg = {
.i2c_adap = &core->i2c_adap,
.i2c_addr = 0x61,
};
static struct xc2028_ctrl ctl = {
.fname = XC2028_DEFAULT_FIRMWARE,
.max_len = 64,
.scode_table = XC3028_FE_OREN538,
};
fe = dvb_attach(xc2028_attach,
fe0->dvb.frontend, &cfg);
if (fe != NULL && fe->ops.tuner_ops.set_config != NULL)
fe->ops.tuner_ops.set_config(fe, &ctl);
}
break;
case CX88_BOARD_PINNACLE_HYBRID_PCTV:
case CX88_BOARD_WINFAST_DTV1800H:
fe0->dvb.frontend = dvb_attach(zl10353_attach,
&cx88_pinnacle_hybrid_pctv,
&core->i2c_adap);
if (fe0->dvb.frontend) {
fe0->dvb.frontend->ops.i2c_gate_ctrl = NULL;
if (attach_xc3028(0x61, dev) < 0)
goto frontend_detach;
}
break;
case CX88_BOARD_WINFAST_DTV1800H_XC4000:
case CX88_BOARD_WINFAST_DTV2000H_PLUS:
fe0->dvb.frontend = dvb_attach(zl10353_attach,
&cx88_pinnacle_hybrid_pctv,
&core->i2c_adap);
if (fe0->dvb.frontend) {
struct xc4000_config cfg = {
.i2c_address = 0x61,
.default_pm = 0,
.dvb_amplitude = 134,
.set_smoothedcvbs = 1,
.if_khz = 4560
};
fe0->dvb.frontend->ops.i2c_gate_ctrl = NULL;
if (attach_xc4000(dev, &cfg) < 0)
goto frontend_detach;
}
break;
case CX88_BOARD_GENIATECH_X8000_MT:
dev->ts_gen_cntrl = 0x00;
fe0->dvb.frontend = dvb_attach(zl10353_attach,
&cx88_geniatech_x8000_mt,
&core->i2c_adap);
if (attach_xc3028(0x61, dev) < 0)
goto frontend_detach;
break;
case CX88_BOARD_KWORLD_ATSC_120:
fe0->dvb.frontend = dvb_attach(s5h1409_attach,
&kworld_atsc_120_config,
&core->i2c_adap);
if (attach_xc3028(0x61, dev) < 0)
goto frontend_detach;
break;
case CX88_BOARD_DVICO_FUSIONHDTV_7_GOLD:
fe0->dvb.frontend = dvb_attach(s5h1411_attach,
&dvico_fusionhdtv7_config,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(xc5000_attach, fe0->dvb.frontend,
&core->i2c_adap,
&dvico_fusionhdtv7_tuner_config))
goto frontend_detach;
}
break;
case CX88_BOARD_HAUPPAUGE_HVR4000:
mfe_shared = 1;
dev->frontends.gate = 2;
fe0->dvb.frontend = dvb_attach(cx24116_attach,
&hauppauge_hvr4000_config,
&dev->core->i2c_adap);
if (fe0->dvb.frontend) {
if (!dvb_attach(isl6421_attach,
fe0->dvb.frontend,
&dev->core->i2c_adap,
0x08, ISL6421_DCL, 0x00, false))
goto frontend_detach;
}
fe1 = vb2_dvb_get_frontend(&dev->frontends, 2);
if (!fe1)
goto frontend_detach;
fe1->dvb.frontend = dvb_attach(cx22702_attach,
&hauppauge_hvr_config,
&dev->core->i2c_adap);
if (fe1->dvb.frontend) {
fe1->dvb.frontend->id = 1;
if (!dvb_attach(simple_tuner_attach,
fe1->dvb.frontend,
&dev->core->i2c_adap,
0x61, TUNER_PHILIPS_FMD1216ME_MK3))
goto frontend_detach;
}
break;
case CX88_BOARD_HAUPPAUGE_HVR4000LITE:
fe0->dvb.frontend = dvb_attach(cx24116_attach,
&hauppauge_hvr4000_config,
&dev->core->i2c_adap);
if (fe0->dvb.frontend) {
if (!dvb_attach(isl6421_attach,
fe0->dvb.frontend,
&dev->core->i2c_adap,
0x08, ISL6421_DCL, 0x00, false))
goto frontend_detach;
}
break;
case CX88_BOARD_PROF_6200:
case CX88_BOARD_TBS_8910:
case CX88_BOARD_TEVII_S420:
fe0->dvb.frontend = dvb_attach(stv0299_attach,
&tevii_tuner_sharp_config,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(dvb_pll_attach, fe0->dvb.frontend, 0x60,
&core->i2c_adap, DVB_PLL_OPERA1))
goto frontend_detach;
core->prev_set_voltage = fe0->dvb.frontend->ops.set_voltage;
fe0->dvb.frontend->ops.set_voltage = tevii_dvbs_set_voltage;
} else {
fe0->dvb.frontend = dvb_attach(stv0288_attach,
&tevii_tuner_earda_config,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(stb6000_attach, fe0->dvb.frontend, 0x61,
&core->i2c_adap))
goto frontend_detach;
core->prev_set_voltage = fe0->dvb.frontend->ops.set_voltage;
fe0->dvb.frontend->ops.set_voltage = tevii_dvbs_set_voltage;
}
}
break;
case CX88_BOARD_TEVII_S460:
fe0->dvb.frontend = dvb_attach(cx24116_attach,
&tevii_s460_config,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL)
fe0->dvb.frontend->ops.set_voltage = tevii_dvbs_set_voltage;
break;
case CX88_BOARD_TEVII_S464:
fe0->dvb.frontend = dvb_attach(ds3000_attach,
&tevii_ds3000_config,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL) {
dvb_attach(ts2020_attach, fe0->dvb.frontend,
&tevii_ts2020_config, &core->i2c_adap);
fe0->dvb.frontend->ops.set_voltage =
tevii_dvbs_set_voltage;
}
break;
case CX88_BOARD_OMICOM_SS4_PCI:
case CX88_BOARD_TBS_8920:
case CX88_BOARD_PROF_7300:
case CX88_BOARD_SATTRADE_ST4200:
fe0->dvb.frontend = dvb_attach(cx24116_attach,
&hauppauge_hvr4000_config,
&core->i2c_adap);
if (fe0->dvb.frontend != NULL)
fe0->dvb.frontend->ops.set_voltage = tevii_dvbs_set_voltage;
break;
case CX88_BOARD_TERRATEC_CINERGY_HT_PCI_MKII:
fe0->dvb.frontend = dvb_attach(zl10353_attach,
&cx88_terratec_cinergy_ht_pci_mkii_config,
&core->i2c_adap);
if (fe0->dvb.frontend) {
fe0->dvb.frontend->ops.i2c_gate_ctrl = NULL;
if (attach_xc3028(0x61, dev) < 0)
goto frontend_detach;
}
break;
case CX88_BOARD_PROF_7301:{
struct dvb_tuner_ops *tuner_ops = NULL;
fe0->dvb.frontend = dvb_attach(stv0900_attach,
&prof_7301_stv0900_config,
&core->i2c_adap, 0);
if (fe0->dvb.frontend != NULL) {
if (!dvb_attach(stb6100_attach, fe0->dvb.frontend,
&prof_7301_stb6100_config,
&core->i2c_adap))
goto frontend_detach;
tuner_ops = &fe0->dvb.frontend->ops.tuner_ops;
tuner_ops->set_frequency = stb6100_set_freq;
tuner_ops->get_frequency = stb6100_get_freq;
tuner_ops->set_bandwidth = stb6100_set_bandw;
tuner_ops->get_bandwidth = stb6100_get_bandw;
core->prev_set_voltage =
fe0->dvb.frontend->ops.set_voltage;
fe0->dvb.frontend->ops.set_voltage =
tevii_dvbs_set_voltage;
}
break;
}
case CX88_BOARD_SAMSUNG_SMT_7020:
dev->ts_gen_cntrl = 0x08;
cx_set(MO_GP0_IO, 0x0101);
cx_clear(MO_GP0_IO, 0x01);
mdelay(100);
cx_set(MO_GP0_IO, 0x01);
mdelay(200);
fe0->dvb.frontend = dvb_attach(stv0299_attach,
&samsung_stv0299_config,
&dev->core->i2c_adap);
if (fe0->dvb.frontend) {
fe0->dvb.frontend->ops.tuner_ops.set_params =
samsung_smt_7020_tuner_set_params;
fe0->dvb.frontend->tuner_priv =
&dev->core->i2c_adap;
fe0->dvb.frontend->ops.set_voltage =
samsung_smt_7020_set_voltage;
fe0->dvb.frontend->ops.set_tone =
samsung_smt_7020_set_tone;
}
break;
case CX88_BOARD_TWINHAN_VP1027_DVBS:
dev->ts_gen_cntrl = 0x00;
fe0->dvb.frontend = dvb_attach(mb86a16_attach,
&twinhan_vp1027,
&core->i2c_adap);
if (fe0->dvb.frontend) {
core->prev_set_voltage =
fe0->dvb.frontend->ops.set_voltage;
fe0->dvb.frontend->ops.set_voltage =
vp1027_set_voltage;
}
break;
default:
printk(KERN_ERR "%s/2: The frontend of your DVB/ATSC card isn't supported yet\n",
core->name);
break;
}
if ( (NULL == fe0->dvb.frontend) || (fe1 && NULL == fe1->dvb.frontend) ) {
printk(KERN_ERR
"%s/2: frontend initialization failed\n",
core->name);
goto frontend_detach;
}
fe0->dvb.frontend->callback = cx88_tuner_callback;
fe0->dvb.frontend->ops.ts_bus_ctrl = cx88_dvb_bus_ctrl;
if (fe1)
fe1->dvb.frontend->ops.ts_bus_ctrl = cx88_dvb_bus_ctrl;
call_all(core, core, s_power, 0);
res = vb2_dvb_register_bus(&dev->frontends, THIS_MODULE, dev,
&dev->pci->dev, adapter_nr, mfe_shared);
if (res)
goto frontend_detach;
return res;
frontend_detach:
core->gate_ctrl = NULL;
vb2_dvb_dealloc_frontends(&dev->frontends);
return res;
}
static int cx8802_dvb_advise_acquire(struct cx8802_driver *drv)
{
struct cx88_core *core = drv->core;
int err = 0;
dprintk( 1, "%s\n", __func__);
switch (core->boardnr) {
case CX88_BOARD_HAUPPAUGE_HVR1300:
cx_set(MO_GP0_IO, 0x00000080);
udelay(1000);
cx_clear(MO_GP0_IO, 0x00000080);
udelay(50);
cx_set(MO_GP0_IO, 0x00000080);
udelay(1000);
cx_clear(MO_GP0_IO, 0x00000004);
udelay(1000);
break;
case CX88_BOARD_HAUPPAUGE_HVR3000:
case CX88_BOARD_HAUPPAUGE_HVR4000:
cx_set(MO_GP0_IO, 0x00000080);
udelay(1000);
cx_clear(MO_GP0_IO, 0x00000080);
udelay(50);
cx_set(MO_GP0_IO, 0x00000080);
udelay(1000);
switch (core->dvbdev->frontends.active_fe_id) {
case 1:
cx_set(MO_GP0_IO, 0x00000004);
cx_write(MO_SRST_IO, 1);
core->dvbdev->ts_gen_cntrl = 0x02;
break;
case 2:
cx_write(MO_SRST_IO, 0);
cx_clear(MO_GP0_IO, 0x00000004);
core->dvbdev->ts_gen_cntrl = 0x0c;
break;
}
udelay(1000);
break;
case CX88_BOARD_WINFAST_DTV2000H_PLUS:
cx_write(MO_GP2_IO, 0x0101);
break;
default:
err = -ENODEV;
}
return err;
}
static int cx8802_dvb_advise_release(struct cx8802_driver *drv)
{
struct cx88_core *core = drv->core;
int err = 0;
dprintk( 1, "%s\n", __func__);
switch (core->boardnr) {
case CX88_BOARD_HAUPPAUGE_HVR1300:
break;
case CX88_BOARD_HAUPPAUGE_HVR3000:
case CX88_BOARD_HAUPPAUGE_HVR4000:
break;
default:
err = -ENODEV;
}
return err;
}
static int cx8802_dvb_probe(struct cx8802_driver *drv)
{
struct cx88_core *core = drv->core;
struct cx8802_dev *dev = drv->core->dvbdev;
int err;
struct vb2_dvb_frontend *fe;
int i;
dprintk( 1, "%s\n", __func__);
dprintk( 1, " ->being probed by Card=%d Name=%s, PCI %02x:%02x\n",
core->boardnr,
core->name,
core->pci_bus,
core->pci_slot);
err = -ENODEV;
if (!(core->board.mpeg & CX88_MPEG_DVB))
goto fail_core;
err = vp3054_i2c_probe(dev);
if (0 != err)
goto fail_core;
printk(KERN_INFO "%s/2: cx2388x based DVB/ATSC card\n", core->name);
dev->ts_gen_cntrl = 0x0c;
err = cx8802_alloc_frontends(dev);
if (err)
goto fail_core;
err = -ENODEV;
for (i = 1; i <= core->board.num_frontends; i++) {
struct vb2_queue *q;
fe = vb2_dvb_get_frontend(&core->dvbdev->frontends, i);
if (fe == NULL) {
printk(KERN_ERR "%s() failed to get frontend(%d)\n",
__func__, i);
goto fail_probe;
}
q = &fe->dvb.dvbq;
q->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
q->io_modes = VB2_MMAP | VB2_USERPTR | VB2_DMABUF | VB2_READ;
q->gfp_flags = GFP_DMA32;
q->min_buffers_needed = 2;
q->drv_priv = dev;
q->buf_struct_size = sizeof(struct cx88_buffer);
q->ops = &dvb_qops;
q->mem_ops = &vb2_dma_sg_memops;
q->timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
q->lock = &core->lock;
err = vb2_queue_init(q);
if (err < 0)
goto fail_probe;
fe->dvb.name = dev->core->name;
}
err = dvb_register(dev);
if (err)
printk(KERN_ERR "%s/2: dvb_register failed (err = %d)\n",
core->name, err);
return err;
fail_probe:
vb2_dvb_dealloc_frontends(&core->dvbdev->frontends);
fail_core:
return err;
}
static int cx8802_dvb_remove(struct cx8802_driver *drv)
{
struct cx88_core *core = drv->core;
struct cx8802_dev *dev = drv->core->dvbdev;
dprintk( 1, "%s\n", __func__);
vb2_dvb_unregister_bus(&dev->frontends);
vp3054_i2c_remove(dev);
core->gate_ctrl = NULL;
return 0;
}
static int __init dvb_init(void)
{
printk(KERN_INFO "cx88/2: cx2388x dvb driver version %s loaded\n",
CX88_VERSION);
return cx8802_register_driver(&cx8802_dvb_driver);
}
static void __exit dvb_fini(void)
{
cx8802_unregister_driver(&cx8802_dvb_driver);
}
