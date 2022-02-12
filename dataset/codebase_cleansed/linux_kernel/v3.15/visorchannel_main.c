static int __init
visorchannel_init(void)
{
INFODRV("driver version %s loaded", VERSION);
return 0;
}
static void
visorchannel_exit(void)
{
INFODRV("driver unloaded");
}
