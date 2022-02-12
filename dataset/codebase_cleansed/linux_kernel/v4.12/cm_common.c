void __init omap2_set_globals_cm(void __iomem *cm, void __iomem *cm2)
{
cm_base = cm;
cm2_base = cm2;
}
int cm_split_idlest_reg(struct clk_omap_reg *idlest_reg, s16 *prcm_inst,
u8 *idlest_reg_id)
{
if (!cm_ll_data->split_idlest_reg) {
WARN_ONCE(1, "cm: %s: no low-level function defined\n",
__func__);
return -EINVAL;
}
return cm_ll_data->split_idlest_reg(idlest_reg, prcm_inst,
idlest_reg_id);
}
int omap_cm_wait_module_ready(u8 part, s16 prcm_mod, u16 idlest_reg,
u8 idlest_shift)
{
if (!cm_ll_data->wait_module_ready) {
WARN_ONCE(1, "cm: %s: no low-level function defined\n",
__func__);
return -EINVAL;
}
return cm_ll_data->wait_module_ready(part, prcm_mod, idlest_reg,
idlest_shift);
}
int omap_cm_wait_module_idle(u8 part, s16 prcm_mod, u16 idlest_reg,
u8 idlest_shift)
{
if (!cm_ll_data->wait_module_idle) {
WARN_ONCE(1, "cm: %s: no low-level function defined\n",
__func__);
return -EINVAL;
}
return cm_ll_data->wait_module_idle(part, prcm_mod, idlest_reg,
idlest_shift);
}
int omap_cm_module_enable(u8 mode, u8 part, u16 inst, u16 clkctrl_offs)
{
if (!cm_ll_data->module_enable) {
WARN_ONCE(1, "cm: %s: no low-level function defined\n",
__func__);
return -EINVAL;
}
cm_ll_data->module_enable(mode, part, inst, clkctrl_offs);
return 0;
}
int omap_cm_module_disable(u8 part, u16 inst, u16 clkctrl_offs)
{
if (!cm_ll_data->module_disable) {
WARN_ONCE(1, "cm: %s: no low-level function defined\n",
__func__);
return -EINVAL;
}
cm_ll_data->module_disable(part, inst, clkctrl_offs);
return 0;
}
int cm_register(struct cm_ll_data *cld)
{
if (!cld)
return -EINVAL;
if (cm_ll_data != &null_cm_ll_data)
return -EEXIST;
cm_ll_data = cld;
return 0;
}
int cm_unregister(struct cm_ll_data *cld)
{
if (!cld || cm_ll_data != cld)
return -EINVAL;
cm_ll_data = &null_cm_ll_data;
return 0;
}
int __init omap2_cm_base_init(void)
{
struct device_node *np;
const struct of_device_id *match;
struct omap_prcm_init_data *data;
void __iomem *mem;
for_each_matching_node_and_match(np, omap_cm_dt_match_table, &match) {
data = (struct omap_prcm_init_data *)match->data;
mem = of_iomap(np, 0);
if (!mem)
return -ENOMEM;
if (data->index == TI_CLKM_CM)
cm_base = mem + data->offset;
if (data->index == TI_CLKM_CM2)
cm2_base = mem + data->offset;
data->mem = mem;
data->np = np;
if (data->init && (data->flags & CM_SINGLE_INSTANCE ||
(cm_base && cm2_base)))
data->init(data);
}
return 0;
}
int __init omap_cm_init(void)
{
struct device_node *np;
const struct of_device_id *match;
const struct omap_prcm_init_data *data;
int ret;
for_each_matching_node_and_match(np, omap_cm_dt_match_table, &match) {
data = match->data;
if (data->flags & CM_NO_CLOCKS)
continue;
ret = omap2_clk_provider_init(np, data->index, NULL, data->mem);
if (ret)
return ret;
}
return 0;
}
