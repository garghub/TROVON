static inline void F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long type )
{
unsigned long V_3 ;
T_1 V_4 ;
V_4 = F_2 ( V_1 >> V_5 , V_6 ) ;
V_3 = F_3 ( V_4 ) ;
V_3 |= type ;
F_4 ( V_2 , V_3 ) ;
#ifdef F_5
F_6 ( V_2 ) ;
#endif
}
static inline void F_7 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long type , int V_7 )
{
if( F_8 ( V_2 & ~ V_8 ) == V_9 )
F_9 ( F_10 () , V_2 ) ;
while( V_7 ) {
F_1 ( V_1 , V_2 , type ) ;
V_1 += V_10 ;
V_2 += V_10 ;
V_7 -- ;
}
}
void T_2 * F_11 ( unsigned long V_1 , unsigned long V_11 ,
unsigned long type )
{
struct V_12 * V_13 ;
unsigned long V_14 , V_2 , V_15 ;
int V_7 ;
if( ! V_11 )
return NULL ;
V_14 = V_1 & ( V_10 - 1 ) ;
V_1 &= ~ ( V_10 - 1 ) ;
V_11 += V_14 ;
V_11 = F_12 ( V_11 ) ;
if( ( V_13 = F_13 ( V_11 , V_16 ) ) == NULL )
return NULL ;
#ifdef F_5
F_14 ( L_1 ,
V_13 -> V_17 , V_11 , V_13 -> V_11 ) ;
#endif
V_7 = V_11 / V_10 ;
V_2 = ( unsigned long ) V_13 -> V_17 ;
V_15 = V_2 + V_14 ;
while( V_7 ) {
int V_18 ;
V_18 = ( V_19 - ( V_2 & V_8 ) ) / V_10 ;
if( V_18 > V_7 )
V_18 = V_7 ;
F_7 ( V_1 , V_2 , type , V_18 ) ;
V_7 -= V_18 ;
V_1 += V_18 * V_10 ;
V_2 += V_18 * V_10 ;
}
return ( void T_2 * ) V_15 ;
}
void T_2 * F_15 ( unsigned long V_1 , unsigned long V_11 , int V_20 )
{
return F_11 ( V_1 , V_11 , V_21 ) ;
}
void F_16 ( void T_2 * V_17 )
{
F_17 ( ( void * ) ( V_22 & ( unsigned long ) V_17 ) ) ;
}
int F_18 ( unsigned long V_17 , char * V_23 )
{
int V_15 = 0 ;
__asm__ __volatile__
(".globl _sun3_map_test_start\n"
"_sun3_map_test_start:\n"
"1: moveb (%2), (%0)\n"
" moveq #1, %1\n"
"2:\n"
".section .fixup,\"ax\"\n"
".even\n"
"3: moveq #0, %1\n"
" jmp 2b\n"
".previous\n"
".section __ex_table,\"a\"\n"
".align 4\n"
".long 1b,3b\n"
".previous\n"
".globl _sun3_map_test_end\n"
"_sun3_map_test_end:\n"
: "=a"(val), "=r"(ret)
: "a"(addr));
return V_15 ;
}
