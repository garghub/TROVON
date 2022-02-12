unsigned long __cpuinit run_uncached(void *func)
{
register long sp __asm__("$sp");
register long ret __asm__("$2");
long lfunc = (long)func, ufunc;
long usp;
if (sp >= (long)CKSEG0 && sp < (long)CKSEG2)
usp = CKSEG1ADDR(sp);
#ifdef CONFIG_64BIT
else if ((long long)sp >= (long long)PHYS_TO_XKPHYS(0, 0) &&
(long long)sp < (long long)PHYS_TO_XKPHYS(8, 0))
usp = PHYS_TO_XKPHYS(K_CALG_UNCACHED,
XKPHYS_TO_PHYS((long long)sp));
#endif
else {
BUG();
usp = sp;
}
if (lfunc >= (long)CKSEG0 && lfunc < (long)CKSEG2)
ufunc = CKSEG1ADDR(lfunc);
#ifdef CONFIG_64BIT
else if ((long long)lfunc >= (long long)PHYS_TO_XKPHYS(0, 0) &&
(long long)lfunc < (long long)PHYS_TO_XKPHYS(8, 0))
ufunc = PHYS_TO_XKPHYS(K_CALG_UNCACHED,
XKPHYS_TO_PHYS((long long)lfunc));
#endif
else {
BUG();
ufunc = lfunc;
}
__asm__ __volatile__ (
" move $16, $sp\n"
" move $sp, %1\n"
" jalr %2\n"
" move $sp, $16"
: "=r" (ret)
: "r" (usp), "r" (ufunc)
: "$16", "$31");
return ret;
}
