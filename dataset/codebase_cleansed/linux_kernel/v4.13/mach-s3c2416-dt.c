static void __init s3c2416_dt_map_io(void)
{
s3c24xx_init_io(NULL, 0);
}
static void __init s3c2416_dt_machine_init(void)
{
s3c_pm_init();
}
