static int tw68_hw_init1(struct tw68_dev *dev)
{
tw_writel(TW68_INTMASK, 0);
tw_writel(TW68_INTSTAT, 0xffffffff);
tw_writel(TW68_DMAC, 0x1600);
tw_writeb(TW68_ACNTL, 0x80);
msleep(100);
tw_writeb(TW68_INFORM, 0x40);
tw_writeb(TW68_OPFORM, 0x04);
tw_writeb(TW68_HSYNC, 0);
tw_writeb(TW68_ACNTL, 0x42);
tw_writeb(TW68_CROP_HI, 0x02);
tw_writeb(TW68_VDELAY_LO, 0x12);
tw_writeb(TW68_VACTIVE_LO, 0xf0);
tw_writeb(TW68_HDELAY_LO, 0x0f);
tw_writeb(TW68_HACTIVE_LO, 0xd0);
tw_writeb(TW68_CNTRL1, 0xcd);
tw_writeb(TW68_VSCALE_LO, 0);
tw_writeb(TW68_SCALE_HI, 0x11);
tw_writeb(TW68_HSCALE_LO, 0);
tw_writeb(TW68_BRIGHT, 0);
tw_writeb(TW68_CONTRAST, 0x5c);
tw_writeb(TW68_SHARPNESS, 0x51);
tw_writeb(TW68_SAT_U, 0x80);
tw_writeb(TW68_SAT_V, 0x80);
tw_writeb(TW68_HUE, 0x00);
tw_writeb(TW68_SHARP2, 0x53);
tw_writeb(TW68_VSHARP, 0x80);
tw_writeb(TW68_CORING, 0x44);
tw_writeb(TW68_CNTRL2, 0x00);
tw_writeb(TW68_SDT, 0x07);
tw_writeb(TW68_SDTR, 0x7f);
tw_writeb(TW68_CLMPG, 0x50);
tw_writeb(TW68_IAGC, 0x22);
tw_writeb(TW68_AGCGAIN, 0xf0);
tw_writeb(TW68_PEAKWT, 0xd8);
tw_writeb(TW68_CLMPL, 0x3c);
tw_writeb(TW68_SYNCT, 0x30);
tw_writeb(TW68_MISSCNT, 0x44);
tw_writeb(TW68_PCLAMP, 0x28);
tw_writeb(TW68_VCNTL1, 0x04);
tw_writeb(TW68_VCNTL2, 0);
tw_writeb(TW68_CKILL, 0x68);
tw_writeb(TW68_COMB, 0x44);
tw_writeb(TW68_LDLY, 0x30);
tw_writeb(TW68_MISC1, 0x14);
tw_writeb(TW68_LOOP, 0xa5);
tw_writeb(TW68_MISC2, 0xe0);
tw_writeb(TW68_MVSN, 0);
tw_writeb(TW68_CLMD, 0x05);
tw_writeb(TW68_IDCNTL, 0);
tw_writeb(TW68_CLCNTL1, 0);
tw_writel(TW68_VBIC, 0x03);
tw_writel(TW68_CAP_CTL, 0x03);
tw_writel(TW68_DMAC, 0x2000);
tw_writel(TW68_TESTREG, 0);
tw_writel(TW68_GPIOC, 0);
tw_writel(TW68_GPOE, 0x0f);
tw_writel(TW68_GPDATA, 0);
mutex_init(&dev->lock);
spin_lock_init(&dev->slock);
tw68_video_init1(dev);
return 0;
}
static irqreturn_t tw68_irq(int irq, void *dev_id)
{
struct tw68_dev *dev = dev_id;
u32 status, orig;
int loop;
status = orig = tw_readl(TW68_INTSTAT) & dev->pci_irqmask;
if (0 == status)
return IRQ_NONE;
for (loop = 0; loop < 10; loop++) {
if (status & dev->board_virqmask)
tw68_irq_video_done(dev, status);
status = tw_readl(TW68_INTSTAT) & dev->pci_irqmask;
if (0 == status)
return IRQ_HANDLED;
}
dev_dbg(&dev->pci->dev, "%s: **** INTERRUPT NOT HANDLED - clearing mask (orig 0x%08x, cur 0x%08x)",
dev->name, orig, tw_readl(TW68_INTSTAT));
dev_dbg(&dev->pci->dev, "%s: pci_irqmask 0x%08x; board_virqmask 0x%08x ****\n",
dev->name, dev->pci_irqmask, dev->board_virqmask);
tw_clearl(TW68_INTMASK, dev->pci_irqmask);
return IRQ_HANDLED;
}
static int tw68_initdev(struct pci_dev *pci_dev,
const struct pci_device_id *pci_id)
{
struct tw68_dev *dev;
int vidnr = -1;
int err;
dev = devm_kzalloc(&pci_dev->dev, sizeof(*dev), GFP_KERNEL);
if (NULL == dev)
return -ENOMEM;
dev->instance = v4l2_device_set_name(&dev->v4l2_dev, "tw68",
&tw68_instance);
err = v4l2_device_register(&pci_dev->dev, &dev->v4l2_dev);
if (err)
return err;
dev->pci = pci_dev;
if (pci_enable_device(pci_dev)) {
err = -EIO;
goto fail1;
}
dev->name = dev->v4l2_dev.name;
if (UNSET != latency) {
pr_info("%s: setting pci latency timer to %d\n",
dev->name, latency);
pci_write_config_byte(pci_dev, PCI_LATENCY_TIMER, latency);
}
pci_read_config_byte(pci_dev, PCI_CLASS_REVISION, &dev->pci_rev);
pci_read_config_byte(pci_dev, PCI_LATENCY_TIMER, &dev->pci_lat);
pr_info("%s: found at %s, rev: %d, irq: %d, latency: %d, mmio: 0x%llx\n",
dev->name, pci_name(pci_dev), dev->pci_rev, pci_dev->irq,
dev->pci_lat, (u64)pci_resource_start(pci_dev, 0));
pci_set_master(pci_dev);
err = pci_set_dma_mask(pci_dev, DMA_BIT_MASK(32));
if (err) {
pr_info("%s: Oops: no 32bit PCI DMA ???\n", dev->name);
goto fail1;
}
switch (pci_id->device) {
case PCI_DEVICE_ID_TECHWELL_6800:
dev->vdecoder = TW6800;
dev->board_virqmask = TW68_VID_INTS;
break;
case PCI_DEVICE_ID_TECHWELL_6801:
dev->vdecoder = TW6801;
dev->board_virqmask = TW68_VID_INTS | TW68_VID_INTSX;
break;
case PCI_DEVICE_ID_TECHWELL_6804:
dev->vdecoder = TW6804;
dev->board_virqmask = TW68_VID_INTS | TW68_VID_INTSX;
break;
default:
dev->vdecoder = TWXXXX;
dev->board_virqmask = TW68_VID_INTS | TW68_VID_INTSX;
break;
}
if (!request_mem_region(pci_resource_start(pci_dev, 0),
pci_resource_len(pci_dev, 0),
dev->name)) {
err = -EBUSY;
pr_err("%s: can't get MMIO memory @ 0x%llx\n",
dev->name,
(unsigned long long)pci_resource_start(pci_dev, 0));
goto fail1;
}
dev->lmmio = ioremap(pci_resource_start(pci_dev, 0),
pci_resource_len(pci_dev, 0));
dev->bmmio = (__u8 __iomem *)dev->lmmio;
if (NULL == dev->lmmio) {
err = -EIO;
pr_err("%s: can't ioremap() MMIO memory\n",
dev->name);
goto fail2;
}
tw68_hw_init1(dev);
dev->alloc_ctx = vb2_dma_sg_init_ctx(&pci_dev->dev);
if (IS_ERR(dev->alloc_ctx)) {
err = PTR_ERR(dev->alloc_ctx);
goto fail3;
}
err = devm_request_irq(&pci_dev->dev, pci_dev->irq, tw68_irq,
IRQF_SHARED, dev->name, dev);
if (err < 0) {
pr_err("%s: can't get IRQ %d\n",
dev->name, pci_dev->irq);
goto fail4;
}
if (dev->instance < TW68_MAXBOARDS)
vidnr = video_nr[dev->instance];
err = tw68_video_init2(dev, vidnr);
if (err < 0) {
pr_err("%s: can't register video device\n",
dev->name);
goto fail5;
}
tw_setl(TW68_INTMASK, dev->pci_irqmask);
pr_info("%s: registered device %s\n",
dev->name, video_device_node_name(&dev->vdev));
return 0;
fail5:
video_unregister_device(&dev->vdev);
fail4:
vb2_dma_sg_cleanup_ctx(dev->alloc_ctx);
fail3:
iounmap(dev->lmmio);
fail2:
release_mem_region(pci_resource_start(pci_dev, 0),
pci_resource_len(pci_dev, 0));
fail1:
v4l2_device_unregister(&dev->v4l2_dev);
return err;
}
static void tw68_finidev(struct pci_dev *pci_dev)
{
struct v4l2_device *v4l2_dev = pci_get_drvdata(pci_dev);
struct tw68_dev *dev =
container_of(v4l2_dev, struct tw68_dev, v4l2_dev);
tw_clearl(TW68_DMAC, TW68_DMAP_EN | TW68_FIFO_EN);
tw_writel(TW68_INTMASK, 0);
video_unregister_device(&dev->vdev);
v4l2_ctrl_handler_free(&dev->hdl);
vb2_dma_sg_cleanup_ctx(dev->alloc_ctx);
iounmap(dev->lmmio);
release_mem_region(pci_resource_start(pci_dev, 0),
pci_resource_len(pci_dev, 0));
v4l2_device_unregister(&dev->v4l2_dev);
}
static int tw68_suspend(struct pci_dev *pci_dev , pm_message_t state)
{
struct v4l2_device *v4l2_dev = pci_get_drvdata(pci_dev);
struct tw68_dev *dev = container_of(v4l2_dev,
struct tw68_dev, v4l2_dev);
tw_clearl(TW68_DMAC, TW68_DMAP_EN | TW68_FIFO_EN);
dev->pci_irqmask &= ~TW68_VID_INTS;
tw_writel(TW68_INTMASK, 0);
synchronize_irq(pci_dev->irq);
pci_save_state(pci_dev);
pci_set_power_state(pci_dev, pci_choose_state(pci_dev, state));
vb2_discard_done(&dev->vidq);
return 0;
}
static int tw68_resume(struct pci_dev *pci_dev)
{
struct v4l2_device *v4l2_dev = pci_get_drvdata(pci_dev);
struct tw68_dev *dev = container_of(v4l2_dev,
struct tw68_dev, v4l2_dev);
struct tw68_buf *buf;
unsigned long flags;
pci_set_power_state(pci_dev, PCI_D0);
pci_restore_state(pci_dev);
msleep(100);
tw68_set_tvnorm_hw(dev);
spin_lock_irqsave(&dev->slock, flags);
buf = container_of(dev->active.next, struct tw68_buf, list);
tw68_video_start_dma(dev, buf);
spin_unlock_irqrestore(&dev->slock, flags);
return 0;
}
