void nlm_node_init(int node)
{
struct nlm_soc_info *nodep;
nodep = nlm_get_node(node);
nodep->sysbase = nlm_get_sys_regbase(node);
nodep->picbase = nlm_get_pic_regbase(node);
nodep->ebase = read_c0_ebase() & (~((1 << 12) - 1));
spin_lock_init(&nodep->piclock);
}
int nlm_irq_to_irt(int irq)
{
uint64_t pcibase;
int devoff, irt;
switch (irq) {
case PIC_UART_0_IRQ:
devoff = XLP_IO_UART0_OFFSET(0);
break;
case PIC_UART_1_IRQ:
devoff = XLP_IO_UART1_OFFSET(0);
break;
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
case PIC_MMC_IRQ:
devoff = XLP_IO_SD_OFFSET(0);
break;
case PIC_I2C_0_IRQ:
devoff = XLP_IO_I2C0_OFFSET(0);
break;
case PIC_I2C_1_IRQ:
devoff = XLP_IO_I2C1_OFFSET(0);
break;
default:
devoff = 0;
break;
}
if (devoff != 0) {
pcibase = nlm_pcicfg_base(devoff);
irt = nlm_read_reg(pcibase, XLP_PCI_IRTINFO_REG) & 0xffff;
if (irq == PIC_I2C_1_IRQ)
irt = irt + 1;
} else if (irq >= PIC_PCIE_LINK_0_IRQ && irq <= PIC_PCIE_LINK_3_IRQ) {
irt = PIC_IRT_PCIE_LINK_INDEX(irq - PIC_PCIE_LINK_0_IRQ);
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
rstval = nlm_read_sys_reg(sysbase, SYS_POWER_ON_RESET_CFG);
dfsval = nlm_read_sys_reg(sysbase, SYS_CORE_DFS_DIV_VALUE);
pll_divf = ((rstval >> 10) & 0x7f) + 1;
pll_divr = ((rstval >> 8) & 0x3) + 1;
ext_div = ((rstval >> 30) & 0x3) + 1;
dfs_div = ((dfsval >> (core * 4)) & 0xf) + 1;
num = 800000000ULL * pll_divf;
denom = 3 * pll_divr * ext_div * dfs_div;
do_div(num, denom);
return (unsigned int)num;
}
unsigned int nlm_get_cpu_frequency(void)
{
return nlm_get_core_frequency(0, 0);
}
