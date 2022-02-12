static int vt8500_pinctrl_probe(struct platform_device *pdev)
{
struct wmt_pinctrl_data *data;
data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
if (!data) {
dev_err(&pdev->dev, "failed to allocate data\n");
return -ENOMEM;
}
data->banks = vt8500_banks;
data->nbanks = ARRAY_SIZE(vt8500_banks);
data->pins = vt8500_pins;
data->npins = ARRAY_SIZE(vt8500_pins);
data->groups = vt8500_groups;
data->ngroups = ARRAY_SIZE(vt8500_groups);
return wmt_pinctrl_probe(pdev, data);
}
