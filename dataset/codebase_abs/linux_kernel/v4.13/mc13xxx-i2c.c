static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
int V_6 ;
V_5 = F_2 ( & V_2 -> V_7 , sizeof( * V_5 ) , V_8 ) ;
if ( ! V_5 )
return - V_9 ;
F_3 ( & V_2 -> V_7 , V_5 ) ;
V_5 -> V_10 = V_2 -> V_10 ;
V_5 -> V_11 = F_4 ( V_2 ,
& V_12 ) ;
if ( F_5 ( V_5 -> V_11 ) ) {
V_6 = F_6 ( V_5 -> V_11 ) ;
F_7 ( & V_2 -> V_7 , L_1 , V_6 ) ;
return V_6 ;
}
if ( V_2 -> V_7 . V_13 ) {
const struct V_14 * V_15 =
F_8 ( V_16 , & V_2 -> V_7 ) ;
V_5 -> V_17 = V_15 -> V_18 ;
} else {
V_5 -> V_17 = ( void * ) V_4 -> V_19 ;
}
return F_9 ( & V_2 -> V_7 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_11 ( & V_2 -> V_7 ) ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_20 ) ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_20 ) ;
}
