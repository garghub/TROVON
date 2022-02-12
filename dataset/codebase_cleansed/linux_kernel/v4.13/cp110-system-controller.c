static int cp110_gate_enable(struct clk_hw *hw)
{
struct cp110_gate_clk *gate = to_cp110_gate_clk(hw);
regmap_update_bits(gate->regmap, CP110_PM_CLOCK_GATING_REG,
BIT(gate->bit_idx), BIT(gate->bit_idx));
return 0;
}
static void cp110_gate_disable(struct clk_hw *hw)
{
struct cp110_gate_clk *gate = to_cp110_gate_clk(hw);
regmap_update_bits(gate->regmap, CP110_PM_CLOCK_GATING_REG,
BIT(gate->bit_idx), 0);
}
static int cp110_gate_is_enabled(struct clk_hw *hw)
{
struct cp110_gate_clk *gate = to_cp110_gate_clk(hw);
u32 val;
regmap_read(gate->regmap, CP110_PM_CLOCK_GATING_REG, &val);
return val & BIT(gate->bit_idx);
}
static struct clk_hw *cp110_register_gate(const char *name,
const char *parent_name,
struct regmap *regmap, u8 bit_idx)
{
struct cp110_gate_clk *gate;
struct clk_hw *hw;
struct clk_init_data init;
int ret;
gate = kzalloc(sizeof(*gate), GFP_KERNEL);
if (!gate)
return ERR_PTR(-ENOMEM);
memset(&init, 0, sizeof(init));
init.name = name;
init.ops = &cp110_gate_ops;
init.parent_names = &parent_name;
init.num_parents = 1;
gate->regmap = regmap;
gate->bit_idx = bit_idx;
gate->hw.init = &init;
hw = &gate->hw;
ret = clk_hw_register(NULL, hw);
if (ret) {
kfree(gate);
hw = ERR_PTR(ret);
}
return hw;
}
static void cp110_unregister_gate(struct clk_hw *hw)
{
clk_hw_unregister(hw);
kfree(to_cp110_gate_clk(hw));
}
static struct clk_hw *cp110_of_clk_get(struct of_phandle_args *clkspec,
void *data)
{
struct clk_hw_onecell_data *clk_data = data;
unsigned int type = clkspec->args[0];
unsigned int idx = clkspec->args[1];
if (type == CP110_CLK_TYPE_CORE) {
if (idx > CP110_MAX_CORE_CLOCKS)
return ERR_PTR(-EINVAL);
return clk_data->hws[idx];
} else if (type == CP110_CLK_TYPE_GATABLE) {
if (idx > CP110_MAX_GATABLE_CLOCKS)
return ERR_PTR(-EINVAL);
return clk_data->hws[CP110_MAX_CORE_CLOCKS + idx];
}
return ERR_PTR(-EINVAL);
}
static char *cp110_unique_name(struct device *dev, struct device_node *np,
const char *name)
{
const __be32 *reg;
u64 addr;
if (!name)
return NULL;
reg = of_get_property(np, "reg", NULL);
addr = of_translate_address(np, reg);
return devm_kasprintf(dev, GFP_KERNEL, "%llx-%s",
(unsigned long long)addr, name);
}
static int cp110_syscon_common_probe(struct platform_device *pdev,
struct device_node *syscon_node)
{
struct regmap *regmap;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
const char *ppv2_name, *apll_name, *core_name, *eip_name, *nand_name,
*sdio_name;
struct clk_hw_onecell_data *cp110_clk_data;
struct clk_hw *hw, **cp110_clks;
u32 nand_clk_ctrl;
int i, ret;
char *gate_name[ARRAY_SIZE(gate_base_names)];
regmap = syscon_node_to_regmap(syscon_node);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
ret = regmap_read(regmap, CP110_NAND_FLASH_CLK_CTRL_REG,
&nand_clk_ctrl);
if (ret)
return ret;
cp110_clk_data = devm_kzalloc(dev, sizeof(*cp110_clk_data) +
sizeof(struct clk_hw *) * CP110_CLK_NUM,
GFP_KERNEL);
if (!cp110_clk_data)
return -ENOMEM;
cp110_clks = cp110_clk_data->hws;
cp110_clk_data->num = CP110_CLK_NUM;
apll_name = cp110_unique_name(dev, syscon_node, "apll");
hw = clk_hw_register_fixed_rate(NULL, apll_name, NULL, 0,
1000 * 1000 * 1000);
if (IS_ERR(hw)) {
ret = PTR_ERR(hw);
goto fail_apll;
}
cp110_clks[CP110_CORE_APLL] = hw;
ppv2_name = cp110_unique_name(dev, syscon_node, "ppv2-core");
hw = clk_hw_register_fixed_factor(NULL, ppv2_name, apll_name, 0, 1, 3);
if (IS_ERR(hw)) {
ret = PTR_ERR(hw);
goto fail_ppv2;
}
cp110_clks[CP110_CORE_PPV2] = hw;
eip_name = cp110_unique_name(dev, syscon_node, "eip");
hw = clk_hw_register_fixed_factor(NULL, eip_name, apll_name, 0, 1, 2);
if (IS_ERR(hw)) {
ret = PTR_ERR(hw);
goto fail_eip;
}
cp110_clks[CP110_CORE_EIP] = hw;
core_name = cp110_unique_name(dev, syscon_node, "core");
hw = clk_hw_register_fixed_factor(NULL, core_name, eip_name, 0, 1, 2);
if (IS_ERR(hw)) {
ret = PTR_ERR(hw);
goto fail_core;
}
cp110_clks[CP110_CORE_CORE] = hw;
nand_name = cp110_unique_name(dev, syscon_node, "nand-core");
if (nand_clk_ctrl & NF_CLOCK_SEL_400_MASK)
hw = clk_hw_register_fixed_factor(NULL, nand_name,
apll_name, 0, 2, 5);
else
hw = clk_hw_register_fixed_factor(NULL, nand_name,
core_name, 0, 1, 1);
if (IS_ERR(hw)) {
ret = PTR_ERR(hw);
goto fail_nand;
}
cp110_clks[CP110_CORE_NAND] = hw;
sdio_name = cp110_unique_name(dev, syscon_node, "sdio-core");
hw = clk_hw_register_fixed_factor(NULL, sdio_name,
apll_name, 0, 2, 5);
if (IS_ERR(hw)) {
ret = PTR_ERR(hw);
goto fail_sdio;
}
cp110_clks[CP110_CORE_SDIO] = hw;
for (i = 0; i < ARRAY_SIZE(gate_base_names); i++)
gate_name[i] = cp110_unique_name(dev, syscon_node,
gate_base_names[i]);
for (i = 0; i < ARRAY_SIZE(gate_base_names); i++) {
const char *parent;
if (gate_name[i] == NULL)
continue;
switch (i) {
case CP110_GATE_AUDIO:
case CP110_GATE_COMM_UNIT:
case CP110_GATE_EIP150:
case CP110_GATE_EIP197:
case CP110_GATE_SLOW_IO:
parent = gate_name[CP110_GATE_MAIN];
break;
case CP110_GATE_MG:
parent = gate_name[CP110_GATE_MG_CORE];
break;
case CP110_GATE_NAND:
parent = nand_name;
break;
case CP110_GATE_PPV2:
parent = ppv2_name;
break;
case CP110_GATE_SDIO:
parent = sdio_name;
break;
case CP110_GATE_GOP_DP:
parent = gate_name[CP110_GATE_SDMMC_GOP];
break;
case CP110_GATE_XOR1:
case CP110_GATE_XOR0:
case CP110_GATE_PCIE_X1_0:
case CP110_GATE_PCIE_X1_1:
case CP110_GATE_PCIE_X4:
parent = gate_name[CP110_GATE_PCIE_XOR];
break;
case CP110_GATE_SATA:
case CP110_GATE_USB3H0:
case CP110_GATE_USB3H1:
case CP110_GATE_USB3DEV:
parent = gate_name[CP110_GATE_SATA_USB];
break;
default:
parent = core_name;
break;
}
hw = cp110_register_gate(gate_name[i], parent, regmap, i);
if (IS_ERR(hw)) {
ret = PTR_ERR(hw);
goto fail_gate;
}
cp110_clks[CP110_MAX_CORE_CLOCKS + i] = hw;
}
ret = of_clk_add_hw_provider(np, cp110_of_clk_get, cp110_clk_data);
if (ret)
goto fail_clk_add;
platform_set_drvdata(pdev, cp110_clks);
return 0;
fail_clk_add:
fail_gate:
for (i = 0; i < CP110_MAX_GATABLE_CLOCKS; i++) {
hw = cp110_clks[CP110_MAX_CORE_CLOCKS + i];
if (hw)
cp110_unregister_gate(hw);
}
clk_hw_unregister_fixed_factor(cp110_clks[CP110_CORE_SDIO]);
fail_sdio:
clk_hw_unregister_fixed_factor(cp110_clks[CP110_CORE_NAND]);
fail_nand:
clk_hw_unregister_fixed_factor(cp110_clks[CP110_CORE_CORE]);
fail_core:
clk_hw_unregister_fixed_factor(cp110_clks[CP110_CORE_EIP]);
fail_eip:
clk_hw_unregister_fixed_factor(cp110_clks[CP110_CORE_PPV2]);
fail_ppv2:
clk_hw_unregister_fixed_rate(cp110_clks[CP110_CORE_APLL]);
fail_apll:
return ret;
}
static int cp110_syscon_legacy_clk_probe(struct platform_device *pdev)
{
dev_warn(&pdev->dev, FW_WARN "Using legacy device tree binding\n");
dev_warn(&pdev->dev, FW_WARN "Update your device tree:\n");
dev_warn(&pdev->dev, FW_WARN
"This binding won't be supported in future kernels\n");
return cp110_syscon_common_probe(pdev, pdev->dev.of_node);
}
static int cp110_clk_probe(struct platform_device *pdev)
{
return cp110_syscon_common_probe(pdev, pdev->dev.of_node->parent);
}
