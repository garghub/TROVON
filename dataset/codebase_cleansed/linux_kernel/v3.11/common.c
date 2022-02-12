void __init dove_map_io(void)
{
iotable_init(dove_io_desc, ARRAY_SIZE(dove_io_desc));
}
static struct clk __init *dove_register_gate(const char *name,
const char *parent, u8 bit_idx)
{
return clk_register_gate(NULL, name, parent, 0,
(void __iomem *)CLOCK_GATING_CONTROL,
bit_idx, 0, &gating_lock);
}
static void __init dove_clk_init(void)
{
struct clk *usb0, *usb1, *sata, *pex0, *pex1, *sdio0, *sdio1;
struct clk *nand, *camera, *i2s0, *i2s1, *crypto, *ac97, *pdma;
struct clk *xor0, *xor1, *ge, *gephy;
tclk = clk_register_fixed_rate(NULL, "tclk", NULL, CLK_IS_ROOT,
dove_tclk);
usb0 = dove_register_gate("usb0", "tclk", CLOCK_GATING_BIT_USB0);
usb1 = dove_register_gate("usb1", "tclk", CLOCK_GATING_BIT_USB1);
sata = dove_register_gate("sata", "tclk", CLOCK_GATING_BIT_SATA);
pex0 = dove_register_gate("pex0", "tclk", CLOCK_GATING_BIT_PCIE0);
pex1 = dove_register_gate("pex1", "tclk", CLOCK_GATING_BIT_PCIE1);
sdio0 = dove_register_gate("sdio0", "tclk", CLOCK_GATING_BIT_SDIO0);
sdio1 = dove_register_gate("sdio1", "tclk", CLOCK_GATING_BIT_SDIO1);
nand = dove_register_gate("nand", "tclk", CLOCK_GATING_BIT_NAND);
camera = dove_register_gate("camera", "tclk", CLOCK_GATING_BIT_CAMERA);
i2s0 = dove_register_gate("i2s0", "tclk", CLOCK_GATING_BIT_I2S0);
i2s1 = dove_register_gate("i2s1", "tclk", CLOCK_GATING_BIT_I2S1);
crypto = dove_register_gate("crypto", "tclk", CLOCK_GATING_BIT_CRYPTO);
ac97 = dove_register_gate("ac97", "tclk", CLOCK_GATING_BIT_AC97);
pdma = dove_register_gate("pdma", "tclk", CLOCK_GATING_BIT_PDMA);
xor0 = dove_register_gate("xor0", "tclk", CLOCK_GATING_BIT_XOR0);
xor1 = dove_register_gate("xor1", "tclk", CLOCK_GATING_BIT_XOR1);
gephy = dove_register_gate("gephy", "tclk", CLOCK_GATING_BIT_GIGA_PHY);
ge = dove_register_gate("ge", "gephy", CLOCK_GATING_BIT_GBE);
orion_clkdev_add(NULL, "orion_spi.0", tclk);
orion_clkdev_add(NULL, "orion_spi.1", tclk);
orion_clkdev_add(NULL, "orion_wdt", tclk);
orion_clkdev_add(NULL, "mv64xxx_i2c.0", tclk);
orion_clkdev_add(NULL, "orion-ehci.0", usb0);
orion_clkdev_add(NULL, "orion-ehci.1", usb1);
orion_clkdev_add(NULL, "mv643xx_eth_port.0", ge);
orion_clkdev_add(NULL, "sata_mv.0", sata);
orion_clkdev_add("0", "pcie", pex0);
orion_clkdev_add("1", "pcie", pex1);
orion_clkdev_add(NULL, "sdhci-dove.0", sdio0);
orion_clkdev_add(NULL, "sdhci-dove.1", sdio1);
orion_clkdev_add(NULL, "orion_nand", nand);
orion_clkdev_add(NULL, "cafe1000-ccic.0", camera);
orion_clkdev_add(NULL, "kirkwood-i2s.0", i2s0);
orion_clkdev_add(NULL, "kirkwood-i2s.1", i2s1);
orion_clkdev_add(NULL, "mv_crypto", crypto);
orion_clkdev_add(NULL, "dove-ac97", ac97);
orion_clkdev_add(NULL, "dove-pdma", pdma);
orion_clkdev_add(NULL, MV_XOR_NAME ".0", xor0);
orion_clkdev_add(NULL, MV_XOR_NAME ".1", xor1);
}
void __init dove_ehci0_init(void)
{
orion_ehci_init(DOVE_USB0_PHYS_BASE, IRQ_DOVE_USB0, EHCI_PHY_NA);
}
void __init dove_ehci1_init(void)
{
orion_ehci_1_init(DOVE_USB1_PHYS_BASE, IRQ_DOVE_USB1);
}
void __init dove_ge00_init(struct mv643xx_eth_platform_data *eth_data)
{
orion_ge00_init(eth_data, DOVE_GE00_PHYS_BASE,
IRQ_DOVE_GE00_SUM, IRQ_DOVE_GE00_ERR,
1600);
}
void __init dove_rtc_init(void)
{
orion_rtc_init(DOVE_RTC_PHYS_BASE, IRQ_DOVE_RTC);
}
void __init dove_sata_init(struct mv_sata_platform_data *sata_data)
{
orion_sata_init(sata_data, DOVE_SATA_PHYS_BASE, IRQ_DOVE_SATA);
}
void __init dove_uart0_init(void)
{
orion_uart0_init(DOVE_UART0_VIRT_BASE, DOVE_UART0_PHYS_BASE,
IRQ_DOVE_UART_0, tclk);
}
void __init dove_uart1_init(void)
{
orion_uart1_init(DOVE_UART1_VIRT_BASE, DOVE_UART1_PHYS_BASE,
IRQ_DOVE_UART_1, tclk);
}
void __init dove_uart2_init(void)
{
orion_uart2_init(DOVE_UART2_VIRT_BASE, DOVE_UART2_PHYS_BASE,
IRQ_DOVE_UART_2, tclk);
}
void __init dove_uart3_init(void)
{
orion_uart3_init(DOVE_UART3_VIRT_BASE, DOVE_UART3_PHYS_BASE,
IRQ_DOVE_UART_3, tclk);
}
void __init dove_spi0_init(void)
{
orion_spi_init(DOVE_SPI0_PHYS_BASE);
}
void __init dove_spi1_init(void)
{
orion_spi_1_init(DOVE_SPI1_PHYS_BASE);
}
void __init dove_i2c_init(void)
{
orion_i2c_init(DOVE_I2C_PHYS_BASE, IRQ_DOVE_I2C, 10);
}
void __init dove_init_early(void)
{
orion_time_set_base(TIMER_VIRT_BASE);
mvebu_mbus_init("marvell,dove-mbus",
BRIDGE_WINS_BASE, BRIDGE_WINS_SZ,
DOVE_MC_WINS_BASE, DOVE_MC_WINS_SZ);
}
static int __init dove_find_tclk(void)
{
return 166666667;
}
void __init dove_timer_init(void)
{
dove_tclk = dove_find_tclk();
orion_time_init(BRIDGE_VIRT_BASE, BRIDGE_INT_TIMER1_CLR,
IRQ_DOVE_BRIDGE, dove_tclk);
}
void __init dove_crypto_init(void)
{
orion_crypto_init(DOVE_CRYPT_PHYS_BASE, DOVE_CESA_PHYS_BASE,
DOVE_CESA_SIZE, IRQ_DOVE_CRYPTO);
}
void __init dove_xor0_init(void)
{
orion_xor0_init(DOVE_XOR0_PHYS_BASE, DOVE_XOR0_HIGH_PHYS_BASE,
IRQ_DOVE_XOR_00, IRQ_DOVE_XOR_01);
}
void __init dove_xor1_init(void)
{
orion_xor1_init(DOVE_XOR1_PHYS_BASE, DOVE_XOR1_HIGH_PHYS_BASE,
IRQ_DOVE_XOR_10, IRQ_DOVE_XOR_11);
}
void __init dove_sdio0_init(void)
{
platform_device_register(&dove_sdio0);
}
void __init dove_sdio1_init(void)
{
platform_device_register(&dove_sdio1);
}
void __init dove_setup_cpu_wins(void)
{
mvebu_mbus_add_window_remap_flags("pcie0.0",
DOVE_PCIE0_IO_PHYS_BASE,
DOVE_PCIE0_IO_SIZE,
DOVE_PCIE0_IO_BUS_BASE,
MVEBU_MBUS_PCI_IO);
mvebu_mbus_add_window_remap_flags("pcie1.0",
DOVE_PCIE1_IO_PHYS_BASE,
DOVE_PCIE1_IO_SIZE,
DOVE_PCIE1_IO_BUS_BASE,
MVEBU_MBUS_PCI_IO);
mvebu_mbus_add_window_remap_flags("pcie0.0",
DOVE_PCIE0_MEM_PHYS_BASE,
DOVE_PCIE0_MEM_SIZE,
MVEBU_MBUS_NO_REMAP,
MVEBU_MBUS_PCI_MEM);
mvebu_mbus_add_window_remap_flags("pcie1.0",
DOVE_PCIE1_MEM_PHYS_BASE,
DOVE_PCIE1_MEM_SIZE,
MVEBU_MBUS_NO_REMAP,
MVEBU_MBUS_PCI_MEM);
mvebu_mbus_add_window("cesa", DOVE_CESA_PHYS_BASE,
DOVE_CESA_SIZE);
mvebu_mbus_add_window("bootrom", DOVE_BOOTROM_PHYS_BASE,
DOVE_BOOTROM_SIZE);
mvebu_mbus_add_window("scratchpad", DOVE_SCRATCHPAD_PHYS_BASE,
DOVE_SCRATCHPAD_SIZE);
}
void __init dove_init(void)
{
pr_info("Dove 88AP510 SoC, TCLK = %d MHz.\n",
(dove_tclk + 499999) / 1000000);
#ifdef CONFIG_CACHE_TAUROS2
tauros2_init(0);
#endif
dove_setup_cpu_wins();
dove_clk_init();
dove_rtc_init();
dove_xor0_init();
dove_xor1_init();
}
void dove_restart(enum reboot_mode mode, const char *cmd)
{
writel(SOFT_RESET_OUT_EN, RSTOUTn_MASK);
writel(SOFT_RESET, SYSTEM_SOFT_RESET);
while (1)
;
}
