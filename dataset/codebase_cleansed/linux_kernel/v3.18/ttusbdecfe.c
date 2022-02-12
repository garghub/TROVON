static int ttusbdecfe_dvbs_read_status(struct dvb_frontend *fe,
fe_status_t *status)
{
*status = FE_HAS_SIGNAL | FE_HAS_VITERBI |
FE_HAS_SYNC | FE_HAS_CARRIER | FE_HAS_LOCK;
return 0;
}
static int ttusbdecfe_dvbt_read_status(struct dvb_frontend *fe,
fe_status_t *status)
{
struct ttusbdecfe_state* state = fe->demodulator_priv;
u8 b[] = { 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00 };
u8 result[4];
int len, ret;
*status=0;
ret=state->config->send_command(fe, 0x73, sizeof(b), b, &len, result);
if(ret)
return ret;
if(len != 4) {
printk(KERN_ERR "%s: unexpected reply\n", __func__);
return -EIO;
}
switch(result[3]) {
case 1:
case 2:
break;
case 3:
*status = FE_HAS_SIGNAL | FE_HAS_VITERBI |
FE_HAS_SYNC | FE_HAS_CARRIER | FE_HAS_LOCK;
break;
case 4:
*status = FE_TIMEDOUT;
break;
default:
pr_info("%s: returned unknown value: %d\n",
__func__, result[3]);
return -EIO;
}
return 0;
}
static int ttusbdecfe_dvbt_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct ttusbdecfe_state* state = (struct ttusbdecfe_state*) fe->demodulator_priv;
u8 b[] = { 0x00, 0x00, 0x00, 0x03,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0xff,
0x00, 0x00, 0x00, 0xff };
__be32 freq = htonl(p->frequency / 1000);
memcpy(&b[4], &freq, sizeof (u32));
state->config->send_command(fe, 0x71, sizeof(b), b, NULL, NULL);
return 0;
}
static int ttusbdecfe_dvbt_get_tune_settings(struct dvb_frontend* fe,
struct dvb_frontend_tune_settings* fesettings)
{
fesettings->min_delay_ms = 1500;
fesettings->step_size = 0;
fesettings->max_drift = 0;
return 0;
}
static int ttusbdecfe_dvbs_set_frontend(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct ttusbdecfe_state* state = (struct ttusbdecfe_state*) fe->demodulator_priv;
u8 b[] = { 0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00 };
__be32 freq;
__be32 sym_rate;
__be32 band;
__be32 lnb_voltage;
freq = htonl(p->frequency +
(state->hi_band ? LOF_HI : LOF_LO));
memcpy(&b[4], &freq, sizeof(u32));
sym_rate = htonl(p->symbol_rate);
memcpy(&b[12], &sym_rate, sizeof(u32));
band = htonl(state->hi_band ? LOF_HI : LOF_LO);
memcpy(&b[24], &band, sizeof(u32));
lnb_voltage = htonl(state->voltage);
memcpy(&b[28], &lnb_voltage, sizeof(u32));
state->config->send_command(fe, 0x71, sizeof(b), b, NULL, NULL);
return 0;
}
static int ttusbdecfe_dvbs_diseqc_send_master_cmd(struct dvb_frontend* fe, struct dvb_diseqc_master_cmd *cmd)
{
struct ttusbdecfe_state* state = (struct ttusbdecfe_state*) fe->demodulator_priv;
u8 b[] = { 0x00, 0xff, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00,
0x00, 0x00 };
if (cmd->msg_len > sizeof(b) - 4)
return -EINVAL;
memcpy(&b[4], cmd->msg, cmd->msg_len);
state->config->send_command(fe, 0x72,
sizeof(b) - (6 - cmd->msg_len), b,
NULL, NULL);
return 0;
}
static int ttusbdecfe_dvbs_set_tone(struct dvb_frontend* fe, fe_sec_tone_mode_t tone)
{
struct ttusbdecfe_state* state = (struct ttusbdecfe_state*) fe->demodulator_priv;
state->hi_band = (SEC_TONE_ON == tone);
return 0;
}
static int ttusbdecfe_dvbs_set_voltage(struct dvb_frontend* fe, fe_sec_voltage_t voltage)
{
struct ttusbdecfe_state* state = (struct ttusbdecfe_state*) fe->demodulator_priv;
switch (voltage) {
case SEC_VOLTAGE_13:
state->voltage = 13;
break;
case SEC_VOLTAGE_18:
state->voltage = 18;
break;
default:
return -EINVAL;
}
return 0;
}
static void ttusbdecfe_release(struct dvb_frontend* fe)
{
struct ttusbdecfe_state* state = (struct ttusbdecfe_state*) fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend* ttusbdecfe_dvbt_attach(const struct ttusbdecfe_config* config)
{
struct ttusbdecfe_state* state = NULL;
state = kmalloc(sizeof(struct ttusbdecfe_state), GFP_KERNEL);
if (state == NULL)
return NULL;
state->config = config;
memcpy(&state->frontend.ops, &ttusbdecfe_dvbt_ops, sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
}
struct dvb_frontend* ttusbdecfe_dvbs_attach(const struct ttusbdecfe_config* config)
{
struct ttusbdecfe_state* state = NULL;
state = kmalloc(sizeof(struct ttusbdecfe_state), GFP_KERNEL);
if (state == NULL)
return NULL;
state->config = config;
state->voltage = 0;
state->hi_band = 0;
memcpy(&state->frontend.ops, &ttusbdecfe_dvbs_ops, sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
}
