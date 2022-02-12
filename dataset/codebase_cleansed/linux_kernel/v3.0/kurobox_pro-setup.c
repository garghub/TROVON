static int __init kurobox_pro_pci_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
int irq;
irq = orion5x_pci_map_irq(dev, slot, pin);
if (irq != -1)
return irq;
return -1;
}
static int __init kurobox_pro_pci_init(void)
{
if (machine_is_kurobox_pro()) {
orion5x_pci_disable();
pci_common_init(&kurobox_pro_pci);
}
return 0;
}
static int kurobox_pro_miconread(unsigned char *buf, int count)
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
static int kurobox_pro_miconwrite(const unsigned char *buf, int count)
{
int i = 0;
while (count--) {
while (!(readl(UART1_REG(LSR)) & UART_LSR_THRE))
barrier();
writel(buf[i++], UART1_REG(TX));
}
return 0;
}
static int kurobox_pro_miconsend(const unsigned char *data, int count)
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
kurobox_pro_miconwrite(data, count);
kurobox_pro_miconwrite(&checksum, 1);
if (kurobox_pro_miconread(recv_buf, sizeof(recv_buf)) <= 3) {
printk(KERN_ERR ">%s: receive failed.\n", __func__);
memset(&send_buf, 0xff, sizeof(send_buf));
kurobox_pro_miconwrite(send_buf, sizeof(send_buf));
mdelay(100);
kurobox_pro_miconread(recv_buf, sizeof(recv_buf));
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
static void kurobox_pro_power_off(void)
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
kurobox_pro_miconsend(watchdogkill, sizeof(watchdogkill)) ;
kurobox_pro_miconsend(shutdownwait, sizeof(shutdownwait)) ;
kurobox_pro_miconsend(poweroff, sizeof(poweroff));
}
static void __init kurobox_pro_init(void)
{
orion5x_init();
orion5x_mpp_conf(kurobox_pro_mpp_modes);
orion5x_ehci0_init();
orion5x_ehci1_init();
orion5x_eth_init(&kurobox_pro_eth_data);
orion5x_i2c_init();
orion5x_sata_init(&kurobox_pro_sata_data);
orion5x_uart0_init();
orion5x_uart1_init();
orion5x_xor_init();
orion5x_setup_dev_boot_win(KUROBOX_PRO_NOR_BOOT_BASE,
KUROBOX_PRO_NOR_BOOT_SIZE);
platform_device_register(&kurobox_pro_nor_flash);
if (machine_is_kurobox_pro()) {
orion5x_setup_dev0_win(KUROBOX_PRO_NAND_BASE,
KUROBOX_PRO_NAND_SIZE);
platform_device_register(&kurobox_pro_nand_flash);
}
i2c_register_board_info(0, &kurobox_pro_i2c_rtc, 1);
pm_power_off = kurobox_pro_power_off;
}
