static void wsp_h8_putc(int c)
{
u8 lsr;
do {
lsr = readb(h8 + LSR);
} while ((lsr & LSR_THRE) != LSR_THRE);
writeb(c, h8 + THR);
}
static int wsp_h8_getc(void)
{
u8 lsr;
do {
lsr = readb(h8 + LSR);
} while ((lsr & LSR_DR) != LSR_DR);
return readb(h8 + RBR);
}
static void wsp_h8_puts(const char *s, int sz)
{
int i;
for (i = 0; i < sz; i++) {
wsp_h8_putc(s[i]);
wsp_h8_getc();
}
wsp_h8_putc('\r');
wsp_h8_putc('\n');
}
static void wsp_h8_terminal_cmd(const char *cmd, int sz)
{
hard_irq_disable();
wsp_h8_puts(cmd, sz);
for (;;)
continue;
}
void wsp_h8_restart(char *cmd)
{
static const char restart[] = "warm-reset";
(void)cmd;
wsp_h8_terminal_cmd(restart, sizeof(restart) - 1);
}
void wsp_h8_power_off(void)
{
static const char off[] = "power-off";
wsp_h8_terminal_cmd(off, sizeof(off) - 1);
}
static void __iomem *wsp_h8_getaddr(void)
{
struct device_node *aliases;
struct device_node *uart;
struct property *path;
void __iomem *va = NULL;
aliases = of_find_node_by_path("/aliases");
if (aliases == NULL)
return NULL;
path = of_find_property(aliases, "serial1", NULL);
if (path == NULL)
goto out;
uart = of_find_node_by_path(path->value);
if (uart == NULL)
goto out;
va = of_iomap(uart, 0);
of_detach_node(uart);
of_node_put(uart);
out:
of_node_put(aliases);
return va;
}
void __init wsp_setup_h8(void)
{
h8 = wsp_h8_getaddr();
if (h8 == NULL) {
pr_warn("UART to H8 could not be found");
h8 = ioremap(0xffc0008000ULL, 0x100);
}
}
