static int or51132_writebuf(struct or51132_state *state, const u8 *buf, int len)
{
int err;
struct i2c_msg msg = { .addr = state->config->demod_address,
.flags = 0, .buf = (u8*)buf, .len = len };
if ((err = i2c_transfer(state->i2c, &msg, 1)) != 1) {
printk(KERN_WARNING "or51132: I2C write (addr 0x%02x len %d) error: %d\n",
msg.addr, msg.len, err);
return -EREMOTEIO;
}
return 0;
}
static int or51132_readbuf(struct or51132_state *state, u8 *buf, int len)
{
int err;
struct i2c_msg msg = { .addr = state->config->demod_address,
.flags = I2C_M_RD, .buf = buf, .len = len };
if ((err = i2c_transfer(state->i2c, &msg, 1)) != 1) {
printk(KERN_WARNING "or51132: I2C read (addr 0x%02x len %d) error: %d\n",
msg.addr, msg.len, err);
return -EREMOTEIO;
}
return 0;
}
static int or51132_readreg(struct or51132_state *state, u8 reg)
{
u8 buf[2] = { 0x04, reg };
struct i2c_msg msg[2] = {
{.addr = state->config->demod_address, .flags = 0,
.buf = buf, .len = 2 },
{.addr = state->config->demod_address, .flags = I2C_M_RD,
.buf = buf, .len = 2 }};
int err;
if ((err = i2c_transfer(state->i2c, msg, 2)) != 2) {
printk(KERN_WARNING "or51132: I2C error reading register %d: %d\n",
reg, err);
return -EREMOTEIO;
}
return buf[0] | (buf[1] << 8);
}
static int or51132_load_firmware (struct dvb_frontend* fe, const struct firmware *fw)
{
struct or51132_state* state = fe->demodulator_priv;
static const u8 run_buf[] = {0x7F,0x01};
u8 rec_buf[8];
u32 firmwareAsize, firmwareBsize;
int i,ret;
dprintk("Firmware is %Zd bytes\n",fw->size);
firmwareAsize = le32_to_cpu(*((__le32*)fw->data));
dprintk("FirmwareA is %i bytes\n",firmwareAsize);
firmwareBsize = le32_to_cpu(*((__le32*)(fw->data+4)));
dprintk("FirmwareB is %i bytes\n",firmwareBsize);
if ((ret = or51132_writebuf(state, &fw->data[8], firmwareAsize))) {
printk(KERN_WARNING "or51132: load_firmware error 1\n");
return ret;
}
if ((ret = or51132_writebuf(state, &fw->data[8+firmwareAsize],
firmwareBsize))) {
printk(KERN_WARNING "or51132: load_firmware error 2\n");
return ret;
}
if ((ret = or51132_writebuf(state, run_buf, 2))) {
printk(KERN_WARNING "or51132: load_firmware error 3\n");
return ret;
}
if ((ret = or51132_writebuf(state, run_buf, 2))) {
printk(KERN_WARNING "or51132: load_firmware error 4\n");
return ret;
}
msleep(50);
if ((ret = or51132_writebytes(state, 0x10, 0x10, 0x00))) {
printk(KERN_WARNING "or51132: load_firmware error a\n");
return ret;
}
if ((ret = or51132_writebytes(state, 0x04, 0x17))) {
printk(KERN_WARNING "or51132: load_firmware error b\n");
return ret;
}
if ((ret = or51132_writebytes(state, 0x00, 0x00))) {
printk(KERN_WARNING "or51132: load_firmware error c\n");
return ret;
}
for (i=0;i<4;i++) {
if ((ret = or51132_readbuf(state, &rec_buf[i*2], 2))) {
printk(KERN_WARNING
"or51132: load_firmware error d - %d\n",i);
return ret;
}
}
printk(KERN_WARNING
"or51132: Version: %02X%02X%02X%02X-%02X%02X%02X%02X (%02X%01X-%01X-%02X%01X-%01X)\n",
rec_buf[1],rec_buf[0],rec_buf[3],rec_buf[2],
rec_buf[5],rec_buf[4],rec_buf[7],rec_buf[6],
rec_buf[3],rec_buf[2]>>4,rec_buf[2]&0x0f,
rec_buf[5],rec_buf[4]>>4,rec_buf[4]&0x0f);
if ((ret = or51132_writebytes(state, 0x10, 0x00, 0x00))) {
printk(KERN_WARNING "or51132: load_firmware error e\n");
return ret;
}
return 0;
}
static int or51132_init(struct dvb_frontend* fe)
{
return 0;
}
static int or51132_read_ber(struct dvb_frontend* fe, u32* ber)
{
*ber = 0;
return 0;
}
static int or51132_read_ucblocks(struct dvb_frontend* fe, u32* ucblocks)
{
*ucblocks = 0;
return 0;
}
static int or51132_sleep(struct dvb_frontend* fe)
{
return 0;
}
static int or51132_setmode(struct dvb_frontend* fe)
{
struct or51132_state* state = fe->demodulator_priv;
u8 cmd_buf1[3] = {0x04, 0x01, 0x5f};
u8 cmd_buf2[3] = {0x1c, 0x00, 0 };
dprintk("setmode %d\n",(int)state->current_modulation);
switch (state->current_modulation) {
case VSB_8:
cmd_buf1[2] = 0x50;
cmd_buf2[1] = 0x03;
cmd_buf2[2] = 0x06;
break;
case QAM_AUTO:
cmd_buf2[2] = 0x4f;
break;
case QAM_256:
cmd_buf2[2] = 0x45;
break;
case QAM_64:
cmd_buf2[2] = 0x43;
break;
default:
printk(KERN_WARNING
"or51132: setmode: Modulation set to unsupported value (%d)\n",
state->current_modulation);
return -EINVAL;
}
if (or51132_writebuf(state, cmd_buf1, 3)) {
printk(KERN_WARNING "or51132: set_mode error 1\n");
return -EREMOTEIO;
}
dprintk("set #1 to %02x\n", cmd_buf1[2]);
if (or51132_writebuf(state, cmd_buf2, 3)) {
printk(KERN_WARNING "or51132: set_mode error 2\n");
return -EREMOTEIO;
}
dprintk("set #6 to 0x%02x%02x\n", cmd_buf2[1], cmd_buf2[2]);
return 0;
}
static int modulation_fw_class(fe_modulation_t modulation)
{
switch(modulation) {
case VSB_8:
return MOD_FWCLASS_VSB;
case QAM_AUTO:
case QAM_64:
case QAM_256:
return MOD_FWCLASS_QAM;
default:
return MOD_FWCLASS_UNKNOWN;
}
}
static int or51132_set_parameters(struct dvb_frontend* fe,
struct dvb_frontend_parameters *param)
{
int ret;
struct or51132_state* state = fe->demodulator_priv;
const struct firmware *fw;
const char *fwname;
int clock_mode;
if (modulation_fw_class(state->current_modulation) !=
modulation_fw_class(param->u.vsb.modulation)) {
switch(modulation_fw_class(param->u.vsb.modulation)) {
case MOD_FWCLASS_VSB:
dprintk("set_parameters VSB MODE\n");
fwname = OR51132_VSB_FIRMWARE;
clock_mode = 0;
break;
case MOD_FWCLASS_QAM:
dprintk("set_parameters QAM MODE\n");
fwname = OR51132_QAM_FIRMWARE;
clock_mode = 1;
break;
default:
printk("or51132: Modulation type(%d) UNSUPPORTED\n",
param->u.vsb.modulation);
return -1;
}
printk("or51132: Waiting for firmware upload(%s)...\n",
fwname);
ret = request_firmware(&fw, fwname, state->i2c->dev.parent);
if (ret) {
printk(KERN_WARNING "or51132: No firmware up"
"loaded(timeout or file not found?)\n");
return ret;
}
ret = or51132_load_firmware(fe, fw);
release_firmware(fw);
if (ret) {
printk(KERN_WARNING "or51132: Writing firmware to "
"device failed!\n");
return ret;
}
printk("or51132: Firmware upload complete.\n");
state->config->set_ts_params(fe, clock_mode);
}
if (state->current_modulation != param->u.vsb.modulation) {
state->current_modulation = param->u.vsb.modulation;
or51132_setmode(fe);
}
if (fe->ops.tuner_ops.set_params) {
fe->ops.tuner_ops.set_params(fe, param);
if (fe->ops.i2c_gate_ctrl) fe->ops.i2c_gate_ctrl(fe, 0);
}
or51132_setmode(fe);
state->current_frequency = param->frequency;
return 0;
}
static int or51132_get_parameters(struct dvb_frontend* fe,
struct dvb_frontend_parameters *param)
{
struct or51132_state* state = fe->demodulator_priv;
int status;
int retry = 1;
start:
if ((status = or51132_readreg(state, 0x00)) < 0) {
printk(KERN_WARNING "or51132: get_parameters: error reading receiver status\n");
return -EREMOTEIO;
}
switch(status&0xff) {
case 0x06: param->u.vsb.modulation = VSB_8; break;
case 0x43: param->u.vsb.modulation = QAM_64; break;
case 0x45: param->u.vsb.modulation = QAM_256; break;
default:
if (retry--) goto start;
printk(KERN_WARNING "or51132: unknown status 0x%02x\n",
status&0xff);
return -EREMOTEIO;
}
param->frequency = state->current_frequency;
param->inversion = INVERSION_AUTO;
return 0;
}
static int or51132_read_status(struct dvb_frontend* fe, fe_status_t* status)
{
struct or51132_state* state = fe->demodulator_priv;
int reg;
if ((reg = or51132_readreg(state, 0x00)) < 0) {
printk(KERN_WARNING "or51132: read_status: error reading receiver status: %d\n", reg);
*status = 0;
return -EREMOTEIO;
}
dprintk("%s: read_status %04x\n", __func__, reg);
if (reg & 0x0100)
*status = FE_HAS_SIGNAL|FE_HAS_CARRIER|FE_HAS_VITERBI|
FE_HAS_SYNC|FE_HAS_LOCK;
else
*status = 0;
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
static int or51132_read_snr(struct dvb_frontend* fe, u16* snr)
{
struct or51132_state* state = fe->demodulator_priv;
int noise, reg;
u32 c, usK = 0;
int retry = 1;
start:
noise = or51132_readreg(state, 0x02);
if (noise < 0) {
printk(KERN_WARNING "or51132: read_snr: error reading equalizer\n");
return -EREMOTEIO;
}
dprintk("read_snr noise (%d)\n", noise);
reg = or51132_readreg(state, 0x00);
if (reg < 0) {
printk(KERN_WARNING "or51132: read_snr: error reading receiver status\n");
return -EREMOTEIO;
}
switch (reg&0xff) {
case 0x06:
if (reg & 0x1000) usK = 3 << 24;
case 0x43:
c = 150204167;
break;
case 0x45:
c = 150290396;
break;
default:
printk(KERN_WARNING "or51132: unknown status 0x%02x\n", reg&0xff);
if (retry--) goto start;
return -EREMOTEIO;
}
dprintk("%s: modulation %02x, NTSC rej O%s\n", __func__,
reg&0xff, reg&0x1000?"n":"ff");
state->snr = calculate_snr(noise, c) - usK;
*snr = (state->snr) >> 16;
dprintk("%s: noise = 0x%08x, snr = %d.%02d dB\n", __func__, noise,
state->snr >> 24, (((state->snr>>8) & 0xffff) * 100) >> 16);
return 0;
}
static int or51132_read_signal_strength(struct dvb_frontend* fe, u16* strength)
{
struct or51132_state* state = (struct or51132_state*) fe->demodulator_priv;
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
static int or51132_get_tune_settings(struct dvb_frontend* fe, struct dvb_frontend_tune_settings* fe_tune_settings)
{
fe_tune_settings->min_delay_ms = 500;
fe_tune_settings->step_size = 0;
fe_tune_settings->max_drift = 0;
return 0;
}
static void or51132_release(struct dvb_frontend* fe)
{
struct or51132_state* state = fe->demodulator_priv;
kfree(state);
}
struct dvb_frontend* or51132_attach(const struct or51132_config* config,
struct i2c_adapter* i2c)
{
struct or51132_state* state = NULL;
state = kzalloc(sizeof(struct or51132_state), GFP_KERNEL);
if (state == NULL)
return NULL;
state->config = config;
state->i2c = i2c;
state->current_frequency = -1;
state->current_modulation = -1;
memcpy(&state->frontend.ops, &or51132_ops, sizeof(struct dvb_frontend_ops));
state->frontend.demodulator_priv = state;
return &state->frontend;
}
