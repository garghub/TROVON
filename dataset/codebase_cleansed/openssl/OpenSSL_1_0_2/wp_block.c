void whirlpool_block(WHIRLPOOL_CTX *ctx, const void *inp, size_t n)
{
int r;
const u8 *p = inp;
union {
u64 q[8];
u8 c[64];
} S, K, *H = (void *)ctx->H.q;
#ifdef GO_FOR_MMX
GO_FOR_MMX(ctx, inp, n);
#endif
do {
#ifdef OPENSSL_SMALL_FOOTPRINT
u64 L[8];
int i;
for (i = 0; i < 64; i++)
S.c[i] = (K.c[i] = H->c[i]) ^ p[i];
for (r = 0; r < ROUNDS; r++) {
for (i = 0; i < 8; i++) {
L[i] = i ? 0 : RC[r];
L[i] ^= C0(K, i) ^ C1(K, (i - 1) & 7) ^
C2(K, (i - 2) & 7) ^ C3(K, (i - 3) & 7) ^
C4(K, (i - 4) & 7) ^ C5(K, (i - 5) & 7) ^
C6(K, (i - 6) & 7) ^ C7(K, (i - 7) & 7);
}
memcpy(K.q, L, 64);
for (i = 0; i < 8; i++) {
L[i] ^= C0(S, i) ^ C1(S, (i - 1) & 7) ^
C2(S, (i - 2) & 7) ^ C3(S, (i - 3) & 7) ^
C4(S, (i - 4) & 7) ^ C5(S, (i - 5) & 7) ^
C6(S, (i - 6) & 7) ^ C7(S, (i - 7) & 7);
}
memcpy(S.q, L, 64);
}
for (i = 0; i < 64; i++)
H->c[i] ^= S.c[i] ^ p[i];
#else
u64 L0, L1, L2, L3, L4, L5, L6, L7;
# ifdef STRICT_ALIGNMENT
if ((size_t)p & 7) {
memcpy(S.c, p, 64);
S.q[0] ^= (K.q[0] = H->q[0]);
S.q[1] ^= (K.q[1] = H->q[1]);
S.q[2] ^= (K.q[2] = H->q[2]);
S.q[3] ^= (K.q[3] = H->q[3]);
S.q[4] ^= (K.q[4] = H->q[4]);
S.q[5] ^= (K.q[5] = H->q[5]);
S.q[6] ^= (K.q[6] = H->q[6]);
S.q[7] ^= (K.q[7] = H->q[7]);
} else
# endif
{
const u64 *pa = (const u64 *)p;
S.q[0] = (K.q[0] = H->q[0]) ^ pa[0];
S.q[1] = (K.q[1] = H->q[1]) ^ pa[1];
S.q[2] = (K.q[2] = H->q[2]) ^ pa[2];
S.q[3] = (K.q[3] = H->q[3]) ^ pa[3];
S.q[4] = (K.q[4] = H->q[4]) ^ pa[4];
S.q[5] = (K.q[5] = H->q[5]) ^ pa[5];
S.q[6] = (K.q[6] = H->q[6]) ^ pa[6];
S.q[7] = (K.q[7] = H->q[7]) ^ pa[7];
}
for (r = 0; r < ROUNDS; r++) {
# ifdef SMALL_REGISTER_BANK
L0 = C0(K, 0) ^ C1(K, 7) ^ C2(K, 6) ^ C3(K, 5) ^
C4(K, 4) ^ C5(K, 3) ^ C6(K, 2) ^ C7(K, 1) ^ RC[r];
L1 = C0(K, 1) ^ C1(K, 0) ^ C2(K, 7) ^ C3(K, 6) ^
C4(K, 5) ^ C5(K, 4) ^ C6(K, 3) ^ C7(K, 2);
L2 = C0(K, 2) ^ C1(K, 1) ^ C2(K, 0) ^ C3(K, 7) ^
C4(K, 6) ^ C5(K, 5) ^ C6(K, 4) ^ C7(K, 3);
L3 = C0(K, 3) ^ C1(K, 2) ^ C2(K, 1) ^ C3(K, 0) ^
C4(K, 7) ^ C5(K, 6) ^ C6(K, 5) ^ C7(K, 4);
L4 = C0(K, 4) ^ C1(K, 3) ^ C2(K, 2) ^ C3(K, 1) ^
C4(K, 0) ^ C5(K, 7) ^ C6(K, 6) ^ C7(K, 5);
L5 = C0(K, 5) ^ C1(K, 4) ^ C2(K, 3) ^ C3(K, 2) ^
C4(K, 1) ^ C5(K, 0) ^ C6(K, 7) ^ C7(K, 6);
L6 = C0(K, 6) ^ C1(K, 5) ^ C2(K, 4) ^ C3(K, 3) ^
C4(K, 2) ^ C5(K, 1) ^ C6(K, 0) ^ C7(K, 7);
L7 = C0(K, 7) ^ C1(K, 6) ^ C2(K, 5) ^ C3(K, 4) ^
C4(K, 3) ^ C5(K, 2) ^ C6(K, 1) ^ C7(K, 0);
K.q[0] = L0;
K.q[1] = L1;
K.q[2] = L2;
K.q[3] = L3;
K.q[4] = L4;
K.q[5] = L5;
K.q[6] = L6;
K.q[7] = L7;
L0 ^= C0(S, 0) ^ C1(S, 7) ^ C2(S, 6) ^ C3(S, 5) ^
C4(S, 4) ^ C5(S, 3) ^ C6(S, 2) ^ C7(S, 1);
L1 ^= C0(S, 1) ^ C1(S, 0) ^ C2(S, 7) ^ C3(S, 6) ^
C4(S, 5) ^ C5(S, 4) ^ C6(S, 3) ^ C7(S, 2);
L2 ^= C0(S, 2) ^ C1(S, 1) ^ C2(S, 0) ^ C3(S, 7) ^
C4(S, 6) ^ C5(S, 5) ^ C6(S, 4) ^ C7(S, 3);
L3 ^= C0(S, 3) ^ C1(S, 2) ^ C2(S, 1) ^ C3(S, 0) ^
C4(S, 7) ^ C5(S, 6) ^ C6(S, 5) ^ C7(S, 4);
L4 ^= C0(S, 4) ^ C1(S, 3) ^ C2(S, 2) ^ C3(S, 1) ^
C4(S, 0) ^ C5(S, 7) ^ C6(S, 6) ^ C7(S, 5);
L5 ^= C0(S, 5) ^ C1(S, 4) ^ C2(S, 3) ^ C3(S, 2) ^
C4(S, 1) ^ C5(S, 0) ^ C6(S, 7) ^ C7(S, 6);
L6 ^= C0(S, 6) ^ C1(S, 5) ^ C2(S, 4) ^ C3(S, 3) ^
C4(S, 2) ^ C5(S, 1) ^ C6(S, 0) ^ C7(S, 7);
L7 ^= C0(S, 7) ^ C1(S, 6) ^ C2(S, 5) ^ C3(S, 4) ^
C4(S, 3) ^ C5(S, 2) ^ C6(S, 1) ^ C7(S, 0);
S.q[0] = L0;
S.q[1] = L1;
S.q[2] = L2;
S.q[3] = L3;
S.q[4] = L4;
S.q[5] = L5;
S.q[6] = L6;
S.q[7] = L7;
# else
L0 = C0(K, 0);
L1 = C1(K, 0);
L2 = C2(K, 0);
L3 = C3(K, 0);
L4 = C4(K, 0);
L5 = C5(K, 0);
L6 = C6(K, 0);
L7 = C7(K, 0);
L0 ^= RC[r];
L1 ^= C0(K, 1);
L2 ^= C1(K, 1);
L3 ^= C2(K, 1);
L4 ^= C3(K, 1);
L5 ^= C4(K, 1);
L6 ^= C5(K, 1);
L7 ^= C6(K, 1);
L0 ^= C7(K, 1);
L2 ^= C0(K, 2);
L3 ^= C1(K, 2);
L4 ^= C2(K, 2);
L5 ^= C3(K, 2);
L6 ^= C4(K, 2);
L7 ^= C5(K, 2);
L0 ^= C6(K, 2);
L1 ^= C7(K, 2);
L3 ^= C0(K, 3);
L4 ^= C1(K, 3);
L5 ^= C2(K, 3);
L6 ^= C3(K, 3);
L7 ^= C4(K, 3);
L0 ^= C5(K, 3);
L1 ^= C6(K, 3);
L2 ^= C7(K, 3);
L4 ^= C0(K, 4);
L5 ^= C1(K, 4);
L6 ^= C2(K, 4);
L7 ^= C3(K, 4);
L0 ^= C4(K, 4);
L1 ^= C5(K, 4);
L2 ^= C6(K, 4);
L3 ^= C7(K, 4);
L5 ^= C0(K, 5);
L6 ^= C1(K, 5);
L7 ^= C2(K, 5);
L0 ^= C3(K, 5);
L1 ^= C4(K, 5);
L2 ^= C5(K, 5);
L3 ^= C6(K, 5);
L4 ^= C7(K, 5);
L6 ^= C0(K, 6);
L7 ^= C1(K, 6);
L0 ^= C2(K, 6);
L1 ^= C3(K, 6);
L2 ^= C4(K, 6);
L3 ^= C5(K, 6);
L4 ^= C6(K, 6);
L5 ^= C7(K, 6);
L7 ^= C0(K, 7);
L0 ^= C1(K, 7);
L1 ^= C2(K, 7);
L2 ^= C3(K, 7);
L3 ^= C4(K, 7);
L4 ^= C5(K, 7);
L5 ^= C6(K, 7);
L6 ^= C7(K, 7);
K.q[0] = L0;
K.q[1] = L1;
K.q[2] = L2;
K.q[3] = L3;
K.q[4] = L4;
K.q[5] = L5;
K.q[6] = L6;
K.q[7] = L7;
L0 ^= C0(S, 0);
L1 ^= C1(S, 0);
L2 ^= C2(S, 0);
L3 ^= C3(S, 0);
L4 ^= C4(S, 0);
L5 ^= C5(S, 0);
L6 ^= C6(S, 0);
L7 ^= C7(S, 0);
L1 ^= C0(S, 1);
L2 ^= C1(S, 1);
L3 ^= C2(S, 1);
L4 ^= C3(S, 1);
L5 ^= C4(S, 1);
L6 ^= C5(S, 1);
L7 ^= C6(S, 1);
L0 ^= C7(S, 1);
L2 ^= C0(S, 2);
L3 ^= C1(S, 2);
L4 ^= C2(S, 2);
L5 ^= C3(S, 2);
L6 ^= C4(S, 2);
L7 ^= C5(S, 2);
L0 ^= C6(S, 2);
L1 ^= C7(S, 2);
L3 ^= C0(S, 3);
L4 ^= C1(S, 3);
L5 ^= C2(S, 3);
L6 ^= C3(S, 3);
L7 ^= C4(S, 3);
L0 ^= C5(S, 3);
L1 ^= C6(S, 3);
L2 ^= C7(S, 3);
L4 ^= C0(S, 4);
L5 ^= C1(S, 4);
L6 ^= C2(S, 4);
L7 ^= C3(S, 4);
L0 ^= C4(S, 4);
L1 ^= C5(S, 4);
L2 ^= C6(S, 4);
L3 ^= C7(S, 4);
L5 ^= C0(S, 5);
L6 ^= C1(S, 5);
L7 ^= C2(S, 5);
L0 ^= C3(S, 5);
L1 ^= C4(S, 5);
L2 ^= C5(S, 5);
L3 ^= C6(S, 5);
L4 ^= C7(S, 5);
L6 ^= C0(S, 6);
L7 ^= C1(S, 6);
L0 ^= C2(S, 6);
L1 ^= C3(S, 6);
L2 ^= C4(S, 6);
L3 ^= C5(S, 6);
L4 ^= C6(S, 6);
L5 ^= C7(S, 6);
L7 ^= C0(S, 7);
L0 ^= C1(S, 7);
L1 ^= C2(S, 7);
L2 ^= C3(S, 7);
L3 ^= C4(S, 7);
L4 ^= C5(S, 7);
L5 ^= C6(S, 7);
L6 ^= C7(S, 7);
S.q[0] = L0;
S.q[1] = L1;
S.q[2] = L2;
S.q[3] = L3;
S.q[4] = L4;
S.q[5] = L5;
S.q[6] = L6;
S.q[7] = L7;
# endif
}
# ifdef STRICT_ALIGNMENT
if ((size_t)p & 7) {
int i;
for (i = 0; i < 64; i++)
H->c[i] ^= S.c[i] ^ p[i];
} else
# endif
{
const u64 *pa = (const u64 *)p;
H->q[0] ^= S.q[0] ^ pa[0];
H->q[1] ^= S.q[1] ^ pa[1];
H->q[2] ^= S.q[2] ^ pa[2];
H->q[3] ^= S.q[3] ^ pa[3];
H->q[4] ^= S.q[4] ^ pa[4];
H->q[5] ^= S.q[5] ^ pa[5];
H->q[6] ^= S.q[6] ^ pa[6];
H->q[7] ^= S.q[7] ^ pa[7];
}
#endif
p += 64;
} while (--n);
}
