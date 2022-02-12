static void at91sam9_ebi_get_config(struct atmel_ebi_dev *ebid,
struct atmel_ebi_dev_config *conf)
{
atmel_smc_cs_conf_get(ebid->ebi->smc.regmap, conf->cs,
&conf->smcconf);
}
static void sama5_ebi_get_config(struct atmel_ebi_dev *ebid,
struct atmel_ebi_dev_config *conf)
{
atmel_hsmc_cs_conf_get(ebid->ebi->smc.regmap, ebid->ebi->smc.layout,
conf->cs, &conf->smcconf);
}
static int atmel_ebi_xslate_smc_timings(struct atmel_ebi_dev *ebid,
struct device_node *np,
struct atmel_smc_cs_conf *smcconf)
{
unsigned int clk_rate = clk_get_rate(ebid->ebi->clk);
unsigned int clk_period_ns = NSEC_PER_SEC / clk_rate;
bool required = false;
unsigned int ncycles;
int ret, i;
u32 val;
ret = of_property_read_u32(np, "atmel,smc-tdf-ns", &val);
if (!ret) {
required = true;
ncycles = DIV_ROUND_UP(val, clk_period_ns);
if (ncycles > ATMEL_SMC_MODE_TDF_MAX) {
ret = -EINVAL;
goto out;
}
if (ncycles < ATMEL_SMC_MODE_TDF_MIN)
ncycles = ATMEL_SMC_MODE_TDF_MIN;
smcconf->mode |= ATMEL_SMC_MODE_TDF(ncycles);
}
for (i = 0; i < ARRAY_SIZE(timings_xlate_table); i++) {
const struct atmel_smc_timing_xlate *xlate;
xlate = &timings_xlate_table[i];
ret = of_property_read_u32(np, xlate->name, &val);
if (ret) {
if (!required)
continue;
else
break;
}
if (!required) {
ret = -EINVAL;
break;
}
ncycles = DIV_ROUND_UP(val, clk_period_ns);
ret = xlate->converter(smcconf, xlate->shift, ncycles);
if (ret)
goto out;
}
out:
if (ret) {
dev_err(ebid->ebi->dev,
"missing or invalid timings definition in %pOF",
np);
return ret;
}
return required;
}
static int atmel_ebi_xslate_smc_config(struct atmel_ebi_dev *ebid,
struct device_node *np,
struct atmel_ebi_dev_config *conf)
{
struct atmel_smc_cs_conf *smcconf = &conf->smcconf;
bool required = false;
const char *tmp_str;
u32 tmp;
int ret;
ret = of_property_read_u32(np, "atmel,smc-bus-width", &tmp);
if (!ret) {
switch (tmp) {
case 8:
smcconf->mode |= ATMEL_SMC_MODE_DBW_8;
break;
case 16:
smcconf->mode |= ATMEL_SMC_MODE_DBW_16;
break;
case 32:
smcconf->mode |= ATMEL_SMC_MODE_DBW_32;
break;
default:
return -EINVAL;
}
required = true;
}
if (of_property_read_bool(np, "atmel,smc-tdf-optimized")) {
smcconf->mode |= ATMEL_SMC_MODE_TDFMODE_OPTIMIZED;
required = true;
}
tmp_str = NULL;
of_property_read_string(np, "atmel,smc-byte-access-type", &tmp_str);
if (tmp_str && !strcmp(tmp_str, "write")) {
smcconf->mode |= ATMEL_SMC_MODE_BAT_WRITE;
required = true;
}
tmp_str = NULL;
of_property_read_string(np, "atmel,smc-read-mode", &tmp_str);
if (tmp_str && !strcmp(tmp_str, "nrd")) {
smcconf->mode |= ATMEL_SMC_MODE_READMODE_NRD;
required = true;
}
tmp_str = NULL;
of_property_read_string(np, "atmel,smc-write-mode", &tmp_str);
if (tmp_str && !strcmp(tmp_str, "nwe")) {
smcconf->mode |= ATMEL_SMC_MODE_WRITEMODE_NWE;
required = true;
}
tmp_str = NULL;
of_property_read_string(np, "atmel,smc-exnw-mode", &tmp_str);
if (tmp_str) {
if (!strcmp(tmp_str, "frozen"))
smcconf->mode |= ATMEL_SMC_MODE_EXNWMODE_FROZEN;
else if (!strcmp(tmp_str, "ready"))
smcconf->mode |= ATMEL_SMC_MODE_EXNWMODE_READY;
else if (strcmp(tmp_str, "disabled"))
return -EINVAL;
required = true;
}
ret = of_property_read_u32(np, "atmel,smc-page-mode", &tmp);
if (!ret) {
switch (tmp) {
case 4:
smcconf->mode |= ATMEL_SMC_MODE_PS_4;
break;
case 8:
smcconf->mode |= ATMEL_SMC_MODE_PS_8;
break;
case 16:
smcconf->mode |= ATMEL_SMC_MODE_PS_16;
break;
case 32:
smcconf->mode |= ATMEL_SMC_MODE_PS_32;
break;
default:
return -EINVAL;
}
smcconf->mode |= ATMEL_SMC_MODE_PMEN;
required = true;
}
ret = atmel_ebi_xslate_smc_timings(ebid, np, &conf->smcconf);
if (ret < 0)
return -EINVAL;
if ((ret > 0 && !required) || (!ret && required)) {
dev_err(ebid->ebi->dev, "missing atmel,smc- properties in %pOF",
np);
return -EINVAL;
}
return required;
}
static void at91sam9_ebi_apply_config(struct atmel_ebi_dev *ebid,
struct atmel_ebi_dev_config *conf)
{
atmel_smc_cs_conf_apply(ebid->ebi->smc.regmap, conf->cs,
&conf->smcconf);
}
static void sama5_ebi_apply_config(struct atmel_ebi_dev *ebid,
struct atmel_ebi_dev_config *conf)
{
atmel_hsmc_cs_conf_apply(ebid->ebi->smc.regmap, ebid->ebi->smc.layout,
conf->cs, &conf->smcconf);
}
static int atmel_ebi_dev_setup(struct atmel_ebi *ebi, struct device_node *np,
int reg_cells)
{
const struct atmel_ebi_caps *caps = ebi->caps;
struct atmel_ebi_dev_config conf = { };
struct device *dev = ebi->dev;
struct atmel_ebi_dev *ebid;
unsigned long cslines = 0;
int ret, numcs = 0, nentries, i;
bool apply = false;
u32 cs;
nentries = of_property_count_elems_of_size(np, "reg",
reg_cells * sizeof(u32));
for (i = 0; i < nentries; i++) {
ret = of_property_read_u32_index(np, "reg", i * reg_cells,
&cs);
if (ret)
return ret;
if (cs >= AT91_MATRIX_EBI_NUM_CS ||
!(ebi->caps->available_cs & BIT(cs))) {
dev_err(dev, "invalid reg property in %pOF\n", np);
return -EINVAL;
}
if (!test_and_set_bit(cs, &cslines))
numcs++;
}
if (!numcs) {
dev_err(dev, "invalid reg property in %pOF\n", np);
return -EINVAL;
}
ebid = devm_kzalloc(ebi->dev,
sizeof(*ebid) + (numcs * sizeof(*ebid->configs)),
GFP_KERNEL);
if (!ebid)
return -ENOMEM;
ebid->ebi = ebi;
ebid->numcs = numcs;
ret = caps->xlate_config(ebid, np, &conf);
if (ret < 0)
return ret;
else if (ret)
apply = true;
i = 0;
for_each_set_bit(cs, &cslines, AT91_MATRIX_EBI_NUM_CS) {
ebid->configs[i].cs = cs;
if (apply) {
conf.cs = cs;
caps->apply_config(ebid, &conf);
}
caps->get_config(ebid, &ebid->configs[i]);
if (ebi->caps->ebi_csa_offs && apply)
regmap_update_bits(ebi->matrix,
ebi->caps->ebi_csa_offs,
BIT(cs), 0);
i++;
}
list_add_tail(&ebid->node, &ebi->devs);
return 0;
}
static int atmel_ebi_dev_disable(struct atmel_ebi *ebi, struct device_node *np)
{
struct device *dev = ebi->dev;
struct property *newprop;
newprop = devm_kzalloc(dev, sizeof(*newprop), GFP_KERNEL);
if (!newprop)
return -ENOMEM;
newprop->name = devm_kstrdup(dev, "status", GFP_KERNEL);
if (!newprop->name)
return -ENOMEM;
newprop->value = devm_kstrdup(dev, "disabled", GFP_KERNEL);
if (!newprop->value)
return -ENOMEM;
newprop->length = sizeof("disabled");
return of_update_property(np, newprop);
}
static int atmel_ebi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *child, *np = dev->of_node, *smc_np;
const struct of_device_id *match;
struct atmel_ebi *ebi;
int ret, reg_cells;
struct clk *clk;
u32 val;
match = of_match_device(atmel_ebi_id_table, dev);
if (!match || !match->data)
return -EINVAL;
ebi = devm_kzalloc(dev, sizeof(*ebi), GFP_KERNEL);
if (!ebi)
return -ENOMEM;
platform_set_drvdata(pdev, ebi);
INIT_LIST_HEAD(&ebi->devs);
ebi->caps = match->data;
ebi->dev = dev;
clk = devm_clk_get(dev, NULL);
if (IS_ERR(clk))
return PTR_ERR(clk);
ebi->clk = clk;
smc_np = of_parse_phandle(dev->of_node, "atmel,smc", 0);
ebi->smc.regmap = syscon_node_to_regmap(smc_np);
if (IS_ERR(ebi->smc.regmap))
return PTR_ERR(ebi->smc.regmap);
ebi->smc.layout = atmel_hsmc_get_reg_layout(smc_np);
if (IS_ERR(ebi->smc.layout))
return PTR_ERR(ebi->smc.layout);
ebi->smc.clk = of_clk_get(smc_np, 0);
if (IS_ERR(ebi->smc.clk)) {
if (PTR_ERR(ebi->smc.clk) != -ENOENT)
return PTR_ERR(ebi->smc.clk);
ebi->smc.clk = NULL;
}
ret = clk_prepare_enable(ebi->smc.clk);
if (ret)
return ret;
if (ebi->caps->ebi_csa_offs) {
ebi->matrix =
syscon_regmap_lookup_by_phandle(np, "atmel,matrix");
if (IS_ERR(ebi->matrix))
return PTR_ERR(ebi->matrix);
}
ret = of_property_read_u32(np, "#address-cells", &val);
if (ret) {
dev_err(dev, "missing #address-cells property\n");
return ret;
}
reg_cells = val;
ret = of_property_read_u32(np, "#size-cells", &val);
if (ret) {
dev_err(dev, "missing #address-cells property\n");
return ret;
}
reg_cells += val;
for_each_available_child_of_node(np, child) {
if (!of_find_property(child, "reg", NULL))
continue;
ret = atmel_ebi_dev_setup(ebi, child, reg_cells);
if (ret) {
dev_err(dev, "failed to configure EBI bus for %pOF, disabling the device",
child);
ret = atmel_ebi_dev_disable(ebi, child);
if (ret)
return ret;
}
}
return of_platform_populate(np, NULL, NULL, dev);
}
static __maybe_unused int atmel_ebi_resume(struct device *dev)
{
struct atmel_ebi *ebi = dev_get_drvdata(dev);
struct atmel_ebi_dev *ebid;
list_for_each_entry(ebid, &ebi->devs, node) {
int i;
for (i = 0; i < ebid->numcs; i++)
ebid->ebi->caps->apply_config(ebid, &ebid->configs[i]);
}
return 0;
}
