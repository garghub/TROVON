int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 -> V_3 , V_4 ) ;
F_3 ( V_1 -> V_5 , V_4 ) ;
F_4 () ;
F_5 ( V_1 -> V_3 , V_4 , 0 ) ;
F_5 ( V_1 -> V_5 , V_4 , 1 ) ;
F_6 () ;
}
T_1 * F_7 ( void )
{
T_1 * V_6 = NULL ;
T_2 V_7 ;
F_8 ( V_6 , T_1 ) ;
V_6 -> V_3 = NULL ;
V_6 -> V_5 = NULL ;
return ( V_6 ) ;
F_9 ( V_8 ) ;
}
T_1 * F_10 ( T_1 * * V_1 ,
unsigned char * * V_2 , long V_9 )
{
F_11 ( V_1 , T_1 * , F_7 ) ;
F_12 () ;
F_13 () ;
F_14 ( V_6 -> V_3 , V_10 , 0 ,
V_11 ) ;
F_14 ( V_6 -> V_5 , V_10 , 1 ,
V_11 ) ;
F_15 ( V_1 , V_12 , V_13 ) ;
}
void V_12 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_16 ( V_1 -> V_3 ) ;
F_16 ( V_1 -> V_5 ) ;
F_17 ( V_1 ) ;
}
static int F_18 ( T_3 * V_14 ,
T_1 * V_15 , T_4 * V_16 , int V_17 )
{
F_19 ( V_16 , L_1 , V_17 , L_2 ) ;
if( V_15 -> V_3 ) {
F_20 ( V_16 , L_3 , 12 ) ;
F_21 ( V_16 , V_15 -> V_3 ) ;
if( V_15 -> V_5 ) F_20 ( V_16 , L_4 , 2 ) ;
}
if( V_15 -> V_5 ) {
F_20 ( V_16 , L_5 , 11 ) ;
F_21 ( V_16 , V_15 -> V_5 ) ;
}
return 1 ;
}
