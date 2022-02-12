static int __init
realview_gic_of_init(struct device_node *node, struct device_node *parent)
{
static struct regmap *map;
map = syscon_regmap_lookup_by_compatible("arm,realview-pb11mp-syscon");
if (!IS_ERR(map)) {
regmap_write(map, REALVIEW_SYS_LOCK_OFFSET,
VERSATILE_LOCK_VAL);
regmap_update_bits(map, REALVIEW_PB11MP_SYS_PLD_CTRL1,
PLD_INTMODE_NEW_NO_DCC,
PLD_INTMODE_MASK);
regmap_write(map, REALVIEW_SYS_LOCK_OFFSET, 0x0000);
pr_info("TC11MP GIC: set up interrupt controller to NEW mode, no DCC\n");
} else {
pr_err("TC11MP GIC setup: could not find syscon\n");
return -ENXIO;
}
return gic_of_init(node, parent);
}
