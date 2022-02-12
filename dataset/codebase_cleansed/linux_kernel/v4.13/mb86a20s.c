static int mb86a20s_i2c_writereg(struct mb86a20s_state *state,
u8 i2c_addr, u8 reg, u8 data)
{
u8 buf[] = { reg, data };
struct i2c_msg msg = {
.addr = i2c_addr, .flags = 0, .buf = buf, .len = 2
};
int rc;
rc = i2c_transfer(state->i2c, &msg, 1);
if (rc != 1) {
dev_err(&state->i2c->dev,
"%s: writereg error (rc == %i, reg == 0x%02x, data == 0x%02x)\n",
__func__, rc, reg, data);
return rc;
}
return 0;
}
static int mb86a20s_i2c_writeregdata(struct mb86a20s_state *state,
u8 i2c_addr, struct regdata *rd, int size)
{
int i, rc;
for (i = 0; i < size; i++) {
rc = mb86a20s_i2c_writereg(state, i2c_addr, rd[i].reg,
rd[i].data);
if (rc < 0)
return rc;
}
return 0;
}
static int mb86a20s_i2c_readreg(struct mb86a20s_state *state,
u8 i2c_addr, u8 reg)
{
u8 val;
int rc;
struct i2c_msg msg[] = {
{ .addr = i2c_addr, .flags = 0, .buf = &reg, .len = 1 },
{ .addr = i2c_addr, .flags = I2C_M_RD, .buf = &val, .len = 1 }
};
rc = i2c_transfer(state->i2c, msg, 2);
if (rc != 2) {
dev_err(&state->i2c->dev, "%s: reg=0x%x (error=%d)\n",
__func__, reg, rc);
return (rc < 0) ? rc : -EIO;
}
return val;
}
static int mb86a20s_read_status(struct dvb_frontend *fe, enum fe_status *status)
{
struct mb86a20s_state *state = fe->demodulator_priv;
int val;
*status = 0;
val = mb86a20s_readreg(state, 0x0a);
if (val < 0)
return val;
val &= 0xf;
if (val >= 2)
*status |= FE_HAS_SIGNAL;
if (val >= 4)
*status |= FE_HAS_CARRIER;
if (val >= 5)
*status |= FE_HAS_VITERBI;
if (val >= 7)
*status |= FE_HAS_SYNC;
if (val >= 9)
*status |= FE_HAS_LOCK;
dev_dbg(&state->i2c->dev, "%s: Status = 0x%02x (state = %d)\n",
__func__, *status, val);
return val;
}
static int mb86a20s_read_signal_strength(struct dvb_frontend *fe)
{
struct mb86a20s_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int rc;
unsigned rf_max, rf_min, rf;
if (state->get_strength_time &&
(!time_after(jiffies, state->get_strength_time)))
return c->strength.stat[0].uvalue;
c->strength.stat[0].uvalue = 0;
rf_max = 0xfff;
rf_min = 0;
do {
rf = (rf_max + rf_min) / 2;
rc = mb86a20s_writereg(state, 0x04, 0x1f);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x05, rf >> 8);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x04, 0x20);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x05, rf);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x02);
if (rc < 0)
return rc;
if (rc & 0x08)
rf_min = (rf_max + rf_min) / 2;
else
rf_max = (rf_max + rf_min) / 2;
if (rf_max - rf_min < 4) {
rf = (rf_max + rf_min) / 2;
rf = rf << (16 - 12);
if (rf)
rf |= (1 << 12) - 1;
dev_dbg(&state->i2c->dev,
"%s: signal strength = %d (%d < RF=%d < %d)\n",
__func__, rf, rf_min, rf >> 4, rf_max);
c->strength.stat[0].uvalue = rf;
state->get_strength_time = jiffies +
msecs_to_jiffies(1000);
return 0;
}
} while (1);
}
static int mb86a20s_get_modulation(struct mb86a20s_state *state,
unsigned layer)
{
int rc;
static unsigned char reg[] = {
[0] = 0x86,
[1] = 0x8a,
[2] = 0x8e,
};
if (layer >= ARRAY_SIZE(reg))
return -EINVAL;
rc = mb86a20s_writereg(state, 0x6d, reg[layer]);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x6e);
if (rc < 0)
return rc;
switch ((rc >> 4) & 0x07) {
case 0:
return DQPSK;
case 1:
return QPSK;
case 2:
return QAM_16;
case 3:
return QAM_64;
default:
return QAM_AUTO;
}
}
static int mb86a20s_get_fec(struct mb86a20s_state *state,
unsigned layer)
{
int rc;
static unsigned char reg[] = {
[0] = 0x87,
[1] = 0x8b,
[2] = 0x8f,
};
if (layer >= ARRAY_SIZE(reg))
return -EINVAL;
rc = mb86a20s_writereg(state, 0x6d, reg[layer]);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x6e);
if (rc < 0)
return rc;
switch ((rc >> 4) & 0x07) {
case 0:
return FEC_1_2;
case 1:
return FEC_2_3;
case 2:
return FEC_3_4;
case 3:
return FEC_5_6;
case 4:
return FEC_7_8;
default:
return FEC_AUTO;
}
}
static int mb86a20s_get_interleaving(struct mb86a20s_state *state,
unsigned layer)
{
int rc;
int interleaving[] = {
0, 1, 2, 4, 8
};
static unsigned char reg[] = {
[0] = 0x88,
[1] = 0x8c,
[2] = 0x90,
};
if (layer >= ARRAY_SIZE(reg))
return -EINVAL;
rc = mb86a20s_writereg(state, 0x6d, reg[layer]);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x6e);
if (rc < 0)
return rc;
return interleaving[(rc >> 4) & 0x07];
}
static int mb86a20s_get_segment_count(struct mb86a20s_state *state,
unsigned layer)
{
int rc, count;
static unsigned char reg[] = {
[0] = 0x89,
[1] = 0x8d,
[2] = 0x91,
};
dev_dbg(&state->i2c->dev, "%s called.\n", __func__);
if (layer >= ARRAY_SIZE(reg))
return -EINVAL;
rc = mb86a20s_writereg(state, 0x6d, reg[layer]);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x6e);
if (rc < 0)
return rc;
count = (rc >> 4) & 0x0f;
dev_dbg(&state->i2c->dev, "%s: segments: %d.\n", __func__, count);
return count;
}
static void mb86a20s_reset_frontend_cache(struct dvb_frontend *fe)
{
struct mb86a20s_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
dev_dbg(&state->i2c->dev, "%s called.\n", __func__);
c->delivery_system = SYS_ISDBT;
c->bandwidth_hz = 6000000;
c->isdbt_layer_enabled = 0;
c->transmission_mode = TRANSMISSION_MODE_AUTO;
c->guard_interval = GUARD_INTERVAL_AUTO;
c->isdbt_sb_mode = 0;
c->isdbt_sb_segment_count = 0;
}
static void mb86a20s_layer_bitrate(struct dvb_frontend *fe, u32 layer,
u32 modulation, u32 forward_error_correction,
u32 guard_interval,
u32 segment)
{
struct mb86a20s_state *state = fe->demodulator_priv;
u32 rate;
int mod, fec, guard;
switch (modulation) {
case DQPSK:
case QPSK:
default:
mod = 0;
break;
case QAM_16:
mod = 1;
break;
case QAM_64:
mod = 2;
break;
}
switch (forward_error_correction) {
default:
case FEC_1_2:
case FEC_AUTO:
fec = 0;
break;
case FEC_2_3:
fec = 1;
break;
case FEC_3_4:
fec = 2;
break;
case FEC_5_6:
fec = 3;
break;
case FEC_7_8:
fec = 4;
break;
}
switch (guard_interval) {
default:
case GUARD_INTERVAL_1_4:
guard = 0;
break;
case GUARD_INTERVAL_1_8:
guard = 1;
break;
case GUARD_INTERVAL_1_16:
guard = 2;
break;
case GUARD_INTERVAL_1_32:
guard = 3;
break;
}
rate = isdbt_rate[mod][fec][guard] * segment * BER_SAMPLING_RATE;
if (rate < 256)
rate = 256;
else if (rate > (1 << 24) - 1)
rate = (1 << 24) - 1;
dev_dbg(&state->i2c->dev,
"%s: layer %c bitrate: %d kbps; counter = %d (0x%06x)\n",
__func__, 'A' + layer,
segment * isdbt_rate[mod][fec][guard]/1000,
rate, rate);
state->estimated_rate[layer] = rate;
}
static int mb86a20s_get_frontend(struct dvb_frontend *fe)
{
struct mb86a20s_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int layer, rc;
dev_dbg(&state->i2c->dev, "%s called.\n", __func__);
mb86a20s_reset_frontend_cache(fe);
rc = mb86a20s_writereg(state, 0x6d, 0x85);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x6e);
if (rc < 0)
return rc;
c->isdbt_partial_reception = (rc & 0x10) ? 1 : 0;
for (layer = 0; layer < NUM_LAYERS; layer++) {
dev_dbg(&state->i2c->dev, "%s: getting data for layer %c.\n",
__func__, 'A' + layer);
rc = mb86a20s_get_segment_count(state, layer);
if (rc < 0)
goto noperlayer_error;
if (rc >= 0 && rc < 14) {
c->layer[layer].segment_count = rc;
} else {
c->layer[layer].segment_count = 0;
state->estimated_rate[layer] = 0;
continue;
}
c->isdbt_layer_enabled |= 1 << layer;
rc = mb86a20s_get_modulation(state, layer);
if (rc < 0)
goto noperlayer_error;
dev_dbg(&state->i2c->dev, "%s: modulation %d.\n",
__func__, rc);
c->layer[layer].modulation = rc;
rc = mb86a20s_get_fec(state, layer);
if (rc < 0)
goto noperlayer_error;
dev_dbg(&state->i2c->dev, "%s: FEC %d.\n",
__func__, rc);
c->layer[layer].fec = rc;
rc = mb86a20s_get_interleaving(state, layer);
if (rc < 0)
goto noperlayer_error;
dev_dbg(&state->i2c->dev, "%s: interleaving %d.\n",
__func__, rc);
c->layer[layer].interleaving = rc;
mb86a20s_layer_bitrate(fe, layer, c->layer[layer].modulation,
c->layer[layer].fec,
c->guard_interval,
c->layer[layer].segment_count);
}
rc = mb86a20s_writereg(state, 0x6d, 0x84);
if (rc < 0)
return rc;
if ((rc & 0x60) == 0x20) {
c->isdbt_sb_mode = 1;
if (!c->isdbt_sb_segment_count)
c->isdbt_sb_segment_count = 1;
}
rc = mb86a20s_readreg(state, 0x07);
if (rc < 0)
return rc;
c->transmission_mode = TRANSMISSION_MODE_AUTO;
if ((rc & 0x60) == 0x20) {
switch ((rc >> 2) & 0x03) {
case 1:
c->transmission_mode = TRANSMISSION_MODE_4K;
break;
case 2:
c->transmission_mode = TRANSMISSION_MODE_8K;
break;
}
}
c->guard_interval = GUARD_INTERVAL_AUTO;
if (!(rc & 0x10)) {
switch (rc & 0x3) {
case 0:
c->guard_interval = GUARD_INTERVAL_1_4;
break;
case 1:
c->guard_interval = GUARD_INTERVAL_1_8;
break;
case 2:
c->guard_interval = GUARD_INTERVAL_1_16;
break;
}
}
return 0;
noperlayer_error:
c->isdbt_layer_enabled = 0;
return rc;
}
static int mb86a20s_reset_counters(struct dvb_frontend *fe)
{
struct mb86a20s_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int rc, val;
dev_dbg(&state->i2c->dev, "%s called.\n", __func__);
if (state->last_frequency != c->frequency) {
memset(&c->cnr, 0, sizeof(c->cnr));
memset(&c->pre_bit_error, 0, sizeof(c->pre_bit_error));
memset(&c->pre_bit_count, 0, sizeof(c->pre_bit_count));
memset(&c->post_bit_error, 0, sizeof(c->post_bit_error));
memset(&c->post_bit_count, 0, sizeof(c->post_bit_count));
memset(&c->block_error, 0, sizeof(c->block_error));
memset(&c->block_count, 0, sizeof(c->block_count));
state->last_frequency = c->frequency;
}
rc = mb86a20s_writeregdata(state, mb86a20s_per_ber_reset);
if (rc < 0)
goto err;
rc = mb86a20s_readreg(state, 0x45);
if (rc < 0)
goto err;
val = rc;
rc = mb86a20s_writereg(state, 0x45, val | 0x10);
if (rc < 0)
goto err;
rc = mb86a20s_writereg(state, 0x45, val & 0x6f);
if (rc < 0)
goto err;
rc = mb86a20s_writereg(state, 0x50, 0x50);
if (rc < 0)
goto err;
rc = mb86a20s_readreg(state, 0x51);
if (rc < 0)
goto err;
val = rc;
rc = mb86a20s_writereg(state, 0x51, val | 0x01);
if (rc < 0)
goto err;
rc = mb86a20s_writereg(state, 0x51, val & 0x06);
if (rc < 0)
goto err;
goto ok;
err:
dev_err(&state->i2c->dev,
"%s: Can't reset FE statistics (error %d).\n",
__func__, rc);
ok:
return rc;
}
static int mb86a20s_get_pre_ber(struct dvb_frontend *fe,
unsigned layer,
u32 *error, u32 *count)
{
struct mb86a20s_state *state = fe->demodulator_priv;
int rc, val;
dev_dbg(&state->i2c->dev, "%s called.\n", __func__);
if (layer >= NUM_LAYERS)
return -EINVAL;
rc = mb86a20s_readreg(state, 0x54);
if (rc < 0)
return rc;
if (!(rc & (1 << layer))) {
dev_dbg(&state->i2c->dev,
"%s: preBER for layer %c is not available yet.\n",
__func__, 'A' + layer);
return -EBUSY;
}
rc = mb86a20s_readreg(state, 0x55 + layer * 3);
if (rc < 0)
return rc;
*error = rc << 16;
rc = mb86a20s_readreg(state, 0x56 + layer * 3);
if (rc < 0)
return rc;
*error |= rc << 8;
rc = mb86a20s_readreg(state, 0x57 + layer * 3);
if (rc < 0)
return rc;
*error |= rc;
dev_dbg(&state->i2c->dev,
"%s: bit error before Viterbi for layer %c: %d.\n",
__func__, 'A' + layer, *error);
rc = mb86a20s_writereg(state, 0x50, 0xa7 + layer * 3);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x51);
if (rc < 0)
return rc;
*count = rc << 16;
rc = mb86a20s_writereg(state, 0x50, 0xa8 + layer * 3);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x51);
if (rc < 0)
return rc;
*count |= rc << 8;
rc = mb86a20s_writereg(state, 0x50, 0xa9 + layer * 3);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x51);
if (rc < 0)
return rc;
*count |= rc;
dev_dbg(&state->i2c->dev,
"%s: bit count before Viterbi for layer %c: %d.\n",
__func__, 'A' + layer, *count);
if (state->estimated_rate[layer]
&& state->estimated_rate[layer] != *count) {
dev_dbg(&state->i2c->dev,
"%s: updating layer %c preBER counter to %d.\n",
__func__, 'A' + layer, state->estimated_rate[layer]);
rc = mb86a20s_writereg(state, 0x52, 0x00);
rc = mb86a20s_writereg(state, 0x50, 0xa7 + layer * 3);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x51,
state->estimated_rate[layer] >> 16);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x50, 0xa8 + layer * 3);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x51,
state->estimated_rate[layer] >> 8);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x50, 0xa9 + layer * 3);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x51,
state->estimated_rate[layer]);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x52, 0x01);
rc = mb86a20s_writereg(state, 0x53, 0x00);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x53, 0x07);
} else {
rc = mb86a20s_readreg(state, 0x53);
if (rc < 0)
return rc;
val = rc;
rc = mb86a20s_writereg(state, 0x53, val & ~(1 << layer));
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x53, val | (1 << layer));
}
return rc;
}
static int mb86a20s_get_post_ber(struct dvb_frontend *fe,
unsigned layer,
u32 *error, u32 *count)
{
struct mb86a20s_state *state = fe->demodulator_priv;
u32 counter, collect_rate;
int rc, val;
dev_dbg(&state->i2c->dev, "%s called.\n", __func__);
if (layer >= NUM_LAYERS)
return -EINVAL;
rc = mb86a20s_readreg(state, 0x60);
if (rc < 0)
return rc;
if (!(rc & (1 << layer))) {
dev_dbg(&state->i2c->dev,
"%s: post BER for layer %c is not available yet.\n",
__func__, 'A' + layer);
return -EBUSY;
}
rc = mb86a20s_readreg(state, 0x64 + layer * 3);
if (rc < 0)
return rc;
*error = rc << 16;
rc = mb86a20s_readreg(state, 0x65 + layer * 3);
if (rc < 0)
return rc;
*error |= rc << 8;
rc = mb86a20s_readreg(state, 0x66 + layer * 3);
if (rc < 0)
return rc;
*error |= rc;
dev_dbg(&state->i2c->dev,
"%s: post bit error for layer %c: %d.\n",
__func__, 'A' + layer, *error);
rc = mb86a20s_writereg(state, 0x50, 0xdc + layer * 2);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x51);
if (rc < 0)
return rc;
counter = rc << 8;
rc = mb86a20s_writereg(state, 0x50, 0xdd + layer * 2);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x51);
if (rc < 0)
return rc;
counter |= rc;
*count = counter * 204 * 8;
dev_dbg(&state->i2c->dev,
"%s: post bit count for layer %c: %d.\n",
__func__, 'A' + layer, *count);
if (!state->estimated_rate[layer])
goto reset_measurement;
collect_rate = state->estimated_rate[layer] / 204 / 8;
if (collect_rate < 32)
collect_rate = 32;
if (collect_rate > 65535)
collect_rate = 65535;
if (collect_rate != counter) {
dev_dbg(&state->i2c->dev,
"%s: updating postBER counter on layer %c to %d.\n",
__func__, 'A' + layer, collect_rate);
rc = mb86a20s_writereg(state, 0x5e, 0x00);
rc = mb86a20s_writereg(state, 0x50, 0xdc + layer * 2);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x51, collect_rate >> 8);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x50, 0xdd + layer * 2);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x51, collect_rate & 0xff);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x5e, 0x07);
rc = mb86a20s_writereg(state, 0x5f, 0x00);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x5f, 0x07);
return rc;
}
reset_measurement:
rc = mb86a20s_readreg(state, 0x5f);
if (rc < 0)
return rc;
val = rc;
rc = mb86a20s_writereg(state, 0x5f, val & ~(1 << layer));
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x5f, val | (1 << layer));
return rc;
}
static int mb86a20s_get_blk_error(struct dvb_frontend *fe,
unsigned layer,
u32 *error, u32 *count)
{
struct mb86a20s_state *state = fe->demodulator_priv;
int rc, val;
u32 collect_rate;
dev_dbg(&state->i2c->dev, "%s called.\n", __func__);
if (layer >= NUM_LAYERS)
return -EINVAL;
rc = mb86a20s_writereg(state, 0x50, 0xb8);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x51);
if (rc < 0)
return rc;
if (!(rc & (1 << layer))) {
dev_dbg(&state->i2c->dev,
"%s: block counts for layer %c aren't available yet.\n",
__func__, 'A' + layer);
return -EBUSY;
}
rc = mb86a20s_writereg(state, 0x50, 0xb9 + layer * 2);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x51);
if (rc < 0)
return rc;
*error = rc << 8;
rc = mb86a20s_writereg(state, 0x50, 0xba + layer * 2);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x51);
if (rc < 0)
return rc;
*error |= rc;
dev_dbg(&state->i2c->dev, "%s: block error for layer %c: %d.\n",
__func__, 'A' + layer, *error);
rc = mb86a20s_writereg(state, 0x50, 0xb2 + layer * 2);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x51);
if (rc < 0)
return rc;
*count = rc << 8;
rc = mb86a20s_writereg(state, 0x50, 0xb3 + layer * 2);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x51);
if (rc < 0)
return rc;
*count |= rc;
dev_dbg(&state->i2c->dev,
"%s: block count for layer %c: %d.\n",
__func__, 'A' + layer, *count);
if (!state->estimated_rate[layer])
goto reset_measurement;
collect_rate = state->estimated_rate[layer] / 204 / 8;
if (collect_rate < 32)
collect_rate = 32;
if (collect_rate > 65535)
collect_rate = 65535;
if (collect_rate != *count) {
dev_dbg(&state->i2c->dev,
"%s: updating PER counter on layer %c to %d.\n",
__func__, 'A' + layer, collect_rate);
rc = mb86a20s_writereg(state, 0x50, 0xb0);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x51, 0x00);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x50, 0xb2 + layer * 2);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x51, collect_rate >> 8);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x50, 0xb3 + layer * 2);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x51, collect_rate & 0xff);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x50, 0xb0);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x51, 0x07);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x50, 0xb1);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x51, 0x07);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x51, 0x00);
return rc;
}
reset_measurement:
rc = mb86a20s_writereg(state, 0x50, 0xb1);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x51);
if (rc < 0)
return rc;
val = rc;
rc = mb86a20s_writereg(state, 0x51, val | (1 << layer));
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x51, val & ~(1 << layer));
return rc;
}
static u32 interpolate_value(u32 value, const struct linear_segments *segments,
unsigned len)
{
u64 tmp64;
u32 dx, dy;
int i, ret;
if (value >= segments[0].x)
return segments[0].y;
if (value < segments[len-1].x)
return segments[len-1].y;
for (i = 1; i < len - 1; i++) {
if (value == segments[i].x)
return segments[i].y;
if (value > segments[i].x)
break;
}
dy = segments[i].y - segments[i - 1].y;
dx = segments[i - 1].x - segments[i].x;
tmp64 = value - segments[i].x;
tmp64 *= dy;
do_div(tmp64, dx);
ret = segments[i].y - tmp64;
return ret;
}
static int mb86a20s_get_main_CNR(struct dvb_frontend *fe)
{
struct mb86a20s_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
u32 cnr_linear, cnr;
int rc, val;
rc = mb86a20s_readreg(state, 0x45);
if (rc < 0)
return rc;
if (!(rc & 0x40)) {
dev_dbg(&state->i2c->dev, "%s: CNR is not available yet.\n",
__func__);
return -EBUSY;
}
val = rc;
rc = mb86a20s_readreg(state, 0x46);
if (rc < 0)
return rc;
cnr_linear = rc << 8;
rc = mb86a20s_readreg(state, 0x46);
if (rc < 0)
return rc;
cnr_linear |= rc;
cnr = interpolate_value(cnr_linear,
cnr_to_db_table, ARRAY_SIZE(cnr_to_db_table));
c->cnr.stat[0].scale = FE_SCALE_DECIBEL;
c->cnr.stat[0].svalue = cnr;
dev_dbg(&state->i2c->dev, "%s: CNR is %d.%03d dB (%d)\n",
__func__, cnr / 1000, cnr % 1000, cnr_linear);
rc = mb86a20s_writereg(state, 0x45, val | 0x10);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x45, val & 0x6f);
return rc;
}
static int mb86a20s_get_blk_error_layer_CNR(struct dvb_frontend *fe)
{
struct mb86a20s_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
u32 mer, cnr;
int rc, val, layer;
const struct linear_segments *segs;
unsigned segs_len;
dev_dbg(&state->i2c->dev, "%s called.\n", __func__);
rc = mb86a20s_writereg(state, 0x50, 0x5b);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x51);
if (rc < 0)
return rc;
if (!(rc & 0x01)) {
dev_dbg(&state->i2c->dev,
"%s: MER measures aren't available yet.\n", __func__);
return -EBUSY;
}
for (layer = 0; layer < NUM_LAYERS; layer++) {
if (!(c->isdbt_layer_enabled & (1 << layer))) {
c->cnr.stat[1 + layer].scale = FE_SCALE_NOT_AVAILABLE;
continue;
}
rc = mb86a20s_writereg(state, 0x50, 0x52 + layer * 3);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x51);
if (rc < 0)
return rc;
mer = rc << 16;
rc = mb86a20s_writereg(state, 0x50, 0x53 + layer * 3);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x51);
if (rc < 0)
return rc;
mer |= rc << 8;
rc = mb86a20s_writereg(state, 0x50, 0x54 + layer * 3);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x51);
if (rc < 0)
return rc;
mer |= rc;
switch (c->layer[layer].modulation) {
case DQPSK:
case QPSK:
segs = cnr_qpsk_table;
segs_len = ARRAY_SIZE(cnr_qpsk_table);
break;
case QAM_16:
segs = cnr_16qam_table;
segs_len = ARRAY_SIZE(cnr_16qam_table);
break;
default:
case QAM_64:
segs = cnr_64qam_table;
segs_len = ARRAY_SIZE(cnr_64qam_table);
break;
}
cnr = interpolate_value(mer, segs, segs_len);
c->cnr.stat[1 + layer].scale = FE_SCALE_DECIBEL;
c->cnr.stat[1 + layer].svalue = cnr;
dev_dbg(&state->i2c->dev,
"%s: CNR for layer %c is %d.%03d dB (MER = %d).\n",
__func__, 'A' + layer, cnr / 1000, cnr % 1000, mer);
}
rc = mb86a20s_writereg(state, 0x50, 0x50);
if (rc < 0)
return rc;
rc = mb86a20s_readreg(state, 0x51);
if (rc < 0)
return rc;
val = rc;
rc = mb86a20s_writereg(state, 0x51, val | 0x01);
if (rc < 0)
return rc;
rc = mb86a20s_writereg(state, 0x51, val & 0x06);
if (rc < 0)
return rc;
return 0;
}
static void mb86a20s_stats_not_ready(struct dvb_frontend *fe)
{
struct mb86a20s_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int layer;
dev_dbg(&state->i2c->dev, "%s called.\n", __func__);
c->strength.len = 1;
c->cnr.len = NUM_LAYERS + 1;
c->pre_bit_error.len = NUM_LAYERS + 1;
c->pre_bit_count.len = NUM_LAYERS + 1;
c->post_bit_error.len = NUM_LAYERS + 1;
c->post_bit_count.len = NUM_LAYERS + 1;
c->block_error.len = NUM_LAYERS + 1;
c->block_count.len = NUM_LAYERS + 1;
c->strength.stat[0].scale = FE_SCALE_RELATIVE;
c->strength.stat[0].uvalue = 0;
for (layer = 0; layer < NUM_LAYERS + 1; layer++) {
c->cnr.stat[layer].scale = FE_SCALE_NOT_AVAILABLE;
c->pre_bit_error.stat[layer].scale = FE_SCALE_NOT_AVAILABLE;
c->pre_bit_count.stat[layer].scale = FE_SCALE_NOT_AVAILABLE;
c->post_bit_error.stat[layer].scale = FE_SCALE_NOT_AVAILABLE;
c->post_bit_count.stat[layer].scale = FE_SCALE_NOT_AVAILABLE;
c->block_error.stat[layer].scale = FE_SCALE_NOT_AVAILABLE;
c->block_count.stat[layer].scale = FE_SCALE_NOT_AVAILABLE;
}
}
static int mb86a20s_get_stats(struct dvb_frontend *fe, int status_nr)
{
struct mb86a20s_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int rc = 0, layer;
u32 bit_error = 0, bit_count = 0;
u32 t_pre_bit_error = 0, t_pre_bit_count = 0;
u32 t_post_bit_error = 0, t_post_bit_count = 0;
u32 block_error = 0, block_count = 0;
u32 t_block_error = 0, t_block_count = 0;
int active_layers = 0, pre_ber_layers = 0, post_ber_layers = 0;
int per_layers = 0;
dev_dbg(&state->i2c->dev, "%s called.\n", __func__);
mb86a20s_get_main_CNR(fe);
mb86a20s_get_blk_error_layer_CNR(fe);
if (status_nr < 9)
return 0;
for (layer = 0; layer < NUM_LAYERS; layer++) {
if (c->isdbt_layer_enabled & (1 << layer)) {
active_layers++;
rc = mb86a20s_get_pre_ber(fe, layer,
&bit_error, &bit_count);
if (rc >= 0) {
c->pre_bit_error.stat[1 + layer].scale = FE_SCALE_COUNTER;
c->pre_bit_error.stat[1 + layer].uvalue += bit_error;
c->pre_bit_count.stat[1 + layer].scale = FE_SCALE_COUNTER;
c->pre_bit_count.stat[1 + layer].uvalue += bit_count;
} else if (rc != -EBUSY) {
c->pre_bit_error.stat[1 + layer].scale = FE_SCALE_NOT_AVAILABLE;
c->pre_bit_count.stat[1 + layer].scale = FE_SCALE_NOT_AVAILABLE;
dev_err(&state->i2c->dev,
"%s: Can't get BER for layer %c (error %d).\n",
__func__, 'A' + layer, rc);
}
if (c->block_error.stat[1 + layer].scale != FE_SCALE_NOT_AVAILABLE)
pre_ber_layers++;
rc = mb86a20s_get_post_ber(fe, layer,
&bit_error, &bit_count);
if (rc >= 0) {
c->post_bit_error.stat[1 + layer].scale = FE_SCALE_COUNTER;
c->post_bit_error.stat[1 + layer].uvalue += bit_error;
c->post_bit_count.stat[1 + layer].scale = FE_SCALE_COUNTER;
c->post_bit_count.stat[1 + layer].uvalue += bit_count;
} else if (rc != -EBUSY) {
c->post_bit_error.stat[1 + layer].scale = FE_SCALE_NOT_AVAILABLE;
c->post_bit_count.stat[1 + layer].scale = FE_SCALE_NOT_AVAILABLE;
dev_err(&state->i2c->dev,
"%s: Can't get BER for layer %c (error %d).\n",
__func__, 'A' + layer, rc);
}
if (c->block_error.stat[1 + layer].scale != FE_SCALE_NOT_AVAILABLE)
post_ber_layers++;
rc = mb86a20s_get_blk_error(fe, layer,
&block_error,
&block_count);
if (rc >= 0) {
c->block_error.stat[1 + layer].scale = FE_SCALE_COUNTER;
c->block_error.stat[1 + layer].uvalue += block_error;
c->block_count.stat[1 + layer].scale = FE_SCALE_COUNTER;
c->block_count.stat[1 + layer].uvalue += block_count;
} else if (rc != -EBUSY) {
c->block_error.stat[1 + layer].scale = FE_SCALE_NOT_AVAILABLE;
c->block_count.stat[1 + layer].scale = FE_SCALE_NOT_AVAILABLE;
dev_err(&state->i2c->dev,
"%s: Can't get PER for layer %c (error %d).\n",
__func__, 'A' + layer, rc);
}
if (c->block_error.stat[1 + layer].scale != FE_SCALE_NOT_AVAILABLE)
per_layers++;
t_pre_bit_error += c->pre_bit_error.stat[1 + layer].uvalue;
t_pre_bit_count += c->pre_bit_count.stat[1 + layer].uvalue;
t_post_bit_error += c->post_bit_error.stat[1 + layer].uvalue;
t_post_bit_count += c->post_bit_count.stat[1 + layer].uvalue;
t_block_error += c->block_error.stat[1 + layer].uvalue;
t_block_count += c->block_count.stat[1 + layer].uvalue;
}
}
if (pre_ber_layers) {
c->pre_bit_error.stat[0].scale = FE_SCALE_COUNTER;
c->pre_bit_error.stat[0].uvalue = t_pre_bit_error;
c->pre_bit_count.stat[0].scale = FE_SCALE_COUNTER;
c->pre_bit_count.stat[0].uvalue = t_pre_bit_count;
} else {
c->pre_bit_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->pre_bit_count.stat[0].scale = FE_SCALE_COUNTER;
}
if (post_ber_layers) {
c->post_bit_error.stat[0].scale = FE_SCALE_COUNTER;
c->post_bit_error.stat[0].uvalue = t_post_bit_error;
c->post_bit_count.stat[0].scale = FE_SCALE_COUNTER;
c->post_bit_count.stat[0].uvalue = t_post_bit_count;
} else {
c->post_bit_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->post_bit_count.stat[0].scale = FE_SCALE_COUNTER;
}
if (per_layers) {
c->block_error.stat[0].scale = FE_SCALE_COUNTER;
c->block_error.stat[0].uvalue = t_block_error;
c->block_count.stat[0].scale = FE_SCALE_COUNTER;
c->block_count.stat[0].uvalue = t_block_count;
} else {
c->block_error.stat[0].scale = FE_SCALE_NOT_AVAILABLE;
c->block_count.stat[0].scale = FE_SCALE_COUNTER;
}
return rc;
}
static int mb86a20s_initfe(struct dvb_frontend *fe)
{
struct mb86a20s_state *state = fe->demodulator_priv;
u64 pll;
u32 fclk;
int rc;
u8 regD5 = 1, reg71, reg09 = 0x3a;
dev_dbg(&state->i2c->dev, "%s called.\n", __func__);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
rc = mb86a20s_writeregdata(state, mb86a20s_init1);
if (rc < 0)
goto err;
if (!state->inversion)
reg09 |= 0x04;
rc = mb86a20s_writereg(state, 0x09, reg09);
if (rc < 0)
goto err;
if (!state->bw)
reg71 = 1;
else
reg71 = 0;
rc = mb86a20s_writereg(state, 0x39, reg71);
if (rc < 0)
goto err;
rc = mb86a20s_writereg(state, 0x71, state->bw);
if (rc < 0)
goto err;
if (state->subchannel) {
rc = mb86a20s_writereg(state, 0x44, state->subchannel);
if (rc < 0)
goto err;
}
fclk = state->config->fclk;
if (!fclk)
fclk = 32571428;
if (fe->ops.tuner_ops.get_if_frequency)
fe->ops.tuner_ops.get_if_frequency(fe, &state->if_freq);
if (!state->if_freq)
state->if_freq = 3300000;
pll = (((u64)1) << 34) * state->if_freq;
do_div(pll, 63 * fclk);
pll = (1 << 25) - pll;
rc = mb86a20s_writereg(state, 0x28, 0x2a);
if (rc < 0)
goto err;
rc = mb86a20s_writereg(state, 0x29, (pll >> 16) & 0xff);
if (rc < 0)
goto err;
rc = mb86a20s_writereg(state, 0x2a, (pll >> 8) & 0xff);
if (rc < 0)
goto err;
rc = mb86a20s_writereg(state, 0x2b, pll & 0xff);
if (rc < 0)
goto err;
dev_dbg(&state->i2c->dev, "%s: fclk=%d, IF=%d, clock reg=0x%06llx\n",
__func__, fclk, state->if_freq, (long long)pll);
pll = state->if_freq * 1677721600L;
do_div(pll, 1628571429L);
rc = mb86a20s_writereg(state, 0x28, 0x20);
if (rc < 0)
goto err;
rc = mb86a20s_writereg(state, 0x29, (pll >> 16) & 0xff);
if (rc < 0)
goto err;
rc = mb86a20s_writereg(state, 0x2a, (pll >> 8) & 0xff);
if (rc < 0)
goto err;
rc = mb86a20s_writereg(state, 0x2b, pll & 0xff);
if (rc < 0)
goto err;
dev_dbg(&state->i2c->dev, "%s: IF=%d, IF reg=0x%06llx\n",
__func__, state->if_freq, (long long)pll);
if (!state->config->is_serial)
regD5 &= ~1;
rc = mb86a20s_writereg(state, 0x50, 0xd5);
if (rc < 0)
goto err;
rc = mb86a20s_writereg(state, 0x51, regD5);
if (rc < 0)
goto err;
rc = mb86a20s_writeregdata(state, mb86a20s_init2);
if (rc < 0)
goto err;
err:
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (rc < 0) {
state->need_init = true;
dev_info(&state->i2c->dev,
"mb86a20s: Init failed. Will try again later\n");
} else {
state->need_init = false;
dev_dbg(&state->i2c->dev, "Initialization succeeded.\n");
}
return rc;
}
static int mb86a20s_set_frontend(struct dvb_frontend *fe)
{
struct mb86a20s_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int rc, if_freq;
dev_dbg(&state->i2c->dev, "%s called.\n", __func__);
if (!c->isdbt_layer_enabled)
c->isdbt_layer_enabled = 7;
if (c->isdbt_layer_enabled == 1)
state->bw = MB86A20S_1SEG;
else if (c->isdbt_partial_reception)
state->bw = MB86A20S_13SEG_PARTIAL;
else
state->bw = MB86A20S_13SEG;
if (c->inversion == INVERSION_ON)
state->inversion = true;
else
state->inversion = false;
if (!c->isdbt_sb_mode) {
state->subchannel = 0;
} else {
if (c->isdbt_sb_subchannel >= ARRAY_SIZE(mb86a20s_subchannel))
c->isdbt_sb_subchannel = 0;
state->subchannel = mb86a20s_subchannel[c->isdbt_sb_subchannel];
}
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
fe->ops.tuner_ops.set_params(fe);
if (fe->ops.tuner_ops.get_if_frequency)
fe->ops.tuner_ops.get_if_frequency(fe, &if_freq);
mb86a20s_initfe(fe);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
rc = mb86a20s_writeregdata(state, mb86a20s_reset_reception);
mb86a20s_reset_counters(fe);
mb86a20s_stats_not_ready(fe);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
return rc;
}
static int mb86a20s_read_status_and_stats(struct dvb_frontend *fe,
enum fe_status *status)
{
struct mb86a20s_state *state = fe->demodulator_priv;
int rc, status_nr;
dev_dbg(&state->i2c->dev, "%s called.\n", __func__);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
status_nr = mb86a20s_read_status(fe, status);
if (status_nr < 7) {
mb86a20s_stats_not_ready(fe);
mb86a20s_reset_frontend_cache(fe);
}
if (status_nr < 0) {
dev_err(&state->i2c->dev,
"%s: Can't read frontend lock status\n", __func__);
rc = status_nr;
goto error;
}
rc = mb86a20s_read_signal_strength(fe);
if (rc < 0) {
dev_err(&state->i2c->dev,
"%s: Can't reset VBER registers.\n", __func__);
mb86a20s_stats_not_ready(fe);
mb86a20s_reset_frontend_cache(fe);
rc = 0;
goto error;
}
if (status_nr >= 7) {
rc = mb86a20s_get_frontend(fe);
if (rc < 0) {
dev_err(&state->i2c->dev,
"%s: Can't get FE TMCC data.\n", __func__);
rc = 0;
goto error;
}
rc = mb86a20s_get_stats(fe, status_nr);
if (rc < 0 && rc != -EBUSY) {
dev_err(&state->i2c->dev,
"%s: Can't get FE statistics.\n", __func__);
rc = 0;
goto error;
}
rc = 0;
}
goto ok;
error:
mb86a20s_stats_not_ready(fe);
ok:
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
return rc;
}
static int mb86a20s_read_signal_strength_from_cache(struct dvb_frontend *fe,
u16 *strength)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
*strength = c->strength.stat[0].uvalue;
return 0;
}
static int mb86a20s_tune(struct dvb_frontend *fe,
bool re_tune,
unsigned int mode_flags,
unsigned int *delay,
enum fe_status *status)
{
struct mb86a20s_state *state = fe->demodulator_priv;
int rc = 0;
dev_dbg(&state->i2c->dev, "%s called.\n", __func__);
if (re_tune)
rc = mb86a20s_set_frontend(fe);
if (!(mode_flags & FE_TUNE_MODE_ONESHOT))
mb86a20s_read_status_and_stats(fe, status);
return rc;
}
static void mb86a20s_release(struct dvb_frontend *fe)
{
struct mb86a20s_state *state = fe->demodulator_priv;
dev_dbg(&state->i2c->dev, "%s called.\n", __func__);
kfree(state);
}
static int mb86a20s_get_frontend_algo(struct dvb_frontend *fe)
{
return DVBFE_ALGO_HW;
}
struct dvb_frontend *mb86a20s_attach(const struct mb86a20s_config *config,
struct i2c_adapter *i2c)
{
struct mb86a20s_state *state;
u8 rev;
dev_dbg(&i2c->dev, "%s called.\n", __func__);
state = kzalloc(sizeof(struct mb86a20s_state), GFP_KERNEL);
if (state == NULL) {
dev_err(&i2c->dev,
"%s: unable to allocate memory for state\n", __func__);
goto error;
}
state->config = config;
state->i2c = i2c;
memcpy(&state->frontend.ops, &mb86a20s_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
rev = mb86a20s_readreg(state, 0);
if (rev == 0x13) {
dev_info(&i2c->dev,
"Detected a Fujitsu mb86a20s frontend\n");
} else {
dev_dbg(&i2c->dev,
"Frontend revision %d is unknown - aborting.\n",
rev);
goto error;
}
return &state->frontend;
error:
kfree(state);
return NULL;
}
