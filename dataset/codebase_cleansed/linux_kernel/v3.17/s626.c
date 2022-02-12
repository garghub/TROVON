static void s626_mc_enable(struct comedi_device *dev,
unsigned int cmd, unsigned int reg)
{
unsigned int val = (cmd << 16) | cmd;
mmiowb();
writel(val, dev->mmio + reg);
}
static void s626_mc_disable(struct comedi_device *dev,
unsigned int cmd, unsigned int reg)
{
writel(cmd << 16 , dev->mmio + reg);
mmiowb();
}
static bool s626_mc_test(struct comedi_device *dev,
unsigned int cmd, unsigned int reg)
{
unsigned int val;
val = readl(dev->mmio + reg);
return (val & cmd) ? true : false;
}
static void s626_debi_transfer(struct comedi_device *dev)
{
static const int timeout = 10000;
int i;
s626_mc_enable(dev, S626_MC2_UPLD_DEBI, S626_P_MC2);
for (i = 0; i < timeout; i++) {
if (s626_mc_test(dev, S626_MC2_UPLD_DEBI, S626_P_MC2))
break;
udelay(1);
}
if (i == timeout)
dev_err(dev->class_dev,
"Timeout while uploading to DEBI control register\n");
for (i = 0; i < timeout; i++) {
if (!(readl(dev->mmio + S626_P_PSR) & S626_PSR_DEBI_S))
break;
udelay(1);
}
if (i == timeout)
dev_err(dev->class_dev, "DEBI transfer timeout\n");
}
static uint16_t s626_debi_read(struct comedi_device *dev, uint16_t addr)
{
writel(S626_DEBI_CMD_RDWORD | addr, dev->mmio + S626_P_DEBICMD);
s626_debi_transfer(dev);
return readl(dev->mmio + S626_P_DEBIAD);
}
static void s626_debi_write(struct comedi_device *dev, uint16_t addr,
uint16_t wdata)
{
writel(S626_DEBI_CMD_WRWORD | addr, dev->mmio + S626_P_DEBICMD);
writel(wdata, dev->mmio + S626_P_DEBIAD);
s626_debi_transfer(dev);
}
static void s626_debi_replace(struct comedi_device *dev, unsigned int addr,
unsigned int mask, unsigned int wdata)
{
unsigned int val;
addr &= 0xffff;
writel(S626_DEBI_CMD_RDWORD | addr, dev->mmio + S626_P_DEBICMD);
s626_debi_transfer(dev);
writel(S626_DEBI_CMD_WRWORD | addr, dev->mmio + S626_P_DEBICMD);
val = readl(dev->mmio + S626_P_DEBIAD);
val &= mask;
val |= wdata;
writel(val & 0xffff, dev->mmio + S626_P_DEBIAD);
s626_debi_transfer(dev);
}
static int s626_i2c_handshake_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
bool status;
status = s626_mc_test(dev, S626_MC2_UPLD_IIC, S626_P_MC2);
if (status)
return 0;
return -EBUSY;
}
static int s626_i2c_handshake(struct comedi_device *dev, uint32_t val)
{
unsigned int ctrl;
int ret;
writel(val, dev->mmio + S626_P_I2CCTRL);
s626_mc_enable(dev, S626_MC2_UPLD_IIC, S626_P_MC2);
ret = comedi_timeout(dev, NULL, NULL, s626_i2c_handshake_eoc, 0);
if (ret)
return ret;
do {
ctrl = readl(dev->mmio + S626_P_I2CCTRL);
} while ((ctrl & (S626_I2C_BUSY | S626_I2C_ERR)) == S626_I2C_BUSY);
return ctrl & S626_I2C_ERR;
}
static uint8_t s626_i2c_read(struct comedi_device *dev, uint8_t addr)
{
struct s626_private *devpriv = dev->private;
if (s626_i2c_handshake(dev, S626_I2C_B2(S626_I2C_ATTRSTART,
devpriv->i2c_adrs) |
S626_I2C_B1(S626_I2C_ATTRSTOP, addr) |
S626_I2C_B0(S626_I2C_ATTRNOP, 0)))
return 0;
if (s626_i2c_handshake(dev, S626_I2C_B2(S626_I2C_ATTRSTART,
(devpriv->i2c_adrs | 1)) |
S626_I2C_B1(S626_I2C_ATTRSTOP, 0) |
S626_I2C_B0(S626_I2C_ATTRNOP, 0)))
return 0;
return (readl(dev->mmio + S626_P_I2CCTRL) >> 16) & 0xff;
}
static int s626_send_dac_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
switch (context) {
case s626_send_dac_wait_not_mc1_a2out:
status = readl(dev->mmio + S626_P_MC1);
if (!(status & S626_MC1_A2OUT))
return 0;
break;
case s626_send_dac_wait_ssr_af2_out:
status = readl(dev->mmio + S626_P_SSR);
if (status & S626_SSR_AF2_OUT)
return 0;
break;
case s626_send_dac_wait_fb_buffer2_msb_00:
status = readl(dev->mmio + S626_P_FB_BUFFER2);
if (!(status & 0xff000000))
return 0;
break;
case s626_send_dac_wait_fb_buffer2_msb_ff:
status = readl(dev->mmio + S626_P_FB_BUFFER2);
if (status & 0xff000000)
return 0;
break;
default:
return -EINVAL;
}
return -EBUSY;
}
static int s626_send_dac(struct comedi_device *dev, uint32_t val)
{
struct s626_private *devpriv = dev->private;
int ret;
s626_debi_write(dev, S626_LP_DACPOL, devpriv->dacpol);
*devpriv->dac_wbuf = val;
s626_mc_enable(dev, S626_MC1_A2OUT, S626_P_MC1);
writel(S626_ISR_AFOU, dev->mmio + S626_P_ISR);
ret = comedi_timeout(dev, NULL, NULL, s626_send_dac_eoc,
s626_send_dac_wait_not_mc1_a2out);
if (ret) {
dev_err(dev->class_dev, "DMA transfer timeout\n");
return ret;
}
writel(S626_XSD2 | S626_RSD3 | S626_SIB_A2,
dev->mmio + S626_VECTPORT(0));
ret = comedi_timeout(dev, NULL, NULL, s626_send_dac_eoc,
s626_send_dac_wait_ssr_af2_out);
if (ret) {
dev_err(dev->class_dev,
"TSL timeout waiting for slot 1 to execute\n");
return ret;
}
writel(S626_XSD2 | S626_XFIFO_2 | S626_RSD2 | S626_SIB_A2 | S626_EOS,
dev->mmio + S626_VECTPORT(0));
if (readl(dev->mmio + S626_P_FB_BUFFER2) & 0xff000000) {
ret = comedi_timeout(dev, NULL, NULL, s626_send_dac_eoc,
s626_send_dac_wait_fb_buffer2_msb_00);
if (ret) {
dev_err(dev->class_dev,
"TSL timeout waiting for slot 0 to execute\n");
return ret;
}
}
writel(S626_RSD3 | S626_SIB_A2 | S626_EOS,
dev->mmio + S626_VECTPORT(0));
ret = comedi_timeout(dev, NULL, NULL, s626_send_dac_eoc,
s626_send_dac_wait_fb_buffer2_msb_ff);
if (ret) {
dev_err(dev->class_dev,
"TSL timeout waiting for slot 0 to execute\n");
return ret;
}
return 0;
}
static int s626_set_dac(struct comedi_device *dev, uint16_t chan,
int16_t dacdata)
{
struct s626_private *devpriv = dev->private;
uint16_t signmask;
uint32_t ws_image;
uint32_t val;
signmask = 1 << chan;
if (dacdata < 0) {
dacdata = -dacdata;
devpriv->dacpol |= signmask;
} else {
devpriv->dacpol &= ~signmask;
}
if ((uint16_t)dacdata > 0x1FFF)
dacdata = 0x1FFF;
ws_image = (chan & 2) ? S626_WS1 : S626_WS2;
writel(S626_XSD2 | S626_XFIFO_1 | ws_image,
dev->mmio + S626_VECTPORT(2));
writel(S626_XSD2 | S626_XFIFO_0 | ws_image,
dev->mmio + S626_VECTPORT(3));
writel(S626_XSD2 | S626_XFIFO_3 | S626_WS3,
dev->mmio + S626_VECTPORT(4));
writel(S626_XSD2 | S626_XFIFO_2 | S626_WS3 | S626_EOS,
dev->mmio + S626_VECTPORT(5));
val = 0x0F000000;
val |= 0x00004000;
val |= ((uint32_t)(chan & 1) << 15);
val |= (uint32_t)dacdata;
return s626_send_dac(dev, val);
}
static int s626_write_trim_dac(struct comedi_device *dev, uint8_t logical_chan,
uint8_t dac_data)
{
struct s626_private *devpriv = dev->private;
uint32_t chan;
devpriv->trim_setpoint[logical_chan] = (uint8_t)dac_data;
chan = s626_trimchan[logical_chan];
writel(S626_XSD2 | S626_XFIFO_1 | S626_WS3,
dev->mmio + S626_VECTPORT(2));
writel(S626_XSD2 | S626_XFIFO_0 | S626_WS3,
dev->mmio + S626_VECTPORT(3));
writel(S626_XSD2 | S626_XFIFO_3 | S626_WS1,
dev->mmio + S626_VECTPORT(4));
writel(S626_XSD2 | S626_XFIFO_2 | S626_WS1 | S626_EOS,
dev->mmio + S626_VECTPORT(5));
return s626_send_dac(dev, (chan << 8) | dac_data);
}
static int s626_load_trim_dacs(struct comedi_device *dev)
{
uint8_t i;
int ret;
for (i = 0; i < ARRAY_SIZE(s626_trimchan); i++) {
ret = s626_write_trim_dac(dev, i,
s626_i2c_read(dev, s626_trimadrs[i]));
if (ret)
return ret;
}
return 0;
}
static void s626_set_latch_source(struct comedi_device *dev,
unsigned int chan, uint16_t value)
{
s626_debi_replace(dev, S626_LP_CRB(chan),
~(S626_CRBMSK_INTCTRL | S626_CRBMSK_LATCHSRC),
S626_SET_CRB_LATCHSRC(value));
}
static void s626_preload(struct comedi_device *dev,
unsigned int chan, uint32_t value)
{
s626_debi_write(dev, S626_LP_CNTR(chan), value);
s626_debi_write(dev, S626_LP_CNTR(chan) + 2, value >> 16);
}
static void s626_reset_cap_flags(struct comedi_device *dev,
unsigned int chan)
{
uint16_t set;
set = S626_SET_CRB_INTRESETCMD(1);
if (chan < 3)
set |= S626_SET_CRB_INTRESET_A(1);
else
set |= S626_SET_CRB_INTRESET_B(1);
s626_debi_replace(dev, S626_LP_CRB(chan), ~S626_CRBMSK_INTCTRL, set);
}
static uint16_t s626_get_mode_a(struct comedi_device *dev,
unsigned int chan)
{
uint16_t cra;
uint16_t crb;
uint16_t setup;
unsigned cntsrc, clkmult, clkpol, encmode;
cra = s626_debi_read(dev, S626_LP_CRA(chan));
crb = s626_debi_read(dev, S626_LP_CRB(chan));
setup =
S626_SET_STD_LOADSRC(S626_GET_CRA_LOADSRC_A(cra)) |
S626_SET_STD_LATCHSRC(S626_GET_CRB_LATCHSRC(crb)) |
S626_SET_STD_INTSRC(S626_GET_CRA_INTSRC_A(cra)) |
S626_SET_STD_INDXSRC(S626_GET_CRA_INDXSRC_A(cra)) |
S626_SET_STD_INDXPOL(S626_GET_CRA_INDXPOL_A(cra)) |
S626_SET_STD_CLKENAB(S626_GET_CRB_CLKENAB_A(crb));
cntsrc = S626_GET_CRA_CNTSRC_A(cra);
if (cntsrc & S626_CNTSRC_SYSCLK) {
encmode = S626_ENCMODE_TIMER;
clkpol = cntsrc & 1;
clkmult = S626_CLKMULT_1X;
} else {
encmode = S626_ENCMODE_COUNTER;
clkpol = S626_GET_CRA_CLKPOL_A(cra);
clkmult = S626_GET_CRA_CLKMULT_A(cra);
if (clkmult == S626_CLKMULT_SPECIAL)
clkmult = S626_CLKMULT_1X;
}
setup |= S626_SET_STD_ENCMODE(encmode) | S626_SET_STD_CLKMULT(clkmult) |
S626_SET_STD_CLKPOL(clkpol);
return setup;
}
static uint16_t s626_get_mode_b(struct comedi_device *dev,
unsigned int chan)
{
uint16_t cra;
uint16_t crb;
uint16_t setup;
unsigned cntsrc, clkmult, clkpol, encmode;
cra = s626_debi_read(dev, S626_LP_CRA(chan));
crb = s626_debi_read(dev, S626_LP_CRB(chan));
setup =
S626_SET_STD_INTSRC(S626_GET_CRB_INTSRC_B(crb)) |
S626_SET_STD_LATCHSRC(S626_GET_CRB_LATCHSRC(crb)) |
S626_SET_STD_LOADSRC(S626_GET_CRB_LOADSRC_B(crb)) |
S626_SET_STD_INDXPOL(S626_GET_CRB_INDXPOL_B(crb)) |
S626_SET_STD_CLKENAB(S626_GET_CRB_CLKENAB_B(crb)) |
S626_SET_STD_INDXSRC(S626_GET_CRA_INDXSRC_B(cra));
cntsrc = S626_GET_CRA_CNTSRC_B(cra);
clkmult = S626_GET_CRB_CLKMULT_B(crb);
if (clkmult == S626_CLKMULT_SPECIAL) {
encmode = S626_ENCMODE_EXTENDER;
clkmult = S626_CLKMULT_1X;
clkpol = cntsrc & 1;
} else if (cntsrc & S626_CNTSRC_SYSCLK) {
encmode = S626_ENCMODE_TIMER;
clkmult = S626_CLKMULT_1X;
clkpol = cntsrc & 1;
} else {
encmode = S626_ENCMODE_COUNTER;
clkpol = S626_GET_CRB_CLKPOL_B(crb);
}
setup |= S626_SET_STD_ENCMODE(encmode) | S626_SET_STD_CLKMULT(clkmult) |
S626_SET_STD_CLKPOL(clkpol);
return setup;
}
static uint16_t s626_get_mode(struct comedi_device *dev,
unsigned int chan)
{
return (chan < 3) ? s626_get_mode_a(dev, chan)
: s626_get_mode_b(dev, chan);
}
static void s626_set_mode_a(struct comedi_device *dev,
unsigned int chan, uint16_t setup,
uint16_t disable_int_src)
{
struct s626_private *devpriv = dev->private;
uint16_t cra;
uint16_t crb;
unsigned cntsrc, clkmult, clkpol;
cra = S626_SET_CRA_LOADSRC_A(S626_GET_STD_LOADSRC(setup));
cra |= S626_SET_CRA_INDXSRC_A(S626_GET_STD_INDXSRC(setup));
crb = S626_SET_CRB_INTRESETCMD(1) | S626_SET_CRB_INTRESET_A(1);
crb |= S626_SET_CRB_CLKENAB_A(S626_GET_STD_CLKENAB(setup));
if (!disable_int_src)
cra |= S626_SET_CRA_INTSRC_A(S626_GET_STD_INTSRC(setup));
clkpol = S626_GET_STD_CLKPOL(setup);
switch (S626_GET_STD_ENCMODE(setup)) {
case S626_ENCMODE_EXTENDER:
case S626_ENCMODE_TIMER:
cntsrc = S626_CNTSRC_SYSCLK;
cntsrc |= clkpol;
clkpol = 1;
clkmult = S626_CLKMULT_1X;
break;
default:
cntsrc = S626_CNTSRC_ENCODER;
clkmult = S626_GET_STD_CLKMULT(setup);
if (clkmult == S626_CLKMULT_SPECIAL)
clkmult = S626_CLKMULT_1X;
break;
}
cra |= S626_SET_CRA_CNTSRC_A(cntsrc) | S626_SET_CRA_CLKPOL_A(clkpol) |
S626_SET_CRA_CLKMULT_A(clkmult);
if (S626_GET_STD_INDXSRC(setup) != S626_INDXSRC_SOFT)
cra |= S626_SET_CRA_INDXPOL_A(S626_GET_STD_INDXPOL(setup));
if (disable_int_src)
devpriv->counter_int_enabs &= ~(S626_OVERMASK(chan) |
S626_INDXMASK(chan));
s626_debi_replace(dev, S626_LP_CRA(chan),
S626_CRAMSK_INDXSRC_B | S626_CRAMSK_CNTSRC_B, cra);
s626_debi_replace(dev, S626_LP_CRB(chan),
~(S626_CRBMSK_INTCTRL | S626_CRBMSK_CLKENAB_A), crb);
}
static void s626_set_mode_b(struct comedi_device *dev,
unsigned int chan, uint16_t setup,
uint16_t disable_int_src)
{
struct s626_private *devpriv = dev->private;
uint16_t cra;
uint16_t crb;
unsigned cntsrc, clkmult, clkpol;
cra = S626_SET_CRA_INDXSRC_B(S626_GET_STD_INDXSRC(setup));
crb = S626_SET_CRB_INTRESETCMD(1) | S626_SET_CRB_INTRESET_B(1);
crb |= S626_SET_CRB_CLKENAB_B(S626_GET_STD_CLKENAB(setup));
crb |= S626_SET_CRB_LOADSRC_B(S626_GET_STD_LOADSRC(setup));
if (!disable_int_src)
crb |= S626_SET_CRB_INTSRC_B(S626_GET_STD_INTSRC(setup));
clkpol = S626_GET_STD_CLKPOL(setup);
switch (S626_GET_STD_ENCMODE(setup)) {
case S626_ENCMODE_TIMER:
cntsrc = S626_CNTSRC_SYSCLK;
cntsrc |= clkpol;
clkpol = 1;
clkmult = S626_CLKMULT_1X;
break;
case S626_ENCMODE_EXTENDER:
cntsrc = S626_CNTSRC_SYSCLK;
cntsrc |= clkpol;
clkpol = 1;
clkmult = S626_CLKMULT_SPECIAL;
break;
default:
cntsrc = S626_CNTSRC_ENCODER;
clkmult = S626_GET_STD_CLKMULT(setup);
if (clkmult == S626_CLKMULT_SPECIAL)
clkmult = S626_CLKMULT_1X;
break;
}
cra |= S626_SET_CRA_CNTSRC_B(cntsrc);
crb |= S626_SET_CRB_CLKPOL_B(clkpol) | S626_SET_CRB_CLKMULT_B(clkmult);
if (S626_GET_STD_INDXSRC(setup) != S626_INDXSRC_SOFT)
crb |= S626_SET_CRB_INDXPOL_B(S626_GET_STD_INDXPOL(setup));
if (disable_int_src)
devpriv->counter_int_enabs &= ~(S626_OVERMASK(chan) |
S626_INDXMASK(chan));
s626_debi_replace(dev, S626_LP_CRA(chan),
~(S626_CRAMSK_INDXSRC_B | S626_CRAMSK_CNTSRC_B), cra);
s626_debi_replace(dev, S626_LP_CRB(chan),
S626_CRBMSK_CLKENAB_A | S626_CRBMSK_LATCHSRC, crb);
}
static void s626_set_mode(struct comedi_device *dev,
unsigned int chan,
uint16_t setup, uint16_t disable_int_src)
{
if (chan < 3)
s626_set_mode_a(dev, chan, setup, disable_int_src);
else
s626_set_mode_b(dev, chan, setup, disable_int_src);
}
static void s626_set_enable(struct comedi_device *dev,
unsigned int chan, uint16_t enab)
{
unsigned int mask = S626_CRBMSK_INTCTRL;
unsigned int set;
if (chan < 3) {
mask |= S626_CRBMSK_CLKENAB_A;
set = S626_SET_CRB_CLKENAB_A(enab);
} else {
mask |= S626_CRBMSK_CLKENAB_B;
set = S626_SET_CRB_CLKENAB_B(enab);
}
s626_debi_replace(dev, S626_LP_CRB(chan), ~mask, set);
}
static uint16_t s626_get_enable(struct comedi_device *dev,
unsigned int chan)
{
uint16_t crb = s626_debi_read(dev, S626_LP_CRB(chan));
return (chan < 3) ? S626_GET_CRB_CLKENAB_A(crb)
: S626_GET_CRB_CLKENAB_B(crb);
}
static uint16_t s626_get_latch_source(struct comedi_device *dev,
unsigned int chan)
{
return S626_GET_CRB_LATCHSRC(s626_debi_read(dev, S626_LP_CRB(chan)));
}
static void s626_set_load_trig(struct comedi_device *dev,
unsigned int chan, uint16_t trig)
{
uint16_t reg;
uint16_t mask;
uint16_t set;
if (chan < 3) {
reg = S626_LP_CRA(chan);
mask = S626_CRAMSK_LOADSRC_A;
set = S626_SET_CRA_LOADSRC_A(trig);
} else {
reg = S626_LP_CRB(chan);
mask = S626_CRBMSK_LOADSRC_B | S626_CRBMSK_INTCTRL;
set = S626_SET_CRB_LOADSRC_B(trig);
}
s626_debi_replace(dev, reg, ~mask, set);
}
static uint16_t s626_get_load_trig(struct comedi_device *dev,
unsigned int chan)
{
if (chan < 3)
return S626_GET_CRA_LOADSRC_A(s626_debi_read(dev,
S626_LP_CRA(chan)));
else
return S626_GET_CRB_LOADSRC_B(s626_debi_read(dev,
S626_LP_CRB(chan)));
}
static void s626_set_int_src(struct comedi_device *dev,
unsigned int chan, uint16_t int_source)
{
struct s626_private *devpriv = dev->private;
uint16_t cra_reg = S626_LP_CRA(chan);
uint16_t crb_reg = S626_LP_CRB(chan);
if (chan < 3) {
s626_debi_replace(dev, crb_reg, ~S626_CRBMSK_INTCTRL,
S626_SET_CRB_INTRESETCMD(1) |
S626_SET_CRB_INTRESET_A(1));
s626_debi_replace(dev, cra_reg, ~S626_CRAMSK_INTSRC_A,
S626_SET_CRA_INTSRC_A(int_source));
} else {
uint16_t crb;
crb = s626_debi_read(dev, crb_reg);
crb &= ~S626_CRBMSK_INTCTRL;
s626_debi_write(dev, crb_reg,
crb | S626_SET_CRB_INTRESETCMD(1) |
S626_SET_CRB_INTRESET_B(1));
s626_debi_write(dev, crb_reg,
(crb & ~S626_CRBMSK_INTSRC_B) |
S626_SET_CRB_INTSRC_B(int_source));
}
devpriv->counter_int_enabs &= ~(S626_OVERMASK(chan) |
S626_INDXMASK(chan));
switch (int_source) {
case 0:
default:
break;
case 1:
devpriv->counter_int_enabs |= S626_OVERMASK(chan);
break;
case 2:
devpriv->counter_int_enabs |= S626_INDXMASK(chan);
break;
case 3:
devpriv->counter_int_enabs |= (S626_OVERMASK(chan) |
S626_INDXMASK(chan));
break;
}
}
static uint16_t s626_get_int_src(struct comedi_device *dev,
unsigned int chan)
{
if (chan < 3)
return S626_GET_CRA_INTSRC_A(s626_debi_read(dev,
S626_LP_CRA(chan)));
else
return S626_GET_CRB_INTSRC_B(s626_debi_read(dev,
S626_LP_CRB(chan)));
}
static void s626_set_clk_mult(struct comedi_device *dev,
unsigned int chan, uint16_t value)
{
uint16_t mode;
mode = s626_get_mode(dev, chan);
mode &= ~S626_STDMSK_CLKMULT;
mode |= S626_SET_STD_CLKMULT(value);
s626_set_mode(dev, chan, mode, false);
}
static uint16_t s626_get_clk_mult(struct comedi_device *dev,
unsigned int chan)
{
return S626_GET_STD_CLKMULT(s626_get_mode(dev, chan));
}
static void s626_set_clk_pol(struct comedi_device *dev,
unsigned int chan, uint16_t value)
{
uint16_t mode;
mode = s626_get_mode(dev, chan);
mode &= ~S626_STDMSK_CLKPOL;
mode |= S626_SET_STD_CLKPOL(value);
s626_set_mode(dev, chan, mode, false);
}
static uint16_t s626_get_clk_pol(struct comedi_device *dev,
unsigned int chan)
{
return S626_GET_STD_CLKPOL(s626_get_mode(dev, chan));
}
static void s626_set_enc_mode(struct comedi_device *dev,
unsigned int chan, uint16_t value)
{
uint16_t mode;
mode = s626_get_mode(dev, chan);
mode &= ~S626_STDMSK_ENCMODE;
mode |= S626_SET_STD_ENCMODE(value);
s626_set_mode(dev, chan, mode, false);
}
static uint16_t s626_get_enc_mode(struct comedi_device *dev,
unsigned int chan)
{
return S626_GET_STD_ENCMODE(s626_get_mode(dev, chan));
}
static void s626_set_index_pol(struct comedi_device *dev,
unsigned int chan, uint16_t value)
{
uint16_t mode;
mode = s626_get_mode(dev, chan);
mode &= ~S626_STDMSK_INDXPOL;
mode |= S626_SET_STD_INDXPOL(value != 0);
s626_set_mode(dev, chan, mode, false);
}
static uint16_t s626_get_index_pol(struct comedi_device *dev,
unsigned int chan)
{
return S626_GET_STD_INDXPOL(s626_get_mode(dev, chan));
}
static void s626_set_index_src(struct comedi_device *dev,
unsigned int chan, uint16_t value)
{
uint16_t mode;
mode = s626_get_mode(dev, chan);
mode &= ~S626_STDMSK_INDXSRC;
mode |= S626_SET_STD_INDXSRC(value != 0);
s626_set_mode(dev, chan, mode, false);
}
static uint16_t s626_get_index_src(struct comedi_device *dev,
unsigned int chan)
{
return S626_GET_STD_INDXSRC(s626_get_mode(dev, chan));
}
static void s626_pulse_index(struct comedi_device *dev,
unsigned int chan)
{
if (chan < 3) {
uint16_t cra;
cra = s626_debi_read(dev, S626_LP_CRA(chan));
s626_debi_write(dev, S626_LP_CRA(chan),
(cra ^ S626_CRAMSK_INDXPOL_A));
s626_debi_write(dev, S626_LP_CRA(chan), cra);
} else {
uint16_t crb;
crb = s626_debi_read(dev, S626_LP_CRB(chan));
crb &= ~S626_CRBMSK_INTCTRL;
s626_debi_write(dev, S626_LP_CRB(chan),
(crb ^ S626_CRBMSK_INDXPOL_B));
s626_debi_write(dev, S626_LP_CRB(chan), crb);
}
}
static unsigned int s626_ai_reg_to_uint(unsigned int data)
{
return ((data >> 18) & 0x3fff) ^ 0x2000;
}
static int s626_dio_set_irq(struct comedi_device *dev, unsigned int chan)
{
unsigned int group = chan / 16;
unsigned int mask = 1 << (chan - (16 * group));
unsigned int status;
status = s626_debi_read(dev, S626_LP_RDEDGSEL(group));
s626_debi_write(dev, S626_LP_WREDGSEL(group), mask | status);
status = s626_debi_read(dev, S626_LP_RDINTSEL(group));
s626_debi_write(dev, S626_LP_WRINTSEL(group), mask | status);
s626_debi_write(dev, S626_LP_MISC1, S626_MISC1_EDCAP);
status = s626_debi_read(dev, S626_LP_RDCAPSEL(group));
s626_debi_write(dev, S626_LP_WRCAPSEL(group), mask | status);
return 0;
}
static int s626_dio_reset_irq(struct comedi_device *dev, unsigned int group,
unsigned int mask)
{
s626_debi_write(dev, S626_LP_MISC1, S626_MISC1_NOEDCAP);
s626_debi_write(dev, S626_LP_WRCAPSEL(group), mask);
return 0;
}
static int s626_dio_clear_irq(struct comedi_device *dev)
{
unsigned int group;
s626_debi_write(dev, S626_LP_MISC1, S626_MISC1_NOEDCAP);
for (group = 0; group < S626_DIO_BANKS; group++)
s626_debi_write(dev, S626_LP_WRCAPSEL(group), 0xffff);
return 0;
}
static void s626_handle_dio_interrupt(struct comedi_device *dev,
uint16_t irqbit, uint8_t group)
{
struct s626_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_cmd *cmd = &s->async->cmd;
s626_dio_reset_irq(dev, group, irqbit);
if (devpriv->ai_cmd_running) {
if ((irqbit >> (cmd->start_arg - (16 * group))) == 1 &&
cmd->start_src == TRIG_EXT) {
s626_mc_enable(dev, S626_MC1_ERPS1, S626_P_MC1);
if (cmd->scan_begin_src == TRIG_EXT)
s626_dio_set_irq(dev, cmd->scan_begin_arg);
}
if ((irqbit >> (cmd->scan_begin_arg - (16 * group))) == 1 &&
cmd->scan_begin_src == TRIG_EXT) {
s626_mc_enable(dev, S626_MC2_ADC_RPS, S626_P_MC2);
if (cmd->convert_src == TRIG_EXT) {
devpriv->ai_convert_count = cmd->chanlist_len;
s626_dio_set_irq(dev, cmd->convert_arg);
}
if (cmd->convert_src == TRIG_TIMER) {
devpriv->ai_convert_count = cmd->chanlist_len;
s626_set_enable(dev, 5, S626_CLKENAB_ALWAYS);
}
}
if ((irqbit >> (cmd->convert_arg - (16 * group))) == 1 &&
cmd->convert_src == TRIG_EXT) {
s626_mc_enable(dev, S626_MC2_ADC_RPS, S626_P_MC2);
devpriv->ai_convert_count--;
if (devpriv->ai_convert_count > 0)
s626_dio_set_irq(dev, cmd->convert_arg);
}
}
}
static void s626_check_dio_interrupts(struct comedi_device *dev)
{
uint16_t irqbit;
uint8_t group;
for (group = 0; group < S626_DIO_BANKS; group++) {
irqbit = 0;
irqbit = s626_debi_read(dev, S626_LP_RDCAPFLG(group));
if (irqbit) {
s626_handle_dio_interrupt(dev, irqbit, group);
return;
}
}
}
static void s626_check_counter_interrupts(struct comedi_device *dev)
{
struct s626_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
uint16_t irqbit;
irqbit = s626_debi_read(dev, S626_LP_RDMISC2);
if (irqbit & S626_IRQ_COINT1A) {
s626_reset_cap_flags(dev, 0);
}
if (irqbit & S626_IRQ_COINT2A) {
s626_reset_cap_flags(dev, 1);
}
if (irqbit & S626_IRQ_COINT3A) {
s626_reset_cap_flags(dev, 2);
}
if (irqbit & S626_IRQ_COINT1B) {
s626_reset_cap_flags(dev, 3);
}
if (irqbit & S626_IRQ_COINT2B) {
s626_reset_cap_flags(dev, 4);
if (devpriv->ai_convert_count > 0) {
devpriv->ai_convert_count--;
if (devpriv->ai_convert_count == 0)
s626_set_enable(dev, 4, S626_CLKENAB_INDEX);
if (cmd->convert_src == TRIG_TIMER) {
s626_mc_enable(dev, S626_MC2_ADC_RPS,
S626_P_MC2);
}
}
}
if (irqbit & S626_IRQ_COINT3B) {
s626_reset_cap_flags(dev, 5);
if (cmd->scan_begin_src == TRIG_TIMER) {
s626_mc_enable(dev, S626_MC2_ADC_RPS, S626_P_MC2);
}
if (cmd->convert_src == TRIG_TIMER) {
devpriv->ai_convert_count = cmd->chanlist_len;
s626_set_enable(dev, 4, S626_CLKENAB_ALWAYS);
}
}
}
static bool s626_handle_eos_interrupt(struct comedi_device *dev)
{
struct s626_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
uint32_t *readaddr = (uint32_t *)devpriv->ana_buf.logical_base + 1;
bool finished = false;
int i;
for (i = 0; i < cmd->chanlist_len; i++) {
unsigned short tempdata;
tempdata = s626_ai_reg_to_uint(*readaddr);
readaddr++;
cfc_write_to_buffer(s, tempdata);
}
async->events |= COMEDI_CB_EOS;
if (!devpriv->ai_continuous)
devpriv->ai_sample_count--;
if (devpriv->ai_sample_count <= 0) {
devpriv->ai_cmd_running = 0;
s626_mc_disable(dev, S626_MC1_ERPS1, S626_P_MC1);
async->events |= COMEDI_CB_EOA;
finished = true;
}
if (devpriv->ai_cmd_running && cmd->scan_begin_src == TRIG_EXT)
s626_dio_set_irq(dev, cmd->scan_begin_arg);
comedi_event(dev, s);
return finished;
}
static irqreturn_t s626_irq_handler(int irq, void *d)
{
struct comedi_device *dev = d;
unsigned long flags;
uint32_t irqtype, irqstatus;
if (!dev->attached)
return IRQ_NONE;
spin_lock_irqsave(&dev->spinlock, flags);
irqstatus = readl(dev->mmio + S626_P_IER);
irqtype = readl(dev->mmio + S626_P_ISR);
writel(0, dev->mmio + S626_P_IER);
writel(irqtype, dev->mmio + S626_P_ISR);
switch (irqtype) {
case S626_IRQ_RPS1:
if (s626_handle_eos_interrupt(dev))
irqstatus = 0;
break;
case S626_IRQ_GPIO3:
s626_check_dio_interrupts(dev);
s626_check_counter_interrupts(dev);
break;
}
writel(irqstatus, dev->mmio + S626_P_IER);
spin_unlock_irqrestore(&dev->spinlock, flags);
return IRQ_HANDLED;
}
static void s626_reset_adc(struct comedi_device *dev, uint8_t *ppl)
{
struct s626_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_cmd *cmd = &s->async->cmd;
uint32_t *rps;
uint32_t jmp_adrs;
uint16_t i;
uint16_t n;
uint32_t local_ppl;
s626_mc_disable(dev, S626_MC1_ERPS1, S626_P_MC1);
rps = (uint32_t *)devpriv->rps_buf.logical_base;
writel((uint32_t)devpriv->rps_buf.physical_base,
dev->mmio + S626_P_RPSADDR1);
if (cmd != NULL && cmd->scan_begin_src != TRIG_FOLLOW) {
*rps++ = S626_RPS_PAUSE | S626_RPS_SIGADC;
*rps++ = S626_RPS_CLRSIGNAL | S626_RPS_SIGADC;
}
*rps++ = S626_RPS_LDREG | (S626_P_DEBICMD >> 2);
*rps++ = S626_DEBI_CMD_WRWORD | S626_LP_GSEL;
*rps++ = S626_RPS_LDREG | (S626_P_DEBIAD >> 2);
*rps++ = S626_GSEL_BIPOLAR5V;
*rps++ = S626_RPS_CLRSIGNAL | S626_RPS_DEBI;
*rps++ = S626_RPS_UPLOAD | S626_RPS_DEBI;
*rps++ = S626_RPS_PAUSE | S626_RPS_DEBI;
for (devpriv->adc_items = 0; devpriv->adc_items < 16;
devpriv->adc_items++) {
local_ppl = (*ppl << 8) | (*ppl & 0x10 ? S626_GSEL_BIPOLAR5V :
S626_GSEL_BIPOLAR10V);
*rps++ = S626_RPS_LDREG | (S626_P_DEBICMD >> 2);
*rps++ = S626_DEBI_CMD_WRWORD | S626_LP_GSEL;
*rps++ = S626_RPS_LDREG | (S626_P_DEBIAD >> 2);
*rps++ = local_ppl;
*rps++ = S626_RPS_CLRSIGNAL | S626_RPS_DEBI;
*rps++ = S626_RPS_UPLOAD | S626_RPS_DEBI;
*rps++ = S626_RPS_PAUSE | S626_RPS_DEBI;
*rps++ = S626_RPS_LDREG | (S626_P_DEBICMD >> 2);
*rps++ = S626_DEBI_CMD_WRWORD | S626_LP_ISEL;
*rps++ = S626_RPS_LDREG | (S626_P_DEBIAD >> 2);
*rps++ = local_ppl;
*rps++ = S626_RPS_CLRSIGNAL | S626_RPS_DEBI;
*rps++ = S626_RPS_UPLOAD | S626_RPS_DEBI;
*rps++ = S626_RPS_PAUSE | S626_RPS_DEBI;
jmp_adrs =
(uint32_t)devpriv->rps_buf.physical_base +
(uint32_t)((unsigned long)rps -
(unsigned long)devpriv->
rps_buf.logical_base);
for (i = 0; i < (10 * S626_RPSCLK_PER_US / 2); i++) {
jmp_adrs += 8;
*rps++ = S626_RPS_JUMP;
*rps++ = jmp_adrs;
}
if (cmd != NULL && cmd->convert_src != TRIG_NOW) {
*rps++ = S626_RPS_PAUSE | S626_RPS_SIGADC;
*rps++ = S626_RPS_CLRSIGNAL | S626_RPS_SIGADC;
}
*rps++ = S626_RPS_LDREG | (S626_P_GPIO >> 2);
*rps++ = S626_GPIO_BASE | S626_GPIO1_LO;
*rps++ = S626_RPS_NOP;
*rps++ = S626_RPS_LDREG | (S626_P_GPIO >> 2);
*rps++ = S626_GPIO_BASE | S626_GPIO1_HI;
*rps++ = S626_RPS_PAUSE | S626_RPS_GPIO2;
*rps++ = S626_RPS_STREG |
(S626_BUGFIX_STREG(S626_P_FB_BUFFER1) >> 2);
*rps++ = (uint32_t)devpriv->ana_buf.physical_base +
(devpriv->adc_items << 2);
if (*ppl++ & S626_EOPL) {
devpriv->adc_items++;
break;
}
}
for (n = 0; n < (2 * S626_RPSCLK_PER_US); n++)
*rps++ = S626_RPS_NOP;
*rps++ = S626_RPS_LDREG | (S626_P_GPIO >> 2);
*rps++ = S626_GPIO_BASE | S626_GPIO1_LO;
*rps++ = S626_RPS_NOP;
*rps++ = S626_RPS_LDREG | (S626_P_GPIO >> 2);
*rps++ = S626_GPIO_BASE | S626_GPIO1_HI;
*rps++ = S626_RPS_PAUSE | S626_RPS_GPIO2;
*rps++ = S626_RPS_STREG | (S626_BUGFIX_STREG(S626_P_FB_BUFFER1) >> 2);
*rps++ = (uint32_t)devpriv->ana_buf.physical_base +
(devpriv->adc_items << 2);
if (devpriv->ai_cmd_running == 1)
*rps++ = S626_RPS_IRQ;
*rps++ = S626_RPS_JUMP;
*rps++ = (uint32_t)devpriv->rps_buf.physical_base;
}
static int s626_ai_rinsn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct s626_private *devpriv = dev->private;
uint8_t i;
int32_t *readaddr;
s626_mc_enable(dev, S626_MC2_ADC_RPS, S626_P_MC2);
while (s626_mc_test(dev, S626_MC2_ADC_RPS, S626_P_MC2))
;
readaddr = (uint32_t *)devpriv->ana_buf.logical_base + 1;
for (i = 0; i < devpriv->adc_items; i++) {
*data = s626_ai_reg_to_uint(*readaddr++);
data++;
}
return i;
}
static int s626_ai_eoc(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned long context)
{
unsigned int status;
status = readl(dev->mmio + S626_P_PSR);
if (status & S626_PSR_GPIO2)
return 0;
return -EBUSY;
}
static int s626_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
uint16_t chan = CR_CHAN(insn->chanspec);
uint16_t range = CR_RANGE(insn->chanspec);
uint16_t adc_spec = 0;
uint32_t gpio_image;
uint32_t tmp;
int ret;
int n;
if (range == 0)
adc_spec = (chan << 8) | (S626_GSEL_BIPOLAR5V);
else
adc_spec = (chan << 8) | (S626_GSEL_BIPOLAR10V);
s626_debi_write(dev, S626_LP_GSEL, adc_spec);
s626_debi_write(dev, S626_LP_ISEL, adc_spec);
for (n = 0; n < insn->n; n++) {
udelay(10);
gpio_image = readl(dev->mmio + S626_P_GPIO);
writel(gpio_image & ~S626_GPIO1_HI, dev->mmio + S626_P_GPIO);
writel(gpio_image & ~S626_GPIO1_HI, dev->mmio + S626_P_GPIO);
writel(gpio_image & ~S626_GPIO1_HI, dev->mmio + S626_P_GPIO);
writel(gpio_image | S626_GPIO1_HI, dev->mmio + S626_P_GPIO);
ret = comedi_timeout(dev, s, insn, s626_ai_eoc, 0);
if (ret)
return ret;
if (n != 0) {
tmp = readl(dev->mmio + S626_P_FB_BUFFER1);
data[n - 1] = s626_ai_reg_to_uint(tmp);
}
udelay(4);
}
gpio_image = readl(dev->mmio + S626_P_GPIO);
writel(gpio_image & ~S626_GPIO1_HI, dev->mmio + S626_P_GPIO);
writel(gpio_image & ~S626_GPIO1_HI, dev->mmio + S626_P_GPIO);
writel(gpio_image & ~S626_GPIO1_HI, dev->mmio + S626_P_GPIO);
writel(gpio_image | S626_GPIO1_HI, dev->mmio + S626_P_GPIO);
ret = comedi_timeout(dev, s, insn, s626_ai_eoc, 0);
if (ret)
return ret;
if (n != 0) {
tmp = readl(dev->mmio + S626_P_FB_BUFFER1);
data[n - 1] = s626_ai_reg_to_uint(tmp);
}
return n;
}
static int s626_ai_load_polllist(uint8_t *ppl, struct comedi_cmd *cmd)
{
int n;
for (n = 0; n < cmd->chanlist_len; n++) {
if (CR_RANGE(cmd->chanlist[n]) == 0)
ppl[n] = CR_CHAN(cmd->chanlist[n]) | S626_RANGE_5V;
else
ppl[n] = CR_CHAN(cmd->chanlist[n]) | S626_RANGE_10V;
}
if (n != 0)
ppl[n - 1] |= S626_EOPL;
return n;
}
static int s626_ai_inttrig(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned int trig_num)
{
struct comedi_cmd *cmd = &s->async->cmd;
if (trig_num != cmd->start_arg)
return -EINVAL;
s626_mc_enable(dev, S626_MC1_ERPS1, S626_P_MC1);
s->async->inttrig = NULL;
return 1;
}
static int s626_ns_to_timer(unsigned int *nanosec, unsigned int flags)
{
int divider, base;
base = 500;
switch (flags & TRIG_ROUND_MASK) {
case TRIG_ROUND_NEAREST:
default:
divider = (*nanosec + base / 2) / base;
break;
case TRIG_ROUND_DOWN:
divider = (*nanosec) / base;
break;
case TRIG_ROUND_UP:
divider = (*nanosec + base - 1) / base;
break;
}
*nanosec = base * divider;
return divider - 1;
}
static void s626_timer_load(struct comedi_device *dev,
unsigned int chan, int tick)
{
uint16_t setup =
S626_SET_STD_LOADSRC(S626_LOADSRC_INDX) |
S626_SET_STD_INDXSRC(S626_INDXSRC_SOFT) |
S626_SET_STD_ENCMODE(S626_ENCMODE_TIMER) |
S626_SET_STD_CLKPOL(S626_CNTDIR_DOWN) |
S626_SET_STD_CLKMULT(S626_CLKMULT_1X) |
S626_SET_STD_CLKENAB(S626_CLKENAB_INDEX);
uint16_t value_latchsrc = S626_LATCHSRC_A_INDXA;
s626_set_mode(dev, chan, setup, false);
s626_preload(dev, chan, tick);
s626_set_load_trig(dev, chan, 0);
s626_pulse_index(dev, chan);
s626_set_load_trig(dev, chan, 1);
s626_set_int_src(dev, chan, S626_INTSRC_OVER);
s626_set_latch_source(dev, chan, value_latchsrc);
}
static int s626_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct s626_private *devpriv = dev->private;
uint8_t ppl[16];
struct comedi_cmd *cmd = &s->async->cmd;
int tick;
if (devpriv->ai_cmd_running) {
dev_err(dev->class_dev,
"s626_ai_cmd: Another ai_cmd is running\n");
return -EBUSY;
}
writel(0, dev->mmio + S626_P_IER);
writel(S626_IRQ_RPS1 | S626_IRQ_GPIO3, dev->mmio + S626_P_ISR);
s626_dio_clear_irq(dev);
devpriv->ai_cmd_running = 0;
if (cmd == NULL)
return -EINVAL;
s626_ai_load_polllist(ppl, cmd);
devpriv->ai_cmd_running = 1;
devpriv->ai_convert_count = 0;
switch (cmd->scan_begin_src) {
case TRIG_FOLLOW:
break;
case TRIG_TIMER:
tick = s626_ns_to_timer(&cmd->scan_begin_arg, cmd->flags);
s626_timer_load(dev, 5, tick);
s626_set_enable(dev, 5, S626_CLKENAB_ALWAYS);
break;
case TRIG_EXT:
if (cmd->start_src != TRIG_EXT)
s626_dio_set_irq(dev, cmd->scan_begin_arg);
break;
}
switch (cmd->convert_src) {
case TRIG_NOW:
break;
case TRIG_TIMER:
tick = s626_ns_to_timer(&cmd->convert_arg, cmd->flags);
s626_timer_load(dev, 4, tick);
s626_set_enable(dev, 4, S626_CLKENAB_INDEX);
break;
case TRIG_EXT:
if (cmd->scan_begin_src != TRIG_EXT &&
cmd->start_src == TRIG_EXT)
s626_dio_set_irq(dev, cmd->convert_arg);
break;
}
switch (cmd->stop_src) {
case TRIG_COUNT:
devpriv->ai_sample_count = cmd->stop_arg;
devpriv->ai_continuous = 0;
break;
case TRIG_NONE:
devpriv->ai_continuous = 1;
devpriv->ai_sample_count = 1;
break;
}
s626_reset_adc(dev, ppl);
switch (cmd->start_src) {
case TRIG_NOW:
s626_mc_enable(dev, S626_MC1_ERPS1, S626_P_MC1);
s->async->inttrig = NULL;
break;
case TRIG_EXT:
s626_dio_set_irq(dev, cmd->start_arg);
s->async->inttrig = NULL;
break;
case TRIG_INT:
s->async->inttrig = s626_ai_inttrig;
break;
}
writel(S626_IRQ_GPIO3 | S626_IRQ_RPS1, dev->mmio + S626_P_IER);
return 0;
}
static int s626_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
int err = 0;
unsigned int arg;
err |= cfc_check_trigger_src(&cmd->start_src,
TRIG_NOW | TRIG_INT | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_EXT | TRIG_FOLLOW);
err |= cfc_check_trigger_src(&cmd->convert_src,
TRIG_TIMER | TRIG_EXT | TRIG_NOW);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->convert_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
switch (cmd->start_src) {
case TRIG_NOW:
case TRIG_INT:
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
break;
case TRIG_EXT:
err |= cfc_check_trigger_arg_max(&cmd->start_arg, 39);
break;
}
if (cmd->scan_begin_src == TRIG_EXT)
err |= cfc_check_trigger_arg_max(&cmd->scan_begin_arg, 39);
if (cmd->convert_src == TRIG_EXT)
err |= cfc_check_trigger_arg_max(&cmd->convert_arg, 39);
#define S626_MAX_SPEED 200000
#define S626_MIN_SPEED 2000000000
if (cmd->scan_begin_src == TRIG_TIMER) {
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
S626_MAX_SPEED);
err |= cfc_check_trigger_arg_max(&cmd->scan_begin_arg,
S626_MIN_SPEED);
} else {
}
if (cmd->convert_src == TRIG_TIMER) {
err |= cfc_check_trigger_arg_min(&cmd->convert_arg,
S626_MAX_SPEED);
err |= cfc_check_trigger_arg_max(&cmd->convert_arg,
S626_MIN_SPEED);
} else {
}
err |= cfc_check_trigger_arg_is(&cmd->scan_end_arg, cmd->chanlist_len);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_max(&cmd->stop_arg, 0x00ffffff);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->scan_begin_arg;
s626_ns_to_timer(&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->scan_begin_arg, arg);
}
if (cmd->convert_src == TRIG_TIMER) {
arg = cmd->convert_arg;
s626_ns_to_timer(&arg, cmd->flags);
err |= cfc_check_trigger_arg_is(&cmd->convert_arg, arg);
if (cmd->scan_begin_src == TRIG_TIMER) {
arg = cmd->convert_arg * cmd->scan_end_arg;
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg,
arg);
}
}
if (err)
return 4;
return 0;
}
static int s626_ai_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct s626_private *devpriv = dev->private;
s626_mc_disable(dev, S626_MC1_ERPS1, S626_P_MC1);
writel(0, dev->mmio + S626_P_IER);
devpriv->ai_cmd_running = 0;
return 0;
}
static int s626_ao_winsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct s626_private *devpriv = dev->private;
int i;
int ret;
uint16_t chan = CR_CHAN(insn->chanspec);
int16_t dacdata;
for (i = 0; i < insn->n; i++) {
dacdata = (int16_t) data[i];
devpriv->ao_readback[CR_CHAN(insn->chanspec)] = data[i];
dacdata -= (0x1fff);
ret = s626_set_dac(dev, chan, dacdata);
if (ret)
return ret;
}
return i;
}
static int s626_ao_rinsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct s626_private *devpriv = dev->private;
int i;
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[CR_CHAN(insn->chanspec)];
return i;
}
static void s626_dio_init(struct comedi_device *dev)
{
uint16_t group;
s626_debi_write(dev, S626_LP_MISC1, S626_MISC1_NOEDCAP);
for (group = 0; group < S626_DIO_BANKS; group++) {
s626_debi_write(dev, S626_LP_WRINTSEL(group), 0);
s626_debi_write(dev, S626_LP_WRCAPSEL(group), 0xffff);
s626_debi_write(dev, S626_LP_WREDGSEL(group), 0);
s626_debi_write(dev, S626_LP_WRDOUT(group), 0);
}
}
static int s626_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long group = (unsigned long)s->private;
if (comedi_dio_update_state(s, data))
s626_debi_write(dev, S626_LP_WRDOUT(group), s->state);
data[1] = s626_debi_read(dev, S626_LP_RDDIN(group));
return insn->n;
}
static int s626_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned long group = (unsigned long)s->private;
int ret;
ret = comedi_dio_insn_config(dev, s, insn, data, 0);
if (ret)
return ret;
s626_debi_write(dev, S626_LP_WRDOUT(group), s->io_bits);
return insn->n;
}
static int s626_enc_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
uint16_t setup =
S626_SET_STD_LOADSRC(S626_LOADSRC_INDX) |
S626_SET_STD_INDXSRC(S626_INDXSRC_SOFT) |
S626_SET_STD_ENCMODE(S626_ENCMODE_COUNTER) |
S626_SET_STD_CLKPOL(S626_CLKPOL_POS) |
S626_SET_STD_CLKMULT(S626_CLKMULT_1X) |
S626_SET_STD_CLKENAB(S626_CLKENAB_INDEX);
uint16_t value_latchsrc = S626_LATCHSRC_AB_READ;
uint16_t enab = S626_CLKENAB_ALWAYS;
s626_set_mode(dev, chan, setup, true);
s626_preload(dev, chan, data[0]);
s626_pulse_index(dev, chan);
s626_set_latch_source(dev, chan, value_latchsrc);
s626_set_enable(dev, chan, (enab != 0));
return insn->n;
}
static int s626_enc_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
uint16_t cntr_latch_reg = S626_LP_CNTR(chan);
int i;
for (i = 0; i < insn->n; i++) {
unsigned int val;
val = s626_debi_read(dev, cntr_latch_reg);
val |= (s626_debi_read(dev, cntr_latch_reg + 2) << 16);
data[i] = val;
}
return insn->n;
}
static int s626_enc_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int chan = CR_CHAN(insn->chanspec);
s626_preload(dev, chan, data[0]);
s626_set_load_trig(dev, chan, 0);
s626_pulse_index(dev, chan);
s626_set_load_trig(dev, chan, 2);
return 1;
}
static void s626_write_misc2(struct comedi_device *dev, uint16_t new_image)
{
s626_debi_write(dev, S626_LP_MISC1, S626_MISC1_WENABLE);
s626_debi_write(dev, S626_LP_WRMISC2, new_image);
s626_debi_write(dev, S626_LP_MISC1, S626_MISC1_WDISABLE);
}
static void s626_close_dma_b(struct comedi_device *dev,
struct s626_buffer_dma *pdma, size_t bsize)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
void *vbptr;
dma_addr_t vpptr;
if (pdma == NULL)
return;
vbptr = pdma->logical_base;
vpptr = pdma->physical_base;
if (vbptr) {
pci_free_consistent(pcidev, bsize, vbptr, vpptr);
pdma->logical_base = NULL;
pdma->physical_base = 0;
}
}
static void s626_counters_init(struct comedi_device *dev)
{
int chan;
uint16_t setup =
S626_SET_STD_LOADSRC(S626_LOADSRC_INDX) |
S626_SET_STD_INDXSRC(S626_INDXSRC_SOFT) |
S626_SET_STD_ENCMODE(S626_ENCMODE_COUNTER) |
S626_SET_STD_CLKPOL(S626_CLKPOL_POS) |
S626_SET_STD_CLKMULT(S626_CLKMULT_1X) |
S626_SET_STD_CLKENAB(S626_CLKENAB_INDEX);
for (chan = 0; chan < S626_ENCODER_CHANNELS; chan++) {
s626_set_mode(dev, chan, setup, true);
s626_set_int_src(dev, chan, 0);
s626_reset_cap_flags(dev, chan);
s626_set_enable(dev, chan, S626_CLKENAB_ALWAYS);
}
}
static int s626_allocate_dma_buffers(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct s626_private *devpriv = dev->private;
void *addr;
dma_addr_t appdma;
addr = pci_alloc_consistent(pcidev, S626_DMABUF_SIZE, &appdma);
if (!addr)
return -ENOMEM;
devpriv->ana_buf.logical_base = addr;
devpriv->ana_buf.physical_base = appdma;
addr = pci_alloc_consistent(pcidev, S626_DMABUF_SIZE, &appdma);
if (!addr)
return -ENOMEM;
devpriv->rps_buf.logical_base = addr;
devpriv->rps_buf.physical_base = appdma;
return 0;
}
static int s626_initialize(struct comedi_device *dev)
{
struct s626_private *devpriv = dev->private;
dma_addr_t phys_buf;
uint16_t chan;
int i;
int ret;
s626_mc_enable(dev, S626_MC1_DEBI | S626_MC1_AUDIO | S626_MC1_I2C,
S626_P_MC1);
writel(S626_DEBI_CFG_SLAVE16 |
(S626_DEBI_TOUT << S626_DEBI_CFG_TOUT_BIT) | S626_DEBI_SWAP |
S626_DEBI_CFG_INTEL, dev->mmio + S626_P_DEBICFG);
writel(S626_DEBI_PAGE_DISABLE, dev->mmio + S626_P_DEBIPAGE);
writel(S626_GPIO_BASE | S626_GPIO1_HI, dev->mmio + S626_P_GPIO);
devpriv->i2c_adrs = 0xA0;
writel(S626_I2C_CLKSEL | S626_I2C_ABORT,
dev->mmio + S626_P_I2CSTAT);
s626_mc_enable(dev, S626_MC2_UPLD_IIC, S626_P_MC2);
ret = comedi_timeout(dev, NULL, NULL, s626_i2c_handshake_eoc, 0);
if (ret)
return ret;
for (i = 0; i < 2; i++) {
writel(S626_I2C_CLKSEL, dev->mmio + S626_P_I2CSTAT);
s626_mc_enable(dev, S626_MC2_UPLD_IIC, S626_P_MC2);
ret = comedi_timeout(dev, NULL, NULL, s626_i2c_handshake_eoc, 0);
if (ret)
return ret;
}
writel(S626_ACON2_INIT, dev->mmio + S626_P_ACON2);
writel(S626_RSD1 | S626_SIB_A1, dev->mmio + S626_P_TSL1);
writel(S626_RSD1 | S626_SIB_A1 | S626_EOS,
dev->mmio + S626_P_TSL1 + 4);
writel(S626_ACON1_ADCSTART, dev->mmio + S626_P_ACON1);
writel((uint32_t)devpriv->rps_buf.physical_base,
dev->mmio + S626_P_RPSADDR1);
writel(0, dev->mmio + S626_P_RPSPAGE1);
writel(0, dev->mmio + S626_P_RPS1_TOUT);
#if 0
{
struct comedi_subdevice *s = dev->read_subdev;
uint8_t poll_list;
uint16_t adc_data;
uint16_t start_val;
uint16_t index;
unsigned int data[16];
poll_list = S626_EOPL;
s626_reset_adc(dev, &poll_list);
s626_ai_rinsn(dev, s, NULL, data);
start_val = data[0];
for (index = 0; index < 500; index++) {
s626_ai_rinsn(dev, s, NULL, data);
adc_data = data[0];
if (adc_data != start_val)
break;
}
}
#endif
writel(0, dev->mmio + S626_P_PCI_BT_A);
phys_buf = devpriv->ana_buf.physical_base +
(S626_DAC_WDMABUF_OS * sizeof(uint32_t));
writel((uint32_t)phys_buf, dev->mmio + S626_P_BASEA2_OUT);
writel((uint32_t)(phys_buf + sizeof(uint32_t)),
dev->mmio + S626_P_PROTA2_OUT);
devpriv->dac_wbuf = (uint32_t *)devpriv->ana_buf.logical_base +
S626_DAC_WDMABUF_OS;
writel(8, dev->mmio + S626_P_PAGEA2_OUT);
writel(S626_XSD2 | S626_RSD3 | S626_SIB_A2 | S626_EOS,
dev->mmio + S626_VECTPORT(0));
writel(S626_LF_A2, dev->mmio + S626_VECTPORT(1));
writel(S626_ACON1_DACSTART, dev->mmio + S626_P_ACON1);
s626_load_trim_dacs(dev);
ret = s626_load_trim_dacs(dev);
if (ret)
return ret;
for (chan = 0; chan < S626_DAC_CHANNELS; chan++) {
ret = s626_set_dac(dev, chan, 0);
if (ret)
return ret;
}
s626_counters_init(dev);
s626_write_misc2(dev, (s626_debi_read(dev, S626_LP_RDMISC2) &
S626_MISC2_BATT_ENABLE));
s626_dio_init(dev);
return 0;
}
static int s626_auto_attach(struct comedi_device *dev,
unsigned long context_unused)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
struct s626_private *devpriv;
struct comedi_subdevice *s;
int ret;
devpriv = comedi_alloc_devpriv(dev, sizeof(*devpriv));
if (!devpriv)
return -ENOMEM;
ret = comedi_pci_enable(dev);
if (ret)
return ret;
dev->mmio = pci_ioremap_bar(pcidev, 0);
if (!dev->mmio)
return -ENOMEM;
writel(0, dev->mmio + S626_P_IER);
writel(S626_MC1_SOFT_RESET, dev->mmio + S626_P_MC1);
ret = s626_allocate_dma_buffers(dev);
if (ret)
return ret;
if (pcidev->irq) {
ret = request_irq(pcidev->irq, s626_irq_handler, IRQF_SHARED,
dev->board_name, dev);
if (ret == 0)
dev->irq = pcidev->irq;
}
ret = comedi_alloc_subdevices(dev, 6);
if (ret)
return ret;
s = &dev->subdevices[0];
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_DIFF;
s->n_chan = S626_ADC_CHANNELS;
s->maxdata = 0x3fff;
s->range_table = &s626_range_table;
s->len_chanlist = S626_ADC_CHANNELS;
s->insn_read = s626_ai_insn_read;
if (dev->irq) {
dev->read_subdev = s;
s->subdev_flags |= SDF_CMD_READ;
s->do_cmd = s626_ai_cmd;
s->do_cmdtest = s626_ai_cmdtest;
s->cancel = s626_ai_cancel;
}
s = &dev->subdevices[1];
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = S626_DAC_CHANNELS;
s->maxdata = 0x3fff;
s->range_table = &range_bipolar10;
s->insn_write = s626_ao_winsn;
s->insn_read = s626_ao_rinsn;
s = &dev->subdevices[2];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = 16;
s->maxdata = 1;
s->io_bits = 0xffff;
s->private = (void *)0;
s->range_table = &range_digital;
s->insn_config = s626_dio_insn_config;
s->insn_bits = s626_dio_insn_bits;
s = &dev->subdevices[3];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = 16;
s->maxdata = 1;
s->io_bits = 0xffff;
s->private = (void *)1;
s->range_table = &range_digital;
s->insn_config = s626_dio_insn_config;
s->insn_bits = s626_dio_insn_bits;
s = &dev->subdevices[4];
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = 16;
s->maxdata = 1;
s->io_bits = 0xffff;
s->private = (void *)2;
s->range_table = &range_digital;
s->insn_config = s626_dio_insn_config;
s->insn_bits = s626_dio_insn_bits;
s = &dev->subdevices[5];
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE | SDF_LSAMPL;
s->n_chan = S626_ENCODER_CHANNELS;
s->maxdata = 0xffffff;
s->range_table = &range_unknown;
s->insn_config = s626_enc_insn_config;
s->insn_read = s626_enc_insn_read;
s->insn_write = s626_enc_insn_write;
ret = s626_initialize(dev);
if (ret)
return ret;
return 0;
}
static void s626_detach(struct comedi_device *dev)
{
struct s626_private *devpriv = dev->private;
if (devpriv) {
devpriv->ai_cmd_running = 0;
if (dev->mmio) {
writel(0, dev->mmio + S626_P_IER);
writel(S626_IRQ_GPIO3 | S626_IRQ_RPS1,
dev->mmio + S626_P_ISR);
s626_write_misc2(dev, 0);
writel(S626_MC1_SHUTDOWN, dev->mmio + S626_P_MC1);
writel(S626_ACON1_BASE, dev->mmio + S626_P_ACON1);
s626_close_dma_b(dev, &devpriv->rps_buf,
S626_DMABUF_SIZE);
s626_close_dma_b(dev, &devpriv->ana_buf,
S626_DMABUF_SIZE);
}
if (dev->irq)
free_irq(dev->irq, dev);
if (dev->mmio)
iounmap(dev->mmio);
}
comedi_pci_disable(dev);
}
static int s626_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
return comedi_pci_auto_config(dev, &s626_driver, id->driver_data);
}
