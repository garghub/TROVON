static int mxl111sf_demod_read_reg(struct mxl111sf_demod_state *state,
u8 addr, u8 *data)
{
return (state->cfg->read_reg) ?
state->cfg->read_reg(state->mxl_state, addr, data) :
-EINVAL;
}
static int mxl111sf_demod_write_reg(struct mxl111sf_demod_state *state,
u8 addr, u8 data)
{
return (state->cfg->write_reg) ?
state->cfg->write_reg(state->mxl_state, addr, data) :
-EINVAL;
}
static
int mxl111sf_demod_program_regs(struct mxl111sf_demod_state *state,
struct mxl111sf_reg_ctrl_info *ctrl_reg_info)
{
return (state->cfg->program_regs) ?
state->cfg->program_regs(state->mxl_state, ctrl_reg_info) :
-EINVAL;
}
static
int mxl1x1sf_demod_get_tps_code_rate(struct mxl111sf_demod_state *state,
fe_code_rate_t *code_rate)
{
u8 val;
int ret = mxl111sf_demod_read_reg(state, V6_CODE_RATE_TPS_REG, &val);
if (mxl_fail(ret))
goto fail;
switch (val & V6_CODE_RATE_TPS_MASK) {
case 0:
*code_rate = FEC_1_2;
break;
case 1:
*code_rate = FEC_2_3;
break;
case 2:
*code_rate = FEC_3_4;
break;
case 3:
*code_rate = FEC_5_6;
break;
case 4:
*code_rate = FEC_7_8;
break;
}
fail:
return ret;
}
static
int mxl1x1sf_demod_get_tps_constellation(struct mxl111sf_demod_state *state,
fe_modulation_t *constellation)
{
u8 val;
int ret = mxl111sf_demod_read_reg(state, V6_MODORDER_TPS_REG, &val);
if (mxl_fail(ret))
goto fail;
switch ((val & V6_PARAM_CONSTELLATION_MASK) >> 4) {
case 0:
*constellation = QPSK;
break;
case 1:
*constellation = QAM_16;
break;
case 2:
*constellation = QAM_64;
break;
}
fail:
return ret;
}
static
int mxl1x1sf_demod_get_tps_guard_fft_mode(struct mxl111sf_demod_state *state,
fe_transmit_mode_t *fft_mode)
{
u8 val;
int ret = mxl111sf_demod_read_reg(state, V6_MODE_TPS_REG, &val);
if (mxl_fail(ret))
goto fail;
switch ((val & V6_PARAM_FFT_MODE_MASK) >> 2) {
case 0:
*fft_mode = TRANSMISSION_MODE_2K;
break;
case 1:
*fft_mode = TRANSMISSION_MODE_8K;
break;
case 2:
*fft_mode = TRANSMISSION_MODE_4K;
break;
}
fail:
return ret;
}
static
int mxl1x1sf_demod_get_tps_guard_interval(struct mxl111sf_demod_state *state,
fe_guard_interval_t *guard)
{
u8 val;
int ret = mxl111sf_demod_read_reg(state, V6_CP_TPS_REG, &val);
if (mxl_fail(ret))
goto fail;
switch ((val & V6_PARAM_GI_MASK) >> 4) {
case 0:
*guard = GUARD_INTERVAL_1_32;
break;
case 1:
*guard = GUARD_INTERVAL_1_16;
break;
case 2:
*guard = GUARD_INTERVAL_1_8;
break;
case 3:
*guard = GUARD_INTERVAL_1_4;
break;
}
fail:
return ret;
}
static
int mxl1x1sf_demod_get_tps_hierarchy(struct mxl111sf_demod_state *state,
fe_hierarchy_t *hierarchy)
{
u8 val;
int ret = mxl111sf_demod_read_reg(state, V6_TPS_HIERACHY_REG, &val);
if (mxl_fail(ret))
goto fail;
switch ((val & V6_TPS_HIERARCHY_INFO_MASK) >> 6) {
case 0:
*hierarchy = HIERARCHY_NONE;
break;
case 1:
*hierarchy = HIERARCHY_1;
break;
case 2:
*hierarchy = HIERARCHY_2;
break;
case 3:
*hierarchy = HIERARCHY_4;
break;
}
fail:
return ret;
}
static
int mxl1x1sf_demod_get_sync_lock_status(struct mxl111sf_demod_state *state,
int *sync_lock)
{
u8 val = 0;
int ret = mxl111sf_demod_read_reg(state, V6_SYNC_LOCK_REG, &val);
if (mxl_fail(ret))
goto fail;
*sync_lock = (val & SYNC_LOCK_MASK) >> 4;
fail:
return ret;
}
static
int mxl1x1sf_demod_get_rs_lock_status(struct mxl111sf_demod_state *state,
int *rs_lock)
{
u8 val = 0;
int ret = mxl111sf_demod_read_reg(state, V6_RS_LOCK_DET_REG, &val);
if (mxl_fail(ret))
goto fail;
*rs_lock = (val & RS_LOCK_DET_MASK) >> 3;
fail:
return ret;
}
static
int mxl1x1sf_demod_get_tps_lock_status(struct mxl111sf_demod_state *state,
int *tps_lock)
{
u8 val = 0;
int ret = mxl111sf_demod_read_reg(state, V6_TPS_LOCK_REG, &val);
if (mxl_fail(ret))
goto fail;
*tps_lock = (val & V6_PARAM_TPS_LOCK_MASK) >> 6;
fail:
return ret;
}
static
int mxl1x1sf_demod_get_fec_lock_status(struct mxl111sf_demod_state *state,
int *fec_lock)
{
u8 val = 0;
int ret = mxl111sf_demod_read_reg(state, V6_IRQ_STATUS_REG, &val);
if (mxl_fail(ret))
goto fail;
*fec_lock = (val & IRQ_MASK_FEC_LOCK) >> 4;
fail:
return ret;
}
static int mxl1x1sf_demod_reset_irq_status(struct mxl111sf_demod_state *state)
{
return mxl111sf_demod_write_reg(state, 0x0e, 0xff);
}
static int mxl111sf_demod_set_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *param)
{
struct mxl111sf_demod_state *state = fe->demodulator_priv;
int ret = 0;
struct mxl111sf_reg_ctrl_info phy_pll_patch[] = {
{0x00, 0xff, 0x01},
{0x40, 0xff, 0x05},
{0x40, 0xff, 0x01},
{0x41, 0xff, 0xca},
{0x41, 0xff, 0xc0},
{0x00, 0xff, 0x00},
{0, 0, 0}
};
mxl_dbg("()");
if (fe->ops.tuner_ops.set_params) {
ret = fe->ops.tuner_ops.set_params(fe, param);
if (mxl_fail(ret))
goto fail;
msleep(50);
}
ret = mxl111sf_demod_program_regs(state, phy_pll_patch);
mxl_fail(ret);
msleep(50);
ret = mxl1x1sf_demod_reset_irq_status(state);
mxl_fail(ret);
msleep(100);
fail:
return ret;
}
static int mxl111sf_demod_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
struct mxl111sf_demod_state *state = fe->demodulator_priv;
u32 fec_per_count, fec_per_scale;
u8 val;
int ret;
*ucblocks = 0;
ret = mxl111sf_demod_read_reg(state, V6_FEC_PER_COUNT_REG, &val);
if (mxl_fail(ret))
goto fail;
fec_per_count = val;
ret = mxl111sf_demod_read_reg(state, V6_FEC_PER_SCALE_REG, &val);
if (mxl_fail(ret))
goto fail;
val &= V6_FEC_PER_SCALE_MASK;
val *= 4;
fec_per_scale = 1 << val;
fec_per_count *= fec_per_scale;
*ucblocks = fec_per_count;
fail:
return ret;
}
static int mxl111sf_demod_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct mxl111sf_demod_state *state = fe->demodulator_priv;
u8 val1, val2, val3;
int ret;
*ber = 0;
ret = mxl111sf_demod_read_reg(state, V6_RS_AVG_ERRORS_LSB_REG, &val1);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_demod_read_reg(state, V6_RS_AVG_ERRORS_MSB_REG, &val2);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_demod_read_reg(state, V6_N_ACCUMULATE_REG, &val3);
if (mxl_fail(ret))
goto fail;
*ber = CALCULATE_BER((val1 | (val2 << 8)), val3);
fail:
return ret;
}
static int mxl111sf_demod_calc_snr(struct mxl111sf_demod_state *state,
u16 *snr)
{
u8 val1, val2;
int ret;
*snr = 0;
ret = mxl111sf_demod_read_reg(state, V6_SNR_RB_LSB_REG, &val1);
if (mxl_fail(ret))
goto fail;
ret = mxl111sf_demod_read_reg(state, V6_SNR_RB_MSB_REG, &val2);
if (mxl_fail(ret))
goto fail;
*snr = CALCULATE_SNR(val1 | ((val2 & 0x03) << 8));
fail:
return ret;
}
static int mxl111sf_demod_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct mxl111sf_demod_state *state = fe->demodulator_priv;
int ret = mxl111sf_demod_calc_snr(state, snr);
if (mxl_fail(ret))
goto fail;
*snr /= 10;
fail:
return ret;
}
static int mxl111sf_demod_read_status(struct dvb_frontend *fe,
fe_status_t *status)
{
struct mxl111sf_demod_state *state = fe->demodulator_priv;
int ret, locked, cr_lock, sync_lock, fec_lock;
*status = 0;
ret = mxl1x1sf_demod_get_rs_lock_status(state, &locked);
if (mxl_fail(ret))
goto fail;
ret = mxl1x1sf_demod_get_tps_lock_status(state, &cr_lock);
if (mxl_fail(ret))
goto fail;
ret = mxl1x1sf_demod_get_sync_lock_status(state, &sync_lock);
if (mxl_fail(ret))
goto fail;
ret = mxl1x1sf_demod_get_fec_lock_status(state, &fec_lock);
if (mxl_fail(ret))
goto fail;
if (locked)
*status |= FE_HAS_SIGNAL;
if (cr_lock)
*status |= FE_HAS_CARRIER;
if (sync_lock)
*status |= FE_HAS_SYNC;
if (fec_lock)
*status |= FE_HAS_VITERBI;
if ((locked) && (cr_lock) && (sync_lock))
*status |= FE_HAS_LOCK;
fail:
return ret;
}
static int mxl111sf_demod_read_signal_strength(struct dvb_frontend *fe,
u16 *signal_strength)
{
struct mxl111sf_demod_state *state = fe->demodulator_priv;
fe_modulation_t constellation;
u16 snr;
mxl111sf_demod_calc_snr(state, &snr);
mxl1x1sf_demod_get_tps_constellation(state, &constellation);
switch (constellation) {
case QPSK:
*signal_strength = (snr >= 1300) ?
min(65535, snr * 44) : snr * 38;
break;
case QAM_16:
*signal_strength = (snr >= 1500) ?
min(65535, snr * 38) : snr * 33;
break;
case QAM_64:
*signal_strength = (snr >= 2000) ?
min(65535, snr * 29) : snr * 25;
break;
default:
*signal_strength = 0;
return -EINVAL;
}
return 0;
}
static int mxl111sf_demod_get_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *p)
{
struct mxl111sf_demod_state *state = fe->demodulator_priv;
mxl_dbg("()");
#if 0
p->inversion = ? INVERSION_ON : INVERSION_OFF;
#endif
if (fe->ops.tuner_ops.get_bandwidth)
fe->ops.tuner_ops.get_bandwidth(fe, &p->u.ofdm.bandwidth);
if (fe->ops.tuner_ops.get_frequency)
fe->ops.tuner_ops.get_frequency(fe, &p->frequency);
mxl1x1sf_demod_get_tps_code_rate(state, &p->u.ofdm.code_rate_HP);
mxl1x1sf_demod_get_tps_code_rate(state, &p->u.ofdm.code_rate_LP);
mxl1x1sf_demod_get_tps_constellation(state, &p->u.ofdm.constellation);
mxl1x1sf_demod_get_tps_guard_fft_mode(state,
&p->u.ofdm.transmission_mode);
mxl1x1sf_demod_get_tps_guard_interval(state,
&p->u.ofdm.guard_interval);
mxl1x1sf_demod_get_tps_hierarchy(state,
&p->u.ofdm.hierarchy_information);
return 0;
}
static
int mxl111sf_demod_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings *tune)
{
tune->min_delay_ms = 1000;
return 0;
}
static void mxl111sf_demod_release(struct dvb_frontend *fe)
{
struct mxl111sf_demod_state *state = fe->demodulator_priv;
mxl_dbg("()");
kfree(state);
fe->demodulator_priv = NULL;
}
struct dvb_frontend *mxl111sf_demod_attach(struct mxl111sf_state *mxl_state,
struct mxl111sf_demod_config *cfg)
{
struct mxl111sf_demod_state *state = NULL;
mxl_dbg("()");
state = kzalloc(sizeof(struct mxl111sf_demod_state), GFP_KERNEL);
if (state == NULL)
return NULL;
state->mxl_state = mxl_state;
state->cfg = cfg;
memcpy(&state->fe.ops, &mxl111sf_demod_ops,
sizeof(struct dvb_frontend_ops));
state->fe.demodulator_priv = state;
return &state->fe;
}
