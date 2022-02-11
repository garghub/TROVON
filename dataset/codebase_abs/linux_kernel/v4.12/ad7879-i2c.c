static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
if ( ! F_2 ( V_2 -> V_6 ,
V_7 ) ) {
F_3 ( & V_2 -> V_8 , L_1 ) ;
return - V_9 ;
}
V_5 = F_4 ( V_2 , & V_10 ) ;
if ( F_5 ( V_5 ) )
return F_6 ( V_5 ) ;
return F_7 ( & V_2 -> V_8 , V_5 , V_2 -> V_11 ,
V_12 , V_13 ) ;
}
