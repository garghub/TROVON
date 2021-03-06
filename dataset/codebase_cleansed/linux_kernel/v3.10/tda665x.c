static int tda665x_read(struct tda665x_state *state, u8 *buf)
{
const struct tda665x_config *config = state->config;
int err = 0;
struct i2c_msg msg = { .addr = config->addr, .flags = I2C_M_RD, .buf = buf, .len = 2 };
err = i2c_transfer(state->i2c, &msg, 1);
if (err != 1)
goto exit;
return err;
exit:
printk(KERN_ERR "%s: I/O Error err=<%d>\n", __func__, err);
return err;
}
static int tda665x_write(struct tda665x_state *state, u8 *buf, u8 length)
{
const struct tda665x_config *config = state->config;
int err = 0;
struct i2c_msg msg = { .addr = config->addr, .flags = 0, .buf = buf, .len = length };
err = i2c_transfer(state->i2c, &msg, 1);
if (err != 1)
goto exit;
return err;
exit:
printk(KERN_ERR "%s: I/O Error err=<%d>\n", __func__, err);
return err;
}
static int tda665x_get_state(struct dvb_frontend *fe,
enum tuner_param param,
struct tuner_state *tstate)
{
struct tda665x_state *state = fe->tuner_priv;
int err = 0;
switch (param) {
case DVBFE_TUNER_FREQUENCY:
tstate->frequency = state->frequency;
break;
case DVBFE_TUNER_BANDWIDTH:
break;
default:
printk(KERN_ERR "%s: Unknown parameter (param=%d)\n", __func__, param);
err = -EINVAL;
break;
}
return err;
}
static int tda665x_get_status(struct dvb_frontend *fe, u32 *status)
{
struct tda665x_state *state = fe->tuner_priv;
u8 result = 0;
int err = 0;
*status = 0;
err = tda665x_read(state, &result);
if (err < 0)
goto exit;
if ((result >> 6) & 0x01) {
printk(KERN_DEBUG "%s: Tuner Phase Locked\n", __func__);
*status = 1;
}
return err;
exit:
printk(KERN_ERR "%s: I/O Error\n", __func__);
return err;
}
static int tda665x_set_state(struct dvb_frontend *fe,
enum tuner_param param,
struct tuner_state *tstate)
{
struct tda665x_state *state = fe->tuner_priv;
const struct tda665x_config *config = state->config;
u32 frequency, status = 0;
u8 buf[4];
int err = 0;
if (param & DVBFE_TUNER_FREQUENCY) {
frequency = tstate->frequency;
if ((frequency < config->frequency_max) || (frequency > config->frequency_min)) {
printk(KERN_ERR "%s: Frequency beyond limits, frequency=%d\n", __func__, frequency);
return -EINVAL;
}
frequency += config->frequency_offst;
frequency *= config->ref_multiplier;
frequency += config->ref_divider >> 1;
frequency /= config->ref_divider;
buf[0] = (u8) ((frequency & 0x7f00) >> 8);
buf[1] = (u8) (frequency & 0x00ff) >> 0;
buf[2] = 0x80 | 0x40 | 0x02;
buf[3] = 0x00;
frequency = tstate->frequency;
if (frequency < 153000000) {
buf[3] |= 0x01;
if (frequency < 68000000)
buf[3] |= 0x40;
if (frequency < 1040000000)
buf[3] |= 0x60;
if (frequency < 1250000000)
buf[3] |= 0x80;
else
buf[3] |= 0xa0;
} else if (frequency < 438000000) {
buf[3] |= 0x02;
if (frequency < 230000000)
buf[3] |= 0x40;
if (frequency < 300000000)
buf[3] |= 0x60;
else
buf[3] |= 0x80;
} else {
buf[3] |= 0x04;
if (frequency < 470000000)
buf[3] |= 0x60;
if (frequency < 526000000)
buf[3] |= 0x80;
else
buf[3] |= 0xa0;
}
err = tda665x_write(state, buf, 5);
if (err < 0)
goto exit;
printk(KERN_DEBUG "%s: Waiting to Phase LOCK\n", __func__);
msleep(20);
err = tda665x_get_status(fe, &status);
if (err < 0)
goto exit;
if (status == 1) {
printk(KERN_DEBUG "%s: Tuner Phase locked: status=%d\n", __func__, status);
state->frequency = frequency;
} else {
printk(KERN_ERR "%s: No Phase lock: status=%d\n", __func__, status);
}
} else {
printk(KERN_ERR "%s: Unknown parameter (param=%d)\n", __func__, param);
return -EINVAL;
}
return 0;
exit:
printk(KERN_ERR "%s: I/O Error\n", __func__);
return err;
}
static int tda665x_release(struct dvb_frontend *fe)
{
struct tda665x_state *state = fe->tuner_priv;
fe->tuner_priv = NULL;
kfree(state);
return 0;
}
struct dvb_frontend *tda665x_attach(struct dvb_frontend *fe,
const struct tda665x_config *config,
struct i2c_adapter *i2c)
{
struct tda665x_state *state = NULL;
struct dvb_tuner_info *info;
state = kzalloc(sizeof(struct tda665x_state), GFP_KERNEL);
if (!state)
return NULL;
state->config = config;
state->i2c = i2c;
state->fe = fe;
fe->tuner_priv = state;
fe->ops.tuner_ops = tda665x_ops;
info = &fe->ops.tuner_ops.info;
memcpy(info->name, config->name, sizeof(config->name));
info->frequency_min = config->frequency_min;
info->frequency_max = config->frequency_max;
info->frequency_step = config->frequency_offst;
printk(KERN_DEBUG "%s: Attaching TDA665x (%s) tuner\n", __func__, info->name);
return fe;
}
