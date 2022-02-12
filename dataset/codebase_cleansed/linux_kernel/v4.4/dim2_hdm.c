bool dim2_sysfs_get_state_cb(void)
{
bool state;
unsigned long flags;
spin_lock_irqsave(&dim_lock, flags);
state = DIM_GetLockState();
spin_unlock_irqrestore(&dim_lock, flags);
return state;
}
u32 DIMCB_IoRead(u32 *ptr32)
{
return __raw_readl(ptr32);
}
void DIMCB_IoWrite(u32 *ptr32, u32 value)
{
__raw_writel(value, ptr32);
}
void DIMCB_OnError(u8 error_id, const char *error_message)
{
pr_err("DIMCB_OnError: error_id - %d, error_message - %s\n", error_id,
error_message);
}
static int startup_dim(struct platform_device *pdev)
{
struct dim2_hdm *dev = platform_get_drvdata(pdev);
struct dim2_platform_data *pdata = pdev->dev.platform_data;
u8 hal_ret;
dev->clk_speed = -1;
if (clock_speed) {
if (!strcmp(clock_speed, "256fs"))
dev->clk_speed = CLK_256FS;
else if (!strcmp(clock_speed, "512fs"))
dev->clk_speed = CLK_512FS;
else if (!strcmp(clock_speed, "1024fs"))
dev->clk_speed = CLK_1024FS;
else if (!strcmp(clock_speed, "2048fs"))
dev->clk_speed = CLK_2048FS;
else if (!strcmp(clock_speed, "3072fs"))
dev->clk_speed = CLK_3072FS;
else if (!strcmp(clock_speed, "4096fs"))
dev->clk_speed = CLK_4096FS;
else if (!strcmp(clock_speed, "6144fs"))
dev->clk_speed = CLK_6144FS;
else if (!strcmp(clock_speed, "8192fs"))
dev->clk_speed = CLK_8192FS;
}
if (dev->clk_speed == -1) {
pr_info("Bad or missing clock speed parameter, using default value: 3072fs\n");
dev->clk_speed = CLK_3072FS;
} else {
pr_info("Selected clock speed: %s\n", clock_speed);
}
if (pdata && pdata->init) {
int ret = pdata->init(pdata, dev->io_base, dev->clk_speed);
if (ret)
return ret;
}
hal_ret = DIM_Startup(dev->io_base, dev->clk_speed);
if (hal_ret != DIM_NO_ERROR) {
pr_err("DIM_Startup failed: %d\n", hal_ret);
if (pdata && pdata->destroy)
pdata->destroy(pdata);
return -ENODEV;
}
return 0;
}
static int try_start_dim_transfer(struct hdm_channel *hdm_ch)
{
u16 buf_size;
struct list_head *head = &hdm_ch->pending_list;
struct mbo *mbo;
unsigned long flags;
struct dim_ch_state_t st;
BUG_ON(!hdm_ch);
BUG_ON(!hdm_ch->is_initialized);
spin_lock_irqsave(&dim_lock, flags);
if (list_empty(head)) {
spin_unlock_irqrestore(&dim_lock, flags);
return -EAGAIN;
}
if (!DIM_GetChannelState(&hdm_ch->ch, &st)->ready) {
spin_unlock_irqrestore(&dim_lock, flags);
return -EAGAIN;
}
mbo = list_entry(head->next, struct mbo, list);
buf_size = mbo->buffer_length;
BUG_ON(mbo->bus_address == 0);
if (!DIM_EnqueueBuffer(&hdm_ch->ch, mbo->bus_address, buf_size)) {
list_del(head->next);
spin_unlock_irqrestore(&dim_lock, flags);
mbo->processed_length = 0;
mbo->status = MBO_E_INVAL;
mbo->complete(mbo);
return -EFAULT;
}
list_move_tail(head->next, &hdm_ch->started_list);
spin_unlock_irqrestore(&dim_lock, flags);
return 0;
}
static int deliver_netinfo_thread(void *data)
{
struct dim2_hdm *dev = data;
while (!kthread_should_stop()) {
wait_event_interruptible(dev->netinfo_waitq,
dev->deliver_netinfo ||
kthread_should_stop());
if (dev->deliver_netinfo) {
dev->deliver_netinfo--;
most_deliver_netinfo(&dev->most_iface, dev->link_state,
dev->mac_addrs);
}
}
return 0;
}
static void retrieve_netinfo(struct dim2_hdm *dev, struct mbo *mbo)
{
u8 *data = mbo->virt_address;
u8 *mac = dev->mac_addrs;
pr_info("Node Address: 0x%03x\n", (u16)data[16] << 8 | data[17]);
dev->link_state = data[18];
pr_info("NIState: %d\n", dev->link_state);
memcpy(mac, data + 19, 6);
pr_info("MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
dev->deliver_netinfo++;
wake_up_interruptible(&dev->netinfo_waitq);
}
static void service_done_flag(struct dim2_hdm *dev, int ch_idx)
{
struct hdm_channel *hdm_ch = dev->hch + ch_idx;
struct dim_ch_state_t st;
struct list_head *head;
struct mbo *mbo;
int done_buffers;
unsigned long flags;
u8 *data;
BUG_ON(!hdm_ch);
BUG_ON(!hdm_ch->is_initialized);
spin_lock_irqsave(&dim_lock, flags);
done_buffers = DIM_GetChannelState(&hdm_ch->ch, &st)->done_buffers;
if (!done_buffers) {
spin_unlock_irqrestore(&dim_lock, flags);
return;
}
if (!DIM_DetachBuffers(&hdm_ch->ch, done_buffers)) {
spin_unlock_irqrestore(&dim_lock, flags);
return;
}
spin_unlock_irqrestore(&dim_lock, flags);
head = &hdm_ch->started_list;
while (done_buffers) {
spin_lock_irqsave(&dim_lock, flags);
if (list_empty(head)) {
spin_unlock_irqrestore(&dim_lock, flags);
pr_crit("hard error: started_mbo list is empty whereas DIM2 has sent buffers\n");
break;
}
mbo = list_entry(head->next, struct mbo, list);
list_del(head->next);
spin_unlock_irqrestore(&dim_lock, flags);
data = mbo->virt_address;
if (hdm_ch->data_type == MOST_CH_ASYNC &&
hdm_ch->direction == MOST_CH_RX &&
PACKET_IS_NET_INFO(data)) {
retrieve_netinfo(dev, mbo);
spin_lock_irqsave(&dim_lock, flags);
list_add_tail(&mbo->list, &hdm_ch->pending_list);
spin_unlock_irqrestore(&dim_lock, flags);
} else {
if (hdm_ch->data_type == MOST_CH_CONTROL ||
hdm_ch->data_type == MOST_CH_ASYNC) {
u32 const data_size =
(u32)data[0] * 256 + data[1] + 2;
mbo->processed_length =
min_t(u32, data_size,
mbo->buffer_length);
} else {
mbo->processed_length = mbo->buffer_length;
}
mbo->status = MBO_SUCCESS;
mbo->complete(mbo);
}
done_buffers--;
}
}
static struct dim_channel **get_active_channels(struct dim2_hdm *dev,
struct dim_channel **buffer)
{
int idx = 0;
int ch_idx;
for (ch_idx = 0; ch_idx < DMA_CHANNELS; ch_idx++) {
if (dev->hch[ch_idx].is_initialized)
buffer[idx++] = &dev->hch[ch_idx].ch;
}
buffer[idx++] = NULL;
return buffer;
}
static void dim2_tasklet_fn(unsigned long data)
{
struct dim2_hdm *dev = (struct dim2_hdm *)data;
unsigned long flags;
int ch_idx;
for (ch_idx = 0; ch_idx < DMA_CHANNELS; ch_idx++) {
if (!dev->hch[ch_idx].is_initialized)
continue;
spin_lock_irqsave(&dim_lock, flags);
DIM_ServiceChannel(&dev->hch[ch_idx].ch);
spin_unlock_irqrestore(&dim_lock, flags);
service_done_flag(dev, ch_idx);
while (!try_start_dim_transfer(dev->hch + ch_idx))
continue;
}
}
static irqreturn_t dim2_ahb_isr(int irq, void *_dev)
{
struct dim2_hdm *dev = _dev;
struct dim_channel *buffer[DMA_CHANNELS + 1];
unsigned long flags;
spin_lock_irqsave(&dim_lock, flags);
DIM_ServiceIrq(get_active_channels(dev, buffer));
spin_unlock_irqrestore(&dim_lock, flags);
#if !defined(ENABLE_HDM_TEST)
dim2_tasklet.data = (unsigned long)dev;
tasklet_schedule(&dim2_tasklet);
#else
dim2_tasklet_fn((unsigned long)dev);
#endif
return IRQ_HANDLED;
}
void raise_dim_interrupt(void)
{
(void)dim2_ahb_isr(0, test_dev);
}
static void complete_all_mbos(struct list_head *head)
{
unsigned long flags;
struct mbo *mbo;
for (;;) {
spin_lock_irqsave(&dim_lock, flags);
if (list_empty(head)) {
spin_unlock_irqrestore(&dim_lock, flags);
break;
}
mbo = list_entry(head->next, struct mbo, list);
list_del(head->next);
spin_unlock_irqrestore(&dim_lock, flags);
mbo->processed_length = 0;
mbo->status = MBO_E_CLOSE;
mbo->complete(mbo);
}
}
static int configure_channel(struct most_interface *most_iface, int ch_idx,
struct most_channel_config *ccfg)
{
struct dim2_hdm *dev = iface_to_hdm(most_iface);
bool const is_tx = ccfg->direction == MOST_CH_TX;
u16 const sub_size = ccfg->subbuffer_size;
u16 const buf_size = ccfg->buffer_size;
u16 new_size;
unsigned long flags;
u8 hal_ret;
int const ch_addr = ch_idx * 2 + 2;
struct hdm_channel *const hdm_ch = dev->hch + ch_idx;
BUG_ON(ch_idx < 0 || ch_idx >= DMA_CHANNELS);
if (hdm_ch->is_initialized)
return -EPERM;
switch (ccfg->data_type) {
case MOST_CH_CONTROL:
new_size = DIM_NormCtrlAsyncBufferSize(buf_size);
if (new_size == 0) {
pr_err("%s: too small buffer size\n", hdm_ch->name);
return -EINVAL;
}
ccfg->buffer_size = new_size;
if (new_size != buf_size)
pr_warn("%s: fixed buffer size (%d -> %d)\n",
hdm_ch->name, buf_size, new_size);
spin_lock_irqsave(&dim_lock, flags);
hal_ret = DIM_InitControl(&hdm_ch->ch, is_tx, ch_addr,
buf_size);
break;
case MOST_CH_ASYNC:
new_size = DIM_NormCtrlAsyncBufferSize(buf_size);
if (new_size == 0) {
pr_err("%s: too small buffer size\n", hdm_ch->name);
return -EINVAL;
}
ccfg->buffer_size = new_size;
if (new_size != buf_size)
pr_warn("%s: fixed buffer size (%d -> %d)\n",
hdm_ch->name, buf_size, new_size);
spin_lock_irqsave(&dim_lock, flags);
hal_ret = DIM_InitAsync(&hdm_ch->ch, is_tx, ch_addr, buf_size);
break;
case MOST_CH_ISOC_AVP:
new_size = DIM_NormIsocBufferSize(buf_size, sub_size);
if (new_size == 0) {
pr_err("%s: invalid sub-buffer size or too small buffer size\n",
hdm_ch->name);
return -EINVAL;
}
ccfg->buffer_size = new_size;
if (new_size != buf_size)
pr_warn("%s: fixed buffer size (%d -> %d)\n",
hdm_ch->name, buf_size, new_size);
spin_lock_irqsave(&dim_lock, flags);
hal_ret = DIM_InitIsoc(&hdm_ch->ch, is_tx, ch_addr, sub_size);
break;
case MOST_CH_SYNC:
new_size = DIM_NormSyncBufferSize(buf_size, sub_size);
if (new_size == 0) {
pr_err("%s: invalid sub-buffer size or too small buffer size\n",
hdm_ch->name);
return -EINVAL;
}
ccfg->buffer_size = new_size;
if (new_size != buf_size)
pr_warn("%s: fixed buffer size (%d -> %d)\n",
hdm_ch->name, buf_size, new_size);
spin_lock_irqsave(&dim_lock, flags);
hal_ret = DIM_InitSync(&hdm_ch->ch, is_tx, ch_addr, sub_size);
break;
default:
pr_err("%s: configure failed, bad channel type: %d\n",
hdm_ch->name, ccfg->data_type);
return -EINVAL;
}
if (hal_ret != DIM_NO_ERROR) {
spin_unlock_irqrestore(&dim_lock, flags);
pr_err("%s: configure failed (%d), type: %d, is_tx: %d\n",
hdm_ch->name, hal_ret, ccfg->data_type, (int)is_tx);
return -ENODEV;
}
hdm_ch->data_type = ccfg->data_type;
hdm_ch->direction = ccfg->direction;
hdm_ch->is_initialized = true;
if (hdm_ch->data_type == MOST_CH_ASYNC &&
hdm_ch->direction == MOST_CH_TX &&
dev->atx_idx < 0)
dev->atx_idx = ch_idx;
spin_unlock_irqrestore(&dim_lock, flags);
return 0;
}
static int enqueue(struct most_interface *most_iface, int ch_idx,
struct mbo *mbo)
{
struct dim2_hdm *dev = iface_to_hdm(most_iface);
struct hdm_channel *hdm_ch = dev->hch + ch_idx;
unsigned long flags;
BUG_ON(ch_idx < 0 || ch_idx >= DMA_CHANNELS);
if (!hdm_ch->is_initialized)
return -EPERM;
if (mbo->bus_address == 0)
return -EFAULT;
spin_lock_irqsave(&dim_lock, flags);
list_add_tail(&mbo->list, &hdm_ch->pending_list);
spin_unlock_irqrestore(&dim_lock, flags);
(void)try_start_dim_transfer(hdm_ch);
return 0;
}
static void request_netinfo(struct most_interface *most_iface, int ch_idx)
{
struct dim2_hdm *dev = iface_to_hdm(most_iface);
struct mbo *mbo;
u8 *data;
if (dev->atx_idx < 0) {
pr_err("Async Tx Not initialized\n");
return;
}
mbo = most_get_mbo(&dev->most_iface, dev->atx_idx, NULL);
if (!mbo)
return;
mbo->buffer_length = 5;
data = mbo->virt_address;
data[0] = 0x00;
data[1] = 0x03;
data[2] = 0x02;
data[3] = 0x08;
data[4] = 0x40;
most_submit_mbo(mbo);
}
static int poison_channel(struct most_interface *most_iface, int ch_idx)
{
struct dim2_hdm *dev = iface_to_hdm(most_iface);
struct hdm_channel *hdm_ch = dev->hch + ch_idx;
unsigned long flags;
u8 hal_ret;
int ret = 0;
BUG_ON(ch_idx < 0 || ch_idx >= DMA_CHANNELS);
if (!hdm_ch->is_initialized)
return -EPERM;
spin_lock_irqsave(&dim_lock, flags);
hal_ret = DIM_DestroyChannel(&hdm_ch->ch);
hdm_ch->is_initialized = false;
if (ch_idx == dev->atx_idx)
dev->atx_idx = -1;
spin_unlock_irqrestore(&dim_lock, flags);
if (hal_ret != DIM_NO_ERROR) {
pr_err("HAL Failed to close channel %s\n", hdm_ch->name);
ret = -EFAULT;
}
complete_all_mbos(&hdm_ch->started_list);
complete_all_mbos(&hdm_ch->pending_list);
return ret;
}
static int dim2_probe(struct platform_device *pdev)
{
struct dim2_hdm *dev;
struct resource *res;
int ret, i;
struct kobject *kobj;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
dev->atx_idx = -1;
platform_set_drvdata(pdev, dev);
#if defined(ENABLE_HDM_TEST)
test_dev = dev;
#else
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
pr_err("no memory region defined\n");
ret = -ENOENT;
goto err_free_dev;
}
if (!request_mem_region(res->start, resource_size(res), pdev->name)) {
pr_err("failed to request mem region\n");
ret = -EBUSY;
goto err_free_dev;
}
dev->io_base = ioremap(res->start, resource_size(res));
if (!dev->io_base) {
pr_err("failed to ioremap\n");
ret = -ENOMEM;
goto err_release_mem;
}
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
pr_err("failed to get irq\n");
goto err_unmap_io;
}
dev->irq_ahb0 = ret;
ret = request_irq(dev->irq_ahb0, dim2_ahb_isr, 0, "mlb_ahb0", dev);
if (ret) {
pr_err("failed to request IRQ: %d, err: %d\n",
dev->irq_ahb0, ret);
goto err_unmap_io;
}
#endif
init_waitqueue_head(&dev->netinfo_waitq);
dev->deliver_netinfo = 0;
dev->netinfo_task = kthread_run(&deliver_netinfo_thread, (void *)dev,
"dim2_netinfo");
if (IS_ERR(dev->netinfo_task)) {
ret = PTR_ERR(dev->netinfo_task);
goto err_free_irq;
}
for (i = 0; i < DMA_CHANNELS; i++) {
struct most_channel_capability *cap = dev->capabilities + i;
struct hdm_channel *hdm_ch = dev->hch + i;
INIT_LIST_HEAD(&hdm_ch->pending_list);
INIT_LIST_HEAD(&hdm_ch->started_list);
hdm_ch->is_initialized = false;
snprintf(hdm_ch->name, sizeof(hdm_ch->name), "ca%d", i * 2 + 2);
cap->name_suffix = hdm_ch->name;
cap->direction = MOST_CH_RX | MOST_CH_TX;
cap->data_type = MOST_CH_CONTROL | MOST_CH_ASYNC |
MOST_CH_ISOC_AVP | MOST_CH_SYNC;
cap->num_buffers_packet = MAX_BUFFERS_PACKET;
cap->buffer_size_packet = MAX_BUF_SIZE_PACKET;
cap->num_buffers_streaming = MAX_BUFFERS_STREAMING;
cap->buffer_size_streaming = MAX_BUF_SIZE_STREAMING;
}
{
const char *fmt;
if (sizeof(res->start) == sizeof(long long))
fmt = "dim2-%016llx";
else if (sizeof(res->start) == sizeof(long))
fmt = "dim2-%016lx";
else
fmt = "dim2-%016x";
snprintf(dev->name, sizeof(dev->name), fmt, res->start);
}
dev->most_iface.interface = ITYPE_MEDIALB_DIM2;
dev->most_iface.description = dev->name;
dev->most_iface.num_channels = DMA_CHANNELS;
dev->most_iface.channel_vector = dev->capabilities;
dev->most_iface.configure = configure_channel;
dev->most_iface.enqueue = enqueue;
dev->most_iface.poison_channel = poison_channel;
dev->most_iface.request_netinfo = request_netinfo;
kobj = most_register_interface(&dev->most_iface);
if (IS_ERR(kobj)) {
ret = PTR_ERR(kobj);
pr_err("failed to register MOST interface\n");
goto err_stop_thread;
}
ret = dim2_sysfs_probe(&dev->bus, kobj);
if (ret)
goto err_unreg_iface;
ret = startup_dim(pdev);
if (ret) {
pr_err("failed to initialize DIM2\n");
goto err_destroy_bus;
}
return 0;
err_destroy_bus:
dim2_sysfs_destroy(&dev->bus);
err_unreg_iface:
most_deregister_interface(&dev->most_iface);
err_stop_thread:
kthread_stop(dev->netinfo_task);
err_free_irq:
#if !defined(ENABLE_HDM_TEST)
free_irq(dev->irq_ahb0, dev);
err_unmap_io:
iounmap(dev->io_base);
err_release_mem:
release_mem_region(res->start, resource_size(res));
err_free_dev:
#endif
kfree(dev);
return ret;
}
static int dim2_remove(struct platform_device *pdev)
{
struct dim2_hdm *dev = platform_get_drvdata(pdev);
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct dim2_platform_data *pdata = pdev->dev.platform_data;
unsigned long flags;
spin_lock_irqsave(&dim_lock, flags);
DIM_Shutdown();
spin_unlock_irqrestore(&dim_lock, flags);
if (pdata && pdata->destroy)
pdata->destroy(pdata);
dim2_sysfs_destroy(&dev->bus);
most_deregister_interface(&dev->most_iface);
kthread_stop(dev->netinfo_task);
#if !defined(ENABLE_HDM_TEST)
free_irq(dev->irq_ahb0, dev);
iounmap(dev->io_base);
release_mem_region(res->start, resource_size(res));
#endif
kfree(dev);
platform_set_drvdata(pdev, NULL);
pdev->id_entry = NULL;
return 0;
}
