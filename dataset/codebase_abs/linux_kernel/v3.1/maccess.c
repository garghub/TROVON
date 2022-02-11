static long F_1 ( void * V_1 , const void * V_2 , T_1 V_3 )
{
unsigned long V_4 , V_5 ;
int V_6 , V_7 ;
int V_8 = - V_9 ;
V_5 = ( unsigned long ) V_1 & ~ 3UL ;
V_6 = ( unsigned long ) V_1 & 3 ;
V_4 = F_2 (unsigned long, 4 - offset, size) ;
V_7 = ( 0xf << ( 4 - V_4 ) ) & 0xf ;
V_7 >>= V_6 ;
asm volatile(
" bras 1,0f\n"
" icm 0,0,0(%3)\n"
"0: l 0,0(%1)\n"
" lra %1,0(%1)\n"
"1: ex %2,0(1)\n"
"2: stura 0,%1\n"
" la %0,0\n"
"3:\n"
EX_TABLE(0b,3b) EX_TABLE(1b,3b) EX_TABLE(2b,3b)
: "+d" (rc), "+a" (aligned)
: "a" (mask), "a" (src) : "cc", "memory", "0", "1");
return V_8 ? V_8 : V_4 ;
}
long F_3 ( void * V_1 , const void * V_2 , T_1 V_3 )
{
long V_10 = 0 ;
while ( V_3 ) {
V_10 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_10 < 0 )
break;
V_1 += V_10 ;
V_2 += V_10 ;
V_3 -= V_10 ;
}
return V_10 < 0 ? - V_9 : 0 ;
}
int F_4 ( void * V_11 , void * V_2 , T_1 V_4 )
{
register unsigned long T_2 V_12 ( L_1 ) = ( unsigned long ) V_11 ;
register unsigned long T_3 V_12 ( L_2 ) = ( unsigned long ) V_4 ;
register unsigned long T_4 V_12 ( L_3 ) = ( unsigned long ) V_2 ;
register unsigned long T_5 V_12 ( L_4 ) = ( unsigned long ) V_4 ;
unsigned long V_13 ;
int V_8 = - V_9 ;
if ( ! V_4 )
return 0 ;
V_13 = F_5 ( 0xf8UL ) ;
asm volatile (
"0: mvcle %1,%2,0x0\n"
"1: jo 0b\n"
" lhi %0,0x0\n"
"2:\n"
EX_TABLE(1b,2b)
: "+d" (rc), "+d" (_dest), "+d" (_src), "+d" (_len1),
"+d" (_len2), "=m" (*((long *) dest))
: "m" (*((long *) src))
: "cc", "memory");
F_6 ( V_13 ) ;
return V_8 ;
}
void F_7 ( void * V_11 , void * V_2 , T_1 V_4 )
{
unsigned long V_14 ;
F_8 ( ( unsigned long ) V_11 + V_4 >= sizeof( struct V_15 ) ) ;
F_9 () ;
F_10 ( V_14 , 0 , 0 ) ;
F_11 ( 0 , 28 ) ;
F_4 ( V_11 + F_12 () , V_2 , V_4 ) ;
F_13 ( V_14 , 0 , 0 ) ;
F_14 () ;
}
