static int lgdt3306a_write_reg(struct lgdt3306a_state *state, u16 reg, u8 val)
{
int ret;
u8 buf[] = { reg >> 8, reg & 0xff, val };
struct i2c_msg msg = {
.addr = state->cfg->i2c_addr, .flags = 0,
.buf = buf, .len = 3,
};
dbg_reg("reg: 0x%04x, val: 0x%02x\n", reg, val);
ret = i2c_transfer(state->i2c_adap, &msg, 1);
if (ret != 1) {
pr_err("error (addr %02x %02x <- %02x, err = %i)\n",
msg.buf[0], msg.buf[1], msg.buf[2], ret);
if (ret < 0)
return ret;
else
return -EREMOTEIO;
}
return 0;
}
static int lgdt3306a_read_reg(struct lgdt3306a_state *state, u16 reg, u8 *val)
{
int ret;
u8 reg_buf[] = { reg >> 8, reg & 0xff };
struct i2c_msg msg[] = {
{ .addr = state->cfg->i2c_addr,
.flags = 0, .buf = reg_buf, .len = 2 },
{ .addr = state->cfg->i2c_addr,
.flags = I2C_M_RD, .buf = val, .len = 1 },
};
ret = i2c_transfer(state->i2c_adap, msg, 2);
if (ret != 2) {
pr_err("error (addr %02x reg %04x error (ret == %i)\n",
state->cfg->i2c_addr, reg, ret);
if (ret < 0)
return ret;
else
return -EREMOTEIO;
}
dbg_reg("reg: 0x%04x, val: 0x%02x\n", reg, *val);
return 0;
}
static int lgdt3306a_set_reg_bit(struct lgdt3306a_state *state,
u16 reg, int bit, int onoff)
{
u8 val;
int ret;
dbg_reg("reg: 0x%04x, bit: %d, level: %d\n", reg, bit, onoff);
ret = lgdt3306a_read_reg(state, reg, &val);
if (lg_chkerr(ret))
goto fail;
val &= ~(1 << bit);
val |= (onoff & 1) << bit;
ret = lgdt3306a_write_reg(state, reg, val);
lg_chkerr(ret);
fail:
return ret;
}
static int lgdt3306a_soft_reset(struct lgdt3306a_state *state)
{
int ret;
dbg_info("\n");
ret = lgdt3306a_set_reg_bit(state, 0x0000, 7, 0);
if (lg_chkerr(ret))
goto fail;
msleep(20);
ret = lgdt3306a_set_reg_bit(state, 0x0000, 7, 1);
lg_chkerr(ret);
fail:
return ret;
}
static int lgdt3306a_mpeg_mode(struct lgdt3306a_state *state,
enum lgdt3306a_mpeg_mode mode)
{
u8 val;
int ret;
dbg_info("(%d)\n", mode);
ret = lgdt3306a_set_reg_bit(state, 0x0071, 7,
mode == LGDT3306A_MPEG_PARALLEL ? 1 : 0);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_set_reg_bit(state, 0x0071, 6, 0);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_read_reg(state, 0x0070, &val);
if (lg_chkerr(ret))
goto fail;
val |= 0x10;
if (mode == LGDT3306A_MPEG_PARALLEL)
val &= ~0x10;
ret = lgdt3306a_write_reg(state, 0x0070, val);
lg_chkerr(ret);
fail:
return ret;
}
static int lgdt3306a_mpeg_mode_polarity(struct lgdt3306a_state *state,
enum lgdt3306a_tp_clock_edge edge,
enum lgdt3306a_tp_valid_polarity valid)
{
u8 val;
int ret;
dbg_info("edge=%d, valid=%d\n", edge, valid);
ret = lgdt3306a_read_reg(state, 0x0070, &val);
if (lg_chkerr(ret))
goto fail;
val &= ~0x06;
if (edge == LGDT3306A_TPCLK_RISING_EDGE)
val |= 0x04;
if (valid == LGDT3306A_TP_VALID_HIGH)
val |= 0x02;
ret = lgdt3306a_write_reg(state, 0x0070, val);
lg_chkerr(ret);
fail:
return ret;
}
static int lgdt3306a_mpeg_tristate(struct lgdt3306a_state *state,
int mode)
{
u8 val;
int ret;
dbg_info("(%d)\n", mode);
if (mode) {
ret = lgdt3306a_read_reg(state, 0x0070, &val);
if (lg_chkerr(ret))
goto fail;
val &= ~0xa8;
ret = lgdt3306a_write_reg(state, 0x0070, val);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_set_reg_bit(state, 0x0003, 6, 1);
if (lg_chkerr(ret))
goto fail;
} else {
ret = lgdt3306a_set_reg_bit(state, 0x0003, 6, 0);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_read_reg(state, 0x0070, &val);
if (lg_chkerr(ret))
goto fail;
val |= 0xa8;
ret = lgdt3306a_write_reg(state, 0x0070, val);
if (lg_chkerr(ret))
goto fail;
}
fail:
return ret;
}
static int lgdt3306a_ts_bus_ctrl(struct dvb_frontend *fe, int acquire)
{
struct lgdt3306a_state *state = fe->demodulator_priv;
dbg_info("acquire=%d\n", acquire);
return lgdt3306a_mpeg_tristate(state, acquire ? 0 : 1);
}
static int lgdt3306a_power(struct lgdt3306a_state *state,
int mode)
{
int ret;
dbg_info("(%d)\n", mode);
if (mode == 0) {
ret = lgdt3306a_set_reg_bit(state, 0x0000, 7, 0);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_set_reg_bit(state, 0x0000, 0, 0);
if (lg_chkerr(ret))
goto fail;
} else {
ret = lgdt3306a_set_reg_bit(state, 0x0000, 7, 1);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_set_reg_bit(state, 0x0000, 0, 1);
if (lg_chkerr(ret))
goto fail;
}
#ifdef DBG_DUMP
lgdt3306a_DumpAllRegs(state);
#endif
fail:
return ret;
}
static int lgdt3306a_set_vsb(struct lgdt3306a_state *state)
{
u8 val;
int ret;
dbg_info("\n");
ret = lgdt3306a_read_reg(state, 0x0002, &val);
val &= 0xf7;
val |= 0x04;
ret = lgdt3306a_write_reg(state, 0x0002, val);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_write_reg(state, 0x0008, 0x80);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_read_reg(state, 0x0009, &val);
val &= 0xe3;
val |= 0x0c;
ret = lgdt3306a_write_reg(state, 0x0009, val);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_read_reg(state, 0x0009, &val);
val &= 0xfc;
ret = lgdt3306a_write_reg(state, 0x0009, val);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_read_reg(state, 0x000d, &val);
val &= 0xbf;
ret = lgdt3306a_write_reg(state, 0x000d, val);
if (lg_chkerr(ret))
goto fail;
#if 0
ret = lgdt3306a_write_reg(state, 0x0024, 0x00);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_write_reg(state, 0x002e, 0x00);
ret = lgdt3306a_write_reg(state, 0x002f, 0x00);
ret = lgdt3306a_write_reg(state, 0x0030, 0x00);
ret = lgdt3306a_write_reg(state, 0x002b, 0x00);
ret = lgdt3306a_write_reg(state, 0x002c, 0x00);
ret = lgdt3306a_write_reg(state, 0x002d, 0x00);
ret = lgdt3306a_write_reg(state, 0x0028, 0x00);
ret = lgdt3306a_write_reg(state, 0x0029, 0x00);
ret = lgdt3306a_write_reg(state, 0x002a, 0x00);
ret = lgdt3306a_write_reg(state, 0x0025, 0x00);
ret = lgdt3306a_write_reg(state, 0x0026, 0x00);
ret = lgdt3306a_write_reg(state, 0x0027, 0x00);
#else
ret = lgdt3306a_write_reg(state, 0x0024, 0x5A);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_write_reg(state, 0x002e, 0x5A);
ret = lgdt3306a_write_reg(state, 0x002f, 0x00);
ret = lgdt3306a_write_reg(state, 0x0030, 0x00);
ret = lgdt3306a_write_reg(state, 0x002b, 0x36);
ret = lgdt3306a_write_reg(state, 0x002c, 0x00);
ret = lgdt3306a_write_reg(state, 0x002d, 0x00);
ret = lgdt3306a_write_reg(state, 0x0028, 0x2A);
ret = lgdt3306a_write_reg(state, 0x0029, 0x00);
ret = lgdt3306a_write_reg(state, 0x002a, 0x00);
ret = lgdt3306a_write_reg(state, 0x0025, 0x06);
ret = lgdt3306a_write_reg(state, 0x0026, 0x00);
ret = lgdt3306a_write_reg(state, 0x0027, 0x00);
#endif
ret = lgdt3306a_read_reg(state, 0x001e, &val);
val &= 0x0f;
val |= 0xa0;
ret = lgdt3306a_write_reg(state, 0x001e, val);
ret = lgdt3306a_write_reg(state, 0x0022, 0x08);
ret = lgdt3306a_write_reg(state, 0x0023, 0xFF);
ret = lgdt3306a_read_reg(state, 0x211f, &val);
val &= 0xef;
ret = lgdt3306a_write_reg(state, 0x211f, val);
ret = lgdt3306a_write_reg(state, 0x2173, 0x01);
ret = lgdt3306a_read_reg(state, 0x1061, &val);
val &= 0xf8;
val |= 0x04;
ret = lgdt3306a_write_reg(state, 0x1061, val);
ret = lgdt3306a_read_reg(state, 0x103d, &val);
val &= 0xcf;
ret = lgdt3306a_write_reg(state, 0x103d, val);
ret = lgdt3306a_write_reg(state, 0x2122, 0x40);
ret = lgdt3306a_read_reg(state, 0x2141, &val);
val &= 0x3f;
ret = lgdt3306a_write_reg(state, 0x2141, val);
ret = lgdt3306a_read_reg(state, 0x2135, &val);
val &= 0x0f;
val |= 0x70;
ret = lgdt3306a_write_reg(state, 0x2135, val);
ret = lgdt3306a_read_reg(state, 0x0003, &val);
val &= 0xf7;
ret = lgdt3306a_write_reg(state, 0x0003, val);
ret = lgdt3306a_read_reg(state, 0x001c, &val);
val &= 0x7f;
ret = lgdt3306a_write_reg(state, 0x001c, val);
ret = lgdt3306a_read_reg(state, 0x2179, &val);
val &= 0xf8;
ret = lgdt3306a_write_reg(state, 0x2179, val);
ret = lgdt3306a_read_reg(state, 0x217a, &val);
val &= 0xf8;
ret = lgdt3306a_write_reg(state, 0x217a, val);
ret = lgdt3306a_soft_reset(state);
if (lg_chkerr(ret))
goto fail;
dbg_info("complete\n");
fail:
return ret;
}
static int lgdt3306a_set_qam(struct lgdt3306a_state *state, int modulation)
{
u8 val;
int ret;
dbg_info("modulation=%d\n", modulation);
ret = lgdt3306a_write_reg(state, 0x0008, 0x08);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_read_reg(state, 0x0002, &val);
val &= 0xfb;
val |= 0x08;
ret = lgdt3306a_write_reg(state, 0x0002, val);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_read_reg(state, 0x0009, &val);
val &= 0xe3;
ret = lgdt3306a_write_reg(state, 0x0009, val);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_read_reg(state, 0x0009, &val);
val &= 0xfc;
val |= 0x02;
ret = lgdt3306a_write_reg(state, 0x0009, val);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_read_reg(state, 0x101a, &val);
val &= 0xf8;
if (modulation == QAM_64)
val |= 0x02;
else
val |= 0x04;
ret = lgdt3306a_write_reg(state, 0x101a, val);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_read_reg(state, 0x000d, &val);
val &= 0xbf;
val |= 0x40;
ret = lgdt3306a_write_reg(state, 0x000d, val);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_read_reg(state, 0x0024, &val);
val &= 0x00;
ret = lgdt3306a_write_reg(state, 0x0024, val);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_soft_reset(state);
if (lg_chkerr(ret))
goto fail;
dbg_info("complete\n");
fail:
return ret;
}
static int lgdt3306a_set_modulation(struct lgdt3306a_state *state,
struct dtv_frontend_properties *p)
{
int ret;
dbg_info("\n");
switch (p->modulation) {
case VSB_8:
ret = lgdt3306a_set_vsb(state);
break;
case QAM_64:
ret = lgdt3306a_set_qam(state, QAM_64);
break;
case QAM_256:
ret = lgdt3306a_set_qam(state, QAM_256);
break;
default:
return -EINVAL;
}
if (lg_chkerr(ret))
goto fail;
state->current_modulation = p->modulation;
fail:
return ret;
}
static int lgdt3306a_agc_setup(struct lgdt3306a_state *state,
struct dtv_frontend_properties *p)
{
dbg_info("\n");
switch (p->modulation) {
case VSB_8:
break;
case QAM_64:
case QAM_256:
break;
default:
return -EINVAL;
}
return 0;
}
static int lgdt3306a_set_inversion(struct lgdt3306a_state *state,
int inversion)
{
int ret;
dbg_info("(%d)\n", inversion);
ret = lgdt3306a_set_reg_bit(state, 0x0002, 2, inversion ? 1 : 0);
return ret;
}
static int lgdt3306a_set_inversion_auto(struct lgdt3306a_state *state,
int enabled)
{
int ret;
dbg_info("(%d)\n", enabled);
ret = lgdt3306a_set_reg_bit(state, 0x0002, 3, enabled);
return ret;
}
static int lgdt3306a_spectral_inversion(struct lgdt3306a_state *state,
struct dtv_frontend_properties *p,
int inversion)
{
int ret = 0;
dbg_info("(%d)\n", inversion);
#if 0
ret = lgdt3306a_set_inversion(state, inversion);
switch (p->modulation) {
case VSB_8:
ret = lgdt3306a_set_inversion_auto(state, 0);
break;
case QAM_64:
case QAM_256:
ret = lgdt3306a_set_inversion_auto(state, 1);
break;
default:
ret = -EINVAL;
}
#endif
return ret;
}
static int lgdt3306a_set_if(struct lgdt3306a_state *state,
struct dtv_frontend_properties *p)
{
int ret;
u16 if_freq_khz;
u8 nco1, nco2;
switch (p->modulation) {
case VSB_8:
if_freq_khz = state->cfg->vsb_if_khz;
break;
case QAM_64:
case QAM_256:
if_freq_khz = state->cfg->qam_if_khz;
break;
default:
return -EINVAL;
}
switch (if_freq_khz) {
default:
pr_warn("IF=%d KHz is not supported, 3250 assumed\n",
if_freq_khz);
case 3250:
nco1 = 0x34;
nco2 = 0x00;
break;
case 3500:
nco1 = 0x38;
nco2 = 0x00;
break;
case 4000:
nco1 = 0x40;
nco2 = 0x00;
break;
case 5000:
nco1 = 0x50;
nco2 = 0x00;
break;
case 5380:
nco1 = 0x56;
nco2 = 0x14;
break;
}
ret = lgdt3306a_write_reg(state, 0x0010, nco1);
if (ret)
return ret;
ret = lgdt3306a_write_reg(state, 0x0011, nco2);
if (ret)
return ret;
dbg_info("if_freq=%d KHz->[%04x]\n", if_freq_khz, nco1<<8 | nco2);
return 0;
}
static int lgdt3306a_i2c_gate_ctrl(struct dvb_frontend *fe, int enable)
{
struct lgdt3306a_state *state = fe->demodulator_priv;
if (state->cfg->deny_i2c_rptr) {
dbg_info("deny_i2c_rptr=%d\n", state->cfg->deny_i2c_rptr);
return 0;
}
dbg_info("(%d)\n", enable);
return lgdt3306a_set_reg_bit(state, 0x0002, 7, enable ? 0 : 1);
}
static int lgdt3306a_sleep(struct lgdt3306a_state *state)
{
int ret;
dbg_info("\n");
state->current_frequency = -1;
ret = lgdt3306a_mpeg_tristate(state, 1);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_power(state, 0);
lg_chkerr(ret);
fail:
return 0;
}
static int lgdt3306a_fe_sleep(struct dvb_frontend *fe)
{
struct lgdt3306a_state *state = fe->demodulator_priv;
return lgdt3306a_sleep(state);
}
static int lgdt3306a_init(struct dvb_frontend *fe)
{
struct lgdt3306a_state *state = fe->demodulator_priv;
u8 val;
int ret;
dbg_info("\n");
ret = lgdt3306a_set_reg_bit(state, 0x0001, 0, 1);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_set_inversion_auto(state, 0);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_set_inversion(state, 1);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_set_reg_bit(state, 0x0004, 7, 1);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_set_reg_bit(state, 0x0004, 2, 0);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_set_reg_bit(state, 0x0004, 3, 0);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_set_reg_bit(state, 0x0005, 6, 0);
if (lg_chkerr(ret))
goto fail;
if (state->cfg->xtalMHz == 24) {
ret = lgdt3306a_read_reg(state, 0x0005, &val);
if (lg_chkerr(ret))
goto fail;
val &= 0xc0;
val |= 0x25;
ret = lgdt3306a_write_reg(state, 0x0005, val);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_write_reg(state, 0x0006, 0x64);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_read_reg(state, 0x000d, &val);
if (lg_chkerr(ret))
goto fail;
val &= 0xc0;
val |= 0x18;
ret = lgdt3306a_write_reg(state, 0x000d, val);
if (lg_chkerr(ret))
goto fail;
} else if (state->cfg->xtalMHz == 25) {
ret = lgdt3306a_read_reg(state, 0x0005, &val);
if (lg_chkerr(ret))
goto fail;
val &= 0xc0;
val |= 0x25;
ret = lgdt3306a_write_reg(state, 0x0005, val);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_write_reg(state, 0x0006, 0x64);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_read_reg(state, 0x000d, &val);
if (lg_chkerr(ret))
goto fail;
val &= 0xc0;
val |= 0x19;
ret = lgdt3306a_write_reg(state, 0x000d, val);
if (lg_chkerr(ret))
goto fail;
} else {
pr_err("Bad xtalMHz=%d\n", state->cfg->xtalMHz);
}
#if 0
ret = lgdt3306a_write_reg(state, 0x000e, 0x00);
ret = lgdt3306a_write_reg(state, 0x000f, 0x00);
#endif
ret = lgdt3306a_write_reg(state, 0x0010, 0x34);
ret = lgdt3306a_write_reg(state, 0x0011, 0x00);
ret = lgdt3306a_write_reg(state, 0x0014, 0);
ret = lgdt3306a_read_reg(state, 0x103c, &val);
val &= 0x0f;
val |= 0x20;
ret = lgdt3306a_write_reg(state, 0x103c, val);
ret = lgdt3306a_read_reg(state, 0x103d, &val);
val &= 0xfc;
val |= 0x03;
ret = lgdt3306a_write_reg(state, 0x103d, val);
ret = lgdt3306a_read_reg(state, 0x1036, &val);
val &= 0xf0;
val |= 0x0c;
ret = lgdt3306a_write_reg(state, 0x1036, val);
ret = lgdt3306a_read_reg(state, 0x211f, &val);
val &= 0xef;
ret = lgdt3306a_write_reg(state, 0x211f, val);
ret = lgdt3306a_read_reg(state, 0x2849, &val);
val &= 0xef;
ret = lgdt3306a_write_reg(state, 0x2849, val);
ret = lgdt3306a_set_vsb(state);
ret = lgdt3306a_mpeg_mode(state, state->cfg->mpeg_mode);
ret = lgdt3306a_mpeg_tristate(state, 1);
ret = lgdt3306a_sleep(state);
lg_chkerr(ret);
fail:
return ret;
}
static int lgdt3306a_set_parameters(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct lgdt3306a_state *state = fe->demodulator_priv;
int ret;
dbg_info("(%d, %d)\n", p->frequency, p->modulation);
if (state->current_frequency == p->frequency &&
state->current_modulation == p->modulation) {
dbg_info(" (already set, skipping ...)\n");
return 0;
}
state->current_frequency = -1;
state->current_modulation = -1;
ret = lgdt3306a_power(state, 1);
if (lg_chkerr(ret))
goto fail;
if (fe->ops.tuner_ops.set_params) {
ret = fe->ops.tuner_ops.set_params(fe);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
#if 0
if (lg_chkerr(ret))
goto fail;
state->current_frequency = p->frequency;
#endif
}
ret = lgdt3306a_set_modulation(state, p);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_agc_setup(state, p);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_set_if(state, p);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_spectral_inversion(state, p,
state->cfg->spectral_inversion ? 1 : 0);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_mpeg_mode(state, state->cfg->mpeg_mode);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_mpeg_mode_polarity(state,
state->cfg->tpclk_edge,
state->cfg->tpvalid_polarity);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_mpeg_tristate(state, 0);
if (lg_chkerr(ret))
goto fail;
ret = lgdt3306a_soft_reset(state);
if (lg_chkerr(ret))
goto fail;
#ifdef DBG_DUMP
lgdt3306a_DumpAllRegs(state);
#endif
state->current_frequency = p->frequency;
fail:
return ret;
}
static int lgdt3306a_get_frontend(struct dvb_frontend *fe,
struct dtv_frontend_properties *p)
{
struct lgdt3306a_state *state = fe->demodulator_priv;
dbg_info("(%u, %d)\n",
state->current_frequency, state->current_modulation);
p->modulation = state->current_modulation;
p->frequency = state->current_frequency;
return 0;
}
static enum dvbfe_algo lgdt3306a_get_frontend_algo(struct dvb_frontend *fe)
{
#if 1
return DVBFE_ALGO_CUSTOM;
#else
return DVBFE_ALGO_HW;
#endif
}
static int lgdt3306a_monitor_vsb(struct lgdt3306a_state *state)
{
u8 val;
int ret;
u8 snrRef, maxPowerMan, nCombDet;
u16 fbDlyCir;
ret = lgdt3306a_read_reg(state, 0x21a1, &val);
if (ret)
return ret;
snrRef = val & 0x3f;
ret = lgdt3306a_read_reg(state, 0x2185, &maxPowerMan);
if (ret)
return ret;
ret = lgdt3306a_read_reg(state, 0x2191, &val);
if (ret)
return ret;
nCombDet = (val & 0x80) >> 7;
ret = lgdt3306a_read_reg(state, 0x2180, &val);
if (ret)
return ret;
fbDlyCir = (val & 0x03) << 8;
ret = lgdt3306a_read_reg(state, 0x2181, &val);
if (ret)
return ret;
fbDlyCir |= val;
dbg_info("snrRef=%d maxPowerMan=0x%x nCombDet=%d fbDlyCir=0x%x\n",
snrRef, maxPowerMan, nCombDet, fbDlyCir);
ret = lgdt3306a_read_reg(state, 0x1061, &val);
if (ret)
return ret;
val &= 0xf8;
if ((snrRef > 18) && (maxPowerMan > 0x68)
&& (nCombDet == 0x01)
&& ((fbDlyCir == 0x03FF) || (fbDlyCir < 0x6C))) {
val |= 0x00;
} else {
val |= 0x04;
}
ret = lgdt3306a_write_reg(state, 0x1061, val);
if (ret)
return ret;
ret = lgdt3306a_read_reg(state, 0x0024, &val);
if (ret)
return ret;
val &= 0x0f;
if (nCombDet == 0) {
val |= 0x50;
}
ret = lgdt3306a_write_reg(state, 0x0024, val);
if (ret)
return ret;
ret = lgdt3306a_read_reg(state, 0x103d, &val);
if (ret)
return ret;
val &= 0xcf;
val |= 0x20;
ret = lgdt3306a_write_reg(state, 0x103d, val);
return ret;
}
static enum lgdt3306a_modulation
lgdt3306a_check_oper_mode(struct lgdt3306a_state *state)
{
u8 val = 0;
int ret;
ret = lgdt3306a_read_reg(state, 0x0081, &val);
if (ret)
goto err;
if (val & 0x80) {
dbg_info("VSB\n");
return LG3306_VSB;
}
if (val & 0x08) {
ret = lgdt3306a_read_reg(state, 0x00a6, &val);
if (ret)
goto err;
val = val >> 2;
if (val & 0x01) {
dbg_info("QAM256\n");
return LG3306_QAM256;
}
dbg_info("QAM64\n");
return LG3306_QAM64;
}
err:
pr_warn("UNKNOWN\n");
return LG3306_UNKNOWN_MODE;
}
static enum lgdt3306a_lock_status
lgdt3306a_check_lock_status(struct lgdt3306a_state *state,
enum lgdt3306a_lock_check whatLock)
{
u8 val = 0;
int ret;
enum lgdt3306a_modulation modeOper;
enum lgdt3306a_lock_status lockStatus;
modeOper = LG3306_UNKNOWN_MODE;
switch (whatLock) {
case LG3306_SYNC_LOCK:
{
ret = lgdt3306a_read_reg(state, 0x00a6, &val);
if (ret)
return ret;
if ((val & 0x80) == 0x80)
lockStatus = LG3306_LOCK;
else
lockStatus = LG3306_UNLOCK;
dbg_info("SYNC_LOCK=%x\n", lockStatus);
break;
}
case LG3306_AGC_LOCK:
{
ret = lgdt3306a_read_reg(state, 0x0080, &val);
if (ret)
return ret;
if ((val & 0x40) == 0x40)
lockStatus = LG3306_LOCK;
else
lockStatus = LG3306_UNLOCK;
dbg_info("AGC_LOCK=%x\n", lockStatus);
break;
}
case LG3306_TR_LOCK:
{
modeOper = lgdt3306a_check_oper_mode(state);
if ((modeOper == LG3306_QAM64) || (modeOper == LG3306_QAM256)) {
ret = lgdt3306a_read_reg(state, 0x1094, &val);
if (ret)
return ret;
if ((val & 0x80) == 0x80)
lockStatus = LG3306_LOCK;
else
lockStatus = LG3306_UNLOCK;
} else
lockStatus = LG3306_UNKNOWN_LOCK;
dbg_info("TR_LOCK=%x\n", lockStatus);
break;
}
case LG3306_FEC_LOCK:
{
modeOper = lgdt3306a_check_oper_mode(state);
if ((modeOper == LG3306_QAM64) || (modeOper == LG3306_QAM256)) {
ret = lgdt3306a_read_reg(state, 0x0080, &val);
if (ret)
return ret;
if ((val & 0x10) == 0x10)
lockStatus = LG3306_LOCK;
else
lockStatus = LG3306_UNLOCK;
} else
lockStatus = LG3306_UNKNOWN_LOCK;
dbg_info("FEC_LOCK=%x\n", lockStatus);
break;
}
default:
lockStatus = LG3306_UNKNOWN_LOCK;
pr_warn("UNKNOWN whatLock=%d\n", whatLock);
break;
}
return lockStatus;
}
static enum lgdt3306a_neverlock_status
lgdt3306a_check_neverlock_status(struct lgdt3306a_state *state)
{
u8 val = 0;
int ret;
enum lgdt3306a_neverlock_status lockStatus;
ret = lgdt3306a_read_reg(state, 0x0080, &val);
if (ret)
return ret;
lockStatus = (enum lgdt3306a_neverlock_status)(val & 0x03);
dbg_info("NeverLock=%d", lockStatus);
return lockStatus;
}
static int lgdt3306a_pre_monitoring(struct lgdt3306a_state *state)
{
u8 val = 0;
int ret;
u8 currChDiffACQ, snrRef, mainStrong, aiccrejStatus;
ret = lgdt3306a_read_reg(state, 0x21bc, &currChDiffACQ);
if (ret)
return ret;
ret = lgdt3306a_read_reg(state, 0x21a1, &val);
if (ret)
return ret;
snrRef = val & 0x3f;
ret = lgdt3306a_read_reg(state, 0x2199, &val);
if (ret)
return ret;
mainStrong = (val & 0x40) >> 6;
ret = lgdt3306a_read_reg(state, 0x0090, &val);
if (ret)
return ret;
aiccrejStatus = (val & 0xf0) >> 4;
dbg_info("snrRef=%d mainStrong=%d aiccrejStatus=%d currChDiffACQ=0x%x\n",
snrRef, mainStrong, aiccrejStatus, currChDiffACQ);
#if 0
if ((mainStrong == 0) && (currChDiffACQ > 0x70))
#endif
if (mainStrong == 0) {
ret = lgdt3306a_read_reg(state, 0x2135, &val);
if (ret)
return ret;
val &= 0x0f;
val |= 0xa0;
ret = lgdt3306a_write_reg(state, 0x2135, val);
if (ret)
return ret;
ret = lgdt3306a_read_reg(state, 0x2141, &val);
if (ret)
return ret;
val &= 0x3f;
val |= 0x80;
ret = lgdt3306a_write_reg(state, 0x2141, val);
if (ret)
return ret;
ret = lgdt3306a_write_reg(state, 0x2122, 0x70);
if (ret)
return ret;
} else {
ret = lgdt3306a_read_reg(state, 0x2135, &val);
if (ret)
return ret;
val &= 0x0f;
val |= 0x70;
ret = lgdt3306a_write_reg(state, 0x2135, val);
if (ret)
return ret;
ret = lgdt3306a_read_reg(state, 0x2141, &val);
if (ret)
return ret;
val &= 0x3f;
val |= 0x40;
ret = lgdt3306a_write_reg(state, 0x2141, val);
if (ret)
return ret;
ret = lgdt3306a_write_reg(state, 0x2122, 0x40);
if (ret)
return ret;
}
return 0;
}
static enum lgdt3306a_lock_status
lgdt3306a_sync_lock_poll(struct lgdt3306a_state *state)
{
enum lgdt3306a_lock_status syncLockStatus = LG3306_UNLOCK;
int i;
for (i = 0; i < 2; i++) {
msleep(30);
syncLockStatus = lgdt3306a_check_lock_status(state,
LG3306_SYNC_LOCK);
if (syncLockStatus == LG3306_LOCK) {
dbg_info("locked(%d)\n", i);
return LG3306_LOCK;
}
}
dbg_info("not locked\n");
return LG3306_UNLOCK;
}
static enum lgdt3306a_lock_status
lgdt3306a_fec_lock_poll(struct lgdt3306a_state *state)
{
enum lgdt3306a_lock_status FECLockStatus = LG3306_UNLOCK;
int i;
for (i = 0; i < 2; i++) {
msleep(30);
FECLockStatus = lgdt3306a_check_lock_status(state,
LG3306_FEC_LOCK);
if (FECLockStatus == LG3306_LOCK) {
dbg_info("locked(%d)\n", i);
return FECLockStatus;
}
}
dbg_info("not locked\n");
return FECLockStatus;
}
static enum lgdt3306a_neverlock_status
lgdt3306a_neverlock_poll(struct lgdt3306a_state *state)
{
enum lgdt3306a_neverlock_status NLLockStatus = LG3306_NL_FAIL;
int i;
for (i = 0; i < 5; i++) {
msleep(30);
NLLockStatus = lgdt3306a_check_neverlock_status(state);
if (NLLockStatus == LG3306_NL_LOCK) {
dbg_info("NL_LOCK(%d)\n", i);
return NLLockStatus;
}
}
dbg_info("NLLockStatus=%d\n", NLLockStatus);
return NLLockStatus;
}
static u8 lgdt3306a_get_packet_error(struct lgdt3306a_state *state)
{
u8 val;
int ret;
ret = lgdt3306a_read_reg(state, 0x00fa, &val);
if (ret)
return ret;
return val;
}
static u32 log10_x1000(u32 x)
{
u32 diff_val, step_val, step_log10;
u32 log_val = 0;
u32 i;
if (x <= 0)
return -1000000;
if (x == 10)
return 0;
if (x < 10) {
while (x < 10) {
x = x * 10;
log_val--;
}
} else {
while (x >= 100) {
x = x / 10;
log_val++;
}
}
log_val *= 1000;
if (x == 10)
return log_val;
for (i = 1; i < ARRAY_SIZE(valx_x10); i++) {
if (valx_x10[i] >= x)
break;
}
if (i == ARRAY_SIZE(valx_x10))
return log_val + log10x_x1000[i - 1];
diff_val = x - valx_x10[i-1];
step_val = valx_x10[i] - valx_x10[i - 1];
step_log10 = log10x_x1000[i] - log10x_x1000[i - 1];
return log_val + log10x_x1000[i - 1] +
((diff_val*step_log10) / step_val);
}
static u32 lgdt3306a_calculate_snr_x100(struct lgdt3306a_state *state)
{
u32 mse;
u32 pwr;
u32 snr_x100;
mse = (read_reg(state, 0x00ec) << 8) |
(read_reg(state, 0x00ed));
pwr = (read_reg(state, 0x00e8) << 8) |
(read_reg(state, 0x00e9));
if (mse == 0)
return 0;
snr_x100 = log10_x1000((pwr * 10000) / mse) - 3000;
dbg_info("mse=%u, pwr=%u, snr_x100=%d\n", mse, pwr, snr_x100);
return snr_x100;
}
static enum lgdt3306a_lock_status
lgdt3306a_vsb_lock_poll(struct lgdt3306a_state *state)
{
int ret;
u8 cnt = 0;
u8 packet_error;
u32 snr;
for (cnt = 0; cnt < 10; cnt++) {
if (lgdt3306a_sync_lock_poll(state) == LG3306_UNLOCK) {
dbg_info("no sync lock!\n");
return LG3306_UNLOCK;
}
msleep(20);
ret = lgdt3306a_pre_monitoring(state);
if (ret)
break;
packet_error = lgdt3306a_get_packet_error(state);
snr = lgdt3306a_calculate_snr_x100(state);
dbg_info("cnt=%d errors=%d snr=%d\n", cnt, packet_error, snr);
if ((snr >= 1500) && (packet_error < 0xff))
return LG3306_LOCK;
}
dbg_info("not locked!\n");
return LG3306_UNLOCK;
}
static enum lgdt3306a_lock_status
lgdt3306a_qam_lock_poll(struct lgdt3306a_state *state)
{
u8 cnt;
u8 packet_error;
u32 snr;
for (cnt = 0; cnt < 10; cnt++) {
if (lgdt3306a_fec_lock_poll(state) == LG3306_UNLOCK) {
dbg_info("no fec lock!\n");
return LG3306_UNLOCK;
}
msleep(20);
packet_error = lgdt3306a_get_packet_error(state);
snr = lgdt3306a_calculate_snr_x100(state);
dbg_info("cnt=%d errors=%d snr=%d\n", cnt, packet_error, snr);
if ((snr >= 1500) && (packet_error < 0xff))
return LG3306_LOCK;
}
dbg_info("not locked!\n");
return LG3306_UNLOCK;
}
static int lgdt3306a_read_status(struct dvb_frontend *fe,
enum fe_status *status)
{
struct lgdt3306a_state *state = fe->demodulator_priv;
u16 strength = 0;
int ret = 0;
if (fe->ops.tuner_ops.get_rf_strength) {
ret = fe->ops.tuner_ops.get_rf_strength(fe, &strength);
if (ret == 0)
dbg_info("strength=%d\n", strength);
else
dbg_info("fe->ops.tuner_ops.get_rf_strength() failed\n");
}
*status = 0;
if (lgdt3306a_neverlock_poll(state) == LG3306_NL_LOCK) {
*status |= FE_HAS_SIGNAL;
*status |= FE_HAS_CARRIER;
switch (state->current_modulation) {
case QAM_256:
case QAM_64:
if (lgdt3306a_qam_lock_poll(state) == LG3306_LOCK) {
*status |= FE_HAS_VITERBI;
*status |= FE_HAS_SYNC;
*status |= FE_HAS_LOCK;
}
break;
case VSB_8:
if (lgdt3306a_vsb_lock_poll(state) == LG3306_LOCK) {
*status |= FE_HAS_VITERBI;
*status |= FE_HAS_SYNC;
*status |= FE_HAS_LOCK;
ret = lgdt3306a_monitor_vsb(state);
}
break;
default:
ret = -EINVAL;
}
}
return ret;
}
static int lgdt3306a_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct lgdt3306a_state *state = fe->demodulator_priv;
state->snr = lgdt3306a_calculate_snr_x100(state);
*snr = state->snr/10;
return 0;
}
static int lgdt3306a_read_signal_strength(struct dvb_frontend *fe,
u16 *strength)
{
struct lgdt3306a_state *state = fe->demodulator_priv;
u16 snr;
int ret;
u32 ref_snr;
u32 str;
*strength = 0;
switch (state->current_modulation) {
case VSB_8:
ref_snr = 1600;
break;
case QAM_64:
ref_snr = 2200;
break;
case QAM_256:
ref_snr = 2800;
break;
default:
return -EINVAL;
}
ret = fe->ops.read_snr(fe, &snr);
if (lg_chkerr(ret))
goto fail;
if (state->snr <= (ref_snr - 100))
str = 0;
else if (state->snr <= ref_snr)
str = (0xffff * 65) / 100;
else {
str = state->snr - ref_snr;
str /= 50;
str += 78;
if (str > 100)
str = 100;
str = (0xffff * str) / 100;
}
*strength = (u16)str;
dbg_info("strength=%u\n", *strength);
fail:
return ret;
}
static int lgdt3306a_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct lgdt3306a_state *state = fe->demodulator_priv;
u32 tmp;
*ber = 0;
#if 1
tmp = read_reg(state, 0x00fc);
tmp = (tmp << 8) | read_reg(state, 0x00fd);
tmp = (tmp << 8) | read_reg(state, 0x00fe);
tmp = (tmp << 8) | read_reg(state, 0x00ff);
*ber = tmp;
dbg_info("ber=%u\n", tmp);
#endif
return 0;
}
static int lgdt3306a_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
struct lgdt3306a_state *state = fe->demodulator_priv;
*ucblocks = 0;
#if 1
*ucblocks = read_reg(state, 0x00f4);
dbg_info("ucblocks=%u\n", *ucblocks);
#endif
return 0;
}
static int lgdt3306a_tune(struct dvb_frontend *fe, bool re_tune,
unsigned int mode_flags, unsigned int *delay,
enum fe_status *status)
{
int ret = 0;
struct lgdt3306a_state *state = fe->demodulator_priv;
dbg_info("re_tune=%u\n", re_tune);
if (re_tune) {
state->current_frequency = -1;
ret = lgdt3306a_set_parameters(fe);
if (ret != 0)
return ret;
}
*delay = 125;
ret = lgdt3306a_read_status(fe, status);
return ret;
}
static int lgdt3306a_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings
*fe_tune_settings)
{
fe_tune_settings->min_delay_ms = 100;
dbg_info("\n");
return 0;
}
static int lgdt3306a_search(struct dvb_frontend *fe)
{
enum fe_status status = 0;
int ret;
ret = lgdt3306a_set_parameters(fe);
if (ret)
goto error;
ret = lgdt3306a_read_status(fe, &status);
if (ret)
goto error;
if (status & FE_HAS_LOCK)
return DVBFE_ALGO_SEARCH_SUCCESS;
else
return DVBFE_ALGO_SEARCH_AGAIN;
error:
dbg_info("failed (%d)\n", ret);
return DVBFE_ALGO_SEARCH_ERROR;
}
static void lgdt3306a_release(struct dvb_frontend *fe)
{
struct lgdt3306a_state *state = fe->demodulator_priv;
dbg_info("\n");
kfree(state);
}
struct dvb_frontend *lgdt3306a_attach(const struct lgdt3306a_config *config,
struct i2c_adapter *i2c_adap)
{
struct lgdt3306a_state *state = NULL;
int ret;
u8 val;
dbg_info("(%d-%04x)\n",
i2c_adap ? i2c_adapter_id(i2c_adap) : 0,
config ? config->i2c_addr : 0);
state = kzalloc(sizeof(struct lgdt3306a_state), GFP_KERNEL);
if (state == NULL)
goto fail;
state->cfg = config;
state->i2c_adap = i2c_adap;
memcpy(&state->frontend.ops, &lgdt3306a_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
ret = lgdt3306a_read_reg(state, 0x0000, &val);
if (lg_chkerr(ret))
goto fail;
if ((val & 0x74) != 0x74) {
pr_warn("expected 0x74, got 0x%x\n", (val & 0x74));
#if 0
goto fail;
#endif
}
ret = lgdt3306a_read_reg(state, 0x0001, &val);
if (lg_chkerr(ret))
goto fail;
if ((val & 0xf6) != 0xc6) {
pr_warn("expected 0xc6, got 0x%x\n", (val & 0xf6));
#if 0
goto fail;
#endif
}
ret = lgdt3306a_read_reg(state, 0x0002, &val);
if (lg_chkerr(ret))
goto fail;
if ((val & 0x73) != 0x03) {
pr_warn("expected 0x03, got 0x%x\n", (val & 0x73));
#if 0
goto fail;
#endif
}
state->current_frequency = -1;
state->current_modulation = -1;
lgdt3306a_sleep(state);
return &state->frontend;
fail:
pr_warn("unable to detect LGDT3306A hardware\n");
kfree(state);
return NULL;
}
static void lgdt3306a_DumpAllRegs(struct lgdt3306a_state *state)
{
memset(regval2, 0xff, sizeof(regval2));
lgdt3306a_DumpRegs(state);
}
static void lgdt3306a_DumpRegs(struct lgdt3306a_state *state)
{
int i;
int sav_debug = debug;
if ((debug & DBG_DUMP) == 0)
return;
debug &= ~DBG_REG;
lg_debug("\n");
for (i = 0; i < numDumpRegs; i++) {
lgdt3306a_read_reg(state, regtab[i], &regval1[i]);
if (regval1[i] != regval2[i]) {
lg_debug(" %04X = %02X\n", regtab[i], regval1[i]);
regval2[i] = regval1[i];
}
}
debug = sav_debug;
}
static int lgdt3306a_select(struct i2c_mux_core *muxc, u32 chan)
{
struct i2c_client *client = i2c_mux_priv(muxc);
struct lgdt3306a_state *state = i2c_get_clientdata(client);
return lgdt3306a_i2c_gate_ctrl(&state->frontend, 1);
}
static int lgdt3306a_deselect(struct i2c_mux_core *muxc, u32 chan)
{
struct i2c_client *client = i2c_mux_priv(muxc);
struct lgdt3306a_state *state = i2c_get_clientdata(client);
return lgdt3306a_i2c_gate_ctrl(&state->frontend, 0);
}
static int lgdt3306a_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct lgdt3306a_config *config;
struct lgdt3306a_state *state;
struct dvb_frontend *fe;
int ret;
config = kzalloc(sizeof(struct lgdt3306a_config), GFP_KERNEL);
if (config == NULL) {
ret = -ENOMEM;
goto fail;
}
memcpy(config, client->dev.platform_data,
sizeof(struct lgdt3306a_config));
config->i2c_addr = client->addr;
fe = lgdt3306a_attach(config, client->adapter);
if (fe == NULL) {
ret = -ENODEV;
goto err_fe;
}
i2c_set_clientdata(client, fe->demodulator_priv);
state = fe->demodulator_priv;
state->muxc = i2c_mux_alloc(client->adapter, &client->dev,
1, 0, I2C_MUX_LOCKED,
lgdt3306a_select, lgdt3306a_deselect);
if (!state->muxc) {
ret = -ENOMEM;
goto err_kfree;
}
state->muxc->priv = client;
ret = i2c_mux_add_adapter(state->muxc, 0, 0, 0);
if (ret)
goto err_kfree;
fe->ops.i2c_gate_ctrl = NULL;
*config->i2c_adapter = state->muxc->adapter[0];
*config->fe = fe;
return 0;
err_kfree:
kfree(state);
err_fe:
kfree(config);
fail:
dev_dbg(&client->dev, "failed=%d\n", ret);
return ret;
}
static int lgdt3306a_remove(struct i2c_client *client)
{
struct lgdt3306a_state *state = i2c_get_clientdata(client);
i2c_mux_del_adapters(state->muxc);
state->frontend.ops.release = NULL;
state->frontend.demodulator_priv = NULL;
kfree(state->cfg);
kfree(state);
return 0;
}
