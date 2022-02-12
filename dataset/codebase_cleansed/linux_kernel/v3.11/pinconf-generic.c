void pinconf_generic_dump_pin(struct pinctrl_dev *pctldev,
struct seq_file *s, unsigned pin)
{
const struct pinconf_ops *ops = pctldev->desc->confops;
int i;
if (!ops->is_generic)
return;
for (i = 0; i < ARRAY_SIZE(conf_items); i++) {
unsigned long config;
int ret;
config = pinconf_to_config_packed(conf_items[i].param, 0);
ret = pin_config_get_for_pin(pctldev, pin, &config);
if (ret == -EINVAL || ret == -ENOTSUPP)
continue;
if (ret) {
seq_printf(s, "ERROR READING CONFIG SETTING %d ", i);
continue;
}
seq_puts(s, " ");
seq_puts(s, conf_items[i].display);
if (conf_items[i].format &&
pinconf_to_config_argument(config) != 0)
seq_printf(s, " (%u %s)",
pinconf_to_config_argument(config),
conf_items[i].format);
}
}
void pinconf_generic_dump_group(struct pinctrl_dev *pctldev,
struct seq_file *s, const char *gname)
{
const struct pinconf_ops *ops = pctldev->desc->confops;
int i;
if (!ops->is_generic)
return;
for (i = 0; i < ARRAY_SIZE(conf_items); i++) {
unsigned long config;
int ret;
config = pinconf_to_config_packed(conf_items[i].param, 0);
ret = pin_config_group_get(dev_name(pctldev->dev), gname,
&config);
if (ret == -EINVAL || ret == -ENOTSUPP)
continue;
if (ret) {
seq_printf(s, "ERROR READING CONFIG SETTING %d ", i);
continue;
}
seq_puts(s, " ");
seq_puts(s, conf_items[i].display);
if (conf_items[i].format && config != 0)
seq_printf(s, " (%u %s)",
pinconf_to_config_argument(config),
conf_items[i].format);
}
}
void pinconf_generic_dump_config(struct pinctrl_dev *pctldev,
struct seq_file *s, unsigned long config)
{
int i;
for (i = 0; i < ARRAY_SIZE(conf_items); i++) {
if (pinconf_to_config_param(config) != conf_items[i].param)
continue;
seq_printf(s, "%s: 0x%x", conf_items[i].display,
pinconf_to_config_argument(config));
}
}
int pinconf_generic_parse_dt_config(struct device_node *np,
unsigned long **configs,
unsigned int *nconfigs)
{
unsigned long *cfg;
unsigned int ncfg = 0;
int ret;
int i;
u32 val;
if (!np)
return -EINVAL;
cfg = kzalloc(sizeof(*cfg) * ARRAY_SIZE(dt_params), GFP_KERNEL);
if (!cfg)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(dt_params); i++) {
struct pinconf_generic_dt_params *par = &dt_params[i];
ret = of_property_read_u32(np, par->property, &val);
if (ret == -EINVAL)
continue;
if (ret)
val = par->default_value;
pr_debug("found %s with value %u\n", par->property, val);
cfg[ncfg] = pinconf_to_config_packed(par->param, val);
ncfg++;
}
ret = 0;
if (ncfg == 0) {
*configs = NULL;
*nconfigs = 0;
goto out;
}
*configs = kzalloc(ncfg * sizeof(unsigned long), GFP_KERNEL);
if (!*configs) {
ret = -ENOMEM;
goto out;
}
memcpy(*configs, cfg, ncfg * sizeof(unsigned long));
*nconfigs = ncfg;
out:
kfree(cfg);
return ret;
}
