static void query_silicon_parameter(void)
{
u32 val;
val = __raw_readl(MX27_IO_ADDRESS(MX27_SYSCTRL_BASE_ADDR
+ SYS_CHIP_ID));
switch (val >> 28) {
case 0:
cpu_silicon_rev = IMX_CHIP_REVISION_1_0;
break;
case 1:
cpu_silicon_rev = IMX_CHIP_REVISION_2_0;
break;
case 2:
cpu_silicon_rev = IMX_CHIP_REVISION_2_1;
break;
default:
cpu_silicon_rev = IMX_CHIP_REVISION_UNKNOWN;
}
cpu_partnumber = (int)((val >> 12) & 0xFFFF);
}
int mx27_revision(void)
{
if (cpu_silicon_rev == -1)
query_silicon_parameter();
if (cpu_partnumber != 0x8821)
return -EINVAL;
return cpu_silicon_rev;
}
