const struct mbus_dram_target_info *mv_mbus_dram_info(void)
{
return &mvebu_mbus_dram_info;
}
static void mvebu_mbus_read_window(struct mvebu_mbus_state *mbus,
int win, int *enabled, u64 *base,
u32 *size, u8 *target, u8 *attr,
u64 *remap)
{
void __iomem *addr = mbus->mbuswins_base +
mbus->soc->win_cfg_offset(win);
u32 basereg = readl(addr + WIN_BASE_OFF);
u32 ctrlreg = readl(addr + WIN_CTRL_OFF);
if (!(ctrlreg & WIN_CTRL_ENABLE)) {
*enabled = 0;
return;
}
*enabled = 1;
*base = ((u64)basereg & WIN_BASE_HIGH) << 32;
*base |= (basereg & WIN_BASE_LOW);
*size = (ctrlreg | ~WIN_CTRL_SIZE_MASK) + 1;
if (target)
*target = (ctrlreg & WIN_CTRL_TGT_MASK) >> WIN_CTRL_TGT_SHIFT;
if (attr)
*attr = (ctrlreg & WIN_CTRL_ATTR_MASK) >> WIN_CTRL_ATTR_SHIFT;
if (remap) {
if (win < mbus->soc->num_remappable_wins) {
u32 remap_low = readl(addr + WIN_REMAP_LO_OFF);
u32 remap_hi = readl(addr + WIN_REMAP_HI_OFF);
*remap = ((u64)remap_hi << 32) | remap_low;
} else
*remap = 0;
}
}
static void mvebu_mbus_disable_window(struct mvebu_mbus_state *mbus,
int win)
{
void __iomem *addr;
addr = mbus->mbuswins_base + mbus->soc->win_cfg_offset(win);
writel(0, addr + WIN_BASE_OFF);
writel(0, addr + WIN_CTRL_OFF);
if (win < mbus->soc->num_remappable_wins) {
writel(0, addr + WIN_REMAP_LO_OFF);
writel(0, addr + WIN_REMAP_HI_OFF);
}
}
static int mvebu_mbus_window_is_free(struct mvebu_mbus_state *mbus,
const int win)
{
void __iomem *addr = mbus->mbuswins_base +
mbus->soc->win_cfg_offset(win);
u32 ctrl = readl(addr + WIN_CTRL_OFF);
return !(ctrl & WIN_CTRL_ENABLE);
}
static int mvebu_mbus_window_conflicts(struct mvebu_mbus_state *mbus,
phys_addr_t base, size_t size,
u8 target, u8 attr)
{
u64 end = (u64)base + size;
int win;
for (win = 0; win < mbus->soc->num_wins; win++) {
u64 wbase, wend;
u32 wsize;
u8 wtarget, wattr;
int enabled;
mvebu_mbus_read_window(mbus, win,
&enabled, &wbase, &wsize,
&wtarget, &wattr, NULL);
if (!enabled)
continue;
wend = wbase + wsize;
if ((u64)base < wend && end > wbase)
return 0;
if (target == wtarget && attr == wattr)
return 0;
}
return 1;
}
static int mvebu_mbus_find_window(struct mvebu_mbus_state *mbus,
phys_addr_t base, size_t size)
{
int win;
for (win = 0; win < mbus->soc->num_wins; win++) {
u64 wbase;
u32 wsize;
int enabled;
mvebu_mbus_read_window(mbus, win,
&enabled, &wbase, &wsize,
NULL, NULL, NULL);
if (!enabled)
continue;
if (base == wbase && size == wsize)
return win;
}
return -ENODEV;
}
static int mvebu_mbus_setup_window(struct mvebu_mbus_state *mbus,
int win, phys_addr_t base, size_t size,
phys_addr_t remap, u8 target,
u8 attr)
{
void __iomem *addr = mbus->mbuswins_base +
mbus->soc->win_cfg_offset(win);
u32 ctrl, remap_addr;
ctrl = ((size - 1) & WIN_CTRL_SIZE_MASK) |
(attr << WIN_CTRL_ATTR_SHIFT) |
(target << WIN_CTRL_TGT_SHIFT) |
WIN_CTRL_ENABLE;
writel(base & WIN_BASE_LOW, addr + WIN_BASE_OFF);
writel(ctrl, addr + WIN_CTRL_OFF);
if (win < mbus->soc->num_remappable_wins) {
if (remap == MVEBU_MBUS_NO_REMAP)
remap_addr = base;
else
remap_addr = remap;
writel(remap_addr & WIN_REMAP_LOW, addr + WIN_REMAP_LO_OFF);
writel(0, addr + WIN_REMAP_HI_OFF);
}
return 0;
}
static int mvebu_mbus_alloc_window(struct mvebu_mbus_state *mbus,
phys_addr_t base, size_t size,
phys_addr_t remap, u8 target,
u8 attr)
{
int win;
if (remap == MVEBU_MBUS_NO_REMAP) {
for (win = mbus->soc->num_remappable_wins;
win < mbus->soc->num_wins; win++)
if (mvebu_mbus_window_is_free(mbus, win))
return mvebu_mbus_setup_window(mbus, win, base,
size, remap,
target, attr);
}
for (win = 0; win < mbus->soc->num_wins; win++)
if (mvebu_mbus_window_is_free(mbus, win))
return mvebu_mbus_setup_window(mbus, win, base, size,
remap, target, attr);
return -ENOMEM;
}
static int mvebu_sdram_debug_show_orion(struct mvebu_mbus_state *mbus,
struct seq_file *seq, void *v)
{
int i;
for (i = 0; i < 4; i++) {
u32 basereg = readl(mbus->sdramwins_base + DDR_BASE_CS_OFF(i));
u32 sizereg = readl(mbus->sdramwins_base + DDR_SIZE_CS_OFF(i));
u64 base;
u32 size;
if (!(sizereg & DDR_SIZE_ENABLED)) {
seq_printf(seq, "[%d] disabled\n", i);
continue;
}
base = ((u64)basereg & DDR_BASE_CS_HIGH_MASK) << 32;
base |= basereg & DDR_BASE_CS_LOW_MASK;
size = (sizereg | ~DDR_SIZE_MASK);
seq_printf(seq, "[%d] %016llx - %016llx : cs%d\n",
i, (unsigned long long)base,
(unsigned long long)base + size + 1,
(sizereg & DDR_SIZE_CS_MASK) >> DDR_SIZE_CS_SHIFT);
}
return 0;
}
static int mvebu_sdram_debug_show_dove(struct mvebu_mbus_state *mbus,
struct seq_file *seq, void *v)
{
int i;
for (i = 0; i < 2; i++) {
u32 map = readl(mbus->sdramwins_base + DOVE_DDR_BASE_CS_OFF(i));
u64 base;
u32 size;
if (!(map & 1)) {
seq_printf(seq, "[%d] disabled\n", i);
continue;
}
base = map & 0xff800000;
size = 0x100000 << (((map & 0x000f0000) >> 16) - 4);
seq_printf(seq, "[%d] %016llx - %016llx : cs%d\n",
i, (unsigned long long)base,
(unsigned long long)base + size, i);
}
return 0;
}
static int mvebu_sdram_debug_show(struct seq_file *seq, void *v)
{
struct mvebu_mbus_state *mbus = &mbus_state;
return mbus->soc->show_cpu_target(mbus, seq, v);
}
static int mvebu_sdram_debug_open(struct inode *inode, struct file *file)
{
return single_open(file, mvebu_sdram_debug_show, inode->i_private);
}
static int mvebu_devs_debug_show(struct seq_file *seq, void *v)
{
struct mvebu_mbus_state *mbus = &mbus_state;
int win;
for (win = 0; win < mbus->soc->num_wins; win++) {
u64 wbase, wremap;
u32 wsize;
u8 wtarget, wattr;
int enabled, i;
const char *name;
mvebu_mbus_read_window(mbus, win,
&enabled, &wbase, &wsize,
&wtarget, &wattr, &wremap);
if (!enabled) {
seq_printf(seq, "[%02d] disabled\n", win);
continue;
}
for (i = 0; mbus->soc->map[i].name; i++)
if (mbus->soc->map[i].target == wtarget &&
mbus->soc->map[i].attr ==
(wattr & mbus->soc->map[i].attrmask))
break;
name = mbus->soc->map[i].name ?: "unknown";
seq_printf(seq, "[%02d] %016llx - %016llx : %s",
win, (unsigned long long)wbase,
(unsigned long long)(wbase + wsize), name);
if (win < mbus->soc->num_remappable_wins) {
seq_printf(seq, " (remap %016llx)\n",
(unsigned long long)wremap);
} else
seq_printf(seq, "\n");
}
return 0;
}
static int mvebu_devs_debug_open(struct inode *inode, struct file *file)
{
return single_open(file, mvebu_devs_debug_show, inode->i_private);
}
static unsigned int orion_mbus_win_offset(int win)
{
return win << 4;
}
static unsigned int armada_370_xp_mbus_win_offset(int win)
{
if (win < 8)
return win << 4;
else
return 0x90 + ((win - 8) << 3);
}
static unsigned int mv78xx0_mbus_win_offset(int win)
{
if (win < 8)
return win << 4;
else
return 0x900 + ((win - 8) << 4);
}
static void __init
mvebu_mbus_default_setup_cpu_target(struct mvebu_mbus_state *mbus)
{
int i;
int cs;
mvebu_mbus_dram_info.mbus_dram_target_id = TARGET_DDR;
for (i = 0, cs = 0; i < 4; i++) {
u32 base = readl(mbus->sdramwins_base + DDR_BASE_CS_OFF(i));
u32 size = readl(mbus->sdramwins_base + DDR_SIZE_CS_OFF(i));
if ((size & DDR_SIZE_ENABLED) &&
!(base & DDR_BASE_CS_HIGH_MASK)) {
struct mbus_dram_window *w;
w = &mvebu_mbus_dram_info.cs[cs++];
w->cs_index = i;
w->mbus_attr = 0xf & ~(1 << i);
if (mbus->hw_io_coherency)
w->mbus_attr |= ATTR_HW_COHERENCY;
w->base = base & DDR_BASE_CS_LOW_MASK;
w->size = (size | ~DDR_SIZE_MASK) + 1;
}
}
mvebu_mbus_dram_info.num_cs = cs;
}
static void __init
mvebu_mbus_dove_setup_cpu_target(struct mvebu_mbus_state *mbus)
{
int i;
int cs;
mvebu_mbus_dram_info.mbus_dram_target_id = TARGET_DDR;
for (i = 0, cs = 0; i < 2; i++) {
u32 map = readl(mbus->sdramwins_base + DOVE_DDR_BASE_CS_OFF(i));
if (map & 1) {
struct mbus_dram_window *w;
w = &mvebu_mbus_dram_info.cs[cs++];
w->cs_index = i;
w->mbus_attr = 0;
w->base = map & 0xff800000;
w->size = 0x100000 << (((map & 0x000f0000) >> 16) - 4);
}
}
mvebu_mbus_dram_info.num_cs = cs;
}
int mvebu_mbus_add_window_remap_flags(const char *devname, phys_addr_t base,
size_t size, phys_addr_t remap,
unsigned int flags)
{
struct mvebu_mbus_state *s = &mbus_state;
u8 target, attr;
int i;
if (!s->soc->map)
return -ENODEV;
for (i = 0; s->soc->map[i].name; i++)
if (!strcmp(s->soc->map[i].name, devname))
break;
if (!s->soc->map[i].name) {
pr_err("unknown device '%s'\n", devname);
return -ENODEV;
}
target = s->soc->map[i].target;
attr = s->soc->map[i].attr;
if (flags == MVEBU_MBUS_PCI_MEM)
attr |= 0x8;
else if (flags == MVEBU_MBUS_PCI_WA)
attr |= 0x28;
if (!mvebu_mbus_window_conflicts(s, base, size, target, attr)) {
pr_err("cannot add window '%s', conflicts with another window\n",
devname);
return -EINVAL;
}
return mvebu_mbus_alloc_window(s, base, size, remap, target, attr);
}
int mvebu_mbus_add_window(const char *devname, phys_addr_t base, size_t size)
{
return mvebu_mbus_add_window_remap_flags(devname, base, size,
MVEBU_MBUS_NO_REMAP, 0);
}
int mvebu_mbus_del_window(phys_addr_t base, size_t size)
{
int win;
win = mvebu_mbus_find_window(&mbus_state, base, size);
if (win < 0)
return win;
mvebu_mbus_disable_window(&mbus_state, win);
return 0;
}
static __init int mvebu_mbus_debugfs_init(void)
{
struct mvebu_mbus_state *s = &mbus_state;
if (!s->mbuswins_base)
return 0;
s->debugfs_root = debugfs_create_dir("mvebu-mbus", NULL);
if (s->debugfs_root) {
s->debugfs_sdram = debugfs_create_file("sdram", S_IRUGO,
s->debugfs_root, NULL,
&mvebu_sdram_debug_fops);
s->debugfs_devs = debugfs_create_file("devices", S_IRUGO,
s->debugfs_root, NULL,
&mvebu_devs_debug_fops);
}
return 0;
}
int __init mvebu_mbus_init(const char *soc, phys_addr_t mbuswins_phys_base,
size_t mbuswins_size,
phys_addr_t sdramwins_phys_base,
size_t sdramwins_size)
{
struct mvebu_mbus_state *mbus = &mbus_state;
const struct of_device_id *of_id;
int win;
for (of_id = of_mvebu_mbus_ids; of_id->compatible; of_id++)
if (!strcmp(of_id->compatible, soc))
break;
if (!of_id->compatible) {
pr_err("could not find a matching SoC family\n");
return -ENODEV;
}
mbus->soc = of_id->data;
mbus->mbuswins_base = ioremap(mbuswins_phys_base, mbuswins_size);
if (!mbus->mbuswins_base)
return -ENOMEM;
mbus->sdramwins_base = ioremap(sdramwins_phys_base, sdramwins_size);
if (!mbus->sdramwins_base) {
iounmap(mbus_state.mbuswins_base);
return -ENOMEM;
}
if (of_find_compatible_node(NULL, NULL, "marvell,coherency-fabric"))
mbus->hw_io_coherency = 1;
for (win = 0; win < mbus->soc->num_wins; win++)
mvebu_mbus_disable_window(mbus, win);
mbus->soc->setup_cpu_target(mbus);
return 0;
}
