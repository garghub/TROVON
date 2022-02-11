static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
V_5 = F_2 ( V_2 , & V_6 ) ;
if ( F_3 ( V_5 ) )
return F_4 ( V_5 ) ;
return F_5 ( & V_2 -> V_7 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_7 ) ;
return 0 ;
}
