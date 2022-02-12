static bool Checkcondition(const u32 condition, const u32 hex)
{
u32 _board = (hex & 0x000000FF);
u32 _interface = (hex & 0x0000FF00) >> 8;
u32 _platform = (hex & 0x00FF0000) >> 16;
u32 cond = condition;
if (condition == 0xCDCDCDCD)
return true;
cond = condition & 0x000000FF;
if ((_board == cond) && cond != 0x00)
return false;
cond = condition & 0x0000FF00;
cond = cond >> 8;
if ((_interface & cond) == 0 && cond != 0x07)
return false;
cond = condition & 0x00FF0000;
cond = cond >> 16;
if ((_platform & cond) == 0 && cond != 0x0F)
return false;
return true;
}
enum HAL_STATUS ODM_ReadAndConfig_MAC_REG_8188E(struct odm_dm_struct *dm_odm)
{
#define READ_NEXT_PAIR(v1, v2, i) do { i += 2; v1 = array[i]; v2 = array[i+1]; } while (0)
u32 hex = 0;
u32 i;
u8 platform = dm_odm->SupportPlatform;
u8 interface_val = dm_odm->SupportInterface;
u8 board = dm_odm->BoardType;
u32 array_len = sizeof(array_MAC_REG_8188E)/sizeof(u32);
u32 *array = array_MAC_REG_8188E;
bool biol = false;
struct adapter *adapt = dm_odm->Adapter;
struct xmit_frame *pxmit_frame = NULL;
u8 bndy_cnt = 1;
enum HAL_STATUS rst = HAL_STATUS_SUCCESS;
hex += board;
hex += interface_val << 8;
hex += platform << 16;
hex += 0xFF000000;
biol = rtw_IOL_applied(adapt);
if (biol) {
pxmit_frame = rtw_IOL_accquire_xmit_frame(adapt);
if (pxmit_frame == NULL) {
pr_info("rtw_IOL_accquire_xmit_frame failed\n");
return HAL_STATUS_FAILURE;
}
}
for (i = 0; i < array_len; i += 2) {
u32 v1 = array[i];
u32 v2 = array[i+1];
if (v1 < 0xCDCDCDCD) {
if (biol) {
if (rtw_IOL_cmd_boundary_handle(pxmit_frame))
bndy_cnt++;
rtw_IOL_append_WB_cmd(pxmit_frame, (u16)v1, (u8)v2, 0xFF);
} else {
odm_ConfigMAC_8188E(dm_odm, v1, (u8)v2);
}
continue;
} else {
if (!Checkcondition(array[i], hex)) {
READ_NEXT_PAIR(v1, v2, i);
while (v2 != 0xDEAD &&
v2 != 0xCDEF &&
v2 != 0xCDCD && i < array_len - 2) {
READ_NEXT_PAIR(v1, v2, i);
}
i -= 2;
} else {
READ_NEXT_PAIR(v1, v2, i);
while (v2 != 0xDEAD &&
v2 != 0xCDEF &&
v2 != 0xCDCD && i < array_len - 2) {
if (biol) {
if (rtw_IOL_cmd_boundary_handle(pxmit_frame))
bndy_cnt++;
rtw_IOL_append_WB_cmd(pxmit_frame, (u16)v1, (u8)v2, 0xFF);
} else {
odm_ConfigMAC_8188E(dm_odm, v1, (u8)v2);
}
READ_NEXT_PAIR(v1, v2, i);
}
while (v2 != 0xDEAD && i < array_len - 2)
READ_NEXT_PAIR(v1, v2, i);
}
}
}
if (biol) {
if (!rtw_IOL_exec_cmds_sync(dm_odm->Adapter, pxmit_frame, 1000, bndy_cnt)) {
pr_info("~~~ MAC IOL_exec_cmds Failed !!!\n");
rst = HAL_STATUS_FAILURE;
}
}
return rst;
}
