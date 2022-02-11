int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 -> V_3 , V_4 ) ;
F_3 ( V_1 -> V_5 , V_6 ) ;
F_3 ( V_1 -> V_7 , V_8 ) ;
F_4 () ;
F_5 ( V_1 -> V_3 , V_4 , 0 ) ;
F_5 ( V_1 -> V_5 , V_6 , 1 ) ;
F_5 ( V_1 -> V_7 , V_8 , 2 ) ;
F_6 () ;
}
T_1 * F_7 ( void )
{
T_1 * V_9 = NULL ;
T_2 V_10 ;
F_8 ( V_9 , T_1 ) ;
V_9 -> V_3 = NULL ;
V_9 -> V_5 = NULL ;
V_9 -> V_7 = NULL ;
return ( V_9 ) ;
F_9 ( V_11 ) ;
}
T_1 * F_10 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_12 )
{
F_11 ( V_1 , T_1 * , F_7 ) ;
F_12 () ;
F_13 () ;
F_14 ( V_9 -> V_3 , V_13 , 0 ,
V_14 ) ;
F_14 ( V_9 -> V_5 , V_15 , 1 ,
V_16 ) ;
F_14 ( V_9 -> V_7 , V_17 , 2 ,
V_18 ) ;
F_15 ( V_1 , V_19 , V_20 ) ;
}
void V_19 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_16 ( V_1 -> V_3 ) ;
F_17 ( V_1 -> V_5 , V_21 ) ;
F_18 ( V_1 -> V_7 ) ;
Free ( V_1 ) ;
}
