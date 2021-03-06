static int __init async_tx_init(void)
{
async_dmaengine_get();
printk(KERN_INFO "async_tx: api initialized (async)\n");
return 0;
}
static void __exit async_tx_exit(void)
{
async_dmaengine_put();
}
struct dma_chan *
__async_tx_find_channel(struct async_submit_ctl *submit,
enum dma_transaction_type tx_type)
{
struct dma_async_tx_descriptor *depend_tx = submit->depend_tx;
if (depend_tx &&
dma_has_cap(tx_type, depend_tx->chan->device->cap_mask))
return depend_tx->chan;
return async_dma_find_channel(tx_type);
}
static void
async_tx_channel_switch(struct dma_async_tx_descriptor *depend_tx,
struct dma_async_tx_descriptor *tx)
{
struct dma_chan *chan = depend_tx->chan;
struct dma_device *device = chan->device;
struct dma_async_tx_descriptor *intr_tx = (void *) ~0;
txd_lock(depend_tx);
if (txd_parent(depend_tx) && depend_tx->chan == tx->chan) {
txd_chain(depend_tx, tx);
intr_tx = NULL;
}
txd_unlock(depend_tx);
if (!intr_tx) {
device->device_issue_pending(chan);
return;
}
if (dma_has_cap(DMA_INTERRUPT, device->cap_mask))
intr_tx = device->device_prep_dma_interrupt(chan, 0);
else
intr_tx = NULL;
if (intr_tx) {
intr_tx->callback = NULL;
intr_tx->callback_param = NULL;
txd_chain(intr_tx, tx);
txd_lock(depend_tx);
if (txd_parent(depend_tx)) {
txd_chain(depend_tx, intr_tx);
async_tx_ack(intr_tx);
intr_tx = NULL;
}
txd_unlock(depend_tx);
if (intr_tx) {
txd_clear_parent(intr_tx);
intr_tx->tx_submit(intr_tx);
async_tx_ack(intr_tx);
}
device->device_issue_pending(chan);
} else {
if (dma_wait_for_async_tx(depend_tx) == DMA_ERROR)
panic("%s: DMA_ERROR waiting for depend_tx\n",
__func__);
tx->tx_submit(tx);
}
}
void
async_tx_submit(struct dma_chan *chan, struct dma_async_tx_descriptor *tx,
struct async_submit_ctl *submit)
{
struct dma_async_tx_descriptor *depend_tx = submit->depend_tx;
tx->callback = submit->cb_fn;
tx->callback_param = submit->cb_param;
if (depend_tx) {
enum submit_disposition s;
BUG_ON(async_tx_test_ack(depend_tx) || txd_next(depend_tx) ||
txd_parent(tx));
txd_lock(depend_tx);
if (txd_parent(depend_tx)) {
if (depend_tx->chan == chan) {
txd_chain(depend_tx, tx);
s = ASYNC_TX_SUBMITTED;
} else
s = ASYNC_TX_CHANNEL_SWITCH;
} else {
if (depend_tx->chan == chan)
s = ASYNC_TX_DIRECT_SUBMIT;
else
s = ASYNC_TX_CHANNEL_SWITCH;
}
txd_unlock(depend_tx);
switch (s) {
case ASYNC_TX_SUBMITTED:
break;
case ASYNC_TX_CHANNEL_SWITCH:
async_tx_channel_switch(depend_tx, tx);
break;
case ASYNC_TX_DIRECT_SUBMIT:
txd_clear_parent(tx);
tx->tx_submit(tx);
break;
}
} else {
txd_clear_parent(tx);
tx->tx_submit(tx);
}
if (submit->flags & ASYNC_TX_ACK)
async_tx_ack(tx);
if (depend_tx)
async_tx_ack(depend_tx);
}
struct dma_async_tx_descriptor *
async_trigger_callback(struct async_submit_ctl *submit)
{
struct dma_chan *chan;
struct dma_device *device;
struct dma_async_tx_descriptor *tx;
struct dma_async_tx_descriptor *depend_tx = submit->depend_tx;
if (depend_tx) {
chan = depend_tx->chan;
device = chan->device;
if (device && !dma_has_cap(DMA_INTERRUPT, device->cap_mask))
device = NULL;
tx = device ? device->device_prep_dma_interrupt(chan, 0) : NULL;
} else
tx = NULL;
if (tx) {
pr_debug("%s: (async)\n", __func__);
async_tx_submit(chan, tx, submit);
} else {
pr_debug("%s: (sync)\n", __func__);
async_tx_quiesce(&submit->depend_tx);
async_tx_sync_epilog(submit);
}
return tx;
}
void async_tx_quiesce(struct dma_async_tx_descriptor **tx)
{
if (*tx) {
BUG_ON(async_tx_test_ack(*tx));
if (dma_wait_for_async_tx(*tx) == DMA_ERROR)
panic("DMA_ERROR waiting for transaction\n");
async_tx_ack(*tx);
*tx = NULL;
}
}
