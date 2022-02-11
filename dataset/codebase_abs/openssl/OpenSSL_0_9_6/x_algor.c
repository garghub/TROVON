int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 -> V_3 , V_4 ) ;
if ( V_1 -> V_5 != NULL )
{ F_3 ( V_1 -> V_5 , V_6 ) ; }
F_4 () ;
F_5 ( V_1 -> V_3 , V_4 ) ;
if ( V_1 -> V_5 != NULL )
{ F_5 ( V_1 -> V_5 , V_6 ) ; }
F_6 () ;
}
T_1 * F_7 ( T_1 * * V_1 , unsigned char * * V_2 , long V_7 )
{
F_8 ( V_1 , T_1 * , V_8 ) ;
F_9 () ;
F_10 () ;
F_11 ( V_9 -> V_3 , V_10 ) ;
if ( ! F_12 () )
{ F_11 ( V_9 -> V_5 , V_11 ) ; }
else
{
F_13 ( V_9 -> V_5 ) ;
V_9 -> V_5 = NULL ;
}
F_14 ( V_1 , V_12 , V_13 ) ;
}
T_1 * V_8 ( void )
{
T_1 * V_9 = NULL ;
T_2 V_14 ;
F_15 ( V_9 , T_1 ) ;
V_9 -> V_3 = F_16 ( V_15 ) ;
V_9 -> V_5 = NULL ;
return ( V_9 ) ;
F_17 ( V_16 ) ;
}
void V_12 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_18 ( V_1 -> V_3 ) ;
F_13 ( V_1 -> V_5 ) ;
F_19 ( V_1 ) ;
}
