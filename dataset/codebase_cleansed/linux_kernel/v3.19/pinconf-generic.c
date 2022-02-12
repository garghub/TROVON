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
if (conf_items[i].has_arg) {
seq_printf(s, " (%u",
pinconf_to_config_argument(config));
if (conf_items[i].format)
seq_printf(s, " %s)", conf_items[i].format);
else
seq_puts(s, ")");
}
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
if (conf_items[i].has_arg) {
seq_printf(s, " (%u",
pinconf_to_config_argument(config));
if (conf_items[i].format)
seq_printf(s, " %s)", conf_items[i].format);
else
seq_puts(s, ")");
}
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
const struct pinconf_generic_dt_params *par = &dt_params[i];
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
*configs = kmemdup(cfg, ncfg * sizeof(unsigned long), GFP_KERNEL);
if (!*configs) {
ret = -ENOMEM;
goto out;
}
*nconfigs = ncfg;
out:
kfree(cfg);
return ret;
}
int pinconf_generic_dt_subnode_to_map(struct pinctrl_dev *pctldev,
struct device_node *np, struct pinctrl_map **map,
unsigned *reserved_maps, unsigned *num_maps,
enum pinctrl_map_type type)
{
int ret;
const char *function;
struct device *dev = pctldev->dev;
unsigned long *configs = NULL;
unsigned num_configs = 0;
unsigned reserve;
struct property *prop;
const char *group;
ret = of_property_read_string(np, "function", &function);
if (ret < 0) {
if (ret != -EINVAL)
dev_err(dev, "could not parse property function\n");
function = NULL;
}
ret = pinconf_generic_parse_dt_config(np, &configs, &num_configs);
if (ret < 0) {
dev_err(dev, "could not parse node property\n");
return ret;
}
reserve = 0;
if (function != NULL)
reserve++;
if (num_configs)
reserve++;
ret = of_property_count_strings(np, "pins");
if (ret < 0) {
dev_err(dev, "could not parse property pins\n");
goto exit;
}
reserve *= ret;
ret = pinctrl_utils_reserve_map(pctldev, map, reserved_maps,
num_maps, reserve);
if (ret < 0)
goto exit;
of_property_for_each_string(np, "pins", prop, group) {
if (function) {
ret = pinctrl_utils_add_map_mux(pctldev, map,
reserved_maps, num_maps, group,
function);
if (ret < 0)
goto exit;
}
if (num_configs) {
ret = pinctrl_utils_add_map_configs(pctldev, map,
reserved_maps, num_maps, group, configs,
num_configs, type);
if (ret < 0)
goto exit;
}
}
ret = 0;
exit:
kfree(configs);
return ret;
}
int pinconf_generic_dt_node_to_map(struct pinctrl_dev *pctldev,
struct device_node *np_config, struct pinctrl_map **map,
unsigned *num_maps, enum pinctrl_map_type type)
{
unsigned reserved_maps;
struct device_node *np;
int ret;
reserved_maps = 0;
*map = NULL;
*num_maps = 0;
for_each_child_of_node(np_config, np) {
ret = pinconf_generic_dt_subnode_to_map(pctldev, np, map,
&reserved_maps, num_maps, type);
if (ret < 0) {
pinctrl_utils_dt_free_map(pctldev, *map, *num_maps);
return ret;
}
}
return 0;
}
