static struct V_1 * * F_1 ( struct V_1 * * V_2 ,
struct V_1 * V_3 )
{
if ( ! F_2 ( V_3 ) -> V_4 &&
F_3 ( V_3 , V_5 ,
V_6 ) ) {
F_2 ( V_3 ) -> V_4 = 1 ;
return NULL ;
}
return F_4 ( V_2 , V_3 ) ;
}
static int F_5 ( struct V_1 * V_3 , int V_7 )
{
const struct V_8 * V_9 = F_6 ( V_3 ) ;
struct V_10 * V_11 = F_7 ( V_3 ) ;
V_11 -> V_12 = ~ F_8 ( V_3 -> V_13 - V_7 , & V_9 -> V_14 ,
& V_9 -> V_15 , 0 ) ;
F_9 ( V_3 ) -> V_16 |= V_17 ;
return F_10 ( V_3 ) ;
}
struct V_1 * F_11 ( struct V_1 * V_3 ,
T_1 V_18 )
{
struct V_10 * V_11 ;
if ( ! F_12 ( V_3 , sizeof( * V_11 ) ) )
return F_13 ( - V_19 ) ;
if ( F_14 ( V_3 -> V_20 != V_21 ) ) {
const struct V_8 * V_22 = F_6 ( V_3 ) ;
struct V_10 * V_11 = F_7 ( V_3 ) ;
V_11 -> V_12 = 0 ;
V_3 -> V_20 = V_21 ;
F_15 ( V_3 , & V_22 -> V_14 , & V_22 -> V_15 ) ;
}
return F_16 ( V_3 , V_18 ) ;
}
int T_2 F_17 ( void )
{
return F_18 ( & V_23 , V_5 ) ;
}
