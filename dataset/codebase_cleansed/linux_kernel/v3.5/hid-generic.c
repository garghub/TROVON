static int __init hid_init(void)
{
return hid_register_driver(&hid_generic);
}
static void __exit hid_exit(void)
{
hid_unregister_driver(&hid_generic);
}
