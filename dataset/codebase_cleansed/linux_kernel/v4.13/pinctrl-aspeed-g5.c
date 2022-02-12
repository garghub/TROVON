static int aspeed_g5_pinctrl_probe(struct platform_device *pdev)
{
int i;
struct regmap *map;
struct device_node *node;
for (i = 0; i < ARRAY_SIZE(aspeed_g5_pins); i++)
aspeed_g5_pins[i].number = i;
node = of_parse_phandle(pdev->dev.of_node, "aspeed,external-nodes", 0);
map = syscon_node_to_regmap(node);
of_node_put(node);
if (IS_ERR(map)) {
dev_warn(&pdev->dev, "No GFX phandle found, some mux configurations may fail\n");
map = NULL;
}
aspeed_g5_pinctrl_data.maps[ASPEED_IP_GFX] = map;
node = of_parse_phandle(pdev->dev.of_node, "aspeed,external-nodes", 1);
if (node) {
map = syscon_node_to_regmap(node->parent);
if (IS_ERR(map)) {
dev_warn(&pdev->dev, "LHC parent is not a syscon, some mux configurations may fail\n");
map = NULL;
}
} else {
dev_warn(&pdev->dev, "No LHC phandle found, some mux configurations may fail\n");
map = NULL;
}
of_node_put(node);
aspeed_g5_pinctrl_data.maps[ASPEED_IP_LPC] = map;
return aspeed_pinctrl_probe(pdev, &aspeed_g5_pinctrl_desc,
&aspeed_g5_pinctrl_data);
}
static int aspeed_g5_pinctrl_init(void)
{
return platform_driver_register(&aspeed_g5_pinctrl_driver);
}
