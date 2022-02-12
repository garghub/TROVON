uint32_t __div64_32(u64 *xp, u32 y)
{
uint32_t rem;
uint64_t q = __xdiv64_32(*xp, y);
rem = *xp - q * y;
*xp = q;
return rem;
}
