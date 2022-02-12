int mantis_uart_read(struct mantis_pci *mantis, u8 *data)
{
struct mantis_hwconfig *config = mantis->hwconfig;
u32 stat = 0, i;
for (i = 0; i < (config->bytes + 1); i++) {
stat = mmread(MANTIS_UART_STAT);
if (stat & MANTIS_UART_RXFIFO_FULL) {
dprintk(MANTIS_ERROR, 1, "RX Fifo FULL");
}
data[i] = mmread(MANTIS_UART_RXD) & 0x3f;
dprintk(MANTIS_DEBUG, 1, "Reading ... <%02x>", data[i] & 0x3f);
if (data[i] & (1 << 7)) {
dprintk(MANTIS_ERROR, 1, "UART framing error");
return -EINVAL;
}
if (data[i] & (1 << 6)) {
dprintk(MANTIS_ERROR, 1, "UART parity error");
return -EINVAL;
}
}
return 0;
}
static void mantis_uart_work(struct work_struct *work)
{
struct mantis_pci *mantis = container_of(work, struct mantis_pci, uart_work);
struct mantis_hwconfig *config = mantis->hwconfig;
u8 buf[16];
int i;
mantis_uart_read(mantis, buf);
for (i = 0; i < (config->bytes + 1); i++)
dprintk(MANTIS_INFO, 1, "UART BUF:%d <%02x> ", i, buf[i]);
dprintk(MANTIS_DEBUG, 0, "\n");
}
static int mantis_uart_setup(struct mantis_pci *mantis,
struct mantis_uart_params *params)
{
u32 reg;
mmwrite((mmread(MANTIS_UART_CTL) | (params->parity & 0x3)), MANTIS_UART_CTL);
reg = mmread(MANTIS_UART_BAUD);
switch (params->baud_rate) {
case MANTIS_BAUD_9600:
reg |= 0xd8;
break;
case MANTIS_BAUD_19200:
reg |= 0x6c;
break;
case MANTIS_BAUD_38400:
reg |= 0x36;
break;
case MANTIS_BAUD_57600:
reg |= 0x23;
break;
case MANTIS_BAUD_115200:
reg |= 0x11;
break;
default:
return -EINVAL;
}
mmwrite(reg, MANTIS_UART_BAUD);
return 0;
}
int mantis_uart_init(struct mantis_pci *mantis)
{
struct mantis_hwconfig *config = mantis->hwconfig;
struct mantis_uart_params params;
params.baud_rate = config->baud_rate;
params.parity = config->parity;
dprintk(MANTIS_INFO, 1, "Initializing UART @ %sbps parity:%s",
rates[params.baud_rate].string,
parity[params.parity].string);
init_waitqueue_head(&mantis->uart_wq);
spin_lock_init(&mantis->uart_lock);
INIT_WORK(&mantis->uart_work, mantis_uart_work);
mmwrite(mmread(MANTIS_UART_CTL) & 0xffef, MANTIS_UART_CTL);
mantis_uart_setup(mantis, &params);
mmwrite((mmread(MANTIS_UART_BAUD) | (config->bytes << 8)), MANTIS_UART_BAUD);
mmwrite((mmread(MANTIS_UART_CTL) | MANTIS_UART_RXFLUSH), MANTIS_UART_CTL);
mmwrite(mmread(MANTIS_INT_MASK) | 0x800, MANTIS_INT_MASK);
mmwrite(mmread(MANTIS_UART_CTL) | MANTIS_UART_RXINT, MANTIS_UART_CTL);
schedule_work(&mantis->uart_work);
dprintk(MANTIS_DEBUG, 1, "UART successfully initialized");
return 0;
}
void mantis_uart_exit(struct mantis_pci *mantis)
{
mmwrite(mmread(MANTIS_UART_CTL) & 0xffef, MANTIS_UART_CTL);
flush_work_sync(&mantis->uart_work);
}
