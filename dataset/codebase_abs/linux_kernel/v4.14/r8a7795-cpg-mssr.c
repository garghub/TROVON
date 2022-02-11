static int T_1 F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
T_2 V_5 ;
int error ;
error = F_2 ( & V_5 ) ;
if ( error )
return error ;
V_4 = & V_6 [ F_3 ( V_5 ) ] ;
if ( ! V_4 -> V_7 ) {
F_4 ( V_2 , L_1 , V_5 ) ;
return - V_8 ;
}
if ( F_5 ( V_9 ) ) {
F_6 ( V_10 ,
F_7 ( V_10 ) ,
V_11 , V_12 ) ;
F_8 ( V_13 ,
F_7 ( V_13 ) ,
V_14 ,
F_7 ( V_14 ) ) ;
F_9 ( V_13 ,
F_7 ( V_13 ) ,
V_15 ,
F_7 ( V_15 ) ) ;
} else {
F_8 ( V_13 ,
F_7 ( V_13 ) ,
V_16 ,
F_7 ( V_16 ) ) ;
}
return F_10 ( V_4 , V_17 , V_5 ) ;
}
