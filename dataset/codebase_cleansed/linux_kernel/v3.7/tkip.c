unsigned int tkip_sbox(unsigned int index)
{
unsigned int index_low;
unsigned int index_high;
unsigned int left, right;
index_low = (index % 256);
index_high = ((index >> 8) % 256);
left = TKIP_Sbox_Lower[index_low] + (TKIP_Sbox_Upper[index_low] * 256);
right = TKIP_Sbox_Upper[index_high] + (TKIP_Sbox_Lower[index_high] * 256);
return (left ^ right);
}
unsigned int rotr1(unsigned int a)
{
unsigned int b;
if ((a & 0x01) == 0x01) {
b = (a >> 1) | 0x8000;
} else {
b = (a >> 1) & 0x7fff;
}
b = b % 65536;
return b;
}
void TKIPvMixKey(
unsigned char *pbyTKey,
unsigned char *pbyTA,
unsigned short wTSC15_0,
unsigned long dwTSC47_16,
unsigned char *pbyRC4Key
)
{
unsigned int p1k[5];
unsigned int tsc0, tsc1, tsc2;
unsigned int ppk0, ppk1, ppk2, ppk3, ppk4, ppk5;
unsigned long int pnl,pnh;
int i, j;
pnl = wTSC15_0;
pnh = dwTSC47_16;
tsc0 = (unsigned int)((pnh >> 16) % 65536);
tsc1 = (unsigned int)(pnh % 65536);
tsc2 = (unsigned int)(pnl % 65536);
p1k[0] = tsc1;
p1k[1] = tsc0;
p1k[2] = (unsigned int)(pbyTA[0] + (pbyTA[1]*256));
p1k[3] = (unsigned int)(pbyTA[2] + (pbyTA[3]*256));
p1k[4] = (unsigned int)(pbyTA[4] + (pbyTA[5]*256));
for (i=0; i<8; i++) {
j = 2*(i & 1);
p1k[0] = (p1k[0] + tkip_sbox( (p1k[4] ^ ((256*pbyTKey[1+j]) + pbyTKey[j])) % 65536 )) % 65536;
p1k[1] = (p1k[1] + tkip_sbox( (p1k[0] ^ ((256*pbyTKey[5+j]) + pbyTKey[4+j])) % 65536 )) % 65536;
p1k[2] = (p1k[2] + tkip_sbox( (p1k[1] ^ ((256*pbyTKey[9+j]) + pbyTKey[8+j])) % 65536 )) % 65536;
p1k[3] = (p1k[3] + tkip_sbox( (p1k[2] ^ ((256*pbyTKey[13+j]) + pbyTKey[12+j])) % 65536 )) % 65536;
p1k[4] = (p1k[4] + tkip_sbox( (p1k[3] ^ (((256*pbyTKey[1+j]) + pbyTKey[j]))) % 65536 )) % 65536;
p1k[4] = (p1k[4] + i) % 65536;
}
ppk0 = p1k[0];
ppk1 = p1k[1];
ppk2 = p1k[2];
ppk3 = p1k[3];
ppk4 = p1k[4];
ppk5 = (p1k[4] + tsc2) % 65536;
ppk0 = ppk0 + tkip_sbox( (ppk5 ^ ((256*pbyTKey[1]) + pbyTKey[0])) % 65536);
ppk1 = ppk1 + tkip_sbox( (ppk0 ^ ((256*pbyTKey[3]) + pbyTKey[2])) % 65536);
ppk2 = ppk2 + tkip_sbox( (ppk1 ^ ((256*pbyTKey[5]) + pbyTKey[4])) % 65536);
ppk3 = ppk3 + tkip_sbox( (ppk2 ^ ((256*pbyTKey[7]) + pbyTKey[6])) % 65536);
ppk4 = ppk4 + tkip_sbox( (ppk3 ^ ((256*pbyTKey[9]) + pbyTKey[8])) % 65536);
ppk5 = ppk5 + tkip_sbox( (ppk4 ^ ((256*pbyTKey[11]) + pbyTKey[10])) % 65536);
ppk0 = ppk0 + rotr1(ppk5 ^ ((256*pbyTKey[13]) + pbyTKey[12]));
ppk1 = ppk1 + rotr1(ppk0 ^ ((256*pbyTKey[15]) + pbyTKey[14]));
ppk2 = ppk2 + rotr1(ppk1);
ppk3 = ppk3 + rotr1(ppk2);
ppk4 = ppk4 + rotr1(ppk3);
ppk5 = ppk5 + rotr1(ppk4);
pbyRC4Key[0] = (tsc2 >> 8) % 256;
pbyRC4Key[1] = (((tsc2 >> 8) % 256) | 0x20) & 0x7f;
pbyRC4Key[2] = tsc2 % 256;
pbyRC4Key[3] = ((ppk5 ^ ((256*pbyTKey[1]) + pbyTKey[0])) >> 1) % 256;
pbyRC4Key[4] = ppk0 % 256;
pbyRC4Key[5] = (ppk0 >> 8) % 256;
pbyRC4Key[6] = ppk1 % 256;
pbyRC4Key[7] = (ppk1 >> 8) % 256;
pbyRC4Key[8] = ppk2 % 256;
pbyRC4Key[9] = (ppk2 >> 8) % 256;
pbyRC4Key[10] = ppk3 % 256;
pbyRC4Key[11] = (ppk3 >> 8) % 256;
pbyRC4Key[12] = ppk4 % 256;
pbyRC4Key[13] = (ppk4 >> 8) % 256;
pbyRC4Key[14] = ppk5 % 256;
pbyRC4Key[15] = (ppk5 >> 8) % 256;
}
