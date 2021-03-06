static inline unsigned long
gc_readl(struct pxa3xx_gcu_priv *priv, unsigned int off)
{
return __raw_readl(priv->mmio_base + off);
}
static inline void
gc_writel(struct pxa3xx_gcu_priv *priv, unsigned int off, unsigned long val)
{
__raw_writel(val, priv->mmio_base + off);
}
static void
pxa3xx_gcu_reset(struct pxa3xx_gcu_priv *priv)
{
QDUMP("RESET");
gc_writel(priv, REG_GCIECR, 0);
gc_writel(priv, REG_GCCR, GCCR_ABORT);
gc_writel(priv, REG_GCCR, 0);
memset(priv->shared, 0, SHARED_SIZE);
priv->shared->buffer_phys = priv->shared_phys;
priv->shared->magic = PXA3XX_GCU_SHARED_MAGIC;
do_gettimeofday(&priv->base_time);
gc_writel(priv, REG_GCRBLR, 0);
gc_writel(priv, REG_GCRBBR, priv->shared_phys);
gc_writel(priv, REG_GCRBTR, priv->shared_phys);
gc_writel(priv, REG_GCIECR, IE_ALL & ~IE_EOB);
}
static void
dump_whole_state(struct pxa3xx_gcu_priv *priv)
{
struct pxa3xx_gcu_shared *sh = priv->shared;
u32 base = gc_readl(priv, REG_GCRBBR);
QDUMP("DUMP");
printk(KERN_DEBUG "== PXA3XX-GCU DUMP ==\n"
"%s, STATUS 0x%02lx, B 0x%08lx [%ld], E %5ld, H %5ld, T %5ld\n",
sh->hw_running ? "running" : "idle ",
gc_readl(priv, REG_GCISCR),
gc_readl(priv, REG_GCRBBR),
gc_readl(priv, REG_GCRBLR),
(gc_readl(priv, REG_GCRBEXHR) - base) / 4,
(gc_readl(priv, REG_GCRBHR) - base) / 4,
(gc_readl(priv, REG_GCRBTR) - base) / 4);
}
static void
flush_running(struct pxa3xx_gcu_priv *priv)
{
struct pxa3xx_gcu_batch *running = priv->running;
struct pxa3xx_gcu_batch *next;
while (running) {
next = running->next;
running->next = priv->free;
priv->free = running;
running = next;
}
priv->running = NULL;
}
static void
run_ready(struct pxa3xx_gcu_priv *priv)
{
unsigned int num = 0;
struct pxa3xx_gcu_shared *shared = priv->shared;
struct pxa3xx_gcu_batch *ready = priv->ready;
QDUMP("Start");
BUG_ON(!ready);
shared->buffer[num++] = 0x05000000;
while (ready) {
shared->buffer[num++] = 0x00000001;
shared->buffer[num++] = ready->phys;
ready = ready->next;
}
shared->buffer[num++] = 0x05000000;
priv->running = priv->ready;
priv->ready = priv->ready_last = NULL;
gc_writel(priv, REG_GCRBLR, 0);
shared->hw_running = 1;
gc_writel(priv, REG_GCRBBR, shared->buffer_phys);
gc_writel(priv, REG_GCRBTR, shared->buffer_phys + num * 4);
gc_writel(priv, REG_GCRBLR, ((num + 63) & ~63) * 4);
}
static irqreturn_t
pxa3xx_gcu_handle_irq(int irq, void *ctx)
{
struct pxa3xx_gcu_priv *priv = ctx;
struct pxa3xx_gcu_shared *shared = priv->shared;
u32 status = gc_readl(priv, REG_GCISCR) & IE_ALL;
QDUMP("-Interrupt");
if (!status)
return IRQ_NONE;
spin_lock(&priv->spinlock);
shared->num_interrupts++;
if (status & IE_EEOB) {
QDUMP(" [EEOB]");
flush_running(priv);
wake_up_all(&priv->wait_free);
if (priv->ready) {
run_ready(priv);
} else {
shared->num_idle++;
shared->hw_running = 0;
QDUMP(" '-> Idle.");
gc_writel(priv, REG_GCRBLR, 0);
wake_up_all(&priv->wait_idle);
}
shared->num_done++;
} else {
QERROR(" [???]");
dump_whole_state(priv);
}
gc_writel(priv, REG_GCISCR, status);
spin_unlock(&priv->spinlock);
return IRQ_HANDLED;
}
static int
pxa3xx_gcu_wait_idle(struct pxa3xx_gcu_priv *priv)
{
int ret = 0;
QDUMP("Waiting for idle...");
priv->shared->num_wait_idle++;
while (priv->shared->hw_running) {
int num = priv->shared->num_interrupts;
u32 rbexhr = gc_readl(priv, REG_GCRBEXHR);
ret = wait_event_interruptible_timeout(priv->wait_idle,
!priv->shared->hw_running, HZ*4);
if (ret != 0)
break;
if (gc_readl(priv, REG_GCRBEXHR) == rbexhr &&
priv->shared->num_interrupts == num) {
QERROR("TIMEOUT");
ret = -ETIMEDOUT;
break;
}
}
QDUMP("done");
return ret;
}
static int
pxa3xx_gcu_wait_free(struct pxa3xx_gcu_priv *priv)
{
int ret = 0;
QDUMP("Waiting for free...");
priv->shared->num_wait_free++;
while (!priv->free) {
u32 rbexhr = gc_readl(priv, REG_GCRBEXHR);
ret = wait_event_interruptible_timeout(priv->wait_free,
priv->free, HZ*4);
if (ret < 0)
break;
if (ret > 0)
continue;
if (gc_readl(priv, REG_GCRBEXHR) == rbexhr) {
QERROR("TIMEOUT");
ret = -ETIMEDOUT;
break;
}
}
QDUMP("done");
return ret;
}
static ssize_t
pxa3xx_gcu_misc_write(struct file *filp, const char *buff,
size_t count, loff_t *offp)
{
int ret;
unsigned long flags;
struct pxa3xx_gcu_batch *buffer;
struct pxa3xx_gcu_priv *priv =
container_of(filp->f_op, struct pxa3xx_gcu_priv, misc_fops);
int words = count / 4;
priv->shared->num_writes++;
priv->shared->num_words += words;
if (words >= PXA3XX_GCU_BATCH_WORDS)
return -E2BIG;
if (!priv->free) {
ret = pxa3xx_gcu_wait_free(priv);
if (ret < 0)
return ret;
}
spin_lock_irqsave(&priv->spinlock, flags);
buffer = priv->free;
priv->free = buffer->next;
spin_unlock_irqrestore(&priv->spinlock, flags);
ret = copy_from_user(buffer->ptr, buff, words * 4);
if (ret) {
spin_lock_irqsave(&priv->spinlock, flags);
buffer->next = priv->free;
priv->free = buffer;
spin_unlock_irqrestore(&priv->spinlock, flags);
return -EFAULT;
}
buffer->length = words;
buffer->ptr[words] = 0x01000000;
spin_lock_irqsave(&priv->spinlock, flags);
buffer->next = NULL;
if (priv->ready) {
BUG_ON(priv->ready_last == NULL);
priv->ready_last->next = buffer;
} else
priv->ready = buffer;
priv->ready_last = buffer;
if (!priv->shared->hw_running)
run_ready(priv);
spin_unlock_irqrestore(&priv->spinlock, flags);
return words * 4;
}
static long
pxa3xx_gcu_misc_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
unsigned long flags;
struct pxa3xx_gcu_priv *priv =
container_of(filp->f_op, struct pxa3xx_gcu_priv, misc_fops);
switch (cmd) {
case PXA3XX_GCU_IOCTL_RESET:
spin_lock_irqsave(&priv->spinlock, flags);
pxa3xx_gcu_reset(priv);
spin_unlock_irqrestore(&priv->spinlock, flags);
return 0;
case PXA3XX_GCU_IOCTL_WAIT_IDLE:
return pxa3xx_gcu_wait_idle(priv);
}
return -ENOSYS;
}
static int
pxa3xx_gcu_misc_mmap(struct file *filp, struct vm_area_struct *vma)
{
unsigned int size = vma->vm_end - vma->vm_start;
struct pxa3xx_gcu_priv *priv =
container_of(filp->f_op, struct pxa3xx_gcu_priv, misc_fops);
switch (vma->vm_pgoff) {
case 0:
if (size != SHARED_SIZE)
return -EINVAL;
return dma_mmap_coherent(NULL, vma,
priv->shared, priv->shared_phys, size);
case SHARED_SIZE >> PAGE_SHIFT:
if (size != resource_size(priv->resource_mem))
return -EINVAL;
vma->vm_flags |= VM_IO;
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
return io_remap_pfn_range(vma, vma->vm_start,
priv->resource_mem->start >> PAGE_SHIFT,
size, vma->vm_page_prot);
}
return -EINVAL;
}
static void pxa3xx_gcu_debug_timedout(unsigned long ptr)
{
struct pxa3xx_gcu_priv *priv = (struct pxa3xx_gcu_priv *) ptr;
QERROR("Timer DUMP");
init_timer(&pxa3xx_gcu_debug_timer);
pxa3xx_gcu_debug_timer.function = pxa3xx_gcu_debug_timedout;
pxa3xx_gcu_debug_timer.data = ptr;
pxa3xx_gcu_debug_timer.expires = jiffies + 5*HZ;
add_timer(&pxa3xx_gcu_debug_timer);
}
static void pxa3xx_gcu_init_debug_timer(void)
{
pxa3xx_gcu_debug_timedout((unsigned long) &pxa3xx_gcu_debug_timer);
}
static inline void pxa3xx_gcu_init_debug_timer(void) {}
static int
add_buffer(struct platform_device *dev,
struct pxa3xx_gcu_priv *priv)
{
struct pxa3xx_gcu_batch *buffer;
buffer = kzalloc(sizeof(struct pxa3xx_gcu_batch), GFP_KERNEL);
if (!buffer)
return -ENOMEM;
buffer->ptr = dma_alloc_coherent(&dev->dev, PXA3XX_GCU_BATCH_WORDS * 4,
&buffer->phys, GFP_KERNEL);
if (!buffer->ptr) {
kfree(buffer);
return -ENOMEM;
}
buffer->next = priv->free;
priv->free = buffer;
return 0;
}
static void
free_buffers(struct platform_device *dev,
struct pxa3xx_gcu_priv *priv)
{
struct pxa3xx_gcu_batch *next, *buffer = priv->free;
while (buffer) {
next = buffer->next;
dma_free_coherent(&dev->dev, PXA3XX_GCU_BATCH_WORDS * 4,
buffer->ptr, buffer->phys);
kfree(buffer);
buffer = next;
}
priv->free = NULL;
}
static int pxa3xx_gcu_probe(struct platform_device *dev)
{
int i, ret, irq;
struct resource *r;
struct pxa3xx_gcu_priv *priv;
priv = kzalloc(sizeof(struct pxa3xx_gcu_priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
for (i = 0; i < 8; i++) {
ret = add_buffer(dev, priv);
if (ret) {
dev_err(&dev->dev, "failed to allocate DMA memory\n");
goto err_free_priv;
}
}
init_waitqueue_head(&priv->wait_idle);
init_waitqueue_head(&priv->wait_free);
spin_lock_init(&priv->spinlock);
priv->misc_fops.owner = THIS_MODULE;
priv->misc_fops.write = pxa3xx_gcu_misc_write;
priv->misc_fops.unlocked_ioctl = pxa3xx_gcu_misc_ioctl;
priv->misc_fops.mmap = pxa3xx_gcu_misc_mmap;
priv->misc_dev.minor = MISCDEV_MINOR,
priv->misc_dev.name = DRV_NAME,
priv->misc_dev.fops = &priv->misc_fops,
ret = misc_register(&priv->misc_dev);
if (ret < 0) {
dev_err(&dev->dev, "misc_register() for minor %d failed\n",
MISCDEV_MINOR);
goto err_free_priv;
}
r = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (r == NULL) {
dev_err(&dev->dev, "no I/O memory resource defined\n");
ret = -ENODEV;
goto err_misc_deregister;
}
if (!request_mem_region(r->start, resource_size(r), dev->name)) {
dev_err(&dev->dev, "failed to request I/O memory\n");
ret = -EBUSY;
goto err_misc_deregister;
}
priv->mmio_base = ioremap_nocache(r->start, resource_size(r));
if (!priv->mmio_base) {
dev_err(&dev->dev, "failed to map I/O memory\n");
ret = -EBUSY;
goto err_free_mem_region;
}
priv->shared = dma_alloc_coherent(&dev->dev, SHARED_SIZE,
&priv->shared_phys, GFP_KERNEL);
if (!priv->shared) {
dev_err(&dev->dev, "failed to allocate DMA memory\n");
ret = -ENOMEM;
goto err_free_io;
}
priv->clk = clk_get(&dev->dev, NULL);
if (IS_ERR(priv->clk)) {
dev_err(&dev->dev, "failed to get clock\n");
ret = -ENODEV;
goto err_free_dma;
}
ret = clk_enable(priv->clk);
if (ret < 0) {
dev_err(&dev->dev, "failed to enable clock\n");
goto err_put_clk;
}
irq = platform_get_irq(dev, 0);
if (irq < 0) {
dev_err(&dev->dev, "no IRQ defined\n");
ret = -ENODEV;
goto err_put_clk;
}
ret = request_irq(irq, pxa3xx_gcu_handle_irq,
0, DRV_NAME, priv);
if (ret) {
dev_err(&dev->dev, "request_irq failed\n");
ret = -EBUSY;
goto err_put_clk;
}
platform_set_drvdata(dev, priv);
priv->resource_mem = r;
pxa3xx_gcu_reset(priv);
pxa3xx_gcu_init_debug_timer();
dev_info(&dev->dev, "registered @0x%p, DMA 0x%p (%d bytes), IRQ %d\n",
(void *) r->start, (void *) priv->shared_phys,
SHARED_SIZE, irq);
return 0;
err_put_clk:
clk_disable(priv->clk);
clk_put(priv->clk);
err_free_dma:
dma_free_coherent(&dev->dev, SHARED_SIZE,
priv->shared, priv->shared_phys);
err_free_io:
iounmap(priv->mmio_base);
err_free_mem_region:
release_mem_region(r->start, resource_size(r));
err_misc_deregister:
misc_deregister(&priv->misc_dev);
err_free_priv:
platform_set_drvdata(dev, NULL);
free_buffers(dev, priv);
kfree(priv);
return ret;
}
static int pxa3xx_gcu_remove(struct platform_device *dev)
{
struct pxa3xx_gcu_priv *priv = platform_get_drvdata(dev);
struct resource *r = priv->resource_mem;
pxa3xx_gcu_wait_idle(priv);
misc_deregister(&priv->misc_dev);
dma_free_coherent(&dev->dev, SHARED_SIZE,
priv->shared, priv->shared_phys);
iounmap(priv->mmio_base);
release_mem_region(r->start, resource_size(r));
platform_set_drvdata(dev, NULL);
clk_disable(priv->clk);
free_buffers(dev, priv);
kfree(priv);
return 0;
}
