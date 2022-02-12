static void sim_write(struct console *co, const char *ptr,
unsigned len)
{
register const int fd __asm__("er0") = 1;
register const char *_ptr __asm__("er1") = ptr;
register const unsigned _len __asm__("er2") = len;
__asm__(".byte 0x5e,0x00,0x00,0xc7\n\t"
: : "g"(fd), "g"(_ptr), "g"(_len));
}
static int sim_probe(struct platform_device *pdev)
{
if (sim_console.data)
return -EEXIST;
if (!strstr(sim_console_buf, "keep"))
sim_console.flags |= CON_BOOT;
register_console(&sim_console);
return 0;
}
static int sim_remove(struct platform_device *pdev)
{
return 0;
}
void __init sim_console_register(void)
{
early_platform_add_devices(devices,
ARRAY_SIZE(devices));
}
