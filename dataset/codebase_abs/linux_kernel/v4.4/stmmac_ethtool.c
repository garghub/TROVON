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
if ( ! V_6 -> V_7 -> V_8 )
V_6 -> V_32 -> V_100 -> V_101 ( & V_2 -> V_102 ,
( void * ) & V_6 -> V_25 ,
V_6 -> V_82 ) ;
else {
if ( V_6 -> V_103 . V_104 ) {
F_23 ( V_6 -> V_82 , & V_6 -> V_105 ) ;
for ( V_80 = 0 ; V_80 < V_106 ; V_80 ++ ) {
char * V_107 ;
V_107 = ( char * ) V_6 + V_108 [ V_80 ] . V_109 ;
V_98 [ V_99 ++ ] = ( V_108 [ V_80 ] . V_110 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_107 ) :
( * ( T_1 * ) V_107 ) ;
}
}
if ( V_6 -> V_111 ) {
int V_112 = F_24 ( V_6 -> V_18 ) ;
if ( V_112 )
V_6 -> V_25 . V_113 = V_112 ;
}
}
for ( V_80 = 0 ; V_80 < V_114 ; V_80 ++ ) {
char * V_107 = ( char * ) V_6 + V_115 [ V_80 ] . V_109 ;
V_98 [ V_99 ++ ] = ( V_115 [ V_80 ] . V_110 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_107 ) : ( * ( T_1 * ) V_107 ) ;
}
}
static int F_25 ( struct V_1 * V_86 , int V_116 )
{
struct V_5 * V_6 = F_2 ( V_86 ) ;
int V_117 ;
switch ( V_116 ) {
case V_118 :
V_117 = V_114 ;
if ( V_6 -> V_103 . V_104 )
V_117 += V_106 ;
return V_117 ;
default:
return - V_35 ;
}
}
static void F_26 ( struct V_1 * V_2 , T_1 V_119 , T_3 * V_98 )
{
int V_80 ;
T_3 * V_107 = V_98 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_119 ) {
case V_118 :
if ( V_6 -> V_103 . V_104 )
for ( V_80 = 0 ; V_80 < V_106 ; V_80 ++ ) {
memcpy ( V_107 , V_108 [ V_80 ] . V_120 ,
V_121 ) ;
V_107 += V_121 ;
}
for ( V_80 = 0 ; V_80 < V_114 ; V_80 ++ ) {
memcpy ( V_107 , V_115 [ V_80 ] . V_120 ,
V_121 ) ;
V_107 += V_121 ;
}
break;
default:
F_27 ( 1 ) ;
break;
}
}
static void F_28 ( struct V_1 * V_2 , struct V_122 * V_123 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_29 ( & V_6 -> V_72 ) ;
if ( F_30 ( V_6 -> V_124 ) ) {
V_123 -> V_46 = V_125 | V_126 ;
V_123 -> V_127 = V_6 -> V_127 ;
}
F_31 ( & V_6 -> V_72 ) ;
}
static int F_32 ( struct V_1 * V_2 , struct V_122 * V_123 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_128 = V_125 | V_126 ;
if ( ( V_6 -> V_129 ) && ( ! V_6 -> V_103 . V_130 ) )
V_123 -> V_127 &= ~ V_125 ;
if ( ! F_30 ( V_6 -> V_124 ) )
return - V_71 ;
if ( V_123 -> V_127 & ~ V_128 )
return - V_71 ;
if ( V_123 -> V_127 ) {
F_33 ( L_4 ) ;
F_34 ( V_6 -> V_124 , 1 ) ;
F_35 ( V_6 -> V_131 ) ;
} else {
F_34 ( V_6 -> V_124 , 0 ) ;
F_36 ( V_6 -> V_131 ) ;
}
F_29 ( & V_6 -> V_72 ) ;
V_6 -> V_127 = V_123 -> V_127 ;
F_31 ( & V_6 -> V_72 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_132 * V_133 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_103 . V_134 )
return - V_35 ;
V_133 -> V_111 = V_6 -> V_111 ;
V_133 -> V_135 = V_6 -> V_135 ;
V_133 -> V_136 = V_6 -> V_136 ;
return F_38 ( V_6 -> V_18 , V_133 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_132 * V_133 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_111 = V_133 -> V_111 ;
if ( ! V_6 -> V_111 )
F_40 ( V_6 ) ;
else {
V_6 -> V_111 = F_41 ( V_6 ) ;
if ( ! V_6 -> V_111 )
return - V_35 ;
V_6 -> V_136 = V_133 -> V_136 ;
}
return F_42 ( V_6 -> V_18 , V_133 ) ;
}
static T_1 F_43 ( T_1 V_137 , struct V_5 * V_6 )
{
unsigned long V_138 = F_44 ( V_6 -> V_139 ) ;
if ( ! V_138 )
return 0 ;
return ( V_137 * ( V_138 / 1000000 ) ) / 256 ;
}
static T_1 F_45 ( T_1 V_140 , struct V_5 * V_6 )
{
unsigned long V_138 = F_44 ( V_6 -> V_139 ) ;
if ( ! V_138 )
return 0 ;
return ( V_140 * 256 ) / ( V_138 / 1000000 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_141 * V_142 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_142 -> V_143 = V_6 -> V_144 ;
V_142 -> V_145 = V_6 -> V_146 ;
if ( V_6 -> V_147 )
V_142 -> V_148 = F_45 ( V_6 -> V_149 , V_6 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_141 * V_142 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_149 ;
if ( ( V_142 -> V_150 ) || ( V_142 -> V_151 ) ||
( V_142 -> V_152 ) || ( V_142 -> V_153 ) ||
( V_142 -> V_154 ) || ( V_142 -> V_155 ) ||
( V_142 -> V_156 ) || ( V_142 -> V_157 ) ||
( V_142 -> V_158 ) || ( V_142 -> V_159 ) ||
( V_142 -> V_160 ) || ( V_142 -> V_161 ) ||
( V_142 -> V_162 ) || ( V_142 -> V_163 ) ||
( V_142 -> V_164 ) ||
( V_142 -> V_165 ) ||
( V_142 -> V_166 ) ||
( V_142 -> V_167 ) || ( V_142 -> V_168 ) )
return - V_35 ;
if ( V_142 -> V_148 == 0 )
return - V_71 ;
if ( ( V_142 -> V_143 == 0 ) &&
( V_142 -> V_145 == 0 ) )
return - V_71 ;
if ( ( V_142 -> V_143 > V_169 ) ||
( V_142 -> V_145 > V_170 ) )
return - V_71 ;
V_149 = F_43 ( V_142 -> V_148 , V_6 ) ;
if ( ( V_149 > V_171 ) || ( V_149 < V_172 ) )
return - V_71 ;
else if ( ! V_6 -> V_147 )
return - V_35 ;
V_6 -> V_146 = V_142 -> V_145 ;
V_6 -> V_144 = V_142 -> V_143 ;
V_6 -> V_149 = V_149 ;
V_6 -> V_32 -> V_100 -> V_173 ( V_6 -> V_82 , V_6 -> V_149 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_174 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ( V_6 -> V_103 . V_175 || V_6 -> V_103 . V_176 ) ) {
V_4 -> V_177 = V_178 |
V_179 |
V_180 |
V_181 |
V_182 |
V_183 ;
if ( V_6 -> V_184 )
V_4 -> V_185 = F_49 ( V_6 -> V_184 ) ;
V_4 -> V_186 = ( 1 << V_187 ) | ( 1 << V_188 ) ;
V_4 -> V_189 = ( ( 1 << V_190 ) |
( 1 << V_191 ) |
( 1 << V_192 ) |
( 1 << V_193 ) |
( 1 << V_194 ) |
( 1 << V_195 ) |
( 1 << V_196 ) |
( 1 << V_197 ) |
( 1 << V_198 ) |
( 1 << V_199 ) |
( 1 << V_200 ) ) ;
return 0 ;
} else
return F_50 ( V_2 , V_4 ) ;
}
void F_51 ( struct V_1 * V_86 )
{
V_86 -> V_201 = & V_202 ;
}
