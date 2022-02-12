static inline struct palmas_clock_info *to_palmas_clks_info(struct clk_hw *hw)
{
return container_of(hw, struct palmas_clock_info, hw);
}
static unsigned long palmas_clks_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return 32768;
}
static int palmas_clks_prepare(struct clk_hw *hw)
{
struct palmas_clock_info *cinfo = to_palmas_clks_info(hw);
int ret;
ret = palmas_update_bits(cinfo->palmas, PALMAS_RESOURCE_BASE,
cinfo->clk_desc->control_reg,
cinfo->clk_desc->enable_mask,
cinfo->clk_desc->enable_mask);
if (ret < 0)
dev_err(cinfo->dev, "Reg 0x%02x update failed, %d\n",
cinfo->clk_desc->control_reg, ret);
else if (cinfo->clk_desc->delay)
udelay(cinfo->clk_desc->delay);
return ret;
}
static void palmas_clks_unprepare(struct clk_hw *hw)
{
struct palmas_clock_info *cinfo = to_palmas_clks_info(hw);
int ret;
if (cinfo->ext_control_pin)
return;
ret = palmas_update_bits(cinfo->palmas, PALMAS_RESOURCE_BASE,
cinfo->clk_desc->control_reg,
cinfo->clk_desc->enable_mask, 0);
if (ret < 0)
dev_err(cinfo->dev, "Reg 0x%02x update failed, %d\n",
cinfo->clk_desc->control_reg, ret);
}
static int palmas_clks_is_prepared(struct clk_hw *hw)
{
struct palmas_clock_info *cinfo = to_palmas_clks_info(hw);
int ret;
u32 val;
if (cinfo->ext_control_pin)
return 1;
ret = palmas_read(cinfo->palmas, PALMAS_RESOURCE_BASE,
cinfo->clk_desc->control_reg, &val);
if (ret < 0) {
dev_err(cinfo->dev, "Reg 0x%02x read failed, %d\n",
cinfo->clk_desc->control_reg, ret);
return ret;
}
return !!(val & cinfo->clk_desc->enable_mask);
}
static void palmas_clks_get_clk_data(struct platform_device *pdev,
struct palmas_clock_info *cinfo)
{
struct device_node *node = pdev->dev.of_node;
unsigned int prop;
int ret;
ret = of_property_read_u32(node, "ti,external-sleep-control",
&prop);
if (ret)
return;
switch (prop) {
case PALMAS_CLOCK_DT_EXT_CONTROL_ENABLE1:
prop = PALMAS_EXT_CONTROL_ENABLE1;
break;
case PALMAS_CLOCK_DT_EXT_CONTROL_ENABLE2:
prop = PALMAS_EXT_CONTROL_ENABLE2;
break;
case PALMAS_CLOCK_DT_EXT_CONTROL_NSLEEP:
prop = PALMAS_EXT_CONTROL_NSLEEP;
break;
default:
dev_warn(&pdev->dev, "%s: Invalid ext control option: %u\n",
node->name, prop);
prop = 0;
break;
}
cinfo->ext_control_pin = prop;
}
static int palmas_clks_init_configure(struct palmas_clock_info *cinfo)
{
int ret;
ret = palmas_update_bits(cinfo->palmas, PALMAS_RESOURCE_BASE,
cinfo->clk_desc->control_reg,
cinfo->clk_desc->sleep_mask, 0);
if (ret < 0) {
dev_err(cinfo->dev, "Reg 0x%02x update failed, %d\n",
cinfo->clk_desc->control_reg, ret);
return ret;
}
if (cinfo->ext_control_pin) {
ret = clk_prepare(cinfo->hw.clk);
if (ret < 0) {
dev_err(cinfo->dev, "Clock prep failed, %d\n", ret);
return ret;
}
ret = palmas_ext_control_req_config(cinfo->palmas,
cinfo->clk_desc->sleep_reqstr_id,
cinfo->ext_control_pin, true);
if (ret < 0) {
dev_err(cinfo->dev, "Ext config for %s failed, %d\n",
cinfo->clk_desc->clk_name, ret);
return ret;
}
}
return ret;
}
static int palmas_clks_probe(struct platform_device *pdev)
{
struct palmas *palmas = dev_get_drvdata(pdev->dev.parent);
struct device_node *node = pdev->dev.of_node;
const struct palmas_clks_of_match_data *match_data;
struct palmas_clock_info *cinfo;
int ret;
match_data = of_device_get_match_data(&pdev->dev);
if (!match_data)
return 1;
cinfo = devm_kzalloc(&pdev->dev, sizeof(*cinfo), GFP_KERNEL);
if (!cinfo)
return -ENOMEM;
palmas_clks_get_clk_data(pdev, cinfo);
platform_set_drvdata(pdev, cinfo);
cinfo->dev = &pdev->dev;
cinfo->palmas = palmas;
cinfo->clk_desc = &match_data->desc;
cinfo->hw.init = &match_data->init;
ret = devm_clk_hw_register(&pdev->dev, &cinfo->hw);
if (ret) {
dev_err(&pdev->dev, "Fail to register clock %s, %d\n",
match_data->desc.clk_name, ret);
return ret;
}
ret = palmas_clks_init_configure(cinfo);
if (ret < 0) {
dev_err(&pdev->dev, "Clock config failed, %d\n", ret);
return ret;
}
ret = of_clk_add_hw_provider(node, of_clk_hw_simple_get, &cinfo->hw);
if (ret < 0)
dev_err(&pdev->dev, "Fail to add clock driver, %d\n", ret);
return ret;
}
static int palmas_clks_remove(struct platform_device *pdev)
{
of_clk_del_provider(pdev->dev.of_node);
return 0;
}
