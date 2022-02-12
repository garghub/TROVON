static int __init p4080_ds_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "fsl,P4080DS")) {
#ifdef CONFIG_PCI
primary_phb_addr = 0x0000;
#endif
return 1;
} else {
return 0;
}
}
