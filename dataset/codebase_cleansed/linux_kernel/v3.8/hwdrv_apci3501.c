static int apci3501_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
data[1] = inl(devpriv->iobase + APCI3501_DIGITAL_IP) & 0x3;
return insn->n;
}
static int apci3501_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
unsigned int mask = data[0];
unsigned int bits = data[1];
s->state = inl(devpriv->iobase + APCI3501_DIGITAL_OP);
if (mask) {
s->state &= ~mask;
s->state |= (bits & mask);
outl(s->state, devpriv->iobase + APCI3501_DIGITAL_OP);
}
data[1] = s->state;
return insn->n;
}
static int i_APCI3501_ConfigAnalogOutput(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
outl(data[0],
devpriv->iobase + APCI3501_ANALOG_OUTPUT +
APCI3501_AO_VOLT_MODE);
if (data[0]) {
devpriv->b_InterruptMode = MODE1;
} else {
devpriv->b_InterruptMode = MODE0;
}
return insn->n;
}
static int i_APCI3501_WriteAnalogOutput(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
unsigned int ul_Command1 = 0, ul_Channel_no, ul_Polarity, ul_DAC_Ready = 0;
ul_Channel_no = CR_CHAN(insn->chanspec);
if (devpriv->b_InterruptMode == MODE1) {
ul_Polarity = 0x80000000;
if ((*data < 0) || (*data > 16384)) {
printk("\nIn WriteAnalogOutput :: Not Valid Data\n");
}
}
else {
ul_Polarity = 0;
if ((*data < 0) || (*data > 8192)) {
printk("\nIn WriteAnalogOutput :: Not Valid Data\n");
}
}
if ((ul_Channel_no < 0) || (ul_Channel_no > 7)) {
printk("\nIn WriteAnalogOutput :: Not Valid Channel\n");
}
ul_DAC_Ready = inl(devpriv->iobase + APCI3501_ANALOG_OUTPUT);
while (ul_DAC_Ready == 0) {
ul_DAC_Ready = inl(devpriv->iobase + APCI3501_ANALOG_OUTPUT);
ul_DAC_Ready = (ul_DAC_Ready >> 8) & 1;
}
if (ul_DAC_Ready) {
ul_Command1 =
(unsigned int) ((unsigned int) (ul_Channel_no & 0xFF) |
(unsigned int) ((*data << 0x8) & 0x7FFFFF00L) |
(unsigned int) (ul_Polarity));
outl(ul_Command1,
devpriv->iobase + APCI3501_ANALOG_OUTPUT +
APCI3501_AO_PROG);
}
return insn->n;
}
static int i_APCI3501_ConfigTimerCounterWatchdog(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
unsigned int ul_Command1 = 0;
devpriv->tsk_Current = current;
if (data[0] == ADDIDATA_WATCHDOG) {
devpriv->b_TimerSelectMode = ADDIDATA_WATCHDOG;
outl(0x0, devpriv->iobase + APCI3501_WATCHDOG + APCI3501_TCW_PROG);
if (data[1] == 1) {
outl(0x02,
devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_PROG);
} else {
outl(0x0, devpriv->iobase + APCI3501_WATCHDOG + APCI3501_TCW_PROG);
}
outl(data[2],
devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_TIMEBASE);
outl(data[3],
devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_RELOAD_VALUE);
ul_Command1 = inl(devpriv->iobase + APCI3501_WATCHDOG + APCI3501_TCW_PROG) | 0xFFF819E0UL;
outl(ul_Command1,
devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_PROG);
}
else if (data[0] == ADDIDATA_TIMER) {
ul_Command1 =
inl(devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_PROG);
ul_Command1 = ul_Command1 & 0xFFFFF9FEUL;
outl(ul_Command1, devpriv->iobase + APCI3501_WATCHDOG + APCI3501_TCW_PROG);
devpriv->b_TimerSelectMode = ADDIDATA_TIMER;
if (data[1] == 1) {
outl(0x02,
devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_PROG);
} else {
outl(0x0, devpriv->iobase + APCI3501_WATCHDOG + APCI3501_TCW_PROG);
}
outl(data[2],
devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_TIMEBASE);
outl(data[3],
devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_RELOAD_VALUE);
ul_Command1 =
inl(devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_PROG);
ul_Command1 =
(ul_Command1 & 0xFFF719E2UL) | 2UL << 13UL | 0x10UL;
outl(ul_Command1, devpriv->iobase + APCI3501_WATCHDOG + APCI3501_TCW_PROG);
}
return insn->n;
}
static int i_APCI3501_StartStopWriteTimerCounterWatchdog(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
unsigned int ul_Command1 = 0;
int i_Temp;
if (devpriv->b_TimerSelectMode == ADDIDATA_WATCHDOG) {
if (data[1] == 1) {
ul_Command1 =
inl(devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_PROG);
ul_Command1 = (ul_Command1 & 0xFFFFF9FFUL) | 0x1UL;
outl(ul_Command1,
devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_PROG);
}
else if (data[1] == 0)
{
ul_Command1 =
inl(devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_PROG);
ul_Command1 = ul_Command1 & 0xFFFFF9FEUL;
outl(0x0,
devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_PROG);
} else if (data[1] == 2) {
ul_Command1 =
inl(devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_PROG);
ul_Command1 = (ul_Command1 & 0xFFFFF9FFUL) | 0x200UL;
outl(ul_Command1,
devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_PROG);
}
}
if (devpriv->b_TimerSelectMode == ADDIDATA_TIMER) {
if (data[1] == 1) {
ul_Command1 =
inl(devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_PROG);
ul_Command1 = (ul_Command1 & 0xFFFFF9FFUL) | 0x1UL;
outl(ul_Command1,
devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_PROG);
} else if (data[1] == 0) {
ul_Command1 =
inl(devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_PROG);
ul_Command1 = ul_Command1 & 0xFFFFF9FEUL;
outl(ul_Command1,
devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_PROG);
}
else if (data[1] == 2) {
ul_Command1 =
inl(devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_PROG);
ul_Command1 = (ul_Command1 & 0xFFFFF9FFUL) | 0x200UL;
outl(ul_Command1,
devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_PROG);
}
}
i_Temp = inl(devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_TRIG_STATUS) & 0x1;
return insn->n;
}
static int i_APCI3501_ReadTimerCounterWatchdog(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
if (devpriv->b_TimerSelectMode == ADDIDATA_WATCHDOG) {
data[0] =
inl(devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_TRIG_STATUS) & 0x1;
data[1] = inl(devpriv->iobase + APCI3501_WATCHDOG);
}
else if (devpriv->b_TimerSelectMode == ADDIDATA_TIMER) {
data[0] =
inl(devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_TRIG_STATUS) & 0x1;
data[1] = inl(devpriv->iobase + APCI3501_WATCHDOG);
}
else if ((devpriv->b_TimerSelectMode != ADDIDATA_TIMER)
&& (devpriv->b_TimerSelectMode != ADDIDATA_WATCHDOG)) {
printk("\nIn ReadTimerCounterWatchdog :: Invalid Subdevice \n");
}
return insn->n;
}
static int i_APCI3501_Reset(struct comedi_device *dev)
{
struct addi_private *devpriv = dev->private;
int i_Count = 0, i_temp = 0;
unsigned int ul_Command1 = 0, ul_Polarity, ul_DAC_Ready = 0;
outl(0x0, devpriv->iobase + APCI3501_DIGITAL_OP);
outl(1, devpriv->iobase + APCI3501_ANALOG_OUTPUT +
APCI3501_AO_VOLT_MODE);
ul_Polarity = 0x80000000;
for (i_Count = 0; i_Count <= 7; i_Count++) {
ul_DAC_Ready = inl(devpriv->iobase + APCI3501_ANALOG_OUTPUT);
while (ul_DAC_Ready == 0) {
ul_DAC_Ready =
inl(devpriv->iobase + APCI3501_ANALOG_OUTPUT);
ul_DAC_Ready = (ul_DAC_Ready >> 8) & 1;
}
if (ul_DAC_Ready) {
ul_Command1 =
(unsigned int) ((unsigned int) (i_Count & 0xFF) |
(unsigned int) ((i_temp << 0x8) & 0x7FFFFF00L) |
(unsigned int) (ul_Polarity));
outl(ul_Command1,
devpriv->iobase + APCI3501_ANALOG_OUTPUT +
APCI3501_AO_PROG);
}
}
return 0;
}
static void v_APCI3501_Interrupt(int irq, void *d)
{
int i_temp;
struct comedi_device *dev = d;
struct addi_private *devpriv = dev->private;
unsigned int ui_Timer_AOWatchdog;
unsigned long ul_Command1;
ul_Command1 =
inl(devpriv->iobase + APCI3501_WATCHDOG + APCI3501_TCW_PROG);
ul_Command1 = (ul_Command1 & 0xFFFFF9FDul);
outl(ul_Command1,
devpriv->iobase + APCI3501_WATCHDOG + APCI3501_TCW_PROG);
ui_Timer_AOWatchdog =
inl(devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_IRQ) & 0x1;
if ((!ui_Timer_AOWatchdog)) {
comedi_error(dev, "IRQ from unknown source");
return;
}
send_sig(SIGIO, devpriv->tsk_Current, 0);
ul_Command1 =
inl(devpriv->iobase + APCI3501_WATCHDOG + APCI3501_TCW_PROG);
ul_Command1 = ((ul_Command1 & 0xFFFFF9FDul) | 1 << 1);
outl(ul_Command1,
devpriv->iobase + APCI3501_WATCHDOG + APCI3501_TCW_PROG);
i_temp = inl(devpriv->iobase + APCI3501_WATCHDOG +
APCI3501_TCW_TRIG_STATUS) & 0x1;
return;
}
