static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 = (struct V_7 * ) V_4 -> V_9 ;
int V_10 = 0 ;
int V_11 ;
V_11 = F_2 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_6 = F_3 ( & V_2 -> V_12 , sizeof( * V_6 ) , V_13 ) ;
if ( ! V_6 )
return - V_14 ;
V_6 -> V_15 = F_4 ( V_2 , V_10 ) ;
V_11 = F_5 ( V_2 , 1 << V_10 , F_6 ( V_2 ) ) ;
if ( V_11 )
return V_11 ;
V_6 -> V_16 = F_7 ( V_2 ) [ V_10 ] ;
V_6 -> V_17 = V_2 -> V_17 ;
if ( V_8 ) {
V_6 -> V_18 = V_8 -> V_18 ;
V_6 -> V_19 = V_8 -> V_19 ;
if ( V_8 -> V_20 ) {
V_11 = V_8 -> V_20 ( V_6 ) ;
if ( V_11 )
return V_11 ;
}
} else {
return - V_21 ;
}
V_11 = F_8 ( & V_2 -> V_12 , V_6 ) ;
if ( V_11 )
return V_11 ;
F_9 ( V_2 , V_6 ) ;
F_10 ( & V_2 -> V_12 , L_1 ,
V_2 -> V_22 , V_2 -> V_23 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_12 ( V_2 ) ;
F_13 ( V_6 ) ;
}
static int F_14 ( struct V_23 * V_12 )
{
struct V_1 * V_2 = F_15 ( V_12 ) ;
struct V_5 * V_6 = F_12 ( V_2 ) ;
return F_16 ( V_6 ) ;
}
static int F_17 ( struct V_23 * V_12 )
{
struct V_1 * V_2 = F_15 ( V_12 ) ;
struct V_5 * V_6 = F_12 ( V_2 ) ;
return F_18 ( V_6 ) ;
}
