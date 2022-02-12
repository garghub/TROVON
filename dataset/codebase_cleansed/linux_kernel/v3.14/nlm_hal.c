void nlm_node_init(int node)
{
struct nlm_soc_info *nodep;
nodep = nlm_get_node(node);
nodep->sysbase = nlm_get_sys_regbase(node);
nodep->picbase = nlm_get_pic_regbase(node);
nodep->ebase = read_c0_ebase() & (~((1 << 12) - 1));
if (cpu_is_xlp9xx())
nodep->socbus = xlp9xx_get_socbus(node);
else
nodep->socbus = 0;
spin_lock_init(&nodep->piclock);
}
int nlm_irq_to_irt(int irq)
{
uint64_t pcibase;
int devoff, irt;
if (cpu_is_xlp9xx()) {
switch (irq) {
case PIC_9XX_XHCI_0_IRQ:
return 114;
case PIC_9XX_XHCI_1_IRQ:
return 115;
case PIC_UART_0_IRQ:
return 133;
case PIC_UART_1_IRQ:
return 134;
case PIC_PCIE_LINK_LEGACY_IRQ(0):
case PIC_PCIE_LINK_LEGACY_IRQ(1):
case PIC_PCIE_LINK_LEGACY_IRQ(2):
case PIC_PCIE_LINK_LEGACY_IRQ(3):
return 191 + irq - PIC_PCIE_LINK_LEGACY_IRQ_BASE;
}
return -1;
}
devoff = 0;
switch (irq) {
case PIC_UART_0_IRQ:
devoff = XLP_IO_UART0_OFFSET(0);
break;
case PIC_UART_1_IRQ:
devoff = XLP_IO_UART1_OFFSET(0);
break;
case PIC_MMC_IRQ:
devoff = XLP_IO_SD_OFFSET(0);
break;
case PIC_I2C_0_IRQ:
case PIC_I2C_1_IRQ:
case PIC_I2C_2_IRQ:
case PIC_I2C_3_IRQ:
if (cpu_is_xlpii())
devoff = XLP2XX_IO_I2C_OFFSET(0);
else
devoff = XLP_IO_I2C0_OFFSET(0);
break;
default:
if (cpu_is_xlpii()) {
switch (irq) {
case PIC_2XX_XHCI_0_IRQ:
devoff = XLP2XX_IO_USB_XHCI0_OFFSET(0);
break;
case PIC_2XX_XHCI_1_IRQ:
devoff = XLP2XX_IO_USB_XHCI1_OFFSET(0);
break;
case PIC_2XX_XHCI_2_IRQ:
devoff = XLP2XX_IO_USB_XHCI2_OFFSET(0);
break;
}
} else {
switch (irq) {
case PIC_EHCI_0_IRQ:
devoff = XLP_IO_USB_EHCI0_OFFSET(0);
break;
case PIC_EHCI_1_IRQ:
devoff = XLP_IO_USB_EHCI1_OFFSET(0);
break;
case PIC_OHCI_0_IRQ:
devoff = XLP_IO_USB_OHCI0_OFFSET(0);
break;
case PIC_OHCI_1_IRQ:
devoff = XLP_IO_USB_OHCI1_OFFSET(0);
break;
case PIC_OHCI_2_IRQ:
devoff = XLP_IO_USB_OHCI2_OFFSET(0);
break;
case PIC_OHCI_3_IRQ:
devoff = XLP_IO_USB_OHCI3_OFFSET(0);
break;
}
}
}
if (devoff != 0) {
pcibase = nlm_pcicfg_base(devoff);
irt = nlm_read_reg(pcibase, XLP_PCI_IRTINFO_REG) & 0xffff;
switch (irq) {
case PIC_I2C_1_IRQ:
irt = irt + 1; break;
case PIC_I2C_2_IRQ:
irt = irt + 2; break;
case PIC_I2C_3_IRQ:
irt = irt + 3; break;
}
} else if (irq >= PIC_PCIE_LINK_LEGACY_IRQ(0) &&
irq <= PIC_PCIE_LINK_LEGACY_IRQ(3)) {
irt = PIC_IRT_PCIE_LINK_INDEX(irq -
PIC_PCIE_LINK_LEGACY_IRQ_BASE);
} else if (irq >= PIC_PCIE_LINK_MSI_IRQ(0) &&
irq <= PIC_PCIE_LINK_MSI_IRQ(3)) {
irt = -2;
} else if (irq >= PIC_PCIE_MSIX_IRQ(0) &&
irq <= PIC_PCIE_MSIX_IRQ(3)) {
irt = -2;
} else {
irt = -1;
}
return irt;
}
unsigned int nlm_get_core_frequency(int node, int core)
{
unsigned int pll_divf, pll_divr, dfs_div, ext_div;
unsigned int rstval, dfsval, denom;
uint64_t num, sysbase;
sysbase = nlm_get_node(node)->sysbase;
if (cpu_is_xlp9xx())
rstval = nlm_read_sys_reg(sysbase, SYS_9XX_POWER_ON_RESET_CFG);
else
rstval = nlm_read_sys_reg(sysbase, SYS_POWER_ON_RESET_CFG);
if (cpu_is_xlpii()) {
num = 1000000ULL * (400 * 3 + 100 * (rstval >> 26));
denom = 3;
} else {
dfsval = nlm_read_sys_reg(sysbase, SYS_CORE_DFS_DIV_VALUE);
pll_divf = ((rstval >> 10) & 0x7f) + 1;
pll_divr = ((rstval >> 8) & 0x3) + 1;
ext_div = ((rstval >> 30) & 0x3) + 1;
dfs_div = ((dfsval >> (core * 4)) & 0xf) + 1;
num = 800000000ULL * pll_divf;
denom = 3 * pll_divr * ext_div * dfs_div;
}
do_div(num, denom);
return (unsigned int)num;
}
static unsigned int nlm_2xx_get_pic_frequency(int node)
{
u32 ctrl_val0, ctrl_val2, vco_post_div, pll_post_div;
u32 mdiv, fdiv, pll_out_freq_den, reg_select, ref_div, pic_div;
u64 ref_clk, sysbase, pll_out_freq_num, ref_clk_select;
sysbase = nlm_get_node(node)->sysbase;
ref_clk_select =
(nlm_read_sys_reg(sysbase, SYS_POWER_ON_RESET_CFG) >> 18) & 0x3;
switch (ref_clk_select) {
case 0:
ref_clk = 200000000ULL;
ref_div = 3;
break;
case 1:
ref_clk = 100000000ULL;
ref_div = 1;
break;
case 2:
ref_clk = 125000000ULL;
ref_div = 1;
break;
case 3:
ref_clk = 400000000ULL;
ref_div = 3;
break;
}
reg_select = (nlm_read_sys_reg(sysbase, SYS_CLK_DEV_SEL) >> 22) & 0x3;
switch (reg_select) {
case 0:
ctrl_val0 = nlm_read_sys_reg(sysbase, SYS_PLL_CTRL0);
ctrl_val2 = nlm_read_sys_reg(sysbase, SYS_PLL_CTRL2);
break;
case 1:
ctrl_val0 = nlm_read_sys_reg(sysbase, SYS_PLL_CTRL0_DEVX(0));
ctrl_val2 = nlm_read_sys_reg(sysbase, SYS_PLL_CTRL2_DEVX(0));
break;
case 2:
ctrl_val0 = nlm_read_sys_reg(sysbase, SYS_PLL_CTRL0_DEVX(1));
ctrl_val2 = nlm_read_sys_reg(sysbase, SYS_PLL_CTRL2_DEVX(1));
break;
case 3:
ctrl_val0 = nlm_read_sys_reg(sysbase, SYS_PLL_CTRL0_DEVX(2));
ctrl_val2 = nlm_read_sys_reg(sysbase, SYS_PLL_CTRL2_DEVX(2));
break;
}
vco_post_div = (ctrl_val0 >> 5) & 0x7;
pll_post_div = (ctrl_val0 >> 24) & 0x7;
mdiv = ctrl_val2 & 0xff;
fdiv = (ctrl_val2 >> 8) & 0xfff;
switch (pll_post_div) {
case 1:
pll_post_div = 2;
break;
case 3:
pll_post_div = 4;
break;
case 7:
pll_post_div = 8;
break;
case 6:
pll_post_div = 16;
break;
case 0:
default:
pll_post_div = 1;
break;
}
fdiv = fdiv/(1 << 13);
pll_out_freq_num = ((ref_clk >> 1) * (6 + mdiv)) + fdiv;
pll_out_freq_den = (1 << vco_post_div) * pll_post_div * 3;
if (pll_out_freq_den > 0)
do_div(pll_out_freq_num, pll_out_freq_den);
pic_div = (nlm_read_sys_reg(sysbase, SYS_CLK_DEV_DIV) >> 22) & 0x3;
do_div(pll_out_freq_num, 1 << pic_div);
return pll_out_freq_num;
}
unsigned int nlm_get_pic_frequency(int node)
{
if (cpu_is_xlp9xx())
return 250000000;
if (cpu_is_xlpii())
return nlm_2xx_get_pic_frequency(node);
else
return 133333333;
}
unsigned int nlm_get_cpu_frequency(void)
{
return nlm_get_core_frequency(0, 0);
}
int xlp_get_dram_map(int n, uint64_t *dram_map)
{
uint64_t bridgebase, base, lim;
uint32_t val;
unsigned int barreg, limreg, xlatreg;
int i, node, rv;
bridgebase = nlm_get_bridge_regbase(0);
rv = 0;
for (i = 0; i < 8; i++) {
if (cpu_is_xlp9xx()) {
barreg = BRIDGE_9XX_DRAM_BAR(i);
limreg = BRIDGE_9XX_DRAM_LIMIT(i);
xlatreg = BRIDGE_9XX_DRAM_NODE_TRANSLN(i);
} else {
barreg = BRIDGE_DRAM_BAR(i);
limreg = BRIDGE_DRAM_LIMIT(i);
xlatreg = BRIDGE_DRAM_NODE_TRANSLN(i);
}
if (n >= 0) {
val = nlm_read_bridge_reg(bridgebase, xlatreg);
node = (val >> 1) & 0x3;
if (n != node)
continue;
}
val = nlm_read_bridge_reg(bridgebase, barreg);
val = (val >> 12) & 0xfffff;
base = (uint64_t) val << 20;
val = nlm_read_bridge_reg(bridgebase, limreg);
val = (val >> 12) & 0xfffff;
if (val == 0)
continue;
lim = ((uint64_t)val + 1) << 20;
dram_map[rv] = base;
dram_map[rv + 1] = lim;
rv += 2;
}
return rv;
}
