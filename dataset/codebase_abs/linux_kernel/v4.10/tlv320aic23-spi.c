static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_4 ;
F_2 ( & V_2 -> V_5 , L_1 ) ;
V_2 -> V_6 = V_7 ;
V_3 = F_3 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
V_4 = F_4 ( V_2 , & V_8 ) ;
return F_5 ( & V_2 -> V_5 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_5 ) ;
return 0 ;
}
