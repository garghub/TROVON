static i40e_status i40e_diag_reg_pattern_test(struct i40e_hw *hw,
u32 reg, u32 mask)
{
const u32 patterns[] = {0x5A5A5A5A, 0xA5A5A5A5, 0x00000000, 0xFFFFFFFF};
u32 pat, val, orig_val;
int i;
orig_val = rd32(hw, reg);
for (i = 0; i < ARRAY_SIZE(patterns); i++) {
pat = patterns[i];
wr32(hw, reg, (pat & mask));
val = rd32(hw, reg);
if ((val & mask) != (pat & mask)) {
i40e_debug(hw, I40E_DEBUG_DIAG,
"%s: reg pattern test failed - reg 0x%08x pat 0x%08x val 0x%08x\n",
__func__, reg, pat, val);
return I40E_ERR_DIAG_TEST_FAILED;
}
}
wr32(hw, reg, orig_val);
val = rd32(hw, reg);
if (val != orig_val) {
i40e_debug(hw, I40E_DEBUG_DIAG,
"%s: reg restore test failed - reg 0x%08x orig_val 0x%08x val 0x%08x\n",
__func__, reg, orig_val, val);
return I40E_ERR_DIAG_TEST_FAILED;
}
return 0;
}
i40e_status i40e_diag_reg_test(struct i40e_hw *hw)
{
i40e_status ret_code = 0;
u32 reg, mask;
u32 i, j;
for (i = 0; (i40e_reg_list[i].offset != 0) && !ret_code; i++) {
mask = i40e_reg_list[i].mask;
for (j = 0; (j < i40e_reg_list[i].elements) && !ret_code; j++) {
reg = i40e_reg_list[i].offset +
(j * i40e_reg_list[i].stride);
ret_code = i40e_diag_reg_pattern_test(hw, reg, mask);
}
}
return ret_code;
}
i40e_status i40e_diag_eeprom_test(struct i40e_hw *hw)
{
i40e_status ret_code;
u16 reg_val;
ret_code = i40e_read_nvm_word(hw, I40E_SR_NVM_CONTROL_WORD, &reg_val);
if ((!ret_code) &&
((reg_val & I40E_SR_CONTROL_WORD_1_MASK) ==
(0x01 << I40E_SR_CONTROL_WORD_1_SHIFT))) {
ret_code = i40e_validate_nvm_checksum(hw, NULL);
} else {
ret_code = I40E_ERR_DIAG_TEST_FAILED;
}
return ret_code;
}
