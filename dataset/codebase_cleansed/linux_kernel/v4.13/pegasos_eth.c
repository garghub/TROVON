static int Enable_SRAM(void)
{
u32 ALong;
if (mv643xx_reg_base == NULL)
mv643xx_reg_base = ioremap(PEGASOS2_MARVELL_REGBASE,
PEGASOS2_MARVELL_REGSIZE);
if (mv643xx_reg_base == NULL)
return -ENOMEM;
#ifdef BE_VERBOSE
printk("Pegasos II/Marvell MV64361: register remapped from %p to %p\n",
(void *)PEGASOS2_MARVELL_REGBASE, (void *)mv643xx_reg_base);
#endif
MV_WRITE(MV64340_SRAM_CONFIG, 0);
MV_WRITE(MV64340_INTEGRATED_SRAM_BASE_ADDR, PEGASOS2_SRAM_BASE >> 16);
MV_READ(MV64340_BASE_ADDR_ENABLE, ALong);
ALong &= ~(1 << 19);
MV_WRITE(MV64340_BASE_ADDR_ENABLE, ALong);
ALong = 0x02;
ALong |= PEGASOS2_SRAM_BASE & 0xffff0000;
MV_WRITE(MV643XX_ETH_BAR_4, ALong);
MV_WRITE(MV643XX_ETH_SIZE_REG_4, (PEGASOS2_SRAM_SIZE-1) & 0xffff0000);
MV_READ(MV643XX_ETH_BASE_ADDR_ENABLE_REG, ALong);
ALong &= ~(1 << 4);
MV_WRITE(MV643XX_ETH_BASE_ADDR_ENABLE_REG, ALong);
#ifdef BE_VERBOSE
printk("Pegasos II/Marvell MV64361: register unmapped\n");
printk("Pegasos II/Marvell MV64361: SRAM at %p, size=%x\n", (void*) PEGASOS2_SRAM_BASE, PEGASOS2_SRAM_SIZE);
#endif
iounmap(mv643xx_reg_base);
mv643xx_reg_base = NULL;
return 1;
}
static int __init mv643xx_eth_add_pds(void)
{
int ret = 0;
static struct pci_device_id pci_marvell_mv64360[] = {
{ PCI_DEVICE(PCI_VENDOR_ID_MARVELL, PCI_DEVICE_ID_MARVELL_MV64360) },
{ }
};
#ifdef BE_VERBOSE
printk("Pegasos II/Marvell MV64361: init\n");
#endif
if (pci_dev_present(pci_marvell_mv64360)) {
ret = platform_add_devices(mv643xx_eth_pd_devs,
ARRAY_SIZE(mv643xx_eth_pd_devs));
if ( Enable_SRAM() < 0)
{
eth_port1_pd.tx_sram_addr = 0;
eth_port1_pd.tx_sram_size = 0;
eth_port1_pd.rx_sram_addr = 0;
eth_port1_pd.rx_sram_size = 0;
#ifdef BE_VERBOSE
printk("Pegasos II/Marvell MV64361: Can't enable the "
"SRAM\n");
#endif
}
}
#ifdef BE_VERBOSE
printk("Pegasos II/Marvell MV64361: init is over\n");
#endif
return ret;
}
