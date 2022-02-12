static int __init init_rc_map_adstech_dvb_t_pci(void)
{
return rc_map_register(&adstech_dvb_t_pci_map);
}
static void __exit exit_rc_map_adstech_dvb_t_pci(void)
{
rc_map_unregister(&adstech_dvb_t_pci_map);
}
