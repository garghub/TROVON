static void pinconf_generic_dump_one(struct pinctrl_dev *pctldev,
struct seq_file *s, const char *gname,
unsigned pin,
const struct pin_config_item *items,
int nitems, int *print_sep)
{
int i;
for (i = 0; i < nitems; i++) {
unsigned long config;
int ret;
config = pinconf_to_config_packed(items[i].param, 0);
if (gname)
ret = pin_config_group_get(dev_name(pctldev->dev),
gname, &config);
else
ret = pin_config_get_for_pin(pctldev, pin, &config);
if (ret == -EINVAL || ret == -ENOTSUPP)
continue;
if (ret) {
seq_printf(s, "ERROR READING CONFIG SETTING %d ", i);
continue;
}
if (*print_sep)
seq_puts(s, ", ");
*print_sep = 1;
seq_puts(s, items[i].display);
if (items[i].has_arg) {
seq_printf(s, " (%u",
pinconf_to_config_argument(config));
if (items[i].format)
seq_printf(s, " %s)", items[i].format);
else
seq_puts(s, ")");
}
}
}
void pinconf_generic_dump_pins(struct pinctrl_dev *pctldev, struct seq_file *s,
const char *gname, unsigned pin)
{
const struct pinconf_ops *ops = pctldev->desc->confops;
int print_sep = 0;
if (!ops->is_generic)
return;
pinconf_generic_dump_one(pctldev, s, gname, pin, conf_items,
ARRAY_SIZE(conf_items), &print_sep);
if (pctldev->desc->num_custom_params &&
pctldev->desc->custom_conf_items)
pinconf_generic_dump_one(pctldev, s, gname, pin,
pctldev->desc->custom_conf_items,
pctldev->desc->num_custom_params,
&print_sep);
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
if (!pctldev->desc->num_custom_params ||
!pctldev->desc->custom_conf_items)
return;
for (i = 0; i < pctldev->desc->num_custom_params; i++) {
if (pinconf_to_config_param(config) !=
pctldev->desc->custom_conf_items[i].param)
continue;
seq_printf(s, "%s: 0x%x",
pctldev->desc->custom_conf_items[i].display,
pinconf_to_config_argument(config));
}
}
static void parse_dt_cfg(struct device_node *np,
const struct pinconf_generic_params *params,
unsigned int count, unsigned long *cfg,
unsigned int *ncfg)
{
int i;
for (i = 0; i < count; i++) {
u32 val;
int ret;
const struct pinconf_generic_params *par = &params[i];
ret = of_property_read_u32(np, par->property, &val);
if (ret == -EINVAL)
continue;
if (ret)
val = par->default_value;
pr_debug("found %s with value %u\n", par->property, val);
cfg[*ncfg] = pinconf_to_config_packed(par->param, val);
(*ncfg)++;
}
}
int pinconf_generic_parse_dt_config(struct device_node *np,
struct pinctrl_dev *pctldev,
unsigned long **configs,
unsigned int *nconfigs)
{
unsigned long *cfg;
unsigned int max_cfg, ncfg = 0;
int ret;
if (!np)
return -EINVAL;
max_cfg = ARRAY_SIZE(dt_params);
if (pctldev)
max_cfg += pctldev->desc->num_custom_params;
cfg = kcalloc(max_cfg, sizeof(*cfg), GFP_KERNEL);
if (!cfg)
return -ENOMEM;
parse_dt_cfg(np, dt_params, ARRAY_SIZE(dt_params), cfg, &ncfg);
if (pctldev && pctldev->desc->num_custom_params &&
pctldev->desc->custom_params)
parse_dt_cfg(np, pctldev->desc->custom_params,
pctldev->desc->num_custom_params, cfg, &ncfg);
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
unsigned reserve, strings_count;
struct property *prop;
const char *group;
const char *subnode_target_type = "pins";
ret = of_property_count_strings(np, "pins");
if (ret < 0) {
ret = of_property_count_strings(np, "groups");
if (ret < 0)
return 0;
if (type == PIN_MAP_TYPE_INVALID)
type = PIN_MAP_TYPE_CONFIGS_GROUP;
subnode_target_type = "groups";
} else {
if (type == PIN_MAP_TYPE_INVALID)
type = PIN_MAP_TYPE_CONFIGS_PIN;
}
strings_count = ret;
ret = of_property_read_string(np, "function", &function);
if (ret < 0) {
if (ret != -EINVAL)
dev_err(dev, "%s: could not parse property function\n",
of_node_full_name(np));
function = NULL;
}
ret = pinconf_generic_parse_dt_config(np, pctldev, &configs,
&num_configs);
if (ret < 0) {
dev_err(dev, "%s: could not parse node property\n",
of_node_full_name(np));
return ret;
}
reserve = 0;
if (function != NULL)
reserve++;
if (num_configs)
reserve++;
reserve *= strings_count;
ret = pinctrl_utils_reserve_map(pctldev, map, reserved_maps,
num_maps, reserve);
if (ret < 0)
goto exit;
of_property_for_each_string(np, subnode_target_type, prop, group) {
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
ret = pinconf_generic_dt_subnode_to_map(pctldev, np_config, map,
&reserved_maps, num_maps, type);
if (ret < 0)
goto exit;
for_each_available_child_of_node(np_config, np) {
ret = pinconf_generic_dt_subnode_to_map(pctldev, np, map,
&reserved_maps, num_maps, type);
if (ret < 0)
goto exit;
}
return 0;
exit:
pinctrl_utils_free_map(pctldev, *map, *num_maps);
return ret;
}
void pinconf_generic_dt_free_map(struct pinctrl_dev *pctldev,
struct pinctrl_map *map,
unsigned num_maps)
{
pinctrl_utils_free_map(pctldev, map, num_maps);
}
