uint32_t
gp_timer_reg_load(uint32_t reg)
{
return ia_css_device_load_uint32(
GP_TIMER_BASE +
(reg * sizeof(uint32_t)));
}
static void
gp_timer_reg_store(uint32_t reg, uint32_t value)
{
ia_css_device_store_uint32((GP_TIMER_BASE +
(reg * sizeof(uint32_t))),
value);
}
void gp_timer_init(gp_timer_ID_t ID)
{
gp_timer_reg_store(_REG_GP_TIMER_OVERALL_ENABLE, 1);
gp_timer_reg_store(_REG_GP_TIMER_ENABLE_ID(ID), 1);
gp_timer_reg_store(_REG_GP_TIMER_SIGNAL_SELECT_ID(ID), GP_TIMER_SIGNAL_SELECT);
gp_timer_reg_store(_REG_GP_TIMER_COUNT_TYPE_ID(ID), GP_TIMER_COUNT_TYPE_LOW);
gp_timer_reg_store(_REG_GP_TIMER_RESET_REG, 0xFF);
}
uint32_t
gp_timer_read(gp_timer_ID_t ID)
{
return gp_timer_reg_load(_REG_GP_TIMER_VALUE_ID(ID));
}
