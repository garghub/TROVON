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
static T_1 F_5 ( T_1 V_46 ,
T_1 V_47 ,
T_1 V_48 )
{
T_1 V_49 , V_50 ;
V_49 = ( 256 * ( ( 8 * ( V_46 - 1 ) ) - V_48 ) ) / ( V_47 - 1 ) ;
V_50 = ( ( V_49 * ( V_47 - 1 ) ) + ( 256 * V_48 ) ) / 2048 ;
if ( V_50 > V_46 - 1 )
V_49 -- ;
return V_49 ;
}
static void
F_6 ( struct V_51 * V_52 ,
const T_1 * V_53 , int V_54 ,
unsigned int V_55 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < V_54 ; V_44 ++ )
F_7 ( & V_52 -> V_56 , V_55 + V_44 ,
V_53 [ V_44 ] ) ;
}
void F_8 ( struct V_51 * V_52 ,
struct V_1 * V_57 )
{
const struct V_58 * V_59 = V_52 -> V_56 . V_59 ;
T_1 V_60 , V_61 ;
if ( ! V_59 -> V_62 . V_63 )
return;
if ( V_57 -> V_64 == V_57 -> V_65 && V_57 -> V_66 == V_57 -> V_67 ) {
F_7 ( & V_52 -> V_56 ,
V_59 -> V_62 . V_63 , 0 ) ;
return;
}
if ( V_59 -> V_62 . V_68 . V_69 ) {
V_60 = F_5 ( V_57 -> V_65 ,
V_57 -> V_64 ,
V_70 ) ;
V_61 = F_5 ( V_57 -> V_67 ,
V_57 -> V_66 ,
V_71 ) ;
F_6 ( V_52 ,
V_57 -> V_64 < V_57 -> V_65 ?
V_72 :
V_73 ,
F_9 ( V_73 ) ,
V_59 -> V_62 . V_68 . V_69 ) ;
F_6 ( V_52 ,
V_57 -> V_66 < V_57 -> V_67 ?
V_74 :
V_75 ,
F_9 ( V_75 ) ,
V_59 -> V_62 . V_68 . V_76 ) ;
} else {
V_60 = ( 1024 * V_57 -> V_65 ) / V_57 -> V_64 ;
V_61 = ( 1024 * V_57 -> V_67 ) / V_57 -> V_66 ;
}
F_7 ( & V_52 -> V_56 , V_59 -> V_62 . V_63 ,
V_77 |
F_10 ( V_60 ,
V_61 ) ) ;
}
static void
F_11 ( struct V_51 * V_52 ,
struct V_1 * V_57 )
{
const struct V_58 * V_59 = V_52 -> V_56 . V_59 ;
if ( V_59 -> V_62 . V_54 )
F_7 ( & V_52 -> V_56 , V_59 -> V_62 . V_54 ,
F_12 ( V_57 -> V_64 ,
V_57 -> V_66 ) ) ;
if ( V_59 -> V_62 . V_78 )
F_7 ( & V_52 -> V_56 ,
V_59 -> V_62 . V_78 ,
F_12 ( V_57 -> V_65 ,
V_57 -> V_67 ) ) ;
if ( V_59 -> V_62 . V_79 )
F_7 ( & V_52 -> V_56 , V_59 -> V_62 . V_79 ,
F_13 ( V_57 -> V_80 ,
V_57 -> V_81 ) ) ;
F_8 ( V_52 , V_57 ) ;
}
static void
F_14 ( struct V_51 * V_52 ,
struct V_1 * V_57 )
{
unsigned int V_82 = V_83 | V_57 -> V_84 ;
const struct V_58 * V_59 = V_52 -> V_56 . V_59 ;
T_1 V_5 = V_57 -> V_4 . V_85 -> V_5 -> V_5 ;
if ( V_5 == V_15 )
V_82 |= V_86 ;
F_7 ( & V_52 -> V_56 , V_87 ,
V_82 ) ;
V_82 = V_88 ;
if ( V_52 -> V_4 . type != V_89 ) {
V_82 |= V_90 | V_91 |
V_92 ;
if ( F_4 ( V_5 ) )
V_82 |= V_93 ;
else
V_82 |= V_94 |
F_15 ( V_57 -> V_95 ) ;
}
if ( V_57 -> V_96 && V_57 -> V_97 )
V_82 |= V_98 ;
F_7 ( & V_52 -> V_56 , V_59 -> V_62 . V_99 ,
V_82 ) ;
}
static void F_16 ( struct V_51 * V_52 ,
struct V_1 * V_57 )
{
T_1 V_82 ;
int V_100 ;
V_100 = F_3 ( V_57 -> V_4 . V_85 -> V_5 -> V_5 ,
& V_82 ) ;
if ( V_100 )
return;
if ( ( V_57 -> V_4 . V_85 -> V_5 -> V_5 == V_41 ||
V_57 -> V_4 . V_85 -> V_5 -> V_5 == V_37 ) &&
F_17 ( V_57 -> V_4 . V_101 ) )
V_82 |= V_102 ;
F_7 ( & V_52 -> V_56 ,
V_103 , V_82 ) ;
}
static void F_18 ( struct V_51 * V_52 ,
struct V_1 * V_57 )
{
const struct V_58 * V_59 = V_52 -> V_56 . V_59 ;
struct V_104 * V_85 = V_57 -> V_4 . V_85 ;
T_1 V_105 ;
int V_44 ;
V_105 = F_19 ( & V_52 -> V_56 , V_106 ) ;
for ( V_44 = 0 ; V_44 < V_57 -> V_107 ; V_44 ++ ) {
struct V_108 * V_109 = F_20 ( V_85 , V_44 ) ;
V_57 -> V_110 [ V_44 ] -> V_111 = V_109 -> V_112 + V_57 -> V_113 [ V_44 ] ;
F_21 ( & V_52 -> V_56 ,
F_22 ( V_44 ) ,
V_57 -> V_110 [ V_44 ] -> V_114 ) ;
if ( ! ( V_105 & V_115 ) ) {
F_21 ( & V_52 -> V_56 ,
F_23 ( V_44 ) ,
V_57 -> V_110 [ V_44 ] -> V_111 ) ;
F_21 ( & V_52 -> V_56 ,
F_24 ( V_44 ) ,
V_57 -> V_110 [ V_44 ] -> V_116 ) ;
F_21 ( & V_52 -> V_56 ,
F_25 ( V_44 ) ,
V_57 -> V_110 [ V_44 ] -> V_114 ) ;
}
if ( V_59 -> V_62 . V_117 [ V_44 ] )
F_7 ( & V_52 -> V_56 ,
V_59 -> V_62 . V_117 [ V_44 ] ,
V_57 -> V_117 [ V_44 ] ) ;
if ( V_59 -> V_62 . V_118 [ V_44 ] )
F_7 ( & V_52 -> V_56 ,
V_59 -> V_62 . V_118 [ V_44 ] ,
V_57 -> V_118 [ V_44 ] ) ;
}
}
int F_26 ( struct V_119 * V_120 )
{
unsigned int V_121 [ 2 ] = { } ;
struct V_122 * V_52 ;
F_27 (plane, c_state) {
struct V_1 * V_123 ;
struct V_2 * V_124 ;
unsigned int V_125 , V_126 = 0 ;
int V_44 ;
V_124 = F_28 ( V_120 -> V_57 , V_52 ) ;
if ( F_29 ( V_124 ) )
return F_30 ( V_124 ) ;
V_123 =
F_1 ( V_124 ) ;
V_125 = ( V_123 -> V_65 * V_123 -> V_67 ) -
( V_123 -> V_97 * V_123 -> V_96 ) ;
for ( V_44 = 0 ; V_44 < V_123 -> V_107 ; V_44 ++ )
V_126 += V_125 * V_123 -> V_127 [ V_44 ] ;
if ( V_121 [ 0 ] <= V_121 [ 1 ] )
V_123 -> V_84 = 0 ;
else
V_123 -> V_84 = 1 ;
V_121 [ V_123 -> V_84 ] += V_126 ;
}
return 0 ;
}
int
F_31 ( struct V_119 * V_120 )
{
int V_128 = 0 , V_129 = 0 , V_97 = 0 , V_96 = 0 ;
const struct V_130 * V_62 ;
struct V_1 * V_131 ;
struct V_2 * V_132 ;
struct V_51 * V_133 ;
struct V_122 * V_134 ;
V_133 = F_32 ( V_120 -> V_135 -> V_133 ) ;
V_62 = & V_133 -> V_56 . V_59 -> V_62 ;
if ( ! V_62 -> V_136 || ! V_62 -> V_137 )
return 0 ;
V_132 = F_28 ( V_120 -> V_57 ,
& V_133 -> V_4 ) ;
if ( F_29 ( V_132 ) )
return F_30 ( V_132 ) ;
V_131 = F_1 ( V_132 ) ;
F_27 (ovl, c_state) {
struct V_1 * V_138 ;
struct V_2 * V_139 ;
if ( V_134 == V_120 -> V_135 -> V_133 )
continue;
V_139 = F_28 ( V_120 -> V_57 , V_134 ) ;
if ( F_29 ( V_139 ) )
return F_30 ( V_139 ) ;
V_138 = F_1 ( V_139 ) ;
if ( ! V_139 -> V_85 ||
F_4 ( V_139 -> V_85 -> V_5 -> V_5 ) ||
V_138 -> V_95 != 255 )
continue;
if ( V_138 -> V_66 * V_138 -> V_64 < V_96 * V_97 )
continue;
V_128 = V_138 -> V_80 ;
V_129 = V_138 -> V_81 ;
V_96 = V_138 -> V_66 ;
V_97 = V_138 -> V_64 ;
}
V_131 -> V_128 = V_128 ;
V_131 -> V_129 = V_129 ;
V_131 -> V_97 = V_97 ;
V_131 -> V_96 = V_96 ;
return 0 ;
}
static void
F_33 ( struct V_51 * V_52 ,
struct V_1 * V_57 )
{
const struct V_130 * V_62 ;
V_62 = & V_52 -> V_56 . V_59 -> V_62 ;
if ( ! V_62 -> V_136 || ! V_62 -> V_137 )
return;
F_7 ( & V_52 -> V_56 , V_62 -> V_136 ,
F_34 ( V_57 -> V_128 ,
V_57 -> V_129 ) ) ;
F_7 ( & V_52 -> V_56 , V_62 -> V_137 ,
F_35 ( V_57 -> V_97 ,
V_57 -> V_96 ) ) ;
}
static int F_36 ( struct V_122 * V_140 ,
struct V_2 * V_3 )
{
struct V_51 * V_52 = F_32 ( V_140 ) ;
struct V_1 * V_57 =
F_1 ( V_3 ) ;
const struct V_58 * V_59 = V_52 -> V_56 . V_59 ;
struct V_104 * V_85 = V_57 -> V_4 . V_85 ;
const struct V_141 * V_6 ;
struct V_119 * V_142 ;
unsigned int V_143 ;
unsigned int V_144 ;
unsigned int V_145 ;
unsigned int V_146 ;
unsigned int V_45 ;
int V_147 = 0 ;
int V_148 = 0 ;
int V_149 = 1 ;
int V_150 = 1 ;
int V_44 ;
if ( ! V_57 -> V_4 . V_135 || ! V_85 )
return 0 ;
V_142 = F_37 ( V_3 -> V_57 , V_3 -> V_135 ) ;
V_6 = & V_142 -> V_151 ;
V_57 -> V_152 = V_3 -> V_152 ;
V_57 -> V_153 = V_3 -> V_153 ;
V_57 -> V_67 = V_3 -> V_67 ;
V_57 -> V_65 = V_3 -> V_65 ;
V_57 -> V_80 = V_3 -> V_80 ;
V_57 -> V_81 = V_3 -> V_81 ;
V_57 -> V_66 = V_3 -> V_66 ;
V_57 -> V_64 = V_3 -> V_64 ;
if ( ( V_57 -> V_152 | V_57 -> V_153 | V_57 -> V_65 | V_57 -> V_67 ) &
V_154 )
return - V_155 ;
V_57 -> V_152 >>= 16 ;
V_57 -> V_153 >>= 16 ;
V_57 -> V_65 >>= 16 ;
V_57 -> V_67 >>= 16 ;
V_57 -> V_107 = V_85 -> V_5 -> V_156 ;
if ( V_57 -> V_107 > V_157 )
return - V_155 ;
if ( F_17 ( V_57 -> V_4 . V_101 ) ) {
V_45 = V_57 -> V_64 ;
V_57 -> V_64 = V_57 -> V_66 ;
V_57 -> V_66 = V_45 ;
V_45 = V_57 -> V_65 ;
V_57 -> V_65 = V_57 -> V_67 ;
V_57 -> V_67 = V_45 ;
}
if ( V_57 -> V_80 + V_57 -> V_64 > V_6 -> V_158 )
V_143 = V_6 -> V_158 - V_57 -> V_80 ;
else
V_143 = V_57 -> V_64 ;
if ( V_57 -> V_80 < 0 ) {
V_143 += V_57 -> V_80 ;
V_147 = - V_57 -> V_80 ;
V_57 -> V_80 = 0 ;
}
if ( V_57 -> V_81 + V_57 -> V_66 > V_6 -> V_159 )
V_144 = V_6 -> V_159 - V_57 -> V_81 ;
else
V_144 = V_57 -> V_66 ;
if ( V_57 -> V_81 < 0 ) {
V_144 += V_57 -> V_81 ;
V_148 = - V_57 -> V_81 ;
V_57 -> V_81 = 0 ;
}
V_145 = F_38 ( V_143 * V_57 -> V_65 ,
V_57 -> V_64 ) ;
V_146 = F_38 ( V_144 * V_57 -> V_67 ,
V_57 -> V_66 ) ;
V_149 = F_39 ( V_85 -> V_5 -> V_5 ) ;
V_150 = F_40 ( V_85 -> V_5 -> V_5 ) ;
for ( V_44 = 0 ; V_44 < V_57 -> V_107 ; V_44 ++ ) {
unsigned int V_160 = 0 ;
int V_161 = V_44 ? V_149 : 1 ;
int V_162 = V_44 ? V_150 : 1 ;
V_57 -> V_127 [ V_44 ] = V_85 -> V_5 -> V_163 [ V_44 ] ;
if ( ! V_57 -> V_127 [ V_44 ] )
return - V_155 ;
switch ( V_57 -> V_4 . V_101 & V_164 ) {
case V_165 :
V_160 = ( ( V_148 + V_57 -> V_153 + V_145 - 1 ) /
V_162 ) * V_85 -> V_166 [ V_44 ] ;
V_160 += ( ( V_147 + V_57 -> V_152 ) / V_161 ) *
V_57 -> V_127 [ V_44 ] ;
V_57 -> V_117 [ V_44 ] = ( ( V_145 - 1 ) / V_162 ) *
V_85 -> V_166 [ V_44 ] ;
V_57 -> V_118 [ V_44 ] = - V_85 -> V_166 [ V_44 ] - V_57 -> V_127 [ V_44 ] ;
break;
case V_167 :
V_160 = ( ( V_148 + V_57 -> V_153 + V_146 - 1 ) /
V_162 ) * V_85 -> V_166 [ V_44 ] ;
V_160 += ( ( V_147 + V_57 -> V_152 + V_145 - 1 ) /
V_161 ) * V_57 -> V_127 [ V_44 ] ;
V_57 -> V_117 [ V_44 ] = ( ( ( ( V_145 - 1 ) / V_161 ) - 1 ) *
V_57 -> V_127 [ V_44 ] ) - V_85 -> V_166 [ V_44 ] ;
V_57 -> V_118 [ V_44 ] = - 2 * V_57 -> V_127 [ V_44 ] ;
break;
case V_168 :
V_160 = ( ( V_148 + V_57 -> V_153 ) / V_162 ) *
V_85 -> V_166 [ V_44 ] ;
V_160 += ( ( V_147 + V_57 -> V_152 + V_146 - 1 ) /
V_161 ) * V_57 -> V_127 [ V_44 ] ;
V_57 -> V_117 [ V_44 ] = - ( ( ( V_145 - 1 ) / V_162 ) *
V_85 -> V_166 [ V_44 ] ) -
( 2 * V_57 -> V_127 [ V_44 ] ) ;
V_57 -> V_118 [ V_44 ] = V_85 -> V_166 [ V_44 ] - V_57 -> V_127 [ V_44 ] ;
break;
case V_169 :
default:
V_160 = ( ( V_148 + V_57 -> V_153 ) / V_162 ) *
V_85 -> V_166 [ V_44 ] ;
V_160 += ( ( V_147 + V_57 -> V_152 ) / V_161 ) *
V_57 -> V_127 [ V_44 ] ;
V_57 -> V_117 [ V_44 ] = V_85 -> V_166 [ V_44 ] -
( ( V_145 / V_161 ) *
V_57 -> V_127 [ V_44 ] ) ;
V_57 -> V_118 [ V_44 ] = 0 ;
break;
}
V_57 -> V_113 [ V_44 ] = V_160 + V_85 -> V_113 [ V_44 ] ;
}
V_57 -> V_65 = V_145 ;
V_57 -> V_67 = V_146 ;
V_57 -> V_64 = V_143 ;
V_57 -> V_66 = V_144 ;
if ( ! V_59 -> V_62 . V_54 &&
( V_6 -> V_158 != V_57 -> V_64 ||
V_6 -> V_159 != V_57 -> V_66 ) )
return - V_155 ;
if ( V_59 -> V_170 && V_57 -> V_66 > V_59 -> V_170 )
return - V_155 ;
if ( V_59 -> V_171 && V_57 -> V_64 > V_59 -> V_171 )
return - V_155 ;
if ( ( V_57 -> V_66 != V_57 -> V_67 || V_57 -> V_64 != V_57 -> V_65 ) &&
( ! V_59 -> V_62 . V_78 ||
F_4 ( V_57 -> V_4 . V_85 -> V_5 -> V_5 ) ) )
return - V_155 ;
if ( V_57 -> V_80 < 0 || V_57 -> V_81 < 0 )
return - V_155 ;
if ( V_57 -> V_64 + V_57 -> V_80 > V_6 -> V_158 ||
V_57 -> V_66 + V_57 -> V_81 > V_6 -> V_159 )
return - V_155 ;
return 0 ;
}
static void F_41 ( struct V_122 * V_140 ,
struct V_2 * V_172 )
{
struct V_51 * V_52 = F_32 ( V_140 ) ;
struct V_1 * V_57 =
F_1 ( V_140 -> V_57 ) ;
T_1 V_105 ;
if ( ! V_140 -> V_57 -> V_135 || ! V_140 -> V_57 -> V_85 )
return;
F_11 ( V_52 , V_57 ) ;
F_14 ( V_52 , V_57 ) ;
F_16 ( V_52 , V_57 ) ;
F_18 ( V_52 , V_57 ) ;
F_33 ( V_52 , V_57 ) ;
F_21 ( & V_52 -> V_56 , V_173 ,
F_42 ( 0 ) |
F_42 ( 1 ) |
F_42 ( 2 ) ) ;
V_105 = F_19 ( & V_52 -> V_56 , V_106 ) ;
F_21 ( & V_52 -> V_56 , V_174 ,
V_175 |
( V_105 & V_115 ?
V_176 : V_115 ) ) ;
}
static void F_43 ( struct V_122 * V_140 ,
struct V_2 * V_177 )
{
struct V_51 * V_52 = F_32 ( V_140 ) ;
F_21 ( & V_52 -> V_56 , V_178 ,
0xffffffff ) ;
F_21 ( & V_52 -> V_56 , V_179 ,
V_180 |
V_176 |
V_175 ) ;
F_19 ( & V_52 -> V_56 , V_181 ) ;
}
static void F_44 ( struct V_122 * V_140 )
{
struct V_51 * V_52 = F_32 ( V_140 ) ;
if ( V_52 -> V_4 . V_85 )
F_45 ( V_52 -> V_4 . V_85 ) ;
F_46 ( V_140 ) ;
}
static int F_47 ( struct V_122 * V_140 ,
struct V_2 * V_3 ,
struct V_182 * V_183 ,
T_2 V_184 )
{
struct V_51 * V_52 = F_32 ( V_140 ) ;
struct V_185 * V_186 = V_52 -> V_187 ;
struct V_1 * V_57 =
F_1 ( V_3 ) ;
if ( V_183 == V_186 -> V_95 )
V_57 -> V_95 = V_184 ;
else
return - V_155 ;
return 0 ;
}
static int F_48 ( struct V_122 * V_140 ,
const struct V_2 * V_3 ,
struct V_182 * V_183 ,
T_2 * V_184 )
{
struct V_51 * V_52 = F_32 ( V_140 ) ;
struct V_185 * V_186 = V_52 -> V_187 ;
const struct V_1 * V_57 =
F_2 ( V_3 , const struct V_1 , V_4 ) ;
if ( V_183 == V_186 -> V_95 )
* V_184 = V_57 -> V_95 ;
else
return - V_155 ;
return 0 ;
}
static int F_49 ( struct V_51 * V_52 ,
struct V_185 * V_186 )
{
const struct V_58 * V_59 = V_52 -> V_56 . V_59 ;
if ( V_59 -> type == V_188 ||
V_59 -> type == V_189 )
F_50 ( & V_52 -> V_4 . V_4 ,
V_186 -> V_95 , 255 ) ;
if ( V_59 -> V_62 . V_117 && V_59 -> V_62 . V_118 ) {
int V_100 ;
V_100 = F_51 ( & V_52 -> V_4 ,
V_169 ,
V_169 |
V_165 |
V_167 |
V_168 ) ;
if ( V_100 )
return V_100 ;
}
if ( V_59 -> V_62 . V_190 ) {
F_7 ( & V_52 -> V_56 ,
V_59 -> V_62 . V_190 ,
0x4c900091 ) ;
F_7 ( & V_52 -> V_56 ,
V_59 -> V_62 . V_190 + 1 ,
0x7a5f5090 ) ;
F_7 ( & V_52 -> V_56 ,
V_59 -> V_62 . V_190 + 2 ,
0x40040890 ) ;
}
return 0 ;
}
void F_52 ( struct V_51 * V_52 )
{
const struct V_58 * V_59 = V_52 -> V_56 . V_59 ;
T_1 V_191 ;
V_191 = F_19 ( & V_52 -> V_56 , V_181 ) ;
if ( V_191 &
( F_42 ( 0 ) | F_42 ( 1 ) |
F_42 ( 2 ) ) )
F_53 ( V_52 -> V_4 . V_192 -> V_192 , L_1 ,
V_59 -> V_193 ) ;
}
static int F_54 ( struct V_122 * V_140 ,
struct V_1 * V_57 )
{
struct V_194 * V_195 = V_140 -> V_192 -> V_196 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < F_9 ( V_57 -> V_110 ) ; V_44 ++ ) {
struct V_197 * V_198 ;
T_3 V_199 ;
V_198 = F_55 ( V_195 -> V_200 , V_201 , & V_199 ) ;
if ( ! V_198 )
goto V_202;
V_198 -> V_111 = 0 ;
V_198 -> V_203 = V_199 ;
V_198 -> V_114 = V_199 ;
V_198 -> V_116 = V_204 ;
V_57 -> V_110 [ V_44 ] = V_198 ;
}
return 0 ;
V_202:
for ( V_44 -- ; V_44 >= 0 ; V_44 -- ) {
F_56 ( V_195 -> V_200 , V_57 -> V_110 [ V_44 ] ,
V_57 -> V_110 [ V_44 ] -> V_114 ) ;
}
return - V_205 ;
}
static void F_57 ( struct V_122 * V_140 )
{
struct V_1 * V_57 ;
if ( V_140 -> V_57 ) {
V_57 = F_1 ( V_140 -> V_57 ) ;
if ( V_57 -> V_4 . V_85 )
F_45 ( V_57 -> V_4 . V_85 ) ;
F_58 ( V_57 ) ;
V_140 -> V_57 = NULL ;
}
V_57 = F_59 ( sizeof( * V_57 ) , V_201 ) ;
if ( V_57 ) {
if ( F_54 ( V_140 , V_57 ) ) {
F_58 ( V_57 ) ;
F_60 ( V_140 -> V_192 -> V_192 ,
L_2 ) ;
return;
}
V_57 -> V_95 = 255 ;
V_140 -> V_57 = & V_57 -> V_4 ;
V_140 -> V_57 -> V_52 = V_140 ;
}
}
static struct V_2 *
F_61 ( struct V_122 * V_140 )
{
struct V_1 * V_57 =
F_1 ( V_140 -> V_57 ) ;
struct V_1 * V_206 ;
V_206 = F_62 ( V_57 , sizeof( * V_57 ) , V_201 ) ;
if ( ! V_206 )
return NULL ;
if ( F_54 ( V_140 , V_206 ) ) {
F_58 ( V_206 ) ;
return NULL ;
}
if ( V_206 -> V_4 . V_85 )
F_63 ( V_206 -> V_4 . V_85 ) ;
return & V_206 -> V_4 ;
}
static void F_64 ( struct V_122 * V_140 ,
struct V_2 * V_3 )
{
struct V_1 * V_57 =
F_1 ( V_3 ) ;
struct V_194 * V_195 = V_140 -> V_192 -> V_196 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < F_9 ( V_57 -> V_110 ) ; V_44 ++ ) {
F_56 ( V_195 -> V_200 , V_57 -> V_110 [ V_44 ] ,
V_57 -> V_110 [ V_44 ] -> V_114 ) ;
}
if ( V_3 -> V_85 )
F_45 ( V_3 -> V_85 ) ;
F_58 ( V_57 ) ;
}
static int F_65 ( struct V_207 * V_192 ,
const struct V_58 * V_59 ,
struct V_185 * V_186 )
{
struct V_194 * V_195 = V_192 -> V_196 ;
struct V_51 * V_52 ;
enum V_208 type ;
int V_100 ;
V_52 = F_66 ( V_192 -> V_192 , sizeof( * V_52 ) , V_201 ) ;
if ( ! V_52 )
return - V_205 ;
F_67 ( & V_52 -> V_56 , V_59 , V_195 -> V_209 -> V_210 ) ;
V_52 -> V_187 = V_186 ;
if ( V_59 -> type == V_211 )
type = V_89 ;
else if ( V_59 -> type == V_189 )
type = V_212 ;
else
type = V_213 ;
V_100 = F_68 ( V_192 , & V_52 -> V_4 , 0 ,
& V_214 ,
V_59 -> V_215 -> V_215 ,
V_59 -> V_215 -> V_216 , type , NULL ) ;
if ( V_100 )
return V_100 ;
F_69 ( & V_52 -> V_4 ,
& V_217 ) ;
V_100 = F_49 ( V_52 , V_186 ) ;
if ( V_100 )
return V_100 ;
V_195 -> V_218 [ V_59 -> V_219 ] = & V_52 -> V_56 ;
return 0 ;
}
static struct V_185 *
F_70 ( struct V_207 * V_192 )
{
struct V_185 * V_186 ;
V_186 = F_66 ( V_192 -> V_192 , sizeof( * V_186 ) , V_201 ) ;
if ( ! V_186 )
return F_71 ( - V_205 ) ;
V_186 -> V_95 = F_72 ( V_192 , 0 , L_3 , 0 , 255 ) ;
if ( ! V_186 -> V_95 )
return F_71 ( - V_205 ) ;
return V_186 ;
}
int F_73 ( struct V_207 * V_192 )
{
struct V_194 * V_195 = V_192 -> V_196 ;
struct V_185 * V_186 ;
const struct V_58 * V_220 = V_195 -> V_59 -> V_218 ;
int V_221 = V_195 -> V_59 -> V_221 ;
int V_44 , V_100 ;
V_186 = F_70 ( V_192 ) ;
if ( F_29 ( V_186 ) )
return F_30 ( V_186 ) ;
V_195 -> V_200 = F_74 ( L_4 , V_192 -> V_192 ,
sizeof( struct V_197 ) ,
sizeof( V_222 ) , 0 ) ;
if ( ! V_195 -> V_200 )
return - V_205 ;
for ( V_44 = 0 ; V_44 < V_221 ; V_44 ++ ) {
if ( V_220 [ V_44 ] . type != V_211 &&
V_220 [ V_44 ] . type != V_188 &&
V_220 [ V_44 ] . type != V_189 )
continue;
V_100 = F_65 ( V_192 , & V_220 [ V_44 ] , V_186 ) ;
if ( V_100 )
return V_100 ;
}
return 0 ;
}
