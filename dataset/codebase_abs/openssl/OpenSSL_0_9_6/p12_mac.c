int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 -> V_3 , V_4 ) ;
F_3 ( V_1 -> V_5 , V_6 ) ;
F_3 ( V_1 -> V_7 , V_8 ) ;
F_4 () ;
F_5 ( V_1 -> V_3 , V_4 ) ;
F_5 ( V_1 -> V_5 , V_6 ) ;
F_5 ( V_1 -> V_7 , V_8 ) ;
F_6 () ;
}
T_1 * F_7 ( void )
{
T_1 * V_9 = NULL ;
T_2 V_10 ;
F_8 ( V_9 , T_1 ) ;
V_9 -> V_3 = F_9 () ;
V_9 -> V_5 = F_10 () ;
V_9 -> V_7 = NULL ;
return ( V_9 ) ;
F_11 ( V_11 ) ;
}
T_1 * F_12 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_12 )
{
F_13 ( V_1 , T_1 * , F_7 ) ;
F_14 () ;
F_15 () ;
F_16 ( V_9 -> V_3 , V_13 ) ;
F_16 ( V_9 -> V_5 , V_14 ) ;
F_17 ( V_9 -> V_7 , V_15 , V_16 ) ;
F_18 ( V_1 , V_17 , V_18 ) ;
}
void V_17 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_19 ( V_1 -> V_3 ) ;
F_20 ( V_1 -> V_5 ) ;
F_21 ( V_1 -> V_7 ) ;
F_22 ( V_1 ) ;
}
