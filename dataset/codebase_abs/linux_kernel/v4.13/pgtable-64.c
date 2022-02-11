void F_1 ( unsigned long V_1 )
{
unsigned long * V_2 , * V_3 ;
unsigned long V_4 ;
#if ! F_2 ( V_5 )
V_4 = ( unsigned long ) V_6 ;
#elif ! F_2 ( V_7 )
V_4 = ( unsigned long ) V_8 ;
#else
V_4 = ( unsigned long ) V_9 ;
#endif
V_2 = ( unsigned long * ) V_1 ;
V_3 = V_2 + V_10 ;
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
void F_3 ( unsigned long V_11 , unsigned long V_12 )
{
unsigned long * V_2 , * V_3 ;
V_2 = ( unsigned long * ) V_11 ;
V_3 = V_2 + V_13 ;
do {
V_2 [ 0 ] = V_12 ;
V_2 [ 1 ] = V_12 ;
V_2 [ 2 ] = V_12 ;
V_2 [ 3 ] = V_12 ;
V_2 [ 4 ] = V_12 ;
V_2 += 8 ;
V_2 [ - 3 ] = V_12 ;
V_2 [ - 2 ] = V_12 ;
V_2 [ - 1 ] = V_12 ;
} while ( V_2 != V_3 );
}
void F_4 ( unsigned long V_11 , unsigned long V_12 )
{
unsigned long * V_2 , * V_3 ;
V_2 = ( unsigned long * ) V_11 ;
V_3 = V_2 + V_14 ;
do {
V_2 [ 0 ] = V_12 ;
V_2 [ 1 ] = V_12 ;
V_2 [ 2 ] = V_12 ;
V_2 [ 3 ] = V_12 ;
V_2 [ 4 ] = V_12 ;
V_2 += 8 ;
V_2 [ - 3 ] = V_12 ;
V_2 [ - 2 ] = V_12 ;
V_2 [ - 1 ] = V_12 ;
} while ( V_2 != V_3 );
}
T_1 F_5 ( struct V_1 * V_1 , T_2 V_15 )
{
T_1 V_16 ;
F_6 ( V_16 ) = ( F_7 ( V_1 ) << V_17 ) | F_8 ( V_15 ) ;
return V_16 ;
}
void F_9 ( struct V_18 * V_19 , unsigned long V_11 ,
T_1 * V_20 , T_1 V_16 )
{
* V_20 = V_16 ;
F_10 () ;
}
void T_3 F_11 ( void )
{
unsigned long V_21 ;
T_4 * V_22 ;
F_1 ( ( unsigned long ) V_23 ) ;
#ifndef V_5
F_4 ( ( unsigned long ) V_6 , ( unsigned long ) V_8 ) ;
#endif
#ifndef V_7
F_3 ( ( unsigned long ) V_8 , ( unsigned long ) V_9 ) ;
#endif
V_22 = V_23 ;
V_21 = F_12 ( V_24 - 1 ) & V_25 ;
F_13 ( V_21 , V_21 + V_26 , V_22 ) ;
}
