const char *DES_options(void)
{
static int init = 1;
static char buf[32];
if (init) {
const char *ptr, *unroll, *risc, *size;
#ifdef DES_PTR
ptr = "ptr";
#else
ptr = "idx";
#endif
#if defined(DES_RISC1) || defined(DES_RISC2)
# ifdef DES_RISC1
risc = "risc1";
# endif
# ifdef DES_RISC2
risc = "risc2";
# endif
#else
risc = "cisc";
#endif
#ifdef DES_UNROLL
unroll = "16";
#else
unroll = "2";
#endif
if (sizeof(DES_LONG) != sizeof(long))
size = "int";
else
size = "long";
BIO_snprintf(buf, sizeof buf, "des(%s,%s,%s,%s)", ptr, risc, unroll,
size);
init = 0;
}
return (buf);
}
void DES_ecb_encrypt(const_DES_cblock *input, DES_cblock *output,
DES_key_schedule *ks, int enc)
{
register DES_LONG l;
DES_LONG ll[2];
const unsigned char *in = &(*input)[0];
unsigned char *out = &(*output)[0];
c2l(in, l);
ll[0] = l;
c2l(in, l);
ll[1] = l;
DES_encrypt1(ll, ks, enc);
l = ll[0];
l2c(l, out);
l = ll[1];
l2c(l, out);
l = ll[0] = ll[1] = 0;
}
