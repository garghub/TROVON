int i_APCI1710_InsnConfigInitTimer(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i_ReturnValue = 0;
unsigned char b_ModulNbr;
unsigned char b_TimerNbr;
unsigned char b_TimerMode;
unsigned int ul_ReloadValue;
unsigned char b_InputClockSelection;
unsigned char b_InputClockLevel;
unsigned char b_OutputLevel;
unsigned char b_HardwareGateLevel;
unsigned int dw_Test = 0;
i_ReturnValue = insn->n;
b_ModulNbr = (unsigned char) CR_AREF(insn->chanspec);
b_TimerNbr = (unsigned char) CR_CHAN(insn->chanspec);
b_TimerMode = (unsigned char) data[0];
ul_ReloadValue = (unsigned int) data[1];
b_InputClockSelection = (unsigned char) data[2];
b_InputClockLevel = (unsigned char) data[3];
b_OutputLevel = (unsigned char) data[4];
b_HardwareGateLevel = (unsigned char) data[5];
if (b_ModulNbr < 4) {
if ((devpriv->s_BoardInfos.dw_MolduleConfiguration[b_ModulNbr] & 0xFFFF0000UL) == APCI1710_82X54_TIMER) {
if (b_TimerNbr <= 2) {
if (b_TimerMode <= 5) {
if (((b_TimerNbr == 0) &&
(b_InputClockSelection == APCI1710_PCI_BUS_CLOCK)) ||
((b_TimerNbr == 0) &&
(b_InputClockSelection == APCI1710_10MHZ)) ||
((b_TimerNbr != 0) &&
((b_InputClockSelection == APCI1710_PCI_BUS_CLOCK) ||
(b_InputClockSelection == APCI1710_FRONT_CONNECTOR_INPUT) ||
(b_InputClockSelection == APCI1710_10MHZ)))) {
if (((b_InputClockSelection == APCI1710_10MHZ) &&
((devpriv->s_BoardInfos.dw_MolduleConfiguration[b_ModulNbr] & 0x0000FFFFUL) >= 0x3131)) ||
(b_InputClockSelection != APCI1710_10MHZ)) {
if ((b_InputClockLevel == 0) ||
(b_InputClockLevel == 1)) {
if ((b_OutputLevel == 0) || (b_OutputLevel == 1)) {
if ((b_HardwareGateLevel == 0) || (b_HardwareGateLevel == 1)) {
if ((b_InputClockSelection == APCI1710_10MHZ) && ((devpriv->s_BoardInfos.dw_MolduleConfiguration[b_ModulNbr] & 0x0000FFFFUL) > 0x3131)) {
dw_Test = inl(devpriv->s_BoardInfos.ui_Address + (16 + (b_TimerNbr * 4) + (64 * b_ModulNbr)));
dw_Test = (dw_Test >> 16) & 1;
} else {
dw_Test = 1;
}
if (dw_Test == 1) {
devpriv->s_ModuleInfo[b_ModulNbr].s_82X54ModuleInfo.s_82X54TimerInfo[b_TimerNbr].b_82X54Init = 1;
devpriv-> s_ModuleInfo[b_ModulNbr].s_82X54ModuleInfo.s_82X54TimerInfo[b_TimerNbr].b_InputClockSelection = b_InputClockSelection;
devpriv->s_ModuleInfo[b_ModulNbr].s_82X54ModuleInfo.s_82X54TimerInfo[b_TimerNbr].b_InputClockLevel = ~b_InputClockLevel & 1;
devpriv->s_ModuleInfo[b_ModulNbr].s_82X54ModuleInfo.s_82X54TimerInfo[b_TimerNbr].b_OutputLevel = ~b_OutputLevel & 1;
devpriv->s_ModuleInfo[b_ModulNbr].s_82X54ModuleInfo.s_82X54TimerInfo[b_TimerNbr].b_HardwareGateLevel = b_HardwareGateLevel;
if (b_InputClockSelection == APCI1710_10MHZ) {
b_InputClockSelection = 2;
}
devpriv->s_ModuleInfo[b_ModulNbr].s_82X54ModuleInfo.s_82X54TimerInfo[b_TimerNbr].dw_ConfigurationWord = (unsigned int)(((b_HardwareGateLevel << 0) & 0x1) | ((b_InputClockLevel << 1) & 0x2) | (((~b_OutputLevel & 1) << 2) & 0x4) | ((b_InputClockSelection << 4) & 0x30));
outl(devpriv->s_ModuleInfo[b_ModulNbr].s_82X54ModuleInfo.s_82X54TimerInfo[b_TimerNbr].dw_ConfigurationWord, devpriv->s_BoardInfos.ui_Address + 32 + (b_TimerNbr * 4) + (64 * b_ModulNbr));
outl((unsigned int) b_TimerMode, devpriv->s_BoardInfos.ui_Address + 16 + (b_TimerNbr * 4) + (64 * b_ModulNbr));
outl(ul_ReloadValue, devpriv->s_BoardInfos.ui_Address + 0 + (b_TimerNbr * 4) + (64 * b_ModulNbr));
}
else {
i_ReturnValue = -6;
}
}
else {
DPRINTK("Selection from hardware gate level is wrong\n");
i_ReturnValue = -9;
}
}
else {
DPRINTK("Selection from output clock level is wrong\n");
i_ReturnValue = -8;
}
}
else {
DPRINTK("Selection from input clock level is wrong\n");
i_ReturnValue = -7;
}
} else {
DPRINTK("Input timer clock selection is wrong\n");
i_ReturnValue = -6;
}
} else {
DPRINTK("Input timer clock selection is wrong\n");
i_ReturnValue = -6;
}
}
else {
DPRINTK("Timer mode selection is wrong\n");
i_ReturnValue = -5;
}
}
else {
DPRINTK("Timer selection wrong\n");
i_ReturnValue = -3;
}
} else {
DPRINTK("The module is not a TIMER module\n");
i_ReturnValue = -4;
}
} else {
DPRINTK("Module number error\n");
i_ReturnValue = -2;
}
return i_ReturnValue;
}
int i_APCI1710_InsnBitsTimer(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
unsigned char b_BitsType;
int i_ReturnValue = 0;
b_BitsType = data[0];
printk("\n82X54");
switch (b_BitsType) {
case APCI1710_TIMER_READVALUE:
i_ReturnValue = i_APCI1710_ReadTimerValue(dev,
(unsigned char)CR_AREF(insn->chanspec),
(unsigned char)CR_CHAN(insn->chanspec),
(unsigned int *) &data[0]);
break;
case APCI1710_TIMER_GETOUTPUTLEVEL:
i_ReturnValue = i_APCI1710_GetTimerOutputLevel(dev,
(unsigned char)CR_AREF(insn->chanspec),
(unsigned char)CR_CHAN(insn->chanspec),
(unsigned char *) &data[0]);
break;
case APCI1710_TIMER_GETPROGRESSSTATUS:
i_ReturnValue = i_APCI1710_GetTimerProgressStatus(dev,
(unsigned char)CR_AREF(insn->chanspec),
(unsigned char)CR_CHAN(insn->chanspec),
(unsigned char *)&data[0]);
break;
case APCI1710_TIMER_WRITEVALUE:
i_ReturnValue = i_APCI1710_WriteTimerValue(dev,
(unsigned char)CR_AREF(insn->chanspec),
(unsigned char)CR_CHAN(insn->chanspec),
(unsigned int)data[1]);
break;
default:
printk("Bits Config Parameter Wrong\n");
i_ReturnValue = -1;
}
if (i_ReturnValue >= 0)
i_ReturnValue = insn->n;
return i_ReturnValue;
}
int i_APCI1710_ReadTimerValue(struct comedi_device *dev,
unsigned char b_ModulNbr, unsigned char b_TimerNbr,
unsigned int *pul_TimerValue)
{
int i_ReturnValue = 0;
if (b_ModulNbr < 4) {
if ((devpriv->s_BoardInfos.
dw_MolduleConfiguration[b_ModulNbr] &
0xFFFF0000UL) == APCI1710_82X54_TIMER) {
if (b_TimerNbr <= 2) {
if (devpriv->
s_ModuleInfo[b_ModulNbr].
s_82X54ModuleInfo.
s_82X54TimerInfo[b_TimerNbr].
b_82X54Init == 1) {
outl((2 << b_TimerNbr) | 0xD0,
devpriv->s_BoardInfos.
ui_Address + 12 +
(64 * b_ModulNbr));
*pul_TimerValue =
inl(devpriv->s_BoardInfos.
ui_Address + (b_TimerNbr * 4) +
(64 * b_ModulNbr));
} else {
DPRINTK("Timer not initialised see function\n");
i_ReturnValue = -5;
}
} else {
DPRINTK("Timer selection wrong\n");
i_ReturnValue = -3;
}
} else {
DPRINTK("The module is not a TIMER module\n");
i_ReturnValue = -4;
}
} else {
DPRINTK("Module number error\n");
i_ReturnValue = -2;
}
return i_ReturnValue;
}
int i_APCI1710_GetTimerOutputLevel(struct comedi_device *dev,
unsigned char b_ModulNbr, unsigned char b_TimerNbr,
unsigned char *pb_OutputLevel)
{
int i_ReturnValue = 0;
unsigned int dw_TimerStatus;
if (b_ModulNbr < 4) {
if ((devpriv->s_BoardInfos.dw_MolduleConfiguration[b_ModulNbr] & 0xFFFF0000UL) == APCI1710_82X54_TIMER) {
if (b_TimerNbr <= 2) {
if (devpriv->s_ModuleInfo[b_ModulNbr].s_82X54ModuleInfo.s_82X54TimerInfo[b_TimerNbr].b_82X54Init == 1) {
outl((2 << b_TimerNbr) | 0xE0, devpriv->s_BoardInfos.ui_Address + 12 + (64 * b_ModulNbr));
dw_TimerStatus = inl(devpriv->s_BoardInfos.ui_Address + 16 + (b_TimerNbr * 4) + (64 * b_ModulNbr));
*pb_OutputLevel = (unsigned char) (((dw_TimerStatus >> 7) & 1) ^ devpriv-> s_ModuleInfo[b_ModulNbr].s_82X54ModuleInfo.s_82X54TimerInfo[b_TimerNbr].b_OutputLevel);
} else {
DPRINTK("Timer not initialised see function\n");
i_ReturnValue = -5;
}
} else {
DPRINTK("Timer selection wrong\n");
i_ReturnValue = -3;
}
} else {
DPRINTK("The module is not a TIMER module\n");
i_ReturnValue = -4;
}
} else {
DPRINTK("Module number error\n");
i_ReturnValue = -2;
}
return i_ReturnValue;
}
int i_APCI1710_GetTimerProgressStatus(struct comedi_device *dev,
unsigned char b_ModulNbr, unsigned char b_TimerNbr,
unsigned char *pb_TimerStatus)
{
int i_ReturnValue = 0;
unsigned int dw_TimerStatus;
if (b_ModulNbr < 4) {
if ((devpriv->s_BoardInfos.dw_MolduleConfiguration[b_ModulNbr] & 0xFFFF0000UL) == APCI1710_82X54_TIMER) {
if (b_TimerNbr <= 2) {
if (devpriv->s_ModuleInfo[b_ModulNbr].s_82X54ModuleInfo.s_82X54TimerInfo[b_TimerNbr].b_82X54Init == 1) {
outl((2 << b_TimerNbr) | 0xE0, devpriv->s_BoardInfos.ui_Address + 12 + (64 * b_ModulNbr));
dw_TimerStatus = inl(devpriv->s_BoardInfos.ui_Address + 16 + (b_TimerNbr * 4) + (64 * b_ModulNbr));
*pb_TimerStatus = (unsigned char) ((dw_TimerStatus) >> 8) & 1;
printk("ProgressStatus : %d", *pb_TimerStatus);
} else {
i_ReturnValue = -5;
}
} else {
i_ReturnValue = -3;
}
} else {
i_ReturnValue = -4;
}
} else {
i_ReturnValue = -2;
}
return i_ReturnValue;
}
int i_APCI1710_WriteTimerValue(struct comedi_device *dev,
unsigned char b_ModulNbr, unsigned char b_TimerNbr,
unsigned int ul_WriteValue)
{
int i_ReturnValue = 0;
if (b_ModulNbr < 4) {
if ((devpriv->s_BoardInfos.dw_MolduleConfiguration[b_ModulNbr] & 0xFFFF0000UL) == APCI1710_82X54_TIMER) {
if (b_TimerNbr <= 2) {
if (devpriv->s_ModuleInfo[b_ModulNbr].s_82X54ModuleInfo.s_82X54TimerInfo[b_TimerNbr].b_82X54Init == 1) {
outl(ul_WriteValue, devpriv->s_BoardInfos.ui_Address + (b_TimerNbr * 4) + (64 * b_ModulNbr));
} else {
DPRINTK("Timer not initialised see function\n");
i_ReturnValue = -5;
}
} else {
DPRINTK("Timer selection wrong\n");
i_ReturnValue = -3;
}
} else {
DPRINTK("The module is not a TIMER module\n");
i_ReturnValue = -4;
}
} else {
DPRINTK("Module number error\n");
i_ReturnValue = -2;
}
return i_ReturnValue;
}
