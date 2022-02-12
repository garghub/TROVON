static int sr_class3_enable(struct omap_sr *sr)
{
unsigned long volt = voltdm_get_voltage(sr->voltdm);
if (!volt) {
pr_warn("%s: Curr voltage unknown. Cannot enable %s\n",
__func__, sr->name);
return -ENODATA;
}
omap_vp_enable(sr->voltdm);
return sr_enable(sr, volt);
}
static int sr_class3_disable(struct omap_sr *sr, int is_volt_reset)
{
sr_disable_errgen(sr);
omap_vp_disable(sr->voltdm);
sr_disable(sr);
if (is_volt_reset)
voltdm_reset(sr->voltdm);
return 0;
}
static int sr_class3_configure(struct omap_sr *sr)
{
return sr_configure_errgen(sr);
}
static int __init sr_class3_init(void)
{
pr_info("SmartReflex Class3 initialized\n");
return sr_register_class(&class3_data);
}
