static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 ;
V_5 = F_3 ( V_2 , & V_6 ) ;
if ( F_4 ( V_5 ) )
return F_5 ( V_5 ) ;
return F_6 ( & V_2 -> V_7 , V_5 , V_4 -> V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_8 ( & V_2 -> V_7 ) ;
}
