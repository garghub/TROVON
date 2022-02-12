unsigned char * __init highlander_plat_irq_setup(void)
{
if ((__raw_readw(0xa4000158) & 0xf000) != 0x1000)
return NULL;
printk(KERN_INFO "Using r7785rp interrupt controller.\n");
__raw_writew(0x0000, PA_IRLSSR1);
__raw_writew(0x0000, PA_IRLPRA);
__raw_writew(0xe598, PA_IRLPRB);
__raw_writew(0x7060, PA_IRLPRC);
__raw_writew(0x0000, PA_IRLPRD);
__raw_writew(0x4321, PA_IRLPRE);
__raw_writew(0xdcba, PA_IRLPRF);
register_intc_controller(&intc_desc);
return irl2irq;
}
