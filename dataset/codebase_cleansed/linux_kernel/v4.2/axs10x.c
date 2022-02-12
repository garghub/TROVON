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
static inline void __init
write_cgu_reg(uint32_t value, void __iomem *reg, void __iomem *lock_reg)
{
unsigned int loops = 128 * 1024, ctr;
iowrite32(value, reg);
ctr = loops;
while (((ioread32(lock_reg) & 1) == 1) && ctr--)
cpu_relax();
ctr = loops;
while (((ioread32(lock_reg) & 1) == 0) && ctr--)
cpu_relax();
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
static unsigned int __init axs103_get_freq(void)
{
union pll_reg idiv, fbdiv, odiv;
unsigned int f = 33333333;
idiv.val = ioread32((void __iomem *)AXC003_CGU + 0x80 + 0);
fbdiv.val = ioread32((void __iomem *)AXC003_CGU + 0x80 + 4);
odiv.val = ioread32((void __iomem *)AXC003_CGU + 0x80 + 8);
if (idiv.bypass != 1)
f = f / (idiv.low + idiv.high);
if (fbdiv.bypass != 1)
f = f * (fbdiv.low + fbdiv.high);
if (odiv.bypass != 1)
f = f / (odiv.low + odiv.high);
f = (f + 500000) / 1000000;
return f;
}
static inline unsigned int __init encode_div(unsigned int id, int upd)
{
union pll_reg div;
div.val = 0;
div.noupd = !upd;
div.bypass = id == 1 ? 1 : 0;
div.edge = (id%2 == 0) ? 0 : 1;
div.low = (id%2 == 0) ? id >> 1 : (id >> 1)+1;
div.high = id >> 1;
return div.val;
}
noinline static void __init
axs103_set_freq(unsigned int id, unsigned int fd, unsigned int od)
{
write_cgu_reg(encode_div(id, 0),
(void __iomem *)AXC003_CGU + 0x80 + 0,
(void __iomem *)AXC003_CGU + 0x110);
write_cgu_reg(encode_div(fd, 0),
(void __iomem *)AXC003_CGU + 0x80 + 4,
(void __iomem *)AXC003_CGU + 0x110);
write_cgu_reg(encode_div(od, 1),
(void __iomem *)AXC003_CGU + 0x80 + 8,
(void __iomem *)AXC003_CGU + 0x110);
}
static void __init axs103_early_init(void)
{
#ifdef CONFIG_ARC_MCIP
unsigned int num_cores = (read_aux_reg(ARC_REG_MCIP_BCR) >> 16) & 0x3F;
if (num_cores > 2)
arc_set_core_freq(50 * 1000000);
#endif
switch (arc_get_core_freq()/1000000) {
case 33:
axs103_set_freq(1, 1, 1);
break;
case 50:
axs103_set_freq(1, 30, 20);
break;
case 75:
axs103_set_freq(2, 45, 10);
break;
case 90:
axs103_set_freq(2, 54, 10);
break;
case 100:
axs103_set_freq(1, 30, 10);
break;
case 125:
axs103_set_freq(2, 45, 6);
break;
default:
arc_set_core_freq(axs103_get_freq() * 1000000);
break;
}
pr_info("Freq is %dMHz\n", axs103_get_freq());
iowrite32(0x01, (void __iomem *) CREG_CPU_GPIO_UART_MUX);
iowrite32((0x00100000U | 0x000C0000U | 0x00003322U),
(void __iomem *) CREG_CPU_TUN_IO_CTRL);
iowrite32(12, (void __iomem *) (CREG_CPU_AXI_M0_IRQ_MUX
+ (AXC003_MST_HS38 << 2)));
iowrite32(0x01, (void __iomem *) CREG_MB_IRQ_MUX);
axs10x_print_board_ver(AXC003_CREG + 4088, "AXC003 CPU Card");
axs10x_early_init();
#ifdef CONFIG_ARC_MCIP
mcip_init_early_smp();
#endif
}
