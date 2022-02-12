static inline void print_err_status(struct em28xx *dev,
int packet, int status)
{
char *errmsg = "Unknown";
switch (status) {
case -ENOENT:
errmsg = "unlinked synchronuously";
break;
case -ECONNRESET:
errmsg = "unlinked asynchronuously";
break;
case -ENOSR:
errmsg = "Buffer error (overrun)";
break;
case -EPIPE:
errmsg = "Stalled (device not responding)";
break;
case -EOVERFLOW:
errmsg = "Babble (bad cable?)";
break;
case -EPROTO:
errmsg = "Bit-stuff error (bad cable?)";
break;
case -EILSEQ:
errmsg = "CRC/Timeout (could be anything)";
break;
case -ETIME:
errmsg = "Device does not respond";
break;
}
if (packet < 0) {
dprintk(1, "URB status %d [%s].\n", status, errmsg);
} else {
dprintk(1, "URB packet %d, status %d [%s].\n",
packet, status, errmsg);
}
}
static inline int em28xx_dvb_urb_data_copy(struct em28xx *dev, struct urb *urb)
{
int xfer_bulk, num_packets, i;
if (!dev)
return 0;
if (dev->disconnected)
return 0;
if (urb->status < 0)
print_err_status(dev, -1, urb->status);
xfer_bulk = usb_pipebulk(urb->pipe);
if (xfer_bulk)
num_packets = 1;
else
num_packets = urb->number_of_packets;
for (i = 0; i < num_packets; i++) {
if (xfer_bulk) {
if (urb->status < 0) {
print_err_status(dev, i, urb->status);
if (urb->status != -EPROTO)
continue;
}
if (!urb->actual_length)
continue;
dvb_dmx_swfilter(&dev->dvb->demux, urb->transfer_buffer,
urb->actual_length);
} else {
if (urb->iso_frame_desc[i].status < 0) {
print_err_status(dev, i,
urb->iso_frame_desc[i].status);
if (urb->iso_frame_desc[i].status != -EPROTO)
continue;
}
if (!urb->iso_frame_desc[i].actual_length)
continue;
dvb_dmx_swfilter(&dev->dvb->demux,
urb->transfer_buffer +
urb->iso_frame_desc[i].offset,
urb->iso_frame_desc[i].actual_length);
}
}
return 0;
}
static int em28xx_start_streaming(struct em28xx_dvb *dvb)
{
int rc;
struct em28xx_i2c_bus *i2c_bus = dvb->adapter.priv;
struct em28xx *dev = i2c_bus->dev;
struct usb_device *udev = interface_to_usbdev(dev->intf);
int dvb_max_packet_size, packet_multiplier, dvb_alt;
if (dev->dvb_xfer_bulk) {
if (!dev->dvb_ep_bulk)
return -ENODEV;
dvb_max_packet_size = 512;
packet_multiplier = EM28XX_DVB_BULK_PACKET_MULTIPLIER;
dvb_alt = 0;
} else {
if (!dev->dvb_ep_isoc)
return -ENODEV;
dvb_max_packet_size = dev->dvb_max_pkt_size_isoc;
if (dvb_max_packet_size < 0)
return dvb_max_packet_size;
packet_multiplier = EM28XX_DVB_NUM_ISOC_PACKETS;
dvb_alt = dev->dvb_alt_isoc;
}
usb_set_interface(udev, dev->ifnum, dvb_alt);
rc = em28xx_set_mode(dev, EM28XX_DIGITAL_MODE);
if (rc < 0)
return rc;
dprintk(1, "Using %d buffers each with %d x %d bytes, alternate %d\n",
EM28XX_DVB_NUM_BUFS,
packet_multiplier,
dvb_max_packet_size, dvb_alt);
return em28xx_init_usb_xfer(dev, EM28XX_DIGITAL_MODE,
dev->dvb_xfer_bulk,
EM28XX_DVB_NUM_BUFS,
dvb_max_packet_size,
packet_multiplier,
em28xx_dvb_urb_data_copy);
}
static int em28xx_stop_streaming(struct em28xx_dvb *dvb)
{
struct em28xx_i2c_bus *i2c_bus = dvb->adapter.priv;
struct em28xx *dev = i2c_bus->dev;
em28xx_stop_urbs(dev);
return 0;
}
static int em28xx_start_feed(struct dvb_demux_feed *feed)
{
struct dvb_demux *demux = feed->demux;
struct em28xx_dvb *dvb = demux->priv;
int rc, ret;
if (!demux->dmx.frontend)
return -EINVAL;
mutex_lock(&dvb->lock);
dvb->nfeeds++;
rc = dvb->nfeeds;
if (dvb->nfeeds == 1) {
ret = em28xx_start_streaming(dvb);
if (ret < 0)
rc = ret;
}
mutex_unlock(&dvb->lock);
return rc;
}
static int em28xx_stop_feed(struct dvb_demux_feed *feed)
{
struct dvb_demux *demux = feed->demux;
struct em28xx_dvb *dvb = demux->priv;
int err = 0;
mutex_lock(&dvb->lock);
dvb->nfeeds--;
if (0 == dvb->nfeeds)
err = em28xx_stop_streaming(dvb);
mutex_unlock(&dvb->lock);
return err;
}
static int em28xx_dvb_bus_ctrl(struct dvb_frontend *fe, int acquire)
{
struct em28xx_i2c_bus *i2c_bus = fe->dvb->priv;
struct em28xx *dev = i2c_bus->dev;
if (acquire)
return em28xx_set_mode(dev, EM28XX_DIGITAL_MODE);
else
return em28xx_set_mode(dev, EM28XX_SUSPEND);
}
static int drxk_gate_ctrl(struct dvb_frontend *fe, int enable)
{
struct em28xx_dvb *dvb = fe->sec_priv;
int status;
if (!dvb)
return -EINVAL;
if (enable) {
down(&dvb->pll_mutex);
status = dvb->gate_ctrl(fe, 1);
} else {
status = dvb->gate_ctrl(fe, 0);
up(&dvb->pll_mutex);
}
return status;
}
static void hauppauge_hvr930c_init(struct em28xx *dev)
{
int i;
struct em28xx_reg_seq hauppauge_hvr930c_init[] = {
{EM2874_R80_GPIO_P0_CTRL, 0xff, 0xff, 0x65},
{EM2874_R80_GPIO_P0_CTRL, 0xfb, 0xff, 0x32},
{EM2874_R80_GPIO_P0_CTRL, 0xff, 0xff, 0xb8},
{ -1, -1, -1, -1},
};
struct em28xx_reg_seq hauppauge_hvr930c_end[] = {
{EM2874_R80_GPIO_P0_CTRL, 0xef, 0xff, 0x01},
{EM2874_R80_GPIO_P0_CTRL, 0xaf, 0xff, 0x65},
{EM2874_R80_GPIO_P0_CTRL, 0xef, 0xff, 0x76},
{EM2874_R80_GPIO_P0_CTRL, 0xef, 0xff, 0x01},
{EM2874_R80_GPIO_P0_CTRL, 0xcf, 0xff, 0x0b},
{EM2874_R80_GPIO_P0_CTRL, 0xef, 0xff, 0x40},
{EM2874_R80_GPIO_P0_CTRL, 0xcf, 0xff, 0x65},
{EM2874_R80_GPIO_P0_CTRL, 0xef, 0xff, 0x65},
{EM2874_R80_GPIO_P0_CTRL, 0xcf, 0xff, 0x0b},
{EM2874_R80_GPIO_P0_CTRL, 0xef, 0xff, 0x65},
{ -1, -1, -1, -1},
};
struct {
unsigned char r[4];
int len;
} regs[] = {
{{ 0x06, 0x02, 0x00, 0x31 }, 4},
{{ 0x01, 0x02 }, 2},
{{ 0x01, 0x02, 0x00, 0xc6 }, 4},
{{ 0x01, 0x00 }, 2},
{{ 0x01, 0x00, 0xff, 0xaf }, 4},
{{ 0x01, 0x00, 0x03, 0xa0 }, 4},
{{ 0x01, 0x00 }, 2},
{{ 0x01, 0x00, 0x73, 0xaf }, 4},
{{ 0x04, 0x00 }, 2},
{{ 0x00, 0x04 }, 2},
{{ 0x00, 0x04, 0x00, 0x0a }, 4},
{{ 0x04, 0x14 }, 2},
{{ 0x04, 0x14, 0x00, 0x00 }, 4},
};
em28xx_gpio_set(dev, hauppauge_hvr930c_init);
em28xx_write_reg(dev, EM28XX_R06_I2C_CLK, 0x40);
msleep(10);
em28xx_write_reg(dev, EM28XX_R06_I2C_CLK, 0x44);
msleep(10);
dev->i2c_client[dev->def_i2c_bus].addr = 0x82 >> 1;
for (i = 0; i < ARRAY_SIZE(regs); i++)
i2c_master_send(&dev->i2c_client[dev->def_i2c_bus], regs[i].r, regs[i].len);
em28xx_gpio_set(dev, hauppauge_hvr930c_end);
msleep(100);
em28xx_write_reg(dev, EM28XX_R06_I2C_CLK, 0x44);
msleep(30);
em28xx_write_reg(dev, EM28XX_R06_I2C_CLK, 0x45);
msleep(10);
}
static void terratec_h5_init(struct em28xx *dev)
{
int i;
struct em28xx_reg_seq terratec_h5_init[] = {
{EM2820_R08_GPIO_CTRL, 0xff, 0xff, 10},
{EM2874_R80_GPIO_P0_CTRL, 0xf6, 0xff, 100},
{EM2874_R80_GPIO_P0_CTRL, 0xf2, 0xff, 50},
{EM2874_R80_GPIO_P0_CTRL, 0xf6, 0xff, 100},
{ -1, -1, -1, -1},
};
struct em28xx_reg_seq terratec_h5_end[] = {
{EM2874_R80_GPIO_P0_CTRL, 0xe6, 0xff, 100},
{EM2874_R80_GPIO_P0_CTRL, 0xa6, 0xff, 50},
{EM2874_R80_GPIO_P0_CTRL, 0xe6, 0xff, 100},
{ -1, -1, -1, -1},
};
struct {
unsigned char r[4];
int len;
} regs[] = {
{{ 0x06, 0x02, 0x00, 0x31 }, 4},
{{ 0x01, 0x02 }, 2},
{{ 0x01, 0x02, 0x00, 0xc6 }, 4},
{{ 0x01, 0x00 }, 2},
{{ 0x01, 0x00, 0xff, 0xaf }, 4},
{{ 0x01, 0x00, 0x03, 0xa0 }, 4},
{{ 0x01, 0x00 }, 2},
{{ 0x01, 0x00, 0x73, 0xaf }, 4},
{{ 0x04, 0x00 }, 2},
{{ 0x00, 0x04 }, 2},
{{ 0x00, 0x04, 0x00, 0x0a }, 4},
{{ 0x04, 0x14 }, 2},
{{ 0x04, 0x14, 0x00, 0x00 }, 4},
};
em28xx_gpio_set(dev, terratec_h5_init);
em28xx_write_reg(dev, EM28XX_R06_I2C_CLK, 0x40);
msleep(10);
em28xx_write_reg(dev, EM28XX_R06_I2C_CLK, 0x45);
msleep(10);
dev->i2c_client[dev->def_i2c_bus].addr = 0x82 >> 1;
for (i = 0; i < ARRAY_SIZE(regs); i++)
i2c_master_send(&dev->i2c_client[dev->def_i2c_bus], regs[i].r, regs[i].len);
em28xx_gpio_set(dev, terratec_h5_end);
}
static void terratec_htc_stick_init(struct em28xx *dev)
{
int i;
struct em28xx_reg_seq terratec_htc_stick_init[] = {
{EM2820_R08_GPIO_CTRL, 0xff, 0xff, 10},
{EM2874_R80_GPIO_P0_CTRL, 0xf6, 0xff, 100},
{EM2874_R80_GPIO_P0_CTRL, 0xe6, 0xff, 50},
{EM2874_R80_GPIO_P0_CTRL, 0xf6, 0xff, 100},
{ -1, -1, -1, -1},
};
struct em28xx_reg_seq terratec_htc_stick_end[] = {
{EM2874_R80_GPIO_P0_CTRL, 0xb6, 0xff, 100},
{EM2874_R80_GPIO_P0_CTRL, 0xf6, 0xff, 50},
{ -1, -1, -1, -1},
};
struct {
unsigned char r[4];
int len;
} regs[] = {
{{ 0x06, 0x02, 0x00, 0x31 }, 4},
{{ 0x01, 0x02 }, 2},
{{ 0x01, 0x02, 0x00, 0xc6 }, 4},
{{ 0x01, 0x00 }, 2},
{{ 0x01, 0x00, 0xff, 0xaf }, 4},
};
em28xx_gpio_set(dev, terratec_htc_stick_init);
em28xx_write_reg(dev, EM28XX_R06_I2C_CLK, 0x40);
msleep(10);
em28xx_write_reg(dev, EM28XX_R06_I2C_CLK, 0x44);
msleep(10);
dev->i2c_client[dev->def_i2c_bus].addr = 0x82 >> 1;
for (i = 0; i < ARRAY_SIZE(regs); i++)
i2c_master_send(&dev->i2c_client[dev->def_i2c_bus], regs[i].r, regs[i].len);
em28xx_gpio_set(dev, terratec_htc_stick_end);
}
static void terratec_htc_usb_xs_init(struct em28xx *dev)
{
int i;
struct em28xx_reg_seq terratec_htc_usb_xs_init[] = {
{EM2820_R08_GPIO_CTRL, 0xff, 0xff, 10},
{EM2874_R80_GPIO_P0_CTRL, 0xb2, 0xff, 100},
{EM2874_R80_GPIO_P0_CTRL, 0xb2, 0xff, 50},
{EM2874_R80_GPIO_P0_CTRL, 0xb6, 0xff, 100},
{ -1, -1, -1, -1},
};
struct em28xx_reg_seq terratec_htc_usb_xs_end[] = {
{EM2874_R80_GPIO_P0_CTRL, 0xa6, 0xff, 100},
{EM2874_R80_GPIO_P0_CTRL, 0xa6, 0xff, 50},
{EM2874_R80_GPIO_P0_CTRL, 0xe6, 0xff, 100},
{ -1, -1, -1, -1},
};
struct {
unsigned char r[4];
int len;
} regs[] = {
{{ 0x06, 0x02, 0x00, 0x31 }, 4},
{{ 0x01, 0x02 }, 2},
{{ 0x01, 0x02, 0x00, 0xc6 }, 4},
{{ 0x01, 0x00 }, 2},
{{ 0x01, 0x00, 0xff, 0xaf }, 4},
{{ 0x01, 0x00, 0x03, 0xa0 }, 4},
{{ 0x01, 0x00 }, 2},
{{ 0x01, 0x00, 0x73, 0xaf }, 4},
{{ 0x04, 0x00 }, 2},
{{ 0x00, 0x04 }, 2},
{{ 0x00, 0x04, 0x00, 0x0a }, 4},
{{ 0x04, 0x14 }, 2},
{{ 0x04, 0x14, 0x00, 0x00 }, 4},
};
em28xx_write_reg(dev, EM28XX_R06_I2C_CLK, 0x40);
em28xx_gpio_set(dev, terratec_htc_usb_xs_init);
em28xx_write_reg(dev, EM28XX_R06_I2C_CLK, 0x40);
msleep(10);
em28xx_write_reg(dev, EM28XX_R06_I2C_CLK, 0x44);
msleep(10);
dev->i2c_client[dev->def_i2c_bus].addr = 0x82 >> 1;
for (i = 0; i < ARRAY_SIZE(regs); i++)
i2c_master_send(&dev->i2c_client[dev->def_i2c_bus], regs[i].r, regs[i].len);
em28xx_gpio_set(dev, terratec_htc_usb_xs_end);
}
static void pctv_520e_init(struct em28xx *dev)
{
int i;
struct {
unsigned char r[4];
int len;
} regs[] = {
{{ 0x06, 0x02, 0x00, 0x31 }, 4},
{{ 0x01, 0x02 }, 2},
{{ 0x01, 0x02, 0x00, 0xc6 }, 4},
{{ 0x01, 0x00 }, 2},
{{ 0x01, 0x00, 0xff, 0xaf }, 4},
{{ 0x01, 0x00, 0x03, 0xa0 }, 4},
{{ 0x01, 0x00 }, 2},
{{ 0x01, 0x00, 0x73, 0xaf }, 4},
};
dev->i2c_client[dev->def_i2c_bus].addr = 0x82 >> 1;
for (i = 0; i < ARRAY_SIZE(regs); i++)
i2c_master_send(&dev->i2c_client[dev->def_i2c_bus], regs[i].r, regs[i].len);
}
static int em28xx_pctv_290e_set_lna(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct em28xx_i2c_bus *i2c_bus = fe->dvb->priv;
struct em28xx *dev = i2c_bus->dev;
#ifdef CONFIG_GPIOLIB
struct em28xx_dvb *dvb = dev->dvb;
int ret;
unsigned long flags;
if (c->lna == 1)
flags = GPIOF_OUT_INIT_HIGH;
else
flags = GPIOF_OUT_INIT_LOW;
ret = gpio_request_one(dvb->lna_gpio, flags, NULL);
if (ret)
dev_err(&dev->intf->dev, "gpio request failed %d\n", ret);
else
gpio_free(dvb->lna_gpio);
return ret;
#else
dev_warn(&dev->intf->dev, "%s: LNA control is disabled (lna=%u)\n",
KBUILD_MODNAME, c->lna);
return 0;
#endif
}
static int em28xx_pctv_292e_set_lna(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct em28xx_i2c_bus *i2c_bus = fe->dvb->priv;
struct em28xx *dev = i2c_bus->dev;
u8 lna;
if (c->lna == 1)
lna = 0x01;
else
lna = 0x00;
return em28xx_write_reg_bits(dev, EM2874_R80_GPIO_P0_CTRL, lna, 0x01);
}
static int em28xx_mt352_terratec_xs_init(struct dvb_frontend *fe)
{
static u8 clock_config[] = { CLOCK_CTL, 0x38, 0x2c };
static u8 reset[] = { RESET, 0x80 };
static u8 adc_ctl_1_cfg[] = { ADC_CTL_1, 0x40 };
static u8 agc_cfg[] = { AGC_TARGET, 0x28, 0xa0 };
static u8 input_freq_cfg[] = { INPUT_FREQ_1, 0x31, 0xb8 };
static u8 rs_err_cfg[] = { RS_ERR_PER_1, 0x00, 0x4d };
static u8 capt_range_cfg[] = { CAPT_RANGE, 0x32 };
static u8 trl_nom_cfg[] = { TRL_NOMINAL_RATE_1, 0x64, 0x00 };
static u8 tps_given_cfg[] = { TPS_GIVEN_1, 0x40, 0x80, 0x50 };
static u8 tuner_go[] = { TUNER_GO, 0x01};
mt352_write(fe, clock_config, sizeof(clock_config));
udelay(200);
mt352_write(fe, reset, sizeof(reset));
mt352_write(fe, adc_ctl_1_cfg, sizeof(adc_ctl_1_cfg));
mt352_write(fe, agc_cfg, sizeof(agc_cfg));
mt352_write(fe, input_freq_cfg, sizeof(input_freq_cfg));
mt352_write(fe, rs_err_cfg, sizeof(rs_err_cfg));
mt352_write(fe, capt_range_cfg, sizeof(capt_range_cfg));
mt352_write(fe, trl_nom_cfg, sizeof(trl_nom_cfg));
mt352_write(fe, tps_given_cfg, sizeof(tps_given_cfg));
mt352_write(fe, tuner_go, sizeof(tuner_go));
return 0;
}
static void px_bcud_init(struct em28xx *dev)
{
int i;
struct {
unsigned char r[4];
int len;
} regs1[] = {
{{ 0x0e, 0x77 }, 2},
{{ 0x0f, 0x77 }, 2},
{{ 0x03, 0x90 }, 2},
}, regs2[] = {
{{ 0x07, 0x01 }, 2},
{{ 0x08, 0x10 }, 2},
{{ 0x13, 0x00 }, 2},
{{ 0x17, 0x00 }, 2},
{{ 0x03, 0x01 }, 2},
{{ 0x10, 0xb1 }, 2},
{{ 0x11, 0x40 }, 2},
{{ 0x85, 0x7a }, 2},
{{ 0x87, 0x04 }, 2},
};
static struct em28xx_reg_seq gpio[] = {
{EM28XX_R06_I2C_CLK, 0x40, 0xff, 300},
{EM2874_R80_GPIO_P0_CTRL, 0xfd, 0xff, 60},
{EM28XX_R15_RGAIN, 0x20, 0xff, 0},
{EM28XX_R16_GGAIN, 0x20, 0xff, 0},
{EM28XX_R17_BGAIN, 0x20, 0xff, 0},
{EM28XX_R18_ROFFSET, 0x00, 0xff, 0},
{EM28XX_R19_GOFFSET, 0x00, 0xff, 0},
{EM28XX_R1A_BOFFSET, 0x00, 0xff, 0},
{EM28XX_R23_UOFFSET, 0x00, 0xff, 0},
{EM28XX_R24_VOFFSET, 0x00, 0xff, 0},
{EM28XX_R26_COMPR, 0x00, 0xff, 0},
{0x13, 0x08, 0xff, 0},
{EM28XX_R12_VINENABLE, 0x27, 0xff, 0},
{EM28XX_R0C_USBSUSP, 0x10, 0xff, 0},
{EM28XX_R27_OUTFMT, 0x00, 0xff, 0},
{EM28XX_R10_VINMODE, 0x00, 0xff, 0},
{EM28XX_R11_VINCTRL, 0x11, 0xff, 0},
{EM2874_R50_IR_CONFIG, 0x01, 0xff, 0},
{EM2874_R5F_TS_ENABLE, 0x80, 0xff, 0},
{EM28XX_R06_I2C_CLK, 0x46, 0xff, 0},
};
em28xx_write_reg(dev, EM28XX_R06_I2C_CLK, 0x46);
dev->dvb->i2c_client_demod->addr = 0x14;
for (i = 0; i < ARRAY_SIZE(regs1); i++)
i2c_master_send(dev->dvb->i2c_client_demod, regs1[i].r,
regs1[i].len);
dev->dvb->i2c_client_demod->addr = 0x15;
for (i = 0; i < ARRAY_SIZE(regs2); i++)
i2c_master_send(dev->dvb->i2c_client_demod, regs2[i].r,
regs2[i].len);
for (i = 0; i < ARRAY_SIZE(gpio); i++) {
em28xx_write_reg_bits(dev, gpio[i].reg, gpio[i].val,
gpio[i].mask);
if (gpio[i].sleep > 0)
msleep(gpio[i].sleep);
}
}
static int em28xx_attach_xc3028(u8 addr, struct em28xx *dev)
{
struct dvb_frontend *fe;
struct xc2028_config cfg;
struct xc2028_ctrl ctl;
memset(&cfg, 0, sizeof(cfg));
cfg.i2c_adap = &dev->i2c_adap[dev->def_i2c_bus];
cfg.i2c_addr = addr;
memset(&ctl, 0, sizeof(ctl));
em28xx_setup_xc3028(dev, &ctl);
cfg.ctrl = &ctl;
if (!dev->dvb->fe[0]) {
dev_err(&dev->intf->dev,
"dvb frontend not attached. Can't attach xc3028\n");
return -EINVAL;
}
fe = dvb_attach(xc2028_attach, dev->dvb->fe[0], &cfg);
if (!fe) {
dev_err(&dev->intf->dev, "xc3028 attach failed\n");
dvb_frontend_detach(dev->dvb->fe[0]);
dev->dvb->fe[0] = NULL;
return -EINVAL;
}
dev_info(&dev->intf->dev, "xc3028 attached\n");
return 0;
}
static int em28xx_register_dvb(struct em28xx_dvb *dvb, struct module *module,
struct em28xx *dev, struct device *device)
{
int result;
bool create_rf_connector = false;
mutex_init(&dvb->lock);
result = dvb_register_adapter(&dvb->adapter,
dev_name(&dev->intf->dev), module,
device, adapter_nr);
if (result < 0) {
dev_warn(&dev->intf->dev,
"dvb_register_adapter failed (errno = %d)\n",
result);
goto fail_adapter;
}
#ifdef CONFIG_MEDIA_CONTROLLER_DVB
dvb->adapter.mdev = dev->media_dev;
#endif
dvb->fe[0]->ops.ts_bus_ctrl = em28xx_dvb_bus_ctrl;
if (dvb->fe[1])
dvb->fe[1]->ops.ts_bus_ctrl = em28xx_dvb_bus_ctrl;
dvb->adapter.priv = &dev->i2c_bus[dev->def_i2c_bus];
result = dvb_register_frontend(&dvb->adapter, dvb->fe[0]);
if (result < 0) {
dev_warn(&dev->intf->dev,
"dvb_register_frontend failed (errno = %d)\n",
result);
goto fail_frontend0;
}
if (dvb->fe[1]) {
result = dvb_register_frontend(&dvb->adapter, dvb->fe[1]);
if (result < 0) {
dev_warn(&dev->intf->dev,
"2nd dvb_register_frontend failed (errno = %d)\n",
result);
goto fail_frontend1;
}
}
dvb->demux.dmx.capabilities =
DMX_TS_FILTERING | DMX_SECTION_FILTERING |
DMX_MEMORY_BASED_FILTERING;
dvb->demux.priv = dvb;
dvb->demux.filternum = 256;
dvb->demux.feednum = 256;
dvb->demux.start_feed = em28xx_start_feed;
dvb->demux.stop_feed = em28xx_stop_feed;
result = dvb_dmx_init(&dvb->demux);
if (result < 0) {
dev_warn(&dev->intf->dev,
"dvb_dmx_init failed (errno = %d)\n",
result);
goto fail_dmx;
}
dvb->dmxdev.filternum = 256;
dvb->dmxdev.demux = &dvb->demux.dmx;
dvb->dmxdev.capabilities = 0;
result = dvb_dmxdev_init(&dvb->dmxdev, &dvb->adapter);
if (result < 0) {
dev_warn(&dev->intf->dev,
"dvb_dmxdev_init failed (errno = %d)\n",
result);
goto fail_dmxdev;
}
dvb->fe_hw.source = DMX_FRONTEND_0;
result = dvb->demux.dmx.add_frontend(&dvb->demux.dmx, &dvb->fe_hw);
if (result < 0) {
dev_warn(&dev->intf->dev,
"add_frontend failed (DMX_FRONTEND_0, errno = %d)\n",
result);
goto fail_fe_hw;
}
dvb->fe_mem.source = DMX_MEMORY_FE;
result = dvb->demux.dmx.add_frontend(&dvb->demux.dmx, &dvb->fe_mem);
if (result < 0) {
dev_warn(&dev->intf->dev,
"add_frontend failed (DMX_MEMORY_FE, errno = %d)\n",
result);
goto fail_fe_mem;
}
result = dvb->demux.dmx.connect_frontend(&dvb->demux.dmx, &dvb->fe_hw);
if (result < 0) {
dev_warn(&dev->intf->dev,
"connect_frontend failed (errno = %d)\n",
result);
goto fail_fe_conn;
}
dvb_net_init(&dvb->adapter, &dvb->net, &dvb->demux.dmx);
if (!dev->has_video || (dev->tuner_type == TUNER_ABSENT))
create_rf_connector = true;
result = dvb_create_media_graph(&dvb->adapter, create_rf_connector);
if (result < 0)
goto fail_create_graph;
return 0;
fail_create_graph:
dvb_net_release(&dvb->net);
fail_fe_conn:
dvb->demux.dmx.remove_frontend(&dvb->demux.dmx, &dvb->fe_mem);
fail_fe_mem:
dvb->demux.dmx.remove_frontend(&dvb->demux.dmx, &dvb->fe_hw);
fail_fe_hw:
dvb_dmxdev_release(&dvb->dmxdev);
fail_dmxdev:
dvb_dmx_release(&dvb->demux);
fail_dmx:
if (dvb->fe[1])
dvb_unregister_frontend(dvb->fe[1]);
dvb_unregister_frontend(dvb->fe[0]);
fail_frontend1:
if (dvb->fe[1])
dvb_frontend_detach(dvb->fe[1]);
fail_frontend0:
dvb_frontend_detach(dvb->fe[0]);
dvb_unregister_adapter(&dvb->adapter);
fail_adapter:
return result;
}
static void em28xx_unregister_dvb(struct em28xx_dvb *dvb)
{
dvb_net_release(&dvb->net);
dvb->demux.dmx.remove_frontend(&dvb->demux.dmx, &dvb->fe_mem);
dvb->demux.dmx.remove_frontend(&dvb->demux.dmx, &dvb->fe_hw);
dvb_dmxdev_release(&dvb->dmxdev);
dvb_dmx_release(&dvb->demux);
if (dvb->fe[1])
dvb_unregister_frontend(dvb->fe[1]);
dvb_unregister_frontend(dvb->fe[0]);
if (dvb->fe[1] && !dvb->dont_attach_fe1)
dvb_frontend_detach(dvb->fe[1]);
dvb_frontend_detach(dvb->fe[0]);
dvb_unregister_adapter(&dvb->adapter);
}
static int em28xx_dvb_init(struct em28xx *dev)
{
int result = 0;
struct em28xx_dvb *dvb;
if (dev->is_audio_only) {
return 0;
}
if (!dev->board.has_dvb) {
return 0;
}
dev_info(&dev->intf->dev, "Binding DVB extension\n");
dvb = kzalloc(sizeof(struct em28xx_dvb), GFP_KERNEL);
if (!dvb)
return -ENOMEM;
dev->dvb = dvb;
dvb->fe[0] = dvb->fe[1] = NULL;
if (dev->dvb_xfer_bulk) {
result = em28xx_alloc_urbs(dev, EM28XX_DIGITAL_MODE,
dev->dvb_xfer_bulk,
EM28XX_DVB_NUM_BUFS,
512,
EM28XX_DVB_BULK_PACKET_MULTIPLIER);
} else {
result = em28xx_alloc_urbs(dev, EM28XX_DIGITAL_MODE,
dev->dvb_xfer_bulk,
EM28XX_DVB_NUM_BUFS,
dev->dvb_max_pkt_size_isoc,
EM28XX_DVB_NUM_ISOC_PACKETS);
}
if (result) {
dev_err(&dev->intf->dev,
"failed to pre-allocate USB transfer buffers for DVB.\n");
kfree(dvb);
dev->dvb = NULL;
return result;
}
mutex_lock(&dev->lock);
em28xx_set_mode(dev, EM28XX_DIGITAL_MODE);
switch (dev->model) {
case EM2874_BOARD_LEADERSHIP_ISDBT:
dvb->fe[0] = dvb_attach(s921_attach,
&sharp_isdbt, &dev->i2c_adap[dev->def_i2c_bus]);
if (!dvb->fe[0]) {
result = -EINVAL;
goto out_free;
}
break;
case EM2883_BOARD_HAUPPAUGE_WINTV_HVR_850:
case EM2883_BOARD_HAUPPAUGE_WINTV_HVR_950:
case EM2880_BOARD_PINNACLE_PCTV_HD_PRO:
case EM2880_BOARD_AMD_ATI_TV_WONDER_HD_600:
dvb->fe[0] = dvb_attach(lgdt330x_attach,
&em2880_lgdt3303_dev,
&dev->i2c_adap[dev->def_i2c_bus]);
if (em28xx_attach_xc3028(0x61, dev) < 0) {
result = -EINVAL;
goto out_free;
}
break;
case EM2880_BOARD_KWORLD_DVB_310U:
dvb->fe[0] = dvb_attach(zl10353_attach,
&em28xx_zl10353_with_xc3028,
&dev->i2c_adap[dev->def_i2c_bus]);
if (em28xx_attach_xc3028(0x61, dev) < 0) {
result = -EINVAL;
goto out_free;
}
break;
case EM2880_BOARD_HAUPPAUGE_WINTV_HVR_900:
case EM2882_BOARD_TERRATEC_HYBRID_XS:
case EM2880_BOARD_EMPIRE_DUAL_TV:
dvb->fe[0] = dvb_attach(zl10353_attach,
&em28xx_zl10353_xc3028_no_i2c_gate,
&dev->i2c_adap[dev->def_i2c_bus]);
if (em28xx_attach_xc3028(0x61, dev) < 0) {
result = -EINVAL;
goto out_free;
}
break;
case EM2880_BOARD_TERRATEC_HYBRID_XS:
case EM2880_BOARD_TERRATEC_HYBRID_XS_FR:
case EM2881_BOARD_PINNACLE_HYBRID_PRO:
case EM2882_BOARD_DIKOM_DK300:
case EM2882_BOARD_KWORLD_VS_DVBT:
dvb->fe[0] = dvb_attach(zl10353_attach,
&em28xx_zl10353_xc3028_no_i2c_gate,
&dev->i2c_adap[dev->def_i2c_bus]);
if (dvb->fe[0] == NULL) {
dvb->fe[0] = dvb_attach(mt352_attach,
&terratec_xs_mt352_cfg,
&dev->i2c_adap[dev->def_i2c_bus]);
}
if (em28xx_attach_xc3028(0x61, dev) < 0) {
result = -EINVAL;
goto out_free;
}
break;
case EM2870_BOARD_TERRATEC_XS_MT2060:
dvb->fe[0] = dvb_attach(zl10353_attach,
&em28xx_zl10353_no_i2c_gate_dev,
&dev->i2c_adap[dev->def_i2c_bus]);
if (dvb->fe[0] != NULL) {
dvb_attach(mt2060_attach, dvb->fe[0],
&dev->i2c_adap[dev->def_i2c_bus],
&em28xx_mt2060_config, 1220);
}
break;
case EM2870_BOARD_KWORLD_355U:
dvb->fe[0] = dvb_attach(zl10353_attach,
&em28xx_zl10353_no_i2c_gate_dev,
&dev->i2c_adap[dev->def_i2c_bus]);
if (dvb->fe[0] != NULL)
dvb_attach(qt1010_attach, dvb->fe[0],
&dev->i2c_adap[dev->def_i2c_bus], &em28xx_qt1010_config);
break;
case EM2883_BOARD_KWORLD_HYBRID_330U:
case EM2882_BOARD_EVGA_INDTUBE:
dvb->fe[0] = dvb_attach(s5h1409_attach,
&em28xx_s5h1409_with_xc3028,
&dev->i2c_adap[dev->def_i2c_bus]);
if (em28xx_attach_xc3028(0x61, dev) < 0) {
result = -EINVAL;
goto out_free;
}
break;
case EM2882_BOARD_KWORLD_ATSC_315U:
dvb->fe[0] = dvb_attach(lgdt330x_attach,
&em2880_lgdt3303_dev,
&dev->i2c_adap[dev->def_i2c_bus]);
if (dvb->fe[0] != NULL) {
if (!dvb_attach(simple_tuner_attach, dvb->fe[0],
&dev->i2c_adap[dev->def_i2c_bus],
0x61, TUNER_THOMSON_DTT761X)) {
result = -EINVAL;
goto out_free;
}
}
break;
case EM2880_BOARD_HAUPPAUGE_WINTV_HVR_900_R2:
case EM2882_BOARD_PINNACLE_HYBRID_PRO_330E:
dvb->fe[0] = dvb_attach(drxd_attach, &em28xx_drxd, NULL,
&dev->i2c_adap[dev->def_i2c_bus],
&dev->intf->dev);
if (em28xx_attach_xc3028(0x61, dev) < 0) {
result = -EINVAL;
goto out_free;
}
break;
case EM2870_BOARD_REDDO_DVB_C_USB_BOX:
dvb->fe[0] = dvb_attach(tda10023_attach,
&em28xx_tda10023_config,
&dev->i2c_adap[dev->def_i2c_bus], 0x48);
if (dvb->fe[0]) {
if (!dvb_attach(simple_tuner_attach, dvb->fe[0],
&dev->i2c_adap[dev->def_i2c_bus],
0x60, TUNER_PHILIPS_CU1216L)) {
result = -EINVAL;
goto out_free;
}
}
break;
case EM2870_BOARD_KWORLD_A340:
dvb->fe[0] = dvb_attach(lgdt3305_attach,
&em2870_lgdt3304_dev,
&dev->i2c_adap[dev->def_i2c_bus]);
if (!dvb->fe[0]) {
result = -EINVAL;
goto out_free;
}
if (!dvb_attach(tda18271_attach, dvb->fe[0], 0x60,
&dev->i2c_adap[dev->def_i2c_bus],
&kworld_a340_config)) {
dvb_frontend_detach(dvb->fe[0]);
result = -EINVAL;
goto out_free;
}
break;
case EM28174_BOARD_PCTV_290E:
dvb->lna_gpio = CXD2820R_GPIO_E | CXD2820R_GPIO_O |
CXD2820R_GPIO_L;
dvb->fe[0] = dvb_attach(cxd2820r_attach,
&em28xx_cxd2820r_config,
&dev->i2c_adap[dev->def_i2c_bus],
&dvb->lna_gpio);
if (dvb->fe[0]) {
if (!dvb_attach(tda18271_attach,
dvb->fe[0],
0x60,
&dev->i2c_adap[dev->def_i2c_bus],
&em28xx_cxd2820r_tda18271_config)) {
dvb_frontend_detach(dvb->fe[0]);
result = -EINVAL;
goto out_free;
}
#ifdef CONFIG_GPIOLIB
result = gpio_request_one(dvb->lna_gpio,
GPIOF_OUT_INIT_LOW, NULL);
if (result)
dev_err(&dev->intf->dev,
"gpio request failed %d\n",
result);
else
gpio_free(dvb->lna_gpio);
result = 0;
#endif
dvb->fe[0]->ops.set_lna = em28xx_pctv_290e_set_lna;
}
break;
case EM2884_BOARD_HAUPPAUGE_WINTV_HVR_930C:
{
struct xc5000_config cfg;
hauppauge_hvr930c_init(dev);
dvb->fe[0] = dvb_attach(drxk_attach,
&hauppauge_930c_drxk, &dev->i2c_adap[dev->def_i2c_bus]);
if (!dvb->fe[0]) {
result = -EINVAL;
goto out_free;
}
dvb->fe[0]->sec_priv = dvb;
sema_init(&dvb->pll_mutex, 1);
dvb->gate_ctrl = dvb->fe[0]->ops.i2c_gate_ctrl;
dvb->fe[0]->ops.i2c_gate_ctrl = drxk_gate_ctrl;
memset(&cfg, 0, sizeof(cfg));
cfg.i2c_address = 0x61;
cfg.if_khz = 4000;
if (dvb->fe[0]->ops.i2c_gate_ctrl)
dvb->fe[0]->ops.i2c_gate_ctrl(dvb->fe[0], 1);
if (!dvb_attach(xc5000_attach, dvb->fe[0], &dev->i2c_adap[dev->def_i2c_bus],
&cfg)) {
result = -EINVAL;
goto out_free;
}
if (dvb->fe[0]->ops.i2c_gate_ctrl)
dvb->fe[0]->ops.i2c_gate_ctrl(dvb->fe[0], 0);
break;
}
case EM2884_BOARD_TERRATEC_H5:
terratec_h5_init(dev);
dvb->fe[0] = dvb_attach(drxk_attach, &terratec_h5_drxk, &dev->i2c_adap[dev->def_i2c_bus]);
if (!dvb->fe[0]) {
result = -EINVAL;
goto out_free;
}
dvb->fe[0]->sec_priv = dvb;
sema_init(&dvb->pll_mutex, 1);
dvb->gate_ctrl = dvb->fe[0]->ops.i2c_gate_ctrl;
dvb->fe[0]->ops.i2c_gate_ctrl = drxk_gate_ctrl;
if (dvb->fe[0]->ops.i2c_gate_ctrl)
dvb->fe[0]->ops.i2c_gate_ctrl(dvb->fe[0], 1);
if (!dvb_attach(tda18271c2dd_attach, dvb->fe[0], &dev->i2c_adap[dev->def_i2c_bus], 0x60)) {
result = -EINVAL;
goto out_free;
}
if (dvb->fe[0]->ops.i2c_gate_ctrl)
dvb->fe[0]->ops.i2c_gate_ctrl(dvb->fe[0], 0);
break;
case EM2884_BOARD_C3TECH_DIGITAL_DUO:
dvb->fe[0] = dvb_attach(mb86a20s_attach,
&c3tech_duo_mb86a20s_config,
&dev->i2c_adap[dev->def_i2c_bus]);
if (dvb->fe[0] != NULL)
dvb_attach(tda18271_attach, dvb->fe[0], 0x60,
&dev->i2c_adap[dev->def_i2c_bus],
&c3tech_duo_tda18271_config);
break;
case EM28174_BOARD_PCTV_460E: {
struct i2c_client *client;
struct i2c_board_info board_info;
struct tda10071_platform_data tda10071_pdata = {};
struct a8293_platform_data a8293_pdata = {};
tda10071_pdata.clk = 40444000,
tda10071_pdata.i2c_wr_max = 64,
tda10071_pdata.ts_mode = TDA10071_TS_SERIAL,
tda10071_pdata.pll_multiplier = 20,
tda10071_pdata.tuner_i2c_addr = 0x14,
memset(&board_info, 0, sizeof(board_info));
strlcpy(board_info.type, "tda10071_cx24118", I2C_NAME_SIZE);
board_info.addr = 0x55;
board_info.platform_data = &tda10071_pdata;
request_module("tda10071");
client = i2c_new_device(&dev->i2c_adap[dev->def_i2c_bus], &board_info);
if (client == NULL || client->dev.driver == NULL) {
result = -ENODEV;
goto out_free;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
result = -ENODEV;
goto out_free;
}
dvb->fe[0] = tda10071_pdata.get_dvb_frontend(client);
dvb->i2c_client_demod = client;
a8293_pdata.dvb_frontend = dvb->fe[0];
memset(&board_info, 0, sizeof(board_info));
strlcpy(board_info.type, "a8293", I2C_NAME_SIZE);
board_info.addr = 0x08;
board_info.platform_data = &a8293_pdata;
request_module("a8293");
client = i2c_new_device(&dev->i2c_adap[dev->def_i2c_bus], &board_info);
if (client == NULL || client->dev.driver == NULL) {
module_put(dvb->i2c_client_demod->dev.driver->owner);
i2c_unregister_device(dvb->i2c_client_demod);
result = -ENODEV;
goto out_free;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
module_put(dvb->i2c_client_demod->dev.driver->owner);
i2c_unregister_device(dvb->i2c_client_demod);
result = -ENODEV;
goto out_free;
}
dvb->i2c_client_sec = client;
break;
}
case EM2874_BOARD_DELOCK_61959:
case EM2874_BOARD_MAXMEDIA_UB425_TC:
dvb->fe[0] = dvb_attach(drxk_attach, &maxmedia_ub425_tc_drxk,
&dev->i2c_adap[dev->def_i2c_bus]);
if (dvb->fe[0]) {
dvb->fe[0]->ops.i2c_gate_ctrl = NULL;
if (!dvb_attach(tda18271_attach, dvb->fe[0], 0x60,
&dev->i2c_adap[dev->def_i2c_bus],
&em28xx_cxd2820r_tda18271_config)) {
dvb_frontend_detach(dvb->fe[0]);
result = -EINVAL;
goto out_free;
}
}
break;
case EM2884_BOARD_PCTV_510E:
case EM2884_BOARD_PCTV_520E:
pctv_520e_init(dev);
dvb->fe[0] = dvb_attach(drxk_attach, &pctv_520e_drxk,
&dev->i2c_adap[dev->def_i2c_bus]);
if (dvb->fe[0]) {
if (!dvb_attach(tda18271_attach, dvb->fe[0], 0x60,
&dev->i2c_adap[dev->def_i2c_bus],
&em28xx_cxd2820r_tda18271_config)) {
dvb_frontend_detach(dvb->fe[0]);
result = -EINVAL;
goto out_free;
}
}
break;
case EM2884_BOARD_ELGATO_EYETV_HYBRID_2008:
case EM2884_BOARD_CINERGY_HTC_STICK:
terratec_htc_stick_init(dev);
dvb->fe[0] = dvb_attach(drxk_attach, &terratec_htc_stick_drxk,
&dev->i2c_adap[dev->def_i2c_bus]);
if (!dvb->fe[0]) {
result = -EINVAL;
goto out_free;
}
if (!dvb_attach(tda18271_attach, dvb->fe[0], 0x60,
&dev->i2c_adap[dev->def_i2c_bus],
&em28xx_cxd2820r_tda18271_config)) {
result = -EINVAL;
goto out_free;
}
break;
case EM2884_BOARD_TERRATEC_HTC_USB_XS:
terratec_htc_usb_xs_init(dev);
dvb->fe[0] = dvb_attach(drxk_attach, &terratec_htc_stick_drxk,
&dev->i2c_adap[dev->def_i2c_bus]);
if (!dvb->fe[0]) {
result = -EINVAL;
goto out_free;
}
if (!dvb_attach(tda18271_attach, dvb->fe[0], 0x60,
&dev->i2c_adap[dev->def_i2c_bus],
&em28xx_cxd2820r_tda18271_config)) {
result = -EINVAL;
goto out_free;
}
break;
case EM2874_BOARD_KWORLD_UB435Q_V2:
dvb->fe[0] = dvb_attach(lgdt3305_attach,
&em2874_lgdt3305_dev,
&dev->i2c_adap[dev->def_i2c_bus]);
if (!dvb->fe[0]) {
result = -EINVAL;
goto out_free;
}
if (!dvb_attach(tda18271_attach, dvb->fe[0], 0x60,
&dev->i2c_adap[dev->def_i2c_bus],
&kworld_ub435q_v2_config)) {
result = -EINVAL;
goto out_free;
}
break;
case EM2874_BOARD_KWORLD_UB435Q_V3:
{
struct i2c_client *client;
struct i2c_adapter *adapter = &dev->i2c_adap[dev->def_i2c_bus];
struct i2c_board_info board_info = {
.type = "tda18212",
.addr = 0x60,
.platform_data = &kworld_ub435q_v3_config,
};
dvb->fe[0] = dvb_attach(lgdt3305_attach,
&em2874_lgdt3305_nogate_dev,
&dev->i2c_adap[dev->def_i2c_bus]);
if (!dvb->fe[0]) {
result = -EINVAL;
goto out_free;
}
kworld_ub435q_v3_config.fe = dvb->fe[0];
request_module("tda18212");
client = i2c_new_device(adapter, &board_info);
if (client == NULL || client->dev.driver == NULL) {
dvb_frontend_detach(dvb->fe[0]);
result = -ENODEV;
goto out_free;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
dvb_frontend_detach(dvb->fe[0]);
result = -ENODEV;
goto out_free;
}
dvb->i2c_client_tuner = client;
break;
}
case EM2874_BOARD_PCTV_HD_MINI_80E:
dvb->fe[0] = dvb_attach(drx39xxj_attach, &dev->i2c_adap[dev->def_i2c_bus]);
if (dvb->fe[0] != NULL) {
dvb->fe[0] = dvb_attach(tda18271_attach, dvb->fe[0], 0x60,
&dev->i2c_adap[dev->def_i2c_bus],
&pinnacle_80e_dvb_config);
if (!dvb->fe[0]) {
result = -EINVAL;
goto out_free;
}
}
break;
case EM28178_BOARD_PCTV_461E: {
struct i2c_client *client;
struct i2c_adapter *i2c_adapter;
struct i2c_board_info board_info;
struct m88ds3103_platform_data m88ds3103_pdata = {};
struct ts2020_config ts2020_config = {};
struct a8293_platform_data a8293_pdata = {};
m88ds3103_pdata.clk = 27000000;
m88ds3103_pdata.i2c_wr_max = 33;
m88ds3103_pdata.ts_mode = M88DS3103_TS_PARALLEL;
m88ds3103_pdata.ts_clk = 16000;
m88ds3103_pdata.ts_clk_pol = 1;
m88ds3103_pdata.agc = 0x99;
memset(&board_info, 0, sizeof(board_info));
strlcpy(board_info.type, "m88ds3103", I2C_NAME_SIZE);
board_info.addr = 0x68;
board_info.platform_data = &m88ds3103_pdata;
request_module("m88ds3103");
client = i2c_new_device(&dev->i2c_adap[dev->def_i2c_bus], &board_info);
if (client == NULL || client->dev.driver == NULL) {
result = -ENODEV;
goto out_free;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
result = -ENODEV;
goto out_free;
}
dvb->fe[0] = m88ds3103_pdata.get_dvb_frontend(client);
i2c_adapter = m88ds3103_pdata.get_i2c_adapter(client);
dvb->i2c_client_demod = client;
ts2020_config.fe = dvb->fe[0];
memset(&board_info, 0, sizeof(board_info));
strlcpy(board_info.type, "ts2022", I2C_NAME_SIZE);
board_info.addr = 0x60;
board_info.platform_data = &ts2020_config;
request_module("ts2020");
client = i2c_new_device(i2c_adapter, &board_info);
if (client == NULL || client->dev.driver == NULL) {
module_put(dvb->i2c_client_demod->dev.driver->owner);
i2c_unregister_device(dvb->i2c_client_demod);
result = -ENODEV;
goto out_free;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
module_put(dvb->i2c_client_demod->dev.driver->owner);
i2c_unregister_device(dvb->i2c_client_demod);
result = -ENODEV;
goto out_free;
}
dvb->i2c_client_tuner = client;
dvb->fe[0]->ops.read_signal_strength =
dvb->fe[0]->ops.tuner_ops.get_rf_strength;
a8293_pdata.dvb_frontend = dvb->fe[0];
memset(&board_info, 0, sizeof(board_info));
strlcpy(board_info.type, "a8293", I2C_NAME_SIZE);
board_info.addr = 0x08;
board_info.platform_data = &a8293_pdata;
request_module("a8293");
client = i2c_new_device(&dev->i2c_adap[dev->def_i2c_bus], &board_info);
if (client == NULL || client->dev.driver == NULL) {
module_put(dvb->i2c_client_tuner->dev.driver->owner);
i2c_unregister_device(dvb->i2c_client_tuner);
module_put(dvb->i2c_client_demod->dev.driver->owner);
i2c_unregister_device(dvb->i2c_client_demod);
result = -ENODEV;
goto out_free;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
module_put(dvb->i2c_client_tuner->dev.driver->owner);
i2c_unregister_device(dvb->i2c_client_tuner);
module_put(dvb->i2c_client_demod->dev.driver->owner);
i2c_unregister_device(dvb->i2c_client_demod);
result = -ENODEV;
goto out_free;
}
dvb->i2c_client_sec = client;
break;
}
case EM28178_BOARD_PCTV_292E:
{
struct i2c_adapter *adapter;
struct i2c_client *client;
struct i2c_board_info info;
struct si2168_config si2168_config;
struct si2157_config si2157_config;
memset(&si2168_config, 0, sizeof(si2168_config));
si2168_config.i2c_adapter = &adapter;
si2168_config.fe = &dvb->fe[0];
si2168_config.ts_mode = SI2168_TS_PARALLEL;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2168", I2C_NAME_SIZE);
info.addr = 0x64;
info.platform_data = &si2168_config;
request_module(info.type);
client = i2c_new_device(&dev->i2c_adap[dev->def_i2c_bus], &info);
if (client == NULL || client->dev.driver == NULL) {
result = -ENODEV;
goto out_free;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
result = -ENODEV;
goto out_free;
}
dvb->i2c_client_demod = client;
memset(&si2157_config, 0, sizeof(si2157_config));
si2157_config.fe = dvb->fe[0];
si2157_config.if_port = 1;
#ifdef CONFIG_MEDIA_CONTROLLER_DVB
si2157_config.mdev = dev->media_dev;
#endif
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2157", I2C_NAME_SIZE);
info.addr = 0x60;
info.platform_data = &si2157_config;
request_module(info.type);
client = i2c_new_device(adapter, &info);
if (client == NULL || client->dev.driver == NULL) {
module_put(dvb->i2c_client_demod->dev.driver->owner);
i2c_unregister_device(dvb->i2c_client_demod);
result = -ENODEV;
goto out_free;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
module_put(dvb->i2c_client_demod->dev.driver->owner);
i2c_unregister_device(dvb->i2c_client_demod);
result = -ENODEV;
goto out_free;
}
dvb->i2c_client_tuner = client;
dvb->fe[0]->ops.set_lna = em28xx_pctv_292e_set_lna;
}
break;
case EM28178_BOARD_TERRATEC_T2_STICK_HD:
{
struct i2c_adapter *adapter;
struct i2c_client *client;
struct i2c_board_info info;
struct si2168_config si2168_config;
struct si2157_config si2157_config;
memset(&si2168_config, 0, sizeof(si2168_config));
si2168_config.i2c_adapter = &adapter;
si2168_config.fe = &dvb->fe[0];
si2168_config.ts_mode = SI2168_TS_PARALLEL;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2168", I2C_NAME_SIZE);
info.addr = 0x64;
info.platform_data = &si2168_config;
request_module(info.type);
client = i2c_new_device(&dev->i2c_adap[dev->def_i2c_bus], &info);
if (client == NULL || client->dev.driver == NULL) {
result = -ENODEV;
goto out_free;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
result = -ENODEV;
goto out_free;
}
dvb->i2c_client_demod = client;
memset(&si2157_config, 0, sizeof(si2157_config));
si2157_config.fe = dvb->fe[0];
si2157_config.if_port = 0;
#ifdef CONFIG_MEDIA_CONTROLLER_DVB
si2157_config.mdev = dev->media_dev;
#endif
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2146", I2C_NAME_SIZE);
info.addr = 0x60;
info.platform_data = &si2157_config;
request_module("si2157");
client = i2c_new_device(adapter, &info);
if (client == NULL || client->dev.driver == NULL) {
module_put(dvb->i2c_client_demod->dev.driver->owner);
i2c_unregister_device(dvb->i2c_client_demod);
result = -ENODEV;
goto out_free;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
module_put(dvb->i2c_client_demod->dev.driver->owner);
i2c_unregister_device(dvb->i2c_client_demod);
result = -ENODEV;
goto out_free;
}
dvb->i2c_client_tuner = client;
}
break;
case EM28178_BOARD_PLEX_PX_BCUD:
{
struct i2c_client *client;
struct i2c_board_info info;
struct tc90522_config tc90522_config;
struct qm1d1c0042_config qm1d1c0042_config;
memset(&tc90522_config, 0, sizeof(tc90522_config));
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "tc90522sat", I2C_NAME_SIZE);
info.addr = 0x15;
info.platform_data = &tc90522_config;
request_module("tc90522");
client = i2c_new_device(&dev->i2c_adap[dev->def_i2c_bus], &info);
if (client == NULL || client->dev.driver == NULL) {
result = -ENODEV;
goto out_free;
}
dvb->i2c_client_demod = client;
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
result = -ENODEV;
goto out_free;
}
memset(&qm1d1c0042_config, 0,
sizeof(qm1d1c0042_config));
qm1d1c0042_config.fe = tc90522_config.fe;
qm1d1c0042_config.lpf = 1;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "qm1d1c0042", I2C_NAME_SIZE);
info.addr = 0x61;
info.platform_data = &qm1d1c0042_config;
request_module(info.type);
client = i2c_new_device(tc90522_config.tuner_i2c,
&info);
if (client == NULL || client->dev.driver == NULL) {
module_put(dvb->i2c_client_demod->dev.driver->owner);
i2c_unregister_device(dvb->i2c_client_demod);
result = -ENODEV;
goto out_free;
}
dvb->i2c_client_tuner = client;
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
module_put(dvb->i2c_client_demod->dev.driver->owner);
i2c_unregister_device(dvb->i2c_client_demod);
result = -ENODEV;
goto out_free;
}
dvb->fe[0] = tc90522_config.fe;
px_bcud_init(dev);
}
break;
case EM28174_BOARD_HAUPPAUGE_WINTV_DUALHD_DVB:
{
struct i2c_adapter *adapter;
struct i2c_client *client;
struct i2c_board_info info;
struct si2168_config si2168_config;
struct si2157_config si2157_config;
memset(&si2168_config, 0, sizeof(si2168_config));
si2168_config.i2c_adapter = &adapter;
si2168_config.fe = &dvb->fe[0];
si2168_config.ts_mode = SI2168_TS_SERIAL;
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2168", I2C_NAME_SIZE);
info.addr = 0x64;
info.platform_data = &si2168_config;
request_module(info.type);
client = i2c_new_device(&dev->i2c_adap[dev->def_i2c_bus], &info);
if (client == NULL || client->dev.driver == NULL) {
result = -ENODEV;
goto out_free;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
result = -ENODEV;
goto out_free;
}
dvb->i2c_client_demod = client;
memset(&si2157_config, 0, sizeof(si2157_config));
si2157_config.fe = dvb->fe[0];
si2157_config.if_port = 1;
#ifdef CONFIG_MEDIA_CONTROLLER_DVB
si2157_config.mdev = dev->media_dev;
#endif
memset(&info, 0, sizeof(struct i2c_board_info));
strlcpy(info.type, "si2157", I2C_NAME_SIZE);
info.addr = 0x60;
info.platform_data = &si2157_config;
request_module(info.type);
client = i2c_new_device(adapter, &info);
if (client == NULL || client->dev.driver == NULL) {
module_put(dvb->i2c_client_demod->dev.driver->owner);
i2c_unregister_device(dvb->i2c_client_demod);
result = -ENODEV;
goto out_free;
}
if (!try_module_get(client->dev.driver->owner)) {
i2c_unregister_device(client);
module_put(dvb->i2c_client_demod->dev.driver->owner);
i2c_unregister_device(dvb->i2c_client_demod);
result = -ENODEV;
goto out_free;
}
dvb->i2c_client_tuner = client;
}
break;
default:
dev_err(&dev->intf->dev,
"The frontend of your DVB/ATSC card isn't supported yet\n");
break;
}
if (NULL == dvb->fe[0]) {
dev_err(&dev->intf->dev, "frontend initialization failed\n");
result = -EINVAL;
goto out_free;
}
dvb->fe[0]->callback = em28xx_tuner_callback;
if (dvb->fe[1])
dvb->fe[1]->callback = em28xx_tuner_callback;
result = em28xx_register_dvb(dvb, THIS_MODULE, dev, &dev->intf->dev);
if (result < 0)
goto out_free;
dev_info(&dev->intf->dev, "DVB extension successfully initialized\n");
kref_get(&dev->ref);
ret:
em28xx_set_mode(dev, EM28XX_SUSPEND);
mutex_unlock(&dev->lock);
return result;
out_free:
kfree(dvb);
dev->dvb = NULL;
goto ret;
}
static inline void prevent_sleep(struct dvb_frontend_ops *ops)
{
ops->set_voltage = NULL;
ops->sleep = NULL;
ops->tuner_ops.sleep = NULL;
}
static int em28xx_dvb_fini(struct em28xx *dev)
{
struct em28xx_dvb *dvb;
struct i2c_client *client;
if (dev->is_audio_only) {
return 0;
}
if (!dev->board.has_dvb) {
return 0;
}
if (!dev->dvb)
return 0;
dev_info(&dev->intf->dev, "Closing DVB extension\n");
dvb = dev->dvb;
em28xx_uninit_usb_xfer(dev, EM28XX_DIGITAL_MODE);
if (dev->disconnected) {
if (dvb->fe[0]) {
prevent_sleep(&dvb->fe[0]->ops);
dvb->fe[0]->exit = DVB_FE_DEVICE_REMOVED;
}
if (dvb->fe[1]) {
prevent_sleep(&dvb->fe[1]->ops);
dvb->fe[1]->exit = DVB_FE_DEVICE_REMOVED;
}
}
client = dvb->i2c_client_sec;
if (client) {
module_put(client->dev.driver->owner);
i2c_unregister_device(client);
}
client = dvb->i2c_client_tuner;
if (client) {
module_put(client->dev.driver->owner);
i2c_unregister_device(client);
}
client = dvb->i2c_client_demod;
if (client) {
module_put(client->dev.driver->owner);
i2c_unregister_device(client);
}
em28xx_unregister_dvb(dvb);
kfree(dvb);
dev->dvb = NULL;
kref_put(&dev->ref, em28xx_free_device);
return 0;
}
static int em28xx_dvb_suspend(struct em28xx *dev)
{
int ret = 0;
if (dev->is_audio_only)
return 0;
if (!dev->board.has_dvb)
return 0;
dev_info(&dev->intf->dev, "Suspending DVB extension\n");
if (dev->dvb) {
struct em28xx_dvb *dvb = dev->dvb;
if (dvb->fe[0]) {
ret = dvb_frontend_suspend(dvb->fe[0]);
dev_info(&dev->intf->dev, "fe0 suspend %d\n", ret);
}
if (dvb->fe[1]) {
dvb_frontend_suspend(dvb->fe[1]);
dev_info(&dev->intf->dev, "fe1 suspend %d\n", ret);
}
}
return 0;
}
static int em28xx_dvb_resume(struct em28xx *dev)
{
int ret = 0;
if (dev->is_audio_only)
return 0;
if (!dev->board.has_dvb)
return 0;
dev_info(&dev->intf->dev, "Resuming DVB extension\n");
if (dev->dvb) {
struct em28xx_dvb *dvb = dev->dvb;
if (dvb->fe[0]) {
ret = dvb_frontend_resume(dvb->fe[0]);
dev_info(&dev->intf->dev, "fe0 resume %d\n", ret);
}
if (dvb->fe[1]) {
ret = dvb_frontend_resume(dvb->fe[1]);
dev_info(&dev->intf->dev, "fe1 resume %d\n", ret);
}
}
return 0;
}
static int __init em28xx_dvb_register(void)
{
return em28xx_register_extension(&dvb_ops);
}
static void __exit em28xx_dvb_unregister(void)
{
em28xx_unregister_extension(&dvb_ops);
}
