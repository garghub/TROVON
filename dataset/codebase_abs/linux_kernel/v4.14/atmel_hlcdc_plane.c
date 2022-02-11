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
case V_43 :
* V_6 = V_44 ;
break;
default:
return - V_45 ;
}
return 0 ;
}
static bool F_4 ( T_1 V_5 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < sizeof( V_5 ) ; V_46 ++ ) {
char V_47 = ( V_5 >> ( 8 * V_46 ) ) & 0xff ;
if ( V_47 == 'A' )
return true ;
}
return false ;
}
static T_1 F_5 ( T_1 V_48 ,
T_1 V_49 ,
T_1 V_50 )
{
T_1 V_51 , V_52 ;
V_51 = ( 256 * ( ( 8 * ( V_48 - 1 ) ) - V_50 ) ) / ( V_49 - 1 ) ;
V_52 = ( ( V_51 * ( V_49 - 1 ) ) + ( 256 * V_50 ) ) / 2048 ;
if ( V_52 > V_48 - 1 )
V_51 -- ;
return V_51 ;
}
static void
F_6 ( struct V_53 * V_54 ,
const T_1 * V_55 , int V_56 ,
unsigned int V_57 )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_56 ; V_46 ++ )
F_7 ( & V_54 -> V_58 , V_57 + V_46 ,
V_55 [ V_46 ] ) ;
}
void F_8 ( struct V_53 * V_54 ,
struct V_1 * V_59 )
{
const struct V_60 * V_61 = V_54 -> V_58 . V_61 ;
T_1 V_62 , V_63 ;
if ( ! V_61 -> V_64 . V_65 )
return;
if ( V_59 -> V_66 == V_59 -> V_67 && V_59 -> V_68 == V_59 -> V_69 ) {
F_7 ( & V_54 -> V_58 ,
V_61 -> V_64 . V_65 , 0 ) ;
return;
}
if ( V_61 -> V_64 . V_70 . V_71 ) {
V_62 = F_5 ( V_59 -> V_67 ,
V_59 -> V_66 ,
V_72 ) ;
V_63 = F_5 ( V_59 -> V_69 ,
V_59 -> V_68 ,
V_73 ) ;
F_6 ( V_54 ,
V_59 -> V_66 < V_59 -> V_67 ?
V_74 :
V_75 ,
F_9 ( V_75 ) ,
V_61 -> V_64 . V_70 . V_71 ) ;
F_6 ( V_54 ,
V_59 -> V_68 < V_59 -> V_69 ?
V_76 :
V_77 ,
F_9 ( V_77 ) ,
V_61 -> V_64 . V_70 . V_78 ) ;
} else {
V_62 = ( 1024 * V_59 -> V_67 ) / V_59 -> V_66 ;
V_63 = ( 1024 * V_59 -> V_69 ) / V_59 -> V_68 ;
}
F_7 ( & V_54 -> V_58 , V_61 -> V_64 . V_65 ,
V_79 |
F_10 ( V_62 ,
V_63 ) ) ;
}
static void
F_11 ( struct V_53 * V_54 ,
struct V_1 * V_59 )
{
const struct V_60 * V_61 = V_54 -> V_58 . V_61 ;
if ( V_61 -> V_64 . V_56 )
F_7 ( & V_54 -> V_58 , V_61 -> V_64 . V_56 ,
F_12 ( V_59 -> V_66 ,
V_59 -> V_68 ) ) ;
if ( V_61 -> V_64 . V_80 )
F_7 ( & V_54 -> V_58 ,
V_61 -> V_64 . V_80 ,
F_12 ( V_59 -> V_67 ,
V_59 -> V_69 ) ) ;
if ( V_61 -> V_64 . V_81 )
F_7 ( & V_54 -> V_58 , V_61 -> V_64 . V_81 ,
F_13 ( V_59 -> V_82 ,
V_59 -> V_83 ) ) ;
F_8 ( V_54 , V_59 ) ;
}
static void
F_14 ( struct V_53 * V_54 ,
struct V_1 * V_59 )
{
unsigned int V_84 = V_85 | V_59 -> V_86 ;
const struct V_60 * V_61 = V_54 -> V_58 . V_61 ;
T_1 V_5 = V_59 -> V_4 . V_87 -> V_5 -> V_5 ;
if ( V_5 == V_17 )
V_84 |= V_88 ;
F_7 ( & V_54 -> V_58 , V_89 ,
V_84 ) ;
V_84 = V_90 ;
if ( V_54 -> V_4 . type != V_91 ) {
V_84 |= V_92 | V_93 |
V_94 ;
if ( F_4 ( V_5 ) )
V_84 |= V_95 ;
else
V_84 |= V_96 |
F_15 ( V_59 -> V_97 ) ;
}
if ( V_59 -> V_98 && V_59 -> V_99 )
V_84 |= V_100 ;
F_7 ( & V_54 -> V_58 , V_61 -> V_64 . V_101 ,
V_84 ) ;
}
static void F_16 ( struct V_53 * V_54 ,
struct V_1 * V_59 )
{
T_1 V_84 ;
int V_102 ;
V_102 = F_3 ( V_59 -> V_4 . V_87 -> V_5 -> V_5 ,
& V_84 ) ;
if ( V_102 )
return;
if ( ( V_59 -> V_4 . V_87 -> V_5 -> V_5 == V_43 ||
V_59 -> V_4 . V_87 -> V_5 -> V_5 == V_39 ) &&
F_17 ( V_59 -> V_4 . V_103 ) )
V_84 |= V_104 ;
F_7 ( & V_54 -> V_58 ,
V_105 , V_84 ) ;
}
static void F_18 ( struct V_53 * V_54 )
{
struct V_106 * V_107 = V_54 -> V_4 . V_107 ;
struct V_108 * V_109 ;
int V_110 ;
if ( ! V_107 || ! V_107 -> V_59 )
return;
if ( ! V_107 -> V_59 -> V_111 || ! V_107 -> V_59 -> V_112 )
return;
V_109 = (struct V_108 * ) V_107 -> V_59 -> V_112 -> V_113 ;
for ( V_110 = 0 ; V_110 < V_114 ; V_110 ++ , V_109 ++ ) {
T_1 V_115 = ( ( V_109 -> V_116 << 8 ) & 0xff0000 ) |
( V_109 -> V_117 & 0xff00 ) |
( V_109 -> V_118 >> 8 ) ;
F_19 ( & V_54 -> V_58 , V_110 , V_115 ) ;
}
}
static void F_20 ( struct V_53 * V_54 ,
struct V_1 * V_59 )
{
const struct V_60 * V_61 = V_54 -> V_58 . V_61 ;
struct V_119 * V_87 = V_59 -> V_4 . V_87 ;
T_1 V_120 ;
int V_46 ;
V_120 = F_21 ( & V_54 -> V_58 , V_121 ) ;
for ( V_46 = 0 ; V_46 < V_59 -> V_122 ; V_46 ++ ) {
struct V_123 * V_124 = F_22 ( V_87 , V_46 ) ;
V_59 -> V_125 [ V_46 ] -> V_126 = V_124 -> V_127 + V_59 -> V_128 [ V_46 ] ;
F_23 ( & V_54 -> V_58 ,
F_24 ( V_46 ) ,
V_59 -> V_125 [ V_46 ] -> V_129 ) ;
if ( ! ( V_120 & V_130 ) ) {
F_23 ( & V_54 -> V_58 ,
F_25 ( V_46 ) ,
V_59 -> V_125 [ V_46 ] -> V_126 ) ;
F_23 ( & V_54 -> V_58 ,
F_26 ( V_46 ) ,
V_59 -> V_125 [ V_46 ] -> V_131 ) ;
F_23 ( & V_54 -> V_58 ,
F_27 ( V_46 ) ,
V_59 -> V_125 [ V_46 ] -> V_129 ) ;
}
if ( V_61 -> V_64 . V_132 [ V_46 ] )
F_7 ( & V_54 -> V_58 ,
V_61 -> V_64 . V_132 [ V_46 ] ,
V_59 -> V_132 [ V_46 ] ) ;
if ( V_61 -> V_64 . V_133 [ V_46 ] )
F_7 ( & V_54 -> V_58 ,
V_61 -> V_64 . V_133 [ V_46 ] ,
V_59 -> V_133 [ V_46 ] ) ;
}
}
int F_28 ( struct V_134 * V_135 )
{
unsigned int V_136 [ 2 ] = { } ;
struct V_137 * V_54 ;
F_29 (plane, c_state) {
struct V_1 * V_138 ;
struct V_2 * V_139 ;
unsigned int V_140 , V_141 = 0 ;
int V_46 ;
V_139 = F_30 ( V_135 -> V_59 , V_54 ) ;
if ( F_31 ( V_139 ) )
return F_32 ( V_139 ) ;
V_138 =
F_1 ( V_139 ) ;
V_140 = ( V_138 -> V_67 * V_138 -> V_69 ) -
( V_138 -> V_99 * V_138 -> V_98 ) ;
for ( V_46 = 0 ; V_46 < V_138 -> V_122 ; V_46 ++ )
V_141 += V_140 * V_138 -> V_142 [ V_46 ] ;
if ( V_136 [ 0 ] <= V_136 [ 1 ] )
V_138 -> V_86 = 0 ;
else
V_138 -> V_86 = 1 ;
V_136 [ V_138 -> V_86 ] += V_141 ;
}
return 0 ;
}
int
F_33 ( struct V_134 * V_135 )
{
int V_143 = 0 , V_144 = 0 , V_99 = 0 , V_98 = 0 ;
const struct V_145 * V_64 ;
struct V_1 * V_146 ;
struct V_2 * V_147 ;
struct V_53 * V_148 ;
struct V_137 * V_149 ;
V_148 = F_34 ( V_135 -> V_107 -> V_148 ) ;
V_64 = & V_148 -> V_58 . V_61 -> V_64 ;
if ( ! V_64 -> V_150 || ! V_64 -> V_151 )
return 0 ;
V_147 = F_30 ( V_135 -> V_59 ,
& V_148 -> V_4 ) ;
if ( F_31 ( V_147 ) )
return F_32 ( V_147 ) ;
V_146 = F_1 ( V_147 ) ;
F_29 (ovl, c_state) {
struct V_1 * V_152 ;
struct V_2 * V_153 ;
if ( V_149 == V_135 -> V_107 -> V_148 )
continue;
V_153 = F_30 ( V_135 -> V_59 , V_149 ) ;
if ( F_31 ( V_153 ) )
return F_32 ( V_153 ) ;
V_152 = F_1 ( V_153 ) ;
if ( ! V_153 -> V_87 ||
F_4 ( V_153 -> V_87 -> V_5 -> V_5 ) ||
V_152 -> V_97 != 255 )
continue;
if ( V_152 -> V_68 * V_152 -> V_66 < V_98 * V_99 )
continue;
V_143 = V_152 -> V_82 ;
V_144 = V_152 -> V_83 ;
V_98 = V_152 -> V_68 ;
V_99 = V_152 -> V_66 ;
}
V_146 -> V_143 = V_143 ;
V_146 -> V_144 = V_144 ;
V_146 -> V_99 = V_99 ;
V_146 -> V_98 = V_98 ;
return 0 ;
}
static void
F_35 ( struct V_53 * V_54 ,
struct V_1 * V_59 )
{
const struct V_145 * V_64 ;
V_64 = & V_54 -> V_58 . V_61 -> V_64 ;
if ( ! V_64 -> V_150 || ! V_64 -> V_151 )
return;
F_7 ( & V_54 -> V_58 , V_64 -> V_150 ,
F_36 ( V_59 -> V_143 ,
V_59 -> V_144 ) ) ;
F_7 ( & V_54 -> V_58 , V_64 -> V_151 ,
F_37 ( V_59 -> V_99 ,
V_59 -> V_98 ) ) ;
}
static int F_38 ( struct V_137 * V_154 ,
struct V_2 * V_3 )
{
struct V_53 * V_54 = F_34 ( V_154 ) ;
struct V_1 * V_59 =
F_1 ( V_3 ) ;
const struct V_60 * V_61 = V_54 -> V_58 . V_61 ;
struct V_119 * V_87 = V_59 -> V_4 . V_87 ;
const struct V_155 * V_6 ;
struct V_134 * V_156 ;
unsigned int V_157 ;
unsigned int V_158 ;
unsigned int V_159 ;
unsigned int V_160 ;
unsigned int V_47 ;
int V_161 = 0 ;
int V_162 = 0 ;
int V_163 = 1 ;
int V_164 = 1 ;
int V_46 ;
if ( ! V_59 -> V_4 . V_107 || ! V_87 )
return 0 ;
V_156 = F_39 ( V_3 -> V_59 , V_3 -> V_107 ) ;
V_6 = & V_156 -> V_165 ;
V_59 -> V_166 = V_3 -> V_166 ;
V_59 -> V_167 = V_3 -> V_167 ;
V_59 -> V_69 = V_3 -> V_69 ;
V_59 -> V_67 = V_3 -> V_67 ;
V_59 -> V_82 = V_3 -> V_82 ;
V_59 -> V_83 = V_3 -> V_83 ;
V_59 -> V_68 = V_3 -> V_68 ;
V_59 -> V_66 = V_3 -> V_66 ;
if ( ( V_59 -> V_166 | V_59 -> V_167 | V_59 -> V_67 | V_59 -> V_69 ) &
V_168 )
return - V_169 ;
V_59 -> V_166 >>= 16 ;
V_59 -> V_167 >>= 16 ;
V_59 -> V_67 >>= 16 ;
V_59 -> V_69 >>= 16 ;
V_59 -> V_122 = V_87 -> V_5 -> V_170 ;
if ( V_59 -> V_122 > V_171 )
return - V_169 ;
if ( F_17 ( V_59 -> V_4 . V_103 ) ) {
V_47 = V_59 -> V_66 ;
V_59 -> V_66 = V_59 -> V_68 ;
V_59 -> V_68 = V_47 ;
V_47 = V_59 -> V_67 ;
V_59 -> V_67 = V_59 -> V_69 ;
V_59 -> V_69 = V_47 ;
}
if ( V_59 -> V_82 + V_59 -> V_66 > V_6 -> V_172 )
V_157 = V_6 -> V_172 - V_59 -> V_82 ;
else
V_157 = V_59 -> V_66 ;
if ( V_59 -> V_82 < 0 ) {
V_157 += V_59 -> V_82 ;
V_161 = - V_59 -> V_82 ;
V_59 -> V_82 = 0 ;
}
if ( V_59 -> V_83 + V_59 -> V_68 > V_6 -> V_173 )
V_158 = V_6 -> V_173 - V_59 -> V_83 ;
else
V_158 = V_59 -> V_68 ;
if ( V_59 -> V_83 < 0 ) {
V_158 += V_59 -> V_83 ;
V_162 = - V_59 -> V_83 ;
V_59 -> V_83 = 0 ;
}
V_159 = F_40 ( V_157 * V_59 -> V_67 ,
V_59 -> V_66 ) ;
V_160 = F_40 ( V_158 * V_59 -> V_69 ,
V_59 -> V_68 ) ;
V_163 = F_41 ( V_87 -> V_5 -> V_5 ) ;
V_164 = F_42 ( V_87 -> V_5 -> V_5 ) ;
for ( V_46 = 0 ; V_46 < V_59 -> V_122 ; V_46 ++ ) {
unsigned int V_174 = 0 ;
int V_175 = V_46 ? V_163 : 1 ;
int V_176 = V_46 ? V_164 : 1 ;
V_59 -> V_142 [ V_46 ] = V_87 -> V_5 -> V_177 [ V_46 ] ;
if ( ! V_59 -> V_142 [ V_46 ] )
return - V_169 ;
switch ( V_59 -> V_4 . V_103 & V_178 ) {
case V_179 :
V_174 = ( ( V_162 + V_59 -> V_167 + V_159 - 1 ) /
V_176 ) * V_87 -> V_180 [ V_46 ] ;
V_174 += ( ( V_161 + V_59 -> V_166 ) / V_175 ) *
V_59 -> V_142 [ V_46 ] ;
V_59 -> V_132 [ V_46 ] = ( ( V_159 - 1 ) / V_176 ) *
V_87 -> V_180 [ V_46 ] ;
V_59 -> V_133 [ V_46 ] = - V_87 -> V_180 [ V_46 ] - V_59 -> V_142 [ V_46 ] ;
break;
case V_181 :
V_174 = ( ( V_162 + V_59 -> V_167 + V_160 - 1 ) /
V_176 ) * V_87 -> V_180 [ V_46 ] ;
V_174 += ( ( V_161 + V_59 -> V_166 + V_159 - 1 ) /
V_175 ) * V_59 -> V_142 [ V_46 ] ;
V_59 -> V_132 [ V_46 ] = ( ( ( ( V_159 - 1 ) / V_175 ) - 1 ) *
V_59 -> V_142 [ V_46 ] ) - V_87 -> V_180 [ V_46 ] ;
V_59 -> V_133 [ V_46 ] = - 2 * V_59 -> V_142 [ V_46 ] ;
break;
case V_182 :
V_174 = ( ( V_162 + V_59 -> V_167 ) / V_176 ) *
V_87 -> V_180 [ V_46 ] ;
V_174 += ( ( V_161 + V_59 -> V_166 + V_160 - 1 ) /
V_175 ) * V_59 -> V_142 [ V_46 ] ;
V_59 -> V_132 [ V_46 ] = - ( ( ( V_159 - 1 ) / V_176 ) *
V_87 -> V_180 [ V_46 ] ) -
( 2 * V_59 -> V_142 [ V_46 ] ) ;
V_59 -> V_133 [ V_46 ] = V_87 -> V_180 [ V_46 ] - V_59 -> V_142 [ V_46 ] ;
break;
case V_183 :
default:
V_174 = ( ( V_162 + V_59 -> V_167 ) / V_176 ) *
V_87 -> V_180 [ V_46 ] ;
V_174 += ( ( V_161 + V_59 -> V_166 ) / V_175 ) *
V_59 -> V_142 [ V_46 ] ;
V_59 -> V_132 [ V_46 ] = V_87 -> V_180 [ V_46 ] -
( ( V_159 / V_175 ) *
V_59 -> V_142 [ V_46 ] ) ;
V_59 -> V_133 [ V_46 ] = 0 ;
break;
}
V_59 -> V_128 [ V_46 ] = V_174 + V_87 -> V_128 [ V_46 ] ;
}
V_59 -> V_67 = V_159 ;
V_59 -> V_69 = V_160 ;
V_59 -> V_66 = V_157 ;
V_59 -> V_68 = V_158 ;
if ( ! V_61 -> V_64 . V_56 &&
( V_6 -> V_172 != V_59 -> V_66 ||
V_6 -> V_173 != V_59 -> V_68 ) )
return - V_169 ;
if ( V_61 -> V_184 && V_59 -> V_68 > V_61 -> V_184 )
return - V_169 ;
if ( V_61 -> V_185 && V_59 -> V_66 > V_61 -> V_185 )
return - V_169 ;
if ( ( V_59 -> V_68 != V_59 -> V_69 || V_59 -> V_66 != V_59 -> V_67 ) &&
( ! V_61 -> V_64 . V_80 ||
F_4 ( V_59 -> V_4 . V_87 -> V_5 -> V_5 ) ) )
return - V_169 ;
if ( V_59 -> V_82 < 0 || V_59 -> V_83 < 0 )
return - V_169 ;
if ( V_59 -> V_66 + V_59 -> V_82 > V_6 -> V_172 ||
V_59 -> V_68 + V_59 -> V_83 > V_6 -> V_173 )
return - V_169 ;
return 0 ;
}
static void F_43 ( struct V_137 * V_154 ,
struct V_2 * V_186 )
{
struct V_53 * V_54 = F_34 ( V_154 ) ;
struct V_1 * V_59 =
F_1 ( V_154 -> V_59 ) ;
T_1 V_120 ;
if ( ! V_154 -> V_59 -> V_107 || ! V_154 -> V_59 -> V_87 )
return;
F_11 ( V_54 , V_59 ) ;
F_14 ( V_54 , V_59 ) ;
F_16 ( V_54 , V_59 ) ;
F_18 ( V_54 ) ;
F_20 ( V_54 , V_59 ) ;
F_35 ( V_54 , V_59 ) ;
F_23 ( & V_54 -> V_58 , V_187 ,
F_44 ( 0 ) |
F_44 ( 1 ) |
F_44 ( 2 ) ) ;
V_120 = F_21 ( & V_54 -> V_58 , V_121 ) ;
F_23 ( & V_54 -> V_58 , V_188 ,
V_189 |
( V_120 & V_130 ?
V_190 : V_130 ) ) ;
}
static void F_45 ( struct V_137 * V_154 ,
struct V_2 * V_191 )
{
struct V_53 * V_54 = F_34 ( V_154 ) ;
F_23 ( & V_54 -> V_58 , V_192 ,
0xffffffff ) ;
F_23 ( & V_54 -> V_58 , V_193 ,
V_194 |
V_190 |
V_189 ) ;
F_21 ( & V_54 -> V_58 , V_195 ) ;
}
static void F_46 ( struct V_137 * V_154 )
{
struct V_53 * V_54 = F_34 ( V_154 ) ;
if ( V_54 -> V_4 . V_87 )
F_47 ( V_54 -> V_4 . V_87 ) ;
F_48 ( V_154 ) ;
}
static int F_49 ( struct V_137 * V_154 ,
struct V_2 * V_3 ,
struct V_196 * V_197 ,
T_2 V_115 )
{
struct V_53 * V_54 = F_34 ( V_154 ) ;
struct V_198 * V_199 = V_54 -> V_200 ;
struct V_1 * V_59 =
F_1 ( V_3 ) ;
if ( V_197 == V_199 -> V_97 )
V_59 -> V_97 = V_115 ;
else
return - V_169 ;
return 0 ;
}
static int F_50 ( struct V_137 * V_154 ,
const struct V_2 * V_3 ,
struct V_196 * V_197 ,
T_2 * V_115 )
{
struct V_53 * V_54 = F_34 ( V_154 ) ;
struct V_198 * V_199 = V_54 -> V_200 ;
const struct V_1 * V_59 =
F_2 ( V_3 , const struct V_1 , V_4 ) ;
if ( V_197 == V_199 -> V_97 )
* V_115 = V_59 -> V_97 ;
else
return - V_169 ;
return 0 ;
}
static int F_51 ( struct V_53 * V_54 ,
struct V_198 * V_199 )
{
const struct V_60 * V_61 = V_54 -> V_58 . V_61 ;
if ( V_61 -> type == V_201 ||
V_61 -> type == V_202 )
F_52 ( & V_54 -> V_4 . V_4 ,
V_199 -> V_97 , 255 ) ;
if ( V_61 -> V_64 . V_132 && V_61 -> V_64 . V_133 ) {
int V_102 ;
V_102 = F_53 ( & V_54 -> V_4 ,
V_183 ,
V_183 |
V_179 |
V_181 |
V_182 ) ;
if ( V_102 )
return V_102 ;
}
if ( V_61 -> V_64 . V_203 ) {
F_7 ( & V_54 -> V_58 ,
V_61 -> V_64 . V_203 ,
0x4c900091 ) ;
F_7 ( & V_54 -> V_58 ,
V_61 -> V_64 . V_203 + 1 ,
0x7a5f5090 ) ;
F_7 ( & V_54 -> V_58 ,
V_61 -> V_64 . V_203 + 2 ,
0x40040890 ) ;
}
return 0 ;
}
void F_54 ( struct V_53 * V_54 )
{
const struct V_60 * V_61 = V_54 -> V_58 . V_61 ;
T_1 V_204 ;
V_204 = F_21 ( & V_54 -> V_58 , V_195 ) ;
if ( V_204 &
( F_44 ( 0 ) | F_44 ( 1 ) |
F_44 ( 2 ) ) )
F_55 ( V_54 -> V_4 . V_205 -> V_205 , L_1 ,
V_61 -> V_206 ) ;
}
static int F_56 ( struct V_137 * V_154 ,
struct V_1 * V_59 )
{
struct V_207 * V_208 = V_154 -> V_205 -> V_209 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_9 ( V_59 -> V_125 ) ; V_46 ++ ) {
struct V_210 * V_211 ;
T_3 V_212 ;
V_211 = F_57 ( V_208 -> V_213 , V_214 , & V_212 ) ;
if ( ! V_211 )
goto V_215;
V_211 -> V_126 = 0 ;
V_211 -> V_216 = V_212 ;
V_211 -> V_129 = V_212 ;
V_211 -> V_131 = V_217 ;
V_59 -> V_125 [ V_46 ] = V_211 ;
}
return 0 ;
V_215:
for ( V_46 -- ; V_46 >= 0 ; V_46 -- ) {
F_58 ( V_208 -> V_213 , V_59 -> V_125 [ V_46 ] ,
V_59 -> V_125 [ V_46 ] -> V_129 ) ;
}
return - V_218 ;
}
static void F_59 ( struct V_137 * V_154 )
{
struct V_1 * V_59 ;
if ( V_154 -> V_59 ) {
V_59 = F_1 ( V_154 -> V_59 ) ;
if ( V_59 -> V_4 . V_87 )
F_47 ( V_59 -> V_4 . V_87 ) ;
F_60 ( V_59 ) ;
V_154 -> V_59 = NULL ;
}
V_59 = F_61 ( sizeof( * V_59 ) , V_214 ) ;
if ( V_59 ) {
if ( F_56 ( V_154 , V_59 ) ) {
F_60 ( V_59 ) ;
F_62 ( V_154 -> V_205 -> V_205 ,
L_2 ) ;
return;
}
V_59 -> V_97 = 255 ;
V_154 -> V_59 = & V_59 -> V_4 ;
V_154 -> V_59 -> V_54 = V_154 ;
}
}
static struct V_2 *
F_63 ( struct V_137 * V_154 )
{
struct V_1 * V_59 =
F_1 ( V_154 -> V_59 ) ;
struct V_1 * V_219 ;
V_219 = F_64 ( V_59 , sizeof( * V_59 ) , V_214 ) ;
if ( ! V_219 )
return NULL ;
if ( F_56 ( V_154 , V_219 ) ) {
F_60 ( V_219 ) ;
return NULL ;
}
if ( V_219 -> V_4 . V_87 )
F_65 ( V_219 -> V_4 . V_87 ) ;
return & V_219 -> V_4 ;
}
static void F_66 ( struct V_137 * V_154 ,
struct V_2 * V_3 )
{
struct V_1 * V_59 =
F_1 ( V_3 ) ;
struct V_207 * V_208 = V_154 -> V_205 -> V_209 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_9 ( V_59 -> V_125 ) ; V_46 ++ ) {
F_58 ( V_208 -> V_213 , V_59 -> V_125 [ V_46 ] ,
V_59 -> V_125 [ V_46 ] -> V_129 ) ;
}
if ( V_3 -> V_87 )
F_47 ( V_3 -> V_87 ) ;
F_60 ( V_59 ) ;
}
static int F_67 ( struct V_220 * V_205 ,
const struct V_60 * V_61 ,
struct V_198 * V_199 )
{
struct V_207 * V_208 = V_205 -> V_209 ;
struct V_53 * V_54 ;
enum V_221 type ;
int V_102 ;
V_54 = F_68 ( V_205 -> V_205 , sizeof( * V_54 ) , V_214 ) ;
if ( ! V_54 )
return - V_218 ;
F_69 ( & V_54 -> V_58 , V_61 , V_208 -> V_222 -> V_223 ) ;
V_54 -> V_200 = V_199 ;
if ( V_61 -> type == V_224 )
type = V_91 ;
else if ( V_61 -> type == V_202 )
type = V_225 ;
else
type = V_226 ;
V_102 = F_70 ( V_205 , & V_54 -> V_4 , 0 ,
& V_227 ,
V_61 -> V_228 -> V_228 ,
V_61 -> V_228 -> V_229 ,
NULL , type , NULL ) ;
if ( V_102 )
return V_102 ;
F_71 ( & V_54 -> V_4 ,
& V_230 ) ;
V_102 = F_51 ( V_54 , V_199 ) ;
if ( V_102 )
return V_102 ;
V_208 -> V_231 [ V_61 -> V_232 ] = & V_54 -> V_58 ;
return 0 ;
}
static struct V_198 *
F_72 ( struct V_220 * V_205 )
{
struct V_198 * V_199 ;
V_199 = F_68 ( V_205 -> V_205 , sizeof( * V_199 ) , V_214 ) ;
if ( ! V_199 )
return F_73 ( - V_218 ) ;
V_199 -> V_97 = F_74 ( V_205 , 0 , L_3 , 0 , 255 ) ;
if ( ! V_199 -> V_97 )
return F_73 ( - V_218 ) ;
return V_199 ;
}
int F_75 ( struct V_220 * V_205 )
{
struct V_207 * V_208 = V_205 -> V_209 ;
struct V_198 * V_199 ;
const struct V_60 * V_233 = V_208 -> V_61 -> V_231 ;
int V_234 = V_208 -> V_61 -> V_234 ;
int V_46 , V_102 ;
V_199 = F_72 ( V_205 ) ;
if ( F_31 ( V_199 ) )
return F_32 ( V_199 ) ;
V_208 -> V_213 = F_76 ( L_4 , V_205 -> V_205 ,
sizeof( struct V_210 ) ,
sizeof( V_235 ) , 0 ) ;
if ( ! V_208 -> V_213 )
return - V_218 ;
for ( V_46 = 0 ; V_46 < V_234 ; V_46 ++ ) {
if ( V_233 [ V_46 ] . type != V_224 &&
V_233 [ V_46 ] . type != V_201 &&
V_233 [ V_46 ] . type != V_202 )
continue;
V_102 = F_67 ( V_205 , & V_233 [ V_46 ] , V_199 ) ;
if ( V_102 )
return V_102 ;
}
return 0 ;
}
