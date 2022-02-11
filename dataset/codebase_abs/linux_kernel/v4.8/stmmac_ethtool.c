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
if ( V_6 -> V_20 -> V_21 & V_22 ||
V_6 -> V_20 -> V_21 & V_23 ) {
struct V_24 V_25 ;
if ( ! V_6 -> V_26 . V_27 ) {
F_5 ( V_15 , V_28 ) ;
V_15 -> V_29 = V_30 ;
return 0 ;
}
V_15 -> V_29 = V_6 -> V_26 . V_31 ;
F_5 ( V_15 , V_6 -> V_26 . V_32 ) ;
if ( ! V_6 -> V_20 -> V_33 -> V_34 )
return - V_35 ;
V_6 -> V_20 -> V_33 -> V_34 ( V_6 -> V_36 , & V_25 ) ;
if ( V_25 . V_37 & V_38 )
V_15 -> V_39 |= V_40 ;
if ( V_25 . V_37 & V_41 )
V_15 -> V_39 |= V_42 ;
if ( V_25 . V_43 & V_38 )
V_15 -> V_44 |= V_40 ;
if ( V_25 . V_43 & V_41 )
V_15 -> V_44 |= V_42 ;
V_15 -> V_45 = V_46 ;
V_15 -> V_47 |= V_48 ;
V_15 -> V_39 |= V_46 ;
V_15 -> V_44 |= V_46 ;
if ( V_25 . V_29 ) {
V_15 -> V_47 |= ( V_49 |
V_50 |
V_51 ) ;
V_15 -> V_39 |= ( V_52 |
V_53 |
V_54 ) ;
} else {
V_15 -> V_47 |= ( V_55 |
V_56 |
V_57 ) ;
V_15 -> V_39 |= ( V_58 |
V_59 |
V_60 ) ;
}
if ( V_25 . V_61 )
V_15 -> V_44 |= ( V_52 |
V_53 |
V_54 ) ;
else
V_15 -> V_44 |= ( V_58 |
V_59 |
V_60 ) ;
V_15 -> V_62 = V_63 ;
return 0 ;
}
if ( V_17 == NULL ) {
F_6 ( L_1 ,
V_64 , V_2 -> V_65 ) ;
return - V_66 ;
}
if ( ! F_7 ( V_2 ) ) {
F_6 ( L_2
L_3 , V_2 -> V_65 ) ;
return - V_67 ;
}
V_15 -> V_68 = V_69 ;
V_19 = F_8 ( V_17 , V_15 ) ;
return V_19 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_17 = V_6 -> V_18 ;
int V_19 ;
if ( V_6 -> V_20 -> V_21 & V_22 ||
V_6 -> V_20 -> V_21 & V_23 ) {
T_1 V_70 = V_46 | V_40 ;
if ( V_15 -> V_45 != V_71 )
return - V_72 ;
V_70 &= ( V_58 |
V_52 |
V_59 |
V_53 |
V_60 |
V_54 ) ;
F_10 ( & V_6 -> V_73 ) ;
if ( V_6 -> V_20 -> V_33 -> V_74 )
V_6 -> V_20 -> V_33 -> V_74 ( V_6 -> V_36 , 1 ,
V_6 -> V_20 -> V_75 , 0 ) ;
F_11 ( & V_6 -> V_73 ) ;
return 0 ;
}
F_10 ( & V_6 -> V_73 ) ;
V_19 = F_12 ( V_17 , V_15 ) ;
F_11 ( & V_6 -> V_73 ) ;
return V_19 ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_76 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_77 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_76 = V_77 ;
}
static int F_15 ( struct V_1 * V_2 )
{
if ( ! F_7 ( V_2 ) )
return - V_67 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return V_78 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_79 * V_80 , void * V_81 )
{
int V_82 ;
T_1 * V_83 = ( T_1 * ) V_81 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
memset ( V_83 , 0x0 , V_78 ) ;
if ( ! V_6 -> V_7 -> V_8 ) {
for ( V_82 = 0 ; V_82 < 12 ; V_82 ++ )
V_83 [ V_82 ] = F_18 ( V_6 -> V_36 + ( V_82 * 4 ) ) ;
for ( V_82 = 0 ; V_82 < 9 ; V_82 ++ )
V_83 [ V_82 + 12 ] =
F_18 ( V_6 -> V_36 + ( V_84 + ( V_82 * 4 ) ) ) ;
V_83 [ 22 ] = F_18 ( V_6 -> V_36 + V_85 ) ;
V_83 [ 23 ] = F_18 ( V_6 -> V_36 + V_86 ) ;
} else {
for ( V_82 = 0 ; V_82 < 55 ; V_82 ++ )
V_83 [ V_82 ] = F_18 ( V_6 -> V_36 + ( V_82 * 4 ) ) ;
for ( V_82 = 0 ; V_82 < 22 ; V_82 ++ )
V_83 [ V_82 + 55 ] =
F_18 ( V_6 -> V_36 + ( V_84 + ( V_82 * 4 ) ) ) ;
}
}
static void
F_19 ( struct V_1 * V_87 ,
struct V_88 * V_37 )
{
struct V_5 * V_6 = F_2 ( V_87 ) ;
V_37 -> V_89 = 0 ;
V_37 -> V_90 = 0 ;
if ( V_6 -> V_20 -> V_21 && V_6 -> V_20 -> V_33 -> V_34 ) {
struct V_24 V_91 ;
V_37 -> V_45 = 1 ;
V_6 -> V_20 -> V_33 -> V_34 ( V_6 -> V_36 , & V_91 ) ;
if ( ! V_91 . V_37 )
return;
} else {
if ( ! ( V_6 -> V_18 -> V_47 & V_92 ) ||
! ( V_6 -> V_18 -> V_47 & V_93 ) )
return;
}
V_37 -> V_45 = V_6 -> V_18 -> V_45 ;
if ( V_6 -> V_94 & V_95 )
V_37 -> V_89 = 1 ;
if ( V_6 -> V_94 & V_96 )
V_37 -> V_90 = 1 ;
}
static int
F_20 ( struct V_1 * V_87 ,
struct V_88 * V_37 )
{
struct V_5 * V_6 = F_2 ( V_87 ) ;
struct V_16 * V_17 = V_6 -> V_18 ;
int V_97 = V_98 ;
if ( V_6 -> V_20 -> V_21 && V_6 -> V_20 -> V_33 -> V_34 ) {
struct V_24 V_91 ;
V_37 -> V_45 = 1 ;
V_6 -> V_20 -> V_33 -> V_34 ( V_6 -> V_36 , & V_91 ) ;
if ( ! V_91 . V_37 )
return - V_35 ;
} else {
if ( ! ( V_17 -> V_47 & V_92 ) ||
! ( V_17 -> V_47 & V_93 ) )
return - V_35 ;
}
if ( V_37 -> V_89 )
V_97 |= V_95 ;
if ( V_37 -> V_90 )
V_97 |= V_96 ;
V_6 -> V_94 = V_97 ;
V_17 -> V_45 = V_37 -> V_45 ;
if ( V_17 -> V_45 ) {
if ( F_7 ( V_87 ) )
return F_21 ( V_17 ) ;
}
V_6 -> V_20 -> V_33 -> V_94 ( V_6 -> V_20 , V_17 -> V_29 , V_6 -> V_94 ,
V_6 -> V_37 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_99 * V_100 , T_2 * V_101 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_82 , V_102 = 0 ;
if ( V_6 -> V_20 -> V_103 -> V_104 )
V_6 -> V_20 -> V_103 -> V_104 ( & V_2 -> V_105 ,
( void * ) & V_6 -> V_26 ,
V_6 -> V_36 ) ;
else {
if ( V_6 -> V_106 . V_107 ) {
F_23 ( V_6 -> V_108 , & V_6 -> V_109 ) ;
for ( V_82 = 0 ; V_82 < V_110 ; V_82 ++ ) {
char * V_111 ;
V_111 = ( char * ) V_6 + V_112 [ V_82 ] . V_113 ;
V_101 [ V_102 ++ ] = ( V_112 [ V_82 ] . V_114 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_111 ) :
( * ( T_1 * ) V_111 ) ;
}
}
if ( V_6 -> V_115 ) {
int V_116 = F_24 ( V_6 -> V_18 ) ;
if ( V_116 )
V_6 -> V_26 . V_117 = V_116 ;
}
if ( ( V_6 -> V_20 -> V_33 -> V_118 ) &&
( V_6 -> V_119 >= V_120 ) )
V_6 -> V_20 -> V_33 -> V_118 ( V_6 -> V_36 ,
( void * ) & V_6 -> V_26 ) ;
}
for ( V_82 = 0 ; V_82 < V_121 ; V_82 ++ ) {
char * V_111 = ( char * ) V_6 + V_122 [ V_82 ] . V_113 ;
V_101 [ V_102 ++ ] = ( V_122 [ V_82 ] . V_114 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_111 ) : ( * ( T_1 * ) V_111 ) ;
}
}
static int F_25 ( struct V_1 * V_87 , int V_123 )
{
struct V_5 * V_6 = F_2 ( V_87 ) ;
int V_124 ;
switch ( V_123 ) {
case V_125 :
V_124 = V_121 ;
if ( V_6 -> V_106 . V_107 )
V_124 += V_110 ;
return V_124 ;
default:
return - V_35 ;
}
}
static void F_26 ( struct V_1 * V_2 , T_1 V_126 , T_3 * V_101 )
{
int V_82 ;
T_3 * V_111 = V_101 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_126 ) {
case V_125 :
if ( V_6 -> V_106 . V_107 )
for ( V_82 = 0 ; V_82 < V_110 ; V_82 ++ ) {
memcpy ( V_111 , V_112 [ V_82 ] . V_127 ,
V_128 ) ;
V_111 += V_128 ;
}
for ( V_82 = 0 ; V_82 < V_121 ; V_82 ++ ) {
memcpy ( V_111 , V_122 [ V_82 ] . V_127 ,
V_128 ) ;
V_111 += V_128 ;
}
break;
default:
F_27 ( 1 ) ;
break;
}
}
static void F_28 ( struct V_1 * V_2 , struct V_129 * V_130 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_29 ( & V_6 -> V_73 ) ;
if ( F_30 ( V_6 -> V_131 ) ) {
V_130 -> V_47 = V_132 | V_133 ;
V_130 -> V_134 = V_6 -> V_134 ;
}
F_31 ( & V_6 -> V_73 ) ;
}
static int F_32 ( struct V_1 * V_2 , struct V_129 * V_130 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_135 = V_132 | V_133 ;
if ( ( V_6 -> V_136 ) && ( ! V_6 -> V_106 . V_137 ) )
V_130 -> V_134 &= ~ V_132 ;
if ( ! F_30 ( V_6 -> V_131 ) )
return - V_72 ;
if ( V_130 -> V_134 & ~ V_135 )
return - V_72 ;
if ( V_130 -> V_134 ) {
F_33 ( L_4 ) ;
F_34 ( V_6 -> V_131 , 1 ) ;
F_35 ( V_6 -> V_138 ) ;
} else {
F_34 ( V_6 -> V_131 , 0 ) ;
F_36 ( V_6 -> V_138 ) ;
}
F_29 ( & V_6 -> V_73 ) ;
V_6 -> V_134 = V_130 -> V_134 ;
F_31 ( & V_6 -> V_73 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_139 * V_140 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_106 . V_141 )
return - V_35 ;
V_140 -> V_115 = V_6 -> V_115 ;
V_140 -> V_142 = V_6 -> V_142 ;
V_140 -> V_143 = V_6 -> V_143 ;
return F_38 ( V_6 -> V_18 , V_140 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_139 * V_140 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_115 = V_140 -> V_115 ;
if ( ! V_6 -> V_115 )
F_40 ( V_6 ) ;
else {
V_6 -> V_115 = F_41 ( V_6 ) ;
if ( ! V_6 -> V_115 )
return - V_35 ;
V_6 -> V_143 = V_140 -> V_143 ;
}
return F_42 ( V_6 -> V_18 , V_140 ) ;
}
static T_1 F_43 ( T_1 V_144 , struct V_5 * V_6 )
{
unsigned long V_145 = F_44 ( V_6 -> V_146 ) ;
if ( ! V_145 )
return 0 ;
return ( V_144 * ( V_145 / 1000000 ) ) / 256 ;
}
static T_1 F_45 ( T_1 V_147 , struct V_5 * V_6 )
{
unsigned long V_145 = F_44 ( V_6 -> V_146 ) ;
if ( ! V_145 )
return 0 ;
return ( V_147 * 256 ) / ( V_145 / 1000000 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_149 -> V_150 = V_6 -> V_151 ;
V_149 -> V_152 = V_6 -> V_153 ;
if ( V_6 -> V_154 )
V_149 -> V_155 = F_45 ( V_6 -> V_156 , V_6 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_148 * V_149 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_156 ;
if ( ( V_149 -> V_157 ) || ( V_149 -> V_158 ) ||
( V_149 -> V_159 ) || ( V_149 -> V_160 ) ||
( V_149 -> V_161 ) || ( V_149 -> V_162 ) ||
( V_149 -> V_163 ) || ( V_149 -> V_164 ) ||
( V_149 -> V_165 ) || ( V_149 -> V_166 ) ||
( V_149 -> V_167 ) || ( V_149 -> V_168 ) ||
( V_149 -> V_169 ) || ( V_149 -> V_170 ) ||
( V_149 -> V_171 ) ||
( V_149 -> V_172 ) ||
( V_149 -> V_173 ) ||
( V_149 -> V_174 ) || ( V_149 -> V_175 ) )
return - V_35 ;
if ( V_149 -> V_155 == 0 )
return - V_72 ;
if ( ( V_149 -> V_150 == 0 ) &&
( V_149 -> V_152 == 0 ) )
return - V_72 ;
if ( ( V_149 -> V_150 > V_176 ) ||
( V_149 -> V_152 > V_177 ) )
return - V_72 ;
V_156 = F_43 ( V_149 -> V_155 , V_6 ) ;
if ( ( V_156 > V_178 ) || ( V_156 < V_179 ) )
return - V_72 ;
else if ( ! V_6 -> V_154 )
return - V_35 ;
V_6 -> V_153 = V_149 -> V_152 ;
V_6 -> V_151 = V_149 -> V_150 ;
V_6 -> V_156 = V_156 ;
V_6 -> V_20 -> V_103 -> V_180 ( V_6 -> V_36 , V_6 -> V_156 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_181 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_6 -> V_106 . V_182 || V_6 -> V_106 . V_183 ) ) {
V_4 -> V_184 = V_185 |
V_186 |
V_187 |
V_188 |
V_189 |
V_190 ;
if ( V_6 -> V_191 )
V_4 -> V_192 = F_49 ( V_6 -> V_191 ) ;
V_4 -> V_193 = ( 1 << V_194 ) | ( 1 << V_195 ) ;
V_4 -> V_196 = ( ( 1 << V_197 ) |
( 1 << V_198 ) |
( 1 << V_199 ) |
( 1 << V_200 ) |
( 1 << V_201 ) |
( 1 << V_202 ) |
( 1 << V_203 ) |
( 1 << V_204 ) |
( 1 << V_205 ) |
( 1 << V_206 ) |
( 1 << V_207 ) ) ;
return 0 ;
} else
return F_50 ( V_2 , V_4 ) ;
}
static int F_51 ( struct V_1 * V_2 ,
const struct V_208 * V_209 , void * V_101 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_210 = 0 ;
switch ( V_209 -> V_211 ) {
case V_212 :
* ( T_1 * ) V_101 = V_6 -> V_213 ;
break;
default:
V_210 = - V_72 ;
break;
}
return V_210 ;
}
static int F_52 ( struct V_1 * V_2 ,
const struct V_208 * V_209 ,
const void * V_101 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_210 = 0 ;
switch ( V_209 -> V_211 ) {
case V_212 :
V_6 -> V_213 = * ( T_1 * ) V_101 ;
break;
default:
V_210 = - V_72 ;
break;
}
return V_210 ;
}
void F_53 ( struct V_1 * V_87 )
{
V_87 -> V_214 = & V_215 ;
}
