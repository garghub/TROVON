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
if ( V_48 -> V_55 < V_48 -> V_58 )
V_64 = V_69 ;
for ( V_44 = 0 ; V_44 < F_7 ( V_68 ) ; V_44 ++ )
F_6 ( & V_47 -> V_51 ,
33 + V_44 ,
0xffffffff ,
V_64 [ V_44 ] ) ;
V_63 = ( ( 8 * 256 * V_48 -> V_58 ) - ( 256 * 4 ) ) /
V_48 -> V_55 ;
V_63 ++ ;
V_66 = ( ( V_63 * V_48 -> V_55 ) + ( 256 * 4 ) ) /
2048 ;
if ( V_66 > V_48 -> V_58 )
V_63 -- ;
V_62 |= ( V_63 << 16 ) | 0x80000000 ;
}
F_6 ( & V_47 -> V_51 , 13 , 0xffffffff ,
V_62 ) ;
} else {
F_6 ( & V_47 -> V_51 , 13 , 0xffffffff , 0 ) ;
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
V_82 |
V_83 ,
V_84 |
V_48 -> V_85 ) ;
F_6 ( & V_47 -> V_51 , V_50 -> V_86 ,
V_74 |
V_75 |
V_79 |
V_87 |
V_78 |
V_73 |
V_71 , V_70 ) ;
}
static void F_10 ( struct V_46 * V_47 ,
struct V_1 * V_48 )
{
T_1 V_70 ;
int V_88 ;
V_88 = F_3 ( V_48 -> V_4 . V_76 -> V_77 ,
& V_70 ) ;
if ( V_88 )
return;
if ( ( V_48 -> V_4 . V_76 -> V_77 == V_41 ||
V_48 -> V_4 . V_76 -> V_77 == V_37 ) &&
F_11 ( V_48 -> V_4 . V_89 ) )
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
int F_14 ( struct V_98 * V_99 )
{
unsigned int V_100 [ 2 ] = { } ;
struct V_101 * V_47 ;
F_15 (plane, c_state) {
struct V_1 * V_102 ;
struct V_2 * V_103 ;
unsigned int V_104 , V_105 = 0 ;
int V_44 ;
V_103 = F_16 ( V_99 -> V_48 , V_47 ) ;
if ( F_17 ( V_103 ) )
return F_18 ( V_103 ) ;
V_102 =
F_1 ( V_103 ) ;
V_104 = ( V_102 -> V_57 * V_102 -> V_58 ) -
( V_102 -> V_106 * V_102 -> V_107 ) ;
for ( V_44 = 0 ; V_44 < V_102 -> V_95 ; V_44 ++ )
V_105 += V_104 * V_102 -> V_108 [ V_44 ] ;
if ( V_100 [ 0 ] <= V_100 [ 1 ] )
V_102 -> V_85 = 0 ;
else
V_102 -> V_85 = 1 ;
V_100 [ V_102 -> V_85 ] += V_105 ;
}
return 0 ;
}
int
F_19 ( struct V_98 * V_99 )
{
int V_109 = 0 , V_110 = 0 , V_106 = 0 , V_107 = 0 ;
const struct V_49 * V_50 ;
struct V_1 * V_111 ;
struct V_2 * V_112 ;
struct V_46 * V_113 ;
struct V_101 * V_114 ;
V_113 = F_20 ( V_99 -> V_115 -> V_113 ) ;
V_50 = & V_113 -> V_51 . V_52 -> V_50 ;
if ( ! V_50 -> V_116 || ! V_50 -> V_117 )
return 0 ;
V_112 = F_16 ( V_99 -> V_48 ,
& V_113 -> V_4 ) ;
if ( F_17 ( V_112 ) )
return F_18 ( V_112 ) ;
V_111 = F_1 ( V_112 ) ;
F_15 (ovl, c_state) {
struct V_1 * V_118 ;
struct V_2 * V_119 ;
if ( V_114 == V_99 -> V_115 -> V_113 )
continue;
V_119 = F_16 ( V_99 -> V_48 , V_114 ) ;
if ( F_17 ( V_119 ) )
return F_18 ( V_119 ) ;
V_118 = F_1 ( V_119 ) ;
if ( ! V_119 -> V_76 ||
F_4 ( V_119 -> V_76 -> V_77 ) ||
V_118 -> V_80 != 255 )
continue;
if ( V_118 -> V_55 * V_118 -> V_54 < V_107 * V_106 )
continue;
V_109 = V_118 -> V_60 ;
V_110 = V_118 -> V_61 ;
V_107 = V_118 -> V_55 ;
V_106 = V_118 -> V_54 ;
}
if ( V_109 == V_111 -> V_109 &&
V_110 == V_111 -> V_110 &&
V_106 == V_111 -> V_106 &&
V_107 == V_111 -> V_107 )
return 0 ;
V_111 -> V_109 = V_109 ;
V_111 -> V_110 = V_110 ;
V_111 -> V_106 = V_106 ;
V_111 -> V_107 = V_107 ;
V_111 -> V_120 = true ;
return 0 ;
}
static void
F_21 ( struct V_46 * V_47 ,
struct V_1 * V_48 )
{
const struct V_49 * V_50 =
& V_47 -> V_51 . V_52 -> V_50 ;
int V_121 = 0 ;
if ( ! V_48 -> V_120 )
return;
V_121 = V_48 -> V_107 * V_48 -> V_106 ;
F_6 ( & V_47 -> V_51 , V_50 -> V_86 ,
V_122 ,
V_121 ? V_122 : 0 ) ;
if ( ! V_121 )
return;
F_6 ( & V_47 -> V_51 ,
V_50 -> V_116 ,
0xffffffff ,
V_48 -> V_109 | ( V_48 -> V_110 << 16 ) ) ;
F_6 ( & V_47 -> V_51 ,
V_50 -> V_117 ,
0xffffffff ,
( V_48 -> V_106 - 1 ) |
( ( V_48 -> V_107 - 1 ) << 16 ) ) ;
}
static int F_22 ( struct V_101 * V_123 ,
struct V_2 * V_3 )
{
struct V_46 * V_47 = F_20 ( V_123 ) ;
struct V_1 * V_48 =
F_1 ( V_3 ) ;
const struct V_49 * V_50 =
& V_47 -> V_51 . V_52 -> V_50 ;
struct V_124 * V_76 = V_48 -> V_4 . V_76 ;
const struct V_125 * V_6 ;
struct V_98 * V_126 ;
unsigned int V_127 ;
unsigned int V_128 ;
unsigned int V_129 ;
unsigned int V_130 ;
unsigned int V_45 ;
int V_131 = 0 ;
int V_132 = 0 ;
int V_133 = 1 ;
int V_134 = 1 ;
int V_44 ;
if ( ! V_48 -> V_4 . V_115 || ! V_76 )
return 0 ;
V_126 = F_23 ( V_3 -> V_48 , V_3 -> V_115 ) ;
V_6 = & V_126 -> V_135 ;
V_48 -> V_136 = V_3 -> V_136 ;
V_48 -> V_137 = V_3 -> V_137 ;
V_48 -> V_58 = V_3 -> V_58 ;
V_48 -> V_57 = V_3 -> V_57 ;
V_48 -> V_60 = V_3 -> V_60 ;
V_48 -> V_61 = V_3 -> V_61 ;
V_48 -> V_55 = V_3 -> V_55 ;
V_48 -> V_54 = V_3 -> V_54 ;
if ( ( V_48 -> V_136 | V_48 -> V_137 | V_48 -> V_57 | V_48 -> V_58 ) &
V_138 )
return - V_139 ;
V_48 -> V_136 >>= 16 ;
V_48 -> V_137 >>= 16 ;
V_48 -> V_57 >>= 16 ;
V_48 -> V_58 >>= 16 ;
V_48 -> V_95 = F_24 ( V_76 -> V_77 ) ;
if ( V_48 -> V_95 > V_140 )
return - V_139 ;
if ( F_11 ( V_48 -> V_4 . V_89 ) ) {
V_45 = V_48 -> V_54 ;
V_48 -> V_54 = V_48 -> V_55 ;
V_48 -> V_55 = V_45 ;
V_45 = V_48 -> V_57 ;
V_48 -> V_57 = V_48 -> V_58 ;
V_48 -> V_58 = V_45 ;
}
if ( V_48 -> V_60 + V_48 -> V_54 > V_6 -> V_141 )
V_127 = V_6 -> V_141 - V_48 -> V_60 ;
else
V_127 = V_48 -> V_54 ;
if ( V_48 -> V_60 < 0 ) {
V_127 += V_48 -> V_60 ;
V_131 = - V_48 -> V_60 ;
V_48 -> V_60 = 0 ;
}
if ( V_48 -> V_61 + V_48 -> V_55 > V_6 -> V_142 )
V_128 = V_6 -> V_142 - V_48 -> V_61 ;
else
V_128 = V_48 -> V_55 ;
if ( V_48 -> V_61 < 0 ) {
V_128 += V_48 -> V_61 ;
V_132 = - V_48 -> V_61 ;
V_48 -> V_61 = 0 ;
}
V_129 = F_25 ( V_127 * V_48 -> V_57 ,
V_48 -> V_54 ) ;
V_130 = F_25 ( V_128 * V_48 -> V_58 ,
V_48 -> V_55 ) ;
V_133 = F_26 ( V_76 -> V_77 ) ;
V_134 = F_27 ( V_76 -> V_77 ) ;
for ( V_44 = 0 ; V_44 < V_48 -> V_95 ; V_44 ++ ) {
unsigned int V_143 = 0 ;
int V_144 = V_44 ? V_133 : 1 ;
int V_145 = V_44 ? V_134 : 1 ;
V_48 -> V_108 [ V_44 ] = F_28 ( V_76 -> V_77 , V_44 ) ;
if ( ! V_48 -> V_108 [ V_44 ] )
return - V_139 ;
switch ( V_48 -> V_4 . V_89 & V_146 ) {
case V_147 :
V_143 = ( ( V_132 + V_48 -> V_137 + V_129 - 1 ) /
V_145 ) * V_76 -> V_148 [ V_44 ] ;
V_143 += ( ( V_131 + V_48 -> V_136 ) / V_144 ) *
V_48 -> V_108 [ V_44 ] ;
V_48 -> V_96 [ V_44 ] = ( ( V_129 - 1 ) / V_145 ) *
V_76 -> V_148 [ V_44 ] ;
V_48 -> V_97 [ V_44 ] = - V_76 -> V_148 [ V_44 ] - V_48 -> V_108 [ V_44 ] ;
break;
case V_149 :
V_143 = ( ( V_132 + V_48 -> V_137 + V_130 - 1 ) /
V_145 ) * V_76 -> V_148 [ V_44 ] ;
V_143 += ( ( V_131 + V_48 -> V_136 + V_129 - 1 ) /
V_144 ) * V_48 -> V_108 [ V_44 ] ;
V_48 -> V_96 [ V_44 ] = ( ( ( ( V_129 - 1 ) / V_144 ) - 1 ) *
V_48 -> V_108 [ V_44 ] ) - V_76 -> V_148 [ V_44 ] ;
V_48 -> V_97 [ V_44 ] = - 2 * V_48 -> V_108 [ V_44 ] ;
break;
case V_150 :
V_143 = ( ( V_132 + V_48 -> V_137 ) / V_145 ) *
V_76 -> V_148 [ V_44 ] ;
V_143 += ( ( V_131 + V_48 -> V_136 + V_130 - 1 ) /
V_144 ) * V_48 -> V_108 [ V_44 ] ;
V_48 -> V_96 [ V_44 ] = - ( ( ( V_129 - 1 ) / V_145 ) *
V_76 -> V_148 [ V_44 ] ) -
( 2 * V_48 -> V_108 [ V_44 ] ) ;
V_48 -> V_97 [ V_44 ] = V_76 -> V_148 [ V_44 ] - V_48 -> V_108 [ V_44 ] ;
break;
case V_151 :
default:
V_143 = ( ( V_132 + V_48 -> V_137 ) / V_145 ) *
V_76 -> V_148 [ V_44 ] ;
V_143 += ( ( V_131 + V_48 -> V_136 ) / V_144 ) *
V_48 -> V_108 [ V_44 ] ;
V_48 -> V_96 [ V_44 ] = V_76 -> V_148 [ V_44 ] -
( ( V_129 / V_144 ) *
V_48 -> V_108 [ V_44 ] ) ;
V_48 -> V_97 [ V_44 ] = 0 ;
break;
}
V_48 -> V_94 [ V_44 ] = V_143 + V_76 -> V_94 [ V_44 ] ;
}
V_48 -> V_57 = V_129 ;
V_48 -> V_58 = V_130 ;
V_48 -> V_54 = V_127 ;
V_48 -> V_55 = V_128 ;
if ( ! V_50 -> V_53 &&
( V_6 -> V_141 != V_48 -> V_54 ||
V_6 -> V_142 != V_48 -> V_55 ) )
return - V_139 ;
if ( V_47 -> V_51 . V_52 -> V_152 &&
V_48 -> V_55 > V_47 -> V_51 . V_52 -> V_152 )
return - V_139 ;
if ( V_47 -> V_51 . V_52 -> V_153 &&
V_48 -> V_54 > V_47 -> V_51 . V_52 -> V_153 )
return - V_139 ;
if ( ( V_48 -> V_55 != V_48 -> V_58 || V_48 -> V_54 != V_48 -> V_57 ) &&
( ! V_50 -> V_56 ||
F_4 ( V_48 -> V_4 . V_76 -> V_77 ) ) )
return - V_139 ;
if ( V_48 -> V_60 < 0 || V_48 -> V_61 < 0 )
return - V_139 ;
if ( V_48 -> V_54 + V_48 -> V_60 > V_6 -> V_141 ||
V_48 -> V_55 + V_48 -> V_61 > V_6 -> V_142 )
return - V_139 ;
return 0 ;
}
static int F_29 ( struct V_101 * V_123 ,
struct V_2 * V_154 )
{
struct V_2 * V_3 = (struct V_2 * ) V_154 ;
struct V_46 * V_47 = F_20 ( V_123 ) ;
struct V_1 * V_48 =
F_1 ( V_3 ) ;
int V_88 ;
V_88 = F_30 ( & V_47 -> V_51 ) ;
if ( ! V_88 )
V_48 -> V_155 = true ;
return V_88 ;
}
static void F_31 ( struct V_101 * V_123 ,
struct V_2 * V_156 )
{
struct V_2 * V_3 = (struct V_2 * ) V_156 ;
struct V_46 * V_47 = F_20 ( V_123 ) ;
struct V_1 * V_48 =
F_1 ( V_3 ) ;
if ( ! V_48 -> V_155 )
return;
F_32 ( & V_47 -> V_51 ) ;
V_48 -> V_155 = false ;
}
static void F_33 ( struct V_101 * V_123 ,
struct V_2 * V_157 )
{
struct V_46 * V_47 = F_20 ( V_123 ) ;
struct V_1 * V_48 =
F_1 ( V_123 -> V_48 ) ;
if ( ! V_123 -> V_48 -> V_115 || ! V_123 -> V_48 -> V_76 )
return;
F_5 ( V_47 , V_48 ) ;
F_8 ( V_47 , V_48 ) ;
F_10 ( V_47 , V_48 ) ;
F_12 ( V_47 , V_48 ) ;
F_21 ( V_47 , V_48 ) ;
F_34 ( & V_47 -> V_51 ) ;
}
static void F_35 ( struct V_101 * V_123 ,
struct V_2 * V_156 )
{
struct V_46 * V_47 = F_20 ( V_123 ) ;
F_36 ( & V_47 -> V_51 ) ;
}
static void F_37 ( struct V_101 * V_123 )
{
struct V_46 * V_47 = F_20 ( V_123 ) ;
if ( V_47 -> V_4 . V_76 )
F_38 ( V_47 -> V_4 . V_76 ) ;
F_39 ( V_123 -> V_158 , & V_47 -> V_51 ) ;
F_40 ( V_123 ) ;
F_41 ( V_123 -> V_158 -> V_158 , V_47 ) ;
}
static int F_42 ( struct V_101 * V_123 ,
struct V_2 * V_3 ,
struct V_159 * V_160 ,
T_2 V_161 )
{
struct V_46 * V_47 = F_20 ( V_123 ) ;
struct V_162 * V_163 = V_47 -> V_164 ;
struct V_1 * V_48 =
F_1 ( V_3 ) ;
if ( V_160 == V_163 -> V_80 )
V_48 -> V_80 = V_161 ;
else
return - V_139 ;
return 0 ;
}
static int F_43 ( struct V_101 * V_123 ,
const struct V_2 * V_3 ,
struct V_159 * V_160 ,
T_2 * V_161 )
{
struct V_46 * V_47 = F_20 ( V_123 ) ;
struct V_162 * V_163 = V_47 -> V_164 ;
const struct V_1 * V_48 =
F_2 ( V_3 , const struct V_1 , V_4 ) ;
if ( V_160 == V_163 -> V_80 )
* V_161 = V_48 -> V_80 ;
else
return - V_139 ;
return 0 ;
}
static int F_44 ( struct V_46 * V_47 ,
const struct V_165 * V_52 ,
struct V_162 * V_163 )
{
struct V_166 * V_166 = V_47 -> V_51 . V_167 -> V_166 ;
if ( V_52 -> type == V_168 ||
V_52 -> type == V_169 ) {
F_45 ( & V_47 -> V_4 . V_4 ,
V_163 -> V_80 , 255 ) ;
F_46 ( V_166 ,
V_52 -> V_170 +
F_47 ( & V_47 -> V_51 ) ,
V_87 ,
V_87 ) ;
}
if ( V_52 -> V_50 . V_96 && V_52 -> V_50 . V_97 ) {
int V_88 ;
V_88 = F_48 ( & V_47 -> V_4 ,
V_151 ,
V_151 |
V_147 |
V_149 |
V_150 ) ;
if ( V_88 )
return V_88 ;
}
if ( V_52 -> V_50 . V_171 ) {
F_49 ( V_166 ,
V_52 -> V_170 +
F_50 ( & V_47 -> V_51 , 0 ) ,
0x4c900091 ) ;
F_49 ( V_166 ,
V_52 -> V_170 +
F_50 ( & V_47 -> V_51 , 1 ) ,
0x7a5f5090 ) ;
F_49 ( V_166 ,
V_52 -> V_170 +
F_50 ( & V_47 -> V_51 , 2 ) ,
0x40040890 ) ;
}
return 0 ;
}
static void F_51 ( struct V_101 * V_123 )
{
struct V_1 * V_48 ;
if ( V_123 -> V_48 ) {
V_48 = F_1 ( V_123 -> V_48 ) ;
if ( V_48 -> V_4 . V_76 )
F_38 ( V_48 -> V_4 . V_76 ) ;
F_52 ( V_48 ) ;
V_123 -> V_48 = NULL ;
}
V_48 = F_53 ( sizeof( * V_48 ) , V_172 ) ;
if ( V_48 ) {
V_48 -> V_80 = 255 ;
V_123 -> V_48 = & V_48 -> V_4 ;
V_123 -> V_48 -> V_47 = V_123 ;
}
}
static struct V_2 *
F_54 ( struct V_101 * V_123 )
{
struct V_1 * V_48 =
F_1 ( V_123 -> V_48 ) ;
struct V_1 * V_173 ;
V_173 = F_55 ( V_48 , sizeof( * V_48 ) , V_172 ) ;
if ( ! V_173 )
return NULL ;
V_173 -> V_120 = false ;
V_173 -> V_155 = false ;
if ( V_173 -> V_4 . V_76 )
F_56 ( V_173 -> V_4 . V_76 ) ;
return & V_173 -> V_4 ;
}
static void F_57 ( struct V_101 * V_47 ,
struct V_2 * V_3 )
{
struct V_1 * V_48 =
F_1 ( V_3 ) ;
if ( V_3 -> V_76 )
F_38 ( V_3 -> V_76 ) ;
F_52 ( V_48 ) ;
}
static struct V_46 *
F_58 ( struct V_174 * V_158 ,
const struct V_165 * V_52 ,
struct V_162 * V_163 )
{
struct V_46 * V_47 ;
enum V_175 type ;
int V_88 ;
V_47 = F_59 ( V_158 -> V_158 , sizeof( * V_47 ) , V_172 ) ;
if ( ! V_47 )
return F_60 ( - V_176 ) ;
V_88 = F_61 ( V_158 , & V_47 -> V_51 , V_52 ) ;
if ( V_88 )
return F_60 ( V_88 ) ;
if ( V_52 -> type == V_177 )
type = V_72 ;
else if ( V_52 -> type == V_169 )
type = V_178 ;
else
type = V_179 ;
V_88 = F_62 ( V_158 , & V_47 -> V_4 , 0 ,
& V_180 ,
V_52 -> V_181 -> V_181 ,
V_52 -> V_181 -> V_182 , type , NULL ) ;
if ( V_88 )
return F_60 ( V_88 ) ;
F_63 ( & V_47 -> V_4 ,
& V_183 ) ;
V_88 = F_44 ( V_47 , V_52 , V_163 ) ;
if ( V_88 )
return F_60 ( V_88 ) ;
return V_47 ;
}
static struct V_162 *
F_64 ( struct V_174 * V_158 )
{
struct V_162 * V_163 ;
V_163 = F_59 ( V_158 -> V_158 , sizeof( * V_163 ) , V_172 ) ;
if ( ! V_163 )
return F_60 ( - V_176 ) ;
V_163 -> V_80 = F_65 ( V_158 , 0 , L_1 , 0 , 255 ) ;
if ( ! V_163 -> V_80 )
return F_60 ( - V_176 ) ;
return V_163 ;
}
struct V_184 *
F_66 ( struct V_174 * V_158 )
{
struct V_185 * V_186 = V_158 -> V_187 ;
struct V_162 * V_163 ;
struct V_184 * V_188 ;
const struct V_165 * V_189 = V_186 -> V_52 -> V_190 ;
int V_191 = V_186 -> V_52 -> V_191 ;
int V_44 ;
V_188 = F_59 ( V_158 -> V_158 , sizeof( * V_188 ) , V_172 ) ;
if ( ! V_188 )
return F_60 ( - V_176 ) ;
for ( V_44 = 0 ; V_44 < V_191 ; V_44 ++ ) {
if ( V_189 [ V_44 ] . type == V_168 )
V_188 -> V_192 ++ ;
}
if ( V_188 -> V_192 ) {
V_188 -> V_193 = F_59 ( V_158 -> V_158 ,
V_188 -> V_192 *
sizeof( * V_188 -> V_193 ) ,
V_172 ) ;
if ( ! V_188 -> V_193 )
return F_60 ( - V_176 ) ;
}
V_163 = F_64 ( V_158 ) ;
if ( F_17 ( V_163 ) )
return F_67 ( V_163 ) ;
V_188 -> V_192 = 0 ;
for ( V_44 = 0 ; V_44 < V_191 ; V_44 ++ ) {
struct V_46 * V_47 ;
if ( V_189 [ V_44 ] . type == V_194 )
continue;
V_47 = F_58 ( V_158 , & V_189 [ V_44 ] , V_163 ) ;
if ( F_17 ( V_47 ) )
return F_67 ( V_47 ) ;
V_47 -> V_164 = V_163 ;
switch ( V_189 [ V_44 ] . type ) {
case V_177 :
if ( V_188 -> V_113 )
return F_60 ( - V_139 ) ;
V_188 -> V_113 = V_47 ;
break;
case V_168 :
V_188 -> V_193 [ V_188 -> V_192 ++ ] = V_47 ;
break;
case V_169 :
if ( V_188 -> V_195 )
return F_60 ( - V_139 ) ;
V_188 -> V_195 = V_47 ;
break;
default:
break;
}
}
return V_188 ;
}
