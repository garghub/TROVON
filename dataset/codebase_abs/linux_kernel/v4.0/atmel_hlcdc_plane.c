static int F_1 ( T_1 V_1 , T_1 * V_2 )
{
switch ( V_1 ) {
case V_3 :
* V_2 = V_4 ;
break;
case V_5 :
* V_2 = V_6 ;
break;
case V_7 :
* V_2 = V_8 ;
break;
case V_9 :
* V_2 = V_10 ;
break;
case V_11 :
* V_2 = V_12 ;
break;
case V_13 :
* V_2 = V_14 ;
break;
case V_15 :
* V_2 = V_16 ;
break;
case V_17 :
* V_2 = V_18 ;
break;
case V_19 :
* V_2 = V_20 ;
break;
case V_21 :
* V_2 = V_22 ;
break;
case V_23 :
* V_2 = V_24 ;
break;
case V_25 :
* V_2 = V_26 ;
break;
case V_27 :
* V_2 = V_28 ;
break;
case V_29 :
* V_2 = V_30 ;
break;
case V_31 :
* V_2 = V_32 ;
break;
case V_33 :
* V_2 = V_34 ;
break;
case V_35 :
* V_2 = V_36 ;
break;
case V_37 :
* V_2 = V_38 ;
break;
default:
return - V_39 ;
}
return 0 ;
}
static bool F_2 ( T_1 V_1 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < sizeof( V_1 ) ; V_40 ++ ) {
char V_41 = ( V_1 >> ( 8 * V_40 ) ) & 0xff ;
if ( V_41 == 'A' )
return true ;
}
return false ;
}
static void
F_3 ( struct V_42 * V_43 ,
struct V_44 * V_45 )
{
const struct V_46 * V_47 =
& V_43 -> V_48 . V_49 -> V_47 ;
if ( V_47 -> V_50 )
F_4 ( & V_43 -> V_48 ,
V_47 -> V_50 ,
0xffffffff ,
( V_45 -> V_51 - 1 ) |
( ( V_45 -> V_52 - 1 ) << 16 ) ) ;
if ( V_47 -> V_53 )
F_4 ( & V_43 -> V_48 ,
V_47 -> V_53 ,
0xffffffff ,
( V_45 -> V_54 - 1 ) |
( ( V_45 -> V_55 - 1 ) << 16 ) ) ;
if ( V_47 -> V_56 )
F_4 ( & V_43 -> V_48 ,
V_47 -> V_56 ,
0xffffffff ,
V_45 -> V_57 |
( V_45 -> V_58 << 16 ) ) ;
if ( V_45 -> V_51 != V_45 -> V_54 || V_45 -> V_52 != V_45 -> V_55 ) {
T_1 V_59 = 0 ;
if ( V_45 -> V_51 != V_45 -> V_54 ) {
int V_40 ;
T_1 V_60 ;
T_1 * V_61 = V_62 ;
T_1 V_63 ;
if ( V_45 -> V_51 < V_45 -> V_54 )
V_61 = V_64 ;
for ( V_40 = 0 ; V_40 < F_5 ( V_62 ) ; V_40 ++ )
F_4 ( & V_43 -> V_48 ,
17 + V_40 ,
0xffffffff ,
V_61 [ V_40 ] ) ;
V_60 = ( ( 8 * 256 * V_45 -> V_54 ) - ( 256 * 4 ) ) /
V_45 -> V_51 ;
V_60 ++ ;
V_63 = ( ( V_60 * V_45 -> V_51 ) + ( 256 * 4 ) ) /
2048 ;
if ( V_63 > V_45 -> V_54 )
V_60 -- ;
V_59 |= V_60 | 0x80000000 ;
}
if ( V_45 -> V_52 != V_45 -> V_55 ) {
int V_40 ;
T_1 V_60 ;
T_1 * V_61 = V_65 ;
T_1 V_63 ;
if ( V_45 -> V_51 < V_45 -> V_54 )
V_61 = V_66 ;
for ( V_40 = 0 ; V_40 < F_5 ( V_65 ) ; V_40 ++ )
F_4 ( & V_43 -> V_48 ,
33 + V_40 ,
0xffffffff ,
V_61 [ V_40 ] ) ;
V_60 = ( ( 8 * 256 * V_45 -> V_54 ) - ( 256 * 4 ) ) /
V_45 -> V_51 ;
V_60 ++ ;
V_63 = ( ( V_60 * V_45 -> V_51 ) + ( 256 * 4 ) ) /
2048 ;
if ( V_63 > V_45 -> V_54 )
V_60 -- ;
V_59 |= ( V_60 << 16 ) | 0x80000000 ;
}
F_4 ( & V_43 -> V_48 , 13 , 0xffffffff ,
V_59 ) ;
}
}
static void
F_6 ( struct V_42 * V_43 ,
struct V_44 * V_45 )
{
const struct V_46 * V_47 =
& V_43 -> V_48 . V_49 -> V_47 ;
unsigned int V_67 = V_68 ;
if ( V_43 -> V_69 . type != V_70 ) {
V_67 |= V_71 | V_72 |
V_73 ;
if ( F_2 ( V_45 -> V_74 -> V_75 ) )
V_67 |= V_76 ;
else
V_67 |= V_77 ;
}
F_4 ( & V_43 -> V_48 ,
V_78 ,
V_79 ,
V_80 ) ;
F_4 ( & V_43 -> V_48 , V_47 -> V_81 ,
V_72 |
V_73 |
V_77 |
V_76 |
V_71 |
V_68 , V_67 ) ;
}
static void F_7 ( struct V_42 * V_43 ,
struct V_44 * V_45 )
{
T_1 V_67 ;
int V_82 ;
V_82 = F_1 ( V_45 -> V_74 -> V_75 , & V_67 ) ;
if ( V_82 )
return;
if ( ( V_45 -> V_74 -> V_75 == V_37 ||
V_45 -> V_74 -> V_75 == V_33 ) &&
( V_43 -> V_83 & ( F_8 ( V_84 ) | F_8 ( V_85 ) ) ) )
V_67 |= V_86 ;
F_4 ( & V_43 -> V_48 ,
V_87 ,
0xffffffff ,
V_67 ) ;
if ( V_45 -> V_74 -> V_75 == V_11 )
V_67 = V_88 ;
else
V_67 = 0 ;
F_4 ( & V_43 -> V_48 ,
V_78 ,
V_88 , V_67 ) ;
}
static void F_9 ( struct V_42 * V_43 ,
struct V_44 * V_45 )
{
struct V_89 * V_48 = & V_43 -> V_48 ;
const struct V_46 * V_47 =
& V_48 -> V_49 -> V_47 ;
int V_40 ;
F_10 ( & V_43 -> V_48 , V_45 -> V_74 , V_45 -> V_90 ) ;
for ( V_40 = 0 ; V_40 < V_45 -> V_91 ; V_40 ++ ) {
if ( V_47 -> V_92 [ V_40 ] ) {
F_4 ( & V_43 -> V_48 ,
V_47 -> V_92 [ V_40 ] ,
0xffffffff ,
V_45 -> V_92 [ V_40 ] ) ;
}
if ( V_47 -> V_93 [ V_40 ] ) {
F_4 ( & V_43 -> V_48 ,
V_47 -> V_93 [ V_40 ] ,
0xffffffff ,
V_45 -> V_93 [ V_40 ] ) ;
}
}
}
static int F_11 ( struct V_94 * V_95 ,
struct V_44 * V_45 ,
const struct V_96 * V_2 )
{
struct V_42 * V_43 = F_12 ( V_95 ) ;
const struct V_46 * V_47 =
& V_43 -> V_48 . V_49 -> V_47 ;
if ( ! V_47 -> V_50 &&
( V_2 -> V_97 != V_45 -> V_51 ||
V_2 -> V_98 != V_45 -> V_52 ) )
return - V_99 ;
if ( V_43 -> V_48 . V_49 -> V_100 &&
V_45 -> V_52 > V_43 -> V_48 . V_49 -> V_100 )
return - V_99 ;
if ( V_43 -> V_48 . V_49 -> V_101 &&
V_45 -> V_51 > V_43 -> V_48 . V_49 -> V_101 )
return - V_99 ;
if ( ( V_45 -> V_52 != V_45 -> V_55 || V_45 -> V_51 != V_45 -> V_54 ) &&
( ! V_47 -> V_53 ||
F_2 ( V_45 -> V_74 -> V_75 ) ) )
return - V_99 ;
if ( V_45 -> V_57 < 0 || V_45 -> V_58 < 0 )
return - V_99 ;
if ( V_45 -> V_51 + V_45 -> V_57 > V_2 -> V_97 ||
V_45 -> V_52 + V_45 -> V_58 > V_2 -> V_98 )
return - V_99 ;
return 0 ;
}
int F_13 ( struct V_94 * V_95 ,
struct V_44 * V_45 ,
const struct V_96 * V_2 )
{
struct V_42 * V_43 = F_12 ( V_95 ) ;
unsigned int V_102 ;
unsigned int V_103 ;
unsigned int V_104 ;
unsigned int V_105 ;
unsigned int V_41 ;
int V_106 = 0 ;
int V_107 = 0 ;
int V_108 = 1 ;
int V_109 = 1 ;
int V_40 ;
if ( ( V_45 -> V_110 | V_45 -> V_111 | V_45 -> V_54 | V_45 -> V_55 ) &
V_112 )
return - V_99 ;
V_45 -> V_110 >>= 16 ;
V_45 -> V_111 >>= 16 ;
V_45 -> V_54 >>= 16 ;
V_45 -> V_55 >>= 16 ;
V_45 -> V_91 = F_14 ( V_45 -> V_74 -> V_75 ) ;
if ( V_45 -> V_91 > V_113 )
return - V_99 ;
if ( V_43 -> V_83 & ( F_8 ( V_84 ) | F_8 ( V_85 ) ) ) {
V_41 = V_45 -> V_51 ;
V_45 -> V_51 = V_45 -> V_52 ;
V_45 -> V_52 = V_41 ;
V_41 = V_45 -> V_54 ;
V_45 -> V_54 = V_45 -> V_55 ;
V_45 -> V_55 = V_41 ;
}
if ( V_45 -> V_57 + V_45 -> V_51 > V_2 -> V_97 )
V_102 = V_2 -> V_97 - V_45 -> V_57 ;
else
V_102 = V_45 -> V_51 ;
if ( V_45 -> V_57 < 0 ) {
V_102 += V_45 -> V_57 ;
V_106 = - V_45 -> V_57 ;
V_45 -> V_57 = 0 ;
}
if ( V_45 -> V_58 + V_45 -> V_52 > V_2 -> V_98 )
V_103 = V_2 -> V_98 - V_45 -> V_58 ;
else
V_103 = V_45 -> V_52 ;
if ( V_45 -> V_58 < 0 ) {
V_103 += V_45 -> V_58 ;
V_107 = - V_45 -> V_58 ;
V_45 -> V_58 = 0 ;
}
V_104 = F_15 ( V_102 * V_45 -> V_54 ,
V_45 -> V_51 ) ;
V_105 = F_15 ( V_103 * V_45 -> V_55 ,
V_45 -> V_52 ) ;
V_108 = F_16 ( V_45 -> V_74 -> V_75 ) ;
V_109 = F_17 ( V_45 -> V_74 -> V_75 ) ;
for ( V_40 = 0 ; V_40 < V_45 -> V_91 ; V_40 ++ ) {
unsigned int V_114 = 0 ;
int V_115 = V_40 ? V_108 : 1 ;
int V_116 = V_40 ? V_109 : 1 ;
V_45 -> V_117 [ V_40 ] = F_18 ( V_45 -> V_74 -> V_75 , V_40 ) ;
if ( ! V_45 -> V_117 [ V_40 ] )
return - V_99 ;
switch ( V_43 -> V_83 & 0xf ) {
case F_8 ( V_84 ) :
V_114 = ( ( V_107 + V_45 -> V_111 + V_104 - 1 ) /
V_116 ) * V_45 -> V_74 -> V_118 [ V_40 ] ;
V_114 += ( ( V_106 + V_45 -> V_110 ) / V_115 ) *
V_45 -> V_117 [ V_40 ] ;
V_45 -> V_92 [ V_40 ] = ( ( V_104 - 1 ) / V_116 ) *
V_45 -> V_74 -> V_118 [ V_40 ] ;
V_45 -> V_93 [ V_40 ] = - V_45 -> V_74 -> V_118 [ V_40 ] - V_45 -> V_117 [ V_40 ] ;
break;
case F_8 ( V_119 ) :
V_114 = ( ( V_107 + V_45 -> V_111 + V_105 - 1 ) /
V_116 ) * V_45 -> V_74 -> V_118 [ V_40 ] ;
V_114 += ( ( V_106 + V_45 -> V_110 + V_104 - 1 ) /
V_115 ) * V_45 -> V_117 [ V_40 ] ;
V_45 -> V_92 [ V_40 ] = ( ( ( ( V_104 - 1 ) / V_115 ) - 1 ) *
V_45 -> V_117 [ V_40 ] ) - V_45 -> V_74 -> V_118 [ V_40 ] ;
V_45 -> V_93 [ V_40 ] = - 2 * V_45 -> V_117 [ V_40 ] ;
break;
case F_8 ( V_85 ) :
V_114 = ( ( V_107 + V_45 -> V_111 ) / V_116 ) *
V_45 -> V_74 -> V_118 [ V_40 ] ;
V_114 += ( ( V_106 + V_45 -> V_110 + V_105 - 1 ) /
V_115 ) * V_45 -> V_117 [ V_40 ] ;
V_45 -> V_92 [ V_40 ] = - ( ( ( V_104 - 1 ) / V_116 ) *
V_45 -> V_74 -> V_118 [ V_40 ] ) -
( 2 * V_45 -> V_117 [ V_40 ] ) ;
V_45 -> V_93 [ V_40 ] = V_45 -> V_74 -> V_118 [ V_40 ] - V_45 -> V_117 [ V_40 ] ;
break;
case F_8 ( V_120 ) :
default:
V_114 = ( ( V_107 + V_45 -> V_111 ) / V_116 ) *
V_45 -> V_74 -> V_118 [ V_40 ] ;
V_114 += ( ( V_106 + V_45 -> V_110 ) / V_115 ) *
V_45 -> V_117 [ V_40 ] ;
V_45 -> V_92 [ V_40 ] = V_45 -> V_74 -> V_118 [ V_40 ] -
( ( V_104 / V_115 ) *
V_45 -> V_117 [ V_40 ] ) ;
V_45 -> V_93 [ V_40 ] = 0 ;
break;
}
V_45 -> V_90 [ V_40 ] = V_114 + V_45 -> V_74 -> V_90 [ V_40 ] ;
}
V_45 -> V_54 = V_104 ;
V_45 -> V_55 = V_105 ;
V_45 -> V_51 = V_102 ;
V_45 -> V_52 = V_103 ;
return F_11 ( V_95 , V_45 , V_2 ) ;
}
int F_19 ( struct V_94 * V_95 ,
struct V_44 * V_45 )
{
struct V_42 * V_43 = F_12 ( V_95 ) ;
int V_82 ;
V_82 = F_20 ( & V_43 -> V_48 ) ;
if ( V_82 )
return V_82 ;
F_3 ( V_43 , V_45 ) ;
F_6 ( V_43 , V_45 ) ;
F_7 ( V_43 , V_45 ) ;
F_9 ( V_43 , V_45 ) ;
F_21 ( & V_43 -> V_48 ) ;
return 0 ;
}
int F_22 ( struct V_94 * V_95 ,
struct V_121 * V_122 ,
struct V_123 * V_74 ,
int V_57 , int V_58 ,
unsigned int V_51 ,
unsigned int V_52 ,
T_2 V_110 , T_2 V_111 ,
T_2 V_54 , T_2 V_55 ,
const struct V_96 * V_2 )
{
struct V_42 * V_43 = F_12 ( V_95 ) ;
struct V_44 V_45 ;
int V_82 = 0 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_57 = V_57 ;
V_45 . V_58 = V_58 ;
V_45 . V_51 = V_51 ;
V_45 . V_52 = V_52 ;
V_45 . V_110 = V_110 ;
V_45 . V_111 = V_111 ;
V_45 . V_54 = V_54 ;
V_45 . V_55 = V_55 ;
V_45 . V_74 = V_74 ;
V_82 = F_13 ( & V_43 -> V_69 , & V_45 , V_2 ) ;
if ( V_82 )
return V_82 ;
if ( ! V_45 . V_52 || ! V_45 . V_51 )
return F_23 ( & V_43 -> V_48 ) ;
return F_19 ( & V_43 -> V_69 , & V_45 ) ;
}
static int F_24 ( struct V_94 * V_95 ,
struct V_121 * V_122 ,
struct V_123 * V_74 ,
int V_57 , int V_58 ,
unsigned int V_51 , unsigned int V_52 ,
T_2 V_110 , T_2 V_111 ,
T_2 V_54 , T_2 V_55 )
{
return F_22 ( V_95 , V_122 , V_74 , V_57 , V_58 ,
V_51 , V_52 , V_110 , V_111 ,
V_54 , V_55 , & V_122 -> V_124 ) ;
}
static int F_25 ( struct V_94 * V_95 )
{
struct V_42 * V_43 = F_12 ( V_95 ) ;
return F_23 ( & V_43 -> V_48 ) ;
}
static void F_26 ( struct V_94 * V_95 )
{
struct V_42 * V_43 = F_12 ( V_95 ) ;
if ( V_43 -> V_69 . V_74 )
F_27 ( V_43 -> V_69 . V_74 ) ;
F_28 ( V_95 -> V_125 , & V_43 -> V_48 ) ;
F_29 ( V_95 ) ;
F_30 ( V_95 -> V_125 -> V_125 , V_43 ) ;
}
static int F_31 ( struct V_42 * V_43 ,
T_3 V_126 )
{
F_20 ( & V_43 -> V_48 ) ;
F_4 ( & V_43 -> V_48 ,
V_43 -> V_48 . V_49 -> V_47 . V_81 ,
V_127 ,
V_126 << V_128 ) ;
F_21 ( & V_43 -> V_48 ) ;
return 0 ;
}
static int F_32 ( struct V_42 * V_43 ,
unsigned int V_83 )
{
V_43 -> V_83 = V_83 ;
return 0 ;
}
static int F_33 ( struct V_94 * V_95 ,
struct V_129 * V_130 ,
T_4 V_131 )
{
struct V_42 * V_43 = F_12 ( V_95 ) ;
struct V_132 * V_133 = V_43 -> V_134 ;
if ( V_130 == V_133 -> V_126 )
F_31 ( V_43 , V_131 ) ;
else if ( V_130 == V_133 -> V_83 )
F_32 ( V_43 , V_131 ) ;
else
return - V_99 ;
return 0 ;
}
static void F_34 ( struct V_42 * V_43 ,
const struct V_135 * V_49 ,
struct V_132 * V_133 )
{
struct V_136 * V_136 = V_43 -> V_48 . V_137 -> V_136 ;
if ( V_49 -> type == V_138 ||
V_49 -> type == V_139 ) {
F_35 ( & V_43 -> V_69 . V_69 ,
V_133 -> V_126 , 255 ) ;
F_36 ( V_136 ,
V_49 -> V_140 +
F_37 ( & V_43 -> V_48 ) ,
V_127 ,
V_127 ) ;
}
if ( V_49 -> V_47 . V_92 && V_49 -> V_47 . V_93 )
F_35 ( & V_43 -> V_69 . V_69 ,
V_133 -> V_83 ,
F_8 ( V_120 ) ) ;
if ( V_49 -> V_47 . V_141 ) {
F_38 ( V_136 ,
V_49 -> V_140 +
F_39 ( & V_43 -> V_48 , 0 ) ,
0x4c900091 ) ;
F_38 ( V_136 ,
V_49 -> V_140 +
F_39 ( & V_43 -> V_48 , 1 ) ,
0x7a5f5090 ) ;
F_38 ( V_136 ,
V_49 -> V_140 +
F_39 ( & V_43 -> V_48 , 2 ) ,
0x40040890 ) ;
}
}
static struct V_42 *
F_40 ( struct V_142 * V_125 ,
const struct V_135 * V_49 ,
struct V_132 * V_133 )
{
struct V_42 * V_43 ;
enum V_143 type ;
int V_82 ;
V_43 = F_41 ( V_125 -> V_125 , sizeof( * V_43 ) , V_144 ) ;
if ( ! V_43 )
return F_42 ( - V_145 ) ;
V_82 = F_43 ( V_125 , & V_43 -> V_48 , V_49 ) ;
if ( V_82 )
return F_42 ( V_82 ) ;
if ( V_49 -> type == V_146 )
type = V_70 ;
else if ( V_49 -> type == V_139 )
type = V_147 ;
else
type = V_148 ;
V_82 = F_44 ( V_125 , & V_43 -> V_69 , 0 ,
& V_149 ,
V_49 -> V_150 -> V_150 ,
V_49 -> V_150 -> V_151 , type ) ;
if ( V_82 )
return F_42 ( V_82 ) ;
F_34 ( V_43 , V_49 , V_133 ) ;
return V_43 ;
}
static struct V_132 *
F_45 ( struct V_142 * V_125 )
{
struct V_132 * V_133 ;
V_133 = F_41 ( V_125 -> V_125 , sizeof( * V_133 ) , V_144 ) ;
if ( ! V_133 )
return F_42 ( - V_145 ) ;
V_133 -> V_126 = F_46 ( V_125 , 0 , L_1 , 0 , 255 ) ;
if ( ! V_133 -> V_126 )
return F_42 ( - V_145 ) ;
V_133 -> V_83 = F_47 ( V_125 ,
F_8 ( V_120 ) |
F_8 ( V_84 ) |
F_8 ( V_119 ) |
F_8 ( V_85 ) ) ;
if ( ! V_133 -> V_83 )
return F_42 ( - V_145 ) ;
return V_133 ;
}
struct V_152 *
F_48 ( struct V_142 * V_125 )
{
struct V_153 * V_154 = V_125 -> V_155 ;
struct V_132 * V_133 ;
struct V_152 * V_156 ;
const struct V_135 * V_157 = V_154 -> V_49 -> V_158 ;
int V_159 = V_154 -> V_49 -> V_159 ;
int V_40 ;
V_156 = F_41 ( V_125 -> V_125 , sizeof( * V_156 ) , V_144 ) ;
if ( ! V_156 )
return F_42 ( - V_145 ) ;
for ( V_40 = 0 ; V_40 < V_159 ; V_40 ++ ) {
if ( V_157 [ V_40 ] . type == V_138 )
V_156 -> V_160 ++ ;
}
if ( V_156 -> V_160 ) {
V_156 -> V_161 = F_41 ( V_125 -> V_125 ,
V_156 -> V_160 *
sizeof( * V_156 -> V_161 ) ,
V_144 ) ;
if ( ! V_156 -> V_161 )
return F_42 ( - V_145 ) ;
}
V_133 = F_45 ( V_125 ) ;
if ( F_49 ( V_133 ) )
return F_50 ( V_133 ) ;
V_156 -> V_160 = 0 ;
for ( V_40 = 0 ; V_40 < V_159 ; V_40 ++ ) {
struct V_42 * V_43 ;
if ( V_157 [ V_40 ] . type == V_162 )
continue;
V_43 = F_40 ( V_125 , & V_157 [ V_40 ] , V_133 ) ;
if ( F_49 ( V_43 ) )
return F_50 ( V_43 ) ;
V_43 -> V_134 = V_133 ;
switch ( V_157 [ V_40 ] . type ) {
case V_146 :
if ( V_156 -> V_163 )
return F_42 ( - V_99 ) ;
V_156 -> V_163 = V_43 ;
break;
case V_138 :
V_156 -> V_161 [ V_156 -> V_160 ++ ] = V_43 ;
break;
case V_139 :
if ( V_156 -> V_164 )
return F_42 ( - V_99 ) ;
V_156 -> V_164 = V_43 ;
break;
default:
break;
}
}
return V_156 ;
}
