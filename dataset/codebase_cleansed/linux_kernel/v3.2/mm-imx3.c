static void imx3_idle(void)
{
unsigned long reg = 0;
if (!need_resched())
__asm__ __volatile__(
"mrc p15, 0, %0, c1, c0, 0\n"
"bic %0, %0, #0x00001000\n"
"bic %0, %0, #0x00000004\n"
"mcr p15, 0, %0, c1, c0, 0\n"
"mov %0, #0\n"
"mcr p15, 0, %0, c7, c5, 0\n"
"mov %0, #0\n"
"mcr p15, 0, %0, c7, c14, 0\n"
"mov %0, #0\n"
"mcr p15, 0, %0, c7, c0, 4\n"
"nop\n" "nop\n" "nop\n" "nop\n"
"nop\n" "nop\n" "nop\n"
"mrc p15, 0, %0, c1, c0, 0\n"
"orr %0, %0, #0x00001000\n"
"orr %0, %0, #0x00000004\n"
"mcr p15, 0, %0, c1, c0, 0\n"
: "=r" (reg));
local_irq_enable();
}
static void __iomem *imx3_ioremap(unsigned long phys_addr, size_t size,
unsigned int mtype)
{
if (mtype == MT_DEVICE) {
if (phys_addr < 0x80000000 &&
!addr_in_module(phys_addr, MX3x_L2CC))
mtype = MT_DEVICE_NONSHARED;
}
return __arm_ioremap(phys_addr, size, mtype);
}
void imx3_init_l2x0(void)
{
void __iomem *l2x0_base;
void __iomem *clkctl_base;
#define L2_MEM_VAL 0x10
clkctl_base = ioremap(MX35_CLKCTL_BASE_ADDR, 4096);
if (clkctl_base != NULL) {
writel(0x00000515, clkctl_base + L2_MEM_VAL);
iounmap(clkctl_base);
} else {
pr_err("L2 cache: Cannot fix timing. Trying to continue without\n");
}
l2x0_base = ioremap(MX3x_L2CC_BASE_ADDR, 4096);
if (IS_ERR(l2x0_base)) {
printk(KERN_ERR "remapping L2 cache area failed with %ld\n",
PTR_ERR(l2x0_base));
return;
}
l2x0_init(l2x0_base, 0x00030024, 0x00000000);
}
void __init mx31_map_io(void)
{
iotable_init(mx31_io_desc, ARRAY_SIZE(mx31_io_desc));
}
void __init imx31_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX31);
mxc_arch_reset_init(MX31_IO_ADDRESS(MX31_WDOG_BASE_ADDR));
pm_idle = imx3_idle;
imx_ioremap = imx3_ioremap;
}
void __init mx31_init_irq(void)
{
mxc_init_irq(MX31_IO_ADDRESS(MX31_AVIC_BASE_ADDR));
}
void __init imx31_soc_init(void)
{
int to_version = mx31_revision() >> 4;
imx3_init_l2x0();
mxc_register_gpio("imx31-gpio", 0, MX31_GPIO1_BASE_ADDR, SZ_16K, MX31_INT_GPIO1, 0);
mxc_register_gpio("imx31-gpio", 1, MX31_GPIO2_BASE_ADDR, SZ_16K, MX31_INT_GPIO2, 0);
mxc_register_gpio("imx31-gpio", 2, MX31_GPIO3_BASE_ADDR, SZ_16K, MX31_INT_GPIO3, 0);
if (to_version == 1) {
strncpy(imx31_sdma_pdata.fw_name, "sdma-imx31-to1.bin",
strlen(imx31_sdma_pdata.fw_name));
imx31_sdma_pdata.script_addrs = &imx31_to1_sdma_script;
}
imx_add_imx_sdma("imx31-sdma", MX31_SDMA_BASE_ADDR, MX31_INT_SDMA, &imx31_sdma_pdata);
}
void __init mx35_map_io(void)
{
iotable_init(mx35_io_desc, ARRAY_SIZE(mx35_io_desc));
}
void __init imx35_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX35);
mxc_iomux_v3_init(MX35_IO_ADDRESS(MX35_IOMUXC_BASE_ADDR));
mxc_arch_reset_init(MX35_IO_ADDRESS(MX35_WDOG_BASE_ADDR));
pm_idle = imx3_idle;
imx_ioremap = imx3_ioremap;
}
void __init mx35_init_irq(void)
{
mxc_init_irq(MX35_IO_ADDRESS(MX35_AVIC_BASE_ADDR));
}
void __init imx35_soc_init(void)
{
int to_version = mx35_revision() >> 4;
imx3_init_l2x0();
mxc_register_gpio("imx31-gpio", 0, MX35_GPIO1_BASE_ADDR, SZ_16K, MX35_INT_GPIO1, 0);
mxc_register_gpio("imx31-gpio", 1, MX35_GPIO2_BASE_ADDR, SZ_16K, MX35_INT_GPIO2, 0);
mxc_register_gpio("imx31-gpio", 2, MX35_GPIO3_BASE_ADDR, SZ_16K, MX35_INT_GPIO3, 0);
if (to_version == 1) {
strncpy(imx35_sdma_pdata.fw_name, "sdma-imx35-to1.bin",
strlen(imx35_sdma_pdata.fw_name));
imx35_sdma_pdata.script_addrs = &imx35_to1_sdma_script;
}
imx_add_imx_sdma("imx35-sdma", MX35_SDMA_BASE_ADDR, MX35_INT_SDMA, &imx35_sdma_pdata);
}
