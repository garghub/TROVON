static __u64 jent_loop_shuffle(struct rand_data *ec,
unsigned int bits, unsigned int min)
{
__u64 time = 0;
__u64 shuffle = 0;
unsigned int i = 0;
unsigned int mask = (1<<bits) - 1;
jent_get_nstime(&time);
if (ec)
time ^= ec->data;
for (i = 0; (DATA_SIZE_BITS / bits) > i; i++) {
shuffle ^= time & mask;
time = time >> bits;
}
return (shuffle + (1<<min));
}
static __u64 jent_fold_time(struct rand_data *ec, __u64 time,
__u64 *folded, __u64 loop_cnt)
{
unsigned int i;
__u64 j = 0;
__u64 new = 0;
#define MAX_FOLD_LOOP_BIT 4
#define MIN_FOLD_LOOP_BIT 0
__u64 fold_loop_cnt =
jent_loop_shuffle(ec, MAX_FOLD_LOOP_BIT, MIN_FOLD_LOOP_BIT);
if (loop_cnt)
fold_loop_cnt = loop_cnt;
for (j = 0; j < fold_loop_cnt; j++) {
new = 0;
for (i = 1; (DATA_SIZE_BITS) >= i; i++) {
__u64 tmp = time << (DATA_SIZE_BITS - i);
tmp = tmp >> (DATA_SIZE_BITS - 1);
new ^= tmp;
}
}
*folded = new;
return fold_loop_cnt;
}
static unsigned int jent_memaccess(struct rand_data *ec, __u64 loop_cnt)
{
unsigned char *tmpval = NULL;
unsigned int wrap = 0;
__u64 i = 0;
#define MAX_ACC_LOOP_BIT 7
#define MIN_ACC_LOOP_BIT 0
__u64 acc_loop_cnt =
jent_loop_shuffle(ec, MAX_ACC_LOOP_BIT, MIN_ACC_LOOP_BIT);
if (NULL == ec || NULL == ec->mem)
return 0;
wrap = ec->memblocksize * ec->memblocks;
if (loop_cnt)
acc_loop_cnt = loop_cnt;
for (i = 0; i < (ec->memaccessloops + acc_loop_cnt); i++) {
tmpval = ec->mem + ec->memlocation;
*tmpval = (*tmpval + 1) & 0xff;
ec->memlocation = ec->memlocation + ec->memblocksize - 1;
ec->memlocation = ec->memlocation % wrap;
}
return i;
}
static void jent_stuck(struct rand_data *ec, __u64 current_delta)
{
__s64 delta2 = ec->last_delta - current_delta;
__s64 delta3 = delta2 - ec->last_delta2;
ec->last_delta = current_delta;
ec->last_delta2 = delta2;
if (!current_delta || !delta2 || !delta3)
ec->stuck = 1;
}
static __u64 jent_measure_jitter(struct rand_data *ec)
{
__u64 time = 0;
__u64 data = 0;
__u64 current_delta = 0;
jent_memaccess(ec, 0);
jent_get_nstime(&time);
current_delta = time - ec->prev_time;
ec->prev_time = time;
jent_fold_time(ec, current_delta, &data, 0);
jent_stuck(ec, current_delta);
return data;
}
static __u64 jent_unbiased_bit(struct rand_data *entropy_collector)
{
do {
__u64 a = jent_measure_jitter(entropy_collector);
__u64 b = jent_measure_jitter(entropy_collector);
if (a == b)
continue;
if (1 == a)
return 1;
else
return 0;
} while (1);
}
static void jent_stir_pool(struct rand_data *entropy_collector)
{
union c {
__u64 u64;
__u32 u32[2];
};
union c constant;
union c mixer;
unsigned int i = 0;
constant.u32[1] = 0x67452301;
constant.u32[0] = 0xefcdab89;
mixer.u32[1] = 0x98badcfe;
mixer.u32[0] = 0x10325476;
for (i = 0; i < DATA_SIZE_BITS; i++) {
if ((entropy_collector->data >> i) & 1)
mixer.u64 ^= constant.u64;
mixer.u64 = jent_rol64(mixer.u64, 1);
}
entropy_collector->data ^= mixer.u64;
}
static void jent_gen_entropy(struct rand_data *ec)
{
unsigned int k = 0;
jent_measure_jitter(ec);
while (1) {
__u64 data = 0;
if (ec->disable_unbias == 1)
data = jent_measure_jitter(ec);
else
data = jent_unbiased_bit(ec);
if (ec->stuck) {
ec->data ^= data;
ec->stuck = 0;
continue;
}
ec->data ^= data;
ec->data ^= ((ec->data >> 63) & 1);
ec->data ^= ((ec->data >> 60) & 1);
ec->data ^= ((ec->data >> 55) & 1);
ec->data ^= ((ec->data >> 30) & 1);
ec->data ^= ((ec->data >> 27) & 1);
ec->data ^= ((ec->data >> 22) & 1);
ec->data = jent_rol64(ec->data, 1);
if (++k >= (DATA_SIZE_BITS * ec->osr))
break;
}
if (ec->stir)
jent_stir_pool(ec);
}
static void jent_fips_test(struct rand_data *ec)
{
if (!jent_fips_enabled())
return;
if (!ec->old_data) {
ec->old_data = ec->data;
jent_gen_entropy(ec);
}
if (ec->data == ec->old_data)
jent_panic("jitterentropy: Duplicate output detected\n");
ec->old_data = ec->data;
}
int jent_read_entropy(struct rand_data *ec, unsigned char *data,
unsigned int len)
{
unsigned char *p = data;
if (!ec)
return -1;
while (0 < len) {
unsigned int tocopy;
jent_gen_entropy(ec);
jent_fips_test(ec);
if ((DATA_SIZE_BITS / 8) < len)
tocopy = (DATA_SIZE_BITS / 8);
else
tocopy = len;
jent_memcpy(p, &ec->data, tocopy);
len -= tocopy;
p += tocopy;
}
return 0;
}
struct rand_data *jent_entropy_collector_alloc(unsigned int osr,
unsigned int flags)
{
struct rand_data *entropy_collector;
entropy_collector = jent_zalloc(sizeof(struct rand_data));
if (!entropy_collector)
return NULL;
if (!(flags & JENT_DISABLE_MEMORY_ACCESS)) {
entropy_collector->mem = jent_zalloc(JENT_MEMORY_SIZE);
if (!entropy_collector->mem) {
jent_zfree(entropy_collector);
return NULL;
}
entropy_collector->memblocksize = JENT_MEMORY_BLOCKSIZE;
entropy_collector->memblocks = JENT_MEMORY_BLOCKS;
entropy_collector->memaccessloops = JENT_MEMORY_ACCESSLOOPS;
}
if (0 == osr)
osr = 1;
entropy_collector->osr = osr;
entropy_collector->stir = 1;
if (flags & JENT_DISABLE_STIR)
entropy_collector->stir = 0;
if (flags & JENT_DISABLE_UNBIAS)
entropy_collector->disable_unbias = 1;
jent_gen_entropy(entropy_collector);
return entropy_collector;
}
void jent_entropy_collector_free(struct rand_data *entropy_collector)
{
jent_zfree(entropy_collector->mem);
entropy_collector->mem = NULL;
jent_zfree(entropy_collector);
entropy_collector = NULL;
}
int jent_entropy_init(void)
{
int i;
__u64 delta_sum = 0;
__u64 old_delta = 0;
int time_backwards = 0;
int count_var = 0;
int count_mod = 0;
#define TESTLOOPCOUNT 300
#define CLEARCACHE 100
for (i = 0; (TESTLOOPCOUNT + CLEARCACHE) > i; i++) {
__u64 time = 0;
__u64 time2 = 0;
__u64 folded = 0;
__u64 delta = 0;
unsigned int lowdelta = 0;
jent_get_nstime(&time);
jent_fold_time(NULL, time, &folded, 1<<MIN_FOLD_LOOP_BIT);
jent_get_nstime(&time2);
if (!time || !time2)
return JENT_ENOTIME;
delta = time2 - time;
if (!delta)
return JENT_ECOARSETIME;
if (CLEARCACHE > i)
continue;
if (!(time2 > time))
time_backwards++;
lowdelta = time2 - time;
if (!(lowdelta % 100))
count_mod++;
if (i) {
if (delta != old_delta)
count_var++;
if (delta > old_delta)
delta_sum += (delta - old_delta);
else
delta_sum += (old_delta - delta);
}
old_delta = delta;
}
if (3 < time_backwards)
return JENT_ENOMONOTONIC;
if (!delta_sum)
return JENT_EVARVAR;
if (delta_sum <= 1)
return JENT_EMINVARVAR;
if ((TESTLOOPCOUNT/10 * 9) < count_mod)
return JENT_ECOARSETIME;
return 0;
}
