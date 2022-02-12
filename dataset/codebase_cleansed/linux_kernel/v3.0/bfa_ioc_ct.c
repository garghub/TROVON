void
bfa_nw_ioc_set_ct_hwif(struct bfa_ioc *ioc)
{
nw_hwif_ct.ioc_pll_init = bfa_ioc_ct_pll_init;
nw_hwif_ct.ioc_firmware_lock = bfa_ioc_ct_firmware_lock;
nw_hwif_ct.ioc_firmware_unlock = bfa_ioc_ct_firmware_unlock;
nw_hwif_ct.ioc_reg_init = bfa_ioc_ct_reg_init;
nw_hwif_ct.ioc_map_port = bfa_ioc_ct_map_port;
nw_hwif_ct.ioc_isr_mode_set = bfa_ioc_ct_isr_mode_set;
nw_hwif_ct.ioc_notify_fail = bfa_ioc_ct_notify_fail;
nw_hwif_ct.ioc_ownership_reset = bfa_ioc_ct_ownership_reset;
nw_hwif_ct.ioc_sync_start = bfa_ioc_ct_sync_start;
nw_hwif_ct.ioc_sync_join = bfa_ioc_ct_sync_join;
nw_hwif_ct.ioc_sync_leave = bfa_ioc_ct_sync_leave;
nw_hwif_ct.ioc_sync_ack = bfa_ioc_ct_sync_ack;
nw_hwif_ct.ioc_sync_complete = bfa_ioc_ct_sync_complete;
ioc->ioc_hwif = &nw_hwif_ct;
}
static bool
bfa_ioc_ct_firmware_lock(struct bfa_ioc *ioc)
{
enum bfi_ioc_state ioc_fwstate;
u32 usecnt;
struct bfi_ioc_image_hdr fwhdr;
if (!ioc->cna)
return true;
if (bfa_cb_image_get_size(BFA_IOC_FWIMG_TYPE(ioc)) <
BFA_IOC_FWIMG_MINSZ)
return true;
bfa_nw_ioc_sem_get(ioc->ioc_regs.ioc_usage_sem_reg);
usecnt = readl(ioc->ioc_regs.ioc_usage_reg);
if (usecnt == 0) {
writel(1, ioc->ioc_regs.ioc_usage_reg);
bfa_nw_ioc_sem_release(ioc->ioc_regs.ioc_usage_sem_reg);
writel(0, ioc->ioc_regs.ioc_fail_sync);
return true;
}
ioc_fwstate = readl(ioc->ioc_regs.ioc_fwstate);
BUG_ON(!(ioc_fwstate != BFI_IOC_UNINIT));
bfa_nw_ioc_fwver_get(ioc, &fwhdr);
if (!bfa_nw_ioc_fwver_cmp(ioc, &fwhdr)) {
bfa_nw_ioc_sem_release(ioc->ioc_regs.ioc_usage_sem_reg);
return false;
}
usecnt++;
writel(usecnt, ioc->ioc_regs.ioc_usage_reg);
bfa_nw_ioc_sem_release(ioc->ioc_regs.ioc_usage_sem_reg);
return true;
}
static void
bfa_ioc_ct_firmware_unlock(struct bfa_ioc *ioc)
{
u32 usecnt;
if (!ioc->cna)
return;
if (bfa_cb_image_get_size(BFA_IOC_FWIMG_TYPE(ioc)) <
BFA_IOC_FWIMG_MINSZ)
return;
bfa_nw_ioc_sem_get(ioc->ioc_regs.ioc_usage_sem_reg);
usecnt = readl(ioc->ioc_regs.ioc_usage_reg);
BUG_ON(!(usecnt > 0));
usecnt--;
writel(usecnt, ioc->ioc_regs.ioc_usage_reg);
bfa_nw_ioc_sem_release(ioc->ioc_regs.ioc_usage_sem_reg);
}
static void
bfa_ioc_ct_notify_fail(struct bfa_ioc *ioc)
{
if (ioc->cna) {
writel(__FW_INIT_HALT_P, ioc->ioc_regs.ll_halt);
writel(__FW_INIT_HALT_P, ioc->ioc_regs.alt_ll_halt);
readl(ioc->ioc_regs.ll_halt);
readl(ioc->ioc_regs.alt_ll_halt);
} else {
writel(__PSS_ERR_STATUS_SET, ioc->ioc_regs.err_set);
readl(ioc->ioc_regs.err_set);
}
}
static void
bfa_ioc_ct_reg_init(struct bfa_ioc *ioc)
{
void __iomem *rb;
int pcifn = bfa_ioc_pcifn(ioc);
rb = bfa_ioc_bar0(ioc);
ioc->ioc_regs.hfn_mbox = rb + iocreg_fnreg[pcifn].hfn_mbox;
ioc->ioc_regs.lpu_mbox = rb + iocreg_fnreg[pcifn].lpu_mbox;
ioc->ioc_regs.host_page_num_fn = rb + iocreg_fnreg[pcifn].hfn_pgn;
if (ioc->port_id == 0) {
ioc->ioc_regs.heartbeat = rb + BFA_IOC0_HBEAT_REG;
ioc->ioc_regs.ioc_fwstate = rb + BFA_IOC0_STATE_REG;
ioc->ioc_regs.alt_ioc_fwstate = rb + BFA_IOC1_STATE_REG;
ioc->ioc_regs.hfn_mbox_cmd = rb + iocreg_mbcmd_p0[pcifn].hfn;
ioc->ioc_regs.lpu_mbox_cmd = rb + iocreg_mbcmd_p0[pcifn].lpu;
ioc->ioc_regs.ll_halt = rb + FW_INIT_HALT_P0;
ioc->ioc_regs.alt_ll_halt = rb + FW_INIT_HALT_P1;
} else {
ioc->ioc_regs.heartbeat = (rb + BFA_IOC1_HBEAT_REG);
ioc->ioc_regs.ioc_fwstate = (rb + BFA_IOC1_STATE_REG);
ioc->ioc_regs.alt_ioc_fwstate = rb + BFA_IOC0_STATE_REG;
ioc->ioc_regs.hfn_mbox_cmd = rb + iocreg_mbcmd_p1[pcifn].hfn;
ioc->ioc_regs.lpu_mbox_cmd = rb + iocreg_mbcmd_p1[pcifn].lpu;
ioc->ioc_regs.ll_halt = rb + FW_INIT_HALT_P1;
ioc->ioc_regs.alt_ll_halt = rb + FW_INIT_HALT_P0;
}
ioc->ioc_regs.pss_ctl_reg = (rb + PSS_CTL_REG);
ioc->ioc_regs.pss_err_status_reg = (rb + PSS_ERR_STATUS_REG);
ioc->ioc_regs.app_pll_fast_ctl_reg = (rb + APP_PLL_425_CTL_REG);
ioc->ioc_regs.app_pll_slow_ctl_reg = (rb + APP_PLL_312_CTL_REG);
ioc->ioc_regs.ioc_sem_reg = (rb + HOST_SEM0_REG);
ioc->ioc_regs.ioc_usage_sem_reg = (rb + HOST_SEM1_REG);
ioc->ioc_regs.ioc_init_sem_reg = (rb + HOST_SEM2_REG);
ioc->ioc_regs.ioc_usage_reg = (rb + BFA_FW_USE_COUNT);
ioc->ioc_regs.ioc_fail_sync = (rb + BFA_IOC_FAIL_SYNC);
ioc->ioc_regs.smem_page_start = (rb + PSS_SMEM_PAGE_START);
ioc->ioc_regs.smem_pg0 = BFI_IOC_SMEM_PG0_CT;
ioc->ioc_regs.err_set = (rb + ERR_SET_REG);
}
static void
bfa_ioc_ct_map_port(struct bfa_ioc *ioc)
{
void __iomem *rb = ioc->pcidev.pci_bar_kva;
u32 r32;
r32 = readl(rb + FNC_PERS_REG);
r32 >>= FNC_PERS_FN_SHIFT(bfa_ioc_pcifn(ioc));
ioc->port_id = (r32 & __F0_PORT_MAP_MK) >> __F0_PORT_MAP_SH;
}
static void
bfa_ioc_ct_isr_mode_set(struct bfa_ioc *ioc, bool msix)
{
void __iomem *rb = ioc->pcidev.pci_bar_kva;
u32 r32, mode;
r32 = readl(rb + FNC_PERS_REG);
mode = (r32 >> FNC_PERS_FN_SHIFT(bfa_ioc_pcifn(ioc))) &
__F0_INTX_STATUS;
if (!msix && mode)
return;
if (msix)
mode = __F0_INTX_STATUS_MSIX;
else
mode = __F0_INTX_STATUS_INTA;
r32 &= ~(__F0_INTX_STATUS << FNC_PERS_FN_SHIFT(bfa_ioc_pcifn(ioc)));
r32 |= (mode << FNC_PERS_FN_SHIFT(bfa_ioc_pcifn(ioc)));
writel(r32, rb + FNC_PERS_REG);
}
static void
bfa_ioc_ct_ownership_reset(struct bfa_ioc *ioc)
{
if (ioc->cna) {
bfa_nw_ioc_sem_get(ioc->ioc_regs.ioc_usage_sem_reg);
writel(0, ioc->ioc_regs.ioc_usage_reg);
bfa_nw_ioc_sem_release(ioc->ioc_regs.ioc_usage_sem_reg);
}
readl(ioc->ioc_regs.ioc_sem_reg);
bfa_nw_ioc_hw_sem_release(ioc);
}
static bool
bfa_ioc_ct_sync_start(struct bfa_ioc *ioc)
{
u32 r32 = readl(ioc->ioc_regs.ioc_fail_sync);
u32 sync_reqd = bfa_ioc_ct_get_sync_reqd(r32);
if (sync_reqd & bfa_ioc_ct_sync_pos(ioc)) {
writel(0, ioc->ioc_regs.ioc_fail_sync);
writel(1, ioc->ioc_regs.ioc_usage_reg);
writel(BFI_IOC_UNINIT, ioc->ioc_regs.ioc_fwstate);
writel(BFI_IOC_UNINIT, ioc->ioc_regs.alt_ioc_fwstate);
return true;
}
return bfa_ioc_ct_sync_complete(ioc);
}
static void
bfa_ioc_ct_sync_join(struct bfa_ioc *ioc)
{
u32 r32 = readl(ioc->ioc_regs.ioc_fail_sync);
u32 sync_pos = bfa_ioc_ct_sync_reqd_pos(ioc);
writel((r32 | sync_pos), ioc->ioc_regs.ioc_fail_sync);
}
static void
bfa_ioc_ct_sync_leave(struct bfa_ioc *ioc)
{
u32 r32 = readl(ioc->ioc_regs.ioc_fail_sync);
u32 sync_msk = bfa_ioc_ct_sync_reqd_pos(ioc) |
bfa_ioc_ct_sync_pos(ioc);
writel((r32 & ~sync_msk), ioc->ioc_regs.ioc_fail_sync);
}
static void
bfa_ioc_ct_sync_ack(struct bfa_ioc *ioc)
{
u32 r32 = readl(ioc->ioc_regs.ioc_fail_sync);
writel((r32 | bfa_ioc_ct_sync_pos(ioc)), ioc->ioc_regs.ioc_fail_sync);
}
static bool
bfa_ioc_ct_sync_complete(struct bfa_ioc *ioc)
{
u32 r32 = readl(ioc->ioc_regs.ioc_fail_sync);
u32 sync_reqd = bfa_ioc_ct_get_sync_reqd(r32);
u32 sync_ackd = bfa_ioc_ct_get_sync_ackd(r32);
u32 tmp_ackd;
if (sync_ackd == 0)
return true;
tmp_ackd = sync_ackd;
if ((sync_reqd & bfa_ioc_ct_sync_pos(ioc)) &&
!(sync_ackd & bfa_ioc_ct_sync_pos(ioc)))
sync_ackd |= bfa_ioc_ct_sync_pos(ioc);
if (sync_reqd == sync_ackd) {
writel(bfa_ioc_ct_clear_sync_ackd(r32),
ioc->ioc_regs.ioc_fail_sync);
writel(BFI_IOC_FAIL, ioc->ioc_regs.ioc_fwstate);
writel(BFI_IOC_FAIL, ioc->ioc_regs.alt_ioc_fwstate);
return true;
}
if (tmp_ackd != sync_ackd)
writel((r32 | sync_ackd), ioc->ioc_regs.ioc_fail_sync);
return false;
}
static enum bfa_status
bfa_ioc_ct_pll_init(void __iomem *rb, bool fcmode)
{
u32 pll_sclk, pll_fclk, r32;
pll_sclk = __APP_PLL_312_LRESETN | __APP_PLL_312_ENARST |
__APP_PLL_312_RSEL200500 | __APP_PLL_312_P0_1(3U) |
__APP_PLL_312_JITLMT0_1(3U) |
__APP_PLL_312_CNTLMT0_1(1U);
pll_fclk = __APP_PLL_425_LRESETN | __APP_PLL_425_ENARST |
__APP_PLL_425_RSEL200500 | __APP_PLL_425_P0_1(3U) |
__APP_PLL_425_JITLMT0_1(3U) |
__APP_PLL_425_CNTLMT0_1(1U);
if (fcmode) {
writel(0, (rb + OP_MODE));
writel(__APP_EMS_CMLCKSEL |
__APP_EMS_REFCKBUFEN2 |
__APP_EMS_CHANNEL_SEL,
(rb + ETH_MAC_SER_REG));
} else {
writel(__GLOBAL_FCOE_MODE, (rb + OP_MODE));
writel(__APP_EMS_REFCKBUFEN1,
(rb + ETH_MAC_SER_REG));
}
writel(BFI_IOC_UNINIT, (rb + BFA_IOC0_STATE_REG));
writel(BFI_IOC_UNINIT, (rb + BFA_IOC1_STATE_REG));
writel(0xffffffffU, (rb + HOSTFN0_INT_MSK));
writel(0xffffffffU, (rb + HOSTFN1_INT_MSK));
writel(0xffffffffU, (rb + HOSTFN0_INT_STATUS));
writel(0xffffffffU, (rb + HOSTFN1_INT_STATUS));
writel(0xffffffffU, (rb + HOSTFN0_INT_MSK));
writel(0xffffffffU, (rb + HOSTFN1_INT_MSK));
writel(pll_sclk |
__APP_PLL_312_LOGIC_SOFT_RESET,
rb + APP_PLL_312_CTL_REG);
writel(pll_fclk |
__APP_PLL_425_LOGIC_SOFT_RESET,
rb + APP_PLL_425_CTL_REG);
writel(pll_sclk |
__APP_PLL_312_LOGIC_SOFT_RESET | __APP_PLL_312_ENABLE,
rb + APP_PLL_312_CTL_REG);
writel(pll_fclk |
__APP_PLL_425_LOGIC_SOFT_RESET | __APP_PLL_425_ENABLE,
rb + APP_PLL_425_CTL_REG);
readl(rb + HOSTFN0_INT_MSK);
udelay(2000);
writel(0xffffffffU, (rb + HOSTFN0_INT_STATUS));
writel(0xffffffffU, (rb + HOSTFN1_INT_STATUS));
writel(pll_sclk |
__APP_PLL_312_ENABLE,
rb + APP_PLL_312_CTL_REG);
writel(pll_fclk |
__APP_PLL_425_ENABLE,
rb + APP_PLL_425_CTL_REG);
if (!fcmode) {
writel(__PMM_1T_RESET_P, (rb + PMM_1T_RESET_REG_P0));
writel(__PMM_1T_RESET_P, (rb + PMM_1T_RESET_REG_P1));
}
r32 = readl((rb + PSS_CTL_REG));
r32 &= ~__PSS_LMEM_RESET;
writel(r32, (rb + PSS_CTL_REG));
udelay(1000);
if (!fcmode) {
writel(0, (rb + PMM_1T_RESET_REG_P0));
writel(0, (rb + PMM_1T_RESET_REG_P1));
}
writel(__EDRAM_BISTR_START, (rb + MBIST_CTL_REG));
udelay(1000);
r32 = readl((rb + MBIST_STAT_REG));
writel(0, (rb + MBIST_CTL_REG));
return BFA_STATUS_OK;
}
