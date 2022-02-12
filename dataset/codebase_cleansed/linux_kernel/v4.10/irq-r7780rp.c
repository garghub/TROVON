unsigned char * __init highlander_plat_irq_setup(void)
{
if (__raw_readw(0xa5000600)) {
printk(KERN_INFO "Using r7780rp interrupt controller.\n");
register_intc_controller(&intc_desc);
return irl2irq;
}
return NULL;
}
