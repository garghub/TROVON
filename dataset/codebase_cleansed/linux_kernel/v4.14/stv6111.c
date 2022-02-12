static inline u32 muldiv32(u32 a, u32 b, u32 c)
{
u64 tmp64;
tmp64 = (u64)a * (u64)b;
do_div(tmp64, c);
return (u32)tmp64;
}
static int i2c_read(struct i2c_adapter *adap,
u8 adr, u8 *msg, int len, u8 *answ, int alen)
{
struct i2c_msg msgs[2] = { { .addr = adr, .flags = 0,
.buf = msg, .len = len},
{ .addr = adr, .flags = I2C_M_RD,
.buf = answ, .len = alen } };
if (i2c_transfer(adap, msgs, 2) != 2) {
dev_err(&adap->dev, "i2c read error\n");
return -EIO;
}
return 0;
}
static int i2c_write(struct i2c_adapter *adap, u8 adr, u8 *data, int len)
{
struct i2c_msg msg = {.addr = adr, .flags = 0,
.buf = data, .len = len};
if (i2c_transfer(adap, &msg, 1) != 1) {
dev_err(&adap->dev, "i2c write error\n");
return -EIO;
}
return 0;
}
static int write_regs(struct stv *state, int reg, int len)
{
u8 d[12];
memcpy(&d[1], &state->reg[reg], len);
d[0] = reg;
return i2c_write(state->i2c, state->adr, d, len + 1);
}
static int write_reg(struct stv *state, u8 reg, u8 val)
{
u8 d[2] = {reg, val};
return i2c_write(state->i2c, state->adr, d, 2);
}
static int read_reg(struct stv *state, u8 reg, u8 *val)
{
return i2c_read(state->i2c, state->adr, &reg, 1, val, 1);
}
static int wait_for_call_done(struct stv *state, u8 mask)
{
int status = 0;
u32 lock_retry_count = 10;
while (lock_retry_count > 0) {
u8 regval;
status = read_reg(state, 9, &regval);
if (status < 0)
return status;
if ((regval & mask) == 0)
break;
usleep_range(4000, 6000);
lock_retry_count -= 1;
status = -EIO;
}
return status;
}
static void init_state(struct stv *state)
{
u32 clkdiv = 0;
u32 agcmode = 0;
u32 agcref = 2;
u32 agcset = 0xffffffff;
u32 bbmode = 0xffffffff;
state->reg[0] = 0x08;
state->reg[1] = 0x41;
state->reg[2] = 0x8f;
state->reg[3] = 0x00;
state->reg[4] = 0xce;
state->reg[5] = 0x54;
state->reg[6] = 0x55;
state->reg[7] = 0x45;
state->reg[8] = 0x46;
state->reg[9] = 0xbd;
state->reg[10] = 0x11;
state->ref_freq = 16000;
if (clkdiv <= 3)
state->reg[0x00] |= (clkdiv & 0x03);
if (agcmode <= 3) {
state->reg[0x03] |= (agcmode << 5);
if (agcmode == 0x01)
state->reg[0x01] |= 0x30;
}
if (bbmode <= 3)
state->reg[0x01] = (state->reg[0x01] & ~0x30) | (bbmode << 4);
if (agcref <= 7)
state->reg[0x03] |= agcref;
if (agcset <= 31)
state->reg[0x02] = (state->reg[0x02] & ~0x1F) | agcset | 0x40;
}
static int attach_init(struct stv *state)
{
if (write_regs(state, 0, 11))
return -ENODEV;
return 0;
}
static void release(struct dvb_frontend *fe)
{
kfree(fe->tuner_priv);
fe->tuner_priv = NULL;
}
static int set_bandwidth(struct dvb_frontend *fe, u32 cutoff_frequency)
{
struct stv *state = fe->tuner_priv;
u32 index = (cutoff_frequency + 999999) / 1000000;
if (index < 6)
index = 6;
if (index > 50)
index = 50;
if ((state->reg[0x08] & ~0xFC) == ((index - 6) << 2))
return 0;
state->reg[0x08] = (state->reg[0x08] & ~0xFC) | ((index - 6) << 2);
state->reg[0x09] = (state->reg[0x09] & ~0x0C) | 0x08;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
write_regs(state, 0x08, 2);
wait_for_call_done(state, 0x08);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
return 0;
}
static int set_lof(struct stv *state, u32 local_frequency, u32 cutoff_frequency)
{
u32 index = (cutoff_frequency + 999999) / 1000000;
u32 frequency = (local_frequency + 500) / 1000;
u32 p = 1, psel = 0, fvco, div, frac;
u8 icp, tmp;
if (index < 6)
index = 6;
if (index > 50)
index = 50;
if (frequency <= 1300000) {
p = 4;
psel = 1;
} else {
p = 2;
psel = 0;
}
fvco = frequency * p;
div = fvco / state->ref_freq;
frac = fvco % state->ref_freq;
frac = muldiv32(frac, 0x40000, state->ref_freq);
icp = 0;
if (fvco < 2700000)
icp = 0;
else if (fvco < 2950000)
icp = 1;
else if (fvco < 3300000)
icp = 2;
else if (fvco < 3700000)
icp = 3;
else if (fvco < 4200000)
icp = 5;
else if (fvco < 4800000)
icp = 6;
else
icp = 7;
state->reg[0x02] |= 0x80;
state->reg[0x03] = (state->reg[0x03] & ~0x80) | (psel << 7);
state->reg[0x04] = (div & 0xFF);
state->reg[0x05] = (((div >> 8) & 0x01) | ((frac & 0x7F) << 1)) & 0xff;
state->reg[0x06] = ((frac >> 7) & 0xFF);
state->reg[0x07] = (state->reg[0x07] & ~0x07) | ((frac >> 15) & 0x07);
state->reg[0x07] = (state->reg[0x07] & ~0xE0) | (icp << 5);
state->reg[0x08] = (state->reg[0x08] & ~0xFC) | ((index - 6) << 2);
state->reg[0x09] = (state->reg[0x09] & ~0x0C) | 0x0C;
write_regs(state, 2, 8);
wait_for_call_done(state, 0x0C);
usleep_range(10000, 12000);
read_reg(state, 0x03, &tmp);
if (tmp & 0x10) {
state->reg[0x02] &= ~0x80;
write_regs(state, 2, 1);
}
read_reg(state, 0x08, &tmp);
state->frequency = frequency;
return 0;
}
static int set_params(struct dvb_frontend *fe)
{
struct stv *state = fe->tuner_priv;
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
u32 freq, cutoff;
if (p->delivery_system != SYS_DVBS && p->delivery_system != SYS_DVBS2)
return -EINVAL;
freq = p->frequency * 1000;
cutoff = 5000000 + muldiv32(p->symbol_rate, 135, 200);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
set_lof(state, freq, cutoff);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
return 0;
}
static s32 table_lookup(const struct slookup *table,
int table_size, u16 reg_value)
{
s32 gain;
s32 reg_diff;
int imin = 0;
int imax = table_size - 1;
int i;
if (reg_value <= table[0].reg_value) {
gain = table[0].value;
} else if (reg_value >= table[imax].reg_value) {
gain = table[imax].value;
} else {
while ((imax - imin) > 1) {
i = (imax + imin) / 2;
if ((table[imin].reg_value <= reg_value) &&
(reg_value <= table[i].reg_value))
imax = i;
else
imin = i;
}
reg_diff = table[imax].reg_value - table[imin].reg_value;
gain = table[imin].value;
if (reg_diff != 0)
gain += ((s32)(reg_value - table[imin].reg_value) *
(s32)(table[imax].value
- table[imin].value)) / reg_diff;
}
return gain;
}
static int get_rf_strength(struct dvb_frontend *fe, u16 *st)
{
struct stv *state = fe->tuner_priv;
u16 rfagc = *st;
s32 gain;
if ((state->reg[0x03] & 0x60) == 0) {
u8 reg = 0;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
write_reg(state, 0x02, state->reg[0x02] | 0x20);
read_reg(state, 2, &reg);
if (reg & 0x20)
read_reg(state, 2, &reg);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
if ((state->reg[0x02] & 0x80) == 0)
gain = table_lookup(lnagain_nf_lookup,
ARRAY_SIZE(lnagain_nf_lookup),
reg & 0x1F);
else
gain = table_lookup(lnagain_iip3_lookup,
ARRAY_SIZE(lnagain_iip3_lookup),
reg & 0x1F);
gain += table_lookup(gain_rfagc_lookup,
ARRAY_SIZE(gain_rfagc_lookup), rfagc);
gain -= 2400;
} else {
if ((state->reg[0x02] & 0x80) == 0) {
gain = table_lookup(
gain_channel_agc_nf_lookup,
ARRAY_SIZE(gain_channel_agc_nf_lookup), rfagc);
gain += 600;
} else {
gain = table_lookup(
gain_channel_agc_iip3_lookup,
ARRAY_SIZE(gain_channel_agc_iip3_lookup),
rfagc);
}
}
if (state->frequency > 0)
gain -= ((((s32)(state->frequency / 1000) - 1550) * 2) / 12);
gain += (s32)((state->reg[0x01] & 0xC0) >> 6) * 600 - 1300;
if (gain < 0)
gain = 0;
else if (gain > 10000)
gain = 10000;
*st = 10000 - gain;
return 0;
}
struct dvb_frontend *stv6111_attach(struct dvb_frontend *fe,
struct i2c_adapter *i2c, u8 adr)
{
struct stv *state;
int stat;
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return NULL;
state->adr = adr;
state->i2c = i2c;
memcpy(&fe->ops.tuner_ops, &tuner_ops, sizeof(struct dvb_tuner_ops));
init_state(state);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
stat = attach_init(state);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
if (stat < 0) {
kfree(state);
return NULL;
}
fe->tuner_priv = state;
return fe;
}
