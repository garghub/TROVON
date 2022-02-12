static int __init
realview_gic_of_init(struct device_node *node, struct device_node *parent)
{
struct regmap *map;
struct device_node *np;
const struct of_device_id *gic_id;
u32 pld1_ctrl;
np = of_find_matching_node_and_match(NULL, syscon_pldset_of_match,
&gic_id);
if (!np)
return -ENODEV;
pld1_ctrl = (u32)gic_id->data;
map = syscon_node_to_regmap(np);
if (!IS_ERR(map)) {
regmap_write(map, REALVIEW_SYS_LOCK_OFFSET,
VERSATILE_LOCK_VAL);
regmap_update_bits(map, pld1_ctrl,
PLD_INTMODE_NEW_NO_DCC,
PLD_INTMODE_MASK);
regmap_write(map, REALVIEW_SYS_LOCK_OFFSET, 0x0000);
pr_info("RealView GIC: set up interrupt controller to NEW mode, no DCC\n");
} else {
pr_err("RealView GIC setup: could not find syscon\n");
return -ENODEV;
}
return gic_of_init(node, parent);
}
