static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
F_3 ( V_4 , V_7 ) ;
F_4 ( V_4 , V_7 , 1000baseT_Full ) ;
F_4 ( V_4 , V_7 , V_8 ) ;
F_3 ( V_4 , V_9 ) ;
F_4 ( V_4 , V_9 , 1000baseT_Full ) ;
F_4 ( V_4 , V_9 , V_8 ) ;
V_4 -> V_10 . V_11 = V_12 ;
V_4 -> V_10 . V_13 = V_6 -> V_14 . V_13 ;
V_4 -> V_10 . V_15 = V_16 ;
return 0 ;
}
static void
F_5 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
F_6 ( V_18 -> V_19 , V_20 ,
sizeof( V_18 -> V_19 ) ) ;
F_6 ( V_18 -> V_21 , V_22 , sizeof( V_18 -> V_21 ) ) ;
F_6 ( V_18 -> V_23 , L_1 ,
sizeof( V_18 -> V_23 ) ) ;
F_6 ( V_18 -> V_24 , F_7 ( V_6 -> V_25 ) ,
sizeof( V_18 -> V_24 ) ) ;
}
static void
F_8 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
V_27 -> V_7 = 0 ;
V_27 -> V_28 = 0 ;
}
static T_1
F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
return V_6 -> V_29 ;
}
static void
F_10 ( struct V_1 * V_2 ,
T_1 V_30 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_29 = V_30 ;
}
static int
F_11 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) ) {
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
}
return 0 ;
}
static void
F_15 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_32 -> V_33 = V_34 ;
V_32 -> V_35 = V_6 -> V_36 . V_37 ;
V_32 -> V_38 = V_39 ;
V_32 -> V_40 = V_6 -> V_41 . V_37 ;
}
static int F_16 ( struct V_1 * V_2 , int V_42 )
{
switch ( V_42 ) {
case V_43 :
return F_17 ( V_44 ) ;
default:
return - V_45 ;
}
}
static void F_18 ( struct V_1 * V_2 ,
struct V_46 * V_47 , T_2 * V_48 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_48 [ 0 ] = V_2 -> V_47 . V_49 ;
V_48 [ 1 ] = V_2 -> V_47 . V_50 ;
V_48 [ 2 ] = V_2 -> V_47 . V_51 ;
V_48 [ 3 ] = V_2 -> V_47 . V_52 ;
V_48 [ 4 ] = V_2 -> V_47 . V_53 ;
V_48 [ 5 ] = V_2 -> V_47 . V_54 ;
V_48 [ 6 ] = V_2 -> V_47 . V_55 ;
V_48 [ 7 ] = V_6 -> V_56 . V_57 ;
V_48 [ 8 ] = V_6 -> V_56 . V_58 ;
V_48 [ 9 ] = V_6 -> V_56 . V_59 ;
V_48 [ 10 ] = V_6 -> V_56 . V_60 ;
V_48 [ 11 ] = V_6 -> V_56 . V_61 ;
V_48 [ 12 ] = V_6 -> V_56 . V_62 ;
}
static void F_19 ( struct V_1 * V_2 , T_1 V_63 ,
T_3 * V_48 )
{
memcpy ( V_48 , V_44 , sizeof( V_44 ) ) ;
}
