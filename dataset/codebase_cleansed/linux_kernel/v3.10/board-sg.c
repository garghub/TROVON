static void __init sg_init(void)
{
ks8695_add_device_lan();
ks8695_add_device_wan();
if (machine_is_sg310())
platform_device_register(&sg_mtd_device);
}
