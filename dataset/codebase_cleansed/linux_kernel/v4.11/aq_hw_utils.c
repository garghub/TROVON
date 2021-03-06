void aq_hw_write_reg_bit(struct aq_hw_s *aq_hw, u32 addr, u32 msk,
u32 shift, u32 val)
{
if (msk ^ ~0) {
u32 reg_old, reg_new;
reg_old = aq_hw_read_reg(aq_hw, addr);
reg_new = (reg_old & (~msk)) | (val << shift);
if (reg_old != reg_new)
aq_hw_write_reg(aq_hw, addr, reg_new);
} else {
aq_hw_write_reg(aq_hw, addr, val);
}
}
u32 aq_hw_read_reg_bit(struct aq_hw_s *aq_hw, u32 addr, u32 msk, u32 shift)
{
return ((aq_hw_read_reg(aq_hw, addr) & msk) >> shift);
}
u32 aq_hw_read_reg(struct aq_hw_s *hw, u32 reg)
{
u32 value = readl(hw->mmio + reg);
if ((~0U) == value && (~0U) == readl(hw->mmio + hw->not_ff_addr))
aq_utils_obj_set(&hw->header.flags, AQ_HW_FLAG_ERR_UNPLUG);
return value;
}
void aq_hw_write_reg(struct aq_hw_s *hw, u32 reg, u32 value)
{
writel(value, hw->mmio + reg);
}
int aq_hw_err_from_flags(struct aq_hw_s *hw)
{
int err = 0;
if (aq_utils_obj_test(&hw->header.flags, AQ_HW_FLAG_ERR_UNPLUG)) {
err = -ENXIO;
goto err_exit;
}
if (aq_utils_obj_test(&hw->header.flags, AQ_HW_FLAG_ERR_HW)) {
err = -EIO;
goto err_exit;
}
err_exit:
return err;
}
