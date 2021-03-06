void __init udbg_early_init(void)
{
#if defined(CONFIG_PPC_EARLY_DEBUG_LPAR)
udbg_init_debug_lpar();
#elif defined(CONFIG_PPC_EARLY_DEBUG_LPAR_HVSI)
udbg_init_debug_lpar_hvsi();
#elif defined(CONFIG_PPC_EARLY_DEBUG_G5)
udbg_init_pmac_realmode();
#elif defined(CONFIG_PPC_EARLY_DEBUG_RTAS_PANEL)
udbg_init_rtas_panel();
#elif defined(CONFIG_PPC_EARLY_DEBUG_RTAS_CONSOLE)
udbg_init_rtas_console();
#elif defined(CONFIG_PPC_EARLY_DEBUG_MAPLE)
udbg_init_maple_realmode();
#elif defined(CONFIG_PPC_EARLY_DEBUG_BEAT)
udbg_init_debug_beat();
#elif defined(CONFIG_PPC_EARLY_DEBUG_PAS_REALMODE)
udbg_init_pas_realmode();
#elif defined(CONFIG_BOOTX_TEXT)
udbg_init_btext();
#elif defined(CONFIG_PPC_EARLY_DEBUG_44x)
udbg_init_44x_as1();
#elif defined(CONFIG_PPC_EARLY_DEBUG_40x)
udbg_init_40x_realmode();
#elif defined(CONFIG_PPC_EARLY_DEBUG_CPM)
udbg_init_cpm();
#elif defined(CONFIG_PPC_EARLY_DEBUG_USBGECKO)
udbg_init_usbgecko();
#elif defined(CONFIG_PPC_EARLY_DEBUG_WSP)
udbg_init_wsp();
#elif defined(CONFIG_PPC_EARLY_DEBUG_MEMCONS)
udbg_init_memcons();
#elif defined(CONFIG_PPC_EARLY_DEBUG_EHV_BC)
udbg_init_ehv_bc();
#elif defined(CONFIG_PPC_EARLY_DEBUG_PS3GELIC)
udbg_init_ps3gelic();
#elif defined(CONFIG_PPC_EARLY_DEBUG_OPAL_RAW)
udbg_init_debug_opal_raw();
#elif defined(CONFIG_PPC_EARLY_DEBUG_OPAL_HVSI)
udbg_init_debug_opal_hvsi();
#endif
#ifdef CONFIG_PPC_EARLY_DEBUG
console_loglevel = 10;
register_early_udbg_console();
#endif
}
void udbg_puts(const char *s)
{
if (udbg_putc) {
char c;
if (s && *s != '\0') {
while ((c = *s++) != '\0')
udbg_putc(c);
}
if (udbg_flush)
udbg_flush();
}
#if 0
else {
printk("%s", s);
}
#endif
}
int udbg_write(const char *s, int n)
{
int remain = n;
char c;
if (!udbg_putc)
return 0;
if (s && *s != '\0') {
while (((c = *s++) != '\0') && (remain-- > 0)) {
udbg_putc(c);
}
}
if (udbg_flush)
udbg_flush();
return n - remain;
}
void udbg_printf(const char *fmt, ...)
{
char buf[UDBG_BUFSIZE];
va_list args;
va_start(args, fmt);
vsnprintf(buf, UDBG_BUFSIZE, fmt, args);
udbg_puts(buf);
va_end(args);
}
void __init udbg_progress(char *s, unsigned short hex)
{
udbg_puts(s);
udbg_puts("\n");
}
static void udbg_console_write(struct console *con, const char *s,
unsigned int n)
{
udbg_write(s, n);
}
void __init register_early_udbg_console(void)
{
if (early_console)
return;
if (!udbg_putc)
return;
if (strstr(boot_command_line, "udbg-immortal")) {
printk(KERN_INFO "early console immortal !\n");
udbg_console.flags &= ~CON_BOOT;
}
early_console = &udbg_console;
register_console(&udbg_console);
}
