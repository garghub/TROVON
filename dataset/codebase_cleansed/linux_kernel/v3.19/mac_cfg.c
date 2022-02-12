bool rtl88eu_phy_mac_config(struct adapter *adapt)
{
u32 i;
u32 arraylength;
u32 *ptrarray;
arraylength = sizeof(array_MAC_REG_8188E)/sizeof(u32);
ptrarray = array_MAC_REG_8188E;
for (i = 0; i < arraylength; i = i + 2)
usb_write8(adapt, ptrarray[i], (u8)ptrarray[i + 1]);
usb_write8(adapt, REG_MAX_AGGR_NUM, MAX_AGGR_NUM);
return true;
}
