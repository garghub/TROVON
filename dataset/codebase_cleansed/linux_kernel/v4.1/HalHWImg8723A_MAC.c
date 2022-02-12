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
cond >>= 8;
if ((_interface & cond) == 0 && cond != 0x07)
return false;
cond = Condition & 0x00FF0000;
cond >>= 16;
if ((_platform & cond) == 0 && cond != 0x0F)
return false;
return true;
}
void ODM_ReadAndConfig_MAC_REG_8723A(struct dm_odm_t *pDM_Odm)
{
#define READ_NEXT_PAIR(v1, v2, i) \
do { \
i += 2; v1 = Array[i]; v2 = Array[i+1]; \
} while (0)
u32 hex = 0;
u32 i = 0;
u8 platform = 0x04;
u8 board = pDM_Odm->BoardType;
u32 ArrayLen = sizeof(Array_MAC_REG_8723A)/sizeof(u32);
u32 *Array = Array_MAC_REG_8723A;
hex += board;
hex += ODM_ITRF_USB << 8;
hex += platform << 16;
hex += 0xFF000000;
for (i = 0; i < ArrayLen; i += 2) {
u32 v1 = Array[i];
u32 v2 = Array[i+1];
if (v1 < 0xCDCDCDCD) {
odm_ConfigMAC_8723A(pDM_Odm, v1, (u8)v2);
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
odm_ConfigMAC_8723A(pDM_Odm, v1, (u8)v2);
READ_NEXT_PAIR(v1, v2, i);
}
while (v2 != 0xDEAD && i < ArrayLen - 2)
READ_NEXT_PAIR(v1, v2, i);
}
}
}
}
