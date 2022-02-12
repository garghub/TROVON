static inline void prandom_state_selftest(void)
{
}
u32 prandom_u32_state(struct rnd_state *state)
{
#define TAUSWORTHE(s, a, b, c, d) ((s & c) << d) ^ (((s << a) ^ s) >> b)
state->s1 = TAUSWORTHE(state->s1, 6U, 13U, 4294967294U, 18U);
state->s2 = TAUSWORTHE(state->s2, 2U, 27U, 4294967288U, 2U);
state->s3 = TAUSWORTHE(state->s3, 13U, 21U, 4294967280U, 7U);
state->s4 = TAUSWORTHE(state->s4, 3U, 12U, 4294967168U, 13U);
return (state->s1 ^ state->s2 ^ state->s3 ^ state->s4);
}
u32 prandom_u32(void)
{
struct rnd_state *state = &get_cpu_var(net_rand_state);
u32 res;
res = prandom_u32_state(state);
put_cpu_var(state);
return res;
}
void prandom_bytes_state(struct rnd_state *state, void *buf, size_t bytes)
{
u8 *ptr = buf;
while (bytes >= sizeof(u32)) {
put_unaligned(prandom_u32_state(state), (u32 *) ptr);
ptr += sizeof(u32);
bytes -= sizeof(u32);
}
if (bytes > 0) {
u32 rem = prandom_u32_state(state);
do {
*ptr++ = (u8) rem;
bytes--;
rem >>= BITS_PER_BYTE;
} while (bytes > 0);
}
}
void prandom_bytes(void *buf, size_t bytes)
{
struct rnd_state *state = &get_cpu_var(net_rand_state);
prandom_bytes_state(state, buf, bytes);
put_cpu_var(state);
}
static void prandom_warmup(struct rnd_state *state)
{
prandom_u32_state(state);
prandom_u32_state(state);
prandom_u32_state(state);
prandom_u32_state(state);
prandom_u32_state(state);
prandom_u32_state(state);
prandom_u32_state(state);
prandom_u32_state(state);
prandom_u32_state(state);
prandom_u32_state(state);
}
static u32 __extract_hwseed(void)
{
unsigned int val = 0;
(void)(arch_get_random_seed_int(&val) ||
arch_get_random_int(&val));
return val;
}
static void prandom_seed_early(struct rnd_state *state, u32 seed,
bool mix_with_hwseed)
{
#define LCG(x) ((x) * 69069U)
#define HWSEED() (mix_with_hwseed ? __extract_hwseed() : 0)
state->s1 = __seed(HWSEED() ^ LCG(seed), 2U);
state->s2 = __seed(HWSEED() ^ LCG(state->s1), 8U);
state->s3 = __seed(HWSEED() ^ LCG(state->s2), 16U);
state->s4 = __seed(HWSEED() ^ LCG(state->s3), 128U);
}
void prandom_seed(u32 entropy)
{
int i;
for_each_possible_cpu (i) {
struct rnd_state *state = &per_cpu(net_rand_state, i);
state->s1 = __seed(state->s1 ^ entropy, 2U);
prandom_warmup(state);
}
}
static int __init prandom_init(void)
{
int i;
prandom_state_selftest();
for_each_possible_cpu(i) {
struct rnd_state *state = &per_cpu(net_rand_state,i);
u32 weak_seed = (i + jiffies) ^ random_get_entropy();
prandom_seed_early(state, weak_seed, true);
prandom_warmup(state);
}
return 0;
}
static void __prandom_timer(unsigned long dontcare)
{
u32 entropy;
unsigned long expires;
get_random_bytes(&entropy, sizeof(entropy));
prandom_seed(entropy);
expires = 40 + prandom_u32_max(40);
seed_timer.expires = jiffies + msecs_to_jiffies(expires * MSEC_PER_SEC);
add_timer(&seed_timer);
}
static void __init __prandom_start_seed_timer(void)
{
set_timer_slack(&seed_timer, HZ);
seed_timer.expires = jiffies + msecs_to_jiffies(40 * MSEC_PER_SEC);
add_timer(&seed_timer);
}
static void __prandom_reseed(bool late)
{
int i;
unsigned long flags;
static bool latch = false;
static DEFINE_SPINLOCK(lock);
if (!spin_trylock_irqsave(&lock, flags))
return;
if (latch && !late)
goto out;
latch = true;
for_each_possible_cpu(i) {
struct rnd_state *state = &per_cpu(net_rand_state,i);
u32 seeds[4];
get_random_bytes(&seeds, sizeof(seeds));
state->s1 = __seed(seeds[0], 2U);
state->s2 = __seed(seeds[1], 8U);
state->s3 = __seed(seeds[2], 16U);
state->s4 = __seed(seeds[3], 128U);
prandom_warmup(state);
}
out:
spin_unlock_irqrestore(&lock, flags);
}
void prandom_reseed_late(void)
{
__prandom_reseed(true);
}
static int __init prandom_reseed(void)
{
__prandom_reseed(false);
__prandom_start_seed_timer();
return 0;
}
static void __init prandom_state_selftest(void)
{
int i, j, errors = 0, runs = 0;
bool error = false;
for (i = 0; i < ARRAY_SIZE(test1); i++) {
struct rnd_state state;
prandom_seed_early(&state, test1[i].seed, false);
prandom_warmup(&state);
if (test1[i].result != prandom_u32_state(&state))
error = true;
}
if (error)
pr_warn("prandom: seed boundary self test failed\n");
else
pr_info("prandom: seed boundary self test passed\n");
for (i = 0; i < ARRAY_SIZE(test2); i++) {
struct rnd_state state;
prandom_seed_early(&state, test2[i].seed, false);
prandom_warmup(&state);
for (j = 0; j < test2[i].iteration - 1; j++)
prandom_u32_state(&state);
if (test2[i].result != prandom_u32_state(&state))
errors++;
runs++;
cond_resched();
}
if (errors)
pr_warn("prandom: %d/%d self tests failed\n", errors, runs);
else
pr_info("prandom: %d self tests passed\n", runs);
}
