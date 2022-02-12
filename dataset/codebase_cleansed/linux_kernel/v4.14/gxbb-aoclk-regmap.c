static int aoclk_gate_regmap_enable(struct clk_hw *hw)
{
struct aoclk_gate_regmap *gate = to_aoclk_gate_regmap(hw);
return regmap_update_bits(gate->regmap, AO_RTI_GEN_CNTL_REG0,
BIT(gate->bit_idx), BIT(gate->bit_idx));
}
static void aoclk_gate_regmap_disable(struct clk_hw *hw)
{
struct aoclk_gate_regmap *gate = to_aoclk_gate_regmap(hw);
regmap_update_bits(gate->regmap, AO_RTI_GEN_CNTL_REG0,
BIT(gate->bit_idx), 0);
}
static int aoclk_gate_regmap_is_enabled(struct clk_hw *hw)
{
struct aoclk_gate_regmap *gate = to_aoclk_gate_regmap(hw);
unsigned int val;
int ret;
ret = regmap_read(gate->regmap, AO_RTI_GEN_CNTL_REG0, &val);
if (ret)
return ret;
return (val & BIT(gate->bit_idx)) != 0;
}
