static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_5 ;
int V_6 ;
V_4 -> V_7 = & V_2 -> V_7 ;
V_6 = F_2 ( V_4 ) ;
if ( V_6 ) {
F_3 ( & V_2 -> V_7 , L_1 , V_6 ) ;
V_4 -> V_7 = NULL ;
return V_6 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
F_6 ( V_4 ) ;
V_4 -> V_7 = NULL ;
return 0 ;
}
