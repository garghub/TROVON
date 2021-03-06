static void wax_choose_irq(struct parisc_device *dev, void *ctrl)
{
int irq;
switch (dev->id.sversion) {
case 0x73: irq = 1; break;
case 0x8c: irq = 6; break;
case 0x90: irq = 10; break;
default: return;
}
gsc_asic_assign_irq(ctrl, irq, &dev->irq);
switch (dev->id.sversion) {
case 0x73: irq = 2; break;
case 0x90: irq = 0; break;
default: return;
}
gsc_asic_assign_irq(ctrl, irq, &dev->aux_irq);
}
static void __init
wax_init_irq(struct gsc_asic *wax)
{
unsigned long base = wax->hpa;
gsc_writel(0x00000000, base+OFFSET_IMR);
gsc_readl(base+OFFSET_IRR);
}
static int __init wax_init_chip(struct parisc_device *dev)
{
struct gsc_asic *wax;
struct parisc_device *parent;
struct gsc_irq gsc_irq;
int ret;
wax = kzalloc(sizeof(*wax), GFP_KERNEL);
if (!wax)
return -ENOMEM;
wax->name = "wax";
wax->hpa = dev->hpa.start;
wax->version = 0;
printk(KERN_INFO "%s at 0x%lx found.\n", wax->name, wax->hpa);
wax_init_irq(wax);
dev->irq = gsc_claim_irq(&gsc_irq, WAX_GSC_IRQ);
if (dev->irq < 0) {
printk(KERN_ERR "%s(): cannot get GSC irq\n",
__func__);
kfree(wax);
return -EBUSY;
}
wax->eim = ((u32) gsc_irq.txn_addr) | gsc_irq.txn_data;
ret = request_irq(gsc_irq.irq, gsc_asic_intr, 0, "wax", wax);
if (ret < 0) {
kfree(wax);
return ret;
}
gsc_writel(wax->eim, wax->hpa + OFFSET_IAR);
ret = gsc_common_setup(dev, wax);
if (ret) {
kfree(wax);
return ret;
}
gsc_fixup_irqs(dev, wax, wax_choose_irq);
parent = parisc_parent(dev);
if (parent->id.hw_type != HPHW_IOA) {
gsc_fixup_irqs(parent, wax, wax_choose_irq);
}
return ret;
}
