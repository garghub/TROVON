u8 ODM_Read1Byte(struct dm_odm_t *pDM_Odm,
u32 RegAddr
)
{
struct rtw_adapter *Adapter = pDM_Odm->Adapter;
return rtw_read8(Adapter, RegAddr);
}
u16 ODM_Read2Byte(struct dm_odm_t *pDM_Odm,
u32 RegAddr
)
{
struct rtw_adapter *Adapter = pDM_Odm->Adapter;
return rtw_read16(Adapter, RegAddr);
}
u32 ODM_Read4Byte(struct dm_odm_t *pDM_Odm,
u32 RegAddr
)
{
struct rtw_adapter *Adapter = pDM_Odm->Adapter;
return rtw_read32(Adapter, RegAddr);
}
void ODM_Write1Byte(
struct dm_odm_t *pDM_Odm,
u32 RegAddr,
u8 Data
)
{
struct rtw_adapter *Adapter = pDM_Odm->Adapter;
rtw_write8(Adapter, RegAddr, Data);
}
void ODM_Write2Byte(
struct dm_odm_t *pDM_Odm,
u32 RegAddr,
u16 Data
)
{
struct rtw_adapter *Adapter = pDM_Odm->Adapter;
rtw_write16(Adapter, RegAddr, Data);
}
void ODM_Write4Byte(
struct dm_odm_t *pDM_Odm,
u32 RegAddr,
u32 Data
)
{
struct rtw_adapter *Adapter = pDM_Odm->Adapter;
rtw_write32(Adapter, RegAddr, Data);
}
void ODM_SetMACReg(
struct dm_odm_t *pDM_Odm,
u32 RegAddr,
u32 BitMask,
u32 Data
)
{
struct rtw_adapter *Adapter = pDM_Odm->Adapter;
PHY_SetBBReg(Adapter, RegAddr, BitMask, Data);
}
u32 ODM_GetMACReg(
struct dm_odm_t *pDM_Odm,
u32 RegAddr,
u32 BitMask
)
{
struct rtw_adapter *Adapter = pDM_Odm->Adapter;
return PHY_QueryBBReg(Adapter, RegAddr, BitMask);
}
void ODM_SetBBReg(
struct dm_odm_t *pDM_Odm,
u32 RegAddr,
u32 BitMask,
u32 Data
)
{
struct rtw_adapter *Adapter = pDM_Odm->Adapter;
PHY_SetBBReg(Adapter, RegAddr, BitMask, Data);
}
u32 ODM_GetBBReg(
struct dm_odm_t *pDM_Odm,
u32 RegAddr,
u32 BitMask
)
{
struct rtw_adapter *Adapter = pDM_Odm->Adapter;
return PHY_QueryBBReg(Adapter, RegAddr, BitMask);
}
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
void ODM_AllocateMemory(
struct dm_odm_t *pDM_Odm,
void **pPtr,
u32 length
)
{
*pPtr = rtw_zvmalloc(length);
}
void ODM_FreeMemory(
struct dm_odm_t *pDM_Odm,
void *pPtr,
u32 length
)
{
rtw_vmfree(pPtr, length);
}
void
ODM_AcquireSpinLock(
struct dm_odm_t *pDM_Odm,
enum rt_spinlock_type type
)
{
}
void ODM_ReleaseSpinLock(
struct dm_odm_t *pDM_Odm,
enum rt_spinlock_type type
)
{
}
void ODM_InitializeWorkItem(
struct dm_odm_t *pDM_Odm,
void *pRtWorkItem,
RT_WORKITEM_CALL_BACK RtWorkItemCallback,
void *pContext,
const char *szID
)
{
}
void ODM_SetTimer(struct dm_odm_t *pDM_Odm, struct timer_list *pTimer, u32 msDelay)
{
mod_timer(pTimer, jiffies + msecs_to_jiffies(msDelay));
}
void ODM_ReleaseTimer(struct dm_odm_t *pDM_Odm, struct timer_list *pTimer)
{
}
u32 ODM_FillH2CCmd(
u8 *pH2CBuffer,
u32 H2CBufferLen,
u32 CmdNum,
u32 *pElementID,
u32 *pCmdLen,
u8 **pCmbBuffer,
u8 *CmdStartSeq
)
{
return true;
}
