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
V_111 ;
}
} else
F_49 ( L_30
L_29 ) ;
}
if ( V_102 -> V_105 == V_112 ) {
if ( ! V_103 ) {
F_14 ( T_1 , V_113 ) ;
F_14 ( T_1 , V_114 ) ;
V_22 -> V_115 = V_116 ;
V_22 -> V_117 = V_102 -> V_118 ;
V_22 -> V_119 = 1 ;
} else {
F_50 ( L_31
L_32 ) ;
}
}
if ( V_103 ) {
F_50 ( L_33 ) ;
V_22 -> V_119 = 1 ;
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
if ( V_102 -> V_105 == V_112 ) {
F_13 ( T_1 , V_113 ) ;
F_13 ( T_1 , V_114 ) ;
}
}
static void F_52 ( struct V_1 * T_1 ,
struct V_99 * V_100 )
{
struct V_120 * V_121 ;
struct V_122 * V_40 = & T_1 -> V_40 ;
struct V_32 * V_22 = & T_1 -> V_22 ;
struct V_101 V_102 ;
T_7 V_118 = 0 ;
char * V_123 = NULL ;
V_102 . V_105 = V_101 . V_105 ;
F_53 (term, config_terms, list) {
switch ( V_121 -> type ) {
case V_124 :
V_22 -> V_54 = V_121 -> V_125 . V_126 ;
V_22 -> V_127 = 0 ;
break;
case V_128 :
V_22 -> V_129 = V_121 -> V_125 . V_127 ;
V_22 -> V_127 = 1 ;
break;
case V_130 :
if ( V_121 -> V_125 . time )
F_14 ( T_1 , TIME ) ;
else
F_13 ( T_1 , TIME ) ;
break;
case V_131 :
V_123 = V_121 -> V_125 . V_132 ;
break;
case V_133 :
V_118 = V_121 -> V_125 . V_134 ;
break;
case V_135 :
V_22 -> V_136 = V_121 -> V_125 . V_136 ? 1 : 0 ;
break;
default:
break;
}
}
if ( ( V_123 != NULL ) || ( V_118 > 0 ) ) {
if ( V_123 != NULL ) {
if ( ! strcmp ( V_123 , L_34 ) ) {
V_102 . V_137 = false ;
V_102 . V_105 = V_138 ;
} else {
V_102 . V_137 = true ;
if ( F_54 ( V_123 , & V_102 ) ) {
F_55 ( L_35
L_36 ,
T_1 -> V_43 ) ;
return;
}
}
}
if ( V_118 > 0 ) {
V_118 = F_56 ( V_118 , sizeof( T_3 ) ) ;
V_102 . V_118 = V_118 ;
}
if ( V_101 . V_137 )
F_51 ( T_1 , & V_101 ) ;
if ( V_102 . V_137 )
F_47 ( T_1 , V_100 , & V_102 ) ;
}
}
void F_57 ( struct V_1 * T_1 , struct V_99 * V_100 )
{
struct V_1 * V_34 = T_1 -> V_34 ;
struct V_32 * V_22 = & T_1 -> V_22 ;
int V_139 = T_1 -> V_33 ;
bool V_140 = V_100 -> V_141 . V_142 && ! V_100 -> V_141 . V_143 ;
V_22 -> V_144 = V_145 . V_144 ? 0 : 1 ;
V_22 -> V_136 = ! V_100 -> V_146 ;
F_14 ( T_1 , V_147 ) ;
F_14 ( T_1 , V_148 ) ;
if ( T_1 -> V_149 ) {
F_14 ( T_1 , V_150 ) ;
F_12 ( T_1 , false ) ;
if ( V_34 -> V_151 > 1 ) {
V_22 -> V_30 |= V_152 ;
V_22 -> V_136 = 0 ;
}
}
if ( ! V_22 -> V_54 || ( V_100 -> V_153 != V_154 ||
V_100 -> V_155 != V_156 ) ) {
if ( V_100 -> V_127 ) {
F_14 ( T_1 , V_157 ) ;
V_22 -> V_127 = 1 ;
V_22 -> V_129 = V_100 -> V_127 ;
} else {
V_22 -> V_54 = V_100 -> V_158 ;
}
}
if ( ( V_34 != T_1 ) && V_34 -> V_149 ) {
V_22 -> V_129 = 0 ;
V_22 -> V_54 = 0 ;
}
if ( V_100 -> V_159 )
V_22 -> V_129 = 0 ;
if ( V_100 -> V_160 )
V_22 -> V_160 = 1 ;
if ( V_100 -> V_161 ) {
F_14 ( T_1 , V_162 ) ;
V_22 -> V_163 = V_139 ;
}
if ( F_48 ( T_1 ) )
T_1 -> V_22 . V_119 = 1 ;
if ( V_101 . V_137 && ! T_1 -> V_164 )
F_47 ( T_1 , V_100 , & V_101 ) ;
if ( V_100 -> V_165 ) {
V_22 -> V_166 = V_100 -> V_165 ;
F_14 ( T_1 , V_167 ) ;
}
if ( F_58 ( & V_100 -> V_141 ) )
F_14 ( T_1 , V_168 ) ;
if ( V_100 -> V_126 )
F_14 ( T_1 , V_157 ) ;
if ( V_100 -> V_169 &&
( ! V_145 . V_144 &&
( ! V_100 -> V_146 || F_58 ( & V_100 -> V_141 ) || V_140 ||
V_100 -> V_170 ) ) )
F_14 ( T_1 , TIME ) ;
if ( V_100 -> V_171 && ! T_1 -> V_164 ) {
F_14 ( T_1 , TIME ) ;
F_14 ( T_1 , V_172 ) ;
F_14 ( T_1 , V_168 ) ;
}
if ( V_100 -> V_161 )
F_14 ( T_1 , V_173 ) ;
if ( V_100 -> V_174 ) {
V_22 -> V_175 = 0 ;
V_22 -> V_176 = 1 ;
}
if ( V_100 -> V_107 && ! T_1 -> V_164 ) {
F_14 ( T_1 , V_108 ) ;
V_22 -> V_109 = V_100 -> V_107 ;
}
if ( V_100 -> V_177 )
F_14 ( T_1 , V_178 ) ;
V_22 -> V_179 = V_139 ;
V_22 -> V_180 = V_139 ;
V_22 -> V_181 = V_139 && ! V_145 . V_181 ;
V_22 -> V_182 = V_139 ;
if ( V_100 -> V_183 )
V_22 -> V_184 = V_139 ;
if ( V_100 -> V_185 )
F_14 ( T_1 , V_186 ) ;
if ( V_100 -> V_187 ) {
T_1 -> V_22 . V_30 |=
V_188 |
V_189 ;
}
if ( F_59 ( T_1 ) )
V_22 -> V_190 = 1 ;
if ( F_60 ( & V_100 -> V_141 ) && F_59 ( T_1 ) &&
! V_100 -> V_191 )
V_22 -> V_192 = 1 ;
if ( T_1 -> V_193 ) {
V_22 -> V_190 = 0 ;
V_22 -> V_192 = 0 ;
}
V_194 = V_100 -> V_194 ;
if ( V_100 -> V_195 ) {
V_22 -> V_195 = 1 ;
V_22 -> V_194 = V_100 -> V_194 ;
}
if ( T_1 -> V_196 )
F_61 ( V_22 ) ;
F_52 ( T_1 , V_100 ) ;
}
static int F_62 ( struct V_1 * T_1 , int V_197 , int V_198 )
{
int V_199 , V_200 ;
if ( T_1 -> V_201 )
V_198 = 1 ;
T_1 -> V_202 = F_63 ( V_197 , V_198 , sizeof( int ) ) ;
if ( T_1 -> V_202 ) {
for ( V_199 = 0 ; V_199 < V_197 ; V_199 ++ ) {
for ( V_200 = 0 ; V_200 < V_198 ; V_200 ++ ) {
F_64 ( T_1 , V_199 , V_200 ) = - 1 ;
}
}
}
return T_1 -> V_202 != NULL ? 0 : - V_45 ;
}
static int F_65 ( struct V_1 * T_1 , int V_197 , int V_198 ,
int V_203 , void * V_204 )
{
int V_199 , V_200 ;
if ( T_1 -> V_201 )
V_198 = 1 ;
for ( V_199 = 0 ; V_199 < V_197 ; V_199 ++ ) {
for ( V_200 = 0 ; V_200 < V_198 ; V_200 ++ ) {
int V_202 = F_64 ( T_1 , V_199 , V_200 ) ,
V_44 = F_66 ( V_202 , V_203 , V_204 ) ;
if ( V_44 )
return V_44 ;
}
}
return 0 ;
}
int F_67 ( struct V_1 * T_1 , int V_197 , int V_198 ,
const char * V_205 )
{
return F_65 ( T_1 , V_197 , V_198 ,
V_206 ,
( void * ) V_205 ) ;
}
int F_68 ( struct V_1 * T_1 , const char * V_205 )
{
char * V_207 = F_43 ( V_205 ) ;
if ( V_207 != NULL ) {
free ( T_1 -> V_205 ) ;
T_1 -> V_205 = V_207 ;
return 0 ;
}
return - 1 ;
}
int F_69 ( struct V_1 * T_1 ,
const char * V_81 , const char * V_205 )
{
char * V_207 ;
if ( T_1 -> V_205 == NULL )
return F_68 ( T_1 , V_205 ) ;
if ( F_20 ( & V_207 , L_37 , T_1 -> V_205 , V_81 , V_205 ) > 0 ) {
free ( T_1 -> V_205 ) ;
T_1 -> V_205 = V_207 ;
return 0 ;
}
return - 1 ;
}
int F_70 ( struct V_1 * T_1 , int V_197 , int V_198 )
{
return F_65 ( T_1 , V_197 , V_198 ,
V_208 ,
0 ) ;
}
int F_71 ( struct V_1 * T_1 , int V_197 , int V_198 )
{
if ( V_197 == 0 || V_198 == 0 )
return 0 ;
if ( T_1 -> V_201 )
V_198 = 1 ;
T_1 -> V_209 = F_63 ( V_197 , V_198 , sizeof( struct V_210 ) ) ;
if ( T_1 -> V_209 == NULL )
return - V_45 ;
T_1 -> V_53 = F_18 ( V_197 * V_198 * sizeof( T_3 ) ) ;
if ( T_1 -> V_53 == NULL ) {
F_72 ( T_1 -> V_209 ) ;
T_1 -> V_209 = NULL ;
return - V_45 ;
}
return 0 ;
}
static void F_73 ( struct V_1 * T_1 )
{
F_72 ( T_1 -> V_202 ) ;
T_1 -> V_202 = NULL ;
}
static void F_74 ( struct V_1 * T_1 )
{
F_72 ( T_1 -> V_209 ) ;
T_1 -> V_209 = NULL ;
F_25 ( & T_1 -> V_53 ) ;
}
static void F_75 ( struct V_1 * T_1 )
{
struct V_120 * V_121 , * V_211 ;
F_76 (term, h, &evsel->config_terms, list) {
F_77 ( & V_121 -> V_212 ) ;
free ( V_121 ) ;
}
}
void F_78 ( struct V_1 * T_1 , int V_197 , int V_198 )
{
int V_199 , V_200 ;
if ( T_1 -> V_201 )
V_198 = 1 ;
for ( V_199 = 0 ; V_199 < V_197 ; V_199 ++ )
for ( V_200 = 0 ; V_200 < V_198 ; ++ V_200 ) {
F_79 ( F_64 ( T_1 , V_199 , V_200 ) ) ;
F_64 ( T_1 , V_199 , V_200 ) = - 1 ;
}
}
void F_80 ( struct V_1 * T_1 )
{
assert ( F_81 ( & T_1 -> V_39 ) ) ;
assert ( T_1 -> V_37 == NULL ) ;
F_73 ( T_1 ) ;
F_74 ( T_1 ) ;
F_75 ( T_1 ) ;
F_82 ( T_1 -> V_213 ) ;
F_83 ( T_1 -> V_214 ) ;
F_83 ( T_1 -> V_215 ) ;
F_84 ( T_1 -> V_216 ) ;
F_25 ( & T_1 -> V_96 ) ;
F_25 ( & T_1 -> V_43 ) ;
V_5 . F_5 ( T_1 ) ;
}
void F_85 ( struct V_1 * T_1 )
{
F_80 ( T_1 ) ;
free ( T_1 ) ;
}
void F_86 ( struct V_1 * T_1 , int V_199 , int V_200 ,
struct V_217 * V_218 )
{
struct V_217 V_219 ;
if ( ! T_1 -> V_220 )
return;
if ( V_199 == - 1 ) {
V_219 = T_1 -> V_220 -> V_221 ;
T_1 -> V_220 -> V_221 = * V_218 ;
} else {
V_219 = * F_87 ( T_1 -> V_220 , V_199 , V_200 ) ;
* F_87 ( T_1 -> V_220 , V_199 , V_200 ) = * V_218 ;
}
V_218 -> V_125 = V_218 -> V_125 - V_219 . V_125 ;
V_218 -> V_222 = V_218 -> V_222 - V_219 . V_222 ;
V_218 -> V_223 = V_218 -> V_223 - V_219 . V_223 ;
}
void F_88 ( struct V_217 * V_218 ,
bool V_36 , T_8 * V_224 )
{
T_8 V_225 = 0 ;
if ( V_36 ) {
if ( V_218 -> V_223 == 0 ) {
V_225 = - 1 ;
V_218 -> V_125 = 0 ;
} else if ( V_218 -> V_223 < V_218 -> V_222 ) {
V_225 = 1 ;
V_218 -> V_125 = ( T_3 ) ( ( double ) V_218 -> V_125 * V_218 -> V_222 / V_218 -> V_223 + 0.5 ) ;
}
} else
V_218 -> V_222 = V_218 -> V_223 = 0 ;
if ( V_224 )
* V_224 = V_225 ;
}
int F_89 ( struct V_1 * T_1 , int V_199 , int V_200 ,
struct V_217 * V_218 )
{
memset ( V_218 , 0 , sizeof( * V_218 ) ) ;
if ( F_64 ( T_1 , V_199 , V_200 ) < 0 )
return - V_7 ;
if ( F_90 ( F_64 ( T_1 , V_199 , V_200 ) , V_218 , sizeof( * V_218 ) ) < 0 )
return - V_226 ;
return 0 ;
}
int F_91 ( struct V_1 * T_1 ,
int V_199 , int V_200 , bool V_36 )
{
struct V_217 V_218 ;
T_2 V_227 = V_36 ? 3 : 1 ;
if ( F_64 ( T_1 , V_199 , V_200 ) < 0 )
return - V_7 ;
if ( T_1 -> V_228 == NULL && F_92 ( T_1 , V_199 + 1 , V_200 + 1 ) < 0 )
return - V_45 ;
if ( F_90 ( F_64 ( T_1 , V_199 , V_200 ) , & V_218 , V_227 * sizeof( T_3 ) ) < 0 )
return - V_226 ;
F_86 ( T_1 , V_199 , V_200 , & V_218 ) ;
F_88 ( & V_218 , V_36 , NULL ) ;
* F_87 ( T_1 -> V_228 , V_199 , V_200 ) = V_218 ;
return 0 ;
}
static int F_93 ( struct V_1 * T_1 , int V_199 , int V_200 )
{
struct V_1 * V_34 = T_1 -> V_34 ;
int V_202 ;
if ( F_59 ( T_1 ) )
return - 1 ;
F_94 ( ! V_34 -> V_202 ) ;
V_202 = F_64 ( V_34 , V_199 , V_200 ) ;
F_94 ( V_202 == - 1 ) ;
return V_202 ;
}
static void F_95 ( char * V_97 , T_2 V_6 , T_3 V_229 , struct V_230 * V_231 )
{
bool V_232 = true ;
int V_11 = 0 ;
do {
if ( V_229 & V_231 [ V_11 ] . V_25 ) {
V_97 += F_30 ( V_97 , V_6 , L_38 , V_232 ? L_1 : L_39 , V_231 [ V_11 ] . V_43 ) ;
V_232 = false ;
}
} while ( V_231 [ ++ V_11 ] . V_43 != NULL );
}
static void F_96 ( char * V_97 , T_2 V_6 , T_3 V_229 )
{
#define F_97 ( T_9 ) { PERF_SAMPLE_##n, #n }
struct V_230 V_231 [] = {
F_97 ( V_147 ) , F_97 ( V_148 ) , F_97 ( TIME ) , F_97 ( V_162 ) ,
F_97 ( V_150 ) , F_97 ( V_104 ) , F_97 ( V_28 ) , F_97 ( V_168 ) ,
F_97 ( V_157 ) , F_97 ( V_233 ) , F_97 ( V_172 ) ,
F_97 ( V_108 ) , F_97 ( V_113 ) , F_97 ( V_114 ) ,
F_97 ( V_29 ) , F_97 ( V_167 ) , F_97 ( V_173 ) ,
{ . V_43 = NULL , }
} ;
#undef F_97
F_95 ( V_97 , V_6 , V_229 , V_231 ) ;
}
static void F_98 ( char * V_97 , T_2 V_6 , T_3 V_229 )
{
#define F_97 ( T_9 ) { PERF_FORMAT_##n, #n }
struct V_230 V_231 [] = {
F_97 ( V_234 ) , F_97 ( V_235 ) ,
F_97 ( V_28 ) , F_97 ( V_236 ) ,
{ . V_43 = NULL , }
} ;
#undef F_97
F_95 ( V_97 , V_6 , V_229 , V_231 ) ;
}
int F_99 ( T_10 * V_237 , struct V_32 * V_22 ,
T_11 V_238 , void * V_239 )
{
char V_97 [ V_240 ] ;
int V_90 = 0 ;
F_100 ( type , V_241 ) ;
F_100 ( V_6 , V_241 ) ;
F_100 ( V_52 , V_242 ) ;
F_101 ( L_40 , V_54 , V_241 ) ;
F_100 ( V_8 , V_243 ) ;
F_100 ( V_30 , V_244 ) ;
F_100 ( V_190 , V_241 ) ;
F_100 ( V_136 , V_241 ) ;
F_100 ( V_245 , V_241 ) ;
F_100 ( V_246 , V_241 ) ;
F_100 ( V_62 , V_241 ) ;
F_100 ( V_61 , V_241 ) ;
F_100 ( V_63 , V_241 ) ;
F_100 ( V_247 , V_241 ) ;
F_100 ( V_180 , V_241 ) ;
F_100 ( V_182 , V_241 ) ;
F_100 ( V_127 , V_241 ) ;
F_100 ( V_160 , V_241 ) ;
F_100 ( V_192 , V_241 ) ;
F_100 ( V_179 , V_241 ) ;
F_100 ( V_175 , V_241 ) ;
F_100 ( V_67 , V_241 ) ;
F_100 ( V_163 , V_241 ) ;
F_100 ( V_144 , V_241 ) ;
F_100 ( V_68 , V_241 ) ;
F_100 ( V_69 , V_241 ) ;
F_100 ( V_248 , V_241 ) ;
F_100 ( V_119 , V_241 ) ;
F_100 ( V_181 , V_241 ) ;
F_100 ( V_249 , V_241 ) ;
F_100 ( V_195 , V_241 ) ;
F_100 ( V_184 , V_241 ) ;
F_101 ( L_41 , V_176 , V_241 ) ;
F_100 ( V_80 , V_241 ) ;
F_101 ( L_42 , V_79 , V_242 ) ;
F_101 ( L_43 , V_250 , V_242 ) ;
F_100 ( V_109 , V_241 ) ;
F_100 ( V_115 , V_242 ) ;
F_100 ( V_117 , V_241 ) ;
F_100 ( V_194 , V_251 ) ;
F_100 ( V_166 , V_242 ) ;
F_100 ( V_252 , V_241 ) ;
return V_90 ;
}
static int F_102 ( struct V_1 * T_1 , struct V_253 * V_214 ,
struct V_254 * V_216 )
{
int V_199 , V_200 , V_198 ;
unsigned long V_255 = V_256 ;
int V_257 = - 1 , V_44 ;
enum { V_258 , V_259 , V_260 } V_261 = V_258 ;
if ( T_1 -> V_201 )
V_198 = 1 ;
else
V_198 = V_216 -> V_262 ;
if ( T_1 -> V_202 == NULL &&
F_62 ( T_1 , V_214 -> V_262 , V_198 ) < 0 )
return - V_45 ;
if ( T_1 -> V_213 ) {
V_255 |= V_263 ;
V_257 = T_1 -> V_213 -> V_202 ;
}
V_264:
if ( V_145 . V_265 )
T_1 -> V_22 . V_194 = V_266 ;
if ( V_145 . V_194 ) {
T_1 -> V_22 . V_195 = 0 ;
T_1 -> V_22 . V_194 = 0 ;
}
if ( V_145 . V_267 )
V_255 &= ~ ( unsigned long ) V_256 ;
if ( V_145 . V_181 )
T_1 -> V_22 . V_181 = 0 ;
if ( V_145 . V_69 )
T_1 -> V_22 . V_69 = T_1 -> V_22 . V_68 = 0 ;
V_268:
if ( V_145 . V_144 )
T_1 -> V_22 . V_144 = 0 ;
if ( V_269 >= 2 ) {
fprintf ( V_270 , L_44 , V_271 ) ;
fprintf ( V_270 , L_45 ) ;
F_99 ( V_270 , & T_1 -> V_22 , V_272 , NULL ) ;
fprintf ( V_270 , L_44 , V_271 ) ;
}
for ( V_199 = 0 ; V_199 < V_214 -> V_262 ; V_199 ++ ) {
for ( V_200 = 0 ; V_200 < V_198 ; V_200 ++ ) {
int V_273 ;
if ( ! T_1 -> V_213 && ! T_1 -> V_201 )
V_257 = F_103 ( V_216 , V_200 ) ;
V_273 = F_93 ( T_1 , V_199 , V_200 ) ;
V_274:
F_104 ( L_46 ,
V_257 , V_214 -> V_275 [ V_199 ] , V_273 , V_255 ) ;
F_64 ( T_1 , V_199 , V_200 ) = F_105 ( & T_1 -> V_22 ,
V_257 ,
V_214 -> V_275 [ V_199 ] ,
V_273 , V_255 ) ;
if ( F_64 ( T_1 , V_199 , V_200 ) < 0 ) {
V_44 = - V_226 ;
F_104 ( L_47 ,
V_44 ) ;
goto V_276;
}
if ( T_1 -> V_38 >= 0 ) {
int V_277 = F_64 ( T_1 , V_199 , V_200 ) ;
int V_38 = T_1 -> V_38 ;
V_44 = F_66 ( V_277 ,
V_278 ,
V_38 ) ;
if ( V_44 && V_226 != V_279 ) {
F_55 ( L_48 ,
V_38 , strerror ( V_226 ) ) ;
V_44 = - V_7 ;
goto V_280;
}
}
V_261 = V_258 ;
if ( V_145 . V_194 ||
V_145 . V_265 ) {
V_44 = - V_7 ;
goto V_280;
}
}
}
return 0 ;
V_276:
if ( V_44 == - V_281 && V_261 < V_260 ) {
struct V_282 V_283 ;
int V_284 = V_226 ;
if ( F_106 ( V_285 , & V_283 ) == 0 ) {
if ( V_261 == V_258 )
V_283 . V_286 = V_283 . V_287 ;
else {
V_283 . V_286 = V_283 . V_287 + 1000 ;
V_283 . V_287 = V_283 . V_286 ;
}
if ( F_107 ( V_285 , & V_283 ) == 0 ) {
V_261 ++ ;
V_226 = V_284 ;
goto V_274;
}
}
V_226 = V_284 ;
}
if ( V_44 != - V_7 || V_199 > 0 || V_200 > 0 )
goto V_280;
if ( ! V_145 . V_265 && T_1 -> V_22 . V_195 ) {
V_145 . V_265 = true ;
goto V_264;
} else if ( ! V_145 . V_194 && T_1 -> V_22 . V_195 ) {
V_145 . V_194 = true ;
goto V_264;
} else if ( ! V_145 . V_267 && ( V_255 & V_256 ) ) {
V_145 . V_267 = true ;
goto V_264;
} else if ( ! V_145 . V_181 && T_1 -> V_22 . V_181 ) {
V_145 . V_181 = true ;
goto V_264;
} else if ( ! V_145 . V_69 &&
( T_1 -> V_22 . V_69 || T_1 -> V_22 . V_68 ) ) {
V_145 . V_69 = true ;
goto V_264;
} else if ( ! V_145 . V_144 ) {
V_145 . V_144 = true ;
goto V_268;
}
V_280:
do {
while ( -- V_200 >= 0 ) {
F_79 ( F_64 ( T_1 , V_199 , V_200 ) ) ;
F_64 ( T_1 , V_199 , V_200 ) = - 1 ;
}
V_200 = V_198 ;
} while ( -- V_199 >= 0 );
return V_44 ;
}
void F_108 ( struct V_1 * T_1 , int V_197 , int V_198 )
{
if ( T_1 -> V_202 == NULL )
return;
F_78 ( T_1 , V_197 , V_198 ) ;
F_73 ( T_1 ) ;
}
int F_109 ( struct V_1 * T_1 , struct V_253 * V_214 ,
struct V_254 * V_216 )
{
if ( V_214 == NULL ) {
V_214 = & V_288 . V_275 ;
}
if ( V_216 == NULL )
V_216 = & V_289 . V_275 ;
return F_102 ( T_1 , V_214 , V_216 ) ;
}
int F_110 ( struct V_1 * T_1 ,
struct V_253 * V_214 )
{
return F_102 ( T_1 , V_214 , & V_289 . V_275 ) ;
}
int F_111 ( struct V_1 * T_1 ,
struct V_254 * V_216 )
{
return F_102 ( T_1 , & V_288 . V_275 , V_216 ) ;
}
static int F_112 ( const struct V_1 * T_1 ,
const union V_290 * V_291 ,
struct V_292 * V_293 )
{
T_3 type = T_1 -> V_22 . V_8 ;
const T_3 * V_294 = V_291 -> V_293 . V_294 ;
bool V_295 = T_1 -> V_296 ;
union V_297 V_298 ;
V_294 += ( ( V_291 -> V_299 . V_6 -
sizeof( V_291 -> V_299 ) ) / sizeof( T_3 ) ) - 1 ;
if ( type & V_13 ) {
V_293 -> V_53 = * V_294 ;
V_294 -- ;
}
if ( type & V_19 ) {
V_298 . V_300 = * V_294 ;
if ( V_295 ) {
V_298 . V_300 = F_113 ( V_298 . V_300 ) ;
V_298 . V_301 [ 0 ] = F_114 ( V_298 . V_301 [ 0 ] ) ;
}
V_293 -> V_199 = V_298 . V_301 [ 0 ] ;
V_294 -- ;
}
if ( type & V_20 ) {
V_293 -> V_302 = * V_294 ;
V_294 -- ;
}
if ( type & V_14 ) {
V_293 -> V_53 = * V_294 ;
V_294 -- ;
}
if ( type & V_17 ) {
V_293 -> time = * V_294 ;
V_294 -- ;
}
if ( type & V_16 ) {
V_298 . V_300 = * V_294 ;
if ( V_295 ) {
V_298 . V_300 = F_113 ( V_298 . V_300 ) ;
V_298 . V_301 [ 0 ] = F_114 ( V_298 . V_301 [ 0 ] ) ;
V_298 . V_301 [ 1 ] = F_114 ( V_298 . V_301 [ 1 ] ) ;
}
V_293 -> V_257 = V_298 . V_301 [ 0 ] ;
V_293 -> V_303 = V_298 . V_301 [ 1 ] ;
V_294 -- ;
}
return 0 ;
}
static inline bool F_115 ( const void * V_304 , T_12 V_305 , const void * V_306 ,
T_3 V_6 )
{
return V_6 > V_305 || V_306 + V_6 > V_304 ;
}
int F_116 ( struct V_1 * T_1 , union V_290 * V_291 ,
struct V_292 * V_307 )
{
T_3 type = T_1 -> V_22 . V_8 ;
bool V_295 = T_1 -> V_296 ;
const T_3 * V_294 ;
T_12 V_305 = V_291 -> V_299 . V_6 ;
const void * V_304 = ( void * ) V_291 + V_305 ;
T_3 V_308 ;
union V_297 V_298 ;
memset ( V_307 , 0 , sizeof( * V_307 ) ) ;
V_307 -> V_199 = V_307 -> V_257 = V_307 -> V_303 = - 1 ;
V_307 -> V_302 = V_307 -> V_53 = V_307 -> time = - 1ULL ;
V_307 -> V_126 = T_1 -> V_22 . V_54 ;
V_307 -> V_309 = 0 ;
if ( V_291 -> V_299 . type != V_310 ) {
if ( ! T_1 -> V_22 . V_144 )
return 0 ;
return F_112 ( T_1 , V_291 , V_307 ) ;
}
V_294 = V_291 -> V_293 . V_294 ;
if ( T_1 -> V_26 + sizeof( V_291 -> V_299 ) > V_291 -> V_299 . V_6 )
return - V_311 ;
V_307 -> V_53 = - 1ULL ;
if ( type & V_13 ) {
V_307 -> V_53 = * V_294 ;
V_294 ++ ;
}
if ( type & V_15 ) {
V_307 -> V_312 = * V_294 ;
V_294 ++ ;
}
if ( type & V_16 ) {
V_298 . V_300 = * V_294 ;
if ( V_295 ) {
V_298 . V_300 = F_113 ( V_298 . V_300 ) ;
V_298 . V_301 [ 0 ] = F_114 ( V_298 . V_301 [ 0 ] ) ;
V_298 . V_301 [ 1 ] = F_114 ( V_298 . V_301 [ 1 ] ) ;
}
V_307 -> V_257 = V_298 . V_301 [ 0 ] ;
V_307 -> V_303 = V_298 . V_301 [ 1 ] ;
V_294 ++ ;
}
if ( type & V_17 ) {
V_307 -> time = * V_294 ;
V_294 ++ ;
}
V_307 -> V_74 = 0 ;
if ( type & V_18 ) {
V_307 -> V_74 = * V_294 ;
V_294 ++ ;
}
if ( type & V_14 ) {
V_307 -> V_53 = * V_294 ;
V_294 ++ ;
}
if ( type & V_20 ) {
V_307 -> V_302 = * V_294 ;
V_294 ++ ;
}
if ( type & V_19 ) {
V_298 . V_300 = * V_294 ;
if ( V_295 ) {
V_298 . V_300 = F_113 ( V_298 . V_300 ) ;
V_298 . V_301 [ 0 ] = F_114 ( V_298 . V_301 [ 0 ] ) ;
}
V_307 -> V_199 = V_298 . V_301 [ 0 ] ;
V_294 ++ ;
}
if ( type & V_49 ) {
V_307 -> V_126 = * V_294 ;
V_294 ++ ;
}
if ( type & V_313 ) {
T_3 V_30 = T_1 -> V_22 . V_30 ;
F_117 ( V_294 ) ;
if ( V_30 & V_152 )
V_307 -> V_314 . V_315 . V_262 = * V_294 ;
else
V_307 -> V_314 . V_316 . V_229 = * V_294 ;
V_294 ++ ;
if ( V_30 & V_188 ) {
F_117 ( V_294 ) ;
V_307 -> V_314 . V_317 = * V_294 ;
V_294 ++ ;
}
if ( V_30 & V_189 ) {
F_117 ( V_294 ) ;
V_307 -> V_314 . V_318 = * V_294 ;
V_294 ++ ;
}
if ( V_30 & V_152 ) {
const T_3 V_319 = V_320 /
sizeof( struct V_321 ) ;
if ( V_307 -> V_314 . V_315 . V_262 > V_319 )
return - V_311 ;
V_308 = V_307 -> V_314 . V_315 . V_262 *
sizeof( struct V_321 ) ;
F_118 ( V_294 , V_308 , V_305 ) ;
V_307 -> V_314 . V_315 . V_322 =
(struct V_321 * ) V_294 ;
V_294 = ( void * ) V_294 + V_308 ;
} else {
F_117 ( V_294 ) ;
V_307 -> V_314 . V_316 . V_53 = * V_294 ;
V_294 ++ ;
}
}
if ( type & V_323 ) {
const T_3 V_324 = V_320 / sizeof( T_3 ) ;
F_117 ( V_294 ) ;
V_307 -> V_325 = (struct V_326 * ) V_294 ++ ;
if ( V_307 -> V_325 -> V_262 > V_324 )
return - V_311 ;
V_308 = V_307 -> V_325 -> V_262 * sizeof( T_3 ) ;
F_118 ( V_294 , V_308 , V_305 ) ;
V_294 = ( void * ) V_294 + V_308 ;
}
if ( type & V_48 ) {
F_117 ( V_294 ) ;
V_298 . V_300 = * V_294 ;
if ( F_119 ( V_295 ,
L_49 ) ) {
V_298 . V_300 = F_113 ( V_298 . V_300 ) ;
V_298 . V_301 [ 0 ] = F_114 ( V_298 . V_301 [ 0 ] ) ;
V_298 . V_301 [ 1 ] = F_114 ( V_298 . V_301 [ 1 ] ) ;
}
V_307 -> V_327 = V_298 . V_301 [ 0 ] ;
V_294 = ( void * ) V_294 + sizeof( T_7 ) ;
F_118 ( V_294 , V_307 -> V_327 , V_305 ) ;
V_307 -> V_328 = ( void * ) V_294 ;
V_294 = ( void * ) V_294 + V_307 -> V_327 ;
}
if ( type & V_329 ) {
const T_3 V_330 = V_320 /
sizeof( struct V_331 ) ;
F_117 ( V_294 ) ;
V_307 -> V_107 = (struct V_107 * ) V_294 ++ ;
if ( V_307 -> V_107 -> V_262 > V_330 )
return - V_311 ;
V_308 = V_307 -> V_107 -> V_262 * sizeof( struct V_331 ) ;
F_118 ( V_294 , V_308 , V_305 ) ;
V_294 = ( void * ) V_294 + V_308 ;
}
if ( type & V_332 ) {
F_117 ( V_294 ) ;
V_307 -> V_333 . V_334 = * V_294 ;
V_294 ++ ;
if ( V_307 -> V_333 . V_334 ) {
T_3 V_9 = T_1 -> V_22 . V_115 ;
V_308 = F_120 ( V_9 ) * sizeof( T_3 ) ;
F_118 ( V_294 , V_308 , V_305 ) ;
V_307 -> V_333 . V_9 = V_9 ;
V_307 -> V_333 . V_335 = ( T_3 * ) V_294 ;
V_294 = ( void * ) V_294 + V_308 ;
}
}
if ( type & V_336 ) {
F_117 ( V_294 ) ;
V_308 = * V_294 ++ ;
V_307 -> V_337 . V_306 = ( ( char * ) ( V_294 - 1 )
- ( char * ) V_291 ) ;
if ( ! V_308 ) {
V_307 -> V_337 . V_6 = 0 ;
} else {
F_118 ( V_294 , V_308 , V_305 ) ;
V_307 -> V_337 . V_307 = ( char * ) V_294 ;
V_294 = ( void * ) V_294 + V_308 ;
F_117 ( V_294 ) ;
V_307 -> V_337 . V_6 = * V_294 ++ ;
if ( F_119 ( V_307 -> V_337 . V_6 > V_308 ,
L_50 ) )
return - V_311 ;
}
}
V_307 -> V_309 = 0 ;
if ( type & V_338 ) {
F_117 ( V_294 ) ;
V_307 -> V_309 = * V_294 ;
V_294 ++ ;
}
V_307 -> V_339 = V_340 ;
if ( type & V_341 ) {
F_117 ( V_294 ) ;
V_307 -> V_339 = * V_294 ;
V_294 ++ ;
}
V_307 -> V_342 = 0 ;
if ( type & V_343 ) {
F_117 ( V_294 ) ;
V_307 -> V_342 = * V_294 ;
V_294 ++ ;
}
V_307 -> V_344 . V_334 = V_345 ;
if ( type & V_346 ) {
F_117 ( V_294 ) ;
V_307 -> V_344 . V_334 = * V_294 ;
V_294 ++ ;
if ( V_307 -> V_344 . V_334 != V_345 ) {
T_3 V_9 = T_1 -> V_22 . V_166 ;
V_308 = F_120 ( V_9 ) * sizeof( T_3 ) ;
F_118 ( V_294 , V_308 , V_305 ) ;
V_307 -> V_344 . V_9 = V_9 ;
V_307 -> V_344 . V_335 = ( T_3 * ) V_294 ;
V_294 = ( void * ) V_294 + V_308 ;
}
}
return 0 ;
}
T_2 F_121 ( const struct V_292 * V_293 , T_3 type ,
T_3 V_30 )
{
T_2 V_308 , V_83 = sizeof( struct V_347 ) ;
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
if ( type & V_313 ) {
V_83 += sizeof( T_3 ) ;
if ( V_30 & V_188 )
V_83 += sizeof( T_3 ) ;
if ( V_30 & V_189 )
V_83 += sizeof( T_3 ) ;
if ( V_30 & V_152 ) {
V_308 = V_293 -> V_314 . V_315 . V_262 *
sizeof( struct V_321 ) ;
V_83 += V_308 ;
} else {
V_83 += sizeof( T_3 ) ;
}
}
if ( type & V_323 ) {
V_308 = ( V_293 -> V_325 -> V_262 + 1 ) * sizeof( T_3 ) ;
V_83 += V_308 ;
}
if ( type & V_48 ) {
V_83 += sizeof( T_7 ) ;
V_83 += V_293 -> V_327 ;
}
if ( type & V_329 ) {
V_308 = V_293 -> V_107 -> V_262 * sizeof( struct V_331 ) ;
V_308 += sizeof( T_3 ) ;
V_83 += V_308 ;
}
if ( type & V_332 ) {
if ( V_293 -> V_333 . V_334 ) {
V_83 += sizeof( T_3 ) ;
V_308 = F_120 ( V_293 -> V_333 . V_9 ) * sizeof( T_3 ) ;
V_83 += V_308 ;
} else {
V_83 += sizeof( T_3 ) ;
}
}
if ( type & V_336 ) {
V_308 = V_293 -> V_337 . V_6 ;
V_83 += sizeof( T_3 ) ;
if ( V_308 ) {
V_83 += V_308 ;
V_83 += sizeof( T_3 ) ;
}
}
if ( type & V_338 )
V_83 += sizeof( T_3 ) ;
if ( type & V_341 )
V_83 += sizeof( T_3 ) ;
if ( type & V_343 )
V_83 += sizeof( T_3 ) ;
if ( type & V_346 ) {
if ( V_293 -> V_344 . V_334 ) {
V_83 += sizeof( T_3 ) ;
V_308 = F_120 ( V_293 -> V_344 . V_9 ) * sizeof( T_3 ) ;
V_83 += V_308 ;
} else {
V_83 += sizeof( T_3 ) ;
}
}
return V_83 ;
}
int F_122 ( union V_290 * V_291 , T_3 type ,
T_3 V_30 ,
const struct V_292 * V_293 ,
bool V_295 )
{
T_3 * V_294 ;
T_2 V_308 ;
union V_297 V_298 ;
V_294 = V_291 -> V_293 . V_294 ;
if ( type & V_13 ) {
* V_294 = V_293 -> V_53 ;
V_294 ++ ;
}
if ( type & V_15 ) {
* V_294 = V_293 -> V_312 ;
V_294 ++ ;
}
if ( type & V_16 ) {
V_298 . V_301 [ 0 ] = V_293 -> V_257 ;
V_298 . V_301 [ 1 ] = V_293 -> V_303 ;
if ( V_295 ) {
V_298 . V_301 [ 0 ] = F_114 ( V_298 . V_301 [ 0 ] ) ;
V_298 . V_301 [ 1 ] = F_114 ( V_298 . V_301 [ 1 ] ) ;
V_298 . V_300 = F_113 ( V_298 . V_300 ) ;
}
* V_294 = V_298 . V_300 ;
V_294 ++ ;
}
if ( type & V_17 ) {
* V_294 = V_293 -> time ;
V_294 ++ ;
}
if ( type & V_18 ) {
* V_294 = V_293 -> V_74 ;
V_294 ++ ;
}
if ( type & V_14 ) {
* V_294 = V_293 -> V_53 ;
V_294 ++ ;
}
if ( type & V_20 ) {
* V_294 = V_293 -> V_302 ;
V_294 ++ ;
}
if ( type & V_19 ) {
V_298 . V_301 [ 0 ] = V_293 -> V_199 ;
if ( V_295 ) {
V_298 . V_301 [ 0 ] = F_114 ( V_298 . V_301 [ 0 ] ) ;
V_298 . V_300 = F_113 ( V_298 . V_300 ) ;
}
* V_294 = V_298 . V_300 ;
V_294 ++ ;
}
if ( type & V_49 ) {
* V_294 = V_293 -> V_126 ;
V_294 ++ ;
}
if ( type & V_313 ) {
if ( V_30 & V_152 )
* V_294 = V_293 -> V_314 . V_315 . V_262 ;
else
* V_294 = V_293 -> V_314 . V_316 . V_229 ;
V_294 ++ ;
if ( V_30 & V_188 ) {
* V_294 = V_293 -> V_314 . V_317 ;
V_294 ++ ;
}
if ( V_30 & V_189 ) {
* V_294 = V_293 -> V_314 . V_318 ;
V_294 ++ ;
}
if ( V_30 & V_152 ) {
V_308 = V_293 -> V_314 . V_315 . V_262 *
sizeof( struct V_321 ) ;
memcpy ( V_294 , V_293 -> V_314 . V_315 . V_322 , V_308 ) ;
V_294 = ( void * ) V_294 + V_308 ;
} else {
* V_294 = V_293 -> V_314 . V_316 . V_53 ;
V_294 ++ ;
}
}
if ( type & V_323 ) {
V_308 = ( V_293 -> V_325 -> V_262 + 1 ) * sizeof( T_3 ) ;
memcpy ( V_294 , V_293 -> V_325 , V_308 ) ;
V_294 = ( void * ) V_294 + V_308 ;
}
if ( type & V_48 ) {
V_298 . V_301 [ 0 ] = V_293 -> V_327 ;
if ( F_119 ( V_295 ,
L_49 ) ) {
V_298 . V_301 [ 0 ] = F_114 ( V_298 . V_301 [ 0 ] ) ;
V_298 . V_301 [ 1 ] = F_114 ( V_298 . V_301 [ 1 ] ) ;
V_298 . V_300 = F_113 ( V_298 . V_300 ) ;
}
* V_294 = V_298 . V_300 ;
V_294 = ( void * ) V_294 + sizeof( T_7 ) ;
memcpy ( V_294 , V_293 -> V_328 , V_293 -> V_327 ) ;
V_294 = ( void * ) V_294 + V_293 -> V_327 ;
}
if ( type & V_329 ) {
V_308 = V_293 -> V_107 -> V_262 * sizeof( struct V_331 ) ;
V_308 += sizeof( T_3 ) ;
memcpy ( V_294 , V_293 -> V_107 , V_308 ) ;
V_294 = ( void * ) V_294 + V_308 ;
}
if ( type & V_332 ) {
if ( V_293 -> V_333 . V_334 ) {
* V_294 ++ = V_293 -> V_333 . V_334 ;
V_308 = F_120 ( V_293 -> V_333 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_294 , V_293 -> V_333 . V_335 , V_308 ) ;
V_294 = ( void * ) V_294 + V_308 ;
} else {
* V_294 ++ = 0 ;
}
}
if ( type & V_336 ) {
V_308 = V_293 -> V_337 . V_6 ;
* V_294 ++ = V_308 ;
if ( V_308 ) {
memcpy ( V_294 , V_293 -> V_337 . V_307 , V_308 ) ;
V_294 = ( void * ) V_294 + V_308 ;
* V_294 ++ = V_308 ;
}
}
if ( type & V_338 ) {
* V_294 = V_293 -> V_309 ;
V_294 ++ ;
}
if ( type & V_341 ) {
* V_294 = V_293 -> V_339 ;
V_294 ++ ;
}
if ( type & V_343 ) {
* V_294 = V_293 -> V_342 ;
V_294 ++ ;
}
if ( type & V_346 ) {
if ( V_293 -> V_344 . V_334 ) {
* V_294 ++ = V_293 -> V_344 . V_334 ;
V_308 = F_120 ( V_293 -> V_344 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_294 , V_293 -> V_344 . V_335 , V_308 ) ;
V_294 = ( void * ) V_294 + V_308 ;
} else {
* V_294 ++ = 0 ;
}
}
return 0 ;
}
struct V_348 * F_123 ( struct V_1 * T_1 , const char * V_43 )
{
return F_124 ( T_1 -> V_51 , V_43 ) ;
}
void * F_125 ( struct V_1 * T_1 , struct V_292 * V_293 ,
const char * V_43 )
{
struct V_348 * V_349 = F_123 ( T_1 , V_43 ) ;
int V_306 ;
if ( ! V_349 )
return NULL ;
V_306 = V_349 -> V_306 ;
if ( V_349 -> V_255 & V_350 ) {
V_306 = * ( int * ) ( V_293 -> V_328 + V_349 -> V_306 ) ;
V_306 &= 0xffff ;
}
return V_293 -> V_328 + V_306 ;
}
T_3 F_126 ( struct V_1 * T_1 , struct V_292 * V_293 ,
const char * V_43 )
{
struct V_348 * V_349 = F_123 ( T_1 , V_43 ) ;
void * V_351 ;
T_3 V_229 ;
if ( ! V_349 )
return 0 ;
V_351 = V_293 -> V_328 + V_349 -> V_306 ;
switch ( V_349 -> V_6 ) {
case 1 :
return * ( T_6 * ) V_351 ;
case 2 :
V_229 = * ( T_12 * ) V_351 ;
break;
case 4 :
V_229 = * ( T_7 * ) V_351 ;
break;
case 8 :
memcpy ( & V_229 , V_351 , sizeof( T_3 ) ) ;
break;
default:
return 0 ;
}
if ( ! T_1 -> V_296 )
return V_229 ;
switch ( V_349 -> V_6 ) {
case 2 :
return F_127 ( V_229 ) ;
case 4 :
return F_114 ( V_229 ) ;
case 8 :
return F_113 ( V_229 ) ;
default:
return 0 ;
}
return 0 ;
}
static int F_128 ( T_10 * V_237 , bool * V_352 , const char * V_353 , ... )
{
T_13 args ;
int V_90 = 0 ;
if ( ! * V_352 ) {
V_90 += fprintf ( V_237 , L_51 ) ;
} else {
V_90 += fprintf ( V_237 , L_9 ) ;
* V_352 = false ;
}
va_start ( args , V_353 ) ;
V_90 += vfprintf ( V_237 , V_353 , args ) ;
va_end ( args ) ;
return V_90 ;
}
static int F_129 ( T_10 * V_237 , const char * V_43 , const char * V_125 , void * V_239 )
{
return F_128 ( V_237 , ( bool * ) V_239 , L_52 , V_43 , V_125 ) ;
}
int F_130 ( struct V_1 * T_1 ,
struct V_354 * V_355 , T_10 * V_237 )
{
bool V_352 = true ;
int V_356 = 0 ;
if ( V_355 -> V_357 ) {
struct V_1 * V_98 ;
if ( ! F_59 ( T_1 ) )
return 0 ;
if ( T_1 -> V_151 > 1 )
V_356 += fprintf ( V_237 , L_53 , T_1 -> V_96 ? : L_1 ) ;
V_356 += fprintf ( V_237 , L_6 , F_42 ( T_1 ) ) ;
F_46 (pos, evsel)
V_356 += fprintf ( V_237 , L_54 , F_42 ( V_98 ) ) ;
if ( T_1 -> V_151 > 1 )
V_356 += fprintf ( V_237 , L_55 ) ;
goto V_358;
}
V_356 += fprintf ( V_237 , L_6 , F_42 ( T_1 ) ) ;
if ( V_355 -> V_269 ) {
V_356 += F_99 ( V_237 , & T_1 -> V_22 ,
F_129 , & V_352 ) ;
} else if ( V_355 -> V_127 ) {
const char * V_121 = L_56 ;
if ( ! T_1 -> V_22 . V_127 )
V_121 = L_57 ;
V_356 += F_128 ( V_237 , & V_352 , L_58 V_359 ,
V_121 , ( T_3 ) T_1 -> V_22 . V_129 ) ;
}
V_358:
fputc ( '\n' , V_237 ) ;
return ++ V_356 ;
}
bool F_131 ( struct V_1 * T_1 , int V_44 ,
char * V_360 , T_2 V_361 )
{
if ( ( V_44 == V_362 || V_44 == V_363 || V_44 == V_364 ) &&
T_1 -> V_22 . type == V_92 &&
T_1 -> V_22 . V_52 == V_365 ) {
F_30 ( V_360 , V_361 , L_6 ,
L_59 ) ;
T_1 -> V_22 . type = V_94 ;
T_1 -> V_22 . V_52 = V_366 ;
F_25 ( & T_1 -> V_43 ) ;
return true ;
}
return false ;
}
int F_132 ( struct V_1 * T_1 , struct V_141 * V_141 ,
int V_44 , char * V_360 , T_2 V_6 )
{
char V_367 [ V_368 ] ;
switch ( V_44 ) {
case V_369 :
case V_370 :
return F_30 ( V_360 , V_6 ,
L_60
L_61
L_62
L_63
L_64
L_65 ,
V_141 -> V_201 ? L_66 : L_1 ) ;
case V_362 :
return F_30 ( V_360 , V_6 , L_67 ,
F_42 ( T_1 ) ) ;
case V_281 :
return F_30 ( V_360 , V_6 , L_6 ,
L_68
L_69
L_70
L_71 ) ;
case V_364 :
if ( V_141 -> V_371 )
return F_30 ( V_360 , V_6 , L_6 ,
L_72 ) ;
break;
case V_372 :
if ( T_1 -> V_22 . V_67 )
return F_30 ( V_360 , V_6 , L_6 ,
L_73 ) ;
#if F_133 ( V_373 ) || F_133 ( V_374 )
if ( T_1 -> V_22 . type == V_92 )
return F_30 ( V_360 , V_6 , L_6 ,
L_74
L_75 ) ;
#endif
break;
case V_375 :
if ( F_134 ( L_76 ) )
return F_30 ( V_360 , V_6 ,
L_77
L_78 ) ;
break;
case V_7 :
if ( V_145 . V_194 )
return F_30 ( V_360 , V_6 , L_79 ) ;
if ( V_145 . V_265 )
return F_30 ( V_360 , V_6 , L_80 , V_194 ) ;
break;
default:
break;
}
return F_30 ( V_360 , V_6 ,
L_81
L_82
L_83 ,
V_44 , F_135 ( V_44 , V_367 , sizeof( V_367 ) ) ,
F_42 ( T_1 ) ) ;
}
