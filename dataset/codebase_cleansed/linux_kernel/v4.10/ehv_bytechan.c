static void enable_tx_interrupt(struct ehv_bc_data *bc)
{
if (!bc->tx_irq_enabled) {
enable_irq(bc->tx_irq);
bc->tx_irq_enabled = 1;
}
}
static void disable_tx_interrupt(struct ehv_bc_data *bc)
{
if (bc->tx_irq_enabled) {
disable_irq_nosync(bc->tx_irq);
bc->tx_irq_enabled = 0;
}
}
static int find_console_handle(void)
{
struct device_node *np = of_stdout;
const uint32_t *iprop;
if (!np || !of_device_is_compatible(np, "epapr,hv-byte-channel"))
return 0;
stdout_irq = irq_of_parse_and_map(np, 0);
if (stdout_irq == NO_IRQ) {
pr_err("ehv-bc: no 'interrupts' property in %s node\n", np->full_name);
return 0;
}
iprop = of_get_property(np, "hv-handle", NULL);
if (!iprop) {
pr_err("ehv-bc: no 'hv-handle' property in %s node\n",
np->name);
return 0;
}
stdout_bc = be32_to_cpu(*iprop);
return 1;
}
static void byte_channel_spin_send(const char data)
{
int ret, count;
do {
count = 1;
ret = ev_byte_channel_send(CONFIG_PPC_EARLY_DEBUG_EHV_BC_HANDLE,
&count, &data);
} while (ret == EV_EAGAIN);
}
static void ehv_bc_udbg_putc(char c)
{
if (c == '\n')
byte_channel_spin_send('\r');
byte_channel_spin_send(c);
}
void __init udbg_init_ehv_bc(void)
{
unsigned int rx_count, tx_count;
unsigned int ret;
ret = ev_byte_channel_poll(CONFIG_PPC_EARLY_DEBUG_EHV_BC_HANDLE,
&rx_count, &tx_count);
if (ret)
return;
udbg_putc = ehv_bc_udbg_putc;
register_early_udbg_console();
udbg_printf("ehv-bc: early console using byte channel handle %u\n",
CONFIG_PPC_EARLY_DEBUG_EHV_BC_HANDLE);
}
static int ehv_bc_console_byte_channel_send(unsigned int handle, const char *s,
unsigned int count)
{
unsigned int len;
int ret = 0;
while (count) {
len = min_t(unsigned int, count, EV_BYTE_CHANNEL_MAX_BYTES);
do {
ret = ev_byte_channel_send(handle, &len, s);
} while (ret == EV_EAGAIN);
count -= len;
s += len;
}
return ret;
}
static void ehv_bc_console_write(struct console *co, const char *s,
unsigned int count)
{
char s2[EV_BYTE_CHANNEL_MAX_BYTES];
unsigned int i, j = 0;
char c;
for (i = 0; i < count; i++) {
c = *s++;
if (c == '\n')
s2[j++] = '\r';
s2[j++] = c;
if (j >= (EV_BYTE_CHANNEL_MAX_BYTES - 1)) {
if (ehv_bc_console_byte_channel_send(stdout_bc, s2, j))
return;
j = 0;
}
}
if (j)
ehv_bc_console_byte_channel_send(stdout_bc, s2, j);
}
static struct tty_driver *ehv_bc_console_device(struct console *co, int *index)
{
*index = co->index;
return ehv_bc_driver;
}
static int __init ehv_bc_console_init(void)
{
if (!find_console_handle()) {
pr_debug("ehv-bc: stdout is not a byte channel\n");
return -ENODEV;
}
#ifdef CONFIG_PPC_EARLY_DEBUG_EHV_BC
if (stdout_bc != CONFIG_PPC_EARLY_DEBUG_EHV_BC_HANDLE)
pr_warn("ehv-bc: udbg handle %u is not the stdout handle\n",
CONFIG_PPC_EARLY_DEBUG_EHV_BC_HANDLE);
#endif
add_preferred_console(ehv_bc_console.name, ehv_bc_console.index, NULL);
register_console(&ehv_bc_console);
pr_info("ehv-bc: registered console driver for byte channel %u\n",
stdout_bc);
return 0;
}
static irqreturn_t ehv_bc_tty_rx_isr(int irq, void *data)
{
struct ehv_bc_data *bc = data;
unsigned int rx_count, tx_count, len;
int count;
char buffer[EV_BYTE_CHANNEL_MAX_BYTES];
int ret;
ev_byte_channel_poll(bc->handle, &rx_count, &tx_count);
count = tty_buffer_request_room(&bc->port, rx_count);
while (count > 0) {
len = min_t(unsigned int, count, sizeof(buffer));
ev_byte_channel_receive(bc->handle, &len, buffer);
ret = tty_insert_flip_string(&bc->port, buffer, len);
if (ret != len)
break;
count -= len;
}
tty_flip_buffer_push(&bc->port);
return IRQ_HANDLED;
}
static void ehv_bc_tx_dequeue(struct ehv_bc_data *bc)
{
unsigned int count;
unsigned int len, ret;
unsigned long flags;
do {
spin_lock_irqsave(&bc->lock, flags);
len = min_t(unsigned int,
CIRC_CNT_TO_END(bc->head, bc->tail, BUF_SIZE),
EV_BYTE_CHANNEL_MAX_BYTES);
ret = ev_byte_channel_send(bc->handle, &len, bc->buf + bc->tail);
if (!ret || (ret == EV_EAGAIN))
bc->tail = (bc->tail + len) & (BUF_SIZE - 1);
count = CIRC_CNT(bc->head, bc->tail, BUF_SIZE);
spin_unlock_irqrestore(&bc->lock, flags);
} while (count && !ret);
spin_lock_irqsave(&bc->lock, flags);
if (CIRC_CNT(bc->head, bc->tail, BUF_SIZE))
enable_tx_interrupt(bc);
else
disable_tx_interrupt(bc);
spin_unlock_irqrestore(&bc->lock, flags);
}
static irqreturn_t ehv_bc_tty_tx_isr(int irq, void *data)
{
struct ehv_bc_data *bc = data;
ehv_bc_tx_dequeue(bc);
tty_port_tty_wakeup(&bc->port);
return IRQ_HANDLED;
}
static int ehv_bc_tty_write(struct tty_struct *ttys, const unsigned char *s,
int count)
{
struct ehv_bc_data *bc = ttys->driver_data;
unsigned long flags;
unsigned int len;
unsigned int written = 0;
while (1) {
spin_lock_irqsave(&bc->lock, flags);
len = CIRC_SPACE_TO_END(bc->head, bc->tail, BUF_SIZE);
if (count < len)
len = count;
if (len) {
memcpy(bc->buf + bc->head, s, len);
bc->head = (bc->head + len) & (BUF_SIZE - 1);
}
spin_unlock_irqrestore(&bc->lock, flags);
if (!len)
break;
s += len;
count -= len;
written += len;
}
ehv_bc_tx_dequeue(bc);
return written;
}
static int ehv_bc_tty_open(struct tty_struct *ttys, struct file *filp)
{
struct ehv_bc_data *bc = &bcs[ttys->index];
if (!bc->dev)
return -ENODEV;
return tty_port_open(&bc->port, ttys, filp);
}
static void ehv_bc_tty_close(struct tty_struct *ttys, struct file *filp)
{
struct ehv_bc_data *bc = &bcs[ttys->index];
if (bc->dev)
tty_port_close(&bc->port, ttys, filp);
}
static int ehv_bc_tty_write_room(struct tty_struct *ttys)
{
struct ehv_bc_data *bc = ttys->driver_data;
unsigned long flags;
int count;
spin_lock_irqsave(&bc->lock, flags);
count = CIRC_SPACE(bc->head, bc->tail, BUF_SIZE);
spin_unlock_irqrestore(&bc->lock, flags);
return count;
}
static void ehv_bc_tty_throttle(struct tty_struct *ttys)
{
struct ehv_bc_data *bc = ttys->driver_data;
disable_irq(bc->rx_irq);
}
static void ehv_bc_tty_unthrottle(struct tty_struct *ttys)
{
struct ehv_bc_data *bc = ttys->driver_data;
enable_irq(bc->rx_irq);
}
static void ehv_bc_tty_hangup(struct tty_struct *ttys)
{
struct ehv_bc_data *bc = ttys->driver_data;
ehv_bc_tx_dequeue(bc);
tty_port_hangup(&bc->port);
}
static int ehv_bc_tty_port_activate(struct tty_port *port,
struct tty_struct *ttys)
{
struct ehv_bc_data *bc = container_of(port, struct ehv_bc_data, port);
int ret;
ttys->driver_data = bc;
ret = request_irq(bc->rx_irq, ehv_bc_tty_rx_isr, 0, "ehv-bc", bc);
if (ret < 0) {
dev_err(bc->dev, "could not request rx irq %u (ret=%i)\n",
bc->rx_irq, ret);
return ret;
}
bc->tx_irq_enabled = 1;
ret = request_irq(bc->tx_irq, ehv_bc_tty_tx_isr, 0, "ehv-bc", bc);
if (ret < 0) {
dev_err(bc->dev, "could not request tx irq %u (ret=%i)\n",
bc->tx_irq, ret);
free_irq(bc->rx_irq, bc);
return ret;
}
disable_tx_interrupt(bc);
return 0;
}
static void ehv_bc_tty_port_shutdown(struct tty_port *port)
{
struct ehv_bc_data *bc = container_of(port, struct ehv_bc_data, port);
free_irq(bc->tx_irq, bc);
free_irq(bc->rx_irq, bc);
}
static int ehv_bc_tty_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct ehv_bc_data *bc;
const uint32_t *iprop;
unsigned int handle;
int ret;
static unsigned int index = 1;
unsigned int i;
iprop = of_get_property(np, "hv-handle", NULL);
if (!iprop) {
dev_err(&pdev->dev, "no 'hv-handle' property in %s node\n",
np->name);
return -ENODEV;
}
handle = be32_to_cpu(*iprop);
i = (handle == stdout_bc) ? 0 : index++;
bc = &bcs[i];
bc->handle = handle;
bc->head = 0;
bc->tail = 0;
spin_lock_init(&bc->lock);
bc->rx_irq = irq_of_parse_and_map(np, 0);
bc->tx_irq = irq_of_parse_and_map(np, 1);
if ((bc->rx_irq == NO_IRQ) || (bc->tx_irq == NO_IRQ)) {
dev_err(&pdev->dev, "no 'interrupts' property in %s node\n",
np->name);
ret = -ENODEV;
goto error;
}
tty_port_init(&bc->port);
bc->port.ops = &ehv_bc_tty_port_ops;
bc->dev = tty_port_register_device(&bc->port, ehv_bc_driver, i,
&pdev->dev);
if (IS_ERR(bc->dev)) {
ret = PTR_ERR(bc->dev);
dev_err(&pdev->dev, "could not register tty (ret=%i)\n", ret);
goto error;
}
dev_set_drvdata(&pdev->dev, bc);
dev_info(&pdev->dev, "registered /dev/%s%u for byte channel %u\n",
ehv_bc_driver->name, i, bc->handle);
return 0;
error:
tty_port_destroy(&bc->port);
irq_dispose_mapping(bc->tx_irq);
irq_dispose_mapping(bc->rx_irq);
memset(bc, 0, sizeof(struct ehv_bc_data));
return ret;
}
static int __init ehv_bc_init(void)
{
struct device_node *np;
unsigned int count = 0;
int ret;
pr_info("ePAPR hypervisor byte channel driver\n");
for_each_compatible_node(np, NULL, "epapr,hv-byte-channel")
count++;
if (!count)
return -ENODEV;
bcs = kzalloc(count * sizeof(struct ehv_bc_data), GFP_KERNEL);
if (!bcs)
return -ENOMEM;
ehv_bc_driver = alloc_tty_driver(count);
if (!ehv_bc_driver) {
ret = -ENOMEM;
goto error;
}
ehv_bc_driver->driver_name = "ehv-bc";
ehv_bc_driver->name = ehv_bc_console.name;
ehv_bc_driver->type = TTY_DRIVER_TYPE_CONSOLE;
ehv_bc_driver->subtype = SYSTEM_TYPE_CONSOLE;
ehv_bc_driver->init_termios = tty_std_termios;
ehv_bc_driver->flags = TTY_DRIVER_REAL_RAW | TTY_DRIVER_DYNAMIC_DEV;
tty_set_operations(ehv_bc_driver, &ehv_bc_ops);
ret = tty_register_driver(ehv_bc_driver);
if (ret) {
pr_err("ehv-bc: could not register tty driver (ret=%i)\n", ret);
goto error;
}
ret = platform_driver_register(&ehv_bc_tty_driver);
if (ret) {
pr_err("ehv-bc: could not register platform driver (ret=%i)\n",
ret);
goto error;
}
return 0;
error:
if (ehv_bc_driver) {
tty_unregister_driver(ehv_bc_driver);
put_tty_driver(ehv_bc_driver);
}
kfree(bcs);
return ret;
}
