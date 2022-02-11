int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 = & V_2 -> V_10 ;
T_1 V_11 ;
int V_12 ;
if ( ! F_2 ( V_4 , L_1 ) )
return 0 ;
V_8 = F_3 ( V_4 , L_2 ) ;
if ( F_4 ( V_8 ) ) {
F_5 ( V_10 , L_3 ) ;
return F_6 ( V_8 ) ;
}
V_12 = F_7 ( V_8 , V_13 , & V_11 ) ;
if ( V_12 ) {
F_5 ( V_10 , L_4 ) ;
return - V_14 ;
}
F_8 ( V_10 , L_5 , V_11 ) ;
if ( ( V_11 & V_15 ) != V_16 ) {
F_5 ( V_10 , L_6 ) ;
return - V_14 ;
}
if ( V_11 & V_17 ) {
if ( V_6 -> V_18 != 2 )
F_9 ( V_10 , L_7 ,
V_6 -> V_18 * 8 ) ;
} else {
if ( V_6 -> V_18 != 1 )
F_9 ( V_10 , L_8 ,
V_6 -> V_18 * 8 ) ;
}
F_10 ( & V_2 -> V_10 , L_9 ) ;
return 0 ;
}
