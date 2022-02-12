static struct bcm2835_mbox *bcm2835_link_mbox(struct mbox_chan *link)
{
return container_of(link->mbox, struct bcm2835_mbox, controller);
}
static irqreturn_t bcm2835_mbox_irq(int irq, void *dev_id)
{
struct bcm2835_mbox *mbox = dev_id;
struct device *dev = mbox->controller.dev;
struct mbox_chan *link = &mbox->controller.chans[0];
while (!(readl(mbox->regs + MAIL0_STA) & ARM_MS_EMPTY)) {
u32 msg = readl(mbox->regs + MAIL0_RD);
dev_dbg(dev, "Reply 0x%08X\n", msg);
mbox_chan_received_data(link, &msg);
}
return IRQ_HANDLED;
}
static int bcm2835_send_data(struct mbox_chan *link, void *data)
{
struct bcm2835_mbox *mbox = bcm2835_link_mbox(link);
u32 msg = *(u32 *)data;
spin_lock(&mbox->lock);
writel(msg, mbox->regs + MAIL1_WRT);
dev_dbg(mbox->controller.dev, "Request 0x%08X\n", msg);
spin_unlock(&mbox->lock);
return 0;
}
static int bcm2835_startup(struct mbox_chan *link)
{
struct bcm2835_mbox *mbox = bcm2835_link_mbox(link);
writel(ARM_MC_IHAVEDATAIRQEN, mbox->regs + MAIL0_CNF);
return 0;
}
static void bcm2835_shutdown(struct mbox_chan *link)
{
struct bcm2835_mbox *mbox = bcm2835_link_mbox(link);
writel(0, mbox->regs + MAIL0_CNF);
}
static bool bcm2835_last_tx_done(struct mbox_chan *link)
{
struct bcm2835_mbox *mbox = bcm2835_link_mbox(link);
bool ret;
spin_lock(&mbox->lock);
ret = !(readl(mbox->regs + MAIL1_STA) & ARM_MS_FULL);
spin_unlock(&mbox->lock);
return ret;
}
static struct mbox_chan *bcm2835_mbox_index_xlate(struct mbox_controller *mbox,
const struct of_phandle_args *sp)
{
if (sp->args_count != 0)
return NULL;
return &mbox->chans[0];
}
static int bcm2835_mbox_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
int ret = 0;
struct resource *iomem;
struct bcm2835_mbox *mbox;
mbox = devm_kzalloc(dev, sizeof(*mbox), GFP_KERNEL);
if (mbox == NULL)
return -ENOMEM;
spin_lock_init(&mbox->lock);
ret = devm_request_irq(dev, irq_of_parse_and_map(dev->of_node, 0),
bcm2835_mbox_irq, 0, dev_name(dev), mbox);
if (ret) {
dev_err(dev, "Failed to register a mailbox IRQ handler: %d\n",
ret);
return -ENODEV;
}
iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mbox->regs = devm_ioremap_resource(&pdev->dev, iomem);
if (IS_ERR(mbox->regs)) {
ret = PTR_ERR(mbox->regs);
dev_err(&pdev->dev, "Failed to remap mailbox regs: %d\n", ret);
return ret;
}
mbox->controller.txdone_poll = true;
mbox->controller.txpoll_period = 5;
mbox->controller.ops = &bcm2835_mbox_chan_ops;
mbox->controller.of_xlate = &bcm2835_mbox_index_xlate;
mbox->controller.dev = dev;
mbox->controller.num_chans = 1;
mbox->controller.chans = devm_kzalloc(dev,
sizeof(*mbox->controller.chans), GFP_KERNEL);
if (!mbox->controller.chans)
return -ENOMEM;
ret = mbox_controller_register(&mbox->controller);
if (ret)
return ret;
platform_set_drvdata(pdev, mbox);
dev_info(dev, "mailbox enabled\n");
return ret;
}
static int bcm2835_mbox_remove(struct platform_device *pdev)
{
struct bcm2835_mbox *mbox = platform_get_drvdata(pdev);
mbox_controller_unregister(&mbox->controller);
return 0;
}
