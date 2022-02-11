static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
switch ( V_3 ) {
case V_5 :
case V_6 :
return 0 ;
default:
V_4 = F_2 ( V_2 -> V_7 + V_3 ) ;
}
return V_4 ;
}
static T_2 F_3 ( struct V_1 * V_2 , int V_3 )
{
T_2 V_4 ;
switch ( V_3 ) {
case V_8 :
V_4 = F_4 ( V_2 -> V_7 + V_3 ) ;
V_4 &= ~ V_9 ;
break;
default:
V_4 = F_4 ( V_2 -> V_7 + V_3 ) ;
}
return V_4 ;
}
static int T_3 F_5 ( struct V_10 * V_11 )
{
return F_6 ( V_11 , & V_12 ) ;
}
static int T_4 F_7 ( struct V_10 * V_11 )
{
return F_8 ( V_11 ) ;
}
static int T_5 F_9 ( void )
{
return F_10 ( & V_13 ) ;
}
static void T_6 F_11 ( void )
{
F_12 ( & V_13 ) ;
}
