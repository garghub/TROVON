void T_1 F_1 ( void )
{
V_1 . V_2 . V_3 = V_4 ;
V_1 . V_2 . V_5 = 1 ;
V_1 . V_2 . V_6 = 0 ;
V_1 . V_2 . V_7 . V_8 = 1 ;
switch ( V_9 . V_10 . V_11 ) {
case V_12 :
V_1 . V_2 . V_6 = 1 ;
break;
case V_13 :
V_1 . V_2 . V_7 . V_8 = 0 ;
V_1 . V_2 . V_5 = 0 ;
break;
case V_14 :
case V_15 :
V_1 . V_2 . V_7 . V_8 = 0 ;
V_1 . V_2 . V_5 = 0 ;
V_1 . V_2 . V_3 = V_16 ;
break;
}
if ( V_1 . V_17 )
V_1 . V_17 () ;
}
bool T_1 F_2 ( void )
{
return V_1 . V_2 . V_7 . V_8 == 0 ;
}
