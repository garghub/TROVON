static int i2c_writebytes (struct or51211_state* state, u8 reg, const u8 *buf,
int len)
{
int err;
struct i2c_msg msg;
msg.addr = reg;
msg.flags = 0;
msg.len = len;
msg.buf = (u8 *)buf;
if ((err = i2c_transfer (state->i2c, &msg, 1)) != 1) {
printk(KERN_WARNING "or51211: i2c_writebytes error "
"(addr %02x, err == %i)\n", reg, err);
return -EREMOTEIO;
}
return 0;
}
static int i2c_readbytes(struct or51211_state *state, u8 reg, u8 *buf, int len)
{
int err;
struct i2c_msg msg;
msg.addr = reg;
msg.flags = I2C_M_RD;
msg.len = len;
msg.buf = buf;
if ((err = i2c_transfer (state->i2c, &msg, 1)) != 1) {
printk(KERN_WARNING "or51211: i2c_readbytes error "
"(addr %02x, err == %i)\n", reg, err);
return -EREMOTEIO;
}
return 0;
}
static int or51211_load_firmware (struct dvb_frontend* fe,
const struct firmware *fw)
{
struct or51211_state* state = fe->demodulator_priv;
u8 tudata[585];
int i;
dprintk("Firmware is %zd bytes\n",fw->size);
tudata[0] = 17;
if (i2c_writebytes(state,0x50,tudata,1)) {
printk(KERN_WARNING "or51211:load_firmware error eprom addr\n");
return -1;
}
if (i2c_readbytes(state,0x50,&tudata[145],192)) {
printk(KERN_WARNING "or51211: load_firmware error eprom\n");
return -1;
}
for (i = 0; i < 145; i++)
tudata[i] = fw->data[i];
for (i = 0; i < 248; i++)
tudata[i+337] = fw->data[145+i];
state->config->reset(fe);
if (i2c_writebytes(state,state->config->demod_address,tudata,585)) {
printk(KERN_WARNING "or51211: load_firmware error 1\n");
return -1;
}
msleep(1);
if (i2c_writebytes(state,state->config->demod_address,
&fw->data[393],8125)) {
printk(KERN_WARNING "or51211: load_firmware error 2\n");
return -1;
}
msleep(1);
if (i2c_writebytes(state,state->config->demod_address,run_buf,2)) {
printk(KERN_WARNING "or51211: load_firmware error 3\n");
return -1;
}
msleep(10);
if (i2c_writebytes(state,state->config->demod_address,run_buf,2)) {
printk(KERN_WARNING "or51211: load_firmware error 4\n");
return -1;
}
msleep(10);
printk("or51211: Done.\n");
return 0;
}
static int or51211_setmode(struct dvb_frontend* fe, int mode)
{
struct or51211_state* state = fe->demodulator_priv;
u8 rec_buf[14];
state->config->setmode(fe, mode);
if (i2c_writebytes(state,state->config->demod_address,run_buf,2)) {
printk(KERN_WARNING "or51211: setmode error 1\n");
return -1;
}
msleep(10);
if (i2c_writebytes(state,state->config->demod_address,run_buf,2)) {
printk(KERN_WARNING "or51211: setmode error 2\n");
return -1;
}
msleep(10);
if (i2c_writebytes(state,state->config->demod_address,cmd_buf,3)) {
printk(KERN_WARNING "or51211: setmode error 3\n");
return -1;
}
rec_buf[0] = 0x04;
rec_buf[1] = 0x00;
rec_buf[2] = 0x03;
rec_buf[3] = 0x00;
msleep(20);
if (i2c_writebytes(state,state->config->demod_address,rec_buf,3)) {
printk(KERN_WARNING "or51211: setmode error 5\n");
}
msleep(3);
if (i2c_readbytes(state,state->config->demod_address,&rec_buf[10],2)) {
printk(KERN_WARNING "or51211: setmode error 6");
return -1;
}
dprintk("setmode rec status %02x %02x\n",rec_buf[10],rec_buf[11]);
return 0;
}
static int or51211_set_parameters(struct dvb_frontend* fe,
struct dvb_frontend_parameters *param)
{
struct or51211_state* state = fe->demodulator_priv;
if (state->current_frequency != param->frequency) {
if (fe->ops.tuner_ops.set_params) {
fe->ops.tuner_ops.set_params(fe, param);
if (fe->ops.i2c_gate_ctrl) fe->ops.i2c_gate_ctrl(fe, 0);
}
or51211_setmode(fe,0);
state->current_frequency = param->frequency;
}
return 0;
}
static int or51211_read_status(struct dvb_frontend* fe, fe_status_t* status)
{
struct or51211_state* state = fe->demodulator_priv;
unsigned char rec_buf[2];
unsigned char snd_buf[] = {0x04,0x00,0x03,0x00};
*status = 0;
if (i2c_writebytes(state,state->config->demod_address,snd_buf,3)) {
printk(KERN_WARNING "or51132: read_status write error\n");
return -1;
}
msleep(3);
if (i2c_readbytes(state,state->config->demod_address,rec_buf,2)) {
printk(KERN_WARNING "or51132: read_status read error\n");
return -1;
}
dprintk("read_status %x %x\n",rec_buf[0],rec_buf[1]);
if (rec_buf[0] & 0x01) {
*status |= FE_HAS_SIGNAL;
*status |= FE_HAS_CARRIER;
*status |= FE_HAS_VITERBI;
*status |= FE_HAS_SYNC;
*status |= FE_HAS_LOCK;
}
return 0;
}
static u32 calculate_snr(u32 mse, u32 c)
{
if (mse == 0)
return 0;
mse = 2*intlog10(mse);
if (mse > c) {
return 0;
}
return 10*(c - mse);
}
static int or51211_read_snr(struct dvb_frontend* fe, u16* snr)
{
struct or51211_state* state = fe->demodulator_priv;
u8 rec_buf[2];
u8 snd_buf[3];
snd_buf[0] = 0x04;
snd_buf[1] = 0x00;
snd_buf[2] = 0x04;
if (i2c_writebytes(state,state->config->demod_address,snd_buf,3)) {
printk(KERN_WARNING "%s: error writing snr reg\n",
__func__);
return -1;
}
if (i2c_readbytes(state,state->config->demod_address,rec_buf,2)) {
printk(KERN_WARNING "%s: read_status read error\n",
__func__);
return -1;
}
state->snr = calculate_snr(rec_buf[0], 89599047);
*snr = (state->snr) >> 16;
dprintk("%s: noise = 0x%02x, snr = %d.%02d dB\n", __func__, rec_buf[0],
state->snr >> 24, (((state->snr>>8) & 0xffff) * 100) >> 16);
return 0;
}
static int or51211_read_signal_strength(struct dvb_frontend* fe, u16* strength)
{
struct or51211_state* state = (struct or51211_state*)fe->demodulator_priv;
u16 snr;
int ret;
ret = fe->ops.read_snr(fe, &snr);
if (ret != 0)
return ret;
if (state->snr >= 8960 * 0x10000)
*strength = 0xffff;
else
*strength = state->snr / 8960;
return 0;
}
static int or51211_read_ber(struct dvb_frontend* fe, u32* ber)
{
*ber = -ENOSYS;
return 0;
}
static int or51211_read_ucblocks(struct dvb_frontend* fe, u32* ucblocks)
{
*ucblocks = -ENOSYS;
return 0;
}
static int or51211_sleep(struct dvb_frontend* fe)
{
return 0;
}
static int or51211_init(struct dvb_frontend* fe)
{
struct or51211_state* state = fe->demodulator_priv;
const struct or51211_config* config = state->config;
const struct firmware* fw;
unsigned char get_ver_buf[] = {0x04,0x00,0x30,0x00,0x00};
unsigned char rec_buf[14];
int ret,i;
if (!state->initialized) {
printk(KERN_INFO "or51211: Waiting for firmware upload "
"(%s)...\n", OR51211_DEFAULT_FIRMWARE);
ret = config->request_firmware(fe, &fw,
OR51211_DEFAULT_FIRMWARE);
printk(KERN_INFO "or51211:Got Hotplug firmware\n");
if (ret) {
printk(KERN_WARNING "or51211: No firmware uploaded "
"(timeout or file not found?)\n");
return ret;
}
ret = or51211_load_firmware(fe, fw);
release_firmware(fw);
if (ret) {
printk(KERN_WARNING "or51211: Writing firmware to "
"device failed!\n");
return ret;
}
printk(KERN_INFO "or51211: Firmware upload complete.\n");
if (i2c_writebytes(state,state->config->demod_address,
cmd_buf,3)) {
printk(KERN_WARNING "or51211: Load DVR Error 5\n");
return -1;
}
rec_buf[0] = 0x04;
rec_buf[1] = 0x00;
rec_buf[2] = 0x03;
rec_buf[3] = 0x00;
msleep(30);
if (i2c_writebytes(state,state->config->demod_address,
rec_buf,3)) {
printk(KERN_WARNING "or51211: Load DVR Error A\n");
return -1;
}
msleep(3);
if (i2c_readbytes(state,state->config->demod_address,
&rec_buf[10],2)) {
printk(KERN_WARNING "or51211: Load DVR Error B\n");
return -1;
}
rec_buf[0] = 0x04;
rec_buf[1] = 0x00;
rec_buf[2] = 0x01;
rec_buf[3] = 0x00;
msleep(20);
if (i2c_writebytes(state,state->config->demod_address,
rec_buf,3)) {
printk(KERN_WARNING "or51211: Load DVR Error C\n");
return -1;
}
msleep(3);
if (i2c_readbytes(state,state->config->demod_address,
&rec_buf[12],2)) {
printk(KERN_WARNING "or51211: Load DVR Error D\n");
return -1;
}
for (i = 0; i < 8; i++)
rec_buf[i]=0xed;
for (i = 0; i < 5; i++) {
msleep(30);
get_ver_buf[4] = i+1;
if (i2c_writebytes(state,state->config->demod_address,
get_ver_buf,5)) {
printk(KERN_WARNING "or51211:Load DVR Error 6"
" - %d\n",i);
return -1;
}
msleep(3);
if (i2c_readbytes(state,state->config->demod_address,
&rec_buf[i*2],2)) {
printk(KERN_WARNING "or51211:Load DVR Error 7"
" - %d\n",i);
return -1;
}
if ((int)rec_buf[i*2+1]!=i+1){
i--;
}
}
dprintk("read_fwbits %x %x %x %x %x %x %x %x %x %x\n",
rec_buf[0], rec_buf[1], rec_buf[2], rec_buf[3],
rec_buf[4], rec_buf[5], rec_buf[6], rec_buf[7],
rec_buf[8], rec_buf[9]);
printk(KERN_INFO "or51211: ver TU%02x%02x%02x VSB mode %02x"
" Status %02x\n",
rec_buf[2], rec_buf[4],rec_buf[6],
rec_buf[12],rec_buf[10]);
rec_buf[0] = 0x04;
rec_buf[1] = 0x00;
rec_buf[2] = 0x03;
rec_buf[3] = 0x00;
msleep(20);
if (i2c_writebytes(state,state->config->demod_address,
rec_buf,3)) {
printk(KERN_WARNING "or51211: Load DVR Error 8\n");
return -1;
}
msleep(20);
if (i2c_readbytes(state,state->config->demod_address,
&rec_buf[8],2)) {
printk(KERN_WARNING "or51211: Load DVR Error 9\n");
return -1;
}
state->initialized = 1;
}
return 0;
}
static int or51211_get_tune_settings(struct dvb_frontend* fe,
struct dvb_frontend_tune_settings* fesettings)
{
fesettings->min_delay_ms = 500;
fesettings->step_size = 0;
fesettings->max_drift = 0;
return 0;
}
static void or51211_release(struct dvb_frontend* fe)
{
struct or51211_state* state = fe->demodulator_priv;
state->config->sleep(fe);
kfree(state);
}
struct dvb_frontend* or51211_attach(const struct or51211_config* config,
struct i2c_adapter* i2c)
{
struct or51211_state* state = NULL;
state = kzalloc(sizeof(struct or51211_state), GFP_KERNEL);
if (state == NULL)
return NULL;
state->config = config;
state->i2c = i2c;
state->initialized = 0;
state->current_frequency = 0;
memcpy(&state->frontend.ops, &or51211_ops, sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
}
