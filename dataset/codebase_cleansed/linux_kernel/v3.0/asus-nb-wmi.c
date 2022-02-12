static int __init asus_nb_wmi_init(void)
{
return asus_wmi_register_driver(&asus_nb_wmi_driver);
}
static void __exit asus_nb_wmi_exit(void)
{
asus_wmi_unregister_driver(&asus_nb_wmi_driver);
}
