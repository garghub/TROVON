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
} ;
struct V_1 * T_1 ;
F_23 ( & V_22 ) ;
V_22 . V_49 = 1 ;
F_24 ( & V_22 ) ;
V_22 . V_49 = 0 ;
T_1 = F_25 ( & V_22 ) ;
if ( T_1 == NULL )
goto V_53;
if ( F_26 ( & T_1 -> V_32 , L_2 ,
V_22 . V_54 ? V_22 . V_54 + 1 : 0 , L_3 ) < 0 )
goto V_55;
V_53:
return T_1 ;
V_55:
F_27 ( T_1 ) ;
T_1 = NULL ;
goto V_53;
}
struct V_1 * F_28 ( const char * V_56 , const char * V_32 , int V_12 )
{
struct V_1 * T_1 = F_20 ( V_5 . V_6 ) ;
int V_57 = - V_58 ;
if ( T_1 == NULL ) {
goto V_59;
} else {
struct V_33 V_22 = {
. type = V_60 ,
. V_8 = ( V_47 | V_17 |
V_19 | V_48 ) ,
} ;
if ( F_26 ( & T_1 -> V_32 , L_4 , V_56 , V_32 ) < 0 )
goto V_61;
T_1 -> V_62 = F_29 ( V_56 , V_32 ) ;
if ( F_30 ( T_1 -> V_62 ) ) {
V_57 = F_31 ( T_1 -> V_62 ) ;
goto V_61;
}
F_23 ( & V_22 ) ;
V_22 . V_51 = T_1 -> V_62 -> V_63 ;
V_22 . V_49 = 1 ;
F_17 ( T_1 , & V_22 , V_12 ) ;
}
return T_1 ;
V_61:
F_32 ( & T_1 -> V_32 ) ;
free ( T_1 ) ;
V_59:
return F_33 ( V_57 ) ;
}
static const char * F_34 ( T_3 V_51 )
{
if ( V_51 < V_64 && V_65 [ V_51 ] )
return V_65 [ V_51 ] ;
return L_5 ;
}
static int F_35 ( struct V_1 * T_1 , char * V_66 , T_2 V_6 )
{
int V_67 = 0 , V_68 = 0 ;
struct V_33 * V_22 = & T_1 -> V_22 ;
bool V_69 = false ;
#define F_36 ( T_4 , T_5 ) do { \
if (!attr->exclude_##context) { \
if (!colon) colon = ++r; \
r += scnprintf(bf + r, size - r, "%c", mod); \
} } while(0)
if ( V_22 -> V_70 || V_22 -> V_71 || V_22 -> V_72 ) {
F_36 ( V_73 , 'k' ) ;
F_36 ( V_74 , 'u' ) ;
F_36 ( V_75 , 'h' ) ;
V_69 = true ;
}
if ( V_22 -> V_54 ) {
if ( ! V_67 )
V_67 = ++ V_68 ;
V_68 += F_37 ( V_66 + V_68 , V_6 - V_68 , L_6 , V_22 -> V_54 , L_7 ) ;
V_69 = true ;
}
if ( V_22 -> V_76 || V_22 -> V_77 == V_69 ) {
F_36 ( V_78 , 'H' ) ;
F_36 ( V_79 , 'G' ) ;
}
#undef F_36
if ( V_67 )
V_66 [ V_67 - 1 ] = ':' ;
return V_68 ;
}
static int F_38 ( struct V_1 * T_1 , char * V_66 , T_2 V_6 )
{
int V_68 = F_37 ( V_66 , V_6 , L_8 , F_34 ( T_1 -> V_22 . V_51 ) ) ;
return V_68 + F_35 ( T_1 , V_66 + V_68 , V_6 - V_68 ) ;
}
static const char * F_39 ( T_3 V_51 )
{
if ( V_51 < V_80 && V_81 [ V_51 ] )
return V_81 [ V_51 ] ;
return L_9 ;
}
static int F_40 ( struct V_1 * T_1 , char * V_66 , T_2 V_6 )
{
int V_68 = F_37 ( V_66 , V_6 , L_8 , F_39 ( T_1 -> V_22 . V_51 ) ) ;
return V_68 + F_35 ( T_1 , V_66 + V_68 , V_6 - V_68 ) ;
}
static int F_41 ( char * V_66 , T_2 V_6 , T_3 V_82 , T_3 type )
{
int V_68 ;
V_68 = F_37 ( V_66 , V_6 , L_10 V_83 L_11 , V_82 ) ;
if ( type & V_84 )
V_68 += F_37 ( V_66 + V_68 , V_6 - V_68 , L_12 ) ;
if ( type & V_85 )
V_68 += F_37 ( V_66 + V_68 , V_6 - V_68 , L_13 ) ;
if ( type & V_86 )
V_68 += F_37 ( V_66 + V_68 , V_6 - V_68 , L_14 ) ;
return V_68 ;
}
static int F_42 ( struct V_1 * T_1 , char * V_66 , T_2 V_6 )
{
struct V_33 * V_22 = & T_1 -> V_22 ;
int V_68 = F_41 ( V_66 , V_6 , V_22 -> V_87 , V_22 -> V_88 ) ;
return V_68 + F_35 ( T_1 , V_66 + V_68 , V_6 - V_68 ) ;
}
bool F_43 ( T_6 type , T_6 V_89 )
{
if ( V_90 [ type ] & F_44 ( V_89 ) )
return true ;
else
return false ;
}
int F_45 ( T_6 type , T_6 V_89 , T_6 V_91 ,
char * V_66 , T_2 V_6 )
{
if ( V_91 ) {
return F_37 ( V_66 , V_6 , L_15 , V_92 [ type ] [ 0 ] ,
V_93 [ V_89 ] [ 0 ] ,
V_94 [ V_91 ] [ 0 ] ) ;
}
return F_37 ( V_66 , V_6 , L_16 , V_92 [ type ] [ 0 ] ,
V_93 [ V_89 ] [ 1 ] ) ;
}
static int F_46 ( T_3 V_51 , char * V_66 , T_2 V_6 )
{
T_6 V_89 , V_91 , type = ( V_51 >> 0 ) & 0xff ;
const char * V_57 = L_17 ;
if ( type >= V_95 )
goto V_59;
V_89 = ( V_51 >> 8 ) & 0xff ;
V_57 = L_18 ;
if ( V_89 >= V_96 )
goto V_59;
V_91 = ( V_51 >> 16 ) & 0xff ;
V_57 = L_19 ;
if ( V_91 >= V_97 )
goto V_59;
V_57 = L_20 ;
if ( ! F_43 ( type , V_89 ) )
goto V_59;
return F_45 ( type , V_89 , V_91 , V_66 , V_6 ) ;
V_59:
return F_37 ( V_66 , V_6 , L_8 , V_57 ) ;
}
static int F_47 ( struct V_1 * T_1 , char * V_66 , T_2 V_6 )
{
int V_98 = F_46 ( T_1 -> V_22 . V_51 , V_66 , V_6 ) ;
return V_98 + F_35 ( T_1 , V_66 + V_98 , V_6 - V_98 ) ;
}
static int F_48 ( struct V_1 * T_1 , char * V_66 , T_2 V_6 )
{
int V_98 = F_37 ( V_66 , V_6 , L_21 V_83 , T_1 -> V_22 . V_51 ) ;
return V_98 + F_35 ( T_1 , V_66 + V_98 , V_6 - V_98 ) ;
}
const char * F_49 ( struct V_1 * T_1 )
{
char V_66 [ 128 ] ;
if ( T_1 -> V_32 )
return T_1 -> V_32 ;
switch ( T_1 -> V_22 . type ) {
case V_99 :
F_48 ( T_1 , V_66 , sizeof( V_66 ) ) ;
break;
case V_50 :
F_38 ( T_1 , V_66 , sizeof( V_66 ) ) ;
break;
case V_100 :
F_47 ( T_1 , V_66 , sizeof( V_66 ) ) ;
break;
case V_101 :
F_40 ( T_1 , V_66 , sizeof( V_66 ) ) ;
break;
case V_60 :
F_37 ( V_66 , sizeof( V_66 ) , L_8 , L_22 ) ;
break;
case V_102 :
F_42 ( T_1 , V_66 , sizeof( V_66 ) ) ;
break;
default:
F_37 ( V_66 , sizeof( V_66 ) , L_23 ,
T_1 -> V_22 . type ) ;
break;
}
T_1 -> V_32 = F_50 ( V_66 ) ;
return T_1 -> V_32 ? : L_24 ;
}
const char * F_51 ( struct V_1 * T_1 )
{
return T_1 -> V_103 ? : L_25 ;
}
int F_52 ( struct V_1 * T_1 , char * V_104 , T_2 V_6 )
{
int V_98 ;
struct V_1 * V_105 ;
const char * V_103 = F_51 ( T_1 ) ;
V_98 = F_37 ( V_104 , V_6 , L_8 , V_103 ) ;
V_98 += F_37 ( V_104 + V_98 , V_6 - V_98 , L_26 ,
F_49 ( T_1 ) ) ;
F_53 (pos, evsel)
V_98 += F_37 ( V_104 + V_98 , V_6 - V_98 , L_27 ,
F_49 ( V_105 ) ) ;
V_98 += F_37 ( V_104 + V_98 , V_6 - V_98 , L_28 ) ;
return V_98 ;
}
void F_54 ( struct V_1 * T_1 ,
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
F_55 ( L_29
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
F_55 ( L_32
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
F_56 ( L_33
L_34 ) ;
}
}
if ( V_110 ) {
F_56 ( L_35 ) ;
V_22 -> V_130 = 1 ;
}
}
static void
F_57 ( struct V_1 * T_1 ,
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
static void F_58 ( struct V_1 * T_1 ,
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
F_59 (term, config_terms, list) {
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
F_60 ( V_132 -> V_136 . V_145 ,
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
if ( F_61 ( V_134 , & V_109 ) ) {
F_62 ( L_38
L_39 ,
T_1 -> V_32 ) ;
return;
}
}
}
if ( V_129 > 0 ) {
V_129 = F_63 ( V_129 , sizeof( T_3 ) ) ;
V_109 . V_129 = V_129 ;
}
if ( V_108 . V_154 )
F_57 ( T_1 , & V_108 ) ;
if ( V_109 . V_154 )
F_54 ( T_1 , V_107 , & V_109 ) ;
}
}
void F_64 ( struct V_1 * T_1 , struct V_106 * V_107 ,
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
F_54 ( T_1 , V_107 , V_156 ) ;
if ( V_107 -> V_183 ) {
V_22 -> V_184 = V_107 -> V_183 ;
F_14 ( T_1 , V_185 ) ;
}
if ( F_65 ( & V_107 -> V_159 ) || V_107 -> V_186 )
F_14 ( T_1 , V_187 ) ;
if ( V_107 -> V_137 )
F_14 ( T_1 , V_175 ) ;
if ( V_107 -> V_188 &&
( ! V_163 . V_162 &&
( ! V_107 -> V_164 || F_65 ( & V_107 -> V_159 ) || V_158 ||
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
if ( F_66 ( T_1 ) )
V_22 -> V_211 = 1 ;
if ( F_67 ( & V_107 -> V_159 ) && F_66 ( T_1 ) &&
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
F_24 ( V_22 ) ;
if ( V_107 -> V_218 ) {
V_22 -> V_70 = 1 ;
V_22 -> V_71 = 0 ;
}
if ( V_107 -> V_219 ) {
V_22 -> V_70 = 0 ;
V_22 -> V_71 = 1 ;
}
F_58 ( T_1 , V_107 ) ;
T_1 -> V_220 = V_107 -> V_220 ;
}
static int F_68 ( struct V_1 * T_1 , int V_221 , int V_222 )
{
if ( T_1 -> V_223 )
V_222 = 1 ;
T_1 -> V_224 = F_69 ( V_221 , V_222 , sizeof( int ) ) ;
if ( T_1 -> V_224 ) {
int V_225 , V_226 ;
for ( V_225 = 0 ; V_225 < V_221 ; V_225 ++ ) {
for ( V_226 = 0 ; V_226 < V_222 ; V_226 ++ ) {
F_70 ( T_1 , V_225 , V_226 ) = - 1 ;
}
}
}
return T_1 -> V_224 != NULL ? 0 : - V_58 ;
}
static int F_71 ( struct V_1 * T_1 , int V_221 , int V_222 ,
int V_227 , void * V_228 )
{
int V_225 , V_226 ;
if ( T_1 -> V_223 )
V_222 = 1 ;
for ( V_225 = 0 ; V_225 < V_221 ; V_225 ++ ) {
for ( V_226 = 0 ; V_226 < V_222 ; V_226 ++ ) {
int V_224 = F_70 ( T_1 , V_225 , V_226 ) ,
V_57 = F_72 ( V_224 , V_227 , V_228 ) ;
if ( V_57 )
return V_57 ;
}
}
return 0 ;
}
int F_73 ( struct V_1 * T_1 , int V_221 , int V_222 ,
const char * V_229 )
{
return F_71 ( T_1 , V_221 , V_222 ,
V_230 ,
( void * ) V_229 ) ;
}
int F_74 ( struct V_1 * T_1 , const char * V_229 )
{
char * V_231 = F_50 ( V_229 ) ;
if ( V_231 != NULL ) {
free ( T_1 -> V_229 ) ;
T_1 -> V_229 = V_231 ;
return 0 ;
}
return - 1 ;
}
static int F_75 ( struct V_1 * T_1 ,
const char * V_232 , const char * V_229 )
{
char * V_231 ;
if ( T_1 -> V_229 == NULL )
return F_74 ( T_1 , V_229 ) ;
if ( F_26 ( & V_231 , V_232 , T_1 -> V_229 , V_229 ) > 0 ) {
free ( T_1 -> V_229 ) ;
T_1 -> V_229 = V_231 ;
return 0 ;
}
return - 1 ;
}
int F_76 ( struct V_1 * T_1 , const char * V_229 )
{
return F_75 ( T_1 , L_40 , V_229 ) ;
}
int F_77 ( struct V_1 * T_1 , const char * V_229 )
{
return F_75 ( T_1 , L_41 , V_229 ) ;
}
int F_78 ( struct V_1 * T_1 )
{
int V_222 = F_79 ( T_1 -> V_233 ) ;
int V_221 = F_80 ( T_1 -> V_234 ) ;
return F_71 ( T_1 , V_221 , V_222 ,
V_235 ,
0 ) ;
}
int F_81 ( struct V_1 * T_1 )
{
int V_222 = F_79 ( T_1 -> V_233 ) ;
int V_221 = F_80 ( T_1 -> V_234 ) ;
return F_71 ( T_1 , V_221 , V_222 ,
V_236 ,
0 ) ;
}
int F_82 ( struct V_1 * T_1 , int V_221 , int V_222 )
{
if ( V_221 == 0 || V_222 == 0 )
return 0 ;
if ( T_1 -> V_223 )
V_222 = 1 ;
T_1 -> V_237 = F_69 ( V_221 , V_222 , sizeof( struct V_238 ) ) ;
if ( T_1 -> V_237 == NULL )
return - V_58 ;
T_1 -> V_63 = F_20 ( V_221 * V_222 * sizeof( T_3 ) ) ;
if ( T_1 -> V_63 == NULL ) {
F_83 ( T_1 -> V_237 ) ;
T_1 -> V_237 = NULL ;
return - V_58 ;
}
return 0 ;
}
static void F_84 ( struct V_1 * T_1 )
{
F_83 ( T_1 -> V_224 ) ;
T_1 -> V_224 = NULL ;
}
static void F_85 ( struct V_1 * T_1 )
{
F_83 ( T_1 -> V_237 ) ;
T_1 -> V_237 = NULL ;
F_32 ( & T_1 -> V_63 ) ;
}
static void F_86 ( struct V_1 * T_1 )
{
struct V_131 * V_132 , * V_239 ;
F_87 (term, h, &evsel->config_terms, list) {
F_88 ( & V_132 -> V_240 ) ;
free ( V_132 ) ;
}
}
void F_89 ( struct V_1 * T_1 , int V_221 , int V_222 )
{
int V_225 , V_226 ;
if ( T_1 -> V_223 )
V_222 = 1 ;
for ( V_225 = 0 ; V_225 < V_221 ; V_225 ++ )
for ( V_226 = 0 ; V_226 < V_222 ; ++ V_226 ) {
F_90 ( F_70 ( T_1 , V_225 , V_226 ) ) ;
F_70 ( T_1 , V_225 , V_226 ) = - 1 ;
}
}
void F_91 ( struct V_1 * T_1 )
{
assert ( F_92 ( & T_1 -> V_40 ) ) ;
assert ( T_1 -> V_38 == NULL ) ;
F_84 ( T_1 ) ;
F_85 ( T_1 ) ;
F_86 ( T_1 ) ;
F_93 ( T_1 -> V_241 ) ;
F_94 ( T_1 -> V_234 ) ;
F_94 ( T_1 -> V_242 ) ;
F_95 ( T_1 -> V_233 ) ;
F_32 ( & T_1 -> V_103 ) ;
F_32 ( & T_1 -> V_32 ) ;
V_5 . F_5 ( T_1 ) ;
}
void F_27 ( struct V_1 * T_1 )
{
F_91 ( T_1 ) ;
free ( T_1 ) ;
}
void F_96 ( struct V_1 * T_1 , int V_225 , int V_226 ,
struct V_243 * V_244 )
{
struct V_243 V_245 ;
if ( ! T_1 -> V_246 )
return;
if ( V_225 == - 1 ) {
V_245 = T_1 -> V_246 -> V_247 ;
T_1 -> V_246 -> V_247 = * V_244 ;
} else {
V_245 = * F_97 ( T_1 -> V_246 , V_225 , V_226 ) ;
* F_97 ( T_1 -> V_246 , V_225 , V_226 ) = * V_244 ;
}
V_244 -> V_136 = V_244 -> V_136 - V_245 . V_136 ;
V_244 -> V_248 = V_244 -> V_248 - V_245 . V_248 ;
V_244 -> V_249 = V_244 -> V_249 - V_245 . V_249 ;
}
void F_98 ( struct V_243 * V_244 ,
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
int F_99 ( struct V_1 * T_1 , int V_225 , int V_226 ,
struct V_243 * V_244 )
{
memset ( V_244 , 0 , sizeof( * V_244 ) ) ;
if ( F_70 ( T_1 , V_225 , V_226 ) < 0 )
return - V_7 ;
if ( F_100 ( F_70 ( T_1 , V_225 , V_226 ) , V_244 , sizeof( * V_244 ) ) <= 0 )
return - V_252 ;
return 0 ;
}
int F_101 ( struct V_1 * T_1 ,
int V_225 , int V_226 , bool V_37 )
{
struct V_243 V_244 ;
T_2 V_253 = V_37 ? 3 : 1 ;
if ( F_70 ( T_1 , V_225 , V_226 ) < 0 )
return - V_7 ;
if ( T_1 -> V_254 == NULL && F_102 ( T_1 , V_225 + 1 , V_226 + 1 ) < 0 )
return - V_58 ;
if ( F_100 ( F_70 ( T_1 , V_225 , V_226 ) , & V_244 , V_253 * sizeof( T_3 ) ) <= 0 )
return - V_252 ;
F_96 ( T_1 , V_225 , V_226 , & V_244 ) ;
F_98 ( & V_244 , V_37 , NULL ) ;
* F_97 ( T_1 -> V_254 , V_225 , V_226 ) = V_244 ;
return 0 ;
}
static int F_103 ( struct V_1 * T_1 , int V_225 , int V_226 )
{
struct V_1 * V_35 = T_1 -> V_35 ;
int V_224 ;
if ( F_66 ( T_1 ) )
return - 1 ;
F_104 ( ! V_35 -> V_224 ) ;
V_224 = F_70 ( V_35 , V_225 , V_226 ) ;
F_104 ( V_224 == - 1 ) ;
return V_224 ;
}
static void F_105 ( char * V_104 , T_2 V_6 , T_3 V_255 , struct V_256 * V_257 )
{
bool V_258 = true ;
int V_11 = 0 ;
do {
if ( V_255 & V_257 [ V_11 ] . V_25 ) {
V_104 += F_37 ( V_104 , V_6 , L_42 , V_258 ? L_1 : L_43 , V_257 [ V_11 ] . V_32 ) ;
V_258 = false ;
}
} while ( V_257 [ ++ V_11 ] . V_32 != NULL );
}
static void F_106 ( char * V_104 , T_2 V_6 , T_3 V_255 )
{
#define F_107 ( T_9 ) { PERF_SAMPLE_##n, #n }
struct V_256 V_257 [] = {
F_107 ( V_165 ) , F_107 ( V_166 ) , F_107 ( TIME ) , F_107 ( V_180 ) ,
F_107 ( V_168 ) , F_107 ( V_111 ) , F_107 ( V_28 ) , F_107 ( V_187 ) ,
F_107 ( V_175 ) , F_107 ( V_259 ) , F_107 ( V_191 ) ,
F_107 ( V_117 ) , F_107 ( V_124 ) , F_107 ( V_125 ) ,
F_107 ( V_29 ) , F_107 ( V_185 ) , F_107 ( V_192 ) ,
F_107 ( V_197 ) ,
{ . V_32 = NULL , }
} ;
#undef F_107
F_105 ( V_104 , V_6 , V_255 , V_257 ) ;
}
static void F_108 ( char * V_104 , T_2 V_6 , T_3 V_255 )
{
#define F_107 ( T_9 ) { PERF_SAMPLE_BRANCH_##n, #n }
struct V_256 V_257 [] = {
F_107 ( V_260 ) , F_107 ( V_261 ) , F_107 ( V_262 ) , F_107 ( V_263 ) ,
F_107 ( V_264 ) , F_107 ( V_265 ) , F_107 ( V_266 ) ,
F_107 ( V_267 ) , F_107 ( V_268 ) , F_107 ( V_269 ) ,
F_107 ( V_270 ) , F_107 ( V_271 ) , F_107 ( V_272 ) ,
F_107 ( V_273 ) , F_107 ( V_274 ) , F_107 ( V_275 ) ,
{ . V_32 = NULL , }
} ;
#undef F_107
F_105 ( V_104 , V_6 , V_255 , V_257 ) ;
}
static void F_109 ( char * V_104 , T_2 V_6 , T_3 V_255 )
{
#define F_107 ( T_9 ) { PERF_FORMAT_##n, #n }
struct V_256 V_257 [] = {
F_107 ( V_276 ) , F_107 ( V_277 ) ,
F_107 ( V_28 ) , F_107 ( V_278 ) ,
{ . V_32 = NULL , }
} ;
#undef F_107
F_105 ( V_104 , V_6 , V_255 , V_257 ) ;
}
int F_110 ( T_10 * V_279 , struct V_33 * V_22 ,
T_11 V_280 , void * V_281 )
{
char V_104 [ V_282 ] ;
int V_98 = 0 ;
F_111 ( type , V_283 ) ;
F_111 ( V_6 , V_283 ) ;
F_111 ( V_51 , V_284 ) ;
F_112 ( L_44 , V_49 , V_283 ) ;
F_111 ( V_8 , V_285 ) ;
F_111 ( V_30 , V_286 ) ;
F_111 ( V_211 , V_283 ) ;
F_111 ( V_150 , V_283 ) ;
F_111 ( V_287 , V_283 ) ;
F_111 ( V_288 , V_283 ) ;
F_111 ( V_71 , V_283 ) ;
F_111 ( V_70 , V_283 ) ;
F_111 ( V_72 , V_283 ) ;
F_111 ( V_289 , V_283 ) ;
F_111 ( V_199 , V_283 ) ;
F_111 ( V_201 , V_283 ) ;
F_111 ( V_138 , V_283 ) ;
F_111 ( V_178 , V_283 ) ;
F_111 ( V_213 , V_283 ) ;
F_111 ( V_198 , V_283 ) ;
F_111 ( V_194 , V_283 ) ;
F_111 ( V_54 , V_283 ) ;
F_111 ( V_181 , V_283 ) ;
F_111 ( V_162 , V_283 ) ;
F_111 ( V_76 , V_283 ) ;
F_111 ( V_77 , V_283 ) ;
F_111 ( V_290 , V_283 ) ;
F_111 ( V_130 , V_283 ) ;
F_111 ( V_200 , V_283 ) ;
F_111 ( V_291 , V_283 ) ;
F_111 ( V_216 , V_283 ) ;
F_111 ( V_205 , V_283 ) ;
F_111 ( V_152 , V_283 ) ;
F_112 ( L_45 , V_195 , V_283 ) ;
F_111 ( V_88 , V_283 ) ;
F_112 ( L_46 , V_87 , V_284 ) ;
F_112 ( L_47 , V_292 , V_284 ) ;
F_111 ( V_118 , V_293 ) ;
F_111 ( V_126 , V_284 ) ;
F_111 ( V_128 , V_283 ) ;
F_111 ( V_215 , V_294 ) ;
F_111 ( V_184 , V_284 ) ;
F_111 ( V_295 , V_283 ) ;
F_111 ( V_112 , V_283 ) ;
return V_98 ;
}
static bool V_220 ( struct V_1 * T_1 ,
struct V_296 * V_233 ,
int V_226 , int V_57 )
{
if ( ! T_1 -> V_220 )
return false ;
if ( T_1 -> V_223 )
return false ;
if ( V_57 != - V_297 )
return false ;
if ( V_233 -> V_298 == 1 )
return false ;
if ( F_113 ( V_233 , V_226 ) )
return false ;
F_55 ( L_48 ,
F_114 ( V_233 , V_226 ) ) ;
return true ;
}
int F_115 ( struct V_1 * T_1 , struct V_299 * V_234 ,
struct V_296 * V_233 )
{
int V_225 , V_226 , V_222 ;
unsigned long V_300 = V_301 ;
int V_302 = - 1 , V_57 ;
enum { V_303 , V_304 , V_305 } V_306 = V_303 ;
if ( V_163 . V_152 && T_1 -> V_22 . V_152 )
return - V_7 ;
if ( V_234 == NULL ) {
static struct V_299 * V_307 ;
if ( V_307 == NULL ) {
V_307 = F_116 () ;
if ( V_307 == NULL )
return - V_58 ;
}
V_234 = V_307 ;
}
if ( V_233 == NULL ) {
static struct V_296 * V_308 ;
if ( V_308 == NULL ) {
V_308 = F_117 ( - 1 ) ;
if ( V_308 == NULL )
return - V_58 ;
}
V_233 = V_308 ;
}
if ( T_1 -> V_223 )
V_222 = 1 ;
else
V_222 = V_233 -> V_298 ;
if ( T_1 -> V_224 == NULL &&
F_68 ( T_1 , V_234 -> V_298 , V_222 ) < 0 )
return - V_58 ;
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
fprintf ( V_317 , L_49 , V_318 ) ;
fprintf ( V_317 , L_50 ) ;
F_110 ( V_317 , & T_1 -> V_22 , V_319 , NULL ) ;
fprintf ( V_317 , L_49 , V_318 ) ;
}
for ( V_225 = 0 ; V_225 < V_234 -> V_298 ; V_225 ++ ) {
for ( V_226 = 0 ; V_226 < V_222 ; V_226 ++ ) {
int V_224 , V_320 ;
if ( ! T_1 -> V_241 && ! T_1 -> V_223 )
V_302 = F_114 ( V_233 , V_226 ) ;
V_320 = F_103 ( T_1 , V_225 , V_226 ) ;
V_321:
F_118 ( L_51 ,
V_302 , V_234 -> V_322 [ V_225 ] , V_320 , V_300 ) ;
V_224 = F_119 ( & T_1 -> V_22 , V_302 , V_234 -> V_322 [ V_225 ] ,
V_320 , V_300 ) ;
F_70 ( T_1 , V_225 , V_226 ) = V_224 ;
if ( V_224 < 0 ) {
V_57 = - V_252 ;
if ( V_220 ( T_1 , V_233 , V_226 , V_57 ) ) {
V_222 -- ;
V_226 -- ;
V_57 = 0 ;
continue;
}
F_118 ( L_52 ,
V_57 ) ;
goto V_323;
}
F_118 ( L_53 , V_224 ) ;
if ( T_1 -> V_39 >= 0 ) {
int V_324 = V_224 ;
int V_39 = T_1 -> V_39 ;
V_57 = F_72 ( V_324 ,
V_325 ,
V_39 ) ;
if ( V_57 && V_252 != V_326 ) {
F_62 ( L_54 ,
V_39 , strerror ( V_252 ) ) ;
V_57 = - V_7 ;
goto V_327;
}
}
V_306 = V_303 ;
if ( V_163 . V_215 ||
V_163 . V_311 ) {
V_57 = - V_7 ;
goto V_327;
}
}
}
return 0 ;
V_323:
if ( V_57 == - V_328 && V_306 < V_305 ) {
struct V_329 V_330 ;
int V_331 = V_252 ;
if ( F_120 ( V_332 , & V_330 ) == 0 ) {
if ( V_306 == V_303 )
V_330 . V_333 = V_330 . V_334 ;
else {
V_330 . V_333 = V_330 . V_334 + 1000 ;
V_330 . V_334 = V_330 . V_333 ;
}
if ( F_121 ( V_332 , & V_330 ) == 0 ) {
V_306 ++ ;
V_252 = V_331 ;
goto V_321;
}
}
V_252 = V_331 ;
}
if ( V_57 != - V_7 || V_225 > 0 || V_226 > 0 )
goto V_327;
if ( ! V_163 . V_152 && T_1 -> V_22 . V_152 ) {
V_163 . V_152 = true ;
goto V_327;
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
V_327:
do {
while ( -- V_226 >= 0 ) {
F_90 ( F_70 ( T_1 , V_225 , V_226 ) ) ;
F_70 ( T_1 , V_225 , V_226 ) = - 1 ;
}
V_226 = V_222 ;
} while ( -- V_225 >= 0 );
return V_57 ;
}
void F_122 ( struct V_1 * T_1 , int V_221 , int V_222 )
{
if ( T_1 -> V_224 == NULL )
return;
F_89 ( T_1 , V_221 , V_222 ) ;
F_84 ( T_1 ) ;
}
int F_123 ( struct V_1 * T_1 ,
struct V_299 * V_234 )
{
return F_115 ( T_1 , V_234 , NULL ) ;
}
int F_124 ( struct V_1 * T_1 ,
struct V_296 * V_233 )
{
return F_115 ( T_1 , NULL , V_233 ) ;
}
static int F_125 ( const struct V_1 * T_1 ,
const union V_335 * V_336 ,
struct V_337 * V_338 )
{
T_3 type = T_1 -> V_22 . V_8 ;
const T_3 * V_339 = V_336 -> V_338 . V_339 ;
bool V_340 = T_1 -> V_341 ;
union V_342 V_343 ;
V_339 += ( ( V_336 -> V_344 . V_6 -
sizeof( V_336 -> V_344 ) ) / sizeof( T_3 ) ) - 1 ;
if ( type & V_13 ) {
V_338 -> V_63 = * V_339 ;
V_339 -- ;
}
if ( type & V_19 ) {
V_343 . V_345 = * V_339 ;
if ( V_340 ) {
V_343 . V_345 = F_126 ( V_343 . V_345 ) ;
V_343 . V_346 [ 0 ] = F_127 ( V_343 . V_346 [ 0 ] ) ;
}
V_338 -> V_225 = V_343 . V_346 [ 0 ] ;
V_339 -- ;
}
if ( type & V_20 ) {
V_338 -> V_347 = * V_339 ;
V_339 -- ;
}
if ( type & V_14 ) {
V_338 -> V_63 = * V_339 ;
V_339 -- ;
}
if ( type & V_17 ) {
V_338 -> time = * V_339 ;
V_339 -- ;
}
if ( type & V_16 ) {
V_343 . V_345 = * V_339 ;
if ( V_340 ) {
V_343 . V_345 = F_126 ( V_343 . V_345 ) ;
V_343 . V_346 [ 0 ] = F_127 ( V_343 . V_346 [ 0 ] ) ;
V_343 . V_346 [ 1 ] = F_127 ( V_343 . V_346 [ 1 ] ) ;
}
V_338 -> V_302 = V_343 . V_346 [ 0 ] ;
V_338 -> V_348 = V_343 . V_346 [ 1 ] ;
V_339 -- ;
}
return 0 ;
}
static inline bool F_128 ( const void * V_349 , T_12 V_350 , const void * V_351 ,
T_3 V_6 )
{
return V_6 > V_350 || V_351 + V_6 > V_349 ;
}
int F_129 ( struct V_1 * T_1 , union V_335 * V_336 ,
struct V_337 * V_352 )
{
T_3 type = T_1 -> V_22 . V_8 ;
bool V_340 = T_1 -> V_341 ;
const T_3 * V_339 ;
T_12 V_350 = V_336 -> V_344 . V_6 ;
const void * V_349 = ( void * ) V_336 + V_350 ;
T_3 V_353 ;
union V_342 V_343 ;
memset ( V_352 , 0 , sizeof( * V_352 ) ) ;
V_352 -> V_225 = V_352 -> V_302 = V_352 -> V_348 = - 1 ;
V_352 -> V_347 = V_352 -> V_63 = V_352 -> time = - 1ULL ;
V_352 -> V_137 = T_1 -> V_22 . V_49 ;
V_352 -> V_354 = V_336 -> V_344 . V_355 & V_356 ;
if ( V_336 -> V_344 . type != V_357 ) {
if ( ! T_1 -> V_22 . V_162 )
return 0 ;
return F_125 ( T_1 , V_336 , V_352 ) ;
}
V_339 = V_336 -> V_338 . V_339 ;
if ( T_1 -> V_26 + sizeof( V_336 -> V_344 ) > V_336 -> V_344 . V_6 )
return - V_358 ;
V_352 -> V_63 = - 1ULL ;
if ( type & V_13 ) {
V_352 -> V_63 = * V_339 ;
V_339 ++ ;
}
if ( type & V_15 ) {
V_352 -> V_359 = * V_339 ;
V_339 ++ ;
}
if ( type & V_16 ) {
V_343 . V_345 = * V_339 ;
if ( V_340 ) {
V_343 . V_345 = F_126 ( V_343 . V_345 ) ;
V_343 . V_346 [ 0 ] = F_127 ( V_343 . V_346 [ 0 ] ) ;
V_343 . V_346 [ 1 ] = F_127 ( V_343 . V_346 [ 1 ] ) ;
}
V_352 -> V_302 = V_343 . V_346 [ 0 ] ;
V_352 -> V_348 = V_343 . V_346 [ 1 ] ;
V_339 ++ ;
}
if ( type & V_17 ) {
V_352 -> time = * V_339 ;
V_339 ++ ;
}
V_352 -> V_82 = 0 ;
if ( type & V_18 ) {
V_352 -> V_82 = * V_339 ;
V_339 ++ ;
}
if ( type & V_14 ) {
V_352 -> V_63 = * V_339 ;
V_339 ++ ;
}
if ( type & V_20 ) {
V_352 -> V_347 = * V_339 ;
V_339 ++ ;
}
if ( type & V_19 ) {
V_343 . V_345 = * V_339 ;
if ( V_340 ) {
V_343 . V_345 = F_126 ( V_343 . V_345 ) ;
V_343 . V_346 [ 0 ] = F_127 ( V_343 . V_346 [ 0 ] ) ;
}
V_352 -> V_225 = V_343 . V_346 [ 0 ] ;
V_339 ++ ;
}
if ( type & V_48 ) {
V_352 -> V_137 = * V_339 ;
V_339 ++ ;
}
if ( type & V_360 ) {
T_3 V_30 = T_1 -> V_22 . V_30 ;
F_130 ( V_339 ) ;
if ( V_30 & V_170 )
V_352 -> V_361 . V_362 . V_298 = * V_339 ;
else
V_352 -> V_361 . V_363 . V_255 = * V_339 ;
V_339 ++ ;
if ( V_30 & V_209 ) {
F_130 ( V_339 ) ;
V_352 -> V_361 . V_364 = * V_339 ;
V_339 ++ ;
}
if ( V_30 & V_210 ) {
F_130 ( V_339 ) ;
V_352 -> V_361 . V_365 = * V_339 ;
V_339 ++ ;
}
if ( V_30 & V_170 ) {
const T_3 V_366 = V_367 /
sizeof( struct V_368 ) ;
if ( V_352 -> V_361 . V_362 . V_298 > V_366 )
return - V_358 ;
V_353 = V_352 -> V_361 . V_362 . V_298 *
sizeof( struct V_368 ) ;
F_131 ( V_339 , V_353 , V_350 ) ;
V_352 -> V_361 . V_362 . V_369 =
(struct V_368 * ) V_339 ;
V_339 = ( void * ) V_339 + V_353 ;
} else {
F_130 ( V_339 ) ;
V_352 -> V_361 . V_363 . V_63 = * V_339 ;
V_339 ++ ;
}
}
if ( type & V_370 ) {
const T_3 V_371 = V_367 / sizeof( T_3 ) ;
F_130 ( V_339 ) ;
V_352 -> V_156 = (struct V_372 * ) V_339 ++ ;
if ( V_352 -> V_156 -> V_298 > V_371 )
return - V_358 ;
V_353 = V_352 -> V_156 -> V_298 * sizeof( T_3 ) ;
F_131 ( V_339 , V_353 , V_350 ) ;
V_339 = ( void * ) V_339 + V_353 ;
}
if ( type & V_47 ) {
F_130 ( V_339 ) ;
V_343 . V_345 = * V_339 ;
if ( F_132 ( V_340 ,
L_55 ) ) {
V_343 . V_345 = F_126 ( V_343 . V_345 ) ;
V_343 . V_346 [ 0 ] = F_127 ( V_343 . V_346 [ 0 ] ) ;
V_343 . V_346 [ 1 ] = F_127 ( V_343 . V_346 [ 1 ] ) ;
}
V_352 -> V_373 = V_343 . V_346 [ 0 ] ;
V_339 = ( void * ) V_339 + sizeof( T_7 ) ;
F_131 ( V_339 , V_352 -> V_373 , V_350 ) ;
V_352 -> V_374 = ( void * ) V_339 ;
V_339 = ( void * ) V_339 + V_352 -> V_373 ;
}
if ( type & V_375 ) {
const T_3 V_376 = V_367 /
sizeof( struct V_377 ) ;
F_130 ( V_339 ) ;
V_352 -> V_116 = (struct V_116 * ) V_339 ++ ;
if ( V_352 -> V_116 -> V_298 > V_376 )
return - V_358 ;
V_353 = V_352 -> V_116 -> V_298 * sizeof( struct V_377 ) ;
F_131 ( V_339 , V_353 , V_350 ) ;
V_339 = ( void * ) V_339 + V_353 ;
}
if ( type & V_378 ) {
F_130 ( V_339 ) ;
V_352 -> V_379 . V_380 = * V_339 ;
V_339 ++ ;
if ( V_352 -> V_379 . V_380 ) {
T_3 V_9 = T_1 -> V_22 . V_126 ;
V_353 = F_133 ( V_9 ) * sizeof( T_3 ) ;
F_131 ( V_339 , V_353 , V_350 ) ;
V_352 -> V_379 . V_9 = V_9 ;
V_352 -> V_379 . V_381 = ( T_3 * ) V_339 ;
V_339 = ( void * ) V_339 + V_353 ;
}
}
if ( type & V_382 ) {
F_130 ( V_339 ) ;
V_353 = * V_339 ++ ;
V_352 -> V_383 . V_351 = ( ( char * ) ( V_339 - 1 )
- ( char * ) V_336 ) ;
if ( ! V_353 ) {
V_352 -> V_383 . V_6 = 0 ;
} else {
F_131 ( V_339 , V_353 , V_350 ) ;
V_352 -> V_383 . V_352 = ( char * ) V_339 ;
V_339 = ( void * ) V_339 + V_353 ;
F_130 ( V_339 ) ;
V_352 -> V_383 . V_6 = * V_339 ++ ;
if ( F_132 ( V_352 -> V_383 . V_6 > V_353 ,
L_56 ) )
return - V_358 ;
}
}
if ( type & V_384 ) {
F_130 ( V_339 ) ;
V_352 -> V_385 = * V_339 ;
V_339 ++ ;
}
V_352 -> V_386 = V_387 ;
if ( type & V_388 ) {
F_130 ( V_339 ) ;
V_352 -> V_386 = * V_339 ;
V_339 ++ ;
}
V_352 -> V_389 = 0 ;
if ( type & V_390 ) {
F_130 ( V_339 ) ;
V_352 -> V_389 = * V_339 ;
V_339 ++ ;
}
V_352 -> V_391 . V_380 = V_392 ;
if ( type & V_393 ) {
F_130 ( V_339 ) ;
V_352 -> V_391 . V_380 = * V_339 ;
V_339 ++ ;
if ( V_352 -> V_391 . V_380 != V_392 ) {
T_3 V_9 = T_1 -> V_22 . V_184 ;
V_353 = F_133 ( V_9 ) * sizeof( T_3 ) ;
F_131 ( V_339 , V_353 , V_350 ) ;
V_352 -> V_391 . V_9 = V_9 ;
V_352 -> V_391 . V_381 = ( T_3 * ) V_339 ;
V_339 = ( void * ) V_339 + V_353 ;
}
}
return 0 ;
}
T_2 F_134 ( const struct V_337 * V_338 , T_3 type ,
T_3 V_30 )
{
T_2 V_353 , V_91 = sizeof( struct V_394 ) ;
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
if ( type & V_360 ) {
V_91 += sizeof( T_3 ) ;
if ( V_30 & V_209 )
V_91 += sizeof( T_3 ) ;
if ( V_30 & V_210 )
V_91 += sizeof( T_3 ) ;
if ( V_30 & V_170 ) {
V_353 = V_338 -> V_361 . V_362 . V_298 *
sizeof( struct V_368 ) ;
V_91 += V_353 ;
} else {
V_91 += sizeof( T_3 ) ;
}
}
if ( type & V_370 ) {
V_353 = ( V_338 -> V_156 -> V_298 + 1 ) * sizeof( T_3 ) ;
V_91 += V_353 ;
}
if ( type & V_47 ) {
V_91 += sizeof( T_7 ) ;
V_91 += V_338 -> V_373 ;
}
if ( type & V_375 ) {
V_353 = V_338 -> V_116 -> V_298 * sizeof( struct V_377 ) ;
V_353 += sizeof( T_3 ) ;
V_91 += V_353 ;
}
if ( type & V_378 ) {
if ( V_338 -> V_379 . V_380 ) {
V_91 += sizeof( T_3 ) ;
V_353 = F_133 ( V_338 -> V_379 . V_9 ) * sizeof( T_3 ) ;
V_91 += V_353 ;
} else {
V_91 += sizeof( T_3 ) ;
}
}
if ( type & V_382 ) {
V_353 = V_338 -> V_383 . V_6 ;
V_91 += sizeof( T_3 ) ;
if ( V_353 ) {
V_91 += V_353 ;
V_91 += sizeof( T_3 ) ;
}
}
if ( type & V_384 )
V_91 += sizeof( T_3 ) ;
if ( type & V_388 )
V_91 += sizeof( T_3 ) ;
if ( type & V_390 )
V_91 += sizeof( T_3 ) ;
if ( type & V_393 ) {
if ( V_338 -> V_391 . V_380 ) {
V_91 += sizeof( T_3 ) ;
V_353 = F_133 ( V_338 -> V_391 . V_9 ) * sizeof( T_3 ) ;
V_91 += V_353 ;
} else {
V_91 += sizeof( T_3 ) ;
}
}
return V_91 ;
}
int F_135 ( union V_335 * V_336 , T_3 type ,
T_3 V_30 ,
const struct V_337 * V_338 ,
bool V_340 )
{
T_3 * V_339 ;
T_2 V_353 ;
union V_342 V_343 ;
V_339 = V_336 -> V_338 . V_339 ;
if ( type & V_13 ) {
* V_339 = V_338 -> V_63 ;
V_339 ++ ;
}
if ( type & V_15 ) {
* V_339 = V_338 -> V_359 ;
V_339 ++ ;
}
if ( type & V_16 ) {
V_343 . V_346 [ 0 ] = V_338 -> V_302 ;
V_343 . V_346 [ 1 ] = V_338 -> V_348 ;
if ( V_340 ) {
V_343 . V_346 [ 0 ] = F_127 ( V_343 . V_346 [ 0 ] ) ;
V_343 . V_346 [ 1 ] = F_127 ( V_343 . V_346 [ 1 ] ) ;
V_343 . V_345 = F_126 ( V_343 . V_345 ) ;
}
* V_339 = V_343 . V_345 ;
V_339 ++ ;
}
if ( type & V_17 ) {
* V_339 = V_338 -> time ;
V_339 ++ ;
}
if ( type & V_18 ) {
* V_339 = V_338 -> V_82 ;
V_339 ++ ;
}
if ( type & V_14 ) {
* V_339 = V_338 -> V_63 ;
V_339 ++ ;
}
if ( type & V_20 ) {
* V_339 = V_338 -> V_347 ;
V_339 ++ ;
}
if ( type & V_19 ) {
V_343 . V_346 [ 0 ] = V_338 -> V_225 ;
if ( V_340 ) {
V_343 . V_346 [ 0 ] = F_127 ( V_343 . V_346 [ 0 ] ) ;
V_343 . V_345 = F_126 ( V_343 . V_345 ) ;
}
* V_339 = V_343 . V_345 ;
V_339 ++ ;
}
if ( type & V_48 ) {
* V_339 = V_338 -> V_137 ;
V_339 ++ ;
}
if ( type & V_360 ) {
if ( V_30 & V_170 )
* V_339 = V_338 -> V_361 . V_362 . V_298 ;
else
* V_339 = V_338 -> V_361 . V_363 . V_255 ;
V_339 ++ ;
if ( V_30 & V_209 ) {
* V_339 = V_338 -> V_361 . V_364 ;
V_339 ++ ;
}
if ( V_30 & V_210 ) {
* V_339 = V_338 -> V_361 . V_365 ;
V_339 ++ ;
}
if ( V_30 & V_170 ) {
V_353 = V_338 -> V_361 . V_362 . V_298 *
sizeof( struct V_368 ) ;
memcpy ( V_339 , V_338 -> V_361 . V_362 . V_369 , V_353 ) ;
V_339 = ( void * ) V_339 + V_353 ;
} else {
* V_339 = V_338 -> V_361 . V_363 . V_63 ;
V_339 ++ ;
}
}
if ( type & V_370 ) {
V_353 = ( V_338 -> V_156 -> V_298 + 1 ) * sizeof( T_3 ) ;
memcpy ( V_339 , V_338 -> V_156 , V_353 ) ;
V_339 = ( void * ) V_339 + V_353 ;
}
if ( type & V_47 ) {
V_343 . V_346 [ 0 ] = V_338 -> V_373 ;
if ( F_132 ( V_340 ,
L_55 ) ) {
V_343 . V_346 [ 0 ] = F_127 ( V_343 . V_346 [ 0 ] ) ;
V_343 . V_346 [ 1 ] = F_127 ( V_343 . V_346 [ 1 ] ) ;
V_343 . V_345 = F_126 ( V_343 . V_345 ) ;
}
* V_339 = V_343 . V_345 ;
V_339 = ( void * ) V_339 + sizeof( T_7 ) ;
memcpy ( V_339 , V_338 -> V_374 , V_338 -> V_373 ) ;
V_339 = ( void * ) V_339 + V_338 -> V_373 ;
}
if ( type & V_375 ) {
V_353 = V_338 -> V_116 -> V_298 * sizeof( struct V_377 ) ;
V_353 += sizeof( T_3 ) ;
memcpy ( V_339 , V_338 -> V_116 , V_353 ) ;
V_339 = ( void * ) V_339 + V_353 ;
}
if ( type & V_378 ) {
if ( V_338 -> V_379 . V_380 ) {
* V_339 ++ = V_338 -> V_379 . V_380 ;
V_353 = F_133 ( V_338 -> V_379 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_339 , V_338 -> V_379 . V_381 , V_353 ) ;
V_339 = ( void * ) V_339 + V_353 ;
} else {
* V_339 ++ = 0 ;
}
}
if ( type & V_382 ) {
V_353 = V_338 -> V_383 . V_6 ;
* V_339 ++ = V_353 ;
if ( V_353 ) {
memcpy ( V_339 , V_338 -> V_383 . V_352 , V_353 ) ;
V_339 = ( void * ) V_339 + V_353 ;
* V_339 ++ = V_353 ;
}
}
if ( type & V_384 ) {
* V_339 = V_338 -> V_385 ;
V_339 ++ ;
}
if ( type & V_388 ) {
* V_339 = V_338 -> V_386 ;
V_339 ++ ;
}
if ( type & V_390 ) {
* V_339 = V_338 -> V_389 ;
V_339 ++ ;
}
if ( type & V_393 ) {
if ( V_338 -> V_391 . V_380 ) {
* V_339 ++ = V_338 -> V_391 . V_380 ;
V_353 = F_133 ( V_338 -> V_391 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_339 , V_338 -> V_391 . V_381 , V_353 ) ;
V_339 = ( void * ) V_339 + V_353 ;
} else {
* V_339 ++ = 0 ;
}
}
return 0 ;
}
struct V_395 * F_136 ( struct V_1 * T_1 , const char * V_32 )
{
return F_137 ( T_1 -> V_62 , V_32 ) ;
}
void * F_138 ( struct V_1 * T_1 , struct V_337 * V_338 ,
const char * V_32 )
{
struct V_395 * V_396 = F_136 ( T_1 , V_32 ) ;
int V_351 ;
if ( ! V_396 )
return NULL ;
V_351 = V_396 -> V_351 ;
if ( V_396 -> V_300 & V_397 ) {
V_351 = * ( int * ) ( V_338 -> V_374 + V_396 -> V_351 ) ;
V_351 &= 0xffff ;
}
return V_338 -> V_374 + V_351 ;
}
T_3 F_139 ( struct V_395 * V_396 , struct V_337 * V_338 ,
bool V_341 )
{
T_3 V_255 ;
void * V_398 = V_338 -> V_374 + V_396 -> V_351 ;
switch ( V_396 -> V_6 ) {
case 1 :
return * ( T_6 * ) V_398 ;
case 2 :
V_255 = * ( T_12 * ) V_398 ;
break;
case 4 :
V_255 = * ( T_7 * ) V_398 ;
break;
case 8 :
memcpy ( & V_255 , V_398 , sizeof( T_3 ) ) ;
break;
default:
return 0 ;
}
if ( ! V_341 )
return V_255 ;
switch ( V_396 -> V_6 ) {
case 2 :
return F_140 ( V_255 ) ;
case 4 :
return F_127 ( V_255 ) ;
case 8 :
return F_126 ( V_255 ) ;
default:
return 0 ;
}
return 0 ;
}
T_3 F_141 ( struct V_1 * T_1 , struct V_337 * V_338 ,
const char * V_32 )
{
struct V_395 * V_396 = F_136 ( T_1 , V_32 ) ;
if ( ! V_396 )
return 0 ;
return V_396 ? F_139 ( V_396 , V_338 , T_1 -> V_341 ) : 0 ;
}
bool F_142 ( struct V_1 * T_1 , int V_57 ,
char * V_399 , T_2 V_400 )
{
int V_401 ;
if ( ( V_57 == V_402 || V_57 == V_403 || V_57 == V_404 ) &&
T_1 -> V_22 . type == V_50 &&
T_1 -> V_22 . V_51 == V_52 ) {
F_37 ( V_399 , V_400 , L_8 ,
L_57 ) ;
T_1 -> V_22 . type = V_101 ;
T_1 -> V_22 . V_51 = V_405 ;
F_32 ( & T_1 -> V_32 ) ;
return true ;
} else if ( V_57 == V_406 && ! T_1 -> V_22 . V_70 &&
( V_401 = F_143 () ) > 1 ) {
const char * V_32 = F_49 ( T_1 ) ;
char * V_407 ;
if ( F_26 ( & V_407 , L_58 , V_32 , strchr ( V_32 , ':' ) ? L_1 : L_11 ) < 0 )
return false ;
if ( T_1 -> V_32 )
free ( T_1 -> V_32 ) ;
T_1 -> V_32 = V_407 ;
F_37 ( V_399 , V_400 ,
L_59 , V_401 ) ;
T_1 -> V_22 . V_70 = 1 ;
return true ;
}
return false ;
}
int F_144 ( struct V_1 * T_1 , struct V_159 * V_159 ,
int V_57 , char * V_399 , T_2 V_6 )
{
char V_408 [ V_409 ] ;
int V_410 = 0 ;
switch ( V_57 ) {
case V_411 :
case V_406 :
if ( V_57 == V_411 )
V_410 = F_37 ( V_399 , V_6 ,
L_60 ,
F_49 ( T_1 ) ) ;
return F_37 ( V_399 + V_410 , V_6 - V_410 ,
L_61
L_62
L_63
L_64
L_65
L_66
L_67
L_68
L_69
L_70
L_71 ,
V_159 -> V_223 ? L_72 : L_1 ,
F_143 () ) ;
case V_402 :
return F_37 ( V_399 , V_6 , L_73 ,
F_49 ( T_1 ) ) ;
case V_328 :
return F_37 ( V_399 , V_6 , L_8 ,
L_74
L_75
L_76
L_77 ) ;
case V_58 :
if ( ( T_1 -> V_22 . V_8 & V_370 ) != 0 &&
F_145 ( L_78 , V_412 ) == 0 )
return F_37 ( V_399 , V_6 ,
L_79
L_80
L_81 , V_413 ) ;
break;
case V_404 :
if ( V_159 -> V_414 )
return F_37 ( V_399 , V_6 , L_8 ,
L_82 ) ;
break;
case V_415 :
if ( T_1 -> V_22 . V_49 != 0 )
return F_37 ( V_399 , V_6 , L_8 ,
L_83 ) ;
if ( T_1 -> V_22 . V_54 )
return F_37 ( V_399 , V_6 , L_8 ,
L_84 ) ;
#if F_146 ( V_416 ) || F_146 ( V_417 )
if ( T_1 -> V_22 . type == V_50 )
return F_37 ( V_399 , V_6 , L_8 ,
L_85
L_86 ) ;
#endif
break;
case V_418 :
if ( F_147 ( L_87 ) )
return F_37 ( V_399 , V_6 ,
L_88
L_89 ) ;
break;
case V_7 :
if ( T_1 -> V_22 . V_152 && V_163 . V_152 )
return F_37 ( V_399 , V_6 , L_90 ) ;
if ( V_163 . V_215 )
return F_37 ( V_399 , V_6 , L_91 ) ;
if ( V_163 . V_311 )
return F_37 ( V_399 , V_6 , L_92 , V_215 ) ;
break;
default:
break;
}
return F_37 ( V_399 , V_6 ,
L_93
L_94
L_95 ,
V_57 , F_148 ( V_57 , V_408 , sizeof( V_408 ) ) ,
F_49 ( T_1 ) ) ;
}
char * F_149 ( struct V_1 * T_1 )
{
if ( T_1 && T_1 -> V_38 && T_1 -> V_38 -> V_419 )
return T_1 -> V_38 -> V_419 -> V_420 ;
return NULL ;
}
