__init void early_shadow_write(struct console *con, const char *s,
unsigned int n)
{
unsigned int i;
if ((shadow_console_buffer + n) <= (char *)(SHADOW_CONSOLE_END - 2)) {
for (i = 0; i <= n; i++)
shadow_console_buffer[i] = s[i];
shadow_console_buffer += n;
shadow_console_buffer[0] = 0;
shadow_console_buffer[1] = 0;
} else
shadow_console_buffer = (char *)SHADOW_CONSOLE_END;
}
__init int shadow_console_enabled(void)
{
return early_shadow_console.flags & CON_ENABLED;
}
__init void mark_shadow_error(void)
{
int *loc = (int *)SHADOW_CONSOLE_MAGIC_LOC;
loc[0] = SHADOW_CONSOLE_MAGIC;
loc[1] = SHADOW_CONSOLE_START;
}
__init void enable_shadow_console(void)
{
if (!shadow_console_enabled()) {
register_console(&early_shadow_console);
mark_shadow_error();
}
}
static __init int disable_shadow_console(void)
{
int *loc = (int *)SHADOW_CONSOLE_MAGIC_LOC;
loc[0] = 0;
return 0;
}
__init void early_shadow_reg(unsigned long reg, unsigned int n)
{
int i;
char ascii[11] = " 0x";
n = n / 4;
reg = reg << ((8 - n) * 4);
n += 3;
for (i = 3; i <= n ; i++) {
ascii[i] = hex_asc_lo(reg >> 28);
reg <<= 4;
}
early_shadow_write(NULL, ascii, n);
}
