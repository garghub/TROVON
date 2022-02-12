static int __init rockchip_grf_init(void)
{
const struct rockchip_grf_info *grf_info;
const struct of_device_id *match;
struct device_node *np;
struct regmap *grf;
int ret, i;
np = of_find_matching_node_and_match(NULL, rockchip_grf_dt_match,
&match);
if (!np)
return -ENODEV;
if (!match || !match->data) {
pr_err("%s: missing grf data\n", __func__);
return -EINVAL;
}
grf_info = match->data;
grf = syscon_node_to_regmap(np);
if (IS_ERR(grf)) {
pr_err("%s: could not get grf syscon\n", __func__);
return PTR_ERR(grf);
}
for (i = 0; i < grf_info->num_values; i++) {
const struct rockchip_grf_value *val = &grf_info->values[i];
pr_debug("%s: adjusting %s in %#6x to %#10x\n", __func__,
val->desc, val->reg, val->val);
ret = regmap_write(grf, val->reg, val->val);
if (ret < 0)
pr_err("%s: write to %#6x failed with %d\n",
__func__, val->reg, ret);
}
return 0;
}
