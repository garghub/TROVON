static void __init bockw_init(void)
{
void __iomem *fpga;
r8a7778_clock_init();
r8a7778_init_irq_extpin(1);
r8a7778_add_standard_devices();
fpga = ioremap_nocache(0x18200000, SZ_1M);
if (fpga) {
u16 val = ioread16(fpga + IRQ0MR);
val &= ~(1 << 4);
iowrite16(val, fpga + IRQ0MR);
iounmap(fpga);
platform_device_register_resndata(
&platform_bus, "smsc911x", -1,
smsc911x_resources, ARRAY_SIZE(smsc911x_resources),
&smsc911x_data, sizeof(smsc911x_data));
}
}
