static int whcrc_cmd(struct uwb_rc *uwb_rc,
const struct uwb_rccb *cmd, size_t cmd_size)
{
int result = 0;
struct whcrc *whcrc = uwb_rc->priv;
struct device *dev = &whcrc->umc_dev->dev;
u32 urccmd;
if (cmd_size >= 4096)
return -EINVAL;
if (le_readl(whcrc->rc_base + URCSTS) & URCSTS_HALTED) {
dev_err(dev, "requesting reset of halted radio controller\n");
uwb_rc_reset_all(uwb_rc);
return -EIO;
}
result = wait_event_timeout(whcrc->cmd_wq,
!(le_readl(whcrc->rc_base + URCCMD) & URCCMD_ACTIVE), HZ/2);
if (result == 0) {
dev_err(dev, "device is not ready to execute commands\n");
return -ETIMEDOUT;
}
memmove(whcrc->cmd_buf, cmd, cmd_size);
le_writeq(whcrc->cmd_dma_buf, whcrc->rc_base + URCCMDADDR);
spin_lock(&whcrc->irq_lock);
urccmd = le_readl(whcrc->rc_base + URCCMD);
urccmd &= ~(URCCMD_EARV | URCCMD_SIZE_MASK);
le_writel(urccmd | URCCMD_ACTIVE | URCCMD_IWR | cmd_size,
whcrc->rc_base + URCCMD);
spin_unlock(&whcrc->irq_lock);
return 0;
}
static int whcrc_reset(struct uwb_rc *rc)
{
struct whcrc *whcrc = rc->priv;
return umc_controller_reset(whcrc->umc_dev);
}
static
void whcrc_enable_events(struct whcrc *whcrc)
{
u32 urccmd;
le_writeq(whcrc->evt_dma_buf, whcrc->rc_base + URCEVTADDR);
spin_lock(&whcrc->irq_lock);
urccmd = le_readl(whcrc->rc_base + URCCMD) & ~URCCMD_ACTIVE;
le_writel(urccmd | URCCMD_EARV, whcrc->rc_base + URCCMD);
spin_unlock(&whcrc->irq_lock);
}
static void whcrc_event_work(struct work_struct *work)
{
struct whcrc *whcrc = container_of(work, struct whcrc, event_work);
size_t size;
u64 urcevtaddr;
urcevtaddr = le_readq(whcrc->rc_base + URCEVTADDR);
size = urcevtaddr & URCEVTADDR_OFFSET_MASK;
uwb_rc_neh_grok(whcrc->uwb_rc, whcrc->evt_buf, size);
whcrc_enable_events(whcrc);
}
static
irqreturn_t whcrc_irq_cb(int irq, void *_whcrc)
{
struct whcrc *whcrc = _whcrc;
struct device *dev = &whcrc->umc_dev->dev;
u32 urcsts;
urcsts = le_readl(whcrc->rc_base + URCSTS);
if (!(urcsts & URCSTS_INT_MASK))
return IRQ_NONE;
le_writel(urcsts & URCSTS_INT_MASK, whcrc->rc_base + URCSTS);
if (urcsts & URCSTS_HSE) {
dev_err(dev, "host system error -- hardware halted\n");
goto out;
}
if (urcsts & URCSTS_ER)
schedule_work(&whcrc->event_work);
if (urcsts & URCSTS_RCI)
wake_up_all(&whcrc->cmd_wq);
out:
return IRQ_HANDLED;
}
static
int whcrc_setup_rc_umc(struct whcrc *whcrc)
{
int result = 0;
struct device *dev = &whcrc->umc_dev->dev;
struct umc_dev *umc_dev = whcrc->umc_dev;
whcrc->area = umc_dev->resource.start;
whcrc->rc_len = resource_size(&umc_dev->resource);
result = -EBUSY;
if (request_mem_region(whcrc->area, whcrc->rc_len, KBUILD_MODNAME) == NULL) {
dev_err(dev, "can't request URC region (%zu bytes @ 0x%lx): %d\n",
whcrc->rc_len, whcrc->area, result);
goto error_request_region;
}
whcrc->rc_base = ioremap_nocache(whcrc->area, whcrc->rc_len);
if (whcrc->rc_base == NULL) {
dev_err(dev, "can't ioremap registers (%zu bytes @ 0x%lx): %d\n",
whcrc->rc_len, whcrc->area, result);
goto error_ioremap_nocache;
}
result = request_irq(umc_dev->irq, whcrc_irq_cb, IRQF_SHARED,
KBUILD_MODNAME, whcrc);
if (result < 0) {
dev_err(dev, "can't allocate IRQ %d: %d\n",
umc_dev->irq, result);
goto error_request_irq;
}
result = -ENOMEM;
whcrc->cmd_buf = dma_alloc_coherent(&umc_dev->dev, PAGE_SIZE,
&whcrc->cmd_dma_buf, GFP_KERNEL);
if (whcrc->cmd_buf == NULL) {
dev_err(dev, "Can't allocate cmd transfer buffer\n");
goto error_cmd_buffer;
}
whcrc->evt_buf = dma_alloc_coherent(&umc_dev->dev, PAGE_SIZE,
&whcrc->evt_dma_buf, GFP_KERNEL);
if (whcrc->evt_buf == NULL) {
dev_err(dev, "Can't allocate evt transfer buffer\n");
goto error_evt_buffer;
}
return 0;
error_evt_buffer:
dma_free_coherent(&umc_dev->dev, PAGE_SIZE, whcrc->cmd_buf,
whcrc->cmd_dma_buf);
error_cmd_buffer:
free_irq(umc_dev->irq, whcrc);
error_request_irq:
iounmap(whcrc->rc_base);
error_ioremap_nocache:
release_mem_region(whcrc->area, whcrc->rc_len);
error_request_region:
return result;
}
static
void whcrc_release_rc_umc(struct whcrc *whcrc)
{
struct umc_dev *umc_dev = whcrc->umc_dev;
dma_free_coherent(&umc_dev->dev, PAGE_SIZE, whcrc->evt_buf,
whcrc->evt_dma_buf);
dma_free_coherent(&umc_dev->dev, PAGE_SIZE, whcrc->cmd_buf,
whcrc->cmd_dma_buf);
free_irq(umc_dev->irq, whcrc);
iounmap(whcrc->rc_base);
release_mem_region(whcrc->area, whcrc->rc_len);
}
static int whcrc_start_rc(struct uwb_rc *rc)
{
struct whcrc *whcrc = rc->priv;
struct device *dev = &whcrc->umc_dev->dev;
le_writel(URCCMD_RESET, whcrc->rc_base + URCCMD);
if (whci_wait_for(dev, whcrc->rc_base + URCCMD, URCCMD_RESET, 0,
5000, "hardware reset") < 0)
return -EBUSY;
le_writel(0, whcrc->rc_base + URCINTR);
le_writel(URCCMD_RS, whcrc->rc_base + URCCMD);
if (whci_wait_for(dev, whcrc->rc_base + URCSTS, URCSTS_HALTED, 0,
5000, "radio controller start") < 0)
return -ETIMEDOUT;
whcrc_enable_events(whcrc);
le_writel(URCINTR_EN_ALL, whcrc->rc_base + URCINTR);
return 0;
}
static
void whcrc_stop_rc(struct uwb_rc *rc)
{
struct whcrc *whcrc = rc->priv;
struct umc_dev *umc_dev = whcrc->umc_dev;
le_writel(0, whcrc->rc_base + URCINTR);
cancel_work_sync(&whcrc->event_work);
le_writel(0, whcrc->rc_base + URCCMD);
whci_wait_for(&umc_dev->dev, whcrc->rc_base + URCSTS,
URCSTS_HALTED, URCSTS_HALTED, 100, "radio controller stop");
}
static void whcrc_init(struct whcrc *whcrc)
{
spin_lock_init(&whcrc->irq_lock);
init_waitqueue_head(&whcrc->cmd_wq);
INIT_WORK(&whcrc->event_work, whcrc_event_work);
}
static
int whcrc_probe(struct umc_dev *umc_dev)
{
int result;
struct uwb_rc *uwb_rc;
struct whcrc *whcrc;
struct device *dev = &umc_dev->dev;
result = -ENOMEM;
uwb_rc = uwb_rc_alloc();
if (uwb_rc == NULL) {
dev_err(dev, "unable to allocate RC instance\n");
goto error_rc_alloc;
}
whcrc = kzalloc(sizeof(*whcrc), GFP_KERNEL);
if (whcrc == NULL) {
dev_err(dev, "unable to allocate WHC-RC instance\n");
goto error_alloc;
}
whcrc_init(whcrc);
whcrc->umc_dev = umc_dev;
result = whcrc_setup_rc_umc(whcrc);
if (result < 0) {
dev_err(dev, "Can't setup RC UMC interface: %d\n", result);
goto error_setup_rc_umc;
}
whcrc->uwb_rc = uwb_rc;
uwb_rc->owner = THIS_MODULE;
uwb_rc->cmd = whcrc_cmd;
uwb_rc->reset = whcrc_reset;
uwb_rc->start = whcrc_start_rc;
uwb_rc->stop = whcrc_stop_rc;
result = uwb_rc_add(uwb_rc, dev, whcrc);
if (result < 0)
goto error_rc_add;
umc_set_drvdata(umc_dev, whcrc);
return 0;
error_rc_add:
whcrc_release_rc_umc(whcrc);
error_setup_rc_umc:
kfree(whcrc);
error_alloc:
uwb_rc_put(uwb_rc);
error_rc_alloc:
return result;
}
static void whcrc_remove(struct umc_dev *umc_dev)
{
struct whcrc *whcrc = umc_get_drvdata(umc_dev);
struct uwb_rc *uwb_rc = whcrc->uwb_rc;
umc_set_drvdata(umc_dev, NULL);
uwb_rc_rm(uwb_rc);
whcrc_release_rc_umc(whcrc);
kfree(whcrc);
uwb_rc_put(uwb_rc);
}
static int whcrc_pre_reset(struct umc_dev *umc)
{
struct whcrc *whcrc = umc_get_drvdata(umc);
struct uwb_rc *uwb_rc = whcrc->uwb_rc;
uwb_rc_pre_reset(uwb_rc);
return 0;
}
static int whcrc_post_reset(struct umc_dev *umc)
{
struct whcrc *whcrc = umc_get_drvdata(umc);
struct uwb_rc *uwb_rc = whcrc->uwb_rc;
return uwb_rc_post_reset(uwb_rc);
}
static int __init whcrc_driver_init(void)
{
return umc_driver_register(&whcrc_driver);
}
static void __exit whcrc_driver_exit(void)
{
umc_driver_unregister(&whcrc_driver);
}
