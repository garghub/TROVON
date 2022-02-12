static int sr_class3_enable(struct voltagedomain *voltdm)
{
unsigned long volt = voltdm_get_voltage(voltdm);
if (!volt) {
pr_warning("%s: Curr voltage unknown. Cannot enable sr_%s\n",
__func__, voltdm->name);
return -ENODATA;
}
omap_vp_enable(voltdm);
return sr_enable(voltdm, volt);
}
static int sr_class3_disable(struct voltagedomain *voltdm, int is_volt_reset)
{
sr_disable_errgen(voltdm);
omap_vp_disable(voltdm);
sr_disable(voltdm);
if (is_volt_reset)
voltdm_reset(voltdm);
return 0;
}
static int sr_class3_configure(struct voltagedomain *voltdm)
{
return sr_configure_errgen(voltdm);
}
static int __init sr_class3_init(void)
{
pr_info("SmartReflex Class3 initialized\n");
return sr_register_class(&class3_data);
}
