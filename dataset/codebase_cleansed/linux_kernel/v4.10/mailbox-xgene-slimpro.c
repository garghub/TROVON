static void mb_chan_send_msg(struct slimpro_mbox_chan *mb_chan, u32 *msg)
{
writel(msg[1], mb_chan->reg + REG_DB_DOUT0);
writel(msg[2], mb_chan->reg + REG_DB_DOUT1);
writel(msg[0], mb_chan->reg + REG_DB_OUT);
}
static void mb_chan_recv_msg(struct slimpro_mbox_chan *mb_chan)
{
mb_chan->rx_msg[1] = readl(mb_chan->reg + REG_DB_DIN0);
mb_chan->rx_msg[2] = readl(mb_chan->reg + REG_DB_DIN1);
mb_chan->rx_msg[0] = readl(mb_chan->reg + REG_DB_IN);
}
static int mb_chan_status_ack(struct slimpro_mbox_chan *mb_chan)
{
u32 val = readl(mb_chan->reg + REG_DB_STAT);
if (val & MBOX_STATUS_ACK_MASK) {
writel(MBOX_STATUS_ACK_MASK, mb_chan->reg + REG_DB_STAT);
return 1;
}
return 0;
}
static int mb_chan_status_avail(struct slimpro_mbox_chan *mb_chan)
{
u32 val = readl(mb_chan->reg + REG_DB_STAT);
if (val & MBOX_STATUS_AVAIL_MASK) {
mb_chan_recv_msg(mb_chan);
writel(MBOX_STATUS_AVAIL_MASK, mb_chan->reg + REG_DB_STAT);
return 1;
}
return 0;
}
static irqreturn_t slimpro_mbox_irq(int irq, void *id)
{
struct slimpro_mbox_chan *mb_chan = id;
if (mb_chan_status_ack(mb_chan))
mbox_chan_txdone(mb_chan->chan, 0);
if (mb_chan_status_avail(mb_chan))
mbox_chan_received_data(mb_chan->chan, mb_chan->rx_msg);
return IRQ_HANDLED;
}
static int slimpro_mbox_send_data(struct mbox_chan *chan, void *msg)
{
struct slimpro_mbox_chan *mb_chan = chan->con_priv;
mb_chan_send_msg(mb_chan, msg);
return 0;
}
static int slimpro_mbox_startup(struct mbox_chan *chan)
{
struct slimpro_mbox_chan *mb_chan = chan->con_priv;
int rc;
u32 val;
rc = devm_request_irq(mb_chan->dev, mb_chan->irq, slimpro_mbox_irq, 0,
MBOX_CON_NAME, mb_chan);
if (unlikely(rc)) {
dev_err(mb_chan->dev, "failed to register mailbox interrupt %d\n",
mb_chan->irq);
return rc;
}
writel(MBOX_STATUS_ACK_MASK | MBOX_STATUS_AVAIL_MASK,
mb_chan->reg + REG_DB_STAT);
val = readl(mb_chan->reg + REG_DB_STATMASK);
val &= ~(MBOX_STATUS_ACK_MASK | MBOX_STATUS_AVAIL_MASK);
writel(val, mb_chan->reg + REG_DB_STATMASK);
return 0;
}
static void slimpro_mbox_shutdown(struct mbox_chan *chan)
{
struct slimpro_mbox_chan *mb_chan = chan->con_priv;
u32 val;
val = readl(mb_chan->reg + REG_DB_STATMASK);
val |= (MBOX_STATUS_ACK_MASK | MBOX_STATUS_AVAIL_MASK);
writel(val, mb_chan->reg + REG_DB_STATMASK);
devm_free_irq(mb_chan->dev, mb_chan->irq, mb_chan);
}
static int slimpro_mbox_probe(struct platform_device *pdev)
{
struct slimpro_mbox *ctx;
struct resource *regs;
void __iomem *mb_base;
int rc;
int i;
ctx = devm_kzalloc(&pdev->dev, sizeof(struct slimpro_mbox), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
platform_set_drvdata(pdev, ctx);
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mb_base = devm_ioremap(&pdev->dev, regs->start, resource_size(regs));
if (!mb_base)
return -ENOMEM;
for (i = 0; i < MBOX_CNT; i++) {
ctx->mc[i].irq = platform_get_irq(pdev, i);
if (ctx->mc[i].irq < 0) {
if (i == 0) {
dev_err(&pdev->dev, "no available IRQ\n");
return -EINVAL;
}
dev_info(&pdev->dev, "no IRQ for channel %d\n", i);
break;
}
ctx->mc[i].dev = &pdev->dev;
ctx->mc[i].reg = mb_base + i * MBOX_REG_SET_OFFSET;
ctx->mc[i].chan = &ctx->chans[i];
ctx->chans[i].con_priv = &ctx->mc[i];
}
ctx->mb_ctrl.dev = &pdev->dev;
ctx->mb_ctrl.chans = ctx->chans;
ctx->mb_ctrl.txdone_irq = true;
ctx->mb_ctrl.ops = &slimpro_mbox_ops;
ctx->mb_ctrl.num_chans = i;
rc = mbox_controller_register(&ctx->mb_ctrl);
if (rc) {
dev_err(&pdev->dev,
"APM X-Gene SLIMpro MailBox register failed:%d\n", rc);
return rc;
}
dev_info(&pdev->dev, "APM X-Gene SLIMpro MailBox registered\n");
return 0;
}
static int slimpro_mbox_remove(struct platform_device *pdev)
{
struct slimpro_mbox *smb = platform_get_drvdata(pdev);
mbox_controller_unregister(&smb->mb_ctrl);
return 0;
}
static int __init slimpro_mbox_init(void)
{
return platform_driver_register(&slimpro_mbox_driver);
}
static void __exit slimpro_mbox_exit(void)
{
platform_driver_unregister(&slimpro_mbox_driver);
}
