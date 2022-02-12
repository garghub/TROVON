static int bnrand(int pseudorand, BIGNUM *rnd, int bits, int top, int bottom)
{
unsigned char *buf=NULL;
int ret=0,bit,bytes,mask;
time_t tim;
bytes=(bits+7)/8;
bit=(bits-1)%8;
mask=0xff<<bit;
buf=(unsigned char *)Malloc(bytes);
if (buf == NULL)
{
BNerr(BN_F_BN_RAND,ERR_R_MALLOC_FAILURE);
goto err;
}
time(&tim);
RAND_add(&tim,sizeof(tim),0);
if (pseudorand)
{
if (RAND_pseudo_bytes(buf, bytes) == -1)
goto err;
}
else
{
if (RAND_bytes(buf, bytes) <= 0)
goto err;
}
if (top)
{
if (bit == 0)
{
buf[0]=1;
buf[1]|=0x80;
}
else
{
buf[0]|=(3<<(bit-1));
buf[0]&= ~(mask<<1);
}
}
else
{
buf[0]|=(1<<bit);
buf[0]&= ~(mask<<1);
}
if (bottom)
buf[bytes-1]|=1;
if (!BN_bin2bn(buf,bytes,rnd)) goto err;
ret=1;
err:
if (buf != NULL)
{
memset(buf,0,bytes);
Free(buf);
}
return(ret);
}
int BN_rand(BIGNUM *rnd, int bits, int top, int bottom)
{
return bnrand(0, rnd, bits, top, bottom);
}
int BN_pseudo_rand(BIGNUM *rnd, int bits, int top, int bottom)
{
return bnrand(1, rnd, bits, top, bottom);
}
