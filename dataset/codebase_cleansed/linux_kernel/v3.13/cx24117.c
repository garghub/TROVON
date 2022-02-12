static int cx24117_writereg(struct cx24117_state *state, u8 reg, u8 data)
{
u8 buf[] = { reg, data };
struct i2c_msg msg = { .addr = state->priv->demod_address,
.flags = 0, .buf = buf, .len = 2 };
int ret;
dev_dbg(&state->priv->i2c->dev,
"%s() demod%d i2c wr @0x%02x=0x%02x\n",
__func__, state->demod, reg, data);
ret = i2c_transfer(state->priv->i2c, &msg, 1);
if (ret < 0) {
dev_warn(&state->priv->i2c->dev,
"%s: demod%d i2c wr err(%i) @0x%02x=0x%02x\n",
KBUILD_MODNAME, state->demod, ret, reg, data);
return ret;
}
return 0;
}
static int cx24117_writecmd(struct cx24117_state *state,
struct cx24117_cmd *cmd)
{
struct i2c_msg msg;
u8 buf[CX24117_ARGLEN+1];
int ret;
dev_dbg(&state->priv->i2c->dev,
"%s() demod%d i2c wr cmd len=%d\n",
__func__, state->demod, cmd->len);
buf[0] = CX24117_REG_COMMAND;
memcpy(&buf[1], cmd->args, cmd->len);
msg.addr = state->priv->demod_address;
msg.flags = 0;
msg.len = cmd->len+1;
msg.buf = buf;
ret = i2c_transfer(state->priv->i2c, &msg, 1);
if (ret < 0) {
dev_warn(&state->priv->i2c->dev,
"%s: demod%d i2c wr cmd err(%i) len=%d\n",
KBUILD_MODNAME, state->demod, ret, cmd->len);
return ret;
}
return 0;
}
static int cx24117_readreg(struct cx24117_state *state, u8 reg)
{
int ret;
u8 recv = 0;
struct i2c_msg msg[] = {
{ .addr = state->priv->demod_address, .flags = 0,
.buf = &reg, .len = 1 },
{ .addr = state->priv->demod_address, .flags = I2C_M_RD,
.buf = &recv, .len = 1 }
};
ret = i2c_transfer(state->priv->i2c, msg, 2);
if (ret < 0) {
dev_warn(&state->priv->i2c->dev,
"%s: demod%d i2c rd err(%d) @0x%x\n",
KBUILD_MODNAME, state->demod, ret, reg);
return ret;
}
dev_dbg(&state->priv->i2c->dev, "%s() demod%d i2c rd @0x%02x=0x%02x\n",
__func__, state->demod, reg, recv);
return recv;
}
static int cx24117_readregN(struct cx24117_state *state,
u8 reg, u8 *buf, int len)
{
int ret;
struct i2c_msg msg[] = {
{ .addr = state->priv->demod_address, .flags = 0,
.buf = &reg, .len = 1 },
{ .addr = state->priv->demod_address, .flags = I2C_M_RD,
.buf = buf, .len = len }
};
ret = i2c_transfer(state->priv->i2c, msg, 2);
if (ret < 0) {
dev_warn(&state->priv->i2c->dev,
"%s: demod%d i2c rd err(%d) @0x%x\n",
KBUILD_MODNAME, state->demod, ret, reg);
return ret;
}
return 0;
}
static int cx24117_set_inversion(struct cx24117_state *state,
fe_spectral_inversion_t inversion)
{
dev_dbg(&state->priv->i2c->dev, "%s(%d) demod%d\n",
__func__, inversion, state->demod);
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
static int cx24117_lookup_fecmod(struct cx24117_state *state,
fe_delivery_system_t d, fe_modulation_t m, fe_code_rate_t f)
{
int i, ret = -EINVAL;
dev_dbg(&state->priv->i2c->dev,
"%s(demod(0x%02x,0x%02x) demod%d\n",
__func__, m, f, state->demod);
for (i = 0; i < ARRAY_SIZE(cx24117_modfec_modes); i++) {
if ((d == cx24117_modfec_modes[i].delivery_system) &&
(m == cx24117_modfec_modes[i].modulation) &&
(f == cx24117_modfec_modes[i].fec)) {
ret = i;
break;
}
}
return ret;
}
static int cx24117_set_fec(struct cx24117_state *state,
fe_delivery_system_t delsys, fe_modulation_t mod, fe_code_rate_t fec)
{
int ret;
dev_dbg(&state->priv->i2c->dev,
"%s(0x%02x,0x%02x) demod%d\n",
__func__, mod, fec, state->demod);
ret = cx24117_lookup_fecmod(state, delsys, mod, fec);
if (ret < 0)
return ret;
state->dnxt.fec = fec;
state->dnxt.fec_val = cx24117_modfec_modes[ret].val;
state->dnxt.fec_mask = cx24117_modfec_modes[ret].mask;
dev_dbg(&state->priv->i2c->dev,
"%s() demod%d mask/val = 0x%02x/0x%02x\n", __func__,
state->demod, state->dnxt.fec_mask, state->dnxt.fec_val);
return 0;
}
static int cx24117_set_symbolrate(struct cx24117_state *state, u32 rate)
{
dev_dbg(&state->priv->i2c->dev, "%s(%d) demod%d\n",
__func__, rate, state->demod);
state->dnxt.symbol_rate = rate;
dev_dbg(&state->priv->i2c->dev,
"%s() demod%d symbol_rate = %d\n",
__func__, state->demod, rate);
return 0;
}
static int cx24117_firmware_ondemand(struct dvb_frontend *fe)
{
struct cx24117_state *state = fe->demodulator_priv;
const struct firmware *fw;
int ret = 0;
dev_dbg(&state->priv->i2c->dev, "%s() demod%d skip_fw_load=%d\n",
__func__, state->demod, state->priv->skip_fw_load);
if (state->priv->skip_fw_load)
return 0;
if (cx24117_readreg(state, 0xeb) != 0xa) {
dev_dbg(&state->priv->i2c->dev,
"%s: Waiting for firmware upload (%s)...\n",
__func__, CX24117_DEFAULT_FIRMWARE);
ret = request_firmware(&fw, CX24117_DEFAULT_FIRMWARE,
state->priv->i2c->dev.parent);
dev_dbg(&state->priv->i2c->dev,
"%s: Waiting for firmware upload(2)...\n", __func__);
if (ret) {
dev_err(&state->priv->i2c->dev,
"%s: No firmware uploaded "
"(timeout or file not found?)\n", __func__);
return ret;
}
state->priv->skip_fw_load = 1;
ret = cx24117_load_firmware(fe, fw);
if (ret)
dev_err(&state->priv->i2c->dev,
"%s: Writing firmware failed\n", __func__);
release_firmware(fw);
dev_info(&state->priv->i2c->dev,
"%s: Firmware upload %s\n", __func__,
ret == 0 ? "complete" : "failed");
state->priv->skip_fw_load = 0;
}
return ret;
}
static int cx24117_cmd_execute_nolock(struct dvb_frontend *fe,
struct cx24117_cmd *cmd)
{
struct cx24117_state *state = fe->demodulator_priv;
int i, ret;
dev_dbg(&state->priv->i2c->dev, "%s() demod%d\n",
__func__, state->demod);
ret = cx24117_firmware_ondemand(fe);
if (ret != 0)
return ret;
cx24117_writecmd(state, cmd);
cx24117_writereg(state, CX24117_REG_EXECUTE, 0x01);
i = 0;
while (cx24117_readreg(state, CX24117_REG_EXECUTE)) {
msleep(20);
if (i++ > 40) {
dev_warn(&state->priv->i2c->dev,
"%s() Firmware not responding\n", __func__);
return -EIO;
}
}
return 0;
}
static int cx24117_cmd_execute(struct dvb_frontend *fe, struct cx24117_cmd *cmd)
{
struct cx24117_state *state = fe->demodulator_priv;
int ret;
mutex_lock(&state->priv->fe_lock);
ret = cx24117_cmd_execute_nolock(fe, cmd);
mutex_unlock(&state->priv->fe_lock);
return ret;
}
static int cx24117_load_firmware(struct dvb_frontend *fe,
const struct firmware *fw)
{
struct cx24117_state *state = fe->demodulator_priv;
struct cx24117_cmd cmd;
int i, ret;
unsigned char vers[4];
struct i2c_msg msg;
u8 *buf;
dev_dbg(&state->priv->i2c->dev,
"%s() demod%d FW is %zu bytes (%02x %02x .. %02x %02x)\n",
__func__, state->demod, fw->size, fw->data[0], fw->data[1],
fw->data[fw->size - 2], fw->data[fw->size - 1]);
cx24117_writereg(state, 0xea, 0x00);
cx24117_writereg(state, 0xea, 0x01);
cx24117_writereg(state, 0xea, 0x00);
cx24117_writereg(state, 0xce, 0x92);
cx24117_writereg(state, 0xfb, 0x00);
cx24117_writereg(state, 0xfc, 0x00);
cx24117_writereg(state, 0xc3, 0x04);
cx24117_writereg(state, 0xc4, 0x04);
cx24117_writereg(state, 0xce, 0x00);
cx24117_writereg(state, 0xcf, 0x00);
cx24117_writereg(state, 0xea, 0x00);
cx24117_writereg(state, 0xeb, 0x0c);
cx24117_writereg(state, 0xec, 0x06);
cx24117_writereg(state, 0xed, 0x05);
cx24117_writereg(state, 0xee, 0x03);
cx24117_writereg(state, 0xef, 0x05);
cx24117_writereg(state, 0xf3, 0x03);
cx24117_writereg(state, 0xf4, 0x44);
cx24117_writereg(state, CX24117_REG_RATEDIV0, 0x04);
cx24117_writereg(state, CX24117_REG_CLKDIV0, 0x02);
cx24117_writereg(state, CX24117_REG_RATEDIV1, 0x04);
cx24117_writereg(state, CX24117_REG_CLKDIV1, 0x02);
cx24117_writereg(state, 0xf2, 0x04);
cx24117_writereg(state, 0xe8, 0x02);
cx24117_writereg(state, 0xea, 0x01);
cx24117_writereg(state, 0xc8, 0x00);
cx24117_writereg(state, 0xc9, 0x00);
cx24117_writereg(state, 0xca, 0x00);
cx24117_writereg(state, 0xcb, 0x00);
cx24117_writereg(state, 0xcc, 0x00);
cx24117_writereg(state, 0xcd, 0x00);
cx24117_writereg(state, 0xe4, 0x03);
cx24117_writereg(state, 0xeb, 0x0a);
cx24117_writereg(state, 0xfb, 0x00);
cx24117_writereg(state, 0xe0, 0x76);
cx24117_writereg(state, 0xf7, 0x81);
cx24117_writereg(state, 0xf8, 0x00);
cx24117_writereg(state, 0xf9, 0x00);
buf = kmalloc(fw->size + 1, GFP_KERNEL);
if (buf == NULL) {
state->priv->skip_fw_load = 0;
return -ENOMEM;
}
buf[0] = 0xfa;
memcpy(&buf[1], fw->data, fw->size);
msg.addr = state->priv->demod_address;
msg.flags = 0;
msg.len = fw->size + 1;
msg.buf = buf;
ret = i2c_transfer(state->priv->i2c, &msg, 1);
if (ret < 0)
return ret;
kfree(buf);
cx24117_writereg(state, 0xf7, 0x0c);
cx24117_writereg(state, 0xe0, 0x00);
cmd.args[0] = 0x1b;
cmd.args[1] = 0x00;
cmd.args[2] = 0x01;
cmd.args[3] = 0x00;
cmd.len = 4;
ret = cx24117_cmd_execute_nolock(fe, &cmd);
if (ret != 0)
goto error;
cmd.args[0] = CMD_SET_VCO;
cmd.args[1] = 0x06;
cmd.args[2] = 0x2b;
cmd.args[3] = 0xd8;
cmd.args[4] = 0xa5;
cmd.args[5] = 0xee;
cmd.args[6] = 0x03;
cmd.args[7] = 0x9d;
cmd.args[8] = 0xfc;
cmd.args[9] = 0x06;
cmd.args[10] = 0x02;
cmd.args[11] = 0x9d;
cmd.args[12] = 0xfc;
cmd.len = 13;
ret = cx24117_cmd_execute_nolock(fe, &cmd);
if (ret != 0)
goto error;
cmd.args[0] = 0x15;
cmd.args[1] = 0x00;
cmd.args[2] = 0x01;
cmd.args[3] = 0x00;
cmd.args[4] = 0x00;
cmd.args[5] = 0x01;
cmd.args[6] = 0x01;
cmd.args[7] = 0x01;
cmd.args[8] = 0x00;
cmd.args[9] = 0x05;
cmd.args[10] = 0x02;
cmd.args[11] = 0x02;
cmd.args[12] = 0x00;
cmd.len = 13;
ret = cx24117_cmd_execute_nolock(fe, &cmd);
if (ret != 0)
goto error;
cmd.args[0] = CMD_MPEGCONFIG;
cmd.args[1] = 0x00;
cmd.args[2] = 0x00;
cmd.args[3] = 0x00;
cmd.args[4] = 0x01;
cmd.args[5] = 0x00;
cmd.len = 6;
ret = cx24117_cmd_execute_nolock(fe, &cmd);
if (ret != 0)
goto error;
for (i = 0; i < 2; i++) {
cmd.args[0] = CMD_TUNERINIT;
cmd.args[1] = (u8) i;
cmd.args[2] = 0x00;
cmd.args[3] = 0x05;
cmd.args[4] = 0x00;
cmd.args[5] = 0x00;
cmd.args[6] = 0x55;
cmd.args[7] = 0x00;
cmd.len = 8;
ret = cx24117_cmd_execute_nolock(fe, &cmd);
if (ret != 0)
goto error;
}
cx24117_writereg(state, 0xce, 0xc0);
cx24117_writereg(state, 0xcf, 0x00);
cx24117_writereg(state, 0xe5, 0x04);
cmd.args[0] = CMD_UPDFWVERS;
cmd.len = 2;
for (i = 0; i < 4; i++) {
cmd.args[1] = i;
ret = cx24117_cmd_execute_nolock(fe, &cmd);
if (ret != 0)
goto error;
vers[i] = cx24117_readreg(state, 0x33);
}
dev_info(&state->priv->i2c->dev,
"%s: FW version %i.%i.%i.%i\n", __func__,
vers[0], vers[1], vers[2], vers[3]);
return 0;
error:
state->priv->skip_fw_load = 0;
dev_err(&state->priv->i2c->dev, "%s() Error running FW.\n", __func__);
return ret;
}
static int cx24117_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct cx24117_state *state = fe->demodulator_priv;
int lock;
lock = cx24117_readreg(state,
(state->demod == 0) ? CX24117_REG_SSTATUS0 :
CX24117_REG_SSTATUS1) &
CX24117_STATUS_MASK;
dev_dbg(&state->priv->i2c->dev, "%s() demod%d status = 0x%02x\n",
__func__, state->demod, lock);
*status = 0;
if (lock & CX24117_HAS_SIGNAL)
*status |= FE_HAS_SIGNAL;
if (lock & CX24117_HAS_CARRIER)
*status |= FE_HAS_CARRIER;
if (lock & CX24117_HAS_VITERBI)
*status |= FE_HAS_VITERBI;
if (lock & CX24117_HAS_SYNCLOCK)
*status |= FE_HAS_SYNC | FE_HAS_LOCK;
return 0;
}
static int cx24117_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct cx24117_state *state = fe->demodulator_priv;
int ret;
u8 buf[4];
u8 base_reg = (state->demod == 0) ?
CX24117_REG_BER4_0 :
CX24117_REG_BER4_1;
ret = cx24117_readregN(state, base_reg, buf, 4);
if (ret != 0)
return ret;
*ber = (buf[0] << 24) | (buf[1] << 16) |
(buf[1] << 8) | buf[0];
dev_dbg(&state->priv->i2c->dev, "%s() demod%d ber=0x%04x\n",
__func__, state->demod, *ber);
return 0;
}
static int cx24117_read_signal_strength(struct dvb_frontend *fe,
u16 *signal_strength)
{
struct cx24117_state *state = fe->demodulator_priv;
struct cx24117_cmd cmd;
int ret;
u16 sig_reading;
u8 buf[2];
u8 reg = (state->demod == 0) ?
CX24117_REG_SSTATUS0 : CX24117_REG_SSTATUS1;
cmd.args[0] = 0x1a;
cmd.args[1] = (u8) state->demod;
cmd.len = 2;
ret = cx24117_cmd_execute(fe, &cmd);
if (ret != 0)
return ret;
ret = cx24117_readregN(state, reg, buf, 2);
if (ret != 0)
return ret;
sig_reading = ((buf[0] & CX24117_SIGNAL_MASK) << 2) | buf[1];
*signal_strength = -100 * sig_reading + 94324;
dev_dbg(&state->priv->i2c->dev,
"%s() demod%d raw / cooked = 0x%04x / 0x%04x\n",
__func__, state->demod, sig_reading, *signal_strength);
return 0;
}
static int cx24117_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct cx24117_state *state = fe->demodulator_priv;
int ret;
u8 buf[2];
u8 reg = (state->demod == 0) ?
CX24117_REG_QUALITY2_0 : CX24117_REG_QUALITY2_1;
ret = cx24117_readregN(state, reg, buf, 2);
if (ret != 0)
return ret;
*snr = (buf[0] << 8) | buf[1];
dev_dbg(&state->priv->i2c->dev,
"%s() demod%d snr = 0x%04x\n",
__func__, state->demod, *snr);
return ret;
}
static int cx24117_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
struct cx24117_state *state = fe->demodulator_priv;
fe_delivery_system_t delsys = fe->dtv_property_cache.delivery_system;
int ret;
u8 buf[2];
u8 reg = (state->demod == 0) ?
CX24117_REG_DVBS_UCB2_0 :
CX24117_REG_DVBS_UCB2_1;
switch (delsys) {
case SYS_DVBS:
break;
case SYS_DVBS2:
reg += (CX24117_REG_DVBS2_UCB2_0 - CX24117_REG_DVBS_UCB2_0);
break;
default:
return -EINVAL;
}
ret = cx24117_readregN(state, reg, buf, 2);
if (ret != 0)
return ret;
*ucblocks = (buf[0] << 8) | buf[1];
dev_dbg(&state->priv->i2c->dev, "%s() demod%d ucb=0x%04x\n",
__func__, state->demod, *ucblocks);
return 0;
}
static void cx24117_clone_params(struct dvb_frontend *fe)
{
struct cx24117_state *state = fe->demodulator_priv;
state->dcur = state->dnxt;
}
static int cx24117_wait_for_lnb(struct dvb_frontend *fe)
{
struct cx24117_state *state = fe->demodulator_priv;
int i;
u8 val, reg = (state->demod == 0) ? CX24117_REG_QSTATUS0 :
CX24117_REG_QSTATUS1;
dev_dbg(&state->priv->i2c->dev, "%s() demod%d qstatus = 0x%02x\n",
__func__, state->demod, cx24117_readreg(state, reg));
for (i = 0; i < 10; i++) {
val = cx24117_readreg(state, reg) & 0x01;
if (val != 0)
return 0;
msleep(30);
}
dev_warn(&state->priv->i2c->dev, "%s: demod%d LNB not ready\n",
KBUILD_MODNAME, state->demod);
return -ETIMEDOUT;
}
static int cx24117_set_voltage(struct dvb_frontend *fe,
fe_sec_voltage_t voltage)
{
struct cx24117_state *state = fe->demodulator_priv;
struct cx24117_cmd cmd;
int ret;
u8 reg = (state->demod == 0) ? 0x10 : 0x20;
dev_dbg(&state->priv->i2c->dev, "%s() demod%d %s\n",
__func__, state->demod,
voltage == SEC_VOLTAGE_13 ? "SEC_VOLTAGE_13" :
voltage == SEC_VOLTAGE_18 ? "SEC_VOLTAGE_18" :
"SEC_VOLTAGE_OFF");
cmd.args[0] = 0x32;
cmd.args[1] = reg;
cmd.args[2] = reg;
cmd.len = 3;
ret = cx24117_cmd_execute(fe, &cmd);
if (ret)
return ret;
if ((voltage == SEC_VOLTAGE_13) ||
(voltage == SEC_VOLTAGE_18)) {
cmd.args[0] = 0x33;
cmd.args[1] = reg;
cmd.args[2] = reg;
cmd.len = 3;
ret = cx24117_cmd_execute(fe, &cmd);
if (ret != 0)
return ret;
ret = cx24117_wait_for_lnb(fe);
if (ret != 0)
return ret;
msleep(100);
cmd.args[0] = CMD_LNBDCLEVEL;
cmd.args[1] = state->demod ? 0 : 1;
cmd.args[2] = (voltage == SEC_VOLTAGE_18 ? 0x01 : 0x00);
cmd.len = 3;
msleep(20);
} else {
cmd.args[0] = 0x33;
cmd.args[1] = 0x00;
cmd.args[2] = reg;
cmd.len = 3;
}
return cx24117_cmd_execute(fe, &cmd);
}
static int cx24117_set_tone(struct dvb_frontend *fe,
fe_sec_tone_mode_t tone)
{
struct cx24117_state *state = fe->demodulator_priv;
struct cx24117_cmd cmd;
int ret;
dev_dbg(&state->priv->i2c->dev, "%s(%d) demod%d\n",
__func__, state->demod, tone);
if ((tone != SEC_TONE_ON) && (tone != SEC_TONE_OFF)) {
dev_warn(&state->priv->i2c->dev, "%s: demod%d invalid tone=%d\n",
KBUILD_MODNAME, state->demod, tone);
return -EINVAL;
}
ret = cx24117_wait_for_lnb(fe);
if (ret != 0)
return ret;
msleep(20);
cmd.args[0] = CMD_SET_TONE;
cmd.args[1] = (state->demod ? 0 : 1);
cmd.args[2] = 0x00;
cmd.args[3] = 0x00;
cmd.len = 5;
switch (tone) {
case SEC_TONE_ON:
cmd.args[4] = 0x01;
break;
case SEC_TONE_OFF:
cmd.args[4] = 0x00;
break;
}
msleep(20);
return cx24117_cmd_execute(fe, &cmd);
}
static int cx24117_diseqc_init(struct dvb_frontend *fe)
{
struct cx24117_state *state = fe->demodulator_priv;
state->dsec_cmd.args[0] = CMD_LNBSEND;
state->dsec_cmd.args[CX24117_DISEQC_DEMOD] = state->demod ? 0 : 1;
state->dsec_cmd.args[CX24117_DISEQC_BURST] = CX24117_DISEQC_MINI_A;
state->dsec_cmd.args[CX24117_DISEQC_ARG3_2] = 0x02;
state->dsec_cmd.args[CX24117_DISEQC_ARG4_0] = 0x00;
state->dsec_cmd.args[CX24117_DISEQC_ARG5_0] = 0x00;
state->dsec_cmd.args[CX24117_DISEQC_MSGLEN] = 0x00;
state->dsec_cmd.len = 7;
return 0;
}
static int cx24117_send_diseqc_msg(struct dvb_frontend *fe,
struct dvb_diseqc_master_cmd *d)
{
struct cx24117_state *state = fe->demodulator_priv;
int i, ret;
dev_dbg(&state->priv->i2c->dev, "%s: demod %d (",
__func__, state->demod);
for (i = 0; i < d->msg_len; i++)
dev_dbg(&state->priv->i2c->dev, "0x%02x ", d->msg[i]);
dev_dbg(&state->priv->i2c->dev, ")\n");
if (d->msg_len > 15)
return -EINVAL;
for (i = 0; i < d->msg_len; i++)
state->dsec_cmd.args[CX24117_DISEQC_MSGOFS + i] = d->msg[i];
state->dsec_cmd.args[CX24117_DISEQC_MSGLEN] = d->msg_len;
state->dsec_cmd.len = CX24117_DISEQC_MSGOFS +
state->dsec_cmd.args[CX24117_DISEQC_MSGLEN];
if (d->msg_len >= 4 && d->msg[2] == 0x38)
state->dsec_cmd.args[CX24117_DISEQC_BURST] =
((d->msg[3] & 4) >> 2);
dev_dbg(&state->priv->i2c->dev, "%s() demod%d burst=%d\n",
__func__, state->demod,
state->dsec_cmd.args[CX24117_DISEQC_BURST]);
ret = cx24117_wait_for_lnb(fe);
if (ret != 0)
return ret;
msleep(100);
ret = cx24117_cmd_execute(fe, &state->dsec_cmd);
if (ret != 0)
return ret;
msleep((state->dsec_cmd.args[CX24117_DISEQC_MSGLEN] << 4) + 60);
return 0;
}
static int cx24117_diseqc_send_burst(struct dvb_frontend *fe,
fe_sec_mini_cmd_t burst)
{
struct cx24117_state *state = fe->demodulator_priv;
dev_dbg(&state->priv->i2c->dev, "%s(%d) demod=%d\n",
__func__, burst, state->demod);
if (burst == SEC_MINI_A)
state->dsec_cmd.args[CX24117_DISEQC_BURST] =
CX24117_DISEQC_MINI_A;
else if (burst == SEC_MINI_B)
state->dsec_cmd.args[CX24117_DISEQC_BURST] =
CX24117_DISEQC_MINI_B;
else
return -EINVAL;
return 0;
}
static int cx24117_get_priv(struct cx24117_priv **priv,
struct i2c_adapter *i2c, u8 client_address)
{
int ret;
mutex_lock(&cx24117_list_mutex);
ret = hybrid_tuner_request_state(struct cx24117_priv, (*priv),
hybrid_tuner_instance_list, i2c, client_address, "cx24117");
mutex_unlock(&cx24117_list_mutex);
return ret;
}
static void cx24117_release_priv(struct cx24117_priv *priv)
{
mutex_lock(&cx24117_list_mutex);
if (priv != NULL)
hybrid_tuner_release_state(priv);
mutex_unlock(&cx24117_list_mutex);
}
static void cx24117_release(struct dvb_frontend *fe)
{
struct cx24117_state *state = fe->demodulator_priv;
dev_dbg(&state->priv->i2c->dev, "%s demod%d\n",
__func__, state->demod);
cx24117_release_priv(state->priv);
kfree(state);
}
struct dvb_frontend *cx24117_attach(const struct cx24117_config *config,
struct i2c_adapter *i2c)
{
struct cx24117_state *state = NULL;
struct cx24117_priv *priv = NULL;
int demod = 0;
demod = cx24117_get_priv(&priv, i2c, config->demod_address);
switch (demod) {
case 0:
dev_err(&state->priv->i2c->dev,
"%s: Error attaching frontend %d\n",
KBUILD_MODNAME, demod);
goto error1;
break;
case 1:
priv->i2c = i2c;
priv->demod_address = config->demod_address;
mutex_init(&priv->fe_lock);
break;
default:
break;
}
state = kzalloc(sizeof(struct cx24117_state), GFP_KERNEL);
if (state == NULL)
goto error2;
state->demod = demod - 1;
state->priv = priv;
if (demod == 0) {
if (cx24117_readreg(state, 0x00) < 0)
goto error3;
}
dev_info(&state->priv->i2c->dev,
"%s: Attaching frontend %d\n",
KBUILD_MODNAME, state->demod);
memcpy(&state->frontend.ops, &cx24117_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error3:
kfree(state);
error2:
cx24117_release_priv(priv);
error1:
return NULL;
}
static int cx24117_initfe(struct dvb_frontend *fe)
{
struct cx24117_state *state = fe->demodulator_priv;
struct cx24117_cmd cmd;
int ret;
dev_dbg(&state->priv->i2c->dev, "%s() demod%d\n",
__func__, state->demod);
mutex_lock(&state->priv->fe_lock);
cmd.args[0] = CMD_TUNERSLEEP;
cmd.args[1] = (state->demod ? 1 : 0);
cmd.args[2] = 0;
cmd.len = 3;
ret = cx24117_cmd_execute_nolock(fe, &cmd);
if (ret != 0)
goto exit;
ret = cx24117_diseqc_init(fe);
if (ret != 0)
goto exit;
cmd.args[0] = 0x3c;
cmd.args[1] = (state->demod ? 1 : 0);
cmd.args[2] = 0x10;
cmd.args[3] = 0x10;
cmd.len = 4;
ret = cx24117_cmd_execute_nolock(fe, &cmd);
if (ret != 0)
goto exit;
cmd.args[0] = 0x34;
cmd.args[1] = (state->demod ? 1 : 0);
cmd.args[2] = CX24117_OCC;
cmd.len = 3;
ret = cx24117_cmd_execute_nolock(fe, &cmd);
exit:
mutex_unlock(&state->priv->fe_lock);
return ret;
}
static int cx24117_sleep(struct dvb_frontend *fe)
{
struct cx24117_state *state = fe->demodulator_priv;
struct cx24117_cmd cmd;
dev_dbg(&state->priv->i2c->dev, "%s() demod%d\n",
__func__, state->demod);
cmd.args[0] = CMD_TUNERSLEEP;
cmd.args[1] = (state->demod ? 1 : 0);
cmd.args[2] = 1;
cmd.len = 3;
return cx24117_cmd_execute(fe, &cmd);
}
static int cx24117_set_frontend(struct dvb_frontend *fe)
{
struct cx24117_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct cx24117_cmd cmd;
fe_status_t tunerstat;
int i, status, ret, retune = 1;
u8 reg_clkdiv, reg_ratediv;
dev_dbg(&state->priv->i2c->dev, "%s() demod%d\n",
__func__, state->demod);
switch (c->delivery_system) {
case SYS_DVBS:
dev_dbg(&state->priv->i2c->dev, "%s() demod%d DVB-S\n",
__func__, state->demod);
if (c->modulation != QPSK) {
dev_dbg(&state->priv->i2c->dev,
"%s() demod%d unsupported modulation (%d)\n",
__func__, state->demod, c->modulation);
return -EINVAL;
}
state->dnxt.pilot_val = CX24117_PILOT_OFF;
state->dnxt.rolloff_val = CX24117_ROLLOFF_035;
break;
case SYS_DVBS2:
dev_dbg(&state->priv->i2c->dev, "%s() demod%d DVB-S2\n",
__func__, state->demod);
if (c->modulation != PSK_8 && c->modulation != QPSK) {
dev_dbg(&state->priv->i2c->dev,
"%s() demod%d unsupported modulation (%d)\n",
__func__, state->demod, c->modulation);
return -EOPNOTSUPP;
}
switch (c->pilot) {
case PILOT_AUTO:
state->dnxt.pilot_val = CX24117_PILOT_AUTO;
break;
case PILOT_OFF:
state->dnxt.pilot_val = CX24117_PILOT_OFF;
break;
case PILOT_ON:
state->dnxt.pilot_val = CX24117_PILOT_ON;
break;
default:
dev_dbg(&state->priv->i2c->dev,
"%s() demod%d unsupported pilot mode (%d)\n",
__func__, state->demod, c->pilot);
return -EOPNOTSUPP;
}
switch (c->rolloff) {
case ROLLOFF_20:
state->dnxt.rolloff_val = CX24117_ROLLOFF_020;
break;
case ROLLOFF_25:
state->dnxt.rolloff_val = CX24117_ROLLOFF_025;
break;
case ROLLOFF_35:
state->dnxt.rolloff_val = CX24117_ROLLOFF_035;
break;
case ROLLOFF_AUTO:
state->dnxt.rolloff_val = CX24117_ROLLOFF_035;
retune = 3;
break;
default:
dev_warn(&state->priv->i2c->dev,
"%s: demod%d unsupported rolloff (%d)\n",
KBUILD_MODNAME, state->demod, c->rolloff);
return -EOPNOTSUPP;
}
break;
default:
dev_warn(&state->priv->i2c->dev,
"%s: demod %d unsupported delivery system (%d)\n",
KBUILD_MODNAME, state->demod, c->delivery_system);
return -EINVAL;
}
state->dnxt.delsys = c->delivery_system;
state->dnxt.modulation = c->modulation;
state->dnxt.frequency = c->frequency;
state->dnxt.pilot = c->pilot;
state->dnxt.rolloff = c->rolloff;
ret = cx24117_set_inversion(state, c->inversion);
if (ret != 0)
return ret;
ret = cx24117_set_fec(state,
c->delivery_system, c->modulation, c->fec_inner);
if (ret != 0)
return ret;
ret = cx24117_set_symbolrate(state, c->symbol_rate);
if (ret != 0)
return ret;
cx24117_clone_params(fe);
dev_dbg(&state->priv->i2c->dev,
"%s: delsys = %d\n", __func__, state->dcur.delsys);
dev_dbg(&state->priv->i2c->dev,
"%s: modulation = %d\n", __func__, state->dcur.modulation);
dev_dbg(&state->priv->i2c->dev,
"%s: frequency = %d\n", __func__, state->dcur.frequency);
dev_dbg(&state->priv->i2c->dev,
"%s: pilot = %d (val = 0x%02x)\n", __func__,
state->dcur.pilot, state->dcur.pilot_val);
dev_dbg(&state->priv->i2c->dev,
"%s: retune = %d\n", __func__, retune);
dev_dbg(&state->priv->i2c->dev,
"%s: rolloff = %d (val = 0x%02x)\n", __func__,
state->dcur.rolloff, state->dcur.rolloff_val);
dev_dbg(&state->priv->i2c->dev,
"%s: symbol_rate = %d\n", __func__, state->dcur.symbol_rate);
dev_dbg(&state->priv->i2c->dev,
"%s: FEC = %d (mask/val = 0x%02x/0x%02x)\n", __func__,
state->dcur.fec, state->dcur.fec_mask, state->dcur.fec_val);
dev_dbg(&state->priv->i2c->dev,
"%s: Inversion = %d (val = 0x%02x)\n", __func__,
state->dcur.inversion, state->dcur.inversion_val);
cmd.args[0] = CMD_TUNEREQUEST;
cmd.args[1] = state->demod;
cmd.args[2] = (state->dcur.frequency & 0xff0000) >> 16;
cmd.args[3] = (state->dcur.frequency & 0x00ff00) >> 8;
cmd.args[4] = (state->dcur.frequency & 0x0000ff);
cmd.args[5] = ((state->dcur.symbol_rate / 1000) & 0xff00) >> 8;
cmd.args[6] = ((state->dcur.symbol_rate / 1000) & 0x00ff);
cmd.args[7] = state->dcur.inversion_val;
cmd.args[8] = state->dcur.fec_val | state->dcur.pilot_val;
cmd.args[9] = CX24117_SEARCH_RANGE_KHZ >> 8;
cmd.args[10] = CX24117_SEARCH_RANGE_KHZ & 0xff;
cmd.args[11] = state->dcur.rolloff_val;
cmd.args[12] = state->dcur.fec_mask;
if (state->dcur.symbol_rate > 30000000) {
reg_ratediv = 0x04;
reg_clkdiv = 0x02;
} else if (state->dcur.symbol_rate > 10000000) {
reg_ratediv = 0x06;
reg_clkdiv = 0x03;
} else {
reg_ratediv = 0x0a;
reg_clkdiv = 0x05;
}
cmd.args[13] = reg_ratediv;
cmd.args[14] = reg_clkdiv;
cx24117_writereg(state, (state->demod == 0) ?
CX24117_REG_CLKDIV0 : CX24117_REG_CLKDIV1, reg_clkdiv);
cx24117_writereg(state, (state->demod == 0) ?
CX24117_REG_RATEDIV0 : CX24117_REG_RATEDIV1, reg_ratediv);
cmd.args[15] = CX24117_PNE;
cmd.len = 16;
do {
status = cx24117_readreg(state, (state->demod == 0) ?
CX24117_REG_SSTATUS0 : CX24117_REG_SSTATUS1) &
CX24117_SIGNAL_MASK;
dev_dbg(&state->priv->i2c->dev,
"%s() demod%d status_setfe = %02x\n",
__func__, state->demod, status);
cx24117_writereg(state, (state->demod == 0) ?
CX24117_REG_SSTATUS0 : CX24117_REG_SSTATUS1, status);
ret = cx24117_cmd_execute(fe, &cmd);
if (ret != 0)
break;
for (i = 0; i < 50; i++) {
cx24117_read_status(fe, &tunerstat);
status = tunerstat & (FE_HAS_SIGNAL | FE_HAS_SYNC);
if (status == (FE_HAS_SIGNAL | FE_HAS_SYNC)) {
dev_dbg(&state->priv->i2c->dev,
"%s() demod%d tuned\n",
__func__, state->demod);
return 0;
}
msleep(20);
}
dev_dbg(&state->priv->i2c->dev, "%s() demod%d not tuned\n",
__func__, state->demod);
if (state->dcur.rolloff == 3)
cmd.args[11]--;
} while (--retune);
return -EINVAL;
}
static int cx24117_tune(struct dvb_frontend *fe, bool re_tune,
unsigned int mode_flags, unsigned int *delay, fe_status_t *status)
{
struct cx24117_state *state = fe->demodulator_priv;
dev_dbg(&state->priv->i2c->dev, "%s() demod%d\n",
__func__, state->demod);
*delay = HZ / 5;
if (re_tune) {
int ret = cx24117_set_frontend(fe);
if (ret)
return ret;
}
return cx24117_read_status(fe, status);
}
static int cx24117_get_algo(struct dvb_frontend *fe)
{
return DVBFE_ALGO_HW;
}
static int cx24117_get_frontend(struct dvb_frontend *fe)
{
struct cx24117_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct cx24117_cmd cmd;
u8 reg, st, inv;
int ret, idx;
unsigned int freq;
short srate_os, freq_os;
u8 buf[0x1f-4];
cmd.args[0] = 0x1c;
cmd.args[1] = (u8) state->demod;
cmd.len = 2;
ret = cx24117_cmd_execute(fe, &cmd);
if (ret != 0)
return ret;
reg = (state->demod == 0) ? CX24117_REG_FREQ3_0 : CX24117_REG_FREQ3_1;
ret = cx24117_readregN(state, reg, buf, 0x1f-4);
if (ret != 0)
return ret;
st = buf[5];
inv = (((state->demod == 0) ? ~st : st) >> 6) & 1;
if (inv == 0)
c->inversion = INVERSION_OFF;
else
c->inversion = INVERSION_ON;
idx = st & 0x3f;
if (c->delivery_system == SYS_DVBS2) {
if (idx > 11)
idx += 9;
else
idx += 7;
}
c->modulation = cx24117_modfec_modes[idx].modulation;
c->fec_inner = cx24117_modfec_modes[idx].fec;
freq = (buf[0] << 16) | (buf[1] << 8) | buf[2];
freq_os = (buf[8] << 8) | buf[9];
c->frequency = freq + freq_os;
srate_os = (buf[10] << 8) | buf[11];
c->symbol_rate = -1000 * srate_os + state->dcur.symbol_rate;
return 0;
}
