static void __init __iomem *win_cfg_base(int win)
{
return (void __iomem *)((win < 8) ? WIN0_OFF(win) : WIN8_OFF(win));
}
static int __init cpu_win_can_remap(int win)
{
if (win < 8)
return 1;
return 0;
}
static void __init setup_cpu_win(int win, u32 base, u32 size,
u8 target, u8 attr, int remap)
{
void __iomem *addr = win_cfg_base(win);
u32 ctrl;
base &= 0xffff0000;
ctrl = ((size - 1) & 0xffff0000) | (attr << 8) | (target << 4) | 1;
writel(base, addr + WIN_BASE_OFF);
writel(ctrl, addr + WIN_CTRL_OFF);
if (cpu_win_can_remap(win)) {
if (remap < 0)
remap = base;
writel(remap & 0xffff0000, addr + WIN_REMAP_LO_OFF);
writel(0, addr + WIN_REMAP_HI_OFF);
}
}
void __init mv78xx0_setup_cpu_mbus(void)
{
void __iomem *addr;
int i;
int cs;
for (i = 0; i < 14; i++) {
addr = win_cfg_base(i);
writel(0, addr + WIN_BASE_OFF);
writel(0, addr + WIN_CTRL_OFF);
if (cpu_win_can_remap(i)) {
writel(0, addr + WIN_REMAP_LO_OFF);
writel(0, addr + WIN_REMAP_HI_OFF);
}
}
mv78xx0_mbus_dram_info.mbus_dram_target_id = TARGET_DDR;
if (mv78xx0_core_index() == 0)
addr = (void __iomem *)DDR_WINDOW_CPU0_BASE;
else
addr = (void __iomem *)DDR_WINDOW_CPU1_BASE;
for (i = 0, cs = 0; i < 4; i++) {
u32 base = readl(addr + DDR_BASE_CS_OFF(i));
u32 size = readl(addr + DDR_SIZE_CS_OFF(i));
if (size & 1) {
struct mbus_dram_window *w;
w = &mv78xx0_mbus_dram_info.cs[cs++];
w->cs_index = i;
w->mbus_attr = 0xf & ~(1 << i);
w->base = base & 0xffff0000;
w->size = (size | 0x0000ffff) + 1;
}
}
mv78xx0_mbus_dram_info.num_cs = cs;
}
void __init mv78xx0_setup_pcie_io_win(int window, u32 base, u32 size,
int maj, int min)
{
setup_cpu_win(window, base, size, TARGET_PCIE(maj),
ATTR_PCIE_IO(min), -1);
}
void __init mv78xx0_setup_pcie_mem_win(int window, u32 base, u32 size,
int maj, int min)
{
setup_cpu_win(window, base, size, TARGET_PCIE(maj),
ATTR_PCIE_MEM(min), -1);
}
