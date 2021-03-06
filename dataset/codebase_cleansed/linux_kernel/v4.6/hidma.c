static inline struct hidma_dev *to_hidma_dev(struct dma_device *dmadev)
{
return container_of(dmadev, struct hidma_dev, ddev);
}
static inline
struct hidma_dev *to_hidma_dev_from_lldev(struct hidma_lldev **_lldevp)
{
return container_of(_lldevp, struct hidma_dev, lldev);
}
static inline struct hidma_chan *to_hidma_chan(struct dma_chan *dmach)
{
return container_of(dmach, struct hidma_chan, chan);
}
static inline
struct hidma_desc *to_hidma_desc(struct dma_async_tx_descriptor *t)
{
return container_of(t, struct hidma_desc, desc);
}
static void hidma_free(struct hidma_dev *dmadev)
{
INIT_LIST_HEAD(&dmadev->ddev.channels);
}
static void hidma_process_completed(struct hidma_chan *mchan)
{
struct dma_device *ddev = mchan->chan.device;
struct hidma_dev *mdma = to_hidma_dev(ddev);
struct dma_async_tx_descriptor *desc;
dma_cookie_t last_cookie;
struct hidma_desc *mdesc;
unsigned long irqflags;
struct list_head list;
INIT_LIST_HEAD(&list);
spin_lock_irqsave(&mchan->lock, irqflags);
list_splice_tail_init(&mchan->completed, &list);
spin_unlock_irqrestore(&mchan->lock, irqflags);
list_for_each_entry(mdesc, &list, node) {
enum dma_status llstat;
desc = &mdesc->desc;
spin_lock_irqsave(&mchan->lock, irqflags);
dma_cookie_complete(desc);
spin_unlock_irqrestore(&mchan->lock, irqflags);
llstat = hidma_ll_status(mdma->lldev, mdesc->tre_ch);
if (desc->callback && (llstat == DMA_COMPLETE))
desc->callback(desc->callback_param);
last_cookie = desc->cookie;
dma_run_dependencies(desc);
}
spin_lock_irqsave(&mchan->lock, irqflags);
list_splice_tail_init(&list, &mchan->free);
spin_unlock_irqrestore(&mchan->lock, irqflags);
}
static void hidma_callback(void *data)
{
struct hidma_desc *mdesc = data;
struct hidma_chan *mchan = to_hidma_chan(mdesc->desc.chan);
struct dma_device *ddev = mchan->chan.device;
struct hidma_dev *dmadev = to_hidma_dev(ddev);
unsigned long irqflags;
bool queued = false;
spin_lock_irqsave(&mchan->lock, irqflags);
if (mdesc->node.next) {
list_move_tail(&mdesc->node, &mchan->completed);
queued = true;
mchan->running = list_first_entry(&mchan->active,
struct hidma_desc, node);
}
spin_unlock_irqrestore(&mchan->lock, irqflags);
hidma_process_completed(mchan);
if (queued) {
pm_runtime_mark_last_busy(dmadev->ddev.dev);
pm_runtime_put_autosuspend(dmadev->ddev.dev);
}
}
static int hidma_chan_init(struct hidma_dev *dmadev, u32 dma_sig)
{
struct hidma_chan *mchan;
struct dma_device *ddev;
mchan = devm_kzalloc(dmadev->ddev.dev, sizeof(*mchan), GFP_KERNEL);
if (!mchan)
return -ENOMEM;
ddev = &dmadev->ddev;
mchan->dma_sig = dma_sig;
mchan->dmadev = dmadev;
mchan->chan.device = ddev;
dma_cookie_init(&mchan->chan);
INIT_LIST_HEAD(&mchan->free);
INIT_LIST_HEAD(&mchan->prepared);
INIT_LIST_HEAD(&mchan->active);
INIT_LIST_HEAD(&mchan->completed);
spin_lock_init(&mchan->lock);
list_add_tail(&mchan->chan.device_node, &ddev->channels);
dmadev->ddev.chancnt++;
return 0;
}
static void hidma_issue_task(unsigned long arg)
{
struct hidma_dev *dmadev = (struct hidma_dev *)arg;
pm_runtime_get_sync(dmadev->ddev.dev);
hidma_ll_start(dmadev->lldev);
}
static void hidma_issue_pending(struct dma_chan *dmach)
{
struct hidma_chan *mchan = to_hidma_chan(dmach);
struct hidma_dev *dmadev = mchan->dmadev;
unsigned long flags;
int status;
spin_lock_irqsave(&mchan->lock, flags);
if (!mchan->running) {
struct hidma_desc *desc = list_first_entry(&mchan->active,
struct hidma_desc,
node);
mchan->running = desc;
}
spin_unlock_irqrestore(&mchan->lock, flags);
status = pm_runtime_get(dmadev->ddev.dev);
if (status < 0)
tasklet_schedule(&dmadev->task);
else
hidma_ll_start(dmadev->lldev);
}
static enum dma_status hidma_tx_status(struct dma_chan *dmach,
dma_cookie_t cookie,
struct dma_tx_state *txstate)
{
struct hidma_chan *mchan = to_hidma_chan(dmach);
enum dma_status ret;
ret = dma_cookie_status(dmach, cookie, txstate);
if (ret == DMA_COMPLETE)
return ret;
if (mchan->paused && (ret == DMA_IN_PROGRESS)) {
unsigned long flags;
dma_cookie_t runcookie;
spin_lock_irqsave(&mchan->lock, flags);
if (mchan->running)
runcookie = mchan->running->desc.cookie;
else
runcookie = -EINVAL;
if (runcookie == cookie)
ret = DMA_PAUSED;
spin_unlock_irqrestore(&mchan->lock, flags);
}
return ret;
}
static dma_cookie_t hidma_tx_submit(struct dma_async_tx_descriptor *txd)
{
struct hidma_chan *mchan = to_hidma_chan(txd->chan);
struct hidma_dev *dmadev = mchan->dmadev;
struct hidma_desc *mdesc;
unsigned long irqflags;
dma_cookie_t cookie;
pm_runtime_get_sync(dmadev->ddev.dev);
if (!hidma_ll_isenabled(dmadev->lldev)) {
pm_runtime_mark_last_busy(dmadev->ddev.dev);
pm_runtime_put_autosuspend(dmadev->ddev.dev);
return -ENODEV;
}
mdesc = container_of(txd, struct hidma_desc, desc);
spin_lock_irqsave(&mchan->lock, irqflags);
list_move_tail(&mdesc->node, &mchan->active);
cookie = dma_cookie_assign(txd);
hidma_ll_queue_request(dmadev->lldev, mdesc->tre_ch);
spin_unlock_irqrestore(&mchan->lock, irqflags);
return cookie;
}
static int hidma_alloc_chan_resources(struct dma_chan *dmach)
{
struct hidma_chan *mchan = to_hidma_chan(dmach);
struct hidma_dev *dmadev = mchan->dmadev;
struct hidma_desc *mdesc, *tmp;
unsigned long irqflags;
LIST_HEAD(descs);
unsigned int i;
int rc = 0;
if (mchan->allocated)
return 0;
for (i = 0; i < dmadev->nr_descriptors; i++) {
mdesc = kzalloc(sizeof(struct hidma_desc), GFP_NOWAIT);
if (!mdesc) {
rc = -ENOMEM;
break;
}
dma_async_tx_descriptor_init(&mdesc->desc, dmach);
mdesc->desc.tx_submit = hidma_tx_submit;
rc = hidma_ll_request(dmadev->lldev, mchan->dma_sig,
"DMA engine", hidma_callback, mdesc,
&mdesc->tre_ch);
if (rc) {
dev_err(dmach->device->dev,
"channel alloc failed at %u\n", i);
kfree(mdesc);
break;
}
list_add_tail(&mdesc->node, &descs);
}
if (rc) {
list_for_each_entry_safe(mdesc, tmp, &descs, node) {
hidma_ll_free(dmadev->lldev, mdesc->tre_ch);
kfree(mdesc);
}
return rc;
}
spin_lock_irqsave(&mchan->lock, irqflags);
list_splice_tail_init(&descs, &mchan->free);
mchan->allocated = true;
spin_unlock_irqrestore(&mchan->lock, irqflags);
return 1;
}
static struct dma_async_tx_descriptor *
hidma_prep_dma_memcpy(struct dma_chan *dmach, dma_addr_t dest, dma_addr_t src,
size_t len, unsigned long flags)
{
struct hidma_chan *mchan = to_hidma_chan(dmach);
struct hidma_desc *mdesc = NULL;
struct hidma_dev *mdma = mchan->dmadev;
unsigned long irqflags;
spin_lock_irqsave(&mchan->lock, irqflags);
if (!list_empty(&mchan->free)) {
mdesc = list_first_entry(&mchan->free, struct hidma_desc, node);
list_del(&mdesc->node);
}
spin_unlock_irqrestore(&mchan->lock, irqflags);
if (!mdesc)
return NULL;
hidma_ll_set_transfer_params(mdma->lldev, mdesc->tre_ch,
src, dest, len, flags);
spin_lock_irqsave(&mchan->lock, irqflags);
list_add_tail(&mdesc->node, &mchan->prepared);
spin_unlock_irqrestore(&mchan->lock, irqflags);
return &mdesc->desc;
}
static int hidma_terminate_channel(struct dma_chan *chan)
{
struct hidma_chan *mchan = to_hidma_chan(chan);
struct hidma_dev *dmadev = to_hidma_dev(mchan->chan.device);
struct hidma_desc *tmp, *mdesc;
unsigned long irqflags;
LIST_HEAD(list);
int rc;
pm_runtime_get_sync(dmadev->ddev.dev);
hidma_process_completed(mchan);
spin_lock_irqsave(&mchan->lock, irqflags);
list_splice_init(&mchan->active, &list);
list_splice_init(&mchan->prepared, &list);
list_splice_init(&mchan->completed, &list);
spin_unlock_irqrestore(&mchan->lock, irqflags);
rc = hidma_ll_pause(dmadev->lldev);
if (rc) {
dev_err(dmadev->ddev.dev, "channel did not pause\n");
goto out;
}
list_for_each_entry_safe(mdesc, tmp, &list, node) {
struct dma_async_tx_descriptor *txd = &mdesc->desc;
dma_async_tx_callback callback = mdesc->desc.callback;
void *param = mdesc->desc.callback_param;
dma_descriptor_unmap(txd);
if (callback)
callback(param);
dma_run_dependencies(txd);
list_move(&mdesc->node, &mchan->free);
}
rc = hidma_ll_resume(dmadev->lldev);
out:
pm_runtime_mark_last_busy(dmadev->ddev.dev);
pm_runtime_put_autosuspend(dmadev->ddev.dev);
return rc;
}
static int hidma_terminate_all(struct dma_chan *chan)
{
struct hidma_chan *mchan = to_hidma_chan(chan);
struct hidma_dev *dmadev = to_hidma_dev(mchan->chan.device);
int rc;
rc = hidma_terminate_channel(chan);
if (rc)
return rc;
pm_runtime_get_sync(dmadev->ddev.dev);
rc = hidma_ll_setup(dmadev->lldev);
pm_runtime_mark_last_busy(dmadev->ddev.dev);
pm_runtime_put_autosuspend(dmadev->ddev.dev);
return rc;
}
static void hidma_free_chan_resources(struct dma_chan *dmach)
{
struct hidma_chan *mchan = to_hidma_chan(dmach);
struct hidma_dev *mdma = mchan->dmadev;
struct hidma_desc *mdesc, *tmp;
unsigned long irqflags;
LIST_HEAD(descs);
hidma_terminate_channel(dmach);
spin_lock_irqsave(&mchan->lock, irqflags);
list_splice_tail_init(&mchan->free, &descs);
list_for_each_entry_safe(mdesc, tmp, &descs, node) {
hidma_ll_free(mdma->lldev, mdesc->tre_ch);
list_del(&mdesc->node);
kfree(mdesc);
}
mchan->allocated = 0;
spin_unlock_irqrestore(&mchan->lock, irqflags);
}
static int hidma_pause(struct dma_chan *chan)
{
struct hidma_chan *mchan;
struct hidma_dev *dmadev;
mchan = to_hidma_chan(chan);
dmadev = to_hidma_dev(mchan->chan.device);
if (!mchan->paused) {
pm_runtime_get_sync(dmadev->ddev.dev);
if (hidma_ll_pause(dmadev->lldev))
dev_warn(dmadev->ddev.dev, "channel did not stop\n");
mchan->paused = true;
pm_runtime_mark_last_busy(dmadev->ddev.dev);
pm_runtime_put_autosuspend(dmadev->ddev.dev);
}
return 0;
}
static int hidma_resume(struct dma_chan *chan)
{
struct hidma_chan *mchan;
struct hidma_dev *dmadev;
int rc = 0;
mchan = to_hidma_chan(chan);
dmadev = to_hidma_dev(mchan->chan.device);
if (mchan->paused) {
pm_runtime_get_sync(dmadev->ddev.dev);
rc = hidma_ll_resume(dmadev->lldev);
if (!rc)
mchan->paused = false;
else
dev_err(dmadev->ddev.dev,
"failed to resume the channel");
pm_runtime_mark_last_busy(dmadev->ddev.dev);
pm_runtime_put_autosuspend(dmadev->ddev.dev);
}
return rc;
}
static irqreturn_t hidma_chirq_handler(int chirq, void *arg)
{
struct hidma_lldev *lldev = arg;
return hidma_ll_inthandler(chirq, lldev);
}
static int hidma_probe(struct platform_device *pdev)
{
struct hidma_dev *dmadev;
struct resource *trca_resource;
struct resource *evca_resource;
int chirq;
void __iomem *evca;
void __iomem *trca;
int rc;
pm_runtime_set_autosuspend_delay(&pdev->dev, HIDMA_AUTOSUSPEND_TIMEOUT);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
trca_resource = platform_get_resource(pdev, IORESOURCE_MEM, 0);
trca = devm_ioremap_resource(&pdev->dev, trca_resource);
if (IS_ERR(trca)) {
rc = -ENOMEM;
goto bailout;
}
evca_resource = platform_get_resource(pdev, IORESOURCE_MEM, 1);
evca = devm_ioremap_resource(&pdev->dev, evca_resource);
if (IS_ERR(evca)) {
rc = -ENOMEM;
goto bailout;
}
chirq = platform_get_irq(pdev, 0);
if (chirq < 0) {
rc = -ENODEV;
goto bailout;
}
dmadev = devm_kzalloc(&pdev->dev, sizeof(*dmadev), GFP_KERNEL);
if (!dmadev) {
rc = -ENOMEM;
goto bailout;
}
INIT_LIST_HEAD(&dmadev->ddev.channels);
spin_lock_init(&dmadev->lock);
dmadev->ddev.dev = &pdev->dev;
pm_runtime_get_sync(dmadev->ddev.dev);
dma_cap_set(DMA_MEMCPY, dmadev->ddev.cap_mask);
if (WARN_ON(!pdev->dev.dma_mask)) {
rc = -ENXIO;
goto dmafree;
}
dmadev->dev_evca = evca;
dmadev->evca_resource = evca_resource;
dmadev->dev_trca = trca;
dmadev->trca_resource = trca_resource;
dmadev->ddev.device_prep_dma_memcpy = hidma_prep_dma_memcpy;
dmadev->ddev.device_alloc_chan_resources = hidma_alloc_chan_resources;
dmadev->ddev.device_free_chan_resources = hidma_free_chan_resources;
dmadev->ddev.device_tx_status = hidma_tx_status;
dmadev->ddev.device_issue_pending = hidma_issue_pending;
dmadev->ddev.device_pause = hidma_pause;
dmadev->ddev.device_resume = hidma_resume;
dmadev->ddev.device_terminate_all = hidma_terminate_all;
dmadev->ddev.copy_align = 8;
device_property_read_u32(&pdev->dev, "desc-count",
&dmadev->nr_descriptors);
if (!dmadev->nr_descriptors && nr_desc_prm)
dmadev->nr_descriptors = nr_desc_prm;
if (!dmadev->nr_descriptors)
dmadev->nr_descriptors = HIDMA_NR_DEFAULT_DESC;
dmadev->chidx = readl(dmadev->dev_trca + 0x28);
rc = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64));
if (rc) {
dev_warn(&pdev->dev, "unable to set coherent mask to 64");
rc = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (rc)
goto dmafree;
}
dmadev->lldev = hidma_ll_init(dmadev->ddev.dev,
dmadev->nr_descriptors, dmadev->dev_trca,
dmadev->dev_evca, dmadev->chidx);
if (!dmadev->lldev) {
rc = -EPROBE_DEFER;
goto dmafree;
}
rc = devm_request_irq(&pdev->dev, chirq, hidma_chirq_handler, 0,
"qcom-hidma", dmadev->lldev);
if (rc)
goto uninit;
INIT_LIST_HEAD(&dmadev->ddev.channels);
rc = hidma_chan_init(dmadev, 0);
if (rc)
goto uninit;
rc = dma_async_device_register(&dmadev->ddev);
if (rc)
goto uninit;
dmadev->irq = chirq;
tasklet_init(&dmadev->task, hidma_issue_task, (unsigned long)dmadev);
dev_info(&pdev->dev, "HI-DMA engine driver registration complete\n");
platform_set_drvdata(pdev, dmadev);
pm_runtime_mark_last_busy(dmadev->ddev.dev);
pm_runtime_put_autosuspend(dmadev->ddev.dev);
return 0;
uninit:
hidma_ll_uninit(dmadev->lldev);
dmafree:
if (dmadev)
hidma_free(dmadev);
bailout:
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return rc;
}
static int hidma_remove(struct platform_device *pdev)
{
struct hidma_dev *dmadev = platform_get_drvdata(pdev);
pm_runtime_get_sync(dmadev->ddev.dev);
dma_async_device_unregister(&dmadev->ddev);
devm_free_irq(dmadev->ddev.dev, dmadev->irq, dmadev->lldev);
hidma_ll_uninit(dmadev->lldev);
hidma_free(dmadev);
dev_info(&pdev->dev, "HI-DMA engine removed\n");
pm_runtime_put_sync_suspend(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
