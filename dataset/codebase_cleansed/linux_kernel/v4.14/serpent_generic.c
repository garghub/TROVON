static void __serpent_setkey_sbox(u32 r0, u32 r1, u32 r2, u32 r3, u32 r4, u32 *k)
{
k += 100;
S3(r3, r4, r0, r1, r2); store_and_load_keys(r1, r2, r4, r3, 28, 24);
S4(r1, r2, r4, r3, r0); store_and_load_keys(r2, r4, r3, r0, 24, 20);
S5(r2, r4, r3, r0, r1); store_and_load_keys(r1, r2, r4, r0, 20, 16);
S6(r1, r2, r4, r0, r3); store_and_load_keys(r4, r3, r2, r0, 16, 12);
S7(r4, r3, r2, r0, r1); store_and_load_keys(r1, r2, r0, r4, 12, 8);
S0(r1, r2, r0, r4, r3); store_and_load_keys(r0, r2, r4, r1, 8, 4);
S1(r0, r2, r4, r1, r3); store_and_load_keys(r3, r4, r1, r0, 4, 0);
S2(r3, r4, r1, r0, r2); store_and_load_keys(r2, r4, r3, r0, 0, -4);
S3(r2, r4, r3, r0, r1); store_and_load_keys(r0, r1, r4, r2, -4, -8);
S4(r0, r1, r4, r2, r3); store_and_load_keys(r1, r4, r2, r3, -8, -12);
S5(r1, r4, r2, r3, r0); store_and_load_keys(r0, r1, r4, r3, -12, -16);
S6(r0, r1, r4, r3, r2); store_and_load_keys(r4, r2, r1, r3, -16, -20);
S7(r4, r2, r1, r3, r0); store_and_load_keys(r0, r1, r3, r4, -20, -24);
S0(r0, r1, r3, r4, r2); store_and_load_keys(r3, r1, r4, r0, -24, -28);
k -= 50;
S1(r3, r1, r4, r0, r2); store_and_load_keys(r2, r4, r0, r3, 22, 18);
S2(r2, r4, r0, r3, r1); store_and_load_keys(r1, r4, r2, r3, 18, 14);
S3(r1, r4, r2, r3, r0); store_and_load_keys(r3, r0, r4, r1, 14, 10);
S4(r3, r0, r4, r1, r2); store_and_load_keys(r0, r4, r1, r2, 10, 6);
S5(r0, r4, r1, r2, r3); store_and_load_keys(r3, r0, r4, r2, 6, 2);
S6(r3, r0, r4, r2, r1); store_and_load_keys(r4, r1, r0, r2, 2, -2);
S7(r4, r1, r0, r2, r3); store_and_load_keys(r3, r0, r2, r4, -2, -6);
S0(r3, r0, r2, r4, r1); store_and_load_keys(r2, r0, r4, r3, -6, -10);
S1(r2, r0, r4, r3, r1); store_and_load_keys(r1, r4, r3, r2, -10, -14);
S2(r1, r4, r3, r2, r0); store_and_load_keys(r0, r4, r1, r2, -14, -18);
S3(r0, r4, r1, r2, r3); store_and_load_keys(r2, r3, r4, r0, -18, -22);
k -= 50;
S4(r2, r3, r4, r0, r1); store_and_load_keys(r3, r4, r0, r1, 28, 24);
S5(r3, r4, r0, r1, r2); store_and_load_keys(r2, r3, r4, r1, 24, 20);
S6(r2, r3, r4, r1, r0); store_and_load_keys(r4, r0, r3, r1, 20, 16);
S7(r4, r0, r3, r1, r2); store_and_load_keys(r2, r3, r1, r4, 16, 12);
S0(r2, r3, r1, r4, r0); store_and_load_keys(r1, r3, r4, r2, 12, 8);
S1(r1, r3, r4, r2, r0); store_and_load_keys(r0, r4, r2, r1, 8, 4);
S2(r0, r4, r2, r1, r3); store_and_load_keys(r3, r4, r0, r1, 4, 0);
S3(r3, r4, r0, r1, r2); storekeys(r1, r2, r4, r3, 0);
}
int __serpent_setkey(struct serpent_ctx *ctx, const u8 *key,
unsigned int keylen)
{
u32 *k = ctx->expkey;
u8 *k8 = (u8 *)k;
u32 r0, r1, r2, r3, r4;
int i;
for (i = 0; i < keylen; ++i)
k8[i] = key[i];
if (i < SERPENT_MAX_KEY_SIZE)
k8[i++] = 1;
while (i < SERPENT_MAX_KEY_SIZE)
k8[i++] = 0;
r0 = le32_to_cpu(k[3]);
r1 = le32_to_cpu(k[4]);
r2 = le32_to_cpu(k[5]);
r3 = le32_to_cpu(k[6]);
r4 = le32_to_cpu(k[7]);
keyiter(le32_to_cpu(k[0]), r0, r4, r2, 0, 0);
keyiter(le32_to_cpu(k[1]), r1, r0, r3, 1, 1);
keyiter(le32_to_cpu(k[2]), r2, r1, r4, 2, 2);
keyiter(le32_to_cpu(k[3]), r3, r2, r0, 3, 3);
keyiter(le32_to_cpu(k[4]), r4, r3, r1, 4, 4);
keyiter(le32_to_cpu(k[5]), r0, r4, r2, 5, 5);
keyiter(le32_to_cpu(k[6]), r1, r0, r3, 6, 6);
keyiter(le32_to_cpu(k[7]), r2, r1, r4, 7, 7);
keyiter(k[0], r3, r2, r0, 8, 8);
keyiter(k[1], r4, r3, r1, 9, 9);
keyiter(k[2], r0, r4, r2, 10, 10);
keyiter(k[3], r1, r0, r3, 11, 11);
keyiter(k[4], r2, r1, r4, 12, 12);
keyiter(k[5], r3, r2, r0, 13, 13);
keyiter(k[6], r4, r3, r1, 14, 14);
keyiter(k[7], r0, r4, r2, 15, 15);
keyiter(k[8], r1, r0, r3, 16, 16);
keyiter(k[9], r2, r1, r4, 17, 17);
keyiter(k[10], r3, r2, r0, 18, 18);
keyiter(k[11], r4, r3, r1, 19, 19);
keyiter(k[12], r0, r4, r2, 20, 20);
keyiter(k[13], r1, r0, r3, 21, 21);
keyiter(k[14], r2, r1, r4, 22, 22);
keyiter(k[15], r3, r2, r0, 23, 23);
keyiter(k[16], r4, r3, r1, 24, 24);
keyiter(k[17], r0, r4, r2, 25, 25);
keyiter(k[18], r1, r0, r3, 26, 26);
keyiter(k[19], r2, r1, r4, 27, 27);
keyiter(k[20], r3, r2, r0, 28, 28);
keyiter(k[21], r4, r3, r1, 29, 29);
keyiter(k[22], r0, r4, r2, 30, 30);
keyiter(k[23], r1, r0, r3, 31, 31);
k += 50;
keyiter(k[-26], r2, r1, r4, 32, -18);
keyiter(k[-25], r3, r2, r0, 33, -17);
keyiter(k[-24], r4, r3, r1, 34, -16);
keyiter(k[-23], r0, r4, r2, 35, -15);
keyiter(k[-22], r1, r0, r3, 36, -14);
keyiter(k[-21], r2, r1, r4, 37, -13);
keyiter(k[-20], r3, r2, r0, 38, -12);
keyiter(k[-19], r4, r3, r1, 39, -11);
keyiter(k[-18], r0, r4, r2, 40, -10);
keyiter(k[-17], r1, r0, r3, 41, -9);
keyiter(k[-16], r2, r1, r4, 42, -8);
keyiter(k[-15], r3, r2, r0, 43, -7);
keyiter(k[-14], r4, r3, r1, 44, -6);
keyiter(k[-13], r0, r4, r2, 45, -5);
keyiter(k[-12], r1, r0, r3, 46, -4);
keyiter(k[-11], r2, r1, r4, 47, -3);
keyiter(k[-10], r3, r2, r0, 48, -2);
keyiter(k[-9], r4, r3, r1, 49, -1);
keyiter(k[-8], r0, r4, r2, 50, 0);
keyiter(k[-7], r1, r0, r3, 51, 1);
keyiter(k[-6], r2, r1, r4, 52, 2);
keyiter(k[-5], r3, r2, r0, 53, 3);
keyiter(k[-4], r4, r3, r1, 54, 4);
keyiter(k[-3], r0, r4, r2, 55, 5);
keyiter(k[-2], r1, r0, r3, 56, 6);
keyiter(k[-1], r2, r1, r4, 57, 7);
keyiter(k[0], r3, r2, r0, 58, 8);
keyiter(k[1], r4, r3, r1, 59, 9);
keyiter(k[2], r0, r4, r2, 60, 10);
keyiter(k[3], r1, r0, r3, 61, 11);
keyiter(k[4], r2, r1, r4, 62, 12);
keyiter(k[5], r3, r2, r0, 63, 13);
keyiter(k[6], r4, r3, r1, 64, 14);
keyiter(k[7], r0, r4, r2, 65, 15);
keyiter(k[8], r1, r0, r3, 66, 16);
keyiter(k[9], r2, r1, r4, 67, 17);
keyiter(k[10], r3, r2, r0, 68, 18);
keyiter(k[11], r4, r3, r1, 69, 19);
keyiter(k[12], r0, r4, r2, 70, 20);
keyiter(k[13], r1, r0, r3, 71, 21);
keyiter(k[14], r2, r1, r4, 72, 22);
keyiter(k[15], r3, r2, r0, 73, 23);
keyiter(k[16], r4, r3, r1, 74, 24);
keyiter(k[17], r0, r4, r2, 75, 25);
keyiter(k[18], r1, r0, r3, 76, 26);
keyiter(k[19], r2, r1, r4, 77, 27);
keyiter(k[20], r3, r2, r0, 78, 28);
keyiter(k[21], r4, r3, r1, 79, 29);
keyiter(k[22], r0, r4, r2, 80, 30);
keyiter(k[23], r1, r0, r3, 81, 31);
k += 50;
keyiter(k[-26], r2, r1, r4, 82, -18);
keyiter(k[-25], r3, r2, r0, 83, -17);
keyiter(k[-24], r4, r3, r1, 84, -16);
keyiter(k[-23], r0, r4, r2, 85, -15);
keyiter(k[-22], r1, r0, r3, 86, -14);
keyiter(k[-21], r2, r1, r4, 87, -13);
keyiter(k[-20], r3, r2, r0, 88, -12);
keyiter(k[-19], r4, r3, r1, 89, -11);
keyiter(k[-18], r0, r4, r2, 90, -10);
keyiter(k[-17], r1, r0, r3, 91, -9);
keyiter(k[-16], r2, r1, r4, 92, -8);
keyiter(k[-15], r3, r2, r0, 93, -7);
keyiter(k[-14], r4, r3, r1, 94, -6);
keyiter(k[-13], r0, r4, r2, 95, -5);
keyiter(k[-12], r1, r0, r3, 96, -4);
keyiter(k[-11], r2, r1, r4, 97, -3);
keyiter(k[-10], r3, r2, r0, 98, -2);
keyiter(k[-9], r4, r3, r1, 99, -1);
keyiter(k[-8], r0, r4, r2, 100, 0);
keyiter(k[-7], r1, r0, r3, 101, 1);
keyiter(k[-6], r2, r1, r4, 102, 2);
keyiter(k[-5], r3, r2, r0, 103, 3);
keyiter(k[-4], r4, r3, r1, 104, 4);
keyiter(k[-3], r0, r4, r2, 105, 5);
keyiter(k[-2], r1, r0, r3, 106, 6);
keyiter(k[-1], r2, r1, r4, 107, 7);
keyiter(k[0], r3, r2, r0, 108, 8);
keyiter(k[1], r4, r3, r1, 109, 9);
keyiter(k[2], r0, r4, r2, 110, 10);
keyiter(k[3], r1, r0, r3, 111, 11);
keyiter(k[4], r2, r1, r4, 112, 12);
keyiter(k[5], r3, r2, r0, 113, 13);
keyiter(k[6], r4, r3, r1, 114, 14);
keyiter(k[7], r0, r4, r2, 115, 15);
keyiter(k[8], r1, r0, r3, 116, 16);
keyiter(k[9], r2, r1, r4, 117, 17);
keyiter(k[10], r3, r2, r0, 118, 18);
keyiter(k[11], r4, r3, r1, 119, 19);
keyiter(k[12], r0, r4, r2, 120, 20);
keyiter(k[13], r1, r0, r3, 121, 21);
keyiter(k[14], r2, r1, r4, 122, 22);
keyiter(k[15], r3, r2, r0, 123, 23);
keyiter(k[16], r4, r3, r1, 124, 24);
keyiter(k[17], r0, r4, r2, 125, 25);
keyiter(k[18], r1, r0, r3, 126, 26);
keyiter(k[19], r2, r1, r4, 127, 27);
keyiter(k[20], r3, r2, r0, 128, 28);
keyiter(k[21], r4, r3, r1, 129, 29);
keyiter(k[22], r0, r4, r2, 130, 30);
keyiter(k[23], r1, r0, r3, 131, 31);
__serpent_setkey_sbox(r0, r1, r2, r3, r4, ctx->expkey);
return 0;
}
int serpent_setkey(struct crypto_tfm *tfm, const u8 *key, unsigned int keylen)
{
return __serpent_setkey(crypto_tfm_ctx(tfm), key, keylen);
}
void __serpent_encrypt(struct serpent_ctx *ctx, u8 *dst, const u8 *src)
{
const u32 *k = ctx->expkey;
const __le32 *s = (const __le32 *)src;
__le32 *d = (__le32 *)dst;
u32 r0, r1, r2, r3, r4;
r0 = le32_to_cpu(s[0]);
r1 = le32_to_cpu(s[1]);
r2 = le32_to_cpu(s[2]);
r3 = le32_to_cpu(s[3]);
K(r0, r1, r2, r3, 0);
S0(r0, r1, r2, r3, r4); LK(r2, r1, r3, r0, r4, 1);
S1(r2, r1, r3, r0, r4); LK(r4, r3, r0, r2, r1, 2);
S2(r4, r3, r0, r2, r1); LK(r1, r3, r4, r2, r0, 3);
S3(r1, r3, r4, r2, r0); LK(r2, r0, r3, r1, r4, 4);
S4(r2, r0, r3, r1, r4); LK(r0, r3, r1, r4, r2, 5);
S5(r0, r3, r1, r4, r2); LK(r2, r0, r3, r4, r1, 6);
S6(r2, r0, r3, r4, r1); LK(r3, r1, r0, r4, r2, 7);
S7(r3, r1, r0, r4, r2); LK(r2, r0, r4, r3, r1, 8);
S0(r2, r0, r4, r3, r1); LK(r4, r0, r3, r2, r1, 9);
S1(r4, r0, r3, r2, r1); LK(r1, r3, r2, r4, r0, 10);
S2(r1, r3, r2, r4, r0); LK(r0, r3, r1, r4, r2, 11);
S3(r0, r3, r1, r4, r2); LK(r4, r2, r3, r0, r1, 12);
S4(r4, r2, r3, r0, r1); LK(r2, r3, r0, r1, r4, 13);
S5(r2, r3, r0, r1, r4); LK(r4, r2, r3, r1, r0, 14);
S6(r4, r2, r3, r1, r0); LK(r3, r0, r2, r1, r4, 15);
S7(r3, r0, r2, r1, r4); LK(r4, r2, r1, r3, r0, 16);
S0(r4, r2, r1, r3, r0); LK(r1, r2, r3, r4, r0, 17);
S1(r1, r2, r3, r4, r0); LK(r0, r3, r4, r1, r2, 18);
S2(r0, r3, r4, r1, r2); LK(r2, r3, r0, r1, r4, 19);
S3(r2, r3, r0, r1, r4); LK(r1, r4, r3, r2, r0, 20);
S4(r1, r4, r3, r2, r0); LK(r4, r3, r2, r0, r1, 21);
S5(r4, r3, r2, r0, r1); LK(r1, r4, r3, r0, r2, 22);
S6(r1, r4, r3, r0, r2); LK(r3, r2, r4, r0, r1, 23);
S7(r3, r2, r4, r0, r1); LK(r1, r4, r0, r3, r2, 24);
S0(r1, r4, r0, r3, r2); LK(r0, r4, r3, r1, r2, 25);
S1(r0, r4, r3, r1, r2); LK(r2, r3, r1, r0, r4, 26);
S2(r2, r3, r1, r0, r4); LK(r4, r3, r2, r0, r1, 27);
S3(r4, r3, r2, r0, r1); LK(r0, r1, r3, r4, r2, 28);
S4(r0, r1, r3, r4, r2); LK(r1, r3, r4, r2, r0, 29);
S5(r1, r3, r4, r2, r0); LK(r0, r1, r3, r2, r4, 30);
S6(r0, r1, r3, r2, r4); LK(r3, r4, r1, r2, r0, 31);
S7(r3, r4, r1, r2, r0); K(r0, r1, r2, r3, 32);
d[0] = cpu_to_le32(r0);
d[1] = cpu_to_le32(r1);
d[2] = cpu_to_le32(r2);
d[3] = cpu_to_le32(r3);
}
static void serpent_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct serpent_ctx *ctx = crypto_tfm_ctx(tfm);
__serpent_encrypt(ctx, dst, src);
}
void __serpent_decrypt(struct serpent_ctx *ctx, u8 *dst, const u8 *src)
{
const u32 *k = ctx->expkey;
const __le32 *s = (const __le32 *)src;
__le32 *d = (__le32 *)dst;
u32 r0, r1, r2, r3, r4;
r0 = le32_to_cpu(s[0]);
r1 = le32_to_cpu(s[1]);
r2 = le32_to_cpu(s[2]);
r3 = le32_to_cpu(s[3]);
K(r0, r1, r2, r3, 32);
SI7(r0, r1, r2, r3, r4); KL(r1, r3, r0, r4, r2, 31);
SI6(r1, r3, r0, r4, r2); KL(r0, r2, r4, r1, r3, 30);
SI5(r0, r2, r4, r1, r3); KL(r2, r3, r0, r4, r1, 29);
SI4(r2, r3, r0, r4, r1); KL(r2, r0, r1, r4, r3, 28);
SI3(r2, r0, r1, r4, r3); KL(r1, r2, r3, r4, r0, 27);
SI2(r1, r2, r3, r4, r0); KL(r2, r0, r4, r3, r1, 26);
SI1(r2, r0, r4, r3, r1); KL(r1, r0, r4, r3, r2, 25);
SI0(r1, r0, r4, r3, r2); KL(r4, r2, r0, r1, r3, 24);
SI7(r4, r2, r0, r1, r3); KL(r2, r1, r4, r3, r0, 23);
SI6(r2, r1, r4, r3, r0); KL(r4, r0, r3, r2, r1, 22);
SI5(r4, r0, r3, r2, r1); KL(r0, r1, r4, r3, r2, 21);
SI4(r0, r1, r4, r3, r2); KL(r0, r4, r2, r3, r1, 20);
SI3(r0, r4, r2, r3, r1); KL(r2, r0, r1, r3, r4, 19);
SI2(r2, r0, r1, r3, r4); KL(r0, r4, r3, r1, r2, 18);
SI1(r0, r4, r3, r1, r2); KL(r2, r4, r3, r1, r0, 17);
SI0(r2, r4, r3, r1, r0); KL(r3, r0, r4, r2, r1, 16);
SI7(r3, r0, r4, r2, r1); KL(r0, r2, r3, r1, r4, 15);
SI6(r0, r2, r3, r1, r4); KL(r3, r4, r1, r0, r2, 14);
SI5(r3, r4, r1, r0, r2); KL(r4, r2, r3, r1, r0, 13);
SI4(r4, r2, r3, r1, r0); KL(r4, r3, r0, r1, r2, 12);
SI3(r4, r3, r0, r1, r2); KL(r0, r4, r2, r1, r3, 11);
SI2(r0, r4, r2, r1, r3); KL(r4, r3, r1, r2, r0, 10);
SI1(r4, r3, r1, r2, r0); KL(r0, r3, r1, r2, r4, 9);
SI0(r0, r3, r1, r2, r4); KL(r1, r4, r3, r0, r2, 8);
SI7(r1, r4, r3, r0, r2); KL(r4, r0, r1, r2, r3, 7);
SI6(r4, r0, r1, r2, r3); KL(r1, r3, r2, r4, r0, 6);
SI5(r1, r3, r2, r4, r0); KL(r3, r0, r1, r2, r4, 5);
SI4(r3, r0, r1, r2, r4); KL(r3, r1, r4, r2, r0, 4);
SI3(r3, r1, r4, r2, r0); KL(r4, r3, r0, r2, r1, 3);
SI2(r4, r3, r0, r2, r1); KL(r3, r1, r2, r0, r4, 2);
SI1(r3, r1, r2, r0, r4); KL(r4, r1, r2, r0, r3, 1);
SI0(r4, r1, r2, r0, r3); K(r2, r3, r1, r4, 0);
d[0] = cpu_to_le32(r2);
d[1] = cpu_to_le32(r3);
d[2] = cpu_to_le32(r1);
d[3] = cpu_to_le32(r4);
}
static void serpent_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
struct serpent_ctx *ctx = crypto_tfm_ctx(tfm);
__serpent_decrypt(ctx, dst, src);
}
static int tnepres_setkey(struct crypto_tfm *tfm, const u8 *key,
unsigned int keylen)
{
u8 rev_key[SERPENT_MAX_KEY_SIZE];
int i;
for (i = 0; i < keylen; ++i)
rev_key[keylen - i - 1] = key[i];
return serpent_setkey(tfm, rev_key, keylen);
}
static void tnepres_encrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
const u32 * const s = (const u32 * const)src;
u32 * const d = (u32 * const)dst;
u32 rs[4], rd[4];
rs[0] = swab32(s[3]);
rs[1] = swab32(s[2]);
rs[2] = swab32(s[1]);
rs[3] = swab32(s[0]);
serpent_encrypt(tfm, (u8 *)rd, (u8 *)rs);
d[0] = swab32(rd[3]);
d[1] = swab32(rd[2]);
d[2] = swab32(rd[1]);
d[3] = swab32(rd[0]);
}
static void tnepres_decrypt(struct crypto_tfm *tfm, u8 *dst, const u8 *src)
{
const u32 * const s = (const u32 * const)src;
u32 * const d = (u32 * const)dst;
u32 rs[4], rd[4];
rs[0] = swab32(s[3]);
rs[1] = swab32(s[2]);
rs[2] = swab32(s[1]);
rs[3] = swab32(s[0]);
serpent_decrypt(tfm, (u8 *)rd, (u8 *)rs);
d[0] = swab32(rd[3]);
d[1] = swab32(rd[2]);
d[2] = swab32(rd[1]);
d[3] = swab32(rd[0]);
}
static int __init serpent_mod_init(void)
{
return crypto_register_algs(srp_algs, ARRAY_SIZE(srp_algs));
}
static void __exit serpent_mod_fini(void)
{
crypto_unregister_algs(srp_algs, ARRAY_SIZE(srp_algs));
}
