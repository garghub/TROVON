u32 prandom32(struct rnd_state *state)
{
#define TAUSWORTHE(s,a,b,c,d) ((s&c)<<d) ^ (((s <<a) ^ s)>>b)
state->s1 = TAUSWORTHE(state->s1, 13, 19, 4294967294UL, 12);
state->s2 = TAUSWORTHE(state->s2, 2, 25, 4294967288UL, 4);
state->s3 = TAUSWORTHE(state->s3, 3, 11, 4294967280UL, 17);
return (state->s1 ^ state->s2 ^ state->s3);
}
u32 random32(void)
{
unsigned long r;
struct rnd_state *state = &get_cpu_var(net_rand_state);
r = prandom32(state);
put_cpu_var(state);
return r;
}
void srandom32(u32 entropy)
{
int i;
for_each_possible_cpu (i) {
struct rnd_state *state = &per_cpu(net_rand_state, i);
state->s1 = __seed(state->s1 ^ entropy, 1);
}
}
static int __init random32_init(void)
{
int i;
for_each_possible_cpu(i) {
struct rnd_state *state = &per_cpu(net_rand_state,i);
#define LCG(x) ((x) * 69069)
state->s1 = __seed(LCG(i + jiffies), 1);
state->s2 = __seed(LCG(state->s1), 7);
state->s3 = __seed(LCG(state->s2), 15);
prandom32(state);
prandom32(state);
prandom32(state);
prandom32(state);
prandom32(state);
prandom32(state);
}
return 0;
}
static int __init random32_reseed(void)
{
int i;
for_each_possible_cpu(i) {
struct rnd_state *state = &per_cpu(net_rand_state,i);
u32 seeds[3];
get_random_bytes(&seeds, sizeof(seeds));
state->s1 = __seed(seeds[0], 1);
state->s2 = __seed(seeds[1], 7);
state->s3 = __seed(seeds[2], 15);
prandom32(state);
}
return 0;
}
