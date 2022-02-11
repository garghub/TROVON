static int F_1 ( struct V_1 * T_1 V_2 )
{
return 0 ;
}
void __weak F_2 ( void ) { }
static void F_3 ( struct V_1 * T_1 V_2 )
{
}
int F_4 ( T_2 V_3 ,
int (* F_5)( struct V_1 * T_1 ) ,
void (* F_6)( struct V_1 * T_1 ) )
{
if ( V_3 == 0 )
goto V_4;
if ( V_5 . V_6 > V_3 )
return - V_7 ;
V_5 . V_6 = V_3 ;
V_4:
if ( F_5 != NULL )
V_5 . F_5 = F_5 ;
if ( F_6 != NULL )
V_5 . F_6 = F_6 ;
return 0 ;
}
int F_7 ( T_3 V_8 )
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
static int F_8 ( T_3 V_8 )
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
static int F_9 ( T_3 V_8 )
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
void F_10 ( struct V_1 * T_1 )
{
T_1 -> V_21 = F_8 ( T_1 -> V_22 . V_8 ) ;
T_1 -> V_23 = F_9 ( T_1 -> V_22 . V_8 ) ;
}
void F_11 ( struct V_1 * T_1 ,
enum V_24 V_25 )
{
if ( ! ( T_1 -> V_22 . V_8 & V_25 ) ) {
T_1 -> V_22 . V_8 |= V_25 ;
T_1 -> V_26 += sizeof( T_3 ) ;
F_10 ( T_1 ) ;
}
}
void F_12 ( struct V_1 * T_1 ,
enum V_24 V_25 )
{
if ( T_1 -> V_22 . V_8 & V_25 ) {
T_1 -> V_22 . V_8 &= ~ V_25 ;
T_1 -> V_26 -= sizeof( T_3 ) ;
F_10 ( T_1 ) ;
}
}
void F_13 ( struct V_1 * T_1 ,
bool V_27 )
{
if ( V_27 ) {
F_14 ( T_1 , V_28 ) ;
F_15 ( T_1 , V_29 ) ;
} else {
F_15 ( T_1 , V_28 ) ;
}
T_1 -> V_22 . V_30 |= V_31 ;
}
bool F_16 ( struct V_1 * T_1 )
{
#define F_17 "ftrace:function"
return T_1 -> V_32 &&
! strncmp ( F_17 , T_1 -> V_32 , sizeof( F_17 ) ) ;
#undef F_17
}
void F_18 ( struct V_1 * T_1 ,
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
F_19 ( & T_1 -> V_40 ) ;
F_19 ( & T_1 -> V_41 ) ;
V_5 . F_5 ( T_1 ) ;
T_1 -> V_26 = F_7 ( V_22 -> V_8 ) ;
F_10 ( T_1 ) ;
T_1 -> V_42 = false ;
T_1 -> V_43 = NULL ;
T_1 -> V_44 = NULL ;
T_1 -> V_45 = NULL ;
T_1 -> V_46 = false ;
}
struct V_1 * F_20 ( struct V_33 * V_22 , int V_12 )
{
struct V_1 * T_1 = F_21 ( V_5 . V_6 ) ;
if ( T_1 != NULL )
F_18 ( T_1 , V_22 , V_12 ) ;
if ( F_22 ( T_1 ) ) {
T_1 -> V_22 . V_8 |= ( V_47 | V_17 |
V_19 | V_48 ) ,
T_1 -> V_22 . V_49 = 1 ;
}
return T_1 ;
}
static bool F_23 ( void )
{
return F_24 () == 0 || F_25 () == - 1 ;
}
struct V_1 * F_26 ( bool V_50 )
{
struct V_33 V_22 = {
. type = V_51 ,
. V_52 = V_53 ,
. V_54 = ! F_23 () ,
} ;
struct V_1 * T_1 ;
F_27 ( & V_22 ) ;
if ( ! V_50 )
goto V_55;
V_22 . V_49 = 1 ;
F_28 ( & V_22 ) ;
V_22 . V_49 = 0 ;
V_55:
T_1 = F_29 ( & V_22 ) ;
if ( T_1 == NULL )
goto V_56;
if ( F_30 ( & T_1 -> V_32 , L_2 ,
( V_22 . V_57 || V_22 . V_54 ) ? L_3 : L_1 ,
V_22 . V_54 ? L_4 : L_1 ,
V_22 . V_57 ? V_22 . V_57 + 1 : 0 , L_5 ) < 0 )
goto V_58;
V_56:
return T_1 ;
V_58:
F_31 ( T_1 ) ;
T_1 = NULL ;
goto V_56;
}
struct V_1 * F_32 ( const char * V_59 , const char * V_32 , int V_12 )
{
struct V_1 * T_1 = F_21 ( V_5 . V_6 ) ;
int V_60 = - V_61 ;
if ( T_1 == NULL ) {
goto V_62;
} else {
struct V_33 V_22 = {
. type = V_63 ,
. V_8 = ( V_47 | V_17 |
V_19 | V_48 ) ,
} ;
if ( F_30 ( & T_1 -> V_32 , L_6 , V_59 , V_32 ) < 0 )
goto V_64;
T_1 -> V_65 = F_33 ( V_59 , V_32 ) ;
if ( F_34 ( T_1 -> V_65 ) ) {
V_60 = F_35 ( T_1 -> V_65 ) ;
goto V_64;
}
F_27 ( & V_22 ) ;
V_22 . V_52 = T_1 -> V_65 -> V_66 ;
V_22 . V_49 = 1 ;
F_18 ( T_1 , & V_22 , V_12 ) ;
}
return T_1 ;
V_64:
F_36 ( & T_1 -> V_32 ) ;
free ( T_1 ) ;
V_62:
return F_37 ( V_60 ) ;
}
static const char * F_38 ( T_3 V_52 )
{
if ( V_52 < V_67 && V_68 [ V_52 ] )
return V_68 [ V_52 ] ;
return L_7 ;
}
static int F_39 ( struct V_1 * T_1 , char * V_69 , T_2 V_6 )
{
int V_70 = 0 , V_71 = 0 ;
struct V_33 * V_22 = & T_1 -> V_22 ;
bool V_72 = false ;
#define F_40 ( T_4 , T_5 ) do { \
if (!attr->exclude_##context) { \
if (!colon) colon = ++r; \
r += scnprintf(bf + r, size - r, "%c", mod); \
} } while(0)
if ( V_22 -> V_54 || V_22 -> V_73 || V_22 -> V_74 ) {
F_40 ( V_75 , 'k' ) ;
F_40 ( V_76 , 'u' ) ;
F_40 ( V_77 , 'h' ) ;
V_72 = true ;
}
if ( V_22 -> V_57 ) {
if ( ! V_70 )
V_70 = ++ V_71 ;
V_71 += F_41 ( V_69 + V_71 , V_6 - V_71 , L_8 , V_22 -> V_57 , L_5 ) ;
V_72 = true ;
}
if ( V_22 -> V_78 || V_22 -> V_79 == V_72 ) {
F_40 ( V_80 , 'H' ) ;
F_40 ( V_81 , 'G' ) ;
}
#undef F_40
if ( V_70 )
V_69 [ V_70 - 1 ] = ':' ;
return V_71 ;
}
static int F_42 ( struct V_1 * T_1 , char * V_69 , T_2 V_6 )
{
int V_71 = F_41 ( V_69 , V_6 , L_9 , F_38 ( T_1 -> V_22 . V_52 ) ) ;
return V_71 + F_39 ( T_1 , V_69 + V_71 , V_6 - V_71 ) ;
}
static const char * F_43 ( T_3 V_52 )
{
if ( V_52 < V_82 && V_83 [ V_52 ] )
return V_83 [ V_52 ] ;
return L_10 ;
}
static int F_44 ( struct V_1 * T_1 , char * V_69 , T_2 V_6 )
{
int V_71 = F_41 ( V_69 , V_6 , L_9 , F_43 ( T_1 -> V_22 . V_52 ) ) ;
return V_71 + F_39 ( T_1 , V_69 + V_71 , V_6 - V_71 ) ;
}
static int F_45 ( char * V_69 , T_2 V_6 , T_3 V_84 , T_3 type )
{
int V_71 ;
V_71 = F_41 ( V_69 , V_6 , L_11 V_85 L_3 , V_84 ) ;
if ( type & V_86 )
V_71 += F_41 ( V_69 + V_71 , V_6 - V_71 , L_12 ) ;
if ( type & V_87 )
V_71 += F_41 ( V_69 + V_71 , V_6 - V_71 , L_13 ) ;
if ( type & V_88 )
V_71 += F_41 ( V_69 + V_71 , V_6 - V_71 , L_14 ) ;
return V_71 ;
}
static int F_46 ( struct V_1 * T_1 , char * V_69 , T_2 V_6 )
{
struct V_33 * V_22 = & T_1 -> V_22 ;
int V_71 = F_45 ( V_69 , V_6 , V_22 -> V_89 , V_22 -> V_90 ) ;
return V_71 + F_39 ( T_1 , V_69 + V_71 , V_6 - V_71 ) ;
}
bool F_47 ( T_6 type , T_6 V_91 )
{
if ( V_92 [ type ] & F_48 ( V_91 ) )
return true ;
else
return false ;
}
int F_49 ( T_6 type , T_6 V_91 , T_6 V_93 ,
char * V_69 , T_2 V_6 )
{
if ( V_93 ) {
return F_41 ( V_69 , V_6 , L_15 , V_94 [ type ] [ 0 ] ,
V_95 [ V_91 ] [ 0 ] ,
V_96 [ V_93 ] [ 0 ] ) ;
}
return F_41 ( V_69 , V_6 , L_16 , V_94 [ type ] [ 0 ] ,
V_95 [ V_91 ] [ 1 ] ) ;
}
static int F_50 ( T_3 V_52 , char * V_69 , T_2 V_6 )
{
T_6 V_91 , V_93 , type = ( V_52 >> 0 ) & 0xff ;
const char * V_60 = L_17 ;
if ( type >= V_97 )
goto V_62;
V_91 = ( V_52 >> 8 ) & 0xff ;
V_60 = L_18 ;
if ( V_91 >= V_98 )
goto V_62;
V_93 = ( V_52 >> 16 ) & 0xff ;
V_60 = L_19 ;
if ( V_93 >= V_99 )
goto V_62;
V_60 = L_20 ;
if ( ! F_47 ( type , V_91 ) )
goto V_62;
return F_49 ( type , V_91 , V_93 , V_69 , V_6 ) ;
V_62:
return F_41 ( V_69 , V_6 , L_9 , V_60 ) ;
}
static int F_51 ( struct V_1 * T_1 , char * V_69 , T_2 V_6 )
{
int V_100 = F_50 ( T_1 -> V_22 . V_52 , V_69 , V_6 ) ;
return V_100 + F_39 ( T_1 , V_69 + V_100 , V_6 - V_100 ) ;
}
static int F_52 ( struct V_1 * T_1 , char * V_69 , T_2 V_6 )
{
int V_100 = F_41 ( V_69 , V_6 , L_21 V_85 , T_1 -> V_22 . V_52 ) ;
return V_100 + F_39 ( T_1 , V_69 + V_100 , V_6 - V_100 ) ;
}
const char * F_53 ( struct V_1 * T_1 )
{
char V_69 [ 128 ] ;
if ( T_1 -> V_32 )
return T_1 -> V_32 ;
switch ( T_1 -> V_22 . type ) {
case V_101 :
F_52 ( T_1 , V_69 , sizeof( V_69 ) ) ;
break;
case V_51 :
F_42 ( T_1 , V_69 , sizeof( V_69 ) ) ;
break;
case V_102 :
F_51 ( T_1 , V_69 , sizeof( V_69 ) ) ;
break;
case V_103 :
F_44 ( T_1 , V_69 , sizeof( V_69 ) ) ;
break;
case V_63 :
F_41 ( V_69 , sizeof( V_69 ) , L_9 , L_22 ) ;
break;
case V_104 :
F_46 ( T_1 , V_69 , sizeof( V_69 ) ) ;
break;
default:
F_41 ( V_69 , sizeof( V_69 ) , L_23 ,
T_1 -> V_22 . type ) ;
break;
}
T_1 -> V_32 = F_54 ( V_69 ) ;
return T_1 -> V_32 ? : L_24 ;
}
const char * F_55 ( struct V_1 * T_1 )
{
return T_1 -> V_105 ? : L_25 ;
}
int F_56 ( struct V_1 * T_1 , char * V_106 , T_2 V_6 )
{
int V_100 ;
struct V_1 * V_107 ;
const char * V_105 = F_55 ( T_1 ) ;
V_100 = F_41 ( V_106 , V_6 , L_9 , V_105 ) ;
V_100 += F_41 ( V_106 + V_100 , V_6 - V_100 , L_26 ,
F_53 ( T_1 ) ) ;
F_57 (pos, evsel)
V_100 += F_41 ( V_106 + V_100 , V_6 - V_100 , L_27 ,
F_53 ( V_107 ) ) ;
V_100 += F_41 ( V_106 + V_100 , V_6 - V_100 , L_28 ) ;
return V_100 ;
}
void F_58 ( struct V_1 * T_1 ,
struct V_108 * V_109 ,
struct V_110 * V_111 )
{
bool V_112 = F_16 ( T_1 ) ;
struct V_33 * V_22 = & T_1 -> V_22 ;
F_15 ( T_1 , V_113 ) ;
V_22 -> V_114 = V_111 -> V_115 ;
if ( V_111 -> V_116 == V_117 ) {
if ( ! V_109 -> V_118 ) {
if ( V_22 -> V_73 ) {
F_59 ( L_29
L_30
L_31 ) ;
} else {
F_15 ( T_1 , V_119 ) ;
V_22 -> V_120 = V_121 |
V_122 |
V_123 |
V_124 ;
}
} else
F_59 ( L_32
L_31 ) ;
}
if ( V_111 -> V_116 == V_125 ) {
if ( ! V_112 ) {
F_15 ( T_1 , V_126 ) ;
F_15 ( T_1 , V_127 ) ;
V_22 -> V_128 = V_129 ;
V_22 -> V_130 = V_111 -> V_131 ;
V_22 -> V_132 = 1 ;
} else {
F_60 ( L_33
L_34 ) ;
}
}
if ( V_112 ) {
F_60 ( L_35 ) ;
V_22 -> V_132 = 1 ;
}
}
static void
F_61 ( struct V_1 * T_1 ,
struct V_110 * V_111 )
{
struct V_33 * V_22 = & T_1 -> V_22 ;
F_14 ( T_1 , V_113 ) ;
if ( V_111 -> V_116 == V_117 ) {
F_14 ( T_1 , V_119 ) ;
V_22 -> V_120 &= ~ ( V_121 |
V_122 ) ;
}
if ( V_111 -> V_116 == V_125 ) {
F_14 ( T_1 , V_126 ) ;
F_14 ( T_1 , V_127 ) ;
}
}
static void F_62 ( struct V_1 * T_1 ,
struct V_108 * V_109 )
{
struct V_133 * V_134 ;
struct V_135 * V_41 = & T_1 -> V_41 ;
struct V_33 * V_22 = & T_1 -> V_22 ;
struct V_110 V_111 ;
T_7 V_131 = 0 ;
int V_115 = 0 ;
const char * V_136 = NULL ;
V_111 . V_116 = V_110 . V_116 ;
F_63 (term, config_terms, list) {
switch ( V_134 -> type ) {
case V_137 :
V_22 -> V_49 = V_134 -> V_138 . V_139 ;
V_22 -> V_140 = 0 ;
break;
case V_141 :
V_22 -> V_142 = V_134 -> V_138 . V_140 ;
V_22 -> V_140 = 1 ;
break;
case V_143 :
if ( V_134 -> V_138 . time )
F_15 ( T_1 , TIME ) ;
else
F_14 ( T_1 , TIME ) ;
break;
case V_144 :
V_136 = V_134 -> V_138 . V_145 ;
break;
case V_146 :
if ( V_134 -> V_138 . V_147 && strcmp ( V_134 -> V_138 . V_147 , L_36 ) ) {
F_15 ( T_1 , V_119 ) ;
F_64 ( V_134 -> V_138 . V_147 ,
& V_22 -> V_120 ) ;
} else
F_14 ( T_1 , V_119 ) ;
break;
case V_148 :
V_131 = V_134 -> V_138 . V_149 ;
break;
case V_150 :
V_115 = V_134 -> V_138 . V_115 ;
break;
case V_151 :
V_22 -> V_152 = V_134 -> V_138 . V_152 ? 1 : 0 ;
break;
case V_153 :
V_22 -> V_154 = V_134 -> V_138 . V_155 ? 1 : 0 ;
break;
default:
break;
}
}
if ( ( V_136 != NULL ) || ( V_131 > 0 ) || V_115 ) {
if ( V_115 ) {
V_111 . V_115 = V_115 ;
if ( V_136 == NULL )
V_136 = L_37 ;
}
if ( V_136 != NULL ) {
if ( ! strcmp ( V_136 , L_36 ) ) {
V_111 . V_156 = false ;
V_111 . V_116 = V_157 ;
} else {
V_111 . V_156 = true ;
if ( F_65 ( V_136 , & V_111 ) ) {
F_66 ( L_38
L_39 ,
T_1 -> V_32 ) ;
return;
}
}
}
if ( V_131 > 0 ) {
V_131 = F_67 ( V_131 , sizeof( T_3 ) ) ;
V_111 . V_131 = V_131 ;
}
if ( V_110 . V_156 )
F_61 ( T_1 , & V_110 ) ;
if ( V_111 . V_156 )
F_58 ( T_1 , V_109 , & V_111 ) ;
}
}
void F_68 ( struct V_1 * T_1 , struct V_108 * V_109 ,
struct V_110 * V_158 )
{
struct V_1 * V_35 = T_1 -> V_35 ;
struct V_33 * V_22 = & T_1 -> V_22 ;
int V_159 = T_1 -> V_34 ;
bool V_160 = V_109 -> V_161 . V_162 && ! V_109 -> V_161 . V_163 ;
V_22 -> V_164 = V_165 . V_164 ? 0 : 1 ;
V_22 -> V_152 = ! V_109 -> V_166 ;
V_22 -> V_154 = V_109 -> V_155 ? 1 : 0 ;
F_15 ( T_1 , V_167 ) ;
F_15 ( T_1 , V_168 ) ;
if ( T_1 -> V_169 ) {
F_15 ( T_1 , V_170 ) ;
F_13 ( T_1 , false ) ;
if ( V_35 -> V_171 > 1 ) {
V_22 -> V_30 |= V_172 ;
V_22 -> V_152 = 0 ;
}
}
if ( ! V_22 -> V_49 || ( V_109 -> V_173 != V_174 ||
V_109 -> V_175 != V_176 ) ) {
if ( V_109 -> V_140 ) {
F_15 ( T_1 , V_177 ) ;
V_22 -> V_140 = 1 ;
V_22 -> V_142 = V_109 -> V_140 ;
} else {
V_22 -> V_49 = V_109 -> V_178 ;
}
}
if ( ( V_35 != T_1 ) && V_35 -> V_169 ) {
V_22 -> V_142 = 0 ;
V_22 -> V_49 = 0 ;
}
if ( V_109 -> V_179 )
V_22 -> V_142 = 0 ;
if ( V_109 -> V_180 ) {
T_1 -> V_22 . V_30 |=
V_181 |
V_182 |
V_31 ;
V_22 -> V_180 = 1 ;
}
if ( V_109 -> V_183 ) {
F_15 ( T_1 , V_184 ) ;
V_22 -> V_185 = V_159 ;
}
if ( F_16 ( T_1 ) )
T_1 -> V_22 . V_132 = 1 ;
if ( V_158 && V_158 -> V_156 && ! T_1 -> V_186 )
F_58 ( T_1 , V_109 , V_158 ) ;
if ( V_109 -> V_187 ) {
V_22 -> V_188 = V_109 -> V_187 ;
F_15 ( T_1 , V_189 ) ;
}
if ( F_69 ( & V_109 -> V_161 ) || V_109 -> V_190 )
F_15 ( T_1 , V_191 ) ;
if ( V_109 -> V_139 )
F_15 ( T_1 , V_177 ) ;
if ( V_109 -> V_192 &&
( ! V_165 . V_164 &&
( ! V_109 -> V_166 || F_69 ( & V_109 -> V_161 ) || V_160 ||
V_109 -> V_193 ) ) )
F_15 ( T_1 , TIME ) ;
if ( V_109 -> V_194 && ! T_1 -> V_186 ) {
F_15 ( T_1 , TIME ) ;
F_15 ( T_1 , V_195 ) ;
F_15 ( T_1 , V_191 ) ;
}
if ( V_109 -> V_183 )
F_15 ( T_1 , V_196 ) ;
if ( V_109 -> V_197 )
F_15 ( T_1 , V_198 ) ;
if ( V_109 -> V_199 ) {
V_22 -> V_200 = 0 ;
V_22 -> V_201 = 1 ;
}
if ( V_109 -> V_118 && ! T_1 -> V_186 ) {
F_15 ( T_1 , V_119 ) ;
V_22 -> V_120 = V_109 -> V_118 ;
}
if ( V_109 -> V_202 )
F_15 ( T_1 , V_203 ) ;
V_22 -> V_204 = V_159 ;
V_22 -> V_205 = V_159 ;
V_22 -> V_206 = V_159 && ! V_165 . V_206 ;
V_22 -> V_207 = V_159 ;
if ( V_109 -> V_208 )
V_22 -> V_209 = V_159 ;
if ( V_109 -> V_210 )
V_22 -> V_211 = V_159 ;
if ( V_109 -> V_212 )
F_15 ( T_1 , V_213 ) ;
if ( V_109 -> V_214 ) {
T_1 -> V_22 . V_30 |=
V_181 |
V_182 ;
}
if ( F_70 ( T_1 ) )
V_22 -> V_215 = 1 ;
if ( F_71 ( & V_109 -> V_161 ) && F_70 ( T_1 ) &&
! V_109 -> V_216 )
V_22 -> V_217 = 1 ;
if ( T_1 -> V_218 ) {
V_22 -> V_215 = 0 ;
V_22 -> V_217 = 0 ;
}
V_219 = V_109 -> V_219 ;
if ( V_109 -> V_220 ) {
V_22 -> V_220 = 1 ;
V_22 -> V_219 = V_109 -> V_219 ;
}
if ( T_1 -> V_221 )
F_28 ( V_22 ) ;
if ( V_109 -> V_222 ) {
V_22 -> V_54 = 1 ;
V_22 -> V_73 = 0 ;
}
if ( V_109 -> V_223 ) {
V_22 -> V_54 = 0 ;
V_22 -> V_73 = 1 ;
}
F_62 ( T_1 , V_109 ) ;
T_1 -> V_224 = V_109 -> V_224 ;
}
static int F_72 ( struct V_1 * T_1 , int V_225 , int V_226 )
{
if ( T_1 -> V_227 )
V_226 = 1 ;
T_1 -> V_228 = F_73 ( V_225 , V_226 , sizeof( int ) ) ;
if ( T_1 -> V_228 ) {
int V_229 , V_230 ;
for ( V_229 = 0 ; V_229 < V_225 ; V_229 ++ ) {
for ( V_230 = 0 ; V_230 < V_226 ; V_230 ++ ) {
F_74 ( T_1 , V_229 , V_230 ) = - 1 ;
}
}
}
return T_1 -> V_228 != NULL ? 0 : - V_61 ;
}
static int F_75 ( struct V_1 * T_1 ,
int V_231 , void * V_232 )
{
int V_229 , V_230 ;
for ( V_229 = 0 ; V_229 < F_76 ( T_1 -> V_228 ) ; V_229 ++ ) {
for ( V_230 = 0 ; V_230 < F_77 ( T_1 -> V_228 ) ; V_230 ++ ) {
int V_228 = F_74 ( T_1 , V_229 , V_230 ) ,
V_60 = F_78 ( V_228 , V_231 , V_232 ) ;
if ( V_60 )
return V_60 ;
}
}
return 0 ;
}
int F_79 ( struct V_1 * T_1 , const char * V_233 )
{
return F_75 ( T_1 ,
V_234 ,
( void * ) V_233 ) ;
}
int F_80 ( struct V_1 * T_1 , const char * V_233 )
{
char * V_235 = F_54 ( V_233 ) ;
if ( V_235 != NULL ) {
free ( T_1 -> V_233 ) ;
T_1 -> V_233 = V_235 ;
return 0 ;
}
return - 1 ;
}
static int F_81 ( struct V_1 * T_1 ,
const char * V_236 , const char * V_233 )
{
char * V_235 ;
if ( T_1 -> V_233 == NULL )
return F_80 ( T_1 , V_233 ) ;
if ( F_30 ( & V_235 , V_236 , T_1 -> V_233 , V_233 ) > 0 ) {
free ( T_1 -> V_233 ) ;
T_1 -> V_233 = V_235 ;
return 0 ;
}
return - 1 ;
}
int F_82 ( struct V_1 * T_1 , const char * V_233 )
{
return F_81 ( T_1 , L_40 , V_233 ) ;
}
int F_83 ( struct V_1 * T_1 , const char * V_233 )
{
return F_81 ( T_1 , L_41 , V_233 ) ;
}
int F_84 ( struct V_1 * T_1 )
{
return F_75 ( T_1 ,
V_237 ,
0 ) ;
}
int F_85 ( struct V_1 * T_1 )
{
return F_75 ( T_1 ,
V_238 ,
0 ) ;
}
int F_86 ( struct V_1 * T_1 , int V_225 , int V_226 )
{
if ( V_225 == 0 || V_226 == 0 )
return 0 ;
if ( T_1 -> V_227 )
V_226 = 1 ;
T_1 -> V_239 = F_73 ( V_225 , V_226 , sizeof( struct V_240 ) ) ;
if ( T_1 -> V_239 == NULL )
return - V_61 ;
T_1 -> V_66 = F_21 ( V_225 * V_226 * sizeof( T_3 ) ) ;
if ( T_1 -> V_66 == NULL ) {
F_87 ( T_1 -> V_239 ) ;
T_1 -> V_239 = NULL ;
return - V_61 ;
}
return 0 ;
}
static void F_88 ( struct V_1 * T_1 )
{
F_87 ( T_1 -> V_228 ) ;
T_1 -> V_228 = NULL ;
}
static void F_89 ( struct V_1 * T_1 )
{
F_87 ( T_1 -> V_239 ) ;
T_1 -> V_239 = NULL ;
F_36 ( & T_1 -> V_66 ) ;
}
static void F_90 ( struct V_1 * T_1 )
{
struct V_133 * V_134 , * V_241 ;
F_91 (term, h, &evsel->config_terms, list) {
F_92 ( & V_134 -> V_242 ) ;
free ( V_134 ) ;
}
}
void F_93 ( struct V_1 * T_1 )
{
int V_229 , V_230 ;
for ( V_229 = 0 ; V_229 < F_76 ( T_1 -> V_228 ) ; V_229 ++ )
for ( V_230 = 0 ; V_230 < F_77 ( T_1 -> V_228 ) ; ++ V_230 ) {
F_94 ( F_74 ( T_1 , V_229 , V_230 ) ) ;
F_74 ( T_1 , V_229 , V_230 ) = - 1 ;
}
}
void F_95 ( struct V_1 * T_1 )
{
assert ( F_96 ( & T_1 -> V_40 ) ) ;
assert ( T_1 -> V_38 == NULL ) ;
F_88 ( T_1 ) ;
F_89 ( T_1 ) ;
F_90 ( T_1 ) ;
F_97 ( T_1 -> V_243 ) ;
F_98 ( T_1 -> V_244 ) ;
F_98 ( T_1 -> V_245 ) ;
F_99 ( T_1 -> V_246 ) ;
F_36 ( & T_1 -> V_105 ) ;
F_36 ( & T_1 -> V_32 ) ;
V_5 . F_6 ( T_1 ) ;
}
void F_31 ( struct V_1 * T_1 )
{
F_95 ( T_1 ) ;
free ( T_1 ) ;
}
void F_100 ( struct V_1 * T_1 , int V_229 , int V_230 ,
struct V_247 * V_248 )
{
struct V_247 V_249 ;
if ( ! T_1 -> V_250 )
return;
if ( V_229 == - 1 ) {
V_249 = T_1 -> V_250 -> V_251 ;
T_1 -> V_250 -> V_251 = * V_248 ;
} else {
V_249 = * F_101 ( T_1 -> V_250 , V_229 , V_230 ) ;
* F_101 ( T_1 -> V_250 , V_229 , V_230 ) = * V_248 ;
}
V_248 -> V_138 = V_248 -> V_138 - V_249 . V_138 ;
V_248 -> V_252 = V_248 -> V_252 - V_249 . V_252 ;
V_248 -> V_253 = V_248 -> V_253 - V_249 . V_253 ;
}
void F_102 ( struct V_247 * V_248 ,
bool V_37 , T_8 * V_254 )
{
T_8 V_255 = 0 ;
if ( V_37 ) {
if ( V_248 -> V_253 == 0 ) {
V_255 = - 1 ;
V_248 -> V_138 = 0 ;
} else if ( V_248 -> V_253 < V_248 -> V_252 ) {
V_255 = 1 ;
V_248 -> V_138 = ( T_3 ) ( ( double ) V_248 -> V_138 * V_248 -> V_252 / V_248 -> V_253 + 0.5 ) ;
}
} else
V_248 -> V_252 = V_248 -> V_253 = 0 ;
if ( V_254 )
* V_254 = V_255 ;
}
static int F_103 ( struct V_1 * T_1 )
{
T_3 V_30 = T_1 -> V_22 . V_30 ;
int V_256 = sizeof( T_3 ) ;
int V_6 = 0 ;
int V_257 = 1 ;
if ( V_30 & V_181 )
V_6 += sizeof( T_3 ) ;
if ( V_30 & V_182 )
V_6 += sizeof( T_3 ) ;
if ( V_30 & V_31 )
V_256 += sizeof( T_3 ) ;
if ( V_30 & V_172 ) {
V_257 = T_1 -> V_171 ;
V_6 += sizeof( T_3 ) ;
}
V_6 += V_256 * V_257 ;
return V_6 ;
}
int F_104 ( struct V_1 * T_1 , int V_229 , int V_230 ,
struct V_247 * V_248 )
{
T_2 V_6 = F_103 ( T_1 ) ;
memset ( V_248 , 0 , sizeof( * V_248 ) ) ;
if ( F_74 ( T_1 , V_229 , V_230 ) < 0 )
return - V_7 ;
if ( F_105 ( F_74 ( T_1 , V_229 , V_230 ) , V_248 -> V_258 , V_6 ) <= 0 )
return - V_259 ;
return 0 ;
}
static int
F_106 ( struct V_1 * T_1 , int V_229 , int V_230 )
{
struct V_247 * V_248 = F_101 ( T_1 -> V_260 , V_229 , V_230 ) ;
return F_104 ( T_1 , V_229 , V_230 , V_248 ) ;
}
static void
F_107 ( struct V_1 * V_261 , int V_229 , int V_230 ,
T_3 V_138 , T_3 V_252 , T_3 V_253 )
{
struct V_247 * V_248 ;
V_248 = F_101 ( V_261 -> V_260 , V_229 , V_230 ) ;
V_248 -> V_138 = V_138 ;
V_248 -> V_252 = V_252 ;
V_248 -> V_253 = V_253 ;
V_248 -> V_262 = true ;
}
static int
F_108 ( struct V_1 * V_35 ,
int V_229 , int V_230 , T_3 * V_263 )
{
T_3 V_30 = V_35 -> V_22 . V_30 ;
struct V_264 * V_265 ;
T_3 V_257 , V_252 = 0 , V_253 = 0 , V_11 ;
V_257 = * V_263 ++ ;
if ( V_257 != ( T_3 ) V_35 -> V_171 )
return - V_7 ;
if ( V_30 & V_181 )
V_252 = * V_263 ++ ;
if ( V_30 & V_182 )
V_253 = * V_263 ++ ;
V_265 = (struct V_264 * ) V_263 ;
F_107 ( V_35 , V_229 , V_230 ,
V_265 [ 0 ] . V_266 , V_252 , V_253 ) ;
for ( V_11 = 1 ; V_11 < V_257 ; V_11 ++ ) {
struct V_1 * V_261 ;
V_261 = F_109 ( V_35 -> V_38 , V_265 [ V_11 ] . V_66 ) ;
if ( ! V_261 )
return - V_7 ;
F_107 ( V_261 , V_229 , V_230 ,
V_265 [ V_11 ] . V_266 , V_252 , V_253 ) ;
}
return 0 ;
}
static int
F_110 ( struct V_1 * V_35 , int V_229 , int V_230 )
{
struct V_267 * V_268 = V_35 -> V_269 ;
T_3 V_30 = V_35 -> V_22 . V_30 ;
int V_6 = F_103 ( V_35 ) ;
T_3 * V_263 = V_268 -> V_270 ;
if ( ! ( V_30 & V_31 ) )
return - V_7 ;
if ( ! F_70 ( V_35 ) )
return - V_7 ;
if ( ! V_263 ) {
V_263 = F_21 ( V_6 ) ;
if ( ! V_263 )
return - V_61 ;
V_268 -> V_270 = V_263 ;
}
if ( F_74 ( V_35 , V_229 , V_230 ) < 0 )
return - V_7 ;
if ( F_105 ( F_74 ( V_35 , V_229 , V_230 ) , V_263 , V_6 ) <= 0 )
return - V_259 ;
return F_108 ( V_35 , V_229 , V_230 , V_263 ) ;
}
int F_111 ( struct V_1 * T_1 , int V_229 , int V_230 )
{
T_3 V_30 = T_1 -> V_22 . V_30 ;
if ( V_30 & V_172 )
return F_110 ( T_1 , V_229 , V_230 ) ;
else
return F_106 ( T_1 , V_229 , V_230 ) ;
}
int F_112 ( struct V_1 * T_1 ,
int V_229 , int V_230 , bool V_37 )
{
struct V_247 V_248 ;
T_2 V_271 = V_37 ? 3 : 1 ;
if ( F_74 ( T_1 , V_229 , V_230 ) < 0 )
return - V_7 ;
if ( T_1 -> V_260 == NULL && F_113 ( T_1 , V_229 + 1 , V_230 + 1 ) < 0 )
return - V_61 ;
if ( F_105 ( F_74 ( T_1 , V_229 , V_230 ) , & V_248 , V_271 * sizeof( T_3 ) ) <= 0 )
return - V_259 ;
F_100 ( T_1 , V_229 , V_230 , & V_248 ) ;
F_102 ( & V_248 , V_37 , NULL ) ;
* F_101 ( T_1 -> V_260 , V_229 , V_230 ) = V_248 ;
return 0 ;
}
static int F_114 ( struct V_1 * T_1 , int V_229 , int V_230 )
{
struct V_1 * V_35 = T_1 -> V_35 ;
int V_228 ;
if ( F_70 ( T_1 ) )
return - 1 ;
F_115 ( ! V_35 -> V_228 ) ;
V_228 = F_74 ( V_35 , V_229 , V_230 ) ;
F_115 ( V_228 == - 1 ) ;
return V_228 ;
}
static void F_116 ( char * V_106 , T_2 V_6 , T_3 V_266 , struct V_272 * V_273 )
{
bool V_274 = true ;
int V_11 = 0 ;
do {
if ( V_266 & V_273 [ V_11 ] . V_25 ) {
V_106 += F_41 ( V_106 , V_6 , L_42 , V_274 ? L_1 : L_43 , V_273 [ V_11 ] . V_32 ) ;
V_274 = false ;
}
} while ( V_273 [ ++ V_11 ] . V_32 != NULL );
}
static void F_117 ( char * V_106 , T_2 V_6 , T_3 V_266 )
{
#define F_118 ( T_9 ) { PERF_SAMPLE_##n, #n }
struct V_272 V_273 [] = {
F_118 ( V_167 ) , F_118 ( V_168 ) , F_118 ( TIME ) , F_118 ( V_184 ) ,
F_118 ( V_170 ) , F_118 ( V_113 ) , F_118 ( V_28 ) , F_118 ( V_191 ) ,
F_118 ( V_177 ) , F_118 ( V_275 ) , F_118 ( V_195 ) ,
F_118 ( V_119 ) , F_118 ( V_126 ) , F_118 ( V_127 ) ,
F_118 ( V_29 ) , F_118 ( V_189 ) , F_118 ( V_196 ) ,
F_118 ( V_203 ) , F_118 ( V_198 ) ,
{ . V_32 = NULL , }
} ;
#undef F_118
F_116 ( V_106 , V_6 , V_266 , V_273 ) ;
}
static void F_119 ( char * V_106 , T_2 V_6 , T_3 V_266 )
{
#define F_118 ( T_9 ) { PERF_SAMPLE_BRANCH_##n, #n }
struct V_272 V_273 [] = {
F_118 ( V_276 ) , F_118 ( V_277 ) , F_118 ( V_278 ) , F_118 ( V_279 ) ,
F_118 ( V_280 ) , F_118 ( V_281 ) , F_118 ( V_282 ) ,
F_118 ( V_283 ) , F_118 ( V_284 ) , F_118 ( V_285 ) ,
F_118 ( V_286 ) , F_118 ( V_287 ) , F_118 ( V_288 ) ,
F_118 ( V_289 ) , F_118 ( V_290 ) , F_118 ( V_291 ) ,
{ . V_32 = NULL , }
} ;
#undef F_118
F_116 ( V_106 , V_6 , V_266 , V_273 ) ;
}
static void F_120 ( char * V_106 , T_2 V_6 , T_3 V_266 )
{
#define F_118 ( T_9 ) { PERF_FORMAT_##n, #n }
struct V_272 V_273 [] = {
F_118 ( V_292 ) , F_118 ( V_293 ) ,
F_118 ( V_28 ) , F_118 ( V_294 ) ,
{ . V_32 = NULL , }
} ;
#undef F_118
F_116 ( V_106 , V_6 , V_266 , V_273 ) ;
}
int F_121 ( T_10 * V_295 , struct V_33 * V_22 ,
T_11 V_296 , void * V_269 )
{
char V_106 [ V_297 ] ;
int V_100 = 0 ;
F_122 ( type , V_298 ) ;
F_122 ( V_6 , V_298 ) ;
F_122 ( V_52 , V_299 ) ;
F_123 ( L_44 , V_49 , V_298 ) ;
F_122 ( V_8 , V_300 ) ;
F_122 ( V_30 , V_301 ) ;
F_122 ( V_215 , V_298 ) ;
F_122 ( V_152 , V_298 ) ;
F_122 ( V_302 , V_298 ) ;
F_122 ( V_303 , V_298 ) ;
F_122 ( V_73 , V_298 ) ;
F_122 ( V_54 , V_298 ) ;
F_122 ( V_74 , V_298 ) ;
F_122 ( V_304 , V_298 ) ;
F_122 ( V_205 , V_298 ) ;
F_122 ( V_207 , V_298 ) ;
F_122 ( V_140 , V_298 ) ;
F_122 ( V_180 , V_298 ) ;
F_122 ( V_217 , V_298 ) ;
F_122 ( V_204 , V_298 ) ;
F_122 ( V_200 , V_298 ) ;
F_122 ( V_57 , V_298 ) ;
F_122 ( V_185 , V_298 ) ;
F_122 ( V_164 , V_298 ) ;
F_122 ( V_78 , V_298 ) ;
F_122 ( V_79 , V_298 ) ;
F_122 ( V_305 , V_298 ) ;
F_122 ( V_132 , V_298 ) ;
F_122 ( V_206 , V_298 ) ;
F_122 ( V_306 , V_298 ) ;
F_122 ( V_220 , V_298 ) ;
F_122 ( V_211 , V_298 ) ;
F_122 ( V_154 , V_298 ) ;
F_123 ( L_45 , V_201 , V_298 ) ;
F_122 ( V_90 , V_298 ) ;
F_123 ( L_46 , V_89 , V_299 ) ;
F_123 ( L_47 , V_307 , V_299 ) ;
F_122 ( V_120 , V_308 ) ;
F_122 ( V_128 , V_299 ) ;
F_122 ( V_130 , V_298 ) ;
F_122 ( V_219 , V_309 ) ;
F_122 ( V_188 , V_299 ) ;
F_122 ( V_310 , V_298 ) ;
F_122 ( V_114 , V_298 ) ;
return V_100 ;
}
static int F_124 ( T_10 * V_295 , const char * V_32 , const char * V_138 ,
void * V_269 V_2 )
{
return fprintf ( V_295 , L_48 , V_32 , V_138 ) ;
}
static bool V_224 ( struct V_1 * T_1 ,
struct V_311 * V_246 ,
int V_230 , int V_60 )
{
if ( ! T_1 -> V_224 )
return false ;
if ( T_1 -> V_227 )
return false ;
if ( V_60 != - V_312 )
return false ;
if ( V_246 -> V_257 == 1 )
return false ;
if ( F_125 ( V_246 , V_230 ) )
return false ;
F_59 ( L_49 ,
F_126 ( V_246 , V_230 ) ) ;
return true ;
}
int F_127 ( struct V_1 * T_1 , struct V_313 * V_244 ,
struct V_311 * V_246 )
{
int V_229 , V_230 , V_226 ;
unsigned long V_314 = V_315 ;
int V_316 = - 1 , V_60 ;
enum { V_317 , V_318 , V_319 } V_320 = V_317 ;
if ( V_165 . V_154 && T_1 -> V_22 . V_154 )
return - V_7 ;
if ( V_244 == NULL ) {
static struct V_313 * V_321 ;
if ( V_321 == NULL ) {
V_321 = F_128 () ;
if ( V_321 == NULL )
return - V_61 ;
}
V_244 = V_321 ;
}
if ( V_246 == NULL ) {
static struct V_311 * V_322 ;
if ( V_322 == NULL ) {
V_322 = F_129 ( - 1 ) ;
if ( V_322 == NULL )
return - V_61 ;
}
V_246 = V_322 ;
}
if ( T_1 -> V_227 )
V_226 = 1 ;
else
V_226 = V_246 -> V_257 ;
if ( T_1 -> V_228 == NULL &&
F_72 ( T_1 , V_244 -> V_257 , V_226 ) < 0 )
return - V_61 ;
if ( T_1 -> V_243 ) {
V_314 |= V_323 ;
V_316 = T_1 -> V_243 -> V_228 ;
}
V_324:
if ( V_165 . V_325 )
T_1 -> V_22 . V_219 = V_326 ;
if ( V_165 . V_219 ) {
T_1 -> V_22 . V_220 = 0 ;
T_1 -> V_22 . V_219 = 0 ;
}
if ( V_165 . V_327 )
V_314 &= ~ ( unsigned long ) V_315 ;
if ( V_165 . V_206 )
T_1 -> V_22 . V_206 = 0 ;
if ( V_165 . V_79 )
T_1 -> V_22 . V_79 = T_1 -> V_22 . V_78 = 0 ;
if ( V_165 . V_328 )
T_1 -> V_22 . V_120 &= ~ ( V_124 |
V_123 ) ;
if ( V_165 . V_329 && T_1 -> V_22 . V_152 )
T_1 -> V_22 . V_30 &= ~ ( V_172 | V_31 ) ;
V_330:
if ( V_165 . V_164 )
T_1 -> V_22 . V_164 = 0 ;
if ( V_331 >= 2 ) {
fprintf ( V_332 , L_50 , V_333 ) ;
fprintf ( V_332 , L_51 ) ;
F_121 ( V_332 , & T_1 -> V_22 , F_124 , NULL ) ;
fprintf ( V_332 , L_50 , V_333 ) ;
}
for ( V_229 = 0 ; V_229 < V_244 -> V_257 ; V_229 ++ ) {
for ( V_230 = 0 ; V_230 < V_226 ; V_230 ++ ) {
int V_228 , V_334 ;
if ( ! T_1 -> V_243 && ! T_1 -> V_227 )
V_316 = F_126 ( V_246 , V_230 ) ;
V_334 = F_114 ( T_1 , V_229 , V_230 ) ;
V_335:
F_130 ( L_52 ,
V_316 , V_244 -> V_336 [ V_229 ] , V_334 , V_314 ) ;
F_2 () ;
V_228 = F_131 ( & T_1 -> V_22 , V_316 , V_244 -> V_336 [ V_229 ] ,
V_334 , V_314 ) ;
F_74 ( T_1 , V_229 , V_230 ) = V_228 ;
if ( V_228 < 0 ) {
V_60 = - V_259 ;
if ( V_224 ( T_1 , V_246 , V_230 , V_60 ) ) {
V_226 -- ;
V_230 -- ;
V_60 = 0 ;
continue;
}
F_130 ( L_53 ,
V_60 ) ;
goto V_337;
}
F_130 ( L_54 , V_228 ) ;
if ( T_1 -> V_39 >= 0 ) {
int V_338 = V_228 ;
int V_39 = T_1 -> V_39 ;
V_60 = F_78 ( V_338 ,
V_339 ,
V_39 ) ;
if ( V_60 && V_259 != V_340 ) {
F_66 ( L_55 ,
V_39 , strerror ( V_259 ) ) ;
V_60 = - V_7 ;
goto V_341;
}
}
V_320 = V_317 ;
if ( V_165 . V_219 ||
V_165 . V_325 ) {
V_60 = - V_7 ;
goto V_341;
}
}
}
return 0 ;
V_337:
if ( V_60 == - V_342 && V_320 < V_319 ) {
struct V_343 V_344 ;
int V_345 = V_259 ;
if ( F_132 ( V_346 , & V_344 ) == 0 ) {
if ( V_320 == V_317 )
V_344 . V_347 = V_344 . V_348 ;
else {
V_344 . V_347 = V_344 . V_348 + 1000 ;
V_344 . V_348 = V_344 . V_347 ;
}
if ( F_133 ( V_346 , & V_344 ) == 0 ) {
V_320 ++ ;
V_259 = V_345 ;
goto V_335;
}
}
V_259 = V_345 ;
}
if ( V_60 != - V_7 || V_229 > 0 || V_230 > 0 )
goto V_341;
if ( ! V_165 . V_154 && T_1 -> V_22 . V_154 ) {
V_165 . V_154 = true ;
F_130 ( L_56 ) ;
goto V_341;
} else if ( ! V_165 . V_325 && T_1 -> V_22 . V_220 ) {
V_165 . V_325 = true ;
F_130 ( L_57 ) ;
goto V_324;
} else if ( ! V_165 . V_219 && T_1 -> V_22 . V_220 ) {
V_165 . V_219 = true ;
F_130 ( L_58 ) ;
goto V_324;
} else if ( ! V_165 . V_327 && ( V_314 & V_315 ) ) {
V_165 . V_327 = true ;
F_130 ( L_59 ) ;
goto V_324;
} else if ( ! V_165 . V_206 && T_1 -> V_22 . V_206 ) {
V_165 . V_206 = true ;
F_130 ( L_60 ) ;
goto V_324;
} else if ( ! V_165 . V_79 &&
( T_1 -> V_22 . V_79 || T_1 -> V_22 . V_78 ) ) {
V_165 . V_79 = true ;
F_130 ( L_61 ) ;
goto V_324;
} else if ( ! V_165 . V_164 ) {
V_165 . V_164 = true ;
F_130 ( L_62 ) ;
goto V_330;
} else if ( ! V_165 . V_328 &&
( T_1 -> V_22 . V_120 &
( V_123 |
V_124 ) ) ) {
V_165 . V_328 = true ;
F_130 ( L_63 ) ;
goto V_324;
} else if ( ! V_165 . V_329 &&
T_1 -> V_22 . V_152 &&
( T_1 -> V_22 . V_30 & V_172 ) ) {
V_165 . V_329 = true ;
F_130 ( L_64 ) ;
goto V_324;
}
V_341:
do {
while ( -- V_230 >= 0 ) {
F_94 ( F_74 ( T_1 , V_229 , V_230 ) ) ;
F_74 ( T_1 , V_229 , V_230 ) = - 1 ;
}
V_230 = V_226 ;
} while ( -- V_229 >= 0 );
return V_60 ;
}
void F_134 ( struct V_1 * T_1 )
{
if ( T_1 -> V_228 == NULL )
return;
F_93 ( T_1 ) ;
F_88 ( T_1 ) ;
}
int F_135 ( struct V_1 * T_1 ,
struct V_313 * V_244 )
{
return F_127 ( T_1 , V_244 , NULL ) ;
}
int F_136 ( struct V_1 * T_1 ,
struct V_311 * V_246 )
{
return F_127 ( T_1 , NULL , V_246 ) ;
}
static int F_137 ( const struct V_1 * T_1 ,
const union V_349 * V_350 ,
struct V_351 * V_352 )
{
T_3 type = T_1 -> V_22 . V_8 ;
const T_3 * V_353 = V_350 -> V_352 . V_353 ;
bool V_354 = T_1 -> V_355 ;
union V_356 V_357 ;
V_353 += ( ( V_350 -> V_358 . V_6 -
sizeof( V_350 -> V_358 ) ) / sizeof( T_3 ) ) - 1 ;
if ( type & V_13 ) {
V_352 -> V_66 = * V_353 ;
V_353 -- ;
}
if ( type & V_19 ) {
V_357 . V_359 = * V_353 ;
if ( V_354 ) {
V_357 . V_359 = F_138 ( V_357 . V_359 ) ;
V_357 . V_360 [ 0 ] = F_139 ( V_357 . V_360 [ 0 ] ) ;
}
V_352 -> V_229 = V_357 . V_360 [ 0 ] ;
V_353 -- ;
}
if ( type & V_20 ) {
V_352 -> V_361 = * V_353 ;
V_353 -- ;
}
if ( type & V_14 ) {
V_352 -> V_66 = * V_353 ;
V_353 -- ;
}
if ( type & V_17 ) {
V_352 -> time = * V_353 ;
V_353 -- ;
}
if ( type & V_16 ) {
V_357 . V_359 = * V_353 ;
if ( V_354 ) {
V_357 . V_359 = F_138 ( V_357 . V_359 ) ;
V_357 . V_360 [ 0 ] = F_139 ( V_357 . V_360 [ 0 ] ) ;
V_357 . V_360 [ 1 ] = F_139 ( V_357 . V_360 [ 1 ] ) ;
}
V_352 -> V_316 = V_357 . V_360 [ 0 ] ;
V_352 -> V_362 = V_357 . V_360 [ 1 ] ;
V_353 -- ;
}
return 0 ;
}
static inline bool F_140 ( const void * V_363 , T_12 V_364 , const void * V_365 ,
T_3 V_6 )
{
return V_6 > V_364 || V_365 + V_6 > V_363 ;
}
int F_141 ( struct V_1 * T_1 , union V_349 * V_350 ,
struct V_351 * V_263 )
{
T_3 type = T_1 -> V_22 . V_8 ;
bool V_354 = T_1 -> V_355 ;
const T_3 * V_353 ;
T_12 V_364 = V_350 -> V_358 . V_6 ;
const void * V_363 = ( void * ) V_350 + V_364 ;
T_3 V_366 ;
union V_356 V_357 ;
memset ( V_263 , 0 , sizeof( * V_263 ) ) ;
V_263 -> V_229 = V_263 -> V_316 = V_263 -> V_362 = - 1 ;
V_263 -> V_361 = V_263 -> V_66 = V_263 -> time = - 1ULL ;
V_263 -> V_139 = T_1 -> V_22 . V_49 ;
V_263 -> V_367 = V_350 -> V_358 . V_368 & V_369 ;
if ( V_350 -> V_358 . type != V_370 ) {
if ( ! T_1 -> V_22 . V_164 )
return 0 ;
return F_137 ( T_1 , V_350 , V_263 ) ;
}
V_353 = V_350 -> V_352 . V_353 ;
if ( T_1 -> V_26 + sizeof( V_350 -> V_358 ) > V_350 -> V_358 . V_6 )
return - V_371 ;
V_263 -> V_66 = - 1ULL ;
if ( type & V_13 ) {
V_263 -> V_66 = * V_353 ;
V_353 ++ ;
}
if ( type & V_15 ) {
V_263 -> V_372 = * V_353 ;
V_353 ++ ;
}
if ( type & V_16 ) {
V_357 . V_359 = * V_353 ;
if ( V_354 ) {
V_357 . V_359 = F_138 ( V_357 . V_359 ) ;
V_357 . V_360 [ 0 ] = F_139 ( V_357 . V_360 [ 0 ] ) ;
V_357 . V_360 [ 1 ] = F_139 ( V_357 . V_360 [ 1 ] ) ;
}
V_263 -> V_316 = V_357 . V_360 [ 0 ] ;
V_263 -> V_362 = V_357 . V_360 [ 1 ] ;
V_353 ++ ;
}
if ( type & V_17 ) {
V_263 -> time = * V_353 ;
V_353 ++ ;
}
V_263 -> V_84 = 0 ;
if ( type & V_18 ) {
V_263 -> V_84 = * V_353 ;
V_353 ++ ;
}
if ( type & V_14 ) {
V_263 -> V_66 = * V_353 ;
V_353 ++ ;
}
if ( type & V_20 ) {
V_263 -> V_361 = * V_353 ;
V_353 ++ ;
}
if ( type & V_19 ) {
V_357 . V_359 = * V_353 ;
if ( V_354 ) {
V_357 . V_359 = F_138 ( V_357 . V_359 ) ;
V_357 . V_360 [ 0 ] = F_139 ( V_357 . V_360 [ 0 ] ) ;
}
V_263 -> V_229 = V_357 . V_360 [ 0 ] ;
V_353 ++ ;
}
if ( type & V_48 ) {
V_263 -> V_139 = * V_353 ;
V_353 ++ ;
}
if ( type & V_373 ) {
T_3 V_30 = T_1 -> V_22 . V_30 ;
F_142 ( V_353 ) ;
if ( V_30 & V_172 )
V_263 -> V_374 . V_375 . V_257 = * V_353 ;
else
V_263 -> V_374 . V_376 . V_266 = * V_353 ;
V_353 ++ ;
if ( V_30 & V_181 ) {
F_142 ( V_353 ) ;
V_263 -> V_374 . V_377 = * V_353 ;
V_353 ++ ;
}
if ( V_30 & V_182 ) {
F_142 ( V_353 ) ;
V_263 -> V_374 . V_378 = * V_353 ;
V_353 ++ ;
}
if ( V_30 & V_172 ) {
const T_3 V_379 = V_380 /
sizeof( struct V_264 ) ;
if ( V_263 -> V_374 . V_375 . V_257 > V_379 )
return - V_371 ;
V_366 = V_263 -> V_374 . V_375 . V_257 *
sizeof( struct V_264 ) ;
F_143 ( V_353 , V_366 , V_364 ) ;
V_263 -> V_374 . V_375 . V_258 =
(struct V_264 * ) V_353 ;
V_353 = ( void * ) V_353 + V_366 ;
} else {
F_142 ( V_353 ) ;
V_263 -> V_374 . V_376 . V_66 = * V_353 ;
V_353 ++ ;
}
}
if ( type & V_381 ) {
const T_3 V_382 = V_380 / sizeof( T_3 ) ;
F_142 ( V_353 ) ;
V_263 -> V_158 = (struct V_383 * ) V_353 ++ ;
if ( V_263 -> V_158 -> V_257 > V_382 )
return - V_371 ;
V_366 = V_263 -> V_158 -> V_257 * sizeof( T_3 ) ;
F_143 ( V_353 , V_366 , V_364 ) ;
V_353 = ( void * ) V_353 + V_366 ;
}
if ( type & V_47 ) {
F_142 ( V_353 ) ;
V_357 . V_359 = * V_353 ;
if ( F_144 ( V_354 ,
L_65 ) ) {
V_357 . V_359 = F_138 ( V_357 . V_359 ) ;
V_357 . V_360 [ 0 ] = F_139 ( V_357 . V_360 [ 0 ] ) ;
V_357 . V_360 [ 1 ] = F_139 ( V_357 . V_360 [ 1 ] ) ;
}
V_263 -> V_384 = V_357 . V_360 [ 0 ] ;
V_353 = ( void * ) V_353 + sizeof( T_7 ) ;
F_143 ( V_353 , V_263 -> V_384 , V_364 ) ;
V_263 -> V_385 = ( void * ) V_353 ;
V_353 = ( void * ) V_353 + V_263 -> V_384 ;
}
if ( type & V_386 ) {
const T_3 V_387 = V_380 /
sizeof( struct V_388 ) ;
F_142 ( V_353 ) ;
V_263 -> V_118 = (struct V_118 * ) V_353 ++ ;
if ( V_263 -> V_118 -> V_257 > V_387 )
return - V_371 ;
V_366 = V_263 -> V_118 -> V_257 * sizeof( struct V_388 ) ;
F_143 ( V_353 , V_366 , V_364 ) ;
V_353 = ( void * ) V_353 + V_366 ;
}
if ( type & V_389 ) {
F_142 ( V_353 ) ;
V_263 -> V_390 . V_391 = * V_353 ;
V_353 ++ ;
if ( V_263 -> V_390 . V_391 ) {
T_3 V_9 = T_1 -> V_22 . V_128 ;
V_366 = F_145 ( V_9 ) * sizeof( T_3 ) ;
F_143 ( V_353 , V_366 , V_364 ) ;
V_263 -> V_390 . V_9 = V_9 ;
V_263 -> V_390 . V_392 = ( T_3 * ) V_353 ;
V_353 = ( void * ) V_353 + V_366 ;
}
}
if ( type & V_393 ) {
F_142 ( V_353 ) ;
V_366 = * V_353 ++ ;
V_263 -> V_394 . V_365 = ( ( char * ) ( V_353 - 1 )
- ( char * ) V_350 ) ;
if ( ! V_366 ) {
V_263 -> V_394 . V_6 = 0 ;
} else {
F_143 ( V_353 , V_366 , V_364 ) ;
V_263 -> V_394 . V_263 = ( char * ) V_353 ;
V_353 = ( void * ) V_353 + V_366 ;
F_142 ( V_353 ) ;
V_263 -> V_394 . V_6 = * V_353 ++ ;
if ( F_144 ( V_263 -> V_394 . V_6 > V_366 ,
L_66 ) )
return - V_371 ;
}
}
if ( type & V_395 ) {
F_142 ( V_353 ) ;
V_263 -> V_396 = * V_353 ;
V_353 ++ ;
}
V_263 -> V_397 = V_398 ;
if ( type & V_399 ) {
F_142 ( V_353 ) ;
V_263 -> V_397 = * V_353 ;
V_353 ++ ;
}
V_263 -> V_400 = 0 ;
if ( type & V_401 ) {
F_142 ( V_353 ) ;
V_263 -> V_400 = * V_353 ;
V_353 ++ ;
}
V_263 -> V_402 . V_391 = V_403 ;
if ( type & V_404 ) {
F_142 ( V_353 ) ;
V_263 -> V_402 . V_391 = * V_353 ;
V_353 ++ ;
if ( V_263 -> V_402 . V_391 != V_403 ) {
T_3 V_9 = T_1 -> V_22 . V_188 ;
V_366 = F_145 ( V_9 ) * sizeof( T_3 ) ;
F_143 ( V_353 , V_366 , V_364 ) ;
V_263 -> V_402 . V_9 = V_9 ;
V_263 -> V_402 . V_392 = ( T_3 * ) V_353 ;
V_353 = ( void * ) V_353 + V_366 ;
}
}
V_263 -> V_405 = 0 ;
if ( type & V_406 ) {
V_263 -> V_405 = * V_353 ;
V_353 ++ ;
}
return 0 ;
}
T_2 F_146 ( const struct V_351 * V_352 , T_3 type ,
T_3 V_30 )
{
T_2 V_366 , V_93 = sizeof( struct V_407 ) ;
if ( type & V_13 )
V_93 += sizeof( T_3 ) ;
if ( type & V_15 )
V_93 += sizeof( T_3 ) ;
if ( type & V_16 )
V_93 += sizeof( T_3 ) ;
if ( type & V_17 )
V_93 += sizeof( T_3 ) ;
if ( type & V_18 )
V_93 += sizeof( T_3 ) ;
if ( type & V_14 )
V_93 += sizeof( T_3 ) ;
if ( type & V_20 )
V_93 += sizeof( T_3 ) ;
if ( type & V_19 )
V_93 += sizeof( T_3 ) ;
if ( type & V_48 )
V_93 += sizeof( T_3 ) ;
if ( type & V_373 ) {
V_93 += sizeof( T_3 ) ;
if ( V_30 & V_181 )
V_93 += sizeof( T_3 ) ;
if ( V_30 & V_182 )
V_93 += sizeof( T_3 ) ;
if ( V_30 & V_172 ) {
V_366 = V_352 -> V_374 . V_375 . V_257 *
sizeof( struct V_264 ) ;
V_93 += V_366 ;
} else {
V_93 += sizeof( T_3 ) ;
}
}
if ( type & V_381 ) {
V_366 = ( V_352 -> V_158 -> V_257 + 1 ) * sizeof( T_3 ) ;
V_93 += V_366 ;
}
if ( type & V_47 ) {
V_93 += sizeof( T_7 ) ;
V_93 += V_352 -> V_384 ;
}
if ( type & V_386 ) {
V_366 = V_352 -> V_118 -> V_257 * sizeof( struct V_388 ) ;
V_366 += sizeof( T_3 ) ;
V_93 += V_366 ;
}
if ( type & V_389 ) {
if ( V_352 -> V_390 . V_391 ) {
V_93 += sizeof( T_3 ) ;
V_366 = F_145 ( V_352 -> V_390 . V_9 ) * sizeof( T_3 ) ;
V_93 += V_366 ;
} else {
V_93 += sizeof( T_3 ) ;
}
}
if ( type & V_393 ) {
V_366 = V_352 -> V_394 . V_6 ;
V_93 += sizeof( T_3 ) ;
if ( V_366 ) {
V_93 += V_366 ;
V_93 += sizeof( T_3 ) ;
}
}
if ( type & V_395 )
V_93 += sizeof( T_3 ) ;
if ( type & V_399 )
V_93 += sizeof( T_3 ) ;
if ( type & V_401 )
V_93 += sizeof( T_3 ) ;
if ( type & V_404 ) {
if ( V_352 -> V_402 . V_391 ) {
V_93 += sizeof( T_3 ) ;
V_366 = F_145 ( V_352 -> V_402 . V_9 ) * sizeof( T_3 ) ;
V_93 += V_366 ;
} else {
V_93 += sizeof( T_3 ) ;
}
}
if ( type & V_406 )
V_93 += sizeof( T_3 ) ;
return V_93 ;
}
int F_147 ( union V_349 * V_350 , T_3 type ,
T_3 V_30 ,
const struct V_351 * V_352 ,
bool V_354 )
{
T_3 * V_353 ;
T_2 V_366 ;
union V_356 V_357 ;
V_353 = V_350 -> V_352 . V_353 ;
if ( type & V_13 ) {
* V_353 = V_352 -> V_66 ;
V_353 ++ ;
}
if ( type & V_15 ) {
* V_353 = V_352 -> V_372 ;
V_353 ++ ;
}
if ( type & V_16 ) {
V_357 . V_360 [ 0 ] = V_352 -> V_316 ;
V_357 . V_360 [ 1 ] = V_352 -> V_362 ;
if ( V_354 ) {
V_357 . V_360 [ 0 ] = F_139 ( V_357 . V_360 [ 0 ] ) ;
V_357 . V_360 [ 1 ] = F_139 ( V_357 . V_360 [ 1 ] ) ;
V_357 . V_359 = F_138 ( V_357 . V_359 ) ;
}
* V_353 = V_357 . V_359 ;
V_353 ++ ;
}
if ( type & V_17 ) {
* V_353 = V_352 -> time ;
V_353 ++ ;
}
if ( type & V_18 ) {
* V_353 = V_352 -> V_84 ;
V_353 ++ ;
}
if ( type & V_14 ) {
* V_353 = V_352 -> V_66 ;
V_353 ++ ;
}
if ( type & V_20 ) {
* V_353 = V_352 -> V_361 ;
V_353 ++ ;
}
if ( type & V_19 ) {
V_357 . V_360 [ 0 ] = V_352 -> V_229 ;
if ( V_354 ) {
V_357 . V_360 [ 0 ] = F_139 ( V_357 . V_360 [ 0 ] ) ;
V_357 . V_359 = F_138 ( V_357 . V_359 ) ;
}
* V_353 = V_357 . V_359 ;
V_353 ++ ;
}
if ( type & V_48 ) {
* V_353 = V_352 -> V_139 ;
V_353 ++ ;
}
if ( type & V_373 ) {
if ( V_30 & V_172 )
* V_353 = V_352 -> V_374 . V_375 . V_257 ;
else
* V_353 = V_352 -> V_374 . V_376 . V_266 ;
V_353 ++ ;
if ( V_30 & V_181 ) {
* V_353 = V_352 -> V_374 . V_377 ;
V_353 ++ ;
}
if ( V_30 & V_182 ) {
* V_353 = V_352 -> V_374 . V_378 ;
V_353 ++ ;
}
if ( V_30 & V_172 ) {
V_366 = V_352 -> V_374 . V_375 . V_257 *
sizeof( struct V_264 ) ;
memcpy ( V_353 , V_352 -> V_374 . V_375 . V_258 , V_366 ) ;
V_353 = ( void * ) V_353 + V_366 ;
} else {
* V_353 = V_352 -> V_374 . V_376 . V_66 ;
V_353 ++ ;
}
}
if ( type & V_381 ) {
V_366 = ( V_352 -> V_158 -> V_257 + 1 ) * sizeof( T_3 ) ;
memcpy ( V_353 , V_352 -> V_158 , V_366 ) ;
V_353 = ( void * ) V_353 + V_366 ;
}
if ( type & V_47 ) {
V_357 . V_360 [ 0 ] = V_352 -> V_384 ;
if ( F_144 ( V_354 ,
L_65 ) ) {
V_357 . V_360 [ 0 ] = F_139 ( V_357 . V_360 [ 0 ] ) ;
V_357 . V_360 [ 1 ] = F_139 ( V_357 . V_360 [ 1 ] ) ;
V_357 . V_359 = F_138 ( V_357 . V_359 ) ;
}
* V_353 = V_357 . V_359 ;
V_353 = ( void * ) V_353 + sizeof( T_7 ) ;
memcpy ( V_353 , V_352 -> V_385 , V_352 -> V_384 ) ;
V_353 = ( void * ) V_353 + V_352 -> V_384 ;
}
if ( type & V_386 ) {
V_366 = V_352 -> V_118 -> V_257 * sizeof( struct V_388 ) ;
V_366 += sizeof( T_3 ) ;
memcpy ( V_353 , V_352 -> V_118 , V_366 ) ;
V_353 = ( void * ) V_353 + V_366 ;
}
if ( type & V_389 ) {
if ( V_352 -> V_390 . V_391 ) {
* V_353 ++ = V_352 -> V_390 . V_391 ;
V_366 = F_145 ( V_352 -> V_390 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_353 , V_352 -> V_390 . V_392 , V_366 ) ;
V_353 = ( void * ) V_353 + V_366 ;
} else {
* V_353 ++ = 0 ;
}
}
if ( type & V_393 ) {
V_366 = V_352 -> V_394 . V_6 ;
* V_353 ++ = V_366 ;
if ( V_366 ) {
memcpy ( V_353 , V_352 -> V_394 . V_263 , V_366 ) ;
V_353 = ( void * ) V_353 + V_366 ;
* V_353 ++ = V_366 ;
}
}
if ( type & V_395 ) {
* V_353 = V_352 -> V_396 ;
V_353 ++ ;
}
if ( type & V_399 ) {
* V_353 = V_352 -> V_397 ;
V_353 ++ ;
}
if ( type & V_401 ) {
* V_353 = V_352 -> V_400 ;
V_353 ++ ;
}
if ( type & V_404 ) {
if ( V_352 -> V_402 . V_391 ) {
* V_353 ++ = V_352 -> V_402 . V_391 ;
V_366 = F_145 ( V_352 -> V_402 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_353 , V_352 -> V_402 . V_392 , V_366 ) ;
V_353 = ( void * ) V_353 + V_366 ;
} else {
* V_353 ++ = 0 ;
}
}
if ( type & V_406 ) {
* V_353 = V_352 -> V_405 ;
V_353 ++ ;
}
return 0 ;
}
struct V_408 * F_148 ( struct V_1 * T_1 , const char * V_32 )
{
return F_149 ( T_1 -> V_65 , V_32 ) ;
}
void * F_150 ( struct V_1 * T_1 , struct V_351 * V_352 ,
const char * V_32 )
{
struct V_408 * V_409 = F_148 ( T_1 , V_32 ) ;
int V_365 ;
if ( ! V_409 )
return NULL ;
V_365 = V_409 -> V_365 ;
if ( V_409 -> V_314 & V_410 ) {
V_365 = * ( int * ) ( V_352 -> V_385 + V_409 -> V_365 ) ;
V_365 &= 0xffff ;
}
return V_352 -> V_385 + V_365 ;
}
T_3 F_151 ( struct V_408 * V_409 , struct V_351 * V_352 ,
bool V_355 )
{
T_3 V_266 ;
void * V_411 = V_352 -> V_385 + V_409 -> V_365 ;
switch ( V_409 -> V_6 ) {
case 1 :
return * ( T_6 * ) V_411 ;
case 2 :
V_266 = * ( T_12 * ) V_411 ;
break;
case 4 :
V_266 = * ( T_7 * ) V_411 ;
break;
case 8 :
memcpy ( & V_266 , V_411 , sizeof( T_3 ) ) ;
break;
default:
return 0 ;
}
if ( ! V_355 )
return V_266 ;
switch ( V_409 -> V_6 ) {
case 2 :
return F_152 ( V_266 ) ;
case 4 :
return F_139 ( V_266 ) ;
case 8 :
return F_138 ( V_266 ) ;
default:
return 0 ;
}
return 0 ;
}
T_3 F_153 ( struct V_1 * T_1 , struct V_351 * V_352 ,
const char * V_32 )
{
struct V_408 * V_409 = F_148 ( T_1 , V_32 ) ;
if ( ! V_409 )
return 0 ;
return V_409 ? F_151 ( V_409 , V_352 , T_1 -> V_355 ) : 0 ;
}
bool F_154 ( struct V_1 * T_1 , int V_60 ,
char * V_412 , T_2 V_413 )
{
int V_414 ;
if ( ( V_60 == V_415 || V_60 == V_416 || V_60 == V_417 ) &&
T_1 -> V_22 . type == V_51 &&
T_1 -> V_22 . V_52 == V_53 ) {
F_41 ( V_412 , V_413 , L_9 ,
L_67 ) ;
T_1 -> V_22 . type = V_103 ;
T_1 -> V_22 . V_52 = V_418 ;
F_36 ( & T_1 -> V_32 ) ;
return true ;
} else if ( V_60 == V_419 && ! T_1 -> V_22 . V_54 &&
( V_414 = F_25 () ) > 1 ) {
const char * V_32 = F_53 ( T_1 ) ;
char * V_420 ;
if ( F_30 ( & V_420 , L_68 , V_32 , strchr ( V_32 , ':' ) ? L_1 : L_3 ) < 0 )
return false ;
if ( T_1 -> V_32 )
free ( T_1 -> V_32 ) ;
T_1 -> V_32 = V_420 ;
F_41 ( V_412 , V_413 ,
L_69 , V_414 ) ;
T_1 -> V_22 . V_54 = 1 ;
return true ;
}
return false ;
}
static bool F_155 ( const char * V_32 )
{
T_2 V_421 = strlen ( V_32 ) ;
T_13 * V_422 ;
struct V_423 * V_424 ;
int V_100 = - 1 ;
V_422 = F_156 ( F_157 () ) ;
if ( ! V_422 )
return false ;
while ( V_100 && ( V_424 = F_158 ( V_422 ) ) != NULL ) {
char V_425 [ V_426 ] ;
char * V_263 ;
T_2 V_6 ;
if ( ( V_424 -> V_427 != V_428 ) ||
! strcmp ( L_70 , V_424 -> V_429 ) ||
! strcmp ( L_71 , V_424 -> V_429 ) )
continue;
F_41 ( V_425 , sizeof( V_425 ) , L_72 ,
F_157 () , V_424 -> V_429 ) ;
if ( F_159 ( V_425 , & V_263 , & V_6 ) )
continue;
V_100 = strncmp ( V_32 , V_263 , V_421 ) ;
free ( V_263 ) ;
}
F_160 ( V_422 ) ;
return V_100 ? false : true ;
}
int F_161 ( struct V_1 * T_1 , struct V_161 * V_161 ,
int V_60 , char * V_412 , T_2 V_6 )
{
char V_430 [ V_431 ] ;
int V_432 = 0 ;
switch ( V_60 ) {
case V_433 :
case V_419 :
if ( V_60 == V_433 )
V_432 = F_41 ( V_412 , V_6 ,
L_73 ,
F_53 ( T_1 ) ) ;
return F_41 ( V_412 + V_432 , V_6 - V_432 ,
L_74
L_75
L_76
L_77
L_78
L_79
L_80
L_81
L_82
L_83
L_84
L_85
L_86 ,
V_161 -> V_227 ? L_87 : L_1 ,
F_25 () ) ;
case V_415 :
return F_41 ( V_412 , V_6 , L_88 ,
F_53 ( T_1 ) ) ;
case V_342 :
return F_41 ( V_412 , V_6 , L_9 ,
L_89
L_90
L_91
L_92 ) ;
case V_61 :
if ( ( T_1 -> V_22 . V_8 & V_381 ) != 0 &&
F_162 ( L_93 , V_434 ) == 0 )
return F_41 ( V_412 , V_6 ,
L_94
L_95
L_96 , V_435 ) ;
break;
case V_417 :
if ( V_161 -> V_436 )
return F_41 ( V_412 , V_6 , L_9 ,
L_97 ) ;
break;
case V_437 :
if ( T_1 -> V_22 . V_49 != 0 )
return F_41 ( V_412 , V_6 , L_9 ,
L_98 ) ;
if ( T_1 -> V_22 . V_57 )
return F_41 ( V_412 , V_6 , L_9 ,
L_99 ) ;
#if F_163 ( V_438 ) || F_163 ( V_439 )
if ( T_1 -> V_22 . type == V_51 )
return F_41 ( V_412 , V_6 , L_9 ,
L_100
L_101 ) ;
#endif
break;
case V_440 :
if ( F_155 ( L_102 ) )
return F_41 ( V_412 , V_6 ,
L_103
L_104 ) ;
break;
case V_7 :
if ( T_1 -> V_22 . V_154 && V_165 . V_154 )
return F_41 ( V_412 , V_6 , L_105 ) ;
if ( V_165 . V_219 )
return F_41 ( V_412 , V_6 , L_106 ) ;
if ( V_165 . V_325 )
return F_41 ( V_412 , V_6 , L_107 , V_219 ) ;
break;
default:
break;
}
return F_41 ( V_412 , V_6 ,
L_108
L_109
L_110 ,
V_60 , F_164 ( V_60 , V_430 , sizeof( V_430 ) ) ,
F_53 ( T_1 ) ) ;
}
char * F_165 ( struct V_1 * T_1 )
{
if ( T_1 && T_1 -> V_38 && T_1 -> V_38 -> V_441 )
return T_1 -> V_38 -> V_441 -> V_442 ;
return NULL ;
}
char * F_166 ( struct V_1 * T_1 )
{
if ( T_1 && T_1 -> V_38 && T_1 -> V_38 -> V_441 )
return T_1 -> V_38 -> V_441 -> V_443 ;
return NULL ;
}
