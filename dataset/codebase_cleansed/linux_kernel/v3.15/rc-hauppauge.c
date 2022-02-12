static int __init init_rc_map_rc5_hauppauge_new(void)
{
return rc_map_register(&rc5_hauppauge_new_map);
}
static void __exit exit_rc_map_rc5_hauppauge_new(void)
{
rc_map_unregister(&rc5_hauppauge_new_map);
}
