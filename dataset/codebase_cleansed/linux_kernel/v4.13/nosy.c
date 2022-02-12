static inline struct pcilynx *
lynx_get(struct pcilynx *lynx)
{
kref_get(&lynx->kref);
return lynx;
}
static void
lynx_release(struct kref *kref)
{
kfree(container_of(kref, struct pcilynx, kref));
}
static inline void
lynx_put(struct pcilynx *lynx)
{
kref_put(&lynx->kref, lynx_release);
}
static int
packet_buffer_init(struct packet_buffer *buffer, size_t capacity)
{
buffer->data = kmalloc(capacity, GFP_KERNEL);
if (buffer->data == NULL)
return -ENOMEM;
buffer->head = (struct packet *) buffer->data;
buffer->tail = (struct packet *) buffer->data;
buffer->capacity = capacity;
buffer->lost_packet_count = 0;
atomic_set(&buffer->size, 0);
init_waitqueue_head(&buffer->wait);
return 0;
}
static void
packet_buffer_destroy(struct packet_buffer *buffer)
{
kfree(buffer->data);
}
static int
packet_buffer_get(struct client *client, char __user *data, size_t user_length)
{
struct packet_buffer *buffer = &client->buffer;
size_t length;
char *end;
if (wait_event_interruptible(buffer->wait,
atomic_read(&buffer->size) > 0) ||
list_empty(&client->lynx->link))
return -ERESTARTSYS;
if (atomic_read(&buffer->size) == 0)
return -ENODEV;
end = buffer->data + buffer->capacity;
length = buffer->head->length;
if (&buffer->head->data[length] < end) {
if (copy_to_user(data, buffer->head->data, length))
return -EFAULT;
buffer->head = (struct packet *) &buffer->head->data[length];
} else {
size_t split = end - buffer->head->data;
if (copy_to_user(data, buffer->head->data, split))
return -EFAULT;
if (copy_to_user(data + split, buffer->data, length - split))
return -EFAULT;
buffer->head = (struct packet *) &buffer->data[length - split];
}
atomic_sub(sizeof(struct packet) + length, &buffer->size);
return length;
}
static void
packet_buffer_put(struct packet_buffer *buffer, void *data, size_t length)
{
char *end;
buffer->total_packet_count++;
if (buffer->capacity <
atomic_read(&buffer->size) + sizeof(struct packet) + length) {
buffer->lost_packet_count++;
return;
}
end = buffer->data + buffer->capacity;
buffer->tail->length = length;
if (&buffer->tail->data[length] < end) {
memcpy(buffer->tail->data, data, length);
buffer->tail = (struct packet *) &buffer->tail->data[length];
} else {
size_t split = end - buffer->tail->data;
memcpy(buffer->tail->data, data, split);
memcpy(buffer->data, data + split, length - split);
buffer->tail = (struct packet *) &buffer->data[length - split];
}
atomic_add(sizeof(struct packet) + length, &buffer->size);
wake_up_interruptible(&buffer->wait);
}
static inline void
reg_write(struct pcilynx *lynx, int offset, u32 data)
{
writel(data, lynx->registers + offset);
}
static inline u32
reg_read(struct pcilynx *lynx, int offset)
{
return readl(lynx->registers + offset);
}
static inline void
reg_set_bits(struct pcilynx *lynx, int offset, u32 mask)
{
reg_write(lynx, offset, (reg_read(lynx, offset) | mask));
}
static inline void
run_pcl(struct pcilynx *lynx, dma_addr_t pcl_bus,
int dmachan)
{
reg_write(lynx, DMA0_CURRENT_PCL + dmachan * 0x20, pcl_bus);
reg_write(lynx, DMA0_CHAN_CTRL + dmachan * 0x20,
DMA_CHAN_CTRL_ENABLE | DMA_CHAN_CTRL_LINK);
}
static int
set_phy_reg(struct pcilynx *lynx, int addr, int val)
{
if (addr > 15) {
dev_err(&lynx->pci_device->dev,
"PHY register address %d out of range\n", addr);
return -1;
}
if (val > 0xff) {
dev_err(&lynx->pci_device->dev,
"PHY register value %d out of range\n", val);
return -1;
}
reg_write(lynx, LINK_PHY, LINK_PHY_WRITE |
LINK_PHY_ADDR(addr) | LINK_PHY_WDATA(val));
return 0;
}
static int
nosy_open(struct inode *inode, struct file *file)
{
int minor = iminor(inode);
struct client *client;
struct pcilynx *tmp, *lynx = NULL;
mutex_lock(&card_mutex);
list_for_each_entry(tmp, &card_list, link)
if (tmp->misc.minor == minor) {
lynx = lynx_get(tmp);
break;
}
mutex_unlock(&card_mutex);
if (lynx == NULL)
return -ENODEV;
client = kmalloc(sizeof *client, GFP_KERNEL);
if (client == NULL)
goto fail;
client->tcode_mask = ~0;
client->lynx = lynx;
INIT_LIST_HEAD(&client->link);
if (packet_buffer_init(&client->buffer, 128 * 1024) < 0)
goto fail;
file->private_data = client;
return nonseekable_open(inode, file);
fail:
kfree(client);
lynx_put(lynx);
return -ENOMEM;
}
static int
nosy_release(struct inode *inode, struct file *file)
{
struct client *client = file->private_data;
struct pcilynx *lynx = client->lynx;
spin_lock_irq(&lynx->client_list_lock);
list_del_init(&client->link);
spin_unlock_irq(&lynx->client_list_lock);
packet_buffer_destroy(&client->buffer);
kfree(client);
lynx_put(lynx);
return 0;
}
static unsigned int
nosy_poll(struct file *file, poll_table *pt)
{
struct client *client = file->private_data;
unsigned int ret = 0;
poll_wait(file, &client->buffer.wait, pt);
if (atomic_read(&client->buffer.size) > 0)
ret = POLLIN | POLLRDNORM;
if (list_empty(&client->lynx->link))
ret |= POLLHUP;
return ret;
}
static ssize_t
nosy_read(struct file *file, char __user *buffer, size_t count, loff_t *offset)
{
struct client *client = file->private_data;
return packet_buffer_get(client, buffer, count);
}
static long
nosy_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
struct client *client = file->private_data;
spinlock_t *client_list_lock = &client->lynx->client_list_lock;
struct nosy_stats stats;
switch (cmd) {
case NOSY_IOC_GET_STATS:
spin_lock_irq(client_list_lock);
stats.total_packet_count = client->buffer.total_packet_count;
stats.lost_packet_count = client->buffer.lost_packet_count;
spin_unlock_irq(client_list_lock);
if (copy_to_user((void __user *) arg, &stats, sizeof stats))
return -EFAULT;
else
return 0;
case NOSY_IOC_START:
spin_lock_irq(client_list_lock);
list_add_tail(&client->link, &client->lynx->client_list);
spin_unlock_irq(client_list_lock);
return 0;
case NOSY_IOC_STOP:
spin_lock_irq(client_list_lock);
list_del_init(&client->link);
spin_unlock_irq(client_list_lock);
return 0;
case NOSY_IOC_FILTER:
spin_lock_irq(client_list_lock);
client->tcode_mask = arg;
spin_unlock_irq(client_list_lock);
return 0;
default:
return -EINVAL;
}
}
static void
packet_irq_handler(struct pcilynx *lynx)
{
struct client *client;
u32 tcode_mask, tcode, timestamp;
size_t length;
struct timespec64 ts64;
length = __le32_to_cpu(lynx->rcv_pcl->pcl_status) & 0x00001fff;
tcode = __le32_to_cpu(lynx->rcv_buffer[1]) >> 4 & 0xf;
ktime_get_real_ts64(&ts64);
timestamp = ts64.tv_nsec / NSEC_PER_USEC;
lynx->rcv_buffer[0] = (__force __le32)timestamp;
if (length == PHY_PACKET_SIZE)
tcode_mask = 1 << TCODE_PHY_PACKET;
else
tcode_mask = 1 << tcode;
spin_lock(&lynx->client_list_lock);
list_for_each_entry(client, &lynx->client_list, link)
if (client->tcode_mask & tcode_mask)
packet_buffer_put(&client->buffer,
lynx->rcv_buffer, length + 4);
spin_unlock(&lynx->client_list_lock);
}
static void
bus_reset_irq_handler(struct pcilynx *lynx)
{
struct client *client;
struct timespec64 ts64;
u32 timestamp;
ktime_get_real_ts64(&ts64);
timestamp = ts64.tv_nsec / NSEC_PER_USEC;
spin_lock(&lynx->client_list_lock);
list_for_each_entry(client, &lynx->client_list, link)
packet_buffer_put(&client->buffer, &timestamp, 4);
spin_unlock(&lynx->client_list_lock);
}
static irqreturn_t
irq_handler(int irq, void *device)
{
struct pcilynx *lynx = device;
u32 pci_int_status;
pci_int_status = reg_read(lynx, PCI_INT_STATUS);
if (pci_int_status == ~0)
return IRQ_NONE;
if ((pci_int_status & PCI_INT_INT_PEND) == 0)
return IRQ_NONE;
if ((pci_int_status & PCI_INT_P1394_INT) != 0) {
u32 link_int_status;
link_int_status = reg_read(lynx, LINK_INT_STATUS);
reg_write(lynx, LINK_INT_STATUS, link_int_status);
if ((link_int_status & LINK_INT_PHY_BUSRESET) > 0)
bus_reset_irq_handler(lynx);
}
reg_write(lynx, PCI_INT_STATUS, pci_int_status);
if ((pci_int_status & PCI_INT_DMA0_HLT) > 0) {
packet_irq_handler(lynx);
run_pcl(lynx, lynx->rcv_start_pcl_bus, 0);
}
return IRQ_HANDLED;
}
static void
remove_card(struct pci_dev *dev)
{
struct pcilynx *lynx = pci_get_drvdata(dev);
struct client *client;
mutex_lock(&card_mutex);
list_del_init(&lynx->link);
misc_deregister(&lynx->misc);
mutex_unlock(&card_mutex);
reg_write(lynx, PCI_INT_ENABLE, 0);
free_irq(lynx->pci_device->irq, lynx);
spin_lock_irq(&lynx->client_list_lock);
list_for_each_entry(client, &lynx->client_list, link)
wake_up_interruptible(&client->buffer.wait);
spin_unlock_irq(&lynx->client_list_lock);
pci_free_consistent(lynx->pci_device, sizeof(struct pcl),
lynx->rcv_start_pcl, lynx->rcv_start_pcl_bus);
pci_free_consistent(lynx->pci_device, sizeof(struct pcl),
lynx->rcv_pcl, lynx->rcv_pcl_bus);
pci_free_consistent(lynx->pci_device, PAGE_SIZE,
lynx->rcv_buffer, lynx->rcv_buffer_bus);
iounmap(lynx->registers);
pci_disable_device(dev);
lynx_put(lynx);
}
static int
add_card(struct pci_dev *dev, const struct pci_device_id *unused)
{
struct pcilynx *lynx;
u32 p, end;
int ret, i;
if (pci_set_dma_mask(dev, DMA_BIT_MASK(32))) {
dev_err(&dev->dev,
"DMA address limits not supported for PCILynx hardware\n");
return -ENXIO;
}
if (pci_enable_device(dev)) {
dev_err(&dev->dev, "Failed to enable PCILynx hardware\n");
return -ENXIO;
}
pci_set_master(dev);
lynx = kzalloc(sizeof *lynx, GFP_KERNEL);
if (lynx == NULL) {
dev_err(&dev->dev, "Failed to allocate control structure\n");
ret = -ENOMEM;
goto fail_disable;
}
lynx->pci_device = dev;
pci_set_drvdata(dev, lynx);
spin_lock_init(&lynx->client_list_lock);
INIT_LIST_HEAD(&lynx->client_list);
kref_init(&lynx->kref);
lynx->registers = ioremap_nocache(pci_resource_start(dev, 0),
PCILYNX_MAX_REGISTER);
if (lynx->registers == NULL) {
dev_err(&dev->dev, "Failed to map registers\n");
ret = -ENOMEM;
goto fail_deallocate_lynx;
}
lynx->rcv_start_pcl = pci_alloc_consistent(lynx->pci_device,
sizeof(struct pcl), &lynx->rcv_start_pcl_bus);
lynx->rcv_pcl = pci_alloc_consistent(lynx->pci_device,
sizeof(struct pcl), &lynx->rcv_pcl_bus);
lynx->rcv_buffer = pci_alloc_consistent(lynx->pci_device,
RCV_BUFFER_SIZE, &lynx->rcv_buffer_bus);
if (lynx->rcv_start_pcl == NULL ||
lynx->rcv_pcl == NULL ||
lynx->rcv_buffer == NULL) {
dev_err(&dev->dev, "Failed to allocate receive buffer\n");
ret = -ENOMEM;
goto fail_deallocate_buffers;
}
lynx->rcv_start_pcl->next = cpu_to_le32(lynx->rcv_pcl_bus);
lynx->rcv_pcl->next = cpu_to_le32(PCL_NEXT_INVALID);
lynx->rcv_pcl->async_error_next = cpu_to_le32(PCL_NEXT_INVALID);
lynx->rcv_pcl->buffer[0].control =
cpu_to_le32(PCL_CMD_RCV | PCL_BIGENDIAN | 2044);
lynx->rcv_pcl->buffer[0].pointer =
cpu_to_le32(lynx->rcv_buffer_bus + 4);
p = lynx->rcv_buffer_bus + 2048;
end = lynx->rcv_buffer_bus + RCV_BUFFER_SIZE;
for (i = 1; p < end; i++, p += 2048) {
lynx->rcv_pcl->buffer[i].control =
cpu_to_le32(PCL_CMD_RCV | PCL_BIGENDIAN | 2048);
lynx->rcv_pcl->buffer[i].pointer = cpu_to_le32(p);
}
lynx->rcv_pcl->buffer[i - 1].control |= cpu_to_le32(PCL_LAST_BUFF);
reg_set_bits(lynx, MISC_CONTROL, MISC_CONTROL_SWRESET);
reg_write(lynx, DMA0_CHAN_CTRL, 0);
reg_write(lynx, DMA_GLOBAL_REGISTER, 0x00 << 24);
#if 0
if ((get_phy_reg(lynx, 2) & 0xe0) == 0xe0) {
lynx->phyic.reg_1394a = 1;
PRINT(KERN_INFO, lynx->id,
"found 1394a conform PHY (using extended register set)");
lynx->phyic.vendor = get_phy_vendorid(lynx);
lynx->phyic.product = get_phy_productid(lynx);
} else {
lynx->phyic.reg_1394a = 0;
PRINT(KERN_INFO, lynx->id, "found old 1394 PHY");
}
#endif
reg_write(lynx, FIFO_SIZES, 255);
reg_set_bits(lynx, PCI_INT_ENABLE, PCI_INT_DMA_ALL);
reg_write(lynx, LINK_INT_ENABLE,
LINK_INT_PHY_TIME_OUT | LINK_INT_PHY_REG_RCVD |
LINK_INT_PHY_BUSRESET | LINK_INT_IT_STUCK |
LINK_INT_AT_STUCK | LINK_INT_SNTRJ |
LINK_INT_TC_ERR | LINK_INT_GRF_OVER_FLOW |
LINK_INT_ITF_UNDER_FLOW | LINK_INT_ATF_UNDER_FLOW);
set_phy_reg(lynx, 4, 0);
reg_set_bits(lynx, LINK_CONTROL, LINK_CONTROL_SNOOP_ENABLE);
run_pcl(lynx, lynx->rcv_start_pcl_bus, 0);
if (request_irq(dev->irq, irq_handler, IRQF_SHARED,
driver_name, lynx)) {
dev_err(&dev->dev,
"Failed to allocate shared interrupt %d\n", dev->irq);
ret = -EIO;
goto fail_deallocate_buffers;
}
lynx->misc.parent = &dev->dev;
lynx->misc.minor = MISC_DYNAMIC_MINOR;
lynx->misc.name = "nosy";
lynx->misc.fops = &nosy_ops;
mutex_lock(&card_mutex);
ret = misc_register(&lynx->misc);
if (ret) {
dev_err(&dev->dev, "Failed to register misc char device\n");
mutex_unlock(&card_mutex);
goto fail_free_irq;
}
list_add_tail(&lynx->link, &card_list);
mutex_unlock(&card_mutex);
dev_info(&dev->dev,
"Initialized PCILynx IEEE1394 card, irq=%d\n", dev->irq);
return 0;
fail_free_irq:
reg_write(lynx, PCI_INT_ENABLE, 0);
free_irq(lynx->pci_device->irq, lynx);
fail_deallocate_buffers:
if (lynx->rcv_start_pcl)
pci_free_consistent(lynx->pci_device, sizeof(struct pcl),
lynx->rcv_start_pcl, lynx->rcv_start_pcl_bus);
if (lynx->rcv_pcl)
pci_free_consistent(lynx->pci_device, sizeof(struct pcl),
lynx->rcv_pcl, lynx->rcv_pcl_bus);
if (lynx->rcv_buffer)
pci_free_consistent(lynx->pci_device, PAGE_SIZE,
lynx->rcv_buffer, lynx->rcv_buffer_bus);
iounmap(lynx->registers);
fail_deallocate_lynx:
kfree(lynx);
fail_disable:
pci_disable_device(dev);
return ret;
}
