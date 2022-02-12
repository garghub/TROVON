static inline u32 tfrc_binsearch(u32 fval, u8 small)
{
u32 try, low = 0, high = TFRC_CALC_X_ARRSIZE - 1;
while (low < high) {
try = (low + high) / 2;
if (fval <= tfrc_calc_x_lookup[try][small])
high = try;
else
low = try + 1;
}
return high;
}
u32 tfrc_calc_x(u16 s, u32 R, u32 p)
{
u16 index;
u32 f;
u64 result;
BUG_ON(p > 1000000);
BUG_ON(p == 0);
if (R == 0) {
DCCP_CRIT("WARNING: RTT is 0, returning maximum X_calc.");
return ~0U;
}
if (p <= TFRC_CALC_X_SPLIT) {
if (p < TFRC_SMALLEST_P) {
DCCP_WARN("Value of p (%d) below resolution. "
"Substituting %d\n", p, TFRC_SMALLEST_P);
index = 0;
} else
index = p/TFRC_SMALLEST_P - 1;
f = tfrc_calc_x_lookup[index][1];
} else {
index = p/(1000000/TFRC_CALC_X_ARRSIZE) - 1;
f = tfrc_calc_x_lookup[index][0];
}
result = scaled_div(s, R);
return scaled_div32(result, f);
}
u32 tfrc_calc_x_reverse_lookup(u32 fvalue)
{
int index;
if (fvalue == 0)
return 0;
if (fvalue < tfrc_calc_x_lookup[0][1]) {
DCCP_WARN("fvalue %u smaller than resolution\n", fvalue);
return TFRC_SMALLEST_P;
}
if (fvalue > tfrc_calc_x_lookup[TFRC_CALC_X_ARRSIZE - 1][0]) {
DCCP_WARN("fvalue %u exceeds bounds!\n", fvalue);
return 1000000;
}
if (fvalue <= tfrc_calc_x_lookup[TFRC_CALC_X_ARRSIZE - 1][1]) {
index = tfrc_binsearch(fvalue, 1);
return (index + 1) * TFRC_CALC_X_SPLIT / TFRC_CALC_X_ARRSIZE;
}
index = tfrc_binsearch(fvalue, 0);
return (index + 1) * 1000000 / TFRC_CALC_X_ARRSIZE;
}
u32 tfrc_invert_loss_event_rate(u32 loss_event_rate)
{
if (loss_event_rate == UINT_MAX)
return 0;
if (unlikely(loss_event_rate == 0))
return 1000000;
return max_t(u32, scaled_div(1, loss_event_rate), TFRC_SMALLEST_P);
}
