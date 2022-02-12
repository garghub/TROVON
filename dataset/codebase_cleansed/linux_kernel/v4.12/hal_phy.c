u32 PHY_CalculateBitShift(u32 BitMask)
{
u32 i;
for (i = 0; i <= 31; i++) {
if (((BitMask>>i) & 0x1) == 1)
break;
}
return i;
}
u32 PHY_RFShadowRead(IN PADAPTER Adapter, IN u8 eRFPath, IN u32 Offset)
{
return RF_Shadow[eRFPath][Offset].Value;
}
void PHY_RFShadowWrite(
IN PADAPTER Adapter, IN u8 eRFPath, IN u32 Offset, IN u32 Data
)
{
RF_Shadow[eRFPath][Offset].Value = (Data & bRFRegOffsetMask);
RF_Shadow[eRFPath][Offset].Driver_Write = true;
}
bool PHY_RFShadowCompare(IN PADAPTER Adapter, IN u8 eRFPath, IN u32 Offset)
{
u32 reg;
if (RF_Shadow[eRFPath][Offset].Compare == true) {
reg = rtw_hal_read_rfreg(Adapter, eRFPath, Offset, bRFRegOffsetMask);
if (RF_Shadow[eRFPath][Offset].Value != reg) {
RF_Shadow[eRFPath][Offset].ErrorOrNot = true;
}
return RF_Shadow[eRFPath][Offset].ErrorOrNot;
}
return false;
}
void PHY_RFShadowRecorver(IN PADAPTER Adapter, IN u8 eRFPath, IN u32 Offset)
{
if (RF_Shadow[eRFPath][Offset].ErrorOrNot == true) {
if (RF_Shadow[eRFPath][Offset].Recorver == true) {
rtw_hal_write_rfreg(Adapter, eRFPath, Offset, bRFRegOffsetMask,
RF_Shadow[eRFPath][Offset].Value);
}
}
}
void PHY_RFShadowCompareAll(IN PADAPTER Adapter)
{
u8 eRFPath = 0;
u32 Offset = 0, maxReg = GET_RF6052_REAL_MAX_REG(Adapter);
for (eRFPath = 0; eRFPath < RF6052_MAX_PATH; eRFPath++) {
for (Offset = 0; Offset < maxReg; Offset++) {
PHY_RFShadowCompare(Adapter, eRFPath, Offset);
}
}
}
void PHY_RFShadowRecorverAll(IN PADAPTER Adapter)
{
u8 eRFPath = 0;
u32 Offset = 0, maxReg = GET_RF6052_REAL_MAX_REG(Adapter);
for (eRFPath = 0; eRFPath < RF6052_MAX_PATH; eRFPath++) {
for (Offset = 0; Offset < maxReg; Offset++) {
PHY_RFShadowRecorver(Adapter, eRFPath, Offset);
}
}
}
void
PHY_RFShadowCompareFlagSet(
IN PADAPTER Adapter, IN u8 eRFPath, IN u32 Offset, IN u8 Type
)
{
RF_Shadow[eRFPath][Offset].Compare = Type;
}
void PHY_RFShadowRecorverFlagSet(
IN PADAPTER Adapter, IN u8 eRFPath, IN u32 Offset, IN u8 Type
)
{
RF_Shadow[eRFPath][Offset].Recorver = Type;
}
void PHY_RFShadowCompareFlagSetAll(IN PADAPTER Adapter)
{
u8 eRFPath = 0;
u32 Offset = 0, maxReg = GET_RF6052_REAL_MAX_REG(Adapter);
for (eRFPath = 0; eRFPath < RF6052_MAX_PATH; eRFPath++) {
for (Offset = 0; Offset < maxReg; Offset++) {
if (Offset != 0x26 && Offset != 0x27)
PHY_RFShadowCompareFlagSet(Adapter, eRFPath, Offset, false);
else
PHY_RFShadowCompareFlagSet(Adapter, eRFPath, Offset, true);
}
}
}
void PHY_RFShadowRecorverFlagSetAll(IN PADAPTER Adapter)
{
u8 eRFPath = 0;
u32 Offset = 0, maxReg = GET_RF6052_REAL_MAX_REG(Adapter);
for (eRFPath = 0; eRFPath < RF6052_MAX_PATH; eRFPath++) {
for (Offset = 0; Offset < maxReg; Offset++) {
if (Offset != 0x26 && Offset != 0x27)
PHY_RFShadowRecorverFlagSet(Adapter, eRFPath, Offset, false);
else
PHY_RFShadowRecorverFlagSet(Adapter, eRFPath, Offset, true);
}
}
}
void PHY_RFShadowRefresh(IN PADAPTER Adapter)
{
u8 eRFPath = 0;
u32 Offset = 0, maxReg = GET_RF6052_REAL_MAX_REG(Adapter);
for (eRFPath = 0; eRFPath < RF6052_MAX_PATH; eRFPath++) {
for (Offset = 0; Offset < maxReg; Offset++) {
RF_Shadow[eRFPath][Offset].Value = 0;
RF_Shadow[eRFPath][Offset].Compare = false;
RF_Shadow[eRFPath][Offset].Recorver = false;
RF_Shadow[eRFPath][Offset].ErrorOrNot = false;
RF_Shadow[eRFPath][Offset].Driver_Write = false;
}
}
}
