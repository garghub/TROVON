int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
if( V_1 -> V_3 ) F_3 ( V_1 -> V_3 , V_4 ) ;
F_3 ( V_1 -> V_5 , V_6 ) ;
F_4 () ;
if ( V_1 -> V_3 ) F_5 ( V_1 -> V_3 , V_4 ) ;
F_5 ( V_1 -> V_5 , V_6 ) ;
F_6 () ;
}
T_1 * F_7 ( void )
{
T_1 * V_7 = NULL ;
T_2 V_8 ;
F_8 ( V_7 , T_1 ) ;
V_7 -> V_3 = 0 ;
V_7 -> V_5 = NULL ;
return ( V_7 ) ;
F_9 ( V_9 ) ;
}
T_1 * F_10 ( T_1 * * V_1 ,
unsigned char * * V_2 , long V_10 )
{
F_11 ( V_1 , T_1 * , F_7 ) ;
F_12 () ;
F_13 () ;
if( ( V_11 & ( ~ V_12 ) ) ==
( V_13 | V_14 ) ) {
F_14 ( V_7 -> V_3 , V_15 ) ;
}
F_15 ( V_7 -> V_5 , V_16 , V_17 ) ;
F_16 ( V_1 , V_18 , V_19 ) ;
}
void V_18 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_17 ( V_1 -> V_5 ) ;
F_18 ( V_1 ) ;
}
