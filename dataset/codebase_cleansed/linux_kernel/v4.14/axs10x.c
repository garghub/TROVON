static void __init axs10x_enable_gpio_intc_wire(void)
{
#define GPIO_INTEN (AXC001_GPIO_INTC + 0x30)
#define GPIO_INTMASK (AXC001_GPIO_INTC + 0x34)
#define GPIO_INTTYPE_LEVEL (AXC001_GPIO_INTC + 0x38)
#define GPIO_INT_POLARITY (AXC001_GPIO_INTC + 0x3c)
#define MB_TO_GPIO_IRQ 12
iowrite32(~(1 << MB_TO_GPIO_IRQ), (void __iomem *) GPIO_INTMASK);
iowrite32(0, (void __iomem *) GPIO_INTTYPE_LEVEL);
iowrite32(~0, (void __iomem *) GPIO_INT_POLARITY);
iowrite32(1 << MB_TO_GPIO_IRQ, (void __iomem *) GPIO_INTEN);
}
static void __init axs10x_print_board_ver(unsigned int creg, const char *str)
{
union ver {
struct {
#ifdef CONFIG_CPU_BIG_ENDIAN
unsigned int pad:11, y:12, m:4, d:5;
#else
unsigned int d:5, m:4, y:12, pad:11;
#endif
};
unsigned int val;
} board;
board.val = ioread32((void __iomem *)creg);
pr_info("AXS: %s FPGA Date: %u-%u-%u\n", str, board.d, board.m,
board.y);
}
static void __init axs10x_early_init(void)
{
int mb_rev;
char mb[32];
if (ioread32((void __iomem *) CREG_MB_CONFIG) & (1 << 28))
mb_rev = 3;
else
mb_rev = 2;
axs10x_enable_gpio_intc_wire();
iowrite32((1 << 5), (void __iomem *) CREG_MB_SW_RESET);
scnprintf(mb, 32, "MainBoard v%d", mb_rev);
axs10x_print_board_ver(CREG_MB_VER, mb);
}
static noinline void __init
axs101_set_memmap(void __iomem *base, const struct aperture map[16])
{
unsigned int slave_select, slave_offset;
int i;
slave_select = slave_offset = 0;
for (i = 0; i < 8; i++) {
slave_select |= map[i].slave_sel << (i << 2);
slave_offset |= map[i].slave_off << (i << 2);
}
iowrite32(slave_select, base + 0x0);
iowrite32(slave_offset, base + 0x8);
slave_select = slave_offset = 0;
for (i = 0; i < 8; i++) {
slave_select |= map[i+8].slave_sel << (i << 2);
slave_offset |= map[i+8].slave_off << (i << 2);
}
iowrite32(slave_select, base + 0x4);
iowrite32(slave_offset, base + 0xC);
}
static void __init axs101_early_init(void)
{
int i;
axs101_set_memmap((void __iomem *) CREG_CPU_ADDR_770, axc001_memmap);
iowrite32(1, (void __iomem *) CREG_CPU_ADDR_770_UPD);
axs101_set_memmap((void __iomem *) CREG_CPU_ADDR_TUNN,
axc001_axi_tunnel_memmap);
iowrite32(1, (void __iomem *) CREG_CPU_ADDR_TUNN_UPD);
for (i = AXS_MB_MST_TUNNEL_CPU; i <= AXS_MB_MST_USB_OHCI; i++)
axs101_set_memmap((void __iomem *) AXS_MB_CREG + (i << 4),
axs_mb_memmap);
iowrite32(0x3ff, (void __iomem *) AXS_MB_CREG + 0x100);
iowrite32(0x01, (void __iomem *) CREG_CPU_GPIO_UART_MUX);
iowrite32(0x01, (void __iomem *) CREG_MB_IRQ_MUX);
iowrite32(0x18, (void __iomem *) CREG_MB_SW_RESET);
iowrite32(0x52, (void __iomem *) CREG_CPU_ARC770_IRQ_MUX);
axs10x_early_init();
}
static void __init axs103_early_init(void)
{
#ifdef CONFIG_ARC_MCIP
unsigned int num_cores = (read_aux_reg(ARC_REG_MCIP_BCR) >> 16) & 0x3F;
if (num_cores > 2) {
u32 freq = 50, orig;
int off = fdt_path_offset(initial_boot_params, "/cpu_card/core_clk");
const struct fdt_property *prop;
prop = fdt_get_property(initial_boot_params, off,
"clock-frequency", NULL);
orig = be32_to_cpu(*(u32*)(prop->data)) / 1000000;
if (freq != orig ) {
freq = cpu_to_be32(freq * 1000000);
fdt_setprop_inplace(initial_boot_params, off,
"clock-frequency", &freq, sizeof(freq));
}
}
#endif
iowrite32(0x01, (void __iomem *) CREG_CPU_GPIO_UART_MUX);
iowrite32((0x00100000U | 0x000C0000U | 0x00003322U),
(void __iomem *) CREG_CPU_TUN_IO_CTRL);
iowrite32(12, (void __iomem *) (CREG_CPU_AXI_M0_IRQ_MUX
+ (AXC003_MST_HS38 << 2)));
iowrite32(0x01, (void __iomem *) CREG_MB_IRQ_MUX);
axs10x_print_board_ver(AXC003_CREG + 4088, "AXC003 CPU Card");
axs10x_early_init();
}
