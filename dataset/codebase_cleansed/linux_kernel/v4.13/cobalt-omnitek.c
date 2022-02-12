static char *get_dma_direction(u32 status)
{
switch (status & DIRECTIONAL_MSK) {
case INPUT_ONLY: return "Input";
case OUTPUT_ONLY: return "Output";
case BIDIRECTIONAL: return "Bidirectional";
}
return "";
}
static void show_dma_capability(struct cobalt *cobalt)
{
u32 header = ioread32(CAPABILITY_HEADER);
u32 capa = ioread32(CAPABILITY_REGISTER);
u32 i;
cobalt_info("Omnitek DMA capability: ID 0x%02x Version 0x%02x Next 0x%x Size 0x%x\n",
header & 0xff, (header >> 8) & 0xff,
(header >> 16) & 0xffff, (capa >> 24) & 0xff);
switch ((capa >> 8) & 0x3) {
case 0:
cobalt_info("Omnitek DMA: 32 bits PCIe and Local\n");
break;
case 1:
cobalt_info("Omnitek DMA: 64 bits PCIe, 32 bits Local\n");
break;
case 3:
cobalt_info("Omnitek DMA: 64 bits PCIe and Local\n");
break;
}
for (i = 0; i < (capa & 0xf); i++) {
u32 status = ioread32(CS_REG(i));
cobalt_info("Omnitek DMA channel #%d: %s %s\n", i,
status & DMA_TYPE_FIFO ? "FIFO" : "MEMORY",
get_dma_direction(status));
}
}
void omni_sg_dma_start(struct cobalt_stream *s, struct sg_dma_desc_info *desc)
{
struct cobalt *cobalt = s->cobalt;
iowrite32((u32)((u64)desc->bus >> 32), DESCRIPTOR(s->dma_channel) + 4);
iowrite32((u32)desc->bus & NEXT_ADRS_MSK, DESCRIPTOR(s->dma_channel));
iowrite32(ENABLE | SCATTER_GATHER_MODE | START, CS_REG(s->dma_channel));
}
bool is_dma_done(struct cobalt_stream *s)
{
struct cobalt *cobalt = s->cobalt;
if (ioread32(CS_REG(s->dma_channel)) & DONE)
return true;
return false;
}
void omni_sg_dma_abort_channel(struct cobalt_stream *s)
{
struct cobalt *cobalt = s->cobalt;
if (is_dma_done(s) == false)
iowrite32(ABORT, CS_REG(s->dma_channel));
}
int omni_sg_dma_init(struct cobalt *cobalt)
{
u32 capa = ioread32(CAPABILITY_REGISTER);
int i;
cobalt->first_fifo_channel = 0;
cobalt->dma_channels = capa & 0xf;
if (capa & PCI_64BIT)
cobalt->pci_32_bit = false;
else
cobalt->pci_32_bit = true;
for (i = 0; i < cobalt->dma_channels; i++) {
u32 status = ioread32(CS_REG(i));
u32 ctrl = ioread32(CS_REG(i));
if (!(ctrl & DONE))
iowrite32(ABORT, CS_REG(i));
if (!(status & DMA_TYPE_FIFO))
cobalt->first_fifo_channel++;
}
show_dma_capability(cobalt);
return 0;
}
int descriptor_list_create(struct cobalt *cobalt,
struct scatterlist *scatter_list, bool to_pci, unsigned sglen,
unsigned size, unsigned width, unsigned stride,
struct sg_dma_desc_info *desc)
{
struct sg_dma_descriptor *d = (struct sg_dma_descriptor *)desc->virt;
dma_addr_t next = desc->bus;
unsigned offset = 0;
unsigned copy_bytes = width;
unsigned copied = 0;
bool first = true;
WARN_ON(sg_dma_address(scatter_list) & 3);
WARN_ON(size & 3);
WARN_ON(next & 3);
WARN_ON(stride & 3);
WARN_ON(stride < width);
if (width >= stride)
copy_bytes = stride = size;
while (size) {
dma_addr_t addr = sg_dma_address(scatter_list) + offset;
unsigned bytes;
if (addr == 0)
return -EFAULT;
if (cobalt->pci_32_bit) {
WARN_ON((u64)addr >> 32);
if ((u64)addr >> 32)
return -EFAULT;
}
d->pci_l = addr & 0xffffffff;
d->pci_h = (u64)addr >> 32;
d->local = 0;
d->reserved0 = 0;
bytes = min(sg_dma_len(scatter_list) - offset,
copy_bytes - copied);
if (first) {
if (to_pci)
d->local = 0x11111111;
first = false;
if (sglen == 1) {
d->bytes = (bytes / 2) & ~3;
d->reserved1 = 0;
size -= d->bytes;
copied += d->bytes;
offset += d->bytes;
addr += d->bytes;
next += sizeof(struct sg_dma_descriptor);
d->next_h = (u32)((u64)next >> 32);
d->next_l = (u32)next |
(to_pci ? WRITE_TO_PCI : 0);
bytes -= d->bytes;
d++;
d->pci_l = addr & 0xffffffff;
d->pci_h = (u64)addr >> 32;
d->local = 0;
d->reserved0 = 0;
}
}
d->bytes = bytes;
d->reserved1 = 0;
size -= bytes;
copied += bytes;
offset += bytes;
if (copied == copy_bytes) {
while (copied < stride) {
bytes = min(sg_dma_len(scatter_list) - offset,
stride - copied);
copied += bytes;
offset += bytes;
size -= bytes;
if (sg_dma_len(scatter_list) == offset) {
offset = 0;
scatter_list = sg_next(scatter_list);
}
}
copied = 0;
} else {
offset = 0;
scatter_list = sg_next(scatter_list);
}
next += sizeof(struct sg_dma_descriptor);
if (size == 0) {
d->next_h = (u32)((u64)desc->bus >> 32);
d->next_l = (u32)desc->bus |
(to_pci ? WRITE_TO_PCI : 0) | INTERRUPT_ENABLE;
if (!to_pci)
d->local = 0x22222222;
desc->last_desc_virt = d;
} else {
d->next_h = (u32)((u64)next >> 32);
d->next_l = (u32)next | (to_pci ? WRITE_TO_PCI : 0);
}
d++;
}
return 0;
}
void descriptor_list_chain(struct sg_dma_desc_info *this,
struct sg_dma_desc_info *next)
{
struct sg_dma_descriptor *d = this->last_desc_virt;
u32 direction = d->next_l & WRITE_TO_PCI;
if (next == NULL) {
d->next_h = 0;
d->next_l = direction | INTERRUPT_ENABLE | END_OF_CHAIN;
} else {
d->next_h = (u32)((u64)next->bus >> 32);
d->next_l = (u32)next->bus | direction | INTERRUPT_ENABLE;
}
}
void *descriptor_list_allocate(struct sg_dma_desc_info *desc, size_t bytes)
{
desc->size = bytes;
desc->virt = dma_alloc_coherent(desc->dev, bytes,
&desc->bus, GFP_KERNEL);
return desc->virt;
}
void descriptor_list_free(struct sg_dma_desc_info *desc)
{
if (desc->virt)
dma_free_coherent(desc->dev, desc->size,
desc->virt, desc->bus);
desc->virt = NULL;
}
void descriptor_list_interrupt_enable(struct sg_dma_desc_info *desc)
{
struct sg_dma_descriptor *d = desc->last_desc_virt;
d->next_l |= INTERRUPT_ENABLE;
}
void descriptor_list_interrupt_disable(struct sg_dma_desc_info *desc)
{
struct sg_dma_descriptor *d = desc->last_desc_virt;
d->next_l &= ~INTERRUPT_ENABLE;
}
void descriptor_list_loopback(struct sg_dma_desc_info *desc)
{
struct sg_dma_descriptor *d = desc->last_desc_virt;
d->next_h = (u32)((u64)desc->bus >> 32);
d->next_l = (u32)desc->bus | (d->next_l & DESCRIPTOR_FLAG_MSK);
}
void descriptor_list_end_of_chain(struct sg_dma_desc_info *desc)
{
struct sg_dma_descriptor *d = desc->last_desc_virt;
d->next_l |= END_OF_CHAIN;
}
