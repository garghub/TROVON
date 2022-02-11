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
T_1 -> V_22 . V_8 |= ( V_42 | V_17 |
V_19 | V_43 ) ,
T_1 -> V_22 . V_44 = 1 ;
}
return T_1 ;
}
struct V_1 * F_20 ( const char * V_45 , const char * V_46 , int V_12 )
{
struct V_1 * T_1 = F_18 ( V_5 . V_6 ) ;
int V_47 = - V_48 ;
if ( T_1 == NULL ) {
goto V_49;
} else {
struct V_32 V_22 = {
. type = V_50 ,
. V_8 = ( V_42 | V_17 |
V_19 | V_43 ) ,
} ;
if ( F_21 ( & T_1 -> V_46 , L_2 , V_45 , V_46 ) < 0 )
goto V_51;
T_1 -> V_52 = F_22 ( V_45 , V_46 ) ;
if ( F_23 ( T_1 -> V_52 ) ) {
V_47 = F_24 ( T_1 -> V_52 ) ;
goto V_51;
}
F_25 ( & V_22 ) ;
V_22 . V_53 = T_1 -> V_52 -> V_54 ;
V_22 . V_44 = 1 ;
F_15 ( T_1 , & V_22 , V_12 ) ;
}
return T_1 ;
V_51:
F_26 ( & T_1 -> V_46 ) ;
free ( T_1 ) ;
V_49:
return F_27 ( V_47 ) ;
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
const char * V_47 = L_15 ;
if ( type > V_87 )
goto V_49;
V_81 = ( V_53 >> 8 ) & 0xff ;
V_47 = L_16 ;
if ( V_81 > V_88 )
goto V_49;
V_83 = ( V_53 >> 16 ) & 0xff ;
V_47 = L_17 ;
if ( V_83 > V_89 )
goto V_49;
V_47 = L_18 ;
if ( ! F_37 ( type , V_81 ) )
goto V_49;
return F_39 ( type , V_81 , V_83 , V_57 , V_6 ) ;
V_49:
return F_31 ( V_57 , V_6 , L_6 , V_47 ) ;
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
if ( T_1 -> V_46 )
return T_1 -> V_46 ;
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
case V_50 :
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
T_1 -> V_46 = F_44 ( V_57 ) ;
return T_1 -> V_46 ? : L_22 ;
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
void F_48 ( struct V_1 * T_1 ,
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
V_22 -> V_44 = V_123 -> V_127 . V_128 ;
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
T_1 -> V_46 ) ;
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
void F_58 ( struct V_1 * T_1 , struct V_99 * V_100 ,
struct V_101 * V_141 )
{
struct V_1 * V_34 = T_1 -> V_34 ;
struct V_32 * V_22 = & T_1 -> V_22 ;
int V_142 = T_1 -> V_33 ;
bool V_143 = V_100 -> V_144 . V_145 && ! V_100 -> V_144 . V_146 ;
V_22 -> V_147 = V_148 . V_147 ? 0 : 1 ;
V_22 -> V_138 = ! V_100 -> V_149 ;
F_14 ( T_1 , V_150 ) ;
F_14 ( T_1 , V_151 ) ;
if ( T_1 -> V_152 ) {
F_14 ( T_1 , V_153 ) ;
F_12 ( T_1 , false ) ;
if ( V_34 -> V_154 > 1 ) {
V_22 -> V_30 |= V_155 ;
V_22 -> V_138 = 0 ;
}
}
if ( ! V_22 -> V_44 || ( V_100 -> V_156 != V_157 ||
V_100 -> V_158 != V_159 ) ) {
if ( V_100 -> V_129 ) {
F_14 ( T_1 , V_160 ) ;
V_22 -> V_129 = 1 ;
V_22 -> V_131 = V_100 -> V_129 ;
} else {
V_22 -> V_44 = V_100 -> V_161 ;
}
}
if ( ( V_34 != T_1 ) && V_34 -> V_152 ) {
V_22 -> V_131 = 0 ;
V_22 -> V_44 = 0 ;
}
if ( V_100 -> V_162 )
V_22 -> V_131 = 0 ;
if ( V_100 -> V_163 )
V_22 -> V_163 = 1 ;
if ( V_100 -> V_164 ) {
F_14 ( T_1 , V_165 ) ;
V_22 -> V_166 = V_142 ;
}
if ( F_49 ( T_1 ) )
T_1 -> V_22 . V_121 = 1 ;
if ( V_141 && V_141 -> V_139 && ! T_1 -> V_167 )
F_48 ( T_1 , V_100 , V_141 ) ;
if ( V_100 -> V_168 ) {
V_22 -> V_169 = V_100 -> V_168 ;
F_14 ( T_1 , V_170 ) ;
}
if ( F_59 ( & V_100 -> V_144 ) )
F_14 ( T_1 , V_171 ) ;
if ( V_100 -> V_128 )
F_14 ( T_1 , V_160 ) ;
if ( V_100 -> V_172 &&
( ! V_148 . V_147 &&
( ! V_100 -> V_149 || F_59 ( & V_100 -> V_144 ) || V_143 ||
V_100 -> V_173 ) ) )
F_14 ( T_1 , TIME ) ;
if ( V_100 -> V_174 && ! T_1 -> V_167 ) {
F_14 ( T_1 , TIME ) ;
F_14 ( T_1 , V_175 ) ;
F_14 ( T_1 , V_171 ) ;
}
if ( V_100 -> V_164 )
F_14 ( T_1 , V_176 ) ;
if ( V_100 -> V_177 ) {
V_22 -> V_178 = 0 ;
V_22 -> V_179 = 1 ;
}
if ( V_100 -> V_107 && ! T_1 -> V_167 ) {
F_14 ( T_1 , V_108 ) ;
V_22 -> V_109 = V_100 -> V_107 ;
}
if ( V_100 -> V_180 )
F_14 ( T_1 , V_181 ) ;
V_22 -> V_182 = V_142 ;
V_22 -> V_183 = V_142 ;
V_22 -> V_184 = V_142 && ! V_148 . V_184 ;
V_22 -> V_185 = V_142 ;
if ( V_100 -> V_186 )
V_22 -> V_187 = V_142 ;
if ( V_100 -> V_188 )
F_14 ( T_1 , V_189 ) ;
if ( V_100 -> V_190 ) {
T_1 -> V_22 . V_30 |=
V_191 |
V_192 ;
}
if ( F_60 ( T_1 ) )
V_22 -> V_193 = 1 ;
if ( F_61 ( & V_100 -> V_144 ) && F_60 ( T_1 ) &&
! V_100 -> V_194 )
V_22 -> V_195 = 1 ;
if ( T_1 -> V_196 ) {
V_22 -> V_193 = 0 ;
V_22 -> V_195 = 0 ;
}
V_197 = V_100 -> V_197 ;
if ( V_100 -> V_198 ) {
V_22 -> V_198 = 1 ;
V_22 -> V_197 = V_100 -> V_197 ;
}
if ( T_1 -> V_199 )
F_62 ( V_22 ) ;
if ( V_100 -> V_200 ) {
V_22 -> V_61 = 1 ;
V_22 -> V_62 = 0 ;
}
if ( V_100 -> V_201 ) {
V_22 -> V_61 = 0 ;
V_22 -> V_62 = 1 ;
}
F_53 ( T_1 , V_100 ) ;
}
static int F_63 ( struct V_1 * T_1 , int V_202 , int V_203 )
{
int V_204 , V_205 ;
if ( T_1 -> V_206 )
V_203 = 1 ;
T_1 -> V_207 = F_64 ( V_202 , V_203 , sizeof( int ) ) ;
if ( T_1 -> V_207 ) {
for ( V_204 = 0 ; V_204 < V_202 ; V_204 ++ ) {
for ( V_205 = 0 ; V_205 < V_203 ; V_205 ++ ) {
F_65 ( T_1 , V_204 , V_205 ) = - 1 ;
}
}
}
return T_1 -> V_207 != NULL ? 0 : - V_48 ;
}
static int F_66 ( struct V_1 * T_1 , int V_202 , int V_203 ,
int V_208 , void * V_209 )
{
int V_204 , V_205 ;
if ( T_1 -> V_206 )
V_203 = 1 ;
for ( V_204 = 0 ; V_204 < V_202 ; V_204 ++ ) {
for ( V_205 = 0 ; V_205 < V_203 ; V_205 ++ ) {
int V_207 = F_65 ( T_1 , V_204 , V_205 ) ,
V_47 = F_67 ( V_207 , V_208 , V_209 ) ;
if ( V_47 )
return V_47 ;
}
}
return 0 ;
}
int F_68 ( struct V_1 * T_1 , int V_202 , int V_203 ,
const char * V_210 )
{
return F_66 ( T_1 , V_202 , V_203 ,
V_211 ,
( void * ) V_210 ) ;
}
int F_69 ( struct V_1 * T_1 , const char * V_210 )
{
char * V_212 = F_44 ( V_210 ) ;
if ( V_212 != NULL ) {
free ( T_1 -> V_210 ) ;
T_1 -> V_210 = V_212 ;
return 0 ;
}
return - 1 ;
}
int F_70 ( struct V_1 * T_1 ,
const char * V_81 , const char * V_210 )
{
char * V_212 ;
if ( T_1 -> V_210 == NULL )
return F_69 ( T_1 , V_210 ) ;
if ( F_21 ( & V_212 , L_37 , T_1 -> V_210 , V_81 , V_210 ) > 0 ) {
free ( T_1 -> V_210 ) ;
T_1 -> V_210 = V_212 ;
return 0 ;
}
return - 1 ;
}
int F_71 ( struct V_1 * T_1 )
{
int V_203 = F_72 ( T_1 -> V_213 ) ;
int V_202 = F_73 ( T_1 -> V_214 ) ;
return F_66 ( T_1 , V_202 , V_203 ,
V_215 ,
0 ) ;
}
int F_74 ( struct V_1 * T_1 )
{
int V_203 = F_72 ( T_1 -> V_213 ) ;
int V_202 = F_73 ( T_1 -> V_214 ) ;
return F_66 ( T_1 , V_202 , V_203 ,
V_216 ,
0 ) ;
}
int F_75 ( struct V_1 * T_1 , int V_202 , int V_203 )
{
if ( V_202 == 0 || V_203 == 0 )
return 0 ;
if ( T_1 -> V_206 )
V_203 = 1 ;
T_1 -> V_217 = F_64 ( V_202 , V_203 , sizeof( struct V_218 ) ) ;
if ( T_1 -> V_217 == NULL )
return - V_48 ;
T_1 -> V_54 = F_18 ( V_202 * V_203 * sizeof( T_3 ) ) ;
if ( T_1 -> V_54 == NULL ) {
F_76 ( T_1 -> V_217 ) ;
T_1 -> V_217 = NULL ;
return - V_48 ;
}
return 0 ;
}
static void F_77 ( struct V_1 * T_1 )
{
F_76 ( T_1 -> V_207 ) ;
T_1 -> V_207 = NULL ;
}
static void F_78 ( struct V_1 * T_1 )
{
F_76 ( T_1 -> V_217 ) ;
T_1 -> V_217 = NULL ;
F_26 ( & T_1 -> V_54 ) ;
}
static void F_79 ( struct V_1 * T_1 )
{
struct V_122 * V_123 , * V_219 ;
F_80 (term, h, &evsel->config_terms, list) {
F_81 ( & V_123 -> V_220 ) ;
free ( V_123 ) ;
}
}
void F_82 ( struct V_1 * T_1 , int V_202 , int V_203 )
{
int V_204 , V_205 ;
if ( T_1 -> V_206 )
V_203 = 1 ;
for ( V_204 = 0 ; V_204 < V_202 ; V_204 ++ )
for ( V_205 = 0 ; V_205 < V_203 ; ++ V_205 ) {
F_83 ( F_65 ( T_1 , V_204 , V_205 ) ) ;
F_65 ( T_1 , V_204 , V_205 ) = - 1 ;
}
}
void F_84 ( struct V_1 * T_1 )
{
assert ( F_85 ( & T_1 -> V_39 ) ) ;
assert ( T_1 -> V_37 == NULL ) ;
F_77 ( T_1 ) ;
F_78 ( T_1 ) ;
F_79 ( T_1 ) ;
F_86 ( T_1 -> V_221 ) ;
F_87 ( T_1 -> V_214 ) ;
F_87 ( T_1 -> V_222 ) ;
F_88 ( T_1 -> V_213 ) ;
F_26 ( & T_1 -> V_96 ) ;
F_26 ( & T_1 -> V_46 ) ;
V_5 . F_5 ( T_1 ) ;
}
void F_89 ( struct V_1 * T_1 )
{
F_84 ( T_1 ) ;
free ( T_1 ) ;
}
void F_90 ( struct V_1 * T_1 , int V_204 , int V_205 ,
struct V_223 * V_224 )
{
struct V_223 V_225 ;
if ( ! T_1 -> V_226 )
return;
if ( V_204 == - 1 ) {
V_225 = T_1 -> V_226 -> V_227 ;
T_1 -> V_226 -> V_227 = * V_224 ;
} else {
V_225 = * F_91 ( T_1 -> V_226 , V_204 , V_205 ) ;
* F_91 ( T_1 -> V_226 , V_204 , V_205 ) = * V_224 ;
}
V_224 -> V_127 = V_224 -> V_127 - V_225 . V_127 ;
V_224 -> V_228 = V_224 -> V_228 - V_225 . V_228 ;
V_224 -> V_229 = V_224 -> V_229 - V_225 . V_229 ;
}
void F_92 ( struct V_223 * V_224 ,
bool V_36 , T_8 * V_230 )
{
T_8 V_231 = 0 ;
if ( V_36 ) {
if ( V_224 -> V_229 == 0 ) {
V_231 = - 1 ;
V_224 -> V_127 = 0 ;
} else if ( V_224 -> V_229 < V_224 -> V_228 ) {
V_231 = 1 ;
V_224 -> V_127 = ( T_3 ) ( ( double ) V_224 -> V_127 * V_224 -> V_228 / V_224 -> V_229 + 0.5 ) ;
}
} else
V_224 -> V_228 = V_224 -> V_229 = 0 ;
if ( V_230 )
* V_230 = V_231 ;
}
int F_93 ( struct V_1 * T_1 , int V_204 , int V_205 ,
struct V_223 * V_224 )
{
memset ( V_224 , 0 , sizeof( * V_224 ) ) ;
if ( F_65 ( T_1 , V_204 , V_205 ) < 0 )
return - V_7 ;
if ( F_94 ( F_65 ( T_1 , V_204 , V_205 ) , V_224 , sizeof( * V_224 ) ) < 0 )
return - V_232 ;
return 0 ;
}
int F_95 ( struct V_1 * T_1 ,
int V_204 , int V_205 , bool V_36 )
{
struct V_223 V_224 ;
T_2 V_233 = V_36 ? 3 : 1 ;
if ( F_65 ( T_1 , V_204 , V_205 ) < 0 )
return - V_7 ;
if ( T_1 -> V_234 == NULL && F_96 ( T_1 , V_204 + 1 , V_205 + 1 ) < 0 )
return - V_48 ;
if ( F_94 ( F_65 ( T_1 , V_204 , V_205 ) , & V_224 , V_233 * sizeof( T_3 ) ) < 0 )
return - V_232 ;
F_90 ( T_1 , V_204 , V_205 , & V_224 ) ;
F_92 ( & V_224 , V_36 , NULL ) ;
* F_91 ( T_1 -> V_234 , V_204 , V_205 ) = V_224 ;
return 0 ;
}
static int F_97 ( struct V_1 * T_1 , int V_204 , int V_205 )
{
struct V_1 * V_34 = T_1 -> V_34 ;
int V_207 ;
if ( F_60 ( T_1 ) )
return - 1 ;
F_98 ( ! V_34 -> V_207 ) ;
V_207 = F_65 ( V_34 , V_204 , V_205 ) ;
F_98 ( V_207 == - 1 ) ;
return V_207 ;
}
static void F_99 ( char * V_97 , T_2 V_6 , T_3 V_235 , struct V_236 * V_237 )
{
bool V_238 = true ;
int V_11 = 0 ;
do {
if ( V_235 & V_237 [ V_11 ] . V_25 ) {
V_97 += F_31 ( V_97 , V_6 , L_38 , V_238 ? L_1 : L_39 , V_237 [ V_11 ] . V_46 ) ;
V_238 = false ;
}
} while ( V_237 [ ++ V_11 ] . V_46 != NULL );
}
static void F_100 ( char * V_97 , T_2 V_6 , T_3 V_235 )
{
#define F_101 ( T_9 ) { PERF_SAMPLE_##n, #n }
struct V_236 V_237 [] = {
F_101 ( V_150 ) , F_101 ( V_151 ) , F_101 ( TIME ) , F_101 ( V_165 ) ,
F_101 ( V_153 ) , F_101 ( V_104 ) , F_101 ( V_28 ) , F_101 ( V_171 ) ,
F_101 ( V_160 ) , F_101 ( V_239 ) , F_101 ( V_175 ) ,
F_101 ( V_108 ) , F_101 ( V_115 ) , F_101 ( V_116 ) ,
F_101 ( V_29 ) , F_101 ( V_170 ) , F_101 ( V_176 ) ,
F_101 ( V_181 ) ,
{ . V_46 = NULL , }
} ;
#undef F_101
F_99 ( V_97 , V_6 , V_235 , V_237 ) ;
}
static void F_102 ( char * V_97 , T_2 V_6 , T_3 V_235 )
{
#define F_101 ( T_9 ) { PERF_SAMPLE_BRANCH_##n, #n }
struct V_236 V_237 [] = {
F_101 ( V_240 ) , F_101 ( V_241 ) , F_101 ( V_242 ) , F_101 ( V_243 ) ,
F_101 ( V_244 ) , F_101 ( V_245 ) , F_101 ( V_246 ) ,
F_101 ( V_247 ) , F_101 ( V_248 ) , F_101 ( V_249 ) ,
F_101 ( V_250 ) , F_101 ( V_251 ) , F_101 ( V_252 ) ,
F_101 ( V_253 ) , F_101 ( V_254 ) , F_101 ( V_255 ) ,
{ . V_46 = NULL , }
} ;
#undef F_101
F_99 ( V_97 , V_6 , V_235 , V_237 ) ;
}
static void F_103 ( char * V_97 , T_2 V_6 , T_3 V_235 )
{
#define F_101 ( T_9 ) { PERF_FORMAT_##n, #n }
struct V_236 V_237 [] = {
F_101 ( V_256 ) , F_101 ( V_257 ) ,
F_101 ( V_28 ) , F_101 ( V_258 ) ,
{ . V_46 = NULL , }
} ;
#undef F_101
F_99 ( V_97 , V_6 , V_235 , V_237 ) ;
}
int F_104 ( T_10 * V_259 , struct V_32 * V_22 ,
T_11 V_260 , void * V_261 )
{
char V_97 [ V_262 ] ;
int V_90 = 0 ;
F_105 ( type , V_263 ) ;
F_105 ( V_6 , V_263 ) ;
F_105 ( V_53 , V_264 ) ;
F_106 ( L_40 , V_44 , V_263 ) ;
F_105 ( V_8 , V_265 ) ;
F_105 ( V_30 , V_266 ) ;
F_105 ( V_193 , V_263 ) ;
F_105 ( V_138 , V_263 ) ;
F_105 ( V_267 , V_263 ) ;
F_105 ( V_268 , V_263 ) ;
F_105 ( V_62 , V_263 ) ;
F_105 ( V_61 , V_263 ) ;
F_105 ( V_63 , V_263 ) ;
F_105 ( V_269 , V_263 ) ;
F_105 ( V_183 , V_263 ) ;
F_105 ( V_185 , V_263 ) ;
F_105 ( V_129 , V_263 ) ;
F_105 ( V_163 , V_263 ) ;
F_105 ( V_195 , V_263 ) ;
F_105 ( V_182 , V_263 ) ;
F_105 ( V_178 , V_263 ) ;
F_105 ( V_67 , V_263 ) ;
F_105 ( V_166 , V_263 ) ;
F_105 ( V_147 , V_263 ) ;
F_105 ( V_68 , V_263 ) ;
F_105 ( V_69 , V_263 ) ;
F_105 ( V_270 , V_263 ) ;
F_105 ( V_121 , V_263 ) ;
F_105 ( V_184 , V_263 ) ;
F_105 ( V_271 , V_263 ) ;
F_105 ( V_198 , V_263 ) ;
F_105 ( V_187 , V_263 ) ;
F_105 ( V_272 , V_263 ) ;
F_106 ( L_41 , V_179 , V_263 ) ;
F_105 ( V_80 , V_263 ) ;
F_106 ( L_42 , V_79 , V_264 ) ;
F_106 ( L_43 , V_273 , V_264 ) ;
F_105 ( V_109 , V_274 ) ;
F_105 ( V_117 , V_264 ) ;
F_105 ( V_119 , V_263 ) ;
F_105 ( V_197 , V_275 ) ;
F_105 ( V_169 , V_264 ) ;
F_105 ( V_276 , V_263 ) ;
return V_90 ;
}
static int F_107 ( struct V_1 * T_1 , struct V_277 * V_214 ,
struct V_278 * V_213 )
{
int V_204 , V_205 , V_203 ;
unsigned long V_279 = V_280 ;
int V_281 = - 1 , V_47 ;
enum { V_282 , V_283 , V_284 } V_285 = V_282 ;
if ( T_1 -> V_206 )
V_203 = 1 ;
else
V_203 = V_213 -> V_286 ;
if ( T_1 -> V_207 == NULL &&
F_63 ( T_1 , V_214 -> V_286 , V_203 ) < 0 )
return - V_48 ;
if ( T_1 -> V_221 ) {
V_279 |= V_287 ;
V_281 = T_1 -> V_221 -> V_207 ;
}
V_288:
if ( V_148 . V_289 )
T_1 -> V_22 . V_197 = V_290 ;
if ( V_148 . V_197 ) {
T_1 -> V_22 . V_198 = 0 ;
T_1 -> V_22 . V_197 = 0 ;
}
if ( V_148 . V_291 )
V_279 &= ~ ( unsigned long ) V_280 ;
if ( V_148 . V_184 )
T_1 -> V_22 . V_184 = 0 ;
if ( V_148 . V_69 )
T_1 -> V_22 . V_69 = T_1 -> V_22 . V_68 = 0 ;
if ( V_148 . V_292 )
T_1 -> V_22 . V_109 &= ~ ( V_113 |
V_112 ) ;
if ( V_148 . V_272 )
T_1 -> V_22 . V_272 = false ;
V_293:
if ( V_148 . V_147 )
T_1 -> V_22 . V_147 = 0 ;
if ( V_294 >= 2 ) {
fprintf ( V_295 , L_44 , V_296 ) ;
fprintf ( V_295 , L_45 ) ;
F_104 ( V_295 , & T_1 -> V_22 , V_297 , NULL ) ;
fprintf ( V_295 , L_44 , V_296 ) ;
}
for ( V_204 = 0 ; V_204 < V_214 -> V_286 ; V_204 ++ ) {
for ( V_205 = 0 ; V_205 < V_203 ; V_205 ++ ) {
int V_298 ;
if ( ! T_1 -> V_221 && ! T_1 -> V_206 )
V_281 = F_108 ( V_213 , V_205 ) ;
V_298 = F_97 ( T_1 , V_204 , V_205 ) ;
V_299:
F_109 ( L_46 ,
V_281 , V_214 -> V_300 [ V_204 ] , V_298 , V_279 ) ;
F_65 ( T_1 , V_204 , V_205 ) = F_110 ( & T_1 -> V_22 ,
V_281 ,
V_214 -> V_300 [ V_204 ] ,
V_298 , V_279 ) ;
if ( F_65 ( T_1 , V_204 , V_205 ) < 0 ) {
V_47 = - V_232 ;
F_109 ( L_47 ,
V_47 ) ;
goto V_301;
}
if ( T_1 -> V_38 >= 0 ) {
int V_302 = F_65 ( T_1 , V_204 , V_205 ) ;
int V_38 = T_1 -> V_38 ;
V_47 = F_67 ( V_302 ,
V_303 ,
V_38 ) ;
if ( V_47 && V_232 != V_304 ) {
F_56 ( L_48 ,
V_38 , strerror ( V_232 ) ) ;
V_47 = - V_7 ;
goto V_305;
}
}
V_285 = V_282 ;
if ( V_148 . V_197 ||
V_148 . V_289 ) {
V_47 = - V_7 ;
goto V_305;
}
if ( T_1 -> V_306 &&
V_148 . V_272 ) {
V_47 = - V_7 ;
goto V_305;
}
}
}
return 0 ;
V_301:
if ( V_47 == - V_307 && V_285 < V_284 ) {
struct V_308 V_309 ;
int V_310 = V_232 ;
if ( F_111 ( V_311 , & V_309 ) == 0 ) {
if ( V_285 == V_282 )
V_309 . V_312 = V_309 . V_313 ;
else {
V_309 . V_312 = V_309 . V_313 + 1000 ;
V_309 . V_313 = V_309 . V_312 ;
}
if ( F_112 ( V_311 , & V_309 ) == 0 ) {
V_285 ++ ;
V_232 = V_310 ;
goto V_299;
}
}
V_232 = V_310 ;
}
if ( V_47 != - V_7 || V_204 > 0 || V_205 > 0 )
goto V_305;
if ( ! V_148 . V_289 && T_1 -> V_22 . V_198 ) {
V_148 . V_289 = true ;
goto V_288;
} else if ( ! V_148 . V_197 && T_1 -> V_22 . V_198 ) {
V_148 . V_197 = true ;
goto V_288;
} else if ( ! V_148 . V_291 && ( V_279 & V_280 ) ) {
V_148 . V_291 = true ;
goto V_288;
} else if ( ! V_148 . V_184 && T_1 -> V_22 . V_184 ) {
V_148 . V_184 = true ;
goto V_288;
} else if ( ! V_148 . V_69 &&
( T_1 -> V_22 . V_69 || T_1 -> V_22 . V_68 ) ) {
V_148 . V_69 = true ;
goto V_288;
} else if ( ! V_148 . V_147 ) {
V_148 . V_147 = true ;
goto V_293;
} else if ( ! V_148 . V_292 &&
( T_1 -> V_22 . V_109 &
( V_112 |
V_113 ) ) ) {
V_148 . V_292 = true ;
goto V_288;
} else if ( ! V_148 . V_272 &&
T_1 -> V_22 . V_272 ) {
V_148 . V_272 = true ;
goto V_288;
}
V_305:
do {
while ( -- V_205 >= 0 ) {
F_83 ( F_65 ( T_1 , V_204 , V_205 ) ) ;
F_65 ( T_1 , V_204 , V_205 ) = - 1 ;
}
V_205 = V_203 ;
} while ( -- V_204 >= 0 );
return V_47 ;
}
void F_113 ( struct V_1 * T_1 , int V_202 , int V_203 )
{
if ( T_1 -> V_207 == NULL )
return;
F_82 ( T_1 , V_202 , V_203 ) ;
F_77 ( T_1 ) ;
}
int F_114 ( struct V_1 * T_1 , struct V_277 * V_214 ,
struct V_278 * V_213 )
{
if ( V_214 == NULL ) {
V_214 = & V_314 . V_300 ;
}
if ( V_213 == NULL )
V_213 = & V_315 . V_300 ;
return F_107 ( T_1 , V_214 , V_213 ) ;
}
int F_115 ( struct V_1 * T_1 ,
struct V_277 * V_214 )
{
return F_107 ( T_1 , V_214 , & V_315 . V_300 ) ;
}
int F_116 ( struct V_1 * T_1 ,
struct V_278 * V_213 )
{
return F_107 ( T_1 , & V_314 . V_300 , V_213 ) ;
}
static int F_117 ( const struct V_1 * T_1 ,
const union V_316 * V_317 ,
struct V_318 * V_319 )
{
T_3 type = T_1 -> V_22 . V_8 ;
const T_3 * V_320 = V_317 -> V_319 . V_320 ;
bool V_321 = T_1 -> V_322 ;
union V_323 V_324 ;
V_320 += ( ( V_317 -> V_325 . V_6 -
sizeof( V_317 -> V_325 ) ) / sizeof( T_3 ) ) - 1 ;
if ( type & V_13 ) {
V_319 -> V_54 = * V_320 ;
V_320 -- ;
}
if ( type & V_19 ) {
V_324 . V_326 = * V_320 ;
if ( V_321 ) {
V_324 . V_326 = F_118 ( V_324 . V_326 ) ;
V_324 . V_327 [ 0 ] = F_119 ( V_324 . V_327 [ 0 ] ) ;
}
V_319 -> V_204 = V_324 . V_327 [ 0 ] ;
V_320 -- ;
}
if ( type & V_20 ) {
V_319 -> V_328 = * V_320 ;
V_320 -- ;
}
if ( type & V_14 ) {
V_319 -> V_54 = * V_320 ;
V_320 -- ;
}
if ( type & V_17 ) {
V_319 -> time = * V_320 ;
V_320 -- ;
}
if ( type & V_16 ) {
V_324 . V_326 = * V_320 ;
if ( V_321 ) {
V_324 . V_326 = F_118 ( V_324 . V_326 ) ;
V_324 . V_327 [ 0 ] = F_119 ( V_324 . V_327 [ 0 ] ) ;
V_324 . V_327 [ 1 ] = F_119 ( V_324 . V_327 [ 1 ] ) ;
}
V_319 -> V_281 = V_324 . V_327 [ 0 ] ;
V_319 -> V_329 = V_324 . V_327 [ 1 ] ;
V_320 -- ;
}
return 0 ;
}
static inline bool F_120 ( const void * V_330 , T_12 V_331 , const void * V_332 ,
T_3 V_6 )
{
return V_6 > V_331 || V_332 + V_6 > V_330 ;
}
int F_121 ( struct V_1 * T_1 , union V_316 * V_317 ,
struct V_318 * V_333 )
{
T_3 type = T_1 -> V_22 . V_8 ;
bool V_321 = T_1 -> V_322 ;
const T_3 * V_320 ;
T_12 V_331 = V_317 -> V_325 . V_6 ;
const void * V_330 = ( void * ) V_317 + V_331 ;
T_3 V_334 ;
union V_323 V_324 ;
memset ( V_333 , 0 , sizeof( * V_333 ) ) ;
V_333 -> V_204 = V_333 -> V_281 = V_333 -> V_329 = - 1 ;
V_333 -> V_328 = V_333 -> V_54 = V_333 -> time = - 1ULL ;
V_333 -> V_128 = T_1 -> V_22 . V_44 ;
V_333 -> V_335 = 0 ;
V_333 -> V_336 = V_317 -> V_325 . V_337 & V_338 ;
if ( V_317 -> V_325 . type != V_339 ) {
if ( ! T_1 -> V_22 . V_147 )
return 0 ;
return F_117 ( T_1 , V_317 , V_333 ) ;
}
V_320 = V_317 -> V_319 . V_320 ;
if ( T_1 -> V_26 + sizeof( V_317 -> V_325 ) > V_317 -> V_325 . V_6 )
return - V_340 ;
V_333 -> V_54 = - 1ULL ;
if ( type & V_13 ) {
V_333 -> V_54 = * V_320 ;
V_320 ++ ;
}
if ( type & V_15 ) {
V_333 -> V_341 = * V_320 ;
V_320 ++ ;
}
if ( type & V_16 ) {
V_324 . V_326 = * V_320 ;
if ( V_321 ) {
V_324 . V_326 = F_118 ( V_324 . V_326 ) ;
V_324 . V_327 [ 0 ] = F_119 ( V_324 . V_327 [ 0 ] ) ;
V_324 . V_327 [ 1 ] = F_119 ( V_324 . V_327 [ 1 ] ) ;
}
V_333 -> V_281 = V_324 . V_327 [ 0 ] ;
V_333 -> V_329 = V_324 . V_327 [ 1 ] ;
V_320 ++ ;
}
if ( type & V_17 ) {
V_333 -> time = * V_320 ;
V_320 ++ ;
}
V_333 -> V_74 = 0 ;
if ( type & V_18 ) {
V_333 -> V_74 = * V_320 ;
V_320 ++ ;
}
if ( type & V_14 ) {
V_333 -> V_54 = * V_320 ;
V_320 ++ ;
}
if ( type & V_20 ) {
V_333 -> V_328 = * V_320 ;
V_320 ++ ;
}
if ( type & V_19 ) {
V_324 . V_326 = * V_320 ;
if ( V_321 ) {
V_324 . V_326 = F_118 ( V_324 . V_326 ) ;
V_324 . V_327 [ 0 ] = F_119 ( V_324 . V_327 [ 0 ] ) ;
}
V_333 -> V_204 = V_324 . V_327 [ 0 ] ;
V_320 ++ ;
}
if ( type & V_43 ) {
V_333 -> V_128 = * V_320 ;
V_320 ++ ;
}
if ( type & V_342 ) {
T_3 V_30 = T_1 -> V_22 . V_30 ;
F_122 ( V_320 ) ;
if ( V_30 & V_155 )
V_333 -> V_343 . V_344 . V_286 = * V_320 ;
else
V_333 -> V_343 . V_345 . V_235 = * V_320 ;
V_320 ++ ;
if ( V_30 & V_191 ) {
F_122 ( V_320 ) ;
V_333 -> V_343 . V_346 = * V_320 ;
V_320 ++ ;
}
if ( V_30 & V_192 ) {
F_122 ( V_320 ) ;
V_333 -> V_343 . V_347 = * V_320 ;
V_320 ++ ;
}
if ( V_30 & V_155 ) {
const T_3 V_348 = V_349 /
sizeof( struct V_350 ) ;
if ( V_333 -> V_343 . V_344 . V_286 > V_348 )
return - V_340 ;
V_334 = V_333 -> V_343 . V_344 . V_286 *
sizeof( struct V_350 ) ;
F_123 ( V_320 , V_334 , V_331 ) ;
V_333 -> V_343 . V_344 . V_351 =
(struct V_350 * ) V_320 ;
V_320 = ( void * ) V_320 + V_334 ;
} else {
F_122 ( V_320 ) ;
V_333 -> V_343 . V_345 . V_54 = * V_320 ;
V_320 ++ ;
}
}
if ( type & V_352 ) {
const T_3 V_353 = V_349 / sizeof( T_3 ) ;
F_122 ( V_320 ) ;
V_333 -> V_141 = (struct V_354 * ) V_320 ++ ;
if ( V_333 -> V_141 -> V_286 > V_353 )
return - V_340 ;
V_334 = V_333 -> V_141 -> V_286 * sizeof( T_3 ) ;
F_123 ( V_320 , V_334 , V_331 ) ;
V_320 = ( void * ) V_320 + V_334 ;
}
if ( type & V_42 ) {
F_122 ( V_320 ) ;
V_324 . V_326 = * V_320 ;
if ( F_124 ( V_321 ,
L_49 ) ) {
V_324 . V_326 = F_118 ( V_324 . V_326 ) ;
V_324 . V_327 [ 0 ] = F_119 ( V_324 . V_327 [ 0 ] ) ;
V_324 . V_327 [ 1 ] = F_119 ( V_324 . V_327 [ 1 ] ) ;
}
V_333 -> V_355 = V_324 . V_327 [ 0 ] ;
V_320 = ( void * ) V_320 + sizeof( T_7 ) ;
F_123 ( V_320 , V_333 -> V_355 , V_331 ) ;
V_333 -> V_356 = ( void * ) V_320 ;
V_320 = ( void * ) V_320 + V_333 -> V_355 ;
}
if ( type & V_357 ) {
const T_3 V_358 = V_349 /
sizeof( struct V_359 ) ;
F_122 ( V_320 ) ;
V_333 -> V_107 = (struct V_107 * ) V_320 ++ ;
if ( V_333 -> V_107 -> V_286 > V_358 )
return - V_340 ;
V_334 = V_333 -> V_107 -> V_286 * sizeof( struct V_359 ) ;
F_123 ( V_320 , V_334 , V_331 ) ;
V_320 = ( void * ) V_320 + V_334 ;
}
if ( type & V_360 ) {
F_122 ( V_320 ) ;
V_333 -> V_361 . V_362 = * V_320 ;
V_320 ++ ;
if ( V_333 -> V_361 . V_362 ) {
T_3 V_9 = T_1 -> V_22 . V_117 ;
V_334 = F_125 ( V_9 ) * sizeof( T_3 ) ;
F_123 ( V_320 , V_334 , V_331 ) ;
V_333 -> V_361 . V_9 = V_9 ;
V_333 -> V_361 . V_363 = ( T_3 * ) V_320 ;
V_320 = ( void * ) V_320 + V_334 ;
}
}
if ( type & V_364 ) {
F_122 ( V_320 ) ;
V_334 = * V_320 ++ ;
V_333 -> V_365 . V_332 = ( ( char * ) ( V_320 - 1 )
- ( char * ) V_317 ) ;
if ( ! V_334 ) {
V_333 -> V_365 . V_6 = 0 ;
} else {
F_123 ( V_320 , V_334 , V_331 ) ;
V_333 -> V_365 . V_333 = ( char * ) V_320 ;
V_320 = ( void * ) V_320 + V_334 ;
F_122 ( V_320 ) ;
V_333 -> V_365 . V_6 = * V_320 ++ ;
if ( F_124 ( V_333 -> V_365 . V_6 > V_334 ,
L_50 ) )
return - V_340 ;
}
}
V_333 -> V_335 = 0 ;
if ( type & V_366 ) {
F_122 ( V_320 ) ;
V_333 -> V_335 = * V_320 ;
V_320 ++ ;
}
V_333 -> V_367 = V_368 ;
if ( type & V_369 ) {
F_122 ( V_320 ) ;
V_333 -> V_367 = * V_320 ;
V_320 ++ ;
}
V_333 -> V_370 = 0 ;
if ( type & V_371 ) {
F_122 ( V_320 ) ;
V_333 -> V_370 = * V_320 ;
V_320 ++ ;
}
V_333 -> V_372 . V_362 = V_373 ;
if ( type & V_374 ) {
F_122 ( V_320 ) ;
V_333 -> V_372 . V_362 = * V_320 ;
V_320 ++ ;
if ( V_333 -> V_372 . V_362 != V_373 ) {
T_3 V_9 = T_1 -> V_22 . V_169 ;
V_334 = F_125 ( V_9 ) * sizeof( T_3 ) ;
F_123 ( V_320 , V_334 , V_331 ) ;
V_333 -> V_372 . V_9 = V_9 ;
V_333 -> V_372 . V_363 = ( T_3 * ) V_320 ;
V_320 = ( void * ) V_320 + V_334 ;
}
}
return 0 ;
}
T_2 F_126 ( const struct V_318 * V_319 , T_3 type ,
T_3 V_30 )
{
T_2 V_334 , V_83 = sizeof( struct V_375 ) ;
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
if ( type & V_43 )
V_83 += sizeof( T_3 ) ;
if ( type & V_342 ) {
V_83 += sizeof( T_3 ) ;
if ( V_30 & V_191 )
V_83 += sizeof( T_3 ) ;
if ( V_30 & V_192 )
V_83 += sizeof( T_3 ) ;
if ( V_30 & V_155 ) {
V_334 = V_319 -> V_343 . V_344 . V_286 *
sizeof( struct V_350 ) ;
V_83 += V_334 ;
} else {
V_83 += sizeof( T_3 ) ;
}
}
if ( type & V_352 ) {
V_334 = ( V_319 -> V_141 -> V_286 + 1 ) * sizeof( T_3 ) ;
V_83 += V_334 ;
}
if ( type & V_42 ) {
V_83 += sizeof( T_7 ) ;
V_83 += V_319 -> V_355 ;
}
if ( type & V_357 ) {
V_334 = V_319 -> V_107 -> V_286 * sizeof( struct V_359 ) ;
V_334 += sizeof( T_3 ) ;
V_83 += V_334 ;
}
if ( type & V_360 ) {
if ( V_319 -> V_361 . V_362 ) {
V_83 += sizeof( T_3 ) ;
V_334 = F_125 ( V_319 -> V_361 . V_9 ) * sizeof( T_3 ) ;
V_83 += V_334 ;
} else {
V_83 += sizeof( T_3 ) ;
}
}
if ( type & V_364 ) {
V_334 = V_319 -> V_365 . V_6 ;
V_83 += sizeof( T_3 ) ;
if ( V_334 ) {
V_83 += V_334 ;
V_83 += sizeof( T_3 ) ;
}
}
if ( type & V_366 )
V_83 += sizeof( T_3 ) ;
if ( type & V_369 )
V_83 += sizeof( T_3 ) ;
if ( type & V_371 )
V_83 += sizeof( T_3 ) ;
if ( type & V_374 ) {
if ( V_319 -> V_372 . V_362 ) {
V_83 += sizeof( T_3 ) ;
V_334 = F_125 ( V_319 -> V_372 . V_9 ) * sizeof( T_3 ) ;
V_83 += V_334 ;
} else {
V_83 += sizeof( T_3 ) ;
}
}
return V_83 ;
}
int F_127 ( union V_316 * V_317 , T_3 type ,
T_3 V_30 ,
const struct V_318 * V_319 ,
bool V_321 )
{
T_3 * V_320 ;
T_2 V_334 ;
union V_323 V_324 ;
V_320 = V_317 -> V_319 . V_320 ;
if ( type & V_13 ) {
* V_320 = V_319 -> V_54 ;
V_320 ++ ;
}
if ( type & V_15 ) {
* V_320 = V_319 -> V_341 ;
V_320 ++ ;
}
if ( type & V_16 ) {
V_324 . V_327 [ 0 ] = V_319 -> V_281 ;
V_324 . V_327 [ 1 ] = V_319 -> V_329 ;
if ( V_321 ) {
V_324 . V_327 [ 0 ] = F_119 ( V_324 . V_327 [ 0 ] ) ;
V_324 . V_327 [ 1 ] = F_119 ( V_324 . V_327 [ 1 ] ) ;
V_324 . V_326 = F_118 ( V_324 . V_326 ) ;
}
* V_320 = V_324 . V_326 ;
V_320 ++ ;
}
if ( type & V_17 ) {
* V_320 = V_319 -> time ;
V_320 ++ ;
}
if ( type & V_18 ) {
* V_320 = V_319 -> V_74 ;
V_320 ++ ;
}
if ( type & V_14 ) {
* V_320 = V_319 -> V_54 ;
V_320 ++ ;
}
if ( type & V_20 ) {
* V_320 = V_319 -> V_328 ;
V_320 ++ ;
}
if ( type & V_19 ) {
V_324 . V_327 [ 0 ] = V_319 -> V_204 ;
if ( V_321 ) {
V_324 . V_327 [ 0 ] = F_119 ( V_324 . V_327 [ 0 ] ) ;
V_324 . V_326 = F_118 ( V_324 . V_326 ) ;
}
* V_320 = V_324 . V_326 ;
V_320 ++ ;
}
if ( type & V_43 ) {
* V_320 = V_319 -> V_128 ;
V_320 ++ ;
}
if ( type & V_342 ) {
if ( V_30 & V_155 )
* V_320 = V_319 -> V_343 . V_344 . V_286 ;
else
* V_320 = V_319 -> V_343 . V_345 . V_235 ;
V_320 ++ ;
if ( V_30 & V_191 ) {
* V_320 = V_319 -> V_343 . V_346 ;
V_320 ++ ;
}
if ( V_30 & V_192 ) {
* V_320 = V_319 -> V_343 . V_347 ;
V_320 ++ ;
}
if ( V_30 & V_155 ) {
V_334 = V_319 -> V_343 . V_344 . V_286 *
sizeof( struct V_350 ) ;
memcpy ( V_320 , V_319 -> V_343 . V_344 . V_351 , V_334 ) ;
V_320 = ( void * ) V_320 + V_334 ;
} else {
* V_320 = V_319 -> V_343 . V_345 . V_54 ;
V_320 ++ ;
}
}
if ( type & V_352 ) {
V_334 = ( V_319 -> V_141 -> V_286 + 1 ) * sizeof( T_3 ) ;
memcpy ( V_320 , V_319 -> V_141 , V_334 ) ;
V_320 = ( void * ) V_320 + V_334 ;
}
if ( type & V_42 ) {
V_324 . V_327 [ 0 ] = V_319 -> V_355 ;
if ( F_124 ( V_321 ,
L_49 ) ) {
V_324 . V_327 [ 0 ] = F_119 ( V_324 . V_327 [ 0 ] ) ;
V_324 . V_327 [ 1 ] = F_119 ( V_324 . V_327 [ 1 ] ) ;
V_324 . V_326 = F_118 ( V_324 . V_326 ) ;
}
* V_320 = V_324 . V_326 ;
V_320 = ( void * ) V_320 + sizeof( T_7 ) ;
memcpy ( V_320 , V_319 -> V_356 , V_319 -> V_355 ) ;
V_320 = ( void * ) V_320 + V_319 -> V_355 ;
}
if ( type & V_357 ) {
V_334 = V_319 -> V_107 -> V_286 * sizeof( struct V_359 ) ;
V_334 += sizeof( T_3 ) ;
memcpy ( V_320 , V_319 -> V_107 , V_334 ) ;
V_320 = ( void * ) V_320 + V_334 ;
}
if ( type & V_360 ) {
if ( V_319 -> V_361 . V_362 ) {
* V_320 ++ = V_319 -> V_361 . V_362 ;
V_334 = F_125 ( V_319 -> V_361 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_320 , V_319 -> V_361 . V_363 , V_334 ) ;
V_320 = ( void * ) V_320 + V_334 ;
} else {
* V_320 ++ = 0 ;
}
}
if ( type & V_364 ) {
V_334 = V_319 -> V_365 . V_6 ;
* V_320 ++ = V_334 ;
if ( V_334 ) {
memcpy ( V_320 , V_319 -> V_365 . V_333 , V_334 ) ;
V_320 = ( void * ) V_320 + V_334 ;
* V_320 ++ = V_334 ;
}
}
if ( type & V_366 ) {
* V_320 = V_319 -> V_335 ;
V_320 ++ ;
}
if ( type & V_369 ) {
* V_320 = V_319 -> V_367 ;
V_320 ++ ;
}
if ( type & V_371 ) {
* V_320 = V_319 -> V_370 ;
V_320 ++ ;
}
if ( type & V_374 ) {
if ( V_319 -> V_372 . V_362 ) {
* V_320 ++ = V_319 -> V_372 . V_362 ;
V_334 = F_125 ( V_319 -> V_372 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_320 , V_319 -> V_372 . V_363 , V_334 ) ;
V_320 = ( void * ) V_320 + V_334 ;
} else {
* V_320 ++ = 0 ;
}
}
return 0 ;
}
struct V_376 * F_128 ( struct V_1 * T_1 , const char * V_46 )
{
return F_129 ( T_1 -> V_52 , V_46 ) ;
}
void * F_130 ( struct V_1 * T_1 , struct V_318 * V_319 ,
const char * V_46 )
{
struct V_376 * V_377 = F_128 ( T_1 , V_46 ) ;
int V_332 ;
if ( ! V_377 )
return NULL ;
V_332 = V_377 -> V_332 ;
if ( V_377 -> V_279 & V_378 ) {
V_332 = * ( int * ) ( V_319 -> V_356 + V_377 -> V_332 ) ;
V_332 &= 0xffff ;
}
return V_319 -> V_356 + V_332 ;
}
T_3 F_131 ( struct V_1 * T_1 , struct V_318 * V_319 ,
const char * V_46 )
{
struct V_376 * V_377 = F_128 ( T_1 , V_46 ) ;
void * V_379 ;
T_3 V_235 ;
if ( ! V_377 )
return 0 ;
V_379 = V_319 -> V_356 + V_377 -> V_332 ;
switch ( V_377 -> V_6 ) {
case 1 :
return * ( T_6 * ) V_379 ;
case 2 :
V_235 = * ( T_12 * ) V_379 ;
break;
case 4 :
V_235 = * ( T_7 * ) V_379 ;
break;
case 8 :
memcpy ( & V_235 , V_379 , sizeof( T_3 ) ) ;
break;
default:
return 0 ;
}
if ( ! T_1 -> V_322 )
return V_235 ;
switch ( V_377 -> V_6 ) {
case 2 :
return F_132 ( V_235 ) ;
case 4 :
return F_119 ( V_235 ) ;
case 8 :
return F_118 ( V_235 ) ;
default:
return 0 ;
}
return 0 ;
}
bool F_133 ( struct V_1 * T_1 , int V_47 ,
char * V_380 , T_2 V_381 )
{
int V_382 ;
if ( ( V_47 == V_383 || V_47 == V_384 || V_47 == V_385 ) &&
T_1 -> V_22 . type == V_92 &&
T_1 -> V_22 . V_53 == V_386 ) {
F_31 ( V_380 , V_381 , L_6 ,
L_51 ) ;
T_1 -> V_22 . type = V_94 ;
T_1 -> V_22 . V_53 = V_387 ;
F_26 ( & T_1 -> V_46 ) ;
return true ;
} else if ( V_47 == V_388 && ! T_1 -> V_22 . V_61 &&
( V_382 = F_134 () ) > 1 ) {
const char * V_46 = F_43 ( T_1 ) ;
char * V_389 ;
if ( F_21 ( & V_389 , L_52 , V_46 , strchr ( V_46 , ':' ) ? L_1 : L_9 ) < 0 )
return false ;
if ( T_1 -> V_46 )
free ( T_1 -> V_46 ) ;
T_1 -> V_46 = V_389 ;
F_31 ( V_380 , V_381 ,
L_53 , V_382 ) ;
T_1 -> V_22 . V_61 = 1 ;
return true ;
}
return false ;
}
int F_135 ( struct V_1 * T_1 , struct V_144 * V_144 ,
int V_47 , char * V_380 , T_2 V_6 )
{
char V_390 [ V_391 ] ;
switch ( V_47 ) {
case V_392 :
case V_388 :
return F_31 ( V_380 , V_6 ,
L_54
L_55
L_56
L_57
L_58
L_59
L_60
L_61
L_62 ,
V_144 -> V_206 ? L_63 : L_1 ,
F_134 () ) ;
case V_383 :
return F_31 ( V_380 , V_6 , L_64 ,
F_43 ( T_1 ) ) ;
case V_307 :
return F_31 ( V_380 , V_6 , L_6 ,
L_65
L_66
L_67
L_68 ) ;
case V_48 :
if ( ( T_1 -> V_22 . V_8 & V_352 ) != 0 &&
F_136 ( L_69 , V_393 ) == 0 )
return F_31 ( V_380 , V_6 ,
L_70
L_71
L_72 , V_394 ) ;
break;
case V_385 :
if ( V_144 -> V_395 )
return F_31 ( V_380 , V_6 , L_6 ,
L_73 ) ;
break;
case V_396 :
if ( T_1 -> V_22 . V_67 )
return F_31 ( V_380 , V_6 , L_6 ,
L_74 ) ;
#if F_137 ( V_397 ) || F_137 ( V_398 )
if ( T_1 -> V_22 . type == V_92 )
return F_31 ( V_380 , V_6 , L_6 ,
L_75
L_76 ) ;
#endif
break;
case V_399 :
if ( F_138 ( L_77 ) )
return F_31 ( V_380 , V_6 ,
L_78
L_79 ) ;
break;
case V_7 :
if ( V_148 . V_197 )
return F_31 ( V_380 , V_6 , L_80 ) ;
if ( V_148 . V_289 )
return F_31 ( V_380 , V_6 , L_81 , V_197 ) ;
break;
default:
break;
}
return F_31 ( V_380 , V_6 ,
L_82
L_83
L_84 ,
V_47 , F_139 ( V_47 , V_390 , sizeof( V_390 ) ) ,
F_43 ( T_1 ) ) ;
}
