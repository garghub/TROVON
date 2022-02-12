static u32 omap2xxx_sdrc_get_slow_dll_ctrl(void)
{
return mem_timings.slow_dll_ctrl;
}
static u32 omap2xxx_sdrc_get_fast_dll_ctrl(void)
{
return mem_timings.fast_dll_ctrl;
}
static u32 omap2xxx_sdrc_get_type(void)
{
return mem_timings.m_type;
}
u32 omap2xxx_sdrc_dll_is_unlocked(void)
{
u32 dll_state = sdrc_read_reg(SDRC_DLLA_CTRL);
if ((dll_state & (1 << 2)) == (1 << 2))
return 1;
else
return 0;
}
u32 omap2xxx_sdrc_reprogram(u32 level, u32 force)
{
u32 dll_ctrl, m_type;
u32 prev = curr_perf_level;
unsigned long flags;
if ((curr_perf_level == level) && !force)
return prev;
if (level == CORE_CLK_SRC_DPLL)
dll_ctrl = omap2xxx_sdrc_get_slow_dll_ctrl();
else if (level == CORE_CLK_SRC_DPLL_X2)
dll_ctrl = omap2xxx_sdrc_get_fast_dll_ctrl();
else
return prev;
m_type = omap2xxx_sdrc_get_type();
local_irq_save(flags);
if (cpu_is_omap2420())
__raw_writel(0xffff, OMAP2420_PRCM_VOLTSETUP);
else
__raw_writel(0xffff, OMAP2430_PRCM_VOLTSETUP);
omap2_sram_reprogram_sdrc(level, dll_ctrl, m_type);
curr_perf_level = level;
local_irq_restore(flags);
return prev;
}
void omap2xxx_sdrc_init_params(u32 force_lock_to_unlock_mode)
{
unsigned long dll_cnt;
u32 fast_dll = 0;
mem_timings.m_type = !((sdrc_read_reg(SDRC_MR_0) & 0x3) == 0x1);
if (cpu_is_omap2422())
mem_timings.base_cs = 1;
else
mem_timings.base_cs = 0;
if (mem_timings.m_type != M_DDR)
return;
if (((mem_timings.fast_dll_ctrl & (1 << 2)) == M_LOCK_CTRL))
mem_timings.dll_mode = M_UNLOCK;
else
mem_timings.dll_mode = M_LOCK;
if (mem_timings.base_cs == 0) {
fast_dll = sdrc_read_reg(SDRC_DLLA_CTRL);
dll_cnt = sdrc_read_reg(SDRC_DLLA_STATUS) & 0xff00;
} else {
fast_dll = sdrc_read_reg(SDRC_DLLB_CTRL);
dll_cnt = sdrc_read_reg(SDRC_DLLB_STATUS) & 0xff00;
}
if (force_lock_to_unlock_mode) {
fast_dll &= ~0xff00;
fast_dll |= dll_cnt;
}
mem_timings.fast_dll_ctrl = (fast_dll | (3 << 8));
omap2_sram_ddr_init(&mem_timings.slow_dll_ctrl,
mem_timings.fast_dll_ctrl,
mem_timings.base_cs,
force_lock_to_unlock_mode);
mem_timings.slow_dll_ctrl &= 0xff00;
mem_timings.slow_dll_ctrl |=
((mem_timings.fast_dll_ctrl & 0xF) | (1 << 2));
mem_timings.slow_dll_ctrl |= ((1 << 1) | (3 << 8));
}
