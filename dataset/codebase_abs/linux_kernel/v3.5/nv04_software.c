static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 V_7 ;
if ( ! F_2 ( V_2 , & V_7 ) ) {
F_3 ( V_2 -> V_8 , V_7 . V_9 , V_7 . V_10 +
V_7 . V_11 * V_7 . V_12 +
V_7 . V_13 * V_7 . V_14 / 8 ) ;
}
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , int V_15 )
{
struct V_16 * V_17 ;
V_17 = F_5 ( sizeof( * V_17 ) , V_18 ) ;
if ( ! V_17 )
return - V_19 ;
F_6 ( & V_17 -> V_20 ) ;
V_2 -> V_21 [ V_15 ] = V_17 ;
return 0 ;
}
static void
F_7 ( struct V_1 * V_2 , int V_15 )
{
struct V_16 * V_17 = V_2 -> V_21 [ V_15 ] ;
V_2 -> V_21 [ V_15 ] = NULL ;
F_8 ( V_17 ) ;
}
static int
F_9 ( struct V_1 * V_2 , int V_15 ,
T_1 V_22 , T_2 V_3 )
{
struct V_23 * V_8 = V_2 -> V_8 ;
struct V_24 * V_25 = NULL ;
int V_26 ;
V_26 = F_10 ( V_8 , V_2 , 16 , 16 , 0 , & V_25 ) ;
if ( V_26 )
return V_26 ;
V_25 -> V_15 = 0 ;
V_25 -> V_3 = V_3 ;
V_26 = F_11 ( V_2 , V_22 , V_25 ) ;
F_12 ( NULL , & V_25 ) ;
return V_26 ;
}
static int
F_13 ( struct V_23 * V_8 , int V_15 )
{
return 0 ;
}
static int
F_14 ( struct V_23 * V_8 , int V_15 , bool V_27 )
{
return 0 ;
}
static void
F_15 ( struct V_23 * V_8 , int V_15 )
{
struct V_28 * V_29 = F_16 ( V_8 , V_15 ) ;
F_17 ( V_8 , V_30 ) ;
F_8 ( V_29 ) ;
}
int
F_18 ( struct V_23 * V_8 )
{
struct V_31 * V_32 = V_8 -> V_33 ;
struct V_28 * V_29 ;
V_29 = F_5 ( sizeof( * V_29 ) , V_18 ) ;
if ( ! V_29 )
return - V_19 ;
V_29 -> V_20 . V_20 . V_34 = F_15 ;
V_29 -> V_20 . V_20 . V_35 = F_13 ;
V_29 -> V_20 . V_20 . V_36 = F_14 ;
V_29 -> V_20 . V_20 . V_37 = F_4 ;
V_29 -> V_20 . V_20 . V_38 = F_7 ;
V_29 -> V_20 . V_20 . V_39 = F_9 ;
F_19 ( & V_29 -> V_20 ) ;
F_20 ( V_8 , V_30 , & V_29 -> V_20 . V_20 ) ;
if ( V_32 -> V_40 <= V_41 ) {
F_21 ( V_8 , 0x006e , V_30 ) ;
F_22 ( V_8 , 0x006e , 0x0150 , V_42 ) ;
F_22 ( V_8 , 0x006e , 0x0500 , F_1 ) ;
} else {
F_21 ( V_8 , 0x016e , V_30 ) ;
F_22 ( V_8 , 0x016e , 0x0500 , F_1 ) ;
}
return 0 ;
}
