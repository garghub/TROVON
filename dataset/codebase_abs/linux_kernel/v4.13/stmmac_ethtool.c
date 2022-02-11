static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 -> V_8 || V_6 -> V_7 -> V_9 )
F_3 ( V_4 -> V_10 , V_11 , sizeof( V_4 -> V_10 ) ) ;
else
F_3 ( V_4 -> V_10 , V_12 ,
sizeof( V_4 -> V_10 ) ) ;
F_3 ( V_4 -> V_13 , V_14 , sizeof( V_4 -> V_13 ) ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_2 -> V_19 ;
if ( V_6 -> V_20 -> V_21 & V_22 ||
V_6 -> V_20 -> V_21 & V_23 ) {
struct V_24 V_25 ;
T_1 V_26 , V_27 , V_28 ;
if ( ! V_6 -> V_29 . V_30 ) {
V_16 -> V_31 . V_32 = V_33 ;
V_16 -> V_31 . V_34 = V_35 ;
return 0 ;
}
V_16 -> V_31 . V_34 = V_6 -> V_29 . V_36 ;
V_16 -> V_31 . V_32 = V_6 -> V_29 . V_37 ;
if ( ! V_6 -> V_20 -> V_38 -> V_39 )
return - V_40 ;
V_6 -> V_20 -> V_38 -> V_39 ( V_6 -> V_41 , & V_25 ) ;
F_5 (
& V_26 , V_16 -> V_42 . V_26 ) ;
F_5 (
& V_27 , V_16 -> V_42 . V_27 ) ;
F_5 (
& V_28 , V_16 -> V_42 . V_28 ) ;
if ( V_25 . V_43 & V_44 )
V_27 |= V_45 ;
if ( V_25 . V_43 & V_46 )
V_27 |= V_47 ;
if ( V_25 . V_48 & V_44 )
V_28 |= V_45 ;
if ( V_25 . V_48 & V_46 )
V_28 |= V_47 ;
V_16 -> V_31 . V_49 = V_50 ;
V_26 |= V_51 ;
V_27 |= V_50 ;
V_28 |= V_50 ;
if ( V_25 . V_34 ) {
V_26 |= ( V_52 |
V_53 |
V_54 ) ;
V_27 |= ( V_55 |
V_56 |
V_57 ) ;
} else {
V_26 |= ( V_58 |
V_59 |
V_60 ) ;
V_27 |= ( V_61 |
V_62 |
V_63 ) ;
}
if ( V_25 . V_64 )
V_28 |= ( V_55 |
V_56 |
V_57 ) ;
else
V_28 |= ( V_61 |
V_62 |
V_63 ) ;
V_16 -> V_31 . V_65 = V_66 ;
F_6 (
V_16 -> V_42 . V_26 , V_26 ) ;
F_6 (
V_16 -> V_42 . V_27 , V_27 ) ;
F_6 (
V_16 -> V_42 . V_28 , V_28 ) ;
return 0 ;
}
if ( V_18 == NULL ) {
F_7 ( L_1 ,
V_67 , V_2 -> V_68 ) ;
return - V_69 ;
}
if ( ! F_8 ( V_2 ) ) {
F_7 ( L_2
L_3 , V_2 -> V_68 ) ;
return - V_70 ;
}
F_9 ( V_18 , V_16 ) ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 ,
const struct V_15 * V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_2 -> V_19 ;
int V_71 ;
if ( V_6 -> V_20 -> V_21 & V_22 ||
V_6 -> V_20 -> V_21 & V_23 ) {
T_1 V_72 = V_50 | V_45 ;
if ( V_16 -> V_31 . V_49 != V_73 )
return - V_74 ;
V_72 &= ( V_61 |
V_55 |
V_62 |
V_56 |
V_63 |
V_57 ) ;
F_11 ( & V_6 -> V_75 ) ;
if ( V_6 -> V_20 -> V_38 -> V_76 )
V_6 -> V_20 -> V_38 -> V_76 ( V_6 -> V_41 , 1 ,
V_6 -> V_20 -> V_77 , 0 ) ;
F_12 ( & V_6 -> V_75 ) ;
return 0 ;
}
V_71 = F_13 ( V_18 , V_16 ) ;
return V_71 ;
}
static T_1 F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_78 ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_79 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_78 = V_79 ;
}
static int F_16 ( struct V_1 * V_2 )
{
if ( ! F_8 ( V_2 ) )
return - V_70 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return V_80 ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_81 * V_82 , void * V_83 )
{
T_1 * V_84 = ( T_1 * ) V_83 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
memset ( V_84 , 0x0 , V_80 ) ;
V_6 -> V_20 -> V_38 -> V_85 ( V_6 -> V_20 , V_84 ) ;
V_6 -> V_20 -> V_86 -> V_85 ( V_6 -> V_41 , V_84 ) ;
memcpy ( & V_84 [ V_87 ] , & V_84 [ V_88 / 4 ] ,
V_89 * 4 ) ;
}
static void
F_19 ( struct V_1 * V_90 ,
struct V_91 * V_43 )
{
struct V_5 * V_6 = F_2 ( V_90 ) ;
V_43 -> V_92 = 0 ;
V_43 -> V_93 = 0 ;
if ( V_6 -> V_20 -> V_21 && V_6 -> V_20 -> V_38 -> V_39 ) {
struct V_24 V_94 ;
V_43 -> V_49 = 1 ;
V_6 -> V_20 -> V_38 -> V_39 ( V_6 -> V_41 , & V_94 ) ;
if ( ! V_94 . V_43 )
return;
} else {
if ( ! ( V_90 -> V_19 -> V_26 & V_95 ) ||
! ( V_90 -> V_19 -> V_26 & V_96 ) )
return;
}
V_43 -> V_49 = V_90 -> V_19 -> V_49 ;
if ( V_6 -> V_97 & V_98 )
V_43 -> V_92 = 1 ;
if ( V_6 -> V_97 & V_99 )
V_43 -> V_93 = 1 ;
}
static int
F_20 ( struct V_1 * V_90 ,
struct V_91 * V_43 )
{
struct V_5 * V_6 = F_2 ( V_90 ) ;
T_1 V_100 = V_6 -> V_7 -> V_101 ;
struct V_17 * V_18 = V_90 -> V_19 ;
int V_102 = V_103 ;
if ( V_6 -> V_20 -> V_21 && V_6 -> V_20 -> V_38 -> V_39 ) {
struct V_24 V_94 ;
V_43 -> V_49 = 1 ;
V_6 -> V_20 -> V_38 -> V_39 ( V_6 -> V_41 , & V_94 ) ;
if ( ! V_94 . V_43 )
return - V_40 ;
} else {
if ( ! ( V_18 -> V_26 & V_95 ) ||
! ( V_18 -> V_26 & V_96 ) )
return - V_40 ;
}
if ( V_43 -> V_92 )
V_102 |= V_98 ;
if ( V_43 -> V_93 )
V_102 |= V_99 ;
V_6 -> V_97 = V_102 ;
V_18 -> V_49 = V_43 -> V_49 ;
if ( V_18 -> V_49 ) {
if ( F_8 ( V_90 ) )
return F_21 ( V_18 ) ;
}
V_6 -> V_20 -> V_38 -> V_97 ( V_6 -> V_20 , V_18 -> V_34 , V_6 -> V_97 ,
V_6 -> V_43 , V_100 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_104 * V_105 , T_2 * V_106 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_107 = V_6 -> V_7 -> V_108 ;
T_1 V_109 = V_6 -> V_7 -> V_101 ;
int V_110 , V_111 = 0 ;
if ( V_6 -> V_20 -> V_86 -> V_112 )
V_6 -> V_20 -> V_86 -> V_112 ( & V_2 -> V_113 ,
( void * ) & V_6 -> V_29 ,
V_6 -> V_41 ) ;
else {
if ( V_6 -> V_114 . V_115 ) {
F_23 ( V_6 -> V_116 , & V_6 -> V_117 ) ;
for ( V_110 = 0 ; V_110 < V_118 ; V_110 ++ ) {
char * V_119 ;
V_119 = ( char * ) V_6 + V_120 [ V_110 ] . V_121 ;
V_106 [ V_111 ++ ] = ( V_120 [ V_110 ] . V_122 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_119 ) :
( * ( T_1 * ) V_119 ) ;
}
}
if ( V_6 -> V_123 ) {
int V_124 = F_24 ( V_2 -> V_19 ) ;
if ( V_124 )
V_6 -> V_29 . V_125 = V_124 ;
}
if ( ( V_6 -> V_20 -> V_38 -> V_126 ) &&
( V_6 -> V_127 >= V_128 ) )
V_6 -> V_20 -> V_38 -> V_126 ( V_6 -> V_41 ,
( void * ) & V_6 -> V_29 ,
V_107 , V_109 ) ;
}
for ( V_110 = 0 ; V_110 < V_129 ; V_110 ++ ) {
char * V_119 = ( char * ) V_6 + V_130 [ V_110 ] . V_121 ;
V_106 [ V_111 ++ ] = ( V_130 [ V_110 ] . V_122 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_119 ) : ( * ( T_1 * ) V_119 ) ;
}
}
static int F_25 ( struct V_1 * V_90 , int V_131 )
{
struct V_5 * V_6 = F_2 ( V_90 ) ;
int V_132 ;
switch ( V_131 ) {
case V_133 :
V_132 = V_129 ;
if ( V_6 -> V_114 . V_115 )
V_132 += V_118 ;
return V_132 ;
default:
return - V_40 ;
}
}
static void F_26 ( struct V_1 * V_2 , T_1 V_134 , T_3 * V_106 )
{
int V_110 ;
T_3 * V_119 = V_106 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_134 ) {
case V_133 :
if ( V_6 -> V_114 . V_115 )
for ( V_110 = 0 ; V_110 < V_118 ; V_110 ++ ) {
memcpy ( V_119 , V_120 [ V_110 ] . V_135 ,
V_136 ) ;
V_119 += V_136 ;
}
for ( V_110 = 0 ; V_110 < V_129 ; V_110 ++ ) {
memcpy ( V_119 , V_130 [ V_110 ] . V_135 ,
V_136 ) ;
V_119 += V_136 ;
}
break;
default:
F_27 ( 1 ) ;
break;
}
}
static void F_28 ( struct V_1 * V_2 , struct V_137 * V_138 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_29 ( & V_6 -> V_75 ) ;
if ( F_30 ( V_6 -> V_139 ) ) {
V_138 -> V_26 = V_140 | V_141 ;
V_138 -> V_142 = V_6 -> V_142 ;
}
F_31 ( & V_6 -> V_75 ) ;
}
static int F_32 ( struct V_1 * V_2 , struct V_137 * V_138 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_143 = V_140 | V_141 ;
if ( ( V_6 -> V_144 ) && ( ! V_6 -> V_114 . V_145 ) )
V_138 -> V_142 &= ~ V_140 ;
if ( ! F_30 ( V_6 -> V_139 ) )
return - V_74 ;
if ( V_138 -> V_142 & ~ V_143 )
return - V_74 ;
if ( V_138 -> V_142 ) {
F_33 ( L_4 ) ;
F_34 ( V_6 -> V_139 , 1 ) ;
F_35 ( V_6 -> V_146 ) ;
} else {
F_34 ( V_6 -> V_139 , 0 ) ;
F_36 ( V_6 -> V_146 ) ;
}
F_29 ( & V_6 -> V_75 ) ;
V_6 -> V_142 = V_138 -> V_142 ;
F_31 ( & V_6 -> V_75 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_114 . V_149 )
return - V_40 ;
V_148 -> V_123 = V_6 -> V_123 ;
V_148 -> V_150 = V_6 -> V_150 ;
V_148 -> V_151 = V_6 -> V_151 ;
return F_38 ( V_2 -> V_19 , V_148 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_147 * V_148 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_123 = V_148 -> V_123 ;
if ( ! V_6 -> V_123 )
F_40 ( V_6 ) ;
else {
V_6 -> V_123 = F_41 ( V_6 ) ;
if ( ! V_6 -> V_123 )
return - V_40 ;
V_6 -> V_151 = V_148 -> V_151 ;
}
return F_42 ( V_2 -> V_19 , V_148 ) ;
}
static T_1 F_43 ( T_1 V_152 , struct V_5 * V_6 )
{
unsigned long V_153 = F_44 ( V_6 -> V_7 -> V_154 ) ;
if ( ! V_153 )
return 0 ;
return ( V_152 * ( V_153 / 1000000 ) ) / 256 ;
}
static T_1 F_45 ( T_1 V_155 , struct V_5 * V_6 )
{
unsigned long V_153 = F_44 ( V_6 -> V_7 -> V_154 ) ;
if ( ! V_153 )
return 0 ;
return ( V_155 * 256 ) / ( V_153 / 1000000 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_156 * V_157 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_157 -> V_158 = V_6 -> V_159 ;
V_157 -> V_160 = V_6 -> V_161 ;
if ( V_6 -> V_162 )
V_157 -> V_163 = F_45 ( V_6 -> V_164 , V_6 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_156 * V_157 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_165 = V_6 -> V_7 -> V_108 ;
unsigned int V_164 ;
if ( ( V_157 -> V_166 ) || ( V_157 -> V_167 ) ||
( V_157 -> V_168 ) || ( V_157 -> V_169 ) ||
( V_157 -> V_170 ) || ( V_157 -> V_171 ) ||
( V_157 -> V_172 ) || ( V_157 -> V_173 ) ||
( V_157 -> V_174 ) || ( V_157 -> V_175 ) ||
( V_157 -> V_176 ) || ( V_157 -> V_177 ) ||
( V_157 -> V_178 ) || ( V_157 -> V_179 ) ||
( V_157 -> V_180 ) ||
( V_157 -> V_181 ) ||
( V_157 -> V_182 ) ||
( V_157 -> V_183 ) || ( V_157 -> V_184 ) )
return - V_40 ;
if ( V_157 -> V_163 == 0 )
return - V_74 ;
if ( ( V_157 -> V_158 == 0 ) &&
( V_157 -> V_160 == 0 ) )
return - V_74 ;
if ( ( V_157 -> V_158 > V_185 ) ||
( V_157 -> V_160 > V_186 ) )
return - V_74 ;
V_164 = F_43 ( V_157 -> V_163 , V_6 ) ;
if ( ( V_164 > V_187 ) || ( V_164 < V_188 ) )
return - V_74 ;
else if ( ! V_6 -> V_162 )
return - V_40 ;
V_6 -> V_161 = V_157 -> V_160 ;
V_6 -> V_159 = V_157 -> V_158 ;
V_6 -> V_164 = V_164 ;
V_6 -> V_20 -> V_86 -> V_189 ( V_6 -> V_41 , V_6 -> V_164 , V_165 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_190 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_6 -> V_114 . V_191 || V_6 -> V_114 . V_192 ) ) {
V_4 -> V_193 = V_194 |
V_195 |
V_196 |
V_197 |
V_198 |
V_199 ;
if ( V_6 -> V_200 )
V_4 -> V_201 = F_49 ( V_6 -> V_200 ) ;
V_4 -> V_202 = ( 1 << V_203 ) | ( 1 << V_204 ) ;
V_4 -> V_205 = ( ( 1 << V_206 ) |
( 1 << V_207 ) |
( 1 << V_208 ) |
( 1 << V_209 ) |
( 1 << V_210 ) |
( 1 << V_211 ) |
( 1 << V_212 ) |
( 1 << V_213 ) |
( 1 << V_214 ) |
( 1 << V_215 ) |
( 1 << V_216 ) ) ;
return 0 ;
} else
return F_50 ( V_2 , V_4 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
const struct V_217 * V_218 , void * V_106 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_219 = 0 ;
switch ( V_218 -> V_220 ) {
case V_221 :
* ( T_1 * ) V_106 = V_6 -> V_222 ;
break;
default:
V_219 = - V_74 ;
break;
}
return V_219 ;
}
static int F_52 ( struct V_1 * V_2 ,
const struct V_217 * V_218 ,
const void * V_106 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_219 = 0 ;
switch ( V_218 -> V_220 ) {
case V_221 :
V_6 -> V_222 = * ( T_1 * ) V_106 ;
break;
default:
V_219 = - V_74 ;
break;
}
return V_219 ;
}
void F_53 ( struct V_1 * V_90 )
{
V_90 -> V_223 = & V_224 ;
}
