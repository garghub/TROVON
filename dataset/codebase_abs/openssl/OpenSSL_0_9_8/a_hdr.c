int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 -> V_3 , V_4 ) ;
F_3 ( V_1 -> V_5 , V_1 -> V_6 -> V_7 ) ;
F_4 () ;
F_5 ( V_1 -> V_3 , V_4 ) ;
F_5 ( V_1 -> V_5 , V_1 -> V_6 -> V_7 ) ;
F_6 () ;
}
T_1 * F_7 ( T_1 * * V_1 , const unsigned char * * V_2 ,
long V_8 )
{
F_8 ( V_1 , T_1 * , V_9 ) ;
F_9 () ;
F_10 () ;
F_11 ( V_10 , V_11 -> V_3 , V_12 ) ;
if ( V_11 -> V_6 != NULL )
{
F_11 ( void , V_11 -> V_5 , V_11 -> V_6 -> V_13 ) ;
}
else
{
if ( V_1 != NULL ) ( * V_1 ) = V_11 ;
return ( V_11 ) ;
}
F_12 ( V_1 , V_14 , V_15 ) ;
}
T_1 * V_9 ( void )
{
T_1 * V_11 = NULL ;
T_2 V_16 ;
F_13 ( V_11 , T_1 ) ;
F_14 ( V_11 -> V_3 , V_17 ) ;
V_11 -> V_6 = NULL ;
V_11 -> V_5 = NULL ;
return ( V_11 ) ;
F_15 ( V_18 ) ;
}
void V_14 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_16 ( V_1 -> V_3 ) ;
if ( V_1 -> V_6 != NULL )
V_1 -> V_6 -> V_19 ( V_1 -> V_5 ) ;
F_17 ( V_1 ) ;
}
