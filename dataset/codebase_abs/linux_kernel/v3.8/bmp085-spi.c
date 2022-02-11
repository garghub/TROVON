static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_4 ;
V_2 -> V_5 = 8 ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 < 0 ) {
F_3 ( & V_2 -> V_6 , L_1 ) ;
return V_3 ;
}
V_4 = F_4 ( V_2 , & V_7 ) ;
if ( F_5 ( V_4 ) ) {
V_3 = F_6 ( V_4 ) ;
F_3 ( & V_2 -> V_6 , L_2 , V_3 ) ;
return V_3 ;
}
return F_7 ( & V_2 -> V_6 , V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_9 ( & V_2 -> V_6 ) ;
}
