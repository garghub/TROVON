static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_5 ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
int V_9 ;
V_5 = F_3 ( & V_2 -> V_8 , sizeof( * V_5 ) , V_10 ) ;
if ( ! V_5 )
return - V_11 ;
F_4 ( & V_2 -> V_8 , V_5 ) ;
V_5 -> V_8 = & V_2 -> V_8 ;
F_5 ( & V_5 -> V_12 ) ;
V_5 -> V_13 = F_6 ( V_2 ,
& V_14 ) ;
if ( F_7 ( V_5 -> V_13 ) ) {
V_9 = F_8 ( V_5 -> V_13 ) ;
F_9 ( V_5 -> V_8 , L_1 ,
V_9 ) ;
F_4 ( & V_2 -> V_8 , NULL ) ;
return V_9 ;
}
if ( V_2 -> V_8 . V_15 ) {
const struct V_16 * V_17 =
F_10 ( V_18 , & V_2 -> V_8 ) ;
V_5 -> V_19 = V_17 -> V_20 ;
} else {
V_5 -> V_19 = ( void * ) V_4 -> V_21 ;
}
V_9 = F_11 ( V_5 , V_7 , V_2 -> V_22 ) ;
return V_9 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_13 ( & V_2 -> V_8 ) ;
F_14 ( V_5 ) ;
return 0 ;
}
static int T_1 F_15 ( void )
{
return F_16 ( & V_23 ) ;
}
static void T_2 F_17 ( void )
{
F_18 ( & V_23 ) ;
}
