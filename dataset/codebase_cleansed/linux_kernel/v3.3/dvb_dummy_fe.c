static int dvb_dummy_fe_read_status(struct dvb_frontend* fe, fe_status_t* status)
{
*status = FE_HAS_SIGNAL
| FE_HAS_CARRIER
| FE_HAS_VITERBI
| FE_HAS_SYNC
| FE_HAS_LOCK;
return 0;
}
static int dvb_dummy_fe_read_ber(struct dvb_frontend* fe, u32* ber)
{
*ber = 0;
return 0;
}
static int dvb_dummy_fe_read_signal_strength(struct dvb_frontend* fe, u16* strength)
{
*strength = 0;
return 0;
}
static int dvb_dummy_fe_read_snr(struct dvb_frontend* fe, u16* snr)
{
*snr = 0;
return 0;
}
static int dvb_dummy_fe_read_ucblocks(struct dvb_frontend* fe, u32* ucblocks)
{
*ucblocks = 0;
return 0;
}
static int dvb_dummy_fe_get_frontend(struct dvb_frontend *fe)
{
return 0;
}
static int dvb_dummy_fe_set_frontend(struct dvb_frontend *fe)
{
if (fe->ops.tuner_ops.set_params) {
fe->ops.tuner_ops.set_params(fe);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
}
return 0;
}
static int dvb_dummy_fe_sleep(struct dvb_frontend* fe)
{
return 0;
}
static int dvb_dummy_fe_init(struct dvb_frontend* fe)
{
return 0;
}
static int dvb_dummy_fe_set_tone(struct dvb_frontend* fe, fe_sec_tone_mode_t tone)
{
return 0;
}
static int dvb_dummy_fe_set_voltage(struct dvb_frontend* fe, fe_sec_voltage_t voltage)
{
return 0;
}
static void dvb_dummy_fe_release(struct dvb_frontend* fe)
{
struct dvb_dummy_fe_state* state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend* dvb_dummy_fe_ofdm_attach(void)
{
struct dvb_dummy_fe_state* state = NULL;
state = kzalloc(sizeof(struct dvb_dummy_fe_state), GFP_KERNEL);
if (state == NULL) goto error;
memcpy(&state->frontend.ops, &dvb_dummy_fe_ofdm_ops, sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error:
kfree(state);
return NULL;
}
struct dvb_frontend *dvb_dummy_fe_qpsk_attach(void)
{
struct dvb_dummy_fe_state* state = NULL;
state = kzalloc(sizeof(struct dvb_dummy_fe_state), GFP_KERNEL);
if (state == NULL) goto error;
memcpy(&state->frontend.ops, &dvb_dummy_fe_qpsk_ops, sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error:
kfree(state);
return NULL;
}
struct dvb_frontend *dvb_dummy_fe_qam_attach(void)
{
struct dvb_dummy_fe_state* state = NULL;
state = kzalloc(sizeof(struct dvb_dummy_fe_state), GFP_KERNEL);
if (state == NULL) goto error;
memcpy(&state->frontend.ops, &dvb_dummy_fe_qam_ops, sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error:
kfree(state);
return NULL;
}
