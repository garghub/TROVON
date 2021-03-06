char *strchr(const char *s, int c)
{
int z, g;
const uintptr_t s_int = (uintptr_t) s;
const uint32_t *p = (const uint32_t *)(s_int & -4);
const uint32_t goal = 0x01010101 * (uint8_t) c;
const uint32_t before_mask = (1 << (s_int << 3)) - 1;
uint32_t v = (*p | before_mask) ^ (goal & __insn_shrib(before_mask, 1));
uint32_t zero_matches, goal_matches;
while (1) {
zero_matches = __insn_seqb(v, 0);
goal_matches = __insn_seqb(v, goal);
if (__builtin_expect(zero_matches | goal_matches, 0))
break;
v = *++p;
}
z = __insn_ctz(zero_matches);
g = __insn_ctz(goal_matches);
return (g <= z) ? ((char *)p) + (g >> 3) : NULL;
}
