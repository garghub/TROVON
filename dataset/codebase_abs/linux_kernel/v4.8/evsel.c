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
bool F_15 ( struct V_1 * T_1 )
{
#define F_16 "ftrace:function"
return T_1 -> V_32 &&
! strncmp ( F_16 , T_1 -> V_32 , sizeof( F_16 ) ) ;
#undef F_16
}
void F_17 ( struct V_1 * T_1 ,
struct V_33 * V_22 , int V_12 )
{
T_1 -> V_12 = V_12 ;
T_1 -> V_34 = ! V_12 ;
T_1 -> V_22 = * V_22 ;
T_1 -> V_35 = T_1 ;
T_1 -> V_36 = L_1 ;
T_1 -> V_37 = 1.0 ;
T_1 -> V_38 = NULL ;
T_1 -> V_39 = - 1 ;
F_18 ( & T_1 -> V_40 ) ;
F_18 ( & T_1 -> V_41 ) ;
V_5 . F_4 ( T_1 ) ;
T_1 -> V_26 = F_6 ( V_22 -> V_8 ) ;
F_9 ( T_1 ) ;
T_1 -> V_42 = false ;
}
struct V_1 * F_19 ( struct V_33 * V_22 , int V_12 )
{
struct V_1 * T_1 = F_20 ( V_5 . V_6 ) ;
if ( T_1 != NULL )
F_17 ( T_1 , V_22 , V_12 ) ;
if ( F_21 ( T_1 ) ) {
T_1 -> V_22 . V_8 |= ( V_43 | V_17 |
V_19 | V_44 ) ,
T_1 -> V_22 . V_45 = 1 ;
}
return T_1 ;
}
struct V_1 * F_22 ( void )
{
struct V_33 V_22 = {
. type = V_46 ,
. V_47 = V_48 ,
} ;
struct V_1 * T_1 ;
F_23 ( & V_22 ) ;
F_24 ( & V_22 ) ;
T_1 = F_25 ( & V_22 ) ;
if ( T_1 == NULL )
goto V_49;
if ( F_26 ( & T_1 -> V_32 , L_2 ,
V_22 . V_50 ? V_22 . V_50 + 1 : 0 , L_3 ) < 0 )
goto V_51;
V_49:
return T_1 ;
V_51:
F_27 ( T_1 ) ;
T_1 = NULL ;
goto V_49;
}
struct V_1 * F_28 ( const char * V_52 , const char * V_32 , int V_12 )
{
struct V_1 * T_1 = F_20 ( V_5 . V_6 ) ;
int V_53 = - V_54 ;
if ( T_1 == NULL ) {
goto V_55;
} else {
struct V_33 V_22 = {
. type = V_56 ,
. V_8 = ( V_43 | V_17 |
V_19 | V_44 ) ,
} ;
if ( F_26 ( & T_1 -> V_32 , L_4 , V_52 , V_32 ) < 0 )
goto V_57;
T_1 -> V_58 = F_29 ( V_52 , V_32 ) ;
if ( F_30 ( T_1 -> V_58 ) ) {
V_53 = F_31 ( T_1 -> V_58 ) ;
goto V_57;
}
F_23 ( & V_22 ) ;
V_22 . V_47 = T_1 -> V_58 -> V_59 ;
V_22 . V_45 = 1 ;
F_17 ( T_1 , & V_22 , V_12 ) ;
}
return T_1 ;
V_57:
F_32 ( & T_1 -> V_32 ) ;
free ( T_1 ) ;
V_55:
return F_33 ( V_53 ) ;
}
static const char * F_34 ( T_3 V_47 )
{
if ( V_47 < V_60 && V_61 [ V_47 ] )
return V_61 [ V_47 ] ;
return L_5 ;
}
static int F_35 ( struct V_1 * T_1 , char * V_62 , T_2 V_6 )
{
int V_63 = 0 , V_64 = 0 ;
struct V_33 * V_22 = & T_1 -> V_22 ;
bool V_65 = false ;
#define F_36 ( T_4 , T_5 ) do { \
if (!attr->exclude_##context) { \
if (!colon) colon = ++r; \
r += scnprintf(bf + r, size - r, "%c", mod); \
} } while(0)
if ( V_22 -> V_66 || V_22 -> V_67 || V_22 -> V_68 ) {
F_36 ( V_69 , 'k' ) ;
F_36 ( V_70 , 'u' ) ;
F_36 ( V_71 , 'h' ) ;
V_65 = true ;
}
if ( V_22 -> V_50 ) {
if ( ! V_63 )
V_63 = ++ V_64 ;
V_64 += F_37 ( V_62 + V_64 , V_6 - V_64 , L_6 , V_22 -> V_50 , L_7 ) ;
V_65 = true ;
}
if ( V_22 -> V_72 || V_22 -> V_73 == V_65 ) {
F_36 ( V_74 , 'H' ) ;
F_36 ( V_75 , 'G' ) ;
}
#undef F_36
if ( V_63 )
V_62 [ V_63 - 1 ] = ':' ;
return V_64 ;
}
static int F_38 ( struct V_1 * T_1 , char * V_62 , T_2 V_6 )
{
int V_64 = F_37 ( V_62 , V_6 , L_8 , F_34 ( T_1 -> V_22 . V_47 ) ) ;
return V_64 + F_35 ( T_1 , V_62 + V_64 , V_6 - V_64 ) ;
}
static const char * F_39 ( T_3 V_47 )
{
if ( V_47 < V_76 && V_77 [ V_47 ] )
return V_77 [ V_47 ] ;
return L_9 ;
}
static int F_40 ( struct V_1 * T_1 , char * V_62 , T_2 V_6 )
{
int V_64 = F_37 ( V_62 , V_6 , L_8 , F_39 ( T_1 -> V_22 . V_47 ) ) ;
return V_64 + F_35 ( T_1 , V_62 + V_64 , V_6 - V_64 ) ;
}
static int F_41 ( char * V_62 , T_2 V_6 , T_3 V_78 , T_3 type )
{
int V_64 ;
V_64 = F_37 ( V_62 , V_6 , L_10 V_79 L_11 , V_78 ) ;
if ( type & V_80 )
V_64 += F_37 ( V_62 + V_64 , V_6 - V_64 , L_12 ) ;
if ( type & V_81 )
V_64 += F_37 ( V_62 + V_64 , V_6 - V_64 , L_13 ) ;
if ( type & V_82 )
V_64 += F_37 ( V_62 + V_64 , V_6 - V_64 , L_14 ) ;
return V_64 ;
}
static int F_42 ( struct V_1 * T_1 , char * V_62 , T_2 V_6 )
{
struct V_33 * V_22 = & T_1 -> V_22 ;
int V_64 = F_41 ( V_62 , V_6 , V_22 -> V_83 , V_22 -> V_84 ) ;
return V_64 + F_35 ( T_1 , V_62 + V_64 , V_6 - V_64 ) ;
}
bool F_43 ( T_6 type , T_6 V_85 )
{
if ( V_86 [ type ] & F_44 ( V_85 ) )
return true ;
else
return false ;
}
int F_45 ( T_6 type , T_6 V_85 , T_6 V_87 ,
char * V_62 , T_2 V_6 )
{
if ( V_87 ) {
return F_37 ( V_62 , V_6 , L_15 , V_88 [ type ] [ 0 ] ,
V_89 [ V_85 ] [ 0 ] ,
V_90 [ V_87 ] [ 0 ] ) ;
}
return F_37 ( V_62 , V_6 , L_16 , V_88 [ type ] [ 0 ] ,
V_89 [ V_85 ] [ 1 ] ) ;
}
static int F_46 ( T_3 V_47 , char * V_62 , T_2 V_6 )
{
T_6 V_85 , V_87 , type = ( V_47 >> 0 ) & 0xff ;
const char * V_53 = L_17 ;
if ( type >= V_91 )
goto V_55;
V_85 = ( V_47 >> 8 ) & 0xff ;
V_53 = L_18 ;
if ( V_85 >= V_92 )
goto V_55;
V_87 = ( V_47 >> 16 ) & 0xff ;
V_53 = L_19 ;
if ( V_87 >= V_93 )
goto V_55;
V_53 = L_20 ;
if ( ! F_43 ( type , V_85 ) )
goto V_55;
return F_45 ( type , V_85 , V_87 , V_62 , V_6 ) ;
V_55:
return F_37 ( V_62 , V_6 , L_8 , V_53 ) ;
}
static int F_47 ( struct V_1 * T_1 , char * V_62 , T_2 V_6 )
{
int V_94 = F_46 ( T_1 -> V_22 . V_47 , V_62 , V_6 ) ;
return V_94 + F_35 ( T_1 , V_62 + V_94 , V_6 - V_94 ) ;
}
static int F_48 ( struct V_1 * T_1 , char * V_62 , T_2 V_6 )
{
int V_94 = F_37 ( V_62 , V_6 , L_21 V_79 , T_1 -> V_22 . V_47 ) ;
return V_94 + F_35 ( T_1 , V_62 + V_94 , V_6 - V_94 ) ;
}
const char * F_49 ( struct V_1 * T_1 )
{
char V_62 [ 128 ] ;
if ( T_1 -> V_32 )
return T_1 -> V_32 ;
switch ( T_1 -> V_22 . type ) {
case V_95 :
F_48 ( T_1 , V_62 , sizeof( V_62 ) ) ;
break;
case V_46 :
F_38 ( T_1 , V_62 , sizeof( V_62 ) ) ;
break;
case V_96 :
F_47 ( T_1 , V_62 , sizeof( V_62 ) ) ;
break;
case V_97 :
F_40 ( T_1 , V_62 , sizeof( V_62 ) ) ;
break;
case V_56 :
F_37 ( V_62 , sizeof( V_62 ) , L_8 , L_22 ) ;
break;
case V_98 :
F_42 ( T_1 , V_62 , sizeof( V_62 ) ) ;
break;
default:
F_37 ( V_62 , sizeof( V_62 ) , L_23 ,
T_1 -> V_22 . type ) ;
break;
}
T_1 -> V_32 = F_50 ( V_62 ) ;
return T_1 -> V_32 ? : L_24 ;
}
const char * F_51 ( struct V_1 * T_1 )
{
return T_1 -> V_99 ? : L_25 ;
}
int F_52 ( struct V_1 * T_1 , char * V_100 , T_2 V_6 )
{
int V_94 ;
struct V_1 * V_101 ;
const char * V_99 = F_51 ( T_1 ) ;
V_94 = F_37 ( V_100 , V_6 , L_8 , V_99 ) ;
V_94 += F_37 ( V_100 + V_94 , V_6 - V_94 , L_26 ,
F_49 ( T_1 ) ) ;
F_53 (pos, evsel)
V_94 += F_37 ( V_100 + V_94 , V_6 - V_94 , L_27 ,
F_49 ( V_101 ) ) ;
V_94 += F_37 ( V_100 + V_94 , V_6 - V_94 , L_28 ) ;
return V_94 ;
}
void F_54 ( struct V_1 * T_1 ,
struct V_102 * V_103 ,
struct V_104 * V_105 )
{
bool V_106 = F_15 ( T_1 ) ;
struct V_33 * V_22 = & T_1 -> V_22 ;
F_14 ( T_1 , V_107 ) ;
V_22 -> V_108 = V_105 -> V_109 ;
if ( V_105 -> V_110 == V_111 ) {
if ( ! V_103 -> V_112 ) {
if ( V_22 -> V_67 ) {
F_55 ( L_29
L_30
L_31 ) ;
} else {
F_14 ( T_1 , V_113 ) ;
V_22 -> V_114 = V_115 |
V_116 |
V_117 |
V_118 ;
}
} else
F_55 ( L_32
L_31 ) ;
}
if ( V_105 -> V_110 == V_119 ) {
if ( ! V_106 ) {
F_14 ( T_1 , V_120 ) ;
F_14 ( T_1 , V_121 ) ;
V_22 -> V_122 = V_123 ;
V_22 -> V_124 = V_105 -> V_125 ;
V_22 -> V_126 = 1 ;
} else {
F_56 ( L_33
L_34 ) ;
}
}
if ( V_106 ) {
F_56 ( L_35 ) ;
V_22 -> V_126 = 1 ;
}
}
static void
F_57 ( struct V_1 * T_1 ,
struct V_104 * V_105 )
{
struct V_33 * V_22 = & T_1 -> V_22 ;
F_13 ( T_1 , V_107 ) ;
if ( V_105 -> V_110 == V_111 ) {
F_13 ( T_1 , V_113 ) ;
V_22 -> V_114 &= ~ ( V_115 |
V_116 ) ;
}
if ( V_105 -> V_110 == V_119 ) {
F_13 ( T_1 , V_120 ) ;
F_13 ( T_1 , V_121 ) ;
}
}
static void F_58 ( struct V_1 * T_1 ,
struct V_102 * V_103 )
{
struct V_127 * V_128 ;
struct V_129 * V_41 = & T_1 -> V_41 ;
struct V_33 * V_22 = & T_1 -> V_22 ;
struct V_104 V_105 ;
T_7 V_125 = 0 ;
int V_109 = 0 ;
const char * V_130 = NULL ;
V_105 . V_110 = V_104 . V_110 ;
F_59 (term, config_terms, list) {
switch ( V_128 -> type ) {
case V_131 :
V_22 -> V_45 = V_128 -> V_132 . V_133 ;
V_22 -> V_134 = 0 ;
break;
case V_135 :
V_22 -> V_136 = V_128 -> V_132 . V_134 ;
V_22 -> V_134 = 1 ;
break;
case V_137 :
if ( V_128 -> V_132 . time )
F_14 ( T_1 , TIME ) ;
else
F_13 ( T_1 , TIME ) ;
break;
case V_138 :
V_130 = V_128 -> V_132 . V_139 ;
break;
case V_140 :
V_125 = V_128 -> V_132 . V_141 ;
break;
case V_142 :
V_109 = V_128 -> V_132 . V_109 ;
break;
case V_143 :
V_22 -> V_144 = V_128 -> V_132 . V_144 ? 1 : 0 ;
break;
case V_145 :
V_22 -> V_146 = V_128 -> V_132 . V_147 ? 1 : 0 ;
break;
default:
break;
}
}
if ( ( V_130 != NULL ) || ( V_125 > 0 ) || V_109 ) {
if ( V_109 ) {
V_105 . V_109 = V_109 ;
if ( V_130 == NULL )
V_130 = L_36 ;
}
if ( V_130 != NULL ) {
if ( ! strcmp ( V_130 , L_37 ) ) {
V_105 . V_148 = false ;
V_105 . V_110 = V_149 ;
} else {
V_105 . V_148 = true ;
if ( F_60 ( V_130 , & V_105 ) ) {
F_61 ( L_38
L_39 ,
T_1 -> V_32 ) ;
return;
}
}
}
if ( V_125 > 0 ) {
V_125 = F_62 ( V_125 , sizeof( T_3 ) ) ;
V_105 . V_125 = V_125 ;
}
if ( V_104 . V_148 )
F_57 ( T_1 , & V_104 ) ;
if ( V_105 . V_148 )
F_54 ( T_1 , V_103 , & V_105 ) ;
}
}
void F_63 ( struct V_1 * T_1 , struct V_102 * V_103 ,
struct V_104 * V_150 )
{
struct V_1 * V_35 = T_1 -> V_35 ;
struct V_33 * V_22 = & T_1 -> V_22 ;
int V_151 = T_1 -> V_34 ;
bool V_152 = V_103 -> V_153 . V_154 && ! V_103 -> V_153 . V_155 ;
V_22 -> V_156 = V_157 . V_156 ? 0 : 1 ;
V_22 -> V_144 = ! V_103 -> V_158 ;
V_22 -> V_146 = V_103 -> V_147 ? 1 : 0 ;
F_14 ( T_1 , V_159 ) ;
F_14 ( T_1 , V_160 ) ;
if ( T_1 -> V_161 ) {
F_14 ( T_1 , V_162 ) ;
F_12 ( T_1 , false ) ;
if ( V_35 -> V_163 > 1 ) {
V_22 -> V_30 |= V_164 ;
V_22 -> V_144 = 0 ;
}
}
if ( ! V_22 -> V_45 || ( V_103 -> V_165 != V_166 ||
V_103 -> V_167 != V_168 ) ) {
if ( V_103 -> V_134 ) {
F_14 ( T_1 , V_169 ) ;
V_22 -> V_134 = 1 ;
V_22 -> V_136 = V_103 -> V_134 ;
} else {
V_22 -> V_45 = V_103 -> V_170 ;
}
}
if ( ( V_35 != T_1 ) && V_35 -> V_161 ) {
V_22 -> V_136 = 0 ;
V_22 -> V_45 = 0 ;
}
if ( V_103 -> V_171 )
V_22 -> V_136 = 0 ;
if ( V_103 -> V_172 )
V_22 -> V_172 = 1 ;
if ( V_103 -> V_173 ) {
F_14 ( T_1 , V_174 ) ;
V_22 -> V_175 = V_151 ;
}
if ( F_15 ( T_1 ) )
T_1 -> V_22 . V_126 = 1 ;
if ( V_150 && V_150 -> V_148 && ! T_1 -> V_176 )
F_54 ( T_1 , V_103 , V_150 ) ;
if ( V_103 -> V_177 ) {
V_22 -> V_178 = V_103 -> V_177 ;
F_14 ( T_1 , V_179 ) ;
}
if ( F_64 ( & V_103 -> V_153 ) || V_103 -> V_180 )
F_14 ( T_1 , V_181 ) ;
if ( V_103 -> V_133 )
F_14 ( T_1 , V_169 ) ;
if ( V_103 -> V_182 &&
( ! V_157 . V_156 &&
( ! V_103 -> V_158 || F_64 ( & V_103 -> V_153 ) || V_152 ||
V_103 -> V_183 ) ) )
F_14 ( T_1 , TIME ) ;
if ( V_103 -> V_184 && ! T_1 -> V_176 ) {
F_14 ( T_1 , TIME ) ;
F_14 ( T_1 , V_185 ) ;
F_14 ( T_1 , V_181 ) ;
}
if ( V_103 -> V_173 )
F_14 ( T_1 , V_186 ) ;
if ( V_103 -> V_187 ) {
V_22 -> V_188 = 0 ;
V_22 -> V_189 = 1 ;
}
if ( V_103 -> V_112 && ! T_1 -> V_176 ) {
F_14 ( T_1 , V_113 ) ;
V_22 -> V_114 = V_103 -> V_112 ;
}
if ( V_103 -> V_190 )
F_14 ( T_1 , V_191 ) ;
V_22 -> V_192 = V_151 ;
V_22 -> V_193 = V_151 ;
V_22 -> V_194 = V_151 && ! V_157 . V_194 ;
V_22 -> V_195 = V_151 ;
if ( V_103 -> V_196 )
V_22 -> V_197 = V_151 ;
if ( V_103 -> V_198 )
F_14 ( T_1 , V_199 ) ;
if ( V_103 -> V_200 ) {
T_1 -> V_22 . V_30 |=
V_201 |
V_202 ;
}
if ( F_65 ( T_1 ) )
V_22 -> V_203 = 1 ;
if ( F_66 ( & V_103 -> V_153 ) && F_65 ( T_1 ) &&
! V_103 -> V_204 )
V_22 -> V_205 = 1 ;
if ( T_1 -> V_206 ) {
V_22 -> V_203 = 0 ;
V_22 -> V_205 = 0 ;
}
V_207 = V_103 -> V_207 ;
if ( V_103 -> V_208 ) {
V_22 -> V_208 = 1 ;
V_22 -> V_207 = V_103 -> V_207 ;
}
if ( T_1 -> V_209 )
F_24 ( V_22 ) ;
if ( V_103 -> V_210 ) {
V_22 -> V_66 = 1 ;
V_22 -> V_67 = 0 ;
}
if ( V_103 -> V_211 ) {
V_22 -> V_66 = 0 ;
V_22 -> V_67 = 1 ;
}
F_58 ( T_1 , V_103 ) ;
}
static int F_67 ( struct V_1 * T_1 , int V_212 , int V_213 )
{
int V_214 , V_215 ;
if ( T_1 -> V_216 )
V_213 = 1 ;
T_1 -> V_217 = F_68 ( V_212 , V_213 , sizeof( int ) ) ;
if ( T_1 -> V_217 ) {
for ( V_214 = 0 ; V_214 < V_212 ; V_214 ++ ) {
for ( V_215 = 0 ; V_215 < V_213 ; V_215 ++ ) {
F_69 ( T_1 , V_214 , V_215 ) = - 1 ;
}
}
}
return T_1 -> V_217 != NULL ? 0 : - V_54 ;
}
static int F_70 ( struct V_1 * T_1 , int V_212 , int V_213 ,
int V_218 , void * V_219 )
{
int V_214 , V_215 ;
if ( T_1 -> V_216 )
V_213 = 1 ;
for ( V_214 = 0 ; V_214 < V_212 ; V_214 ++ ) {
for ( V_215 = 0 ; V_215 < V_213 ; V_215 ++ ) {
int V_217 = F_69 ( T_1 , V_214 , V_215 ) ,
V_53 = F_71 ( V_217 , V_218 , V_219 ) ;
if ( V_53 )
return V_53 ;
}
}
return 0 ;
}
int F_72 ( struct V_1 * T_1 , int V_212 , int V_213 ,
const char * V_220 )
{
return F_70 ( T_1 , V_212 , V_213 ,
V_221 ,
( void * ) V_220 ) ;
}
int F_73 ( struct V_1 * T_1 , const char * V_220 )
{
char * V_222 = F_50 ( V_220 ) ;
if ( V_222 != NULL ) {
free ( T_1 -> V_220 ) ;
T_1 -> V_220 = V_222 ;
return 0 ;
}
return - 1 ;
}
int F_74 ( struct V_1 * T_1 ,
const char * V_85 , const char * V_220 )
{
char * V_222 ;
if ( T_1 -> V_220 == NULL )
return F_73 ( T_1 , V_220 ) ;
if ( F_26 ( & V_222 , L_40 , T_1 -> V_220 , V_85 , V_220 ) > 0 ) {
free ( T_1 -> V_220 ) ;
T_1 -> V_220 = V_222 ;
return 0 ;
}
return - 1 ;
}
int F_75 ( struct V_1 * T_1 )
{
int V_213 = F_76 ( T_1 -> V_223 ) ;
int V_212 = F_77 ( T_1 -> V_224 ) ;
return F_70 ( T_1 , V_212 , V_213 ,
V_225 ,
0 ) ;
}
int F_78 ( struct V_1 * T_1 )
{
int V_213 = F_76 ( T_1 -> V_223 ) ;
int V_212 = F_77 ( T_1 -> V_224 ) ;
return F_70 ( T_1 , V_212 , V_213 ,
V_226 ,
0 ) ;
}
int F_79 ( struct V_1 * T_1 , int V_212 , int V_213 )
{
if ( V_212 == 0 || V_213 == 0 )
return 0 ;
if ( T_1 -> V_216 )
V_213 = 1 ;
T_1 -> V_227 = F_68 ( V_212 , V_213 , sizeof( struct V_228 ) ) ;
if ( T_1 -> V_227 == NULL )
return - V_54 ;
T_1 -> V_59 = F_20 ( V_212 * V_213 * sizeof( T_3 ) ) ;
if ( T_1 -> V_59 == NULL ) {
F_80 ( T_1 -> V_227 ) ;
T_1 -> V_227 = NULL ;
return - V_54 ;
}
return 0 ;
}
static void F_81 ( struct V_1 * T_1 )
{
F_80 ( T_1 -> V_217 ) ;
T_1 -> V_217 = NULL ;
}
static void F_82 ( struct V_1 * T_1 )
{
F_80 ( T_1 -> V_227 ) ;
T_1 -> V_227 = NULL ;
F_32 ( & T_1 -> V_59 ) ;
}
static void F_83 ( struct V_1 * T_1 )
{
struct V_127 * V_128 , * V_229 ;
F_84 (term, h, &evsel->config_terms, list) {
F_85 ( & V_128 -> V_230 ) ;
free ( V_128 ) ;
}
}
void F_86 ( struct V_1 * T_1 , int V_212 , int V_213 )
{
int V_214 , V_215 ;
if ( T_1 -> V_216 )
V_213 = 1 ;
for ( V_214 = 0 ; V_214 < V_212 ; V_214 ++ )
for ( V_215 = 0 ; V_215 < V_213 ; ++ V_215 ) {
F_87 ( F_69 ( T_1 , V_214 , V_215 ) ) ;
F_69 ( T_1 , V_214 , V_215 ) = - 1 ;
}
}
void F_88 ( struct V_1 * T_1 )
{
assert ( F_89 ( & T_1 -> V_40 ) ) ;
assert ( T_1 -> V_38 == NULL ) ;
F_81 ( T_1 ) ;
F_82 ( T_1 ) ;
F_83 ( T_1 ) ;
F_90 ( T_1 -> V_231 ) ;
F_91 ( T_1 -> V_224 ) ;
F_91 ( T_1 -> V_232 ) ;
F_92 ( T_1 -> V_223 ) ;
F_32 ( & T_1 -> V_99 ) ;
F_32 ( & T_1 -> V_32 ) ;
V_5 . F_5 ( T_1 ) ;
}
void F_27 ( struct V_1 * T_1 )
{
F_88 ( T_1 ) ;
free ( T_1 ) ;
}
void F_93 ( struct V_1 * T_1 , int V_214 , int V_215 ,
struct V_233 * V_234 )
{
struct V_233 V_235 ;
if ( ! T_1 -> V_236 )
return;
if ( V_214 == - 1 ) {
V_235 = T_1 -> V_236 -> V_237 ;
T_1 -> V_236 -> V_237 = * V_234 ;
} else {
V_235 = * F_94 ( T_1 -> V_236 , V_214 , V_215 ) ;
* F_94 ( T_1 -> V_236 , V_214 , V_215 ) = * V_234 ;
}
V_234 -> V_132 = V_234 -> V_132 - V_235 . V_132 ;
V_234 -> V_238 = V_234 -> V_238 - V_235 . V_238 ;
V_234 -> V_239 = V_234 -> V_239 - V_235 . V_239 ;
}
void F_95 ( struct V_233 * V_234 ,
bool V_37 , T_8 * V_240 )
{
T_8 V_241 = 0 ;
if ( V_37 ) {
if ( V_234 -> V_239 == 0 ) {
V_241 = - 1 ;
V_234 -> V_132 = 0 ;
} else if ( V_234 -> V_239 < V_234 -> V_238 ) {
V_241 = 1 ;
V_234 -> V_132 = ( T_3 ) ( ( double ) V_234 -> V_132 * V_234 -> V_238 / V_234 -> V_239 + 0.5 ) ;
}
} else
V_234 -> V_238 = V_234 -> V_239 = 0 ;
if ( V_240 )
* V_240 = V_241 ;
}
int F_96 ( struct V_1 * T_1 , int V_214 , int V_215 ,
struct V_233 * V_234 )
{
memset ( V_234 , 0 , sizeof( * V_234 ) ) ;
if ( F_69 ( T_1 , V_214 , V_215 ) < 0 )
return - V_7 ;
if ( F_97 ( F_69 ( T_1 , V_214 , V_215 ) , V_234 , sizeof( * V_234 ) ) < 0 )
return - V_242 ;
return 0 ;
}
int F_98 ( struct V_1 * T_1 ,
int V_214 , int V_215 , bool V_37 )
{
struct V_233 V_234 ;
T_2 V_243 = V_37 ? 3 : 1 ;
if ( F_69 ( T_1 , V_214 , V_215 ) < 0 )
return - V_7 ;
if ( T_1 -> V_244 == NULL && F_99 ( T_1 , V_214 + 1 , V_215 + 1 ) < 0 )
return - V_54 ;
if ( F_97 ( F_69 ( T_1 , V_214 , V_215 ) , & V_234 , V_243 * sizeof( T_3 ) ) < 0 )
return - V_242 ;
F_93 ( T_1 , V_214 , V_215 , & V_234 ) ;
F_95 ( & V_234 , V_37 , NULL ) ;
* F_94 ( T_1 -> V_244 , V_214 , V_215 ) = V_234 ;
return 0 ;
}
static int F_100 ( struct V_1 * T_1 , int V_214 , int V_215 )
{
struct V_1 * V_35 = T_1 -> V_35 ;
int V_217 ;
if ( F_65 ( T_1 ) )
return - 1 ;
F_101 ( ! V_35 -> V_217 ) ;
V_217 = F_69 ( V_35 , V_214 , V_215 ) ;
F_101 ( V_217 == - 1 ) ;
return V_217 ;
}
static void F_102 ( char * V_100 , T_2 V_6 , T_3 V_245 , struct V_246 * V_247 )
{
bool V_248 = true ;
int V_11 = 0 ;
do {
if ( V_245 & V_247 [ V_11 ] . V_25 ) {
V_100 += F_37 ( V_100 , V_6 , L_41 , V_248 ? L_1 : L_42 , V_247 [ V_11 ] . V_32 ) ;
V_248 = false ;
}
} while ( V_247 [ ++ V_11 ] . V_32 != NULL );
}
static void F_103 ( char * V_100 , T_2 V_6 , T_3 V_245 )
{
#define F_104 ( T_9 ) { PERF_SAMPLE_##n, #n }
struct V_246 V_247 [] = {
F_104 ( V_159 ) , F_104 ( V_160 ) , F_104 ( TIME ) , F_104 ( V_174 ) ,
F_104 ( V_162 ) , F_104 ( V_107 ) , F_104 ( V_28 ) , F_104 ( V_181 ) ,
F_104 ( V_169 ) , F_104 ( V_249 ) , F_104 ( V_185 ) ,
F_104 ( V_113 ) , F_104 ( V_120 ) , F_104 ( V_121 ) ,
F_104 ( V_29 ) , F_104 ( V_179 ) , F_104 ( V_186 ) ,
F_104 ( V_191 ) ,
{ . V_32 = NULL , }
} ;
#undef F_104
F_102 ( V_100 , V_6 , V_245 , V_247 ) ;
}
static void F_105 ( char * V_100 , T_2 V_6 , T_3 V_245 )
{
#define F_104 ( T_9 ) { PERF_SAMPLE_BRANCH_##n, #n }
struct V_246 V_247 [] = {
F_104 ( V_250 ) , F_104 ( V_251 ) , F_104 ( V_252 ) , F_104 ( V_253 ) ,
F_104 ( V_254 ) , F_104 ( V_255 ) , F_104 ( V_256 ) ,
F_104 ( V_257 ) , F_104 ( V_258 ) , F_104 ( V_259 ) ,
F_104 ( V_260 ) , F_104 ( V_261 ) , F_104 ( V_262 ) ,
F_104 ( V_263 ) , F_104 ( V_264 ) , F_104 ( V_265 ) ,
{ . V_32 = NULL , }
} ;
#undef F_104
F_102 ( V_100 , V_6 , V_245 , V_247 ) ;
}
static void F_106 ( char * V_100 , T_2 V_6 , T_3 V_245 )
{
#define F_104 ( T_9 ) { PERF_FORMAT_##n, #n }
struct V_246 V_247 [] = {
F_104 ( V_266 ) , F_104 ( V_267 ) ,
F_104 ( V_28 ) , F_104 ( V_268 ) ,
{ . V_32 = NULL , }
} ;
#undef F_104
F_102 ( V_100 , V_6 , V_245 , V_247 ) ;
}
int F_107 ( T_10 * V_269 , struct V_33 * V_22 ,
T_11 V_270 , void * V_271 )
{
char V_100 [ V_272 ] ;
int V_94 = 0 ;
F_108 ( type , V_273 ) ;
F_108 ( V_6 , V_273 ) ;
F_108 ( V_47 , V_274 ) ;
F_109 ( L_43 , V_45 , V_273 ) ;
F_108 ( V_8 , V_275 ) ;
F_108 ( V_30 , V_276 ) ;
F_108 ( V_203 , V_273 ) ;
F_108 ( V_144 , V_273 ) ;
F_108 ( V_277 , V_273 ) ;
F_108 ( V_278 , V_273 ) ;
F_108 ( V_67 , V_273 ) ;
F_108 ( V_66 , V_273 ) ;
F_108 ( V_68 , V_273 ) ;
F_108 ( V_279 , V_273 ) ;
F_108 ( V_193 , V_273 ) ;
F_108 ( V_195 , V_273 ) ;
F_108 ( V_134 , V_273 ) ;
F_108 ( V_172 , V_273 ) ;
F_108 ( V_205 , V_273 ) ;
F_108 ( V_192 , V_273 ) ;
F_108 ( V_188 , V_273 ) ;
F_108 ( V_50 , V_273 ) ;
F_108 ( V_175 , V_273 ) ;
F_108 ( V_156 , V_273 ) ;
F_108 ( V_72 , V_273 ) ;
F_108 ( V_73 , V_273 ) ;
F_108 ( V_280 , V_273 ) ;
F_108 ( V_126 , V_273 ) ;
F_108 ( V_194 , V_273 ) ;
F_108 ( V_281 , V_273 ) ;
F_108 ( V_208 , V_273 ) ;
F_108 ( V_197 , V_273 ) ;
F_108 ( V_146 , V_273 ) ;
F_109 ( L_44 , V_189 , V_273 ) ;
F_108 ( V_84 , V_273 ) ;
F_109 ( L_45 , V_83 , V_274 ) ;
F_109 ( L_46 , V_282 , V_274 ) ;
F_108 ( V_114 , V_283 ) ;
F_108 ( V_122 , V_274 ) ;
F_108 ( V_124 , V_273 ) ;
F_108 ( V_207 , V_284 ) ;
F_108 ( V_178 , V_274 ) ;
F_108 ( V_285 , V_273 ) ;
F_108 ( V_108 , V_273 ) ;
return V_94 ;
}
static int F_110 ( struct V_1 * T_1 , struct V_286 * V_224 ,
struct V_287 * V_223 )
{
int V_214 , V_215 , V_213 ;
unsigned long V_288 = V_289 ;
int V_290 = - 1 , V_53 ;
enum { V_291 , V_292 , V_293 } V_294 = V_291 ;
if ( V_157 . V_146 && T_1 -> V_22 . V_146 )
return - V_7 ;
if ( T_1 -> V_216 )
V_213 = 1 ;
else
V_213 = V_223 -> V_295 ;
if ( T_1 -> V_217 == NULL &&
F_67 ( T_1 , V_224 -> V_295 , V_213 ) < 0 )
return - V_54 ;
if ( T_1 -> V_231 ) {
V_288 |= V_296 ;
V_290 = T_1 -> V_231 -> V_217 ;
}
V_297:
if ( V_157 . V_298 )
T_1 -> V_22 . V_207 = V_299 ;
if ( V_157 . V_207 ) {
T_1 -> V_22 . V_208 = 0 ;
T_1 -> V_22 . V_207 = 0 ;
}
if ( V_157 . V_300 )
V_288 &= ~ ( unsigned long ) V_289 ;
if ( V_157 . V_194 )
T_1 -> V_22 . V_194 = 0 ;
if ( V_157 . V_73 )
T_1 -> V_22 . V_73 = T_1 -> V_22 . V_72 = 0 ;
if ( V_157 . V_301 )
T_1 -> V_22 . V_114 &= ~ ( V_118 |
V_117 ) ;
V_302:
if ( V_157 . V_156 )
T_1 -> V_22 . V_156 = 0 ;
if ( V_303 >= 2 ) {
fprintf ( V_304 , L_47 , V_305 ) ;
fprintf ( V_304 , L_48 ) ;
F_107 ( V_304 , & T_1 -> V_22 , V_306 , NULL ) ;
fprintf ( V_304 , L_47 , V_305 ) ;
}
for ( V_214 = 0 ; V_214 < V_224 -> V_295 ; V_214 ++ ) {
for ( V_215 = 0 ; V_215 < V_213 ; V_215 ++ ) {
int V_307 ;
if ( ! T_1 -> V_231 && ! T_1 -> V_216 )
V_290 = F_111 ( V_223 , V_215 ) ;
V_307 = F_100 ( T_1 , V_214 , V_215 ) ;
V_308:
F_112 ( L_49 ,
V_290 , V_224 -> V_309 [ V_214 ] , V_307 , V_288 ) ;
F_69 ( T_1 , V_214 , V_215 ) = F_113 ( & T_1 -> V_22 ,
V_290 ,
V_224 -> V_309 [ V_214 ] ,
V_307 , V_288 ) ;
if ( F_69 ( T_1 , V_214 , V_215 ) < 0 ) {
V_53 = - V_242 ;
F_112 ( L_50 ,
V_53 ) ;
goto V_310;
}
if ( T_1 -> V_39 >= 0 ) {
int V_311 = F_69 ( T_1 , V_214 , V_215 ) ;
int V_39 = T_1 -> V_39 ;
V_53 = F_71 ( V_311 ,
V_312 ,
V_39 ) ;
if ( V_53 && V_242 != V_313 ) {
F_61 ( L_51 ,
V_39 , strerror ( V_242 ) ) ;
V_53 = - V_7 ;
goto V_314;
}
}
V_294 = V_291 ;
if ( V_157 . V_207 ||
V_157 . V_298 ) {
V_53 = - V_7 ;
goto V_314;
}
}
}
return 0 ;
V_310:
if ( V_53 == - V_315 && V_294 < V_293 ) {
struct V_316 V_317 ;
int V_318 = V_242 ;
if ( F_114 ( V_319 , & V_317 ) == 0 ) {
if ( V_294 == V_291 )
V_317 . V_320 = V_317 . V_321 ;
else {
V_317 . V_320 = V_317 . V_321 + 1000 ;
V_317 . V_321 = V_317 . V_320 ;
}
if ( F_115 ( V_319 , & V_317 ) == 0 ) {
V_294 ++ ;
V_242 = V_318 ;
goto V_308;
}
}
V_242 = V_318 ;
}
if ( V_53 != - V_7 || V_214 > 0 || V_215 > 0 )
goto V_314;
if ( ! V_157 . V_146 && T_1 -> V_22 . V_146 ) {
V_157 . V_146 = true ;
goto V_314;
} else if ( ! V_157 . V_298 && T_1 -> V_22 . V_208 ) {
V_157 . V_298 = true ;
goto V_297;
} else if ( ! V_157 . V_207 && T_1 -> V_22 . V_208 ) {
V_157 . V_207 = true ;
goto V_297;
} else if ( ! V_157 . V_300 && ( V_288 & V_289 ) ) {
V_157 . V_300 = true ;
goto V_297;
} else if ( ! V_157 . V_194 && T_1 -> V_22 . V_194 ) {
V_157 . V_194 = true ;
goto V_297;
} else if ( ! V_157 . V_73 &&
( T_1 -> V_22 . V_73 || T_1 -> V_22 . V_72 ) ) {
V_157 . V_73 = true ;
goto V_297;
} else if ( ! V_157 . V_156 ) {
V_157 . V_156 = true ;
goto V_302;
} else if ( ! V_157 . V_301 &&
( T_1 -> V_22 . V_114 &
( V_117 |
V_118 ) ) ) {
V_157 . V_301 = true ;
goto V_297;
}
V_314:
do {
while ( -- V_215 >= 0 ) {
F_87 ( F_69 ( T_1 , V_214 , V_215 ) ) ;
F_69 ( T_1 , V_214 , V_215 ) = - 1 ;
}
V_215 = V_213 ;
} while ( -- V_214 >= 0 );
return V_53 ;
}
void F_116 ( struct V_1 * T_1 , int V_212 , int V_213 )
{
if ( T_1 -> V_217 == NULL )
return;
F_86 ( T_1 , V_212 , V_213 ) ;
F_81 ( T_1 ) ;
}
int F_117 ( struct V_1 * T_1 , struct V_286 * V_224 ,
struct V_287 * V_223 )
{
if ( V_224 == NULL ) {
V_224 = & V_322 . V_309 ;
}
if ( V_223 == NULL )
V_223 = & V_323 . V_309 ;
return F_110 ( T_1 , V_224 , V_223 ) ;
}
int F_118 ( struct V_1 * T_1 ,
struct V_286 * V_224 )
{
return F_110 ( T_1 , V_224 , & V_323 . V_309 ) ;
}
int F_119 ( struct V_1 * T_1 ,
struct V_287 * V_223 )
{
return F_110 ( T_1 , & V_322 . V_309 , V_223 ) ;
}
static int F_120 ( const struct V_1 * T_1 ,
const union V_324 * V_325 ,
struct V_326 * V_327 )
{
T_3 type = T_1 -> V_22 . V_8 ;
const T_3 * V_328 = V_325 -> V_327 . V_328 ;
bool V_329 = T_1 -> V_330 ;
union V_331 V_332 ;
V_328 += ( ( V_325 -> V_333 . V_6 -
sizeof( V_325 -> V_333 ) ) / sizeof( T_3 ) ) - 1 ;
if ( type & V_13 ) {
V_327 -> V_59 = * V_328 ;
V_328 -- ;
}
if ( type & V_19 ) {
V_332 . V_334 = * V_328 ;
if ( V_329 ) {
V_332 . V_334 = F_121 ( V_332 . V_334 ) ;
V_332 . V_335 [ 0 ] = F_122 ( V_332 . V_335 [ 0 ] ) ;
}
V_327 -> V_214 = V_332 . V_335 [ 0 ] ;
V_328 -- ;
}
if ( type & V_20 ) {
V_327 -> V_336 = * V_328 ;
V_328 -- ;
}
if ( type & V_14 ) {
V_327 -> V_59 = * V_328 ;
V_328 -- ;
}
if ( type & V_17 ) {
V_327 -> time = * V_328 ;
V_328 -- ;
}
if ( type & V_16 ) {
V_332 . V_334 = * V_328 ;
if ( V_329 ) {
V_332 . V_334 = F_121 ( V_332 . V_334 ) ;
V_332 . V_335 [ 0 ] = F_122 ( V_332 . V_335 [ 0 ] ) ;
V_332 . V_335 [ 1 ] = F_122 ( V_332 . V_335 [ 1 ] ) ;
}
V_327 -> V_290 = V_332 . V_335 [ 0 ] ;
V_327 -> V_337 = V_332 . V_335 [ 1 ] ;
V_328 -- ;
}
return 0 ;
}
static inline bool F_123 ( const void * V_338 , T_12 V_339 , const void * V_340 ,
T_3 V_6 )
{
return V_6 > V_339 || V_340 + V_6 > V_338 ;
}
int F_124 ( struct V_1 * T_1 , union V_324 * V_325 ,
struct V_326 * V_341 )
{
T_3 type = T_1 -> V_22 . V_8 ;
bool V_329 = T_1 -> V_330 ;
const T_3 * V_328 ;
T_12 V_339 = V_325 -> V_333 . V_6 ;
const void * V_338 = ( void * ) V_325 + V_339 ;
T_3 V_342 ;
union V_331 V_332 ;
memset ( V_341 , 0 , sizeof( * V_341 ) ) ;
V_341 -> V_214 = V_341 -> V_290 = V_341 -> V_337 = - 1 ;
V_341 -> V_336 = V_341 -> V_59 = V_341 -> time = - 1ULL ;
V_341 -> V_133 = T_1 -> V_22 . V_45 ;
V_341 -> V_343 = 0 ;
V_341 -> V_344 = V_325 -> V_333 . V_345 & V_346 ;
if ( V_325 -> V_333 . type != V_347 ) {
if ( ! T_1 -> V_22 . V_156 )
return 0 ;
return F_120 ( T_1 , V_325 , V_341 ) ;
}
V_328 = V_325 -> V_327 . V_328 ;
if ( T_1 -> V_26 + sizeof( V_325 -> V_333 ) > V_325 -> V_333 . V_6 )
return - V_348 ;
V_341 -> V_59 = - 1ULL ;
if ( type & V_13 ) {
V_341 -> V_59 = * V_328 ;
V_328 ++ ;
}
if ( type & V_15 ) {
V_341 -> V_349 = * V_328 ;
V_328 ++ ;
}
if ( type & V_16 ) {
V_332 . V_334 = * V_328 ;
if ( V_329 ) {
V_332 . V_334 = F_121 ( V_332 . V_334 ) ;
V_332 . V_335 [ 0 ] = F_122 ( V_332 . V_335 [ 0 ] ) ;
V_332 . V_335 [ 1 ] = F_122 ( V_332 . V_335 [ 1 ] ) ;
}
V_341 -> V_290 = V_332 . V_335 [ 0 ] ;
V_341 -> V_337 = V_332 . V_335 [ 1 ] ;
V_328 ++ ;
}
if ( type & V_17 ) {
V_341 -> time = * V_328 ;
V_328 ++ ;
}
V_341 -> V_78 = 0 ;
if ( type & V_18 ) {
V_341 -> V_78 = * V_328 ;
V_328 ++ ;
}
if ( type & V_14 ) {
V_341 -> V_59 = * V_328 ;
V_328 ++ ;
}
if ( type & V_20 ) {
V_341 -> V_336 = * V_328 ;
V_328 ++ ;
}
if ( type & V_19 ) {
V_332 . V_334 = * V_328 ;
if ( V_329 ) {
V_332 . V_334 = F_121 ( V_332 . V_334 ) ;
V_332 . V_335 [ 0 ] = F_122 ( V_332 . V_335 [ 0 ] ) ;
}
V_341 -> V_214 = V_332 . V_335 [ 0 ] ;
V_328 ++ ;
}
if ( type & V_44 ) {
V_341 -> V_133 = * V_328 ;
V_328 ++ ;
}
if ( type & V_350 ) {
T_3 V_30 = T_1 -> V_22 . V_30 ;
F_125 ( V_328 ) ;
if ( V_30 & V_164 )
V_341 -> V_351 . V_352 . V_295 = * V_328 ;
else
V_341 -> V_351 . V_353 . V_245 = * V_328 ;
V_328 ++ ;
if ( V_30 & V_201 ) {
F_125 ( V_328 ) ;
V_341 -> V_351 . V_354 = * V_328 ;
V_328 ++ ;
}
if ( V_30 & V_202 ) {
F_125 ( V_328 ) ;
V_341 -> V_351 . V_355 = * V_328 ;
V_328 ++ ;
}
if ( V_30 & V_164 ) {
const T_3 V_356 = V_357 /
sizeof( struct V_358 ) ;
if ( V_341 -> V_351 . V_352 . V_295 > V_356 )
return - V_348 ;
V_342 = V_341 -> V_351 . V_352 . V_295 *
sizeof( struct V_358 ) ;
F_126 ( V_328 , V_342 , V_339 ) ;
V_341 -> V_351 . V_352 . V_359 =
(struct V_358 * ) V_328 ;
V_328 = ( void * ) V_328 + V_342 ;
} else {
F_125 ( V_328 ) ;
V_341 -> V_351 . V_353 . V_59 = * V_328 ;
V_328 ++ ;
}
}
if ( type & V_360 ) {
const T_3 V_361 = V_357 / sizeof( T_3 ) ;
F_125 ( V_328 ) ;
V_341 -> V_150 = (struct V_362 * ) V_328 ++ ;
if ( V_341 -> V_150 -> V_295 > V_361 )
return - V_348 ;
V_342 = V_341 -> V_150 -> V_295 * sizeof( T_3 ) ;
F_126 ( V_328 , V_342 , V_339 ) ;
V_328 = ( void * ) V_328 + V_342 ;
}
if ( type & V_43 ) {
F_125 ( V_328 ) ;
V_332 . V_334 = * V_328 ;
if ( F_127 ( V_329 ,
L_52 ) ) {
V_332 . V_334 = F_121 ( V_332 . V_334 ) ;
V_332 . V_335 [ 0 ] = F_122 ( V_332 . V_335 [ 0 ] ) ;
V_332 . V_335 [ 1 ] = F_122 ( V_332 . V_335 [ 1 ] ) ;
}
V_341 -> V_363 = V_332 . V_335 [ 0 ] ;
V_328 = ( void * ) V_328 + sizeof( T_7 ) ;
F_126 ( V_328 , V_341 -> V_363 , V_339 ) ;
V_341 -> V_364 = ( void * ) V_328 ;
V_328 = ( void * ) V_328 + V_341 -> V_363 ;
}
if ( type & V_365 ) {
const T_3 V_366 = V_357 /
sizeof( struct V_367 ) ;
F_125 ( V_328 ) ;
V_341 -> V_112 = (struct V_112 * ) V_328 ++ ;
if ( V_341 -> V_112 -> V_295 > V_366 )
return - V_348 ;
V_342 = V_341 -> V_112 -> V_295 * sizeof( struct V_367 ) ;
F_126 ( V_328 , V_342 , V_339 ) ;
V_328 = ( void * ) V_328 + V_342 ;
}
if ( type & V_368 ) {
F_125 ( V_328 ) ;
V_341 -> V_369 . V_370 = * V_328 ;
V_328 ++ ;
if ( V_341 -> V_369 . V_370 ) {
T_3 V_9 = T_1 -> V_22 . V_122 ;
V_342 = F_128 ( V_9 ) * sizeof( T_3 ) ;
F_126 ( V_328 , V_342 , V_339 ) ;
V_341 -> V_369 . V_9 = V_9 ;
V_341 -> V_369 . V_371 = ( T_3 * ) V_328 ;
V_328 = ( void * ) V_328 + V_342 ;
}
}
if ( type & V_372 ) {
F_125 ( V_328 ) ;
V_342 = * V_328 ++ ;
V_341 -> V_373 . V_340 = ( ( char * ) ( V_328 - 1 )
- ( char * ) V_325 ) ;
if ( ! V_342 ) {
V_341 -> V_373 . V_6 = 0 ;
} else {
F_126 ( V_328 , V_342 , V_339 ) ;
V_341 -> V_373 . V_341 = ( char * ) V_328 ;
V_328 = ( void * ) V_328 + V_342 ;
F_125 ( V_328 ) ;
V_341 -> V_373 . V_6 = * V_328 ++ ;
if ( F_127 ( V_341 -> V_373 . V_6 > V_342 ,
L_53 ) )
return - V_348 ;
}
}
V_341 -> V_343 = 0 ;
if ( type & V_374 ) {
F_125 ( V_328 ) ;
V_341 -> V_343 = * V_328 ;
V_328 ++ ;
}
V_341 -> V_375 = V_376 ;
if ( type & V_377 ) {
F_125 ( V_328 ) ;
V_341 -> V_375 = * V_328 ;
V_328 ++ ;
}
V_341 -> V_378 = 0 ;
if ( type & V_379 ) {
F_125 ( V_328 ) ;
V_341 -> V_378 = * V_328 ;
V_328 ++ ;
}
V_341 -> V_380 . V_370 = V_381 ;
if ( type & V_382 ) {
F_125 ( V_328 ) ;
V_341 -> V_380 . V_370 = * V_328 ;
V_328 ++ ;
if ( V_341 -> V_380 . V_370 != V_381 ) {
T_3 V_9 = T_1 -> V_22 . V_178 ;
V_342 = F_128 ( V_9 ) * sizeof( T_3 ) ;
F_126 ( V_328 , V_342 , V_339 ) ;
V_341 -> V_380 . V_9 = V_9 ;
V_341 -> V_380 . V_371 = ( T_3 * ) V_328 ;
V_328 = ( void * ) V_328 + V_342 ;
}
}
return 0 ;
}
T_2 F_129 ( const struct V_326 * V_327 , T_3 type ,
T_3 V_30 )
{
T_2 V_342 , V_87 = sizeof( struct V_383 ) ;
if ( type & V_13 )
V_87 += sizeof( T_3 ) ;
if ( type & V_15 )
V_87 += sizeof( T_3 ) ;
if ( type & V_16 )
V_87 += sizeof( T_3 ) ;
if ( type & V_17 )
V_87 += sizeof( T_3 ) ;
if ( type & V_18 )
V_87 += sizeof( T_3 ) ;
if ( type & V_14 )
V_87 += sizeof( T_3 ) ;
if ( type & V_20 )
V_87 += sizeof( T_3 ) ;
if ( type & V_19 )
V_87 += sizeof( T_3 ) ;
if ( type & V_44 )
V_87 += sizeof( T_3 ) ;
if ( type & V_350 ) {
V_87 += sizeof( T_3 ) ;
if ( V_30 & V_201 )
V_87 += sizeof( T_3 ) ;
if ( V_30 & V_202 )
V_87 += sizeof( T_3 ) ;
if ( V_30 & V_164 ) {
V_342 = V_327 -> V_351 . V_352 . V_295 *
sizeof( struct V_358 ) ;
V_87 += V_342 ;
} else {
V_87 += sizeof( T_3 ) ;
}
}
if ( type & V_360 ) {
V_342 = ( V_327 -> V_150 -> V_295 + 1 ) * sizeof( T_3 ) ;
V_87 += V_342 ;
}
if ( type & V_43 ) {
V_87 += sizeof( T_7 ) ;
V_87 += V_327 -> V_363 ;
}
if ( type & V_365 ) {
V_342 = V_327 -> V_112 -> V_295 * sizeof( struct V_367 ) ;
V_342 += sizeof( T_3 ) ;
V_87 += V_342 ;
}
if ( type & V_368 ) {
if ( V_327 -> V_369 . V_370 ) {
V_87 += sizeof( T_3 ) ;
V_342 = F_128 ( V_327 -> V_369 . V_9 ) * sizeof( T_3 ) ;
V_87 += V_342 ;
} else {
V_87 += sizeof( T_3 ) ;
}
}
if ( type & V_372 ) {
V_342 = V_327 -> V_373 . V_6 ;
V_87 += sizeof( T_3 ) ;
if ( V_342 ) {
V_87 += V_342 ;
V_87 += sizeof( T_3 ) ;
}
}
if ( type & V_374 )
V_87 += sizeof( T_3 ) ;
if ( type & V_377 )
V_87 += sizeof( T_3 ) ;
if ( type & V_379 )
V_87 += sizeof( T_3 ) ;
if ( type & V_382 ) {
if ( V_327 -> V_380 . V_370 ) {
V_87 += sizeof( T_3 ) ;
V_342 = F_128 ( V_327 -> V_380 . V_9 ) * sizeof( T_3 ) ;
V_87 += V_342 ;
} else {
V_87 += sizeof( T_3 ) ;
}
}
return V_87 ;
}
int F_130 ( union V_324 * V_325 , T_3 type ,
T_3 V_30 ,
const struct V_326 * V_327 ,
bool V_329 )
{
T_3 * V_328 ;
T_2 V_342 ;
union V_331 V_332 ;
V_328 = V_325 -> V_327 . V_328 ;
if ( type & V_13 ) {
* V_328 = V_327 -> V_59 ;
V_328 ++ ;
}
if ( type & V_15 ) {
* V_328 = V_327 -> V_349 ;
V_328 ++ ;
}
if ( type & V_16 ) {
V_332 . V_335 [ 0 ] = V_327 -> V_290 ;
V_332 . V_335 [ 1 ] = V_327 -> V_337 ;
if ( V_329 ) {
V_332 . V_335 [ 0 ] = F_122 ( V_332 . V_335 [ 0 ] ) ;
V_332 . V_335 [ 1 ] = F_122 ( V_332 . V_335 [ 1 ] ) ;
V_332 . V_334 = F_121 ( V_332 . V_334 ) ;
}
* V_328 = V_332 . V_334 ;
V_328 ++ ;
}
if ( type & V_17 ) {
* V_328 = V_327 -> time ;
V_328 ++ ;
}
if ( type & V_18 ) {
* V_328 = V_327 -> V_78 ;
V_328 ++ ;
}
if ( type & V_14 ) {
* V_328 = V_327 -> V_59 ;
V_328 ++ ;
}
if ( type & V_20 ) {
* V_328 = V_327 -> V_336 ;
V_328 ++ ;
}
if ( type & V_19 ) {
V_332 . V_335 [ 0 ] = V_327 -> V_214 ;
if ( V_329 ) {
V_332 . V_335 [ 0 ] = F_122 ( V_332 . V_335 [ 0 ] ) ;
V_332 . V_334 = F_121 ( V_332 . V_334 ) ;
}
* V_328 = V_332 . V_334 ;
V_328 ++ ;
}
if ( type & V_44 ) {
* V_328 = V_327 -> V_133 ;
V_328 ++ ;
}
if ( type & V_350 ) {
if ( V_30 & V_164 )
* V_328 = V_327 -> V_351 . V_352 . V_295 ;
else
* V_328 = V_327 -> V_351 . V_353 . V_245 ;
V_328 ++ ;
if ( V_30 & V_201 ) {
* V_328 = V_327 -> V_351 . V_354 ;
V_328 ++ ;
}
if ( V_30 & V_202 ) {
* V_328 = V_327 -> V_351 . V_355 ;
V_328 ++ ;
}
if ( V_30 & V_164 ) {
V_342 = V_327 -> V_351 . V_352 . V_295 *
sizeof( struct V_358 ) ;
memcpy ( V_328 , V_327 -> V_351 . V_352 . V_359 , V_342 ) ;
V_328 = ( void * ) V_328 + V_342 ;
} else {
* V_328 = V_327 -> V_351 . V_353 . V_59 ;
V_328 ++ ;
}
}
if ( type & V_360 ) {
V_342 = ( V_327 -> V_150 -> V_295 + 1 ) * sizeof( T_3 ) ;
memcpy ( V_328 , V_327 -> V_150 , V_342 ) ;
V_328 = ( void * ) V_328 + V_342 ;
}
if ( type & V_43 ) {
V_332 . V_335 [ 0 ] = V_327 -> V_363 ;
if ( F_127 ( V_329 ,
L_52 ) ) {
V_332 . V_335 [ 0 ] = F_122 ( V_332 . V_335 [ 0 ] ) ;
V_332 . V_335 [ 1 ] = F_122 ( V_332 . V_335 [ 1 ] ) ;
V_332 . V_334 = F_121 ( V_332 . V_334 ) ;
}
* V_328 = V_332 . V_334 ;
V_328 = ( void * ) V_328 + sizeof( T_7 ) ;
memcpy ( V_328 , V_327 -> V_364 , V_327 -> V_363 ) ;
V_328 = ( void * ) V_328 + V_327 -> V_363 ;
}
if ( type & V_365 ) {
V_342 = V_327 -> V_112 -> V_295 * sizeof( struct V_367 ) ;
V_342 += sizeof( T_3 ) ;
memcpy ( V_328 , V_327 -> V_112 , V_342 ) ;
V_328 = ( void * ) V_328 + V_342 ;
}
if ( type & V_368 ) {
if ( V_327 -> V_369 . V_370 ) {
* V_328 ++ = V_327 -> V_369 . V_370 ;
V_342 = F_128 ( V_327 -> V_369 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_328 , V_327 -> V_369 . V_371 , V_342 ) ;
V_328 = ( void * ) V_328 + V_342 ;
} else {
* V_328 ++ = 0 ;
}
}
if ( type & V_372 ) {
V_342 = V_327 -> V_373 . V_6 ;
* V_328 ++ = V_342 ;
if ( V_342 ) {
memcpy ( V_328 , V_327 -> V_373 . V_341 , V_342 ) ;
V_328 = ( void * ) V_328 + V_342 ;
* V_328 ++ = V_342 ;
}
}
if ( type & V_374 ) {
* V_328 = V_327 -> V_343 ;
V_328 ++ ;
}
if ( type & V_377 ) {
* V_328 = V_327 -> V_375 ;
V_328 ++ ;
}
if ( type & V_379 ) {
* V_328 = V_327 -> V_378 ;
V_328 ++ ;
}
if ( type & V_382 ) {
if ( V_327 -> V_380 . V_370 ) {
* V_328 ++ = V_327 -> V_380 . V_370 ;
V_342 = F_128 ( V_327 -> V_380 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_328 , V_327 -> V_380 . V_371 , V_342 ) ;
V_328 = ( void * ) V_328 + V_342 ;
} else {
* V_328 ++ = 0 ;
}
}
return 0 ;
}
struct V_384 * F_131 ( struct V_1 * T_1 , const char * V_32 )
{
return F_132 ( T_1 -> V_58 , V_32 ) ;
}
void * F_133 ( struct V_1 * T_1 , struct V_326 * V_327 ,
const char * V_32 )
{
struct V_384 * V_385 = F_131 ( T_1 , V_32 ) ;
int V_340 ;
if ( ! V_385 )
return NULL ;
V_340 = V_385 -> V_340 ;
if ( V_385 -> V_288 & V_386 ) {
V_340 = * ( int * ) ( V_327 -> V_364 + V_385 -> V_340 ) ;
V_340 &= 0xffff ;
}
return V_327 -> V_364 + V_340 ;
}
T_3 F_134 ( struct V_384 * V_385 , struct V_326 * V_327 ,
bool V_330 )
{
T_3 V_245 ;
void * V_387 = V_327 -> V_364 + V_385 -> V_340 ;
switch ( V_385 -> V_6 ) {
case 1 :
return * ( T_6 * ) V_387 ;
case 2 :
V_245 = * ( T_12 * ) V_387 ;
break;
case 4 :
V_245 = * ( T_7 * ) V_387 ;
break;
case 8 :
memcpy ( & V_245 , V_387 , sizeof( T_3 ) ) ;
break;
default:
return 0 ;
}
if ( ! V_330 )
return V_245 ;
switch ( V_385 -> V_6 ) {
case 2 :
return F_135 ( V_245 ) ;
case 4 :
return F_122 ( V_245 ) ;
case 8 :
return F_121 ( V_245 ) ;
default:
return 0 ;
}
return 0 ;
}
T_3 F_136 ( struct V_1 * T_1 , struct V_326 * V_327 ,
const char * V_32 )
{
struct V_384 * V_385 = F_131 ( T_1 , V_32 ) ;
if ( ! V_385 )
return 0 ;
return V_385 ? F_134 ( V_385 , V_327 , T_1 -> V_330 ) : 0 ;
}
bool F_137 ( struct V_1 * T_1 , int V_53 ,
char * V_388 , T_2 V_389 )
{
int V_390 ;
if ( ( V_53 == V_391 || V_53 == V_392 || V_53 == V_393 ) &&
T_1 -> V_22 . type == V_46 &&
T_1 -> V_22 . V_47 == V_48 ) {
F_37 ( V_388 , V_389 , L_8 ,
L_54 ) ;
T_1 -> V_22 . type = V_97 ;
T_1 -> V_22 . V_47 = V_394 ;
F_32 ( & T_1 -> V_32 ) ;
return true ;
} else if ( V_53 == V_395 && ! T_1 -> V_22 . V_66 &&
( V_390 = F_138 () ) > 1 ) {
const char * V_32 = F_49 ( T_1 ) ;
char * V_396 ;
if ( F_26 ( & V_396 , L_55 , V_32 , strchr ( V_32 , ':' ) ? L_1 : L_11 ) < 0 )
return false ;
if ( T_1 -> V_32 )
free ( T_1 -> V_32 ) ;
T_1 -> V_32 = V_396 ;
F_37 ( V_388 , V_389 ,
L_56 , V_390 ) ;
T_1 -> V_22 . V_66 = 1 ;
return true ;
}
return false ;
}
int F_139 ( struct V_1 * T_1 , struct V_153 * V_153 ,
int V_53 , char * V_388 , T_2 V_6 )
{
char V_397 [ V_398 ] ;
switch ( V_53 ) {
case V_399 :
case V_395 :
return F_37 ( V_388 , V_6 ,
L_57
L_58
L_59
L_60
L_61
L_62
L_63
L_64
L_65 ,
V_153 -> V_216 ? L_66 : L_1 ,
F_138 () ) ;
case V_391 :
return F_37 ( V_388 , V_6 , L_67 ,
F_49 ( T_1 ) ) ;
case V_315 :
return F_37 ( V_388 , V_6 , L_8 ,
L_68
L_69
L_70
L_71 ) ;
case V_54 :
if ( ( T_1 -> V_22 . V_8 & V_360 ) != 0 &&
F_140 ( L_72 , V_400 ) == 0 )
return F_37 ( V_388 , V_6 ,
L_73
L_74
L_75 , V_401 ) ;
break;
case V_393 :
if ( V_153 -> V_402 )
return F_37 ( V_388 , V_6 , L_8 ,
L_76 ) ;
break;
case V_403 :
if ( T_1 -> V_22 . V_45 != 0 )
return F_37 ( V_388 , V_6 , L_8 ,
L_77 ) ;
if ( T_1 -> V_22 . V_50 )
return F_37 ( V_388 , V_6 , L_8 ,
L_78 ) ;
#if F_141 ( V_404 ) || F_141 ( V_405 )
if ( T_1 -> V_22 . type == V_46 )
return F_37 ( V_388 , V_6 , L_8 ,
L_79
L_80 ) ;
#endif
break;
case V_406 :
if ( F_142 ( L_81 ) )
return F_37 ( V_388 , V_6 ,
L_82
L_83 ) ;
break;
case V_7 :
if ( T_1 -> V_22 . V_146 && V_157 . V_146 )
return F_37 ( V_388 , V_6 , L_84 ) ;
if ( V_157 . V_207 )
return F_37 ( V_388 , V_6 , L_85 ) ;
if ( V_157 . V_298 )
return F_37 ( V_388 , V_6 , L_86 , V_207 ) ;
break;
default:
break;
}
return F_37 ( V_388 , V_6 ,
L_87
L_88
L_89 ,
V_53 , F_143 ( V_53 , V_397 , sizeof( V_397 ) ) ,
F_49 ( T_1 ) ) ;
}
char * F_144 ( struct V_1 * T_1 )
{
if ( T_1 && T_1 -> V_38 && T_1 -> V_38 -> V_407 )
return T_1 -> V_38 -> V_407 -> V_408 ;
return NULL ;
}
