static bool CheckCondition(const u32 condition, const u32 hex)
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
enum HAL_STATUS ODM_ReadAndConfig_AGC_TAB_1T_8188E(struct odm_dm_struct *dm_odm)
{
u32 hex = 0;
u32 i = 0;
u8 platform = dm_odm->SupportPlatform;
u8 interfaceValue = dm_odm->SupportInterface;
u8 board = dm_odm->BoardType;
u32 arraylen = sizeof(array_agc_tab_1t_8188e)/sizeof(u32);
u32 *array = array_agc_tab_1t_8188e;
bool biol = false;
struct adapter *adapter = dm_odm->Adapter;
struct xmit_frame *pxmit_frame = NULL;
u8 bndy_cnt = 1;
enum HAL_STATUS rst = HAL_STATUS_SUCCESS;
hex += board;
hex += interfaceValue << 8;
hex += platform << 16;
hex += 0xFF000000;
biol = rtw_IOL_applied(adapter);
if (biol) {
pxmit_frame = rtw_IOL_accquire_xmit_frame(adapter);
if (pxmit_frame == NULL) {
pr_info("rtw_IOL_accquire_xmit_frame failed\n");
return HAL_STATUS_FAILURE;
}
}
for (i = 0; i < arraylen; i += 2) {
u32 v1 = array[i];
u32 v2 = array[i+1];
if (v1 < 0xCDCDCDCD) {
if (biol) {
if (rtw_IOL_cmd_boundary_handle(pxmit_frame))
bndy_cnt++;
rtw_IOL_append_WD_cmd(pxmit_frame, (u16)v1, v2, bMaskDWord);
} else {
odm_ConfigBB_AGC_8188E(dm_odm, v1, bMaskDWord, v2);
}
continue;
} else {
if (!CheckCondition(array[i], hex)) {
read_next_pair(array, v1, v2, i);
while (v2 != 0xDEAD &&
v2 != 0xCDEF &&
v2 != 0xCDCD && i < arraylen - 2)
read_next_pair(array, v1, v2, i);
i -= 2;
} else {
read_next_pair(array, v1, v2, i);
while (v2 != 0xDEAD &&
v2 != 0xCDEF &&
v2 != 0xCDCD && i < arraylen - 2) {
if (biol) {
if (rtw_IOL_cmd_boundary_handle(pxmit_frame))
bndy_cnt++;
rtw_IOL_append_WD_cmd(pxmit_frame, (u16)v1, v2, bMaskDWord);
} else {
odm_ConfigBB_AGC_8188E(dm_odm, v1, bMaskDWord, v2);
}
read_next_pair(array, v1, v2, i);
}
while (v2 != 0xDEAD && i < arraylen - 2)
read_next_pair(array, v1, v2, i);
}
}
}
if (biol) {
if (!rtw_IOL_exec_cmds_sync(dm_odm->Adapter, pxmit_frame, 1000, bndy_cnt)) {
printk("~~~ %s IOL_exec_cmds Failed !!!\n", __func__);
rst = HAL_STATUS_FAILURE;
}
}
return rst;
}
enum HAL_STATUS ODM_ReadAndConfig_PHY_REG_1T_8188E(struct odm_dm_struct *dm_odm)
{
u32 hex = 0;
u32 i = 0;
u8 platform = dm_odm->SupportPlatform;
u8 interfaceValue = dm_odm->SupportInterface;
u8 board = dm_odm->BoardType;
u32 arraylen = sizeof(array_phy_reg_1t_8188e)/sizeof(u32);
u32 *array = array_phy_reg_1t_8188e;
bool biol = false;
struct adapter *adapter = dm_odm->Adapter;
struct xmit_frame *pxmit_frame = NULL;
u8 bndy_cnt = 1;
enum HAL_STATUS rst = HAL_STATUS_SUCCESS;
hex += board;
hex += interfaceValue << 8;
hex += platform << 16;
hex += 0xFF000000;
biol = rtw_IOL_applied(adapter);
if (biol) {
pxmit_frame = rtw_IOL_accquire_xmit_frame(adapter);
if (pxmit_frame == NULL) {
pr_info("rtw_IOL_accquire_xmit_frame failed\n");
return HAL_STATUS_FAILURE;
}
}
for (i = 0; i < arraylen; i += 2) {
u32 v1 = array[i];
u32 v2 = array[i+1];
if (v1 < 0xCDCDCDCD) {
if (biol) {
if (rtw_IOL_cmd_boundary_handle(pxmit_frame))
bndy_cnt++;
if (v1 == 0xfe) {
rtw_IOL_append_DELAY_MS_cmd(pxmit_frame, 50);
} else if (v1 == 0xfd) {
rtw_IOL_append_DELAY_MS_cmd(pxmit_frame, 5);
} else if (v1 == 0xfc) {
rtw_IOL_append_DELAY_MS_cmd(pxmit_frame, 1);
} else if (v1 == 0xfb) {
rtw_IOL_append_DELAY_US_cmd(pxmit_frame, 50);
} else if (v1 == 0xfa) {
rtw_IOL_append_DELAY_US_cmd(pxmit_frame, 5);
} else if (v1 == 0xf9) {
rtw_IOL_append_DELAY_US_cmd(pxmit_frame, 1);
} else {
if (v1 == 0xa24)
dm_odm->RFCalibrateInfo.RegA24 = v2;
rtw_IOL_append_WD_cmd(pxmit_frame, (u16)v1, v2, bMaskDWord);
}
} else {
odm_ConfigBB_PHY_8188E(dm_odm, v1, bMaskDWord, v2);
}
continue;
} else {
if (!CheckCondition(array[i], hex)) {
read_next_pair(array, v1, v2, i);
while (v2 != 0xDEAD &&
v2 != 0xCDEF &&
v2 != 0xCDCD && i < arraylen - 2)
read_next_pair(array, v1, v2, i);
i -= 2;
} else {
read_next_pair(array, v1, v2, i);
while (v2 != 0xDEAD &&
v2 != 0xCDEF &&
v2 != 0xCDCD && i < arraylen - 2) {
if (biol) {
if (rtw_IOL_cmd_boundary_handle(pxmit_frame))
bndy_cnt++;
if (v1 == 0xfe) {
rtw_IOL_append_DELAY_MS_cmd(pxmit_frame, 50);
} else if (v1 == 0xfd) {
rtw_IOL_append_DELAY_MS_cmd(pxmit_frame, 5);
} else if (v1 == 0xfc) {
rtw_IOL_append_DELAY_MS_cmd(pxmit_frame, 1);
} else if (v1 == 0xfb) {
rtw_IOL_append_DELAY_US_cmd(pxmit_frame, 50);
} else if (v1 == 0xfa) {
rtw_IOL_append_DELAY_US_cmd(pxmit_frame, 5);
} else if (v1 == 0xf9) {
rtw_IOL_append_DELAY_US_cmd(pxmit_frame, 1);
} else{
if (v1 == 0xa24)
dm_odm->RFCalibrateInfo.RegA24 = v2;
rtw_IOL_append_WD_cmd(pxmit_frame, (u16)v1, v2, bMaskDWord);
}
} else {
odm_ConfigBB_PHY_8188E(dm_odm, v1, bMaskDWord, v2);
}
read_next_pair(array, v1, v2, i);
}
while (v2 != 0xDEAD && i < arraylen - 2)
read_next_pair(array, v1, v2, i);
}
}
}
if (biol) {
if (!rtw_IOL_exec_cmds_sync(dm_odm->Adapter, pxmit_frame, 1000, bndy_cnt)) {
rst = HAL_STATUS_FAILURE;
pr_info("~~~ IOL Config %s Failed !!!\n", __func__);
}
}
return rst;
}
void ODM_ReadAndConfig_PHY_REG_PG_8188E(struct odm_dm_struct *dm_odm)
{
u32 hex;
u32 i = 0;
u8 platform = dm_odm->SupportPlatform;
u8 interfaceValue = dm_odm->SupportInterface;
u8 board = dm_odm->BoardType;
u32 arraylen = sizeof(array_phy_reg_pg_8188e) / sizeof(u32);
u32 *array = array_phy_reg_pg_8188e;
hex = board + (interfaceValue << 8);
hex += (platform << 16) + 0xFF000000;
for (i = 0; i < arraylen; i += 3) {
u32 v1 = array[i];
u32 v2 = array[i+1];
u32 v3 = array[i+2];
if (v1 < 0xCDCDCDCD) {
odm_ConfigBB_PHY_REG_PG_8188E(dm_odm, v1, v2, v3);
continue;
} else {
if (!CheckCondition(array[i], hex)) {
i += 2;
v1 = array[i];
v2 = array[i+1];
v3 = array[i+2];
while (v2 != 0xDEAD) {
i += 3;
v1 = array[i];
v2 = array[i+1];
v3 = array[i+1];
}
}
}
}
}
