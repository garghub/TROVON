void RSAZ_1024_mod_exp_avx2(BN_ULONG result_norm[16],
const BN_ULONG base_norm[16],
const BN_ULONG exponent[16],
const BN_ULONG m_norm[16], const BN_ULONG RR[16],
BN_ULONG k0)
{
unsigned char storage[320 * 3 + 32 * 9 * 16 + 64];
unsigned char *p_str = storage + (64 - ((size_t)storage % 64));
unsigned char *a_inv, *m, *result;
unsigned char *table_s = p_str + 320 * 3;
unsigned char *R2 = table_s;
int index;
int wvalue;
if ((((size_t)p_str & 4095) + 320) >> 12) {
result = p_str;
a_inv = p_str + 320;
m = p_str + 320 * 2;
} else {
m = p_str;
result = p_str + 320;
a_inv = p_str + 320 * 2;
}
rsaz_1024_norm2red_avx2(m, m_norm);
rsaz_1024_norm2red_avx2(a_inv, base_norm);
rsaz_1024_norm2red_avx2(R2, RR);
rsaz_1024_mul_avx2(R2, R2, R2, m, k0);
rsaz_1024_mul_avx2(R2, R2, two80, m, k0);
rsaz_1024_mul_avx2(result, R2, one, m, k0);
rsaz_1024_mul_avx2(a_inv, a_inv, R2, m, k0);
rsaz_1024_scatter5_avx2(table_s, result, 0);
rsaz_1024_scatter5_avx2(table_s, a_inv, 1);
rsaz_1024_sqr_avx2(result, a_inv, m, k0, 1);
rsaz_1024_scatter5_avx2(table_s, result, 2);
#if 0
for (index = 3; index < 32; index++) {
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
rsaz_1024_scatter5_avx2(table_s, result, index);
}
#else
rsaz_1024_sqr_avx2(result, result, m, k0, 1);
rsaz_1024_scatter5_avx2(table_s, result, 4);
rsaz_1024_sqr_avx2(result, result, m, k0, 1);
rsaz_1024_scatter5_avx2(table_s, result, 8);
rsaz_1024_sqr_avx2(result, result, m, k0, 1);
rsaz_1024_scatter5_avx2(table_s, result, 16);
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
rsaz_1024_scatter5_avx2(table_s, result, 17);
rsaz_1024_gather5_avx2(result, table_s, 2);
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
rsaz_1024_scatter5_avx2(table_s, result, 3);
rsaz_1024_sqr_avx2(result, result, m, k0, 1);
rsaz_1024_scatter5_avx2(table_s, result, 6);
rsaz_1024_sqr_avx2(result, result, m, k0, 1);
rsaz_1024_scatter5_avx2(table_s, result, 12);
rsaz_1024_sqr_avx2(result, result, m, k0, 1);
rsaz_1024_scatter5_avx2(table_s, result, 24);
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
rsaz_1024_scatter5_avx2(table_s, result, 25);
rsaz_1024_gather5_avx2(result, table_s, 4);
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
rsaz_1024_scatter5_avx2(table_s, result, 5);
rsaz_1024_sqr_avx2(result, result, m, k0, 1);
rsaz_1024_scatter5_avx2(table_s, result, 10);
rsaz_1024_sqr_avx2(result, result, m, k0, 1);
rsaz_1024_scatter5_avx2(table_s, result, 20);
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
rsaz_1024_scatter5_avx2(table_s, result, 21);
rsaz_1024_gather5_avx2(result, table_s, 6);
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
rsaz_1024_scatter5_avx2(table_s, result, 7);
rsaz_1024_sqr_avx2(result, result, m, k0, 1);
rsaz_1024_scatter5_avx2(table_s, result, 14);
rsaz_1024_sqr_avx2(result, result, m, k0, 1);
rsaz_1024_scatter5_avx2(table_s, result, 28);
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
rsaz_1024_scatter5_avx2(table_s, result, 29);
rsaz_1024_gather5_avx2(result, table_s, 8);
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
rsaz_1024_scatter5_avx2(table_s, result, 9);
rsaz_1024_sqr_avx2(result, result, m, k0, 1);
rsaz_1024_scatter5_avx2(table_s, result, 18);
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
rsaz_1024_scatter5_avx2(table_s, result, 19);
rsaz_1024_gather5_avx2(result, table_s, 10);
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
rsaz_1024_scatter5_avx2(table_s, result, 11);
rsaz_1024_sqr_avx2(result, result, m, k0, 1);
rsaz_1024_scatter5_avx2(table_s, result, 22);
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
rsaz_1024_scatter5_avx2(table_s, result, 23);
rsaz_1024_gather5_avx2(result, table_s, 12);
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
rsaz_1024_scatter5_avx2(table_s, result, 13);
rsaz_1024_sqr_avx2(result, result, m, k0, 1);
rsaz_1024_scatter5_avx2(table_s, result, 26);
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
rsaz_1024_scatter5_avx2(table_s, result, 27);
rsaz_1024_gather5_avx2(result, table_s, 14);
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
rsaz_1024_scatter5_avx2(table_s, result, 15);
rsaz_1024_sqr_avx2(result, result, m, k0, 1);
rsaz_1024_scatter5_avx2(table_s, result, 30);
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
rsaz_1024_scatter5_avx2(table_s, result, 31);
#endif
p_str = (unsigned char *)exponent;
wvalue = p_str[127] >> 3;
rsaz_1024_gather5_avx2(result, table_s, wvalue);
index = 1014;
while (index > -1) {
rsaz_1024_sqr_avx2(result, result, m, k0, 5);
wvalue = (p_str[(index / 8) + 1] << 8) | p_str[index / 8];
wvalue = (wvalue >> (index % 8)) & 31;
index -= 5;
rsaz_1024_gather5_avx2(a_inv, table_s, wvalue);
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
}
rsaz_1024_sqr_avx2(result, result, m, k0, 4);
wvalue = p_str[0] & 15;
rsaz_1024_gather5_avx2(a_inv, table_s, wvalue);
rsaz_1024_mul_avx2(result, result, a_inv, m, k0);
rsaz_1024_mul_avx2(result, result, one, m, k0);
rsaz_1024_red2norm_avx2(result_norm, result);
OPENSSL_cleanse(storage, sizeof(storage));
}
void RSAZ_512_mod_exp(BN_ULONG result[8],
const BN_ULONG base[8], const BN_ULONG exponent[8],
const BN_ULONG m[8], BN_ULONG k0, const BN_ULONG RR[8])
{
unsigned char storage[16 * 8 * 8 + 64 * 2 + 64];
unsigned char *table = storage + (64 - ((size_t)storage % 64));
BN_ULONG *a_inv = (BN_ULONG *)(table + 16 * 8 * 8);
BN_ULONG *temp = (BN_ULONG *)(table + 16 * 8 * 8 + 8 * 8);
unsigned char *p_str = (unsigned char *)exponent;
int index;
unsigned int wvalue;
temp[0] = 0 - m[0];
temp[1] = ~m[1];
temp[2] = ~m[2];
temp[3] = ~m[3];
temp[4] = ~m[4];
temp[5] = ~m[5];
temp[6] = ~m[6];
temp[7] = ~m[7];
rsaz_512_scatter4(table, temp, 0);
rsaz_512_mul(a_inv, base, RR, m, k0);
rsaz_512_scatter4(table, a_inv, 1);
rsaz_512_sqr(temp, a_inv, m, k0, 1);
rsaz_512_scatter4(table, temp, 2);
for (index = 3; index < 16; index++)
rsaz_512_mul_scatter4(temp, a_inv, m, k0, table, index);
wvalue = p_str[63];
rsaz_512_gather4(temp, table, wvalue >> 4);
rsaz_512_sqr(temp, temp, m, k0, 4);
rsaz_512_mul_gather4(temp, temp, table, m, k0, wvalue & 0xf);
for (index = 62; index >= 0; index--) {
wvalue = p_str[index];
rsaz_512_sqr(temp, temp, m, k0, 4);
rsaz_512_mul_gather4(temp, temp, table, m, k0, wvalue >> 4);
rsaz_512_sqr(temp, temp, m, k0, 4);
rsaz_512_mul_gather4(temp, temp, table, m, k0, wvalue & 0x0f);
}
rsaz_512_mul_by_one(result, temp, m, k0);
OPENSSL_cleanse(storage, sizeof(storage));
}
