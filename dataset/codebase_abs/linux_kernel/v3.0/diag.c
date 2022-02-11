int F_1 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_3 )
{
register unsigned long T_1 V_4 ( L_1 ) = V_2 ;
register unsigned long T_2 V_4 ( L_2 ) = V_3 ;
int V_5 = 0 ;
asm volatile(
#ifdef F_2
" sam31\n"
" diag %2,2,0x14\n"
" sam64\n"
#else
" diag %2,2,0x14\n"
#endif
" ipm %0\n"
" srl %0,28\n"
: "=d" (rc), "+d" (_ry2)
: "d" (rx), "d" (_ry1)
: "cc");
return V_5 ;
}
int F_3 ( struct F_3 * V_6 )
{
static struct F_3 V_7 ;
static F_4 ( V_8 ) ;
unsigned long V_9 ;
int V_10 ;
F_5 ( & V_8 , V_9 ) ;
V_7 = * V_6 ;
#ifdef F_2
asm volatile(
" lhi %0,-1\n"
" sam31\n"
" diag %1,0,0x210\n"
"0: ipm %0\n"
" srl %0,28\n"
"1: sam64\n"
EX_TABLE(0b, 1b)
: "=&d" (ccode) : "a" (&diag210_tmp) : "cc", "memory");
#else
asm volatile(
" lhi %0,-1\n"
" diag %1,0,0x210\n"
"0: ipm %0\n"
" srl %0,28\n"
"1:\n"
EX_TABLE(0b, 1b)
: "=&d" (ccode) : "a" (&diag210_tmp) : "cc", "memory");
#endif
* V_6 = V_7 ;
F_6 ( & V_8 , V_9 ) ;
return V_10 ;
}
