static void * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( & V_2 -> V_5 , sizeof( * V_4 ) , V_6 ) ;
if ( ! V_4 )
return F_3 ( - V_7 ) ;
V_4 -> V_8 = F_4 ( V_2 -> V_5 . V_9 ) ;
if ( V_4 -> V_8 < 0 )
return F_3 ( V_4 -> V_8 ) ;
V_4 -> V_10 = F_5 ( L_1 ) ;
if ( F_6 ( V_4 -> V_10 ) ) {
F_7 ( & V_2 -> V_5 , L_2 ) ;
return V_4 -> V_10 ;
}
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 , void * V_11 )
{
struct V_3 * V_4 = V_11 ;
T_1 V_12 ;
if ( V_4 -> V_8 == V_13 ) {
V_12 = V_14 ;
} else if ( V_4 -> V_8 == V_15 ) {
V_12 = V_16 ;
} else {
F_7 ( & V_2 -> V_5 , L_3 ) ;
return - V_17 ;
}
F_9 ( V_4 -> V_10 , V_18 ,
V_19 , V_12 ) ;
return 0 ;
}
