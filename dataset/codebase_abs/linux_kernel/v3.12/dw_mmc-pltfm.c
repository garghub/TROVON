static void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
* V_3 |= V_4 ;
}
int F_2 ( struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
struct V_1 * V_2 ;
struct V_9 * V_10 ;
int V_11 ;
V_2 = F_3 ( & V_6 -> V_12 , sizeof( struct V_1 ) , V_13 ) ;
if ( ! V_2 )
return - V_14 ;
V_2 -> V_15 = F_4 ( V_6 , 0 ) ;
if ( V_2 -> V_15 < 0 )
return V_2 -> V_15 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_12 = & V_6 -> V_12 ;
V_2 -> V_16 = 0 ;
V_2 -> V_17 = V_6 -> V_12 . V_18 ;
V_10 = F_5 ( V_6 , V_19 , 0 ) ;
V_2 -> V_10 = F_6 ( & V_6 -> V_12 , V_10 ) ;
if ( F_7 ( V_2 -> V_10 ) )
return F_8 ( V_2 -> V_10 ) ;
if ( V_8 && V_8 -> V_20 ) {
V_11 = V_8 -> V_20 ( V_2 ) ;
if ( V_11 )
return V_11 ;
}
F_9 ( V_6 , V_2 ) ;
return F_10 ( V_2 ) ;
}
static int F_11 ( struct V_21 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
return F_13 ( V_2 ) ;
}
static int F_14 ( struct V_21 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
return F_15 ( V_2 ) ;
}
static int F_16 ( struct V_5 * V_6 )
{
const struct V_7 * V_8 = NULL ;
const struct V_22 * V_23 ;
if ( V_6 -> V_12 . V_24 ) {
V_23 = F_17 ( V_25 , V_6 -> V_12 . V_24 ) ;
V_8 = V_23 -> V_26 ;
}
return F_2 ( V_6 , V_8 ) ;
}
int F_18 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_19 ( V_6 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
