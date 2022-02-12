static void at91sam9_ebi_get_config(struct at91_ebi_dev *ebid,
struct at91_ebi_dev_config *conf)
{
struct at91sam9_smc_generic_fields *fields = &ebid->ebi->sam9;
unsigned int clk_period = NSEC_PER_SEC / clk_get_rate(ebid->ebi->clk);
struct at91sam9_ebi_dev_config *config = &conf->sam9;
struct at91sam9_smc_timings *timings = &config->timings;
unsigned int val;
regmap_fields_read(fields->mode, conf->cs, &val);
config->mode = val & ~AT91_SMC_TDF;
val = (val & AT91_SMC_TDF) >> 16;
timings->tdf_ns = clk_period * val;
regmap_fields_read(fields->setup, conf->cs, &val);
timings->ncs_rd_setup_ns = (val >> 24) & 0x1f;
timings->ncs_rd_setup_ns += ((val >> 29) & 0x1) * 128;
timings->ncs_rd_setup_ns *= clk_period;
timings->nrd_setup_ns = (val >> 16) & 0x1f;
timings->nrd_setup_ns += ((val >> 21) & 0x1) * 128;
timings->nrd_setup_ns *= clk_period;
timings->ncs_wr_setup_ns = (val >> 8) & 0x1f;
timings->ncs_wr_setup_ns += ((val >> 13) & 0x1) * 128;
timings->ncs_wr_setup_ns *= clk_period;
timings->nwe_setup_ns = val & 0x1f;
timings->nwe_setup_ns += ((val >> 5) & 0x1) * 128;
timings->nwe_setup_ns *= clk_period;
regmap_fields_read(fields->pulse, conf->cs, &val);
timings->ncs_rd_pulse_ns = (val >> 24) & 0x3f;
timings->ncs_rd_pulse_ns += ((val >> 30) & 0x1) * 256;
timings->ncs_rd_pulse_ns *= clk_period;
timings->nrd_pulse_ns = (val >> 16) & 0x3f;
timings->nrd_pulse_ns += ((val >> 22) & 0x1) * 256;
timings->nrd_pulse_ns *= clk_period;
timings->ncs_wr_pulse_ns = (val >> 8) & 0x3f;
timings->ncs_wr_pulse_ns += ((val >> 14) & 0x1) * 256;
timings->ncs_wr_pulse_ns *= clk_period;
timings->nwe_pulse_ns = val & 0x3f;
timings->nwe_pulse_ns += ((val >> 6) & 0x1) * 256;
timings->nwe_pulse_ns *= clk_period;
regmap_fields_read(fields->cycle, conf->cs, &val);
timings->nrd_cycle_ns = (val >> 16) & 0x7f;
timings->nrd_cycle_ns += ((val >> 23) & 0x3) * 256;
timings->nrd_cycle_ns *= clk_period;
timings->nwe_cycle_ns = val & 0x7f;
timings->nwe_cycle_ns += ((val >> 7) & 0x3) * 256;
timings->nwe_cycle_ns *= clk_period;
}
static int at91_xlate_timing(struct device_node *np, const char *prop,
u32 *val, bool *required)
{
if (!of_property_read_u32(np, prop, val)) {
*required = true;
return 0;
}
if (*required)
return -EINVAL;
return 0;
}
static int at91sam9_smc_xslate_timings(struct at91_ebi_dev *ebid,
struct device_node *np,
struct at91sam9_smc_timings *timings,
bool *required)
{
int ret;
ret = at91_xlate_timing(np, "atmel,smc-ncs-rd-setup-ns",
&timings->ncs_rd_setup_ns, required);
if (ret)
goto out;
ret = at91_xlate_timing(np, "atmel,smc-nrd-setup-ns",
&timings->nrd_setup_ns, required);
if (ret)
goto out;
ret = at91_xlate_timing(np, "atmel,smc-ncs-wr-setup-ns",
&timings->ncs_wr_setup_ns, required);
if (ret)
goto out;
ret = at91_xlate_timing(np, "atmel,smc-nwe-setup-ns",
&timings->nwe_setup_ns, required);
if (ret)
goto out;
ret = at91_xlate_timing(np, "atmel,smc-ncs-rd-pulse-ns",
&timings->ncs_rd_pulse_ns, required);
if (ret)
goto out;
ret = at91_xlate_timing(np, "atmel,smc-nrd-pulse-ns",
&timings->nrd_pulse_ns, required);
if (ret)
goto out;
ret = at91_xlate_timing(np, "atmel,smc-ncs-wr-pulse-ns",
&timings->ncs_wr_pulse_ns, required);
if (ret)
goto out;
ret = at91_xlate_timing(np, "atmel,smc-nwe-pulse-ns",
&timings->nwe_pulse_ns, required);
if (ret)
goto out;
ret = at91_xlate_timing(np, "atmel,smc-nwe-cycle-ns",
&timings->nwe_cycle_ns, required);
if (ret)
goto out;
ret = at91_xlate_timing(np, "atmel,smc-nrd-cycle-ns",
&timings->nrd_cycle_ns, required);
if (ret)
goto out;
ret = at91_xlate_timing(np, "atmel,smc-tdf-ns",
&timings->tdf_ns, required);
out:
if (ret)
dev_err(ebid->ebi->dev,
"missing or invalid timings definition in %s",
np->full_name);
return ret;
}
static int at91sam9_ebi_xslate_config(struct at91_ebi_dev *ebid,
struct device_node *np,
struct at91_ebi_dev_config *conf)
{
struct at91sam9_ebi_dev_config *config = &conf->sam9;
bool required = false;
const char *tmp_str;
u32 tmp;
int ret;
ret = of_property_read_u32(np, "atmel,smc-bus-width", &tmp);
if (!ret) {
switch (tmp) {
case 8:
config->mode |= AT91_SMC_DBW_8;
break;
case 16:
config->mode |= AT91_SMC_DBW_16;
break;
case 32:
config->mode |= AT91_SMC_DBW_32;
break;
default:
return -EINVAL;
}
required = true;
}
if (of_property_read_bool(np, "atmel,smc-tdf-optimized")) {
config->mode |= AT91_SMC_TDFMODE_OPTIMIZED;
required = true;
}
tmp_str = NULL;
of_property_read_string(np, "atmel,smc-byte-access-type", &tmp_str);
if (tmp_str && !strcmp(tmp_str, "write")) {
config->mode |= AT91_SMC_BAT_WRITE;
required = true;
}
tmp_str = NULL;
of_property_read_string(np, "atmel,smc-read-mode", &tmp_str);
if (tmp_str && !strcmp(tmp_str, "nrd")) {
config->mode |= AT91_SMC_READMODE_NRD;
required = true;
}
tmp_str = NULL;
of_property_read_string(np, "atmel,smc-write-mode", &tmp_str);
if (tmp_str && !strcmp(tmp_str, "nwe")) {
config->mode |= AT91_SMC_WRITEMODE_NWE;
required = true;
}
tmp_str = NULL;
of_property_read_string(np, "atmel,smc-exnw-mode", &tmp_str);
if (tmp_str) {
if (!strcmp(tmp_str, "frozen"))
config->mode |= AT91_SMC_EXNWMODE_FROZEN;
else if (!strcmp(tmp_str, "ready"))
config->mode |= AT91_SMC_EXNWMODE_READY;
else if (strcmp(tmp_str, "disabled"))
return -EINVAL;
required = true;
}
ret = of_property_read_u32(np, "atmel,smc-page-mode", &tmp);
if (!ret) {
switch (tmp) {
case 4:
config->mode |= AT91_SMC_PS_4;
break;
case 8:
config->mode |= AT91_SMC_PS_8;
break;
case 16:
config->mode |= AT91_SMC_PS_16;
break;
case 32:
config->mode |= AT91_SMC_PS_32;
break;
default:
return -EINVAL;
}
config->mode |= AT91_SMC_PMEN;
required = true;
}
ret = at91sam9_smc_xslate_timings(ebid, np, &config->timings,
&required);
if (ret)
return ret;
return required;
}
static int at91sam9_ebi_apply_config(struct at91_ebi_dev *ebid,
struct at91_ebi_dev_config *conf)
{
unsigned int clk_rate = clk_get_rate(ebid->ebi->clk);
unsigned int clk_period = NSEC_PER_SEC / clk_rate;
struct at91sam9_ebi_dev_config *config = &conf->sam9;
struct at91sam9_smc_timings *timings = &config->timings;
struct at91sam9_smc_generic_fields *fields = &ebid->ebi->sam9;
u32 coded_val;
u32 val;
coded_val = at91sam9_smc_setup_ns_to_cycles(clk_rate,
timings->ncs_rd_setup_ns);
val = AT91SAM9_SMC_NCS_NRDSETUP(coded_val);
coded_val = at91sam9_smc_setup_ns_to_cycles(clk_rate,
timings->nrd_setup_ns);
val |= AT91SAM9_SMC_NRDSETUP(coded_val);
coded_val = at91sam9_smc_setup_ns_to_cycles(clk_rate,
timings->ncs_wr_setup_ns);
val |= AT91SAM9_SMC_NCS_WRSETUP(coded_val);
coded_val = at91sam9_smc_setup_ns_to_cycles(clk_rate,
timings->nwe_setup_ns);
val |= AT91SAM9_SMC_NWESETUP(coded_val);
regmap_fields_write(fields->setup, conf->cs, val);
coded_val = at91sam9_smc_pulse_ns_to_cycles(clk_rate,
timings->ncs_rd_pulse_ns);
val = AT91SAM9_SMC_NCS_NRDPULSE(coded_val);
coded_val = at91sam9_smc_pulse_ns_to_cycles(clk_rate,
timings->nrd_pulse_ns);
val |= AT91SAM9_SMC_NRDPULSE(coded_val);
coded_val = at91sam9_smc_pulse_ns_to_cycles(clk_rate,
timings->ncs_wr_pulse_ns);
val |= AT91SAM9_SMC_NCS_WRPULSE(coded_val);
coded_val = at91sam9_smc_pulse_ns_to_cycles(clk_rate,
timings->nwe_pulse_ns);
val |= AT91SAM9_SMC_NWEPULSE(coded_val);
regmap_fields_write(fields->pulse, conf->cs, val);
coded_val = at91sam9_smc_cycle_ns_to_cycles(clk_rate,
timings->nrd_cycle_ns);
val = AT91SAM9_SMC_NRDCYCLE(coded_val);
coded_val = at91sam9_smc_cycle_ns_to_cycles(clk_rate,
timings->nwe_cycle_ns);
val |= AT91SAM9_SMC_NWECYCLE(coded_val);
regmap_fields_write(fields->cycle, conf->cs, val);
val = DIV_ROUND_UP(timings->tdf_ns, clk_period);
if (val > AT91_SMC_TDF_MAX)
val = AT91_SMC_TDF_MAX;
regmap_fields_write(fields->mode, conf->cs,
config->mode | AT91_SMC_TDF_(val));
return 0;
}
static int at91sam9_ebi_init(struct at91_ebi *ebi)
{
struct at91sam9_smc_generic_fields *fields = &ebi->sam9;
struct reg_field field = REG_FIELD(0, 0, 31);
field.id_size = fls(ebi->caps->available_cs);
field.id_offset = AT91SAM9_SMC_GENERIC_BLK_SZ;
field.reg = AT91SAM9_SMC_SETUP(AT91SAM9_SMC_GENERIC);
fields->setup = devm_regmap_field_alloc(ebi->dev, ebi->smc.regmap,
field);
if (IS_ERR(fields->setup))
return PTR_ERR(fields->setup);
field.reg = AT91SAM9_SMC_PULSE(AT91SAM9_SMC_GENERIC);
fields->pulse = devm_regmap_field_alloc(ebi->dev, ebi->smc.regmap,
field);
if (IS_ERR(fields->pulse))
return PTR_ERR(fields->pulse);
field.reg = AT91SAM9_SMC_CYCLE(AT91SAM9_SMC_GENERIC);
fields->cycle = devm_regmap_field_alloc(ebi->dev, ebi->smc.regmap,
field);
if (IS_ERR(fields->cycle))
return PTR_ERR(fields->cycle);
field.reg = AT91SAM9_SMC_MODE(AT91SAM9_SMC_GENERIC);
fields->mode = devm_regmap_field_alloc(ebi->dev, ebi->smc.regmap,
field);
return PTR_ERR_OR_ZERO(fields->mode);
}
static int sama5d3_ebi_init(struct at91_ebi *ebi)
{
struct at91sam9_smc_generic_fields *fields = &ebi->sam9;
struct reg_field field = REG_FIELD(0, 0, 31);
field.id_size = fls(ebi->caps->available_cs);
field.id_offset = SAMA5_SMC_GENERIC_BLK_SZ;
field.reg = AT91SAM9_SMC_SETUP(SAMA5_SMC_GENERIC);
fields->setup = devm_regmap_field_alloc(ebi->dev, ebi->smc.regmap,
field);
if (IS_ERR(fields->setup))
return PTR_ERR(fields->setup);
field.reg = AT91SAM9_SMC_PULSE(SAMA5_SMC_GENERIC);
fields->pulse = devm_regmap_field_alloc(ebi->dev, ebi->smc.regmap,
field);
if (IS_ERR(fields->pulse))
return PTR_ERR(fields->pulse);
field.reg = AT91SAM9_SMC_CYCLE(SAMA5_SMC_GENERIC);
fields->cycle = devm_regmap_field_alloc(ebi->dev, ebi->smc.regmap,
field);
if (IS_ERR(fields->cycle))
return PTR_ERR(fields->cycle);
field.reg = SAMA5_SMC_MODE(SAMA5_SMC_GENERIC);
fields->mode = devm_regmap_field_alloc(ebi->dev, ebi->smc.regmap,
field);
return PTR_ERR_OR_ZERO(fields->mode);
}
static int at91_ebi_dev_setup(struct at91_ebi *ebi, struct device_node *np,
int reg_cells)
{
const struct at91_ebi_caps *caps = ebi->caps;
struct at91_ebi_dev_config conf = { };
struct device *dev = ebi->dev;
struct at91_ebi_dev *ebid;
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
dev_err(dev, "invalid reg property in %s\n",
np->full_name);
return -EINVAL;
}
if (!test_and_set_bit(cs, &cslines))
numcs++;
}
if (!numcs) {
dev_err(dev, "invalid reg property in %s\n", np->full_name);
return -EINVAL;
}
ebid = devm_kzalloc(ebi->dev,
sizeof(*ebid) + (numcs * sizeof(*ebid->configs)),
GFP_KERNEL);
if (!ebid)
return -ENOMEM;
ebid->ebi = ebi;
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
ret = caps->apply_config(ebid, &conf);
if (ret)
return ret;
}
caps->get_config(ebid, &ebid->configs[i]);
if (ebi->ebi_csa && apply)
regmap_field_update_bits(ebi->ebi_csa,
BIT(cs), 0);
i++;
}
list_add_tail(&ebid->node, &ebi->devs);
return 0;
}
static int at91_ebi_dev_disable(struct at91_ebi *ebi, struct device_node *np)
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
static int at91_ebi_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *child, *np = dev->of_node, *smc_np;
const struct of_device_id *match;
struct at91_ebi *ebi;
int ret, reg_cells;
struct clk *clk;
u32 val;
match = of_match_device(at91_ebi_id_table, dev);
if (!match || !match->data)
return -EINVAL;
ebi = devm_kzalloc(dev, sizeof(*ebi), GFP_KERNEL);
if (!ebi)
return -ENOMEM;
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
ebi->smc.clk = of_clk_get(smc_np, 0);
if (IS_ERR(ebi->smc.clk)) {
if (PTR_ERR(ebi->smc.clk) != -ENOENT)
return PTR_ERR(ebi->smc.clk);
ebi->smc.clk = NULL;
}
ret = clk_prepare_enable(ebi->smc.clk);
if (ret)
return ret;
if (ebi->caps->ebi_csa) {
ebi->matrix =
syscon_regmap_lookup_by_phandle(np, "atmel,matrix");
if (IS_ERR(ebi->matrix))
return PTR_ERR(ebi->matrix);
ebi->ebi_csa = regmap_field_alloc(ebi->matrix,
*ebi->caps->ebi_csa);
if (IS_ERR(ebi->ebi_csa))
return PTR_ERR(ebi->ebi_csa);
}
ret = ebi->caps->init(ebi);
if (ret)
return ret;
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
ret = at91_ebi_dev_setup(ebi, child, reg_cells);
if (ret) {
dev_err(dev, "failed to configure EBI bus for %s, disabling the device",
child->full_name);
ret = at91_ebi_dev_disable(ebi, child);
if (ret)
return ret;
}
}
return of_platform_populate(np, NULL, NULL, dev);
}
