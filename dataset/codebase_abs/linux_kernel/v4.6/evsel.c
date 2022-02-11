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
if ( F_19 ( T_1 ) ) {
T_1 -> V_22 . V_8 |= V_42 ;
T_1 -> V_22 . V_43 = 1 ;
}
return T_1 ;
}
struct V_1 * F_20 ( const char * V_44 , const char * V_45 , int V_12 )
{
struct V_1 * T_1 = F_18 ( V_5 . V_6 ) ;
int V_46 = - V_47 ;
if ( T_1 == NULL ) {
goto V_48;
} else {
struct V_32 V_22 = {
. type = V_49 ,
. V_8 = ( V_42 | V_17 |
V_19 | V_50 ) ,
} ;
if ( F_21 ( & T_1 -> V_45 , L_2 , V_44 , V_45 ) < 0 )
goto V_51;
T_1 -> V_52 = F_22 ( V_44 , V_45 ) ;
if ( F_23 ( T_1 -> V_52 ) ) {
V_46 = F_24 ( T_1 -> V_52 ) ;
goto V_51;
}
F_25 ( & V_22 ) ;
V_22 . V_53 = T_1 -> V_52 -> V_54 ;
V_22 . V_43 = 1 ;
F_15 ( T_1 , & V_22 , V_12 ) ;
}
return T_1 ;
V_51:
F_26 ( & T_1 -> V_45 ) ;
free ( T_1 ) ;
V_48:
return F_27 ( V_46 ) ;
}
static const char * F_28 ( T_3 V_53 )
{
if ( V_53 < V_55 && V_56 [ V_53 ] )
return V_56 [ V_53 ] ;
return L_3 ;
}
static int F_29 ( struct V_1 * T_1 , char * V_57 , T_2 V_6 )
{
int V_58 = 0 , V_59 = 0 ;
struct V_32 * V_22 = & T_1 -> V_22 ;
bool V_60 = false ;
#define F_30 ( T_4 , T_5 ) do { \
if (!attr->exclude_##context) { \
if (!colon) colon = ++r; \
r += scnprintf(bf + r, size - r, "%c", mod); \
} } while(0)
if ( V_22 -> V_61 || V_22 -> V_62 || V_22 -> V_63 ) {
F_30 ( V_64 , 'k' ) ;
F_30 ( V_65 , 'u' ) ;
F_30 ( V_66 , 'h' ) ;
V_60 = true ;
}
if ( V_22 -> V_67 ) {
if ( ! V_58 )
V_58 = ++ V_59 ;
V_59 += F_31 ( V_57 + V_59 , V_6 - V_59 , L_4 , V_22 -> V_67 , L_5 ) ;
V_60 = true ;
}
if ( V_22 -> V_68 || V_22 -> V_69 == V_60 ) {
F_30 ( V_70 , 'H' ) ;
F_30 ( V_71 , 'G' ) ;
}
#undef F_30
if ( V_58 )
V_57 [ V_58 - 1 ] = ':' ;
return V_59 ;
}
static int F_32 ( struct V_1 * T_1 , char * V_57 , T_2 V_6 )
{
int V_59 = F_31 ( V_57 , V_6 , L_6 , F_28 ( T_1 -> V_22 . V_53 ) ) ;
return V_59 + F_29 ( T_1 , V_57 + V_59 , V_6 - V_59 ) ;
}
static const char * F_33 ( T_3 V_53 )
{
if ( V_53 < V_72 && V_73 [ V_53 ] )
return V_73 [ V_53 ] ;
return L_7 ;
}
static int F_34 ( struct V_1 * T_1 , char * V_57 , T_2 V_6 )
{
int V_59 = F_31 ( V_57 , V_6 , L_6 , F_33 ( T_1 -> V_22 . V_53 ) ) ;
return V_59 + F_29 ( T_1 , V_57 + V_59 , V_6 - V_59 ) ;
}
static int F_35 ( char * V_57 , T_2 V_6 , T_3 V_74 , T_3 type )
{
int V_59 ;
V_59 = F_31 ( V_57 , V_6 , L_8 V_75 L_9 , V_74 ) ;
if ( type & V_76 )
V_59 += F_31 ( V_57 + V_59 , V_6 - V_59 , L_10 ) ;
if ( type & V_77 )
V_59 += F_31 ( V_57 + V_59 , V_6 - V_59 , L_11 ) ;
if ( type & V_78 )
V_59 += F_31 ( V_57 + V_59 , V_6 - V_59 , L_12 ) ;
return V_59 ;
}
static int F_36 ( struct V_1 * T_1 , char * V_57 , T_2 V_6 )
{
struct V_32 * V_22 = & T_1 -> V_22 ;
int V_59 = F_35 ( V_57 , V_6 , V_22 -> V_79 , V_22 -> V_80 ) ;
return V_59 + F_29 ( T_1 , V_57 + V_59 , V_6 - V_59 ) ;
}
bool F_37 ( T_6 type , T_6 V_81 )
{
if ( V_82 [ type ] & F_38 ( V_81 ) )
return true ;
else
return false ;
}
int F_39 ( T_6 type , T_6 V_81 , T_6 V_83 ,
char * V_57 , T_2 V_6 )
{
if ( V_83 ) {
return F_31 ( V_57 , V_6 , L_13 , V_84 [ type ] [ 0 ] ,
V_85 [ V_81 ] [ 0 ] ,
V_86 [ V_83 ] [ 0 ] ) ;
}
return F_31 ( V_57 , V_6 , L_14 , V_84 [ type ] [ 0 ] ,
V_85 [ V_81 ] [ 1 ] ) ;
}
static int F_40 ( T_3 V_53 , char * V_57 , T_2 V_6 )
{
T_6 V_81 , V_83 , type = ( V_53 >> 0 ) & 0xff ;
const char * V_46 = L_15 ;
if ( type > V_87 )
goto V_48;
V_81 = ( V_53 >> 8 ) & 0xff ;
V_46 = L_16 ;
if ( V_81 > V_88 )
goto V_48;
V_83 = ( V_53 >> 16 ) & 0xff ;
V_46 = L_17 ;
if ( V_83 > V_89 )
goto V_48;
V_46 = L_18 ;
if ( ! F_37 ( type , V_81 ) )
goto V_48;
return F_39 ( type , V_81 , V_83 , V_57 , V_6 ) ;
V_48:
return F_31 ( V_57 , V_6 , L_6 , V_46 ) ;
}
static int F_41 ( struct V_1 * T_1 , char * V_57 , T_2 V_6 )
{
int V_90 = F_40 ( T_1 -> V_22 . V_53 , V_57 , V_6 ) ;
return V_90 + F_29 ( T_1 , V_57 + V_90 , V_6 - V_90 ) ;
}
static int F_42 ( struct V_1 * T_1 , char * V_57 , T_2 V_6 )
{
int V_90 = F_31 ( V_57 , V_6 , L_19 V_75 , T_1 -> V_22 . V_53 ) ;
return V_90 + F_29 ( T_1 , V_57 + V_90 , V_6 - V_90 ) ;
}
const char * F_43 ( struct V_1 * T_1 )
{
char V_57 [ 128 ] ;
if ( T_1 -> V_45 )
return T_1 -> V_45 ;
switch ( T_1 -> V_22 . type ) {
case V_91 :
F_42 ( T_1 , V_57 , sizeof( V_57 ) ) ;
break;
case V_92 :
F_32 ( T_1 , V_57 , sizeof( V_57 ) ) ;
break;
case V_93 :
F_41 ( T_1 , V_57 , sizeof( V_57 ) ) ;
break;
case V_94 :
F_34 ( T_1 , V_57 , sizeof( V_57 ) ) ;
break;
case V_49 :
F_31 ( V_57 , sizeof( V_57 ) , L_6 , L_20 ) ;
break;
case V_95 :
F_36 ( T_1 , V_57 , sizeof( V_57 ) ) ;
break;
default:
F_31 ( V_57 , sizeof( V_57 ) , L_21 ,
T_1 -> V_22 . type ) ;
break;
}
T_1 -> V_45 = F_44 ( V_57 ) ;
return T_1 -> V_45 ? : L_22 ;
}
const char * F_45 ( struct V_1 * T_1 )
{
return T_1 -> V_96 ? : L_23 ;
}
int F_46 ( struct V_1 * T_1 , char * V_97 , T_2 V_6 )
{
int V_90 ;
struct V_1 * V_98 ;
const char * V_96 = F_45 ( T_1 ) ;
V_90 = F_31 ( V_97 , V_6 , L_6 , V_96 ) ;
V_90 += F_31 ( V_97 + V_90 , V_6 - V_90 , L_24 ,
F_43 ( T_1 ) ) ;
F_47 (pos, evsel)
V_90 += F_31 ( V_97 + V_90 , V_6 - V_90 , L_25 ,
F_43 ( V_98 ) ) ;
V_90 += F_31 ( V_97 + V_90 , V_6 - V_90 , L_26 ) ;
return V_90 ;
}
static void
F_48 ( struct V_1 * T_1 ,
struct V_99 * V_100 ,
struct V_101 * V_102 )
{
bool V_103 = F_49 ( T_1 ) ;
struct V_32 * V_22 = & T_1 -> V_22 ;
F_14 ( T_1 , V_104 ) ;
if ( V_102 -> V_105 == V_106 ) {
if ( ! V_100 -> V_107 ) {
if ( V_22 -> V_62 ) {
F_50 ( L_27
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
F_50 ( L_30
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
F_51 ( L_31
L_32 ) ;
}
}
if ( V_103 ) {
F_51 ( L_33 ) ;
V_22 -> V_121 = 1 ;
}
}
static void
F_52 ( struct V_1 * T_1 ,
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
static void F_53 ( struct V_1 * T_1 ,
struct V_99 * V_100 )
{
struct V_122 * V_123 ;
struct V_124 * V_40 = & T_1 -> V_40 ;
struct V_32 * V_22 = & T_1 -> V_22 ;
struct V_101 V_102 ;
T_7 V_120 = 0 ;
char * V_125 = NULL ;
V_102 . V_105 = V_101 . V_105 ;
F_54 (term, config_terms, list) {
switch ( V_123 -> type ) {
case V_126 :
V_22 -> V_43 = V_123 -> V_127 . V_128 ;
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
if ( F_55 ( V_125 , & V_102 ) ) {
F_56 ( L_35
L_36 ,
T_1 -> V_45 ) ;
return;
}
}
}
if ( V_120 > 0 ) {
V_120 = F_57 ( V_120 , sizeof( T_3 ) ) ;
V_102 . V_120 = V_120 ;
}
if ( V_101 . V_139 )
F_52 ( T_1 , & V_101 ) ;
if ( V_102 . V_139 )
F_48 ( T_1 , V_100 , & V_102 ) ;
}
}
void F_58 ( struct V_1 * T_1 , struct V_99 * V_100 )
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
if ( ! V_22 -> V_43 || ( V_100 -> V_155 != V_156 ||
V_100 -> V_157 != V_158 ) ) {
if ( V_100 -> V_129 ) {
F_14 ( T_1 , V_159 ) ;
V_22 -> V_129 = 1 ;
V_22 -> V_131 = V_100 -> V_129 ;
} else {
V_22 -> V_43 = V_100 -> V_160 ;
}
}
if ( ( V_34 != T_1 ) && V_34 -> V_151 ) {
V_22 -> V_131 = 0 ;
V_22 -> V_43 = 0 ;
}
if ( V_100 -> V_161 )
V_22 -> V_131 = 0 ;
if ( V_100 -> V_162 )
V_22 -> V_162 = 1 ;
if ( V_100 -> V_163 ) {
F_14 ( T_1 , V_164 ) ;
V_22 -> V_165 = V_141 ;
}
if ( F_49 ( T_1 ) )
T_1 -> V_22 . V_121 = 1 ;
if ( V_101 . V_139 && ! T_1 -> V_166 )
F_48 ( T_1 , V_100 , & V_101 ) ;
if ( V_100 -> V_167 ) {
V_22 -> V_168 = V_100 -> V_167 ;
F_14 ( T_1 , V_169 ) ;
}
if ( F_59 ( & V_100 -> V_143 ) )
F_14 ( T_1 , V_170 ) ;
if ( V_100 -> V_128 )
F_14 ( T_1 , V_159 ) ;
if ( V_100 -> V_171 &&
( ! V_147 . V_146 &&
( ! V_100 -> V_148 || F_59 ( & V_100 -> V_143 ) || V_142 ||
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
if ( F_60 ( T_1 ) )
V_22 -> V_192 = 1 ;
if ( F_61 ( & V_100 -> V_143 ) && F_60 ( T_1 ) &&
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
F_62 ( V_22 ) ;
if ( V_100 -> V_199 ) {
V_22 -> V_61 = 1 ;
V_22 -> V_62 = 0 ;
}
if ( V_100 -> V_200 ) {
V_22 -> V_61 = 0 ;
V_22 -> V_62 = 1 ;
}
F_53 ( T_1 , V_100 ) ;
}
static int F_63 ( struct V_1 * T_1 , int V_201 , int V_202 )
{
int V_203 , V_204 ;
if ( T_1 -> V_205 )
V_202 = 1 ;
T_1 -> V_206 = F_64 ( V_201 , V_202 , sizeof( int ) ) ;
if ( T_1 -> V_206 ) {
for ( V_203 = 0 ; V_203 < V_201 ; V_203 ++ ) {
for ( V_204 = 0 ; V_204 < V_202 ; V_204 ++ ) {
F_65 ( T_1 , V_203 , V_204 ) = - 1 ;
}
}
}
return T_1 -> V_206 != NULL ? 0 : - V_47 ;
}
static int F_66 ( struct V_1 * T_1 , int V_201 , int V_202 ,
int V_207 , void * V_208 )
{
int V_203 , V_204 ;
if ( T_1 -> V_205 )
V_202 = 1 ;
for ( V_203 = 0 ; V_203 < V_201 ; V_203 ++ ) {
for ( V_204 = 0 ; V_204 < V_202 ; V_204 ++ ) {
int V_206 = F_65 ( T_1 , V_203 , V_204 ) ,
V_46 = F_67 ( V_206 , V_207 , V_208 ) ;
if ( V_46 )
return V_46 ;
}
}
return 0 ;
}
int F_68 ( struct V_1 * T_1 , int V_201 , int V_202 ,
const char * V_209 )
{
return F_66 ( T_1 , V_201 , V_202 ,
V_210 ,
( void * ) V_209 ) ;
}
int F_69 ( struct V_1 * T_1 , const char * V_209 )
{
char * V_211 = F_44 ( V_209 ) ;
if ( V_211 != NULL ) {
free ( T_1 -> V_209 ) ;
T_1 -> V_209 = V_211 ;
return 0 ;
}
return - 1 ;
}
int F_70 ( struct V_1 * T_1 ,
const char * V_81 , const char * V_209 )
{
char * V_211 ;
if ( T_1 -> V_209 == NULL )
return F_69 ( T_1 , V_209 ) ;
if ( F_21 ( & V_211 , L_37 , T_1 -> V_209 , V_81 , V_209 ) > 0 ) {
free ( T_1 -> V_209 ) ;
T_1 -> V_209 = V_211 ;
return 0 ;
}
return - 1 ;
}
int F_71 ( struct V_1 * T_1 )
{
int V_202 = F_72 ( T_1 -> V_212 ) ;
int V_201 = F_73 ( T_1 -> V_213 ) ;
return F_66 ( T_1 , V_201 , V_202 ,
V_214 ,
0 ) ;
}
int F_74 ( struct V_1 * T_1 )
{
int V_202 = F_72 ( T_1 -> V_212 ) ;
int V_201 = F_73 ( T_1 -> V_213 ) ;
return F_66 ( T_1 , V_201 , V_202 ,
V_215 ,
0 ) ;
}
int F_75 ( struct V_1 * T_1 , int V_201 , int V_202 )
{
if ( V_201 == 0 || V_202 == 0 )
return 0 ;
if ( T_1 -> V_205 )
V_202 = 1 ;
T_1 -> V_216 = F_64 ( V_201 , V_202 , sizeof( struct V_217 ) ) ;
if ( T_1 -> V_216 == NULL )
return - V_47 ;
T_1 -> V_54 = F_18 ( V_201 * V_202 * sizeof( T_3 ) ) ;
if ( T_1 -> V_54 == NULL ) {
F_76 ( T_1 -> V_216 ) ;
T_1 -> V_216 = NULL ;
return - V_47 ;
}
return 0 ;
}
static void F_77 ( struct V_1 * T_1 )
{
F_76 ( T_1 -> V_206 ) ;
T_1 -> V_206 = NULL ;
}
static void F_78 ( struct V_1 * T_1 )
{
F_76 ( T_1 -> V_216 ) ;
T_1 -> V_216 = NULL ;
F_26 ( & T_1 -> V_54 ) ;
}
static void F_79 ( struct V_1 * T_1 )
{
struct V_122 * V_123 , * V_218 ;
F_80 (term, h, &evsel->config_terms, list) {
F_81 ( & V_123 -> V_219 ) ;
free ( V_123 ) ;
}
}
void F_82 ( struct V_1 * T_1 , int V_201 , int V_202 )
{
int V_203 , V_204 ;
if ( T_1 -> V_205 )
V_202 = 1 ;
for ( V_203 = 0 ; V_203 < V_201 ; V_203 ++ )
for ( V_204 = 0 ; V_204 < V_202 ; ++ V_204 ) {
F_83 ( F_65 ( T_1 , V_203 , V_204 ) ) ;
F_65 ( T_1 , V_203 , V_204 ) = - 1 ;
}
}
void F_84 ( struct V_1 * T_1 )
{
assert ( F_85 ( & T_1 -> V_39 ) ) ;
assert ( T_1 -> V_37 == NULL ) ;
F_77 ( T_1 ) ;
F_78 ( T_1 ) ;
F_79 ( T_1 ) ;
F_86 ( T_1 -> V_220 ) ;
F_87 ( T_1 -> V_213 ) ;
F_87 ( T_1 -> V_221 ) ;
F_88 ( T_1 -> V_212 ) ;
F_26 ( & T_1 -> V_96 ) ;
F_26 ( & T_1 -> V_45 ) ;
V_5 . F_5 ( T_1 ) ;
}
void F_89 ( struct V_1 * T_1 )
{
F_84 ( T_1 ) ;
free ( T_1 ) ;
}
void F_90 ( struct V_1 * T_1 , int V_203 , int V_204 ,
struct V_222 * V_223 )
{
struct V_222 V_224 ;
if ( ! T_1 -> V_225 )
return;
if ( V_203 == - 1 ) {
V_224 = T_1 -> V_225 -> V_226 ;
T_1 -> V_225 -> V_226 = * V_223 ;
} else {
V_224 = * F_91 ( T_1 -> V_225 , V_203 , V_204 ) ;
* F_91 ( T_1 -> V_225 , V_203 , V_204 ) = * V_223 ;
}
V_223 -> V_127 = V_223 -> V_127 - V_224 . V_127 ;
V_223 -> V_227 = V_223 -> V_227 - V_224 . V_227 ;
V_223 -> V_228 = V_223 -> V_228 - V_224 . V_228 ;
}
void F_92 ( struct V_222 * V_223 ,
bool V_36 , T_8 * V_229 )
{
T_8 V_230 = 0 ;
if ( V_36 ) {
if ( V_223 -> V_228 == 0 ) {
V_230 = - 1 ;
V_223 -> V_127 = 0 ;
} else if ( V_223 -> V_228 < V_223 -> V_227 ) {
V_230 = 1 ;
V_223 -> V_127 = ( T_3 ) ( ( double ) V_223 -> V_127 * V_223 -> V_227 / V_223 -> V_228 + 0.5 ) ;
}
} else
V_223 -> V_227 = V_223 -> V_228 = 0 ;
if ( V_229 )
* V_229 = V_230 ;
}
int F_93 ( struct V_1 * T_1 , int V_203 , int V_204 ,
struct V_222 * V_223 )
{
memset ( V_223 , 0 , sizeof( * V_223 ) ) ;
if ( F_65 ( T_1 , V_203 , V_204 ) < 0 )
return - V_7 ;
if ( F_94 ( F_65 ( T_1 , V_203 , V_204 ) , V_223 , sizeof( * V_223 ) ) < 0 )
return - V_231 ;
return 0 ;
}
int F_95 ( struct V_1 * T_1 ,
int V_203 , int V_204 , bool V_36 )
{
struct V_222 V_223 ;
T_2 V_232 = V_36 ? 3 : 1 ;
if ( F_65 ( T_1 , V_203 , V_204 ) < 0 )
return - V_7 ;
if ( T_1 -> V_233 == NULL && F_96 ( T_1 , V_203 + 1 , V_204 + 1 ) < 0 )
return - V_47 ;
if ( F_94 ( F_65 ( T_1 , V_203 , V_204 ) , & V_223 , V_232 * sizeof( T_3 ) ) < 0 )
return - V_231 ;
F_90 ( T_1 , V_203 , V_204 , & V_223 ) ;
F_92 ( & V_223 , V_36 , NULL ) ;
* F_91 ( T_1 -> V_233 , V_203 , V_204 ) = V_223 ;
return 0 ;
}
static int F_97 ( struct V_1 * T_1 , int V_203 , int V_204 )
{
struct V_1 * V_34 = T_1 -> V_34 ;
int V_206 ;
if ( F_60 ( T_1 ) )
return - 1 ;
F_98 ( ! V_34 -> V_206 ) ;
V_206 = F_65 ( V_34 , V_203 , V_204 ) ;
F_98 ( V_206 == - 1 ) ;
return V_206 ;
}
static void F_99 ( char * V_97 , T_2 V_6 , T_3 V_234 , struct V_235 * V_236 )
{
bool V_237 = true ;
int V_11 = 0 ;
do {
if ( V_234 & V_236 [ V_11 ] . V_25 ) {
V_97 += F_31 ( V_97 , V_6 , L_38 , V_237 ? L_1 : L_39 , V_236 [ V_11 ] . V_45 ) ;
V_237 = false ;
}
} while ( V_236 [ ++ V_11 ] . V_45 != NULL );
}
static void F_100 ( char * V_97 , T_2 V_6 , T_3 V_234 )
{
#define F_101 ( T_9 ) { PERF_SAMPLE_##n, #n }
struct V_235 V_236 [] = {
F_101 ( V_149 ) , F_101 ( V_150 ) , F_101 ( TIME ) , F_101 ( V_164 ) ,
F_101 ( V_152 ) , F_101 ( V_104 ) , F_101 ( V_28 ) , F_101 ( V_170 ) ,
F_101 ( V_159 ) , F_101 ( V_238 ) , F_101 ( V_174 ) ,
F_101 ( V_108 ) , F_101 ( V_115 ) , F_101 ( V_116 ) ,
F_101 ( V_29 ) , F_101 ( V_169 ) , F_101 ( V_175 ) ,
F_101 ( V_180 ) ,
{ . V_45 = NULL , }
} ;
#undef F_101
F_99 ( V_97 , V_6 , V_234 , V_236 ) ;
}
static void F_102 ( char * V_97 , T_2 V_6 , T_3 V_234 )
{
#define F_101 ( T_9 ) { PERF_FORMAT_##n, #n }
struct V_235 V_236 [] = {
F_101 ( V_239 ) , F_101 ( V_240 ) ,
F_101 ( V_28 ) , F_101 ( V_241 ) ,
{ . V_45 = NULL , }
} ;
#undef F_101
F_99 ( V_97 , V_6 , V_234 , V_236 ) ;
}
int F_103 ( T_10 * V_242 , struct V_32 * V_22 ,
T_11 V_243 , void * V_244 )
{
char V_97 [ V_245 ] ;
int V_90 = 0 ;
F_104 ( type , V_246 ) ;
F_104 ( V_6 , V_246 ) ;
F_104 ( V_53 , V_247 ) ;
F_105 ( L_40 , V_43 , V_246 ) ;
F_104 ( V_8 , V_248 ) ;
F_104 ( V_30 , V_249 ) ;
F_104 ( V_192 , V_246 ) ;
F_104 ( V_138 , V_246 ) ;
F_104 ( V_250 , V_246 ) ;
F_104 ( V_251 , V_246 ) ;
F_104 ( V_62 , V_246 ) ;
F_104 ( V_61 , V_246 ) ;
F_104 ( V_63 , V_246 ) ;
F_104 ( V_252 , V_246 ) ;
F_104 ( V_182 , V_246 ) ;
F_104 ( V_184 , V_246 ) ;
F_104 ( V_129 , V_246 ) ;
F_104 ( V_162 , V_246 ) ;
F_104 ( V_194 , V_246 ) ;
F_104 ( V_181 , V_246 ) ;
F_104 ( V_177 , V_246 ) ;
F_104 ( V_67 , V_246 ) ;
F_104 ( V_165 , V_246 ) ;
F_104 ( V_146 , V_246 ) ;
F_104 ( V_68 , V_246 ) ;
F_104 ( V_69 , V_246 ) ;
F_104 ( V_253 , V_246 ) ;
F_104 ( V_121 , V_246 ) ;
F_104 ( V_183 , V_246 ) ;
F_104 ( V_254 , V_246 ) ;
F_104 ( V_197 , V_246 ) ;
F_104 ( V_186 , V_246 ) ;
F_105 ( L_41 , V_178 , V_246 ) ;
F_104 ( V_80 , V_246 ) ;
F_105 ( L_42 , V_79 , V_247 ) ;
F_105 ( L_43 , V_255 , V_247 ) ;
F_104 ( V_109 , V_246 ) ;
F_104 ( V_117 , V_247 ) ;
F_104 ( V_119 , V_246 ) ;
F_104 ( V_196 , V_256 ) ;
F_104 ( V_168 , V_247 ) ;
F_104 ( V_257 , V_246 ) ;
return V_90 ;
}
static int F_106 ( struct V_1 * T_1 , struct V_258 * V_213 ,
struct V_259 * V_212 )
{
int V_203 , V_204 , V_202 ;
unsigned long V_260 = V_261 ;
int V_262 = - 1 , V_46 ;
enum { V_263 , V_264 , V_265 } V_266 = V_263 ;
if ( T_1 -> V_205 )
V_202 = 1 ;
else
V_202 = V_212 -> V_267 ;
if ( T_1 -> V_206 == NULL &&
F_63 ( T_1 , V_213 -> V_267 , V_202 ) < 0 )
return - V_47 ;
if ( T_1 -> V_220 ) {
V_260 |= V_268 ;
V_262 = T_1 -> V_220 -> V_206 ;
}
V_269:
if ( V_147 . V_270 )
T_1 -> V_22 . V_196 = V_271 ;
if ( V_147 . V_196 ) {
T_1 -> V_22 . V_197 = 0 ;
T_1 -> V_22 . V_196 = 0 ;
}
if ( V_147 . V_272 )
V_260 &= ~ ( unsigned long ) V_261 ;
if ( V_147 . V_183 )
T_1 -> V_22 . V_183 = 0 ;
if ( V_147 . V_69 )
T_1 -> V_22 . V_69 = T_1 -> V_22 . V_68 = 0 ;
if ( V_147 . V_273 )
T_1 -> V_22 . V_109 &= ~ ( V_113 |
V_112 ) ;
V_274:
if ( V_147 . V_146 )
T_1 -> V_22 . V_146 = 0 ;
if ( V_275 >= 2 ) {
fprintf ( V_276 , L_44 , V_277 ) ;
fprintf ( V_276 , L_45 ) ;
F_103 ( V_276 , & T_1 -> V_22 , V_278 , NULL ) ;
fprintf ( V_276 , L_44 , V_277 ) ;
}
for ( V_203 = 0 ; V_203 < V_213 -> V_267 ; V_203 ++ ) {
for ( V_204 = 0 ; V_204 < V_202 ; V_204 ++ ) {
int V_279 ;
if ( ! T_1 -> V_220 && ! T_1 -> V_205 )
V_262 = F_107 ( V_212 , V_204 ) ;
V_279 = F_97 ( T_1 , V_203 , V_204 ) ;
V_280:
F_108 ( L_46 ,
V_262 , V_213 -> V_281 [ V_203 ] , V_279 , V_260 ) ;
F_65 ( T_1 , V_203 , V_204 ) = F_109 ( & T_1 -> V_22 ,
V_262 ,
V_213 -> V_281 [ V_203 ] ,
V_279 , V_260 ) ;
if ( F_65 ( T_1 , V_203 , V_204 ) < 0 ) {
V_46 = - V_231 ;
F_108 ( L_47 ,
V_46 ) ;
goto V_282;
}
if ( T_1 -> V_38 >= 0 ) {
int V_283 = F_65 ( T_1 , V_203 , V_204 ) ;
int V_38 = T_1 -> V_38 ;
V_46 = F_67 ( V_283 ,
V_284 ,
V_38 ) ;
if ( V_46 && V_231 != V_285 ) {
F_56 ( L_48 ,
V_38 , strerror ( V_231 ) ) ;
V_46 = - V_7 ;
goto V_286;
}
}
V_266 = V_263 ;
if ( V_147 . V_196 ||
V_147 . V_270 ) {
V_46 = - V_7 ;
goto V_286;
}
}
}
return 0 ;
V_282:
if ( V_46 == - V_287 && V_266 < V_265 ) {
struct V_288 V_289 ;
int V_290 = V_231 ;
if ( F_110 ( V_291 , & V_289 ) == 0 ) {
if ( V_266 == V_263 )
V_289 . V_292 = V_289 . V_293 ;
else {
V_289 . V_292 = V_289 . V_293 + 1000 ;
V_289 . V_293 = V_289 . V_292 ;
}
if ( F_111 ( V_291 , & V_289 ) == 0 ) {
V_266 ++ ;
V_231 = V_290 ;
goto V_280;
}
}
V_231 = V_290 ;
}
if ( V_46 != - V_7 || V_203 > 0 || V_204 > 0 )
goto V_286;
if ( ! V_147 . V_270 && T_1 -> V_22 . V_197 ) {
V_147 . V_270 = true ;
goto V_269;
} else if ( ! V_147 . V_196 && T_1 -> V_22 . V_197 ) {
V_147 . V_196 = true ;
goto V_269;
} else if ( ! V_147 . V_272 && ( V_260 & V_261 ) ) {
V_147 . V_272 = true ;
goto V_269;
} else if ( ! V_147 . V_183 && T_1 -> V_22 . V_183 ) {
V_147 . V_183 = true ;
goto V_269;
} else if ( ! V_147 . V_69 &&
( T_1 -> V_22 . V_69 || T_1 -> V_22 . V_68 ) ) {
V_147 . V_69 = true ;
goto V_269;
} else if ( ! V_147 . V_146 ) {
V_147 . V_146 = true ;
goto V_274;
} else if ( ! V_147 . V_273 &&
( T_1 -> V_22 . V_109 &
( V_112 |
V_113 ) ) ) {
V_147 . V_273 = true ;
goto V_269;
}
V_286:
do {
while ( -- V_204 >= 0 ) {
F_83 ( F_65 ( T_1 , V_203 , V_204 ) ) ;
F_65 ( T_1 , V_203 , V_204 ) = - 1 ;
}
V_204 = V_202 ;
} while ( -- V_203 >= 0 );
return V_46 ;
}
void F_112 ( struct V_1 * T_1 , int V_201 , int V_202 )
{
if ( T_1 -> V_206 == NULL )
return;
F_82 ( T_1 , V_201 , V_202 ) ;
F_77 ( T_1 ) ;
}
int F_113 ( struct V_1 * T_1 , struct V_258 * V_213 ,
struct V_259 * V_212 )
{
if ( V_213 == NULL ) {
V_213 = & V_294 . V_281 ;
}
if ( V_212 == NULL )
V_212 = & V_295 . V_281 ;
return F_106 ( T_1 , V_213 , V_212 ) ;
}
int F_114 ( struct V_1 * T_1 ,
struct V_258 * V_213 )
{
return F_106 ( T_1 , V_213 , & V_295 . V_281 ) ;
}
int F_115 ( struct V_1 * T_1 ,
struct V_259 * V_212 )
{
return F_106 ( T_1 , & V_294 . V_281 , V_212 ) ;
}
static int F_116 ( const struct V_1 * T_1 ,
const union V_296 * V_297 ,
struct V_298 * V_299 )
{
T_3 type = T_1 -> V_22 . V_8 ;
const T_3 * V_300 = V_297 -> V_299 . V_300 ;
bool V_301 = T_1 -> V_302 ;
union V_303 V_304 ;
V_300 += ( ( V_297 -> V_305 . V_6 -
sizeof( V_297 -> V_305 ) ) / sizeof( T_3 ) ) - 1 ;
if ( type & V_13 ) {
V_299 -> V_54 = * V_300 ;
V_300 -- ;
}
if ( type & V_19 ) {
V_304 . V_306 = * V_300 ;
if ( V_301 ) {
V_304 . V_306 = F_117 ( V_304 . V_306 ) ;
V_304 . V_307 [ 0 ] = F_118 ( V_304 . V_307 [ 0 ] ) ;
}
V_299 -> V_203 = V_304 . V_307 [ 0 ] ;
V_300 -- ;
}
if ( type & V_20 ) {
V_299 -> V_308 = * V_300 ;
V_300 -- ;
}
if ( type & V_14 ) {
V_299 -> V_54 = * V_300 ;
V_300 -- ;
}
if ( type & V_17 ) {
V_299 -> time = * V_300 ;
V_300 -- ;
}
if ( type & V_16 ) {
V_304 . V_306 = * V_300 ;
if ( V_301 ) {
V_304 . V_306 = F_117 ( V_304 . V_306 ) ;
V_304 . V_307 [ 0 ] = F_118 ( V_304 . V_307 [ 0 ] ) ;
V_304 . V_307 [ 1 ] = F_118 ( V_304 . V_307 [ 1 ] ) ;
}
V_299 -> V_262 = V_304 . V_307 [ 0 ] ;
V_299 -> V_309 = V_304 . V_307 [ 1 ] ;
V_300 -- ;
}
return 0 ;
}
static inline bool F_119 ( const void * V_310 , T_12 V_311 , const void * V_312 ,
T_3 V_6 )
{
return V_6 > V_311 || V_312 + V_6 > V_310 ;
}
int F_120 ( struct V_1 * T_1 , union V_296 * V_297 ,
struct V_298 * V_313 )
{
T_3 type = T_1 -> V_22 . V_8 ;
bool V_301 = T_1 -> V_302 ;
const T_3 * V_300 ;
T_12 V_311 = V_297 -> V_305 . V_6 ;
const void * V_310 = ( void * ) V_297 + V_311 ;
T_3 V_314 ;
union V_303 V_304 ;
memset ( V_313 , 0 , sizeof( * V_313 ) ) ;
V_313 -> V_203 = V_313 -> V_262 = V_313 -> V_309 = - 1 ;
V_313 -> V_308 = V_313 -> V_54 = V_313 -> time = - 1ULL ;
V_313 -> V_128 = T_1 -> V_22 . V_43 ;
V_313 -> V_315 = 0 ;
V_313 -> V_316 = V_297 -> V_305 . V_317 & V_318 ;
if ( V_297 -> V_305 . type != V_319 ) {
if ( ! T_1 -> V_22 . V_146 )
return 0 ;
return F_116 ( T_1 , V_297 , V_313 ) ;
}
V_300 = V_297 -> V_299 . V_300 ;
if ( T_1 -> V_26 + sizeof( V_297 -> V_305 ) > V_297 -> V_305 . V_6 )
return - V_320 ;
V_313 -> V_54 = - 1ULL ;
if ( type & V_13 ) {
V_313 -> V_54 = * V_300 ;
V_300 ++ ;
}
if ( type & V_15 ) {
V_313 -> V_321 = * V_300 ;
V_300 ++ ;
}
if ( type & V_16 ) {
V_304 . V_306 = * V_300 ;
if ( V_301 ) {
V_304 . V_306 = F_117 ( V_304 . V_306 ) ;
V_304 . V_307 [ 0 ] = F_118 ( V_304 . V_307 [ 0 ] ) ;
V_304 . V_307 [ 1 ] = F_118 ( V_304 . V_307 [ 1 ] ) ;
}
V_313 -> V_262 = V_304 . V_307 [ 0 ] ;
V_313 -> V_309 = V_304 . V_307 [ 1 ] ;
V_300 ++ ;
}
if ( type & V_17 ) {
V_313 -> time = * V_300 ;
V_300 ++ ;
}
V_313 -> V_74 = 0 ;
if ( type & V_18 ) {
V_313 -> V_74 = * V_300 ;
V_300 ++ ;
}
if ( type & V_14 ) {
V_313 -> V_54 = * V_300 ;
V_300 ++ ;
}
if ( type & V_20 ) {
V_313 -> V_308 = * V_300 ;
V_300 ++ ;
}
if ( type & V_19 ) {
V_304 . V_306 = * V_300 ;
if ( V_301 ) {
V_304 . V_306 = F_117 ( V_304 . V_306 ) ;
V_304 . V_307 [ 0 ] = F_118 ( V_304 . V_307 [ 0 ] ) ;
}
V_313 -> V_203 = V_304 . V_307 [ 0 ] ;
V_300 ++ ;
}
if ( type & V_50 ) {
V_313 -> V_128 = * V_300 ;
V_300 ++ ;
}
if ( type & V_322 ) {
T_3 V_30 = T_1 -> V_22 . V_30 ;
F_121 ( V_300 ) ;
if ( V_30 & V_154 )
V_313 -> V_323 . V_324 . V_267 = * V_300 ;
else
V_313 -> V_323 . V_325 . V_234 = * V_300 ;
V_300 ++ ;
if ( V_30 & V_190 ) {
F_121 ( V_300 ) ;
V_313 -> V_323 . V_326 = * V_300 ;
V_300 ++ ;
}
if ( V_30 & V_191 ) {
F_121 ( V_300 ) ;
V_313 -> V_323 . V_327 = * V_300 ;
V_300 ++ ;
}
if ( V_30 & V_154 ) {
const T_3 V_328 = V_329 /
sizeof( struct V_330 ) ;
if ( V_313 -> V_323 . V_324 . V_267 > V_328 )
return - V_320 ;
V_314 = V_313 -> V_323 . V_324 . V_267 *
sizeof( struct V_330 ) ;
F_122 ( V_300 , V_314 , V_311 ) ;
V_313 -> V_323 . V_324 . V_331 =
(struct V_330 * ) V_300 ;
V_300 = ( void * ) V_300 + V_314 ;
} else {
F_121 ( V_300 ) ;
V_313 -> V_323 . V_325 . V_54 = * V_300 ;
V_300 ++ ;
}
}
if ( type & V_332 ) {
const T_3 V_333 = V_329 / sizeof( T_3 ) ;
F_121 ( V_300 ) ;
V_313 -> V_334 = (struct V_335 * ) V_300 ++ ;
if ( V_313 -> V_334 -> V_267 > V_333 )
return - V_320 ;
V_314 = V_313 -> V_334 -> V_267 * sizeof( T_3 ) ;
F_122 ( V_300 , V_314 , V_311 ) ;
V_300 = ( void * ) V_300 + V_314 ;
}
if ( type & V_42 ) {
F_121 ( V_300 ) ;
V_304 . V_306 = * V_300 ;
if ( F_123 ( V_301 ,
L_49 ) ) {
V_304 . V_306 = F_117 ( V_304 . V_306 ) ;
V_304 . V_307 [ 0 ] = F_118 ( V_304 . V_307 [ 0 ] ) ;
V_304 . V_307 [ 1 ] = F_118 ( V_304 . V_307 [ 1 ] ) ;
}
V_313 -> V_336 = V_304 . V_307 [ 0 ] ;
V_300 = ( void * ) V_300 + sizeof( T_7 ) ;
F_122 ( V_300 , V_313 -> V_336 , V_311 ) ;
V_313 -> V_337 = ( void * ) V_300 ;
V_300 = ( void * ) V_300 + V_313 -> V_336 ;
}
if ( type & V_338 ) {
const T_3 V_339 = V_329 /
sizeof( struct V_340 ) ;
F_121 ( V_300 ) ;
V_313 -> V_107 = (struct V_107 * ) V_300 ++ ;
if ( V_313 -> V_107 -> V_267 > V_339 )
return - V_320 ;
V_314 = V_313 -> V_107 -> V_267 * sizeof( struct V_340 ) ;
F_122 ( V_300 , V_314 , V_311 ) ;
V_300 = ( void * ) V_300 + V_314 ;
}
if ( type & V_341 ) {
F_121 ( V_300 ) ;
V_313 -> V_342 . V_343 = * V_300 ;
V_300 ++ ;
if ( V_313 -> V_342 . V_343 ) {
T_3 V_9 = T_1 -> V_22 . V_117 ;
V_314 = F_124 ( V_9 ) * sizeof( T_3 ) ;
F_122 ( V_300 , V_314 , V_311 ) ;
V_313 -> V_342 . V_9 = V_9 ;
V_313 -> V_342 . V_344 = ( T_3 * ) V_300 ;
V_300 = ( void * ) V_300 + V_314 ;
}
}
if ( type & V_345 ) {
F_121 ( V_300 ) ;
V_314 = * V_300 ++ ;
V_313 -> V_346 . V_312 = ( ( char * ) ( V_300 - 1 )
- ( char * ) V_297 ) ;
if ( ! V_314 ) {
V_313 -> V_346 . V_6 = 0 ;
} else {
F_122 ( V_300 , V_314 , V_311 ) ;
V_313 -> V_346 . V_313 = ( char * ) V_300 ;
V_300 = ( void * ) V_300 + V_314 ;
F_121 ( V_300 ) ;
V_313 -> V_346 . V_6 = * V_300 ++ ;
if ( F_123 ( V_313 -> V_346 . V_6 > V_314 ,
L_50 ) )
return - V_320 ;
}
}
V_313 -> V_315 = 0 ;
if ( type & V_347 ) {
F_121 ( V_300 ) ;
V_313 -> V_315 = * V_300 ;
V_300 ++ ;
}
V_313 -> V_348 = V_349 ;
if ( type & V_350 ) {
F_121 ( V_300 ) ;
V_313 -> V_348 = * V_300 ;
V_300 ++ ;
}
V_313 -> V_351 = 0 ;
if ( type & V_352 ) {
F_121 ( V_300 ) ;
V_313 -> V_351 = * V_300 ;
V_300 ++ ;
}
V_313 -> V_353 . V_343 = V_354 ;
if ( type & V_355 ) {
F_121 ( V_300 ) ;
V_313 -> V_353 . V_343 = * V_300 ;
V_300 ++ ;
if ( V_313 -> V_353 . V_343 != V_354 ) {
T_3 V_9 = T_1 -> V_22 . V_168 ;
V_314 = F_124 ( V_9 ) * sizeof( T_3 ) ;
F_122 ( V_300 , V_314 , V_311 ) ;
V_313 -> V_353 . V_9 = V_9 ;
V_313 -> V_353 . V_344 = ( T_3 * ) V_300 ;
V_300 = ( void * ) V_300 + V_314 ;
}
}
return 0 ;
}
T_2 F_125 ( const struct V_298 * V_299 , T_3 type ,
T_3 V_30 )
{
T_2 V_314 , V_83 = sizeof( struct V_356 ) ;
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
if ( type & V_50 )
V_83 += sizeof( T_3 ) ;
if ( type & V_322 ) {
V_83 += sizeof( T_3 ) ;
if ( V_30 & V_190 )
V_83 += sizeof( T_3 ) ;
if ( V_30 & V_191 )
V_83 += sizeof( T_3 ) ;
if ( V_30 & V_154 ) {
V_314 = V_299 -> V_323 . V_324 . V_267 *
sizeof( struct V_330 ) ;
V_83 += V_314 ;
} else {
V_83 += sizeof( T_3 ) ;
}
}
if ( type & V_332 ) {
V_314 = ( V_299 -> V_334 -> V_267 + 1 ) * sizeof( T_3 ) ;
V_83 += V_314 ;
}
if ( type & V_42 ) {
V_83 += sizeof( T_7 ) ;
V_83 += V_299 -> V_336 ;
}
if ( type & V_338 ) {
V_314 = V_299 -> V_107 -> V_267 * sizeof( struct V_340 ) ;
V_314 += sizeof( T_3 ) ;
V_83 += V_314 ;
}
if ( type & V_341 ) {
if ( V_299 -> V_342 . V_343 ) {
V_83 += sizeof( T_3 ) ;
V_314 = F_124 ( V_299 -> V_342 . V_9 ) * sizeof( T_3 ) ;
V_83 += V_314 ;
} else {
V_83 += sizeof( T_3 ) ;
}
}
if ( type & V_345 ) {
V_314 = V_299 -> V_346 . V_6 ;
V_83 += sizeof( T_3 ) ;
if ( V_314 ) {
V_83 += V_314 ;
V_83 += sizeof( T_3 ) ;
}
}
if ( type & V_347 )
V_83 += sizeof( T_3 ) ;
if ( type & V_350 )
V_83 += sizeof( T_3 ) ;
if ( type & V_352 )
V_83 += sizeof( T_3 ) ;
if ( type & V_355 ) {
if ( V_299 -> V_353 . V_343 ) {
V_83 += sizeof( T_3 ) ;
V_314 = F_124 ( V_299 -> V_353 . V_9 ) * sizeof( T_3 ) ;
V_83 += V_314 ;
} else {
V_83 += sizeof( T_3 ) ;
}
}
return V_83 ;
}
int F_126 ( union V_296 * V_297 , T_3 type ,
T_3 V_30 ,
const struct V_298 * V_299 ,
bool V_301 )
{
T_3 * V_300 ;
T_2 V_314 ;
union V_303 V_304 ;
V_300 = V_297 -> V_299 . V_300 ;
if ( type & V_13 ) {
* V_300 = V_299 -> V_54 ;
V_300 ++ ;
}
if ( type & V_15 ) {
* V_300 = V_299 -> V_321 ;
V_300 ++ ;
}
if ( type & V_16 ) {
V_304 . V_307 [ 0 ] = V_299 -> V_262 ;
V_304 . V_307 [ 1 ] = V_299 -> V_309 ;
if ( V_301 ) {
V_304 . V_307 [ 0 ] = F_118 ( V_304 . V_307 [ 0 ] ) ;
V_304 . V_307 [ 1 ] = F_118 ( V_304 . V_307 [ 1 ] ) ;
V_304 . V_306 = F_117 ( V_304 . V_306 ) ;
}
* V_300 = V_304 . V_306 ;
V_300 ++ ;
}
if ( type & V_17 ) {
* V_300 = V_299 -> time ;
V_300 ++ ;
}
if ( type & V_18 ) {
* V_300 = V_299 -> V_74 ;
V_300 ++ ;
}
if ( type & V_14 ) {
* V_300 = V_299 -> V_54 ;
V_300 ++ ;
}
if ( type & V_20 ) {
* V_300 = V_299 -> V_308 ;
V_300 ++ ;
}
if ( type & V_19 ) {
V_304 . V_307 [ 0 ] = V_299 -> V_203 ;
if ( V_301 ) {
V_304 . V_307 [ 0 ] = F_118 ( V_304 . V_307 [ 0 ] ) ;
V_304 . V_306 = F_117 ( V_304 . V_306 ) ;
}
* V_300 = V_304 . V_306 ;
V_300 ++ ;
}
if ( type & V_50 ) {
* V_300 = V_299 -> V_128 ;
V_300 ++ ;
}
if ( type & V_322 ) {
if ( V_30 & V_154 )
* V_300 = V_299 -> V_323 . V_324 . V_267 ;
else
* V_300 = V_299 -> V_323 . V_325 . V_234 ;
V_300 ++ ;
if ( V_30 & V_190 ) {
* V_300 = V_299 -> V_323 . V_326 ;
V_300 ++ ;
}
if ( V_30 & V_191 ) {
* V_300 = V_299 -> V_323 . V_327 ;
V_300 ++ ;
}
if ( V_30 & V_154 ) {
V_314 = V_299 -> V_323 . V_324 . V_267 *
sizeof( struct V_330 ) ;
memcpy ( V_300 , V_299 -> V_323 . V_324 . V_331 , V_314 ) ;
V_300 = ( void * ) V_300 + V_314 ;
} else {
* V_300 = V_299 -> V_323 . V_325 . V_54 ;
V_300 ++ ;
}
}
if ( type & V_332 ) {
V_314 = ( V_299 -> V_334 -> V_267 + 1 ) * sizeof( T_3 ) ;
memcpy ( V_300 , V_299 -> V_334 , V_314 ) ;
V_300 = ( void * ) V_300 + V_314 ;
}
if ( type & V_42 ) {
V_304 . V_307 [ 0 ] = V_299 -> V_336 ;
if ( F_123 ( V_301 ,
L_49 ) ) {
V_304 . V_307 [ 0 ] = F_118 ( V_304 . V_307 [ 0 ] ) ;
V_304 . V_307 [ 1 ] = F_118 ( V_304 . V_307 [ 1 ] ) ;
V_304 . V_306 = F_117 ( V_304 . V_306 ) ;
}
* V_300 = V_304 . V_306 ;
V_300 = ( void * ) V_300 + sizeof( T_7 ) ;
memcpy ( V_300 , V_299 -> V_337 , V_299 -> V_336 ) ;
V_300 = ( void * ) V_300 + V_299 -> V_336 ;
}
if ( type & V_338 ) {
V_314 = V_299 -> V_107 -> V_267 * sizeof( struct V_340 ) ;
V_314 += sizeof( T_3 ) ;
memcpy ( V_300 , V_299 -> V_107 , V_314 ) ;
V_300 = ( void * ) V_300 + V_314 ;
}
if ( type & V_341 ) {
if ( V_299 -> V_342 . V_343 ) {
* V_300 ++ = V_299 -> V_342 . V_343 ;
V_314 = F_124 ( V_299 -> V_342 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_300 , V_299 -> V_342 . V_344 , V_314 ) ;
V_300 = ( void * ) V_300 + V_314 ;
} else {
* V_300 ++ = 0 ;
}
}
if ( type & V_345 ) {
V_314 = V_299 -> V_346 . V_6 ;
* V_300 ++ = V_314 ;
if ( V_314 ) {
memcpy ( V_300 , V_299 -> V_346 . V_313 , V_314 ) ;
V_300 = ( void * ) V_300 + V_314 ;
* V_300 ++ = V_314 ;
}
}
if ( type & V_347 ) {
* V_300 = V_299 -> V_315 ;
V_300 ++ ;
}
if ( type & V_350 ) {
* V_300 = V_299 -> V_348 ;
V_300 ++ ;
}
if ( type & V_352 ) {
* V_300 = V_299 -> V_351 ;
V_300 ++ ;
}
if ( type & V_355 ) {
if ( V_299 -> V_353 . V_343 ) {
* V_300 ++ = V_299 -> V_353 . V_343 ;
V_314 = F_124 ( V_299 -> V_353 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_300 , V_299 -> V_353 . V_344 , V_314 ) ;
V_300 = ( void * ) V_300 + V_314 ;
} else {
* V_300 ++ = 0 ;
}
}
return 0 ;
}
struct V_357 * F_127 ( struct V_1 * T_1 , const char * V_45 )
{
return F_128 ( T_1 -> V_52 , V_45 ) ;
}
void * F_129 ( struct V_1 * T_1 , struct V_298 * V_299 ,
const char * V_45 )
{
struct V_357 * V_358 = F_127 ( T_1 , V_45 ) ;
int V_312 ;
if ( ! V_358 )
return NULL ;
V_312 = V_358 -> V_312 ;
if ( V_358 -> V_260 & V_359 ) {
V_312 = * ( int * ) ( V_299 -> V_337 + V_358 -> V_312 ) ;
V_312 &= 0xffff ;
}
return V_299 -> V_337 + V_312 ;
}
T_3 F_130 ( struct V_1 * T_1 , struct V_298 * V_299 ,
const char * V_45 )
{
struct V_357 * V_358 = F_127 ( T_1 , V_45 ) ;
void * V_360 ;
T_3 V_234 ;
if ( ! V_358 )
return 0 ;
V_360 = V_299 -> V_337 + V_358 -> V_312 ;
switch ( V_358 -> V_6 ) {
case 1 :
return * ( T_6 * ) V_360 ;
case 2 :
V_234 = * ( T_12 * ) V_360 ;
break;
case 4 :
V_234 = * ( T_7 * ) V_360 ;
break;
case 8 :
memcpy ( & V_234 , V_360 , sizeof( T_3 ) ) ;
break;
default:
return 0 ;
}
if ( ! T_1 -> V_302 )
return V_234 ;
switch ( V_358 -> V_6 ) {
case 2 :
return F_131 ( V_234 ) ;
case 4 :
return F_118 ( V_234 ) ;
case 8 :
return F_117 ( V_234 ) ;
default:
return 0 ;
}
return 0 ;
}
static int F_132 ( T_10 * V_242 , bool * V_361 , const char * V_362 , ... )
{
T_13 args ;
int V_90 = 0 ;
if ( ! * V_361 ) {
V_90 += fprintf ( V_242 , L_51 ) ;
} else {
V_90 += fprintf ( V_242 , L_9 ) ;
* V_361 = false ;
}
va_start ( args , V_362 ) ;
V_90 += vfprintf ( V_242 , V_362 , args ) ;
va_end ( args ) ;
return V_90 ;
}
static int F_133 ( T_10 * V_242 , const char * V_45 , const char * V_127 , void * V_244 )
{
return F_132 ( V_242 , ( bool * ) V_244 , L_52 , V_45 , V_127 ) ;
}
int F_134 ( struct V_1 * T_1 ,
struct V_363 * V_364 , T_10 * V_242 )
{
bool V_361 = true ;
int V_365 = 0 ;
if ( V_364 -> V_366 ) {
struct V_1 * V_98 ;
if ( ! F_60 ( T_1 ) )
return 0 ;
if ( T_1 -> V_153 > 1 )
V_365 += fprintf ( V_242 , L_53 , T_1 -> V_96 ? : L_1 ) ;
V_365 += fprintf ( V_242 , L_6 , F_43 ( T_1 ) ) ;
F_47 (pos, evsel)
V_365 += fprintf ( V_242 , L_54 , F_43 ( V_98 ) ) ;
if ( T_1 -> V_153 > 1 )
V_365 += fprintf ( V_242 , L_55 ) ;
goto V_367;
}
V_365 += fprintf ( V_242 , L_6 , F_43 ( T_1 ) ) ;
if ( V_364 -> V_275 ) {
V_365 += F_103 ( V_242 , & T_1 -> V_22 ,
F_133 , & V_361 ) ;
} else if ( V_364 -> V_129 ) {
const char * V_123 = L_56 ;
if ( ! T_1 -> V_22 . V_129 )
V_123 = L_57 ;
V_365 += F_132 ( V_242 , & V_361 , L_58 V_368 ,
V_123 , ( T_3 ) T_1 -> V_22 . V_131 ) ;
}
if ( V_364 -> V_369 ) {
struct V_357 * V_358 ;
if ( T_1 -> V_22 . type != V_49 ) {
V_365 += F_132 ( V_242 , & V_361 , L_59 ) ;
goto V_367;
}
V_358 = T_1 -> V_52 -> V_370 . V_371 ;
if ( V_358 == NULL ) {
V_365 += F_132 ( V_242 , & V_361 , L_60 ) ;
goto V_367;
}
V_365 += F_132 ( V_242 , & V_361 , L_61 , V_358 -> V_45 ) ;
V_358 = V_358 -> V_372 ;
while ( V_358 ) {
V_365 += F_132 ( V_242 , & V_361 , L_6 , V_358 -> V_45 ) ;
V_358 = V_358 -> V_372 ;
}
}
V_367:
fputc ( '\n' , V_242 ) ;
return ++ V_365 ;
}
bool F_135 ( struct V_1 * T_1 , int V_46 ,
char * V_373 , T_2 V_374 )
{
int V_375 ;
if ( ( V_46 == V_376 || V_46 == V_377 || V_46 == V_378 ) &&
T_1 -> V_22 . type == V_92 &&
T_1 -> V_22 . V_53 == V_379 ) {
F_31 ( V_373 , V_374 , L_6 ,
L_62 ) ;
T_1 -> V_22 . type = V_94 ;
T_1 -> V_22 . V_53 = V_380 ;
F_26 ( & T_1 -> V_45 ) ;
return true ;
} else if ( V_46 == V_381 && ! T_1 -> V_22 . V_61 &&
( V_375 = F_136 () ) > 1 ) {
const char * V_45 = F_43 ( T_1 ) ;
char * V_382 ;
if ( F_21 ( & V_382 , L_63 , V_45 , strchr ( V_45 , ':' ) ? L_1 : L_9 ) < 0 )
return false ;
if ( T_1 -> V_45 )
free ( T_1 -> V_45 ) ;
T_1 -> V_45 = V_382 ;
F_31 ( V_373 , V_374 ,
L_64 , V_375 ) ;
T_1 -> V_22 . V_61 = 1 ;
return true ;
}
return false ;
}
int F_137 ( struct V_1 * T_1 , struct V_143 * V_143 ,
int V_46 , char * V_373 , T_2 V_6 )
{
char V_383 [ V_384 ] ;
switch ( V_46 ) {
case V_385 :
case V_381 :
return F_31 ( V_373 , V_6 ,
L_65
L_66
L_67
L_68
L_69
L_70
L_71
L_72
L_73 ,
V_143 -> V_205 ? L_74 : L_1 ,
F_136 () ) ;
case V_376 :
return F_31 ( V_373 , V_6 , L_75 ,
F_43 ( T_1 ) ) ;
case V_287 :
return F_31 ( V_373 , V_6 , L_6 ,
L_76
L_77
L_78
L_79 ) ;
case V_378 :
if ( V_143 -> V_386 )
return F_31 ( V_373 , V_6 , L_6 ,
L_80 ) ;
break;
case V_387 :
if ( T_1 -> V_22 . V_67 )
return F_31 ( V_373 , V_6 , L_6 ,
L_81 ) ;
#if F_138 ( V_388 ) || F_138 ( V_389 )
if ( T_1 -> V_22 . type == V_92 )
return F_31 ( V_373 , V_6 , L_6 ,
L_82
L_83 ) ;
#endif
break;
case V_390 :
if ( F_139 ( L_84 ) )
return F_31 ( V_373 , V_6 ,
L_85
L_86 ) ;
break;
case V_7 :
if ( V_147 . V_196 )
return F_31 ( V_373 , V_6 , L_87 ) ;
if ( V_147 . V_270 )
return F_31 ( V_373 , V_6 , L_88 , V_196 ) ;
break;
default:
break;
}
return F_31 ( V_373 , V_6 ,
L_89
L_90
L_91 ,
V_46 , F_140 ( V_46 , V_383 , sizeof( V_383 ) ) ,
F_43 ( T_1 ) ) ;
}
