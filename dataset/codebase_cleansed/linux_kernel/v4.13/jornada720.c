static int __init jornada720_init(void)
{
int ret = -ENODEV;
if (machine_is_jornada720()) {
GPDR |= GPIO_GPIO20;
TUCR = TUCR_VAL;
GPSR = GPIO_GPIO20;
udelay(1);
GPCR = GPIO_GPIO20;
udelay(1);
GPSR = GPIO_GPIO20;
udelay(20);
gpiod_add_lookup_table(&jornada_ts_gpiod_table);
ret = platform_add_devices(devices, ARRAY_SIZE(devices));
}
return ret;
}
static void __init jornada720_map_io(void)
{
sa1100_map_io();
iotable_init(jornada720_io_desc, ARRAY_SIZE(jornada720_io_desc));
sa1100_register_uart(0, 3);
sa1100_register_uart(1, 1);
}
static void jornada720_set_vpp(int vpp)
{
if (vpp)
PPSR |= PPC_LDD7;
else
PPSR &= ~PPC_LDD7;
PPDR |= PPC_LDD7;
}
static void __init jornada720_mach_init(void)
{
sa11x0_register_mtd(&jornada720_flash_data, &jornada720_flash_resource, 1);
}
