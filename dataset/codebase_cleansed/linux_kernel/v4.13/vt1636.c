u8 viafb_gpio_i2c_read_lvds(struct lvds_setting_information
*plvds_setting_info, struct lvds_chip_information *plvds_chip_info,
u8 index)
{
u8 data;
viafb_i2c_readbyte(plvds_chip_info->i2c_port,
plvds_chip_info->lvds_chip_slave_addr, index, &data);
return data;
}
void viafb_gpio_i2c_write_mask_lvds(struct lvds_setting_information
*plvds_setting_info, struct lvds_chip_information
*plvds_chip_info, struct IODATA io_data)
{
int index, data;
index = io_data.Index;
data = viafb_gpio_i2c_read_lvds(plvds_setting_info, plvds_chip_info,
index);
data = (data & (~io_data.Mask)) | io_data.Data;
viafb_i2c_writebyte(plvds_chip_info->i2c_port,
plvds_chip_info->lvds_chip_slave_addr, index, data);
}
void viafb_init_lvds_vt1636(struct lvds_setting_information
*plvds_setting_info, struct lvds_chip_information *plvds_chip_info)
{
int reg_num, i;
reg_num = ARRAY_SIZE(common_init_data);
for (i = 0; i < reg_num; i++)
viafb_gpio_i2c_write_mask_lvds(plvds_setting_info,
plvds_chip_info, common_init_data[i]);
if (plvds_setting_info->device_lcd_dualedge)
viafb_gpio_i2c_write_mask_lvds(plvds_setting_info,
plvds_chip_info, dual_channel_enable_data);
else
viafb_gpio_i2c_write_mask_lvds(plvds_setting_info,
plvds_chip_info, single_channel_enable_data);
if (plvds_setting_info->LCDDithering)
viafb_gpio_i2c_write_mask_lvds(plvds_setting_info,
plvds_chip_info, dithering_enable_data);
else
viafb_gpio_i2c_write_mask_lvds(plvds_setting_info,
plvds_chip_info, dithering_disable_data);
}
void viafb_enable_lvds_vt1636(struct lvds_setting_information
*plvds_setting_info,
struct lvds_chip_information *plvds_chip_info)
{
viafb_gpio_i2c_write_mask_lvds(plvds_setting_info, plvds_chip_info,
vdd_on_data);
}
void viafb_disable_lvds_vt1636(struct lvds_setting_information
*plvds_setting_info,
struct lvds_chip_information *plvds_chip_info)
{
viafb_gpio_i2c_write_mask_lvds(plvds_setting_info, plvds_chip_info,
vdd_off_data);
}
bool viafb_lvds_identify_vt1636(u8 i2c_adapter)
{
u8 Buffer[2];
DEBUG_MSG(KERN_INFO "viafb_lvds_identify_vt1636.\n");
viaparinfo->chip_info->lvds_chip_info.lvds_chip_slave_addr =
VT1636_LVDS_I2C_ADDR;
if (viafb_i2c_readbyte(i2c_adapter, VT1636_LVDS_I2C_ADDR,
0x00, &Buffer[0]))
return false;
viafb_i2c_readbyte(i2c_adapter, VT1636_LVDS_I2C_ADDR, 0x01, &Buffer[1]);
if (!((Buffer[0] == 0x06) && (Buffer[1] == 0x11)))
return false;
viafb_i2c_readbyte(i2c_adapter, VT1636_LVDS_I2C_ADDR, 0x02, &Buffer[0]);
viafb_i2c_readbyte(i2c_adapter, VT1636_LVDS_I2C_ADDR, 0x03, &Buffer[1]);
if ((Buffer[0] == 0x45) && (Buffer[1] == 0x33)) {
viaparinfo->chip_info->lvds_chip_info.lvds_chip_name =
VT1636_LVDS;
return true;
}
return false;
}
static int get_clk_range_index(u32 Clk)
{
if (Clk < DPA_CLK_30M)
return DPA_CLK_RANGE_30M;
else if (Clk < DPA_CLK_50M)
return DPA_CLK_RANGE_30_50M;
else if (Clk < DPA_CLK_70M)
return DPA_CLK_RANGE_50_70M;
else if (Clk < DPA_CLK_100M)
return DPA_CLK_RANGE_70_100M;
else if (Clk < DPA_CLK_150M)
return DPA_CLK_RANGE_100_150M;
else
return DPA_CLK_RANGE_150M;
}
static void set_dpa_vt1636(struct lvds_setting_information
*plvds_setting_info, struct lvds_chip_information *plvds_chip_info,
struct VT1636_DPA_SETTING *p_vt1636_dpa_setting)
{
struct IODATA io_data;
io_data.Index = 0x09;
io_data.Mask = 0x1F;
io_data.Data = p_vt1636_dpa_setting->CLK_SEL_ST1;
viafb_gpio_i2c_write_mask_lvds(plvds_setting_info,
plvds_chip_info, io_data);
io_data.Index = 0x08;
io_data.Mask = 0x0F;
io_data.Data = p_vt1636_dpa_setting->CLK_SEL_ST2;
viafb_gpio_i2c_write_mask_lvds(plvds_setting_info, plvds_chip_info,
io_data);
}
void viafb_vt1636_patch_skew_on_vt3324(
struct lvds_setting_information *plvds_setting_info,
struct lvds_chip_information *plvds_chip_info)
{
struct VT1636_DPA_SETTING dpa = {0x00, 0x00}, dpa_16x12 = {0x0B, 0x03},
*pdpa;
int index;
DEBUG_MSG(KERN_INFO "viafb_vt1636_patch_skew_on_vt3324.\n");
index = get_clk_range_index(plvds_setting_info->vclk);
viafb_set_dpa_gfx(plvds_chip_info->output_interface,
&GFX_DPA_SETTING_TBL_VT3324[index]);
if (plvds_setting_info->lcd_panel_hres == 1600 &&
plvds_setting_info->lcd_panel_vres == 1200)
pdpa = &dpa_16x12;
else
pdpa = &dpa;
set_dpa_vt1636(plvds_setting_info, plvds_chip_info, pdpa);
}
void viafb_vt1636_patch_skew_on_vt3327(
struct lvds_setting_information *plvds_setting_info,
struct lvds_chip_information *plvds_chip_info)
{
struct VT1636_DPA_SETTING dpa = {0x00, 0x00};
int index;
DEBUG_MSG(KERN_INFO "viafb_vt1636_patch_skew_on_vt3327.\n");
index = get_clk_range_index(plvds_setting_info->vclk);
viafb_set_dpa_gfx(plvds_chip_info->output_interface,
&GFX_DPA_SETTING_TBL_VT3327[index]);
set_dpa_vt1636(plvds_setting_info, plvds_chip_info, &dpa);
}
void viafb_vt1636_patch_skew_on_vt3364(
struct lvds_setting_information *plvds_setting_info,
struct lvds_chip_information *plvds_chip_info)
{
int index;
DEBUG_MSG(KERN_INFO "viafb_vt1636_patch_skew_on_vt3364.\n");
index = get_clk_range_index(plvds_setting_info->vclk);
viafb_set_dpa_gfx(plvds_chip_info->output_interface,
&GFX_DPA_SETTING_TBL_VT3364[index]);
}
