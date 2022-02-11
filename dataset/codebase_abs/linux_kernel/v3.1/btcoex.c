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
T_1 V_18 , V_19 ;
bool V_20 = V_7 . V_14 ;
if ( F_2 ( V_2 ) )
V_20 = ! V_7 . V_14 ;
V_5 -> V_21 =
( V_5 -> V_21 & V_22 ) |
F_3 ( V_7 . V_8 , V_23 ) |
F_3 ( V_7 . V_9 , V_24 ) |
F_3 ( V_7 . V_10 , V_25 ) |
F_3 ( V_7 . V_11 , V_26 ) |
F_3 ( V_7 . V_13 , V_27 ) |
F_3 ( V_20 , V_28 ) |
F_3 ( V_7 . V_15 , V_29 ) |
F_3 ( V_7 . V_16 , V_30 ) |
F_3 ( V_3 , V_22 ) ;
V_5 -> V_31 =
F_3 ( V_7 . V_17 , V_32 ) |
F_3 ( V_33 , V_34 ) |
V_35 ;
for ( V_18 = 0 ; V_18 < 32 ; V_18 ++ ) {
V_19 = ( V_36 << V_18 ) >> 27 ;
V_2 -> V_37 . V_38 [ V_19 ] = V_18 ;
}
}
void F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_5 ( V_2 , V_39 ,
( V_40 |
V_41 ) ) ;
F_6 ( V_2 , V_39 ,
V_42 ) ;
F_7 ( V_2 , V_43 ,
V_44 ,
V_5 -> V_45 ) ;
F_8 ( V_2 , V_5 -> V_45 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_6 ( V_2 , V_39 ,
( V_46 |
V_42 ) ) ;
F_7 ( V_2 , V_43 ,
V_44 ,
V_5 -> V_45 ) ;
F_7 ( V_2 , V_43 ,
V_47 ,
V_5 -> V_48 ) ;
F_8 ( V_2 , V_5 -> V_45 ) ;
F_8 ( V_2 , V_5 -> V_48 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_11 ( V_2 , V_5 -> V_49 ,
V_50 ) ;
}
void F_12 ( struct V_1 * V_2 ,
T_1 V_51 ,
T_1 V_52 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
V_5 -> V_53 = F_3 ( V_51 , V_54 ) |
F_3 ( V_52 , V_55 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
T_1 V_56 ;
F_14 ( V_2 , V_57 , V_5 -> V_21 ) ;
F_14 ( V_2 , V_58 , V_5 -> V_31 ) ;
if ( F_2 ( V_2 ) ) {
F_14 ( V_2 , V_59 , V_2 -> V_60 [ 0 ] ) ;
F_14 ( V_2 , V_61 , V_2 -> V_60 [ 1 ] ) ;
F_14 ( V_2 , V_62 , V_2 -> V_63 [ 0 ] ) ;
F_14 ( V_2 , V_64 , V_2 -> V_63 [ 1 ] ) ;
F_14 ( V_2 , V_65 , V_2 -> V_63 [ 2 ] ) ;
F_14 ( V_2 , V_66 , V_2 -> V_63 [ 3 ] ) ;
} else
F_14 ( V_2 , V_67 , V_5 -> V_53 ) ;
if ( F_15 ( V_2 ) ) {
V_56 = F_16 ( V_2 , 0x50040 ) ;
V_56 &= 0xFFFFFEFF ;
F_14 ( V_2 , 0x50040 , V_56 ) ;
}
F_7 ( V_2 , V_68 , V_69 , 1 ) ;
F_7 ( V_2 , V_70 , V_71 , 0 ) ;
F_11 ( V_2 , V_5 -> V_49 ,
V_72 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
switch ( V_5 -> V_73 ) {
case V_74 :
break;
case V_75 :
F_10 ( V_2 ) ;
break;
case V_76 :
F_13 ( V_2 ) ;
break;
}
F_18 ( V_2 , V_77 ,
( 0x2 << ( V_5 -> V_45 * 2 ) ) ,
( 0x3 << ( V_5 -> V_45 * 2 ) ) ) ;
V_2 -> V_5 . V_78 = true ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_20 ( V_2 , V_5 -> V_49 , 0 ) ;
F_11 ( V_2 , V_5 -> V_49 ,
V_79 ) ;
if ( V_5 -> V_73 == V_76 ) {
F_14 ( V_2 , V_57 , V_27 | V_26 ) ;
F_14 ( V_2 , V_58 , 0 ) ;
if ( F_2 ( V_2 ) ) {
F_14 ( V_2 , V_59 , 0 ) ;
F_14 ( V_2 , V_61 , 0 ) ;
F_14 ( V_2 , V_62 , 0 ) ;
F_14 ( V_2 , V_64 , 0 ) ;
F_14 ( V_2 , V_65 , 0 ) ;
F_14 ( V_2 , V_66 , 0 ) ;
} else
F_14 ( V_2 , V_67 , 0 ) ;
}
V_2 -> V_5 . V_78 = false ;
}
static void F_21 ( struct V_1 * V_2 ,
enum V_80 V_81 )
{
V_2 -> V_63 [ 0 ] = V_82 ;
V_2 -> V_63 [ 1 ] = V_82 ;
V_2 -> V_63 [ 2 ] = V_82 ;
V_2 -> V_63 [ 3 ] = V_82 ;
switch ( V_81 ) {
case V_83 :
V_2 -> V_60 [ 0 ] = V_84 ;
V_2 -> V_60 [ 1 ] = V_85 ;
break;
case V_86 :
V_2 -> V_60 [ 0 ] = V_87 ;
V_2 -> V_60 [ 1 ] = V_88 ;
break;
case V_89 :
V_2 -> V_60 [ 0 ] = V_90 ;
V_2 -> V_60 [ 1 ] = V_91 ;
break;
default:
F_22 ( F_23 ( V_2 ) , V_92 ,
L_1 ) ;
break;
}
F_17 ( V_2 ) ;
}
void F_24 ( struct V_1 * V_2 ,
enum V_80 V_81 )
{
if ( F_2 ( V_2 ) ) {
F_21 ( V_2 , V_81 ) ;
return;
}
switch ( V_81 ) {
case V_83 :
F_12 ( V_2 , V_93 ,
V_94 ) ;
break;
case V_86 :
F_12 ( V_2 , V_93 ,
V_95 ) ;
break;
case V_89 :
F_12 ( V_2 , V_93 ,
V_96 ) ;
break;
default:
F_22 ( F_23 ( V_2 ) , V_92 ,
L_1 ) ;
break;
}
F_17 ( V_2 ) ;
}
