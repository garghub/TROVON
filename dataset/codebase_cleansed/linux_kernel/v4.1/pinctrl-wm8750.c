static int wm8750_pinctrl_probe(struct platform_device *pdev)
{
struct wmt_pinctrl_data *data;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data) {
dev_err(&pdev->dev, "failed to allocate data\n");
return -ENOMEM;
}
data->banks = wm8750_banks;
data->nbanks = ARRAY_SIZE(wm8750_banks);
data->pins = wm8750_pins;
data->npins = ARRAY_SIZE(wm8750_pins);
data->groups = wm8750_groups;
data->ngroups = ARRAY_SIZE(wm8750_groups);
return wmt_pinctrl_probe(pdev, data);
}
static int wm8750_pinctrl_remove(struct platform_device *pdev)
{
return wmt_pinctrl_remove(pdev);
}
