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
T_1 F_4 ( struct V_1 * V_1 , T_2 V_11 )
{
T_1 V_12 ;
F_5 ( V_12 ) = ( F_6 ( V_1 ) << V_13 ) | F_7 ( V_11 ) ;
return V_12 ;
}
void F_8 ( struct V_14 * V_15 , unsigned long V_8 ,
T_1 * V_16 , T_1 V_12 )
{
* V_16 = V_12 ;
F_9 () ;
}
void T_3 F_10 ( void )
{
unsigned long V_17 ;
T_4 * V_18 ;
F_1 ( ( unsigned long ) V_19 ) ;
#ifndef F_2
F_3 ( ( unsigned long ) V_6 , ( unsigned long ) V_5 ) ;
#endif
V_18 = V_19 ;
V_17 = F_11 ( V_20 - 1 ) & V_21 ;
F_12 ( V_17 , V_17 + V_22 , V_18 ) ;
}
