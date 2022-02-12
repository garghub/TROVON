static void __ebus_dma_reset(struct ebus_dma_info *p, int no_drain)
{
int i;
u32 val = 0;
writel(EBDMA_CSR_RESET, p->regs + EBDMA_CSR);
udelay(1);
if (no_drain)
return;
for (i = EBUS_DMA_RESET_TIMEOUT; i > 0; i--) {
val = readl(p->regs + EBDMA_CSR);
if (!(val & (EBDMA_CSR_DRAIN | EBDMA_CSR_CYC_PEND)))
break;
udelay(10);
}
}
static irqreturn_t ebus_dma_irq(int irq, void *dev_id)
{
struct ebus_dma_info *p = dev_id;
unsigned long flags;
u32 csr = 0;
spin_lock_irqsave(&p->lock, flags);
csr = readl(p->regs + EBDMA_CSR);
writel(csr, p->regs + EBDMA_CSR);
spin_unlock_irqrestore(&p->lock, flags);
if (csr & EBDMA_CSR_ERR_PEND) {
printk(KERN_CRIT "ebus_dma(%s): DMA error!\n", p->name);
p->callback(p, EBUS_DMA_EVENT_ERROR, p->client_cookie);
return IRQ_HANDLED;
} else if (csr & EBDMA_CSR_INT_PEND) {
p->callback(p,
(csr & EBDMA_CSR_TC) ?
EBUS_DMA_EVENT_DMA : EBUS_DMA_EVENT_DEVICE,
p->client_cookie);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
int ebus_dma_register(struct ebus_dma_info *p)
{
u32 csr;
if (!p->regs)
return -EINVAL;
if (p->flags & ~(EBUS_DMA_FLAG_USE_EBDMA_HANDLER |
EBUS_DMA_FLAG_TCI_DISABLE))
return -EINVAL;
if ((p->flags & EBUS_DMA_FLAG_USE_EBDMA_HANDLER) && !p->callback)
return -EINVAL;
if (!strlen(p->name))
return -EINVAL;
__ebus_dma_reset(p, 1);
csr = EBDMA_CSR_BURST_SZ_16 | EBDMA_CSR_EN_CNT;
if (p->flags & EBUS_DMA_FLAG_TCI_DISABLE)
csr |= EBDMA_CSR_TCI_DIS;
writel(csr, p->regs + EBDMA_CSR);
return 0;
}
int ebus_dma_irq_enable(struct ebus_dma_info *p, int on)
{
unsigned long flags;
u32 csr;
if (on) {
if (p->flags & EBUS_DMA_FLAG_USE_EBDMA_HANDLER) {
if (request_irq(p->irq, ebus_dma_irq, IRQF_SHARED, p->name, p))
return -EBUSY;
}
spin_lock_irqsave(&p->lock, flags);
csr = readl(p->regs + EBDMA_CSR);
csr |= EBDMA_CSR_INT_EN;
writel(csr, p->regs + EBDMA_CSR);
spin_unlock_irqrestore(&p->lock, flags);
} else {
spin_lock_irqsave(&p->lock, flags);
csr = readl(p->regs + EBDMA_CSR);
csr &= ~EBDMA_CSR_INT_EN;
writel(csr, p->regs + EBDMA_CSR);
spin_unlock_irqrestore(&p->lock, flags);
if (p->flags & EBUS_DMA_FLAG_USE_EBDMA_HANDLER) {
free_irq(p->irq, p);
}
}
return 0;
}
void ebus_dma_unregister(struct ebus_dma_info *p)
{
unsigned long flags;
u32 csr;
int irq_on = 0;
spin_lock_irqsave(&p->lock, flags);
csr = readl(p->regs + EBDMA_CSR);
if (csr & EBDMA_CSR_INT_EN) {
csr &= ~EBDMA_CSR_INT_EN;
writel(csr, p->regs + EBDMA_CSR);
irq_on = 1;
}
spin_unlock_irqrestore(&p->lock, flags);
if (irq_on)
free_irq(p->irq, p);
}
int ebus_dma_request(struct ebus_dma_info *p, dma_addr_t bus_addr, size_t len)
{
unsigned long flags;
u32 csr;
int err;
if (len >= (1 << 24))
return -EINVAL;
spin_lock_irqsave(&p->lock, flags);
csr = readl(p->regs + EBDMA_CSR);
err = -EINVAL;
if (!(csr & EBDMA_CSR_EN_DMA))
goto out;
err = -EBUSY;
if (csr & EBDMA_CSR_NA_LOADED)
goto out;
writel(len, p->regs + EBDMA_COUNT);
writel(bus_addr, p->regs + EBDMA_ADDR);
err = 0;
out:
spin_unlock_irqrestore(&p->lock, flags);
return err;
}
void ebus_dma_prepare(struct ebus_dma_info *p, int write)
{
unsigned long flags;
u32 csr;
spin_lock_irqsave(&p->lock, flags);
__ebus_dma_reset(p, 0);
csr = (EBDMA_CSR_INT_EN |
EBDMA_CSR_EN_CNT |
EBDMA_CSR_BURST_SZ_16 |
EBDMA_CSR_EN_NEXT);
if (write)
csr |= EBDMA_CSR_WRITE;
if (p->flags & EBUS_DMA_FLAG_TCI_DISABLE)
csr |= EBDMA_CSR_TCI_DIS;
writel(csr, p->regs + EBDMA_CSR);
spin_unlock_irqrestore(&p->lock, flags);
}
unsigned int ebus_dma_residue(struct ebus_dma_info *p)
{
return readl(p->regs + EBDMA_COUNT);
}
unsigned int ebus_dma_addr(struct ebus_dma_info *p)
{
return readl(p->regs + EBDMA_ADDR);
}
void ebus_dma_enable(struct ebus_dma_info *p, int on)
{
unsigned long flags;
u32 orig_csr, csr;
spin_lock_irqsave(&p->lock, flags);
orig_csr = csr = readl(p->regs + EBDMA_CSR);
if (on)
csr |= EBDMA_CSR_EN_DMA;
else
csr &= ~EBDMA_CSR_EN_DMA;
if ((orig_csr & EBDMA_CSR_EN_DMA) !=
(csr & EBDMA_CSR_EN_DMA))
writel(csr, p->regs + EBDMA_CSR);
spin_unlock_irqrestore(&p->lock, flags);
}
