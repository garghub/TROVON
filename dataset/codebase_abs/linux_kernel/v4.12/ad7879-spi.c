static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 ;
if ( V_2 -> V_4 > V_5 ) {
F_2 ( & V_2 -> V_6 , L_1 , V_2 -> V_4 ) ;
return - V_7 ;
}
V_3 = F_3 ( V_2 , & V_8 ) ;
if ( F_4 ( V_3 ) )
return F_5 ( V_3 ) ;
return F_6 ( & V_2 -> V_6 , V_3 , V_2 -> V_9 , V_10 , V_11 ) ;
}
