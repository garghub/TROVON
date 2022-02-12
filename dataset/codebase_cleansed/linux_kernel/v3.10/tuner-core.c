static void tuner_detach(struct dvb_frontend *fe)
{
if (fe->ops.tuner_ops.release) {
fe->ops.tuner_ops.release(fe);
symbol_put_addr(fe->ops.tuner_ops.release);
}
if (fe->ops.analog_ops.release) {
fe->ops.analog_ops.release(fe);
symbol_put_addr(fe->ops.analog_ops.release);
}
}
static void tuner_detach(struct dvb_frontend *fe)
{
if (fe->ops.tuner_ops.release)
fe->ops.tuner_ops.release(fe);
if (fe->ops.analog_ops.release)
fe->ops.analog_ops.release(fe);
}
static inline struct tuner *to_tuner(struct v4l2_subdev *sd)
{
return container_of(sd, struct tuner, sd);
}
static void fe_set_params(struct dvb_frontend *fe,
struct analog_parameters *params)
{
struct dvb_tuner_ops *fe_tuner_ops = &fe->ops.tuner_ops;
struct tuner *t = fe->analog_demod_priv;
if (NULL == fe_tuner_ops->set_analog_params) {
tuner_warn("Tuner frontend module has no way to set freq\n");
return;
}
fe_tuner_ops->set_analog_params(fe, params);
}
static void fe_standby(struct dvb_frontend *fe)
{
struct dvb_tuner_ops *fe_tuner_ops = &fe->ops.tuner_ops;
if (fe_tuner_ops->sleep)
fe_tuner_ops->sleep(fe);
}
static int fe_set_config(struct dvb_frontend *fe, void *priv_cfg)
{
struct dvb_tuner_ops *fe_tuner_ops = &fe->ops.tuner_ops;
struct tuner *t = fe->analog_demod_priv;
if (fe_tuner_ops->set_config)
return fe_tuner_ops->set_config(fe, priv_cfg);
tuner_warn("Tuner frontend module has no way to set config\n");
return 0;
}
static void set_type(struct i2c_client *c, unsigned int type,
unsigned int new_mode_mask, void *new_config,
int (*tuner_callback) (void *dev, int component, int cmd, int arg))
{
struct tuner *t = to_tuner(i2c_get_clientdata(c));
struct dvb_tuner_ops *fe_tuner_ops = &t->fe.ops.tuner_ops;
struct analog_demod_ops *analog_ops = &t->fe.ops.analog_ops;
unsigned char buffer[4];
int tune_now = 1;
if (type == UNSET || type == TUNER_ABSENT) {
tuner_dbg("tuner 0x%02x: Tuner type absent\n", c->addr);
return;
}
t->type = type;
t->config = new_config;
if (tuner_callback != NULL) {
tuner_dbg("defining GPIO callback\n");
t->fe.callback = tuner_callback;
}
tuner_detach(&t->fe);
t->fe.analog_demod_priv = NULL;
switch (t->type) {
case TUNER_MT2032:
if (!dvb_attach(microtune_attach,
&t->fe, t->i2c->adapter, t->i2c->addr))
goto attach_failed;
break;
case TUNER_PHILIPS_TDA8290:
{
if (!dvb_attach(tda829x_attach, &t->fe, t->i2c->adapter,
t->i2c->addr, t->config))
goto attach_failed;
break;
}
case TUNER_TEA5767:
if (!dvb_attach(tea5767_attach, &t->fe,
t->i2c->adapter, t->i2c->addr))
goto attach_failed;
t->mode_mask = T_RADIO;
break;
case TUNER_TEA5761:
if (!dvb_attach(tea5761_attach, &t->fe,
t->i2c->adapter, t->i2c->addr))
goto attach_failed;
t->mode_mask = T_RADIO;
break;
case TUNER_PHILIPS_FMD1216ME_MK3:
case TUNER_PHILIPS_FMD1216MEX_MK3:
buffer[0] = 0x0b;
buffer[1] = 0xdc;
buffer[2] = 0x9c;
buffer[3] = 0x60;
i2c_master_send(c, buffer, 4);
mdelay(1);
buffer[2] = 0x86;
buffer[3] = 0x54;
i2c_master_send(c, buffer, 4);
if (!dvb_attach(simple_tuner_attach, &t->fe,
t->i2c->adapter, t->i2c->addr, t->type))
goto attach_failed;
break;
case TUNER_PHILIPS_TD1316:
buffer[0] = 0x0b;
buffer[1] = 0xdc;
buffer[2] = 0x86;
buffer[3] = 0xa4;
i2c_master_send(c, buffer, 4);
if (!dvb_attach(simple_tuner_attach, &t->fe,
t->i2c->adapter, t->i2c->addr, t->type))
goto attach_failed;
break;
case TUNER_XC2028:
{
struct xc2028_config cfg = {
.i2c_adap = t->i2c->adapter,
.i2c_addr = t->i2c->addr,
};
if (!dvb_attach(xc2028_attach, &t->fe, &cfg))
goto attach_failed;
tune_now = 0;
break;
}
case TUNER_TDA9887:
if (!dvb_attach(tda9887_attach,
&t->fe, t->i2c->adapter, t->i2c->addr))
goto attach_failed;
break;
case TUNER_XC5000:
{
struct xc5000_config xc5000_cfg = {
.i2c_address = t->i2c->addr,
.if_khz = 0,
};
if (!dvb_attach(xc5000_attach,
&t->fe, t->i2c->adapter, &xc5000_cfg))
goto attach_failed;
tune_now = 0;
break;
}
case TUNER_XC5000C:
{
struct xc5000_config xc5000c_cfg = {
.i2c_address = t->i2c->addr,
.if_khz = 0,
.chip_id = XC5000C,
};
if (!dvb_attach(xc5000_attach,
&t->fe, t->i2c->adapter, &xc5000c_cfg))
goto attach_failed;
tune_now = 0;
break;
}
case TUNER_NXP_TDA18271:
{
struct tda18271_config cfg = {
.small_i2c = TDA18271_03_BYTE_CHUNK_INIT,
};
if (!dvb_attach(tda18271_attach, &t->fe, t->i2c->addr,
t->i2c->adapter, &cfg))
goto attach_failed;
tune_now = 0;
break;
}
case TUNER_XC4000:
{
struct xc4000_config xc4000_cfg = {
.i2c_address = t->i2c->addr,
.default_pm = 0,
.dvb_amplitude = 0,
.set_smoothedcvbs = 0,
.if_khz = 0
};
if (!dvb_attach(xc4000_attach,
&t->fe, t->i2c->adapter, &xc4000_cfg))
goto attach_failed;
tune_now = 0;
break;
}
default:
if (!dvb_attach(simple_tuner_attach, &t->fe,
t->i2c->adapter, t->i2c->addr, t->type))
goto attach_failed;
break;
}
if ((NULL == analog_ops->set_params) &&
(fe_tuner_ops->set_analog_params)) {
t->name = fe_tuner_ops->info.name;
t->fe.analog_demod_priv = t;
memcpy(analog_ops, &tuner_analog_ops,
sizeof(struct analog_demod_ops));
if (fe_tuner_ops->get_rf_strength)
analog_ops->has_signal = fe_tuner_ops->get_rf_strength;
if (fe_tuner_ops->get_afc)
analog_ops->get_afc = fe_tuner_ops->get_afc;
} else {
t->name = analog_ops->info.name;
}
tuner_dbg("type set to %s\n", t->name);
t->mode_mask = new_mode_mask;
if (tune_now) {
if (V4L2_TUNER_RADIO == t->mode)
set_radio_freq(c, t->radio_freq);
else
set_tv_freq(c, t->tv_freq);
}
tuner_dbg("%s %s I2C addr 0x%02x with type %d used for 0x%02x\n",
c->adapter->name, c->driver->driver.name, c->addr << 1, type,
t->mode_mask);
return;
attach_failed:
tuner_dbg("Tuner attach for type = %d failed.\n", t->type);
t->type = TUNER_ABSENT;
return;
}
static int tuner_s_type_addr(struct v4l2_subdev *sd,
struct tuner_setup *tun_setup)
{
struct tuner *t = to_tuner(sd);
struct i2c_client *c = v4l2_get_subdevdata(sd);
tuner_dbg("Calling set_type_addr for type=%d, addr=0x%02x, mode=0x%02x, config=%p\n",
tun_setup->type,
tun_setup->addr,
tun_setup->mode_mask,
tun_setup->config);
if ((t->type == UNSET && ((tun_setup->addr == ADDR_UNSET) &&
(t->mode_mask & tun_setup->mode_mask))) ||
(tun_setup->addr == c->addr)) {
set_type(c, tun_setup->type, tun_setup->mode_mask,
tun_setup->config, tun_setup->tuner_callback);
} else
tuner_dbg("set addr discarded for type %i, mask %x. "
"Asked to change tuner at addr 0x%02x, with mask %x\n",
t->type, t->mode_mask,
tun_setup->addr, tun_setup->mode_mask);
return 0;
}
static int tuner_s_config(struct v4l2_subdev *sd,
const struct v4l2_priv_tun_config *cfg)
{
struct tuner *t = to_tuner(sd);
struct analog_demod_ops *analog_ops = &t->fe.ops.analog_ops;
if (t->type != cfg->tuner)
return 0;
if (analog_ops->set_config) {
analog_ops->set_config(&t->fe, cfg->priv);
return 0;
}
tuner_dbg("Tuner frontend module has no way to set config\n");
return 0;
}
static void tuner_lookup(struct i2c_adapter *adap,
struct tuner **radio, struct tuner **tv)
{
struct tuner *pos;
*radio = NULL;
*tv = NULL;
list_for_each_entry(pos, &tuner_list, list) {
int mode_mask;
if (pos->i2c->adapter != adap ||
strcmp(pos->i2c->driver->driver.name, "tuner"))
continue;
mode_mask = pos->mode_mask;
if (*radio == NULL && mode_mask == T_RADIO)
*radio = pos;
else if (*tv == NULL && pos->type != TUNER_TDA9887 &&
(pos->mode_mask & T_ANALOG_TV))
*tv = pos;
}
}
static int tuner_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tuner *t;
struct tuner *radio;
struct tuner *tv;
t = kzalloc(sizeof(struct tuner), GFP_KERNEL);
if (NULL == t)
return -ENOMEM;
v4l2_i2c_subdev_init(&t->sd, client, &tuner_ops);
t->i2c = client;
t->name = "(tuner unset)";
t->type = UNSET;
t->audmode = V4L2_TUNER_MODE_STEREO;
t->standby = 1;
t->radio_freq = 87.5 * 16000;
t->tv_freq = 400 * 16;
if (show_i2c) {
unsigned char buffer[16];
int i, rc;
memset(buffer, 0, sizeof(buffer));
rc = i2c_master_recv(client, buffer, sizeof(buffer));
tuner_info("I2C RECV = ");
for (i = 0; i < rc; i++)
printk(KERN_CONT "%02x ", buffer[i]);
printk("\n");
}
if (!no_autodetect) {
switch (client->addr) {
case 0x10:
if (tuner_symbol_probe(tea5761_autodetection,
t->i2c->adapter,
t->i2c->addr) >= 0) {
t->type = TUNER_TEA5761;
t->mode_mask = T_RADIO;
tuner_lookup(t->i2c->adapter, &radio, &tv);
if (tv)
tv->mode_mask &= ~T_RADIO;
goto register_client;
}
kfree(t);
return -ENODEV;
case 0x42:
case 0x43:
case 0x4a:
case 0x4b:
if (tuner_symbol_probe(tda829x_probe, t->i2c->adapter,
t->i2c->addr) >= 0) {
tuner_dbg("tda829x detected\n");
} else {
t->type = TUNER_TDA9887;
t->mode_mask = T_RADIO | T_ANALOG_TV;
goto register_client;
}
break;
case 0x60:
if (tuner_symbol_probe(tea5767_autodetection,
t->i2c->adapter, t->i2c->addr)
>= 0) {
t->type = TUNER_TEA5767;
t->mode_mask = T_RADIO;
tuner_lookup(t->i2c->adapter, &radio, &tv);
if (tv)
tv->mode_mask &= ~T_RADIO;
goto register_client;
}
break;
}
}
tuner_lookup(t->i2c->adapter, &radio, &tv);
if (tv == NULL) {
t->mode_mask = T_ANALOG_TV;
if (radio == NULL)
t->mode_mask |= T_RADIO;
tuner_dbg("Setting mode_mask to 0x%02x\n", t->mode_mask);
}
register_client:
if (t->mode_mask & T_ANALOG_TV)
t->mode = V4L2_TUNER_ANALOG_TV;
else
t->mode = V4L2_TUNER_RADIO;
set_type(client, t->type, t->mode_mask, t->config, t->fe.callback);
list_add_tail(&t->list, &tuner_list);
tuner_info("Tuner %d found with type(s)%s%s.\n",
t->type,
t->mode_mask & T_RADIO ? " Radio" : "",
t->mode_mask & T_ANALOG_TV ? " TV" : "");
return 0;
}
static int tuner_remove(struct i2c_client *client)
{
struct tuner *t = to_tuner(i2c_get_clientdata(client));
v4l2_device_unregister_subdev(&t->sd);
tuner_detach(&t->fe);
t->fe.analog_demod_priv = NULL;
list_del(&t->list);
kfree(t);
return 0;
}
static inline int check_mode(struct tuner *t, enum v4l2_tuner_type mode)
{
int t_mode;
if (mode == V4L2_TUNER_RADIO)
t_mode = T_RADIO;
else
t_mode = T_ANALOG_TV;
if ((t_mode & t->mode_mask) == 0)
return -EINVAL;
return 0;
}
static int set_mode(struct tuner *t, enum v4l2_tuner_type mode)
{
struct analog_demod_ops *analog_ops = &t->fe.ops.analog_ops;
if (mode != t->mode) {
if (check_mode(t, mode) == -EINVAL) {
tuner_dbg("Tuner doesn't support mode %d. "
"Putting tuner to sleep\n", mode);
t->standby = true;
if (analog_ops->standby)
analog_ops->standby(&t->fe);
return -EINVAL;
}
t->mode = mode;
tuner_dbg("Changing to mode %d\n", mode);
}
return 0;
}
static void set_freq(struct tuner *t, unsigned int freq)
{
struct i2c_client *client = v4l2_get_subdevdata(&t->sd);
if (t->mode == V4L2_TUNER_RADIO) {
if (!freq)
freq = t->radio_freq;
set_radio_freq(client, freq);
} else {
if (!freq)
freq = t->tv_freq;
set_tv_freq(client, freq);
}
}
static void set_tv_freq(struct i2c_client *c, unsigned int freq)
{
struct tuner *t = to_tuner(i2c_get_clientdata(c));
struct analog_demod_ops *analog_ops = &t->fe.ops.analog_ops;
struct analog_parameters params = {
.mode = t->mode,
.audmode = t->audmode,
.std = t->std
};
if (t->type == UNSET) {
tuner_warn("tuner type not set\n");
return;
}
if (NULL == analog_ops->set_params) {
tuner_warn("Tuner has no way to set tv freq\n");
return;
}
if (freq < tv_range[0] * 16 || freq > tv_range[1] * 16) {
tuner_dbg("TV freq (%d.%02d) out of range (%d-%d)\n",
freq / 16, freq % 16 * 100 / 16, tv_range[0],
tv_range[1]);
if (freq < tv_range[0] * 16)
freq = tv_range[0] * 16;
else
freq = tv_range[1] * 16;
}
params.frequency = freq;
tuner_dbg("tv freq set to %d.%02d\n",
freq / 16, freq % 16 * 100 / 16);
t->tv_freq = freq;
t->standby = false;
analog_ops->set_params(&t->fe, &params);
}
static v4l2_std_id tuner_fixup_std(struct tuner *t, v4l2_std_id std)
{
if (pal[0] != '-' && (std & V4L2_STD_PAL) == V4L2_STD_PAL) {
switch (pal[0]) {
case '6':
return V4L2_STD_PAL_60;
case 'b':
case 'B':
case 'g':
case 'G':
return V4L2_STD_PAL_BG;
case 'i':
case 'I':
return V4L2_STD_PAL_I;
case 'd':
case 'D':
case 'k':
case 'K':
return V4L2_STD_PAL_DK;
case 'M':
case 'm':
return V4L2_STD_PAL_M;
case 'N':
case 'n':
if (pal[1] == 'c' || pal[1] == 'C')
return V4L2_STD_PAL_Nc;
return V4L2_STD_PAL_N;
default:
tuner_warn("pal= argument not recognised\n");
break;
}
}
if (secam[0] != '-' && (std & V4L2_STD_SECAM) == V4L2_STD_SECAM) {
switch (secam[0]) {
case 'b':
case 'B':
case 'g':
case 'G':
case 'h':
case 'H':
return V4L2_STD_SECAM_B |
V4L2_STD_SECAM_G |
V4L2_STD_SECAM_H;
case 'd':
case 'D':
case 'k':
case 'K':
return V4L2_STD_SECAM_DK;
case 'l':
case 'L':
if ((secam[1] == 'C') || (secam[1] == 'c'))
return V4L2_STD_SECAM_LC;
return V4L2_STD_SECAM_L;
default:
tuner_warn("secam= argument not recognised\n");
break;
}
}
if (ntsc[0] != '-' && (std & V4L2_STD_NTSC) == V4L2_STD_NTSC) {
switch (ntsc[0]) {
case 'm':
case 'M':
return V4L2_STD_NTSC_M;
case 'j':
case 'J':
return V4L2_STD_NTSC_M_JP;
case 'k':
case 'K':
return V4L2_STD_NTSC_M_KR;
default:
tuner_info("ntsc= argument not recognised\n");
break;
}
}
return std;
}
static void set_radio_freq(struct i2c_client *c, unsigned int freq)
{
struct tuner *t = to_tuner(i2c_get_clientdata(c));
struct analog_demod_ops *analog_ops = &t->fe.ops.analog_ops;
struct analog_parameters params = {
.mode = t->mode,
.audmode = t->audmode,
.std = t->std
};
if (t->type == UNSET) {
tuner_warn("tuner type not set\n");
return;
}
if (NULL == analog_ops->set_params) {
tuner_warn("tuner has no way to set radio frequency\n");
return;
}
if (freq < radio_range[0] * 16000 || freq > radio_range[1] * 16000) {
tuner_dbg("radio freq (%d.%02d) out of range (%d-%d)\n",
freq / 16000, freq % 16000 * 100 / 16000,
radio_range[0], radio_range[1]);
if (freq < radio_range[0] * 16000)
freq = radio_range[0] * 16000;
else
freq = radio_range[1] * 16000;
}
params.frequency = freq;
tuner_dbg("radio freq set to %d.%02d\n",
freq / 16000, freq % 16000 * 100 / 16000);
t->radio_freq = freq;
t->standby = false;
analog_ops->set_params(&t->fe, &params);
t->audmode = params.audmode;
}
static void tuner_status(struct dvb_frontend *fe)
{
struct tuner *t = fe->analog_demod_priv;
unsigned long freq, freq_fraction;
struct dvb_tuner_ops *fe_tuner_ops = &fe->ops.tuner_ops;
struct analog_demod_ops *analog_ops = &fe->ops.analog_ops;
const char *p;
switch (t->mode) {
case V4L2_TUNER_RADIO:
p = "radio";
break;
case V4L2_TUNER_DIGITAL_TV:
p = "digital TV";
break;
case V4L2_TUNER_ANALOG_TV:
default:
p = "analog TV";
break;
}
if (t->mode == V4L2_TUNER_RADIO) {
freq = t->radio_freq / 16000;
freq_fraction = (t->radio_freq % 16000) * 100 / 16000;
} else {
freq = t->tv_freq / 16;
freq_fraction = (t->tv_freq % 16) * 100 / 16;
}
tuner_info("Tuner mode: %s%s\n", p,
t->standby ? " on standby mode" : "");
tuner_info("Frequency: %lu.%02lu MHz\n", freq, freq_fraction);
tuner_info("Standard: 0x%08lx\n", (unsigned long)t->std);
if (t->mode != V4L2_TUNER_RADIO)
return;
if (fe_tuner_ops->get_status) {
u32 tuner_status;
fe_tuner_ops->get_status(&t->fe, &tuner_status);
if (tuner_status & TUNER_STATUS_LOCKED)
tuner_info("Tuner is locked.\n");
if (tuner_status & TUNER_STATUS_STEREO)
tuner_info("Stereo: yes\n");
}
if (analog_ops->has_signal) {
u16 signal;
if (!analog_ops->has_signal(fe, &signal))
tuner_info("Signal strength: %hu\n", signal);
}
}
static int tuner_s_radio(struct v4l2_subdev *sd)
{
struct tuner *t = to_tuner(sd);
if (set_mode(t, V4L2_TUNER_RADIO) == 0)
set_freq(t, 0);
return 0;
}
static int tuner_s_power(struct v4l2_subdev *sd, int on)
{
struct tuner *t = to_tuner(sd);
struct analog_demod_ops *analog_ops = &t->fe.ops.analog_ops;
if (on) {
if (t->standby && set_mode(t, t->mode) == 0) {
tuner_dbg("Waking up tuner\n");
set_freq(t, 0);
}
return 0;
}
tuner_dbg("Putting tuner to sleep\n");
t->standby = true;
if (analog_ops->standby)
analog_ops->standby(&t->fe);
return 0;
}
static int tuner_s_std(struct v4l2_subdev *sd, v4l2_std_id std)
{
struct tuner *t = to_tuner(sd);
if (set_mode(t, V4L2_TUNER_ANALOG_TV))
return 0;
t->std = tuner_fixup_std(t, std);
if (t->std != std)
tuner_dbg("Fixup standard %llx to %llx\n", std, t->std);
set_freq(t, 0);
return 0;
}
static int tuner_s_frequency(struct v4l2_subdev *sd, const struct v4l2_frequency *f)
{
struct tuner *t = to_tuner(sd);
if (set_mode(t, f->type) == 0)
set_freq(t, f->frequency);
return 0;
}
static int tuner_g_frequency(struct v4l2_subdev *sd, struct v4l2_frequency *f)
{
struct tuner *t = to_tuner(sd);
struct dvb_tuner_ops *fe_tuner_ops = &t->fe.ops.tuner_ops;
if (check_mode(t, f->type) == -EINVAL)
return 0;
if (f->type == t->mode && fe_tuner_ops->get_frequency && !t->standby) {
u32 abs_freq;
fe_tuner_ops->get_frequency(&t->fe, &abs_freq);
f->frequency = (V4L2_TUNER_RADIO == t->mode) ?
DIV_ROUND_CLOSEST(abs_freq * 2, 125) :
DIV_ROUND_CLOSEST(abs_freq, 62500);
} else {
f->frequency = (V4L2_TUNER_RADIO == f->type) ?
t->radio_freq : t->tv_freq;
}
return 0;
}
static int tuner_g_tuner(struct v4l2_subdev *sd, struct v4l2_tuner *vt)
{
struct tuner *t = to_tuner(sd);
struct analog_demod_ops *analog_ops = &t->fe.ops.analog_ops;
struct dvb_tuner_ops *fe_tuner_ops = &t->fe.ops.tuner_ops;
if (check_mode(t, vt->type) == -EINVAL)
return 0;
if (vt->type == t->mode && analog_ops->get_afc)
analog_ops->get_afc(&t->fe, &vt->afc);
if (vt->type == t->mode && analog_ops->has_signal) {
u16 signal = (u16)vt->signal;
if (!analog_ops->has_signal(&t->fe, &signal))
vt->signal = signal;
}
if (vt->type != V4L2_TUNER_RADIO) {
vt->capability |= V4L2_TUNER_CAP_NORM;
vt->rangelow = tv_range[0] * 16;
vt->rangehigh = tv_range[1] * 16;
return 0;
}
if (vt->type == t->mode) {
vt->rxsubchans = V4L2_TUNER_SUB_MONO | V4L2_TUNER_SUB_STEREO;
if (fe_tuner_ops->get_status) {
u32 tuner_status;
fe_tuner_ops->get_status(&t->fe, &tuner_status);
vt->rxsubchans =
(tuner_status & TUNER_STATUS_STEREO) ?
V4L2_TUNER_SUB_STEREO :
V4L2_TUNER_SUB_MONO;
}
vt->audmode = t->audmode;
}
vt->capability |= V4L2_TUNER_CAP_LOW | V4L2_TUNER_CAP_STEREO;
vt->rangelow = radio_range[0] * 16000;
vt->rangehigh = radio_range[1] * 16000;
return 0;
}
static int tuner_s_tuner(struct v4l2_subdev *sd, const struct v4l2_tuner *vt)
{
struct tuner *t = to_tuner(sd);
if (set_mode(t, vt->type))
return 0;
if (t->mode == V4L2_TUNER_RADIO) {
t->audmode = vt->audmode;
if (t->audmode != V4L2_TUNER_MODE_MONO &&
t->audmode != V4L2_TUNER_MODE_STEREO)
t->audmode = V4L2_TUNER_MODE_STEREO;
}
set_freq(t, 0);
return 0;
}
static int tuner_log_status(struct v4l2_subdev *sd)
{
struct tuner *t = to_tuner(sd);
struct analog_demod_ops *analog_ops = &t->fe.ops.analog_ops;
if (analog_ops->tuner_status)
analog_ops->tuner_status(&t->fe);
return 0;
}
static int tuner_suspend(struct device *dev)
{
struct i2c_client *c = to_i2c_client(dev);
struct tuner *t = to_tuner(i2c_get_clientdata(c));
struct analog_demod_ops *analog_ops = &t->fe.ops.analog_ops;
tuner_dbg("suspend\n");
if (!t->standby && analog_ops->standby)
analog_ops->standby(&t->fe);
return 0;
}
static int tuner_resume(struct device *dev)
{
struct i2c_client *c = to_i2c_client(dev);
struct tuner *t = to_tuner(i2c_get_clientdata(c));
tuner_dbg("resume\n");
if (!t->standby)
if (set_mode(t, t->mode) == 0)
set_freq(t, 0);
return 0;
}
static int tuner_command(struct i2c_client *client, unsigned cmd, void *arg)
{
struct v4l2_subdev *sd = i2c_get_clientdata(client);
switch (cmd) {
case TUNER_SET_CONFIG:
return tuner_s_config(sd, arg);
}
return -ENOIOCTLCMD;
}
