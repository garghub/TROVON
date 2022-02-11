int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 -> V_3 , V_4 ) ;
F_3 ( V_1 -> V_5 , V_4 ) ;
F_4 () ;
F_5 ( V_1 -> V_3 , V_4 ) ;
F_5 ( V_1 -> V_5 , V_4 ) ;
F_6 () ;
}
T_1 * F_7 ( T_1 * * V_1 , unsigned char * * V_2 , long V_6 )
{
F_8 ( V_1 , T_1 * , V_7 ) ;
F_9 () ;
F_10 () ;
F_11 ( V_8 -> V_3 , V_9 ) ;
F_11 ( V_8 -> V_5 , V_9 ) ;
F_12 ( V_1 , V_10 , V_11 ) ;
}
T_1 * V_7 ( void )
{
T_1 * V_8 = NULL ;
T_2 V_12 ;
F_13 ( V_8 , T_1 ) ;
F_14 ( V_8 -> V_3 , V_13 ) ;
F_14 ( V_8 -> V_5 , V_13 ) ;
return ( V_8 ) ;
F_15 ( V_14 ) ;
}
void V_10 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_16 ( V_1 -> V_3 ) ;
F_16 ( V_1 -> V_5 ) ;
F_17 ( V_1 ) ;
}
