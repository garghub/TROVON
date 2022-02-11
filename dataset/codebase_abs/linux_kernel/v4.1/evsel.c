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
F_16 ( & T_1 -> V_37 ) ;
V_5 . F_4 ( T_1 ) ;
T_1 -> V_26 = F_6 ( V_22 -> V_8 ) ;
F_9 ( T_1 ) ;
}
struct V_1 * F_17 ( struct V_32 * V_22 , int V_12 )
{
struct V_1 * T_1 = F_18 ( V_5 . V_6 ) ;
if ( T_1 != NULL )
F_15 ( T_1 , V_22 , V_12 ) ;
return T_1 ;
}
struct V_1 * F_19 ( const char * V_38 , const char * V_39 , int V_12 )
{
struct V_1 * T_1 = F_18 ( V_5 . V_6 ) ;
if ( T_1 != NULL ) {
struct V_32 V_22 = {
. type = V_40 ,
. V_8 = ( V_41 | V_17 |
V_19 | V_42 ) ,
} ;
if ( F_20 ( & T_1 -> V_39 , L_2 , V_38 , V_39 ) < 0 )
goto V_43;
T_1 -> V_44 = F_21 ( V_38 , V_39 ) ;
if ( T_1 -> V_44 == NULL )
goto V_43;
F_22 ( & V_22 ) ;
V_22 . V_45 = T_1 -> V_44 -> V_46 ;
V_22 . V_47 = 1 ;
F_15 ( T_1 , & V_22 , V_12 ) ;
}
return T_1 ;
V_43:
F_23 ( & T_1 -> V_39 ) ;
free ( T_1 ) ;
return NULL ;
}
static const char * F_24 ( T_3 V_45 )
{
if ( V_45 < V_48 && V_49 [ V_45 ] )
return V_49 [ V_45 ] ;
return L_3 ;
}
static int F_25 ( struct V_1 * T_1 , char * V_50 , T_2 V_6 )
{
int V_51 = 0 , V_52 = 0 ;
struct V_32 * V_22 = & T_1 -> V_22 ;
bool V_53 = false ;
#define F_26 ( T_4 , T_5 ) do { \
if (!attr->exclude_##context) { \
if (!colon) colon = ++r; \
r += scnprintf(bf + r, size - r, "%c", mod); \
} } while(0)
if ( V_22 -> V_54 || V_22 -> V_55 || V_22 -> V_56 ) {
F_26 ( V_57 , 'k' ) ;
F_26 ( V_58 , 'u' ) ;
F_26 ( V_59 , 'h' ) ;
V_53 = true ;
}
if ( V_22 -> V_60 ) {
if ( ! V_51 )
V_51 = ++ V_52 ;
V_52 += F_27 ( V_50 + V_52 , V_6 - V_52 , L_4 , V_22 -> V_60 , L_5 ) ;
V_53 = true ;
}
if ( V_22 -> V_61 || V_22 -> V_62 == V_53 ) {
F_26 ( V_63 , 'H' ) ;
F_26 ( V_64 , 'G' ) ;
}
#undef F_26
if ( V_51 )
V_50 [ V_51 - 1 ] = ':' ;
return V_52 ;
}
static int F_28 ( struct V_1 * T_1 , char * V_50 , T_2 V_6 )
{
int V_52 = F_27 ( V_50 , V_6 , L_6 , F_24 ( T_1 -> V_22 . V_45 ) ) ;
return V_52 + F_25 ( T_1 , V_50 + V_52 , V_6 - V_52 ) ;
}
static const char * F_29 ( T_3 V_45 )
{
if ( V_45 < V_65 && V_66 [ V_45 ] )
return V_66 [ V_45 ] ;
return L_7 ;
}
static int F_30 ( struct V_1 * T_1 , char * V_50 , T_2 V_6 )
{
int V_52 = F_27 ( V_50 , V_6 , L_6 , F_29 ( T_1 -> V_22 . V_45 ) ) ;
return V_52 + F_25 ( T_1 , V_50 + V_52 , V_6 - V_52 ) ;
}
static int F_31 ( char * V_50 , T_2 V_6 , T_3 V_67 , T_3 type )
{
int V_52 ;
V_52 = F_27 ( V_50 , V_6 , L_8 V_68 L_9 , V_67 ) ;
if ( type & V_69 )
V_52 += F_27 ( V_50 + V_52 , V_6 - V_52 , L_10 ) ;
if ( type & V_70 )
V_52 += F_27 ( V_50 + V_52 , V_6 - V_52 , L_11 ) ;
if ( type & V_71 )
V_52 += F_27 ( V_50 + V_52 , V_6 - V_52 , L_12 ) ;
return V_52 ;
}
static int F_32 ( struct V_1 * T_1 , char * V_50 , T_2 V_6 )
{
struct V_32 * V_22 = & T_1 -> V_22 ;
int V_52 = F_31 ( V_50 , V_6 , V_22 -> V_72 , V_22 -> V_73 ) ;
return V_52 + F_25 ( T_1 , V_50 + V_52 , V_6 - V_52 ) ;
}
bool F_33 ( T_6 type , T_6 V_74 )
{
if ( V_75 [ type ] & F_34 ( V_74 ) )
return true ;
else
return false ;
}
int F_35 ( T_6 type , T_6 V_74 , T_6 V_76 ,
char * V_50 , T_2 V_6 )
{
if ( V_76 ) {
return F_27 ( V_50 , V_6 , L_13 , V_77 [ type ] [ 0 ] ,
V_78 [ V_74 ] [ 0 ] ,
V_79 [ V_76 ] [ 0 ] ) ;
}
return F_27 ( V_50 , V_6 , L_14 , V_77 [ type ] [ 0 ] ,
V_78 [ V_74 ] [ 1 ] ) ;
}
static int F_36 ( T_3 V_45 , char * V_50 , T_2 V_6 )
{
T_6 V_74 , V_76 , type = ( V_45 >> 0 ) & 0xff ;
const char * V_80 = L_15 ;
if ( type > V_81 )
goto V_82;
V_74 = ( V_45 >> 8 ) & 0xff ;
V_80 = L_16 ;
if ( V_74 > V_83 )
goto V_82;
V_76 = ( V_45 >> 16 ) & 0xff ;
V_80 = L_17 ;
if ( V_76 > V_84 )
goto V_82;
V_80 = L_18 ;
if ( ! F_33 ( type , V_74 ) )
goto V_82;
return F_35 ( type , V_74 , V_76 , V_50 , V_6 ) ;
V_82:
return F_27 ( V_50 , V_6 , L_6 , V_80 ) ;
}
static int F_37 ( struct V_1 * T_1 , char * V_50 , T_2 V_6 )
{
int V_85 = F_36 ( T_1 -> V_22 . V_45 , V_50 , V_6 ) ;
return V_85 + F_25 ( T_1 , V_50 + V_85 , V_6 - V_85 ) ;
}
static int F_38 ( struct V_1 * T_1 , char * V_50 , T_2 V_6 )
{
int V_85 = F_27 ( V_50 , V_6 , L_19 V_68 , T_1 -> V_22 . V_45 ) ;
return V_85 + F_25 ( T_1 , V_50 + V_85 , V_6 - V_85 ) ;
}
const char * F_39 ( struct V_1 * T_1 )
{
char V_50 [ 128 ] ;
if ( T_1 -> V_39 )
return T_1 -> V_39 ;
switch ( T_1 -> V_22 . type ) {
case V_86 :
F_38 ( T_1 , V_50 , sizeof( V_50 ) ) ;
break;
case V_87 :
F_28 ( T_1 , V_50 , sizeof( V_50 ) ) ;
break;
case V_88 :
F_37 ( T_1 , V_50 , sizeof( V_50 ) ) ;
break;
case V_89 :
F_30 ( T_1 , V_50 , sizeof( V_50 ) ) ;
break;
case V_40 :
F_27 ( V_50 , sizeof( V_50 ) , L_6 , L_20 ) ;
break;
case V_90 :
F_32 ( T_1 , V_50 , sizeof( V_50 ) ) ;
break;
default:
F_27 ( V_50 , sizeof( V_50 ) , L_21 ,
T_1 -> V_22 . type ) ;
break;
}
T_1 -> V_39 = F_40 ( V_50 ) ;
return T_1 -> V_39 ? : L_22 ;
}
const char * F_41 ( struct V_1 * T_1 )
{
return T_1 -> V_91 ? : L_23 ;
}
int F_42 ( struct V_1 * T_1 , char * V_92 , T_2 V_6 )
{
int V_85 ;
struct V_1 * V_93 ;
const char * V_91 = F_41 ( T_1 ) ;
V_85 = F_27 ( V_92 , V_6 , L_6 , V_91 ) ;
V_85 += F_27 ( V_92 + V_85 , V_6 - V_85 , L_24 ,
F_39 ( T_1 ) ) ;
F_43 (pos, evsel)
V_85 += F_27 ( V_92 + V_85 , V_6 - V_85 , L_25 ,
F_39 ( V_93 ) ) ;
V_85 += F_27 ( V_92 + V_85 , V_6 - V_85 , L_26 ) ;
return V_85 ;
}
static void
F_44 ( struct V_1 * T_1 ,
struct V_94 * V_95 )
{
bool V_96 = F_45 ( T_1 ) ;
struct V_32 * V_22 = & T_1 -> V_22 ;
F_14 ( T_1 , V_97 ) ;
if ( V_98 . V_99 == V_100 ) {
if ( ! V_95 -> V_101 ) {
if ( V_22 -> V_55 ) {
F_46 ( L_27
L_28
L_29 ) ;
} else {
F_14 ( T_1 , V_102 ) ;
V_22 -> V_103 = V_104 |
V_105 ;
}
} else
F_46 ( L_30
L_29 ) ;
}
if ( V_98 . V_99 == V_106 ) {
if ( ! V_96 ) {
F_14 ( T_1 , V_107 ) ;
F_14 ( T_1 , V_108 ) ;
V_22 -> V_109 = V_110 ;
V_22 -> V_111 = V_98 . V_112 ;
V_22 -> V_113 = 1 ;
} else {
F_47 ( L_31
L_32 ) ;
}
}
if ( V_96 ) {
F_47 ( L_33 ) ;
V_22 -> V_113 = 1 ;
}
}
void F_48 ( struct V_1 * T_1 , struct V_94 * V_95 )
{
struct V_1 * V_34 = T_1 -> V_34 ;
struct V_32 * V_22 = & T_1 -> V_22 ;
int V_114 = T_1 -> V_33 ;
bool V_115 = V_95 -> V_116 . V_117 && ! V_95 -> V_116 . V_118 ;
V_22 -> V_119 = V_120 . V_119 ? 0 : 1 ;
V_22 -> V_121 = ! V_95 -> V_122 ;
F_14 ( T_1 , V_123 ) ;
F_14 ( T_1 , V_124 ) ;
if ( T_1 -> V_125 ) {
F_14 ( T_1 , V_126 ) ;
F_12 ( T_1 , false ) ;
if ( V_34 -> V_127 > 1 ) {
V_22 -> V_30 |= V_128 ;
V_22 -> V_121 = 0 ;
}
}
if ( ! V_22 -> V_47 || ( V_95 -> V_129 != V_130 ||
V_95 -> V_131 != V_132 ) ) {
if ( V_95 -> V_133 ) {
F_14 ( T_1 , V_134 ) ;
V_22 -> V_133 = 1 ;
V_22 -> V_135 = V_95 -> V_133 ;
} else {
V_22 -> V_47 = V_95 -> V_136 ;
}
}
if ( ( V_34 != T_1 ) && V_34 -> V_125 ) {
V_22 -> V_135 = 0 ;
V_22 -> V_47 = 0 ;
}
if ( V_95 -> V_137 )
V_22 -> V_135 = 0 ;
if ( V_95 -> V_138 )
V_22 -> V_138 = 1 ;
if ( V_95 -> V_139 ) {
F_14 ( T_1 , V_140 ) ;
V_22 -> V_141 = V_114 ;
}
if ( F_45 ( T_1 ) )
T_1 -> V_22 . V_113 = 1 ;
if ( V_98 . V_142 && ! T_1 -> V_143 )
F_44 ( T_1 , V_95 ) ;
if ( V_95 -> V_144 ) {
V_22 -> V_145 = V_110 ;
F_14 ( T_1 , V_146 ) ;
}
if ( F_49 ( & V_95 -> V_116 ) )
F_14 ( T_1 , V_147 ) ;
if ( V_95 -> V_148 )
F_14 ( T_1 , V_134 ) ;
if ( V_95 -> V_149 &&
( ! V_120 . V_119 &&
( ! V_95 -> V_122 || F_49 ( & V_95 -> V_116 ) || V_115 ) ) )
F_14 ( T_1 , TIME ) ;
if ( V_95 -> V_150 && ! T_1 -> V_143 ) {
F_14 ( T_1 , TIME ) ;
F_14 ( T_1 , V_151 ) ;
F_14 ( T_1 , V_147 ) ;
}
if ( V_95 -> V_139 )
F_14 ( T_1 , V_152 ) ;
if ( V_95 -> V_153 ) {
V_22 -> V_154 = 0 ;
V_22 -> V_155 = 1 ;
}
if ( V_95 -> V_101 && ! T_1 -> V_143 ) {
F_14 ( T_1 , V_102 ) ;
V_22 -> V_103 = V_95 -> V_101 ;
}
if ( V_95 -> V_156 )
F_14 ( T_1 , V_157 ) ;
V_22 -> V_158 = V_114 ;
V_22 -> V_159 = V_114 ;
V_22 -> V_160 = V_114 && ! V_120 . V_160 ;
V_22 -> V_161 = V_114 ;
if ( V_95 -> V_162 )
F_14 ( T_1 , V_163 ) ;
if ( V_95 -> V_164 ) {
T_1 -> V_22 . V_30 |=
V_165 |
V_166 ;
}
if ( F_50 ( T_1 ) )
V_22 -> V_167 = 1 ;
if ( F_51 ( & V_95 -> V_116 ) && F_50 ( T_1 ) &&
! V_95 -> V_168 )
V_22 -> V_169 = 1 ;
if ( T_1 -> V_170 ) {
V_22 -> V_167 = 0 ;
V_22 -> V_169 = 0 ;
}
V_171 = V_95 -> V_171 ;
if ( V_95 -> V_172 ) {
V_22 -> V_172 = 1 ;
V_22 -> V_171 = V_95 -> V_171 ;
}
}
static int F_52 ( struct V_1 * T_1 , int V_173 , int V_174 )
{
int V_175 , V_176 ;
if ( T_1 -> V_177 )
V_174 = 1 ;
T_1 -> V_178 = F_53 ( V_173 , V_174 , sizeof( int ) ) ;
if ( T_1 -> V_178 ) {
for ( V_175 = 0 ; V_175 < V_173 ; V_175 ++ ) {
for ( V_176 = 0 ; V_176 < V_174 ; V_176 ++ ) {
F_54 ( T_1 , V_175 , V_176 ) = - 1 ;
}
}
}
return T_1 -> V_178 != NULL ? 0 : - V_179 ;
}
static int F_55 ( struct V_1 * T_1 , int V_173 , int V_174 ,
int V_180 , void * V_181 )
{
int V_175 , V_176 ;
if ( T_1 -> V_177 )
V_174 = 1 ;
for ( V_175 = 0 ; V_175 < V_173 ; V_175 ++ ) {
for ( V_176 = 0 ; V_176 < V_174 ; V_176 ++ ) {
int V_178 = F_54 ( T_1 , V_175 , V_176 ) ,
V_80 = F_56 ( V_178 , V_180 , V_181 ) ;
if ( V_80 )
return V_80 ;
}
}
return 0 ;
}
int F_57 ( struct V_1 * T_1 , int V_173 , int V_174 ,
const char * V_182 )
{
return F_55 ( T_1 , V_173 , V_174 ,
V_183 ,
( void * ) V_182 ) ;
}
int F_58 ( struct V_1 * T_1 , int V_173 , int V_174 )
{
return F_55 ( T_1 , V_173 , V_174 ,
V_184 ,
0 ) ;
}
int F_59 ( struct V_1 * T_1 , int V_173 , int V_174 )
{
if ( V_173 == 0 || V_174 == 0 )
return 0 ;
if ( T_1 -> V_177 )
V_174 = 1 ;
T_1 -> V_185 = F_53 ( V_173 , V_174 , sizeof( struct V_186 ) ) ;
if ( T_1 -> V_185 == NULL )
return - V_179 ;
T_1 -> V_46 = F_18 ( V_173 * V_174 * sizeof( T_3 ) ) ;
if ( T_1 -> V_46 == NULL ) {
F_60 ( T_1 -> V_185 ) ;
T_1 -> V_185 = NULL ;
return - V_179 ;
}
return 0 ;
}
void F_61 ( struct V_1 * T_1 , int V_173 )
{
memset ( T_1 -> V_187 , 0 , ( sizeof( * T_1 -> V_187 ) +
( V_173 * sizeof( struct V_188 ) ) ) ) ;
}
int F_62 ( struct V_1 * T_1 , int V_173 )
{
T_1 -> V_187 = F_18 ( ( sizeof( * T_1 -> V_187 ) +
( V_173 * sizeof( struct V_188 ) ) ) ) ;
return T_1 -> V_187 != NULL ? 0 : - V_179 ;
}
static void F_63 ( struct V_1 * T_1 )
{
F_60 ( T_1 -> V_178 ) ;
T_1 -> V_178 = NULL ;
}
static void F_64 ( struct V_1 * T_1 )
{
F_60 ( T_1 -> V_185 ) ;
T_1 -> V_185 = NULL ;
F_23 ( & T_1 -> V_46 ) ;
}
void F_65 ( struct V_1 * T_1 , int V_173 , int V_174 )
{
int V_175 , V_176 ;
if ( T_1 -> V_177 )
V_174 = 1 ;
for ( V_175 = 0 ; V_175 < V_173 ; V_175 ++ )
for ( V_176 = 0 ; V_176 < V_174 ; ++ V_176 ) {
F_66 ( F_54 ( T_1 , V_175 , V_176 ) ) ;
F_54 ( T_1 , V_175 , V_176 ) = - 1 ;
}
}
void F_67 ( struct V_1 * T_1 )
{
F_23 ( & T_1 -> V_187 ) ;
}
void F_68 ( struct V_1 * T_1 )
{
assert ( F_69 ( & T_1 -> V_37 ) ) ;
F_63 ( T_1 ) ;
F_64 ( T_1 ) ;
F_70 ( T_1 -> V_189 ) ;
F_23 ( & T_1 -> V_91 ) ;
F_23 ( & T_1 -> V_39 ) ;
V_5 . F_5 ( T_1 ) ;
}
void F_71 ( struct V_1 * T_1 )
{
F_68 ( T_1 ) ;
free ( T_1 ) ;
}
void F_72 ( struct V_1 * T_1 , int V_175 ,
struct V_188 * V_190 )
{
struct V_188 V_191 ;
if ( ! T_1 -> V_192 )
return;
if ( V_175 == - 1 ) {
V_191 = T_1 -> V_192 -> V_193 ;
T_1 -> V_192 -> V_193 = * V_190 ;
} else {
V_191 = T_1 -> V_192 -> V_175 [ V_175 ] ;
T_1 -> V_192 -> V_175 [ V_175 ] = * V_190 ;
}
V_190 -> V_194 = V_190 -> V_194 - V_191 . V_194 ;
V_190 -> V_195 = V_190 -> V_195 - V_191 . V_195 ;
V_190 -> V_196 = V_190 -> V_196 - V_191 . V_196 ;
}
void F_73 ( struct V_188 * V_190 ,
bool V_36 , T_7 * V_197 )
{
T_7 V_198 = 0 ;
if ( V_36 ) {
if ( V_190 -> V_196 == 0 ) {
V_198 = - 1 ;
V_190 -> V_194 = 0 ;
} else if ( V_190 -> V_196 < V_190 -> V_195 ) {
V_198 = 1 ;
V_190 -> V_194 = ( T_3 ) ( ( double ) V_190 -> V_194 * V_190 -> V_195 / V_190 -> V_196 + 0.5 ) ;
}
} else
V_190 -> V_195 = V_190 -> V_196 = 0 ;
if ( V_197 )
* V_197 = V_198 ;
}
int F_74 ( struct V_1 * T_1 , int V_175 , int V_176 ,
T_8 V_199 )
{
struct V_188 V_190 ;
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
if ( F_54 ( T_1 , V_175 , V_176 ) < 0 )
return - V_7 ;
if ( F_75 ( F_54 ( T_1 , V_175 , V_176 ) , & V_190 , sizeof( V_190 ) ) < 0 )
return - V_200 ;
return V_199 ( T_1 , V_175 , V_176 , & V_190 ) ;
}
int F_76 ( struct V_1 * T_1 ,
int V_175 , int V_176 , bool V_36 )
{
struct V_188 V_190 ;
T_2 V_201 = V_36 ? 3 : 1 ;
if ( F_54 ( T_1 , V_175 , V_176 ) < 0 )
return - V_7 ;
if ( T_1 -> V_187 == NULL && F_62 ( T_1 , V_175 + 1 ) < 0 )
return - V_179 ;
if ( F_75 ( F_54 ( T_1 , V_175 , V_176 ) , & V_190 , V_201 * sizeof( T_3 ) ) < 0 )
return - V_200 ;
F_72 ( T_1 , V_175 , & V_190 ) ;
F_73 ( & V_190 , V_36 , NULL ) ;
T_1 -> V_187 -> V_175 [ V_175 ] = V_190 ;
return 0 ;
}
static int F_77 ( struct V_1 * T_1 , int V_175 , int V_176 )
{
struct V_1 * V_34 = T_1 -> V_34 ;
int V_178 ;
if ( F_50 ( T_1 ) )
return - 1 ;
F_78 ( ! V_34 -> V_178 ) ;
V_178 = F_54 ( V_34 , V_175 , V_176 ) ;
F_78 ( V_178 == - 1 ) ;
return V_178 ;
}
static void F_79 ( char * V_92 , T_2 V_6 , T_3 V_202 , struct V_203 * V_204 )
{
bool V_205 = true ;
int V_11 = 0 ;
do {
if ( V_202 & V_204 [ V_11 ] . V_25 ) {
V_92 += F_27 ( V_92 , V_6 , L_34 , V_205 ? L_1 : L_35 , V_204 [ V_11 ] . V_39 ) ;
V_205 = false ;
}
} while ( V_204 [ ++ V_11 ] . V_39 != NULL );
}
static void F_80 ( char * V_92 , T_2 V_6 , T_3 V_202 )
{
#define F_81 ( T_9 ) { PERF_SAMPLE_##n, #n }
struct V_203 V_204 [] = {
F_81 ( V_123 ) , F_81 ( V_124 ) , F_81 ( TIME ) , F_81 ( V_140 ) ,
F_81 ( V_126 ) , F_81 ( V_97 ) , F_81 ( V_28 ) , F_81 ( V_147 ) ,
F_81 ( V_134 ) , F_81 ( V_206 ) , F_81 ( V_151 ) ,
F_81 ( V_102 ) , F_81 ( V_107 ) , F_81 ( V_108 ) ,
F_81 ( V_29 ) , F_81 ( V_146 ) ,
{ . V_39 = NULL , }
} ;
#undef F_81
F_79 ( V_92 , V_6 , V_202 , V_204 ) ;
}
static void F_82 ( char * V_92 , T_2 V_6 , T_3 V_202 )
{
#define F_81 ( T_9 ) { PERF_FORMAT_##n, #n }
struct V_203 V_204 [] = {
F_81 ( V_207 ) , F_81 ( V_208 ) ,
F_81 ( V_28 ) , F_81 ( V_209 ) ,
{ . V_39 = NULL , }
} ;
#undef F_81
F_79 ( V_92 , V_6 , V_202 , V_204 ) ;
}
int F_83 ( T_10 * V_210 , struct V_32 * V_22 ,
T_11 V_211 , void * V_212 )
{
char V_92 [ V_213 ] ;
int V_85 = 0 ;
F_84 ( type , V_214 ) ;
F_84 ( V_6 , V_214 ) ;
F_84 ( V_45 , V_215 ) ;
F_85 ( L_36 , V_47 , V_214 ) ;
F_84 ( V_8 , V_216 ) ;
F_84 ( V_30 , V_217 ) ;
F_84 ( V_167 , V_214 ) ;
F_84 ( V_121 , V_214 ) ;
F_84 ( V_218 , V_214 ) ;
F_84 ( V_219 , V_214 ) ;
F_84 ( V_55 , V_214 ) ;
F_84 ( V_54 , V_214 ) ;
F_84 ( V_56 , V_214 ) ;
F_84 ( V_220 , V_214 ) ;
F_84 ( V_159 , V_214 ) ;
F_84 ( V_161 , V_214 ) ;
F_84 ( V_133 , V_214 ) ;
F_84 ( V_138 , V_214 ) ;
F_84 ( V_169 , V_214 ) ;
F_84 ( V_158 , V_214 ) ;
F_84 ( V_154 , V_214 ) ;
F_84 ( V_60 , V_214 ) ;
F_84 ( V_141 , V_214 ) ;
F_84 ( V_119 , V_214 ) ;
F_84 ( V_61 , V_214 ) ;
F_84 ( V_62 , V_214 ) ;
F_84 ( V_221 , V_214 ) ;
F_84 ( V_113 , V_214 ) ;
F_84 ( V_160 , V_214 ) ;
F_84 ( V_222 , V_214 ) ;
F_84 ( V_172 , V_214 ) ;
F_85 ( L_37 , V_155 , V_214 ) ;
F_84 ( V_73 , V_214 ) ;
F_85 ( L_38 , V_72 , V_215 ) ;
F_85 ( L_39 , V_223 , V_215 ) ;
F_84 ( V_109 , V_215 ) ;
F_84 ( V_111 , V_214 ) ;
F_84 ( V_171 , V_224 ) ;
F_84 ( V_145 , V_215 ) ;
return V_85 ;
}
static int F_86 ( struct V_1 * T_1 , struct V_225 * V_226 ,
struct V_227 * V_228 )
{
int V_175 , V_176 , V_174 ;
unsigned long V_229 = V_230 ;
int V_231 = - 1 , V_80 ;
enum { V_232 , V_233 , V_234 } V_235 = V_232 ;
if ( T_1 -> V_177 )
V_174 = 1 ;
else
V_174 = V_228 -> V_236 ;
if ( T_1 -> V_178 == NULL &&
F_52 ( T_1 , V_226 -> V_236 , V_174 ) < 0 )
return - V_179 ;
if ( T_1 -> V_189 ) {
V_229 |= V_237 ;
V_231 = T_1 -> V_189 -> V_178 ;
}
V_238:
if ( V_120 . V_239 )
T_1 -> V_22 . V_171 = V_240 ;
if ( V_120 . V_171 ) {
T_1 -> V_22 . V_172 = 0 ;
T_1 -> V_22 . V_171 = 0 ;
}
if ( V_120 . V_241 )
V_229 &= ~ ( unsigned long ) V_230 ;
if ( V_120 . V_160 )
T_1 -> V_22 . V_160 = 0 ;
if ( V_120 . V_62 )
T_1 -> V_22 . V_62 = T_1 -> V_22 . V_61 = 0 ;
V_242:
if ( V_120 . V_119 )
T_1 -> V_22 . V_119 = 0 ;
if ( V_243 >= 2 ) {
fprintf ( V_244 , L_40 , V_245 ) ;
fprintf ( V_244 , L_41 ) ;
F_83 ( V_244 , & T_1 -> V_22 , V_246 , NULL ) ;
fprintf ( V_244 , L_40 , V_245 ) ;
}
for ( V_175 = 0 ; V_175 < V_226 -> V_236 ; V_175 ++ ) {
for ( V_176 = 0 ; V_176 < V_174 ; V_176 ++ ) {
int V_247 ;
if ( ! T_1 -> V_189 && ! T_1 -> V_177 )
V_231 = V_228 -> V_248 [ V_176 ] ;
V_247 = F_77 ( T_1 , V_175 , V_176 ) ;
V_249:
F_87 ( L_42 ,
V_231 , V_226 -> V_248 [ V_175 ] , V_247 , V_229 ) ;
F_54 ( T_1 , V_175 , V_176 ) = F_88 ( & T_1 -> V_22 ,
V_231 ,
V_226 -> V_248 [ V_175 ] ,
V_247 , V_229 ) ;
if ( F_54 ( T_1 , V_175 , V_176 ) < 0 ) {
V_80 = - V_200 ;
F_87 ( L_43 ,
V_80 ) ;
goto V_250;
}
V_235 = V_232 ;
if ( V_120 . V_171 ||
V_120 . V_239 ) {
V_80 = - V_7 ;
goto V_251;
}
}
}
return 0 ;
V_250:
if ( V_80 == - V_252 && V_235 < V_234 ) {
struct V_253 V_254 ;
int V_255 = V_200 ;
if ( F_89 ( V_256 , & V_254 ) == 0 ) {
if ( V_235 == V_232 )
V_254 . V_257 = V_254 . V_258 ;
else {
V_254 . V_257 = V_254 . V_258 + 1000 ;
V_254 . V_258 = V_254 . V_257 ;
}
if ( F_90 ( V_256 , & V_254 ) == 0 ) {
V_235 ++ ;
V_200 = V_255 ;
goto V_249;
}
}
V_200 = V_255 ;
}
if ( V_80 != - V_7 || V_175 > 0 || V_176 > 0 )
goto V_251;
if ( ! V_120 . V_239 && T_1 -> V_22 . V_172 ) {
V_120 . V_239 = true ;
goto V_238;
} else if ( ! V_120 . V_171 && T_1 -> V_22 . V_172 ) {
V_120 . V_171 = true ;
goto V_238;
} else if ( ! V_120 . V_241 && ( V_229 & V_230 ) ) {
V_120 . V_241 = true ;
goto V_238;
} else if ( ! V_120 . V_160 && T_1 -> V_22 . V_160 ) {
V_120 . V_160 = true ;
goto V_238;
} else if ( ! V_120 . V_62 &&
( T_1 -> V_22 . V_62 || T_1 -> V_22 . V_61 ) ) {
V_120 . V_62 = true ;
goto V_238;
} else if ( ! V_120 . V_119 ) {
V_120 . V_119 = true ;
goto V_242;
}
V_251:
do {
while ( -- V_176 >= 0 ) {
F_66 ( F_54 ( T_1 , V_175 , V_176 ) ) ;
F_54 ( T_1 , V_175 , V_176 ) = - 1 ;
}
V_176 = V_174 ;
} while ( -- V_175 >= 0 );
return V_80 ;
}
void F_91 ( struct V_1 * T_1 , int V_173 , int V_174 )
{
if ( T_1 -> V_178 == NULL )
return;
F_65 ( T_1 , V_173 , V_174 ) ;
F_63 ( T_1 ) ;
}
int F_92 ( struct V_1 * T_1 , struct V_225 * V_226 ,
struct V_227 * V_228 )
{
if ( V_226 == NULL ) {
V_226 = & V_259 . V_248 ;
}
if ( V_228 == NULL )
V_228 = & V_260 . V_248 ;
return F_86 ( T_1 , V_226 , V_228 ) ;
}
int F_93 ( struct V_1 * T_1 ,
struct V_225 * V_226 )
{
return F_86 ( T_1 , V_226 , & V_260 . V_248 ) ;
}
int F_94 ( struct V_1 * T_1 ,
struct V_227 * V_228 )
{
return F_86 ( T_1 , & V_259 . V_248 , V_228 ) ;
}
static int F_95 ( const struct V_1 * T_1 ,
const union V_261 * V_262 ,
struct V_263 * V_264 )
{
T_3 type = T_1 -> V_22 . V_8 ;
const T_3 * V_265 = V_262 -> V_264 . V_265 ;
bool V_266 = T_1 -> V_267 ;
union V_268 V_269 ;
V_265 += ( ( V_262 -> V_270 . V_6 -
sizeof( V_262 -> V_270 ) ) / sizeof( T_3 ) ) - 1 ;
if ( type & V_13 ) {
V_264 -> V_46 = * V_265 ;
V_265 -- ;
}
if ( type & V_19 ) {
V_269 . V_271 = * V_265 ;
if ( V_266 ) {
V_269 . V_271 = F_96 ( V_269 . V_271 ) ;
V_269 . V_272 [ 0 ] = F_97 ( V_269 . V_272 [ 0 ] ) ;
}
V_264 -> V_175 = V_269 . V_272 [ 0 ] ;
V_265 -- ;
}
if ( type & V_20 ) {
V_264 -> V_273 = * V_265 ;
V_265 -- ;
}
if ( type & V_14 ) {
V_264 -> V_46 = * V_265 ;
V_265 -- ;
}
if ( type & V_17 ) {
V_264 -> time = * V_265 ;
V_265 -- ;
}
if ( type & V_16 ) {
V_269 . V_271 = * V_265 ;
if ( V_266 ) {
V_269 . V_271 = F_96 ( V_269 . V_271 ) ;
V_269 . V_272 [ 0 ] = F_97 ( V_269 . V_272 [ 0 ] ) ;
V_269 . V_272 [ 1 ] = F_97 ( V_269 . V_272 [ 1 ] ) ;
}
V_264 -> V_231 = V_269 . V_272 [ 0 ] ;
V_264 -> V_274 = V_269 . V_272 [ 1 ] ;
V_265 -- ;
}
return 0 ;
}
static inline bool F_98 ( const void * V_275 , T_12 V_276 , const void * V_277 ,
T_3 V_6 )
{
return V_6 > V_276 || V_277 + V_6 > V_275 ;
}
int F_99 ( struct V_1 * T_1 , union V_261 * V_262 ,
struct V_263 * V_278 )
{
T_3 type = T_1 -> V_22 . V_8 ;
bool V_266 = T_1 -> V_267 ;
const T_3 * V_265 ;
T_12 V_276 = V_262 -> V_270 . V_6 ;
const void * V_275 = ( void * ) V_262 + V_276 ;
T_3 V_279 ;
union V_268 V_269 ;
memset ( V_278 , 0 , sizeof( * V_278 ) ) ;
V_278 -> V_175 = V_278 -> V_231 = V_278 -> V_274 = - 1 ;
V_278 -> V_273 = V_278 -> V_46 = V_278 -> time = - 1ULL ;
V_278 -> V_148 = T_1 -> V_22 . V_47 ;
V_278 -> V_280 = 0 ;
if ( V_262 -> V_270 . type != V_281 ) {
if ( ! T_1 -> V_22 . V_119 )
return 0 ;
return F_95 ( T_1 , V_262 , V_278 ) ;
}
V_265 = V_262 -> V_264 . V_265 ;
if ( T_1 -> V_26 + sizeof( V_262 -> V_270 ) > V_262 -> V_270 . V_6 )
return - V_282 ;
V_278 -> V_46 = - 1ULL ;
if ( type & V_13 ) {
V_278 -> V_46 = * V_265 ;
V_265 ++ ;
}
if ( type & V_15 ) {
V_278 -> V_283 = * V_265 ;
V_265 ++ ;
}
if ( type & V_16 ) {
V_269 . V_271 = * V_265 ;
if ( V_266 ) {
V_269 . V_271 = F_96 ( V_269 . V_271 ) ;
V_269 . V_272 [ 0 ] = F_97 ( V_269 . V_272 [ 0 ] ) ;
V_269 . V_272 [ 1 ] = F_97 ( V_269 . V_272 [ 1 ] ) ;
}
V_278 -> V_231 = V_269 . V_272 [ 0 ] ;
V_278 -> V_274 = V_269 . V_272 [ 1 ] ;
V_265 ++ ;
}
if ( type & V_17 ) {
V_278 -> time = * V_265 ;
V_265 ++ ;
}
V_278 -> V_67 = 0 ;
if ( type & V_18 ) {
V_278 -> V_67 = * V_265 ;
V_265 ++ ;
}
if ( type & V_14 ) {
V_278 -> V_46 = * V_265 ;
V_265 ++ ;
}
if ( type & V_20 ) {
V_278 -> V_273 = * V_265 ;
V_265 ++ ;
}
if ( type & V_19 ) {
V_269 . V_271 = * V_265 ;
if ( V_266 ) {
V_269 . V_271 = F_96 ( V_269 . V_271 ) ;
V_269 . V_272 [ 0 ] = F_97 ( V_269 . V_272 [ 0 ] ) ;
}
V_278 -> V_175 = V_269 . V_272 [ 0 ] ;
V_265 ++ ;
}
if ( type & V_42 ) {
V_278 -> V_148 = * V_265 ;
V_265 ++ ;
}
if ( type & V_284 ) {
T_3 V_30 = T_1 -> V_22 . V_30 ;
F_100 ( V_265 ) ;
if ( V_30 & V_128 )
V_278 -> V_285 . V_286 . V_236 = * V_265 ;
else
V_278 -> V_285 . V_287 . V_202 = * V_265 ;
V_265 ++ ;
if ( V_30 & V_165 ) {
F_100 ( V_265 ) ;
V_278 -> V_285 . V_288 = * V_265 ;
V_265 ++ ;
}
if ( V_30 & V_166 ) {
F_100 ( V_265 ) ;
V_278 -> V_285 . V_289 = * V_265 ;
V_265 ++ ;
}
if ( V_30 & V_128 ) {
const T_3 V_290 = V_291 /
sizeof( struct V_292 ) ;
if ( V_278 -> V_285 . V_286 . V_236 > V_290 )
return - V_282 ;
V_279 = V_278 -> V_285 . V_286 . V_236 *
sizeof( struct V_292 ) ;
F_101 ( V_265 , V_279 , V_276 ) ;
V_278 -> V_285 . V_286 . V_293 =
(struct V_292 * ) V_265 ;
V_265 = ( void * ) V_265 + V_279 ;
} else {
F_100 ( V_265 ) ;
V_278 -> V_285 . V_287 . V_46 = * V_265 ;
V_265 ++ ;
}
}
if ( type & V_294 ) {
const T_3 V_295 = V_291 / sizeof( T_3 ) ;
F_100 ( V_265 ) ;
V_278 -> V_296 = (struct V_297 * ) V_265 ++ ;
if ( V_278 -> V_296 -> V_236 > V_295 )
return - V_282 ;
V_279 = V_278 -> V_296 -> V_236 * sizeof( T_3 ) ;
F_101 ( V_265 , V_279 , V_276 ) ;
V_265 = ( void * ) V_265 + V_279 ;
}
if ( type & V_41 ) {
F_100 ( V_265 ) ;
V_269 . V_271 = * V_265 ;
if ( F_102 ( V_266 ,
L_44 ) ) {
V_269 . V_271 = F_96 ( V_269 . V_271 ) ;
V_269 . V_272 [ 0 ] = F_97 ( V_269 . V_272 [ 0 ] ) ;
V_269 . V_272 [ 1 ] = F_97 ( V_269 . V_272 [ 1 ] ) ;
}
V_278 -> V_298 = V_269 . V_272 [ 0 ] ;
V_265 = ( void * ) V_265 + sizeof( V_299 ) ;
F_101 ( V_265 , V_278 -> V_298 , V_276 ) ;
V_278 -> V_300 = ( void * ) V_265 ;
V_265 = ( void * ) V_265 + V_278 -> V_298 ;
}
if ( type & V_301 ) {
const T_3 V_302 = V_291 /
sizeof( struct V_303 ) ;
F_100 ( V_265 ) ;
V_278 -> V_101 = (struct V_101 * ) V_265 ++ ;
if ( V_278 -> V_101 -> V_236 > V_302 )
return - V_282 ;
V_279 = V_278 -> V_101 -> V_236 * sizeof( struct V_303 ) ;
F_101 ( V_265 , V_279 , V_276 ) ;
V_265 = ( void * ) V_265 + V_279 ;
}
if ( type & V_304 ) {
F_100 ( V_265 ) ;
V_278 -> V_305 . V_306 = * V_265 ;
V_265 ++ ;
if ( V_278 -> V_305 . V_306 ) {
T_3 V_9 = T_1 -> V_22 . V_109 ;
V_279 = F_103 ( V_9 ) * sizeof( T_3 ) ;
F_101 ( V_265 , V_279 , V_276 ) ;
V_278 -> V_305 . V_9 = V_9 ;
V_278 -> V_305 . V_307 = ( T_3 * ) V_265 ;
V_265 = ( void * ) V_265 + V_279 ;
}
}
if ( type & V_308 ) {
F_100 ( V_265 ) ;
V_279 = * V_265 ++ ;
V_278 -> V_309 . V_277 = ( ( char * ) ( V_265 - 1 )
- ( char * ) V_262 ) ;
if ( ! V_279 ) {
V_278 -> V_309 . V_6 = 0 ;
} else {
F_101 ( V_265 , V_279 , V_276 ) ;
V_278 -> V_309 . V_278 = ( char * ) V_265 ;
V_265 = ( void * ) V_265 + V_279 ;
F_100 ( V_265 ) ;
V_278 -> V_309 . V_6 = * V_265 ++ ;
if ( F_102 ( V_278 -> V_309 . V_6 > V_279 ,
L_45 ) )
return - V_282 ;
}
}
V_278 -> V_280 = 0 ;
if ( type & V_310 ) {
F_100 ( V_265 ) ;
V_278 -> V_280 = * V_265 ;
V_265 ++ ;
}
V_278 -> V_311 = V_312 ;
if ( type & V_313 ) {
F_100 ( V_265 ) ;
V_278 -> V_311 = * V_265 ;
V_265 ++ ;
}
V_278 -> V_314 = 0 ;
if ( type & V_315 ) {
F_100 ( V_265 ) ;
V_278 -> V_314 = * V_265 ;
V_265 ++ ;
}
V_278 -> V_316 . V_306 = V_317 ;
if ( type & V_318 ) {
F_100 ( V_265 ) ;
V_278 -> V_316 . V_306 = * V_265 ;
V_265 ++ ;
if ( V_278 -> V_316 . V_306 != V_317 ) {
T_3 V_9 = T_1 -> V_22 . V_145 ;
V_279 = F_103 ( V_9 ) * sizeof( T_3 ) ;
F_101 ( V_265 , V_279 , V_276 ) ;
V_278 -> V_316 . V_9 = V_9 ;
V_278 -> V_316 . V_307 = ( T_3 * ) V_265 ;
V_265 = ( void * ) V_265 + V_279 ;
}
}
return 0 ;
}
T_2 F_104 ( const struct V_263 * V_264 , T_3 type ,
T_3 V_30 )
{
T_2 V_279 , V_76 = sizeof( struct V_319 ) ;
if ( type & V_13 )
V_76 += sizeof( T_3 ) ;
if ( type & V_15 )
V_76 += sizeof( T_3 ) ;
if ( type & V_16 )
V_76 += sizeof( T_3 ) ;
if ( type & V_17 )
V_76 += sizeof( T_3 ) ;
if ( type & V_18 )
V_76 += sizeof( T_3 ) ;
if ( type & V_14 )
V_76 += sizeof( T_3 ) ;
if ( type & V_20 )
V_76 += sizeof( T_3 ) ;
if ( type & V_19 )
V_76 += sizeof( T_3 ) ;
if ( type & V_42 )
V_76 += sizeof( T_3 ) ;
if ( type & V_284 ) {
V_76 += sizeof( T_3 ) ;
if ( V_30 & V_165 )
V_76 += sizeof( T_3 ) ;
if ( V_30 & V_166 )
V_76 += sizeof( T_3 ) ;
if ( V_30 & V_128 ) {
V_279 = V_264 -> V_285 . V_286 . V_236 *
sizeof( struct V_292 ) ;
V_76 += V_279 ;
} else {
V_76 += sizeof( T_3 ) ;
}
}
if ( type & V_294 ) {
V_279 = ( V_264 -> V_296 -> V_236 + 1 ) * sizeof( T_3 ) ;
V_76 += V_279 ;
}
if ( type & V_41 ) {
V_76 += sizeof( V_299 ) ;
V_76 += V_264 -> V_298 ;
}
if ( type & V_301 ) {
V_279 = V_264 -> V_101 -> V_236 * sizeof( struct V_303 ) ;
V_279 += sizeof( T_3 ) ;
V_76 += V_279 ;
}
if ( type & V_304 ) {
if ( V_264 -> V_305 . V_306 ) {
V_76 += sizeof( T_3 ) ;
V_279 = F_103 ( V_264 -> V_305 . V_9 ) * sizeof( T_3 ) ;
V_76 += V_279 ;
} else {
V_76 += sizeof( T_3 ) ;
}
}
if ( type & V_308 ) {
V_279 = V_264 -> V_309 . V_6 ;
V_76 += sizeof( T_3 ) ;
if ( V_279 ) {
V_76 += V_279 ;
V_76 += sizeof( T_3 ) ;
}
}
if ( type & V_310 )
V_76 += sizeof( T_3 ) ;
if ( type & V_313 )
V_76 += sizeof( T_3 ) ;
if ( type & V_315 )
V_76 += sizeof( T_3 ) ;
if ( type & V_318 ) {
if ( V_264 -> V_316 . V_306 ) {
V_76 += sizeof( T_3 ) ;
V_279 = F_103 ( V_264 -> V_316 . V_9 ) * sizeof( T_3 ) ;
V_76 += V_279 ;
} else {
V_76 += sizeof( T_3 ) ;
}
}
return V_76 ;
}
int F_105 ( union V_261 * V_262 , T_3 type ,
T_3 V_30 ,
const struct V_263 * V_264 ,
bool V_266 )
{
T_3 * V_265 ;
T_2 V_279 ;
union V_268 V_269 ;
V_265 = V_262 -> V_264 . V_265 ;
if ( type & V_13 ) {
* V_265 = V_264 -> V_46 ;
V_265 ++ ;
}
if ( type & V_15 ) {
* V_265 = V_264 -> V_283 ;
V_265 ++ ;
}
if ( type & V_16 ) {
V_269 . V_272 [ 0 ] = V_264 -> V_231 ;
V_269 . V_272 [ 1 ] = V_264 -> V_274 ;
if ( V_266 ) {
V_269 . V_272 [ 0 ] = F_97 ( V_269 . V_272 [ 0 ] ) ;
V_269 . V_272 [ 1 ] = F_97 ( V_269 . V_272 [ 1 ] ) ;
V_269 . V_271 = F_96 ( V_269 . V_271 ) ;
}
* V_265 = V_269 . V_271 ;
V_265 ++ ;
}
if ( type & V_17 ) {
* V_265 = V_264 -> time ;
V_265 ++ ;
}
if ( type & V_18 ) {
* V_265 = V_264 -> V_67 ;
V_265 ++ ;
}
if ( type & V_14 ) {
* V_265 = V_264 -> V_46 ;
V_265 ++ ;
}
if ( type & V_20 ) {
* V_265 = V_264 -> V_273 ;
V_265 ++ ;
}
if ( type & V_19 ) {
V_269 . V_272 [ 0 ] = V_264 -> V_175 ;
if ( V_266 ) {
V_269 . V_272 [ 0 ] = F_97 ( V_269 . V_272 [ 0 ] ) ;
V_269 . V_271 = F_96 ( V_269 . V_271 ) ;
}
* V_265 = V_269 . V_271 ;
V_265 ++ ;
}
if ( type & V_42 ) {
* V_265 = V_264 -> V_148 ;
V_265 ++ ;
}
if ( type & V_284 ) {
if ( V_30 & V_128 )
* V_265 = V_264 -> V_285 . V_286 . V_236 ;
else
* V_265 = V_264 -> V_285 . V_287 . V_202 ;
V_265 ++ ;
if ( V_30 & V_165 ) {
* V_265 = V_264 -> V_285 . V_288 ;
V_265 ++ ;
}
if ( V_30 & V_166 ) {
* V_265 = V_264 -> V_285 . V_289 ;
V_265 ++ ;
}
if ( V_30 & V_128 ) {
V_279 = V_264 -> V_285 . V_286 . V_236 *
sizeof( struct V_292 ) ;
memcpy ( V_265 , V_264 -> V_285 . V_286 . V_293 , V_279 ) ;
V_265 = ( void * ) V_265 + V_279 ;
} else {
* V_265 = V_264 -> V_285 . V_287 . V_46 ;
V_265 ++ ;
}
}
if ( type & V_294 ) {
V_279 = ( V_264 -> V_296 -> V_236 + 1 ) * sizeof( T_3 ) ;
memcpy ( V_265 , V_264 -> V_296 , V_279 ) ;
V_265 = ( void * ) V_265 + V_279 ;
}
if ( type & V_41 ) {
V_269 . V_272 [ 0 ] = V_264 -> V_298 ;
if ( F_102 ( V_266 ,
L_44 ) ) {
V_269 . V_272 [ 0 ] = F_97 ( V_269 . V_272 [ 0 ] ) ;
V_269 . V_272 [ 1 ] = F_97 ( V_269 . V_272 [ 1 ] ) ;
V_269 . V_271 = F_96 ( V_269 . V_271 ) ;
}
* V_265 = V_269 . V_271 ;
V_265 = ( void * ) V_265 + sizeof( V_299 ) ;
memcpy ( V_265 , V_264 -> V_300 , V_264 -> V_298 ) ;
V_265 = ( void * ) V_265 + V_264 -> V_298 ;
}
if ( type & V_301 ) {
V_279 = V_264 -> V_101 -> V_236 * sizeof( struct V_303 ) ;
V_279 += sizeof( T_3 ) ;
memcpy ( V_265 , V_264 -> V_101 , V_279 ) ;
V_265 = ( void * ) V_265 + V_279 ;
}
if ( type & V_304 ) {
if ( V_264 -> V_305 . V_306 ) {
* V_265 ++ = V_264 -> V_305 . V_306 ;
V_279 = F_103 ( V_264 -> V_305 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_265 , V_264 -> V_305 . V_307 , V_279 ) ;
V_265 = ( void * ) V_265 + V_279 ;
} else {
* V_265 ++ = 0 ;
}
}
if ( type & V_308 ) {
V_279 = V_264 -> V_309 . V_6 ;
* V_265 ++ = V_279 ;
if ( V_279 ) {
memcpy ( V_265 , V_264 -> V_309 . V_278 , V_279 ) ;
V_265 = ( void * ) V_265 + V_279 ;
* V_265 ++ = V_279 ;
}
}
if ( type & V_310 ) {
* V_265 = V_264 -> V_280 ;
V_265 ++ ;
}
if ( type & V_313 ) {
* V_265 = V_264 -> V_311 ;
V_265 ++ ;
}
if ( type & V_315 ) {
* V_265 = V_264 -> V_314 ;
V_265 ++ ;
}
if ( type & V_318 ) {
if ( V_264 -> V_316 . V_306 ) {
* V_265 ++ = V_264 -> V_316 . V_306 ;
V_279 = F_103 ( V_264 -> V_316 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_265 , V_264 -> V_316 . V_307 , V_279 ) ;
V_265 = ( void * ) V_265 + V_279 ;
} else {
* V_265 ++ = 0 ;
}
}
return 0 ;
}
struct V_320 * F_106 ( struct V_1 * T_1 , const char * V_39 )
{
return F_107 ( T_1 -> V_44 , V_39 ) ;
}
void * F_108 ( struct V_1 * T_1 , struct V_263 * V_264 ,
const char * V_39 )
{
struct V_320 * V_321 = F_106 ( T_1 , V_39 ) ;
int V_277 ;
if ( ! V_321 )
return NULL ;
V_277 = V_321 -> V_277 ;
if ( V_321 -> V_229 & V_322 ) {
V_277 = * ( int * ) ( V_264 -> V_300 + V_321 -> V_277 ) ;
V_277 &= 0xffff ;
}
return V_264 -> V_300 + V_277 ;
}
T_3 F_109 ( struct V_1 * T_1 , struct V_263 * V_264 ,
const char * V_39 )
{
struct V_320 * V_321 = F_106 ( T_1 , V_39 ) ;
void * V_323 ;
T_3 V_202 ;
if ( ! V_321 )
return 0 ;
V_323 = V_264 -> V_300 + V_321 -> V_277 ;
switch ( V_321 -> V_6 ) {
case 1 :
return * ( T_6 * ) V_323 ;
case 2 :
V_202 = * ( T_12 * ) V_323 ;
break;
case 4 :
V_202 = * ( V_299 * ) V_323 ;
break;
case 8 :
memcpy ( & V_202 , V_323 , sizeof( T_3 ) ) ;
break;
default:
return 0 ;
}
if ( ! T_1 -> V_267 )
return V_202 ;
switch ( V_321 -> V_6 ) {
case 2 :
return F_110 ( V_202 ) ;
case 4 :
return F_97 ( V_202 ) ;
case 8 :
return F_96 ( V_202 ) ;
default:
return 0 ;
}
return 0 ;
}
static int F_111 ( T_10 * V_210 , bool * V_324 , const char * V_325 , ... )
{
T_13 args ;
int V_85 = 0 ;
if ( ! * V_324 ) {
V_85 += fprintf ( V_210 , L_46 ) ;
} else {
V_85 += fprintf ( V_210 , L_9 ) ;
* V_324 = false ;
}
va_start ( args , V_325 ) ;
V_85 += vfprintf ( V_210 , V_325 , args ) ;
va_end ( args ) ;
return V_85 ;
}
static int F_112 ( T_10 * V_210 , const char * V_39 , const char * V_194 , void * V_212 )
{
return F_111 ( V_210 , ( bool * ) V_212 , L_47 , V_39 , V_194 ) ;
}
int F_113 ( struct V_1 * T_1 ,
struct V_326 * V_327 , T_10 * V_210 )
{
bool V_324 = true ;
int V_328 = 0 ;
if ( V_327 -> V_329 ) {
struct V_1 * V_93 ;
if ( ! F_50 ( T_1 ) )
return 0 ;
if ( T_1 -> V_127 > 1 )
V_328 += fprintf ( V_210 , L_48 , T_1 -> V_91 ? : L_1 ) ;
V_328 += fprintf ( V_210 , L_6 , F_39 ( T_1 ) ) ;
F_43 (pos, evsel)
V_328 += fprintf ( V_210 , L_49 , F_39 ( V_93 ) ) ;
if ( T_1 -> V_127 > 1 )
V_328 += fprintf ( V_210 , L_50 ) ;
goto V_330;
}
V_328 += fprintf ( V_210 , L_6 , F_39 ( T_1 ) ) ;
if ( V_327 -> V_243 ) {
V_328 += F_83 ( V_210 , & T_1 -> V_22 ,
F_112 , & V_324 ) ;
} else if ( V_327 -> V_133 ) {
V_328 += F_111 ( V_210 , & V_324 , L_51 V_331 ,
( T_3 ) T_1 -> V_22 . V_135 ) ;
}
V_330:
fputc ( '\n' , V_210 ) ;
return ++ V_328 ;
}
bool F_114 ( struct V_1 * T_1 , int V_80 ,
char * V_332 , T_2 V_333 )
{
if ( ( V_80 == V_334 || V_80 == V_335 || V_80 == V_336 ) &&
T_1 -> V_22 . type == V_87 &&
T_1 -> V_22 . V_45 == V_337 ) {
F_27 ( V_332 , V_333 , L_6 ,
L_52 ) ;
T_1 -> V_22 . type = V_89 ;
T_1 -> V_22 . V_45 = V_338 ;
F_23 ( & T_1 -> V_39 ) ;
return true ;
}
return false ;
}
int F_115 ( struct V_1 * T_1 , struct V_116 * V_116 ,
int V_80 , char * V_332 , T_2 V_6 )
{
char V_339 [ V_340 ] ;
switch ( V_80 ) {
case V_341 :
case V_342 :
return F_27 ( V_332 , V_6 ,
L_53
L_54
L_55
L_56
L_57
L_58 ,
V_116 -> V_177 ? L_59 : L_1 ) ;
case V_334 :
return F_27 ( V_332 , V_6 , L_60 ,
F_39 ( T_1 ) ) ;
case V_252 :
return F_27 ( V_332 , V_6 , L_6 ,
L_61
L_62 ) ;
case V_336 :
if ( V_116 -> V_343 )
return F_27 ( V_332 , V_6 , L_6 ,
L_63 ) ;
break;
case V_344 :
if ( T_1 -> V_22 . V_60 )
return F_27 ( V_332 , V_6 , L_6 ,
L_64 ) ;
#if F_116 ( V_345 ) || F_116 ( V_346 )
if ( T_1 -> V_22 . type == V_87 )
return F_27 ( V_332 , V_6 , L_6 ,
L_65
L_66 ) ;
#endif
break;
case V_347 :
if ( F_117 ( L_67 ) )
return F_27 ( V_332 , V_6 ,
L_68
L_69 ) ;
break;
case V_7 :
if ( V_120 . V_171 )
return F_27 ( V_332 , V_6 , L_70 ) ;
if ( V_120 . V_239 )
return F_27 ( V_332 , V_6 , L_71 , V_171 ) ;
break;
default:
break;
}
return F_27 ( V_332 , V_6 ,
L_72
L_73
L_74 ,
V_80 , F_118 ( V_80 , V_339 , sizeof( V_339 ) ) ,
F_39 ( T_1 ) ) ;
}
