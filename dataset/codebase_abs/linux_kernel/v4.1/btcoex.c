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
bool V_18 = V_7 . V_14 ;
if ( F_2 ( V_2 ) )
V_18 = ! V_7 . V_14 ;
V_5 -> V_19 =
( V_5 -> V_19 & V_20 ) |
F_3 ( V_7 . V_8 , V_21 ) |
F_3 ( V_7 . V_9 , V_22 ) |
F_3 ( V_7 . V_10 , V_23 ) |
F_3 ( V_7 . V_11 , V_24 ) |
F_3 ( V_7 . V_13 , V_25 ) |
F_3 ( V_18 , V_26 ) |
F_3 ( V_7 . V_15 , V_27 ) |
F_3 ( V_7 . V_16 , V_28 ) |
F_3 ( V_3 , V_20 ) ;
V_5 -> V_29 =
F_3 ( V_7 . V_17 , V_30 ) |
F_3 ( V_31 , V_32 ) |
V_33 ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_34 * V_35 = F_5 ( V_2 ) ;
struct V_4 * V_5 = & V_2 -> V_5 ;
if ( ! V_35 -> V_36 ) {
V_5 -> V_37 = V_38 ;
return;
}
if ( V_2 -> V_39 . V_40 & V_41 ) {
V_5 -> V_37 = V_42 ;
} else if ( F_2 ( V_2 ) ) {
V_5 -> V_37 = V_43 ;
V_5 -> V_44 = V_45 ;
V_5 -> V_46 = V_47 ;
V_5 -> V_48 = V_49 ;
} else if ( F_6 ( V_2 ) ) {
V_5 -> V_44 = V_50 ;
V_5 -> V_46 = V_51 ;
if ( F_7 ( V_2 ) ) {
V_5 -> V_37 = V_43 ;
V_5 -> V_48 = V_52 ;
} else {
V_5 -> V_37 = V_53 ;
}
}
}
void F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_9 ( V_2 , V_54 ,
( V_55 |
V_56 ) ) ;
F_10 ( V_2 , V_54 ,
V_57 ) ;
F_11 ( V_2 , V_58 ,
V_59 ,
V_5 -> V_44 ) ;
F_12 ( V_2 , V_5 -> V_44 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_10 ( V_2 , V_54 ,
( V_60 |
V_57 ) ) ;
F_11 ( V_2 , V_58 ,
V_59 ,
V_5 -> V_44 ) ;
F_11 ( V_2 , V_58 ,
V_61 ,
V_5 -> V_48 ) ;
F_12 ( V_2 , V_5 -> V_44 ) ;
F_12 ( V_2 , V_5 -> V_48 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_62 . V_63 = false ;
V_2 -> V_5 . V_62 . V_64 = 0 ;
V_2 -> V_5 . V_62 . V_65 = 3 ;
V_2 -> V_5 . V_62 . V_66 = 0 ;
V_2 -> V_5 . V_62 . V_67 = false ;
V_2 -> V_5 . V_62 . V_68 = true ;
V_2 -> V_5 . V_62 . V_69 = true ;
V_2 -> V_5 . V_62 . V_70 = false ;
V_2 -> V_5 . V_62 . V_71 [ 0 ] = 0x00000000 ;
V_2 -> V_5 . V_62 . V_71 [ 1 ] = 0xffffffff ;
V_2 -> V_5 . V_62 . V_71 [ 2 ] = 0xffffffff ;
V_2 -> V_5 . V_62 . V_71 [ 3 ] = 0x7fffffff ;
V_2 -> V_5 . V_62 . V_72 = true ;
V_2 -> V_5 . V_62 . V_73 = true ;
V_2 -> V_5 . V_62 . V_74 = false ;
V_2 -> V_5 . V_62 . V_75 = false ;
V_2 -> V_5 . V_62 . V_76 = 0 ;
V_2 -> V_5 . V_62 . V_77 = 0 ;
V_2 -> V_5 . V_62 . V_78 = ( F_15 ( V_2 ) ) ? 0x2201 : 0xa4c1 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_17 ( V_2 , V_5 -> V_46 ,
V_79 ) ;
}
void F_18 ( struct V_1 * V_2 ,
T_1 V_80 ,
T_1 V_81 ,
enum V_82 V_83 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_84 * V_85 = & V_2 -> V_5 . V_62 ;
T_2 V_86 [] = { 24 , 16 , 16 , 0 } ;
bool V_87 = ( V_85 -> V_87 && V_5 -> V_88 [ V_83 ] ) ;
const T_1 * V_89 = V_90 [ V_83 ] ;
int V_91 ;
if ( ! F_2 ( V_2 ) ) {
V_5 -> V_92 =
F_3 ( V_80 , V_93 ) |
F_3 ( V_81 , V_94 ) ;
return;
}
if ( F_15 ( V_2 ) || F_19 ( V_2 ) ) {
enum V_82 V_95 =
( ( V_83 == V_96 ) &&
V_5 -> V_62 . V_97 ) ?
V_98 : V_83 ;
V_89 = V_99 [ V_95 ] ;
}
for ( V_91 = 0 ; V_91 < V_100 ; V_91 ++ ) {
V_5 -> V_80 [ V_91 ] = V_101 ;
V_5 -> V_81 [ V_91 ] = V_89 [ V_91 ] ;
if ( V_87 && V_91 ) {
V_5 -> V_81 [ V_91 ] &=
~ ( 0xff << V_86 [ V_91 - 1 ] ) ;
V_5 -> V_81 [ V_91 ] |=
( V_5 -> V_88 [ V_83 ] <<
V_86 [ V_91 - 1 ] ) ;
}
}
if ( V_87 ) {
V_5 -> V_81 [ V_91 - 1 ] &= ~ ( 0xff << V_86 [ V_91 - 1 ] ) ;
V_5 -> V_81 [ V_91 - 1 ] |= ( V_5 -> V_88 [ V_83 ]
<< V_86 [ V_91 - 1 ] ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_102 = & V_2 -> V_5 ;
T_1 V_103 ;
int V_91 ;
F_21 ( V_2 , V_104 , V_102 -> V_19 ) ;
F_21 ( V_2 , V_105 , V_102 -> V_29 ) ;
if ( F_2 ( V_2 ) ) {
F_21 ( V_2 , V_106 , V_102 -> V_81 [ 0 ] ) ;
F_21 ( V_2 , V_107 , V_102 -> V_81 [ 1 ] ) ;
for ( V_91 = 0 ; V_91 < V_108 ; V_91 ++ )
F_21 ( V_2 , F_22 ( V_91 ) ,
V_102 -> V_80 [ V_91 ] ) ;
} else
F_21 ( V_2 , V_109 , V_102 -> V_92 ) ;
if ( F_23 ( V_2 ) ) {
V_103 = F_24 ( V_2 , 0x50040 ) ;
V_103 &= 0xFFFFFEFF ;
F_21 ( V_2 , 0x50040 , V_103 ) ;
}
F_11 ( V_2 , V_110 , V_111 , 1 ) ;
F_11 ( V_2 , V_112 , V_113 , 0 ) ;
F_17 ( V_2 , V_102 -> V_46 ,
V_114 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_102 = & V_2 -> V_5 ;
int V_91 ;
for ( V_91 = 0 ; V_91 < V_108 ; V_91 ++ )
F_21 ( V_2 , F_26 ( V_91 ) ,
V_102 -> V_81 [ V_91 ] ) ;
F_11 ( V_2 , V_110 , V_111 , 1 ) ;
V_102 -> V_115 = true ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_91 ;
F_28 ( V_2 , V_116 ) ;
for ( V_91 = 0 ; V_91 < V_108 ; V_91 ++ )
F_21 ( V_2 , F_26 ( V_91 ) ,
V_5 -> V_81 [ V_91 ] ) ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
switch ( F_30 ( V_2 ) ) {
case V_38 :
return;
case V_53 :
F_16 ( V_2 ) ;
break;
case V_43 :
F_20 ( V_2 ) ;
break;
case V_42 :
F_25 ( V_2 ) ;
break;
}
if ( F_30 ( V_2 ) != V_42 ) {
F_31 ( V_2 , V_117 ,
( 0x2 << ( V_5 -> V_44 * 2 ) ) ,
( 0x3 << ( V_5 -> V_44 * 2 ) ) ) ;
}
V_2 -> V_5 . V_115 = true ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_91 ;
V_5 -> V_115 = false ;
if ( F_30 ( V_2 ) == V_42 ) {
F_27 ( V_2 ) ;
return;
}
if ( ! F_2 ( V_2 ) )
F_33 ( V_2 , V_5 -> V_46 , 0 ) ;
F_17 ( V_2 , V_5 -> V_46 ,
V_118 ) ;
if ( V_5 -> V_37 == V_43 ) {
F_21 ( V_2 , V_104 , V_25 | V_24 ) ;
F_21 ( V_2 , V_105 , 0 ) ;
if ( F_2 ( V_2 ) ) {
F_21 ( V_2 , V_106 , 0 ) ;
F_21 ( V_2 , V_107 , 0 ) ;
for ( V_91 = 0 ; V_91 < V_108 ; V_91 ++ )
F_21 ( V_2 , F_22 ( V_91 ) , 0 ) ;
} else
F_21 ( V_2 , V_109 , 0 ) ;
}
}
void F_28 ( struct V_1 * V_2 ,
enum V_82 V_83 )
{
if ( F_2 ( V_2 ) ) {
F_18 ( V_2 , 0 , 0 , V_83 ) ;
return;
}
switch ( V_83 ) {
case V_119 :
F_18 ( V_2 , V_120 ,
V_121 , 0 ) ;
break;
case V_96 :
F_18 ( V_2 , V_120 ,
V_122 , 0 ) ;
break;
case V_116 :
F_18 ( V_2 , V_120 ,
V_123 , 0 ) ;
break;
default:
F_34 ( F_5 ( V_2 ) , V_124 , L_1 ) ;
break;
}
}
void F_35 ( struct V_1 * V_2 , T_2 * V_125 )
{
struct V_4 * V_102 = & V_2 -> V_5 ;
int V_91 ;
for ( V_91 = 0 ; V_91 < V_126 ; V_91 ++ )
V_102 -> V_88 [ V_91 ] = V_125 [ V_91 ] ;
}
