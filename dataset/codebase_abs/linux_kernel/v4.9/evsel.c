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
if ( T_1 -> V_214 )
V_213 = 1 ;
T_1 -> V_215 = F_68 ( V_212 , V_213 , sizeof( int ) ) ;
if ( T_1 -> V_215 ) {
int V_216 , V_217 ;
for ( V_216 = 0 ; V_216 < V_212 ; V_216 ++ ) {
for ( V_217 = 0 ; V_217 < V_213 ; V_217 ++ ) {
F_69 ( T_1 , V_216 , V_217 ) = - 1 ;
}
}
}
return T_1 -> V_215 != NULL ? 0 : - V_54 ;
}
static int F_70 ( struct V_1 * T_1 , int V_212 , int V_213 ,
int V_218 , void * V_219 )
{
int V_216 , V_217 ;
if ( T_1 -> V_214 )
V_213 = 1 ;
for ( V_216 = 0 ; V_216 < V_212 ; V_216 ++ ) {
for ( V_217 = 0 ; V_217 < V_213 ; V_217 ++ ) {
int V_215 = F_69 ( T_1 , V_216 , V_217 ) ,
V_53 = F_71 ( V_215 , V_218 , V_219 ) ;
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
static int F_74 ( struct V_1 * T_1 ,
const char * V_223 , const char * V_220 )
{
char * V_222 ;
if ( T_1 -> V_220 == NULL )
return F_73 ( T_1 , V_220 ) ;
if ( F_26 ( & V_222 , V_223 , T_1 -> V_220 , V_220 ) > 0 ) {
free ( T_1 -> V_220 ) ;
T_1 -> V_220 = V_222 ;
return 0 ;
}
return - 1 ;
}
int F_75 ( struct V_1 * T_1 , const char * V_220 )
{
return F_74 ( T_1 , L_40 , V_220 ) ;
}
int F_76 ( struct V_1 * T_1 , const char * V_220 )
{
return F_74 ( T_1 , L_41 , V_220 ) ;
}
int F_77 ( struct V_1 * T_1 )
{
int V_213 = F_78 ( T_1 -> V_224 ) ;
int V_212 = F_79 ( T_1 -> V_225 ) ;
return F_70 ( T_1 , V_212 , V_213 ,
V_226 ,
0 ) ;
}
int F_80 ( struct V_1 * T_1 )
{
int V_213 = F_78 ( T_1 -> V_224 ) ;
int V_212 = F_79 ( T_1 -> V_225 ) ;
return F_70 ( T_1 , V_212 , V_213 ,
V_227 ,
0 ) ;
}
int F_81 ( struct V_1 * T_1 , int V_212 , int V_213 )
{
if ( V_212 == 0 || V_213 == 0 )
return 0 ;
if ( T_1 -> V_214 )
V_213 = 1 ;
T_1 -> V_228 = F_68 ( V_212 , V_213 , sizeof( struct V_229 ) ) ;
if ( T_1 -> V_228 == NULL )
return - V_54 ;
T_1 -> V_59 = F_20 ( V_212 * V_213 * sizeof( T_3 ) ) ;
if ( T_1 -> V_59 == NULL ) {
F_82 ( T_1 -> V_228 ) ;
T_1 -> V_228 = NULL ;
return - V_54 ;
}
return 0 ;
}
static void F_83 ( struct V_1 * T_1 )
{
F_82 ( T_1 -> V_215 ) ;
T_1 -> V_215 = NULL ;
}
static void F_84 ( struct V_1 * T_1 )
{
F_82 ( T_1 -> V_228 ) ;
T_1 -> V_228 = NULL ;
F_32 ( & T_1 -> V_59 ) ;
}
static void F_85 ( struct V_1 * T_1 )
{
struct V_127 * V_128 , * V_230 ;
F_86 (term, h, &evsel->config_terms, list) {
F_87 ( & V_128 -> V_231 ) ;
free ( V_128 ) ;
}
}
void F_88 ( struct V_1 * T_1 , int V_212 , int V_213 )
{
int V_216 , V_217 ;
if ( T_1 -> V_214 )
V_213 = 1 ;
for ( V_216 = 0 ; V_216 < V_212 ; V_216 ++ )
for ( V_217 = 0 ; V_217 < V_213 ; ++ V_217 ) {
F_89 ( F_69 ( T_1 , V_216 , V_217 ) ) ;
F_69 ( T_1 , V_216 , V_217 ) = - 1 ;
}
}
void F_90 ( struct V_1 * T_1 )
{
assert ( F_91 ( & T_1 -> V_40 ) ) ;
assert ( T_1 -> V_38 == NULL ) ;
F_83 ( T_1 ) ;
F_84 ( T_1 ) ;
F_85 ( T_1 ) ;
F_92 ( T_1 -> V_232 ) ;
F_93 ( T_1 -> V_225 ) ;
F_93 ( T_1 -> V_233 ) ;
F_94 ( T_1 -> V_224 ) ;
F_32 ( & T_1 -> V_99 ) ;
F_32 ( & T_1 -> V_32 ) ;
V_5 . F_5 ( T_1 ) ;
}
void F_27 ( struct V_1 * T_1 )
{
F_90 ( T_1 ) ;
free ( T_1 ) ;
}
void F_95 ( struct V_1 * T_1 , int V_216 , int V_217 ,
struct V_234 * V_235 )
{
struct V_234 V_236 ;
if ( ! T_1 -> V_237 )
return;
if ( V_216 == - 1 ) {
V_236 = T_1 -> V_237 -> V_238 ;
T_1 -> V_237 -> V_238 = * V_235 ;
} else {
V_236 = * F_96 ( T_1 -> V_237 , V_216 , V_217 ) ;
* F_96 ( T_1 -> V_237 , V_216 , V_217 ) = * V_235 ;
}
V_235 -> V_132 = V_235 -> V_132 - V_236 . V_132 ;
V_235 -> V_239 = V_235 -> V_239 - V_236 . V_239 ;
V_235 -> V_240 = V_235 -> V_240 - V_236 . V_240 ;
}
void F_97 ( struct V_234 * V_235 ,
bool V_37 , T_8 * V_241 )
{
T_8 V_242 = 0 ;
if ( V_37 ) {
if ( V_235 -> V_240 == 0 ) {
V_242 = - 1 ;
V_235 -> V_132 = 0 ;
} else if ( V_235 -> V_240 < V_235 -> V_239 ) {
V_242 = 1 ;
V_235 -> V_132 = ( T_3 ) ( ( double ) V_235 -> V_132 * V_235 -> V_239 / V_235 -> V_240 + 0.5 ) ;
}
} else
V_235 -> V_239 = V_235 -> V_240 = 0 ;
if ( V_241 )
* V_241 = V_242 ;
}
int F_98 ( struct V_1 * T_1 , int V_216 , int V_217 ,
struct V_234 * V_235 )
{
memset ( V_235 , 0 , sizeof( * V_235 ) ) ;
if ( F_69 ( T_1 , V_216 , V_217 ) < 0 )
return - V_7 ;
if ( F_99 ( F_69 ( T_1 , V_216 , V_217 ) , V_235 , sizeof( * V_235 ) ) < 0 )
return - V_243 ;
return 0 ;
}
int F_100 ( struct V_1 * T_1 ,
int V_216 , int V_217 , bool V_37 )
{
struct V_234 V_235 ;
T_2 V_244 = V_37 ? 3 : 1 ;
if ( F_69 ( T_1 , V_216 , V_217 ) < 0 )
return - V_7 ;
if ( T_1 -> V_245 == NULL && F_101 ( T_1 , V_216 + 1 , V_217 + 1 ) < 0 )
return - V_54 ;
if ( F_99 ( F_69 ( T_1 , V_216 , V_217 ) , & V_235 , V_244 * sizeof( T_3 ) ) < 0 )
return - V_243 ;
F_95 ( T_1 , V_216 , V_217 , & V_235 ) ;
F_97 ( & V_235 , V_37 , NULL ) ;
* F_96 ( T_1 -> V_245 , V_216 , V_217 ) = V_235 ;
return 0 ;
}
static int F_102 ( struct V_1 * T_1 , int V_216 , int V_217 )
{
struct V_1 * V_35 = T_1 -> V_35 ;
int V_215 ;
if ( F_65 ( T_1 ) )
return - 1 ;
F_103 ( ! V_35 -> V_215 ) ;
V_215 = F_69 ( V_35 , V_216 , V_217 ) ;
F_103 ( V_215 == - 1 ) ;
return V_215 ;
}
static void F_104 ( char * V_100 , T_2 V_6 , T_3 V_246 , struct V_247 * V_248 )
{
bool V_249 = true ;
int V_11 = 0 ;
do {
if ( V_246 & V_248 [ V_11 ] . V_25 ) {
V_100 += F_37 ( V_100 , V_6 , L_42 , V_249 ? L_1 : L_43 , V_248 [ V_11 ] . V_32 ) ;
V_249 = false ;
}
} while ( V_248 [ ++ V_11 ] . V_32 != NULL );
}
static void F_105 ( char * V_100 , T_2 V_6 , T_3 V_246 )
{
#define F_106 ( T_9 ) { PERF_SAMPLE_##n, #n }
struct V_247 V_248 [] = {
F_106 ( V_159 ) , F_106 ( V_160 ) , F_106 ( TIME ) , F_106 ( V_174 ) ,
F_106 ( V_162 ) , F_106 ( V_107 ) , F_106 ( V_28 ) , F_106 ( V_181 ) ,
F_106 ( V_169 ) , F_106 ( V_250 ) , F_106 ( V_185 ) ,
F_106 ( V_113 ) , F_106 ( V_120 ) , F_106 ( V_121 ) ,
F_106 ( V_29 ) , F_106 ( V_179 ) , F_106 ( V_186 ) ,
F_106 ( V_191 ) ,
{ . V_32 = NULL , }
} ;
#undef F_106
F_104 ( V_100 , V_6 , V_246 , V_248 ) ;
}
static void F_107 ( char * V_100 , T_2 V_6 , T_3 V_246 )
{
#define F_106 ( T_9 ) { PERF_SAMPLE_BRANCH_##n, #n }
struct V_247 V_248 [] = {
F_106 ( V_251 ) , F_106 ( V_252 ) , F_106 ( V_253 ) , F_106 ( V_254 ) ,
F_106 ( V_255 ) , F_106 ( V_256 ) , F_106 ( V_257 ) ,
F_106 ( V_258 ) , F_106 ( V_259 ) , F_106 ( V_260 ) ,
F_106 ( V_261 ) , F_106 ( V_262 ) , F_106 ( V_263 ) ,
F_106 ( V_264 ) , F_106 ( V_265 ) , F_106 ( V_266 ) ,
{ . V_32 = NULL , }
} ;
#undef F_106
F_104 ( V_100 , V_6 , V_246 , V_248 ) ;
}
static void F_108 ( char * V_100 , T_2 V_6 , T_3 V_246 )
{
#define F_106 ( T_9 ) { PERF_FORMAT_##n, #n }
struct V_247 V_248 [] = {
F_106 ( V_267 ) , F_106 ( V_268 ) ,
F_106 ( V_28 ) , F_106 ( V_269 ) ,
{ . V_32 = NULL , }
} ;
#undef F_106
F_104 ( V_100 , V_6 , V_246 , V_248 ) ;
}
int F_109 ( T_10 * V_270 , struct V_33 * V_22 ,
T_11 V_271 , void * V_272 )
{
char V_100 [ V_273 ] ;
int V_94 = 0 ;
F_110 ( type , V_274 ) ;
F_110 ( V_6 , V_274 ) ;
F_110 ( V_47 , V_275 ) ;
F_111 ( L_44 , V_45 , V_274 ) ;
F_110 ( V_8 , V_276 ) ;
F_110 ( V_30 , V_277 ) ;
F_110 ( V_203 , V_274 ) ;
F_110 ( V_144 , V_274 ) ;
F_110 ( V_278 , V_274 ) ;
F_110 ( V_279 , V_274 ) ;
F_110 ( V_67 , V_274 ) ;
F_110 ( V_66 , V_274 ) ;
F_110 ( V_68 , V_274 ) ;
F_110 ( V_280 , V_274 ) ;
F_110 ( V_193 , V_274 ) ;
F_110 ( V_195 , V_274 ) ;
F_110 ( V_134 , V_274 ) ;
F_110 ( V_172 , V_274 ) ;
F_110 ( V_205 , V_274 ) ;
F_110 ( V_192 , V_274 ) ;
F_110 ( V_188 , V_274 ) ;
F_110 ( V_50 , V_274 ) ;
F_110 ( V_175 , V_274 ) ;
F_110 ( V_156 , V_274 ) ;
F_110 ( V_72 , V_274 ) ;
F_110 ( V_73 , V_274 ) ;
F_110 ( V_281 , V_274 ) ;
F_110 ( V_126 , V_274 ) ;
F_110 ( V_194 , V_274 ) ;
F_110 ( V_282 , V_274 ) ;
F_110 ( V_208 , V_274 ) ;
F_110 ( V_197 , V_274 ) ;
F_110 ( V_146 , V_274 ) ;
F_111 ( L_45 , V_189 , V_274 ) ;
F_110 ( V_84 , V_274 ) ;
F_111 ( L_46 , V_83 , V_275 ) ;
F_111 ( L_47 , V_283 , V_275 ) ;
F_110 ( V_114 , V_284 ) ;
F_110 ( V_122 , V_275 ) ;
F_110 ( V_124 , V_274 ) ;
F_110 ( V_207 , V_285 ) ;
F_110 ( V_178 , V_275 ) ;
F_110 ( V_286 , V_274 ) ;
F_110 ( V_108 , V_274 ) ;
return V_94 ;
}
static int F_112 ( struct V_1 * T_1 , struct V_287 * V_225 ,
struct V_288 * V_224 )
{
int V_216 , V_217 , V_213 ;
unsigned long V_289 = V_290 ;
int V_291 = - 1 , V_53 ;
enum { V_292 , V_293 , V_294 } V_295 = V_292 ;
if ( V_157 . V_146 && T_1 -> V_22 . V_146 )
return - V_7 ;
if ( T_1 -> V_214 )
V_213 = 1 ;
else
V_213 = V_224 -> V_296 ;
if ( T_1 -> V_215 == NULL &&
F_67 ( T_1 , V_225 -> V_296 , V_213 ) < 0 )
return - V_54 ;
if ( T_1 -> V_232 ) {
V_289 |= V_297 ;
V_291 = T_1 -> V_232 -> V_215 ;
}
V_298:
if ( V_157 . V_299 )
T_1 -> V_22 . V_207 = V_300 ;
if ( V_157 . V_207 ) {
T_1 -> V_22 . V_208 = 0 ;
T_1 -> V_22 . V_207 = 0 ;
}
if ( V_157 . V_301 )
V_289 &= ~ ( unsigned long ) V_290 ;
if ( V_157 . V_194 )
T_1 -> V_22 . V_194 = 0 ;
if ( V_157 . V_73 )
T_1 -> V_22 . V_73 = T_1 -> V_22 . V_72 = 0 ;
if ( V_157 . V_302 )
T_1 -> V_22 . V_114 &= ~ ( V_118 |
V_117 ) ;
V_303:
if ( V_157 . V_156 )
T_1 -> V_22 . V_156 = 0 ;
if ( V_304 >= 2 ) {
fprintf ( V_305 , L_48 , V_306 ) ;
fprintf ( V_305 , L_49 ) ;
F_109 ( V_305 , & T_1 -> V_22 , V_307 , NULL ) ;
fprintf ( V_305 , L_48 , V_306 ) ;
}
for ( V_216 = 0 ; V_216 < V_225 -> V_296 ; V_216 ++ ) {
for ( V_217 = 0 ; V_217 < V_213 ; V_217 ++ ) {
int V_308 ;
if ( ! T_1 -> V_232 && ! T_1 -> V_214 )
V_291 = F_113 ( V_224 , V_217 ) ;
V_308 = F_102 ( T_1 , V_216 , V_217 ) ;
V_309:
F_114 ( L_50 ,
V_291 , V_225 -> V_310 [ V_216 ] , V_308 , V_289 ) ;
F_69 ( T_1 , V_216 , V_217 ) = F_115 ( & T_1 -> V_22 ,
V_291 ,
V_225 -> V_310 [ V_216 ] ,
V_308 , V_289 ) ;
if ( F_69 ( T_1 , V_216 , V_217 ) < 0 ) {
V_53 = - V_243 ;
F_114 ( L_51 ,
V_53 ) ;
goto V_311;
}
if ( T_1 -> V_39 >= 0 ) {
int V_312 = F_69 ( T_1 , V_216 , V_217 ) ;
int V_39 = T_1 -> V_39 ;
V_53 = F_71 ( V_312 ,
V_313 ,
V_39 ) ;
if ( V_53 && V_243 != V_314 ) {
F_61 ( L_52 ,
V_39 , strerror ( V_243 ) ) ;
V_53 = - V_7 ;
goto V_315;
}
}
V_295 = V_292 ;
if ( V_157 . V_207 ||
V_157 . V_299 ) {
V_53 = - V_7 ;
goto V_315;
}
}
}
return 0 ;
V_311:
if ( V_53 == - V_316 && V_295 < V_294 ) {
struct V_317 V_318 ;
int V_319 = V_243 ;
if ( F_116 ( V_320 , & V_318 ) == 0 ) {
if ( V_295 == V_292 )
V_318 . V_321 = V_318 . V_322 ;
else {
V_318 . V_321 = V_318 . V_322 + 1000 ;
V_318 . V_322 = V_318 . V_321 ;
}
if ( F_117 ( V_320 , & V_318 ) == 0 ) {
V_295 ++ ;
V_243 = V_319 ;
goto V_309;
}
}
V_243 = V_319 ;
}
if ( V_53 != - V_7 || V_216 > 0 || V_217 > 0 )
goto V_315;
if ( ! V_157 . V_146 && T_1 -> V_22 . V_146 ) {
V_157 . V_146 = true ;
goto V_315;
} else if ( ! V_157 . V_299 && T_1 -> V_22 . V_208 ) {
V_157 . V_299 = true ;
goto V_298;
} else if ( ! V_157 . V_207 && T_1 -> V_22 . V_208 ) {
V_157 . V_207 = true ;
goto V_298;
} else if ( ! V_157 . V_301 && ( V_289 & V_290 ) ) {
V_157 . V_301 = true ;
goto V_298;
} else if ( ! V_157 . V_194 && T_1 -> V_22 . V_194 ) {
V_157 . V_194 = true ;
goto V_298;
} else if ( ! V_157 . V_73 &&
( T_1 -> V_22 . V_73 || T_1 -> V_22 . V_72 ) ) {
V_157 . V_73 = true ;
goto V_298;
} else if ( ! V_157 . V_156 ) {
V_157 . V_156 = true ;
goto V_303;
} else if ( ! V_157 . V_302 &&
( T_1 -> V_22 . V_114 &
( V_117 |
V_118 ) ) ) {
V_157 . V_302 = true ;
goto V_298;
}
V_315:
do {
while ( -- V_217 >= 0 ) {
F_89 ( F_69 ( T_1 , V_216 , V_217 ) ) ;
F_69 ( T_1 , V_216 , V_217 ) = - 1 ;
}
V_217 = V_213 ;
} while ( -- V_216 >= 0 );
return V_53 ;
}
void F_118 ( struct V_1 * T_1 , int V_212 , int V_213 )
{
if ( T_1 -> V_215 == NULL )
return;
F_88 ( T_1 , V_212 , V_213 ) ;
F_83 ( T_1 ) ;
}
int F_119 ( struct V_1 * T_1 , struct V_287 * V_225 ,
struct V_288 * V_224 )
{
if ( V_225 == NULL ) {
V_225 = & V_323 . V_310 ;
}
if ( V_224 == NULL )
V_224 = & V_324 . V_310 ;
return F_112 ( T_1 , V_225 , V_224 ) ;
}
int F_120 ( struct V_1 * T_1 ,
struct V_287 * V_225 )
{
return F_112 ( T_1 , V_225 , & V_324 . V_310 ) ;
}
int F_121 ( struct V_1 * T_1 ,
struct V_288 * V_224 )
{
return F_112 ( T_1 , & V_323 . V_310 , V_224 ) ;
}
static int F_122 ( const struct V_1 * T_1 ,
const union V_325 * V_326 ,
struct V_327 * V_328 )
{
T_3 type = T_1 -> V_22 . V_8 ;
const T_3 * V_329 = V_326 -> V_328 . V_329 ;
bool V_330 = T_1 -> V_331 ;
union V_332 V_333 ;
V_329 += ( ( V_326 -> V_334 . V_6 -
sizeof( V_326 -> V_334 ) ) / sizeof( T_3 ) ) - 1 ;
if ( type & V_13 ) {
V_328 -> V_59 = * V_329 ;
V_329 -- ;
}
if ( type & V_19 ) {
V_333 . V_335 = * V_329 ;
if ( V_330 ) {
V_333 . V_335 = F_123 ( V_333 . V_335 ) ;
V_333 . V_336 [ 0 ] = F_124 ( V_333 . V_336 [ 0 ] ) ;
}
V_328 -> V_216 = V_333 . V_336 [ 0 ] ;
V_329 -- ;
}
if ( type & V_20 ) {
V_328 -> V_337 = * V_329 ;
V_329 -- ;
}
if ( type & V_14 ) {
V_328 -> V_59 = * V_329 ;
V_329 -- ;
}
if ( type & V_17 ) {
V_328 -> time = * V_329 ;
V_329 -- ;
}
if ( type & V_16 ) {
V_333 . V_335 = * V_329 ;
if ( V_330 ) {
V_333 . V_335 = F_123 ( V_333 . V_335 ) ;
V_333 . V_336 [ 0 ] = F_124 ( V_333 . V_336 [ 0 ] ) ;
V_333 . V_336 [ 1 ] = F_124 ( V_333 . V_336 [ 1 ] ) ;
}
V_328 -> V_291 = V_333 . V_336 [ 0 ] ;
V_328 -> V_338 = V_333 . V_336 [ 1 ] ;
V_329 -- ;
}
return 0 ;
}
static inline bool F_125 ( const void * V_339 , T_12 V_340 , const void * V_341 ,
T_3 V_6 )
{
return V_6 > V_340 || V_341 + V_6 > V_339 ;
}
int F_126 ( struct V_1 * T_1 , union V_325 * V_326 ,
struct V_327 * V_342 )
{
T_3 type = T_1 -> V_22 . V_8 ;
bool V_330 = T_1 -> V_331 ;
const T_3 * V_329 ;
T_12 V_340 = V_326 -> V_334 . V_6 ;
const void * V_339 = ( void * ) V_326 + V_340 ;
T_3 V_343 ;
union V_332 V_333 ;
memset ( V_342 , 0 , sizeof( * V_342 ) ) ;
V_342 -> V_216 = V_342 -> V_291 = V_342 -> V_338 = - 1 ;
V_342 -> V_337 = V_342 -> V_59 = V_342 -> time = - 1ULL ;
V_342 -> V_133 = T_1 -> V_22 . V_45 ;
V_342 -> V_344 = V_326 -> V_334 . V_345 & V_346 ;
if ( V_326 -> V_334 . type != V_347 ) {
if ( ! T_1 -> V_22 . V_156 )
return 0 ;
return F_122 ( T_1 , V_326 , V_342 ) ;
}
V_329 = V_326 -> V_328 . V_329 ;
if ( T_1 -> V_26 + sizeof( V_326 -> V_334 ) > V_326 -> V_334 . V_6 )
return - V_348 ;
V_342 -> V_59 = - 1ULL ;
if ( type & V_13 ) {
V_342 -> V_59 = * V_329 ;
V_329 ++ ;
}
if ( type & V_15 ) {
V_342 -> V_349 = * V_329 ;
V_329 ++ ;
}
if ( type & V_16 ) {
V_333 . V_335 = * V_329 ;
if ( V_330 ) {
V_333 . V_335 = F_123 ( V_333 . V_335 ) ;
V_333 . V_336 [ 0 ] = F_124 ( V_333 . V_336 [ 0 ] ) ;
V_333 . V_336 [ 1 ] = F_124 ( V_333 . V_336 [ 1 ] ) ;
}
V_342 -> V_291 = V_333 . V_336 [ 0 ] ;
V_342 -> V_338 = V_333 . V_336 [ 1 ] ;
V_329 ++ ;
}
if ( type & V_17 ) {
V_342 -> time = * V_329 ;
V_329 ++ ;
}
V_342 -> V_78 = 0 ;
if ( type & V_18 ) {
V_342 -> V_78 = * V_329 ;
V_329 ++ ;
}
if ( type & V_14 ) {
V_342 -> V_59 = * V_329 ;
V_329 ++ ;
}
if ( type & V_20 ) {
V_342 -> V_337 = * V_329 ;
V_329 ++ ;
}
if ( type & V_19 ) {
V_333 . V_335 = * V_329 ;
if ( V_330 ) {
V_333 . V_335 = F_123 ( V_333 . V_335 ) ;
V_333 . V_336 [ 0 ] = F_124 ( V_333 . V_336 [ 0 ] ) ;
}
V_342 -> V_216 = V_333 . V_336 [ 0 ] ;
V_329 ++ ;
}
if ( type & V_44 ) {
V_342 -> V_133 = * V_329 ;
V_329 ++ ;
}
if ( type & V_350 ) {
T_3 V_30 = T_1 -> V_22 . V_30 ;
F_127 ( V_329 ) ;
if ( V_30 & V_164 )
V_342 -> V_351 . V_352 . V_296 = * V_329 ;
else
V_342 -> V_351 . V_353 . V_246 = * V_329 ;
V_329 ++ ;
if ( V_30 & V_201 ) {
F_127 ( V_329 ) ;
V_342 -> V_351 . V_354 = * V_329 ;
V_329 ++ ;
}
if ( V_30 & V_202 ) {
F_127 ( V_329 ) ;
V_342 -> V_351 . V_355 = * V_329 ;
V_329 ++ ;
}
if ( V_30 & V_164 ) {
const T_3 V_356 = V_357 /
sizeof( struct V_358 ) ;
if ( V_342 -> V_351 . V_352 . V_296 > V_356 )
return - V_348 ;
V_343 = V_342 -> V_351 . V_352 . V_296 *
sizeof( struct V_358 ) ;
F_128 ( V_329 , V_343 , V_340 ) ;
V_342 -> V_351 . V_352 . V_359 =
(struct V_358 * ) V_329 ;
V_329 = ( void * ) V_329 + V_343 ;
} else {
F_127 ( V_329 ) ;
V_342 -> V_351 . V_353 . V_59 = * V_329 ;
V_329 ++ ;
}
}
if ( type & V_360 ) {
const T_3 V_361 = V_357 / sizeof( T_3 ) ;
F_127 ( V_329 ) ;
V_342 -> V_150 = (struct V_362 * ) V_329 ++ ;
if ( V_342 -> V_150 -> V_296 > V_361 )
return - V_348 ;
V_343 = V_342 -> V_150 -> V_296 * sizeof( T_3 ) ;
F_128 ( V_329 , V_343 , V_340 ) ;
V_329 = ( void * ) V_329 + V_343 ;
}
if ( type & V_43 ) {
F_127 ( V_329 ) ;
V_333 . V_335 = * V_329 ;
if ( F_129 ( V_330 ,
L_53 ) ) {
V_333 . V_335 = F_123 ( V_333 . V_335 ) ;
V_333 . V_336 [ 0 ] = F_124 ( V_333 . V_336 [ 0 ] ) ;
V_333 . V_336 [ 1 ] = F_124 ( V_333 . V_336 [ 1 ] ) ;
}
V_342 -> V_363 = V_333 . V_336 [ 0 ] ;
V_329 = ( void * ) V_329 + sizeof( T_7 ) ;
F_128 ( V_329 , V_342 -> V_363 , V_340 ) ;
V_342 -> V_364 = ( void * ) V_329 ;
V_329 = ( void * ) V_329 + V_342 -> V_363 ;
}
if ( type & V_365 ) {
const T_3 V_366 = V_357 /
sizeof( struct V_367 ) ;
F_127 ( V_329 ) ;
V_342 -> V_112 = (struct V_112 * ) V_329 ++ ;
if ( V_342 -> V_112 -> V_296 > V_366 )
return - V_348 ;
V_343 = V_342 -> V_112 -> V_296 * sizeof( struct V_367 ) ;
F_128 ( V_329 , V_343 , V_340 ) ;
V_329 = ( void * ) V_329 + V_343 ;
}
if ( type & V_368 ) {
F_127 ( V_329 ) ;
V_342 -> V_369 . V_370 = * V_329 ;
V_329 ++ ;
if ( V_342 -> V_369 . V_370 ) {
T_3 V_9 = T_1 -> V_22 . V_122 ;
V_343 = F_130 ( V_9 ) * sizeof( T_3 ) ;
F_128 ( V_329 , V_343 , V_340 ) ;
V_342 -> V_369 . V_9 = V_9 ;
V_342 -> V_369 . V_371 = ( T_3 * ) V_329 ;
V_329 = ( void * ) V_329 + V_343 ;
}
}
if ( type & V_372 ) {
F_127 ( V_329 ) ;
V_343 = * V_329 ++ ;
V_342 -> V_373 . V_341 = ( ( char * ) ( V_329 - 1 )
- ( char * ) V_326 ) ;
if ( ! V_343 ) {
V_342 -> V_373 . V_6 = 0 ;
} else {
F_128 ( V_329 , V_343 , V_340 ) ;
V_342 -> V_373 . V_342 = ( char * ) V_329 ;
V_329 = ( void * ) V_329 + V_343 ;
F_127 ( V_329 ) ;
V_342 -> V_373 . V_6 = * V_329 ++ ;
if ( F_129 ( V_342 -> V_373 . V_6 > V_343 ,
L_54 ) )
return - V_348 ;
}
}
if ( type & V_374 ) {
F_127 ( V_329 ) ;
V_342 -> V_375 = * V_329 ;
V_329 ++ ;
}
V_342 -> V_376 = V_377 ;
if ( type & V_378 ) {
F_127 ( V_329 ) ;
V_342 -> V_376 = * V_329 ;
V_329 ++ ;
}
V_342 -> V_379 = 0 ;
if ( type & V_380 ) {
F_127 ( V_329 ) ;
V_342 -> V_379 = * V_329 ;
V_329 ++ ;
}
V_342 -> V_381 . V_370 = V_382 ;
if ( type & V_383 ) {
F_127 ( V_329 ) ;
V_342 -> V_381 . V_370 = * V_329 ;
V_329 ++ ;
if ( V_342 -> V_381 . V_370 != V_382 ) {
T_3 V_9 = T_1 -> V_22 . V_178 ;
V_343 = F_130 ( V_9 ) * sizeof( T_3 ) ;
F_128 ( V_329 , V_343 , V_340 ) ;
V_342 -> V_381 . V_9 = V_9 ;
V_342 -> V_381 . V_371 = ( T_3 * ) V_329 ;
V_329 = ( void * ) V_329 + V_343 ;
}
}
return 0 ;
}
T_2 F_131 ( const struct V_327 * V_328 , T_3 type ,
T_3 V_30 )
{
T_2 V_343 , V_87 = sizeof( struct V_384 ) ;
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
V_343 = V_328 -> V_351 . V_352 . V_296 *
sizeof( struct V_358 ) ;
V_87 += V_343 ;
} else {
V_87 += sizeof( T_3 ) ;
}
}
if ( type & V_360 ) {
V_343 = ( V_328 -> V_150 -> V_296 + 1 ) * sizeof( T_3 ) ;
V_87 += V_343 ;
}
if ( type & V_43 ) {
V_87 += sizeof( T_7 ) ;
V_87 += V_328 -> V_363 ;
}
if ( type & V_365 ) {
V_343 = V_328 -> V_112 -> V_296 * sizeof( struct V_367 ) ;
V_343 += sizeof( T_3 ) ;
V_87 += V_343 ;
}
if ( type & V_368 ) {
if ( V_328 -> V_369 . V_370 ) {
V_87 += sizeof( T_3 ) ;
V_343 = F_130 ( V_328 -> V_369 . V_9 ) * sizeof( T_3 ) ;
V_87 += V_343 ;
} else {
V_87 += sizeof( T_3 ) ;
}
}
if ( type & V_372 ) {
V_343 = V_328 -> V_373 . V_6 ;
V_87 += sizeof( T_3 ) ;
if ( V_343 ) {
V_87 += V_343 ;
V_87 += sizeof( T_3 ) ;
}
}
if ( type & V_374 )
V_87 += sizeof( T_3 ) ;
if ( type & V_378 )
V_87 += sizeof( T_3 ) ;
if ( type & V_380 )
V_87 += sizeof( T_3 ) ;
if ( type & V_383 ) {
if ( V_328 -> V_381 . V_370 ) {
V_87 += sizeof( T_3 ) ;
V_343 = F_130 ( V_328 -> V_381 . V_9 ) * sizeof( T_3 ) ;
V_87 += V_343 ;
} else {
V_87 += sizeof( T_3 ) ;
}
}
return V_87 ;
}
int F_132 ( union V_325 * V_326 , T_3 type ,
T_3 V_30 ,
const struct V_327 * V_328 ,
bool V_330 )
{
T_3 * V_329 ;
T_2 V_343 ;
union V_332 V_333 ;
V_329 = V_326 -> V_328 . V_329 ;
if ( type & V_13 ) {
* V_329 = V_328 -> V_59 ;
V_329 ++ ;
}
if ( type & V_15 ) {
* V_329 = V_328 -> V_349 ;
V_329 ++ ;
}
if ( type & V_16 ) {
V_333 . V_336 [ 0 ] = V_328 -> V_291 ;
V_333 . V_336 [ 1 ] = V_328 -> V_338 ;
if ( V_330 ) {
V_333 . V_336 [ 0 ] = F_124 ( V_333 . V_336 [ 0 ] ) ;
V_333 . V_336 [ 1 ] = F_124 ( V_333 . V_336 [ 1 ] ) ;
V_333 . V_335 = F_123 ( V_333 . V_335 ) ;
}
* V_329 = V_333 . V_335 ;
V_329 ++ ;
}
if ( type & V_17 ) {
* V_329 = V_328 -> time ;
V_329 ++ ;
}
if ( type & V_18 ) {
* V_329 = V_328 -> V_78 ;
V_329 ++ ;
}
if ( type & V_14 ) {
* V_329 = V_328 -> V_59 ;
V_329 ++ ;
}
if ( type & V_20 ) {
* V_329 = V_328 -> V_337 ;
V_329 ++ ;
}
if ( type & V_19 ) {
V_333 . V_336 [ 0 ] = V_328 -> V_216 ;
if ( V_330 ) {
V_333 . V_336 [ 0 ] = F_124 ( V_333 . V_336 [ 0 ] ) ;
V_333 . V_335 = F_123 ( V_333 . V_335 ) ;
}
* V_329 = V_333 . V_335 ;
V_329 ++ ;
}
if ( type & V_44 ) {
* V_329 = V_328 -> V_133 ;
V_329 ++ ;
}
if ( type & V_350 ) {
if ( V_30 & V_164 )
* V_329 = V_328 -> V_351 . V_352 . V_296 ;
else
* V_329 = V_328 -> V_351 . V_353 . V_246 ;
V_329 ++ ;
if ( V_30 & V_201 ) {
* V_329 = V_328 -> V_351 . V_354 ;
V_329 ++ ;
}
if ( V_30 & V_202 ) {
* V_329 = V_328 -> V_351 . V_355 ;
V_329 ++ ;
}
if ( V_30 & V_164 ) {
V_343 = V_328 -> V_351 . V_352 . V_296 *
sizeof( struct V_358 ) ;
memcpy ( V_329 , V_328 -> V_351 . V_352 . V_359 , V_343 ) ;
V_329 = ( void * ) V_329 + V_343 ;
} else {
* V_329 = V_328 -> V_351 . V_353 . V_59 ;
V_329 ++ ;
}
}
if ( type & V_360 ) {
V_343 = ( V_328 -> V_150 -> V_296 + 1 ) * sizeof( T_3 ) ;
memcpy ( V_329 , V_328 -> V_150 , V_343 ) ;
V_329 = ( void * ) V_329 + V_343 ;
}
if ( type & V_43 ) {
V_333 . V_336 [ 0 ] = V_328 -> V_363 ;
if ( F_129 ( V_330 ,
L_53 ) ) {
V_333 . V_336 [ 0 ] = F_124 ( V_333 . V_336 [ 0 ] ) ;
V_333 . V_336 [ 1 ] = F_124 ( V_333 . V_336 [ 1 ] ) ;
V_333 . V_335 = F_123 ( V_333 . V_335 ) ;
}
* V_329 = V_333 . V_335 ;
V_329 = ( void * ) V_329 + sizeof( T_7 ) ;
memcpy ( V_329 , V_328 -> V_364 , V_328 -> V_363 ) ;
V_329 = ( void * ) V_329 + V_328 -> V_363 ;
}
if ( type & V_365 ) {
V_343 = V_328 -> V_112 -> V_296 * sizeof( struct V_367 ) ;
V_343 += sizeof( T_3 ) ;
memcpy ( V_329 , V_328 -> V_112 , V_343 ) ;
V_329 = ( void * ) V_329 + V_343 ;
}
if ( type & V_368 ) {
if ( V_328 -> V_369 . V_370 ) {
* V_329 ++ = V_328 -> V_369 . V_370 ;
V_343 = F_130 ( V_328 -> V_369 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_329 , V_328 -> V_369 . V_371 , V_343 ) ;
V_329 = ( void * ) V_329 + V_343 ;
} else {
* V_329 ++ = 0 ;
}
}
if ( type & V_372 ) {
V_343 = V_328 -> V_373 . V_6 ;
* V_329 ++ = V_343 ;
if ( V_343 ) {
memcpy ( V_329 , V_328 -> V_373 . V_342 , V_343 ) ;
V_329 = ( void * ) V_329 + V_343 ;
* V_329 ++ = V_343 ;
}
}
if ( type & V_374 ) {
* V_329 = V_328 -> V_375 ;
V_329 ++ ;
}
if ( type & V_378 ) {
* V_329 = V_328 -> V_376 ;
V_329 ++ ;
}
if ( type & V_380 ) {
* V_329 = V_328 -> V_379 ;
V_329 ++ ;
}
if ( type & V_383 ) {
if ( V_328 -> V_381 . V_370 ) {
* V_329 ++ = V_328 -> V_381 . V_370 ;
V_343 = F_130 ( V_328 -> V_381 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_329 , V_328 -> V_381 . V_371 , V_343 ) ;
V_329 = ( void * ) V_329 + V_343 ;
} else {
* V_329 ++ = 0 ;
}
}
return 0 ;
}
struct V_385 * F_133 ( struct V_1 * T_1 , const char * V_32 )
{
return F_134 ( T_1 -> V_58 , V_32 ) ;
}
void * F_135 ( struct V_1 * T_1 , struct V_327 * V_328 ,
const char * V_32 )
{
struct V_385 * V_386 = F_133 ( T_1 , V_32 ) ;
int V_341 ;
if ( ! V_386 )
return NULL ;
V_341 = V_386 -> V_341 ;
if ( V_386 -> V_289 & V_387 ) {
V_341 = * ( int * ) ( V_328 -> V_364 + V_386 -> V_341 ) ;
V_341 &= 0xffff ;
}
return V_328 -> V_364 + V_341 ;
}
T_3 F_136 ( struct V_385 * V_386 , struct V_327 * V_328 ,
bool V_331 )
{
T_3 V_246 ;
void * V_388 = V_328 -> V_364 + V_386 -> V_341 ;
switch ( V_386 -> V_6 ) {
case 1 :
return * ( T_6 * ) V_388 ;
case 2 :
V_246 = * ( T_12 * ) V_388 ;
break;
case 4 :
V_246 = * ( T_7 * ) V_388 ;
break;
case 8 :
memcpy ( & V_246 , V_388 , sizeof( T_3 ) ) ;
break;
default:
return 0 ;
}
if ( ! V_331 )
return V_246 ;
switch ( V_386 -> V_6 ) {
case 2 :
return F_137 ( V_246 ) ;
case 4 :
return F_124 ( V_246 ) ;
case 8 :
return F_123 ( V_246 ) ;
default:
return 0 ;
}
return 0 ;
}
T_3 F_138 ( struct V_1 * T_1 , struct V_327 * V_328 ,
const char * V_32 )
{
struct V_385 * V_386 = F_133 ( T_1 , V_32 ) ;
if ( ! V_386 )
return 0 ;
return V_386 ? F_136 ( V_386 , V_328 , T_1 -> V_331 ) : 0 ;
}
bool F_139 ( struct V_1 * T_1 , int V_53 ,
char * V_389 , T_2 V_390 )
{
int V_391 ;
if ( ( V_53 == V_392 || V_53 == V_393 || V_53 == V_394 ) &&
T_1 -> V_22 . type == V_46 &&
T_1 -> V_22 . V_47 == V_48 ) {
F_37 ( V_389 , V_390 , L_8 ,
L_55 ) ;
T_1 -> V_22 . type = V_97 ;
T_1 -> V_22 . V_47 = V_395 ;
F_32 ( & T_1 -> V_32 ) ;
return true ;
} else if ( V_53 == V_396 && ! T_1 -> V_22 . V_66 &&
( V_391 = F_140 () ) > 1 ) {
const char * V_32 = F_49 ( T_1 ) ;
char * V_397 ;
if ( F_26 ( & V_397 , L_56 , V_32 , strchr ( V_32 , ':' ) ? L_1 : L_11 ) < 0 )
return false ;
if ( T_1 -> V_32 )
free ( T_1 -> V_32 ) ;
T_1 -> V_32 = V_397 ;
F_37 ( V_389 , V_390 ,
L_57 , V_391 ) ;
T_1 -> V_22 . V_66 = 1 ;
return true ;
}
return false ;
}
int F_141 ( struct V_1 * T_1 , struct V_153 * V_153 ,
int V_53 , char * V_389 , T_2 V_6 )
{
char V_398 [ V_399 ] ;
switch ( V_53 ) {
case V_400 :
case V_396 :
return F_37 ( V_389 , V_6 ,
L_58
L_59
L_60
L_61
L_62
L_63
L_64
L_65
L_66 ,
V_153 -> V_214 ? L_67 : L_1 ,
F_140 () ) ;
case V_392 :
return F_37 ( V_389 , V_6 , L_68 ,
F_49 ( T_1 ) ) ;
case V_316 :
return F_37 ( V_389 , V_6 , L_8 ,
L_69
L_70
L_71
L_72 ) ;
case V_54 :
if ( ( T_1 -> V_22 . V_8 & V_360 ) != 0 &&
F_142 ( L_73 , V_401 ) == 0 )
return F_37 ( V_389 , V_6 ,
L_74
L_75
L_76 , V_402 ) ;
break;
case V_394 :
if ( V_153 -> V_403 )
return F_37 ( V_389 , V_6 , L_8 ,
L_77 ) ;
break;
case V_404 :
if ( T_1 -> V_22 . V_45 != 0 )
return F_37 ( V_389 , V_6 , L_8 ,
L_78 ) ;
if ( T_1 -> V_22 . V_50 )
return F_37 ( V_389 , V_6 , L_8 ,
L_79 ) ;
#if F_143 ( V_405 ) || F_143 ( V_406 )
if ( T_1 -> V_22 . type == V_46 )
return F_37 ( V_389 , V_6 , L_8 ,
L_80
L_81 ) ;
#endif
break;
case V_407 :
if ( F_144 ( L_82 ) )
return F_37 ( V_389 , V_6 ,
L_83
L_84 ) ;
break;
case V_7 :
if ( T_1 -> V_22 . V_146 && V_157 . V_146 )
return F_37 ( V_389 , V_6 , L_85 ) ;
if ( V_157 . V_207 )
return F_37 ( V_389 , V_6 , L_86 ) ;
if ( V_157 . V_299 )
return F_37 ( V_389 , V_6 , L_87 , V_207 ) ;
break;
default:
break;
}
return F_37 ( V_389 , V_6 ,
L_88
L_89
L_90 ,
V_53 , F_145 ( V_53 , V_398 , sizeof( V_398 ) ) ,
F_49 ( T_1 ) ) ;
}
char * F_146 ( struct V_1 * T_1 )
{
if ( T_1 && T_1 -> V_38 && T_1 -> V_38 -> V_408 )
return T_1 -> V_38 -> V_408 -> V_409 ;
return NULL ;
}
