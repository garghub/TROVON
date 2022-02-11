static int T_1 F_1 ( void )
{
#if F_2 ( V_1 ) || F_2 ( V_2 )
int V_3 ;
V_3 = F_3 ( V_4 , V_5 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_3 ( V_6 , L_1 ) ;
if ( V_3 ) {
F_4 ( V_4 ) ;
return V_3 ;
}
F_5 ( V_4 , 0 ) ;
F_6 ( F_7 () | V_7 ) ;
F_5 ( V_6 , 0 ) ;
F_8 ( 2 ) ;
F_9 ( V_6 , 1 ) ;
#endif
return 0 ;
}
static int T_1 F_10 ( void )
{
F_11 ( V_8 L_2 , V_9 ) ;
F_12 ( V_10 , F_13 ( V_10 ) ) ;
#if F_2 ( V_11 ) || F_2 ( V_12 )
F_14 ( V_13 , F_13 ( V_13 ) ) ;
#endif
#if F_2 ( V_14 ) || F_2 ( V_15 )
F_15 ( V_16 , V_17 ) ;
#endif
if ( F_1 () )
F_16 ( L_3 ) ;
return 0 ;
}
void T_1 F_17 ( void )
{
F_11 ( V_8 L_4 ) ;
F_18 ( V_18 ,
F_13 ( V_18 ) ) ;
}
int F_19 ( char * V_19 )
{
return 1 ;
}
