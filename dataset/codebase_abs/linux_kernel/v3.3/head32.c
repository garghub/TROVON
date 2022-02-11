static void T_1 F_1 ( void )
{
V_1 . V_2 . V_3 = V_4 ;
V_1 . V_5 . V_6 = V_7 ;
F_2 () ;
}
void T_1 F_3 ( void )
{
F_4 ( F_5 ( & V_8 ) ,
F_5 ( & V_9 ) - F_5 ( & V_8 ) ) ;
#ifdef F_6
if ( V_10 . V_11 . V_12 && V_10 . V_11 . V_13 ) {
T_2 V_13 = V_10 . V_11 . V_13 ;
T_2 V_14 = V_10 . V_11 . V_14 ;
T_2 V_15 = F_7 ( V_13 + V_14 ) ;
F_4 ( V_13 , V_15 - V_13 ) ;
}
#endif
switch ( V_10 . V_11 . V_16 ) {
case V_17 :
F_8 () ;
break;
case V_18 :
F_9 () ;
break;
default:
F_1 () ;
break;
}
F_10 () ;
}
