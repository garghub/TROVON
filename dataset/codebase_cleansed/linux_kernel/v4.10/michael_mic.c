static
void MichaelInitializeFunction(struct michel_mic_t *Mic, uint8_t *key)
{
Mic->K0 = getUInt32(key, 0);
Mic->K1 = getUInt32(key, 4);
MichaelClear(Mic);
}
static
void MichaelAppend(struct michel_mic_t *Mic, uint8_t *src, int nBytes)
{
int addlen;
if (Mic->nBytesInM) {
addlen = 4 - Mic->nBytesInM;
if (addlen > nBytes)
addlen = nBytes;
memcpy(&Mic->M[Mic->nBytesInM], src, addlen);
Mic->nBytesInM += addlen;
src += addlen;
nBytes -= addlen;
if (Mic->nBytesInM < 4)
return;
Mic->L ^= getUInt32(Mic->M, 0);
MichaelBlockFunction(Mic->L, Mic->R);
Mic->nBytesInM = 0;
}
while (nBytes >= 4) {
Mic->L ^= getUInt32(src, 0);
MichaelBlockFunction(Mic->L, Mic->R);
src += 4;
nBytes -= 4;
}
if (nBytes > 0) {
Mic->nBytesInM = nBytes;
memcpy(Mic->M, src, nBytes);
}
}
static
void MichaelGetMIC(struct michel_mic_t *Mic, uint8_t *dst)
{
u8 *data = Mic->M;
switch (Mic->nBytesInM) {
case 0:
Mic->L ^= 0x5a;
break;
case 1:
Mic->L ^= data[0] | 0x5a00;
break;
case 2:
Mic->L ^= data[0] | (data[1] << 8) | 0x5a0000;
break;
case 3:
Mic->L ^= data[0] | (data[1] << 8) | (data[2] << 16) |
0x5a000000;
break;
}
MichaelBlockFunction(Mic->L, Mic->R);
MichaelBlockFunction(Mic->L, Mic->R);
putUInt32(dst, 0, Mic->L);
putUInt32(dst, 4, Mic->R);
MichaelClear(Mic);
}
void MichaelMICFunction(struct michel_mic_t *Mic, u8 *Key,
u8 *Data, int Len, u8 priority,
u8 *Result)
{
u8 pad_data[4] = { priority, 0, 0, 0 };
MichaelInitializeFunction(Mic, Key);
MichaelAppend(Mic, (uint8_t *) Data, 12);
MichaelAppend(Mic, pad_data, 4);
MichaelAppend(Mic, (uint8_t *) (Data + 12), Len - 12);
MichaelGetMIC(Mic, Result);
}
