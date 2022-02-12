static inline int mbox_read_reg(size_t ofs)
{
return __raw_readw(mbox_base + ofs);
}
static inline void mbox_write_reg(u32 val, size_t ofs)
{
__raw_writew(val, mbox_base + ofs);
}
static mbox_msg_t omap1_mbox_fifo_read(struct omap_mbox *mbox)
{
struct omap_mbox1_fifo *fifo =
&((struct omap_mbox1_priv *)mbox->priv)->rx_fifo;
mbox_msg_t msg;
msg = mbox_read_reg(fifo->data);
msg |= ((mbox_msg_t) mbox_read_reg(fifo->cmd)) << 16;
return msg;
}
static void
omap1_mbox_fifo_write(struct omap_mbox *mbox, mbox_msg_t msg)
{
struct omap_mbox1_fifo *fifo =
&((struct omap_mbox1_priv *)mbox->priv)->tx_fifo;
mbox_write_reg(msg & 0xffff, fifo->data);
mbox_write_reg(msg >> 16, fifo->cmd);
}
static int omap1_mbox_fifo_empty(struct omap_mbox *mbox)
{
return 0;
}
static int omap1_mbox_fifo_full(struct omap_mbox *mbox)
{
struct omap_mbox1_fifo *fifo =
&((struct omap_mbox1_priv *)mbox->priv)->rx_fifo;
return mbox_read_reg(fifo->flag);
}
static void
omap1_mbox_enable_irq(struct omap_mbox *mbox, omap_mbox_type_t irq)
{
if (irq == IRQ_RX)
enable_irq(mbox->irq);
}
static void
omap1_mbox_disable_irq(struct omap_mbox *mbox, omap_mbox_type_t irq)
{
if (irq == IRQ_RX)
disable_irq(mbox->irq);
}
static int
omap1_mbox_is_irq(struct omap_mbox *mbox, omap_mbox_type_t irq)
{
if (irq == IRQ_TX)
return 0;
return 1;
}
static int omap1_mbox_probe(struct platform_device *pdev)
{
struct resource *mem;
int ret;
struct omap_mbox **list;
list = omap1_mboxes;
list[0]->irq = platform_get_irq_byname(pdev, "dsp");
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mbox_base = ioremap(mem->start, resource_size(mem));
if (!mbox_base)
return -ENOMEM;
ret = omap_mbox_register(&pdev->dev, list);
if (ret) {
iounmap(mbox_base);
return ret;
}
return 0;
}
static int omap1_mbox_remove(struct platform_device *pdev)
{
omap_mbox_unregister();
iounmap(mbox_base);
return 0;
}
static int __init omap1_mbox_init(void)
{
return platform_driver_register(&omap1_mbox_driver);
}
static void __exit omap1_mbox_exit(void)
{
platform_driver_unregister(&omap1_mbox_driver);
}
