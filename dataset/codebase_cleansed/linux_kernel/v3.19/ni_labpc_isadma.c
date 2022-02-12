static unsigned int labpc_suggest_transfer_size(const struct comedi_cmd *cmd)
{
unsigned int size;
unsigned int freq;
if (cmd->convert_src == TRIG_TIMER)
freq = 1000000000 / cmd->convert_arg;
else
freq = 0xffffffff;
size = (freq / 3) * sample_size;
if (size > dma_buffer_size)
size = dma_buffer_size - dma_buffer_size % sample_size;
else if (size < sample_size)
size = sample_size;
return size;
}
void labpc_setup_dma(struct comedi_device *dev, struct comedi_subdevice *s)
{
struct labpc_private *devpriv = dev->private;
struct comedi_cmd *cmd = &s->async->cmd;
unsigned long irq_flags;
irq_flags = claim_dma_lock();
disable_dma(devpriv->dma_chan);
clear_dma_ff(devpriv->dma_chan);
set_dma_addr(devpriv->dma_chan, devpriv->dma_addr);
devpriv->dma_transfer_size = labpc_suggest_transfer_size(cmd);
if (cmd->stop_src == TRIG_COUNT &&
devpriv->count * sample_size < devpriv->dma_transfer_size)
devpriv->dma_transfer_size = devpriv->count * sample_size;
set_dma_count(devpriv->dma_chan, devpriv->dma_transfer_size);
enable_dma(devpriv->dma_chan);
release_dma_lock(irq_flags);
devpriv->cmd3 |= (CMD3_DMAEN | CMD3_DMATCINTEN);
}
void labpc_drain_dma(struct comedi_device *dev)
{
struct labpc_private *devpriv = dev->private;
struct comedi_subdevice *s = dev->read_subdev;
struct comedi_async *async = s->async;
struct comedi_cmd *cmd = &async->cmd;
int status;
unsigned long flags;
unsigned int max_points, num_points, residue, leftover;
status = devpriv->stat1;
flags = claim_dma_lock();
disable_dma(devpriv->dma_chan);
clear_dma_ff(devpriv->dma_chan);
max_points = devpriv->dma_transfer_size / sample_size;
residue = get_dma_residue(devpriv->dma_chan) / sample_size;
num_points = max_points - residue;
if (cmd->stop_src == TRIG_COUNT && devpriv->count < num_points)
num_points = devpriv->count;
leftover = 0;
if (cmd->stop_src != TRIG_COUNT) {
leftover = devpriv->dma_transfer_size / sample_size;
} else if (devpriv->count > num_points) {
leftover = devpriv->count - num_points;
if (leftover > max_points)
leftover = max_points;
}
comedi_buf_write_samples(s, devpriv->dma_buffer, num_points);
if (cmd->stop_src == TRIG_COUNT)
devpriv->count -= num_points;
set_dma_addr(devpriv->dma_chan, devpriv->dma_addr);
set_dma_count(devpriv->dma_chan, leftover * sample_size);
release_dma_lock(flags);
}
static void handle_isa_dma(struct comedi_device *dev)
{
struct labpc_private *devpriv = dev->private;
labpc_drain_dma(dev);
enable_dma(devpriv->dma_chan);
devpriv->write_byte(dev, 0x1, DMATC_CLEAR_REG);
}
void labpc_handle_dma_status(struct comedi_device *dev)
{
const struct labpc_boardinfo *board = dev->board_ptr;
struct labpc_private *devpriv = dev->private;
if (devpriv->stat1 & STAT1_GATA0 ||
(board->is_labpc1200 && devpriv->stat2 & STAT2_OUTA1))
handle_isa_dma(dev);
}
int labpc_init_dma_chan(struct comedi_device *dev, unsigned int dma_chan)
{
struct labpc_private *devpriv = dev->private;
void *dma_buffer;
unsigned long dma_flags;
int ret;
if (dma_chan != 1 && dma_chan != 3)
return -EINVAL;
dma_buffer = kmalloc(dma_buffer_size, GFP_KERNEL | GFP_DMA);
if (!dma_buffer)
return -ENOMEM;
ret = request_dma(dma_chan, dev->board_name);
if (ret) {
kfree(dma_buffer);
return ret;
}
devpriv->dma_buffer = dma_buffer;
devpriv->dma_chan = dma_chan;
devpriv->dma_addr = virt_to_bus(devpriv->dma_buffer);
dma_flags = claim_dma_lock();
disable_dma(devpriv->dma_chan);
set_dma_mode(devpriv->dma_chan, DMA_MODE_READ);
release_dma_lock(dma_flags);
return 0;
}
void labpc_free_dma_chan(struct comedi_device *dev)
{
struct labpc_private *devpriv = dev->private;
kfree(devpriv->dma_buffer);
devpriv->dma_buffer = NULL;
if (devpriv->dma_chan) {
free_dma(devpriv->dma_chan);
devpriv->dma_chan = 0;
}
}
static int __init ni_labpc_isadma_init_module(void)
{
return 0;
}
static void __exit ni_labpc_isadma_cleanup_module(void)
{
}
