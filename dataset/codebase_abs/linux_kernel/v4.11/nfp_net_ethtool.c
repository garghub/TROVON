static void F_1 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 ;
if ( ! V_2 -> V_6 )
return;
V_5 = F_2 ( V_2 -> V_6 ) ;
if ( F_3 ( V_5 ) )
return;
snprintf ( V_3 , V_7 , L_1 ,
F_4 ( V_5 ) ,
F_5 ( V_5 ) ) ;
F_6 ( V_5 ) ;
}
static void F_7 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
char V_12 [ V_7 ] = {} ;
struct V_1 * V_2 = F_8 ( V_9 ) ;
F_9 ( V_11 -> V_13 , V_2 -> V_14 -> V_13 -> V_15 ,
sizeof( V_11 -> V_13 ) ) ;
F_9 ( V_11 -> V_3 , V_16 , sizeof( V_11 -> V_3 ) ) ;
F_1 ( V_2 , V_12 ) ;
snprintf ( V_11 -> V_17 , sizeof( V_11 -> V_17 ) ,
L_2 ,
V_2 -> V_18 . V_19 , V_2 -> V_18 . V_20 ,
V_2 -> V_18 . V_21 , V_2 -> V_18 . V_22 , V_12 ) ;
F_9 ( V_11 -> V_23 , F_10 ( V_2 -> V_14 ) ,
sizeof( V_11 -> V_23 ) ) ;
V_11 -> V_24 = V_25 ;
V_11 -> V_26 = V_27 ;
}
static void F_11 ( struct V_8 * V_9 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
V_29 -> V_30 = V_31 ;
V_29 -> V_32 = V_33 ;
V_29 -> V_34 = V_2 -> V_35 ;
V_29 -> V_36 = V_2 -> V_37 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_35 , T_1 V_37 )
{
struct V_38 * V_39 = NULL , * V_40 = NULL ;
struct V_38 V_41 = {
. V_42 = V_2 -> V_43 ,
. V_44 = V_2 -> V_9 -> V_44 ,
. V_45 = V_35 ,
} ;
struct V_38 V_46 = {
. V_42 = V_2 -> V_47 ,
. V_45 = V_37 ,
} ;
if ( V_2 -> V_35 != V_35 )
V_39 = & V_41 ;
if ( V_2 -> V_37 != V_37 )
V_40 = & V_46 ;
return F_13 ( V_2 , & V_2 -> V_48 ,
V_39 , V_40 ) ;
}
static int F_14 ( struct V_8 * V_9 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
T_1 V_35 , V_37 ;
if ( V_29 -> V_49 || V_29 -> V_50 )
return - V_51 ;
V_35 = F_15 ( V_29 -> V_34 ) ;
V_37 = F_15 ( V_29 -> V_36 ) ;
if ( V_35 < V_52 || V_35 > V_31 ||
V_37 < V_53 || V_37 > V_33 )
return - V_51 ;
if ( V_2 -> V_35 == V_35 && V_2 -> V_37 == V_37 )
return 0 ;
F_16 ( V_2 , L_3 ,
V_2 -> V_35 , V_35 , V_2 -> V_37 , V_37 ) ;
return F_12 ( V_2 , V_35 , V_37 ) ;
}
static void F_17 ( struct V_8 * V_9 ,
T_1 V_54 , T_2 * V_55 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
T_2 * V_56 = V_55 ;
int V_57 ;
switch ( V_54 ) {
case V_58 :
for ( V_57 = 0 ; V_57 < V_59 ; V_57 ++ ) {
memcpy ( V_56 , V_60 [ V_57 ] . V_15 , V_61 ) ;
V_56 += V_61 ;
}
for ( V_57 = 0 ; V_57 < V_2 -> V_62 ; V_57 ++ ) {
sprintf ( V_56 , L_4 , V_57 ) ;
V_56 += V_61 ;
sprintf ( V_56 , L_5 , V_57 ) ;
V_56 += V_61 ;
sprintf ( V_56 , L_6 , V_57 ) ;
V_56 += V_61 ;
}
strncpy ( V_56 , L_7 , V_61 ) ;
V_56 += V_61 ;
strncpy ( V_56 , L_8 , V_61 ) ;
V_56 += V_61 ;
strncpy ( V_56 , L_9 , V_61 ) ;
V_56 += V_61 ;
strncpy ( V_56 , L_10 , V_61 ) ;
V_56 += V_61 ;
strncpy ( V_56 , L_11 , V_61 ) ;
V_56 += V_61 ;
strncpy ( V_56 , L_12 , V_61 ) ;
V_56 += V_61 ;
strncpy ( V_56 , L_13 , V_61 ) ;
V_56 += V_61 ;
for ( V_57 = 0 ; V_57 < V_2 -> V_47 ; V_57 ++ ) {
sprintf ( V_56 , L_14 , V_57 ) ;
V_56 += V_61 ;
sprintf ( V_56 , L_15 , V_57 ) ;
V_56 += V_61 ;
}
for ( V_57 = 0 ; V_57 < V_2 -> V_43 ; V_57 ++ ) {
sprintf ( V_56 , L_16 , V_57 ) ;
V_56 += V_61 ;
sprintf ( V_56 , L_17 , V_57 ) ;
V_56 += V_61 ;
}
break;
}
}
static void F_18 ( struct V_8 * V_9 ,
struct V_63 * V_64 , T_3 * V_55 )
{
T_3 V_65 [ V_66 ] = {} ;
struct V_1 * V_2 = F_8 ( V_9 ) ;
struct V_67 * V_68 ;
struct V_67 V_69 = {} ;
T_3 V_70 [ V_66 ] ;
T_2 T_4 * V_71 ;
int V_57 , V_72 , V_73 ;
T_2 * V_56 ;
V_68 = F_19 ( V_9 , & V_69 ) ;
for ( V_57 = 0 ; V_57 < V_59 ; V_57 ++ ) {
switch ( V_60 [ V_57 ] . type ) {
case V_74 :
V_56 = ( char * ) V_68 + V_60 [ V_57 ] . V_75 ;
V_55 [ V_57 ] = V_60 [ V_57 ] . V_76 == sizeof( T_3 ) ?
* ( T_3 * ) V_56 : * ( T_1 * ) V_56 ;
break;
case V_77 :
V_71 = V_2 -> V_78 + V_60 [ V_57 ] . V_75 ;
V_55 [ V_57 ] = F_20 ( V_71 ) ;
break;
}
}
for ( V_72 = 0 ; V_72 < V_2 -> V_62 ; V_72 ++ ) {
unsigned int V_79 ;
do {
V_79 = F_21 ( & V_2 -> V_80 [ V_72 ] . V_81 ) ;
V_55 [ V_57 ++ ] = V_2 -> V_80 [ V_72 ] . V_82 ;
V_70 [ 0 ] = V_2 -> V_80 [ V_72 ] . V_83 ;
V_70 [ 1 ] = V_2 -> V_80 [ V_72 ] . V_84 ;
V_70 [ 2 ] = V_2 -> V_80 [ V_72 ] . V_85 ;
} while ( F_22 ( & V_2 -> V_80 [ V_72 ] . V_81 , V_79 ) );
do {
V_79 = F_21 ( & V_2 -> V_80 [ V_72 ] . V_86 ) ;
V_55 [ V_57 ++ ] = V_2 -> V_80 [ V_72 ] . V_87 ;
V_55 [ V_57 ++ ] = V_2 -> V_80 [ V_72 ] . V_88 ;
V_70 [ 3 ] = V_2 -> V_80 [ V_72 ] . V_89 ;
V_70 [ 4 ] = V_2 -> V_80 [ V_72 ] . V_90 ;
V_70 [ 5 ] = V_2 -> V_80 [ V_72 ] . V_91 ;
V_70 [ 6 ] = V_2 -> V_80 [ V_72 ] . V_92 ;
} while ( F_22 ( & V_2 -> V_80 [ V_72 ] . V_86 , V_79 ) );
for ( V_73 = 0 ; V_73 < V_66 ; V_73 ++ )
V_65 [ V_73 ] += V_70 [ V_73 ] ;
}
for ( V_72 = 0 ; V_72 < V_66 ; V_72 ++ )
V_55 [ V_57 ++ ] = V_65 [ V_72 ] ;
for ( V_72 = 0 ; V_72 < V_2 -> V_47 ; V_72 ++ ) {
V_71 = V_2 -> V_78 + F_23 ( V_72 ) ;
V_55 [ V_57 ++ ] = F_20 ( V_71 ) ;
V_71 = V_2 -> V_78 + F_23 ( V_72 ) + 8 ;
V_55 [ V_57 ++ ] = F_20 ( V_71 ) ;
}
for ( V_72 = 0 ; V_72 < V_2 -> V_43 ; V_72 ++ ) {
V_71 = V_2 -> V_78 + F_24 ( V_72 ) ;
V_55 [ V_57 ++ ] = F_20 ( V_71 ) ;
V_71 = V_2 -> V_78 + F_24 ( V_72 ) + 8 ;
V_55 [ V_57 ++ ] = F_20 ( V_71 ) ;
}
}
static int F_25 ( struct V_8 * V_9 , int V_93 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
switch ( V_93 ) {
case V_58 :
return V_25 ;
default:
return - V_94 ;
}
}
static T_1 F_26 ( T_1 V_95 )
{
static const T_1 V_96 [ V_97 + 1 ] = {
[ V_98 ] = V_99 ,
[ V_100 ] = V_101 ,
[ V_102 ] = V_103 ,
[ V_104 ] = V_105 ,
[ V_106 ] = V_107 ,
[ V_97 ] = V_108 ,
} ;
if ( V_95 >= F_27 ( V_96 ) )
return 0 ;
return V_96 [ V_95 ] ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_109 * V_110 )
{
T_1 V_111 ;
V_110 -> V_55 = 0 ;
if ( ! ( V_2 -> V_112 & V_113 ) )
return - V_94 ;
V_111 = F_26 ( V_110 -> V_95 ) ;
if ( ! V_111 )
return - V_51 ;
V_110 -> V_55 |= V_114 | V_115 ;
if ( V_2 -> V_116 & V_111 )
V_110 -> V_55 |= V_117 | V_118 ;
return 0 ;
}
static int F_29 ( struct V_8 * V_9 ,
struct V_109 * V_110 , T_1 * V_119 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
switch ( V_110 -> V_110 ) {
case V_120 :
V_110 -> V_55 = V_2 -> V_43 ;
return 0 ;
case V_121 :
return F_28 ( V_2 , V_110 ) ;
default:
return - V_94 ;
}
}
static int F_30 ( struct V_1 * V_2 ,
struct V_109 * V_122 )
{
T_1 V_123 = V_2 -> V_116 ;
T_1 V_111 ;
int V_124 ;
if ( ! ( V_2 -> V_112 & V_113 ) )
return - V_94 ;
if ( V_122 -> V_55 & ~ ( V_114 | V_115 |
V_117 | V_118 ) )
return - V_51 ;
if ( ! ( V_122 -> V_55 & V_114 ) ||
! ( V_122 -> V_55 & V_115 ) )
return - V_51 ;
V_111 = F_26 ( V_122 -> V_95 ) ;
if ( ! V_111 )
return - V_51 ;
switch ( V_122 -> V_55 & ( V_117 | V_118 ) ) {
case 0 :
V_123 &= ~ V_111 ;
break;
case ( V_117 | V_118 ) :
V_123 |= V_111 ;
break;
default:
return - V_51 ;
}
V_123 |= V_125 ;
V_123 |= V_126 ;
if ( V_123 == V_2 -> V_116 )
return 0 ;
F_31 ( V_123 , V_2 -> V_78 + V_127 ) ;
V_124 = F_32 ( V_2 , V_128 ) ;
if ( V_124 )
return V_124 ;
V_2 -> V_116 = V_123 ;
F_16 ( V_2 , L_18 , V_2 -> V_116 ) ;
return 0 ;
}
static int F_33 ( struct V_8 * V_9 ,
struct V_109 * V_110 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
switch ( V_110 -> V_110 ) {
case V_129 :
return F_30 ( V_2 , V_110 ) ;
default:
return - V_94 ;
}
}
static T_1 F_34 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
if ( ! ( V_2 -> V_112 & V_113 ) )
return 0 ;
return F_27 ( V_2 -> V_130 ) ;
}
static T_1 F_35 ( struct V_8 * V_9 )
{
return V_131 ;
}
static int F_36 ( struct V_8 * V_9 , T_1 * V_132 , T_2 * V_133 ,
T_2 * V_134 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
int V_57 ;
if ( ! ( V_2 -> V_112 & V_113 ) )
return - V_94 ;
if ( V_132 )
for ( V_57 = 0 ; V_57 < F_27 ( V_2 -> V_130 ) ; V_57 ++ )
V_132 [ V_57 ] = V_2 -> V_130 [ V_57 ] ;
if ( V_133 )
memcpy ( V_133 , V_2 -> V_135 , V_131 ) ;
if ( V_134 )
* V_134 = V_136 ;
return 0 ;
}
static int F_37 ( struct V_8 * V_9 ,
const T_1 * V_132 , const T_2 * V_133 ,
const T_2 V_134 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
int V_57 ;
if ( ! ( V_2 -> V_112 & V_113 ) ||
! ( V_134 == V_137 || V_134 == V_136 ) )
return - V_94 ;
if ( ! V_133 && ! V_132 )
return 0 ;
if ( V_133 ) {
memcpy ( V_2 -> V_135 , V_133 , V_131 ) ;
F_38 ( V_2 ) ;
}
if ( V_132 ) {
for ( V_57 = 0 ; V_57 < F_27 ( V_2 -> V_130 ) ; V_57 ++ )
V_2 -> V_130 [ V_57 ] = V_132 [ V_57 ] ;
F_39 ( V_2 ) ;
}
return F_32 ( V_2 , V_128 ) ;
}
static int F_40 ( struct V_8 * V_9 )
{
return V_27 ;
}
static void F_41 ( struct V_8 * V_9 ,
struct V_138 * V_139 , void * V_56 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
T_1 * V_140 = V_56 ;
int V_57 ;
V_139 -> V_3 = F_42 ( V_2 , V_141 ) ;
for ( V_57 = 0 ; V_57 < V_27 / sizeof( T_1 ) ; V_57 ++ )
V_140 [ V_57 ] = F_43 ( V_2 -> V_78 + ( V_57 * sizeof( T_1 ) ) ) ;
}
static int F_44 ( struct V_8 * V_9 ,
struct V_142 * V_143 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
if ( ! ( V_2 -> V_112 & V_144 ) )
return - V_51 ;
V_143 -> V_145 = V_2 -> V_145 ;
V_143 -> V_146 = V_2 -> V_147 ;
V_143 -> V_148 = V_2 -> V_148 ;
V_143 -> V_149 = V_2 -> V_150 ;
return 0 ;
}
static int
F_45 ( struct V_1 * V_2 , struct V_151 * V_152 , void * V_153 )
{
struct V_154 * V_155 ;
int V_156 ;
if ( ! V_2 -> V_6 )
return - V_94 ;
V_152 -> V_3 = 1 ;
V_152 -> V_157 = V_158 ;
V_155 = F_46 ( V_2 -> V_6 , V_159 ) ;
if ( F_3 ( V_155 ) )
return F_47 ( V_155 ) ;
if ( V_153 ) {
if ( V_152 -> V_160 != F_48 ( V_155 ) ) {
V_156 = - V_51 ;
goto V_161;
}
V_156 = F_49 ( V_2 -> V_6 , F_50 ( V_155 ) ,
F_51 ( V_155 ) ,
V_153 , V_152 -> V_160 ) ;
if ( V_156 != V_152 -> V_160 )
V_156 = V_156 < 0 ? V_156 : - V_162 ;
else
V_156 = 0 ;
} else {
V_152 -> V_160 = F_48 ( V_155 ) ;
V_156 = 0 ;
}
V_161:
F_52 ( V_155 ) ;
return V_156 ;
}
static int F_53 ( struct V_8 * V_9 , struct V_151 * V_163 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
if ( ! V_2 -> V_6 )
return - V_94 ;
if ( V_163 -> V_157 != V_158 )
return - V_51 ;
V_2 -> V_164 = V_163 -> V_157 ;
return 0 ;
}
static int
F_54 ( struct V_8 * V_9 , struct V_151 * V_152 )
{
return F_45 ( F_8 ( V_9 ) , V_152 , NULL ) ;
}
static int
F_55 ( struct V_8 * V_9 , struct V_151 * V_152 ,
void * V_153 )
{
return F_45 ( F_8 ( V_9 ) , V_152 , V_153 ) ;
}
static int F_56 ( struct V_8 * V_9 ,
struct V_142 * V_143 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
unsigned int V_165 ;
if ( V_143 -> V_166 ||
V_143 -> V_167 ||
V_143 -> V_168 ||
V_143 -> V_169 ||
V_143 -> V_170 ||
V_143 -> V_171 ||
V_143 -> V_172 ||
V_143 -> V_173 ||
V_143 -> V_174 ||
V_143 -> V_175 ||
V_143 -> V_176 ||
V_143 -> V_177 ||
V_143 -> V_178 ||
V_143 -> V_179 ||
V_143 -> V_180 ||
V_143 -> V_181 ||
V_143 -> V_182 ||
V_143 -> V_183 )
return - V_184 ;
V_165 = V_2 -> V_185 / 16 ;
if ( ! ( V_2 -> V_112 & V_144 ) )
return - V_51 ;
if ( ! V_143 -> V_145 && ! V_143 -> V_146 )
return - V_51 ;
if ( ! V_143 -> V_148 && ! V_143 -> V_149 )
return - V_51 ;
if ( V_143 -> V_145 * V_165 >= ( ( 1 << 16 ) - 1 ) )
return - V_51 ;
if ( V_143 -> V_148 * V_165 >= ( ( 1 << 16 ) - 1 ) )
return - V_51 ;
if ( V_143 -> V_146 >= ( ( 1 << 16 ) - 1 ) )
return - V_51 ;
if ( V_143 -> V_149 >= ( ( 1 << 16 ) - 1 ) )
return - V_51 ;
V_2 -> V_145 = V_143 -> V_145 ;
V_2 -> V_147 = V_143 -> V_146 ;
V_2 -> V_148 = V_143 -> V_148 ;
V_2 -> V_150 = V_143 -> V_149 ;
F_57 ( V_2 ) ;
return F_32 ( V_2 , V_186 ) ;
}
static void F_58 ( struct V_8 * V_9 ,
struct V_187 * V_188 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
unsigned int V_47 ;
V_47 = V_2 -> V_47 ;
if ( V_2 -> V_48 )
V_47 -= V_2 -> V_43 ;
V_188 -> V_189 = F_59 ( V_2 -> V_190 , V_2 -> V_191 ) ;
V_188 -> V_192 = F_59 ( V_2 -> V_193 , V_2 -> V_191 ) ;
V_188 -> V_194 = F_59 ( V_188 -> V_189 , V_188 -> V_192 ) ;
V_188 -> V_195 = V_196 ;
V_188 -> V_197 = F_59 ( V_2 -> V_43 , V_47 ) ;
V_188 -> V_198 = V_2 -> V_43 - V_188 -> V_197 ;
V_188 -> V_199 = V_47 - V_188 -> V_197 ;
V_188 -> V_200 = V_196 ;
}
static int F_60 ( struct V_1 * V_2 , unsigned int V_201 ,
unsigned int V_202 )
{
struct V_38 * V_39 = NULL , * V_40 = NULL ;
struct V_38 V_41 = {
. V_42 = V_201 ,
. V_44 = V_2 -> V_9 -> V_44 ,
. V_45 = V_2 -> V_35 ,
} ;
struct V_38 V_46 = {
. V_42 = V_202 ,
. V_45 = V_2 -> V_37 ,
} ;
if ( V_2 -> V_43 != V_201 )
V_39 = & V_41 ;
if ( V_2 -> V_203 != V_202 ||
( V_2 -> V_48 && V_39 ) )
V_40 = & V_46 ;
if ( V_2 -> V_48 )
V_46 . V_42 += V_201 ;
return F_13 ( V_2 , & V_2 -> V_48 ,
V_39 , V_40 ) ;
}
static int F_61 ( struct V_8 * V_9 ,
struct V_187 * V_188 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
unsigned int V_201 , V_202 ;
if ( ! V_188 -> V_197 ||
V_188 -> V_200 != V_196 ||
( V_188 -> V_198 && V_188 -> V_199 ) )
return - V_51 ;
V_201 = V_188 -> V_197 + V_188 -> V_198 ;
V_202 = V_188 -> V_197 + V_188 -> V_199 ;
if ( V_201 > F_59 ( V_2 -> V_190 , V_2 -> V_191 ) ||
V_202 > F_59 ( V_2 -> V_193 , V_2 -> V_191 ) )
return - V_51 ;
return F_60 ( V_2 , V_201 , V_202 ) ;
}
void F_62 ( struct V_8 * V_9 )
{
V_9 -> V_204 = & V_205 ;
}
