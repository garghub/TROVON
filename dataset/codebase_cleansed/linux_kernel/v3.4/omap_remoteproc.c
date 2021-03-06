static int omap_rproc_mbox_callback(struct notifier_block *this,
unsigned long index, void *data)
{
mbox_msg_t msg = (mbox_msg_t) data;
struct omap_rproc *oproc = container_of(this, struct omap_rproc, nb);
struct device *dev = oproc->rproc->dev;
const char *name = oproc->rproc->name;
dev_dbg(dev, "mbox msg: 0x%x\n", msg);
switch (msg) {
case RP_MBOX_CRASH:
dev_err(dev, "omap rproc %s crashed\n", name);
break;
case RP_MBOX_ECHO_REPLY:
dev_info(dev, "received echo reply from %s\n", name);
break;
default:
if (rproc_vq_interrupt(oproc->rproc, msg) == IRQ_NONE)
dev_dbg(dev, "no message was found in vqid %d\n", msg);
}
return NOTIFY_DONE;
}
static void omap_rproc_kick(struct rproc *rproc, int vqid)
{
struct omap_rproc *oproc = rproc->priv;
int ret;
ret = omap_mbox_msg_send(oproc->mbox, vqid);
if (ret)
dev_err(rproc->dev, "omap_mbox_msg_send failed: %d\n", ret);
}
static int omap_rproc_start(struct rproc *rproc)
{
struct omap_rproc *oproc = rproc->priv;
struct platform_device *pdev = to_platform_device(rproc->dev);
struct omap_rproc_pdata *pdata = pdev->dev.platform_data;
int ret;
oproc->nb.notifier_call = omap_rproc_mbox_callback;
oproc->mbox = omap_mbox_get(pdata->mbox_name, &oproc->nb);
if (IS_ERR(oproc->mbox)) {
ret = PTR_ERR(oproc->mbox);
dev_err(rproc->dev, "omap_mbox_get failed: %d\n", ret);
return ret;
}
ret = omap_mbox_msg_send(oproc->mbox, RP_MBOX_ECHO_REQUEST);
if (ret) {
dev_err(rproc->dev, "omap_mbox_get failed: %d\n", ret);
goto put_mbox;
}
ret = pdata->device_enable(pdev);
if (ret) {
dev_err(rproc->dev, "omap_device_enable failed: %d\n", ret);
goto put_mbox;
}
return 0;
put_mbox:
omap_mbox_put(oproc->mbox, &oproc->nb);
return ret;
}
static int omap_rproc_stop(struct rproc *rproc)
{
struct platform_device *pdev = to_platform_device(rproc->dev);
struct omap_rproc_pdata *pdata = pdev->dev.platform_data;
struct omap_rproc *oproc = rproc->priv;
int ret;
ret = pdata->device_shutdown(pdev);
if (ret)
return ret;
omap_mbox_put(oproc->mbox, &oproc->nb);
return 0;
}
static int __devinit omap_rproc_probe(struct platform_device *pdev)
{
struct omap_rproc_pdata *pdata = pdev->dev.platform_data;
struct omap_rproc *oproc;
struct rproc *rproc;
int ret;
ret = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
if (ret) {
dev_err(pdev->dev.parent, "dma_set_coherent_mask: %d\n", ret);
return ret;
}
rproc = rproc_alloc(&pdev->dev, pdata->name, &omap_rproc_ops,
pdata->firmware, sizeof(*oproc));
if (!rproc)
return -ENOMEM;
oproc = rproc->priv;
oproc->rproc = rproc;
platform_set_drvdata(pdev, rproc);
ret = rproc_register(rproc);
if (ret)
goto free_rproc;
return 0;
free_rproc:
rproc_free(rproc);
return ret;
}
static int __devexit omap_rproc_remove(struct platform_device *pdev)
{
struct rproc *rproc = platform_get_drvdata(pdev);
return rproc_unregister(rproc);
}
