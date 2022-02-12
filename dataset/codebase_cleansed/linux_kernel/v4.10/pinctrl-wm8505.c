static int wm8505_pinctrl_probe(struct platform_device *pdev)
{
struct wmt_pinctrl_data *data;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data) {
dev_err(&pdev->dev, "failed to allocate data\n");
return -ENOMEM;
}
data->banks = wm8505_banks;
data->nbanks = ARRAY_SIZE(wm8505_banks);
data->pins = wm8505_pins;
data->npins = ARRAY_SIZE(wm8505_pins);
data->groups = wm8505_groups;
data->ngroups = ARRAY_SIZE(wm8505_groups);
return wmt_pinctrl_probe(pdev, data);
}
