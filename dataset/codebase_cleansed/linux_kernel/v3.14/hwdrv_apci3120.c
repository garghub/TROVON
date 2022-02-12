static int i_APCI3120_InsnConfigAnalogInput(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
const struct addi_board *this_board = comedi_board(dev);
struct addi_private *devpriv = dev->private;
unsigned int i;
if ((data[0] != APCI3120_EOC_MODE) && (data[0] != APCI3120_EOS_MODE))
return -1;
devpriv->ui_EocEosConversionTime = data[2];
if (data[0] == APCI3120_EOS_MODE) {
for (i = 0; i < data[3]; i++) {
if (CR_CHAN(data[4 + i]) >=
this_board->i_NbrAiChannel) {
printk("bad channel list\n");
return -2;
}
}
devpriv->b_InterruptMode = APCI3120_EOS_MODE;
if (data[1])
devpriv->b_EocEosInterrupt = APCI3120_ENABLE;
else
devpriv->b_EocEosInterrupt = APCI3120_DISABLE;
devpriv->ui_AiNbrofChannels = data[3];
for (i = 0; i < devpriv->ui_AiNbrofChannels; i++)
devpriv->ui_AiChannelList[i] = data[4 + i];
} else {
devpriv->b_InterruptMode = APCI3120_EOC_MODE;
if (data[1])
devpriv->b_EocEosInterrupt = APCI3120_ENABLE;
else
devpriv->b_EocEosInterrupt = APCI3120_DISABLE;
}
return insn->n;
}
static int i_APCI3120_SetupChannelList(struct comedi_device *dev,
struct comedi_subdevice *s,
int n_chan,
unsigned int *chanlist,
char check)
{
struct addi_private *devpriv = dev->private;
unsigned int i;
unsigned int gain;
unsigned short us_TmpValue;
if (n_chan < 1) {
if (!check)
comedi_error(dev, "range/channel list is empty!");
return 0;
}
if (check)
return 1;
devpriv->us_OutputRegister =
devpriv->us_OutputRegister & APCI3120_CLEAR_PA_PR;
devpriv->us_OutputRegister = ((n_chan - 1) & 0xf) << 8;
outw(devpriv->us_OutputRegister, dev->iobase + APCI3120_WR_ADDRESS);
for (i = 0; i < n_chan; i++) {
us_TmpValue = CR_CHAN(chanlist[i]);
if (CR_RANGE(chanlist[i]) < APCI3120_BIPOLAR_RANGES)
us_TmpValue &= ((~APCI3120_UNIPOLAR) & 0xff);
else
us_TmpValue |= APCI3120_UNIPOLAR;
gain = CR_RANGE(chanlist[i]);
us_TmpValue |= ((gain & 0x03) << 4);
us_TmpValue |= i << 8;
outw(us_TmpValue, dev->iobase + APCI3120_SEQ_RAM_ADDRESS);
printk("\n Gain = %i",
(((unsigned char)CR_RANGE(chanlist[i]) & 0x03) << 2));
printk("\n Channel = %i", CR_CHAN(chanlist[i]));
printk("\n Polarity = %i", us_TmpValue & APCI3120_UNIPOLAR);
}
return 1;
}
static int i_APCI3120_InsnReadAnalogInput(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
const struct addi_board *this_board = comedi_board(dev);
struct addi_private *devpriv = dev->private;
unsigned short us_ConvertTiming, us_TmpValue, i;
unsigned char b_Tmp;
if (!devpriv->ui_EocEosConversionTime) {
printk("No timer0 Value using 10 us\n");
us_ConvertTiming = 10;
} else
us_ConvertTiming = (unsigned short) (devpriv->ui_EocEosConversionTime / 1000);
devpriv->b_TimerSelectMode = 0;
devpriv->b_ModeSelectRegister = 0;
devpriv->us_OutputRegister = 0;
if (insn->unused[0] == 222) {
for (i = 0; i < insn->n; i++)
data[i] = devpriv->ui_AiReadData[i];
} else {
devpriv->tsk_Current = current;
us_TmpValue =
(unsigned short) inw(devpriv->iobase + APCI3120_RD_STATUS);
if ((us_TmpValue & 0x00B0) == 0x00B0
|| !strcmp(this_board->pc_DriverName, "apci3001")) {
us_ConvertTiming = (us_ConvertTiming * 2) - 2;
} else {
us_ConvertTiming =
((us_ConvertTiming * 12926) / 10000) - 1;
}
us_TmpValue = (unsigned short) devpriv->b_InterruptMode;
switch (us_TmpValue) {
case APCI3120_EOC_MODE:
inw(devpriv->iobase + APCI3120_RESET_FIFO);
if (!i_APCI3120_SetupChannelList(dev, s, 1,
&insn->chanspec, 0))
return -EINVAL;
devpriv->b_TimerSelectMode =
(devpriv->
b_TimerSelectMode & 0xFC) |
APCI3120_TIMER_0_MODE_4;
outb(devpriv->b_TimerSelectMode,
devpriv->iobase + APCI3120_TIMER_CRT1);
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister & APCI3120_DISABLE_SCAN;
if (devpriv->b_EocEosInterrupt == APCI3120_ENABLE) {
devpriv->b_ModeSelectRegister =
(devpriv->
b_ModeSelectRegister &
APCI3120_DISABLE_EOS_INT) |
APCI3120_ENABLE_EOC_INT;
inw(devpriv->iobase);
} else {
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister &
APCI3120_DISABLE_ALL_INTERRUPT_WITHOUT_TIMER;
}
outb(devpriv->b_ModeSelectRegister,
devpriv->iobase + APCI3120_WRITE_MODE_SELECT);
devpriv->us_OutputRegister =
(devpriv->
us_OutputRegister & APCI3120_CLEAR_PA_PR) |
APCI3120_ENABLE_TIMER0;
outw(devpriv->us_OutputRegister,
devpriv->iobase + APCI3120_WR_ADDRESS);
b_Tmp = ((devpriv->
b_DigitalOutputRegister) & 0xF0) |
APCI3120_SELECT_TIMER_0_WORD;
outb(b_Tmp, devpriv->iobase + APCI3120_TIMER_CRT0);
outw(us_ConvertTiming,
devpriv->iobase + APCI3120_TIMER_VALUE);
us_TmpValue =
(unsigned short) inw(dev->iobase + APCI3120_RD_STATUS);
if (devpriv->b_EocEosInterrupt == APCI3120_DISABLE) {
do {
us_TmpValue =
inw(devpriv->iobase +
APCI3120_RD_STATUS);
} while ((us_TmpValue & APCI3120_EOC) ==
APCI3120_EOC);
us_TmpValue = inw(devpriv->iobase + 0);
*data = us_TmpValue;
inw(devpriv->iobase + APCI3120_RESET_FIFO);
}
break;
case APCI3120_EOS_MODE:
inw(devpriv->iobase);
inw(devpriv->iobase + APCI3120_RESET_FIFO);
devpriv->us_OutputRegister =
(devpriv->
us_OutputRegister & APCI3120_CLEAR_PA_PR) |
APCI3120_DISABLE_TIMER0;
outw(devpriv->us_OutputRegister,
devpriv->iobase + APCI3120_WR_ADDRESS);
if (!i_APCI3120_SetupChannelList(dev, s,
devpriv->ui_AiNbrofChannels,
devpriv->ui_AiChannelList, 0))
return -EINVAL;
devpriv->b_TimerSelectMode =
(devpriv->
b_TimerSelectMode & 0xFC) |
APCI3120_TIMER_0_MODE_2;
outb(devpriv->b_TimerSelectMode,
devpriv->iobase + APCI3120_TIMER_CRT1);
b_Tmp = ((devpriv->
b_DigitalOutputRegister) & 0xF0) |
APCI3120_SELECT_TIMER_0_WORD;
outb(b_Tmp, devpriv->iobase + APCI3120_TIMER_CRT0);
outw(us_ConvertTiming,
devpriv->iobase + APCI3120_TIMER_VALUE);
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister | APCI3120_ENABLE_SCAN;
outb(devpriv->b_ModeSelectRegister,
devpriv->iobase + APCI3120_WRITE_MODE_SELECT);
if (devpriv->b_EocEosInterrupt == APCI3120_ENABLE) {
devpriv->b_ModeSelectRegister =
(devpriv->
b_ModeSelectRegister &
APCI3120_DISABLE_EOC_INT) |
APCI3120_ENABLE_EOS_INT;
inw(devpriv->iobase);
} else
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister &
APCI3120_DISABLE_ALL_INTERRUPT_WITHOUT_TIMER;
outb(devpriv->b_ModeSelectRegister,
devpriv->iobase + APCI3120_WRITE_MODE_SELECT);
inw(devpriv->iobase + APCI3120_RD_STATUS);
devpriv->us_OutputRegister =
devpriv->
us_OutputRegister | APCI3120_ENABLE_TIMER0;
outw(devpriv->us_OutputRegister,
devpriv->iobase + APCI3120_WR_ADDRESS);
outw(0, devpriv->iobase + APCI3120_START_CONVERSION);
if (devpriv->b_EocEosInterrupt == APCI3120_DISABLE) {
do {
us_TmpValue =
inw(devpriv->iobase +
APCI3120_RD_STATUS);
} while ((us_TmpValue & APCI3120_EOS) !=
APCI3120_EOS);
for (i = 0; i < devpriv->ui_AiNbrofChannels;
i++) {
us_TmpValue = inw(devpriv->iobase);
data[i] = (unsigned int) us_TmpValue;
}
devpriv->b_InterruptMode = APCI3120_EOC_MODE;
}
break;
default:
printk("inputs wrong\n");
}
devpriv->ui_EocEosConversionTime = 0;
}
return insn->n;
}
static int i_APCI3120_Reset(struct comedi_device *dev)
{
struct addi_private *devpriv = dev->private;
unsigned int i;
unsigned short us_TmpValue;
devpriv->b_AiCyclicAcquisition = APCI3120_DISABLE;
devpriv->b_EocEosInterrupt = APCI3120_DISABLE;
devpriv->b_InterruptMode = APCI3120_EOC_MODE;
devpriv->ui_EocEosConversionTime = 0;
devpriv->b_OutputMemoryStatus = 0;
devpriv->b_Timer2Mode = 0;
devpriv->b_Timer2Interrupt = 0;
devpriv->b_ExttrigEnable = 0;
devpriv->b_ModeSelectRegister = 0;
outb(devpriv->b_ModeSelectRegister,
dev->iobase + APCI3120_WRITE_MODE_SELECT);
devpriv->us_OutputRegister = 0;
outw(devpriv->us_OutputRegister, dev->iobase + APCI3120_WR_ADDRESS);
outw(8191 | APCI3120_ANALOG_OP_CHANNEL_1, dev->iobase + APCI3120_ANALOG_OUTPUT_1);
outw(8191 | APCI3120_ANALOG_OP_CHANNEL_2, dev->iobase + APCI3120_ANALOG_OUTPUT_1);
outw(8191 | APCI3120_ANALOG_OP_CHANNEL_3, dev->iobase + APCI3120_ANALOG_OUTPUT_1);
outw(8191 | APCI3120_ANALOG_OP_CHANNEL_4, dev->iobase + APCI3120_ANALOG_OUTPUT_1);
outw(8191 | APCI3120_ANALOG_OP_CHANNEL_5, dev->iobase + APCI3120_ANALOG_OUTPUT_2);
outw(8191 | APCI3120_ANALOG_OP_CHANNEL_6, dev->iobase + APCI3120_ANALOG_OUTPUT_2);
outw(8191 | APCI3120_ANALOG_OP_CHANNEL_7, dev->iobase + APCI3120_ANALOG_OUTPUT_2);
outw(8191 | APCI3120_ANALOG_OP_CHANNEL_8, dev->iobase + APCI3120_ANALOG_OUTPUT_2);
udelay(10);
inw(dev->iobase + 0);
inb(dev->iobase + APCI3120_RESET_FIFO);
inw(dev->iobase + APCI3120_RD_STATUS);
for (i = 0; i < 16; i++) {
us_TmpValue = i << 8;
outw(us_TmpValue, dev->iobase + APCI3120_SEQ_RAM_ADDRESS);
}
return 0;
}
static int i_APCI3120_ExttrigEnable(struct comedi_device *dev)
{
struct addi_private *devpriv = dev->private;
devpriv->us_OutputRegister |= APCI3120_ENABLE_EXT_TRIGGER;
outw(devpriv->us_OutputRegister, dev->iobase + APCI3120_WR_ADDRESS);
return 0;
}
static int i_APCI3120_ExttrigDisable(struct comedi_device *dev)
{
struct addi_private *devpriv = dev->private;
devpriv->us_OutputRegister &= ~APCI3120_ENABLE_EXT_TRIGGER;
outw(devpriv->us_OutputRegister, dev->iobase + APCI3120_WR_ADDRESS);
return 0;
}
static int i_APCI3120_StopCyclicAcquisition(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct addi_private *devpriv = dev->private;
outw(0, devpriv->i_IobaseAddon + 4);
outw(APCI3120_ADD_ON_AGCSTS_LOW, devpriv->i_IobaseAddon + 0);
outw(0, devpriv->i_IobaseAddon + 2);
outw(APCI3120_ADD_ON_AGCSTS_HIGH, devpriv->i_IobaseAddon + 0);
outw(0, devpriv->i_IobaseAddon + 2);
outl(0, devpriv->i_IobaseAmcc + AMCC_OP_REG_MCSR);
i_APCI3120_ExttrigDisable(dev);
devpriv->us_OutputRegister = 0;
outw(devpriv->
us_OutputRegister & APCI3120_DISABLE_TIMER0 &
APCI3120_DISABLE_TIMER1, dev->iobase + APCI3120_WR_ADDRESS);
outw(APCI3120_DISABLE_ALL_TIMER, dev->iobase + APCI3120_WR_ADDRESS);
outb(APCI3120_DISABLE_ALL_INTERRUPT,
dev->iobase + APCI3120_WRITE_MODE_SELECT);
inb(dev->iobase + APCI3120_RESET_FIFO);
inw(dev->iobase + APCI3120_RD_STATUS);
devpriv->ui_AiActualScan = 0;
s->async->cur_chan = 0;
devpriv->b_AiContinuous = 0;
devpriv->ui_DmaActualBuffer = 0;
devpriv->b_AiCyclicAcquisition = APCI3120_DISABLE;
devpriv->b_InterruptMode = APCI3120_EOC_MODE;
devpriv->b_EocEosInterrupt = APCI3120_DISABLE;
i_APCI3120_Reset(dev);
return 0;
}
static int i_APCI3120_CommandTestAnalogInput(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_cmd *cmd)
{
const struct addi_board *this_board = comedi_board(dev);
int err = 0;
err |= cfc_check_trigger_src(&cmd->start_src, TRIG_NOW | TRIG_EXT);
err |= cfc_check_trigger_src(&cmd->scan_begin_src,
TRIG_TIMER | TRIG_FOLLOW);
err |= cfc_check_trigger_src(&cmd->convert_src, TRIG_TIMER);
err |= cfc_check_trigger_src(&cmd->scan_end_src, TRIG_COUNT);
err |= cfc_check_trigger_src(&cmd->stop_src, TRIG_COUNT | TRIG_NONE);
if (err)
return 1;
err |= cfc_check_trigger_is_unique(cmd->start_src);
err |= cfc_check_trigger_is_unique(cmd->scan_begin_src);
err |= cfc_check_trigger_is_unique(cmd->stop_src);
if (err)
return 2;
err |= cfc_check_trigger_arg_is(&cmd->start_arg, 0);
if (cmd->scan_begin_src == TRIG_TIMER)
err |= cfc_check_trigger_arg_min(&cmd->scan_begin_arg, 100000);
if (cmd->convert_src == TRIG_TIMER) {
if (cmd->scan_begin_src == TRIG_TIMER) {
if (cmd->convert_arg)
err |= cfc_check_trigger_arg_min(
&cmd->convert_arg, 10000);
} else {
err |= cfc_check_trigger_arg_min(&cmd->convert_arg,
10000);
}
}
err |= cfc_check_trigger_arg_min(&cmd->chanlist_len, 1);
err |= cfc_check_trigger_arg_max(&cmd->chanlist_len,
this_board->i_AiChannelList);
if (cmd->stop_src == TRIG_COUNT)
err |= cfc_check_trigger_arg_min(&cmd->stop_arg, 1);
else
err |= cfc_check_trigger_arg_is(&cmd->stop_arg, 0);
if (err)
return 3;
if (cmd->convert_src == TRIG_TIMER) {
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
static int i_APCI3120_CyclicAnalogInput(int mode,
struct comedi_device *dev,
struct comedi_subdevice *s)
{
const struct addi_board *this_board = comedi_board(dev);
struct addi_private *devpriv = dev->private;
unsigned char b_Tmp;
unsigned int ui_Tmp, ui_DelayTiming = 0, ui_TimerValue1 = 0, dmalen0 =
0, dmalen1 = 0, ui_TimerValue2 =
0, ui_TimerValue0, ui_ConvertTiming;
unsigned short us_TmpValue;
inb(dev->iobase + APCI3120_RESET_FIFO);
devpriv->b_AiCyclicAcquisition = APCI3120_ENABLE;
devpriv->b_TimerSelectMode = 0;
devpriv->us_OutputRegister = 0;
devpriv->b_ModeSelectRegister = 0;
outl(APCI3120_CLEAR_WRITE_TC_INT,
devpriv->i_IobaseAmcc + APCI3120_AMCC_OP_REG_INTCSR);
devpriv->us_OutputRegister = devpriv->us_OutputRegister &
APCI3120_DISABLE_TIMER0 &
APCI3120_DISABLE_TIMER1 & APCI3120_CLEAR_PA_PR;
outw(devpriv->us_OutputRegister, dev->iobase + APCI3120_WR_ADDRESS);
inb(devpriv->iobase + APCI3120_RESET_FIFO);
devpriv->ui_AiActualScan = 0;
s->async->cur_chan = 0;
devpriv->ui_DmaActualBuffer = 0;
ui_TimerValue2 = devpriv->ui_AiNbrofScans - 2;
ui_ConvertTiming = devpriv->ui_AiTimer0;
if (mode == 2)
ui_DelayTiming = devpriv->ui_AiTimer1;
if (!i_APCI3120_SetupChannelList(dev, s, devpriv->ui_AiNbrofChannels,
devpriv->pui_AiChannelList, 0))
return -EINVAL;
us_TmpValue = (unsigned short) inw(dev->iobase + APCI3120_RD_STATUS);
if ((us_TmpValue & 0x00B0) == 0x00B0
|| !strcmp(this_board->pc_DriverName, "apci3001")) {
ui_TimerValue0 = ui_ConvertTiming * 2 - 2000;
ui_TimerValue0 = ui_TimerValue0 / 1000;
if (mode == 2) {
ui_DelayTiming = ui_DelayTiming / 1000;
ui_TimerValue1 = ui_DelayTiming * 2 - 200;
ui_TimerValue1 = ui_TimerValue1 / 100;
}
} else {
ui_ConvertTiming = ui_ConvertTiming / 1000;
ui_TimerValue0 = ui_ConvertTiming * 12926 - 10000;
ui_TimerValue0 = ui_TimerValue0 / 10000;
if (mode == 2) {
ui_DelayTiming = ui_DelayTiming / 1000;
ui_TimerValue1 = ui_DelayTiming * 12926 - 1;
ui_TimerValue1 = ui_TimerValue1 / 1000000;
}
}
if (devpriv->b_ExttrigEnable == APCI3120_ENABLE)
i_APCI3120_ExttrigEnable(dev);
switch (mode) {
case 1:
devpriv->b_TimerSelectMode =
(devpriv->
b_TimerSelectMode & 0xFC) | APCI3120_TIMER_0_MODE_2;
outb(devpriv->b_TimerSelectMode,
dev->iobase + APCI3120_TIMER_CRT1);
b_Tmp = ((devpriv->
b_DigitalOutputRegister) & 0xF0) |
APCI3120_SELECT_TIMER_0_WORD;
outb(b_Tmp, dev->iobase + APCI3120_TIMER_CRT0);
outw(((unsigned short) ui_TimerValue0),
dev->iobase + APCI3120_TIMER_VALUE);
break;
case 2:
devpriv->b_TimerSelectMode =
(devpriv->
b_TimerSelectMode & 0xF3) | APCI3120_TIMER_1_MODE_2;
outb(devpriv->b_TimerSelectMode,
dev->iobase + APCI3120_TIMER_CRT1);
b_Tmp = ((devpriv->
b_DigitalOutputRegister) & 0xF0) |
APCI3120_SELECT_TIMER_1_WORD;
outb(b_Tmp, dev->iobase + APCI3120_TIMER_CRT0);
outw(((unsigned short) ui_TimerValue1),
dev->iobase + APCI3120_TIMER_VALUE);
devpriv->b_TimerSelectMode =
(devpriv->
b_TimerSelectMode & 0xFC) | APCI3120_TIMER_0_MODE_2;
outb(devpriv->b_TimerSelectMode,
dev->iobase + APCI3120_TIMER_CRT1);
b_Tmp = ((devpriv->
b_DigitalOutputRegister) & 0xF0) |
APCI3120_SELECT_TIMER_0_WORD;
outb(b_Tmp, dev->iobase + APCI3120_TIMER_CRT0);
outw(((unsigned short) ui_TimerValue0),
dev->iobase + APCI3120_TIMER_VALUE);
break;
}
devpriv->b_ModeSelectRegister = devpriv->b_ModeSelectRegister &
APCI3120_DISABLE_SCAN;
outb(devpriv->b_ModeSelectRegister,
dev->iobase + APCI3120_WRITE_MODE_SELECT);
if (devpriv->us_UseDma == APCI3120_DISABLE) {
devpriv->b_InterruptMode = APCI3120_EOS_MODE;
devpriv->b_EocEosInterrupt = APCI3120_ENABLE;
devpriv->b_ModeSelectRegister =
(devpriv->
b_ModeSelectRegister & APCI3120_DISABLE_EOC_INT) |
APCI3120_ENABLE_EOS_INT;
outb(devpriv->b_ModeSelectRegister,
dev->iobase + APCI3120_WRITE_MODE_SELECT);
if (!devpriv->b_AiContinuous) {
devpriv->us_OutputRegister =
devpriv->
us_OutputRegister & APCI3120_DISABLE_TIMER2;
outw(devpriv->us_OutputRegister,
dev->iobase + APCI3120_WR_ADDRESS);
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister &
APCI3120_DISABLE_TIMER_INT & 0xEF;
outb(devpriv->b_ModeSelectRegister,
dev->iobase + APCI3120_WRITE_MODE_SELECT);
devpriv->b_TimerSelectMode =
(devpriv->
b_TimerSelectMode & 0x0F) |
APCI3120_TIMER_2_MODE_0;
outb(devpriv->b_TimerSelectMode,
dev->iobase + APCI3120_TIMER_CRT1);
b_Tmp = ((devpriv->
b_DigitalOutputRegister) & 0xF0) |
APCI3120_SELECT_TIMER_2_LOW_WORD;
outb(b_Tmp, dev->iobase + APCI3120_TIMER_CRT0);
outw(LOWORD(ui_TimerValue2),
dev->iobase + APCI3120_TIMER_VALUE);
b_Tmp = ((devpriv->
b_DigitalOutputRegister) & 0xF0) |
APCI3120_SELECT_TIMER_2_HIGH_WORD;
outb(b_Tmp, dev->iobase + APCI3120_TIMER_CRT0);
outw(HIWORD(ui_TimerValue2),
dev->iobase + APCI3120_TIMER_VALUE);
inb(dev->iobase + APCI3120_TIMER_STATUS_REGISTER);
devpriv->b_ModeSelectRegister =
(devpriv->
b_ModeSelectRegister |
APCI3120_ENABLE_TIMER_COUNTER) &
APCI3120_DISABLE_WATCHDOG;
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister |
APCI3120_TIMER2_SELECT_EOS;
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister |
APCI3120_ENABLE_TIMER_INT;
outb(devpriv->b_ModeSelectRegister,
dev->iobase + APCI3120_WRITE_MODE_SELECT);
devpriv->b_Timer2Mode = APCI3120_COUNTER;
devpriv->b_Timer2Interrupt = APCI3120_ENABLE;
}
} else {
devpriv->b_InterruptMode = APCI3120_DMA_MODE;
devpriv->b_ModeSelectRegister = devpriv->b_ModeSelectRegister &
APCI3120_DISABLE_EOC_INT & APCI3120_DISABLE_EOS_INT;
outb(devpriv->b_ModeSelectRegister,
dev->iobase + APCI3120_WRITE_MODE_SELECT);
dmalen0 = devpriv->ui_DmaBufferSize[0];
dmalen1 = devpriv->ui_DmaBufferSize[1];
if (!devpriv->b_AiContinuous) {
if (dmalen0 > (devpriv->ui_AiNbrofScans * devpriv->ui_AiScanLength * 2)) {
dmalen0 =
devpriv->ui_AiNbrofScans *
devpriv->ui_AiScanLength * 2;
} else if (dmalen1 > (devpriv->ui_AiNbrofScans * devpriv->ui_AiScanLength * 2 - dmalen0))
dmalen1 =
devpriv->ui_AiNbrofScans *
devpriv->ui_AiScanLength * 2 - dmalen0;
}
if (devpriv->ui_AiFlags & TRIG_WAKE_EOS) {
if (dmalen0 > (devpriv->ui_AiScanLength * 2)) {
dmalen0 = devpriv->ui_AiScanLength * 2;
if (devpriv->ui_AiScanLength & 1)
dmalen0 += 2;
}
if (dmalen1 > (devpriv->ui_AiScanLength * 2)) {
dmalen1 = devpriv->ui_AiScanLength * 2;
if (devpriv->ui_AiScanLength & 1)
dmalen1 -= 2;
if (dmalen1 < 4)
dmalen1 = 4;
}
} else {
if (dmalen0 > (devpriv->ui_AiDataLength))
dmalen0 = devpriv->ui_AiDataLength;
if (dmalen1 > (devpriv->ui_AiDataLength))
dmalen1 = devpriv->ui_AiDataLength;
}
devpriv->ui_DmaBufferUsesize[0] = dmalen0;
devpriv->ui_DmaBufferUsesize[1] = dmalen1;
ui_Tmp = AGCSTS_TC_ENABLE | AGCSTS_RESET_A2P_FIFO;
outl(ui_Tmp, devpriv->i_IobaseAmcc + AMCC_OP_REG_AGCSTS);
outw(APCI3120_ADD_ON_AGCSTS_LOW, devpriv->i_IobaseAddon + 0);
outw(APCI3120_ENABLE_TRANSFER_ADD_ON_LOW,
devpriv->i_IobaseAddon + 2);
outw(APCI3120_ADD_ON_AGCSTS_HIGH, devpriv->i_IobaseAddon + 0);
outw(APCI3120_ENABLE_TRANSFER_ADD_ON_HIGH,
devpriv->i_IobaseAddon + 2);
outw(0x1000, devpriv->i_IobaseAddon + 2);
outl(APCI3120_A2P_FIFO_MANAGEMENT, devpriv->i_IobaseAmcc +
APCI3120_AMCC_OP_MCSR);
outw(APCI3120_ADD_ON_MWAR_LOW, devpriv->i_IobaseAddon + 0);
outw((devpriv->ul_DmaBufferHw[0] & 0xFFFF),
devpriv->i_IobaseAddon + 2);
outw(APCI3120_ADD_ON_MWAR_HIGH, devpriv->i_IobaseAddon + 0);
outw((devpriv->ul_DmaBufferHw[0] / 65536),
devpriv->i_IobaseAddon + 2);
outw(APCI3120_ADD_ON_MWTC_LOW, devpriv->i_IobaseAddon + 0);
outw((devpriv->ui_DmaBufferUsesize[0] & 0xFFFF),
devpriv->i_IobaseAddon + 2);
outw(APCI3120_ADD_ON_MWTC_HIGH, devpriv->i_IobaseAddon + 0);
outw((devpriv->ui_DmaBufferUsesize[0] / 65536),
devpriv->i_IobaseAddon + 2);
outl(0x04000000UL, devpriv->i_IobaseAmcc + AMCC_OP_REG_MCSR);
outl((APCI3120_FIFO_ADVANCE_ON_BYTE_2 |
APCI3120_ENABLE_WRITE_TC_INT),
devpriv->i_IobaseAmcc + AMCC_OP_REG_INTCSR);
outw(3, devpriv->i_IobaseAddon + 4);
outl(0x04000000UL,
devpriv->i_IobaseAmcc + APCI3120_AMCC_OP_MCSR);
}
if ((devpriv->us_UseDma == APCI3120_DISABLE)
&& !devpriv->b_AiContinuous) {
devpriv->us_OutputRegister =
devpriv->us_OutputRegister | APCI3120_ENABLE_TIMER2;
outw(devpriv->us_OutputRegister,
dev->iobase + APCI3120_WR_ADDRESS);
}
switch (mode) {
case 1:
devpriv->us_OutputRegister =
devpriv->us_OutputRegister | APCI3120_ENABLE_TIMER0;
outw(devpriv->us_OutputRegister,
dev->iobase + APCI3120_WR_ADDRESS);
break;
case 2:
devpriv->us_OutputRegister =
devpriv->us_OutputRegister | APCI3120_ENABLE_TIMER1;
devpriv->us_OutputRegister =
devpriv->us_OutputRegister | APCI3120_ENABLE_TIMER0;
outw(devpriv->us_OutputRegister,
dev->iobase + APCI3120_WR_ADDRESS);
break;
}
return 0;
}
static int i_APCI3120_CommandAnalogInput(struct comedi_device *dev,
struct comedi_subdevice *s)
{
struct addi_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
devpriv->ui_AiFlags = cmd->flags;
devpriv->ui_AiNbrofChannels = cmd->chanlist_len;
devpriv->ui_AiScanLength = cmd->scan_end_arg;
devpriv->pui_AiChannelList = cmd->chanlist;
devpriv->ui_AiDataLength = s->async->prealloc_bufsz;
if (cmd->stop_src == TRIG_COUNT)
devpriv->ui_AiNbrofScans = cmd->stop_arg;
else
devpriv->ui_AiNbrofScans = 0;
devpriv->ui_AiTimer0 = 0;
devpriv->ui_AiTimer1 = 0;
if ((devpriv->ui_AiNbrofScans == 0) || (devpriv->ui_AiNbrofScans == -1))
devpriv->b_AiContinuous = 1;
if (cmd->start_src == TRIG_EXT)
devpriv->b_ExttrigEnable = APCI3120_ENABLE;
else
devpriv->b_ExttrigEnable = APCI3120_DISABLE;
if (cmd->scan_begin_src == TRIG_FOLLOW) {
if (cmd->convert_src == TRIG_TIMER) {
devpriv->ui_AiTimer0 = cmd->convert_arg;
return i_APCI3120_CyclicAnalogInput(1, dev, s);
}
}
if ((cmd->scan_begin_src == TRIG_TIMER)
&& (cmd->convert_src == TRIG_TIMER)) {
devpriv->ui_AiTimer1 = cmd->scan_begin_arg;
devpriv->ui_AiTimer0 = cmd->convert_arg;
return i_APCI3120_CyclicAnalogInput(2, dev, s);
}
return -1;
}
static void v_APCI3120_InterruptDmaMoveBlock16bit(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned short *dma_buffer,
unsigned int num_samples)
{
struct addi_private *devpriv = dev->private;
devpriv->ui_AiActualScan +=
(s->async->cur_chan + num_samples) / devpriv->ui_AiScanLength;
s->async->cur_chan += num_samples;
s->async->cur_chan %= devpriv->ui_AiScanLength;
cfc_write_array_to_buffer(s, dma_buffer, num_samples * sizeof(short));
}
static void v_APCI3120_InterruptDma(int irq, void *d)
{
struct comedi_device *dev = d;
struct addi_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
unsigned int next_dma_buf, samplesinbuf;
unsigned long low_word, high_word, var;
unsigned int ui_Tmp;
samplesinbuf =
devpriv->ui_DmaBufferUsesize[devpriv->ui_DmaActualBuffer] -
inl(devpriv->i_IobaseAmcc + AMCC_OP_REG_MWTC);
if (samplesinbuf <
devpriv->ui_DmaBufferUsesize[devpriv->ui_DmaActualBuffer]) {
comedi_error(dev, "Interrupted DMA transfer!");
}
if (samplesinbuf & 1) {
comedi_error(dev, "Odd count of bytes in DMA ring!");
i_APCI3120_StopCyclicAcquisition(dev, s);
devpriv->b_AiCyclicAcquisition = APCI3120_DISABLE;
return;
}
samplesinbuf = samplesinbuf >> 1;
if (devpriv->b_DmaDoubleBuffer) {
next_dma_buf = 1 - devpriv->ui_DmaActualBuffer;
ui_Tmp = AGCSTS_TC_ENABLE | AGCSTS_RESET_A2P_FIFO;
outl(ui_Tmp, devpriv->i_IobaseAddon + AMCC_OP_REG_AGCSTS);
outw(APCI3120_ADD_ON_AGCSTS_LOW, devpriv->i_IobaseAddon + 0);
outw(APCI3120_ENABLE_TRANSFER_ADD_ON_LOW,
devpriv->i_IobaseAddon + 2);
outw(APCI3120_ADD_ON_AGCSTS_HIGH, devpriv->i_IobaseAddon + 0);
outw(APCI3120_ENABLE_TRANSFER_ADD_ON_HIGH, devpriv->i_IobaseAddon + 2);
var = devpriv->ul_DmaBufferHw[next_dma_buf];
low_word = var & 0xffff;
var = devpriv->ul_DmaBufferHw[next_dma_buf];
high_word = var / 65536;
outw(APCI3120_ADD_ON_MWAR_LOW, devpriv->i_IobaseAddon + 0);
outw(low_word, devpriv->i_IobaseAddon + 2);
outw(APCI3120_ADD_ON_MWAR_HIGH, devpriv->i_IobaseAddon + 0);
outw(high_word, devpriv->i_IobaseAddon + 2);
var = devpriv->ui_DmaBufferUsesize[next_dma_buf];
low_word = var & 0xffff;
var = devpriv->ui_DmaBufferUsesize[next_dma_buf];
high_word = var / 65536;
outw(APCI3120_ADD_ON_MWTC_LOW, devpriv->i_IobaseAddon + 0);
outw(low_word, devpriv->i_IobaseAddon + 2);
outw(APCI3120_ADD_ON_MWTC_HIGH, devpriv->i_IobaseAddon + 0);
outw(high_word, devpriv->i_IobaseAddon + 2);
outw(3, devpriv->i_IobaseAddon + 4);
outl((APCI3120_FIFO_ADVANCE_ON_BYTE_2 |
APCI3120_ENABLE_WRITE_TC_INT),
devpriv->i_IobaseAmcc + AMCC_OP_REG_INTCSR);
}
if (samplesinbuf) {
v_APCI3120_InterruptDmaMoveBlock16bit(dev, s,
devpriv->ul_DmaBufferVirtual[devpriv->
ui_DmaActualBuffer], samplesinbuf);
if (!(devpriv->ui_AiFlags & TRIG_WAKE_EOS)) {
s->async->events |= COMEDI_CB_EOS;
comedi_event(dev, s);
}
}
if (!devpriv->b_AiContinuous)
if (devpriv->ui_AiActualScan >= devpriv->ui_AiNbrofScans) {
i_APCI3120_StopCyclicAcquisition(dev, s);
devpriv->b_AiCyclicAcquisition = APCI3120_DISABLE;
s->async->events |= COMEDI_CB_EOA;
comedi_event(dev, s);
return;
}
if (devpriv->b_DmaDoubleBuffer) {
devpriv->ui_DmaActualBuffer = 1 - devpriv->ui_DmaActualBuffer;
} else {
ui_Tmp = AGCSTS_TC_ENABLE | AGCSTS_RESET_A2P_FIFO;
outl(ui_Tmp, devpriv->i_IobaseAddon + AMCC_OP_REG_AGCSTS);
outw(APCI3120_ADD_ON_AGCSTS_LOW, devpriv->i_IobaseAddon + 0);
outw(APCI3120_ENABLE_TRANSFER_ADD_ON_LOW,
devpriv->i_IobaseAddon + 2);
outw(APCI3120_ADD_ON_AGCSTS_HIGH, devpriv->i_IobaseAddon + 0);
outw(APCI3120_ENABLE_TRANSFER_ADD_ON_HIGH, devpriv->i_IobaseAddon + 2);
outl(APCI3120_A2P_FIFO_MANAGEMENT,
devpriv->i_IobaseAmcc + AMCC_OP_REG_MCSR);
var = devpriv->ul_DmaBufferHw[0];
low_word = var & 0xffff;
var = devpriv->ul_DmaBufferHw[0];
high_word = var / 65536;
outw(APCI3120_ADD_ON_MWAR_LOW, devpriv->i_IobaseAddon + 0);
outw(low_word, devpriv->i_IobaseAddon + 2);
outw(APCI3120_ADD_ON_MWAR_HIGH, devpriv->i_IobaseAddon + 0);
outw(high_word, devpriv->i_IobaseAddon + 2);
var = devpriv->ui_DmaBufferUsesize[0];
low_word = var & 0xffff;
var = devpriv->ui_DmaBufferUsesize[0];
high_word = var / 65536;
outw(APCI3120_ADD_ON_MWTC_LOW, devpriv->i_IobaseAddon + 0);
outw(low_word, devpriv->i_IobaseAddon + 2);
outw(APCI3120_ADD_ON_MWTC_HIGH, devpriv->i_IobaseAddon + 0);
outw(high_word, devpriv->i_IobaseAddon + 2);
outw(3, devpriv->i_IobaseAddon + 4);
outl((APCI3120_FIFO_ADVANCE_ON_BYTE_2 |
APCI3120_ENABLE_WRITE_TC_INT),
devpriv->i_IobaseAmcc + AMCC_OP_REG_INTCSR);
}
}
static int i_APCI3120_InterruptHandleEos(struct comedi_device *dev)
{
struct addi_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
int n_chan, i;
int err = 1;
n_chan = devpriv->ui_AiNbrofChannels;
s->async->events = 0;
for (i = 0; i < n_chan; i++)
err &= comedi_buf_put(s->async, inw(dev->iobase + 0));
s->async->events |= COMEDI_CB_EOS;
if (err == 0)
s->async->events |= COMEDI_CB_OVERFLOW;
comedi_event(dev, s);
return 0;
}
static void v_APCI3120_Interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct addi_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
unsigned short int_daq;
unsigned int int_amcc, ui_Check, i;
unsigned short us_TmpValue;
unsigned char b_DummyRead;
ui_Check = 1;
int_daq = inw(dev->iobase + APCI3120_RD_STATUS) & 0xf000;
int_amcc = inl(devpriv->i_IobaseAmcc + AMCC_OP_REG_INTCSR);
if ((!int_daq) && (!(int_amcc & ANY_S593X_INT))) {
comedi_error(dev, "IRQ from unknown source");
return;
}
outl(int_amcc | 0x00ff0000, devpriv->i_IobaseAmcc + AMCC_OP_REG_INTCSR);
int_daq = (int_daq >> 12) & 0xF;
if (devpriv->b_ExttrigEnable == APCI3120_ENABLE) {
i_APCI3120_ExttrigDisable(dev);
devpriv->b_ExttrigEnable = APCI3120_DISABLE;
}
inb(devpriv->i_IobaseAmcc + APCI3120_TIMER_STATUS_REGISTER);
if (int_amcc & MASTER_ABORT_INT)
comedi_error(dev, "AMCC IRQ - MASTER DMA ABORT!");
if (int_amcc & TARGET_ABORT_INT)
comedi_error(dev, "AMCC IRQ - TARGET DMA ABORT!");
if (((int_daq & 0x8) == 0)
&& (devpriv->b_InterruptMode == APCI3120_EOC_MODE)) {
if (devpriv->b_EocEosInterrupt == APCI3120_ENABLE) {
devpriv->ui_AiReadData[0] =
(unsigned int) inw(devpriv->iobase + 0);
devpriv->b_EocEosInterrupt = APCI3120_DISABLE;
send_sig(SIGIO, devpriv->tsk_Current, 0);
} else {
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister & APCI3120_DISABLE_EOC_INT;
outb(devpriv->b_ModeSelectRegister,
devpriv->iobase + APCI3120_WRITE_MODE_SELECT);
}
}
if ((int_daq & 0x2) && (devpriv->b_InterruptMode == APCI3120_EOS_MODE)) {
if (devpriv->b_EocEosInterrupt == APCI3120_ENABLE) {
if (devpriv->b_AiCyclicAcquisition == APCI3120_ENABLE) {
ui_Check = 0;
i_APCI3120_InterruptHandleEos(dev);
devpriv->ui_AiActualScan++;
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister |
APCI3120_ENABLE_EOS_INT;
outb(devpriv->b_ModeSelectRegister,
dev->iobase +
APCI3120_WRITE_MODE_SELECT);
} else {
ui_Check = 0;
for (i = 0; i < devpriv->ui_AiNbrofChannels;
i++) {
us_TmpValue = inw(devpriv->iobase + 0);
devpriv->ui_AiReadData[i] =
(unsigned int) us_TmpValue;
}
devpriv->b_EocEosInterrupt = APCI3120_DISABLE;
devpriv->b_InterruptMode = APCI3120_EOC_MODE;
send_sig(SIGIO, devpriv->tsk_Current, 0);
}
} else {
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister & APCI3120_DISABLE_EOS_INT;
outb(devpriv->b_ModeSelectRegister,
dev->iobase + APCI3120_WRITE_MODE_SELECT);
devpriv->b_EocEosInterrupt = APCI3120_DISABLE;
devpriv->b_InterruptMode = APCI3120_EOC_MODE;
}
}
if (int_daq & 0x1) {
switch (devpriv->b_Timer2Mode) {
case APCI3120_COUNTER:
devpriv->b_AiCyclicAcquisition = APCI3120_DISABLE;
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister & APCI3120_DISABLE_EOS_INT;
outb(devpriv->b_ModeSelectRegister,
dev->iobase + APCI3120_WRITE_MODE_SELECT);
devpriv->us_OutputRegister =
devpriv->
us_OutputRegister & APCI3120_DISABLE_ALL_TIMER;
outw(devpriv->us_OutputRegister,
dev->iobase + APCI3120_WR_ADDRESS);
i_APCI3120_StopCyclicAcquisition(dev, s);
devpriv->b_AiCyclicAcquisition = APCI3120_DISABLE;
s->async->events |= COMEDI_CB_EOA;
comedi_event(dev, s);
break;
case APCI3120_TIMER:
send_sig(SIGIO, devpriv->tsk_Current, 0);
break;
case APCI3120_WATCHDOG:
send_sig(SIGIO, devpriv->tsk_Current, 0);
break;
default:
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister &
APCI3120_DISABLE_TIMER_INT;
outb(devpriv->b_ModeSelectRegister,
dev->iobase + APCI3120_WRITE_MODE_SELECT);
}
b_DummyRead = inb(dev->iobase + APCI3120_TIMER_STATUS_REGISTER);
}
if ((int_daq & 0x4) && (devpriv->b_InterruptMode == APCI3120_DMA_MODE)) {
if (devpriv->b_AiCyclicAcquisition == APCI3120_ENABLE) {
outl(APCI3120_CLEAR_WRITE_TC_INT,
devpriv->i_IobaseAmcc +
APCI3120_AMCC_OP_REG_INTCSR);
inw(dev->iobase + APCI3120_TIMER_STATUS_REGISTER);
v_APCI3120_InterruptDma(irq, d);
} else {
outw(devpriv->
us_OutputRegister & APCI3120_DISABLE_TIMER0 &
APCI3120_DISABLE_TIMER1,
dev->iobase + APCI3120_WR_ADDRESS);
}
}
return;
}
static int i_APCI3120_InsnConfigTimer(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
const struct addi_board *this_board = comedi_board(dev);
struct addi_private *devpriv = dev->private;
unsigned int ui_Timervalue2;
unsigned short us_TmpValue;
unsigned char b_Tmp;
if (!data[1])
comedi_error(dev, "config:No timer constant !");
devpriv->b_Timer2Interrupt = (unsigned char) data[2];
ui_Timervalue2 = data[1] / 1000;
us_TmpValue = (unsigned short) inw(devpriv->iobase + APCI3120_RD_STATUS);
if ((us_TmpValue & 0x00B0) == 0x00B0
|| !strcmp(this_board->pc_DriverName, "apci3001")) {
ui_Timervalue2 = ui_Timervalue2 / 50;
} else {
ui_Timervalue2 = ui_Timervalue2 / 70;
}
devpriv->us_OutputRegister =
devpriv->us_OutputRegister & APCI3120_DISABLE_TIMER2;
outw(devpriv->us_OutputRegister, devpriv->iobase + APCI3120_WR_ADDRESS);
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister & APCI3120_DISABLE_TIMER_INT & 0xEF;
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister & APCI3120_DISABLE_EOC_INT &
APCI3120_DISABLE_EOS_INT;
outb(devpriv->b_ModeSelectRegister,
devpriv->iobase + APCI3120_WRITE_MODE_SELECT);
if (data[0] == APCI3120_TIMER) {
devpriv->b_TimerSelectMode =
(devpriv->
b_TimerSelectMode & 0x0F) | APCI3120_TIMER_2_MODE_2;
outb(devpriv->b_TimerSelectMode,
devpriv->iobase + APCI3120_TIMER_CRT1);
b_Tmp = ((devpriv->
b_DigitalOutputRegister) & 0xF0) |
APCI3120_SELECT_TIMER_2_LOW_WORD;
outb(b_Tmp, devpriv->iobase + APCI3120_TIMER_CRT0);
outw(LOWORD(ui_Timervalue2),
devpriv->iobase + APCI3120_TIMER_VALUE);
b_Tmp = ((devpriv->
b_DigitalOutputRegister) & 0xF0) |
APCI3120_SELECT_TIMER_2_HIGH_WORD;
outb(b_Tmp, devpriv->iobase + APCI3120_TIMER_CRT0);
outw(HIWORD(ui_Timervalue2),
devpriv->iobase + APCI3120_TIMER_VALUE);
devpriv->b_Timer2Mode = APCI3120_TIMER;
} else {
devpriv->b_TimerSelectMode =
(devpriv->
b_TimerSelectMode & 0x0F) | APCI3120_TIMER_2_MODE_5;
outb(devpriv->b_TimerSelectMode,
devpriv->iobase + APCI3120_TIMER_CRT1);
b_Tmp = ((devpriv->
b_DigitalOutputRegister) & 0xF0) |
APCI3120_SELECT_TIMER_2_LOW_WORD;
outb(b_Tmp, devpriv->iobase + APCI3120_TIMER_CRT0);
outw(LOWORD(ui_Timervalue2),
devpriv->iobase + APCI3120_TIMER_VALUE);
b_Tmp = ((devpriv->
b_DigitalOutputRegister) & 0xF0) |
APCI3120_SELECT_TIMER_2_HIGH_WORD;
outb(b_Tmp, devpriv->iobase + APCI3120_TIMER_CRT0);
outw(HIWORD(ui_Timervalue2),
devpriv->iobase + APCI3120_TIMER_VALUE);
devpriv->b_Timer2Mode = APCI3120_WATCHDOG;
}
return insn->n;
}
static int i_APCI3120_InsnWriteTimer(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
const struct addi_board *this_board = comedi_board(dev);
struct addi_private *devpriv = dev->private;
unsigned int ui_Timervalue2 = 0;
unsigned short us_TmpValue;
unsigned char b_Tmp;
if ((devpriv->b_Timer2Mode != APCI3120_WATCHDOG)
&& (devpriv->b_Timer2Mode != APCI3120_TIMER)) {
comedi_error(dev, "\nwrite:timer2 not configured ");
return -EINVAL;
}
if (data[0] == 2) {
if (devpriv->b_Timer2Mode != APCI3120_TIMER) {
comedi_error(dev,
"write :timer2 not configured in TIMER MODE");
return -EINVAL;
}
if (data[1])
ui_Timervalue2 = data[1];
else
ui_Timervalue2 = 0;
}
switch (data[0]) {
case APCI3120_START:
inb(devpriv->iobase + APCI3120_TIMER_STATUS_REGISTER);
if (devpriv->b_Timer2Mode == APCI3120_TIMER) {
devpriv->b_ModeSelectRegister =
devpriv->b_ModeSelectRegister & 0x0B;
} else {
devpriv->b_ModeSelectRegister =
(devpriv->
b_ModeSelectRegister & 0x0B) |
APCI3120_ENABLE_WATCHDOG;
}
if ((devpriv->b_Timer2Interrupt) == APCI3120_ENABLE) {
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister |
APCI3120_ENABLE_TIMER_INT;
devpriv->tsk_Current = current;
} else {
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister &
APCI3120_DISABLE_TIMER_INT;
}
outb(devpriv->b_ModeSelectRegister,
devpriv->iobase + APCI3120_WRITE_MODE_SELECT);
if (devpriv->b_Timer2Mode == APCI3120_TIMER) {
devpriv->us_OutputRegister =
devpriv->
us_OutputRegister | APCI3120_ENABLE_TIMER2;
outw(devpriv->us_OutputRegister,
devpriv->iobase + APCI3120_WR_ADDRESS);
}
break;
case APCI3120_STOP:
if (devpriv->b_Timer2Mode == APCI3120_TIMER) {
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister &
APCI3120_DISABLE_TIMER_COUNTER;
} else {
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister &
APCI3120_DISABLE_WATCHDOG;
}
devpriv->b_ModeSelectRegister =
devpriv->
b_ModeSelectRegister & APCI3120_DISABLE_TIMER_INT;
outb(devpriv->b_ModeSelectRegister,
devpriv->iobase + APCI3120_WRITE_MODE_SELECT);
devpriv->us_OutputRegister =
devpriv->us_OutputRegister & APCI3120_DISABLE_TIMER_INT;
outw(devpriv->us_OutputRegister,
devpriv->iobase + APCI3120_WR_ADDRESS);
inb(devpriv->iobase + APCI3120_TIMER_STATUS_REGISTER);
break;
case 2:
if (devpriv->b_Timer2Mode != APCI3120_TIMER) {
comedi_error(dev,
"write :timer2 not configured in TIMER MODE");
return -EINVAL;
}
us_TmpValue =
(unsigned short) inw(devpriv->iobase + APCI3120_RD_STATUS);
if ((us_TmpValue & 0x00B0) == 0x00B0
|| !strcmp(this_board->pc_DriverName, "apci3001")) {
ui_Timervalue2 = ui_Timervalue2 / 50;
} else {
ui_Timervalue2 = ui_Timervalue2 / 70;
}
b_Tmp = ((devpriv->
b_DigitalOutputRegister) & 0xF0) |
APCI3120_SELECT_TIMER_2_LOW_WORD;
outb(b_Tmp, devpriv->iobase + APCI3120_TIMER_CRT0);
outw(LOWORD(ui_Timervalue2),
devpriv->iobase + APCI3120_TIMER_VALUE);
b_Tmp = ((devpriv->
b_DigitalOutputRegister) & 0xF0) |
APCI3120_SELECT_TIMER_2_HIGH_WORD;
outb(b_Tmp, devpriv->iobase + APCI3120_TIMER_CRT0);
outw(HIWORD(ui_Timervalue2),
devpriv->iobase + APCI3120_TIMER_VALUE);
break;
default:
return -EINVAL;
}
return insn->n;
}
static int i_APCI3120_InsnReadTimer(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
unsigned char b_Tmp;
unsigned short us_TmpValue, us_TmpValue_2, us_StatusValue;
if ((devpriv->b_Timer2Mode != APCI3120_WATCHDOG)
&& (devpriv->b_Timer2Mode != APCI3120_TIMER)) {
comedi_error(dev, "\nread:timer2 not configured ");
}
if (devpriv->b_Timer2Mode == APCI3120_TIMER) {
b_Tmp = ((devpriv->
b_DigitalOutputRegister) & 0xF0) |
APCI3120_SELECT_TIMER_2_LOW_WORD;
outb(b_Tmp, devpriv->iobase + APCI3120_TIMER_CRT0);
us_TmpValue = inw(devpriv->iobase + APCI3120_TIMER_VALUE);
b_Tmp = ((devpriv->
b_DigitalOutputRegister) & 0xF0) |
APCI3120_SELECT_TIMER_2_HIGH_WORD;
outb(b_Tmp, devpriv->iobase + APCI3120_TIMER_CRT0);
us_TmpValue_2 = inw(devpriv->iobase + APCI3120_TIMER_VALUE);
data[0] = (unsigned int) ((us_TmpValue) | ((us_TmpValue_2) << 16));
} else {
us_StatusValue = inw(devpriv->iobase + APCI3120_RD_STATUS);
us_StatusValue =
((us_StatusValue & APCI3120_FC_TIMER) >> 12) & 1;
if (us_StatusValue == 1) {
inb(devpriv->iobase + APCI3120_TIMER_STATUS_REGISTER);
}
data[0] = us_StatusValue;
}
return insn->n;
}
static int apci3120_di_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
unsigned int val;
val = inw(devpriv->iobase + APCI3120_RD_STATUS);
data[1] = (val >> 8) & 0xf;
return insn->n;
}
static int apci3120_do_insn_bits(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
if (comedi_dio_update_state(s, data)) {
devpriv->b_DigitalOutputRegister = s->state << 4;
outb(devpriv->b_DigitalOutputRegister,
devpriv->iobase + APCI3120_DIGITAL_OUTPUT);
}
data[1] = s->state;
return insn->n;
}
static int i_APCI3120_InsnWriteAnalogOutput(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn,
unsigned int *data)
{
struct addi_private *devpriv = dev->private;
unsigned int ui_Range, ui_Channel;
unsigned short us_TmpValue;
ui_Range = CR_RANGE(insn->chanspec);
ui_Channel = CR_CHAN(insn->chanspec);
if (ui_Range) {
if (data[0] != 0)
data[0] =
((((ui_Channel & 0x03) << 14) & 0xC000) | (1 <<
13) | (data[0] + 8191));
else
data[0] =
((((ui_Channel & 0x03) << 14) & 0xC000) | (1 <<
13) | 8192);
} else {
data[0] =
((((ui_Channel & 0x03) << 14) & 0xC000) | (0 << 13) |
data[0]);
}
do {
us_TmpValue =
((unsigned short) inw(devpriv->iobase +
APCI3120_RD_STATUS)) & 0x0001;
} while (us_TmpValue != 0x0001);
if (ui_Channel <= 3)
outw((unsigned short) data[0],
devpriv->iobase + APCI3120_ANALOG_OUTPUT_1);
else
outw((unsigned short) data[0],
devpriv->iobase + APCI3120_ANALOG_OUTPUT_2);
return insn->n;
}
