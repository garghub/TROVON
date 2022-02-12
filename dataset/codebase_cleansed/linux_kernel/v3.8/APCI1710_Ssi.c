static int i_APCI1710_InsnConfigInitSSI(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
int i_ReturnValue = 0;
unsigned int ui_TimerValue;
unsigned char b_ModulNbr, b_SSIProfile, b_PositionTurnLength, b_TurnCptLength,
b_PCIInputClock, b_SSICountingMode;
unsigned int ul_SSIOutputClock;
b_ModulNbr = CR_AREF(insn->chanspec);
b_SSIProfile = (unsigned char) data[0];
b_PositionTurnLength = (unsigned char) data[1];
b_TurnCptLength = (unsigned char) data[2];
b_PCIInputClock = (unsigned char) data[3];
ul_SSIOutputClock = (unsigned int) data[4];
b_SSICountingMode = (unsigned char) data[5];
i_ReturnValue = insn->n;
if (b_ModulNbr < 4) {
if ((devpriv->s_BoardInfos.
dw_MolduleConfiguration[b_ModulNbr] &
0xFFFF0000UL) == APCI1710_SSI_COUNTER) {
if (b_SSIProfile >= 2 && b_SSIProfile < 33) {
if (b_PositionTurnLength > 0
&& b_PositionTurnLength < 32) {
if (b_TurnCptLength > 0
&& b_TurnCptLength < 32) {
if ((b_TurnCptLength +
b_PositionTurnLength)
<= b_SSIProfile) {
if (b_PCIInputClock ==
APCI1710_30MHZ
||
b_PCIInputClock
==
APCI1710_33MHZ)
{
if ((b_PCIInputClock == APCI1710_30MHZ && (ul_SSIOutputClock > 228 && ul_SSIOutputClock <= 5000000UL)) || (b_PCIInputClock == APCI1710_33MHZ && (ul_SSIOutputClock > 251 && ul_SSIOutputClock <= 5000000UL))) {
if (b_SSICountingMode == APCI1710_BINARY_MODE || b_SSICountingMode == APCI1710_GRAY_MODE) {
devpriv->
s_ModuleInfo
[b_ModulNbr].
s_SSICounterInfo.
b_SSIProfile
=
b_SSIProfile;
devpriv->
s_ModuleInfo
[b_ModulNbr].
s_SSICounterInfo.
b_PositionTurnLength
=
b_PositionTurnLength;
devpriv->
s_ModuleInfo
[b_ModulNbr].
s_SSICounterInfo.
b_TurnCptLength
=
b_TurnCptLength;
if (b_SSICountingMode == APCI1710_BINARY_MODE) {
outl(b_SSIProfile + 1, devpriv->s_BoardInfos.ui_Address + 4 + (64 * b_ModulNbr));
} else {
outl(b_SSIProfile, devpriv->s_BoardInfos.ui_Address + 4 + (64 * b_ModulNbr));
}
ui_TimerValue
=
(unsigned int)
(
((unsigned int) (b_PCIInputClock) * 500000UL) / ul_SSIOutputClock);
outl(ui_TimerValue, devpriv->s_BoardInfos.ui_Address + (64 * b_ModulNbr));
outl(7 * b_SSICountingMode, devpriv->s_BoardInfos.ui_Address + 12 + (64 * b_ModulNbr));
devpriv->
s_ModuleInfo
[b_ModulNbr].
s_SSICounterInfo.
b_SSIInit
=
1;
} else {
DPRINTK("The selected SSI counting mode parameter is wrong\n");
i_ReturnValue
=
-9;
}
} else {
DPRINTK("The selected SSI output clock is wrong\n");
i_ReturnValue
=
-8;
}
} else {
DPRINTK("The selected PCI input clock is wrong\n");
i_ReturnValue =
-7;
}
} else {
DPRINTK("The selected SSI profile length is wrong\n");
i_ReturnValue = -4;
}
} else {
DPRINTK("The selected SSI turn counter data length is wrong\n");
i_ReturnValue = -6;
}
} else {
DPRINTK("The selected SSI position data length is wrong\n");
i_ReturnValue = -5;
}
} else {
DPRINTK("The selected SSI profile length is wrong\n");
i_ReturnValue = -4;
}
} else {
DPRINTK("The module is not a SSI module\n");
i_ReturnValue = -3;
}
} else {
DPRINTK("Module number error\n");
i_ReturnValue = -2;
}
return i_ReturnValue;
}
static int i_APCI1710_InsnReadSSIValue(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
int i_ReturnValue = 0;
unsigned char b_Cpt;
unsigned char b_Length;
unsigned char b_Schift;
unsigned char b_SSICpt;
unsigned int dw_And;
unsigned int dw_And1;
unsigned int dw_And2;
unsigned int dw_StatusReg;
unsigned int dw_CounterValue;
unsigned char b_ModulNbr;
unsigned char b_SelectedSSI;
unsigned char b_ReadType;
unsigned int *pul_Position;
unsigned int *pul_TurnCpt;
unsigned int *pul_Position1;
unsigned int *pul_TurnCpt1;
i_ReturnValue = insn->n;
pul_Position1 = (unsigned int *) &data[0];
pul_TurnCpt1 = (unsigned int *) &data[1];
pul_Position = (unsigned int *) &data[0];
pul_TurnCpt = (unsigned int *) &data[3];
b_ModulNbr = (unsigned char) CR_AREF(insn->chanspec);
b_SelectedSSI = (unsigned char) CR_CHAN(insn->chanspec);
b_ReadType = (unsigned char) CR_RANGE(insn->chanspec);
if (b_ModulNbr < 4) {
if ((devpriv->s_BoardInfos.
dw_MolduleConfiguration[b_ModulNbr] &
0xFFFF0000UL) == APCI1710_SSI_COUNTER) {
if (devpriv->s_ModuleInfo[b_ModulNbr].
s_SSICounterInfo.b_SSIInit == 1) {
switch (b_ReadType) {
case APCI1710_SSI_READ1VALUE:
if (b_SelectedSSI < 3) {
outl(0, devpriv->s_BoardInfos.
ui_Address + 8 +
(64 * b_ModulNbr));
do {
dw_StatusReg =
inl(devpriv->
s_BoardInfos.
ui_Address +
(64 * b_ModulNbr));
} while ((dw_StatusReg & 0x1)
!= 0);
dw_CounterValue =
inl(devpriv->
s_BoardInfos.
ui_Address + 4 +
(b_SelectedSSI * 4) +
(64 * b_ModulNbr));
b_Length =
devpriv->
s_ModuleInfo
[b_ModulNbr].
s_SSICounterInfo.
b_SSIProfile / 2;
if ((b_Length * 2) !=
devpriv->
s_ModuleInfo
[b_ModulNbr].
s_SSICounterInfo.
b_SSIProfile) {
b_Length++;
}
b_Schift =
b_Length -
devpriv->
s_ModuleInfo
[b_ModulNbr].
s_SSICounterInfo.
b_PositionTurnLength;
*pul_Position1 =
dw_CounterValue >>
b_Schift;
dw_And = 1;
for (b_Cpt = 0;
b_Cpt <
devpriv->
s_ModuleInfo
[b_ModulNbr].
s_SSICounterInfo.
b_PositionTurnLength;
b_Cpt++) {
dw_And = dw_And * 2;
}
*pul_Position1 =
*pul_Position1 &
((dw_And) - 1);
*pul_TurnCpt1 =
dw_CounterValue >>
b_Length;
dw_And = 1;
for (b_Cpt = 0;
b_Cpt <
devpriv->
s_ModuleInfo
[b_ModulNbr].
s_SSICounterInfo.
b_TurnCptLength;
b_Cpt++) {
dw_And = dw_And * 2;
}
*pul_TurnCpt1 =
*pul_TurnCpt1 &
((dw_And) - 1);
} else {
DPRINTK("The selected SSI is wrong\n");
i_ReturnValue = -5;
}
break;
case APCI1710_SSI_READALLVALUE:
dw_And1 = 1;
for (b_Cpt = 0;
b_Cpt <
devpriv->
s_ModuleInfo[b_ModulNbr].
s_SSICounterInfo.
b_PositionTurnLength; b_Cpt++) {
dw_And1 = dw_And1 * 2;
}
dw_And2 = 1;
for (b_Cpt = 0;
b_Cpt <
devpriv->
s_ModuleInfo[b_ModulNbr].
s_SSICounterInfo.
b_TurnCptLength; b_Cpt++) {
dw_And2 = dw_And2 * 2;
}
outl(0, devpriv->s_BoardInfos.
ui_Address + 8 +
(64 * b_ModulNbr));
do {
dw_StatusReg =
inl(devpriv->
s_BoardInfos.
ui_Address +
(64 * b_ModulNbr));
} while ((dw_StatusReg & 0x1) != 0);
for (b_SSICpt = 0; b_SSICpt < 3;
b_SSICpt++) {
dw_CounterValue =
inl(devpriv->
s_BoardInfos.
ui_Address + 4 +
(b_SSICpt * 4) +
(64 * b_ModulNbr));
b_Length =
devpriv->
s_ModuleInfo
[b_ModulNbr].
s_SSICounterInfo.
b_SSIProfile / 2;
if ((b_Length * 2) !=
devpriv->
s_ModuleInfo
[b_ModulNbr].
s_SSICounterInfo.
b_SSIProfile) {
b_Length++;
}
b_Schift =
b_Length -
devpriv->
s_ModuleInfo
[b_ModulNbr].
s_SSICounterInfo.
b_PositionTurnLength;
pul_Position[b_SSICpt] =
dw_CounterValue >>
b_Schift;
pul_Position[b_SSICpt] =
pul_Position[b_SSICpt] &
((dw_And1) - 1);
pul_TurnCpt[b_SSICpt] =
dw_CounterValue >>
b_Length;
pul_TurnCpt[b_SSICpt] =
pul_TurnCpt[b_SSICpt] &
((dw_And2) - 1);
}
break;
default:
printk("Read Type Inputs Wrong\n");
}
} else {
DPRINTK("SSI not initialised\n");
i_ReturnValue = -4;
}
} else {
DPRINTK("The module is not a SSI module\n");
i_ReturnValue = -3;
}
} else {
DPRINTK("Module number error\n");
i_ReturnValue = -2;
}
return i_ReturnValue;
}
static int i_APCI1710_InsnBitsSSIDigitalIO(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
int i_ReturnValue = 0;
unsigned int dw_StatusReg;
unsigned char b_ModulNbr;
unsigned char b_InputChannel;
unsigned char *pb_ChannelStatus;
unsigned char *pb_InputStatus;
unsigned char b_IOType;
i_ReturnValue = insn->n;
b_ModulNbr = (unsigned char) CR_AREF(insn->chanspec);
b_IOType = (unsigned char) data[0];
if (b_ModulNbr < 4) {
if ((devpriv->s_BoardInfos.
dw_MolduleConfiguration[b_ModulNbr] &
0xFFFF0000UL) == APCI1710_SSI_COUNTER) {
switch (b_IOType) {
case APCI1710_SSI_SET_CHANNELON:
outl(1, devpriv->s_BoardInfos.ui_Address + 16 +
(64 * b_ModulNbr));
break;
case APCI1710_SSI_SET_CHANNELOFF:
outl(0, devpriv->s_BoardInfos.ui_Address + 16 +
(64 * b_ModulNbr));
break;
case APCI1710_SSI_READ_1CHANNEL:
b_InputChannel = (unsigned char) CR_CHAN(insn->chanspec);
pb_ChannelStatus = (unsigned char *) &data[0];
if (b_InputChannel <= 2) {
dw_StatusReg =
inl(devpriv->s_BoardInfos.
ui_Address + (64 * b_ModulNbr));
*pb_ChannelStatus =
(unsigned char) (((~dw_StatusReg) >> (4 +
b_InputChannel))
& 1);
} else {
DPRINTK("Selected digital input error\n");
i_ReturnValue = -4;
}
break;
case APCI1710_SSI_READ_ALLCHANNEL:
pb_InputStatus = (unsigned char *) &data[0];
dw_StatusReg =
inl(devpriv->s_BoardInfos.ui_Address +
(64 * b_ModulNbr));
*pb_InputStatus =
(unsigned char) (((~dw_StatusReg) >> 4) & 7);
break;
default:
printk("IO type wrong\n");
}
} else {
DPRINTK("The module is not a SSI module\n");
i_ReturnValue = -3;
}
} else {
DPRINTK("Module number error\n");
i_ReturnValue = -2;
}
return i_ReturnValue;
}
