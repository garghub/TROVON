void __init device_tree_init(void)
{
unflatten_and_copy_device_tree();
}
static int __init publish_devices(void)
{
if (!of_have_populated_dt())
return 0;
return of_platform_bus_probe(NULL, bus_ids, NULL);
}
