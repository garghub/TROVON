static int F_1 ( struct V_1 * V_2 , unsigned int V_3 , char * * V_4 )
{
if ( V_3 != 0 ) {
V_2 -> error = L_1 ;
return - V_5 ;
}
V_2 -> V_6 = 1 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_7 * V_7 ,
union V_8 * V_9 )
{
switch( F_3 ( V_7 ) ) {
case V_10 :
F_4 ( V_7 ) ;
break;
case V_11 :
return - V_12 ;
case V_13 :
break;
}
F_5 ( V_7 , 0 ) ;
return V_14 ;
}
static int T_1 F_6 ( void )
{
int V_15 = F_7 ( & V_16 ) ;
if ( V_15 < 0 )
F_8 ( L_2 , V_15 ) ;
return V_15 ;
}
static void T_2 F_9 ( void )
{
F_10 ( & V_16 ) ;
}
