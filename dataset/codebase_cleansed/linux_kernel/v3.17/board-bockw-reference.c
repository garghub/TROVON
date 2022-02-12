static void __init bockw_init(void)
{
void __iomem *fpga;
void __iomem *pfc;
r8a7778_clock_init();
r8a7778_init_irq_extpin_dt(1);
r8a7778_add_dt_devices();
fpga = ioremap_nocache(FPGA, SZ_1M);
if (fpga) {
u16 val = ioread16(fpga + IRQ0MR);
val &= ~(1 << 4);
iowrite16(val, fpga + IRQ0MR);
iounmap(fpga);
}
pfc = ioremap_nocache(PFC, 0x200);
if (pfc) {
iowrite32(ioread32(pfc + PUPR4) | (3 << 26), pfc + PUPR4);
iounmap(pfc);
}
of_platform_populate(NULL, of_default_bus_match_table, NULL, NULL);
}
