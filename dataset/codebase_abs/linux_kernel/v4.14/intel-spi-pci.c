static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
T_1 V_9 ;
int V_10 ;
V_10 = F_2 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_6 = F_3 ( & V_2 -> V_11 , ( void * ) V_4 -> V_12 , sizeof( * V_6 ) ,
V_13 ) ;
if ( ! V_6 )
return - V_14 ;
F_4 ( V_2 , V_15 , & V_9 ) ;
if ( ! ( V_9 & V_16 ) ) {
V_9 |= V_16 ;
F_5 ( V_2 , V_15 , V_9 ) ;
F_4 ( V_2 , V_15 , & V_9 ) ;
}
V_6 -> V_17 = ! ! ( V_9 & V_16 ) ;
V_8 = F_6 ( & V_2 -> V_11 , & V_2 -> V_18 [ 0 ] , V_6 ) ;
if ( F_7 ( V_8 ) )
return F_8 ( V_8 ) ;
F_9 ( V_2 , V_8 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( F_12 ( V_2 ) ) ;
}
