static inline unsigned int mbox_read_reg(size_t ofs)
{
return __raw_readl(mbox_base + ofs);
}
static inline void mbox_write_reg(u32 val, size_t ofs)
{
__raw_writel(val, mbox_base + ofs);
}
static int omap2_mbox_startup(struct omap_mbox *mbox)
{
u32 l;
pm_runtime_enable(mbox->dev->parent);
pm_runtime_get_sync(mbox->dev->parent);
l = mbox_read_reg(MAILBOX_REVISION);
pr_debug("omap mailbox rev %d.%d\n", (l & 0xf0) >> 4, (l & 0x0f));
return 0;
}
static void omap2_mbox_shutdown(struct omap_mbox *mbox)
{
pm_runtime_put_sync(mbox->dev->parent);
pm_runtime_disable(mbox->dev->parent);
}
static mbox_msg_t omap2_mbox_fifo_read(struct omap_mbox *mbox)
{
struct omap_mbox2_fifo *fifo =
&((struct omap_mbox2_priv *)mbox->priv)->rx_fifo;
return (mbox_msg_t) mbox_read_reg(fifo->msg);
}
static void omap2_mbox_fifo_write(struct omap_mbox *mbox, mbox_msg_t msg)
{
struct omap_mbox2_fifo *fifo =
&((struct omap_mbox2_priv *)mbox->priv)->tx_fifo;
mbox_write_reg(msg, fifo->msg);
}
static int omap2_mbox_fifo_empty(struct omap_mbox *mbox)
{
struct omap_mbox2_fifo *fifo =
&((struct omap_mbox2_priv *)mbox->priv)->rx_fifo;
return (mbox_read_reg(fifo->msg_stat) == 0);
}
static int omap2_mbox_fifo_full(struct omap_mbox *mbox)
{
struct omap_mbox2_fifo *fifo =
&((struct omap_mbox2_priv *)mbox->priv)->tx_fifo;
return mbox_read_reg(fifo->fifo_stat);
}
static void omap2_mbox_enable_irq(struct omap_mbox *mbox, omap_mbox_irq_t irq)
{
struct omap_mbox2_priv *p = mbox->priv;
u32 l, bit = (irq == IRQ_TX) ? p->notfull_bit : p->newmsg_bit;
l = mbox_read_reg(p->irqenable);
l |= bit;
mbox_write_reg(l, p->irqenable);
}
static void omap2_mbox_disable_irq(struct omap_mbox *mbox, omap_mbox_irq_t irq)
{
struct omap_mbox2_priv *p = mbox->priv;
u32 bit = (irq == IRQ_TX) ? p->notfull_bit : p->newmsg_bit;
if (!p->intr_type)
bit = mbox_read_reg(p->irqdisable) & ~bit;
mbox_write_reg(bit, p->irqdisable);
}
static void omap2_mbox_ack_irq(struct omap_mbox *mbox, omap_mbox_irq_t irq)
{
struct omap_mbox2_priv *p = mbox->priv;
u32 bit = (irq == IRQ_TX) ? p->notfull_bit : p->newmsg_bit;
mbox_write_reg(bit, p->irqstatus);
mbox_read_reg(p->irqstatus);
}
static int omap2_mbox_is_irq(struct omap_mbox *mbox, omap_mbox_irq_t irq)
{
struct omap_mbox2_priv *p = mbox->priv;
u32 bit = (irq == IRQ_TX) ? p->notfull_bit : p->newmsg_bit;
u32 enable = mbox_read_reg(p->irqenable);
u32 status = mbox_read_reg(p->irqstatus);
return (int)(enable & status & bit);
}
static void omap2_mbox_save_ctx(struct omap_mbox *mbox)
{
int i;
struct omap_mbox2_priv *p = mbox->priv;
int nr_regs;
if (p->intr_type)
nr_regs = OMAP4_MBOX_NR_REGS;
else
nr_regs = MBOX_NR_REGS;
for (i = 0; i < nr_regs; i++) {
p->ctx[i] = mbox_read_reg(i * sizeof(u32));
dev_dbg(mbox->dev, "%s: [%02x] %08x\n", __func__,
i, p->ctx[i]);
}
}
static void omap2_mbox_restore_ctx(struct omap_mbox *mbox)
{
int i;
struct omap_mbox2_priv *p = mbox->priv;
int nr_regs;
if (p->intr_type)
nr_regs = OMAP4_MBOX_NR_REGS;
else
nr_regs = MBOX_NR_REGS;
for (i = 0; i < nr_regs; i++) {
mbox_write_reg(p->ctx[i], i * sizeof(u32));
dev_dbg(mbox->dev, "%s: [%02x] %08x\n", __func__,
i, p->ctx[i]);
}
}
static int omap2_mbox_probe(struct platform_device *pdev)
{
struct resource *mem;
int ret;
struct omap_mbox **list, *mbox, *mboxblk;
struct omap_mbox2_priv *priv, *privblk;
struct omap_mbox_pdata *pdata = pdev->dev.platform_data;
struct omap_mbox_dev_info *info;
int i;
if (!pdata || !pdata->info_cnt || !pdata->info) {
pr_err("%s: platform not supported\n", __func__);
return -ENODEV;
}
list = kzalloc((pdata->info_cnt + 1) * sizeof(*list), GFP_KERNEL);
if (!list)
return -ENOMEM;
mboxblk = mbox = kzalloc(pdata->info_cnt * sizeof(*mbox), GFP_KERNEL);
if (!mboxblk) {
ret = -ENOMEM;
goto free_list;
}
privblk = priv = kzalloc(pdata->info_cnt * sizeof(*priv), GFP_KERNEL);
if (!privblk) {
ret = -ENOMEM;
goto free_mboxblk;
}
info = pdata->info;
for (i = 0; i < pdata->info_cnt; i++, info++, priv++) {
priv->tx_fifo.msg = MAILBOX_MESSAGE(info->tx_id);
priv->tx_fifo.fifo_stat = MAILBOX_FIFOSTATUS(info->tx_id);
priv->rx_fifo.msg = MAILBOX_MESSAGE(info->rx_id);
priv->rx_fifo.msg_stat = MAILBOX_MSGSTATUS(info->rx_id);
priv->notfull_bit = MAILBOX_IRQ_NOTFULL(info->tx_id);
priv->newmsg_bit = MAILBOX_IRQ_NEWMSG(info->rx_id);
if (pdata->intr_type) {
priv->irqenable = OMAP4_MAILBOX_IRQENABLE(info->usr_id);
priv->irqstatus = OMAP4_MAILBOX_IRQSTATUS(info->usr_id);
priv->irqdisable =
OMAP4_MAILBOX_IRQENABLE_CLR(info->usr_id);
} else {
priv->irqenable = MAILBOX_IRQENABLE(info->usr_id);
priv->irqstatus = MAILBOX_IRQSTATUS(info->usr_id);
priv->irqdisable = MAILBOX_IRQENABLE(info->usr_id);
}
priv->intr_type = pdata->intr_type;
mbox->priv = priv;
mbox->name = info->name;
mbox->ops = &omap2_mbox_ops;
mbox->irq = platform_get_irq(pdev, info->irq_id);
if (mbox->irq < 0) {
ret = mbox->irq;
goto free_privblk;
}
list[i] = mbox++;
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
ret = -ENOENT;
goto free_privblk;
}
mbox_base = ioremap(mem->start, resource_size(mem));
if (!mbox_base) {
ret = -ENOMEM;
goto free_privblk;
}
ret = omap_mbox_register(&pdev->dev, list);
if (ret)
goto unmap_mbox;
platform_set_drvdata(pdev, list);
return 0;
unmap_mbox:
iounmap(mbox_base);
free_privblk:
kfree(privblk);
free_mboxblk:
kfree(mboxblk);
free_list:
kfree(list);
return ret;
}
static int omap2_mbox_remove(struct platform_device *pdev)
{
struct omap_mbox2_priv *privblk;
struct omap_mbox **list = platform_get_drvdata(pdev);
struct omap_mbox *mboxblk = list[0];
privblk = mboxblk->priv;
omap_mbox_unregister();
iounmap(mbox_base);
kfree(privblk);
kfree(mboxblk);
kfree(list);
return 0;
}
static int __init omap2_mbox_init(void)
{
return platform_driver_register(&omap2_mbox_driver);
}
static void __exit omap2_mbox_exit(void)
{
platform_driver_unregister(&omap2_mbox_driver);
}
