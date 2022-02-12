static int ds3000_writereg(struct ds3000_state *state, int reg, int data)
{
u8 buf[] = { reg, data };
struct i2c_msg msg = { .addr = state->config->demod_address,
.flags = 0, .buf = buf, .len = 2 };
int err;
dprintk("%s: write reg 0x%02x, value 0x%02x\n", __func__, reg, data);
err = i2c_transfer(state->i2c, &msg, 1);
if (err != 1) {
printk(KERN_ERR "%s: writereg error(err == %i, reg == 0x%02x,"
" value == 0x%02x)\n", __func__, err, reg, data);
return -EREMOTEIO;
}
return 0;
}
static int ds3000_tuner_writereg(struct ds3000_state *state, int reg, int data)
{
u8 buf[] = { reg, data };
struct i2c_msg msg = { .addr = 0x60,
.flags = 0, .buf = buf, .len = 2 };
int err;
dprintk("%s: write reg 0x%02x, value 0x%02x\n", __func__, reg, data);
ds3000_writereg(state, 0x03, 0x11);
err = i2c_transfer(state->i2c, &msg, 1);
if (err != 1) {
printk("%s: writereg error(err == %i, reg == 0x%02x,"
" value == 0x%02x)\n", __func__, err, reg, data);
return -EREMOTEIO;
}
return 0;
}
static int ds3000_writeFW(struct ds3000_state *state, int reg,
const u8 *data, u16 len)
{
int i, ret = -EREMOTEIO;
struct i2c_msg msg;
u8 *buf;
buf = kmalloc(33, GFP_KERNEL);
if (buf == NULL) {
printk(KERN_ERR "Unable to kmalloc\n");
ret = -ENOMEM;
goto error;
}
*(buf) = reg;
msg.addr = state->config->demod_address;
msg.flags = 0;
msg.buf = buf;
msg.len = 33;
for (i = 0; i < len; i += 32) {
memcpy(buf + 1, data + i, 32);
dprintk("%s: write reg 0x%02x, len = %d\n", __func__, reg, len);
ret = i2c_transfer(state->i2c, &msg, 1);
if (ret != 1) {
printk(KERN_ERR "%s: write error(err == %i, "
"reg == 0x%02x\n", __func__, ret, reg);
ret = -EREMOTEIO;
}
}
error:
kfree(buf);
return ret;
}
static int ds3000_readreg(struct ds3000_state *state, u8 reg)
{
int ret;
u8 b0[] = { reg };
u8 b1[] = { 0 };
struct i2c_msg msg[] = {
{
.addr = state->config->demod_address,
.flags = 0,
.buf = b0,
.len = 1
}, {
.addr = state->config->demod_address,
.flags = I2C_M_RD,
.buf = b1,
.len = 1
}
};
ret = i2c_transfer(state->i2c, msg, 2);
if (ret != 2) {
printk(KERN_ERR "%s: reg=0x%x(error=%d)\n", __func__, reg, ret);
return ret;
}
dprintk("%s: read reg 0x%02x, value 0x%02x\n", __func__, reg, b1[0]);
return b1[0];
}
static int ds3000_tuner_readreg(struct ds3000_state *state, u8 reg)
{
int ret;
u8 b0[] = { reg };
u8 b1[] = { 0 };
struct i2c_msg msg[] = {
{
.addr = 0x60,
.flags = 0,
.buf = b0,
.len = 1
}, {
.addr = 0x60,
.flags = I2C_M_RD,
.buf = b1,
.len = 1
}
};
ds3000_writereg(state, 0x03, 0x12);
ret = i2c_transfer(state->i2c, msg, 2);
if (ret != 2) {
printk(KERN_ERR "%s: reg=0x%x(error=%d)\n", __func__, reg, ret);
return ret;
}
dprintk("%s: read reg 0x%02x, value 0x%02x\n", __func__, reg, b1[0]);
return b1[0];
}
static int ds3000_firmware_ondemand(struct dvb_frontend *fe)
{
struct ds3000_state *state = fe->demodulator_priv;
const struct firmware *fw;
int ret = 0;
dprintk("%s()\n", __func__);
ret = ds3000_readreg(state, 0xb2);
if (ret < 0)
return ret;
printk(KERN_INFO "%s: Waiting for firmware upload (%s)...\n", __func__,
DS3000_DEFAULT_FIRMWARE);
ret = request_firmware(&fw, DS3000_DEFAULT_FIRMWARE,
state->i2c->dev.parent);
printk(KERN_INFO "%s: Waiting for firmware upload(2)...\n", __func__);
if (ret) {
printk(KERN_ERR "%s: No firmware uploaded (timeout or file not "
"found?)\n", __func__);
return ret;
}
ret = ds3000_load_firmware(fe, fw);
if (ret)
printk("%s: Writing firmware to device failed\n", __func__);
release_firmware(fw);
dprintk("%s: Firmware upload %s\n", __func__,
ret == 0 ? "complete" : "failed");
return ret;
}
static int ds3000_load_firmware(struct dvb_frontend *fe,
const struct firmware *fw)
{
struct ds3000_state *state = fe->demodulator_priv;
dprintk("%s\n", __func__);
dprintk("Firmware is %zu bytes (%02x %02x .. %02x %02x)\n",
fw->size,
fw->data[0],
fw->data[1],
fw->data[fw->size - 2],
fw->data[fw->size - 1]);
ds3000_writereg(state, 0xb2, 0x01);
ds3000_writeFW(state, 0xb0, fw->data, fw->size);
ds3000_writereg(state, 0xb2, 0x00);
return 0;
}
static int ds3000_set_voltage(struct dvb_frontend *fe, fe_sec_voltage_t voltage)
{
struct ds3000_state *state = fe->demodulator_priv;
u8 data;
dprintk("%s(%d)\n", __func__, voltage);
data = ds3000_readreg(state, 0xa2);
data |= 0x03;
switch (voltage) {
case SEC_VOLTAGE_18:
data &= ~0x03;
break;
case SEC_VOLTAGE_13:
data &= ~0x03;
data |= 0x01;
break;
case SEC_VOLTAGE_OFF:
break;
}
ds3000_writereg(state, 0xa2, data);
return 0;
}
static int ds3000_read_status(struct dvb_frontend *fe, fe_status_t* status)
{
struct ds3000_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int lock;
*status = 0;
switch (c->delivery_system) {
case SYS_DVBS:
lock = ds3000_readreg(state, 0xd1);
if ((lock & 0x07) == 0x07)
*status = FE_HAS_SIGNAL | FE_HAS_CARRIER |
FE_HAS_VITERBI | FE_HAS_SYNC |
FE_HAS_LOCK;
break;
case SYS_DVBS2:
lock = ds3000_readreg(state, 0x0d);
if ((lock & 0x8f) == 0x8f)
*status = FE_HAS_SIGNAL | FE_HAS_CARRIER |
FE_HAS_VITERBI | FE_HAS_SYNC |
FE_HAS_LOCK;
break;
default:
return 1;
}
dprintk("%s: status = 0x%02x\n", __func__, lock);
return 0;
}
static int ds3000_read_ber(struct dvb_frontend *fe, u32* ber)
{
struct ds3000_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
u8 data;
u32 ber_reading, lpdc_frames;
dprintk("%s()\n", __func__);
switch (c->delivery_system) {
case SYS_DVBS:
ds3000_writereg(state, 0xf9, 0x04);
data = ds3000_readreg(state, 0xf8);
if ((data & 0x10) == 0) {
*ber = (ds3000_readreg(state, 0xf7) << 8) |
ds3000_readreg(state, 0xf6);
data |= 0x10;
ds3000_writereg(state, 0xf8, data);
ds3000_writereg(state, 0xf8, data);
} else
*ber = 0xffffffff;
break;
case SYS_DVBS2:
lpdc_frames = (ds3000_readreg(state, 0xd7) << 16) |
(ds3000_readreg(state, 0xd6) << 8) |
ds3000_readreg(state, 0xd5);
ber_reading = (ds3000_readreg(state, 0xf8) << 8) |
ds3000_readreg(state, 0xf7);
if (lpdc_frames > 750) {
ds3000_writereg(state, 0xd1, 0x01);
ds3000_writereg(state, 0xf9, 0x01);
ds3000_writereg(state, 0xf9, 0x00);
ds3000_writereg(state, 0xd1, 0x00);
*ber = ber_reading;
} else
*ber = 0xffffffff;
break;
default:
return 1;
}
return 0;
}
static int ds3000_read_signal_strength(struct dvb_frontend *fe,
u16 *signal_strength)
{
struct ds3000_state *state = fe->demodulator_priv;
u16 sig_reading, sig_strength;
u8 rfgain, bbgain;
dprintk("%s()\n", __func__);
rfgain = ds3000_tuner_readreg(state, 0x3d) & 0x1f;
bbgain = ds3000_tuner_readreg(state, 0x21) & 0x1f;
if (rfgain > 15)
rfgain = 15;
if (bbgain > 13)
bbgain = 13;
sig_reading = rfgain * 2 + bbgain * 3;
sig_strength = 40 + (64 - sig_reading) * 50 / 64 ;
*signal_strength = sig_strength * 1000;
dprintk("%s: raw / cooked = 0x%04x / 0x%04x\n", __func__,
sig_reading, *signal_strength);
return 0;
}
static int ds3000_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct ds3000_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
u8 snr_reading, snr_value;
u32 dvbs2_signal_reading, dvbs2_noise_reading, tmp;
static const u16 dvbs_snr_tab[] = {
0x0000, 0x1b13, 0x2aea, 0x3627, 0x3ede, 0x45fe, 0x4c03,
0x513a, 0x55d4, 0x59f2, 0x5dab, 0x6111, 0x6431, 0x6717,
0x69c9, 0x6c4e, 0x6eac, 0x70e8, 0x7304, 0x7505
};
static const u16 dvbs2_snr_tab[] = {
0x0000, 0x0bc2, 0x12a3, 0x1785, 0x1b4e, 0x1e65, 0x2103,
0x2347, 0x2546, 0x2710, 0x28ae, 0x2a28, 0x2b83, 0x2cc5,
0x2df1, 0x2f09, 0x3010, 0x3109, 0x31f4, 0x32d2, 0x33a6,
0x3470, 0x3531, 0x35ea, 0x369b, 0x3746, 0x37ea, 0x3888,
0x3920, 0x39b3, 0x3a42, 0x3acc, 0x3b51, 0x3bd3, 0x3c51,
0x3ccb, 0x3d42, 0x3db6, 0x3e27, 0x3e95, 0x3f00, 0x3f68,
0x3fcf, 0x4033, 0x4094, 0x40f4, 0x4151, 0x41ac, 0x4206,
0x425e, 0x42b4, 0x4308, 0x435b, 0x43ac, 0x43fc, 0x444a,
0x4497, 0x44e2, 0x452d, 0x4576, 0x45bd, 0x4604, 0x4649,
0x468e, 0x46d1, 0x4713, 0x4755, 0x4795, 0x47d4, 0x4813,
0x4851, 0x488d, 0x48c9, 0x4904, 0x493f, 0x4978, 0x49b1,
0x49e9, 0x4a20, 0x4a57
};
dprintk("%s()\n", __func__);
switch (c->delivery_system) {
case SYS_DVBS:
snr_reading = ds3000_readreg(state, 0xff);
snr_reading /= 8;
if (snr_reading == 0)
*snr = 0x0000;
else {
if (snr_reading > 20)
snr_reading = 20;
snr_value = dvbs_snr_tab[snr_reading - 1] * 10 / 23026;
*snr = snr_value * 8 * 655;
}
dprintk("%s: raw / cooked = 0x%02x / 0x%04x\n", __func__,
snr_reading, *snr);
break;
case SYS_DVBS2:
dvbs2_noise_reading = (ds3000_readreg(state, 0x8c) & 0x3f) +
(ds3000_readreg(state, 0x8d) << 4);
dvbs2_signal_reading = ds3000_readreg(state, 0x8e);
tmp = dvbs2_signal_reading * dvbs2_signal_reading >> 1;
if (tmp == 0) {
*snr = 0x0000;
return 0;
}
if (dvbs2_noise_reading == 0) {
snr_value = 0x0013;
*snr = 0xffff;
return 0;
}
if (tmp > dvbs2_noise_reading) {
snr_reading = tmp / dvbs2_noise_reading;
if (snr_reading > 80)
snr_reading = 80;
snr_value = dvbs2_snr_tab[snr_reading - 1] / 1000;
*snr = snr_value * 5 * 655;
} else {
snr_reading = dvbs2_noise_reading / tmp;
if (snr_reading > 80)
snr_reading = 80;
*snr = -(dvbs2_snr_tab[snr_reading] / 1000);
}
dprintk("%s: raw / cooked = 0x%02x / 0x%04x\n", __func__,
snr_reading, *snr);
break;
default:
return 1;
}
return 0;
}
static int ds3000_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
struct ds3000_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
u8 data;
u16 _ucblocks;
dprintk("%s()\n", __func__);
switch (c->delivery_system) {
case SYS_DVBS:
*ucblocks = (ds3000_readreg(state, 0xf5) << 8) |
ds3000_readreg(state, 0xf4);
data = ds3000_readreg(state, 0xf8);
data &= ~0x20;
ds3000_writereg(state, 0xf8, data);
data |= 0x20;
ds3000_writereg(state, 0xf8, data);
break;
case SYS_DVBS2:
_ucblocks = (ds3000_readreg(state, 0xe2) << 8) |
ds3000_readreg(state, 0xe1);
if (_ucblocks > state->prevUCBS2)
*ucblocks = _ucblocks - state->prevUCBS2;
else
*ucblocks = state->prevUCBS2 - _ucblocks;
state->prevUCBS2 = _ucblocks;
break;
default:
return 1;
}
return 0;
}
static int ds3000_set_tone(struct dvb_frontend *fe, fe_sec_tone_mode_t tone)
{
struct ds3000_state *state = fe->demodulator_priv;
u8 data;
dprintk("%s(%d)\n", __func__, tone);
if ((tone != SEC_TONE_ON) && (tone != SEC_TONE_OFF)) {
printk(KERN_ERR "%s: Invalid, tone=%d\n", __func__, tone);
return -EINVAL;
}
data = ds3000_readreg(state, 0xa2);
data &= ~0xc0;
ds3000_writereg(state, 0xa2, data);
switch (tone) {
case SEC_TONE_ON:
dprintk("%s: setting tone on\n", __func__);
data = ds3000_readreg(state, 0xa1);
data &= ~0x43;
data |= 0x04;
ds3000_writereg(state, 0xa1, data);
break;
case SEC_TONE_OFF:
dprintk("%s: setting tone off\n", __func__);
data = ds3000_readreg(state, 0xa2);
data |= 0x80;
ds3000_writereg(state, 0xa2, data);
break;
}
return 0;
}
static int ds3000_send_diseqc_msg(struct dvb_frontend *fe,
struct dvb_diseqc_master_cmd *d)
{
struct ds3000_state *state = fe->demodulator_priv;
int i;
u8 data;
dprintk("%s(", __func__);
for (i = 0 ; i < d->msg_len;) {
dprintk("0x%02x", d->msg[i]);
if (++i < d->msg_len)
dprintk(", ");
}
data = ds3000_readreg(state, 0xa2);
data &= ~0xc0;
ds3000_writereg(state, 0xa2, data);
for (i = 0; i < d->msg_len; i++)
ds3000_writereg(state, 0xa3 + i, d->msg[i]);
data = ds3000_readreg(state, 0xa1);
data &= ~0xf8;
data |= ((d->msg_len - 1) << 3) | 0x07;
ds3000_writereg(state, 0xa1, data);
for (i = 0; i < 15; i++) {
data = ds3000_readreg(state, 0xa1);
if ((data & 0x40) == 0)
break;
msleep(10);
}
if (i == 15) {
data = ds3000_readreg(state, 0xa1);
data &= ~0x80;
data |= 0x40;
ds3000_writereg(state, 0xa1, data);
data = ds3000_readreg(state, 0xa2);
data &= ~0xc0;
data |= 0x80;
ds3000_writereg(state, 0xa2, data);
return 1;
}
data = ds3000_readreg(state, 0xa2);
data &= ~0xc0;
data |= 0x80;
ds3000_writereg(state, 0xa2, data);
return 0;
}
static int ds3000_diseqc_send_burst(struct dvb_frontend *fe,
fe_sec_mini_cmd_t burst)
{
struct ds3000_state *state = fe->demodulator_priv;
int i;
u8 data;
dprintk("%s()\n", __func__);
data = ds3000_readreg(state, 0xa2);
data &= ~0xc0;
ds3000_writereg(state, 0xa2, data);
if (burst == SEC_MINI_A)
ds3000_writereg(state, 0xa1, 0x02);
else if (burst == SEC_MINI_B)
ds3000_writereg(state, 0xa1, 0x01);
else
return -EINVAL;
msleep(13);
for (i = 0; i < 5; i++) {
data = ds3000_readreg(state, 0xa1);
if ((data & 0x40) == 0)
break;
msleep(1);
}
if (i == 5) {
data = ds3000_readreg(state, 0xa1);
data &= ~0x80;
data |= 0x40;
ds3000_writereg(state, 0xa1, data);
data = ds3000_readreg(state, 0xa2);
data &= ~0xc0;
data |= 0x80;
ds3000_writereg(state, 0xa2, data);
return 1;
}
data = ds3000_readreg(state, 0xa2);
data &= ~0xc0;
data |= 0x80;
ds3000_writereg(state, 0xa2, data);
return 0;
}
static void ds3000_release(struct dvb_frontend *fe)
{
struct ds3000_state *state = fe->demodulator_priv;
dprintk("%s\n", __func__);
kfree(state);
}
struct dvb_frontend *ds3000_attach(const struct ds3000_config *config,
struct i2c_adapter *i2c)
{
struct ds3000_state *state = NULL;
int ret;
dprintk("%s\n", __func__);
state = kzalloc(sizeof(struct ds3000_state), GFP_KERNEL);
if (state == NULL) {
printk(KERN_ERR "Unable to kmalloc\n");
goto error2;
}
state->config = config;
state->i2c = i2c;
state->prevUCBS2 = 0;
ret = ds3000_readreg(state, 0x00) & 0xfe;
if (ret != 0xe0) {
printk(KERN_ERR "Invalid probe, probably not a DS3000\n");
goto error3;
}
printk(KERN_INFO "DS3000 chip version: %d.%d attached.\n",
ds3000_readreg(state, 0x02),
ds3000_readreg(state, 0x01));
memcpy(&state->frontend.ops, &ds3000_ops,
sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
error3:
kfree(state);
error2:
return NULL;
}
static int ds3000_set_carrier_offset(struct dvb_frontend *fe,
s32 carrier_offset_khz)
{
struct ds3000_state *state = fe->demodulator_priv;
s32 tmp;
tmp = carrier_offset_khz;
tmp *= 65536;
tmp = (2 * tmp + DS3000_SAMPLE_RATE) / (2 * DS3000_SAMPLE_RATE);
if (tmp < 0)
tmp += 65536;
ds3000_writereg(state, 0x5f, tmp >> 8);
ds3000_writereg(state, 0x5e, tmp & 0xff);
return 0;
}
static int ds3000_set_frontend(struct dvb_frontend *fe)
{
struct ds3000_state *state = fe->demodulator_priv;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int i;
fe_status_t status;
u8 mlpf, mlpf_new, mlpf_max, mlpf_min, nlpf, div4;
s32 offset_khz;
u16 value, ndiv;
u32 f3db;
dprintk("%s() ", __func__);
if (state->config->set_ts_params)
state->config->set_ts_params(fe, 0);
ds3000_tuner_writereg(state, 0x07, 0x02);
ds3000_tuner_writereg(state, 0x10, 0x00);
ds3000_tuner_writereg(state, 0x60, 0x79);
ds3000_tuner_writereg(state, 0x08, 0x01);
ds3000_tuner_writereg(state, 0x00, 0x01);
div4 = 0;
if (c->frequency < 1146000) {
ds3000_tuner_writereg(state, 0x10, 0x11);
div4 = 1;
ndiv = ((c->frequency * (6 + 8) * 4) +
(DS3000_XTAL_FREQ / 2)) /
DS3000_XTAL_FREQ - 1024;
} else {
ds3000_tuner_writereg(state, 0x10, 0x01);
ndiv = ((c->frequency * (6 + 8) * 2) +
(DS3000_XTAL_FREQ / 2)) /
DS3000_XTAL_FREQ - 1024;
}
ds3000_tuner_writereg(state, 0x01, (ndiv & 0x0f00) >> 8);
ds3000_tuner_writereg(state, 0x02, ndiv & 0x00ff);
ds3000_tuner_writereg(state, 0x03, 0x06);
ds3000_tuner_writereg(state, 0x51, 0x0f);
ds3000_tuner_writereg(state, 0x51, 0x1f);
ds3000_tuner_writereg(state, 0x50, 0x10);
ds3000_tuner_writereg(state, 0x50, 0x00);
msleep(5);
ds3000_tuner_writereg(state, 0x51, 0x17);
ds3000_tuner_writereg(state, 0x51, 0x1f);
ds3000_tuner_writereg(state, 0x50, 0x08);
ds3000_tuner_writereg(state, 0x50, 0x00);
msleep(5);
value = ds3000_tuner_readreg(state, 0x3d);
value &= 0x0f;
if ((value > 4) && (value < 15)) {
value -= 3;
if (value < 4)
value = 4;
value = ((value << 3) | 0x01) & 0x79;
}
ds3000_tuner_writereg(state, 0x60, value);
ds3000_tuner_writereg(state, 0x51, 0x17);
ds3000_tuner_writereg(state, 0x51, 0x1f);
ds3000_tuner_writereg(state, 0x50, 0x08);
ds3000_tuner_writereg(state, 0x50, 0x00);
ds3000_tuner_writereg(state, 0x04, 0x2e);
ds3000_tuner_writereg(state, 0x51, 0x1b);
ds3000_tuner_writereg(state, 0x51, 0x1f);
ds3000_tuner_writereg(state, 0x50, 0x04);
ds3000_tuner_writereg(state, 0x50, 0x00);
msleep(5);
f3db = ((c->symbol_rate / 1000) << 2) / 5 + 2000;
if ((c->symbol_rate / 1000) < 5000)
f3db += 3000;
if (f3db < 7000)
f3db = 7000;
if (f3db > 40000)
f3db = 40000;
value = ds3000_tuner_readreg(state, 0x26);
mlpf = 0x2e * 207 / ((value << 1) + 151);
mlpf_max = mlpf * 135 / 100;
mlpf_min = mlpf * 78 / 100;
if (mlpf_max > 63)
mlpf_max = 63;
nlpf = ((mlpf * f3db * 1000) + (2766 * DS3000_XTAL_FREQ / 2))
/ (2766 * DS3000_XTAL_FREQ);
if (nlpf > 23)
nlpf = 23;
if (nlpf < 1)
nlpf = 1;
mlpf_new = ((DS3000_XTAL_FREQ * nlpf * 2766) +
(1000 * f3db / 2)) / (1000 * f3db);
if (mlpf_new < mlpf_min) {
nlpf++;
mlpf_new = ((DS3000_XTAL_FREQ * nlpf * 2766) +
(1000 * f3db / 2)) / (1000 * f3db);
}
if (mlpf_new > mlpf_max)
mlpf_new = mlpf_max;
ds3000_tuner_writereg(state, 0x04, mlpf_new);
ds3000_tuner_writereg(state, 0x06, nlpf);
ds3000_tuner_writereg(state, 0x51, 0x1b);
ds3000_tuner_writereg(state, 0x51, 0x1f);
ds3000_tuner_writereg(state, 0x50, 0x04);
ds3000_tuner_writereg(state, 0x50, 0x00);
msleep(5);
ds3000_tuner_writereg(state, 0x51, 0x1e);
ds3000_tuner_writereg(state, 0x51, 0x1f);
ds3000_tuner_writereg(state, 0x50, 0x01);
ds3000_tuner_writereg(state, 0x50, 0x00);
msleep(60);
offset_khz = (ndiv - ndiv % 2 + 1024) * DS3000_XTAL_FREQ
/ (6 + 8) / (div4 + 1) / 2 - c->frequency;
ds3000_writereg(state, 0x07, 0x80);
ds3000_writereg(state, 0x07, 0x00);
ds3000_writereg(state, 0xb2, 0x01);
ds3000_writereg(state, 0x00, 0x01);
switch (c->delivery_system) {
case SYS_DVBS:
for (i = 0; i < sizeof(ds3000_dvbs_init_tab); i += 2)
ds3000_writereg(state,
ds3000_dvbs_init_tab[i],
ds3000_dvbs_init_tab[i + 1]);
value = ds3000_readreg(state, 0xfe);
value &= 0xc0;
value |= 0x1b;
ds3000_writereg(state, 0xfe, value);
break;
case SYS_DVBS2:
for (i = 0; i < sizeof(ds3000_dvbs2_init_tab); i += 2)
ds3000_writereg(state,
ds3000_dvbs2_init_tab[i],
ds3000_dvbs2_init_tab[i + 1]);
if (c->symbol_rate >= 30000000)
ds3000_writereg(state, 0xfe, 0x54);
else
ds3000_writereg(state, 0xfe, 0x98);
break;
default:
return 1;
}
ds3000_writereg(state, 0x29, 0x80);
ds3000_writereg(state, 0x25, 0x8a);
if ((c->symbol_rate / 1000) <= 5000) {
value = 29777 / (c->symbol_rate / 1000) + 1;
if (value % 2 != 0)
value++;
ds3000_writereg(state, 0xc3, 0x0d);
ds3000_writereg(state, 0xc8, value);
ds3000_writereg(state, 0xc4, 0x10);
ds3000_writereg(state, 0xc7, 0x0e);
} else if ((c->symbol_rate / 1000) <= 10000) {
value = 92166 / (c->symbol_rate / 1000) + 1;
if (value % 2 != 0)
value++;
ds3000_writereg(state, 0xc3, 0x07);
ds3000_writereg(state, 0xc8, value);
ds3000_writereg(state, 0xc4, 0x09);
ds3000_writereg(state, 0xc7, 0x12);
} else if ((c->symbol_rate / 1000) <= 20000) {
value = 64516 / (c->symbol_rate / 1000) + 1;
ds3000_writereg(state, 0xc3, value);
ds3000_writereg(state, 0xc8, 0x0e);
ds3000_writereg(state, 0xc4, 0x07);
ds3000_writereg(state, 0xc7, 0x18);
} else {
value = 129032 / (c->symbol_rate / 1000) + 1;
ds3000_writereg(state, 0xc3, value);
ds3000_writereg(state, 0xc8, 0x0a);
ds3000_writereg(state, 0xc4, 0x05);
ds3000_writereg(state, 0xc7, 0x24);
}
value = (((c->symbol_rate / 1000) << 16) +
(DS3000_SAMPLE_RATE / 2)) / DS3000_SAMPLE_RATE;
ds3000_writereg(state, 0x61, value & 0x00ff);
ds3000_writereg(state, 0x62, (value & 0xff00) >> 8);
ds3000_writereg(state, 0x56, 0x00);
ds3000_writereg(state, 0x76, 0x00);
if (state->config->ci_mode) {
switch (c->delivery_system) {
case SYS_DVBS:
default:
ds3000_writereg(state, 0xfd, 0x80);
break;
case SYS_DVBS2:
ds3000_writereg(state, 0xfd, 0x01);
break;
}
}
ds3000_writereg(state, 0x00, 0x00);
ds3000_writereg(state, 0xb2, 0x00);
ds3000_set_carrier_offset(fe, offset_khz);
for (i = 0; i < 30 ; i++) {
ds3000_read_status(fe, &status);
if (status & FE_HAS_LOCK)
break;
msleep(10);
}
return 0;
}
static int ds3000_tune(struct dvb_frontend *fe,
bool re_tune,
unsigned int mode_flags,
unsigned int *delay,
fe_status_t *status)
{
if (re_tune) {
int ret = ds3000_set_frontend(fe);
if (ret)
return ret;
}
*delay = HZ / 5;
return ds3000_read_status(fe, status);
}
static enum dvbfe_algo ds3000_get_algo(struct dvb_frontend *fe)
{
dprintk("%s()\n", __func__);
return DVBFE_ALGO_HW;
}
static int ds3000_initfe(struct dvb_frontend *fe)
{
struct ds3000_state *state = fe->demodulator_priv;
int ret;
dprintk("%s()\n", __func__);
ds3000_writereg(state, 0x08, 0x01 | ds3000_readreg(state, 0x08));
msleep(1);
ds3000_tuner_writereg(state, 0x42, 0x73);
ds3000_tuner_writereg(state, 0x05, 0x01);
ds3000_tuner_writereg(state, 0x62, 0xf5);
ret = ds3000_firmware_ondemand(fe);
if (ret != 0) {
printk(KERN_ERR "%s: Unable initialize firmware\n", __func__);
return ret;
}
return 0;
}
static int ds3000_sleep(struct dvb_frontend *fe)
{
dprintk("%s()\n", __func__);
return 0;
}
