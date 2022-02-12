int bcm63xx_get_fallback_sprom(struct ssb_bus *bus, struct ssb_sprom *out)
{
if (bus->bustype == SSB_BUSTYPE_PCI) {
memcpy(out, &bcm63xx_sprom, sizeof(struct ssb_sprom));
return 0;
} else {
printk(KERN_ERR PFX "unable to fill SPROM for given bustype.\n");
return -EINVAL;
}
}
const char *board_get_name(void)
{
return board.name;
}
static int board_get_mac_address(u8 *mac)
{
u8 *p;
int count;
if (mac_addr_used >= nvram.mac_addr_count) {
printk(KERN_ERR PFX "not enough mac address\n");
return -ENODEV;
}
memcpy(mac, nvram.mac_addr_base, ETH_ALEN);
p = mac + ETH_ALEN - 1;
count = mac_addr_used;
while (count--) {
do {
(*p)++;
if (*p != 0)
break;
p--;
} while (p != mac);
}
if (p == mac) {
printk(KERN_ERR PFX "unable to fetch mac address\n");
return -ENODEV;
}
mac_addr_used++;
return 0;
}
void __init board_prom_init(void)
{
unsigned int check_len, i;
u8 *boot_addr, *cfe, *p;
char cfe_version[32];
u32 val;
if (BCMCPU_IS_6328())
val = 0x18000000;
else {
val = bcm_mpi_readl(MPI_CSBASE_REG(0));
val &= MPI_CSBASE_BASE_MASK;
}
boot_addr = (u8 *)KSEG1ADDR(val);
cfe = boot_addr + BCM963XX_CFE_VERSION_OFFSET;
if (!memcmp(cfe, "cfe-v", 5))
snprintf(cfe_version, sizeof(cfe_version), "%u.%u.%u-%u.%u",
cfe[5], cfe[6], cfe[7], cfe[8], cfe[9]);
else
strcpy(cfe_version, "unknown");
printk(KERN_INFO PFX "CFE version: %s\n", cfe_version);
memcpy(&nvram, boot_addr + BCM963XX_NVRAM_OFFSET, sizeof(nvram));
if (nvram.version <= 4)
check_len = offsetof(struct bcm963xx_nvram, checksum_old);
else
check_len = sizeof(nvram);
val = 0;
p = (u8 *)&nvram;
while (check_len--)
val += *p;
if (val) {
printk(KERN_ERR PFX "invalid nvram checksum\n");
return;
}
for (i = 0; i < ARRAY_SIZE(bcm963xx_boards); i++) {
if (strncmp(nvram.name, bcm963xx_boards[i]->name,
sizeof(nvram.name)))
continue;
memcpy(&board, bcm963xx_boards[i], sizeof(board));
break;
}
if (!board.name[0]) {
char name[17];
memcpy(name, nvram.name, 16);
name[16] = 0;
printk(KERN_ERR PFX "unknown bcm963xx board: %s\n",
name);
return;
}
val = 0;
#ifdef CONFIG_PCI
if (board.has_pci) {
bcm63xx_pci_enabled = 1;
if (BCMCPU_IS_6348())
val |= GPIO_MODE_6348_G2_PCI;
}
#endif
if (board.has_pccard) {
if (BCMCPU_IS_6348())
val |= GPIO_MODE_6348_G1_MII_PCCARD;
}
if (board.has_enet0 && !board.enet0.use_internal_phy) {
if (BCMCPU_IS_6348())
val |= GPIO_MODE_6348_G3_EXT_MII |
GPIO_MODE_6348_G0_EXT_MII;
}
if (board.has_enet1 && !board.enet1.use_internal_phy) {
if (BCMCPU_IS_6348())
val |= GPIO_MODE_6348_G3_EXT_MII |
GPIO_MODE_6348_G0_EXT_MII;
}
bcm_gpio_writel(val, GPIO_MODE_REG);
}
void __init board_setup(void)
{
if (!board.name[0])
panic("unable to detect bcm963xx board");
printk(KERN_INFO PFX "board name: %s\n", board.name);
if (bcm63xx_get_cpu_id() != board.expected_cpu_id)
panic("unexpected CPU for bcm963xx board");
}
int __init board_register_devices(void)
{
if (board.has_uart0)
bcm63xx_uart_register(0);
if (board.has_uart1)
bcm63xx_uart_register(1);
if (board.has_pccard)
bcm63xx_pcmcia_register();
if (board.has_enet0 &&
!board_get_mac_address(board.enet0.mac_addr))
bcm63xx_enet_register(0, &board.enet0);
if (board.has_enet1 &&
!board_get_mac_address(board.enet1.mac_addr))
bcm63xx_enet_register(1, &board.enet1);
if (board.has_dsp)
bcm63xx_dsp_register(&board.dsp);
#ifdef CONFIG_SSB_PCIHOST
if (!board_get_mac_address(bcm63xx_sprom.il0mac)) {
memcpy(bcm63xx_sprom.et0mac, bcm63xx_sprom.il0mac, ETH_ALEN);
memcpy(bcm63xx_sprom.et1mac, bcm63xx_sprom.il0mac, ETH_ALEN);
if (ssb_arch_register_fallback_sprom(
&bcm63xx_get_fallback_sprom) < 0)
pr_err(PFX "failed to register fallback SPROM\n");
}
#endif
bcm63xx_spi_register();
bcm63xx_flash_register();
bcm63xx_led_data.num_leds = ARRAY_SIZE(board.leds);
bcm63xx_led_data.leds = board.leds;
platform_device_register(&bcm63xx_gpio_leds);
return 0;
}
