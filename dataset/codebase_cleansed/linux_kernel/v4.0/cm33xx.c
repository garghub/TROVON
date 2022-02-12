static inline u32 am33xx_cm_read_reg(u16 inst, u16 idx)
{
return readl_relaxed(cm_base + inst + idx);
}
static inline void am33xx_cm_write_reg(u32 val, u16 inst, u16 idx)
{
writel_relaxed(val, cm_base + inst + idx);
}
static inline u32 am33xx_cm_rmw_reg_bits(u32 mask, u32 bits, s16 inst, s16 idx)
{
u32 v;
v = am33xx_cm_read_reg(inst, idx);
v &= ~mask;
v |= bits;
am33xx_cm_write_reg(v, inst, idx);
return v;
}
static u32 _clkctrl_idlest(u16 inst, u16 clkctrl_offs)
{
u32 v = am33xx_cm_read_reg(inst, clkctrl_offs);
v &= AM33XX_IDLEST_MASK;
v >>= AM33XX_IDLEST_SHIFT;
return v;
}
static bool _is_module_ready(u16 inst, u16 clkctrl_offs)
{
u32 v;
v = _clkctrl_idlest(inst, clkctrl_offs);
return (v == CLKCTRL_IDLEST_FUNCTIONAL ||
v == CLKCTRL_IDLEST_INTERFACE_IDLE) ? true : false;
}
static void _clktrctrl_write(u8 c, u16 inst, u16 cdoffs)
{
u32 v;
v = am33xx_cm_read_reg(inst, cdoffs);
v &= ~AM33XX_CLKTRCTRL_MASK;
v |= c << AM33XX_CLKTRCTRL_SHIFT;
am33xx_cm_write_reg(v, inst, cdoffs);
}
static bool am33xx_cm_is_clkdm_in_hwsup(u16 inst, u16 cdoffs)
{
u32 v;
v = am33xx_cm_read_reg(inst, cdoffs);
v &= AM33XX_CLKTRCTRL_MASK;
v >>= AM33XX_CLKTRCTRL_SHIFT;
return (v == OMAP34XX_CLKSTCTRL_ENABLE_AUTO) ? true : false;
}
static void am33xx_cm_clkdm_enable_hwsup(u16 inst, u16 cdoffs)
{
_clktrctrl_write(OMAP34XX_CLKSTCTRL_ENABLE_AUTO, inst, cdoffs);
}
static void am33xx_cm_clkdm_disable_hwsup(u16 inst, u16 cdoffs)
{
_clktrctrl_write(OMAP34XX_CLKSTCTRL_DISABLE_AUTO, inst, cdoffs);
}
static void am33xx_cm_clkdm_force_sleep(u16 inst, u16 cdoffs)
{
_clktrctrl_write(OMAP34XX_CLKSTCTRL_FORCE_SLEEP, inst, cdoffs);
}
static void am33xx_cm_clkdm_force_wakeup(u16 inst, u16 cdoffs)
{
_clktrctrl_write(OMAP34XX_CLKSTCTRL_FORCE_WAKEUP, inst, cdoffs);
}
static int am33xx_cm_wait_module_ready(u8 part, s16 inst, u16 clkctrl_offs,
u8 bit_shift)
{
int i = 0;
omap_test_timeout(_is_module_ready(inst, clkctrl_offs),
MAX_MODULE_READY_TIME, i);
return (i < MAX_MODULE_READY_TIME) ? 0 : -EBUSY;
}
static int am33xx_cm_wait_module_idle(u8 part, s16 inst, u16 clkctrl_offs,
u8 bit_shift)
{
int i = 0;
if (!clkctrl_offs)
return 0;
omap_test_timeout((_clkctrl_idlest(inst, clkctrl_offs) ==
CLKCTRL_IDLEST_DISABLED),
MAX_MODULE_READY_TIME, i);
return (i < MAX_MODULE_READY_TIME) ? 0 : -EBUSY;
}
static void am33xx_cm_module_enable(u8 mode, u8 part, u16 inst,
u16 clkctrl_offs)
{
u32 v;
v = am33xx_cm_read_reg(inst, clkctrl_offs);
v &= ~AM33XX_MODULEMODE_MASK;
v |= mode << AM33XX_MODULEMODE_SHIFT;
am33xx_cm_write_reg(v, inst, clkctrl_offs);
}
static void am33xx_cm_module_disable(u8 part, u16 inst, u16 clkctrl_offs)
{
u32 v;
v = am33xx_cm_read_reg(inst, clkctrl_offs);
v &= ~AM33XX_MODULEMODE_MASK;
am33xx_cm_write_reg(v, inst, clkctrl_offs);
}
static int am33xx_clkdm_sleep(struct clockdomain *clkdm)
{
am33xx_cm_clkdm_force_sleep(clkdm->cm_inst, clkdm->clkdm_offs);
return 0;
}
static int am33xx_clkdm_wakeup(struct clockdomain *clkdm)
{
am33xx_cm_clkdm_force_wakeup(clkdm->cm_inst, clkdm->clkdm_offs);
return 0;
}
static void am33xx_clkdm_allow_idle(struct clockdomain *clkdm)
{
am33xx_cm_clkdm_enable_hwsup(clkdm->cm_inst, clkdm->clkdm_offs);
}
static void am33xx_clkdm_deny_idle(struct clockdomain *clkdm)
{
am33xx_cm_clkdm_disable_hwsup(clkdm->cm_inst, clkdm->clkdm_offs);
}
static int am33xx_clkdm_clk_enable(struct clockdomain *clkdm)
{
if (clkdm->flags & CLKDM_CAN_FORCE_WAKEUP)
return am33xx_clkdm_wakeup(clkdm);
return 0;
}
static int am33xx_clkdm_clk_disable(struct clockdomain *clkdm)
{
bool hwsup = false;
hwsup = am33xx_cm_is_clkdm_in_hwsup(clkdm->cm_inst, clkdm->clkdm_offs);
if (!hwsup && (clkdm->flags & CLKDM_CAN_FORCE_SLEEP))
am33xx_clkdm_sleep(clkdm);
return 0;
}
int __init am33xx_cm_init(void)
{
return cm_register(&am33xx_cm_ll_data);
}
static void __exit am33xx_cm_exit(void)
{
cm_unregister(&am33xx_cm_ll_data);
}
