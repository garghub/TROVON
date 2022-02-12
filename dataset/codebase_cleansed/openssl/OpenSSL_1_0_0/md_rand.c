RAND_METHOD *RAND_SSLeay(void)
{
return(&rand_ssleay_meth);
}
static void ssleay_rand_cleanup(void)
{
OPENSSL_cleanse(state,sizeof(state));
state_num=0;
state_index=0;
OPENSSL_cleanse(md,MD_DIGEST_LENGTH);
md_count[0]=0;
md_count[1]=0;
entropy=0;
initialized=0;
}
static void ssleay_rand_add(const void *buf, int num, double add)
{
int i,j,k,st_idx;
long md_c[2];
unsigned char local_md[MD_DIGEST_LENGTH];
EVP_MD_CTX m;
int do_not_lock;
if (crypto_lock_rand)
{
CRYPTO_THREADID cur;
CRYPTO_THREADID_current(&cur);
CRYPTO_r_lock(CRYPTO_LOCK_RAND2);
do_not_lock = !CRYPTO_THREADID_cmp(&locking_threadid, &cur);
CRYPTO_r_unlock(CRYPTO_LOCK_RAND2);
}
else
do_not_lock = 0;
if (!do_not_lock) CRYPTO_w_lock(CRYPTO_LOCK_RAND);
st_idx=state_index;
md_c[0] = md_count[0];
md_c[1] = md_count[1];
memcpy(local_md, md, sizeof md);
state_index += num;
if (state_index >= STATE_SIZE)
{
state_index%=STATE_SIZE;
state_num=STATE_SIZE;
}
else if (state_num < STATE_SIZE)
{
if (state_index > state_num)
state_num=state_index;
}
md_count[1] += (num / MD_DIGEST_LENGTH) + (num % MD_DIGEST_LENGTH > 0);
if (!do_not_lock) CRYPTO_w_unlock(CRYPTO_LOCK_RAND);
EVP_MD_CTX_init(&m);
for (i=0; i<num; i+=MD_DIGEST_LENGTH)
{
j=(num-i);
j=(j > MD_DIGEST_LENGTH)?MD_DIGEST_LENGTH:j;
MD_Init(&m);
MD_Update(&m,local_md,MD_DIGEST_LENGTH);
k=(st_idx+j)-STATE_SIZE;
if (k > 0)
{
MD_Update(&m,&(state[st_idx]),j-k);
MD_Update(&m,&(state[0]),k);
}
else
MD_Update(&m,&(state[st_idx]),j);
MD_Update(&m,buf,j);
MD_Update(&m,(unsigned char *)&(md_c[0]),sizeof(md_c));
MD_Final(&m,local_md);
md_c[1]++;
buf=(const char *)buf + j;
for (k=0; k<j; k++)
{
state[st_idx++]^=local_md[k];
if (st_idx >= STATE_SIZE)
st_idx=0;
}
}
EVP_MD_CTX_cleanup(&m);
if (!do_not_lock) CRYPTO_w_lock(CRYPTO_LOCK_RAND);
for (k = 0; k < (int)sizeof(md); k++)
{
md[k] ^= local_md[k];
}
if (entropy < ENTROPY_NEEDED)
entropy += add;
if (!do_not_lock) CRYPTO_w_unlock(CRYPTO_LOCK_RAND);
#if !defined(OPENSSL_THREADS) && !defined(OPENSSL_SYS_WIN32)
assert(md_c[1] == md_count[1]);
#endif
}
static void ssleay_rand_seed(const void *buf, int num)
{
ssleay_rand_add(buf, num, (double)num);
}
static int ssleay_rand_bytes(unsigned char *buf, int num)
{
static volatile int stirred_pool = 0;
int i,j,k,st_num,st_idx;
int num_ceil;
int ok;
long md_c[2];
unsigned char local_md[MD_DIGEST_LENGTH];
EVP_MD_CTX m;
#ifndef GETPID_IS_MEANINGLESS
pid_t curr_pid = getpid();
#endif
int do_stir_pool = 0;
#ifdef PREDICT
if (rand_predictable)
{
static unsigned char val=0;
for (i=0; i<num; i++)
buf[i]=val++;
return(1);
}
#endif
if (num <= 0)
return 1;
EVP_MD_CTX_init(&m);
num_ceil = (1 + (num-1)/(MD_DIGEST_LENGTH/2)) * (MD_DIGEST_LENGTH/2);
CRYPTO_w_lock(CRYPTO_LOCK_RAND);
CRYPTO_w_lock(CRYPTO_LOCK_RAND2);
CRYPTO_THREADID_current(&locking_threadid);
CRYPTO_w_unlock(CRYPTO_LOCK_RAND2);
crypto_lock_rand = 1;
if (!initialized)
{
RAND_poll();
initialized = 1;
}
if (!stirred_pool)
do_stir_pool = 1;
ok = (entropy >= ENTROPY_NEEDED);
if (!ok)
{
entropy -= num;
if (entropy < 0)
entropy = 0;
}
if (do_stir_pool)
{
int n = STATE_SIZE;
while (n > 0)
{
#if MD_DIGEST_LENGTH > 20
# error "Please adjust DUMMY_SEED."
#endif
#define DUMMY_SEED "...................."
ssleay_rand_add(DUMMY_SEED, MD_DIGEST_LENGTH, 0.0);
n -= MD_DIGEST_LENGTH;
}
if (ok)
stirred_pool = 1;
}
st_idx=state_index;
st_num=state_num;
md_c[0] = md_count[0];
md_c[1] = md_count[1];
memcpy(local_md, md, sizeof md);
state_index+=num_ceil;
if (state_index > state_num)
state_index %= state_num;
md_count[0] += 1;
crypto_lock_rand = 0;
CRYPTO_w_unlock(CRYPTO_LOCK_RAND);
while (num > 0)
{
j=(num >= MD_DIGEST_LENGTH/2)?MD_DIGEST_LENGTH/2:num;
num-=j;
MD_Init(&m);
#ifndef GETPID_IS_MEANINGLESS
if (curr_pid)
{
MD_Update(&m,(unsigned char*)&curr_pid,sizeof curr_pid);
curr_pid = 0;
}
#endif
MD_Update(&m,local_md,MD_DIGEST_LENGTH);
MD_Update(&m,(unsigned char *)&(md_c[0]),sizeof(md_c));
#ifndef PURIFY
MD_Update(&m,buf,j);
#endif
k=(st_idx+MD_DIGEST_LENGTH/2)-st_num;
if (k > 0)
{
MD_Update(&m,&(state[st_idx]),MD_DIGEST_LENGTH/2-k);
MD_Update(&m,&(state[0]),k);
}
else
MD_Update(&m,&(state[st_idx]),MD_DIGEST_LENGTH/2);
MD_Final(&m,local_md);
for (i=0; i<MD_DIGEST_LENGTH/2; i++)
{
state[st_idx++]^=local_md[i];
if (st_idx >= st_num)
st_idx=0;
if (i < j)
*(buf++)=local_md[i+MD_DIGEST_LENGTH/2];
}
}
MD_Init(&m);
MD_Update(&m,(unsigned char *)&(md_c[0]),sizeof(md_c));
MD_Update(&m,local_md,MD_DIGEST_LENGTH);
CRYPTO_w_lock(CRYPTO_LOCK_RAND);
MD_Update(&m,md,MD_DIGEST_LENGTH);
MD_Final(&m,md);
CRYPTO_w_unlock(CRYPTO_LOCK_RAND);
EVP_MD_CTX_cleanup(&m);
if (ok)
return(1);
else
{
RANDerr(RAND_F_SSLEAY_RAND_BYTES,RAND_R_PRNG_NOT_SEEDED);
ERR_add_error_data(1, "You need to read the OpenSSL FAQ, "
"http://www.openssl.org/support/faq.html");
return(0);
}
}
static int ssleay_rand_pseudo_bytes(unsigned char *buf, int num)
{
int ret;
unsigned long err;
ret = RAND_bytes(buf, num);
if (ret == 0)
{
err = ERR_peek_error();
if (ERR_GET_LIB(err) == ERR_LIB_RAND &&
ERR_GET_REASON(err) == RAND_R_PRNG_NOT_SEEDED)
ERR_clear_error();
}
return (ret);
}
static int ssleay_rand_status(void)
{
CRYPTO_THREADID cur;
int ret;
int do_not_lock;
CRYPTO_THREADID_current(&cur);
if (crypto_lock_rand)
{
CRYPTO_r_lock(CRYPTO_LOCK_RAND2);
do_not_lock = !CRYPTO_THREADID_cmp(&locking_threadid, &cur);
CRYPTO_r_unlock(CRYPTO_LOCK_RAND2);
}
else
do_not_lock = 0;
if (!do_not_lock)
{
CRYPTO_w_lock(CRYPTO_LOCK_RAND);
CRYPTO_w_lock(CRYPTO_LOCK_RAND2);
CRYPTO_THREADID_cpy(&locking_threadid, &cur);
CRYPTO_w_unlock(CRYPTO_LOCK_RAND2);
crypto_lock_rand = 1;
}
if (!initialized)
{
RAND_poll();
initialized = 1;
}
ret = entropy >= ENTROPY_NEEDED;
if (!do_not_lock)
{
crypto_lock_rand = 0;
CRYPTO_w_unlock(CRYPTO_LOCK_RAND);
}
return ret;
}
