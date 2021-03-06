void odm_ConfigRFReg_8188E(struct odm_dm_struct *pDM_Odm, u32 Addr,
u32 Data, enum ODM_RF_RADIO_PATH RF_PATH,
u32 RegAddr)
{
if (Addr == 0xffe) {
ODM_sleep_ms(50);
} else if (Addr == 0xfd) {
ODM_delay_ms(5);
} else if (Addr == 0xfc) {
ODM_delay_ms(1);
} else if (Addr == 0xfb) {
ODM_delay_us(50);
} else if (Addr == 0xfa) {
ODM_delay_us(5);
} else if (Addr == 0xf9) {
ODM_delay_us(1);
} else {
ODM_SetRFReg(pDM_Odm, RF_PATH, RegAddr, bRFRegOffsetMask, Data);
ODM_delay_us(1);
}
}
void odm_ConfigRF_RadioA_8188E(struct odm_dm_struct *pDM_Odm, u32 Addr, u32 Data)
{
u32 content = 0x1000;
u32 maskforPhySet = (u32)(content&0xE000);
odm_ConfigRFReg_8188E(pDM_Odm, Addr, Data, ODM_RF_PATH_A, Addr|maskforPhySet);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ConfigRFWithHeaderFile: [RadioA] %08X %08X\n", Addr, Data));
}
void odm_ConfigRF_RadioB_8188E(struct odm_dm_struct *pDM_Odm, u32 Addr, u32 Data)
{
u32 content = 0x1001;
u32 maskforPhySet = (u32)(content&0xE000);
odm_ConfigRFReg_8188E(pDM_Odm, Addr, Data, ODM_RF_PATH_B, Addr|maskforPhySet);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ConfigRFWithHeaderFile: [RadioB] %08X %08X\n", Addr, Data));
}
void odm_ConfigMAC_8188E(struct odm_dm_struct *pDM_Odm, u32 Addr, u8 Data)
{
ODM_Write1Byte(pDM_Odm, Addr, Data);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE, ("===> ODM_ConfigMACWithHeaderFile: [MAC_REG] %08X %08X\n", Addr, Data));
}
void odm_ConfigBB_AGC_8188E(struct odm_dm_struct *pDM_Odm, u32 Addr, u32 Bitmask, u32 Data)
{
ODM_SetBBReg(pDM_Odm, Addr, Bitmask, Data);
ODM_delay_us(1);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE,
("===> ODM_ConfigBBWithHeaderFile: [AGC_TAB] %08X %08X\n",
Addr, Data));
}
void odm_ConfigBB_PHY_REG_PG_8188E(struct odm_dm_struct *pDM_Odm, u32 Addr,
u32 Bitmask, u32 Data)
{
if (Addr == 0xfe) {
ODM_sleep_ms(50);
} else if (Addr == 0xfd) {
ODM_delay_ms(5);
} else if (Addr == 0xfc) {
ODM_delay_ms(1);
} else if (Addr == 0xfb) {
ODM_delay_us(50);
} else if (Addr == 0xfa) {
ODM_delay_us(5);
} else if (Addr == 0xf9) {
ODM_delay_us(1);
} else{
ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_LOUD,
("===> @@@@@@@ ODM_ConfigBBWithHeaderFile: [PHY_REG] %08X %08X %08X\n",
Addr, Bitmask, Data));
storePwrIndexDiffRateOffset(pDM_Odm->Adapter, Addr, Bitmask, Data);
}
}
void odm_ConfigBB_PHY_8188E(struct odm_dm_struct *pDM_Odm, u32 Addr, u32 Bitmask, u32 Data)
{
if (Addr == 0xfe) {
ODM_sleep_ms(50);
} else if (Addr == 0xfd) {
ODM_delay_ms(5);
} else if (Addr == 0xfc) {
ODM_delay_ms(1);
} else if (Addr == 0xfb) {
ODM_delay_us(50);
} else if (Addr == 0xfa) {
ODM_delay_us(5);
} else if (Addr == 0xf9) {
ODM_delay_us(1);
} else {
if (Addr == 0xa24)
pDM_Odm->RFCalibrateInfo.RegA24 = Data;
ODM_SetBBReg(pDM_Odm, Addr, Bitmask, Data);
ODM_delay_us(1);
ODM_RT_TRACE(pDM_Odm, ODM_COMP_INIT, ODM_DBG_TRACE,
("===> ODM_ConfigBBWithHeaderFile: [PHY_REG] %08X %08X\n",
Addr, Data));
}
}
