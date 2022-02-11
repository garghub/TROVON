T_1 * F_1 ( void )
{
T_1 * V_1 = NULL ;
T_2 V_2 ;
F_2 ( V_1 , T_1 ) ;
V_1 -> V_3 = F_3 ( V_4 ) ;
V_1 -> V_5 = NULL ;
return ( V_1 ) ;
F_4 ( V_6 ) ;
}
T_1 * F_5 ( T_1 * * V_7 , unsigned char * * V_8 ,
long V_9 )
{
F_6 ( V_7 , T_1 * , F_1 ) ;
F_7 () ;
F_8 () ;
F_9 ( V_1 -> V_3 , V_10 ) ;
F_9 ( V_1 -> V_5 , V_11 ) ;
F_10 ( V_7 , V_12 , V_13 ) ;
}
void V_12 ( T_1 * V_7 )
{
if ( V_7 == NULL ) return;
F_11 ( V_7 -> V_3 ) ;
F_12 ( V_7 -> V_5 ) ;
Free ( V_7 ) ;
}
