int i_APCI2032_ConfigDigitalOutput(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int ul_Command = 0;
devpriv->tsk_Current = current;
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
outl(ul_Command, devpriv->iobase + APCI2032_DIGITAL_OP_INTERRUPT);
ui_InterruptData = inl(devpriv->iobase + APCI2032_DIGITAL_OP_INTERRUPT);
return insn->n;
}
int i_APCI2032_WriteDigitalOutput(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int ui_Temp, ui_Temp1;
unsigned int ui_NoOfChannel = CR_CHAN(insn->chanspec);
if (devpriv->b_OutputMemoryStatus) {
ui_Temp = inl(devpriv->iobase + APCI2032_DIGITAL_OP);
}
else {
ui_Temp = 0;
}
if (data[3] == 0) {
if (data[1] == 0) {
data[0] = (data[0] << ui_NoOfChannel) | ui_Temp;
outl(data[0], devpriv->iobase + APCI2032_DIGITAL_OP);
}
else {
if (data[1] == 1) {
switch (ui_NoOfChannel) {
case 2:
data[0] =
(data[0] << (2 *
data[2])) | ui_Temp;
break;
case 4:
data[0] =
(data[0] << (4 *
data[2])) | ui_Temp;
break;
case 8:
data[0] =
(data[0] << (8 *
data[2])) | ui_Temp;
break;
case 16:
data[0] =
(data[0] << (16 *
data[2])) | ui_Temp;
break;
case 31:
data[0] = data[0] | ui_Temp;
break;
default:
comedi_error(dev, " chan spec wrong");
return -EINVAL;
}
outl(data[0],
devpriv->iobase + APCI2032_DIGITAL_OP);
}
else {
printk("\nSpecified channel not supported\n");
}
}
}
else {
if (data[3] == 1) {
if (data[1] == 0) {
data[0] = ~data[0] & 0x1;
ui_Temp1 = 1;
ui_Temp1 = ui_Temp1 << ui_NoOfChannel;
ui_Temp = ui_Temp | ui_Temp1;
data[0] =
(data[0] << ui_NoOfChannel) ^
0xffffffff;
data[0] = data[0] & ui_Temp;
outl(data[0],
devpriv->iobase + APCI2032_DIGITAL_OP);
}
else {
if (data[1] == 1) {
switch (ui_NoOfChannel) {
case 2:
data[0] = ~data[0] & 0x3;
ui_Temp1 = 3;
ui_Temp1 =
ui_Temp1 << 2 * data[2];
ui_Temp = ui_Temp | ui_Temp1;
data[0] =
((data[0] << (2 *
data
[2])) ^
0xffffffff) & ui_Temp;
break;
case 4:
data[0] = ~data[0] & 0xf;
ui_Temp1 = 15;
ui_Temp1 =
ui_Temp1 << 4 * data[2];
ui_Temp = ui_Temp | ui_Temp1;
data[0] =
((data[0] << (4 *
data
[2])) ^
0xffffffff) & ui_Temp;
break;
case 8:
data[0] = ~data[0] & 0xff;
ui_Temp1 = 255;
ui_Temp1 =
ui_Temp1 << 8 * data[2];
ui_Temp = ui_Temp | ui_Temp1;
data[0] =
((data[0] << (8 *
data
[2])) ^
0xffffffff) & ui_Temp;
break;
case 16:
data[0] = ~data[0] & 0xffff;
ui_Temp1 = 65535;
ui_Temp1 =
ui_Temp1 << 16 *
data[2];
ui_Temp = ui_Temp | ui_Temp1;
data[0] =
((data[0] << (16 *
data
[2])) ^
0xffffffff) & ui_Temp;
break;
case 31:
break;
default:
comedi_error(dev,
" chan spec wrong");
return -EINVAL;
}
outl(data[0],
devpriv->iobase +
APCI2032_DIGITAL_OP);
}
else {
printk("\nSpecified channel not supported\n");
}
}
}
else {
printk("\nSpecified functionality does not exist\n");
return -EINVAL;
}
}
return insn->n;
}
int i_APCI2032_ReadDigitalOutput(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int ui_Temp;
unsigned int ui_NoOfChannel;
ui_NoOfChannel = CR_CHAN(insn->chanspec);
ui_Temp = data[0];
*data = inl(devpriv->iobase + APCI2032_DIGITAL_OP_RW);
if (ui_Temp == 0) {
*data = (*data >> ui_NoOfChannel) & 0x1;
}
else {
if (ui_Temp == 1) {
switch (ui_NoOfChannel) {
case 2:
*data = (*data >> (2 * data[1])) & 3;
break;
case 4:
*data = (*data >> (4 * data[1])) & 15;
break;
case 8:
*data = (*data >> (8 * data[1])) & 255;
break;
case 16:
*data = (*data >> (16 * data[1])) & 65535;
break;
case 31:
break;
default:
comedi_error(dev, " chan spec wrong");
return -EINVAL;
}
}
else {
printk("\nSpecified channel not supported \n");
}
}
return insn->n;
}
int i_APCI2032_ConfigWatchdog(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (data[0] == 0) {
outl(0x0,
devpriv->iobase + APCI2032_DIGITAL_OP_WATCHDOG +
APCI2032_TCW_PROG);
outl(data[1],
devpriv->iobase + APCI2032_DIGITAL_OP_WATCHDOG +
APCI2032_TCW_RELOAD_VALUE);
} else {
printk("\nThe input parameters are wrong\n");
return -EINVAL;
}
return insn->n;
}
int i_APCI2032_StartStopWriteWatchdog(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
switch (data[0]) {
case 0:
outl(0x0, devpriv->iobase + APCI2032_DIGITAL_OP_WATCHDOG + APCI2032_TCW_PROG);
break;
case 1:
outl(0x0001,
devpriv->iobase + APCI2032_DIGITAL_OP_WATCHDOG +
APCI2032_TCW_PROG);
break;
case 2:
outl(0x0201,
devpriv->iobase + APCI2032_DIGITAL_OP_WATCHDOG +
APCI2032_TCW_PROG);
break;
default:
printk("\nSpecified functionality does not exist\n");
return -EINVAL;
}
return insn->n;
}
int i_APCI2032_ReadWatchdog(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[0] =
inl(devpriv->iobase + APCI2032_DIGITAL_OP_WATCHDOG +
APCI2032_TCW_TRIG_STATUS) & 0x1;
return insn->n;
}
void v_APCI2032_Interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
unsigned int ui_DO;
ui_DO = inl(devpriv->iobase + APCI2032_DIGITAL_OP_IRQ) & 0x1;
if (ui_DO == 0) {
printk("\nInterrupt from unKnown source\n");
}
if (ui_DO) {
ui_Type =
inl(devpriv->iobase +
APCI2032_DIGITAL_OP_INTERRUPT_STATUS) & 0x3;
outl(0x0,
devpriv->iobase + APCI2032_DIGITAL_OP +
APCI2032_DIGITAL_OP_INTERRUPT);
if (ui_Type == 1) {
send_sig(SIGIO, devpriv->tsk_Current, 0);
}
else {
if (ui_Type == 2) {
send_sig(SIGIO, devpriv->tsk_Current, 0);
}
}
}
return;
}
int i_APCI2032_ReadInterruptStatus(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
*data = ui_Type;
return insn->n;
}
int i_APCI2032_Reset(struct comedi_device *dev)
{
devpriv->b_DigitalOutputRegister = 0;
ui_Type = 0;
outl(0x0, devpriv->iobase + APCI2032_DIGITAL_OP);
outl(0x0, devpriv->iobase + APCI2032_DIGITAL_OP_INTERRUPT);
outl(0x0, devpriv->iobase + APCI2032_DIGITAL_OP_WATCHDOG + APCI2032_TCW_PROG);
outl(0x0, devpriv->iobase + APCI2032_DIGITAL_OP_WATCHDOG + APCI2032_TCW_RELOAD_VALUE);
return 0;
}
