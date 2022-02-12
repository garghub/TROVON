static
int stv0367_writeregs(struct stv0367_state *state, u16 reg, u8 *data, int len)
{
u8 buf[len + 2];
struct i2c_msg msg = {
.addr = state->config->demod_address,
.flags = 0,
.buf = buf,
.len = len + 2
};
int ret;
buf[0] = MSB(reg);
buf[1] = LSB(reg);
memcpy(buf + 2, data, len);
if (i2cdebug)
printk(KERN_DEBUG "%s: %02x: %02x\n", __func__, reg, buf[2]);
ret = i2c_transfer(state->i2c, &msg, 1);
if (ret != 1)
printk(KERN_ERR "%s: i2c write error!\n", __func__);
return (ret != 1) ? -EREMOTEIO : 0;
}
static int stv0367_writereg(struct stv0367_state *state, u16 reg, u8 data)
{
return stv0367_writeregs(state, reg, &data, 1);
}
static u8 stv0367_readreg(struct stv0367_state *state, u16 reg)
{
u8 b0[] = { 0, 0 };
u8 b1[] = { 0 };
struct i2c_msg msg[] = {
{
.addr = state->config->demod_address,
.flags = 0,
.buf = b0,
.len = 2
}, {
.addr = state->config->demod_address,
.flags = I2C_M_RD,
.buf = b1,
.len = 1
}
};
int ret;
b0[0] = MSB(reg);
b0[1] = LSB(reg);
ret = i2c_transfer(state->i2c, msg, 2);
if (ret != 2)
printk(KERN_ERR "%s: i2c read error\n", __func__);
if (i2cdebug)
printk(KERN_DEBUG "%s: %02x: %02x\n", __func__, reg, b1[0]);
return b1[0];
}
static void extract_mask_pos(u32 label, u8 *mask, u8 *pos)
{
u8 position = 0, i = 0;
(*mask) = label & 0xff;
while ((position == 0) && (i < 8)) {
position = ((*mask) >> i) & 0x01;
i++;
}
(*pos) = (i - 1);
}
static void stv0367_writebits(struct stv0367_state *state, u32 label, u8 val)
{
u8 reg, mask, pos;
reg = stv0367_readreg(state, (label >> 16) & 0xffff);
extract_mask_pos(label, &mask, &pos);
val = mask & (val << pos);
reg = (reg & (~mask)) | val;
stv0367_writereg(state, (label >> 16) & 0xffff, reg);
}
static void stv0367_setbits(u8 *reg, u32 label, u8 val)
{
u8 mask, pos;
extract_mask_pos(label, &mask, &pos);
val = mask & (val << pos);
(*reg) = ((*reg) & (~mask)) | val;
}
static u8 stv0367_readbits(struct stv0367_state *state, u32 label)
{
u8 val = 0xff;
u8 mask, pos;
extract_mask_pos(label, &mask, &pos);
val = stv0367_readreg(state, label >> 16);
val = (val & mask) >> pos;
return val;
}
u8 stv0367_getbits(u8 reg, u32 label)
{
u8 mask, pos;
extract_mask_pos(label, &mask, &pos);
return (reg & mask) >> pos;
}
static int stv0367ter_gate_ctrl(struct dvb_frontend *fe, int enable)
{
struct stv0367_state *state = fe->demodulator_priv;
u8 tmp = stv0367_readreg(state, R367TER_I2CRPT);
dprintk("%s:\n", __func__);
if (enable) {
stv0367_setbits(&tmp, F367TER_STOP_ENABLE, 0);
stv0367_setbits(&tmp, F367TER_I2CT_ON, 1);
} else {
stv0367_setbits(&tmp, F367TER_STOP_ENABLE, 1);
stv0367_setbits(&tmp, F367TER_I2CT_ON, 0);
}
stv0367_writereg(state, R367TER_I2CRPT, tmp);
return 0;
}
static u32 stv0367_get_tuner_freq(struct dvb_frontend *fe)
{
struct dvb_frontend_ops *frontend_ops = NULL;
struct dvb_tuner_ops *tuner_ops = NULL;
u32 freq = 0;
int err = 0;
dprintk("%s:\n", __func__);
if (&fe->ops)
frontend_ops = &fe->ops;
if (&frontend_ops->tuner_ops)
tuner_ops = &frontend_ops->tuner_ops;
if (tuner_ops->get_frequency) {
err = tuner_ops->get_frequency(fe, &freq);
if (err < 0) {
printk(KERN_ERR "%s: Invalid parameter\n", __func__);
return err;
}
dprintk("%s: frequency=%d\n", __func__, freq);
} else
return -1;
return freq;
}
static u32 stv0367ter_get_mclk(struct stv0367_state *state, u32 ExtClk_Hz)
{
u32 mclk_Hz = 0;
u32 m, n, p;
dprintk("%s:\n", __func__);
if (stv0367_readbits(state, F367TER_BYPASS_PLLXN) == 0) {
n = (u32)stv0367_readbits(state, F367TER_PLL_NDIV);
if (n == 0)
n = n + 1;
m = (u32)stv0367_readbits(state, F367TER_PLL_MDIV);
if (m == 0)
m = m + 1;
p = (u32)stv0367_readbits(state, F367TER_PLL_PDIV);
if (p > 5)
p = 5;
mclk_Hz = ((ExtClk_Hz / 2) * n) / (m * (1 << p));
dprintk("N=%d M=%d P=%d mclk_Hz=%d ExtClk_Hz=%d\n",
n, m, p, mclk_Hz, ExtClk_Hz);
} else
mclk_Hz = ExtClk_Hz;
dprintk("%s: mclk_Hz=%d\n", __func__, mclk_Hz);
return mclk_Hz;
}
static int stv0367ter_filt_coeff_init(struct stv0367_state *state,
u16 CellsCoeffs[3][6][5], u32 DemodXtal)
{
int i, j, k, freq;
dprintk("%s:\n", __func__);
freq = stv0367ter_get_mclk(state, DemodXtal);
if (freq == 53125000)
k = 1;
else if (freq == 54000000)
k = 0;
else if (freq == 52500000)
k = 2;
else
return 0;
for (i = 1; i <= 6; i++) {
stv0367_writebits(state, F367TER_IIR_CELL_NB, i - 1);
for (j = 1; j <= 5; j++) {
stv0367_writereg(state,
(R367TER_IIRCX_COEFF1_MSB + 2 * (j - 1)),
MSB(CellsCoeffs[k][i-1][j-1]));
stv0367_writereg(state,
(R367TER_IIRCX_COEFF1_LSB + 2 * (j - 1)),
LSB(CellsCoeffs[k][i-1][j-1]));
}
}
return 1;
}
static void stv0367ter_agc_iir_lock_detect_set(struct stv0367_state *state)
{
dprintk("%s:\n", __func__);
stv0367_writebits(state, F367TER_LOCK_DETECT_LSB, 0x00);
stv0367_writebits(state, F367TER_LOCK_DETECT_CHOICE, 0x00);
stv0367_writebits(state, F367TER_LOCK_DETECT_MSB, 0x06);
stv0367_writebits(state, F367TER_AUT_AGC_TARGET_LSB, 0x04);
stv0367_writebits(state, F367TER_LOCK_DETECT_CHOICE, 0x01);
stv0367_writebits(state, F367TER_LOCK_DETECT_MSB, 0x06);
stv0367_writebits(state, F367TER_AUT_AGC_TARGET_LSB, 0x04);
stv0367_writebits(state, F367TER_LOCK_DETECT_CHOICE, 0x02);
stv0367_writebits(state, F367TER_LOCK_DETECT_MSB, 0x01);
stv0367_writebits(state, F367TER_AUT_AGC_TARGET_LSB, 0x00);
stv0367_writebits(state, F367TER_LOCK_DETECT_CHOICE, 0x03);
stv0367_writebits(state, F367TER_LOCK_DETECT_MSB, 0x01);
stv0367_writebits(state, F367TER_AUT_AGC_TARGET_LSB, 0x00);
}
static int stv0367_iir_filt_init(struct stv0367_state *state, u8 Bandwidth,
u32 DemodXtalValue)
{
dprintk("%s:\n", __func__);
stv0367_writebits(state, F367TER_NRST_IIR, 0);
switch (Bandwidth) {
case 6:
if (!stv0367ter_filt_coeff_init(state,
CellsCoeffs_6MHz_367cofdm,
DemodXtalValue))
return 0;
break;
case 7:
if (!stv0367ter_filt_coeff_init(state,
CellsCoeffs_7MHz_367cofdm,
DemodXtalValue))
return 0;
break;
case 8:
if (!stv0367ter_filt_coeff_init(state,
CellsCoeffs_8MHz_367cofdm,
DemodXtalValue))
return 0;
break;
default:
return 0;
}
stv0367_writebits(state, F367TER_NRST_IIR, 1);
return 1;
}
static void stv0367ter_agc_iir_rst(struct stv0367_state *state)
{
u8 com_n;
dprintk("%s:\n", __func__);
com_n = stv0367_readbits(state, F367TER_COM_N);
stv0367_writebits(state, F367TER_COM_N, 0x07);
stv0367_writebits(state, F367TER_COM_SOFT_RSTN, 0x00);
stv0367_writebits(state, F367TER_COM_AGC_ON, 0x00);
stv0367_writebits(state, F367TER_COM_SOFT_RSTN, 0x01);
stv0367_writebits(state, F367TER_COM_AGC_ON, 0x01);
stv0367_writebits(state, F367TER_COM_N, com_n);
}
static int stv0367ter_duration(s32 mode, int tempo1, int tempo2, int tempo3)
{
int local_tempo = 0;
switch (mode) {
case 0:
local_tempo = tempo1;
break;
case 1:
local_tempo = tempo2;
break ;
case 2:
local_tempo = tempo3;
break;
default:
break;
}
return local_tempo;
}
static enum
stv0367_ter_signal_type stv0367ter_check_syr(struct stv0367_state *state)
{
int wd = 100;
unsigned short int SYR_var;
s32 SYRStatus;
dprintk("%s:\n", __func__);
SYR_var = stv0367_readbits(state, F367TER_SYR_LOCK);
while ((!SYR_var) && (wd > 0)) {
usleep_range(2000, 3000);
wd -= 2;
SYR_var = stv0367_readbits(state, F367TER_SYR_LOCK);
}
if (!SYR_var)
SYRStatus = FE_TER_NOSYMBOL;
else
SYRStatus = FE_TER_SYMBOLOK;
dprintk("stv0367ter_check_syr SYRStatus %s\n",
SYR_var == 0 ? "No Symbol" : "OK");
return SYRStatus;
}
static enum
stv0367_ter_signal_type stv0367ter_check_cpamp(struct stv0367_state *state,
s32 FFTmode)
{
s32 CPAMPvalue = 0, CPAMPStatus, CPAMPMin;
int wd = 0;
dprintk("%s:\n", __func__);
switch (FFTmode) {
case 0:
CPAMPMin = 20;
wd = 10;
break;
case 1:
CPAMPMin = 80;
wd = 55;
break;
case 2:
CPAMPMin = 40;
wd = 30;
break;
default:
CPAMPMin = 0xffff;
break;
}
dprintk("%s: CPAMPMin=%d wd=%d\n", __func__, CPAMPMin, wd);
CPAMPvalue = stv0367_readbits(state, F367TER_PPM_CPAMP_DIRECT);
while ((CPAMPvalue < CPAMPMin) && (wd > 0)) {
usleep_range(1000, 2000);
wd -= 1;
CPAMPvalue = stv0367_readbits(state, F367TER_PPM_CPAMP_DIRECT);
}
dprintk("******last CPAMPvalue= %d at wd=%d\n", CPAMPvalue, wd);
if (CPAMPvalue < CPAMPMin) {
CPAMPStatus = FE_TER_NOCPAMP;
printk(KERN_ERR "CPAMP failed\n");
} else {
printk(KERN_ERR "CPAMP OK !\n");
CPAMPStatus = FE_TER_CPAMPOK;
}
return CPAMPStatus;
}
enum
stv0367_ter_signal_type stv0367ter_lock_algo(struct stv0367_state *state)
{
enum stv0367_ter_signal_type ret_flag;
short int wd, tempo;
u8 try, u_var1 = 0, u_var2 = 0, u_var3 = 0, u_var4 = 0, mode, guard;
u8 tmp, tmp2;
dprintk("%s:\n", __func__);
if (state == NULL)
return FE_TER_SWNOK;
try = 0;
do {
ret_flag = FE_TER_LOCKOK;
stv0367_writebits(state, F367TER_CORE_ACTIVE, 0);
if (state->config->if_iq_mode != 0)
stv0367_writebits(state, F367TER_COM_N, 0x07);
stv0367_writebits(state, F367TER_GUARD, 3);
stv0367_writebits(state, F367TER_MODE, 0);
stv0367_writebits(state, F367TER_SYR_TR_DIS, 0);
usleep_range(5000, 10000);
stv0367_writebits(state, F367TER_CORE_ACTIVE, 1);
if (stv0367ter_check_syr(state) == FE_TER_NOSYMBOL)
return FE_TER_NOSYMBOL;
else {
mode = stv0367_readbits(state, F367TER_SYR_MODE);
if (stv0367ter_check_cpamp(state, mode) ==
FE_TER_NOCPAMP) {
if (try == 0)
ret_flag = FE_TER_NOCPAMP;
}
}
try++;
} while ((try < 10) && (ret_flag != FE_TER_LOCKOK));
tmp = stv0367_readreg(state, R367TER_SYR_STAT);
tmp2 = stv0367_readreg(state, R367TER_STATUS);
dprintk("state=%p\n", state);
dprintk("LOCK OK! mode=%d SYR_STAT=0x%x R367TER_STATUS=0x%x\n",
mode, tmp, tmp2);
tmp = stv0367_readreg(state, R367TER_PRVIT);
tmp2 = stv0367_readreg(state, R367TER_I2CRPT);
dprintk("PRVIT=0x%x I2CRPT=0x%x\n", tmp, tmp2);
tmp = stv0367_readreg(state, R367TER_GAIN_SRC1);
dprintk("GAIN_SRC1=0x%x\n", tmp);
if ((mode != 0) && (mode != 1) && (mode != 2))
return FE_TER_SWNOK;
#if 0
switch (guard) {
case 0:
case 1:
stv0367_writebits(state, F367TER_AUTO_LE_EN, 0);
stv0367_writereg(state, R367TER_CHC_CTL, 0x01);
break;
case 2:
case 3:
stv0367_writebits(state, F367TER_AUTO_LE_EN, 1);
stv0367_writereg(state, R367TER_CHC_CTL, 0x11);
break;
default:
return FE_TER_SWNOK;
}
#endif
stv0367_writebits(state, F367TER_RST_SFEC, 1);
stv0367_writebits(state, F367TER_RST_REEDSOLO, 1);
usleep_range(1000, 2000);
stv0367_writebits(state, F367TER_RST_SFEC, 0);
stv0367_writebits(state, F367TER_RST_REEDSOLO, 0);
u_var1 = stv0367_readbits(state, F367TER_LK);
u_var2 = stv0367_readbits(state, F367TER_PRF);
u_var3 = stv0367_readbits(state, F367TER_TPS_LOCK);
wd = stv0367ter_duration(mode, 125, 500, 250);
tempo = stv0367ter_duration(mode, 4, 16, 8);
while (((!u_var1) || (!u_var2) || (!u_var3)) && (wd >= 0)) {
usleep_range(1000 * tempo, 1000 * (tempo + 1));
wd -= tempo;
u_var1 = stv0367_readbits(state, F367TER_LK);
u_var2 = stv0367_readbits(state, F367TER_PRF);
u_var3 = stv0367_readbits(state, F367TER_TPS_LOCK);
}
if (!u_var1)
return FE_TER_NOLOCK;
if (!u_var2)
return FE_TER_NOPRFOUND;
if (!u_var3)
return FE_TER_NOTPS;
guard = stv0367_readbits(state, F367TER_SYR_GUARD);
stv0367_writereg(state, R367TER_CHC_CTL, 0x11);
switch (guard) {
case 0:
case 1:
stv0367_writebits(state, F367TER_AUTO_LE_EN, 0);
stv0367_writebits(state, F367TER_SYR_FILTER, 0);
break;
case 2:
case 3:
stv0367_writebits(state, F367TER_AUTO_LE_EN, 1);
stv0367_writebits(state, F367TER_SYR_FILTER, 1);
break;
default:
return FE_TER_SWNOK;
}
if ((stv0367_readbits(state, F367TER_TPS_CONST) == 2) &&
(mode == 1) &&
(stv0367_readbits(state, F367TER_TPS_HPCODE) != 0)) {
stv0367_writereg(state, R367TER_SFDLYSETH, 0xc0);
stv0367_writereg(state, R367TER_SFDLYSETM, 0x60);
stv0367_writereg(state, R367TER_SFDLYSETL, 0x0);
} else
stv0367_writereg(state, R367TER_SFDLYSETH, 0x0);
wd = stv0367ter_duration(mode, 125, 500, 250);
u_var4 = stv0367_readbits(state, F367TER_TSFIFO_LINEOK);
while ((!u_var4) && (wd >= 0)) {
usleep_range(1000 * tempo, 1000 * (tempo + 1));
wd -= tempo;
u_var4 = stv0367_readbits(state, F367TER_TSFIFO_LINEOK);
}
if (!u_var4)
return FE_TER_NOLOCK;
stv0367_writebits(state, F367TER_SYR_TR_DIS, 1);
dprintk("FE_TER_LOCKOK !!!\n");
return FE_TER_LOCKOK;
}
static void stv0367ter_set_ts_mode(struct stv0367_state *state,
enum stv0367_ts_mode PathTS)
{
dprintk("%s:\n", __func__);
if (state == NULL)
return;
stv0367_writebits(state, F367TER_TS_DIS, 0);
switch (PathTS) {
default:
case STV0367_PARALLEL_PUNCT_CLOCK:
stv0367_writebits(state, F367TER_TSFIFO_SERIAL, 0);
stv0367_writebits(state, F367TER_TSFIFO_DVBCI, 0);
break;
case STV0367_SERIAL_PUNCT_CLOCK:
stv0367_writebits(state, F367TER_TSFIFO_SERIAL, 1);
stv0367_writebits(state, F367TER_TSFIFO_DVBCI, 1);
break;
}
}
static void stv0367ter_set_clk_pol(struct stv0367_state *state,
enum stv0367_clk_pol clock)
{
dprintk("%s:\n", __func__);
if (state == NULL)
return;
switch (clock) {
case STV0367_RISINGEDGE_CLOCK:
stv0367_writebits(state, F367TER_TS_BYTE_CLK_INV, 1);
break;
case STV0367_FALLINGEDGE_CLOCK:
stv0367_writebits(state, F367TER_TS_BYTE_CLK_INV, 0);
break;
default:
stv0367_writebits(state, F367TER_TS_BYTE_CLK_INV, 0);
break;
}
}
static int stv0367ter_standby(struct dvb_frontend *fe, u8 standby_on)
{
struct stv0367_state *state = fe->demodulator_priv;
dprintk("%s:\n", __func__);
if (standby_on) {
stv0367_writebits(state, F367TER_STDBY, 1);
stv0367_writebits(state, F367TER_STDBY_FEC, 1);
stv0367_writebits(state, F367TER_STDBY_CORE, 1);
} else {
stv0367_writebits(state, F367TER_STDBY, 0);
stv0367_writebits(state, F367TER_STDBY_FEC, 0);
stv0367_writebits(state, F367TER_STDBY_CORE, 0);
}
return 0;
}
static int stv0367ter_sleep(struct dvb_frontend *fe)
{
return stv0367ter_standby(fe, 1);
}
int stv0367ter_init(struct dvb_frontend *fe)
{
struct stv0367_state *state = fe->demodulator_priv;
struct stv0367ter_state *ter_state = state->ter_state;
int i;
dprintk("%s:\n", __func__);
ter_state->pBER = 0;
for (i = 0; i < STV0367TER_NBREGS; i++)
stv0367_writereg(state, def0367ter[i].addr,
def0367ter[i].value);
switch (state->config->xtal) {
case 25000000:
stv0367_writereg(state, R367TER_PLLMDIV, 0xa);
stv0367_writereg(state, R367TER_PLLNDIV, 0x55);
stv0367_writereg(state, R367TER_PLLSETUP, 0x18);
break;
default:
case 27000000:
dprintk("FE_STV0367TER_SetCLKgen for 27Mhz\n");
stv0367_writereg(state, R367TER_PLLMDIV, 0x1);
stv0367_writereg(state, R367TER_PLLNDIV, 0x8);
stv0367_writereg(state, R367TER_PLLSETUP, 0x18);
break;
case 30000000:
stv0367_writereg(state, R367TER_PLLMDIV, 0xc);
stv0367_writereg(state, R367TER_PLLNDIV, 0x55);
stv0367_writereg(state, R367TER_PLLSETUP, 0x18);
break;
}
stv0367_writereg(state, R367TER_I2CRPT, 0xa0);
stv0367_writereg(state, R367TER_ANACTRL, 0x00);
stv0367ter_set_ts_mode(state, state->config->ts_mode);
stv0367ter_set_clk_pol(state, state->config->clk_pol);
state->chip_id = stv0367_readreg(state, R367TER_ID);
ter_state->first_lock = 0;
ter_state->unlock_counter = 2;
return 0;
}
static int stv0367ter_algo(struct dvb_frontend *fe,
struct dvb_frontend_parameters *param)
{
struct stv0367_state *state = fe->demodulator_priv;
struct stv0367ter_state *ter_state = state->ter_state;
int offset = 0, tempo = 0;
u8 u_var;
u8 counter, tps_rcvd[2];
s8 step;
s32 timing_offset = 0;
u32 trl_nomrate = 0, InternalFreq = 0, temp = 0;
dprintk("%s:\n", __func__);
ter_state->frequency = param->frequency;
ter_state->force = FE_TER_FORCENONE
+ stv0367_readbits(state, F367TER_FORCE) * 2;
ter_state->if_iq_mode = state->config->if_iq_mode;
switch (state->config->if_iq_mode) {
case FE_TER_NORMAL_IF_TUNER:
dprintk("ALGO: FE_TER_NORMAL_IF_TUNER selected\n");
stv0367_writebits(state, F367TER_TUNER_BB, 0);
stv0367_writebits(state, F367TER_LONGPATH_IF, 0);
stv0367_writebits(state, F367TER_DEMUX_SWAP, 0);
break;
case FE_TER_LONGPATH_IF_TUNER:
dprintk("ALGO: FE_TER_LONGPATH_IF_TUNER selected\n");
stv0367_writebits(state, F367TER_TUNER_BB, 0);
stv0367_writebits(state, F367TER_LONGPATH_IF, 1);
stv0367_writebits(state, F367TER_DEMUX_SWAP, 1);
break;
case FE_TER_IQ_TUNER:
dprintk("ALGO: FE_TER_IQ_TUNER selected\n");
stv0367_writebits(state, F367TER_TUNER_BB, 1);
stv0367_writebits(state, F367TER_PPM_INVSEL, 0);
break;
default:
printk(KERN_ERR "ALGO: wrong TUNER type selected\n");
return -EINVAL;
}
usleep_range(5000, 7000);
switch (param->inversion) {
case INVERSION_AUTO:
default:
dprintk("%s: inversion AUTO\n", __func__);
if (ter_state->if_iq_mode == FE_TER_IQ_TUNER)
stv0367_writebits(state, F367TER_IQ_INVERT,
ter_state->sense);
else
stv0367_writebits(state, F367TER_INV_SPECTR,
ter_state->sense);
break;
case INVERSION_ON:
case INVERSION_OFF:
if (ter_state->if_iq_mode == FE_TER_IQ_TUNER)
stv0367_writebits(state, F367TER_IQ_INVERT,
param->inversion);
else
stv0367_writebits(state, F367TER_INV_SPECTR,
param->inversion);
break;
}
if ((ter_state->if_iq_mode != FE_TER_NORMAL_IF_TUNER) &&
(ter_state->pBW != ter_state->bw)) {
stv0367ter_agc_iir_lock_detect_set(state);
stv0367_writebits(state, F367TER_SEL_IQNTAR, 1);
stv0367_writebits(state, F367TER_AUT_AGC_TARGET_MSB, 0xB);
stv0367_writebits(state, F367TER_SEL_IQNTAR, 0);
stv0367_writebits(state, F367TER_AUT_AGC_TARGET_MSB, 0xB);
if (!stv0367_iir_filt_init(state, ter_state->bw,
state->config->xtal))
return -EINVAL;
ter_state->pBW = ter_state->bw;
stv0367ter_agc_iir_rst(state);
}
if (ter_state->hierarchy == FE_TER_HIER_LOW_PRIO)
stv0367_writebits(state, F367TER_BDI_LPSEL, 0x01);
else
stv0367_writebits(state, F367TER_BDI_LPSEL, 0x00);
InternalFreq = stv0367ter_get_mclk(state, state->config->xtal) / 1000;
temp = (int)
((((ter_state->bw * 64 * (1 << 15) * 100)
/ (InternalFreq)) * 10) / 7);
stv0367_writebits(state, F367TER_TRL_NOMRATE_LSB, temp % 2);
temp = temp / 2;
stv0367_writebits(state, F367TER_TRL_NOMRATE_HI, temp / 256);
stv0367_writebits(state, F367TER_TRL_NOMRATE_LO, temp % 256);
temp = stv0367_readbits(state, F367TER_TRL_NOMRATE_HI) * 512 +
stv0367_readbits(state, F367TER_TRL_NOMRATE_LO) * 2 +
stv0367_readbits(state, F367TER_TRL_NOMRATE_LSB);
temp = (int)(((1 << 17) * ter_state->bw * 1000) / (7 * (InternalFreq)));
stv0367_writebits(state, F367TER_GAIN_SRC_HI, temp / 256);
stv0367_writebits(state, F367TER_GAIN_SRC_LO, temp % 256);
temp = stv0367_readbits(state, F367TER_GAIN_SRC_HI) * 256 +
stv0367_readbits(state, F367TER_GAIN_SRC_LO);
temp = (int)
((InternalFreq - state->config->if_khz) * (1 << 16)
/ (InternalFreq));
dprintk("DEROT temp=0x%x\n", temp);
stv0367_writebits(state, F367TER_INC_DEROT_HI, temp / 256);
stv0367_writebits(state, F367TER_INC_DEROT_LO, temp % 256);
ter_state->echo_pos = 0;
ter_state->ucblocks = 0;
ter_state->pBER = 0;
stv0367_writebits(state, F367TER_LONG_ECHO, ter_state->echo_pos);
if (stv0367ter_lock_algo(state) != FE_TER_LOCKOK)
return 0;
ter_state->state = FE_TER_LOCKOK;
tps_rcvd[0] = stv0367_readreg(state, R367TER_TPS_RCVD2);
tps_rcvd[1] = stv0367_readreg(state, R367TER_TPS_RCVD3);
ter_state->mode = stv0367_readbits(state, F367TER_SYR_MODE);
ter_state->guard = stv0367_readbits(state, F367TER_SYR_GUARD);
ter_state->first_lock = 1;
ter_state->agc_val =
(stv0367_readbits(state, F367TER_AGC1_VAL_LO) << 16) +
(stv0367_readbits(state, F367TER_AGC1_VAL_HI) << 24) +
stv0367_readbits(state, F367TER_AGC2_VAL_LO) +
(stv0367_readbits(state, F367TER_AGC2_VAL_HI) << 8);
stv0367_writebits(state, F367TER_FREEZE, 1);
offset = (stv0367_readbits(state, F367TER_CRL_FOFFSET_VHI) << 16) ;
offset += (stv0367_readbits(state, F367TER_CRL_FOFFSET_HI) << 8);
offset += (stv0367_readbits(state, F367TER_CRL_FOFFSET_LO));
stv0367_writebits(state, F367TER_FREEZE, 0);
if (offset > 8388607)
offset -= 16777216;
offset = offset * 2 / 16384;
if (ter_state->mode == FE_TER_MODE_2K)
offset = (offset * 4464) / 1000;
else if (ter_state->mode == FE_TER_MODE_4K)
offset = (offset * 223) / 100;
else if (ter_state->mode == FE_TER_MODE_8K)
offset = (offset * 111) / 100;
if (stv0367_readbits(state, F367TER_PPM_INVSEL) == 1) {
if ((stv0367_readbits(state, F367TER_INV_SPECTR) ==
(stv0367_readbits(state,
F367TER_STATUS_INV_SPECRUM) == 1)))
offset = offset * -1;
}
if (ter_state->bw == 6)
offset = (offset * 6) / 8;
else if (ter_state->bw == 7)
offset = (offset * 7) / 8;
ter_state->frequency += offset;
tempo = 10;
while ((timing_offset == 0) && (tempo > 0)) {
usleep_range(10000, 20000);
timing_offset = stv0367_readbits(state, F367TER_TRL_TOFFSET_LO)
+ 256 * stv0367_readbits(state,
F367TER_TRL_TOFFSET_HI);
if (timing_offset >= 32768)
timing_offset -= 65536;
trl_nomrate = (512 * stv0367_readbits(state,
F367TER_TRL_NOMRATE_HI)
+ stv0367_readbits(state, F367TER_TRL_NOMRATE_LO) * 2
+ stv0367_readbits(state, F367TER_TRL_NOMRATE_LSB));
timing_offset = ((signed)(1000000 / trl_nomrate) *
timing_offset) / 2048;
tempo--;
}
if (timing_offset <= 0) {
timing_offset = (timing_offset - 11) / 22;
step = -1;
} else {
timing_offset = (timing_offset + 11) / 22;
step = 1;
}
for (counter = 0; counter < abs(timing_offset); counter++) {
trl_nomrate += step;
stv0367_writebits(state, F367TER_TRL_NOMRATE_LSB,
trl_nomrate % 2);
stv0367_writebits(state, F367TER_TRL_NOMRATE_LO,
trl_nomrate / 2);
usleep_range(1000, 2000);
}
usleep_range(5000, 6000);
u_var = stv0367_readbits(state, F367TER_LK);
if (!u_var) {
stv0367_writebits(state, F367TER_CORE_ACTIVE, 0);
msleep(20);
stv0367_writebits(state, F367TER_CORE_ACTIVE, 1);
}
return 0;
}
static int stv0367ter_set_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *param)
{
struct dvb_ofdm_parameters *op = &param->u.ofdm;
struct stv0367_state *state = fe->demodulator_priv;
struct stv0367ter_state *ter_state = state->ter_state;
s8 num_trials, index;
u8 SenseTrials[] = { INVERSION_ON, INVERSION_OFF };
stv0367ter_init(fe);
if (fe->ops.tuner_ops.set_params) {
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
fe->ops.tuner_ops.set_params(fe, param);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
}
switch (op->transmission_mode) {
default:
case TRANSMISSION_MODE_AUTO:
case TRANSMISSION_MODE_2K:
ter_state->mode = FE_TER_MODE_2K;
break;
case TRANSMISSION_MODE_8K:
ter_state->mode = FE_TER_MODE_8K;
break;
}
switch (op->guard_interval) {
default:
case GUARD_INTERVAL_1_32:
case GUARD_INTERVAL_1_16:
case GUARD_INTERVAL_1_8:
case GUARD_INTERVAL_1_4:
ter_state->guard = op->guard_interval;
break;
case GUARD_INTERVAL_AUTO:
ter_state->guard = GUARD_INTERVAL_1_32;
break;
}
switch (op->bandwidth) {
case BANDWIDTH_6_MHZ:
ter_state->bw = FE_TER_CHAN_BW_6M;
break;
case BANDWIDTH_7_MHZ:
ter_state->bw = FE_TER_CHAN_BW_7M;
break;
case BANDWIDTH_8_MHZ:
default:
ter_state->bw = FE_TER_CHAN_BW_8M;
}
ter_state->hierarchy = FE_TER_HIER_NONE;
switch (param->inversion) {
case INVERSION_OFF:
case INVERSION_ON:
num_trials = 1;
break;
default:
num_trials = 2;
if (ter_state->first_lock)
num_trials = 1;
break;
}
ter_state->state = FE_TER_NOLOCK;
index = 0;
while (((index) < num_trials) && (ter_state->state != FE_TER_LOCKOK)) {
if (!ter_state->first_lock) {
if (param->inversion == INVERSION_AUTO)
ter_state->sense = SenseTrials[index];
}
stv0367ter_algo(fe, param);
if ((ter_state->state == FE_TER_LOCKOK) &&
(param->inversion == INVERSION_AUTO) &&
(index == 1)) {
SenseTrials[index] = SenseTrials[0];
SenseTrials[(index + 1) % 2] = (SenseTrials[1] + 1) % 2;
}
index++;
}
return 0;
}
static int stv0367ter_read_ucblocks(struct dvb_frontend *fe, u32 *ucblocks)
{
struct stv0367_state *state = fe->demodulator_priv;
struct stv0367ter_state *ter_state = state->ter_state;
u32 errs = 0;
if (stv0367_readbits(state, F367TER_SFERRC_OLDVALUE) == 0) {
errs =
((u32)stv0367_readbits(state, F367TER_ERR_CNT1)
* (1 << 16))
+ ((u32)stv0367_readbits(state, F367TER_ERR_CNT1_HI)
* (1 << 8))
+ ((u32)stv0367_readbits(state, F367TER_ERR_CNT1_LO));
ter_state->ucblocks = errs;
}
(*ucblocks) = ter_state->ucblocks;
return 0;
}
static int stv0367ter_get_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *param)
{
struct stv0367_state *state = fe->demodulator_priv;
struct stv0367ter_state *ter_state = state->ter_state;
struct dvb_ofdm_parameters *op = &param->u.ofdm;
struct dtv_frontend_properties *c = &fe->dtv_property_cache;
int error = 0;
enum stv0367_ter_mode mode;
int constell = 0, Data = 0;
param->frequency = stv0367_get_tuner_freq(fe);
if ((int)param->frequency < 0)
param->frequency = c->frequency;
constell = stv0367_readbits(state, F367TER_TPS_CONST);
if (constell == 0)
op->constellation = QPSK;
else if (constell == 1)
op->constellation = QAM_16;
else
op->constellation = QAM_64;
param->inversion = stv0367_readbits(state, F367TER_INV_SPECTR);
Data = stv0367_readbits(state, F367TER_TPS_HIERMODE);
switch (Data) {
case 0:
op->hierarchy_information = HIERARCHY_NONE;
break;
case 1:
op->hierarchy_information = HIERARCHY_1;
break;
case 2:
op->hierarchy_information = HIERARCHY_2;
break;
case 3:
op->hierarchy_information = HIERARCHY_4;
break;
default:
op->hierarchy_information = HIERARCHY_AUTO;
break;
}
if (ter_state->hierarchy == FE_TER_HIER_LOW_PRIO)
Data = stv0367_readbits(state, F367TER_TPS_LPCODE);
else
Data = stv0367_readbits(state, F367TER_TPS_HPCODE);
switch (Data) {
case 0:
op->code_rate_HP = FEC_1_2;
break;
case 1:
op->code_rate_HP = FEC_2_3;
break;
case 2:
op->code_rate_HP = FEC_3_4;
break;
case 3:
op->code_rate_HP = FEC_5_6;
break;
case 4:
op->code_rate_HP = FEC_7_8;
break;
default:
op->code_rate_HP = FEC_AUTO;
break;
}
mode = stv0367_readbits(state, F367TER_SYR_MODE);
switch (mode) {
case FE_TER_MODE_2K:
op->transmission_mode = TRANSMISSION_MODE_2K;
break;
case FE_TER_MODE_8K:
op->transmission_mode = TRANSMISSION_MODE_8K;
break;
default:
op->transmission_mode = TRANSMISSION_MODE_AUTO;
}
op->guard_interval = stv0367_readbits(state, F367TER_SYR_GUARD);
return error;
}
static int stv0367ter_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct stv0367_state *state = fe->demodulator_priv;
u32 snru32 = 0;
int cpt = 0;
u8 cut = stv0367_readbits(state, F367TER_IDENTIFICATIONREG);
while (cpt < 10) {
usleep_range(2000, 3000);
if (cut == 0x50)
snru32 += stv0367_readbits(state, F367TER_CHCSNR) / 4;
else
snru32 += 125 * stv0367_readbits(state, F367TER_CHCSNR);
cpt++;
}
snru32 /= 10;
*snr = snru32 / 1000;
return 0;
}
static int stv0367ter_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct stv0367_state *state = fe->demodulator_priv;
dprintk("%s:\n", __func__);
*status = 0;
if (stv0367_readbits(state, F367TER_LK)) {
*status |= FE_HAS_LOCK;
dprintk("%s: stv0367 has locked\n", __func__);
}
return 0;
}
static int stv0367ter_read_ber(struct dvb_frontend *fe, u32 *ber)
{
struct stv0367_state *state = fe->demodulator_priv;
struct stv0367ter_state *ter_state = state->ter_state;
u32 Errors = 0, tber = 0, temporary = 0;
int abc = 0, def = 0;
if (stv0367_readbits(state, F367TER_SFERRC_OLDVALUE) == 0)
Errors = ((u32)stv0367_readbits(state, F367TER_SFEC_ERR_CNT)
* (1 << 16))
+ ((u32)stv0367_readbits(state, F367TER_SFEC_ERR_CNT_HI)
* (1 << 8))
+ ((u32)stv0367_readbits(state,
F367TER_SFEC_ERR_CNT_LO));
else {
tber = ter_state->pBER;
return 0;
}
abc = stv0367_readbits(state, F367TER_SFEC_ERR_SOURCE);
def = stv0367_readbits(state, F367TER_SFEC_NUM_EVENT);
if (Errors == 0) {
tber = 0;
} else if (abc == 0x7) {
if (Errors <= 4) {
temporary = (Errors * 1000000000) / (8 * (1 << 14));
temporary = temporary;
} else if (Errors <= 42) {
temporary = (Errors * 100000000) / (8 * (1 << 14));
temporary = temporary * 10;
} else if (Errors <= 429) {
temporary = (Errors * 10000000) / (8 * (1 << 14));
temporary = temporary * 100;
} else if (Errors <= 4294) {
temporary = (Errors * 1000000) / (8 * (1 << 14));
temporary = temporary * 1000;
} else if (Errors <= 42949) {
temporary = (Errors * 100000) / (8 * (1 << 14));
temporary = temporary * 10000;
} else if (Errors <= 429496) {
temporary = (Errors * 10000) / (8 * (1 << 14));
temporary = temporary * 100000;
} else {
temporary = (Errors * 1000) / (8 * (1 << 14));
temporary = temporary * 100000;
}
if (def == 2)
tber = temporary;
else if (def == 3)
tber = temporary / 4;
else if (def == 4)
tber = temporary / 16;
else if (def == 5)
tber = temporary / 64;
else if (def == 6)
tber = temporary / 256;
else
tber = 0;
if ((Errors < 4294967) && (Errors > 429496))
tber *= 10;
}
ter_state->pBER = tber;
(*ber) = tber;
return 0;
}
static int stv0367_get_tune_settings(struct dvb_frontend *fe,
struct dvb_frontend_tune_settings
*fe_tune_settings)
{
fe_tune_settings->min_delay_ms = 1000;
fe_tune_settings->step_size = 0;
fe_tune_settings->max_drift = 0;
return 0;
}
static void stv0367_release(struct dvb_frontend *fe)
{
struct stv0367_state *state = fe->demodulator_priv;
kfree(state->ter_state);
kfree(state->cab_state);
kfree(state);
}
struct dvb_frontend *stv0367ter_attach(const struct stv0367_config *config,
struct i2c_adapter *i2c)
{
struct stv0367_state *state = NULL;
struct stv0367ter_state *ter_state = NULL;
state = kzalloc(sizeof(struct stv0367_state), GFP_KERNEL);
if (state == NULL)
goto error;
ter_state = kzalloc(sizeof(struct stv0367ter_state), GFP_KERNEL);
if (ter_state == NULL)
goto error;
state->i2c = i2c;
state->config = config;
state->ter_state = ter_state;
state->fe.ops = stv0367ter_ops;
state->fe.demodulator_priv = state;
state->chip_id = stv0367_readreg(state, 0xf000);
dprintk("%s: chip_id = 0x%x\n", __func__, state->chip_id);
if ((state->chip_id != 0x50) && (state->chip_id != 0x60))
goto error;
return &state->fe;
error:
kfree(ter_state);
kfree(state);
return NULL;
}
static int stv0367cab_gate_ctrl(struct dvb_frontend *fe, int enable)
{
struct stv0367_state *state = fe->demodulator_priv;
dprintk("%s:\n", __func__);
stv0367_writebits(state, F367CAB_I2CT_ON, (enable > 0) ? 1 : 0);
return 0;
}
static u32 stv0367cab_get_mclk(struct dvb_frontend *fe, u32 ExtClk_Hz)
{
struct stv0367_state *state = fe->demodulator_priv;
u32 mclk_Hz = 0;
u32 M, N, P;
if (stv0367_readbits(state, F367CAB_BYPASS_PLLXN) == 0) {
N = (u32)stv0367_readbits(state, F367CAB_PLL_NDIV);
if (N == 0)
N = N + 1;
M = (u32)stv0367_readbits(state, F367CAB_PLL_MDIV);
if (M == 0)
M = M + 1;
P = (u32)stv0367_readbits(state, F367CAB_PLL_PDIV);
if (P > 5)
P = 5;
mclk_Hz = ((ExtClk_Hz / 2) * N) / (M * (1 << P));
dprintk("stv0367cab_get_mclk BYPASS_PLLXN mclk_Hz=%d\n",
mclk_Hz);
} else
mclk_Hz = ExtClk_Hz;
dprintk("stv0367cab_get_mclk final mclk_Hz=%d\n", mclk_Hz);
return mclk_Hz;
}
static u32 stv0367cab_get_adc_freq(struct dvb_frontend *fe, u32 ExtClk_Hz)
{
u32 ADCClk_Hz = ExtClk_Hz;
ADCClk_Hz = stv0367cab_get_mclk(fe, ExtClk_Hz);
return ADCClk_Hz;
}
enum stv0367cab_mod stv0367cab_SetQamSize(struct stv0367_state *state,
u32 SymbolRate,
enum stv0367cab_mod QAMSize)
{
stv0367_writebits(state, F367CAB_QAM_MODE, QAMSize);
switch (QAMSize) {
case FE_CAB_MOD_QAM4:
stv0367_writereg(state, R367CAB_IQDEM_ADJ_AGC_REF, 0x00);
break;
case FE_CAB_MOD_QAM16:
stv0367_writereg(state, R367CAB_AGC_PWR_REF_L, 0x64);
stv0367_writereg(state, R367CAB_IQDEM_ADJ_AGC_REF, 0x00);
stv0367_writereg(state, R367CAB_FSM_STATE, 0x90);
stv0367_writereg(state, R367CAB_EQU_CTR_LPF_GAIN, 0xc1);
stv0367_writereg(state, R367CAB_EQU_CRL_LPF_GAIN, 0xa7);
stv0367_writereg(state, R367CAB_EQU_CRL_LD_SEN, 0x95);
stv0367_writereg(state, R367CAB_EQU_CRL_LIMITER, 0x40);
stv0367_writereg(state, R367CAB_EQU_PNT_GAIN, 0x8a);
break;
case FE_CAB_MOD_QAM32:
stv0367_writereg(state, R367CAB_IQDEM_ADJ_AGC_REF, 0x00);
stv0367_writereg(state, R367CAB_AGC_PWR_REF_L, 0x6e);
stv0367_writereg(state, R367CAB_FSM_STATE, 0xb0);
stv0367_writereg(state, R367CAB_EQU_CTR_LPF_GAIN, 0xc1);
stv0367_writereg(state, R367CAB_EQU_CRL_LPF_GAIN, 0xb7);
stv0367_writereg(state, R367CAB_EQU_CRL_LD_SEN, 0x9d);
stv0367_writereg(state, R367CAB_EQU_CRL_LIMITER, 0x7f);
stv0367_writereg(state, R367CAB_EQU_PNT_GAIN, 0xa7);
break;
case FE_CAB_MOD_QAM64:
stv0367_writereg(state, R367CAB_IQDEM_ADJ_AGC_REF, 0x82);
stv0367_writereg(state, R367CAB_AGC_PWR_REF_L, 0x5a);
if (SymbolRate > 45000000) {
stv0367_writereg(state, R367CAB_FSM_STATE, 0xb0);
stv0367_writereg(state, R367CAB_EQU_CTR_LPF_GAIN, 0xc1);
stv0367_writereg(state, R367CAB_EQU_CRL_LPF_GAIN, 0xa5);
} else if (SymbolRate > 25000000) {
stv0367_writereg(state, R367CAB_FSM_STATE, 0xa0);
stv0367_writereg(state, R367CAB_EQU_CTR_LPF_GAIN, 0xc1);
stv0367_writereg(state, R367CAB_EQU_CRL_LPF_GAIN, 0xa6);
} else {
stv0367_writereg(state, R367CAB_FSM_STATE, 0xa0);
stv0367_writereg(state, R367CAB_EQU_CTR_LPF_GAIN, 0xd1);
stv0367_writereg(state, R367CAB_EQU_CRL_LPF_GAIN, 0xa7);
}
stv0367_writereg(state, R367CAB_EQU_CRL_LD_SEN, 0x95);
stv0367_writereg(state, R367CAB_EQU_CRL_LIMITER, 0x40);
stv0367_writereg(state, R367CAB_EQU_PNT_GAIN, 0x99);
break;
case FE_CAB_MOD_QAM128:
stv0367_writereg(state, R367CAB_IQDEM_ADJ_AGC_REF, 0x00);
stv0367_writereg(state, R367CAB_AGC_PWR_REF_L, 0x76);
stv0367_writereg(state, R367CAB_FSM_STATE, 0x90);
stv0367_writereg(state, R367CAB_EQU_CTR_LPF_GAIN, 0xb1);
if (SymbolRate > 45000000)
stv0367_writereg(state, R367CAB_EQU_CRL_LPF_GAIN, 0xa7);
else if (SymbolRate > 25000000)
stv0367_writereg(state, R367CAB_EQU_CRL_LPF_GAIN, 0xa6);
else
stv0367_writereg(state, R367CAB_EQU_CRL_LPF_GAIN, 0x97);
stv0367_writereg(state, R367CAB_EQU_CRL_LD_SEN, 0x8e);
stv0367_writereg(state, R367CAB_EQU_CRL_LIMITER, 0x7f);
stv0367_writereg(state, R367CAB_EQU_PNT_GAIN, 0xa7);
break;
case FE_CAB_MOD_QAM256:
stv0367_writereg(state, R367CAB_IQDEM_ADJ_AGC_REF, 0x94);
stv0367_writereg(state, R367CAB_AGC_PWR_REF_L, 0x5a);
stv0367_writereg(state, R367CAB_FSM_STATE, 0xa0);
if (SymbolRate > 45000000)
stv0367_writereg(state, R367CAB_EQU_CTR_LPF_GAIN, 0xc1);
else if (SymbolRate > 25000000)
stv0367_writereg(state, R367CAB_EQU_CTR_LPF_GAIN, 0xc1);
else
stv0367_writereg(state, R367CAB_EQU_CTR_LPF_GAIN, 0xd1);
stv0367_writereg(state, R367CAB_EQU_CRL_LPF_GAIN, 0xa7);
stv0367_writereg(state, R367CAB_EQU_CRL_LD_SEN, 0x85);
stv0367_writereg(state, R367CAB_EQU_CRL_LIMITER, 0x40);
stv0367_writereg(state, R367CAB_EQU_PNT_GAIN, 0xa7);
break;
case FE_CAB_MOD_QAM512:
stv0367_writereg(state, R367CAB_IQDEM_ADJ_AGC_REF, 0x00);
break;
case FE_CAB_MOD_QAM1024:
stv0367_writereg(state, R367CAB_IQDEM_ADJ_AGC_REF, 0x00);
break;
default:
break;
}
return QAMSize;
}
static u32 stv0367cab_set_derot_freq(struct stv0367_state *state,
u32 adc_hz, s32 derot_hz)
{
u32 sampled_if = 0;
u32 adc_khz;
adc_khz = adc_hz / 1000;
dprintk("%s: adc_hz=%d derot_hz=%d\n", __func__, adc_hz, derot_hz);
if (adc_khz != 0) {
if (derot_hz < 1000000)
derot_hz = adc_hz / 4;
if (derot_hz > adc_hz)
derot_hz = derot_hz - adc_hz;
sampled_if = (u32)derot_hz / 1000;
sampled_if *= 32768;
sampled_if /= adc_khz;
sampled_if *= 256;
}
if (sampled_if > 8388607)
sampled_if = 8388607;
dprintk("%s: sampled_if=0x%x\n", __func__, sampled_if);
stv0367_writereg(state, R367CAB_MIX_NCO_LL, sampled_if);
stv0367_writereg(state, R367CAB_MIX_NCO_HL, (sampled_if >> 8));
stv0367_writebits(state, F367CAB_MIX_NCO_INC_HH, (sampled_if >> 16));
return derot_hz;
}
static u32 stv0367cab_get_derot_freq(struct stv0367_state *state, u32 adc_hz)
{
u32 sampled_if;
sampled_if = stv0367_readbits(state, F367CAB_MIX_NCO_INC_LL) +
(stv0367_readbits(state, F367CAB_MIX_NCO_INC_HL) << 8) +
(stv0367_readbits(state, F367CAB_MIX_NCO_INC_HH) << 16);
sampled_if /= 256;
sampled_if *= (adc_hz / 1000);
sampled_if += 1;
sampled_if /= 32768;
return sampled_if;
}
static u32 stv0367cab_set_srate(struct stv0367_state *state, u32 adc_hz,
u32 mclk_hz, u32 SymbolRate,
enum stv0367cab_mod QAMSize)
{
u32 QamSizeCorr = 0;
u32 u32_tmp = 0, u32_tmp1 = 0;
u32 adp_khz;
dprintk("%s:\n", __func__);
switch (QAMSize) {
case FE_CAB_MOD_QAM4:
QamSizeCorr = 1110;
break;
case FE_CAB_MOD_QAM16:
QamSizeCorr = 1032;
break;
case FE_CAB_MOD_QAM32:
QamSizeCorr = 954;
break;
case FE_CAB_MOD_QAM64:
QamSizeCorr = 983;
break;
case FE_CAB_MOD_QAM128:
QamSizeCorr = 957;
break;
case FE_CAB_MOD_QAM256:
QamSizeCorr = 948;
break;
case FE_CAB_MOD_QAM512:
QamSizeCorr = 0;
break;
case FE_CAB_MOD_QAM1024:
QamSizeCorr = 944;
break;
default:
break;
}
if (adc_hz != 0) {
u32_tmp = 256 * SymbolRate;
u32_tmp = u32_tmp / adc_hz;
}
stv0367_writereg(state, R367CAB_EQU_CRL_TFR, (u8)u32_tmp);
adp_khz = (mclk_hz >> 1) / 1000;
if (adp_khz != 0) {
u32_tmp = SymbolRate;
u32_tmp1 = SymbolRate;
if (u32_tmp < 2097152) {
u32_tmp *= 2048;
u32_tmp = u32_tmp / adp_khz;
u32_tmp = u32_tmp * 16384;
u32_tmp /= 125 ;
u32_tmp = u32_tmp * 8;
u32_tmp1 *= 2048;
u32_tmp1 /= 439;
u32_tmp1 *= 256;
u32_tmp1 = u32_tmp1 / adp_khz;
u32_tmp1 *= QamSizeCorr * 9;
u32_tmp1 = u32_tmp1 / 10000000;
} else if (u32_tmp < 4194304) {
u32_tmp *= 1024 ;
u32_tmp = u32_tmp / adp_khz;
u32_tmp = u32_tmp * 16384;
u32_tmp /= 125 ;
u32_tmp = u32_tmp * 16;
u32_tmp1 *= 1024;
u32_tmp1 /= 439;
u32_tmp1 *= 256;
u32_tmp1 = u32_tmp1 / adp_khz;
u32_tmp1 *= QamSizeCorr * 9;
u32_tmp1 = u32_tmp1 / 5000000;
} else if (u32_tmp < 8388607) {
u32_tmp *= 512 ;
u32_tmp = u32_tmp / adp_khz;
u32_tmp = u32_tmp * 16384;
u32_tmp /= 125 ;
u32_tmp = u32_tmp * 32;
u32_tmp1 *= 512;
u32_tmp1 /= 439;
u32_tmp1 *= 256;
u32_tmp1 = u32_tmp1 / adp_khz;
u32_tmp1 *= QamSizeCorr * 9;
u32_tmp1 = u32_tmp1 / 2500000;
} else {
u32_tmp *= 256 ;
u32_tmp = u32_tmp / adp_khz;
u32_tmp = u32_tmp * 16384;
u32_tmp /= 125 ;
u32_tmp = u32_tmp * 64;
u32_tmp1 *= 256;
u32_tmp1 /= 439;
u32_tmp1 *= 256;
u32_tmp1 = u32_tmp1 / adp_khz;
u32_tmp1 *= QamSizeCorr * 9;
u32_tmp1 = u32_tmp1 / 1250000;
}
}
#if 0
if (stv0367_readbits(state, F367CAB_ADJ_EN)) {
stv0367cab_SetIirAdjacentcoefficient(state, mclk_hz,
SymbolRate);
stv0367_writebits(state, F367CAB_ALLPASSFILT_EN, 1);
stv0367cab_SetAllPasscoefficient(state, mclk_hz, SymbolRate);
} else
#endif
stv0367_writebits(state, F367CAB_ALLPASSFILT_EN, 0);
stv0367_writereg(state, R367CAB_SRC_NCO_LL, u32_tmp);
stv0367_writereg(state, R367CAB_SRC_NCO_LH, (u32_tmp >> 8));
stv0367_writereg(state, R367CAB_SRC_NCO_HL, (u32_tmp >> 16));
stv0367_writereg(state, R367CAB_SRC_NCO_HH, (u32_tmp >> 24));
stv0367_writereg(state, R367CAB_IQDEM_GAIN_SRC_L, u32_tmp1 & 0x00ff);
stv0367_writebits(state, F367CAB_GAIN_SRC_HI, (u32_tmp1 >> 8) & 0x00ff);
return SymbolRate ;
}
static u32 stv0367cab_GetSymbolRate(struct stv0367_state *state, u32 mclk_hz)
{
u32 regsym;
u32 adp_khz;
regsym = stv0367_readreg(state, R367CAB_SRC_NCO_LL) +
(stv0367_readreg(state, R367CAB_SRC_NCO_LH) << 8) +
(stv0367_readreg(state, R367CAB_SRC_NCO_HL) << 16) +
(stv0367_readreg(state, R367CAB_SRC_NCO_HH) << 24);
adp_khz = (mclk_hz >> 1) / 1000;
if (regsym < 134217728) {
regsym = regsym * 32;
regsym = regsym / 32768;
regsym = adp_khz * regsym;
regsym = regsym / 128;
regsym *= 125 ;
regsym /= 2048 ;
} else if (regsym < 268435456) {
regsym = regsym * 16;
regsym = regsym / 32768;
regsym = adp_khz * regsym;
regsym = regsym / 128;
regsym *= 125 ;
regsym /= 1024 ;
} else if (regsym < 536870912) {
regsym = regsym * 8;
regsym = regsym / 32768;
regsym = adp_khz * regsym;
regsym = regsym / 128;
regsym *= 125 ;
regsym /= 512 ;
} else {
regsym = regsym * 4;
regsym = regsym / 32768;
regsym = adp_khz * regsym;
regsym = regsym / 128;
regsym *= 125 ;
regsym /= 256 ;
}
return regsym;
}
static int stv0367cab_read_status(struct dvb_frontend *fe, fe_status_t *status)
{
struct stv0367_state *state = fe->demodulator_priv;
dprintk("%s:\n", __func__);
*status = 0;
if (stv0367_readbits(state, F367CAB_QAMFEC_LOCK)) {
*status |= FE_HAS_LOCK;
dprintk("%s: stv0367 has locked\n", __func__);
}
return 0;
}
static int stv0367cab_standby(struct dvb_frontend *fe, u8 standby_on)
{
struct stv0367_state *state = fe->demodulator_priv;
dprintk("%s:\n", __func__);
if (standby_on) {
stv0367_writebits(state, F367CAB_BYPASS_PLLXN, 0x03);
stv0367_writebits(state, F367CAB_STDBY_PLLXN, 0x01);
stv0367_writebits(state, F367CAB_STDBY, 1);
stv0367_writebits(state, F367CAB_STDBY_CORE, 1);
stv0367_writebits(state, F367CAB_EN_BUFFER_I, 0);
stv0367_writebits(state, F367CAB_EN_BUFFER_Q, 0);
stv0367_writebits(state, F367CAB_POFFQ, 1);
stv0367_writebits(state, F367CAB_POFFI, 1);
} else {
stv0367_writebits(state, F367CAB_STDBY_PLLXN, 0x00);
stv0367_writebits(state, F367CAB_BYPASS_PLLXN, 0x00);
stv0367_writebits(state, F367CAB_STDBY, 0);
stv0367_writebits(state, F367CAB_STDBY_CORE, 0);
stv0367_writebits(state, F367CAB_EN_BUFFER_I, 1);
stv0367_writebits(state, F367CAB_EN_BUFFER_Q, 1);
stv0367_writebits(state, F367CAB_POFFQ, 0);
stv0367_writebits(state, F367CAB_POFFI, 0);
}
return 0;
}
static int stv0367cab_sleep(struct dvb_frontend *fe)
{
return stv0367cab_standby(fe, 1);
}
int stv0367cab_init(struct dvb_frontend *fe)
{
struct stv0367_state *state = fe->demodulator_priv;
struct stv0367cab_state *cab_state = state->cab_state;
int i;
dprintk("%s:\n", __func__);
for (i = 0; i < STV0367CAB_NBREGS; i++)
stv0367_writereg(state, def0367cab[i].addr,
def0367cab[i].value);
switch (state->config->ts_mode) {
case STV0367_DVBCI_CLOCK:
dprintk("Setting TSMode = STV0367_DVBCI_CLOCK\n");
stv0367_writebits(state, F367CAB_OUTFORMAT, 0x03);
break;
case STV0367_SERIAL_PUNCT_CLOCK:
case STV0367_SERIAL_CONT_CLOCK:
stv0367_writebits(state, F367CAB_OUTFORMAT, 0x01);
break;
case STV0367_PARALLEL_PUNCT_CLOCK:
case STV0367_OUTPUTMODE_DEFAULT:
stv0367_writebits(state, F367CAB_OUTFORMAT, 0x00);
break;
}
switch (state->config->clk_pol) {
case STV0367_RISINGEDGE_CLOCK:
stv0367_writebits(state, F367CAB_CLK_POLARITY, 0x00);
break;
case STV0367_FALLINGEDGE_CLOCK:
case STV0367_CLOCKPOLARITY_DEFAULT:
stv0367_writebits(state, F367CAB_CLK_POLARITY, 0x01);
break;
}
stv0367_writebits(state, F367CAB_SYNC_STRIP, 0x00);
stv0367_writebits(state, F367CAB_CT_NBST, 0x01);
stv0367_writebits(state, F367CAB_TS_SWAP, 0x01);
stv0367_writebits(state, F367CAB_FIFO_BYPASS, 0x00);
stv0367_writereg(state, R367CAB_ANACTRL, 0x00);
cab_state->mclk = stv0367cab_get_mclk(fe, state->config->xtal);
cab_state->adc_clk = stv0367cab_get_adc_freq(fe, state->config->xtal);
return 0;
}
static
enum stv0367_cab_signal_type stv0367cab_algo(struct stv0367_state *state,
struct dvb_frontend_parameters *param)
{
struct dvb_qam_parameters *op = &param->u.qam;
struct stv0367cab_state *cab_state = state->cab_state;
enum stv0367_cab_signal_type signalType = FE_CAB_NOAGC;
u32 QAMFEC_Lock, QAM_Lock, u32_tmp,
LockTime, TRLTimeOut, AGCTimeOut, CRLSymbols,
CRLTimeOut, EQLTimeOut, DemodTimeOut, FECTimeOut;
u8 TrackAGCAccum;
s32 tmp;
dprintk("%s:\n", __func__);
AGCTimeOut = 25;
TRLTimeOut = 100000000 / op->symbol_rate;
switch (op->modulation) {
case QAM_16:
CRLSymbols = 150000;
EQLTimeOut = 100;
break;
case QAM_32:
CRLSymbols = 250000;
EQLTimeOut = 100;
break;
case QAM_64:
CRLSymbols = 200000;
EQLTimeOut = 100;
break;
case QAM_128:
CRLSymbols = 250000;
EQLTimeOut = 100;
break;
case QAM_256:
CRLSymbols = 250000;
EQLTimeOut = 100;
break;
default:
CRLSymbols = 200000;
EQLTimeOut = 100;
break;
}
#if 0
if (pIntParams->search_range < 0) {
CRLTimeOut = (25 * CRLSymbols *
(-pIntParams->search_range / 1000)) /
(pIntParams->symbol_rate / 1000);
} else
#endif
CRLTimeOut = (25 * CRLSymbols * (cab_state->search_range / 1000)) /
(op->symbol_rate / 1000);
CRLTimeOut = (1000 * CRLTimeOut) / op->symbol_rate;
if (CRLTimeOut < 50)
CRLTimeOut = 50;
FECTimeOut = 20;
DemodTimeOut = AGCTimeOut + TRLTimeOut + CRLTimeOut + EQLTimeOut;
dprintk("%s: DemodTimeOut=%d\n", __func__, DemodTimeOut);
stv0367_writereg(state, R367CAB_CTRL_1, 0x04);
TrackAGCAccum = stv0367_readbits(state, F367CAB_AGC_ACCUMRSTSEL);
stv0367_writebits(state, F367CAB_AGC_ACCUMRSTSEL, 0x0);
stv0367_writebits(state, F367CAB_MODULUSMAP_EN, 0);
stv0367_writebits(state, F367CAB_SWEEP_EN, 0);
stv0367cab_set_derot_freq(state, cab_state->adc_clk,
(1000 * (s32)state->config->if_khz + cab_state->derot_offset));
if ((op->symbol_rate > 10800000) | (op->symbol_rate < 1800000)) {
stv0367_writebits(state, F367CAB_ADJ_EN, 0);
stv0367_writebits(state, F367CAB_ALLPASSFILT_EN, 0);
}
#if 0
tuner_lock = stv0367cab_tuner_get_status(fe);
if (tuner_lock == 0)
return FE_367CAB_NOTUNER;
#endif
LockTime = 0;
stv0367_writereg(state, R367CAB_CTRL_1, 0x00);
do {
QAM_Lock = stv0367_readbits(state, F367CAB_FSM_STATUS);
if ((LockTime >= (DemodTimeOut - EQLTimeOut)) &&
(QAM_Lock == 0x04))
LockTime = DemodTimeOut;
else if ((LockTime >= (AGCTimeOut + TRLTimeOut)) &&
(QAM_Lock == 0x02))
{
LockTime = DemodTimeOut;
u32_tmp = stv0367_readbits(state,
F367CAB_AGC_PWR_WORD_LO) +
(stv0367_readbits(state,
F367CAB_AGC_PWR_WORD_ME) << 8) +
(stv0367_readbits(state,
F367CAB_AGC_PWR_WORD_HI) << 16);
if (u32_tmp >= 131072)
u32_tmp = 262144 - u32_tmp;
u32_tmp = u32_tmp / (1 << (11 - stv0367_readbits(state,
F367CAB_AGC_IF_BWSEL)));
if (u32_tmp < stv0367_readbits(state,
F367CAB_AGC_PWRREF_LO) +
256 * stv0367_readbits(state,
F367CAB_AGC_PWRREF_HI) - 10)
QAM_Lock = 0x0f;
} else {
usleep_range(10000, 20000);
LockTime += 10;
}
dprintk("QAM_Lock=0x%x LockTime=%d\n", QAM_Lock, LockTime);
tmp = stv0367_readreg(state, R367CAB_IT_STATUS1);
dprintk("R367CAB_IT_STATUS1=0x%x\n", tmp);
} while (((QAM_Lock != 0x0c) && (QAM_Lock != 0x0b)) &&
(LockTime < DemodTimeOut));
dprintk("QAM_Lock=0x%x\n", QAM_Lock);
tmp = stv0367_readreg(state, R367CAB_IT_STATUS1);
dprintk("R367CAB_IT_STATUS1=0x%x\n", tmp);
tmp = stv0367_readreg(state, R367CAB_IT_STATUS2);
dprintk("R367CAB_IT_STATUS2=0x%x\n", tmp);
tmp = stv0367cab_get_derot_freq(state, cab_state->adc_clk);
dprintk("stv0367cab_get_derot_freq=0x%x\n", tmp);
if ((QAM_Lock == 0x0c) || (QAM_Lock == 0x0b)) {
LockTime = 0;
do {
usleep_range(5000, 7000);
LockTime += 5;
QAMFEC_Lock = stv0367_readbits(state,
F367CAB_QAMFEC_LOCK);
} while (!QAMFEC_Lock && (LockTime < FECTimeOut));
} else
QAMFEC_Lock = 0;
if (QAMFEC_Lock) {
signalType = FE_CAB_DATAOK;
cab_state->modulation = op->modulation;
cab_state->spect_inv = stv0367_readbits(state,
F367CAB_QUAD_INV);
#if 0
if (state->config->if_khz != 0) {
if (state->config->if_khz > cab_state->adc_clk / 1000) {
cab_state->freq_khz =
FE_Cab_TunerGetFrequency(pIntParams->hTuner)
- stv0367cab_get_derot_freq(state, cab_state->adc_clk)
- cab_state->adc_clk / 1000 + state->config->if_khz;
} else {
cab_state->freq_khz =
FE_Cab_TunerGetFrequency(pIntParams->hTuner)
- stv0367cab_get_derot_freq(state, cab_state->adc_clk)
+ state->config->if_khz;
}
} else {
cab_state->freq_khz =
FE_Cab_TunerGetFrequency(pIntParams->hTuner) +
stv0367cab_get_derot_freq(state,
cab_state->adc_clk) -
cab_state->adc_clk / 4000;
}
#endif
cab_state->symbol_rate = stv0367cab_GetSymbolRate(state,
cab_state->mclk);
cab_state->locked = 1;
} else {
switch (QAM_Lock) {
case 1:
signalType = FE_CAB_NOAGC;
break;
case 2:
signalType = FE_CAB_NOTIMING;
break;
case 3:
signalType = FE_CAB_TIMINGOK;
break;
case 4:
signalType = FE_CAB_NOCARRIER;
break;
case 5:
signalType = FE_CAB_CARRIEROK;
break;
case 7:
signalType = FE_CAB_NOBLIND;
break;
case 8:
signalType = FE_CAB_BLINDOK;
break;
case 10:
signalType = FE_CAB_NODEMOD;
break;
case 11:
signalType = FE_CAB_DEMODOK;
break;
case 12:
signalType = FE_CAB_DEMODOK;
break;
case 13:
signalType = FE_CAB_NODEMOD;
break;
case 14:
signalType = FE_CAB_NOBLIND;
break;
case 15:
signalType = FE_CAB_NOSIGNAL;
break;
default:
break;
}
}
stv0367_writebits(state, F367CAB_AGC_ACCUMRSTSEL, TrackAGCAccum);
return signalType;
}
static int stv0367cab_set_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *param)
{
struct stv0367_state *state = fe->demodulator_priv;
struct stv0367cab_state *cab_state = state->cab_state;
struct dvb_qam_parameters *op = &param->u.qam;
enum stv0367cab_mod QAMSize = 0;
dprintk("%s: freq = %d, srate = %d\n", __func__,
param->frequency, op->symbol_rate);
cab_state->derot_offset = 0;
switch (op->modulation) {
case QAM_16:
QAMSize = FE_CAB_MOD_QAM16;
break;
case QAM_32:
QAMSize = FE_CAB_MOD_QAM32;
break;
case QAM_64:
QAMSize = FE_CAB_MOD_QAM64;
break;
case QAM_128:
QAMSize = FE_CAB_MOD_QAM128;
break;
case QAM_256:
QAMSize = FE_CAB_MOD_QAM256;
break;
default:
break;
}
stv0367cab_init(fe);
if (fe->ops.tuner_ops.set_params) {
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
fe->ops.tuner_ops.set_params(fe, param);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 0);
}
stv0367cab_SetQamSize(
state,
op->symbol_rate,
QAMSize);
stv0367cab_set_srate(state,
cab_state->adc_clk,
cab_state->mclk,
op->symbol_rate,
QAMSize);
cab_state->state = stv0367cab_algo(state, param);
return 0;
}
static int stv0367cab_get_frontend(struct dvb_frontend *fe,
struct dvb_frontend_parameters *param)
{
struct stv0367_state *state = fe->demodulator_priv;
struct stv0367cab_state *cab_state = state->cab_state;
struct dvb_qam_parameters *op = &param->u.qam;
enum stv0367cab_mod QAMSize;
dprintk("%s:\n", __func__);
op->symbol_rate = stv0367cab_GetSymbolRate(state, cab_state->mclk);
QAMSize = stv0367_readbits(state, F367CAB_QAM_MODE);
switch (QAMSize) {
case FE_CAB_MOD_QAM16:
op->modulation = QAM_16;
break;
case FE_CAB_MOD_QAM32:
op->modulation = QAM_32;
break;
case FE_CAB_MOD_QAM64:
op->modulation = QAM_64;
break;
case FE_CAB_MOD_QAM128:
op->modulation = QAM_128;
break;
case QAM_256:
op->modulation = QAM_256;
break;
default:
break;
}
param->frequency = stv0367_get_tuner_freq(fe);
dprintk("%s: tuner frequency = %d\n", __func__, param->frequency);
if (state->config->if_khz == 0) {
param->frequency +=
(stv0367cab_get_derot_freq(state, cab_state->adc_clk) -
cab_state->adc_clk / 4000);
return 0;
}
if (state->config->if_khz > cab_state->adc_clk / 1000)
param->frequency += (state->config->if_khz
- stv0367cab_get_derot_freq(state, cab_state->adc_clk)
- cab_state->adc_clk / 1000);
else
param->frequency += (state->config->if_khz
- stv0367cab_get_derot_freq(state, cab_state->adc_clk));
return 0;
}
static s32 stv0367cab_get_rf_lvl(struct stv0367_state *state)
{
s32 rfLevel = 0;
s32 RfAgcPwm = 0, IfAgcPwm = 0;
u8 i;
stv0367_writebits(state, F367CAB_STDBY_ADCGP, 0x0);
RfAgcPwm =
(stv0367_readbits(state, F367CAB_RF_AGC1_LEVEL_LO) & 0x03) +
(stv0367_readbits(state, F367CAB_RF_AGC1_LEVEL_HI) << 2);
RfAgcPwm = 100 * RfAgcPwm / 1023;
IfAgcPwm =
stv0367_readbits(state, F367CAB_AGC_IF_PWMCMD_LO) +
(stv0367_readbits(state, F367CAB_AGC_IF_PWMCMD_HI) << 8);
if (IfAgcPwm >= 2048)
IfAgcPwm -= 2048;
else
IfAgcPwm += 2048;
IfAgcPwm = 100 * IfAgcPwm / 4095;
if (RfAgcPwm < 90 && IfAgcPwm < 28) {
for (i = 0; i < RF_LOOKUP_TABLE_SIZE; i++) {
if (RfAgcPwm <= stv0367cab_RF_LookUp1[0][i]) {
rfLevel = (-1) * stv0367cab_RF_LookUp1[1][i];
break;
}
}
if (i == RF_LOOKUP_TABLE_SIZE)
rfLevel = -56;
} else {
for (i = 0; i < RF_LOOKUP_TABLE2_SIZE; i++) {
if (IfAgcPwm <= stv0367cab_RF_LookUp2[0][i]) {
rfLevel = (-1) * stv0367cab_RF_LookUp2[1][i];
break;
}
}
if (i == RF_LOOKUP_TABLE2_SIZE)
rfLevel = -72;
}
return rfLevel;
}
static int stv0367cab_read_strength(struct dvb_frontend *fe, u16 *strength)
{
struct stv0367_state *state = fe->demodulator_priv;
s32 signal = stv0367cab_get_rf_lvl(state);
dprintk("%s: signal=%d dBm\n", __func__, signal);
if (signal <= -72)
*strength = 65535;
else
*strength = (22 + signal) * (-1311);
dprintk("%s: strength=%d\n", __func__, (*strength));
return 0;
}
static int stv0367cab_read_snr(struct dvb_frontend *fe, u16 *snr)
{
struct stv0367_state *state = fe->demodulator_priv;
u32 noisepercentage;
enum stv0367cab_mod QAMSize;
u32 regval = 0, temp = 0;
int power, i;
QAMSize = stv0367_readbits(state, F367CAB_QAM_MODE);
switch (QAMSize) {
case FE_CAB_MOD_QAM4:
power = 21904;
break;
case FE_CAB_MOD_QAM16:
power = 20480;
break;
case FE_CAB_MOD_QAM32:
power = 23040;
break;
case FE_CAB_MOD_QAM64:
power = 21504;
break;
case FE_CAB_MOD_QAM128:
power = 23616;
break;
case FE_CAB_MOD_QAM256:
power = 21760;
break;
case FE_CAB_MOD_QAM512:
power = 1;
break;
case FE_CAB_MOD_QAM1024:
power = 21280;
break;
default:
power = 1;
break;
}
for (i = 0; i < 10; i++) {
regval += (stv0367_readbits(state, F367CAB_SNR_LO)
+ 256 * stv0367_readbits(state, F367CAB_SNR_HI));
}
regval /= 10;
if (regval != 0) {
temp = power
* (1 << (3 + stv0367_readbits(state, F367CAB_SNR_PER)));
temp /= regval;
}
if (temp >= 5012)
noisepercentage = 100;
else if (temp >= 3981)
noisepercentage = 93;
else if (temp >= 3162)
noisepercentage = 86;
else if (temp >= 2512)
noisepercentage = 79;
else if (temp >= 1995)
noisepercentage = 72;
else if (temp >= 1585)
noisepercentage = 65;
else if (temp >= 1259)
noisepercentage = 58;
else if (temp >= 1000)
noisepercentage = 50;
else if (temp >= 794)
noisepercentage = 43;
else if (temp >= 501)
noisepercentage = 36;
else if (temp >= 316)
noisepercentage = 29;
else if (temp >= 200)
noisepercentage = 22;
else if (temp >= 158)
noisepercentage = 14;
else if (temp >= 126)
noisepercentage = 7;
else
noisepercentage = 0;
dprintk("%s: noisepercentage=%d\n", __func__, noisepercentage);
*snr = (noisepercentage * 65535) / 100;
return 0;
}
static int stv0367cab_read_ucblcks(struct dvb_frontend *fe, u32 *ucblocks)
{
struct stv0367_state *state = fe->demodulator_priv;
int corrected, tscount;
*ucblocks = (stv0367_readreg(state, R367CAB_RS_COUNTER_5) << 8)
| stv0367_readreg(state, R367CAB_RS_COUNTER_4);
corrected = (stv0367_readreg(state, R367CAB_RS_COUNTER_3) << 8)
| stv0367_readreg(state, R367CAB_RS_COUNTER_2);
tscount = (stv0367_readreg(state, R367CAB_RS_COUNTER_2) << 8)
| stv0367_readreg(state, R367CAB_RS_COUNTER_1);
dprintk("%s: uncorrected blocks=%d corrected blocks=%d tscount=%d\n",
__func__, *ucblocks, corrected, tscount);
return 0;
}
struct dvb_frontend *stv0367cab_attach(const struct stv0367_config *config,
struct i2c_adapter *i2c)
{
struct stv0367_state *state = NULL;
struct stv0367cab_state *cab_state = NULL;
state = kzalloc(sizeof(struct stv0367_state), GFP_KERNEL);
if (state == NULL)
goto error;
cab_state = kzalloc(sizeof(struct stv0367cab_state), GFP_KERNEL);
if (cab_state == NULL)
goto error;
state->i2c = i2c;
state->config = config;
cab_state->search_range = 280000;
state->cab_state = cab_state;
state->fe.ops = stv0367cab_ops;
state->fe.demodulator_priv = state;
state->chip_id = stv0367_readreg(state, 0xf000);
dprintk("%s: chip_id = 0x%x\n", __func__, state->chip_id);
if ((state->chip_id != 0x50) && (state->chip_id != 0x60))
goto error;
return &state->fe;
error:
kfree(cab_state);
kfree(state);
return NULL;
}
