static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
V_4 -> V_7 = ( V_8 |
V_9 ) ;
V_4 -> V_10 = ( V_11 |
V_12 ) ;
V_4 -> V_13 = V_14 ;
F_3 ( V_4 , V_6 -> V_15 . V_16 ) ;
V_4 -> V_17 = V_18 ;
return 0 ;
}
static void
F_4 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
memset ( V_20 , 0 , sizeof( struct V_19 ) ) ;
strncpy ( V_20 -> V_21 , V_22 , 32 ) ;
strncpy ( V_20 -> V_23 , V_24 , 32 ) ;
strcpy ( V_20 -> V_25 , L_1 ) ;
strncpy ( V_20 -> V_26 , F_5 ( V_6 -> V_27 ) , 32 ) ;
}
static void
F_6 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
V_29 -> V_7 = 0 ;
V_29 -> V_30 = 0 ;
}
static T_1
F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
return V_6 -> V_31 ;
}
static void
F_8 ( struct V_1 * V_2 ,
T_1 V_32 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_31 = V_32 ;
}
static int
F_9 ( struct V_1 * V_2 )
{
if ( F_10 ( V_2 ) ) {
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
}
return 0 ;
}
static void
F_13 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_34 -> V_35 = V_36 ;
V_34 -> V_37 = V_6 -> V_38 . V_39 ;
V_34 -> V_40 = V_41 ;
V_34 -> V_42 = V_6 -> V_43 . V_39 ;
}
static int F_14 ( struct V_1 * V_2 , int V_44 )
{
switch ( V_44 ) {
case V_45 :
return F_15 ( V_46 ) ;
default:
return - V_47 ;
}
}
static void F_16 ( struct V_1 * V_2 ,
struct V_48 * V_49 , T_2 * V_50 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_50 [ 0 ] = V_2 -> V_49 . V_51 ;
V_50 [ 1 ] = V_2 -> V_49 . V_52 ;
V_50 [ 2 ] = V_2 -> V_49 . V_53 ;
V_50 [ 3 ] = V_2 -> V_49 . V_54 ;
V_50 [ 4 ] = V_2 -> V_49 . V_55 ;
V_50 [ 5 ] = V_2 -> V_49 . V_56 ;
V_50 [ 6 ] = V_2 -> V_49 . V_57 ;
V_50 [ 7 ] = V_6 -> V_58 . V_59 ;
V_50 [ 8 ] = V_6 -> V_58 . V_60 ;
V_50 [ 9 ] = V_6 -> V_58 . V_61 ;
V_50 [ 10 ] = V_6 -> V_58 . V_62 ;
V_50 [ 11 ] = V_6 -> V_58 . V_63 ;
V_50 [ 12 ] = V_6 -> V_58 . V_64 ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_65 ,
T_3 * V_50 )
{
memcpy ( V_50 , V_46 , sizeof( V_46 ) ) ;
}
