void T_1 F_1 ( void )
{
V_1 . V_2 . V_3 = 1 ;
V_1 . V_2 . V_4 = 0 ;
V_1 . V_2 . V_5 . V_6 = 1 ;
switch ( V_7 . V_8 . V_9 ) {
case V_10 :
V_1 . V_2 . V_4 = 1 ;
break;
case V_11 :
case V_12 :
case V_13 :
case V_14 :
V_1 . V_2 . V_5 . V_6 = 0 ;
V_1 . V_2 . V_3 = 0 ;
break;
}
if ( V_1 . V_15 )
V_1 . V_15 () ;
}
bool T_1 F_2 ( void )
{
return V_1 . V_2 . V_5 . V_6 == 0 ;
}
