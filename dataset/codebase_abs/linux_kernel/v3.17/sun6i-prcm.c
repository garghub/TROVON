static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
const struct V_7 * V_8 ;
const struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
V_8 = F_2 ( V_14 , V_4 ) ;
if ( ! V_8 )
return - V_15 ;
V_10 = V_8 -> V_10 ;
V_12 = F_3 ( V_2 , V_16 , 0 ) ;
if ( ! V_12 ) {
F_4 ( & V_2 -> V_5 , L_1 ) ;
return - V_17 ;
}
V_13 = F_5 ( & V_2 -> V_5 , 0 , V_10 -> V_18 , V_10 -> V_19 ,
V_12 , - 1 , NULL ) ;
if ( V_13 ) {
F_4 ( & V_2 -> V_5 , L_2 ) ;
return V_13 ;
}
return 0 ;
}
