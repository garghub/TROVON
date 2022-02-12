static int isa_get_dma_residue(unsigned int chan, dma_t *dma)
{
unsigned int io_port = isa_dma_port[chan][ISA_DMA_COUNT];
int count;
count = 1 + inb(io_port);
count |= inb(io_port) << 8;
return chan < 4 ? count : (count << 1);
}
static void isa_enable_dma(unsigned int chan, dma_t *dma)
{
if (dma->invalid) {
unsigned long address, length;
unsigned int mode;
enum dma_data_direction direction;
mode = (chan & 3) | dma->dma_mode;
switch (dma->dma_mode & DMA_MODE_MASK) {
case DMA_MODE_READ:
direction = DMA_FROM_DEVICE;
break;
case DMA_MODE_WRITE:
direction = DMA_TO_DEVICE;
break;
case DMA_MODE_CASCADE:
direction = DMA_BIDIRECTIONAL;
break;
default:
direction = DMA_NONE;
break;
}
if (!dma->sg) {
dma->sg = &dma->buf;
dma->sgcount = 1;
dma->buf.length = dma->count;
dma->buf.dma_address = dma_map_single(NULL,
dma->addr, dma->count,
direction);
}
address = dma->buf.dma_address;
length = dma->buf.length - 1;
outb(address >> 16, isa_dma_port[chan][ISA_DMA_PGLO]);
outb(address >> 24, isa_dma_port[chan][ISA_DMA_PGHI]);
if (chan >= 4) {
address >>= 1;
length >>= 1;
}
outb(0, isa_dma_port[chan][ISA_DMA_CLRFF]);
outb(address, isa_dma_port[chan][ISA_DMA_ADDR]);
outb(address >> 8, isa_dma_port[chan][ISA_DMA_ADDR]);
outb(length, isa_dma_port[chan][ISA_DMA_COUNT]);
outb(length >> 8, isa_dma_port[chan][ISA_DMA_COUNT]);
outb(mode, isa_dma_port[chan][ISA_DMA_MODE]);
dma->invalid = 0;
}
outb(chan & 3, isa_dma_port[chan][ISA_DMA_MASK]);
}
static void isa_disable_dma(unsigned int chan, dma_t *dma)
{
outb(chan | 4, isa_dma_port[chan][ISA_DMA_MASK]);
}
void __init isa_init_dma(void)
{
outb(0xff, 0x0d);
outb(0xff, 0xda);
outb(0x55, 0x00);
outb(0xaa, 0x00);
if (inb(0) == 0x55 && inb(0) == 0xaa) {
unsigned int chan, i;
for (chan = 0; chan < 8; chan++) {
isa_dma[chan].d_ops = &isa_dma_ops;
isa_disable_dma(chan, NULL);
}
outb(0x40, 0x0b);
outb(0x41, 0x0b);
outb(0x42, 0x0b);
outb(0x43, 0x0b);
outb(0xc0, 0xd6);
outb(0x41, 0xd6);
outb(0x42, 0xd6);
outb(0x43, 0xd6);
outb(0, 0xd4);
outb(0x10, 0x08);
outb(0x10, 0xd0);
outb(0x30, 0x40b);
outb(0x31, 0x40b);
outb(0x32, 0x40b);
outb(0x33, 0x40b);
outb(0x31, 0x4d6);
outb(0x32, 0x4d6);
outb(0x33, 0x4d6);
for (i = 0; i < ARRAY_SIZE(dma_resources); i++)
request_resource(&ioport_resource, dma_resources + i);
for (chan = 0; chan < 8; chan++) {
int ret = isa_dma_add(chan, &isa_dma[chan]);
if (ret)
printk(KERN_ERR "ISADMA%u: unable to register: %d\n",
chan, ret);
}
request_dma(DMA_ISA_CASCADE, "cascade");
}
}
