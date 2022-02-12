static uint64_t load_3(const uint8_t *in) {
uint64_t result;
result = (uint64_t)in[0];
result |= ((uint64_t)in[1]) << 8;
result |= ((uint64_t)in[2]) << 16;
return result;
}
static uint64_t load_4(const uint8_t *in) {
uint64_t result;
result = (uint64_t)in[0];
result |= ((uint64_t)in[1]) << 8;
result |= ((uint64_t)in[2]) << 16;
result |= ((uint64_t)in[3]) << 24;
return result;
}
static void fe_frombytes(fe h, const uint8_t *s) {
int64_t h0 = load_4(s);
int64_t h1 = load_3(s + 4) << 6;
int64_t h2 = load_3(s + 7) << 5;
int64_t h3 = load_3(s + 10) << 3;
int64_t h4 = load_3(s + 13) << 2;
int64_t h5 = load_4(s + 16);
int64_t h6 = load_3(s + 20) << 7;
int64_t h7 = load_3(s + 23) << 5;
int64_t h8 = load_3(s + 26) << 4;
int64_t h9 = (load_3(s + 29) & 8388607) << 2;
int64_t carry0;
int64_t carry1;
int64_t carry2;
int64_t carry3;
int64_t carry4;
int64_t carry5;
int64_t carry6;
int64_t carry7;
int64_t carry8;
int64_t carry9;
carry9 = h9 + (1 << 24); h0 += (carry9 >> 25) * 19; h9 -= carry9 & kTop39Bits;
carry1 = h1 + (1 << 24); h2 += carry1 >> 25; h1 -= carry1 & kTop39Bits;
carry3 = h3 + (1 << 24); h4 += carry3 >> 25; h3 -= carry3 & kTop39Bits;
carry5 = h5 + (1 << 24); h6 += carry5 >> 25; h5 -= carry5 & kTop39Bits;
carry7 = h7 + (1 << 24); h8 += carry7 >> 25; h7 -= carry7 & kTop39Bits;
carry0 = h0 + (1 << 25); h1 += carry0 >> 26; h0 -= carry0 & kTop38Bits;
carry2 = h2 + (1 << 25); h3 += carry2 >> 26; h2 -= carry2 & kTop38Bits;
carry4 = h4 + (1 << 25); h5 += carry4 >> 26; h4 -= carry4 & kTop38Bits;
carry6 = h6 + (1 << 25); h7 += carry6 >> 26; h6 -= carry6 & kTop38Bits;
carry8 = h8 + (1 << 25); h9 += carry8 >> 26; h8 -= carry8 & kTop38Bits;
h[0] = h0;
h[1] = h1;
h[2] = h2;
h[3] = h3;
h[4] = h4;
h[5] = h5;
h[6] = h6;
h[7] = h7;
h[8] = h8;
h[9] = h9;
}
static void fe_tobytes(uint8_t *s, const fe h) {
int32_t h0 = h[0];
int32_t h1 = h[1];
int32_t h2 = h[2];
int32_t h3 = h[3];
int32_t h4 = h[4];
int32_t h5 = h[5];
int32_t h6 = h[6];
int32_t h7 = h[7];
int32_t h8 = h[8];
int32_t h9 = h[9];
int32_t q;
q = (19 * h9 + (((int32_t) 1) << 24)) >> 25;
q = (h0 + q) >> 26;
q = (h1 + q) >> 25;
q = (h2 + q) >> 26;
q = (h3 + q) >> 25;
q = (h4 + q) >> 26;
q = (h5 + q) >> 25;
q = (h6 + q) >> 26;
q = (h7 + q) >> 25;
q = (h8 + q) >> 26;
q = (h9 + q) >> 25;
h0 += 19 * q;
h1 += h0 >> 26; h0 &= kBottom26Bits;
h2 += h1 >> 25; h1 &= kBottom25Bits;
h3 += h2 >> 26; h2 &= kBottom26Bits;
h4 += h3 >> 25; h3 &= kBottom25Bits;
h5 += h4 >> 26; h4 &= kBottom26Bits;
h6 += h5 >> 25; h5 &= kBottom25Bits;
h7 += h6 >> 26; h6 &= kBottom26Bits;
h8 += h7 >> 25; h7 &= kBottom25Bits;
h9 += h8 >> 26; h8 &= kBottom26Bits;
h9 &= kBottom25Bits;
s[0] = h0 >> 0;
s[1] = h0 >> 8;
s[2] = h0 >> 16;
s[3] = (h0 >> 24) | ((uint32_t)(h1) << 2);
s[4] = h1 >> 6;
s[5] = h1 >> 14;
s[6] = (h1 >> 22) | ((uint32_t)(h2) << 3);
s[7] = h2 >> 5;
s[8] = h2 >> 13;
s[9] = (h2 >> 21) | ((uint32_t)(h3) << 5);
s[10] = h3 >> 3;
s[11] = h3 >> 11;
s[12] = (h3 >> 19) | ((uint32_t)(h4) << 6);
s[13] = h4 >> 2;
s[14] = h4 >> 10;
s[15] = h4 >> 18;
s[16] = h5 >> 0;
s[17] = h5 >> 8;
s[18] = h5 >> 16;
s[19] = (h5 >> 24) | ((uint32_t)(h6) << 1);
s[20] = h6 >> 7;
s[21] = h6 >> 15;
s[22] = (h6 >> 23) | ((uint32_t)(h7) << 3);
s[23] = h7 >> 5;
s[24] = h7 >> 13;
s[25] = (h7 >> 21) | ((uint32_t)(h8) << 4);
s[26] = h8 >> 4;
s[27] = h8 >> 12;
s[28] = (h8 >> 20) | ((uint32_t)(h9) << 6);
s[29] = h9 >> 2;
s[30] = h9 >> 10;
s[31] = h9 >> 18;
}
static void fe_copy(fe h, const fe f) {
memmove(h, f, sizeof(int32_t) * 10);
}
static void fe_0(fe h) { memset(h, 0, sizeof(int32_t) * 10); }
static void fe_1(fe h) {
memset(h, 0, sizeof(int32_t) * 10);
h[0] = 1;
}
static void fe_add(fe h, const fe f, const fe g) {
unsigned i;
for (i = 0; i < 10; i++) {
h[i] = f[i] + g[i];
}
}
static void fe_sub(fe h, const fe f, const fe g) {
unsigned i;
for (i = 0; i < 10; i++) {
h[i] = f[i] - g[i];
}
}
static void fe_mul(fe h, const fe f, const fe g) {
int32_t f0 = f[0];
int32_t f1 = f[1];
int32_t f2 = f[2];
int32_t f3 = f[3];
int32_t f4 = f[4];
int32_t f5 = f[5];
int32_t f6 = f[6];
int32_t f7 = f[7];
int32_t f8 = f[8];
int32_t f9 = f[9];
int32_t g0 = g[0];
int32_t g1 = g[1];
int32_t g2 = g[2];
int32_t g3 = g[3];
int32_t g4 = g[4];
int32_t g5 = g[5];
int32_t g6 = g[6];
int32_t g7 = g[7];
int32_t g8 = g[8];
int32_t g9 = g[9];
int32_t g1_19 = 19 * g1;
int32_t g2_19 = 19 * g2;
int32_t g3_19 = 19 * g3;
int32_t g4_19 = 19 * g4;
int32_t g5_19 = 19 * g5;
int32_t g6_19 = 19 * g6;
int32_t g7_19 = 19 * g7;
int32_t g8_19 = 19 * g8;
int32_t g9_19 = 19 * g9;
int32_t f1_2 = 2 * f1;
int32_t f3_2 = 2 * f3;
int32_t f5_2 = 2 * f5;
int32_t f7_2 = 2 * f7;
int32_t f9_2 = 2 * f9;
int64_t f0g0 = f0 * (int64_t) g0;
int64_t f0g1 = f0 * (int64_t) g1;
int64_t f0g2 = f0 * (int64_t) g2;
int64_t f0g3 = f0 * (int64_t) g3;
int64_t f0g4 = f0 * (int64_t) g4;
int64_t f0g5 = f0 * (int64_t) g5;
int64_t f0g6 = f0 * (int64_t) g6;
int64_t f0g7 = f0 * (int64_t) g7;
int64_t f0g8 = f0 * (int64_t) g8;
int64_t f0g9 = f0 * (int64_t) g9;
int64_t f1g0 = f1 * (int64_t) g0;
int64_t f1g1_2 = f1_2 * (int64_t) g1;
int64_t f1g2 = f1 * (int64_t) g2;
int64_t f1g3_2 = f1_2 * (int64_t) g3;
int64_t f1g4 = f1 * (int64_t) g4;
int64_t f1g5_2 = f1_2 * (int64_t) g5;
int64_t f1g6 = f1 * (int64_t) g6;
int64_t f1g7_2 = f1_2 * (int64_t) g7;
int64_t f1g8 = f1 * (int64_t) g8;
int64_t f1g9_38 = f1_2 * (int64_t) g9_19;
int64_t f2g0 = f2 * (int64_t) g0;
int64_t f2g1 = f2 * (int64_t) g1;
int64_t f2g2 = f2 * (int64_t) g2;
int64_t f2g3 = f2 * (int64_t) g3;
int64_t f2g4 = f2 * (int64_t) g4;
int64_t f2g5 = f2 * (int64_t) g5;
int64_t f2g6 = f2 * (int64_t) g6;
int64_t f2g7 = f2 * (int64_t) g7;
int64_t f2g8_19 = f2 * (int64_t) g8_19;
int64_t f2g9_19 = f2 * (int64_t) g9_19;
int64_t f3g0 = f3 * (int64_t) g0;
int64_t f3g1_2 = f3_2 * (int64_t) g1;
int64_t f3g2 = f3 * (int64_t) g2;
int64_t f3g3_2 = f3_2 * (int64_t) g3;
int64_t f3g4 = f3 * (int64_t) g4;
int64_t f3g5_2 = f3_2 * (int64_t) g5;
int64_t f3g6 = f3 * (int64_t) g6;
int64_t f3g7_38 = f3_2 * (int64_t) g7_19;
int64_t f3g8_19 = f3 * (int64_t) g8_19;
int64_t f3g9_38 = f3_2 * (int64_t) g9_19;
int64_t f4g0 = f4 * (int64_t) g0;
int64_t f4g1 = f4 * (int64_t) g1;
int64_t f4g2 = f4 * (int64_t) g2;
int64_t f4g3 = f4 * (int64_t) g3;
int64_t f4g4 = f4 * (int64_t) g4;
int64_t f4g5 = f4 * (int64_t) g5;
int64_t f4g6_19 = f4 * (int64_t) g6_19;
int64_t f4g7_19 = f4 * (int64_t) g7_19;
int64_t f4g8_19 = f4 * (int64_t) g8_19;
int64_t f4g9_19 = f4 * (int64_t) g9_19;
int64_t f5g0 = f5 * (int64_t) g0;
int64_t f5g1_2 = f5_2 * (int64_t) g1;
int64_t f5g2 = f5 * (int64_t) g2;
int64_t f5g3_2 = f5_2 * (int64_t) g3;
int64_t f5g4 = f5 * (int64_t) g4;
int64_t f5g5_38 = f5_2 * (int64_t) g5_19;
int64_t f5g6_19 = f5 * (int64_t) g6_19;
int64_t f5g7_38 = f5_2 * (int64_t) g7_19;
int64_t f5g8_19 = f5 * (int64_t) g8_19;
int64_t f5g9_38 = f5_2 * (int64_t) g9_19;
int64_t f6g0 = f6 * (int64_t) g0;
int64_t f6g1 = f6 * (int64_t) g1;
int64_t f6g2 = f6 * (int64_t) g2;
int64_t f6g3 = f6 * (int64_t) g3;
int64_t f6g4_19 = f6 * (int64_t) g4_19;
int64_t f6g5_19 = f6 * (int64_t) g5_19;
int64_t f6g6_19 = f6 * (int64_t) g6_19;
int64_t f6g7_19 = f6 * (int64_t) g7_19;
int64_t f6g8_19 = f6 * (int64_t) g8_19;
int64_t f6g9_19 = f6 * (int64_t) g9_19;
int64_t f7g0 = f7 * (int64_t) g0;
int64_t f7g1_2 = f7_2 * (int64_t) g1;
int64_t f7g2 = f7 * (int64_t) g2;
int64_t f7g3_38 = f7_2 * (int64_t) g3_19;
int64_t f7g4_19 = f7 * (int64_t) g4_19;
int64_t f7g5_38 = f7_2 * (int64_t) g5_19;
int64_t f7g6_19 = f7 * (int64_t) g6_19;
int64_t f7g7_38 = f7_2 * (int64_t) g7_19;
int64_t f7g8_19 = f7 * (int64_t) g8_19;
int64_t f7g9_38 = f7_2 * (int64_t) g9_19;
int64_t f8g0 = f8 * (int64_t) g0;
int64_t f8g1 = f8 * (int64_t) g1;
int64_t f8g2_19 = f8 * (int64_t) g2_19;
int64_t f8g3_19 = f8 * (int64_t) g3_19;
int64_t f8g4_19 = f8 * (int64_t) g4_19;
int64_t f8g5_19 = f8 * (int64_t) g5_19;
int64_t f8g6_19 = f8 * (int64_t) g6_19;
int64_t f8g7_19 = f8 * (int64_t) g7_19;
int64_t f8g8_19 = f8 * (int64_t) g8_19;
int64_t f8g9_19 = f8 * (int64_t) g9_19;
int64_t f9g0 = f9 * (int64_t) g0;
int64_t f9g1_38 = f9_2 * (int64_t) g1_19;
int64_t f9g2_19 = f9 * (int64_t) g2_19;
int64_t f9g3_38 = f9_2 * (int64_t) g3_19;
int64_t f9g4_19 = f9 * (int64_t) g4_19;
int64_t f9g5_38 = f9_2 * (int64_t) g5_19;
int64_t f9g6_19 = f9 * (int64_t) g6_19;
int64_t f9g7_38 = f9_2 * (int64_t) g7_19;
int64_t f9g8_19 = f9 * (int64_t) g8_19;
int64_t f9g9_38 = f9_2 * (int64_t) g9_19;
int64_t h0 = f0g0+f1g9_38+f2g8_19+f3g7_38+f4g6_19+f5g5_38+f6g4_19+f7g3_38+f8g2_19+f9g1_38;
int64_t h1 = f0g1+f1g0 +f2g9_19+f3g8_19+f4g7_19+f5g6_19+f6g5_19+f7g4_19+f8g3_19+f9g2_19;
int64_t h2 = f0g2+f1g1_2 +f2g0 +f3g9_38+f4g8_19+f5g7_38+f6g6_19+f7g5_38+f8g4_19+f9g3_38;
int64_t h3 = f0g3+f1g2 +f2g1 +f3g0 +f4g9_19+f5g8_19+f6g7_19+f7g6_19+f8g5_19+f9g4_19;
int64_t h4 = f0g4+f1g3_2 +f2g2 +f3g1_2 +f4g0 +f5g9_38+f6g8_19+f7g7_38+f8g6_19+f9g5_38;
int64_t h5 = f0g5+f1g4 +f2g3 +f3g2 +f4g1 +f5g0 +f6g9_19+f7g8_19+f8g7_19+f9g6_19;
int64_t h6 = f0g6+f1g5_2 +f2g4 +f3g3_2 +f4g2 +f5g1_2 +f6g0 +f7g9_38+f8g8_19+f9g7_38;
int64_t h7 = f0g7+f1g6 +f2g5 +f3g4 +f4g3 +f5g2 +f6g1 +f7g0 +f8g9_19+f9g8_19;
int64_t h8 = f0g8+f1g7_2 +f2g6 +f3g5_2 +f4g4 +f5g3_2 +f6g2 +f7g1_2 +f8g0 +f9g9_38;
int64_t h9 = f0g9+f1g8 +f2g7 +f3g6 +f4g5 +f5g4 +f6g3 +f7g2 +f8g1 +f9g0 ;
int64_t carry0;
int64_t carry1;
int64_t carry2;
int64_t carry3;
int64_t carry4;
int64_t carry5;
int64_t carry6;
int64_t carry7;
int64_t carry8;
int64_t carry9;
carry0 = h0 + (1 << 25); h1 += carry0 >> 26; h0 -= carry0 & kTop38Bits;
carry4 = h4 + (1 << 25); h5 += carry4 >> 26; h4 -= carry4 & kTop38Bits;
carry1 = h1 + (1 << 24); h2 += carry1 >> 25; h1 -= carry1 & kTop39Bits;
carry5 = h5 + (1 << 24); h6 += carry5 >> 25; h5 -= carry5 & kTop39Bits;
carry2 = h2 + (1 << 25); h3 += carry2 >> 26; h2 -= carry2 & kTop38Bits;
carry6 = h6 + (1 << 25); h7 += carry6 >> 26; h6 -= carry6 & kTop38Bits;
carry3 = h3 + (1 << 24); h4 += carry3 >> 25; h3 -= carry3 & kTop39Bits;
carry7 = h7 + (1 << 24); h8 += carry7 >> 25; h7 -= carry7 & kTop39Bits;
carry4 = h4 + (1 << 25); h5 += carry4 >> 26; h4 -= carry4 & kTop38Bits;
carry8 = h8 + (1 << 25); h9 += carry8 >> 26; h8 -= carry8 & kTop38Bits;
carry9 = h9 + (1 << 24); h0 += (carry9 >> 25) * 19; h9 -= carry9 & kTop39Bits;
carry0 = h0 + (1 << 25); h1 += carry0 >> 26; h0 -= carry0 & kTop38Bits;
h[0] = h0;
h[1] = h1;
h[2] = h2;
h[3] = h3;
h[4] = h4;
h[5] = h5;
h[6] = h6;
h[7] = h7;
h[8] = h8;
h[9] = h9;
}
static void fe_sq(fe h, const fe f) {
int32_t f0 = f[0];
int32_t f1 = f[1];
int32_t f2 = f[2];
int32_t f3 = f[3];
int32_t f4 = f[4];
int32_t f5 = f[5];
int32_t f6 = f[6];
int32_t f7 = f[7];
int32_t f8 = f[8];
int32_t f9 = f[9];
int32_t f0_2 = 2 * f0;
int32_t f1_2 = 2 * f1;
int32_t f2_2 = 2 * f2;
int32_t f3_2 = 2 * f3;
int32_t f4_2 = 2 * f4;
int32_t f5_2 = 2 * f5;
int32_t f6_2 = 2 * f6;
int32_t f7_2 = 2 * f7;
int32_t f5_38 = 38 * f5;
int32_t f6_19 = 19 * f6;
int32_t f7_38 = 38 * f7;
int32_t f8_19 = 19 * f8;
int32_t f9_38 = 38 * f9;
int64_t f0f0 = f0 * (int64_t) f0;
int64_t f0f1_2 = f0_2 * (int64_t) f1;
int64_t f0f2_2 = f0_2 * (int64_t) f2;
int64_t f0f3_2 = f0_2 * (int64_t) f3;
int64_t f0f4_2 = f0_2 * (int64_t) f4;
int64_t f0f5_2 = f0_2 * (int64_t) f5;
int64_t f0f6_2 = f0_2 * (int64_t) f6;
int64_t f0f7_2 = f0_2 * (int64_t) f7;
int64_t f0f8_2 = f0_2 * (int64_t) f8;
int64_t f0f9_2 = f0_2 * (int64_t) f9;
int64_t f1f1_2 = f1_2 * (int64_t) f1;
int64_t f1f2_2 = f1_2 * (int64_t) f2;
int64_t f1f3_4 = f1_2 * (int64_t) f3_2;
int64_t f1f4_2 = f1_2 * (int64_t) f4;
int64_t f1f5_4 = f1_2 * (int64_t) f5_2;
int64_t f1f6_2 = f1_2 * (int64_t) f6;
int64_t f1f7_4 = f1_2 * (int64_t) f7_2;
int64_t f1f8_2 = f1_2 * (int64_t) f8;
int64_t f1f9_76 = f1_2 * (int64_t) f9_38;
int64_t f2f2 = f2 * (int64_t) f2;
int64_t f2f3_2 = f2_2 * (int64_t) f3;
int64_t f2f4_2 = f2_2 * (int64_t) f4;
int64_t f2f5_2 = f2_2 * (int64_t) f5;
int64_t f2f6_2 = f2_2 * (int64_t) f6;
int64_t f2f7_2 = f2_2 * (int64_t) f7;
int64_t f2f8_38 = f2_2 * (int64_t) f8_19;
int64_t f2f9_38 = f2 * (int64_t) f9_38;
int64_t f3f3_2 = f3_2 * (int64_t) f3;
int64_t f3f4_2 = f3_2 * (int64_t) f4;
int64_t f3f5_4 = f3_2 * (int64_t) f5_2;
int64_t f3f6_2 = f3_2 * (int64_t) f6;
int64_t f3f7_76 = f3_2 * (int64_t) f7_38;
int64_t f3f8_38 = f3_2 * (int64_t) f8_19;
int64_t f3f9_76 = f3_2 * (int64_t) f9_38;
int64_t f4f4 = f4 * (int64_t) f4;
int64_t f4f5_2 = f4_2 * (int64_t) f5;
int64_t f4f6_38 = f4_2 * (int64_t) f6_19;
int64_t f4f7_38 = f4 * (int64_t) f7_38;
int64_t f4f8_38 = f4_2 * (int64_t) f8_19;
int64_t f4f9_38 = f4 * (int64_t) f9_38;
int64_t f5f5_38 = f5 * (int64_t) f5_38;
int64_t f5f6_38 = f5_2 * (int64_t) f6_19;
int64_t f5f7_76 = f5_2 * (int64_t) f7_38;
int64_t f5f8_38 = f5_2 * (int64_t) f8_19;
int64_t f5f9_76 = f5_2 * (int64_t) f9_38;
int64_t f6f6_19 = f6 * (int64_t) f6_19;
int64_t f6f7_38 = f6 * (int64_t) f7_38;
int64_t f6f8_38 = f6_2 * (int64_t) f8_19;
int64_t f6f9_38 = f6 * (int64_t) f9_38;
int64_t f7f7_38 = f7 * (int64_t) f7_38;
int64_t f7f8_38 = f7_2 * (int64_t) f8_19;
int64_t f7f9_76 = f7_2 * (int64_t) f9_38;
int64_t f8f8_19 = f8 * (int64_t) f8_19;
int64_t f8f9_38 = f8 * (int64_t) f9_38;
int64_t f9f9_38 = f9 * (int64_t) f9_38;
int64_t h0 = f0f0 +f1f9_76+f2f8_38+f3f7_76+f4f6_38+f5f5_38;
int64_t h1 = f0f1_2+f2f9_38+f3f8_38+f4f7_38+f5f6_38;
int64_t h2 = f0f2_2+f1f1_2 +f3f9_76+f4f8_38+f5f7_76+f6f6_19;
int64_t h3 = f0f3_2+f1f2_2 +f4f9_38+f5f8_38+f6f7_38;
int64_t h4 = f0f4_2+f1f3_4 +f2f2 +f5f9_76+f6f8_38+f7f7_38;
int64_t h5 = f0f5_2+f1f4_2 +f2f3_2 +f6f9_38+f7f8_38;
int64_t h6 = f0f6_2+f1f5_4 +f2f4_2 +f3f3_2 +f7f9_76+f8f8_19;
int64_t h7 = f0f7_2+f1f6_2 +f2f5_2 +f3f4_2 +f8f9_38;
int64_t h8 = f0f8_2+f1f7_4 +f2f6_2 +f3f5_4 +f4f4 +f9f9_38;
int64_t h9 = f0f9_2+f1f8_2 +f2f7_2 +f3f6_2 +f4f5_2;
int64_t carry0;
int64_t carry1;
int64_t carry2;
int64_t carry3;
int64_t carry4;
int64_t carry5;
int64_t carry6;
int64_t carry7;
int64_t carry8;
int64_t carry9;
carry0 = h0 + (1 << 25); h1 += carry0 >> 26; h0 -= carry0 & kTop38Bits;
carry4 = h4 + (1 << 25); h5 += carry4 >> 26; h4 -= carry4 & kTop38Bits;
carry1 = h1 + (1 << 24); h2 += carry1 >> 25; h1 -= carry1 & kTop39Bits;
carry5 = h5 + (1 << 24); h6 += carry5 >> 25; h5 -= carry5 & kTop39Bits;
carry2 = h2 + (1 << 25); h3 += carry2 >> 26; h2 -= carry2 & kTop38Bits;
carry6 = h6 + (1 << 25); h7 += carry6 >> 26; h6 -= carry6 & kTop38Bits;
carry3 = h3 + (1 << 24); h4 += carry3 >> 25; h3 -= carry3 & kTop39Bits;
carry7 = h7 + (1 << 24); h8 += carry7 >> 25; h7 -= carry7 & kTop39Bits;
carry4 = h4 + (1 << 25); h5 += carry4 >> 26; h4 -= carry4 & kTop38Bits;
carry8 = h8 + (1 << 25); h9 += carry8 >> 26; h8 -= carry8 & kTop38Bits;
carry9 = h9 + (1 << 24); h0 += (carry9 >> 25) * 19; h9 -= carry9 & kTop39Bits;
carry0 = h0 + (1 << 25); h1 += carry0 >> 26; h0 -= carry0 & kTop38Bits;
h[0] = h0;
h[1] = h1;
h[2] = h2;
h[3] = h3;
h[4] = h4;
h[5] = h5;
h[6] = h6;
h[7] = h7;
h[8] = h8;
h[9] = h9;
}
static void fe_invert(fe out, const fe z) {
fe t0;
fe t1;
fe t2;
fe t3;
int i;
fe_sq(t0, z);
fe_sq(t1, t0);
fe_sq(t1, t1);
fe_mul(t1, z, t1);
fe_mul(t0, t0, t1);
fe_sq(t2, t0);
fe_mul(t1, t1, t2);
fe_sq(t2, t1);
for (i = 1; i < 5; ++i) {
fe_sq(t2, t2);
}
fe_mul(t1, t2, t1);
fe_sq(t2, t1);
for (i = 1; i < 10; ++i) {
fe_sq(t2, t2);
}
fe_mul(t2, t2, t1);
fe_sq(t3, t2);
for (i = 1; i < 20; ++i) {
fe_sq(t3, t3);
}
fe_mul(t2, t3, t2);
for (i = 0; i < 10; ++i) {
fe_sq(t2, t2);
}
fe_mul(t1, t2, t1);
fe_sq(t2, t1);
for (i = 1; i < 50; ++i) {
fe_sq(t2, t2);
}
fe_mul(t2, t2, t1);
fe_sq(t3, t2);
for (i = 1; i < 100; ++i) {
fe_sq(t3, t3);
}
fe_mul(t2, t3, t2);
fe_sq(t2, t2);
for (i = 1; i < 50; ++i) {
fe_sq(t2, t2);
}
fe_mul(t1, t2, t1);
fe_sq(t1, t1);
for (i = 1; i < 5; ++i) {
fe_sq(t1, t1);
}
fe_mul(out, t1, t0);
}
static void fe_neg(fe h, const fe f) {
unsigned i;
for (i = 0; i < 10; i++) {
h[i] = -f[i];
}
}
static void fe_cmov(fe f, const fe g, unsigned b) {
size_t i;
b = 0-b;
for (i = 0; i < 10; i++) {
int32_t x = f[i] ^ g[i];
x &= b;
f[i] ^= x;
}
}
static void fe_sq2(fe h, const fe f) {
int32_t f0 = f[0];
int32_t f1 = f[1];
int32_t f2 = f[2];
int32_t f3 = f[3];
int32_t f4 = f[4];
int32_t f5 = f[5];
int32_t f6 = f[6];
int32_t f7 = f[7];
int32_t f8 = f[8];
int32_t f9 = f[9];
int32_t f0_2 = 2 * f0;
int32_t f1_2 = 2 * f1;
int32_t f2_2 = 2 * f2;
int32_t f3_2 = 2 * f3;
int32_t f4_2 = 2 * f4;
int32_t f5_2 = 2 * f5;
int32_t f6_2 = 2 * f6;
int32_t f7_2 = 2 * f7;
int32_t f5_38 = 38 * f5;
int32_t f6_19 = 19 * f6;
int32_t f7_38 = 38 * f7;
int32_t f8_19 = 19 * f8;
int32_t f9_38 = 38 * f9;
int64_t f0f0 = f0 * (int64_t) f0;
int64_t f0f1_2 = f0_2 * (int64_t) f1;
int64_t f0f2_2 = f0_2 * (int64_t) f2;
int64_t f0f3_2 = f0_2 * (int64_t) f3;
int64_t f0f4_2 = f0_2 * (int64_t) f4;
int64_t f0f5_2 = f0_2 * (int64_t) f5;
int64_t f0f6_2 = f0_2 * (int64_t) f6;
int64_t f0f7_2 = f0_2 * (int64_t) f7;
int64_t f0f8_2 = f0_2 * (int64_t) f8;
int64_t f0f9_2 = f0_2 * (int64_t) f9;
int64_t f1f1_2 = f1_2 * (int64_t) f1;
int64_t f1f2_2 = f1_2 * (int64_t) f2;
int64_t f1f3_4 = f1_2 * (int64_t) f3_2;
int64_t f1f4_2 = f1_2 * (int64_t) f4;
int64_t f1f5_4 = f1_2 * (int64_t) f5_2;
int64_t f1f6_2 = f1_2 * (int64_t) f6;
int64_t f1f7_4 = f1_2 * (int64_t) f7_2;
int64_t f1f8_2 = f1_2 * (int64_t) f8;
int64_t f1f9_76 = f1_2 * (int64_t) f9_38;
int64_t f2f2 = f2 * (int64_t) f2;
int64_t f2f3_2 = f2_2 * (int64_t) f3;
int64_t f2f4_2 = f2_2 * (int64_t) f4;
int64_t f2f5_2 = f2_2 * (int64_t) f5;
int64_t f2f6_2 = f2_2 * (int64_t) f6;
int64_t f2f7_2 = f2_2 * (int64_t) f7;
int64_t f2f8_38 = f2_2 * (int64_t) f8_19;
int64_t f2f9_38 = f2 * (int64_t) f9_38;
int64_t f3f3_2 = f3_2 * (int64_t) f3;
int64_t f3f4_2 = f3_2 * (int64_t) f4;
int64_t f3f5_4 = f3_2 * (int64_t) f5_2;
int64_t f3f6_2 = f3_2 * (int64_t) f6;
int64_t f3f7_76 = f3_2 * (int64_t) f7_38;
int64_t f3f8_38 = f3_2 * (int64_t) f8_19;
int64_t f3f9_76 = f3_2 * (int64_t) f9_38;
int64_t f4f4 = f4 * (int64_t) f4;
int64_t f4f5_2 = f4_2 * (int64_t) f5;
int64_t f4f6_38 = f4_2 * (int64_t) f6_19;
int64_t f4f7_38 = f4 * (int64_t) f7_38;
int64_t f4f8_38 = f4_2 * (int64_t) f8_19;
int64_t f4f9_38 = f4 * (int64_t) f9_38;
int64_t f5f5_38 = f5 * (int64_t) f5_38;
int64_t f5f6_38 = f5_2 * (int64_t) f6_19;
int64_t f5f7_76 = f5_2 * (int64_t) f7_38;
int64_t f5f8_38 = f5_2 * (int64_t) f8_19;
int64_t f5f9_76 = f5_2 * (int64_t) f9_38;
int64_t f6f6_19 = f6 * (int64_t) f6_19;
int64_t f6f7_38 = f6 * (int64_t) f7_38;
int64_t f6f8_38 = f6_2 * (int64_t) f8_19;
int64_t f6f9_38 = f6 * (int64_t) f9_38;
int64_t f7f7_38 = f7 * (int64_t) f7_38;
int64_t f7f8_38 = f7_2 * (int64_t) f8_19;
int64_t f7f9_76 = f7_2 * (int64_t) f9_38;
int64_t f8f8_19 = f8 * (int64_t) f8_19;
int64_t f8f9_38 = f8 * (int64_t) f9_38;
int64_t f9f9_38 = f9 * (int64_t) f9_38;
int64_t h0 = f0f0 +f1f9_76+f2f8_38+f3f7_76+f4f6_38+f5f5_38;
int64_t h1 = f0f1_2+f2f9_38+f3f8_38+f4f7_38+f5f6_38;
int64_t h2 = f0f2_2+f1f1_2 +f3f9_76+f4f8_38+f5f7_76+f6f6_19;
int64_t h3 = f0f3_2+f1f2_2 +f4f9_38+f5f8_38+f6f7_38;
int64_t h4 = f0f4_2+f1f3_4 +f2f2 +f5f9_76+f6f8_38+f7f7_38;
int64_t h5 = f0f5_2+f1f4_2 +f2f3_2 +f6f9_38+f7f8_38;
int64_t h6 = f0f6_2+f1f5_4 +f2f4_2 +f3f3_2 +f7f9_76+f8f8_19;
int64_t h7 = f0f7_2+f1f6_2 +f2f5_2 +f3f4_2 +f8f9_38;
int64_t h8 = f0f8_2+f1f7_4 +f2f6_2 +f3f5_4 +f4f4 +f9f9_38;
int64_t h9 = f0f9_2+f1f8_2 +f2f7_2 +f3f6_2 +f4f5_2;
int64_t carry0;
int64_t carry1;
int64_t carry2;
int64_t carry3;
int64_t carry4;
int64_t carry5;
int64_t carry6;
int64_t carry7;
int64_t carry8;
int64_t carry9;
h0 += h0;
h1 += h1;
h2 += h2;
h3 += h3;
h4 += h4;
h5 += h5;
h6 += h6;
h7 += h7;
h8 += h8;
h9 += h9;
carry0 = h0 + (1 << 25); h1 += carry0 >> 26; h0 -= carry0 & kTop38Bits;
carry4 = h4 + (1 << 25); h5 += carry4 >> 26; h4 -= carry4 & kTop38Bits;
carry1 = h1 + (1 << 24); h2 += carry1 >> 25; h1 -= carry1 & kTop39Bits;
carry5 = h5 + (1 << 24); h6 += carry5 >> 25; h5 -= carry5 & kTop39Bits;
carry2 = h2 + (1 << 25); h3 += carry2 >> 26; h2 -= carry2 & kTop38Bits;
carry6 = h6 + (1 << 25); h7 += carry6 >> 26; h6 -= carry6 & kTop38Bits;
carry3 = h3 + (1 << 24); h4 += carry3 >> 25; h3 -= carry3 & kTop39Bits;
carry7 = h7 + (1 << 24); h8 += carry7 >> 25; h7 -= carry7 & kTop39Bits;
carry4 = h4 + (1 << 25); h5 += carry4 >> 26; h4 -= carry4 & kTop38Bits;
carry8 = h8 + (1 << 25); h9 += carry8 >> 26; h8 -= carry8 & kTop38Bits;
carry9 = h9 + (1 << 24); h0 += (carry9 >> 25) * 19; h9 -= carry9 & kTop39Bits;
carry0 = h0 + (1 << 25); h1 += carry0 >> 26; h0 -= carry0 & kTop38Bits;
h[0] = h0;
h[1] = h1;
h[2] = h2;
h[3] = h3;
h[4] = h4;
h[5] = h5;
h[6] = h6;
h[7] = h7;
h[8] = h8;
h[9] = h9;
}
static void ge_p3_0(ge_p3 *h) {
fe_0(h->X);
fe_1(h->Y);
fe_1(h->Z);
fe_0(h->T);
}
static void ge_precomp_0(ge_precomp *h) {
fe_1(h->yplusx);
fe_1(h->yminusx);
fe_0(h->xy2d);
}
static void ge_p3_to_p2(ge_p2 *r, const ge_p3 *p) {
fe_copy(r->X, p->X);
fe_copy(r->Y, p->Y);
fe_copy(r->Z, p->Z);
}
static void ge_p1p1_to_p2(ge_p2 *r, const ge_p1p1 *p) {
fe_mul(r->X, p->X, p->T);
fe_mul(r->Y, p->Y, p->Z);
fe_mul(r->Z, p->Z, p->T);
}
static void ge_p1p1_to_p3(ge_p3 *r, const ge_p1p1 *p) {
fe_mul(r->X, p->X, p->T);
fe_mul(r->Y, p->Y, p->Z);
fe_mul(r->Z, p->Z, p->T);
fe_mul(r->T, p->X, p->Y);
}
static void ge_p2_dbl(ge_p1p1 *r, const ge_p2 *p) {
fe t0;
fe_sq(r->X, p->X);
fe_sq(r->Z, p->Y);
fe_sq2(r->T, p->Z);
fe_add(r->Y, p->X, p->Y);
fe_sq(t0, r->Y);
fe_add(r->Y, r->Z, r->X);
fe_sub(r->Z, r->Z, r->X);
fe_sub(r->X, t0, r->Y);
fe_sub(r->T, r->T, r->Z);
}
static void ge_p3_dbl(ge_p1p1 *r, const ge_p3 *p) {
ge_p2 q;
ge_p3_to_p2(&q, p);
ge_p2_dbl(r, &q);
}
static void ge_madd(ge_p1p1 *r, const ge_p3 *p, const ge_precomp *q) {
fe t0;
fe_add(r->X, p->Y, p->X);
fe_sub(r->Y, p->Y, p->X);
fe_mul(r->Z, r->X, q->yplusx);
fe_mul(r->Y, r->Y, q->yminusx);
fe_mul(r->T, q->xy2d, p->T);
fe_add(t0, p->Z, p->Z);
fe_sub(r->X, r->Z, r->Y);
fe_add(r->Y, r->Z, r->Y);
fe_add(r->Z, t0, r->T);
fe_sub(r->T, t0, r->T);
}
static uint8_t equal(signed char b, signed char c) {
uint8_t ub = b;
uint8_t uc = c;
uint8_t x = ub ^ uc;
uint32_t y = x;
y -= 1;
y >>= 31;
return y;
}
static void cmov(ge_precomp *t, const ge_precomp *u, uint8_t b) {
fe_cmov(t->yplusx, u->yplusx, b);
fe_cmov(t->yminusx, u->yminusx, b);
fe_cmov(t->xy2d, u->xy2d, b);
}
static uint8_t negative(signed char b) {
uint32_t x = b;
x >>= 31;
return x;
}
static void table_select(ge_precomp *t, int pos, signed char b) {
ge_precomp minust;
uint8_t bnegative = negative(b);
uint8_t babs = b - ((uint8_t)((-bnegative) & b) << 1);
ge_precomp_0(t);
cmov(t, &k25519Precomp[pos][0], equal(babs, 1));
cmov(t, &k25519Precomp[pos][1], equal(babs, 2));
cmov(t, &k25519Precomp[pos][2], equal(babs, 3));
cmov(t, &k25519Precomp[pos][3], equal(babs, 4));
cmov(t, &k25519Precomp[pos][4], equal(babs, 5));
cmov(t, &k25519Precomp[pos][5], equal(babs, 6));
cmov(t, &k25519Precomp[pos][6], equal(babs, 7));
cmov(t, &k25519Precomp[pos][7], equal(babs, 8));
fe_copy(minust.yplusx, t->yminusx);
fe_copy(minust.yminusx, t->yplusx);
fe_neg(minust.xy2d, t->xy2d);
cmov(t, &minust, bnegative);
}
static void ge_scalarmult_base(ge_p3 *h, const uint8_t *a) {
signed char e[64];
signed char carry;
ge_p1p1 r;
ge_p2 s;
ge_precomp t;
int i;
for (i = 0; i < 32; ++i) {
e[2 * i + 0] = (a[i] >> 0) & 15;
e[2 * i + 1] = (a[i] >> 4) & 15;
}
carry = 0;
for (i = 0; i < 63; ++i) {
e[i] += carry;
carry = e[i] + 8;
carry >>= 4;
e[i] -= carry << 4;
}
e[63] += carry;
ge_p3_0(h);
for (i = 1; i < 64; i += 2) {
table_select(&t, i / 2, e[i]);
ge_madd(&r, h, &t);
ge_p1p1_to_p3(h, &r);
}
ge_p3_dbl(&r, h);
ge_p1p1_to_p2(&s, &r);
ge_p2_dbl(&r, &s);
ge_p1p1_to_p2(&s, &r);
ge_p2_dbl(&r, &s);
ge_p1p1_to_p2(&s, &r);
ge_p2_dbl(&r, &s);
ge_p1p1_to_p3(h, &r);
for (i = 0; i < 64; i += 2) {
table_select(&t, i / 2, e[i]);
ge_madd(&r, h, &t);
ge_p1p1_to_p3(h, &r);
}
}
static void fe_cswap(fe f, fe g, unsigned int b) {
size_t i;
b = 0-b;
for (i = 0; i < 10; i++) {
int32_t x = f[i] ^ g[i];
x &= b;
f[i] ^= x;
g[i] ^= x;
}
}
static void fe_mul121666(fe h, fe f) {
int32_t f0 = f[0];
int32_t f1 = f[1];
int32_t f2 = f[2];
int32_t f3 = f[3];
int32_t f4 = f[4];
int32_t f5 = f[5];
int32_t f6 = f[6];
int32_t f7 = f[7];
int32_t f8 = f[8];
int32_t f9 = f[9];
int64_t h0 = f0 * (int64_t) 121666;
int64_t h1 = f1 * (int64_t) 121666;
int64_t h2 = f2 * (int64_t) 121666;
int64_t h3 = f3 * (int64_t) 121666;
int64_t h4 = f4 * (int64_t) 121666;
int64_t h5 = f5 * (int64_t) 121666;
int64_t h6 = f6 * (int64_t) 121666;
int64_t h7 = f7 * (int64_t) 121666;
int64_t h8 = f8 * (int64_t) 121666;
int64_t h9 = f9 * (int64_t) 121666;
int64_t carry0;
int64_t carry1;
int64_t carry2;
int64_t carry3;
int64_t carry4;
int64_t carry5;
int64_t carry6;
int64_t carry7;
int64_t carry8;
int64_t carry9;
carry9 = h9 + (1 << 24); h0 += (carry9 >> 25) * 19; h9 -= carry9 & kTop39Bits;
carry1 = h1 + (1 << 24); h2 += carry1 >> 25; h1 -= carry1 & kTop39Bits;
carry3 = h3 + (1 << 24); h4 += carry3 >> 25; h3 -= carry3 & kTop39Bits;
carry5 = h5 + (1 << 24); h6 += carry5 >> 25; h5 -= carry5 & kTop39Bits;
carry7 = h7 + (1 << 24); h8 += carry7 >> 25; h7 -= carry7 & kTop39Bits;
carry0 = h0 + (1 << 25); h1 += carry0 >> 26; h0 -= carry0 & kTop38Bits;
carry2 = h2 + (1 << 25); h3 += carry2 >> 26; h2 -= carry2 & kTop38Bits;
carry4 = h4 + (1 << 25); h5 += carry4 >> 26; h4 -= carry4 & kTop38Bits;
carry6 = h6 + (1 << 25); h7 += carry6 >> 26; h6 -= carry6 & kTop38Bits;
carry8 = h8 + (1 << 25); h9 += carry8 >> 26; h8 -= carry8 & kTop38Bits;
h[0] = h0;
h[1] = h1;
h[2] = h2;
h[3] = h3;
h[4] = h4;
h[5] = h5;
h[6] = h6;
h[7] = h7;
h[8] = h8;
h[9] = h9;
}
static void x25519_scalar_mult_generic(uint8_t out[32],
const uint8_t scalar[32],
const uint8_t point[32]) {
fe x1, x2, z2, x3, z3, tmp0, tmp1;
uint8_t e[32];
unsigned swap = 0;
int pos;
memcpy(e, scalar, 32);
e[0] &= 248;
e[31] &= 127;
e[31] |= 64;
fe_frombytes(x1, point);
fe_1(x2);
fe_0(z2);
fe_copy(x3, x1);
fe_1(z3);
for (pos = 254; pos >= 0; --pos) {
unsigned b = 1 & (e[pos / 8] >> (pos & 7));
swap ^= b;
fe_cswap(x2, x3, swap);
fe_cswap(z2, z3, swap);
swap = b;
fe_sub(tmp0, x3, z3);
fe_sub(tmp1, x2, z2);
fe_add(x2, x2, z2);
fe_add(z2, x3, z3);
fe_mul(z3, tmp0, x2);
fe_mul(z2, z2, tmp1);
fe_sq(tmp0, tmp1);
fe_sq(tmp1, x2);
fe_add(x3, z3, z2);
fe_sub(z2, z3, z2);
fe_mul(x2, tmp1, tmp0);
fe_sub(tmp1, tmp1, tmp0);
fe_sq(z2, z2);
fe_mul121666(z3, tmp1);
fe_sq(x3, x3);
fe_add(tmp0, tmp0, z3);
fe_mul(z3, x1, z2);
fe_mul(z2, tmp1, tmp0);
}
fe_cswap(x2, x3, swap);
fe_cswap(z2, z3, swap);
fe_invert(z2, z2);
fe_mul(x2, x2, z2);
fe_tobytes(out, x2);
}
static void x25519_scalar_mult(uint8_t out[32], const uint8_t scalar[32],
const uint8_t point[32]) {
x25519_scalar_mult_generic(out, scalar, point);
}
int X25519(uint8_t out_shared_key[32], const uint8_t private_key[32],
const uint8_t peer_public_value[32]) {
static const uint8_t kZeros[32] = {0};
x25519_scalar_mult(out_shared_key, private_key, peer_public_value);
return CRYPTO_memcmp(kZeros, out_shared_key, 32) != 0;
}
void X25519_public_from_private(uint8_t out_public_value[32],
const uint8_t private_key[32]) {
uint8_t e[32];
ge_p3 A;
fe zplusy, zminusy, zminusy_inv;
memcpy(e, private_key, 32);
e[0] &= 248;
e[31] &= 127;
e[31] |= 64;
ge_scalarmult_base(&A, e);
fe_add(zplusy, A.Z, A.Y);
fe_sub(zminusy, A.Z, A.Y);
fe_invert(zminusy_inv, zminusy);
fe_mul(zplusy, zplusy, zminusy_inv);
fe_tobytes(out_public_value, zplusy);
}
