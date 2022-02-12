static inline unsigned int labpc_inb(unsigned long address)
{
return inb(address);
}
static inline void labpc_outb(unsigned int byte, unsigned long address)
{
outb(byte, address);
}
static inline unsigned int labpc_readb(unsigned long address)
{
return readb((void *)address);
}
static inline void labpc_writeb(unsigned int byte, unsigned long address)
{
writeb(byte, (void *)address);
}
static inline int labpc_counter_load(struct comedi_device *dev,
unsigned long base_address,
unsigned int counter_number,
unsigned int count, unsigned int mode)
{
if (thisboard->memory_mapped_io)
return i8254_mm_load((void *)base_address, 0, counter_number,
count, mode);
else
return i8254_load(base_address, 0, counter_number, count, mode);
}
int labpc_common_attach(struct comedi_device *dev, unsigned long iobase,
unsigned int irq, unsigned int dma_chan)
{
struct comedi_subdevice *s;
int i;
unsigned long isr_flags;
#ifdef CONFIG_ISA_DMA_API
unsigned long dma_flags;
#endif
short lsb, msb;
int ret;
printk(KERN_ERR "comedi%d: ni_labpc: %s, io 0x%lx", dev->minor,
thisboard->name,
iobase);
if (irq)
printk(", irq %u", irq);
if (dma_chan)
printk(", dma %u", dma_chan);
printk("\n");
if (iobase == 0) {
printk(KERN_ERR "io base address is zero!\n");
return -EINVAL;
}
if (thisboard->bustype == isa_bustype) {
if (!request_region(iobase, LABPC_SIZE,
driver_labpc.driver_name)) {
printk(KERN_ERR "I/O port conflict\n");
return -EIO;
}
}
dev->iobase = iobase;
if (thisboard->memory_mapped_io) {
devpriv->read_byte = labpc_readb;
devpriv->write_byte = labpc_writeb;
} else {
devpriv->read_byte = labpc_inb;
devpriv->write_byte = labpc_outb;
}
devpriv->write_byte(devpriv->command1_bits, dev->iobase + COMMAND1_REG);
devpriv->write_byte(devpriv->command2_bits, dev->iobase + COMMAND2_REG);
devpriv->write_byte(devpriv->command3_bits, dev->iobase + COMMAND3_REG);
devpriv->write_byte(devpriv->command4_bits, dev->iobase + COMMAND4_REG);
if (thisboard->register_layout == labpc_1200_layout) {
devpriv->write_byte(devpriv->command5_bits,
dev->iobase + COMMAND5_REG);
devpriv->write_byte(devpriv->command6_bits,
dev->iobase + COMMAND6_REG);
}
if (irq) {
isr_flags = 0;
if (thisboard->bustype == pci_bustype
|| thisboard->bustype == pcmcia_bustype)
isr_flags |= IRQF_SHARED;
if (request_irq(irq, labpc_interrupt, isr_flags,
driver_labpc.driver_name, dev)) {
printk(KERN_ERR "unable to allocate irq %u\n", irq);
return -EINVAL;
}
}
dev->irq = irq;
#ifdef CONFIG_ISA_DMA_API
if (dma_chan > 3) {
printk(KERN_ERR " invalid dma channel %u\n", dma_chan);
return -EINVAL;
} else if (dma_chan) {
devpriv->dma_buffer =
kmalloc(dma_buffer_size, GFP_KERNEL | GFP_DMA);
if (devpriv->dma_buffer == NULL) {
printk(KERN_ERR " failed to allocate dma buffer\n");
return -ENOMEM;
}
if (request_dma(dma_chan, driver_labpc.driver_name)) {
printk(KERN_ERR " failed to allocate dma channel %u\n",
dma_chan);
return -EINVAL;
}
devpriv->dma_chan = dma_chan;
dma_flags = claim_dma_lock();
disable_dma(devpriv->dma_chan);
set_dma_mode(devpriv->dma_chan, DMA_MODE_READ);
release_dma_lock(dma_flags);
}
#endif
dev->board_name = thisboard->name;
ret = comedi_alloc_subdevices(dev, 5);
if (ret)
return ret;
s = dev->subdevices + 0;
dev->read_subdev = s;
s->type = COMEDI_SUBD_AI;
s->subdev_flags =
SDF_READABLE | SDF_GROUND | SDF_COMMON | SDF_DIFF | SDF_CMD_READ;
s->n_chan = 8;
s->len_chanlist = 8;
s->maxdata = (1 << 12) - 1;
s->range_table = thisboard->ai_range_table;
s->do_cmd = labpc_ai_cmd;
s->do_cmdtest = labpc_ai_cmdtest;
s->insn_read = labpc_ai_rinsn;
s->cancel = labpc_cancel;
s = dev->subdevices + 1;
if (thisboard->has_ao) {
s->type = COMEDI_SUBD_AO;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_GROUND;
s->n_chan = NUM_AO_CHAN;
s->maxdata = (1 << 12) - 1;
s->range_table = &range_labpc_ao;
s->insn_read = labpc_ao_rinsn;
s->insn_write = labpc_ao_winsn;
for (i = 0; i < s->n_chan; i++) {
devpriv->ao_value[i] = s->maxdata / 2;
lsb = devpriv->ao_value[i] & 0xff;
msb = (devpriv->ao_value[i] >> 8) & 0xff;
devpriv->write_byte(lsb, dev->iobase + DAC_LSB_REG(i));
devpriv->write_byte(msb, dev->iobase + DAC_MSB_REG(i));
}
} else {
s->type = COMEDI_SUBD_UNUSED;
}
s = dev->subdevices + 2;
if (thisboard->memory_mapped_io)
subdev_8255_init(dev, s, labpc_dio_mem_callback,
(unsigned long)(dev->iobase + DIO_BASE_REG));
else
subdev_8255_init(dev, s, NULL, dev->iobase + DIO_BASE_REG);
s = dev->subdevices + 3;
if (thisboard->register_layout == labpc_1200_layout) {
s->type = COMEDI_SUBD_CALIB;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = 16;
s->maxdata = 0xff;
s->insn_read = labpc_calib_read_insn;
s->insn_write = labpc_calib_write_insn;
for (i = 0; i < s->n_chan; i++)
write_caldac(dev, i, s->maxdata / 2);
} else
s->type = COMEDI_SUBD_UNUSED;
s = dev->subdevices + 4;
if (thisboard->register_layout == labpc_1200_layout) {
s->type = COMEDI_SUBD_MEMORY;
s->subdev_flags = SDF_READABLE | SDF_WRITABLE | SDF_INTERNAL;
s->n_chan = EEPROM_SIZE;
s->maxdata = 0xff;
s->insn_read = labpc_eeprom_read_insn;
s->insn_write = labpc_eeprom_write_insn;
for (i = 0; i < EEPROM_SIZE; i++)
devpriv->eeprom_data[i] = labpc_eeprom_read(dev, i);
#ifdef LABPC_DEBUG
printk(KERN_ERR " eeprom:");
for (i = 0; i < EEPROM_SIZE; i++)
printk(" %i:0x%x ", i, devpriv->eeprom_data[i]);
printk("\n");
#endif
} else
s->type = COMEDI_SUBD_UNUSED;
return 0;
}
static int labpc_attach(struct comedi_device *dev, struct comedi_devconfig *it)
{
unsigned long iobase = 0;
unsigned int irq = 0;
unsigned int dma_chan = 0;
#ifdef CONFIG_COMEDI_PCI_DRIVERS
int retval;
#endif
if (alloc_private(dev, sizeof(struct labpc_private)) < 0)
return -ENOMEM;
switch (thisboard->bustype) {
case isa_bustype:
#ifdef CONFIG_ISA_DMA_API
iobase = it->options[0];
irq = it->options[1];
dma_chan = it->options[2];
#else
printk(KERN_ERR " this driver has not been built with ISA DMA "
"support.\n");
return -EINVAL;
#endif
break;
case pci_bustype:
#ifdef CONFIG_COMEDI_PCI_DRIVERS
retval = labpc_find_device(dev, it->options[0], it->options[1]);
if (retval < 0)
return retval;
retval = mite_setup(devpriv->mite);
if (retval < 0)
return retval;
iobase = (unsigned long)devpriv->mite->daq_io_addr;
irq = mite_irq(devpriv->mite);
#else
printk(KERN_ERR " this driver has not been built with PCI "
"support.\n");
return -EINVAL;
#endif
break;
case pcmcia_bustype:
printk
(" this driver does not support pcmcia cards, use ni_labpc_cs.o\n");
return -EINVAL;
break;
default:
printk(KERN_ERR "bug! couldn't determine board type\n");
return -EINVAL;
break;
}
return labpc_common_attach(dev, iobase, irq, dma_chan);
}
static int labpc_find_device(struct comedi_device *dev, int bus, int slot)
{
struct mite_struct *mite;
int i;
for (mite = mite_devices; mite; mite = mite->next) {
if (mite->used)
continue;
if (bus || slot) {
if (bus != mite->pcidev->bus->number
|| slot != PCI_SLOT(mite->pcidev->devfn))
continue;
}
for (i = 0; i < driver_labpc.num_names; i++) {
if (labpc_boards[i].bustype != pci_bustype)
continue;
if (mite_device_id(mite) == labpc_boards[i].device_id) {
devpriv->mite = mite;
dev->board_ptr = &labpc_boards[i];
return 0;
}
}
}
printk(KERN_ERR "no device found\n");
mite_list_devices();
return -EIO;
}
void labpc_common_detach(struct comedi_device *dev)
{
if (dev->subdevices)
subdev_8255_cleanup(dev, dev->subdevices + 2);
#ifdef CONFIG_ISA_DMA_API
kfree(devpriv->dma_buffer);
if (devpriv->dma_chan)
free_dma(devpriv->dma_chan);
#endif
if (dev->irq)
free_irq(dev->irq, dev);
if (thisboard->bustype == isa_bustype && dev->iobase)
release_region(dev->iobase, LABPC_SIZE);
#ifdef CONFIG_COMEDI_PCI_DRIVERS
if (devpriv->mite)
mite_unsetup(devpriv->mite);
#endif
}
static void labpc_clear_adc_fifo(const struct comedi_device *dev)
{
devpriv->write_byte(0x1, dev->iobase + ADC_CLEAR_REG);
devpriv->read_byte(dev->iobase + ADC_FIFO_REG);
devpriv->read_byte(dev->iobase + ADC_FIFO_REG);
}
static int labpc_cancel(struct comedi_device *dev, struct comedi_subdevice *s)
{
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->command2_bits &= ~SWTRIG_BIT & ~HWTRIG_BIT & ~PRETRIG_BIT;
devpriv->write_byte(devpriv->command2_bits, dev->iobase + COMMAND2_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
devpriv->command3_bits = 0;
devpriv->write_byte(devpriv->command3_bits, dev->iobase + COMMAND3_REG);
return 0;
}
static enum scan_mode labpc_ai_scan_mode(const struct comedi_cmd *cmd)
{
if (cmd->chanlist_len == 1)
return MODE_SINGLE_CHAN;
if (cmd->chanlist == NULL)
return MODE_MULT_CHAN_UP;
if (CR_CHAN(cmd->chanlist[0]) == CR_CHAN(cmd->chanlist[1]))
return MODE_SINGLE_CHAN_INTERVAL;
if (CR_CHAN(cmd->chanlist[0]) < CR_CHAN(cmd->chanlist[1]))
return MODE_MULT_CHAN_UP;
if (CR_CHAN(cmd->chanlist[0]) > CR_CHAN(cmd->chanlist[1]))
return MODE_MULT_CHAN_DOWN;
printk(KERN_ERR "ni_labpc: bug! this should never happen\n");
return 0;
}
static int labpc_ai_chanlist_invalid(const struct comedi_device *dev,
const struct comedi_cmd *cmd)
{
int mode, channel, range, aref, i;
if (cmd->chanlist == NULL)
return 0;
mode = labpc_ai_scan_mode(cmd);
if (mode == MODE_SINGLE_CHAN)
return 0;
if (mode == MODE_SINGLE_CHAN_INTERVAL) {
if (cmd->chanlist_len > 0xff) {
comedi_error(dev,
"ni_labpc: chanlist too long for single channel interval mode\n");
return 1;
}
}
channel = CR_CHAN(cmd->chanlist[0]);
range = CR_RANGE(cmd->chanlist[0]);
aref = CR_AREF(cmd->chanlist[0]);
for (i = 0; i < cmd->chanlist_len; i++) {
switch (mode) {
case MODE_SINGLE_CHAN_INTERVAL:
if (CR_CHAN(cmd->chanlist[i]) != channel) {
comedi_error(dev,
"channel scanning order specified in chanlist is not supported by hardware.\n");
return 1;
}
break;
case MODE_MULT_CHAN_UP:
if (CR_CHAN(cmd->chanlist[i]) != i) {
comedi_error(dev,
"channel scanning order specified in chanlist is not supported by hardware.\n");
return 1;
}
break;
case MODE_MULT_CHAN_DOWN:
if (CR_CHAN(cmd->chanlist[i]) !=
cmd->chanlist_len - i - 1) {
comedi_error(dev,
"channel scanning order specified in chanlist is not supported by hardware.\n");
return 1;
}
break;
default:
printk(KERN_ERR "ni_labpc: bug! in chanlist check\n");
return 1;
break;
}
if (CR_RANGE(cmd->chanlist[i]) != range) {
comedi_error(dev,
"entries in chanlist must all have the same range\n");
return 1;
}
if (CR_AREF(cmd->chanlist[i]) != aref) {
comedi_error(dev,
"entries in chanlist must all have the same reference\n");
return 1;
}
}
return 0;
}
static int labpc_use_continuous_mode(const struct comedi_cmd *cmd)
{
if (labpc_ai_scan_mode(cmd) == MODE_SINGLE_CHAN)
return 1;
if (cmd->scan_begin_src == TRIG_FOLLOW)
return 1;
return 0;
}
static unsigned int labpc_ai_convert_period(const struct comedi_cmd *cmd)
{
if (cmd->convert_src != TRIG_TIMER)
return 0;
if (labpc_ai_scan_mode(cmd) == MODE_SINGLE_CHAN &&
cmd->scan_begin_src == TRIG_TIMER)
return cmd->scan_begin_arg;
return cmd->convert_arg;
}
static void labpc_set_ai_convert_period(struct comedi_cmd *cmd, unsigned int ns)
{
if (cmd->convert_src != TRIG_TIMER)
return;
if (labpc_ai_scan_mode(cmd) == MODE_SINGLE_CHAN &&
cmd->scan_begin_src == TRIG_TIMER) {
cmd->scan_begin_arg = ns;
if (cmd->convert_arg > cmd->scan_begin_arg)
cmd->convert_arg = cmd->scan_begin_arg;
} else
cmd->convert_arg = ns;
}
static unsigned int labpc_ai_scan_period(const struct comedi_cmd *cmd)
{
if (cmd->scan_begin_src != TRIG_TIMER)
return 0;
if (labpc_ai_scan_mode(cmd) == MODE_SINGLE_CHAN &&
cmd->convert_src == TRIG_TIMER)
return 0;
return cmd->scan_begin_arg;
}
static void labpc_set_ai_scan_period(struct comedi_cmd *cmd, unsigned int ns)
{
if (cmd->scan_begin_src != TRIG_TIMER)
return;
if (labpc_ai_scan_mode(cmd) == MODE_SINGLE_CHAN &&
cmd->convert_src == TRIG_TIMER)
return;
cmd->scan_begin_arg = ns;
}
static int labpc_ai_cmdtest(struct comedi_device *dev,
struct comedi_subdevice *s, struct comedi_cmd *cmd)
{
int err = 0;
int tmp, tmp2;
int stop_mask;
tmp = cmd->start_src;
cmd->start_src &= TRIG_NOW | TRIG_EXT;
if (!cmd->start_src || tmp != cmd->start_src)
err++;
tmp = cmd->scan_begin_src;
cmd->scan_begin_src &= TRIG_TIMER | TRIG_FOLLOW | TRIG_EXT;
if (!cmd->scan_begin_src || tmp != cmd->scan_begin_src)
err++;
tmp = cmd->convert_src;
cmd->convert_src &= TRIG_TIMER | TRIG_EXT;
if (!cmd->convert_src || tmp != cmd->convert_src)
err++;
tmp = cmd->scan_end_src;
cmd->scan_end_src &= TRIG_COUNT;
if (!cmd->scan_end_src || tmp != cmd->scan_end_src)
err++;
tmp = cmd->stop_src;
stop_mask = TRIG_COUNT | TRIG_NONE;
if (thisboard->register_layout == labpc_1200_layout)
stop_mask |= TRIG_EXT;
cmd->stop_src &= stop_mask;
if (!cmd->stop_src || tmp != cmd->stop_src)
err++;
if (err)
return 1;
if (cmd->start_src != TRIG_NOW && cmd->start_src != TRIG_EXT)
err++;
if (cmd->scan_begin_src != TRIG_TIMER &&
cmd->scan_begin_src != TRIG_FOLLOW &&
cmd->scan_begin_src != TRIG_EXT)
err++;
if (cmd->convert_src != TRIG_TIMER && cmd->convert_src != TRIG_EXT)
err++;
if (cmd->stop_src != TRIG_COUNT &&
cmd->stop_src != TRIG_EXT && cmd->stop_src != TRIG_NONE)
err++;
if (cmd->start_src == TRIG_EXT && cmd->stop_src == TRIG_EXT)
err++;
if (err)
return 2;
if (cmd->start_arg == TRIG_NOW && cmd->start_arg != 0) {
cmd->start_arg = 0;
err++;
}
if (!cmd->chanlist_len)
err++;
if (cmd->scan_end_arg != cmd->chanlist_len) {
cmd->scan_end_arg = cmd->chanlist_len;
err++;
}
if (cmd->convert_src == TRIG_TIMER) {
if (cmd->convert_arg < thisboard->ai_speed) {
cmd->convert_arg = thisboard->ai_speed;
err++;
}
}
if (cmd->scan_begin_src == TRIG_TIMER) {
if (cmd->convert_src == TRIG_TIMER &&
cmd->scan_begin_arg <
cmd->convert_arg * cmd->chanlist_len) {
cmd->scan_begin_arg =
cmd->convert_arg * cmd->chanlist_len;
err++;
}
if (cmd->scan_begin_arg <
thisboard->ai_speed * cmd->chanlist_len) {
cmd->scan_begin_arg =
thisboard->ai_speed * cmd->chanlist_len;
err++;
}
}
switch (cmd->stop_src) {
case TRIG_COUNT:
if (!cmd->stop_arg) {
cmd->stop_arg = 1;
err++;
}
break;
case TRIG_NONE:
if (cmd->stop_arg != 0) {
cmd->stop_arg = 0;
err++;
}
break;
default:
break;
}
if (err)
return 3;
tmp = cmd->convert_arg;
tmp2 = cmd->scan_begin_arg;
labpc_adc_timing(dev, cmd);
if (tmp != cmd->convert_arg || tmp2 != cmd->scan_begin_arg)
err++;
if (err)
return 4;
if (labpc_ai_chanlist_invalid(dev, cmd))
return 5;
return 0;
}
static int labpc_ai_cmd(struct comedi_device *dev, struct comedi_subdevice *s)
{
int channel, range, aref;
#ifdef CONFIG_ISA_DMA_API
unsigned long irq_flags;
#endif
int ret;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
enum transfer_type xfer;
unsigned long flags;
if (!dev->irq) {
comedi_error(dev, "no irq assigned, cannot perform command");
return -1;
}
range = CR_RANGE(cmd->chanlist[0]);
aref = CR_AREF(cmd->chanlist[0]);
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->command2_bits &= ~SWTRIG_BIT & ~HWTRIG_BIT & ~PRETRIG_BIT;
devpriv->write_byte(devpriv->command2_bits, dev->iobase + COMMAND2_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
devpriv->command3_bits = 0;
devpriv->write_byte(devpriv->command3_bits, dev->iobase + COMMAND3_REG);
if (cmd->stop_src == TRIG_COUNT)
devpriv->count = cmd->stop_arg * cmd->chanlist_len;
if (cmd->stop_src == TRIG_EXT) {
ret = labpc_counter_load(dev, dev->iobase + COUNTER_A_BASE_REG,
1, 3, 0);
if (ret < 0) {
comedi_error(dev, "error loading counter a1");
return -1;
}
} else
devpriv->write_byte(INIT_A1_BITS,
dev->iobase + COUNTER_A_CONTROL_REG);
#ifdef CONFIG_ISA_DMA_API
if (devpriv->dma_chan &&
(cmd->flags & (TRIG_WAKE_EOS | TRIG_RT)) == 0 &&
thisboard->bustype == isa_bustype) {
xfer = isa_dma_transfer;
} else
#endif
if (thisboard->register_layout == labpc_1200_layout &&
(cmd->flags & TRIG_WAKE_EOS) == 0 &&
(cmd->stop_src != TRIG_COUNT || devpriv->count > 256)) {
xfer = fifo_half_full_transfer;
} else
xfer = fifo_not_empty_transfer;
devpriv->current_transfer = xfer;
if (thisboard->register_layout == labpc_1200_layout) {
if (aref != AREF_GROUND)
devpriv->command6_bits |= ADC_COMMON_BIT;
else
devpriv->command6_bits &= ~ADC_COMMON_BIT;
if (thisboard->ai_range_is_unipolar[range])
devpriv->command6_bits |= ADC_UNIP_BIT;
else
devpriv->command6_bits &= ~ADC_UNIP_BIT;
if (xfer == fifo_half_full_transfer)
devpriv->command6_bits |= ADC_FHF_INTR_EN_BIT;
else
devpriv->command6_bits &= ~ADC_FHF_INTR_EN_BIT;
if (cmd->stop_src == TRIG_EXT)
devpriv->command6_bits |= A1_INTR_EN_BIT;
else
devpriv->command6_bits &= ~A1_INTR_EN_BIT;
if (labpc_ai_scan_mode(cmd) == MODE_MULT_CHAN_UP)
devpriv->command6_bits |= ADC_SCAN_UP_BIT;
else
devpriv->command6_bits &= ~ADC_SCAN_UP_BIT;
devpriv->write_byte(devpriv->command6_bits,
dev->iobase + COMMAND6_REG);
}
devpriv->command1_bits = 0;
if (labpc_ai_scan_mode(cmd) == MODE_MULT_CHAN_UP)
channel = CR_CHAN(cmd->chanlist[cmd->chanlist_len - 1]);
else
channel = CR_CHAN(cmd->chanlist[0]);
if (labpc_ai_scan_mode(cmd) != MODE_SINGLE_CHAN && aref == AREF_DIFF)
channel *= 2;
devpriv->command1_bits |= ADC_CHAN_BITS(channel);
devpriv->command1_bits |= thisboard->ai_range_code[range];
devpriv->write_byte(devpriv->command1_bits, dev->iobase + COMMAND1_REG);
if (labpc_ai_scan_mode(cmd) == MODE_MULT_CHAN_UP ||
labpc_ai_scan_mode(cmd) == MODE_MULT_CHAN_DOWN) {
devpriv->command1_bits |= ADC_SCAN_EN_BIT;
udelay(1);
devpriv->write_byte(devpriv->command1_bits,
dev->iobase + COMMAND1_REG);
}
devpriv->command4_bits = 0;
if (cmd->convert_src != TRIG_EXT)
devpriv->command4_bits |= EXT_CONVERT_DISABLE_BIT;
if (labpc_use_continuous_mode(cmd) == 0) {
devpriv->command4_bits |= INTERVAL_SCAN_EN_BIT;
if (cmd->scan_begin_src == TRIG_EXT)
devpriv->command4_bits |= EXT_SCAN_EN_BIT;
}
if (aref == AREF_DIFF)
devpriv->command4_bits |= ADC_DIFF_BIT;
devpriv->write_byte(devpriv->command4_bits, dev->iobase + COMMAND4_REG);
devpriv->write_byte(cmd->chanlist_len,
dev->iobase + INTERVAL_COUNT_REG);
devpriv->write_byte(INTERVAL_LOAD_BITS,
dev->iobase + INTERVAL_LOAD_REG);
if (cmd->convert_src == TRIG_TIMER || cmd->scan_begin_src == TRIG_TIMER) {
labpc_adc_timing(dev, cmd);
ret = labpc_counter_load(dev, dev->iobase + COUNTER_B_BASE_REG,
0, devpriv->divisor_b0, 3);
if (ret < 0) {
comedi_error(dev, "error loading counter b0");
return -1;
}
}
if (labpc_ai_convert_period(cmd)) {
ret = labpc_counter_load(dev, dev->iobase + COUNTER_A_BASE_REG,
0, devpriv->divisor_a0, 2);
if (ret < 0) {
comedi_error(dev, "error loading counter a0");
return -1;
}
} else
devpriv->write_byte(INIT_A0_BITS,
dev->iobase + COUNTER_A_CONTROL_REG);
if (labpc_ai_scan_period(cmd)) {
ret = labpc_counter_load(dev, dev->iobase + COUNTER_B_BASE_REG,
1, devpriv->divisor_b1, 2);
if (ret < 0) {
comedi_error(dev, "error loading counter b1");
return -1;
}
}
labpc_clear_adc_fifo(dev);
#ifdef CONFIG_ISA_DMA_API
if (xfer == isa_dma_transfer) {
irq_flags = claim_dma_lock();
disable_dma(devpriv->dma_chan);
clear_dma_ff(devpriv->dma_chan);
set_dma_addr(devpriv->dma_chan,
virt_to_bus(devpriv->dma_buffer));
devpriv->dma_transfer_size = labpc_suggest_transfer_size(*cmd);
if (cmd->stop_src == TRIG_COUNT &&
devpriv->count * sample_size < devpriv->dma_transfer_size) {
devpriv->dma_transfer_size =
devpriv->count * sample_size;
}
set_dma_count(devpriv->dma_chan, devpriv->dma_transfer_size);
enable_dma(devpriv->dma_chan);
release_dma_lock(irq_flags);
devpriv->command3_bits |= DMA_EN_BIT | DMATC_INTR_EN_BIT;
} else
devpriv->command3_bits &= ~DMA_EN_BIT & ~DMATC_INTR_EN_BIT;
#endif
devpriv->command3_bits |= ERR_INTR_EN_BIT;
if (xfer == fifo_not_empty_transfer)
devpriv->command3_bits |= ADC_FNE_INTR_EN_BIT;
else
devpriv->command3_bits &= ~ADC_FNE_INTR_EN_BIT;
devpriv->write_byte(devpriv->command3_bits, dev->iobase + COMMAND3_REG);
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->command2_bits |= CASCADE_BIT;
switch (cmd->start_src) {
case TRIG_EXT:
devpriv->command2_bits |= HWTRIG_BIT;
devpriv->command2_bits &= ~PRETRIG_BIT & ~SWTRIG_BIT;
break;
case TRIG_NOW:
devpriv->command2_bits |= SWTRIG_BIT;
devpriv->command2_bits &= ~PRETRIG_BIT & ~HWTRIG_BIT;
break;
default:
comedi_error(dev, "bug with start_src");
spin_unlock_irqrestore(&dev->spinlock, flags);
return -1;
break;
}
switch (cmd->stop_src) {
case TRIG_EXT:
devpriv->command2_bits |= HWTRIG_BIT | PRETRIG_BIT;
break;
case TRIG_COUNT:
case TRIG_NONE:
break;
default:
comedi_error(dev, "bug with stop_src");
spin_unlock_irqrestore(&dev->spinlock, flags);
return -1;
}
devpriv->write_byte(devpriv->command2_bits, dev->iobase + COMMAND2_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
return 0;
}
static irqreturn_t labpc_interrupt(int irq, void *d)
{
struct comedi_device *dev = d;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async;
struct comedi_cmd *cmd;
if (dev->attached == 0) {
comedi_error(dev, "premature interrupt");
return IRQ_HANDLED;
}
async = s->async;
cmd = &async->cmd;
async->events = 0;
devpriv->status1_bits = devpriv->read_byte(dev->iobase + STATUS1_REG);
if (thisboard->register_layout == labpc_1200_layout)
devpriv->status2_bits =
devpriv->read_byte(dev->iobase + STATUS2_REG);
if ((devpriv->status1_bits & (DMATC_BIT | TIMER_BIT | OVERFLOW_BIT |
OVERRUN_BIT | DATA_AVAIL_BIT)) == 0
&& (devpriv->status2_bits & A1_TC_BIT) == 0
&& (devpriv->status2_bits & FNHF_BIT)) {
return IRQ_NONE;
}
if (devpriv->status1_bits & OVERRUN_BIT) {
devpriv->write_byte(0x1, dev->iobase + ADC_CLEAR_REG);
async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
comedi_event(dev, s);
comedi_error(dev, "overrun");
return IRQ_HANDLED;
}
#ifdef CONFIG_ISA_DMA_API
if (devpriv->current_transfer == isa_dma_transfer) {
if (devpriv->status1_bits & DMATC_BIT ||
(thisboard->register_layout == labpc_1200_layout
&& devpriv->status2_bits & A1_TC_BIT)) {
handle_isa_dma(dev);
}
} else
#endif
labpc_drain_fifo(dev);
if (devpriv->status1_bits & TIMER_BIT) {
comedi_error(dev, "handled timer interrupt?");
devpriv->write_byte(0x1, dev->iobase + TIMER_CLEAR_REG);
}
if (devpriv->status1_bits & OVERFLOW_BIT) {
devpriv->write_byte(0x1, dev->iobase + ADC_CLEAR_REG);
async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
comedi_event(dev, s);
comedi_error(dev, "overflow");
return IRQ_HANDLED;
}
if (cmd->stop_src == TRIG_EXT) {
if (devpriv->status2_bits & A1_TC_BIT) {
labpc_drain_dregs(dev);
labpc_cancel(dev, s);
async->events |= COMEDI_CB_EOA;
}
}
if (cmd->stop_src == TRIG_COUNT) {
if (devpriv->count == 0) {
labpc_cancel(dev, s);
async->events |= COMEDI_CB_EOA;
}
}
comedi_event(dev, s);
return IRQ_HANDLED;
}
static int labpc_drain_fifo(struct comedi_device *dev)
{
unsigned int lsb, msb;
short data;
struct comedi_async *async = dev->read_subdev->async;
const int timeout = 10000;
unsigned int i;
devpriv->status1_bits = devpriv->read_byte(dev->iobase + STATUS1_REG);
for (i = 0; (devpriv->status1_bits & DATA_AVAIL_BIT) && i < timeout;
i++) {
if (async->cmd.stop_src == TRIG_COUNT) {
if (devpriv->count == 0)
break;
devpriv->count--;
}
lsb = devpriv->read_byte(dev->iobase + ADC_FIFO_REG);
msb = devpriv->read_byte(dev->iobase + ADC_FIFO_REG);
data = (msb << 8) | lsb;
cfc_write_to_buffer(dev->read_subdev, data);
devpriv->status1_bits =
devpriv->read_byte(dev->iobase + STATUS1_REG);
}
if (i == timeout) {
comedi_error(dev, "ai timeout, fifo never empties");
async->events |= COMEDI_CB_ERROR | COMEDI_CB_EOA;
return -1;
}
return 0;
}
static void labpc_drain_dma(struct comedi_device *dev)
{
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
int status;
unsigned long flags;
unsigned int max_points, num_points, residue, leftover;
int i;
status = devpriv->status1_bits;
flags = claim_dma_lock();
disable_dma(devpriv->dma_chan);
clear_dma_ff(devpriv->dma_chan);
max_points = devpriv->dma_transfer_size / sample_size;
residue = get_dma_residue(devpriv->dma_chan) / sample_size;
num_points = max_points - residue;
if (devpriv->count < num_points && async->cmd.stop_src == TRIG_COUNT)
num_points = devpriv->count;
leftover = 0;
if (async->cmd.stop_src != TRIG_COUNT) {
leftover = devpriv->dma_transfer_size / sample_size;
} else if (devpriv->count > num_points) {
leftover = devpriv->count - num_points;
if (leftover > max_points)
leftover = max_points;
}
for (i = 0; i < num_points; i++)
cfc_write_to_buffer(s, devpriv->dma_buffer[i]);
if (async->cmd.stop_src == TRIG_COUNT)
devpriv->count -= num_points;
set_dma_addr(devpriv->dma_chan, virt_to_bus(devpriv->dma_buffer));
set_dma_count(devpriv->dma_chan, leftover * sample_size);
release_dma_lock(flags);
async->events |= COMEDI_CB_BLOCK;
}
static void handle_isa_dma(struct comedi_device *dev)
{
labpc_drain_dma(dev);
enable_dma(devpriv->dma_chan);
devpriv->write_byte(0x1, dev->iobase + DMATC_CLEAR_REG);
}
static void labpc_drain_dregs(struct comedi_device *dev)
{
#ifdef CONFIG_ISA_DMA_API
if (devpriv->current_transfer == isa_dma_transfer)
labpc_drain_dma(dev);
#endif
labpc_drain_fifo(dev);
}
static int labpc_ai_rinsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int i, n;
int chan, range;
int lsb, msb;
int timeout = 1000;
unsigned long flags;
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->command2_bits &= ~SWTRIG_BIT & ~HWTRIG_BIT & ~PRETRIG_BIT;
devpriv->write_byte(devpriv->command2_bits, dev->iobase + COMMAND2_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
devpriv->command3_bits = 0;
devpriv->write_byte(devpriv->command3_bits, dev->iobase + COMMAND3_REG);
devpriv->command1_bits = 0;
chan = CR_CHAN(insn->chanspec);
range = CR_RANGE(insn->chanspec);
devpriv->command1_bits |= thisboard->ai_range_code[range];
if (CR_AREF(insn->chanspec) == AREF_DIFF)
chan *= 2;
devpriv->command1_bits |= ADC_CHAN_BITS(chan);
devpriv->write_byte(devpriv->command1_bits, dev->iobase + COMMAND1_REG);
if (thisboard->register_layout == labpc_1200_layout) {
if (CR_AREF(insn->chanspec) != AREF_GROUND)
devpriv->command6_bits |= ADC_COMMON_BIT;
else
devpriv->command6_bits &= ~ADC_COMMON_BIT;
if (thisboard->ai_range_is_unipolar[range])
devpriv->command6_bits |= ADC_UNIP_BIT;
else
devpriv->command6_bits &= ~ADC_UNIP_BIT;
devpriv->command6_bits &= ~ADC_FHF_INTR_EN_BIT;
devpriv->command6_bits &= ~A1_INTR_EN_BIT;
devpriv->write_byte(devpriv->command6_bits,
dev->iobase + COMMAND6_REG);
}
devpriv->command4_bits = 0;
devpriv->command4_bits |= EXT_CONVERT_DISABLE_BIT;
if (CR_AREF(insn->chanspec) == AREF_DIFF)
devpriv->command4_bits |= ADC_DIFF_BIT;
devpriv->write_byte(devpriv->command4_bits, dev->iobase + COMMAND4_REG);
devpriv->write_byte(INIT_A0_BITS, dev->iobase + COUNTER_A_CONTROL_REG);
labpc_clear_adc_fifo(dev);
for (n = 0; n < insn->n; n++) {
devpriv->write_byte(0x1, dev->iobase + ADC_CONVERT_REG);
for (i = 0; i < timeout; i++) {
if (devpriv->read_byte(dev->iobase +
STATUS1_REG) & DATA_AVAIL_BIT)
break;
udelay(1);
}
if (i == timeout) {
comedi_error(dev, "timeout");
return -ETIME;
}
lsb = devpriv->read_byte(dev->iobase + ADC_FIFO_REG);
msb = devpriv->read_byte(dev->iobase + ADC_FIFO_REG);
data[n] = (msb << 8) | lsb;
}
return n;
}
static int labpc_ao_winsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int channel, range;
unsigned long flags;
int lsb, msb;
channel = CR_CHAN(insn->chanspec);
spin_lock_irqsave(&dev->spinlock, flags);
devpriv->command2_bits &= ~DAC_PACED_BIT(channel);
devpriv->write_byte(devpriv->command2_bits, dev->iobase + COMMAND2_REG);
spin_unlock_irqrestore(&dev->spinlock, flags);
if (thisboard->register_layout == labpc_1200_layout) {
range = CR_RANGE(insn->chanspec);
if (range & AO_RANGE_IS_UNIPOLAR)
devpriv->command6_bits |= DAC_UNIP_BIT(channel);
else
devpriv->command6_bits &= ~DAC_UNIP_BIT(channel);
devpriv->write_byte(devpriv->command6_bits,
dev->iobase + COMMAND6_REG);
}
lsb = data[0] & 0xff;
msb = (data[0] >> 8) & 0xff;
devpriv->write_byte(lsb, dev->iobase + DAC_LSB_REG(channel));
devpriv->write_byte(msb, dev->iobase + DAC_MSB_REG(channel));
devpriv->ao_value[channel] = data[0];
return 1;
}
static int labpc_ao_rinsn(struct comedi_device *dev, struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[0] = devpriv->ao_value[CR_CHAN(insn->chanspec)];
return 1;
}
static int labpc_calib_read_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[0] = devpriv->caldac[CR_CHAN(insn->chanspec)];
return 1;
}
static int labpc_calib_write_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int channel = CR_CHAN(insn->chanspec);
write_caldac(dev, channel, data[0]);
return 1;
}
static int labpc_eeprom_read_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
data[0] = devpriv->eeprom_data[CR_CHAN(insn->chanspec)];
return 1;
}
static int labpc_eeprom_write_insn(struct comedi_device *dev,
struct comedi_subdevice *s,
struct comedi_insn *insn, unsigned int *data)
{
int channel = CR_CHAN(insn->chanspec);
int ret;
if (channel < 16 || channel > 127) {
printk
("eeprom writes are only allowed to channels 16 through 127 (the pointer and user areas)");
return -EINVAL;
}
ret = labpc_eeprom_write(dev, channel, data[0]);
if (ret < 0)
return ret;
return 1;
}
static unsigned int labpc_suggest_transfer_size(struct comedi_cmd cmd)
{
unsigned int size;
unsigned int freq;
if (cmd.convert_src == TRIG_TIMER)
freq = 1000000000 / cmd.convert_arg;
else
freq = 0xffffffff;
size = (freq / 3) * sample_size;
if (size > dma_buffer_size)
size = dma_buffer_size - dma_buffer_size % sample_size;
else if (size < sample_size)
size = sample_size;
return size;
}
static void labpc_adc_timing(struct comedi_device *dev, struct comedi_cmd *cmd)
{
const int max_counter_value = 0x10000;
const int min_counter_value = 2;
unsigned int base_period;
if (labpc_ai_convert_period(cmd) && labpc_ai_scan_period(cmd)) {
devpriv->divisor_b0 = (labpc_ai_scan_period(cmd) - 1) /
(LABPC_TIMER_BASE * max_counter_value) + 1;
if (devpriv->divisor_b0 < min_counter_value)
devpriv->divisor_b0 = min_counter_value;
if (devpriv->divisor_b0 > max_counter_value)
devpriv->divisor_b0 = max_counter_value;
base_period = LABPC_TIMER_BASE * devpriv->divisor_b0;
switch (cmd->flags & TRIG_ROUND_MASK) {
default:
case TRIG_ROUND_NEAREST:
devpriv->divisor_a0 =
(labpc_ai_convert_period(cmd) +
(base_period / 2)) / base_period;
devpriv->divisor_b1 =
(labpc_ai_scan_period(cmd) +
(base_period / 2)) / base_period;
break;
case TRIG_ROUND_UP:
devpriv->divisor_a0 =
(labpc_ai_convert_period(cmd) + (base_period -
1)) / base_period;
devpriv->divisor_b1 =
(labpc_ai_scan_period(cmd) + (base_period -
1)) / base_period;
break;
case TRIG_ROUND_DOWN:
devpriv->divisor_a0 =
labpc_ai_convert_period(cmd) / base_period;
devpriv->divisor_b1 =
labpc_ai_scan_period(cmd) / base_period;
break;
}
if (devpriv->divisor_a0 < min_counter_value)
devpriv->divisor_a0 = min_counter_value;
if (devpriv->divisor_a0 > max_counter_value)
devpriv->divisor_a0 = max_counter_value;
if (devpriv->divisor_b1 < min_counter_value)
devpriv->divisor_b1 = min_counter_value;
if (devpriv->divisor_b1 > max_counter_value)
devpriv->divisor_b1 = max_counter_value;
labpc_set_ai_convert_period(cmd,
base_period * devpriv->divisor_a0);
labpc_set_ai_scan_period(cmd,
base_period * devpriv->divisor_b1);
} else if (labpc_ai_scan_period(cmd)) {
unsigned int scan_period;
scan_period = labpc_ai_scan_period(cmd);
i8253_cascade_ns_to_timer_2div(LABPC_TIMER_BASE,
&(devpriv->divisor_b1),
&(devpriv->divisor_b0),
&scan_period,
cmd->flags & TRIG_ROUND_MASK);
labpc_set_ai_scan_period(cmd, scan_period);
} else if (labpc_ai_convert_period(cmd)) {
unsigned int convert_period;
convert_period = labpc_ai_convert_period(cmd);
i8253_cascade_ns_to_timer_2div(LABPC_TIMER_BASE,
&(devpriv->divisor_a0),
&(devpriv->divisor_b0),
&convert_period,
cmd->flags & TRIG_ROUND_MASK);
labpc_set_ai_convert_period(cmd, convert_period);
}
}
static int labpc_dio_mem_callback(int dir, int port, int data,
unsigned long iobase)
{
if (dir) {
writeb(data, (void *)(iobase + port));
return 0;
} else {
return readb((void *)(iobase + port));
}
}
static void labpc_serial_out(struct comedi_device *dev, unsigned int value,
unsigned int value_width)
{
int i;
for (i = 1; i <= value_width; i++) {
devpriv->command5_bits &= ~SCLOCK_BIT;
if (value & (1 << (value_width - i)))
devpriv->command5_bits |= SDATA_BIT;
else
devpriv->command5_bits &= ~SDATA_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits,
dev->iobase + COMMAND5_REG);
devpriv->command5_bits |= SCLOCK_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits,
dev->iobase + COMMAND5_REG);
}
}
static unsigned int labpc_serial_in(struct comedi_device *dev)
{
unsigned int value = 0;
int i;
const int value_width = 8;
for (i = 1; i <= value_width; i++) {
devpriv->command5_bits |= SCLOCK_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits,
dev->iobase + COMMAND5_REG);
devpriv->command5_bits &= ~SCLOCK_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits,
dev->iobase + COMMAND5_REG);
udelay(1);
devpriv->status2_bits =
devpriv->read_byte(dev->iobase + STATUS2_REG);
if (devpriv->status2_bits & EEPROM_OUT_BIT)
value |= 1 << (value_width - i);
}
return value;
}
static unsigned int labpc_eeprom_read(struct comedi_device *dev,
unsigned int address)
{
unsigned int value;
const int read_instruction = 0x3;
const int write_length = 8;
devpriv->command5_bits &= ~EEPROM_EN_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits, dev->iobase + COMMAND5_REG);
devpriv->command5_bits |= EEPROM_EN_BIT | EEPROM_WRITE_UNPROTECT_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits, dev->iobase + COMMAND5_REG);
labpc_serial_out(dev, read_instruction, write_length);
labpc_serial_out(dev, address, write_length);
value = labpc_serial_in(dev);
devpriv->command5_bits &= ~EEPROM_EN_BIT & ~EEPROM_WRITE_UNPROTECT_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits, dev->iobase + COMMAND5_REG);
return value;
}
static int labpc_eeprom_write(struct comedi_device *dev,
unsigned int address, unsigned int value)
{
const int write_enable_instruction = 0x6;
const int write_instruction = 0x2;
const int write_length = 8;
const int write_in_progress_bit = 0x1;
const int timeout = 10000;
int i;
for (i = 0; i < timeout; i++) {
if ((labpc_eeprom_read_status(dev) & write_in_progress_bit) ==
0)
break;
}
if (i == timeout) {
comedi_error(dev, "eeprom write timed out");
return -ETIME;
}
devpriv->eeprom_data[address] = value;
devpriv->command5_bits &= ~EEPROM_EN_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits, dev->iobase + COMMAND5_REG);
devpriv->command5_bits |= EEPROM_EN_BIT | EEPROM_WRITE_UNPROTECT_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits, dev->iobase + COMMAND5_REG);
labpc_serial_out(dev, write_enable_instruction, write_length);
devpriv->command5_bits &= ~EEPROM_EN_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits, dev->iobase + COMMAND5_REG);
devpriv->command5_bits |= EEPROM_EN_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits, dev->iobase + COMMAND5_REG);
labpc_serial_out(dev, write_instruction, write_length);
labpc_serial_out(dev, address, write_length);
labpc_serial_out(dev, value, write_length);
devpriv->command5_bits &= ~EEPROM_EN_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits, dev->iobase + COMMAND5_REG);
devpriv->command5_bits &= ~EEPROM_EN_BIT & ~EEPROM_WRITE_UNPROTECT_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits, dev->iobase + COMMAND5_REG);
return 0;
}
static unsigned int labpc_eeprom_read_status(struct comedi_device *dev)
{
unsigned int value;
const int read_status_instruction = 0x5;
const int write_length = 8;
devpriv->command5_bits &= ~EEPROM_EN_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits, dev->iobase + COMMAND5_REG);
devpriv->command5_bits |= EEPROM_EN_BIT | EEPROM_WRITE_UNPROTECT_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits, dev->iobase + COMMAND5_REG);
labpc_serial_out(dev, read_status_instruction, write_length);
value = labpc_serial_in(dev);
devpriv->command5_bits &= ~EEPROM_EN_BIT & ~EEPROM_WRITE_UNPROTECT_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits, dev->iobase + COMMAND5_REG);
return value;
}
static void write_caldac(struct comedi_device *dev, unsigned int channel,
unsigned int value)
{
if (value == devpriv->caldac[channel])
return;
devpriv->caldac[channel] = value;
devpriv->command5_bits &=
~CALDAC_LOAD_BIT & ~EEPROM_EN_BIT & ~EEPROM_WRITE_UNPROTECT_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits, dev->iobase + COMMAND5_REG);
labpc_serial_out(dev, channel, 4);
labpc_serial_out(dev, value, 8);
devpriv->command5_bits |= CALDAC_LOAD_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits, dev->iobase + COMMAND5_REG);
devpriv->command5_bits &= ~CALDAC_LOAD_BIT;
udelay(1);
devpriv->write_byte(devpriv->command5_bits, dev->iobase + COMMAND5_REG);
}
static int __devinit driver_labpc_pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
return comedi_pci_auto_config(dev, &driver_labpc);
}
static void __devexit driver_labpc_pci_remove(struct pci_dev *dev)
{
comedi_pci_auto_unconfig(dev);
}
static int __init driver_labpc_init_module(void)
{
int retval;
retval = comedi_driver_register(&driver_labpc);
if (retval < 0)
return retval;
driver_labpc_pci_driver.name = (char *)driver_labpc.driver_name;
return pci_register_driver(&driver_labpc_pci_driver);
}
static void __exit driver_labpc_cleanup_module(void)
{
pci_unregister_driver(&driver_labpc_pci_driver);
comedi_driver_unregister(&driver_labpc);
}
static int __init driver_labpc_init_module(void)
{
return comedi_driver_register(&driver_labpc);
}
static void __exit driver_labpc_cleanup_module(void)
{
comedi_driver_unregister(&driver_labpc);
}
