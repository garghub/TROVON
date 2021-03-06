u32 omap2_pwrdm_get_mem_bank_onstate_mask(u8 bank)
{
switch (bank) {
case 0:
return OMAP_MEM0_ONSTATE_MASK;
case 1:
return OMAP_MEM1_ONSTATE_MASK;
case 2:
return OMAP_MEM2_ONSTATE_MASK;
case 3:
return OMAP_MEM3_ONSTATE_MASK;
case 4:
return OMAP_MEM4_ONSTATE_MASK;
default:
WARN_ON(1);
return -EEXIST;
}
return 0;
}
u32 omap2_pwrdm_get_mem_bank_retst_mask(u8 bank)
{
switch (bank) {
case 0:
return OMAP_MEM0_RETSTATE_MASK;
case 1:
return OMAP_MEM1_RETSTATE_MASK;
case 2:
return OMAP_MEM2_RETSTATE_MASK;
case 3:
return OMAP_MEM3_RETSTATE_MASK;
case 4:
return OMAP_MEM4_RETSTATE_MASK;
default:
WARN_ON(1);
return -EEXIST;
}
return 0;
}
u32 omap2_pwrdm_get_mem_bank_stst_mask(u8 bank)
{
switch (bank) {
case 0:
return OMAP_MEM0_STATEST_MASK;
case 1:
return OMAP_MEM1_STATEST_MASK;
case 2:
return OMAP_MEM2_STATEST_MASK;
case 3:
return OMAP_MEM3_STATEST_MASK;
case 4:
return OMAP_MEM4_STATEST_MASK;
default:
WARN_ON(1);
return -EEXIST;
}
return 0;
}
