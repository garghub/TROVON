static int F_1 ( struct V_1 * T_1 V_2 )
{
return 0 ;
}
static void F_2 ( struct V_1 * T_1 V_2 )
{
}
int F_3 ( T_2 V_3 ,
int (* F_4)( struct V_1 * T_1 ) ,
void (* F_5)( struct V_1 * T_1 ) )
{
if ( V_3 == 0 )
goto V_4;
if ( V_5 . V_6 > V_3 )
return - V_7 ;
V_5 . V_6 = V_3 ;
V_4:
if ( F_4 != NULL )
V_5 . F_4 = F_4 ;
if ( F_5 != NULL )
V_5 . F_5 = F_5 ;
return 0 ;
}
int F_6 ( T_3 V_8 )
{
T_3 V_9 = V_8 & V_10 ;
int V_6 = 0 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ ) {
if ( V_9 & ( 1ULL << V_11 ) )
V_6 ++ ;
}
V_6 *= sizeof( T_3 ) ;
return V_6 ;
}
static int F_7 ( T_3 V_8 )
{
int V_12 = 0 ;
if ( V_8 & V_13 )
return 0 ;
if ( ! ( V_8 & V_14 ) )
return - 1 ;
if ( V_8 & V_15 )
V_12 += 1 ;
if ( V_8 & V_16 )
V_12 += 1 ;
if ( V_8 & V_17 )
V_12 += 1 ;
if ( V_8 & V_18 )
V_12 += 1 ;
return V_12 ;
}
static int F_8 ( T_3 V_8 )
{
int V_12 = 1 ;
if ( V_8 & V_13 )
return 1 ;
if ( ! ( V_8 & V_14 ) )
return - 1 ;
if ( V_8 & V_19 )
V_12 += 1 ;
if ( V_8 & V_20 )
V_12 += 1 ;
return V_12 ;
}
void F_9 ( struct V_1 * T_1 )
{
T_1 -> V_21 = F_7 ( T_1 -> V_22 . V_8 ) ;
T_1 -> V_23 = F_8 ( T_1 -> V_22 . V_8 ) ;
}
void F_10 ( struct V_1 * T_1 ,
enum V_24 V_25 )
{
if ( ! ( T_1 -> V_22 . V_8 & V_25 ) ) {
T_1 -> V_22 . V_8 |= V_25 ;
T_1 -> V_26 += sizeof( T_3 ) ;
F_9 ( T_1 ) ;
}
}
void F_11 ( struct V_1 * T_1 ,
enum V_24 V_25 )
{
if ( T_1 -> V_22 . V_8 & V_25 ) {
T_1 -> V_22 . V_8 &= ~ V_25 ;
T_1 -> V_26 -= sizeof( T_3 ) ;
F_9 ( T_1 ) ;
}
}
void F_12 ( struct V_1 * T_1 ,
bool V_27 )
{
if ( V_27 ) {
F_13 ( T_1 , V_28 ) ;
F_14 ( T_1 , V_29 ) ;
} else {
F_14 ( T_1 , V_28 ) ;
}
T_1 -> V_22 . V_30 |= V_31 ;
}
void F_15 ( struct V_1 * T_1 ,
struct V_32 * V_22 , int V_12 )
{
T_1 -> V_12 = V_12 ;
T_1 -> V_33 = ! V_12 ;
T_1 -> V_22 = * V_22 ;
T_1 -> V_34 = T_1 ;
T_1 -> V_35 = L_1 ;
T_1 -> V_36 = 1.0 ;
T_1 -> V_37 = NULL ;
T_1 -> V_38 = - 1 ;
F_16 ( & T_1 -> V_39 ) ;
F_16 ( & T_1 -> V_40 ) ;
V_5 . F_4 ( T_1 ) ;
T_1 -> V_26 = F_6 ( V_22 -> V_8 ) ;
F_9 ( T_1 ) ;
T_1 -> V_41 = false ;
}
struct V_1 * F_17 ( struct V_32 * V_22 , int V_12 )
{
struct V_1 * T_1 = F_18 ( V_5 . V_6 ) ;
if ( T_1 != NULL )
F_15 ( T_1 , V_22 , V_12 ) ;
return T_1 ;
}
struct V_1 * F_19 ( const char * V_42 , const char * V_43 , int V_12 )
{
struct V_1 * T_1 = F_18 ( V_5 . V_6 ) ;
int V_44 = - V_45 ;
if ( T_1 == NULL ) {
goto V_46;
} else {
struct V_32 V_22 = {
. type = V_47 ,
. V_8 = ( V_48 | V_17 |
V_19 | V_49 ) ,
} ;
if ( F_20 ( & T_1 -> V_43 , L_2 , V_42 , V_43 ) < 0 )
goto V_50;
T_1 -> V_51 = F_21 ( V_42 , V_43 ) ;
if ( F_22 ( T_1 -> V_51 ) ) {
V_44 = F_23 ( T_1 -> V_51 ) ;
goto V_50;
}
F_24 ( & V_22 ) ;
V_22 . V_52 = T_1 -> V_51 -> V_53 ;
V_22 . V_54 = 1 ;
F_15 ( T_1 , & V_22 , V_12 ) ;
}
return T_1 ;
V_50:
F_25 ( & T_1 -> V_43 ) ;
free ( T_1 ) ;
V_46:
return F_26 ( V_44 ) ;
}
static const char * F_27 ( T_3 V_52 )
{
if ( V_52 < V_55 && V_56 [ V_52 ] )
return V_56 [ V_52 ] ;
return L_3 ;
}
static int F_28 ( struct V_1 * T_1 , char * V_57 , T_2 V_6 )
{
int V_58 = 0 , V_59 = 0 ;
struct V_32 * V_22 = & T_1 -> V_22 ;
bool V_60 = false ;
#define F_29 ( T_4 , T_5 ) do { \
if (!attr->exclude_##context) { \
if (!colon) colon = ++r; \
r += scnprintf(bf + r, size - r, "%c", mod); \
} } while(0)
if ( V_22 -> V_61 || V_22 -> V_62 || V_22 -> V_63 ) {
F_29 ( V_64 , 'k' ) ;
F_29 ( V_65 , 'u' ) ;
F_29 ( V_66 , 'h' ) ;
V_60 = true ;
}
if ( V_22 -> V_67 ) {
if ( ! V_58 )
V_58 = ++ V_59 ;
V_59 += F_30 ( V_57 + V_59 , V_6 - V_59 , L_4 , V_22 -> V_67 , L_5 ) ;
V_60 = true ;
}
if ( V_22 -> V_68 || V_22 -> V_69 == V_60 ) {
F_29 ( V_70 , 'H' ) ;
F_29 ( V_71 , 'G' ) ;
}
#undef F_29
if ( V_58 )
V_57 [ V_58 - 1 ] = ':' ;
return V_59 ;
}
static int F_31 ( struct V_1 * T_1 , char * V_57 , T_2 V_6 )
{
int V_59 = F_30 ( V_57 , V_6 , L_6 , F_27 ( T_1 -> V_22 . V_52 ) ) ;
return V_59 + F_28 ( T_1 , V_57 + V_59 , V_6 - V_59 ) ;
}
static const char * F_32 ( T_3 V_52 )
{
if ( V_52 < V_72 && V_73 [ V_52 ] )
return V_73 [ V_52 ] ;
return L_7 ;
}
static int F_33 ( struct V_1 * T_1 , char * V_57 , T_2 V_6 )
{
int V_59 = F_30 ( V_57 , V_6 , L_6 , F_32 ( T_1 -> V_22 . V_52 ) ) ;
return V_59 + F_28 ( T_1 , V_57 + V_59 , V_6 - V_59 ) ;
}
static int F_34 ( char * V_57 , T_2 V_6 , T_3 V_74 , T_3 type )
{
int V_59 ;
V_59 = F_30 ( V_57 , V_6 , L_8 V_75 L_9 , V_74 ) ;
if ( type & V_76 )
V_59 += F_30 ( V_57 + V_59 , V_6 - V_59 , L_10 ) ;
if ( type & V_77 )
V_59 += F_30 ( V_57 + V_59 , V_6 - V_59 , L_11 ) ;
if ( type & V_78 )
V_59 += F_30 ( V_57 + V_59 , V_6 - V_59 , L_12 ) ;
return V_59 ;
}
static int F_35 ( struct V_1 * T_1 , char * V_57 , T_2 V_6 )
{
struct V_32 * V_22 = & T_1 -> V_22 ;
int V_59 = F_34 ( V_57 , V_6 , V_22 -> V_79 , V_22 -> V_80 ) ;
return V_59 + F_28 ( T_1 , V_57 + V_59 , V_6 - V_59 ) ;
}
bool F_36 ( T_6 type , T_6 V_81 )
{
if ( V_82 [ type ] & F_37 ( V_81 ) )
return true ;
else
return false ;
}
int F_38 ( T_6 type , T_6 V_81 , T_6 V_83 ,
char * V_57 , T_2 V_6 )
{
if ( V_83 ) {
return F_30 ( V_57 , V_6 , L_13 , V_84 [ type ] [ 0 ] ,
V_85 [ V_81 ] [ 0 ] ,
V_86 [ V_83 ] [ 0 ] ) ;
}
return F_30 ( V_57 , V_6 , L_14 , V_84 [ type ] [ 0 ] ,
V_85 [ V_81 ] [ 1 ] ) ;
}
static int F_39 ( T_3 V_52 , char * V_57 , T_2 V_6 )
{
T_6 V_81 , V_83 , type = ( V_52 >> 0 ) & 0xff ;
const char * V_44 = L_15 ;
if ( type > V_87 )
goto V_46;
V_81 = ( V_52 >> 8 ) & 0xff ;
V_44 = L_16 ;
if ( V_81 > V_88 )
goto V_46;
V_83 = ( V_52 >> 16 ) & 0xff ;
V_44 = L_17 ;
if ( V_83 > V_89 )
goto V_46;
V_44 = L_18 ;
if ( ! F_36 ( type , V_81 ) )
goto V_46;
return F_38 ( type , V_81 , V_83 , V_57 , V_6 ) ;
V_46:
return F_30 ( V_57 , V_6 , L_6 , V_44 ) ;
}
static int F_40 ( struct V_1 * T_1 , char * V_57 , T_2 V_6 )
{
int V_90 = F_39 ( T_1 -> V_22 . V_52 , V_57 , V_6 ) ;
return V_90 + F_28 ( T_1 , V_57 + V_90 , V_6 - V_90 ) ;
}
static int F_41 ( struct V_1 * T_1 , char * V_57 , T_2 V_6 )
{
int V_90 = F_30 ( V_57 , V_6 , L_19 V_75 , T_1 -> V_22 . V_52 ) ;
return V_90 + F_28 ( T_1 , V_57 + V_90 , V_6 - V_90 ) ;
}
const char * F_42 ( struct V_1 * T_1 )
{
char V_57 [ 128 ] ;
if ( T_1 -> V_43 )
return T_1 -> V_43 ;
switch ( T_1 -> V_22 . type ) {
case V_91 :
F_41 ( T_1 , V_57 , sizeof( V_57 ) ) ;
break;
case V_92 :
F_31 ( T_1 , V_57 , sizeof( V_57 ) ) ;
break;
case V_93 :
F_40 ( T_1 , V_57 , sizeof( V_57 ) ) ;
break;
case V_94 :
F_33 ( T_1 , V_57 , sizeof( V_57 ) ) ;
break;
case V_47 :
F_30 ( V_57 , sizeof( V_57 ) , L_6 , L_20 ) ;
break;
case V_95 :
F_35 ( T_1 , V_57 , sizeof( V_57 ) ) ;
break;
default:
F_30 ( V_57 , sizeof( V_57 ) , L_21 ,
T_1 -> V_22 . type ) ;
break;
}
T_1 -> V_43 = F_43 ( V_57 ) ;
return T_1 -> V_43 ? : L_22 ;
}
const char * F_44 ( struct V_1 * T_1 )
{
return T_1 -> V_96 ? : L_23 ;
}
int F_45 ( struct V_1 * T_1 , char * V_97 , T_2 V_6 )
{
int V_90 ;
struct V_1 * V_98 ;
const char * V_96 = F_44 ( T_1 ) ;
V_90 = F_30 ( V_97 , V_6 , L_6 , V_96 ) ;
V_90 += F_30 ( V_97 + V_90 , V_6 - V_90 , L_24 ,
F_42 ( T_1 ) ) ;
F_46 (pos, evsel)
V_90 += F_30 ( V_97 + V_90 , V_6 - V_90 , L_25 ,
F_42 ( V_98 ) ) ;
V_90 += F_30 ( V_97 + V_90 , V_6 - V_90 , L_26 ) ;
return V_90 ;
}
static void
F_47 ( struct V_1 * T_1 ,
struct V_99 * V_100 ,
struct V_101 * V_102 )
{
bool V_103 = F_48 ( T_1 ) ;
struct V_32 * V_22 = & T_1 -> V_22 ;
F_14 ( T_1 , V_104 ) ;
if ( V_102 -> V_105 == V_106 ) {
if ( ! V_100 -> V_107 ) {
if ( V_22 -> V_62 ) {
F_49 ( L_27
L_28
L_29 ) ;
} else {
F_14 ( T_1 , V_108 ) ;
V_22 -> V_109 = V_110 |
V_111 |
V_112 |
V_113 ;
}
} else
F_49 ( L_30
L_29 ) ;
}
if ( V_102 -> V_105 == V_114 ) {
if ( ! V_103 ) {
F_14 ( T_1 , V_115 ) ;
F_14 ( T_1 , V_116 ) ;
V_22 -> V_117 = V_118 ;
V_22 -> V_119 = V_102 -> V_120 ;
V_22 -> V_121 = 1 ;
} else {
F_50 ( L_31
L_32 ) ;
}
}
if ( V_103 ) {
F_50 ( L_33 ) ;
V_22 -> V_121 = 1 ;
}
}
static void
F_51 ( struct V_1 * T_1 ,
struct V_101 * V_102 )
{
struct V_32 * V_22 = & T_1 -> V_22 ;
F_13 ( T_1 , V_104 ) ;
if ( V_102 -> V_105 == V_106 ) {
F_13 ( T_1 , V_108 ) ;
V_22 -> V_109 &= ~ ( V_110 |
V_111 ) ;
}
if ( V_102 -> V_105 == V_114 ) {
F_13 ( T_1 , V_115 ) ;
F_13 ( T_1 , V_116 ) ;
}
}
static void F_52 ( struct V_1 * T_1 ,
struct V_99 * V_100 )
{
struct V_122 * V_123 ;
struct V_124 * V_40 = & T_1 -> V_40 ;
struct V_32 * V_22 = & T_1 -> V_22 ;
struct V_101 V_102 ;
T_7 V_120 = 0 ;
char * V_125 = NULL ;
V_102 . V_105 = V_101 . V_105 ;
F_53 (term, config_terms, list) {
switch ( V_123 -> type ) {
case V_126 :
V_22 -> V_54 = V_123 -> V_127 . V_128 ;
V_22 -> V_129 = 0 ;
break;
case V_130 :
V_22 -> V_131 = V_123 -> V_127 . V_129 ;
V_22 -> V_129 = 1 ;
break;
case V_132 :
if ( V_123 -> V_127 . time )
F_14 ( T_1 , TIME ) ;
else
F_13 ( T_1 , TIME ) ;
break;
case V_133 :
V_125 = V_123 -> V_127 . V_134 ;
break;
case V_135 :
V_120 = V_123 -> V_127 . V_136 ;
break;
case V_137 :
V_22 -> V_138 = V_123 -> V_127 . V_138 ? 1 : 0 ;
break;
default:
break;
}
}
if ( ( V_125 != NULL ) || ( V_120 > 0 ) ) {
if ( V_125 != NULL ) {
if ( ! strcmp ( V_125 , L_34 ) ) {
V_102 . V_139 = false ;
V_102 . V_105 = V_140 ;
} else {
V_102 . V_139 = true ;
if ( F_54 ( V_125 , & V_102 ) ) {
F_55 ( L_35
L_36 ,
T_1 -> V_43 ) ;
return;
}
}
}
if ( V_120 > 0 ) {
V_120 = F_56 ( V_120 , sizeof( T_3 ) ) ;
V_102 . V_120 = V_120 ;
}
if ( V_101 . V_139 )
F_51 ( T_1 , & V_101 ) ;
if ( V_102 . V_139 )
F_47 ( T_1 , V_100 , & V_102 ) ;
}
}
void F_57 ( struct V_1 * T_1 , struct V_99 * V_100 )
{
struct V_1 * V_34 = T_1 -> V_34 ;
struct V_32 * V_22 = & T_1 -> V_22 ;
int V_141 = T_1 -> V_33 ;
bool V_142 = V_100 -> V_143 . V_144 && ! V_100 -> V_143 . V_145 ;
V_22 -> V_146 = V_147 . V_146 ? 0 : 1 ;
V_22 -> V_138 = ! V_100 -> V_148 ;
F_14 ( T_1 , V_149 ) ;
F_14 ( T_1 , V_150 ) ;
if ( T_1 -> V_151 ) {
F_14 ( T_1 , V_152 ) ;
F_12 ( T_1 , false ) ;
if ( V_34 -> V_153 > 1 ) {
V_22 -> V_30 |= V_154 ;
V_22 -> V_138 = 0 ;
}
}
if ( ! V_22 -> V_54 || ( V_100 -> V_155 != V_156 ||
V_100 -> V_157 != V_158 ) ) {
if ( V_100 -> V_129 ) {
F_14 ( T_1 , V_159 ) ;
V_22 -> V_129 = 1 ;
V_22 -> V_131 = V_100 -> V_129 ;
} else {
V_22 -> V_54 = V_100 -> V_160 ;
}
}
if ( ( V_34 != T_1 ) && V_34 -> V_151 ) {
V_22 -> V_131 = 0 ;
V_22 -> V_54 = 0 ;
}
if ( V_100 -> V_161 )
V_22 -> V_131 = 0 ;
if ( V_100 -> V_162 )
V_22 -> V_162 = 1 ;
if ( V_100 -> V_163 ) {
F_14 ( T_1 , V_164 ) ;
V_22 -> V_165 = V_141 ;
}
if ( F_48 ( T_1 ) )
T_1 -> V_22 . V_121 = 1 ;
if ( V_101 . V_139 && ! T_1 -> V_166 )
F_47 ( T_1 , V_100 , & V_101 ) ;
if ( V_100 -> V_167 ) {
V_22 -> V_168 = V_100 -> V_167 ;
F_14 ( T_1 , V_169 ) ;
}
if ( F_58 ( & V_100 -> V_143 ) )
F_14 ( T_1 , V_170 ) ;
if ( V_100 -> V_128 )
F_14 ( T_1 , V_159 ) ;
if ( V_100 -> V_171 &&
( ! V_147 . V_146 &&
( ! V_100 -> V_148 || F_58 ( & V_100 -> V_143 ) || V_142 ||
V_100 -> V_172 ) ) )
F_14 ( T_1 , TIME ) ;
if ( V_100 -> V_173 && ! T_1 -> V_166 ) {
F_14 ( T_1 , TIME ) ;
F_14 ( T_1 , V_174 ) ;
F_14 ( T_1 , V_170 ) ;
}
if ( V_100 -> V_163 )
F_14 ( T_1 , V_175 ) ;
if ( V_100 -> V_176 ) {
V_22 -> V_177 = 0 ;
V_22 -> V_178 = 1 ;
}
if ( V_100 -> V_107 && ! T_1 -> V_166 ) {
F_14 ( T_1 , V_108 ) ;
V_22 -> V_109 = V_100 -> V_107 ;
}
if ( V_100 -> V_179 )
F_14 ( T_1 , V_180 ) ;
V_22 -> V_181 = V_141 ;
V_22 -> V_182 = V_141 ;
V_22 -> V_183 = V_141 && ! V_147 . V_183 ;
V_22 -> V_184 = V_141 ;
if ( V_100 -> V_185 )
V_22 -> V_186 = V_141 ;
if ( V_100 -> V_187 )
F_14 ( T_1 , V_188 ) ;
if ( V_100 -> V_189 ) {
T_1 -> V_22 . V_30 |=
V_190 |
V_191 ;
}
if ( F_59 ( T_1 ) )
V_22 -> V_192 = 1 ;
if ( F_60 ( & V_100 -> V_143 ) && F_59 ( T_1 ) &&
! V_100 -> V_193 )
V_22 -> V_194 = 1 ;
if ( T_1 -> V_195 ) {
V_22 -> V_192 = 0 ;
V_22 -> V_194 = 0 ;
}
V_196 = V_100 -> V_196 ;
if ( V_100 -> V_197 ) {
V_22 -> V_197 = 1 ;
V_22 -> V_196 = V_100 -> V_196 ;
}
if ( T_1 -> V_198 )
F_61 ( V_22 ) ;
F_52 ( T_1 , V_100 ) ;
}
static int F_62 ( struct V_1 * T_1 , int V_199 , int V_200 )
{
int V_201 , V_202 ;
if ( T_1 -> V_203 )
V_200 = 1 ;
T_1 -> V_204 = F_63 ( V_199 , V_200 , sizeof( int ) ) ;
if ( T_1 -> V_204 ) {
for ( V_201 = 0 ; V_201 < V_199 ; V_201 ++ ) {
for ( V_202 = 0 ; V_202 < V_200 ; V_202 ++ ) {
F_64 ( T_1 , V_201 , V_202 ) = - 1 ;
}
}
}
return T_1 -> V_204 != NULL ? 0 : - V_45 ;
}
static int F_65 ( struct V_1 * T_1 , int V_199 , int V_200 ,
int V_205 , void * V_206 )
{
int V_201 , V_202 ;
if ( T_1 -> V_203 )
V_200 = 1 ;
for ( V_201 = 0 ; V_201 < V_199 ; V_201 ++ ) {
for ( V_202 = 0 ; V_202 < V_200 ; V_202 ++ ) {
int V_204 = F_64 ( T_1 , V_201 , V_202 ) ,
V_44 = F_66 ( V_204 , V_205 , V_206 ) ;
if ( V_44 )
return V_44 ;
}
}
return 0 ;
}
int F_67 ( struct V_1 * T_1 , int V_199 , int V_200 ,
const char * V_207 )
{
return F_65 ( T_1 , V_199 , V_200 ,
V_208 ,
( void * ) V_207 ) ;
}
int F_68 ( struct V_1 * T_1 , const char * V_207 )
{
char * V_209 = F_43 ( V_207 ) ;
if ( V_209 != NULL ) {
free ( T_1 -> V_207 ) ;
T_1 -> V_207 = V_209 ;
return 0 ;
}
return - 1 ;
}
int F_69 ( struct V_1 * T_1 ,
const char * V_81 , const char * V_207 )
{
char * V_209 ;
if ( T_1 -> V_207 == NULL )
return F_68 ( T_1 , V_207 ) ;
if ( F_20 ( & V_209 , L_37 , T_1 -> V_207 , V_81 , V_207 ) > 0 ) {
free ( T_1 -> V_207 ) ;
T_1 -> V_207 = V_209 ;
return 0 ;
}
return - 1 ;
}
int F_70 ( struct V_1 * T_1 )
{
int V_200 = F_71 ( T_1 -> V_210 ) ;
int V_199 = F_72 ( T_1 -> V_211 ) ;
return F_65 ( T_1 , V_199 , V_200 ,
V_212 ,
0 ) ;
}
int F_73 ( struct V_1 * T_1 )
{
int V_200 = F_71 ( T_1 -> V_210 ) ;
int V_199 = F_72 ( T_1 -> V_211 ) ;
return F_65 ( T_1 , V_199 , V_200 ,
V_213 ,
0 ) ;
}
int F_74 ( struct V_1 * T_1 , int V_199 , int V_200 )
{
if ( V_199 == 0 || V_200 == 0 )
return 0 ;
if ( T_1 -> V_203 )
V_200 = 1 ;
T_1 -> V_214 = F_63 ( V_199 , V_200 , sizeof( struct V_215 ) ) ;
if ( T_1 -> V_214 == NULL )
return - V_45 ;
T_1 -> V_53 = F_18 ( V_199 * V_200 * sizeof( T_3 ) ) ;
if ( T_1 -> V_53 == NULL ) {
F_75 ( T_1 -> V_214 ) ;
T_1 -> V_214 = NULL ;
return - V_45 ;
}
return 0 ;
}
static void F_76 ( struct V_1 * T_1 )
{
F_75 ( T_1 -> V_204 ) ;
T_1 -> V_204 = NULL ;
}
static void F_77 ( struct V_1 * T_1 )
{
F_75 ( T_1 -> V_214 ) ;
T_1 -> V_214 = NULL ;
F_25 ( & T_1 -> V_53 ) ;
}
static void F_78 ( struct V_1 * T_1 )
{
struct V_122 * V_123 , * V_216 ;
F_79 (term, h, &evsel->config_terms, list) {
F_80 ( & V_123 -> V_217 ) ;
free ( V_123 ) ;
}
}
void F_81 ( struct V_1 * T_1 , int V_199 , int V_200 )
{
int V_201 , V_202 ;
if ( T_1 -> V_203 )
V_200 = 1 ;
for ( V_201 = 0 ; V_201 < V_199 ; V_201 ++ )
for ( V_202 = 0 ; V_202 < V_200 ; ++ V_202 ) {
F_82 ( F_64 ( T_1 , V_201 , V_202 ) ) ;
F_64 ( T_1 , V_201 , V_202 ) = - 1 ;
}
}
void F_83 ( struct V_1 * T_1 )
{
assert ( F_84 ( & T_1 -> V_39 ) ) ;
assert ( T_1 -> V_37 == NULL ) ;
F_76 ( T_1 ) ;
F_77 ( T_1 ) ;
F_78 ( T_1 ) ;
F_85 ( T_1 -> V_218 ) ;
F_86 ( T_1 -> V_211 ) ;
F_86 ( T_1 -> V_219 ) ;
F_87 ( T_1 -> V_210 ) ;
F_25 ( & T_1 -> V_96 ) ;
F_25 ( & T_1 -> V_43 ) ;
V_5 . F_5 ( T_1 ) ;
}
void F_88 ( struct V_1 * T_1 )
{
F_83 ( T_1 ) ;
free ( T_1 ) ;
}
void F_89 ( struct V_1 * T_1 , int V_201 , int V_202 ,
struct V_220 * V_221 )
{
struct V_220 V_222 ;
if ( ! T_1 -> V_223 )
return;
if ( V_201 == - 1 ) {
V_222 = T_1 -> V_223 -> V_224 ;
T_1 -> V_223 -> V_224 = * V_221 ;
} else {
V_222 = * F_90 ( T_1 -> V_223 , V_201 , V_202 ) ;
* F_90 ( T_1 -> V_223 , V_201 , V_202 ) = * V_221 ;
}
V_221 -> V_127 = V_221 -> V_127 - V_222 . V_127 ;
V_221 -> V_225 = V_221 -> V_225 - V_222 . V_225 ;
V_221 -> V_226 = V_221 -> V_226 - V_222 . V_226 ;
}
void F_91 ( struct V_220 * V_221 ,
bool V_36 , T_8 * V_227 )
{
T_8 V_228 = 0 ;
if ( V_36 ) {
if ( V_221 -> V_226 == 0 ) {
V_228 = - 1 ;
V_221 -> V_127 = 0 ;
} else if ( V_221 -> V_226 < V_221 -> V_225 ) {
V_228 = 1 ;
V_221 -> V_127 = ( T_3 ) ( ( double ) V_221 -> V_127 * V_221 -> V_225 / V_221 -> V_226 + 0.5 ) ;
}
} else
V_221 -> V_225 = V_221 -> V_226 = 0 ;
if ( V_227 )
* V_227 = V_228 ;
}
int F_92 ( struct V_1 * T_1 , int V_201 , int V_202 ,
struct V_220 * V_221 )
{
memset ( V_221 , 0 , sizeof( * V_221 ) ) ;
if ( F_64 ( T_1 , V_201 , V_202 ) < 0 )
return - V_7 ;
if ( F_93 ( F_64 ( T_1 , V_201 , V_202 ) , V_221 , sizeof( * V_221 ) ) < 0 )
return - V_229 ;
return 0 ;
}
int F_94 ( struct V_1 * T_1 ,
int V_201 , int V_202 , bool V_36 )
{
struct V_220 V_221 ;
T_2 V_230 = V_36 ? 3 : 1 ;
if ( F_64 ( T_1 , V_201 , V_202 ) < 0 )
return - V_7 ;
if ( T_1 -> V_231 == NULL && F_95 ( T_1 , V_201 + 1 , V_202 + 1 ) < 0 )
return - V_45 ;
if ( F_93 ( F_64 ( T_1 , V_201 , V_202 ) , & V_221 , V_230 * sizeof( T_3 ) ) < 0 )
return - V_229 ;
F_89 ( T_1 , V_201 , V_202 , & V_221 ) ;
F_91 ( & V_221 , V_36 , NULL ) ;
* F_90 ( T_1 -> V_231 , V_201 , V_202 ) = V_221 ;
return 0 ;
}
static int F_96 ( struct V_1 * T_1 , int V_201 , int V_202 )
{
struct V_1 * V_34 = T_1 -> V_34 ;
int V_204 ;
if ( F_59 ( T_1 ) )
return - 1 ;
F_97 ( ! V_34 -> V_204 ) ;
V_204 = F_64 ( V_34 , V_201 , V_202 ) ;
F_97 ( V_204 == - 1 ) ;
return V_204 ;
}
static void F_98 ( char * V_97 , T_2 V_6 , T_3 V_232 , struct V_233 * V_234 )
{
bool V_235 = true ;
int V_11 = 0 ;
do {
if ( V_232 & V_234 [ V_11 ] . V_25 ) {
V_97 += F_30 ( V_97 , V_6 , L_38 , V_235 ? L_1 : L_39 , V_234 [ V_11 ] . V_43 ) ;
V_235 = false ;
}
} while ( V_234 [ ++ V_11 ] . V_43 != NULL );
}
static void F_99 ( char * V_97 , T_2 V_6 , T_3 V_232 )
{
#define F_100 ( T_9 ) { PERF_SAMPLE_##n, #n }
struct V_233 V_234 [] = {
F_100 ( V_149 ) , F_100 ( V_150 ) , F_100 ( TIME ) , F_100 ( V_164 ) ,
F_100 ( V_152 ) , F_100 ( V_104 ) , F_100 ( V_28 ) , F_100 ( V_170 ) ,
F_100 ( V_159 ) , F_100 ( V_236 ) , F_100 ( V_174 ) ,
F_100 ( V_108 ) , F_100 ( V_115 ) , F_100 ( V_116 ) ,
F_100 ( V_29 ) , F_100 ( V_169 ) , F_100 ( V_175 ) ,
F_100 ( V_180 ) ,
{ . V_43 = NULL , }
} ;
#undef F_100
F_98 ( V_97 , V_6 , V_232 , V_234 ) ;
}
static void F_101 ( char * V_97 , T_2 V_6 , T_3 V_232 )
{
#define F_100 ( T_9 ) { PERF_FORMAT_##n, #n }
struct V_233 V_234 [] = {
F_100 ( V_237 ) , F_100 ( V_238 ) ,
F_100 ( V_28 ) , F_100 ( V_239 ) ,
{ . V_43 = NULL , }
} ;
#undef F_100
F_98 ( V_97 , V_6 , V_232 , V_234 ) ;
}
int F_102 ( T_10 * V_240 , struct V_32 * V_22 ,
T_11 V_241 , void * V_242 )
{
char V_97 [ V_243 ] ;
int V_90 = 0 ;
F_103 ( type , V_244 ) ;
F_103 ( V_6 , V_244 ) ;
F_103 ( V_52 , V_245 ) ;
F_104 ( L_40 , V_54 , V_244 ) ;
F_103 ( V_8 , V_246 ) ;
F_103 ( V_30 , V_247 ) ;
F_103 ( V_192 , V_244 ) ;
F_103 ( V_138 , V_244 ) ;
F_103 ( V_248 , V_244 ) ;
F_103 ( V_249 , V_244 ) ;
F_103 ( V_62 , V_244 ) ;
F_103 ( V_61 , V_244 ) ;
F_103 ( V_63 , V_244 ) ;
F_103 ( V_250 , V_244 ) ;
F_103 ( V_182 , V_244 ) ;
F_103 ( V_184 , V_244 ) ;
F_103 ( V_129 , V_244 ) ;
F_103 ( V_162 , V_244 ) ;
F_103 ( V_194 , V_244 ) ;
F_103 ( V_181 , V_244 ) ;
F_103 ( V_177 , V_244 ) ;
F_103 ( V_67 , V_244 ) ;
F_103 ( V_165 , V_244 ) ;
F_103 ( V_146 , V_244 ) ;
F_103 ( V_68 , V_244 ) ;
F_103 ( V_69 , V_244 ) ;
F_103 ( V_251 , V_244 ) ;
F_103 ( V_121 , V_244 ) ;
F_103 ( V_183 , V_244 ) ;
F_103 ( V_252 , V_244 ) ;
F_103 ( V_197 , V_244 ) ;
F_103 ( V_186 , V_244 ) ;
F_104 ( L_41 , V_178 , V_244 ) ;
F_103 ( V_80 , V_244 ) ;
F_104 ( L_42 , V_79 , V_245 ) ;
F_104 ( L_43 , V_253 , V_245 ) ;
F_103 ( V_109 , V_244 ) ;
F_103 ( V_117 , V_245 ) ;
F_103 ( V_119 , V_244 ) ;
F_103 ( V_196 , V_254 ) ;
F_103 ( V_168 , V_245 ) ;
F_103 ( V_255 , V_244 ) ;
return V_90 ;
}
static int F_105 ( struct V_1 * T_1 , struct V_256 * V_211 ,
struct V_257 * V_210 )
{
int V_201 , V_202 , V_200 ;
unsigned long V_258 = V_259 ;
int V_260 = - 1 , V_44 ;
enum { V_261 , V_262 , V_263 } V_264 = V_261 ;
if ( T_1 -> V_203 )
V_200 = 1 ;
else
V_200 = V_210 -> V_265 ;
if ( T_1 -> V_204 == NULL &&
F_62 ( T_1 , V_211 -> V_265 , V_200 ) < 0 )
return - V_45 ;
if ( T_1 -> V_218 ) {
V_258 |= V_266 ;
V_260 = T_1 -> V_218 -> V_204 ;
}
V_267:
if ( V_147 . V_268 )
T_1 -> V_22 . V_196 = V_269 ;
if ( V_147 . V_196 ) {
T_1 -> V_22 . V_197 = 0 ;
T_1 -> V_22 . V_196 = 0 ;
}
if ( V_147 . V_270 )
V_258 &= ~ ( unsigned long ) V_259 ;
if ( V_147 . V_183 )
T_1 -> V_22 . V_183 = 0 ;
if ( V_147 . V_69 )
T_1 -> V_22 . V_69 = T_1 -> V_22 . V_68 = 0 ;
if ( V_147 . V_271 )
T_1 -> V_22 . V_109 &= ~ ( V_113 |
V_112 ) ;
V_272:
if ( V_147 . V_146 )
T_1 -> V_22 . V_146 = 0 ;
if ( V_273 >= 2 ) {
fprintf ( V_274 , L_44 , V_275 ) ;
fprintf ( V_274 , L_45 ) ;
F_102 ( V_274 , & T_1 -> V_22 , V_276 , NULL ) ;
fprintf ( V_274 , L_44 , V_275 ) ;
}
for ( V_201 = 0 ; V_201 < V_211 -> V_265 ; V_201 ++ ) {
for ( V_202 = 0 ; V_202 < V_200 ; V_202 ++ ) {
int V_277 ;
if ( ! T_1 -> V_218 && ! T_1 -> V_203 )
V_260 = F_106 ( V_210 , V_202 ) ;
V_277 = F_96 ( T_1 , V_201 , V_202 ) ;
V_278:
F_107 ( L_46 ,
V_260 , V_211 -> V_279 [ V_201 ] , V_277 , V_258 ) ;
F_64 ( T_1 , V_201 , V_202 ) = F_108 ( & T_1 -> V_22 ,
V_260 ,
V_211 -> V_279 [ V_201 ] ,
V_277 , V_258 ) ;
if ( F_64 ( T_1 , V_201 , V_202 ) < 0 ) {
V_44 = - V_229 ;
F_107 ( L_47 ,
V_44 ) ;
goto V_280;
}
if ( T_1 -> V_38 >= 0 ) {
int V_281 = F_64 ( T_1 , V_201 , V_202 ) ;
int V_38 = T_1 -> V_38 ;
V_44 = F_66 ( V_281 ,
V_282 ,
V_38 ) ;
if ( V_44 && V_229 != V_283 ) {
F_55 ( L_48 ,
V_38 , strerror ( V_229 ) ) ;
V_44 = - V_7 ;
goto V_284;
}
}
V_264 = V_261 ;
if ( V_147 . V_196 ||
V_147 . V_268 ) {
V_44 = - V_7 ;
goto V_284;
}
}
}
return 0 ;
V_280:
if ( V_44 == - V_285 && V_264 < V_263 ) {
struct V_286 V_287 ;
int V_288 = V_229 ;
if ( F_109 ( V_289 , & V_287 ) == 0 ) {
if ( V_264 == V_261 )
V_287 . V_290 = V_287 . V_291 ;
else {
V_287 . V_290 = V_287 . V_291 + 1000 ;
V_287 . V_291 = V_287 . V_290 ;
}
if ( F_110 ( V_289 , & V_287 ) == 0 ) {
V_264 ++ ;
V_229 = V_288 ;
goto V_278;
}
}
V_229 = V_288 ;
}
if ( V_44 != - V_7 || V_201 > 0 || V_202 > 0 )
goto V_284;
if ( ! V_147 . V_268 && T_1 -> V_22 . V_197 ) {
V_147 . V_268 = true ;
goto V_267;
} else if ( ! V_147 . V_196 && T_1 -> V_22 . V_197 ) {
V_147 . V_196 = true ;
goto V_267;
} else if ( ! V_147 . V_270 && ( V_258 & V_259 ) ) {
V_147 . V_270 = true ;
goto V_267;
} else if ( ! V_147 . V_183 && T_1 -> V_22 . V_183 ) {
V_147 . V_183 = true ;
goto V_267;
} else if ( ! V_147 . V_69 &&
( T_1 -> V_22 . V_69 || T_1 -> V_22 . V_68 ) ) {
V_147 . V_69 = true ;
goto V_267;
} else if ( ! V_147 . V_146 ) {
V_147 . V_146 = true ;
goto V_272;
} else if ( ! V_147 . V_271 &&
( T_1 -> V_22 . V_109 &
( V_112 |
V_113 ) ) ) {
V_147 . V_271 = true ;
goto V_267;
}
V_284:
do {
while ( -- V_202 >= 0 ) {
F_82 ( F_64 ( T_1 , V_201 , V_202 ) ) ;
F_64 ( T_1 , V_201 , V_202 ) = - 1 ;
}
V_202 = V_200 ;
} while ( -- V_201 >= 0 );
return V_44 ;
}
void F_111 ( struct V_1 * T_1 , int V_199 , int V_200 )
{
if ( T_1 -> V_204 == NULL )
return;
F_81 ( T_1 , V_199 , V_200 ) ;
F_76 ( T_1 ) ;
}
int F_112 ( struct V_1 * T_1 , struct V_256 * V_211 ,
struct V_257 * V_210 )
{
if ( V_211 == NULL ) {
V_211 = & V_292 . V_279 ;
}
if ( V_210 == NULL )
V_210 = & V_293 . V_279 ;
return F_105 ( T_1 , V_211 , V_210 ) ;
}
int F_113 ( struct V_1 * T_1 ,
struct V_256 * V_211 )
{
return F_105 ( T_1 , V_211 , & V_293 . V_279 ) ;
}
int F_114 ( struct V_1 * T_1 ,
struct V_257 * V_210 )
{
return F_105 ( T_1 , & V_292 . V_279 , V_210 ) ;
}
static int F_115 ( const struct V_1 * T_1 ,
const union V_294 * V_295 ,
struct V_296 * V_297 )
{
T_3 type = T_1 -> V_22 . V_8 ;
const T_3 * V_298 = V_295 -> V_297 . V_298 ;
bool V_299 = T_1 -> V_300 ;
union V_301 V_302 ;
V_298 += ( ( V_295 -> V_303 . V_6 -
sizeof( V_295 -> V_303 ) ) / sizeof( T_3 ) ) - 1 ;
if ( type & V_13 ) {
V_297 -> V_53 = * V_298 ;
V_298 -- ;
}
if ( type & V_19 ) {
V_302 . V_304 = * V_298 ;
if ( V_299 ) {
V_302 . V_304 = F_116 ( V_302 . V_304 ) ;
V_302 . V_305 [ 0 ] = F_117 ( V_302 . V_305 [ 0 ] ) ;
}
V_297 -> V_201 = V_302 . V_305 [ 0 ] ;
V_298 -- ;
}
if ( type & V_20 ) {
V_297 -> V_306 = * V_298 ;
V_298 -- ;
}
if ( type & V_14 ) {
V_297 -> V_53 = * V_298 ;
V_298 -- ;
}
if ( type & V_17 ) {
V_297 -> time = * V_298 ;
V_298 -- ;
}
if ( type & V_16 ) {
V_302 . V_304 = * V_298 ;
if ( V_299 ) {
V_302 . V_304 = F_116 ( V_302 . V_304 ) ;
V_302 . V_305 [ 0 ] = F_117 ( V_302 . V_305 [ 0 ] ) ;
V_302 . V_305 [ 1 ] = F_117 ( V_302 . V_305 [ 1 ] ) ;
}
V_297 -> V_260 = V_302 . V_305 [ 0 ] ;
V_297 -> V_307 = V_302 . V_305 [ 1 ] ;
V_298 -- ;
}
return 0 ;
}
static inline bool F_118 ( const void * V_308 , T_12 V_309 , const void * V_310 ,
T_3 V_6 )
{
return V_6 > V_309 || V_310 + V_6 > V_308 ;
}
int F_119 ( struct V_1 * T_1 , union V_294 * V_295 ,
struct V_296 * V_311 )
{
T_3 type = T_1 -> V_22 . V_8 ;
bool V_299 = T_1 -> V_300 ;
const T_3 * V_298 ;
T_12 V_309 = V_295 -> V_303 . V_6 ;
const void * V_308 = ( void * ) V_295 + V_309 ;
T_3 V_312 ;
union V_301 V_302 ;
memset ( V_311 , 0 , sizeof( * V_311 ) ) ;
V_311 -> V_201 = V_311 -> V_260 = V_311 -> V_307 = - 1 ;
V_311 -> V_306 = V_311 -> V_53 = V_311 -> time = - 1ULL ;
V_311 -> V_128 = T_1 -> V_22 . V_54 ;
V_311 -> V_313 = 0 ;
if ( V_295 -> V_303 . type != V_314 ) {
if ( ! T_1 -> V_22 . V_146 )
return 0 ;
return F_115 ( T_1 , V_295 , V_311 ) ;
}
V_298 = V_295 -> V_297 . V_298 ;
if ( T_1 -> V_26 + sizeof( V_295 -> V_303 ) > V_295 -> V_303 . V_6 )
return - V_315 ;
V_311 -> V_53 = - 1ULL ;
if ( type & V_13 ) {
V_311 -> V_53 = * V_298 ;
V_298 ++ ;
}
if ( type & V_15 ) {
V_311 -> V_316 = * V_298 ;
V_298 ++ ;
}
if ( type & V_16 ) {
V_302 . V_304 = * V_298 ;
if ( V_299 ) {
V_302 . V_304 = F_116 ( V_302 . V_304 ) ;
V_302 . V_305 [ 0 ] = F_117 ( V_302 . V_305 [ 0 ] ) ;
V_302 . V_305 [ 1 ] = F_117 ( V_302 . V_305 [ 1 ] ) ;
}
V_311 -> V_260 = V_302 . V_305 [ 0 ] ;
V_311 -> V_307 = V_302 . V_305 [ 1 ] ;
V_298 ++ ;
}
if ( type & V_17 ) {
V_311 -> time = * V_298 ;
V_298 ++ ;
}
V_311 -> V_74 = 0 ;
if ( type & V_18 ) {
V_311 -> V_74 = * V_298 ;
V_298 ++ ;
}
if ( type & V_14 ) {
V_311 -> V_53 = * V_298 ;
V_298 ++ ;
}
if ( type & V_20 ) {
V_311 -> V_306 = * V_298 ;
V_298 ++ ;
}
if ( type & V_19 ) {
V_302 . V_304 = * V_298 ;
if ( V_299 ) {
V_302 . V_304 = F_116 ( V_302 . V_304 ) ;
V_302 . V_305 [ 0 ] = F_117 ( V_302 . V_305 [ 0 ] ) ;
}
V_311 -> V_201 = V_302 . V_305 [ 0 ] ;
V_298 ++ ;
}
if ( type & V_49 ) {
V_311 -> V_128 = * V_298 ;
V_298 ++ ;
}
if ( type & V_317 ) {
T_3 V_30 = T_1 -> V_22 . V_30 ;
F_120 ( V_298 ) ;
if ( V_30 & V_154 )
V_311 -> V_318 . V_319 . V_265 = * V_298 ;
else
V_311 -> V_318 . V_320 . V_232 = * V_298 ;
V_298 ++ ;
if ( V_30 & V_190 ) {
F_120 ( V_298 ) ;
V_311 -> V_318 . V_321 = * V_298 ;
V_298 ++ ;
}
if ( V_30 & V_191 ) {
F_120 ( V_298 ) ;
V_311 -> V_318 . V_322 = * V_298 ;
V_298 ++ ;
}
if ( V_30 & V_154 ) {
const T_3 V_323 = V_324 /
sizeof( struct V_325 ) ;
if ( V_311 -> V_318 . V_319 . V_265 > V_323 )
return - V_315 ;
V_312 = V_311 -> V_318 . V_319 . V_265 *
sizeof( struct V_325 ) ;
F_121 ( V_298 , V_312 , V_309 ) ;
V_311 -> V_318 . V_319 . V_326 =
(struct V_325 * ) V_298 ;
V_298 = ( void * ) V_298 + V_312 ;
} else {
F_120 ( V_298 ) ;
V_311 -> V_318 . V_320 . V_53 = * V_298 ;
V_298 ++ ;
}
}
if ( type & V_327 ) {
const T_3 V_328 = V_324 / sizeof( T_3 ) ;
F_120 ( V_298 ) ;
V_311 -> V_329 = (struct V_330 * ) V_298 ++ ;
if ( V_311 -> V_329 -> V_265 > V_328 )
return - V_315 ;
V_312 = V_311 -> V_329 -> V_265 * sizeof( T_3 ) ;
F_121 ( V_298 , V_312 , V_309 ) ;
V_298 = ( void * ) V_298 + V_312 ;
}
if ( type & V_48 ) {
F_120 ( V_298 ) ;
V_302 . V_304 = * V_298 ;
if ( F_122 ( V_299 ,
L_49 ) ) {
V_302 . V_304 = F_116 ( V_302 . V_304 ) ;
V_302 . V_305 [ 0 ] = F_117 ( V_302 . V_305 [ 0 ] ) ;
V_302 . V_305 [ 1 ] = F_117 ( V_302 . V_305 [ 1 ] ) ;
}
V_311 -> V_331 = V_302 . V_305 [ 0 ] ;
V_298 = ( void * ) V_298 + sizeof( T_7 ) ;
F_121 ( V_298 , V_311 -> V_331 , V_309 ) ;
V_311 -> V_332 = ( void * ) V_298 ;
V_298 = ( void * ) V_298 + V_311 -> V_331 ;
}
if ( type & V_333 ) {
const T_3 V_334 = V_324 /
sizeof( struct V_335 ) ;
F_120 ( V_298 ) ;
V_311 -> V_107 = (struct V_107 * ) V_298 ++ ;
if ( V_311 -> V_107 -> V_265 > V_334 )
return - V_315 ;
V_312 = V_311 -> V_107 -> V_265 * sizeof( struct V_335 ) ;
F_121 ( V_298 , V_312 , V_309 ) ;
V_298 = ( void * ) V_298 + V_312 ;
}
if ( type & V_336 ) {
F_120 ( V_298 ) ;
V_311 -> V_337 . V_338 = * V_298 ;
V_298 ++ ;
if ( V_311 -> V_337 . V_338 ) {
T_3 V_9 = T_1 -> V_22 . V_117 ;
V_312 = F_123 ( V_9 ) * sizeof( T_3 ) ;
F_121 ( V_298 , V_312 , V_309 ) ;
V_311 -> V_337 . V_9 = V_9 ;
V_311 -> V_337 . V_339 = ( T_3 * ) V_298 ;
V_298 = ( void * ) V_298 + V_312 ;
}
}
if ( type & V_340 ) {
F_120 ( V_298 ) ;
V_312 = * V_298 ++ ;
V_311 -> V_341 . V_310 = ( ( char * ) ( V_298 - 1 )
- ( char * ) V_295 ) ;
if ( ! V_312 ) {
V_311 -> V_341 . V_6 = 0 ;
} else {
F_121 ( V_298 , V_312 , V_309 ) ;
V_311 -> V_341 . V_311 = ( char * ) V_298 ;
V_298 = ( void * ) V_298 + V_312 ;
F_120 ( V_298 ) ;
V_311 -> V_341 . V_6 = * V_298 ++ ;
if ( F_122 ( V_311 -> V_341 . V_6 > V_312 ,
L_50 ) )
return - V_315 ;
}
}
V_311 -> V_313 = 0 ;
if ( type & V_342 ) {
F_120 ( V_298 ) ;
V_311 -> V_313 = * V_298 ;
V_298 ++ ;
}
V_311 -> V_343 = V_344 ;
if ( type & V_345 ) {
F_120 ( V_298 ) ;
V_311 -> V_343 = * V_298 ;
V_298 ++ ;
}
V_311 -> V_346 = 0 ;
if ( type & V_347 ) {
F_120 ( V_298 ) ;
V_311 -> V_346 = * V_298 ;
V_298 ++ ;
}
V_311 -> V_348 . V_338 = V_349 ;
if ( type & V_350 ) {
F_120 ( V_298 ) ;
V_311 -> V_348 . V_338 = * V_298 ;
V_298 ++ ;
if ( V_311 -> V_348 . V_338 != V_349 ) {
T_3 V_9 = T_1 -> V_22 . V_168 ;
V_312 = F_123 ( V_9 ) * sizeof( T_3 ) ;
F_121 ( V_298 , V_312 , V_309 ) ;
V_311 -> V_348 . V_9 = V_9 ;
V_311 -> V_348 . V_339 = ( T_3 * ) V_298 ;
V_298 = ( void * ) V_298 + V_312 ;
}
}
return 0 ;
}
T_2 F_124 ( const struct V_296 * V_297 , T_3 type ,
T_3 V_30 )
{
T_2 V_312 , V_83 = sizeof( struct V_351 ) ;
if ( type & V_13 )
V_83 += sizeof( T_3 ) ;
if ( type & V_15 )
V_83 += sizeof( T_3 ) ;
if ( type & V_16 )
V_83 += sizeof( T_3 ) ;
if ( type & V_17 )
V_83 += sizeof( T_3 ) ;
if ( type & V_18 )
V_83 += sizeof( T_3 ) ;
if ( type & V_14 )
V_83 += sizeof( T_3 ) ;
if ( type & V_20 )
V_83 += sizeof( T_3 ) ;
if ( type & V_19 )
V_83 += sizeof( T_3 ) ;
if ( type & V_49 )
V_83 += sizeof( T_3 ) ;
if ( type & V_317 ) {
V_83 += sizeof( T_3 ) ;
if ( V_30 & V_190 )
V_83 += sizeof( T_3 ) ;
if ( V_30 & V_191 )
V_83 += sizeof( T_3 ) ;
if ( V_30 & V_154 ) {
V_312 = V_297 -> V_318 . V_319 . V_265 *
sizeof( struct V_325 ) ;
V_83 += V_312 ;
} else {
V_83 += sizeof( T_3 ) ;
}
}
if ( type & V_327 ) {
V_312 = ( V_297 -> V_329 -> V_265 + 1 ) * sizeof( T_3 ) ;
V_83 += V_312 ;
}
if ( type & V_48 ) {
V_83 += sizeof( T_7 ) ;
V_83 += V_297 -> V_331 ;
}
if ( type & V_333 ) {
V_312 = V_297 -> V_107 -> V_265 * sizeof( struct V_335 ) ;
V_312 += sizeof( T_3 ) ;
V_83 += V_312 ;
}
if ( type & V_336 ) {
if ( V_297 -> V_337 . V_338 ) {
V_83 += sizeof( T_3 ) ;
V_312 = F_123 ( V_297 -> V_337 . V_9 ) * sizeof( T_3 ) ;
V_83 += V_312 ;
} else {
V_83 += sizeof( T_3 ) ;
}
}
if ( type & V_340 ) {
V_312 = V_297 -> V_341 . V_6 ;
V_83 += sizeof( T_3 ) ;
if ( V_312 ) {
V_83 += V_312 ;
V_83 += sizeof( T_3 ) ;
}
}
if ( type & V_342 )
V_83 += sizeof( T_3 ) ;
if ( type & V_345 )
V_83 += sizeof( T_3 ) ;
if ( type & V_347 )
V_83 += sizeof( T_3 ) ;
if ( type & V_350 ) {
if ( V_297 -> V_348 . V_338 ) {
V_83 += sizeof( T_3 ) ;
V_312 = F_123 ( V_297 -> V_348 . V_9 ) * sizeof( T_3 ) ;
V_83 += V_312 ;
} else {
V_83 += sizeof( T_3 ) ;
}
}
return V_83 ;
}
int F_125 ( union V_294 * V_295 , T_3 type ,
T_3 V_30 ,
const struct V_296 * V_297 ,
bool V_299 )
{
T_3 * V_298 ;
T_2 V_312 ;
union V_301 V_302 ;
V_298 = V_295 -> V_297 . V_298 ;
if ( type & V_13 ) {
* V_298 = V_297 -> V_53 ;
V_298 ++ ;
}
if ( type & V_15 ) {
* V_298 = V_297 -> V_316 ;
V_298 ++ ;
}
if ( type & V_16 ) {
V_302 . V_305 [ 0 ] = V_297 -> V_260 ;
V_302 . V_305 [ 1 ] = V_297 -> V_307 ;
if ( V_299 ) {
V_302 . V_305 [ 0 ] = F_117 ( V_302 . V_305 [ 0 ] ) ;
V_302 . V_305 [ 1 ] = F_117 ( V_302 . V_305 [ 1 ] ) ;
V_302 . V_304 = F_116 ( V_302 . V_304 ) ;
}
* V_298 = V_302 . V_304 ;
V_298 ++ ;
}
if ( type & V_17 ) {
* V_298 = V_297 -> time ;
V_298 ++ ;
}
if ( type & V_18 ) {
* V_298 = V_297 -> V_74 ;
V_298 ++ ;
}
if ( type & V_14 ) {
* V_298 = V_297 -> V_53 ;
V_298 ++ ;
}
if ( type & V_20 ) {
* V_298 = V_297 -> V_306 ;
V_298 ++ ;
}
if ( type & V_19 ) {
V_302 . V_305 [ 0 ] = V_297 -> V_201 ;
if ( V_299 ) {
V_302 . V_305 [ 0 ] = F_117 ( V_302 . V_305 [ 0 ] ) ;
V_302 . V_304 = F_116 ( V_302 . V_304 ) ;
}
* V_298 = V_302 . V_304 ;
V_298 ++ ;
}
if ( type & V_49 ) {
* V_298 = V_297 -> V_128 ;
V_298 ++ ;
}
if ( type & V_317 ) {
if ( V_30 & V_154 )
* V_298 = V_297 -> V_318 . V_319 . V_265 ;
else
* V_298 = V_297 -> V_318 . V_320 . V_232 ;
V_298 ++ ;
if ( V_30 & V_190 ) {
* V_298 = V_297 -> V_318 . V_321 ;
V_298 ++ ;
}
if ( V_30 & V_191 ) {
* V_298 = V_297 -> V_318 . V_322 ;
V_298 ++ ;
}
if ( V_30 & V_154 ) {
V_312 = V_297 -> V_318 . V_319 . V_265 *
sizeof( struct V_325 ) ;
memcpy ( V_298 , V_297 -> V_318 . V_319 . V_326 , V_312 ) ;
V_298 = ( void * ) V_298 + V_312 ;
} else {
* V_298 = V_297 -> V_318 . V_320 . V_53 ;
V_298 ++ ;
}
}
if ( type & V_327 ) {
V_312 = ( V_297 -> V_329 -> V_265 + 1 ) * sizeof( T_3 ) ;
memcpy ( V_298 , V_297 -> V_329 , V_312 ) ;
V_298 = ( void * ) V_298 + V_312 ;
}
if ( type & V_48 ) {
V_302 . V_305 [ 0 ] = V_297 -> V_331 ;
if ( F_122 ( V_299 ,
L_49 ) ) {
V_302 . V_305 [ 0 ] = F_117 ( V_302 . V_305 [ 0 ] ) ;
V_302 . V_305 [ 1 ] = F_117 ( V_302 . V_305 [ 1 ] ) ;
V_302 . V_304 = F_116 ( V_302 . V_304 ) ;
}
* V_298 = V_302 . V_304 ;
V_298 = ( void * ) V_298 + sizeof( T_7 ) ;
memcpy ( V_298 , V_297 -> V_332 , V_297 -> V_331 ) ;
V_298 = ( void * ) V_298 + V_297 -> V_331 ;
}
if ( type & V_333 ) {
V_312 = V_297 -> V_107 -> V_265 * sizeof( struct V_335 ) ;
V_312 += sizeof( T_3 ) ;
memcpy ( V_298 , V_297 -> V_107 , V_312 ) ;
V_298 = ( void * ) V_298 + V_312 ;
}
if ( type & V_336 ) {
if ( V_297 -> V_337 . V_338 ) {
* V_298 ++ = V_297 -> V_337 . V_338 ;
V_312 = F_123 ( V_297 -> V_337 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_298 , V_297 -> V_337 . V_339 , V_312 ) ;
V_298 = ( void * ) V_298 + V_312 ;
} else {
* V_298 ++ = 0 ;
}
}
if ( type & V_340 ) {
V_312 = V_297 -> V_341 . V_6 ;
* V_298 ++ = V_312 ;
if ( V_312 ) {
memcpy ( V_298 , V_297 -> V_341 . V_311 , V_312 ) ;
V_298 = ( void * ) V_298 + V_312 ;
* V_298 ++ = V_312 ;
}
}
if ( type & V_342 ) {
* V_298 = V_297 -> V_313 ;
V_298 ++ ;
}
if ( type & V_345 ) {
* V_298 = V_297 -> V_343 ;
V_298 ++ ;
}
if ( type & V_347 ) {
* V_298 = V_297 -> V_346 ;
V_298 ++ ;
}
if ( type & V_350 ) {
if ( V_297 -> V_348 . V_338 ) {
* V_298 ++ = V_297 -> V_348 . V_338 ;
V_312 = F_123 ( V_297 -> V_348 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_298 , V_297 -> V_348 . V_339 , V_312 ) ;
V_298 = ( void * ) V_298 + V_312 ;
} else {
* V_298 ++ = 0 ;
}
}
return 0 ;
}
struct V_352 * F_126 ( struct V_1 * T_1 , const char * V_43 )
{
return F_127 ( T_1 -> V_51 , V_43 ) ;
}
void * F_128 ( struct V_1 * T_1 , struct V_296 * V_297 ,
const char * V_43 )
{
struct V_352 * V_353 = F_126 ( T_1 , V_43 ) ;
int V_310 ;
if ( ! V_353 )
return NULL ;
V_310 = V_353 -> V_310 ;
if ( V_353 -> V_258 & V_354 ) {
V_310 = * ( int * ) ( V_297 -> V_332 + V_353 -> V_310 ) ;
V_310 &= 0xffff ;
}
return V_297 -> V_332 + V_310 ;
}
T_3 F_129 ( struct V_1 * T_1 , struct V_296 * V_297 ,
const char * V_43 )
{
struct V_352 * V_353 = F_126 ( T_1 , V_43 ) ;
void * V_355 ;
T_3 V_232 ;
if ( ! V_353 )
return 0 ;
V_355 = V_297 -> V_332 + V_353 -> V_310 ;
switch ( V_353 -> V_6 ) {
case 1 :
return * ( T_6 * ) V_355 ;
case 2 :
V_232 = * ( T_12 * ) V_355 ;
break;
case 4 :
V_232 = * ( T_7 * ) V_355 ;
break;
case 8 :
memcpy ( & V_232 , V_355 , sizeof( T_3 ) ) ;
break;
default:
return 0 ;
}
if ( ! T_1 -> V_300 )
return V_232 ;
switch ( V_353 -> V_6 ) {
case 2 :
return F_130 ( V_232 ) ;
case 4 :
return F_117 ( V_232 ) ;
case 8 :
return F_116 ( V_232 ) ;
default:
return 0 ;
}
return 0 ;
}
static int F_131 ( T_10 * V_240 , bool * V_356 , const char * V_357 , ... )
{
T_13 args ;
int V_90 = 0 ;
if ( ! * V_356 ) {
V_90 += fprintf ( V_240 , L_51 ) ;
} else {
V_90 += fprintf ( V_240 , L_9 ) ;
* V_356 = false ;
}
va_start ( args , V_357 ) ;
V_90 += vfprintf ( V_240 , V_357 , args ) ;
va_end ( args ) ;
return V_90 ;
}
static int F_132 ( T_10 * V_240 , const char * V_43 , const char * V_127 , void * V_242 )
{
return F_131 ( V_240 , ( bool * ) V_242 , L_52 , V_43 , V_127 ) ;
}
int F_133 ( struct V_1 * T_1 ,
struct V_358 * V_359 , T_10 * V_240 )
{
bool V_356 = true ;
int V_360 = 0 ;
if ( V_359 -> V_361 ) {
struct V_1 * V_98 ;
if ( ! F_59 ( T_1 ) )
return 0 ;
if ( T_1 -> V_153 > 1 )
V_360 += fprintf ( V_240 , L_53 , T_1 -> V_96 ? : L_1 ) ;
V_360 += fprintf ( V_240 , L_6 , F_42 ( T_1 ) ) ;
F_46 (pos, evsel)
V_360 += fprintf ( V_240 , L_54 , F_42 ( V_98 ) ) ;
if ( T_1 -> V_153 > 1 )
V_360 += fprintf ( V_240 , L_55 ) ;
goto V_362;
}
V_360 += fprintf ( V_240 , L_6 , F_42 ( T_1 ) ) ;
if ( V_359 -> V_273 ) {
V_360 += F_102 ( V_240 , & T_1 -> V_22 ,
F_132 , & V_356 ) ;
} else if ( V_359 -> V_129 ) {
const char * V_123 = L_56 ;
if ( ! T_1 -> V_22 . V_129 )
V_123 = L_57 ;
V_360 += F_131 ( V_240 , & V_356 , L_58 V_363 ,
V_123 , ( T_3 ) T_1 -> V_22 . V_131 ) ;
}
if ( V_359 -> V_364 ) {
struct V_352 * V_353 ;
if ( T_1 -> V_22 . type != V_47 ) {
V_360 += F_131 ( V_240 , & V_356 , L_59 ) ;
goto V_362;
}
V_353 = T_1 -> V_51 -> V_365 . V_366 ;
if ( V_353 == NULL ) {
V_360 += F_131 ( V_240 , & V_356 , L_60 ) ;
goto V_362;
}
V_360 += F_131 ( V_240 , & V_356 , L_61 , V_353 -> V_43 ) ;
V_353 = V_353 -> V_367 ;
while ( V_353 ) {
V_360 += F_131 ( V_240 , & V_356 , L_6 , V_353 -> V_43 ) ;
V_353 = V_353 -> V_367 ;
}
}
V_362:
fputc ( '\n' , V_240 ) ;
return ++ V_360 ;
}
bool F_134 ( struct V_1 * T_1 , int V_44 ,
char * V_368 , T_2 V_369 )
{
if ( ( V_44 == V_370 || V_44 == V_371 || V_44 == V_372 ) &&
T_1 -> V_22 . type == V_92 &&
T_1 -> V_22 . V_52 == V_373 ) {
F_30 ( V_368 , V_369 , L_6 ,
L_62 ) ;
T_1 -> V_22 . type = V_94 ;
T_1 -> V_22 . V_52 = V_374 ;
F_25 ( & T_1 -> V_43 ) ;
return true ;
}
return false ;
}
int F_135 ( struct V_1 * T_1 , struct V_143 * V_143 ,
int V_44 , char * V_368 , T_2 V_6 )
{
char V_375 [ V_376 ] ;
switch ( V_44 ) {
case V_377 :
case V_378 :
return F_30 ( V_368 , V_6 ,
L_63
L_64
L_65
L_66
L_67
L_68 ,
V_143 -> V_203 ? L_69 : L_1 ) ;
case V_370 :
return F_30 ( V_368 , V_6 , L_70 ,
F_42 ( T_1 ) ) ;
case V_285 :
return F_30 ( V_368 , V_6 , L_6 ,
L_71
L_72
L_73
L_74 ) ;
case V_372 :
if ( V_143 -> V_379 )
return F_30 ( V_368 , V_6 , L_6 ,
L_75 ) ;
break;
case V_380 :
if ( T_1 -> V_22 . V_67 )
return F_30 ( V_368 , V_6 , L_6 ,
L_76 ) ;
#if F_136 ( V_381 ) || F_136 ( V_382 )
if ( T_1 -> V_22 . type == V_92 )
return F_30 ( V_368 , V_6 , L_6 ,
L_77
L_78 ) ;
#endif
break;
case V_383 :
if ( F_137 ( L_79 ) )
return F_30 ( V_368 , V_6 ,
L_80
L_81 ) ;
break;
case V_7 :
if ( V_147 . V_196 )
return F_30 ( V_368 , V_6 , L_82 ) ;
if ( V_147 . V_268 )
return F_30 ( V_368 , V_6 , L_83 , V_196 ) ;
break;
default:
break;
}
return F_30 ( V_368 , V_6 ,
L_84
L_85
L_86 ,
V_44 , F_138 ( V_44 , V_375 , sizeof( V_375 ) ) ,
F_42 ( T_1 ) ) ;
}
