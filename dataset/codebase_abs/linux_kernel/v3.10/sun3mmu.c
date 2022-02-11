void T_1 F_1 ( void )
{
T_2 * V_1 ;
T_3 * V_2 ;
int V_3 ;
unsigned long V_4 ;
unsigned long V_5 ;
unsigned long V_6 ;
unsigned long V_7 [ V_8 ] = { 0 , } ;
unsigned long V_9 ;
#ifdef F_2
V_10 = 0 ;
#endif
V_11 = F_3 ( V_12 ) ;
V_4 = V_13 ;
V_1 = V_14 ;
memset ( V_14 , 0 , sizeof ( V_14 ) ) ;
memset ( V_15 , 0 , sizeof ( V_15 ) ) ;
V_9 = V_16 * sizeof( T_3 ) ;
V_9 = ( V_9 + V_12 ) & ~ ( V_12 - 1 ) ;
V_5 = ( unsigned long ) F_3 ( V_9 ) ;
V_6 = ( V_5 + V_9 + V_12 ) & V_17 ;
V_1 += V_13 >> V_18 ;
while ( V_4 < ( unsigned long ) V_19 ) {
V_2 = ( T_3 * ) F_4 ( V_5 ) ;
V_5 += V_20 * sizeof ( T_3 ) ;
F_5 ( * V_1 ) = ( unsigned long ) V_2 ;
V_1 ++ ;
V_2 = ( T_3 * ) F_6 ( ( unsigned long ) V_2 ) ;
for ( V_3 = 0 ; V_3 < V_20 ; ++ V_3 , ++ V_2 ) {
T_3 V_21 = F_7 ( F_8 ( V_4 ) , V_22 ) ;
if ( V_4 >= ( unsigned long ) V_19 )
F_9 ( V_21 ) = 0 ;
F_10 ( V_2 , V_21 ) ;
V_4 += V_12 ;
}
}
F_11 ( V_6 ) ;
V_23 -> V_24 = NULL ;
V_7 [ V_25 ] = ( ( unsigned long ) V_19 - V_13 ) >> V_26 ;
F_12 ( 0 , V_7 ,
( F_4 ( V_13 ) >> V_26 ) + 1 , NULL ) ;
}
