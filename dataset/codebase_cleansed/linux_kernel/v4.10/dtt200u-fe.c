static int dtt200u_fe_read_status(struct dvb_frontend *fe,
enum fe_status *stat)
{
struct dtt200u_fe_state *state = fe->demodulator_priv;
int ret;
mutex_lock(&state->data_mutex);
state->data[0] = GET_TUNE_STATUS;
ret = dvb_usb_generic_rw(state->d, state->data, 1, state->data, 3, 0);
if (ret < 0) {
*stat = 0;
mutex_unlock(&state->data_mutex);
return ret;
}
switch (state->data[0]) {
case 0x01:
*stat = FE_HAS_SIGNAL | FE_HAS_CARRIER |
FE_HAS_VITERBI | FE_HAS_SYNC | FE_HAS_LOCK;
break;
case 0x00:
*stat = FE_TIMEDOUT;
break;
default:
case 0x02:
*stat = 0;
break;
}
mutex_unlock(&state->data_mutex);
return 0;
}
static int dtt200u_fe_read_ber(struct dvb_frontend* fe, u32 *ber)
{
struct dtt200u_fe_state *state = fe->demodulator_priv;
int ret;
mutex_lock(&state->data_mutex);
state->data[0] = GET_VIT_ERR_CNT;
ret = dvb_usb_generic_rw(state->d, state->data, 1, state->data, 3, 0);
if (ret >= 0)
*ber = (state->data[0] << 16) | (state->data[1] << 8) | state->data[2];
mutex_unlock(&state->data_mutex);
return ret;
}
static int dtt200u_fe_read_unc_blocks(struct dvb_frontend* fe, u32 *unc)
{
struct dtt200u_fe_state *state = fe->demodulator_priv;
int ret;
mutex_lock(&state->data_mutex);
state->data[0] = GET_RS_UNCOR_BLK_CNT;
ret = dvb_usb_generic_rw(state->d, state->data, 1, state->data, 2, 0);
if (ret >= 0)
*unc = (state->data[0] << 8) | state->data[1];
mutex_unlock(&state->data_mutex);
return ret;
}
static int dtt200u_fe_read_signal_strength(struct dvb_frontend* fe, u16 *strength)
{
struct dtt200u_fe_state *state = fe->demodulator_priv;
int ret;
mutex_lock(&state->data_mutex);
state->data[0] = GET_AGC;
ret = dvb_usb_generic_rw(state->d, state->data, 1, state->data, 1, 0);
if (ret >= 0)
*strength = (state->data[0] << 8) | state->data[0];
mutex_unlock(&state->data_mutex);
return ret;
}
static int dtt200u_fe_read_snr(struct dvb_frontend* fe, u16 *snr)
{
struct dtt200u_fe_state *state = fe->demodulator_priv;
int ret;
mutex_lock(&state->data_mutex);
state->data[0] = GET_SNR;
ret = dvb_usb_generic_rw(state->d, state->data, 1, state->data, 1, 0);
if (ret >= 0)
*snr = ~((state->data[0] << 8) | state->data[0]);
mutex_unlock(&state->data_mutex);
return ret;
}
static int dtt200u_fe_init(struct dvb_frontend* fe)
{
struct dtt200u_fe_state *state = fe->demodulator_priv;
int ret;
mutex_lock(&state->data_mutex);
state->data[0] = SET_INIT;
ret = dvb_usb_generic_write(state->d, state->data, 1);
mutex_unlock(&state->data_mutex);
return ret;
}
static int dtt200u_fe_sleep(struct dvb_frontend* fe)
{
return dtt200u_fe_init(fe);
}
static int dtt200u_fe_get_tune_settings(struct dvb_frontend* fe, struct dvb_frontend_tune_settings *tune)
{
tune->min_delay_ms = 1500;
tune->step_size = 0;
tune->max_drift = 0;
return 0;
}
static int dtt200u_fe_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *fep = &fe->dtv_property_cache;
struct dtt200u_fe_state *state = fe->demodulator_priv;
int ret;
u16 freq = fep->frequency / 250000;
mutex_lock(&state->data_mutex);
state->data[0] = SET_BANDWIDTH;
switch (fep->bandwidth_hz) {
case 8000000:
state->data[1] = 8;
break;
case 7000000:
state->data[1] = 7;
break;
case 6000000:
state->data[1] = 6;
break;
default:
ret = -EINVAL;
goto ret;
}
ret = dvb_usb_generic_write(state->d, state->data, 2);
if (ret < 0)
goto ret;
state->data[0] = SET_RF_FREQ;
state->data[1] = freq & 0xff;
state->data[2] = (freq >> 8) & 0xff;
ret = dvb_usb_generic_write(state->d, state->data, 3);
if (ret < 0)
goto ret;
ret:
mutex_unlock(&state->data_mutex);
return ret;
}
static int dtt200u_fe_get_frontend(struct dvb_frontend* fe,
struct dtv_frontend_properties *fep)
{
struct dtt200u_fe_state *state = fe->demodulator_priv;
memcpy(fep, &state->fep, sizeof(struct dtv_frontend_properties));
return 0;
}
static void dtt200u_fe_release(struct dvb_frontend* fe)
{
struct dtt200u_fe_state *state = (struct dtt200u_fe_state*) fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend* dtt200u_fe_attach(struct dvb_usb_device *d)
{
struct dtt200u_fe_state* state = NULL;
state = kzalloc(sizeof(struct dtt200u_fe_state), GFP_KERNEL);
if (state == NULL)
goto error;
deb_info("attaching frontend dtt200u\n");
state->d = d;
mutex_init(&state->data_mutex);
memcpy(&state->frontend.ops,&dtt200u_fe_ops,sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error:
return NULL;
}
