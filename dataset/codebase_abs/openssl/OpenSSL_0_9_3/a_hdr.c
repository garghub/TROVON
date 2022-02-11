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
T_1 * F_7 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_8 )
{
F_8 ( V_1 , T_1 * , V_9 ) ;
F_9 () ;
F_10 () ;
F_11 ( V_10 -> V_3 , V_11 ) ;
if ( V_10 -> V_6 != NULL )
{
F_11 ( V_10 -> V_5 , V_10 -> V_6 -> V_12 ) ;
}
else
{
if ( V_1 != NULL ) ( * V_1 ) = V_10 ;
return ( V_10 ) ;
}
F_12 ( V_1 , V_13 , V_14 ) ;
}
T_1 * V_9 ( void )
{
T_1 * V_10 = NULL ;
T_2 V_15 ;
F_13 ( V_10 , T_1 ) ;
F_14 ( V_10 -> V_3 , V_16 ) ;
V_10 -> V_6 = NULL ;
V_10 -> V_5 = NULL ;
return ( V_10 ) ;
F_15 ( V_17 ) ;
}
void V_13 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_16 ( V_1 -> V_3 ) ;
if ( V_1 -> V_6 != NULL )
V_1 -> V_6 -> V_18 ( V_1 -> V_5 ) ;
Free ( ( char * ) V_1 ) ;
}
