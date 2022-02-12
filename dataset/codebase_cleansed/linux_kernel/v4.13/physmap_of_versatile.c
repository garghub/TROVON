static int ap_flash_init(struct platform_device *pdev)
{
struct device_node *ebi;
static void __iomem *ebi_base;
u32 val;
int ret;
ebi = of_find_matching_node(NULL, ebi_match);
if (!ebi) {
return -ENODEV;
}
ebi_base = of_iomap(ebi, 0);
if (!ebi_base)
return -ENODEV;
ret = regmap_write(syscon_regmap,
INTEGRATOR_SC_CTRLC_OFFSET,
INTEGRATOR_SC_CTRL_FLVPPEN | INTEGRATOR_SC_CTRL_FLWP);
if (ret)
dev_err(&pdev->dev, "error clearing Integrator VPP/WP\n");
writel(INTEGRATOR_EBI_LOCK_VAL, ebi_base + INTEGRATOR_EBI_LOCK_OFFSET);
val = readl(ebi_base + INTEGRATOR_EBI_CSR1_OFFSET);
val |= INTEGRATOR_EBI_WRITE_ENABLE;
writel(val, ebi_base + INTEGRATOR_EBI_CSR1_OFFSET);
writel(0, ebi_base + INTEGRATOR_EBI_LOCK_OFFSET);
iounmap(ebi_base);
return 0;
}
static void ap_flash_set_vpp(struct map_info *map, int on)
{
int ret;
if (on) {
ret = regmap_write(syscon_regmap,
INTEGRATOR_SC_CTRLS_OFFSET,
INTEGRATOR_SC_CTRL_FLVPPEN | INTEGRATOR_SC_CTRL_FLWP);
if (ret)
pr_err("error enabling AP VPP\n");
} else {
ret = regmap_write(syscon_regmap,
INTEGRATOR_SC_CTRLC_OFFSET,
INTEGRATOR_SC_CTRL_FLVPPEN | INTEGRATOR_SC_CTRL_FLWP);
if (ret)
pr_err("error disabling AP VPP\n");
}
}
static void cp_flash_set_vpp(struct map_info *map, int on)
{
int ret;
if (on) {
ret = regmap_update_bits(syscon_regmap,
INTCP_FLASHPROG_OFFSET,
CINTEGRATOR_FLMASK,
CINTEGRATOR_FLVPPEN | CINTEGRATOR_FLWREN);
if (ret)
pr_err("error setting CP VPP\n");
} else {
ret = regmap_update_bits(syscon_regmap,
INTCP_FLASHPROG_OFFSET,
CINTEGRATOR_FLMASK,
0);
if (ret)
pr_err("error setting CP VPP\n");
}
}
static void versatile_flash_set_vpp(struct map_info *map, int on)
{
int ret;
ret = regmap_update_bits(syscon_regmap, VERSATILE_SYS_FLASH_OFFSET,
0x01, !!on);
if (ret)
pr_err("error setting Versatile VPP\n");
}
int of_flash_probe_versatile(struct platform_device *pdev,
struct device_node *np,
struct map_info *map)
{
struct device_node *sysnp;
const struct of_device_id *devid;
struct regmap *rmap;
static enum versatile_flashprot versatile_flashprot;
int ret;
if (!of_device_is_compatible(np, "arm,versatile-flash"))
return 0;
if (!syscon_regmap) {
sysnp = of_find_matching_node_and_match(NULL,
syscon_match,
&devid);
if (!sysnp)
return -ENODEV;
versatile_flashprot = (enum versatile_flashprot)devid->data;
rmap = syscon_node_to_regmap(sysnp);
if (IS_ERR(rmap))
return PTR_ERR(rmap);
syscon_regmap = rmap;
}
switch (versatile_flashprot) {
case INTEGRATOR_AP_FLASHPROT:
ret = ap_flash_init(pdev);
if (ret)
return ret;
map->set_vpp = ap_flash_set_vpp;
dev_info(&pdev->dev, "Integrator/AP flash protection\n");
break;
case INTEGRATOR_CP_FLASHPROT:
map->set_vpp = cp_flash_set_vpp;
dev_info(&pdev->dev, "Integrator/CP flash protection\n");
break;
case VERSATILE_FLASHPROT:
case REALVIEW_FLASHPROT:
map->set_vpp = versatile_flash_set_vpp;
dev_info(&pdev->dev, "versatile/realview flash protection\n");
break;
default:
dev_info(&pdev->dev, "device marked as Versatile flash "
"but no system controller was found\n");
break;
}
return 0;
}
