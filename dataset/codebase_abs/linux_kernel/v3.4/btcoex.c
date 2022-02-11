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
struct V_39 * V_40 = F_5 ( V_2 ) ;
struct V_4 * V_5 = & V_2 -> V_5 ;
if ( ! V_40 -> V_41 ) {
V_5 -> V_42 = V_43 ;
return;
}
if ( F_6 ( V_2 ) ) {
V_5 -> V_42 = V_44 ;
} else if ( F_2 ( V_2 ) ) {
V_5 -> V_42 = V_45 ;
V_5 -> V_46 = V_47 ;
V_5 -> V_48 = V_49 ;
V_5 -> V_50 = V_51 ;
} else if ( F_7 ( V_2 ) ) {
V_5 -> V_46 = V_52 ;
V_5 -> V_48 = V_53 ;
if ( F_8 ( V_2 ) ) {
V_5 -> V_42 = V_45 ;
V_5 -> V_50 = V_54 ;
} else {
V_5 -> V_42 = V_55 ;
}
}
}
void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_10 ( V_2 , V_56 ,
( V_57 |
V_58 ) ) ;
F_11 ( V_2 , V_56 ,
V_59 ) ;
F_12 ( V_2 , V_60 ,
V_61 ,
V_5 -> V_46 ) ;
F_13 ( V_2 , V_5 -> V_46 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_11 ( V_2 , V_56 ,
( V_62 |
V_59 ) ) ;
F_12 ( V_2 , V_60 ,
V_61 ,
V_5 -> V_46 ) ;
F_12 ( V_2 , V_60 ,
V_63 ,
V_5 -> V_50 ) ;
F_13 ( V_2 , V_5 -> V_46 ) ;
F_13 ( V_2 , V_5 -> V_50 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_64 . V_65 = false ;
V_2 -> V_5 . V_64 . V_66 = 0 ;
V_2 -> V_5 . V_64 . V_67 = 3 ;
V_2 -> V_5 . V_64 . V_68 = 0 ;
V_2 -> V_5 . V_64 . V_69 = false ;
V_2 -> V_5 . V_64 . V_70 = true ;
V_2 -> V_5 . V_64 . V_71 = true ;
V_2 -> V_5 . V_64 . V_72 = false ;
V_2 -> V_5 . V_64 . V_73 [ 0 ] = 0x00000000 ;
V_2 -> V_5 . V_64 . V_73 [ 1 ] = 0xffffffff ;
V_2 -> V_5 . V_64 . V_73 [ 2 ] = 0xffffffff ;
V_2 -> V_5 . V_64 . V_73 [ 3 ] = 0x7fffffff ;
V_2 -> V_5 . V_64 . V_74 = true ;
V_2 -> V_5 . V_64 . V_75 = true ;
V_2 -> V_5 . V_64 . V_76 = false ;
V_2 -> V_5 . V_64 . V_77 = false ;
V_2 -> V_5 . V_64 . V_78 = 0 ;
V_2 -> V_5 . V_64 . V_79 = 0 ;
V_2 -> V_5 . V_64 . V_80 = 0x2201 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_17 ( V_2 , V_5 -> V_48 ,
V_81 ) ;
}
void F_18 ( struct V_1 * V_2 ,
T_1 V_82 ,
T_1 V_83 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
V_5 -> V_84 = F_3 ( V_82 , V_85 ) |
F_3 ( V_83 , V_86 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_87 = & V_2 -> V_5 ;
T_1 V_88 ;
int V_18 ;
F_20 ( V_2 , V_89 , V_87 -> V_21 ) ;
F_20 ( V_2 , V_90 , V_87 -> V_31 ) ;
if ( F_2 ( V_2 ) ) {
F_20 ( V_2 , V_91 , V_87 -> V_83 [ 0 ] ) ;
F_20 ( V_2 , V_92 , V_87 -> V_83 [ 1 ] ) ;
for ( V_18 = 0 ; V_18 < V_93 ; V_18 ++ )
F_20 ( V_2 , F_21 ( V_18 ) ,
V_87 -> V_82 [ V_18 ] ) ;
} else
F_20 ( V_2 , V_94 , V_87 -> V_84 ) ;
if ( F_22 ( V_2 ) ) {
V_88 = F_23 ( V_2 , 0x50040 ) ;
V_88 &= 0xFFFFFEFF ;
F_20 ( V_2 , 0x50040 , V_88 ) ;
}
F_12 ( V_2 , V_95 , V_96 , 1 ) ;
F_12 ( V_2 , V_97 , V_98 , 0 ) ;
F_17 ( V_2 , V_87 -> V_48 ,
V_99 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_87 = & V_2 -> V_5 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_93 ; V_18 ++ )
F_20 ( V_2 , F_25 ( V_18 ) ,
V_87 -> V_83 [ V_18 ] ) ;
F_12 ( V_2 , V_95 , V_96 , 1 ) ;
V_87 -> V_100 = true ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
switch ( F_27 ( V_2 ) ) {
case V_43 :
return;
case V_55 :
F_16 ( V_2 ) ;
break;
case V_45 :
F_19 ( V_2 ) ;
break;
case V_44 :
F_24 ( V_2 ) ;
return;
}
F_28 ( V_2 , V_101 ,
( 0x2 << ( V_5 -> V_46 * 2 ) ) ,
( 0x3 << ( V_5 -> V_46 * 2 ) ) ) ;
V_2 -> V_5 . V_100 = true ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_18 ;
V_5 -> V_100 = false ;
if ( V_5 -> V_42 == V_44 ) {
F_30 ( V_2 , V_102 ) ;
for ( V_18 = 0 ; V_18 < V_93 ; V_18 ++ )
F_20 ( V_2 , F_25 ( V_18 ) ,
V_5 -> V_83 [ V_18 ] ) ;
}
F_31 ( V_2 , V_5 -> V_48 , 0 ) ;
F_17 ( V_2 , V_5 -> V_48 ,
V_103 ) ;
if ( V_5 -> V_42 == V_45 ) {
F_20 ( V_2 , V_89 , V_27 | V_26 ) ;
F_20 ( V_2 , V_90 , 0 ) ;
if ( F_2 ( V_2 ) ) {
F_20 ( V_2 , V_91 , 0 ) ;
F_20 ( V_2 , V_92 , 0 ) ;
for ( V_18 = 0 ; V_18 < V_93 ; V_18 ++ )
F_20 ( V_2 , F_21 ( V_18 ) , 0 ) ;
} else
F_20 ( V_2 , V_94 , 0 ) ;
}
}
static void F_32 ( struct V_1 * V_2 ,
enum V_104 V_105 )
{
struct V_4 * V_87 = & V_2 -> V_5 ;
const T_1 * V_106 = F_6 ( V_2 ) ? V_107 [ V_105 ] :
V_108 [ V_105 ] ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_109 ; V_18 ++ ) {
V_87 -> V_82 [ V_18 ] = V_110 ;
V_87 -> V_83 [ V_18 ] = V_106 [ V_18 ] ;
}
}
void F_30 ( struct V_1 * V_2 ,
enum V_104 V_105 )
{
if ( F_2 ( V_2 ) ) {
F_32 ( V_2 , V_105 ) ;
return;
}
switch ( V_105 ) {
case V_111 :
F_18 ( V_2 , V_112 ,
V_113 ) ;
break;
case V_114 :
F_18 ( V_2 , V_112 ,
V_115 ) ;
break;
case V_102 :
F_18 ( V_2 , V_112 ,
V_116 ) ;
break;
default:
F_33 ( F_5 ( V_2 ) , V_117 , L_1 ) ;
break;
}
}
