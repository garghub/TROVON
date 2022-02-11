static int T_1 F_1 ( void )
{
F_2 ( V_1 L_1 ) ;
if ( F_3 () )
V_2 . V_3 = & V_4 ;
else
V_2 . V_3 = & V_5 ;
F_4 ( & V_2 ) ;
return 0 ;
}
int T_1 F_5 ( const struct V_6 * V_7 , T_2 V_8 , T_2 V_9 )
{
switch ( V_8 ) {
case 1 :
case 2 :
case 3 :
return V_10 + ( ( ( V_8 - 1 ) + ( V_9 - 1 ) ) % 4 ) ;
case 4 :
return V_11 ;
case 5 :
return V_12 ;
case 6 :
return V_13 ;
default:
return 0xff ;
}
return - 1 ;
}
int F_6 ( struct V_6 * V_7 )
{
return 0 ;
}
