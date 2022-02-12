static int gsbi_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct device_node *tcsr_node;
const struct of_device_id *match;
struct resource *res;
void __iomem *base;
struct gsbi_info *gsbi;
int i;
u32 mask, gsbi_num;
const struct crci_config *config = NULL;
gsbi = devm_kzalloc(&pdev->dev, sizeof(*gsbi), GFP_KERNEL);
if (!gsbi)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
gsbi->tcsr = syscon_regmap_lookup_by_phandle(node, "syscon-tcsr");
if (!IS_ERR(gsbi->tcsr)) {
tcsr_node = of_parse_phandle(node, "syscon-tcsr", 0);
if (tcsr_node) {
match = of_match_node(tcsr_dt_match, tcsr_node);
if (match)
config = match->data;
else
dev_warn(&pdev->dev, "no matching TCSR\n");
of_node_put(tcsr_node);
}
}
if (of_property_read_u32(node, "cell-index", &gsbi_num)) {
dev_err(&pdev->dev, "missing cell-index\n");
return -EINVAL;
}
if (gsbi_num < 1 || gsbi_num > MAX_GSBI) {
dev_err(&pdev->dev, "invalid cell-index\n");
return -EINVAL;
}
if (of_property_read_u32(node, "qcom,mode", &gsbi->mode)) {
dev_err(&pdev->dev, "missing mode configuration\n");
return -EINVAL;
}
of_property_read_u32(node, "qcom,crci", &gsbi->crci);
dev_info(&pdev->dev, "GSBI port protocol: %d crci: %d\n",
gsbi->mode, gsbi->crci);
gsbi->hclk = devm_clk_get(&pdev->dev, "iface");
if (IS_ERR(gsbi->hclk))
return PTR_ERR(gsbi->hclk);
clk_prepare_enable(gsbi->hclk);
writel_relaxed((gsbi->mode << GSBI_PROTOCOL_SHIFT) | gsbi->crci,
base + GSBI_CTRL_REG);
if (config) {
for (i = 0; i < config->num_rows; i++) {
mask = config->array[i][gsbi_num - 1];
if (gsbi->mode == GSBI_PROT_SPI)
regmap_update_bits(gsbi->tcsr,
TCSR_ADM_CRCI_BASE + 4 * i, mask, 0);
else
regmap_update_bits(gsbi->tcsr,
TCSR_ADM_CRCI_BASE + 4 * i, mask, mask);
}
}
wmb();
platform_set_drvdata(pdev, gsbi);
return of_platform_populate(node, NULL, NULL, &pdev->dev);
}
static int gsbi_remove(struct platform_device *pdev)
{
struct gsbi_info *gsbi = platform_get_drvdata(pdev);
clk_disable_unprepare(gsbi->hclk);
return 0;
}
