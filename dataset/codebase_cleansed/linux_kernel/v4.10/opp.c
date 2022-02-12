int __init omap_init_opp_table(struct omap_opp_def *opp_def,
u32 opp_def_size)
{
int i, r;
if (of_have_populated_dt())
return -EINVAL;
if (!opp_def || !opp_def_size) {
pr_err("%s: invalid params!\n", __func__);
return -EINVAL;
}
if (omap_table_init)
return -EEXIST;
omap_table_init = 1;
for (i = 0; i < opp_def_size; i++, opp_def++) {
struct omap_hwmod *oh;
struct device *dev;
if (!opp_def->hwmod_name) {
pr_err("%s: NULL name of omap_hwmod, failing [%d].\n",
__func__, i);
return -EINVAL;
}
if (!strncmp(opp_def->hwmod_name, "mpu", 3)) {
dev = get_cpu_device(0);
} else {
oh = omap_hwmod_lookup(opp_def->hwmod_name);
if (!oh || !oh->od) {
pr_debug("%s: no hwmod or odev for %s, [%d] cannot add OPPs.\n",
__func__, opp_def->hwmod_name, i);
continue;
}
dev = &oh->od->pdev->dev;
}
r = dev_pm_opp_add(dev, opp_def->freq, opp_def->u_volt);
if (r) {
dev_err(dev, "%s: add OPP %ld failed for %s [%d] result=%d\n",
__func__, opp_def->freq,
opp_def->hwmod_name, i, r);
} else {
if (!opp_def->default_available)
r = dev_pm_opp_disable(dev, opp_def->freq);
if (r)
dev_err(dev, "%s: disable %ld failed for %s [%d] result=%d\n",
__func__, opp_def->freq,
opp_def->hwmod_name, i, r);
}
}
return 0;
}
