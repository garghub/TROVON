static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_8 [ V_9 ] ;
T_1 V_10 = V_7 -> V_11 . V_12 + V_4 -> V_13 * 16 ;
int V_14 ;
V_14 = F_2 ( V_4 , 5 ) ;
if ( V_14 == 0 ) {
F_3 ( V_4 , 0 , V_15 , 4 ) ;
F_4 ( V_4 , F_5 ( V_10 ) ) ;
F_4 ( V_4 , F_6 ( V_10 ) ) ;
F_4 ( V_4 , V_2 -> V_16 ) ;
F_4 ( V_4 , V_17 ) ;
F_7 ( V_4 ) ;
}
return V_14 ;
}
static int
F_8 ( struct V_1 * V_2 ,
struct V_3 * V_18 , struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_8 [ V_9 ] ;
T_1 V_10 = V_7 -> V_11 . V_12 + V_18 -> V_13 * 16 ;
int V_14 ;
V_14 = F_2 ( V_4 , 5 ) ;
if ( V_14 == 0 ) {
F_3 ( V_4 , 0 , V_15 , 4 ) ;
F_4 ( V_4 , F_5 ( V_10 ) ) ;
F_4 ( V_4 , F_6 ( V_10 ) ) ;
F_4 ( V_4 , V_2 -> V_16 ) ;
F_4 ( V_4 , V_19 |
V_20 ) ;
F_7 ( V_4 ) ;
}
return V_14 ;
}
static T_2
F_9 ( struct V_3 * V_4 )
{
struct V_21 * V_22 = F_10 ( V_4 -> V_23 , V_9 ) ;
return F_11 ( V_22 -> V_24 , V_4 -> V_13 * 16 / 4 ) ;
}
static void
F_12 ( struct V_3 * V_4 , int V_25 )
{
struct V_21 * V_22 = F_10 ( V_4 -> V_23 , V_25 ) ;
struct V_6 * V_7 = V_4 -> V_8 [ V_25 ] ;
F_13 ( V_22 -> V_24 , & V_7 -> V_11 ) ;
F_14 ( & V_7 -> V_26 ) ;
V_4 -> V_8 [ V_25 ] = NULL ;
F_15 ( V_7 ) ;
}
static int
F_16 ( struct V_3 * V_4 , int V_25 )
{
struct V_21 * V_22 = F_10 ( V_4 -> V_23 , V_25 ) ;
struct V_6 * V_7 ;
int V_14 ;
V_7 = V_4 -> V_8 [ V_25 ] = F_17 ( sizeof( * V_7 ) , V_27 ) ;
if ( ! V_7 )
return - V_28 ;
F_18 ( & V_7 -> V_26 ) ;
V_14 = F_19 ( V_22 -> V_24 , V_4 -> V_29 , & V_7 -> V_11 ) ;
if ( V_14 )
F_12 ( V_4 , V_25 ) ;
F_20 ( V_22 -> V_24 , V_4 -> V_13 * 16 / 4 , 0x00000000 ) ;
return V_14 ;
}
static int
F_21 ( struct V_30 * V_23 , int V_25 , bool V_31 )
{
return 0 ;
}
static int
F_22 ( struct V_30 * V_23 , int V_25 )
{
return 0 ;
}
static void
F_23 ( struct V_30 * V_23 , int V_25 )
{
struct V_32 * V_33 = V_23 -> V_34 ;
struct V_21 * V_22 = F_10 ( V_23 , V_25 ) ;
F_24 ( V_22 -> V_24 ) ;
F_25 ( NULL , & V_22 -> V_24 ) ;
V_33 -> V_35 [ V_25 ] = NULL ;
F_15 ( V_22 ) ;
}
int
F_26 ( struct V_30 * V_23 )
{
struct V_36 * V_37 = F_10 ( V_23 , V_38 ) ;
struct V_32 * V_33 = V_23 -> V_34 ;
struct V_21 * V_22 ;
int V_14 ;
V_22 = F_17 ( sizeof( * V_22 ) , V_27 ) ;
if ( ! V_22 )
return - V_28 ;
V_22 -> V_26 . V_25 . V_39 = F_23 ;
V_22 -> V_26 . V_25 . V_40 = F_22 ;
V_22 -> V_26 . V_25 . V_41 = F_21 ;
V_22 -> V_26 . V_25 . V_42 = F_16 ;
V_22 -> V_26 . V_25 . V_43 = F_12 ;
V_22 -> V_26 . V_44 = F_1 ;
V_22 -> V_26 . V_45 = F_8 ;
V_22 -> V_26 . V_46 = F_9 ;
V_33 -> V_35 [ V_9 ] = & V_22 -> V_26 . V_25 ;
V_14 = F_27 ( V_23 , 16 * V_37 -> V_47 , 0 , V_48 ,
0 , 0 , NULL , & V_22 -> V_24 ) ;
if ( V_14 == 0 ) {
V_14 = F_28 ( V_22 -> V_24 , V_48 ) ;
if ( V_14 == 0 )
V_14 = F_29 ( V_22 -> V_24 ) ;
if ( V_14 )
F_25 ( NULL , & V_22 -> V_24 ) ;
}
if ( V_14 )
F_23 ( V_23 , V_9 ) ;
return V_14 ;
}
