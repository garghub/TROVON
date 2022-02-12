static int _stb0899_read_reg(struct stb0899_state *state, unsigned int reg)
{
int ret;
u8 b0[] = { reg >> 8, reg & 0xff };
u8 buf;
struct i2c_msg msg[] = {
{
.addr = state->config->demod_address,
.flags = 0,
.buf = b0,
.len = 2
},{
.addr = state->config->demod_address,
.flags = I2C_M_RD,
.buf = &buf,
.len = 1
}
};
ret = i2c_transfer(state->i2c, msg, 2);
if (ret != 2) {
if (ret != -ERESTARTSYS)
dprintk(state->verbose, FE_ERROR, 1,
"Read error, Reg=[0x%02x], Status=%d",
reg, ret);
return ret < 0 ? ret : -EREMOTEIO;
}
if (unlikely(*state->verbose >= FE_DEBUGREG))
dprintk(state->verbose, FE_ERROR, 1, "Reg=[0x%02x], data=%02x",
reg, buf);
return (unsigned int)buf;
}
int stb0899_read_reg(struct stb0899_state *state, unsigned int reg)
{
int result;
result = _stb0899_read_reg(state, reg);
if ((reg != 0xf2ff) && (reg != 0xf6ff) &&
(((reg & 0xff00) == 0xf200) || ((reg & 0xff00) == 0xf600)))
_stb0899_read_reg(state, (reg | 0x00ff));
return result;
}
u32 _stb0899_read_s2reg(struct stb0899_state *state,
u32 stb0899_i2cdev,
u32 stb0899_base_addr,
u16 stb0899_reg_offset)
{
int status;
u32 data;
u8 buf[7] = { 0 };
u16 tmpaddr;
u8 buf_0[] = {
GETBYTE(stb0899_i2cdev, BYTE1),
GETBYTE(stb0899_i2cdev, BYTE0),
GETBYTE(stb0899_base_addr, BYTE0),
GETBYTE(stb0899_base_addr, BYTE1),
GETBYTE(stb0899_base_addr, BYTE2),
GETBYTE(stb0899_base_addr, BYTE3),
};
u8 buf_1[] = {
0x00,
0x00,
};
struct i2c_msg msg_0 = {
.addr = state->config->demod_address,
.flags = 0,
.buf = buf_0,
.len = 6
};
struct i2c_msg msg_1 = {
.addr = state->config->demod_address,
.flags = 0,
.buf = buf_1,
.len = 2
};
struct i2c_msg msg_r = {
.addr = state->config->demod_address,
.flags = I2C_M_RD,
.buf = buf,
.len = 4
};
tmpaddr = stb0899_reg_offset & 0xff00;
if (!(stb0899_reg_offset & 0x8))
tmpaddr = stb0899_reg_offset | 0x20;
buf_1[0] = GETBYTE(tmpaddr, BYTE1);
buf_1[1] = GETBYTE(tmpaddr, BYTE0);
status = i2c_transfer(state->i2c, &msg_0, 1);
if (status < 1) {
if (status != -ERESTARTSYS)
printk(KERN_ERR "%s ERR(1), Device=[0x%04x], Base address=[0x%08x], Offset=[0x%04x], Status=%d\n",
__func__, stb0899_i2cdev, stb0899_base_addr, stb0899_reg_offset, status);
goto err;
}
status = i2c_transfer(state->i2c, &msg_1, 1);
if (status < 1)
goto err;
status = i2c_transfer(state->i2c, &msg_r, 1);
if (status < 1)
goto err;
buf_1[0] = GETBYTE(stb0899_reg_offset, BYTE1);
buf_1[1] = GETBYTE(stb0899_reg_offset, BYTE0);
status = i2c_transfer(state->i2c, &msg_1, 1);
if (status < 1) {
if (status != -ERESTARTSYS)
printk(KERN_ERR "%s ERR(2), Device=[0x%04x], Base address=[0x%08x], Offset=[0x%04x], Status=%d\n",
__func__, stb0899_i2cdev, stb0899_base_addr, stb0899_reg_offset, status);
goto err;
}
status = i2c_transfer(state->i2c, &msg_r, 1);
if (status < 1) {
if (status != -ERESTARTSYS)
printk(KERN_ERR "%s ERR(3), Device=[0x%04x], Base address=[0x%08x], Offset=[0x%04x], Status=%d\n",
__func__, stb0899_i2cdev, stb0899_base_addr, stb0899_reg_offset, status);
return status < 0 ? status : -EREMOTEIO;
}
data = MAKEWORD32(buf[3], buf[2], buf[1], buf[0]);
if (unlikely(*state->verbose >= FE_DEBUGREG))
printk(KERN_DEBUG "%s Device=[0x%04x], Base address=[0x%08x], Offset=[0x%04x], Data=[0x%08x]\n",
__func__, stb0899_i2cdev, stb0899_base_addr, stb0899_reg_offset, data);
return data;
err:
return status < 0 ? status : -EREMOTEIO;
}
int stb0899_write_s2reg(struct stb0899_state *state,
u32 stb0899_i2cdev,
u32 stb0899_base_addr,
u16 stb0899_reg_offset,
u32 stb0899_data)
{
int status;
u8 buf_0[] = {
GETBYTE(stb0899_i2cdev, BYTE1),
GETBYTE(stb0899_i2cdev, BYTE0),
GETBYTE(stb0899_base_addr, BYTE0),
GETBYTE(stb0899_base_addr, BYTE1),
GETBYTE(stb0899_base_addr, BYTE2),
GETBYTE(stb0899_base_addr, BYTE3),
};
u8 buf_1[] = {
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
};
struct i2c_msg msg_0 = {
.addr = state->config->demod_address,
.flags = 0,
.buf = buf_0,
.len = 6
};
struct i2c_msg msg_1 = {
.addr = state->config->demod_address,
.flags = 0,
.buf = buf_1,
.len = 6
};
buf_1[0] = GETBYTE(stb0899_reg_offset, BYTE1);
buf_1[1] = GETBYTE(stb0899_reg_offset, BYTE0);
buf_1[2] = GETBYTE(stb0899_data, BYTE0);
buf_1[3] = GETBYTE(stb0899_data, BYTE1);
buf_1[4] = GETBYTE(stb0899_data, BYTE2);
buf_1[5] = GETBYTE(stb0899_data, BYTE3);
if (unlikely(*state->verbose >= FE_DEBUGREG))
printk(KERN_DEBUG "%s Device=[0x%04x], Base Address=[0x%08x], Offset=[0x%04x], Data=[0x%08x]\n",
__func__, stb0899_i2cdev, stb0899_base_addr, stb0899_reg_offset, stb0899_data);
status = i2c_transfer(state->i2c, &msg_0, 1);
if (unlikely(status < 1)) {
if (status != -ERESTARTSYS)
printk(KERN_ERR "%s ERR (1), Device=[0x%04x], Base Address=[0x%08x], Offset=[0x%04x], Data=[0x%08x], status=%d\n",
__func__, stb0899_i2cdev, stb0899_base_addr, stb0899_reg_offset, stb0899_data, status);
goto err;
}
status = i2c_transfer(state->i2c, &msg_1, 1);
if (unlikely(status < 1)) {
if (status != -ERESTARTSYS)
printk(KERN_ERR "%s ERR (2), Device=[0x%04x], Base Address=[0x%08x], Offset=[0x%04x], Data=[0x%08x], status=%d\n",
__func__, stb0899_i2cdev, stb0899_base_addr, stb0899_reg_offset, stb0899_data, status);
return status < 0 ? status : -EREMOTEIO;
}
return 0;
err:
return status < 0 ? status : -EREMOTEIO;
}
int stb0899_read_regs(struct stb0899_state *state, unsigned int reg, u8 *buf, u32 count)
{
int status;
u8 b0[] = { reg >> 8, reg & 0xff };
struct i2c_msg msg[] = {
{
.addr = state->config->demod_address,
.flags = 0,
.buf = b0,
.len = 2
},{
.addr = state->config->demod_address,
.flags = I2C_M_RD,
.buf = buf,
.len = count
}
};
status = i2c_transfer(state->i2c, msg, 2);
if (status != 2) {
if (status != -ERESTARTSYS)
printk(KERN_ERR "%s Read error, Reg=[0x%04x], Count=%u, Status=%d\n",
__func__, reg, count, status);
goto err;
}
if ((reg != 0xf2ff) && (reg != 0xf6ff) &&
(((reg & 0xff00) == 0xf200) || ((reg & 0xff00) == 0xf600)))
_stb0899_read_reg(state, (reg | 0x00ff));
if (unlikely(*state->verbose >= FE_DEBUGREG)) {
int i;
printk(KERN_DEBUG "%s [0x%04x]:", __func__, reg);
for (i = 0; i < count; i++) {
printk(" %02x", buf[i]);
}
printk("\n");
}
return 0;
err:
return status < 0 ? status : -EREMOTEIO;
}
int stb0899_write_regs(struct stb0899_state *state, unsigned int reg, u8 *data, u32 count)
{
int ret;
u8 buf[2 + count];
struct i2c_msg i2c_msg = {
.addr = state->config->demod_address,
.flags = 0,
.buf = buf,
.len = 2 + count
};
buf[0] = reg >> 8;
buf[1] = reg & 0xff;
memcpy(&buf[2], data, count);
if (unlikely(*state->verbose >= FE_DEBUGREG)) {
int i;
printk(KERN_DEBUG "%s [0x%04x]:", __func__, reg);
for (i = 0; i < count; i++)
printk(" %02x", data[i]);
printk("\n");
}
ret = i2c_transfer(state->i2c, &i2c_msg, 1);
if ((((reg & 0xff00) == 0xf200) || ((reg & 0xff00) == 0xf600)))
stb0899_read_reg(state, (reg | 0x00ff));
if (ret != 1) {
if (ret != -ERESTARTSYS)
dprintk(state->verbose, FE_ERROR, 1, "Reg=[0x%04x], Data=[0x%02x ...], Count=%u, Status=%d",
reg, data[0], count, ret);
return ret < 0 ? ret : -EREMOTEIO;
}
return 0;
}
int stb0899_write_reg(struct stb0899_state *state, unsigned int reg, u8 data)
{
return stb0899_write_regs(state, reg, &data, 1);
}
static u32 stb0899_get_mclk(struct stb0899_state *state)
{
u32 mclk = 0, div = 0;
div = stb0899_read_reg(state, STB0899_NCOARSE);
mclk = (div + 1) * state->config->xtal_freq / 6;
dprintk(state->verbose, FE_DEBUG, 1, "div=%d, mclk=%d", div, mclk);
return mclk;
}
static void stb0899_set_mclk(struct stb0899_state *state, u32 Mclk)
{
struct stb0899_internal *internal = &state->internal;
u8 mdiv = 0;
dprintk(state->verbose, FE_DEBUG, 1, "state->config=%p", state->config);
mdiv = ((6 * Mclk) / state->config->xtal_freq) - 1;
dprintk(state->verbose, FE_DEBUG, 1, "mdiv=%d", mdiv);
stb0899_write_reg(state, STB0899_NCOARSE, mdiv);
internal->master_clk = stb0899_get_mclk(state);
dprintk(state->verbose, FE_DEBUG, 1, "MasterCLOCK=%d", internal->master_clk);
}
static int stb0899_postproc(struct stb0899_state *state, u8 ctl, int enable)
{
struct stb0899_config *config = state->config;
const struct stb0899_postproc *postproc = config->postproc;
if (postproc) {
if (enable) {
if (postproc[ctl].level == STB0899_GPIOPULLUP)
stb0899_write_reg(state, postproc[ctl].gpio, 0x02);
else
stb0899_write_reg(state, postproc[ctl].gpio, 0x82);
} else {
if (postproc[ctl].level == STB0899_GPIOPULLUP)
stb0899_write_reg(state, postproc[ctl].gpio, 0x82);
else
stb0899_write_reg(state, postproc[ctl].gpio, 0x02);
}
}
return 0;
}
static void stb0899_release(struct dvb_frontend *fe)
{
struct stb0899_state *state = fe->demodulator_priv;
dprintk(state->verbose, FE_DEBUG, 1, "Release Frontend");
stb0899_postproc(state, STB0899_POSTPROC_GPIO_POWER, 0);
kfree(state);
}
static int stb0899_get_alpha(struct stb0899_state *state)
{
u8 mode_coeff;
mode_coeff = stb0899_read_reg(state, STB0899_DEMOD);
if (STB0899_GETFIELD(MODECOEFF, mode_coeff) == 1)
return 20;
else
return 35;
}
static void stb0899_init_calc(struct stb0899_state *state)
{
struct stb0899_internal *internal = &state->internal;
int master_clk;
u8 agc[2];
u8 agc1cn;
u32 reg;
agc1cn = stb0899_read_reg(state, STB0899_AGC1CN);
stb0899_read_regs(state, STB0899_AGC1REF, agc, 2);
master_clk = stb0899_get_mclk(state);
internal->t_agc1 = 0;
internal->t_agc2 = 0;
internal->master_clk = master_clk;
internal->mclk = master_clk / 65536L;
internal->rolloff = stb0899_get_alpha(state);
internal->agc_gain = 8154;
reg = STB0899_READ_S2REG(STB0899_S2DEMOD, IF_AGC_CNTRL);
STB0899_SETFIELD_VAL(IF_GAIN_INIT, reg, internal->agc_gain);
stb0899_write_s2reg(state, STB0899_S2DEMOD, STB0899_BASE_IF_AGC_CNTRL, STB0899_OFF0_IF_AGC_CNTRL, reg);
reg = STB0899_READ_S2REG(STB0899_S2DEMOD, RRC_ALPHA);
internal->rrc_alpha = STB0899_GETFIELD(RRC_ALPHA, reg);
internal->center_freq = 0;
internal->av_frame_coarse = 10;
internal->av_frame_fine = 20;
internal->step_size = 2;
}
static int stb0899_wait_diseqc_fifo_empty(struct stb0899_state *state, int timeout)
{
u8 reg = 0;
unsigned long start = jiffies;
while (1) {
reg = stb0899_read_reg(state, STB0899_DISSTATUS);
if (!STB0899_GETFIELD(FIFOFULL, reg))
break;
if ((jiffies - start) > timeout) {
dprintk(state->verbose, FE_ERROR, 1, "timed out !!");
return -ETIMEDOUT;
}
}
return 0;
}
static int stb0899_send_diseqc_msg(struct dvb_frontend *fe, struct dvb_diseqc_master_cmd *cmd)
{
struct stb0899_state *state = fe->demodulator_priv;
u8 reg, i;
if (cmd->msg_len > 8)
return -EINVAL;
reg = stb0899_read_reg(state, STB0899_DISCNTRL1);
STB0899_SETFIELD_VAL(DISPRECHARGE, reg, 1);
stb0899_write_reg(state, STB0899_DISCNTRL1, reg);
for (i = 0; i < cmd->msg_len; i++) {
if (stb0899_wait_diseqc_fifo_empty(state, 100) < 0)
return -ETIMEDOUT;
stb0899_write_reg(state, STB0899_DISFIFO, cmd->msg[i]);
}
reg = stb0899_read_reg(state, STB0899_DISCNTRL1);
STB0899_SETFIELD_VAL(DISPRECHARGE, reg, 0);
stb0899_write_reg(state, STB0899_DISCNTRL1, reg);
msleep(100);
return 0;
}
static int stb0899_wait_diseqc_rxidle(struct stb0899_state *state, int timeout)
{
u8 reg = 0;
unsigned long start = jiffies;
while (!STB0899_GETFIELD(RXEND, reg)) {
reg = stb0899_read_reg(state, STB0899_DISRX_ST0);
if (jiffies - start > timeout) {
dprintk(state->verbose, FE_ERROR, 1, "timed out!!");
return -ETIMEDOUT;
}
msleep(10);
}
return 0;
}
static int stb0899_recv_slave_reply(struct dvb_frontend *fe, struct dvb_diseqc_slave_reply *reply)
{
struct stb0899_state *state = fe->demodulator_priv;
u8 reg, length = 0, i;
int result;
if (stb0899_wait_diseqc_rxidle(state, 100) < 0)
return -ETIMEDOUT;
reg = stb0899_read_reg(state, STB0899_DISRX_ST0);
if (STB0899_GETFIELD(RXEND, reg)) {
reg = stb0899_read_reg(state, STB0899_DISRX_ST1);
length = STB0899_GETFIELD(FIFOBYTENBR, reg);
if (length > sizeof (reply->msg)) {
result = -EOVERFLOW;
goto exit;
}
reply->msg_len = length;
for (i = 0; i < length; i++)
reply->msg[i] = stb0899_read_reg(state, STB0899_DISFIFO);
}
return 0;
exit:
return result;
}
static int stb0899_wait_diseqc_txidle(struct stb0899_state *state, int timeout)
{
u8 reg = 0;
unsigned long start = jiffies;
while (!STB0899_GETFIELD(TXIDLE, reg)) {
reg = stb0899_read_reg(state, STB0899_DISSTATUS);
if (jiffies - start > timeout) {
dprintk(state->verbose, FE_ERROR, 1, "timed out!!");
return -ETIMEDOUT;
}
msleep(10);
}
return 0;
}
static int stb0899_send_diseqc_burst(struct dvb_frontend *fe, fe_sec_mini_cmd_t burst)
{
struct stb0899_state *state = fe->demodulator_priv;
u8 reg, old_state;
if (stb0899_wait_diseqc_txidle(state, 100) < 0)
return -ETIMEDOUT;
reg = stb0899_read_reg(state, STB0899_DISCNTRL1);
old_state = reg;
STB0899_SETFIELD_VAL(DISEQCMODE, reg, 0x03);
STB0899_SETFIELD_VAL(DISPRECHARGE, reg, 0x01);
stb0899_write_reg(state, STB0899_DISCNTRL1, reg);
switch (burst) {
case SEC_MINI_A:
stb0899_write_reg(state, STB0899_DISFIFO, 0x00);
break;
case SEC_MINI_B:
stb0899_write_reg(state, STB0899_DISFIFO, 0xff);
break;
}
reg = stb0899_read_reg(state, STB0899_DISCNTRL1);
STB0899_SETFIELD_VAL(DISPRECHARGE, reg, 0x00);
stb0899_write_reg(state, STB0899_DISCNTRL1, reg);
if (stb0899_wait_diseqc_txidle(state, 100) < 0)
return -ETIMEDOUT;
stb0899_write_reg(state, STB0899_DISCNTRL1, old_state);
return 0;
}
static int stb0899_diseqc_init(struct stb0899_state *state)
{
struct dvb_diseqc_master_cmd tx_data;
u8 f22_tx, f22_rx, reg;
u32 mclk, tx_freq = 22000;
tx_data.msg[0] = 0xe2;
tx_data.msg_len = 3;
reg = stb0899_read_reg(state, STB0899_DISCNTRL2);
STB0899_SETFIELD_VAL(ONECHIP_TRX, reg, 0);
stb0899_write_reg(state, STB0899_DISCNTRL2, reg);
reg = stb0899_read_reg(state, STB0899_DISCNTRL1);
STB0899_SETFIELD_VAL(DISEQCRESET, reg, 1);
stb0899_write_reg(state, STB0899_DISCNTRL1, reg);
reg = stb0899_read_reg(state, STB0899_DISCNTRL1);
STB0899_SETFIELD_VAL(DISEQCRESET, reg, 0);
stb0899_write_reg(state, STB0899_DISCNTRL1, reg);
mclk = stb0899_get_mclk(state);
f22_tx = mclk / (tx_freq * 32);
stb0899_write_reg(state, STB0899_DISF22, f22_tx);
state->rx_freq = 20000;
f22_rx = mclk / (state->rx_freq * 32);
return 0;
}
static int stb0899_sleep(struct dvb_frontend *fe)
{
struct stb0899_state *state = fe->demodulator_priv;
dprintk(state->verbose, FE_DEBUG, 1, "Going to Sleep .. (Really tired .. :-))");
stb0899_postproc(state, STB0899_POSTPROC_GPIO_POWER, 0);
return 0;
}
static int stb0899_wakeup(struct dvb_frontend *fe)
{
int rc;
struct stb0899_state *state = fe->demodulator_priv;
if ((rc = stb0899_write_reg(state, STB0899_SYNTCTRL, STB0899_SELOSCI)))
return rc;
if ((rc = stb0899_write_reg(state, STB0899_STOPCLK1, 0x00)))
return rc;
if ((rc = stb0899_write_reg(state, STB0899_STOPCLK2, 0x00)))
return rc;
stb0899_postproc(state, STB0899_POSTPROC_GPIO_POWER, 1);
return 0;
}
static int stb0899_init(struct dvb_frontend *fe)
{
int i;
struct stb0899_state *state = fe->demodulator_priv;
struct stb0899_config *config = state->config;
dprintk(state->verbose, FE_DEBUG, 1, "Initializing STB0899 ... ");
dprintk(state->verbose, FE_DEBUG, 1, "init device");
for (i = 0; config->init_dev[i].address != 0xffff; i++)
stb0899_write_reg(state, config->init_dev[i].address, config->init_dev[i].data);
dprintk(state->verbose, FE_DEBUG, 1, "init S2 demod");
for (i = 0; config->init_s2_demod[i].offset != 0xffff; i++)
stb0899_write_s2reg(state, STB0899_S2DEMOD,
config->init_s2_demod[i].base_address,
config->init_s2_demod[i].offset,
config->init_s2_demod[i].data);
dprintk(state->verbose, FE_DEBUG, 1, "init S1 demod");
for (i = 0; config->init_s1_demod[i].address != 0xffff; i++)
stb0899_write_reg(state, config->init_s1_demod[i].address, config->init_s1_demod[i].data);
dprintk(state->verbose, FE_DEBUG, 1, "init S2 FEC");
for (i = 0; config->init_s2_fec[i].offset != 0xffff; i++)
stb0899_write_s2reg(state, STB0899_S2FEC,
config->init_s2_fec[i].base_address,
config->init_s2_fec[i].offset,
config->init_s2_fec[i].data);
dprintk(state->verbose, FE_DEBUG, 1, "init TST");
for (i = 0; config->init_tst[i].address != 0xffff; i++)
stb0899_write_reg(state, config->init_tst[i].address, config->init_tst[i].data);
stb0899_init_calc(state);
stb0899_diseqc_init(state);
return 0;
}
static int stb0899_table_lookup(const struct stb0899_tab *tab, int max, int val)
{
int res = 0;
int min = 0, med;
if (val < tab[min].read)
res = tab[min].real;
else if (val >= tab[max].read)
res = tab[max].real;
else {
while ((max - min) > 1) {
med = (max + min) / 2;
if (val >= tab[min].read && val < tab[med].read)
max = med;
else
min = med;
}
res = ((val - tab[min].read) *
(tab[max].real - tab[min].real) /
(tab[max].read - tab[min].read)) +
tab[min].real;
}
return res;
}
static int stb0899_read_signal_strength(struct dvb_frontend *fe, u16 *strength)
{
struct stb0899_state *state = fe->demodulator_priv;
struct stb0899_internal *internal = &state->internal;
int val;
u32 reg;
switch (state->delsys) {
case SYS_DVBS:
case SYS_DSS:
if (internal->lock) {
reg = stb0899_read_reg(state, STB0899_VSTATUS);
if (STB0899_GETFIELD(VSTATUS_LOCKEDVIT, reg)) {
reg = stb0899_read_reg(state, STB0899_AGCIQIN);
val = (s32)(s8)STB0899_GETFIELD(AGCIQVALUE, reg);
*strength = stb0899_table_lookup(stb0899_dvbsrf_tab, ARRAY_SIZE(stb0899_dvbsrf_tab) - 1, val);
*strength += 750;
dprintk(state->verbose, FE_DEBUG, 1, "AGCIQVALUE = 0x%02x, C = %d * 0.1 dBm",
val & 0xff, *strength);
}
}
break;
case SYS_DVBS2:
if (internal->lock) {
reg = STB0899_READ_S2REG(STB0899_DEMOD, IF_AGC_GAIN);
val = STB0899_GETFIELD(IF_AGC_GAIN, reg);
*strength = stb0899_table_lookup(stb0899_dvbs2rf_tab, ARRAY_SIZE(stb0899_dvbs2rf_tab) - 1, val);
*strength += 750;
dprintk(state->verbose, FE_DEBUG, 1, "IF_AGC_GAIN = 0x%04x, C = %d * 0.1 dBm",
val & 0x3fff, *strength);
}
break;
default:
dprintk(state->verbose, FE_DEBUG, 1, "Unsupported delivery system");
return -EINVAL;
}
return 0;
}
static int stb0899_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct stb0899_state *state = fe->demodulator_priv;
struct stb0899_internal *internal = &state->internal;
unsigned int val, quant, quantn = -1, est, estn = -1;
u8 buf[2];
u32 reg;
reg = stb0899_read_reg(state, STB0899_VSTATUS);
switch (state->delsys) {
case SYS_DVBS:
case SYS_DSS:
if (internal->lock) {
if (STB0899_GETFIELD(VSTATUS_LOCKEDVIT, reg)) {
stb0899_read_regs(state, STB0899_NIRM, buf, 2);
val = MAKEWORD16(buf[0], buf[1]);
*snr = stb0899_table_lookup(stb0899_cn_tab, ARRAY_SIZE(stb0899_cn_tab) - 1, val);
dprintk(state->verbose, FE_DEBUG, 1, "NIR = 0x%02x%02x = %u, C/N = %d * 0.1 dBm\n",
buf[0], buf[1], val, *snr);
}
}
break;
case SYS_DVBS2:
if (internal->lock) {
reg = STB0899_READ_S2REG(STB0899_S2DEMOD, UWP_CNTRL1);
quant = STB0899_GETFIELD(UWP_ESN0_QUANT, reg);
reg = STB0899_READ_S2REG(STB0899_S2DEMOD, UWP_STAT2);
est = STB0899_GETFIELD(ESN0_EST, reg);
if (est == 1)
val = 301;
else if (est == 2)
val = 270;
else {
quantn = stb0899_table_lookup(stb0899_quant_tab, ARRAY_SIZE(stb0899_quant_tab) - 1, quant * 100);
estn = stb0899_table_lookup(stb0899_est_tab, ARRAY_SIZE(stb0899_est_tab) - 1, est);
val = (quantn - estn) / 10;
}
*snr = val;
dprintk(state->verbose, FE_DEBUG, 1, "Es/N0 quant = %d (%d) estimate = %u (%d), C/N = %d * 0.1 dBm",
quant, quantn, est, estn, val);
}
break;
default:
dprintk(state->verbose, FE_DEBUG, 1, "Unsupported delivery system");
return -EINVAL;
}
return 0;
}
static int stb0899_read_status(struct dvb_frontend *fe, enum fe_status *status)
{
struct stb0899_state *state = fe->demodulator_priv;
struct stb0899_internal *internal = &state->internal;
u8 reg;
*status = 0;
switch (state->delsys) {
case SYS_DVBS:
case SYS_DSS:
dprintk(state->verbose, FE_DEBUG, 1, "Delivery system DVB-S/DSS");
if (internal->lock) {
reg = stb0899_read_reg(state, STB0899_VSTATUS);
if (STB0899_GETFIELD(VSTATUS_LOCKEDVIT, reg)) {
dprintk(state->verbose, FE_DEBUG, 1, "--------> FE_HAS_CARRIER | FE_HAS_LOCK");
*status |= FE_HAS_CARRIER | FE_HAS_LOCK;
reg = stb0899_read_reg(state, STB0899_PLPARM);
if (STB0899_GETFIELD(VITCURPUN, reg)) {
dprintk(state->verbose, FE_DEBUG, 1, "--------> FE_HAS_VITERBI | FE_HAS_SYNC");
*status |= FE_HAS_VITERBI | FE_HAS_SYNC;
stb0899_postproc(state, STB0899_POSTPROC_GPIO_LOCK, 1);
}
}
}
break;
case SYS_DVBS2:
dprintk(state->verbose, FE_DEBUG, 1, "Delivery system DVB-S2");
if (internal->lock) {
reg = STB0899_READ_S2REG(STB0899_S2DEMOD, DMD_STAT2);
if (STB0899_GETFIELD(UWP_LOCK, reg) && STB0899_GETFIELD(CSM_LOCK, reg)) {
*status |= FE_HAS_CARRIER;
dprintk(state->verbose, FE_DEBUG, 1,
"UWP & CSM Lock ! ---> DVB-S2 FE_HAS_CARRIER");
reg = stb0899_read_reg(state, STB0899_CFGPDELSTATUS1);
if (STB0899_GETFIELD(CFGPDELSTATUS_LOCK, reg)) {
*status |= FE_HAS_LOCK;
dprintk(state->verbose, FE_DEBUG, 1,
"Packet Delineator Locked ! -----> DVB-S2 FE_HAS_LOCK");
}
if (STB0899_GETFIELD(CONTINUOUS_STREAM, reg)) {
*status |= FE_HAS_VITERBI;
dprintk(state->verbose, FE_DEBUG, 1,
"Packet Delineator found VITERBI ! -----> DVB-S2 FE_HAS_VITERBI");
}
if (STB0899_GETFIELD(ACCEPTED_STREAM, reg)) {
*status |= FE_HAS_SYNC;
dprintk(state->verbose, FE_DEBUG, 1,
"Packet Delineator found SYNC ! -----> DVB-S2 FE_HAS_SYNC");
stb0899_postproc(state, STB0899_POSTPROC_GPIO_LOCK, 1);
}
}
}
break;
default:
dprintk(state->verbose, FE_DEBUG, 1, "Unsupported delivery system");
return -EINVAL;
}
return 0;
}
static int stb0899_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct stb0899_state *state = fe->demodulator_priv;
struct stb0899_internal *internal = &state->internal;
u8 lsb, msb;
u32 i;
*ber = 0;
switch (state->delsys) {
case SYS_DVBS:
case SYS_DSS:
if (internal->lock) {
for (i = 0; i < 5; i++) {
msleep(100);
lsb = stb0899_read_reg(state, STB0899_ECNT1L);
msb = stb0899_read_reg(state, STB0899_ECNT1M);
*ber += MAKEWORD16(msb, lsb);
}
*ber /= 5;
if (STB0899_GETFIELD(VSTATUS_PRFVIT, internal->v_status)) {
*ber *= 9766;
*ber /= (-1 + (1 << (2 * STB0899_GETFIELD(NOE, internal->err_ctrl))));
*ber /= 8;
}
}
break;
case SYS_DVBS2:
if (internal->lock) {
for (i = 0; i < 5; i++) {
msleep(100);
lsb = stb0899_read_reg(state, STB0899_ECNT1L);
msb = stb0899_read_reg(state, STB0899_ECNT1M);
*ber += MAKEWORD16(msb, lsb);
}
*ber *= 10000000;
*ber /= (-1 + (1 << (4 + 2 * STB0899_GETFIELD(NOE, internal->err_ctrl))));
}
break;
default:
dprintk(state->verbose, FE_DEBUG, 1, "Unsupported delivery system");
return -EINVAL;
}
return 0;
}
static int stb0899_set_voltage(struct dvb_frontend *fe, fe_sec_voltage_t voltage)
{
struct stb0899_state *state = fe->demodulator_priv;
switch (voltage) {
case SEC_VOLTAGE_13:
stb0899_write_reg(state, STB0899_GPIO00CFG, 0x82);
stb0899_write_reg(state, STB0899_GPIO01CFG, 0x02);
stb0899_write_reg(state, STB0899_GPIO02CFG, 0x00);
break;
case SEC_VOLTAGE_18:
stb0899_write_reg(state, STB0899_GPIO00CFG, 0x02);
stb0899_write_reg(state, STB0899_GPIO01CFG, 0x02);
stb0899_write_reg(state, STB0899_GPIO02CFG, 0x82);
break;
case SEC_VOLTAGE_OFF:
stb0899_write_reg(state, STB0899_GPIO00CFG, 0x82);
stb0899_write_reg(state, STB0899_GPIO01CFG, 0x82);
stb0899_write_reg(state, STB0899_GPIO02CFG, 0x82);
break;
default:
return -EINVAL;
}
return 0;
}
static int stb0899_set_tone(struct dvb_frontend *fe, fe_sec_tone_mode_t tone)
{
struct stb0899_state *state = fe->demodulator_priv;
struct stb0899_internal *internal = &state->internal;
u8 div, reg;
if (stb0899_wait_diseqc_txidle(state, 100) < 0)
return -ETIMEDOUT;
switch (tone) {
case SEC_TONE_ON:
div = (internal->master_clk / 100) / 5632;
div = (div + 5) / 10;
stb0899_write_reg(state, STB0899_DISEQCOCFG, 0x66);
reg = stb0899_read_reg(state, STB0899_ACRPRESC);
STB0899_SETFIELD_VAL(ACRPRESC, reg, 0x03);
stb0899_write_reg(state, STB0899_ACRPRESC, reg);
stb0899_write_reg(state, STB0899_ACRDIV1, div);
break;
case SEC_TONE_OFF:
stb0899_write_reg(state, STB0899_DISEQCOCFG, 0x20);
break;
default:
return -EINVAL;
}
return 0;
}
int stb0899_i2c_gate_ctrl(struct dvb_frontend *fe, int enable)
{
int i2c_stat;
struct stb0899_state *state = fe->demodulator_priv;
i2c_stat = stb0899_read_reg(state, STB0899_I2CRPT);
if (i2c_stat < 0)
goto err;
if (enable) {
dprintk(state->verbose, FE_DEBUG, 1, "Enabling I2C Repeater ...");
i2c_stat |= STB0899_I2CTON;
if (stb0899_write_reg(state, STB0899_I2CRPT, i2c_stat) < 0)
goto err;
} else {
dprintk(state->verbose, FE_DEBUG, 1, "Disabling I2C Repeater ...");
i2c_stat &= ~STB0899_I2CTON;
if (stb0899_write_reg(state, STB0899_I2CRPT, i2c_stat) < 0)
goto err;
}
return 0;
err:
dprintk(state->verbose, FE_ERROR, 1, "I2C Repeater control failed");
return -EREMOTEIO;
}
static inline void CONVERT32(u32 x, char *str)
{
*str++ = (x >> 24) & 0xff;
*str++ = (x >> 16) & 0xff;
*str++ = (x >> 8) & 0xff;
*str++ = (x >> 0) & 0xff;
*str = '\0';
}
int stb0899_get_dev_id(struct stb0899_state *state)
{
u8 chip_id, release;
u16 id;
u32 demod_ver = 0, fec_ver = 0;
char demod_str[5] = { 0 };
char fec_str[5] = { 0 };
id = stb0899_read_reg(state, STB0899_DEV_ID);
dprintk(state->verbose, FE_DEBUG, 1, "ID reg=[0x%02x]", id);
chip_id = STB0899_GETFIELD(CHIP_ID, id);
release = STB0899_GETFIELD(CHIP_REL, id);
dprintk(state->verbose, FE_ERROR, 1, "Device ID=[%d], Release=[%d]",
chip_id, release);
CONVERT32(STB0899_READ_S2REG(STB0899_S2DEMOD, DMD_CORE_ID), (char *)&demod_str);
demod_ver = STB0899_READ_S2REG(STB0899_S2DEMOD, DMD_VERSION_ID);
dprintk(state->verbose, FE_ERROR, 1, "Demodulator Core ID=[%s], Version=[%d]", (char *) &demod_str, demod_ver);
CONVERT32(STB0899_READ_S2REG(STB0899_S2FEC, FEC_CORE_ID_REG), (char *)&fec_str);
fec_ver = STB0899_READ_S2REG(STB0899_S2FEC, FEC_VER_ID_REG);
if (! (chip_id > 0)) {
dprintk(state->verbose, FE_ERROR, 1, "couldn't find a STB 0899");
return -ENODEV;
}
dprintk(state->verbose, FE_ERROR, 1, "FEC Core ID=[%s], Version=[%d]", (char*) &fec_str, fec_ver);
return 0;
}
static void stb0899_set_delivery(struct stb0899_state *state)
{
u8 reg;
u8 stop_clk[2];
stop_clk[0] = stb0899_read_reg(state, STB0899_STOPCLK1);
stop_clk[1] = stb0899_read_reg(state, STB0899_STOPCLK2);
switch (state->delsys) {
case SYS_DVBS:
dprintk(state->verbose, FE_DEBUG, 1, "Delivery System -- DVB-S");
reg = stb0899_read_reg(state, STB0899_FECM);
STB0899_SETFIELD_VAL(FECM_RSVD0, reg, 0);
STB0899_SETFIELD_VAL(FECM_VITERBI_ON, reg, 1);
stb0899_write_reg(state, STB0899_FECM, reg);
stb0899_write_reg(state, STB0899_RSULC, 0xb1);
stb0899_write_reg(state, STB0899_TSULC, 0x40);
stb0899_write_reg(state, STB0899_RSLLC, 0x42);
stb0899_write_reg(state, STB0899_TSLPL, 0x12);
reg = stb0899_read_reg(state, STB0899_TSTRES);
STB0899_SETFIELD_VAL(FRESLDPC, reg, 1);
stb0899_write_reg(state, STB0899_TSTRES, reg);
STB0899_SETFIELD_VAL(STOP_CHK8PSK, stop_clk[0], 1);
STB0899_SETFIELD_VAL(STOP_CKFEC108, stop_clk[0], 1);
STB0899_SETFIELD_VAL(STOP_CKFEC216, stop_clk[0], 1);
STB0899_SETFIELD_VAL(STOP_CKPKDLIN108, stop_clk[1], 1);
STB0899_SETFIELD_VAL(STOP_CKPKDLIN216, stop_clk[1], 1);
STB0899_SETFIELD_VAL(STOP_CKINTBUF216, stop_clk[0], 1);
STB0899_SETFIELD_VAL(STOP_CKCORE216, stop_clk[0], 0);
STB0899_SETFIELD_VAL(STOP_CKS2DMD108, stop_clk[1], 1);
break;
case SYS_DVBS2:
reg = stb0899_read_reg(state, STB0899_FECM);
STB0899_SETFIELD_VAL(FECM_RSVD0, reg, 0);
STB0899_SETFIELD_VAL(FECM_VITERBI_ON, reg, 0);
stb0899_write_reg(state, STB0899_FECM, reg);
stb0899_write_reg(state, STB0899_RSULC, 0xb1);
stb0899_write_reg(state, STB0899_TSULC, 0x42);
stb0899_write_reg(state, STB0899_RSLLC, 0x40);
stb0899_write_reg(state, STB0899_TSLPL, 0x02);
reg = stb0899_read_reg(state, STB0899_TSTRES);
STB0899_SETFIELD_VAL(FRESLDPC, reg, 0);
stb0899_write_reg(state, STB0899_TSTRES, reg);
STB0899_SETFIELD_VAL(STOP_CHK8PSK, stop_clk[0], 1);
STB0899_SETFIELD_VAL(STOP_CKFEC108, stop_clk[0], 0);
STB0899_SETFIELD_VAL(STOP_CKFEC216, stop_clk[0], 0);
STB0899_SETFIELD_VAL(STOP_CKPKDLIN108, stop_clk[1], 0);
STB0899_SETFIELD_VAL(STOP_CKPKDLIN216, stop_clk[1], 0);
STB0899_SETFIELD_VAL(STOP_CKINTBUF216, stop_clk[0], 0);
STB0899_SETFIELD_VAL(STOP_CKCORE216, stop_clk[0], 0);
STB0899_SETFIELD_VAL(STOP_CKS2DMD108, stop_clk[1], 0);
break;
case SYS_DSS:
reg = stb0899_read_reg(state, STB0899_FECM);
STB0899_SETFIELD_VAL(FECM_RSVD0, reg, 1);
STB0899_SETFIELD_VAL(FECM_VITERBI_ON, reg, 1);
stb0899_write_reg(state, STB0899_FECM, reg);
stb0899_write_reg(state, STB0899_RSULC, 0xa1);
stb0899_write_reg(state, STB0899_TSULC, 0x61);
stb0899_write_reg(state, STB0899_RSLLC, 0x42);
reg = stb0899_read_reg(state, STB0899_TSTRES);
STB0899_SETFIELD_VAL(FRESLDPC, reg, 1);
stb0899_write_reg(state, STB0899_TSTRES, reg);
STB0899_SETFIELD_VAL(STOP_CHK8PSK, stop_clk[0], 1);
STB0899_SETFIELD_VAL(STOP_CKFEC108, stop_clk[0], 1);
STB0899_SETFIELD_VAL(STOP_CKFEC216, stop_clk[0], 1);
STB0899_SETFIELD_VAL(STOP_CKPKDLIN108, stop_clk[1], 1);
STB0899_SETFIELD_VAL(STOP_CKPKDLIN216, stop_clk[1], 1);
STB0899_SETFIELD_VAL(STOP_CKCORE216, stop_clk[0], 0);
STB0899_SETFIELD_VAL(STOP_CKS2DMD108, stop_clk[1], 1);
break;
default:
dprintk(state->verbose, FE_ERROR, 1, "Unsupported delivery system");
break;
}
STB0899_SETFIELD_VAL(STOP_CKADCI108, stop_clk[0], 0);
stb0899_write_regs(state, STB0899_STOPCLK1, stop_clk, 2);
}
static void stb0899_set_iterations(struct stb0899_state *state)
{
struct stb0899_internal *internal = &state->internal;
struct stb0899_config *config = state->config;
s32 iter_scale;
u32 reg;
iter_scale = 17 * (internal->master_clk / 1000);
iter_scale += 410000;
iter_scale /= (internal->srate / 1000000);
iter_scale /= 1000;
if (iter_scale > config->ldpc_max_iter)
iter_scale = config->ldpc_max_iter;
reg = STB0899_READ_S2REG(STB0899_S2FEC, MAX_ITER);
STB0899_SETFIELD_VAL(MAX_ITERATIONS, reg, iter_scale);
stb0899_write_s2reg(state, STB0899_S2FEC, STB0899_BASE_MAX_ITER, STB0899_OFF0_MAX_ITER, reg);
}
static enum dvbfe_search stb0899_search(struct dvb_frontend *fe, struct dvb_frontend_parameters *p)
{
struct stb0899_state *state = fe->demodulator_priv;
struct stb0899_params *i_params = &state->params;
struct stb0899_internal *internal = &state->internal;
struct stb0899_config *config = state->config;
struct dtv_frontend_properties *props = &fe->dtv_property_cache;
u32 SearchRange, gain;
i_params->freq = p->frequency;
i_params->srate = p->u.qpsk.symbol_rate;
state->delsys = props->delivery_system;
dprintk(state->verbose, FE_DEBUG, 1, "delivery system=%d", state->delsys);
SearchRange = 10000000;
dprintk(state->verbose, FE_DEBUG, 1, "Frequency=%d, Srate=%d", i_params->freq, i_params->srate);
if (INRANGE(i_params->srate, 1000000, 45000000)) {
dprintk(state->verbose, FE_DEBUG, 1, "Parameters IN RANGE");
stb0899_set_delivery(state);
if (state->config->tuner_set_rfsiggain) {
if (internal->srate > 15000000)
gain = 8;
else if (internal->srate > 5000000)
gain = 12;
else
gain = 14;
state->config->tuner_set_rfsiggain(fe, gain);
}
if (i_params->srate <= 5000000)
stb0899_set_mclk(state, config->lo_clk);
else
stb0899_set_mclk(state, config->hi_clk);
switch (state->delsys) {
case SYS_DVBS:
case SYS_DSS:
dprintk(state->verbose, FE_DEBUG, 1, "DVB-S delivery system");
internal->freq = i_params->freq;
internal->srate = i_params->srate;
internal->srch_range = SearchRange + 1500000 + (i_params->srate / 5);
internal->derot_percent = 30;
stb0899_i2c_gate_ctrl(&state->frontend, 1);
if (state->config->tuner_set_bandwidth)
state->config->tuner_set_bandwidth(fe, (13 * (stb0899_carr_width(state) + SearchRange)) / 10);
if (state->config->tuner_get_bandwidth)
state->config->tuner_get_bandwidth(fe, &internal->tuner_bw);
stb0899_i2c_gate_ctrl(&state->frontend, 0);
stb0899_write_reg(state, STB0899_AGCRFCFG, 0x11);
dprintk(state->verbose, FE_DEBUG, 1, "running DVB-S search algo ..");
if (stb0899_dvbs_algo(state) == RANGEOK) {
internal->lock = 1;
dprintk(state->verbose, FE_DEBUG, 1,
"-------------------------------------> DVB-S LOCK !");
return DVBFE_ALGO_SEARCH_SUCCESS;
} else {
internal->lock = 0;
return DVBFE_ALGO_SEARCH_FAILED;
}
break;
case SYS_DVBS2:
internal->freq = i_params->freq;
internal->srate = i_params->srate;
internal->srch_range = SearchRange;
stb0899_i2c_gate_ctrl(&state->frontend, 1);
if (state->config->tuner_set_bandwidth)
state->config->tuner_set_bandwidth(fe, (stb0899_carr_width(state) + SearchRange));
if (state->config->tuner_get_bandwidth)
state->config->tuner_get_bandwidth(fe, &internal->tuner_bw);
stb0899_i2c_gate_ctrl(&state->frontend, 0);
stb0899_write_reg(state, STB0899_AGCRFCFG, 0x1c);
stb0899_set_iterations(state);
dprintk(state->verbose, FE_DEBUG, 1, "running DVB-S2 search algo ..");
if (stb0899_dvbs2_algo(state) == DVBS2_FEC_LOCK) {
internal->lock = 1;
dprintk(state->verbose, FE_DEBUG, 1,
"-------------------------------------> DVB-S2 LOCK !");
return DVBFE_ALGO_SEARCH_SUCCESS;
} else {
internal->lock = 0;
return DVBFE_ALGO_SEARCH_FAILED;
}
break;
default:
dprintk(state->verbose, FE_ERROR, 1, "Unsupported delivery system");
return DVBFE_ALGO_SEARCH_INVALID;
}
}
return DVBFE_ALGO_SEARCH_ERROR;
}
static int stb0899_track(struct dvb_frontend *fe, struct dvb_frontend_parameters *p)
{
return 0;
}
static int stb0899_get_frontend(struct dvb_frontend *fe, struct dvb_frontend_parameters *p)
{
struct stb0899_state *state = fe->demodulator_priv;
struct stb0899_internal *internal = &state->internal;
dprintk(state->verbose, FE_DEBUG, 1, "Get params");
p->u.qpsk.symbol_rate = internal->srate;
return 0;
}
static enum dvbfe_algo stb0899_frontend_algo(struct dvb_frontend *fe)
{
return DVBFE_ALGO_CUSTOM;
}
struct dvb_frontend *stb0899_attach(struct stb0899_config *config, struct i2c_adapter *i2c)
{
struct stb0899_state *state = NULL;
enum stb0899_inversion inversion;
state = kzalloc(sizeof (struct stb0899_state), GFP_KERNEL);
if (state == NULL)
goto error;
inversion = config->inversion;
state->verbose = &verbose;
state->config = config;
state->i2c = i2c;
state->frontend.ops = stb0899_ops;
state->frontend.demodulator_priv = state;
state->internal.inversion = inversion;
stb0899_wakeup(&state->frontend);
if (stb0899_get_dev_id(state) == -ENODEV) {
printk("%s: Exiting .. !\n", __func__);
goto error;
}
printk("%s: Attaching STB0899 \n", __func__);
return &state->frontend;
error:
kfree(state);
return NULL;
}
