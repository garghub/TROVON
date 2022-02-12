static void e_series_win_out(struct comedi_device *dev, uint16_t data, int reg)
{
unsigned long flags;
spin_lock_irqsave(&devpriv->window_lock, flags);
ni_writew(reg, Window_Address);
ni_writew(data, Window_Data);
spin_unlock_irqrestore(&devpriv->window_lock, flags);
}
static uint16_t e_series_win_in(struct comedi_device *dev, int reg)
{
unsigned long flags;
uint16_t ret;
spin_lock_irqsave(&devpriv->window_lock, flags);
ni_writew(reg, Window_Address);
ret = ni_readw(Window_Data);
spin_unlock_irqrestore(&devpriv->window_lock, flags);
return ret;
}
static void m_series_stc_writew(struct comedi_device *dev, uint16_t data,
int reg)
{
unsigned offset;
switch (reg) {
case ADC_FIFO_Clear:
offset = M_Offset_AI_FIFO_Clear;
break;
case AI_Command_1_Register:
offset = M_Offset_AI_Command_1;
break;
case AI_Command_2_Register:
offset = M_Offset_AI_Command_2;
break;
case AI_Mode_1_Register:
offset = M_Offset_AI_Mode_1;
break;
case AI_Mode_2_Register:
offset = M_Offset_AI_Mode_2;
break;
case AI_Mode_3_Register:
offset = M_Offset_AI_Mode_3;
break;
case AI_Output_Control_Register:
offset = M_Offset_AI_Output_Control;
break;
case AI_Personal_Register:
offset = M_Offset_AI_Personal;
break;
case AI_SI2_Load_A_Register:
ni_writel(data, M_Offset_AI_SI2_Load_A);
return;
break;
case AI_SI2_Load_B_Register:
ni_writel(data, M_Offset_AI_SI2_Load_B);
return;
break;
case AI_START_STOP_Select_Register:
offset = M_Offset_AI_START_STOP_Select;
break;
case AI_Trigger_Select_Register:
offset = M_Offset_AI_Trigger_Select;
break;
case Analog_Trigger_Etc_Register:
offset = M_Offset_Analog_Trigger_Etc;
break;
case AO_Command_1_Register:
offset = M_Offset_AO_Command_1;
break;
case AO_Command_2_Register:
offset = M_Offset_AO_Command_2;
break;
case AO_Mode_1_Register:
offset = M_Offset_AO_Mode_1;
break;
case AO_Mode_2_Register:
offset = M_Offset_AO_Mode_2;
break;
case AO_Mode_3_Register:
offset = M_Offset_AO_Mode_3;
break;
case AO_Output_Control_Register:
offset = M_Offset_AO_Output_Control;
break;
case AO_Personal_Register:
offset = M_Offset_AO_Personal;
break;
case AO_Start_Select_Register:
offset = M_Offset_AO_Start_Select;
break;
case AO_Trigger_Select_Register:
offset = M_Offset_AO_Trigger_Select;
break;
case Clock_and_FOUT_Register:
offset = M_Offset_Clock_and_FOUT;
break;
case Configuration_Memory_Clear:
offset = M_Offset_Configuration_Memory_Clear;
break;
case DAC_FIFO_Clear:
offset = M_Offset_AO_FIFO_Clear;
break;
case DIO_Control_Register:
printk
("%s: FIXME: register 0x%x does not map cleanly on to m-series boards.\n",
__func__, reg);
return;
break;
case G_Autoincrement_Register(0):
offset = M_Offset_G0_Autoincrement;
break;
case G_Autoincrement_Register(1):
offset = M_Offset_G1_Autoincrement;
break;
case G_Command_Register(0):
offset = M_Offset_G0_Command;
break;
case G_Command_Register(1):
offset = M_Offset_G1_Command;
break;
case G_Input_Select_Register(0):
offset = M_Offset_G0_Input_Select;
break;
case G_Input_Select_Register(1):
offset = M_Offset_G1_Input_Select;
break;
case G_Mode_Register(0):
offset = M_Offset_G0_Mode;
break;
case G_Mode_Register(1):
offset = M_Offset_G1_Mode;
break;
case Interrupt_A_Ack_Register:
offset = M_Offset_Interrupt_A_Ack;
break;
case Interrupt_A_Enable_Register:
offset = M_Offset_Interrupt_A_Enable;
break;
case Interrupt_B_Ack_Register:
offset = M_Offset_Interrupt_B_Ack;
break;
case Interrupt_B_Enable_Register:
offset = M_Offset_Interrupt_B_Enable;
break;
case Interrupt_Control_Register:
offset = M_Offset_Interrupt_Control;
break;
case IO_Bidirection_Pin_Register:
offset = M_Offset_IO_Bidirection_Pin;
break;
case Joint_Reset_Register:
offset = M_Offset_Joint_Reset;
break;
case RTSI_Trig_A_Output_Register:
offset = M_Offset_RTSI_Trig_A_Output;
break;
case RTSI_Trig_B_Output_Register:
offset = M_Offset_RTSI_Trig_B_Output;
break;
case RTSI_Trig_Direction_Register:
offset = M_Offset_RTSI_Trig_Direction;
break;
default:
printk(KERN_WARNING "%s: bug! unhandled register=0x%x in switch.\n",
__func__, reg);
BUG();
return;
break;
}
ni_writew(data, offset);
}
static uint16_t m_series_stc_readw(struct comedi_device *dev, int reg)
{
unsigned offset;
switch (reg) {
case AI_Status_1_Register:
offset = M_Offset_AI_Status_1;
break;
case AO_Status_1_Register:
offset = M_Offset_AO_Status_1;
break;
case AO_Status_2_Register:
offset = M_Offset_AO_Status_2;
break;
case DIO_Serial_Input_Register:
return ni_readb(M_Offset_SCXI_Serial_Data_In);
break;
case Joint_Status_1_Register:
offset = M_Offset_Joint_Status_1;
break;
case Joint_Status_2_Register:
offset = M_Offset_Joint_Status_2;
break;
case G_Status_Register:
offset = M_Offset_G01_Status;
break;
default:
printk(KERN_WARNING "%s: bug! unhandled register=0x%x in switch.\n",
__func__, reg);
BUG();
return 0;
break;
}
return ni_readw(offset);
}
static void m_series_stc_writel(struct comedi_device *dev, uint32_t data,
int reg)
{
unsigned offset;
switch (reg) {
case AI_SC_Load_A_Registers:
offset = M_Offset_AI_SC_Load_A;
break;
case AI_SI_Load_A_Registers:
offset = M_Offset_AI_SI_Load_A;
break;
case AO_BC_Load_A_Register:
offset = M_Offset_AO_BC_Load_A;
break;
case AO_UC_Load_A_Register:
offset = M_Offset_AO_UC_Load_A;
break;
case AO_UI_Load_A_Register:
offset = M_Offset_AO_UI_Load_A;
break;
case G_Load_A_Register(0):
offset = M_Offset_G0_Load_A;
break;
case G_Load_A_Register(1):
offset = M_Offset_G1_Load_A;
break;
case G_Load_B_Register(0):
offset = M_Offset_G0_Load_B;
break;
case G_Load_B_Register(1):
offset = M_Offset_G1_Load_B;
break;
default:
printk(KERN_WARNING "%s: bug! unhandled register=0x%x in switch.\n",
__func__, reg);
BUG();
return;
break;
}
ni_writel(data, offset);
}
static uint32_t m_series_stc_readl(struct comedi_device *dev, int reg)
{
unsigned offset;
switch (reg) {
case G_HW_Save_Register(0):
offset = M_Offset_G0_HW_Save;
break;
case G_HW_Save_Register(1):
offset = M_Offset_G1_HW_Save;
break;
case G_Save_Register(0):
offset = M_Offset_G0_Save;
break;
case G_Save_Register(1):
offset = M_Offset_G1_Save;
break;
default:
printk(KERN_WARNING "%s: bug! unhandled register=0x%x in switch.\n",
__func__, reg);
BUG();
return 0;
break;
}
return ni_readl(offset);
}
static void m_series_init_eeprom_buffer(struct comedi_device *dev)
{
static const int Start_Cal_EEPROM = 0x400;
static const unsigned window_size = 10;
static const int serial_number_eeprom_offset = 0x4;
static const int serial_number_eeprom_length = 0x4;
unsigned old_iodwbsr_bits;
unsigned old_iodwbsr1_bits;
unsigned old_iodwcr1_bits;
int i;
old_iodwbsr_bits = readl(devpriv->mite->mite_io_addr + MITE_IODWBSR);
old_iodwbsr1_bits = readl(devpriv->mite->mite_io_addr + MITE_IODWBSR_1);
old_iodwcr1_bits = readl(devpriv->mite->mite_io_addr + MITE_IODWCR_1);
writel(0x0, devpriv->mite->mite_io_addr + MITE_IODWBSR);
writel(((0x80 | window_size) | devpriv->mite->daq_phys_addr),
devpriv->mite->mite_io_addr + MITE_IODWBSR_1);
writel(0x1 | old_iodwcr1_bits,
devpriv->mite->mite_io_addr + MITE_IODWCR_1);
writel(0xf, devpriv->mite->mite_io_addr + 0x30);
BUG_ON(serial_number_eeprom_length > sizeof(devpriv->serial_number));
for (i = 0; i < serial_number_eeprom_length; ++i) {
char *byte_ptr = (char *)&devpriv->serial_number + i;
*byte_ptr = ni_readb(serial_number_eeprom_offset + i);
}
devpriv->serial_number = be32_to_cpu(devpriv->serial_number);
for (i = 0; i < M_SERIES_EEPROM_SIZE; ++i)
devpriv->eeprom_buffer[i] = ni_readb(Start_Cal_EEPROM + i);
writel(old_iodwbsr1_bits, devpriv->mite->mite_io_addr + MITE_IODWBSR_1);
writel(old_iodwbsr_bits, devpriv->mite->mite_io_addr + MITE_IODWBSR);
writel(old_iodwcr1_bits, devpriv->mite->mite_io_addr + MITE_IODWCR_1);
writel(0x0, devpriv->mite->mite_io_addr + 0x30);
}
static void init_6143(struct comedi_device *dev)
{
devpriv->stc_writew(dev, 0, Interrupt_Control_Register);
ni_writeb(0x00, Magic_6143);
ni_writeb(0x80, PipelineDelay_6143);
ni_writeb(0x00, EOC_Set_6143);
ni_writel(boardtype.ai_fifo_depth / 2, AIFIFO_Flag_6143);
devpriv->ai_calib_source_enabled = 0;
ni_writew(devpriv->ai_calib_source | Calibration_Channel_6143_RelayOff,
Calibration_Channel_6143);
ni_writew(devpriv->ai_calib_source, Calibration_Channel_6143);
}
static void pcimio_detach(struct comedi_device *dev)
{
mio_common_detach(dev);
if (dev->irq)
free_irq(dev->irq, dev);
if (dev->private) {
mite_free_ring(devpriv->ai_mite_ring);
mite_free_ring(devpriv->ao_mite_ring);
mite_free_ring(devpriv->cdo_mite_ring);
mite_free_ring(devpriv->gpct_mite_ring[0]);
mite_free_ring(devpriv->gpct_mite_ring[1]);
if (devpriv->mite)
mite_unsetup(devpriv->mite);
}
}
static int pcimio_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
int ret;
dev_info(dev->class_dev, "ni_pcimio: attach\n");
ret = ni_alloc_private(dev);
if (ret < 0)
return ret;
ret = pcimio_find_device(dev, it->options[0], it->options[1]);
if (ret < 0)
return ret;
dev_dbg(dev->class_dev, "%s\n", boardtype.name);
dev->board_name = boardtype.name;
if (boardtype.reg_type & ni_reg_m_series_mask) {
devpriv->stc_writew = &m_series_stc_writew;
devpriv->stc_readw = &m_series_stc_readw;
devpriv->stc_writel = &m_series_stc_writel;
devpriv->stc_readl = &m_series_stc_readl;
} else {
devpriv->stc_writew = &e_series_win_out;
devpriv->stc_readw = &e_series_win_in;
devpriv->stc_writel = &win_out2;
devpriv->stc_readl = &win_in2;
}
ret = mite_setup(devpriv->mite);
if (ret < 0) {
pr_warn("error setting up mite\n");
return ret;
}
comedi_set_hw_dev(dev, &devpriv->mite->pcidev->dev);
devpriv->ai_mite_ring = mite_alloc_ring(devpriv->mite);
if (devpriv->ai_mite_ring == NULL)
return -ENOMEM;
devpriv->ao_mite_ring = mite_alloc_ring(devpriv->mite);
if (devpriv->ao_mite_ring == NULL)
return -ENOMEM;
devpriv->cdo_mite_ring = mite_alloc_ring(devpriv->mite);
if (devpriv->cdo_mite_ring == NULL)
return -ENOMEM;
devpriv->gpct_mite_ring[0] = mite_alloc_ring(devpriv->mite);
if (devpriv->gpct_mite_ring[0] == NULL)
return -ENOMEM;
devpriv->gpct_mite_ring[1] = mite_alloc_ring(devpriv->mite);
if (devpriv->gpct_mite_ring[1] == NULL)
return -ENOMEM;
if (boardtype.reg_type & ni_reg_m_series_mask)
m_series_init_eeprom_buffer(dev);
if (boardtype.reg_type == ni_reg_6143)
init_6143(dev);
dev->irq = mite_irq(devpriv->mite);
if (dev->irq == 0) {
pr_warn("unknown irq (bad)\n");
} else {
pr_debug("( irq = %u )\n", dev->irq);
ret = request_irq(dev->irq, ni_E_interrupt, NI_E_IRQ_FLAGS,
DRV_NAME, dev);
if (ret < 0) {
pr_warn("irq not available\n");
dev->irq = 0;
}
}
ret = ni_E_init(dev, it);
if (ret < 0)
return ret;
dev->subdevices[NI_AI_SUBDEV].buf_change = &pcimio_ai_change;
dev->subdevices[NI_AO_SUBDEV].buf_change = &pcimio_ao_change;
dev->subdevices[NI_GPCT_SUBDEV(0)].buf_change = &pcimio_gpct0_change;
dev->subdevices[NI_GPCT_SUBDEV(1)].buf_change = &pcimio_gpct1_change;
dev->subdevices[NI_DIO_SUBDEV].buf_change = &pcimio_dio_change;
return ret;
}
static int pcimio_find_device(struct comedi_device *dev, int bus, int slot)
{
struct mite_struct *mite;
int i;
for (mite = mite_devices; mite; mite = mite->next) {
if (mite->used)
continue;
if (bus || slot) {
if (bus != mite->pcidev->bus->number ||
slot != PCI_SLOT(mite->pcidev->devfn))
continue;
}
for (i = 0; i < n_pcimio_boards; i++) {
if (mite_device_id(mite) == ni_boards[i].device_id) {
dev->board_ptr = ni_boards + i;
devpriv->mite = mite;
return 0;
}
}
}
pr_warn("no device found\n");
mite_list_devices();
return -EIO;
}
static int pcimio_ai_change(struct comedi_device *dev,
struct comedi_subdevice *s, unsigned long new_size)
{
int ret;
ret = mite_buf_change(devpriv->ai_mite_ring, s->async);
if (ret < 0)
return ret;
return 0;
}
static int pcimio_ao_change(struct comedi_device *dev,
struct comedi_subdevice *s, unsigned long new_size)
{
int ret;
ret = mite_buf_change(devpriv->ao_mite_ring, s->async);
if (ret < 0)
return ret;
return 0;
}
static int pcimio_gpct0_change(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned long new_size)
{
int ret;
ret = mite_buf_change(devpriv->gpct_mite_ring[0], s->async);
if (ret < 0)
return ret;
return 0;
}
static int pcimio_gpct1_change(struct comedi_device *dev,
struct comedi_subdevice *s,
unsigned long new_size)
{
int ret;
ret = mite_buf_change(devpriv->gpct_mite_ring[1], s->async);
if (ret < 0)
return ret;
return 0;
}
static int pcimio_dio_change(struct comedi_device *dev,
struct comedi_subdevice *s, unsigned long new_size)
{
int ret;
ret = mite_buf_change(devpriv->cdo_mite_ring, s->async);
if (ret < 0)
return ret;
return 0;
}
static int __devinit ni_pcimio_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &ni_pcimio_driver);
}
static void __devexit ni_pcimio_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
