static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
const struct V_4 * V_5 = F_2 ( V_2 ) ;
V_3 = F_3 ( V_2 , & V_6 ) ;
if ( F_4 ( V_3 ) ) {
F_5 ( & V_2 -> V_7 , L_1 ) ;
return F_6 ( V_3 ) ;
}
return F_7 ( & V_2 -> V_7 , V_3 , V_2 -> V_8 , V_5 -> V_9 ,
true ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_9 ( & V_2 -> V_7 ) ;
}
