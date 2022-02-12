int i_APCI1710_InsnConfigInitTTLIO(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i_ReturnValue = 0;
unsigned char b_ModulNbr;
unsigned char b_InitType;
unsigned char b_PortAMode;
unsigned char b_PortBMode;
unsigned char b_PortCMode;
unsigned char b_PortDMode;
b_ModulNbr = (unsigned char) CR_AREF(insn->chanspec);
b_InitType = (unsigned char) data[0];
i_ReturnValue = insn->n;
if (b_ModulNbr < 4) {
if ((devpriv->s_BoardInfos.
dw_MolduleConfiguration[b_ModulNbr] &
0xFFFF0000UL) == APCI1710_TTL_IO) {
switch (b_InitType) {
case APCI1710_TTL_INIT:
devpriv->s_ModuleInfo[b_ModulNbr].
s_TTLIOInfo.b_TTLInit = 1;
devpriv->s_ModuleInfo[b_ModulNbr].
s_TTLIOInfo.b_PortConfiguration[0] = 0;
devpriv->s_ModuleInfo[b_ModulNbr].
s_TTLIOInfo.b_PortConfiguration[1] = 0;
devpriv->s_ModuleInfo[b_ModulNbr].
s_TTLIOInfo.b_PortConfiguration[2] = 0;
devpriv->s_ModuleInfo[b_ModulNbr].
s_TTLIOInfo.b_PortConfiguration[3] = 1;
outl(0x8,
devpriv->s_BoardInfos.ui_Address + 20 +
(64 * b_ModulNbr));
break;
case APCI1710_TTL_INITDIRECTION:
b_PortAMode = (unsigned char) data[1];
b_PortBMode = (unsigned char) data[2];
b_PortCMode = (unsigned char) data[3];
b_PortDMode = (unsigned char) data[4];
if ((devpriv->s_BoardInfos.
dw_MolduleConfiguration
[b_ModulNbr] & 0xFFFF) >=
0x3230) {
if ((b_PortAMode == 0)
|| (b_PortAMode == 1)) {
if ((b_PortBMode == 0)
|| (b_PortBMode == 1)) {
if ((b_PortCMode == 0)
|| (b_PortCMode
== 1)) {
if ((b_PortDMode == 0) || (b_PortDMode == 1)) {
devpriv->
s_ModuleInfo
[b_ModulNbr].
s_TTLIOInfo.
b_TTLInit
=
1;
devpriv->
s_ModuleInfo
[b_ModulNbr].
s_TTLIOInfo.
b_PortConfiguration
[0]
=
b_PortAMode;
devpriv->
s_ModuleInfo
[b_ModulNbr].
s_TTLIOInfo.
b_PortConfiguration
[1]
=
b_PortBMode;
devpriv->
s_ModuleInfo
[b_ModulNbr].
s_TTLIOInfo.
b_PortConfiguration
[2]
=
b_PortCMode;
devpriv->
s_ModuleInfo
[b_ModulNbr].
s_TTLIOInfo.
b_PortConfiguration
[3]
=
b_PortDMode;
outl((b_PortAMode << 0) | (b_PortBMode << 1) | (b_PortCMode << 2) | (b_PortDMode << 3), devpriv->s_BoardInfos.ui_Address + 20 + (64 * b_ModulNbr));
} else {
DPRINTK("Port D mode selection is wrong\n");
i_ReturnValue
=
-8;
}
} else {
DPRINTK("Port C mode selection is wrong\n");
i_ReturnValue =
-7;
}
} else {
DPRINTK("Port B mode selection is wrong\n");
i_ReturnValue = -6;
}
} else {
DPRINTK("Port A mode selection is wrong\n");
i_ReturnValue = -5;
}
} else {
DPRINTK("Function not available for this version\n");
i_ReturnValue = -4;
}
break;
DPRINTK("\n");
default:
printk("Bad Config Type\n");
}
} else {
DPRINTK("The module is not a TTL module\n");
i_ReturnValue = -3;
}
} else {
DPRINTK("Module number error\n");
i_ReturnValue = -2;
}
return i_ReturnValue;
}
int i_APCI1710_InsnBitsReadTTLIO(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i_ReturnValue = 0;
unsigned int dw_StatusReg;
unsigned char b_ModulNbr;
unsigned char b_SelectedPort;
unsigned char b_InputChannel;
unsigned char b_ReadType;
unsigned char *pb_ChannelStatus;
unsigned char *pb_PortValue;
i_ReturnValue = insn->n;
b_ReadType = (unsigned char) data[0];
b_ModulNbr = CR_AREF(insn->chanspec);
b_SelectedPort = CR_RANGE(insn->chanspec);
b_InputChannel = CR_CHAN(insn->chanspec);
if (b_ModulNbr < 4) {
if ((devpriv->s_BoardInfos.
dw_MolduleConfiguration[b_ModulNbr] &
0xFFFF0000UL) == APCI1710_TTL_IO) {
switch (b_ReadType) {
case APCI1710_TTL_READCHANNEL:
pb_ChannelStatus = (unsigned char *) &data[0];
if (((b_SelectedPort <= 2)
&& ((devpriv->s_BoardInfos.
dw_MolduleConfiguration
[b_ModulNbr] &
0xFFFF) ==
0x3130))
|| ((b_SelectedPort <= 3)
&& ((devpriv->s_BoardInfos.
dw_MolduleConfiguration
[b_ModulNbr] &
0xFFFF) >=
0x3230))) {
if (((b_InputChannel <= 7)
&& (b_SelectedPort < 3))
|| ((b_InputChannel <= 1)
&& (b_SelectedPort ==
3))) {
if (devpriv->
s_ModuleInfo
[b_ModulNbr].
s_TTLIOInfo.b_TTLInit ==
1) {
if (((devpriv->s_BoardInfos.dw_MolduleConfiguration[b_ModulNbr] & 0xFFFF) == 0x3130) || (((devpriv->s_BoardInfos.dw_MolduleConfiguration[b_ModulNbr] & 0xFFFF) >= 0x3230) && (devpriv->s_ModuleInfo[b_ModulNbr].s_TTLIOInfo.b_PortConfiguration[b_SelectedPort] == 0))) {
dw_StatusReg =
inl
(devpriv->
s_BoardInfos.
ui_Address
+
(64 * b_ModulNbr));
*pb_ChannelStatus
=
(unsigned char) (
(dw_StatusReg
>>
(8 * b_SelectedPort)) >> b_InputChannel) & 1;
} else {
DPRINTK("Selected TTL I/O port error\n");
i_ReturnValue =
-4;
}
} else {
DPRINTK("TTL I/O not initialised\n");
i_ReturnValue = -6;
}
} else {
DPRINTK("Selected digital input error\n");
i_ReturnValue = -5;
}
} else {
DPRINTK("Selected TTL I/O port error\n");
i_ReturnValue = -4;
}
break;
case APCI1710_TTL_READPORT:
pb_PortValue = (unsigned char *) &data[0];
if (((b_SelectedPort <= 2)
&& ((devpriv->s_BoardInfos.
dw_MolduleConfiguration
[b_ModulNbr] &
0xFFFF) ==
0x3130))
|| ((b_SelectedPort <= 3)
&& ((devpriv->s_BoardInfos.
dw_MolduleConfiguration
[b_ModulNbr] &
0xFFFF) >=
0x3230))) {
if (devpriv->s_ModuleInfo[b_ModulNbr].
s_TTLIOInfo.b_TTLInit == 1) {
if (((devpriv->s_BoardInfos.
dw_MolduleConfiguration
[b_ModulNbr]
&
0xFFFF)
== 0x3130)
|| (((devpriv->s_BoardInfos.dw_MolduleConfiguration[b_ModulNbr] & 0xFFFF) >= 0x3230) && (devpriv->s_ModuleInfo[b_ModulNbr].s_TTLIOInfo.b_PortConfiguration[b_SelectedPort] == 0))) {
dw_StatusReg =
inl(devpriv->
s_BoardInfos.
ui_Address +
(64 * b_ModulNbr));
*pb_PortValue =
(unsigned char) (
(dw_StatusReg >>
(8 * b_SelectedPort)) & 0xFF);
} else {
DPRINTK("Selected TTL I/O port error\n");
i_ReturnValue = -4;
}
} else {
DPRINTK("TTL I/O not initialised\n");
i_ReturnValue = -5;
}
} else {
DPRINTK("Selected TTL I/O port error\n");
i_ReturnValue = -4;
}
break;
default:
printk("Bad ReadType\n");
}
} else {
DPRINTK("The module is not a TTL module\n");
i_ReturnValue = -3;
}
} else {
DPRINTK("Module number error\n");
i_ReturnValue = -2;
}
return i_ReturnValue;
}
int i_APCI1710_InsnReadTTLIOAllPortValue(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_insn *insn, unsigned int *data)
{
int i_ReturnValue = 0;
unsigned int dw_StatusReg;
unsigned char b_ModulNbr;
unsigned int *pul_PortValue;
b_ModulNbr = (unsigned char) CR_AREF(insn->chanspec);
i_ReturnValue = insn->n;
pul_PortValue = (unsigned int *) &data[0];
if (b_ModulNbr < 4) {
if ((devpriv->s_BoardInfos.
dw_MolduleConfiguration[b_ModulNbr] &
0xFFFF0000UL) == APCI1710_TTL_IO) {
if (devpriv->
s_ModuleInfo[b_ModulNbr].
s_TTLIOInfo.b_TTLInit == 1) {
dw_StatusReg = inl(devpriv->s_BoardInfos.
ui_Address + (64 * b_ModulNbr));
if ((devpriv->s_BoardInfos.
dw_MolduleConfiguration
[b_ModulNbr] & 0xFFFF) ==
0x3130) {
*pul_PortValue =
dw_StatusReg & 0xFFFFFFUL;
} else {
if (devpriv->s_ModuleInfo[b_ModulNbr].
s_TTLIOInfo.
b_PortConfiguration[0] == 1) {
*pul_PortValue =
dw_StatusReg &
0x3FFFF00UL;
}
if (devpriv->
s_ModuleInfo[b_ModulNbr].
s_TTLIOInfo.
b_PortConfiguration[1] == 1) {
*pul_PortValue =
dw_StatusReg &
0x3FF00FFUL;
}
if (devpriv->
s_ModuleInfo[b_ModulNbr].
s_TTLIOInfo.
b_PortConfiguration[2] == 1) {
*pul_PortValue =
dw_StatusReg &
0x300FFFFUL;
}
if (devpriv->
s_ModuleInfo[b_ModulNbr].
s_TTLIOInfo.
b_PortConfiguration[3] == 1) {
*pul_PortValue =
dw_StatusReg &
0xFFFFFFUL;
}
}
} else {
DPRINTK("TTL I/O not initialised\n");
i_ReturnValue = -5;
}
} else {
DPRINTK("The module is not a TTL module\n");
i_ReturnValue = -3;
}
} else {
DPRINTK("Module number error\n");
i_ReturnValue = -2;
}
return i_ReturnValue;
}
