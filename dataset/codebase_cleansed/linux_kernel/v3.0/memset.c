void *memset(void *pdst, int c, unsigned int plen)
{
register char *return_dst __asm__ ("r10") = pdst;
register int n __asm__ ("r12") = plen;
register int lc __asm__ ("r11") = c;
__asm__("movu.b %0,r13 \n\
lslq 8,r13 \n\
move.b %0,r13 \n\
move.d r13,%0 \n\
lslq 16,r13 \n\
or.d r13,%0"
: "=r" (lc)
: "0" (lc)
: "r13");
{
register char *dst __asm__ ("r13") = pdst;
if (((unsigned long) pdst & 3) != 0
&& n >= 3)
{
if ((unsigned long) dst & 1)
{
*dst = (char) lc;
n--;
dst++;
}
if ((unsigned long) dst & 2)
{
*(short *) dst = lc;
n -= 2;
dst += 2;
}
}
if (n >= MEMSET_BY_BLOCK_THRESHOLD)
{
__asm__ volatile
("\
;; GCC does promise correct register allocations, but let's \n\
;; make sure it keeps its promises. \n\
.ifnc %0-%1-%4,$r13-$r12-$r11 \n\
.error \"GCC reg alloc bug: %0-%1-%4 != $r13-$r12-$r11\" \n\
.endif \n\
\n\
;; Save the registers we'll clobber in the movem process \n\
;; on the stack. Don't mention them to gcc, it will only be \n\
;; upset. \n\
subq 11*4,sp \n\
movem r10,[sp] \n\
\n\
move.d r11,r0 \n\
move.d r11,r1 \n\
move.d r11,r2 \n\
move.d r11,r3 \n\
move.d r11,r4 \n\
move.d r11,r5 \n\
move.d r11,r6 \n\
move.d r11,r7 \n\
move.d r11,r8 \n\
move.d r11,r9 \n\
move.d r11,r10 \n\
\n\
;; Now we've got this: \n\
;; r13 - dst \n\
;; r12 - n \n\
\n\
;; Update n for the first loop \n\
subq 12*4,r12 \n\
0: \n\
"
#ifdef __arch_common_v10_v32
" setf\n"
#endif
" subq 12*4,r12 \n\
bge 0b \n\
movem r11,[r13+] \n\
\n\
;; Compensate for last loop underflowing n. \n\
addq 12*4,r12 \n\
\n\
;; Restore registers from stack. \n\
movem [sp+],r10"
: "=r" (dst), "=r" (n)
: "0" (dst), "1" (n), "r" (lc));
}
while (n >= 16)
{
*(long *) dst = lc; dst += 4;
*(long *) dst = lc; dst += 4;
*(long *) dst = lc; dst += 4;
*(long *) dst = lc; dst += 4;
n -= 16;
}
switch (n)
{
case 0:
break;
case 1:
*dst = (char) lc;
break;
case 2:
*(short *) dst = (short) lc;
break;
case 3:
*(short *) dst = (short) lc; dst += 2;
*dst = (char) lc;
break;
case 4:
*(long *) dst = lc;
break;
case 5:
*(long *) dst = lc; dst += 4;
*dst = (char) lc;
break;
case 6:
*(long *) dst = lc; dst += 4;
*(short *) dst = (short) lc;
break;
case 7:
*(long *) dst = lc; dst += 4;
*(short *) dst = (short) lc; dst += 2;
*dst = (char) lc;
break;
case 8:
*(long *) dst = lc; dst += 4;
*(long *) dst = lc;
break;
case 9:
*(long *) dst = lc; dst += 4;
*(long *) dst = lc; dst += 4;
*dst = (char) lc;
break;
case 10:
*(long *) dst = lc; dst += 4;
*(long *) dst = lc; dst += 4;
*(short *) dst = (short) lc;
break;
case 11:
*(long *) dst = lc; dst += 4;
*(long *) dst = lc; dst += 4;
*(short *) dst = (short) lc; dst += 2;
*dst = (char) lc;
break;
case 12:
*(long *) dst = lc; dst += 4;
*(long *) dst = lc; dst += 4;
*(long *) dst = lc;
break;
case 13:
*(long *) dst = lc; dst += 4;
*(long *) dst = lc; dst += 4;
*(long *) dst = lc; dst += 4;
*dst = (char) lc;
break;
case 14:
*(long *) dst = lc; dst += 4;
*(long *) dst = lc; dst += 4;
*(long *) dst = lc; dst += 4;
*(short *) dst = (short) lc;
break;
case 15:
*(long *) dst = lc; dst += 4;
*(long *) dst = lc; dst += 4;
*(long *) dst = lc; dst += 4;
*(short *) dst = (short) lc; dst += 2;
*dst = (char) lc;
break;
}
}
return return_dst;
}
