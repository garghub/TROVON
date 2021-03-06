static void dump_read_message(struct dvb_frontend *fe, unsigned char *buf)
{
struct tda9887_priv *priv = fe->analog_demod_priv;
static char *afc[16] = {
"- 12.5 kHz",
"- 37.5 kHz",
"- 62.5 kHz",
"- 87.5 kHz",
"-112.5 kHz",
"-137.5 kHz",
"-162.5 kHz",
"-187.5 kHz [min]",
"+187.5 kHz [max]",
"+162.5 kHz",
"+137.5 kHz",
"+112.5 kHz",
"+ 87.5 kHz",
"+ 62.5 kHz",
"+ 37.5 kHz",
"+ 12.5 kHz",
};
tuner_info("read: 0x%2x\n", buf[0]);
tuner_info(" after power on : %s\n", (buf[0] & 0x01) ? "yes" : "no");
tuner_info(" afc : %s\n", afc[(buf[0] >> 1) & 0x0f]);
tuner_info(" fmif level : %s\n", (buf[0] & 0x20) ? "high" : "low");
tuner_info(" afc window : %s\n", (buf[0] & 0x40) ? "in" : "out");
tuner_info(" vfi level : %s\n", (buf[0] & 0x80) ? "high" : "low");
}
static void dump_write_message(struct dvb_frontend *fe, unsigned char *buf)
{
struct tda9887_priv *priv = fe->analog_demod_priv;
static char *sound[4] = {
"AM/TV",
"FM/radio",
"FM/TV",
"FM/radio"
};
static char *adjust[32] = {
"-16", "-15", "-14", "-13", "-12", "-11", "-10", "-9",
"-8", "-7", "-6", "-5", "-4", "-3", "-2", "-1",
"0", "+1", "+2", "+3", "+4", "+5", "+6", "+7",
"+8", "+9", "+10", "+11", "+12", "+13", "+14", "+15"
};
static char *deemph[4] = {
"no", "no", "75", "50"
};
static char *carrier[4] = {
"4.5 MHz",
"5.5 MHz",
"6.0 MHz",
"6.5 MHz / AM"
};
static char *vif[8] = {
"58.75 MHz",
"45.75 MHz",
"38.9 MHz",
"38.0 MHz",
"33.9 MHz",
"33.4 MHz",
"45.75 MHz + pin13",
"38.9 MHz + pin13",
};
static char *rif[4] = {
"44 MHz",
"52 MHz",
"52 MHz",
"44 MHz",
};
tuner_info("write: byte B 0x%02x\n", buf[1]);
tuner_info(" B0 video mode : %s\n",
(buf[1] & 0x01) ? "video trap" : "sound trap");
tuner_info(" B1 auto mute fm : %s\n",
(buf[1] & 0x02) ? "yes" : "no");
tuner_info(" B2 carrier mode : %s\n",
(buf[1] & 0x04) ? "QSS" : "Intercarrier");
tuner_info(" B3-4 tv sound/radio : %s\n",
sound[(buf[1] & 0x18) >> 3]);
tuner_info(" B5 force mute audio: %s\n",
(buf[1] & 0x20) ? "yes" : "no");
tuner_info(" B6 output port 1 : %s\n",
(buf[1] & 0x40) ? "high (inactive)" : "low (active)");
tuner_info(" B7 output port 2 : %s\n",
(buf[1] & 0x80) ? "high (inactive)" : "low (active)");
tuner_info("write: byte C 0x%02x\n", buf[2]);
tuner_info(" C0-4 top adjustment : %s dB\n",
adjust[buf[2] & 0x1f]);
tuner_info(" C5-6 de-emphasis : %s\n",
deemph[(buf[2] & 0x60) >> 5]);
tuner_info(" C7 audio gain : %s\n",
(buf[2] & 0x80) ? "-6" : "0");
tuner_info("write: byte E 0x%02x\n", buf[3]);
tuner_info(" E0-1 sound carrier : %s\n",
carrier[(buf[3] & 0x03)]);
tuner_info(" E6 l pll gating : %s\n",
(buf[3] & 0x40) ? "36" : "13");
if (buf[1] & 0x08) {
tuner_info(" E2-4 video if : %s\n",
rif[(buf[3] & 0x0c) >> 2]);
tuner_info(" E7 vif agc output : %s\n",
(buf[3] & 0x80)
? ((buf[3] & 0x10) ? "fm-agc radio" :
"sif-agc radio")
: "fm radio carrier afc");
} else {
tuner_info(" E2-4 video if : %s\n",
vif[(buf[3] & 0x1c) >> 2]);
tuner_info(" E5 tuner gain : %s\n",
(buf[3] & 0x80)
? ((buf[3] & 0x20) ? "external" : "normal")
: ((buf[3] & 0x20) ? "minimum" : "normal"));
tuner_info(" E7 vif agc output : %s\n",
(buf[3] & 0x80) ? ((buf[3] & 0x20)
? "pin3 port, pin22 vif agc out"
: "pin22 port, pin3 vif acg ext in")
: "pin3+pin22 port");
}
tuner_info("--\n");
}
static int tda9887_set_tvnorm(struct dvb_frontend *fe)
{
struct tda9887_priv *priv = fe->analog_demod_priv;
struct tvnorm *norm = NULL;
char *buf = priv->data;
int i;
if (priv->mode == V4L2_TUNER_RADIO) {
if (priv->audmode == V4L2_TUNER_MODE_MONO)
norm = &radio_mono;
else
norm = &radio_stereo;
} else {
for (i = 0; i < ARRAY_SIZE(tvnorms); i++) {
if (tvnorms[i].std & priv->std) {
norm = tvnorms+i;
break;
}
}
}
if (NULL == norm) {
tuner_dbg("Unsupported tvnorm entry - audio muted\n");
return -1;
}
tuner_dbg("configure for: %s\n", norm->name);
buf[1] = norm->b;
buf[2] = norm->c;
buf[3] = norm->e;
return 0;
}
static int tda9887_set_insmod(struct dvb_frontend *fe)
{
struct tda9887_priv *priv = fe->analog_demod_priv;
char *buf = priv->data;
if (UNSET != port1) {
if (port1)
buf[1] |= cOutputPort1Inactive;
else
buf[1] &= ~cOutputPort1Inactive;
}
if (UNSET != port2) {
if (port2)
buf[1] |= cOutputPort2Inactive;
else
buf[1] &= ~cOutputPort2Inactive;
}
if (UNSET != qss) {
if (qss)
buf[1] |= cQSS;
else
buf[1] &= ~cQSS;
}
if (adjust < 0x20) {
buf[2] &= ~cTopMask;
buf[2] |= adjust;
}
return 0;
}
static int tda9887_do_config(struct dvb_frontend *fe)
{
struct tda9887_priv *priv = fe->analog_demod_priv;
char *buf = priv->data;
if (priv->config & TDA9887_PORT1_ACTIVE)
buf[1] &= ~cOutputPort1Inactive;
if (priv->config & TDA9887_PORT1_INACTIVE)
buf[1] |= cOutputPort1Inactive;
if (priv->config & TDA9887_PORT2_ACTIVE)
buf[1] &= ~cOutputPort2Inactive;
if (priv->config & TDA9887_PORT2_INACTIVE)
buf[1] |= cOutputPort2Inactive;
if (priv->config & TDA9887_QSS)
buf[1] |= cQSS;
if (priv->config & TDA9887_INTERCARRIER)
buf[1] &= ~cQSS;
if (priv->config & TDA9887_AUTOMUTE)
buf[1] |= cAutoMuteFmActive;
if (priv->config & TDA9887_DEEMPHASIS_MASK) {
buf[2] &= ~0x60;
switch (priv->config & TDA9887_DEEMPHASIS_MASK) {
case TDA9887_DEEMPHASIS_NONE:
buf[2] |= cDeemphasisOFF;
break;
case TDA9887_DEEMPHASIS_50:
buf[2] |= cDeemphasisON | cDeemphasis50;
break;
case TDA9887_DEEMPHASIS_75:
buf[2] |= cDeemphasisON | cDeemphasis75;
break;
}
}
if (priv->config & TDA9887_TOP_SET) {
buf[2] &= ~cTopMask;
buf[2] |= (priv->config >> 8) & cTopMask;
}
if ((priv->config & TDA9887_INTERCARRIER_NTSC) &&
(priv->std & V4L2_STD_NTSC))
buf[1] &= ~cQSS;
if (priv->config & TDA9887_GATING_18)
buf[3] &= ~cGating_36;
if (priv->mode == V4L2_TUNER_RADIO) {
if (priv->config & TDA9887_RIF_41_3) {
buf[3] &= ~cVideoIFMask;
buf[3] |= cRadioIF_41_30;
}
if (priv->config & TDA9887_GAIN_NORMAL)
buf[3] &= ~cTunerGainLow;
}
return 0;
}
static int tda9887_status(struct dvb_frontend *fe)
{
struct tda9887_priv *priv = fe->analog_demod_priv;
unsigned char buf[1];
int rc;
memset(buf,0,sizeof(buf));
if (1 != (rc = tuner_i2c_xfer_recv(&priv->i2c_props,buf,1)))
tuner_info("i2c i/o error: rc == %d (should be 1)\n", rc);
dump_read_message(fe, buf);
return 0;
}
static void tda9887_configure(struct dvb_frontend *fe)
{
struct tda9887_priv *priv = fe->analog_demod_priv;
int rc;
memset(priv->data,0,sizeof(priv->data));
tda9887_set_tvnorm(fe);
priv->data[1] |= cOutputPort1Inactive;
priv->data[1] |= cOutputPort2Inactive;
tda9887_do_config(fe);
tda9887_set_insmod(fe);
if (priv->standby)
priv->data[1] |= cForcedMuteAudioON;
tuner_dbg("writing: b=0x%02x c=0x%02x e=0x%02x\n",
priv->data[1], priv->data[2], priv->data[3]);
if (debug > 1)
dump_write_message(fe, priv->data);
if (4 != (rc = tuner_i2c_xfer_send(&priv->i2c_props,priv->data,4)))
tuner_info("i2c i/o error: rc == %d (should be 4)\n", rc);
if (debug > 2) {
msleep_interruptible(1000);
tda9887_status(fe);
}
}
static void tda9887_tuner_status(struct dvb_frontend *fe)
{
struct tda9887_priv *priv = fe->analog_demod_priv;
tuner_info("Data bytes: b=0x%02x c=0x%02x e=0x%02x\n",
priv->data[1], priv->data[2], priv->data[3]);
}
static int tda9887_get_afc(struct dvb_frontend *fe)
{
struct tda9887_priv *priv = fe->analog_demod_priv;
static int AFC_BITS_2_kHz[] = {
-12500, -37500, -62500, -97500,
-112500, -137500, -162500, -187500,
187500, 162500, 137500, 112500,
97500 , 62500, 37500 , 12500
};
int afc=0;
__u8 reg = 0;
if (1 == tuner_i2c_xfer_recv(&priv->i2c_props,&reg,1))
afc = AFC_BITS_2_kHz[(reg>>1)&0x0f];
return afc;
}
static void tda9887_standby(struct dvb_frontend *fe)
{
struct tda9887_priv *priv = fe->analog_demod_priv;
priv->standby = true;
tda9887_configure(fe);
}
static void tda9887_set_params(struct dvb_frontend *fe,
struct analog_parameters *params)
{
struct tda9887_priv *priv = fe->analog_demod_priv;
priv->standby = false;
priv->mode = params->mode;
priv->audmode = params->audmode;
priv->std = params->std;
tda9887_configure(fe);
}
static int tda9887_set_config(struct dvb_frontend *fe, void *priv_cfg)
{
struct tda9887_priv *priv = fe->analog_demod_priv;
priv->config = *(unsigned int *)priv_cfg;
tda9887_configure(fe);
return 0;
}
static void tda9887_release(struct dvb_frontend *fe)
{
struct tda9887_priv *priv = fe->analog_demod_priv;
mutex_lock(&tda9887_list_mutex);
if (priv)
hybrid_tuner_release_state(priv);
mutex_unlock(&tda9887_list_mutex);
fe->analog_demod_priv = NULL;
}
struct dvb_frontend *tda9887_attach(struct dvb_frontend *fe,
struct i2c_adapter *i2c_adap,
u8 i2c_addr)
{
struct tda9887_priv *priv = NULL;
int instance;
mutex_lock(&tda9887_list_mutex);
instance = hybrid_tuner_request_state(struct tda9887_priv, priv,
hybrid_tuner_instance_list,
i2c_adap, i2c_addr, "tda9887");
switch (instance) {
case 0:
mutex_unlock(&tda9887_list_mutex);
return NULL;
case 1:
fe->analog_demod_priv = priv;
priv->standby = true;
tuner_info("tda988[5/6/7] found\n");
break;
default:
fe->analog_demod_priv = priv;
break;
}
mutex_unlock(&tda9887_list_mutex);
memcpy(&fe->ops.analog_ops, &tda9887_ops,
sizeof(struct analog_demod_ops));
return fe;
}
