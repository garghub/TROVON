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
V_10 = F_2 ( V_11 ) ;
V_4 = V_12 ;
V_1 = V_13 ;
memset ( V_13 , 0 , sizeof ( V_13 ) ) ;
memset ( V_14 , 0 , sizeof ( V_14 ) ) ;
V_9 = V_15 * sizeof( T_3 ) ;
V_9 = ( V_9 + V_11 ) & ~ ( V_11 - 1 ) ;
V_5 = ( unsigned long ) F_2 ( V_9 ) ;
V_6 = ( V_5 + V_9 + V_11 ) & V_16 ;
V_1 += V_12 >> V_17 ;
while ( V_4 < ( unsigned long ) V_18 ) {
V_2 = ( T_3 * ) F_3 ( V_5 ) ;
V_5 += V_19 * sizeof ( T_3 ) ;
F_4 ( * V_1 ) = ( unsigned long ) V_2 ;
V_1 ++ ;
V_2 = ( T_3 * ) F_5 ( ( unsigned long ) V_2 ) ;
for ( V_3 = 0 ; V_3 < V_19 ; ++ V_3 , ++ V_2 ) {
T_3 V_20 = F_6 ( F_7 ( V_4 ) , V_21 ) ;
if ( V_4 >= ( unsigned long ) V_18 )
F_8 ( V_20 ) = 0 ;
F_9 ( V_2 , V_20 ) ;
V_4 += V_11 ;
}
}
F_10 ( V_6 ) ;
V_22 -> V_23 = NULL ;
V_7 [ V_24 ] = ( ( unsigned long ) V_18 - V_12 ) >> V_25 ;
F_11 ( 0 , V_7 ,
( F_3 ( V_12 ) >> V_25 ) + 1 , NULL ) ;
}
