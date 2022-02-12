static int vp7045_fe_read_status(struct dvb_frontend* fe, fe_status_t *status)
{
struct vp7045_fe_state *state = fe->demodulator_priv;
u8 s0 = vp7045_read_reg(state->d,0x00),
s1 = vp7045_read_reg(state->d,0x01),
s3 = vp7045_read_reg(state->d,0x03);
*status = 0;
if (s0 & (1 << 4))
*status |= FE_HAS_CARRIER;
if (s0 & (1 << 1))
*status |= FE_HAS_VITERBI;
if (s0 & (1 << 5))
*status |= FE_HAS_LOCK;
if (s1 & (1 << 1))
*status |= FE_HAS_SYNC;
if (s3 & (1 << 6))
*status |= FE_HAS_SIGNAL;
if ((*status & (FE_HAS_CARRIER | FE_HAS_VITERBI | FE_HAS_SYNC)) !=
(FE_HAS_CARRIER | FE_HAS_VITERBI | FE_HAS_SYNC))
*status &= ~FE_HAS_LOCK;
return 0;
}
static int vp7045_fe_read_ber(struct dvb_frontend* fe, u32 *ber)
{
struct vp7045_fe_state *state = fe->demodulator_priv;
*ber = (vp7045_read_reg(state->d, 0x0D) << 16) |
(vp7045_read_reg(state->d, 0x0E) << 8) |
vp7045_read_reg(state->d, 0x0F);
return 0;
}
static int vp7045_fe_read_unc_blocks(struct dvb_frontend* fe, u32 *unc)
{
struct vp7045_fe_state *state = fe->demodulator_priv;
*unc = (vp7045_read_reg(state->d, 0x10) << 8) |
vp7045_read_reg(state->d, 0x11);
return 0;
}
static int vp7045_fe_read_signal_strength(struct dvb_frontend* fe, u16 *strength)
{
struct vp7045_fe_state *state = fe->demodulator_priv;
u16 signal = (vp7045_read_reg(state->d, 0x14) << 8) |
vp7045_read_reg(state->d, 0x15);
*strength = ~signal;
return 0;
}
static int vp7045_fe_read_snr(struct dvb_frontend* fe, u16 *snr)
{
struct vp7045_fe_state *state = fe->demodulator_priv;
u8 _snr = vp7045_read_reg(state->d, 0x09);
*snr = (_snr << 8) | _snr;
return 0;
}
static int vp7045_fe_init(struct dvb_frontend* fe)
{
return 0;
}
static int vp7045_fe_sleep(struct dvb_frontend* fe)
{
return 0;
}
static int vp7045_fe_get_tune_settings(struct dvb_frontend* fe, struct dvb_frontend_tune_settings *tune)
{
tune->min_delay_ms = 800;
return 0;
}
static int vp7045_fe_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *fep = &fe->dtv_property_cache;
struct vp7045_fe_state *state = fe->demodulator_priv;
u8 buf[5];
u32 freq = fep->frequency / 1000;
buf[0] = (freq >> 16) & 0xff;
buf[1] = (freq >> 8) & 0xff;
buf[2] = freq & 0xff;
buf[3] = 0;
switch (fep->bandwidth_hz) {
case 8000000:
buf[4] = 8;
break;
case 7000000:
buf[4] = 7;
break;
case 6000000:
buf[4] = 6;
break;
default:
return -EINVAL;
}
vp7045_usb_op(state->d,LOCK_TUNER_COMMAND,buf,5,NULL,0,200);
return 0;
}
static void vp7045_fe_release(struct dvb_frontend* fe)
{
struct vp7045_fe_state *state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend * vp7045_fe_attach(struct dvb_usb_device *d)
{
struct vp7045_fe_state *s = kzalloc(sizeof(struct vp7045_fe_state), GFP_KERNEL);
if (s == NULL)
goto error;
s->d = d;
memcpy(&s->fe.ops, &vp7045_fe_ops, sizeof(struct dvb_frontend_ops));
s->fe.demodulator_priv = s;
return &s->fe;
error:
return NULL;
}
