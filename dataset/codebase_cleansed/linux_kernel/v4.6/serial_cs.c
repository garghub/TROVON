static void quirk_setup_brainboxes_0104(struct pcmcia_device *link, struct uart_8250_port *uart)
{
uart->port.uartclk = 14745600;
}
static int quirk_post_ibm(struct pcmcia_device *link)
{
u8 val;
int ret;
ret = pcmcia_read_config_byte(link, 0x800, &val);
if (ret)
goto failed;
ret = pcmcia_write_config_byte(link, 0x800, val | 1);
if (ret)
goto failed;
return 0;
failed:
return -ENODEV;
}
static void quirk_config_nokia(struct pcmcia_device *link)
{
struct serial_info *info = link->priv;
if (info->multi > 1)
info->multi = 1;
}
static void quirk_wakeup_oxsemi(struct pcmcia_device *link)
{
struct serial_info *info = link->priv;
if (info->c950ctrl)
outb(12, info->c950ctrl + 1);
}
static void quirk_wakeup_possio_gcc(struct pcmcia_device *link)
{
struct serial_info *info = link->priv;
unsigned int ctrl = info->c950ctrl;
outb(0xA, ctrl + 1);
msleep(100);
outb(0xE, ctrl + 1);
msleep(300);
outb(0xC, ctrl + 1);
msleep(100);
outb(0xE, ctrl + 1);
msleep(200);
outb(0xF, ctrl + 1);
msleep(100);
outb(0xE, ctrl + 1);
msleep(100);
outb(0xC, ctrl + 1);
}
static void quirk_config_socket(struct pcmcia_device *link)
{
struct serial_info *info = link->priv;
if (info->multi)
link->config_flags |= CONF_ENABLE_ESR;
}
static void serial_remove(struct pcmcia_device *link)
{
struct serial_info *info = link->priv;
int i;
dev_dbg(&link->dev, "serial_release\n");
for (i = 0; i < info->ndev; i++)
serial8250_unregister_port(info->line[i]);
if (!info->slave)
pcmcia_disable_device(link);
}
static int serial_suspend(struct pcmcia_device *link)
{
struct serial_info *info = link->priv;
int i;
for (i = 0; i < info->ndev; i++)
serial8250_suspend_port(info->line[i]);
return 0;
}
static int serial_resume(struct pcmcia_device *link)
{
struct serial_info *info = link->priv;
int i;
for (i = 0; i < info->ndev; i++)
serial8250_resume_port(info->line[i]);
if (info->quirk && info->quirk->wakeup)
info->quirk->wakeup(link);
return 0;
}
static int serial_probe(struct pcmcia_device *link)
{
struct serial_info *info;
dev_dbg(&link->dev, "serial_attach()\n");
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->p_dev = link;
link->priv = info;
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
if (do_sound)
link->config_flags |= CONF_ENABLE_SPKR;
return serial_config(link);
}
static void serial_detach(struct pcmcia_device *link)
{
struct serial_info *info = link->priv;
dev_dbg(&link->dev, "serial_detach\n");
serial_remove(link);
kfree(info);
}
static int setup_serial(struct pcmcia_device *handle, struct serial_info *info,
unsigned int iobase, int irq)
{
struct uart_8250_port uart;
int line;
memset(&uart, 0, sizeof(uart));
uart.port.iobase = iobase;
uart.port.irq = irq;
uart.port.flags = UPF_BOOT_AUTOCONF | UPF_SKIP_TEST | UPF_SHARE_IRQ;
uart.port.uartclk = 1843200;
uart.port.dev = &handle->dev;
if (buggy_uart)
uart.port.flags |= UPF_BUGGY_UART;
if (info->quirk && info->quirk->setup)
info->quirk->setup(handle, &uart);
line = serial8250_register_8250_port(&uart);
if (line < 0) {
pr_err("serial_cs: serial8250_register_8250_port() at 0x%04lx, irq %d failed\n",
(unsigned long)iobase, irq);
return -EINVAL;
}
info->line[info->ndev] = line;
info->ndev++;
return 0;
}
static int pfc_config(struct pcmcia_device *p_dev)
{
unsigned int port = 0;
struct serial_info *info = p_dev->priv;
if ((p_dev->resource[1]->end != 0) &&
(resource_size(p_dev->resource[1]) == 8)) {
port = p_dev->resource[1]->start;
info->slave = 1;
} else if ((info->manfid == MANFID_OSITECH) &&
(resource_size(p_dev->resource[0]) == 0x40)) {
port = p_dev->resource[0]->start + 0x28;
info->slave = 1;
}
if (info->slave)
return setup_serial(p_dev, info, port, p_dev->irq);
dev_warn(&p_dev->dev, "no usable port range found, giving up\n");
return -ENODEV;
}
static int simple_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
static const int size_table[2] = { 8, 16 };
int *try = priv_data;
if (p_dev->resource[0]->start == 0)
return -ENODEV;
if ((*try & 0x1) == 0)
p_dev->io_lines = 16;
if (p_dev->resource[0]->end != size_table[(*try >> 1)])
return -ENODEV;
p_dev->resource[0]->end = 8;
p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_8;
return pcmcia_request_io(p_dev);
}
static int simple_config_check_notpicky(struct pcmcia_device *p_dev,
void *priv_data)
{
static const unsigned int base[5] = { 0x3f8, 0x2f8, 0x3e8, 0x2e8, 0x0 };
int j;
if (p_dev->io_lines > 3)
return -ENODEV;
p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_8;
p_dev->resource[0]->end = 8;
for (j = 0; j < 5; j++) {
p_dev->resource[0]->start = base[j];
p_dev->io_lines = base[j] ? 16 : 3;
if (!pcmcia_request_io(p_dev))
return 0;
}
return -ENODEV;
}
static int simple_config(struct pcmcia_device *link)
{
struct serial_info *info = link->priv;
int i = -ENODEV, try;
link->config_flags |= CONF_AUTO_SET_VPP;
for (try = 0; try < 4; try++)
if (!pcmcia_loop_config(link, simple_config_check, &try))
goto found_port;
if (!pcmcia_loop_config(link, simple_config_check_notpicky, NULL))
goto found_port;
dev_warn(&link->dev, "no usable port range found, giving up\n");
return -1;
found_port:
if (info->multi && (info->manfid == MANFID_3COM))
link->config_index &= ~(0x08);
if (info->quirk && info->quirk->config)
info->quirk->config(link);
i = pcmcia_enable_device(link);
if (i != 0)
return -1;
return setup_serial(link, info, link->resource[0]->start, link->irq);
}
static int multi_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
int *multi = priv_data;
if (p_dev->resource[1]->end)
return -EINVAL;
if (p_dev->resource[0]->end <= 8)
return -EINVAL;
p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_8;
p_dev->resource[0]->end = *multi * 8;
if (pcmcia_request_io(p_dev))
return -ENODEV;
return 0;
}
static int multi_config_check_notpicky(struct pcmcia_device *p_dev,
void *priv_data)
{
int *base2 = priv_data;
if (!p_dev->resource[0]->end || !p_dev->resource[1]->end ||
p_dev->resource[0]->start + 8 != p_dev->resource[1]->start)
return -ENODEV;
p_dev->resource[0]->end = p_dev->resource[1]->end = 8;
p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_8;
if (pcmcia_request_io(p_dev))
return -ENODEV;
*base2 = p_dev->resource[0]->start + 8;
return 0;
}
static int multi_config(struct pcmcia_device *link)
{
struct serial_info *info = link->priv;
int i, base2 = 0;
if (!pcmcia_loop_config(link, multi_config_check, &info->multi))
base2 = link->resource[0]->start + 8;
else {
info->multi = 2;
if (pcmcia_loop_config(link, multi_config_check_notpicky,
&base2)) {
dev_warn(&link->dev,
"no usable port range found, giving up\n");
return -ENODEV;
}
}
if (!link->irq)
dev_warn(&link->dev, "no usable IRQ found, continuing...\n");
if (info->quirk && info->quirk->config)
info->quirk->config(link);
i = pcmcia_enable_device(link);
if (i != 0)
return -ENODEV;
if (info->manfid == MANFID_OXSEMI || (info->manfid == MANFID_POSSIO &&
info->prodid == PRODID_POSSIO_GCC)) {
int err;
if (link->config_index == 1 ||
link->config_index == 3) {
err = setup_serial(link, info, base2,
link->irq);
base2 = link->resource[0]->start;
} else {
err = setup_serial(link, info, link->resource[0]->start,
link->irq);
}
info->c950ctrl = base2;
if (info->quirk && info->quirk->wakeup)
info->quirk->wakeup(link);
return 0;
}
setup_serial(link, info, link->resource[0]->start, link->irq);
for (i = 0; i < info->multi - 1; i++)
setup_serial(link, info, base2 + (8 * i),
link->irq);
return 0;
}
static int serial_check_for_multi(struct pcmcia_device *p_dev, void *priv_data)
{
struct serial_info *info = p_dev->priv;
if (!p_dev->resource[0]->end)
return -EINVAL;
if ((!p_dev->resource[1]->end) && (p_dev->resource[0]->end % 8 == 0))
info->multi = p_dev->resource[0]->end >> 3;
if ((p_dev->resource[1]->end) && (p_dev->resource[0]->end == 8)
&& (p_dev->resource[1]->end == 8))
info->multi = 2;
return 0;
}
static int serial_config(struct pcmcia_device *link)
{
struct serial_info *info = link->priv;
int i;
dev_dbg(&link->dev, "serial_config\n");
info->multi = (link->socket->functions > 1);
info->manfid = link->manf_id;
info->prodid = link->card_id;
for (i = 0; i < ARRAY_SIZE(quirks); i++)
if ((quirks[i].manfid == ~0 ||
quirks[i].manfid == info->manfid) &&
(quirks[i].prodid == ~0 ||
quirks[i].prodid == info->prodid)) {
info->quirk = &quirks[i];
break;
}
if ((info->multi == 0) &&
(link->has_func_id) &&
(link->socket->pcmcia_pfc == 0) &&
((link->func_id == CISTPL_FUNCID_MULTI) ||
(link->func_id == CISTPL_FUNCID_SERIAL)))
pcmcia_loop_config(link, serial_check_for_multi, info);
if (info->quirk && info->quirk->multi != -1)
info->multi = info->quirk->multi;
dev_info(&link->dev,
"trying to set up [0x%04x:0x%04x] (pfc: %d, multi: %d, quirk: %p)\n",
link->manf_id, link->card_id,
link->socket->pcmcia_pfc, info->multi, info->quirk);
if (link->socket->pcmcia_pfc)
i = pfc_config(link);
else if (info->multi > 1)
i = multi_config(link);
else
i = simple_config(link);
if (i || info->ndev == 0)
goto failed;
if (info->quirk && info->quirk->post)
if (info->quirk->post(link))
goto failed;
return 0;
failed:
dev_warn(&link->dev, "failed to initialize\n");
serial_remove(link);
return -ENODEV;
}
