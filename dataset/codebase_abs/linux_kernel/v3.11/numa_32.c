void F_1 ( int V_1 , unsigned long V_2 , unsigned long V_3 )
{
unsigned long V_4 ;
F_2 ( V_5 L_1 ,
V_1 , V_2 , V_3 ) ;
F_2 ( V_6 L_2 , V_1 ) ;
F_2 ( V_6 L_3 ) ;
for ( V_4 = V_2 ; V_4 < V_3 ; V_4 += V_7 ) {
V_8 [ V_4 / V_7 ] = V_1 ;
F_2 ( V_9 L_4 , V_4 ) ;
}
F_2 ( V_9 L_5 ) ;
}
unsigned long F_3 ( int V_1 , unsigned long V_10 ,
unsigned long V_11 )
{
unsigned long V_12 = V_11 - V_10 ;
if ( ! V_12 )
return 0 ;
return ( V_12 + 1 ) * sizeof( struct V_13 ) ;
}
void T_1 F_4 ( void )
{
F_5 () ;
#ifdef F_6
V_14 = V_15 = V_16 ;
if ( V_16 > V_17 )
V_14 = V_17 ;
F_2 ( V_18 L_6 ,
F_7 ( V_15 - V_14 ) ) ;
V_19 = ( void * ) F_8 ( V_14 * V_20 - 1 ) + 1 ;
#else
V_19 = ( void * ) F_8 ( V_17 * V_20 - 1 ) + 1 ;
#endif
F_2 ( V_18 L_7 ,
F_7 ( V_17 ) ) ;
F_2 ( V_6 L_8 ,
V_17 , V_14 ) ;
F_2 ( V_6 L_9 ,
( V_21 ) F_9 ( V_17 ) ) ;
F_2 ( V_6 L_10 ,
( V_21 ) F_9 ( V_14 ) ) ;
F_10 () ;
}
