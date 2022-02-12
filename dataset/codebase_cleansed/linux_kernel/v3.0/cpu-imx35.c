void __init mx35_read_cpu_rev(void)
{
u32 rev;
char *srev;
rev = __raw_readl(MX35_IO_ADDRESS(MX35_IIM_BASE_ADDR + MXC_IIMSREV));
switch (rev) {
case 0x00:
mx35_cpu_rev = IMX_CHIP_REVISION_1_0;
srev = "1.0";
break;
case 0x10:
mx35_cpu_rev = IMX_CHIP_REVISION_2_0;
srev = "2.0";
break;
case 0x11:
mx35_cpu_rev = IMX_CHIP_REVISION_2_1;
srev = "2.1";
break;
default:
mx35_cpu_rev = IMX_CHIP_REVISION_UNKNOWN;
srev = "unknown";
}
printk(KERN_INFO "CPU identified as i.MX35, silicon rev %s\n", srev);
}
