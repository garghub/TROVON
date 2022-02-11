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
V_2 -> V_5 . V_63 . V_79 = 0x2201 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
F_16 ( V_2 , V_5 -> V_47 ,
V_80 ) ;
}
void F_17 ( struct V_1 * V_2 ,
T_1 V_81 ,
T_1 V_82 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
V_5 -> V_83 = F_3 ( V_81 , V_84 ) |
F_3 ( V_82 , V_85 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_86 = & V_2 -> V_5 ;
T_1 V_87 ;
int V_18 ;
F_19 ( V_2 , V_88 , V_86 -> V_21 ) ;
F_19 ( V_2 , V_89 , V_86 -> V_31 ) ;
if ( F_2 ( V_2 ) ) {
F_19 ( V_2 , V_90 , V_86 -> V_82 [ 0 ] ) ;
F_19 ( V_2 , V_91 , V_86 -> V_82 [ 1 ] ) ;
for ( V_18 = 0 ; V_18 < V_92 ; V_18 ++ )
F_19 ( V_2 , F_20 ( V_18 ) ,
V_86 -> V_81 [ V_18 ] ) ;
} else
F_19 ( V_2 , V_93 , V_86 -> V_83 ) ;
if ( F_21 ( V_2 ) ) {
V_87 = F_22 ( V_2 , 0x50040 ) ;
V_87 &= 0xFFFFFEFF ;
F_19 ( V_2 , 0x50040 , V_87 ) ;
}
F_11 ( V_2 , V_94 , V_95 , 1 ) ;
F_11 ( V_2 , V_96 , V_97 , 0 ) ;
F_16 ( V_2 , V_86 -> V_47 ,
V_98 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_4 * V_86 = & V_2 -> V_5 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_92 ; V_18 ++ )
F_19 ( V_2 , F_24 ( V_18 ) ,
V_86 -> V_82 [ V_18 ] ) ;
F_11 ( V_2 , V_94 , V_95 , 1 ) ;
V_86 -> V_99 = true ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
switch ( F_26 ( V_2 ) ) {
case V_43 :
return;
case V_54 :
F_15 ( V_2 ) ;
break;
case V_44 :
if ( F_27 ( V_2 ) ) {
F_23 ( V_2 ) ;
return;
}
F_18 ( V_2 ) ;
break;
}
F_28 ( V_2 , V_100 ,
( 0x2 << ( V_5 -> V_45 * 2 ) ) ,
( 0x3 << ( V_5 -> V_45 * 2 ) ) ) ;
V_2 -> V_5 . V_99 = true ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_5 ;
int V_18 ;
V_5 -> V_99 = false ;
if ( F_27 ( V_2 ) ) {
F_30 ( V_2 , V_101 ) ;
for ( V_18 = 0 ; V_18 < V_92 ; V_18 ++ )
F_19 ( V_2 , F_24 ( V_18 ) ,
V_5 -> V_82 [ V_18 ] ) ;
return;
}
F_31 ( V_2 , V_5 -> V_47 , 0 ) ;
F_16 ( V_2 , V_5 -> V_47 ,
V_102 ) ;
if ( V_5 -> V_42 == V_44 ) {
F_19 ( V_2 , V_88 , V_27 | V_26 ) ;
F_19 ( V_2 , V_89 , 0 ) ;
if ( F_2 ( V_2 ) ) {
F_19 ( V_2 , V_90 , 0 ) ;
F_19 ( V_2 , V_91 , 0 ) ;
for ( V_18 = 0 ; V_18 < V_92 ; V_18 ++ )
F_19 ( V_2 , F_20 ( V_18 ) , 0 ) ;
} else
F_19 ( V_2 , V_93 , 0 ) ;
}
}
static void F_32 ( struct V_1 * V_2 ,
enum V_103 V_104 )
{
struct V_4 * V_86 = & V_2 -> V_5 ;
const T_1 * V_105 = F_27 ( V_2 ) ? V_106 [ V_104 ] :
V_107 [ V_104 ] ;
int V_18 ;
for ( V_18 = 0 ; V_18 < V_108 ; V_18 ++ ) {
V_86 -> V_81 [ V_18 ] = V_109 ;
V_86 -> V_82 [ V_18 ] = V_105 [ V_18 ] ;
}
}
void F_30 ( struct V_1 * V_2 ,
enum V_103 V_104 )
{
if ( F_2 ( V_2 ) ) {
F_32 ( V_2 , V_104 ) ;
return;
}
switch ( V_104 ) {
case V_110 :
F_17 ( V_2 , V_111 ,
V_112 ) ;
break;
case V_113 :
F_17 ( V_2 , V_111 ,
V_114 ) ;
break;
case V_101 :
F_17 ( V_2 , V_111 ,
V_115 ) ;
break;
default:
F_33 ( F_5 ( V_2 ) , V_116 , L_1 ) ;
break;
}
}
