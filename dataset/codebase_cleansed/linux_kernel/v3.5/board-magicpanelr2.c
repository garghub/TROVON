static int __init ethernet_reset_finished(void)
{
int i;
if (LAN9115_READY)
return 1;
for (i = 0; i < 10; ++i) {
mdelay(10);
if (LAN9115_READY)
return 1;
}
return 0;
}
static void __init reset_ethernet(void)
{
CLRBITS_OUTB(0x10, PORT_PMDR);
udelay(200);
SETBITS_OUTB(0x10, PORT_PMDR);
}
static void __init setup_chip_select(void)
{
__raw_writel(0x36db0400, CS2BCR);
__raw_writel(0x000003c0, CS2WCR);
__raw_writel(0x00000200, CS4BCR);
__raw_writel(0x00100981, CS4WCR);
__raw_writel(0x00000200, CS5ABCR);
__raw_writel(0x00100981, CS5AWCR);
__raw_writel(0x00000200, CS5BBCR);
__raw_writel(0x00100981, CS5BWCR);
__raw_writel(0x00000200, CS6ABCR);
__raw_writel(0x001009C1, CS6AWCR);
}
static void __init setup_port_multiplexing(void)
{
__raw_writew(0x5555, PORT_PACR);
__raw_writew(0x5555, PORT_PBCR);
__raw_writew(0x5500, PORT_PCCR);
__raw_writew(0x5555, PORT_PDCR);
__raw_writew(0x3C00, PORT_PECR);
__raw_writew(0x0002, PORT_PFCR);
__raw_writew(0x03D5, PORT_PGCR);
__raw_writew(0x0050, PORT_PHCR);
__raw_writew(0x0000, PORT_PJCR);
__raw_writew(0x00FF, PORT_PKCR);
__raw_writew(0x0000, PORT_PLCR);
__raw_writew(0x5552, PORT_PMCR);
#if CONFIG_SH_MAGIC_PANEL_R2_VERSION == 2
__raw_writeb(0x30, PORT_PMDR);
#elif CONFIG_SH_MAGIC_PANEL_R2_VERSION == 3
__raw_writeb(0xF0, PORT_PMDR);
#else
#error Unknown revision of PLATFORM_MP_R2
#endif
__raw_writew(0x0100, PORT_PPCR);
__raw_writeb(0x10, PORT_PPDR);
gpio_request(GPIO_FN_A25, NULL);
gpio_request(GPIO_FN_A24, NULL);
gpio_request(GPIO_FN_A23, NULL);
gpio_request(GPIO_FN_A22, NULL);
gpio_request(GPIO_FN_A21, NULL);
gpio_request(GPIO_FN_A20, NULL);
gpio_request(GPIO_FN_A19, NULL);
gpio_request(GPIO_FN_A0, NULL);
__raw_writew(0x0140, PORT_PSCR);
__raw_writew(0x0001, PORT_PTCR);
__raw_writew(0x0240, PORT_PUCR);
__raw_writew(0x0142, PORT_PVCR);
}
static void __init mpr2_setup(char **cmdline_p)
{
__raw_writew(0xAABC, PORT_PSELA);
__raw_writew(0x3C00, PORT_PSELB);
__raw_writew(0x0000, PORT_PSELC);
__raw_writew(0x0000, PORT_PSELD);
__raw_writew(0x0101, PORT_UTRCTL);
__raw_writew(0xA5C0, PORT_UCLKCR_W);
setup_chip_select();
setup_port_multiplexing();
reset_ethernet();
printk(KERN_INFO "Magic Panel Release 2 A.%i\n",
CONFIG_SH_MAGIC_PANEL_R2_VERSION);
if (ethernet_reset_finished() == 0)
printk(KERN_WARNING "Ethernet not ready\n");
}
static int __init mpr2_devices_setup(void)
{
return platform_add_devices(mpr2_devices, ARRAY_SIZE(mpr2_devices));
}
static void __init init_mpr2_IRQ(void)
{
plat_irq_setup_pins(IRQ_MODE_IRQ);
irq_set_irq_type(evt2irq(0x600), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(evt2irq(0x620), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(evt2irq(0x640), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(evt2irq(0x660), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(evt2irq(0x680), IRQ_TYPE_EDGE_RISING);
irq_set_irq_type(evt2irq(0x6a0), IRQ_TYPE_EDGE_FALLING);
intc_set_priority(evt2irq(0x600), 13);
intc_set_priority(evt2irq(0x620), 13);
intc_set_priority(evt2irq(0x640), 13);
intc_set_priority(evt2irq(0x660), 6);
}
