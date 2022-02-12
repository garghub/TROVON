int msnd_register(multisound_dev_t *dev)
{
int i;
for (i = 0; i < MSND_MAX_DEVS; ++i)
if (devs[i] == NULL)
break;
if (i == MSND_MAX_DEVS)
return -ENOMEM;
devs[i] = dev;
++num_devs;
return 0;
}
void msnd_unregister(multisound_dev_t *dev)
{
int i;
for (i = 0; i < MSND_MAX_DEVS; ++i)
if (devs[i] == dev)
break;
if (i == MSND_MAX_DEVS) {
printk(KERN_WARNING LOGNAME ": Unregistering unknown device\n");
return;
}
devs[i] = NULL;
--num_devs;
}
void msnd_init_queue(void __iomem *base, int start, int size)
{
writew(PCTODSP_BASED(start), base + JQS_wStart);
writew(PCTODSP_OFFSET(size) - 1, base + JQS_wSize);
writew(0, base + JQS_wHead);
writew(0, base + JQS_wTail);
}
void msnd_fifo_init(msnd_fifo *f)
{
f->data = NULL;
}
void msnd_fifo_free(msnd_fifo *f)
{
vfree(f->data);
f->data = NULL;
}
int msnd_fifo_alloc(msnd_fifo *f, size_t n)
{
msnd_fifo_free(f);
f->data = vmalloc(n);
f->n = n;
f->tail = 0;
f->head = 0;
f->len = 0;
if (!f->data)
return -ENOMEM;
return 0;
}
void msnd_fifo_make_empty(msnd_fifo *f)
{
f->len = f->tail = f->head = 0;
}
int msnd_fifo_write_io(msnd_fifo *f, char __iomem *buf, size_t len)
{
int count = 0;
while ((count < len) && (f->len != f->n)) {
int nwritten;
if (f->head <= f->tail) {
nwritten = len - count;
if (nwritten > f->n - f->tail)
nwritten = f->n - f->tail;
}
else {
nwritten = f->head - f->tail;
if (nwritten > len - count)
nwritten = len - count;
}
memcpy_fromio(f->data + f->tail, buf, nwritten);
count += nwritten;
buf += nwritten;
f->len += nwritten;
f->tail += nwritten;
f->tail %= f->n;
}
return count;
}
int msnd_fifo_write(msnd_fifo *f, const char *buf, size_t len)
{
int count = 0;
while ((count < len) && (f->len != f->n)) {
int nwritten;
if (f->head <= f->tail) {
nwritten = len - count;
if (nwritten > f->n - f->tail)
nwritten = f->n - f->tail;
}
else {
nwritten = f->head - f->tail;
if (nwritten > len - count)
nwritten = len - count;
}
memcpy(f->data + f->tail, buf, nwritten);
count += nwritten;
buf += nwritten;
f->len += nwritten;
f->tail += nwritten;
f->tail %= f->n;
}
return count;
}
int msnd_fifo_read_io(msnd_fifo *f, char __iomem *buf, size_t len)
{
int count = 0;
while ((count < len) && (f->len > 0)) {
int nread;
if (f->tail <= f->head) {
nread = len - count;
if (nread > f->n - f->head)
nread = f->n - f->head;
}
else {
nread = f->tail - f->head;
if (nread > len - count)
nread = len - count;
}
memcpy_toio(buf, f->data + f->head, nread);
count += nread;
buf += nread;
f->len -= nread;
f->head += nread;
f->head %= f->n;
}
return count;
}
int msnd_fifo_read(msnd_fifo *f, char *buf, size_t len)
{
int count = 0;
while ((count < len) && (f->len > 0)) {
int nread;
if (f->tail <= f->head) {
nread = len - count;
if (nread > f->n - f->head)
nread = f->n - f->head;
}
else {
nread = f->tail - f->head;
if (nread > len - count)
nread = len - count;
}
memcpy(buf, f->data + f->head, nread);
count += nread;
buf += nread;
f->len -= nread;
f->head += nread;
f->head %= f->n;
}
return count;
}
static int msnd_wait_TXDE(multisound_dev_t *dev)
{
register unsigned int io = dev->io;
register int timeout = 1000;
while(timeout-- > 0)
if (msnd_inb(io + HP_ISR) & HPISR_TXDE)
return 0;
return -EIO;
}
static int msnd_wait_HC0(multisound_dev_t *dev)
{
register unsigned int io = dev->io;
register int timeout = 1000;
while(timeout-- > 0)
if (!(msnd_inb(io + HP_CVR) & HPCVR_HC))
return 0;
return -EIO;
}
int msnd_send_dsp_cmd(multisound_dev_t *dev, BYTE cmd)
{
unsigned long flags;
spin_lock_irqsave(&dev->lock, flags);
if (msnd_wait_HC0(dev) == 0) {
msnd_outb(cmd, dev->io + HP_CVR);
spin_unlock_irqrestore(&dev->lock, flags);
return 0;
}
spin_unlock_irqrestore(&dev->lock, flags);
printk(KERN_DEBUG LOGNAME ": Send DSP command timeout\n");
return -EIO;
}
int msnd_send_word(multisound_dev_t *dev, unsigned char high,
unsigned char mid, unsigned char low)
{
register unsigned int io = dev->io;
if (msnd_wait_TXDE(dev) == 0) {
msnd_outb(high, io + HP_TXH);
msnd_outb(mid, io + HP_TXM);
msnd_outb(low, io + HP_TXL);
return 0;
}
printk(KERN_DEBUG LOGNAME ": Send host word timeout\n");
return -EIO;
}
int msnd_upload_host(multisound_dev_t *dev, char *bin, int len)
{
int i;
if (len % 3 != 0) {
printk(KERN_WARNING LOGNAME ": Upload host data not multiple of 3!\n");
return -EINVAL;
}
for (i = 0; i < len; i += 3)
if (msnd_send_word(dev, bin[i], bin[i + 1], bin[i + 2]) != 0)
return -EIO;
msnd_inb(dev->io + HP_RXL);
msnd_inb(dev->io + HP_CVR);
return 0;
}
int msnd_enable_irq(multisound_dev_t *dev)
{
unsigned long flags;
if (dev->irq_ref++)
return 0;
printk(KERN_DEBUG LOGNAME ": Enabling IRQ\n");
spin_lock_irqsave(&dev->lock, flags);
if (msnd_wait_TXDE(dev) == 0) {
msnd_outb(msnd_inb(dev->io + HP_ICR) | HPICR_TREQ, dev->io + HP_ICR);
if (dev->type == msndClassic)
msnd_outb(dev->irqid, dev->io + HP_IRQM);
msnd_outb(msnd_inb(dev->io + HP_ICR) & ~HPICR_TREQ, dev->io + HP_ICR);
msnd_outb(msnd_inb(dev->io + HP_ICR) | HPICR_RREQ, dev->io + HP_ICR);
enable_irq(dev->irq);
msnd_init_queue(dev->DSPQ, dev->dspq_data_buff, dev->dspq_buff_size);
spin_unlock_irqrestore(&dev->lock, flags);
return 0;
}
spin_unlock_irqrestore(&dev->lock, flags);
printk(KERN_DEBUG LOGNAME ": Enable IRQ failed\n");
return -EIO;
}
int msnd_disable_irq(multisound_dev_t *dev)
{
unsigned long flags;
if (--dev->irq_ref > 0)
return 0;
if (dev->irq_ref < 0)
printk(KERN_DEBUG LOGNAME ": IRQ ref count is %d\n", dev->irq_ref);
printk(KERN_DEBUG LOGNAME ": Disabling IRQ\n");
spin_lock_irqsave(&dev->lock, flags);
if (msnd_wait_TXDE(dev) == 0) {
msnd_outb(msnd_inb(dev->io + HP_ICR) & ~HPICR_RREQ, dev->io + HP_ICR);
if (dev->type == msndClassic)
msnd_outb(HPIRQ_NONE, dev->io + HP_IRQM);
disable_irq(dev->irq);
spin_unlock_irqrestore(&dev->lock, flags);
return 0;
}
spin_unlock_irqrestore(&dev->lock, flags);
printk(KERN_DEBUG LOGNAME ": Disable IRQ failed\n");
return -EIO;
}
int init_module(void)
{
return 0;
}
void cleanup_module(void)
{
}
