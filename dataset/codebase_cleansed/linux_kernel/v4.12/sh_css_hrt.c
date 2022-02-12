bool sh_css_hrt_system_is_idle(void)
{
bool not_idle = false, idle;
fifo_channel_t ch;
idle = sp_ctrl_getbit(SP0_ID, SP_SC_REG, SP_IDLE_BIT);
not_idle |= !idle;
if (!idle)
IA_CSS_WARNING("SP not idle");
idle = isp_ctrl_getbit(ISP0_ID, ISP_SC_REG, ISP_IDLE_BIT);
not_idle |= !idle;
if (!idle)
IA_CSS_WARNING("ISP not idle");
for (ch=0; ch<N_FIFO_CHANNEL; ch++) {
fifo_channel_state_t state;
fifo_channel_get_state(FIFO_MONITOR0_ID, ch, &state);
if (state.fifo_valid) {
IA_CSS_WARNING("FIFO channel %d is not empty", ch);
not_idle = true;
}
}
return !not_idle;
}
enum ia_css_err sh_css_hrt_sp_wait(void)
{
#if defined(HAS_IRQ_MAP_VERSION_2)
irq_sw_channel_id_t irq_id = IRQ_SW_CHANNEL0_ID;
#else
irq_sw_channel_id_t irq_id = IRQ_SW_CHANNEL2_ID;
#endif
while (!sp_ctrl_getbit(SP0_ID, SP_SC_REG, SP_IDLE_BIT) &&
((irq_reg_load(IRQ0_ID,
_HRT_IRQ_CONTROLLER_STATUS_REG_IDX) &
(1U<<(irq_id + IRQ_SW_CHANNEL_OFFSET))) == 0)) {
hrt_sleep();
}
return IA_CSS_SUCCESS;
}
