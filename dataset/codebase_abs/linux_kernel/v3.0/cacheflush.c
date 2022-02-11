void F_1 ( unsigned long V_1 , unsigned long V_2 )
{
F_2 ( ( const void * ) V_1 , V_2 - V_1 , V_3 ) ;
}
static inline void F_3 ( char * V_4 )
{
* ( volatile char * ) V_4 ;
}
void F_4 ( void * V_5 , T_1 V_6 , int V_7 )
{
char * V_4 , * V_8 ;
T_1 V_9 , V_10 ;
const unsigned long V_11 = 8192 ;
#ifdef F_5
T_2 V_12 = F_6 ( V_13 ) ;
F_7 ( V_13 , 0 ) ;
#endif
F_8 ( V_5 , V_6 ) ;
F_9 () ;
if ( V_7 ) {
V_9 = V_14 ;
V_10 = ( V_11 / V_14 ) *
( 1 << F_10 () ) ;
} else {
V_9 = V_11 ;
V_10 = ( 1 << F_10 () ) ;
}
V_4 = ( char * ) V_5 + V_6 - 1 ;
F_3 ( V_4 ) ;
V_4 -= V_9 ;
V_4 = ( char * ) ( ( unsigned long ) V_4 | ( V_9 - 1 ) ) ;
V_8 = V_4 - ( V_9 * ( V_10 - 2 ) ) ;
if ( ( long ) V_8 < ( long ) V_5 )
V_8 = V_5 ;
#pragma V_15 V_16
for (; V_4 >= V_8 ; V_4 -= V_9 )
F_3 ( V_4 ) ;
V_4 = ( char * ) V_5 + V_6 - 1 ;
F_11 ( V_4 ) ;
V_4 -= V_9 ;
V_4 = ( char * ) ( ( unsigned long ) V_4 | ( V_9 - 1 ) ) ;
for (; V_4 >= V_8 ; V_4 -= V_9 )
F_11 ( V_4 ) ;
F_9 () ;
#ifdef F_5
F_7 ( V_13 , V_12 ) ;
#endif
}
