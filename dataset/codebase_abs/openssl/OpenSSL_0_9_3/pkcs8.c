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
T_1 * F_7 ( T_1 * * V_1 , unsigned char * * V_2 , long V_9 )
{
F_8 ( V_1 , T_1 * , V_10 ) ;
F_9 () ;
F_10 () ;
F_11 ( V_11 -> V_3 , V_12 ) ;
F_11 ( V_11 -> V_5 , V_13 ) ;
F_11 ( V_11 -> V_7 , V_14 ) ;
F_12 ( V_1 , V_15 , V_16 ) ;
}
T_1 * F_13 ( void )
{
T_2 * V_11 = NULL ;
F_14 ( V_11 , T_2 ) ;
V_11 -> V_17 = 1 ;
V_11 -> type = V_18
F_15 ( V_11 -> V_3 , V_19 ) ;
F_15 ( V_11 -> V_5 , V_20 ) ;
F_15 ( V_11 -> V_7 , V_21 ) ;
return ( V_11 ) ;
F_16 ( V_22 ) ;
}
void F_17 ( T_1 * V_1 )
{
int V_23 ;
if ( V_1 == NULL ) return;
V_23 = F_18 ( & V_1 -> V_17 , - 1 , V_24 ) ;
#ifdef F_19
F_19 ( L_1 , V_1 ) ;
#endif
if ( V_23 > 0 ) return;
#ifdef F_20
if ( V_23 < 0 )
{
fprintf ( V_25 , L_2 ) ;
abort () ;
}
#endif
F_21 ( V_1 -> V_3 ) ;
F_22 ( V_1 -> V_5 ) ;
F_23 ( V_1 -> V_7 ) ;
Free ( ( char * ) V_1 ) ;
}
