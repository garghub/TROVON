static int F_1 ( T_1 V_1 )
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
void F_2 ( struct V_6 * V_6 )
{
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_7 [ 0 ] = V_6 -> V_7 [ 1 ] = V_8 ;
V_6 -> V_9 = & V_6 -> V_7 [ 0 ] ;
V_6 -> V_10 = V_8 ;
V_6 -> V_11 = V_8 ;
F_3 ( & V_6 -> V_12 , NULL ) ;
}
void F_4 ( struct V_13 * V_14 ,
struct V_15 * V_16 , int V_17 )
{
V_14 -> V_17 = V_17 ;
V_14 -> V_16 = * V_16 ;
F_5 ( & V_14 -> V_18 ) ;
F_2 ( & V_14 -> V_6 ) ;
V_14 -> V_19 = F_1 ( V_16 -> V_1 ) ;
}
struct V_13 * F_6 ( struct V_15 * V_16 , int V_17 )
{
struct V_13 * V_14 = F_7 ( sizeof( * V_14 ) ) ;
if ( V_14 != NULL )
F_4 ( V_14 , V_16 , V_17 ) ;
return V_14 ;
}
struct V_20 * F_8 ( const char * V_21 , const char * V_22 )
{
int V_23 , V_24 ;
char * V_25 ;
void * V_26 = NULL , * V_27 ;
T_2 V_4 = 0 , V_28 = 0 ;
struct V_20 * V_29 = NULL ;
if ( F_9 ( & V_25 , L_1 , V_30 , V_21 , V_22 ) < 0 )
goto V_31;
V_23 = F_10 ( V_25 , V_32 ) ;
if ( V_23 < 0 )
goto V_33;
do {
if ( V_4 == V_28 ) {
V_28 += V_34 ;
V_27 = realloc ( V_26 , V_28 ) ;
if ( V_27 == NULL )
goto V_35;
V_26 = V_27 ;
}
V_24 = F_11 ( V_23 , V_26 + V_4 , V_34 ) ;
if ( V_24 < 0 )
goto V_35;
V_4 += V_24 ;
} while ( V_24 > 0 );
F_12 ( & V_29 , V_26 , V_4 , V_21 ) ;
V_35:
free ( V_26 ) ;
F_13 ( V_23 ) ;
V_33:
free ( V_25 ) ;
V_31:
return V_29 ;
}
struct V_13 * F_14 ( const char * V_21 , const char * V_22 , int V_17 )
{
struct V_13 * V_14 = F_7 ( sizeof( * V_14 ) ) ;
if ( V_14 != NULL ) {
struct V_15 V_16 = {
. type = V_36 ,
. V_1 = ( V_37 | V_38 |
V_39 | V_40 ) ,
} ;
if ( F_9 ( & V_14 -> V_22 , L_2 , V_21 , V_22 ) < 0 )
goto V_41;
V_14 -> V_42 = F_8 ( V_21 , V_22 ) ;
if ( V_14 -> V_42 == NULL )
goto V_41;
F_15 ( & V_16 ) ;
V_16 . V_43 = V_14 -> V_42 -> V_44 ;
V_16 . V_45 = 1 ;
F_4 ( V_14 , & V_16 , V_17 ) ;
}
return V_14 ;
V_41:
free ( V_14 -> V_22 ) ;
free ( V_14 ) ;
return NULL ;
}
static const char * F_16 ( T_1 V_43 )
{
if ( V_43 < V_46 && V_47 [ V_43 ] )
return V_47 [ V_43 ] ;
return L_3 ;
}
static int F_17 ( struct V_13 * V_14 , char * V_26 , T_2 V_4 )
{
int V_48 = 0 , V_49 = 0 ;
struct V_15 * V_16 = & V_14 -> V_16 ;
bool V_50 = false ;
#define F_18 ( T_3 , T_4 ) do { \
if (!attr->exclude_##context) { \
if (!colon) colon = ++r; \
r += scnprintf(bf + r, size - r, "%c", mod); \
} } while(0)
if ( V_16 -> V_51 || V_16 -> V_52 || V_16 -> V_53 ) {
F_18 ( V_54 , 'k' ) ;
F_18 ( V_55 , 'u' ) ;
F_18 ( V_56 , 'h' ) ;
V_50 = true ;
}
if ( V_16 -> V_57 ) {
if ( ! V_48 )
V_48 = ++ V_49 ;
V_49 += F_19 ( V_26 + V_49 , V_4 - V_49 , L_4 , V_16 -> V_57 , L_5 ) ;
V_50 = true ;
}
if ( V_16 -> V_58 || V_16 -> V_59 == V_50 ) {
F_18 ( V_60 , 'H' ) ;
F_18 ( V_61 , 'G' ) ;
}
#undef F_18
if ( V_48 )
V_26 [ V_48 - 1 ] = ':' ;
return V_49 ;
}
static int F_20 ( struct V_13 * V_14 , char * V_26 , T_2 V_4 )
{
int V_49 = F_19 ( V_26 , V_4 , L_6 , F_16 ( V_14 -> V_16 . V_43 ) ) ;
return V_49 + F_17 ( V_14 , V_26 + V_49 , V_4 - V_49 ) ;
}
static const char * F_21 ( T_1 V_43 )
{
if ( V_43 < V_62 && V_63 [ V_43 ] )
return V_63 [ V_43 ] ;
return L_7 ;
}
static int F_22 ( struct V_13 * V_14 , char * V_26 , T_2 V_4 )
{
int V_49 = F_19 ( V_26 , V_4 , L_6 , F_21 ( V_14 -> V_16 . V_43 ) ) ;
return V_49 + F_17 ( V_14 , V_26 + V_49 , V_4 - V_49 ) ;
}
static int F_23 ( char * V_26 , T_2 V_4 , T_1 V_64 , T_1 type )
{
int V_49 ;
V_49 = F_19 ( V_26 , V_4 , L_8 V_65 L_9 , V_64 ) ;
if ( type & V_66 )
V_49 += F_19 ( V_26 + V_49 , V_4 - V_49 , L_10 ) ;
if ( type & V_67 )
V_49 += F_19 ( V_26 + V_49 , V_4 - V_49 , L_11 ) ;
if ( type & V_68 )
V_49 += F_19 ( V_26 + V_49 , V_4 - V_49 , L_12 ) ;
return V_49 ;
}
static int F_24 ( struct V_13 * V_14 , char * V_26 , T_2 V_4 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
int V_49 = F_23 ( V_26 , V_4 , V_16 -> V_69 , V_16 -> V_70 ) ;
return V_49 + F_17 ( V_14 , V_26 + V_49 , V_4 - V_49 ) ;
}
bool F_25 ( T_5 type , T_5 V_71 )
{
if ( V_72 [ type ] & F_26 ( V_71 ) )
return true ;
else
return false ;
}
int F_27 ( T_5 type , T_5 V_71 , T_5 V_73 ,
char * V_26 , T_2 V_4 )
{
if ( V_73 ) {
return F_19 ( V_26 , V_4 , L_13 , V_74 [ type ] [ 0 ] ,
V_75 [ V_71 ] [ 0 ] ,
V_76 [ V_73 ] [ 0 ] ) ;
}
return F_19 ( V_26 , V_4 , L_14 , V_74 [ type ] [ 0 ] ,
V_75 [ V_71 ] [ 1 ] ) ;
}
static int F_28 ( T_1 V_43 , char * V_26 , T_2 V_4 )
{
T_5 V_71 , V_73 , type = ( V_43 >> 0 ) & 0xff ;
const char * V_77 = L_15 ;
if ( type > V_78 )
goto V_79;
V_71 = ( V_43 >> 8 ) & 0xff ;
V_77 = L_16 ;
if ( V_71 > V_80 )
goto V_79;
V_73 = ( V_43 >> 16 ) & 0xff ;
V_77 = L_17 ;
if ( V_73 > V_81 )
goto V_79;
V_77 = L_18 ;
if ( ! F_25 ( type , V_71 ) )
goto V_79;
return F_27 ( type , V_71 , V_73 , V_26 , V_4 ) ;
V_79:
return F_19 ( V_26 , V_4 , L_6 , V_77 ) ;
}
static int F_29 ( struct V_13 * V_14 , char * V_26 , T_2 V_4 )
{
int V_82 = F_28 ( V_14 -> V_16 . V_43 , V_26 , V_4 ) ;
return V_82 + F_17 ( V_14 , V_26 + V_82 , V_4 - V_82 ) ;
}
static int F_30 ( struct V_13 * V_14 , char * V_26 , T_2 V_4 )
{
int V_82 = F_19 ( V_26 , V_4 , L_19 V_65 , V_14 -> V_16 . V_43 ) ;
return V_82 + F_17 ( V_14 , V_26 + V_82 , V_4 - V_82 ) ;
}
const char * F_31 ( struct V_13 * V_14 )
{
char V_26 [ 128 ] ;
if ( V_14 -> V_22 )
return V_14 -> V_22 ;
switch ( V_14 -> V_16 . type ) {
case V_83 :
F_30 ( V_14 , V_26 , sizeof( V_26 ) ) ;
break;
case V_84 :
F_20 ( V_14 , V_26 , sizeof( V_26 ) ) ;
break;
case V_85 :
F_29 ( V_14 , V_26 , sizeof( V_26 ) ) ;
break;
case V_86 :
F_22 ( V_14 , V_26 , sizeof( V_26 ) ) ;
break;
case V_36 :
F_19 ( V_26 , sizeof( V_26 ) , L_6 , L_20 ) ;
break;
case V_87 :
F_24 ( V_14 , V_26 , sizeof( V_26 ) ) ;
break;
default:
F_19 ( V_26 , sizeof( V_26 ) , L_21 ,
V_14 -> V_16 . type ) ;
break;
}
V_14 -> V_22 = F_32 ( V_26 ) ;
return V_14 -> V_22 ? : L_22 ;
}
void F_33 ( struct V_13 * V_14 ,
struct V_88 * V_89 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
int V_90 = ! V_14 -> V_17 ;
V_16 -> V_91 = V_89 -> V_92 ? 0 : 1 ;
V_16 -> V_93 = ! V_89 -> V_94 ;
V_16 -> V_95 = V_96 |
V_97 |
V_98 ;
V_16 -> V_1 |= V_99 | V_100 ;
if ( ! V_16 -> V_45 || ( V_89 -> V_101 != V_102 &&
V_89 -> V_103 != V_104 ) ) {
if ( V_89 -> V_105 ) {
V_16 -> V_1 |= V_40 ;
V_16 -> V_105 = 1 ;
V_16 -> V_106 = V_89 -> V_105 ;
} else {
V_16 -> V_45 = V_89 -> V_107 ;
}
}
if ( V_89 -> V_108 )
V_16 -> V_106 = 0 ;
if ( V_89 -> V_109 )
V_16 -> V_109 = 1 ;
if ( V_89 -> V_110 ) {
V_16 -> V_1 |= V_111 ;
V_16 -> V_112 = V_90 ;
}
if ( V_89 -> V_113 ) {
V_16 -> V_1 |= V_114 ;
if ( V_89 -> V_113 == V_115 ) {
V_16 -> V_1 |= V_116 |
V_117 ;
V_16 -> V_118 = V_119 ;
V_16 -> V_120 = V_89 -> V_121 ;
V_16 -> V_122 = 1 ;
}
}
if ( F_34 ( & V_89 -> V_123 ) )
V_16 -> V_1 |= V_39 ;
if ( V_89 -> V_124 )
V_16 -> V_1 |= V_40 ;
if ( ! V_89 -> V_92 &&
( V_89 -> V_125 || ! V_89 -> V_94 ||
F_34 ( & V_89 -> V_123 ) ) )
V_16 -> V_1 |= V_38 ;
if ( V_89 -> V_126 ) {
V_16 -> V_1 |= V_38 ;
V_16 -> V_1 |= V_37 ;
V_16 -> V_1 |= V_39 ;
}
if ( V_89 -> V_127 ) {
V_16 -> V_128 = 0 ;
V_16 -> V_129 = 1 ;
}
if ( V_89 -> V_130 ) {
V_16 -> V_1 |= V_131 ;
V_16 -> V_132 = V_89 -> V_130 ;
}
V_16 -> V_133 = V_90 ;
V_16 -> V_134 = V_90 ;
if ( ! F_35 ( V_14 ) )
V_16 -> V_135 = 1 ;
if ( F_36 ( & V_89 -> V_123 ) && ! F_35 ( V_14 ) )
V_16 -> V_136 = 1 ;
}
int F_37 ( struct V_13 * V_14 , int V_137 , int V_138 )
{
int V_139 , V_140 ;
V_14 -> V_23 = F_38 ( V_137 , V_138 , sizeof( int ) ) ;
if ( V_14 -> V_23 ) {
for ( V_139 = 0 ; V_139 < V_137 ; V_139 ++ ) {
for ( V_140 = 0 ; V_140 < V_138 ; V_140 ++ ) {
F_39 ( V_14 , V_139 , V_140 ) = - 1 ;
}
}
}
return V_14 -> V_23 != NULL ? 0 : - V_141 ;
}
int F_40 ( struct V_13 * V_14 , int V_137 , int V_138 ,
const char * V_142 )
{
int V_139 , V_140 ;
for ( V_139 = 0 ; V_139 < V_137 ; V_139 ++ ) {
for ( V_140 = 0 ; V_140 < V_138 ; V_140 ++ ) {
int V_23 = F_39 ( V_14 , V_139 , V_140 ) ,
V_77 = F_41 ( V_23 , V_143 , V_142 ) ;
if ( V_77 )
return V_77 ;
}
}
return 0 ;
}
int F_42 ( struct V_13 * V_14 , int V_137 , int V_138 )
{
V_14 -> V_144 = F_38 ( V_137 , V_138 , sizeof( struct V_145 ) ) ;
if ( V_14 -> V_144 == NULL )
return - V_141 ;
V_14 -> V_44 = F_7 ( V_137 * V_138 * sizeof( T_1 ) ) ;
if ( V_14 -> V_44 == NULL ) {
F_43 ( V_14 -> V_144 ) ;
V_14 -> V_144 = NULL ;
return - V_141 ;
}
return 0 ;
}
int F_44 ( struct V_13 * V_14 , int V_137 )
{
V_14 -> V_146 = F_7 ( ( sizeof( * V_14 -> V_146 ) +
( V_137 * sizeof( struct V_147 ) ) ) ) ;
return V_14 -> V_146 != NULL ? 0 : - V_141 ;
}
void F_45 ( struct V_13 * V_14 )
{
F_43 ( V_14 -> V_23 ) ;
V_14 -> V_23 = NULL ;
}
void F_46 ( struct V_13 * V_14 )
{
F_43 ( V_14 -> V_144 ) ;
V_14 -> V_144 = NULL ;
free ( V_14 -> V_44 ) ;
V_14 -> V_44 = NULL ;
}
void F_47 ( struct V_13 * V_14 , int V_137 , int V_138 )
{
int V_139 , V_140 ;
for ( V_139 = 0 ; V_139 < V_137 ; V_139 ++ )
for ( V_140 = 0 ; V_140 < V_138 ; ++ V_140 ) {
F_13 ( F_39 ( V_14 , V_139 , V_140 ) ) ;
F_39 ( V_14 , V_139 , V_140 ) = - 1 ;
}
}
void F_48 ( struct V_13 * V_14 )
{
assert ( F_49 ( & V_14 -> V_18 ) ) ;
F_43 ( V_14 -> V_23 ) ;
F_43 ( V_14 -> V_144 ) ;
free ( V_14 -> V_44 ) ;
}
void F_50 ( struct V_13 * V_14 )
{
F_48 ( V_14 ) ;
F_51 ( V_14 -> V_148 ) ;
free ( V_14 -> V_149 ) ;
if ( V_14 -> V_42 )
F_52 ( V_14 -> V_42 ) ;
free ( V_14 -> V_22 ) ;
free ( V_14 ) ;
}
int F_53 ( struct V_13 * V_14 ,
int V_139 , int V_140 , bool V_150 )
{
struct V_147 V_151 ;
T_2 V_152 = V_150 ? 3 : 1 ;
if ( F_39 ( V_14 , V_139 , V_140 ) < 0 )
return - V_153 ;
if ( V_14 -> V_146 == NULL && F_44 ( V_14 , V_139 + 1 ) < 0 )
return - V_141 ;
if ( F_54 ( F_39 ( V_14 , V_139 , V_140 ) , & V_151 , V_152 * sizeof( T_1 ) ) < 0 )
return - V_154 ;
if ( V_150 ) {
if ( V_151 . V_155 == 0 )
V_151 . V_156 = 0 ;
else if ( V_151 . V_155 < V_151 . V_157 )
V_151 . V_156 = ( T_1 ) ( ( double ) V_151 . V_156 * V_151 . V_157 / V_151 . V_155 + 0.5 ) ;
} else
V_151 . V_157 = V_151 . V_155 = 0 ;
V_14 -> V_146 -> V_139 [ V_139 ] = V_151 ;
return 0 ;
}
int F_55 ( struct V_13 * V_14 ,
int V_137 , int V_138 , bool V_150 )
{
T_2 V_152 = V_150 ? 3 : 1 ;
int V_139 , V_140 ;
struct V_147 * V_158 = & V_14 -> V_146 -> V_158 , V_151 ;
V_158 -> V_156 = V_158 -> V_157 = V_158 -> V_155 = 0 ;
for ( V_139 = 0 ; V_139 < V_137 ; V_139 ++ ) {
for ( V_140 = 0 ; V_140 < V_138 ; V_140 ++ ) {
if ( F_39 ( V_14 , V_139 , V_140 ) < 0 )
continue;
if ( F_54 ( F_39 ( V_14 , V_139 , V_140 ) ,
& V_151 , V_152 * sizeof( T_1 ) ) < 0 )
return - V_154 ;
V_158 -> V_156 += V_151 . V_156 ;
if ( V_150 ) {
V_158 -> V_157 += V_151 . V_157 ;
V_158 -> V_155 += V_151 . V_155 ;
}
}
}
V_14 -> V_146 -> V_159 = 0 ;
if ( V_150 ) {
if ( V_158 -> V_155 == 0 ) {
V_14 -> V_146 -> V_159 = - 1 ;
V_158 -> V_156 = 0 ;
return 0 ;
}
if ( V_158 -> V_155 < V_158 -> V_157 ) {
V_14 -> V_146 -> V_159 = 1 ;
V_158 -> V_156 = ( T_1 ) ( ( double ) V_158 -> V_156 * V_158 -> V_157 / V_158 -> V_155 + 0.5 ) ;
}
} else
V_158 -> V_157 = V_158 -> V_155 = 0 ;
return 0 ;
}
static int F_56 ( struct V_13 * V_14 , int V_139 , int V_140 )
{
struct V_13 * V_160 = V_14 -> V_160 ;
int V_23 ;
if ( ! F_35 ( V_14 ) )
return - 1 ;
F_57 ( ! V_160 -> V_23 ) ;
V_23 = F_39 ( V_160 , V_139 , V_140 ) ;
F_57 ( V_23 == - 1 ) ;
return V_23 ;
}
static int F_58 ( struct V_13 * V_14 , struct V_161 * V_162 ,
struct V_163 * V_164 )
{
int V_139 , V_140 ;
unsigned long V_165 = 0 ;
int V_166 = - 1 , V_77 ;
if ( V_14 -> V_23 == NULL &&
F_37 ( V_14 , V_162 -> V_167 , V_164 -> V_167 ) < 0 )
return - V_141 ;
if ( V_14 -> V_148 ) {
V_165 = V_168 ;
V_166 = V_14 -> V_148 -> V_23 ;
}
for ( V_139 = 0 ; V_139 < V_162 -> V_167 ; V_139 ++ ) {
for ( V_140 = 0 ; V_140 < V_164 -> V_167 ; V_140 ++ ) {
int V_169 ;
if ( ! V_14 -> V_148 )
V_166 = V_164 -> V_170 [ V_140 ] ;
V_169 = F_56 ( V_14 , V_139 , V_140 ) ;
F_39 ( V_14 , V_139 , V_140 ) = F_59 ( & V_14 -> V_16 ,
V_166 ,
V_162 -> V_170 [ V_139 ] ,
V_169 , V_165 ) ;
if ( F_39 ( V_14 , V_139 , V_140 ) < 0 ) {
V_77 = - V_154 ;
goto V_171;
}
}
}
return 0 ;
V_171:
do {
while ( -- V_140 >= 0 ) {
F_13 ( F_39 ( V_14 , V_139 , V_140 ) ) ;
F_39 ( V_14 , V_139 , V_140 ) = - 1 ;
}
V_140 = V_164 -> V_167 ;
} while ( -- V_139 >= 0 );
return V_77 ;
}
void F_60 ( struct V_13 * V_14 , int V_137 , int V_138 )
{
if ( V_14 -> V_23 == NULL )
return;
F_47 ( V_14 , V_137 , V_138 ) ;
F_45 ( V_14 ) ;
V_14 -> V_23 = NULL ;
}
int F_61 ( struct V_13 * V_14 , struct V_161 * V_162 ,
struct V_163 * V_164 )
{
if ( V_162 == NULL ) {
V_162 = & V_172 . V_170 ;
}
if ( V_164 == NULL )
V_164 = & V_173 . V_170 ;
return F_58 ( V_14 , V_162 , V_164 ) ;
}
int F_62 ( struct V_13 * V_14 ,
struct V_161 * V_162 )
{
return F_58 ( V_14 , V_162 , & V_173 . V_170 ) ;
}
int F_63 ( struct V_13 * V_14 ,
struct V_163 * V_164 )
{
return F_58 ( V_14 , & V_172 . V_170 , V_164 ) ;
}
static int F_64 ( const struct V_13 * V_14 ,
const union V_174 * V_175 ,
struct V_176 * V_177 )
{
T_1 type = V_14 -> V_16 . V_1 ;
const T_1 * V_178 = V_175 -> V_177 . V_178 ;
bool V_179 = V_14 -> V_180 ;
union V_181 V_182 ;
V_178 += ( ( V_175 -> V_183 . V_4 -
sizeof( V_175 -> V_183 ) ) / sizeof( T_1 ) ) - 1 ;
if ( type & V_39 ) {
V_182 . V_184 = * V_178 ;
if ( V_179 ) {
V_182 . V_184 = F_65 ( V_182 . V_184 ) ;
V_182 . V_185 [ 0 ] = F_66 ( V_182 . V_185 [ 0 ] ) ;
}
V_177 -> V_139 = V_182 . V_185 [ 0 ] ;
V_178 -- ;
}
if ( type & V_186 ) {
V_177 -> V_187 = * V_178 ;
V_178 -- ;
}
if ( type & V_188 ) {
V_177 -> V_44 = * V_178 ;
V_178 -- ;
}
if ( type & V_38 ) {
V_177 -> time = * V_178 ;
V_178 -- ;
}
if ( type & V_100 ) {
V_182 . V_184 = * V_178 ;
if ( V_179 ) {
V_182 . V_184 = F_65 ( V_182 . V_184 ) ;
V_182 . V_185 [ 0 ] = F_66 ( V_182 . V_185 [ 0 ] ) ;
V_182 . V_185 [ 1 ] = F_66 ( V_182 . V_185 [ 1 ] ) ;
}
V_177 -> V_166 = V_182 . V_185 [ 0 ] ;
V_177 -> V_189 = V_182 . V_185 [ 1 ] ;
}
return 0 ;
}
static bool F_67 ( const union V_174 * V_175 ,
const void * V_190 , T_1 V_4 )
{
const void * V_191 = V_175 ;
if ( V_190 + V_4 > V_191 + V_175 -> V_183 . V_4 )
return true ;
return false ;
}
int F_68 ( struct V_13 * V_14 , union V_174 * V_175 ,
struct V_176 * V_192 )
{
T_1 type = V_14 -> V_16 . V_1 ;
T_1 V_193 = V_14 -> V_16 . V_118 ;
bool V_179 = V_14 -> V_180 ;
const T_1 * V_178 ;
union V_181 V_182 ;
memset ( V_192 , 0 , sizeof( * V_192 ) ) ;
V_192 -> V_139 = V_192 -> V_166 = V_192 -> V_189 = - 1 ;
V_192 -> V_187 = V_192 -> V_44 = V_192 -> time = - 1ULL ;
V_192 -> V_124 = 1 ;
if ( V_175 -> V_183 . type != V_194 ) {
if ( ! V_14 -> V_16 . V_91 )
return 0 ;
return F_64 ( V_14 , V_175 , V_192 ) ;
}
V_178 = V_175 -> V_177 . V_178 ;
if ( V_14 -> V_19 + sizeof( V_175 -> V_183 ) > V_175 -> V_183 . V_4 )
return - V_195 ;
if ( type & V_99 ) {
V_192 -> V_196 = V_175 -> V_196 . V_196 ;
V_178 ++ ;
}
if ( type & V_100 ) {
V_182 . V_184 = * V_178 ;
if ( V_179 ) {
V_182 . V_184 = F_65 ( V_182 . V_184 ) ;
V_182 . V_185 [ 0 ] = F_66 ( V_182 . V_185 [ 0 ] ) ;
V_182 . V_185 [ 1 ] = F_66 ( V_182 . V_185 [ 1 ] ) ;
}
V_192 -> V_166 = V_182 . V_185 [ 0 ] ;
V_192 -> V_189 = V_182 . V_185 [ 1 ] ;
V_178 ++ ;
}
if ( type & V_38 ) {
V_192 -> time = * V_178 ;
V_178 ++ ;
}
V_192 -> V_64 = 0 ;
if ( type & V_111 ) {
V_192 -> V_64 = * V_178 ;
V_178 ++ ;
}
V_192 -> V_44 = - 1ULL ;
if ( type & V_188 ) {
V_192 -> V_44 = * V_178 ;
V_178 ++ ;
}
if ( type & V_186 ) {
V_192 -> V_187 = * V_178 ;
V_178 ++ ;
}
if ( type & V_39 ) {
V_182 . V_184 = * V_178 ;
if ( V_179 ) {
V_182 . V_184 = F_65 ( V_182 . V_184 ) ;
V_182 . V_185 [ 0 ] = F_66 ( V_182 . V_185 [ 0 ] ) ;
}
V_192 -> V_139 = V_182 . V_185 [ 0 ] ;
V_178 ++ ;
}
if ( type & V_40 ) {
V_192 -> V_124 = * V_178 ;
V_178 ++ ;
}
if ( type & V_197 ) {
fprintf ( V_198 , L_23 ) ;
return - 1 ;
}
if ( type & V_114 ) {
if ( F_67 ( V_175 , V_178 , sizeof( V_192 -> V_199 -> V_167 ) ) )
return - V_195 ;
V_192 -> V_199 = (struct V_200 * ) V_178 ;
if ( F_67 ( V_175 , V_178 , V_192 -> V_199 -> V_167 ) )
return - V_195 ;
V_178 += 1 + V_192 -> V_199 -> V_167 ;
}
if ( type & V_37 ) {
const T_1 * V_201 ;
V_182 . V_184 = * V_178 ;
if ( F_69 ( V_179 ,
L_24 ) ) {
V_182 . V_184 = F_65 ( V_182 . V_184 ) ;
V_182 . V_185 [ 0 ] = F_66 ( V_182 . V_185 [ 0 ] ) ;
V_182 . V_185 [ 1 ] = F_66 ( V_182 . V_185 [ 1 ] ) ;
}
if ( F_67 ( V_175 , V_178 , sizeof( V_202 ) ) )
return - V_195 ;
V_192 -> V_203 = V_182 . V_185 [ 0 ] ;
V_201 = ( void * ) V_178 + sizeof( V_202 ) ;
if ( F_67 ( V_175 , V_201 , V_192 -> V_203 ) )
return - V_195 ;
V_192 -> V_204 = ( void * ) V_201 ;
V_178 = ( void * ) V_178 + V_192 -> V_203 + sizeof( V_202 ) ;
}
if ( type & V_131 ) {
T_1 V_205 ;
V_192 -> V_130 = (struct V_130 * ) V_178 ;
V_178 ++ ;
V_205 = V_192 -> V_130 -> V_167 * sizeof( struct V_206 ) ;
V_205 /= sizeof( T_1 ) ;
V_178 += V_205 ;
}
if ( type & V_116 ) {
T_1 V_207 = * V_178 ++ ;
if ( V_207 ) {
V_192 -> V_208 . V_209 = ( T_1 * ) V_178 ;
V_178 += F_70 ( V_193 ) ;
}
}
if ( type & V_117 ) {
T_1 V_4 = * V_178 ++ ;
V_192 -> V_210 . V_190 = ( ( char * ) ( V_178 - 1 )
- ( char * ) V_175 ) ;
if ( ! V_4 ) {
V_192 -> V_210 . V_4 = 0 ;
} else {
V_192 -> V_210 . V_192 = ( char * ) V_178 ;
V_178 += V_4 / sizeof( * V_178 ) ;
V_192 -> V_210 . V_4 = * V_178 ;
}
}
return 0 ;
}
int F_71 ( union V_174 * V_175 , T_1 type ,
const struct V_176 * V_177 ,
bool V_179 )
{
T_1 * V_178 ;
union V_181 V_182 ;
V_178 = V_175 -> V_177 . V_178 ;
if ( type & V_99 ) {
V_175 -> V_196 . V_196 = V_177 -> V_196 ;
V_178 ++ ;
}
if ( type & V_100 ) {
V_182 . V_185 [ 0 ] = V_177 -> V_166 ;
V_182 . V_185 [ 1 ] = V_177 -> V_189 ;
if ( V_179 ) {
V_182 . V_185 [ 0 ] = F_66 ( V_182 . V_185 [ 0 ] ) ;
V_182 . V_185 [ 1 ] = F_66 ( V_182 . V_185 [ 1 ] ) ;
V_182 . V_184 = F_65 ( V_182 . V_184 ) ;
}
* V_178 = V_182 . V_184 ;
V_178 ++ ;
}
if ( type & V_38 ) {
* V_178 = V_177 -> time ;
V_178 ++ ;
}
if ( type & V_111 ) {
* V_178 = V_177 -> V_64 ;
V_178 ++ ;
}
if ( type & V_188 ) {
* V_178 = V_177 -> V_44 ;
V_178 ++ ;
}
if ( type & V_186 ) {
* V_178 = V_177 -> V_187 ;
V_178 ++ ;
}
if ( type & V_39 ) {
V_182 . V_185 [ 0 ] = V_177 -> V_139 ;
if ( V_179 ) {
V_182 . V_185 [ 0 ] = F_66 ( V_182 . V_185 [ 0 ] ) ;
V_182 . V_184 = F_65 ( V_182 . V_184 ) ;
}
* V_178 = V_182 . V_184 ;
V_178 ++ ;
}
if ( type & V_40 ) {
* V_178 = V_177 -> V_124 ;
V_178 ++ ;
}
return 0 ;
}
struct V_211 * F_72 ( struct V_13 * V_14 , const char * V_22 )
{
return F_73 ( V_14 -> V_42 , V_22 ) ;
}
void * F_74 ( struct V_13 * V_14 , struct V_176 * V_177 ,
const char * V_22 )
{
struct V_211 * V_212 = F_72 ( V_14 , V_22 ) ;
int V_190 ;
if ( ! V_212 )
return NULL ;
V_190 = V_212 -> V_190 ;
if ( V_212 -> V_165 & V_213 ) {
V_190 = * ( int * ) ( V_177 -> V_204 + V_212 -> V_190 ) ;
V_190 &= 0xffff ;
}
return V_177 -> V_204 + V_190 ;
}
T_1 F_75 ( struct V_13 * V_14 , struct V_176 * V_177 ,
const char * V_22 )
{
struct V_211 * V_212 = F_72 ( V_14 , V_22 ) ;
void * V_214 ;
T_1 V_215 ;
if ( ! V_212 )
return 0 ;
V_214 = V_177 -> V_204 + V_212 -> V_190 ;
switch ( V_212 -> V_4 ) {
case 1 :
return * ( T_5 * ) V_214 ;
case 2 :
V_215 = * ( V_216 * ) V_214 ;
break;
case 4 :
V_215 = * ( V_202 * ) V_214 ;
break;
case 8 :
V_215 = * ( T_1 * ) V_214 ;
break;
default:
return 0 ;
}
if ( ! V_14 -> V_180 )
return V_215 ;
switch ( V_212 -> V_4 ) {
case 2 :
return F_76 ( V_215 ) ;
case 4 :
return F_66 ( V_215 ) ;
case 8 :
return F_65 ( V_215 ) ;
default:
return 0 ;
}
return 0 ;
}
