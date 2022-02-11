static struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 =
F_1 ( V_3 ) ;
if ( V_4 -> V_5 )
return V_4 -> V_5 -> V_6 -> V_7 ( V_4 -> V_5 ) ;
return 0 ;
}
static enum V_8
F_4 ( struct V_2 * V_3 , bool V_9 )
{
struct V_1 * V_4 =
F_1 ( V_3 ) ;
if ( V_4 -> V_5 )
return V_10 ;
return V_11 ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_4 =
F_1 ( V_3 ) ;
if ( V_4 -> V_5 )
F_6 ( V_4 -> V_5 ) ;
F_7 ( V_3 ) ;
F_8 ( V_3 ) ;
}
static int F_9 ( struct V_12 * V_13 ,
const struct V_14 * V_15 )
{
struct V_1 * V_4 = V_13 -> V_16 ;
struct V_17 * V_18 ;
struct V_19 * V_5 ;
int V_20 = - V_21 ;
V_18 = F_10 ( V_15 -> V_22 ) ;
V_5 = F_11 ( V_18 ) ;
F_12 ( V_18 ) ;
if ( ! V_5 )
return - V_21 ;
V_4 -> V_3 . V_23 = V_24 ;
V_4 -> V_3 . V_25 = 0 ;
F_13 ( & V_4 -> V_3 ,
& V_26 ) ;
V_20 = F_14 ( V_13 , & V_4 -> V_3 ,
& V_27 ,
V_28 ) ;
if ( ! V_20 )
V_4 -> V_5 = V_5 ;
return V_20 ;
}
int F_15 ( struct V_12 * V_13 )
{
struct V_17 * V_29 = NULL ;
struct V_14 V_15 ;
int V_20 ;
F_16 (drm->dev->of_node, ep_np) {
V_20 = F_17 ( V_29 , & V_15 ) ;
if ( ! V_20 )
V_20 = F_9 ( V_13 , & V_15 ) ;
if ( V_20 ) {
F_12 ( V_29 ) ;
return V_20 ;
}
}
return 0 ;
}
