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
void F_4 ( struct V_11 * V_12 ,
unsigned long V_13 ,
T_1 * V_14 )
{
if ( ! F_5 ( * V_14 ) ) {
T_1 V_15 = F_6 ( * V_14 ) ;
F_7 ( V_12 -> V_16 , V_13 , V_14 , V_15 ) ;
}
}
T_1 F_8 ( struct V_1 * V_1 , T_2 V_17 )
{
T_1 V_15 ;
F_9 ( V_15 ) = ( F_10 ( V_1 ) << V_18 ) | F_11 ( V_17 ) ;
return V_15 ;
}
void F_7 ( struct V_19 * V_20 , unsigned long V_8 ,
T_1 * V_14 , T_1 V_15 )
{
* V_14 = V_15 ;
F_12 () ;
}
void T_3 F_13 ( void )
{
unsigned long V_21 ;
T_4 * V_22 ;
F_1 ( ( unsigned long ) V_23 ) ;
#ifndef F_2
F_3 ( ( unsigned long ) V_6 , ( unsigned long ) V_5 ) ;
#endif
V_22 = V_23 ;
V_21 = F_14 ( V_24 - 1 ) & V_25 ;
F_15 ( V_21 , V_21 + V_26 , V_22 ) ;
}
