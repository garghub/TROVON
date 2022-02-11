static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 [ V_9 ] ;
struct V_10 * V_11 ;
V_11 = F_2 ( V_2 , V_5 ) ;
if ( ! V_11 )
return - V_12 ;
if ( F_3 ( V_11 , NULL ) )
return - V_13 ;
V_7 -> V_14 . V_15 = V_11 ;
V_7 -> V_16 . V_14 . V_17 = ~ 0 ;
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 [ V_9 ] ;
if ( F_3 ( V_7 -> V_14 . V_15 , & V_5 ) )
return - V_18 ;
V_7 -> V_16 . V_14 . V_17 = V_5 >> 2 ;
return 0 ;
}
static int
F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 [ V_9 ] ;
V_7 -> V_16 . V_14 . V_19 = V_5 ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_20 * V_21 = F_7 ( V_2 -> V_22 , V_9 ) ;
struct V_6 * V_7 = V_2 -> V_8 [ V_9 ] ;
struct V_23 * V_22 = V_2 -> V_22 ;
if ( ! V_7 -> V_14 . V_15 || V_7 -> V_16 . V_14 . V_17 == ~ 0 || V_5 > 1 )
return - V_13 ;
F_8 ( V_22 , V_5 ) ;
V_7 -> V_16 . V_14 . V_24 = V_5 ;
F_9 ( & V_7 -> V_16 . V_14 . V_25 , & V_21 -> V_16 . V_14 ) ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
F_11 ( V_2 , NULL ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 , int V_26 )
{
struct V_20 * V_21 = F_7 ( V_2 -> V_22 , V_9 ) ;
struct V_27 * V_28 = V_27 ( V_2 -> V_22 ) ;
struct V_6 * V_7 ;
int V_29 = 0 , V_30 ;
V_7 = F_13 ( sizeof( * V_7 ) , V_31 ) ;
if ( ! V_7 )
return - V_32 ;
F_14 ( & V_7 -> V_16 ) ;
V_7 -> V_16 . V_14 . V_33 = V_2 -> V_34 ;
V_2 -> V_8 [ V_26 ] = V_7 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_22 -> V_35 . V_36 ; V_30 ++ ) {
struct V_37 * V_38 = & V_28 -> V_39 [ V_30 ] ;
struct V_10 * V_40 = NULL ;
V_29 = F_15 ( V_2 , V_41 ,
V_38 -> V_42 . V_33 -> V_33 . V_17 , 0x1000 ,
V_43 ,
V_44 , & V_40 ) ;
if ( V_29 )
break;
V_29 = F_16 ( V_2 , V_45 + V_30 , V_40 ) ;
F_17 ( NULL , & V_40 ) ;
}
if ( V_29 )
V_21 -> V_16 . V_16 . V_46 ( V_2 , V_26 ) ;
return V_29 ;
}
static void
F_18 ( struct V_1 * V_2 , int V_26 )
{
struct V_6 * V_7 = V_2 -> V_8 [ V_26 ] ;
V_2 -> V_8 [ V_26 ] = NULL ;
F_19 ( V_7 ) ;
}
static int
F_20 ( struct V_1 * V_2 , int V_26 ,
T_1 V_47 , T_2 V_3 )
{
struct V_23 * V_22 = V_2 -> V_22 ;
struct V_10 * V_40 = NULL ;
int V_29 ;
V_29 = F_21 ( V_22 , V_2 , 16 , 16 , 0 , & V_40 ) ;
if ( V_29 )
return V_29 ;
V_40 -> V_26 = 0 ;
V_40 -> V_3 = V_3 ;
V_29 = F_16 ( V_2 , V_47 , V_40 ) ;
F_17 ( NULL , & V_40 ) ;
return V_29 ;
}
static int
F_22 ( struct V_23 * V_22 , int V_26 )
{
return 0 ;
}
static int
F_23 ( struct V_23 * V_22 , int V_26 , bool V_48 )
{
return 0 ;
}
static void
F_24 ( struct V_23 * V_22 , int V_26 )
{
struct V_20 * V_21 = F_7 ( V_22 , V_26 ) ;
F_25 ( V_22 , V_49 ) ;
F_19 ( V_21 ) ;
}
int
F_26 ( struct V_23 * V_22 )
{
struct V_20 * V_21 = F_13 ( sizeof( * V_21 ) , V_31 ) ;
if ( ! V_21 )
return - V_32 ;
V_21 -> V_16 . V_16 . V_50 = F_24 ;
V_21 -> V_16 . V_16 . V_51 = F_22 ;
V_21 -> V_16 . V_16 . V_52 = F_23 ;
V_21 -> V_16 . V_16 . V_53 = F_12 ;
V_21 -> V_16 . V_16 . V_46 = F_18 ;
V_21 -> V_16 . V_16 . V_54 = F_20 ;
F_27 ( & V_21 -> V_16 ) ;
F_28 ( V_22 , V_49 , & V_21 -> V_16 . V_16 ) ;
F_29 ( V_22 , 0x506e , V_49 ) ;
F_30 ( V_22 , 0x506e , 0x018c , F_1 ) ;
F_30 ( V_22 , 0x506e , 0x0400 , F_4 ) ;
F_30 ( V_22 , 0x506e , 0x0404 , F_5 ) ;
F_30 ( V_22 , 0x506e , 0x0408 , F_6 ) ;
F_30 ( V_22 , 0x506e , 0x0500 , F_10 ) ;
return 0 ;
}
