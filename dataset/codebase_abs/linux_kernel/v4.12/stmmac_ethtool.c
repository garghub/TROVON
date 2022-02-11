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
int V_20 ;
if ( V_6 -> V_21 -> V_22 & V_23 ||
V_6 -> V_21 -> V_22 & V_24 ) {
struct V_25 V_26 ;
T_1 V_27 , V_28 , V_29 ;
if ( ! V_6 -> V_30 . V_31 ) {
V_16 -> V_32 . V_33 = V_34 ;
V_16 -> V_32 . V_35 = V_36 ;
return 0 ;
}
V_16 -> V_32 . V_35 = V_6 -> V_30 . V_37 ;
V_16 -> V_32 . V_33 = V_6 -> V_30 . V_38 ;
if ( ! V_6 -> V_21 -> V_39 -> V_40 )
return - V_41 ;
V_6 -> V_21 -> V_39 -> V_40 ( V_6 -> V_42 , & V_26 ) ;
F_5 (
& V_27 , V_16 -> V_43 . V_27 ) ;
F_5 (
& V_28 , V_16 -> V_43 . V_28 ) ;
F_5 (
& V_29 , V_16 -> V_43 . V_29 ) ;
if ( V_26 . V_44 & V_45 )
V_28 |= V_46 ;
if ( V_26 . V_44 & V_47 )
V_28 |= V_48 ;
if ( V_26 . V_49 & V_45 )
V_29 |= V_46 ;
if ( V_26 . V_49 & V_47 )
V_29 |= V_48 ;
V_16 -> V_32 . V_50 = V_51 ;
V_27 |= V_52 ;
V_28 |= V_51 ;
V_29 |= V_51 ;
if ( V_26 . V_35 ) {
V_27 |= ( V_53 |
V_54 |
V_55 ) ;
V_28 |= ( V_56 |
V_57 |
V_58 ) ;
} else {
V_27 |= ( V_59 |
V_60 |
V_61 ) ;
V_28 |= ( V_62 |
V_63 |
V_64 ) ;
}
if ( V_26 . V_65 )
V_29 |= ( V_56 |
V_57 |
V_58 ) ;
else
V_29 |= ( V_62 |
V_63 |
V_64 ) ;
V_16 -> V_32 . V_66 = V_67 ;
F_6 (
V_16 -> V_43 . V_27 , V_27 ) ;
F_6 (
V_16 -> V_43 . V_28 , V_28 ) ;
F_6 (
V_16 -> V_43 . V_29 , V_29 ) ;
return 0 ;
}
if ( V_18 == NULL ) {
F_7 ( L_1 ,
V_68 , V_2 -> V_69 ) ;
return - V_70 ;
}
if ( ! F_8 ( V_2 ) ) {
F_7 ( L_2
L_3 , V_2 -> V_69 ) ;
return - V_71 ;
}
V_20 = F_9 ( V_18 , V_16 ) ;
return V_20 ;
}
static int
F_10 ( struct V_1 * V_2 ,
const struct V_15 * V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_2 -> V_19 ;
int V_20 ;
if ( V_6 -> V_21 -> V_22 & V_23 ||
V_6 -> V_21 -> V_22 & V_24 ) {
T_1 V_72 = V_51 | V_46 ;
if ( V_16 -> V_32 . V_50 != V_73 )
return - V_74 ;
V_72 &= ( V_62 |
V_56 |
V_63 |
V_57 |
V_64 |
V_58 ) ;
F_11 ( & V_6 -> V_75 ) ;
if ( V_6 -> V_21 -> V_39 -> V_76 )
V_6 -> V_21 -> V_39 -> V_76 ( V_6 -> V_42 , 1 ,
V_6 -> V_21 -> V_77 , 0 ) ;
F_12 ( & V_6 -> V_75 ) ;
return 0 ;
}
V_20 = F_13 ( V_18 , V_16 ) ;
return V_20 ;
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
return - V_71 ;
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
V_6 -> V_21 -> V_39 -> V_85 ( V_6 -> V_21 , V_84 ) ;
V_6 -> V_21 -> V_86 -> V_85 ( V_6 -> V_42 , V_84 ) ;
}
static void
F_19 ( struct V_1 * V_87 ,
struct V_88 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_87 ) ;
V_44 -> V_89 = 0 ;
V_44 -> V_90 = 0 ;
if ( V_6 -> V_21 -> V_22 && V_6 -> V_21 -> V_39 -> V_40 ) {
struct V_25 V_91 ;
V_44 -> V_50 = 1 ;
V_6 -> V_21 -> V_39 -> V_40 ( V_6 -> V_42 , & V_91 ) ;
if ( ! V_91 . V_44 )
return;
} else {
if ( ! ( V_87 -> V_19 -> V_27 & V_92 ) ||
! ( V_87 -> V_19 -> V_27 & V_93 ) )
return;
}
V_44 -> V_50 = V_87 -> V_19 -> V_50 ;
if ( V_6 -> V_94 & V_95 )
V_44 -> V_89 = 1 ;
if ( V_6 -> V_94 & V_96 )
V_44 -> V_90 = 1 ;
}
static int
F_20 ( struct V_1 * V_87 ,
struct V_88 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_87 ) ;
T_1 V_97 = V_6 -> V_7 -> V_98 ;
struct V_17 * V_18 = V_87 -> V_19 ;
int V_99 = V_100 ;
if ( V_6 -> V_21 -> V_22 && V_6 -> V_21 -> V_39 -> V_40 ) {
struct V_25 V_91 ;
V_44 -> V_50 = 1 ;
V_6 -> V_21 -> V_39 -> V_40 ( V_6 -> V_42 , & V_91 ) ;
if ( ! V_91 . V_44 )
return - V_41 ;
} else {
if ( ! ( V_18 -> V_27 & V_92 ) ||
! ( V_18 -> V_27 & V_93 ) )
return - V_41 ;
}
if ( V_44 -> V_89 )
V_99 |= V_95 ;
if ( V_44 -> V_90 )
V_99 |= V_96 ;
V_6 -> V_94 = V_99 ;
V_18 -> V_50 = V_44 -> V_50 ;
if ( V_18 -> V_50 ) {
if ( F_8 ( V_87 ) )
return F_21 ( V_18 ) ;
}
V_6 -> V_21 -> V_39 -> V_94 ( V_6 -> V_21 , V_18 -> V_35 , V_6 -> V_94 ,
V_6 -> V_44 , V_97 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_101 * V_102 , T_2 * V_103 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_104 = V_6 -> V_7 -> V_105 ;
T_1 V_106 = V_6 -> V_7 -> V_98 ;
int V_107 , V_108 = 0 ;
if ( V_6 -> V_21 -> V_86 -> V_109 )
V_6 -> V_21 -> V_86 -> V_109 ( & V_2 -> V_110 ,
( void * ) & V_6 -> V_30 ,
V_6 -> V_42 ) ;
else {
if ( V_6 -> V_111 . V_112 ) {
F_23 ( V_6 -> V_113 , & V_6 -> V_114 ) ;
for ( V_107 = 0 ; V_107 < V_115 ; V_107 ++ ) {
char * V_116 ;
V_116 = ( char * ) V_6 + V_117 [ V_107 ] . V_118 ;
V_103 [ V_108 ++ ] = ( V_117 [ V_107 ] . V_119 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_116 ) :
( * ( T_1 * ) V_116 ) ;
}
}
if ( V_6 -> V_120 ) {
int V_121 = F_24 ( V_2 -> V_19 ) ;
if ( V_121 )
V_6 -> V_30 . V_122 = V_121 ;
}
if ( ( V_6 -> V_21 -> V_39 -> V_123 ) &&
( V_6 -> V_124 >= V_125 ) )
V_6 -> V_21 -> V_39 -> V_123 ( V_6 -> V_42 ,
( void * ) & V_6 -> V_30 ,
V_104 , V_106 ) ;
}
for ( V_107 = 0 ; V_107 < V_126 ; V_107 ++ ) {
char * V_116 = ( char * ) V_6 + V_127 [ V_107 ] . V_118 ;
V_103 [ V_108 ++ ] = ( V_127 [ V_107 ] . V_119 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_116 ) : ( * ( T_1 * ) V_116 ) ;
}
}
static int F_25 ( struct V_1 * V_87 , int V_128 )
{
struct V_5 * V_6 = F_2 ( V_87 ) ;
int V_129 ;
switch ( V_128 ) {
case V_130 :
V_129 = V_126 ;
if ( V_6 -> V_111 . V_112 )
V_129 += V_115 ;
return V_129 ;
default:
return - V_41 ;
}
}
static void F_26 ( struct V_1 * V_2 , T_1 V_131 , T_3 * V_103 )
{
int V_107 ;
T_3 * V_116 = V_103 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_131 ) {
case V_130 :
if ( V_6 -> V_111 . V_112 )
for ( V_107 = 0 ; V_107 < V_115 ; V_107 ++ ) {
memcpy ( V_116 , V_117 [ V_107 ] . V_132 ,
V_133 ) ;
V_116 += V_133 ;
}
for ( V_107 = 0 ; V_107 < V_126 ; V_107 ++ ) {
memcpy ( V_116 , V_127 [ V_107 ] . V_132 ,
V_133 ) ;
V_116 += V_133 ;
}
break;
default:
F_27 ( 1 ) ;
break;
}
}
static void F_28 ( struct V_1 * V_2 , struct V_134 * V_135 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_29 ( & V_6 -> V_75 ) ;
if ( F_30 ( V_6 -> V_136 ) ) {
V_135 -> V_27 = V_137 | V_138 ;
V_135 -> V_139 = V_6 -> V_139 ;
}
F_31 ( & V_6 -> V_75 ) ;
}
static int F_32 ( struct V_1 * V_2 , struct V_134 * V_135 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_140 = V_137 | V_138 ;
if ( ( V_6 -> V_141 ) && ( ! V_6 -> V_111 . V_142 ) )
V_135 -> V_139 &= ~ V_137 ;
if ( ! F_30 ( V_6 -> V_136 ) )
return - V_74 ;
if ( V_135 -> V_139 & ~ V_140 )
return - V_74 ;
if ( V_135 -> V_139 ) {
F_33 ( L_4 ) ;
F_34 ( V_6 -> V_136 , 1 ) ;
F_35 ( V_6 -> V_143 ) ;
} else {
F_34 ( V_6 -> V_136 , 0 ) ;
F_36 ( V_6 -> V_143 ) ;
}
F_29 ( & V_6 -> V_75 ) ;
V_6 -> V_139 = V_135 -> V_139 ;
F_31 ( & V_6 -> V_75 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_144 * V_145 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_111 . V_146 )
return - V_41 ;
V_145 -> V_120 = V_6 -> V_120 ;
V_145 -> V_147 = V_6 -> V_147 ;
V_145 -> V_148 = V_6 -> V_148 ;
return F_38 ( V_2 -> V_19 , V_145 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_144 * V_145 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_120 = V_145 -> V_120 ;
if ( ! V_6 -> V_120 )
F_40 ( V_6 ) ;
else {
V_6 -> V_120 = F_41 ( V_6 ) ;
if ( ! V_6 -> V_120 )
return - V_41 ;
V_6 -> V_148 = V_145 -> V_148 ;
}
return F_42 ( V_2 -> V_19 , V_145 ) ;
}
static T_1 F_43 ( T_1 V_149 , struct V_5 * V_6 )
{
unsigned long V_150 = F_44 ( V_6 -> V_7 -> V_151 ) ;
if ( ! V_150 )
return 0 ;
return ( V_149 * ( V_150 / 1000000 ) ) / 256 ;
}
static T_1 F_45 ( T_1 V_152 , struct V_5 * V_6 )
{
unsigned long V_150 = F_44 ( V_6 -> V_7 -> V_151 ) ;
if ( ! V_150 )
return 0 ;
return ( V_152 * 256 ) / ( V_150 / 1000000 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_154 -> V_155 = V_6 -> V_156 ;
V_154 -> V_157 = V_6 -> V_158 ;
if ( V_6 -> V_159 )
V_154 -> V_160 = F_45 ( V_6 -> V_161 , V_6 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_153 * V_154 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_162 = V_6 -> V_7 -> V_105 ;
unsigned int V_161 ;
if ( ( V_154 -> V_163 ) || ( V_154 -> V_164 ) ||
( V_154 -> V_165 ) || ( V_154 -> V_166 ) ||
( V_154 -> V_167 ) || ( V_154 -> V_168 ) ||
( V_154 -> V_169 ) || ( V_154 -> V_170 ) ||
( V_154 -> V_171 ) || ( V_154 -> V_172 ) ||
( V_154 -> V_173 ) || ( V_154 -> V_174 ) ||
( V_154 -> V_175 ) || ( V_154 -> V_176 ) ||
( V_154 -> V_177 ) ||
( V_154 -> V_178 ) ||
( V_154 -> V_179 ) ||
( V_154 -> V_180 ) || ( V_154 -> V_181 ) )
return - V_41 ;
if ( V_154 -> V_160 == 0 )
return - V_74 ;
if ( ( V_154 -> V_155 == 0 ) &&
( V_154 -> V_157 == 0 ) )
return - V_74 ;
if ( ( V_154 -> V_155 > V_182 ) ||
( V_154 -> V_157 > V_183 ) )
return - V_74 ;
V_161 = F_43 ( V_154 -> V_160 , V_6 ) ;
if ( ( V_161 > V_184 ) || ( V_161 < V_185 ) )
return - V_74 ;
else if ( ! V_6 -> V_159 )
return - V_41 ;
V_6 -> V_158 = V_154 -> V_157 ;
V_6 -> V_156 = V_154 -> V_155 ;
V_6 -> V_161 = V_161 ;
V_6 -> V_21 -> V_86 -> V_186 ( V_6 -> V_42 , V_6 -> V_161 , V_162 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_187 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_6 -> V_111 . V_188 || V_6 -> V_111 . V_189 ) ) {
V_4 -> V_190 = V_191 |
V_192 |
V_193 |
V_194 |
V_195 |
V_196 ;
if ( V_6 -> V_197 )
V_4 -> V_198 = F_49 ( V_6 -> V_197 ) ;
V_4 -> V_199 = ( 1 << V_200 ) | ( 1 << V_201 ) ;
V_4 -> V_202 = ( ( 1 << V_203 ) |
( 1 << V_204 ) |
( 1 << V_205 ) |
( 1 << V_206 ) |
( 1 << V_207 ) |
( 1 << V_208 ) |
( 1 << V_209 ) |
( 1 << V_210 ) |
( 1 << V_211 ) |
( 1 << V_212 ) |
( 1 << V_213 ) ) ;
return 0 ;
} else
return F_50 ( V_2 , V_4 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
const struct V_214 * V_215 , void * V_103 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_216 = 0 ;
switch ( V_215 -> V_217 ) {
case V_218 :
* ( T_1 * ) V_103 = V_6 -> V_219 ;
break;
default:
V_216 = - V_74 ;
break;
}
return V_216 ;
}
static int F_52 ( struct V_1 * V_2 ,
const struct V_214 * V_215 ,
const void * V_103 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_216 = 0 ;
switch ( V_215 -> V_217 ) {
case V_218 :
V_6 -> V_219 = * ( T_1 * ) V_103 ;
break;
default:
V_216 = - V_74 ;
break;
}
return V_216 ;
}
void F_53 ( struct V_1 * V_87 )
{
V_87 -> V_220 = & V_221 ;
}
