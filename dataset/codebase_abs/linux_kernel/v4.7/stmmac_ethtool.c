static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 -> V_8 )
F_3 ( V_4 -> V_9 , V_10 , sizeof( V_4 -> V_9 ) ) ;
else
F_3 ( V_4 -> V_9 , V_11 ,
sizeof( V_4 -> V_9 ) ) ;
F_3 ( V_4 -> V_12 , V_13 , sizeof( V_4 -> V_12 ) ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_6 -> V_18 ;
int V_19 ;
if ( ( V_6 -> V_20 & V_21 ) || ( V_6 -> V_20 & V_22 ) ) {
struct V_23 V_24 ;
if ( ! V_6 -> V_25 . V_26 ) {
F_5 ( V_15 , V_27 ) ;
V_15 -> V_28 = V_29 ;
return 0 ;
}
V_15 -> V_28 = V_6 -> V_25 . V_30 ;
F_5 ( V_15 , V_6 -> V_25 . V_31 ) ;
if ( ! V_6 -> V_32 -> V_33 -> V_34 )
return - V_35 ;
V_6 -> V_32 -> V_33 -> V_34 ( V_6 -> V_32 , & V_24 ) ;
if ( V_24 . V_36 & V_37 )
V_15 -> V_38 |= V_39 ;
if ( V_24 . V_36 & V_40 )
V_15 -> V_38 |= V_41 ;
if ( V_24 . V_42 & V_37 )
V_15 -> V_43 |= V_39 ;
if ( V_24 . V_42 & V_40 )
V_15 -> V_43 |= V_41 ;
V_15 -> V_44 = V_45 ;
V_15 -> V_46 |= V_47 ;
V_15 -> V_38 |= V_45 ;
V_15 -> V_43 |= V_45 ;
if ( V_24 . V_28 ) {
V_15 -> V_46 |= ( V_48 |
V_49 |
V_50 ) ;
V_15 -> V_38 |= ( V_51 |
V_52 |
V_53 ) ;
} else {
V_15 -> V_46 |= ( V_54 |
V_55 |
V_56 ) ;
V_15 -> V_38 |= ( V_57 |
V_58 |
V_59 ) ;
}
if ( V_24 . V_60 )
V_15 -> V_43 |= ( V_51 |
V_52 |
V_53 ) ;
else
V_15 -> V_43 |= ( V_57 |
V_58 |
V_59 ) ;
V_15 -> V_61 = V_62 ;
return 0 ;
}
if ( V_17 == NULL ) {
F_6 ( L_1 ,
V_63 , V_2 -> V_64 ) ;
return - V_65 ;
}
if ( ! F_7 ( V_2 ) ) {
F_6 ( L_2
L_3 , V_2 -> V_64 ) ;
return - V_66 ;
}
V_15 -> V_67 = V_68 ;
V_19 = F_8 ( V_17 , V_15 ) ;
return V_19 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_6 -> V_18 ;
int V_19 ;
if ( ( V_6 -> V_20 & V_21 ) || ( V_6 -> V_20 & V_22 ) ) {
T_1 V_69 = V_45 | V_39 ;
if ( V_15 -> V_44 != V_70 )
return - V_71 ;
V_69 &= ( V_57 |
V_51 |
V_58 |
V_52 |
V_59 |
V_53 ) ;
F_10 ( & V_6 -> V_72 ) ;
if ( V_6 -> V_32 -> V_33 -> V_73 )
V_6 -> V_32 -> V_33 -> V_73 ( V_6 -> V_32 , 1 ) ;
F_11 ( & V_6 -> V_72 ) ;
return 0 ;
}
F_10 ( & V_6 -> V_72 ) ;
V_19 = F_12 ( V_17 , V_15 ) ;
F_11 ( & V_6 -> V_72 ) ;
return V_19 ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_74 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_75 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_74 = V_75 ;
}
static int F_15 ( struct V_1 * V_2 )
{
if ( ! F_7 ( V_2 ) )
return - V_66 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return V_76 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_77 * V_78 , void * V_79 )
{
int V_80 ;
T_1 * V_81 = ( T_1 * ) V_79 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
memset ( V_81 , 0x0 , V_76 ) ;
if ( ! V_6 -> V_7 -> V_8 ) {
for ( V_80 = 0 ; V_80 < 12 ; V_80 ++ )
V_81 [ V_80 ] = F_18 ( V_6 -> V_82 + ( V_80 * 4 ) ) ;
for ( V_80 = 0 ; V_80 < 9 ; V_80 ++ )
V_81 [ V_80 + 12 ] =
F_18 ( V_6 -> V_82 + ( V_83 + ( V_80 * 4 ) ) ) ;
V_81 [ 22 ] = F_18 ( V_6 -> V_82 + V_84 ) ;
V_81 [ 23 ] = F_18 ( V_6 -> V_82 + V_85 ) ;
} else {
for ( V_80 = 0 ; V_80 < 55 ; V_80 ++ )
V_81 [ V_80 ] = F_18 ( V_6 -> V_82 + ( V_80 * 4 ) ) ;
for ( V_80 = 0 ; V_80 < 22 ; V_80 ++ )
V_81 [ V_80 + 55 ] =
F_18 ( V_6 -> V_82 + ( V_83 + ( V_80 * 4 ) ) ) ;
}
}
static void
F_19 ( struct V_1 * V_86 ,
struct V_87 * V_36 )
{
struct V_5 * V_6 = F_2 ( V_86 ) ;
if ( V_6 -> V_20 )
return;
V_36 -> V_88 = 0 ;
V_36 -> V_89 = 0 ;
V_36 -> V_44 = V_6 -> V_18 -> V_44 ;
if ( V_6 -> V_90 & V_91 )
V_36 -> V_88 = 1 ;
if ( V_6 -> V_90 & V_92 )
V_36 -> V_89 = 1 ;
}
static int
F_20 ( struct V_1 * V_86 ,
struct V_87 * V_36 )
{
struct V_5 * V_6 = F_2 ( V_86 ) ;
struct V_16 * V_17 = V_6 -> V_18 ;
int V_93 = V_94 ;
int V_95 = 0 ;
if ( V_6 -> V_20 )
return - V_35 ;
if ( V_36 -> V_88 )
V_93 |= V_91 ;
if ( V_36 -> V_89 )
V_93 |= V_92 ;
V_6 -> V_90 = V_93 ;
V_17 -> V_44 = V_36 -> V_44 ;
if ( V_17 -> V_44 ) {
if ( F_7 ( V_86 ) )
V_95 = F_21 ( V_17 ) ;
} else
V_6 -> V_32 -> V_33 -> V_90 ( V_6 -> V_32 , V_17 -> V_28 ,
V_6 -> V_90 , V_6 -> V_36 ) ;
return V_95 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_96 * V_97 , T_2 * V_98 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_80 , V_99 = 0 ;
if ( V_6 -> V_32 -> V_100 -> V_101 )
V_6 -> V_32 -> V_100 -> V_101 ( & V_2 -> V_102 ,
( void * ) & V_6 -> V_25 ,
V_6 -> V_82 ) ;
else {
if ( V_6 -> V_103 . V_104 ) {
F_23 ( V_6 -> V_105 , & V_6 -> V_106 ) ;
for ( V_80 = 0 ; V_80 < V_107 ; V_80 ++ ) {
char * V_108 ;
V_108 = ( char * ) V_6 + V_109 [ V_80 ] . V_110 ;
V_98 [ V_99 ++ ] = ( V_109 [ V_80 ] . V_111 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_108 ) :
( * ( T_1 * ) V_108 ) ;
}
}
if ( V_6 -> V_112 ) {
int V_113 = F_24 ( V_6 -> V_18 ) ;
if ( V_113 )
V_6 -> V_25 . V_114 = V_113 ;
}
if ( ( V_6 -> V_32 -> V_33 -> V_115 ) &&
( V_6 -> V_116 >= V_117 ) )
V_6 -> V_32 -> V_33 -> V_115 ( V_6 -> V_82 ,
( void * ) & V_6 -> V_25 ) ;
}
for ( V_80 = 0 ; V_80 < V_118 ; V_80 ++ ) {
char * V_108 = ( char * ) V_6 + V_119 [ V_80 ] . V_110 ;
V_98 [ V_99 ++ ] = ( V_119 [ V_80 ] . V_111 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_108 ) : ( * ( T_1 * ) V_108 ) ;
}
}
static int F_25 ( struct V_1 * V_86 , int V_120 )
{
struct V_5 * V_6 = F_2 ( V_86 ) ;
int V_121 ;
switch ( V_120 ) {
case V_122 :
V_121 = V_118 ;
if ( V_6 -> V_103 . V_104 )
V_121 += V_107 ;
return V_121 ;
default:
return - V_35 ;
}
}
static void F_26 ( struct V_1 * V_2 , T_1 V_123 , T_3 * V_98 )
{
int V_80 ;
T_3 * V_108 = V_98 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_123 ) {
case V_122 :
if ( V_6 -> V_103 . V_104 )
for ( V_80 = 0 ; V_80 < V_107 ; V_80 ++ ) {
memcpy ( V_108 , V_109 [ V_80 ] . V_124 ,
V_125 ) ;
V_108 += V_125 ;
}
for ( V_80 = 0 ; V_80 < V_118 ; V_80 ++ ) {
memcpy ( V_108 , V_119 [ V_80 ] . V_124 ,
V_125 ) ;
V_108 += V_125 ;
}
break;
default:
F_27 ( 1 ) ;
break;
}
}
static void F_28 ( struct V_1 * V_2 , struct V_126 * V_127 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_29 ( & V_6 -> V_72 ) ;
if ( F_30 ( V_6 -> V_128 ) ) {
V_127 -> V_46 = V_129 | V_130 ;
V_127 -> V_131 = V_6 -> V_131 ;
}
F_31 ( & V_6 -> V_72 ) ;
}
static int F_32 ( struct V_1 * V_2 , struct V_126 * V_127 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_132 = V_129 | V_130 ;
if ( ( V_6 -> V_133 ) && ( ! V_6 -> V_103 . V_134 ) )
V_127 -> V_131 &= ~ V_129 ;
if ( ! F_30 ( V_6 -> V_128 ) )
return - V_71 ;
if ( V_127 -> V_131 & ~ V_132 )
return - V_71 ;
if ( V_127 -> V_131 ) {
F_33 ( L_4 ) ;
F_34 ( V_6 -> V_128 , 1 ) ;
F_35 ( V_6 -> V_135 ) ;
} else {
F_34 ( V_6 -> V_128 , 0 ) ;
F_36 ( V_6 -> V_135 ) ;
}
F_29 ( & V_6 -> V_72 ) ;
V_6 -> V_131 = V_127 -> V_131 ;
F_31 ( & V_6 -> V_72 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_136 * V_137 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_103 . V_138 )
return - V_35 ;
V_137 -> V_112 = V_6 -> V_112 ;
V_137 -> V_139 = V_6 -> V_139 ;
V_137 -> V_140 = V_6 -> V_140 ;
return F_38 ( V_6 -> V_18 , V_137 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_136 * V_137 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_112 = V_137 -> V_112 ;
if ( ! V_6 -> V_112 )
F_40 ( V_6 ) ;
else {
V_6 -> V_112 = F_41 ( V_6 ) ;
if ( ! V_6 -> V_112 )
return - V_35 ;
V_6 -> V_140 = V_137 -> V_140 ;
}
return F_42 ( V_6 -> V_18 , V_137 ) ;
}
static T_1 F_43 ( T_1 V_141 , struct V_5 * V_6 )
{
unsigned long V_142 = F_44 ( V_6 -> V_143 ) ;
if ( ! V_142 )
return 0 ;
return ( V_141 * ( V_142 / 1000000 ) ) / 256 ;
}
static T_1 F_45 ( T_1 V_144 , struct V_5 * V_6 )
{
unsigned long V_142 = F_44 ( V_6 -> V_143 ) ;
if ( ! V_142 )
return 0 ;
return ( V_144 * 256 ) / ( V_142 / 1000000 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_145 * V_146 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_146 -> V_147 = V_6 -> V_148 ;
V_146 -> V_149 = V_6 -> V_150 ;
if ( V_6 -> V_151 )
V_146 -> V_152 = F_45 ( V_6 -> V_153 , V_6 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_145 * V_146 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_153 ;
if ( ( V_146 -> V_154 ) || ( V_146 -> V_155 ) ||
( V_146 -> V_156 ) || ( V_146 -> V_157 ) ||
( V_146 -> V_158 ) || ( V_146 -> V_159 ) ||
( V_146 -> V_160 ) || ( V_146 -> V_161 ) ||
( V_146 -> V_162 ) || ( V_146 -> V_163 ) ||
( V_146 -> V_164 ) || ( V_146 -> V_165 ) ||
( V_146 -> V_166 ) || ( V_146 -> V_167 ) ||
( V_146 -> V_168 ) ||
( V_146 -> V_169 ) ||
( V_146 -> V_170 ) ||
( V_146 -> V_171 ) || ( V_146 -> V_172 ) )
return - V_35 ;
if ( V_146 -> V_152 == 0 )
return - V_71 ;
if ( ( V_146 -> V_147 == 0 ) &&
( V_146 -> V_149 == 0 ) )
return - V_71 ;
if ( ( V_146 -> V_147 > V_173 ) ||
( V_146 -> V_149 > V_174 ) )
return - V_71 ;
V_153 = F_43 ( V_146 -> V_152 , V_6 ) ;
if ( ( V_153 > V_175 ) || ( V_153 < V_176 ) )
return - V_71 ;
else if ( ! V_6 -> V_151 )
return - V_35 ;
V_6 -> V_150 = V_146 -> V_149 ;
V_6 -> V_148 = V_146 -> V_147 ;
V_6 -> V_153 = V_153 ;
V_6 -> V_32 -> V_100 -> V_177 ( V_6 -> V_82 , V_6 -> V_153 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_178 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_6 -> V_103 . V_179 || V_6 -> V_103 . V_180 ) ) {
V_4 -> V_181 = V_182 |
V_183 |
V_184 |
V_185 |
V_186 |
V_187 ;
if ( V_6 -> V_188 )
V_4 -> V_189 = F_49 ( V_6 -> V_188 ) ;
V_4 -> V_190 = ( 1 << V_191 ) | ( 1 << V_192 ) ;
V_4 -> V_193 = ( ( 1 << V_194 ) |
( 1 << V_195 ) |
( 1 << V_196 ) |
( 1 << V_197 ) |
( 1 << V_198 ) |
( 1 << V_199 ) |
( 1 << V_200 ) |
( 1 << V_201 ) |
( 1 << V_202 ) |
( 1 << V_203 ) |
( 1 << V_204 ) ) ;
return 0 ;
} else
return F_50 ( V_2 , V_4 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
const struct V_205 * V_206 , void * V_98 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_95 = 0 ;
switch ( V_206 -> V_207 ) {
case V_208 :
* ( T_1 * ) V_98 = V_6 -> V_209 ;
break;
default:
V_95 = - V_71 ;
break;
}
return V_95 ;
}
static int F_52 ( struct V_1 * V_2 ,
const struct V_205 * V_206 ,
const void * V_98 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_95 = 0 ;
switch ( V_206 -> V_207 ) {
case V_208 :
V_6 -> V_209 = * ( T_1 * ) V_98 ;
break;
default:
V_95 = - V_71 ;
break;
}
return V_95 ;
}
void F_53 ( struct V_1 * V_86 )
{
V_86 -> V_210 = & V_211 ;
}
