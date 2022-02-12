static int pm8941_wled_update_status(struct backlight_device *bl)
{
struct pm8941_wled *wled = bl_get_data(bl);
u16 val = bl->props.brightness;
u8 ctrl = 0;
int rc;
int i;
if (bl->props.power != FB_BLANK_UNBLANK ||
bl->props.fb_blank != FB_BLANK_UNBLANK ||
bl->props.state & BL_CORE_FBBLANK)
val = 0;
if (val != 0)
ctrl = PM8941_WLED_REG_MOD_EN_BIT;
rc = regmap_update_bits(wled->regmap,
wled->addr + PM8941_WLED_REG_MOD_EN,
PM8941_WLED_REG_MOD_EN_MASK, ctrl);
if (rc)
return rc;
for (i = 0; i < wled->cfg.num_strings; ++i) {
u8 v[2] = { val & 0xff, (val >> 8) & 0xf };
rc = regmap_bulk_write(wled->regmap,
wled->addr + PM8941_WLED_REG_VAL_BASE + 2 * i,
v, 2);
if (rc)
return rc;
}
rc = regmap_update_bits(wled->regmap,
wled->addr + PM8941_WLED_REG_SYNC,
PM8941_WLED_REG_SYNC_MASK, PM8941_WLED_REG_SYNC_ALL);
if (rc)
return rc;
rc = regmap_update_bits(wled->regmap,
wled->addr + PM8941_WLED_REG_SYNC,
PM8941_WLED_REG_SYNC_MASK, PM8941_WLED_REG_SYNC_CLEAR);
return rc;
}
static int pm8941_wled_setup(struct pm8941_wled *wled)
{
int rc;
int i;
rc = regmap_update_bits(wled->regmap,
wled->addr + PM8941_WLED_REG_OVP,
PM8941_WLED_REG_OVP_MASK, wled->cfg.ovp);
if (rc)
return rc;
rc = regmap_update_bits(wled->regmap,
wled->addr + PM8941_WLED_REG_BOOST,
PM8941_WLED_REG_BOOST_MASK, wled->cfg.i_boost_limit);
if (rc)
return rc;
rc = regmap_update_bits(wled->regmap,
wled->addr + PM8941_WLED_REG_FREQ,
PM8941_WLED_REG_FREQ_MASK, wled->cfg.switch_freq);
if (rc)
return rc;
if (wled->cfg.cs_out_en) {
u8 all = (BIT(wled->cfg.num_strings) - 1)
<< PM8941_WLED_REG_SINK_SHFT;
rc = regmap_update_bits(wled->regmap,
wled->addr + PM8941_WLED_REG_SINK,
PM8941_WLED_REG_SINK_MASK, all);
if (rc)
return rc;
}
for (i = 0; i < wled->cfg.num_strings; ++i) {
u16 addr = wled->addr + PM8941_WLED_REG_STR_OFFSET * i;
rc = regmap_update_bits(wled->regmap,
addr + PM8941_WLED_REG_STR_MOD_EN_BASE,
PM8941_WLED_REG_STR_MOD_MASK,
PM8941_WLED_REG_STR_MOD_EN);
if (rc)
return rc;
if (wled->cfg.ext_gen) {
rc = regmap_update_bits(wled->regmap,
addr + PM8941_WLED_REG_STR_MOD_SRC_BASE,
PM8941_WLED_REG_STR_MOD_SRC_MASK,
PM8941_WLED_REG_STR_MOD_SRC_EXT);
if (rc)
return rc;
}
rc = regmap_update_bits(wled->regmap,
addr + PM8941_WLED_REG_STR_SCALE_BASE,
PM8941_WLED_REG_STR_SCALE_MASK,
wled->cfg.i_limit);
if (rc)
return rc;
rc = regmap_update_bits(wled->regmap,
addr + PM8941_WLED_REG_STR_CABC_BASE,
PM8941_WLED_REG_STR_CABC_MASK,
wled->cfg.cabc_en ?
PM8941_WLED_REG_STR_CABC_EN : 0);
if (rc)
return rc;
}
return 0;
}
static u32 pm8941_wled_num_strings_values_fn(u32 idx)
{
return idx + 1;
}
static u32 pm8941_wled_switch_freq_values_fn(u32 idx)
{
return 19200 / (2 * (1 + idx));
}
static u32 pm8941_wled_values(const struct pm8941_wled_var_cfg *cfg, u32 idx)
{
if (idx >= cfg->size)
return UINT_MAX;
if (cfg->fn)
return cfg->fn(idx);
if (cfg->values)
return cfg->values[idx];
return idx;
}
static int pm8941_wled_configure(struct pm8941_wled *wled, struct device *dev)
{
struct pm8941_wled_config *cfg = &wled->cfg;
u32 val;
int rc;
u32 c;
int i;
int j;
const struct {
const char *name;
u32 *val_ptr;
const struct pm8941_wled_var_cfg *cfg;
} u32_opts[] = {
{
"qcom,current-boost-limit",
&cfg->i_boost_limit,
.cfg = &pm8941_wled_i_boost_limit_cfg,
},
{
"qcom,current-limit",
&cfg->i_limit,
.cfg = &pm8941_wled_i_limit_cfg,
},
{
"qcom,ovp",
&cfg->ovp,
.cfg = &pm8941_wled_ovp_cfg,
},
{
"qcom,switching-freq",
&cfg->switch_freq,
.cfg = &pm8941_wled_switch_freq_cfg,
},
{
"qcom,num-strings",
&cfg->num_strings,
.cfg = &pm8941_wled_num_strings_cfg,
},
};
const struct {
const char *name;
bool *val_ptr;
} bool_opts[] = {
{ "qcom,cs-out", &cfg->cs_out_en, },
{ "qcom,ext-gen", &cfg->ext_gen, },
{ "qcom,cabc", &cfg->cabc_en, },
};
rc = of_property_read_u32(dev->of_node, "reg", &val);
if (rc || val > 0xffff) {
dev_err(dev, "invalid IO resources\n");
return rc ? rc : -EINVAL;
}
wled->addr = val;
rc = of_property_read_string(dev->of_node, "label", &wled->name);
if (rc)
wled->name = dev->of_node->name;
*cfg = pm8941_wled_config_defaults;
for (i = 0; i < ARRAY_SIZE(u32_opts); ++i) {
rc = of_property_read_u32(dev->of_node, u32_opts[i].name, &val);
if (rc == -EINVAL) {
continue;
} else if (rc) {
dev_err(dev, "error reading '%s'\n", u32_opts[i].name);
return rc;
}
c = UINT_MAX;
for (j = 0; c != val; j++) {
c = pm8941_wled_values(u32_opts[i].cfg, j);
if (c == UINT_MAX) {
dev_err(dev, "invalid value for '%s'\n",
u32_opts[i].name);
return -EINVAL;
}
}
dev_dbg(dev, "'%s' = %u\n", u32_opts[i].name, c);
*u32_opts[i].val_ptr = j;
}
for (i = 0; i < ARRAY_SIZE(bool_opts); ++i) {
if (of_property_read_bool(dev->of_node, bool_opts[i].name))
*bool_opts[i].val_ptr = true;
}
cfg->num_strings = cfg->num_strings + 1;
return 0;
}
static int pm8941_wled_probe(struct platform_device *pdev)
{
struct backlight_properties props;
struct backlight_device *bl;
struct pm8941_wled *wled;
struct regmap *regmap;
u32 val;
int rc;
regmap = dev_get_regmap(pdev->dev.parent, NULL);
if (!regmap) {
dev_err(&pdev->dev, "Unable to get regmap\n");
return -EINVAL;
}
wled = devm_kzalloc(&pdev->dev, sizeof(*wled), GFP_KERNEL);
if (!wled)
return -ENOMEM;
wled->regmap = regmap;
rc = pm8941_wled_configure(wled, &pdev->dev);
if (rc)
return rc;
rc = pm8941_wled_setup(wled);
if (rc)
return rc;
val = PM8941_WLED_DEFAULT_BRIGHTNESS;
of_property_read_u32(pdev->dev.of_node, "default-brightness", &val);
memset(&props, 0, sizeof(struct backlight_properties));
props.type = BACKLIGHT_RAW;
props.brightness = val;
props.max_brightness = PM8941_WLED_REG_VAL_MAX;
bl = devm_backlight_device_register(&pdev->dev, wled->name,
&pdev->dev, wled,
&pm8941_wled_ops, &props);
return PTR_ERR_OR_ZERO(bl);
}
