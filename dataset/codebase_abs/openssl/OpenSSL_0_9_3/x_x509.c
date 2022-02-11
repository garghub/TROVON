T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
int F_2 ( T_2 * V_2 , unsigned char * * V_3 )
{
F_3 ( V_2 ) ;
F_4 ( V_2 -> V_4 , V_5 ) ;
F_4 ( V_2 -> V_6 , V_7 ) ;
F_4 ( V_2 -> V_8 , V_9 ) ;
F_5 () ;
F_6 ( V_2 -> V_4 , V_5 ) ;
F_6 ( V_2 -> V_6 , V_7 ) ;
F_6 ( V_2 -> V_8 , V_9 ) ;
F_7 () ;
}
T_2 * F_8 ( T_2 * * V_2 , unsigned char * * V_3 , long V_10 )
{
F_9 ( V_2 , T_2 * , V_11 ) ;
F_10 () ;
F_11 () ;
F_12 ( V_12 -> V_4 , V_13 ) ;
F_12 ( V_12 -> V_6 , V_14 ) ;
F_12 ( V_12 -> V_8 , V_15 ) ;
if ( V_12 -> V_16 != NULL ) Free ( V_12 -> V_16 ) ;
V_12 -> V_16 = F_13 ( V_12 -> V_4 -> V_17 , NULL , 0 ) ;
F_14 ( V_2 , V_18 , V_19 ) ;
}
T_2 * V_11 ( void )
{
T_2 * V_12 = NULL ;
T_3 V_20 ;
F_15 ( V_12 , T_2 ) ;
V_12 -> V_21 = 1 ;
V_12 -> V_22 = 0 ;
V_12 -> V_16 = NULL ;
F_16 ( V_12 -> V_4 , V_23 ) ;
F_16 ( V_12 -> V_6 , V_24 ) ;
F_16 ( V_12 -> V_8 , V_25 ) ;
return ( V_12 ) ;
F_17 ( V_26 ) ;
}
void V_18 ( T_2 * V_2 )
{
int V_27 ;
if ( V_2 == NULL ) return;
V_27 = F_18 ( & V_2 -> V_21 , - 1 , V_28 ) ;
#ifdef F_19
F_19 ( L_1 , V_2 ) ;
#endif
if ( V_27 > 0 ) return;
#ifdef F_20
if ( V_27 < 0 )
{
fprintf ( V_29 , L_2 ) ;
abort () ;
}
#endif
F_21 ( V_2 -> V_4 ) ;
F_22 ( V_2 -> V_6 ) ;
F_23 ( V_2 -> V_8 ) ;
if ( V_2 -> V_16 != NULL ) Free ( V_2 -> V_16 ) ;
Free ( ( char * ) V_2 ) ;
}
