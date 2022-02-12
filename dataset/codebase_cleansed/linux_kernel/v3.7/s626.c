static void DEBItransfer(struct comedi_device *dev)
{
MC_ENABLE(P_MC2, MC2_UPLD_DEBI);
while (!MC_TEST(P_MC2, MC2_UPLD_DEBI))
;
while (RR7146(P_PSR) & PSR_DEBI_S)
;
}
static uint16_t DEBIread(struct comedi_device *dev, uint16_t addr)
{
uint16_t retval;
WR7146(P_DEBICMD, DEBI_CMD_RDWORD | addr);
DEBItransfer(dev);
retval = (uint16_t) RR7146(P_DEBIAD);
return retval;
}
static void DEBIwrite(struct comedi_device *dev, uint16_t addr, uint16_t wdata)
{
WR7146(P_DEBICMD, DEBI_CMD_WRWORD | addr);
WR7146(P_DEBIAD, wdata);
DEBItransfer(dev);
}
static void DEBIreplace(struct comedi_device *dev, uint16_t addr, uint16_t mask,
uint16_t wdata)
{
WR7146(P_DEBICMD, DEBI_CMD_RDWORD | addr);
DEBItransfer(dev);
WR7146(P_DEBICMD, DEBI_CMD_WRWORD | addr);
WR7146(P_DEBIAD, wdata | ((uint16_t) RR7146(P_DEBIAD) & mask));
DEBItransfer(dev);
}
static uint32_t I2Chandshake(struct comedi_device *dev, uint32_t val)
{
WR7146(P_I2CCTRL, val);
MC_ENABLE(P_MC2, MC2_UPLD_IIC);
while (!MC_TEST(P_MC2, MC2_UPLD_IIC))
;
while ((RR7146(P_I2CCTRL) & (I2C_BUSY | I2C_ERR)) == I2C_BUSY)
;
return RR7146(P_I2CCTRL) & I2C_ERR;
}
static uint8_t I2Cread(struct comedi_device *dev, uint8_t addr)
{
uint8_t rtnval;
if (I2Chandshake(dev, I2C_B2(I2C_ATTRSTART, I2CW)
| I2C_B1(I2C_ATTRSTOP, addr)
| I2C_B0(I2C_ATTRNOP, 0))) {
return 0;
}
if (I2Chandshake(dev, I2C_B2(I2C_ATTRSTART, I2CR)
|I2C_B1(I2C_ATTRSTOP, 0)
|I2C_B0(I2C_ATTRNOP, 0))) {
return 0;
}
rtnval = (uint8_t) (RR7146(P_I2CCTRL) >> 16);
return rtnval;
}
static void SendDAC(struct comedi_device *dev, uint32_t val)
{
DEBIwrite(dev, LP_DACPOL, devpriv->Dacpol);
*devpriv->pDacWBuf = val;
MC_ENABLE(P_MC1, MC1_A2OUT);
WR7146(P_ISR, ISR_AFOU);
while ((RR7146(P_MC1) & MC1_A2OUT) != 0)
;
SETVECT(0, XSD2 | RSD3 | SIB_A2);
while ((RR7146(P_SSR) & SSR_AF2_OUT) == 0)
;
SETVECT(0, XSD2 | XFIFO_2 | RSD2 | SIB_A2 | EOS);
if ((RR7146(P_FB_BUFFER2) & 0xFF000000) != 0) {
while ((RR7146(P_FB_BUFFER2) & 0xFF000000) != 0)
;
}
SETVECT(0, RSD3 | SIB_A2 | EOS);
while ((RR7146(P_FB_BUFFER2) & 0xFF000000) == 0)
;
}
static void SetDAC(struct comedi_device *dev, uint16_t chan, short dacdata)
{
register uint16_t signmask;
register uint32_t WSImage;
signmask = 1 << chan;
if (dacdata < 0) {
dacdata = -dacdata;
devpriv->Dacpol |= signmask;
} else
devpriv->Dacpol &= ~signmask;
if ((uint16_t) dacdata > 0x1FFF)
dacdata = 0x1FFF;
WSImage = (chan & 2) ? WS1 : WS2;
SETVECT(2, XSD2 | XFIFO_1 | WSImage);
SETVECT(3, XSD2 | XFIFO_0 | WSImage);
SETVECT(4, XSD2 | XFIFO_3 | WS3);
SETVECT(5, XSD2 | XFIFO_2 | WS3 | EOS);
SendDAC(dev, 0x0F000000
| 0x00004000
| ((uint32_t) (chan & 1) << 15)
| (uint32_t) dacdata);
}
static void WriteTrimDAC(struct comedi_device *dev, uint8_t LogicalChan,
uint8_t DacData)
{
uint32_t chan;
devpriv->TrimSetpoint[LogicalChan] = (uint8_t) DacData;
chan = (uint32_t) trimchan[LogicalChan];
SETVECT(2, XSD2 | XFIFO_1 | WS3);
SETVECT(3, XSD2 | XFIFO_0 | WS3);
SETVECT(4, XSD2 | XFIFO_3 | WS1);
SETVECT(5, XSD2 | XFIFO_2 | WS1 | EOS);
SendDAC(dev, ((uint32_t) chan << 8)
| (uint32_t) DacData);
}
static void LoadTrimDACs(struct comedi_device *dev)
{
register uint8_t i;
for (i = 0; i < ARRAY_SIZE(trimchan); i++)
WriteTrimDAC(dev, i, I2Cread(dev, trimadrs[i]));
}
static uint32_t ReadLatch(struct comedi_device *dev, struct enc_private *k)
{
register uint32_t value;
value = (uint32_t) DEBIread(dev, k->MyLatchLsw);
value |= ((uint32_t) DEBIread(dev, k->MyLatchLsw + 2) << 16);
return value;
}
static void SetLatchSource(struct comedi_device *dev, struct enc_private *k,
uint16_t value)
{
DEBIreplace(dev, k->MyCRB,
(uint16_t) (~(CRBMSK_INTCTRL | CRBMSK_LATCHSRC)),
(uint16_t) (value << CRBBIT_LATCHSRC));
}
static void Preload(struct comedi_device *dev, struct enc_private *k,
uint32_t value)
{
DEBIwrite(dev, (uint16_t) (k->MyLatchLsw), (uint16_t) value);
DEBIwrite(dev, (uint16_t) (k->MyLatchLsw + 2),
(uint16_t) (value >> 16));
}
static unsigned int s626_ai_reg_to_uint(int data)
{
unsigned int tempdata;
tempdata = (data >> 18);
if (tempdata & 0x2000)
tempdata &= 0x1fff;
else
tempdata += (1 << 13);
return tempdata;
}
static int s626_dio_set_irq(struct comedi_device *dev, unsigned int chan)
{
unsigned int group;
unsigned int bitmask;
unsigned int status;
group = chan / 16;
bitmask = 1 << (chan - (16 * group));
status = DEBIread(dev,
((struct dio_private *)(dev->subdevices + 2 +
group)->private)->RDEdgSel);
DEBIwrite(dev,
((struct dio_private *)(dev->subdevices + 2 +
group)->private)->WREdgSel,
bitmask | status);
status = DEBIread(dev,
((struct dio_private *)(dev->subdevices + 2 +
group)->private)->RDIntSel);
DEBIwrite(dev,
((struct dio_private *)(dev->subdevices + 2 +
group)->private)->WRIntSel,
bitmask | status);
DEBIwrite(dev, LP_MISC1, MISC1_EDCAP);
status = DEBIread(dev,
((struct dio_private *)(dev->subdevices + 2 +
group)->private)->RDCapSel);
DEBIwrite(dev,
((struct dio_private *)(dev->subdevices + 2 +
group)->private)->WRCapSel,
bitmask | status);
return 0;
}
static int s626_dio_reset_irq(struct comedi_device *dev, unsigned int group,
unsigned int mask)
{
DEBIwrite(dev, LP_MISC1, MISC1_NOEDCAP);
DEBIwrite(dev,
((struct dio_private *)(dev->subdevices + 2 +
group)->private)->WRCapSel, mask);
return 0;
}
static int s626_dio_clear_irq(struct comedi_device *dev)
{
unsigned int group;
DEBIwrite(dev, LP_MISC1, MISC1_NOEDCAP);
for (group = 0; group < S626_DIO_BANKS; group++) {
DEBIwrite(dev,
((struct dio_private *)(dev->subdevices + 2 +
group)->private)->WRCapSel,
0xffff);
}
return 0;
}
static irqreturn_t s626_irq_handler(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s;
struct comedi_cmd *cmd;
struct enc_private *k;
unsigned long flags;
int32_t *readaddr;
uint32_t irqtype, irqstatus;
int i = 0;
short tempdata;
uint8_t group;
uint16_t irqbit;
if (dev->attached == 0)
return IRQ_NONE;
spin_lock_irqsave(&dev->spinlock, flags);
irqstatus = readl(devpriv->base_addr + P_IER);
irqtype = readl(devpriv->base_addr + P_ISR);
writel(0, devpriv->base_addr + P_IER);
writel(irqtype, devpriv->base_addr + P_ISR);
switch (irqtype) {
case IRQ_RPS1:
s = dev->subdevices;
cmd = &(s->async->cmd);
readaddr = (int32_t *) devpriv->ANABuf.LogicalBase + 1;
for (i = 0; i < (s->async->cmd.chanlist_len); i++) {
tempdata = s626_ai_reg_to_uint((int)*readaddr);
readaddr++;
if (cfc_write_to_buffer(s, tempdata) == 0)
printk
("s626_irq_handler: cfc_write_to_buffer error!\n");
}
s->async->events |= COMEDI_CB_EOS;
if (!(devpriv->ai_continous))
devpriv->ai_sample_count--;
if (devpriv->ai_sample_count <= 0) {
devpriv->ai_cmd_running = 0;
MC_DISABLE(P_MC1, MC1_ERPS1);
s->async->events |= COMEDI_CB_EOA;
irqstatus = 0;
}
if (devpriv->ai_cmd_running && cmd->scan_begin_src == TRIG_EXT)
s626_dio_set_irq(dev, cmd->scan_begin_arg);
comedi_event(dev, s);
break;
case IRQ_GPIO3:
s = dev->subdevices;
cmd = &(s->async->cmd);
for (group = 0; group < S626_DIO_BANKS; group++) {
irqbit = 0;
irqbit = DEBIread(dev,
((struct dio_private *)(dev->
subdevices +
2 +
group)->
private)->RDCapFlg);
if (irqbit) {
s626_dio_reset_irq(dev, group, irqbit);
if (devpriv->ai_cmd_running) {
if ((irqbit >> (cmd->start_arg -
(16 * group)))
== 1 && cmd->start_src == TRIG_EXT) {
MC_ENABLE(P_MC1, MC1_ERPS1);
if (cmd->scan_begin_src ==
TRIG_EXT) {
s626_dio_set_irq(dev,
cmd->scan_begin_arg);
}
}
if ((irqbit >> (cmd->scan_begin_arg -
(16 * group)))
== 1
&& cmd->scan_begin_src ==
TRIG_EXT) {
MC_ENABLE(P_MC2, MC2_ADC_RPS);
if (cmd->convert_src ==
TRIG_EXT) {
devpriv->ai_convert_count
= cmd->chanlist_len;
s626_dio_set_irq(dev,
cmd->convert_arg);
}
if (cmd->convert_src ==
TRIG_TIMER) {
k = &encpriv[5];
devpriv->ai_convert_count
= cmd->chanlist_len;
k->SetEnable(dev, k,
CLKENAB_ALWAYS);
}
}
if ((irqbit >> (cmd->convert_arg -
(16 * group)))
== 1
&& cmd->convert_src == TRIG_EXT) {
MC_ENABLE(P_MC2, MC2_ADC_RPS);
devpriv->ai_convert_count--;
if (devpriv->ai_convert_count >
0) {
s626_dio_set_irq(dev,
cmd->convert_arg);
}
}
}
break;
}
}
irqbit = DEBIread(dev, LP_RDMISC2);
if (irqbit & IRQ_COINT1A) {
k = &encpriv[0];
k->ResetCapFlags(dev, k);
}
if (irqbit & IRQ_COINT2A) {
k = &encpriv[1];
k->ResetCapFlags(dev, k);
}
if (irqbit & IRQ_COINT3A) {
k = &encpriv[2];
k->ResetCapFlags(dev, k);
}
if (irqbit & IRQ_COINT1B) {
k = &encpriv[3];
k->ResetCapFlags(dev, k);
}
if (irqbit & IRQ_COINT2B) {
k = &encpriv[4];
k->ResetCapFlags(dev, k);
if (devpriv->ai_convert_count > 0) {
devpriv->ai_convert_count--;
if (devpriv->ai_convert_count == 0)
k->SetEnable(dev, k, CLKENAB_INDEX);
if (cmd->convert_src == TRIG_TIMER) {
MC_ENABLE(P_MC2, MC2_ADC_RPS);
}
}
}
if (irqbit & IRQ_COINT3B) {
k = &encpriv[5];
k->ResetCapFlags(dev, k);
if (cmd->scan_begin_src == TRIG_TIMER) {
MC_ENABLE(P_MC2, MC2_ADC_RPS);
}
if (cmd->convert_src == TRIG_TIMER) {
k = &encpriv[4];
devpriv->ai_convert_count = cmd->chanlist_len;
k->SetEnable(dev, k, CLKENAB_ALWAYS);
}
}
}
writel(irqstatus, devpriv->base_addr + P_IER);
spin_unlock_irqrestore(&dev->spinlock, flags);
return IRQ_HANDLED;
}
static void ResetADC(struct comedi_device *dev, uint8_t *ppl)
{
register uint32_t *pRPS;
uint32_t JmpAdrs;
uint16_t i;
uint16_t n;
uint32_t LocalPPL;
struct comedi_cmd *cmd = &(dev->subdevices->async->cmd);
MC_DISABLE(P_MC1, MC1_ERPS1);
pRPS = (uint32_t *) devpriv->RPSBuf.LogicalBase;
WR7146(P_RPSADDR1, (uint32_t) devpriv->RPSBuf.PhysicalBase);
if (cmd != NULL && cmd->scan_begin_src != TRIG_FOLLOW) {
*pRPS++ = RPS_PAUSE | RPS_SIGADC;
*pRPS++ = RPS_CLRSIGNAL | RPS_SIGADC;
}
*pRPS++ = RPS_LDREG | (P_DEBICMD >> 2);
*pRPS++ = DEBI_CMD_WRWORD | LP_GSEL;
*pRPS++ = RPS_LDREG | (P_DEBIAD >> 2);
*pRPS++ = GSEL_BIPOLAR5V;
*pRPS++ = RPS_CLRSIGNAL | RPS_DEBI;
*pRPS++ = RPS_UPLOAD | RPS_DEBI;
*pRPS++ = RPS_PAUSE | RPS_DEBI;
for (devpriv->AdcItems = 0; devpriv->AdcItems < 16; devpriv->AdcItems++) {
LocalPPL =
(*ppl << 8) | (*ppl & 0x10 ? GSEL_BIPOLAR5V :
GSEL_BIPOLAR10V);
*pRPS++ = RPS_LDREG | (P_DEBICMD >> 2);
*pRPS++ = DEBI_CMD_WRWORD | LP_GSEL;
*pRPS++ = RPS_LDREG | (P_DEBIAD >> 2);
*pRPS++ = LocalPPL;
*pRPS++ = RPS_CLRSIGNAL | RPS_DEBI;
*pRPS++ = RPS_UPLOAD | RPS_DEBI;
*pRPS++ = RPS_PAUSE | RPS_DEBI;
*pRPS++ = RPS_LDREG | (P_DEBICMD >> 2);
*pRPS++ = DEBI_CMD_WRWORD | LP_ISEL;
*pRPS++ = RPS_LDREG | (P_DEBIAD >> 2);
*pRPS++ = LocalPPL;
*pRPS++ = RPS_CLRSIGNAL | RPS_DEBI;
*pRPS++ = RPS_UPLOAD | RPS_DEBI;
*pRPS++ = RPS_PAUSE | RPS_DEBI;
JmpAdrs =
(uint32_t) devpriv->RPSBuf.PhysicalBase +
(uint32_t) ((unsigned long)pRPS -
(unsigned long)devpriv->RPSBuf.LogicalBase);
for (i = 0; i < (10 * RPSCLK_PER_US / 2); i++) {
JmpAdrs += 8;
*pRPS++ = RPS_JUMP;
*pRPS++ = JmpAdrs;
}
if (cmd != NULL && cmd->convert_src != TRIG_NOW) {
*pRPS++ = RPS_PAUSE | RPS_SIGADC;
*pRPS++ = RPS_CLRSIGNAL | RPS_SIGADC;
}
*pRPS++ = RPS_LDREG | (P_GPIO >> 2);
*pRPS++ = GPIO_BASE | GPIO1_LO;
*pRPS++ = RPS_NOP;
*pRPS++ = RPS_LDREG | (P_GPIO >> 2);
*pRPS++ = GPIO_BASE | GPIO1_HI;
*pRPS++ = RPS_PAUSE | RPS_GPIO2;
*pRPS++ = RPS_STREG | (BUGFIX_STREG(P_FB_BUFFER1) >> 2);
*pRPS++ =
(uint32_t) devpriv->ANABuf.PhysicalBase +
(devpriv->AdcItems << 2);
if (*ppl++ & EOPL) {
devpriv->AdcItems++;
break;
}
}
for (n = 0; n < (2 * RPSCLK_PER_US); n++)
*pRPS++ = RPS_NOP;
*pRPS++ = RPS_LDREG | (P_GPIO >> 2);
*pRPS++ = GPIO_BASE | GPIO1_LO;
*pRPS++ = RPS_NOP;
*pRPS++ = RPS_LDREG | (P_GPIO >> 2);
*pRPS++ = GPIO_BASE | GPIO1_HI;
*pRPS++ = RPS_PAUSE | RPS_GPIO2;
*pRPS++ = RPS_STREG | (BUGFIX_STREG(P_FB_BUFFER1) >> 2);
*pRPS++ =
(uint32_t) devpriv->ANABuf.PhysicalBase + (devpriv->AdcItems << 2);
if (devpriv->ai_cmd_running == 1) {
*pRPS++ = RPS_IRQ;
}
*pRPS++ = RPS_JUMP;
*pRPS++ = (uint32_t) devpriv->RPSBuf.PhysicalBase;
}
static int s626_ai_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
return -EINVAL;
}
static int s626_ai_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
uint16_t chan = CR_CHAN(insn->chanspec);
uint16_t range = CR_RANGE(insn->chanspec);
uint16_t AdcSpec = 0;
uint32_t GpioImage;
int n;
if (range == 0)
AdcSpec = (chan << 8) | (GSEL_BIPOLAR5V);
else
AdcSpec = (chan << 8) | (GSEL_BIPOLAR10V);
DEBIwrite(dev, LP_GSEL, AdcSpec);
DEBIwrite(dev, LP_ISEL, AdcSpec);
for (n = 0; n < insn->n; n++) {
udelay(10);
GpioImage = RR7146(P_GPIO);
WR7146(P_GPIO, GpioImage & ~GPIO1_HI);
WR7146(P_GPIO, GpioImage & ~GPIO1_HI);
WR7146(P_GPIO, GpioImage & ~GPIO1_HI);
WR7146(P_GPIO, GpioImage | GPIO1_HI);
while (!(RR7146(P_PSR) & PSR_GPIO2))
;
if (n != 0)
data[n - 1] = s626_ai_reg_to_uint(RR7146(P_FB_BUFFER1));
udelay(4);
}
GpioImage = RR7146(P_GPIO);
WR7146(P_GPIO, GpioImage & ~GPIO1_HI);
WR7146(P_GPIO, GpioImage & ~GPIO1_HI);
WR7146(P_GPIO, GpioImage & ~GPIO1_HI);
WR7146(P_GPIO, GpioImage | GPIO1_HI);
while (!(RR7146(P_PSR) & PSR_GPIO2))
;
if (n != 0)
data[n - 1] = s626_ai_reg_to_uint(RR7146(P_FB_BUFFER1));
return n;
}
static int s626_ai_load_polllist(uint8_t *ppl, struct comedi_cmd *cmd)
{
int n;
for (n = 0; n < cmd->chanlist_len; n++) {
if (CR_RANGE((cmd->chanlist)[n]) == 0)
ppl[n] = (CR_CHAN((cmd->chanlist)[n])) | (RANGE_5V);
else
ppl[n] = (CR_CHAN((cmd->chanlist)[n])) | (RANGE_10V);
}
if (n != 0)
ppl[n - 1] |= EOPL;
return n;
}
static int s626_ai_inttrig(struct comedi_device *dev,
struct comedi_subdevice *s, unsigned int trignum)
{
if (trignum != 0)
return -EINVAL;
MC_ENABLE(P_MC1, MC1_ERPS1);
s->async->inttrig = NULL;
return 1;
}
static int s626_ns_to_timer(int *nanosec, int round_mode)
{
int divider, base;
base = 500;
switch (round_mode) {
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
static void s626_timer_load(struct comedi_device *dev, struct enc_private *k,
int tick)
{
uint16_t Setup = (LOADSRC_INDX << BF_LOADSRC) |
(INDXSRC_SOFT << BF_INDXSRC) |
(CLKSRC_TIMER << BF_CLKSRC) |
(CLKPOL_POS << BF_CLKPOL) |
(CNTDIR_DOWN << BF_CLKPOL) |
(CLKMULT_1X << BF_CLKMULT) |
(CLKENAB_INDEX << BF_CLKENAB);
uint16_t valueSrclatch = LATCHSRC_A_INDXA;
k->SetMode(dev, k, Setup, FALSE);
Preload(dev, k, tick);
k->SetLoadTrig(dev, k, 0);
k->PulseIndex(dev, k);
k->SetLoadTrig(dev, k, 1);
k->SetIntSrc(dev, k, INTSRC_OVER);
SetLatchSource(dev, k, valueSrclatch);
}
static int s626_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
uint8_t ppl[16];
struct comedi_cmd *cmd = &s->async->cmd;
struct enc_private *k;
int tick;
if (devpriv->ai_cmd_running) {
printk(KERN_ERR "s626_ai_cmd: Another ai_cmd is running %d\n",
dev->minor);
return -EBUSY;
}
writel(0, devpriv->base_addr + P_IER);
writel(IRQ_RPS1 | IRQ_GPIO3, devpriv->base_addr + P_ISR);
s626_dio_clear_irq(dev);
devpriv->ai_cmd_running = 0;
if (cmd == NULL)
return -EINVAL;
if (dev->irq == 0) {
comedi_error(dev,
"s626_ai_cmd: cannot run command without an irq");
return -EIO;
}
s626_ai_load_polllist(ppl, cmd);
devpriv->ai_cmd_running = 1;
devpriv->ai_convert_count = 0;
switch (cmd->scan_begin_src) {
case TRIG_FOLLOW:
break;
case TRIG_TIMER:
k = &encpriv[5];
tick = s626_ns_to_timer((int *)&cmd->scan_begin_arg,
cmd->flags & TRIG_ROUND_MASK);
s626_timer_load(dev, k, tick);
k->SetEnable(dev, k, CLKENAB_ALWAYS);
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
k = &encpriv[4];
tick = s626_ns_to_timer((int *)&cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
s626_timer_load(dev, k, tick);
k->SetEnable(dev, k, CLKENAB_INDEX);
break;
case TRIG_EXT:
if (cmd->scan_begin_src != TRIG_EXT
&& cmd->start_src == TRIG_EXT)
s626_dio_set_irq(dev, cmd->convert_arg);
break;
}
switch (cmd->stop_src) {
case TRIG_COUNT:
devpriv->ai_sample_count = cmd->stop_arg;
devpriv->ai_continous = 0;
break;
case TRIG_NONE:
devpriv->ai_continous = 1;
devpriv->ai_sample_count = 0;
break;
}
ResetADC(dev, ppl);
switch (cmd->start_src) {
case TRIG_NOW:
MC_ENABLE(P_MC1, MC1_ERPS1);
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
writel(IRQ_GPIO3 | IRQ_RPS1, devpriv->base_addr + P_IER);
return 0;
}
static int s626_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
int err = 0;
int tmp;
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
if (cmd->start_src != TRIG_EXT && cmd->start_arg != 0) {
cmd->start_arg = 0;
err++;
}
if (cmd->start_src == TRIG_EXT && cmd->start_arg > 39) {
cmd->start_arg = 39;
err++;
}
if (cmd->scan_begin_src == TRIG_EXT && cmd->scan_begin_arg > 39) {
cmd->scan_begin_arg = 39;
err++;
}
if (cmd->convert_src == TRIG_EXT && cmd->convert_arg > 39) {
cmd->convert_arg = 39;
err++;
}
#define MAX_SPEED 200000
#define MIN_SPEED 2000000000
if (cmd->scan_begin_src == TRIG_TIMER) {
if (cmd->scan_begin_arg < MAX_SPEED) {
cmd->scan_begin_arg = MAX_SPEED;
err++;
}
if (cmd->scan_begin_arg > MIN_SPEED) {
cmd->scan_begin_arg = MIN_SPEED;
err++;
}
} else {
}
if (cmd->convert_src == TRIG_TIMER) {
if (cmd->convert_arg < MAX_SPEED) {
cmd->convert_arg = MAX_SPEED;
err++;
}
if (cmd->convert_arg > MIN_SPEED) {
cmd->convert_arg = MIN_SPEED;
err++;
}
} else {
}
if (cmd->scan_end_arg != cmd->chanlist_len) {
cmd->scan_end_arg = cmd->chanlist_len;
err++;
}
if (cmd->stop_src == TRIG_COUNT) {
if (cmd->stop_arg > 0x00ffffff) {
cmd->stop_arg = 0x00ffffff;
err++;
}
} else {
if (cmd->stop_arg != 0) {
cmd->stop_arg = 0;
err++;
}
}
if (err)
return 3;
if (cmd->scan_begin_src == TRIG_TIMER) {
tmp = cmd->scan_begin_arg;
s626_ns_to_timer((int *)&cmd->scan_begin_arg,
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->scan_begin_arg)
err++;
}
if (cmd->convert_src == TRIG_TIMER) {
tmp = cmd->convert_arg;
s626_ns_to_timer((int *)&cmd->convert_arg,
cmd->flags & TRIG_ROUND_MASK);
if (tmp != cmd->convert_arg)
err++;
if (cmd->scan_begin_src == TRIG_TIMER &&
cmd->scan_begin_arg <
cmd->convert_arg * cmd->scan_end_arg) {
cmd->scan_begin_arg =
cmd->convert_arg * cmd->scan_end_arg;
err++;
}
}
if (err)
return 4;
return 0;
}
static int s626_ai_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
MC_DISABLE(P_MC1, MC1_ERPS1);
writel(0, devpriv->base_addr + P_IER);
devpriv->ai_cmd_running = 0;
return 0;
}
static int s626_ao_winsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
uint16_t chan = CR_CHAN(insn->chanspec);
int16_t dacdata;
for (i = 0; i < insn->n; i++) {
dacdata = (int16_t) data[i];
devpriv->ao_readback[CR_CHAN(insn->chanspec)] = data[i];
dacdata -= (0x1fff);
SetDAC(dev, chan, dacdata);
}
return i;
}
static int s626_ao_rinsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i;
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ao_readback[CR_CHAN(insn->chanspec)];
return i;
}
static void s626_dio_init(struct comedi_device *dev)
{
uint16_t group;
struct comedi_subdevice *s;
DEBIwrite(dev, LP_MISC1, MISC1_NOEDCAP);
for (group = 0; group < S626_DIO_BANKS; group++) {
s = dev->subdevices + 2 + group;
DEBIwrite(dev, diopriv->WRIntSel, 0);
DEBIwrite(dev, diopriv->WRCapSel, 0xFFFF);
DEBIwrite(dev, diopriv->WREdgSel, 0);
DEBIwrite(dev, diopriv->WRDOut, 0);
}
}
static int s626_dio_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (data[0]) {
if ((s->io_bits & data[0]) != data[0])
return -EIO;
s->state &= ~data[0];
s->state |= data[0] & data[1];
DEBIwrite(dev, diopriv->WRDOut, s->state);
}
data[1] = DEBIread(dev, diopriv->RDDIn);
return insn->n;
}
static int s626_dio_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
switch (data[0]) {
case INSN_CONFIG_DIO_QUERY:
data[1] =
(s->
io_bits & (1 << CR_CHAN(insn->chanspec))) ? COMEDI_OUTPUT :
COMEDI_INPUT;
return insn->n;
break;
case COMEDI_INPUT:
s->io_bits &= ~(1 << CR_CHAN(insn->chanspec));
break;
case COMEDI_OUTPUT:
s->io_bits |= 1 << CR_CHAN(insn->chanspec);
break;
default:
return -EINVAL;
break;
}
DEBIwrite(dev, diopriv->WRDOut, s->io_bits);
return 1;
}
static int s626_enc_insn_config(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
uint16_t Setup = (LOADSRC_INDX << BF_LOADSRC) |
(INDXSRC_SOFT << BF_INDXSRC) |
(CLKSRC_COUNTER << BF_CLKSRC) |
(CLKPOL_POS << BF_CLKPOL) |
(CLKMULT_1X << BF_CLKMULT) |
(CLKENAB_INDEX << BF_CLKENAB);
uint16_t valueSrclatch = LATCHSRC_AB_READ;
uint16_t enab = CLKENAB_ALWAYS;
struct enc_private *k = &encpriv[CR_CHAN(insn->chanspec)];
k->SetMode(dev, k, Setup, TRUE);
Preload(dev, k, data[0]);
k->PulseIndex(dev, k);
SetLatchSource(dev, k, valueSrclatch);
k->SetEnable(dev, k, (uint16_t) (enab != 0));
return insn->n;
}
static int s626_enc_insn_read(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int n;
struct enc_private *k = &encpriv[CR_CHAN(insn->chanspec)];
for (n = 0; n < insn->n; n++)
data[n] = ReadLatch(dev, k);
return n;
}
static int s626_enc_insn_write(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
struct enc_private *k = &encpriv[CR_CHAN(insn->chanspec)];
Preload(dev, k, data[0]);
k->SetLoadTrig(dev, k, 0);
k->PulseIndex(dev, k);
k->SetLoadTrig(dev, k, 2);
return 1;
}
static void WriteMISC2(struct comedi_device *dev, uint16_t NewImage)
{
DEBIwrite(dev, LP_MISC1, MISC1_WENABLE);
DEBIwrite(dev, LP_WRMISC2, NewImage);
DEBIwrite(dev, LP_MISC1, MISC1_WDISABLE);
}
static void CloseDMAB(struct comedi_device *dev, struct bufferDMA *pdma,
size_t bsize)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
void *vbptr;
dma_addr_t vpptr;
if (pdma == NULL)
return;
vbptr = pdma->LogicalBase;
vpptr = pdma->PhysicalBase;
if (vbptr) {
pci_free_consistent(pcidev, bsize, vbptr, vpptr);
pdma->LogicalBase = NULL;
pdma->PhysicalBase = 0;
}
}
static void ResetCapFlags_A(struct comedi_device *dev, struct enc_private *k)
{
DEBIreplace(dev, k->MyCRB, (uint16_t) (~CRBMSK_INTCTRL),
CRBMSK_INTRESETCMD | CRBMSK_INTRESET_A);
}
static void ResetCapFlags_B(struct comedi_device *dev, struct enc_private *k)
{
DEBIreplace(dev, k->MyCRB, (uint16_t) (~CRBMSK_INTCTRL),
CRBMSK_INTRESETCMD | CRBMSK_INTRESET_B);
}
static uint16_t GetMode_A(struct comedi_device *dev, struct enc_private *k)
{
register uint16_t cra;
register uint16_t crb;
register uint16_t setup;
cra = DEBIread(dev, k->MyCRA);
crb = DEBIread(dev, k->MyCRB);
setup = ((cra & STDMSK_LOADSRC)
|((crb << (STDBIT_LATCHSRC - CRBBIT_LATCHSRC)) & STDMSK_LATCHSRC)
|((cra << (STDBIT_INTSRC - CRABIT_INTSRC_A)) & STDMSK_INTSRC)
|((cra << (STDBIT_INDXSRC - (CRABIT_INDXSRC_A + 1))) & STDMSK_INDXSRC)
|((cra >> (CRABIT_INDXPOL_A - STDBIT_INDXPOL)) & STDMSK_INDXPOL)
|((crb >> (CRBBIT_CLKENAB_A - STDBIT_CLKENAB)) & STDMSK_CLKENAB));
if (cra & (2 << CRABIT_CLKSRC_A))
setup |= ((CLKSRC_TIMER << STDBIT_CLKSRC)
|((cra << (STDBIT_CLKPOL - CRABIT_CLKSRC_A)) & STDMSK_CLKPOL)
|(MULT_X1 << STDBIT_CLKMULT));
else
setup |= ((CLKSRC_COUNTER << STDBIT_CLKSRC)
|((cra >> (CRABIT_CLKPOL_A - STDBIT_CLKPOL)) & STDMSK_CLKPOL)
|(((cra & CRAMSK_CLKMULT_A) == (MULT_X0 << CRABIT_CLKMULT_A)) ?
(MULT_X1 << STDBIT_CLKMULT) :
((cra >> (CRABIT_CLKMULT_A -
STDBIT_CLKMULT)) & STDMSK_CLKMULT)));
return setup;
}
static uint16_t GetMode_B(struct comedi_device *dev, struct enc_private *k)
{
register uint16_t cra;
register uint16_t crb;
register uint16_t setup;
cra = DEBIread(dev, k->MyCRA);
crb = DEBIread(dev, k->MyCRB);
setup = (((crb << (STDBIT_INTSRC - CRBBIT_INTSRC_B)) & STDMSK_INTSRC)
|((crb << (STDBIT_LATCHSRC - CRBBIT_LATCHSRC)) & STDMSK_LATCHSRC)
|((crb << (STDBIT_LOADSRC - CRBBIT_LOADSRC_B)) & STDMSK_LOADSRC)
|((crb << (STDBIT_INDXPOL - CRBBIT_INDXPOL_B)) & STDMSK_INDXPOL)
|((crb >> (CRBBIT_CLKENAB_B - STDBIT_CLKENAB)) & STDMSK_CLKENAB)
|((cra >> ((CRABIT_INDXSRC_B + 1) - STDBIT_INDXSRC)) & STDMSK_INDXSRC));
if ((crb & CRBMSK_CLKMULT_B) == (MULT_X0 << CRBBIT_CLKMULT_B))
setup |= ((CLKSRC_EXTENDER << STDBIT_CLKSRC)
|(MULT_X1 << STDBIT_CLKMULT)
|((cra >> (CRABIT_CLKSRC_B - STDBIT_CLKPOL)) & STDMSK_CLKPOL));
else if (cra & (2 << CRABIT_CLKSRC_B))
setup |= ((CLKSRC_TIMER << STDBIT_CLKSRC)
|(MULT_X1 << STDBIT_CLKMULT)
|((cra >> (CRABIT_CLKSRC_B - STDBIT_CLKPOL)) & STDMSK_CLKPOL));
else
setup |= ((CLKSRC_COUNTER << STDBIT_CLKSRC)
|((crb >> (CRBBIT_CLKMULT_B - STDBIT_CLKMULT)) & STDMSK_CLKMULT)
|((crb << (STDBIT_CLKPOL - CRBBIT_CLKPOL_B)) & STDMSK_CLKPOL));
return setup;
}
static void SetMode_A(struct comedi_device *dev, struct enc_private *k,
uint16_t Setup, uint16_t DisableIntSrc)
{
register uint16_t cra;
register uint16_t crb;
register uint16_t setup = Setup;
cra = ((setup & CRAMSK_LOADSRC_A)
|((setup & STDMSK_INDXSRC) >> (STDBIT_INDXSRC - (CRABIT_INDXSRC_A + 1))));
crb = (CRBMSK_INTRESETCMD | CRBMSK_INTRESET_A
| ((setup & STDMSK_CLKENAB) << (CRBBIT_CLKENAB_A - STDBIT_CLKENAB)));
if (!DisableIntSrc)
cra |= ((setup & STDMSK_INTSRC) >> (STDBIT_INTSRC -
CRABIT_INTSRC_A));
switch ((setup & STDMSK_CLKSRC) >> STDBIT_CLKSRC) {
case CLKSRC_EXTENDER:
case CLKSRC_TIMER:
cra |= ((2 << CRABIT_CLKSRC_A)
|((setup & STDMSK_CLKPOL) >> (STDBIT_CLKPOL - CRABIT_CLKSRC_A))
|(1 << CRABIT_CLKPOL_A)
|(MULT_X1 << CRABIT_CLKMULT_A));
break;
default:
cra |= (CLKSRC_COUNTER
| ((setup & STDMSK_CLKPOL) << (CRABIT_CLKPOL_A - STDBIT_CLKPOL))
|(((setup & STDMSK_CLKMULT) == (MULT_X0 << STDBIT_CLKMULT)) ?
(MULT_X1 << CRABIT_CLKMULT_A) :
((setup & STDMSK_CLKMULT) << (CRABIT_CLKMULT_A -
STDBIT_CLKMULT))));
}
if (~setup & STDMSK_INDXSRC)
cra |= ((setup & STDMSK_INDXPOL) << (CRABIT_INDXPOL_A -
STDBIT_INDXPOL));
if (DisableIntSrc)
devpriv->CounterIntEnabs &= ~k->MyEventBits[3];
DEBIreplace(dev, k->MyCRA, CRAMSK_INDXSRC_B | CRAMSK_CLKSRC_B, cra);
DEBIreplace(dev, k->MyCRB,
(uint16_t) (~(CRBMSK_INTCTRL | CRBMSK_CLKENAB_A)), crb);
}
static void SetMode_B(struct comedi_device *dev, struct enc_private *k,
uint16_t Setup, uint16_t DisableIntSrc)
{
register uint16_t cra;
register uint16_t crb;
register uint16_t setup = Setup;
cra = ((setup & STDMSK_INDXSRC) << ((CRABIT_INDXSRC_B + 1) - STDBIT_INDXSRC));
crb = (CRBMSK_INTRESETCMD | CRBMSK_INTRESET_B
| ((setup & STDMSK_CLKENAB) << (CRBBIT_CLKENAB_B - STDBIT_CLKENAB))
|((setup & STDMSK_LOADSRC) >> (STDBIT_LOADSRC - CRBBIT_LOADSRC_B)));
if (!DisableIntSrc)
crb |= ((setup & STDMSK_INTSRC) >> (STDBIT_INTSRC -
CRBBIT_INTSRC_B));
switch ((setup & STDMSK_CLKSRC) >> STDBIT_CLKSRC) {
case CLKSRC_TIMER:
cra |= ((2 << CRABIT_CLKSRC_B)
|((setup & STDMSK_CLKPOL) << (CRABIT_CLKSRC_B - STDBIT_CLKPOL)));
crb |= ((1 << CRBBIT_CLKPOL_B)
|(MULT_X1 << CRBBIT_CLKMULT_B));
break;
case CLKSRC_EXTENDER:
cra |= ((2 << CRABIT_CLKSRC_B)
|((setup & STDMSK_CLKPOL) << (CRABIT_CLKSRC_B - STDBIT_CLKPOL)));
crb |= ((1 << CRBBIT_CLKPOL_B)
|(MULT_X0 << CRBBIT_CLKMULT_B));
break;
default:
cra |= (CLKSRC_COUNTER << CRABIT_CLKSRC_B);
crb |= (((setup & STDMSK_CLKPOL) >> (STDBIT_CLKPOL - CRBBIT_CLKPOL_B))
|(((setup & STDMSK_CLKMULT) == (MULT_X0 << STDBIT_CLKMULT)) ?
(MULT_X1 << CRBBIT_CLKMULT_B) :
((setup & STDMSK_CLKMULT) << (CRBBIT_CLKMULT_B -
STDBIT_CLKMULT))));
}
if (~setup & STDMSK_INDXSRC)
crb |= ((setup & STDMSK_INDXPOL) >> (STDBIT_INDXPOL -
CRBBIT_INDXPOL_B));
if (DisableIntSrc)
devpriv->CounterIntEnabs &= ~k->MyEventBits[3];
DEBIreplace(dev, k->MyCRA,
(uint16_t) (~(CRAMSK_INDXSRC_B | CRAMSK_CLKSRC_B)), cra);
DEBIreplace(dev, k->MyCRB, CRBMSK_CLKENAB_A | CRBMSK_LATCHSRC, crb);
}
static void SetEnable_A(struct comedi_device *dev, struct enc_private *k,
uint16_t enab)
{
DEBIreplace(dev, k->MyCRB,
(uint16_t) (~(CRBMSK_INTCTRL | CRBMSK_CLKENAB_A)),
(uint16_t) (enab << CRBBIT_CLKENAB_A));
}
static void SetEnable_B(struct comedi_device *dev, struct enc_private *k,
uint16_t enab)
{
DEBIreplace(dev, k->MyCRB,
(uint16_t) (~(CRBMSK_INTCTRL | CRBMSK_CLKENAB_B)),
(uint16_t) (enab << CRBBIT_CLKENAB_B));
}
static uint16_t GetEnable_A(struct comedi_device *dev, struct enc_private *k)
{
return (DEBIread(dev, k->MyCRB) >> CRBBIT_CLKENAB_A) & 1;
}
static uint16_t GetEnable_B(struct comedi_device *dev, struct enc_private *k)
{
return (DEBIread(dev, k->MyCRB) >> CRBBIT_CLKENAB_B) & 1;
}
static void SetLoadTrig_A(struct comedi_device *dev, struct enc_private *k,
uint16_t Trig)
{
DEBIreplace(dev, k->MyCRA, (uint16_t) (~CRAMSK_LOADSRC_A),
(uint16_t) (Trig << CRABIT_LOADSRC_A));
}
static void SetLoadTrig_B(struct comedi_device *dev, struct enc_private *k,
uint16_t Trig)
{
DEBIreplace(dev, k->MyCRB,
(uint16_t) (~(CRBMSK_LOADSRC_B | CRBMSK_INTCTRL)),
(uint16_t) (Trig << CRBBIT_LOADSRC_B));
}
static uint16_t GetLoadTrig_A(struct comedi_device *dev, struct enc_private *k)
{
return (DEBIread(dev, k->MyCRA) >> CRABIT_LOADSRC_A) & 3;
}
static uint16_t GetLoadTrig_B(struct comedi_device *dev, struct enc_private *k)
{
return (DEBIread(dev, k->MyCRB) >> CRBBIT_LOADSRC_B) & 3;
}
static void SetIntSrc_A(struct comedi_device *dev, struct enc_private *k,
uint16_t IntSource)
{
DEBIreplace(dev, k->MyCRB, (uint16_t) (~CRBMSK_INTCTRL),
CRBMSK_INTRESETCMD | CRBMSK_INTRESET_A);
DEBIreplace(dev, k->MyCRA, ~CRAMSK_INTSRC_A,
(uint16_t) (IntSource << CRABIT_INTSRC_A));
devpriv->CounterIntEnabs =
(devpriv->CounterIntEnabs & ~k->
MyEventBits[3]) | k->MyEventBits[IntSource];
}
static void SetIntSrc_B(struct comedi_device *dev, struct enc_private *k,
uint16_t IntSource)
{
uint16_t crb;
crb = DEBIread(dev, k->MyCRB) & ~CRBMSK_INTCTRL;
DEBIwrite(dev, k->MyCRB,
(uint16_t) (crb | CRBMSK_INTRESETCMD | CRBMSK_INTRESET_B));
DEBIwrite(dev, k->MyCRB,
(uint16_t) ((crb & ~CRBMSK_INTSRC_B) | (IntSource <<
CRBBIT_INTSRC_B)));
devpriv->CounterIntEnabs =
(devpriv->CounterIntEnabs & ~k->
MyEventBits[3]) | k->MyEventBits[IntSource];
}
static uint16_t GetIntSrc_A(struct comedi_device *dev, struct enc_private *k)
{
return (DEBIread(dev, k->MyCRA) >> CRABIT_INTSRC_A) & 3;
}
static uint16_t GetIntSrc_B(struct comedi_device *dev, struct enc_private *k)
{
return (DEBIread(dev, k->MyCRB) >> CRBBIT_INTSRC_B) & 3;
}
static void PulseIndex_A(struct comedi_device *dev, struct enc_private *k)
{
register uint16_t cra;
cra = DEBIread(dev, k->MyCRA);
DEBIwrite(dev, k->MyCRA, (uint16_t) (cra ^ CRAMSK_INDXPOL_A));
DEBIwrite(dev, k->MyCRA, cra);
}
static void PulseIndex_B(struct comedi_device *dev, struct enc_private *k)
{
register uint16_t crb;
crb = DEBIread(dev, k->MyCRB) & ~CRBMSK_INTCTRL;
DEBIwrite(dev, k->MyCRB, (uint16_t) (crb ^ CRBMSK_INDXPOL_B));
DEBIwrite(dev, k->MyCRB, crb);
}
static void CountersInit(struct comedi_device *dev)
{
int chan;
struct enc_private *k;
uint16_t Setup = (LOADSRC_INDX << BF_LOADSRC) |
(INDXSRC_SOFT << BF_INDXSRC) |
(CLKSRC_COUNTER << BF_CLKSRC) |
(CLKPOL_POS << BF_CLKPOL) |
(CNTDIR_UP << BF_CLKPOL) |
(CLKMULT_1X << BF_CLKMULT) |
(CLKENAB_INDEX << BF_CLKENAB);
for (chan = 0; chan < S626_ENCODER_CHANNELS; chan++) {
k = &encpriv[chan];
k->SetMode(dev, k, Setup, TRUE);
k->SetIntSrc(dev, k, 0);
k->ResetCapFlags(dev, k);
k->SetEnable(dev, k, CLKENAB_ALWAYS);
}
}
static int s626_allocate_dma_buffers(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
void *addr;
dma_addr_t appdma;
addr = pci_alloc_consistent(pcidev, DMABUF_SIZE, &appdma);
if (!addr)
return -ENOMEM;
devpriv->ANABuf.LogicalBase = addr;
devpriv->ANABuf.PhysicalBase = appdma;
addr = pci_alloc_consistent(pcidev, DMABUF_SIZE, &appdma);
if (!addr)
return -ENOMEM;
devpriv->RPSBuf.LogicalBase = addr;
devpriv->RPSBuf.PhysicalBase = appdma;
return 0;
}
static void s626_initialize(struct comedi_device *dev)
{
dma_addr_t pPhysBuf;
uint16_t chan;
int i;
MC_ENABLE(P_MC1, MC1_DEBI | MC1_AUDIO | MC1_I2C);
WR7146(P_DEBICFG, DEBI_CFG_SLAVE16 |
(DEBI_TOUT << DEBI_CFG_TOUT_BIT) |
DEBI_SWAP | DEBI_CFG_INTEL);
WR7146(P_DEBIPAGE, DEBI_PAGE_DISABLE);
WR7146(P_GPIO, GPIO_BASE | GPIO1_HI);
devpriv->I2CAdrs = 0xA0;
WR7146(P_I2CSTAT, I2C_CLKSEL | I2C_ABORT);
MC_ENABLE(P_MC2, MC2_UPLD_IIC);
while ((RR7146(P_MC2) & MC2_UPLD_IIC) == 0)
;
for (i = 0; i < 2; i++) {
WR7146(P_I2CSTAT, I2C_CLKSEL);
MC_ENABLE(P_MC2, MC2_UPLD_IIC);
while (!MC_TEST(P_MC2, MC2_UPLD_IIC))
;
}
WR7146(P_ACON2, ACON2_INIT);
WR7146(P_TSL1, RSD1 | SIB_A1);
WR7146(P_TSL1 + 4, RSD1 | SIB_A1 | EOS);
WR7146(P_ACON1, ACON1_ADCSTART);
WR7146(P_RPSADDR1, (uint32_t)devpriv->RPSBuf.PhysicalBase);
WR7146(P_RPSPAGE1, 0);
WR7146(P_RPS1_TOUT, 0);
#if 0
{
uint8_t PollList;
uint16_t AdcData;
uint16_t StartVal;
uint16_t index;
unsigned int data[16];
PollList = EOPL;
ResetADC(dev, &PollList);
s626_ai_rinsn(dev, dev->subdevices, NULL, data);
StartVal = data[0];
for (index = 0; index < 500; index++) {
s626_ai_rinsn(dev, dev->subdevices, NULL, data);
AdcData = data[0];
if (AdcData != StartVal)
break;
}
}
#endif
WR7146(P_PCI_BT_A, 0);
pPhysBuf = devpriv->ANABuf.PhysicalBase +
(DAC_WDMABUF_OS * sizeof(uint32_t));
WR7146(P_BASEA2_OUT, (uint32_t) pPhysBuf);
WR7146(P_PROTA2_OUT, (uint32_t) (pPhysBuf + sizeof(uint32_t)));
devpriv->pDacWBuf = (uint32_t *)devpriv->ANABuf.LogicalBase +
DAC_WDMABUF_OS;
WR7146(P_PAGEA2_OUT, 8);
SETVECT(0, XSD2 | RSD3 | SIB_A2 | EOS);
SETVECT(1, LF_A2);
WR7146(P_ACON1, ACON1_DACSTART);
LoadTrimDACs(dev);
LoadTrimDACs(dev);
for (chan = 0; chan < S626_DAC_CHANNELS; chan++)
SetDAC(dev, chan, 0);
CountersInit(dev);
WriteMISC2(dev, (uint16_t)(DEBIread(dev, LP_RDMISC2) &
MISC2_BATT_ENABLE));
s626_dio_init(dev);
}
static int s626_attach_pci(struct comedi_device *dev, struct pci_dev *pcidev)
{
struct comedi_subdevice *s;
int ret;
comedi_set_hw_dev(dev, &pcidev->dev);
dev->board_name = dev->driver->driver_name;
if (alloc_private(dev, sizeof(struct s626_private)) < 0)
return -ENOMEM;
ret = comedi_pci_enable(pcidev, dev->board_name);
if (ret)
return ret;
dev->iobase = 1;
devpriv->base_addr = ioremap(pci_resource_start(pcidev, 0),
pci_resource_len(pcidev, 0));
if (!devpriv->base_addr)
return -ENOMEM;
writel(0, devpriv->base_addr + P_IER);
writel(MC1_SOFT_RESET, devpriv->base_addr + P_MC1);
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
s = dev->subdevices + 0;
dev->read_subdev = s;
s->type = COMEDI_SUBD_AI;
s->subdev_flags = SDF_READABLE | SDF_DIFF | SDF_CMD_READ;
s->n_chan = S626_ADC_CHANNELS;
s->maxdata = (0xffff >> 2);
s->range_table = &s626_range_table;
s->len_chanlist = S626_ADC_CHANNELS;
s->insn_config = s626_ai_insn_config;
s->insn_read = s626_ai_insn_read;
s->do_cmd = s626_ai_cmd;
s->do_cmdtest = s626_ai_cmdtest;
s->cancel = s626_ai_cancel;
s = dev->subdevices + 1;
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = S626_DAC_CHANNELS;
s->maxdata = (0x3fff);
s->range_table = &range_bipolar10;
s->insn_write = s626_ao_winsn;
s->insn_read = s626_ao_rinsn;
s = dev->subdevices + 2;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = 16;
s->maxdata = 1;
s->io_bits = 0xffff;
s->private = &dio_private_A;
s->range_table = &range_digital;
s->insn_config = s626_dio_insn_config;
s->insn_bits = s626_dio_insn_bits;
s = dev->subdevices + 3;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = 16;
s->maxdata = 1;
s->io_bits = 0xffff;
s->private = &dio_private_B;
s->range_table = &range_digital;
s->insn_config = s626_dio_insn_config;
s->insn_bits = s626_dio_insn_bits;
s = dev->subdevices + 4;
s->type = COMEDI_SUBD_DIO;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE;
s->n_chan = 16;
s->maxdata = 1;
s->io_bits = 0xffff;
s->private = &dio_private_C;
s->range_table = &range_digital;
s->insn_config = s626_dio_insn_config;
s->insn_bits = s626_dio_insn_bits;
s = dev->subdevices + 5;
s->type = COMEDI_SUBD_COUNTER;
s->subdev_flags = SDF_WRITABLE | SDF_READABLE | SDF_LSAMPL;
s->n_chan = S626_ENCODER_CHANNELS;
s->private = enc_private_data;
s->insn_config = s626_enc_insn_config;
s->insn_read = s626_enc_insn_read;
s->insn_write = s626_enc_insn_write;
s->maxdata = 0xffffff;
s->range_table = &range_unknown;
s626_initialize(dev);
dev_info(dev->class_dev, "%s attached\n", dev->board_name);
return 0;
}
static void s626_detach(struct comedi_device *dev)
{
struct pci_dev *pcidev = comedi_to_pci_dev(dev);
if (devpriv) {
devpriv->ai_cmd_running = 0;
if (devpriv->base_addr) {
WR7146(P_IER, 0);
WR7146(P_ISR, IRQ_GPIO3 | IRQ_RPS1);
WriteMISC2(dev, 0);
WR7146(P_MC1, MC1_SHUTDOWN);
WR7146(P_ACON1, ACON1_BASE);
CloseDMAB(dev, &devpriv->RPSBuf, DMABUF_SIZE);
CloseDMAB(dev, &devpriv->ANABuf, DMABUF_SIZE);
}
if (dev->irq)
free_irq(dev->irq, dev);
if (devpriv->base_addr)
iounmap(devpriv->base_addr);
}
if (pcidev) {
if (dev->iobase)
comedi_pci_disable(pcidev);
}
}
static int __devinit s626_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &s626_driver);
}
static void __devexit s626_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
