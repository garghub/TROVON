static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
const struct V_5 * V_6 ;
struct V_7 * V_8 = F_2 ( V_2 -> V_9 . V_10 ) ;
struct V_11 * V_11 ;
struct V_12 * V_13 = F_3 ( & V_2 -> V_9 ) ;
int V_14 ;
V_6 = F_4 ( V_15 , & V_2 -> V_9 ) ;
if ( V_6 )
V_8 -> V_16 = ( const struct V_3 * ) V_6 -> V_17 ;
V_11 = F_5 ( sizeof( * V_11 ) , V_18 ) ;
if ( ! V_11 )
return - V_19 ;
F_6 ( & V_2 -> V_9 , V_11 ) ;
V_11 -> V_9 = & V_2 -> V_9 ;
F_7 ( & V_11 -> V_20 ) ;
V_11 -> V_21 = F_8 ( V_2 , & V_22 ) ;
if ( F_9 ( V_11 -> V_21 ) ) {
V_14 = F_10 ( V_11 -> V_21 ) ;
F_11 ( V_11 -> V_9 , L_1 ,
V_14 ) ;
F_6 ( & V_2 -> V_9 , NULL ) ;
F_12 ( V_11 ) ;
return V_14 ;
}
V_14 = F_13 ( V_11 , V_13 , V_2 -> V_23 ) ;
if ( V_14 == 0 && ( V_4 -> V_24 != V_11 -> V_25 ) )
F_14 ( V_11 -> V_9 ,
L_2 ) ;
return V_14 ;
}
static int T_1 F_15 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_16 ( & V_2 -> V_9 ) ;
F_17 ( V_11 ) ;
return 0 ;
}
static int T_2 F_18 ( void )
{
return F_19 ( & V_26 ) ;
}
static void T_3 F_20 ( void )
{
F_21 ( & V_26 ) ;
}
