static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
int V_6 ;
V_5 = F_2 ( V_2 , & V_7 ) ;
if ( F_3 ( V_5 ) ) {
V_6 = F_4 ( V_5 ) ;
F_5 ( & V_2 -> V_8 , L_1 , V_6 ) ;
return V_6 ;
}
return F_6 ( & V_2 -> V_8 , V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_8 ( & V_2 -> V_8 ) ;
}
