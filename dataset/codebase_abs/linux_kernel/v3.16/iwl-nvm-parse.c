static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 ,
const T_1 * const V_7 )
{
int V_8 ;
int V_9 = 0 ;
struct V_10 * V_11 ;
T_2 V_12 ;
bool V_13 ;
int V_14 , V_15 ;
const T_3 * V_16 ;
if ( V_4 -> V_17 != V_18 ) {
V_14 = V_19 ;
V_16 = & V_20 [ 0 ] ;
V_15 = V_21 ;
} else {
V_14 = V_22 ;
V_16 = & V_23 [ 0 ] ;
V_15 = V_24 ;
}
for ( V_8 = 0 ; V_8 < V_14 ; V_8 ++ ) {
V_12 = F_2 ( V_7 + V_8 ) ;
if ( V_8 >= V_15 &&
! V_6 -> V_25 )
V_12 &= ~ V_26 ;
if ( ! ( V_12 & V_26 ) ) {
F_3 ( V_2 ,
L_1 ,
V_16 [ V_8 ] ,
V_12 ,
( V_8 >= V_15 ) ?
L_2 : L_3 ) ;
continue;
}
V_11 = & V_6 -> V_27 [ V_9 ] ;
V_9 ++ ;
V_11 -> V_28 = V_16 [ V_8 ] ;
V_11 -> V_29 = ( V_8 < V_15 ) ?
V_30 : V_31 ;
V_11 -> V_32 =
F_4 (
V_11 -> V_28 , V_11 -> V_29 ) ;
V_11 -> V_33 = V_34 ;
if ( V_8 < V_15 &&
( V_12 & V_35 ) ) {
if ( V_16 [ V_8 ] <= V_36 )
V_11 -> V_33 &= ~ V_37 ;
if ( V_16 [ V_8 ] >= V_38 )
V_11 -> V_33 &= ~ V_39 ;
} else if ( V_16 [ V_8 ] <= V_40 &&
( V_12 & V_35 ) ) {
if ( ( V_8 - V_15 ) % 2 == 0 )
V_11 -> V_33 &= ~ V_37 ;
else
V_11 -> V_33 &= ~ V_39 ;
}
if ( ! ( V_12 & V_41 ) )
V_11 -> V_33 |= V_42 ;
if ( ! ( V_12 & V_43 ) )
V_11 -> V_33 |= V_44 ;
if ( ! ( V_12 & V_45 ) )
V_11 -> V_33 |= V_46 ;
if ( ! ( V_12 & V_47 ) )
V_11 -> V_33 |= V_46 ;
if ( V_12 & V_48 )
V_11 -> V_33 |= V_49 ;
V_11 -> V_50 = V_51 ;
V_13 = V_11 -> V_29 == V_31 ;
F_3 ( V_2 ,
L_4 ,
V_11 -> V_28 ,
V_13 ? L_2 : L_3 ,
F_5 ( V_52 ) ,
F_5 ( V_53 ) ,
F_5 ( V_54 ) ,
F_5 ( V_55 ) ,
F_5 ( V_56 ) ,
F_5 ( V_57 ) ,
V_12 ,
V_11 -> V_50 ,
( ( V_12 & V_45 ) &&
! ( V_12 & V_48 ) )
? L_5 : L_6 ) ;
}
return V_9 ;
}
static void F_6 ( const struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_58 * V_59 ,
T_3 V_60 , T_3 V_61 )
{
int V_62 = F_7 ( V_61 ) ;
int V_63 = F_7 ( V_60 ) ;
V_59 -> V_64 = true ;
V_59 -> V_65 = V_66 |
V_67 |
V_68 |
3 << V_69 |
7 << V_70 ;
if ( V_63 > 1 )
V_59 -> V_65 |= V_71 ;
else
V_59 -> V_65 |= V_72 ;
if ( V_73 . V_74 )
V_59 -> V_65 |= V_75 ;
V_59 -> V_76 . V_77 =
F_8 ( V_78 << 0 |
V_78 << 2 |
V_79 << 4 |
V_79 << 6 |
V_79 << 8 |
V_79 << 10 |
V_79 << 12 |
V_79 << 14 ) ;
if ( V_62 == 1 || V_4 -> V_80 ) {
V_59 -> V_65 |= V_81 ;
V_59 -> V_76 . V_77 |=
F_8 ( V_79 << 2 ) ;
}
V_59 -> V_76 . V_82 = V_59 -> V_76 . V_77 ;
}
static void F_9 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 ,
const T_1 * V_83 , bool V_84 ,
T_3 V_60 , T_3 V_61 )
{
int V_9 ;
int V_85 = 0 ;
struct V_86 * V_87 ;
if ( V_4 -> V_17 != V_18 )
V_9 = F_1 (
V_2 , V_4 , V_6 ,
& V_83 [ V_88 ] ) ;
else
V_9 = F_1 (
V_2 , V_4 , V_6 ,
& V_83 [ V_89 ] ) ;
V_87 = & V_6 -> V_90 [ V_30 ] ;
V_87 -> V_29 = V_30 ;
V_87 -> V_91 = & V_92 [ V_93 ] ;
V_87 -> V_94 = V_95 ;
V_85 += F_10 ( V_6 , V_87 , V_9 ,
V_30 ) ;
F_11 ( V_4 , V_6 , & V_87 -> V_96 , V_30 ,
V_60 , V_61 ) ;
V_87 = & V_6 -> V_90 [ V_31 ] ;
V_87 -> V_29 = V_31 ;
V_87 -> V_91 = & V_92 [ V_97 ] ;
V_87 -> V_94 = V_98 ;
V_85 += F_10 ( V_6 , V_87 , V_9 ,
V_31 ) ;
F_11 ( V_4 , V_6 , & V_87 -> V_96 , V_31 ,
V_60 , V_61 ) ;
if ( V_84 )
F_6 ( V_4 , V_6 , & V_87 -> V_59 ,
V_60 , V_61 ) ;
if ( V_9 != V_85 )
F_12 ( V_2 , L_7 ,
V_85 , V_9 ) ;
}
static int F_13 ( const struct V_3 * V_4 ,
const T_1 * V_99 )
{
if ( V_4 -> V_17 != V_18 )
return F_14 ( V_99 + V_100 ) ;
else
return F_15 ( ( V_101 * ) ( V_99 + V_102 ) ) ;
}
static int F_16 ( const struct V_3 * V_4 ,
const T_1 * V_99 )
{
if ( V_4 -> V_17 != V_18 )
return F_14 ( V_99 + V_103 ) ;
else
return F_15 ( ( V_101 * ) ( V_99 +
V_104 ) ) ;
}
static int F_17 ( const struct V_3 * V_4 ,
const T_1 * V_99 )
{
if ( V_4 -> V_17 != V_18 )
return F_14 ( V_99 + V_105 ) ;
else
return F_15 ( ( V_101 * ) ( V_99 + V_106 ) ) ;
}
static int F_18 ( const struct V_3 * V_4 ,
const T_1 * V_99 )
{
if ( V_4 -> V_17 != V_18 )
return F_14 ( V_99 + V_107 ) ;
else
return F_15 ( ( V_101 * ) ( V_99 + V_108 ) )
& V_109 ;
}
static void F_19 ( const struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_4 V_110 )
{
if ( V_4 -> V_17 != V_18 ) {
V_6 -> V_111 = F_20 ( V_110 ) ;
V_6 -> V_112 = F_21 ( V_110 ) ;
V_6 -> V_113 = F_22 ( V_110 ) ;
V_6 -> V_114 = F_23 ( V_110 ) ;
return;
}
V_6 -> V_111 = F_24 ( V_110 ) ;
V_6 -> V_112 = F_25 ( V_110 ) ;
V_6 -> V_113 = F_26 ( V_110 ) ;
V_6 -> V_114 = F_27 ( V_110 ) ;
}
static void F_28 ( const struct V_3 * V_4 ,
struct V_5 * V_6 ,
const T_1 * V_115 )
{
const T_3 * V_116 = ( const T_3 * ) ( V_115 + V_117 ) ;
V_6 -> V_116 [ 0 ] = V_116 [ 1 ] ;
V_6 -> V_116 [ 1 ] = V_116 [ 0 ] ;
V_6 -> V_116 [ 2 ] = V_116 [ 3 ] ;
V_6 -> V_116 [ 3 ] = V_116 [ 2 ] ;
V_6 -> V_116 [ 4 ] = V_116 [ 5 ] ;
V_6 -> V_116 [ 5 ] = V_116 [ 4 ] ;
}
static void F_29 ( const struct V_3 * V_4 ,
struct V_5 * V_6 ,
const T_1 * V_118 ,
const T_1 * V_119 )
{
const T_3 * V_116 ;
if ( V_118 ) {
V_116 = ( const T_3 * ) ( V_118 +
V_120 ) ;
V_6 -> V_116 [ 0 ] = V_116 [ 1 ] ;
V_6 -> V_116 [ 1 ] = V_116 [ 0 ] ;
V_6 -> V_116 [ 2 ] = V_116 [ 3 ] ;
V_6 -> V_116 [ 3 ] = V_116 [ 2 ] ;
V_6 -> V_116 [ 4 ] = V_116 [ 5 ] ;
V_6 -> V_116 [ 5 ] = V_116 [ 4 ] ;
if ( F_30 ( V_116 ) )
return;
}
V_116 = ( const T_3 * ) ( V_119 + V_121 ) ;
V_6 -> V_116 [ 0 ] = V_116 [ 3 ] ;
V_6 -> V_116 [ 1 ] = V_116 [ 2 ] ;
V_6 -> V_116 [ 2 ] = V_116 [ 1 ] ;
V_6 -> V_116 [ 3 ] = V_116 [ 0 ] ;
V_116 = ( const T_3 * ) ( V_119 + V_122 ) ;
V_6 -> V_116 [ 4 ] = V_116 [ 1 ] ;
V_6 -> V_116 [ 5 ] = V_116 [ 0 ] ;
}
struct V_5 *
F_31 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
const T_1 * V_119 , const T_1 * V_99 ,
const T_1 * V_123 , const T_1 * V_124 ,
const T_1 * V_118 , T_3 V_60 , T_3 V_61 )
{
struct V_5 * V_6 ;
T_4 V_125 ;
T_4 V_110 ;
if ( V_4 -> V_17 != V_18 )
V_6 = F_32 ( sizeof( * V_6 ) +
sizeof( struct V_10 ) *
V_19 ,
V_126 ) ;
else
V_6 = F_32 ( sizeof( * V_6 ) +
sizeof( struct V_10 ) *
V_22 ,
V_126 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_127 = F_16 ( V_4 , V_99 ) ;
V_110 = F_17 ( V_4 , V_99 ) ;
F_19 ( V_4 , V_6 , V_110 ) ;
V_125 = F_13 ( V_4 , V_99 ) ;
V_6 -> V_128 = V_125 & V_129 ;
V_6 -> V_25 = V_125 & V_130 ;
V_6 -> V_131 = V_125 & V_132 ;
V_6 -> V_133 = V_125 & V_134 ;
if ( V_73 . V_135 & V_136 )
V_6 -> V_131 = false ;
V_6 -> V_137 = F_18 ( V_4 , V_99 ) ;
if ( V_4 -> V_17 != V_18 ) {
if ( ! V_123 ) {
F_12 ( V_2 ,
L_8 ) ;
F_33 ( V_6 ) ;
return NULL ;
}
V_6 -> V_138 [ 0 ] = * ( V_123 + V_139 ) ;
V_6 -> V_138 [ 1 ] = * ( V_123 + V_139 + 1 ) ;
}
if ( V_4 -> V_17 != V_18 ) {
F_28 ( V_4 , V_6 , V_119 ) ;
F_9 ( V_2 , V_4 , V_6 , V_99 ,
V_125 & V_134 , V_60 ,
V_61 ) ;
} else {
F_29 ( V_4 , V_6 , V_118 , V_119 ) ;
F_9 ( V_2 , V_4 , V_6 , V_124 ,
V_125 & V_134 , V_60 ,
V_61 ) ;
}
V_6 -> V_140 = 255 ;
return V_6 ;
}
