static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 = F_2 ( V_4 , 7 ) ;
if ( V_6 == 0 ) {
F_3 ( V_4 , 0 , V_7 , 1 ) ;
F_4 ( V_4 , V_8 ) ;
F_3 ( V_4 , 0 , V_9 , 4 ) ;
F_4 ( V_4 , F_5 ( V_4 -> V_10 * 16 ) ) ;
F_4 ( V_4 , F_6 ( V_4 -> V_10 * 16 ) ) ;
F_4 ( V_4 , V_2 -> V_11 ) ;
F_4 ( V_4 , V_12 ) ;
F_7 ( V_4 ) ;
}
return V_6 ;
}
static int
F_8 ( struct V_1 * V_2 ,
struct V_3 * V_13 , struct V_3 * V_4 )
{
int V_6 = F_2 ( V_4 , 7 ) ;
if ( V_6 == 0 ) {
F_3 ( V_4 , 0 , V_7 , 1 ) ;
F_4 ( V_4 , V_8 ) ;
F_3 ( V_4 , 0 , V_9 , 4 ) ;
F_4 ( V_4 , F_5 ( V_13 -> V_10 * 16 ) ) ;
F_4 ( V_4 , F_6 ( V_13 -> V_10 * 16 ) ) ;
F_4 ( V_4 , V_2 -> V_11 ) ;
F_4 ( V_4 , V_14 ) ;
F_7 ( V_4 ) ;
}
return V_6 ;
}
static T_1
F_9 ( struct V_3 * V_4 )
{
struct V_15 * V_16 = F_10 ( V_4 -> V_17 , V_18 ) ;
return F_11 ( V_16 -> V_19 , V_4 -> V_10 * 16 ) ;
}
static void
F_12 ( struct V_3 * V_4 , int V_20 )
{
struct V_21 * V_22 = V_4 -> V_23 [ V_20 ] ;
F_13 ( & V_22 -> V_24 ) ;
V_4 -> V_23 [ V_20 ] = NULL ;
F_14 ( V_22 ) ;
}
static int
F_15 ( struct V_3 * V_4 , int V_20 )
{
struct V_15 * V_16 = F_10 ( V_4 -> V_17 , V_20 ) ;
struct V_21 * V_22 ;
struct V_25 * V_26 ;
int V_6 ;
V_22 = V_4 -> V_23 [ V_20 ] = F_16 ( sizeof( * V_22 ) , V_27 ) ;
if ( ! V_22 )
return - V_28 ;
F_17 ( & V_22 -> V_24 ) ;
V_6 = F_18 ( V_4 , V_29 ,
V_16 -> V_19 -> V_30 , V_16 -> V_19 -> V_31 ,
V_32 ,
V_33 , & V_26 ) ;
if ( V_6 == 0 ) {
V_6 = F_19 ( V_4 , V_8 , V_26 ) ;
F_20 ( NULL , & V_26 ) ;
F_21 ( V_16 -> V_19 , V_4 -> V_10 * 16 , 0x00000000 ) ;
}
if ( V_6 )
F_12 ( V_4 , V_20 ) ;
return V_6 ;
}
static int
F_22 ( struct V_34 * V_17 , int V_20 , bool V_35 )
{
return 0 ;
}
static int
F_23 ( struct V_34 * V_17 , int V_20 )
{
return 0 ;
}
static void
F_24 ( struct V_34 * V_17 , int V_20 )
{
struct V_36 * V_37 = V_17 -> V_38 ;
struct V_15 * V_16 = F_10 ( V_17 , V_20 ) ;
F_20 ( NULL , & V_16 -> V_19 ) ;
V_37 -> V_39 [ V_20 ] = NULL ;
F_14 ( V_16 ) ;
}
int
F_25 ( struct V_34 * V_17 )
{
struct V_40 * V_41 = F_10 ( V_17 , V_42 ) ;
struct V_36 * V_37 = V_17 -> V_38 ;
struct V_15 * V_16 ;
int V_6 ;
V_16 = F_16 ( sizeof( * V_16 ) , V_27 ) ;
if ( ! V_16 )
return - V_28 ;
V_16 -> V_24 . V_20 . V_43 = F_24 ;
V_16 -> V_24 . V_20 . V_44 = F_23 ;
V_16 -> V_24 . V_20 . V_45 = F_22 ;
V_16 -> V_24 . V_20 . V_46 = F_15 ;
V_16 -> V_24 . V_20 . V_47 = F_12 ;
V_16 -> V_24 . V_48 = F_1 ;
V_16 -> V_24 . V_49 = F_8 ;
V_16 -> V_24 . V_50 = F_9 ;
V_37 -> V_39 [ V_18 ] = & V_16 -> V_24 . V_20 ;
V_6 = F_26 ( V_17 , NULL , 16 * V_41 -> V_51 ,
0x1000 , 0 , & V_16 -> V_19 ) ;
if ( V_6 )
goto V_52;
V_52:
if ( V_6 )
F_24 ( V_17 , V_18 ) ;
return V_6 ;
}
