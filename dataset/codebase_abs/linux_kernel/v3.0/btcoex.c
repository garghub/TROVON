void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
const struct V_6 V_7 = {
. V_8 = 0 ,
. V_9 = true ,
. V_10 = true ,
. V_11 = V_12 ,
. V_13 = true ,
. V_14 = true ,
. V_15 = 2 ,
. V_16 = 5 ,
. V_17 = true ,
} ;
T_1 V_18 ;
bool V_19 = V_7 . V_14 ;
if ( F_2 ( V_2 ) )
V_19 = ! V_7 . V_14 ;
V_5 -> V_20 =
( V_5 -> V_20 & V_21 ) |
F_3 ( V_7 . V_8 , V_22 ) |
F_3 ( V_7 . V_9 , V_23 ) |
F_3 ( V_7 . V_10 , V_24 ) |
F_3 ( V_7 . V_11 , V_25 ) |
F_3 ( V_7 . V_13 , V_26 ) |
F_3 ( V_19 , V_27 ) |
F_3 ( V_7 . V_15 , V_28 ) |
F_3 ( V_7 . V_16 , V_29 ) |
F_3 ( V_3 , V_21 ) ;
V_5 -> V_30 =
F_3 ( V_7 . V_17 , V_31 ) |
F_3 ( V_32 , V_33 ) |
V_34 ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ )
V_2 -> V_35 . V_36 [ ( V_37 << V_18 ) >> 27 ] = V_18 ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_5 ( V_2 , V_38 ,
( V_39 |
V_40 ) ) ;
F_6 ( V_2 , V_38 ,
V_41 ) ;
F_7 ( V_2 , V_42 ,
V_43 ,
V_5 -> V_44 ) ;
F_8 ( V_2 , V_5 -> V_44 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_6 ( V_2 , V_38 ,
( V_45 |
V_41 ) ) ;
F_7 ( V_2 , V_42 ,
V_43 ,
V_5 -> V_44 ) ;
F_7 ( V_2 , V_42 ,
V_46 ,
V_5 -> V_47 ) ;
F_8 ( V_2 , V_5 -> V_44 ) ;
F_8 ( V_2 , V_5 -> V_47 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_11 ( V_2 , V_5 -> V_48 ,
V_49 ) ;
}
void F_12 ( struct V_1 * V_2 ,
T_1 V_50 ,
T_1 V_51 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
V_5 -> V_52 = F_3 ( V_50 , V_53 ) |
F_3 ( V_51 , V_54 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
T_1 V_55 ;
F_14 ( V_2 , V_56 , V_5 -> V_20 ) ;
F_14 ( V_2 , V_57 , V_5 -> V_30 ) ;
if ( F_2 ( V_2 ) ) {
F_14 ( V_2 , V_58 , V_2 -> V_59 [ 0 ] ) ;
F_14 ( V_2 , V_60 , V_2 -> V_59 [ 1 ] ) ;
F_14 ( V_2 , V_61 , V_2 -> V_62 [ 0 ] ) ;
F_14 ( V_2 , V_63 , V_2 -> V_62 [ 1 ] ) ;
F_14 ( V_2 , V_64 , V_2 -> V_62 [ 2 ] ) ;
F_14 ( V_2 , V_65 , V_2 -> V_62 [ 3 ] ) ;
} else
F_14 ( V_2 , V_66 , V_5 -> V_52 ) ;
if ( F_15 ( V_2 ) ) {
V_55 = F_16 ( V_2 , 0x50040 ) ;
V_55 &= 0xFFFFFEFF ;
F_14 ( V_2 , 0x50040 , V_55 ) ;
}
F_7 ( V_2 , V_67 , V_68 , 1 ) ;
F_7 ( V_2 , V_69 , V_70 , 0 ) ;
F_11 ( V_2 , V_5 -> V_48 ,
V_71 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
switch ( V_5 -> V_72 ) {
case V_73 :
break;
case V_74 :
F_10 ( V_2 ) ;
break;
case V_75 :
F_13 ( V_2 ) ;
break;
}
F_18 ( V_2 , V_76 ,
( 0x2 << ( V_5 -> V_44 * 2 ) ) ,
( 0x3 << ( V_5 -> V_44 * 2 ) ) ) ;
V_2 -> V_5 . V_77 = true ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_20 ( V_2 , V_5 -> V_48 , 0 ) ;
F_11 ( V_2 , V_5 -> V_48 ,
V_78 ) ;
if ( V_5 -> V_72 == V_75 ) {
F_14 ( V_2 , V_56 , V_26 | V_25 ) ;
F_14 ( V_2 , V_57 , 0 ) ;
if ( F_2 ( V_2 ) ) {
F_14 ( V_2 , V_58 , 0 ) ;
F_14 ( V_2 , V_60 , 0 ) ;
F_14 ( V_2 , V_61 , 0 ) ;
F_14 ( V_2 , V_63 , 0 ) ;
F_14 ( V_2 , V_64 , 0 ) ;
F_14 ( V_2 , V_65 , 0 ) ;
} else
F_14 ( V_2 , V_66 , 0 ) ;
}
V_2 -> V_5 . V_77 = false ;
}
static void F_21 ( struct V_1 * V_2 ,
enum V_79 V_80 )
{
V_2 -> V_62 [ 0 ] = V_81 ;
V_2 -> V_62 [ 1 ] = V_81 ;
V_2 -> V_62 [ 2 ] = V_81 ;
V_2 -> V_62 [ 3 ] = V_81 ;
switch ( V_80 ) {
case V_82 :
V_2 -> V_59 [ 0 ] = V_83 ;
V_2 -> V_59 [ 1 ] = V_84 ;
break;
case V_85 :
V_2 -> V_59 [ 0 ] = V_86 ;
V_2 -> V_59 [ 1 ] = V_87 ;
break;
case V_88 :
V_2 -> V_59 [ 0 ] = V_89 ;
V_2 -> V_59 [ 1 ] = V_90 ;
break;
default:
F_22 ( F_23 ( V_2 ) , V_91 ,
L_1 ) ;
break;
}
F_17 ( V_2 ) ;
}
void F_24 ( struct V_1 * V_2 ,
enum V_79 V_80 )
{
if ( F_2 ( V_2 ) ) {
F_21 ( V_2 , V_80 ) ;
return;
}
switch ( V_80 ) {
case V_82 :
F_12 ( V_2 , V_92 ,
V_93 ) ;
break;
case V_85 :
F_12 ( V_2 , V_92 ,
V_94 ) ;
break;
case V_88 :
F_12 ( V_2 , V_92 ,
V_95 ) ;
break;
default:
F_22 ( F_23 ( V_2 ) , V_91 ,
L_1 ) ;
break;
}
F_17 ( V_2 ) ;
}
