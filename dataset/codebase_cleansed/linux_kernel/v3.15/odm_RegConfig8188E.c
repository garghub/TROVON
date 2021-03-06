void odm_ConfigRFReg_8188E(struct odm_dm_struct *pDM_Odm, u32 Addr,
u32 Data, enum rf_radio_path RF_PATH,
u32 RegAddr)
{
struct adapter *adapter = pDM_Odm->Adapter;
if (Addr == 0xffe) {
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
PHY_SetRFReg(adapter, RF_PATH, RegAddr, bRFRegOffsetMask, Data);
udelay(1);
}
}
void odm_ConfigRF_RadioA_8188E(struct odm_dm_struct *pDM_Odm, u32 Addr, u32 Data)
{
u32 content = 0x1000;
u32 maskforPhySet = (u32)(content&0xE000);
odm_ConfigRFReg_8188E(pDM_Odm, Addr, Data, RF_PATH_A, Addr|maskforPhySet);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ConfigRFWithHeaderFile: [RadioA] %08X %08X\n", Addr, Data));
}
void odm_ConfigRF_RadioB_8188E(struct odm_dm_struct *pDM_Odm, u32 Addr, u32 Data)
{
u32 content = 0x1001;
u32 maskforPhySet = (u32)(content&0xE000);
odm_ConfigRFReg_8188E(pDM_Odm, Addr, Data, RF_PATH_B, Addr|maskforPhySet);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ConfigRFWithHeaderFile: [RadioB] %08X %08X\n", Addr, Data));
}
void odm_ConfigMAC_8188E(struct odm_dm_struct *pDM_Odm, u32 Addr, u8 Data)
{
struct adapter *adapt = pDM_Odm->Adapter;
rtw_write8(adapt, Addr, Data);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ConfigMACWithHeaderFile: [MAC_REG] %08X %08X\n", Addr, Data));
}
void odm_ConfigBB_AGC_8188E(struct odm_dm_struct *pDM_Odm, u32 Addr, u32 Bitmask, u32 Data)
{
struct adapter *adapter = pDM_Odm->Adapter;
PHY_SetBBReg(adapter, Addr, Bitmask, Data);
udelay(1);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE,
("===> ODM_ConfigBBWithHeaderFile: [AGC_TAB] %08X %08X\n",
Addr, Data));
}
void odm_ConfigBB_PHY_REG_PG_8188E(struct odm_dm_struct *pDM_Odm, u32 Addr,
u32 Bitmask, u32 Data)
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
} else{
ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_LOUD,
("===> @@@@@@@ ODM_ConfigBBWithHeaderFile: [PHY_REG] %08X %08X %08X\n",
Addr, Bitmask, Data));
storePwrIndexDiffRateOffset(pDM_Odm->Adapter, Addr, Bitmask, Data);
}
}
void odm_ConfigBB_PHY_8188E(struct odm_dm_struct *pDM_Odm, u32 Addr, u32 Bitmask, u32 Data)
{
struct adapter *adapter = pDM_Odm->Adapter;
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
if (Addr == 0xa24)
pDM_Odm->RFCalibrateInfo.RegA24 = Data;
PHY_SetBBReg(adapter, Addr, Bitmask, Data);
udelay(1);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE,
("===> ODM_ConfigBBWithHeaderFile: [PHY_REG] %08X %08X\n",
Addr, Data));
}
}
