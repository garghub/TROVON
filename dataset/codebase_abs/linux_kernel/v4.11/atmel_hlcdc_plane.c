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
if ( F_4 ( V_48 -> V_4 . V_76 -> V_5 -> V_5 ) )
V_70 |= V_77 ;
else
V_70 |= V_78 |
F_9 ( V_48 -> V_79 ) ;
}
F_6 ( & V_47 -> V_51 ,
V_80 ,
V_81 |
V_82 ,
V_83 |
V_48 -> V_84 ) ;
F_6 ( & V_47 -> V_51 , V_50 -> V_85 ,
V_74 |
V_75 |
V_78 |
V_86 |
V_77 |
V_73 |
V_71 , V_70 ) ;
}
static void F_10 ( struct V_46 * V_47 ,
struct V_1 * V_48 )
{
T_1 V_70 ;
int V_87 ;
V_87 = F_3 ( V_48 -> V_4 . V_76 -> V_5 -> V_5 ,
& V_70 ) ;
if ( V_87 )
return;
if ( ( V_48 -> V_4 . V_76 -> V_5 -> V_5 == V_41 ||
V_48 -> V_4 . V_76 -> V_5 -> V_5 == V_37 ) &&
F_11 ( V_48 -> V_4 . V_88 ) )
V_70 |= V_89 ;
F_6 ( & V_47 -> V_51 ,
V_90 ,
0xffffffff ,
V_70 ) ;
if ( V_48 -> V_4 . V_76 -> V_5 -> V_5 == V_15 )
V_70 = V_91 ;
else
V_70 = 0 ;
F_6 ( & V_47 -> V_51 ,
V_80 ,
V_91 , V_70 ) ;
}
static void F_12 ( struct V_46 * V_47 ,
struct V_1 * V_48 )
{
struct V_92 * V_51 = & V_47 -> V_51 ;
const struct V_49 * V_50 =
& V_51 -> V_52 -> V_50 ;
int V_44 ;
F_13 ( & V_47 -> V_51 , V_48 -> V_4 . V_76 ,
V_48 -> V_93 ) ;
for ( V_44 = 0 ; V_44 < V_48 -> V_94 ; V_44 ++ ) {
if ( V_50 -> V_95 [ V_44 ] ) {
F_6 ( & V_47 -> V_51 ,
V_50 -> V_95 [ V_44 ] ,
0xffffffff ,
V_48 -> V_95 [ V_44 ] ) ;
}
if ( V_50 -> V_96 [ V_44 ] ) {
F_6 ( & V_47 -> V_51 ,
V_50 -> V_96 [ V_44 ] ,
0xffffffff ,
V_48 -> V_96 [ V_44 ] ) ;
}
}
}
int F_14 ( struct V_97 * V_98 )
{
unsigned int V_99 [ 2 ] = { } ;
struct V_100 * V_47 ;
F_15 (plane, c_state) {
struct V_1 * V_101 ;
struct V_2 * V_102 ;
unsigned int V_103 , V_104 = 0 ;
int V_44 ;
V_102 = F_16 ( V_98 -> V_48 , V_47 ) ;
if ( F_17 ( V_102 ) )
return F_18 ( V_102 ) ;
V_101 =
F_1 ( V_102 ) ;
V_103 = ( V_101 -> V_57 * V_101 -> V_58 ) -
( V_101 -> V_105 * V_101 -> V_106 ) ;
for ( V_44 = 0 ; V_44 < V_101 -> V_94 ; V_44 ++ )
V_104 += V_103 * V_101 -> V_107 [ V_44 ] ;
if ( V_99 [ 0 ] <= V_99 [ 1 ] )
V_101 -> V_84 = 0 ;
else
V_101 -> V_84 = 1 ;
V_99 [ V_101 -> V_84 ] += V_104 ;
}
return 0 ;
}
int
F_19 ( struct V_97 * V_98 )
{
int V_108 = 0 , V_109 = 0 , V_105 = 0 , V_106 = 0 ;
const struct V_49 * V_50 ;
struct V_1 * V_110 ;
struct V_2 * V_111 ;
struct V_46 * V_112 ;
struct V_100 * V_113 ;
V_112 = F_20 ( V_98 -> V_114 -> V_112 ) ;
V_50 = & V_112 -> V_51 . V_52 -> V_50 ;
if ( ! V_50 -> V_115 || ! V_50 -> V_116 )
return 0 ;
V_111 = F_16 ( V_98 -> V_48 ,
& V_112 -> V_4 ) ;
if ( F_17 ( V_111 ) )
return F_18 ( V_111 ) ;
V_110 = F_1 ( V_111 ) ;
F_15 (ovl, c_state) {
struct V_1 * V_117 ;
struct V_2 * V_118 ;
if ( V_113 == V_98 -> V_114 -> V_112 )
continue;
V_118 = F_16 ( V_98 -> V_48 , V_113 ) ;
if ( F_17 ( V_118 ) )
return F_18 ( V_118 ) ;
V_117 = F_1 ( V_118 ) ;
if ( ! V_118 -> V_76 ||
F_4 ( V_118 -> V_76 -> V_5 -> V_5 ) ||
V_117 -> V_79 != 255 )
continue;
if ( V_117 -> V_55 * V_117 -> V_54 < V_106 * V_105 )
continue;
V_108 = V_117 -> V_60 ;
V_109 = V_117 -> V_61 ;
V_106 = V_117 -> V_55 ;
V_105 = V_117 -> V_54 ;
}
if ( V_108 == V_110 -> V_108 &&
V_109 == V_110 -> V_109 &&
V_105 == V_110 -> V_105 &&
V_106 == V_110 -> V_106 )
return 0 ;
V_110 -> V_108 = V_108 ;
V_110 -> V_109 = V_109 ;
V_110 -> V_105 = V_105 ;
V_110 -> V_106 = V_106 ;
V_110 -> V_119 = true ;
return 0 ;
}
static void
F_21 ( struct V_46 * V_47 ,
struct V_1 * V_48 )
{
const struct V_49 * V_50 =
& V_47 -> V_51 . V_52 -> V_50 ;
int V_120 = 0 ;
if ( ! V_48 -> V_119 )
return;
V_120 = V_48 -> V_106 * V_48 -> V_105 ;
F_6 ( & V_47 -> V_51 , V_50 -> V_85 ,
V_121 ,
V_120 ? V_121 : 0 ) ;
if ( ! V_120 )
return;
F_6 ( & V_47 -> V_51 ,
V_50 -> V_115 ,
0xffffffff ,
V_48 -> V_108 | ( V_48 -> V_109 << 16 ) ) ;
F_6 ( & V_47 -> V_51 ,
V_50 -> V_116 ,
0xffffffff ,
( V_48 -> V_105 - 1 ) |
( ( V_48 -> V_106 - 1 ) << 16 ) ) ;
}
static int F_22 ( struct V_100 * V_122 ,
struct V_2 * V_3 )
{
struct V_46 * V_47 = F_20 ( V_122 ) ;
struct V_1 * V_48 =
F_1 ( V_3 ) ;
const struct V_49 * V_50 =
& V_47 -> V_51 . V_52 -> V_50 ;
struct V_123 * V_76 = V_48 -> V_4 . V_76 ;
const struct V_124 * V_6 ;
struct V_97 * V_125 ;
unsigned int V_126 ;
unsigned int V_127 ;
unsigned int V_128 ;
unsigned int V_129 ;
unsigned int V_45 ;
int V_130 = 0 ;
int V_131 = 0 ;
int V_132 = 1 ;
int V_133 = 1 ;
int V_44 ;
if ( ! V_48 -> V_4 . V_114 || ! V_76 )
return 0 ;
V_125 = F_23 ( V_3 -> V_48 , V_3 -> V_114 ) ;
V_6 = & V_125 -> V_134 ;
V_48 -> V_135 = V_3 -> V_135 ;
V_48 -> V_136 = V_3 -> V_136 ;
V_48 -> V_58 = V_3 -> V_58 ;
V_48 -> V_57 = V_3 -> V_57 ;
V_48 -> V_60 = V_3 -> V_60 ;
V_48 -> V_61 = V_3 -> V_61 ;
V_48 -> V_55 = V_3 -> V_55 ;
V_48 -> V_54 = V_3 -> V_54 ;
if ( ( V_48 -> V_135 | V_48 -> V_136 | V_48 -> V_57 | V_48 -> V_58 ) &
V_137 )
return - V_138 ;
V_48 -> V_135 >>= 16 ;
V_48 -> V_136 >>= 16 ;
V_48 -> V_57 >>= 16 ;
V_48 -> V_58 >>= 16 ;
V_48 -> V_94 = V_76 -> V_5 -> V_139 ;
if ( V_48 -> V_94 > V_140 )
return - V_138 ;
if ( F_11 ( V_48 -> V_4 . V_88 ) ) {
V_45 = V_48 -> V_54 ;
V_48 -> V_54 = V_48 -> V_55 ;
V_48 -> V_55 = V_45 ;
V_45 = V_48 -> V_57 ;
V_48 -> V_57 = V_48 -> V_58 ;
V_48 -> V_58 = V_45 ;
}
if ( V_48 -> V_60 + V_48 -> V_54 > V_6 -> V_141 )
V_126 = V_6 -> V_141 - V_48 -> V_60 ;
else
V_126 = V_48 -> V_54 ;
if ( V_48 -> V_60 < 0 ) {
V_126 += V_48 -> V_60 ;
V_130 = - V_48 -> V_60 ;
V_48 -> V_60 = 0 ;
}
if ( V_48 -> V_61 + V_48 -> V_55 > V_6 -> V_142 )
V_127 = V_6 -> V_142 - V_48 -> V_61 ;
else
V_127 = V_48 -> V_55 ;
if ( V_48 -> V_61 < 0 ) {
V_127 += V_48 -> V_61 ;
V_131 = - V_48 -> V_61 ;
V_48 -> V_61 = 0 ;
}
V_128 = F_24 ( V_126 * V_48 -> V_57 ,
V_48 -> V_54 ) ;
V_129 = F_24 ( V_127 * V_48 -> V_58 ,
V_48 -> V_55 ) ;
V_132 = F_25 ( V_76 -> V_5 -> V_5 ) ;
V_133 = F_26 ( V_76 -> V_5 -> V_5 ) ;
for ( V_44 = 0 ; V_44 < V_48 -> V_94 ; V_44 ++ ) {
unsigned int V_143 = 0 ;
int V_144 = V_44 ? V_132 : 1 ;
int V_145 = V_44 ? V_133 : 1 ;
V_48 -> V_107 [ V_44 ] = V_76 -> V_5 -> V_146 [ V_44 ] ;
if ( ! V_48 -> V_107 [ V_44 ] )
return - V_138 ;
switch ( V_48 -> V_4 . V_88 & V_147 ) {
case V_148 :
V_143 = ( ( V_131 + V_48 -> V_136 + V_128 - 1 ) /
V_145 ) * V_76 -> V_149 [ V_44 ] ;
V_143 += ( ( V_130 + V_48 -> V_135 ) / V_144 ) *
V_48 -> V_107 [ V_44 ] ;
V_48 -> V_95 [ V_44 ] = ( ( V_128 - 1 ) / V_145 ) *
V_76 -> V_149 [ V_44 ] ;
V_48 -> V_96 [ V_44 ] = - V_76 -> V_149 [ V_44 ] - V_48 -> V_107 [ V_44 ] ;
break;
case V_150 :
V_143 = ( ( V_131 + V_48 -> V_136 + V_129 - 1 ) /
V_145 ) * V_76 -> V_149 [ V_44 ] ;
V_143 += ( ( V_130 + V_48 -> V_135 + V_128 - 1 ) /
V_144 ) * V_48 -> V_107 [ V_44 ] ;
V_48 -> V_95 [ V_44 ] = ( ( ( ( V_128 - 1 ) / V_144 ) - 1 ) *
V_48 -> V_107 [ V_44 ] ) - V_76 -> V_149 [ V_44 ] ;
V_48 -> V_96 [ V_44 ] = - 2 * V_48 -> V_107 [ V_44 ] ;
break;
case V_151 :
V_143 = ( ( V_131 + V_48 -> V_136 ) / V_145 ) *
V_76 -> V_149 [ V_44 ] ;
V_143 += ( ( V_130 + V_48 -> V_135 + V_129 - 1 ) /
V_144 ) * V_48 -> V_107 [ V_44 ] ;
V_48 -> V_95 [ V_44 ] = - ( ( ( V_128 - 1 ) / V_145 ) *
V_76 -> V_149 [ V_44 ] ) -
( 2 * V_48 -> V_107 [ V_44 ] ) ;
V_48 -> V_96 [ V_44 ] = V_76 -> V_149 [ V_44 ] - V_48 -> V_107 [ V_44 ] ;
break;
case V_152 :
default:
V_143 = ( ( V_131 + V_48 -> V_136 ) / V_145 ) *
V_76 -> V_149 [ V_44 ] ;
V_143 += ( ( V_130 + V_48 -> V_135 ) / V_144 ) *
V_48 -> V_107 [ V_44 ] ;
V_48 -> V_95 [ V_44 ] = V_76 -> V_149 [ V_44 ] -
( ( V_128 / V_144 ) *
V_48 -> V_107 [ V_44 ] ) ;
V_48 -> V_96 [ V_44 ] = 0 ;
break;
}
V_48 -> V_93 [ V_44 ] = V_143 + V_76 -> V_93 [ V_44 ] ;
}
V_48 -> V_57 = V_128 ;
V_48 -> V_58 = V_129 ;
V_48 -> V_54 = V_126 ;
V_48 -> V_55 = V_127 ;
if ( ! V_50 -> V_53 &&
( V_6 -> V_141 != V_48 -> V_54 ||
V_6 -> V_142 != V_48 -> V_55 ) )
return - V_138 ;
if ( V_47 -> V_51 . V_52 -> V_153 &&
V_48 -> V_55 > V_47 -> V_51 . V_52 -> V_153 )
return - V_138 ;
if ( V_47 -> V_51 . V_52 -> V_154 &&
V_48 -> V_54 > V_47 -> V_51 . V_52 -> V_154 )
return - V_138 ;
if ( ( V_48 -> V_55 != V_48 -> V_58 || V_48 -> V_54 != V_48 -> V_57 ) &&
( ! V_50 -> V_56 ||
F_4 ( V_48 -> V_4 . V_76 -> V_5 -> V_5 ) ) )
return - V_138 ;
if ( V_48 -> V_60 < 0 || V_48 -> V_61 < 0 )
return - V_138 ;
if ( V_48 -> V_54 + V_48 -> V_60 > V_6 -> V_141 ||
V_48 -> V_55 + V_48 -> V_61 > V_6 -> V_142 )
return - V_138 ;
return 0 ;
}
static int F_27 ( struct V_100 * V_122 ,
struct V_2 * V_155 )
{
struct V_2 * V_3 = (struct V_2 * ) V_155 ;
struct V_46 * V_47 = F_20 ( V_122 ) ;
struct V_1 * V_48 =
F_1 ( V_3 ) ;
int V_87 ;
V_87 = F_28 ( & V_47 -> V_51 ) ;
if ( ! V_87 )
V_48 -> V_156 = true ;
return V_87 ;
}
static void F_29 ( struct V_100 * V_122 ,
struct V_2 * V_157 )
{
struct V_2 * V_3 = (struct V_2 * ) V_157 ;
struct V_46 * V_47 = F_20 ( V_122 ) ;
struct V_1 * V_48 =
F_1 ( V_3 ) ;
if ( ! V_48 -> V_156 )
return;
F_30 ( & V_47 -> V_51 ) ;
V_48 -> V_156 = false ;
}
static void F_31 ( struct V_100 * V_122 ,
struct V_2 * V_158 )
{
struct V_46 * V_47 = F_20 ( V_122 ) ;
struct V_1 * V_48 =
F_1 ( V_122 -> V_48 ) ;
if ( ! V_122 -> V_48 -> V_114 || ! V_122 -> V_48 -> V_76 )
return;
F_5 ( V_47 , V_48 ) ;
F_8 ( V_47 , V_48 ) ;
F_10 ( V_47 , V_48 ) ;
F_12 ( V_47 , V_48 ) ;
F_21 ( V_47 , V_48 ) ;
F_32 ( & V_47 -> V_51 ) ;
}
static void F_33 ( struct V_100 * V_122 ,
struct V_2 * V_157 )
{
struct V_46 * V_47 = F_20 ( V_122 ) ;
F_34 ( & V_47 -> V_51 ) ;
}
static void F_35 ( struct V_100 * V_122 )
{
struct V_46 * V_47 = F_20 ( V_122 ) ;
if ( V_47 -> V_4 . V_76 )
F_36 ( V_47 -> V_4 . V_76 ) ;
F_37 ( V_122 -> V_159 , & V_47 -> V_51 ) ;
F_38 ( V_122 ) ;
F_39 ( V_122 -> V_159 -> V_159 , V_47 ) ;
}
static int F_40 ( struct V_100 * V_122 ,
struct V_2 * V_3 ,
struct V_160 * V_161 ,
T_2 V_162 )
{
struct V_46 * V_47 = F_20 ( V_122 ) ;
struct V_163 * V_164 = V_47 -> V_165 ;
struct V_1 * V_48 =
F_1 ( V_3 ) ;
if ( V_161 == V_164 -> V_79 )
V_48 -> V_79 = V_162 ;
else
return - V_138 ;
return 0 ;
}
static int F_41 ( struct V_100 * V_122 ,
const struct V_2 * V_3 ,
struct V_160 * V_161 ,
T_2 * V_162 )
{
struct V_46 * V_47 = F_20 ( V_122 ) ;
struct V_163 * V_164 = V_47 -> V_165 ;
const struct V_1 * V_48 =
F_2 ( V_3 , const struct V_1 , V_4 ) ;
if ( V_161 == V_164 -> V_79 )
* V_162 = V_48 -> V_79 ;
else
return - V_138 ;
return 0 ;
}
static int F_42 ( struct V_46 * V_47 ,
const struct V_166 * V_52 ,
struct V_163 * V_164 )
{
struct V_167 * V_167 = V_47 -> V_51 . V_168 -> V_167 ;
if ( V_52 -> type == V_169 ||
V_52 -> type == V_170 ) {
F_43 ( & V_47 -> V_4 . V_4 ,
V_164 -> V_79 , 255 ) ;
F_44 ( V_167 ,
V_52 -> V_171 +
F_45 ( & V_47 -> V_51 ) ,
V_86 ,
V_86 ) ;
}
if ( V_52 -> V_50 . V_95 && V_52 -> V_50 . V_96 ) {
int V_87 ;
V_87 = F_46 ( & V_47 -> V_4 ,
V_152 ,
V_152 |
V_148 |
V_150 |
V_151 ) ;
if ( V_87 )
return V_87 ;
}
if ( V_52 -> V_50 . V_172 ) {
F_47 ( V_167 ,
V_52 -> V_171 +
F_48 ( & V_47 -> V_51 , 0 ) ,
0x4c900091 ) ;
F_47 ( V_167 ,
V_52 -> V_171 +
F_48 ( & V_47 -> V_51 , 1 ) ,
0x7a5f5090 ) ;
F_47 ( V_167 ,
V_52 -> V_171 +
F_48 ( & V_47 -> V_51 , 2 ) ,
0x40040890 ) ;
}
return 0 ;
}
static void F_49 ( struct V_100 * V_122 )
{
struct V_1 * V_48 ;
if ( V_122 -> V_48 ) {
V_48 = F_1 ( V_122 -> V_48 ) ;
if ( V_48 -> V_4 . V_76 )
F_36 ( V_48 -> V_4 . V_76 ) ;
F_50 ( V_48 ) ;
V_122 -> V_48 = NULL ;
}
V_48 = F_51 ( sizeof( * V_48 ) , V_173 ) ;
if ( V_48 ) {
V_48 -> V_79 = 255 ;
V_122 -> V_48 = & V_48 -> V_4 ;
V_122 -> V_48 -> V_47 = V_122 ;
}
}
static struct V_2 *
F_52 ( struct V_100 * V_122 )
{
struct V_1 * V_48 =
F_1 ( V_122 -> V_48 ) ;
struct V_1 * V_174 ;
V_174 = F_53 ( V_48 , sizeof( * V_48 ) , V_173 ) ;
if ( ! V_174 )
return NULL ;
V_174 -> V_119 = false ;
V_174 -> V_156 = false ;
if ( V_174 -> V_4 . V_76 )
F_54 ( V_174 -> V_4 . V_76 ) ;
return & V_174 -> V_4 ;
}
static void F_55 ( struct V_100 * V_47 ,
struct V_2 * V_3 )
{
struct V_1 * V_48 =
F_1 ( V_3 ) ;
if ( V_3 -> V_76 )
F_36 ( V_3 -> V_76 ) ;
F_50 ( V_48 ) ;
}
static struct V_46 *
F_56 ( struct V_175 * V_159 ,
const struct V_166 * V_52 ,
struct V_163 * V_164 )
{
struct V_46 * V_47 ;
enum V_176 type ;
int V_87 ;
V_47 = F_57 ( V_159 -> V_159 , sizeof( * V_47 ) , V_173 ) ;
if ( ! V_47 )
return F_58 ( - V_177 ) ;
V_87 = F_59 ( V_159 , & V_47 -> V_51 , V_52 ) ;
if ( V_87 )
return F_58 ( V_87 ) ;
if ( V_52 -> type == V_178 )
type = V_72 ;
else if ( V_52 -> type == V_170 )
type = V_179 ;
else
type = V_180 ;
V_87 = F_60 ( V_159 , & V_47 -> V_4 , 0 ,
& V_181 ,
V_52 -> V_182 -> V_182 ,
V_52 -> V_182 -> V_183 , type , NULL ) ;
if ( V_87 )
return F_58 ( V_87 ) ;
F_61 ( & V_47 -> V_4 ,
& V_184 ) ;
V_87 = F_42 ( V_47 , V_52 , V_164 ) ;
if ( V_87 )
return F_58 ( V_87 ) ;
return V_47 ;
}
static struct V_163 *
F_62 ( struct V_175 * V_159 )
{
struct V_163 * V_164 ;
V_164 = F_57 ( V_159 -> V_159 , sizeof( * V_164 ) , V_173 ) ;
if ( ! V_164 )
return F_58 ( - V_177 ) ;
V_164 -> V_79 = F_63 ( V_159 , 0 , L_1 , 0 , 255 ) ;
if ( ! V_164 -> V_79 )
return F_58 ( - V_177 ) ;
return V_164 ;
}
struct V_185 *
F_64 ( struct V_175 * V_159 )
{
struct V_186 * V_187 = V_159 -> V_188 ;
struct V_163 * V_164 ;
struct V_185 * V_189 ;
const struct V_166 * V_190 = V_187 -> V_52 -> V_191 ;
int V_192 = V_187 -> V_52 -> V_192 ;
int V_44 ;
V_189 = F_57 ( V_159 -> V_159 , sizeof( * V_189 ) , V_173 ) ;
if ( ! V_189 )
return F_58 ( - V_177 ) ;
for ( V_44 = 0 ; V_44 < V_192 ; V_44 ++ ) {
if ( V_190 [ V_44 ] . type == V_169 )
V_189 -> V_193 ++ ;
}
if ( V_189 -> V_193 ) {
V_189 -> V_194 = F_57 ( V_159 -> V_159 ,
V_189 -> V_193 *
sizeof( * V_189 -> V_194 ) ,
V_173 ) ;
if ( ! V_189 -> V_194 )
return F_58 ( - V_177 ) ;
}
V_164 = F_62 ( V_159 ) ;
if ( F_17 ( V_164 ) )
return F_65 ( V_164 ) ;
V_189 -> V_193 = 0 ;
for ( V_44 = 0 ; V_44 < V_192 ; V_44 ++ ) {
struct V_46 * V_47 ;
if ( V_190 [ V_44 ] . type == V_195 )
continue;
V_47 = F_56 ( V_159 , & V_190 [ V_44 ] , V_164 ) ;
if ( F_17 ( V_47 ) )
return F_65 ( V_47 ) ;
V_47 -> V_165 = V_164 ;
switch ( V_190 [ V_44 ] . type ) {
case V_178 :
if ( V_189 -> V_112 )
return F_58 ( - V_138 ) ;
V_189 -> V_112 = V_47 ;
break;
case V_169 :
V_189 -> V_194 [ V_189 -> V_193 ++ ] = V_47 ;
break;
case V_170 :
if ( V_189 -> V_196 )
return F_58 ( - V_138 ) ;
V_189 -> V_196 = V_47 ;
break;
default:
break;
}
}
return V_189 ;
}
