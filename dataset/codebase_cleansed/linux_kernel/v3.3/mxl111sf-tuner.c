static int mxl111sf_tuner_read_reg(struct mxl111sf_tuner_state *state,
u8 addr, u8 *data)
{
return (state->cfg->read_reg) ?
state->cfg->read_reg(state->mxl_state, addr, data) :
-EINVAL;
}
static int mxl111sf_tuner_write_reg(struct mxl111sf_tuner_state *state,
u8 addr, u8 data)
{
return (state->cfg->write_reg) ?
state->cfg->write_reg(state->mxl_state, addr, data) :
-EINVAL;
}
static int mxl111sf_tuner_program_regs(struct mxl111sf_tuner_state *state,
struct mxl111sf_reg_ctrl_info *ctrl_reg_info)
{
return (state->cfg->program_regs) ?
state->cfg->program_regs(state->mxl_state, ctrl_reg_info) :
-EINVAL;
}
static int mxl1x1sf_tuner_top_master_ctrl(struct mxl111sf_tuner_state *state,
int onoff)
{
return (state->cfg->top_master_ctrl) ?
state->cfg->top_master_ctrl(state->mxl_state, onoff) :
-EINVAL;
}
static struct mxl111sf_reg_ctrl_info *mxl111sf_calc_phy_tune_regs(u32 freq,
u8 bw)
{
u8 filt_bw;
switch (bw) {
case 0:
filt_bw = 25;
break;
case 1:
filt_bw = 69;
break;
case 6:
filt_bw = 21;
break;
case 7:
filt_bw = 42;
break;
case 8:
filt_bw = 63;
break;
default:
err("%s: invalid bandwidth setting!", __func__);
return NULL;
}
freq /= 1000000;
freq *= 64;
#if 0
freq += 0.5;
#endif
mxl_phy_tune_rf[0].data = filt_bw;
mxl_phy_tune_rf[1].data = (freq & 0xff);
mxl_phy_tune_rf[2].data = (freq >> 8) & 0xff;
return mxl_phy_tune_rf;
}
static int mxl1x1sf_tuner_set_if_output_freq(struct mxl111sf_tuner_state *state)
{
int ret;
u8 ctrl;
#if 0
u16 iffcw;
u32 if_freq;
#endif
mxl_dbg("(IF polarity = %d, IF freq = 0x%02x)",
state->cfg->invert_spectrum, state->cfg->if_freq);
ctrl = state->cfg->invert_spectrum;
ctrl |= state->cfg->if_freq;
ret = mxl111sf_tuner_write_reg(state, V6_TUNER_IF_SEL_REG, ctrl);
if (mxl_fail(ret))
goto fail;
#if 0
if_freq /= 1000000;
if_freq += 0.5;
if (MXL_IF_LO == state->cfg->if_freq) {
ctrl = 0x08;
iffcw = (u16)(if_freq / (108 * 4096));
} else if (MXL_IF_HI == state->cfg->if_freq) {
ctrl = 0x08;
iffcw = (u16)(if_freq / (216 * 4096));
} else {
ctrl = 0;
iffcw = 0;
}
ctrl |= (iffcw >> 8);
#endif
ret = mxl111sf_tuner_read_reg(state, V6_TUNER_IF_FCW_BYP_REG, &ctrl);
if (mxl_fail(ret))
goto fail;
ctrl &= 0xf0;
ctrl |= 0x90;
ret = mxl111sf_tuner_write_reg(state, V6_TUNER_IF_FCW_BYP_REG, ctrl);
if (mxl_fail(ret))
goto fail;
#if 0
ctrl = iffcw & 0x00ff;
#endif
ret = mxl111sf_tuner_write_reg(state, V6_TUNER_IF_FCW_REG, ctrl);
if (mxl_fail(ret))
goto fail;
state->if_freq = state->cfg->if_freq;
fail:
return ret;
}
static int mxl1x1sf_tune_rf(struct dvb_frontend *fe, u32 freq, u8 bw)
{
struct mxl111sf_tuner_state *state = fe->tuner_priv;
static struct mxl111sf_reg_ctrl_info *reg_ctrl_array;
int ret;
u8 mxl_mode;
mxl_dbg("(freq = %d, bw = 0x%x)", freq, bw);
ret = mxl111sf_tuner_write_reg(state, START_TUNE_REG, 0);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_tuner_read_reg(state, MXL_MODE_REG, &mxl_mode);
if (mxl_fail(ret))
goto fail;
reg_ctrl_array = mxl111sf_calc_phy_tune_regs(freq, bw);
if (!reg_ctrl_array)
return -EINVAL;
ret = mxl111sf_tuner_program_regs(state, reg_ctrl_array);
if (mxl_fail(ret))
goto fail;
if ((mxl_mode & MXL_DEV_MODE_MASK) == MXL_TUNER_MODE) {
mxl1x1sf_tuner_top_master_ctrl(state, 0);
mxl1x1sf_tuner_top_master_ctrl(state, 1);
mxl1x1sf_tuner_set_if_output_freq(state);
}
ret = mxl111sf_tuner_write_reg(state, START_TUNE_REG, 1);
if (mxl_fail(ret))
goto fail;
if (state->cfg->ant_hunt)
state->cfg->ant_hunt(fe);
fail:
return ret;
}
static int mxl1x1sf_tuner_get_lock_status(struct mxl111sf_tuner_state *state,
int *rf_synth_lock,
int *ref_synth_lock)
{
int ret;
u8 data;
*rf_synth_lock = 0;
*ref_synth_lock = 0;
ret = mxl111sf_tuner_read_reg(state, V6_RF_LOCK_STATUS_REG, &data);
if (mxl_fail(ret))
goto fail;
*ref_synth_lock = ((data & 0x03) == 0x03) ? 1 : 0;
*rf_synth_lock = ((data & 0x0c) == 0x0c) ? 1 : 0;
fail:
return ret;
}
static int mxl111sf_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
u32 delsys = c->delivery_system;
struct mxl111sf_tuner_state *state = fe->tuner_priv;
int ret;
u8 bw;
mxl_dbg("()");
switch (delsys) {
case SYS_ATSC:
bw = 0;
break;
case SYS_DVBC_ANNEX_B:
bw = 1;
break;
case SYS_DVBT:
switch (c->bandwidth_hz) {
case 6000000:
bw = 6;
break;
case 7000000:
bw = 7;
break;
case 8000000:
bw = 8;
break;
default:
err("%s: bandwidth not set!", __func__);
return -EINVAL;
}
break;
default:
err("%s: modulation type not supported!", __func__);
return -EINVAL;
}
ret = mxl1x1sf_tune_rf(fe, c->frequency, bw);
if (mxl_fail(ret))
goto fail;
state->frequency = c->frequency;
state->bandwidth = c->bandwidth_hz;
fail:
return ret;
}
static int mxl111sf_tuner_get_status(struct dvb_frontend *fe, u32 *status)
{
struct mxl111sf_tuner_state *state = fe->tuner_priv;
int rf_locked, ref_locked, ret;
*status = 0;
ret = mxl1x1sf_tuner_get_lock_status(state, &rf_locked, &ref_locked);
if (mxl_fail(ret))
goto fail;
mxl_info("%s%s", rf_locked ? "rf locked " : "",
ref_locked ? "ref locked" : "");
if ((rf_locked) || (ref_locked))
*status |= TUNER_STATUS_LOCKED;
fail:
return ret;
}
static int mxl111sf_get_rf_strength(struct dvb_frontend *fe, u16 *strength)
{
struct mxl111sf_tuner_state *state = fe->tuner_priv;
u8 val1, val2;
int ret;
*strength = 0;
ret = mxl111sf_tuner_write_reg(state, 0x00, 0x02);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_tuner_read_reg(state, V6_DIG_RF_PWR_LSB_REG, &val1);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_tuner_read_reg(state, V6_DIG_RF_PWR_MSB_REG, &val2);
if (mxl_fail(ret))
goto fail;
*strength = val1 | ((val2 & 0x07) << 8);
fail:
ret = mxl111sf_tuner_write_reg(state, 0x00, 0x00);
mxl_fail(ret);
return ret;
}
static int mxl111sf_tuner_get_frequency(struct dvb_frontend *fe, u32 *frequency)
{
struct mxl111sf_tuner_state *state = fe->tuner_priv;
*frequency = state->frequency;
return 0;
}
static int mxl111sf_tuner_get_bandwidth(struct dvb_frontend *fe, u32 *bandwidth)
{
struct mxl111sf_tuner_state *state = fe->tuner_priv;
*bandwidth = state->bandwidth;
return 0;
}
static int mxl111sf_tuner_get_if_frequency(struct dvb_frontend *fe,
u32 *frequency)
{
struct mxl111sf_tuner_state *state = fe->tuner_priv;
*frequency = 0;
switch (state->if_freq) {
case MXL_IF_4_0:
*frequency = 4000000;
break;
case MXL_IF_4_5:
*frequency = 4500000;
break;
case MXL_IF_4_57:
*frequency = 4570000;
break;
case MXL_IF_5_0:
*frequency = 5000000;
break;
case MXL_IF_5_38:
*frequency = 5380000;
break;
case MXL_IF_6_0:
*frequency = 6000000;
break;
case MXL_IF_6_28:
*frequency = 6280000;
break;
case MXL_IF_7_2:
*frequency = 7200000;
break;
case MXL_IF_35_25:
*frequency = 35250000;
break;
case MXL_IF_36:
*frequency = 36000000;
break;
case MXL_IF_36_15:
*frequency = 36150000;
break;
case MXL_IF_44:
*frequency = 44000000;
break;
}
return 0;
}
static int mxl111sf_tuner_release(struct dvb_frontend *fe)
{
struct mxl111sf_tuner_state *state = fe->tuner_priv;
mxl_dbg("()");
kfree(state);
fe->tuner_priv = NULL;
return 0;
}
struct dvb_frontend *mxl111sf_tuner_attach(struct dvb_frontend *fe,
struct mxl111sf_state *mxl_state,
struct mxl111sf_tuner_config *cfg)
{
struct mxl111sf_tuner_state *state = NULL;
mxl_dbg("()");
state = kzalloc(sizeof(struct mxl111sf_tuner_state), GFP_KERNEL);
if (state == NULL)
return NULL;
state->mxl_state = mxl_state;
state->cfg = cfg;
memcpy(&fe->ops.tuner_ops, &mxl111sf_tuner_tuner_ops,
sizeof(struct dvb_tuner_ops));
fe->tuner_priv = state;
return fe;
}
