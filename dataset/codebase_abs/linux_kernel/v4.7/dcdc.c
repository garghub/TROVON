static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 , V_5 , 0 ) ;
V_6 = F_3 ( & V_2 -> V_7 , V_4 ) ;
if ( F_4 ( V_6 ) )
return F_5 ( V_6 ) ;
F_6 ( & V_2 -> V_7 , L_1 ,
F_7 ( V_8 ) * 8 ) ;
return 0 ;
}
int T_1 F_8 ( void )
{
int V_9 = F_9 ( & V_10 ) ;
if ( V_9 )
F_10 ( L_2 ) ;
return V_9 ;
}
