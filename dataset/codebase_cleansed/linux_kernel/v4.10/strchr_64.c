char *strchr(const char *s, int c)
{
int z, g;
const uintptr_t s_int = (uintptr_t) s;
const uint64_t *p = (const uint64_t *)(s_int & -8);
const uint64_t goal = copy_byte(c);
const uint64_t before_mask = MASK(s_int);
uint64_t v = (*p | before_mask) ^ (goal & __insn_v1shrui(before_mask, 1));
uint64_t zero_matches, goal_matches;
while (1) {
zero_matches = __insn_v1cmpeqi(v, 0);
goal_matches = __insn_v1cmpeq(v, goal);
if (__builtin_expect((zero_matches | goal_matches) != 0, 0))
break;
v = *++p;
}
z = CFZ(zero_matches);
g = CFZ(goal_matches);
return (g <= z) ? ((char *)p) + (g >> 3) : NULL;
}
