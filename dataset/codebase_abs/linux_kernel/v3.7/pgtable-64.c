void F_1 ( unsigned long V_1 )
{
unsigned long * V_2 , * V_3 ;
unsigned long V_4 ;
#ifdef F_2
V_4 = ( unsigned long ) V_5 ;
#else
V_4 = ( unsigned long ) V_6 ;
#endif
V_2 = ( unsigned long * ) V_1 ;
V_3 = V_2 + V_7 ;
do {
V_2 [ 0 ] = V_4 ;
V_2 [ 1 ] = V_4 ;
V_2 [ 2 ] = V_4 ;
V_2 [ 3 ] = V_4 ;
V_2 [ 4 ] = V_4 ;
V_2 += 8 ;
V_2 [ - 3 ] = V_4 ;
V_2 [ - 2 ] = V_4 ;
V_2 [ - 1 ] = V_4 ;
} while ( V_2 != V_3 );
}
void F_3 ( unsigned long V_8 , unsigned long V_9 )
{
unsigned long * V_2 , * V_3 ;
V_2 = ( unsigned long * ) V_8 ;
V_3 = V_2 + V_10 ;
do {
V_2 [ 0 ] = V_9 ;
V_2 [ 1 ] = V_9 ;
V_2 [ 2 ] = V_9 ;
V_2 [ 3 ] = V_9 ;
V_2 [ 4 ] = V_9 ;
V_2 += 8 ;
V_2 [ - 3 ] = V_9 ;
V_2 [ - 2 ] = V_9 ;
V_2 [ - 1 ] = V_9 ;
} while ( V_2 != V_3 );
}
void T_1 F_4 ( void )
{
unsigned long V_11 ;
T_2 * V_12 ;
F_1 ( ( unsigned long ) V_13 ) ;
#ifndef F_2
F_3 ( ( unsigned long ) V_6 , ( unsigned long ) V_5 ) ;
#endif
V_12 = V_13 ;
V_11 = F_5 ( V_14 - 1 ) & V_15 ;
F_6 ( V_11 , V_11 + V_16 , V_12 ) ;
}
