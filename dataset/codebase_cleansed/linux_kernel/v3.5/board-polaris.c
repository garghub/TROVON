static int __init polaris_initialise(void)
{
u16 wcr, bcr_mask;
printk(KERN_INFO "Configuring Polaris external bus\n");
wcr = __raw_readw(WCR2);
wcr &= (~AREA5_WAIT_CTRL);
wcr |= (WAIT_STATES_10 << 10);
__raw_writew(wcr, WCR2);
bcr_mask = __raw_readw(BCR2);
bcr_mask |= 1 << 10;
__raw_writew(bcr_mask, BCR2);
return platform_add_devices(polaris_devices,
ARRAY_SIZE(polaris_devices));
}
static void __init init_polaris_irq(void)
{
__raw_writew(0, BCR_ILCRA);
__raw_writew(0, BCR_ILCRB);
__raw_writew(0, BCR_ILCRC);
__raw_writew(0, BCR_ILCRD);
__raw_writew(0, BCR_ILCRE);
__raw_writew(0, BCR_ILCRF);
__raw_writew(0, BCR_ILCRG);
register_ipr_controller(&ipr_irq_desc);
}
