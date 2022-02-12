static void xor_128(u8 *a, u8 *b, u8 *out)
{
u32 *dwPtrA = (u32 *) a;
u32 *dwPtrB = (u32 *) b;
u32 *dwPtrOut = (u32 *) out;
(*dwPtrOut++) = (*dwPtrA++) ^ (*dwPtrB++);
(*dwPtrOut++) = (*dwPtrA++) ^ (*dwPtrB++);
(*dwPtrOut++) = (*dwPtrA++) ^ (*dwPtrB++);
(*dwPtrOut++) = (*dwPtrA++) ^ (*dwPtrB++);
}
static void xor_32(u8 *a, u8 *b, u8 *out)
{
u32 *dwPtrA = (u32 *) a;
u32 *dwPtrB = (u32 *) b;
u32 *dwPtrOut = (u32 *) out;
(*dwPtrOut++) = (*dwPtrA++) ^ (*dwPtrB++);
}
static void AddRoundKey(u8 *key, int round)
{
u8 sbox_key[4];
u8 rcon_table[10] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36};
sbox_key[0] = sbox_table[key[13]];
sbox_key[1] = sbox_table[key[14]];
sbox_key[2] = sbox_table[key[15]];
sbox_key[3] = sbox_table[key[12]];
key[0] = key[0] ^ rcon_table[round];
xor_32(&key[0], sbox_key, &key[0]);
xor_32(&key[4], &key[0], &key[4]);
xor_32(&key[8], &key[4], &key[8]);
xor_32(&key[12], &key[8], &key[12]);
}
static void SubBytes(u8 *in, u8 *out)
{
int i;
for (i = 0; i < 16; i++)
out[i] = sbox_table[in[i]];
}
static void ShiftRows(u8 *in, u8 *out)
{
out[0] = in[0];
out[1] = in[5];
out[2] = in[10];
out[3] = in[15];
out[4] = in[4];
out[5] = in[9];
out[6] = in[14];
out[7] = in[3];
out[8] = in[8];
out[9] = in[13];
out[10] = in[2];
out[11] = in[7];
out[12] = in[12];
out[13] = in[1];
out[14] = in[6];
out[15] = in[11];
}
static void MixColumns(u8 *in, u8 *out)
{
out[0] = dot2_table[in[0]] ^ dot3_table[in[1]] ^ in[2] ^ in[3];
out[1] = in[0] ^ dot2_table[in[1]] ^ dot3_table[in[2]] ^ in[3];
out[2] = in[0] ^ in[1] ^ dot2_table[in[2]] ^ dot3_table[in[3]];
out[3] = dot3_table[in[0]] ^ in[1] ^ in[2] ^ dot2_table[in[3]];
}
static void AESv128(u8 *key, u8 *data, u8 *ciphertext)
{
int i;
int round;
u8 TmpdataA[16];
u8 TmpdataB[16];
u8 abyRoundKey[16];
for (i = 0; i < 16; i++)
abyRoundKey[i] = key[i];
for (round = 0; round < 11; round++) {
if (round == 0) {
xor_128(abyRoundKey, data, ciphertext);
AddRoundKey(abyRoundKey, round);
} else if (round == 10) {
SubBytes(ciphertext, TmpdataA);
ShiftRows(TmpdataA, TmpdataB);
xor_128(TmpdataB, abyRoundKey, ciphertext);
} else {
SubBytes(ciphertext, TmpdataA);
ShiftRows(TmpdataA, TmpdataB);
MixColumns(&TmpdataB[0], &TmpdataA[0]);
MixColumns(&TmpdataB[4], &TmpdataA[4]);
MixColumns(&TmpdataB[8], &TmpdataA[8]);
MixColumns(&TmpdataB[12], &TmpdataA[12]);
xor_128(TmpdataA, abyRoundKey, ciphertext);
AddRoundKey(abyRoundKey, round);
}
}
}
bool AESbGenCCMP(u8 *pbyRxKey, u8 *pbyFrame, u16 wFrameSize)
{
u8 abyNonce[13];
u8 MIC_IV[16];
u8 MIC_HDR1[16];
u8 MIC_HDR2[16];
u8 abyMIC[16];
u8 abyCTRPLD[16];
u8 abyTmp[16];
u8 abyPlainText[16];
u8 abyLastCipher[16];
struct ieee80211_hdr *pMACHeader = (struct ieee80211_hdr *) pbyFrame;
u8 *pbyIV;
u8 *pbyPayload;
u16 wHLen = 22;
u16 wPayloadSize = wFrameSize - 8 - 8 - 4 - WLAN_HDR_ADDR3_LEN;
bool bA4 = false;
u8 byTmp;
u16 wCnt;
int ii, jj, kk;
pbyIV = pbyFrame + WLAN_HDR_ADDR3_LEN;
if (WLAN_GET_FC_TODS(*(u16 *) pbyFrame) &&
WLAN_GET_FC_FROMDS(*(u16 *) pbyFrame)) {
bA4 = true;
pbyIV += 6;
wHLen += 6;
wPayloadSize -= 6;
}
pbyPayload = pbyIV + 8;
abyNonce[0] = 0x00;
memcpy(&(abyNonce[1]), pMACHeader->addr2, ETH_ALEN);
abyNonce[7] = pbyIV[7];
abyNonce[8] = pbyIV[6];
abyNonce[9] = pbyIV[5];
abyNonce[10] = pbyIV[4];
abyNonce[11] = pbyIV[1];
abyNonce[12] = pbyIV[0];
MIC_IV[0] = 0x59;
memcpy(&(MIC_IV[1]), &(abyNonce[0]), 13);
MIC_IV[14] = (u8)(wPayloadSize >> 8);
MIC_IV[15] = (u8)(wPayloadSize & 0xff);
MIC_HDR1[0] = (u8)(wHLen >> 8);
MIC_HDR1[1] = (u8)(wHLen & 0xff);
byTmp = (u8)(pMACHeader->frame_control & 0xff);
MIC_HDR1[2] = byTmp & 0x8f;
byTmp = (u8)(pMACHeader->frame_control >> 8);
byTmp &= 0x87;
MIC_HDR1[3] = byTmp | 0x40;
memcpy(&(MIC_HDR1[4]), pMACHeader->addr1, ETH_ALEN);
memcpy(&(MIC_HDR1[10]), pMACHeader->addr2, ETH_ALEN);
memcpy(&(MIC_HDR2[0]), pMACHeader->addr3, ETH_ALEN);
byTmp = (u8)(pMACHeader->seq_ctrl & 0xff);
MIC_HDR2[6] = byTmp & 0x0f;
MIC_HDR2[7] = 0;
if (bA4) {
memcpy(&(MIC_HDR2[8]), pMACHeader->addr4, ETH_ALEN);
} else {
MIC_HDR2[8] = 0x00;
MIC_HDR2[9] = 0x00;
MIC_HDR2[10] = 0x00;
MIC_HDR2[11] = 0x00;
MIC_HDR2[12] = 0x00;
MIC_HDR2[13] = 0x00;
}
MIC_HDR2[14] = 0x00;
MIC_HDR2[15] = 0x00;
AESv128(pbyRxKey, MIC_IV, abyMIC);
for (kk = 0; kk < 16; kk++)
abyTmp[kk] = MIC_HDR1[kk] ^ abyMIC[kk];
AESv128(pbyRxKey, abyTmp, abyMIC);
for (kk = 0; kk < 16; kk++)
abyTmp[kk] = MIC_HDR2[kk] ^ abyMIC[kk];
AESv128(pbyRxKey, abyTmp, abyMIC);
wCnt = 1;
abyCTRPLD[0] = 0x01;
memcpy(&(abyCTRPLD[1]), &(abyNonce[0]), 13);
for (jj = wPayloadSize; jj > 16; jj = jj-16) {
abyCTRPLD[14] = (u8) (wCnt >> 8);
abyCTRPLD[15] = (u8) (wCnt & 0xff);
AESv128(pbyRxKey, abyCTRPLD, abyTmp);
for (kk = 0; kk < 16; kk++)
abyPlainText[kk] = abyTmp[kk] ^ pbyPayload[kk];
for (kk = 0; kk < 16; kk++)
abyTmp[kk] = abyMIC[kk] ^ abyPlainText[kk];
AESv128(pbyRxKey, abyTmp, abyMIC);
memcpy(pbyPayload, abyPlainText, 16);
wCnt++;
pbyPayload += 16;
}
memcpy(&(abyLastCipher[0]), pbyPayload, jj);
for (ii = jj; ii < 16; ii++)
abyLastCipher[ii] = 0x00;
abyCTRPLD[14] = (u8) (wCnt >> 8);
abyCTRPLD[15] = (u8) (wCnt & 0xff);
AESv128(pbyRxKey, abyCTRPLD, abyTmp);
for (kk = 0; kk < 16; kk++)
abyPlainText[kk] = abyTmp[kk] ^ abyLastCipher[kk];
memcpy(pbyPayload, abyPlainText, jj);
pbyPayload += jj;
for (ii = jj; ii < 16; ii++)
abyPlainText[ii] = 0x00;
for (kk = 0; kk < 16; kk++)
abyTmp[kk] = abyMIC[kk] ^ abyPlainText[kk];
AESv128(pbyRxKey, abyTmp, abyMIC);
wCnt = 0;
abyCTRPLD[14] = (u8) (wCnt >> 8);
abyCTRPLD[15] = (u8) (wCnt & 0xff);
AESv128(pbyRxKey, abyCTRPLD, abyTmp);
for (kk = 0; kk < 8; kk++)
abyTmp[kk] = abyTmp[kk] ^ pbyPayload[kk];
if (!memcmp(abyMIC, abyTmp, 8))
return true;
else
return false;
}
