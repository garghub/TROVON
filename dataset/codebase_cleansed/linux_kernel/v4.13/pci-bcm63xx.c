static u32 bcm63xx_int_cfg_readl(u32 reg)
{
u32 tmp;
tmp = reg & MPI_PCICFGCTL_CFGADDR_MASK;
tmp |= MPI_PCICFGCTL_WRITEEN_MASK;
bcm_mpi_writel(tmp, MPI_PCICFGCTL_REG);
iob();
return bcm_mpi_readl(MPI_PCICFGDATA_REG);
}
static void bcm63xx_int_cfg_writel(u32 val, u32 reg)
{
u32 tmp;
tmp = reg & MPI_PCICFGCTL_CFGADDR_MASK;
tmp |= MPI_PCICFGCTL_WRITEEN_MASK;
bcm_mpi_writel(tmp, MPI_PCICFGCTL_REG);
bcm_mpi_writel(val, MPI_PCICFGDATA_REG);
}
static void __init bcm63xx_reset_pcie(void)
{
u32 val;
u32 reg;
if (BCMCPU_IS_6328())
reg = MISC_SERDES_CTRL_6328_REG;
else
reg = MISC_SERDES_CTRL_6362_REG;
val = bcm_misc_readl(reg);
val |= SERDES_PCIE_EN | SERDES_PCIE_EXD_EN;
bcm_misc_writel(val, reg);
bcm63xx_core_set_reset(BCM63XX_RESET_PCIE, 1);
bcm63xx_core_set_reset(BCM63XX_RESET_PCIE_EXT, 1);
mdelay(10);
bcm63xx_core_set_reset(BCM63XX_RESET_PCIE, 0);
mdelay(10);
bcm63xx_core_set_reset(BCM63XX_RESET_PCIE_EXT, 0);
mdelay(200);
}
static int __init bcm63xx_register_pcie(void)
{
u32 val;
pcie_clk = clk_get(NULL, "pcie");
if (IS_ERR_OR_NULL(pcie_clk))
return -ENODEV;
clk_prepare_enable(pcie_clk);
bcm63xx_reset_pcie();
val = bcm_pcie_readl(PCIE_BRIDGE_OPT1_REG);
val |= OPT1_RD_BE_OPT_EN;
val |= OPT1_RD_REPLY_BE_FIX_EN;
val |= OPT1_PCIE_BRIDGE_HOLE_DET_EN;
val |= OPT1_L1_INT_STATUS_MASK_POL;
bcm_pcie_writel(val, PCIE_BRIDGE_OPT1_REG);
val = bcm_pcie_readl(PCIE_BRIDGE_RC_INT_MASK_REG);
val |= PCIE_RC_INT_A | PCIE_RC_INT_B | PCIE_RC_INT_C | PCIE_RC_INT_D;
bcm_pcie_writel(val, PCIE_BRIDGE_RC_INT_MASK_REG);
val = bcm_pcie_readl(PCIE_BRIDGE_OPT2_REG);
val |= OPT2_TX_CREDIT_CHK_EN;
val |= OPT2_UBUS_UR_DECODE_DIS;
val |= (PCIE_BUS_DEVICE << OPT2_CFG_TYPE1_BUS_NO_SHIFT);
val |= OPT2_CFG_TYPE1_BD_SEL;
bcm_pcie_writel(val, PCIE_BRIDGE_OPT2_REG);
val = bcm_pcie_readl(PCIE_IDVAL3_REG);
val &= ~IDVAL3_CLASS_CODE_MASK;
val |= (PCI_CLASS_BRIDGE_PCI << IDVAL3_SUBCLASS_SHIFT);
bcm_pcie_writel(val, PCIE_IDVAL3_REG);
val = bcm_pcie_readl(PCIE_CONFIG2_REG);
val &= ~CONFIG2_BAR1_SIZE_MASK;
bcm_pcie_writel(val, PCIE_CONFIG2_REG);
val = (BCM_PCIE_MEM_BASE_PA >> 20) << BASEMASK_BASE_SHIFT;
val |= (BCM_PCIE_MEM_BASE_PA >> 20) << BASEMASK_MASK_SHIFT;
val |= BASEMASK_REMAP_EN;
bcm_pcie_writel(val, PCIE_BRIDGE_BAR0_BASEMASK_REG);
val = (BCM_PCIE_MEM_BASE_PA >> 20) << REBASE_ADDR_BASE_SHIFT;
bcm_pcie_writel(val, PCIE_BRIDGE_BAR0_REBASE_ADDR_REG);
register_pci_controller(&bcm63xx_pcie_controller);
return 0;
}
static int __init bcm63xx_register_pci(void)
{
unsigned int mem_size;
u32 val;
pci_iospace_start = ioremap_nocache(BCM_PCI_IO_BASE_PA, 4);
if (!pci_iospace_start)
return -ENOMEM;
val = BCM_PCI_MEM_BASE_PA & MPI_L2P_BASE_MASK;
bcm_mpi_writel(val, MPI_L2PMEMBASE1_REG);
bcm_mpi_writel(~(BCM_PCI_MEM_SIZE - 1), MPI_L2PMEMRANGE1_REG);
bcm_mpi_writel(val | MPI_L2PREMAP_ENABLED_MASK, MPI_L2PMEMREMAP1_REG);
val = bcm_pcmcia_readl(PCMCIA_C1_REG);
val &= ~PCMCIA_C1_CBIDSEL_MASK;
val |= (CARDBUS_PCI_IDSEL << PCMCIA_C1_CBIDSEL_SHIFT);
bcm_pcmcia_writel(val, PCMCIA_C1_REG);
#ifdef CONFIG_CARDBUS
val = BCM_CB_MEM_BASE_PA & MPI_L2P_BASE_MASK;
bcm_mpi_writel(val, MPI_L2PMEMBASE2_REG);
bcm_mpi_writel(~(BCM_CB_MEM_SIZE - 1), MPI_L2PMEMRANGE2_REG);
val |= MPI_L2PREMAP_ENABLED_MASK | MPI_L2PREMAP_IS_CARDBUS_MASK;
bcm_mpi_writel(val, MPI_L2PMEMREMAP2_REG);
#else
bcm_mpi_writel(0, MPI_L2PMEMREMAP2_REG);
#endif
val = BCM_PCI_IO_BASE_PA & MPI_L2P_BASE_MASK;
bcm_mpi_writel(val, MPI_L2PIOBASE_REG);
bcm_mpi_writel(~(BCM_PCI_IO_SIZE - 1), MPI_L2PIORANGE_REG);
bcm_mpi_writel(val | MPI_L2PREMAP_ENABLED_MASK, MPI_L2PIOREMAP_REG);
bcm_mpi_writel(MPI_LOCBUSCTL_EN_PCI_GPIO_MASK, MPI_LOCBUSCTL_REG);
bcm63xx_int_cfg_writel(0, PCI_BASE_ADDRESS_3);
if (BCMCPU_IS_3368() || BCMCPU_IS_6358() || BCMCPU_IS_6368())
val = MPI_SP0_REMAP_ENABLE_MASK;
else
val = 0;
bcm_mpi_writel(val, MPI_SP0_REMAP_REG);
bcm63xx_int_cfg_writel(0x0, PCI_BASE_ADDRESS_4);
bcm_mpi_writel(0, MPI_SP1_REMAP_REG);
mem_size = bcm63xx_get_memory_size();
if (BCMCPU_IS_6348() && (bcm63xx_get_cpu_rev() & 0xf0) == 0xa0) {
if (mem_size > (16 * 1024 * 1024))
printk(KERN_WARNING "bcm63xx: this CPU "
"revision cannot handle more than 16MB "
"of RAM for PCI bus mastering\n");
} else {
bcm_mpi_writel(~(mem_size - 1), MPI_SP0_RANGE_REG);
bcm_mpi_writel(0, MPI_SP1_RANGE_REG);
}
val = bcm63xx_int_cfg_readl(BCMPCI_REG_TIMERS);
val &= ~REG_TIMER_RETRY_MASK;
bcm63xx_int_cfg_writel(val, BCMPCI_REG_TIMERS);
val = bcm63xx_int_cfg_readl(PCI_COMMAND);
val |= (PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER);
bcm63xx_int_cfg_writel(val, PCI_COMMAND);
val = bcm_mpi_readl(MPI_PCIMODESEL_REG);
val &= ~MPI_PCIMODESEL_BAR1_NOSWAP_MASK;
val &= ~MPI_PCIMODESEL_BAR2_NOSWAP_MASK;
val &= ~MPI_PCIMODESEL_PREFETCH_MASK;
val |= (8 << MPI_PCIMODESEL_PREFETCH_SHIFT);
bcm_mpi_writel(val, MPI_PCIMODESEL_REG);
val = bcm_mpi_readl(MPI_LOCINT_REG);
val |= MPI_LOCINT_MASK(MPI_LOCINT_EXT_PCI_INT);
bcm_mpi_writel(val, MPI_LOCINT_REG);
register_pci_controller(&bcm63xx_controller);
#ifdef CONFIG_CARDBUS
register_pci_controller(&bcm63xx_cb_controller);
#endif
request_mem_region(BCM_PCI_IO_BASE_PA, BCM_PCI_IO_SIZE,
"bcm63xx PCI IO space");
return 0;
}
static int __init bcm63xx_pci_init(void)
{
if (!bcm63xx_pci_enabled)
return -ENODEV;
switch (bcm63xx_get_cpu_id()) {
case BCM6328_CPU_ID:
case BCM6362_CPU_ID:
return bcm63xx_register_pcie();
case BCM3368_CPU_ID:
case BCM6348_CPU_ID:
case BCM6358_CPU_ID:
case BCM6368_CPU_ID:
return bcm63xx_register_pci();
default:
return -ENODEV;
}
}
