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
if ( F_2 ( V_2 ) ) {
V_5 -> V_42 = V_44 ;
V_5 -> V_45 = V_46 ;
V_5 -> V_47 = V_48 ;
V_5 -> V_49 = V_50 ;
} else if ( F_6 ( V_2 ) ) {
V_5 -> V_45 = V_51 ;
V_5 -> V_47 = V_52 ;
if ( F_7 ( V_2 ) ) {
V_5 -> V_42 = V_44 ;
V_5 -> V_49 = V_53 ;
} else {
V_5 -> V_42 = V_54 ;
}
}
}
void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_9 ( V_2 , V_55 ,
( V_56 |
V_57 ) ) ;
F_10 ( V_2 , V_55 ,
V_58 ) ;
F_11 ( V_2 , V_59 ,
V_60 ,
V_5 -> V_45 ) ;
F_12 ( V_2 , V_5 -> V_45 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_10 ( V_2 , V_55 ,
( V_61 |
V_58 ) ) ;
F_11 ( V_2 , V_59 ,
V_60 ,
V_5 -> V_45 ) ;
F_11 ( V_2 , V_59 ,
V_62 ,
V_5 -> V_49 ) ;
F_12 ( V_2 , V_5 -> V_45 ) ;
F_12 ( V_2 , V_5 -> V_49 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_63 . V_64 = false ;
V_2 -> V_5 . V_63 . V_65 = 0 ;
V_2 -> V_5 . V_63 . V_66 = 3 ;
V_2 -> V_5 . V_63 . V_67 = 0 ;
V_2 -> V_5 . V_63 . V_68 = false ;
V_2 -> V_5 . V_63 . V_69 = true ;
V_2 -> V_5 . V_63 . V_70 = true ;
V_2 -> V_5 . V_63 . V_71 = false ;
V_2 -> V_5 . V_63 . V_72 [ 0 ] = 0x00000000 ;
V_2 -> V_5 . V_63 . V_72 [ 1 ] = 0xffffffff ;
V_2 -> V_5 . V_63 . V_72 [ 2 ] = 0xffffffff ;
V_2 -> V_5 . V_63 . V_72 [ 3 ] = 0x7fffffff ;
V_2 -> V_5 . V_63 . V_73 = true ;
V_2 -> V_5 . V_63 . V_74 = true ;
V_2 -> V_5 . V_63 . V_75 = false ;
V_2 -> V_5 . V_63 . V_76 = false ;
V_2 -> V_5 . V_63 . V_77 = 0 ;
V_2 -> V_5 . V_63 . V_78 = 0 ;
V_2 -> V_5 . V_63 . V_79 = ( F_15 ( V_2 ) ) ? 0x2201 : 0xa4c1 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_17 ( V_2 , V_5 -> V_47 ,
V_80 ) ;
}
void F_18 ( struct V_1 * V_2 ,
T_1 V_81 ,
T_1 V_82 ,
enum V_83 V_84 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_85 * V_86 = & V_2 -> V_5 . V_63 ;
T_2 V_87 [] = { 24 , 16 , 16 , 0 } ;
bool V_88 = ( V_86 -> V_88 && V_5 -> V_89 [ V_84 ] ) ;
const T_1 * V_90 = V_91 [ V_84 ] ;
int V_18 ;
if ( ! F_2 ( V_2 ) ) {
V_5 -> V_92 =
F_3 ( V_81 , V_93 ) |
F_3 ( V_82 , V_94 ) ;
return;
}
if ( F_15 ( V_2 ) || F_19 ( V_2 ) ) {
enum V_83 V_95 =
( ( V_84 == V_96 ) &&
V_5 -> V_63 . V_97 ) ?
V_98 : V_84 ;
V_90 = V_99 [ V_95 ] ;
}
for ( V_18 = 0 ; V_18 < V_100 ; V_18 ++ ) {
V_5 -> V_81 [ V_18 ] = V_101 ;
V_5 -> V_82 [ V_18 ] = V_90 [ V_18 ] ;
if ( V_88 && V_18 ) {
V_5 -> V_82 [ V_18 ] &=
~ ( 0xff << V_87 [ V_18 - 1 ] ) ;
V_5 -> V_82 [ V_18 ] |=
( V_5 -> V_89 [ V_84 ] <<
V_87 [ V_18 - 1 ] ) ;
}
}
if ( V_88 ) {
V_5 -> V_82 [ V_18 - 1 ] &= ~ ( 0xff << V_87 [ V_18 - 1 ] ) ;
V_5 -> V_82 [ V_18 - 1 ] |= ( V_5 -> V_89 [ V_84 ]
<< V_87 [ V_18 - 1 ] ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_102 = & V_2 -> V_5 ;
T_1 V_103 ;
int V_18 ;
F_21 ( V_2 , V_104 , V_102 -> V_21 ) ;
F_21 ( V_2 , V_105 , V_102 -> V_31 ) ;
if ( F_2 ( V_2 ) ) {
F_21 ( V_2 , V_106 , V_102 -> V_82 [ 0 ] ) ;
F_21 ( V_2 , V_107 , V_102 -> V_82 [ 1 ] ) ;
for ( V_18 = 0 ; V_18 < V_108 ; V_18 ++ )
F_21 ( V_2 , F_22 ( V_18 ) ,
V_102 -> V_81 [ V_18 ] ) ;
} else
F_21 ( V_2 , V_109 , V_102 -> V_92 ) ;
if ( F_23 ( V_2 ) ) {
V_103 = F_24 ( V_2 , 0x50040 ) ;
V_103 &= 0xFFFFFEFF ;
F_21 ( V_2 , 0x50040 , V_103 ) ;
}
F_11 ( V_2 , V_110 , V_111 , 1 ) ;
F_11 ( V_2 , V_112 , V_113 , 0 ) ;
F_17 ( V_2 , V_102 -> V_47 ,
V_114 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_102 = & V_2 -> V_5 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_108 ; V_18 ++ )
F_21 ( V_2 , F_26 ( V_18 ) ,
V_102 -> V_82 [ V_18 ] ) ;
F_11 ( V_2 , V_110 , V_111 , 1 ) ;
V_102 -> V_115 = true ;
}
void F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
switch ( F_28 ( V_2 ) ) {
case V_43 :
return;
case V_54 :
F_16 ( V_2 ) ;
break;
case V_44 :
if ( F_15 ( V_2 ) || F_19 ( V_2 ) ) {
F_25 ( V_2 ) ;
return;
}
F_20 ( V_2 ) ;
break;
}
F_29 ( V_2 , V_116 ,
( 0x2 << ( V_5 -> V_45 * 2 ) ) ,
( 0x3 << ( V_5 -> V_45 * 2 ) ) ) ;
V_2 -> V_5 . V_115 = true ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_18 ;
V_5 -> V_115 = false ;
if ( F_15 ( V_2 ) || F_19 ( V_2 ) ) {
F_31 ( V_2 , V_117 ) ;
for ( V_18 = 0 ; V_18 < V_108 ; V_18 ++ )
F_21 ( V_2 , F_26 ( V_18 ) ,
V_5 -> V_82 [ V_18 ] ) ;
return;
}
F_32 ( V_2 , V_5 -> V_47 , 0 ) ;
F_17 ( V_2 , V_5 -> V_47 ,
V_118 ) ;
if ( V_5 -> V_42 == V_44 ) {
F_21 ( V_2 , V_104 , V_27 | V_26 ) ;
F_21 ( V_2 , V_105 , 0 ) ;
if ( F_2 ( V_2 ) ) {
F_21 ( V_2 , V_106 , 0 ) ;
F_21 ( V_2 , V_107 , 0 ) ;
for ( V_18 = 0 ; V_18 < V_108 ; V_18 ++ )
F_21 ( V_2 , F_22 ( V_18 ) , 0 ) ;
} else
F_21 ( V_2 , V_109 , 0 ) ;
}
}
void F_31 ( struct V_1 * V_2 ,
enum V_83 V_84 )
{
if ( F_2 ( V_2 ) ) {
F_18 ( V_2 , 0 , 0 , V_84 ) ;
return;
}
switch ( V_84 ) {
case V_119 :
F_18 ( V_2 , V_120 ,
V_121 , 0 ) ;
break;
case V_96 :
F_18 ( V_2 , V_120 ,
V_122 , 0 ) ;
break;
case V_117 :
F_18 ( V_2 , V_120 ,
V_123 , 0 ) ;
break;
default:
F_33 ( F_5 ( V_2 ) , V_124 , L_1 ) ;
break;
}
}
void F_34 ( struct V_1 * V_2 , T_2 * V_125 )
{
struct V_4 * V_102 = & V_2 -> V_5 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_126 ; V_18 ++ )
V_102 -> V_89 [ V_18 ] = V_125 [ V_18 ] ;
}
