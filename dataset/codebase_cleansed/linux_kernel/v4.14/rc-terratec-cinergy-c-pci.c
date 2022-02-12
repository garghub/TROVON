static int __init init_rc_map_terratec_cinergy_c_pci(void)
{
return rc_map_register(&terratec_cinergy_c_pci_map);
}
static void __exit exit_rc_map_terratec_cinergy_c_pci(void)
{
rc_map_unregister(&terratec_cinergy_c_pci_map);
}
