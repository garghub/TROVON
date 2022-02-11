static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( T_1 V_5 , T_1 * V_6 )
{
switch ( V_5 ) {
case V_7 :
* V_6 = V_8 ;
break;
case V_9 :
* V_6 = V_10 ;
break;
case V_11 :
* V_6 = V_12 ;
break;
case V_13 :
* V_6 = V_14 ;
break;
case V_15 :
* V_6 = V_16 ;
break;
case V_17 :
* V_6 = V_18 ;
break;
case V_19 :
* V_6 = V_20 ;
break;
case V_21 :
* V_6 = V_22 ;
break;
case V_23 :
* V_6 = V_24 ;
break;
case V_25 :
* V_6 = V_26 ;
break;
case V_27 :
* V_6 = V_28 ;
break;
case V_29 :
* V_6 = V_30 ;
break;
case V_31 :
* V_6 = V_32 ;
break;
case V_33 :
* V_6 = V_34 ;
break;
case V_35 :
* V_6 = V_36 ;
break;
case V_37 :
* V_6 = V_38 ;
break;
case V_39 :
* V_6 = V_40 ;
break;
case V_41 :
* V_6 = V_42 ;
break;
default:
return - V_43 ;
}
return 0 ;
}
static bool F_4 ( T_1 V_5 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < sizeof( V_5 ) ; V_44 ++ ) {
char V_45 = ( V_5 >> ( 8 * V_44 ) ) & 0xff ;
if ( V_45 == 'A' )
return true ;
}
return false ;
}
static void
F_5 ( struct V_46 * V_47 ,
struct V_1 * V_48 )
{
const struct V_49 * V_50 =
& V_47 -> V_51 . V_52 -> V_50 ;
if ( V_50 -> V_53 )
F_6 ( & V_47 -> V_51 ,
V_50 -> V_53 ,
0xffffffff ,
( V_48 -> V_54 - 1 ) |
( ( V_48 -> V_55 - 1 ) << 16 ) ) ;
if ( V_50 -> V_56 )
F_6 ( & V_47 -> V_51 ,
V_50 -> V_56 ,
0xffffffff ,
( V_48 -> V_57 - 1 ) |
( ( V_48 -> V_58 - 1 ) << 16 ) ) ;
if ( V_50 -> V_59 )
F_6 ( & V_47 -> V_51 ,
V_50 -> V_59 ,
0xffffffff ,
V_48 -> V_60 |
( V_48 -> V_61 << 16 ) ) ;
if ( V_48 -> V_54 != V_48 -> V_57 || V_48 -> V_55 != V_48 -> V_58 ) {
T_1 V_62 = 0 ;
if ( V_48 -> V_54 != V_48 -> V_57 ) {
int V_44 ;
T_1 V_63 ;
T_1 * V_64 = V_65 ;
T_1 V_66 ;
if ( V_48 -> V_54 < V_48 -> V_57 )
V_64 = V_67 ;
for ( V_44 = 0 ; V_44 < F_7 ( V_65 ) ; V_44 ++ )
F_6 ( & V_47 -> V_51 ,
17 + V_44 ,
0xffffffff ,
V_64 [ V_44 ] ) ;
V_63 = ( ( 8 * 256 * V_48 -> V_57 ) - ( 256 * 4 ) ) /
V_48 -> V_54 ;
V_63 ++ ;
V_66 = ( ( V_63 * V_48 -> V_54 ) + ( 256 * 4 ) ) /
2048 ;
if ( V_66 > V_48 -> V_57 )
V_63 -- ;
V_62 |= V_63 | 0x80000000 ;
}
if ( V_48 -> V_55 != V_48 -> V_58 ) {
int V_44 ;
T_1 V_63 ;
T_1 * V_64 = V_68 ;
T_1 V_66 ;
if ( V_48 -> V_54 < V_48 -> V_57 )
V_64 = V_69 ;
for ( V_44 = 0 ; V_44 < F_7 ( V_68 ) ; V_44 ++ )
F_6 ( & V_47 -> V_51 ,
33 + V_44 ,
0xffffffff ,
V_64 [ V_44 ] ) ;
V_63 = ( ( 8 * 256 * V_48 -> V_57 ) - ( 256 * 4 ) ) /
V_48 -> V_54 ;
V_63 ++ ;
V_66 = ( ( V_63 * V_48 -> V_54 ) + ( 256 * 4 ) ) /
2048 ;
if ( V_66 > V_48 -> V_57 )
V_63 -- ;
V_62 |= ( V_63 << 16 ) | 0x80000000 ;
}
F_6 ( & V_47 -> V_51 , 13 , 0xffffffff ,
V_62 ) ;
}
}
static void
F_8 ( struct V_46 * V_47 ,
struct V_1 * V_48 )
{
const struct V_49 * V_50 =
& V_47 -> V_51 . V_52 -> V_50 ;
unsigned int V_70 = V_71 ;
if ( V_47 -> V_4 . type != V_72 ) {
V_70 |= V_73 | V_74 |
V_75 ;
if ( F_4 ( V_48 -> V_4 . V_76 -> V_77 ) )
V_70 |= V_78 ;
else
V_70 |= V_79 |
F_9 ( V_48 -> V_80 ) ;
}
F_6 ( & V_47 -> V_51 ,
V_81 ,
V_82 ,
V_83 ) ;
F_6 ( & V_47 -> V_51 , V_50 -> V_84 ,
V_74 |
V_75 |
V_79 |
V_85 |
V_78 |
V_73 |
V_71 , V_70 ) ;
}
static void F_10 ( struct V_46 * V_47 ,
struct V_1 * V_48 )
{
T_1 V_70 ;
int V_86 ;
V_86 = F_3 ( V_48 -> V_4 . V_76 -> V_77 ,
& V_70 ) ;
if ( V_86 )
return;
if ( ( V_48 -> V_4 . V_76 -> V_77 == V_41 ||
V_48 -> V_4 . V_76 -> V_77 == V_37 ) &&
( V_48 -> V_4 . V_87 & ( F_11 ( V_88 ) | F_11 ( V_89 ) ) ) )
V_70 |= V_90 ;
F_6 ( & V_47 -> V_51 ,
V_91 ,
0xffffffff ,
V_70 ) ;
if ( V_48 -> V_4 . V_76 -> V_77 == V_15 )
V_70 = V_92 ;
else
V_70 = 0 ;
F_6 ( & V_47 -> V_51 ,
V_81 ,
V_92 , V_70 ) ;
}
static void F_12 ( struct V_46 * V_47 ,
struct V_1 * V_48 )
{
struct V_93 * V_51 = & V_47 -> V_51 ;
const struct V_49 * V_50 =
& V_51 -> V_52 -> V_50 ;
int V_44 ;
F_13 ( & V_47 -> V_51 , V_48 -> V_4 . V_76 ,
V_48 -> V_94 ) ;
for ( V_44 = 0 ; V_44 < V_48 -> V_95 ; V_44 ++ ) {
if ( V_50 -> V_96 [ V_44 ] ) {
F_6 ( & V_47 -> V_51 ,
V_50 -> V_96 [ V_44 ] ,
0xffffffff ,
V_48 -> V_96 [ V_44 ] ) ;
}
if ( V_50 -> V_97 [ V_44 ] ) {
F_6 ( & V_47 -> V_51 ,
V_50 -> V_97 [ V_44 ] ,
0xffffffff ,
V_48 -> V_97 [ V_44 ] ) ;
}
}
}
int
F_14 ( struct V_98 * V_99 )
{
int V_100 = 0 , V_101 = 0 , V_102 = 0 , V_103 = 0 ;
const struct V_49 * V_50 ;
struct V_1 * V_104 ;
struct V_2 * V_105 ;
struct V_46 * V_106 ;
struct V_107 * V_108 ;
V_106 = F_15 ( V_99 -> V_109 -> V_106 ) ;
V_50 = & V_106 -> V_51 . V_52 -> V_50 ;
if ( ! V_50 -> V_110 || ! V_50 -> V_111 )
return 0 ;
V_105 = F_16 ( V_99 -> V_48 ,
& V_106 -> V_4 ) ;
if ( F_17 ( V_105 ) )
return F_18 ( V_105 ) ;
V_104 = F_1 ( V_105 ) ;
F_19 (ovl, c_state) {
struct V_1 * V_112 ;
struct V_2 * V_113 ;
if ( V_108 == V_99 -> V_109 -> V_106 )
continue;
V_113 = F_16 ( V_99 -> V_48 , V_108 ) ;
if ( F_17 ( V_113 ) )
return F_18 ( V_113 ) ;
V_112 = F_1 ( V_113 ) ;
if ( ! V_113 -> V_76 ||
F_4 ( V_113 -> V_76 -> V_77 ) ||
V_112 -> V_80 != 255 )
continue;
if ( V_112 -> V_55 * V_112 -> V_54 < V_103 * V_102 )
continue;
V_100 = V_112 -> V_60 ;
V_101 = V_112 -> V_61 ;
V_103 = V_112 -> V_55 ;
V_102 = V_112 -> V_54 ;
}
if ( V_100 == V_104 -> V_100 &&
V_101 == V_104 -> V_101 &&
V_102 == V_104 -> V_102 &&
V_103 == V_104 -> V_103 )
return 0 ;
V_104 -> V_100 = V_100 ;
V_104 -> V_101 = V_101 ;
V_104 -> V_102 = V_102 ;
V_104 -> V_103 = V_103 ;
V_104 -> V_114 = true ;
return 0 ;
}
static void
F_20 ( struct V_46 * V_47 ,
struct V_1 * V_48 )
{
const struct V_49 * V_50 =
& V_47 -> V_51 . V_52 -> V_50 ;
int V_115 = 0 ;
if ( ! V_48 -> V_114 )
return;
V_115 = V_48 -> V_103 * V_48 -> V_102 ;
F_6 ( & V_47 -> V_51 , V_50 -> V_84 ,
V_116 ,
V_115 ? V_116 : 0 ) ;
if ( ! V_115 )
return;
F_6 ( & V_47 -> V_51 ,
V_50 -> V_110 ,
0xffffffff ,
V_48 -> V_100 | ( V_48 -> V_101 << 16 ) ) ;
F_6 ( & V_47 -> V_51 ,
V_50 -> V_111 ,
0xffffffff ,
( V_48 -> V_102 - 1 ) |
( ( V_48 -> V_103 - 1 ) << 16 ) ) ;
}
static int F_21 ( struct V_107 * V_117 ,
struct V_2 * V_3 )
{
struct V_46 * V_47 = F_15 ( V_117 ) ;
struct V_1 * V_48 =
F_1 ( V_3 ) ;
const struct V_49 * V_50 =
& V_47 -> V_51 . V_52 -> V_50 ;
struct V_118 * V_76 = V_48 -> V_4 . V_76 ;
const struct V_119 * V_6 ;
struct V_98 * V_120 ;
unsigned int V_121 ;
unsigned int V_122 ;
unsigned int V_123 ;
unsigned int V_124 ;
unsigned int V_45 ;
int V_125 = 0 ;
int V_126 = 0 ;
int V_127 = 1 ;
int V_128 = 1 ;
int V_44 ;
if ( ! V_48 -> V_4 . V_109 || ! V_76 )
return 0 ;
V_120 = V_3 -> V_48 -> V_129 [ F_22 ( V_3 -> V_109 ) ] ;
V_6 = & V_120 -> V_130 ;
V_48 -> V_131 = V_3 -> V_131 ;
V_48 -> V_132 = V_3 -> V_132 ;
V_48 -> V_58 = V_3 -> V_58 ;
V_48 -> V_57 = V_3 -> V_57 ;
V_48 -> V_60 = V_3 -> V_60 ;
V_48 -> V_61 = V_3 -> V_61 ;
V_48 -> V_55 = V_3 -> V_55 ;
V_48 -> V_54 = V_3 -> V_54 ;
if ( ( V_48 -> V_131 | V_48 -> V_132 | V_48 -> V_57 | V_48 -> V_58 ) &
V_133 )
return - V_134 ;
V_48 -> V_131 >>= 16 ;
V_48 -> V_132 >>= 16 ;
V_48 -> V_57 >>= 16 ;
V_48 -> V_58 >>= 16 ;
V_48 -> V_95 = F_23 ( V_76 -> V_77 ) ;
if ( V_48 -> V_95 > V_135 )
return - V_134 ;
if ( V_48 -> V_4 . V_87 & ( F_11 ( V_88 ) | F_11 ( V_89 ) ) ) {
V_45 = V_48 -> V_54 ;
V_48 -> V_54 = V_48 -> V_55 ;
V_48 -> V_55 = V_45 ;
V_45 = V_48 -> V_57 ;
V_48 -> V_57 = V_48 -> V_58 ;
V_48 -> V_58 = V_45 ;
}
if ( V_48 -> V_60 + V_48 -> V_54 > V_6 -> V_136 )
V_121 = V_6 -> V_136 - V_48 -> V_60 ;
else
V_121 = V_48 -> V_54 ;
if ( V_48 -> V_60 < 0 ) {
V_121 += V_48 -> V_60 ;
V_125 = - V_48 -> V_60 ;
V_48 -> V_60 = 0 ;
}
if ( V_48 -> V_61 + V_48 -> V_55 > V_6 -> V_137 )
V_122 = V_6 -> V_137 - V_48 -> V_61 ;
else
V_122 = V_48 -> V_55 ;
if ( V_48 -> V_61 < 0 ) {
V_122 += V_48 -> V_61 ;
V_126 = - V_48 -> V_61 ;
V_48 -> V_61 = 0 ;
}
V_123 = F_24 ( V_121 * V_48 -> V_57 ,
V_48 -> V_54 ) ;
V_124 = F_24 ( V_122 * V_48 -> V_58 ,
V_48 -> V_55 ) ;
V_127 = F_25 ( V_76 -> V_77 ) ;
V_128 = F_26 ( V_76 -> V_77 ) ;
for ( V_44 = 0 ; V_44 < V_48 -> V_95 ; V_44 ++ ) {
unsigned int V_138 = 0 ;
int V_139 = V_44 ? V_127 : 1 ;
int V_140 = V_44 ? V_128 : 1 ;
V_48 -> V_141 [ V_44 ] = F_27 ( V_76 -> V_77 , V_44 ) ;
if ( ! V_48 -> V_141 [ V_44 ] )
return - V_134 ;
switch ( V_48 -> V_4 . V_87 & V_142 ) {
case F_11 ( V_88 ) :
V_138 = ( ( V_126 + V_48 -> V_132 + V_123 - 1 ) /
V_140 ) * V_76 -> V_143 [ V_44 ] ;
V_138 += ( ( V_125 + V_48 -> V_131 ) / V_139 ) *
V_48 -> V_141 [ V_44 ] ;
V_48 -> V_96 [ V_44 ] = ( ( V_123 - 1 ) / V_140 ) *
V_76 -> V_143 [ V_44 ] ;
V_48 -> V_97 [ V_44 ] = - V_76 -> V_143 [ V_44 ] - V_48 -> V_141 [ V_44 ] ;
break;
case F_11 ( V_144 ) :
V_138 = ( ( V_126 + V_48 -> V_132 + V_124 - 1 ) /
V_140 ) * V_76 -> V_143 [ V_44 ] ;
V_138 += ( ( V_125 + V_48 -> V_131 + V_123 - 1 ) /
V_139 ) * V_48 -> V_141 [ V_44 ] ;
V_48 -> V_96 [ V_44 ] = ( ( ( ( V_123 - 1 ) / V_139 ) - 1 ) *
V_48 -> V_141 [ V_44 ] ) - V_76 -> V_143 [ V_44 ] ;
V_48 -> V_97 [ V_44 ] = - 2 * V_48 -> V_141 [ V_44 ] ;
break;
case F_11 ( V_89 ) :
V_138 = ( ( V_126 + V_48 -> V_132 ) / V_140 ) *
V_76 -> V_143 [ V_44 ] ;
V_138 += ( ( V_125 + V_48 -> V_131 + V_124 - 1 ) /
V_139 ) * V_48 -> V_141 [ V_44 ] ;
V_48 -> V_96 [ V_44 ] = - ( ( ( V_123 - 1 ) / V_140 ) *
V_76 -> V_143 [ V_44 ] ) -
( 2 * V_48 -> V_141 [ V_44 ] ) ;
V_48 -> V_97 [ V_44 ] = V_76 -> V_143 [ V_44 ] - V_48 -> V_141 [ V_44 ] ;
break;
case F_11 ( V_145 ) :
default:
V_138 = ( ( V_126 + V_48 -> V_132 ) / V_140 ) *
V_76 -> V_143 [ V_44 ] ;
V_138 += ( ( V_125 + V_48 -> V_131 ) / V_139 ) *
V_48 -> V_141 [ V_44 ] ;
V_48 -> V_96 [ V_44 ] = V_76 -> V_143 [ V_44 ] -
( ( V_123 / V_139 ) *
V_48 -> V_141 [ V_44 ] ) ;
V_48 -> V_97 [ V_44 ] = 0 ;
break;
}
V_48 -> V_94 [ V_44 ] = V_138 + V_76 -> V_94 [ V_44 ] ;
}
V_48 -> V_57 = V_123 ;
V_48 -> V_58 = V_124 ;
V_48 -> V_54 = V_121 ;
V_48 -> V_55 = V_122 ;
if ( ! V_50 -> V_53 &&
( V_6 -> V_136 != V_48 -> V_54 ||
V_6 -> V_137 != V_48 -> V_55 ) )
return - V_134 ;
if ( V_47 -> V_51 . V_52 -> V_146 &&
V_48 -> V_55 > V_47 -> V_51 . V_52 -> V_146 )
return - V_134 ;
if ( V_47 -> V_51 . V_52 -> V_147 &&
V_48 -> V_54 > V_47 -> V_51 . V_52 -> V_147 )
return - V_134 ;
if ( ( V_48 -> V_55 != V_48 -> V_58 || V_48 -> V_54 != V_48 -> V_57 ) &&
( ! V_50 -> V_56 ||
F_4 ( V_48 -> V_4 . V_76 -> V_77 ) ) )
return - V_134 ;
if ( V_48 -> V_60 < 0 || V_48 -> V_61 < 0 )
return - V_134 ;
if ( V_48 -> V_54 + V_48 -> V_60 > V_6 -> V_136 ||
V_48 -> V_55 + V_48 -> V_61 > V_6 -> V_137 )
return - V_134 ;
return 0 ;
}
static int F_28 ( struct V_107 * V_117 ,
const struct V_2 * V_148 )
{
struct V_46 * V_47 = F_15 ( V_117 ) ;
if ( ! V_148 -> V_76 )
return 0 ;
return F_29 ( & V_47 -> V_51 ) ;
}
static void F_30 ( struct V_107 * V_117 ,
struct V_2 * V_149 )
{
struct V_46 * V_47 = F_15 ( V_117 ) ;
struct V_1 * V_48 =
F_1 ( V_117 -> V_48 ) ;
if ( ! V_117 -> V_48 -> V_109 || ! V_117 -> V_48 -> V_76 )
return;
F_5 ( V_47 , V_48 ) ;
F_8 ( V_47 , V_48 ) ;
F_10 ( V_47 , V_48 ) ;
F_12 ( V_47 , V_48 ) ;
F_20 ( V_47 , V_48 ) ;
F_31 ( & V_47 -> V_51 ) ;
}
static void F_32 ( struct V_107 * V_117 ,
struct V_2 * V_150 )
{
struct V_46 * V_47 = F_15 ( V_117 ) ;
F_33 ( & V_47 -> V_51 ) ;
}
static void F_34 ( struct V_107 * V_117 )
{
struct V_46 * V_47 = F_15 ( V_117 ) ;
if ( V_47 -> V_4 . V_76 )
F_35 ( V_47 -> V_4 . V_76 ) ;
F_36 ( V_117 -> V_151 , & V_47 -> V_51 ) ;
F_37 ( V_117 ) ;
F_38 ( V_117 -> V_151 -> V_151 , V_47 ) ;
}
static int F_39 ( struct V_107 * V_117 ,
struct V_2 * V_3 ,
struct V_152 * V_153 ,
T_2 V_154 )
{
struct V_46 * V_47 = F_15 ( V_117 ) ;
struct V_155 * V_156 = V_47 -> V_157 ;
struct V_1 * V_48 =
F_1 ( V_3 ) ;
if ( V_153 == V_156 -> V_80 )
V_48 -> V_80 = V_154 ;
else
return - V_134 ;
return 0 ;
}
static int F_40 ( struct V_107 * V_117 ,
const struct V_2 * V_3 ,
struct V_152 * V_153 ,
T_2 * V_154 )
{
struct V_46 * V_47 = F_15 ( V_117 ) ;
struct V_155 * V_156 = V_47 -> V_157 ;
const struct V_1 * V_48 =
F_2 ( V_3 , const struct V_1 , V_4 ) ;
if ( V_153 == V_156 -> V_80 )
* V_154 = V_48 -> V_80 ;
else
return - V_134 ;
return 0 ;
}
static void F_41 ( struct V_46 * V_47 ,
const struct V_158 * V_52 ,
struct V_155 * V_156 )
{
struct V_159 * V_159 = V_47 -> V_51 . V_160 -> V_159 ;
if ( V_52 -> type == V_161 ||
V_52 -> type == V_162 ) {
F_42 ( & V_47 -> V_4 . V_4 ,
V_156 -> V_80 , 255 ) ;
F_43 ( V_159 ,
V_52 -> V_163 +
F_44 ( & V_47 -> V_51 ) ,
V_85 ,
V_85 ) ;
}
if ( V_52 -> V_50 . V_96 && V_52 -> V_50 . V_97 )
F_42 ( & V_47 -> V_4 . V_4 ,
V_47 -> V_4 . V_151 -> V_164 . V_165 ,
F_11 ( V_145 ) ) ;
if ( V_52 -> V_50 . V_166 ) {
F_45 ( V_159 ,
V_52 -> V_163 +
F_46 ( & V_47 -> V_51 , 0 ) ,
0x4c900091 ) ;
F_45 ( V_159 ,
V_52 -> V_163 +
F_46 ( & V_47 -> V_51 , 1 ) ,
0x7a5f5090 ) ;
F_45 ( V_159 ,
V_52 -> V_163 +
F_46 ( & V_47 -> V_51 , 2 ) ,
0x40040890 ) ;
}
}
static void F_47 ( struct V_107 * V_117 )
{
struct V_1 * V_48 ;
if ( V_117 -> V_48 ) {
V_48 = F_1 ( V_117 -> V_48 ) ;
if ( V_48 -> V_4 . V_76 )
F_35 ( V_48 -> V_4 . V_76 ) ;
F_48 ( V_48 ) ;
V_117 -> V_48 = NULL ;
}
V_48 = F_49 ( sizeof( * V_48 ) , V_167 ) ;
if ( V_48 ) {
V_48 -> V_80 = 255 ;
V_117 -> V_48 = & V_48 -> V_4 ;
V_117 -> V_48 -> V_47 = V_117 ;
}
}
static struct V_2 *
F_50 ( struct V_107 * V_117 )
{
struct V_1 * V_48 =
F_1 ( V_117 -> V_48 ) ;
struct V_1 * V_168 ;
V_168 = F_51 ( V_48 , sizeof( * V_48 ) , V_167 ) ;
if ( ! V_168 )
return NULL ;
V_168 -> V_114 = false ;
if ( V_168 -> V_4 . V_76 )
F_52 ( V_168 -> V_4 . V_76 ) ;
return & V_168 -> V_4 ;
}
static void F_53 ( struct V_107 * V_47 ,
struct V_2 * V_3 )
{
struct V_1 * V_48 =
F_1 ( V_3 ) ;
if ( V_3 -> V_76 )
F_35 ( V_3 -> V_76 ) ;
F_48 ( V_48 ) ;
}
static struct V_46 *
F_54 ( struct V_169 * V_151 ,
const struct V_158 * V_52 ,
struct V_155 * V_156 )
{
struct V_46 * V_47 ;
enum V_170 type ;
int V_86 ;
V_47 = F_55 ( V_151 -> V_151 , sizeof( * V_47 ) , V_167 ) ;
if ( ! V_47 )
return F_56 ( - V_171 ) ;
V_86 = F_57 ( V_151 , & V_47 -> V_51 , V_52 ) ;
if ( V_86 )
return F_56 ( V_86 ) ;
if ( V_52 -> type == V_172 )
type = V_72 ;
else if ( V_52 -> type == V_162 )
type = V_173 ;
else
type = V_174 ;
V_86 = F_58 ( V_151 , & V_47 -> V_4 , 0 ,
& V_175 ,
V_52 -> V_176 -> V_176 ,
V_52 -> V_176 -> V_177 , type ) ;
if ( V_86 )
return F_56 ( V_86 ) ;
F_59 ( & V_47 -> V_4 ,
& V_178 ) ;
F_41 ( V_47 , V_52 , V_156 ) ;
return V_47 ;
}
static struct V_155 *
F_60 ( struct V_169 * V_151 )
{
struct V_155 * V_156 ;
V_156 = F_55 ( V_151 -> V_151 , sizeof( * V_156 ) , V_167 ) ;
if ( ! V_156 )
return F_56 ( - V_171 ) ;
V_156 -> V_80 = F_61 ( V_151 , 0 , L_1 , 0 , 255 ) ;
if ( ! V_156 -> V_80 )
return F_56 ( - V_171 ) ;
V_151 -> V_164 . V_165 =
F_62 ( V_151 ,
F_11 ( V_145 ) |
F_11 ( V_88 ) |
F_11 ( V_144 ) |
F_11 ( V_89 ) ) ;
if ( ! V_151 -> V_164 . V_165 )
return F_56 ( - V_171 ) ;
return V_156 ;
}
struct V_179 *
F_63 ( struct V_169 * V_151 )
{
struct V_180 * V_181 = V_151 -> V_182 ;
struct V_155 * V_156 ;
struct V_179 * V_183 ;
const struct V_158 * V_184 = V_181 -> V_52 -> V_185 ;
int V_186 = V_181 -> V_52 -> V_186 ;
int V_44 ;
V_183 = F_55 ( V_151 -> V_151 , sizeof( * V_183 ) , V_167 ) ;
if ( ! V_183 )
return F_56 ( - V_171 ) ;
for ( V_44 = 0 ; V_44 < V_186 ; V_44 ++ ) {
if ( V_184 [ V_44 ] . type == V_161 )
V_183 -> V_187 ++ ;
}
if ( V_183 -> V_187 ) {
V_183 -> V_188 = F_55 ( V_151 -> V_151 ,
V_183 -> V_187 *
sizeof( * V_183 -> V_188 ) ,
V_167 ) ;
if ( ! V_183 -> V_188 )
return F_56 ( - V_171 ) ;
}
V_156 = F_60 ( V_151 ) ;
if ( F_17 ( V_156 ) )
return F_64 ( V_156 ) ;
V_183 -> V_187 = 0 ;
for ( V_44 = 0 ; V_44 < V_186 ; V_44 ++ ) {
struct V_46 * V_47 ;
if ( V_184 [ V_44 ] . type == V_189 )
continue;
V_47 = F_54 ( V_151 , & V_184 [ V_44 ] , V_156 ) ;
if ( F_17 ( V_47 ) )
return F_64 ( V_47 ) ;
V_47 -> V_157 = V_156 ;
switch ( V_184 [ V_44 ] . type ) {
case V_172 :
if ( V_183 -> V_106 )
return F_56 ( - V_134 ) ;
V_183 -> V_106 = V_47 ;
break;
case V_161 :
V_183 -> V_188 [ V_183 -> V_187 ++ ] = V_47 ;
break;
case V_162 :
if ( V_183 -> V_190 )
return F_56 ( - V_134 ) ;
V_183 -> V_190 = V_47 ;
break;
default:
break;
}
}
return V_183 ;
}
