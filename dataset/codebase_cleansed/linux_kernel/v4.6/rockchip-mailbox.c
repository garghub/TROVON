static int rockchip_mbox_send_data(struct mbox_chan *chan, void *data)
{
struct rockchip_mbox *mb = dev_get_drvdata(chan->mbox->dev);
struct rockchip_mbox_msg *msg = data;
struct rockchip_mbox_chan *chans = mb->chans;
if (!msg)
return -EINVAL;
if (msg->rx_size > mb->buf_size) {
dev_err(mb->mbox.dev, "Transmit size over buf size(%d)\n",
mb->buf_size);
return -EINVAL;
}
dev_dbg(mb->mbox.dev, "Chan[%d]: A2B message, cmd 0x%08x\n",
chans->idx, msg->cmd);
mb->chans[chans->idx].msg = msg;
writel_relaxed(msg->cmd, mb->mbox_base + MAILBOX_A2B_CMD(chans->idx));
writel_relaxed(msg->rx_size, mb->mbox_base +
MAILBOX_A2B_DAT(chans->idx));
return 0;
}
static int rockchip_mbox_startup(struct mbox_chan *chan)
{
struct rockchip_mbox *mb = dev_get_drvdata(chan->mbox->dev);
writel_relaxed((1 << mb->mbox.num_chans) - 1,
mb->mbox_base + MAILBOX_B2A_INTEN);
return 0;
}
static void rockchip_mbox_shutdown(struct mbox_chan *chan)
{
struct rockchip_mbox *mb = dev_get_drvdata(chan->mbox->dev);
struct rockchip_mbox_chan *chans = mb->chans;
writel_relaxed(0, mb->mbox_base + MAILBOX_B2A_INTEN);
mb->chans[chans->idx].msg = NULL;
}
static irqreturn_t rockchip_mbox_irq(int irq, void *dev_id)
{
int idx;
struct rockchip_mbox *mb = (struct rockchip_mbox *)dev_id;
u32 status = readl_relaxed(mb->mbox_base + MAILBOX_B2A_STATUS);
for (idx = 0; idx < mb->mbox.num_chans; idx++) {
if ((status & (1 << idx)) && (irq == mb->chans[idx].irq)) {
writel_relaxed(1 << idx,
mb->mbox_base + MAILBOX_B2A_STATUS);
return IRQ_WAKE_THREAD;
}
}
return IRQ_NONE;
}
static irqreturn_t rockchip_mbox_isr(int irq, void *dev_id)
{
int idx;
struct rockchip_mbox_msg *msg = NULL;
struct rockchip_mbox *mb = (struct rockchip_mbox *)dev_id;
for (idx = 0; idx < mb->mbox.num_chans; idx++) {
if (irq != mb->chans[idx].irq)
continue;
msg = mb->chans[idx].msg;
if (!msg) {
dev_err(mb->mbox.dev,
"Chan[%d]: B2A message is NULL\n", idx);
break;
}
mbox_chan_received_data(&mb->mbox.chans[idx], msg);
mb->chans[idx].msg = NULL;
dev_dbg(mb->mbox.dev, "Chan[%d]: B2A message, cmd 0x%08x\n",
idx, msg->cmd);
break;
}
return IRQ_HANDLED;
}
static int rockchip_mbox_probe(struct platform_device *pdev)
{
struct rockchip_mbox *mb;
const struct of_device_id *match;
const struct rockchip_mbox_data *drv_data;
struct resource *res;
int ret, irq, i;
if (!pdev->dev.of_node)
return -ENODEV;
match = of_match_node(rockchip_mbox_of_match, pdev->dev.of_node);
drv_data = (const struct rockchip_mbox_data *)match->data;
mb = devm_kzalloc(&pdev->dev, sizeof(*mb), GFP_KERNEL);
if (!mb)
return -ENOMEM;
mb->chans = devm_kcalloc(&pdev->dev, drv_data->num_chans,
sizeof(*mb->chans), GFP_KERNEL);
if (!mb->chans)
return -ENOMEM;
mb->mbox.chans = devm_kcalloc(&pdev->dev, drv_data->num_chans,
sizeof(*mb->mbox.chans), GFP_KERNEL);
if (!mb->mbox.chans)
return -ENOMEM;
platform_set_drvdata(pdev, mb);
mb->mbox.dev = &pdev->dev;
mb->mbox.num_chans = drv_data->num_chans;
mb->mbox.ops = &rockchip_mbox_chan_ops;
mb->mbox.txdone_irq = true;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
mb->mbox_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mb->mbox_base))
return PTR_ERR(mb->mbox_base);
mb->buf_size = (size_t)resource_size(res) / (drv_data->num_chans * 2);
mb->pclk = devm_clk_get(&pdev->dev, "pclk_mailbox");
if (IS_ERR(mb->pclk)) {
ret = PTR_ERR(mb->pclk);
dev_err(&pdev->dev, "failed to get pclk_mailbox clock: %d\n",
ret);
return ret;
}
ret = clk_prepare_enable(mb->pclk);
if (ret) {
dev_err(&pdev->dev, "failed to enable pclk: %d\n", ret);
return ret;
}
for (i = 0; i < mb->mbox.num_chans; i++) {
irq = platform_get_irq(pdev, i);
if (irq < 0)
return irq;
ret = devm_request_threaded_irq(&pdev->dev, irq,
rockchip_mbox_irq,
rockchip_mbox_isr, IRQF_ONESHOT,
dev_name(&pdev->dev), mb);
if (ret < 0)
return ret;
mb->chans[i].idx = i;
mb->chans[i].irq = irq;
mb->chans[i].mb = mb;
mb->chans[i].msg = NULL;
}
ret = mbox_controller_register(&mb->mbox);
if (ret < 0)
dev_err(&pdev->dev, "Failed to register mailbox: %d\n", ret);
return ret;
}
static int rockchip_mbox_remove(struct platform_device *pdev)
{
struct rockchip_mbox *mb = platform_get_drvdata(pdev);
if (!mb)
return -EINVAL;
mbox_controller_unregister(&mb->mbox);
return 0;
}
