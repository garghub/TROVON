static int goldfish_cmd_locked(struct goldfish_pipe *pipe, enum PipeCmdCode cmd)
{
pipe->command_buffer->cmd = cmd;
pipe->command_buffer->status = PIPE_ERROR_INVAL;
writel(pipe->id, pipe->dev->base + PIPE_REG_CMD);
return pipe->command_buffer->status;
}
static int goldfish_cmd(struct goldfish_pipe *pipe, enum PipeCmdCode cmd)
{
int status;
if (mutex_lock_interruptible(&pipe->lock))
return PIPE_ERROR_IO;
status = goldfish_cmd_locked(pipe, cmd);
mutex_unlock(&pipe->lock);
return status;
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
static int pin_user_pages(unsigned long first_page, unsigned long last_page,
unsigned int last_page_size, int is_write,
struct page *pages[MAX_BUFFERS_PER_COMMAND],
unsigned int *iter_last_page_size)
{
int ret;
int requested_pages = ((last_page - first_page) >> PAGE_SHIFT) + 1;
if (requested_pages > MAX_BUFFERS_PER_COMMAND) {
requested_pages = MAX_BUFFERS_PER_COMMAND;
*iter_last_page_size = PAGE_SIZE;
} else {
*iter_last_page_size = last_page_size;
}
ret = get_user_pages_fast(
first_page, requested_pages, !is_write, pages);
if (ret <= 0)
return -EFAULT;
if (ret < requested_pages)
*iter_last_page_size = PAGE_SIZE;
return ret;
}
static void release_user_pages(struct page **pages, int pages_count,
int is_write, s32 consumed_size)
{
int i;
for (i = 0; i < pages_count; i++) {
if (!is_write && consumed_size > 0)
set_page_dirty(pages[i]);
put_page(pages[i]);
}
}
static void populate_rw_params(
struct page **pages, int pages_count,
unsigned long address, unsigned long address_end,
unsigned long first_page, unsigned long last_page,
unsigned int iter_last_page_size, int is_write,
struct goldfish_pipe_command *command)
{
unsigned long xaddr = page_to_phys(pages[0]);
unsigned long xaddr_prev = xaddr;
int buffer_idx = 0;
int i = 1;
int size_on_page = first_page == last_page
? (int)(address_end - address)
: (PAGE_SIZE - (address & ~PAGE_MASK));
command->rw_params.ptrs[0] = (u64)(xaddr | (address & ~PAGE_MASK));
command->rw_params.sizes[0] = size_on_page;
for (; i < pages_count; ++i) {
xaddr = page_to_phys(pages[i]);
size_on_page = (i == pages_count - 1) ?
iter_last_page_size : PAGE_SIZE;
if (xaddr == xaddr_prev + PAGE_SIZE) {
command->rw_params.sizes[buffer_idx] += size_on_page;
} else {
++buffer_idx;
command->rw_params.ptrs[buffer_idx] = (u64)xaddr;
command->rw_params.sizes[buffer_idx] = size_on_page;
}
xaddr_prev = xaddr;
}
command->rw_params.buffers_count = buffer_idx + 1;
}
static int transfer_max_buffers(struct goldfish_pipe *pipe,
unsigned long address, unsigned long address_end, int is_write,
unsigned long last_page, unsigned int last_page_size,
s32 *consumed_size, int *status)
{
static struct page *pages[MAX_BUFFERS_PER_COMMAND];
unsigned long first_page = address & PAGE_MASK;
unsigned int iter_last_page_size;
int pages_count = pin_user_pages(first_page, last_page,
last_page_size, is_write,
pages, &iter_last_page_size);
if (pages_count < 0)
return pages_count;
if (mutex_lock_interruptible(&pipe->lock))
return -ERESTARTSYS;
populate_rw_params(pages, pages_count, address, address_end,
first_page, last_page, iter_last_page_size, is_write,
pipe->command_buffer);
*status = goldfish_cmd_locked(pipe,
is_write ? PIPE_CMD_WRITE : PIPE_CMD_READ);
*consumed_size = pipe->command_buffer->rw_params.consumed_size;
release_user_pages(pages, pages_count, is_write, *consumed_size);
mutex_unlock(&pipe->lock);
return 0;
}
static int wait_for_host_signal(struct goldfish_pipe *pipe, int is_write)
{
u32 wakeBit = is_write ? BIT_WAKE_ON_WRITE : BIT_WAKE_ON_READ;
set_bit(wakeBit, &pipe->flags);
(void)goldfish_cmd(pipe,
is_write ? PIPE_CMD_WAKE_ON_WRITE : PIPE_CMD_WAKE_ON_READ);
while (test_bit(wakeBit, &pipe->flags)) {
if (wait_event_interruptible(
pipe->wake_queue,
!test_bit(wakeBit, &pipe->flags)))
return -ERESTARTSYS;
if (test_bit(BIT_CLOSED_ON_HOST, &pipe->flags))
return -EIO;
}
return 0;
}
static ssize_t goldfish_pipe_read_write(struct file *filp,
char __user *buffer, size_t bufflen, int is_write)
{
struct goldfish_pipe *pipe = filp->private_data;
int count = 0, ret = -EINVAL;
unsigned long address, address_end, last_page;
unsigned int last_page_size;
if (unlikely(test_bit(BIT_CLOSED_ON_HOST, &pipe->flags)))
return -EIO;
if (unlikely(bufflen == 0))
return 0;
if (unlikely(!access_ok(is_write ? VERIFY_WRITE : VERIFY_READ,
buffer, bufflen)))
return -EFAULT;
address = (unsigned long)buffer;
address_end = address + bufflen;
last_page = (address_end - 1) & PAGE_MASK;
last_page_size = ((address_end - 1) & ~PAGE_MASK) + 1;
while (address < address_end) {
s32 consumed_size;
int status;
ret = transfer_max_buffers(pipe, address, address_end, is_write,
last_page, last_page_size, &consumed_size,
&status);
if (ret < 0)
break;
if (consumed_size > 0) {
count += consumed_size;
address += consumed_size;
}
if (status > 0)
continue;
if (status == 0) {
ret = 0;
break;
}
if (count > 0) {
if (status != PIPE_ERROR_AGAIN)
pr_info_ratelimited("goldfish_pipe: backend error %d on %s\n",
status, is_write ? "write" : "read");
break;
}
if (status != PIPE_ERROR_AGAIN ||
(filp->f_flags & O_NONBLOCK) != 0) {
ret = goldfish_pipe_error_convert(status);
break;
}
status = wait_for_host_signal(pipe, is_write);
if (status < 0)
return status;
}
if (count > 0)
return count;
return ret;
}
static ssize_t goldfish_pipe_read(struct file *filp, char __user *buffer,
size_t bufflen, loff_t *ppos)
{
return goldfish_pipe_read_write(filp, buffer, bufflen,
0);
}
static ssize_t goldfish_pipe_write(struct file *filp,
const char __user *buffer, size_t bufflen,
loff_t *ppos)
{
return goldfish_pipe_read_write(filp,
(char __user *)buffer, bufflen,
1);
}
static unsigned int goldfish_pipe_poll(struct file *filp, poll_table *wait)
{
struct goldfish_pipe *pipe = filp->private_data;
unsigned int mask = 0;
int status;
poll_wait(filp, &pipe->wake_queue, wait);
status = goldfish_cmd(pipe, PIPE_CMD_POLL);
if (status < 0)
return -ERESTARTSYS;
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
static void signalled_pipes_add_locked(struct goldfish_pipe_dev *dev,
u32 id, u32 flags)
{
struct goldfish_pipe *pipe;
if (WARN_ON(id >= dev->pipes_capacity))
return;
pipe = dev->pipes[id];
if (!pipe)
return;
pipe->signalled_flags |= flags;
if (pipe->prev_signalled || pipe->next_signalled
|| dev->first_signalled_pipe == pipe)
return;
pipe->next_signalled = dev->first_signalled_pipe;
if (dev->first_signalled_pipe)
dev->first_signalled_pipe->prev_signalled = pipe;
dev->first_signalled_pipe = pipe;
}
static void signalled_pipes_remove_locked(struct goldfish_pipe_dev *dev,
struct goldfish_pipe *pipe) {
if (pipe->prev_signalled)
pipe->prev_signalled->next_signalled = pipe->next_signalled;
if (pipe->next_signalled)
pipe->next_signalled->prev_signalled = pipe->prev_signalled;
if (pipe == dev->first_signalled_pipe)
dev->first_signalled_pipe = pipe->next_signalled;
pipe->prev_signalled = NULL;
pipe->next_signalled = NULL;
}
static struct goldfish_pipe *signalled_pipes_pop_front(
struct goldfish_pipe_dev *dev, int *wakes)
{
struct goldfish_pipe *pipe;
unsigned long flags;
spin_lock_irqsave(&dev->lock, flags);
pipe = dev->first_signalled_pipe;
if (pipe) {
*wakes = pipe->signalled_flags;
pipe->signalled_flags = 0;
dev->first_signalled_pipe = pipe->next_signalled;
if (dev->first_signalled_pipe)
dev->first_signalled_pipe->prev_signalled = NULL;
pipe->next_signalled = NULL;
}
spin_unlock_irqrestore(&dev->lock, flags);
return pipe;
}
static void goldfish_interrupt_task(unsigned long unused)
{
struct goldfish_pipe_dev *dev = pipe_dev;
struct goldfish_pipe *pipe;
int wakes;
while ((pipe = signalled_pipes_pop_front(dev, &wakes)) != NULL) {
if (wakes & PIPE_WAKE_CLOSED) {
pipe->flags = 1 << BIT_CLOSED_ON_HOST;
} else {
if (wakes & PIPE_WAKE_READ)
clear_bit(BIT_WAKE_ON_READ, &pipe->flags);
if (wakes & PIPE_WAKE_WRITE)
clear_bit(BIT_WAKE_ON_WRITE, &pipe->flags);
}
wake_up_interruptible(&pipe->wake_queue);
}
}
static irqreturn_t goldfish_pipe_interrupt(int irq, void *dev_id)
{
u32 count;
u32 i;
unsigned long flags;
struct goldfish_pipe_dev *dev = dev_id;
if (dev != pipe_dev)
return IRQ_NONE;
spin_lock_irqsave(&dev->lock, flags);
count = readl(dev->base + PIPE_REG_GET_SIGNALLED);
if (count == 0) {
spin_unlock_irqrestore(&dev->lock, flags);
return IRQ_NONE;
}
if (count > MAX_SIGNALLED_PIPES)
count = MAX_SIGNALLED_PIPES;
for (i = 0; i < count; ++i)
signalled_pipes_add_locked(dev,
dev->buffers->signalled_pipe_buffers[i].id,
dev->buffers->signalled_pipe_buffers[i].flags);
spin_unlock_irqrestore(&dev->lock, flags);
tasklet_schedule(&goldfish_interrupt_tasklet);
return IRQ_HANDLED;
}
static int get_free_pipe_id_locked(struct goldfish_pipe_dev *dev)
{
int id;
for (id = 0; id < dev->pipes_capacity; ++id)
if (!dev->pipes[id])
return id;
{
u32 new_capacity = 2 * dev->pipes_capacity;
struct goldfish_pipe **pipes =
kcalloc(new_capacity, sizeof(*pipes), GFP_ATOMIC);
if (!pipes)
return -ENOMEM;
memcpy(pipes, dev->pipes, sizeof(*pipes) * dev->pipes_capacity);
kfree(dev->pipes);
dev->pipes = pipes;
id = dev->pipes_capacity;
dev->pipes_capacity = new_capacity;
}
return id;
}
static int goldfish_pipe_open(struct inode *inode, struct file *file)
{
struct goldfish_pipe_dev *dev = pipe_dev;
unsigned long flags;
int id;
int status;
struct goldfish_pipe *pipe = kzalloc(sizeof(*pipe), GFP_KERNEL);
if (pipe == NULL)
return -ENOMEM;
pipe->dev = dev;
mutex_init(&pipe->lock);
init_waitqueue_head(&pipe->wake_queue);
pipe->command_buffer =
(struct goldfish_pipe_command *)__get_free_page(GFP_KERNEL);
if (!pipe->command_buffer) {
status = -ENOMEM;
goto err_pipe;
}
spin_lock_irqsave(&dev->lock, flags);
id = get_free_pipe_id_locked(dev);
if (id < 0) {
status = id;
goto err_id_locked;
}
dev->pipes[id] = pipe;
pipe->id = id;
pipe->command_buffer->id = id;
dev->buffers->open_command_params.rw_params_max_count =
MAX_BUFFERS_PER_COMMAND;
dev->buffers->open_command_params.command_buffer_ptr =
(u64)(unsigned long)__pa(pipe->command_buffer);
status = goldfish_cmd_locked(pipe, PIPE_CMD_OPEN);
spin_unlock_irqrestore(&dev->lock, flags);
if (status < 0)
goto err_cmd;
file->private_data = pipe;
return 0;
err_cmd:
spin_lock_irqsave(&dev->lock, flags);
dev->pipes[id] = NULL;
err_id_locked:
spin_unlock_irqrestore(&dev->lock, flags);
free_page((unsigned long)pipe->command_buffer);
err_pipe:
kfree(pipe);
return status;
}
static int goldfish_pipe_release(struct inode *inode, struct file *filp)
{
unsigned long flags;
struct goldfish_pipe *pipe = filp->private_data;
struct goldfish_pipe_dev *dev = pipe->dev;
(void)goldfish_cmd(pipe, PIPE_CMD_CLOSE);
spin_lock_irqsave(&dev->lock, flags);
dev->pipes[pipe->id] = NULL;
signalled_pipes_remove_locked(dev, pipe);
spin_unlock_irqrestore(&dev->lock, flags);
filp->private_data = NULL;
free_page((unsigned long)pipe->command_buffer);
kfree(pipe);
return 0;
}
static int goldfish_pipe_device_init(struct platform_device *pdev)
{
char *page;
struct goldfish_pipe_dev *dev = pipe_dev;
int err = devm_request_irq(&pdev->dev, dev->irq,
goldfish_pipe_interrupt,
IRQF_SHARED, "goldfish_pipe", dev);
if (err) {
dev_err(&pdev->dev, "unable to allocate IRQ for v2\n");
return err;
}
err = misc_register(&goldfish_pipe_dev);
if (err) {
dev_err(&pdev->dev, "unable to register v2 device\n");
return err;
}
dev->first_signalled_pipe = NULL;
dev->pipes_capacity = INITIAL_PIPES_CAPACITY;
dev->pipes = kcalloc(dev->pipes_capacity, sizeof(*dev->pipes),
GFP_KERNEL);
if (!dev->pipes)
return -ENOMEM;
if (WARN_ON(sizeof(*dev->buffers) > PAGE_SIZE))
return -ENOMEM;
page = (char *)__get_free_page(GFP_KERNEL);
if (!page) {
kfree(dev->pipes);
return -ENOMEM;
}
dev->buffers = (struct goldfish_pipe_dev_buffers *)page;
{
u64 paddr = __pa(&dev->buffers->signalled_pipe_buffers);
writel((u32)(unsigned long)(paddr >> 32),
dev->base + PIPE_REG_SIGNAL_BUFFER_HIGH);
writel((u32)(unsigned long)paddr,
dev->base + PIPE_REG_SIGNAL_BUFFER);
writel((u32)MAX_SIGNALLED_PIPES,
dev->base + PIPE_REG_SIGNAL_BUFFER_COUNT);
paddr = __pa(&dev->buffers->open_command_params);
writel((u32)(unsigned long)(paddr >> 32),
dev->base + PIPE_REG_OPEN_BUFFER_HIGH);
writel((u32)(unsigned long)paddr,
dev->base + PIPE_REG_OPEN_BUFFER);
}
return 0;
}
static void goldfish_pipe_device_deinit(struct platform_device *pdev)
{
struct goldfish_pipe_dev *dev = pipe_dev;
misc_deregister(&goldfish_pipe_dev);
kfree(dev->pipes);
free_page((unsigned long)dev->buffers);
}
static int goldfish_pipe_probe(struct platform_device *pdev)
{
int err;
struct resource *r;
struct goldfish_pipe_dev *dev = pipe_dev;
if (WARN_ON(sizeof(struct goldfish_pipe_command) > PAGE_SIZE))
return -ENOMEM;
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
writel((u32)PIPE_DRIVER_VERSION, dev->base + PIPE_REG_VERSION);
dev->version = readl(dev->base + PIPE_REG_VERSION);
if (WARN_ON(dev->version < PIPE_CURRENT_DEVICE_VERSION))
return -EINVAL;
err = goldfish_pipe_device_init(pdev);
if (!err)
return 0;
error:
dev->base = NULL;
return err;
}
static int goldfish_pipe_remove(struct platform_device *pdev)
{
struct goldfish_pipe_dev *dev = pipe_dev;
goldfish_pipe_device_deinit(pdev);
dev->base = NULL;
return 0;
}
