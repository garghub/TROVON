bool _cxl_pci_associate_default_context(struct pci_dev *dev, struct cxl_afu *afu)
{
struct cxl_context *ctx;
ctx = cxl_dev_context_init(dev);
if (IS_ERR(ctx))
return false;
dev->dev.archdata.cxl_ctx = ctx;
return (cxl_ops->afu_check_and_enable(afu) == 0);
}
void _cxl_pci_disable_device(struct pci_dev *dev)
{
struct cxl_context *ctx = cxl_get_context(dev);
if (ctx) {
if (ctx->status == STARTED) {
dev_err(&dev->dev, "Default context started\n");
return;
}
dev->dev.archdata.cxl_ctx = NULL;
cxl_release_context(ctx);
}
}
