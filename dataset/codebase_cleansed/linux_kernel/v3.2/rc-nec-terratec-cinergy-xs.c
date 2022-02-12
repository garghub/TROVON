static int __init init_rc_map_nec_terratec_cinergy_xs(void)
{
return rc_map_register(&nec_terratec_cinergy_xs_map);
}
static void __exit exit_rc_map_nec_terratec_cinergy_xs(void)
{
rc_map_unregister(&nec_terratec_cinergy_xs_map);
}
