void __init tsp2_pci_preinit(void)
{
int pin;
pin = TSP2_PCI_SLOT0_IRQ_PIN;
if (gpio_request(pin, "PCI Int1") == 0) {
if (gpio_direction_input(pin) == 0) {
irq_set_irq_type(gpio_to_irq(pin), IRQ_TYPE_LEVEL_LOW);
} else {
printk(KERN_ERR "tsp2_pci_preinit failed "
"to set_irq_type pin %d\n", pin);
gpio_free(pin);
}
} else {
printk(KERN_ERR "tsp2_pci_preinit failed to "
"gpio_request %d\n", pin);
}
}
static int __init tsp2_pci_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
int irq;
irq = orion5x_pci_map_irq(dev, slot, pin);
if (irq != -1)
return irq;
if (slot == TSP2_PCI_SLOT0_OFFS)
return gpio_to_irq(TSP2_PCI_SLOT0_IRQ_PIN);
return -1;
}
static int __init tsp2_pci_init(void)
{
if (machine_is_terastation_pro2())
pci_common_init(&tsp2_pci);
return 0;
}
static int tsp2_miconread(unsigned char *buf, int count)
{
int i;
int timeout;
for (i = 0; i < count; i++) {
timeout = 10;
while (!(readl(UART1_REG(LSR)) & UART_LSR_DR)) {
if (--timeout == 0)
break;
udelay(1000);
}
if (timeout == 0)
break;
buf[i] = readl(UART1_REG(RX));
}
return i;
}
static int tsp2_miconwrite(const unsigned char *buf, int count)
{
int i = 0;
while (count--) {
while (!(readl(UART1_REG(LSR)) & UART_LSR_THRE))
barrier();
writel(buf[i++], UART1_REG(TX));
}
return 0;
}
static int tsp2_miconsend(const unsigned char *data, int count)
{
int i;
unsigned char checksum = 0;
unsigned char recv_buf[40];
unsigned char send_buf[40];
unsigned char correct_ack[3];
int retry = 2;
for (i = 0; i < count; i++)
checksum -= data[i];
do {
tsp2_miconwrite(data, count);
tsp2_miconwrite(&checksum, 1);
if (tsp2_miconread(recv_buf, sizeof(recv_buf)) <= 3) {
printk(KERN_ERR ">%s: receive failed.\n", __func__);
memset(&send_buf, 0xff, sizeof(send_buf));
tsp2_miconwrite(send_buf, sizeof(send_buf));
mdelay(100);
tsp2_miconread(recv_buf, sizeof(recv_buf));
} else {
correct_ack[0] = 0x01;
correct_ack[1] = data[1];
correct_ack[2] = 0x00;
if ((recv_buf[0] + recv_buf[1] + recv_buf[2] +
recv_buf[3]) & 0xFF) {
printk(KERN_ERR ">%s: Checksum Error : "
"Received data[%02x, %02x, %02x, %02x]"
"\n", __func__, recv_buf[0],
recv_buf[1], recv_buf[2], recv_buf[3]);
} else {
if (correct_ack[0] == recv_buf[0] &&
correct_ack[1] == recv_buf[1] &&
correct_ack[2] == recv_buf[2]) {
mdelay(10);
return 0;
}
}
printk(KERN_ERR ">%s: Error : NAK or Illegal Data "
"Received\n", __func__);
}
} while (retry--);
mdelay(10);
return -1;
}
static void tsp2_power_off(void)
{
const unsigned char watchdogkill[] = {0x01, 0x35, 0x00};
const unsigned char shutdownwait[] = {0x00, 0x0c};
const unsigned char poweroff[] = {0x00, 0x06};
const unsigned divisor = ((orion5x_tclk + (8 * 38400)) / (16 * 38400));
pr_info("%s: triggering power-off...\n", __func__);
writel(0x83, UART1_REG(LCR));
writel(divisor & 0xff, UART1_REG(DLL));
writel((divisor >> 8) & 0xff, UART1_REG(DLM));
writel(0x1b, UART1_REG(LCR));
writel(0x00, UART1_REG(IER));
writel(0x07, UART1_REG(FCR));
writel(0x00, UART1_REG(MCR));
tsp2_miconsend(watchdogkill, sizeof(watchdogkill)) ;
tsp2_miconsend(shutdownwait, sizeof(shutdownwait)) ;
tsp2_miconsend(poweroff, sizeof(poweroff));
}
static void __init tsp2_init(void)
{
orion5x_init();
orion5x_mpp_conf(tsp2_mpp_modes);
mvebu_mbus_add_window("devbus-boot", TSP2_NOR_BOOT_BASE,
TSP2_NOR_BOOT_SIZE);
platform_device_register(&tsp2_nor_flash);
orion5x_ehci0_init();
orion5x_eth_init(&tsp2_eth_data);
orion5x_i2c_init();
orion5x_uart0_init();
orion5x_uart1_init();
if (gpio_request(TSP2_RTC_GPIO, "rtc") == 0) {
if (gpio_direction_input(TSP2_RTC_GPIO) == 0)
tsp2_i2c_rtc.irq = gpio_to_irq(TSP2_RTC_GPIO);
else
gpio_free(TSP2_RTC_GPIO);
}
if (tsp2_i2c_rtc.irq == 0)
pr_warning("tsp2_init: failed to get RTC IRQ\n");
i2c_register_board_info(0, &tsp2_i2c_rtc, 1);
pm_power_off = tsp2_power_off;
}
