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
if ( V_96 . V_136 && ! T_1 -> V_137 )
F_44 ( T_1 ) ;
if ( F_48 ( & V_107 -> V_110 ) )
F_14 ( T_1 , V_138 ) ;
if ( V_107 -> V_139 )
F_14 ( T_1 , V_128 ) ;
if ( V_107 -> V_140 &&
( ! V_114 . V_113 &&
( ! V_107 -> V_116 || F_48 ( & V_107 -> V_110 ) || V_109 ) ) )
F_14 ( T_1 , TIME ) ;
if ( V_107 -> V_141 && ! T_1 -> V_137 ) {
F_14 ( T_1 , TIME ) ;
F_14 ( T_1 , V_142 ) ;
F_14 ( T_1 , V_138 ) ;
}
if ( V_107 -> V_133 )
F_14 ( T_1 , V_143 ) ;
if ( V_107 -> V_144 ) {
V_22 -> V_145 = 0 ;
V_22 -> V_146 = 1 ;
}
if ( V_107 -> V_147 && ! T_1 -> V_137 ) {
F_14 ( T_1 , V_148 ) ;
V_22 -> V_149 = V_107 -> V_147 ;
}
if ( V_107 -> V_150 )
F_14 ( T_1 , V_151 ) ;
V_22 -> V_152 = V_108 ;
V_22 -> V_153 = V_108 && ! V_114 . V_153 ;
V_22 -> V_154 = V_108 ;
if ( V_107 -> V_155 )
F_14 ( T_1 , V_156 ) ;
if ( F_49 ( T_1 ) )
V_22 -> V_157 = 1 ;
if ( F_50 ( & V_107 -> V_110 ) && F_49 ( T_1 ) &&
! V_107 -> V_158 )
V_22 -> V_159 = 1 ;
if ( T_1 -> V_160 ) {
V_22 -> V_157 = 0 ;
V_22 -> V_159 = 0 ;
}
}
static int F_51 ( struct V_1 * T_1 , int V_161 , int V_162 )
{
int V_163 , V_164 ;
if ( T_1 -> V_165 )
V_162 = 1 ;
T_1 -> V_166 = F_52 ( V_161 , V_162 , sizeof( int ) ) ;
if ( T_1 -> V_166 ) {
for ( V_163 = 0 ; V_163 < V_161 ; V_163 ++ ) {
for ( V_164 = 0 ; V_164 < V_162 ; V_164 ++ ) {
F_53 ( T_1 , V_163 , V_164 ) = - 1 ;
}
}
}
return T_1 -> V_166 != NULL ? 0 : - V_167 ;
}
static int F_54 ( struct V_1 * T_1 , int V_161 , int V_162 ,
int V_168 , void * V_169 )
{
int V_163 , V_164 ;
if ( T_1 -> V_165 )
V_162 = 1 ;
for ( V_163 = 0 ; V_163 < V_161 ; V_163 ++ ) {
for ( V_164 = 0 ; V_164 < V_162 ; V_164 ++ ) {
int V_166 = F_53 ( T_1 , V_163 , V_164 ) ,
V_80 = F_55 ( V_166 , V_168 , V_169 ) ;
if ( V_80 )
return V_80 ;
}
}
return 0 ;
}
int F_56 ( struct V_1 * T_1 , int V_161 , int V_162 ,
const char * V_170 )
{
return F_54 ( T_1 , V_161 , V_162 ,
V_171 ,
( void * ) V_170 ) ;
}
int F_57 ( struct V_1 * T_1 , int V_161 , int V_162 )
{
return F_54 ( T_1 , V_161 , V_162 ,
V_172 ,
0 ) ;
}
int F_58 ( struct V_1 * T_1 , int V_161 , int V_162 )
{
if ( T_1 -> V_165 )
V_162 = 1 ;
T_1 -> V_173 = F_52 ( V_161 , V_162 , sizeof( struct V_174 ) ) ;
if ( T_1 -> V_173 == NULL )
return - V_167 ;
T_1 -> V_46 = F_18 ( V_161 * V_162 * sizeof( T_3 ) ) ;
if ( T_1 -> V_46 == NULL ) {
F_59 ( T_1 -> V_173 ) ;
T_1 -> V_173 = NULL ;
return - V_167 ;
}
return 0 ;
}
void F_60 ( struct V_1 * T_1 , int V_161 )
{
memset ( T_1 -> V_175 , 0 , ( sizeof( * T_1 -> V_175 ) +
( V_161 * sizeof( struct V_176 ) ) ) ) ;
}
int F_61 ( struct V_1 * T_1 , int V_161 )
{
T_1 -> V_175 = F_18 ( ( sizeof( * T_1 -> V_175 ) +
( V_161 * sizeof( struct V_176 ) ) ) ) ;
return T_1 -> V_175 != NULL ? 0 : - V_167 ;
}
static void F_62 ( struct V_1 * T_1 )
{
F_59 ( T_1 -> V_166 ) ;
T_1 -> V_166 = NULL ;
}
static void F_63 ( struct V_1 * T_1 )
{
F_59 ( T_1 -> V_173 ) ;
T_1 -> V_173 = NULL ;
F_23 ( & T_1 -> V_46 ) ;
}
void F_64 ( struct V_1 * T_1 , int V_161 , int V_162 )
{
int V_163 , V_164 ;
if ( T_1 -> V_165 )
V_162 = 1 ;
for ( V_163 = 0 ; V_163 < V_161 ; V_163 ++ )
for ( V_164 = 0 ; V_164 < V_162 ; ++ V_164 ) {
F_65 ( F_53 ( T_1 , V_163 , V_164 ) ) ;
F_53 ( T_1 , V_163 , V_164 ) = - 1 ;
}
}
void F_66 ( struct V_1 * T_1 )
{
F_23 ( & T_1 -> V_175 ) ;
}
void F_67 ( struct V_1 * T_1 )
{
assert ( F_68 ( & T_1 -> V_37 ) ) ;
F_62 ( T_1 ) ;
F_63 ( T_1 ) ;
F_69 ( T_1 -> V_177 ) ;
F_23 ( & T_1 -> V_91 ) ;
if ( T_1 -> V_44 )
F_70 ( T_1 -> V_44 ) ;
F_23 ( & T_1 -> V_39 ) ;
V_5 . F_5 ( T_1 ) ;
}
void F_71 ( struct V_1 * T_1 )
{
F_67 ( T_1 ) ;
free ( T_1 ) ;
}
static inline void F_72 ( struct V_1 * T_1 ,
int V_163 ,
struct V_176 * V_178 )
{
struct V_176 V_179 ;
if ( ! T_1 -> V_180 )
return;
if ( V_163 == - 1 ) {
V_179 = T_1 -> V_180 -> V_181 ;
T_1 -> V_180 -> V_181 = * V_178 ;
} else {
V_179 = T_1 -> V_180 -> V_163 [ V_163 ] ;
T_1 -> V_180 -> V_163 [ V_163 ] = * V_178 ;
}
V_178 -> V_182 = V_178 -> V_182 - V_179 . V_182 ;
V_178 -> V_183 = V_178 -> V_183 - V_179 . V_183 ;
V_178 -> V_184 = V_178 -> V_184 - V_179 . V_184 ;
}
int F_73 ( struct V_1 * T_1 ,
int V_163 , int V_164 , bool V_36 )
{
struct V_176 V_178 ;
T_2 V_185 = V_36 ? 3 : 1 ;
if ( F_53 ( T_1 , V_163 , V_164 ) < 0 )
return - V_7 ;
if ( T_1 -> V_175 == NULL && F_61 ( T_1 , V_163 + 1 ) < 0 )
return - V_167 ;
if ( F_74 ( F_53 ( T_1 , V_163 , V_164 ) , & V_178 , V_185 * sizeof( T_3 ) ) < 0 )
return - V_186 ;
F_72 ( T_1 , V_163 , & V_178 ) ;
if ( V_36 ) {
if ( V_178 . V_184 == 0 )
V_178 . V_182 = 0 ;
else if ( V_178 . V_184 < V_178 . V_183 )
V_178 . V_182 = ( T_3 ) ( ( double ) V_178 . V_182 * V_178 . V_183 / V_178 . V_184 + 0.5 ) ;
} else
V_178 . V_183 = V_178 . V_184 = 0 ;
T_1 -> V_175 -> V_163 [ V_163 ] = V_178 ;
return 0 ;
}
int F_75 ( struct V_1 * T_1 ,
int V_161 , int V_162 , bool V_36 )
{
T_2 V_185 = V_36 ? 3 : 1 ;
int V_163 , V_164 ;
struct V_176 * V_181 = & T_1 -> V_175 -> V_181 , V_178 ;
if ( T_1 -> V_165 )
V_162 = 1 ;
V_181 -> V_182 = V_181 -> V_183 = V_181 -> V_184 = 0 ;
for ( V_163 = 0 ; V_163 < V_161 ; V_163 ++ ) {
for ( V_164 = 0 ; V_164 < V_162 ; V_164 ++ ) {
if ( F_53 ( T_1 , V_163 , V_164 ) < 0 )
continue;
if ( F_74 ( F_53 ( T_1 , V_163 , V_164 ) ,
& V_178 , V_185 * sizeof( T_3 ) ) < 0 )
return - V_186 ;
V_181 -> V_182 += V_178 . V_182 ;
if ( V_36 ) {
V_181 -> V_183 += V_178 . V_183 ;
V_181 -> V_184 += V_178 . V_184 ;
}
}
}
F_72 ( T_1 , - 1 , V_181 ) ;
T_1 -> V_175 -> V_187 = 0 ;
if ( V_36 ) {
if ( V_181 -> V_184 == 0 ) {
T_1 -> V_175 -> V_187 = - 1 ;
V_181 -> V_182 = 0 ;
return 0 ;
}
if ( V_181 -> V_184 < V_181 -> V_183 ) {
T_1 -> V_175 -> V_187 = 1 ;
V_181 -> V_182 = ( T_3 ) ( ( double ) V_181 -> V_182 * V_181 -> V_183 / V_181 -> V_184 + 0.5 ) ;
}
} else
V_181 -> V_183 = V_181 -> V_184 = 0 ;
return 0 ;
}
static int F_76 ( struct V_1 * T_1 , int V_163 , int V_164 )
{
struct V_1 * V_34 = T_1 -> V_34 ;
int V_166 ;
if ( F_49 ( T_1 ) )
return - 1 ;
F_77 ( ! V_34 -> V_166 ) ;
V_166 = F_53 ( V_34 , V_163 , V_164 ) ;
F_77 ( V_166 == - 1 ) ;
return V_166 ;
}
static T_2 F_78 ( struct V_32 * V_22 , T_7 * V_188 )
{
T_2 V_85 = 0 ;
V_85 += fprintf ( V_188 , L_30 , V_189 ) ;
V_85 += fprintf ( V_188 , L_31 ) ;
V_85 += F_79 ( type ) ;
V_85 += F_79 ( V_6 ) ;
V_85 += F_80 ( V_45 ) ;
V_85 += F_81 ( V_47 ) ;
V_85 += F_81 ( V_129 ) ;
V_85 += F_80 ( V_8 ) ;
V_85 += F_80 ( V_30 ) ;
V_85 += F_82 ( V_157 , V_115 ) ;
V_85 += F_82 ( V_190 , V_191 ) ;
V_85 += F_82 ( V_55 , V_54 ) ;
V_85 += F_82 ( V_56 , V_192 ) ;
V_85 += F_82 ( V_152 , V_154 ) ;
V_85 += F_82 ( V_153 , V_193 ) ;
V_85 += F_82 ( V_127 , V_132 ) ;
V_85 += F_82 ( V_159 , V_194 ) ;
V_85 += F_82 ( V_145 , V_60 ) ;
V_85 += F_82 ( V_135 , V_113 ) ;
V_85 += F_82 ( V_61 , V_62 ) ;
V_85 += F_83 ( L_32 , V_195 ,
L_33 , V_105 ) ;
V_85 += F_79 ( V_146 ) ;
V_85 += F_79 ( V_196 ) ;
V_85 += F_84 ( V_73 ) ;
V_85 += F_80 ( V_72 ) ;
V_85 += F_80 ( V_197 ) ;
V_85 += F_81 ( V_198 ) ;
V_85 += F_80 ( V_199 ) ;
V_85 += F_80 ( V_149 ) ;
V_85 += F_80 ( V_101 ) ;
V_85 += F_79 ( V_103 ) ;
V_85 += fprintf ( V_188 , L_30 , V_189 ) ;
return V_85 ;
}
static int F_85 ( struct V_1 * T_1 , struct V_200 * V_201 ,
struct V_202 * V_203 )
{
int V_163 , V_164 , V_162 ;
unsigned long V_204 = V_205 ;
int V_206 = - 1 , V_80 ;
enum { V_207 , V_208 , V_209 } V_210 = V_207 ;
if ( T_1 -> V_165 )
V_162 = 1 ;
else
V_162 = V_203 -> V_211 ;
if ( T_1 -> V_166 == NULL &&
F_51 ( T_1 , V_201 -> V_211 , V_162 ) < 0 )
return - V_167 ;
if ( T_1 -> V_177 ) {
V_204 |= V_212 ;
V_206 = T_1 -> V_177 -> V_166 ;
}
V_213:
if ( V_114 . V_214 )
V_204 &= ~ ( unsigned long ) V_205 ;
if ( V_114 . V_153 )
T_1 -> V_22 . V_153 = 0 ;
if ( V_114 . V_62 )
T_1 -> V_22 . V_62 = T_1 -> V_22 . V_61 = 0 ;
V_215:
if ( V_114 . V_113 )
T_1 -> V_22 . V_113 = 0 ;
if ( V_216 >= 2 )
F_78 ( & T_1 -> V_22 , V_217 ) ;
for ( V_163 = 0 ; V_163 < V_201 -> V_211 ; V_163 ++ ) {
for ( V_164 = 0 ; V_164 < V_162 ; V_164 ++ ) {
int V_218 ;
if ( ! T_1 -> V_177 && ! T_1 -> V_165 )
V_206 = V_203 -> V_219 [ V_164 ] ;
V_218 = F_76 ( T_1 , V_163 , V_164 ) ;
V_220:
F_86 ( L_34 ,
V_206 , V_201 -> V_219 [ V_163 ] , V_218 , V_204 ) ;
F_53 ( T_1 , V_163 , V_164 ) = F_87 ( & T_1 -> V_22 ,
V_206 ,
V_201 -> V_219 [ V_163 ] ,
V_218 , V_204 ) ;
if ( F_53 ( T_1 , V_163 , V_164 ) < 0 ) {
V_80 = - V_186 ;
F_86 ( L_35 ,
V_80 ) ;
goto V_221;
}
V_210 = V_207 ;
}
}
return 0 ;
V_221:
if ( V_80 == - V_222 && V_210 < V_209 ) {
struct V_223 V_224 ;
int V_225 = V_186 ;
if ( F_88 ( V_226 , & V_224 ) == 0 ) {
if ( V_210 == V_207 )
V_224 . V_227 = V_224 . V_228 ;
else {
V_224 . V_227 = V_224 . V_228 + 1000 ;
V_224 . V_228 = V_224 . V_227 ;
}
if ( F_89 ( V_226 , & V_224 ) == 0 ) {
V_210 ++ ;
V_186 = V_225 ;
goto V_220;
}
}
V_186 = V_225 ;
}
if ( V_80 != - V_7 || V_163 > 0 || V_164 > 0 )
goto V_229;
if ( ! V_114 . V_214 && ( V_204 & V_205 ) ) {
V_114 . V_214 = true ;
goto V_213;
} else if ( ! V_114 . V_153 && T_1 -> V_22 . V_153 ) {
V_114 . V_153 = true ;
goto V_213;
} else if ( ! V_114 . V_62 &&
( T_1 -> V_22 . V_62 || T_1 -> V_22 . V_61 ) ) {
V_114 . V_62 = true ;
goto V_213;
} else if ( ! V_114 . V_113 ) {
V_114 . V_113 = true ;
goto V_215;
}
V_229:
do {
while ( -- V_164 >= 0 ) {
F_65 ( F_53 ( T_1 , V_163 , V_164 ) ) ;
F_53 ( T_1 , V_163 , V_164 ) = - 1 ;
}
V_164 = V_162 ;
} while ( -- V_163 >= 0 );
return V_80 ;
}
void F_90 ( struct V_1 * T_1 , int V_161 , int V_162 )
{
if ( T_1 -> V_166 == NULL )
return;
F_64 ( T_1 , V_161 , V_162 ) ;
F_62 ( T_1 ) ;
}
int F_91 ( struct V_1 * T_1 , struct V_200 * V_201 ,
struct V_202 * V_203 )
{
if ( V_201 == NULL ) {
V_201 = & V_230 . V_219 ;
}
if ( V_203 == NULL )
V_203 = & V_231 . V_219 ;
return F_85 ( T_1 , V_201 , V_203 ) ;
}
int F_92 ( struct V_1 * T_1 ,
struct V_200 * V_201 )
{
return F_85 ( T_1 , V_201 , & V_231 . V_219 ) ;
}
int F_93 ( struct V_1 * T_1 ,
struct V_202 * V_203 )
{
return F_85 ( T_1 , & V_230 . V_219 , V_203 ) ;
}
static int F_94 ( const struct V_1 * T_1 ,
const union V_232 * V_233 ,
struct V_234 * V_235 )
{
T_3 type = T_1 -> V_22 . V_8 ;
const T_3 * V_236 = V_233 -> V_235 . V_236 ;
bool V_237 = T_1 -> V_238 ;
union V_239 V_240 ;
V_236 += ( ( V_233 -> V_241 . V_6 -
sizeof( V_233 -> V_241 ) ) / sizeof( T_3 ) ) - 1 ;
if ( type & V_13 ) {
V_235 -> V_46 = * V_236 ;
V_236 -- ;
}
if ( type & V_19 ) {
V_240 . V_242 = * V_236 ;
if ( V_237 ) {
V_240 . V_242 = F_95 ( V_240 . V_242 ) ;
V_240 . V_243 [ 0 ] = F_96 ( V_240 . V_243 [ 0 ] ) ;
}
V_235 -> V_163 = V_240 . V_243 [ 0 ] ;
V_236 -- ;
}
if ( type & V_20 ) {
V_235 -> V_244 = * V_236 ;
V_236 -- ;
}
if ( type & V_14 ) {
V_235 -> V_46 = * V_236 ;
V_236 -- ;
}
if ( type & V_17 ) {
V_235 -> time = * V_236 ;
V_236 -- ;
}
if ( type & V_16 ) {
V_240 . V_242 = * V_236 ;
if ( V_237 ) {
V_240 . V_242 = F_95 ( V_240 . V_242 ) ;
V_240 . V_243 [ 0 ] = F_96 ( V_240 . V_243 [ 0 ] ) ;
V_240 . V_243 [ 1 ] = F_96 ( V_240 . V_243 [ 1 ] ) ;
}
V_235 -> V_206 = V_240 . V_243 [ 0 ] ;
V_235 -> V_245 = V_240 . V_243 [ 1 ] ;
V_236 -- ;
}
return 0 ;
}
static inline bool F_97 ( const void * V_246 , T_8 V_247 , const void * V_248 ,
T_3 V_6 )
{
return V_6 > V_247 || V_248 + V_6 > V_246 ;
}
int F_98 ( struct V_1 * T_1 , union V_232 * V_233 ,
struct V_234 * V_249 )
{
T_3 type = T_1 -> V_22 . V_8 ;
bool V_237 = T_1 -> V_238 ;
const T_3 * V_236 ;
T_8 V_247 = V_233 -> V_241 . V_6 ;
const void * V_246 = ( void * ) V_233 + V_247 ;
T_3 V_250 ;
union V_239 V_240 ;
memset ( V_249 , 0 , sizeof( * V_249 ) ) ;
V_249 -> V_163 = V_249 -> V_206 = V_249 -> V_245 = - 1 ;
V_249 -> V_244 = V_249 -> V_46 = V_249 -> time = - 1ULL ;
V_249 -> V_139 = T_1 -> V_22 . V_47 ;
V_249 -> V_251 = 0 ;
if ( V_233 -> V_241 . type != V_252 ) {
if ( ! T_1 -> V_22 . V_113 )
return 0 ;
return F_94 ( T_1 , V_233 , V_249 ) ;
}
V_236 = V_233 -> V_235 . V_236 ;
if ( T_1 -> V_26 + sizeof( V_233 -> V_241 ) > V_233 -> V_241 . V_6 )
return - V_253 ;
V_249 -> V_46 = - 1ULL ;
if ( type & V_13 ) {
V_249 -> V_46 = * V_236 ;
V_236 ++ ;
}
if ( type & V_15 ) {
V_249 -> V_254 = * V_236 ;
V_236 ++ ;
}
if ( type & V_16 ) {
V_240 . V_242 = * V_236 ;
if ( V_237 ) {
V_240 . V_242 = F_95 ( V_240 . V_242 ) ;
V_240 . V_243 [ 0 ] = F_96 ( V_240 . V_243 [ 0 ] ) ;
V_240 . V_243 [ 1 ] = F_96 ( V_240 . V_243 [ 1 ] ) ;
}
V_249 -> V_206 = V_240 . V_243 [ 0 ] ;
V_249 -> V_245 = V_240 . V_243 [ 1 ] ;
V_236 ++ ;
}
if ( type & V_17 ) {
V_249 -> time = * V_236 ;
V_236 ++ ;
}
V_249 -> V_67 = 0 ;
if ( type & V_18 ) {
V_249 -> V_67 = * V_236 ;
V_236 ++ ;
}
if ( type & V_14 ) {
V_249 -> V_46 = * V_236 ;
V_236 ++ ;
}
if ( type & V_20 ) {
V_249 -> V_244 = * V_236 ;
V_236 ++ ;
}
if ( type & V_19 ) {
V_240 . V_242 = * V_236 ;
if ( V_237 ) {
V_240 . V_242 = F_95 ( V_240 . V_242 ) ;
V_240 . V_243 [ 0 ] = F_96 ( V_240 . V_243 [ 0 ] ) ;
}
V_249 -> V_163 = V_240 . V_243 [ 0 ] ;
V_236 ++ ;
}
if ( type & V_42 ) {
V_249 -> V_139 = * V_236 ;
V_236 ++ ;
}
if ( type & V_255 ) {
T_3 V_30 = T_1 -> V_22 . V_30 ;
F_99 ( V_236 ) ;
if ( V_30 & V_122 )
V_249 -> V_256 . V_257 . V_211 = * V_236 ;
else
V_249 -> V_256 . V_258 . V_259 = * V_236 ;
V_236 ++ ;
if ( V_30 & V_260 ) {
F_99 ( V_236 ) ;
V_249 -> V_256 . V_261 = * V_236 ;
V_236 ++ ;
}
if ( V_30 & V_262 ) {
F_99 ( V_236 ) ;
V_249 -> V_256 . V_263 = * V_236 ;
V_236 ++ ;
}
if ( V_30 & V_122 ) {
const T_3 V_264 = V_265 /
sizeof( struct V_266 ) ;
if ( V_249 -> V_256 . V_257 . V_211 > V_264 )
return - V_253 ;
V_250 = V_249 -> V_256 . V_257 . V_211 *
sizeof( struct V_266 ) ;
F_100 ( V_236 , V_250 , V_247 ) ;
V_249 -> V_256 . V_257 . V_267 =
(struct V_266 * ) V_236 ;
V_236 = ( void * ) V_236 + V_250 ;
} else {
F_99 ( V_236 ) ;
V_249 -> V_256 . V_258 . V_46 = * V_236 ;
V_236 ++ ;
}
}
if ( type & V_268 ) {
const T_3 V_269 = V_265 / sizeof( T_3 ) ;
F_99 ( V_236 ) ;
V_249 -> V_270 = (struct V_271 * ) V_236 ++ ;
if ( V_249 -> V_270 -> V_211 > V_269 )
return - V_253 ;
V_250 = V_249 -> V_270 -> V_211 * sizeof( T_3 ) ;
F_100 ( V_236 , V_250 , V_247 ) ;
V_236 = ( void * ) V_236 + V_250 ;
}
if ( type & V_41 ) {
F_99 ( V_236 ) ;
V_240 . V_242 = * V_236 ;
if ( F_101 ( V_237 ,
L_36 ) ) {
V_240 . V_242 = F_95 ( V_240 . V_242 ) ;
V_240 . V_243 [ 0 ] = F_96 ( V_240 . V_243 [ 0 ] ) ;
V_240 . V_243 [ 1 ] = F_96 ( V_240 . V_243 [ 1 ] ) ;
}
V_249 -> V_272 = V_240 . V_243 [ 0 ] ;
V_236 = ( void * ) V_236 + sizeof( V_273 ) ;
F_100 ( V_236 , V_249 -> V_272 , V_247 ) ;
V_249 -> V_274 = ( void * ) V_236 ;
V_236 = ( void * ) V_236 + V_249 -> V_272 ;
}
if ( type & V_275 ) {
const T_3 V_276 = V_265 /
sizeof( struct V_277 ) ;
F_99 ( V_236 ) ;
V_249 -> V_147 = (struct V_147 * ) V_236 ++ ;
if ( V_249 -> V_147 -> V_211 > V_276 )
return - V_253 ;
V_250 = V_249 -> V_147 -> V_211 * sizeof( struct V_277 ) ;
F_100 ( V_236 , V_250 , V_247 ) ;
V_236 = ( void * ) V_236 + V_250 ;
}
if ( type & V_278 ) {
F_99 ( V_236 ) ;
V_249 -> V_279 . V_280 = * V_236 ;
V_236 ++ ;
if ( V_249 -> V_279 . V_280 ) {
T_3 V_9 = T_1 -> V_22 . V_101 ;
V_250 = F_102 ( V_9 ) * sizeof( T_3 ) ;
F_100 ( V_236 , V_250 , V_247 ) ;
V_249 -> V_279 . V_9 = V_9 ;
V_249 -> V_279 . V_281 = ( T_3 * ) V_236 ;
V_236 = ( void * ) V_236 + V_250 ;
}
}
if ( type & V_282 ) {
F_99 ( V_236 ) ;
V_250 = * V_236 ++ ;
V_249 -> V_283 . V_248 = ( ( char * ) ( V_236 - 1 )
- ( char * ) V_233 ) ;
if ( ! V_250 ) {
V_249 -> V_283 . V_6 = 0 ;
} else {
F_100 ( V_236 , V_250 , V_247 ) ;
V_249 -> V_283 . V_249 = ( char * ) V_236 ;
V_236 = ( void * ) V_236 + V_250 ;
F_99 ( V_236 ) ;
V_249 -> V_283 . V_6 = * V_236 ++ ;
if ( F_101 ( V_249 -> V_283 . V_6 > V_250 ,
L_37 ) )
return - V_253 ;
}
}
V_249 -> V_251 = 0 ;
if ( type & V_284 ) {
F_99 ( V_236 ) ;
V_249 -> V_251 = * V_236 ;
V_236 ++ ;
}
V_249 -> V_285 = V_286 ;
if ( type & V_287 ) {
F_99 ( V_236 ) ;
V_249 -> V_285 = * V_236 ;
V_236 ++ ;
}
V_249 -> V_288 = 0 ;
if ( type & V_289 ) {
F_99 ( V_236 ) ;
V_249 -> V_288 = * V_236 ;
V_236 ++ ;
}
return 0 ;
}
T_2 F_103 ( const struct V_234 * V_235 , T_3 type ,
T_3 V_30 )
{
T_2 V_250 , V_76 = sizeof( struct V_290 ) ;
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
if ( type & V_255 ) {
V_76 += sizeof( T_3 ) ;
if ( V_30 & V_260 )
V_76 += sizeof( T_3 ) ;
if ( V_30 & V_262 )
V_76 += sizeof( T_3 ) ;
if ( V_30 & V_122 ) {
V_250 = V_235 -> V_256 . V_257 . V_211 *
sizeof( struct V_266 ) ;
V_76 += V_250 ;
} else {
V_76 += sizeof( T_3 ) ;
}
}
if ( type & V_268 ) {
V_250 = ( V_235 -> V_270 -> V_211 + 1 ) * sizeof( T_3 ) ;
V_76 += V_250 ;
}
if ( type & V_41 ) {
V_76 += sizeof( V_273 ) ;
V_76 += V_235 -> V_272 ;
}
if ( type & V_275 ) {
V_250 = V_235 -> V_147 -> V_211 * sizeof( struct V_277 ) ;
V_250 += sizeof( T_3 ) ;
V_76 += V_250 ;
}
if ( type & V_278 ) {
if ( V_235 -> V_279 . V_280 ) {
V_76 += sizeof( T_3 ) ;
V_250 = F_102 ( V_235 -> V_279 . V_9 ) * sizeof( T_3 ) ;
V_76 += V_250 ;
} else {
V_76 += sizeof( T_3 ) ;
}
}
if ( type & V_282 ) {
V_250 = V_235 -> V_283 . V_6 ;
V_76 += sizeof( T_3 ) ;
if ( V_250 ) {
V_76 += V_250 ;
V_76 += sizeof( T_3 ) ;
}
}
if ( type & V_284 )
V_76 += sizeof( T_3 ) ;
if ( type & V_287 )
V_76 += sizeof( T_3 ) ;
if ( type & V_289 )
V_76 += sizeof( T_3 ) ;
return V_76 ;
}
int F_104 ( union V_232 * V_233 , T_3 type ,
T_3 V_30 ,
const struct V_234 * V_235 ,
bool V_237 )
{
T_3 * V_236 ;
T_2 V_250 ;
union V_239 V_240 ;
V_236 = V_233 -> V_235 . V_236 ;
if ( type & V_13 ) {
* V_236 = V_235 -> V_46 ;
V_236 ++ ;
}
if ( type & V_15 ) {
* V_236 = V_235 -> V_254 ;
V_236 ++ ;
}
if ( type & V_16 ) {
V_240 . V_243 [ 0 ] = V_235 -> V_206 ;
V_240 . V_243 [ 1 ] = V_235 -> V_245 ;
if ( V_237 ) {
V_240 . V_243 [ 0 ] = F_96 ( V_240 . V_243 [ 0 ] ) ;
V_240 . V_243 [ 1 ] = F_96 ( V_240 . V_243 [ 1 ] ) ;
V_240 . V_242 = F_95 ( V_240 . V_242 ) ;
}
* V_236 = V_240 . V_242 ;
V_236 ++ ;
}
if ( type & V_17 ) {
* V_236 = V_235 -> time ;
V_236 ++ ;
}
if ( type & V_18 ) {
* V_236 = V_235 -> V_67 ;
V_236 ++ ;
}
if ( type & V_14 ) {
* V_236 = V_235 -> V_46 ;
V_236 ++ ;
}
if ( type & V_20 ) {
* V_236 = V_235 -> V_244 ;
V_236 ++ ;
}
if ( type & V_19 ) {
V_240 . V_243 [ 0 ] = V_235 -> V_163 ;
if ( V_237 ) {
V_240 . V_243 [ 0 ] = F_96 ( V_240 . V_243 [ 0 ] ) ;
V_240 . V_242 = F_95 ( V_240 . V_242 ) ;
}
* V_236 = V_240 . V_242 ;
V_236 ++ ;
}
if ( type & V_42 ) {
* V_236 = V_235 -> V_139 ;
V_236 ++ ;
}
if ( type & V_255 ) {
if ( V_30 & V_122 )
* V_236 = V_235 -> V_256 . V_257 . V_211 ;
else
* V_236 = V_235 -> V_256 . V_258 . V_259 ;
V_236 ++ ;
if ( V_30 & V_260 ) {
* V_236 = V_235 -> V_256 . V_261 ;
V_236 ++ ;
}
if ( V_30 & V_262 ) {
* V_236 = V_235 -> V_256 . V_263 ;
V_236 ++ ;
}
if ( V_30 & V_122 ) {
V_250 = V_235 -> V_256 . V_257 . V_211 *
sizeof( struct V_266 ) ;
memcpy ( V_236 , V_235 -> V_256 . V_257 . V_267 , V_250 ) ;
V_236 = ( void * ) V_236 + V_250 ;
} else {
* V_236 = V_235 -> V_256 . V_258 . V_46 ;
V_236 ++ ;
}
}
if ( type & V_268 ) {
V_250 = ( V_235 -> V_270 -> V_211 + 1 ) * sizeof( T_3 ) ;
memcpy ( V_236 , V_235 -> V_270 , V_250 ) ;
V_236 = ( void * ) V_236 + V_250 ;
}
if ( type & V_41 ) {
V_240 . V_243 [ 0 ] = V_235 -> V_272 ;
if ( F_101 ( V_237 ,
L_36 ) ) {
V_240 . V_243 [ 0 ] = F_96 ( V_240 . V_243 [ 0 ] ) ;
V_240 . V_243 [ 1 ] = F_96 ( V_240 . V_243 [ 1 ] ) ;
V_240 . V_242 = F_95 ( V_240 . V_242 ) ;
}
* V_236 = V_240 . V_242 ;
V_236 = ( void * ) V_236 + sizeof( V_273 ) ;
memcpy ( V_236 , V_235 -> V_274 , V_235 -> V_272 ) ;
V_236 = ( void * ) V_236 + V_235 -> V_272 ;
}
if ( type & V_275 ) {
V_250 = V_235 -> V_147 -> V_211 * sizeof( struct V_277 ) ;
V_250 += sizeof( T_3 ) ;
memcpy ( V_236 , V_235 -> V_147 , V_250 ) ;
V_236 = ( void * ) V_236 + V_250 ;
}
if ( type & V_278 ) {
if ( V_235 -> V_279 . V_280 ) {
* V_236 ++ = V_235 -> V_279 . V_280 ;
V_250 = F_102 ( V_235 -> V_279 . V_9 ) * sizeof( T_3 ) ;
memcpy ( V_236 , V_235 -> V_279 . V_281 , V_250 ) ;
V_236 = ( void * ) V_236 + V_250 ;
} else {
* V_236 ++ = 0 ;
}
}
if ( type & V_282 ) {
V_250 = V_235 -> V_283 . V_6 ;
* V_236 ++ = V_250 ;
if ( V_250 ) {
memcpy ( V_236 , V_235 -> V_283 . V_249 , V_250 ) ;
V_236 = ( void * ) V_236 + V_250 ;
* V_236 ++ = V_250 ;
}
}
if ( type & V_284 ) {
* V_236 = V_235 -> V_251 ;
V_236 ++ ;
}
if ( type & V_287 ) {
* V_236 = V_235 -> V_285 ;
V_236 ++ ;
}
if ( type & V_289 ) {
* V_236 = V_235 -> V_288 ;
V_236 ++ ;
}
return 0 ;
}
struct V_291 * F_105 ( struct V_1 * T_1 , const char * V_39 )
{
return F_106 ( T_1 -> V_44 , V_39 ) ;
}
void * F_107 ( struct V_1 * T_1 , struct V_234 * V_235 ,
const char * V_39 )
{
struct V_291 * V_292 = F_105 ( T_1 , V_39 ) ;
int V_248 ;
if ( ! V_292 )
return NULL ;
V_248 = V_292 -> V_248 ;
if ( V_292 -> V_204 & V_293 ) {
V_248 = * ( int * ) ( V_235 -> V_274 + V_292 -> V_248 ) ;
V_248 &= 0xffff ;
}
return V_235 -> V_274 + V_248 ;
}
T_3 F_108 ( struct V_1 * T_1 , struct V_234 * V_235 ,
const char * V_39 )
{
struct V_291 * V_292 = F_105 ( T_1 , V_39 ) ;
void * V_294 ;
T_3 V_259 ;
if ( ! V_292 )
return 0 ;
V_294 = V_235 -> V_274 + V_292 -> V_248 ;
switch ( V_292 -> V_6 ) {
case 1 :
return * ( T_6 * ) V_294 ;
case 2 :
V_259 = * ( T_8 * ) V_294 ;
break;
case 4 :
V_259 = * ( V_273 * ) V_294 ;
break;
case 8 :
V_259 = * ( T_3 * ) V_294 ;
break;
default:
return 0 ;
}
if ( ! T_1 -> V_238 )
return V_259 ;
switch ( V_292 -> V_6 ) {
case 2 :
return F_109 ( V_259 ) ;
case 4 :
return F_96 ( V_259 ) ;
case 8 :
return F_95 ( V_259 ) ;
default:
return 0 ;
}
return 0 ;
}
static int F_110 ( T_7 * V_188 , bool * V_295 , const char * V_296 , ... )
{
T_9 args ;
int V_85 = 0 ;
if ( ! * V_295 ) {
V_85 += fprintf ( V_188 , L_38 ) ;
} else {
V_85 += fprintf ( V_188 , L_9 ) ;
* V_295 = false ;
}
va_start ( args , V_296 ) ;
V_85 += vfprintf ( V_188 , V_296 , args ) ;
va_end ( args ) ;
return V_85 ;
}
static int F_111 ( T_7 * V_188 , bool * V_295 , const char * V_292 , T_3 V_259 )
{
if ( V_259 == 0 )
return 0 ;
return F_110 ( V_188 , V_295 , L_39 V_297 , V_292 , V_259 ) ;
}
static int F_112 ( T_7 * V_188 , const char * V_292 , T_3 V_259 ,
struct V_298 * V_299 , bool * V_295 )
{
int V_11 = 0 , V_300 = F_110 ( V_188 , V_295 , L_40 , V_292 ) ;
bool V_301 = true ;
do {
if ( V_259 & V_299 [ V_11 ] . V_25 ) {
V_300 += fprintf ( V_188 , L_41 , V_301 ? L_1 : L_42 , V_299 [ V_11 ] . V_39 ) ;
V_301 = false ;
}
} while ( V_299 [ ++ V_11 ] . V_39 != NULL );
return V_300 ;
}
static int F_113 ( T_7 * V_188 , bool * V_295 , T_3 V_259 )
{
#define F_114 ( T_10 ) { PERF_SAMPLE_##n, #n }
struct V_298 V_299 [] = {
F_114 ( V_117 ) , F_114 ( V_118 ) , F_114 ( TIME ) , F_114 ( V_134 ) ,
F_114 ( V_120 ) , F_114 ( V_95 ) , F_114 ( V_28 ) , F_114 ( V_138 ) ,
F_114 ( V_128 ) , F_114 ( V_302 ) , F_114 ( V_142 ) ,
F_114 ( V_148 ) , F_114 ( V_99 ) , F_114 ( V_100 ) ,
F_114 ( V_29 ) ,
{ . V_39 = NULL , }
} ;
#undef F_114
return F_112 ( V_188 , L_43 , V_259 , V_299 , V_295 ) ;
}
static int F_115 ( T_7 * V_188 , bool * V_295 , T_3 V_259 )
{
#define F_114 ( T_10 ) { PERF_FORMAT_##n, #n }
struct V_298 V_299 [] = {
F_114 ( V_303 ) , F_114 ( V_304 ) ,
F_114 ( V_28 ) , F_114 ( V_305 ) ,
{ . V_39 = NULL , }
} ;
#undef F_114
return F_112 ( V_188 , L_44 , V_259 , V_299 , V_295 ) ;
}
int F_116 ( struct V_1 * T_1 ,
struct V_306 * V_307 , T_7 * V_188 )
{
bool V_295 = true ;
int V_300 = 0 ;
if ( V_307 -> V_308 ) {
struct V_1 * V_93 ;
if ( ! F_49 ( T_1 ) )
return 0 ;
if ( T_1 -> V_121 > 1 )
V_300 += fprintf ( V_188 , L_45 , T_1 -> V_91 ? : L_1 ) ;
V_300 += fprintf ( V_188 , L_6 , F_39 ( T_1 ) ) ;
F_43 (pos, evsel)
V_300 += fprintf ( V_188 , L_46 , F_39 ( V_93 ) ) ;
if ( T_1 -> V_121 > 1 )
V_300 += fprintf ( V_188 , L_47 ) ;
goto V_309;
}
V_300 += fprintf ( V_188 , L_6 , F_39 ( T_1 ) ) ;
if ( V_307 -> V_216 || V_307 -> V_127 ) {
V_300 += F_110 ( V_188 , & V_295 , L_48 V_297 ,
( T_3 ) T_1 -> V_22 . V_129 ) ;
}
if ( V_307 -> V_216 ) {
F_117 ( type ) ;
F_117 ( V_45 ) ;
F_117 ( V_197 ) ;
F_117 ( V_199 ) ;
F_117 ( V_6 ) ;
V_300 += F_113 ( V_188 , & V_295 , T_1 -> V_22 . V_8 ) ;
if ( T_1 -> V_22 . V_30 )
V_300 += F_115 ( V_188 , & V_295 , T_1 -> V_22 . V_30 ) ;
F_117 ( V_157 ) ;
F_117 ( V_115 ) ;
F_117 ( V_190 ) ;
F_117 ( V_191 ) ;
F_117 ( V_55 ) ;
F_117 ( V_54 ) ;
F_117 ( V_56 ) ;
F_117 ( V_192 ) ;
F_117 ( V_152 ) ;
F_117 ( V_153 ) ;
F_117 ( V_154 ) ;
F_117 ( V_193 ) ;
F_117 ( V_127 ) ;
F_117 ( V_132 ) ;
F_117 ( V_159 ) ;
F_117 ( V_194 ) ;
F_117 ( V_145 ) ;
F_117 ( V_60 ) ;
F_117 ( V_135 ) ;
F_117 ( V_113 ) ;
F_117 ( V_61 ) ;
F_117 ( V_62 ) ;
F_117 ( V_310 ) ;
F_117 ( V_146 ) ;
F_117 ( V_73 ) ;
F_117 ( V_149 ) ;
}
V_309:
fputc ( '\n' , V_188 ) ;
return ++ V_300 ;
}
bool F_118 ( struct V_1 * T_1 , int V_80 ,
char * V_311 , T_2 V_312 )
{
if ( ( V_80 == V_313 || V_80 == V_314 || V_80 == V_315 ) &&
T_1 -> V_22 . type == V_87 &&
T_1 -> V_22 . V_45 == V_316 ) {
F_27 ( V_311 , V_312 , L_6 ,
L_49 ) ;
T_1 -> V_22 . type = V_89 ;
T_1 -> V_22 . V_45 = V_317 ;
F_23 ( & T_1 -> V_39 ) ;
return true ;
}
return false ;
}
int F_119 ( struct V_1 * T_1 , struct V_110 * V_110 ,
int V_80 , char * V_311 , T_2 V_6 )
{
char V_318 [ V_319 ] ;
switch ( V_80 ) {
case V_320 :
case V_321 :
return F_27 ( V_311 , V_6 ,
L_50
L_51
L_52
L_53
L_54
L_55 ,
V_110 -> V_165 ? L_56 : L_1 ) ;
case V_313 :
return F_27 ( V_311 , V_6 , L_57 ,
F_39 ( T_1 ) ) ;
case V_222 :
return F_27 ( V_311 , V_6 , L_6 ,
L_58
L_59 ) ;
case V_315 :
if ( V_110 -> V_322 )
return F_27 ( V_311 , V_6 , L_6 ,
L_60 ) ;
break;
case V_323 :
if ( T_1 -> V_22 . V_60 )
return F_27 ( V_311 , V_6 , L_6 ,
L_61 ) ;
#if F_120 ( V_324 ) || F_120 ( V_325 )
if ( T_1 -> V_22 . type == V_87 )
return F_27 ( V_311 , V_6 , L_6 ,
L_62
L_63 ) ;
#endif
break;
case V_326 :
if ( F_121 ( L_64 ) )
return F_27 ( V_311 , V_6 ,
L_65
L_66 ) ;
break;
default:
break;
}
return F_27 ( V_311 , V_6 ,
L_67
L_68
L_69 ,
V_80 , F_122 ( V_80 , V_318 , sizeof( V_318 ) ) ,
F_39 ( T_1 ) ) ;
}
