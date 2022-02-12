static void asp_choose_irq(struct parisc_device *dev, void *ctrl)
{
int irq;
switch (dev->id.sversion) {
case 0x71: irq = 9; break;
case 0x72: irq = 8; break;
case 0x73: irq = 1; break;
case 0x74: irq = 7; break;
case 0x75: irq = (dev->hw_path == 4) ? 5 : 6; break;
case 0x76: irq = 10; break;
case 0x77: irq = 11; break;
case 0x7a: irq = 13; break;
case 0x7b: irq = 13; break;
case 0x7c: irq = 3; break;
case 0x7d: irq = 4; break;
case 0x7f: irq = 13; break;
default: return;
}
gsc_asic_assign_irq(ctrl, irq, &dev->irq);
switch (dev->id.sversion) {
case 0x73: irq = 2; break;
case 0x76: irq = 0; break;
default: return;
}
gsc_asic_assign_irq(ctrl, irq, &dev->aux_irq);
}
static int __init asp_init_chip(struct parisc_device *dev)
{
struct gsc_irq gsc_irq;
int ret;
asp.version = gsc_readb(dev->hpa.start + ASP_VER_OFFSET) & 0xf;
asp.name = (asp.version == 1) ? "Asp" : "Cutoff";
asp.hpa = ASP_INTERRUPT_ADDR;
printk(KERN_INFO "%s version %d at 0x%lx found.\n",
asp.name, asp.version, (unsigned long)dev->hpa.start);
ret = -EBUSY;
dev->irq = gsc_claim_irq(&gsc_irq, ASP_GSC_IRQ);
if (dev->irq < 0) {
printk(KERN_ERR "%s(): cannot get GSC irq\n", __func__);
goto out;
}
asp.eim = ((u32) gsc_irq.txn_addr) | gsc_irq.txn_data;
ret = request_irq(gsc_irq.irq, gsc_asic_intr, 0, "asp", &asp);
if (ret < 0)
goto out;
gsc_writel((1 << (31 - ASP_GSC_IRQ)),VIPER_INT_WORD);
ret = gsc_common_setup(dev, &asp);
if (ret)
goto out;
gsc_fixup_irqs(dev, &asp, asp_choose_irq);
gsc_fixup_irqs(parisc_parent(dev), &asp, asp_choose_irq);
#ifdef CONFIG_CHASSIS_LCD_LED
register_led_driver(DISPLAY_MODEL_OLD_ASP, LED_CMD_REG_NONE,
ASP_LED_ADDR);
#endif
out:
return ret;
}
