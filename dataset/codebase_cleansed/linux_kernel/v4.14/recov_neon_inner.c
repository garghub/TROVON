static uint8x16_t vqtbl1q_u8(uint8x16_t a, uint8x16_t b)
{
union {
uint8x16_t val;
uint8x8x2_t pair;
} __a = { a };
return vcombine_u8(vtbl2_u8(__a.pair, vget_low_u8(b)),
vtbl2_u8(__a.pair, vget_high_u8(b)));
}
void __raid6_2data_recov_neon(int bytes, uint8_t *p, uint8_t *q, uint8_t *dp,
uint8_t *dq, const uint8_t *pbmul,
const uint8_t *qmul)
{
uint8x16_t pm0 = vld1q_u8(pbmul);
uint8x16_t pm1 = vld1q_u8(pbmul + 16);
uint8x16_t qm0 = vld1q_u8(qmul);
uint8x16_t qm1 = vld1q_u8(qmul + 16);
while (bytes) {
uint8x16_t vx, vy, px, qx, db;
px = veorq_u8(vld1q_u8(p), vld1q_u8(dp));
vx = veorq_u8(vld1q_u8(q), vld1q_u8(dq));
vy = (uint8x16_t)vshrq_n_s16((int16x8_t)vx, 4);
vx = vqtbl1q_u8(qm0, vandq_u8(vx, x0f));
vy = vqtbl1q_u8(qm1, vandq_u8(vy, x0f));
qx = veorq_u8(vx, vy);
vy = (uint8x16_t)vshrq_n_s16((int16x8_t)px, 4);
vx = vqtbl1q_u8(pm0, vandq_u8(px, x0f));
vy = vqtbl1q_u8(pm1, vandq_u8(vy, x0f));
vx = veorq_u8(vx, vy);
db = veorq_u8(vx, qx);
vst1q_u8(dq, db);
vst1q_u8(dp, veorq_u8(db, px));
bytes -= 16;
p += 16;
q += 16;
dp += 16;
dq += 16;
}
}
void __raid6_datap_recov_neon(int bytes, uint8_t *p, uint8_t *q, uint8_t *dq,
const uint8_t *qmul)
{
uint8x16_t qm0 = vld1q_u8(qmul);
uint8x16_t qm1 = vld1q_u8(qmul + 16);
while (bytes) {
uint8x16_t vx, vy;
vx = veorq_u8(vld1q_u8(q), vld1q_u8(dq));
vy = (uint8x16_t)vshrq_n_s16((int16x8_t)vx, 4);
vx = vqtbl1q_u8(qm0, vandq_u8(vx, x0f));
vy = vqtbl1q_u8(qm1, vandq_u8(vy, x0f));
vx = veorq_u8(vx, vy);
vy = veorq_u8(vx, vld1q_u8(p));
vst1q_u8(dq, vx);
vst1q_u8(p, vy);
bytes -= 16;
p += 16;
q += 16;
dq += 16;
}
}
