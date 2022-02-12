static void of_get_regulation_constraints(struct device_node *np,
struct regulator_init_data **init_data,
const struct regulator_desc *desc)
{
struct regulation_constraints *constraints = &(*init_data)->constraints;
struct regulator_state *suspend_state;
struct device_node *suspend_np;
int ret, i;
u32 pval;
constraints->name = of_get_property(np, "regulator-name", NULL);
if (!of_property_read_u32(np, "regulator-min-microvolt", &pval))
constraints->min_uV = pval;
if (!of_property_read_u32(np, "regulator-max-microvolt", &pval))
constraints->max_uV = pval;
if (constraints->min_uV != constraints->max_uV)
constraints->valid_ops_mask |= REGULATOR_CHANGE_VOLTAGE;
if (constraints->min_uV && constraints->max_uV)
constraints->apply_uV = true;
if (!of_property_read_u32(np, "regulator-microvolt-offset", &pval))
constraints->uV_offset = pval;
if (!of_property_read_u32(np, "regulator-min-microamp", &pval))
constraints->min_uA = pval;
if (!of_property_read_u32(np, "regulator-max-microamp", &pval))
constraints->max_uA = pval;
if (!of_property_read_u32(np, "regulator-input-current-limit-microamp",
&pval))
constraints->ilim_uA = pval;
if (constraints->min_uA != constraints->max_uA)
constraints->valid_ops_mask |= REGULATOR_CHANGE_CURRENT;
constraints->boot_on = of_property_read_bool(np, "regulator-boot-on");
constraints->always_on = of_property_read_bool(np, "regulator-always-on");
if (!constraints->always_on)
constraints->valid_ops_mask |= REGULATOR_CHANGE_STATUS;
constraints->pull_down = of_property_read_bool(np, "regulator-pull-down");
if (of_property_read_bool(np, "regulator-allow-bypass"))
constraints->valid_ops_mask |= REGULATOR_CHANGE_BYPASS;
if (of_property_read_bool(np, "regulator-allow-set-load"))
constraints->valid_ops_mask |= REGULATOR_CHANGE_DRMS;
ret = of_property_read_u32(np, "regulator-ramp-delay", &pval);
if (!ret) {
if (pval)
constraints->ramp_delay = pval;
else
constraints->ramp_disable = true;
}
ret = of_property_read_u32(np, "regulator-settling-time-us", &pval);
if (!ret)
constraints->settling_time = pval;
ret = of_property_read_u32(np, "regulator-settling-time-up-us", &pval);
if (!ret)
constraints->settling_time_up = pval;
if (constraints->settling_time_up && constraints->settling_time) {
pr_warn("%s: ambiguous configuration for settling time, ignoring 'regulator-settling-time-up-us'\n",
np->name);
constraints->settling_time_up = 0;
}
ret = of_property_read_u32(np, "regulator-settling-time-down-us",
&pval);
if (!ret)
constraints->settling_time_down = pval;
if (constraints->settling_time_down && constraints->settling_time) {
pr_warn("%s: ambiguous configuration for settling time, ignoring 'regulator-settling-time-down-us'\n",
np->name);
constraints->settling_time_down = 0;
}
ret = of_property_read_u32(np, "regulator-enable-ramp-delay", &pval);
if (!ret)
constraints->enable_time = pval;
constraints->soft_start = of_property_read_bool(np,
"regulator-soft-start");
ret = of_property_read_u32(np, "regulator-active-discharge", &pval);
if (!ret) {
constraints->active_discharge =
(pval) ? REGULATOR_ACTIVE_DISCHARGE_ENABLE :
REGULATOR_ACTIVE_DISCHARGE_DISABLE;
}
if (!of_property_read_u32(np, "regulator-initial-mode", &pval)) {
if (desc && desc->of_map_mode) {
ret = desc->of_map_mode(pval);
if (ret == -EINVAL)
pr_err("%s: invalid mode %u\n", np->name, pval);
else
constraints->initial_mode = ret;
} else {
pr_warn("%s: mapping for mode %d not defined\n",
np->name, pval);
}
}
if (!of_property_read_u32(np, "regulator-system-load", &pval))
constraints->system_load = pval;
constraints->over_current_protection = of_property_read_bool(np,
"regulator-over-current-protection");
for (i = 0; i < ARRAY_SIZE(regulator_states); i++) {
switch (i) {
case PM_SUSPEND_MEM:
suspend_state = &constraints->state_mem;
break;
case PM_SUSPEND_MAX:
suspend_state = &constraints->state_disk;
break;
case PM_SUSPEND_ON:
case PM_SUSPEND_FREEZE:
case PM_SUSPEND_STANDBY:
default:
continue;
}
suspend_np = of_get_child_by_name(np, regulator_states[i]);
if (!suspend_np || !suspend_state)
continue;
if (!of_property_read_u32(suspend_np, "regulator-mode",
&pval)) {
if (desc && desc->of_map_mode) {
ret = desc->of_map_mode(pval);
if (ret == -EINVAL)
pr_err("%s: invalid mode %u\n",
np->name, pval);
else
suspend_state->mode = ret;
} else {
pr_warn("%s: mapping for mode %d not defined\n",
np->name, pval);
}
}
if (of_property_read_bool(suspend_np,
"regulator-on-in-suspend"))
suspend_state->enabled = true;
else if (of_property_read_bool(suspend_np,
"regulator-off-in-suspend"))
suspend_state->disabled = true;
if (!of_property_read_u32(suspend_np,
"regulator-suspend-microvolt", &pval))
suspend_state->uV = pval;
if (i == PM_SUSPEND_MEM)
constraints->initial_state = PM_SUSPEND_MEM;
of_node_put(suspend_np);
suspend_state = NULL;
suspend_np = NULL;
}
}
struct regulator_init_data *of_get_regulator_init_data(struct device *dev,
struct device_node *node,
const struct regulator_desc *desc)
{
struct regulator_init_data *init_data;
if (!node)
return NULL;
init_data = devm_kzalloc(dev, sizeof(*init_data), GFP_KERNEL);
if (!init_data)
return NULL;
of_get_regulation_constraints(node, &init_data, desc);
return init_data;
}
static void devm_of_regulator_put_matches(struct device *dev, void *res)
{
struct devm_of_regulator_matches *devm_matches = res;
int i;
for (i = 0; i < devm_matches->num_matches; i++)
of_node_put(devm_matches->matches[i].of_node);
}
int of_regulator_match(struct device *dev, struct device_node *node,
struct of_regulator_match *matches,
unsigned int num_matches)
{
unsigned int count = 0;
unsigned int i;
const char *name;
struct device_node *child;
struct devm_of_regulator_matches *devm_matches;
if (!dev || !node)
return -EINVAL;
devm_matches = devres_alloc(devm_of_regulator_put_matches,
sizeof(struct devm_of_regulator_matches),
GFP_KERNEL);
if (!devm_matches)
return -ENOMEM;
devm_matches->matches = matches;
devm_matches->num_matches = num_matches;
devres_add(dev, devm_matches);
for (i = 0; i < num_matches; i++) {
struct of_regulator_match *match = &matches[i];
match->init_data = NULL;
match->of_node = NULL;
}
for_each_child_of_node(node, child) {
name = of_get_property(child,
"regulator-compatible", NULL);
if (!name)
name = child->name;
for (i = 0; i < num_matches; i++) {
struct of_regulator_match *match = &matches[i];
if (match->of_node)
continue;
if (strcmp(match->name, name))
continue;
match->init_data =
of_get_regulator_init_data(dev, child,
match->desc);
if (!match->init_data) {
dev_err(dev,
"failed to parse DT for regulator %s\n",
child->name);
return -EINVAL;
}
match->of_node = of_node_get(child);
count++;
break;
}
}
return count;
}
struct regulator_init_data *regulator_of_get_init_data(struct device *dev,
const struct regulator_desc *desc,
struct regulator_config *config,
struct device_node **node)
{
struct device_node *search, *child;
struct regulator_init_data *init_data = NULL;
const char *name;
if (!dev->of_node || !desc->of_match)
return NULL;
if (desc->regulators_node)
search = of_get_child_by_name(dev->of_node,
desc->regulators_node);
else
search = dev->of_node;
if (!search) {
dev_dbg(dev, "Failed to find regulator container node '%s'\n",
desc->regulators_node);
return NULL;
}
for_each_available_child_of_node(search, child) {
name = of_get_property(child, "regulator-compatible", NULL);
if (!name)
name = child->name;
if (strcmp(desc->of_match, name))
continue;
init_data = of_get_regulator_init_data(dev, child, desc);
if (!init_data) {
dev_err(dev,
"failed to parse DT for regulator %s\n",
child->name);
break;
}
if (desc->of_parse_cb) {
if (desc->of_parse_cb(child, desc, config)) {
dev_err(dev,
"driver callback failed to parse DT for regulator %s\n",
child->name);
init_data = NULL;
break;
}
}
of_node_get(child);
*node = child;
break;
}
of_node_put(search);
return init_data;
}
