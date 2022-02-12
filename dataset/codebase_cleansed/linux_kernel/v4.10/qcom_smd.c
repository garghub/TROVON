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
SET_RX_CHANNEL_INFO(channel, tail, 0);
qcom_smd_signal_channel(channel);
channel->state = SMD_CHANNEL_CLOSED;
channel->pkt_size = 0;
}
static void qcom_smd_channel_set_callback(struct qcom_smd_channel *channel,
rpmsg_rx_cb_t cb)
{
struct rpmsg_endpoint *ept = &channel->qsept->ept;
unsigned long flags;
spin_lock_irqsave(&channel->recv_lock, flags);
ept->cb = cb;
spin_unlock_irqrestore(&channel->recv_lock, flags);
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
dev_dbg(&edge->dev, "set_state(%s, %d)\n", channel->name, state);
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
static void smd_copy_from_fifo(void *dst,
const void __iomem *src,
size_t count,
bool word_aligned)
{
if (word_aligned) {
__ioread32_copy(dst, src, count / sizeof(u32));
} else {
memcpy_fromio(dst, src, count);
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
struct rpmsg_endpoint *ept = &channel->qsept->ept;
unsigned tail;
size_t len;
void *ptr;
int ret;
tail = GET_RX_CHANNEL_INFO(channel, tail);
if (tail + channel->pkt_size >= channel->fifo_size) {
ptr = channel->bounce_buffer;
len = qcom_smd_channel_peek(channel, ptr, channel->pkt_size);
} else {
ptr = channel->rx_fifo + tail;
len = channel->pkt_size;
}
ret = ept->cb(ept->rpdev, ptr, len, ept->priv, RPMSG_ADDR_ANY);
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
bool kick_scanner = false;
bool kick_state = false;
spin_lock(&edge->channels_lock);
list_for_each_entry(channel, &edge->channels, list) {
spin_lock(&channel->recv_lock);
kick_state |= qcom_smd_channel_intr(channel);
spin_unlock(&channel->recv_lock);
}
spin_unlock(&edge->channels_lock);
available = qcom_smem_get_free_space(edge->remote_pid);
if (available != edge->smem_available) {
edge->smem_available = available;
kick_scanner = true;
}
if (kick_scanner)
schedule_work(&edge->scan_work);
if (kick_state)
schedule_work(&edge->state_work);
return IRQ_HANDLED;
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
static int __qcom_smd_send(struct qcom_smd_channel *channel, const void *data,
int len, bool wait)
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
if (!wait) {
ret = -EAGAIN;
goto out;
}
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
static int qcom_smd_channel_open(struct qcom_smd_channel *channel,
rpmsg_rx_cb_t cb)
{
size_t bb_size;
bb_size = min(channel->fifo_size, SZ_4K);
channel->bounce_buffer = kmalloc(bb_size, GFP_KERNEL);
if (!channel->bounce_buffer)
return -ENOMEM;
qcom_smd_channel_set_callback(channel, cb);
qcom_smd_channel_set_state(channel, SMD_CHANNEL_OPENING);
qcom_smd_channel_set_state(channel, SMD_CHANNEL_OPENED);
return 0;
}
static void qcom_smd_channel_close(struct qcom_smd_channel *channel)
{
qcom_smd_channel_set_callback(channel, NULL);
kfree(channel->bounce_buffer);
channel->bounce_buffer = NULL;
qcom_smd_channel_set_state(channel, SMD_CHANNEL_CLOSED);
qcom_smd_channel_reset(channel);
}
static struct qcom_smd_channel *
qcom_smd_find_channel(struct qcom_smd_edge *edge, const char *name)
{
struct qcom_smd_channel *channel;
struct qcom_smd_channel *ret = NULL;
unsigned long flags;
spin_lock_irqsave(&edge->channels_lock, flags);
list_for_each_entry(channel, &edge->channels, list) {
if (!strcmp(channel->name, name)) {
ret = channel;
break;
}
}
spin_unlock_irqrestore(&edge->channels_lock, flags);
return ret;
}
static void __ept_release(struct kref *kref)
{
struct rpmsg_endpoint *ept = container_of(kref, struct rpmsg_endpoint,
refcount);
kfree(to_smd_endpoint(ept));
}
static struct rpmsg_endpoint *qcom_smd_create_ept(struct rpmsg_device *rpdev,
rpmsg_rx_cb_t cb, void *priv,
struct rpmsg_channel_info chinfo)
{
struct qcom_smd_endpoint *qsept;
struct qcom_smd_channel *channel;
struct qcom_smd_device *qsdev = to_smd_device(rpdev);
struct qcom_smd_edge *edge = qsdev->edge;
struct rpmsg_endpoint *ept;
const char *name = chinfo.name;
int ret;
ret = wait_event_interruptible_timeout(edge->new_channel_event,
(channel = qcom_smd_find_channel(edge, name)) != NULL,
HZ);
if (!ret)
return NULL;
if (channel->state != SMD_CHANNEL_CLOSED) {
dev_err(&rpdev->dev, "channel %s is busy\n", channel->name);
return NULL;
}
qsept = kzalloc(sizeof(*qsept), GFP_KERNEL);
if (!qsept)
return NULL;
ept = &qsept->ept;
kref_init(&ept->refcount);
ept->rpdev = rpdev;
ept->cb = cb;
ept->priv = priv;
ept->ops = &qcom_smd_endpoint_ops;
channel->qsept = qsept;
qsept->qsch = channel;
ret = qcom_smd_channel_open(channel, cb);
if (ret)
goto free_ept;
return ept;
free_ept:
channel->qsept = NULL;
kref_put(&ept->refcount, __ept_release);
return NULL;
}
static void qcom_smd_destroy_ept(struct rpmsg_endpoint *ept)
{
struct qcom_smd_endpoint *qsept = to_smd_endpoint(ept);
struct qcom_smd_channel *ch = qsept->qsch;
qcom_smd_channel_close(ch);
ch->qsept = NULL;
kref_put(&ept->refcount, __ept_release);
}
static int qcom_smd_send(struct rpmsg_endpoint *ept, void *data, int len)
{
struct qcom_smd_endpoint *qsept = to_smd_endpoint(ept);
return __qcom_smd_send(qsept->qsch, data, len, true);
}
static int qcom_smd_trysend(struct rpmsg_endpoint *ept, void *data, int len)
{
struct qcom_smd_endpoint *qsept = to_smd_endpoint(ept);
return __qcom_smd_send(qsept->qsch, data, len, false);
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
struct rpmsg_device *rpdev;
struct qcom_smd_edge *edge = channel->edge;
dev_dbg(&edge->dev, "registering '%s'\n", channel->name);
qsdev = kzalloc(sizeof(*qsdev), GFP_KERNEL);
if (!qsdev)
return -ENOMEM;
qsdev->edge = edge;
qsdev->rpdev.ops = &qcom_smd_device_ops;
rpdev = &qsdev->rpdev;
strncpy(rpdev->id.name, channel->name, RPMSG_NAME_SIZE);
rpdev->src = RPMSG_ADDR_ANY;
rpdev->dst = RPMSG_ADDR_ANY;
rpdev->dev.of_node = qcom_smd_match_channel(edge->of_node, channel->name);
rpdev->dev.parent = &edge->dev;
return rpmsg_register_device(rpdev);
}
static struct qcom_smd_channel *qcom_smd_create_channel(struct qcom_smd_edge *edge,
unsigned smem_info_item,
unsigned smem_fifo_item,
char *name)
{
struct qcom_smd_channel *channel;
size_t fifo_size;
size_t info_size;
void *fifo_base;
void *info;
int ret;
channel = devm_kzalloc(&edge->dev, sizeof(*channel), GFP_KERNEL);
if (!channel)
return ERR_PTR(-ENOMEM);
channel->edge = edge;
channel->name = devm_kstrdup(&edge->dev, name, GFP_KERNEL);
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
dev_err(&edge->dev,
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
dev_dbg(&edge->dev, "new channel '%s' info-size: %zu fifo-size: %zu\n",
name, info_size, fifo_size);
channel->tx_fifo = fifo_base;
channel->rx_fifo = fifo_base + fifo_size;
channel->fifo_size = fifo_size;
qcom_smd_channel_reset(channel);
return channel;
free_name_and_channel:
devm_kfree(&edge->dev, channel->name);
devm_kfree(&edge->dev, channel);
return ERR_PTR(ret);
}
static void qcom_channel_scan_worker(struct work_struct *work)
{
struct qcom_smd_edge *edge = container_of(work, struct qcom_smd_edge, scan_work);
struct qcom_smd_alloc_entry *alloc_tbl;
struct qcom_smd_alloc_entry *entry;
struct qcom_smd_channel *channel;
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
dev_dbg(&edge->dev, "new channel found: '%s'\n", channel->name);
set_bit(i, edge->allocated[tbl]);
wake_up_interruptible(&edge->new_channel_event);
}
}
schedule_work(&edge->state_work);
}
static void qcom_channel_state_worker(struct work_struct *work)
{
struct qcom_smd_channel *channel;
struct qcom_smd_edge *edge = container_of(work,
struct qcom_smd_edge,
state_work);
struct rpmsg_channel_info chinfo;
unsigned remote_state;
unsigned long flags;
spin_lock_irqsave(&edge->channels_lock, flags);
list_for_each_entry(channel, &edge->channels, list) {
if (channel->state != SMD_CHANNEL_CLOSED)
continue;
remote_state = GET_RX_CHANNEL_INFO(channel, state);
if (remote_state != SMD_CHANNEL_OPENING &&
remote_state != SMD_CHANNEL_OPENED)
continue;
if (channel->registered)
continue;
spin_unlock_irqrestore(&edge->channels_lock, flags);
qcom_smd_create_device(channel);
channel->registered = true;
spin_lock_irqsave(&edge->channels_lock, flags);
channel->registered = true;
}
list_for_each_entry(channel, &edge->channels, list) {
if (channel->state != SMD_CHANNEL_OPENING &&
channel->state != SMD_CHANNEL_OPENED)
continue;
remote_state = GET_RX_CHANNEL_INFO(channel, state);
if (remote_state == SMD_CHANNEL_OPENING ||
remote_state == SMD_CHANNEL_OPENED)
continue;
spin_unlock_irqrestore(&edge->channels_lock, flags);
strncpy(chinfo.name, channel->name, sizeof(chinfo.name));
chinfo.src = RPMSG_ADDR_ANY;
chinfo.dst = RPMSG_ADDR_ANY;
rpmsg_unregister_device(&edge->dev, &chinfo);
channel->registered = false;
spin_lock_irqsave(&edge->channels_lock, flags);
}
spin_unlock_irqrestore(&edge->channels_lock, flags);
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
INIT_WORK(&edge->scan_work, qcom_channel_scan_worker);
INIT_WORK(&edge->state_work, qcom_channel_state_worker);
edge->of_node = of_node_get(node);
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
return 0;
}
static void qcom_smd_edge_release(struct device *dev)
{
struct qcom_smd_channel *channel;
struct qcom_smd_edge *edge = to_smd_edge(dev);
list_for_each_entry(channel, &edge->channels, list) {
SET_RX_CHANNEL_INFO(channel, state, SMD_CHANNEL_CLOSED);
SET_RX_CHANNEL_INFO(channel, head, 0);
SET_RX_CHANNEL_INFO(channel, tail, 0);
}
kfree(edge);
}
struct qcom_smd_edge *qcom_smd_register_edge(struct device *parent,
struct device_node *node)
{
struct qcom_smd_edge *edge;
int ret;
edge = kzalloc(sizeof(*edge), GFP_KERNEL);
if (!edge)
return ERR_PTR(-ENOMEM);
init_waitqueue_head(&edge->new_channel_event);
edge->dev.parent = parent;
edge->dev.release = qcom_smd_edge_release;
dev_set_name(&edge->dev, "%s:%s", dev_name(parent), node->name);
ret = device_register(&edge->dev);
if (ret) {
pr_err("failed to register smd edge\n");
return ERR_PTR(ret);
}
ret = qcom_smd_parse_edge(&edge->dev, node, edge);
if (ret) {
dev_err(&edge->dev, "failed to parse smd edge\n");
goto unregister_dev;
}
schedule_work(&edge->scan_work);
return edge;
unregister_dev:
put_device(&edge->dev);
return ERR_PTR(ret);
}
static int qcom_smd_remove_device(struct device *dev, void *data)
{
device_unregister(dev);
return 0;
}
int qcom_smd_unregister_edge(struct qcom_smd_edge *edge)
{
int ret;
disable_irq(edge->irq);
cancel_work_sync(&edge->scan_work);
cancel_work_sync(&edge->state_work);
ret = device_for_each_child(&edge->dev, NULL, qcom_smd_remove_device);
if (ret)
dev_warn(&edge->dev, "can't remove smd device: %d\n", ret);
device_unregister(&edge->dev);
return 0;
}
static int qcom_smd_probe(struct platform_device *pdev)
{
struct device_node *node;
void *p;
p = qcom_smem_get(QCOM_SMEM_HOST_ANY, smem_items[0].alloc_tbl_id, NULL);
if (PTR_ERR(p) == -EPROBE_DEFER)
return PTR_ERR(p);
for_each_available_child_of_node(pdev->dev.of_node, node)
qcom_smd_register_edge(&pdev->dev, node);
return 0;
}
static int qcom_smd_remove_edge(struct device *dev, void *data)
{
struct qcom_smd_edge *edge = to_smd_edge(dev);
return qcom_smd_unregister_edge(edge);
}
static int qcom_smd_remove(struct platform_device *pdev)
{
int ret;
ret = device_for_each_child(&pdev->dev, NULL, qcom_smd_remove_edge);
if (ret)
dev_warn(&pdev->dev, "can't remove smd device: %d\n", ret);
return ret;
}
static int __init qcom_smd_init(void)
{
return platform_driver_register(&qcom_smd_driver);
}
static void __exit qcom_smd_exit(void)
{
platform_driver_unregister(&qcom_smd_driver);
}
