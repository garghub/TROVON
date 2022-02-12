void ODM_SetRFReg(
struct dm_odm_t *pDM_Odm,
enum RF_RADIO_PATH eRFPath,
u32 RegAddr,
u32 BitMask,
u32 Data
)
{
struct rtw_adapter *Adapter = pDM_Odm->Adapter;
PHY_SetRFReg(Adapter, eRFPath, RegAddr, BitMask, Data);
}
u32 ODM_GetRFReg(
struct dm_odm_t *pDM_Odm,
enum RF_RADIO_PATH eRFPath,
u32 RegAddr,
u32 BitMask
)
{
struct rtw_adapter *Adapter = pDM_Odm->Adapter;
return PHY_QueryRFReg(Adapter, eRFPath, RegAddr, BitMask);
}
