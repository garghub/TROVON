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
switch( F_3 ( V_7 ) ) {
case V_8 :
F_4 ( V_7 ) ;
break;
case V_9 :
return - V_10 ;
case V_11 :
break;
}
F_5 ( V_7 , 0 ) ;
return V_12 ;
}
static int T_1 F_6 ( void )
{
int V_13 = F_7 ( & V_14 ) ;
if ( V_13 < 0 )
F_8 ( L_2 , V_13 ) ;
return V_13 ;
}
static void T_2 F_9 ( void )
{
F_10 ( & V_14 ) ;
}
