static void __init clps711x_map_io(void)
{
iotable_init(&clps711x_io_desc, 1);
}
static void __init clps711x_init(void)
{
u32 id[5];
id[0] = readl(CLPS711X_VIRT_BASE + UNIQID);
id[1] = readl(CLPS711X_VIRT_BASE + RANDID0);
id[2] = readl(CLPS711X_VIRT_BASE + RANDID1);
id[3] = readl(CLPS711X_VIRT_BASE + RANDID2);
id[4] = readl(CLPS711X_VIRT_BASE + RANDID3);
system_rev = SYSFLG1_VERID(readl(CLPS711X_VIRT_BASE + SYSFLG1));
add_device_randomness(id, sizeof(id));
system_serial_low = id[0];
platform_device_register_simple("clps711x-cpuidle", PLATFORM_DEVID_NONE,
&clps711x_cpuidle_res, 1);
}
static void clps711x_restart(enum reboot_mode mode, const char *cmd)
{
soft_restart(0);
}
