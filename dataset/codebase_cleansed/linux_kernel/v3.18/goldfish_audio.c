static ssize_t goldfish_audio_read(struct file *fp, char __user *buf,
size_t count, loff_t *pos)
{
struct goldfish_audio *data = fp->private_data;
int length;
int result = 0;
if (!data->read_supported)
return -ENODEV;
while (count > 0) {
length = (count > READ_BUFFER_SIZE ? READ_BUFFER_SIZE : count);
AUDIO_WRITE(data, AUDIO_START_READ, length);
wait_event_interruptible(data->wait, (data->buffer_status &
AUDIO_INT_READ_BUFFER_FULL));
length = AUDIO_READ(data, AUDIO_READ_BUFFER_AVAILABLE);
if (copy_to_user(buf, data->read_buffer, length))
return -EFAULT;
result += length;
buf += length;
count -= length;
}
return result;
}
static ssize_t goldfish_audio_write(struct file *fp, const char __user *buf,
size_t count, loff_t *pos)
{
struct goldfish_audio *data = fp->private_data;
unsigned long irq_flags;
ssize_t result = 0;
char __iomem *kbuf;
while (count > 0) {
ssize_t copy = count;
if (copy > WRITE_BUFFER_SIZE)
copy = WRITE_BUFFER_SIZE;
wait_event_interruptible(data->wait, (data->buffer_status &
(AUDIO_INT_WRITE_BUFFER_1_EMPTY |
AUDIO_INT_WRITE_BUFFER_2_EMPTY)));
if ((data->buffer_status & AUDIO_INT_WRITE_BUFFER_1_EMPTY) != 0)
kbuf = data->write_buffer1;
else
kbuf = data->write_buffer2;
if (copy_from_user(kbuf, buf, copy)) {
result = -EFAULT;
break;
}
spin_lock_irqsave(&data->lock, irq_flags);
if (kbuf == data->write_buffer1) {
data->buffer_status &= ~AUDIO_INT_WRITE_BUFFER_1_EMPTY;
AUDIO_WRITE(data, AUDIO_WRITE_BUFFER_1, copy);
} else {
data->buffer_status &= ~AUDIO_INT_WRITE_BUFFER_2_EMPTY;
AUDIO_WRITE(data, AUDIO_WRITE_BUFFER_2, copy);
}
spin_unlock_irqrestore(&data->lock, irq_flags);
buf += copy;
result += copy;
count -= copy;
}
return result;
}
static int goldfish_audio_open(struct inode *ip, struct file *fp)
{
if (!audio_data)
return -ENODEV;
if (atomic_inc_return(&open_count) == 1) {
fp->private_data = audio_data;
audio_data->buffer_status = (AUDIO_INT_WRITE_BUFFER_1_EMPTY |
AUDIO_INT_WRITE_BUFFER_2_EMPTY);
AUDIO_WRITE(audio_data, AUDIO_INT_ENABLE, AUDIO_INT_MASK);
return 0;
}
atomic_dec(&open_count);
return -EBUSY;
}
static int goldfish_audio_release(struct inode *ip, struct file *fp)
{
atomic_dec(&open_count);
AUDIO_WRITE(audio_data, AUDIO_INT_ENABLE, 0);
return 0;
}
static long goldfish_audio_ioctl(struct file *fp, unsigned int cmd,
unsigned long arg)
{
if (cmd == 315)
return -1;
return 0;
}
static irqreturn_t goldfish_audio_interrupt(int irq, void *dev_id)
{
unsigned long irq_flags;
struct goldfish_audio *data = dev_id;
u32 status;
spin_lock_irqsave(&data->lock, irq_flags);
status = AUDIO_READ(data, AUDIO_INT_STATUS);
status &= AUDIO_INT_MASK;
if (status) {
data->buffer_status = status;
wake_up(&data->wait);
}
spin_unlock_irqrestore(&data->lock, irq_flags);
return status ? IRQ_HANDLED : IRQ_NONE;
}
static int goldfish_audio_probe(struct platform_device *pdev)
{
int ret;
struct resource *r;
struct goldfish_audio *data;
dma_addr_t buf_addr;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
spin_lock_init(&data->lock);
init_waitqueue_head(&data->wait);
platform_set_drvdata(pdev, data);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (r == NULL) {
dev_err(&pdev->dev, "platform_get_resource failed\n");
return -ENODEV;
}
data->reg_base = devm_ioremap(&pdev->dev, r->start, PAGE_SIZE);
if (data->reg_base == NULL)
return -ENOMEM;
data->irq = platform_get_irq(pdev, 0);
if (data->irq < 0) {
dev_err(&pdev->dev, "platform_get_irq failed\n");
return -ENODEV;
}
data->buffer_virt = dmam_alloc_coherent(&pdev->dev,
COMBINED_BUFFER_SIZE, &buf_addr, GFP_KERNEL);
if (data->buffer_virt == NULL) {
dev_err(&pdev->dev, "allocate buffer failed\n");
return -ENOMEM;
}
data->buffer_phys = buf_addr;
data->write_buffer1 = data->buffer_virt;
data->write_buffer2 = data->buffer_virt + WRITE_BUFFER_SIZE;
data->read_buffer = data->buffer_virt + 2 * WRITE_BUFFER_SIZE;
ret = devm_request_irq(&pdev->dev, data->irq, goldfish_audio_interrupt,
IRQF_SHARED, pdev->name, data);
if (ret) {
dev_err(&pdev->dev, "request_irq failed\n");
return ret;
}
ret = misc_register(&goldfish_audio_device);
if (ret) {
dev_err(&pdev->dev,
"misc_register returned %d in goldfish_audio_init\n",
ret);
return ret;
}
AUDIO_WRITE64(data, AUDIO_SET_WRITE_BUFFER_1,
AUDIO_SET_WRITE_BUFFER_1_HIGH, buf_addr);
buf_addr += WRITE_BUFFER_SIZE;
AUDIO_WRITE64(data, AUDIO_SET_WRITE_BUFFER_2,
AUDIO_SET_WRITE_BUFFER_2_HIGH, buf_addr);
buf_addr += WRITE_BUFFER_SIZE;
data->read_supported = AUDIO_READ(data, AUDIO_READ_SUPPORTED);
if (data->read_supported)
AUDIO_WRITE64(data, AUDIO_SET_READ_BUFFER,
AUDIO_SET_READ_BUFFER_HIGH, buf_addr);
audio_data = data;
return 0;
}
static int goldfish_audio_remove(struct platform_device *pdev)
{
misc_deregister(&goldfish_audio_device);
audio_data = NULL;
return 0;
}
