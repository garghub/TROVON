static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( V_2 , L_1 , V_4 ) ;
V_3 = F_3 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_4 ( V_2 ) ;
if ( V_3 ) {
F_5 ( V_2 ) ;
return V_3 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_2 ( V_2 , L_1 , V_4 ) ;
F_7 ( V_2 ) ;
return F_5 ( V_2 ) ;
}
static int T_1 F_8 ( void )
{
F_9 ( & V_5 , & V_6 ) ;
return 0 ;
}
