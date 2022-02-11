static int T_1 F_1 ( void )
{
int V_1 ;
struct V_2 V_3 ;
#ifdef F_2
V_1 = F_3 ( L_1 ) ;
if ( V_1 == - V_4 )
return 0 ;
if ( V_1 && ( F_4 () != 0 ) )
return 0 ;
#endif
V_3 . V_5 = 800 ;
V_3 . V_6 = 480 ;
V_3 . type = V_7 ;
V_3 . V_8 = V_9 ;
V_3 . V_10 = 0 ;
V_3 . V_11 = 24 ;
V_3 . V_12 = 2 ;
V_3 . V_13 = 38460000 ;
V_3 . V_14 . V_15 = 21 ;
V_3 . V_14 . V_16 = 81 ;
V_3 . V_14 . V_17 = 60 ;
V_3 . V_14 . V_18 = 18 ;
V_3 . V_14 . V_19 = 27 ;
V_3 . V_14 . V_20 = 2 ;
V_3 . V_14 . V_21 = 0 ;
V_3 . V_14 . V_22 = 0xff ;
V_3 . V_14 . V_23 = 0 ;
V_1 = F_5 ( & V_3 ) ;
if ( V_1 )
F_6 ( V_24 L_2 , V_25 ) ;
return V_1 ;
}
