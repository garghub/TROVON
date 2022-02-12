RAND_METHOD *RAND_SSLeay(void)
{
return(&rand_ssleay_meth);
}
static void ssleay_rand_cleanup(void)
{
memset(state,0,sizeof(state));
state_num=0;
state_index=0;
memset(md,0,MD_DIGEST_LENGTH);
md_count[0]=0;
md_count[1]=0;
entropy=0;
}
static void ssleay_rand_add(const void *buf, int num, double add)
{
int i,j,k,st_idx;
long md_c[2];
unsigned char local_md[MD_DIGEST_LENGTH];
MD_CTX m;
#ifdef NORAND
return;
#endif
CRYPTO_w_lock(CRYPTO_LOCK_RAND);
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
CRYPTO_w_unlock(CRYPTO_LOCK_RAND);
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
MD_Final(local_md,&m);
md_c[1]++;
buf=(const char *)buf + j;
for (k=0; k<j; k++)
{
state[st_idx++]^=local_md[k];
if (st_idx >= STATE_SIZE)
st_idx=0;
}
}
memset((char *)&m,0,sizeof(m));
CRYPTO_w_lock(CRYPTO_LOCK_RAND);
for (k = 0; k < sizeof md; k++)
{
md[k] ^= local_md[k];
}
if (entropy < ENTROPY_NEEDED)
entropy += add;
CRYPTO_w_unlock(CRYPTO_LOCK_RAND);
#ifndef THREADS
assert(md_c[1] == md_count[1]);
#endif
}
static void ssleay_rand_seed(const void *buf, int num)
{
ssleay_rand_add(buf, num, num);
}
static void ssleay_rand_initialize(void)
{
unsigned long l;
#ifndef GETPID_IS_MEANINGLESS
pid_t curr_pid = getpid();
#endif
#ifdef DEVRANDOM
FILE *fh;
#endif
CRYPTO_w_unlock(CRYPTO_LOCK_RAND);
#ifndef GETPID_IS_MEANINGLESS
l=curr_pid;
RAND_add(&l,sizeof(l),0);
l=getuid();
RAND_add(&l,sizeof(l),0);
#endif
l=time(NULL);
RAND_add(&l,sizeof(l),0);
#ifdef DEVRANDOM
if ((fh = fopen(DEVRANDOM, "r")) != NULL)
{
unsigned char tmpbuf[ENTROPY_NEEDED];
int n;
setvbuf(fh, NULL, _IONBF, 0);
n=fread((unsigned char *)tmpbuf,1,ENTROPY_NEEDED,fh);
fclose(fh);
RAND_add(tmpbuf,sizeof tmpbuf,n);
memset(tmpbuf,0,n);
}
#endif
#ifdef PURIFY
memset(state,0,STATE_SIZE);
memset(md,0,MD_DIGEST_LENGTH);
#endif
CRYPTO_w_lock(CRYPTO_LOCK_RAND);
initialized=1;
}
static int ssleay_rand_bytes(unsigned char *buf, int num)
{
int i,j,k,st_num,st_idx;
int ok;
long md_c[2];
unsigned char local_md[MD_DIGEST_LENGTH];
MD_CTX m;
#ifndef GETPID_IS_MEANINGLESS
pid_t curr_pid = getpid();
#endif
#ifdef PREDICT
{
static unsigned char val=0;
for (i=0; i<num; i++)
buf[i]=val++;
return(1);
}
#endif
CRYPTO_w_lock(CRYPTO_LOCK_RAND);
if (!initialized)
ssleay_rand_initialize();
ok = (entropy >= ENTROPY_NEEDED);
if (!ok)
{
entropy -= num;
if (entropy < 0)
entropy = 0;
}
st_idx=state_index;
st_num=state_num;
md_c[0] = md_count[0];
md_c[1] = md_count[1];
memcpy(local_md, md, sizeof md);
state_index+=num;
if (state_index > state_num)
state_index %= state_num;
md_count[0] += 1;
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
MD_Update(&m,&(local_md[MD_DIGEST_LENGTH/2]),MD_DIGEST_LENGTH/2);
MD_Update(&m,(unsigned char *)&(md_c[0]),sizeof(md_c));
#ifndef PURIFY
MD_Update(&m,buf,j);
#endif
k=(st_idx+j)-st_num;
if (k > 0)
{
MD_Update(&m,&(state[st_idx]),j-k);
MD_Update(&m,&(state[0]),k);
}
else
MD_Update(&m,&(state[st_idx]),j);
MD_Final(local_md,&m);
for (i=0; i<j; i++)
{
state[st_idx++]^=local_md[i];
*(buf++)=local_md[i+MD_DIGEST_LENGTH/2];
if (st_idx >= st_num)
st_idx=0;
}
}
MD_Init(&m);
MD_Update(&m,(unsigned char *)&(md_c[0]),sizeof(md_c));
MD_Update(&m,local_md,MD_DIGEST_LENGTH);
CRYPTO_w_lock(CRYPTO_LOCK_RAND);
MD_Update(&m,md,MD_DIGEST_LENGTH);
MD_Final(md,&m);
CRYPTO_w_unlock(CRYPTO_LOCK_RAND);
memset(&m,0,sizeof(m));
if (ok)
return(1);
else
{
RANDerr(RAND_F_SSLEAY_RAND_BYTES,RAND_R_PRNG_NOT_SEEDED);
return(0);
}
}
static int ssleay_rand_pseudo_bytes(unsigned char *buf, int num)
{
int ret, err;
ret = RAND_bytes(buf, num);
if (ret == 0)
{
err = ERR_peek_error();
if (ERR_GET_LIB(err) == ERR_LIB_RAND &&
ERR_GET_REASON(err) == RAND_R_PRNG_NOT_SEEDED)
(void)ERR_get_error();
}
return (ret);
}
int RAND_status(void)
{
if (!initialized)
ssleay_rand_initialize();
return (entropy >= ENTROPY_NEEDED);
}
void RAND_screen(void)
{
HDC hScrDC;
HDC hMemDC;
HBITMAP hBitmap;
HBITMAP hOldBitmap;
BITMAP bm;
unsigned int size;
char *bmbits;
int w;
int h;
int y;
int n = 16;
hScrDC = CreateDC("DISPLAY", NULL, NULL, NULL);
hMemDC = CreateCompatibleDC(hScrDC);
w = GetDeviceCaps(hScrDC, HORZRES);
h = GetDeviceCaps(hScrDC, VERTRES);
hBitmap = CreateCompatibleBitmap(hScrDC, w, n);
hOldBitmap = SelectObject(hMemDC, hBitmap);
GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&bm);
size = (unsigned int)bm.bmWidthBytes * bm.bmHeight * bm.bmPlanes;
bmbits = Malloc(size);
if (bmbits) {
for (y = 0; y < h-n; y += n)
{
unsigned char md[MD_DIGEST_LENGTH];
BitBlt(hMemDC, 0, 0, w, n, hScrDC, 0, y, SRCCOPY);
GetBitmapBits(hBitmap, size, bmbits);
MD(bmbits,size,md);
RAND_seed(md, MD_DIGEST_LENGTH);
}
Free(bmbits);
}
hBitmap = SelectObject(hMemDC, hOldBitmap);
DeleteObject(hBitmap);
DeleteDC(hMemDC);
DeleteDC(hScrDC);
}
