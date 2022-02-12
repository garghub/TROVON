static inline bool sti_mbox_channel_is_enabled(struct mbox_chan *chan)
{
struct sti_channel *chan_info = chan->con_priv;
struct sti_mbox_device *mdev = chan_info->mdev;
unsigned int instance = chan_info->instance;
unsigned int channel = chan_info->channel;
return mdev->enabled[instance] & BIT(channel);
}
static inline
struct mbox_chan *sti_mbox_to_channel(struct mbox_controller *mbox,
unsigned int instance,
unsigned int channel)
{
struct sti_channel *chan_info;
int i;
for (i = 0; i < mbox->num_chans; i++) {
chan_info = mbox->chans[i].con_priv;
if (chan_info &&
chan_info->instance == instance &&
chan_info->channel == channel)
return &mbox->chans[i];
}
dev_err(mbox->dev,
"Channel not registered: instance: %d channel: %d\n",
instance, channel);
return NULL;
}
static void sti_mbox_enable_channel(struct mbox_chan *chan)
{
struct sti_channel *chan_info = chan->con_priv;
struct sti_mbox_device *mdev = chan_info->mdev;
unsigned int instance = chan_info->instance;
unsigned int channel = chan_info->channel;
unsigned long flags;
void __iomem *base = MBOX_BASE(mdev, instance);
spin_lock_irqsave(&mdev->lock, flags);
mdev->enabled[instance] |= BIT(channel);
writel_relaxed(BIT(channel), base + STI_ENA_SET_OFFSET);
spin_unlock_irqrestore(&mdev->lock, flags);
}
static void sti_mbox_disable_channel(struct mbox_chan *chan)
{
struct sti_channel *chan_info = chan->con_priv;
struct sti_mbox_device *mdev = chan_info->mdev;
unsigned int instance = chan_info->instance;
unsigned int channel = chan_info->channel;
unsigned long flags;
void __iomem *base = MBOX_BASE(mdev, instance);
spin_lock_irqsave(&mdev->lock, flags);
mdev->enabled[instance] &= ~BIT(channel);
writel_relaxed(BIT(channel), base + STI_ENA_CLR_OFFSET);
spin_unlock_irqrestore(&mdev->lock, flags);
}
static void sti_mbox_clear_irq(struct mbox_chan *chan)
{
struct sti_channel *chan_info = chan->con_priv;
struct sti_mbox_device *mdev = chan_info->mdev;
unsigned int instance = chan_info->instance;
unsigned int channel = chan_info->channel;
void __iomem *base = MBOX_BASE(mdev, instance);
writel_relaxed(BIT(channel), base + STI_IRQ_CLR_OFFSET);
}
static struct mbox_chan *sti_mbox_irq_to_channel(struct sti_mbox_device *mdev,
unsigned int instance)
{
struct mbox_controller *mbox = mdev->mbox;
struct mbox_chan *chan = NULL;
unsigned int channel;
unsigned long bits;
void __iomem *base = MBOX_BASE(mdev, instance);
bits = readl_relaxed(base + STI_IRQ_VAL_OFFSET);
if (!bits)
return NULL;
for (channel = 0; bits; channel++) {
if (!test_and_clear_bit(channel, &bits))
continue;
chan = sti_mbox_to_channel(mbox, instance, channel);
if (chan) {
dev_dbg(mbox->dev,
"IRQ fired on instance: %d channel: %d\n",
instance, channel);
break;
}
}
return chan;
}
static irqreturn_t sti_mbox_thread_handler(int irq, void *data)
{
struct sti_mbox_device *mdev = data;
struct sti_mbox_pdata *pdata = dev_get_platdata(mdev->dev);
struct mbox_chan *chan;
unsigned int instance;
for (instance = 0; instance < pdata->num_inst; instance++) {
keep_looking:
chan = sti_mbox_irq_to_channel(mdev, instance);
if (!chan)
continue;
mbox_chan_received_data(chan, NULL);
sti_mbox_clear_irq(chan);
sti_mbox_enable_channel(chan);
goto keep_looking;
}
return IRQ_HANDLED;
}
static irqreturn_t sti_mbox_irq_handler(int irq, void *data)
{
struct sti_mbox_device *mdev = data;
struct sti_mbox_pdata *pdata = dev_get_platdata(mdev->dev);
struct sti_channel *chan_info;
struct mbox_chan *chan;
unsigned int instance;
int ret = IRQ_NONE;
for (instance = 0; instance < pdata->num_inst; instance++) {
chan = sti_mbox_irq_to_channel(mdev, instance);
if (!chan)
continue;
chan_info = chan->con_priv;
if (!sti_mbox_channel_is_enabled(chan)) {
dev_warn(mdev->dev,
"Unexpected IRQ: %s\n"
" instance: %d: channel: %d [enabled: %x]\n",
mdev->name, chan_info->instance,
chan_info->channel, mdev->enabled[instance]);
if (ret == IRQ_NONE)
ret = IRQ_HANDLED;
continue;
}
sti_mbox_disable_channel(chan);
ret = IRQ_WAKE_THREAD;
}
if (ret == IRQ_NONE)
dev_err(mdev->dev, "Spurious IRQ - was a channel requested?\n");
return ret;
}
static bool sti_mbox_tx_is_ready(struct mbox_chan *chan)
{
struct sti_channel *chan_info = chan->con_priv;
struct sti_mbox_device *mdev = chan_info->mdev;
unsigned int instance = chan_info->instance;
unsigned int channel = chan_info->channel;
void __iomem *base = MBOX_BASE(mdev, instance);
if (!(readl_relaxed(base + STI_ENA_VAL_OFFSET) & BIT(channel))) {
dev_dbg(mdev->dev, "Mbox: %s: inst: %d, chan: %d disabled\n",
mdev->name, instance, channel);
return false;
}
if (readl_relaxed(base + STI_IRQ_VAL_OFFSET) & BIT(channel)) {
dev_dbg(mdev->dev, "Mbox: %s: inst: %d, chan: %d not ready\n",
mdev->name, instance, channel);
return false;
}
return true;
}
static int sti_mbox_send_data(struct mbox_chan *chan, void *data)
{
struct sti_channel *chan_info = chan->con_priv;
struct sti_mbox_device *mdev = chan_info->mdev;
unsigned int instance = chan_info->instance;
unsigned int channel = chan_info->channel;
void __iomem *base = MBOX_BASE(mdev, instance);
writel_relaxed(BIT(channel), base + STI_IRQ_SET_OFFSET);
dev_dbg(mdev->dev,
"Sent via Mailbox %s: instance: %d channel: %d\n",
mdev->name, instance, channel);
return 0;
}
static int sti_mbox_startup_chan(struct mbox_chan *chan)
{
sti_mbox_clear_irq(chan);
sti_mbox_enable_channel(chan);
return 0;
}
static void sti_mbox_shutdown_chan(struct mbox_chan *chan)
{
struct sti_channel *chan_info = chan->con_priv;
struct mbox_controller *mbox = chan_info->mdev->mbox;
int i;
for (i = 0; i < mbox->num_chans; i++)
if (chan == &mbox->chans[i])
break;
if (mbox->num_chans == i) {
dev_warn(mbox->dev, "Request to free non-existent channel\n");
return;
}
sti_mbox_disable_channel(chan);
sti_mbox_clear_irq(chan);
chan->con_priv = NULL;
}
static struct mbox_chan *sti_mbox_xlate(struct mbox_controller *mbox,
const struct of_phandle_args *spec)
{
struct sti_mbox_device *mdev = dev_get_drvdata(mbox->dev);
struct sti_mbox_pdata *pdata = dev_get_platdata(mdev->dev);
struct sti_channel *chan_info;
struct mbox_chan *chan = NULL;
unsigned int instance = spec->args[0];
unsigned int channel = spec->args[1];
int i;
if (instance >= pdata->num_inst || channel >= pdata->num_chan) {
dev_err(mbox->dev,
"Invalid channel requested instance: %d channel: %d\n",
instance, channel);
return ERR_PTR(-EINVAL);
}
for (i = 0; i < mbox->num_chans; i++) {
chan_info = mbox->chans[i].con_priv;
if (chan_info &&
mbox->dev == chan_info->mdev->dev &&
instance == chan_info->instance &&
channel == chan_info->channel) {
dev_err(mbox->dev, "Channel in use\n");
return ERR_PTR(-EBUSY);
}
if (!chan && !chan_info)
chan = &mbox->chans[i];
}
if (!chan) {
dev_err(mbox->dev, "No free channels left\n");
return ERR_PTR(-EBUSY);
}
chan_info = devm_kzalloc(mbox->dev, sizeof(*chan_info), GFP_KERNEL);
if (!chan_info)
return ERR_PTR(-ENOMEM);
chan_info->mdev = mdev;
chan_info->instance = instance;
chan_info->channel = channel;
chan->con_priv = chan_info;
dev_info(mbox->dev,
"Mbox: %s: Created channel: instance: %d channel: %d\n",
mdev->name, instance, channel);
return chan;
}
static int sti_mbox_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct mbox_controller *mbox;
struct sti_mbox_device *mdev;
struct device_node *np = pdev->dev.of_node;
struct mbox_chan *chans;
struct resource *res;
int irq;
int ret;
match = of_match_device(sti_mailbox_match, &pdev->dev);
if (!match) {
dev_err(&pdev->dev, "No configuration found\n");
return -ENODEV;
}
pdev->dev.platform_data = (struct sti_mbox_pdata *) match->data;
mdev = devm_kzalloc(&pdev->dev, sizeof(*mdev), GFP_KERNEL);
if (!mdev)
return -ENOMEM;
platform_set_drvdata(pdev, mdev);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mdev->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mdev->base))
return PTR_ERR(mdev->base);
ret = of_property_read_string(np, "mbox-name", &mdev->name);
if (ret)
mdev->name = np->full_name;
mbox = devm_kzalloc(&pdev->dev, sizeof(*mbox), GFP_KERNEL);
if (!mbox)
return -ENOMEM;
chans = devm_kzalloc(&pdev->dev,
sizeof(*chans) * STI_MBOX_CHAN_MAX, GFP_KERNEL);
if (!chans)
return -ENOMEM;
mdev->dev = &pdev->dev;
mdev->mbox = mbox;
spin_lock_init(&mdev->lock);
mbox->txdone_irq = false;
mbox->txdone_poll = true;
mbox->txpoll_period = 100;
mbox->ops = &sti_mbox_ops;
mbox->dev = mdev->dev;
mbox->of_xlate = sti_mbox_xlate;
mbox->chans = chans;
mbox->num_chans = STI_MBOX_CHAN_MAX;
ret = mbox_controller_register(mbox);
if (ret)
return ret;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_info(&pdev->dev,
"%s: Registered Tx only Mailbox\n", mdev->name);
return 0;
}
ret = devm_request_threaded_irq(&pdev->dev, irq,
sti_mbox_irq_handler,
sti_mbox_thread_handler,
IRQF_ONESHOT, mdev->name, mdev);
if (ret) {
dev_err(&pdev->dev, "Can't claim IRQ %d\n", irq);
mbox_controller_unregister(mbox);
return -EINVAL;
}
dev_info(&pdev->dev, "%s: Registered Tx/Rx Mailbox\n", mdev->name);
return 0;
}
static int sti_mbox_remove(struct platform_device *pdev)
{
struct sti_mbox_device *mdev = platform_get_drvdata(pdev);
mbox_controller_unregister(mdev->mbox);
return 0;
}
