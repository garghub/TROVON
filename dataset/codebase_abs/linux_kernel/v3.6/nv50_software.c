static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 [ V_9 ] ;
struct V_10 * V_11 ;
V_11 = F_2 ( V_2 , V_5 ) ;
if ( ! V_11 )
return - V_12 ;
V_7 -> V_13 . V_14 . V_15 = V_11 -> V_16 >> 4 ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 [ V_9 ] ;
V_7 -> V_13 . V_14 . V_17 = V_5 ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 [ V_9 ] ;
V_7 -> V_13 . V_14 . V_18 = V_5 ;
return 0 ;
}
static int
F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_19 * V_20 = F_6 ( V_2 -> V_21 , V_9 ) ;
struct V_6 * V_7 = V_2 -> V_8 [ V_9 ] ;
struct V_22 * V_21 = V_2 -> V_21 ;
if ( V_5 > 1 )
return - V_23 ;
F_7 ( V_21 , V_5 ) ;
V_7 -> V_13 . V_14 . V_24 = V_5 ;
F_8 ( & V_7 -> V_13 . V_14 . V_25 , & V_20 -> V_13 . V_14 ) ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
F_10 ( V_2 , NULL ) ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 , int V_26 )
{
struct V_19 * V_20 = F_6 ( V_2 -> V_21 , V_9 ) ;
struct V_27 * V_28 = V_27 ( V_2 -> V_21 ) ;
struct V_6 * V_7 ;
int V_29 = 0 , V_30 ;
V_7 = F_12 ( sizeof( * V_7 ) , V_31 ) ;
if ( ! V_7 )
return - V_32 ;
F_13 ( & V_7 -> V_13 ) ;
V_7 -> V_13 . V_14 . V_33 = V_2 -> V_34 -> V_35 >> 12 ;
V_2 -> V_8 [ V_26 ] = V_7 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_21 -> V_36 . V_37 ; V_30 ++ ) {
struct V_38 * V_39 = & V_28 -> V_40 [ V_30 ] ;
struct V_10 * V_41 = NULL ;
V_29 = F_14 ( V_2 , V_42 ,
V_39 -> V_43 . V_44 -> V_44 . V_17 , 0x1000 ,
V_45 ,
V_46 , & V_41 ) ;
if ( V_29 )
break;
V_29 = F_15 ( V_2 , V_47 + V_30 , V_41 ) ;
F_16 ( NULL , & V_41 ) ;
}
if ( V_29 )
V_20 -> V_13 . V_13 . V_48 ( V_2 , V_26 ) ;
return V_29 ;
}
static void
F_17 ( struct V_1 * V_2 , int V_26 )
{
struct V_6 * V_7 = V_2 -> V_8 [ V_26 ] ;
V_2 -> V_8 [ V_26 ] = NULL ;
F_18 ( V_7 ) ;
}
static int
F_19 ( struct V_1 * V_2 , int V_26 ,
T_1 V_49 , T_2 V_3 )
{
struct V_22 * V_21 = V_2 -> V_21 ;
struct V_10 * V_41 = NULL ;
int V_29 ;
V_29 = F_20 ( V_21 , V_2 , 16 , 16 , 0 , & V_41 ) ;
if ( V_29 )
return V_29 ;
V_41 -> V_26 = 0 ;
V_41 -> V_3 = V_3 ;
V_29 = F_15 ( V_2 , V_49 , V_41 ) ;
F_16 ( NULL , & V_41 ) ;
return V_29 ;
}
static int
F_21 ( struct V_22 * V_21 , int V_26 )
{
return 0 ;
}
static int
F_22 ( struct V_22 * V_21 , int V_26 , bool V_50 )
{
return 0 ;
}
static void
F_23 ( struct V_22 * V_21 , int V_26 )
{
struct V_19 * V_20 = F_6 ( V_21 , V_26 ) ;
F_24 ( V_21 , V_51 ) ;
F_18 ( V_20 ) ;
}
int
F_25 ( struct V_22 * V_21 )
{
struct V_19 * V_20 = F_12 ( sizeof( * V_20 ) , V_31 ) ;
if ( ! V_20 )
return - V_32 ;
V_20 -> V_13 . V_13 . V_52 = F_23 ;
V_20 -> V_13 . V_13 . V_53 = F_21 ;
V_20 -> V_13 . V_13 . V_54 = F_22 ;
V_20 -> V_13 . V_13 . V_55 = F_11 ;
V_20 -> V_13 . V_13 . V_48 = F_17 ;
V_20 -> V_13 . V_13 . V_56 = F_19 ;
F_26 ( & V_20 -> V_13 ) ;
F_27 ( V_21 , V_51 , & V_20 -> V_13 . V_13 ) ;
F_28 ( V_21 , 0x506e , V_51 ) ;
F_29 ( V_21 , 0x506e , 0x018c , F_1 ) ;
F_29 ( V_21 , 0x506e , 0x0400 , F_3 ) ;
F_29 ( V_21 , 0x506e , 0x0404 , F_4 ) ;
F_29 ( V_21 , 0x506e , 0x0408 , F_5 ) ;
F_29 ( V_21 , 0x506e , 0x0500 , F_9 ) ;
return 0 ;
}
