RAND_METHOD *RAND_OpenSSL(void)
{
return (&rand_meth);
}
static void rand_cleanup(void)
{
OPENSSL_cleanse(state, sizeof(state));
state_num = 0;
state_index = 0;
OPENSSL_cleanse(md, MD_DIGEST_LENGTH);
md_count[0] = 0;
md_count[1] = 0;
entropy = 0;
initialized = 0;
CRYPTO_THREAD_lock_free(rand_lock);
CRYPTO_THREAD_lock_free(rand_tmp_lock);
}
static int rand_add(const void *buf, int num, double add)
{
int i, j, k, st_idx;
long md_c[2];
unsigned char local_md[MD_DIGEST_LENGTH];
EVP_MD_CTX *m;
int do_not_lock;
int rv = 0;
if (!num)
return 1;
m = EVP_MD_CTX_new();
if (m == NULL)
goto err;
if (!RUN_ONCE(&rand_lock_init, do_rand_lock_init))
goto err;
if (crypto_lock_rand) {
CRYPTO_THREAD_ID cur = CRYPTO_THREAD_get_current_id();
CRYPTO_THREAD_read_lock(rand_tmp_lock);
do_not_lock = CRYPTO_THREAD_compare_id(locking_threadid, cur);
CRYPTO_THREAD_unlock(rand_tmp_lock);
} else
do_not_lock = 0;
if (!do_not_lock)
CRYPTO_THREAD_write_lock(rand_lock);
st_idx = state_index;
md_c[0] = md_count[0];
md_c[1] = md_count[1];
memcpy(local_md, md, sizeof md);
state_index += num;
if (state_index >= STATE_SIZE) {
state_index %= STATE_SIZE;
state_num = STATE_SIZE;
} else if (state_num < STATE_SIZE) {
if (state_index > state_num)
state_num = state_index;
}
md_count[1] += (num / MD_DIGEST_LENGTH) + (num % MD_DIGEST_LENGTH > 0);
if (!do_not_lock)
CRYPTO_THREAD_unlock(rand_lock);
for (i = 0; i < num; i += MD_DIGEST_LENGTH) {
j = (num - i);
j = (j > MD_DIGEST_LENGTH) ? MD_DIGEST_LENGTH : j;
if (!MD_Init(m))
goto err;
if (!MD_Update(m, local_md, MD_DIGEST_LENGTH))
goto err;
k = (st_idx + j) - STATE_SIZE;
if (k > 0) {
if (!MD_Update(m, &(state[st_idx]), j - k))
goto err;
if (!MD_Update(m, &(state[0]), k))
goto err;
} else if (!MD_Update(m, &(state[st_idx]), j))
goto err;
if (!MD_Update(m, buf, j))
goto err;
if (!MD_Update(m, (unsigned char *)&(md_c[0]), sizeof(md_c)))
goto err;
if (!MD_Final(m, local_md))
goto err;
md_c[1]++;
buf = (const char *)buf + j;
for (k = 0; k < j; k++) {
state[st_idx++] ^= local_md[k];
if (st_idx >= STATE_SIZE)
st_idx = 0;
}
}
if (!do_not_lock)
CRYPTO_THREAD_write_lock(rand_lock);
for (k = 0; k < (int)sizeof(md); k++) {
md[k] ^= local_md[k];
}
if (entropy < ENTROPY_NEEDED)
entropy += add;
if (!do_not_lock)
CRYPTO_THREAD_unlock(rand_lock);
rv = 1;
err:
EVP_MD_CTX_free(m);
return rv;
}
static int rand_seed(const void *buf, int num)
{
return rand_add(buf, num, (double)num);
}
static int rand_bytes(unsigned char *buf, int num, int pseudo)
{
static volatile int stirred_pool = 0;
int i, j, k;
size_t num_ceil, st_idx, st_num;
int ok;
long md_c[2];
unsigned char local_md[MD_DIGEST_LENGTH];
EVP_MD_CTX *m;
#ifndef GETPID_IS_MEANINGLESS
pid_t curr_pid = getpid();
#endif
time_t curr_time = time(NULL);
int do_stir_pool = 0;
#ifdef OPENSSL_SYS_WIN32
FILETIME tv;
# ifdef _WIN32_WCE
SYSTEMTIME t;
GetSystemTime(&t);
SystemTimeToFileTime(&t, &tv);
# else
GetSystemTimeAsFileTime(&tv);
# endif
#elif defined(OPENSSL_SYS_VXWORKS)
struct timespec tv;
clock_gettime(CLOCK_REALTIME, &ts);
#elif defined(OPENSSL_SYS_DSPBIOS)
unsigned long long tv, OPENSSL_rdtsc();
tv = OPENSSL_rdtsc();
#else
struct timeval tv;
gettimeofday(&tv, NULL);
#endif
#ifdef PREDICT
if (rand_predictable) {
static unsigned char val = 0;
for (i = 0; i < num; i++)
buf[i] = val++;
return (1);
}
#endif
if (num <= 0)
return 1;
m = EVP_MD_CTX_new();
if (m == NULL)
goto err_mem;
num_ceil =
(1 + (num - 1) / (MD_DIGEST_LENGTH / 2)) * (MD_DIGEST_LENGTH / 2);
if (!RUN_ONCE(&rand_lock_init, do_rand_lock_init))
goto err_mem;
CRYPTO_THREAD_write_lock(rand_lock);
ASYNC_block_pause();
CRYPTO_THREAD_write_lock(rand_tmp_lock);
locking_threadid = CRYPTO_THREAD_get_current_id();
CRYPTO_THREAD_unlock(rand_tmp_lock);
crypto_lock_rand = 1;
if (!initialized) {
RAND_poll();
initialized = 1;
}
if (!stirred_pool)
do_stir_pool = 1;
ok = (entropy >= ENTROPY_NEEDED);
if (!ok) {
entropy -= num;
if (entropy < 0)
entropy = 0;
}
if (do_stir_pool) {
int n = STATE_SIZE;
while (n > 0) {
#if MD_DIGEST_LENGTH > 20
# error "Please adjust DUMMY_SEED."
#endif
#define DUMMY_SEED "...................."
rand_add(DUMMY_SEED, MD_DIGEST_LENGTH, 0.0);
n -= MD_DIGEST_LENGTH;
}
if (ok)
stirred_pool = 1;
}
st_idx = state_index;
st_num = state_num;
md_c[0] = md_count[0];
md_c[1] = md_count[1];
memcpy(local_md, md, sizeof md);
state_index += num_ceil;
if (state_index > state_num)
state_index %= state_num;
md_count[0] += 1;
crypto_lock_rand = 0;
ASYNC_unblock_pause();
CRYPTO_THREAD_unlock(rand_lock);
while (num > 0) {
j = (num >= MD_DIGEST_LENGTH / 2) ? MD_DIGEST_LENGTH / 2 : num;
num -= j;
if (!MD_Init(m))
goto err;
#ifndef GETPID_IS_MEANINGLESS
if (curr_pid) {
if (!MD_Update(m, (unsigned char *)&curr_pid, sizeof curr_pid))
goto err;
curr_pid = 0;
}
#endif
if (curr_time) {
if (!MD_Update(m, (unsigned char *)&curr_time, sizeof curr_time))
goto err;
if (!MD_Update(m, (unsigned char *)&tv, sizeof tv))
goto err;
curr_time = 0;
if (!rand_hw_seed(m))
goto err;
}
if (!MD_Update(m, local_md, MD_DIGEST_LENGTH))
goto err;
if (!MD_Update(m, (unsigned char *)&(md_c[0]), sizeof(md_c)))
goto err;
k = (st_idx + MD_DIGEST_LENGTH / 2) - st_num;
if (k > 0) {
if (!MD_Update(m, &(state[st_idx]), MD_DIGEST_LENGTH / 2 - k))
goto err;
if (!MD_Update(m, &(state[0]), k))
goto err;
} else if (!MD_Update(m, &(state[st_idx]), MD_DIGEST_LENGTH / 2))
goto err;
if (!MD_Final(m, local_md))
goto err;
for (i = 0; i < MD_DIGEST_LENGTH / 2; i++) {
state[st_idx++] ^= local_md[i];
if (st_idx >= st_num)
st_idx = 0;
if (i < j)
*(buf++) = local_md[i + MD_DIGEST_LENGTH / 2];
}
}
if (!MD_Init(m)
|| !MD_Update(m, (unsigned char *)&(md_c[0]), sizeof(md_c))
|| !MD_Update(m, local_md, MD_DIGEST_LENGTH))
goto err;
CRYPTO_THREAD_write_lock(rand_lock);
ASYNC_block_pause();
if (!MD_Update(m, md, MD_DIGEST_LENGTH) || !MD_Final(m, md)) {
CRYPTO_THREAD_unlock(rand_lock);
goto err;
}
ASYNC_unblock_pause();
CRYPTO_THREAD_unlock(rand_lock);
EVP_MD_CTX_free(m);
if (ok)
return (1);
else if (pseudo)
return 0;
else {
RANDerr(RAND_F_RAND_BYTES, RAND_R_PRNG_NOT_SEEDED);
ERR_add_error_data(1, "You need to read the OpenSSL FAQ, "
"https://www.openssl.org/docs/faq.html");
return (0);
}
err:
RANDerr(RAND_F_RAND_BYTES, ERR_R_EVP_LIB);
EVP_MD_CTX_free(m);
return 0;
err_mem:
RANDerr(RAND_F_RAND_BYTES, ERR_R_MALLOC_FAILURE);
EVP_MD_CTX_free(m);
return 0;
}
static int rand_nopseudo_bytes(unsigned char *buf, int num)
{
return rand_bytes(buf, num, 0);
}
static int rand_pseudo_bytes(unsigned char *buf, int num)
{
return rand_bytes(buf, num, 1);
}
static int rand_status(void)
{
CRYPTO_THREAD_ID cur;
int ret;
int do_not_lock;
if (!RUN_ONCE(&rand_lock_init, do_rand_lock_init))
return 0;
cur = CRYPTO_THREAD_get_current_id();
if (crypto_lock_rand) {
CRYPTO_THREAD_read_lock(rand_tmp_lock);
do_not_lock = CRYPTO_THREAD_compare_id(locking_threadid, cur);
CRYPTO_THREAD_unlock(rand_tmp_lock);
} else
do_not_lock = 0;
if (!do_not_lock) {
CRYPTO_THREAD_write_lock(rand_lock);
ASYNC_block_pause();
CRYPTO_THREAD_write_lock(rand_tmp_lock);
locking_threadid = cur;
CRYPTO_THREAD_unlock(rand_tmp_lock);
crypto_lock_rand = 1;
}
if (!initialized) {
RAND_poll();
initialized = 1;
}
ret = entropy >= ENTROPY_NEEDED;
if (!do_not_lock) {
crypto_lock_rand = 0;
ASYNC_unblock_pause();
CRYPTO_THREAD_unlock(rand_lock);
}
return ret;
}
static int rand_hw_seed(EVP_MD_CTX *ctx)
{
int i;
if (!(OPENSSL_ia32cap_P[1] & (1 << (62 - 32))))
return 1;
for (i = 0; i < RDRAND_CALLS; i++) {
size_t rnd;
rnd = OPENSSL_ia32_rdrand();
if (rnd == 0)
return 1;
if (!MD_Update(ctx, (unsigned char *)&rnd, sizeof(size_t)))
return 0;
}
return 1;
}
void rand_hw_xor(unsigned char *buf, size_t num)
{
size_t rnd;
if (!(OPENSSL_ia32cap_P[1] & (1 << (62 - 32))))
return;
while (num >= sizeof(size_t)) {
rnd = OPENSSL_ia32_rdrand();
if (rnd == 0)
return;
*((size_t *)buf) ^= rnd;
buf += sizeof(size_t);
num -= sizeof(size_t);
}
if (num) {
rnd = OPENSSL_ia32_rdrand();
if (rnd == 0)
return;
while (num) {
*buf ^= rnd & 0xff;
rnd >>= 8;
buf++;
num--;
}
}
}
static int rand_hw_seed(EVP_MD_CTX *ctx)
{
return 1;
}
void rand_hw_xor(unsigned char *buf, size_t num)
{
return;
}
