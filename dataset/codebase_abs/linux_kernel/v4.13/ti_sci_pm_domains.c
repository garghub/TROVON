static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
return V_6 -> V_8 ;
}
static const struct V_9 * F_3 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_4 ( V_2 -> V_12 ) ;
struct V_13 * V_14 = F_5 ( V_11 ) ;
return V_14 -> V_15 ;
}
static int F_6 ( struct V_1 * V_2 )
{
const struct V_9 * V_15 = F_3 ( V_2 ) ;
int V_8 = F_1 ( V_2 ) ;
return V_15 -> V_16 . V_17 . V_18 ( V_15 , V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
const struct V_9 * V_15 = F_3 ( V_2 ) ;
int V_8 = F_1 ( V_2 ) ;
return V_15 -> V_16 . V_17 . V_19 ( V_15 , V_8 ) ;
}
static int F_8 ( struct V_10 * V_20 ,
struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_23 ;
struct V_24 V_25 ;
struct V_13 * V_14 = F_5 ( V_20 ) ;
const struct V_9 * V_15 = V_14 -> V_15 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_8 , V_26 = 0 ;
V_26 = F_9 ( V_22 , L_1 ,
L_2 , 0 , & V_25 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_25 . V_27 != 1 )
return - V_28 ;
V_8 = V_25 . args [ 0 ] ;
V_26 = V_15 -> V_16 . V_17 . V_29 ( V_15 , V_8 ) ;
if ( V_26 )
return - V_28 ;
V_6 = F_10 ( sizeof( * V_6 ) , V_30 ) ;
if ( ! V_6 )
return - V_31 ;
V_6 -> V_8 = V_8 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_7 = V_6 ;
return 0 ;
}
static void F_11 ( struct V_10 * V_20 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_7 ;
F_12 ( V_6 ) ;
V_4 -> V_7 = NULL ;
}
static int F_13 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = & V_33 -> V_2 ;
struct V_21 * V_22 = V_2 -> V_23 ;
struct V_13 * V_34 ;
int V_26 ;
V_34 = F_14 ( V_2 , sizeof( * V_34 ) , V_30 ) ;
if ( ! V_34 )
return - V_31 ;
V_34 -> V_15 = F_15 ( V_2 ) ;
if ( F_16 ( V_34 -> V_15 ) )
return F_17 ( V_34 -> V_15 ) ;
V_34 -> V_2 = V_2 ;
V_34 -> V_11 . V_35 = L_3 ;
V_34 -> V_11 . V_36 = F_8 ;
V_34 -> V_11 . V_37 = F_11 ;
V_34 -> V_11 . V_17 . V_38 = F_6 ;
V_34 -> V_11 . V_17 . V_39 = F_7 ;
F_18 ( & V_34 -> V_11 , NULL , true ) ;
V_26 = F_19 ( V_22 , & V_34 -> V_11 ) ;
return V_26 ;
}
