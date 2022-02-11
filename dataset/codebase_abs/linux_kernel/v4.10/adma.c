static int T_1 F_1 ( void )
{
#ifdef F_2
F_3 ( V_1 , V_2 . V_3 ) ;
F_3 ( V_4 , V_2 . V_3 ) ;
#else
F_3 ( V_1 , V_2 . V_3 ) ;
F_3 ( V_4 , V_2 . V_3 ) ;
#endif
#ifdef F_2
F_3 ( V_1 , V_5 . V_3 ) ;
F_3 ( V_4 , V_5 . V_3 ) ;
#else
F_3 ( V_1 , V_5 . V_3 ) ;
F_3 ( V_4 , V_5 . V_3 ) ;
#endif
#ifdef F_2
F_3 ( V_6 , V_7 . V_3 ) ;
F_3 ( V_4 , V_7 . V_3 ) ;
#else
F_3 ( V_6 , V_7 . V_3 ) ;
F_3 ( V_8 , V_7 . V_3 ) ;
F_3 ( V_4 , V_7 . V_3 ) ;
#endif
return 0 ;
}
