static inline void owl_uart_write(struct uart_port *port, u32 val, unsigned int off)
{
writel(val, port->membase + off);
}
static inline u32 owl_uart_read(struct uart_port *port, unsigned int off)
{
return readl(port->membase + off);
}
static void owl_console_putchar(struct uart_port *port, int ch)
{
if (!port->membase)
return;
while (owl_uart_read(port, OWL_UART_STAT) & OWL_UART_STAT_TFFU)
cpu_relax();
owl_uart_write(port, ch, OWL_UART_TXDAT);
}
static void owl_uart_port_write(struct uart_port *port, const char *s,
u_int count)
{
u32 old_ctl, val;
unsigned long flags;
int locked;
local_irq_save(flags);
if (port->sysrq)
locked = 0;
else if (oops_in_progress)
locked = spin_trylock(&port->lock);
else {
spin_lock(&port->lock);
locked = 1;
}
old_ctl = owl_uart_read(port, OWL_UART_CTL);
val = old_ctl | OWL_UART_CTL_TRFS_TX;
val &= ~(OWL_UART_CTL_RXIE | OWL_UART_CTL_TXIE);
owl_uart_write(port, val, OWL_UART_CTL);
uart_console_write(port, s, count, owl_console_putchar);
while (owl_uart_read(port, OWL_UART_STAT) & OWL_UART_STAT_TRFL_MASK)
cpu_relax();
val = owl_uart_read(port, OWL_UART_STAT);
val |= OWL_UART_STAT_TIP | OWL_UART_STAT_RIP;
owl_uart_write(port, val, OWL_UART_STAT);
owl_uart_write(port, old_ctl, OWL_UART_CTL);
if (locked)
spin_unlock(&port->lock);
local_irq_restore(flags);
}
static void owl_uart_early_console_write(struct console *co,
const char *s,
u_int count)
{
struct earlycon_device *dev = co->data;
owl_uart_port_write(&dev->port, s, count);
}
static int __init
owl_uart_early_console_setup(struct earlycon_device *device, const char *opt)
{
if (!device->port.membase)
return -ENODEV;
device->con->write = owl_uart_early_console_write;
return 0;
}
