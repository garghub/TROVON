int
popcount(unsigned int mask)
{
#if (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
return __builtin_popcount(mask);
#else
unsigned long y;
y = (mask >> 1) &033333333333;
y = mask - y - ((y >>1) & 033333333333);
return (((y + (y >> 3)) & 030707070707) % 077);
#endif
}
