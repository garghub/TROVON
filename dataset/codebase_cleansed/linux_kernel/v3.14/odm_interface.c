u8 ODM_Read1Byte(struct odm_dm_struct *pDM_Odm, u32 RegAddr)
{
struct adapter *Adapter = pDM_Odm->Adapter;
return rtw_read8(Adapter, RegAddr);
}
u16 ODM_Read2Byte(struct odm_dm_struct *pDM_Odm, u32 RegAddr)
{
struct adapter *Adapter = pDM_Odm->Adapter;
return rtw_read16(Adapter, RegAddr);
}
u32 ODM_Read4Byte(struct odm_dm_struct *pDM_Odm, u32 RegAddr)
{
struct adapter *Adapter = pDM_Odm->Adapter;
return rtw_read32(Adapter, RegAddr);
}
void ODM_Write1Byte(struct odm_dm_struct *pDM_Odm, u32 RegAddr, u8 Data)
{
struct adapter *Adapter = pDM_Odm->Adapter;
rtw_write8(Adapter, RegAddr, Data);
}
void ODM_Write2Byte(struct odm_dm_struct *pDM_Odm, u32 RegAddr, u16 Data)
{
struct adapter *Adapter = pDM_Odm->Adapter;
rtw_write16(Adapter, RegAddr, Data);
}
void ODM_Write4Byte(struct odm_dm_struct *pDM_Odm, u32 RegAddr, u32 Data)
{
struct adapter *Adapter = pDM_Odm->Adapter;
rtw_write32(Adapter, RegAddr, Data);
}
void ODM_AllocateMemory(struct odm_dm_struct *pDM_Odm, void **pPtr, u32 length)
{
*pPtr = rtw_zvmalloc(length);
}
void ODM_FreeMemory(struct odm_dm_struct *pDM_Odm, void *pPtr, u32 length)
{
rtw_vmfree(pPtr, length);
}
s32 ODM_CompareMemory(struct odm_dm_struct *pDM_Odm, void *pBuf1, void *pBuf2, u32 length)
{
return _rtw_memcmp(pBuf1, pBuf2, length);
}
void ODM_SetTimer(struct odm_dm_struct *pDM_Odm, struct timer_list *pTimer, u32 msDelay)
{
_set_timer(pTimer, msDelay);
}
void ODM_InitializeTimer(struct odm_dm_struct *pDM_Odm, struct timer_list *pTimer,
void *CallBackFunc, void *pContext,
const char *szID)
{
struct adapter *Adapter = pDM_Odm->Adapter;
_init_timer(pTimer, Adapter->pnetdev, CallBackFunc, pDM_Odm);
}
void ODM_CancelTimer(struct odm_dm_struct *pDM_Odm, struct timer_list *pTimer)
{
_cancel_timer_ex(pTimer);
}
u32 ODM_FillH2CCmd(u8 *pH2CBuffer, u32 H2CBufferLen, u32 CmdNum,
u32 *pElementID, u32 *pCmdLen,
u8 **pCmbBuffer, u8 *CmdStartSeq)
{
return true;
}
