static int __init sam440ep_device_probe(void)
{
of_platform_bus_probe(NULL, sam440ep_of_bus, NULL);
return 0;
}
static int __init sam440ep_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (!of_flat_dt_is_compatible(root, "acube,sam440ep"))
return 0;
ppc_pci_set_flags(PPC_PCI_REASSIGN_ALL_RSRC);
return 1;
}
static int sam440ep_setup_rtc(void)
{
return i2c_register_board_info(0, &sam440ep_rtc_info, 1);
}
