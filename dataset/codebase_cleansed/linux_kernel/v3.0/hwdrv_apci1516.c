int i_APCI1516_Read1DigitalInput(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int ui_TmpValue = 0;
unsigned int ui_Channel;
ui_Channel = CR_CHAN(insn->chanspec);
if (ui_Channel <= 7) {
ui_TmpValue = (unsigned int) inw(devpriv->iobase + APCI1516_DIGITAL_IP);
*data = (ui_TmpValue >> ui_Channel) & 0x1;
}
else {
return -EINVAL;
}
return insn->n;
}
int i_APCI1516_ReadMoreDigitalInput(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int ui_PortValue = data[0];
unsigned int ui_Mask = 0;
unsigned int ui_NoOfChannels;
ui_NoOfChannels = CR_CHAN(insn->chanspec);
*data = (unsigned int) inw(devpriv->iobase + APCI1516_DIGITAL_IP);
switch (ui_NoOfChannels) {
case 2:
ui_Mask = 3;
*data = (*data >> (2 * ui_PortValue)) & ui_Mask;
break;
case 4:
ui_Mask = 15;
*data = (*data >> (4 * ui_PortValue)) & ui_Mask;
break;
case 7:
break;
default:
printk("\nWrong parameters\n");
return -EINVAL;
break;
}
return insn->n;
}
int i_APCI1516_ConfigDigitalOutput(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
devpriv->b_OutputMemoryStatus = data[0];
return insn->n;
}
int i_APCI1516_WriteDigitalOutput(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int ui_Temp, ui_Temp1;
unsigned int ui_NoOfChannel = CR_CHAN(insn->chanspec);
printk("EL311003 : @=%x\n", devpriv->iobase + APCI1516_DIGITAL_OP);
if (devpriv->b_OutputMemoryStatus) {
ui_Temp = inw(devpriv->iobase + APCI1516_DIGITAL_OP);
}
else {
ui_Temp = 0;
}
if (data[3] == 0) {
if (data[1] == 0) {
data[0] = (data[0] << ui_NoOfChannel) | ui_Temp;
outw(data[0], devpriv->iobase + APCI1516_DIGITAL_OP);
printk("EL311003 : d=%d @=%x\n", data[0],
devpriv->iobase + APCI1516_DIGITAL_OP);
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
case 7:
data[0] = data[0] | ui_Temp;
break;
default:
comedi_error(dev, " chan spec wrong");
return -EINVAL;
}
outw(data[0],
devpriv->iobase + APCI1516_DIGITAL_OP);
printk("EL311003 : d=%d @=%x\n", data[0],
devpriv->iobase + APCI1516_DIGITAL_OP);
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
data[0] = (data[0] << ui_NoOfChannel) ^ 0xff;
data[0] = data[0] & ui_Temp;
outw(data[0],
devpriv->iobase + APCI1516_DIGITAL_OP);
printk("EL311003 : d=%d @=%x\n", data[0],
devpriv->iobase + APCI1516_DIGITAL_OP);
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
0xff) & ui_Temp;
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
0xff) & ui_Temp;
break;
case 7:
break;
default:
comedi_error(dev,
" chan spec wrong");
return -EINVAL;
}
outw(data[0],
devpriv->iobase +
APCI1516_DIGITAL_OP);
printk("EL311003 : d=%d @=%x\n",
data[0],
devpriv->iobase +
APCI1516_DIGITAL_OP);
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
return (insn->n);
}
int i_APCI1516_ReadDigitalOutput(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned int ui_Temp;
unsigned int ui_NoOfChannel = CR_CHAN(insn->chanspec);
ui_Temp = data[0];
*data = inw(devpriv->iobase + APCI1516_DIGITAL_OP_RW);
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
case 7:
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
int i_APCI1516_ConfigWatchdog(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
if (data[0] == 0) {
outw(0x0,
devpriv->i_IobaseAddon +
APCI1516_WATCHDOG_ENABLEDISABLE);
outw(data[1],
devpriv->i_IobaseAddon +
APCI1516_WATCHDOG_RELOAD_VALUE);
data[1] = data[1] >> 16;
outw(data[1],
devpriv->i_IobaseAddon +
APCI1516_WATCHDOG_RELOAD_VALUE + 2);
}
else {
printk("\nThe input parameters are wrong\n");
return -EINVAL;
}
return insn->n;
}
int i_APCI1516_StartStopWriteWatchdog(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
switch (data[0]) {
case 0:
outw(0x0, devpriv->i_IobaseAddon + APCI1516_WATCHDOG_ENABLEDISABLE);
break;
case 1:
outw(0x0001,
devpriv->i_IobaseAddon +
APCI1516_WATCHDOG_ENABLEDISABLE);
break;
case 2:
outw(0x0201,
devpriv->i_IobaseAddon +
APCI1516_WATCHDOG_ENABLEDISABLE);
break;
default:
printk("\nSpecified functionality does not exist\n");
return -EINVAL;
}
return insn->n;
}
int i_APCI1516_ReadWatchdog(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[0] = inw(devpriv->i_IobaseAddon + APCI1516_WATCHDOG_STATUS) & 0x1;
return insn->n;
}
int i_APCI1516_Reset(struct comedi_device *dev)
{
outw(0x0, devpriv->iobase + APCI1516_DIGITAL_OP);
outw(0x0, devpriv->i_IobaseAddon + APCI1516_WATCHDOG_ENABLEDISABLE);
outw(0x0, devpriv->i_IobaseAddon + APCI1516_WATCHDOG_RELOAD_VALUE);
outw(0x0, devpriv->i_IobaseAddon + APCI1516_WATCHDOG_RELOAD_VALUE + 2);
return 0;
}
