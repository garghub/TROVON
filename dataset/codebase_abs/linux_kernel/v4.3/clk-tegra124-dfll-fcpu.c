static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 , V_5 ;
struct V_6 * V_7 ;
const struct V_8 * V_9 ;
V_3 = V_10 . V_11 ;
V_4 = V_10 . V_12 ;
V_5 = V_10 . V_13 ;
if ( V_4 >= F_2 ( V_14 ) ) {
F_3 ( & V_2 -> V_15 , L_1 ,
V_4 ) ;
return - V_16 ;
}
V_7 = F_4 ( & V_2 -> V_15 , sizeof( * V_7 ) , V_17 ) ;
if ( ! V_7 )
return - V_18 ;
V_7 -> V_15 = F_5 ( 0 ) ;
if ( ! V_7 -> V_15 ) {
F_3 ( & V_2 -> V_15 , L_2 ) ;
return - V_16 ;
}
V_9 = F_6 ( V_19 ,
F_2 ( V_19 ) ,
V_3 , V_4 , V_5 ,
V_14 [ V_4 ] ,
V_7 -> V_15 ) ;
if ( F_7 ( V_9 ) ) {
F_3 ( & V_2 -> V_15 , L_3 ,
F_8 ( V_9 ) ) ;
return F_8 ( V_9 ) ;
}
V_7 -> V_20 = V_9 -> V_20 ;
V_7 -> V_21 = V_9 -> V_22 . V_21 ;
V_7 -> V_23 = V_9 -> V_22 . V_23 ;
V_7 -> V_24 = V_9 -> V_22 . V_24 ;
return F_9 ( V_2 , V_7 ) ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_25 ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( & V_25 ) ;
}
