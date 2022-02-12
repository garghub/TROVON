const char *RC4_options(void)
{
#ifdef RC4_INDEX
if (sizeof(RC4_INT) == 1)
return("rc4(idx,char)");
else
return("rc4(idx,int)");
#else
if (sizeof(RC4_INT) == 1)
return("rc4(ptr,char)");
else
return("rc4(ptr,int)");
#endif
}
void RC4_set_key(RC4_KEY *key, int len, const unsigned char *data)
{
register RC4_INT tmp;
register int id1,id2;
register RC4_INT *d;
unsigned int i;
d= &(key->data[0]);
key->x = 0;
key->y = 0;
id1=id2=0;
#define SK_LOOP(d,n) { \
tmp=d[(n)]; \
id2 = (data[id1] + tmp + id2) & 0xff; \
if (++id1 == len) id1=0; \
d[(n)]=d[id2]; \
d[id2]=tmp; }
#if defined(OPENSSL_CPUID_OBJ) && !defined(OPENSSL_NO_ASM)
# if defined(__i386) || defined(__i386__) || defined(_M_IX86) || \
defined(__INTEL__) || \
defined(__x86_64) || defined(__x86_64__) || defined(_M_AMD64)
if (sizeof(RC4_INT) > 1) {
if (OPENSSL_ia32cap_P & (1<<28)) {
unsigned char *cp=(unsigned char *)d;
for (i=0;i<256;i++) cp[i]=i;
for (i=0;i<256;i++) SK_LOOP(cp,i);
d[256/sizeof(RC4_INT)]=-1;
return;
}
}
# endif
#endif
for (i=0; i < 256; i++) d[i]=i;
for (i=0; i < 256; i+=4)
{
SK_LOOP(d,i+0);
SK_LOOP(d,i+1);
SK_LOOP(d,i+2);
SK_LOOP(d,i+3);
}
}
