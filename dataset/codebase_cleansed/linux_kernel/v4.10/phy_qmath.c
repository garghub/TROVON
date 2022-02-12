u16 qm_mulu16(u16 op1, u16 op2)
{
return (u16) (((u32) op1 * (u32) op2) >> 16);
}
s16 qm_muls16(s16 op1, s16 op2)
{
s32 result;
if (op1 == (s16) 0x8000 && op2 == (s16) 0x8000)
result = 0x7fffffff;
else
result = ((s32) (op1) * (s32) (op2));
return (s16) (result >> 15);
}
s32 qm_add32(s32 op1, s32 op2)
{
s32 result;
result = op1 + op2;
if (op1 < 0 && op2 < 0 && result > 0)
result = 0x80000000;
else if (op1 > 0 && op2 > 0 && result < 0)
result = 0x7fffffff;
return result;
}
s16 qm_add16(s16 op1, s16 op2)
{
s16 result;
s32 temp = (s32) op1 + (s32) op2;
if (temp > (s32) 0x7fff)
result = (s16) 0x7fff;
else if (temp < (s32) 0xffff8000)
result = (s16) 0xffff8000;
else
result = (s16) temp;
return result;
}
s16 qm_sub16(s16 op1, s16 op2)
{
s16 result;
s32 temp = (s32) op1 - (s32) op2;
if (temp > (s32) 0x7fff)
result = (s16) 0x7fff;
else if (temp < (s32) 0xffff8000)
result = (s16) 0xffff8000;
else
result = (s16) temp;
return result;
}
s32 qm_shl32(s32 op, int shift)
{
int i;
s32 result;
result = op;
if (shift > 31)
shift = 31;
else if (shift < -31)
shift = -31;
if (shift >= 0) {
for (i = 0; i < shift; i++)
result = qm_add32(result, result);
} else {
result = result >> (-shift);
}
return result;
}
s16 qm_shl16(s16 op, int shift)
{
int i;
s16 result;
result = op;
if (shift > 15)
shift = 15;
else if (shift < -15)
shift = -15;
if (shift > 0) {
for (i = 0; i < shift; i++)
result = qm_add16(result, result);
} else {
result = result >> (-shift);
}
return result;
}
s16 qm_shr16(s16 op, int shift)
{
return qm_shl16(op, -shift);
}
s16 qm_norm32(s32 op)
{
u16 u16extraSignBits;
if (op == 0) {
return 31;
} else {
u16extraSignBits = 0;
while ((op >> 31) == (op >> 30)) {
u16extraSignBits++;
op = op << 1;
}
}
return u16extraSignBits;
}
void qm_log10(s32 N, s16 qN, s16 *log10N, s16 *qLog10N)
{
s16 s16norm, s16tableIndex, s16errorApproximation;
u16 u16offset;
s32 s32log;
s16norm = qm_norm32(N);
N = N << s16norm;
qN = qN + s16norm - 30;
s16tableIndex = (s16) (N >> (32 - (2 + LOG2_LOG_TABLE_SIZE)));
s16tableIndex =
s16tableIndex & (s16) ((1 << LOG2_LOG_TABLE_SIZE) - 1);
N = N & ((1 << (32 - (2 + LOG2_LOG_TABLE_SIZE))) - 1);
u16offset = (u16) (N >> (32 - (2 + LOG2_LOG_TABLE_SIZE + 16)));
s32log = log_table[s16tableIndex];
s16errorApproximation = (s16) qm_mulu16(u16offset,
(u16) (log_table[s16tableIndex + 1] -
log_table[s16tableIndex]));
s32log = qm_add16((s16) s32log, s16errorApproximation);
s32log = qm_add32(s32log, ((s32) -qN) << 15);
s16norm = qm_norm32(s32log);
s32log = qm_shl32(s32log, s16norm - 16);
*log10N = qm_muls16((s16) s32log, (s16) LOG10_2);
*qLog10N = 15 + s16norm - 16 + 1;
return;
}
