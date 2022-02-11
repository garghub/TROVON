static inline void *
F_1 ( unsigned long * V_1 , void * V_2 )
{
unsigned long V_3 = ( unsigned long ) V_2 ;
unsigned long V_4 ;
V_4 = V_1 [ V_3 >> 13 ] ;
V_4 >>= 32 ;
V_4 <<= 13 ;
V_4 |= V_3 & 0x1fff ;
return ( void * ) V_4 ;
}
void
F_2 ( void )
{
unsigned long V_5 , V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
V_11 -> V_12 = 0 ;
V_11 -> V_13 = 0 ;
V_11 -> V_14 = V_15 [ 1 ] >> 32 ;
V_11 -> V_16 = 0 ;
V_11 -> V_17 = 0 ;
V_11 -> V_18 = 0 ;
V_11 -> V_19 = 1 ;
V_11 -> V_20 = 0 ;
V_11 -> V_21 = 0 ;
V_10 = F_1 ( V_22 , V_11 ) ;
F_3 ( L_1 ) ;
V_5 = F_4 ( 2 , V_11 , V_10 , V_22 ) ;
if ( V_5 ) {
F_3 ( L_2 , V_5 ) ;
F_5 () ;
}
V_8 = (struct V_7 * )
( V_23 -> V_24 + ( unsigned long ) V_23 ) ;
V_6 = V_8 -> V_25 = V_8 -> V_26 [ 2 ] ;
F_3 ( L_3 , V_6 ) ;
F_6 () ;
}
static inline void
F_7 ( unsigned long V_27 , unsigned long V_28 , unsigned long V_29 )
{
memcpy ( ( void * ) V_27 , ( void * ) V_28 , V_29 ) ;
}
static inline void
F_8 ( void )
{
__asm__ __volatile__(
"bis %0,%0,$27\n\t"
"jmp ($27)"
:
: "r" (START_ADDR));
}
void
F_9 ( void )
{
static long V_30 ;
static char V_31 [ 256 ] V_32 ( ( F_10 ( 8 ) ) ) ;
static unsigned long V_33 ;
F_3 ( L_4 V_34 L_5 ) ;
if ( V_23 -> V_35 != 8192 ) {
F_3 ( L_6 ,
V_23 -> V_35 >> 10 ) ;
return;
}
if ( V_23 -> V_1 != ( unsigned long ) V_22 ) {
F_3 ( L_7 ,
V_22 , ( void * ) V_23 -> V_1 ) ;
return;
}
F_2 () ;
V_33 = ( ( V_36 + 5 * V_37 + V_38 ) |
( V_38 - 1 ) ) + 1 ;
#ifdef F_11
F_3 ( L_8 , V_33 ) ;
#endif
F_12 ( V_33 - V_38 ) ;
V_30 = F_13 ( V_39 , V_31 , sizeof( V_31 ) ) ;
if ( V_30 < 0 || V_30 >= sizeof( V_31 ) ) {
V_30 = 0 ;
}
V_31 [ V_30 ] = '\0' ;
F_3 ( L_9 , V_31 ) ;
#ifdef F_11
F_7 ( V_33 , V_40 + V_37 , F_11 ) ;
#endif
F_7 ( V_36 + ( 4 * V_37 ) , V_40 , V_37 ) ;
F_7 ( V_36 , V_36 + ( 4 * V_37 ) , V_37 ) ;
memset ( ( char * ) V_41 , 0 , V_38 ) ;
strcpy ( ( char * ) V_41 , V_31 ) ;
#ifdef F_11
( ( long * ) ( V_41 + 256 ) ) [ 0 ] = V_33 ;
( ( long * ) ( V_41 + 256 ) ) [ 1 ] = F_11 ;
#endif
F_8 () ;
}
