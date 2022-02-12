static void tea5767_status_dump(struct tea5767_priv *priv,
unsigned char *buffer)
{
unsigned int div, frq;
if (TEA5767_READY_FLAG_MASK & buffer[0])
tuner_info("Ready Flag ON\n");
else
tuner_info("Ready Flag OFF\n");
if (TEA5767_BAND_LIMIT_MASK & buffer[0])
tuner_info("Tuner at band limit\n");
else
tuner_info("Tuner not at band limit\n");
div = ((buffer[0] & 0x3f) << 8) | buffer[1];
switch (priv->ctrl.xtal_freq) {
case TEA5767_HIGH_LO_13MHz:
frq = (div * 50000 - 700000 - 225000) / 4;
break;
case TEA5767_LOW_LO_13MHz:
frq = (div * 50000 + 700000 + 225000) / 4;
break;
case TEA5767_LOW_LO_32768:
frq = (div * 32768 + 700000 + 225000) / 4;
break;
case TEA5767_HIGH_LO_32768:
default:
frq = (div * 32768 - 700000 - 225000) / 4;
break;
}
buffer[0] = (div >> 8) & 0x3f;
buffer[1] = div & 0xff;
tuner_info("Frequency %d.%03d KHz (divider = 0x%04x)\n",
frq / 1000, frq % 1000, div);
if (TEA5767_STEREO_MASK & buffer[2])
tuner_info("Stereo\n");
else
tuner_info("Mono\n");
tuner_info("IF Counter = %d\n", buffer[2] & TEA5767_IF_CNTR_MASK);
tuner_info("ADC Level = %d\n",
(buffer[3] & TEA5767_ADC_LEVEL_MASK) >> 4);
tuner_info("Chip ID = %d\n", (buffer[3] & TEA5767_CHIP_ID_MASK));
tuner_info("Reserved = 0x%02x\n",
(buffer[4] & TEA5767_RESERVED_MASK));
}
static int set_radio_freq(struct dvb_frontend *fe,
struct analog_parameters *params)
{
struct tea5767_priv *priv = fe->tuner_priv;
unsigned int frq = params->frequency;
unsigned char buffer[5];
unsigned div;
int rc;
tuner_dbg("radio freq = %d.%03d MHz\n", frq/16000,(frq/16)%1000);
buffer[2] = 0;
if (priv->ctrl.port1)
buffer[2] |= TEA5767_PORT1_HIGH;
if (params->audmode == V4L2_TUNER_MODE_MONO) {
tuner_dbg("TEA5767 set to mono\n");
buffer[2] |= TEA5767_MONO;
} else {
tuner_dbg("TEA5767 set to stereo\n");
}
buffer[3] = 0;
if (priv->ctrl.port2)
buffer[3] |= TEA5767_PORT2_HIGH;
if (priv->ctrl.high_cut)
buffer[3] |= TEA5767_HIGH_CUT_CTRL;
if (priv->ctrl.st_noise)
buffer[3] |= TEA5767_ST_NOISE_CTL;
if (priv->ctrl.soft_mute)
buffer[3] |= TEA5767_SOFT_MUTE;
if (priv->ctrl.japan_band)
buffer[3] |= TEA5767_JAPAN_BAND;
buffer[4] = 0;
if (priv->ctrl.deemph_75)
buffer[4] |= TEA5767_DEEMPH_75;
if (priv->ctrl.pllref)
buffer[4] |= TEA5767_PLLREF_ENABLE;
switch (priv->ctrl.xtal_freq) {
case TEA5767_HIGH_LO_13MHz:
tuner_dbg("radio HIGH LO inject xtal @ 13 MHz\n");
buffer[2] |= TEA5767_HIGH_LO_INJECT;
div = (frq * (4000 / 16) + 700000 + 225000 + 25000) / 50000;
break;
case TEA5767_LOW_LO_13MHz:
tuner_dbg("radio LOW LO inject xtal @ 13 MHz\n");
div = (frq * (4000 / 16) - 700000 - 225000 + 25000) / 50000;
break;
case TEA5767_LOW_LO_32768:
tuner_dbg("radio LOW LO inject xtal @ 32,768 MHz\n");
buffer[3] |= TEA5767_XTAL_32768;
div = ((frq * (4000 / 16) - 700000 - 225000) + 16384) >> 15;
break;
case TEA5767_HIGH_LO_32768:
default:
tuner_dbg("radio HIGH LO inject xtal @ 32,768 MHz\n");
buffer[2] |= TEA5767_HIGH_LO_INJECT;
buffer[3] |= TEA5767_XTAL_32768;
div = ((frq * (4000 / 16) + 700000 + 225000) + 16384) >> 15;
break;
}
buffer[0] = (div >> 8) & 0x3f;
buffer[1] = div & 0xff;
if (5 != (rc = tuner_i2c_xfer_send(&priv->i2c_props, buffer, 5)))
tuner_warn("i2c i/o error: rc == %d (should be 5)\n", rc);
if (debug) {
if (5 != (rc = tuner_i2c_xfer_recv(&priv->i2c_props, buffer, 5)))
tuner_warn("i2c i/o error: rc == %d (should be 5)\n", rc);
else
tea5767_status_dump(priv, buffer);
}
priv->frequency = frq * 125 / 2;
return 0;
}
static int tea5767_read_status(struct dvb_frontend *fe, char *buffer)
{
struct tea5767_priv *priv = fe->tuner_priv;
int rc;
memset(buffer, 0, 5);
if (5 != (rc = tuner_i2c_xfer_recv(&priv->i2c_props, buffer, 5))) {
tuner_warn("i2c i/o error: rc == %d (should be 5)\n", rc);
return -EREMOTEIO;
}
return 0;
}
static inline int tea5767_signal(struct dvb_frontend *fe, const char *buffer)
{
struct tea5767_priv *priv = fe->tuner_priv;
int signal = ((buffer[3] & TEA5767_ADC_LEVEL_MASK) << 8);
tuner_dbg("Signal strength: %d\n", signal);
return signal;
}
static inline int tea5767_stereo(struct dvb_frontend *fe, const char *buffer)
{
struct tea5767_priv *priv = fe->tuner_priv;
int stereo = buffer[2] & TEA5767_STEREO_MASK;
tuner_dbg("Radio ST GET = %02x\n", stereo);
return (stereo ? V4L2_TUNER_SUB_STEREO : 0);
}
static int tea5767_get_status(struct dvb_frontend *fe, u32 *status)
{
unsigned char buffer[5];
*status = 0;
if (0 == tea5767_read_status(fe, buffer)) {
if (tea5767_signal(fe, buffer))
*status = TUNER_STATUS_LOCKED;
if (tea5767_stereo(fe, buffer))
*status |= TUNER_STATUS_STEREO;
}
return 0;
}
static int tea5767_get_rf_strength(struct dvb_frontend *fe, u16 *strength)
{
unsigned char buffer[5];
*strength = 0;
if (0 == tea5767_read_status(fe, buffer))
*strength = tea5767_signal(fe, buffer);
return 0;
}
static int tea5767_standby(struct dvb_frontend *fe)
{
unsigned char buffer[5];
struct tea5767_priv *priv = fe->tuner_priv;
unsigned div, rc;
div = (87500 * 4 + 700 + 225 + 25) / 50;
buffer[0] = (div >> 8) & 0x3f;
buffer[1] = div & 0xff;
buffer[2] = TEA5767_PORT1_HIGH;
buffer[3] = TEA5767_PORT2_HIGH | TEA5767_HIGH_CUT_CTRL |
TEA5767_ST_NOISE_CTL | TEA5767_JAPAN_BAND | TEA5767_STDBY;
buffer[4] = 0;
if (5 != (rc = tuner_i2c_xfer_send(&priv->i2c_props, buffer, 5)))
tuner_warn("i2c i/o error: rc == %d (should be 5)\n", rc);
return 0;
}
int tea5767_autodetection(struct i2c_adapter* i2c_adap, u8 i2c_addr)
{
struct tuner_i2c_props i2c = { .adap = i2c_adap, .addr = i2c_addr };
unsigned char buffer[7] = { 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };
int rc;
if ((rc = tuner_i2c_xfer_recv(&i2c, buffer, 7))< 5) {
printk(KERN_WARNING "It is not a TEA5767. Received %i bytes.\n", rc);
return -EINVAL;
}
if (buffer[0] == buffer[1] && buffer[0] == buffer[2] &&
buffer[0] == buffer[3] && buffer[0] == buffer[4]) {
printk(KERN_WARNING "All bytes are equal. It is not a TEA5767\n");
return -EINVAL;
}
if (((buffer[3] & 0x0f) != 0x00) || (buffer[4] != 0x00)) {
printk(KERN_WARNING "Chip ID is not zero. It is not a TEA5767\n");
return -EINVAL;
}
return 0;
}
static int tea5767_release(struct dvb_frontend *fe)
{
kfree(fe->tuner_priv);
fe->tuner_priv = NULL;
return 0;
}
static int tea5767_get_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct tea5767_priv *priv = fe->tuner_priv;
*frequency = priv->frequency;
return 0;
}
static int tea5767_set_config (struct dvb_frontend *fe, void *priv_cfg)
{
struct tea5767_priv *priv = fe->tuner_priv;
memcpy(&priv->ctrl, priv_cfg, sizeof(priv->ctrl));
return 0;
}
struct dvb_frontend *tea5767_attach(struct dvb_frontend *fe,
struct i2c_adapter* i2c_adap,
u8 i2c_addr)
{
struct tea5767_priv *priv = NULL;
priv = kzalloc(sizeof(struct tea5767_priv), GFP_KERNEL);
if (priv == NULL)
return NULL;
fe->tuner_priv = priv;
priv->i2c_props.addr = i2c_addr;
priv->i2c_props.adap = i2c_adap;
priv->i2c_props.name = "tea5767";
priv->ctrl.xtal_freq = TEA5767_HIGH_LO_32768;
priv->ctrl.port1 = 1;
priv->ctrl.port2 = 1;
priv->ctrl.high_cut = 1;
priv->ctrl.st_noise = 1;
priv->ctrl.japan_band = 1;
memcpy(&fe->ops.tuner_ops, &tea5767_tuner_ops,
sizeof(struct dvb_tuner_ops));
tuner_info("type set to %s\n", "Philips TEA5767HN FM Radio");
return fe;
}
