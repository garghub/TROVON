static struct glink_channel *glink_rpm_alloc_channel(struct glink_rpm *glink,
const char *name)
{
struct glink_channel *channel;
channel = kzalloc(sizeof(*channel), GFP_KERNEL);
if (!channel)
return ERR_PTR(-ENOMEM);
spin_lock_init(&channel->recv_lock);
channel->glink = glink;
channel->name = kstrdup(name, GFP_KERNEL);
init_completion(&channel->open_req);
init_completion(&channel->open_ack);
kref_init(&channel->refcount);
return channel;
}
static void glink_rpm_channel_release(struct kref *ref)
{
struct glink_channel *channel = container_of(ref, struct glink_channel,
refcount);
kfree(channel->name);
kfree(channel);
}
static size_t glink_rpm_rx_avail(struct glink_rpm *glink)
{
struct glink_rpm_pipe *pipe = &glink->rx_pipe;
unsigned int head;
unsigned int tail;
head = readl(pipe->head);
tail = readl(pipe->tail);
if (head < tail)
return pipe->length - tail + head;
else
return head - tail;
}
static void glink_rpm_rx_peak(struct glink_rpm *glink,
void *data, size_t count)
{
struct glink_rpm_pipe *pipe = &glink->rx_pipe;
unsigned int tail;
size_t len;
tail = readl(pipe->tail);
len = min_t(size_t, count, pipe->length - tail);
if (len) {
__ioread32_copy(data, pipe->fifo + tail,
len / sizeof(u32));
}
if (len != count) {
__ioread32_copy(data + len, pipe->fifo,
(count - len) / sizeof(u32));
}
}
static void glink_rpm_rx_advance(struct glink_rpm *glink,
size_t count)
{
struct glink_rpm_pipe *pipe = &glink->rx_pipe;
unsigned int tail;
tail = readl(pipe->tail);
tail += count;
if (tail >= pipe->length)
tail -= pipe->length;
writel(tail, pipe->tail);
}
static size_t glink_rpm_tx_avail(struct glink_rpm *glink)
{
struct glink_rpm_pipe *pipe = &glink->tx_pipe;
unsigned int head;
unsigned int tail;
head = readl(pipe->head);
tail = readl(pipe->tail);
if (tail <= head)
return pipe->length - head + tail;
else
return tail - head;
}
static unsigned int glink_rpm_tx_write(struct glink_rpm *glink,
unsigned int head,
const void *data, size_t count)
{
struct glink_rpm_pipe *pipe = &glink->tx_pipe;
size_t len;
len = min_t(size_t, count, pipe->length - head);
if (len) {
__iowrite32_copy(pipe->fifo + head, data,
len / sizeof(u32));
}
if (len != count) {
__iowrite32_copy(pipe->fifo, data + len,
(count - len) / sizeof(u32));
}
head += count;
if (head >= pipe->length)
head -= pipe->length;
return head;
}
static int glink_rpm_tx(struct glink_rpm *glink,
const void *hdr, size_t hlen,
const void *data, size_t dlen, bool wait)
{
struct glink_rpm_pipe *pipe = &glink->tx_pipe;
unsigned int head;
unsigned int tlen = hlen + dlen;
int ret;
if (tlen >= glink->tx_pipe.length)
return -EINVAL;
if (WARN(tlen % 8, "Unaligned TX request"))
return -EINVAL;
ret = mutex_lock_interruptible(&glink->tx_lock);
if (ret)
return ret;
while (glink_rpm_tx_avail(glink) < tlen) {
if (!wait) {
ret = -ENOMEM;
goto out;
}
msleep(10);
}
head = readl(pipe->head);
head = glink_rpm_tx_write(glink, head, hdr, hlen);
head = glink_rpm_tx_write(glink, head, data, dlen);
writel(head, pipe->head);
mbox_send_message(glink->mbox_chan, NULL);
mbox_client_txdone(glink->mbox_chan, 0);
out:
mutex_unlock(&glink->tx_lock);
return ret;
}
static int glink_rpm_send_version(struct glink_rpm *glink)
{
struct glink_msg msg;
msg.cmd = cpu_to_le16(RPM_CMD_VERSION);
msg.param1 = cpu_to_le16(1);
msg.param2 = cpu_to_le32(GLINK_FEATURE_INTENTLESS);
return glink_rpm_tx(glink, &msg, sizeof(msg), NULL, 0, true);
}
static void glink_rpm_send_version_ack(struct glink_rpm *glink)
{
struct glink_msg msg;
msg.cmd = cpu_to_le16(RPM_CMD_VERSION_ACK);
msg.param1 = cpu_to_le16(1);
msg.param2 = cpu_to_le32(0);
glink_rpm_tx(glink, &msg, sizeof(msg), NULL, 0, true);
}
static void glink_rpm_send_open_ack(struct glink_rpm *glink,
struct glink_channel *channel)
{
struct glink_msg msg;
msg.cmd = cpu_to_le16(RPM_CMD_OPEN_ACK);
msg.param1 = cpu_to_le16(channel->rcid);
msg.param2 = cpu_to_le32(0);
glink_rpm_tx(glink, &msg, sizeof(msg), NULL, 0, true);
}
static int glink_rpm_send_open_req(struct glink_rpm *glink,
struct glink_channel *channel)
{
struct {
struct glink_msg msg;
u8 name[GLINK_NAME_SIZE];
} __packed req;
int name_len = strlen(channel->name) + 1;
int req_len = ALIGN(sizeof(req.msg) + name_len, 8);
int ret;
kref_get(&channel->refcount);
mutex_lock(&glink->idr_lock);
ret = idr_alloc_cyclic(&glink->lcids, channel,
RPM_GLINK_CID_MIN, RPM_GLINK_CID_MAX, GFP_KERNEL);
mutex_unlock(&glink->idr_lock);
if (ret < 0)
return ret;
channel->lcid = ret;
req.msg.cmd = cpu_to_le16(RPM_CMD_OPEN);
req.msg.param1 = cpu_to_le16(channel->lcid);
req.msg.param2 = cpu_to_le32(name_len);
strcpy(req.name, channel->name);
ret = glink_rpm_tx(glink, &req, req_len, NULL, 0, true);
if (ret)
goto remove_idr;
return 0;
remove_idr:
mutex_lock(&glink->idr_lock);
idr_remove(&glink->lcids, channel->lcid);
channel->lcid = 0;
mutex_unlock(&glink->idr_lock);
return ret;
}
static void glink_rpm_send_close_req(struct glink_rpm *glink,
struct glink_channel *channel)
{
struct glink_msg req;
req.cmd = cpu_to_le16(RPM_CMD_CLOSE);
req.param1 = cpu_to_le16(channel->lcid);
req.param2 = 0;
glink_rpm_tx(glink, &req, sizeof(req), NULL, 0, true);
}
static void glink_rpm_send_close_ack(struct glink_rpm *glink, unsigned int rcid)
{
struct glink_msg req;
req.cmd = cpu_to_le16(RPM_CMD_CLOSE_ACK);
req.param1 = cpu_to_le16(rcid);
req.param2 = 0;
glink_rpm_tx(glink, &req, sizeof(req), NULL, 0, true);
}
static int glink_rpm_rx_defer(struct glink_rpm *glink, size_t extra)
{
struct glink_defer_cmd *dcmd;
extra = ALIGN(extra, 8);
if (glink_rpm_rx_avail(glink) < sizeof(struct glink_msg) + extra) {
dev_dbg(glink->dev, "Insufficient data in rx fifo");
return -ENXIO;
}
dcmd = kzalloc(sizeof(*dcmd) + extra, GFP_ATOMIC);
if (!dcmd)
return -ENOMEM;
INIT_LIST_HEAD(&dcmd->node);
glink_rpm_rx_peak(glink, &dcmd->msg, sizeof(dcmd->msg) + extra);
spin_lock(&glink->rx_lock);
list_add_tail(&dcmd->node, &glink->rx_queue);
spin_unlock(&glink->rx_lock);
schedule_work(&glink->rx_work);
glink_rpm_rx_advance(glink, sizeof(dcmd->msg) + extra);
return 0;
}
static int glink_rpm_rx_data(struct glink_rpm *glink, size_t avail)
{
struct glink_channel *channel;
struct {
struct glink_msg msg;
__le32 chunk_size;
__le32 left_size;
} __packed hdr;
unsigned int chunk_size;
unsigned int left_size;
unsigned int rcid;
if (avail < sizeof(hdr)) {
dev_dbg(glink->dev, "Not enough data in fifo\n");
return -EAGAIN;
}
glink_rpm_rx_peak(glink, &hdr, sizeof(hdr));
chunk_size = le32_to_cpu(hdr.chunk_size);
left_size = le32_to_cpu(hdr.left_size);
if (avail < sizeof(hdr) + chunk_size) {
dev_dbg(glink->dev, "Payload not yet in fifo\n");
return -EAGAIN;
}
if (WARN(chunk_size % 4, "Incoming data must be word aligned\n"))
return -EINVAL;
rcid = le16_to_cpu(hdr.msg.param1);
channel = idr_find(&glink->rcids, rcid);
if (!channel) {
dev_dbg(glink->dev, "Data on non-existing channel\n");
glink_rpm_rx_advance(glink, ALIGN(sizeof(hdr) + chunk_size, 8));
return 0;
}
if (!channel->buf) {
channel->buf = kmalloc(chunk_size + left_size, GFP_ATOMIC);
if (!channel->buf)
return -ENOMEM;
channel->buf_size = chunk_size + left_size;
channel->buf_offset = 0;
}
glink_rpm_rx_advance(glink, sizeof(hdr));
if (channel->buf_size - channel->buf_offset < chunk_size) {
dev_err(glink->dev, "Insufficient space in input buffer\n");
glink_rpm_rx_advance(glink, chunk_size);
return -ENOMEM;
}
glink_rpm_rx_peak(glink, channel->buf + channel->buf_offset, chunk_size);
channel->buf_offset += chunk_size;
if (!left_size) {
spin_lock(&channel->recv_lock);
if (channel->ept.cb) {
channel->ept.cb(channel->ept.rpdev,
channel->buf,
channel->buf_offset,
channel->ept.priv,
RPMSG_ADDR_ANY);
}
spin_unlock(&channel->recv_lock);
kfree(channel->buf);
channel->buf = NULL;
channel->buf_size = 0;
}
glink_rpm_rx_advance(glink, ALIGN(chunk_size, 8));
return 0;
}
static int glink_rpm_rx_open_ack(struct glink_rpm *glink, unsigned int lcid)
{
struct glink_channel *channel;
channel = idr_find(&glink->lcids, lcid);
if (!channel) {
dev_err(glink->dev, "Invalid open ack packet\n");
return -EINVAL;
}
complete(&channel->open_ack);
return 0;
}
static irqreturn_t glink_rpm_intr(int irq, void *data)
{
struct glink_rpm *glink = data;
struct glink_msg msg;
unsigned int param1;
unsigned int param2;
unsigned int avail;
unsigned int cmd;
int ret;
for (;;) {
avail = glink_rpm_rx_avail(glink);
if (avail < sizeof(msg))
break;
glink_rpm_rx_peak(glink, &msg, sizeof(msg));
cmd = le16_to_cpu(msg.cmd);
param1 = le16_to_cpu(msg.param1);
param2 = le32_to_cpu(msg.param2);
switch (cmd) {
case RPM_CMD_VERSION:
case RPM_CMD_VERSION_ACK:
case RPM_CMD_CLOSE:
case RPM_CMD_CLOSE_ACK:
ret = glink_rpm_rx_defer(glink, 0);
break;
case RPM_CMD_OPEN_ACK:
ret = glink_rpm_rx_open_ack(glink, param1);
glink_rpm_rx_advance(glink, ALIGN(sizeof(msg), 8));
break;
case RPM_CMD_OPEN:
ret = glink_rpm_rx_defer(glink, param2);
break;
case RPM_CMD_TX_DATA:
case RPM_CMD_TX_DATA_CONT:
ret = glink_rpm_rx_data(glink, avail);
break;
case RPM_CMD_READ_NOTIF:
glink_rpm_rx_advance(glink, ALIGN(sizeof(msg), 8));
mbox_send_message(glink->mbox_chan, NULL);
mbox_client_txdone(glink->mbox_chan, 0);
ret = 0;
break;
default:
dev_err(glink->dev, "unhandled rx cmd: %d\n", cmd);
ret = -EINVAL;
break;
}
if (ret)
break;
}
return IRQ_HANDLED;
}
static struct glink_channel *glink_rpm_create_local(struct glink_rpm *glink,
const char *name)
{
struct glink_channel *channel;
int ret;
channel = glink_rpm_alloc_channel(glink, name);
if (IS_ERR(channel))
return ERR_CAST(channel);
ret = glink_rpm_send_open_req(glink, channel);
if (ret)
goto release_channel;
ret = wait_for_completion_timeout(&channel->open_ack, 5 * HZ);
if (!ret)
goto err_timeout;
ret = wait_for_completion_timeout(&channel->open_req, 5 * HZ);
if (!ret)
goto err_timeout;
glink_rpm_send_open_ack(glink, channel);
return channel;
err_timeout:
mutex_lock(&glink->idr_lock);
idr_remove(&glink->lcids, channel->lcid);
mutex_unlock(&glink->idr_lock);
release_channel:
kref_put(&channel->refcount, glink_rpm_channel_release);
kref_put(&channel->refcount, glink_rpm_channel_release);
return ERR_PTR(-ETIMEDOUT);
}
static int glink_rpm_create_remote(struct glink_rpm *glink,
struct glink_channel *channel)
{
int ret;
glink_rpm_send_open_ack(glink, channel);
ret = glink_rpm_send_open_req(glink, channel);
if (ret)
goto close_link;
ret = wait_for_completion_timeout(&channel->open_ack, 5 * HZ);
if (!ret) {
ret = -ETIMEDOUT;
goto close_link;
}
return 0;
close_link:
glink_rpm_send_close_req(glink, channel);
kref_put(&channel->refcount, glink_rpm_channel_release);
return ret;
}
static struct rpmsg_endpoint *glink_rpm_create_ept(struct rpmsg_device *rpdev,
rpmsg_rx_cb_t cb, void *priv,
struct rpmsg_channel_info chinfo)
{
struct glink_channel *parent = to_glink_channel(rpdev->ept);
struct glink_channel *channel;
struct glink_rpm *glink = parent->glink;
struct rpmsg_endpoint *ept;
const char *name = chinfo.name;
int cid;
int ret;
idr_for_each_entry(&glink->rcids, channel, cid) {
if (!strcmp(channel->name, name))
break;
}
if (!channel) {
channel = glink_rpm_create_local(glink, name);
if (IS_ERR(channel))
return NULL;
} else {
ret = glink_rpm_create_remote(glink, channel);
if (ret)
return NULL;
}
ept = &channel->ept;
ept->rpdev = rpdev;
ept->cb = cb;
ept->priv = priv;
ept->ops = &glink_endpoint_ops;
return ept;
}
static void glink_rpm_destroy_ept(struct rpmsg_endpoint *ept)
{
struct glink_channel *channel = to_glink_channel(ept);
struct glink_rpm *glink = channel->glink;
unsigned long flags;
spin_lock_irqsave(&channel->recv_lock, flags);
channel->ept.cb = NULL;
spin_unlock_irqrestore(&channel->recv_lock, flags);
channel->rpdev = NULL;
glink_rpm_send_close_req(glink, channel);
}
static int __glink_rpm_send(struct glink_channel *channel,
void *data, int len, bool wait)
{
struct glink_rpm *glink = channel->glink;
struct {
struct glink_msg msg;
__le32 chunk_size;
__le32 left_size;
} __packed req;
if (WARN(len % 8, "RPM GLINK expects 8 byte aligned messages\n"))
return -EINVAL;
req.msg.cmd = cpu_to_le16(RPM_CMD_TX_DATA);
req.msg.param1 = cpu_to_le16(channel->lcid);
req.msg.param2 = cpu_to_le32(channel->rcid);
req.chunk_size = cpu_to_le32(len);
req.left_size = cpu_to_le32(0);
return glink_rpm_tx(glink, &req, sizeof(req), data, len, wait);
}
static int glink_rpm_send(struct rpmsg_endpoint *ept, void *data, int len)
{
struct glink_channel *channel = to_glink_channel(ept);
return __glink_rpm_send(channel, data, len, true);
}
static int glink_rpm_trysend(struct rpmsg_endpoint *ept, void *data, int len)
{
struct glink_channel *channel = to_glink_channel(ept);
return __glink_rpm_send(channel, data, len, false);
}
static struct device_node *glink_rpm_match_channel(struct device_node *node,
const char *channel)
{
struct device_node *child;
const char *name;
const char *key;
int ret;
for_each_available_child_of_node(node, child) {
key = "qcom,glink-channels";
ret = of_property_read_string(child, key, &name);
if (ret)
continue;
if (strcmp(name, channel) == 0)
return child;
}
return NULL;
}
static void glink_rpm_rpdev_release(struct device *dev)
{
struct rpmsg_device *rpdev = to_rpmsg_device(dev);
struct glink_channel *channel = to_glink_channel(rpdev->ept);
channel->rpdev = NULL;
kfree(rpdev);
}
static int glink_rpm_rx_open(struct glink_rpm *glink, unsigned int rcid,
char *name)
{
struct glink_channel *channel;
struct rpmsg_device *rpdev;
bool create_device = false;
int lcid;
int ret;
idr_for_each_entry(&glink->lcids, channel, lcid) {
if (!strcmp(channel->name, name))
break;
}
if (!channel) {
channel = glink_rpm_alloc_channel(glink, name);
if (IS_ERR(channel))
return PTR_ERR(channel);
create_device = true;
}
mutex_lock(&glink->idr_lock);
ret = idr_alloc(&glink->rcids, channel, rcid, rcid + 1, GFP_KERNEL);
if (ret < 0) {
dev_err(glink->dev, "Unable to insert channel into rcid list\n");
mutex_unlock(&glink->idr_lock);
goto free_channel;
}
channel->rcid = ret;
mutex_unlock(&glink->idr_lock);
complete(&channel->open_req);
if (create_device) {
rpdev = kzalloc(sizeof(*rpdev), GFP_KERNEL);
if (!rpdev) {
ret = -ENOMEM;
goto rcid_remove;
}
rpdev->ept = &channel->ept;
strncpy(rpdev->id.name, name, RPMSG_NAME_SIZE);
rpdev->src = RPMSG_ADDR_ANY;
rpdev->dst = RPMSG_ADDR_ANY;
rpdev->ops = &glink_device_ops;
rpdev->dev.of_node = glink_rpm_match_channel(glink->dev->of_node, name);
rpdev->dev.parent = glink->dev;
rpdev->dev.release = glink_rpm_rpdev_release;
ret = rpmsg_register_device(rpdev);
if (ret)
goto free_rpdev;
channel->rpdev = rpdev;
}
return 0;
free_rpdev:
kfree(rpdev);
rcid_remove:
mutex_lock(&glink->idr_lock);
idr_remove(&glink->rcids, channel->rcid);
channel->rcid = 0;
mutex_unlock(&glink->idr_lock);
free_channel:
if (create_device)
kref_put(&channel->refcount, glink_rpm_channel_release);
return ret;
}
static void glink_rpm_rx_close(struct glink_rpm *glink, unsigned int rcid)
{
struct rpmsg_channel_info chinfo;
struct glink_channel *channel;
channel = idr_find(&glink->rcids, rcid);
if (WARN(!channel, "close request on unknown channel\n"))
return;
if (channel->rpdev) {
strncpy(chinfo.name, channel->name, sizeof(chinfo.name));
chinfo.src = RPMSG_ADDR_ANY;
chinfo.dst = RPMSG_ADDR_ANY;
rpmsg_unregister_device(glink->dev, &chinfo);
}
glink_rpm_send_close_ack(glink, channel->rcid);
mutex_lock(&glink->idr_lock);
idr_remove(&glink->rcids, channel->rcid);
channel->rcid = 0;
mutex_unlock(&glink->idr_lock);
kref_put(&channel->refcount, glink_rpm_channel_release);
}
static void glink_rpm_rx_close_ack(struct glink_rpm *glink, unsigned int lcid)
{
struct glink_channel *channel;
channel = idr_find(&glink->lcids, lcid);
if (WARN(!channel, "close ack on unknown channel\n"))
return;
mutex_lock(&glink->idr_lock);
idr_remove(&glink->lcids, channel->lcid);
channel->lcid = 0;
mutex_unlock(&glink->idr_lock);
kref_put(&channel->refcount, glink_rpm_channel_release);
}
static void glink_rpm_work(struct work_struct *work)
{
struct glink_rpm *glink = container_of(work, struct glink_rpm, rx_work);
struct glink_defer_cmd *dcmd;
struct glink_msg *msg;
unsigned long flags;
unsigned int param1;
unsigned int param2;
unsigned int cmd;
for (;;) {
spin_lock_irqsave(&glink->rx_lock, flags);
if (list_empty(&glink->rx_queue)) {
spin_unlock_irqrestore(&glink->rx_lock, flags);
break;
}
dcmd = list_first_entry(&glink->rx_queue, struct glink_defer_cmd, node);
list_del(&dcmd->node);
spin_unlock_irqrestore(&glink->rx_lock, flags);
msg = &dcmd->msg;
cmd = le16_to_cpu(msg->cmd);
param1 = le16_to_cpu(msg->param1);
param2 = le32_to_cpu(msg->param2);
switch (cmd) {
case RPM_CMD_VERSION:
glink_rpm_send_version_ack(glink);
break;
case RPM_CMD_VERSION_ACK:
break;
case RPM_CMD_OPEN:
glink_rpm_rx_open(glink, param1, msg->data);
break;
case RPM_CMD_CLOSE:
glink_rpm_rx_close(glink, param1);
break;
case RPM_CMD_CLOSE_ACK:
glink_rpm_rx_close_ack(glink, param1);
break;
default:
WARN(1, "Unknown defer object %d\n", cmd);
break;
}
kfree(dcmd);
}
}
static int glink_rpm_parse_toc(struct device *dev,
void __iomem *msg_ram,
size_t msg_ram_size,
struct glink_rpm_pipe *rx,
struct glink_rpm_pipe *tx)
{
struct rpm_toc *toc;
int num_entries;
unsigned int id;
size_t offset;
size_t size;
void *buf;
int i;
buf = kzalloc(RPM_TOC_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
__ioread32_copy(buf, msg_ram + msg_ram_size - RPM_TOC_SIZE,
RPM_TOC_SIZE / sizeof(u32));
toc = buf;
if (le32_to_cpu(toc->magic) != RPM_TOC_MAGIC) {
dev_err(dev, "RPM TOC has invalid magic\n");
goto err_inval;
}
num_entries = le32_to_cpu(toc->count);
if (num_entries > RPM_TOC_MAX_ENTRIES) {
dev_err(dev, "Invalid number of toc entries\n");
goto err_inval;
}
for (i = 0; i < num_entries; i++) {
id = le32_to_cpu(toc->entries[i].id);
offset = le32_to_cpu(toc->entries[i].offset);
size = le32_to_cpu(toc->entries[i].size);
if (offset > msg_ram_size || offset + size > msg_ram_size) {
dev_err(dev, "TOC entry with invalid size\n");
continue;
}
switch (id) {
case RPM_RX_FIFO_ID:
rx->length = size;
rx->tail = msg_ram + offset;
rx->head = msg_ram + offset + sizeof(u32);
rx->fifo = msg_ram + offset + 2 * sizeof(u32);
break;
case RPM_TX_FIFO_ID:
tx->length = size;
tx->tail = msg_ram + offset;
tx->head = msg_ram + offset + sizeof(u32);
tx->fifo = msg_ram + offset + 2 * sizeof(u32);
break;
}
}
if (!rx->fifo || !tx->fifo) {
dev_err(dev, "Unable to find rx and tx descriptors\n");
goto err_inval;
}
kfree(buf);
return 0;
err_inval:
kfree(buf);
return -EINVAL;
}
static int glink_rpm_probe(struct platform_device *pdev)
{
struct glink_rpm *glink;
struct device_node *np;
void __iomem *msg_ram;
size_t msg_ram_size;
struct device *dev = &pdev->dev;
struct resource r;
int irq;
int ret;
glink = devm_kzalloc(dev, sizeof(*glink), GFP_KERNEL);
if (!glink)
return -ENOMEM;
glink->dev = dev;
mutex_init(&glink->tx_lock);
spin_lock_init(&glink->rx_lock);
INIT_LIST_HEAD(&glink->rx_queue);
INIT_WORK(&glink->rx_work, glink_rpm_work);
mutex_init(&glink->idr_lock);
idr_init(&glink->lcids);
idr_init(&glink->rcids);
glink->mbox_client.dev = &pdev->dev;
glink->mbox_chan = mbox_request_channel(&glink->mbox_client, 0);
if (IS_ERR(glink->mbox_chan)) {
if (PTR_ERR(glink->mbox_chan) != -EPROBE_DEFER)
dev_err(&pdev->dev, "failed to acquire IPC channel\n");
return PTR_ERR(glink->mbox_chan);
}
np = of_parse_phandle(dev->of_node, "qcom,rpm-msg-ram", 0);
ret = of_address_to_resource(np, 0, &r);
of_node_put(np);
if (ret)
return ret;
msg_ram = devm_ioremap(dev, r.start, resource_size(&r));
msg_ram_size = resource_size(&r);
if (!msg_ram)
return -ENOMEM;
ret = glink_rpm_parse_toc(dev, msg_ram, msg_ram_size,
&glink->rx_pipe, &glink->tx_pipe);
if (ret)
return ret;
writel(0, glink->tx_pipe.head);
writel(0, glink->rx_pipe.tail);
irq = platform_get_irq(pdev, 0);
ret = devm_request_irq(dev, irq,
glink_rpm_intr,
IRQF_NO_SUSPEND | IRQF_SHARED,
"glink-rpm", glink);
if (ret) {
dev_err(dev, "Failed to request IRQ\n");
return ret;
}
glink->irq = irq;
ret = glink_rpm_send_version(glink);
if (ret)
return ret;
platform_set_drvdata(pdev, glink);
return 0;
}
static int glink_rpm_remove_device(struct device *dev, void *data)
{
device_unregister(dev);
return 0;
}
static int glink_rpm_remove(struct platform_device *pdev)
{
struct glink_rpm *glink = platform_get_drvdata(pdev);
struct glink_channel *channel;
int cid;
int ret;
disable_irq(glink->irq);
cancel_work_sync(&glink->rx_work);
ret = device_for_each_child(glink->dev, NULL, glink_rpm_remove_device);
if (ret)
dev_warn(glink->dev, "Can't remove GLINK devices: %d\n", ret);
idr_for_each_entry(&glink->lcids, channel, cid)
kref_put(&channel->refcount, glink_rpm_channel_release);
idr_destroy(&glink->lcids);
idr_destroy(&glink->rcids);
return 0;
}
static int __init glink_rpm_init(void)
{
return platform_driver_register(&glink_rpm_driver);
}
static void __exit glink_rpm_exit(void)
{
platform_driver_unregister(&glink_rpm_driver);
}
