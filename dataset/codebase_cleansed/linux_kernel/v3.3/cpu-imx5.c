static int get_mx51_srev(void)
{
void __iomem *iim_base = MX51_IO_ADDRESS(MX51_IIM_BASE_ADDR);
u32 rev = readl(iim_base + IIM_SREV) & 0xff;
switch (rev) {
case 0x0:
return IMX_CHIP_REVISION_2_0;
case 0x10:
return IMX_CHIP_REVISION_3_0;
default:
return IMX_CHIP_REVISION_UNKNOWN;
}
}
int mx51_revision(void)
{
if (!cpu_is_mx51())
return -EINVAL;
if (mx5_cpu_rev == -1)
mx5_cpu_rev = get_mx51_srev();
return mx5_cpu_rev;
}
static int __init mx51_neon_fixup(void)
{
if (!cpu_is_mx51())
return 0;
if (mx51_revision() < IMX_CHIP_REVISION_3_0 &&
(elf_hwcap & HWCAP_NEON)) {
elf_hwcap &= ~HWCAP_NEON;
pr_info("Turning off NEON support, detected broken NEON implementation\n");
}
return 0;
}
static int get_mx53_srev(void)
{
void __iomem *iim_base = MX51_IO_ADDRESS(MX53_IIM_BASE_ADDR);
u32 rev = readl(iim_base + IIM_SREV) & 0xff;
switch (rev) {
case 0x0:
return IMX_CHIP_REVISION_1_0;
case 0x2:
return IMX_CHIP_REVISION_2_0;
case 0x3:
return IMX_CHIP_REVISION_2_1;
default:
return IMX_CHIP_REVISION_UNKNOWN;
}
}
int mx53_revision(void)
{
if (!cpu_is_mx53())
return -EINVAL;
if (mx5_cpu_rev == -1)
mx5_cpu_rev = get_mx53_srev();
return mx5_cpu_rev;
}
static int get_mx50_srev(void)
{
void __iomem *anatop = ioremap(MX50_ANATOP_BASE_ADDR, SZ_8K);
u32 rev;
if (!anatop) {
mx5_cpu_rev = -EINVAL;
return 0;
}
rev = readl(anatop + MX50_HW_ADADIG_DIGPROG);
rev &= 0xff;
iounmap(anatop);
if (rev == 0x0)
return IMX_CHIP_REVISION_1_0;
else if (rev == 0x1)
return IMX_CHIP_REVISION_1_1;
return 0;
}
int mx50_revision(void)
{
if (!cpu_is_mx50())
return -EINVAL;
if (mx5_cpu_rev == -1)
mx5_cpu_rev = get_mx50_srev();
return mx5_cpu_rev;
}
static int __init post_cpu_init(void)
{
unsigned int reg;
void __iomem *base;
if (cpu_is_mx51() || cpu_is_mx53()) {
if (cpu_is_mx51())
base = MX51_IO_ADDRESS(MX51_AIPS1_BASE_ADDR);
else
base = MX53_IO_ADDRESS(MX53_AIPS1_BASE_ADDR);
__raw_writel(0x0, base + 0x40);
__raw_writel(0x0, base + 0x44);
__raw_writel(0x0, base + 0x48);
__raw_writel(0x0, base + 0x4C);
reg = __raw_readl(base + 0x50) & 0x00FFFFFF;
__raw_writel(reg, base + 0x50);
if (cpu_is_mx51())
base = MX51_IO_ADDRESS(MX51_AIPS2_BASE_ADDR);
else
base = MX53_IO_ADDRESS(MX53_AIPS2_BASE_ADDR);
__raw_writel(0x0, base + 0x40);
__raw_writel(0x0, base + 0x44);
__raw_writel(0x0, base + 0x48);
__raw_writel(0x0, base + 0x4C);
reg = __raw_readl(base + 0x50) & 0x00FFFFFF;
__raw_writel(reg, base + 0x50);
}
return 0;
}
