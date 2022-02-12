static inline struct dma_pl330_chan *
to_pchan(struct dma_chan *ch)
{
if (!ch)
return NULL;
return container_of(ch, struct dma_pl330_chan, chan);
}
static inline struct dma_pl330_desc *
to_desc(struct dma_async_tx_descriptor *tx)
{
return container_of(tx, struct dma_pl330_desc, txd);
}
static inline void free_desc_list(struct list_head *list)
{
struct dma_pl330_dmac *pdmac;
struct dma_pl330_desc *desc;
struct dma_pl330_chan *pch;
unsigned long flags;
if (list_empty(list))
return;
list_for_each_entry(desc, list, node) {
dma_async_tx_callback callback;
void *param;
pch = desc->pchan;
callback = desc->txd.callback;
param = desc->txd.callback_param;
if (callback)
callback(param);
desc->pchan = NULL;
}
pdmac = pch->dmac;
spin_lock_irqsave(&pdmac->pool_lock, flags);
list_splice_tail_init(list, &pdmac->desc_pool);
spin_unlock_irqrestore(&pdmac->pool_lock, flags);
}
static inline void fill_queue(struct dma_pl330_chan *pch)
{
struct dma_pl330_desc *desc;
int ret;
list_for_each_entry(desc, &pch->work_list, node) {
if (desc->status == BUSY)
break;
ret = pl330_submit_req(pch->pl330_chid,
&desc->req);
if (!ret) {
desc->status = BUSY;
break;
} else if (ret == -EAGAIN) {
break;
} else {
desc->status = DONE;
dev_err(pch->dmac->pif.dev, "%s:%d Bad Desc(%d)\n",
__func__, __LINE__, desc->txd.cookie);
tasklet_schedule(&pch->task);
}
}
}
static void pl330_tasklet(unsigned long data)
{
struct dma_pl330_chan *pch = (struct dma_pl330_chan *)data;
struct dma_pl330_desc *desc, *_dt;
unsigned long flags;
LIST_HEAD(list);
spin_lock_irqsave(&pch->lock, flags);
list_for_each_entry_safe(desc, _dt, &pch->work_list, node)
if (desc->status == DONE) {
pch->completed = desc->txd.cookie;
list_move_tail(&desc->node, &list);
}
fill_queue(pch);
pl330_chan_ctrl(pch->pl330_chid, PL330_OP_START);
spin_unlock_irqrestore(&pch->lock, flags);
free_desc_list(&list);
}
static void dma_pl330_rqcb(void *token, enum pl330_op_err err)
{
struct dma_pl330_desc *desc = token;
struct dma_pl330_chan *pch = desc->pchan;
unsigned long flags;
if (!pch)
return;
spin_lock_irqsave(&pch->lock, flags);
desc->status = DONE;
spin_unlock_irqrestore(&pch->lock, flags);
tasklet_schedule(&pch->task);
}
static int pl330_alloc_chan_resources(struct dma_chan *chan)
{
struct dma_pl330_chan *pch = to_pchan(chan);
struct dma_pl330_dmac *pdmac = pch->dmac;
unsigned long flags;
spin_lock_irqsave(&pch->lock, flags);
pch->completed = chan->cookie = 1;
pch->pl330_chid = pl330_request_channel(&pdmac->pif);
if (!pch->pl330_chid) {
spin_unlock_irqrestore(&pch->lock, flags);
return 0;
}
tasklet_init(&pch->task, pl330_tasklet, (unsigned long) pch);
spin_unlock_irqrestore(&pch->lock, flags);
return 1;
}
static int pl330_control(struct dma_chan *chan, enum dma_ctrl_cmd cmd, unsigned long arg)
{
struct dma_pl330_chan *pch = to_pchan(chan);
struct dma_pl330_desc *desc;
unsigned long flags;
if (cmd != DMA_TERMINATE_ALL)
return -ENXIO;
spin_lock_irqsave(&pch->lock, flags);
pl330_chan_ctrl(pch->pl330_chid, PL330_OP_FLUSH);
list_for_each_entry(desc, &pch->work_list, node)
desc->status = DONE;
spin_unlock_irqrestore(&pch->lock, flags);
pl330_tasklet((unsigned long) pch);
return 0;
}
static void pl330_free_chan_resources(struct dma_chan *chan)
{
struct dma_pl330_chan *pch = to_pchan(chan);
unsigned long flags;
spin_lock_irqsave(&pch->lock, flags);
tasklet_kill(&pch->task);
pl330_release_channel(pch->pl330_chid);
pch->pl330_chid = NULL;
spin_unlock_irqrestore(&pch->lock, flags);
}
static enum dma_status
pl330_tx_status(struct dma_chan *chan, dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct dma_pl330_chan *pch = to_pchan(chan);
dma_cookie_t last_done, last_used;
int ret;
last_done = pch->completed;
last_used = chan->cookie;
ret = dma_async_is_complete(cookie, last_done, last_used);
dma_set_tx_state(txstate, last_done, last_used, 0);
return ret;
}
static void pl330_issue_pending(struct dma_chan *chan)
{
pl330_tasklet((unsigned long) to_pchan(chan));
}
static dma_cookie_t pl330_tx_submit(struct dma_async_tx_descriptor *tx)
{
struct dma_pl330_desc *desc, *last = to_desc(tx);
struct dma_pl330_chan *pch = to_pchan(tx->chan);
dma_cookie_t cookie;
unsigned long flags;
spin_lock_irqsave(&pch->lock, flags);
cookie = tx->chan->cookie;
while (!list_empty(&last->node)) {
desc = list_entry(last->node.next, struct dma_pl330_desc, node);
if (++cookie < 0)
cookie = 1;
desc->txd.cookie = cookie;
list_move_tail(&desc->node, &pch->work_list);
}
if (++cookie < 0)
cookie = 1;
last->txd.cookie = cookie;
list_add_tail(&last->node, &pch->work_list);
tx->chan->cookie = cookie;
spin_unlock_irqrestore(&pch->lock, flags);
return cookie;
}
static inline void _init_desc(struct dma_pl330_desc *desc)
{
desc->pchan = NULL;
desc->req.x = &desc->px;
desc->req.token = desc;
desc->rqcfg.swap = SWAP_NO;
desc->rqcfg.privileged = 0;
desc->rqcfg.insnaccess = 0;
desc->rqcfg.scctl = SCCTRL0;
desc->rqcfg.dcctl = DCCTRL0;
desc->req.cfg = &desc->rqcfg;
desc->req.xfer_cb = dma_pl330_rqcb;
desc->txd.tx_submit = pl330_tx_submit;
INIT_LIST_HEAD(&desc->node);
}
int add_desc(struct dma_pl330_dmac *pdmac, gfp_t flg, int count)
{
struct dma_pl330_desc *desc;
unsigned long flags;
int i;
if (!pdmac)
return 0;
desc = kmalloc(count * sizeof(*desc), flg);
if (!desc)
return 0;
spin_lock_irqsave(&pdmac->pool_lock, flags);
for (i = 0; i < count; i++) {
_init_desc(&desc[i]);
list_add_tail(&desc[i].node, &pdmac->desc_pool);
}
spin_unlock_irqrestore(&pdmac->pool_lock, flags);
return count;
}
static struct dma_pl330_desc *
pluck_desc(struct dma_pl330_dmac *pdmac)
{
struct dma_pl330_desc *desc = NULL;
unsigned long flags;
if (!pdmac)
return NULL;
spin_lock_irqsave(&pdmac->pool_lock, flags);
if (!list_empty(&pdmac->desc_pool)) {
desc = list_entry(pdmac->desc_pool.next,
struct dma_pl330_desc, node);
list_del_init(&desc->node);
desc->status = PREP;
desc->txd.callback = NULL;
}
spin_unlock_irqrestore(&pdmac->pool_lock, flags);
return desc;
}
static struct dma_pl330_desc *pl330_get_desc(struct dma_pl330_chan *pch)
{
struct dma_pl330_dmac *pdmac = pch->dmac;
struct dma_pl330_peri *peri = pch->chan.private;
struct dma_pl330_desc *desc;
desc = pluck_desc(pdmac);
if (!desc) {
if (!add_desc(pdmac, GFP_ATOMIC, 1))
return NULL;
desc = pluck_desc(pdmac);
if (!desc) {
dev_err(pch->dmac->pif.dev,
"%s:%d ALERT!\n", __func__, __LINE__);
return NULL;
}
}
desc->pchan = pch;
desc->txd.cookie = 0;
async_tx_ack(&desc->txd);
desc->req.rqtype = peri->rqtype;
desc->req.peri = peri->peri_id;
dma_async_tx_descriptor_init(&desc->txd, &pch->chan);
return desc;
}
static inline void fill_px(struct pl330_xfer *px,
dma_addr_t dst, dma_addr_t src, size_t len)
{
px->next = NULL;
px->bytes = len;
px->dst_addr = dst;
px->src_addr = src;
}
static struct dma_pl330_desc *
__pl330_prep_dma_memcpy(struct dma_pl330_chan *pch, dma_addr_t dst,
dma_addr_t src, size_t len)
{
struct dma_pl330_desc *desc = pl330_get_desc(pch);
if (!desc) {
dev_err(pch->dmac->pif.dev, "%s:%d Unable to fetch desc\n",
__func__, __LINE__);
return NULL;
}
fill_px(&desc->px, dst, src, len);
return desc;
}
static inline int get_burst_len(struct dma_pl330_desc *desc, size_t len)
{
struct dma_pl330_chan *pch = desc->pchan;
struct pl330_info *pi = &pch->dmac->pif;
int burst_len;
burst_len = pi->pcfg.data_bus_width / 8;
burst_len *= pi->pcfg.data_buf_dep;
burst_len >>= desc->rqcfg.brst_size;
if (burst_len > 16)
burst_len = 16;
while (burst_len > 1) {
if (!(len % (burst_len << desc->rqcfg.brst_size)))
break;
burst_len--;
}
return burst_len;
}
static struct dma_async_tx_descriptor *
pl330_prep_dma_memcpy(struct dma_chan *chan, dma_addr_t dst,
dma_addr_t src, size_t len, unsigned long flags)
{
struct dma_pl330_desc *desc;
struct dma_pl330_chan *pch = to_pchan(chan);
struct dma_pl330_peri *peri = chan->private;
struct pl330_info *pi;
int burst;
if (unlikely(!pch || !len || !peri))
return NULL;
if (peri->rqtype != MEMTOMEM)
return NULL;
pi = &pch->dmac->pif;
desc = __pl330_prep_dma_memcpy(pch, dst, src, len);
if (!desc)
return NULL;
desc->rqcfg.src_inc = 1;
desc->rqcfg.dst_inc = 1;
burst = pi->pcfg.data_bus_width / 8;
while (burst > 1) {
if (!(len % burst))
break;
burst /= 2;
}
desc->rqcfg.brst_size = 0;
while (burst != (1 << desc->rqcfg.brst_size))
desc->rqcfg.brst_size++;
desc->rqcfg.brst_len = get_burst_len(desc, len);
desc->txd.flags = flags;
return &desc->txd;
}
static struct dma_async_tx_descriptor *
pl330_prep_slave_sg(struct dma_chan *chan, struct scatterlist *sgl,
unsigned int sg_len, enum dma_data_direction direction,
unsigned long flg)
{
struct dma_pl330_desc *first, *desc = NULL;
struct dma_pl330_chan *pch = to_pchan(chan);
struct dma_pl330_peri *peri = chan->private;
struct scatterlist *sg;
unsigned long flags;
int i, burst_size;
dma_addr_t addr;
if (unlikely(!pch || !sgl || !sg_len))
return NULL;
if ((direction == DMA_TO_DEVICE &&
peri->rqtype != MEMTODEV) ||
(direction == DMA_FROM_DEVICE &&
peri->rqtype != DEVTOMEM)) {
dev_err(pch->dmac->pif.dev, "%s:%d Invalid Direction\n",
__func__, __LINE__);
return NULL;
}
addr = peri->fifo_addr;
burst_size = peri->burst_sz;
first = NULL;
for_each_sg(sgl, sg, sg_len, i) {
desc = pl330_get_desc(pch);
if (!desc) {
struct dma_pl330_dmac *pdmac = pch->dmac;
dev_err(pch->dmac->pif.dev,
"%s:%d Unable to fetch desc\n",
__func__, __LINE__);
if (!first)
return NULL;
spin_lock_irqsave(&pdmac->pool_lock, flags);
while (!list_empty(&first->node)) {
desc = list_entry(first->node.next,
struct dma_pl330_desc, node);
list_move_tail(&desc->node, &pdmac->desc_pool);
}
list_move_tail(&first->node, &pdmac->desc_pool);
spin_unlock_irqrestore(&pdmac->pool_lock, flags);
return NULL;
}
if (!first)
first = desc;
else
list_add_tail(&desc->node, &first->node);
if (direction == DMA_TO_DEVICE) {
desc->rqcfg.src_inc = 1;
desc->rqcfg.dst_inc = 0;
fill_px(&desc->px,
addr, sg_dma_address(sg), sg_dma_len(sg));
} else {
desc->rqcfg.src_inc = 0;
desc->rqcfg.dst_inc = 1;
fill_px(&desc->px,
sg_dma_address(sg), addr, sg_dma_len(sg));
}
desc->rqcfg.brst_size = burst_size;
desc->rqcfg.brst_len = 1;
}
desc->txd.flags = flg;
return &desc->txd;
}
static irqreturn_t pl330_irq_handler(int irq, void *data)
{
if (pl330_update(data))
return IRQ_HANDLED;
else
return IRQ_NONE;
}
static int __devinit
pl330_probe(struct amba_device *adev, const struct amba_id *id)
{
struct dma_pl330_platdata *pdat;
struct dma_pl330_dmac *pdmac;
struct dma_pl330_chan *pch;
struct pl330_info *pi;
struct dma_device *pd;
struct resource *res;
int i, ret, irq;
pdat = adev->dev.platform_data;
if (!pdat || !pdat->nr_valid_peri) {
dev_err(&adev->dev, "platform data missing\n");
return -ENODEV;
}
pdmac = kzalloc(pdat->nr_valid_peri * sizeof(*pch)
+ sizeof(*pdmac), GFP_KERNEL);
if (!pdmac) {
dev_err(&adev->dev, "unable to allocate mem\n");
return -ENOMEM;
}
pi = &pdmac->pif;
pi->dev = &adev->dev;
pi->pl330_data = NULL;
pi->mcbufsz = pdat->mcbuf_sz;
res = &adev->res;
request_mem_region(res->start, resource_size(res), "dma-pl330");
pi->base = ioremap(res->start, resource_size(res));
if (!pi->base) {
ret = -ENXIO;
goto probe_err1;
}
irq = adev->irq[0];
ret = request_irq(irq, pl330_irq_handler, 0,
dev_name(&adev->dev), pi);
if (ret)
goto probe_err2;
ret = pl330_add(pi);
if (ret)
goto probe_err3;
INIT_LIST_HEAD(&pdmac->desc_pool);
spin_lock_init(&pdmac->pool_lock);
if (!add_desc(pdmac, GFP_KERNEL, NR_DEFAULT_DESC))
dev_warn(&adev->dev, "unable to allocate desc\n");
pd = &pdmac->ddma;
INIT_LIST_HEAD(&pd->channels);
for (i = 0; i < pdat->nr_valid_peri; i++) {
struct dma_pl330_peri *peri = &pdat->peri[i];
pch = &pdmac->peripherals[i];
switch (peri->rqtype) {
case MEMTOMEM:
dma_cap_set(DMA_MEMCPY, pd->cap_mask);
break;
case MEMTODEV:
case DEVTOMEM:
dma_cap_set(DMA_SLAVE, pd->cap_mask);
break;
default:
dev_err(&adev->dev, "DEVTODEV Not Supported\n");
continue;
}
INIT_LIST_HEAD(&pch->work_list);
spin_lock_init(&pch->lock);
pch->pl330_chid = NULL;
pch->chan.private = peri;
pch->chan.device = pd;
pch->chan.chan_id = i;
pch->dmac = pdmac;
pd->chancnt++;
list_add_tail(&pch->chan.device_node, &pd->channels);
}
pd->dev = &adev->dev;
pd->device_alloc_chan_resources = pl330_alloc_chan_resources;
pd->device_free_chan_resources = pl330_free_chan_resources;
pd->device_prep_dma_memcpy = pl330_prep_dma_memcpy;
pd->device_tx_status = pl330_tx_status;
pd->device_prep_slave_sg = pl330_prep_slave_sg;
pd->device_control = pl330_control;
pd->device_issue_pending = pl330_issue_pending;
ret = dma_async_device_register(pd);
if (ret) {
dev_err(&adev->dev, "unable to register DMAC\n");
goto probe_err4;
}
amba_set_drvdata(adev, pdmac);
dev_info(&adev->dev,
"Loaded driver for PL330 DMAC-%d\n", adev->periphid);
dev_info(&adev->dev,
"\tDBUFF-%ux%ubytes Num_Chans-%u Num_Peri-%u Num_Events-%u\n",
pi->pcfg.data_buf_dep,
pi->pcfg.data_bus_width / 8, pi->pcfg.num_chan,
pi->pcfg.num_peri, pi->pcfg.num_events);
return 0;
probe_err4:
pl330_del(pi);
probe_err3:
free_irq(irq, pi);
probe_err2:
iounmap(pi->base);
probe_err1:
release_mem_region(res->start, resource_size(res));
kfree(pdmac);
return ret;
}
static int __devexit pl330_remove(struct amba_device *adev)
{
struct dma_pl330_dmac *pdmac = amba_get_drvdata(adev);
struct dma_pl330_chan *pch, *_p;
struct pl330_info *pi;
struct resource *res;
int irq;
if (!pdmac)
return 0;
amba_set_drvdata(adev, NULL);
list_for_each_entry_safe(pch, _p, &pdmac->ddma.channels,
chan.device_node) {
list_del(&pch->chan.device_node);
pl330_control(&pch->chan, DMA_TERMINATE_ALL, 0);
pl330_free_chan_resources(&pch->chan);
}
pi = &pdmac->pif;
pl330_del(pi);
irq = adev->irq[0];
free_irq(irq, pi);
iounmap(pi->base);
res = &adev->res;
release_mem_region(res->start, resource_size(res));
kfree(pdmac);
return 0;
}
static int __init pl330_init(void)
{
return amba_driver_register(&pl330_driver);
}
static void __exit pl330_exit(void)
{
amba_driver_unregister(&pl330_driver);
return;
}
