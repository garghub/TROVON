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
}
static void ssleay_rand_seed(const void *buf, int num)
{
int i,j,k,st_idx,st_num;
MD_CTX m;
#ifdef NORAND
return;
#endif
CRYPTO_w_lock(CRYPTO_LOCK_RAND);
st_idx=state_index;
st_num=state_num;
state_index=(state_index+num);
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
CRYPTO_w_unlock(CRYPTO_LOCK_RAND);
for (i=0; i<num; i+=MD_DIGEST_LENGTH)
{
j=(num-i);
j=(j > MD_DIGEST_LENGTH)?MD_DIGEST_LENGTH:j;
MD_Init(&m);
MD_Update(&m,md,MD_DIGEST_LENGTH);
k=(st_idx+j)-STATE_SIZE;
if (k > 0)
{
MD_Update(&m,&(state[st_idx]),j-k);
MD_Update(&m,&(state[0]),k);
}
else
MD_Update(&m,&(state[st_idx]),j);
MD_Update(&m,buf,j);
MD_Update(&m,(unsigned char *)&(md_count[0]),sizeof(md_count));
MD_Final(md,&m);
md_count[1]++;
buf=(const char *)buf + j;
for (k=0; k<j; k++)
{
state[st_idx++]^=md[k];
if (st_idx >= STATE_SIZE)
{
st_idx=0;
st_num=STATE_SIZE;
}
}
}
memset((char *)&m,0,sizeof(m));
}
static void ssleay_rand_bytes(unsigned char *buf, int num)
{
int i,j,k,st_num,st_idx;
MD_CTX m;
static int init=1;
unsigned long l;
#ifdef DEVRANDOM
FILE *fh;
#endif
#ifdef PREDICT
{
static unsigned char val=0;
for (i=0; i<num; i++)
buf[i]=val++;
return;
}
#endif
CRYPTO_w_lock(CRYPTO_LOCK_RAND);
if (init)
{
CRYPTO_w_unlock(CRYPTO_LOCK_RAND);
RAND_seed(&m,sizeof(m));
#ifndef MSDOS
l=getpid();
RAND_seed(&l,sizeof(l));
l=getuid();
RAND_seed(&l,sizeof(l));
#endif
l=time(NULL);
RAND_seed(&l,sizeof(l));
if ((fh = fopen(DEVRANDOM, "r")) != NULL)
{
unsigned char tmpbuf[32];
fread((unsigned char *)tmpbuf,1,32,fh);
fclose(fh);
RAND_seed(tmpbuf,32);
memset(tmpbuf,0,32);
}
#ifdef PURIFY
memset(state,0,STATE_SIZE);
memset(md,0,MD_DIGEST_LENGTH);
#endif
CRYPTO_w_lock(CRYPTO_LOCK_RAND);
init=0;
}
st_idx=state_index;
st_num=state_num;
state_index+=num;
if (state_index > state_num)
state_index=(state_index%state_num);
CRYPTO_w_unlock(CRYPTO_LOCK_RAND);
while (num > 0)
{
j=(num >= MD_DIGEST_LENGTH/2)?MD_DIGEST_LENGTH/2:num;
num-=j;
MD_Init(&m);
MD_Update(&m,&(md[MD_DIGEST_LENGTH/2]),MD_DIGEST_LENGTH/2);
MD_Update(&m,(unsigned char *)&(md_count[0]),sizeof(md_count));
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
MD_Final(md,&m);
for (i=0; i<j; i++)
{
if (st_idx >= st_num)
st_idx=0;
state[st_idx++]^=md[i];
*(buf++)=md[i+MD_DIGEST_LENGTH/2];
}
}
MD_Init(&m);
MD_Update(&m,(unsigned char *)&(md_count[0]),sizeof(md_count));
md_count[0]++;
MD_Update(&m,md,MD_DIGEST_LENGTH);
MD_Final(md,&m);
memset(&m,0,sizeof(m));
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
