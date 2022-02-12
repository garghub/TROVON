static int syscfg_reset_program_hw(struct reset_controller_dev *rcdev,
unsigned long idx, int assert)
{
struct syscfg_reset_controller *rst = to_syscfg_reset_controller(rcdev);
const struct syscfg_reset_channel *ch;
u32 ctrl_val = rst->active_low ? !assert : !!assert;
int err;
if (idx >= rcdev->nr_resets)
return -EINVAL;
ch = &rst->channels[idx];
err = regmap_field_write(ch->reset, ctrl_val);
if (err)
return err;
if (ch->ack) {
unsigned long timeout = jiffies + msecs_to_jiffies(1000);
u32 ack_val;
while (true) {
err = regmap_field_read(ch->ack, &ack_val);
if (err)
return err;
if (ack_val == ctrl_val)
break;
if (time_after(jiffies, timeout))
return -ETIME;
cpu_relax();
}
}
return 0;
}
static int syscfg_reset_assert(struct reset_controller_dev *rcdev,
unsigned long idx)
{
return syscfg_reset_program_hw(rcdev, idx, true);
}
static int syscfg_reset_deassert(struct reset_controller_dev *rcdev,
unsigned long idx)
{
return syscfg_reset_program_hw(rcdev, idx, false);
}
static int syscfg_reset_dev(struct reset_controller_dev *rcdev,
unsigned long idx)
{
int err = syscfg_reset_assert(rcdev, idx);
if (err)
return err;
return syscfg_reset_deassert(rcdev, idx);
}
static int syscfg_reset_controller_register(struct device *dev,
const struct syscfg_reset_controller_data *data)
{
struct syscfg_reset_controller *rc;
size_t size;
int i, err;
rc = devm_kzalloc(dev, sizeof(*rc), GFP_KERNEL);
if (!rc)
return -ENOMEM;
size = sizeof(struct syscfg_reset_channel) * data->nr_channels;
rc->channels = devm_kzalloc(dev, size, GFP_KERNEL);
if (!rc->channels)
return -ENOMEM;
rc->rst.ops = &syscfg_reset_ops,
rc->rst.of_node = dev->of_node;
rc->rst.nr_resets = data->nr_channels;
rc->active_low = data->active_low;
for (i = 0; i < data->nr_channels; i++) {
struct regmap *map;
struct regmap_field *f;
const char *compatible = data->channels[i].compatible;
map = syscon_regmap_lookup_by_compatible(compatible);
if (IS_ERR(map))
return PTR_ERR(map);
f = devm_regmap_field_alloc(dev, map, data->channels[i].reset);
if (IS_ERR(f))
return PTR_ERR(f);
rc->channels[i].reset = f;
if (!data->wait_for_ack)
continue;
f = devm_regmap_field_alloc(dev, map, data->channels[i].ack);
if (IS_ERR(f))
return PTR_ERR(f);
rc->channels[i].ack = f;
}
err = reset_controller_register(&rc->rst);
if (!err)
dev_info(dev, "registered\n");
return err;
}
int syscfg_reset_probe(struct platform_device *pdev)
{
struct device *dev = pdev ? &pdev->dev : NULL;
const struct of_device_id *match;
if (!dev || !dev->driver)
return -ENODEV;
match = of_match_device(dev->driver->of_match_table, dev);
if (!match || !match->data)
return -EINVAL;
return syscfg_reset_controller_register(dev, match->data);
}
