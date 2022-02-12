static int __init
visorchannel_init(void)
{
if (!unisys_spar_platform)
return -ENODEV;
return 0;
}
static void
visorchannel_exit(void)
{
}
