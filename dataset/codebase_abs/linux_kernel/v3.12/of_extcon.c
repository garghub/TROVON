struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
if ( ! V_3 -> V_10 ) {
F_2 ( V_3 , L_1 ) ;
return F_3 ( - V_11 ) ;
}
V_6 = F_4 ( V_3 -> V_10 , L_2 , V_4 ) ;
if ( ! V_6 ) {
F_2 ( V_3 , L_3 ,
V_3 -> V_10 -> V_12 ) ;
return F_3 ( - V_13 ) ;
}
V_9 = F_5 ( V_6 ) ;
if ( ! V_9 ) {
F_2 ( V_3 , L_4 ) ;
return F_3 ( - V_14 ) ;
}
V_7 = F_6 ( F_7 ( & V_9 -> V_3 ) ) ;
if ( ! V_7 ) {
F_2 ( V_3 , L_5 ,
F_7 ( & V_9 -> V_3 ) ) ;
return F_3 ( - V_13 ) ;
}
return V_7 ;
}
