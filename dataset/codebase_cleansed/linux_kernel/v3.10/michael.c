static void s_vClear(void)
{
L = K0;
R = K1;
nBytesInM = 0;
M = 0;
}
static void s_vSetKey(u32 dwK0, u32 dwK1)
{
K0 = dwK0;
K1 = dwK1;
s_vClear();
}
static void s_vAppendByte(u8 b)
{
M |= b << (8*nBytesInM);
nBytesInM++;
if (nBytesInM >= 4) {
L ^= M;
R ^= ROL32(L, 17);
L += R;
R ^= ((L & 0xff00ff00) >> 8) | ((L & 0x00ff00ff) << 8);
L += R;
R ^= ROL32(L, 3);
L += R;
R ^= ROR32(L, 2);
L += R;
M = 0;
nBytesInM = 0;
}
}
void MIC_vInit(u32 dwK0, u32 dwK1)
{
s_vSetKey(dwK0, dwK1);
}
void MIC_vUnInit(void)
{
K0 = 0;
K1 = 0;
s_vClear();
}
void MIC_vAppend(u8 * src, unsigned int nBytes)
{
while (nBytes > 0) {
s_vAppendByte(*src++);
nBytes--;
}
}
void MIC_vGetMIC(u32 * pdwL, u32 * pdwR)
{
s_vAppendByte(0x5a);
s_vAppendByte(0);
s_vAppendByte(0);
s_vAppendByte(0);
s_vAppendByte(0);
while (nBytesInM != 0)
s_vAppendByte(0);
*pdwL = L;
*pdwR = R;
s_vClear();
}
