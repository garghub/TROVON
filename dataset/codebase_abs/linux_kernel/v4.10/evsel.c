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
if ( V_128 -> V_132 . V_141 && strcmp ( V_128 -> V_132 . V_141 , L_36 ) ) {
F_14 ( T_1 , V_113 ) ;
F_60 ( V_128 -> V_132 . V_141 ,
& V_22 -> V_114 ) ;
} else
F_13 ( T_1 , V_113 ) ;
break;
case V_142 :
V_125 = V_128 -> V_132 . V_143 ;
break;
case V_144 :
V_109 = V_128 -> V_132 . V_109 ;
break;
case V_145 :
V_22 -> V_146 = V_128 -> V_132 . V_146 ? 1 : 0 ;
break;
case V_147 :
V_22 -> V_148 = V_128 -> V_132 . V_149 ? 1 : 0 ;
break;
default:
break;
}
}
if ( ( V_130 != NULL ) || ( V_125 > 0 ) || V_109 ) {
if ( V_109 ) {
V_105 . V_109 = V_109 ;
if ( V_130 == NULL )
V_130 = L_37 ;
}
if ( V_130 != NULL ) {
if ( ! strcmp ( V_130 , L_36 ) ) {
V_105 . V_150 = false ;
V_105 . V_110 = V_151 ;
} else {
V_105 . V_150 = true ;
if ( F_61 ( V_130 , & V_105 ) ) {
F_62 ( L_38
L_39 ,
T_1 -> V_32 ) ;
return;
}
}
}
if ( V_125 > 0 ) {
V_125 = F_63 ( V_125 , sizeof( T_3 ) ) ;
V_105 . V_125 = V_125 ;
}
if ( V_104 . V_150 )
F_57 ( T_1 , & V_104 ) ;
if ( V_105 . V_150 )
F_54 ( T_1 , V_103 , & V_105 ) ;
}
}
void F_64 ( struct V_1 * T_1 , struct V_102 * V_103 ,
struct V_104 * V_152 )
{
struct V_1 * V_35 = T_1 -> V_35 ;
struct V_33 * V_22 = & T_1 -> V_22 ;
int V_153 = T_1 -> V_34 ;
bool V_154 = V_103 -> V_155 . V_156 && ! V_103 -> V_155 . V_157 ;
V_22 -> V_158 = V_159 . V_158 ? 0 : 1 ;
V_22 -> V_146 = ! V_103 -> V_160 ;
V_22 -> V_148 = V_103 -> V_149 ? 1 : 0 ;
F_14 ( T_1 , V_161 ) ;
F_14 ( T_1 , V_162 ) ;
if ( T_1 -> V_163 ) {
F_14 ( T_1 , V_164 ) ;
F_12 ( T_1 , false ) ;
if ( V_35 -> V_165 > 1 ) {
V_22 -> V_30 |= V_166 ;
V_22 -> V_146 = 0 ;
}
}
if ( ! V_22 -> V_45 || ( V_103 -> V_167 != V_168 ||
V_103 -> V_169 != V_170 ) ) {
if ( V_103 -> V_134 ) {
F_14 ( T_1 , V_171 ) ;
V_22 -> V_134 = 1 ;
V_22 -> V_136 = V_103 -> V_134 ;
} else {
V_22 -> V_45 = V_103 -> V_172 ;
}
}
if ( ( V_35 != T_1 ) && V_35 -> V_163 ) {
V_22 -> V_136 = 0 ;
V_22 -> V_45 = 0 ;
}
if ( V_103 -> V_173 )
V_22 -> V_136 = 0 ;
if ( V_103 -> V_174 )
V_22 -> V_174 = 1 ;
if ( V_103 -> V_175 ) {
F_14 ( T_1 , V_176 ) ;
V_22 -> V_177 = V_153 ;
}
if ( F_15 ( T_1 ) )
T_1 -> V_22 . V_126 = 1 ;
if ( V_152 && V_152 -> V_150 && ! T_1 -> V_178 )
F_54 ( T_1 , V_103 , V_152 ) ;
if ( V_103 -> V_179 ) {
V_22 -> V_180 = V_103 -> V_179 ;
F_14 ( T_1 , V_181 ) ;
}
if ( F_65 ( & V_103 -> V_155 ) || V_103 -> V_182 )
F_14 ( T_1 , V_183 ) ;
if ( V_103 -> V_133 )
F_14 ( T_1 , V_171 ) ;
if ( V_103 -> V_184 &&
( ! V_159 . V_158 &&
( ! V_103 -> V_160 || F_65 ( & V_103 -> V_155 ) || V_154 ||
V_103 -> V_185 ) ) )
F_14 ( T_1 , TIME ) ;
if ( V_103 -> V_186 && ! T_1 -> V_178 ) {
F_14 ( T_1 , TIME ) ;
F_14 ( T_1 , V_187 ) ;
F_14 ( T_1 , V_183 ) ;
}
if ( V_103 -> V_175 )
F_14 ( T_1 , V_188 ) ;
if ( V_103 -> V_189 ) {
V_22 -> V_190 = 0 ;
V_22 -> V_191 = 1 ;
}
if ( V_103 -> V_112 && ! T_1 -> V_178 ) {
F_14 ( T_1 , V_113 ) ;
V_22 -> V_114 = V_103 -> V_112 ;
}
if ( V_103 -> V_192 )
F_14 ( T_1 , V_193 ) ;
V_22 -> V_194 = V_153 ;
V_22 -> V_195 = V_153 ;
V_22 -> V_196 = V_153 && ! V_159 . V_196 ;
V_22 -> V_197 = V_153 ;
if ( V_103 -> V_198 )
V_22 -> V_199 = V_153 ;
if ( V_103 -> V_200 )
F_14 ( T_1 , V_201 ) ;
if ( V_103 -> V_202 ) {
T_1 -> V_22 . V_30 |=
V_203 |
V_204 ;
}
if ( F_66 ( T_1 ) )
V_22 -> V_205 = 1 ;
if ( F_67 ( & V_103 -> V_155 ) && F_66 ( T_1 ) &&
! V_103 -> V_206 )
V_22 -> V_207 = 1 ;
if ( T_1 -> V_208 ) {
V_22 -> V_205 = 0 ;
V_22 -> V_207 = 0 ;
}
V_209 = V_103 -> V_209 ;
if ( V_103 -> V_210 ) {
V_22 -> V_210 = 1 ;
V_22 -> V_209 = V_103 -> V_209 ;
}
if ( T_1 -> V_211 )
F_24 ( V_22 ) ;
if ( V_103 -> V_212 ) {
V_22 -> V_66 = 1 ;
V_22 -> V_67 = 0 ;
}
if ( V_103 -> V_213 ) {
V_22 -> V_66 = 0 ;
V_22 -> V_67 = 1 ;
}
F_58 ( T_1 , V_103 ) ;
T_1 -> V_214 = V_103 -> V_214 ;
}
static int F_68 ( struct V_1 * T_1 , int V_215 , int V_216 )
{
if ( T_1 -> V_217 )
V_216 = 1 ;
T_1 -> V_218 = F_69 ( V_215 , V_216 , sizeof( int ) ) ;
if ( T_1 -> V_218 ) {
int V_219 , V_220 ;
for ( V_219 = 0 ; V_219 < V_215 ; V_219 ++ ) {
for ( V_220 = 0 ; V_220 < V_216 ; V_220 ++ ) {
F_70 ( T_1 , V_219 , V_220 ) = - 1 ;
}
}
}
return T_1 -> V_218 != NULL ? 0 : - V_54 ;
}
static int F_71 ( struct V_1 * T_1 , int V_215 , int V_216 ,
int V_221 , void * V_222 )
{
int V_219 , V_220 ;
if ( T_1 -> V_217 )
V_216 = 1 ;
for ( V_219 = 0 ; V_219 < V_215 ; V_219 ++ ) {
for ( V_220 = 0 ; V_220 < V_216 ; V_220 ++ ) {
int V_218 = F_70 ( T_1 , V_219 , V_220 ) ,
V_53 = F_72 ( V_218 , V_221 , V_222 ) ;
if ( V_53 )
return V_53 ;
}
}
return 0 ;
}
int F_73 ( struct V_1 * T_1 , int V_215 , int V_216 ,
const char * V_223 )
{
return F_71 ( T_1 , V_215 , V_216 ,
V_224 ,
( void * ) V_223 ) ;
}
int F_74 ( struct V_1 * T_1 , const char * V_223 )
{
char * V_225 = F_50 ( V_223 ) ;
if ( V_225 != NULL ) {
free ( T_1 -> V_223 ) ;
T_1 -> V_223 = V_225 ;
return 0 ;
}
return - 1 ;
}
static int F_75 ( struct V_1 * T_1 ,
const char * V_226 , const char * V_223 )
{
char * V_225 ;
if ( T_1 -> V_223 == NULL )
return F_74 ( T_1 , V_223 ) ;
if ( F_26 ( & V_225 , V_226 , T_1 -> V_223 , V_223 ) > 0 ) {
free ( T_1 -> V_223 ) ;
T_1 -> V_223 = V_225 ;
return 0 ;
}
return - 1 ;
}
int F_76 ( struct V_1 * T_1 , const char * V_223 )
{
return F_75 ( T_1 , L_40 , V_223 ) ;
}
int F_77 ( struct V_1 * T_1 , const char * V_223 )
{
return F_75 ( T_1 , L_41 , V_223 ) ;
}
int F_78 ( struct V_1 * T_1 )
{
int V_216 = F_79 ( T_1 -> V_227 ) ;
int V_215 = F_80 ( T_1 -> V_228 ) ;
return F_71 ( T_1 , V_215 , V_216 ,
V_229 ,
0 ) ;
}
int F_81 ( struct V_1 * T_1 )
{
int V_216 = F_79 ( T_1 -> V_227 ) ;
int V_215 = F_80 ( T_1 -> V_228 ) ;
return F_71 ( T_1 , V_215 , V_216 ,
V_230 ,
0 ) ;
}
int F_82 ( struct V_1 * T_1 , int V_215 , int V_216 )
{
if ( V_215 == 0 || V_216 == 0 )
return 0 ;
if ( T_1 -> V_217 )
V_216 = 1 ;
T_1 -> V_231 = F_69 ( V_215 , V_216 , sizeof( struct V_232 ) ) ;
if ( T_1 -> V_231 == NULL )
return - V_54 ;
T_1 -> V_59 = F_20 ( V_215 * V_216 * sizeof( T_3 ) ) ;
if ( T_1 -> V_59 == NULL ) {
F_83 ( T_1 -> V_231 ) ;
T_1 -> V_231 = NULL ;
return - V_54 ;
}
return 0 ;
}
static void F_84 ( struct V_1 * T_1 )
{
F_83 ( T_1 -> V_218 ) ;
T_1 -> V_218 = NULL ;
}
static void F_85 ( struct V_1 * T_1 )
{
F_83 ( T_1 -> V_231 ) ;
T_1 -> V_231 = NULL ;
F_32 ( & T_1 -> V_59 ) ;
}
static void F_86 ( struct V_1 * T_1 )
{
struct V_127 * V_128 , * V_233 ;
F_87 (term, h, &evsel->config_terms, list) {
F_88 ( & V_128 -> V_234 ) ;
free ( V_128 ) ;
}
}
void F_89 ( struct V_1 * T_1 , int V_215 , int V_216 )
{
int V_219 , V_220 ;
if ( T_1 -> V_217 )
V_216 = 1 ;
for ( V_219 = 0 ; V_219 < V_215 ; V_219 ++ )
for ( V_220 = 0 ; V_220 < V_216 ; ++ V_220 ) {
F_90 ( F_70 ( T_1 , V_219 , V_220 ) ) ;
F_70 ( T_1 , V_219 , V_220 ) = - 1 ;
}
}
void F_91 ( struct V_1 * T_1 )
{
assert ( F_92 ( & T_1 -> V_40 ) ) ;
assert ( T_1 -> V_38 == NULL ) ;
F_84 ( T_1 ) ;
F_85 ( T_1 ) ;
F_86 ( T_1 ) ;
F_93 ( T_1 -> V_235 ) ;
F_94 ( T_1 -> V_228 ) ;
F_94 ( T_1 -> V_236 ) ;
F_95 ( T_1 -> V_227 ) ;
F_32 ( & T_1 -> V_99 ) ;
F_32 ( & T_1 -> V_32 ) ;
V_5 . F_5 ( T_1 ) ;
}
void F_27 ( struct V_1 * T_1 )
{
F_91 ( T_1 ) ;
free ( T_1 ) ;
}
void F_96 ( struct V_1 * T_1 , int V_219 , int V_220 ,
struct V_237 * V_238 )
{
struct V_237 V_239 ;
if ( ! T_1 -> V_240 )
return;
if ( V_219 == - 1 ) {
V_239 = T_1 -> V_240 -> V_241 ;
T_1 -> V_240 -> V_241 = * V_238 ;
} else {
V_239 = * F_97 ( T_1 -> V_240 , V_219 , V_220 ) ;
* F_97 ( T_1 -> V_240 , V_219 , V_220 ) = * V_238 ;
}
V_238 -> V_132 = V_238 -> V_132 - V_239 . V_132 ;
V_238 -> V_242 = V_238 -> V_242 - V_239 . V_242 ;
V_238 -> V_243 = V_238 -> V_243 - V_239 . V_243 ;
}
void F_98 ( struct V_237 * V_238 ,
bool V_37 , T_8 * V_244 )
{
T_8 V_245 = 0 ;
if ( V_37 ) {
if ( V_238 -> V_243 == 0 ) {
V_245 = - 1 ;
V_238 -> V_132 = 0 ;
} else if ( V_238 -> V_243 < V_238 -> V_242 ) {
V_245 = 1 ;
V_238 -> V_132 = ( T_3 ) ( ( double ) V_238 -> V_132 * V_238 -> V_242 / V_238 -> V_243 + 0.5 ) ;
}
} else
V_238 -> V_242 = V_238 -> V_243 = 0 ;
if ( V_244 )
* V_244 = V_245 ;
}
int F_99 ( struct V_1 * T_1 , int V_219 , int V_220 ,
struct V_237 * V_238 )
{
memset ( V_238 , 0 , sizeof( * V_238 ) ) ;
if ( F_70 ( T_1 , V_219 , V_220 ) < 0 )
return - V_7 ;
if ( F_100 ( F_70 ( T_1 , V_219 , V_220 ) , V_238 , sizeof( * V_238 ) ) < 0 )
return - V_246 ;
return 0 ;
}
int F_101 ( struct V_1 * T_1 ,
int V_219 , int V_220 , bool V_37 )
{
struct V_237 V_238 ;
T_2 V_247 = V_37 ? 3 : 1 ;
if ( F_70 ( T_1 , V_219 , V_220 ) < 0 )
return - V_7 ;
if ( T_1 -> V_248 == NULL && F_102 ( T_1 , V_219 + 1 , V_220 + 1 ) < 0 )
return - V_54 ;
if ( F_100 ( F_70 ( T_1 , V_219 , V_220 ) , & V_238 , V_247 * sizeof( T_3 ) ) < 0 )
return - V_246 ;
F_96 ( T_1 , V_219 , V_220 , & V_238 ) ;
F_98 ( & V_238 , V_37 , NULL ) ;
* F_97 ( T_1 -> V_248 , V_219 , V_220 ) = V_238 ;
return 0 ;
}
static int F_103 ( struct V_1 * T_1 , int V_219 , int V_220 )
{
struct V_1 * V_35 = T_1 -> V_35 ;
int V_218 ;
if ( F_66 ( T_1 ) )
return - 1 ;
F_104 ( ! V_35 -> V_218 ) ;
V_218 = F_70 ( V_35 , V_219 , V_220 ) ;
F_104 ( V_218 == - 1 ) ;
return V_218 ;
}
static void F_105 ( char * V_100 , T_2 V_6 , T_3 V_249 , struct V_250 * V_251 )
{
bool V_252 = true ;
int V_11 = 0 ;
do {
if ( V_249 & V_251 [ V_11 ] . V_25 ) {
V_100 += F_37 ( V_100 , V_6 , L_42 , V_252 ? L_1 : L_43 , V_251 [ V_11 ] . V_32 ) ;
V_252 = false ;
}
} while ( V_251 [ ++ V_11 ] . V_32 != NULL );
}
static void F_106 ( char * V_100 , T_2 V_6 , T_3 V_249 )
{
#define F_107 ( T_9 ) { PERF_SAMPLE_##n, #n }
struct V_250 V_251 [] = {
F_107 ( V_161 ) , F_107 ( V_162 ) , F_107 ( TIME ) , F_107 ( V_176 ) ,
F_107 ( V_164 ) , F_107 ( V_107 ) , F_107 ( V_28 ) , F_107 ( V_183 ) ,
F_107 ( V_171 ) , F_107 ( V_253 ) , F_107 ( V_187 ) ,
F_107 ( V_113 ) , F_107 ( V_120 ) , F_107 ( V_121 ) ,
F_107 ( V_29 ) , F_107 ( V_181 ) , F_107 ( V_188 ) ,
F_107 ( V_193 ) ,
{ . V_32 = NULL , }
} ;
#undef F_107
F_105 ( V_100 , V_6 , V_249 , V_251 ) ;
}
static void F_108 ( char * V_100 , T_2 V_6 , T_3 V_249 )
{
#define F_107 ( T_9 ) { PERF_SAMPLE_BRANCH_##n, #n }
struct V_250 V_251 [] = {
F_107 ( V_254 ) , F_107 ( V_255 ) , F_107 ( V_256 ) , F_107 ( V_257 ) ,
F_107 ( V_258 ) , F_107 ( V_259 ) , F_107 ( V_260 ) ,
F_107 ( V_261 ) , F_107 ( V_262 ) , F_107 ( V_263 ) ,
F_107 ( V_264 ) , F_107 ( V_265 ) , F_107 ( V_266 ) ,
F_107 ( V_267 ) , F_107 ( V_268 ) , F_107 ( V_269 ) ,
{ . V_32 = NULL , }
} ;
#undef F_107
F_105 ( V_100 , V_6 , V_249 , V_251 ) ;
}
static void F_109 ( char * V_100 , T_2 V_6 , T_3 V_249 )
{
#define F_107 ( T_9 ) { PERF_FORMAT_##n, #n }
struct V_250 V_251 [] = {
F_107 ( V_270 ) , F_107 ( V_271 ) ,
F_107 ( V_28 ) , F_107 ( V_272 ) ,
{ . V_32 = NULL , }
} ;
#undef F_107
F_105 ( V_100 , V_6 , V_249 , V_251 ) ;
}
int F_110 ( T_10 * V_273 , struct V_33 * V_22 ,
T_11 V_274 , void * V_275 )
{
char V_100 [ V_276 ] ;
int V_94 = 0 ;
F_111 ( type , V_277 ) ;
F_111 ( V_6 , V_277 ) ;
F_111 ( V_47 , V_278 ) ;
F_112 ( L_44 , V_45 , V_277 ) ;
F_111 ( V_8 , V_279 ) ;
F_111 ( V_30 , V_280 ) ;
F_111 ( V_205 , V_277 ) ;
F_111 ( V_146 , V_277 ) ;
F_111 ( V_281 , V_277 ) ;
F_111 ( V_282 , V_277 ) ;
F_111 ( V_67 , V_277 ) ;
F_111 ( V_66 , V_277 ) ;
F_111 ( V_68 , V_277 ) ;
F_111 ( V_283 , V_277 ) ;
F_111 ( V_195 , V_277 ) ;
F_111 ( V_197 , V_277 ) ;
F_111 ( V_134 , V_277 ) ;
F_111 ( V_174 , V_277 ) ;
F_111 ( V_207 , V_277 ) ;
F_111 ( V_194 , V_277 ) ;
F_111 ( V_190 , V_277 ) ;
F_111 ( V_50 , V_277 ) ;
F_111 ( V_177 , V_277 ) ;
F_111 ( V_158 , V_277 ) ;
F_111 ( V_72 , V_277 ) ;
F_111 ( V_73 , V_277 ) ;
F_111 ( V_284 , V_277 ) ;
F_111 ( V_126 , V_277 ) ;
F_111 ( V_196 , V_277 ) ;
F_111 ( V_285 , V_277 ) ;
F_111 ( V_210 , V_277 ) ;
F_111 ( V_199 , V_277 ) ;
F_111 ( V_148 , V_277 ) ;
F_112 ( L_45 , V_191 , V_277 ) ;
F_111 ( V_84 , V_277 ) ;
F_112 ( L_46 , V_83 , V_278 ) ;
F_112 ( L_47 , V_286 , V_278 ) ;
F_111 ( V_114 , V_287 ) ;
F_111 ( V_122 , V_278 ) ;
F_111 ( V_124 , V_277 ) ;
F_111 ( V_209 , V_288 ) ;
F_111 ( V_180 , V_278 ) ;
F_111 ( V_289 , V_277 ) ;
F_111 ( V_108 , V_277 ) ;
return V_94 ;
}
static bool V_214 ( struct V_1 * T_1 ,
struct V_290 * V_227 ,
int V_220 , int V_53 )
{
if ( ! T_1 -> V_214 )
return false ;
if ( T_1 -> V_217 )
return false ;
if ( V_53 != - V_291 )
return false ;
if ( V_227 -> V_292 == 1 )
return false ;
if ( F_113 ( V_227 , V_220 ) )
return false ;
F_55 ( L_48 ,
F_114 ( V_227 , V_220 ) ) ;
return true ;
}
static int F_115 ( struct V_1 * T_1 , struct V_293 * V_228 ,
struct V_290 * V_227 )
{
int V_219 , V_220 , V_216 ;
unsigned long V_294 = V_295 ;
int V_296 = - 1 , V_53 ;
enum { V_297 , V_298 , V_299 } V_300 = V_297 ;
if ( V_159 . V_148 && T_1 -> V_22 . V_148 )
return - V_7 ;
if ( T_1 -> V_217 )
V_216 = 1 ;
else
V_216 = V_227 -> V_292 ;
if ( T_1 -> V_218 == NULL &&
F_68 ( T_1 , V_228 -> V_292 , V_216 ) < 0 )
return - V_54 ;
if ( T_1 -> V_235 ) {
V_294 |= V_301 ;
V_296 = T_1 -> V_235 -> V_218 ;
}
V_302:
if ( V_159 . V_303 )
T_1 -> V_22 . V_209 = V_304 ;
if ( V_159 . V_209 ) {
T_1 -> V_22 . V_210 = 0 ;
T_1 -> V_22 . V_209 = 0 ;
}
if ( V_159 . V_305 )
V_294 &= ~ ( unsigned long ) V_295 ;
if ( V_159 . V_196 )
T_1 -> V_22 . V_196 = 0 ;
if ( V_159 . V_73 )
T_1 -> V_22 . V_73 = T_1 -> V_22 . V_72 = 0 ;
if ( V_159 . V_306 )
T_1 -> V_22 . V_114 &= ~ ( V_118 |
V_117 ) ;
V_307:
if ( V_159 . V_158 )
T_1 -> V_22 . V_158 = 0 ;
if ( V_308 >= 2 ) {
fprintf ( V_309 , L_49 , V_310 ) ;
fprintf ( V_309 , L_50 ) ;
F_110 ( V_309 , & T_1 -> V_22 , V_311 , NULL ) ;
fprintf ( V_309 , L_49 , V_310 ) ;
}
for ( V_219 = 0 ; V_219 < V_228 -> V_292 ; V_219 ++ ) {
for ( V_220 = 0 ; V_220 < V_216 ; V_220 ++ ) {
int V_218 , V_312 ;
if ( ! T_1 -> V_235 && ! T_1 -> V_217 )
V_296 = F_114 ( V_227 , V_220 ) ;
V_312 = F_103 ( T_1 , V_219 , V_220 ) ;
V_313:
F_116 ( L_51 ,
V_296 , V_228 -> V_314 [ V_219 ] , V_312 , V_294 ) ;
V_218 = F_117 ( & T_1 -> V_22 , V_296 , V_228 -> V_314 [ V_219 ] ,
V_312 , V_294 ) ;
F_70 ( T_1 , V_219 , V_220 ) = V_218 ;
if ( V_218 < 0 ) {
V_53 = - V_246 ;
if ( V_214 ( T_1 , V_227 , V_220 , V_53 ) ) {
V_216 -- ;
V_220 -- ;
V_53 = 0 ;
continue;
}
F_116 ( L_52 ,
V_53 ) ;
goto V_315;
}
F_116 ( L_53 , V_218 ) ;
if ( T_1 -> V_39 >= 0 ) {
int V_316 = V_218 ;
int V_39 = T_1 -> V_39 ;
V_53 = F_72 ( V_316 ,
V_317 ,
V_39 ) ;
if ( V_53 && V_246 != V_318 ) {
F_62 ( L_54 ,
V_39 , strerror ( V_246 ) ) ;
V_53 = - V_7 ;
goto V_319;
}
}
V_300 = V_297 ;
if ( V_159 . V_209 ||
V_159 . V_303 ) {
V_53 = - V_7 ;
goto V_319;
}
}
}
return 0 ;
V_315:
if ( V_53 == - V_320 && V_300 < V_299 ) {
struct V_321 V_322 ;
int V_323 = V_246 ;
if ( F_118 ( V_324 , & V_322 ) == 0 ) {
if ( V_300 == V_297 )
V_322 . V_325 = V_322 . V_326 ;
else {
V_322 . V_325 = V_322 . V_326 + 1000 ;
V_322 . V_326 = V_322 . V_325 ;
}
if ( F_119 ( V_324 , & V_322 ) == 0 ) {
V_300 ++ ;
V_246 = V_323 ;
goto V_313;
}
}
V_246 = V_323 ;
}
if ( V_53 != - V_7 || V_219 > 0 || V_220 > 0 )
goto V_319;
if ( ! V_159 . V_148 && T_1 -> V_22 . V_148 ) {
V_159 . V_148 = true ;
goto V_319;
} else if ( ! V_159 . V_303 && T_1 -> V_22 . V_210 ) {
V_159 . V_303 = true ;
goto V_302;
} else if ( ! V_159 . V_209 && T_1 -> V_22 . V_210 ) {
V_159 . V_209 = true ;
goto V_302;
} else if ( ! V_159 . V_305 && ( V_294 & V_295 ) ) {
V_159 . V_305 = true ;
goto V_302;
} else if ( ! V_159 . V_196 && T_1 -> V_22 . V_196 ) {
V_159 . V_196 = true ;
goto V_302;
} else if ( ! V_159 . V_73 &&
( T_1 -> V_22 . V_73 || T_1 -> V_22 . V_72 ) ) {
V_159 . V_73 = true ;
goto V_302;
} else if ( ! V_159 . V_158 ) {
V_159 . V_158 = true ;
goto V_307;
} else if ( ! V_159 . V_306 &&
( T_1 -> V_22 . V_114 &
( V_117 |
V_118 ) ) ) {
V_159 . V_306 = true ;
goto V_302;
}
V_319:
do {
while ( -- V_220 >= 0 ) {
F_90 ( F_70 ( T_1 , V_219 , V_220 ) ) ;
F_70 ( T_1 , V_219 , V_220 ) = - 1 ;
}
V_220 = V_216 ;
} while ( -- V_219 >= 0 );
return V_53 ;
}
void F_120 ( struct V_1 * T_1 , int V_215 , int V_216 )
{
if ( T_1 -> V_218 == NULL )
return;
F_89 ( T_1 , V_215 , V_216 ) ;
F_84 ( T_1 ) ;
}
int F_121 ( struct V_1 * T_1 , struct V_293 * V_228 ,
struct V_290 * V_227 )
{
if ( V_228 == NULL ) {
V_228 = & V_327 . V_314 ;
}
if ( V_227 == NULL )
V_227 = & V_328 . V_314 ;
return F_115 ( T_1 , V_228 , V_227 ) ;
}
int F_122 ( struct V_1 * T_1 ,
struct V_293 * V_228 )
{
return F_115 ( T_1 , V_228 , & V_328 . V_314 ) ;
}
int F_123 ( struct V_1 * T_1 ,
struct V_290 * V_227 )
{
return F_115 ( T_1 , & V_327 . V_314 , V_227 ) ;
}
static int F_124 ( const struct V_1 * T_1 ,
const union V_329 * V_330 ,
struct V_331 * V_332 )
{
T_3 type = T_1 -> V_22 . V_8 ;
const T_3 * V_333 = V_330 -> V_332 . V_333 ;
bool V_334 = T_1 -> V_335 ;
union V_336 V_337 ;
V_333 += ( ( V_330 -> V_338 . V_6 -
sizeof( V_330 -> V_338 ) ) / sizeof( T_3 ) ) - 1 ;
if ( type & V_13 ) {
V_332 -> V_59 = * V_333 ;
V_333 -- ;
}
if ( type & V_19 ) {
V_337 . V_339 = * V_333 ;
if ( V_334 ) {
V_337 . V_339 = F_125 ( V_337 . V_339 ) ;
V_337 . V_340 [ 0 ] = F_126 ( V_337 . V_340 [ 0 ] ) ;
}
V_332 -> V_219 = V_337 . V_340 [ 0 ] ;
V_333 -- ;
}
if ( type & V_20 ) {
V_332 -> V_341 = * V_333 ;
V_333 -- ;
}
if ( type & V_14 ) {
V_332 -> V_59 = * V_333 ;
V_333 -- ;
}
if ( type & V_17 ) {
V_332 -> time = * V_333 ;
V_333 -- ;
}
if ( type & V_16 ) {
V_337 . V_339 = * V_333 ;
if ( V_334 ) {
V_337 . V_339 = F_125 ( V_337 . V_339 ) ;
V_337 . V_340 [ 0 ] = F_126 ( V_337 . V_340 [ 0 ] ) ;
V_337 . V_340 [ 1 ] = F_126 ( V_337 . V_340 [ 1 ] ) ;
}
V_332 -> V_296 = V_337 . V_340 [ 0 ] ;
V_332 -> V_342 = V_337 . V_340 [ 1 ] ;
V_333 -- ;
}
return 0 ;
}
static inline bool F_127 ( const void * V_343 , T_12 V_344 , const void * V_345 ,
T_3 V_6 )
{
return V_6 > V_344 || V_345 + V_6 > V_343 ;
}
int F_128 ( struct V_1 * T_1 , union V_329 * V_330 ,
struct V_331 * V_346 )
{
T_3 type = T_1 -> V_22 . V_8 ;
bool V_334 = T_1 -> V_335 ;
const T_3 * V_333 ;
T_12 V_344 = V_330 -> V_338 . V_6 ;
const void * V_343 = ( void * ) V_330 + V_344 ;
T_3 V_347 ;
union V_336 V_337 ;
memset ( V_346 , 0 , sizeof( * V_346 ) ) ;
V_346 -> V_219 = V_346 -> V_296 = V_346 -> V_342 = - 1 ;
V_346 -> V_341 = V_346 -> V_59 = V_346 -> time = - 1ULL ;
V_346 -> V_133 = T_1 -> V_22 . V_45 ;
V_346 -> V_348 = V_330 -> V_338 . V_349 & V_350 ;
if ( V_330 -> V_338 . type != V_351 ) {
if ( ! T_1 -> V_22 . V_158 )
return 0 ;
return F_124 ( T_1 , V_330 , V_346 ) ;
}
V_333 = V_330 -> V_332 . V_333 ;
if ( T_1 -> V_26 + sizeof( V_330 -> V_338 ) > V_330 -> V_338 . V_6 )
return - V_352 ;
V_346 -> V_59 = - 1ULL ;
if ( type & V_13 ) {
V_346 -> V_59 = * V_333 ;
V_333 ++ ;
}
if ( type & V_15 ) {
V_346 -> V_353 = * V_333 ;
V_333 ++ ;
}
if ( type & V_16 ) {
V_337 . V_339 = * V_333 ;
if ( V_334 ) {
V_337 . V_339 = F_125 ( V_337 . V_339 ) ;
V_337 . V_340 [ 0 ] = F_126 ( V_337 . V_340 [ 0 ] ) ;
V_337 . V_340 [ 1 ] = F_126 ( V_337 . V_340 [ 1 ] ) ;
}
V_346 -> V_296 = V_337 . V_340 [ 0 ] ;
V_346 -> V_342 = V_337 . V_340 [ 1 ] ;
V_333 ++ ;
}
if ( type & V_17 ) {
V_346 -> time = * V_333 ;
V_333 ++ ;
}
V_346 -> V_78 = 0 ;
if ( type & V_18 ) {
V_346 -> V_78 = * V_333 ;
V_333 ++ ;
}
if ( type & V_14 ) {
V_346 -> V_59 = * V_333 ;
V_333 ++ ;
}
if ( type & V_20 ) {
V_346 -> V_341 = * V_333 ;
V_333 ++ ;
}
if ( type & V_19 ) {
V_337 . V_339 = * V_333 ;
if ( V_334 ) {
V_337 . V_339 = F_125 ( V_337 . V_339 ) ;
V_337 . V_340 [ 0 ] = F_126 ( V_337 . V_340 [ 0 ] ) ;
}
V_346 -> V_219 = V_337 . V_340 [ 0 ] ;
V_333 ++ ;
}
if ( type & V_44 ) {
V_346 -> V_133 = * V_333 ;
V_333 ++ ;
}
if ( type & V_354 ) {
T_3 V_30 = T_1 -> V_22 . V_30 ;
F_129 ( V_333 ) ;
if ( V_30 & V_166 )
V_346 -> V_355 . V_356 . V_292 = * V_333 ;
else
V_346 -> V_355 . V_357 . V_249 = * V_333 ;
V_333 ++ ;
if ( V_30 & V_203 ) {
F_129 ( V_333 ) ;
V_346 -> V_355 . V_358 = * V_333 ;
V_333 ++ ;
}
if ( V_30 & V_204 ) {
F_129 ( V_333 ) ;
V_346 -> V_355 . V_359 = * V_333 ;
V_333 ++ ;
}
if ( V_30 & V_166 ) {
const T_3 V_360 = V_361 /
sizeof( struct V_362 ) ;
if ( V_346 -> V_355 . V_356 . V_292 > V_360 )
return - V_352 ;
V_347 = V_346 -> V_355 . V_356 . V_292 *
sizeof( struct V_362 ) ;
F_130 ( V_333 , V_347 , V_344 ) ;
V_346 -> V_355 . V_356 . V_363 =
(struct V_362 * ) V_333 ;
V_333 = ( void * ) V_333 + V_347 ;
} else {
F_129 ( V_333 ) ;
V_346 -> V_355 . V_357 . V_59 = * V_333 ;
V_333 ++ ;
}
}
if ( type & V_364 ) {
const T_3 V_365 = V_361 / sizeof( T_3 ) ;
F_129 ( V_333 ) ;
V_346 -> V_152 = (struct V_366 * ) V_333 ++ ;
if ( V_346 -> V_152 -> V_292 > V_365 )
return - V_352 ;
V_347 = V_346 -> V_152 -> V_292 * sizeof( T_3 ) ;
F_130 ( V_333 , V_347 , V_344 ) ;
V_333 = ( void * ) V_333 + V_347 ;
}
if ( type & V_43 ) {
F_129 ( V_333 ) ;
V_337 . V_339 = * V_333 ;
if ( F_131 ( V_334 ,
L_55 ) ) {
V_337 . V_339 = F_125 ( V_337 . V_339 ) ;
V_337 . V_340 [ 0 ] = F_126 ( V_337 . V_340 [ 0 ] ) ;
V_337 . V_340 [ 1 ] = F_126 ( V_337 . V_340 [ 1 ] ) ;
}
V_346 -> V_367 = V_337 . V_340 [ 0 ] ;
V_333 = ( void * ) V_333 + sizeof( T_7 ) ;
F_130 ( V_333 , V_346 -> V_367 , V_344 ) ;
V_346 -> V_368 = ( void * ) V_333 ;
V_333 = ( void * ) V_333 + V_346 -> V_367 ;
}
if ( type & V_369 ) {
const T_3 V_370 = V_361 /
sizeof( struct V_371 ) ;
F_129 ( V_333 ) ;
V_346 -> V_112 = (struct V_112 * ) V_333 ++ ;
if ( V_346 -> V_112 -> V_292 > V_370 )
return - V_352 ;
V_347 = V_346 -> V_112 -> V_292 * sizeof( struct V_371 ) ;
F_130 ( V_333 , V_347 , V_344 ) ;
V_333 = ( void * ) V_333 + V_347 ;
}
if ( type & V_372 ) {
F_129 ( V_333 ) ;
V_346 -> V_373 . V_374 = * V_333 ;
V_333 ++ ;
if ( V_346 -> V_373 . V_374 ) {
T_3 V_9 = T_1 -> V_22 . V_122 ;
V_347 = F_132 ( V_9 ) * sizeof( T_3 ) ;
F_130 ( V_333 , V_347 , V_344 ) ;
V_346 -> V_373 . V_9 = V_9 ;
V_346 -> V_373 . V_375 = ( T_3 * ) V_333 ;
V_333 = ( void * ) V_333 + V_347 ;
}
}
if ( type & V_376 ) {
F_129 ( V_333 ) ;
V_347 = * V_333 ++ ;
V_346 -> V_377 . V_345 = ( ( char * ) ( V_333 - 1 )
- ( char * ) V_330 ) ;
if ( ! V_347 ) {
V_346 -> V_377 . V_6 = 0 ;
} else {
F_130 ( V_333 , V_347 , V_344 ) ;
V_346 -> V_377 . V_346 = ( char * ) V_333 ;
V_333 = ( void * ) V_333 + V_347 ;
F_129 ( V_333 ) ;
V_346 -> V_377 . V_6 = * V_333 ++ ;
if ( F_131 ( V_346 -> V_377 . V_6 > V_347 ,
L_56 ) )
return - V_352 ;
}
}
if ( type & V_378 ) {
F_129 ( V_333 ) ;
V_346 -> V_379 = * V_333 ;
V_333 ++ ;
}
V_346 -> V_380 = V_381 ;
if ( type & V_382 ) {
F_129 ( V_333 ) ;
V_346 -> V_380 = * V_333 ;
V_333 ++ ;
}
V_346 -> V_383 = 0 ;
if ( type & V_384 ) {
F_129 ( V_333 ) ;
V_346 -> V_383 = * V_333 ;
V_333 ++ ;
}
V_346 -> V_385 . V_374 = V_386 ;
if ( type & V_387 ) {
F_129 ( V_333 ) ;
V_346 -> V_385 . V_374 = * V_333 ;
V_333 ++ ;
if ( V_346 -> V_385 . V_374 != V_386 ) {
T_3 V_9 = T_1 -> V_22 . V_180 ;
V_347 = F_132 ( V_9 ) * sizeof( T_3 ) ;
F_130 ( V_333 , V_347 , V_344 ) ;
V_346 -> V_385 . V_9 = V_9 ;
V_346 -> V_385 . V_375 = ( T_3 * ) V_333 ;
V_333 = ( void * ) V_333 + V_347 ;
}
}
return 0 ;
}
T_2 F_133 ( const struct V_331 * V_332 , T_3 type ,
T_3 V_30 )
{
T_2 V_347 , V_87 = sizeof( struct V_388 ) ;
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
if ( type & V_354 ) {
V_87 += sizeof( T_3 ) ;
if ( V_30 & V_203 )
V_87 += sizeof( T_3 ) ;
if ( V_30 & V_204 )
V_87 += sizeof( T_3 ) ;
if ( V_30 & V_166 ) {
V_347 = V_332 -> V_355 . V_356 . V_292 *
sizeof( struct V_362 ) ;
V_87 += V_347 ;
} else {
V_87 += sizeof( T_3 ) ;
}
}
if ( type & V_364 ) {
V_347 = ( V_332 -> V_152 -> V_292 + 1 ) * sizeof( T_3 ) ;
V_87 += V_347 ;
}
if ( type & V_43 ) {
V_87 += sizeof( T_7 ) ;
V_87 += V_332 -> V_367 ;
}
if ( type & V_369 ) {
V_347 = V_332 -> V_112 -> V_292 * sizeof( struct V_371 ) ;
V_347 += sizeof( T_3 ) ;
V_87 += V_347 ;
}
if ( type & V_372 ) {
if ( V_332 -> V_373 . V_374 ) {
V_87 += sizeof( T_3 ) ;
V_347 = F_132 ( V_332 -> V_373 . V_9 ) * sizeof( T_3 ) ;
V_87 += V_347 ;
} else {
V_87 += sizeof( T_3 ) ;
}
}
if ( type & V_376 ) {
V_347 = V_332 -> V_377 . V_6 ;
V_87 += sizeof( T_3 ) ;
if ( V_347 ) {
V_87 += V_347 ;
V_87 += sizeof( T_3 ) ;
}
}
if ( type & V_378 )
V_87 += sizeof( T_3 ) ;
if ( type & V_382 )
V_87 += sizeof( T_3 ) ;
if ( type & V_384 )
V_87 += sizeof( T_3 ) ;
if ( type & V_387 ) {
if ( V_332 -> V_385 . V_374 ) {
V_87 += sizeof( T_3 ) ;
V_347 = F_132 ( V_332 -> V_385 . V_9 ) * sizeof( T_3 ) ;
V_87 += V_347 ;
} else {
V_87 += sizeof( T_3 ) ;
}
}
return V_87 ;
}
int F_134 ( union V_329 * V_330 , T_3 type ,
T_3 V_30 ,
const struct V_331 * V_332 ,
bool V_334 )
{
T_3 * V_333 ;
T_2 V_347 ;
union V_336 V_337 ;
V_333 = V_330 -> V_332 . V_333 ;
if ( type & V_13 ) {
* V_333 = V_332 -> V_59 ;
V_333 ++ ;
}
if ( type & V_15 ) {
* V_333 = V_332 -> V_353 ;
V_333 ++ ;
}
if ( type & V_16 ) {
V_337 . V_340 [ 0 ] = V_332 -> V_296 ;
V_337 . V_340 [ 1 ] = V_332 -> V_342 ;
if ( V_334 ) {
V_337 . V_340 [ 0 ] = F_126 ( V_337 . V_340 [ 0 ] ) ;
V_337 . V_340 [ 1 ] = F_126 ( V_337 . V_340 [ 1 ] ) ;
V_337 . V_339 = F_125 ( V_337 . V_339 ) ;
}
* V_333 = V_337 . V_339 ;
V_333 ++ ;
}
if ( type & V_17 ) {
* V_333 = V_332 -> time ;
V_333 ++ ;
}
if ( type & V_18 ) {
* V_333 = V_332 -> V_78 ;
V_333 ++ ;
}
if ( type & V_14 ) {
* V_333 = V_332 -> V_59 ;
V_333 ++ ;
}
if ( type & V_20 ) {
* V_333 = V_332 -> V_341 ;
V_333 ++ ;
}
if ( type & V_19 ) {
V_337 . V_340 [ 0 ] = V_332 -> V_219 ;
if ( V_334 ) {
V_337 . V_340 [ 0 ] = F_126 ( V_337 . V_340 [ 0 ] ) ;
V_337 . V_339 = F_125 ( V_337 . V_339 ) ;
}
* V_333 = V_337 . V_339 ;
V_333 ++ ;
}
if ( type & V_44 ) {
* V_333 = V_332 -> V_133 ;
V_333 ++ ;
}
if ( type & V_354 ) {
if ( V_30 & V_166 )
* V_333 = V_332 -> V_355 . V_356 . V_292 ;
else
* V_333 = V_332 -> V_355 . V_357 . V_249 ;
V_333 ++ ;
if ( V_30 & V_203 ) {
* V_333 = V_332 -> V_355 . V_358 ;
V_333 ++ ;
}
if ( V_30 & V_204 ) {
* V_333 = V_332 -> V_355 . V_359 ;
V_333 ++ ;
}
if ( V_30 & V_166 ) {
V_347 = V_332 -> V_355 . V_356 . V_292 *
sizeof( struct V_362 ) ;
memcpy ( V_333 , V_332 -> V_355 . V_356 . V_363 , V_347 ) ;
V_333 = ( void * ) V_333 + V_347 ;
} else {
* V_333 = V_332 -> V_355 . V_357 . V_59 ;
V_333 ++ ;
}
}
if ( type & V_364 ) {
V_347 = ( V_332 -> V_152 -> V_292 + 1 ) * sizeof( T_3 ) ;
memcpy ( V_333 , V_332 -> V_152 , V_347 ) ;
V_333 = ( void * ) V_333 + V_347 ;
}
if ( type & V_43 ) {
V_337 . V_340 [ 0 ] = V_332 -> V_367 ;
if ( F_131 ( V_334 ,
L_55 ) ) {
V_337 . V_340 [ 0 ] = F_126 ( V_337 . V_340 [ 0 ] ) ;
V_337 . V_340 [ 1 ] = F_126 ( V_337 . V_340 [ 1 ] ) ;
V_337 . V_339 = F_125 ( V_337 . V_339 ) ;
}
* V_333 = V_337 . V_339 ;
V_333 = ( void * ) V_333 + sizeof( T_7 ) ;
memcpy ( V_333 , V_332 -> V_368 , V_332 -> V_367 ) ;
V_333 = ( void * ) V_333 + V_332 -> V_367 ;
}
if ( type & V_369 ) {
V_347 = V_332 -> V_112 -> V_292 * sizeof( struct V_371 ) ;
V_347 += sizeof( T_3 ) ;
memcpy ( V_333 , V_332 -> V_112 , V_347 ) ;
V_333 = ( void * ) V_333 + V_347 ;
}
if ( type & V_372 ) {
if ( V_332 -> V_373 . V_374 ) {
* V_333 ++ = V_332 -> V_373 . V_374 ;
V_347 = F_132 ( V_332 -> V_373 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_333 , V_332 -> V_373 . V_375 , V_347 ) ;
V_333 = ( void * ) V_333 + V_347 ;
} else {
* V_333 ++ = 0 ;
}
}
if ( type & V_376 ) {
V_347 = V_332 -> V_377 . V_6 ;
* V_333 ++ = V_347 ;
if ( V_347 ) {
memcpy ( V_333 , V_332 -> V_377 . V_346 , V_347 ) ;
V_333 = ( void * ) V_333 + V_347 ;
* V_333 ++ = V_347 ;
}
}
if ( type & V_378 ) {
* V_333 = V_332 -> V_379 ;
V_333 ++ ;
}
if ( type & V_382 ) {
* V_333 = V_332 -> V_380 ;
V_333 ++ ;
}
if ( type & V_384 ) {
* V_333 = V_332 -> V_383 ;
V_333 ++ ;
}
if ( type & V_387 ) {
if ( V_332 -> V_385 . V_374 ) {
* V_333 ++ = V_332 -> V_385 . V_374 ;
V_347 = F_132 ( V_332 -> V_385 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_333 , V_332 -> V_385 . V_375 , V_347 ) ;
V_333 = ( void * ) V_333 + V_347 ;
} else {
* V_333 ++ = 0 ;
}
}
return 0 ;
}
struct V_389 * F_135 ( struct V_1 * T_1 , const char * V_32 )
{
return F_136 ( T_1 -> V_58 , V_32 ) ;
}
void * F_137 ( struct V_1 * T_1 , struct V_331 * V_332 ,
const char * V_32 )
{
struct V_389 * V_390 = F_135 ( T_1 , V_32 ) ;
int V_345 ;
if ( ! V_390 )
return NULL ;
V_345 = V_390 -> V_345 ;
if ( V_390 -> V_294 & V_391 ) {
V_345 = * ( int * ) ( V_332 -> V_368 + V_390 -> V_345 ) ;
V_345 &= 0xffff ;
}
return V_332 -> V_368 + V_345 ;
}
T_3 F_138 ( struct V_389 * V_390 , struct V_331 * V_332 ,
bool V_335 )
{
T_3 V_249 ;
void * V_392 = V_332 -> V_368 + V_390 -> V_345 ;
switch ( V_390 -> V_6 ) {
case 1 :
return * ( T_6 * ) V_392 ;
case 2 :
V_249 = * ( T_12 * ) V_392 ;
break;
case 4 :
V_249 = * ( T_7 * ) V_392 ;
break;
case 8 :
memcpy ( & V_249 , V_392 , sizeof( T_3 ) ) ;
break;
default:
return 0 ;
}
if ( ! V_335 )
return V_249 ;
switch ( V_390 -> V_6 ) {
case 2 :
return F_139 ( V_249 ) ;
case 4 :
return F_126 ( V_249 ) ;
case 8 :
return F_125 ( V_249 ) ;
default:
return 0 ;
}
return 0 ;
}
T_3 F_140 ( struct V_1 * T_1 , struct V_331 * V_332 ,
const char * V_32 )
{
struct V_389 * V_390 = F_135 ( T_1 , V_32 ) ;
if ( ! V_390 )
return 0 ;
return V_390 ? F_138 ( V_390 , V_332 , T_1 -> V_335 ) : 0 ;
}
bool F_141 ( struct V_1 * T_1 , int V_53 ,
char * V_393 , T_2 V_394 )
{
int V_395 ;
if ( ( V_53 == V_396 || V_53 == V_397 || V_53 == V_398 ) &&
T_1 -> V_22 . type == V_46 &&
T_1 -> V_22 . V_47 == V_48 ) {
F_37 ( V_393 , V_394 , L_8 ,
L_57 ) ;
T_1 -> V_22 . type = V_97 ;
T_1 -> V_22 . V_47 = V_399 ;
F_32 ( & T_1 -> V_32 ) ;
return true ;
} else if ( V_53 == V_400 && ! T_1 -> V_22 . V_66 &&
( V_395 = F_142 () ) > 1 ) {
const char * V_32 = F_49 ( T_1 ) ;
char * V_401 ;
if ( F_26 ( & V_401 , L_58 , V_32 , strchr ( V_32 , ':' ) ? L_1 : L_11 ) < 0 )
return false ;
if ( T_1 -> V_32 )
free ( T_1 -> V_32 ) ;
T_1 -> V_32 = V_401 ;
F_37 ( V_393 , V_394 ,
L_59 , V_395 ) ;
T_1 -> V_22 . V_66 = 1 ;
return true ;
}
return false ;
}
int F_143 ( struct V_1 * T_1 , struct V_155 * V_155 ,
int V_53 , char * V_393 , T_2 V_6 )
{
char V_402 [ V_403 ] ;
switch ( V_53 ) {
case V_404 :
case V_400 :
return F_37 ( V_393 , V_6 ,
L_60
L_61
L_62
L_63
L_64
L_65
L_66
L_67
L_68 ,
V_155 -> V_217 ? L_69 : L_1 ,
F_142 () ) ;
case V_396 :
return F_37 ( V_393 , V_6 , L_70 ,
F_49 ( T_1 ) ) ;
case V_320 :
return F_37 ( V_393 , V_6 , L_8 ,
L_71
L_72
L_73
L_74 ) ;
case V_54 :
if ( ( T_1 -> V_22 . V_8 & V_364 ) != 0 &&
F_144 ( L_75 , V_405 ) == 0 )
return F_37 ( V_393 , V_6 ,
L_76
L_77
L_78 , V_406 ) ;
break;
case V_398 :
if ( V_155 -> V_407 )
return F_37 ( V_393 , V_6 , L_8 ,
L_79 ) ;
break;
case V_408 :
if ( T_1 -> V_22 . V_45 != 0 )
return F_37 ( V_393 , V_6 , L_8 ,
L_80 ) ;
if ( T_1 -> V_22 . V_50 )
return F_37 ( V_393 , V_6 , L_8 ,
L_81 ) ;
#if F_145 ( V_409 ) || F_145 ( V_410 )
if ( T_1 -> V_22 . type == V_46 )
return F_37 ( V_393 , V_6 , L_8 ,
L_82
L_83 ) ;
#endif
break;
case V_411 :
if ( F_146 ( L_84 ) )
return F_37 ( V_393 , V_6 ,
L_85
L_86 ) ;
break;
case V_7 :
if ( T_1 -> V_22 . V_148 && V_159 . V_148 )
return F_37 ( V_393 , V_6 , L_87 ) ;
if ( V_159 . V_209 )
return F_37 ( V_393 , V_6 , L_88 ) ;
if ( V_159 . V_303 )
return F_37 ( V_393 , V_6 , L_89 , V_209 ) ;
break;
default:
break;
}
return F_37 ( V_393 , V_6 ,
L_90
L_91
L_92 ,
V_53 , F_147 ( V_53 , V_402 , sizeof( V_402 ) ) ,
F_49 ( T_1 ) ) ;
}
char * F_148 ( struct V_1 * T_1 )
{
if ( T_1 && T_1 -> V_38 && T_1 -> V_38 -> V_412 )
return T_1 -> V_38 -> V_412 -> V_413 ;
return NULL ;
}
