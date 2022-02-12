int twofish_setkey(struct crypto_tfm *tfm, const u8 *key, unsigned int key_len)
{
struct twofish_ctx *ctx = crypto_tfm_ctx(tfm);
u32 *flags = &tfm->crt_flags;
int i, j, k;
u32 x, y;
u8 sa = 0, sb = 0, sc = 0, sd = 0, se = 0, sf = 0, sg = 0, sh = 0;
u8 si = 0, sj = 0, sk = 0, sl = 0, sm = 0, sn = 0, so = 0, sp = 0;
u8 tmp;
if (key_len % 8)
{
*flags |= CRYPTO_TFM_RES_BAD_KEY_LEN;
return -EINVAL;
}
CALC_S (sa, sb, sc, sd, 0, 0x00, 0x2D, 0x01, 0x2D);
CALC_S (sa, sb, sc, sd, 1, 0x2D, 0xA4, 0x44, 0x8A);
CALC_S (sa, sb, sc, sd, 2, 0x8A, 0xD5, 0xBF, 0xD1);
CALC_S (sa, sb, sc, sd, 3, 0xD1, 0x7F, 0x3D, 0x99);
CALC_S (sa, sb, sc, sd, 4, 0x99, 0x46, 0x66, 0x96);
CALC_S (sa, sb, sc, sd, 5, 0x96, 0x3C, 0x5B, 0xED);
CALC_S (sa, sb, sc, sd, 6, 0xED, 0x37, 0x4F, 0xE0);
CALC_S (sa, sb, sc, sd, 7, 0xE0, 0xD0, 0x8C, 0x17);
CALC_S (se, sf, sg, sh, 8, 0x00, 0x2D, 0x01, 0x2D);
CALC_S (se, sf, sg, sh, 9, 0x2D, 0xA4, 0x44, 0x8A);
CALC_S (se, sf, sg, sh, 10, 0x8A, 0xD5, 0xBF, 0xD1);
CALC_S (se, sf, sg, sh, 11, 0xD1, 0x7F, 0x3D, 0x99);
CALC_S (se, sf, sg, sh, 12, 0x99, 0x46, 0x66, 0x96);
CALC_S (se, sf, sg, sh, 13, 0x96, 0x3C, 0x5B, 0xED);
CALC_S (se, sf, sg, sh, 14, 0xED, 0x37, 0x4F, 0xE0);
CALC_S (se, sf, sg, sh, 15, 0xE0, 0xD0, 0x8C, 0x17);
if (key_len == 24 || key_len == 32) {
CALC_S (si, sj, sk, sl, 16, 0x00, 0x2D, 0x01, 0x2D);
CALC_S (si, sj, sk, sl, 17, 0x2D, 0xA4, 0x44, 0x8A);
CALC_S (si, sj, sk, sl, 18, 0x8A, 0xD5, 0xBF, 0xD1);
CALC_S (si, sj, sk, sl, 19, 0xD1, 0x7F, 0x3D, 0x99);
CALC_S (si, sj, sk, sl, 20, 0x99, 0x46, 0x66, 0x96);
CALC_S (si, sj, sk, sl, 21, 0x96, 0x3C, 0x5B, 0xED);
CALC_S (si, sj, sk, sl, 22, 0xED, 0x37, 0x4F, 0xE0);
CALC_S (si, sj, sk, sl, 23, 0xE0, 0xD0, 0x8C, 0x17);
}
if (key_len == 32) {
CALC_S (sm, sn, so, sp, 24, 0x00, 0x2D, 0x01, 0x2D);
CALC_S (sm, sn, so, sp, 25, 0x2D, 0xA4, 0x44, 0x8A);
CALC_S (sm, sn, so, sp, 26, 0x8A, 0xD5, 0xBF, 0xD1);
CALC_S (sm, sn, so, sp, 27, 0xD1, 0x7F, 0x3D, 0x99);
CALC_S (sm, sn, so, sp, 28, 0x99, 0x46, 0x66, 0x96);
CALC_S (sm, sn, so, sp, 29, 0x96, 0x3C, 0x5B, 0xED);
CALC_S (sm, sn, so, sp, 30, 0xED, 0x37, 0x4F, 0xE0);
CALC_S (sm, sn, so, sp, 31, 0xE0, 0xD0, 0x8C, 0x17);
for ( i = j = 0, k = 1; i < 256; i++, j += 2, k += 2 ) {
CALC_SB256_2( i, calc_sb_tbl[j], calc_sb_tbl[k] );
}
for ( i = 0; i < 8; i += 2 ) {
CALC_K256 (w, i, q0[i], q1[i], q0[i+1], q1[i+1]);
}
for ( i = 0; i < 32; i += 2 ) {
CALC_K256 (k, i, q0[i+8], q1[i+8], q0[i+9], q1[i+9]);
}
} else if (key_len == 24) {
for ( i = j = 0, k = 1; i < 256; i++, j += 2, k += 2 ) {
CALC_SB192_2( i, calc_sb_tbl[j], calc_sb_tbl[k] );
}
for ( i = 0; i < 8; i += 2 ) {
CALC_K192 (w, i, q0[i], q1[i], q0[i+1], q1[i+1]);
}
for ( i = 0; i < 32; i += 2 ) {
CALC_K192 (k, i, q0[i+8], q1[i+8], q0[i+9], q1[i+9]);
}
} else {
for ( i = j = 0, k = 1; i < 256; i++, j += 2, k += 2 ) {
CALC_SB_2( i, calc_sb_tbl[j], calc_sb_tbl[k] );
}
for ( i = 0; i < 8; i += 2 ) {
CALC_K (w, i, q0[i], q1[i], q0[i+1], q1[i+1]);
}
for ( i = 0; i < 32; i += 2 ) {
CALC_K (k, i, q0[i+8], q1[i+8], q0[i+9], q1[i+9]);
}
}
return 0;
}
