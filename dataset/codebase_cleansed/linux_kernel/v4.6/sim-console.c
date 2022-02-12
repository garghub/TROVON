static void sim_write(struct console *con, const char *s, unsigned n)
{
register const int fd __asm__("er0") = 1;
register const char *_ptr __asm__("er1") = s;
register const unsigned _len __asm__("er2") = n;
__asm__(".byte 0x5e,0x00,0x00,0xc7\n\t"
: : "g"(fd), "g"(_ptr), "g"(_len));
}
static int __init sim_setup(struct earlycon_device *device, const char *opt)
{
device->con->write = sim_write;
return 0;
}
