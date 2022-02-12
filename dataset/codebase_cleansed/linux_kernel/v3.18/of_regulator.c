static void of_get_regulation_constraints(struct device_node *np,
struct regulator_init_data **init_data)
{
const __be32 *min_uV, *max_uV;
struct regulation_constraints *constraints = &(*init_data)->constraints;
int ret;
u32 pval;
constraints->name = of_get_property(np, "regulator-name", NULL);
min_uV = of_get_property(np, "regulator-min-microvolt", NULL);
if (min_uV)
constraints->min_uV = be32_to_cpu(*min_uV);
max_uV = of_get_property(np, "regulator-max-microvolt", NULL);
if (max_uV)
constraints->max_uV = be32_to_cpu(*max_uV);
if (constraints->min_uV != constraints->max_uV)
constraints->valid_ops_mask |= REGULATOR_CHANGE_VOLTAGE;
if (min_uV && max_uV && constraints->min_uV == constraints->max_uV)
constraints->apply_uV = true;
if (!of_property_read_u32(np, "regulator-microvolt-offset", &pval))
constraints->uV_offset = pval;
if (!of_property_read_u32(np, "regulator-min-microamp", &pval))
constraints->min_uA = pval;
if (!of_property_read_u32(np, "regulator-max-microamp", &pval))
constraints->max_uA = pval;
if (constraints->min_uA != constraints->max_uA)
constraints->valid_ops_mask |= REGULATOR_CHANGE_CURRENT;
constraints->boot_on = of_property_read_bool(np, "regulator-boot-on");
constraints->always_on = of_property_read_bool(np, "regulator-always-on");
if (!constraints->always_on)
constraints->valid_ops_mask |= REGULATOR_CHANGE_STATUS;
if (of_property_read_bool(np, "regulator-allow-bypass"))
constraints->valid_ops_mask |= REGULATOR_CHANGE_BYPASS;
ret = of_property_read_u32(np, "regulator-ramp-delay", &pval);
if (!ret) {
if (pval)
constraints->ramp_delay = pval;
else
constraints->ramp_disable = true;
}
ret = of_property_read_u32(np, "regulator-enable-ramp-delay", &pval);
if (!ret)
constraints->enable_time = pval;
}
struct regulator_init_data *of_get_regulator_init_data(struct device *dev,
struct device_node *node)
{
struct regulator_init_data *init_data;
if (!node)
return NULL;
init_data = devm_kzalloc(dev, sizeof(*init_data), GFP_KERNEL);
if (!init_data)
return NULL;
of_get_regulation_constraints(node, &init_data);
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
of_get_regulator_init_data(dev, child);
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
for_each_child_of_node(search, child) {
name = of_get_property(child, "regulator-compatible", NULL);
if (!name)
name = child->name;
if (strcmp(desc->of_match, name))
continue;
init_data = of_get_regulator_init_data(dev, child);
if (!init_data) {
dev_err(dev,
"failed to parse DT for regulator %s\n",
child->name);
break;
}
of_node_get(child);
*node = child;
break;
}
of_node_put(search);
return init_data;
}
