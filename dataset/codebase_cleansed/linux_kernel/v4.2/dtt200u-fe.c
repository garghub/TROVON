static int dtt200u_fe_read_status(struct dvb_frontend *fe,
enum fe_status *stat)
{
struct dtt200u_fe_state *state = fe->demodulator_priv;
u8 st = GET_TUNE_STATUS, b[3];
dvb_usb_generic_rw(state->d,&st,1,b,3,0);
switch (b[0]) {
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
return 0;
}
static int dtt200u_fe_read_ber(struct dvb_frontend* fe, u32 *ber)
{
struct dtt200u_fe_state *state = fe->demodulator_priv;
u8 bw = GET_VIT_ERR_CNT,b[3];
dvb_usb_generic_rw(state->d,&bw,1,b,3,0);
*ber = (b[0] << 16) | (b[1] << 8) | b[2];
return 0;
}
static int dtt200u_fe_read_unc_blocks(struct dvb_frontend* fe, u32 *unc)
{
struct dtt200u_fe_state *state = fe->demodulator_priv;
u8 bw = GET_RS_UNCOR_BLK_CNT,b[2];
dvb_usb_generic_rw(state->d,&bw,1,b,2,0);
*unc = (b[0] << 8) | b[1];
return 0;
}
static int dtt200u_fe_read_signal_strength(struct dvb_frontend* fe, u16 *strength)
{
struct dtt200u_fe_state *state = fe->demodulator_priv;
u8 bw = GET_AGC, b;
dvb_usb_generic_rw(state->d,&bw,1,&b,1,0);
*strength = (b << 8) | b;
return 0;
}
static int dtt200u_fe_read_snr(struct dvb_frontend* fe, u16 *snr)
{
struct dtt200u_fe_state *state = fe->demodulator_priv;
u8 bw = GET_SNR,br;
dvb_usb_generic_rw(state->d,&bw,1,&br,1,0);
*snr = ~((br << 8) | br);
return 0;
}
static int dtt200u_fe_init(struct dvb_frontend* fe)
{
struct dtt200u_fe_state *state = fe->demodulator_priv;
u8 b = SET_INIT;
return dvb_usb_generic_write(state->d,&b,1);
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
int i;
enum fe_status st;
u16 freq = fep->frequency / 250000;
u8 bwbuf[2] = { SET_BANDWIDTH, 0 },freqbuf[3] = { SET_RF_FREQ, 0, 0 };
switch (fep->bandwidth_hz) {
case 8000000:
bwbuf[1] = 8;
break;
case 7000000:
bwbuf[1] = 7;
break;
case 6000000:
bwbuf[1] = 6;
break;
default:
return -EINVAL;
}
dvb_usb_generic_write(state->d,bwbuf,2);
freqbuf[1] = freq & 0xff;
freqbuf[2] = (freq >> 8) & 0xff;
dvb_usb_generic_write(state->d,freqbuf,3);
for (i = 0; i < 30; i++) {
msleep(20);
dtt200u_fe_read_status(fe, &st);
if (st & FE_TIMEDOUT)
continue;
}
return 0;
}
static int dtt200u_fe_get_frontend(struct dvb_frontend* fe)
{
struct dtv_frontend_properties *fep = &fe->dtv_property_cache;
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
memcpy(&state->frontend.ops,&dtt200u_fe_ops,sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error:
return NULL;
}
