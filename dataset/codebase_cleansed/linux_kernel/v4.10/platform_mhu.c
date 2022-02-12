static irqreturn_t platform_mhu_rx_interrupt(int irq, void *p)
{
struct mbox_chan *chan = p;
struct platform_mhu_link *mlink = chan->con_priv;
u32 val;
val = readl_relaxed(mlink->rx_reg + INTR_STAT_OFS);
if (!val)
return IRQ_NONE;
mbox_chan_received_data(chan, (void *)&val);
writel_relaxed(val, mlink->rx_reg + INTR_CLR_OFS);
return IRQ_HANDLED;
}
static bool platform_mhu_last_tx_done(struct mbox_chan *chan)
{
struct platform_mhu_link *mlink = chan->con_priv;
u32 val = readl_relaxed(mlink->tx_reg + INTR_STAT_OFS);
return (val == 0);
}
static int platform_mhu_send_data(struct mbox_chan *chan, void *data)
{
struct platform_mhu_link *mlink = chan->con_priv;
u32 *arg = data;
writel_relaxed(*arg, mlink->tx_reg + INTR_SET_OFS);
return 0;
}
static int platform_mhu_startup(struct mbox_chan *chan)
{
struct platform_mhu_link *mlink = chan->con_priv;
u32 val;
int ret;
val = readl_relaxed(mlink->tx_reg + INTR_STAT_OFS);
writel_relaxed(val, mlink->tx_reg + INTR_CLR_OFS);
ret = request_irq(mlink->irq, platform_mhu_rx_interrupt,
IRQF_SHARED, "platform_mhu_link", chan);
if (ret) {
dev_err(chan->mbox->dev,
"Unable to acquire IRQ %d\n", mlink->irq);
return ret;
}
return 0;
}
static void platform_mhu_shutdown(struct mbox_chan *chan)
{
struct platform_mhu_link *mlink = chan->con_priv;
free_irq(mlink->irq, chan);
}
static int platform_mhu_probe(struct platform_device *pdev)
{
int i, err;
struct platform_mhu *mhu;
struct device *dev = &pdev->dev;
struct resource *res;
int platform_mhu_reg[MHU_CHANS] = {
MHU_SEC_OFFSET, MHU_LP_OFFSET, MHU_HP_OFFSET
};
mhu = devm_kzalloc(dev, sizeof(*mhu), GFP_KERNEL);
if (!mhu)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mhu->base = devm_ioremap_resource(dev, res);
if (IS_ERR(mhu->base)) {
dev_err(dev, "ioremap failed\n");
return PTR_ERR(mhu->base);
}
for (i = 0; i < MHU_CHANS; i++) {
mhu->chan[i].con_priv = &mhu->mlink[i];
mhu->mlink[i].irq = platform_get_irq(pdev, i);
if (mhu->mlink[i].irq < 0) {
dev_err(dev, "failed to get irq%d\n", i);
return mhu->mlink[i].irq;
}
mhu->mlink[i].rx_reg = mhu->base + platform_mhu_reg[i];
mhu->mlink[i].tx_reg = mhu->mlink[i].rx_reg + TX_REG_OFFSET;
}
mhu->mbox.dev = dev;
mhu->mbox.chans = &mhu->chan[0];
mhu->mbox.num_chans = MHU_CHANS;
mhu->mbox.ops = &platform_mhu_ops;
mhu->mbox.txdone_irq = false;
mhu->mbox.txdone_poll = true;
mhu->mbox.txpoll_period = 1;
platform_set_drvdata(pdev, mhu);
err = mbox_controller_register(&mhu->mbox);
if (err) {
dev_err(dev, "Failed to register mailboxes %d\n", err);
return err;
}
dev_info(dev, "Platform MHU Mailbox registered\n");
return 0;
}
static int platform_mhu_remove(struct platform_device *pdev)
{
struct platform_mhu *mhu = platform_get_drvdata(pdev);
mbox_controller_unregister(&mhu->mbox);
return 0;
}
