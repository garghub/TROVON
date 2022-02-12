int Camellia_Ekeygen(int keyBitLength, const u8 *rawKey, KEY_TABLE_TYPE k)
{
register u32 s0,s1,s2,s3;
k[0] = s0 = GETU32(rawKey);
k[1] = s1 = GETU32(rawKey+4);
k[2] = s2 = GETU32(rawKey+8);
k[3] = s3 = GETU32(rawKey+12);
if (keyBitLength != 128)
{
k[8] = s0 = GETU32(rawKey+16);
k[9] = s1 = GETU32(rawKey+20);
if (keyBitLength == 192)
{
k[10] = s2 = ~s0;
k[11] = s3 = ~s1;
}
else
{
k[10] = s2 = GETU32(rawKey+24);
k[11] = s3 = GETU32(rawKey+28);
}
s0 ^= k[0], s1 ^= k[1], s2 ^= k[2], s3 ^= k[3];
}
Camellia_Feistel(s0,s1,s2,s3,SIGMA+0);
Camellia_Feistel(s2,s3,s0,s1,SIGMA+2);
s0 ^= k[0], s1 ^= k[1], s2 ^= k[2], s3 ^= k[3];
Camellia_Feistel(s0,s1,s2,s3,SIGMA+4);
Camellia_Feistel(s2,s3,s0,s1,SIGMA+6);
if (keyBitLength == 128)
{
k[ 4] = s0, k[ 5] = s1, k[ 6] = s2, k[ 7] = s3;
RotLeft128(s0,s1,s2,s3,15);
k[12] = s0, k[13] = s1, k[14] = s2, k[15] = s3;
RotLeft128(s0,s1,s2,s3,15);
k[16] = s0, k[17] = s1, k[18] = s2, k[19] = s3;
RotLeft128(s0,s1,s2,s3,15);
k[24] = s0, k[25] = s1;
RotLeft128(s0,s1,s2,s3,15);
k[28] = s0, k[29] = s1, k[30] = s2, k[31] = s3;
RotLeft128(s1,s2,s3,s0,2);
k[40] = s1, k[41] = s2, k[42] = s3, k[43] = s0;
RotLeft128(s1,s2,s3,s0,17);
k[48] = s1, k[49] = s2, k[50] = s3, k[51] = s0;
s0 = k[ 0], s1 = k[ 1], s2 = k[ 2], s3 = k[ 3];
RotLeft128(s0,s1,s2,s3,15);
k[ 8] = s0, k[ 9] = s1, k[10] = s2, k[11] = s3;
RotLeft128(s0,s1,s2,s3,30);
k[20] = s0, k[21] = s1, k[22] = s2, k[23] = s3;
RotLeft128(s0,s1,s2,s3,15);
k[26] = s2, k[27] = s3;
RotLeft128(s0,s1,s2,s3,17);
k[32] = s0, k[33] = s1, k[34] = s2, k[35] = s3;
RotLeft128(s0,s1,s2,s3,17);
k[36] = s0, k[37] = s1, k[38] = s2, k[39] = s3;
RotLeft128(s0,s1,s2,s3,17);
k[44] = s0, k[45] = s1, k[46] = s2, k[47] = s3;
return 3;
}
else
{
k[12] = s0, k[13] = s1, k[14] = s2, k[15] = s3;
s0 ^= k[8], s1 ^= k[9], s2 ^=k[10], s3 ^=k[11];
Camellia_Feistel(s0,s1,s2,s3,(SIGMA+8));
Camellia_Feistel(s2,s3,s0,s1,(SIGMA+10));
k[ 4] = s0, k[ 5] = s1, k[ 6] = s2, k[ 7] = s3;
RotLeft128(s0,s1,s2,s3,30);
k[20] = s0, k[21] = s1, k[22] = s2, k[23] = s3;
RotLeft128(s0,s1,s2,s3,30);
k[40] = s0, k[41] = s1, k[42] = s2, k[43] = s3;
RotLeft128(s1,s2,s3,s0,19);
k[64] = s1, k[65] = s2, k[66] = s3, k[67] = s0;
s0 = k[ 8], s1 = k[ 9], s2 = k[10], s3 = k[11];
RotLeft128(s0,s1,s2,s3,15);
k[ 8] = s0, k[ 9] = s1, k[10] = s2, k[11] = s3;
RotLeft128(s0,s1,s2,s3,15);
k[16] = s0, k[17] = s1, k[18] = s2, k[19] = s3;
RotLeft128(s0,s1,s2,s3,30);
k[36] = s0, k[37] = s1, k[38] = s2, k[39] = s3;
RotLeft128(s1,s2,s3,s0,2);
k[52] = s1, k[53] = s2, k[54] = s3, k[55] = s0;
s0 = k[12], s1 = k[13], s2 = k[14], s3 = k[15];
RotLeft128(s0,s1,s2,s3,15);
k[12] = s0, k[13] = s1, k[14] = s2, k[15] = s3;
RotLeft128(s0,s1,s2,s3,30);
k[28] = s0, k[29] = s1, k[30] = s2, k[31] = s3;
k[48] = s1, k[49] = s2, k[50] = s3, k[51] = s0;
RotLeft128(s1,s2,s3,s0,17);
k[56] = s1, k[57] = s2, k[58] = s3, k[59] = s0;
s0 = k[ 0], s1 = k[ 1], s2 = k[ 2], s3 = k[ 3];
RotLeft128(s1,s2,s3,s0,13);
k[24] = s1, k[25] = s2, k[26] = s3, k[27] = s0;
RotLeft128(s1,s2,s3,s0,15);
k[32] = s1, k[33] = s2, k[34] = s3, k[35] = s0;
RotLeft128(s1,s2,s3,s0,17);
k[44] = s1, k[45] = s2, k[46] = s3, k[47] = s0;
RotLeft128(s2,s3,s0,s1,2);
k[60] = s2, k[61] = s3, k[62] = s0, k[63] = s1;
return 4;
}
}
void Camellia_EncryptBlock_Rounds(int grandRounds, const u8 plaintext[],
const KEY_TABLE_TYPE keyTable, u8 ciphertext[])
{
register u32 s0,s1,s2,s3;
const u32 *k = keyTable,*kend = keyTable+grandRounds*16;
s0 = GETU32(plaintext) ^ k[0];
s1 = GETU32(plaintext+4) ^ k[1];
s2 = GETU32(plaintext+8) ^ k[2];
s3 = GETU32(plaintext+12) ^ k[3];
k += 4;
while (1)
{
Camellia_Feistel(s0,s1,s2,s3,k+0);
Camellia_Feistel(s2,s3,s0,s1,k+2);
Camellia_Feistel(s0,s1,s2,s3,k+4);
Camellia_Feistel(s2,s3,s0,s1,k+6);
Camellia_Feistel(s0,s1,s2,s3,k+8);
Camellia_Feistel(s2,s3,s0,s1,k+10);
k += 12;
if (k == kend) break;
s1 ^= LeftRotate(s0 & k[0], 1);
s2 ^= s3 | k[3];
s0 ^= s1 | k[1];
s3 ^= LeftRotate(s2 & k[2], 1);
k += 4;
}
s2 ^= k[0], s3 ^= k[1], s0 ^= k[2], s1 ^= k[3];
PUTU32(ciphertext, s2);
PUTU32(ciphertext+4, s3);
PUTU32(ciphertext+8, s0);
PUTU32(ciphertext+12,s1);
}
void Camellia_EncryptBlock(int keyBitLength, const u8 plaintext[],
const KEY_TABLE_TYPE keyTable, u8 ciphertext[])
{
Camellia_EncryptBlock_Rounds(keyBitLength==128?3:4,
plaintext,keyTable,ciphertext);
}
void Camellia_DecryptBlock_Rounds(int grandRounds, const u8 ciphertext[],
const KEY_TABLE_TYPE keyTable, u8 plaintext[])
{
u32 s0,s1,s2,s3;
const u32 *k = keyTable+grandRounds*16,*kend = keyTable+4;
s0 = GETU32(ciphertext) ^ k[0];
s1 = GETU32(ciphertext+4) ^ k[1];
s2 = GETU32(ciphertext+8) ^ k[2];
s3 = GETU32(ciphertext+12) ^ k[3];
while (1)
{
k -= 12;
Camellia_Feistel(s0,s1,s2,s3,k+10);
Camellia_Feistel(s2,s3,s0,s1,k+8);
Camellia_Feistel(s0,s1,s2,s3,k+6);
Camellia_Feistel(s2,s3,s0,s1,k+4);
Camellia_Feistel(s0,s1,s2,s3,k+2);
Camellia_Feistel(s2,s3,s0,s1,k+0);
if (k == kend) break;
k -= 4;
s1 ^= LeftRotate(s0 & k[2], 1);
s2 ^= s3 | k[1];
s0 ^= s1 | k[3];
s3 ^= LeftRotate(s2 & k[0], 1);
}
k -= 4;
s2 ^= k[0], s3 ^= k[1], s0 ^= k[2], s1 ^= k[3];
PUTU32(plaintext, s2);
PUTU32(plaintext+4, s3);
PUTU32(plaintext+8, s0);
PUTU32(plaintext+12,s1);
}
void Camellia_DecryptBlock(int keyBitLength, const u8 plaintext[],
const KEY_TABLE_TYPE keyTable, u8 ciphertext[])
{
Camellia_DecryptBlock_Rounds(keyBitLength==128?3:4,
plaintext,keyTable,ciphertext);
}
