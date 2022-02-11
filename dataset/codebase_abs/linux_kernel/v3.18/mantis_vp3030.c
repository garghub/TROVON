static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
int V_10 = 0 ;
F_2 ( V_2 , V_8 -> V_11 , 0 ) ;
F_3 ( 100 ) ;
V_10 = F_4 ( V_2 , V_12 ) ;
F_3 ( 100 ) ;
F_2 ( V_2 , V_8 -> V_11 , 1 ) ;
if ( V_10 == 0 ) {
F_3 ( 250 ) ;
F_5 ( V_13 , 1 , L_1 ) ;
V_4 = F_6 ( V_14 , & V_15 , V_6 ) ;
if ( ! V_4 )
return - 1 ;
F_6 ( V_16 , V_4 , & V_17 , V_6 ) ;
} else {
F_5 ( V_13 , 1 , L_2 ,
V_6 -> V_18 ,
V_10 ) ;
return - V_19 ;
}
V_2 -> V_4 = V_4 ;
F_5 ( V_13 , 1 , L_3 ) ;
return 0 ;
}
