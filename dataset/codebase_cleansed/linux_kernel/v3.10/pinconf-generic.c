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
