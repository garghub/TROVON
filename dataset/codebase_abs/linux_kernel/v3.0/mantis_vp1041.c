static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_2 ( V_2 , V_8 ) ;
if ( V_7 == 0 ) {
F_3 ( V_2 ) ;
F_4 ( 250 ) ;
V_2 -> V_4 = F_5 ( V_9 , & V_10 , V_6 ) ;
if ( V_2 -> V_4 ) {
F_6 ( V_11 , 1 ,
L_1 ,
V_10 . V_12 ) ;
if ( F_5 ( V_13 , V_2 -> V_4 , & V_14 , V_6 ) ) {
if ( ! F_5 ( V_15 , V_2 -> V_4 , V_6 , 0 , 0 ) )
F_6 ( V_11 , 1 , L_2 ) ;
}
} else {
return - V_16 ;
}
} else {
F_6 ( V_11 , 1 , L_3 ,
V_6 -> V_17 ,
V_7 ) ;
return - V_18 ;
}
F_6 ( V_11 , 1 , L_4 ) ;
return 0 ;
}
