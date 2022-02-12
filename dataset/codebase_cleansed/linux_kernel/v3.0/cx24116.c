static int cx24116_writereg(struct cx24116_state *state, int reg, int data)
{
u8 buf[] = { reg, data };
struct i2c_msg msg = { .addr = state->config->demod_address,
.flags = 0, .buf = buf, .len = 2 };
int err;
if (debug > 1)
printk("cx24116: %s: write reg 0x%02x, value 0x%02x\n",
__func__, reg, data);
err = i2c_transfer(state->i2c, &msg, 1);
if (err != 1) {
printk(KERN_ERR "%s: writereg error(err == %i, reg == 0x%02x,"
" value == 0x%02x)\n", __func__, err, reg, data);
return -EREMOTEIO;
}
return 0;
}
static int cx24116_writeregN(struct cx24116_state *state, int reg,
const u8 *data, u16 len)
{
int ret = -EREMOTEIO;
struct i2c_msg msg;
u8 *buf;
buf = kmalloc(len + 1, GFP_KERNEL);
if (buf == NULL) {
printk("Unable to kmalloc\n");
ret = -ENOMEM;
goto error;
}
*(buf) = reg;
memcpy(buf + 1, data, len);
msg.addr = state->config->demod_address;
msg.flags = 0;
msg.buf = buf;
msg.len = len + 1;
if (debug > 1)
printk(KERN_INFO "cx24116: %s: write regN 0x%02x, len = %d\n",
__func__, reg, len);
ret = i2c_transfer(state->i2c, &msg, 1);
if (ret != 1) {
printk(KERN_ERR "%s: writereg error(err == %i, reg == 0x%02x\n",
__func__, ret, reg);
ret = -EREMOTEIO;
}
error:
kfree(buf);
return ret;
}
static int cx24116_readreg(struct cx24116_state *state, u8 reg)
{
int ret;
u8 b0[] = { reg };
u8 b1[] = { 0 };
struct i2c_msg msg[] = {
{ .addr = state->config->demod_address, .flags = 0,
.buf = b0, .len = 1 },
{ .addr = state->config->demod_address, .flags = I2C_M_RD,
.buf = b1, .len = 1 }
};
ret = i2c_transfer(state->i2c, msg, 2);
if (ret != 2) {
printk(KERN_ERR "%s: reg=0x%x (error=%d)\n",
__func__, reg, ret);
return ret;
}
if (debug > 1)
printk(KERN_INFO "cx24116: read reg 0x%02x, value 0x%02x\n",
reg, b1[0]);
return b1[0];
}
static int cx24116_set_inversion(struct cx24116_state *state,
fe_spectral_inversion_t inversion)
{
dprintk("%s(%d)\n", __func__, inversion);
switch (inversion) {
case INVERSION_OFF:
state->dnxt.inversion_val = 0x00;
break;
case INVERSION_ON:
state->dnxt.inversion_val = 0x04;
break;
case INVERSION_AUTO:
state->dnxt.inversion_val = 0x0C;
break;
default:
return -EINVAL;
}
state->dnxt.inversion = inversion;
return 0;
}
static int cx24116_lookup_fecmod(struct cx24116_state *state,
fe_delivery_system_t d, fe_modulation_t m, fe_code_rate_t f)
{
int i, ret = -EOPNOTSUPP;
dprintk("%s(0x%02x,0x%02x)\n", __func__, m, f);
for (i = 0; i < ARRAY_SIZE(CX24116_MODFEC_MODES); i++) {
if ((d == CX24116_MODFEC_MODES[i].delivery_system) &&
(m == CX24116_MODFEC_MODES[i].modulation) &&
(f == CX24116_MODFEC_MODES[i].fec)) {
ret = i;
break;
}
}
return ret;
}
static int cx24116_set_fec(struct cx24116_state *state,
fe_delivery_system_t delsys, fe_modulation_t mod, fe_code_rate_t fec)
{
int ret = 0;
dprintk("%s(0x%02x,0x%02x)\n", __func__, mod, fec);
ret = cx24116_lookup_fecmod(state, delsys, mod, fec);
if (ret < 0)
return ret;
state->dnxt.fec = fec;
state->dnxt.fec_val = CX24116_MODFEC_MODES[ret].val;
state->dnxt.fec_mask = CX24116_MODFEC_MODES[ret].mask;
dprintk("%s() mask/val = 0x%02x/0x%02x\n", __func__,
state->dnxt.fec_mask, state->dnxt.fec_val);
return 0;
}
static int cx24116_set_symbolrate(struct cx24116_state *state, u32 rate)
{
dprintk("%s(%d)\n", __func__, rate);
if ((rate > state->frontend.ops.info.symbol_rate_max) ||
(rate < state->frontend.ops.info.symbol_rate_min)) {
dprintk("%s() unsupported symbol_rate = %d\n", __func__, rate);
return -EOPNOTSUPP;
}
state->dnxt.symbol_rate = rate;
dprintk("%s() symbol_rate = %d\n", __func__, rate);
return 0;
}
static int cx24116_firmware_ondemand(struct dvb_frontend *fe)
{
struct cx24116_state *state = fe->demodulator_priv;
const struct firmware *fw;
int ret = 0;
dprintk("%s()\n", __func__);
if (cx24116_readreg(state, 0x20) > 0) {
if (state->skip_fw_load)
return 0;
printk(KERN_INFO "%s: Waiting for firmware upload (%s)...\n",
__func__, CX24116_DEFAULT_FIRMWARE);
ret = request_firmware(&fw, CX24116_DEFAULT_FIRMWARE,
state->i2c->dev.parent);
printk(KERN_INFO "%s: Waiting for firmware upload(2)...\n",
__func__);
if (ret) {
printk(KERN_ERR "%s: No firmware uploaded "
"(timeout or file not found?)\n", __func__);
return ret;
}
state->skip_fw_load = 1;
ret = cx24116_load_firmware(fe, fw);
if (ret)
printk(KERN_ERR "%s: Writing firmware to device failed\n",
__func__);
release_firmware(fw);
printk(KERN_INFO "%s: Firmware upload %s\n", __func__,
ret == 0 ? "complete" : "failed");
state->skip_fw_load = 0;
}
return ret;
}
static int cx24116_cmd_execute(struct dvb_frontend *fe, struct cx24116_cmd *cmd)
{
struct cx24116_state *state = fe->demodulator_priv;
int i, ret;
dprintk("%s()\n", __func__);
ret = cx24116_firmware_ondemand(fe);
if (ret != 0) {
printk(KERN_ERR "%s(): Unable initialise the firmware\n",
__func__);
return ret;
}
for (i = 0; i < cmd->len ; i++) {
dprintk("%s: 0x%02x == 0x%02x\n", __func__, i, cmd->args[i]);
cx24116_writereg(state, i, cmd->args[i]);
}
cx24116_writereg(state, CX24116_REG_EXECUTE, 0x01);
while (cx24116_readreg(state, CX24116_REG_EXECUTE)) {
msleep(10);
if (i++ > 64) {
printk(KERN_WARNING "%s() Firmware not responding\n",
__func__);
return -EREMOTEIO;
}
}
return 0;
}
static int cx24116_load_firmware(struct dvb_frontend *fe,
const struct firmware *fw)
{
struct cx24116_state *state = fe->demodulator_priv;
struct cx24116_cmd cmd;
int i, ret, len, max, remaining;
unsigned char vers[4];
dprintk("%s\n", __func__);
dprintk("Firmware is %zu bytes (%02x %02x .. %02x %02x)\n",
fw->size,
fw->data[0],
fw->data[1],
fw->data[fw->size-2],
fw->data[fw->size-1]);
if (state->config->reset_device)
state->config->reset_device(fe);
cx24116_writereg(state, 0xE5, 0x00);
cx24116_writereg(state, 0xF1, 0x08);
cx24116_writereg(state, 0xF2, 0x13);
cx24116_writereg(state, 0xe0, 0x03);
cx24116_writereg(state, 0xe0, 0x00);
cx24116_writereg(state, CX24116_REG_CLKDIV, 0x46);
cx24116_writereg(state, CX24116_REG_RATEDIV, 0x00);
cx24116_writereg(state, 0xF0, 0x03);
cx24116_writereg(state, 0xF4, 0x81);
cx24116_writereg(state, 0xF5, 0x00);
cx24116_writereg(state, 0xF6, 0x00);
if (state->config->i2c_wr_max)
max = state->config->i2c_wr_max;
else
max = INT_MAX;
for (remaining = fw->size; remaining > 0; remaining -= max - 1) {
len = remaining;
if (len > max - 1)
len = max - 1;
cx24116_writeregN(state, 0xF7, &fw->data[fw->size - remaining],
len);
}
cx24116_writereg(state, 0xF4, 0x10);
cx24116_writereg(state, 0xF0, 0x00);
cx24116_writereg(state, 0xF8, 0x06);
cmd.args[0x00] = CMD_SET_VCO;
cmd.args[0x01] = 0x05;
cmd.args[0x02] = 0xdc;
cmd.args[0x03] = 0xda;
cmd.args[0x04] = 0xae;
cmd.args[0x05] = 0xaa;
cmd.args[0x06] = 0x04;
cmd.args[0x07] = 0x9d;
cmd.args[0x08] = 0xfc;
cmd.args[0x09] = 0x06;
cmd.len = 0x0a;
ret = cx24116_cmd_execute(fe, &cmd);
if (ret != 0)
return ret;
cx24116_writereg(state, CX24116_REG_SSTATUS, 0x00);
cmd.args[0x00] = CMD_TUNERINIT;
cmd.args[0x01] = 0x00;
cmd.args[0x02] = 0x00;
cmd.len = 0x03;
ret = cx24116_cmd_execute(fe, &cmd);
if (ret != 0)
return ret;
cx24116_writereg(state, 0xe5, 0x00);
cmd.args[0x00] = CMD_MPEGCONFIG;
cmd.args[0x01] = 0x01;
cmd.args[0x02] = 0x75;
cmd.args[0x03] = 0x00;
if (state->config->mpg_clk_pos_pol)
cmd.args[0x04] = state->config->mpg_clk_pos_pol;
else
cmd.args[0x04] = 0x02;
cmd.args[0x05] = 0x00;
cmd.len = 0x06;
ret = cx24116_cmd_execute(fe, &cmd);
if (ret != 0)
return ret;
cmd.args[0x00] = CMD_UPDFWVERS;
cmd.len = 0x02;
for (i = 0; i < 4; i++) {
cmd.args[0x01] = i;
ret = cx24116_cmd_execute(fe, &cmd);
if (ret != 0)
return ret;
vers[i] = cx24116_readreg(state, CX24116_REG_MAILBOX);
}
printk(KERN_INFO "%s: FW version %i.%i.%i.%i\n", __func__,
vers[0], vers[1], vers[2], vers[3]);
return 0;
}
static int cx24116_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct cx24116_state *state = fe->demodulator_priv;
int lock = cx24116_readreg(state, CX24116_REG_SSTATUS) &
CX24116_STATUS_MASK;
dprintk("%s: status = 0x%02x\n", __func__, lock);
*status = 0;
if (lock & CX24116_HAS_SIGNAL)
*status |= FE_HAS_SIGNAL;
if (lock & CX24116_HAS_CARRIER)
*status |= FE_HAS_CARRIER;
if (lock & CX24116_HAS_VITERBI)
*status |= FE_HAS_VITERBI;
if (lock & CX24116_HAS_SYNCLOCK)
*status |= FE_HAS_SYNC | FE_HAS_LOCK;
return 0;
}
static int cx24116_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct cx24116_state *state = fe->demodulator_priv;
dprintk("%s()\n", __func__);
*ber = (cx24116_readreg(state, CX24116_REG_BER24) << 24) |
(cx24116_readreg(state, CX24116_REG_BER16) << 16) |
(cx24116_readreg(state, CX24116_REG_BER8) << 8) |
cx24116_readreg(state, CX24116_REG_BER0);
return 0;
}
static int cx24116_read_signal_strength(struct dvb_frontend *fe,
u16 *signal_strength)
{
struct cx24116_state *state = fe->demodulator_priv;
struct cx24116_cmd cmd;
int ret;
u16 sig_reading;
dprintk("%s()\n", __func__);
cmd.args[0x00] = CMD_GETAGC;
cmd.len = 0x01;
ret = cx24116_cmd_execute(fe, &cmd);
if (ret != 0)
return ret;
sig_reading =
(cx24116_readreg(state,
CX24116_REG_SSTATUS) & CX24116_SIGNAL_MASK) |
(cx24116_readreg(state, CX24116_REG_SIGNAL) << 6);
*signal_strength = 0 - sig_reading;
dprintk("%s: raw / cooked = 0x%04x / 0x%04x\n",
__func__, sig_reading, *signal_strength);
return 0;
}
static int cx24116_read_snr_pct(struct dvb_frontend *fe, u16 *snr)
{
struct cx24116_state *state = fe->demodulator_priv;
u8 snr_reading;
static const u32 snr_tab[] = {
0x00000, 0x0199A, 0x03333, 0x04ccD, 0x06667,
0x08000, 0x0999A, 0x0b333, 0x0cccD, 0x0e667,
0x10000, 0x1199A, 0x13333, 0x14ccD, 0x16667,
0x18000 };
dprintk("%s()\n", __func__);
snr_reading = cx24116_readreg(state, CX24116_REG_QUALITY0);
if (snr_reading >= 0xa0 )
*snr = 0xffff;
else
*snr = snr_tab[(snr_reading & 0xf0) >> 4] +
(snr_tab[(snr_reading & 0x0f)] >> 4);
dprintk("%s: raw / cooked = 0x%02x / 0x%04x\n", __func__,
snr_reading, *snr);
return 0;
}
static int cx24116_read_snr_esno(struct dvb_frontend *fe, u16 *snr)
{
struct cx24116_state *state = fe->demodulator_priv;
dprintk("%s()\n", __func__);
*snr = cx24116_readreg(state, CX24116_REG_QUALITY8) << 8 |
cx24116_readreg(state, CX24116_REG_QUALITY0);
dprintk("%s: raw 0x%04x\n", __func__, *snr);
return 0;
}
static int cx24116_read_snr(struct dvb_frontend *fe, u16 *snr)
{
if (esno_snr == 1)
return cx24116_read_snr_esno(fe, snr);
else
return cx24116_read_snr_pct(fe, snr);
}
static int cx24116_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
struct cx24116_state *state = fe->demodulator_priv;
dprintk("%s()\n", __func__);
*ucblocks = (cx24116_readreg(state, CX24116_REG_UCB8) << 8) |
cx24116_readreg(state, CX24116_REG_UCB0);
return 0;
}
static void cx24116_clone_params(struct dvb_frontend *fe)
{
struct cx24116_state *state = fe->demodulator_priv;
memcpy(&state->dcur, &state->dnxt, sizeof(state->dcur));
}
static int cx24116_wait_for_lnb(struct dvb_frontend *fe)
{
struct cx24116_state *state = fe->demodulator_priv;
int i;
dprintk("%s() qstatus = 0x%02x\n", __func__,
cx24116_readreg(state, CX24116_REG_QSTATUS));
for (i = 0; i < 30 ; i++) {
if (cx24116_readreg(state, CX24116_REG_QSTATUS) & 0x20)
return 0;
msleep(10);
}
dprintk("%s(): LNB not ready\n", __func__);
return -ETIMEDOUT;
}
static int cx24116_set_voltage(struct dvb_frontend *fe,
fe_sec_voltage_t voltage)
{
struct cx24116_cmd cmd;
int ret;
dprintk("%s: %s\n", __func__,
voltage == SEC_VOLTAGE_13 ? "SEC_VOLTAGE_13" :
voltage == SEC_VOLTAGE_18 ? "SEC_VOLTAGE_18" : "??");
ret = cx24116_wait_for_lnb(fe);
if (ret != 0)
return ret;
msleep(100);
cmd.args[0x00] = CMD_LNBDCLEVEL;
cmd.args[0x01] = (voltage == SEC_VOLTAGE_18 ? 0x01 : 0x00);
cmd.len = 0x02;
msleep(15);
return cx24116_cmd_execute(fe, &cmd);
}
static int cx24116_set_tone(struct dvb_frontend *fe,
fe_sec_tone_mode_t tone)
{
struct cx24116_cmd cmd;
int ret;
dprintk("%s(%d)\n", __func__, tone);
if ((tone != SEC_TONE_ON) && (tone != SEC_TONE_OFF)) {
printk(KERN_ERR "%s: Invalid, tone=%d\n", __func__, tone);
return -EINVAL;
}
ret = cx24116_wait_for_lnb(fe);
if (ret != 0)
return ret;
msleep(15);
cmd.args[0x00] = CMD_SET_TONE;
cmd.args[0x01] = 0x00;
cmd.args[0x02] = 0x00;
switch (tone) {
case SEC_TONE_ON:
dprintk("%s: setting tone on\n", __func__);
cmd.args[0x03] = 0x01;
break;
case SEC_TONE_OFF:
dprintk("%s: setting tone off\n", __func__);
cmd.args[0x03] = 0x00;
break;
}
cmd.len = 0x04;
msleep(15);
return cx24116_cmd_execute(fe, &cmd);
}
static int cx24116_diseqc_init(struct dvb_frontend *fe)
{
struct cx24116_state *state = fe->demodulator_priv;
struct cx24116_cmd cmd;
int ret;
cmd.args[0x00] = CMD_LNBCONFIG;
cmd.args[0x01] = 0x00;
cmd.args[0x02] = 0x10;
cmd.args[0x03] = 0x00;
cmd.args[0x04] = 0x8f;
cmd.args[0x05] = 0x28;
cmd.args[0x06] = (toneburst == CX24116_DISEQC_TONEOFF) ? 0x00 : 0x01;
cmd.args[0x07] = 0x01;
cmd.len = 0x08;
ret = cx24116_cmd_execute(fe, &cmd);
if (ret != 0)
return ret;
state->dsec_cmd.args[0x00] = CMD_LNBSEND;
state->dsec_cmd.args[CX24116_DISEQC_BURST] = CX24116_DISEQC_MINI_A;
state->dsec_cmd.args[CX24116_DISEQC_ARG2_2] = 0x02;
state->dsec_cmd.args[CX24116_DISEQC_ARG3_0] = 0x00;
state->dsec_cmd.args[CX24116_DISEQC_ARG4_0] = 0x00;
state->dsec_cmd.args[CX24116_DISEQC_MSGLEN] = 0x00;
state->dsec_cmd.len = CX24116_DISEQC_MSGOFS;
return 0;
}
static int cx24116_send_diseqc_msg(struct dvb_frontend *fe,
struct dvb_diseqc_master_cmd *d)
{
struct cx24116_state *state = fe->demodulator_priv;
int i, ret;
if (debug) {
printk(KERN_INFO "cx24116: %s(", __func__);
for (i = 0 ; i < d->msg_len ;) {
printk(KERN_INFO "0x%02x", d->msg[i]);
if (++i < d->msg_len)
printk(KERN_INFO ", ");
}
printk(") toneburst=%d\n", toneburst);
}
if (d->msg_len > (CX24116_ARGLEN - CX24116_DISEQC_MSGOFS))
return -EINVAL;
for (i = 0; i < d->msg_len; i++)
state->dsec_cmd.args[CX24116_DISEQC_MSGOFS + i] = d->msg[i];
state->dsec_cmd.args[CX24116_DISEQC_MSGLEN] = d->msg_len;
state->dsec_cmd.len = CX24116_DISEQC_MSGOFS +
state->dsec_cmd.args[CX24116_DISEQC_MSGLEN];
if (toneburst == CX24116_DISEQC_MESGCACHE)
return 0;
else if (toneburst == CX24116_DISEQC_TONEOFF)
state->dsec_cmd.args[CX24116_DISEQC_BURST] = 0;
else if (toneburst == CX24116_DISEQC_TONECACHE) {
if (d->msg_len >= 4 && d->msg[2] == 0x38)
state->dsec_cmd.args[CX24116_DISEQC_BURST] =
((d->msg[3] & 4) >> 2);
if (debug)
dprintk("%s burst=%d\n", __func__,
state->dsec_cmd.args[CX24116_DISEQC_BURST]);
}
ret = cx24116_wait_for_lnb(fe);
if (ret != 0)
return ret;
msleep(100);
ret = cx24116_cmd_execute(fe, &state->dsec_cmd);
if (ret != 0)
return ret;
msleep((state->dsec_cmd.args[CX24116_DISEQC_MSGLEN] << 4) +
((toneburst == CX24116_DISEQC_TONEOFF) ? 30 : 60));
return 0;
}
static int cx24116_diseqc_send_burst(struct dvb_frontend *fe,
fe_sec_mini_cmd_t burst)
{
struct cx24116_state *state = fe->demodulator_priv;
int ret;
dprintk("%s(%d) toneburst=%d\n", __func__, burst, toneburst);
if (burst == SEC_MINI_A)
state->dsec_cmd.args[CX24116_DISEQC_BURST] =
CX24116_DISEQC_MINI_A;
else if (burst == SEC_MINI_B)
state->dsec_cmd.args[CX24116_DISEQC_BURST] =
CX24116_DISEQC_MINI_B;
else
return -EINVAL;
if (toneburst != CX24116_DISEQC_MESGCACHE)
return 0;
ret = cx24116_wait_for_lnb(fe);
if (ret != 0)
return ret;
msleep(100);
ret = cx24116_cmd_execute(fe, &state->dsec_cmd);
if (ret != 0)
return ret;
msleep((state->dsec_cmd.args[CX24116_DISEQC_MSGLEN] << 4) + 60);
return 0;
}
static void cx24116_release(struct dvb_frontend *fe)
{
struct cx24116_state *state = fe->demodulator_priv;
dprintk("%s\n", __func__);
kfree(state);
}
struct dvb_frontend *cx24116_attach(const struct cx24116_config *config,
struct i2c_adapter *i2c)
{
struct cx24116_state *state = NULL;
int ret;
dprintk("%s\n", __func__);
state = kzalloc(sizeof(struct cx24116_state), GFP_KERNEL);
if (state == NULL)
goto error1;
state->config = config;
state->i2c = i2c;
ret = (cx24116_readreg(state, 0xFF) << 8) |
cx24116_readreg(state, 0xFE);
if (ret != 0x0501) {
printk(KERN_INFO "Invalid probe, probably not a CX24116 device\n");
goto error2;
}
memcpy(&state->frontend.ops, &cx24116_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error2: kfree(state);
error1: return NULL;
}
static int cx24116_initfe(struct dvb_frontend *fe)
{
struct cx24116_state *state = fe->demodulator_priv;
struct cx24116_cmd cmd;
int ret;
dprintk("%s()\n", __func__);
cx24116_writereg(state, 0xe0, 0);
cx24116_writereg(state, 0xe1, 0);
cx24116_writereg(state, 0xea, 0);
cmd.args[0x00] = CMD_TUNERSLEEP;
cmd.args[0x01] = 0;
cmd.len = 0x02;
ret = cx24116_cmd_execute(fe, &cmd);
if (ret != 0)
return ret;
ret = cx24116_diseqc_init(fe);
if (ret != 0)
return ret;
return cx24116_set_voltage(fe, SEC_VOLTAGE_13);
}
static int cx24116_sleep(struct dvb_frontend *fe)
{
struct cx24116_state *state = fe->demodulator_priv;
struct cx24116_cmd cmd;
int ret;
dprintk("%s()\n", __func__);
cmd.args[0x00] = CMD_TUNERSLEEP;
cmd.args[0x01] = 1;
cmd.len = 0x02;
ret = cx24116_cmd_execute(fe, &cmd);
if (ret != 0)
return ret;
cx24116_writereg(state, 0xea, 0xff);
cx24116_writereg(state, 0xe1, 1);
cx24116_writereg(state, 0xe0, 1);
return 0;
}
static int cx24116_set_property(struct dvb_frontend *fe,
struct dtv_property *tvp)
{
dprintk("%s(..)\n", __func__);
return 0;
}
static int cx24116_get_property(struct dvb_frontend *fe,
struct dtv_property *tvp)
{
dprintk("%s(..)\n", __func__);
return 0;
}
static int cx24116_set_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *p)
{
struct cx24116_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct cx24116_cmd cmd;
fe_status_t tunerstat;
int i, status, ret, retune = 1;
dprintk("%s()\n", __func__);
switch (c->delivery_system) {
case SYS_DVBS:
dprintk("%s: DVB-S delivery system selected\n", __func__);
if (c->modulation != QPSK) {
dprintk("%s: unsupported modulation selected (%d)\n",
__func__, c->modulation);
return -EOPNOTSUPP;
}
state->dnxt.pilot_val = CX24116_PILOT_OFF;
if (c->rolloff != ROLLOFF_35) {
dprintk("%s: unsupported rolloff selected (%d)\n",
__func__, c->rolloff);
return -EOPNOTSUPP;
}
state->dnxt.rolloff_val = CX24116_ROLLOFF_035;
break;
case SYS_DVBS2:
dprintk("%s: DVB-S2 delivery system selected\n", __func__);
if (c->modulation != PSK_8 && c->modulation != QPSK) {
dprintk("%s: unsupported modulation selected (%d)\n",
__func__, c->modulation);
return -EOPNOTSUPP;
}
switch (c->pilot) {
case PILOT_AUTO:
state->dnxt.pilot_val = (c->modulation == QPSK)
? CX24116_PILOT_OFF : CX24116_PILOT_ON;
retune++;
break;
case PILOT_OFF:
state->dnxt.pilot_val = CX24116_PILOT_OFF;
break;
case PILOT_ON:
state->dnxt.pilot_val = CX24116_PILOT_ON;
break;
default:
dprintk("%s: unsupported pilot mode selected (%d)\n",
__func__, c->pilot);
return -EOPNOTSUPP;
}
switch (c->rolloff) {
case ROLLOFF_20:
state->dnxt.rolloff_val = CX24116_ROLLOFF_020;
break;
case ROLLOFF_25:
state->dnxt.rolloff_val = CX24116_ROLLOFF_025;
break;
case ROLLOFF_35:
state->dnxt.rolloff_val = CX24116_ROLLOFF_035;
break;
case ROLLOFF_AUTO:
default:
dprintk("%s: unsupported rolloff selected (%d)\n",
__func__, c->rolloff);
return -EOPNOTSUPP;
}
break;
default:
dprintk("%s: unsupported delivery system selected (%d)\n",
__func__, c->delivery_system);
return -EOPNOTSUPP;
}
state->dnxt.delsys = c->delivery_system;
state->dnxt.modulation = c->modulation;
state->dnxt.frequency = c->frequency;
state->dnxt.pilot = c->pilot;
state->dnxt.rolloff = c->rolloff;
ret = cx24116_set_inversion(state, c->inversion);
if (ret != 0)
return ret;
ret = cx24116_set_fec(state, c->delivery_system, c->modulation, c->fec_inner);
if (ret != 0)
return ret;
ret = cx24116_set_symbolrate(state, c->symbol_rate);
if (ret != 0)
return ret;
cx24116_clone_params(fe);
dprintk("%s: delsys = %d\n", __func__, state->dcur.delsys);
dprintk("%s: modulation = %d\n", __func__, state->dcur.modulation);
dprintk("%s: frequency = %d\n", __func__, state->dcur.frequency);
dprintk("%s: pilot = %d (val = 0x%02x)\n", __func__,
state->dcur.pilot, state->dcur.pilot_val);
dprintk("%s: retune = %d\n", __func__, retune);
dprintk("%s: rolloff = %d (val = 0x%02x)\n", __func__,
state->dcur.rolloff, state->dcur.rolloff_val);
dprintk("%s: symbol_rate = %d\n", __func__, state->dcur.symbol_rate);
dprintk("%s: FEC = %d (mask/val = 0x%02x/0x%02x)\n", __func__,
state->dcur.fec, state->dcur.fec_mask, state->dcur.fec_val);
dprintk("%s: Inversion = %d (val = 0x%02x)\n", __func__,
state->dcur.inversion, state->dcur.inversion_val);
if (state->config->set_ts_params)
state->config->set_ts_params(fe, 0);
cmd.args[0x00] = CMD_BANDWIDTH;
cmd.args[0x01] = 0x01;
cmd.len = 0x02;
ret = cx24116_cmd_execute(fe, &cmd);
if (ret != 0)
return ret;
cmd.args[0x00] = CMD_TUNEREQUEST;
cmd.args[0x01] = (state->dcur.frequency & 0xff0000) >> 16;
cmd.args[0x02] = (state->dcur.frequency & 0x00ff00) >> 8;
cmd.args[0x03] = (state->dcur.frequency & 0x0000ff);
cmd.args[0x04] = ((state->dcur.symbol_rate / 1000) & 0xff00) >> 8;
cmd.args[0x05] = ((state->dcur.symbol_rate / 1000) & 0x00ff);
cmd.args[0x06] = state->dcur.inversion_val;
cmd.args[0x07] = state->dcur.fec_val | state->dcur.pilot_val;
cmd.args[0x08] = CX24116_SEARCH_RANGE_KHZ >> 8;
cmd.args[0x09] = CX24116_SEARCH_RANGE_KHZ & 0xff;
cmd.args[0x0a] = 0x00;
cmd.args[0x0b] = 0x00;
cmd.args[0x0c] = state->dcur.rolloff_val;
cmd.args[0x0d] = state->dcur.fec_mask;
if (state->dcur.symbol_rate > 30000000) {
cmd.args[0x0e] = 0x04;
cmd.args[0x0f] = 0x00;
cmd.args[0x10] = 0x01;
cmd.args[0x11] = 0x77;
cmd.args[0x12] = 0x36;
cx24116_writereg(state, CX24116_REG_CLKDIV, 0x44);
cx24116_writereg(state, CX24116_REG_RATEDIV, 0x01);
} else {
cmd.args[0x0e] = 0x06;
cmd.args[0x0f] = 0x00;
cmd.args[0x10] = 0x00;
cmd.args[0x11] = 0xFA;
cmd.args[0x12] = 0x24;
cx24116_writereg(state, CX24116_REG_CLKDIV, 0x46);
cx24116_writereg(state, CX24116_REG_RATEDIV, 0x00);
}
cmd.len = 0x13;
do {
status = cx24116_readreg(state, CX24116_REG_SSTATUS)
& CX24116_SIGNAL_MASK;
cx24116_writereg(state, CX24116_REG_SSTATUS, status);
ret = cx24116_cmd_execute(fe, &cmd);
if (ret != 0)
break;
for (i = 0; i < 50 ; i++) {
cx24116_read_status(fe, &tunerstat);
status = tunerstat & (FE_HAS_SIGNAL | FE_HAS_SYNC);
if (status == (FE_HAS_SIGNAL | FE_HAS_SYNC)) {
dprintk("%s: Tuned\n", __func__);
goto tuned;
}
msleep(10);
}
dprintk("%s: Not tuned\n", __func__);
if (state->dcur.pilot == PILOT_AUTO)
cmd.args[0x07] ^= CX24116_PILOT_ON;
} while (--retune);
tuned:
cmd.args[0x00] = CMD_BANDWIDTH;
cmd.args[0x01] = 0x00;
cmd.len = 0x02;
ret = cx24116_cmd_execute(fe, &cmd);
if (ret != 0)
return ret;
return ret;
}
static int cx24116_tune(struct dvb_frontend *fe, struct dvb_frontend_parameters *params,
unsigned int mode_flags, unsigned int *delay, fe_status_t *status)
{
*delay = HZ / 5;
if (params) {
int ret = cx24116_set_frontend(fe, params);
if (ret)
return ret;
}
return cx24116_read_status(fe, status);
}
static int cx24116_get_algo(struct dvb_frontend *fe)
{
return DVBFE_ALGO_HW;
}
