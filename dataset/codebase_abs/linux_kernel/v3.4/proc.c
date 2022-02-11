int T_1 F_1 ( void )
{
F_2 ( L_1 ) ;
if ( ! F_3 ( L_2 , NULL ) )
goto V_1;
#ifdef F_4
if ( ! F_5 ( L_3 , V_2 | 0444 , NULL ,
& V_3 ) )
goto V_4;
#endif
#ifdef F_6
if ( ! F_5 ( L_4 , V_2 | 0444 , NULL ,
& V_5 ) )
goto V_6;
#endif
#ifdef F_7
if ( ! F_5 ( L_5 , V_2 | 0444 , NULL ,
& V_7 ) )
goto V_8;
#endif
F_8 ( L_6 ) ;
return 0 ;
#ifdef F_7
V_8:
#endif
#ifdef F_6
F_9 ( L_4 , NULL ) ;
V_6:
#endif
#ifdef F_4
F_9 ( L_3 , NULL ) ;
V_4:
#endif
F_9 ( L_2 , NULL ) ;
V_1:
F_8 ( L_7 ) ;
return - V_9 ;
}
void F_10 ( void )
{
#ifdef F_7
F_9 ( L_5 , NULL ) ;
#endif
#ifdef F_6
F_9 ( L_4 , NULL ) ;
#endif
#ifdef F_4
F_9 ( L_3 , NULL ) ;
#endif
F_9 ( L_2 , NULL ) ;
}
