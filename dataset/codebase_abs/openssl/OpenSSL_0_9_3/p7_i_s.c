int F_1 ( T_1 * V_1 ,
unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 -> V_3 , V_4 ) ;
F_3 ( V_1 -> V_5 , V_6 ) ;
F_4 () ;
F_5 ( V_1 -> V_3 , V_4 ) ;
F_5 ( V_1 -> V_5 , V_6 ) ;
F_6 () ;
}
T_1 * F_7 ( T_1 * * V_1 , unsigned char * * V_2 , long V_7 )
{
F_8 ( V_1 , T_1 * , V_8 ) ;
F_9 () ;
F_10 () ;
F_11 ( V_9 -> V_3 , V_10 ) ;
F_11 ( V_9 -> V_5 , V_11 ) ;
F_12 ( V_1 , V_12 ,
V_13 ) ;
}
T_1 * V_8 ( void )
{
T_1 * V_9 = NULL ;
T_2 V_14 ;
F_13 ( V_9 , T_1 ) ;
F_14 ( V_9 -> V_3 , V_15 ) ;
F_14 ( V_9 -> V_5 , V_16 ) ;
return ( V_9 ) ;
F_15 ( V_17 ) ;
}
void V_12 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_16 ( V_1 -> V_3 ) ;
F_17 ( V_1 -> V_5 ) ;
Free ( ( char * ) V_1 ) ;
}
