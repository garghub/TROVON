void via_set_primary_address(u32 addr)
{
DEBUG_MSG(KERN_DEBUG "via_set_primary_address(0x%08X)\n", addr);
via_write_reg(VIACR, 0x0D, addr & 0xFF);
via_write_reg(VIACR, 0x0C, (addr >> 8) & 0xFF);
via_write_reg(VIACR, 0x34, (addr >> 16) & 0xFF);
via_write_reg_mask(VIACR, 0x48, (addr >> 24) & 0x1F, 0x1F);
}
void via_set_secondary_address(u32 addr)
{
DEBUG_MSG(KERN_DEBUG "via_set_secondary_address(0x%08X)\n", addr);
via_write_reg_mask(VIACR, 0x62, (addr >> 2) & 0xFE, 0xFE);
via_write_reg(VIACR, 0x63, (addr >> 10) & 0xFF);
via_write_reg(VIACR, 0x64, (addr >> 18) & 0xFF);
via_write_reg_mask(VIACR, 0xA3, (addr >> 26) & 0x07, 0x07);
}
void via_set_primary_pitch(u32 pitch)
{
DEBUG_MSG(KERN_DEBUG "via_set_primary_pitch(0x%08X)\n", pitch);
pitch = pitch >> 3;
via_write_reg(VIACR, 0x13, pitch & 0xFF);
via_write_reg_mask(VIACR, 0x35, (pitch >> (8 - 5)) & 0xE0, 0xE0);
}
void via_set_secondary_pitch(u32 pitch)
{
DEBUG_MSG(KERN_DEBUG "via_set_secondary_pitch(0x%08X)\n", pitch);
pitch = pitch >> 3;
via_write_reg(VIACR, 0x66, pitch & 0xFF);
via_write_reg_mask(VIACR, 0x67, (pitch >> 8) & 0x03, 0x03);
via_write_reg_mask(VIACR, 0x71, (pitch >> (10 - 7)) & 0x80, 0x80);
}
void via_set_primary_color_depth(u8 depth)
{
u8 value;
DEBUG_MSG(KERN_DEBUG "via_set_primary_color_depth(%d)\n", depth);
switch (depth) {
case 8:
value = 0x00;
break;
case 15:
value = 0x04;
break;
case 16:
value = 0x14;
break;
case 24:
value = 0x0C;
break;
case 30:
value = 0x08;
break;
default:
printk(KERN_WARNING "via_set_primary_color_depth: "
"Unsupported depth: %d\n", depth);
return;
}
via_write_reg_mask(VIASR, 0x15, value, 0x1C);
}
void via_set_secondary_color_depth(u8 depth)
{
u8 value;
DEBUG_MSG(KERN_DEBUG "via_set_secondary_color_depth(%d)\n", depth);
switch (depth) {
case 8:
value = 0x00;
break;
case 16:
value = 0x40;
break;
case 24:
value = 0xC0;
break;
case 30:
value = 0x80;
break;
default:
printk(KERN_WARNING "via_set_secondary_color_depth: "
"Unsupported depth: %d\n", depth);
return;
}
via_write_reg_mask(VIACR, 0x67, value, 0xC0);
}
