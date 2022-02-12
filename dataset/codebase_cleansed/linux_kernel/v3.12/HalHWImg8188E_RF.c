static bool CheckCondition(const u32 Condition, const u32 Hex)
{
u32 _board = (Hex & 0x000000FF);
u32 _interface = (Hex & 0x0000FF00) >> 8;
u32 _platform = (Hex & 0x00FF0000) >> 16;
u32 cond = Condition;
if (Condition == 0xCDCDCDCD)
return true;
cond = Condition & 0x000000FF;
if ((_board == cond) && cond != 0x00)
return false;
cond = Condition & 0x0000FF00;
cond = cond >> 8;
if ((_interface & cond) == 0 && cond != 0x07)
return false;
cond = Condition & 0x00FF0000;
cond = cond >> 16;
if ((_platform & cond) == 0 && cond != 0x0F)
return false;
return true;
}
enum HAL_STATUS ODM_ReadAndConfig_RadioA_1T_8188E(struct odm_dm_struct *pDM_Odm)
{
#define READ_NEXT_PAIR(v1, v2, i) do \
{ i += 2; v1 = Array[i]; \
v2 = Array[i+1]; } while (0)
u32 hex = 0;
u32 i = 0;
u8 platform = pDM_Odm->SupportPlatform;
u8 interfaceValue = pDM_Odm->SupportInterface;
u8 board = pDM_Odm->BoardType;
u32 ArrayLen = sizeof(Array_RadioA_1T_8188E)/sizeof(u32);
u32 *Array = Array_RadioA_1T_8188E;
bool biol = false;
struct adapter *Adapter = pDM_Odm->Adapter;
struct xmit_frame *pxmit_frame = NULL;
u8 bndy_cnt = 1;
enum HAL_STATUS rst = HAL_STATUS_SUCCESS;
hex += board;
hex += interfaceValue << 8;
hex += platform << 16;
hex += 0xFF000000;
biol = rtw_IOL_applied(Adapter);
if (biol) {
pxmit_frame = rtw_IOL_accquire_xmit_frame(Adapter);
if (pxmit_frame == NULL) {
pr_info("rtw_IOL_accquire_xmit_frame failed\n");
return HAL_STATUS_FAILURE;
}
}
for (i = 0; i < ArrayLen; i += 2) {
u32 v1 = Array[i];
u32 v2 = Array[i+1];
if (v1 < 0xCDCDCDCD) {
if (biol) {
if (rtw_IOL_cmd_boundary_handle(pxmit_frame))
bndy_cnt++;
if (v1 == 0xffe)
rtw_IOL_append_DELAY_MS_cmd(pxmit_frame, 50);
else if (v1 == 0xfd)
rtw_IOL_append_DELAY_MS_cmd(pxmit_frame, 5);
else if (v1 == 0xfc)
rtw_IOL_append_DELAY_MS_cmd(pxmit_frame, 1);
else if (v1 == 0xfb)
rtw_IOL_append_DELAY_US_cmd(pxmit_frame, 50);
else if (v1 == 0xfa)
rtw_IOL_append_DELAY_US_cmd(pxmit_frame, 5);
else if (v1 == 0xf9)
rtw_IOL_append_DELAY_US_cmd(pxmit_frame, 1);
else
rtw_IOL_append_WRF_cmd(pxmit_frame, ODM_RF_PATH_A, (u16)v1, v2, bRFRegOffsetMask);
} else {
odm_ConfigRF_RadioA_8188E(pDM_Odm, v1, v2);
}
continue;
} else {
if (!CheckCondition(Array[i], hex)) {
READ_NEXT_PAIR(v1, v2, i);
while (v2 != 0xDEAD &&
v2 != 0xCDEF &&
v2 != 0xCDCD && i < ArrayLen - 2)
READ_NEXT_PAIR(v1, v2, i);
i -= 2;
} else {
READ_NEXT_PAIR(v1, v2, i);
while (v2 != 0xDEAD &&
v2 != 0xCDEF &&
v2 != 0xCDCD && i < ArrayLen - 2) {
if (biol) {
if (rtw_IOL_cmd_boundary_handle(pxmit_frame))
bndy_cnt++;
if (v1 == 0xffe)
rtw_IOL_append_DELAY_MS_cmd(pxmit_frame, 50);
else if (v1 == 0xfd)
rtw_IOL_append_DELAY_MS_cmd(pxmit_frame, 5);
else if (v1 == 0xfc)
rtw_IOL_append_DELAY_MS_cmd(pxmit_frame, 1);
else if (v1 == 0xfb)
rtw_IOL_append_DELAY_US_cmd(pxmit_frame, 50);
else if (v1 == 0xfa)
rtw_IOL_append_DELAY_US_cmd(pxmit_frame, 5);
else if (v1 == 0xf9)
rtw_IOL_append_DELAY_US_cmd(pxmit_frame, 1);
else
rtw_IOL_append_WRF_cmd(pxmit_frame, ODM_RF_PATH_A, (u16)v1, v2, bRFRegOffsetMask);
} else {
odm_ConfigRF_RadioA_8188E(pDM_Odm, v1, v2);
}
READ_NEXT_PAIR(v1, v2, i);
}
while (v2 != 0xDEAD && i < ArrayLen - 2)
READ_NEXT_PAIR(v1, v2, i);
}
}
}
if (biol) {
if (!rtw_IOL_exec_cmds_sync(pDM_Odm->Adapter, pxmit_frame, 1000, bndy_cnt)) {
rst = HAL_STATUS_FAILURE;
pr_info("~~~ IOL Config %s Failed !!!\n", __func__);
}
}
return rst;
}
