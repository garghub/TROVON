int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
int V_3 = 0 ;
F_2 ( V_1 ) ;
F_3 ( V_1 -> type , V_4 ) ;
F_4 ( V_5 , V_1 -> V_6 , V_7 , 0 ,
V_8 , V_3 ) ;
F_5 () ;
F_6 ( V_1 -> type , V_4 ) ;
F_7 ( V_5 , V_1 -> V_6 , V_7 , 0 ,
V_8 , V_3 ) ;
F_8 () ;
}
T_1 * F_9 ( void )
{
T_1 * V_9 = NULL ;
T_2 V_10 ;
F_10 ( V_9 , T_1 ) ;
V_9 -> type = F_11 ( V_11 ) ;
V_9 -> V_6 = NULL ;
return ( V_9 ) ;
F_12 ( V_12 ) ;
}
T_1 * F_13 ( T_1 * * V_1 ,
unsigned char * * V_2 , long V_13 )
{
F_14 ( V_1 , T_1 * ,
F_9 ) ;
F_15 () ;
F_16 () ;
F_17 ( V_9 -> type , V_14 ) ;
F_18 ( V_5 , V_9 -> V_6 , V_15 , V_16 , 0 ,
V_8 ) ;
F_19 ( V_1 , V_17 ,
V_18 ) ;
}
void V_17 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_20 ( V_1 -> type ) ;
if( V_1 -> V_6 )
F_21 ( V_1 -> V_6 , V_16 ) ;
F_22 ( V_1 ) ;
}
