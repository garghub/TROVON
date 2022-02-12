void __init nuc93x_map_io(struct map_desc *mach_desc, int mach_size)
{
unsigned long idcode = 0x0;
iotable_init(mach_desc, mach_size);
iotable_init(nuc93x_iodesc, ARRAY_SIZE(nuc93x_iodesc));
idcode = __raw_readl(NUC93XPDID);
if (idcode == NUC932_CPUID)
printk(KERN_INFO "CPU type 0x%08lx is NUC910\n", idcode);
else
printk(KERN_ERR "CPU type detect error!\n");
}
void __init nuc93x_init_clocks(void)
{
clks_register(nuc932_clkregs, ARRAY_SIZE(nuc932_clkregs));
}
