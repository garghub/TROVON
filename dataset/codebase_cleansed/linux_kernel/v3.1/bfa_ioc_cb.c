void
bfa_ioc_set_cb_hwif(struct bfa_ioc_s *ioc)
{
hwif_cb.ioc_pll_init = bfa_ioc_cb_pll_init;
hwif_cb.ioc_firmware_lock = bfa_ioc_cb_firmware_lock;
hwif_cb.ioc_firmware_unlock = bfa_ioc_cb_firmware_unlock;
hwif_cb.ioc_reg_init = bfa_ioc_cb_reg_init;
hwif_cb.ioc_map_port = bfa_ioc_cb_map_port;
hwif_cb.ioc_isr_mode_set = bfa_ioc_cb_isr_mode_set;
hwif_cb.ioc_notify_fail = bfa_ioc_cb_notify_fail;
hwif_cb.ioc_ownership_reset = bfa_ioc_cb_ownership_reset;
hwif_cb.ioc_sync_start = bfa_ioc_cb_sync_start;
hwif_cb.ioc_sync_join = bfa_ioc_cb_sync_join;
hwif_cb.ioc_sync_leave = bfa_ioc_cb_sync_leave;
hwif_cb.ioc_sync_ack = bfa_ioc_cb_sync_ack;
hwif_cb.ioc_sync_complete = bfa_ioc_cb_sync_complete;
ioc->ioc_hwif = &hwif_cb;
}
static bfa_boolean_t
bfa_ioc_cb_firmware_lock(struct bfa_ioc_s *ioc)
{
return BFA_TRUE;
}
static void
bfa_ioc_cb_firmware_unlock(struct bfa_ioc_s *ioc)
{
}
static void
bfa_ioc_cb_notify_fail(struct bfa_ioc_s *ioc)
{
writel(~0U, ioc->ioc_regs.err_set);
readl(ioc->ioc_regs.err_set);
}
static void
bfa_ioc_cb_reg_init(struct bfa_ioc_s *ioc)
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
} else {
ioc->ioc_regs.heartbeat = (rb + BFA_IOC1_HBEAT_REG);
ioc->ioc_regs.ioc_fwstate = (rb + BFA_IOC1_STATE_REG);
ioc->ioc_regs.alt_ioc_fwstate = (rb + BFA_IOC0_STATE_REG);
}
ioc->ioc_regs.hfn_mbox_cmd = rb + iocreg_mbcmd[pcifn].hfn;
ioc->ioc_regs.lpu_mbox_cmd = rb + iocreg_mbcmd[pcifn].lpu;
ioc->ioc_regs.pss_ctl_reg = (rb + PSS_CTL_REG);
ioc->ioc_regs.pss_err_status_reg = (rb + PSS_ERR_STATUS_REG);
ioc->ioc_regs.app_pll_fast_ctl_reg = (rb + APP_PLL_LCLK_CTL_REG);
ioc->ioc_regs.app_pll_slow_ctl_reg = (rb + APP_PLL_SCLK_CTL_REG);
ioc->ioc_regs.ioc_sem_reg = (rb + HOST_SEM0_REG);
ioc->ioc_regs.ioc_init_sem_reg = (rb + HOST_SEM2_REG);
ioc->ioc_regs.smem_page_start = (rb + PSS_SMEM_PAGE_START);
ioc->ioc_regs.smem_pg0 = BFI_IOC_SMEM_PG0_CB;
ioc->ioc_regs.err_set = (rb + ERR_SET_REG);
}
static void
bfa_ioc_cb_map_port(struct bfa_ioc_s *ioc)
{
ioc->port_id = bfa_ioc_pcifn(ioc);
bfa_trc(ioc, ioc->port_id);
}
static void
bfa_ioc_cb_isr_mode_set(struct bfa_ioc_s *ioc, bfa_boolean_t msix)
{
}
static bfa_boolean_t
bfa_ioc_cb_sync_start(struct bfa_ioc_s *ioc)
{
return bfa_ioc_cb_sync_complete(ioc);
}
static void
bfa_ioc_cb_ownership_reset(struct bfa_ioc_s *ioc)
{
readl(ioc->ioc_regs.ioc_sem_reg);
writel(1, ioc->ioc_regs.ioc_sem_reg);
}
static void
bfa_ioc_cb_sync_join(struct bfa_ioc_s *ioc)
{
}
static void
bfa_ioc_cb_sync_leave(struct bfa_ioc_s *ioc)
{
}
static void
bfa_ioc_cb_sync_ack(struct bfa_ioc_s *ioc)
{
writel(BFI_IOC_FAIL, ioc->ioc_regs.ioc_fwstate);
}
static bfa_boolean_t
bfa_ioc_cb_sync_complete(struct bfa_ioc_s *ioc)
{
uint32_t fwstate, alt_fwstate;
fwstate = readl(ioc->ioc_regs.ioc_fwstate);
if (fwstate == BFI_IOC_UNINIT ||
fwstate == BFI_IOC_INITING ||
fwstate == BFI_IOC_DISABLED ||
fwstate == BFI_IOC_MEMTEST ||
fwstate == BFI_IOC_OP)
return BFA_TRUE;
else {
alt_fwstate = readl(ioc->ioc_regs.alt_ioc_fwstate);
if (alt_fwstate == BFI_IOC_FAIL ||
alt_fwstate == BFI_IOC_DISABLED ||
alt_fwstate == BFI_IOC_UNINIT ||
alt_fwstate == BFI_IOC_INITING ||
alt_fwstate == BFI_IOC_MEMTEST)
return BFA_TRUE;
else
return BFA_FALSE;
}
}
bfa_status_t
bfa_ioc_cb_pll_init(void __iomem *rb, enum bfi_asic_mode fcmode)
{
u32 pll_sclk, pll_fclk;
pll_sclk = __APP_PLL_SCLK_ENABLE | __APP_PLL_SCLK_LRESETN |
__APP_PLL_SCLK_P0_1(3U) |
__APP_PLL_SCLK_JITLMT0_1(3U) |
__APP_PLL_SCLK_CNTLMT0_1(3U);
pll_fclk = __APP_PLL_LCLK_ENABLE | __APP_PLL_LCLK_LRESETN |
__APP_PLL_LCLK_RSEL200500 | __APP_PLL_LCLK_P0_1(3U) |
__APP_PLL_LCLK_JITLMT0_1(3U) |
__APP_PLL_LCLK_CNTLMT0_1(3U);
writel(BFI_IOC_UNINIT, (rb + BFA_IOC0_STATE_REG));
writel(BFI_IOC_UNINIT, (rb + BFA_IOC1_STATE_REG));
writel(0xffffffffU, (rb + HOSTFN0_INT_MSK));
writel(0xffffffffU, (rb + HOSTFN1_INT_MSK));
writel(0xffffffffU, (rb + HOSTFN0_INT_STATUS));
writel(0xffffffffU, (rb + HOSTFN1_INT_STATUS));
writel(0xffffffffU, (rb + HOSTFN0_INT_MSK));
writel(0xffffffffU, (rb + HOSTFN1_INT_MSK));
writel(__APP_PLL_SCLK_LOGIC_SOFT_RESET, rb + APP_PLL_SCLK_CTL_REG);
writel(__APP_PLL_SCLK_BYPASS | __APP_PLL_SCLK_LOGIC_SOFT_RESET,
rb + APP_PLL_SCLK_CTL_REG);
writel(__APP_PLL_LCLK_LOGIC_SOFT_RESET, rb + APP_PLL_LCLK_CTL_REG);
writel(__APP_PLL_LCLK_BYPASS | __APP_PLL_LCLK_LOGIC_SOFT_RESET,
rb + APP_PLL_LCLK_CTL_REG);
udelay(2);
writel(__APP_PLL_SCLK_LOGIC_SOFT_RESET, rb + APP_PLL_SCLK_CTL_REG);
writel(__APP_PLL_LCLK_LOGIC_SOFT_RESET, rb + APP_PLL_LCLK_CTL_REG);
writel(pll_sclk | __APP_PLL_SCLK_LOGIC_SOFT_RESET,
rb + APP_PLL_SCLK_CTL_REG);
writel(pll_fclk | __APP_PLL_LCLK_LOGIC_SOFT_RESET,
rb + APP_PLL_LCLK_CTL_REG);
udelay(2000);
writel(0xffffffffU, (rb + HOSTFN0_INT_STATUS));
writel(0xffffffffU, (rb + HOSTFN1_INT_STATUS));
writel(pll_sclk, (rb + APP_PLL_SCLK_CTL_REG));
writel(pll_fclk, (rb + APP_PLL_LCLK_CTL_REG));
return BFA_STATUS_OK;
}
