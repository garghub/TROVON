static int __init blackfin_dma_init(void)
{
int i;
printk(KERN_INFO "Blackfin DMA Controller\n");
#if ANOMALY_05000480
bfin_write_DMAC_TC_PER(0x0111);
#endif
for (i = 0; i < MAX_DMA_CHANNELS; i++) {
atomic_set(&dma_ch[i].chan_status, 0);
dma_ch[i].regs = dma_io_base_addr[i];
}
request_dma(CH_MEM_STREAM0_DEST, "Blackfin dma_memcpy");
request_dma(CH_MEM_STREAM0_SRC, "Blackfin dma_memcpy");
#if defined(CONFIG_DEB_DMA_URGENT)
bfin_write_EBIU_DDRQUE(bfin_read_EBIU_DDRQUE()
| DEB1_URGENT | DEB2_URGENT | DEB3_URGENT);
#endif
return 0;
}
static int proc_dma_show(struct seq_file *m, void *v)
{
int i;
for (i = 0; i < MAX_DMA_CHANNELS; ++i)
if (dma_channel_active(i))
seq_printf(m, "%2d: %s\n", i, dma_ch[i].device_id);
return 0;
}
static int proc_dma_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_dma_show, NULL);
}
static int __init proc_dma_init(void)
{
return proc_create("dma", 0, NULL, &proc_dma_operations) != NULL;
}
static void set_dma_peripheral_map(unsigned int channel, const char *device_id)
{
#ifdef CONFIG_BF54x
unsigned int per_map;
switch (channel) {
case CH_UART2_RX: per_map = 0xC << 12; break;
case CH_UART2_TX: per_map = 0xD << 12; break;
case CH_UART3_RX: per_map = 0xE << 12; break;
case CH_UART3_TX: per_map = 0xF << 12; break;
default: return;
}
if (strncmp(device_id, "BFIN_UART", 9) == 0)
dma_ch[channel].regs->peripheral_map = per_map;
#endif
}
int request_dma(unsigned int channel, const char *device_id)
{
pr_debug("request_dma() : BEGIN\n");
if (device_id == NULL)
printk(KERN_WARNING "request_dma(%u): no device_id given\n", channel);
#if defined(CONFIG_BF561) && ANOMALY_05000182
if (channel >= CH_IMEM_STREAM0_DEST && channel <= CH_IMEM_STREAM1_DEST) {
if (get_cclk() > 500000000) {
printk(KERN_WARNING
"Request IMDMA failed due to ANOMALY 05000182\n");
return -EFAULT;
}
}
#endif
if (atomic_cmpxchg(&dma_ch[channel].chan_status, 0, 1)) {
pr_debug("DMA CHANNEL IN USE\n");
return -EBUSY;
}
set_dma_peripheral_map(channel, device_id);
dma_ch[channel].device_id = device_id;
dma_ch[channel].irq = 0;
pr_debug("request_dma() : END\n");
return 0;
}
int set_dma_callback(unsigned int channel, irq_handler_t callback, void *data)
{
int ret;
unsigned int irq;
BUG_ON(channel >= MAX_DMA_CHANNELS || !callback ||
!atomic_read(&dma_ch[channel].chan_status));
irq = channel2irq(channel);
ret = request_irq(irq, callback, 0, dma_ch[channel].device_id, data);
if (ret)
return ret;
dma_ch[channel].irq = irq;
dma_ch[channel].data = data;
return 0;
}
static void clear_dma_buffer(unsigned int channel)
{
dma_ch[channel].regs->cfg |= RESTART;
SSYNC();
dma_ch[channel].regs->cfg &= ~RESTART;
}
void free_dma(unsigned int channel)
{
pr_debug("freedma() : BEGIN\n");
BUG_ON(channel >= MAX_DMA_CHANNELS ||
!atomic_read(&dma_ch[channel].chan_status));
disable_dma(channel);
clear_dma_buffer(channel);
if (dma_ch[channel].irq)
free_irq(dma_ch[channel].irq, dma_ch[channel].data);
atomic_set(&dma_ch[channel].chan_status, 0);
pr_debug("freedma() : END\n");
}
int blackfin_dma_suspend(void)
{
int i;
for (i = 0; i < MAX_DMA_CHANNELS; ++i) {
if (dma_ch[i].regs->cfg & DMAEN) {
printk(KERN_ERR "DMA Channel %d failed to suspend\n", i);
return -EBUSY;
}
if (i < MAX_DMA_SUSPEND_CHANNELS)
dma_ch[i].saved_peripheral_map = dma_ch[i].regs->peripheral_map;
}
#if ANOMALY_05000480
bfin_write_DMAC_TC_PER(0x0);
#endif
return 0;
}
void blackfin_dma_resume(void)
{
int i;
for (i = 0; i < MAX_DMA_CHANNELS; ++i) {
dma_ch[i].regs->cfg = 0;
if (i < MAX_DMA_SUSPEND_CHANNELS)
dma_ch[i].regs->peripheral_map = dma_ch[i].saved_peripheral_map;
}
#if ANOMALY_05000480
bfin_write_DMAC_TC_PER(0x0111);
#endif
}
void __init blackfin_dma_early_init(void)
{
early_shadow_stamp();
bfin_write_MDMA_S0_CONFIG(0);
bfin_write_MDMA_S1_CONFIG(0);
}
void __init early_dma_memcpy(void *pdst, const void *psrc, size_t size)
{
unsigned long dst = (unsigned long)pdst;
unsigned long src = (unsigned long)psrc;
struct dma_register *dst_ch, *src_ch;
early_shadow_stamp();
BUG_ON(dst % 4);
BUG_ON(src % 4);
BUG_ON(size % 4);
src_ch = 0;
while (1) {
if (src_ch == (struct dma_register *)MDMA_S0_NEXT_DESC_PTR) {
dst_ch = (struct dma_register *)MDMA_D1_NEXT_DESC_PTR;
src_ch = (struct dma_register *)MDMA_S1_NEXT_DESC_PTR;
} else {
dst_ch = (struct dma_register *)MDMA_D0_NEXT_DESC_PTR;
src_ch = (struct dma_register *)MDMA_S0_NEXT_DESC_PTR;
}
if (!bfin_read16(&src_ch->cfg))
break;
else if (bfin_read16(&dst_ch->irq_status) & DMA_DONE) {
bfin_write16(&src_ch->cfg, 0);
break;
}
}
__builtin_bfin_ssync();
bfin_write32(&dst_ch->start_addr, dst);
bfin_write16(&dst_ch->x_count, size >> 2);
bfin_write16(&dst_ch->x_modify, 1 << 2);
bfin_write16(&dst_ch->irq_status, DMA_DONE | DMA_ERR);
bfin_write32(&src_ch->start_addr, src);
bfin_write16(&src_ch->x_count, size >> 2);
bfin_write16(&src_ch->x_modify, 1 << 2);
bfin_write16(&src_ch->irq_status, DMA_DONE | DMA_ERR);
bfin_write16(&src_ch->cfg, DMAEN | WDSIZE_32);
bfin_write16(&dst_ch->cfg, WNR | DI_EN | DMAEN | WDSIZE_32);
__builtin_bfin_ssync();
}
void __init early_dma_memcpy_done(void)
{
early_shadow_stamp();
while ((bfin_read_MDMA_S0_CONFIG() && !(bfin_read_MDMA_D0_IRQ_STATUS() & DMA_DONE)) ||
(bfin_read_MDMA_S1_CONFIG() && !(bfin_read_MDMA_D1_IRQ_STATUS() & DMA_DONE)))
continue;
bfin_write_MDMA_D0_IRQ_STATUS(DMA_DONE | DMA_ERR);
bfin_write_MDMA_D1_IRQ_STATUS(DMA_DONE | DMA_ERR);
bfin_write_MDMA_S0_CONFIG(0);
bfin_write_MDMA_S1_CONFIG(0);
bfin_write_MDMA_D0_CONFIG(0);
bfin_write_MDMA_D1_CONFIG(0);
__builtin_bfin_ssync();
}
static void __dma_memcpy(u32 daddr, s16 dmod, u32 saddr, s16 smod, size_t cnt, u32 conf)
{
static DEFINE_SPINLOCK(mdma_lock);
unsigned long flags;
spin_lock_irqsave(&mdma_lock, flags);
__builtin_bfin_ssync();
if (bfin_read_MDMA_S0_CONFIG())
while (!(bfin_read_MDMA_D0_IRQ_STATUS() & DMA_DONE))
continue;
if (conf & DMA2D) {
u32 shift = abs(dmod) >> 1;
size_t ycnt = cnt >> (16 - shift);
cnt = 1 << (16 - shift);
bfin_write_MDMA_D0_Y_COUNT(ycnt);
bfin_write_MDMA_S0_Y_COUNT(ycnt);
bfin_write_MDMA_D0_Y_MODIFY(dmod);
bfin_write_MDMA_S0_Y_MODIFY(smod);
}
bfin_write_MDMA_D0_START_ADDR(daddr);
bfin_write_MDMA_D0_X_COUNT(cnt);
bfin_write_MDMA_D0_X_MODIFY(dmod);
bfin_write_MDMA_D0_IRQ_STATUS(DMA_DONE | DMA_ERR);
bfin_write_MDMA_S0_START_ADDR(saddr);
bfin_write_MDMA_S0_X_COUNT(cnt);
bfin_write_MDMA_S0_X_MODIFY(smod);
bfin_write_MDMA_S0_IRQ_STATUS(DMA_DONE | DMA_ERR);
bfin_write_MDMA_S0_CONFIG(DMAEN | conf);
bfin_write_MDMA_D0_CONFIG(WNR | DI_EN | DMAEN | conf);
spin_unlock_irqrestore(&mdma_lock, flags);
SSYNC();
while (!(bfin_read_MDMA_D0_IRQ_STATUS() & DMA_DONE))
if (bfin_read_MDMA_S0_CONFIG())
continue;
else
return;
bfin_write_MDMA_D0_IRQ_STATUS(DMA_DONE | DMA_ERR);
bfin_write_MDMA_S0_CONFIG(0);
bfin_write_MDMA_D0_CONFIG(0);
}
static void *_dma_memcpy(void *pdst, const void *psrc, size_t size)
{
u32 conf, shift;
s16 mod;
unsigned long dst = (unsigned long)pdst;
unsigned long src = (unsigned long)psrc;
if (size == 0)
return NULL;
if (dst % 4 == 0 && src % 4 == 0 && size % 4 == 0) {
conf = WDSIZE_32;
shift = 2;
} else if (dst % 2 == 0 && src % 2 == 0 && size % 2 == 0) {
conf = WDSIZE_16;
shift = 1;
} else {
conf = WDSIZE_8;
shift = 0;
}
mod = 1 << shift;
if (src < dst) {
mod *= -1;
dst += size + mod;
src += size + mod;
}
size >>= shift;
if (size > 0x10000)
conf |= DMA2D;
__dma_memcpy(dst, mod, src, mod, size, conf);
return pdst;
}
void *dma_memcpy(void *pdst, const void *psrc, size_t size)
{
unsigned long dst = (unsigned long)pdst;
unsigned long src = (unsigned long)psrc;
if (bfin_addr_dcacheable(src))
blackfin_dcache_flush_range(src, src + size);
if (bfin_addr_dcacheable(dst))
blackfin_dcache_invalidate_range(dst, dst + size);
return dma_memcpy_nocache(pdst, psrc, size);
}
void *dma_memcpy_nocache(void *pdst, const void *psrc, size_t size)
{
size_t bulk, rest;
bulk = size & ~0xffff;
rest = size - bulk;
if (bulk)
_dma_memcpy(pdst, psrc, bulk);
_dma_memcpy(pdst + bulk, psrc + bulk, rest);
return pdst;
}
void *safe_dma_memcpy(void *dst, const void *src, size_t size)
{
if (!access_ok(VERIFY_WRITE, dst, size))
return NULL;
if (!access_ok(VERIFY_READ, src, size))
return NULL;
return dma_memcpy(dst, src, size);
}
static void _dma_out(unsigned long addr, unsigned long buf, unsigned short len,
u16 size, u16 dma_size)
{
blackfin_dcache_flush_range(buf, buf + len * size);
__dma_memcpy(addr, 0, buf, size, len, dma_size);
}
static void _dma_in(unsigned long addr, unsigned long buf, unsigned short len,
u16 size, u16 dma_size)
{
blackfin_dcache_invalidate_range(buf, buf + len * size);
__dma_memcpy(buf, size, addr, 0, len, dma_size);
}
