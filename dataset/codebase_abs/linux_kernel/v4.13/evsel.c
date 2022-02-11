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
T_1 -> V_43 = NULL ;
T_1 -> V_44 = NULL ;
T_1 -> V_45 = NULL ;
T_1 -> V_46 = false ;
}
struct V_1 * F_19 ( struct V_33 * V_22 , int V_12 )
{
struct V_1 * T_1 = F_20 ( V_5 . V_6 ) ;
if ( T_1 != NULL )
F_17 ( T_1 , V_22 , V_12 ) ;
if ( F_21 ( T_1 ) ) {
T_1 -> V_22 . V_8 |= ( V_47 | V_17 |
V_19 | V_48 ) ,
T_1 -> V_22 . V_49 = 1 ;
}
return T_1 ;
}
struct V_1 * F_22 ( void )
{
struct V_33 V_22 = {
. type = V_50 ,
. V_51 = V_52 ,
. V_53 = F_23 () != 0 ,
} ;
struct V_1 * T_1 ;
F_24 ( & V_22 ) ;
V_22 . V_49 = 1 ;
F_25 ( & V_22 ) ;
V_22 . V_49 = 0 ;
T_1 = F_26 ( & V_22 ) ;
if ( T_1 == NULL )
goto V_54;
if ( F_27 ( & T_1 -> V_32 , L_2 ,
( V_22 . V_55 || V_22 . V_53 ) ? L_3 : L_1 ,
V_22 . V_53 ? L_4 : L_1 ,
V_22 . V_55 ? V_22 . V_55 + 1 : 0 , L_5 ) < 0 )
goto V_56;
V_54:
return T_1 ;
V_56:
F_28 ( T_1 ) ;
T_1 = NULL ;
goto V_54;
}
struct V_1 * F_29 ( const char * V_57 , const char * V_32 , int V_12 )
{
struct V_1 * T_1 = F_20 ( V_5 . V_6 ) ;
int V_58 = - V_59 ;
if ( T_1 == NULL ) {
goto V_60;
} else {
struct V_33 V_22 = {
. type = V_61 ,
. V_8 = ( V_47 | V_17 |
V_19 | V_48 ) ,
} ;
if ( F_27 ( & T_1 -> V_32 , L_6 , V_57 , V_32 ) < 0 )
goto V_62;
T_1 -> V_63 = F_30 ( V_57 , V_32 ) ;
if ( F_31 ( T_1 -> V_63 ) ) {
V_58 = F_32 ( T_1 -> V_63 ) ;
goto V_62;
}
F_24 ( & V_22 ) ;
V_22 . V_51 = T_1 -> V_63 -> V_64 ;
V_22 . V_49 = 1 ;
F_17 ( T_1 , & V_22 , V_12 ) ;
}
return T_1 ;
V_62:
F_33 ( & T_1 -> V_32 ) ;
free ( T_1 ) ;
V_60:
return F_34 ( V_58 ) ;
}
static const char * F_35 ( T_3 V_51 )
{
if ( V_51 < V_65 && V_66 [ V_51 ] )
return V_66 [ V_51 ] ;
return L_7 ;
}
static int F_36 ( struct V_1 * T_1 , char * V_67 , T_2 V_6 )
{
int V_68 = 0 , V_69 = 0 ;
struct V_33 * V_22 = & T_1 -> V_22 ;
bool V_70 = false ;
#define F_37 ( T_4 , T_5 ) do { \
if (!attr->exclude_##context) { \
if (!colon) colon = ++r; \
r += scnprintf(bf + r, size - r, "%c", mod); \
} } while(0)
if ( V_22 -> V_53 || V_22 -> V_71 || V_22 -> V_72 ) {
F_37 ( V_73 , 'k' ) ;
F_37 ( V_74 , 'u' ) ;
F_37 ( V_75 , 'h' ) ;
V_70 = true ;
}
if ( V_22 -> V_55 ) {
if ( ! V_68 )
V_68 = ++ V_69 ;
V_69 += F_38 ( V_67 + V_69 , V_6 - V_69 , L_8 , V_22 -> V_55 , L_5 ) ;
V_70 = true ;
}
if ( V_22 -> V_76 || V_22 -> V_77 == V_70 ) {
F_37 ( V_78 , 'H' ) ;
F_37 ( V_79 , 'G' ) ;
}
#undef F_37
if ( V_68 )
V_67 [ V_68 - 1 ] = ':' ;
return V_69 ;
}
static int F_39 ( struct V_1 * T_1 , char * V_67 , T_2 V_6 )
{
int V_69 = F_38 ( V_67 , V_6 , L_9 , F_35 ( T_1 -> V_22 . V_51 ) ) ;
return V_69 + F_36 ( T_1 , V_67 + V_69 , V_6 - V_69 ) ;
}
static const char * F_40 ( T_3 V_51 )
{
if ( V_51 < V_80 && V_81 [ V_51 ] )
return V_81 [ V_51 ] ;
return L_10 ;
}
static int F_41 ( struct V_1 * T_1 , char * V_67 , T_2 V_6 )
{
int V_69 = F_38 ( V_67 , V_6 , L_9 , F_40 ( T_1 -> V_22 . V_51 ) ) ;
return V_69 + F_36 ( T_1 , V_67 + V_69 , V_6 - V_69 ) ;
}
static int F_42 ( char * V_67 , T_2 V_6 , T_3 V_82 , T_3 type )
{
int V_69 ;
V_69 = F_38 ( V_67 , V_6 , L_11 V_83 L_3 , V_82 ) ;
if ( type & V_84 )
V_69 += F_38 ( V_67 + V_69 , V_6 - V_69 , L_12 ) ;
if ( type & V_85 )
V_69 += F_38 ( V_67 + V_69 , V_6 - V_69 , L_13 ) ;
if ( type & V_86 )
V_69 += F_38 ( V_67 + V_69 , V_6 - V_69 , L_14 ) ;
return V_69 ;
}
static int F_43 ( struct V_1 * T_1 , char * V_67 , T_2 V_6 )
{
struct V_33 * V_22 = & T_1 -> V_22 ;
int V_69 = F_42 ( V_67 , V_6 , V_22 -> V_87 , V_22 -> V_88 ) ;
return V_69 + F_36 ( T_1 , V_67 + V_69 , V_6 - V_69 ) ;
}
bool F_44 ( T_6 type , T_6 V_89 )
{
if ( V_90 [ type ] & F_45 ( V_89 ) )
return true ;
else
return false ;
}
int F_46 ( T_6 type , T_6 V_89 , T_6 V_91 ,
char * V_67 , T_2 V_6 )
{
if ( V_91 ) {
return F_38 ( V_67 , V_6 , L_15 , V_92 [ type ] [ 0 ] ,
V_93 [ V_89 ] [ 0 ] ,
V_94 [ V_91 ] [ 0 ] ) ;
}
return F_38 ( V_67 , V_6 , L_16 , V_92 [ type ] [ 0 ] ,
V_93 [ V_89 ] [ 1 ] ) ;
}
static int F_47 ( T_3 V_51 , char * V_67 , T_2 V_6 )
{
T_6 V_89 , V_91 , type = ( V_51 >> 0 ) & 0xff ;
const char * V_58 = L_17 ;
if ( type >= V_95 )
goto V_60;
V_89 = ( V_51 >> 8 ) & 0xff ;
V_58 = L_18 ;
if ( V_89 >= V_96 )
goto V_60;
V_91 = ( V_51 >> 16 ) & 0xff ;
V_58 = L_19 ;
if ( V_91 >= V_97 )
goto V_60;
V_58 = L_20 ;
if ( ! F_44 ( type , V_89 ) )
goto V_60;
return F_46 ( type , V_89 , V_91 , V_67 , V_6 ) ;
V_60:
return F_38 ( V_67 , V_6 , L_9 , V_58 ) ;
}
static int F_48 ( struct V_1 * T_1 , char * V_67 , T_2 V_6 )
{
int V_98 = F_47 ( T_1 -> V_22 . V_51 , V_67 , V_6 ) ;
return V_98 + F_36 ( T_1 , V_67 + V_98 , V_6 - V_98 ) ;
}
static int F_49 ( struct V_1 * T_1 , char * V_67 , T_2 V_6 )
{
int V_98 = F_38 ( V_67 , V_6 , L_21 V_83 , T_1 -> V_22 . V_51 ) ;
return V_98 + F_36 ( T_1 , V_67 + V_98 , V_6 - V_98 ) ;
}
const char * F_50 ( struct V_1 * T_1 )
{
char V_67 [ 128 ] ;
if ( T_1 -> V_32 )
return T_1 -> V_32 ;
switch ( T_1 -> V_22 . type ) {
case V_99 :
F_49 ( T_1 , V_67 , sizeof( V_67 ) ) ;
break;
case V_50 :
F_39 ( T_1 , V_67 , sizeof( V_67 ) ) ;
break;
case V_100 :
F_48 ( T_1 , V_67 , sizeof( V_67 ) ) ;
break;
case V_101 :
F_41 ( T_1 , V_67 , sizeof( V_67 ) ) ;
break;
case V_61 :
F_38 ( V_67 , sizeof( V_67 ) , L_9 , L_22 ) ;
break;
case V_102 :
F_43 ( T_1 , V_67 , sizeof( V_67 ) ) ;
break;
default:
F_38 ( V_67 , sizeof( V_67 ) , L_23 ,
T_1 -> V_22 . type ) ;
break;
}
T_1 -> V_32 = F_51 ( V_67 ) ;
return T_1 -> V_32 ? : L_24 ;
}
const char * F_52 ( struct V_1 * T_1 )
{
return T_1 -> V_103 ? : L_25 ;
}
int F_53 ( struct V_1 * T_1 , char * V_104 , T_2 V_6 )
{
int V_98 ;
struct V_1 * V_105 ;
const char * V_103 = F_52 ( T_1 ) ;
V_98 = F_38 ( V_104 , V_6 , L_9 , V_103 ) ;
V_98 += F_38 ( V_104 + V_98 , V_6 - V_98 , L_26 ,
F_50 ( T_1 ) ) ;
F_54 (pos, evsel)
V_98 += F_38 ( V_104 + V_98 , V_6 - V_98 , L_27 ,
F_50 ( V_105 ) ) ;
V_98 += F_38 ( V_104 + V_98 , V_6 - V_98 , L_28 ) ;
return V_98 ;
}
void F_55 ( struct V_1 * T_1 ,
struct V_106 * V_107 ,
struct V_108 * V_109 )
{
bool V_110 = F_15 ( T_1 ) ;
struct V_33 * V_22 = & T_1 -> V_22 ;
F_14 ( T_1 , V_111 ) ;
V_22 -> V_112 = V_109 -> V_113 ;
if ( V_109 -> V_114 == V_115 ) {
if ( ! V_107 -> V_116 ) {
if ( V_22 -> V_71 ) {
F_56 ( L_29
L_30
L_31 ) ;
} else {
F_14 ( T_1 , V_117 ) ;
V_22 -> V_118 = V_119 |
V_120 |
V_121 |
V_122 ;
}
} else
F_56 ( L_32
L_31 ) ;
}
if ( V_109 -> V_114 == V_123 ) {
if ( ! V_110 ) {
F_14 ( T_1 , V_124 ) ;
F_14 ( T_1 , V_125 ) ;
V_22 -> V_126 = V_127 ;
V_22 -> V_128 = V_109 -> V_129 ;
V_22 -> V_130 = 1 ;
} else {
F_57 ( L_33
L_34 ) ;
}
}
if ( V_110 ) {
F_57 ( L_35 ) ;
V_22 -> V_130 = 1 ;
}
}
static void
F_58 ( struct V_1 * T_1 ,
struct V_108 * V_109 )
{
struct V_33 * V_22 = & T_1 -> V_22 ;
F_13 ( T_1 , V_111 ) ;
if ( V_109 -> V_114 == V_115 ) {
F_13 ( T_1 , V_117 ) ;
V_22 -> V_118 &= ~ ( V_119 |
V_120 ) ;
}
if ( V_109 -> V_114 == V_123 ) {
F_13 ( T_1 , V_124 ) ;
F_13 ( T_1 , V_125 ) ;
}
}
static void F_59 ( struct V_1 * T_1 ,
struct V_106 * V_107 )
{
struct V_131 * V_132 ;
struct V_133 * V_41 = & T_1 -> V_41 ;
struct V_33 * V_22 = & T_1 -> V_22 ;
struct V_108 V_109 ;
T_7 V_129 = 0 ;
int V_113 = 0 ;
const char * V_134 = NULL ;
V_109 . V_114 = V_108 . V_114 ;
F_60 (term, config_terms, list) {
switch ( V_132 -> type ) {
case V_135 :
V_22 -> V_49 = V_132 -> V_136 . V_137 ;
V_22 -> V_138 = 0 ;
break;
case V_139 :
V_22 -> V_140 = V_132 -> V_136 . V_138 ;
V_22 -> V_138 = 1 ;
break;
case V_141 :
if ( V_132 -> V_136 . time )
F_14 ( T_1 , TIME ) ;
else
F_13 ( T_1 , TIME ) ;
break;
case V_142 :
V_134 = V_132 -> V_136 . V_143 ;
break;
case V_144 :
if ( V_132 -> V_136 . V_145 && strcmp ( V_132 -> V_136 . V_145 , L_36 ) ) {
F_14 ( T_1 , V_117 ) ;
F_61 ( V_132 -> V_136 . V_145 ,
& V_22 -> V_118 ) ;
} else
F_13 ( T_1 , V_117 ) ;
break;
case V_146 :
V_129 = V_132 -> V_136 . V_147 ;
break;
case V_148 :
V_113 = V_132 -> V_136 . V_113 ;
break;
case V_149 :
V_22 -> V_150 = V_132 -> V_136 . V_150 ? 1 : 0 ;
break;
case V_151 :
V_22 -> V_152 = V_132 -> V_136 . V_153 ? 1 : 0 ;
break;
default:
break;
}
}
if ( ( V_134 != NULL ) || ( V_129 > 0 ) || V_113 ) {
if ( V_113 ) {
V_109 . V_113 = V_113 ;
if ( V_134 == NULL )
V_134 = L_37 ;
}
if ( V_134 != NULL ) {
if ( ! strcmp ( V_134 , L_36 ) ) {
V_109 . V_154 = false ;
V_109 . V_114 = V_155 ;
} else {
V_109 . V_154 = true ;
if ( F_62 ( V_134 , & V_109 ) ) {
F_63 ( L_38
L_39 ,
T_1 -> V_32 ) ;
return;
}
}
}
if ( V_129 > 0 ) {
V_129 = F_64 ( V_129 , sizeof( T_3 ) ) ;
V_109 . V_129 = V_129 ;
}
if ( V_108 . V_154 )
F_58 ( T_1 , & V_108 ) ;
if ( V_109 . V_154 )
F_55 ( T_1 , V_107 , & V_109 ) ;
}
}
void F_65 ( struct V_1 * T_1 , struct V_106 * V_107 ,
struct V_108 * V_156 )
{
struct V_1 * V_35 = T_1 -> V_35 ;
struct V_33 * V_22 = & T_1 -> V_22 ;
int V_157 = T_1 -> V_34 ;
bool V_158 = V_107 -> V_159 . V_160 && ! V_107 -> V_159 . V_161 ;
V_22 -> V_162 = V_163 . V_162 ? 0 : 1 ;
V_22 -> V_150 = ! V_107 -> V_164 ;
V_22 -> V_152 = V_107 -> V_153 ? 1 : 0 ;
F_14 ( T_1 , V_165 ) ;
F_14 ( T_1 , V_166 ) ;
if ( T_1 -> V_167 ) {
F_14 ( T_1 , V_168 ) ;
F_12 ( T_1 , false ) ;
if ( V_35 -> V_169 > 1 ) {
V_22 -> V_30 |= V_170 ;
V_22 -> V_150 = 0 ;
}
}
if ( ! V_22 -> V_49 || ( V_107 -> V_171 != V_172 ||
V_107 -> V_173 != V_174 ) ) {
if ( V_107 -> V_138 ) {
F_14 ( T_1 , V_175 ) ;
V_22 -> V_138 = 1 ;
V_22 -> V_140 = V_107 -> V_138 ;
} else {
V_22 -> V_49 = V_107 -> V_176 ;
}
}
if ( ( V_35 != T_1 ) && V_35 -> V_167 ) {
V_22 -> V_140 = 0 ;
V_22 -> V_49 = 0 ;
}
if ( V_107 -> V_177 )
V_22 -> V_140 = 0 ;
if ( V_107 -> V_178 )
V_22 -> V_178 = 1 ;
if ( V_107 -> V_179 ) {
F_14 ( T_1 , V_180 ) ;
V_22 -> V_181 = V_157 ;
}
if ( F_15 ( T_1 ) )
T_1 -> V_22 . V_130 = 1 ;
if ( V_156 && V_156 -> V_154 && ! T_1 -> V_182 )
F_55 ( T_1 , V_107 , V_156 ) ;
if ( V_107 -> V_183 ) {
V_22 -> V_184 = V_107 -> V_183 ;
F_14 ( T_1 , V_185 ) ;
}
if ( F_66 ( & V_107 -> V_159 ) || V_107 -> V_186 )
F_14 ( T_1 , V_187 ) ;
if ( V_107 -> V_137 )
F_14 ( T_1 , V_175 ) ;
if ( V_107 -> V_188 &&
( ! V_163 . V_162 &&
( ! V_107 -> V_164 || F_66 ( & V_107 -> V_159 ) || V_158 ||
V_107 -> V_189 ) ) )
F_14 ( T_1 , TIME ) ;
if ( V_107 -> V_190 && ! T_1 -> V_182 ) {
F_14 ( T_1 , TIME ) ;
F_14 ( T_1 , V_191 ) ;
F_14 ( T_1 , V_187 ) ;
}
if ( V_107 -> V_179 )
F_14 ( T_1 , V_192 ) ;
if ( V_107 -> V_193 ) {
V_22 -> V_194 = 0 ;
V_22 -> V_195 = 1 ;
}
if ( V_107 -> V_116 && ! T_1 -> V_182 ) {
F_14 ( T_1 , V_117 ) ;
V_22 -> V_118 = V_107 -> V_116 ;
}
if ( V_107 -> V_196 )
F_14 ( T_1 , V_197 ) ;
V_22 -> V_198 = V_157 ;
V_22 -> V_199 = V_157 ;
V_22 -> V_200 = V_157 && ! V_163 . V_200 ;
V_22 -> V_201 = V_157 ;
if ( V_107 -> V_202 )
V_22 -> V_203 = V_157 ;
if ( V_107 -> V_204 )
V_22 -> V_205 = V_157 ;
if ( V_107 -> V_206 )
F_14 ( T_1 , V_207 ) ;
if ( V_107 -> V_208 ) {
T_1 -> V_22 . V_30 |=
V_209 |
V_210 ;
}
if ( F_67 ( T_1 ) )
V_22 -> V_211 = 1 ;
if ( F_68 ( & V_107 -> V_159 ) && F_67 ( T_1 ) &&
! V_107 -> V_212 )
V_22 -> V_213 = 1 ;
if ( T_1 -> V_214 ) {
V_22 -> V_211 = 0 ;
V_22 -> V_213 = 0 ;
}
V_215 = V_107 -> V_215 ;
if ( V_107 -> V_216 ) {
V_22 -> V_216 = 1 ;
V_22 -> V_215 = V_107 -> V_215 ;
}
if ( T_1 -> V_217 )
F_25 ( V_22 ) ;
if ( V_107 -> V_218 ) {
V_22 -> V_53 = 1 ;
V_22 -> V_71 = 0 ;
}
if ( V_107 -> V_219 ) {
V_22 -> V_53 = 0 ;
V_22 -> V_71 = 1 ;
}
F_59 ( T_1 , V_107 ) ;
T_1 -> V_220 = V_107 -> V_220 ;
}
static int F_69 ( struct V_1 * T_1 , int V_221 , int V_222 )
{
if ( T_1 -> V_223 )
V_222 = 1 ;
T_1 -> V_224 = F_70 ( V_221 , V_222 , sizeof( int ) ) ;
if ( T_1 -> V_224 ) {
int V_225 , V_226 ;
for ( V_225 = 0 ; V_225 < V_221 ; V_225 ++ ) {
for ( V_226 = 0 ; V_226 < V_222 ; V_226 ++ ) {
F_71 ( T_1 , V_225 , V_226 ) = - 1 ;
}
}
}
return T_1 -> V_224 != NULL ? 0 : - V_59 ;
}
static int F_72 ( struct V_1 * T_1 , int V_221 , int V_222 ,
int V_227 , void * V_228 )
{
int V_225 , V_226 ;
if ( T_1 -> V_223 )
V_222 = 1 ;
for ( V_225 = 0 ; V_225 < V_221 ; V_225 ++ ) {
for ( V_226 = 0 ; V_226 < V_222 ; V_226 ++ ) {
int V_224 = F_71 ( T_1 , V_225 , V_226 ) ,
V_58 = F_73 ( V_224 , V_227 , V_228 ) ;
if ( V_58 )
return V_58 ;
}
}
return 0 ;
}
int F_74 ( struct V_1 * T_1 , int V_221 , int V_222 ,
const char * V_229 )
{
return F_72 ( T_1 , V_221 , V_222 ,
V_230 ,
( void * ) V_229 ) ;
}
int F_75 ( struct V_1 * T_1 , const char * V_229 )
{
char * V_231 = F_51 ( V_229 ) ;
if ( V_231 != NULL ) {
free ( T_1 -> V_229 ) ;
T_1 -> V_229 = V_231 ;
return 0 ;
}
return - 1 ;
}
static int F_76 ( struct V_1 * T_1 ,
const char * V_232 , const char * V_229 )
{
char * V_231 ;
if ( T_1 -> V_229 == NULL )
return F_75 ( T_1 , V_229 ) ;
if ( F_27 ( & V_231 , V_232 , T_1 -> V_229 , V_229 ) > 0 ) {
free ( T_1 -> V_229 ) ;
T_1 -> V_229 = V_231 ;
return 0 ;
}
return - 1 ;
}
int F_77 ( struct V_1 * T_1 , const char * V_229 )
{
return F_76 ( T_1 , L_40 , V_229 ) ;
}
int F_78 ( struct V_1 * T_1 , const char * V_229 )
{
return F_76 ( T_1 , L_41 , V_229 ) ;
}
int F_79 ( struct V_1 * T_1 )
{
int V_222 = F_80 ( T_1 -> V_233 ) ;
int V_221 = F_81 ( T_1 -> V_234 ) ;
return F_72 ( T_1 , V_221 , V_222 ,
V_235 ,
0 ) ;
}
int F_82 ( struct V_1 * T_1 )
{
int V_222 = F_80 ( T_1 -> V_233 ) ;
int V_221 = F_81 ( T_1 -> V_234 ) ;
return F_72 ( T_1 , V_221 , V_222 ,
V_236 ,
0 ) ;
}
int F_83 ( struct V_1 * T_1 , int V_221 , int V_222 )
{
if ( V_221 == 0 || V_222 == 0 )
return 0 ;
if ( T_1 -> V_223 )
V_222 = 1 ;
T_1 -> V_237 = F_70 ( V_221 , V_222 , sizeof( struct V_238 ) ) ;
if ( T_1 -> V_237 == NULL )
return - V_59 ;
T_1 -> V_64 = F_20 ( V_221 * V_222 * sizeof( T_3 ) ) ;
if ( T_1 -> V_64 == NULL ) {
F_84 ( T_1 -> V_237 ) ;
T_1 -> V_237 = NULL ;
return - V_59 ;
}
return 0 ;
}
static void F_85 ( struct V_1 * T_1 )
{
F_84 ( T_1 -> V_224 ) ;
T_1 -> V_224 = NULL ;
}
static void F_86 ( struct V_1 * T_1 )
{
F_84 ( T_1 -> V_237 ) ;
T_1 -> V_237 = NULL ;
F_33 ( & T_1 -> V_64 ) ;
}
static void F_87 ( struct V_1 * T_1 )
{
struct V_131 * V_132 , * V_239 ;
F_88 (term, h, &evsel->config_terms, list) {
F_89 ( & V_132 -> V_240 ) ;
free ( V_132 ) ;
}
}
void F_90 ( struct V_1 * T_1 , int V_221 , int V_222 )
{
int V_225 , V_226 ;
if ( T_1 -> V_223 )
V_222 = 1 ;
for ( V_225 = 0 ; V_225 < V_221 ; V_225 ++ )
for ( V_226 = 0 ; V_226 < V_222 ; ++ V_226 ) {
F_91 ( F_71 ( T_1 , V_225 , V_226 ) ) ;
F_71 ( T_1 , V_225 , V_226 ) = - 1 ;
}
}
void F_92 ( struct V_1 * T_1 )
{
assert ( F_93 ( & T_1 -> V_40 ) ) ;
assert ( T_1 -> V_38 == NULL ) ;
F_85 ( T_1 ) ;
F_86 ( T_1 ) ;
F_87 ( T_1 ) ;
F_94 ( T_1 -> V_241 ) ;
F_95 ( T_1 -> V_234 ) ;
F_95 ( T_1 -> V_242 ) ;
F_96 ( T_1 -> V_233 ) ;
F_33 ( & T_1 -> V_103 ) ;
F_33 ( & T_1 -> V_32 ) ;
V_5 . F_5 ( T_1 ) ;
}
void F_28 ( struct V_1 * T_1 )
{
F_92 ( T_1 ) ;
free ( T_1 ) ;
}
void F_97 ( struct V_1 * T_1 , int V_225 , int V_226 ,
struct V_243 * V_244 )
{
struct V_243 V_245 ;
if ( ! T_1 -> V_246 )
return;
if ( V_225 == - 1 ) {
V_245 = T_1 -> V_246 -> V_247 ;
T_1 -> V_246 -> V_247 = * V_244 ;
} else {
V_245 = * F_98 ( T_1 -> V_246 , V_225 , V_226 ) ;
* F_98 ( T_1 -> V_246 , V_225 , V_226 ) = * V_244 ;
}
V_244 -> V_136 = V_244 -> V_136 - V_245 . V_136 ;
V_244 -> V_248 = V_244 -> V_248 - V_245 . V_248 ;
V_244 -> V_249 = V_244 -> V_249 - V_245 . V_249 ;
}
void F_99 ( struct V_243 * V_244 ,
bool V_37 , T_8 * V_250 )
{
T_8 V_251 = 0 ;
if ( V_37 ) {
if ( V_244 -> V_249 == 0 ) {
V_251 = - 1 ;
V_244 -> V_136 = 0 ;
} else if ( V_244 -> V_249 < V_244 -> V_248 ) {
V_251 = 1 ;
V_244 -> V_136 = ( T_3 ) ( ( double ) V_244 -> V_136 * V_244 -> V_248 / V_244 -> V_249 + 0.5 ) ;
}
} else
V_244 -> V_248 = V_244 -> V_249 = 0 ;
if ( V_250 )
* V_250 = V_251 ;
}
int F_100 ( struct V_1 * T_1 , int V_225 , int V_226 ,
struct V_243 * V_244 )
{
memset ( V_244 , 0 , sizeof( * V_244 ) ) ;
if ( F_71 ( T_1 , V_225 , V_226 ) < 0 )
return - V_7 ;
if ( F_101 ( F_71 ( T_1 , V_225 , V_226 ) , V_244 , sizeof( * V_244 ) ) <= 0 )
return - V_252 ;
return 0 ;
}
int F_102 ( struct V_1 * T_1 ,
int V_225 , int V_226 , bool V_37 )
{
struct V_243 V_244 ;
T_2 V_253 = V_37 ? 3 : 1 ;
if ( F_71 ( T_1 , V_225 , V_226 ) < 0 )
return - V_7 ;
if ( T_1 -> V_254 == NULL && F_103 ( T_1 , V_225 + 1 , V_226 + 1 ) < 0 )
return - V_59 ;
if ( F_101 ( F_71 ( T_1 , V_225 , V_226 ) , & V_244 , V_253 * sizeof( T_3 ) ) <= 0 )
return - V_252 ;
F_97 ( T_1 , V_225 , V_226 , & V_244 ) ;
F_99 ( & V_244 , V_37 , NULL ) ;
* F_98 ( T_1 -> V_254 , V_225 , V_226 ) = V_244 ;
return 0 ;
}
static int F_104 ( struct V_1 * T_1 , int V_225 , int V_226 )
{
struct V_1 * V_35 = T_1 -> V_35 ;
int V_224 ;
if ( F_67 ( T_1 ) )
return - 1 ;
F_105 ( ! V_35 -> V_224 ) ;
V_224 = F_71 ( V_35 , V_225 , V_226 ) ;
F_105 ( V_224 == - 1 ) ;
return V_224 ;
}
static void F_106 ( char * V_104 , T_2 V_6 , T_3 V_255 , struct V_256 * V_257 )
{
bool V_258 = true ;
int V_11 = 0 ;
do {
if ( V_255 & V_257 [ V_11 ] . V_25 ) {
V_104 += F_38 ( V_104 , V_6 , L_42 , V_258 ? L_1 : L_43 , V_257 [ V_11 ] . V_32 ) ;
V_258 = false ;
}
} while ( V_257 [ ++ V_11 ] . V_32 != NULL );
}
static void F_107 ( char * V_104 , T_2 V_6 , T_3 V_255 )
{
#define F_108 ( T_9 ) { PERF_SAMPLE_##n, #n }
struct V_256 V_257 [] = {
F_108 ( V_165 ) , F_108 ( V_166 ) , F_108 ( TIME ) , F_108 ( V_180 ) ,
F_108 ( V_168 ) , F_108 ( V_111 ) , F_108 ( V_28 ) , F_108 ( V_187 ) ,
F_108 ( V_175 ) , F_108 ( V_259 ) , F_108 ( V_191 ) ,
F_108 ( V_117 ) , F_108 ( V_124 ) , F_108 ( V_125 ) ,
F_108 ( V_29 ) , F_108 ( V_185 ) , F_108 ( V_192 ) ,
F_108 ( V_197 ) ,
{ . V_32 = NULL , }
} ;
#undef F_108
F_106 ( V_104 , V_6 , V_255 , V_257 ) ;
}
static void F_109 ( char * V_104 , T_2 V_6 , T_3 V_255 )
{
#define F_108 ( T_9 ) { PERF_SAMPLE_BRANCH_##n, #n }
struct V_256 V_257 [] = {
F_108 ( V_260 ) , F_108 ( V_261 ) , F_108 ( V_262 ) , F_108 ( V_263 ) ,
F_108 ( V_264 ) , F_108 ( V_265 ) , F_108 ( V_266 ) ,
F_108 ( V_267 ) , F_108 ( V_268 ) , F_108 ( V_269 ) ,
F_108 ( V_270 ) , F_108 ( V_271 ) , F_108 ( V_272 ) ,
F_108 ( V_273 ) , F_108 ( V_274 ) , F_108 ( V_275 ) ,
{ . V_32 = NULL , }
} ;
#undef F_108
F_106 ( V_104 , V_6 , V_255 , V_257 ) ;
}
static void F_110 ( char * V_104 , T_2 V_6 , T_3 V_255 )
{
#define F_108 ( T_9 ) { PERF_FORMAT_##n, #n }
struct V_256 V_257 [] = {
F_108 ( V_276 ) , F_108 ( V_277 ) ,
F_108 ( V_28 ) , F_108 ( V_278 ) ,
{ . V_32 = NULL , }
} ;
#undef F_108
F_106 ( V_104 , V_6 , V_255 , V_257 ) ;
}
int F_111 ( T_10 * V_279 , struct V_33 * V_22 ,
T_11 V_280 , void * V_281 )
{
char V_104 [ V_282 ] ;
int V_98 = 0 ;
F_112 ( type , V_283 ) ;
F_112 ( V_6 , V_283 ) ;
F_112 ( V_51 , V_284 ) ;
F_113 ( L_44 , V_49 , V_283 ) ;
F_112 ( V_8 , V_285 ) ;
F_112 ( V_30 , V_286 ) ;
F_112 ( V_211 , V_283 ) ;
F_112 ( V_150 , V_283 ) ;
F_112 ( V_287 , V_283 ) ;
F_112 ( V_288 , V_283 ) ;
F_112 ( V_71 , V_283 ) ;
F_112 ( V_53 , V_283 ) ;
F_112 ( V_72 , V_283 ) ;
F_112 ( V_289 , V_283 ) ;
F_112 ( V_199 , V_283 ) ;
F_112 ( V_201 , V_283 ) ;
F_112 ( V_138 , V_283 ) ;
F_112 ( V_178 , V_283 ) ;
F_112 ( V_213 , V_283 ) ;
F_112 ( V_198 , V_283 ) ;
F_112 ( V_194 , V_283 ) ;
F_112 ( V_55 , V_283 ) ;
F_112 ( V_181 , V_283 ) ;
F_112 ( V_162 , V_283 ) ;
F_112 ( V_76 , V_283 ) ;
F_112 ( V_77 , V_283 ) ;
F_112 ( V_290 , V_283 ) ;
F_112 ( V_130 , V_283 ) ;
F_112 ( V_200 , V_283 ) ;
F_112 ( V_291 , V_283 ) ;
F_112 ( V_216 , V_283 ) ;
F_112 ( V_205 , V_283 ) ;
F_112 ( V_152 , V_283 ) ;
F_113 ( L_45 , V_195 , V_283 ) ;
F_112 ( V_88 , V_283 ) ;
F_113 ( L_46 , V_87 , V_284 ) ;
F_113 ( L_47 , V_292 , V_284 ) ;
F_112 ( V_118 , V_293 ) ;
F_112 ( V_126 , V_284 ) ;
F_112 ( V_128 , V_283 ) ;
F_112 ( V_215 , V_294 ) ;
F_112 ( V_184 , V_284 ) ;
F_112 ( V_295 , V_283 ) ;
F_112 ( V_112 , V_283 ) ;
return V_98 ;
}
static int F_114 ( T_10 * V_279 , const char * V_32 , const char * V_136 ,
void * V_281 V_2 )
{
return fprintf ( V_279 , L_48 , V_32 , V_136 ) ;
}
static bool V_220 ( struct V_1 * T_1 ,
struct V_296 * V_233 ,
int V_226 , int V_58 )
{
if ( ! T_1 -> V_220 )
return false ;
if ( T_1 -> V_223 )
return false ;
if ( V_58 != - V_297 )
return false ;
if ( V_233 -> V_298 == 1 )
return false ;
if ( F_115 ( V_233 , V_226 ) )
return false ;
F_56 ( L_49 ,
F_116 ( V_233 , V_226 ) ) ;
return true ;
}
int F_117 ( struct V_1 * T_1 , struct V_299 * V_234 ,
struct V_296 * V_233 )
{
int V_225 , V_226 , V_222 ;
unsigned long V_300 = V_301 ;
int V_302 = - 1 , V_58 ;
enum { V_303 , V_304 , V_305 } V_306 = V_303 ;
if ( V_163 . V_152 && T_1 -> V_22 . V_152 )
return - V_7 ;
if ( V_234 == NULL ) {
static struct V_299 * V_307 ;
if ( V_307 == NULL ) {
V_307 = F_118 () ;
if ( V_307 == NULL )
return - V_59 ;
}
V_234 = V_307 ;
}
if ( V_233 == NULL ) {
static struct V_296 * V_308 ;
if ( V_308 == NULL ) {
V_308 = F_119 ( - 1 ) ;
if ( V_308 == NULL )
return - V_59 ;
}
V_233 = V_308 ;
}
if ( T_1 -> V_223 )
V_222 = 1 ;
else
V_222 = V_233 -> V_298 ;
if ( T_1 -> V_224 == NULL &&
F_69 ( T_1 , V_234 -> V_298 , V_222 ) < 0 )
return - V_59 ;
if ( T_1 -> V_241 ) {
V_300 |= V_309 ;
V_302 = T_1 -> V_241 -> V_224 ;
}
V_310:
if ( V_163 . V_311 )
T_1 -> V_22 . V_215 = V_312 ;
if ( V_163 . V_215 ) {
T_1 -> V_22 . V_216 = 0 ;
T_1 -> V_22 . V_215 = 0 ;
}
if ( V_163 . V_313 )
V_300 &= ~ ( unsigned long ) V_301 ;
if ( V_163 . V_200 )
T_1 -> V_22 . V_200 = 0 ;
if ( V_163 . V_77 )
T_1 -> V_22 . V_77 = T_1 -> V_22 . V_76 = 0 ;
if ( V_163 . V_314 )
T_1 -> V_22 . V_118 &= ~ ( V_122 |
V_121 ) ;
V_315:
if ( V_163 . V_162 )
T_1 -> V_22 . V_162 = 0 ;
if ( V_316 >= 2 ) {
fprintf ( V_317 , L_50 , V_318 ) ;
fprintf ( V_317 , L_51 ) ;
F_111 ( V_317 , & T_1 -> V_22 , F_114 , NULL ) ;
fprintf ( V_317 , L_50 , V_318 ) ;
}
for ( V_225 = 0 ; V_225 < V_234 -> V_298 ; V_225 ++ ) {
for ( V_226 = 0 ; V_226 < V_222 ; V_226 ++ ) {
int V_224 , V_319 ;
if ( ! T_1 -> V_241 && ! T_1 -> V_223 )
V_302 = F_116 ( V_233 , V_226 ) ;
V_319 = F_104 ( T_1 , V_225 , V_226 ) ;
V_320:
F_120 ( L_52 ,
V_302 , V_234 -> V_321 [ V_225 ] , V_319 , V_300 ) ;
V_224 = F_121 ( & T_1 -> V_22 , V_302 , V_234 -> V_321 [ V_225 ] ,
V_319 , V_300 ) ;
F_71 ( T_1 , V_225 , V_226 ) = V_224 ;
if ( V_224 < 0 ) {
V_58 = - V_252 ;
if ( V_220 ( T_1 , V_233 , V_226 , V_58 ) ) {
V_222 -- ;
V_226 -- ;
V_58 = 0 ;
continue;
}
F_120 ( L_53 ,
V_58 ) ;
goto V_322;
}
F_120 ( L_54 , V_224 ) ;
if ( T_1 -> V_39 >= 0 ) {
int V_323 = V_224 ;
int V_39 = T_1 -> V_39 ;
V_58 = F_73 ( V_323 ,
V_324 ,
V_39 ) ;
if ( V_58 && V_252 != V_325 ) {
F_63 ( L_55 ,
V_39 , strerror ( V_252 ) ) ;
V_58 = - V_7 ;
goto V_326;
}
}
V_306 = V_303 ;
if ( V_163 . V_215 ||
V_163 . V_311 ) {
V_58 = - V_7 ;
goto V_326;
}
}
}
return 0 ;
V_322:
if ( V_58 == - V_327 && V_306 < V_305 ) {
struct V_328 V_329 ;
int V_330 = V_252 ;
if ( F_122 ( V_331 , & V_329 ) == 0 ) {
if ( V_306 == V_303 )
V_329 . V_332 = V_329 . V_333 ;
else {
V_329 . V_332 = V_329 . V_333 + 1000 ;
V_329 . V_333 = V_329 . V_332 ;
}
if ( F_123 ( V_331 , & V_329 ) == 0 ) {
V_306 ++ ;
V_252 = V_330 ;
goto V_320;
}
}
V_252 = V_330 ;
}
if ( V_58 != - V_7 || V_225 > 0 || V_226 > 0 )
goto V_326;
if ( ! V_163 . V_152 && T_1 -> V_22 . V_152 ) {
V_163 . V_152 = true ;
goto V_326;
} else if ( ! V_163 . V_311 && T_1 -> V_22 . V_216 ) {
V_163 . V_311 = true ;
goto V_310;
} else if ( ! V_163 . V_215 && T_1 -> V_22 . V_216 ) {
V_163 . V_215 = true ;
goto V_310;
} else if ( ! V_163 . V_313 && ( V_300 & V_301 ) ) {
V_163 . V_313 = true ;
goto V_310;
} else if ( ! V_163 . V_200 && T_1 -> V_22 . V_200 ) {
V_163 . V_200 = true ;
goto V_310;
} else if ( ! V_163 . V_77 &&
( T_1 -> V_22 . V_77 || T_1 -> V_22 . V_76 ) ) {
V_163 . V_77 = true ;
goto V_310;
} else if ( ! V_163 . V_162 ) {
V_163 . V_162 = true ;
goto V_315;
} else if ( ! V_163 . V_314 &&
( T_1 -> V_22 . V_118 &
( V_121 |
V_122 ) ) ) {
V_163 . V_314 = true ;
goto V_310;
}
V_326:
do {
while ( -- V_226 >= 0 ) {
F_91 ( F_71 ( T_1 , V_225 , V_226 ) ) ;
F_71 ( T_1 , V_225 , V_226 ) = - 1 ;
}
V_226 = V_222 ;
} while ( -- V_225 >= 0 );
return V_58 ;
}
void F_124 ( struct V_1 * T_1 , int V_221 , int V_222 )
{
if ( T_1 -> V_224 == NULL )
return;
F_90 ( T_1 , V_221 , V_222 ) ;
F_85 ( T_1 ) ;
}
int F_125 ( struct V_1 * T_1 ,
struct V_299 * V_234 )
{
return F_117 ( T_1 , V_234 , NULL ) ;
}
int F_126 ( struct V_1 * T_1 ,
struct V_296 * V_233 )
{
return F_117 ( T_1 , NULL , V_233 ) ;
}
static int F_127 ( const struct V_1 * T_1 ,
const union V_334 * V_335 ,
struct V_336 * V_337 )
{
T_3 type = T_1 -> V_22 . V_8 ;
const T_3 * V_338 = V_335 -> V_337 . V_338 ;
bool V_339 = T_1 -> V_340 ;
union V_341 V_342 ;
V_338 += ( ( V_335 -> V_343 . V_6 -
sizeof( V_335 -> V_343 ) ) / sizeof( T_3 ) ) - 1 ;
if ( type & V_13 ) {
V_337 -> V_64 = * V_338 ;
V_338 -- ;
}
if ( type & V_19 ) {
V_342 . V_344 = * V_338 ;
if ( V_339 ) {
V_342 . V_344 = F_128 ( V_342 . V_344 ) ;
V_342 . V_345 [ 0 ] = F_129 ( V_342 . V_345 [ 0 ] ) ;
}
V_337 -> V_225 = V_342 . V_345 [ 0 ] ;
V_338 -- ;
}
if ( type & V_20 ) {
V_337 -> V_346 = * V_338 ;
V_338 -- ;
}
if ( type & V_14 ) {
V_337 -> V_64 = * V_338 ;
V_338 -- ;
}
if ( type & V_17 ) {
V_337 -> time = * V_338 ;
V_338 -- ;
}
if ( type & V_16 ) {
V_342 . V_344 = * V_338 ;
if ( V_339 ) {
V_342 . V_344 = F_128 ( V_342 . V_344 ) ;
V_342 . V_345 [ 0 ] = F_129 ( V_342 . V_345 [ 0 ] ) ;
V_342 . V_345 [ 1 ] = F_129 ( V_342 . V_345 [ 1 ] ) ;
}
V_337 -> V_302 = V_342 . V_345 [ 0 ] ;
V_337 -> V_347 = V_342 . V_345 [ 1 ] ;
V_338 -- ;
}
return 0 ;
}
static inline bool F_130 ( const void * V_348 , T_12 V_349 , const void * V_350 ,
T_3 V_6 )
{
return V_6 > V_349 || V_350 + V_6 > V_348 ;
}
int F_131 ( struct V_1 * T_1 , union V_334 * V_335 ,
struct V_336 * V_351 )
{
T_3 type = T_1 -> V_22 . V_8 ;
bool V_339 = T_1 -> V_340 ;
const T_3 * V_338 ;
T_12 V_349 = V_335 -> V_343 . V_6 ;
const void * V_348 = ( void * ) V_335 + V_349 ;
T_3 V_352 ;
union V_341 V_342 ;
memset ( V_351 , 0 , sizeof( * V_351 ) ) ;
V_351 -> V_225 = V_351 -> V_302 = V_351 -> V_347 = - 1 ;
V_351 -> V_346 = V_351 -> V_64 = V_351 -> time = - 1ULL ;
V_351 -> V_137 = T_1 -> V_22 . V_49 ;
V_351 -> V_353 = V_335 -> V_343 . V_354 & V_355 ;
if ( V_335 -> V_343 . type != V_356 ) {
if ( ! T_1 -> V_22 . V_162 )
return 0 ;
return F_127 ( T_1 , V_335 , V_351 ) ;
}
V_338 = V_335 -> V_337 . V_338 ;
if ( T_1 -> V_26 + sizeof( V_335 -> V_343 ) > V_335 -> V_343 . V_6 )
return - V_357 ;
V_351 -> V_64 = - 1ULL ;
if ( type & V_13 ) {
V_351 -> V_64 = * V_338 ;
V_338 ++ ;
}
if ( type & V_15 ) {
V_351 -> V_358 = * V_338 ;
V_338 ++ ;
}
if ( type & V_16 ) {
V_342 . V_344 = * V_338 ;
if ( V_339 ) {
V_342 . V_344 = F_128 ( V_342 . V_344 ) ;
V_342 . V_345 [ 0 ] = F_129 ( V_342 . V_345 [ 0 ] ) ;
V_342 . V_345 [ 1 ] = F_129 ( V_342 . V_345 [ 1 ] ) ;
}
V_351 -> V_302 = V_342 . V_345 [ 0 ] ;
V_351 -> V_347 = V_342 . V_345 [ 1 ] ;
V_338 ++ ;
}
if ( type & V_17 ) {
V_351 -> time = * V_338 ;
V_338 ++ ;
}
V_351 -> V_82 = 0 ;
if ( type & V_18 ) {
V_351 -> V_82 = * V_338 ;
V_338 ++ ;
}
if ( type & V_14 ) {
V_351 -> V_64 = * V_338 ;
V_338 ++ ;
}
if ( type & V_20 ) {
V_351 -> V_346 = * V_338 ;
V_338 ++ ;
}
if ( type & V_19 ) {
V_342 . V_344 = * V_338 ;
if ( V_339 ) {
V_342 . V_344 = F_128 ( V_342 . V_344 ) ;
V_342 . V_345 [ 0 ] = F_129 ( V_342 . V_345 [ 0 ] ) ;
}
V_351 -> V_225 = V_342 . V_345 [ 0 ] ;
V_338 ++ ;
}
if ( type & V_48 ) {
V_351 -> V_137 = * V_338 ;
V_338 ++ ;
}
if ( type & V_359 ) {
T_3 V_30 = T_1 -> V_22 . V_30 ;
F_132 ( V_338 ) ;
if ( V_30 & V_170 )
V_351 -> V_360 . V_361 . V_298 = * V_338 ;
else
V_351 -> V_360 . V_362 . V_255 = * V_338 ;
V_338 ++ ;
if ( V_30 & V_209 ) {
F_132 ( V_338 ) ;
V_351 -> V_360 . V_363 = * V_338 ;
V_338 ++ ;
}
if ( V_30 & V_210 ) {
F_132 ( V_338 ) ;
V_351 -> V_360 . V_364 = * V_338 ;
V_338 ++ ;
}
if ( V_30 & V_170 ) {
const T_3 V_365 = V_366 /
sizeof( struct V_367 ) ;
if ( V_351 -> V_360 . V_361 . V_298 > V_365 )
return - V_357 ;
V_352 = V_351 -> V_360 . V_361 . V_298 *
sizeof( struct V_367 ) ;
F_133 ( V_338 , V_352 , V_349 ) ;
V_351 -> V_360 . V_361 . V_368 =
(struct V_367 * ) V_338 ;
V_338 = ( void * ) V_338 + V_352 ;
} else {
F_132 ( V_338 ) ;
V_351 -> V_360 . V_362 . V_64 = * V_338 ;
V_338 ++ ;
}
}
if ( type & V_369 ) {
const T_3 V_370 = V_366 / sizeof( T_3 ) ;
F_132 ( V_338 ) ;
V_351 -> V_156 = (struct V_371 * ) V_338 ++ ;
if ( V_351 -> V_156 -> V_298 > V_370 )
return - V_357 ;
V_352 = V_351 -> V_156 -> V_298 * sizeof( T_3 ) ;
F_133 ( V_338 , V_352 , V_349 ) ;
V_338 = ( void * ) V_338 + V_352 ;
}
if ( type & V_47 ) {
F_132 ( V_338 ) ;
V_342 . V_344 = * V_338 ;
if ( F_134 ( V_339 ,
L_56 ) ) {
V_342 . V_344 = F_128 ( V_342 . V_344 ) ;
V_342 . V_345 [ 0 ] = F_129 ( V_342 . V_345 [ 0 ] ) ;
V_342 . V_345 [ 1 ] = F_129 ( V_342 . V_345 [ 1 ] ) ;
}
V_351 -> V_372 = V_342 . V_345 [ 0 ] ;
V_338 = ( void * ) V_338 + sizeof( T_7 ) ;
F_133 ( V_338 , V_351 -> V_372 , V_349 ) ;
V_351 -> V_373 = ( void * ) V_338 ;
V_338 = ( void * ) V_338 + V_351 -> V_372 ;
}
if ( type & V_374 ) {
const T_3 V_375 = V_366 /
sizeof( struct V_376 ) ;
F_132 ( V_338 ) ;
V_351 -> V_116 = (struct V_116 * ) V_338 ++ ;
if ( V_351 -> V_116 -> V_298 > V_375 )
return - V_357 ;
V_352 = V_351 -> V_116 -> V_298 * sizeof( struct V_376 ) ;
F_133 ( V_338 , V_352 , V_349 ) ;
V_338 = ( void * ) V_338 + V_352 ;
}
if ( type & V_377 ) {
F_132 ( V_338 ) ;
V_351 -> V_378 . V_379 = * V_338 ;
V_338 ++ ;
if ( V_351 -> V_378 . V_379 ) {
T_3 V_9 = T_1 -> V_22 . V_126 ;
V_352 = F_135 ( V_9 ) * sizeof( T_3 ) ;
F_133 ( V_338 , V_352 , V_349 ) ;
V_351 -> V_378 . V_9 = V_9 ;
V_351 -> V_378 . V_380 = ( T_3 * ) V_338 ;
V_338 = ( void * ) V_338 + V_352 ;
}
}
if ( type & V_381 ) {
F_132 ( V_338 ) ;
V_352 = * V_338 ++ ;
V_351 -> V_382 . V_350 = ( ( char * ) ( V_338 - 1 )
- ( char * ) V_335 ) ;
if ( ! V_352 ) {
V_351 -> V_382 . V_6 = 0 ;
} else {
F_133 ( V_338 , V_352 , V_349 ) ;
V_351 -> V_382 . V_351 = ( char * ) V_338 ;
V_338 = ( void * ) V_338 + V_352 ;
F_132 ( V_338 ) ;
V_351 -> V_382 . V_6 = * V_338 ++ ;
if ( F_134 ( V_351 -> V_382 . V_6 > V_352 ,
L_57 ) )
return - V_357 ;
}
}
if ( type & V_383 ) {
F_132 ( V_338 ) ;
V_351 -> V_384 = * V_338 ;
V_338 ++ ;
}
V_351 -> V_385 = V_386 ;
if ( type & V_387 ) {
F_132 ( V_338 ) ;
V_351 -> V_385 = * V_338 ;
V_338 ++ ;
}
V_351 -> V_388 = 0 ;
if ( type & V_389 ) {
F_132 ( V_338 ) ;
V_351 -> V_388 = * V_338 ;
V_338 ++ ;
}
V_351 -> V_390 . V_379 = V_391 ;
if ( type & V_392 ) {
F_132 ( V_338 ) ;
V_351 -> V_390 . V_379 = * V_338 ;
V_338 ++ ;
if ( V_351 -> V_390 . V_379 != V_391 ) {
T_3 V_9 = T_1 -> V_22 . V_184 ;
V_352 = F_135 ( V_9 ) * sizeof( T_3 ) ;
F_133 ( V_338 , V_352 , V_349 ) ;
V_351 -> V_390 . V_9 = V_9 ;
V_351 -> V_390 . V_380 = ( T_3 * ) V_338 ;
V_338 = ( void * ) V_338 + V_352 ;
}
}
return 0 ;
}
T_2 F_136 ( const struct V_336 * V_337 , T_3 type ,
T_3 V_30 )
{
T_2 V_352 , V_91 = sizeof( struct V_393 ) ;
if ( type & V_13 )
V_91 += sizeof( T_3 ) ;
if ( type & V_15 )
V_91 += sizeof( T_3 ) ;
if ( type & V_16 )
V_91 += sizeof( T_3 ) ;
if ( type & V_17 )
V_91 += sizeof( T_3 ) ;
if ( type & V_18 )
V_91 += sizeof( T_3 ) ;
if ( type & V_14 )
V_91 += sizeof( T_3 ) ;
if ( type & V_20 )
V_91 += sizeof( T_3 ) ;
if ( type & V_19 )
V_91 += sizeof( T_3 ) ;
if ( type & V_48 )
V_91 += sizeof( T_3 ) ;
if ( type & V_359 ) {
V_91 += sizeof( T_3 ) ;
if ( V_30 & V_209 )
V_91 += sizeof( T_3 ) ;
if ( V_30 & V_210 )
V_91 += sizeof( T_3 ) ;
if ( V_30 & V_170 ) {
V_352 = V_337 -> V_360 . V_361 . V_298 *
sizeof( struct V_367 ) ;
V_91 += V_352 ;
} else {
V_91 += sizeof( T_3 ) ;
}
}
if ( type & V_369 ) {
V_352 = ( V_337 -> V_156 -> V_298 + 1 ) * sizeof( T_3 ) ;
V_91 += V_352 ;
}
if ( type & V_47 ) {
V_91 += sizeof( T_7 ) ;
V_91 += V_337 -> V_372 ;
}
if ( type & V_374 ) {
V_352 = V_337 -> V_116 -> V_298 * sizeof( struct V_376 ) ;
V_352 += sizeof( T_3 ) ;
V_91 += V_352 ;
}
if ( type & V_377 ) {
if ( V_337 -> V_378 . V_379 ) {
V_91 += sizeof( T_3 ) ;
V_352 = F_135 ( V_337 -> V_378 . V_9 ) * sizeof( T_3 ) ;
V_91 += V_352 ;
} else {
V_91 += sizeof( T_3 ) ;
}
}
if ( type & V_381 ) {
V_352 = V_337 -> V_382 . V_6 ;
V_91 += sizeof( T_3 ) ;
if ( V_352 ) {
V_91 += V_352 ;
V_91 += sizeof( T_3 ) ;
}
}
if ( type & V_383 )
V_91 += sizeof( T_3 ) ;
if ( type & V_387 )
V_91 += sizeof( T_3 ) ;
if ( type & V_389 )
V_91 += sizeof( T_3 ) ;
if ( type & V_392 ) {
if ( V_337 -> V_390 . V_379 ) {
V_91 += sizeof( T_3 ) ;
V_352 = F_135 ( V_337 -> V_390 . V_9 ) * sizeof( T_3 ) ;
V_91 += V_352 ;
} else {
V_91 += sizeof( T_3 ) ;
}
}
return V_91 ;
}
int F_137 ( union V_334 * V_335 , T_3 type ,
T_3 V_30 ,
const struct V_336 * V_337 ,
bool V_339 )
{
T_3 * V_338 ;
T_2 V_352 ;
union V_341 V_342 ;
V_338 = V_335 -> V_337 . V_338 ;
if ( type & V_13 ) {
* V_338 = V_337 -> V_64 ;
V_338 ++ ;
}
if ( type & V_15 ) {
* V_338 = V_337 -> V_358 ;
V_338 ++ ;
}
if ( type & V_16 ) {
V_342 . V_345 [ 0 ] = V_337 -> V_302 ;
V_342 . V_345 [ 1 ] = V_337 -> V_347 ;
if ( V_339 ) {
V_342 . V_345 [ 0 ] = F_129 ( V_342 . V_345 [ 0 ] ) ;
V_342 . V_345 [ 1 ] = F_129 ( V_342 . V_345 [ 1 ] ) ;
V_342 . V_344 = F_128 ( V_342 . V_344 ) ;
}
* V_338 = V_342 . V_344 ;
V_338 ++ ;
}
if ( type & V_17 ) {
* V_338 = V_337 -> time ;
V_338 ++ ;
}
if ( type & V_18 ) {
* V_338 = V_337 -> V_82 ;
V_338 ++ ;
}
if ( type & V_14 ) {
* V_338 = V_337 -> V_64 ;
V_338 ++ ;
}
if ( type & V_20 ) {
* V_338 = V_337 -> V_346 ;
V_338 ++ ;
}
if ( type & V_19 ) {
V_342 . V_345 [ 0 ] = V_337 -> V_225 ;
if ( V_339 ) {
V_342 . V_345 [ 0 ] = F_129 ( V_342 . V_345 [ 0 ] ) ;
V_342 . V_344 = F_128 ( V_342 . V_344 ) ;
}
* V_338 = V_342 . V_344 ;
V_338 ++ ;
}
if ( type & V_48 ) {
* V_338 = V_337 -> V_137 ;
V_338 ++ ;
}
if ( type & V_359 ) {
if ( V_30 & V_170 )
* V_338 = V_337 -> V_360 . V_361 . V_298 ;
else
* V_338 = V_337 -> V_360 . V_362 . V_255 ;
V_338 ++ ;
if ( V_30 & V_209 ) {
* V_338 = V_337 -> V_360 . V_363 ;
V_338 ++ ;
}
if ( V_30 & V_210 ) {
* V_338 = V_337 -> V_360 . V_364 ;
V_338 ++ ;
}
if ( V_30 & V_170 ) {
V_352 = V_337 -> V_360 . V_361 . V_298 *
sizeof( struct V_367 ) ;
memcpy ( V_338 , V_337 -> V_360 . V_361 . V_368 , V_352 ) ;
V_338 = ( void * ) V_338 + V_352 ;
} else {
* V_338 = V_337 -> V_360 . V_362 . V_64 ;
V_338 ++ ;
}
}
if ( type & V_369 ) {
V_352 = ( V_337 -> V_156 -> V_298 + 1 ) * sizeof( T_3 ) ;
memcpy ( V_338 , V_337 -> V_156 , V_352 ) ;
V_338 = ( void * ) V_338 + V_352 ;
}
if ( type & V_47 ) {
V_342 . V_345 [ 0 ] = V_337 -> V_372 ;
if ( F_134 ( V_339 ,
L_56 ) ) {
V_342 . V_345 [ 0 ] = F_129 ( V_342 . V_345 [ 0 ] ) ;
V_342 . V_345 [ 1 ] = F_129 ( V_342 . V_345 [ 1 ] ) ;
V_342 . V_344 = F_128 ( V_342 . V_344 ) ;
}
* V_338 = V_342 . V_344 ;
V_338 = ( void * ) V_338 + sizeof( T_7 ) ;
memcpy ( V_338 , V_337 -> V_373 , V_337 -> V_372 ) ;
V_338 = ( void * ) V_338 + V_337 -> V_372 ;
}
if ( type & V_374 ) {
V_352 = V_337 -> V_116 -> V_298 * sizeof( struct V_376 ) ;
V_352 += sizeof( T_3 ) ;
memcpy ( V_338 , V_337 -> V_116 , V_352 ) ;
V_338 = ( void * ) V_338 + V_352 ;
}
if ( type & V_377 ) {
if ( V_337 -> V_378 . V_379 ) {
* V_338 ++ = V_337 -> V_378 . V_379 ;
V_352 = F_135 ( V_337 -> V_378 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_338 , V_337 -> V_378 . V_380 , V_352 ) ;
V_338 = ( void * ) V_338 + V_352 ;
} else {
* V_338 ++ = 0 ;
}
}
if ( type & V_381 ) {
V_352 = V_337 -> V_382 . V_6 ;
* V_338 ++ = V_352 ;
if ( V_352 ) {
memcpy ( V_338 , V_337 -> V_382 . V_351 , V_352 ) ;
V_338 = ( void * ) V_338 + V_352 ;
* V_338 ++ = V_352 ;
}
}
if ( type & V_383 ) {
* V_338 = V_337 -> V_384 ;
V_338 ++ ;
}
if ( type & V_387 ) {
* V_338 = V_337 -> V_385 ;
V_338 ++ ;
}
if ( type & V_389 ) {
* V_338 = V_337 -> V_388 ;
V_338 ++ ;
}
if ( type & V_392 ) {
if ( V_337 -> V_390 . V_379 ) {
* V_338 ++ = V_337 -> V_390 . V_379 ;
V_352 = F_135 ( V_337 -> V_390 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_338 , V_337 -> V_390 . V_380 , V_352 ) ;
V_338 = ( void * ) V_338 + V_352 ;
} else {
* V_338 ++ = 0 ;
}
}
return 0 ;
}
struct V_394 * F_138 ( struct V_1 * T_1 , const char * V_32 )
{
return F_139 ( T_1 -> V_63 , V_32 ) ;
}
void * F_140 ( struct V_1 * T_1 , struct V_336 * V_337 ,
const char * V_32 )
{
struct V_394 * V_395 = F_138 ( T_1 , V_32 ) ;
int V_350 ;
if ( ! V_395 )
return NULL ;
V_350 = V_395 -> V_350 ;
if ( V_395 -> V_300 & V_396 ) {
V_350 = * ( int * ) ( V_337 -> V_373 + V_395 -> V_350 ) ;
V_350 &= 0xffff ;
}
return V_337 -> V_373 + V_350 ;
}
T_3 F_141 ( struct V_394 * V_395 , struct V_336 * V_337 ,
bool V_340 )
{
T_3 V_255 ;
void * V_397 = V_337 -> V_373 + V_395 -> V_350 ;
switch ( V_395 -> V_6 ) {
case 1 :
return * ( T_6 * ) V_397 ;
case 2 :
V_255 = * ( T_12 * ) V_397 ;
break;
case 4 :
V_255 = * ( T_7 * ) V_397 ;
break;
case 8 :
memcpy ( & V_255 , V_397 , sizeof( T_3 ) ) ;
break;
default:
return 0 ;
}
if ( ! V_340 )
return V_255 ;
switch ( V_395 -> V_6 ) {
case 2 :
return F_142 ( V_255 ) ;
case 4 :
return F_129 ( V_255 ) ;
case 8 :
return F_128 ( V_255 ) ;
default:
return 0 ;
}
return 0 ;
}
T_3 F_143 ( struct V_1 * T_1 , struct V_336 * V_337 ,
const char * V_32 )
{
struct V_394 * V_395 = F_138 ( T_1 , V_32 ) ;
if ( ! V_395 )
return 0 ;
return V_395 ? F_141 ( V_395 , V_337 , T_1 -> V_340 ) : 0 ;
}
bool F_144 ( struct V_1 * T_1 , int V_58 ,
char * V_398 , T_2 V_399 )
{
int V_400 ;
if ( ( V_58 == V_401 || V_58 == V_402 || V_58 == V_403 ) &&
T_1 -> V_22 . type == V_50 &&
T_1 -> V_22 . V_51 == V_52 ) {
F_38 ( V_398 , V_399 , L_9 ,
L_58 ) ;
T_1 -> V_22 . type = V_101 ;
T_1 -> V_22 . V_51 = V_404 ;
F_33 ( & T_1 -> V_32 ) ;
return true ;
} else if ( V_58 == V_405 && ! T_1 -> V_22 . V_53 &&
( V_400 = F_145 () ) > 1 ) {
const char * V_32 = F_50 ( T_1 ) ;
char * V_406 ;
if ( F_27 ( & V_406 , L_59 , V_32 , strchr ( V_32 , ':' ) ? L_1 : L_3 ) < 0 )
return false ;
if ( T_1 -> V_32 )
free ( T_1 -> V_32 ) ;
T_1 -> V_32 = V_406 ;
F_38 ( V_398 , V_399 ,
L_60 , V_400 ) ;
T_1 -> V_22 . V_53 = 1 ;
return true ;
}
return false ;
}
static bool F_146 ( const char * V_32 )
{
T_2 V_407 = strlen ( V_32 ) ;
T_13 * V_408 ;
struct V_409 * V_410 ;
int V_98 = - 1 ;
V_408 = F_147 ( F_148 () ) ;
if ( ! V_408 )
return false ;
while ( V_98 && ( V_410 = F_149 ( V_408 ) ) != NULL ) {
char V_411 [ V_412 ] ;
char * V_351 ;
T_2 V_6 ;
if ( ( V_410 -> V_413 != V_414 ) ||
! strcmp ( L_61 , V_410 -> V_415 ) ||
! strcmp ( L_62 , V_410 -> V_415 ) )
continue;
F_38 ( V_411 , sizeof( V_411 ) , L_63 ,
F_148 () , V_410 -> V_415 ) ;
if ( F_150 ( V_411 , & V_351 , & V_6 ) )
continue;
V_98 = strncmp ( V_32 , V_351 , V_407 ) ;
free ( V_351 ) ;
}
F_151 ( V_408 ) ;
return V_98 ? false : true ;
}
int F_152 ( struct V_1 * T_1 , struct V_159 * V_159 ,
int V_58 , char * V_398 , T_2 V_6 )
{
char V_416 [ V_417 ] ;
int V_418 = 0 ;
switch ( V_58 ) {
case V_419 :
case V_405 :
if ( V_58 == V_419 )
V_418 = F_38 ( V_398 , V_6 ,
L_64 ,
F_50 ( T_1 ) ) ;
return F_38 ( V_398 + V_418 , V_6 - V_418 ,
L_65
L_66
L_67
L_68
L_69
L_70
L_71
L_72
L_73
L_74
L_75 ,
V_159 -> V_223 ? L_76 : L_1 ,
F_145 () ) ;
case V_401 :
return F_38 ( V_398 , V_6 , L_77 ,
F_50 ( T_1 ) ) ;
case V_327 :
return F_38 ( V_398 , V_6 , L_9 ,
L_78
L_79
L_80
L_81 ) ;
case V_59 :
if ( ( T_1 -> V_22 . V_8 & V_369 ) != 0 &&
F_153 ( L_82 , V_420 ) == 0 )
return F_38 ( V_398 , V_6 ,
L_83
L_84
L_85 , V_421 ) ;
break;
case V_403 :
if ( V_159 -> V_422 )
return F_38 ( V_398 , V_6 , L_9 ,
L_86 ) ;
break;
case V_423 :
if ( T_1 -> V_22 . V_49 != 0 )
return F_38 ( V_398 , V_6 , L_9 ,
L_87 ) ;
if ( T_1 -> V_22 . V_55 )
return F_38 ( V_398 , V_6 , L_9 ,
L_88 ) ;
#if F_154 ( V_424 ) || F_154 ( V_425 )
if ( T_1 -> V_22 . type == V_50 )
return F_38 ( V_398 , V_6 , L_9 ,
L_89
L_90 ) ;
#endif
break;
case V_426 :
if ( F_146 ( L_91 ) )
return F_38 ( V_398 , V_6 ,
L_92
L_93 ) ;
break;
case V_7 :
if ( T_1 -> V_22 . V_152 && V_163 . V_152 )
return F_38 ( V_398 , V_6 , L_94 ) ;
if ( V_163 . V_215 )
return F_38 ( V_398 , V_6 , L_95 ) ;
if ( V_163 . V_311 )
return F_38 ( V_398 , V_6 , L_96 , V_215 ) ;
break;
default:
break;
}
return F_38 ( V_398 , V_6 ,
L_97
L_98
L_99 ,
V_58 , F_155 ( V_58 , V_416 , sizeof( V_416 ) ) ,
F_50 ( T_1 ) ) ;
}
char * F_156 ( struct V_1 * T_1 )
{
if ( T_1 && T_1 -> V_38 && T_1 -> V_38 -> V_427 )
return T_1 -> V_38 -> V_427 -> V_428 ;
return NULL ;
}
