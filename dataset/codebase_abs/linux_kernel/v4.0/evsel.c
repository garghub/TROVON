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
F_44 ( struct V_1 * T_1 )
{
bool V_94 = F_45 ( T_1 ) ;
struct V_32 * V_22 = & T_1 -> V_22 ;
F_14 ( T_1 , V_95 ) ;
if ( V_96 . V_97 == V_98 ) {
if ( ! V_94 ) {
F_14 ( T_1 , V_99 ) ;
F_14 ( T_1 , V_100 ) ;
V_22 -> V_101 = V_102 ;
V_22 -> V_103 = V_96 . V_104 ;
V_22 -> V_105 = 1 ;
} else {
F_46 ( L_27
L_28 ) ;
}
}
if ( V_94 ) {
F_46 ( L_29 ) ;
V_22 -> V_105 = 1 ;
}
}
void F_47 ( struct V_1 * T_1 , struct V_106 * V_107 )
{
struct V_1 * V_34 = T_1 -> V_34 ;
struct V_32 * V_22 = & T_1 -> V_22 ;
int V_108 = T_1 -> V_33 ;
bool V_109 = V_107 -> V_110 . V_111 && ! V_107 -> V_110 . V_112 ;
V_22 -> V_113 = V_114 . V_113 ? 0 : 1 ;
V_22 -> V_115 = ! V_107 -> V_116 ;
F_14 ( T_1 , V_117 ) ;
F_14 ( T_1 , V_118 ) ;
if ( T_1 -> V_119 ) {
F_14 ( T_1 , V_120 ) ;
F_12 ( T_1 , false ) ;
if ( V_34 -> V_121 > 1 ) {
V_22 -> V_30 |= V_122 ;
V_22 -> V_115 = 0 ;
}
}
if ( ! V_22 -> V_47 || ( V_107 -> V_123 != V_124 ||
V_107 -> V_125 != V_126 ) ) {
if ( V_107 -> V_127 ) {
F_14 ( T_1 , V_128 ) ;
V_22 -> V_127 = 1 ;
V_22 -> V_129 = V_107 -> V_127 ;
} else {
V_22 -> V_47 = V_107 -> V_130 ;
}
}
if ( ( V_34 != T_1 ) && V_34 -> V_119 ) {
V_22 -> V_129 = 0 ;
V_22 -> V_47 = 0 ;
}
if ( V_107 -> V_131 )
V_22 -> V_129 = 0 ;
if ( V_107 -> V_132 )
V_22 -> V_132 = 1 ;
if ( V_107 -> V_133 ) {
F_14 ( T_1 , V_134 ) ;
V_22 -> V_135 = V_108 ;
}
if ( F_45 ( T_1 ) )
T_1 -> V_22 . V_105 = 1 ;
if ( V_96 . V_136 && ! T_1 -> V_137 )
F_44 ( T_1 ) ;
if ( V_107 -> V_138 ) {
V_22 -> V_139 = V_102 ;
F_14 ( T_1 , V_140 ) ;
}
if ( F_48 ( & V_107 -> V_110 ) )
F_14 ( T_1 , V_141 ) ;
if ( V_107 -> V_142 )
F_14 ( T_1 , V_128 ) ;
if ( V_107 -> V_143 &&
( ! V_114 . V_113 &&
( ! V_107 -> V_116 || F_48 ( & V_107 -> V_110 ) || V_109 ) ) )
F_14 ( T_1 , TIME ) ;
if ( V_107 -> V_144 && ! T_1 -> V_137 ) {
F_14 ( T_1 , TIME ) ;
F_14 ( T_1 , V_145 ) ;
F_14 ( T_1 , V_141 ) ;
}
if ( V_107 -> V_133 )
F_14 ( T_1 , V_146 ) ;
if ( V_107 -> V_147 ) {
V_22 -> V_148 = 0 ;
V_22 -> V_149 = 1 ;
}
if ( V_107 -> V_150 && ! T_1 -> V_137 ) {
F_14 ( T_1 , V_151 ) ;
V_22 -> V_152 = V_107 -> V_150 ;
}
if ( V_107 -> V_153 )
F_14 ( T_1 , V_154 ) ;
V_22 -> V_155 = V_108 ;
V_22 -> V_156 = V_108 ;
V_22 -> V_157 = V_108 && ! V_114 . V_157 ;
V_22 -> V_158 = V_108 ;
if ( V_107 -> V_159 )
F_14 ( T_1 , V_160 ) ;
if ( F_49 ( T_1 ) )
V_22 -> V_161 = 1 ;
if ( F_50 ( & V_107 -> V_110 ) && F_49 ( T_1 ) &&
! V_107 -> V_162 )
V_22 -> V_163 = 1 ;
if ( T_1 -> V_164 ) {
V_22 -> V_161 = 0 ;
V_22 -> V_163 = 0 ;
}
}
static int F_51 ( struct V_1 * T_1 , int V_165 , int V_166 )
{
int V_167 , V_168 ;
if ( T_1 -> V_169 )
V_166 = 1 ;
T_1 -> V_170 = F_52 ( V_165 , V_166 , sizeof( int ) ) ;
if ( T_1 -> V_170 ) {
for ( V_167 = 0 ; V_167 < V_165 ; V_167 ++ ) {
for ( V_168 = 0 ; V_168 < V_166 ; V_168 ++ ) {
F_53 ( T_1 , V_167 , V_168 ) = - 1 ;
}
}
}
return T_1 -> V_170 != NULL ? 0 : - V_171 ;
}
static int F_54 ( struct V_1 * T_1 , int V_165 , int V_166 ,
int V_172 , void * V_173 )
{
int V_167 , V_168 ;
if ( T_1 -> V_169 )
V_166 = 1 ;
for ( V_167 = 0 ; V_167 < V_165 ; V_167 ++ ) {
for ( V_168 = 0 ; V_168 < V_166 ; V_168 ++ ) {
int V_170 = F_53 ( T_1 , V_167 , V_168 ) ,
V_80 = F_55 ( V_170 , V_172 , V_173 ) ;
if ( V_80 )
return V_80 ;
}
}
return 0 ;
}
int F_56 ( struct V_1 * T_1 , int V_165 , int V_166 ,
const char * V_174 )
{
return F_54 ( T_1 , V_165 , V_166 ,
V_175 ,
( void * ) V_174 ) ;
}
int F_57 ( struct V_1 * T_1 , int V_165 , int V_166 )
{
return F_54 ( T_1 , V_165 , V_166 ,
V_176 ,
0 ) ;
}
int F_58 ( struct V_1 * T_1 , int V_165 , int V_166 )
{
if ( V_165 == 0 || V_166 == 0 )
return 0 ;
if ( T_1 -> V_169 )
V_166 = 1 ;
T_1 -> V_177 = F_52 ( V_165 , V_166 , sizeof( struct V_178 ) ) ;
if ( T_1 -> V_177 == NULL )
return - V_171 ;
T_1 -> V_46 = F_18 ( V_165 * V_166 * sizeof( T_3 ) ) ;
if ( T_1 -> V_46 == NULL ) {
F_59 ( T_1 -> V_177 ) ;
T_1 -> V_177 = NULL ;
return - V_171 ;
}
return 0 ;
}
void F_60 ( struct V_1 * T_1 , int V_165 )
{
memset ( T_1 -> V_179 , 0 , ( sizeof( * T_1 -> V_179 ) +
( V_165 * sizeof( struct V_180 ) ) ) ) ;
}
int F_61 ( struct V_1 * T_1 , int V_165 )
{
T_1 -> V_179 = F_18 ( ( sizeof( * T_1 -> V_179 ) +
( V_165 * sizeof( struct V_180 ) ) ) ) ;
return T_1 -> V_179 != NULL ? 0 : - V_171 ;
}
static void F_62 ( struct V_1 * T_1 )
{
F_59 ( T_1 -> V_170 ) ;
T_1 -> V_170 = NULL ;
}
static void F_63 ( struct V_1 * T_1 )
{
F_59 ( T_1 -> V_177 ) ;
T_1 -> V_177 = NULL ;
F_23 ( & T_1 -> V_46 ) ;
}
void F_64 ( struct V_1 * T_1 , int V_165 , int V_166 )
{
int V_167 , V_168 ;
if ( T_1 -> V_169 )
V_166 = 1 ;
for ( V_167 = 0 ; V_167 < V_165 ; V_167 ++ )
for ( V_168 = 0 ; V_168 < V_166 ; ++ V_168 ) {
F_65 ( F_53 ( T_1 , V_167 , V_168 ) ) ;
F_53 ( T_1 , V_167 , V_168 ) = - 1 ;
}
}
void F_66 ( struct V_1 * T_1 )
{
F_23 ( & T_1 -> V_179 ) ;
}
void F_67 ( struct V_1 * T_1 )
{
assert ( F_68 ( & T_1 -> V_37 ) ) ;
F_62 ( T_1 ) ;
F_63 ( T_1 ) ;
F_69 ( T_1 -> V_181 ) ;
F_23 ( & T_1 -> V_91 ) ;
F_23 ( & T_1 -> V_39 ) ;
V_5 . F_5 ( T_1 ) ;
}
void F_70 ( struct V_1 * T_1 )
{
F_67 ( T_1 ) ;
free ( T_1 ) ;
}
void F_71 ( struct V_1 * T_1 , int V_167 ,
struct V_180 * V_182 )
{
struct V_180 V_183 ;
if ( ! T_1 -> V_184 )
return;
if ( V_167 == - 1 ) {
V_183 = T_1 -> V_184 -> V_185 ;
T_1 -> V_184 -> V_185 = * V_182 ;
} else {
V_183 = T_1 -> V_184 -> V_167 [ V_167 ] ;
T_1 -> V_184 -> V_167 [ V_167 ] = * V_182 ;
}
V_182 -> V_186 = V_182 -> V_186 - V_183 . V_186 ;
V_182 -> V_187 = V_182 -> V_187 - V_183 . V_187 ;
V_182 -> V_188 = V_182 -> V_188 - V_183 . V_188 ;
}
void F_72 ( struct V_180 * V_182 ,
bool V_36 , T_7 * V_189 )
{
T_7 V_190 = 0 ;
if ( V_36 ) {
if ( V_182 -> V_188 == 0 ) {
V_190 = - 1 ;
V_182 -> V_186 = 0 ;
} else if ( V_182 -> V_188 < V_182 -> V_187 ) {
V_190 = 1 ;
V_182 -> V_186 = ( T_3 ) ( ( double ) V_182 -> V_186 * V_182 -> V_187 / V_182 -> V_188 + 0.5 ) ;
}
} else
V_182 -> V_187 = V_182 -> V_188 = 0 ;
if ( V_189 )
* V_189 = V_190 ;
}
int F_73 ( struct V_1 * T_1 , int V_167 , int V_168 ,
T_8 V_191 )
{
struct V_180 V_182 ;
memset ( & V_182 , 0 , sizeof( V_182 ) ) ;
if ( F_53 ( T_1 , V_167 , V_168 ) < 0 )
return - V_7 ;
if ( F_74 ( F_53 ( T_1 , V_167 , V_168 ) , & V_182 , sizeof( V_182 ) ) < 0 )
return - V_192 ;
return V_191 ( T_1 , V_167 , V_168 , & V_182 ) ;
}
int F_75 ( struct V_1 * T_1 ,
int V_167 , int V_168 , bool V_36 )
{
struct V_180 V_182 ;
T_2 V_193 = V_36 ? 3 : 1 ;
if ( F_53 ( T_1 , V_167 , V_168 ) < 0 )
return - V_7 ;
if ( T_1 -> V_179 == NULL && F_61 ( T_1 , V_167 + 1 ) < 0 )
return - V_171 ;
if ( F_74 ( F_53 ( T_1 , V_167 , V_168 ) , & V_182 , V_193 * sizeof( T_3 ) ) < 0 )
return - V_192 ;
F_71 ( T_1 , V_167 , & V_182 ) ;
F_72 ( & V_182 , V_36 , NULL ) ;
T_1 -> V_179 -> V_167 [ V_167 ] = V_182 ;
return 0 ;
}
static int F_76 ( struct V_1 * T_1 , int V_167 , int V_168 )
{
struct V_1 * V_34 = T_1 -> V_34 ;
int V_170 ;
if ( F_49 ( T_1 ) )
return - 1 ;
F_77 ( ! V_34 -> V_170 ) ;
V_170 = F_53 ( V_34 , V_167 , V_168 ) ;
F_77 ( V_170 == - 1 ) ;
return V_170 ;
}
static T_2 F_78 ( struct V_32 * V_22 , T_9 * V_194 )
{
T_2 V_85 = 0 ;
V_85 += fprintf ( V_194 , L_30 , V_195 ) ;
V_85 += fprintf ( V_194 , L_31 ) ;
V_85 += F_79 ( type ) ;
V_85 += F_79 ( V_6 ) ;
V_85 += F_80 ( V_45 ) ;
V_85 += F_81 ( V_47 ) ;
V_85 += F_81 ( V_129 ) ;
V_85 += F_80 ( V_8 ) ;
V_85 += F_80 ( V_30 ) ;
V_85 += F_82 ( V_161 , V_115 ) ;
V_85 += F_82 ( V_196 , V_197 ) ;
V_85 += F_82 ( V_55 , V_54 ) ;
V_85 += F_82 ( V_56 , V_198 ) ;
V_85 += F_82 ( V_156 , V_158 ) ;
V_85 += F_82 ( V_157 , V_199 ) ;
V_85 += F_82 ( V_127 , V_132 ) ;
V_85 += F_82 ( V_163 , V_155 ) ;
V_85 += F_82 ( V_148 , V_60 ) ;
V_85 += F_82 ( V_135 , V_113 ) ;
V_85 += F_82 ( V_61 , V_62 ) ;
V_85 += F_83 ( L_32 , V_200 ,
L_33 , V_105 ) ;
V_85 += F_79 ( V_149 ) ;
V_85 += F_79 ( V_201 ) ;
V_85 += F_84 ( V_73 ) ;
V_85 += F_80 ( V_72 ) ;
V_85 += F_80 ( V_202 ) ;
V_85 += F_81 ( V_203 ) ;
V_85 += F_80 ( V_204 ) ;
V_85 += F_80 ( V_152 ) ;
V_85 += F_80 ( V_101 ) ;
V_85 += F_79 ( V_103 ) ;
V_85 += F_80 ( V_139 ) ;
V_85 += fprintf ( V_194 , L_30 , V_195 ) ;
return V_85 ;
}
static int F_85 ( struct V_1 * T_1 , struct V_205 * V_206 ,
struct V_207 * V_208 )
{
int V_167 , V_168 , V_166 ;
unsigned long V_209 = V_210 ;
int V_211 = - 1 , V_80 ;
enum { V_212 , V_213 , V_214 } V_215 = V_212 ;
if ( T_1 -> V_169 )
V_166 = 1 ;
else
V_166 = V_208 -> V_216 ;
if ( T_1 -> V_170 == NULL &&
F_51 ( T_1 , V_206 -> V_216 , V_166 ) < 0 )
return - V_171 ;
if ( T_1 -> V_181 ) {
V_209 |= V_217 ;
V_211 = T_1 -> V_181 -> V_170 ;
}
V_218:
if ( V_114 . V_219 )
V_209 &= ~ ( unsigned long ) V_210 ;
if ( V_114 . V_157 )
T_1 -> V_22 . V_157 = 0 ;
if ( V_114 . V_62 )
T_1 -> V_22 . V_62 = T_1 -> V_22 . V_61 = 0 ;
V_220:
if ( V_114 . V_113 )
T_1 -> V_22 . V_113 = 0 ;
if ( V_221 >= 2 )
F_78 ( & T_1 -> V_22 , V_222 ) ;
for ( V_167 = 0 ; V_167 < V_206 -> V_216 ; V_167 ++ ) {
for ( V_168 = 0 ; V_168 < V_166 ; V_168 ++ ) {
int V_223 ;
if ( ! T_1 -> V_181 && ! T_1 -> V_169 )
V_211 = V_208 -> V_224 [ V_168 ] ;
V_223 = F_76 ( T_1 , V_167 , V_168 ) ;
V_225:
F_86 ( L_34 ,
V_211 , V_206 -> V_224 [ V_167 ] , V_223 , V_209 ) ;
F_53 ( T_1 , V_167 , V_168 ) = F_87 ( & T_1 -> V_22 ,
V_211 ,
V_206 -> V_224 [ V_167 ] ,
V_223 , V_209 ) ;
if ( F_53 ( T_1 , V_167 , V_168 ) < 0 ) {
V_80 = - V_192 ;
F_86 ( L_35 ,
V_80 ) ;
goto V_226;
}
V_215 = V_212 ;
}
}
return 0 ;
V_226:
if ( V_80 == - V_227 && V_215 < V_214 ) {
struct V_228 V_229 ;
int V_230 = V_192 ;
if ( F_88 ( V_231 , & V_229 ) == 0 ) {
if ( V_215 == V_212 )
V_229 . V_232 = V_229 . V_233 ;
else {
V_229 . V_232 = V_229 . V_233 + 1000 ;
V_229 . V_233 = V_229 . V_232 ;
}
if ( F_89 ( V_231 , & V_229 ) == 0 ) {
V_215 ++ ;
V_192 = V_230 ;
goto V_225;
}
}
V_192 = V_230 ;
}
if ( V_80 != - V_7 || V_167 > 0 || V_168 > 0 )
goto V_234;
if ( ! V_114 . V_219 && ( V_209 & V_210 ) ) {
V_114 . V_219 = true ;
goto V_218;
} else if ( ! V_114 . V_157 && T_1 -> V_22 . V_157 ) {
V_114 . V_157 = true ;
goto V_218;
} else if ( ! V_114 . V_62 &&
( T_1 -> V_22 . V_62 || T_1 -> V_22 . V_61 ) ) {
V_114 . V_62 = true ;
goto V_218;
} else if ( ! V_114 . V_113 ) {
V_114 . V_113 = true ;
goto V_220;
}
V_234:
do {
while ( -- V_168 >= 0 ) {
F_65 ( F_53 ( T_1 , V_167 , V_168 ) ) ;
F_53 ( T_1 , V_167 , V_168 ) = - 1 ;
}
V_168 = V_166 ;
} while ( -- V_167 >= 0 );
return V_80 ;
}
void F_90 ( struct V_1 * T_1 , int V_165 , int V_166 )
{
if ( T_1 -> V_170 == NULL )
return;
F_64 ( T_1 , V_165 , V_166 ) ;
F_62 ( T_1 ) ;
}
int F_91 ( struct V_1 * T_1 , struct V_205 * V_206 ,
struct V_207 * V_208 )
{
if ( V_206 == NULL ) {
V_206 = & V_235 . V_224 ;
}
if ( V_208 == NULL )
V_208 = & V_236 . V_224 ;
return F_85 ( T_1 , V_206 , V_208 ) ;
}
int F_92 ( struct V_1 * T_1 ,
struct V_205 * V_206 )
{
return F_85 ( T_1 , V_206 , & V_236 . V_224 ) ;
}
int F_93 ( struct V_1 * T_1 ,
struct V_207 * V_208 )
{
return F_85 ( T_1 , & V_235 . V_224 , V_208 ) ;
}
static int F_94 ( const struct V_1 * T_1 ,
const union V_237 * V_238 ,
struct V_239 * V_240 )
{
T_3 type = T_1 -> V_22 . V_8 ;
const T_3 * V_241 = V_238 -> V_240 . V_241 ;
bool V_242 = T_1 -> V_243 ;
union V_244 V_245 ;
V_241 += ( ( V_238 -> V_246 . V_6 -
sizeof( V_238 -> V_246 ) ) / sizeof( T_3 ) ) - 1 ;
if ( type & V_13 ) {
V_240 -> V_46 = * V_241 ;
V_241 -- ;
}
if ( type & V_19 ) {
V_245 . V_247 = * V_241 ;
if ( V_242 ) {
V_245 . V_247 = F_95 ( V_245 . V_247 ) ;
V_245 . V_248 [ 0 ] = F_96 ( V_245 . V_248 [ 0 ] ) ;
}
V_240 -> V_167 = V_245 . V_248 [ 0 ] ;
V_241 -- ;
}
if ( type & V_20 ) {
V_240 -> V_249 = * V_241 ;
V_241 -- ;
}
if ( type & V_14 ) {
V_240 -> V_46 = * V_241 ;
V_241 -- ;
}
if ( type & V_17 ) {
V_240 -> time = * V_241 ;
V_241 -- ;
}
if ( type & V_16 ) {
V_245 . V_247 = * V_241 ;
if ( V_242 ) {
V_245 . V_247 = F_95 ( V_245 . V_247 ) ;
V_245 . V_248 [ 0 ] = F_96 ( V_245 . V_248 [ 0 ] ) ;
V_245 . V_248 [ 1 ] = F_96 ( V_245 . V_248 [ 1 ] ) ;
}
V_240 -> V_211 = V_245 . V_248 [ 0 ] ;
V_240 -> V_250 = V_245 . V_248 [ 1 ] ;
V_241 -- ;
}
return 0 ;
}
static inline bool F_97 ( const void * V_251 , T_10 V_252 , const void * V_253 ,
T_3 V_6 )
{
return V_6 > V_252 || V_253 + V_6 > V_251 ;
}
int F_98 ( struct V_1 * T_1 , union V_237 * V_238 ,
struct V_239 * V_254 )
{
T_3 type = T_1 -> V_22 . V_8 ;
bool V_242 = T_1 -> V_243 ;
const T_3 * V_241 ;
T_10 V_252 = V_238 -> V_246 . V_6 ;
const void * V_251 = ( void * ) V_238 + V_252 ;
T_3 V_255 ;
union V_244 V_245 ;
memset ( V_254 , 0 , sizeof( * V_254 ) ) ;
V_254 -> V_167 = V_254 -> V_211 = V_254 -> V_250 = - 1 ;
V_254 -> V_249 = V_254 -> V_46 = V_254 -> time = - 1ULL ;
V_254 -> V_142 = T_1 -> V_22 . V_47 ;
V_254 -> V_256 = 0 ;
if ( V_238 -> V_246 . type != V_257 ) {
if ( ! T_1 -> V_22 . V_113 )
return 0 ;
return F_94 ( T_1 , V_238 , V_254 ) ;
}
V_241 = V_238 -> V_240 . V_241 ;
if ( T_1 -> V_26 + sizeof( V_238 -> V_246 ) > V_238 -> V_246 . V_6 )
return - V_258 ;
V_254 -> V_46 = - 1ULL ;
if ( type & V_13 ) {
V_254 -> V_46 = * V_241 ;
V_241 ++ ;
}
if ( type & V_15 ) {
V_254 -> V_259 = * V_241 ;
V_241 ++ ;
}
if ( type & V_16 ) {
V_245 . V_247 = * V_241 ;
if ( V_242 ) {
V_245 . V_247 = F_95 ( V_245 . V_247 ) ;
V_245 . V_248 [ 0 ] = F_96 ( V_245 . V_248 [ 0 ] ) ;
V_245 . V_248 [ 1 ] = F_96 ( V_245 . V_248 [ 1 ] ) ;
}
V_254 -> V_211 = V_245 . V_248 [ 0 ] ;
V_254 -> V_250 = V_245 . V_248 [ 1 ] ;
V_241 ++ ;
}
if ( type & V_17 ) {
V_254 -> time = * V_241 ;
V_241 ++ ;
}
V_254 -> V_67 = 0 ;
if ( type & V_18 ) {
V_254 -> V_67 = * V_241 ;
V_241 ++ ;
}
if ( type & V_14 ) {
V_254 -> V_46 = * V_241 ;
V_241 ++ ;
}
if ( type & V_20 ) {
V_254 -> V_249 = * V_241 ;
V_241 ++ ;
}
if ( type & V_19 ) {
V_245 . V_247 = * V_241 ;
if ( V_242 ) {
V_245 . V_247 = F_95 ( V_245 . V_247 ) ;
V_245 . V_248 [ 0 ] = F_96 ( V_245 . V_248 [ 0 ] ) ;
}
V_254 -> V_167 = V_245 . V_248 [ 0 ] ;
V_241 ++ ;
}
if ( type & V_42 ) {
V_254 -> V_142 = * V_241 ;
V_241 ++ ;
}
if ( type & V_260 ) {
T_3 V_30 = T_1 -> V_22 . V_30 ;
F_99 ( V_241 ) ;
if ( V_30 & V_122 )
V_254 -> V_261 . V_262 . V_216 = * V_241 ;
else
V_254 -> V_261 . V_263 . V_264 = * V_241 ;
V_241 ++ ;
if ( V_30 & V_265 ) {
F_99 ( V_241 ) ;
V_254 -> V_261 . V_266 = * V_241 ;
V_241 ++ ;
}
if ( V_30 & V_267 ) {
F_99 ( V_241 ) ;
V_254 -> V_261 . V_268 = * V_241 ;
V_241 ++ ;
}
if ( V_30 & V_122 ) {
const T_3 V_269 = V_270 /
sizeof( struct V_271 ) ;
if ( V_254 -> V_261 . V_262 . V_216 > V_269 )
return - V_258 ;
V_255 = V_254 -> V_261 . V_262 . V_216 *
sizeof( struct V_271 ) ;
F_100 ( V_241 , V_255 , V_252 ) ;
V_254 -> V_261 . V_262 . V_272 =
(struct V_271 * ) V_241 ;
V_241 = ( void * ) V_241 + V_255 ;
} else {
F_99 ( V_241 ) ;
V_254 -> V_261 . V_263 . V_46 = * V_241 ;
V_241 ++ ;
}
}
if ( type & V_273 ) {
const T_3 V_274 = V_270 / sizeof( T_3 ) ;
F_99 ( V_241 ) ;
V_254 -> V_275 = (struct V_276 * ) V_241 ++ ;
if ( V_254 -> V_275 -> V_216 > V_274 )
return - V_258 ;
V_255 = V_254 -> V_275 -> V_216 * sizeof( T_3 ) ;
F_100 ( V_241 , V_255 , V_252 ) ;
V_241 = ( void * ) V_241 + V_255 ;
}
if ( type & V_41 ) {
F_99 ( V_241 ) ;
V_245 . V_247 = * V_241 ;
if ( F_101 ( V_242 ,
L_36 ) ) {
V_245 . V_247 = F_95 ( V_245 . V_247 ) ;
V_245 . V_248 [ 0 ] = F_96 ( V_245 . V_248 [ 0 ] ) ;
V_245 . V_248 [ 1 ] = F_96 ( V_245 . V_248 [ 1 ] ) ;
}
V_254 -> V_277 = V_245 . V_248 [ 0 ] ;
V_241 = ( void * ) V_241 + sizeof( V_278 ) ;
F_100 ( V_241 , V_254 -> V_277 , V_252 ) ;
V_254 -> V_279 = ( void * ) V_241 ;
V_241 = ( void * ) V_241 + V_254 -> V_277 ;
}
if ( type & V_280 ) {
const T_3 V_281 = V_270 /
sizeof( struct V_282 ) ;
F_99 ( V_241 ) ;
V_254 -> V_150 = (struct V_150 * ) V_241 ++ ;
if ( V_254 -> V_150 -> V_216 > V_281 )
return - V_258 ;
V_255 = V_254 -> V_150 -> V_216 * sizeof( struct V_282 ) ;
F_100 ( V_241 , V_255 , V_252 ) ;
V_241 = ( void * ) V_241 + V_255 ;
}
if ( type & V_283 ) {
F_99 ( V_241 ) ;
V_254 -> V_284 . V_285 = * V_241 ;
V_241 ++ ;
if ( V_254 -> V_284 . V_285 ) {
T_3 V_9 = T_1 -> V_22 . V_101 ;
V_255 = F_102 ( V_9 ) * sizeof( T_3 ) ;
F_100 ( V_241 , V_255 , V_252 ) ;
V_254 -> V_284 . V_9 = V_9 ;
V_254 -> V_284 . V_286 = ( T_3 * ) V_241 ;
V_241 = ( void * ) V_241 + V_255 ;
}
}
if ( type & V_287 ) {
F_99 ( V_241 ) ;
V_255 = * V_241 ++ ;
V_254 -> V_288 . V_253 = ( ( char * ) ( V_241 - 1 )
- ( char * ) V_238 ) ;
if ( ! V_255 ) {
V_254 -> V_288 . V_6 = 0 ;
} else {
F_100 ( V_241 , V_255 , V_252 ) ;
V_254 -> V_288 . V_254 = ( char * ) V_241 ;
V_241 = ( void * ) V_241 + V_255 ;
F_99 ( V_241 ) ;
V_254 -> V_288 . V_6 = * V_241 ++ ;
if ( F_101 ( V_254 -> V_288 . V_6 > V_255 ,
L_37 ) )
return - V_258 ;
}
}
V_254 -> V_256 = 0 ;
if ( type & V_289 ) {
F_99 ( V_241 ) ;
V_254 -> V_256 = * V_241 ;
V_241 ++ ;
}
V_254 -> V_290 = V_291 ;
if ( type & V_292 ) {
F_99 ( V_241 ) ;
V_254 -> V_290 = * V_241 ;
V_241 ++ ;
}
V_254 -> V_293 = 0 ;
if ( type & V_294 ) {
F_99 ( V_241 ) ;
V_254 -> V_293 = * V_241 ;
V_241 ++ ;
}
V_254 -> V_295 . V_285 = V_296 ;
if ( type & V_297 ) {
F_99 ( V_241 ) ;
V_254 -> V_295 . V_285 = * V_241 ;
V_241 ++ ;
if ( V_254 -> V_295 . V_285 != V_296 ) {
T_3 V_9 = T_1 -> V_22 . V_139 ;
V_255 = F_102 ( V_9 ) * sizeof( T_3 ) ;
F_100 ( V_241 , V_255 , V_252 ) ;
V_254 -> V_295 . V_9 = V_9 ;
V_254 -> V_295 . V_286 = ( T_3 * ) V_241 ;
V_241 = ( void * ) V_241 + V_255 ;
}
}
return 0 ;
}
T_2 F_103 ( const struct V_239 * V_240 , T_3 type ,
T_3 V_30 )
{
T_2 V_255 , V_76 = sizeof( struct V_298 ) ;
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
if ( type & V_260 ) {
V_76 += sizeof( T_3 ) ;
if ( V_30 & V_265 )
V_76 += sizeof( T_3 ) ;
if ( V_30 & V_267 )
V_76 += sizeof( T_3 ) ;
if ( V_30 & V_122 ) {
V_255 = V_240 -> V_261 . V_262 . V_216 *
sizeof( struct V_271 ) ;
V_76 += V_255 ;
} else {
V_76 += sizeof( T_3 ) ;
}
}
if ( type & V_273 ) {
V_255 = ( V_240 -> V_275 -> V_216 + 1 ) * sizeof( T_3 ) ;
V_76 += V_255 ;
}
if ( type & V_41 ) {
V_76 += sizeof( V_278 ) ;
V_76 += V_240 -> V_277 ;
}
if ( type & V_280 ) {
V_255 = V_240 -> V_150 -> V_216 * sizeof( struct V_282 ) ;
V_255 += sizeof( T_3 ) ;
V_76 += V_255 ;
}
if ( type & V_283 ) {
if ( V_240 -> V_284 . V_285 ) {
V_76 += sizeof( T_3 ) ;
V_255 = F_102 ( V_240 -> V_284 . V_9 ) * sizeof( T_3 ) ;
V_76 += V_255 ;
} else {
V_76 += sizeof( T_3 ) ;
}
}
if ( type & V_287 ) {
V_255 = V_240 -> V_288 . V_6 ;
V_76 += sizeof( T_3 ) ;
if ( V_255 ) {
V_76 += V_255 ;
V_76 += sizeof( T_3 ) ;
}
}
if ( type & V_289 )
V_76 += sizeof( T_3 ) ;
if ( type & V_292 )
V_76 += sizeof( T_3 ) ;
if ( type & V_294 )
V_76 += sizeof( T_3 ) ;
if ( type & V_297 ) {
if ( V_240 -> V_295 . V_285 ) {
V_76 += sizeof( T_3 ) ;
V_255 = F_102 ( V_240 -> V_295 . V_9 ) * sizeof( T_3 ) ;
V_76 += V_255 ;
} else {
V_76 += sizeof( T_3 ) ;
}
}
return V_76 ;
}
int F_104 ( union V_237 * V_238 , T_3 type ,
T_3 V_30 ,
const struct V_239 * V_240 ,
bool V_242 )
{
T_3 * V_241 ;
T_2 V_255 ;
union V_244 V_245 ;
V_241 = V_238 -> V_240 . V_241 ;
if ( type & V_13 ) {
* V_241 = V_240 -> V_46 ;
V_241 ++ ;
}
if ( type & V_15 ) {
* V_241 = V_240 -> V_259 ;
V_241 ++ ;
}
if ( type & V_16 ) {
V_245 . V_248 [ 0 ] = V_240 -> V_211 ;
V_245 . V_248 [ 1 ] = V_240 -> V_250 ;
if ( V_242 ) {
V_245 . V_248 [ 0 ] = F_96 ( V_245 . V_248 [ 0 ] ) ;
V_245 . V_248 [ 1 ] = F_96 ( V_245 . V_248 [ 1 ] ) ;
V_245 . V_247 = F_95 ( V_245 . V_247 ) ;
}
* V_241 = V_245 . V_247 ;
V_241 ++ ;
}
if ( type & V_17 ) {
* V_241 = V_240 -> time ;
V_241 ++ ;
}
if ( type & V_18 ) {
* V_241 = V_240 -> V_67 ;
V_241 ++ ;
}
if ( type & V_14 ) {
* V_241 = V_240 -> V_46 ;
V_241 ++ ;
}
if ( type & V_20 ) {
* V_241 = V_240 -> V_249 ;
V_241 ++ ;
}
if ( type & V_19 ) {
V_245 . V_248 [ 0 ] = V_240 -> V_167 ;
if ( V_242 ) {
V_245 . V_248 [ 0 ] = F_96 ( V_245 . V_248 [ 0 ] ) ;
V_245 . V_247 = F_95 ( V_245 . V_247 ) ;
}
* V_241 = V_245 . V_247 ;
V_241 ++ ;
}
if ( type & V_42 ) {
* V_241 = V_240 -> V_142 ;
V_241 ++ ;
}
if ( type & V_260 ) {
if ( V_30 & V_122 )
* V_241 = V_240 -> V_261 . V_262 . V_216 ;
else
* V_241 = V_240 -> V_261 . V_263 . V_264 ;
V_241 ++ ;
if ( V_30 & V_265 ) {
* V_241 = V_240 -> V_261 . V_266 ;
V_241 ++ ;
}
if ( V_30 & V_267 ) {
* V_241 = V_240 -> V_261 . V_268 ;
V_241 ++ ;
}
if ( V_30 & V_122 ) {
V_255 = V_240 -> V_261 . V_262 . V_216 *
sizeof( struct V_271 ) ;
memcpy ( V_241 , V_240 -> V_261 . V_262 . V_272 , V_255 ) ;
V_241 = ( void * ) V_241 + V_255 ;
} else {
* V_241 = V_240 -> V_261 . V_263 . V_46 ;
V_241 ++ ;
}
}
if ( type & V_273 ) {
V_255 = ( V_240 -> V_275 -> V_216 + 1 ) * sizeof( T_3 ) ;
memcpy ( V_241 , V_240 -> V_275 , V_255 ) ;
V_241 = ( void * ) V_241 + V_255 ;
}
if ( type & V_41 ) {
V_245 . V_248 [ 0 ] = V_240 -> V_277 ;
if ( F_101 ( V_242 ,
L_36 ) ) {
V_245 . V_248 [ 0 ] = F_96 ( V_245 . V_248 [ 0 ] ) ;
V_245 . V_248 [ 1 ] = F_96 ( V_245 . V_248 [ 1 ] ) ;
V_245 . V_247 = F_95 ( V_245 . V_247 ) ;
}
* V_241 = V_245 . V_247 ;
V_241 = ( void * ) V_241 + sizeof( V_278 ) ;
memcpy ( V_241 , V_240 -> V_279 , V_240 -> V_277 ) ;
V_241 = ( void * ) V_241 + V_240 -> V_277 ;
}
if ( type & V_280 ) {
V_255 = V_240 -> V_150 -> V_216 * sizeof( struct V_282 ) ;
V_255 += sizeof( T_3 ) ;
memcpy ( V_241 , V_240 -> V_150 , V_255 ) ;
V_241 = ( void * ) V_241 + V_255 ;
}
if ( type & V_283 ) {
if ( V_240 -> V_284 . V_285 ) {
* V_241 ++ = V_240 -> V_284 . V_285 ;
V_255 = F_102 ( V_240 -> V_284 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_241 , V_240 -> V_284 . V_286 , V_255 ) ;
V_241 = ( void * ) V_241 + V_255 ;
} else {
* V_241 ++ = 0 ;
}
}
if ( type & V_287 ) {
V_255 = V_240 -> V_288 . V_6 ;
* V_241 ++ = V_255 ;
if ( V_255 ) {
memcpy ( V_241 , V_240 -> V_288 . V_254 , V_255 ) ;
V_241 = ( void * ) V_241 + V_255 ;
* V_241 ++ = V_255 ;
}
}
if ( type & V_289 ) {
* V_241 = V_240 -> V_256 ;
V_241 ++ ;
}
if ( type & V_292 ) {
* V_241 = V_240 -> V_290 ;
V_241 ++ ;
}
if ( type & V_294 ) {
* V_241 = V_240 -> V_293 ;
V_241 ++ ;
}
if ( type & V_297 ) {
if ( V_240 -> V_295 . V_285 ) {
* V_241 ++ = V_240 -> V_295 . V_285 ;
V_255 = F_102 ( V_240 -> V_295 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_241 , V_240 -> V_295 . V_286 , V_255 ) ;
V_241 = ( void * ) V_241 + V_255 ;
} else {
* V_241 ++ = 0 ;
}
}
return 0 ;
}
struct V_299 * F_105 ( struct V_1 * T_1 , const char * V_39 )
{
return F_106 ( T_1 -> V_44 , V_39 ) ;
}
void * F_107 ( struct V_1 * T_1 , struct V_239 * V_240 ,
const char * V_39 )
{
struct V_299 * V_300 = F_105 ( T_1 , V_39 ) ;
int V_253 ;
if ( ! V_300 )
return NULL ;
V_253 = V_300 -> V_253 ;
if ( V_300 -> V_209 & V_301 ) {
V_253 = * ( int * ) ( V_240 -> V_279 + V_300 -> V_253 ) ;
V_253 &= 0xffff ;
}
return V_240 -> V_279 + V_253 ;
}
T_3 F_108 ( struct V_1 * T_1 , struct V_239 * V_240 ,
const char * V_39 )
{
struct V_299 * V_300 = F_105 ( T_1 , V_39 ) ;
void * V_302 ;
T_3 V_264 ;
if ( ! V_300 )
return 0 ;
V_302 = V_240 -> V_279 + V_300 -> V_253 ;
switch ( V_300 -> V_6 ) {
case 1 :
return * ( T_6 * ) V_302 ;
case 2 :
V_264 = * ( T_10 * ) V_302 ;
break;
case 4 :
V_264 = * ( V_278 * ) V_302 ;
break;
case 8 :
V_264 = * ( T_3 * ) V_302 ;
break;
default:
return 0 ;
}
if ( ! T_1 -> V_243 )
return V_264 ;
switch ( V_300 -> V_6 ) {
case 2 :
return F_109 ( V_264 ) ;
case 4 :
return F_96 ( V_264 ) ;
case 8 :
return F_95 ( V_264 ) ;
default:
return 0 ;
}
return 0 ;
}
static int F_110 ( T_9 * V_194 , bool * V_303 , const char * V_304 , ... )
{
T_11 args ;
int V_85 = 0 ;
if ( ! * V_303 ) {
V_85 += fprintf ( V_194 , L_38 ) ;
} else {
V_85 += fprintf ( V_194 , L_9 ) ;
* V_303 = false ;
}
va_start ( args , V_304 ) ;
V_85 += vfprintf ( V_194 , V_304 , args ) ;
va_end ( args ) ;
return V_85 ;
}
static int F_111 ( T_9 * V_194 , bool * V_303 , const char * V_300 , T_3 V_264 )
{
if ( V_264 == 0 )
return 0 ;
return F_110 ( V_194 , V_303 , L_39 V_305 , V_300 , V_264 ) ;
}
static int F_112 ( T_9 * V_194 , const char * V_300 , T_3 V_264 ,
struct V_306 * V_307 , bool * V_303 )
{
int V_11 = 0 , V_308 = F_110 ( V_194 , V_303 , L_40 , V_300 ) ;
bool V_309 = true ;
do {
if ( V_264 & V_307 [ V_11 ] . V_25 ) {
V_308 += fprintf ( V_194 , L_41 , V_309 ? L_1 : L_42 , V_307 [ V_11 ] . V_39 ) ;
V_309 = false ;
}
} while ( V_307 [ ++ V_11 ] . V_39 != NULL );
return V_308 ;
}
static int F_113 ( T_9 * V_194 , bool * V_303 , T_3 V_264 )
{
#define F_114 ( T_12 ) { PERF_SAMPLE_##n, #n }
struct V_306 V_307 [] = {
F_114 ( V_117 ) , F_114 ( V_118 ) , F_114 ( TIME ) , F_114 ( V_134 ) ,
F_114 ( V_120 ) , F_114 ( V_95 ) , F_114 ( V_28 ) , F_114 ( V_141 ) ,
F_114 ( V_128 ) , F_114 ( V_310 ) , F_114 ( V_145 ) ,
F_114 ( V_151 ) , F_114 ( V_99 ) , F_114 ( V_100 ) ,
F_114 ( V_29 ) , F_114 ( V_140 ) ,
{ . V_39 = NULL , }
} ;
#undef F_114
return F_112 ( V_194 , L_43 , V_264 , V_307 , V_303 ) ;
}
static int F_115 ( T_9 * V_194 , bool * V_303 , T_3 V_264 )
{
#define F_114 ( T_12 ) { PERF_FORMAT_##n, #n }
struct V_306 V_307 [] = {
F_114 ( V_311 ) , F_114 ( V_312 ) ,
F_114 ( V_28 ) , F_114 ( V_313 ) ,
{ . V_39 = NULL , }
} ;
#undef F_114
return F_112 ( V_194 , L_44 , V_264 , V_307 , V_303 ) ;
}
int F_116 ( struct V_1 * T_1 ,
struct V_314 * V_315 , T_9 * V_194 )
{
bool V_303 = true ;
int V_308 = 0 ;
if ( V_315 -> V_316 ) {
struct V_1 * V_93 ;
if ( ! F_49 ( T_1 ) )
return 0 ;
if ( T_1 -> V_121 > 1 )
V_308 += fprintf ( V_194 , L_45 , T_1 -> V_91 ? : L_1 ) ;
V_308 += fprintf ( V_194 , L_6 , F_39 ( T_1 ) ) ;
F_43 (pos, evsel)
V_308 += fprintf ( V_194 , L_46 , F_39 ( V_93 ) ) ;
if ( T_1 -> V_121 > 1 )
V_308 += fprintf ( V_194 , L_47 ) ;
goto V_317;
}
V_308 += fprintf ( V_194 , L_6 , F_39 ( T_1 ) ) ;
if ( V_315 -> V_221 || V_315 -> V_127 ) {
V_308 += F_110 ( V_194 , & V_303 , L_48 V_305 ,
( T_3 ) T_1 -> V_22 . V_129 ) ;
}
if ( V_315 -> V_221 ) {
F_117 ( type ) ;
F_117 ( V_45 ) ;
F_117 ( V_202 ) ;
F_117 ( V_204 ) ;
F_117 ( V_6 ) ;
V_308 += F_113 ( V_194 , & V_303 , T_1 -> V_22 . V_8 ) ;
if ( T_1 -> V_22 . V_30 )
V_308 += F_115 ( V_194 , & V_303 , T_1 -> V_22 . V_30 ) ;
F_117 ( V_161 ) ;
F_117 ( V_115 ) ;
F_117 ( V_196 ) ;
F_117 ( V_197 ) ;
F_117 ( V_55 ) ;
F_117 ( V_54 ) ;
F_117 ( V_56 ) ;
F_117 ( V_198 ) ;
F_117 ( V_156 ) ;
F_117 ( V_157 ) ;
F_117 ( V_158 ) ;
F_117 ( V_199 ) ;
F_117 ( V_127 ) ;
F_117 ( V_132 ) ;
F_117 ( V_163 ) ;
F_117 ( V_155 ) ;
F_117 ( V_148 ) ;
F_117 ( V_60 ) ;
F_117 ( V_135 ) ;
F_117 ( V_113 ) ;
F_117 ( V_61 ) ;
F_117 ( V_62 ) ;
F_117 ( V_318 ) ;
F_117 ( V_149 ) ;
F_117 ( V_73 ) ;
F_117 ( V_152 ) ;
}
V_317:
fputc ( '\n' , V_194 ) ;
return ++ V_308 ;
}
bool F_118 ( struct V_1 * T_1 , int V_80 ,
char * V_319 , T_2 V_320 )
{
if ( ( V_80 == V_321 || V_80 == V_322 || V_80 == V_323 ) &&
T_1 -> V_22 . type == V_87 &&
T_1 -> V_22 . V_45 == V_324 ) {
F_27 ( V_319 , V_320 , L_6 ,
L_49 ) ;
T_1 -> V_22 . type = V_89 ;
T_1 -> V_22 . V_45 = V_325 ;
F_23 ( & T_1 -> V_39 ) ;
return true ;
}
return false ;
}
int F_119 ( struct V_1 * T_1 , struct V_110 * V_110 ,
int V_80 , char * V_319 , T_2 V_6 )
{
char V_326 [ V_327 ] ;
switch ( V_80 ) {
case V_328 :
case V_329 :
return F_27 ( V_319 , V_6 ,
L_50
L_51
L_52
L_53
L_54
L_55 ,
V_110 -> V_169 ? L_56 : L_1 ) ;
case V_321 :
return F_27 ( V_319 , V_6 , L_57 ,
F_39 ( T_1 ) ) ;
case V_227 :
return F_27 ( V_319 , V_6 , L_6 ,
L_58
L_59 ) ;
case V_323 :
if ( V_110 -> V_330 )
return F_27 ( V_319 , V_6 , L_6 ,
L_60 ) ;
break;
case V_331 :
if ( T_1 -> V_22 . V_60 )
return F_27 ( V_319 , V_6 , L_6 ,
L_61 ) ;
#if F_120 ( V_332 ) || F_120 ( V_333 )
if ( T_1 -> V_22 . type == V_87 )
return F_27 ( V_319 , V_6 , L_6 ,
L_62
L_63 ) ;
#endif
break;
case V_334 :
if ( F_121 ( L_64 ) )
return F_27 ( V_319 , V_6 ,
L_65
L_66 ) ;
break;
default:
break;
}
return F_27 ( V_319 , V_6 ,
L_67
L_68
L_69 ,
V_80 , F_122 ( V_80 , V_326 , sizeof( V_326 ) ) ,
F_39 ( T_1 ) ) ;
}
