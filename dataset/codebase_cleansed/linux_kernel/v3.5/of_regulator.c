static void of_get_regulation_constraints(struct device_node *np,
struct regulator_init_data **init_data)
{
const __be32 *min_uV, *max_uV, *uV_offset;
const __be32 *min_uA, *max_uA;
struct regulation_constraints *constraints = &(*init_data)->constraints;
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
uV_offset = of_get_property(np, "regulator-microvolt-offset", NULL);
if (uV_offset)
constraints->uV_offset = be32_to_cpu(*uV_offset);
min_uA = of_get_property(np, "regulator-min-microamp", NULL);
if (min_uA)
constraints->min_uA = be32_to_cpu(*min_uA);
max_uA = of_get_property(np, "regulator-max-microamp", NULL);
if (max_uA)
constraints->max_uA = be32_to_cpu(*max_uA);
if (constraints->min_uA != constraints->max_uA)
constraints->valid_ops_mask |= REGULATOR_CHANGE_CURRENT;
if (of_find_property(np, "regulator-boot-on", NULL))
constraints->boot_on = true;
if (of_find_property(np, "regulator-always-on", NULL))
constraints->always_on = true;
else
constraints->valid_ops_mask |= REGULATOR_CHANGE_STATUS;
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
int of_regulator_match(struct device *dev, struct device_node *node,
struct of_regulator_match *matches,
unsigned int num_matches)
{
unsigned int count = 0;
unsigned int i;
if (!dev || !node)
return -EINVAL;
for (i = 0; i < num_matches; i++) {
struct of_regulator_match *match = &matches[i];
struct device_node *child;
child = of_find_node_by_name(node, match->name);
if (!child)
continue;
match->init_data = of_get_regulator_init_data(dev, child);
if (!match->init_data) {
dev_err(dev, "failed to parse DT for regulator %s\n",
child->name);
return -EINVAL;
}
match->of_node = child;
count++;
}
return count;
}
