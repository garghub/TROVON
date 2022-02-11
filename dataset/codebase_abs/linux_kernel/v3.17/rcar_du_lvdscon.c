static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
struct V_5 * V_6 ;
V_6 = F_3 ( V_2 -> V_7 ) ;
if ( V_6 == NULL )
return 0 ;
V_6 -> type = V_8 | V_9 ;
V_6 -> clock = V_4 -> V_10 -> V_6 . clock ;
V_6 -> V_11 = V_4 -> V_10 -> V_6 . V_11 ;
V_6 -> V_12 = V_4 -> V_10 -> V_6 . V_12 ;
V_6 -> V_13 = V_4 -> V_10 -> V_6 . V_13 ;
V_6 -> V_14 = V_4 -> V_10 -> V_6 . V_14 ;
V_6 -> V_15 = V_4 -> V_10 -> V_6 . V_15 ;
V_6 -> V_16 = V_4 -> V_10 -> V_6 . V_16 ;
V_6 -> V_17 = V_4 -> V_10 -> V_6 . V_17 ;
V_6 -> V_18 = V_4 -> V_10 -> V_6 . V_18 ;
V_6 -> V_19 = V_4 -> V_10 -> V_6 . V_19 ;
F_4 ( V_6 ) ;
F_5 ( V_2 , V_6 ) ;
return 1 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
}
static enum V_20
F_9 ( struct V_1 * V_2 , bool V_21 )
{
return V_22 ;
}
int F_10 ( struct V_23 * V_24 ,
struct V_25 * V_26 ,
const struct V_27 * V_10 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
int V_28 ;
V_4 = F_11 ( V_24 -> V_7 , sizeof( * V_4 ) , V_29 ) ;
if ( V_4 == NULL )
return - V_30 ;
V_4 -> V_10 = V_10 ;
V_2 = & V_4 -> V_2 . V_2 ;
V_2 -> V_31 . V_32 = V_10 -> V_32 ;
V_2 -> V_31 . V_33 = V_10 -> V_33 ;
V_28 = F_12 ( V_24 -> V_34 , V_2 , & V_35 ,
V_36 ) ;
if ( V_28 < 0 )
return V_28 ;
F_13 ( V_2 , & V_37 ) ;
V_28 = F_14 ( V_2 ) ;
if ( V_28 < 0 )
return V_28 ;
F_15 ( V_2 , V_38 ) ;
F_16 ( & V_2 -> V_39 ,
V_24 -> V_34 -> V_40 . V_41 , V_38 ) ;
V_28 = F_17 ( V_2 , & V_26 -> V_42 ) ;
if ( V_28 < 0 )
return V_28 ;
V_2 -> V_42 = & V_26 -> V_42 ;
V_4 -> V_2 . V_42 = V_26 ;
return 0 ;
}
