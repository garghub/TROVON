static void xor_128(BYTE *a, BYTE *b, BYTE *out)
{
PDWORD dwPtrA = (PDWORD) a;
PDWORD dwPtrB = (PDWORD) b;
PDWORD dwPtrOut = (PDWORD) out;
(*dwPtrOut++) = (*dwPtrA++) ^ (*dwPtrB++);
(*dwPtrOut++) = (*dwPtrA++) ^ (*dwPtrB++);
(*dwPtrOut++) = (*dwPtrA++) ^ (*dwPtrB++);
(*dwPtrOut++) = (*dwPtrA++) ^ (*dwPtrB++);
}
static void xor_32(BYTE *a, BYTE *b, BYTE *out)
{
PDWORD dwPtrA = (PDWORD) a;
PDWORD dwPtrB = (PDWORD) b;
PDWORD dwPtrOut = (PDWORD) out;
(*dwPtrOut++) = (*dwPtrA++) ^ (*dwPtrB++);
}
void AddRoundKey(BYTE *key, int round)
{
BYTE sbox_key[4];
BYTE rcon_table[10] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36};
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
void SubBytes(BYTE *in, BYTE *out)
{
int i;
for (i = 0; i < 16; i++)
out[i] = sbox_table[in[i]];
}
void ShiftRows(BYTE *in, BYTE *out)
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
void MixColumns(BYTE *in, BYTE *out)
{
out[0] = dot2_table[in[0]] ^ dot3_table[in[1]] ^ in[2] ^ in[3];
out[1] = in[0] ^ dot2_table[in[1]] ^ dot3_table[in[2]] ^ in[3];
out[2] = in[0] ^ in[1] ^ dot2_table[in[2]] ^ dot3_table[in[3]];
out[3] = dot3_table[in[0]] ^ in[1] ^ in[2] ^ dot2_table[in[3]];
}
void AESv128(BYTE *key, BYTE *data, BYTE *ciphertext)
{
int i;
int round;
BYTE TmpdataA[16];
BYTE TmpdataB[16];
BYTE abyRoundKey[16];
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
BOOL AESbGenCCMP(PBYTE pbyRxKey, PBYTE pbyFrame, WORD wFrameSize)
{
BYTE abyNonce[13];
BYTE MIC_IV[16];
BYTE MIC_HDR1[16];
BYTE MIC_HDR2[16];
BYTE abyMIC[16];
BYTE abyCTRPLD[16];
BYTE abyTmp[16];
BYTE abyPlainText[16];
BYTE abyLastCipher[16];
PS802_11Header pMACHeader = (PS802_11Header) pbyFrame;
PBYTE pbyIV;
PBYTE pbyPayload;
WORD wHLen = 22;
WORD wPayloadSize = wFrameSize - 8 - 8 - 4 - WLAN_HDR_ADDR3_LEN;
BOOL bA4 = FALSE;
BYTE byTmp;
WORD wCnt;
int ii, jj, kk;
pbyIV = pbyFrame + WLAN_HDR_ADDR3_LEN;
if (WLAN_GET_FC_TODS(*(PWORD) pbyFrame) &&
WLAN_GET_FC_FROMDS(*(PWORD) pbyFrame)) {
bA4 = TRUE;
pbyIV += 6;
wHLen += 6;
wPayloadSize -= 6;
}
pbyPayload = pbyIV + 8;
abyNonce[0] = 0x00;
memcpy(&(abyNonce[1]), pMACHeader->abyAddr2, ETH_ALEN);
abyNonce[7] = pbyIV[7];
abyNonce[8] = pbyIV[6];
abyNonce[9] = pbyIV[5];
abyNonce[10] = pbyIV[4];
abyNonce[11] = pbyIV[1];
abyNonce[12] = pbyIV[0];
MIC_IV[0] = 0x59;
memcpy(&(MIC_IV[1]), &(abyNonce[0]), 13);
MIC_IV[14] = (BYTE)(wPayloadSize >> 8);
MIC_IV[15] = (BYTE)(wPayloadSize & 0xff);
MIC_HDR1[0] = (BYTE)(wHLen >> 8);
MIC_HDR1[1] = (BYTE)(wHLen & 0xff);
byTmp = (BYTE)(pMACHeader->wFrameCtl & 0xff);
MIC_HDR1[2] = byTmp & 0x8f;
byTmp = (BYTE)(pMACHeader->wFrameCtl >> 8);
byTmp &= 0x87;
MIC_HDR1[3] = byTmp | 0x40;
memcpy(&(MIC_HDR1[4]), pMACHeader->abyAddr1, ETH_ALEN);
memcpy(&(MIC_HDR1[10]), pMACHeader->abyAddr2, ETH_ALEN);
memcpy(&(MIC_HDR2[0]), pMACHeader->abyAddr3, ETH_ALEN);
byTmp = (BYTE)(pMACHeader->wSeqCtl & 0xff);
MIC_HDR2[6] = byTmp & 0x0f;
MIC_HDR2[7] = 0;
if (bA4) {
memcpy(&(MIC_HDR2[8]), pMACHeader->abyAddr4, ETH_ALEN);
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
abyCTRPLD[14] = (BYTE) (wCnt >> 8);
abyCTRPLD[15] = (BYTE) (wCnt & 0xff);
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
abyCTRPLD[14] = (BYTE) (wCnt >> 8);
abyCTRPLD[15] = (BYTE) (wCnt & 0xff);
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
abyCTRPLD[14] = (BYTE) (wCnt >> 8);
abyCTRPLD[15] = (BYTE) (wCnt & 0xff);
AESv128(pbyRxKey, abyCTRPLD, abyTmp);
for (kk = 0; kk < 8; kk++)
abyTmp[kk] = abyTmp[kk] ^ pbyPayload[kk];
if (!memcmp(abyMIC, abyTmp, 8))
return TRUE;
else
return FALSE;
}
