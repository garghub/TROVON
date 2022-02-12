static u32 goldfish_cmd_status(struct goldfish_pipe *pipe, u32 cmd)
{
unsigned long flags;
u32 status;
struct goldfish_pipe_dev *dev = pipe->dev;
spin_lock_irqsave(&dev->lock, flags);
gf_write_ptr(pipe, dev->base + PIPE_REG_CHANNEL,
dev->base + PIPE_REG_CHANNEL_HIGH);
writel(cmd, dev->base + PIPE_REG_COMMAND);
status = readl(dev->base + PIPE_REG_STATUS);
spin_unlock_irqrestore(&dev->lock, flags);
return status;
}
static void goldfish_cmd(struct goldfish_pipe *pipe, u32 cmd)
{
unsigned long flags;
struct goldfish_pipe_dev *dev = pipe->dev;
spin_lock_irqsave(&dev->lock, flags);
gf_write_ptr(pipe, dev->base + PIPE_REG_CHANNEL,
dev->base + PIPE_REG_CHANNEL_HIGH);
writel(cmd, dev->base + PIPE_REG_COMMAND);
spin_unlock_irqrestore(&dev->lock, flags);
}
static int goldfish_pipe_error_convert(int status)
{
switch (status) {
case PIPE_ERROR_AGAIN:
return -EAGAIN;
case PIPE_ERROR_NOMEM:
return -ENOMEM;
case PIPE_ERROR_IO:
return -EIO;
default:
return -EINVAL;
}
}
static int valid_batchbuffer_addr(struct goldfish_pipe_dev *dev,
struct access_params *aps)
{
u32 aph, apl;
u64 paddr;
aph = readl(dev->base + PIPE_REG_PARAMS_ADDR_HIGH);
apl = readl(dev->base + PIPE_REG_PARAMS_ADDR_LOW);
paddr = ((u64)aph << 32) | apl;
if (paddr != (__pa(aps)))
return 0;
return 1;
}
static int setup_access_params_addr(struct platform_device *pdev,
struct goldfish_pipe_dev *dev)
{
dma_addr_t dma_handle;
struct access_params *aps;
aps = dmam_alloc_coherent(&pdev->dev, sizeof(struct access_params),
&dma_handle, GFP_KERNEL);
if (!aps)
return -ENOMEM;
writel(upper_32_bits(dma_handle), dev->base + PIPE_REG_PARAMS_ADDR_HIGH);
writel(lower_32_bits(dma_handle), dev->base + PIPE_REG_PARAMS_ADDR_LOW);
if (valid_batchbuffer_addr(dev, aps)) {
dev->aps = aps;
return 0;
} else
return -1;
}
static int access_with_param(struct goldfish_pipe_dev *dev, const int cmd,
unsigned long address, unsigned long avail,
struct goldfish_pipe *pipe, int *status)
{
struct access_params *aps = dev->aps;
if (aps == NULL)
return -1;
aps->result = INITIAL_BATCH_RESULT;
aps->channel = (unsigned long)pipe;
aps->size = avail;
aps->address = address;
aps->cmd = cmd;
writel(cmd, dev->base + PIPE_REG_ACCESS_PARAMS);
if (aps->result == INITIAL_BATCH_RESULT)
return -1;
*status = aps->result;
return 0;
}
static ssize_t goldfish_pipe_read_write(struct file *filp, char __user *buffer,
size_t bufflen, int is_write)
{
unsigned long irq_flags;
struct goldfish_pipe *pipe = filp->private_data;
struct goldfish_pipe_dev *dev = pipe->dev;
unsigned long address, address_end;
int count = 0, ret = -EINVAL;
if (test_bit(BIT_CLOSED_ON_HOST, &pipe->flags))
return -EIO;
if (unlikely(bufflen == 0))
return 0;
if (!access_ok(is_write ? VERIFY_WRITE : VERIFY_READ,
buffer, bufflen))
return -EFAULT;
if (mutex_lock_interruptible(&pipe->lock))
return -ERESTARTSYS;
address = (unsigned long)(void *)buffer;
address_end = address + bufflen;
while (address < address_end) {
unsigned long page_end = (address & PAGE_MASK) + PAGE_SIZE;
unsigned long next = page_end < address_end ? page_end
: address_end;
unsigned long avail = next - address;
int status, wakeBit;
struct page *page;
unsigned long xaddr;
down_read(&current->mm->mmap_sem);
ret = get_user_pages(address, 1, !is_write, 0, &page, NULL);
up_read(&current->mm->mmap_sem);
if (ret < 0)
break;
if (dev->version) {
xaddr = page_to_phys(page) | (address & ~PAGE_MASK);
} else {
xaddr = address;
}
spin_lock_irqsave(&dev->lock, irq_flags);
if (access_with_param(dev,
is_write ? CMD_WRITE_BUFFER : CMD_READ_BUFFER,
xaddr, avail, pipe, &status)) {
gf_write_ptr(pipe, dev->base + PIPE_REG_CHANNEL,
dev->base + PIPE_REG_CHANNEL_HIGH);
writel(avail, dev->base + PIPE_REG_SIZE);
gf_write_ptr((void *)xaddr,
dev->base + PIPE_REG_ADDRESS,
dev->base + PIPE_REG_ADDRESS_HIGH);
writel(is_write ? CMD_WRITE_BUFFER : CMD_READ_BUFFER,
dev->base + PIPE_REG_COMMAND);
status = readl(dev->base + PIPE_REG_STATUS);
}
spin_unlock_irqrestore(&dev->lock, irq_flags);
if (status > 0 && !is_write)
set_page_dirty(page);
put_page(page);
if (status > 0) {
count += status;
address += status;
continue;
} else if (status == 0) {
ret = 0;
break;
} else if (status < 0 && count > 0) {
if (status != PIPE_ERROR_AGAIN)
pr_info_ratelimited("goldfish_pipe: backend returned error %d on %s\n",
status, is_write ? "write" : "read");
ret = 0;
break;
}
if (status != PIPE_ERROR_AGAIN ||
(filp->f_flags & O_NONBLOCK) != 0) {
ret = goldfish_pipe_error_convert(status);
break;
}
wakeBit = is_write ? BIT_WAKE_ON_WRITE : BIT_WAKE_ON_READ;
set_bit(wakeBit, &pipe->flags);
goldfish_cmd(pipe,
is_write ? CMD_WAKE_ON_WRITE : CMD_WAKE_ON_READ);
mutex_unlock(&pipe->lock);
while (test_bit(wakeBit, &pipe->flags)) {
if (wait_event_interruptible(
pipe->wake_queue,
!test_bit(wakeBit, &pipe->flags)))
return -ERESTARTSYS;
if (test_bit(BIT_CLOSED_ON_HOST, &pipe->flags))
return -EIO;
}
if (mutex_lock_interruptible(&pipe->lock))
return -ERESTARTSYS;
}
mutex_unlock(&pipe->lock);
if (ret < 0)
return ret;
else
return count;
}
static ssize_t goldfish_pipe_read(struct file *filp, char __user *buffer,
size_t bufflen, loff_t *ppos)
{
return goldfish_pipe_read_write(filp, buffer, bufflen, 0);
}
static ssize_t goldfish_pipe_write(struct file *filp,
const char __user *buffer, size_t bufflen,
loff_t *ppos)
{
return goldfish_pipe_read_write(filp, (char __user *)buffer,
bufflen, 1);
}
static unsigned int goldfish_pipe_poll(struct file *filp, poll_table *wait)
{
struct goldfish_pipe *pipe = filp->private_data;
unsigned int mask = 0;
int status;
mutex_lock(&pipe->lock);
poll_wait(filp, &pipe->wake_queue, wait);
status = goldfish_cmd_status(pipe, CMD_POLL);
mutex_unlock(&pipe->lock);
if (status & PIPE_POLL_IN)
mask |= POLLIN | POLLRDNORM;
if (status & PIPE_POLL_OUT)
mask |= POLLOUT | POLLWRNORM;
if (status & PIPE_POLL_HUP)
mask |= POLLHUP;
if (test_bit(BIT_CLOSED_ON_HOST, &pipe->flags))
mask |= POLLERR;
return mask;
}
static irqreturn_t goldfish_pipe_interrupt(int irq, void *dev_id)
{
struct goldfish_pipe_dev *dev = dev_id;
unsigned long irq_flags;
int count = 0;
spin_lock_irqsave(&dev->lock, irq_flags);
for (;;) {
struct goldfish_pipe *pipe;
unsigned long wakes;
unsigned long channel = 0;
#ifdef CONFIG_64BIT
channel = (u64)readl(dev->base + PIPE_REG_CHANNEL_HIGH) << 32;
if (channel == 0)
break;
#endif
channel |= readl(dev->base + PIPE_REG_CHANNEL);
if (channel == 0)
break;
wakes = readl(dev->base + PIPE_REG_WAKES);
pipe = (struct goldfish_pipe *)(ptrdiff_t)channel;
if (wakes & PIPE_WAKE_CLOSED) {
set_bit(BIT_CLOSED_ON_HOST, &pipe->flags);
wakes |= PIPE_WAKE_READ | PIPE_WAKE_WRITE;
}
if (wakes & PIPE_WAKE_READ)
clear_bit(BIT_WAKE_ON_READ, &pipe->flags);
if (wakes & PIPE_WAKE_WRITE)
clear_bit(BIT_WAKE_ON_WRITE, &pipe->flags);
wake_up_interruptible(&pipe->wake_queue);
count++;
}
spin_unlock_irqrestore(&dev->lock, irq_flags);
return (count == 0) ? IRQ_NONE : IRQ_HANDLED;
}
static int goldfish_pipe_open(struct inode *inode, struct file *file)
{
struct goldfish_pipe *pipe;
struct goldfish_pipe_dev *dev = pipe_dev;
int32_t status;
pipe = kzalloc(sizeof(*pipe), GFP_KERNEL);
if (pipe == NULL)
return -ENOMEM;
pipe->dev = dev;
mutex_init(&pipe->lock);
init_waitqueue_head(&pipe->wake_queue);
status = goldfish_cmd_status(pipe, CMD_OPEN);
if (status < 0) {
kfree(pipe);
return status;
}
file->private_data = pipe;
return 0;
}
static int goldfish_pipe_release(struct inode *inode, struct file *filp)
{
struct goldfish_pipe *pipe = filp->private_data;
goldfish_cmd(pipe, CMD_CLOSE);
kfree(pipe);
filp->private_data = NULL;
return 0;
}
static int goldfish_pipe_probe(struct platform_device *pdev)
{
int err;
struct resource *r;
struct goldfish_pipe_dev *dev = pipe_dev;
WARN_ON(dev->base != NULL);
spin_lock_init(&dev->lock);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (r == NULL || resource_size(r) < PAGE_SIZE) {
dev_err(&pdev->dev, "can't allocate i/o page\n");
return -EINVAL;
}
dev->base = devm_ioremap(&pdev->dev, r->start, PAGE_SIZE);
if (dev->base == NULL) {
dev_err(&pdev->dev, "ioremap failed\n");
return -EINVAL;
}
r = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (r == NULL) {
err = -EINVAL;
goto error;
}
dev->irq = r->start;
err = devm_request_irq(&pdev->dev, dev->irq, goldfish_pipe_interrupt,
IRQF_SHARED, "goldfish_pipe", dev);
if (err) {
dev_err(&pdev->dev, "unable to allocate IRQ\n");
goto error;
}
err = misc_register(&goldfish_pipe_device);
if (err) {
dev_err(&pdev->dev, "unable to register device\n");
goto error;
}
setup_access_params_addr(pdev, dev);
dev->version = readl(dev->base + PIPE_REG_VERSION);
return 0;
error:
dev->base = NULL;
return err;
}
static int goldfish_pipe_remove(struct platform_device *pdev)
{
struct goldfish_pipe_dev *dev = pipe_dev;
misc_deregister(&goldfish_pipe_device);
dev->base = NULL;
return 0;
}
