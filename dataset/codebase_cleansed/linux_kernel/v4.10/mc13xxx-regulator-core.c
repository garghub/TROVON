static int mc13xxx_regulator_enable(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
struct mc13xxx_regulator *mc13xxx_regulators = priv->mc13xxx_regulators;
int id = rdev_get_id(rdev);
dev_dbg(rdev_get_dev(rdev), "%s id: %d\n", __func__, id);
return mc13xxx_reg_rmw(priv->mc13xxx, mc13xxx_regulators[id].reg,
mc13xxx_regulators[id].enable_bit,
mc13xxx_regulators[id].enable_bit);
}
static int mc13xxx_regulator_disable(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
struct mc13xxx_regulator *mc13xxx_regulators = priv->mc13xxx_regulators;
int id = rdev_get_id(rdev);
dev_dbg(rdev_get_dev(rdev), "%s id: %d\n", __func__, id);
return mc13xxx_reg_rmw(priv->mc13xxx, mc13xxx_regulators[id].reg,
mc13xxx_regulators[id].enable_bit, 0);
}
static int mc13xxx_regulator_is_enabled(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
struct mc13xxx_regulator *mc13xxx_regulators = priv->mc13xxx_regulators;
int ret, id = rdev_get_id(rdev);
unsigned int val;
ret = mc13xxx_reg_read(priv->mc13xxx, mc13xxx_regulators[id].reg, &val);
if (ret)
return ret;
return (val & mc13xxx_regulators[id].enable_bit) != 0;
}
static int mc13xxx_regulator_set_voltage_sel(struct regulator_dev *rdev,
unsigned selector)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
struct mc13xxx_regulator *mc13xxx_regulators = priv->mc13xxx_regulators;
int id = rdev_get_id(rdev);
return mc13xxx_reg_rmw(priv->mc13xxx, mc13xxx_regulators[id].vsel_reg,
mc13xxx_regulators[id].vsel_mask,
selector << mc13xxx_regulators[id].vsel_shift);
}
static int mc13xxx_regulator_get_voltage(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
struct mc13xxx_regulator *mc13xxx_regulators = priv->mc13xxx_regulators;
int ret, id = rdev_get_id(rdev);
unsigned int val;
dev_dbg(rdev_get_dev(rdev), "%s id: %d\n", __func__, id);
ret = mc13xxx_reg_read(priv->mc13xxx,
mc13xxx_regulators[id].vsel_reg, &val);
if (ret)
return ret;
val = (val & mc13xxx_regulators[id].vsel_mask)
>> mc13xxx_regulators[id].vsel_shift;
dev_dbg(rdev_get_dev(rdev), "%s id: %d val: %d\n", __func__, id, val);
BUG_ON(val >= mc13xxx_regulators[id].desc.n_voltages);
return rdev->desc->volt_table[val];
}
int mc13xxx_fixed_regulator_set_voltage(struct regulator_dev *rdev, int min_uV,
int max_uV, unsigned *selector)
{
int id = rdev_get_id(rdev);
dev_dbg(rdev_get_dev(rdev), "%s id: %d min_uV: %d max_uV: %d\n",
__func__, id, min_uV, max_uV);
if (min_uV <= rdev->desc->volt_table[0] &&
rdev->desc->volt_table[0] <= max_uV) {
*selector = 0;
return 0;
} else {
return -EINVAL;
}
}
int mc13xxx_get_num_regulators_dt(struct platform_device *pdev)
{
struct device_node *parent;
int num;
if (!pdev->dev.parent->of_node)
return -ENODEV;
parent = of_get_child_by_name(pdev->dev.parent->of_node, "regulators");
if (!parent)
return -ENODEV;
num = of_get_child_count(parent);
of_node_put(parent);
return num;
}
struct mc13xxx_regulator_init_data *mc13xxx_parse_regulators_dt(
struct platform_device *pdev, struct mc13xxx_regulator *regulators,
int num_regulators)
{
struct mc13xxx_regulator_priv *priv = platform_get_drvdata(pdev);
struct mc13xxx_regulator_init_data *data, *p;
struct device_node *parent, *child;
int i, parsed = 0;
if (!pdev->dev.parent->of_node)
return NULL;
parent = of_get_child_by_name(pdev->dev.parent->of_node, "regulators");
if (!parent)
return NULL;
data = devm_kzalloc(&pdev->dev, sizeof(*data) * priv->num_regulators,
GFP_KERNEL);
if (!data) {
of_node_put(parent);
return NULL;
}
p = data;
for_each_child_of_node(parent, child) {
int found = 0;
for (i = 0; i < num_regulators; i++) {
if (!regulators[i].desc.name)
continue;
if (!of_node_cmp(child->name,
regulators[i].desc.name)) {
p->id = i;
p->init_data = of_get_regulator_init_data(
&pdev->dev, child,
&regulators[i].desc);
p->node = child;
p++;
parsed++;
found = 1;
break;
}
}
if (!found)
dev_warn(&pdev->dev,
"Unknown regulator: %s\n", child->name);
}
of_node_put(parent);
priv->num_regulators = parsed;
return data;
}
