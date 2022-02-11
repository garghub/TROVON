static int T_1 F_1 ( void )
{
int V_1 ;
struct V_2 V_3 ;
#ifdef F_2
T_2 V_4 ;
V_1 = F_3 ( L_1 ) ;
if ( V_1 == - V_5 )
return 0 ;
if ( V_1 ) {
V_4 = F_4 () ;
if ( V_4 != 0xd2638722 )
return 0 ;
}
#endif
V_3 . V_6 = 480 ;
V_3 . V_7 = 800 ;
V_3 . type = V_8 ;
V_3 . V_9 = V_10 ;
V_3 . V_11 . V_12 = V_13 ;
V_3 . V_14 = 0 ;
V_3 . V_15 = 18 ;
V_3 . V_16 . V_17 = FALSE ;
V_3 . V_18 = 15 ;
V_3 . V_19 = 1 ;
V_3 . V_20 = 192000000 ;
V_3 . V_21 = 190000000 ;
V_3 . V_22 = 200000000 ;
V_3 . V_23 = 2 ;
V_1 = F_5 ( & V_3 , V_24 ,
V_25 ) ;
if ( V_1 )
F_6 ( V_26 L_2 , V_27 ) ;
return V_1 ;
}
