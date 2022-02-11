static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , char * * V_4 )
{
if ( V_3 != 0 ) {
V_2 -> error = L_1 ;
return - V_5 ;
}
V_2 -> V_6 = 1 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_7 * V_7 )
{
switch ( F_3 ( V_7 ) ) {
case V_8 :
if ( V_7 -> V_9 & V_10 ) {
return - V_11 ;
}
F_4 ( V_7 ) ;
break;
case V_12 :
break;
default:
return - V_11 ;
}
F_5 ( V_7 ) ;
return V_13 ;
}
static int T_1 F_6 ( void )
{
int V_14 = F_7 ( & V_15 ) ;
if ( V_14 < 0 )
F_8 ( L_2 , V_14 ) ;
return V_14 ;
}
static void T_2 F_9 ( void )
{
F_10 ( & V_15 ) ;
}
