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
F_16 ( & T_1 -> V_38 ) ;
F_16 ( & T_1 -> V_39 ) ;
V_5 . F_4 ( T_1 ) ;
T_1 -> V_26 = F_6 ( V_22 -> V_8 ) ;
F_9 ( T_1 ) ;
T_1 -> V_40 = false ;
}
struct V_1 * F_17 ( struct V_32 * V_22 , int V_12 )
{
struct V_1 * T_1 = F_18 ( V_5 . V_6 ) ;
if ( T_1 != NULL )
F_15 ( T_1 , V_22 , V_12 ) ;
return T_1 ;
}
struct V_1 * F_19 ( const char * V_41 , const char * V_42 , int V_12 )
{
struct V_1 * T_1 = F_18 ( V_5 . V_6 ) ;
if ( T_1 != NULL ) {
struct V_32 V_22 = {
. type = V_43 ,
. V_8 = ( V_44 | V_17 |
V_19 | V_45 ) ,
} ;
if ( F_20 ( & T_1 -> V_42 , L_2 , V_41 , V_42 ) < 0 )
goto V_46;
T_1 -> V_47 = F_21 ( V_41 , V_42 ) ;
if ( T_1 -> V_47 == NULL )
goto V_46;
F_22 ( & V_22 ) ;
V_22 . V_48 = T_1 -> V_47 -> V_49 ;
V_22 . V_50 = 1 ;
F_15 ( T_1 , & V_22 , V_12 ) ;
}
return T_1 ;
V_46:
F_23 ( & T_1 -> V_42 ) ;
free ( T_1 ) ;
return NULL ;
}
static const char * F_24 ( T_3 V_48 )
{
if ( V_48 < V_51 && V_52 [ V_48 ] )
return V_52 [ V_48 ] ;
return L_3 ;
}
static int F_25 ( struct V_1 * T_1 , char * V_53 , T_2 V_6 )
{
int V_54 = 0 , V_55 = 0 ;
struct V_32 * V_22 = & T_1 -> V_22 ;
bool V_56 = false ;
#define F_26 ( T_4 , T_5 ) do { \
if (!attr->exclude_##context) { \
if (!colon) colon = ++r; \
r += scnprintf(bf + r, size - r, "%c", mod); \
} } while(0)
if ( V_22 -> V_57 || V_22 -> V_58 || V_22 -> V_59 ) {
F_26 ( V_60 , 'k' ) ;
F_26 ( V_61 , 'u' ) ;
F_26 ( V_62 , 'h' ) ;
V_56 = true ;
}
if ( V_22 -> V_63 ) {
if ( ! V_54 )
V_54 = ++ V_55 ;
V_55 += F_27 ( V_53 + V_55 , V_6 - V_55 , L_4 , V_22 -> V_63 , L_5 ) ;
V_56 = true ;
}
if ( V_22 -> V_64 || V_22 -> V_65 == V_56 ) {
F_26 ( V_66 , 'H' ) ;
F_26 ( V_67 , 'G' ) ;
}
#undef F_26
if ( V_54 )
V_53 [ V_54 - 1 ] = ':' ;
return V_55 ;
}
static int F_28 ( struct V_1 * T_1 , char * V_53 , T_2 V_6 )
{
int V_55 = F_27 ( V_53 , V_6 , L_6 , F_24 ( T_1 -> V_22 . V_48 ) ) ;
return V_55 + F_25 ( T_1 , V_53 + V_55 , V_6 - V_55 ) ;
}
static const char * F_29 ( T_3 V_48 )
{
if ( V_48 < V_68 && V_69 [ V_48 ] )
return V_69 [ V_48 ] ;
return L_7 ;
}
static int F_30 ( struct V_1 * T_1 , char * V_53 , T_2 V_6 )
{
int V_55 = F_27 ( V_53 , V_6 , L_6 , F_29 ( T_1 -> V_22 . V_48 ) ) ;
return V_55 + F_25 ( T_1 , V_53 + V_55 , V_6 - V_55 ) ;
}
static int F_31 ( char * V_53 , T_2 V_6 , T_3 V_70 , T_3 type )
{
int V_55 ;
V_55 = F_27 ( V_53 , V_6 , L_8 V_71 L_9 , V_70 ) ;
if ( type & V_72 )
V_55 += F_27 ( V_53 + V_55 , V_6 - V_55 , L_10 ) ;
if ( type & V_73 )
V_55 += F_27 ( V_53 + V_55 , V_6 - V_55 , L_11 ) ;
if ( type & V_74 )
V_55 += F_27 ( V_53 + V_55 , V_6 - V_55 , L_12 ) ;
return V_55 ;
}
static int F_32 ( struct V_1 * T_1 , char * V_53 , T_2 V_6 )
{
struct V_32 * V_22 = & T_1 -> V_22 ;
int V_55 = F_31 ( V_53 , V_6 , V_22 -> V_75 , V_22 -> V_76 ) ;
return V_55 + F_25 ( T_1 , V_53 + V_55 , V_6 - V_55 ) ;
}
bool F_33 ( T_6 type , T_6 V_77 )
{
if ( V_78 [ type ] & F_34 ( V_77 ) )
return true ;
else
return false ;
}
int F_35 ( T_6 type , T_6 V_77 , T_6 V_79 ,
char * V_53 , T_2 V_6 )
{
if ( V_79 ) {
return F_27 ( V_53 , V_6 , L_13 , V_80 [ type ] [ 0 ] ,
V_81 [ V_77 ] [ 0 ] ,
V_82 [ V_79 ] [ 0 ] ) ;
}
return F_27 ( V_53 , V_6 , L_14 , V_80 [ type ] [ 0 ] ,
V_81 [ V_77 ] [ 1 ] ) ;
}
static int F_36 ( T_3 V_48 , char * V_53 , T_2 V_6 )
{
T_6 V_77 , V_79 , type = ( V_48 >> 0 ) & 0xff ;
const char * V_83 = L_15 ;
if ( type > V_84 )
goto V_85;
V_77 = ( V_48 >> 8 ) & 0xff ;
V_83 = L_16 ;
if ( V_77 > V_86 )
goto V_85;
V_79 = ( V_48 >> 16 ) & 0xff ;
V_83 = L_17 ;
if ( V_79 > V_87 )
goto V_85;
V_83 = L_18 ;
if ( ! F_33 ( type , V_77 ) )
goto V_85;
return F_35 ( type , V_77 , V_79 , V_53 , V_6 ) ;
V_85:
return F_27 ( V_53 , V_6 , L_6 , V_83 ) ;
}
static int F_37 ( struct V_1 * T_1 , char * V_53 , T_2 V_6 )
{
int V_88 = F_36 ( T_1 -> V_22 . V_48 , V_53 , V_6 ) ;
return V_88 + F_25 ( T_1 , V_53 + V_88 , V_6 - V_88 ) ;
}
static int F_38 ( struct V_1 * T_1 , char * V_53 , T_2 V_6 )
{
int V_88 = F_27 ( V_53 , V_6 , L_19 V_71 , T_1 -> V_22 . V_48 ) ;
return V_88 + F_25 ( T_1 , V_53 + V_88 , V_6 - V_88 ) ;
}
const char * F_39 ( struct V_1 * T_1 )
{
char V_53 [ 128 ] ;
if ( T_1 -> V_42 )
return T_1 -> V_42 ;
switch ( T_1 -> V_22 . type ) {
case V_89 :
F_38 ( T_1 , V_53 , sizeof( V_53 ) ) ;
break;
case V_90 :
F_28 ( T_1 , V_53 , sizeof( V_53 ) ) ;
break;
case V_91 :
F_37 ( T_1 , V_53 , sizeof( V_53 ) ) ;
break;
case V_92 :
F_30 ( T_1 , V_53 , sizeof( V_53 ) ) ;
break;
case V_43 :
F_27 ( V_53 , sizeof( V_53 ) , L_6 , L_20 ) ;
break;
case V_93 :
F_32 ( T_1 , V_53 , sizeof( V_53 ) ) ;
break;
default:
F_27 ( V_53 , sizeof( V_53 ) , L_21 ,
T_1 -> V_22 . type ) ;
break;
}
T_1 -> V_42 = F_40 ( V_53 ) ;
return T_1 -> V_42 ? : L_22 ;
}
const char * F_41 ( struct V_1 * T_1 )
{
return T_1 -> V_94 ? : L_23 ;
}
int F_42 ( struct V_1 * T_1 , char * V_95 , T_2 V_6 )
{
int V_88 ;
struct V_1 * V_96 ;
const char * V_94 = F_41 ( T_1 ) ;
V_88 = F_27 ( V_95 , V_6 , L_6 , V_94 ) ;
V_88 += F_27 ( V_95 + V_88 , V_6 - V_88 , L_24 ,
F_39 ( T_1 ) ) ;
F_43 (pos, evsel)
V_88 += F_27 ( V_95 + V_88 , V_6 - V_88 , L_25 ,
F_39 ( V_96 ) ) ;
V_88 += F_27 ( V_95 + V_88 , V_6 - V_88 , L_26 ) ;
return V_88 ;
}
static void
F_44 ( struct V_1 * T_1 ,
struct V_97 * V_98 ,
struct V_99 * V_100 )
{
bool V_101 = F_45 ( T_1 ) ;
struct V_32 * V_22 = & T_1 -> V_22 ;
F_14 ( T_1 , V_102 ) ;
if ( V_100 -> V_103 == V_104 ) {
if ( ! V_98 -> V_105 ) {
if ( V_22 -> V_58 ) {
F_46 ( L_27
L_28
L_29 ) ;
} else {
F_14 ( T_1 , V_106 ) ;
V_22 -> V_107 = V_108 |
V_109 ;
}
} else
F_46 ( L_30
L_29 ) ;
}
if ( V_100 -> V_103 == V_110 ) {
if ( ! V_101 ) {
F_14 ( T_1 , V_111 ) ;
F_14 ( T_1 , V_112 ) ;
V_22 -> V_113 = V_114 ;
V_22 -> V_115 = V_100 -> V_116 ;
V_22 -> V_117 = 1 ;
} else {
F_47 ( L_31
L_32 ) ;
}
}
if ( V_101 ) {
F_47 ( L_33 ) ;
V_22 -> V_117 = 1 ;
}
}
static void
F_48 ( struct V_1 * T_1 ,
struct V_99 * V_100 )
{
struct V_32 * V_22 = & T_1 -> V_22 ;
F_13 ( T_1 , V_102 ) ;
if ( V_100 -> V_103 == V_104 ) {
F_13 ( T_1 , V_106 ) ;
V_22 -> V_107 &= ~ ( V_108 |
V_109 ) ;
}
if ( V_100 -> V_103 == V_110 ) {
F_13 ( T_1 , V_111 ) ;
F_13 ( T_1 , V_112 ) ;
}
}
static void F_49 ( struct V_1 * T_1 ,
struct V_97 * V_98 )
{
struct V_118 * V_119 ;
struct V_120 * V_39 = & T_1 -> V_39 ;
struct V_32 * V_22 = & T_1 -> V_22 ;
struct V_99 V_100 ;
T_7 V_116 = 0 ;
char * V_121 = NULL ;
V_100 . V_103 = V_99 . V_103 ;
F_50 (term, config_terms, list) {
switch ( V_119 -> type ) {
case V_122 :
V_22 -> V_50 = V_119 -> V_123 . V_124 ;
V_22 -> V_125 = 0 ;
break;
case V_126 :
V_22 -> V_127 = V_119 -> V_123 . V_125 ;
V_22 -> V_125 = 1 ;
break;
case V_128 :
if ( V_119 -> V_123 . time )
F_14 ( T_1 , TIME ) ;
else
F_13 ( T_1 , TIME ) ;
break;
case V_129 :
V_121 = V_119 -> V_123 . V_130 ;
break;
case V_131 :
V_116 = V_119 -> V_123 . V_132 ;
break;
default:
break;
}
}
if ( ( V_121 != NULL ) || ( V_116 > 0 ) ) {
if ( V_121 != NULL ) {
if ( ! strcmp ( V_121 , L_34 ) ) {
V_100 . V_133 = false ;
V_100 . V_103 = V_134 ;
} else {
V_100 . V_133 = true ;
if ( F_51 ( V_121 , & V_100 ) ) {
F_52 ( L_35
L_36 ,
T_1 -> V_42 ) ;
return;
}
}
}
if ( V_116 > 0 ) {
V_116 = F_53 ( V_116 , sizeof( T_3 ) ) ;
V_100 . V_116 = V_116 ;
}
if ( V_99 . V_133 )
F_48 ( T_1 , & V_99 ) ;
if ( V_100 . V_133 )
F_44 ( T_1 , V_98 , & V_100 ) ;
}
}
void F_54 ( struct V_1 * T_1 , struct V_97 * V_98 )
{
struct V_1 * V_34 = T_1 -> V_34 ;
struct V_32 * V_22 = & T_1 -> V_22 ;
int V_135 = T_1 -> V_33 ;
bool V_136 = V_98 -> V_137 . V_138 && ! V_98 -> V_137 . V_139 ;
V_22 -> V_140 = V_141 . V_140 ? 0 : 1 ;
V_22 -> V_142 = ! V_98 -> V_143 ;
F_14 ( T_1 , V_144 ) ;
F_14 ( T_1 , V_145 ) ;
if ( T_1 -> V_146 ) {
F_14 ( T_1 , V_147 ) ;
F_12 ( T_1 , false ) ;
if ( V_34 -> V_148 > 1 ) {
V_22 -> V_30 |= V_149 ;
V_22 -> V_142 = 0 ;
}
}
if ( ! V_22 -> V_50 || ( V_98 -> V_150 != V_151 ||
V_98 -> V_152 != V_153 ) ) {
if ( V_98 -> V_125 ) {
F_14 ( T_1 , V_154 ) ;
V_22 -> V_125 = 1 ;
V_22 -> V_127 = V_98 -> V_125 ;
} else {
V_22 -> V_50 = V_98 -> V_155 ;
}
}
if ( ( V_34 != T_1 ) && V_34 -> V_146 ) {
V_22 -> V_127 = 0 ;
V_22 -> V_50 = 0 ;
}
if ( V_98 -> V_156 )
V_22 -> V_127 = 0 ;
if ( V_98 -> V_157 )
V_22 -> V_157 = 1 ;
if ( V_98 -> V_158 ) {
F_14 ( T_1 , V_159 ) ;
V_22 -> V_160 = V_135 ;
}
if ( F_45 ( T_1 ) )
T_1 -> V_22 . V_117 = 1 ;
if ( V_99 . V_133 && ! T_1 -> V_161 )
F_44 ( T_1 , V_98 , & V_99 ) ;
if ( V_98 -> V_162 ) {
V_22 -> V_163 = V_98 -> V_162 ;
F_14 ( T_1 , V_164 ) ;
}
if ( F_55 ( & V_98 -> V_137 ) )
F_14 ( T_1 , V_165 ) ;
if ( V_98 -> V_124 )
F_14 ( T_1 , V_154 ) ;
if ( V_98 -> V_166 &&
( ! V_141 . V_140 &&
( ! V_98 -> V_143 || F_55 ( & V_98 -> V_137 ) || V_136 ||
V_98 -> V_167 ) ) )
F_14 ( T_1 , TIME ) ;
if ( V_98 -> V_168 && ! T_1 -> V_161 ) {
F_14 ( T_1 , TIME ) ;
F_14 ( T_1 , V_169 ) ;
F_14 ( T_1 , V_165 ) ;
}
if ( V_98 -> V_158 )
F_14 ( T_1 , V_170 ) ;
if ( V_98 -> V_171 ) {
V_22 -> V_172 = 0 ;
V_22 -> V_173 = 1 ;
}
if ( V_98 -> V_105 && ! T_1 -> V_161 ) {
F_14 ( T_1 , V_106 ) ;
V_22 -> V_107 = V_98 -> V_105 ;
}
if ( V_98 -> V_174 )
F_14 ( T_1 , V_175 ) ;
V_22 -> V_176 = V_135 ;
V_22 -> V_177 = V_135 ;
V_22 -> V_178 = V_135 && ! V_141 . V_178 ;
V_22 -> V_179 = V_135 ;
if ( V_98 -> V_180 )
V_22 -> V_181 = V_135 ;
if ( V_98 -> V_182 )
F_14 ( T_1 , V_183 ) ;
if ( V_98 -> V_184 ) {
T_1 -> V_22 . V_30 |=
V_185 |
V_186 ;
}
if ( F_56 ( T_1 ) )
V_22 -> V_187 = 1 ;
if ( F_57 ( & V_98 -> V_137 ) && F_56 ( T_1 ) &&
! V_98 -> V_188 )
V_22 -> V_189 = 1 ;
if ( T_1 -> V_190 ) {
V_22 -> V_187 = 0 ;
V_22 -> V_189 = 0 ;
}
V_191 = V_98 -> V_191 ;
if ( V_98 -> V_192 ) {
V_22 -> V_192 = 1 ;
V_22 -> V_191 = V_98 -> V_191 ;
}
F_49 ( T_1 , V_98 ) ;
}
static int F_58 ( struct V_1 * T_1 , int V_193 , int V_194 )
{
int V_195 , V_196 ;
if ( T_1 -> V_197 )
V_194 = 1 ;
T_1 -> V_198 = F_59 ( V_193 , V_194 , sizeof( int ) ) ;
if ( T_1 -> V_198 ) {
for ( V_195 = 0 ; V_195 < V_193 ; V_195 ++ ) {
for ( V_196 = 0 ; V_196 < V_194 ; V_196 ++ ) {
F_60 ( T_1 , V_195 , V_196 ) = - 1 ;
}
}
}
return T_1 -> V_198 != NULL ? 0 : - V_199 ;
}
static int F_61 ( struct V_1 * T_1 , int V_193 , int V_194 ,
int V_200 , void * V_201 )
{
int V_195 , V_196 ;
if ( T_1 -> V_197 )
V_194 = 1 ;
for ( V_195 = 0 ; V_195 < V_193 ; V_195 ++ ) {
for ( V_196 = 0 ; V_196 < V_194 ; V_196 ++ ) {
int V_198 = F_60 ( T_1 , V_195 , V_196 ) ,
V_83 = F_62 ( V_198 , V_200 , V_201 ) ;
if ( V_83 )
return V_83 ;
}
}
return 0 ;
}
int F_63 ( struct V_1 * T_1 , int V_193 , int V_194 ,
const char * V_202 )
{
return F_61 ( T_1 , V_193 , V_194 ,
V_203 ,
( void * ) V_202 ) ;
}
int F_64 ( struct V_1 * T_1 , const char * V_202 )
{
char * V_204 = F_40 ( V_202 ) ;
if ( V_204 != NULL ) {
free ( T_1 -> V_202 ) ;
T_1 -> V_202 = V_204 ;
return 0 ;
}
return - 1 ;
}
int F_65 ( struct V_1 * T_1 ,
const char * V_77 , const char * V_202 )
{
char * V_204 ;
if ( T_1 -> V_202 == NULL )
return F_64 ( T_1 , V_202 ) ;
if ( F_20 ( & V_204 , L_37 , T_1 -> V_202 , V_77 , V_202 ) > 0 ) {
free ( T_1 -> V_202 ) ;
T_1 -> V_202 = V_204 ;
return 0 ;
}
return - 1 ;
}
int F_66 ( struct V_1 * T_1 , int V_193 , int V_194 )
{
return F_61 ( T_1 , V_193 , V_194 ,
V_205 ,
0 ) ;
}
int F_67 ( struct V_1 * T_1 , int V_193 , int V_194 )
{
if ( V_193 == 0 || V_194 == 0 )
return 0 ;
if ( T_1 -> V_197 )
V_194 = 1 ;
T_1 -> V_206 = F_59 ( V_193 , V_194 , sizeof( struct V_207 ) ) ;
if ( T_1 -> V_206 == NULL )
return - V_199 ;
T_1 -> V_49 = F_18 ( V_193 * V_194 * sizeof( T_3 ) ) ;
if ( T_1 -> V_49 == NULL ) {
F_68 ( T_1 -> V_206 ) ;
T_1 -> V_206 = NULL ;
return - V_199 ;
}
return 0 ;
}
static void F_69 ( struct V_1 * T_1 )
{
F_68 ( T_1 -> V_198 ) ;
T_1 -> V_198 = NULL ;
}
static void F_70 ( struct V_1 * T_1 )
{
F_68 ( T_1 -> V_206 ) ;
T_1 -> V_206 = NULL ;
F_23 ( & T_1 -> V_49 ) ;
}
static void F_71 ( struct V_1 * T_1 )
{
struct V_118 * V_119 , * V_208 ;
F_72 (term, h, &evsel->config_terms, list) {
F_73 ( & V_119 -> V_209 ) ;
free ( V_119 ) ;
}
}
void F_74 ( struct V_1 * T_1 , int V_193 , int V_194 )
{
int V_195 , V_196 ;
if ( T_1 -> V_197 )
V_194 = 1 ;
for ( V_195 = 0 ; V_195 < V_193 ; V_195 ++ )
for ( V_196 = 0 ; V_196 < V_194 ; ++ V_196 ) {
F_75 ( F_60 ( T_1 , V_195 , V_196 ) ) ;
F_60 ( T_1 , V_195 , V_196 ) = - 1 ;
}
}
void F_76 ( struct V_1 * T_1 )
{
assert ( F_77 ( & T_1 -> V_38 ) ) ;
assert ( T_1 -> V_37 == NULL ) ;
F_69 ( T_1 ) ;
F_70 ( T_1 ) ;
F_71 ( T_1 ) ;
F_78 ( T_1 -> V_210 ) ;
F_79 ( T_1 -> V_211 ) ;
F_79 ( T_1 -> V_212 ) ;
F_80 ( T_1 -> V_213 ) ;
F_23 ( & T_1 -> V_94 ) ;
F_23 ( & T_1 -> V_42 ) ;
V_5 . F_5 ( T_1 ) ;
}
void F_81 ( struct V_1 * T_1 )
{
F_76 ( T_1 ) ;
free ( T_1 ) ;
}
void F_82 ( struct V_1 * T_1 , int V_195 , int V_196 ,
struct V_214 * V_215 )
{
struct V_214 V_216 ;
if ( ! T_1 -> V_217 )
return;
if ( V_195 == - 1 ) {
V_216 = T_1 -> V_217 -> V_218 ;
T_1 -> V_217 -> V_218 = * V_215 ;
} else {
V_216 = * F_83 ( T_1 -> V_217 , V_195 , V_196 ) ;
* F_83 ( T_1 -> V_217 , V_195 , V_196 ) = * V_215 ;
}
V_215 -> V_123 = V_215 -> V_123 - V_216 . V_123 ;
V_215 -> V_219 = V_215 -> V_219 - V_216 . V_219 ;
V_215 -> V_220 = V_215 -> V_220 - V_216 . V_220 ;
}
void F_84 ( struct V_214 * V_215 ,
bool V_36 , T_8 * V_221 )
{
T_8 V_222 = 0 ;
if ( V_36 ) {
if ( V_215 -> V_220 == 0 ) {
V_222 = - 1 ;
V_215 -> V_123 = 0 ;
} else if ( V_215 -> V_220 < V_215 -> V_219 ) {
V_222 = 1 ;
V_215 -> V_123 = ( T_3 ) ( ( double ) V_215 -> V_123 * V_215 -> V_219 / V_215 -> V_220 + 0.5 ) ;
}
} else
V_215 -> V_219 = V_215 -> V_220 = 0 ;
if ( V_221 )
* V_221 = V_222 ;
}
int F_85 ( struct V_1 * T_1 , int V_195 , int V_196 ,
struct V_214 * V_215 )
{
memset ( V_215 , 0 , sizeof( * V_215 ) ) ;
if ( F_60 ( T_1 , V_195 , V_196 ) < 0 )
return - V_7 ;
if ( F_86 ( F_60 ( T_1 , V_195 , V_196 ) , V_215 , sizeof( * V_215 ) ) < 0 )
return - V_223 ;
return 0 ;
}
int F_87 ( struct V_1 * T_1 ,
int V_195 , int V_196 , bool V_36 )
{
struct V_214 V_215 ;
T_2 V_224 = V_36 ? 3 : 1 ;
if ( F_60 ( T_1 , V_195 , V_196 ) < 0 )
return - V_7 ;
if ( T_1 -> V_225 == NULL && F_88 ( T_1 , V_195 + 1 , V_196 + 1 ) < 0 )
return - V_199 ;
if ( F_86 ( F_60 ( T_1 , V_195 , V_196 ) , & V_215 , V_224 * sizeof( T_3 ) ) < 0 )
return - V_223 ;
F_82 ( T_1 , V_195 , V_196 , & V_215 ) ;
F_84 ( & V_215 , V_36 , NULL ) ;
* F_83 ( T_1 -> V_225 , V_195 , V_196 ) = V_215 ;
return 0 ;
}
static int F_89 ( struct V_1 * T_1 , int V_195 , int V_196 )
{
struct V_1 * V_34 = T_1 -> V_34 ;
int V_198 ;
if ( F_56 ( T_1 ) )
return - 1 ;
F_90 ( ! V_34 -> V_198 ) ;
V_198 = F_60 ( V_34 , V_195 , V_196 ) ;
F_90 ( V_198 == - 1 ) ;
return V_198 ;
}
static void F_91 ( char * V_95 , T_2 V_6 , T_3 V_226 , struct V_227 * V_228 )
{
bool V_229 = true ;
int V_11 = 0 ;
do {
if ( V_226 & V_228 [ V_11 ] . V_25 ) {
V_95 += F_27 ( V_95 , V_6 , L_38 , V_229 ? L_1 : L_39 , V_228 [ V_11 ] . V_42 ) ;
V_229 = false ;
}
} while ( V_228 [ ++ V_11 ] . V_42 != NULL );
}
static void F_92 ( char * V_95 , T_2 V_6 , T_3 V_226 )
{
#define F_93 ( T_9 ) { PERF_SAMPLE_##n, #n }
struct V_227 V_228 [] = {
F_93 ( V_144 ) , F_93 ( V_145 ) , F_93 ( TIME ) , F_93 ( V_159 ) ,
F_93 ( V_147 ) , F_93 ( V_102 ) , F_93 ( V_28 ) , F_93 ( V_165 ) ,
F_93 ( V_154 ) , F_93 ( V_230 ) , F_93 ( V_169 ) ,
F_93 ( V_106 ) , F_93 ( V_111 ) , F_93 ( V_112 ) ,
F_93 ( V_29 ) , F_93 ( V_164 ) ,
{ . V_42 = NULL , }
} ;
#undef F_93
F_91 ( V_95 , V_6 , V_226 , V_228 ) ;
}
static void F_94 ( char * V_95 , T_2 V_6 , T_3 V_226 )
{
#define F_93 ( T_9 ) { PERF_FORMAT_##n, #n }
struct V_227 V_228 [] = {
F_93 ( V_231 ) , F_93 ( V_232 ) ,
F_93 ( V_28 ) , F_93 ( V_233 ) ,
{ . V_42 = NULL , }
} ;
#undef F_93
F_91 ( V_95 , V_6 , V_226 , V_228 ) ;
}
int F_95 ( T_10 * V_234 , struct V_32 * V_22 ,
T_11 V_235 , void * V_236 )
{
char V_95 [ V_237 ] ;
int V_88 = 0 ;
F_96 ( type , V_238 ) ;
F_96 ( V_6 , V_238 ) ;
F_96 ( V_48 , V_239 ) ;
F_97 ( L_40 , V_50 , V_238 ) ;
F_96 ( V_8 , V_240 ) ;
F_96 ( V_30 , V_241 ) ;
F_96 ( V_187 , V_238 ) ;
F_96 ( V_142 , V_238 ) ;
F_96 ( V_242 , V_238 ) ;
F_96 ( V_243 , V_238 ) ;
F_96 ( V_58 , V_238 ) ;
F_96 ( V_57 , V_238 ) ;
F_96 ( V_59 , V_238 ) ;
F_96 ( V_244 , V_238 ) ;
F_96 ( V_177 , V_238 ) ;
F_96 ( V_179 , V_238 ) ;
F_96 ( V_125 , V_238 ) ;
F_96 ( V_157 , V_238 ) ;
F_96 ( V_189 , V_238 ) ;
F_96 ( V_176 , V_238 ) ;
F_96 ( V_172 , V_238 ) ;
F_96 ( V_63 , V_238 ) ;
F_96 ( V_160 , V_238 ) ;
F_96 ( V_140 , V_238 ) ;
F_96 ( V_64 , V_238 ) ;
F_96 ( V_65 , V_238 ) ;
F_96 ( V_245 , V_238 ) ;
F_96 ( V_117 , V_238 ) ;
F_96 ( V_178 , V_238 ) ;
F_96 ( V_246 , V_238 ) ;
F_96 ( V_192 , V_238 ) ;
F_96 ( V_181 , V_238 ) ;
F_97 ( L_41 , V_173 , V_238 ) ;
F_96 ( V_76 , V_238 ) ;
F_97 ( L_42 , V_75 , V_239 ) ;
F_97 ( L_43 , V_247 , V_239 ) ;
F_96 ( V_113 , V_239 ) ;
F_96 ( V_115 , V_238 ) ;
F_96 ( V_191 , V_248 ) ;
F_96 ( V_163 , V_239 ) ;
F_96 ( V_249 , V_238 ) ;
return V_88 ;
}
static int F_98 ( struct V_1 * T_1 , struct V_250 * V_211 ,
struct V_251 * V_213 )
{
int V_195 , V_196 , V_194 ;
unsigned long V_252 = V_253 ;
int V_254 = - 1 , V_83 ;
enum { V_255 , V_256 , V_257 } V_258 = V_255 ;
if ( T_1 -> V_197 )
V_194 = 1 ;
else
V_194 = V_213 -> V_259 ;
if ( T_1 -> V_198 == NULL &&
F_58 ( T_1 , V_211 -> V_259 , V_194 ) < 0 )
return - V_199 ;
if ( T_1 -> V_210 ) {
V_252 |= V_260 ;
V_254 = T_1 -> V_210 -> V_198 ;
}
V_261:
if ( V_141 . V_262 )
T_1 -> V_22 . V_191 = V_263 ;
if ( V_141 . V_191 ) {
T_1 -> V_22 . V_192 = 0 ;
T_1 -> V_22 . V_191 = 0 ;
}
if ( V_141 . V_264 )
V_252 &= ~ ( unsigned long ) V_253 ;
if ( V_141 . V_178 )
T_1 -> V_22 . V_178 = 0 ;
if ( V_141 . V_65 )
T_1 -> V_22 . V_65 = T_1 -> V_22 . V_64 = 0 ;
V_265:
if ( V_141 . V_140 )
T_1 -> V_22 . V_140 = 0 ;
if ( V_266 >= 2 ) {
fprintf ( V_267 , L_44 , V_268 ) ;
fprintf ( V_267 , L_45 ) ;
F_95 ( V_267 , & T_1 -> V_22 , V_269 , NULL ) ;
fprintf ( V_267 , L_44 , V_268 ) ;
}
for ( V_195 = 0 ; V_195 < V_211 -> V_259 ; V_195 ++ ) {
for ( V_196 = 0 ; V_196 < V_194 ; V_196 ++ ) {
int V_270 ;
if ( ! T_1 -> V_210 && ! T_1 -> V_197 )
V_254 = F_99 ( V_213 , V_196 ) ;
V_270 = F_89 ( T_1 , V_195 , V_196 ) ;
V_271:
F_100 ( L_46 ,
V_254 , V_211 -> V_272 [ V_195 ] , V_270 , V_252 ) ;
F_60 ( T_1 , V_195 , V_196 ) = F_101 ( & T_1 -> V_22 ,
V_254 ,
V_211 -> V_272 [ V_195 ] ,
V_270 , V_252 ) ;
if ( F_60 ( T_1 , V_195 , V_196 ) < 0 ) {
V_83 = - V_223 ;
F_100 ( L_47 ,
V_83 ) ;
goto V_273;
}
V_258 = V_255 ;
if ( V_141 . V_191 ||
V_141 . V_262 ) {
V_83 = - V_7 ;
goto V_274;
}
}
}
return 0 ;
V_273:
if ( V_83 == - V_275 && V_258 < V_257 ) {
struct V_276 V_277 ;
int V_278 = V_223 ;
if ( F_102 ( V_279 , & V_277 ) == 0 ) {
if ( V_258 == V_255 )
V_277 . V_280 = V_277 . V_281 ;
else {
V_277 . V_280 = V_277 . V_281 + 1000 ;
V_277 . V_281 = V_277 . V_280 ;
}
if ( F_103 ( V_279 , & V_277 ) == 0 ) {
V_258 ++ ;
V_223 = V_278 ;
goto V_271;
}
}
V_223 = V_278 ;
}
if ( V_83 != - V_7 || V_195 > 0 || V_196 > 0 )
goto V_274;
if ( ! V_141 . V_262 && T_1 -> V_22 . V_192 ) {
V_141 . V_262 = true ;
goto V_261;
} else if ( ! V_141 . V_191 && T_1 -> V_22 . V_192 ) {
V_141 . V_191 = true ;
goto V_261;
} else if ( ! V_141 . V_264 && ( V_252 & V_253 ) ) {
V_141 . V_264 = true ;
goto V_261;
} else if ( ! V_141 . V_178 && T_1 -> V_22 . V_178 ) {
V_141 . V_178 = true ;
goto V_261;
} else if ( ! V_141 . V_65 &&
( T_1 -> V_22 . V_65 || T_1 -> V_22 . V_64 ) ) {
V_141 . V_65 = true ;
goto V_261;
} else if ( ! V_141 . V_140 ) {
V_141 . V_140 = true ;
goto V_265;
}
V_274:
do {
while ( -- V_196 >= 0 ) {
F_75 ( F_60 ( T_1 , V_195 , V_196 ) ) ;
F_60 ( T_1 , V_195 , V_196 ) = - 1 ;
}
V_196 = V_194 ;
} while ( -- V_195 >= 0 );
return V_83 ;
}
void F_104 ( struct V_1 * T_1 , int V_193 , int V_194 )
{
if ( T_1 -> V_198 == NULL )
return;
F_74 ( T_1 , V_193 , V_194 ) ;
F_69 ( T_1 ) ;
}
int F_105 ( struct V_1 * T_1 , struct V_250 * V_211 ,
struct V_251 * V_213 )
{
if ( V_211 == NULL ) {
V_211 = & V_282 . V_272 ;
}
if ( V_213 == NULL )
V_213 = & V_283 . V_272 ;
return F_98 ( T_1 , V_211 , V_213 ) ;
}
int F_106 ( struct V_1 * T_1 ,
struct V_250 * V_211 )
{
return F_98 ( T_1 , V_211 , & V_283 . V_272 ) ;
}
int F_107 ( struct V_1 * T_1 ,
struct V_251 * V_213 )
{
return F_98 ( T_1 , & V_282 . V_272 , V_213 ) ;
}
static int F_108 ( const struct V_1 * T_1 ,
const union V_284 * V_285 ,
struct V_286 * V_287 )
{
T_3 type = T_1 -> V_22 . V_8 ;
const T_3 * V_288 = V_285 -> V_287 . V_288 ;
bool V_289 = T_1 -> V_290 ;
union V_291 V_292 ;
V_288 += ( ( V_285 -> V_293 . V_6 -
sizeof( V_285 -> V_293 ) ) / sizeof( T_3 ) ) - 1 ;
if ( type & V_13 ) {
V_287 -> V_49 = * V_288 ;
V_288 -- ;
}
if ( type & V_19 ) {
V_292 . V_294 = * V_288 ;
if ( V_289 ) {
V_292 . V_294 = F_109 ( V_292 . V_294 ) ;
V_292 . V_295 [ 0 ] = F_110 ( V_292 . V_295 [ 0 ] ) ;
}
V_287 -> V_195 = V_292 . V_295 [ 0 ] ;
V_288 -- ;
}
if ( type & V_20 ) {
V_287 -> V_296 = * V_288 ;
V_288 -- ;
}
if ( type & V_14 ) {
V_287 -> V_49 = * V_288 ;
V_288 -- ;
}
if ( type & V_17 ) {
V_287 -> time = * V_288 ;
V_288 -- ;
}
if ( type & V_16 ) {
V_292 . V_294 = * V_288 ;
if ( V_289 ) {
V_292 . V_294 = F_109 ( V_292 . V_294 ) ;
V_292 . V_295 [ 0 ] = F_110 ( V_292 . V_295 [ 0 ] ) ;
V_292 . V_295 [ 1 ] = F_110 ( V_292 . V_295 [ 1 ] ) ;
}
V_287 -> V_254 = V_292 . V_295 [ 0 ] ;
V_287 -> V_297 = V_292 . V_295 [ 1 ] ;
V_288 -- ;
}
return 0 ;
}
static inline bool F_111 ( const void * V_298 , T_12 V_299 , const void * V_300 ,
T_3 V_6 )
{
return V_6 > V_299 || V_300 + V_6 > V_298 ;
}
int F_112 ( struct V_1 * T_1 , union V_284 * V_285 ,
struct V_286 * V_301 )
{
T_3 type = T_1 -> V_22 . V_8 ;
bool V_289 = T_1 -> V_290 ;
const T_3 * V_288 ;
T_12 V_299 = V_285 -> V_293 . V_6 ;
const void * V_298 = ( void * ) V_285 + V_299 ;
T_3 V_302 ;
union V_291 V_292 ;
memset ( V_301 , 0 , sizeof( * V_301 ) ) ;
V_301 -> V_195 = V_301 -> V_254 = V_301 -> V_297 = - 1 ;
V_301 -> V_296 = V_301 -> V_49 = V_301 -> time = - 1ULL ;
V_301 -> V_124 = T_1 -> V_22 . V_50 ;
V_301 -> V_303 = 0 ;
if ( V_285 -> V_293 . type != V_304 ) {
if ( ! T_1 -> V_22 . V_140 )
return 0 ;
return F_108 ( T_1 , V_285 , V_301 ) ;
}
V_288 = V_285 -> V_287 . V_288 ;
if ( T_1 -> V_26 + sizeof( V_285 -> V_293 ) > V_285 -> V_293 . V_6 )
return - V_305 ;
V_301 -> V_49 = - 1ULL ;
if ( type & V_13 ) {
V_301 -> V_49 = * V_288 ;
V_288 ++ ;
}
if ( type & V_15 ) {
V_301 -> V_306 = * V_288 ;
V_288 ++ ;
}
if ( type & V_16 ) {
V_292 . V_294 = * V_288 ;
if ( V_289 ) {
V_292 . V_294 = F_109 ( V_292 . V_294 ) ;
V_292 . V_295 [ 0 ] = F_110 ( V_292 . V_295 [ 0 ] ) ;
V_292 . V_295 [ 1 ] = F_110 ( V_292 . V_295 [ 1 ] ) ;
}
V_301 -> V_254 = V_292 . V_295 [ 0 ] ;
V_301 -> V_297 = V_292 . V_295 [ 1 ] ;
V_288 ++ ;
}
if ( type & V_17 ) {
V_301 -> time = * V_288 ;
V_288 ++ ;
}
V_301 -> V_70 = 0 ;
if ( type & V_18 ) {
V_301 -> V_70 = * V_288 ;
V_288 ++ ;
}
if ( type & V_14 ) {
V_301 -> V_49 = * V_288 ;
V_288 ++ ;
}
if ( type & V_20 ) {
V_301 -> V_296 = * V_288 ;
V_288 ++ ;
}
if ( type & V_19 ) {
V_292 . V_294 = * V_288 ;
if ( V_289 ) {
V_292 . V_294 = F_109 ( V_292 . V_294 ) ;
V_292 . V_295 [ 0 ] = F_110 ( V_292 . V_295 [ 0 ] ) ;
}
V_301 -> V_195 = V_292 . V_295 [ 0 ] ;
V_288 ++ ;
}
if ( type & V_45 ) {
V_301 -> V_124 = * V_288 ;
V_288 ++ ;
}
if ( type & V_307 ) {
T_3 V_30 = T_1 -> V_22 . V_30 ;
F_113 ( V_288 ) ;
if ( V_30 & V_149 )
V_301 -> V_308 . V_309 . V_259 = * V_288 ;
else
V_301 -> V_308 . V_310 . V_226 = * V_288 ;
V_288 ++ ;
if ( V_30 & V_185 ) {
F_113 ( V_288 ) ;
V_301 -> V_308 . V_311 = * V_288 ;
V_288 ++ ;
}
if ( V_30 & V_186 ) {
F_113 ( V_288 ) ;
V_301 -> V_308 . V_312 = * V_288 ;
V_288 ++ ;
}
if ( V_30 & V_149 ) {
const T_3 V_313 = V_314 /
sizeof( struct V_315 ) ;
if ( V_301 -> V_308 . V_309 . V_259 > V_313 )
return - V_305 ;
V_302 = V_301 -> V_308 . V_309 . V_259 *
sizeof( struct V_315 ) ;
F_114 ( V_288 , V_302 , V_299 ) ;
V_301 -> V_308 . V_309 . V_316 =
(struct V_315 * ) V_288 ;
V_288 = ( void * ) V_288 + V_302 ;
} else {
F_113 ( V_288 ) ;
V_301 -> V_308 . V_310 . V_49 = * V_288 ;
V_288 ++ ;
}
}
if ( type & V_317 ) {
const T_3 V_318 = V_314 / sizeof( T_3 ) ;
F_113 ( V_288 ) ;
V_301 -> V_319 = (struct V_320 * ) V_288 ++ ;
if ( V_301 -> V_319 -> V_259 > V_318 )
return - V_305 ;
V_302 = V_301 -> V_319 -> V_259 * sizeof( T_3 ) ;
F_114 ( V_288 , V_302 , V_299 ) ;
V_288 = ( void * ) V_288 + V_302 ;
}
if ( type & V_44 ) {
F_113 ( V_288 ) ;
V_292 . V_294 = * V_288 ;
if ( F_115 ( V_289 ,
L_48 ) ) {
V_292 . V_294 = F_109 ( V_292 . V_294 ) ;
V_292 . V_295 [ 0 ] = F_110 ( V_292 . V_295 [ 0 ] ) ;
V_292 . V_295 [ 1 ] = F_110 ( V_292 . V_295 [ 1 ] ) ;
}
V_301 -> V_321 = V_292 . V_295 [ 0 ] ;
V_288 = ( void * ) V_288 + sizeof( T_7 ) ;
F_114 ( V_288 , V_301 -> V_321 , V_299 ) ;
V_301 -> V_322 = ( void * ) V_288 ;
V_288 = ( void * ) V_288 + V_301 -> V_321 ;
}
if ( type & V_323 ) {
const T_3 V_324 = V_314 /
sizeof( struct V_325 ) ;
F_113 ( V_288 ) ;
V_301 -> V_105 = (struct V_105 * ) V_288 ++ ;
if ( V_301 -> V_105 -> V_259 > V_324 )
return - V_305 ;
V_302 = V_301 -> V_105 -> V_259 * sizeof( struct V_325 ) ;
F_114 ( V_288 , V_302 , V_299 ) ;
V_288 = ( void * ) V_288 + V_302 ;
}
if ( type & V_326 ) {
F_113 ( V_288 ) ;
V_301 -> V_327 . V_328 = * V_288 ;
V_288 ++ ;
if ( V_301 -> V_327 . V_328 ) {
T_3 V_9 = T_1 -> V_22 . V_113 ;
V_302 = F_116 ( V_9 ) * sizeof( T_3 ) ;
F_114 ( V_288 , V_302 , V_299 ) ;
V_301 -> V_327 . V_9 = V_9 ;
V_301 -> V_327 . V_329 = ( T_3 * ) V_288 ;
V_288 = ( void * ) V_288 + V_302 ;
}
}
if ( type & V_330 ) {
F_113 ( V_288 ) ;
V_302 = * V_288 ++ ;
V_301 -> V_331 . V_300 = ( ( char * ) ( V_288 - 1 )
- ( char * ) V_285 ) ;
if ( ! V_302 ) {
V_301 -> V_331 . V_6 = 0 ;
} else {
F_114 ( V_288 , V_302 , V_299 ) ;
V_301 -> V_331 . V_301 = ( char * ) V_288 ;
V_288 = ( void * ) V_288 + V_302 ;
F_113 ( V_288 ) ;
V_301 -> V_331 . V_6 = * V_288 ++ ;
if ( F_115 ( V_301 -> V_331 . V_6 > V_302 ,
L_49 ) )
return - V_305 ;
}
}
V_301 -> V_303 = 0 ;
if ( type & V_332 ) {
F_113 ( V_288 ) ;
V_301 -> V_303 = * V_288 ;
V_288 ++ ;
}
V_301 -> V_333 = V_334 ;
if ( type & V_335 ) {
F_113 ( V_288 ) ;
V_301 -> V_333 = * V_288 ;
V_288 ++ ;
}
V_301 -> V_336 = 0 ;
if ( type & V_337 ) {
F_113 ( V_288 ) ;
V_301 -> V_336 = * V_288 ;
V_288 ++ ;
}
V_301 -> V_338 . V_328 = V_339 ;
if ( type & V_340 ) {
F_113 ( V_288 ) ;
V_301 -> V_338 . V_328 = * V_288 ;
V_288 ++ ;
if ( V_301 -> V_338 . V_328 != V_339 ) {
T_3 V_9 = T_1 -> V_22 . V_163 ;
V_302 = F_116 ( V_9 ) * sizeof( T_3 ) ;
F_114 ( V_288 , V_302 , V_299 ) ;
V_301 -> V_338 . V_9 = V_9 ;
V_301 -> V_338 . V_329 = ( T_3 * ) V_288 ;
V_288 = ( void * ) V_288 + V_302 ;
}
}
return 0 ;
}
T_2 F_117 ( const struct V_286 * V_287 , T_3 type ,
T_3 V_30 )
{
T_2 V_302 , V_79 = sizeof( struct V_341 ) ;
if ( type & V_13 )
V_79 += sizeof( T_3 ) ;
if ( type & V_15 )
V_79 += sizeof( T_3 ) ;
if ( type & V_16 )
V_79 += sizeof( T_3 ) ;
if ( type & V_17 )
V_79 += sizeof( T_3 ) ;
if ( type & V_18 )
V_79 += sizeof( T_3 ) ;
if ( type & V_14 )
V_79 += sizeof( T_3 ) ;
if ( type & V_20 )
V_79 += sizeof( T_3 ) ;
if ( type & V_19 )
V_79 += sizeof( T_3 ) ;
if ( type & V_45 )
V_79 += sizeof( T_3 ) ;
if ( type & V_307 ) {
V_79 += sizeof( T_3 ) ;
if ( V_30 & V_185 )
V_79 += sizeof( T_3 ) ;
if ( V_30 & V_186 )
V_79 += sizeof( T_3 ) ;
if ( V_30 & V_149 ) {
V_302 = V_287 -> V_308 . V_309 . V_259 *
sizeof( struct V_315 ) ;
V_79 += V_302 ;
} else {
V_79 += sizeof( T_3 ) ;
}
}
if ( type & V_317 ) {
V_302 = ( V_287 -> V_319 -> V_259 + 1 ) * sizeof( T_3 ) ;
V_79 += V_302 ;
}
if ( type & V_44 ) {
V_79 += sizeof( T_7 ) ;
V_79 += V_287 -> V_321 ;
}
if ( type & V_323 ) {
V_302 = V_287 -> V_105 -> V_259 * sizeof( struct V_325 ) ;
V_302 += sizeof( T_3 ) ;
V_79 += V_302 ;
}
if ( type & V_326 ) {
if ( V_287 -> V_327 . V_328 ) {
V_79 += sizeof( T_3 ) ;
V_302 = F_116 ( V_287 -> V_327 . V_9 ) * sizeof( T_3 ) ;
V_79 += V_302 ;
} else {
V_79 += sizeof( T_3 ) ;
}
}
if ( type & V_330 ) {
V_302 = V_287 -> V_331 . V_6 ;
V_79 += sizeof( T_3 ) ;
if ( V_302 ) {
V_79 += V_302 ;
V_79 += sizeof( T_3 ) ;
}
}
if ( type & V_332 )
V_79 += sizeof( T_3 ) ;
if ( type & V_335 )
V_79 += sizeof( T_3 ) ;
if ( type & V_337 )
V_79 += sizeof( T_3 ) ;
if ( type & V_340 ) {
if ( V_287 -> V_338 . V_328 ) {
V_79 += sizeof( T_3 ) ;
V_302 = F_116 ( V_287 -> V_338 . V_9 ) * sizeof( T_3 ) ;
V_79 += V_302 ;
} else {
V_79 += sizeof( T_3 ) ;
}
}
return V_79 ;
}
int F_118 ( union V_284 * V_285 , T_3 type ,
T_3 V_30 ,
const struct V_286 * V_287 ,
bool V_289 )
{
T_3 * V_288 ;
T_2 V_302 ;
union V_291 V_292 ;
V_288 = V_285 -> V_287 . V_288 ;
if ( type & V_13 ) {
* V_288 = V_287 -> V_49 ;
V_288 ++ ;
}
if ( type & V_15 ) {
* V_288 = V_287 -> V_306 ;
V_288 ++ ;
}
if ( type & V_16 ) {
V_292 . V_295 [ 0 ] = V_287 -> V_254 ;
V_292 . V_295 [ 1 ] = V_287 -> V_297 ;
if ( V_289 ) {
V_292 . V_295 [ 0 ] = F_110 ( V_292 . V_295 [ 0 ] ) ;
V_292 . V_295 [ 1 ] = F_110 ( V_292 . V_295 [ 1 ] ) ;
V_292 . V_294 = F_109 ( V_292 . V_294 ) ;
}
* V_288 = V_292 . V_294 ;
V_288 ++ ;
}
if ( type & V_17 ) {
* V_288 = V_287 -> time ;
V_288 ++ ;
}
if ( type & V_18 ) {
* V_288 = V_287 -> V_70 ;
V_288 ++ ;
}
if ( type & V_14 ) {
* V_288 = V_287 -> V_49 ;
V_288 ++ ;
}
if ( type & V_20 ) {
* V_288 = V_287 -> V_296 ;
V_288 ++ ;
}
if ( type & V_19 ) {
V_292 . V_295 [ 0 ] = V_287 -> V_195 ;
if ( V_289 ) {
V_292 . V_295 [ 0 ] = F_110 ( V_292 . V_295 [ 0 ] ) ;
V_292 . V_294 = F_109 ( V_292 . V_294 ) ;
}
* V_288 = V_292 . V_294 ;
V_288 ++ ;
}
if ( type & V_45 ) {
* V_288 = V_287 -> V_124 ;
V_288 ++ ;
}
if ( type & V_307 ) {
if ( V_30 & V_149 )
* V_288 = V_287 -> V_308 . V_309 . V_259 ;
else
* V_288 = V_287 -> V_308 . V_310 . V_226 ;
V_288 ++ ;
if ( V_30 & V_185 ) {
* V_288 = V_287 -> V_308 . V_311 ;
V_288 ++ ;
}
if ( V_30 & V_186 ) {
* V_288 = V_287 -> V_308 . V_312 ;
V_288 ++ ;
}
if ( V_30 & V_149 ) {
V_302 = V_287 -> V_308 . V_309 . V_259 *
sizeof( struct V_315 ) ;
memcpy ( V_288 , V_287 -> V_308 . V_309 . V_316 , V_302 ) ;
V_288 = ( void * ) V_288 + V_302 ;
} else {
* V_288 = V_287 -> V_308 . V_310 . V_49 ;
V_288 ++ ;
}
}
if ( type & V_317 ) {
V_302 = ( V_287 -> V_319 -> V_259 + 1 ) * sizeof( T_3 ) ;
memcpy ( V_288 , V_287 -> V_319 , V_302 ) ;
V_288 = ( void * ) V_288 + V_302 ;
}
if ( type & V_44 ) {
V_292 . V_295 [ 0 ] = V_287 -> V_321 ;
if ( F_115 ( V_289 ,
L_48 ) ) {
V_292 . V_295 [ 0 ] = F_110 ( V_292 . V_295 [ 0 ] ) ;
V_292 . V_295 [ 1 ] = F_110 ( V_292 . V_295 [ 1 ] ) ;
V_292 . V_294 = F_109 ( V_292 . V_294 ) ;
}
* V_288 = V_292 . V_294 ;
V_288 = ( void * ) V_288 + sizeof( T_7 ) ;
memcpy ( V_288 , V_287 -> V_322 , V_287 -> V_321 ) ;
V_288 = ( void * ) V_288 + V_287 -> V_321 ;
}
if ( type & V_323 ) {
V_302 = V_287 -> V_105 -> V_259 * sizeof( struct V_325 ) ;
V_302 += sizeof( T_3 ) ;
memcpy ( V_288 , V_287 -> V_105 , V_302 ) ;
V_288 = ( void * ) V_288 + V_302 ;
}
if ( type & V_326 ) {
if ( V_287 -> V_327 . V_328 ) {
* V_288 ++ = V_287 -> V_327 . V_328 ;
V_302 = F_116 ( V_287 -> V_327 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_288 , V_287 -> V_327 . V_329 , V_302 ) ;
V_288 = ( void * ) V_288 + V_302 ;
} else {
* V_288 ++ = 0 ;
}
}
if ( type & V_330 ) {
V_302 = V_287 -> V_331 . V_6 ;
* V_288 ++ = V_302 ;
if ( V_302 ) {
memcpy ( V_288 , V_287 -> V_331 . V_301 , V_302 ) ;
V_288 = ( void * ) V_288 + V_302 ;
* V_288 ++ = V_302 ;
}
}
if ( type & V_332 ) {
* V_288 = V_287 -> V_303 ;
V_288 ++ ;
}
if ( type & V_335 ) {
* V_288 = V_287 -> V_333 ;
V_288 ++ ;
}
if ( type & V_337 ) {
* V_288 = V_287 -> V_336 ;
V_288 ++ ;
}
if ( type & V_340 ) {
if ( V_287 -> V_338 . V_328 ) {
* V_288 ++ = V_287 -> V_338 . V_328 ;
V_302 = F_116 ( V_287 -> V_338 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_288 , V_287 -> V_338 . V_329 , V_302 ) ;
V_288 = ( void * ) V_288 + V_302 ;
} else {
* V_288 ++ = 0 ;
}
}
return 0 ;
}
struct V_342 * F_119 ( struct V_1 * T_1 , const char * V_42 )
{
return F_120 ( T_1 -> V_47 , V_42 ) ;
}
void * F_121 ( struct V_1 * T_1 , struct V_286 * V_287 ,
const char * V_42 )
{
struct V_342 * V_343 = F_119 ( T_1 , V_42 ) ;
int V_300 ;
if ( ! V_343 )
return NULL ;
V_300 = V_343 -> V_300 ;
if ( V_343 -> V_252 & V_344 ) {
V_300 = * ( int * ) ( V_287 -> V_322 + V_343 -> V_300 ) ;
V_300 &= 0xffff ;
}
return V_287 -> V_322 + V_300 ;
}
T_3 F_122 ( struct V_1 * T_1 , struct V_286 * V_287 ,
const char * V_42 )
{
struct V_342 * V_343 = F_119 ( T_1 , V_42 ) ;
void * V_345 ;
T_3 V_226 ;
if ( ! V_343 )
return 0 ;
V_345 = V_287 -> V_322 + V_343 -> V_300 ;
switch ( V_343 -> V_6 ) {
case 1 :
return * ( T_6 * ) V_345 ;
case 2 :
V_226 = * ( T_12 * ) V_345 ;
break;
case 4 :
V_226 = * ( T_7 * ) V_345 ;
break;
case 8 :
memcpy ( & V_226 , V_345 , sizeof( T_3 ) ) ;
break;
default:
return 0 ;
}
if ( ! T_1 -> V_290 )
return V_226 ;
switch ( V_343 -> V_6 ) {
case 2 :
return F_123 ( V_226 ) ;
case 4 :
return F_110 ( V_226 ) ;
case 8 :
return F_109 ( V_226 ) ;
default:
return 0 ;
}
return 0 ;
}
static int F_124 ( T_10 * V_234 , bool * V_346 , const char * V_347 , ... )
{
T_13 args ;
int V_88 = 0 ;
if ( ! * V_346 ) {
V_88 += fprintf ( V_234 , L_50 ) ;
} else {
V_88 += fprintf ( V_234 , L_9 ) ;
* V_346 = false ;
}
va_start ( args , V_347 ) ;
V_88 += vfprintf ( V_234 , V_347 , args ) ;
va_end ( args ) ;
return V_88 ;
}
static int F_125 ( T_10 * V_234 , const char * V_42 , const char * V_123 , void * V_236 )
{
return F_124 ( V_234 , ( bool * ) V_236 , L_51 , V_42 , V_123 ) ;
}
int F_126 ( struct V_1 * T_1 ,
struct V_348 * V_349 , T_10 * V_234 )
{
bool V_346 = true ;
int V_350 = 0 ;
if ( V_349 -> V_351 ) {
struct V_1 * V_96 ;
if ( ! F_56 ( T_1 ) )
return 0 ;
if ( T_1 -> V_148 > 1 )
V_350 += fprintf ( V_234 , L_52 , T_1 -> V_94 ? : L_1 ) ;
V_350 += fprintf ( V_234 , L_6 , F_39 ( T_1 ) ) ;
F_43 (pos, evsel)
V_350 += fprintf ( V_234 , L_53 , F_39 ( V_96 ) ) ;
if ( T_1 -> V_148 > 1 )
V_350 += fprintf ( V_234 , L_54 ) ;
goto V_352;
}
V_350 += fprintf ( V_234 , L_6 , F_39 ( T_1 ) ) ;
if ( V_349 -> V_266 ) {
V_350 += F_95 ( V_234 , & T_1 -> V_22 ,
F_125 , & V_346 ) ;
} else if ( V_349 -> V_125 ) {
const char * V_119 = L_55 ;
if ( ! T_1 -> V_22 . V_125 )
V_119 = L_56 ;
V_350 += F_124 ( V_234 , & V_346 , L_57 V_353 ,
V_119 , ( T_3 ) T_1 -> V_22 . V_127 ) ;
}
V_352:
fputc ( '\n' , V_234 ) ;
return ++ V_350 ;
}
bool F_127 ( struct V_1 * T_1 , int V_83 ,
char * V_354 , T_2 V_355 )
{
if ( ( V_83 == V_356 || V_83 == V_357 || V_83 == V_358 ) &&
T_1 -> V_22 . type == V_90 &&
T_1 -> V_22 . V_48 == V_359 ) {
F_27 ( V_354 , V_355 , L_6 ,
L_58 ) ;
T_1 -> V_22 . type = V_92 ;
T_1 -> V_22 . V_48 = V_360 ;
F_23 ( & T_1 -> V_42 ) ;
return true ;
}
return false ;
}
int F_128 ( struct V_1 * T_1 , struct V_137 * V_137 ,
int V_83 , char * V_354 , T_2 V_6 )
{
char V_361 [ V_362 ] ;
switch ( V_83 ) {
case V_363 :
case V_364 :
return F_27 ( V_354 , V_6 ,
L_59
L_60
L_61
L_62
L_63
L_64 ,
V_137 -> V_197 ? L_65 : L_1 ) ;
case V_356 :
return F_27 ( V_354 , V_6 , L_66 ,
F_39 ( T_1 ) ) ;
case V_275 :
return F_27 ( V_354 , V_6 , L_6 ,
L_67
L_68
L_69
L_70 ) ;
case V_358 :
if ( V_137 -> V_365 )
return F_27 ( V_354 , V_6 , L_6 ,
L_71 ) ;
break;
case V_366 :
if ( T_1 -> V_22 . V_63 )
return F_27 ( V_354 , V_6 , L_6 ,
L_72 ) ;
#if F_129 ( V_367 ) || F_129 ( V_368 )
if ( T_1 -> V_22 . type == V_90 )
return F_27 ( V_354 , V_6 , L_6 ,
L_73
L_74 ) ;
#endif
break;
case V_369 :
if ( F_130 ( L_75 ) )
return F_27 ( V_354 , V_6 ,
L_76
L_77 ) ;
break;
case V_7 :
if ( V_141 . V_191 )
return F_27 ( V_354 , V_6 , L_78 ) ;
if ( V_141 . V_262 )
return F_27 ( V_354 , V_6 , L_79 , V_191 ) ;
break;
default:
break;
}
return F_27 ( V_354 , V_6 ,
L_80
L_81
L_82 ,
V_83 , F_131 ( V_83 , V_361 , sizeof( V_361 ) ) ,
F_39 ( T_1 ) ) ;
}
