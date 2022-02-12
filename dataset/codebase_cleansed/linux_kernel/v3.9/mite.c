struct mite_struct *mite_alloc(struct pci_dev *pcidev)
{
struct mite_struct *mite;
unsigned int i;
mite = kzalloc(sizeof(*mite), GFP_KERNEL);
if (mite) {
spin_lock_init(&mite->lock);
mite->pcidev = pcidev;
for (i = 0; i < MAX_MITE_DMA_CHANNELS; ++i) {
mite->channels[i].mite = mite;
mite->channels[i].channel = i;
mite->channels[i].done = 1;
}
}
return mite;
}
static void dump_chip_signature(u32 csigr_bits)
{
pr_info("version = %i, type = %i, mite mode = %i, interface mode = %i\n",
mite_csigr_version(csigr_bits), mite_csigr_type(csigr_bits),
mite_csigr_mmode(csigr_bits), mite_csigr_imode(csigr_bits));
pr_info("num channels = %i, write post fifo depth = %i, wins = %i, iowins = %i\n",
mite_csigr_dmac(csigr_bits), mite_csigr_wpdep(csigr_bits),
mite_csigr_wins(csigr_bits), mite_csigr_iowins(csigr_bits));
}
static unsigned mite_fifo_size(struct mite_struct *mite, unsigned channel)
{
unsigned fcr_bits = readl(mite->mite_io_addr + MITE_FCR(channel));
unsigned empty_count = (fcr_bits >> 16) & 0xff;
unsigned full_count = fcr_bits & 0xff;
return empty_count + full_count;
}
int mite_setup2(struct mite_struct *mite, unsigned use_iodwbsr_1)
{
unsigned long length;
resource_size_t addr;
int i;
u32 csigr_bits;
unsigned unknown_dma_burst_bits;
if (comedi_pci_enable(mite->pcidev, "mite")) {
dev_err(&mite->pcidev->dev,
"error enabling mite and requesting io regions\n");
return -EIO;
}
pci_set_master(mite->pcidev);
addr = pci_resource_start(mite->pcidev, 0);
mite->mite_phys_addr = addr;
mite->mite_io_addr = ioremap(addr, PCI_MITE_SIZE);
if (!mite->mite_io_addr) {
dev_err(&mite->pcidev->dev,
"Failed to remap mite io memory address\n");
return -ENOMEM;
}
addr = pci_resource_start(mite->pcidev, 1);
mite->daq_phys_addr = addr;
length = pci_resource_len(mite->pcidev, 1);
mite->daq_io_addr = ioremap(mite->daq_phys_addr, length);
if (!mite->daq_io_addr) {
dev_err(&mite->pcidev->dev,
"Failed to remap daq io memory address\n");
return -ENOMEM;
}
if (use_iodwbsr_1) {
writel(0, mite->mite_io_addr + MITE_IODWBSR);
dev_info(&mite->pcidev->dev,
"using I/O Window Base Size register 1\n");
writel(mite->daq_phys_addr | WENAB |
MITE_IODWBSR_1_WSIZE_bits(length),
mite->mite_io_addr + MITE_IODWBSR_1);
writel(0, mite->mite_io_addr + MITE_IODWCR_1);
} else {
writel(mite->daq_phys_addr | WENAB,
mite->mite_io_addr + MITE_IODWBSR);
}
unknown_dma_burst_bits =
readl(mite->mite_io_addr + MITE_UNKNOWN_DMA_BURST_REG);
unknown_dma_burst_bits |= UNKNOWN_DMA_BURST_ENABLE_BITS;
writel(unknown_dma_burst_bits,
mite->mite_io_addr + MITE_UNKNOWN_DMA_BURST_REG);
csigr_bits = readl(mite->mite_io_addr + MITE_CSIGR);
mite->num_channels = mite_csigr_dmac(csigr_bits);
if (mite->num_channels > MAX_MITE_DMA_CHANNELS) {
dev_warn(&mite->pcidev->dev,
"mite: bug? chip claims to have %i dma channels. Setting to %i.\n",
mite->num_channels, MAX_MITE_DMA_CHANNELS);
mite->num_channels = MAX_MITE_DMA_CHANNELS;
}
dump_chip_signature(csigr_bits);
for (i = 0; i < mite->num_channels; i++) {
writel(CHOR_DMARESET, mite->mite_io_addr + MITE_CHOR(i));
writel(CHCR_CLR_DMA_IE | CHCR_CLR_LINKP_IE | CHCR_CLR_SAR_IE |
CHCR_CLR_DONE_IE | CHCR_CLR_MRDY_IE | CHCR_CLR_DRDY_IE |
CHCR_CLR_LC_IE | CHCR_CLR_CONT_RB_IE,
mite->mite_io_addr + MITE_CHCR(i));
}
mite->fifo_size = mite_fifo_size(mite, 0);
dev_info(&mite->pcidev->dev, "fifo size is %i.\n", mite->fifo_size);
return 0;
}
int mite_setup(struct mite_struct *mite)
{
return mite_setup2(mite, 0);
}
void mite_unsetup(struct mite_struct *mite)
{
if (!mite)
return;
if (mite->mite_io_addr) {
iounmap(mite->mite_io_addr);
mite->mite_io_addr = NULL;
}
if (mite->daq_io_addr) {
iounmap(mite->daq_io_addr);
mite->daq_io_addr = NULL;
}
if (mite->mite_phys_addr) {
comedi_pci_disable(mite->pcidev);
mite->mite_phys_addr = 0;
}
}
struct mite_dma_descriptor_ring *mite_alloc_ring(struct mite_struct *mite)
{
struct mite_dma_descriptor_ring *ring =
kmalloc(sizeof(struct mite_dma_descriptor_ring), GFP_KERNEL);
if (ring == NULL)
return ring;
ring->hw_dev = get_device(&mite->pcidev->dev);
if (ring->hw_dev == NULL) {
kfree(ring);
return NULL;
}
ring->n_links = 0;
ring->descriptors = NULL;
ring->descriptors_dma_addr = 0;
return ring;
}
void mite_free_ring(struct mite_dma_descriptor_ring *ring)
{
if (ring) {
if (ring->descriptors) {
dma_free_coherent(ring->hw_dev,
ring->n_links *
sizeof(struct mite_dma_descriptor),
ring->descriptors,
ring->descriptors_dma_addr);
}
put_device(ring->hw_dev);
kfree(ring);
}
}
struct mite_channel *mite_request_channel_in_range(struct mite_struct *mite,
struct
mite_dma_descriptor_ring
*ring, unsigned min_channel,
unsigned max_channel)
{
int i;
unsigned long flags;
struct mite_channel *channel = NULL;
spin_lock_irqsave(&mite->lock, flags);
for (i = min_channel; i <= max_channel; ++i) {
if (mite->channel_allocated[i] == 0) {
mite->channel_allocated[i] = 1;
channel = &mite->channels[i];
channel->ring = ring;
break;
}
}
spin_unlock_irqrestore(&mite->lock, flags);
return channel;
}
void mite_release_channel(struct mite_channel *mite_chan)
{
struct mite_struct *mite = mite_chan->mite;
unsigned long flags;
spin_lock_irqsave(&mite->lock, flags);
if (mite->channel_allocated[mite_chan->channel]) {
mite_dma_disarm(mite_chan);
mite_dma_reset(mite_chan);
writel(CHCR_CLR_DMA_IE | CHCR_CLR_LINKP_IE |
CHCR_CLR_SAR_IE | CHCR_CLR_DONE_IE |
CHCR_CLR_MRDY_IE | CHCR_CLR_DRDY_IE |
CHCR_CLR_LC_IE | CHCR_CLR_CONT_RB_IE,
mite->mite_io_addr + MITE_CHCR(mite_chan->channel));
mite->channel_allocated[mite_chan->channel] = 0;
mite_chan->ring = NULL;
mmiowb();
}
spin_unlock_irqrestore(&mite->lock, flags);
}
void mite_dma_arm(struct mite_channel *mite_chan)
{
struct mite_struct *mite = mite_chan->mite;
int chor;
unsigned long flags;
MDPRINTK("mite_dma_arm ch%i\n", mite_chan->channel);
smp_mb();
chor = CHOR_START;
spin_lock_irqsave(&mite->lock, flags);
mite_chan->done = 0;
writel(chor, mite->mite_io_addr + MITE_CHOR(mite_chan->channel));
mmiowb();
spin_unlock_irqrestore(&mite->lock, flags);
}
int mite_buf_change(struct mite_dma_descriptor_ring *ring,
struct comedi_async *async)
{
unsigned int n_links;
int i;
if (ring->descriptors) {
dma_free_coherent(ring->hw_dev,
ring->n_links *
sizeof(struct mite_dma_descriptor),
ring->descriptors,
ring->descriptors_dma_addr);
}
ring->descriptors = NULL;
ring->descriptors_dma_addr = 0;
ring->n_links = 0;
if (async->prealloc_bufsz == 0)
return 0;
n_links = async->prealloc_bufsz >> PAGE_SHIFT;
MDPRINTK("ring->hw_dev=%p, n_links=0x%04x\n", ring->hw_dev, n_links);
ring->descriptors =
dma_alloc_coherent(ring->hw_dev,
n_links * sizeof(struct mite_dma_descriptor),
&ring->descriptors_dma_addr, GFP_KERNEL);
if (!ring->descriptors) {
dev_err(async->subdevice->device->class_dev,
"mite: ring buffer allocation failed\n");
return -ENOMEM;
}
ring->n_links = n_links;
for (i = 0; i < n_links; i++) {
ring->descriptors[i].count = cpu_to_le32(PAGE_SIZE);
ring->descriptors[i].addr =
cpu_to_le32(async->buf_page_list[i].dma_addr);
ring->descriptors[i].next =
cpu_to_le32(ring->descriptors_dma_addr + (i +
1) *
sizeof(struct mite_dma_descriptor));
}
ring->descriptors[n_links - 1].next =
cpu_to_le32(ring->descriptors_dma_addr);
smp_wmb();
return 0;
}
void mite_prep_dma(struct mite_channel *mite_chan,
unsigned int num_device_bits, unsigned int num_memory_bits)
{
unsigned int chor, chcr, mcr, dcr, lkcr;
struct mite_struct *mite = mite_chan->mite;
MDPRINTK("mite_prep_dma ch%i\n", mite_chan->channel);
chor = CHOR_DMARESET | CHOR_FRESET;
writel(chor, mite->mite_io_addr + MITE_CHOR(mite_chan->channel));
chcr = CHCR_SET_DMA_IE | CHCR_LINKSHORT | CHCR_SET_DONE_IE |
CHCR_BURSTEN;
chcr |= CHCR_SET_LC_IE;
if (num_memory_bits == 32 && num_device_bits == 16) {
chcr |= CHCR_BYTE_SWAP_DEVICE | CHCR_BYTE_SWAP_MEMORY;
}
if (mite_chan->dir == COMEDI_INPUT)
chcr |= CHCR_DEV_TO_MEM;
writel(chcr, mite->mite_io_addr + MITE_CHCR(mite_chan->channel));
mcr = CR_RL(64) | CR_ASEQUP;
switch (num_memory_bits) {
case 8:
mcr |= CR_PSIZE8;
break;
case 16:
mcr |= CR_PSIZE16;
break;
case 32:
mcr |= CR_PSIZE32;
break;
default:
pr_warn("bug! invalid mem bit width for dma transfer\n");
break;
}
writel(mcr, mite->mite_io_addr + MITE_MCR(mite_chan->channel));
dcr = CR_RL(64) | CR_ASEQUP;
dcr |= CR_PORTIO | CR_AMDEVICE | CR_REQSDRQ(mite_chan->channel);
switch (num_device_bits) {
case 8:
dcr |= CR_PSIZE8;
break;
case 16:
dcr |= CR_PSIZE16;
break;
case 32:
dcr |= CR_PSIZE32;
break;
default:
pr_warn("bug! invalid dev bit width for dma transfer\n");
break;
}
writel(dcr, mite->mite_io_addr + MITE_DCR(mite_chan->channel));
writel(0, mite->mite_io_addr + MITE_DAR(mite_chan->channel));
lkcr = CR_RL(64) | CR_ASEQUP | CR_PSIZE32;
writel(lkcr, mite->mite_io_addr + MITE_LKCR(mite_chan->channel));
writel(mite_chan->ring->descriptors_dma_addr,
mite->mite_io_addr + MITE_LKAR(mite_chan->channel));
MDPRINTK("exit mite_prep_dma\n");
}
static u32 mite_device_bytes_transferred(struct mite_channel *mite_chan)
{
struct mite_struct *mite = mite_chan->mite;
return readl(mite->mite_io_addr + MITE_DAR(mite_chan->channel));
}
u32 mite_bytes_in_transit(struct mite_channel *mite_chan)
{
struct mite_struct *mite = mite_chan->mite;
return readl(mite->mite_io_addr +
MITE_FCR(mite_chan->channel)) & 0x000000FF;
}
u32 mite_bytes_written_to_memory_lb(struct mite_channel *mite_chan)
{
u32 device_byte_count;
device_byte_count = mite_device_bytes_transferred(mite_chan);
return device_byte_count - mite_bytes_in_transit(mite_chan);
}
u32 mite_bytes_written_to_memory_ub(struct mite_channel *mite_chan)
{
u32 in_transit_count;
in_transit_count = mite_bytes_in_transit(mite_chan);
return mite_device_bytes_transferred(mite_chan) - in_transit_count;
}
u32 mite_bytes_read_from_memory_lb(struct mite_channel *mite_chan)
{
u32 device_byte_count;
device_byte_count = mite_device_bytes_transferred(mite_chan);
return device_byte_count + mite_bytes_in_transit(mite_chan);
}
u32 mite_bytes_read_from_memory_ub(struct mite_channel *mite_chan)
{
u32 in_transit_count;
in_transit_count = mite_bytes_in_transit(mite_chan);
return mite_device_bytes_transferred(mite_chan) + in_transit_count;
}
unsigned mite_dma_tcr(struct mite_channel *mite_chan)
{
struct mite_struct *mite = mite_chan->mite;
int tcr;
int lkar;
lkar = readl(mite->mite_io_addr + MITE_LKAR(mite_chan->channel));
tcr = readl(mite->mite_io_addr + MITE_TCR(mite_chan->channel));
MDPRINTK("mite_dma_tcr ch%i, lkar=0x%08x tcr=%d\n", mite_chan->channel,
lkar, tcr);
return tcr;
}
void mite_dma_disarm(struct mite_channel *mite_chan)
{
struct mite_struct *mite = mite_chan->mite;
unsigned chor;
chor = CHOR_ABORT;
writel(chor, mite->mite_io_addr + MITE_CHOR(mite_chan->channel));
}
int mite_sync_input_dma(struct mite_channel *mite_chan,
struct comedi_async *async)
{
int count;
unsigned int nbytes, old_alloc_count;
const unsigned bytes_per_scan = cfc_bytes_per_scan(async->subdevice);
old_alloc_count = async->buf_write_alloc_count;
comedi_buf_write_alloc(async, async->prealloc_bufsz);
nbytes = mite_bytes_written_to_memory_lb(mite_chan);
if ((int)(mite_bytes_written_to_memory_ub(mite_chan) -
old_alloc_count) > 0) {
dev_warn(async->subdevice->device->class_dev,
"mite: DMA overwrite of free area\n");
async->events |= COMEDI_CB_OVERFLOW;
return -1;
}
count = nbytes - async->buf_write_count;
if (count <= 0)
return 0;
comedi_buf_write_free(async, count);
async->scan_progress += count;
if (async->scan_progress >= bytes_per_scan) {
async->scan_progress %= bytes_per_scan;
async->events |= COMEDI_CB_EOS;
}
async->events |= COMEDI_CB_BLOCK;
return 0;
}
int mite_sync_output_dma(struct mite_channel *mite_chan,
struct comedi_async *async)
{
int count;
u32 nbytes_ub, nbytes_lb;
unsigned int old_alloc_count;
u32 stop_count =
async->cmd.stop_arg * cfc_bytes_per_scan(async->subdevice);
old_alloc_count = async->buf_read_alloc_count;
comedi_buf_read_alloc(async, async->prealloc_bufsz);
nbytes_lb = mite_bytes_read_from_memory_lb(mite_chan);
if (async->cmd.stop_src == TRIG_COUNT &&
(int)(nbytes_lb - stop_count) > 0)
nbytes_lb = stop_count;
nbytes_ub = mite_bytes_read_from_memory_ub(mite_chan);
if (async->cmd.stop_src == TRIG_COUNT &&
(int)(nbytes_ub - stop_count) > 0)
nbytes_ub = stop_count;
if ((int)(nbytes_ub - old_alloc_count) > 0) {
dev_warn(async->subdevice->device->class_dev,
"mite: DMA underrun\n");
async->events |= COMEDI_CB_OVERFLOW;
return -1;
}
count = nbytes_lb - async->buf_read_count;
if (count <= 0)
return 0;
if (count) {
comedi_buf_read_free(async, count);
async->events |= COMEDI_CB_BLOCK;
}
return 0;
}
unsigned mite_get_status(struct mite_channel *mite_chan)
{
struct mite_struct *mite = mite_chan->mite;
unsigned status;
unsigned long flags;
spin_lock_irqsave(&mite->lock, flags);
status = readl(mite->mite_io_addr + MITE_CHSR(mite_chan->channel));
if (status & CHSR_DONE) {
mite_chan->done = 1;
writel(CHOR_CLRDONE,
mite->mite_io_addr + MITE_CHOR(mite_chan->channel));
}
mmiowb();
spin_unlock_irqrestore(&mite->lock, flags);
return status;
}
int mite_done(struct mite_channel *mite_chan)
{
struct mite_struct *mite = mite_chan->mite;
unsigned long flags;
int done;
mite_get_status(mite_chan);
spin_lock_irqsave(&mite->lock, flags);
done = mite_chan->done;
spin_unlock_irqrestore(&mite->lock, flags);
return done;
}
static void mite_decode(const char *const *bit_str, unsigned int bits)
{
int i;
for (i = 31; i >= 0; i--) {
if (bits & (1 << i))
pr_debug(" %s\n", bit_str[i]);
}
}
void mite_dump_regs(struct mite_channel *mite_chan)
{
void __iomem *mite_io_addr = mite_chan->mite->mite_io_addr;
unsigned int offset;
unsigned int value;
int channel = mite_chan->channel;
pr_debug("mite_dump_regs ch%i\n", channel);
pr_debug("mite address is =%p\n", mite_io_addr);
offset = MITE_CHOR(channel);
value = readl(mite_io_addr + offset);
pr_debug("mite status[CHOR] at 0x%08x =0x%08x\n", offset, value);
mite_decode(mite_CHOR_strings, value);
offset = MITE_CHCR(channel);
value = readl(mite_io_addr + offset);
pr_debug("mite status[CHCR] at 0x%08x =0x%08x\n", offset, value);
mite_decode(mite_CHCR_strings, value);
offset = MITE_TCR(channel);
value = readl(mite_io_addr + offset);
pr_debug("mite status[TCR] at 0x%08x =0x%08x\n", offset, value);
offset = MITE_MCR(channel);
value = readl(mite_io_addr + offset);
pr_debug("mite status[MCR] at 0x%08x =0x%08x\n", offset, value);
mite_decode(mite_MCR_strings, value);
offset = MITE_MAR(channel);
value = readl(mite_io_addr + offset);
pr_debug("mite status[MAR] at 0x%08x =0x%08x\n", offset, value);
offset = MITE_DCR(channel);
value = readl(mite_io_addr + offset);
pr_debug("mite status[DCR] at 0x%08x =0x%08x\n", offset, value);
mite_decode(mite_DCR_strings, value);
offset = MITE_DAR(channel);
value = readl(mite_io_addr + offset);
pr_debug("mite status[DAR] at 0x%08x =0x%08x\n", offset, value);
offset = MITE_LKCR(channel);
value = readl(mite_io_addr + offset);
pr_debug("mite status[LKCR] at 0x%08x =0x%08x\n", offset, value);
mite_decode(mite_LKCR_strings, value);
offset = MITE_LKAR(channel);
value = readl(mite_io_addr + offset);
pr_debug("mite status[LKAR] at 0x%08x =0x%08x\n", offset, value);
offset = MITE_CHSR(channel);
value = readl(mite_io_addr + offset);
pr_debug("mite status[CHSR] at 0x%08x =0x%08x\n", offset, value);
mite_decode(mite_CHSR_strings, value);
offset = MITE_FCR(channel);
value = readl(mite_io_addr + offset);
pr_debug("mite status[FCR] at 0x%08x =0x%08x\n", offset, value);
}
static int __init mite_module_init(void)
{
return 0;
}
static void __exit mite_module_exit(void)
{
}
