void
odm_ConfigRFReg_8723A(
struct dm_odm_t *pDM_Odm,
u32 Addr,
u32 Data,
enum RF_RADIO_PATH RF_PATH,
u32 RegAddr
)
{
if (Addr == 0xfe) {
msleep(50);
} else if (Addr == 0xfd) {
mdelay(5);
} else if (Addr == 0xfc) {
mdelay(1);
} else if (Addr == 0xfb) {
udelay(50);
} else if (Addr == 0xfa) {
udelay(5);
} else if (Addr == 0xf9) {
udelay(1);
} else {
ODM_SetRFReg(pDM_Odm, RF_PATH, RegAddr, bRFRegOffsetMask, Data);
udelay(1);
}
}
void odm_ConfigMAC_8723A(struct dm_odm_t *pDM_Odm,
u32 Addr,
u8 Data
)
{
ODM_Write1Byte(pDM_Odm, Addr, Data);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_LOUD,
("===> ODM_ConfigMACWithHeaderFile23a: [MAC_REG] %08X %08X\n",
Addr, Data));
}
void
odm_ConfigBB_AGC_8723A(
struct dm_odm_t *pDM_Odm,
u32 Addr,
u32 Bitmask,
u32 Data
)
{
ODM_SetBBReg(pDM_Odm, Addr, Bitmask, Data);
udelay(1);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_LOUD,
("===> ODM_ConfigBBWithHeaderFile23a: [AGC_TAB] %08X %08X\n",
Addr, Data));
}
void
odm_ConfigBB_PHY_8723A(
struct dm_odm_t *pDM_Odm,
u32 Addr,
u32 Bitmask,
u32 Data
)
{
if (Addr == 0xfe)
msleep(50);
else if (Addr == 0xfd)
mdelay(5);
else if (Addr == 0xfc)
mdelay(1);
else if (Addr == 0xfb)
udelay(50);
else if (Addr == 0xfa)
udelay(5);
else if (Addr == 0xf9)
udelay(1);
else if (Addr == 0xa24)
pDM_Odm->RFCalibrateInfo.RegA24 = Data;
ODM_SetBBReg(pDM_Odm, Addr, Bitmask, Data);
udelay(1);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_LOUD,
("===> ODM_ConfigBBWithHeaderFile23a: [PHY_REG] %08X %08X\n",
Addr, Data));
}
