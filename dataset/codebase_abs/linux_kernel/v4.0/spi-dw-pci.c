static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = (struct V_9 * ) V_4 -> V_11 ;
int V_12 = 0 ;
int V_13 ;
V_13 = F_2 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_6 = F_3 ( & V_2 -> V_14 , sizeof( struct V_5 ) ,
V_15 ) ;
if ( ! V_6 )
return - V_16 ;
V_6 -> V_2 = V_2 ;
V_8 = & V_6 -> V_8 ;
V_8 -> V_17 = F_4 ( V_2 , V_12 ) ;
V_13 = F_5 ( V_2 , 1 << V_12 , F_6 ( V_2 ) ) ;
if ( V_13 )
return V_13 ;
V_8 -> V_18 = F_7 ( V_2 ) [ V_12 ] ;
V_8 -> V_19 = V_2 -> V_19 ;
if ( V_10 ) {
V_8 -> V_20 = V_10 -> V_20 ;
V_8 -> V_21 = V_10 -> V_21 ;
if ( V_10 -> V_22 ) {
V_13 = V_10 -> V_22 ( V_8 ) ;
if ( V_13 )
return V_13 ;
}
} else {
return - V_23 ;
}
V_13 = F_8 ( & V_2 -> V_14 , V_8 ) ;
if ( V_13 )
return V_13 ;
F_9 ( V_2 , V_6 ) ;
F_10 ( & V_2 -> V_14 , L_1 ,
V_2 -> V_24 , V_2 -> V_25 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_12 ( V_2 ) ;
F_13 ( & V_6 -> V_8 ) ;
}
static int F_14 ( struct V_25 * V_14 )
{
struct V_1 * V_2 = F_15 ( V_14 ) ;
struct V_5 * V_6 = F_12 ( V_2 ) ;
return F_16 ( & V_6 -> V_8 ) ;
}
static int F_17 ( struct V_25 * V_14 )
{
struct V_1 * V_2 = F_15 ( V_14 ) ;
struct V_5 * V_6 = F_12 ( V_2 ) ;
return F_18 ( & V_6 -> V_8 ) ;
}
