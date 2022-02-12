static inline int ti_msgmgr_queue_get_num_messages(struct ti_queue_inst *qinst)
{
u32 val;
val = readl(qinst->queue_state) & Q_STATE_ENTRY_COUNT_MASK;
val >>= __ffs(Q_STATE_ENTRY_COUNT_MASK);
return val;
}
static irqreturn_t ti_msgmgr_queue_rx_interrupt(int irq, void *p)
{
struct mbox_chan *chan = p;
struct device *dev = chan->mbox->dev;
struct ti_msgmgr_inst *inst = dev_get_drvdata(dev);
struct ti_queue_inst *qinst = chan->con_priv;
const struct ti_msgmgr_desc *desc;
int msg_count, num_words;
struct ti_msgmgr_message message;
void __iomem *data_reg;
u32 *word_data;
if (WARN_ON(!inst)) {
dev_err(dev, "no platform drv data??\n");
return -EINVAL;
}
if (qinst->is_tx) {
dev_err(dev, "Cannot handle rx interrupt on tx channel %s\n",
qinst->name);
return IRQ_NONE;
}
msg_count = ti_msgmgr_queue_get_num_messages(qinst);
if (!msg_count) {
dev_dbg(dev, "Spurious event - 0 pending data!\n");
return IRQ_NONE;
}
desc = inst->desc;
message.len = desc->max_message_size;
message.buf = (u8 *)qinst->rx_buff;
for (data_reg = qinst->queue_buff_start, word_data = qinst->rx_buff,
num_words = (desc->max_message_size / sizeof(u32));
num_words; num_words--, data_reg += sizeof(u32), word_data++)
*word_data = readl(data_reg);
mbox_chan_received_data(chan, (void *)&message);
return IRQ_HANDLED;
}
static bool ti_msgmgr_queue_peek_data(struct mbox_chan *chan)
{
struct ti_queue_inst *qinst = chan->con_priv;
int msg_count;
if (qinst->is_tx)
return false;
msg_count = ti_msgmgr_queue_get_num_messages(qinst);
return msg_count ? true : false;
}
static bool ti_msgmgr_last_tx_done(struct mbox_chan *chan)
{
struct ti_queue_inst *qinst = chan->con_priv;
int msg_count;
if (!qinst->is_tx)
return false;
msg_count = ti_msgmgr_queue_get_num_messages(qinst);
return msg_count ? false : true;
}
static int ti_msgmgr_send_data(struct mbox_chan *chan, void *data)
{
struct device *dev = chan->mbox->dev;
struct ti_msgmgr_inst *inst = dev_get_drvdata(dev);
const struct ti_msgmgr_desc *desc;
struct ti_queue_inst *qinst = chan->con_priv;
int num_words, trail_bytes;
struct ti_msgmgr_message *message = data;
void __iomem *data_reg;
u32 *word_data;
if (WARN_ON(!inst)) {
dev_err(dev, "no platform drv data??\n");
return -EINVAL;
}
desc = inst->desc;
if (desc->max_message_size < message->len) {
dev_err(dev, "Queue %s message length %d > max %d\n",
qinst->name, message->len, desc->max_message_size);
return -EINVAL;
}
for (data_reg = qinst->queue_buff_start,
num_words = message->len / sizeof(u32),
word_data = (u32 *)message->buf;
num_words; num_words--, data_reg += sizeof(u32), word_data++)
writel(*word_data, data_reg);
trail_bytes = message->len % sizeof(u32);
if (trail_bytes) {
u32 data_trail = *word_data;
data_trail &= 0xFFFFFFFF >> (8 * (sizeof(u32) - trail_bytes));
writel(data_trail, data_reg);
data_reg++;
}
if (data_reg <= qinst->queue_buff_end)
writel(0, qinst->queue_buff_end);
return 0;
}
static int ti_msgmgr_queue_startup(struct mbox_chan *chan)
{
struct ti_queue_inst *qinst = chan->con_priv;
struct device *dev = chan->mbox->dev;
int ret;
if (!qinst->is_tx) {
ret = request_irq(qinst->irq, ti_msgmgr_queue_rx_interrupt,
IRQF_SHARED, qinst->name, chan);
if (ret) {
dev_err(dev, "Unable to get IRQ %d on %s(res=%d)\n",
qinst->irq, qinst->name, ret);
return ret;
}
}
return 0;
}
static void ti_msgmgr_queue_shutdown(struct mbox_chan *chan)
{
struct ti_queue_inst *qinst = chan->con_priv;
if (!qinst->is_tx)
free_irq(qinst->irq, chan);
}
static struct mbox_chan *ti_msgmgr_of_xlate(struct mbox_controller *mbox,
const struct of_phandle_args *p)
{
struct ti_msgmgr_inst *inst;
int req_qid, req_pid;
struct ti_queue_inst *qinst;
int i;
inst = container_of(mbox, struct ti_msgmgr_inst, mbox);
if (WARN_ON(!inst))
return ERR_PTR(-EINVAL);
if (p->args_count != 2) {
dev_err(inst->dev, "Invalid arguments in dt[%d] instead of 2\n",
p->args_count);
return ERR_PTR(-EINVAL);
}
req_qid = p->args[0];
req_pid = p->args[1];
for (qinst = inst->qinsts, i = 0; i < inst->num_valid_queues;
i++, qinst++) {
if (req_qid == qinst->queue_id && req_pid == qinst->proxy_id)
return qinst->chan;
}
dev_err(inst->dev, "Queue ID %d, Proxy ID %d is wrong on %s\n",
req_qid, req_pid, p->np->name);
return ERR_PTR(-ENOENT);
}
static int ti_msgmgr_queue_setup(int idx, struct device *dev,
struct device_node *np,
struct ti_msgmgr_inst *inst,
const struct ti_msgmgr_desc *d,
const struct ti_msgmgr_valid_queue_desc *qd,
struct ti_queue_inst *qinst,
struct mbox_chan *chan)
{
qinst->proxy_id = qd->proxy_id;
qinst->queue_id = qd->queue_id;
if (qinst->queue_id > d->queue_count) {
dev_err(dev, "Queue Data [idx=%d] queuid %d > %d\n",
idx, qinst->queue_id, d->queue_count);
return -ERANGE;
}
qinst->is_tx = qd->is_tx;
snprintf(qinst->name, sizeof(qinst->name), "%s %s_%03d_%03d",
dev_name(dev), qinst->is_tx ? "tx" : "rx", qinst->queue_id,
qinst->proxy_id);
if (!qinst->is_tx) {
char of_rx_irq_name[7];
snprintf(of_rx_irq_name, sizeof(of_rx_irq_name),
"rx_%03d", qinst->queue_id);
qinst->irq = of_irq_get_byname(np, of_rx_irq_name);
if (qinst->irq < 0) {
dev_crit(dev,
"[%d]QID %d PID %d:No IRQ[%s]: %d\n",
idx, qinst->queue_id, qinst->proxy_id,
of_rx_irq_name, qinst->irq);
return qinst->irq;
}
qinst->rx_buff = devm_kzalloc(dev,
d->max_message_size, GFP_KERNEL);
if (!qinst->rx_buff)
return -ENOMEM;
}
qinst->queue_buff_start = inst->queue_proxy_region +
Q_DATA_OFFSET(qinst->proxy_id, qinst->queue_id, d->data_first_reg);
qinst->queue_buff_end = inst->queue_proxy_region +
Q_DATA_OFFSET(qinst->proxy_id, qinst->queue_id, d->data_last_reg);
qinst->queue_state = inst->queue_state_debug_region +
Q_STATE_OFFSET(qinst->queue_id);
qinst->chan = chan;
chan->con_priv = qinst;
dev_dbg(dev, "[%d] qidx=%d pidx=%d irq=%d q_s=%p q_e = %p\n",
idx, qinst->queue_id, qinst->proxy_id, qinst->irq,
qinst->queue_buff_start, qinst->queue_buff_end);
return 0;
}
static int ti_msgmgr_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct of_device_id *of_id;
struct device_node *np;
struct resource *res;
const struct ti_msgmgr_desc *desc;
struct ti_msgmgr_inst *inst;
struct ti_queue_inst *qinst;
struct mbox_controller *mbox;
struct mbox_chan *chans;
int queue_count;
int i;
int ret = -EINVAL;
const struct ti_msgmgr_valid_queue_desc *queue_desc;
if (!dev->of_node) {
dev_err(dev, "no OF information\n");
return -EINVAL;
}
np = dev->of_node;
of_id = of_match_device(ti_msgmgr_of_match, dev);
if (!of_id) {
dev_err(dev, "OF data missing\n");
return -EINVAL;
}
desc = of_id->data;
inst = devm_kzalloc(dev, sizeof(*inst), GFP_KERNEL);
if (!inst)
return -ENOMEM;
inst->dev = dev;
inst->desc = desc;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"queue_proxy_region");
inst->queue_proxy_region = devm_ioremap_resource(dev, res);
if (IS_ERR(inst->queue_proxy_region))
return PTR_ERR(inst->queue_proxy_region);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"queue_state_debug_region");
inst->queue_state_debug_region = devm_ioremap_resource(dev, res);
if (IS_ERR(inst->queue_state_debug_region))
return PTR_ERR(inst->queue_state_debug_region);
dev_dbg(dev, "proxy region=%p, queue_state=%p\n",
inst->queue_proxy_region, inst->queue_state_debug_region);
queue_count = desc->num_valid_queues;
if (!queue_count || queue_count > desc->queue_count) {
dev_crit(dev, "Invalid Number of queues %d. Max %d\n",
queue_count, desc->queue_count);
return -ERANGE;
}
inst->num_valid_queues = queue_count;
qinst = devm_kzalloc(dev, sizeof(*qinst) * queue_count, GFP_KERNEL);
if (!qinst)
return -ENOMEM;
inst->qinsts = qinst;
chans = devm_kzalloc(dev, sizeof(*chans) * queue_count, GFP_KERNEL);
if (!chans)
return -ENOMEM;
inst->chans = chans;
for (i = 0, queue_desc = desc->valid_queues;
i < queue_count; i++, qinst++, chans++, queue_desc++) {
ret = ti_msgmgr_queue_setup(i, dev, np, inst,
desc, queue_desc, qinst, chans);
if (ret)
return ret;
}
mbox = &inst->mbox;
mbox->dev = dev;
mbox->ops = &ti_msgmgr_chan_ops;
mbox->chans = inst->chans;
mbox->num_chans = inst->num_valid_queues;
mbox->txdone_irq = false;
mbox->txdone_poll = desc->tx_polled;
if (desc->tx_polled)
mbox->txpoll_period = desc->tx_poll_timeout_ms;
mbox->of_xlate = ti_msgmgr_of_xlate;
platform_set_drvdata(pdev, inst);
ret = mbox_controller_register(mbox);
if (ret)
dev_err(dev, "Failed to register mbox_controller(%d)\n", ret);
return ret;
}
static int ti_msgmgr_remove(struct platform_device *pdev)
{
struct ti_msgmgr_inst *inst;
inst = platform_get_drvdata(pdev);
mbox_controller_unregister(&inst->mbox);
return 0;
}
