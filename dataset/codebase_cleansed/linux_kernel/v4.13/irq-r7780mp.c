unsigned char * __init highlander_plat_irq_setup(void)
{
if ((__raw_readw(0xa4000700) & 0xf000) == 0x2000) {
printk(KERN_INFO "Using r7780mp interrupt controller.\n");
register_intc_controller(&intc_desc);
return irl2irq;
}
return NULL;
}
