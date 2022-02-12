static int cx24110_writereg (struct cx24110_state* state, int reg, int data)
{
u8 buf [] = { reg, data };
struct i2c_msg msg = { .addr = state->config->demod_address, .flags = 0, .buf = buf, .len = 2 };
int err;
if ((err = i2c_transfer(state->i2c, &msg, 1)) != 1) {
dprintk ("%s: writereg error (err == %i, reg == 0x%02x,"
" data == 0x%02x)\n", __func__, err, reg, data);
return -EREMOTEIO;
}
return 0;
}
static int cx24110_readreg (struct cx24110_state* state, u8 reg)
{
int ret;
u8 b0 [] = { reg };
u8 b1 [] = { 0 };
struct i2c_msg msg [] = { { .addr = state->config->demod_address, .flags = 0, .buf = b0, .len = 1 },
{ .addr = state->config->demod_address, .flags = I2C_M_RD, .buf = b1, .len = 1 } };
ret = i2c_transfer(state->i2c, msg, 2);
if (ret != 2) return ret;
return b1[0];
}
static int cx24110_set_inversion(struct cx24110_state *state,
enum fe_spectral_inversion inversion)
{
switch (inversion) {
case INVERSION_OFF:
cx24110_writereg(state,0x37,cx24110_readreg(state,0x37)|0x1);
cx24110_writereg(state,0x5,cx24110_readreg(state,0x5)&0xf7);
cx24110_writereg(state,0x22,cx24110_readreg(state,0x22)&0xef);
break;
case INVERSION_ON:
cx24110_writereg(state,0x37,cx24110_readreg(state,0x37)|0x1);
cx24110_writereg(state,0x5,cx24110_readreg(state,0x5)|0x08);
cx24110_writereg(state,0x22,cx24110_readreg(state,0x22)|0x10);
break;
case INVERSION_AUTO:
cx24110_writereg(state,0x37,cx24110_readreg(state,0x37)&0xfe);
break;
default:
return -EINVAL;
}
return 0;
}
static int cx24110_set_fec(struct cx24110_state *state, enum fe_code_rate fec)
{
static const int rate[FEC_AUTO] = {-1, 1, 2, 3, 5, 7, -1};
static const int g1[FEC_AUTO] = {-1, 0x01, 0x02, 0x05, 0x15, 0x45, -1};
static const int g2[FEC_AUTO] = {-1, 0x01, 0x03, 0x06, 0x1a, 0x7a, -1};
if (fec > FEC_AUTO)
fec = FEC_AUTO;
if (fec == FEC_AUTO) {
cx24110_writereg(state, 0x37, cx24110_readreg(state, 0x37) & 0xdf);
cx24110_writereg(state, 0x18, 0xae);
cx24110_writereg(state, 0x05, (cx24110_readreg(state, 0x05) & 0xf0) | 0x3);
cx24110_writereg(state, 0x22, (cx24110_readreg(state, 0x22) & 0xf0) | 0x3);
cx24110_writereg(state, 0x1a, 0x05);
cx24110_writereg(state, 0x1b, 0x06);
return 0;
} else {
cx24110_writereg(state, 0x37, cx24110_readreg(state, 0x37) | 0x20);
if (rate[fec] < 0)
return -EINVAL;
cx24110_writereg(state, 0x05, (cx24110_readreg(state, 0x05) & 0xf0) | rate[fec]);
cx24110_writereg(state, 0x22, (cx24110_readreg(state, 0x22) & 0xf0) | rate[fec]);
cx24110_writereg(state, 0x1a, g1[fec]);
cx24110_writereg(state, 0x1b, g2[fec]);
}
return 0;
}
static enum fe_code_rate cx24110_get_fec(struct cx24110_state *state)
{
int i;
i=cx24110_readreg(state,0x22)&0x0f;
if(!(i&0x08)) {
return FEC_1_2 + i - 1;
} else {
return FEC_NONE;
}
}
static int cx24110_set_symbolrate (struct cx24110_state* state, u32 srate)
{
u32 ratio;
u32 tmp, fclk, BDRI;
static const u32 bands[]={5000000UL,15000000UL,90999000UL/2};
int i;
dprintk("cx24110 debug: entering %s(%d)\n",__func__,srate);
if (srate>90999000UL/2)
srate=90999000UL/2;
if (srate<500000)
srate=500000;
for(i = 0; (i < ARRAY_SIZE(bands)) && (srate>bands[i]); i++)
;
tmp=cx24110_readreg(state,0x07)&0xfc;
if(srate<90999000UL/4) {
cx24110_writereg(state,0x07,tmp);
cx24110_writereg(state,0x06,0x78);
fclk=90999000UL/2;
} else if(srate<60666000UL/2) {
cx24110_writereg(state,0x07,tmp|0x1);
cx24110_writereg(state,0x06,0xa5);
fclk=60666000UL;
} else if(srate<80888000UL/2) {
cx24110_writereg(state,0x07,tmp|0x2);
cx24110_writereg(state,0x06,0x87);
fclk=80888000UL;
} else {
cx24110_writereg(state,0x07,tmp|0x3);
cx24110_writereg(state,0x06,0x78);
fclk=90999000UL;
}
dprintk("cx24110 debug: fclk %d Hz\n",fclk);
tmp=srate<<6;
BDRI=fclk>>2;
ratio=(tmp/BDRI);
tmp=(tmp%BDRI)<<8;
ratio=(ratio<<8)+(tmp/BDRI);
tmp=(tmp%BDRI)<<8;
ratio=(ratio<<8)+(tmp/BDRI);
tmp=(tmp%BDRI)<<1;
ratio=(ratio<<1)+(tmp/BDRI);
dprintk("srate= %d (range %d, up to %d)\n", srate,i,bands[i]);
dprintk("fclk = %d\n", fclk);
dprintk("ratio= %08x\n", ratio);
cx24110_writereg(state, 0x1, (ratio>>16)&0xff);
cx24110_writereg(state, 0x2, (ratio>>8)&0xff);
cx24110_writereg(state, 0x3, (ratio)&0xff);
return 0;
}
static int _cx24110_pll_write (struct dvb_frontend* fe, const u8 buf[], int len)
{
struct cx24110_state *state = fe->demodulator_priv;
if (len != 3)
return -EINVAL;
cx24110_writereg(state,0x6d,0x30);
cx24110_writereg(state,0x70,0x15);
while (cx24110_readreg(state,0x6d)&0x80)
cx24110_writereg(state,0x72,0);
cx24110_writereg(state,0x72,buf[0]);
while ((cx24110_readreg(state,0x6d)&0xc0)==0x80)
;
cx24110_writereg(state,0x72,buf[1]);
while ((cx24110_readreg(state,0x6d)&0xc0)==0x80)
;
cx24110_writereg(state,0x72,buf[2]);
while ((cx24110_readreg(state,0x6d)&0xc0)==0x80)
;
cx24110_writereg(state,0x6d,0x32);
cx24110_writereg(state,0x6d,0x30);
return 0;
}
static int cx24110_initfe(struct dvb_frontend* fe)
{
struct cx24110_state *state = fe->demodulator_priv;
int i;
dprintk("%s: init chip\n", __func__);
for(i = 0; i < ARRAY_SIZE(cx24110_regdata); i++) {
cx24110_writereg(state, cx24110_regdata[i].reg, cx24110_regdata[i].data);
}
return 0;
}
static int cx24110_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage voltage)
{
struct cx24110_state *state = fe->demodulator_priv;
switch (voltage) {
case SEC_VOLTAGE_13:
return cx24110_writereg(state,0x76,(cx24110_readreg(state,0x76)&0x3b)|0xc0);
case SEC_VOLTAGE_18:
return cx24110_writereg(state,0x76,(cx24110_readreg(state,0x76)&0x3b)|0x40);
default:
return -EINVAL;
}
}
static int cx24110_diseqc_send_burst(struct dvb_frontend *fe,
enum fe_sec_mini_cmd burst)
{
int rv, bit;
struct cx24110_state *state = fe->demodulator_priv;
unsigned long timeout;
if (burst == SEC_MINI_A)
bit = 0x00;
else if (burst == SEC_MINI_B)
bit = 0x08;
else
return -EINVAL;
rv = cx24110_readreg(state, 0x77);
if (!(rv & 0x04))
cx24110_writereg(state, 0x77, rv | 0x04);
rv = cx24110_readreg(state, 0x76);
cx24110_writereg(state, 0x76, ((rv & 0x90) | 0x40 | bit));
timeout = jiffies + msecs_to_jiffies(100);
while (!time_after(jiffies, timeout) && !(cx24110_readreg(state, 0x76) & 0x40))
;
return 0;
}
static int cx24110_send_diseqc_msg(struct dvb_frontend* fe,
struct dvb_diseqc_master_cmd *cmd)
{
int i, rv;
struct cx24110_state *state = fe->demodulator_priv;
unsigned long timeout;
if (cmd->msg_len < 3 || cmd->msg_len > 6)
return -EINVAL;
for (i = 0; i < cmd->msg_len; i++)
cx24110_writereg(state, 0x79 + i, cmd->msg[i]);
rv = cx24110_readreg(state, 0x77);
if (rv & 0x04) {
cx24110_writereg(state, 0x77, rv & ~0x04);
msleep(30);
}
rv = cx24110_readreg(state, 0x76);
cx24110_writereg(state, 0x76, ((rv & 0x90) | 0x40) | ((cmd->msg_len-3) & 3));
timeout = jiffies + msecs_to_jiffies(100);
while (!time_after(jiffies, timeout) && !(cx24110_readreg(state, 0x76) & 0x40))
;
return 0;
}
static int cx24110_read_status(struct dvb_frontend *fe,
enum fe_status *status)
{
struct cx24110_state *state = fe->demodulator_priv;
int sync = cx24110_readreg (state, 0x55);
*status = 0;
if (sync & 0x10)
*status |= FE_HAS_SIGNAL;
if (sync & 0x08)
*status |= FE_HAS_CARRIER;
sync = cx24110_readreg (state, 0x08);
if (sync & 0x40)
*status |= FE_HAS_VITERBI;
if (sync & 0x20)
*status |= FE_HAS_SYNC;
if ((sync & 0x60) == 0x60)
*status |= FE_HAS_LOCK;
return 0;
}
static int cx24110_read_ber(struct dvb_frontend* fe, u32* ber)
{
struct cx24110_state *state = fe->demodulator_priv;
if(cx24110_readreg(state,0x24)&0x10) {
cx24110_writereg(state,0x24,0x04);
state->lastber=cx24110_readreg(state,0x25)|
(cx24110_readreg(state,0x26)<<8);
cx24110_writereg(state,0x24,0x04);
cx24110_writereg(state,0x24,0x14);
}
*ber = state->lastber;
return 0;
}
static int cx24110_read_signal_strength(struct dvb_frontend* fe, u16* signal_strength)
{
struct cx24110_state *state = fe->demodulator_priv;
u8 signal = cx24110_readreg (state, 0x27)+128;
*signal_strength = (signal << 8) | signal;
return 0;
}
static int cx24110_read_snr(struct dvb_frontend* fe, u16* snr)
{
struct cx24110_state *state = fe->demodulator_priv;
if(cx24110_readreg(state,0x6a)&0x80) {
state->lastesn0=cx24110_readreg(state,0x69)|
(cx24110_readreg(state,0x68)<<8);
cx24110_writereg(state,0x6a,0x84);
}
*snr = state->lastesn0;
return 0;
}
static int cx24110_read_ucblocks(struct dvb_frontend* fe, u32* ucblocks)
{
struct cx24110_state *state = fe->demodulator_priv;
if(cx24110_readreg(state,0x10)&0x40) {
cx24110_writereg(state,0x10,0x60);
(void)(cx24110_readreg(state, 0x12) |
(cx24110_readreg(state, 0x13) << 8) |
(cx24110_readreg(state, 0x14) << 16));
cx24110_writereg(state,0x10,0x70);
state->lastbler=cx24110_readreg(state,0x12)|
(cx24110_readreg(state,0x13)<<8)|
(cx24110_readreg(state,0x14)<<16);
cx24110_writereg(state,0x10,0x20);
}
*ucblocks = state->lastbler;
return 0;
}
static int cx24110_set_frontend(struct dvb_frontend *fe)
{
struct cx24110_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
if (fe->ops.tuner_ops.set_params) {
fe->ops.tuner_ops.set_params(fe);
if (fe->ops.i2c_gate_ctrl) fe->ops.i2c_gate_ctrl(fe, 0);
}
cx24110_set_inversion(state, p->inversion);
cx24110_set_fec(state, p->fec_inner);
cx24110_set_symbolrate(state, p->symbol_rate);
cx24110_writereg(state,0x04,0x05);
return 0;
}
static int cx24110_get_frontend(struct dvb_frontend *fe,
struct dtv_frontend_properties *p)
{
struct cx24110_state *state = fe->demodulator_priv;
s32 afc; unsigned sclk;
sclk = cx24110_readreg (state, 0x07) & 0x03;
if (sclk==0) sclk=90999000L/2L;
else if (sclk==1) sclk=60666000L;
else if (sclk==2) sclk=80888000L;
else sclk=90999000L;
sclk>>=8;
afc = sclk*(cx24110_readreg (state, 0x44)&0x1f)+
((sclk*cx24110_readreg (state, 0x45))>>8)+
((sclk*cx24110_readreg (state, 0x46))>>16);
p->frequency += afc;
p->inversion = (cx24110_readreg (state, 0x22) & 0x10) ?
INVERSION_ON : INVERSION_OFF;
p->fec_inner = cx24110_get_fec(state);
return 0;
}
static int cx24110_set_tone(struct dvb_frontend *fe,
enum fe_sec_tone_mode tone)
{
struct cx24110_state *state = fe->demodulator_priv;
return cx24110_writereg(state,0x76,(cx24110_readreg(state,0x76)&~0x10)|(((tone==SEC_TONE_ON))?0x10:0));
}
static void cx24110_release(struct dvb_frontend* fe)
{
struct cx24110_state* state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend* cx24110_attach(const struct cx24110_config* config,
struct i2c_adapter* i2c)
{
struct cx24110_state* state = NULL;
int ret;
state = kzalloc(sizeof(struct cx24110_state), GFP_KERNEL);
if (state == NULL) goto error;
state->config = config;
state->i2c = i2c;
state->lastber = 0;
state->lastbler = 0;
state->lastesn0 = 0;
ret = cx24110_readreg(state, 0x00);
if ((ret != 0x5a) && (ret != 0x69)) goto error;
memcpy(&state->frontend.ops, &cx24110_ops, sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error:
kfree(state);
return NULL;
}
