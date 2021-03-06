static void tea5761_status_dump(unsigned char *buffer)
{
unsigned int div, frq;
div = ((buffer[2] & 0x3f) << 8) | buffer[3];
frq = 1000 * (div * 32768 / 1000 + FREQ_OFFSET + 225) / 4;
printk(KERN_INFO "tea5761: Frequency %d.%03d KHz (divider = 0x%04x)\n",
frq / 1000, frq % 1000, div);
}
static int __set_radio_freq(struct dvb_frontend *fe,
unsigned int freq,
bool mono)
{
struct tea5761_priv *priv = fe->tuner_priv;
unsigned int frq = freq;
unsigned char buffer[7] = {0, 0, 0, 0, 0, 0, 0 };
unsigned div;
int rc;
tuner_dbg("radio freq counter %d\n", frq);
if (priv->standby) {
tuner_dbg("TEA5761 set to standby mode\n");
buffer[5] |= TEA5761_TNCTRL_MU;
} else {
buffer[4] |= TEA5761_TNCTRL_PUPD_0;
}
if (mono) {
tuner_dbg("TEA5761 set to mono\n");
buffer[5] |= TEA5761_TNCTRL_MST;
} else {
tuner_dbg("TEA5761 set to stereo\n");
}
div = (1000 * (frq * 4 / 16 + 700 + 225) ) >> 15;
buffer[1] = (div >> 8) & 0x3f;
buffer[2] = div & 0xff;
if (debug)
tea5761_status_dump(buffer);
if (7 != (rc = tuner_i2c_xfer_send(&priv->i2c_props, buffer, 7)))
tuner_warn("i2c i/o error: rc == %d (should be 5)\n", rc);
priv->frequency = frq * 125 / 2;
return 0;
}
static int set_radio_freq(struct dvb_frontend *fe,
struct analog_parameters *params)
{
struct tea5761_priv *priv = fe->analog_demod_priv;
priv->standby = false;
return __set_radio_freq(fe, params->frequency,
params->audmode == V4L2_TUNER_MODE_MONO);
}
static int set_radio_sleep(struct dvb_frontend *fe)
{
struct tea5761_priv *priv = fe->analog_demod_priv;
priv->standby = true;
return __set_radio_freq(fe, priv->frequency, false);
}
static int tea5761_read_status(struct dvb_frontend *fe, char *buffer)
{
struct tea5761_priv *priv = fe->tuner_priv;
int rc;
memset(buffer, 0, 16);
if (16 != (rc = tuner_i2c_xfer_recv(&priv->i2c_props, buffer, 16))) {
tuner_warn("i2c i/o error: rc == %d (should be 16)\n", rc);
return -EREMOTEIO;
}
return 0;
}
static inline int tea5761_signal(struct dvb_frontend *fe, const char *buffer)
{
struct tea5761_priv *priv = fe->tuner_priv;
int signal = ((buffer[9] & TEA5761_TUNCHECK_LEV_MASK) << (13 - 4));
tuner_dbg("Signal strength: %d\n", signal);
return signal;
}
static inline int tea5761_stereo(struct dvb_frontend *fe, const char *buffer)
{
struct tea5761_priv *priv = fe->tuner_priv;
int stereo = buffer[9] & TEA5761_TUNCHECK_STEREO;
tuner_dbg("Radio ST GET = %02x\n", stereo);
return (stereo ? V4L2_TUNER_SUB_STEREO : 0);
}
static int tea5761_get_status(struct dvb_frontend *fe, u32 *status)
{
unsigned char buffer[16];
*status = 0;
if (0 == tea5761_read_status(fe, buffer)) {
if (tea5761_signal(fe, buffer))
*status = TUNER_STATUS_LOCKED;
if (tea5761_stereo(fe, buffer))
*status |= TUNER_STATUS_STEREO;
}
return 0;
}
static int tea5761_get_rf_strength(struct dvb_frontend *fe, u16 *strength)
{
unsigned char buffer[16];
*strength = 0;
if (0 == tea5761_read_status(fe, buffer))
*strength = tea5761_signal(fe, buffer);
return 0;
}
int tea5761_autodetection(struct i2c_adapter* i2c_adap, u8 i2c_addr)
{
unsigned char buffer[16];
int rc;
struct tuner_i2c_props i2c = { .adap = i2c_adap, .addr = i2c_addr };
if (16 != (rc = tuner_i2c_xfer_recv(&i2c, buffer, 16))) {
printk(KERN_WARNING "it is not a TEA5761. Received %i chars.\n", rc);
return -EINVAL;
}
if ((buffer[13] != 0x2b) || (buffer[14] != 0x57) || (buffer[15] != 0x061)) {
printk(KERN_WARNING "Manufacturer ID= 0x%02x, Chip ID = %02x%02x. It is not a TEA5761\n",
buffer[13], buffer[14], buffer[15]);
return -EINVAL;
}
printk(KERN_WARNING "tea5761: TEA%02x%02x detected. Manufacturer ID= 0x%02x\n",
buffer[14], buffer[15], buffer[13]);
return 0;
}
static void tea5761_release(struct dvb_frontend *fe)
{
kfree(fe->tuner_priv);
fe->tuner_priv = NULL;
}
static int tea5761_get_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct tea5761_priv *priv = fe->tuner_priv;
*frequency = priv->frequency;
return 0;
}
struct dvb_frontend *tea5761_attach(struct dvb_frontend *fe,
struct i2c_adapter* i2c_adap,
u8 i2c_addr)
{
struct tea5761_priv *priv = NULL;
if (tea5761_autodetection(i2c_adap, i2c_addr) != 0)
return NULL;
priv = kzalloc(sizeof(struct tea5761_priv), GFP_KERNEL);
if (priv == NULL)
return NULL;
fe->tuner_priv = priv;
priv->i2c_props.addr = i2c_addr;
priv->i2c_props.adap = i2c_adap;
priv->i2c_props.name = "tea5761";
memcpy(&fe->ops.tuner_ops, &tea5761_tuner_ops,
sizeof(struct dvb_tuner_ops));
tuner_info("type set to %s\n", "Philips TEA5761HN FM Radio");
return fe;
}
