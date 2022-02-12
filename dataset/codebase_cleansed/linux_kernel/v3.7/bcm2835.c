void __init bcm2835_map_io(void)
{
iotable_init(&io_map, 1);
}
void __init bcm2835_init(void)
{
int ret;
bcm2835_init_clocks();
ret = of_platform_populate(NULL, of_default_bus_match_table, NULL,
NULL);
if (ret) {
pr_err("of_platform_populate failed: %d\n", ret);
BUG();
}
}
