int F_1 ( T_1 V_1 )
{
T_1 V_2 = V_1 & V_3 ;
int V_4 = 0 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < 64 ; V_5 ++ ) {
if ( V_2 & ( 1ULL << V_5 ) )
V_4 ++ ;
}
V_4 *= sizeof( T_1 ) ;
return V_4 ;
}
static int F_2 ( T_1 V_1 )
{
int V_6 = 0 ;
if ( V_1 & V_7 )
return 0 ;
if ( ! ( V_1 & V_8 ) )
return - 1 ;
if ( V_1 & V_9 )
V_6 += 1 ;
if ( V_1 & V_10 )
V_6 += 1 ;
if ( V_1 & V_11 )
V_6 += 1 ;
if ( V_1 & V_12 )
V_6 += 1 ;
return V_6 ;
}
static int F_3 ( T_1 V_1 )
{
int V_6 = 1 ;
if ( V_1 & V_7 )
return 1 ;
if ( ! ( V_1 & V_8 ) )
return - 1 ;
if ( V_1 & V_13 )
V_6 += 1 ;
if ( V_1 & V_14 )
V_6 += 1 ;
return V_6 ;
}
void F_4 ( struct V_15 * V_16 )
{
V_16 -> V_17 = F_2 ( V_16 -> V_18 . V_1 ) ;
V_16 -> V_19 = F_3 ( V_16 -> V_18 . V_1 ) ;
}
void F_5 ( struct V_20 * V_20 )
{
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
V_20 -> V_21 [ 0 ] = V_20 -> V_21 [ 1 ] = V_22 ;
V_20 -> V_23 = & V_20 -> V_21 [ 0 ] ;
V_20 -> V_24 = V_22 ;
V_20 -> V_25 = V_22 ;
F_6 ( & V_20 -> V_26 , NULL ) ;
}
void F_7 ( struct V_15 * V_16 ,
enum V_27 V_28 )
{
if ( ! ( V_16 -> V_18 . V_1 & V_28 ) ) {
V_16 -> V_18 . V_1 |= V_28 ;
V_16 -> V_29 += sizeof( T_1 ) ;
F_4 ( V_16 ) ;
}
}
void F_8 ( struct V_15 * V_16 ,
enum V_27 V_28 )
{
if ( V_16 -> V_18 . V_1 & V_28 ) {
V_16 -> V_18 . V_1 &= ~ V_28 ;
V_16 -> V_29 -= sizeof( T_1 ) ;
F_4 ( V_16 ) ;
}
}
void F_9 ( struct V_15 * V_16 ,
bool V_30 )
{
if ( V_30 ) {
F_10 ( V_16 , V_31 ) ;
F_11 ( V_16 , V_32 ) ;
} else {
F_11 ( V_16 , V_31 ) ;
}
V_16 -> V_18 . V_33 |= V_34 ;
}
void F_12 ( struct V_15 * V_16 ,
struct V_35 * V_18 , int V_6 )
{
V_16 -> V_6 = V_6 ;
V_16 -> V_18 = * V_18 ;
V_16 -> V_36 = V_16 ;
F_13 ( & V_16 -> V_37 ) ;
F_5 ( & V_16 -> V_20 ) ;
V_16 -> V_29 = F_1 ( V_18 -> V_1 ) ;
F_4 ( V_16 ) ;
}
struct V_15 * F_14 ( struct V_35 * V_18 , int V_6 )
{
struct V_15 * V_16 = F_15 ( sizeof( * V_16 ) ) ;
if ( V_16 != NULL )
F_12 ( V_16 , V_18 , V_6 ) ;
return V_16 ;
}
struct V_38 * F_16 ( const char * V_39 , const char * V_40 )
{
int V_41 , V_42 ;
char * V_43 ;
void * V_44 = NULL , * V_45 ;
T_2 V_4 = 0 , V_46 = 0 ;
struct V_38 * V_47 = NULL ;
if ( F_17 ( & V_43 , L_1 , V_48 , V_39 , V_40 ) < 0 )
goto V_49;
V_41 = F_18 ( V_43 , V_50 ) ;
if ( V_41 < 0 )
goto V_51;
do {
if ( V_4 == V_46 ) {
V_46 += V_52 ;
V_45 = realloc ( V_44 , V_46 ) ;
if ( V_45 == NULL )
goto V_53;
V_44 = V_45 ;
}
V_42 = F_19 ( V_41 , V_44 + V_4 , V_46 - V_4 ) ;
if ( V_42 < 0 )
goto V_53;
V_4 += V_42 ;
} while ( V_42 > 0 );
F_20 ( & V_47 , V_44 , V_4 , V_39 ) ;
V_53:
free ( V_44 ) ;
F_21 ( V_41 ) ;
V_51:
free ( V_43 ) ;
V_49:
return V_47 ;
}
struct V_15 * F_22 ( const char * V_39 , const char * V_40 , int V_6 )
{
struct V_15 * V_16 = F_15 ( sizeof( * V_16 ) ) ;
if ( V_16 != NULL ) {
struct V_35 V_18 = {
. type = V_54 ,
. V_1 = ( V_55 | V_11 |
V_13 | V_56 ) ,
} ;
if ( F_17 ( & V_16 -> V_40 , L_2 , V_39 , V_40 ) < 0 )
goto V_57;
V_16 -> V_58 = F_16 ( V_39 , V_40 ) ;
if ( V_16 -> V_58 == NULL )
goto V_57;
F_23 ( & V_18 ) ;
V_18 . V_59 = V_16 -> V_58 -> V_60 ;
V_18 . V_61 = 1 ;
F_12 ( V_16 , & V_18 , V_6 ) ;
}
return V_16 ;
V_57:
free ( V_16 -> V_40 ) ;
free ( V_16 ) ;
return NULL ;
}
static const char * F_24 ( T_1 V_59 )
{
if ( V_59 < V_62 && V_63 [ V_59 ] )
return V_63 [ V_59 ] ;
return L_3 ;
}
static int F_25 ( struct V_15 * V_16 , char * V_44 , T_2 V_4 )
{
int V_64 = 0 , V_65 = 0 ;
struct V_35 * V_18 = & V_16 -> V_18 ;
bool V_66 = false ;
#define F_26 ( T_3 , T_4 ) do { \
if (!attr->exclude_##context) { \
if (!colon) colon = ++r; \
r += scnprintf(bf + r, size - r, "%c", mod); \
} } while(0)
if ( V_18 -> V_67 || V_18 -> V_68 || V_18 -> V_69 ) {
F_26 ( V_70 , 'k' ) ;
F_26 ( V_71 , 'u' ) ;
F_26 ( V_72 , 'h' ) ;
V_66 = true ;
}
if ( V_18 -> V_73 ) {
if ( ! V_64 )
V_64 = ++ V_65 ;
V_65 += F_27 ( V_44 + V_65 , V_4 - V_65 , L_4 , V_18 -> V_73 , L_5 ) ;
V_66 = true ;
}
if ( V_18 -> V_74 || V_18 -> V_75 == V_66 ) {
F_26 ( V_76 , 'H' ) ;
F_26 ( V_77 , 'G' ) ;
}
#undef F_26
if ( V_64 )
V_44 [ V_64 - 1 ] = ':' ;
return V_65 ;
}
static int F_28 ( struct V_15 * V_16 , char * V_44 , T_2 V_4 )
{
int V_65 = F_27 ( V_44 , V_4 , L_6 , F_24 ( V_16 -> V_18 . V_59 ) ) ;
return V_65 + F_25 ( V_16 , V_44 + V_65 , V_4 - V_65 ) ;
}
static const char * F_29 ( T_1 V_59 )
{
if ( V_59 < V_78 && V_79 [ V_59 ] )
return V_79 [ V_59 ] ;
return L_7 ;
}
static int F_30 ( struct V_15 * V_16 , char * V_44 , T_2 V_4 )
{
int V_65 = F_27 ( V_44 , V_4 , L_6 , F_29 ( V_16 -> V_18 . V_59 ) ) ;
return V_65 + F_25 ( V_16 , V_44 + V_65 , V_4 - V_65 ) ;
}
static int F_31 ( char * V_44 , T_2 V_4 , T_1 V_80 , T_1 type )
{
int V_65 ;
V_65 = F_27 ( V_44 , V_4 , L_8 V_81 L_9 , V_80 ) ;
if ( type & V_82 )
V_65 += F_27 ( V_44 + V_65 , V_4 - V_65 , L_10 ) ;
if ( type & V_83 )
V_65 += F_27 ( V_44 + V_65 , V_4 - V_65 , L_11 ) ;
if ( type & V_84 )
V_65 += F_27 ( V_44 + V_65 , V_4 - V_65 , L_12 ) ;
return V_65 ;
}
static int F_32 ( struct V_15 * V_16 , char * V_44 , T_2 V_4 )
{
struct V_35 * V_18 = & V_16 -> V_18 ;
int V_65 = F_31 ( V_44 , V_4 , V_18 -> V_85 , V_18 -> V_86 ) ;
return V_65 + F_25 ( V_16 , V_44 + V_65 , V_4 - V_65 ) ;
}
bool F_33 ( T_5 type , T_5 V_87 )
{
if ( V_88 [ type ] & F_34 ( V_87 ) )
return true ;
else
return false ;
}
int F_35 ( T_5 type , T_5 V_87 , T_5 V_89 ,
char * V_44 , T_2 V_4 )
{
if ( V_89 ) {
return F_27 ( V_44 , V_4 , L_13 , V_90 [ type ] [ 0 ] ,
V_91 [ V_87 ] [ 0 ] ,
V_92 [ V_89 ] [ 0 ] ) ;
}
return F_27 ( V_44 , V_4 , L_14 , V_90 [ type ] [ 0 ] ,
V_91 [ V_87 ] [ 1 ] ) ;
}
static int F_36 ( T_1 V_59 , char * V_44 , T_2 V_4 )
{
T_5 V_87 , V_89 , type = ( V_59 >> 0 ) & 0xff ;
const char * V_93 = L_15 ;
if ( type > V_94 )
goto V_95;
V_87 = ( V_59 >> 8 ) & 0xff ;
V_93 = L_16 ;
if ( V_87 > V_96 )
goto V_95;
V_89 = ( V_59 >> 16 ) & 0xff ;
V_93 = L_17 ;
if ( V_89 > V_97 )
goto V_95;
V_93 = L_18 ;
if ( ! F_33 ( type , V_87 ) )
goto V_95;
return F_35 ( type , V_87 , V_89 , V_44 , V_4 ) ;
V_95:
return F_27 ( V_44 , V_4 , L_6 , V_93 ) ;
}
static int F_37 ( struct V_15 * V_16 , char * V_44 , T_2 V_4 )
{
int V_98 = F_36 ( V_16 -> V_18 . V_59 , V_44 , V_4 ) ;
return V_98 + F_25 ( V_16 , V_44 + V_98 , V_4 - V_98 ) ;
}
static int F_38 ( struct V_15 * V_16 , char * V_44 , T_2 V_4 )
{
int V_98 = F_27 ( V_44 , V_4 , L_19 V_81 , V_16 -> V_18 . V_59 ) ;
return V_98 + F_25 ( V_16 , V_44 + V_98 , V_4 - V_98 ) ;
}
const char * F_39 ( struct V_15 * V_16 )
{
char V_44 [ 128 ] ;
if ( V_16 -> V_40 )
return V_16 -> V_40 ;
switch ( V_16 -> V_18 . type ) {
case V_99 :
F_38 ( V_16 , V_44 , sizeof( V_44 ) ) ;
break;
case V_100 :
F_28 ( V_16 , V_44 , sizeof( V_44 ) ) ;
break;
case V_101 :
F_37 ( V_16 , V_44 , sizeof( V_44 ) ) ;
break;
case V_102 :
F_30 ( V_16 , V_44 , sizeof( V_44 ) ) ;
break;
case V_54 :
F_27 ( V_44 , sizeof( V_44 ) , L_6 , L_20 ) ;
break;
case V_103 :
F_32 ( V_16 , V_44 , sizeof( V_44 ) ) ;
break;
default:
F_27 ( V_44 , sizeof( V_44 ) , L_21 ,
V_16 -> V_18 . type ) ;
break;
}
V_16 -> V_40 = F_40 ( V_44 ) ;
return V_16 -> V_40 ? : L_22 ;
}
const char * F_41 ( struct V_15 * V_16 )
{
return V_16 -> V_104 ? : L_23 ;
}
int F_42 ( struct V_15 * V_16 , char * V_105 , T_2 V_4 )
{
int V_98 ;
struct V_15 * V_106 ;
const char * V_104 = F_41 ( V_16 ) ;
V_98 = F_27 ( V_105 , V_4 , L_6 , V_104 ) ;
V_98 += F_27 ( V_105 + V_98 , V_4 - V_98 , L_24 ,
F_39 ( V_16 ) ) ;
F_43 (pos, evsel)
V_98 += F_27 ( V_105 + V_98 , V_4 - V_98 , L_25 ,
F_39 ( V_106 ) ) ;
V_98 += F_27 ( V_105 + V_98 , V_4 - V_98 , L_26 ) ;
return V_98 ;
}
void F_44 ( struct V_15 * V_16 ,
struct V_107 * V_108 )
{
struct V_15 * V_36 = V_16 -> V_36 ;
struct V_35 * V_18 = & V_16 -> V_18 ;
int V_109 = ! V_16 -> V_6 ;
V_18 -> V_110 = V_111 . V_110 ? 0 : 1 ;
V_18 -> V_112 = ! V_108 -> V_113 ;
F_11 ( V_16 , V_114 ) ;
F_11 ( V_16 , V_115 ) ;
if ( V_16 -> V_116 ) {
F_11 ( V_16 , V_117 ) ;
F_9 ( V_16 , false ) ;
if ( V_36 -> V_118 > 1 ) {
V_18 -> V_33 |= V_119 ;
V_18 -> V_112 = 0 ;
}
}
if ( ! V_18 -> V_61 || ( V_108 -> V_120 != V_121 &&
V_108 -> V_122 != V_123 ) ) {
if ( V_108 -> V_124 ) {
F_11 ( V_16 , V_125 ) ;
V_18 -> V_124 = 1 ;
V_18 -> V_126 = V_108 -> V_124 ;
} else {
V_18 -> V_61 = V_108 -> V_127 ;
}
}
if ( ( V_36 != V_16 ) && V_36 -> V_116 ) {
V_18 -> V_126 = 0 ;
V_18 -> V_61 = 0 ;
}
if ( V_108 -> V_128 )
V_18 -> V_126 = 0 ;
if ( V_108 -> V_129 )
V_18 -> V_129 = 1 ;
if ( V_108 -> V_130 ) {
F_11 ( V_16 , V_131 ) ;
V_18 -> V_132 = V_109 ;
}
if ( V_108 -> V_133 ) {
F_11 ( V_16 , V_134 ) ;
if ( V_108 -> V_133 == V_135 ) {
F_11 ( V_16 , V_136 ) ;
F_11 ( V_16 , V_137 ) ;
V_18 -> V_138 = V_139 ;
V_18 -> V_140 = V_108 -> V_141 ;
V_18 -> V_142 = 1 ;
}
}
if ( F_45 ( & V_108 -> V_143 ) )
F_11 ( V_16 , V_144 ) ;
if ( V_108 -> V_145 )
F_11 ( V_16 , V_125 ) ;
if ( ! V_111 . V_110 &&
( V_108 -> V_146 || ! V_108 -> V_113 ||
F_45 ( & V_108 -> V_143 ) ) )
F_11 ( V_16 , TIME ) ;
if ( V_108 -> V_147 ) {
F_11 ( V_16 , TIME ) ;
F_11 ( V_16 , V_148 ) ;
F_11 ( V_16 , V_144 ) ;
}
if ( V_108 -> V_130 )
V_18 -> V_1 |= V_149 ;
if ( V_108 -> V_150 ) {
V_18 -> V_151 = 0 ;
V_18 -> V_152 = 1 ;
}
if ( V_108 -> V_153 ) {
F_11 ( V_16 , V_154 ) ;
V_18 -> V_155 = V_108 -> V_153 ;
}
if ( V_108 -> V_156 )
V_18 -> V_1 |= V_157 ;
V_18 -> V_158 = V_109 ;
V_18 -> V_159 = V_109 ;
if ( F_46 ( V_16 ) )
V_18 -> V_160 = 1 ;
if ( F_47 ( & V_108 -> V_143 ) && F_46 ( V_16 ) )
V_18 -> V_161 = 1 ;
}
int F_48 ( struct V_15 * V_16 , int V_162 , int V_163 )
{
int V_164 , V_165 ;
V_16 -> V_41 = F_49 ( V_162 , V_163 , sizeof( int ) ) ;
if ( V_16 -> V_41 ) {
for ( V_164 = 0 ; V_164 < V_162 ; V_164 ++ ) {
for ( V_165 = 0 ; V_165 < V_163 ; V_165 ++ ) {
F_50 ( V_16 , V_164 , V_165 ) = - 1 ;
}
}
}
return V_16 -> V_41 != NULL ? 0 : - V_166 ;
}
static int F_51 ( struct V_15 * V_16 , int V_162 , int V_163 ,
int V_167 , void * V_168 )
{
int V_164 , V_165 ;
for ( V_164 = 0 ; V_164 < V_162 ; V_164 ++ ) {
for ( V_165 = 0 ; V_165 < V_163 ; V_165 ++ ) {
int V_41 = F_50 ( V_16 , V_164 , V_165 ) ,
V_93 = F_52 ( V_41 , V_167 , V_168 ) ;
if ( V_93 )
return V_93 ;
}
}
return 0 ;
}
int F_53 ( struct V_15 * V_16 , int V_162 , int V_163 ,
const char * V_169 )
{
return F_51 ( V_16 , V_162 , V_163 ,
V_170 ,
( void * ) V_169 ) ;
}
int F_54 ( struct V_15 * V_16 , int V_162 , int V_163 )
{
return F_51 ( V_16 , V_162 , V_163 ,
V_171 ,
0 ) ;
}
int F_55 ( struct V_15 * V_16 , int V_162 , int V_163 )
{
V_16 -> V_172 = F_49 ( V_162 , V_163 , sizeof( struct V_173 ) ) ;
if ( V_16 -> V_172 == NULL )
return - V_166 ;
V_16 -> V_60 = F_15 ( V_162 * V_163 * sizeof( T_1 ) ) ;
if ( V_16 -> V_60 == NULL ) {
F_56 ( V_16 -> V_172 ) ;
V_16 -> V_172 = NULL ;
return - V_166 ;
}
return 0 ;
}
void F_57 ( struct V_15 * V_16 , int V_162 )
{
memset ( V_16 -> V_174 , 0 , ( sizeof( * V_16 -> V_174 ) +
( V_162 * sizeof( struct V_175 ) ) ) ) ;
}
int F_58 ( struct V_15 * V_16 , int V_162 )
{
V_16 -> V_174 = F_15 ( ( sizeof( * V_16 -> V_174 ) +
( V_162 * sizeof( struct V_175 ) ) ) ) ;
return V_16 -> V_174 != NULL ? 0 : - V_166 ;
}
void F_59 ( struct V_15 * V_16 )
{
F_56 ( V_16 -> V_41 ) ;
V_16 -> V_41 = NULL ;
}
void F_60 ( struct V_15 * V_16 )
{
F_56 ( V_16 -> V_172 ) ;
V_16 -> V_172 = NULL ;
free ( V_16 -> V_60 ) ;
V_16 -> V_60 = NULL ;
}
void F_61 ( struct V_15 * V_16 , int V_162 , int V_163 )
{
int V_164 , V_165 ;
for ( V_164 = 0 ; V_164 < V_162 ; V_164 ++ )
for ( V_165 = 0 ; V_165 < V_163 ; ++ V_165 ) {
F_21 ( F_50 ( V_16 , V_164 , V_165 ) ) ;
F_50 ( V_16 , V_164 , V_165 ) = - 1 ;
}
}
void F_62 ( struct V_15 * V_16 )
{
free ( V_16 -> V_174 ) ;
}
void F_63 ( struct V_15 * V_16 )
{
assert ( F_64 ( & V_16 -> V_37 ) ) ;
F_59 ( V_16 ) ;
F_60 ( V_16 ) ;
}
void F_65 ( struct V_15 * V_16 )
{
F_63 ( V_16 ) ;
F_66 ( V_16 -> V_176 ) ;
free ( V_16 -> V_104 ) ;
if ( V_16 -> V_58 )
F_67 ( V_16 -> V_58 ) ;
free ( V_16 -> V_40 ) ;
free ( V_16 ) ;
}
static inline void F_68 ( struct V_15 * V_16 ,
int V_164 ,
struct V_175 * V_177 )
{
struct V_175 V_178 ;
if ( ! V_16 -> V_179 )
return;
if ( V_164 == - 1 ) {
V_178 = V_16 -> V_179 -> V_180 ;
V_16 -> V_179 -> V_180 = * V_177 ;
} else {
V_178 = V_16 -> V_179 -> V_164 [ V_164 ] ;
V_16 -> V_179 -> V_164 [ V_164 ] = * V_177 ;
}
V_177 -> V_181 = V_177 -> V_181 - V_178 . V_181 ;
V_177 -> V_182 = V_177 -> V_182 - V_178 . V_182 ;
V_177 -> V_183 = V_177 -> V_183 - V_178 . V_183 ;
}
int F_69 ( struct V_15 * V_16 ,
int V_164 , int V_165 , bool V_184 )
{
struct V_175 V_177 ;
T_2 V_185 = V_184 ? 3 : 1 ;
if ( F_50 ( V_16 , V_164 , V_165 ) < 0 )
return - V_186 ;
if ( V_16 -> V_174 == NULL && F_58 ( V_16 , V_164 + 1 ) < 0 )
return - V_166 ;
if ( F_70 ( F_50 ( V_16 , V_164 , V_165 ) , & V_177 , V_185 * sizeof( T_1 ) ) < 0 )
return - V_187 ;
F_68 ( V_16 , V_164 , & V_177 ) ;
if ( V_184 ) {
if ( V_177 . V_183 == 0 )
V_177 . V_181 = 0 ;
else if ( V_177 . V_183 < V_177 . V_182 )
V_177 . V_181 = ( T_1 ) ( ( double ) V_177 . V_181 * V_177 . V_182 / V_177 . V_183 + 0.5 ) ;
} else
V_177 . V_182 = V_177 . V_183 = 0 ;
V_16 -> V_174 -> V_164 [ V_164 ] = V_177 ;
return 0 ;
}
int F_71 ( struct V_15 * V_16 ,
int V_162 , int V_163 , bool V_184 )
{
T_2 V_185 = V_184 ? 3 : 1 ;
int V_164 , V_165 ;
struct V_175 * V_180 = & V_16 -> V_174 -> V_180 , V_177 ;
V_180 -> V_181 = V_180 -> V_182 = V_180 -> V_183 = 0 ;
for ( V_164 = 0 ; V_164 < V_162 ; V_164 ++ ) {
for ( V_165 = 0 ; V_165 < V_163 ; V_165 ++ ) {
if ( F_50 ( V_16 , V_164 , V_165 ) < 0 )
continue;
if ( F_70 ( F_50 ( V_16 , V_164 , V_165 ) ,
& V_177 , V_185 * sizeof( T_1 ) ) < 0 )
return - V_187 ;
V_180 -> V_181 += V_177 . V_181 ;
if ( V_184 ) {
V_180 -> V_182 += V_177 . V_182 ;
V_180 -> V_183 += V_177 . V_183 ;
}
}
}
F_68 ( V_16 , - 1 , V_180 ) ;
V_16 -> V_174 -> V_188 = 0 ;
if ( V_184 ) {
if ( V_180 -> V_183 == 0 ) {
V_16 -> V_174 -> V_188 = - 1 ;
V_180 -> V_181 = 0 ;
return 0 ;
}
if ( V_180 -> V_183 < V_180 -> V_182 ) {
V_16 -> V_174 -> V_188 = 1 ;
V_180 -> V_181 = ( T_1 ) ( ( double ) V_180 -> V_181 * V_180 -> V_182 / V_180 -> V_183 + 0.5 ) ;
}
} else
V_180 -> V_182 = V_180 -> V_183 = 0 ;
return 0 ;
}
static int F_72 ( struct V_15 * V_16 , int V_164 , int V_165 )
{
struct V_15 * V_36 = V_16 -> V_36 ;
int V_41 ;
if ( F_46 ( V_16 ) )
return - 1 ;
F_73 ( ! V_36 -> V_41 ) ;
V_41 = F_50 ( V_36 , V_164 , V_165 ) ;
F_73 ( V_41 == - 1 ) ;
return V_41 ;
}
static T_2 F_74 ( struct V_35 * V_18 , T_6 * V_189 )
{
T_2 V_98 = 0 ;
V_98 += fprintf ( V_189 , L_27 , V_190 ) ;
V_98 += fprintf ( V_189 , L_28 ) ;
V_98 += F_75 ( type ) ;
V_98 += F_75 ( V_4 ) ;
V_98 += F_76 ( V_59 ) ;
V_98 += F_77 ( V_61 ) ;
V_98 += F_77 ( V_126 ) ;
V_98 += F_76 ( V_1 ) ;
V_98 += F_76 ( V_33 ) ;
V_98 += F_78 ( V_160 , V_112 ) ;
V_98 += F_78 ( V_191 , V_192 ) ;
V_98 += F_78 ( V_68 , V_67 ) ;
V_98 += F_78 ( V_69 , V_193 ) ;
V_98 += F_78 ( V_158 , V_159 ) ;
V_98 += F_78 ( V_124 , V_129 ) ;
V_98 += F_78 ( V_161 , V_194 ) ;
V_98 += F_78 ( V_151 , V_73 ) ;
V_98 += F_78 ( V_132 , V_110 ) ;
V_98 += F_78 ( V_74 , V_75 ) ;
V_98 += F_79 ( L_29 , V_195 ,
L_30 , V_142 ) ;
V_98 += F_75 ( V_152 ) ;
V_98 += F_75 ( V_196 ) ;
V_98 += F_80 ( V_86 ) ;
V_98 += F_76 ( V_85 ) ;
V_98 += F_76 ( V_197 ) ;
V_98 += F_77 ( V_198 ) ;
V_98 += F_76 ( V_199 ) ;
V_98 += F_76 ( V_155 ) ;
V_98 += F_76 ( V_138 ) ;
V_98 += F_75 ( V_140 ) ;
V_98 += fprintf ( V_189 , L_27 , V_190 ) ;
return V_98 ;
}
static int F_81 ( struct V_15 * V_16 , struct V_200 * V_201 ,
struct V_202 * V_203 )
{
int V_164 , V_165 ;
unsigned long V_204 = 0 ;
int V_205 = - 1 , V_93 ;
enum { V_206 , V_207 , V_208 } V_209 = V_206 ;
if ( V_16 -> V_41 == NULL &&
F_48 ( V_16 , V_201 -> V_210 , V_203 -> V_210 ) < 0 )
return - V_166 ;
if ( V_16 -> V_176 ) {
V_204 = V_211 ;
V_205 = V_16 -> V_176 -> V_41 ;
}
V_212:
if ( V_111 . V_213 )
V_16 -> V_18 . V_213 = 0 ;
if ( V_111 . V_75 )
V_16 -> V_18 . V_75 = V_16 -> V_18 . V_74 = 0 ;
V_214:
if ( V_111 . V_110 )
V_16 -> V_18 . V_110 = 0 ;
if ( V_215 >= 2 )
F_74 ( & V_16 -> V_18 , V_216 ) ;
for ( V_164 = 0 ; V_164 < V_201 -> V_210 ; V_164 ++ ) {
for ( V_165 = 0 ; V_165 < V_203 -> V_210 ; V_165 ++ ) {
int V_217 ;
if ( ! V_16 -> V_176 )
V_205 = V_203 -> V_218 [ V_165 ] ;
V_217 = F_72 ( V_16 , V_164 , V_165 ) ;
V_219:
F_82 ( L_31 ,
V_205 , V_201 -> V_218 [ V_164 ] , V_217 , V_204 ) ;
F_50 ( V_16 , V_164 , V_165 ) = F_83 ( & V_16 -> V_18 ,
V_205 ,
V_201 -> V_218 [ V_164 ] ,
V_217 , V_204 ) ;
if ( F_50 ( V_16 , V_164 , V_165 ) < 0 ) {
V_93 = - V_187 ;
goto V_220;
}
V_209 = V_206 ;
}
}
return 0 ;
V_220:
if ( V_93 == - V_221 && V_209 < V_208 ) {
struct V_222 V_223 ;
int V_224 = V_187 ;
if ( F_84 ( V_225 , & V_223 ) == 0 ) {
if ( V_209 == V_206 )
V_223 . V_226 = V_223 . V_227 ;
else {
V_223 . V_226 = V_223 . V_227 + 1000 ;
V_223 . V_227 = V_223 . V_226 ;
}
if ( F_85 ( V_225 , & V_223 ) == 0 ) {
V_209 ++ ;
V_187 = V_224 ;
goto V_219;
}
}
V_187 = V_224 ;
}
if ( V_93 != - V_186 || V_164 > 0 || V_165 > 0 )
goto V_228;
if ( ! V_111 . V_213 && V_16 -> V_18 . V_213 ) {
V_111 . V_213 = true ;
goto V_212;
} else if ( ! V_111 . V_75 &&
( V_16 -> V_18 . V_75 || V_16 -> V_18 . V_74 ) ) {
V_111 . V_75 = true ;
goto V_212;
} else if ( ! V_111 . V_110 ) {
V_111 . V_110 = true ;
goto V_214;
}
V_228:
do {
while ( -- V_165 >= 0 ) {
F_21 ( F_50 ( V_16 , V_164 , V_165 ) ) ;
F_50 ( V_16 , V_164 , V_165 ) = - 1 ;
}
V_165 = V_203 -> V_210 ;
} while ( -- V_164 >= 0 );
return V_93 ;
}
void F_86 ( struct V_15 * V_16 , int V_162 , int V_163 )
{
if ( V_16 -> V_41 == NULL )
return;
F_61 ( V_16 , V_162 , V_163 ) ;
F_59 ( V_16 ) ;
V_16 -> V_41 = NULL ;
}
int F_87 ( struct V_15 * V_16 , struct V_200 * V_201 ,
struct V_202 * V_203 )
{
if ( V_201 == NULL ) {
V_201 = & V_229 . V_218 ;
}
if ( V_203 == NULL )
V_203 = & V_230 . V_218 ;
return F_81 ( V_16 , V_201 , V_203 ) ;
}
int F_88 ( struct V_15 * V_16 ,
struct V_200 * V_201 )
{
return F_81 ( V_16 , V_201 , & V_230 . V_218 ) ;
}
int F_89 ( struct V_15 * V_16 ,
struct V_202 * V_203 )
{
return F_81 ( V_16 , & V_229 . V_218 , V_203 ) ;
}
static int F_90 ( const struct V_15 * V_16 ,
const union V_231 * V_232 ,
struct V_233 * V_234 )
{
T_1 type = V_16 -> V_18 . V_1 ;
const T_1 * V_235 = V_232 -> V_234 . V_235 ;
bool V_236 = V_16 -> V_237 ;
union V_238 V_239 ;
V_235 += ( ( V_232 -> V_240 . V_4 -
sizeof( V_232 -> V_240 ) ) / sizeof( T_1 ) ) - 1 ;
if ( type & V_7 ) {
V_234 -> V_60 = * V_235 ;
V_235 -- ;
}
if ( type & V_13 ) {
V_239 . V_241 = * V_235 ;
if ( V_236 ) {
V_239 . V_241 = F_91 ( V_239 . V_241 ) ;
V_239 . V_242 [ 0 ] = F_92 ( V_239 . V_242 [ 0 ] ) ;
}
V_234 -> V_164 = V_239 . V_242 [ 0 ] ;
V_235 -- ;
}
if ( type & V_14 ) {
V_234 -> V_243 = * V_235 ;
V_235 -- ;
}
if ( type & V_8 ) {
V_234 -> V_60 = * V_235 ;
V_235 -- ;
}
if ( type & V_11 ) {
V_234 -> time = * V_235 ;
V_235 -- ;
}
if ( type & V_10 ) {
V_239 . V_241 = * V_235 ;
if ( V_236 ) {
V_239 . V_241 = F_91 ( V_239 . V_241 ) ;
V_239 . V_242 [ 0 ] = F_92 ( V_239 . V_242 [ 0 ] ) ;
V_239 . V_242 [ 1 ] = F_92 ( V_239 . V_242 [ 1 ] ) ;
}
V_234 -> V_205 = V_239 . V_242 [ 0 ] ;
V_234 -> V_244 = V_239 . V_242 [ 1 ] ;
}
return 0 ;
}
static inline bool F_93 ( const void * V_245 , T_7 V_246 , const void * V_247 ,
T_1 V_4 )
{
return V_4 > V_246 || V_247 + V_4 > V_245 ;
}
int F_94 ( struct V_15 * V_16 , union V_231 * V_232 ,
struct V_233 * V_248 )
{
T_1 type = V_16 -> V_18 . V_1 ;
bool V_236 = V_16 -> V_237 ;
const T_1 * V_235 ;
T_7 V_246 = V_232 -> V_240 . V_4 ;
const void * V_245 = ( void * ) V_232 + V_246 ;
T_1 V_249 ;
union V_238 V_239 ;
memset ( V_248 , 0 , sizeof( * V_248 ) ) ;
V_248 -> V_164 = V_248 -> V_205 = V_248 -> V_244 = - 1 ;
V_248 -> V_243 = V_248 -> V_60 = V_248 -> time = - 1ULL ;
V_248 -> V_145 = 1 ;
V_248 -> V_250 = 0 ;
if ( V_232 -> V_240 . type != V_251 ) {
if ( ! V_16 -> V_18 . V_110 )
return 0 ;
return F_90 ( V_16 , V_232 , V_248 ) ;
}
V_235 = V_232 -> V_234 . V_235 ;
if ( V_16 -> V_29 + sizeof( V_232 -> V_240 ) > V_232 -> V_240 . V_4 )
return - V_252 ;
V_248 -> V_60 = - 1ULL ;
if ( type & V_7 ) {
V_248 -> V_60 = * V_235 ;
V_235 ++ ;
}
if ( type & V_9 ) {
V_248 -> V_253 = * V_235 ;
V_235 ++ ;
}
if ( type & V_10 ) {
V_239 . V_241 = * V_235 ;
if ( V_236 ) {
V_239 . V_241 = F_91 ( V_239 . V_241 ) ;
V_239 . V_242 [ 0 ] = F_92 ( V_239 . V_242 [ 0 ] ) ;
V_239 . V_242 [ 1 ] = F_92 ( V_239 . V_242 [ 1 ] ) ;
}
V_248 -> V_205 = V_239 . V_242 [ 0 ] ;
V_248 -> V_244 = V_239 . V_242 [ 1 ] ;
V_235 ++ ;
}
if ( type & V_11 ) {
V_248 -> time = * V_235 ;
V_235 ++ ;
}
V_248 -> V_80 = 0 ;
if ( type & V_12 ) {
V_248 -> V_80 = * V_235 ;
V_235 ++ ;
}
if ( type & V_8 ) {
V_248 -> V_60 = * V_235 ;
V_235 ++ ;
}
if ( type & V_14 ) {
V_248 -> V_243 = * V_235 ;
V_235 ++ ;
}
if ( type & V_13 ) {
V_239 . V_241 = * V_235 ;
if ( V_236 ) {
V_239 . V_241 = F_91 ( V_239 . V_241 ) ;
V_239 . V_242 [ 0 ] = F_92 ( V_239 . V_242 [ 0 ] ) ;
}
V_248 -> V_164 = V_239 . V_242 [ 0 ] ;
V_235 ++ ;
}
if ( type & V_56 ) {
V_248 -> V_145 = * V_235 ;
V_235 ++ ;
}
if ( type & V_254 ) {
T_1 V_33 = V_16 -> V_18 . V_33 ;
F_95 ( V_235 ) ;
if ( V_33 & V_119 )
V_248 -> F_19 . V_255 . V_210 = * V_235 ;
else
V_248 -> F_19 . V_256 . V_257 = * V_235 ;
V_235 ++ ;
if ( V_33 & V_258 ) {
F_95 ( V_235 ) ;
V_248 -> F_19 . V_259 = * V_235 ;
V_235 ++ ;
}
if ( V_33 & V_260 ) {
F_95 ( V_235 ) ;
V_248 -> F_19 . V_261 = * V_235 ;
V_235 ++ ;
}
if ( V_33 & V_119 ) {
const T_1 V_262 = V_263 /
sizeof( struct V_264 ) ;
if ( V_248 -> F_19 . V_255 . V_210 > V_262 )
return - V_252 ;
V_249 = V_248 -> F_19 . V_255 . V_210 *
sizeof( struct V_264 ) ;
F_96 ( V_235 , V_249 , V_246 ) ;
V_248 -> F_19 . V_255 . V_265 =
(struct V_264 * ) V_235 ;
V_235 = ( void * ) V_235 + V_249 ;
} else {
F_95 ( V_235 ) ;
V_248 -> F_19 . V_256 . V_60 = * V_235 ;
V_235 ++ ;
}
}
if ( type & V_266 ) {
const T_1 V_267 = V_263 / sizeof( T_1 ) ;
F_95 ( V_235 ) ;
V_248 -> V_268 = (struct V_269 * ) V_235 ++ ;
if ( V_248 -> V_268 -> V_210 > V_267 )
return - V_252 ;
V_249 = V_248 -> V_268 -> V_210 * sizeof( T_1 ) ;
F_96 ( V_235 , V_249 , V_246 ) ;
V_235 = ( void * ) V_235 + V_249 ;
}
if ( type & V_55 ) {
F_95 ( V_235 ) ;
V_239 . V_241 = * V_235 ;
if ( F_97 ( V_236 ,
L_32 ) ) {
V_239 . V_241 = F_91 ( V_239 . V_241 ) ;
V_239 . V_242 [ 0 ] = F_92 ( V_239 . V_242 [ 0 ] ) ;
V_239 . V_242 [ 1 ] = F_92 ( V_239 . V_242 [ 1 ] ) ;
}
V_248 -> V_270 = V_239 . V_242 [ 0 ] ;
V_235 = ( void * ) V_235 + sizeof( V_271 ) ;
F_96 ( V_235 , V_248 -> V_270 , V_246 ) ;
V_248 -> V_272 = ( void * ) V_235 ;
V_235 = ( void * ) V_235 + V_248 -> V_270 ;
}
if ( type & V_273 ) {
const T_1 V_274 = V_263 /
sizeof( struct V_275 ) ;
F_95 ( V_235 ) ;
V_248 -> V_153 = (struct V_153 * ) V_235 ++ ;
if ( V_248 -> V_153 -> V_210 > V_274 )
return - V_252 ;
V_249 = V_248 -> V_153 -> V_210 * sizeof( struct V_275 ) ;
F_96 ( V_235 , V_249 , V_246 ) ;
V_235 = ( void * ) V_235 + V_249 ;
}
if ( type & V_276 ) {
F_95 ( V_235 ) ;
V_248 -> V_277 . V_278 = * V_235 ;
V_235 ++ ;
if ( V_248 -> V_277 . V_278 ) {
T_1 V_279 = V_16 -> V_18 . V_138 ;
V_249 = F_98 ( V_279 ) * sizeof( T_1 ) ;
F_96 ( V_235 , V_249 , V_246 ) ;
V_248 -> V_277 . V_280 = ( T_1 * ) V_235 ;
V_235 = ( void * ) V_235 + V_249 ;
}
}
if ( type & V_281 ) {
F_95 ( V_235 ) ;
V_249 = * V_235 ++ ;
V_248 -> V_282 . V_247 = ( ( char * ) ( V_235 - 1 )
- ( char * ) V_232 ) ;
if ( ! V_249 ) {
V_248 -> V_282 . V_4 = 0 ;
} else {
F_96 ( V_235 , V_249 , V_246 ) ;
V_248 -> V_282 . V_248 = ( char * ) V_235 ;
V_235 = ( void * ) V_235 + V_249 ;
F_95 ( V_235 ) ;
V_248 -> V_282 . V_4 = * V_235 ++ ;
}
}
V_248 -> V_250 = 0 ;
if ( type & V_157 ) {
F_95 ( V_235 ) ;
V_248 -> V_250 = * V_235 ;
V_235 ++ ;
}
V_248 -> V_283 = V_284 ;
if ( type & V_149 ) {
F_95 ( V_235 ) ;
V_248 -> V_283 = * V_235 ;
V_235 ++ ;
}
return 0 ;
}
T_2 F_99 ( const struct V_233 * V_234 , T_1 type ,
T_1 V_138 , T_1 V_33 )
{
T_2 V_249 , V_89 = sizeof( struct V_285 ) ;
if ( type & V_7 )
V_89 += sizeof( T_1 ) ;
if ( type & V_9 )
V_89 += sizeof( T_1 ) ;
if ( type & V_10 )
V_89 += sizeof( T_1 ) ;
if ( type & V_11 )
V_89 += sizeof( T_1 ) ;
if ( type & V_12 )
V_89 += sizeof( T_1 ) ;
if ( type & V_8 )
V_89 += sizeof( T_1 ) ;
if ( type & V_14 )
V_89 += sizeof( T_1 ) ;
if ( type & V_13 )
V_89 += sizeof( T_1 ) ;
if ( type & V_56 )
V_89 += sizeof( T_1 ) ;
if ( type & V_254 ) {
V_89 += sizeof( T_1 ) ;
if ( V_33 & V_258 )
V_89 += sizeof( T_1 ) ;
if ( V_33 & V_260 )
V_89 += sizeof( T_1 ) ;
if ( V_33 & V_119 ) {
V_249 = V_234 -> F_19 . V_255 . V_210 *
sizeof( struct V_264 ) ;
V_89 += V_249 ;
} else {
V_89 += sizeof( T_1 ) ;
}
}
if ( type & V_266 ) {
V_249 = ( V_234 -> V_268 -> V_210 + 1 ) * sizeof( T_1 ) ;
V_89 += V_249 ;
}
if ( type & V_55 ) {
V_89 += sizeof( V_271 ) ;
V_89 += V_234 -> V_270 ;
}
if ( type & V_273 ) {
V_249 = V_234 -> V_153 -> V_210 * sizeof( struct V_275 ) ;
V_249 += sizeof( T_1 ) ;
V_89 += V_249 ;
}
if ( type & V_276 ) {
if ( V_234 -> V_277 . V_278 ) {
V_89 += sizeof( T_1 ) ;
V_249 = F_98 ( V_138 ) * sizeof( T_1 ) ;
V_89 += V_249 ;
} else {
V_89 += sizeof( T_1 ) ;
}
}
if ( type & V_281 ) {
V_249 = V_234 -> V_282 . V_4 ;
V_89 += sizeof( T_1 ) ;
if ( V_249 ) {
V_89 += V_249 ;
V_89 += sizeof( T_1 ) ;
}
}
if ( type & V_157 )
V_89 += sizeof( T_1 ) ;
if ( type & V_149 )
V_89 += sizeof( T_1 ) ;
return V_89 ;
}
int F_100 ( union V_231 * V_232 , T_1 type ,
T_1 V_138 , T_1 V_33 ,
const struct V_233 * V_234 ,
bool V_236 )
{
T_1 * V_235 ;
T_2 V_249 ;
union V_238 V_239 ;
V_235 = V_232 -> V_234 . V_235 ;
if ( type & V_7 ) {
* V_235 = V_234 -> V_60 ;
V_235 ++ ;
}
if ( type & V_9 ) {
* V_235 = V_234 -> V_253 ;
V_235 ++ ;
}
if ( type & V_10 ) {
V_239 . V_242 [ 0 ] = V_234 -> V_205 ;
V_239 . V_242 [ 1 ] = V_234 -> V_244 ;
if ( V_236 ) {
V_239 . V_242 [ 0 ] = F_92 ( V_239 . V_242 [ 0 ] ) ;
V_239 . V_242 [ 1 ] = F_92 ( V_239 . V_242 [ 1 ] ) ;
V_239 . V_241 = F_91 ( V_239 . V_241 ) ;
}
* V_235 = V_239 . V_241 ;
V_235 ++ ;
}
if ( type & V_11 ) {
* V_235 = V_234 -> time ;
V_235 ++ ;
}
if ( type & V_12 ) {
* V_235 = V_234 -> V_80 ;
V_235 ++ ;
}
if ( type & V_8 ) {
* V_235 = V_234 -> V_60 ;
V_235 ++ ;
}
if ( type & V_14 ) {
* V_235 = V_234 -> V_243 ;
V_235 ++ ;
}
if ( type & V_13 ) {
V_239 . V_242 [ 0 ] = V_234 -> V_164 ;
if ( V_236 ) {
V_239 . V_242 [ 0 ] = F_92 ( V_239 . V_242 [ 0 ] ) ;
V_239 . V_241 = F_91 ( V_239 . V_241 ) ;
}
* V_235 = V_239 . V_241 ;
V_235 ++ ;
}
if ( type & V_56 ) {
* V_235 = V_234 -> V_145 ;
V_235 ++ ;
}
if ( type & V_254 ) {
if ( V_33 & V_119 )
* V_235 = V_234 -> F_19 . V_255 . V_210 ;
else
* V_235 = V_234 -> F_19 . V_256 . V_257 ;
V_235 ++ ;
if ( V_33 & V_258 ) {
* V_235 = V_234 -> F_19 . V_259 ;
V_235 ++ ;
}
if ( V_33 & V_260 ) {
* V_235 = V_234 -> F_19 . V_261 ;
V_235 ++ ;
}
if ( V_33 & V_119 ) {
V_249 = V_234 -> F_19 . V_255 . V_210 *
sizeof( struct V_264 ) ;
memcpy ( V_235 , V_234 -> F_19 . V_255 . V_265 , V_249 ) ;
V_235 = ( void * ) V_235 + V_249 ;
} else {
* V_235 = V_234 -> F_19 . V_256 . V_60 ;
V_235 ++ ;
}
}
if ( type & V_266 ) {
V_249 = ( V_234 -> V_268 -> V_210 + 1 ) * sizeof( T_1 ) ;
memcpy ( V_235 , V_234 -> V_268 , V_249 ) ;
V_235 = ( void * ) V_235 + V_249 ;
}
if ( type & V_55 ) {
V_239 . V_242 [ 0 ] = V_234 -> V_270 ;
if ( F_97 ( V_236 ,
L_32 ) ) {
V_239 . V_242 [ 0 ] = F_92 ( V_239 . V_242 [ 0 ] ) ;
V_239 . V_242 [ 1 ] = F_92 ( V_239 . V_242 [ 1 ] ) ;
V_239 . V_241 = F_91 ( V_239 . V_241 ) ;
}
* V_235 = V_239 . V_241 ;
V_235 = ( void * ) V_235 + sizeof( V_271 ) ;
memcpy ( V_235 , V_234 -> V_272 , V_234 -> V_270 ) ;
V_235 = ( void * ) V_235 + V_234 -> V_270 ;
}
if ( type & V_273 ) {
V_249 = V_234 -> V_153 -> V_210 * sizeof( struct V_275 ) ;
V_249 += sizeof( T_1 ) ;
memcpy ( V_235 , V_234 -> V_153 , V_249 ) ;
V_235 = ( void * ) V_235 + V_249 ;
}
if ( type & V_276 ) {
if ( V_234 -> V_277 . V_278 ) {
* V_235 ++ = V_234 -> V_277 . V_278 ;
V_249 = F_98 ( V_138 ) * sizeof( T_1 ) ;
memcpy ( V_235 , V_234 -> V_277 . V_280 , V_249 ) ;
V_235 = ( void * ) V_235 + V_249 ;
} else {
* V_235 ++ = 0 ;
}
}
if ( type & V_281 ) {
V_249 = V_234 -> V_282 . V_4 ;
* V_235 ++ = V_249 ;
if ( V_249 ) {
memcpy ( V_235 , V_234 -> V_282 . V_248 , V_249 ) ;
V_235 = ( void * ) V_235 + V_249 ;
* V_235 ++ = V_249 ;
}
}
if ( type & V_157 ) {
* V_235 = V_234 -> V_250 ;
V_235 ++ ;
}
if ( type & V_149 ) {
* V_235 = V_234 -> V_283 ;
V_235 ++ ;
}
return 0 ;
}
struct V_286 * F_101 ( struct V_15 * V_16 , const char * V_40 )
{
return F_102 ( V_16 -> V_58 , V_40 ) ;
}
void * F_103 ( struct V_15 * V_16 , struct V_233 * V_234 ,
const char * V_40 )
{
struct V_286 * V_287 = F_101 ( V_16 , V_40 ) ;
int V_247 ;
if ( ! V_287 )
return NULL ;
V_247 = V_287 -> V_247 ;
if ( V_287 -> V_204 & V_288 ) {
V_247 = * ( int * ) ( V_234 -> V_272 + V_287 -> V_247 ) ;
V_247 &= 0xffff ;
}
return V_234 -> V_272 + V_247 ;
}
T_1 F_104 ( struct V_15 * V_16 , struct V_233 * V_234 ,
const char * V_40 )
{
struct V_286 * V_287 = F_101 ( V_16 , V_40 ) ;
void * V_289 ;
T_1 V_257 ;
if ( ! V_287 )
return 0 ;
V_289 = V_234 -> V_272 + V_287 -> V_247 ;
switch ( V_287 -> V_4 ) {
case 1 :
return * ( T_5 * ) V_289 ;
case 2 :
V_257 = * ( T_7 * ) V_289 ;
break;
case 4 :
V_257 = * ( V_271 * ) V_289 ;
break;
case 8 :
V_257 = * ( T_1 * ) V_289 ;
break;
default:
return 0 ;
}
if ( ! V_16 -> V_237 )
return V_257 ;
switch ( V_287 -> V_4 ) {
case 2 :
return F_105 ( V_257 ) ;
case 4 :
return F_92 ( V_257 ) ;
case 8 :
return F_91 ( V_257 ) ;
default:
return 0 ;
}
return 0 ;
}
static int F_106 ( T_6 * V_189 , bool * V_290 , const char * V_291 , ... )
{
T_8 args ;
int V_98 = 0 ;
if ( ! * V_290 ) {
V_98 += fprintf ( V_189 , L_33 ) ;
} else {
V_98 += fprintf ( V_189 , L_9 ) ;
* V_290 = false ;
}
va_start ( args , V_291 ) ;
V_98 += vfprintf ( V_189 , V_291 , args ) ;
va_end ( args ) ;
return V_98 ;
}
static int F_107 ( T_6 * V_189 , bool * V_290 , const char * V_287 , T_1 V_257 )
{
if ( V_257 == 0 )
return 0 ;
return F_106 ( V_189 , V_290 , L_34 V_292 , V_287 , V_257 ) ;
}
static int F_108 ( T_6 * V_189 , const char * V_287 , T_1 V_257 ,
struct V_293 * V_294 , bool * V_290 )
{
int V_5 = 0 , V_295 = F_106 ( V_189 , V_290 , L_35 , V_287 ) ;
bool V_296 = true ;
do {
if ( V_257 & V_294 [ V_5 ] . V_28 ) {
V_295 += fprintf ( V_189 , L_36 , V_296 ? L_37 : L_38 , V_294 [ V_5 ] . V_40 ) ;
V_296 = false ;
}
} while ( V_294 [ ++ V_5 ] . V_40 != NULL );
return V_295 ;
}
static int F_109 ( T_6 * V_189 , bool * V_290 , T_1 V_257 )
{
#define F_110 ( V_42 ) { PERF_SAMPLE_##n, #n }
struct V_293 V_294 [] = {
F_110 ( V_114 ) , F_110 ( V_115 ) , F_110 ( TIME ) , F_110 ( V_131 ) ,
F_110 ( V_117 ) , F_110 ( V_134 ) , F_110 ( V_31 ) , F_110 ( V_144 ) ,
F_110 ( V_125 ) , F_110 ( V_297 ) , F_110 ( V_148 ) ,
F_110 ( V_154 ) , F_110 ( V_136 ) , F_110 ( V_137 ) ,
F_110 ( V_32 ) ,
{ . V_40 = NULL , }
} ;
#undef F_110
return F_108 ( V_189 , L_39 , V_257 , V_294 , V_290 ) ;
}
static int F_111 ( T_6 * V_189 , bool * V_290 , T_1 V_257 )
{
#define F_110 ( V_42 ) { PERF_FORMAT_##n, #n }
struct V_293 V_294 [] = {
F_110 ( V_298 ) , F_110 ( V_299 ) ,
F_110 ( V_31 ) , F_110 ( V_300 ) ,
{ . V_40 = NULL , }
} ;
#undef F_110
return F_108 ( V_189 , L_40 , V_257 , V_294 , V_290 ) ;
}
int F_112 ( struct V_15 * V_16 ,
struct V_301 * V_302 , T_6 * V_189 )
{
bool V_290 = true ;
int V_295 = 0 ;
if ( V_302 -> V_303 ) {
struct V_15 * V_106 ;
if ( ! F_46 ( V_16 ) )
return 0 ;
if ( V_16 -> V_118 > 1 )
V_295 += fprintf ( V_189 , L_41 , V_16 -> V_104 ? : L_37 ) ;
V_295 += fprintf ( V_189 , L_6 , F_39 ( V_16 ) ) ;
F_43 (pos, evsel)
V_295 += fprintf ( V_189 , L_42 , F_39 ( V_106 ) ) ;
if ( V_16 -> V_118 > 1 )
V_295 += fprintf ( V_189 , L_43 ) ;
goto V_49;
}
V_295 += fprintf ( V_189 , L_6 , F_39 ( V_16 ) ) ;
if ( V_302 -> V_215 || V_302 -> V_124 ) {
V_295 += F_106 ( V_189 , & V_290 , L_44 V_292 ,
( T_1 ) V_16 -> V_18 . V_126 ) ;
}
if ( V_302 -> V_215 ) {
F_113 ( type ) ;
F_113 ( V_59 ) ;
F_113 ( V_197 ) ;
F_113 ( V_199 ) ;
F_113 ( V_4 ) ;
V_295 += F_109 ( V_189 , & V_290 , V_16 -> V_18 . V_1 ) ;
if ( V_16 -> V_18 . V_33 )
V_295 += F_111 ( V_189 , & V_290 , V_16 -> V_18 . V_33 ) ;
F_113 ( V_160 ) ;
F_113 ( V_112 ) ;
F_113 ( V_191 ) ;
F_113 ( V_192 ) ;
F_113 ( V_68 ) ;
F_113 ( V_67 ) ;
F_113 ( V_69 ) ;
F_113 ( V_193 ) ;
F_113 ( V_158 ) ;
F_113 ( V_213 ) ;
F_113 ( V_159 ) ;
F_113 ( V_124 ) ;
F_113 ( V_129 ) ;
F_113 ( V_161 ) ;
F_113 ( V_194 ) ;
F_113 ( V_151 ) ;
F_113 ( V_73 ) ;
F_113 ( V_132 ) ;
F_113 ( V_110 ) ;
F_113 ( V_74 ) ;
F_113 ( V_75 ) ;
F_113 ( V_304 ) ;
F_113 ( V_152 ) ;
F_113 ( V_86 ) ;
F_113 ( V_155 ) ;
}
V_49:
fputc ( '\n' , V_189 ) ;
return ++ V_295 ;
}
bool F_114 ( struct V_15 * V_16 , int V_93 ,
char * V_305 , T_2 V_306 )
{
if ( ( V_93 == V_307 || V_93 == V_308 || V_93 == V_309 ) &&
V_16 -> V_18 . type == V_100 &&
V_16 -> V_18 . V_59 == V_310 ) {
F_27 ( V_305 , V_306 , L_6 ,
L_45 ) ;
V_16 -> V_18 . type = V_102 ;
V_16 -> V_18 . V_59 = V_311 ;
free ( V_16 -> V_40 ) ;
V_16 -> V_40 = NULL ;
return true ;
}
return false ;
}
int F_115 ( struct V_15 * V_16 ,
struct V_312 * V_143 ,
int V_93 , char * V_305 , T_2 V_4 )
{
switch ( V_93 ) {
case V_313 :
case V_314 :
return F_27 ( V_305 , V_4 ,
L_46
L_47
L_48
L_49
L_50
L_51 ,
V_143 -> V_315 ? L_52 : L_37 ) ;
case V_307 :
return F_27 ( V_305 , V_4 , L_53 ,
F_39 ( V_16 ) ) ;
case V_221 :
return F_27 ( V_305 , V_4 , L_6 ,
L_54
L_55 ) ;
case V_309 :
if ( V_143 -> V_316 )
return F_27 ( V_305 , V_4 , L_6 ,
L_56 ) ;
break;
case V_317 :
if ( V_16 -> V_18 . V_73 )
return F_27 ( V_305 , V_4 , L_6 ,
L_57 ) ;
#if F_116 ( V_318 ) || F_116 ( V_319 )
if ( V_16 -> V_18 . type == V_100 )
return F_27 ( V_305 , V_4 , L_6 ,
L_58
L_59 ) ;
#endif
break;
default:
break;
}
return F_27 ( V_305 , V_4 ,
L_60
L_61
L_62 ,
V_93 , strerror ( V_93 ) , F_39 ( V_16 ) ) ;
}
