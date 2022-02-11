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
( V_48 -> V_4 . V_89 & ( V_90 | V_91 ) ) )
V_70 |= V_92 ;
F_6 ( & V_47 -> V_51 ,
V_93 ,
0xffffffff ,
V_70 ) ;
if ( V_48 -> V_4 . V_76 -> V_77 == V_15 )
V_70 = V_94 ;
else
V_70 = 0 ;
F_6 ( & V_47 -> V_51 ,
V_81 ,
V_94 , V_70 ) ;
}
static void F_11 ( struct V_46 * V_47 ,
struct V_1 * V_48 )
{
struct V_95 * V_51 = & V_47 -> V_51 ;
const struct V_49 * V_50 =
& V_51 -> V_52 -> V_50 ;
int V_44 ;
F_12 ( & V_47 -> V_51 , V_48 -> V_4 . V_76 ,
V_48 -> V_96 ) ;
for ( V_44 = 0 ; V_44 < V_48 -> V_97 ; V_44 ++ ) {
if ( V_50 -> V_98 [ V_44 ] ) {
F_6 ( & V_47 -> V_51 ,
V_50 -> V_98 [ V_44 ] ,
0xffffffff ,
V_48 -> V_98 [ V_44 ] ) ;
}
if ( V_50 -> V_99 [ V_44 ] ) {
F_6 ( & V_47 -> V_51 ,
V_50 -> V_99 [ V_44 ] ,
0xffffffff ,
V_48 -> V_99 [ V_44 ] ) ;
}
}
}
int F_13 ( struct V_100 * V_101 )
{
unsigned int V_102 [ 2 ] = { } ;
struct V_103 * V_47 ;
F_14 (plane, c_state) {
struct V_1 * V_104 ;
struct V_2 * V_105 ;
unsigned int V_106 , V_107 = 0 ;
int V_44 ;
V_105 = F_15 ( V_101 -> V_48 , V_47 ) ;
if ( F_16 ( V_105 ) )
return F_17 ( V_105 ) ;
V_104 =
F_1 ( V_105 ) ;
V_106 = ( V_104 -> V_57 * V_104 -> V_58 ) -
( V_104 -> V_108 * V_104 -> V_109 ) ;
for ( V_44 = 0 ; V_44 < V_104 -> V_97 ; V_44 ++ )
V_107 += V_106 * V_104 -> V_110 [ V_44 ] ;
if ( V_102 [ 0 ] <= V_102 [ 1 ] )
V_104 -> V_85 = 0 ;
else
V_104 -> V_85 = 1 ;
V_102 [ V_104 -> V_85 ] += V_107 ;
}
return 0 ;
}
int
F_18 ( struct V_100 * V_101 )
{
int V_111 = 0 , V_112 = 0 , V_108 = 0 , V_109 = 0 ;
const struct V_49 * V_50 ;
struct V_1 * V_113 ;
struct V_2 * V_114 ;
struct V_46 * V_115 ;
struct V_103 * V_116 ;
V_115 = F_19 ( V_101 -> V_117 -> V_115 ) ;
V_50 = & V_115 -> V_51 . V_52 -> V_50 ;
if ( ! V_50 -> V_118 || ! V_50 -> V_119 )
return 0 ;
V_114 = F_15 ( V_101 -> V_48 ,
& V_115 -> V_4 ) ;
if ( F_16 ( V_114 ) )
return F_17 ( V_114 ) ;
V_113 = F_1 ( V_114 ) ;
F_14 (ovl, c_state) {
struct V_1 * V_120 ;
struct V_2 * V_121 ;
if ( V_116 == V_101 -> V_117 -> V_115 )
continue;
V_121 = F_15 ( V_101 -> V_48 , V_116 ) ;
if ( F_16 ( V_121 ) )
return F_17 ( V_121 ) ;
V_120 = F_1 ( V_121 ) ;
if ( ! V_121 -> V_76 ||
F_4 ( V_121 -> V_76 -> V_77 ) ||
V_120 -> V_80 != 255 )
continue;
if ( V_120 -> V_55 * V_120 -> V_54 < V_109 * V_108 )
continue;
V_111 = V_120 -> V_60 ;
V_112 = V_120 -> V_61 ;
V_109 = V_120 -> V_55 ;
V_108 = V_120 -> V_54 ;
}
if ( V_111 == V_113 -> V_111 &&
V_112 == V_113 -> V_112 &&
V_108 == V_113 -> V_108 &&
V_109 == V_113 -> V_109 )
return 0 ;
V_113 -> V_111 = V_111 ;
V_113 -> V_112 = V_112 ;
V_113 -> V_108 = V_108 ;
V_113 -> V_109 = V_109 ;
V_113 -> V_122 = true ;
return 0 ;
}
static void
F_20 ( struct V_46 * V_47 ,
struct V_1 * V_48 )
{
const struct V_49 * V_50 =
& V_47 -> V_51 . V_52 -> V_50 ;
int V_123 = 0 ;
if ( ! V_48 -> V_122 )
return;
V_123 = V_48 -> V_109 * V_48 -> V_108 ;
F_6 ( & V_47 -> V_51 , V_50 -> V_86 ,
V_124 ,
V_123 ? V_124 : 0 ) ;
if ( ! V_123 )
return;
F_6 ( & V_47 -> V_51 ,
V_50 -> V_118 ,
0xffffffff ,
V_48 -> V_111 | ( V_48 -> V_112 << 16 ) ) ;
F_6 ( & V_47 -> V_51 ,
V_50 -> V_119 ,
0xffffffff ,
( V_48 -> V_108 - 1 ) |
( ( V_48 -> V_109 - 1 ) << 16 ) ) ;
}
static int F_21 ( struct V_103 * V_125 ,
struct V_2 * V_3 )
{
struct V_46 * V_47 = F_19 ( V_125 ) ;
struct V_1 * V_48 =
F_1 ( V_3 ) ;
const struct V_49 * V_50 =
& V_47 -> V_51 . V_52 -> V_50 ;
struct V_126 * V_76 = V_48 -> V_4 . V_76 ;
const struct V_127 * V_6 ;
struct V_100 * V_128 ;
unsigned int V_129 ;
unsigned int V_130 ;
unsigned int V_131 ;
unsigned int V_132 ;
unsigned int V_45 ;
int V_133 = 0 ;
int V_134 = 0 ;
int V_135 = 1 ;
int V_136 = 1 ;
int V_44 ;
if ( ! V_48 -> V_4 . V_117 || ! V_76 )
return 0 ;
V_128 = F_22 ( V_3 -> V_48 , V_3 -> V_117 ) ;
V_6 = & V_128 -> V_137 ;
V_48 -> V_138 = V_3 -> V_138 ;
V_48 -> V_139 = V_3 -> V_139 ;
V_48 -> V_58 = V_3 -> V_58 ;
V_48 -> V_57 = V_3 -> V_57 ;
V_48 -> V_60 = V_3 -> V_60 ;
V_48 -> V_61 = V_3 -> V_61 ;
V_48 -> V_55 = V_3 -> V_55 ;
V_48 -> V_54 = V_3 -> V_54 ;
if ( ( V_48 -> V_138 | V_48 -> V_139 | V_48 -> V_57 | V_48 -> V_58 ) &
V_140 )
return - V_141 ;
V_48 -> V_138 >>= 16 ;
V_48 -> V_139 >>= 16 ;
V_48 -> V_57 >>= 16 ;
V_48 -> V_58 >>= 16 ;
V_48 -> V_97 = F_23 ( V_76 -> V_77 ) ;
if ( V_48 -> V_97 > V_142 )
return - V_141 ;
if ( V_48 -> V_4 . V_89 & ( V_90 | V_91 ) ) {
V_45 = V_48 -> V_54 ;
V_48 -> V_54 = V_48 -> V_55 ;
V_48 -> V_55 = V_45 ;
V_45 = V_48 -> V_57 ;
V_48 -> V_57 = V_48 -> V_58 ;
V_48 -> V_58 = V_45 ;
}
if ( V_48 -> V_60 + V_48 -> V_54 > V_6 -> V_143 )
V_129 = V_6 -> V_143 - V_48 -> V_60 ;
else
V_129 = V_48 -> V_54 ;
if ( V_48 -> V_60 < 0 ) {
V_129 += V_48 -> V_60 ;
V_133 = - V_48 -> V_60 ;
V_48 -> V_60 = 0 ;
}
if ( V_48 -> V_61 + V_48 -> V_55 > V_6 -> V_144 )
V_130 = V_6 -> V_144 - V_48 -> V_61 ;
else
V_130 = V_48 -> V_55 ;
if ( V_48 -> V_61 < 0 ) {
V_130 += V_48 -> V_61 ;
V_134 = - V_48 -> V_61 ;
V_48 -> V_61 = 0 ;
}
V_131 = F_24 ( V_129 * V_48 -> V_57 ,
V_48 -> V_54 ) ;
V_132 = F_24 ( V_130 * V_48 -> V_58 ,
V_48 -> V_55 ) ;
V_135 = F_25 ( V_76 -> V_77 ) ;
V_136 = F_26 ( V_76 -> V_77 ) ;
for ( V_44 = 0 ; V_44 < V_48 -> V_97 ; V_44 ++ ) {
unsigned int V_145 = 0 ;
int V_146 = V_44 ? V_135 : 1 ;
int V_147 = V_44 ? V_136 : 1 ;
V_48 -> V_110 [ V_44 ] = F_27 ( V_76 -> V_77 , V_44 ) ;
if ( ! V_48 -> V_110 [ V_44 ] )
return - V_141 ;
switch ( V_48 -> V_4 . V_89 & V_148 ) {
case V_90 :
V_145 = ( ( V_134 + V_48 -> V_139 + V_131 - 1 ) /
V_147 ) * V_76 -> V_149 [ V_44 ] ;
V_145 += ( ( V_133 + V_48 -> V_138 ) / V_146 ) *
V_48 -> V_110 [ V_44 ] ;
V_48 -> V_98 [ V_44 ] = ( ( V_131 - 1 ) / V_147 ) *
V_76 -> V_149 [ V_44 ] ;
V_48 -> V_99 [ V_44 ] = - V_76 -> V_149 [ V_44 ] - V_48 -> V_110 [ V_44 ] ;
break;
case V_150 :
V_145 = ( ( V_134 + V_48 -> V_139 + V_132 - 1 ) /
V_147 ) * V_76 -> V_149 [ V_44 ] ;
V_145 += ( ( V_133 + V_48 -> V_138 + V_131 - 1 ) /
V_146 ) * V_48 -> V_110 [ V_44 ] ;
V_48 -> V_98 [ V_44 ] = ( ( ( ( V_131 - 1 ) / V_146 ) - 1 ) *
V_48 -> V_110 [ V_44 ] ) - V_76 -> V_149 [ V_44 ] ;
V_48 -> V_99 [ V_44 ] = - 2 * V_48 -> V_110 [ V_44 ] ;
break;
case V_91 :
V_145 = ( ( V_134 + V_48 -> V_139 ) / V_147 ) *
V_76 -> V_149 [ V_44 ] ;
V_145 += ( ( V_133 + V_48 -> V_138 + V_132 - 1 ) /
V_146 ) * V_48 -> V_110 [ V_44 ] ;
V_48 -> V_98 [ V_44 ] = - ( ( ( V_131 - 1 ) / V_147 ) *
V_76 -> V_149 [ V_44 ] ) -
( 2 * V_48 -> V_110 [ V_44 ] ) ;
V_48 -> V_99 [ V_44 ] = V_76 -> V_149 [ V_44 ] - V_48 -> V_110 [ V_44 ] ;
break;
case V_151 :
default:
V_145 = ( ( V_134 + V_48 -> V_139 ) / V_147 ) *
V_76 -> V_149 [ V_44 ] ;
V_145 += ( ( V_133 + V_48 -> V_138 ) / V_146 ) *
V_48 -> V_110 [ V_44 ] ;
V_48 -> V_98 [ V_44 ] = V_76 -> V_149 [ V_44 ] -
( ( V_131 / V_146 ) *
V_48 -> V_110 [ V_44 ] ) ;
V_48 -> V_99 [ V_44 ] = 0 ;
break;
}
V_48 -> V_96 [ V_44 ] = V_145 + V_76 -> V_96 [ V_44 ] ;
}
V_48 -> V_57 = V_131 ;
V_48 -> V_58 = V_132 ;
V_48 -> V_54 = V_129 ;
V_48 -> V_55 = V_130 ;
if ( ! V_50 -> V_53 &&
( V_6 -> V_143 != V_48 -> V_54 ||
V_6 -> V_144 != V_48 -> V_55 ) )
return - V_141 ;
if ( V_47 -> V_51 . V_52 -> V_152 &&
V_48 -> V_55 > V_47 -> V_51 . V_52 -> V_152 )
return - V_141 ;
if ( V_47 -> V_51 . V_52 -> V_153 &&
V_48 -> V_54 > V_47 -> V_51 . V_52 -> V_153 )
return - V_141 ;
if ( ( V_48 -> V_55 != V_48 -> V_58 || V_48 -> V_54 != V_48 -> V_57 ) &&
( ! V_50 -> V_56 ||
F_4 ( V_48 -> V_4 . V_76 -> V_77 ) ) )
return - V_141 ;
if ( V_48 -> V_60 < 0 || V_48 -> V_61 < 0 )
return - V_141 ;
if ( V_48 -> V_54 + V_48 -> V_60 > V_6 -> V_143 ||
V_48 -> V_55 + V_48 -> V_61 > V_6 -> V_144 )
return - V_141 ;
return 0 ;
}
static int F_28 ( struct V_103 * V_125 ,
struct V_2 * V_154 )
{
struct V_2 * V_3 = (struct V_2 * ) V_154 ;
struct V_46 * V_47 = F_19 ( V_125 ) ;
struct V_1 * V_48 =
F_1 ( V_3 ) ;
int V_88 ;
V_88 = F_29 ( & V_47 -> V_51 ) ;
if ( ! V_88 )
V_48 -> V_155 = true ;
return V_88 ;
}
static void F_30 ( struct V_103 * V_125 ,
struct V_2 * V_156 )
{
struct V_2 * V_3 = (struct V_2 * ) V_156 ;
struct V_46 * V_47 = F_19 ( V_125 ) ;
struct V_1 * V_48 =
F_1 ( V_3 ) ;
if ( ! V_48 -> V_155 )
return;
F_31 ( & V_47 -> V_51 ) ;
V_48 -> V_155 = false ;
}
static void F_32 ( struct V_103 * V_125 ,
struct V_2 * V_157 )
{
struct V_46 * V_47 = F_19 ( V_125 ) ;
struct V_1 * V_48 =
F_1 ( V_125 -> V_48 ) ;
if ( ! V_125 -> V_48 -> V_117 || ! V_125 -> V_48 -> V_76 )
return;
F_5 ( V_47 , V_48 ) ;
F_8 ( V_47 , V_48 ) ;
F_10 ( V_47 , V_48 ) ;
F_11 ( V_47 , V_48 ) ;
F_20 ( V_47 , V_48 ) ;
F_33 ( & V_47 -> V_51 ) ;
}
static void F_34 ( struct V_103 * V_125 ,
struct V_2 * V_156 )
{
struct V_46 * V_47 = F_19 ( V_125 ) ;
F_35 ( & V_47 -> V_51 ) ;
}
static void F_36 ( struct V_103 * V_125 )
{
struct V_46 * V_47 = F_19 ( V_125 ) ;
if ( V_47 -> V_4 . V_76 )
F_37 ( V_47 -> V_4 . V_76 ) ;
F_38 ( V_125 -> V_158 , & V_47 -> V_51 ) ;
F_39 ( V_125 ) ;
F_40 ( V_125 -> V_158 -> V_158 , V_47 ) ;
}
static int F_41 ( struct V_103 * V_125 ,
struct V_2 * V_3 ,
struct V_159 * V_160 ,
T_2 V_161 )
{
struct V_46 * V_47 = F_19 ( V_125 ) ;
struct V_162 * V_163 = V_47 -> V_164 ;
struct V_1 * V_48 =
F_1 ( V_3 ) ;
if ( V_160 == V_163 -> V_80 )
V_48 -> V_80 = V_161 ;
else
return - V_141 ;
return 0 ;
}
static int F_42 ( struct V_103 * V_125 ,
const struct V_2 * V_3 ,
struct V_159 * V_160 ,
T_2 * V_161 )
{
struct V_46 * V_47 = F_19 ( V_125 ) ;
struct V_162 * V_163 = V_47 -> V_164 ;
const struct V_1 * V_48 =
F_2 ( V_3 , const struct V_1 , V_4 ) ;
if ( V_160 == V_163 -> V_80 )
* V_161 = V_48 -> V_80 ;
else
return - V_141 ;
return 0 ;
}
static void F_43 ( struct V_46 * V_47 ,
const struct V_165 * V_52 ,
struct V_162 * V_163 )
{
struct V_166 * V_166 = V_47 -> V_51 . V_167 -> V_166 ;
if ( V_52 -> type == V_168 ||
V_52 -> type == V_169 ) {
F_44 ( & V_47 -> V_4 . V_4 ,
V_163 -> V_80 , 255 ) ;
F_45 ( V_166 ,
V_52 -> V_170 +
F_46 ( & V_47 -> V_51 ) ,
V_87 ,
V_87 ) ;
}
if ( V_52 -> V_50 . V_98 && V_52 -> V_50 . V_99 )
F_44 ( & V_47 -> V_4 . V_4 ,
V_47 -> V_4 . V_158 -> V_171 . V_172 ,
V_151 ) ;
if ( V_52 -> V_50 . V_173 ) {
F_47 ( V_166 ,
V_52 -> V_170 +
F_48 ( & V_47 -> V_51 , 0 ) ,
0x4c900091 ) ;
F_47 ( V_166 ,
V_52 -> V_170 +
F_48 ( & V_47 -> V_51 , 1 ) ,
0x7a5f5090 ) ;
F_47 ( V_166 ,
V_52 -> V_170 +
F_48 ( & V_47 -> V_51 , 2 ) ,
0x40040890 ) ;
}
}
static void F_49 ( struct V_103 * V_125 )
{
struct V_1 * V_48 ;
if ( V_125 -> V_48 ) {
V_48 = F_1 ( V_125 -> V_48 ) ;
if ( V_48 -> V_4 . V_76 )
F_37 ( V_48 -> V_4 . V_76 ) ;
F_50 ( V_48 ) ;
V_125 -> V_48 = NULL ;
}
V_48 = F_51 ( sizeof( * V_48 ) , V_174 ) ;
if ( V_48 ) {
V_48 -> V_80 = 255 ;
V_125 -> V_48 = & V_48 -> V_4 ;
V_125 -> V_48 -> V_47 = V_125 ;
}
}
static struct V_2 *
F_52 ( struct V_103 * V_125 )
{
struct V_1 * V_48 =
F_1 ( V_125 -> V_48 ) ;
struct V_1 * V_175 ;
V_175 = F_53 ( V_48 , sizeof( * V_48 ) , V_174 ) ;
if ( ! V_175 )
return NULL ;
V_175 -> V_122 = false ;
V_175 -> V_155 = false ;
if ( V_175 -> V_4 . V_76 )
F_54 ( V_175 -> V_4 . V_76 ) ;
return & V_175 -> V_4 ;
}
static void F_55 ( struct V_103 * V_47 ,
struct V_2 * V_3 )
{
struct V_1 * V_48 =
F_1 ( V_3 ) ;
if ( V_3 -> V_76 )
F_37 ( V_3 -> V_76 ) ;
F_50 ( V_48 ) ;
}
static struct V_46 *
F_56 ( struct V_176 * V_158 ,
const struct V_165 * V_52 ,
struct V_162 * V_163 )
{
struct V_46 * V_47 ;
enum V_177 type ;
int V_88 ;
V_47 = F_57 ( V_158 -> V_158 , sizeof( * V_47 ) , V_174 ) ;
if ( ! V_47 )
return F_58 ( - V_178 ) ;
V_88 = F_59 ( V_158 , & V_47 -> V_51 , V_52 ) ;
if ( V_88 )
return F_58 ( V_88 ) ;
if ( V_52 -> type == V_179 )
type = V_72 ;
else if ( V_52 -> type == V_169 )
type = V_180 ;
else
type = V_181 ;
V_88 = F_60 ( V_158 , & V_47 -> V_4 , 0 ,
& V_182 ,
V_52 -> V_183 -> V_183 ,
V_52 -> V_183 -> V_184 , type , NULL ) ;
if ( V_88 )
return F_58 ( V_88 ) ;
F_61 ( & V_47 -> V_4 ,
& V_185 ) ;
F_43 ( V_47 , V_52 , V_163 ) ;
return V_47 ;
}
static struct V_162 *
F_62 ( struct V_176 * V_158 )
{
struct V_162 * V_163 ;
V_163 = F_57 ( V_158 -> V_158 , sizeof( * V_163 ) , V_174 ) ;
if ( ! V_163 )
return F_58 ( - V_178 ) ;
V_163 -> V_80 = F_63 ( V_158 , 0 , L_1 , 0 , 255 ) ;
if ( ! V_163 -> V_80 )
return F_58 ( - V_178 ) ;
V_158 -> V_171 . V_172 =
F_64 ( V_158 ,
V_151 |
V_90 |
V_150 |
V_91 ) ;
if ( ! V_158 -> V_171 . V_172 )
return F_58 ( - V_178 ) ;
return V_163 ;
}
struct V_186 *
F_65 ( struct V_176 * V_158 )
{
struct V_187 * V_188 = V_158 -> V_189 ;
struct V_162 * V_163 ;
struct V_186 * V_190 ;
const struct V_165 * V_191 = V_188 -> V_52 -> V_192 ;
int V_193 = V_188 -> V_52 -> V_193 ;
int V_44 ;
V_190 = F_57 ( V_158 -> V_158 , sizeof( * V_190 ) , V_174 ) ;
if ( ! V_190 )
return F_58 ( - V_178 ) ;
for ( V_44 = 0 ; V_44 < V_193 ; V_44 ++ ) {
if ( V_191 [ V_44 ] . type == V_168 )
V_190 -> V_194 ++ ;
}
if ( V_190 -> V_194 ) {
V_190 -> V_195 = F_57 ( V_158 -> V_158 ,
V_190 -> V_194 *
sizeof( * V_190 -> V_195 ) ,
V_174 ) ;
if ( ! V_190 -> V_195 )
return F_58 ( - V_178 ) ;
}
V_163 = F_62 ( V_158 ) ;
if ( F_16 ( V_163 ) )
return F_66 ( V_163 ) ;
V_190 -> V_194 = 0 ;
for ( V_44 = 0 ; V_44 < V_193 ; V_44 ++ ) {
struct V_46 * V_47 ;
if ( V_191 [ V_44 ] . type == V_196 )
continue;
V_47 = F_56 ( V_158 , & V_191 [ V_44 ] , V_163 ) ;
if ( F_16 ( V_47 ) )
return F_66 ( V_47 ) ;
V_47 -> V_164 = V_163 ;
switch ( V_191 [ V_44 ] . type ) {
case V_179 :
if ( V_190 -> V_115 )
return F_58 ( - V_141 ) ;
V_190 -> V_115 = V_47 ;
break;
case V_168 :
V_190 -> V_195 [ V_190 -> V_194 ++ ] = V_47 ;
break;
case V_169 :
if ( V_190 -> V_197 )
return F_58 ( - V_141 ) ;
V_190 -> V_197 = V_47 ;
break;
default:
break;
}
}
return V_190 ;
}
