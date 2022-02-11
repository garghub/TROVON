static int F_1 ( T_1 V_1 , T_2 V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 )
{
const T_3 V_6 [ V_7 ] = {
6 * 256 ,
6 * 32 ,
6 * 8 ,
6 * 256
} ;
T_2 V_8 = 0 , V_9 = 0 ;
T_1 V_10 ;
T_1 V_11 ;
if ( V_2 >= V_7 )
return - V_12 ;
V_11 = V_6 [ V_2 ] ;
V_10 = ( 1008000 + ( V_11 >> 1 ) - 1 ) / V_11 ;
if ( V_10 == V_1 ) {
* V_3 = 126 ;
* V_4 = 0 ;
* V_5 = 0 ;
return 0 ;
} else if ( V_10 > V_1 ) {
while ( V_10 > V_1 ) {
V_9 ++ ;
V_10 = 1008000 / ( V_11 * ( 1 << V_9 ) ) ;
}
if ( V_10 == V_1 )
* V_3 = 126 ;
else
* V_3 = ( V_1 * V_11 * ( 1 << V_9 ) + 4000 ) / 8000 ;
} else {
T_1 V_13 ;
while ( V_10 < V_1 ) {
V_8 ++ ;
V_13 = 1008000 * ( 1 << V_8 ) ;
V_10 = ( V_13 + ( V_11 >> 1 ) ) / V_11 ;
}
if ( V_10 == V_1 ) {
* V_3 = 126 ;
} else {
T_1 V_14 = ( 8000 * ( 1 << -- V_8 ) ) ;
* V_3 = ( V_1 * V_11 + ( V_14 >> 1 ) ) / V_14 ;
}
}
* V_4 = V_8 ;
* V_5 = V_9 ;
return 0 ;
}
static int F_2 ( struct V_15 * V_16 , bool V_17 , bool V_18 )
{
struct V_19 V_20 ;
F_3 ( & V_20 , V_21 , false ) ;
V_20 . V_22 [ 0 ] = F_4 ( ( V_17 ? V_23 : 0 ) |
( V_18 ? V_24 : 0 ) ) ;
return F_5 ( & V_16 -> V_25 , & V_20 , 1 ) ;
}
static int F_6 ( struct V_15 * V_16 , T_2 * V_26 , T_2 V_27 )
{
T_2 V_28 ;
V_28 = V_16 -> V_29 . V_30 [ V_27 ] ;
if ( V_28 >= V_16 -> V_29 . V_31 )
return - V_12 ;
V_26 [ V_27 >> 1 ] |= V_28 << ( ( V_27 & 1 ) * 4 ) ;
return 0 ;
}
static int F_7 ( struct V_15 * V_16 )
{
struct V_19 V_20 ;
T_2 * V_26 = ( T_2 * ) V_20 . V_22 ;
T_2 V_27 ;
int V_32 ;
F_3 ( & V_20 , V_33 , false ) ;
for ( V_27 = 0 ; V_27 < V_34 ; V_27 ++ ) {
V_32 = F_6 ( V_16 , V_26 , V_27 ) ;
if ( V_32 )
return V_32 ;
}
return F_5 ( & V_16 -> V_25 , & V_20 , 1 ) ;
}
static int F_8 ( struct V_15 * V_16 ,
T_2 V_35 , T_2 V_36 )
{
struct V_37 * V_38 ;
struct V_19 V_20 ;
F_3 ( & V_20 , V_39 , false ) ;
V_38 = (struct V_37 * ) V_20 . V_22 ;
V_38 -> V_35 = V_35 ;
V_38 -> V_36 = V_36 ;
return F_5 ( & V_16 -> V_25 , & V_20 , 1 ) ;
}
static int F_9 ( struct V_15 * V_16 ,
T_3 V_40 , T_2 V_26 )
{
struct V_41 * V_38 ;
struct V_19 V_20 ;
F_3 ( & V_20 , V_42 , false ) ;
V_38 = (struct V_41 * ) V_20 . V_22 ;
V_38 -> V_40 = F_10 ( V_40 ) ;
V_38 -> V_43 = V_26 ;
V_38 -> V_44 = V_45 ;
return F_5 ( & V_16 -> V_25 , & V_20 , 1 ) ;
}
static int F_11 ( struct V_15 * V_16 ,
T_2 V_46 , T_3 V_40 )
{
struct V_47 * V_38 ;
struct V_19 V_20 ;
F_3 ( & V_20 , V_48 , false ) ;
V_38 = (struct V_47 * ) V_20 . V_22 ;
V_38 -> V_49 = F_10 ( V_46 ) ;
V_38 -> V_50 = F_10 ( V_40 | V_51 ) ;
return F_5 ( & V_16 -> V_25 , & V_20 , 1 ) ;
}
static int F_12 ( struct V_15 * V_16 , T_2 V_35 ,
T_2 V_52 )
{
struct V_53 * V_54 ;
struct V_19 V_20 ;
F_3 ( & V_20 , V_55 , false ) ;
V_54 = (struct V_53 * ) V_20 . V_22 ;
V_54 -> V_35 = V_35 ;
V_54 -> V_52 = V_52 ;
return F_5 ( & V_16 -> V_25 , & V_20 , 1 ) ;
}
static int F_13 ( struct V_15 * V_16 , T_2 V_27 ,
T_2 V_52 )
{
struct V_56 * V_54 ;
struct V_19 V_20 ;
F_3 ( & V_20 , V_57 , false ) ;
V_54 = (struct V_56 * ) V_20 . V_22 ;
V_54 -> V_27 = V_27 ;
V_54 -> V_52 = V_52 ;
return F_5 ( & V_16 -> V_25 , & V_20 , 1 ) ;
}
static int F_14 ( struct V_15 * V_16 , T_3 V_40 ,
T_2 V_52 )
{
struct V_58 * V_54 ;
struct V_19 V_20 ;
F_3 ( & V_20 , V_59 , false ) ;
V_54 = (struct V_58 * ) V_20 . V_22 ;
V_54 -> V_40 = F_10 ( V_40 ) ;
V_54 -> V_52 = V_52 ;
return F_5 ( & V_16 -> V_25 , & V_20 , 1 ) ;
}
static int F_15 ( struct V_15 * V_16 ,
enum V_60 V_61 , T_2 V_35 ,
T_2 V_3 , T_2 V_4 , T_2 V_5 , T_2 V_62 , T_2 V_63 )
{
struct V_64 * V_65 ;
enum V_66 V_67 ;
struct V_19 V_20 ;
V_67 = V_61 ? V_68 :
V_69 ;
F_3 ( & V_20 , V_67 , false ) ;
V_65 = (struct V_64 * ) V_20 . V_22 ;
V_65 -> V_35 = V_35 ;
F_16 ( V_65 -> V_70 , V_71 , V_3 ) ;
F_16 ( V_65 -> V_70 , V_72 , V_4 ) ;
F_16 ( V_65 -> V_70 , V_73 , V_5 ) ;
F_16 ( V_65 -> V_70 , V_74 , V_62 ) ;
F_16 ( V_65 -> V_70 , V_75 , V_63 ) ;
return F_5 ( & V_16 -> V_25 , & V_20 , 1 ) ;
}
static int F_17 ( struct V_15 * V_16 ,
enum V_60 V_61 , T_2 V_27 ,
T_2 V_3 , T_2 V_4 , T_2 V_5 ,
T_2 V_62 , T_2 V_63 )
{
struct V_76 * V_65 ;
enum V_66 V_67 ;
struct V_19 V_20 ;
V_67 = V_61 ? V_77 :
V_78 ;
F_3 ( & V_20 , V_67 , false ) ;
V_65 = (struct V_76 * ) V_20 . V_22 ;
V_65 -> V_27 = V_27 ;
F_16 ( V_65 -> V_79 , V_71 , V_3 ) ;
F_16 ( V_65 -> V_79 , V_72 , V_4 ) ;
F_16 ( V_65 -> V_79 , V_73 , V_5 ) ;
F_16 ( V_65 -> V_79 , V_74 , V_62 ) ;
F_16 ( V_65 -> V_79 , V_75 , V_63 ) ;
return F_5 ( & V_16 -> V_25 , & V_20 , 1 ) ;
}
static int F_18 ( struct V_15 * V_16 , T_2 V_35 )
{
struct V_19 V_20 ;
F_3 ( & V_20 , V_80 , false ) ;
if ( V_16 -> V_29 . V_81 [ V_35 ] . V_82 == V_83 )
V_20 . V_22 [ 1 ] = F_4 ( V_84 ) ;
else
V_20 . V_22 [ 1 ] = 0 ;
V_20 . V_22 [ 0 ] = F_4 ( V_35 ) ;
return F_5 ( & V_16 -> V_25 , & V_20 , 1 ) ;
}
static int F_19 ( struct V_15 * V_16 , T_2 V_27 )
{
struct V_19 V_20 ;
F_3 ( & V_20 , V_85 , false ) ;
if ( V_16 -> V_29 . V_86 [ V_27 ] . V_87 == V_83 )
V_20 . V_22 [ 1 ] = F_4 ( V_84 ) ;
else
V_20 . V_22 [ 1 ] = 0 ;
V_20 . V_22 [ 0 ] = F_4 ( V_27 ) ;
return F_5 ( & V_16 -> V_25 , & V_20 , 1 ) ;
}
static int F_20 ( struct V_15 * V_16 , T_3 V_40 )
{
struct V_19 V_20 ;
F_3 ( & V_20 , V_88 , false ) ;
if ( V_16 -> V_29 . V_86 [ V_40 ] . V_87 == V_83 )
V_20 . V_22 [ 1 ] = F_4 ( V_84 ) ;
else
V_20 . V_22 [ 1 ] = 0 ;
V_20 . V_22 [ 0 ] = F_4 ( V_40 ) ;
return F_5 ( & V_16 -> V_25 , & V_20 , 1 ) ;
}
static int F_21 ( struct V_15 * V_16 , T_2 V_28 )
{
struct V_89 * V_90 ;
struct V_19 V_20 ;
F_3 ( & V_20 , V_91 ,
false ) ;
V_90 = (struct V_89 * ) V_20 . V_22 ;
V_90 -> V_92 = V_28 ;
V_90 -> V_93 = F_4 ( 1 << V_28 ) ;
return F_5 ( & V_16 -> V_25 , & V_20 , 1 ) ;
}
static void F_22 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = & V_95 -> V_98 . V_97 ;
struct V_15 * V_16 = V_95 -> V_99 ;
T_2 V_100 ;
V_97 = & V_95 -> V_98 . V_97 ;
V_95 -> V_101 = V_16 -> V_29 . V_81 [ 0 ] . V_101 ;
V_97 -> V_31 =
F_23 ( T_3 , V_97 -> V_102 , V_16 -> V_29 . V_31 ) ;
V_97 -> V_103
= F_23 ( T_3 , V_16 -> V_104 ,
V_97 -> V_102 / V_97 -> V_31 ) ;
V_95 -> V_105 = V_16 -> V_29 . V_31 * V_95 -> V_106 ;
V_95 -> V_52 = 100 ;
V_95 -> V_107 = V_97 -> V_103 ;
for ( V_100 = 0 ; V_100 < V_97 -> V_31 ; V_100 ++ ) {
if ( V_16 -> V_108 & F_24 ( V_100 ) ) {
V_97 -> V_86 [ V_100 ] . V_109 = true ;
V_97 -> V_86 [ V_100 ] . V_110 = V_100 * V_97 -> V_103 ;
V_97 -> V_86 [ V_100 ] . V_111 = V_97 -> V_103 ;
V_97 -> V_86 [ V_100 ] . V_28 = V_100 ;
} else {
V_97 -> V_86 [ V_100 ] . V_109 = false ;
V_97 -> V_86 [ V_100 ] . V_110 = 0 ;
V_97 -> V_86 [ V_100 ] . V_111 = 1 ;
V_97 -> V_86 [ V_100 ] . V_28 = 0 ;
}
}
memcpy ( V_97 -> V_30 , V_16 -> V_29 . V_30 ,
F_25 ( struct V_96 , V_30 ) ) ;
}
static void F_26 ( struct V_15 * V_16 )
{
struct V_94 * V_95 = V_16 -> V_95 ;
T_1 V_100 ;
for ( V_100 = 0 ; V_100 < V_16 -> V_112 ; V_100 ++ ) {
F_22 ( V_95 ) ;
V_95 ++ ;
}
}
static void F_27 ( struct V_15 * V_16 )
{
T_2 V_100 ;
for ( V_100 = 0 ; V_100 < V_16 -> V_29 . V_31 ; V_100 ++ ) {
V_16 -> V_29 . V_86 [ V_100 ] . V_92 = V_100 ;
V_16 -> V_29 . V_86 [ V_100 ] . V_87 = V_83 ;
V_16 -> V_29 . V_86 [ V_100 ] . V_113 = 0 ;
V_16 -> V_29 . V_86 [ V_100 ] . V_101 =
V_16 -> V_29 . V_81 [ 0 ] . V_101 ;
}
for ( V_100 = 0 ; V_100 < V_34 ; V_100 ++ )
V_16 -> V_29 . V_30 [ V_100 ] =
( V_100 >= V_16 -> V_29 . V_31 ) ? 0 : V_100 ;
V_16 -> V_114 &= ~ V_115 ;
}
static void F_28 ( struct V_15 * V_16 )
{
T_2 V_100 ;
for ( V_100 = 0 ; V_100 < V_16 -> V_29 . V_116 ; V_100 ++ ) {
int V_117 ;
V_16 -> V_29 . V_118 [ V_100 ] = V_100 ? 0 : 100 ;
V_16 -> V_29 . V_81 [ V_100 ] . V_35 = V_100 ;
V_16 -> V_29 . V_81 [ V_100 ] . V_82 = V_83 ;
V_16 -> V_29 . V_81 [ V_100 ] . V_101 = V_119 ;
if ( V_100 != 0 )
continue;
V_16 -> V_29 . V_81 [ V_100 ] . V_120 = V_16 -> V_108 ;
for ( V_117 = 0 ; V_117 < V_16 -> V_29 . V_31 ; V_117 ++ )
V_16 -> V_29 . V_81 [ V_100 ] . V_121 [ V_117 ] = 100 ;
}
}
static int F_29 ( struct V_15 * V_16 )
{
if ( ( V_16 -> V_122 != V_123 ) &&
( V_16 -> V_29 . V_116 != 1 ) )
return - V_12 ;
F_28 ( V_16 ) ;
F_27 ( V_16 ) ;
F_26 ( V_16 ) ;
V_16 -> V_29 . V_124 = V_125 ;
V_16 -> V_126 = V_16 -> V_29 . V_124 ;
return 0 ;
}
static int F_30 ( struct V_15 * V_16 )
{
int V_32 ;
T_1 V_100 ;
if ( V_16 -> V_122 != V_123 )
return 0 ;
for ( V_100 = 0 ; V_100 < V_16 -> V_29 . V_116 ; V_100 ++ ) {
V_32 = F_8 (
V_16 , V_100 , V_16 -> V_29 . V_81 [ V_100 ] . V_120 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int F_31 ( struct V_15 * V_16 )
{
T_2 V_4 , V_3 , V_5 ;
int V_32 ;
T_1 V_100 ;
if ( V_16 -> V_122 != V_123 )
return 0 ;
for ( V_100 = 0 ; V_100 < V_16 -> V_29 . V_116 ; V_100 ++ ) {
V_32 = F_1 (
V_16 -> V_29 . V_81 [ V_100 ] . V_101 ,
V_127 ,
& V_3 , & V_4 , & V_5 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_15 ( V_16 ,
V_128 , V_100 ,
0 , 0 , 0 , V_129 ,
V_130 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_15 ( V_16 ,
V_131 , V_100 ,
V_3 , V_4 , V_5 ,
V_129 ,
V_130 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int F_32 ( struct V_15 * V_16 )
{
int V_32 ;
T_1 V_100 ;
if ( V_16 -> V_122 != V_123 )
return 0 ;
for ( V_100 = 0 ; V_100 < V_16 -> V_29 . V_116 ; V_100 ++ ) {
V_32 = F_12 ( V_16 , V_100 ,
V_16 -> V_29 . V_118 [ V_100 ] ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int F_33 ( struct V_15 * V_16 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 = & V_95 -> V_98 . V_97 ;
struct V_132 * * V_133 = V_97 -> V_133 ;
struct V_134 * V_135 ;
T_1 V_100 , V_136 ;
int V_32 ;
for ( V_100 = 0 ; V_100 < V_97 -> V_31 ; V_100 ++ ) {
V_135 = & V_97 -> V_86 [ V_100 ] ;
for ( V_136 = 0 ; V_136 < V_135 -> V_111 ; V_136 ++ ) {
struct V_132 * V_137 = V_133 [ V_135 -> V_110 + V_136 ] ;
V_32 = F_11 ( V_16 ,
F_34 ( V_137 ) ,
V_95 -> V_105 + V_100 ) ;
if ( V_32 )
return V_32 ;
}
}
return 0 ;
}
static int F_35 ( struct V_15 * V_16 )
{
struct V_94 * V_95 = V_16 -> V_95 ;
int V_32 ;
T_1 V_100 ;
if ( V_16 -> V_122 == V_123 ) {
for ( V_100 = 0 ; V_100 < V_16 -> V_29 . V_31 ; V_100 ++ ) {
V_32 = F_9 ( V_16 , V_100 , V_100 ) ;
if ( V_32 )
return V_32 ;
}
} else if ( V_16 -> V_122 == V_138 ) {
int V_117 ;
for ( V_117 = 0 ; V_117 < V_16 -> V_112 ; V_117 ++ )
for ( V_100 = 0 ; V_100 < V_139 ; V_100 ++ ) {
V_32 = F_9 (
V_16 , V_95 [ V_117 ] . V_105 + V_100 , V_117 ) ;
if ( V_32 )
return V_32 ;
}
} else {
return - V_12 ;
}
for ( V_100 = 0 ; V_100 < V_16 -> V_112 ; V_100 ++ ) {
V_32 = F_33 ( V_16 , V_95 ) ;
if ( V_32 )
return V_32 ;
V_95 ++ ;
}
return 0 ;
}
static int F_36 ( struct V_15 * V_16 )
{
T_2 V_4 , V_3 , V_5 ;
int V_32 ;
T_1 V_100 ;
for ( V_100 = 0 ; V_100 < V_16 -> V_29 . V_31 ; V_100 ++ ) {
V_32 = F_1 (
V_16 -> V_29 . V_86 [ V_100 ] . V_101 ,
V_140 ,
& V_3 , & V_4 , & V_5 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_17 (
V_16 , V_128 , V_100 ,
0 , 0 , 0 , V_129 ,
V_130 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_17 (
V_16 , V_131 , V_100 ,
V_3 , V_4 , V_5 , V_129 ,
V_130 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int F_37 ( struct V_94 * V_95 )
{
struct V_15 * V_16 = V_95 -> V_99 ;
T_2 V_4 , V_3 , V_5 ;
int V_32 ;
V_32 = F_1 ( V_95 -> V_101 , V_141 ,
& V_3 , & V_4 , & V_5 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_17 ( V_16 , V_128 ,
V_95 -> V_106 ,
0 , 0 , 0 , V_129 ,
V_130 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_17 ( V_16 , V_131 ,
V_95 -> V_106 ,
V_3 , V_4 , V_5 ,
V_129 ,
V_130 ) ;
if ( V_32 )
return V_32 ;
return 0 ;
}
static int F_38 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = & V_95 -> V_98 . V_97 ;
struct V_15 * V_16 = V_95 -> V_99 ;
struct V_134 * V_135 ;
T_2 V_4 , V_3 , V_5 ;
T_1 V_100 ;
int V_32 ;
for ( V_100 = 0 ; V_100 < V_97 -> V_31 ; V_100 ++ ) {
V_135 = & V_97 -> V_86 [ V_100 ] ;
V_32 = F_1 (
V_16 -> V_29 . V_86 [ V_100 ] . V_101 ,
V_142 ,
& V_3 , & V_4 , & V_5 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int F_39 ( struct V_15 * V_16 )
{
struct V_94 * V_95 = V_16 -> V_95 ;
int V_32 ;
T_1 V_100 ;
for ( V_100 = 0 ; V_100 < V_16 -> V_112 ; V_100 ++ ) {
V_32 = F_37 ( V_95 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_38 ( V_95 ) ;
if ( V_32 )
return V_32 ;
V_95 ++ ;
}
return 0 ;
}
static int F_40 ( struct V_15 * V_16 )
{
int V_32 ;
if ( V_16 -> V_122 == V_123 ) {
V_32 = F_36 ( V_16 ) ;
if ( V_32 )
return V_32 ;
} else {
V_32 = F_39 ( V_16 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int F_41 ( struct V_15 * V_16 )
{
struct V_143 * V_81 ;
T_2 V_52 ;
int V_32 ;
T_1 V_100 ;
for ( V_100 = 0 ; V_100 < V_16 -> V_29 . V_31 ; V_100 ++ ) {
V_81 =
& V_16 -> V_29 . V_81 [ V_16 -> V_29 . V_86 [ V_100 ] . V_113 ] ;
V_52 = V_81 -> V_121 [ V_100 ] ;
V_32 = F_13 ( V_16 , V_100 , V_52 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_14 ( V_16 , V_100 , V_52 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int F_42 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = & V_95 -> V_98 . V_97 ;
struct V_15 * V_16 = V_95 -> V_99 ;
int V_32 ;
T_2 V_100 ;
V_32 = F_13 ( V_16 , V_95 -> V_106 , V_95 -> V_52 ) ;
if ( V_32 )
return V_32 ;
for ( V_100 = 0 ; V_100 < V_97 -> V_31 ; V_100 ++ ) {
V_32 = F_14 (
V_16 , V_95 -> V_105 + V_100 ,
V_16 -> V_29 . V_81 [ 0 ] . V_121 [ V_100 ] ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int F_43 ( struct V_15 * V_16 )
{
struct V_94 * V_95 = V_16 -> V_95 ;
int V_32 ;
T_1 V_100 ;
for ( V_100 = 0 ; V_100 < V_16 -> V_112 ; V_100 ++ ) {
V_32 = F_42 ( V_95 ) ;
if ( V_32 )
return V_32 ;
V_95 ++ ;
}
return 0 ;
}
static int F_44 ( struct V_15 * V_16 )
{
int V_32 ;
if ( V_16 -> V_122 == V_123 ) {
V_32 = F_41 ( V_16 ) ;
if ( V_32 )
return V_32 ;
} else {
V_32 = F_43 ( V_16 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int F_45 ( struct V_15 * V_16 )
{
int V_32 ;
V_32 = F_30 ( V_16 ) ;
if ( V_32 )
return V_32 ;
return F_35 ( V_16 ) ;
}
static int F_46 ( struct V_15 * V_16 )
{
int V_32 ;
V_32 = F_31 ( V_16 ) ;
if ( V_32 )
return V_32 ;
return F_40 ( V_16 ) ;
}
int F_47 ( struct V_15 * V_16 )
{
int V_32 ;
V_32 = F_32 ( V_16 ) ;
if ( V_32 )
return V_32 ;
return F_44 ( V_16 ) ;
}
static int F_48 ( struct V_15 * V_16 )
{
int V_32 ;
T_2 V_100 ;
if ( V_16 -> V_122 == V_138 )
return 0 ;
for ( V_100 = 0 ; V_100 < V_16 -> V_29 . V_116 ; V_100 ++ ) {
V_32 = F_18 ( V_16 , V_100 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int F_49 ( struct V_94 * V_95 )
{
struct V_96 * V_97 = & V_95 -> V_98 . V_97 ;
struct V_15 * V_16 = V_95 -> V_99 ;
int V_32 ;
T_2 V_100 ;
V_32 = F_19 ( V_16 , V_95 -> V_106 ) ;
if ( V_32 )
return V_32 ;
for ( V_100 = 0 ; V_100 < V_97 -> V_31 ; V_100 ++ ) {
V_32 = F_20 ( V_16 , V_95 -> V_105 + V_100 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
static int F_50 ( struct V_15 * V_16 )
{
struct V_94 * V_95 = V_16 -> V_95 ;
int V_32 ;
T_2 V_100 ;
if ( V_16 -> V_122 == V_123 ) {
for ( V_100 = 0 ; V_100 < V_16 -> V_29 . V_31 ; V_100 ++ ) {
V_32 = F_19 ( V_16 , V_100 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_20 ( V_16 , V_100 ) ;
if ( V_32 )
return V_32 ;
}
} else {
for ( V_100 = 0 ; V_100 < V_16 -> V_112 ; V_100 ++ ) {
V_32 = F_49 ( V_95 ) ;
if ( V_32 )
return V_32 ;
V_95 ++ ;
}
}
return 0 ;
}
static int F_51 ( struct V_15 * V_16 )
{
int V_32 ;
V_32 = F_48 ( V_16 ) ;
if ( V_32 )
return V_32 ;
return F_50 ( V_16 ) ;
}
static int F_52 ( struct V_15 * V_16 )
{
int V_32 ;
V_32 = F_45 ( V_16 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_46 ( V_16 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_47 ( V_16 ) ;
if ( V_32 )
return V_32 ;
return F_51 ( V_16 ) ;
}
int F_53 ( struct V_15 * V_16 )
{
bool V_144 = V_16 -> V_29 . V_124 != V_145 ;
int V_32 ;
T_2 V_100 ;
V_32 = F_2 ( V_16 , V_144 , V_144 ) ;
if ( V_32 )
return V_32 ;
if ( ! F_54 ( V_16 ) )
return 0 ;
for ( V_100 = 0 ; V_100 < V_16 -> V_29 . V_31 ; V_100 ++ ) {
V_32 = F_21 ( V_16 , V_100 ) ;
if ( V_32 )
return V_32 ;
}
return F_7 ( V_16 ) ;
}
int F_55 ( struct V_15 * V_16 )
{
int V_32 ;
if ( ( V_16 -> V_122 != V_123 ) &&
( V_16 -> V_122 != V_138 ) )
return - V_146 ;
V_32 = F_52 ( V_16 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_53 ( V_16 ) ;
if ( V_32 )
return V_32 ;
return 0 ;
}
int F_56 ( struct V_15 * V_16 )
{
int V_32 = F_29 ( V_16 ) ;
if ( V_32 )
return V_32 ;
return F_55 ( V_16 ) ;
}
