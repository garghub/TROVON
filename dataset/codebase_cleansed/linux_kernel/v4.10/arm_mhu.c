static irqreturn_t mhu_rx_interrupt(int irq, void *p)
{
struct mbox_chan *chan = p;
struct mhu_link *mlink = chan->con_priv;
u32 val;
val = readl_relaxed(mlink->rx_reg + INTR_STAT_OFS);
if (!val)
return IRQ_NONE;
mbox_chan_received_data(chan, (void *)&val);
writel_relaxed(val, mlink->rx_reg + INTR_CLR_OFS);
return IRQ_HANDLED;
}
static bool mhu_last_tx_done(struct mbox_chan *chan)
{
struct mhu_link *mlink = chan->con_priv;
u32 val = readl_relaxed(mlink->tx_reg + INTR_STAT_OFS);
return (val == 0);
}
static int mhu_send_data(struct mbox_chan *chan, void *data)
{
struct mhu_link *mlink = chan->con_priv;
u32 *arg = data;
writel_relaxed(*arg, mlink->tx_reg + INTR_SET_OFS);
return 0;
}
static int mhu_startup(struct mbox_chan *chan)
{
struct mhu_link *mlink = chan->con_priv;
u32 val;
int ret;
val = readl_relaxed(mlink->tx_reg + INTR_STAT_OFS);
writel_relaxed(val, mlink->tx_reg + INTR_CLR_OFS);
ret = request_irq(mlink->irq, mhu_rx_interrupt,
IRQF_SHARED, "mhu_link", chan);
if (ret) {
dev_err(chan->mbox->dev,
"Unable to acquire IRQ %d\n", mlink->irq);
return ret;
}
return 0;
}
static void mhu_shutdown(struct mbox_chan *chan)
{
struct mhu_link *mlink = chan->con_priv;
free_irq(mlink->irq, chan);
}
static int mhu_probe(struct amba_device *adev, const struct amba_id *id)
{
int i, err;
struct arm_mhu *mhu;
struct device *dev = &adev->dev;
int mhu_reg[MHU_CHANS] = {MHU_LP_OFFSET, MHU_HP_OFFSET, MHU_SEC_OFFSET};
mhu = devm_kzalloc(dev, sizeof(*mhu), GFP_KERNEL);
if (!mhu)
return -ENOMEM;
mhu->base = devm_ioremap_resource(dev, &adev->res);
if (IS_ERR(mhu->base)) {
dev_err(dev, "ioremap failed\n");
return PTR_ERR(mhu->base);
}
for (i = 0; i < MHU_CHANS; i++) {
mhu->chan[i].con_priv = &mhu->mlink[i];
mhu->mlink[i].irq = adev->irq[i];
mhu->mlink[i].rx_reg = mhu->base + mhu_reg[i];
mhu->mlink[i].tx_reg = mhu->mlink[i].rx_reg + TX_REG_OFFSET;
}
mhu->mbox.dev = dev;
mhu->mbox.chans = &mhu->chan[0];
mhu->mbox.num_chans = MHU_CHANS;
mhu->mbox.ops = &mhu_ops;
mhu->mbox.txdone_irq = false;
mhu->mbox.txdone_poll = true;
mhu->mbox.txpoll_period = 1;
amba_set_drvdata(adev, mhu);
err = mbox_controller_register(&mhu->mbox);
if (err) {
dev_err(dev, "Failed to register mailboxes %d\n", err);
return err;
}
dev_info(dev, "ARM MHU Mailbox registered\n");
return 0;
}
static int mhu_remove(struct amba_device *adev)
{
struct arm_mhu *mhu = amba_get_drvdata(adev);
mbox_controller_unregister(&mhu->mbox);
return 0;
}
