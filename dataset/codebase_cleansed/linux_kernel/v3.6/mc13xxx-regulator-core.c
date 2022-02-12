static int mc13xxx_regulator_enable(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
struct mc13xxx_regulator *mc13xxx_regulators = priv->mc13xxx_regulators;
int id = rdev_get_id(rdev);
int ret;
dev_dbg(rdev_get_dev(rdev), "%s id: %d\n", __func__, id);
mc13xxx_lock(priv->mc13xxx);
ret = mc13xxx_reg_rmw(priv->mc13xxx, mc13xxx_regulators[id].reg,
mc13xxx_regulators[id].enable_bit,
mc13xxx_regulators[id].enable_bit);
mc13xxx_unlock(priv->mc13xxx);
return ret;
}
static int mc13xxx_regulator_disable(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
struct mc13xxx_regulator *mc13xxx_regulators = priv->mc13xxx_regulators;
int id = rdev_get_id(rdev);
int ret;
dev_dbg(rdev_get_dev(rdev), "%s id: %d\n", __func__, id);
mc13xxx_lock(priv->mc13xxx);
ret = mc13xxx_reg_rmw(priv->mc13xxx, mc13xxx_regulators[id].reg,
mc13xxx_regulators[id].enable_bit, 0);
mc13xxx_unlock(priv->mc13xxx);
return ret;
}
static int mc13xxx_regulator_is_enabled(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
struct mc13xxx_regulator *mc13xxx_regulators = priv->mc13xxx_regulators;
int ret, id = rdev_get_id(rdev);
unsigned int val;
mc13xxx_lock(priv->mc13xxx);
ret = mc13xxx_reg_read(priv->mc13xxx, mc13xxx_regulators[id].reg, &val);
mc13xxx_unlock(priv->mc13xxx);
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
int ret;
mc13xxx_lock(priv->mc13xxx);
ret = mc13xxx_reg_rmw(priv->mc13xxx, mc13xxx_regulators[id].vsel_reg,
mc13xxx_regulators[id].vsel_mask,
selector << mc13xxx_regulators[id].vsel_shift);
mc13xxx_unlock(priv->mc13xxx);
return ret;
}
static int mc13xxx_regulator_get_voltage(struct regulator_dev *rdev)
{
struct mc13xxx_regulator_priv *priv = rdev_get_drvdata(rdev);
struct mc13xxx_regulator *mc13xxx_regulators = priv->mc13xxx_regulators;
int ret, id = rdev_get_id(rdev);
unsigned int val;
dev_dbg(rdev_get_dev(rdev), "%s id: %d\n", __func__, id);
mc13xxx_lock(priv->mc13xxx);
ret = mc13xxx_reg_read(priv->mc13xxx,
mc13xxx_regulators[id].vsel_reg, &val);
mc13xxx_unlock(priv->mc13xxx);
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
rdev->desc->volt_table[0] <= max_uV)
return 0;
else
return -EINVAL;
}
int mc13xxx_fixed_regulator_get_voltage(struct regulator_dev *rdev)
{
int id = rdev_get_id(rdev);
dev_dbg(rdev_get_dev(rdev), "%s id: %d\n", __func__, id);
return rdev->desc->volt_table[0];
}
int __devinit mc13xxx_get_num_regulators_dt(struct platform_device *pdev)
{
struct device_node *parent, *child;
int num = 0;
of_node_get(pdev->dev.parent->of_node);
parent = of_find_node_by_name(pdev->dev.parent->of_node, "regulators");
if (!parent)
return -ENODEV;
for_each_child_of_node(parent, child)
num++;
return num;
}
struct mc13xxx_regulator_init_data * __devinit mc13xxx_parse_regulators_dt(
struct platform_device *pdev, struct mc13xxx_regulator *regulators,
int num_regulators)
{
struct mc13xxx_regulator_priv *priv = platform_get_drvdata(pdev);
struct mc13xxx_regulator_init_data *data, *p;
struct device_node *parent, *child;
int i;
of_node_get(pdev->dev.parent->of_node);
parent = of_find_node_by_name(pdev->dev.parent->of_node, "regulators");
if (!parent)
return NULL;
data = devm_kzalloc(&pdev->dev, sizeof(*data) * priv->num_regulators,
GFP_KERNEL);
if (!data)
return NULL;
p = data;
for_each_child_of_node(parent, child) {
for (i = 0; i < num_regulators; i++) {
if (!of_node_cmp(child->name,
regulators[i].desc.name)) {
p->id = i;
p->init_data = of_get_regulator_init_data(
&pdev->dev, child);
p->node = child;
p++;
break;
}
}
}
return data;
}
