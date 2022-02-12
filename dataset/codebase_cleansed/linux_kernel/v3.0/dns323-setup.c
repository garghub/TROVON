static int __init dns323_pci_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
int irq;
irq = orion5x_pci_map_irq(dev, slot, pin);
if (irq != -1)
return irq;
return -1;
}
static int __init dns323_pci_init(void)
{
if (machine_is_dns323() && system_rev == DNS323_REV_A1)
pci_common_init(&dns323_pci);
return 0;
}
static int __init dns323_parse_hex_nibble(char n)
{
if (n >= '0' && n <= '9')
return n - '0';
if (n >= 'A' && n <= 'F')
return n - 'A' + 10;
if (n >= 'a' && n <= 'f')
return n - 'a' + 10;
return -1;
}
static int __init dns323_parse_hex_byte(const char *b)
{
int hi;
int lo;
hi = dns323_parse_hex_nibble(b[0]);
lo = dns323_parse_hex_nibble(b[1]);
if (hi < 0 || lo < 0)
return -1;
return (hi << 4) | lo;
}
static int __init dns323_read_mac_addr(void)
{
u_int8_t addr[6];
int i;
char *mac_page;
mac_page = ioremap(DNS323_NOR_BOOT_BASE + 0x7d0000 + 196480, 1024);
if (!mac_page)
return -ENOMEM;
for (i = 0; i < 5; i++) {
if (*(mac_page + (i * 3) + 2) != ':') {
goto error_fail;
}
}
for (i = 0; i < 6; i++) {
int byte;
byte = dns323_parse_hex_byte(mac_page + (i * 3));
if (byte < 0) {
goto error_fail;
}
addr[i] = byte;
}
iounmap(mac_page);
printk("DNS-323: Found ethernet MAC address: ");
for (i = 0; i < 6; i++)
printk("%.2x%s", addr[i], (i < 5) ? ":" : ".\n");
memcpy(dns323_eth_data.mac_addr, addr, 6);
return 0;
error_fail:
iounmap(mac_page);
return -EINVAL;
}
static int dns323_gpio_blink_set(unsigned gpio, int state,
unsigned long *delay_on, unsigned long *delay_off)
{
if (delay_on && delay_off && !*delay_on && !*delay_off)
*delay_on = *delay_off = ORION_BLINK_HALF_PERIOD;
switch(state) {
case GPIO_LED_NO_BLINK_LOW:
case GPIO_LED_NO_BLINK_HIGH:
orion_gpio_set_blink(gpio, 0);
gpio_set_value(gpio, state);
break;
case GPIO_LED_BLINK:
orion_gpio_set_blink(gpio, 1);
}
return 0;
}
static void dns323a_power_off(void)
{
pr_info("DNS-323: Triggering power-off...\n");
gpio_set_value(DNS323_GPIO_POWER_OFF, 1);
}
static void dns323b_power_off(void)
{
pr_info("DNS-323: Triggering power-off...\n");
gpio_set_value(DNS323_GPIO_POWER_OFF, 1);
mdelay(100);
gpio_set_value(DNS323_GPIO_POWER_OFF, 0);
}
static void dns323c_power_off(void)
{
pr_info("DNS-323: Triggering power-off...\n");
gpio_set_value(DNS323C_GPIO_POWER_OFF, 1);
}
static int dns323c_phy_fixup(struct phy_device *phy)
{
phy->dev_flags |= MARVELL_PHY_M1118_DNS323_LEDS;
return 0;
}
static int __init dns323_identify_rev(void)
{
u32 dev, rev, i, reg;
pr_debug("DNS-323: Identifying board ... \n");
orion5x_pcie_id(&dev, &rev);
if (dev == MV88F5181_DEV_ID) {
pr_debug("DNS-323: 5181 found, board is A1\n");
return DNS323_REV_A1;
}
pr_debug("DNS-323: 5182 found, board is B1 or C1, checking PHY...\n");
#define ETH_SMI_REG (ORION5X_ETH_VIRT_BASE + 0x2000 + 0x004)
#define SMI_BUSY 0x10000000
#define SMI_READ_VALID 0x08000000
#define SMI_OPCODE_READ 0x04000000
#define SMI_OPCODE_WRITE 0x00000000
for (i = 0; i < 1000; i++) {
reg = readl(ETH_SMI_REG);
if (!(reg & SMI_BUSY))
break;
}
if (i >= 1000) {
pr_warning("DNS-323: Timeout accessing PHY, assuming rev B1\n");
return DNS323_REV_B1;
}
writel((3 << 21) |
(8 << 16) |
SMI_OPCODE_READ, ETH_SMI_REG);
for (i = 0; i < 1000; i++) {
reg = readl(ETH_SMI_REG);
if (reg & SMI_READ_VALID)
break;
}
if (i >= 1000) {
pr_warning("DNS-323: Timeout reading PHY, assuming rev B1\n");
return DNS323_REV_B1;
}
pr_debug("DNS-323: Ethernet PHY ID 0x%x\n", reg & 0xffff);
switch(reg & 0xfff0) {
case 0x0cc0:
return DNS323_REV_B1;
case 0x0e10:
return DNS323_REV_C1;
default:
pr_warning("DNS-323: Unknown PHY ID 0x%04x, assuming rev B1\n",
reg & 0xffff);
}
return DNS323_REV_B1;
}
static void __init dns323_init(void)
{
orion5x_init();
system_rev = dns323_identify_rev();
pr_info("DNS-323: Identified HW revision %c1\n", 'A' + system_rev);
switch(system_rev) {
case DNS323_REV_A1:
orion5x_mpp_conf(dns323a_mpp_modes);
writel(0, MPP_DEV_CTRL);
break;
case DNS323_REV_B1:
orion5x_mpp_conf(dns323b_mpp_modes);
break;
case DNS323_REV_C1:
orion5x_mpp_conf(dns323c_mpp_modes);
break;
}
orion5x_setup_dev_boot_win(DNS323_NOR_BOOT_BASE, DNS323_NOR_BOOT_SIZE);
platform_device_register(&dns323_nor_flash);
switch(system_rev) {
case DNS323_REV_A1:
dns323ab_leds[0].active_low = 1;
gpio_request(DNS323_GPIO_LED_POWER1, "Power Led Enable");
gpio_direction_output(DNS323_GPIO_LED_POWER1, 0);
case DNS323_REV_B1:
i2c_register_board_info(0, dns323ab_i2c_devices,
ARRAY_SIZE(dns323ab_i2c_devices));
break;
case DNS323_REV_C1:
dns323_gpio_leds.dev.platform_data = &dns323c_led_data;
dns323_button_device.dev.platform_data = &dns323c_button_data;
i2c_register_board_info(0, dns323c_i2c_devices,
ARRAY_SIZE(dns323c_i2c_devices));
platform_device_register_simple("dns323c-fan", 0, NULL, 0);
phy_register_fixup_for_uid(MARVELL_PHY_ID_88E1118,
MARVELL_PHY_ID_MASK,
dns323c_phy_fixup);
}
platform_device_register(&dns323_gpio_leds);
platform_device_register(&dns323_button_device);
if (dns323_read_mac_addr() < 0)
printk("DNS-323: Failed to read MAC address\n");
orion5x_ehci0_init();
orion5x_eth_init(&dns323_eth_data);
orion5x_i2c_init();
orion5x_uart0_init();
switch(system_rev) {
case DNS323_REV_A1:
if (gpio_request(DNS323_GPIO_POWER_OFF, "POWEROFF") != 0 ||
gpio_direction_output(DNS323_GPIO_POWER_OFF, 0) != 0)
pr_err("DNS-323: failed to setup power-off GPIO\n");
pm_power_off = dns323a_power_off;
break;
case DNS323_REV_B1:
orion5x_sata_init(&dns323_sata_data);
if (gpio_request(DNS323_GPIO_SYSTEM_UP, "SYS_READY") == 0)
gpio_direction_output(DNS323_GPIO_SYSTEM_UP, 1);
if (gpio_request(DNS323_GPIO_POWER_OFF, "POWEROFF") != 0 ||
gpio_direction_output(DNS323_GPIO_POWER_OFF, 0) != 0)
pr_err("DNS-323: failed to setup power-off GPIO\n");
pm_power_off = dns323b_power_off;
break;
case DNS323_REV_C1:
orion5x_sata_init(&dns323_sata_data);
if (gpio_request(DNS323C_GPIO_POWER_OFF, "POWEROFF") != 0 ||
gpio_direction_output(DNS323C_GPIO_POWER_OFF, 0) != 0)
pr_err("DNS-323: failed to setup power-off GPIO\n");
pm_power_off = dns323c_power_off;
writel(0x5, ORION5X_SATA_VIRT_BASE | 0x2c);
break;
}
}
