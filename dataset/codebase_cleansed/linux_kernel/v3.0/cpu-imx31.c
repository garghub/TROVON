void __init mx31_read_cpu_rev(void)
{
u32 i, srev;
srev = __raw_readl(MX31_IO_ADDRESS(MX31_IIM_BASE_ADDR + MXC_IIMSREV));
for (i = 0; i < ARRAY_SIZE(mx31_cpu_type); i++)
if (srev == mx31_cpu_type[i].srev) {
printk(KERN_INFO
"CPU identified as %s, silicon rev %s\n",
mx31_cpu_type[i].name, mx31_cpu_type[i].v);
mx31_cpu_rev = mx31_cpu_type[i].rev;
return;
}
mx31_cpu_rev = IMX_CHIP_REVISION_UNKNOWN;
printk(KERN_WARNING "Unknown CPU identifier. srev = %02x\n", srev);
}
