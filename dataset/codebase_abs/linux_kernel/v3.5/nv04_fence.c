static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 = F_2 ( V_4 , 2 ) ;
if ( V_6 == 0 ) {
F_3 ( V_4 , V_7 , 0x0150 , 1 ) ;
F_4 ( V_4 , V_2 -> V_8 ) ;
F_5 ( V_4 ) ;
}
return V_6 ;
}
static int
F_6 ( struct V_1 * V_2 ,
struct V_3 * V_9 , struct V_3 * V_4 )
{
return - V_10 ;
}
int
F_7 ( struct V_3 * V_4 , T_1 V_11 , T_1 V_12 , T_1 V_13 )
{
struct V_14 * V_15 = V_4 -> V_16 [ V_17 ] ;
F_8 ( & V_15 -> V_8 , V_13 ) ;
return 0 ;
}
static T_1
F_9 ( struct V_3 * V_4 )
{
struct V_14 * V_15 = V_4 -> V_16 [ V_17 ] ;
return F_10 ( & V_15 -> V_8 ) ;
}
static void
F_11 ( struct V_3 * V_4 , int V_18 )
{
struct V_14 * V_15 = V_4 -> V_16 [ V_18 ] ;
F_12 ( & V_15 -> V_19 ) ;
V_4 -> V_16 [ V_18 ] = NULL ;
F_13 ( V_15 ) ;
}
static int
F_14 ( struct V_3 * V_4 , int V_18 )
{
struct V_14 * V_15 = F_15 ( sizeof( * V_15 ) , V_20 ) ;
if ( V_15 ) {
F_16 ( & V_15 -> V_19 ) ;
F_8 ( & V_15 -> V_8 , 0 ) ;
V_4 -> V_16 [ V_18 ] = V_15 ;
return 0 ;
}
return - V_21 ;
}
static int
F_17 ( struct V_22 * V_23 , int V_18 , bool V_24 )
{
return 0 ;
}
static int
F_18 ( struct V_22 * V_23 , int V_18 )
{
return 0 ;
}
static void
F_19 ( struct V_22 * V_23 , int V_18 )
{
struct V_25 * V_26 = V_23 -> V_27 ;
struct V_28 * V_29 = F_20 ( V_23 , V_18 ) ;
V_26 -> V_30 [ V_18 ] = NULL ;
F_13 ( V_29 ) ;
}
int
F_21 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = V_23 -> V_27 ;
struct V_28 * V_29 ;
int V_6 ;
V_29 = F_15 ( sizeof( * V_29 ) , V_20 ) ;
if ( ! V_29 )
return - V_21 ;
V_29 -> V_19 . V_18 . V_31 = F_19 ;
V_29 -> V_19 . V_18 . V_32 = F_18 ;
V_29 -> V_19 . V_18 . V_33 = F_17 ;
V_29 -> V_19 . V_18 . V_34 = F_14 ;
V_29 -> V_19 . V_18 . V_35 = F_11 ;
V_29 -> V_19 . V_36 = F_1 ;
V_29 -> V_19 . V_37 = F_6 ;
V_29 -> V_19 . V_38 = F_9 ;
V_26 -> V_30 [ V_17 ] = & V_29 -> V_19 . V_18 ;
return V_6 ;
}
