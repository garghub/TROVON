static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return 32768 ;
}
static int F_2 ( struct V_1 * V_2 , bool V_4 )
{
struct V_5 * V_5 = F_3 ( V_2 ,
struct V_5 ,
V_6 ) ;
struct V_7 * V_7 = V_5 -> V_7 ;
return F_4 ( V_7 -> V_8 , V_9 ,
V_10 , V_4 ? V_10 : 0 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , true ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( V_2 , false ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_3 ( V_2 ,
struct V_5 ,
V_6 ) ;
struct V_7 * V_7 = V_5 -> V_7 ;
T_1 V_11 ;
int V_12 = F_8 ( V_7 -> V_8 , V_9 , & V_11 ) ;
if ( V_12 < 0 )
return V_12 ;
return ( V_11 & V_10 ) ? 1 : 0 ;
}
static int F_9 ( struct V_13 * V_14 )
{
struct V_7 * V_7 = F_10 ( V_14 -> V_15 . V_16 ) ;
struct V_17 * V_18 = V_7 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_15 . V_22 ;
struct V_23 V_24 = {} ;
struct V_25 * * V_26 ;
struct V_5 * V_5 ;
V_5 = F_11 ( & V_18 -> V_15 ,
sizeof( * V_5 ) , V_27 ) ;
if ( ! V_5 )
return - V_28 ;
V_5 -> V_7 = V_7 ;
V_26 = F_12 ( & V_18 -> V_15 , V_29 ,
sizeof( struct V_25 * ) , V_27 ) ;
if ( ! V_26 )
return - V_28 ;
V_24 . V_30 = V_31 ;
V_24 . V_32 = NULL ;
V_24 . V_33 = 0 ;
V_24 . V_34 = L_1 ;
V_24 . V_35 = & V_36 ;
V_5 -> V_37 . V_24 = & V_24 ;
F_13 ( V_21 , L_2 ,
0 , & V_24 . V_34 ) ;
V_26 [ 0 ] = F_14 ( & V_18 -> V_15 ,
& V_5 -> V_37 ) ;
if ( F_15 ( V_26 [ 0 ] ) )
return F_16 ( V_26 [ 0 ] ) ;
V_24 . V_34 = L_3 ;
V_24 . V_35 = & V_38 ;
V_5 -> V_6 . V_24 = & V_24 ;
F_13 ( V_21 , L_2 ,
1 , & V_24 . V_34 ) ;
V_26 [ 1 ] = F_14 ( & V_18 -> V_15 ,
& V_5 -> V_6 ) ;
if ( F_15 ( V_26 [ 1 ] ) )
return F_16 ( V_26 [ 1 ] ) ;
V_5 -> V_39 . V_40 = V_26 ;
V_5 -> V_39 . V_41 = V_29 ;
return F_17 ( V_21 , V_42 ,
& V_5 -> V_39 ) ;
}
static int F_18 ( struct V_13 * V_14 )
{
struct V_7 * V_7 = F_10 ( V_14 -> V_15 . V_16 ) ;
struct V_17 * V_18 = V_7 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_15 . V_22 ;
F_19 ( V_21 ) ;
return 0 ;
}
