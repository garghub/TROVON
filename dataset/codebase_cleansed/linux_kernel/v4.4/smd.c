static void qcom_smd_signal_channel(struct qcom_smd_channel *channel)
{
struct qcom_smd_edge *edge = channel->edge;
regmap_write(edge->ipc_regmap, edge->ipc_offset, BIT(edge->ipc_bit));
}
static void qcom_smd_channel_reset(struct qcom_smd_channel *channel)
{
SET_TX_CHANNEL_INFO(channel, state, SMD_CHANNEL_CLOSED);
SET_TX_CHANNEL_FLAG(channel, fDSR, 0);
SET_TX_CHANNEL_FLAG(channel, fCTS, 0);
SET_TX_CHANNEL_FLAG(channel, fCD, 0);
SET_TX_CHANNEL_FLAG(channel, fRI, 0);
SET_TX_CHANNEL_FLAG(channel, fHEAD, 0);
SET_TX_CHANNEL_FLAG(channel, fTAIL, 0);
SET_TX_CHANNEL_FLAG(channel, fSTATE, 1);
SET_TX_CHANNEL_FLAG(channel, fBLOCKREADINTR, 1);
SET_TX_CHANNEL_INFO(channel, head, 0);
SET_TX_CHANNEL_INFO(channel, tail, 0);
qcom_smd_signal_channel(channel);
channel->state = SMD_CHANNEL_CLOSED;
channel->pkt_size = 0;
}
static size_t qcom_smd_channel_get_rx_avail(struct qcom_smd_channel *channel)
{
unsigned head;
unsigned tail;
head = GET_RX_CHANNEL_INFO(channel, head);
tail = GET_RX_CHANNEL_INFO(channel, tail);
return (head - tail) & (channel->fifo_size - 1);
}
static void qcom_smd_channel_set_state(struct qcom_smd_channel *channel,
int state)
{
struct qcom_smd_edge *edge = channel->edge;
bool is_open = state == SMD_CHANNEL_OPENED;
if (channel->state == state)
return;
dev_dbg(edge->smd->dev, "set_state(%s, %d)\n", channel->name, state);
SET_TX_CHANNEL_FLAG(channel, fDSR, is_open);
SET_TX_CHANNEL_FLAG(channel, fCTS, is_open);
SET_TX_CHANNEL_FLAG(channel, fCD, is_open);
SET_TX_CHANNEL_INFO(channel, state, state);
SET_TX_CHANNEL_FLAG(channel, fSTATE, 1);
channel->state = state;
qcom_smd_signal_channel(channel);
}
static void smd_copy_to_fifo(void __iomem *dst,
const void *src,
size_t count,
bool word_aligned)
{
if (word_aligned) {
__iowrite32_copy(dst, src, count / sizeof(u32));
} else {
memcpy_toio(dst, src, count);
}
}
static void smd_copy_from_fifo(void *_dst,
const void __iomem *_src,
size_t count,
bool word_aligned)
{
u32 *dst = (u32 *)_dst;
u32 *src = (u32 *)_src;
if (word_aligned) {
count /= sizeof(u32);
while (count--)
*dst++ = __raw_readl(src++);
} else {
memcpy_fromio(_dst, _src, count);
}
}
static size_t qcom_smd_channel_peek(struct qcom_smd_channel *channel,
void *buf, size_t count)
{
bool word_aligned;
unsigned tail;
size_t len;
word_aligned = channel->info_word;
tail = GET_RX_CHANNEL_INFO(channel, tail);
len = min_t(size_t, count, channel->fifo_size - tail);
if (len) {
smd_copy_from_fifo(buf,
channel->rx_fifo + tail,
len,
word_aligned);
}
if (len != count) {
smd_copy_from_fifo(buf + len,
channel->rx_fifo,
count - len,
word_aligned);
}
return count;
}
static void qcom_smd_channel_advance(struct qcom_smd_channel *channel,
size_t count)
{
unsigned tail;
tail = GET_RX_CHANNEL_INFO(channel, tail);
tail += count;
tail &= (channel->fifo_size - 1);
SET_RX_CHANNEL_INFO(channel, tail, tail);
}
static int qcom_smd_channel_recv_single(struct qcom_smd_channel *channel)
{
struct qcom_smd_device *qsdev = channel->qsdev;
unsigned tail;
size_t len;
void *ptr;
int ret;
if (!channel->cb)
return 0;
tail = GET_RX_CHANNEL_INFO(channel, tail);
if (tail + channel->pkt_size >= channel->fifo_size) {
ptr = channel->bounce_buffer;
len = qcom_smd_channel_peek(channel, ptr, channel->pkt_size);
} else {
ptr = channel->rx_fifo + tail;
len = channel->pkt_size;
}
ret = channel->cb(qsdev, ptr, len);
if (ret < 0)
return ret;
qcom_smd_channel_advance(channel, len);
channel->pkt_size = 0;
return 0;
}
static bool qcom_smd_channel_intr(struct qcom_smd_channel *channel)
{
bool need_state_scan = false;
int remote_state;
__le32 pktlen;
int avail;
int ret;
remote_state = GET_RX_CHANNEL_INFO(channel, state);
if (remote_state != channel->remote_state) {
channel->remote_state = remote_state;
need_state_scan = true;
}
SET_RX_CHANNEL_FLAG(channel, fSTATE, 0);
if (!GET_TX_CHANNEL_FLAG(channel, fBLOCKREADINTR))
wake_up_interruptible(&channel->fblockread_event);
if (channel->state != SMD_CHANNEL_OPENED)
goto out;
SET_RX_CHANNEL_FLAG(channel, fHEAD, 0);
for (;;) {
avail = qcom_smd_channel_get_rx_avail(channel);
if (!channel->pkt_size && avail >= SMD_PACKET_HEADER_LEN) {
qcom_smd_channel_peek(channel, &pktlen, sizeof(pktlen));
qcom_smd_channel_advance(channel, SMD_PACKET_HEADER_LEN);
channel->pkt_size = le32_to_cpu(pktlen);
} else if (channel->pkt_size && avail >= channel->pkt_size) {
ret = qcom_smd_channel_recv_single(channel);
if (ret)
break;
} else {
break;
}
}
SET_RX_CHANNEL_FLAG(channel, fTAIL, 1);
if (!GET_RX_CHANNEL_FLAG(channel, fBLOCKREADINTR)) {
wmb();
qcom_smd_signal_channel(channel);
}
out:
return need_state_scan;
}
static irqreturn_t qcom_smd_edge_intr(int irq, void *data)
{
struct qcom_smd_edge *edge = data;
struct qcom_smd_channel *channel;
unsigned available;
bool kick_worker = false;
spin_lock(&edge->channels_lock);
list_for_each_entry(channel, &edge->channels, list) {
spin_lock(&channel->recv_lock);
kick_worker |= qcom_smd_channel_intr(channel);
spin_unlock(&channel->recv_lock);
}
spin_unlock(&edge->channels_lock);
available = qcom_smem_get_free_space(edge->remote_pid);
if (available != edge->smem_available) {
edge->smem_available = available;
edge->need_rescan = true;
kick_worker = true;
}
if (kick_worker)
schedule_work(&edge->work);
return IRQ_HANDLED;
}
static void qcom_smd_channel_resume(struct qcom_smd_channel *channel)
{
unsigned long flags;
spin_lock_irqsave(&channel->recv_lock, flags);
qcom_smd_channel_intr(channel);
spin_unlock_irqrestore(&channel->recv_lock, flags);
}
static size_t qcom_smd_get_tx_avail(struct qcom_smd_channel *channel)
{
unsigned head;
unsigned tail;
unsigned mask = channel->fifo_size - 1;
head = GET_TX_CHANNEL_INFO(channel, head);
tail = GET_TX_CHANNEL_INFO(channel, tail);
return mask - ((head - tail) & mask);
}
static int qcom_smd_write_fifo(struct qcom_smd_channel *channel,
const void *data,
size_t count)
{
bool word_aligned;
unsigned head;
size_t len;
word_aligned = channel->info_word;
head = GET_TX_CHANNEL_INFO(channel, head);
len = min_t(size_t, count, channel->fifo_size - head);
if (len) {
smd_copy_to_fifo(channel->tx_fifo + head,
data,
len,
word_aligned);
}
if (len != count) {
smd_copy_to_fifo(channel->tx_fifo,
data + len,
count - len,
word_aligned);
}
head += count;
head &= (channel->fifo_size - 1);
SET_TX_CHANNEL_INFO(channel, head, head);
return count;
}
int qcom_smd_send(struct qcom_smd_channel *channel, const void *data, int len)
{
__le32 hdr[5] = { cpu_to_le32(len), };
int tlen = sizeof(hdr) + len;
int ret;
if (channel->info_word && len % 4)
return -EINVAL;
if (tlen >= channel->fifo_size)
return -EINVAL;
ret = mutex_lock_interruptible(&channel->tx_lock);
if (ret)
return ret;
while (qcom_smd_get_tx_avail(channel) < tlen) {
if (channel->state != SMD_CHANNEL_OPENED) {
ret = -EPIPE;
goto out;
}
SET_TX_CHANNEL_FLAG(channel, fBLOCKREADINTR, 0);
ret = wait_event_interruptible(channel->fblockread_event,
qcom_smd_get_tx_avail(channel) >= tlen ||
channel->state != SMD_CHANNEL_OPENED);
if (ret)
goto out;
SET_TX_CHANNEL_FLAG(channel, fBLOCKREADINTR, 1);
}
SET_TX_CHANNEL_FLAG(channel, fTAIL, 0);
qcom_smd_write_fifo(channel, hdr, sizeof(hdr));
qcom_smd_write_fifo(channel, data, len);
SET_TX_CHANNEL_FLAG(channel, fHEAD, 1);
wmb();
qcom_smd_signal_channel(channel);
out:
mutex_unlock(&channel->tx_lock);
return ret;
}
static struct qcom_smd_device *to_smd_device(struct device *dev)
{
return container_of(dev, struct qcom_smd_device, dev);
}
static struct qcom_smd_driver *to_smd_driver(struct device *dev)
{
struct qcom_smd_device *qsdev = to_smd_device(dev);
return container_of(qsdev->dev.driver, struct qcom_smd_driver, driver);
}
static int qcom_smd_dev_match(struct device *dev, struct device_driver *drv)
{
struct qcom_smd_device *qsdev = to_smd_device(dev);
struct qcom_smd_driver *qsdrv = container_of(drv, struct qcom_smd_driver, driver);
const struct qcom_smd_id *match = qsdrv->smd_match_table;
const char *name = qsdev->channel->name;
if (match) {
while (match->name[0]) {
if (!strcmp(match->name, name))
return 1;
match++;
}
}
return of_driver_match_device(dev, drv);
}
static int qcom_smd_dev_probe(struct device *dev)
{
struct qcom_smd_device *qsdev = to_smd_device(dev);
struct qcom_smd_driver *qsdrv = to_smd_driver(dev);
struct qcom_smd_channel *channel = qsdev->channel;
size_t bb_size;
int ret;
bb_size = min(channel->fifo_size, SZ_4K);
channel->bounce_buffer = kmalloc(bb_size, GFP_KERNEL);
if (!channel->bounce_buffer)
return -ENOMEM;
channel->cb = qsdrv->callback;
qcom_smd_channel_set_state(channel, SMD_CHANNEL_OPENING);
qcom_smd_channel_set_state(channel, SMD_CHANNEL_OPENED);
ret = qsdrv->probe(qsdev);
if (ret)
goto err;
qcom_smd_channel_resume(channel);
return 0;
err:
dev_err(&qsdev->dev, "probe failed\n");
channel->cb = NULL;
kfree(channel->bounce_buffer);
channel->bounce_buffer = NULL;
qcom_smd_channel_set_state(channel, SMD_CHANNEL_CLOSED);
return ret;
}
static int qcom_smd_dev_remove(struct device *dev)
{
struct qcom_smd_device *qsdev = to_smd_device(dev);
struct qcom_smd_driver *qsdrv = to_smd_driver(dev);
struct qcom_smd_channel *channel = qsdev->channel;
unsigned long flags;
qcom_smd_channel_set_state(channel, SMD_CHANNEL_CLOSING);
spin_lock_irqsave(&channel->recv_lock, flags);
channel->cb = NULL;
spin_unlock_irqrestore(&channel->recv_lock, flags);
wake_up_interruptible(&channel->fblockread_event);
if (qsdrv->remove)
qsdrv->remove(qsdev);
channel->qsdev = NULL;
kfree(channel->bounce_buffer);
channel->bounce_buffer = NULL;
qcom_smd_channel_set_state(channel, SMD_CHANNEL_CLOSED);
qcom_smd_channel_reset(channel);
return 0;
}
static void qcom_smd_release_device(struct device *dev)
{
struct qcom_smd_device *qsdev = to_smd_device(dev);
kfree(qsdev);
}
static struct device_node *qcom_smd_match_channel(struct device_node *edge_node,
const char *channel)
{
struct device_node *child;
const char *name;
const char *key;
int ret;
for_each_available_child_of_node(edge_node, child) {
key = "qcom,smd-channels";
ret = of_property_read_string(child, key, &name);
if (ret)
continue;
if (strcmp(name, channel) == 0)
return child;
}
return NULL;
}
static int qcom_smd_create_device(struct qcom_smd_channel *channel)
{
struct qcom_smd_device *qsdev;
struct qcom_smd_edge *edge = channel->edge;
struct device_node *node;
struct qcom_smd *smd = edge->smd;
int ret;
if (channel->qsdev)
return -EEXIST;
dev_dbg(smd->dev, "registering '%s'\n", channel->name);
qsdev = kzalloc(sizeof(*qsdev), GFP_KERNEL);
if (!qsdev)
return -ENOMEM;
node = qcom_smd_match_channel(edge->of_node, channel->name);
dev_set_name(&qsdev->dev, "%s.%s",
edge->of_node->name,
node ? node->name : channel->name);
qsdev->dev.parent = smd->dev;
qsdev->dev.bus = &qcom_smd_bus;
qsdev->dev.release = qcom_smd_release_device;
qsdev->dev.of_node = node;
qsdev->channel = channel;
channel->qsdev = qsdev;
ret = device_register(&qsdev->dev);
if (ret) {
dev_err(smd->dev, "device_register failed: %d\n", ret);
put_device(&qsdev->dev);
}
return ret;
}
static void qcom_smd_destroy_device(struct qcom_smd_channel *channel)
{
struct device *dev;
BUG_ON(!channel->qsdev);
dev = &channel->qsdev->dev;
device_unregister(dev);
of_node_put(dev->of_node);
put_device(dev);
}
int qcom_smd_driver_register(struct qcom_smd_driver *qsdrv)
{
qsdrv->driver.bus = &qcom_smd_bus;
return driver_register(&qsdrv->driver);
}
void qcom_smd_driver_unregister(struct qcom_smd_driver *qsdrv)
{
driver_unregister(&qsdrv->driver);
}
static struct qcom_smd_channel *qcom_smd_create_channel(struct qcom_smd_edge *edge,
unsigned smem_info_item,
unsigned smem_fifo_item,
char *name)
{
struct qcom_smd_channel *channel;
struct qcom_smd *smd = edge->smd;
size_t fifo_size;
size_t info_size;
void *fifo_base;
void *info;
int ret;
channel = devm_kzalloc(smd->dev, sizeof(*channel), GFP_KERNEL);
if (!channel)
return ERR_PTR(-ENOMEM);
channel->edge = edge;
channel->name = devm_kstrdup(smd->dev, name, GFP_KERNEL);
if (!channel->name)
return ERR_PTR(-ENOMEM);
mutex_init(&channel->tx_lock);
spin_lock_init(&channel->recv_lock);
init_waitqueue_head(&channel->fblockread_event);
info = qcom_smem_get(edge->remote_pid, smem_info_item, &info_size);
if (IS_ERR(info)) {
ret = PTR_ERR(info);
goto free_name_and_channel;
}
if (info_size == 2 * sizeof(struct smd_channel_info_word)) {
channel->info_word = info;
} else if (info_size == 2 * sizeof(struct smd_channel_info)) {
channel->info = info;
} else {
dev_err(smd->dev,
"channel info of size %zu not supported\n", info_size);
ret = -EINVAL;
goto free_name_and_channel;
}
fifo_base = qcom_smem_get(edge->remote_pid, smem_fifo_item, &fifo_size);
if (IS_ERR(fifo_base)) {
ret = PTR_ERR(fifo_base);
goto free_name_and_channel;
}
fifo_size /= 2;
dev_dbg(smd->dev, "new channel '%s' info-size: %zu fifo-size: %zu\n",
name, info_size, fifo_size);
channel->tx_fifo = fifo_base;
channel->rx_fifo = fifo_base + fifo_size;
channel->fifo_size = fifo_size;
qcom_smd_channel_reset(channel);
return channel;
free_name_and_channel:
devm_kfree(smd->dev, channel->name);
devm_kfree(smd->dev, channel);
return ERR_PTR(ret);
}
static void qcom_discover_channels(struct qcom_smd_edge *edge)
{
struct qcom_smd_alloc_entry *alloc_tbl;
struct qcom_smd_alloc_entry *entry;
struct qcom_smd_channel *channel;
struct qcom_smd *smd = edge->smd;
unsigned long flags;
unsigned fifo_id;
unsigned info_id;
int tbl;
int i;
u32 eflags, cid;
for (tbl = 0; tbl < SMD_ALLOC_TBL_COUNT; tbl++) {
alloc_tbl = qcom_smem_get(edge->remote_pid,
smem_items[tbl].alloc_tbl_id, NULL);
if (IS_ERR(alloc_tbl))
continue;
for (i = 0; i < SMD_ALLOC_TBL_SIZE; i++) {
entry = &alloc_tbl[i];
eflags = le32_to_cpu(entry->flags);
if (test_bit(i, edge->allocated[tbl]))
continue;
if (entry->ref_count == 0)
continue;
if (!entry->name[0])
continue;
if (!(eflags & SMD_CHANNEL_FLAGS_PACKET))
continue;
if ((eflags & SMD_CHANNEL_FLAGS_EDGE_MASK) != edge->edge_id)
continue;
cid = le32_to_cpu(entry->cid);
info_id = smem_items[tbl].info_base_id + cid;
fifo_id = smem_items[tbl].fifo_base_id + cid;
channel = qcom_smd_create_channel(edge, info_id, fifo_id, entry->name);
if (IS_ERR(channel))
continue;
spin_lock_irqsave(&edge->channels_lock, flags);
list_add(&channel->list, &edge->channels);
spin_unlock_irqrestore(&edge->channels_lock, flags);
dev_dbg(smd->dev, "new channel found: '%s'\n", channel->name);
set_bit(i, edge->allocated[tbl]);
}
}
schedule_work(&edge->work);
}
static void qcom_channel_state_worker(struct work_struct *work)
{
struct qcom_smd_channel *channel;
struct qcom_smd_edge *edge = container_of(work,
struct qcom_smd_edge,
work);
unsigned remote_state;
if (edge->need_rescan) {
edge->need_rescan = false;
qcom_discover_channels(edge);
}
list_for_each_entry(channel, &edge->channels, list) {
if (channel->state != SMD_CHANNEL_CLOSED)
continue;
remote_state = GET_RX_CHANNEL_INFO(channel, state);
if (remote_state != SMD_CHANNEL_OPENING &&
remote_state != SMD_CHANNEL_OPENED)
continue;
qcom_smd_create_device(channel);
}
list_for_each_entry(channel, &edge->channels, list) {
if (channel->state != SMD_CHANNEL_OPENING &&
channel->state != SMD_CHANNEL_OPENED)
continue;
remote_state = GET_RX_CHANNEL_INFO(channel, state);
if (remote_state == SMD_CHANNEL_OPENING ||
remote_state == SMD_CHANNEL_OPENED)
continue;
qcom_smd_destroy_device(channel);
}
}
static int qcom_smd_parse_edge(struct device *dev,
struct device_node *node,
struct qcom_smd_edge *edge)
{
struct device_node *syscon_np;
const char *key;
int irq;
int ret;
INIT_LIST_HEAD(&edge->channels);
spin_lock_init(&edge->channels_lock);
INIT_WORK(&edge->work, qcom_channel_state_worker);
edge->of_node = of_node_get(node);
irq = irq_of_parse_and_map(node, 0);
if (irq < 0) {
dev_err(dev, "required smd interrupt missing\n");
return -EINVAL;
}
ret = devm_request_irq(dev, irq,
qcom_smd_edge_intr, IRQF_TRIGGER_RISING,
node->name, edge);
if (ret) {
dev_err(dev, "failed to request smd irq\n");
return ret;
}
edge->irq = irq;
key = "qcom,smd-edge";
ret = of_property_read_u32(node, key, &edge->edge_id);
if (ret) {
dev_err(dev, "edge missing %s property\n", key);
return -EINVAL;
}
edge->remote_pid = QCOM_SMEM_HOST_ANY;
key = "qcom,remote-pid";
of_property_read_u32(node, key, &edge->remote_pid);
syscon_np = of_parse_phandle(node, "qcom,ipc", 0);
if (!syscon_np) {
dev_err(dev, "no qcom,ipc node\n");
return -ENODEV;
}
edge->ipc_regmap = syscon_node_to_regmap(syscon_np);
if (IS_ERR(edge->ipc_regmap))
return PTR_ERR(edge->ipc_regmap);
key = "qcom,ipc";
ret = of_property_read_u32_index(node, key, 1, &edge->ipc_offset);
if (ret < 0) {
dev_err(dev, "no offset in %s\n", key);
return -EINVAL;
}
ret = of_property_read_u32_index(node, key, 2, &edge->ipc_bit);
if (ret < 0) {
dev_err(dev, "no bit in %s\n", key);
return -EINVAL;
}
return 0;
}
static int qcom_smd_probe(struct platform_device *pdev)
{
struct qcom_smd_edge *edge;
struct device_node *node;
struct qcom_smd *smd;
size_t array_size;
int num_edges;
int ret;
int i = 0;
void *p;
p = qcom_smem_get(QCOM_SMEM_HOST_ANY, smem_items[0].alloc_tbl_id, NULL);
if (PTR_ERR(p) == -EPROBE_DEFER)
return PTR_ERR(p);
num_edges = of_get_available_child_count(pdev->dev.of_node);
array_size = sizeof(*smd) + num_edges * sizeof(struct qcom_smd_edge);
smd = devm_kzalloc(&pdev->dev, array_size, GFP_KERNEL);
if (!smd)
return -ENOMEM;
smd->dev = &pdev->dev;
smd->num_edges = num_edges;
for_each_available_child_of_node(pdev->dev.of_node, node) {
edge = &smd->edges[i++];
edge->smd = smd;
ret = qcom_smd_parse_edge(&pdev->dev, node, edge);
if (ret)
continue;
edge->need_rescan = true;
schedule_work(&edge->work);
}
platform_set_drvdata(pdev, smd);
return 0;
}
static int qcom_smd_remove(struct platform_device *pdev)
{
struct qcom_smd_channel *channel;
struct qcom_smd_edge *edge;
struct qcom_smd *smd = platform_get_drvdata(pdev);
int i;
for (i = 0; i < smd->num_edges; i++) {
edge = &smd->edges[i];
disable_irq(edge->irq);
cancel_work_sync(&edge->work);
list_for_each_entry(channel, &edge->channels, list) {
if (!channel->qsdev)
continue;
qcom_smd_destroy_device(channel);
}
}
return 0;
}
static int __init qcom_smd_init(void)
{
int ret;
ret = bus_register(&qcom_smd_bus);
if (ret) {
pr_err("failed to register smd bus: %d\n", ret);
return ret;
}
return platform_driver_register(&qcom_smd_driver);
}
static void __exit qcom_smd_exit(void)
{
platform_driver_unregister(&qcom_smd_driver);
bus_unregister(&qcom_smd_bus);
}
