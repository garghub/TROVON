static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 = V_5 | V_6 | V_3 ;
T_2 V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
V_7 = F_3 ( V_9 , V_4 ) ;
if ( V_7 < 0 ) {
F_4 ( V_2 , L_1 ,
V_10 , V_3 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_5 ( struct V_8 * V_9 ,
const struct V_11 * V_12 )
{
return F_6 ( & V_9 -> V_2 , V_9 -> V_13 , V_14 ,
F_7 ( V_9 , & V_15 ) ,
F_1 ) ;
}
static int F_8 ( struct V_8 * V_9 )
{
return F_9 ( & V_9 -> V_2 ) ;
}
