static int add_to_rbuf(struct mbox_chan *chan, void *mssg)
{
int idx;
unsigned long flags;
spin_lock_irqsave(&chan->lock, flags);
if (chan->msg_count == MBOX_TX_QUEUE_LEN) {
spin_unlock_irqrestore(&chan->lock, flags);
return -ENOBUFS;
}
idx = chan->msg_free;
chan->msg_data[idx] = mssg;
chan->msg_count++;
if (idx == MBOX_TX_QUEUE_LEN - 1)
chan->msg_free = 0;
else
chan->msg_free++;
spin_unlock_irqrestore(&chan->lock, flags);
return idx;
}
static void msg_submit(struct mbox_chan *chan)
{
unsigned count, idx;
unsigned long flags;
void *data;
int err = -EBUSY;
spin_lock_irqsave(&chan->lock, flags);
if (!chan->msg_count || chan->active_req)
goto exit;
count = chan->msg_count;
idx = chan->msg_free;
if (idx >= count)
idx -= count;
else
idx += MBOX_TX_QUEUE_LEN - count;
data = chan->msg_data[idx];
if (chan->cl->tx_prepare)
chan->cl->tx_prepare(chan->cl, data);
err = chan->mbox->ops->send_data(chan, data);
if (!err) {
chan->active_req = data;
chan->msg_count--;
}
exit:
spin_unlock_irqrestore(&chan->lock, flags);
if (!err && (chan->txdone_method & TXDONE_BY_POLL))
poll_txdone((unsigned long)chan->mbox);
}
static void tx_tick(struct mbox_chan *chan, int r)
{
unsigned long flags;
void *mssg;
spin_lock_irqsave(&chan->lock, flags);
mssg = chan->active_req;
chan->active_req = NULL;
spin_unlock_irqrestore(&chan->lock, flags);
msg_submit(chan);
if (mssg && chan->cl->tx_done)
chan->cl->tx_done(chan->cl, mssg, r);
if (chan->cl->tx_block)
complete(&chan->tx_complete);
}
static void poll_txdone(unsigned long data)
{
struct mbox_controller *mbox = (struct mbox_controller *)data;
bool txdone, resched = false;
int i;
for (i = 0; i < mbox->num_chans; i++) {
struct mbox_chan *chan = &mbox->chans[i];
if (chan->active_req && chan->cl) {
txdone = chan->mbox->ops->last_tx_done(chan);
if (txdone)
tx_tick(chan, 0);
else
resched = true;
}
}
if (resched)
mod_timer(&mbox->poll, jiffies +
msecs_to_jiffies(mbox->txpoll_period));
}
void mbox_chan_received_data(struct mbox_chan *chan, void *mssg)
{
if (chan->cl->rx_callback)
chan->cl->rx_callback(chan->cl, mssg);
}
void mbox_chan_txdone(struct mbox_chan *chan, int r)
{
if (unlikely(!(chan->txdone_method & TXDONE_BY_IRQ))) {
dev_err(chan->mbox->dev,
"Controller can't run the TX ticker\n");
return;
}
tx_tick(chan, r);
}
void mbox_client_txdone(struct mbox_chan *chan, int r)
{
if (unlikely(!(chan->txdone_method & TXDONE_BY_ACK))) {
dev_err(chan->mbox->dev, "Client can't run the TX ticker\n");
return;
}
tx_tick(chan, r);
}
bool mbox_client_peek_data(struct mbox_chan *chan)
{
if (chan->mbox->ops->peek_data)
return chan->mbox->ops->peek_data(chan);
return false;
}
int mbox_send_message(struct mbox_chan *chan, void *mssg)
{
int t;
if (!chan || !chan->cl)
return -EINVAL;
t = add_to_rbuf(chan, mssg);
if (t < 0) {
dev_err(chan->mbox->dev, "Try increasing MBOX_TX_QUEUE_LEN\n");
return t;
}
msg_submit(chan);
if (chan->cl->tx_block && chan->active_req) {
unsigned long wait;
int ret;
if (!chan->cl->tx_tout)
wait = msecs_to_jiffies(3600000);
else
wait = msecs_to_jiffies(chan->cl->tx_tout);
ret = wait_for_completion_timeout(&chan->tx_complete, wait);
if (ret == 0) {
t = -EIO;
tx_tick(chan, -EIO);
}
}
return t;
}
struct mbox_chan *mbox_request_channel(struct mbox_client *cl, int index)
{
struct device *dev = cl->dev;
struct mbox_controller *mbox;
struct of_phandle_args spec;
struct mbox_chan *chan;
unsigned long flags;
int ret;
if (!dev || !dev->of_node) {
pr_debug("%s: No owner device node\n", __func__);
return ERR_PTR(-ENODEV);
}
mutex_lock(&con_mutex);
if (of_parse_phandle_with_args(dev->of_node, "mboxes",
"#mbox-cells", index, &spec)) {
dev_dbg(dev, "%s: can't parse \"mboxes\" property\n", __func__);
mutex_unlock(&con_mutex);
return ERR_PTR(-ENODEV);
}
chan = ERR_PTR(-EPROBE_DEFER);
list_for_each_entry(mbox, &mbox_cons, node)
if (mbox->dev->of_node == spec.np) {
chan = mbox->of_xlate(mbox, &spec);
break;
}
of_node_put(spec.np);
if (IS_ERR(chan)) {
mutex_unlock(&con_mutex);
return chan;
}
if (chan->cl || !try_module_get(mbox->dev->driver->owner)) {
dev_dbg(dev, "%s: mailbox not free\n", __func__);
mutex_unlock(&con_mutex);
return ERR_PTR(-EBUSY);
}
spin_lock_irqsave(&chan->lock, flags);
chan->msg_free = 0;
chan->msg_count = 0;
chan->active_req = NULL;
chan->cl = cl;
init_completion(&chan->tx_complete);
if (chan->txdone_method == TXDONE_BY_POLL && cl->knows_txdone)
chan->txdone_method |= TXDONE_BY_ACK;
spin_unlock_irqrestore(&chan->lock, flags);
ret = chan->mbox->ops->startup(chan);
if (ret) {
dev_err(dev, "Unable to startup the chan (%d)\n", ret);
mbox_free_channel(chan);
chan = ERR_PTR(ret);
}
mutex_unlock(&con_mutex);
return chan;
}
struct mbox_chan *mbox_request_channel_byname(struct mbox_client *cl,
const char *name)
{
struct device_node *np = cl->dev->of_node;
struct property *prop;
const char *mbox_name;
int index = 0;
if (!np) {
dev_err(cl->dev, "%s() currently only supports DT\n", __func__);
return ERR_PTR(-ENOSYS);
}
if (!of_get_property(np, "mbox-names", NULL)) {
dev_err(cl->dev,
"%s() requires an \"mbox-names\" property\n", __func__);
return ERR_PTR(-ENOSYS);
}
of_property_for_each_string(np, "mbox-names", prop, mbox_name) {
if (!strncmp(name, mbox_name, strlen(name)))
break;
index++;
}
return mbox_request_channel(cl, index);
}
void mbox_free_channel(struct mbox_chan *chan)
{
unsigned long flags;
if (!chan || !chan->cl)
return;
chan->mbox->ops->shutdown(chan);
spin_lock_irqsave(&chan->lock, flags);
chan->cl = NULL;
chan->active_req = NULL;
if (chan->txdone_method == (TXDONE_BY_POLL | TXDONE_BY_ACK))
chan->txdone_method = TXDONE_BY_POLL;
module_put(chan->mbox->dev->driver->owner);
spin_unlock_irqrestore(&chan->lock, flags);
}
static struct mbox_chan *
of_mbox_index_xlate(struct mbox_controller *mbox,
const struct of_phandle_args *sp)
{
int ind = sp->args[0];
if (ind >= mbox->num_chans)
return ERR_PTR(-EINVAL);
return &mbox->chans[ind];
}
int mbox_controller_register(struct mbox_controller *mbox)
{
int i, txdone;
if (!mbox || !mbox->dev || !mbox->ops || !mbox->num_chans)
return -EINVAL;
if (mbox->txdone_irq)
txdone = TXDONE_BY_IRQ;
else if (mbox->txdone_poll)
txdone = TXDONE_BY_POLL;
else
txdone = TXDONE_BY_ACK;
if (txdone == TXDONE_BY_POLL) {
mbox->poll.function = &poll_txdone;
mbox->poll.data = (unsigned long)mbox;
init_timer(&mbox->poll);
}
for (i = 0; i < mbox->num_chans; i++) {
struct mbox_chan *chan = &mbox->chans[i];
chan->cl = NULL;
chan->mbox = mbox;
chan->txdone_method = txdone;
spin_lock_init(&chan->lock);
}
if (!mbox->of_xlate)
mbox->of_xlate = of_mbox_index_xlate;
mutex_lock(&con_mutex);
list_add_tail(&mbox->node, &mbox_cons);
mutex_unlock(&con_mutex);
return 0;
}
void mbox_controller_unregister(struct mbox_controller *mbox)
{
int i;
if (!mbox)
return;
mutex_lock(&con_mutex);
list_del(&mbox->node);
for (i = 0; i < mbox->num_chans; i++)
mbox_free_channel(&mbox->chans[i]);
if (mbox->txdone_poll)
del_timer_sync(&mbox->poll);
mutex_unlock(&con_mutex);
}
