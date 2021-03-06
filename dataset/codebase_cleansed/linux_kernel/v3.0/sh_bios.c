static inline long sh_bios_call(long func, long arg0, long arg1, long arg2,
long arg3)
{
register long r0 __asm__("r0") = func;
register long r4 __asm__("r4") = arg0;
register long r5 __asm__("r5") = arg1;
register long r6 __asm__("r6") = arg2;
register long r7 __asm__("r7") = arg3;
if (!gdb_vbr_vector)
return -ENOSYS;
__asm__ __volatile__("trapa #0x3f":"=z"(r0)
:"0"(r0), "r"(r4), "r"(r5), "r"(r6), "r"(r7)
:"memory");
return r0;
}
void sh_bios_console_write(const char *buf, unsigned int len)
{
sh_bios_call(BIOS_CALL_CONSOLE_WRITE, (long)buf, (long)len, 0, 0);
}
void sh_bios_gdb_detach(void)
{
sh_bios_call(BIOS_CALL_GDB_DETACH, 0, 0, 0, 0);
}
void sh_bios_get_node_addr(unsigned char *node_addr)
{
sh_bios_call(BIOS_CALL_ETH_NODE_ADDR, 0, (long)node_addr, 0, 0);
}
void sh_bios_shutdown(unsigned int how)
{
sh_bios_call(BIOS_CALL_SHUTDOWN, how, 0, 0, 0);
}
void sh_bios_vbr_init(void)
{
unsigned long vbr;
if (unlikely(gdb_vbr_vector))
return;
__asm__ __volatile__ ("stc vbr, %0" : "=r" (vbr));
if (vbr) {
gdb_vbr_vector = (void *)(vbr + 0x100);
printk(KERN_NOTICE "Setting GDB trap vector to %p\n",
gdb_vbr_vector);
} else
printk(KERN_NOTICE "SH-BIOS not detected\n");
}
void sh_bios_vbr_reload(void)
{
if (gdb_vbr_vector)
__asm__ __volatile__ (
"ldc %0, vbr"
:
: "r" (((unsigned long) gdb_vbr_vector) - 0x100)
: "memory"
);
}
static void sh_console_write(struct console *co, const char *s,
unsigned count)
{
sh_bios_console_write(s, count);
}
static int __init sh_console_setup(struct console *co, char *options)
{
int cflag = CREAD | HUPCL | CLOCAL;
cflag |= B115200 | CS8 | 0;
co->cflag = cflag;
return 0;
}
static int __init setup_early_printk(char *buf)
{
int keep_early = 0;
if (!buf)
return 0;
if (strstr(buf, "keep"))
keep_early = 1;
if (!strncmp(buf, "bios", 4))
early_console = &bios_console;
if (likely(early_console)) {
if (keep_early)
early_console->flags &= ~CON_BOOT;
else
early_console->flags |= CON_BOOT;
register_console(early_console);
}
return 0;
}
