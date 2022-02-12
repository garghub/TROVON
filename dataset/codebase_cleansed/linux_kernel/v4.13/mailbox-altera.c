static struct altera_mbox *mbox_chan_to_altera_mbox(struct mbox_chan *chan)
{
if (!chan || !chan->con_priv)
return NULL;
return (struct altera_mbox *)chan->con_priv;
}
static inline int altera_mbox_full(struct altera_mbox *mbox)
{
u32 status;
status = readl_relaxed(mbox->mbox_base + MAILBOX_STS_REG);
return MBOX_FULL(status);
}
static inline int altera_mbox_pending(struct altera_mbox *mbox)
{
u32 status;
status = readl_relaxed(mbox->mbox_base + MAILBOX_STS_REG);
return MBOX_PENDING(status);
}
static void altera_mbox_rx_intmask(struct altera_mbox *mbox, bool enable)
{
u32 mask;
mask = readl_relaxed(mbox->mbox_base + MAILBOX_INTMASK_REG);
if (enable)
mask |= INT_PENDING_MSK;
else
mask &= ~INT_PENDING_MSK;
writel_relaxed(mask, mbox->mbox_base + MAILBOX_INTMASK_REG);
}
static void altera_mbox_tx_intmask(struct altera_mbox *mbox, bool enable)
{
u32 mask;
mask = readl_relaxed(mbox->mbox_base + MAILBOX_INTMASK_REG);
if (enable)
mask |= INT_SPACE_MSK;
else
mask &= ~INT_SPACE_MSK;
writel_relaxed(mask, mbox->mbox_base + MAILBOX_INTMASK_REG);
}
static bool altera_mbox_is_sender(struct altera_mbox *mbox)
{
u32 reg;
#define MBOX_MAGIC 0xA5A5AA55
writel_relaxed(MBOX_MAGIC, mbox->mbox_base + MAILBOX_PTR_REG);
reg = readl_relaxed(mbox->mbox_base + MAILBOX_PTR_REG);
if (reg == MBOX_MAGIC) {
writel_relaxed(0, mbox->mbox_base + MAILBOX_PTR_REG);
return true;
}
return false;
}
static void altera_mbox_rx_data(struct mbox_chan *chan)
{
struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);
u32 data[2];
if (altera_mbox_pending(mbox)) {
data[MBOX_PTR] =
readl_relaxed(mbox->mbox_base + MAILBOX_PTR_REG);
data[MBOX_CMD] =
readl_relaxed(mbox->mbox_base + MAILBOX_CMD_REG);
mbox_chan_received_data(chan, (void *)data);
}
}
static void altera_mbox_poll_rx(unsigned long data)
{
struct mbox_chan *chan = (struct mbox_chan *)data;
struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);
altera_mbox_rx_data(chan);
mod_timer(&mbox->rxpoll_timer,
jiffies + msecs_to_jiffies(MBOX_POLLING_MS));
}
static irqreturn_t altera_mbox_tx_interrupt(int irq, void *p)
{
struct mbox_chan *chan = (struct mbox_chan *)p;
struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);
altera_mbox_tx_intmask(mbox, false);
mbox_chan_txdone(chan, 0);
return IRQ_HANDLED;
}
static irqreturn_t altera_mbox_rx_interrupt(int irq, void *p)
{
struct mbox_chan *chan = (struct mbox_chan *)p;
altera_mbox_rx_data(chan);
return IRQ_HANDLED;
}
static int altera_mbox_startup_sender(struct mbox_chan *chan)
{
int ret;
struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);
if (mbox->intr_mode) {
ret = request_irq(mbox->irq, altera_mbox_tx_interrupt, 0,
DRIVER_NAME, chan);
if (unlikely(ret)) {
dev_err(mbox->dev,
"failed to register mailbox interrupt:%d\n",
ret);
return ret;
}
}
return 0;
}
static int altera_mbox_startup_receiver(struct mbox_chan *chan)
{
int ret;
struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);
if (mbox->intr_mode) {
ret = request_irq(mbox->irq, altera_mbox_rx_interrupt, 0,
DRIVER_NAME, chan);
if (unlikely(ret)) {
mbox->intr_mode = false;
goto polling;
}
altera_mbox_rx_intmask(mbox, true);
return 0;
}
polling:
setup_timer(&mbox->rxpoll_timer, altera_mbox_poll_rx,
(unsigned long)chan);
mod_timer(&mbox->rxpoll_timer,
jiffies + msecs_to_jiffies(MBOX_POLLING_MS));
return 0;
}
static int altera_mbox_send_data(struct mbox_chan *chan, void *data)
{
struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);
u32 *udata = (u32 *)data;
if (!mbox || !data)
return -EINVAL;
if (!mbox->is_sender) {
dev_warn(mbox->dev,
"failed to send. This is receiver mailbox.\n");
return -EINVAL;
}
if (altera_mbox_full(mbox))
return -EBUSY;
if (mbox->intr_mode)
altera_mbox_tx_intmask(mbox, true);
writel_relaxed(udata[MBOX_PTR], mbox->mbox_base + MAILBOX_PTR_REG);
writel_relaxed(udata[MBOX_CMD], mbox->mbox_base + MAILBOX_CMD_REG);
return 0;
}
static bool altera_mbox_last_tx_done(struct mbox_chan *chan)
{
struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);
return altera_mbox_full(mbox) ? false : true;
}
static bool altera_mbox_peek_data(struct mbox_chan *chan)
{
struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);
return altera_mbox_pending(mbox) ? true : false;
}
static int altera_mbox_startup(struct mbox_chan *chan)
{
struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);
int ret = 0;
if (!mbox)
return -EINVAL;
if (mbox->is_sender)
ret = altera_mbox_startup_sender(chan);
else
ret = altera_mbox_startup_receiver(chan);
return ret;
}
static void altera_mbox_shutdown(struct mbox_chan *chan)
{
struct altera_mbox *mbox = mbox_chan_to_altera_mbox(chan);
if (mbox->intr_mode) {
writel_relaxed(~0, mbox->mbox_base + MAILBOX_INTMASK_REG);
free_irq(mbox->irq, chan);
} else if (!mbox->is_sender) {
del_timer_sync(&mbox->rxpoll_timer);
}
}
static int altera_mbox_probe(struct platform_device *pdev)
{
struct altera_mbox *mbox;
struct resource *regs;
struct mbox_chan *chans;
int ret;
mbox = devm_kzalloc(&pdev->dev, sizeof(*mbox),
GFP_KERNEL);
if (!mbox)
return -ENOMEM;
chans = devm_kzalloc(&pdev->dev, sizeof(*chans), GFP_KERNEL);
if (!chans)
return -ENOMEM;
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mbox->mbox_base = devm_ioremap_resource(&pdev->dev, regs);
if (IS_ERR(mbox->mbox_base))
return PTR_ERR(mbox->mbox_base);
mbox->is_sender = altera_mbox_is_sender(mbox);
mbox->irq = platform_get_irq(pdev, 0);
if (mbox->irq >= 0)
mbox->intr_mode = true;
mbox->dev = &pdev->dev;
chans[0].con_priv = mbox;
mbox->controller.dev = mbox->dev;
mbox->controller.num_chans = 1;
mbox->controller.chans = chans;
mbox->controller.ops = &altera_mbox_ops;
if (mbox->is_sender) {
if (mbox->intr_mode) {
mbox->controller.txdone_irq = true;
} else {
mbox->controller.txdone_poll = true;
mbox->controller.txpoll_period = MBOX_POLLING_MS;
}
}
ret = mbox_controller_register(&mbox->controller);
if (ret) {
dev_err(&pdev->dev, "Register mailbox failed\n");
goto err;
}
platform_set_drvdata(pdev, mbox);
err:
return ret;
}
static int altera_mbox_remove(struct platform_device *pdev)
{
struct altera_mbox *mbox = platform_get_drvdata(pdev);
if (!mbox)
return -EINVAL;
mbox_controller_unregister(&mbox->controller);
return 0;
}
