static void __iomem * __init earlycon_map(unsigned long paddr, size_t size)
{
void __iomem *base;
#ifdef CONFIG_FIX_EARLYCON_MEM
set_fixmap_io(FIX_EARLYCON_MEM_BASE, paddr & PAGE_MASK);
base = (void __iomem *)__fix_to_virt(FIX_EARLYCON_MEM_BASE);
base += paddr & ~PAGE_MASK;
#else
base = ioremap(paddr, size);
#endif
if (!base)
pr_err("%s: Couldn't map 0x%llx\n", __func__,
(unsigned long long)paddr);
return base;
}
static int __init parse_options(struct earlycon_device *device, char *options)
{
struct uart_port *port = &device->port;
int length;
unsigned long addr;
if (uart_parse_earlycon(options, &port->iotype, &addr, &options))
return -EINVAL;
switch (port->iotype) {
case UPIO_MEM:
port->mapbase = addr;
break;
case UPIO_MEM16:
port->regshift = 1;
port->mapbase = addr;
break;
case UPIO_MEM32:
case UPIO_MEM32BE:
port->regshift = 2;
port->mapbase = addr;
break;
case UPIO_PORT:
port->iobase = addr;
break;
default:
return -EINVAL;
}
if (options) {
device->baud = simple_strtoul(options, NULL, 0);
length = min(strcspn(options, " ") + 1,
(size_t)(sizeof(device->options)));
strlcpy(device->options, options, length);
}
if (port->iotype == UPIO_MEM || port->iotype == UPIO_MEM16 ||
port->iotype == UPIO_MEM32 || port->iotype == UPIO_MEM32BE)
pr_info("Early serial console at MMIO%s 0x%llx (options '%s')\n",
(port->iotype == UPIO_MEM) ? "" :
(port->iotype == UPIO_MEM16) ? "16" :
(port->iotype == UPIO_MEM32) ? "32" : "32be",
(unsigned long long)port->mapbase,
device->options);
else
pr_info("Early serial console at I/O port 0x%lx (options '%s')\n",
port->iobase,
device->options);
return 0;
}
static int __init register_earlycon(char *buf, const struct earlycon_id *match)
{
int err;
struct uart_port *port = &early_console_dev.port;
if (buf && !parse_options(&early_console_dev, buf))
buf = NULL;
spin_lock_init(&port->lock);
port->uartclk = BASE_BAUD * 16;
if (port->mapbase)
port->membase = earlycon_map(port->mapbase, 64);
early_console_dev.con->data = &early_console_dev;
err = match->setup(&early_console_dev, buf);
if (err < 0)
return err;
if (!early_console_dev.con->write)
return -ENODEV;
register_console(early_console_dev.con);
return 0;
}
int __init setup_earlycon(char *buf)
{
const struct earlycon_id *match;
if (!buf || !buf[0])
return -EINVAL;
if (early_con.flags & CON_ENABLED)
return -EALREADY;
for (match = __earlycon_table; match->name[0]; match++) {
size_t len = strlen(match->name);
if (strncmp(buf, match->name, len))
continue;
if (buf[len]) {
if (buf[len] != ',')
continue;
buf += len + 1;
} else
buf = NULL;
return register_earlycon(buf, match);
}
return -ENOENT;
}
static int __init param_setup_earlycon(char *buf)
{
int err;
if (!buf || !buf[0])
return 0;
err = setup_earlycon(buf);
if (err == -ENOENT || err == -EALREADY)
return 0;
return err;
}
int __init of_setup_earlycon(unsigned long addr,
int (*setup)(struct earlycon_device *, const char *))
{
int err;
struct uart_port *port = &early_console_dev.port;
spin_lock_init(&port->lock);
port->iotype = UPIO_MEM;
port->mapbase = addr;
port->uartclk = BASE_BAUD * 16;
port->membase = earlycon_map(addr, SZ_4K);
early_console_dev.con->data = &early_console_dev;
err = setup(&early_console_dev, NULL);
if (err < 0)
return err;
if (!early_console_dev.con->write)
return -ENODEV;
register_console(early_console_dev.con);
return 0;
}
