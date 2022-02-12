static int configure_channel(struct most_interface *most_iface,
int ch_idx,
struct most_channel_config *channel_config)
{
struct hdm_i2c *dev = to_hdm(most_iface);
BUG_ON(ch_idx < 0 || ch_idx >= NUM_CHANNELS);
BUG_ON(dev->is_open[ch_idx]);
if (channel_config->data_type != MOST_CH_CONTROL) {
pr_err("bad data type for channel %d\n", ch_idx);
return -EPERM;
}
if (channel_config->direction != dev->capabilities[ch_idx].direction) {
pr_err("bad direction for channel %d\n", ch_idx);
return -EPERM;
}
if ((channel_config->direction == MOST_CH_RX) && (dev->polling_mode)) {
schedule_delayed_work(&dev->rx.dwork,
msecs_to_jiffies(MSEC_PER_SEC / 4));
}
dev->is_open[ch_idx] = true;
return 0;
}
static int enqueue(struct most_interface *most_iface,
int ch_idx, struct mbo *mbo)
{
struct hdm_i2c *dev = to_hdm(most_iface);
int ret;
BUG_ON(ch_idx < 0 || ch_idx >= NUM_CHANNELS);
BUG_ON(!dev->is_open[ch_idx]);
if (ch_idx == CH_RX) {
mutex_lock(&dev->rx.list_mutex);
list_add_tail(&mbo->list, &dev->rx.list);
mutex_unlock(&dev->rx.list_mutex);
wake_up_interruptible(&dev->rx.waitq);
} else {
ret = i2c_master_send(dev->client, mbo->virt_address,
mbo->buffer_length);
if (ret <= 0) {
mbo->processed_length = 0;
mbo->status = MBO_E_INVAL;
} else {
mbo->processed_length = mbo->buffer_length;
mbo->status = MBO_SUCCESS;
}
mbo->complete(mbo);
}
return 0;
}
static int poison_channel(struct most_interface *most_iface,
int ch_idx)
{
struct hdm_i2c *dev = to_hdm(most_iface);
struct mbo *mbo;
BUG_ON(ch_idx < 0 || ch_idx >= NUM_CHANNELS);
BUG_ON(!dev->is_open[ch_idx]);
dev->is_open[ch_idx] = false;
if (ch_idx == CH_RX) {
mutex_lock(&dev->rx.list_mutex);
while (!list_empty(&dev->rx.list)) {
mbo = list_first_mbo(&dev->rx.list);
list_del(&mbo->list);
mutex_unlock(&dev->rx.list_mutex);
mbo->processed_length = 0;
mbo->status = MBO_E_CLOSE;
mbo->complete(mbo);
mutex_lock(&dev->rx.list_mutex);
}
mutex_unlock(&dev->rx.list_mutex);
wake_up_interruptible(&dev->rx.waitq);
}
return 0;
}
static void do_rx_work(struct hdm_i2c *dev)
{
struct mbo *mbo;
unsigned char msg[MAX_BUF_SIZE_CONTROL];
int ret, ch_idx = CH_RX;
u16 pml, data_size;
ret = i2c_master_recv(dev->client, msg, 2);
if (ret <= 0) {
pr_err("Failed to receive PML\n");
return;
}
pml = (msg[0] << 8) | msg[1];
if (!pml)
return;
data_size = pml + 2;
ret = i2c_master_recv(dev->client, msg, data_size);
if (ret <= 0) {
pr_err("Failed to receive a Port Message\n");
return;
}
for (;;) {
if (wait_event_interruptible(dev->rx.waitq,
!dev->is_open[ch_idx] ||
!list_empty(&dev->rx.list))) {
pr_err("wait_event_interruptible() failed\n");
return;
}
if (!dev->is_open[ch_idx])
return;
mutex_lock(&dev->rx.list_mutex);
if (!list_empty(&dev->rx.list))
break;
mutex_unlock(&dev->rx.list_mutex);
}
mbo = list_first_mbo(&dev->rx.list);
list_del(&mbo->list);
mutex_unlock(&dev->rx.list_mutex);
mbo->processed_length = min(data_size, mbo->buffer_length);
memcpy(mbo->virt_address, msg, mbo->processed_length);
mbo->status = MBO_SUCCESS;
mbo->complete(mbo);
}
static void pending_rx_work(struct work_struct *work)
{
struct hdm_i2c *dev = container_of(work, struct hdm_i2c, rx.dwork.work);
do_rx_work(dev);
if (dev->polling_mode) {
if (dev->is_open[CH_RX])
schedule_delayed_work(&dev->rx.dwork,
msecs_to_jiffies(MSEC_PER_SEC
/ scan_rate));
} else {
enable_irq(dev->client->irq);
}
}
static irqreturn_t most_irq_handler(int irq, void *_dev)
{
struct hdm_i2c *dev = _dev;
disable_irq_nosync(irq);
schedule_delayed_work(&dev->rx.dwork, 0);
return IRQ_HANDLED;
}
static int i2c_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
struct hdm_i2c *dev;
int ret, i;
struct kobject *kobj;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
snprintf(dev->name, sizeof(dev->name), "i2c-%d-%04x",
client->adapter->nr, client->addr);
for (i = 0; i < NUM_CHANNELS; i++) {
dev->is_open[i] = false;
dev->capabilities[i].data_type = MOST_CH_CONTROL;
dev->capabilities[i].num_buffers_packet = MAX_BUFFERS_CONTROL;
dev->capabilities[i].buffer_size_packet = MAX_BUF_SIZE_CONTROL;
}
dev->capabilities[CH_RX].direction = MOST_CH_RX;
dev->capabilities[CH_RX].name_suffix = "rx";
dev->capabilities[CH_TX].direction = MOST_CH_TX;
dev->capabilities[CH_TX].name_suffix = "tx";
dev->most_iface.interface = ITYPE_I2C;
dev->most_iface.description = dev->name;
dev->most_iface.num_channels = NUM_CHANNELS;
dev->most_iface.channel_vector = dev->capabilities;
dev->most_iface.configure = configure_channel;
dev->most_iface.enqueue = enqueue;
dev->most_iface.poison_channel = poison_channel;
INIT_LIST_HEAD(&dev->rx.list);
mutex_init(&dev->rx.list_mutex);
init_waitqueue_head(&dev->rx.waitq);
INIT_DELAYED_WORK(&dev->rx.dwork, pending_rx_work);
dev->client = client;
i2c_set_clientdata(client, dev);
kobj = most_register_interface(&dev->most_iface);
if (IS_ERR(kobj)) {
pr_err("Failed to register i2c as a MOST interface\n");
kfree(dev);
return PTR_ERR(kobj);
}
dev->polling_mode = polling_req || client->irq <= 0;
if (!dev->polling_mode) {
pr_info("Requesting IRQ: %d\n", client->irq);
ret = request_irq(client->irq, most_irq_handler, 0,
client->name, dev);
if (ret) {
pr_info("IRQ request failed: %d, falling back to polling\n",
ret);
dev->polling_mode = true;
}
}
if (dev->polling_mode)
pr_info("Using polling at rate: %d times/sec\n", scan_rate);
return 0;
}
static int i2c_remove(struct i2c_client *client)
{
struct hdm_i2c *dev = i2c_get_clientdata(client);
int i;
if (!dev->polling_mode)
free_irq(client->irq, dev);
most_deregister_interface(&dev->most_iface);
for (i = 0 ; i < NUM_CHANNELS; i++)
if (dev->is_open[i])
poison_channel(&dev->most_iface, i);
cancel_delayed_work_sync(&dev->rx.dwork);
kfree(dev);
return 0;
}
