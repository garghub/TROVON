int
F_1 ( void * V_1 , void * V_2 )
{
F_2 ( V_3 ) ;
F_3 ( V_4 ) ;
V_5 ;
float V_6 ;
#ifdef F_4
F_5 ( L_1 , V_7 , V_1 , V_2 ) ;
#endif
F_6 ( V_3 , V_1 ) ;
#ifdef F_4
F_5 ( L_2 , V_8 , V_9 , V_10 , V_11 , V_12 ) ;
#endif
F_7 ( V_13 , V_14 , 1 , 2 , V_4 , V_3 ) ;
#ifdef F_4
F_5 ( L_3 , V_15 , V_16 , V_17 , V_18 ) ;
#endif
F_8 ( V_13 , 1 , V_4 ) ;
if ( ! V_19 || ! F_9 ( V_19 ) ) {
F_10 ( V_13 , & V_6 , V_4 ) ;
if ( F_11 ( V_2 , & V_6 , sizeof( float ) ) )
return - V_20 ;
}
return V_19 ;
}
