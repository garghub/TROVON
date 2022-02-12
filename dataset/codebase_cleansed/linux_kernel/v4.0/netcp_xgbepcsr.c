static void netcp_xgbe_serdes_cmu_init(void __iomem *serdes_regs)
{
int i;
for (i = 0; i < ARRAY_SIZE(cfg_phyb_1p25g_156p25mhz_cmu0); i++) {
reg_rmw(serdes_regs + cfg_phyb_1p25g_156p25mhz_cmu0[i].ofs,
cfg_phyb_1p25g_156p25mhz_cmu0[i].val,
cfg_phyb_1p25g_156p25mhz_cmu0[i].mask);
}
for (i = 0; i < ARRAY_SIZE(cfg_phyb_10p3125g_156p25mhz_cmu1); i++) {
reg_rmw(serdes_regs + cfg_phyb_10p3125g_156p25mhz_cmu1[i].ofs,
cfg_phyb_10p3125g_156p25mhz_cmu1[i].val,
cfg_phyb_10p3125g_156p25mhz_cmu1[i].mask);
}
}
static void netcp_xgbe_serdes_lane_config(
void __iomem *serdes_regs, int lane)
{
int i;
for (i = 0; i < ARRAY_SIZE(cfg_phyb_10p3125g_16bit_lane); i++) {
reg_rmw(serdes_regs +
cfg_phyb_10p3125g_16bit_lane[i].ofs +
(0x200 * lane),
cfg_phyb_10p3125g_16bit_lane[i].val,
cfg_phyb_10p3125g_16bit_lane[i].mask);
}
reg_rmw(serdes_regs + (0x200 * lane) + 0x0380,
0x00000000, 0x00000010);
reg_rmw(serdes_regs + (0x200 * lane) + 0x03c0,
0x00000000, 0x00000200);
}
static void netcp_xgbe_serdes_com_enable(void __iomem *serdes_regs)
{
int i;
for (i = 0; i < ARRAY_SIZE(cfg_phyb_10p3125g_comlane); i++) {
reg_rmw(serdes_regs + cfg_phyb_10p3125g_comlane[i].ofs,
cfg_phyb_10p3125g_comlane[i].val,
cfg_phyb_10p3125g_comlane[i].mask);
}
}
static void netcp_xgbe_serdes_lane_enable(
void __iomem *serdes_regs, int lane)
{
writel(0xe0e9e038, serdes_regs + 0x1fe0 + (4 * lane));
}
static void netcp_xgbe_serdes_phyb_rst_clr(void __iomem *serdes_regs)
{
reg_rmw(serdes_regs + 0x0a00, 0x0000001f, 0x000000ff);
}
static void netcp_xgbe_serdes_pll_disable(void __iomem *serdes_regs)
{
writel(0x88000000, serdes_regs + 0x1ff4);
}
static void netcp_xgbe_serdes_pll_enable(void __iomem *serdes_regs)
{
netcp_xgbe_serdes_phyb_rst_clr(serdes_regs);
writel(0xee000000, serdes_regs + 0x1ff4);
}
static int netcp_xgbe_wait_pll_locked(void __iomem *sw_regs)
{
unsigned long timeout;
int ret = 0;
u32 val_1, val_0;
timeout = jiffies + msecs_to_jiffies(500);
do {
val_0 = (readl(sw_regs + XGBE_SGMII_1_OFFSET) & BIT(4));
val_1 = (readl(sw_regs + XGBE_SGMII_2_OFFSET) & BIT(4));
if (val_1 && val_0)
return 0;
if (time_after(jiffies, timeout)) {
ret = -ETIMEDOUT;
break;
}
cpu_relax();
} while (true);
pr_err("XGBE serdes not locked: time out.\n");
return ret;
}
static void netcp_xgbe_serdes_enable_xgmii_port(void __iomem *sw_regs)
{
writel(0x03, sw_regs + XGBE_CTRL_OFFSET);
}
static u32 netcp_xgbe_serdes_read_tbus_val(void __iomem *serdes_regs)
{
u32 tmp;
if (PHY_A(serdes_regs)) {
tmp = (readl(serdes_regs + 0x0ec) >> 24) & 0x0ff;
tmp |= ((readl(serdes_regs + 0x0fc) >> 16) & 0x00f00);
} else {
tmp = (readl(serdes_regs + 0x0f8) >> 16) & 0x0fff;
}
return tmp;
}
static void netcp_xgbe_serdes_write_tbus_addr(void __iomem *serdes_regs,
int select, int ofs)
{
if (PHY_A(serdes_regs)) {
reg_rmw(serdes_regs + 0x0008, ((select << 5) + ofs) << 24,
~0x00ffffff);
return;
}
switch (select) {
case 1:
select = 2;
break;
case 2:
select = 3;
break;
default:
return;
}
reg_rmw(serdes_regs + 0x00fc, ((select << 8) + ofs) << 16, ~0xf800ffff);
}
static u32 netcp_xgbe_serdes_read_select_tbus(void __iomem *serdes_regs,
int select, int ofs)
{
netcp_xgbe_serdes_write_tbus_addr(serdes_regs, select, ofs);
return netcp_xgbe_serdes_read_tbus_val(serdes_regs);
}
static void netcp_xgbe_serdes_reset_cdr(void __iomem *serdes_regs,
void __iomem *sig_detect_reg, int lane)
{
u32 tmp, dlpf, tbus;
tmp = netcp_xgbe_serdes_read_select_tbus(
serdes_regs, lane + 1, 5);
dlpf = tmp >> 2;
if (dlpf < 400 || dlpf > 700) {
reg_rmw(sig_detect_reg, VAL_SH(2, 1), MASK_WID_SH(2, 1));
mdelay(1);
reg_rmw(sig_detect_reg, VAL_SH(0, 1), MASK_WID_SH(2, 1));
} else {
tbus = netcp_xgbe_serdes_read_select_tbus(serdes_regs, lane +
1, 0xe);
pr_debug("XGBE: CDR centered, DLPF: %4d,%d,%d.\n",
tmp >> 2, tmp & 3, (tbus >> 2) & 3);
}
}
static int netcp_xgbe_check_link_status(void __iomem *serdes_regs,
void __iomem *sw_regs, u32 lanes,
u32 *current_state, u32 *lane_down)
{
void __iomem *pcsr_base = sw_regs + 0x0600;
void __iomem *sig_detect_reg;
u32 pcsr_rx_stat, blk_lock, blk_errs;
int loss, i, status = 1;
for (i = 0; i < lanes; i++) {
loss = readl(serdes_regs + 0x1fc0 + 0x20 + (i * 0x04)) & 0x1;
pcsr_rx_stat = readl(pcsr_base + 0x0c + (i * 0x80));
blk_lock = (pcsr_rx_stat >> 30) & 0x1;
blk_errs = (pcsr_rx_stat >> 16) & 0x0ff;
sig_detect_reg = serdes_regs + (i * 0x200) + 0x200 + 0x04;
if (blk_errs == 0x0ff)
blk_lock = 0;
switch (current_state[i]) {
case 0:
if (!loss && blk_lock) {
pr_debug("XGBE PCSR Linked Lane: %d\n", i);
reg_rmw(sig_detect_reg, VAL_SH(3, 1),
MASK_WID_SH(2, 1));
current_state[i] = 1;
} else if (!blk_lock) {
pr_debug("XGBE PCSR Recover Lane: %d\n", i);
netcp_xgbe_serdes_reset_cdr(serdes_regs,
sig_detect_reg, i);
}
break;
case 1:
if (!blk_lock) {
lane_down[i] = 1;
current_state[i] = 2;
}
break;
case 2:
if (blk_lock)
current_state[i] = 1;
else {
netcp_xgbe_serdes_reset_cdr(serdes_regs,
sig_detect_reg, i);
current_state[i] = 0;
}
break;
default:
pr_err("XGBE: unknown current_state[%d] %d\n",
i, current_state[i]);
break;
}
if (blk_errs > 0) {
reg_rmw(pcsr_base + 0x08 + (i * 0x80), VAL_SH(0x19, 0),
MASK_WID_SH(8, 0));
reg_rmw(pcsr_base + 0x08 + (i * 0x80), VAL_SH(0x00, 0),
MASK_WID_SH(8, 0));
}
status &= (current_state[i] == 1);
}
return status;
}
static int netcp_xgbe_serdes_check_lane(void __iomem *serdes_regs,
void __iomem *sw_regs)
{
u32 current_state[2] = {0, 0};
int retries = 0, link_up;
u32 lane_down[2];
do {
lane_down[0] = 0;
lane_down[1] = 0;
link_up = netcp_xgbe_check_link_status(serdes_regs, sw_regs, 2,
current_state,
lane_down);
if (link_up)
break;
if (lane_down[0])
pr_debug("XGBE: detected link down on lane 0\n");
if (lane_down[1])
pr_debug("XGBE: detected link down on lane 1\n");
if (++retries > 1) {
pr_debug("XGBE: timeout waiting for serdes link up\n");
return -ETIMEDOUT;
}
mdelay(100);
} while (!link_up);
pr_debug("XGBE: PCSR link is up\n");
return 0;
}
static void netcp_xgbe_serdes_setup_cm_c1_c2(void __iomem *serdes_regs,
int lane, int cm, int c1, int c2)
{
int i;
for (i = 0; i < ARRAY_SIZE(cfg_cm_c1_c2); i++) {
reg_rmw(serdes_regs + cfg_cm_c1_c2[i].ofs + (0x200 * lane),
cfg_cm_c1_c2[i].val,
cfg_cm_c1_c2[i].mask);
}
}
static void netcp_xgbe_reset_serdes(void __iomem *serdes_regs)
{
reg_rmw(serdes_regs + PCSR_CPU_CTRL_OFFSET, POR_EN, POR_EN);
usleep_range(10, 100);
reg_rmw(serdes_regs + PCSR_CPU_CTRL_OFFSET, 0, POR_EN);
usleep_range(10, 100);
}
static int netcp_xgbe_serdes_config(void __iomem *serdes_regs,
void __iomem *sw_regs)
{
u32 ret, i;
netcp_xgbe_serdes_pll_disable(serdes_regs);
netcp_xgbe_serdes_cmu_init(serdes_regs);
for (i = 0; i < 2; i++)
netcp_xgbe_serdes_lane_config(serdes_regs, i);
netcp_xgbe_serdes_com_enable(serdes_regs);
for (i = 0; i < 2; i++)
netcp_xgbe_serdes_setup_cm_c1_c2(serdes_regs, i, 0, 0, 5);
netcp_xgbe_serdes_pll_enable(serdes_regs);
for (i = 0; i < 2; i++)
netcp_xgbe_serdes_lane_enable(serdes_regs, i);
ret = netcp_xgbe_wait_pll_locked(sw_regs);
if (ret)
return ret;
netcp_xgbe_serdes_enable_xgmii_port(sw_regs);
netcp_xgbe_serdes_check_lane(serdes_regs, sw_regs);
return ret;
}
int netcp_xgbe_serdes_init(void __iomem *serdes_regs, void __iomem *xgbe_regs)
{
u32 val;
val = readl(serdes_regs + 0xa00);
if (val & 0x1f) {
pr_debug("XGBE: serdes already in operation - reset\n");
netcp_xgbe_reset_serdes(serdes_regs);
}
return netcp_xgbe_serdes_config(serdes_regs, xgbe_regs);
}
