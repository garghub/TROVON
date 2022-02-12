static int cx24120_readreg(struct cx24120_state *state, u8 reg)
{
int ret;
u8 buf = 0;
struct i2c_msg msg[] = {
{
.addr = state->config->i2c_addr,
.flags = 0,
.len = 1,
.buf = &reg
}, {
.addr = state->config->i2c_addr,
.flags = I2C_M_RD,
.len = 1,
.buf = &buf
}
};
ret = i2c_transfer(state->i2c, msg, 2);
if (ret != 2) {
err("Read error: reg=0x%02x, ret=%i)\n", reg, ret);
return ret;
}
dev_dbg(&state->i2c->dev, "reg=0x%02x; data=0x%02x\n", reg, buf);
return buf;
}
static int cx24120_writereg(struct cx24120_state *state, u8 reg, u8 data)
{
u8 buf[] = { reg, data };
struct i2c_msg msg = {
.addr = state->config->i2c_addr,
.flags = 0,
.buf = buf,
.len = 2
};
int ret;
ret = i2c_transfer(state->i2c, &msg, 1);
if (ret != 1) {
err("Write error: i2c_write error(err == %i, 0x%02x: 0x%02x)\n",
ret, reg, data);
return ret;
}
dev_dbg(&state->i2c->dev, "reg=0x%02x; data=0x%02x\n", reg, data);
return 0;
}
static int cx24120_writeregs(struct cx24120_state *state,
u8 reg, const u8 *values, u16 len, u8 incr)
{
int ret;
u16 max = state->config->i2c_wr_max > 0 ?
state->config->i2c_wr_max :
len;
struct i2c_msg msg = {
.addr = state->config->i2c_addr,
.flags = 0,
};
msg.buf = kmalloc(max + 1, GFP_KERNEL);
if (!msg.buf)
return -ENOMEM;
while (len) {
msg.buf[0] = reg;
msg.len = len > max ? max : len;
memcpy(&msg.buf[1], values, msg.len);
len -= msg.len;
values += msg.len;
if (incr)
reg += msg.len;
msg.len++;
ret = i2c_transfer(state->i2c, &msg, 1);
if (ret != 1) {
err("i2c_write error(err == %i, 0x%02x)\n", ret, reg);
goto out;
}
dev_dbg(&state->i2c->dev, "reg=0x%02x; data=%*ph\n",
reg, msg.len - 1, msg.buf + 1);
}
ret = 0;
out:
kfree(msg.buf);
return ret;
}
struct dvb_frontend *cx24120_attach(const struct cx24120_config *config,
struct i2c_adapter *i2c)
{
struct cx24120_state *state;
int demod_rev;
info("Conexant cx24120/cx24118 - DVBS/S2 Satellite demod/tuner\n");
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state) {
err("Unable to allocate memory for cx24120_state\n");
goto error;
}
state->config = config;
state->i2c = i2c;
demod_rev = cx24120_readreg(state, CX24120_REG_REVISION);
switch (demod_rev) {
case 0x07:
info("Demod cx24120 rev. 0x07 detected.\n");
break;
case 0x05:
info("Demod cx24120 rev. 0x05 detected.\n");
break;
default:
err("Unsupported demod revision: 0x%x detected.\n", demod_rev);
goto error;
}
state->cold_init = 0;
memcpy(&state->frontend.ops, &cx24120_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
info("Conexant cx24120/cx24118 attached.\n");
return &state->frontend;
error:
kfree(state);
return NULL;
}
static int cx24120_test_rom(struct cx24120_state *state)
{
int err, ret;
err = cx24120_readreg(state, 0xfd);
if (err & 4) {
ret = cx24120_readreg(state, 0xdf) & 0xfe;
err = cx24120_writereg(state, 0xdf, ret);
}
return err;
}
static int cx24120_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
if (c->cnr.stat[0].scale != FE_SCALE_DECIBEL)
*snr = 0;
else
*snr = div_s64(c->cnr.stat[0].svalue, 100);
return 0;
}
static int cx24120_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct cx24120_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
if (c->post_bit_error.stat[0].scale != FE_SCALE_COUNTER) {
*ber = 0;
return 0;
}
*ber = c->post_bit_error.stat[0].uvalue - state->ber_prev;
state->ber_prev = c->post_bit_error.stat[0].uvalue;
return 0;
}
static void cx24120_check_cmd(struct cx24120_state *state, u8 id)
{
switch (id) {
case CMD_TUNEREQUEST:
case CMD_CLOCK_READ:
case CMD_DISEQC_MSG1:
case CMD_DISEQC_MSG2:
case CMD_SETVOLTAGE:
case CMD_SETTONE:
case CMD_DISEQC_BURST:
cx24120_msg_mpeg_output_global_config(state, 0);
default:
return;
}
}
static int cx24120_message_send(struct cx24120_state *state,
struct cx24120_cmd *cmd)
{
int ficus;
if (state->mpeg_enabled) {
cx24120_check_cmd(state, cmd->id);
}
cx24120_writereg(state, CX24120_REG_CMD_START, cmd->id);
cx24120_writeregs(state, CX24120_REG_CMD_ARGS, &cmd->arg[0],
cmd->len, 1);
cx24120_writereg(state, CX24120_REG_CMD_END, 0x01);
ficus = 1000;
while (cx24120_readreg(state, CX24120_REG_CMD_END)) {
msleep(20);
ficus -= 20;
if (ficus == 0) {
err("Error sending message to firmware\n");
return -EREMOTEIO;
}
}
dev_dbg(&state->i2c->dev, "sent message 0x%02x\n", cmd->id);
return 0;
}
static int cx24120_message_sendrcv(struct cx24120_state *state,
struct cx24120_cmd *cmd, u8 numreg)
{
int ret, i;
if (numreg > CX24120_MAX_CMD_LEN) {
err("Too many registers to read. cmd->reg = %d", numreg);
return -EREMOTEIO;
}
ret = cx24120_message_send(state, cmd);
if (ret != 0)
return ret;
if (!numreg)
return 0;
for (i = 0; i < numreg; i++)
cmd->arg[i] = cx24120_readreg(state, (cmd->len + i + 1));
return 0;
}
static int cx24120_read_signal_strength(struct dvb_frontend *fe,
u16 *signal_strength)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
if (c->strength.stat[0].scale != FE_SCALE_RELATIVE)
*signal_strength = 0;
else
*signal_strength = c->strength.stat[0].uvalue;
return 0;
}
static int cx24120_msg_mpeg_output_global_config(struct cx24120_state *state,
u8 enable)
{
struct cx24120_cmd cmd;
int ret;
cmd.id = CMD_MPEG_ONOFF;
cmd.len = 4;
cmd.arg[0] = 0x01;
cmd.arg[1] = 0x00;
cmd.arg[2] = enable ? 0 : (u8)(-1);
cmd.arg[3] = 0x01;
ret = cx24120_message_send(state, &cmd);
if (ret != 0) {
dev_dbg(&state->i2c->dev, "failed to %s MPEG output\n",
enable ? "enable" : "disable");
return ret;
}
state->mpeg_enabled = enable;
dev_dbg(&state->i2c->dev, "MPEG output %s\n",
enable ? "enabled" : "disabled");
return 0;
}
static int cx24120_msg_mpeg_output_config(struct cx24120_state *state, u8 seq)
{
struct cx24120_cmd cmd;
struct cx24120_initial_mpeg_config i =
state->config->initial_mpeg_config;
cmd.id = CMD_MPEG_INIT;
cmd.len = 7;
cmd.arg[0] = seq;
cmd.arg[1] = ((i.x1 & 0x01) << 1) | ((i.x1 >> 1) & 0x01);
cmd.arg[2] = 0x05;
cmd.arg[3] = 0x02;
cmd.arg[4] = ((i.x2 >> 1) & 0x01);
cmd.arg[5] = (i.x2 & 0xf0) | (i.x3 & 0x0f);
cmd.arg[6] = 0x10;
return cx24120_message_send(state, &cmd);
}
static int cx24120_diseqc_send_burst(struct dvb_frontend *fe,
enum fe_sec_mini_cmd burst)
{
struct cx24120_state *state = fe->demodulator_priv;
struct cx24120_cmd cmd;
dev_dbg(&state->i2c->dev, "\n");
cmd.id = CMD_DISEQC_BURST;
cmd.len = 0;
cmd.arg[0] = 0x00;
cmd.arg[1] = (burst == SEC_MINI_B) ? 0x01 : 0x00;
return cx24120_message_send(state, &cmd);
}
static int cx24120_set_tone(struct dvb_frontend *fe, enum fe_sec_tone_mode tone)
{
struct cx24120_state *state = fe->demodulator_priv;
struct cx24120_cmd cmd;
dev_dbg(&state->i2c->dev, "(%d)\n", tone);
if ((tone != SEC_TONE_ON) && (tone != SEC_TONE_OFF)) {
err("Invalid tone=%d\n", tone);
return -EINVAL;
}
cmd.id = CMD_SETTONE;
cmd.len = 4;
cmd.arg[0] = 0x00;
cmd.arg[1] = 0x00;
cmd.arg[2] = 0x00;
cmd.arg[3] = (tone == SEC_TONE_ON) ? 0x01 : 0x00;
return cx24120_message_send(state, &cmd);
}
static int cx24120_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage voltage)
{
struct cx24120_state *state = fe->demodulator_priv;
struct cx24120_cmd cmd;
dev_dbg(&state->i2c->dev, "(%d)\n", voltage);
cmd.id = CMD_SETVOLTAGE;
cmd.len = 2;
cmd.arg[0] = 0x00;
cmd.arg[1] = (voltage == SEC_VOLTAGE_18) ? 0x01 : 0x00;
return cx24120_message_send(state, &cmd);
}
static int cx24120_send_diseqc_msg(struct dvb_frontend *fe,
struct dvb_diseqc_master_cmd *d)
{
struct cx24120_state *state = fe->demodulator_priv;
struct cx24120_cmd cmd;
int back_count;
dev_dbg(&state->i2c->dev, "\n");
cmd.id = CMD_DISEQC_MSG1;
cmd.len = 11;
cmd.arg[0] = 0x00;
cmd.arg[1] = 0x00;
cmd.arg[2] = 0x03;
cmd.arg[3] = 0x16;
cmd.arg[4] = 0x28;
cmd.arg[5] = 0x01;
cmd.arg[6] = 0x01;
cmd.arg[7] = 0x14;
cmd.arg[8] = 0x19;
cmd.arg[9] = 0x14;
cmd.arg[10] = 0x1e;
if (cx24120_message_send(state, &cmd)) {
err("send 1st message(0x%x) failed\n", cmd.id);
return -EREMOTEIO;
}
cmd.id = CMD_DISEQC_MSG2;
cmd.len = d->msg_len + 6;
cmd.arg[0] = 0x00;
cmd.arg[1] = 0x01;
cmd.arg[2] = 0x02;
cmd.arg[3] = 0x00;
cmd.arg[4] = 0x00;
cmd.arg[5] = d->msg_len;
memcpy(&cmd.arg[6], &d->msg, d->msg_len);
if (cx24120_message_send(state, &cmd)) {
err("send 2nd message(0x%x) failed\n", cmd.id);
return -EREMOTEIO;
}
back_count = 500;
do {
if (!(cx24120_readreg(state, 0x93) & 0x01)) {
dev_dbg(&state->i2c->dev, "diseqc sequence sent\n");
return 0;
}
msleep(20);
back_count -= 20;
} while (back_count);
err("Too long waiting for diseqc.\n");
return -ETIMEDOUT;
}
static void cx24120_get_stats(struct cx24120_state *state)
{
struct dvb_frontend *fe = &state->frontend;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct cx24120_cmd cmd;
int ret, cnr, msecs;
u16 sig, ucb;
u32 ber;
dev_dbg(&state->i2c->dev, "\n");
if (state->fe_status & FE_HAS_SIGNAL) {
cmd.id = CMD_READ_SNR;
cmd.len = 1;
cmd.arg[0] = 0x00;
ret = cx24120_message_send(state, &cmd);
if (ret != 0) {
err("error reading signal strength\n");
return;
}
sig = cx24120_readreg(state, CX24120_REG_SIGSTR_H) >> 6;
sig = sig << 8;
sig |= cx24120_readreg(state, CX24120_REG_SIGSTR_L);
dev_dbg(&state->i2c->dev,
"signal strength from firmware = 0x%x\n", sig);
sig = -100 * sig + 94324;
c->strength.stat[0].scale = FE_SCALE_RELATIVE;
c->strength.stat[0].uvalue = sig;
} else {
c->strength.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
}
if (state->fe_status & FE_HAS_VITERBI) {
cnr = cx24120_readreg(state, CX24120_REG_QUALITY_H) << 8;
cnr |= cx24120_readreg(state, CX24120_REG_QUALITY_L);
dev_dbg(&state->i2c->dev, "read SNR index = %d\n", cnr);
cnr = cnr * 100;
c->cnr.stat[0].scale = FE_SCALE_DECIBEL;
c->cnr.stat[0].svalue = cnr;
} else {
c->cnr.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
}
if (!(state->fe_status & FE_HAS_LOCK)) {
c->post_bit_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->post_bit_count.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->block_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->block_count.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
return;
}
if (time_after(jiffies, state->ber_jiffies_stats)) {
msecs = (state->berw_usecs + 500) / 1000;
state->ber_jiffies_stats = jiffies + msecs_to_jiffies(msecs);
ber = cx24120_readreg(state, CX24120_REG_BER_HH) << 24;
ber |= cx24120_readreg(state, CX24120_REG_BER_HL) << 16;
ber |= cx24120_readreg(state, CX24120_REG_BER_LH) << 8;
ber |= cx24120_readreg(state, CX24120_REG_BER_LL);
dev_dbg(&state->i2c->dev, "read BER index = %d\n", ber);
c->post_bit_error.stat[0].scale = FE_SCALE_COUNTER;
c->post_bit_error.stat[0].uvalue += ber;
c->post_bit_count.stat[0].scale = FE_SCALE_COUNTER;
c->post_bit_count.stat[0].uvalue += CX24120_BER_WSIZE;
}
if (time_after(jiffies, state->per_jiffies_stats)) {
state->per_jiffies_stats = jiffies + msecs_to_jiffies(1000);
ucb = cx24120_readreg(state, CX24120_REG_UCB_H) << 8;
ucb |= cx24120_readreg(state, CX24120_REG_UCB_L);
dev_dbg(&state->i2c->dev, "ucblocks = %d\n", ucb);
if (ucb < state->ucb_offset)
state->ucb_offset = c->block_error.stat[0].uvalue;
c->block_error.stat[0].scale = FE_SCALE_COUNTER;
c->block_error.stat[0].uvalue = ucb + state->ucb_offset;
c->block_count.stat[0].scale = FE_SCALE_COUNTER;
c->block_count.stat[0].uvalue += state->bitrate / 8 / 208;
}
}
static int cx24120_read_status(struct dvb_frontend *fe, enum fe_status *status)
{
struct cx24120_state *state = fe->demodulator_priv;
int lock;
lock = cx24120_readreg(state, CX24120_REG_STATUS);
dev_dbg(&state->i2c->dev, "status = 0x%02x\n", lock);
*status = 0;
if (lock & CX24120_HAS_SIGNAL)
*status = FE_HAS_SIGNAL;
if (lock & CX24120_HAS_CARRIER)
*status |= FE_HAS_CARRIER;
if (lock & CX24120_HAS_VITERBI)
*status |= FE_HAS_VITERBI | FE_HAS_SYNC;
if (lock & CX24120_HAS_LOCK)
*status |= FE_HAS_LOCK;
state->fe_status = *status;
cx24120_get_stats(state);
if (state->need_clock_set && *status & FE_HAS_LOCK) {
cx24120_set_clock_ratios(fe);
if (!state->mpeg_enabled)
cx24120_msg_mpeg_output_global_config(state, 1);
state->need_clock_set = 0;
}
return 0;
}
static int cx24120_get_fec(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct cx24120_state *state = fe->demodulator_priv;
int idx;
int ret;
int fec;
ret = cx24120_readreg(state, CX24120_REG_FECMODE);
fec = ret & 0x3f;
dev_dbg(&state->i2c->dev, "raw fec = %d\n", fec);
for (idx = 0; idx < ARRAY_SIZE(modfec_lookup_table); idx++) {
if (modfec_lookup_table[idx].delsys != state->dcur.delsys)
continue;
if (modfec_lookup_table[idx].val != fec)
continue;
break;
}
if (idx >= ARRAY_SIZE(modfec_lookup_table)) {
dev_dbg(&state->i2c->dev, "couldn't find fec!\n");
return -EINVAL;
}
c->modulation = modfec_lookup_table[idx].mod;
c->fec_inner = modfec_lookup_table[idx].fec;
c->pilot = (ret & 0x80) ? PILOT_ON : PILOT_OFF;
dev_dbg(&state->i2c->dev, "mod(%d), fec(%d), pilot(%d)\n",
c->modulation, c->fec_inner, c->pilot);
return 0;
}
static void cx24120_calculate_ber_window(struct cx24120_state *state, u32 rate)
{
struct dvb_frontend *fe = &state->frontend;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
u64 tmp;
tmp = (u64)c->symbol_rate * rate;
do_div(tmp, 256);
state->bitrate = tmp;
tmp = 1000000ULL * CX24120_BER_WSIZE;
do_div(tmp, state->bitrate);
state->berw_usecs = tmp;
dev_dbg(&state->i2c->dev, "bitrate: %u, berw_usecs: %u\n",
state->bitrate, state->berw_usecs);
}
static void cx24120_set_clock_ratios(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct cx24120_state *state = fe->demodulator_priv;
struct cx24120_cmd cmd;
int ret, idx;
ret = cx24120_get_fec(fe);
if (ret != 0)
return;
for (idx = 0; idx < ARRAY_SIZE(clock_ratios_table); idx++) {
if (clock_ratios_table[idx].delsys != state->dcur.delsys)
continue;
if (clock_ratios_table[idx].mod != c->modulation)
continue;
if (clock_ratios_table[idx].fec != c->fec_inner)
continue;
if (clock_ratios_table[idx].pilot != c->pilot)
continue;
break;
}
if (idx >= ARRAY_SIZE(clock_ratios_table)) {
info("Clock ratio not found - data reception in danger\n");
return;
}
cmd.id = CMD_CLOCK_READ;
cmd.len = 1;
cmd.arg[0] = 0x00;
ret = cx24120_message_sendrcv(state, &cmd, 6);
if (ret != 0)
return;
dev_dbg(&state->i2c->dev, "m=%d, n=%d; idx: %d m=%d, n=%d, rate=%d\n",
cmd.arg[2] | (cmd.arg[1] << 8) | (cmd.arg[0] << 16),
cmd.arg[5] | (cmd.arg[4] << 8) | (cmd.arg[3] << 16),
idx,
clock_ratios_table[idx].m_rat,
clock_ratios_table[idx].n_rat,
clock_ratios_table[idx].rate);
cmd.id = CMD_CLOCK_SET;
cmd.len = 10;
cmd.arg[0] = 0;
cmd.arg[1] = 0x10;
cmd.arg[2] = (clock_ratios_table[idx].m_rat >> 16) & 0xff;
cmd.arg[3] = (clock_ratios_table[idx].m_rat >> 8) & 0xff;
cmd.arg[4] = (clock_ratios_table[idx].m_rat >> 0) & 0xff;
cmd.arg[5] = (clock_ratios_table[idx].n_rat >> 16) & 0xff;
cmd.arg[6] = (clock_ratios_table[idx].n_rat >> 8) & 0xff;
cmd.arg[7] = (clock_ratios_table[idx].n_rat >> 0) & 0xff;
cmd.arg[8] = (clock_ratios_table[idx].rate >> 8) & 0xff;
cmd.arg[9] = (clock_ratios_table[idx].rate >> 0) & 0xff;
cx24120_message_send(state, &cmd);
cx24120_calculate_ber_window(state, clock_ratios_table[idx].rate);
}
static int cx24120_set_inversion(struct cx24120_state *state,
enum fe_spectral_inversion inversion)
{
dev_dbg(&state->i2c->dev, "(%d)\n", inversion);
switch (inversion) {
case INVERSION_OFF:
state->dnxt.inversion_val = 0x00;
break;
case INVERSION_ON:
state->dnxt.inversion_val = 0x04;
break;
case INVERSION_AUTO:
state->dnxt.inversion_val = 0x0c;
break;
default:
return -EINVAL;
}
state->dnxt.inversion = inversion;
return 0;
}
static int cx24120_set_fec(struct cx24120_state *state, enum fe_modulation mod,
enum fe_code_rate fec)
{
int idx;
dev_dbg(&state->i2c->dev, "(0x%02x,0x%02x)\n", mod, fec);
state->dnxt.fec = fec;
for (idx = 0; idx < ARRAY_SIZE(modfec_table); idx++) {
if (modfec_table[idx].delsys != state->dnxt.delsys)
continue;
if (modfec_table[idx].mod != mod)
continue;
if (modfec_table[idx].fec != fec)
continue;
state->dnxt.fec_mask = 0x00;
state->dnxt.fec_val = modfec_table[idx].val;
return 0;
}
if (state->dnxt.delsys == SYS_DVBS2) {
state->dnxt.fec_mask = 0x00;
state->dnxt.fec_val = 0x00;
} else {
state->dnxt.fec_val = 0x2e;
state->dnxt.fec_mask = 0xac;
}
return 0;
}
static int cx24120_set_pilot(struct cx24120_state *state, enum fe_pilot pilot)
{
dev_dbg(&state->i2c->dev, "(%d)\n", pilot);
if (state->dnxt.delsys != SYS_DVBS2) {
state->dnxt.pilot_val = CX24120_PILOT_OFF;
return 0;
}
switch (pilot) {
case PILOT_OFF:
state->dnxt.pilot_val = CX24120_PILOT_OFF;
break;
case PILOT_ON:
state->dnxt.pilot_val = CX24120_PILOT_ON;
break;
case PILOT_AUTO:
default:
state->dnxt.pilot_val = CX24120_PILOT_AUTO;
}
return 0;
}
static int cx24120_set_symbolrate(struct cx24120_state *state, u32 rate)
{
dev_dbg(&state->i2c->dev, "(%d)\n", rate);
state->dnxt.symbol_rate = rate;
if (rate > 31000000) {
state->dnxt.clkdiv = (-(rate < 31000001) & 3) + 2;
state->dnxt.ratediv = (-(rate < 31000001) & 6) + 4;
} else {
state->dnxt.clkdiv = 3;
state->dnxt.ratediv = 6;
}
return 0;
}
static void cx24120_clone_params(struct dvb_frontend *fe)
{
struct cx24120_state *state = fe->demodulator_priv;
state->dcur = state->dnxt;
}
static int cx24120_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct cx24120_state *state = fe->demodulator_priv;
struct cx24120_cmd cmd;
int ret;
switch (c->delivery_system) {
case SYS_DVBS2:
dev_dbg(&state->i2c->dev, "DVB-S2\n");
break;
case SYS_DVBS:
dev_dbg(&state->i2c->dev, "DVB-S\n");
break;
default:
dev_dbg(&state->i2c->dev,
"delivery system(%d) not supported\n",
c->delivery_system);
ret = -EINVAL;
break;
}
state->dnxt.delsys = c->delivery_system;
state->dnxt.modulation = c->modulation;
state->dnxt.frequency = c->frequency;
state->dnxt.pilot = c->pilot;
ret = cx24120_set_inversion(state, c->inversion);
if (ret != 0)
return ret;
ret = cx24120_set_fec(state, c->modulation, c->fec_inner);
if (ret != 0)
return ret;
ret = cx24120_set_pilot(state, c->pilot);
if (ret != 0)
return ret;
ret = cx24120_set_symbolrate(state, c->symbol_rate);
if (ret != 0)
return ret;
cx24120_clone_params(fe);
dev_dbg(&state->i2c->dev,
"delsys = %d\n", state->dcur.delsys);
dev_dbg(&state->i2c->dev,
"modulation = %d\n", state->dcur.modulation);
dev_dbg(&state->i2c->dev,
"frequency = %d\n", state->dcur.frequency);
dev_dbg(&state->i2c->dev,
"pilot = %d (val = 0x%02x)\n",
state->dcur.pilot, state->dcur.pilot_val);
dev_dbg(&state->i2c->dev,
"symbol_rate = %d (clkdiv/ratediv = 0x%02x/0x%02x)\n",
state->dcur.symbol_rate,
state->dcur.clkdiv, state->dcur.ratediv);
dev_dbg(&state->i2c->dev,
"FEC = %d (mask/val = 0x%02x/0x%02x)\n",
state->dcur.fec, state->dcur.fec_mask, state->dcur.fec_val);
dev_dbg(&state->i2c->dev,
"Inversion = %d (val = 0x%02x)\n",
state->dcur.inversion, state->dcur.inversion_val);
state->need_clock_set = 1;
cmd.id = CMD_TUNEREQUEST;
cmd.len = 15;
cmd.arg[0] = 0;
cmd.arg[1] = (state->dcur.frequency & 0xff0000) >> 16;
cmd.arg[2] = (state->dcur.frequency & 0x00ff00) >> 8;
cmd.arg[3] = (state->dcur.frequency & 0x0000ff);
cmd.arg[4] = ((state->dcur.symbol_rate / 1000) & 0xff00) >> 8;
cmd.arg[5] = ((state->dcur.symbol_rate / 1000) & 0x00ff);
cmd.arg[6] = state->dcur.inversion;
cmd.arg[7] = state->dcur.fec_val | state->dcur.pilot_val;
cmd.arg[8] = CX24120_SEARCH_RANGE_KHZ >> 8;
cmd.arg[9] = CX24120_SEARCH_RANGE_KHZ & 0xff;
cmd.arg[10] = 0;
cmd.arg[11] = state->dcur.fec_mask;
cmd.arg[12] = state->dcur.ratediv;
cmd.arg[13] = state->dcur.clkdiv;
cmd.arg[14] = 0;
ret = cx24120_message_send(state, &cmd);
if (ret != 0)
return ret;
ret = cx24120_writereg(state, CX24120_REG_CLKDIV, state->dcur.clkdiv);
ret = cx24120_readreg(state, CX24120_REG_RATEDIV);
ret &= 0xfffffff0;
ret |= state->dcur.ratediv;
ret = cx24120_writereg(state, CX24120_REG_RATEDIV, ret);
return 0;
}
static int cx24120_set_vco(struct cx24120_state *state)
{
struct cx24120_cmd cmd;
u32 nxtal_khz, vco;
u64 inv_vco;
u32 xtal_khz = state->config->xtal_khz;
nxtal_khz = xtal_khz * 4;
vco = nxtal_khz * 10;
inv_vco = DIV_ROUND_CLOSEST_ULL(0x400000000ULL, vco);
dev_dbg(&state->i2c->dev, "xtal=%d, vco=%d, inv_vco=%lld\n",
xtal_khz, vco, inv_vco);
cmd.id = CMD_VCO_SET;
cmd.len = 12;
cmd.arg[0] = (vco >> 16) & 0xff;
cmd.arg[1] = (vco >> 8) & 0xff;
cmd.arg[2] = vco & 0xff;
cmd.arg[3] = (inv_vco >> 8) & 0xff;
cmd.arg[4] = (inv_vco) & 0xff;
cmd.arg[5] = 0x03;
cmd.arg[6] = (nxtal_khz >> 8) & 0xff;
cmd.arg[7] = nxtal_khz & 0xff;
cmd.arg[8] = 0x06;
cmd.arg[9] = 0x03;
cmd.arg[10] = (xtal_khz >> 16) & 0xff;
cmd.arg[11] = xtal_khz & 0xff;
return cx24120_message_send(state, &cmd);
}
static int cx24120_init(struct dvb_frontend *fe)
{
const struct firmware *fw;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
struct cx24120_state *state = fe->demodulator_priv;
struct cx24120_cmd cmd;
u8 reg;
int ret, i;
unsigned char vers[4];
if (state->cold_init)
return 0;
cx24120_writereg(state, 0xea, 0x00);
cx24120_test_rom(state);
reg = cx24120_readreg(state, 0xfb) & 0xfe;
cx24120_writereg(state, 0xfb, reg);
reg = cx24120_readreg(state, 0xfc) & 0xfe;
cx24120_writereg(state, 0xfc, reg);
cx24120_writereg(state, 0xc3, 0x04);
cx24120_writereg(state, 0xc4, 0x04);
cx24120_writereg(state, 0xce, 0x00);
cx24120_writereg(state, 0xcf, 0x00);
reg = cx24120_readreg(state, 0xea) & 0xfe;
cx24120_writereg(state, 0xea, reg);
cx24120_writereg(state, 0xeb, 0x0c);
cx24120_writereg(state, 0xec, 0x06);
cx24120_writereg(state, 0xed, 0x05);
cx24120_writereg(state, 0xee, 0x03);
cx24120_writereg(state, 0xef, 0x05);
cx24120_writereg(state, 0xf3, 0x03);
cx24120_writereg(state, 0xf4, 0x44);
for (i = 0; i < 3; i++) {
cx24120_writereg(state, 0xf0 + i, 0x04);
cx24120_writereg(state, 0xe6 + i, 0x02);
}
cx24120_writereg(state, 0xea, (reg | 0x01));
for (i = 0; i < 6; i += 2) {
cx24120_writereg(state, 0xc5 + i, 0x00);
cx24120_writereg(state, 0xc6 + i, 0x00);
}
cx24120_writereg(state, 0xe4, 0x03);
cx24120_writereg(state, 0xeb, 0x0a);
dev_dbg(&state->i2c->dev, "requesting firmware (%s) to download...\n",
CX24120_FIRMWARE);
ret = state->config->request_firmware(fe, &fw, CX24120_FIRMWARE);
if (ret) {
err("Could not load firmware (%s): %d\n", CX24120_FIRMWARE,
ret);
return ret;
}
dev_dbg(&state->i2c->dev,
"Firmware found, size %d bytes (%02x %02x .. %02x %02x)\n",
(int)fw->size,
fw->data[0],
fw->data[1],
fw->data[fw->size - 2],
fw->data[fw->size - 1]);
cx24120_test_rom(state);
reg = cx24120_readreg(state, 0xfb) & 0xfe;
cx24120_writereg(state, 0xfb, reg);
cx24120_writereg(state, 0xe0, 0x76);
cx24120_writereg(state, 0xf7, 0x81);
cx24120_writereg(state, 0xf8, 0x00);
cx24120_writereg(state, 0xf9, 0x00);
cx24120_writeregs(state, 0xfa, fw->data, (fw->size - 1), 0x00);
cx24120_writereg(state, 0xf7, 0xc0);
cx24120_writereg(state, 0xe0, 0x00);
reg = (fw->size - 2) & 0x00ff;
cx24120_writereg(state, 0xf8, reg);
reg = ((fw->size - 2) >> 8) & 0x00ff;
cx24120_writereg(state, 0xf9, reg);
cx24120_writereg(state, 0xf7, 0x00);
cx24120_writereg(state, 0xdc, 0x00);
cx24120_writereg(state, 0xdc, 0x07);
msleep(500);
reg = cx24120_readreg(state, 0xe1);
if (reg == fw->data[fw->size - 1]) {
dev_dbg(&state->i2c->dev, "Firmware uploaded successfully\n");
ret = 0;
} else {
err("Firmware upload failed. Last byte returned=0x%x\n", ret);
ret = -EREMOTEIO;
}
cx24120_writereg(state, 0xdc, 0x00);
release_firmware(fw);
if (ret != 0)
return ret;
cmd.id = CMD_START_TUNER;
cmd.len = 3;
cmd.arg[0] = 0x00;
cmd.arg[1] = 0x00;
cmd.arg[2] = 0x00;
if (cx24120_message_send(state, &cmd) != 0) {
err("Error tuner start! :(\n");
return -EREMOTEIO;
}
ret = cx24120_set_vco(state);
if (ret != 0) {
err("Error set VCO! :(\n");
return ret;
}
cmd.id = CMD_BANDWIDTH;
cmd.len = 12;
cmd.arg[0] = 0x00;
cmd.arg[1] = 0x00;
cmd.arg[2] = 0x00;
cmd.arg[3] = 0x00;
cmd.arg[4] = 0x05;
cmd.arg[5] = 0x02;
cmd.arg[6] = 0x02;
cmd.arg[7] = 0x00;
cmd.arg[8] = 0x05;
cmd.arg[9] = 0x02;
cmd.arg[10] = 0x02;
cmd.arg[11] = 0x00;
if (cx24120_message_send(state, &cmd)) {
err("Error set bandwidth!\n");
return -EREMOTEIO;
}
reg = cx24120_readreg(state, 0xba);
if (reg > 3) {
dev_dbg(&state->i2c->dev, "Reset-readreg 0xba: %x\n", ret);
err("Error initialising tuner!\n");
return -EREMOTEIO;
}
dev_dbg(&state->i2c->dev, "Tuner initialised correctly.\n");
cx24120_writereg(state, 0xeb, 0x0a);
if (cx24120_msg_mpeg_output_global_config(state, 0) ||
cx24120_msg_mpeg_output_config(state, 0) ||
cx24120_msg_mpeg_output_config(state, 1) ||
cx24120_msg_mpeg_output_config(state, 2)) {
err("Error initialising mpeg output. :(\n");
return -EREMOTEIO;
}
cmd.id = CMD_BER_CTRL;
cmd.len = 3;
cmd.arg[0] = 0x00;
cmd.arg[1] = CX24120_BER_WINDOW;
cmd.arg[2] = CX24120_BER_WINDOW;
if (cx24120_message_send(state, &cmd)) {
err("Error setting ber window\n");
return -EREMOTEIO;
}
cmd.id = CMD_FWVERSION;
cmd.len = 1;
for (i = 0; i < 4; i++) {
cmd.arg[0] = i;
ret = cx24120_message_send(state, &cmd);
if (ret != 0)
return ret;
vers[i] = cx24120_readreg(state, CX24120_REG_MAILBOX);
}
info("FW version %i.%i.%i.%i\n", vers[0], vers[1], vers[2], vers[3]);
c->strength.len = 1;
c->strength.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->cnr.len = 1;
c->cnr.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->post_bit_error.len = 1;
c->post_bit_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->post_bit_count.len = 1;
c->post_bit_count.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->block_error.len = 1;
c->block_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->block_count.len = 1;
c->block_count.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
state->cold_init = 1;
return 0;
}
static int cx24120_tune(struct dvb_frontend *fe, bool re_tune,
unsigned int mode_flags, unsigned int *delay,
enum fe_status *status)
{
struct cx24120_state *state = fe->demodulator_priv;
int ret;
dev_dbg(&state->i2c->dev, "(%d)\n", re_tune);
if (re_tune) {
ret = cx24120_set_frontend(fe);
if (ret)
return ret;
}
return cx24120_read_status(fe, status);
}
static int cx24120_get_algo(struct dvb_frontend *fe)
{
return DVBFE_ALGO_HW;
}
static int cx24120_sleep(struct dvb_frontend *fe)
{
return 0;
}
static int cx24120_get_frontend(struct dvb_frontend *fe,
struct dtv_frontend_properties *c)
{
struct cx24120_state *state = fe->demodulator_priv;
u8 freq1, freq2, freq3;
int status;
dev_dbg(&state->i2c->dev, "\n");
status = cx24120_readreg(state, CX24120_REG_STATUS);
if (!(status & CX24120_HAS_LOCK))
return 0;
freq1 = cx24120_readreg(state, CX24120_REG_FREQ1);
freq2 = cx24120_readreg(state, CX24120_REG_FREQ2);
freq3 = cx24120_readreg(state, CX24120_REG_FREQ3);
c->frequency = (freq3 << 16) | (freq2 << 8) | freq1;
dev_dbg(&state->i2c->dev, "frequency = %d\n", c->frequency);
cx24120_get_fec(fe);
return 0;
}
static void cx24120_release(struct dvb_frontend *fe)
{
struct cx24120_state *state = fe->demodulator_priv;
dev_dbg(&state->i2c->dev, "Clear state structure\n");
kfree(state);
}
static int cx24120_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
struct cx24120_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
if (c->block_error.stat[0].scale != FE_SCALE_COUNTER) {
*ucblocks = 0;
return 0;
}
*ucblocks = c->block_error.stat[0].uvalue - state->ucb_offset;
return 0;
}
