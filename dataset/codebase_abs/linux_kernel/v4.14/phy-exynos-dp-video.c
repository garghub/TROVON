static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
return F_3 ( V_3 -> V_4 , V_3 -> V_5 -> V_6 ,
V_7 , V_7 ) ;
}
static int F_4 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
return F_3 ( V_3 -> V_4 , V_3 -> V_5 -> V_6 ,
V_7 , 0 ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
struct V_10 * V_11 = & V_9 -> V_11 ;
struct V_12 * V_12 ;
struct V_1 * V_1 ;
V_3 = F_6 ( V_11 , sizeof( * V_3 ) , V_13 ) ;
if ( ! V_3 )
return - V_14 ;
V_3 -> V_4 = F_7 ( V_11 -> V_15 ,
L_1 ) ;
if ( F_8 ( V_3 -> V_4 ) ) {
F_9 ( V_11 , L_2 ) ;
return F_10 ( V_3 -> V_4 ) ;
}
V_3 -> V_5 = F_11 ( V_11 ) ;
V_1 = F_12 ( V_11 , NULL , & V_16 ) ;
if ( F_8 ( V_1 ) ) {
F_9 ( V_11 , L_3 ) ;
return F_10 ( V_1 ) ;
}
F_13 ( V_1 , V_3 ) ;
V_12 = F_14 ( V_11 , V_17 ) ;
return F_15 ( V_12 ) ;
}
