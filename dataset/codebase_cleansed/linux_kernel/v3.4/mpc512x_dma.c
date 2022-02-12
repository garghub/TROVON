static inline struct mpc_dma_chan *dma_chan_to_mpc_dma_chan(struct dma_chan *c)
{
return container_of(c, struct mpc_dma_chan, chan);
}
static inline struct mpc_dma *dma_chan_to_mpc_dma(struct dma_chan *c)
{
struct mpc_dma_chan *mchan = dma_chan_to_mpc_dma_chan(c);
return container_of(mchan, struct mpc_dma, channels[c->chan_id]);
}
static void mpc_dma_execute(struct mpc_dma_chan *mchan)
{
struct mpc_dma *mdma = dma_chan_to_mpc_dma(&mchan->chan);
struct mpc_dma_desc *first = NULL;
struct mpc_dma_desc *prev = NULL;
struct mpc_dma_desc *mdesc;
int cid = mchan->chan.chan_id;
list_splice_tail_init(&mchan->queued, &mchan->active);
list_for_each_entry(mdesc, &mchan->active, node) {
if (!first)
first = mdesc;
if (!prev) {
prev = mdesc;
continue;
}
prev->tcd->dlast_sga = mdesc->tcd_paddr;
prev->tcd->e_sg = 1;
mdesc->tcd->start = 1;
prev = mdesc;
}
prev->tcd->int_maj = 1;
memcpy_toio(&mdma->tcd[cid], first->tcd, sizeof(struct mpc_dma_tcd));
if (first != prev)
mdma->tcd[cid].e_sg = 1;
out_8(&mdma->regs->dmassrt, cid);
}
static void mpc_dma_irq_process(struct mpc_dma *mdma, u32 is, u32 es, int off)
{
struct mpc_dma_chan *mchan;
struct mpc_dma_desc *mdesc;
u32 status = is | es;
int ch;
while ((ch = fls(status) - 1) >= 0) {
status &= ~(1 << ch);
mchan = &mdma->channels[ch + off];
spin_lock(&mchan->lock);
out_8(&mdma->regs->dmacint, ch + off);
out_8(&mdma->regs->dmacerr, ch + off);
if (es & (1 << ch))
list_for_each_entry(mdesc, &mchan->active, node)
mdesc->error = -EIO;
list_splice_tail_init(&mchan->active, &mchan->completed);
if (!list_empty(&mchan->queued))
mpc_dma_execute(mchan);
spin_unlock(&mchan->lock);
}
}
static irqreturn_t mpc_dma_irq(int irq, void *data)
{
struct mpc_dma *mdma = data;
uint es;
es = in_be32(&mdma->regs->dmaes);
spin_lock(&mdma->error_status_lock);
if ((es & MPC_DMA_DMAES_VLD) && mdma->error_status == 0)
mdma->error_status = es;
spin_unlock(&mdma->error_status_lock);
if (mdma->dma.chancnt > 32) {
mpc_dma_irq_process(mdma, in_be32(&mdma->regs->dmainth),
in_be32(&mdma->regs->dmaerrh), 32);
}
mpc_dma_irq_process(mdma, in_be32(&mdma->regs->dmaintl),
in_be32(&mdma->regs->dmaerrl), 0);
tasklet_schedule(&mdma->tasklet);
return IRQ_HANDLED;
}
static void mpc_dma_process_completed(struct mpc_dma *mdma)
{
dma_cookie_t last_cookie = 0;
struct mpc_dma_chan *mchan;
struct mpc_dma_desc *mdesc;
struct dma_async_tx_descriptor *desc;
unsigned long flags;
LIST_HEAD(list);
int i;
for (i = 0; i < mdma->dma.chancnt; i++) {
mchan = &mdma->channels[i];
spin_lock_irqsave(&mchan->lock, flags);
if (!list_empty(&mchan->completed))
list_splice_tail_init(&mchan->completed, &list);
spin_unlock_irqrestore(&mchan->lock, flags);
if (list_empty(&list))
continue;
list_for_each_entry(mdesc, &list, node) {
desc = &mdesc->desc;
if (desc->callback)
desc->callback(desc->callback_param);
last_cookie = desc->cookie;
dma_run_dependencies(desc);
}
spin_lock_irqsave(&mchan->lock, flags);
list_splice_tail_init(&list, &mchan->free);
mchan->chan.completed_cookie = last_cookie;
spin_unlock_irqrestore(&mchan->lock, flags);
}
}
static void mpc_dma_tasklet(unsigned long data)
{
struct mpc_dma *mdma = (void *)data;
unsigned long flags;
uint es;
spin_lock_irqsave(&mdma->error_status_lock, flags);
es = mdma->error_status;
mdma->error_status = 0;
spin_unlock_irqrestore(&mdma->error_status_lock, flags);
if (es) {
dev_err(mdma->dma.dev,
"Hardware reported following error(s) on channel %u:\n",
MPC_DMA_DMAES_ERRCHN(es));
if (es & MPC_DMA_DMAES_GPE)
dev_err(mdma->dma.dev, "- Group Priority Error\n");
if (es & MPC_DMA_DMAES_CPE)
dev_err(mdma->dma.dev, "- Channel Priority Error\n");
if (es & MPC_DMA_DMAES_SAE)
dev_err(mdma->dma.dev, "- Source Address Error\n");
if (es & MPC_DMA_DMAES_SOE)
dev_err(mdma->dma.dev, "- Source Offset"
" Configuration Error\n");
if (es & MPC_DMA_DMAES_DAE)
dev_err(mdma->dma.dev, "- Destination Address"
" Error\n");
if (es & MPC_DMA_DMAES_DOE)
dev_err(mdma->dma.dev, "- Destination Offset"
" Configuration Error\n");
if (es & MPC_DMA_DMAES_NCE)
dev_err(mdma->dma.dev, "- NBytes/Citter"
" Configuration Error\n");
if (es & MPC_DMA_DMAES_SGE)
dev_err(mdma->dma.dev, "- Scatter/Gather"
" Configuration Error\n");
if (es & MPC_DMA_DMAES_SBE)
dev_err(mdma->dma.dev, "- Source Bus Error\n");
if (es & MPC_DMA_DMAES_DBE)
dev_err(mdma->dma.dev, "- Destination Bus Error\n");
}
mpc_dma_process_completed(mdma);
}
static dma_cookie_t mpc_dma_tx_submit(struct dma_async_tx_descriptor *txd)
{
struct mpc_dma_chan *mchan = dma_chan_to_mpc_dma_chan(txd->chan);
struct mpc_dma_desc *mdesc;
unsigned long flags;
dma_cookie_t cookie;
mdesc = container_of(txd, struct mpc_dma_desc, desc);
spin_lock_irqsave(&mchan->lock, flags);
list_move_tail(&mdesc->node, &mchan->queued);
if (list_empty(&mchan->active))
mpc_dma_execute(mchan);
cookie = dma_cookie_assign(txd);
spin_unlock_irqrestore(&mchan->lock, flags);
return cookie;
}
static int mpc_dma_alloc_chan_resources(struct dma_chan *chan)
{
struct mpc_dma *mdma = dma_chan_to_mpc_dma(chan);
struct mpc_dma_chan *mchan = dma_chan_to_mpc_dma_chan(chan);
struct mpc_dma_desc *mdesc;
struct mpc_dma_tcd *tcd;
dma_addr_t tcd_paddr;
unsigned long flags;
LIST_HEAD(descs);
int i;
tcd = dma_alloc_coherent(mdma->dma.dev,
MPC_DMA_DESCRIPTORS * sizeof(struct mpc_dma_tcd),
&tcd_paddr, GFP_KERNEL);
if (!tcd)
return -ENOMEM;
for (i = 0; i < MPC_DMA_DESCRIPTORS; i++) {
mdesc = kzalloc(sizeof(struct mpc_dma_desc), GFP_KERNEL);
if (!mdesc) {
dev_notice(mdma->dma.dev, "Memory allocation error. "
"Allocated only %u descriptors\n", i);
break;
}
dma_async_tx_descriptor_init(&mdesc->desc, chan);
mdesc->desc.flags = DMA_CTRL_ACK;
mdesc->desc.tx_submit = mpc_dma_tx_submit;
mdesc->tcd = &tcd[i];
mdesc->tcd_paddr = tcd_paddr + (i * sizeof(struct mpc_dma_tcd));
list_add_tail(&mdesc->node, &descs);
}
if (i == 0) {
dma_free_coherent(mdma->dma.dev,
MPC_DMA_DESCRIPTORS * sizeof(struct mpc_dma_tcd),
tcd, tcd_paddr);
return -ENOMEM;
}
spin_lock_irqsave(&mchan->lock, flags);
mchan->tcd = tcd;
mchan->tcd_paddr = tcd_paddr;
list_splice_tail_init(&descs, &mchan->free);
spin_unlock_irqrestore(&mchan->lock, flags);
out_8(&mdma->regs->dmaseei, chan->chan_id);
return 0;
}
static void mpc_dma_free_chan_resources(struct dma_chan *chan)
{
struct mpc_dma *mdma = dma_chan_to_mpc_dma(chan);
struct mpc_dma_chan *mchan = dma_chan_to_mpc_dma_chan(chan);
struct mpc_dma_desc *mdesc, *tmp;
struct mpc_dma_tcd *tcd;
dma_addr_t tcd_paddr;
unsigned long flags;
LIST_HEAD(descs);
spin_lock_irqsave(&mchan->lock, flags);
BUG_ON(!list_empty(&mchan->prepared));
BUG_ON(!list_empty(&mchan->queued));
BUG_ON(!list_empty(&mchan->active));
BUG_ON(!list_empty(&mchan->completed));
list_splice_tail_init(&mchan->free, &descs);
tcd = mchan->tcd;
tcd_paddr = mchan->tcd_paddr;
spin_unlock_irqrestore(&mchan->lock, flags);
dma_free_coherent(mdma->dma.dev,
MPC_DMA_DESCRIPTORS * sizeof(struct mpc_dma_tcd),
tcd, tcd_paddr);
list_for_each_entry_safe(mdesc, tmp, &descs, node)
kfree(mdesc);
out_8(&mdma->regs->dmaceei, chan->chan_id);
}
static void mpc_dma_issue_pending(struct dma_chan *chan)
{
}
static enum dma_status
mpc_dma_tx_status(struct dma_chan *chan, dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct mpc_dma_chan *mchan = dma_chan_to_mpc_dma_chan(chan);
enum dma_status ret;
unsigned long flags;
spin_lock_irqsave(&mchan->lock, flags);
ret = dma_cookie_status(chan, cookie, txstate);
spin_unlock_irqrestore(&mchan->lock, flags);
return ret;
}
static struct dma_async_tx_descriptor *
mpc_dma_prep_memcpy(struct dma_chan *chan, dma_addr_t dst, dma_addr_t src,
size_t len, unsigned long flags)
{
struct mpc_dma *mdma = dma_chan_to_mpc_dma(chan);
struct mpc_dma_chan *mchan = dma_chan_to_mpc_dma_chan(chan);
struct mpc_dma_desc *mdesc = NULL;
struct mpc_dma_tcd *tcd;
unsigned long iflags;
spin_lock_irqsave(&mchan->lock, iflags);
if (!list_empty(&mchan->free)) {
mdesc = list_first_entry(&mchan->free, struct mpc_dma_desc,
node);
list_del(&mdesc->node);
}
spin_unlock_irqrestore(&mchan->lock, iflags);
if (!mdesc) {
mpc_dma_process_completed(mdma);
return NULL;
}
mdesc->error = 0;
tcd = mdesc->tcd;
memset(tcd, 0, sizeof(struct mpc_dma_tcd));
if (IS_ALIGNED(src | dst | len, 32)) {
tcd->ssize = MPC_DMA_TSIZE_32;
tcd->dsize = MPC_DMA_TSIZE_32;
tcd->soff = 32;
tcd->doff = 32;
} else if (!mdma->is_mpc8308 && IS_ALIGNED(src | dst | len, 16)) {
tcd->ssize = MPC_DMA_TSIZE_16;
tcd->dsize = MPC_DMA_TSIZE_16;
tcd->soff = 16;
tcd->doff = 16;
} else if (IS_ALIGNED(src | dst | len, 4)) {
tcd->ssize = MPC_DMA_TSIZE_4;
tcd->dsize = MPC_DMA_TSIZE_4;
tcd->soff = 4;
tcd->doff = 4;
} else if (IS_ALIGNED(src | dst | len, 2)) {
tcd->ssize = MPC_DMA_TSIZE_2;
tcd->dsize = MPC_DMA_TSIZE_2;
tcd->soff = 2;
tcd->doff = 2;
} else {
tcd->ssize = MPC_DMA_TSIZE_1;
tcd->dsize = MPC_DMA_TSIZE_1;
tcd->soff = 1;
tcd->doff = 1;
}
tcd->saddr = src;
tcd->daddr = dst;
tcd->nbytes = len;
tcd->biter = 1;
tcd->citer = 1;
spin_lock_irqsave(&mchan->lock, iflags);
list_add_tail(&mdesc->node, &mchan->prepared);
spin_unlock_irqrestore(&mchan->lock, iflags);
return &mdesc->desc;
}
static int __devinit mpc_dma_probe(struct platform_device *op)
{
struct device_node *dn = op->dev.of_node;
struct device *dev = &op->dev;
struct dma_device *dma;
struct mpc_dma *mdma;
struct mpc_dma_chan *mchan;
struct resource res;
ulong regs_start, regs_size;
int retval, i;
mdma = devm_kzalloc(dev, sizeof(struct mpc_dma), GFP_KERNEL);
if (!mdma) {
dev_err(dev, "Memory exhausted!\n");
return -ENOMEM;
}
mdma->irq = irq_of_parse_and_map(dn, 0);
if (mdma->irq == NO_IRQ) {
dev_err(dev, "Error mapping IRQ!\n");
return -EINVAL;
}
if (of_device_is_compatible(dn, "fsl,mpc8308-dma")) {
mdma->is_mpc8308 = 1;
mdma->irq2 = irq_of_parse_and_map(dn, 1);
if (mdma->irq2 == NO_IRQ) {
dev_err(dev, "Error mapping IRQ!\n");
return -EINVAL;
}
}
retval = of_address_to_resource(dn, 0, &res);
if (retval) {
dev_err(dev, "Error parsing memory region!\n");
return retval;
}
regs_start = res.start;
regs_size = resource_size(&res);
if (!devm_request_mem_region(dev, regs_start, regs_size, DRV_NAME)) {
dev_err(dev, "Error requesting memory region!\n");
return -EBUSY;
}
mdma->regs = devm_ioremap(dev, regs_start, regs_size);
if (!mdma->regs) {
dev_err(dev, "Error mapping memory region!\n");
return -ENOMEM;
}
mdma->tcd = (struct mpc_dma_tcd *)((u8 *)(mdma->regs)
+ MPC_DMA_TCD_OFFSET);
retval = devm_request_irq(dev, mdma->irq, &mpc_dma_irq, 0, DRV_NAME,
mdma);
if (retval) {
dev_err(dev, "Error requesting IRQ!\n");
return -EINVAL;
}
if (mdma->is_mpc8308) {
retval = devm_request_irq(dev, mdma->irq2, &mpc_dma_irq, 0,
DRV_NAME, mdma);
if (retval) {
dev_err(dev, "Error requesting IRQ2!\n");
return -EINVAL;
}
}
spin_lock_init(&mdma->error_status_lock);
dma = &mdma->dma;
dma->dev = dev;
if (!mdma->is_mpc8308)
dma->chancnt = MPC_DMA_CHANNELS;
else
dma->chancnt = 16;
dma->device_alloc_chan_resources = mpc_dma_alloc_chan_resources;
dma->device_free_chan_resources = mpc_dma_free_chan_resources;
dma->device_issue_pending = mpc_dma_issue_pending;
dma->device_tx_status = mpc_dma_tx_status;
dma->device_prep_dma_memcpy = mpc_dma_prep_memcpy;
INIT_LIST_HEAD(&dma->channels);
dma_cap_set(DMA_MEMCPY, dma->cap_mask);
for (i = 0; i < dma->chancnt; i++) {
mchan = &mdma->channels[i];
mchan->chan.device = dma;
dma_cookie_init(&mchan->chan);
INIT_LIST_HEAD(&mchan->free);
INIT_LIST_HEAD(&mchan->prepared);
INIT_LIST_HEAD(&mchan->queued);
INIT_LIST_HEAD(&mchan->active);
INIT_LIST_HEAD(&mchan->completed);
spin_lock_init(&mchan->lock);
list_add_tail(&mchan->chan.device_node, &dma->channels);
}
tasklet_init(&mdma->tasklet, mpc_dma_tasklet, (unsigned long)mdma);
if (!mdma->is_mpc8308) {
out_be32(&mdma->regs->dmacr, MPC_DMA_DMACR_EDCG |
MPC_DMA_DMACR_ERGA | MPC_DMA_DMACR_ERCA);
out_be32(&mdma->regs->dmaerqh, 0);
out_be32(&mdma->regs->dmaerql, 0);
out_be32(&mdma->regs->dmaeeih, 0);
out_be32(&mdma->regs->dmaeeil, 0);
out_be32(&mdma->regs->dmainth, 0xFFFFFFFF);
out_be32(&mdma->regs->dmaintl, 0xFFFFFFFF);
out_be32(&mdma->regs->dmaerrh, 0xFFFFFFFF);
out_be32(&mdma->regs->dmaerrl, 0xFFFFFFFF);
out_be32(&mdma->regs->dmaihsa, 0);
out_be32(&mdma->regs->dmailsa, 0);
} else {
out_be32(&mdma->regs->dmacr, MPC_DMA_DMACR_ERCA);
out_be32(&mdma->regs->dmagpor, MPC_DMA_DMAGPOR_SNOOP_ENABLE);
out_be32(&mdma->regs->dmaeeil, 0);
out_be32(&mdma->regs->dmaintl, 0xFFFF);
out_be32(&mdma->regs->dmaerrl, 0xFFFF);
}
dev_set_drvdata(dev, mdma);
retval = dma_async_device_register(dma);
if (retval) {
devm_free_irq(dev, mdma->irq, mdma);
irq_dispose_mapping(mdma->irq);
}
return retval;
}
static int __devexit mpc_dma_remove(struct platform_device *op)
{
struct device *dev = &op->dev;
struct mpc_dma *mdma = dev_get_drvdata(dev);
dma_async_device_unregister(&mdma->dma);
devm_free_irq(dev, mdma->irq, mdma);
irq_dispose_mapping(mdma->irq);
return 0;
}
