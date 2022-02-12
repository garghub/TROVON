static int i_APCI1564_ConfigDigitalInput(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
devpriv->tsk_Current = current;
if (data[0] == ADDIDATA_ENABLE) {
data[2] = data[2] << 4;
data[3] = data[3] << 4;
outl(data[2],
devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP +
APCI1564_DIGITAL_IP_INTERRUPT_MODE1);
outl(data[3],
devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP +
APCI1564_DIGITAL_IP_INTERRUPT_MODE2);
if (data[1] == ADDIDATA_OR) {
outl(0x4,
devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP +
APCI1564_DIGITAL_IP_IRQ);
}
else {
outl(0x6,
devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP +
APCI1564_DIGITAL_IP_IRQ);
}
}
else {
outl(0x0,
devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP +
APCI1564_DIGITAL_IP_INTERRUPT_MODE1);
outl(0x0,
devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP +
APCI1564_DIGITAL_IP_INTERRUPT_MODE2);
outl(0x0,
devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP +
APCI1564_DIGITAL_IP_IRQ);
}
return insn->n;
}
static int apci1564_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
data[1] = inl(devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP);
return insn->n;
}
static int i_APCI1564_ConfigDigitalOutput(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
unsigned int ul_Command = 0;
if ((data[0] != 0) && (data[0] != 1)) {
comedi_error(dev,
"Not a valid Data !!! ,Data should be 1 or 0\n");
return -EINVAL;
}
if (data[0]) {
devpriv->b_OutputMemoryStatus = ADDIDATA_ENABLE;
}
else {
devpriv->b_OutputMemoryStatus = ADDIDATA_DISABLE;
}
if (data[1] == ADDIDATA_ENABLE) {
ul_Command = ul_Command | 0x1;
}
else {
ul_Command = ul_Command & 0xFFFFFFFE;
}
if (data[2] == ADDIDATA_ENABLE) {
ul_Command = ul_Command | 0x2;
}
else {
ul_Command = ul_Command & 0xFFFFFFFD;
}
outl(ul_Command,
devpriv->i_IobaseAmcc + APCI1564_DIGITAL_OP +
APCI1564_DIGITAL_OP_INTERRUPT);
ui_InterruptData =
inl(devpriv->i_IobaseAmcc + APCI1564_DIGITAL_OP +
APCI1564_DIGITAL_OP_INTERRUPT);
devpriv->tsk_Current = current;
return insn->n;
}
static int apci1564_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
unsigned int mask = data[0];
unsigned int bits = data[1];
s->state = inl(devpriv->i_IobaseAmcc + APCI1564_DIGITAL_OP +
APCI1564_DIGITAL_OP_RW);
if (mask) {
s->state &= ~mask;
s->state |= (bits & mask);
outl(s->state, devpriv->i_IobaseAmcc + APCI1564_DIGITAL_OP +
APCI1564_DIGITAL_OP_RW);
}
data[1] = s->state;
return insn->n;
}
static int i_APCI1564_ConfigTimerCounterWatchdog(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
unsigned int ul_Command1 = 0;
devpriv->tsk_Current = current;
if (data[0] == ADDIDATA_WATCHDOG) {
devpriv->b_TimerSelectMode = ADDIDATA_WATCHDOG;
outl(0x0,
devpriv->i_IobaseAmcc + APCI1564_DIGITAL_OP_WATCHDOG +
APCI1564_TCW_PROG);
outl(data[3],
devpriv->i_IobaseAmcc + APCI1564_DIGITAL_OP_WATCHDOG +
APCI1564_TCW_RELOAD_VALUE);
}
else if (data[0] == ADDIDATA_TIMER) {
ul_Command1 =
inl(devpriv->i_IobaseAmcc + APCI1564_TIMER +
APCI1564_TCW_PROG);
ul_Command1 = ul_Command1 & 0xFFFFF9FEUL;
outl(ul_Command1, devpriv->i_IobaseAmcc + APCI1564_TIMER + APCI1564_TCW_PROG);
devpriv->b_TimerSelectMode = ADDIDATA_TIMER;
if (data[1] == 1) {
outl(0x02, devpriv->i_IobaseAmcc + APCI1564_TIMER + APCI1564_TCW_PROG);
outl(0x0,
devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP +
APCI1564_DIGITAL_IP_IRQ);
outl(0x0,
devpriv->i_IobaseAmcc + APCI1564_DIGITAL_OP +
APCI1564_DIGITAL_OP_IRQ);
outl(0x0,
devpriv->i_IobaseAmcc +
APCI1564_DIGITAL_OP_WATCHDOG +
APCI1564_TCW_IRQ);
outl(0x0,
devpriv->iobase + APCI1564_COUNTER1 +
APCI1564_TCW_IRQ);
outl(0x0,
devpriv->iobase + APCI1564_COUNTER2 +
APCI1564_TCW_IRQ);
outl(0x0,
devpriv->iobase + APCI1564_COUNTER3 +
APCI1564_TCW_IRQ);
outl(0x0,
devpriv->iobase + APCI1564_COUNTER4 +
APCI1564_TCW_IRQ);
}
else {
outl(0x0, devpriv->i_IobaseAmcc + APCI1564_TIMER + APCI1564_TCW_PROG);
}
outl(data[2],
devpriv->i_IobaseAmcc + APCI1564_TIMER +
APCI1564_TCW_TIMEBASE);
outl(data[3],
devpriv->i_IobaseAmcc + APCI1564_TIMER +
APCI1564_TCW_RELOAD_VALUE);
ul_Command1 =
inl(devpriv->i_IobaseAmcc + APCI1564_TIMER +
APCI1564_TCW_PROG);
ul_Command1 =
(ul_Command1 & 0xFFF719E2UL) | 2UL << 13UL | 0x10UL;
outl(ul_Command1, devpriv->i_IobaseAmcc + APCI1564_TIMER + APCI1564_TCW_PROG);
}
else if (data[0] == ADDIDATA_COUNTER) {
devpriv->b_TimerSelectMode = ADDIDATA_COUNTER;
devpriv->b_ModeSelectRegister = data[5];
ul_Command1 =
inl(devpriv->iobase + ((data[5] - 1) * 0x20) +
APCI1564_TCW_PROG);
ul_Command1 = ul_Command1 & 0xFFFFF9FEUL;
outl(ul_Command1, devpriv->iobase + ((data[5] - 1) * 0x20) + APCI1564_TCW_PROG);
outl(data[3],
devpriv->iobase + ((data[5] - 1) * 0x20) +
APCI1564_TCW_RELOAD_VALUE);
ul_Command1 =
(ul_Command1 & 0xFFFC19E2UL) | 0x80000UL |
(unsigned int) ((unsigned int) data[4] << 16UL);
outl(ul_Command1,
devpriv->iobase + ((data[5] - 1) * 0x20) +
APCI1564_TCW_PROG);
ul_Command1 = (ul_Command1 & 0xFFFFF9FD) | (data[1] << 1);
outl(ul_Command1,
devpriv->iobase + ((data[5] - 1) * 0x20) +
APCI1564_TCW_PROG);
ul_Command1 = (ul_Command1 & 0xFFFBF9FFUL) | (data[6] << 18);
outl(ul_Command1,
devpriv->iobase + ((data[5] - 1) * 0x20) +
APCI1564_TCW_PROG);
}
else {
printk(" Invalid subdevice.");
}
return insn->n;
}
static int i_APCI1564_StartStopWriteTimerCounterWatchdog(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
unsigned int ul_Command1 = 0;
if (devpriv->b_TimerSelectMode == ADDIDATA_WATCHDOG) {
switch (data[1]) {
case 0:
outl(0x0, devpriv->i_IobaseAmcc + APCI1564_DIGITAL_OP_WATCHDOG + APCI1564_TCW_PROG);
break;
case 1:
outl(0x0001,
devpriv->i_IobaseAmcc +
APCI1564_DIGITAL_OP_WATCHDOG +
APCI1564_TCW_PROG);
break;
case 2:
outl(0x0201,
devpriv->i_IobaseAmcc +
APCI1564_DIGITAL_OP_WATCHDOG +
APCI1564_TCW_PROG);
break;
default:
printk("\nSpecified functionality does not exist\n");
return -EINVAL;
}
}
if (devpriv->b_TimerSelectMode == ADDIDATA_TIMER) {
if (data[1] == 1) {
ul_Command1 =
inl(devpriv->i_IobaseAmcc + APCI1564_TIMER +
APCI1564_TCW_PROG);
ul_Command1 = (ul_Command1 & 0xFFFFF9FFUL) | 0x1UL;
outl(ul_Command1,
devpriv->i_IobaseAmcc + APCI1564_TIMER +
APCI1564_TCW_PROG);
}
else if (data[1] == 0) {
ul_Command1 =
inl(devpriv->i_IobaseAmcc + APCI1564_TIMER +
APCI1564_TCW_PROG);
ul_Command1 = ul_Command1 & 0xFFFFF9FEUL;
outl(ul_Command1,
devpriv->i_IobaseAmcc + APCI1564_TIMER +
APCI1564_TCW_PROG);
}
}
if (devpriv->b_TimerSelectMode == ADDIDATA_COUNTER) {
ul_Command1 =
inl(devpriv->iobase + ((devpriv->b_ModeSelectRegister -
1) * 0x20) + APCI1564_TCW_PROG);
if (data[1] == 1) {
ul_Command1 = (ul_Command1 & 0xFFFFF9FFUL) | 0x1UL;
}
else if (data[1] == 0) {
ul_Command1 = 0;
}
else if (data[1] == 2) {
ul_Command1 = (ul_Command1 & 0xFFFFF9FFUL) | 0x400;
}
outl(ul_Command1,
devpriv->iobase + ((devpriv->b_ModeSelectRegister -
1) * 0x20) + APCI1564_TCW_PROG);
}
return insn->n;
}
static int i_APCI1564_ReadTimerCounterWatchdog(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
unsigned int ul_Command1 = 0;
if (devpriv->b_TimerSelectMode == ADDIDATA_WATCHDOG) {
data[0] =
inl(devpriv->i_IobaseAmcc +
APCI1564_DIGITAL_OP_WATCHDOG +
APCI1564_TCW_TRIG_STATUS) & 0x1;
data[1] =
inl(devpriv->i_IobaseAmcc +
APCI1564_DIGITAL_OP_WATCHDOG);
}
else if (devpriv->b_TimerSelectMode == ADDIDATA_TIMER) {
data[0] =
inl(devpriv->i_IobaseAmcc + APCI1564_TIMER +
APCI1564_TCW_TRIG_STATUS) & 0x1;
data[1] = inl(devpriv->i_IobaseAmcc + APCI1564_TIMER);
}
else if (devpriv->b_TimerSelectMode == ADDIDATA_COUNTER) {
data[0] =
inl(devpriv->iobase + ((devpriv->b_ModeSelectRegister -
1) * 0x20) +
APCI1564_TCW_SYNC_ENABLEDISABLE);
ul_Command1 =
inl(devpriv->iobase + ((devpriv->b_ModeSelectRegister -
1) * 0x20) + APCI1564_TCW_TRIG_STATUS);
data[1] = (unsigned char) ((ul_Command1 >> 1) & 1);
data[2] = (unsigned char) ((ul_Command1 >> 2) & 1);
data[3] = (unsigned char) ((ul_Command1 >> 3) & 1);
data[4] = (unsigned char) ((ul_Command1 >> 0) & 1);
}
else if ((devpriv->b_TimerSelectMode != ADDIDATA_TIMER)
&& (devpriv->b_TimerSelectMode != ADDIDATA_WATCHDOG)
&& (devpriv->b_TimerSelectMode != ADDIDATA_COUNTER)) {
printk("\n Invalid Subdevice !!!\n");
}
return insn->n;
}
static int i_APCI1564_ReadInterruptStatus(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
*data = ui_Type;
return insn->n;
}
static void v_APCI1564_Interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct addi_private *devpriv = dev->private;
unsigned int ui_DO, ui_DI;
unsigned int ui_Timer;
unsigned int ui_C1, ui_C2, ui_C3, ui_C4;
unsigned int ul_Command2 = 0;
ui_DI = inl(devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP +
APCI1564_DIGITAL_IP_IRQ) & 0x01;
ui_DO = inl(devpriv->i_IobaseAmcc + APCI1564_DIGITAL_OP +
APCI1564_DIGITAL_OP_IRQ) & 0x01;
ui_Timer =
inl(devpriv->i_IobaseAmcc + APCI1564_TIMER +
APCI1564_TCW_IRQ) & 0x01;
ui_C1 = inl(devpriv->iobase + APCI1564_COUNTER1 +
APCI1564_TCW_IRQ) & 0x1;
ui_C2 = inl(devpriv->iobase + APCI1564_COUNTER2 +
APCI1564_TCW_IRQ) & 0x1;
ui_C3 = inl(devpriv->iobase + APCI1564_COUNTER3 +
APCI1564_TCW_IRQ) & 0x1;
ui_C4 = inl(devpriv->iobase + APCI1564_COUNTER4 +
APCI1564_TCW_IRQ) & 0x1;
if (ui_DI == 0 && ui_DO == 0 && ui_Timer == 0 && ui_C1 == 0
&& ui_C2 == 0 && ui_C3 == 0 && ui_C4 == 0) {
printk("\nInterrupt from unknown source\n");
}
if (ui_DI == 1) {
ui_DI = inl(devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP +
APCI1564_DIGITAL_IP_IRQ);
outl(0x0,
devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP +
APCI1564_DIGITAL_IP_IRQ);
ui_InterruptStatus_1564 =
inl(devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP +
APCI1564_DIGITAL_IP_INTERRUPT_STATUS);
ui_InterruptStatus_1564 = ui_InterruptStatus_1564 & 0X000FFFF0;
send_sig(SIGIO, devpriv->tsk_Current, 0);
outl(ui_DI, devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP + APCI1564_DIGITAL_IP_IRQ);
return;
}
if (ui_DO == 1) {
ui_Type =
inl(devpriv->i_IobaseAmcc + APCI1564_DIGITAL_OP +
APCI1564_DIGITAL_OP_INTERRUPT_STATUS) & 0x3;
outl(0x0,
devpriv->i_IobaseAmcc + APCI1564_DIGITAL_OP +
APCI1564_DIGITAL_OP_INTERRUPT);
send_sig(SIGIO, devpriv->tsk_Current, 0);
}
if (ui_Timer == 1) {
devpriv->b_TimerSelectMode = ADDIDATA_TIMER;
if (devpriv->b_TimerSelectMode) {
ul_Command2 =
inl(devpriv->i_IobaseAmcc + APCI1564_TIMER +
APCI1564_TCW_PROG);
outl(0x0,
devpriv->i_IobaseAmcc + APCI1564_TIMER +
APCI1564_TCW_PROG);
send_sig(SIGIO, devpriv->tsk_Current, 0);
outl(ul_Command2,
devpriv->i_IobaseAmcc + APCI1564_TIMER +
APCI1564_TCW_PROG);
}
}
if (ui_C1 == 1) {
devpriv->b_TimerSelectMode = ADDIDATA_COUNTER;
if (devpriv->b_TimerSelectMode) {
ul_Command2 =
inl(devpriv->iobase + APCI1564_COUNTER1 +
APCI1564_TCW_PROG);
outl(0x0,
devpriv->iobase + APCI1564_COUNTER1 +
APCI1564_TCW_PROG);
send_sig(SIGIO, devpriv->tsk_Current, 0);
outl(ul_Command2,
devpriv->iobase + APCI1564_COUNTER1 +
APCI1564_TCW_PROG);
}
}
if (ui_C2 == 1) {
devpriv->b_TimerSelectMode = ADDIDATA_COUNTER;
if (devpriv->b_TimerSelectMode) {
ul_Command2 =
inl(devpriv->iobase + APCI1564_COUNTER2 +
APCI1564_TCW_PROG);
outl(0x0,
devpriv->iobase + APCI1564_COUNTER2 +
APCI1564_TCW_PROG);
send_sig(SIGIO, devpriv->tsk_Current, 0);
outl(ul_Command2,
devpriv->iobase + APCI1564_COUNTER2 +
APCI1564_TCW_PROG);
}
}
if (ui_C3 == 1) {
devpriv->b_TimerSelectMode = ADDIDATA_COUNTER;
if (devpriv->b_TimerSelectMode) {
ul_Command2 =
inl(devpriv->iobase + APCI1564_COUNTER3 +
APCI1564_TCW_PROG);
outl(0x0,
devpriv->iobase + APCI1564_COUNTER3 +
APCI1564_TCW_PROG);
send_sig(SIGIO, devpriv->tsk_Current, 0);
outl(ul_Command2,
devpriv->iobase + APCI1564_COUNTER3 +
APCI1564_TCW_PROG);
}
}
if (ui_C4 == 1) {
devpriv->b_TimerSelectMode = ADDIDATA_COUNTER;
if (devpriv->b_TimerSelectMode) {
ul_Command2 =
inl(devpriv->iobase + APCI1564_COUNTER4 +
APCI1564_TCW_PROG);
outl(0x0,
devpriv->iobase + APCI1564_COUNTER4 +
APCI1564_TCW_PROG);
send_sig(SIGIO, devpriv->tsk_Current, 0);
outl(ul_Command2,
devpriv->iobase + APCI1564_COUNTER4 +
APCI1564_TCW_PROG);
}
}
return;
}
static int i_APCI1564_Reset(struct comedi_device *dev)
{
struct addi_private *devpriv = dev->private;
outl(0x0, devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP_IRQ);
inl(devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP_INTERRUPT_STATUS);
outl(0x0, devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP_INTERRUPT_MODE1);
outl(0x0, devpriv->i_IobaseAmcc + APCI1564_DIGITAL_IP_INTERRUPT_MODE2);
devpriv->b_DigitalOutputRegister = 0;
ui_Type = 0;
outl(0x0, devpriv->i_IobaseAmcc + APCI1564_DIGITAL_OP);
outl(0x0, devpriv->i_IobaseAmcc + APCI1564_DIGITAL_OP_INTERRUPT);
outl(0x0,
devpriv->i_IobaseAmcc + APCI1564_DIGITAL_OP_WATCHDOG +
APCI1564_TCW_RELOAD_VALUE);
outl(0x0, devpriv->i_IobaseAmcc + APCI1564_TIMER);
outl(0x0, devpriv->i_IobaseAmcc + APCI1564_TIMER + APCI1564_TCW_PROG);
outl(0x0, devpriv->iobase + APCI1564_COUNTER1 + APCI1564_TCW_PROG);
outl(0x0, devpriv->iobase + APCI1564_COUNTER2 + APCI1564_TCW_PROG);
outl(0x0, devpriv->iobase + APCI1564_COUNTER3 + APCI1564_TCW_PROG);
outl(0x0, devpriv->iobase + APCI1564_COUNTER4 + APCI1564_TCW_PROG);
return 0;
}
