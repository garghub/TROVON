void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
F_2 ( L_2 ,
0xffff & F_3 ( V_2 ) , F_4 ( V_2 ) ,
F_5 () , F_6 () ) ;
if ( F_3 ( V_2 ) & 3 )
F_2 ( L_3 , 0xffff & F_7 ( V_2 ) ,
F_8 ( V_2 ) ) ;
F_2 ( L_4 , F_9 ( V_2 ) ,
F_6 () ) ;
F_2 ( L_5 ,
F_10 ( V_2 ) , F_11 ( V_2 ) ,
F_12 ( V_2 ) , F_13 ( V_2 ) ) ;
F_2 ( L_6 ,
F_14 ( V_2 ) , F_15 ( V_2 ) , F_16 ( V_2 ) ) ;
F_2 ( L_7 ,
0xffff & F_17 ( V_2 ) ,
0xffff & F_18 ( V_2 ) ) ;
F_19 ( NULL , ( unsigned long * ) & V_2 ) ;
}
static inline int F_20 ( struct V_3 * V_4 , void * V_5 )
{
return V_5 > ( void * ) V_4 &&
V_5 < ( void * ) V_4 + V_6 - 3 ;
}
static inline unsigned long F_21 ( struct V_3 * V_4 ,
unsigned long * V_7 , unsigned long V_8 )
{
unsigned long V_9 ;
#ifdef F_22
while ( F_20 ( V_4 , ( void * ) V_8 ) ) {
V_9 = * ( unsigned long * ) ( V_8 + 4 ) ;
F_2 ( L_8 , V_8 + 4 , V_9 ) ;
F_23 ( L_9 , V_9 ) ;
F_2 ( L_1 ) ;
V_8 = * ( unsigned long * ) V_8 ;
}
#else
while ( F_20 ( V_4 , V_7 ) ) {
V_9 = * V_7 ;
if ( F_24 ( V_9 ) ) {
F_2 ( L_8 , ( unsigned long ) V_7 , V_9 ) ;
F_23 ( L_9 , V_9 ) ;
F_2 ( L_1 ) ;
}
V_7 ++ ;
}
#endif
return V_8 ;
}
void F_19 ( struct V_10 * V_11 , unsigned long * V_7 )
{
unsigned long V_8 ;
struct V_3 * V_12 ;
if ( ! V_7 ) {
V_7 = ( unsigned long * ) & V_7 ;
F_2 ( L_10 ) ;
F_25 ( 1 ) ;
}
if ( ! V_11 )
V_11 = V_13 ;
if ( V_11 != V_13 ) {
V_8 = ( unsigned long ) F_26 ( V_11 ) ;
} else {
asm ("movl %%ebp, %0" : "=r" (ebp) : );
}
V_12 = (struct V_3 * )
( ( unsigned long ) V_7 & ( ~ ( V_6 - 1 ) ) ) ;
F_21 ( V_12 , V_7 , V_8 ) ;
F_2 ( L_1 ) ;
}
