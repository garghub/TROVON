static void trans_result(u8 reg2, u8 reg3, u8 *ecc1, u8 *ecc2)
{
u8 a;
u8 b;
u8 i;
a = BIT7; b = BIT7;
*ecc1 = *ecc2 = 0;
for (i = 0; i < 4; ++i) {
if ((reg3&a) != 0)
*ecc1 |= b;
b = b>>1;
if ((reg2&a) != 0)
*ecc1 |= b;
b = b>>1;
a = a>>1;
}
b = BIT7;
for (i = 0; i < 4; ++i) {
if ((reg3&a) != 0)
*ecc2 |= b;
b = b>>1;
if ((reg2&a) != 0)
*ecc2 |= b;
b = b>>1;
a = a>>1;
}
}
void calculate_ecc(u8 *table, u8 *data, u8 *ecc1, u8 *ecc2, u8 *ecc3)
{
u32 i;
u8 a;
u8 reg1;
u8 reg2;
u8 reg3;
reg1 = reg2 = reg3 = 0;
for (i = 0; i < 256; ++i) {
a = table[data[i]];
reg1 ^= (a&MASK_CPS);
if ((a&BIT6) != 0) {
reg3 ^= (u8)i;
reg2 ^= ~((u8)i);
}
}
trans_result(reg2, reg3, ecc1, ecc2);
*ecc1 = ~(*ecc1); *ecc2 = ~(*ecc2);
*ecc3 = ((~reg1)<<2)|BIT1BIT0;
}
u8 correct_data(u8 *data, u8 *eccdata, u8 ecc1, u8 ecc2, u8 ecc3)
{
u32 l;
u32 d;
u32 i;
u8 d1, d2, d3;
u8 a;
u8 add;
u8 b;
u8 bit;
d1 = ecc1^eccdata[1]; d2 = ecc2^eccdata[0];
d3 = ecc3^eccdata[2];
d = ((u32)d1<<16)
+((u32)d2<<8)
+(u32)d3;
if (d == 0)
return 0;
if (((d^(d>>1))&CORRECTABLE) == CORRECTABLE) {
l = BIT23;
add = 0;
a = BIT7;
for (i = 0; i < 8; ++i) {
if ((d&l) != 0)
add |= a;
l >>= 2; a >>= 1;
}
bit = 0;
b = BIT2;
for (i = 0; i < 3; ++i) {
if ((d&l) != 0)
bit |= b;
l >>= 2; b >>= 1;
}
b = BIT0;
data[add] ^= (b<<bit);
return 1;
}
i = 0;
d &= 0x00ffffffL;
while (d) {
if (d&BIT0)
++i;
d >>= 1;
}
if (i == 1) {
eccdata[1] = ecc1; eccdata[0] = ecc2;
eccdata[2] = ecc3;
return 2;
}
return 3;
}
int _Correct_D_SwECC(u8 *buf, u8 *redundant_ecc, u8 *calculate_ecc)
{
u32 err;
err = correct_data(buf, redundant_ecc, *(calculate_ecc + 1),
*(calculate_ecc), *(calculate_ecc + 2));
if (err == 1)
memcpy(calculate_ecc, redundant_ecc, 3);
if (err == 0 || err == 1 || err == 2)
return 0;
return -1;
}
void _Calculate_D_SwECC(u8 *buf, u8 *ecc)
{
calculate_ecc(ecctable, buf, ecc+1, ecc+0, ecc+2);
}
