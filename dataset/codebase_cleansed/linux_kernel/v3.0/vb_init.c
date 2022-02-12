static unsigned char
XGINew_GetXG20DRAMType(struct xgi_hw_device_info *HwDeviceExtension,
struct vb_device_info *pVBInfo)
{
unsigned char data, temp;
if (HwDeviceExtension->jChipType < XG20) {
if (*pVBInfo->pSoftSetting & SoftDRAMType) {
data = *pVBInfo->pSoftSetting & 0x07;
return data;
} else {
data = xgifb_reg_get(pVBInfo->P3c4, 0x39) & 0x02;
if (data == 0)
data = (xgifb_reg_get(pVBInfo->P3c4, 0x3A) &
0x02) >> 1;
return data;
}
} else if (HwDeviceExtension->jChipType == XG27) {
if (*pVBInfo->pSoftSetting & SoftDRAMType) {
data = *pVBInfo->pSoftSetting & 0x07;
return data;
}
temp = xgifb_reg_get(pVBInfo->P3c4, 0x3B);
if ((temp & 0x88) == 0x80)
data = 0;
else
data = 1;
return data;
} else if (HwDeviceExtension->jChipType == XG21) {
xgifb_reg_and(pVBInfo->P3d4, 0xB4, ~0x02);
udelay(800);
xgifb_reg_or(pVBInfo->P3d4, 0x4A, 0x80);
temp = xgifb_reg_get(pVBInfo->P3d4, 0x48);
if (temp & 0x01)
data = 1;
else
data = 0;
xgifb_reg_or(pVBInfo->P3d4, 0xB4, 0x02);
return data;
} else {
data = xgifb_reg_get(pVBInfo->P3d4, 0x97) & 0x01;
if (data == 1)
data++;
return data;
}
}
static void XGINew_DDR1x_MRS_340(unsigned long P3c4,
struct vb_device_info *pVBInfo)
{
xgifb_reg_set(P3c4, 0x18, 0x01);
xgifb_reg_set(P3c4, 0x19, 0x20);
xgifb_reg_set(P3c4, 0x16, 0x00);
xgifb_reg_set(P3c4, 0x16, 0x80);
if (*pVBInfo->pXGINew_DRAMTypeDefinition != 0x0C) {
mdelay(3);
xgifb_reg_set(P3c4, 0x18, 0x00);
xgifb_reg_set(P3c4, 0x19, 0x20);
xgifb_reg_set(P3c4, 0x16, 0x00);
xgifb_reg_set(P3c4, 0x16, 0x80);
}
udelay(60);
xgifb_reg_set(P3c4, 0x18, pVBInfo->SR15[2][XGINew_RAMType]);
xgifb_reg_set(P3c4, 0x19, 0x01);
xgifb_reg_set(P3c4, 0x16, pVBInfo->SR16[0]);
xgifb_reg_set(P3c4, 0x16, pVBInfo->SR16[1]);
mdelay(1);
xgifb_reg_set(P3c4, 0x1B, 0x03);
udelay(500);
xgifb_reg_set(P3c4, 0x18, pVBInfo->SR15[2][XGINew_RAMType]);
xgifb_reg_set(P3c4, 0x19, 0x00);
xgifb_reg_set(P3c4, 0x16, pVBInfo->SR16[2]);
xgifb_reg_set(P3c4, 0x16, pVBInfo->SR16[3]);
xgifb_reg_set(P3c4, 0x1B, 0x00);
}
static void XGINew_SetMemoryClock(struct xgi_hw_device_info *HwDeviceExtension,
struct vb_device_info *pVBInfo)
{
xgifb_reg_set(pVBInfo->P3c4,
0x28,
pVBInfo->MCLKData[XGINew_RAMType].SR28);
xgifb_reg_set(pVBInfo->P3c4,
0x29,
pVBInfo->MCLKData[XGINew_RAMType].SR29);
xgifb_reg_set(pVBInfo->P3c4,
0x2A,
pVBInfo->MCLKData[XGINew_RAMType].SR2A);
xgifb_reg_set(pVBInfo->P3c4,
0x2E,
pVBInfo->ECLKData[XGINew_RAMType].SR2E);
xgifb_reg_set(pVBInfo->P3c4,
0x2F,
pVBInfo->ECLKData[XGINew_RAMType].SR2F);
xgifb_reg_set(pVBInfo->P3c4,
0x30,
pVBInfo->ECLKData[XGINew_RAMType].SR30);
if (HwDeviceExtension->jChipType == XG42) {
if ((pVBInfo->MCLKData[XGINew_RAMType].SR28 == 0x1C) &&
(pVBInfo->MCLKData[XGINew_RAMType].SR29 == 0x01) &&
(((pVBInfo->ECLKData[XGINew_RAMType].SR2E == 0x1C) &&
(pVBInfo->ECLKData[XGINew_RAMType].SR2F == 0x01)) ||
((pVBInfo->ECLKData[XGINew_RAMType].SR2E == 0x22) &&
(pVBInfo->ECLKData[XGINew_RAMType].SR2F == 0x01))))
xgifb_reg_set(pVBInfo->P3c4,
0x32,
((unsigned char) xgifb_reg_get(
pVBInfo->P3c4, 0x32) & 0xFC) | 0x02);
}
}
static void XGINew_DDRII_Bootup_XG27(
struct xgi_hw_device_info *HwDeviceExtension,
unsigned long P3c4, struct vb_device_info *pVBInfo)
{
unsigned long P3d4 = P3c4 + 0x10;
XGINew_RAMType = (int) XGINew_GetXG20DRAMType(HwDeviceExtension,
pVBInfo);
XGINew_SetMemoryClock(HwDeviceExtension, pVBInfo);
xgifb_reg_set(P3d4, 0x97, *pVBInfo->pXGINew_CR97);
udelay(200);
xgifb_reg_set(P3c4, 0x18, 0x00);
xgifb_reg_set(P3c4, 0x19, 0x80);
xgifb_reg_set(P3c4, 0x16, 0x20);
udelay(15);
xgifb_reg_set(P3c4, 0x16, 0xA0);
udelay(15);
xgifb_reg_set(P3c4, 0x18, 0x00);
xgifb_reg_set(P3c4, 0x19, 0xC0);
xgifb_reg_set(P3c4, 0x16, 0x20);
udelay(15);
xgifb_reg_set(P3c4, 0x16, 0xA0);
udelay(15);
xgifb_reg_set(P3c4, 0x18, 0x00);
xgifb_reg_set(P3c4, 0x19, 0x40);
xgifb_reg_set(P3c4, 0x16, 0x20);
udelay(30);
xgifb_reg_set(P3c4, 0x16, 0xA0);
udelay(15);
xgifb_reg_set(P3c4, 0x18, 0x42);
xgifb_reg_set(P3c4, 0x19, 0x0A);
xgifb_reg_set(P3c4, 0x16, 0x00);
udelay(30);
xgifb_reg_set(P3c4, 0x16, 0x00);
xgifb_reg_set(P3c4, 0x16, 0x80);
xgifb_reg_set(P3c4, 0x1B, 0x04);
udelay(60);
xgifb_reg_set(P3c4, 0x1B, 0x00);
xgifb_reg_set(P3c4, 0x18, 0x42);
xgifb_reg_set(P3c4, 0x19, 0x08);
xgifb_reg_set(P3c4, 0x16, 0x00);
udelay(30);
xgifb_reg_set(P3c4, 0x16, 0x83);
udelay(15);
xgifb_reg_set(P3c4, 0x18, 0x80);
xgifb_reg_set(P3c4, 0x19, 0x46);
xgifb_reg_set(P3c4, 0x16, 0x20);
udelay(30);
xgifb_reg_set(P3c4, 0x16, 0xA0);
udelay(15);
xgifb_reg_set(P3c4, 0x18, 0x00);
xgifb_reg_set(P3c4, 0x19, 0x40);
xgifb_reg_set(P3c4, 0x16, 0x20);
udelay(30);
xgifb_reg_set(P3c4, 0x16, 0xA0);
udelay(15);
xgifb_reg_set(P3c4, 0x1B, 0x04);
udelay(200);
}
static void XGINew_DDR2_MRS_XG20(struct xgi_hw_device_info *HwDeviceExtension,
unsigned long P3c4, struct vb_device_info *pVBInfo)
{
unsigned long P3d4 = P3c4 + 0x10;
XGINew_RAMType = (int) XGINew_GetXG20DRAMType(HwDeviceExtension,
pVBInfo);
XGINew_SetMemoryClock(HwDeviceExtension, pVBInfo);
xgifb_reg_set(P3d4, 0x97, 0x11);
udelay(200);
xgifb_reg_set(P3c4, 0x18, 0x00);
xgifb_reg_set(P3c4, 0x19, 0x80);
xgifb_reg_set(P3c4, 0x16, 0x05);
xgifb_reg_set(P3c4, 0x16, 0x85);
xgifb_reg_set(P3c4, 0x18, 0x00);
xgifb_reg_set(P3c4, 0x19, 0xC0);
xgifb_reg_set(P3c4, 0x16, 0x05);
xgifb_reg_set(P3c4, 0x16, 0x85);
xgifb_reg_set(P3c4, 0x18, 0x00);
xgifb_reg_set(P3c4, 0x19, 0x40);
xgifb_reg_set(P3c4, 0x16, 0x05);
xgifb_reg_set(P3c4, 0x16, 0x85);
xgifb_reg_set(P3c4, 0x18, 0x42);
xgifb_reg_set(P3c4, 0x19, 0x02);
xgifb_reg_set(P3c4, 0x16, 0x05);
xgifb_reg_set(P3c4, 0x16, 0x85);
udelay(15);
xgifb_reg_set(P3c4, 0x1B, 0x04);
udelay(30);
xgifb_reg_set(P3c4, 0x1B, 0x00);
udelay(100);
xgifb_reg_set(P3c4, 0x18, 0x42);
xgifb_reg_set(P3c4, 0x19, 0x00);
xgifb_reg_set(P3c4, 0x16, 0x05);
xgifb_reg_set(P3c4, 0x16, 0x85);
udelay(200);
}
static void XGINew_DDR1x_MRS_XG20(unsigned long P3c4,
struct vb_device_info *pVBInfo)
{
xgifb_reg_set(P3c4, 0x18, 0x01);
xgifb_reg_set(P3c4, 0x19, 0x40);
xgifb_reg_set(P3c4, 0x16, 0x00);
xgifb_reg_set(P3c4, 0x16, 0x80);
udelay(60);
xgifb_reg_set(P3c4, 0x18, 0x00);
xgifb_reg_set(P3c4, 0x19, 0x40);
xgifb_reg_set(P3c4, 0x16, 0x00);
xgifb_reg_set(P3c4, 0x16, 0x80);
udelay(60);
xgifb_reg_set(P3c4, 0x18, pVBInfo->SR15[2][XGINew_RAMType]);
xgifb_reg_set(P3c4, 0x19, 0x01);
xgifb_reg_set(P3c4, 0x16, 0x03);
xgifb_reg_set(P3c4, 0x16, 0x83);
mdelay(1);
xgifb_reg_set(P3c4, 0x1B, 0x03);
udelay(500);
xgifb_reg_set(P3c4, 0x18, pVBInfo->SR15[2][XGINew_RAMType]);
xgifb_reg_set(P3c4, 0x19, 0x00);
xgifb_reg_set(P3c4, 0x16, 0x03);
xgifb_reg_set(P3c4, 0x16, 0x83);
xgifb_reg_set(P3c4, 0x1B, 0x00);
}
static void XGINew_DDR1x_DefaultRegister(
struct xgi_hw_device_info *HwDeviceExtension,
unsigned long Port, struct vb_device_info *pVBInfo)
{
unsigned long P3d4 = Port, P3c4 = Port - 0x10;
if (HwDeviceExtension->jChipType >= XG20) {
XGINew_SetMemoryClock(HwDeviceExtension, pVBInfo);
xgifb_reg_set(P3d4,
0x82,
pVBInfo->CR40[11][XGINew_RAMType]);
xgifb_reg_set(P3d4,
0x85,
pVBInfo->CR40[12][XGINew_RAMType]);
xgifb_reg_set(P3d4,
0x86,
pVBInfo->CR40[13][XGINew_RAMType]);
xgifb_reg_set(P3d4, 0x98, 0x01);
xgifb_reg_set(P3d4, 0x9A, 0x02);
XGINew_DDR1x_MRS_XG20(P3c4, pVBInfo);
} else {
XGINew_SetMemoryClock(HwDeviceExtension, pVBInfo);
switch (HwDeviceExtension->jChipType) {
case XG41:
case XG42:
xgifb_reg_set(P3d4,
0x82,
pVBInfo->CR40[11][XGINew_RAMType]);
xgifb_reg_set(P3d4,
0x85,
pVBInfo->CR40[12][XGINew_RAMType]);
xgifb_reg_set(P3d4,
0x86,
pVBInfo->CR40[13][XGINew_RAMType]);
break;
default:
xgifb_reg_set(P3d4, 0x82, 0x88);
xgifb_reg_set(P3d4, 0x86, 0x00);
xgifb_reg_get(P3d4, 0x86);
xgifb_reg_set(P3d4, 0x86, 0x88);
xgifb_reg_get(P3d4, 0x86);
xgifb_reg_set(P3d4,
0x86,
pVBInfo->CR40[13][XGINew_RAMType]);
xgifb_reg_set(P3d4, 0x82, 0x77);
xgifb_reg_set(P3d4, 0x85, 0x00);
xgifb_reg_get(P3d4, 0x85);
xgifb_reg_set(P3d4, 0x85, 0x88);
xgifb_reg_get(P3d4, 0x85);
xgifb_reg_set(P3d4,
0x85,
pVBInfo->CR40[12][XGINew_RAMType]);
xgifb_reg_set(P3d4,
0x82,
pVBInfo->CR40[11][XGINew_RAMType]);
break;
}
xgifb_reg_set(P3d4, 0x97, 0x00);
xgifb_reg_set(P3d4, 0x98, 0x01);
xgifb_reg_set(P3d4, 0x9A, 0x02);
XGINew_DDR1x_MRS_340(P3c4, pVBInfo);
}
}
static void XGINew_DDR2_DefaultRegister(
struct xgi_hw_device_info *HwDeviceExtension,
unsigned long Port, struct vb_device_info *pVBInfo)
{
unsigned long P3d4 = Port, P3c4 = Port - 0x10;
xgifb_reg_set(P3d4, 0x82, 0x77);
xgifb_reg_set(P3d4, 0x86, 0x00);
xgifb_reg_get(P3d4, 0x86);
xgifb_reg_set(P3d4, 0x86, 0x88);
xgifb_reg_get(P3d4, 0x86);
xgifb_reg_set(P3d4, 0x86, pVBInfo->CR40[13][XGINew_RAMType]);
xgifb_reg_set(P3d4, 0x82, 0x77);
xgifb_reg_set(P3d4, 0x85, 0x00);
xgifb_reg_get(P3d4, 0x85);
xgifb_reg_set(P3d4, 0x85, 0x88);
xgifb_reg_get(P3d4, 0x85);
xgifb_reg_set(P3d4, 0x85, pVBInfo->CR40[12][XGINew_RAMType]);
if (HwDeviceExtension->jChipType == XG27)
xgifb_reg_set(P3d4, 0x82, pVBInfo->CR40[11][XGINew_RAMType]);
else
xgifb_reg_set(P3d4, 0x82, 0xA8);
xgifb_reg_set(P3d4, 0x98, 0x01);
xgifb_reg_set(P3d4, 0x9A, 0x02);
if (HwDeviceExtension->jChipType == XG27)
XGINew_DDRII_Bootup_XG27(HwDeviceExtension, P3c4, pVBInfo);
else
XGINew_DDR2_MRS_XG20(HwDeviceExtension, P3c4, pVBInfo);
}
static void XGINew_SetDRAMDefaultRegister340(
struct xgi_hw_device_info *HwDeviceExtension,
unsigned long Port, struct vb_device_info *pVBInfo)
{
unsigned char temp, temp1, temp2, temp3, i, j, k;
unsigned long P3d4 = Port, P3c4 = Port - 0x10;
xgifb_reg_set(P3d4, 0x6D, pVBInfo->CR40[8][XGINew_RAMType]);
xgifb_reg_set(P3d4, 0x68, pVBInfo->CR40[5][XGINew_RAMType]);
xgifb_reg_set(P3d4, 0x69, pVBInfo->CR40[6][XGINew_RAMType]);
xgifb_reg_set(P3d4, 0x6A, pVBInfo->CR40[7][XGINew_RAMType]);
temp2 = 0;
for (i = 0; i < 4; i++) {
temp = pVBInfo->CR6B[XGINew_RAMType][i];
for (j = 0; j < 4; j++) {
temp1 = ((temp >> (2 * j)) & 0x03) << 2;
temp2 |= temp1;
xgifb_reg_set(P3d4, 0x6B, temp2);
xgifb_reg_get(P3d4, 0x6B);
temp2 &= 0xF0;
temp2 += 0x10;
}
}
temp2 = 0;
for (i = 0; i < 4; i++) {
temp = pVBInfo->CR6E[XGINew_RAMType][i];
for (j = 0; j < 4; j++) {
temp1 = ((temp >> (2 * j)) & 0x03) << 2;
temp2 |= temp1;
xgifb_reg_set(P3d4, 0x6E, temp2);
xgifb_reg_get(P3d4, 0x6E);
temp2 &= 0xF0;
temp2 += 0x10;
}
}
temp3 = 0;
for (k = 0; k < 4; k++) {
xgifb_reg_and_or(P3d4, 0x6E, 0xFC, temp3);
temp2 = 0;
for (i = 0; i < 8; i++) {
temp = pVBInfo->CR6F[XGINew_RAMType][8 * k + i];
for (j = 0; j < 4; j++) {
temp1 = (temp >> (2 * j)) & 0x03;
temp2 |= temp1;
xgifb_reg_set(P3d4, 0x6F, temp2);
xgifb_reg_get(P3d4, 0x6F);
temp2 &= 0xF8;
temp2 += 0x08;
}
}
temp3 += 0x01;
}
xgifb_reg_set(P3d4, 0x80, pVBInfo->CR40[9][XGINew_RAMType]);
xgifb_reg_set(P3d4, 0x81, pVBInfo->CR40[10][XGINew_RAMType]);
temp2 = 0x80;
temp = pVBInfo->CR89[XGINew_RAMType][0];
for (j = 0; j < 4; j++) {
temp1 = (temp >> (2 * j)) & 0x03;
temp2 |= temp1;
xgifb_reg_set(P3d4, 0x89, temp2);
xgifb_reg_get(P3d4, 0x89);
temp2 &= 0xF0;
temp2 += 0x10;
}
temp = pVBInfo->CR89[XGINew_RAMType][1];
temp1 = temp & 0x03;
temp2 |= temp1;
xgifb_reg_set(P3d4, 0x89, temp2);
temp = pVBInfo->CR40[3][XGINew_RAMType];
temp1 = temp & 0x0F;
temp2 = (temp >> 4) & 0x07;
temp3 = temp & 0x80;
xgifb_reg_set(P3d4, 0x45, temp1);
xgifb_reg_set(P3d4, 0x99, temp2);
xgifb_reg_or(P3d4, 0x40, temp3);
xgifb_reg_set(P3d4, 0x41, pVBInfo->CR40[0][XGINew_RAMType]);
if (HwDeviceExtension->jChipType == XG27)
xgifb_reg_set(P3d4, 0x8F, *pVBInfo->pCR8F);
for (j = 0; j <= 6; j++)
xgifb_reg_set(P3d4, (0x90 + j),
pVBInfo->CR40[14 + j][XGINew_RAMType]);
for (j = 0; j <= 2; j++)
xgifb_reg_set(P3d4, (0xC3 + j),
pVBInfo->CR40[21 + j][XGINew_RAMType]);
for (j = 0; j < 2; j++)
xgifb_reg_set(P3d4, (0x8A + j),
pVBInfo->CR40[1 + j][XGINew_RAMType]);
if ((HwDeviceExtension->jChipType == XG41) ||
(HwDeviceExtension->jChipType == XG42))
xgifb_reg_set(P3d4, 0x8C, 0x87);
xgifb_reg_set(P3d4, 0x59, pVBInfo->CR40[4][XGINew_RAMType]);
xgifb_reg_set(P3d4, 0x83, 0x09);
xgifb_reg_set(P3d4, 0x87, 0x00);
xgifb_reg_set(P3d4, 0xCF, *pVBInfo->pCRCF);
if (XGINew_RAMType) {
xgifb_reg_set(P3c4, 0x17, 0x80);
if (HwDeviceExtension->jChipType == XG27)
xgifb_reg_set(P3c4, 0x17, 0x02);
} else {
xgifb_reg_set(P3c4, 0x17, 0x00);
}
xgifb_reg_set(P3c4, 0x1A, 0x87);
temp = XGINew_GetXG20DRAMType(HwDeviceExtension, pVBInfo);
if (temp == 0) {
XGINew_DDR1x_DefaultRegister(HwDeviceExtension, P3d4, pVBInfo);
} else {
xgifb_reg_set(P3d4, 0xB0, 0x80);
XGINew_DDR2_DefaultRegister(HwDeviceExtension, P3d4, pVBInfo);
}
xgifb_reg_set(P3c4, 0x1B, pVBInfo->SR15[3][XGINew_RAMType]);
}
static void XGINew_SetDRAMSizingType(int index,
unsigned short DRAMTYPE_TABLE[][5],
struct vb_device_info *pVBInfo)
{
unsigned short data;
data = DRAMTYPE_TABLE[index][4];
xgifb_reg_and_or(pVBInfo->P3c4, 0x13, 0x80, data);
udelay(15);
}
static unsigned short XGINew_SetDRAMSizeReg(int index,
unsigned short DRAMTYPE_TABLE[][5],
struct vb_device_info *pVBInfo)
{
unsigned short data = 0, memsize = 0;
int RankSize;
unsigned char ChannelNo;
RankSize = DRAMTYPE_TABLE[index][3] * XGINew_DataBusWidth / 32;
data = xgifb_reg_get(pVBInfo->P3c4, 0x13);
data &= 0x80;
if (data == 0x80)
RankSize *= 2;
data = 0;
if (XGINew_ChannelAB == 3)
ChannelNo = 4;
else
ChannelNo = XGINew_ChannelAB;
if (ChannelNo * RankSize <= 256) {
while ((RankSize >>= 1) > 0)
data += 0x10;
memsize = data >> 4;
xgifb_reg_set(pVBInfo->P3c4,
0x14,
(xgifb_reg_get(pVBInfo->P3c4, 0x14) & 0x0F) |
(data & 0xF0));
}
return memsize;
}
static unsigned short XGINew_SetDRAMSize20Reg(int index,
unsigned short DRAMTYPE_TABLE[][5],
struct vb_device_info *pVBInfo)
{
unsigned short data = 0, memsize = 0;
int RankSize;
unsigned char ChannelNo;
RankSize = DRAMTYPE_TABLE[index][3] * XGINew_DataBusWidth / 8;
data = xgifb_reg_get(pVBInfo->P3c4, 0x13);
data &= 0x80;
if (data == 0x80)
RankSize *= 2;
data = 0;
if (XGINew_ChannelAB == 3)
ChannelNo = 4;
else
ChannelNo = XGINew_ChannelAB;
if (ChannelNo * RankSize <= 256) {
while ((RankSize >>= 1) > 0)
data += 0x10;
memsize = data >> 4;
xgifb_reg_set(pVBInfo->P3c4,
0x14,
(xgifb_reg_get(pVBInfo->P3c4, 0x14) & 0x0F) |
(data & 0xF0));
udelay(15);
}
return memsize;
}
static int XGINew_ReadWriteRest(unsigned short StopAddr,
unsigned short StartAddr, struct vb_device_info *pVBInfo)
{
int i;
unsigned long Position = 0;
*((unsigned long *) (pVBInfo->FBAddr + Position)) = Position;
for (i = StartAddr; i <= StopAddr; i++) {
Position = 1 << i;
*((unsigned long *) (pVBInfo->FBAddr + Position)) = Position;
}
udelay(500);
Position = 0;
if ((*(unsigned long *) (pVBInfo->FBAddr + Position)) != Position)
return 0;
for (i = StartAddr; i <= StopAddr; i++) {
Position = 1 << i;
if ((*(unsigned long *) (pVBInfo->FBAddr + Position)) !=
Position)
return 0;
}
return 1;
}
static unsigned char XGINew_CheckFrequence(struct vb_device_info *pVBInfo)
{
unsigned char data;
data = xgifb_reg_get(pVBInfo->P3d4, 0x97);
if ((data & 0x10) == 0) {
data = xgifb_reg_get(pVBInfo->P3c4, 0x39);
data = (data & 0x02) >> 1;
return data;
} else {
return data & 0x01;
}
}
static void XGINew_CheckChannel(struct xgi_hw_device_info *HwDeviceExtension,
struct vb_device_info *pVBInfo)
{
unsigned char data;
switch (HwDeviceExtension->jChipType) {
case XG20:
case XG21:
data = xgifb_reg_get(pVBInfo->P3d4, 0x97);
data = data & 0x01;
XGINew_ChannelAB = 1;
if (data == 0) {
if ((HwDeviceExtension->ulVideoMemorySize - 1)
> 0x1000000) {
XGINew_DataBusWidth = 32;
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0xB1);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x52);
udelay(15);
if (XGINew_ReadWriteRest(24, 23, pVBInfo) == 1)
return;
if ((HwDeviceExtension->ulVideoMemorySize - 1) >
0x800000) {
xgifb_reg_set(pVBInfo->P3c4,
0x13,
0x31);
xgifb_reg_set(pVBInfo->P3c4,
0x14,
0x42);
udelay(15);
if (XGINew_ReadWriteRest(23,
23,
pVBInfo) == 1)
return;
}
}
if ((HwDeviceExtension->ulVideoMemorySize - 1) >
0x800000) {
XGINew_DataBusWidth = 16;
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0xB1);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x41);
udelay(15);
if (XGINew_ReadWriteRest(23, 22, pVBInfo) == 1)
return;
else
xgifb_reg_set(pVBInfo->P3c4,
0x13,
0x31);
udelay(15);
}
} else {
if ((HwDeviceExtension->ulVideoMemorySize - 1) >
0x800000) {
XGINew_DataBusWidth = 16;
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0xB1);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x41);
udelay(15);
if (XGINew_ReadWriteRest(23, 22, pVBInfo) == 1)
return;
if ((HwDeviceExtension->ulVideoMemorySize - 1) >
0x400000) {
xgifb_reg_set(pVBInfo->P3c4,
0x13,
0x31);
xgifb_reg_set(pVBInfo->P3c4,
0x14,
0x31);
udelay(15);
if (XGINew_ReadWriteRest(22,
22,
pVBInfo) == 1)
return;
}
}
if ((HwDeviceExtension->ulVideoMemorySize - 1) >
0x400000) {
XGINew_DataBusWidth = 8;
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0xB1);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x30);
udelay(15);
if (XGINew_ReadWriteRest(22, 21, pVBInfo) == 1)
return;
else
xgifb_reg_set(pVBInfo->P3c4,
0x13,
0x31);
udelay(15);
}
}
break;
case XG27:
XGINew_DataBusWidth = 16;
XGINew_ChannelAB = 1;
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x51);
break;
case XG41:
if (XGINew_CheckFrequence(pVBInfo) == 1) {
XGINew_DataBusWidth = 32;
XGINew_ChannelAB = 3;
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0xA1);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x4C);
if (XGINew_ReadWriteRest(25, 23, pVBInfo) == 1)
return;
XGINew_ChannelAB = 2;
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x48);
if (XGINew_ReadWriteRest(24, 23, pVBInfo) == 1)
return;
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x49);
if (XGINew_ReadWriteRest(24, 23, pVBInfo) == 1)
return;
XGINew_ChannelAB = 3;
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0x21);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x3C);
if (XGINew_ReadWriteRest(24, 23, pVBInfo) == 1)
return;
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x38);
if (XGINew_ReadWriteRest(8, 4, pVBInfo) == 1)
return;
else
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x39);
} else {
XGINew_DataBusWidth = 64;
XGINew_ChannelAB = 2;
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0xA1);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x5A);
if (XGINew_ReadWriteRest(25, 24, pVBInfo) == 1)
return;
XGINew_ChannelAB = 1;
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x52);
if (XGINew_ReadWriteRest(24, 23, pVBInfo) == 1)
return;
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x53);
if (XGINew_ReadWriteRest(24, 23, pVBInfo) == 1)
return;
XGINew_ChannelAB = 2;
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0x21);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x4A);
if (XGINew_ReadWriteRest(24, 23, pVBInfo) == 1)
return;
XGINew_ChannelAB = 1;
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x42);
if (XGINew_ReadWriteRest(8, 4, pVBInfo) == 1)
return;
else
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x43);
}
break;
case XG42:
if (XGINew_CheckFrequence(pVBInfo) == 1) {
XGINew_DataBusWidth = 32;
XGINew_ChannelAB = 2;
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0xA1);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x44);
if (XGINew_ReadWriteRest(24, 23, pVBInfo) == 1)
return;
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0x21);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x34);
if (XGINew_ReadWriteRest(23, 22, pVBInfo) == 1)
return;
XGINew_ChannelAB = 1;
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0xA1);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x40);
if (XGINew_ReadWriteRest(23, 22, pVBInfo) == 1)
return;
else {
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0x21);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x30);
}
} else {
XGINew_DataBusWidth = 64;
XGINew_ChannelAB = 1;
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0xA1);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x52);
if (XGINew_ReadWriteRest(24, 23, pVBInfo) == 1)
return;
else {
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0x21);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x42);
}
}
break;
default:
if (XGINew_CheckFrequence(pVBInfo) == 1) {
XGINew_DataBusWidth = 32;
XGINew_ChannelAB = 3;
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0xA1);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x4C);
if (XGINew_ReadWriteRest(25, 23, pVBInfo) == 1)
return;
XGINew_ChannelAB = 2;
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x48);
if (XGINew_ReadWriteRest(24, 23, pVBInfo) == 1)
return;
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0x21);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x3C);
if (XGINew_ReadWriteRest(24, 23, pVBInfo) == 1) {
XGINew_ChannelAB = 3;
} else {
XGINew_ChannelAB = 2;
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x38);
}
} else {
XGINew_DataBusWidth = 64;
XGINew_ChannelAB = 2;
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0xA1);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x5A);
if (XGINew_ReadWriteRest(25, 24, pVBInfo) == 1) {
return;
} else {
xgifb_reg_set(pVBInfo->P3c4, 0x13, 0x21);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x4A);
}
}
break;
}
}
static int XGINew_DDRSizing340(struct xgi_hw_device_info *HwDeviceExtension,
struct vb_device_info *pVBInfo)
{
int i;
unsigned short memsize, addr;
xgifb_reg_set(pVBInfo->P3c4, 0x15, 0x00);
xgifb_reg_set(pVBInfo->P3c4, 0x1C, 0x00);
XGINew_CheckChannel(HwDeviceExtension, pVBInfo);
if (HwDeviceExtension->jChipType >= XG20) {
for (i = 0; i < 12; i++) {
XGINew_SetDRAMSizingType(i,
XGINew_DDRDRAM_TYPE20,
pVBInfo);
memsize = XGINew_SetDRAMSize20Reg(i,
XGINew_DDRDRAM_TYPE20,
pVBInfo);
if (memsize == 0)
continue;
addr = memsize + (XGINew_ChannelAB - 2) + 20;
if ((HwDeviceExtension->ulVideoMemorySize - 1) <
(unsigned long) (1 << addr))
continue;
if (XGINew_ReadWriteRest(addr, 5, pVBInfo) == 1)
return 1;
}
} else {
for (i = 0; i < 4; i++) {
XGINew_SetDRAMSizingType(i,
XGINew_DDRDRAM_TYPE340,
pVBInfo);
memsize = XGINew_SetDRAMSizeReg(i,
XGINew_DDRDRAM_TYPE340,
pVBInfo);
if (memsize == 0)
continue;
addr = memsize + (XGINew_ChannelAB - 2) + 20;
if ((HwDeviceExtension->ulVideoMemorySize - 1) <
(unsigned long) (1 << addr))
continue;
if (XGINew_ReadWriteRest(addr, 9, pVBInfo) == 1)
return 1;
}
}
return 0;
}
static void XGINew_SetDRAMSize_340(struct xgi_hw_device_info *HwDeviceExtension,
struct vb_device_info *pVBInfo)
{
unsigned short data;
pVBInfo->ROMAddr = HwDeviceExtension->pjVirtualRomBase;
pVBInfo->FBAddr = HwDeviceExtension->pjVideoMemoryAddress;
XGISetModeNew(HwDeviceExtension, 0x2e);
data = xgifb_reg_get(pVBInfo->P3c4, 0x21);
xgifb_reg_set(pVBInfo->P3c4, 0x21, (unsigned short) (data & 0xDF));
XGI_DisplayOff(HwDeviceExtension, pVBInfo);
XGINew_DDRSizing340(HwDeviceExtension, pVBInfo);
data = xgifb_reg_get(pVBInfo->P3c4, 0x21);
xgifb_reg_set(pVBInfo->P3c4, 0x21, (unsigned short) (data | 0x20));
}
static void ReadVBIOSTablData(unsigned char ChipType,
struct vb_device_info *pVBInfo)
{
volatile unsigned char *pVideoMemory =
(unsigned char *) pVBInfo->ROMAddr;
unsigned long i;
unsigned char j, k;
if (ChipType == XG21) {
pVBInfo->IF_DEF_LVDS = 0;
if (pVideoMemory[0x65] & 0x1) {
pVBInfo->IF_DEF_LVDS = 1;
i = pVideoMemory[0x316] | (pVideoMemory[0x317] << 8);
j = pVideoMemory[i - 1];
if (j != 0xff) {
k = 0;
do {
pVBInfo->XG21_LVDSCapList[k].
LVDS_Capability
= pVideoMemory[i] |
(pVideoMemory[i + 1] << 8);
pVBInfo->XG21_LVDSCapList[k].LVDSHT
= pVideoMemory[i + 2] |
(pVideoMemory[i + 3] << 8);
pVBInfo->XG21_LVDSCapList[k].LVDSVT
= pVideoMemory[i + 4] |
(pVideoMemory[i + 5] << 8);
pVBInfo->XG21_LVDSCapList[k].LVDSHDE
= pVideoMemory[i + 6] |
(pVideoMemory[i + 7] << 8);
pVBInfo->XG21_LVDSCapList[k].LVDSVDE
= pVideoMemory[i + 8] |
(pVideoMemory[i + 9] << 8);
pVBInfo->XG21_LVDSCapList[k].LVDSHFP
= pVideoMemory[i + 10] |
(pVideoMemory[i + 11] << 8);
pVBInfo->XG21_LVDSCapList[k].LVDSVFP
= pVideoMemory[i + 12] |
(pVideoMemory[i + 13] << 8);
pVBInfo->XG21_LVDSCapList[k].LVDSHSYNC
= pVideoMemory[i + 14] |
(pVideoMemory[i + 15] << 8);
pVBInfo->XG21_LVDSCapList[k].LVDSVSYNC
= pVideoMemory[i + 16] |
(pVideoMemory[i + 17] << 8);
pVBInfo->XG21_LVDSCapList[k].VCLKData1
= pVideoMemory[i + 18];
pVBInfo->XG21_LVDSCapList[k].VCLKData2
= pVideoMemory[i + 19];
pVBInfo->XG21_LVDSCapList[k].PSC_S1
= pVideoMemory[i + 20];
pVBInfo->XG21_LVDSCapList[k].PSC_S2
= pVideoMemory[i + 21];
pVBInfo->XG21_LVDSCapList[k].PSC_S3
= pVideoMemory[i + 22];
pVBInfo->XG21_LVDSCapList[k].PSC_S4
= pVideoMemory[i + 23];
pVBInfo->XG21_LVDSCapList[k].PSC_S5
= pVideoMemory[i + 24];
i += 25;
j--;
k++;
} while ((j > 0) &&
(k < (sizeof(XGI21_LCDCapList) /
sizeof(struct
XGI21_LVDSCapStruct))));
} else {
pVBInfo->XG21_LVDSCapList[0].LVDS_Capability
= pVideoMemory[i] |
(pVideoMemory[i + 1] << 8);
pVBInfo->XG21_LVDSCapList[0].LVDSHT
= pVideoMemory[i + 2] |
(pVideoMemory[i + 3] << 8);
pVBInfo->XG21_LVDSCapList[0].LVDSVT
= pVideoMemory[i + 4] |
(pVideoMemory[i + 5] << 8);
pVBInfo->XG21_LVDSCapList[0].LVDSHDE
= pVideoMemory[i + 6] |
(pVideoMemory[i + 7] << 8);
pVBInfo->XG21_LVDSCapList[0].LVDSVDE
= pVideoMemory[i + 8] |
(pVideoMemory[i + 9] << 8);
pVBInfo->XG21_LVDSCapList[0].LVDSHFP
= pVideoMemory[i + 10] |
(pVideoMemory[i + 11] << 8);
pVBInfo->XG21_LVDSCapList[0].LVDSVFP
= pVideoMemory[i + 12] |
(pVideoMemory[i + 13] << 8);
pVBInfo->XG21_LVDSCapList[0].LVDSHSYNC
= pVideoMemory[i + 14] |
(pVideoMemory[i + 15] << 8);
pVBInfo->XG21_LVDSCapList[0].LVDSVSYNC
= pVideoMemory[i + 16] |
(pVideoMemory[i + 17] << 8);
pVBInfo->XG21_LVDSCapList[0].VCLKData1
= pVideoMemory[i + 18];
pVBInfo->XG21_LVDSCapList[0].VCLKData2
= pVideoMemory[i + 19];
pVBInfo->XG21_LVDSCapList[0].PSC_S1
= pVideoMemory[i + 20];
pVBInfo->XG21_LVDSCapList[0].PSC_S2
= pVideoMemory[i + 21];
pVBInfo->XG21_LVDSCapList[0].PSC_S3
= pVideoMemory[i + 22];
pVBInfo->XG21_LVDSCapList[0].PSC_S4
= pVideoMemory[i + 23];
pVBInfo->XG21_LVDSCapList[0].PSC_S5
= pVideoMemory[i + 24];
}
}
}
}
static void XGINew_ChkSenseStatus(struct xgi_hw_device_info *HwDeviceExtension,
struct vb_device_info *pVBInfo)
{
unsigned short tempbx = 0, temp, tempcx, CR3CData;
temp = xgifb_reg_get(pVBInfo->P3d4, 0x32);
if (temp & Monitor1Sense)
tempbx |= ActiveCRT1;
if (temp & LCDSense)
tempbx |= ActiveLCD;
if (temp & Monitor2Sense)
tempbx |= ActiveCRT2;
if (temp & TVSense) {
tempbx |= ActiveTV;
if (temp & AVIDEOSense)
tempbx |= (ActiveAVideo << 8);
if (temp & SVIDEOSense)
tempbx |= (ActiveSVideo << 8);
if (temp & SCARTSense)
tempbx |= (ActiveSCART << 8);
if (temp & HiTVSense)
tempbx |= (ActiveHiTV << 8);
if (temp & YPbPrSense)
tempbx |= (ActiveYPbPr << 8);
}
tempcx = xgifb_reg_get(pVBInfo->P3d4, 0x3d);
tempcx |= (xgifb_reg_get(pVBInfo->P3d4, 0x3e) << 8);
if (tempbx & tempcx) {
CR3CData = xgifb_reg_get(pVBInfo->P3d4, 0x3c);
if (!(CR3CData & DisplayDeviceFromCMOS)) {
tempcx = 0x1FF0;
if (*pVBInfo->pSoftSetting & ModeSoftSetting)
tempbx = 0x1FF0;
}
} else {
tempcx = 0x1FF0;
if (*pVBInfo->pSoftSetting & ModeSoftSetting)
tempbx = 0x1FF0;
}
tempbx &= tempcx;
xgifb_reg_set(pVBInfo->P3d4, 0x3d, (tempbx & 0x00FF));
xgifb_reg_set(pVBInfo->P3d4, 0x3e, ((tempbx & 0xFF00) >> 8));
}
static void XGINew_SetModeScratch(struct xgi_hw_device_info *HwDeviceExtension,
struct vb_device_info *pVBInfo)
{
unsigned short temp, tempcl = 0, tempch = 0, CR31Data, CR38Data;
temp = xgifb_reg_get(pVBInfo->P3d4, 0x3d);
temp |= xgifb_reg_get(pVBInfo->P3d4, 0x3e) << 8;
temp |= (xgifb_reg_get(pVBInfo->P3d4, 0x31) & (DriverMode >> 8)) << 8;
if (pVBInfo->IF_DEF_CRT2Monitor == 1) {
if (temp & ActiveCRT2)
tempcl = SetCRT2ToRAMDAC;
}
if (temp & ActiveLCD) {
tempcl |= SetCRT2ToLCD;
if (temp & DriverMode) {
if (temp & ActiveTV) {
tempch = SetToLCDA | EnableDualEdge;
temp ^= SetCRT2ToLCD;
if ((temp >> 8) & ActiveAVideo)
tempcl |= SetCRT2ToAVIDEO;
if ((temp >> 8) & ActiveSVideo)
tempcl |= SetCRT2ToSVIDEO;
if ((temp >> 8) & ActiveSCART)
tempcl |= SetCRT2ToSCART;
if (pVBInfo->IF_DEF_HiVision == 1) {
if ((temp >> 8) & ActiveHiTV)
tempcl |= SetCRT2ToHiVisionTV;
}
if (pVBInfo->IF_DEF_YPbPr == 1) {
if ((temp >> 8) & ActiveYPbPr)
tempch |= SetYPbPr;
}
}
}
} else {
if ((temp >> 8) & ActiveAVideo)
tempcl |= SetCRT2ToAVIDEO;
if ((temp >> 8) & ActiveSVideo)
tempcl |= SetCRT2ToSVIDEO;
if ((temp >> 8) & ActiveSCART)
tempcl |= SetCRT2ToSCART;
if (pVBInfo->IF_DEF_HiVision == 1) {
if ((temp >> 8) & ActiveHiTV)
tempcl |= SetCRT2ToHiVisionTV;
}
if (pVBInfo->IF_DEF_YPbPr == 1) {
if ((temp >> 8) & ActiveYPbPr)
tempch |= SetYPbPr;
}
}
tempcl |= SetSimuScanMode;
if ((!(temp & ActiveCRT1)) && ((temp & ActiveLCD) || (temp & ActiveTV)
|| (temp & ActiveCRT2)))
tempcl ^= (SetSimuScanMode | SwitchToCRT2);
if ((temp & ActiveLCD) && (temp & ActiveTV))
tempcl ^= (SetSimuScanMode | SwitchToCRT2);
xgifb_reg_set(pVBInfo->P3d4, 0x30, tempcl);
CR31Data = xgifb_reg_get(pVBInfo->P3d4, 0x31);
CR31Data &= ~(SetNotSimuMode >> 8);
if (!(temp & ActiveCRT1))
CR31Data |= (SetNotSimuMode >> 8);
CR31Data &= ~(DisableCRT2Display >> 8);
if (!((temp & ActiveLCD) || (temp & ActiveTV) || (temp & ActiveCRT2)))
CR31Data |= (DisableCRT2Display >> 8);
xgifb_reg_set(pVBInfo->P3d4, 0x31, CR31Data);
CR38Data = xgifb_reg_get(pVBInfo->P3d4, 0x38);
CR38Data &= ~SetYPbPr;
CR38Data |= tempch;
xgifb_reg_set(pVBInfo->P3d4, 0x38, CR38Data);
}
static void XGINew_GetXG21Sense(struct xgi_hw_device_info *HwDeviceExtension,
struct vb_device_info *pVBInfo)
{
unsigned char Temp;
volatile unsigned char *pVideoMemory =
(unsigned char *) pVBInfo->ROMAddr;
pVBInfo->IF_DEF_LVDS = 0;
#if 1
if ((pVideoMemory[0x65] & 0x01)) {
pVBInfo->IF_DEF_LVDS = 1;
xgifb_reg_or(pVBInfo->P3d4, 0x32, LCDSense);
xgifb_reg_and_or(pVBInfo->P3d4, 0x38, ~0xE0, 0xC0);
} else {
#endif
xgifb_reg_and_or(pVBInfo->P3d4, 0x4A, ~0x03, 0x03);
Temp = xgifb_reg_get(pVBInfo->P3d4, 0x48) & 0xC0;
if (Temp == 0xC0) {
XGINew_SenseLCD(HwDeviceExtension, pVBInfo);
xgifb_reg_or(pVBInfo->P3d4, 0x32, LCDSense);
xgifb_reg_and_or(pVBInfo->P3d4, 0x4A, ~0x20, 0x20);
Temp = xgifb_reg_get(pVBInfo->P3d4, 0x48) & 0x04;
if (!Temp)
xgifb_reg_and_or(pVBInfo->P3d4,
0x38,
~0xE0,
0x80);
else
xgifb_reg_and_or(pVBInfo->P3d4,
0x38,
~0xE0,
0xA0);
xgifb_reg_and(pVBInfo->P3d4, 0x4A, ~0x20);
}
#if 1
}
#endif
}
static void XGINew_GetXG27Sense(struct xgi_hw_device_info *HwDeviceExtension,
struct vb_device_info *pVBInfo)
{
unsigned char Temp, bCR4A;
pVBInfo->IF_DEF_LVDS = 0;
bCR4A = xgifb_reg_get(pVBInfo->P3d4, 0x4A);
xgifb_reg_and_or(pVBInfo->P3d4, 0x4A, ~0x07, 0x07);
Temp = xgifb_reg_get(pVBInfo->P3d4, 0x48) & 0x07;
xgifb_reg_set(pVBInfo->P3d4, 0x4A, bCR4A);
if (Temp <= 0x02) {
pVBInfo->IF_DEF_LVDS = 1;
xgifb_reg_and_or(pVBInfo->P3d4, 0x38, ~0xE0, 0xC0);
xgifb_reg_set(pVBInfo->P3d4, 0x30, 0x21);
} else {
xgifb_reg_and_or(pVBInfo->P3d4, 0x38, ~0xE0, 0xA0);
}
xgifb_reg_or(pVBInfo->P3d4, 0x32, LCDSense);
}
static unsigned char GetXG21FPBits(struct vb_device_info *pVBInfo)
{
unsigned char CR38, CR4A, temp;
CR4A = xgifb_reg_get(pVBInfo->P3d4, 0x4A);
xgifb_reg_and_or(pVBInfo->P3d4, 0x4A, ~0x10, 0x10);
CR38 = xgifb_reg_get(pVBInfo->P3d4, 0x38);
temp = 0;
if ((CR38 & 0xE0) > 0x80) {
temp = xgifb_reg_get(pVBInfo->P3d4, 0x48);
temp &= 0x08;
temp >>= 3;
}
xgifb_reg_set(pVBInfo->P3d4, 0x4A, CR4A);
return temp;
}
static unsigned char GetXG27FPBits(struct vb_device_info *pVBInfo)
{
unsigned char CR4A, temp;
CR4A = xgifb_reg_get(pVBInfo->P3d4, 0x4A);
xgifb_reg_and_or(pVBInfo->P3d4, 0x4A, ~0x03, 0x03);
temp = xgifb_reg_get(pVBInfo->P3d4, 0x48);
if (temp <= 2)
temp &= 0x03;
else
temp = ((temp & 0x04) >> 1) || ((~temp) & 0x01);
xgifb_reg_set(pVBInfo->P3d4, 0x4A, CR4A);
return temp;
}
unsigned char XGIInitNew(struct xgi_hw_device_info *HwDeviceExtension)
{
struct vb_device_info VBINF;
struct vb_device_info *pVBInfo = &VBINF;
unsigned char i, temp = 0, temp1;
volatile unsigned char *pVideoMemory;
unsigned long Temp;
pVBInfo->ROMAddr = HwDeviceExtension->pjVirtualRomBase;
pVBInfo->FBAddr = HwDeviceExtension->pjVideoMemoryAddress;
pVBInfo->BaseAddr = (unsigned long) HwDeviceExtension->pjIOAddress;
pVideoMemory = (unsigned char *) pVBInfo->ROMAddr;
if (pVBInfo->FBAddr == NULL) {
printk("\n pVBInfo->FBAddr == 0 ");
return 0;
}
printk("1");
if (pVBInfo->BaseAddr == 0) {
printk("\npVBInfo->BaseAddr == 0 ");
return 0;
}
printk("2");
outb(0x67, (pVBInfo->BaseAddr + 0x12));
pVBInfo->ISXPDOS = 0;
printk("3");
printk("4");
pVBInfo->P3c4 = pVBInfo->BaseAddr + 0x14;
pVBInfo->P3d4 = pVBInfo->BaseAddr + 0x24;
pVBInfo->P3c0 = pVBInfo->BaseAddr + 0x10;
pVBInfo->P3ce = pVBInfo->BaseAddr + 0x1e;
pVBInfo->P3c2 = pVBInfo->BaseAddr + 0x12;
pVBInfo->P3ca = pVBInfo->BaseAddr + 0x1a;
pVBInfo->P3c6 = pVBInfo->BaseAddr + 0x16;
pVBInfo->P3c7 = pVBInfo->BaseAddr + 0x17;
pVBInfo->P3c8 = pVBInfo->BaseAddr + 0x18;
pVBInfo->P3c9 = pVBInfo->BaseAddr + 0x19;
pVBInfo->P3da = pVBInfo->BaseAddr + 0x2A;
pVBInfo->Part0Port = pVBInfo->BaseAddr + XGI_CRT2_PORT_00;
pVBInfo->Part1Port = pVBInfo->BaseAddr + XGI_CRT2_PORT_04;
pVBInfo->Part2Port = pVBInfo->BaseAddr + XGI_CRT2_PORT_10;
pVBInfo->Part3Port = pVBInfo->BaseAddr + XGI_CRT2_PORT_12;
pVBInfo->Part4Port = pVBInfo->BaseAddr + XGI_CRT2_PORT_14;
pVBInfo->Part5Port = pVBInfo->BaseAddr + XGI_CRT2_PORT_14 + 2;
printk("5");
if (HwDeviceExtension->jChipType < XG20)
XGI_GetVBType(pVBInfo);
InitTo330Pointer(HwDeviceExtension->jChipType, pVBInfo);
ReadVBIOSTablData(HwDeviceExtension->jChipType, pVBInfo);
xgifb_reg_set(pVBInfo->P3c4, 0x05, 0x86);
printk("6");
if (HwDeviceExtension->jChipType == XG21)
XGINew_GetXG21Sense(HwDeviceExtension, pVBInfo);
if (HwDeviceExtension->jChipType == XG27)
XGINew_GetXG27Sense(HwDeviceExtension, pVBInfo);
printk("7");
for (i = 0x06; i < 0x20; i++)
xgifb_reg_set(pVBInfo->P3c4, i, 0);
for (i = 0x21; i <= 0x27; i++)
xgifb_reg_set(pVBInfo->P3c4, i, 0);
printk("8");
for (i = 0x31; i <= 0x3B; i++)
xgifb_reg_set(pVBInfo->P3c4, i, 0);
printk("9");
if (HwDeviceExtension->jChipType == XG42)
xgifb_reg_set(pVBInfo->P3c4, 0x3B, 0xC0);
for (i = 0x79; i <= 0x7C; i++)
xgifb_reg_set(pVBInfo->P3d4, i, 0);
printk("10");
if (HwDeviceExtension->jChipType >= XG20)
xgifb_reg_set(pVBInfo->P3d4, 0x97, *pVBInfo->pXGINew_CR97);
printk("11");
xgifb_reg_set(pVBInfo->P3c4, 0x07, *pVBInfo->pSR07);
if (HwDeviceExtension->jChipType == XG27) {
xgifb_reg_set(pVBInfo->P3c4, 0x40, *pVBInfo->pSR40);
xgifb_reg_set(pVBInfo->P3c4, 0x41, *pVBInfo->pSR41);
}
xgifb_reg_set(pVBInfo->P3c4, 0x11, 0x0F);
xgifb_reg_set(pVBInfo->P3c4, 0x1F, *pVBInfo->pSR1F);
xgifb_reg_set(pVBInfo->P3c4, 0x20, 0xA0);
xgifb_reg_set(pVBInfo->P3c4, 0x36, 0x70);
if (HwDeviceExtension->jChipType == XG27)
xgifb_reg_set(pVBInfo->P3c4, 0x36, *pVBInfo->pSR36);
printk("12");
if (HwDeviceExtension->jChipType < XG20) {
printk("13");
for (i = 0x47; i <= 0x4C; i++)
xgifb_reg_set(pVBInfo->P3d4,
i,
pVBInfo->AGPReg[i - 0x47]);
for (i = 0x70; i <= 0x71; i++)
xgifb_reg_set(pVBInfo->P3d4,
i,
pVBInfo->AGPReg[6 + i - 0x70]);
for (i = 0x74; i <= 0x77; i++)
xgifb_reg_set(pVBInfo->P3d4,
i,
pVBInfo->AGPReg[8 + i - 0x74]);
HwDeviceExtension->pQueryVGAConfigSpace(HwDeviceExtension,
0x50,
0,
&Temp);
Temp >>= 20;
Temp &= 0xF;
if (Temp == 1)
xgifb_reg_set(pVBInfo->P3d4, 0x48, 0x20);
printk("14");
}
xgifb_reg_set(pVBInfo->P3c4, 0x23, *pVBInfo->pSR23);
xgifb_reg_set(pVBInfo->P3c4, 0x24, *pVBInfo->pSR24);
xgifb_reg_set(pVBInfo->P3c4, 0x25, pVBInfo->SR25[0]);
printk("15");
if (HwDeviceExtension->jChipType < XG20) {
XGI_UnLockCRT2(HwDeviceExtension, pVBInfo);
xgifb_reg_and_or(pVBInfo->Part0Port, 0x3F, 0xEF, 0x00);
xgifb_reg_set(pVBInfo->Part1Port, 0x00, 0x00);
temp1 = (unsigned char) xgifb_reg_get(pVBInfo->P3d4, 0x7B);
temp = (unsigned char) ((temp1 >> 4) & 0x0F);
xgifb_reg_set(pVBInfo->Part1Port,
0x02,
(*pVBInfo->pCRT2Data_1_2));
printk("16");
xgifb_reg_set(pVBInfo->Part1Port, 0x2E, 0x08);
}
xgifb_reg_set(pVBInfo->P3c4, 0x27, 0x1F);
if ((HwDeviceExtension->jChipType == XG42) &&
XGINew_GetXG20DRAMType(HwDeviceExtension, pVBInfo) != 0) {
xgifb_reg_set(pVBInfo->P3c4,
0x31,
(*pVBInfo->pSR31 & 0x3F) | 0x40);
xgifb_reg_set(pVBInfo->P3c4,
0x32,
(*pVBInfo->pSR32 & 0xFC) | 0x01);
} else {
xgifb_reg_set(pVBInfo->P3c4, 0x31, *pVBInfo->pSR31);
xgifb_reg_set(pVBInfo->P3c4, 0x32, *pVBInfo->pSR32);
}
xgifb_reg_set(pVBInfo->P3c4, 0x33, *pVBInfo->pSR33);
printk("17");
if (HwDeviceExtension->jChipType < XG20) {
if (XGI_BridgeIsOn(pVBInfo) == 1) {
if (pVBInfo->IF_DEF_LVDS == 0) {
xgifb_reg_set(pVBInfo->Part2Port, 0x00, 0x1C);
xgifb_reg_set(pVBInfo->Part4Port,
0x0D,
*pVBInfo->pCRT2Data_4_D);
xgifb_reg_set(pVBInfo->Part4Port,
0x0E,
*pVBInfo->pCRT2Data_4_E);
xgifb_reg_set(pVBInfo->Part4Port,
0x10,
*pVBInfo->pCRT2Data_4_10);
xgifb_reg_set(pVBInfo->Part4Port, 0x0F, 0x3F);
}
XGI_LockCRT2(HwDeviceExtension, pVBInfo);
}
}
printk("18");
printk("181");
printk("182");
XGI_SenseCRT1(pVBInfo);
printk("183");
pVBInfo->IF_DEF_CH7007 = 0;
if ((HwDeviceExtension->jChipType == XG21) &&
(pVBInfo->IF_DEF_CH7007)) {
printk("184");
XGI_GetSenseStatus(HwDeviceExtension, pVBInfo);
printk("185");
}
if (HwDeviceExtension->jChipType == XG21) {
printk("186");
xgifb_reg_and_or(pVBInfo->P3d4,
0x32,
~Monitor1Sense,
Monitor1Sense);
temp = GetXG21FPBits(pVBInfo);
xgifb_reg_and_or(pVBInfo->P3d4, 0x37, ~0x01, temp);
printk("187");
}
if (HwDeviceExtension->jChipType == XG27) {
xgifb_reg_and_or(pVBInfo->P3d4,
0x32,
~Monitor1Sense,
Monitor1Sense);
temp = GetXG27FPBits(pVBInfo);
xgifb_reg_and_or(pVBInfo->P3d4, 0x37, ~0x03, temp);
}
printk("19");
XGINew_RAMType = (int) XGINew_GetXG20DRAMType(HwDeviceExtension,
pVBInfo);
XGINew_SetDRAMDefaultRegister340(HwDeviceExtension,
pVBInfo->P3d4,
pVBInfo);
printk("20");
XGINew_SetDRAMSize_340(HwDeviceExtension, pVBInfo);
printk("21");
printk("22");
xgifb_reg_set(pVBInfo->P3c4,
0x22,
(unsigned char) ((*pVBInfo->pSR22) & 0xFE));
xgifb_reg_set(pVBInfo->P3c4, 0x21, *pVBInfo->pSR21);
printk("23");
XGINew_ChkSenseStatus(HwDeviceExtension, pVBInfo);
XGINew_SetModeScratch(HwDeviceExtension, pVBInfo);
printk("24");
xgifb_reg_set(pVBInfo->P3d4, 0x8c, 0x87);
xgifb_reg_set(pVBInfo->P3c4, 0x14, 0x31);
printk("25");
return 1;
}
