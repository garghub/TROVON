static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( ! F_2 ( V_2 -> V_7 , V_8 ) ) {
F_3 ( & V_2 -> V_9 , L_1 ) ;
return - V_10 ;
}
V_6 = F_4 ( & V_11 , & V_2 -> V_9 , V_2 -> V_12 ,
V_13 ) ;
if ( F_5 ( V_6 ) )
return F_6 ( V_6 ) ;
F_7 ( V_2 , V_6 ) ;
return 0 ;
}
