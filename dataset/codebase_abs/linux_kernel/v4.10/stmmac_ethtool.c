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
int V_84 ;
T_1 * V_85 = ( T_1 * ) V_83 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
memset ( V_85 , 0x0 , V_80 ) ;
if ( ! ( V_6 -> V_7 -> V_8 || V_6 -> V_7 -> V_9 ) ) {
for ( V_84 = 0 ; V_84 < 12 ; V_84 ++ )
V_85 [ V_84 ] = F_19 ( V_6 -> V_42 + ( V_84 * 4 ) ) ;
for ( V_84 = 0 ; V_84 < 9 ; V_84 ++ )
V_85 [ V_84 + 12 ] =
F_19 ( V_6 -> V_42 + ( V_86 + ( V_84 * 4 ) ) ) ;
V_85 [ 22 ] = F_19 ( V_6 -> V_42 + V_87 ) ;
V_85 [ 23 ] = F_19 ( V_6 -> V_42 + V_88 ) ;
} else {
for ( V_84 = 0 ; V_84 < 55 ; V_84 ++ )
V_85 [ V_84 ] = F_19 ( V_6 -> V_42 + ( V_84 * 4 ) ) ;
for ( V_84 = 0 ; V_84 < 22 ; V_84 ++ )
V_85 [ V_84 + 55 ] =
F_19 ( V_6 -> V_42 + ( V_86 + ( V_84 * 4 ) ) ) ;
}
}
static void
F_20 ( struct V_1 * V_89 ,
struct V_90 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_89 ) ;
V_44 -> V_91 = 0 ;
V_44 -> V_92 = 0 ;
if ( V_6 -> V_21 -> V_22 && V_6 -> V_21 -> V_39 -> V_40 ) {
struct V_25 V_93 ;
V_44 -> V_50 = 1 ;
V_6 -> V_21 -> V_39 -> V_40 ( V_6 -> V_42 , & V_93 ) ;
if ( ! V_93 . V_44 )
return;
} else {
if ( ! ( V_89 -> V_19 -> V_27 & V_94 ) ||
! ( V_89 -> V_19 -> V_27 & V_95 ) )
return;
}
V_44 -> V_50 = V_89 -> V_19 -> V_50 ;
if ( V_6 -> V_96 & V_97 )
V_44 -> V_91 = 1 ;
if ( V_6 -> V_96 & V_98 )
V_44 -> V_92 = 1 ;
}
static int
F_21 ( struct V_1 * V_89 ,
struct V_90 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_89 ) ;
struct V_17 * V_18 = V_89 -> V_19 ;
int V_99 = V_100 ;
if ( V_6 -> V_21 -> V_22 && V_6 -> V_21 -> V_39 -> V_40 ) {
struct V_25 V_93 ;
V_44 -> V_50 = 1 ;
V_6 -> V_21 -> V_39 -> V_40 ( V_6 -> V_42 , & V_93 ) ;
if ( ! V_93 . V_44 )
return - V_41 ;
} else {
if ( ! ( V_18 -> V_27 & V_94 ) ||
! ( V_18 -> V_27 & V_95 ) )
return - V_41 ;
}
if ( V_44 -> V_91 )
V_99 |= V_97 ;
if ( V_44 -> V_92 )
V_99 |= V_98 ;
V_6 -> V_96 = V_99 ;
V_18 -> V_50 = V_44 -> V_50 ;
if ( V_18 -> V_50 ) {
if ( F_8 ( V_89 ) )
return F_22 ( V_18 ) ;
}
V_6 -> V_21 -> V_39 -> V_96 ( V_6 -> V_21 , V_18 -> V_35 , V_6 -> V_96 ,
V_6 -> V_44 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_101 * V_102 , T_2 * V_103 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_84 , V_104 = 0 ;
if ( V_6 -> V_21 -> V_105 -> V_106 )
V_6 -> V_21 -> V_105 -> V_106 ( & V_2 -> V_107 ,
( void * ) & V_6 -> V_30 ,
V_6 -> V_42 ) ;
else {
if ( V_6 -> V_108 . V_109 ) {
F_24 ( V_6 -> V_110 , & V_6 -> V_111 ) ;
for ( V_84 = 0 ; V_84 < V_112 ; V_84 ++ ) {
char * V_113 ;
V_113 = ( char * ) V_6 + V_114 [ V_84 ] . V_115 ;
V_103 [ V_104 ++ ] = ( V_114 [ V_84 ] . V_116 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_113 ) :
( * ( T_1 * ) V_113 ) ;
}
}
if ( V_6 -> V_117 ) {
int V_118 = F_25 ( V_2 -> V_19 ) ;
if ( V_118 )
V_6 -> V_30 . V_119 = V_118 ;
}
if ( ( V_6 -> V_21 -> V_39 -> V_120 ) &&
( V_6 -> V_121 >= V_122 ) )
V_6 -> V_21 -> V_39 -> V_120 ( V_6 -> V_42 ,
( void * ) & V_6 -> V_30 ) ;
}
for ( V_84 = 0 ; V_84 < V_123 ; V_84 ++ ) {
char * V_113 = ( char * ) V_6 + V_124 [ V_84 ] . V_115 ;
V_103 [ V_104 ++ ] = ( V_124 [ V_84 ] . V_116 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_113 ) : ( * ( T_1 * ) V_113 ) ;
}
}
static int F_26 ( struct V_1 * V_89 , int V_125 )
{
struct V_5 * V_6 = F_2 ( V_89 ) ;
int V_126 ;
switch ( V_125 ) {
case V_127 :
V_126 = V_123 ;
if ( V_6 -> V_108 . V_109 )
V_126 += V_112 ;
return V_126 ;
default:
return - V_41 ;
}
}
static void F_27 ( struct V_1 * V_2 , T_1 V_128 , T_3 * V_103 )
{
int V_84 ;
T_3 * V_113 = V_103 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_128 ) {
case V_127 :
if ( V_6 -> V_108 . V_109 )
for ( V_84 = 0 ; V_84 < V_112 ; V_84 ++ ) {
memcpy ( V_113 , V_114 [ V_84 ] . V_129 ,
V_130 ) ;
V_113 += V_130 ;
}
for ( V_84 = 0 ; V_84 < V_123 ; V_84 ++ ) {
memcpy ( V_113 , V_124 [ V_84 ] . V_129 ,
V_130 ) ;
V_113 += V_130 ;
}
break;
default:
F_28 ( 1 ) ;
break;
}
}
static void F_29 ( struct V_1 * V_2 , struct V_131 * V_132 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_30 ( & V_6 -> V_75 ) ;
if ( F_31 ( V_6 -> V_133 ) ) {
V_132 -> V_27 = V_134 | V_135 ;
V_132 -> V_136 = V_6 -> V_136 ;
}
F_32 ( & V_6 -> V_75 ) ;
}
static int F_33 ( struct V_1 * V_2 , struct V_131 * V_132 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_137 = V_134 | V_135 ;
if ( ( V_6 -> V_138 ) && ( ! V_6 -> V_108 . V_139 ) )
V_132 -> V_136 &= ~ V_134 ;
if ( ! F_31 ( V_6 -> V_133 ) )
return - V_74 ;
if ( V_132 -> V_136 & ~ V_137 )
return - V_74 ;
if ( V_132 -> V_136 ) {
F_34 ( L_4 ) ;
F_35 ( V_6 -> V_133 , 1 ) ;
F_36 ( V_6 -> V_140 ) ;
} else {
F_35 ( V_6 -> V_133 , 0 ) ;
F_37 ( V_6 -> V_140 ) ;
}
F_30 ( & V_6 -> V_75 ) ;
V_6 -> V_136 = V_132 -> V_136 ;
F_32 ( & V_6 -> V_75 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_141 * V_142 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_108 . V_143 )
return - V_41 ;
V_142 -> V_117 = V_6 -> V_117 ;
V_142 -> V_144 = V_6 -> V_144 ;
V_142 -> V_145 = V_6 -> V_145 ;
return F_39 ( V_2 -> V_19 , V_142 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_141 * V_142 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_117 = V_142 -> V_117 ;
if ( ! V_6 -> V_117 )
F_41 ( V_6 ) ;
else {
V_6 -> V_117 = F_42 ( V_6 ) ;
if ( ! V_6 -> V_117 )
return - V_41 ;
V_6 -> V_145 = V_142 -> V_145 ;
}
return F_43 ( V_2 -> V_19 , V_142 ) ;
}
static T_1 F_44 ( T_1 V_146 , struct V_5 * V_6 )
{
unsigned long V_147 = F_45 ( V_6 -> V_148 ) ;
if ( ! V_147 )
return 0 ;
return ( V_146 * ( V_147 / 1000000 ) ) / 256 ;
}
static T_1 F_46 ( T_1 V_149 , struct V_5 * V_6 )
{
unsigned long V_147 = F_45 ( V_6 -> V_148 ) ;
if ( ! V_147 )
return 0 ;
return ( V_149 * 256 ) / ( V_147 / 1000000 ) ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_150 * V_151 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_151 -> V_152 = V_6 -> V_153 ;
V_151 -> V_154 = V_6 -> V_155 ;
if ( V_6 -> V_156 )
V_151 -> V_157 = F_46 ( V_6 -> V_158 , V_6 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_150 * V_151 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_158 ;
if ( ( V_151 -> V_159 ) || ( V_151 -> V_160 ) ||
( V_151 -> V_161 ) || ( V_151 -> V_162 ) ||
( V_151 -> V_163 ) || ( V_151 -> V_164 ) ||
( V_151 -> V_165 ) || ( V_151 -> V_166 ) ||
( V_151 -> V_167 ) || ( V_151 -> V_168 ) ||
( V_151 -> V_169 ) || ( V_151 -> V_170 ) ||
( V_151 -> V_171 ) || ( V_151 -> V_172 ) ||
( V_151 -> V_173 ) ||
( V_151 -> V_174 ) ||
( V_151 -> V_175 ) ||
( V_151 -> V_176 ) || ( V_151 -> V_177 ) )
return - V_41 ;
if ( V_151 -> V_157 == 0 )
return - V_74 ;
if ( ( V_151 -> V_152 == 0 ) &&
( V_151 -> V_154 == 0 ) )
return - V_74 ;
if ( ( V_151 -> V_152 > V_178 ) ||
( V_151 -> V_154 > V_179 ) )
return - V_74 ;
V_158 = F_44 ( V_151 -> V_157 , V_6 ) ;
if ( ( V_158 > V_180 ) || ( V_158 < V_181 ) )
return - V_74 ;
else if ( ! V_6 -> V_156 )
return - V_41 ;
V_6 -> V_155 = V_151 -> V_154 ;
V_6 -> V_153 = V_151 -> V_152 ;
V_6 -> V_158 = V_158 ;
V_6 -> V_21 -> V_105 -> V_182 ( V_6 -> V_42 , V_6 -> V_158 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_183 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_6 -> V_108 . V_184 || V_6 -> V_108 . V_185 ) ) {
V_4 -> V_186 = V_187 |
V_188 |
V_189 |
V_190 |
V_191 |
V_192 ;
if ( V_6 -> V_193 )
V_4 -> V_194 = F_50 ( V_6 -> V_193 ) ;
V_4 -> V_195 = ( 1 << V_196 ) | ( 1 << V_197 ) ;
V_4 -> V_198 = ( ( 1 << V_199 ) |
( 1 << V_200 ) |
( 1 << V_201 ) |
( 1 << V_202 ) |
( 1 << V_203 ) |
( 1 << V_204 ) |
( 1 << V_205 ) |
( 1 << V_206 ) |
( 1 << V_207 ) |
( 1 << V_208 ) |
( 1 << V_209 ) ) ;
return 0 ;
} else
return F_51 ( V_2 , V_4 ) ;
}
static int F_52 ( struct V_1 * V_2 ,
const struct V_210 * V_211 , void * V_103 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_212 = 0 ;
switch ( V_211 -> V_213 ) {
case V_214 :
* ( T_1 * ) V_103 = V_6 -> V_215 ;
break;
default:
V_212 = - V_74 ;
break;
}
return V_212 ;
}
static int F_53 ( struct V_1 * V_2 ,
const struct V_210 * V_211 ,
const void * V_103 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_212 = 0 ;
switch ( V_211 -> V_213 ) {
case V_214 :
V_6 -> V_215 = * ( T_1 * ) V_103 ;
break;
default:
V_212 = - V_74 ;
break;
}
return V_212 ;
}
void F_54 ( struct V_1 * V_89 )
{
V_89 -> V_216 = & V_217 ;
}
