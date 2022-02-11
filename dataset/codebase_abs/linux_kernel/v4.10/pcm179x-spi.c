static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
int V_4 ;
V_3 = F_2 ( V_2 , & V_5 ) ;
if ( F_3 ( V_3 ) ) {
V_4 = F_4 ( V_3 ) ;
F_5 ( & V_2 -> V_6 , L_1 , V_4 ) ;
return V_4 ;
}
return F_6 ( & V_2 -> V_6 , V_3 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_8 ( & V_2 -> V_6 ) ;
}
