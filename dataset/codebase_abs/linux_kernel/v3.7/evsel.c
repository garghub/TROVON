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
void F_33 ( struct V_13 * V_14 , struct V_88 * V_89 ,
struct V_13 * V_90 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
int V_91 = ! V_14 -> V_17 ;
V_16 -> V_92 = 1 ;
V_16 -> V_93 = V_89 -> V_94 ? 0 : 1 ;
V_16 -> V_95 = ! V_89 -> V_96 ;
V_16 -> V_97 = V_98 |
V_99 |
V_100 ;
V_16 -> V_1 |= V_101 | V_102 ;
if ( ! V_16 -> V_45 || ( V_89 -> V_103 != V_104 &&
V_89 -> V_105 != V_106 ) ) {
if ( V_89 -> V_107 ) {
V_16 -> V_1 |= V_40 ;
V_16 -> V_107 = 1 ;
V_16 -> V_108 = V_89 -> V_107 ;
} else {
V_16 -> V_45 = V_89 -> V_109 ;
}
}
if ( V_89 -> V_110 )
V_16 -> V_108 = 0 ;
if ( V_89 -> V_111 )
V_16 -> V_111 = 1 ;
if ( V_89 -> V_112 ) {
V_16 -> V_1 |= V_113 ;
V_16 -> V_114 = V_91 ;
}
if ( V_89 -> V_115 ) {
V_16 -> V_1 |= V_116 ;
if ( V_89 -> V_115 == V_117 ) {
V_16 -> V_1 |= V_118 |
V_119 ;
V_16 -> V_120 = V_121 ;
V_16 -> V_122 = V_89 -> V_123 ;
V_16 -> V_124 = 1 ;
}
}
if ( F_34 ( & V_89 -> V_125 ) )
V_16 -> V_1 |= V_39 ;
if ( V_89 -> V_126 )
V_16 -> V_1 |= V_40 ;
if ( ! V_89 -> V_94 &&
( V_89 -> V_127 || ! V_89 -> V_96 ||
F_34 ( & V_89 -> V_125 ) ) )
V_16 -> V_1 |= V_38 ;
if ( V_89 -> V_128 ) {
V_16 -> V_1 |= V_38 ;
V_16 -> V_1 |= V_37 ;
V_16 -> V_1 |= V_39 ;
}
if ( V_89 -> V_129 ) {
V_16 -> V_130 = 0 ;
V_16 -> V_131 = 1 ;
}
if ( V_89 -> V_132 ) {
V_16 -> V_1 |= V_133 ;
V_16 -> V_134 = V_89 -> V_132 ;
}
V_16 -> V_135 = V_91 ;
V_16 -> V_136 = V_91 ;
if ( F_35 ( & V_89 -> V_125 ) &&
( ! V_89 -> V_137 || V_14 == V_90 ) ) {
V_16 -> V_138 = 1 ;
}
}
int F_36 ( struct V_13 * V_14 , int V_139 , int V_140 )
{
int V_141 , V_142 ;
V_14 -> V_23 = F_37 ( V_139 , V_140 , sizeof( int ) ) ;
if ( V_14 -> V_23 ) {
for ( V_141 = 0 ; V_141 < V_139 ; V_141 ++ ) {
for ( V_142 = 0 ; V_142 < V_140 ; V_142 ++ ) {
F_38 ( V_14 , V_141 , V_142 ) = - 1 ;
}
}
}
return V_14 -> V_23 != NULL ? 0 : - V_143 ;
}
int F_39 ( struct V_13 * V_14 , int V_139 , int V_140 ,
const char * V_144 )
{
int V_141 , V_142 ;
for ( V_141 = 0 ; V_141 < V_139 ; V_141 ++ ) {
for ( V_142 = 0 ; V_142 < V_140 ; V_142 ++ ) {
int V_23 = F_38 ( V_14 , V_141 , V_142 ) ,
V_77 = F_40 ( V_23 , V_145 , V_144 ) ;
if ( V_77 )
return V_77 ;
}
}
return 0 ;
}
int F_41 ( struct V_13 * V_14 , int V_139 , int V_140 )
{
V_14 -> V_146 = F_37 ( V_139 , V_140 , sizeof( struct V_147 ) ) ;
if ( V_14 -> V_146 == NULL )
return - V_143 ;
V_14 -> V_44 = F_7 ( V_139 * V_140 * sizeof( T_1 ) ) ;
if ( V_14 -> V_44 == NULL ) {
F_42 ( V_14 -> V_146 ) ;
V_14 -> V_146 = NULL ;
return - V_143 ;
}
return 0 ;
}
int F_43 ( struct V_13 * V_14 , int V_139 )
{
V_14 -> V_148 = F_7 ( ( sizeof( * V_14 -> V_148 ) +
( V_139 * sizeof( struct V_149 ) ) ) ) ;
return V_14 -> V_148 != NULL ? 0 : - V_143 ;
}
void F_44 ( struct V_13 * V_14 )
{
F_42 ( V_14 -> V_23 ) ;
V_14 -> V_23 = NULL ;
}
void F_45 ( struct V_13 * V_14 )
{
F_42 ( V_14 -> V_146 ) ;
V_14 -> V_146 = NULL ;
free ( V_14 -> V_44 ) ;
V_14 -> V_44 = NULL ;
}
void F_46 ( struct V_13 * V_14 , int V_139 , int V_140 )
{
int V_141 , V_142 ;
for ( V_141 = 0 ; V_141 < V_139 ; V_141 ++ )
for ( V_142 = 0 ; V_142 < V_140 ; ++ V_142 ) {
F_13 ( F_38 ( V_14 , V_141 , V_142 ) ) ;
F_38 ( V_14 , V_141 , V_142 ) = - 1 ;
}
}
void F_47 ( struct V_13 * V_14 )
{
assert ( F_48 ( & V_14 -> V_18 ) ) ;
F_42 ( V_14 -> V_23 ) ;
F_42 ( V_14 -> V_146 ) ;
free ( V_14 -> V_44 ) ;
}
void F_49 ( struct V_13 * V_14 )
{
F_47 ( V_14 ) ;
F_50 ( V_14 -> V_150 ) ;
free ( V_14 -> V_151 ) ;
if ( V_14 -> V_42 )
F_51 ( V_14 -> V_42 ) ;
free ( V_14 -> V_22 ) ;
free ( V_14 ) ;
}
int F_52 ( struct V_13 * V_14 ,
int V_141 , int V_142 , bool V_152 )
{
struct V_149 V_153 ;
T_2 V_154 = V_152 ? 3 : 1 ;
if ( F_38 ( V_14 , V_141 , V_142 ) < 0 )
return - V_155 ;
if ( V_14 -> V_148 == NULL && F_43 ( V_14 , V_141 + 1 ) < 0 )
return - V_143 ;
if ( F_53 ( F_38 ( V_14 , V_141 , V_142 ) , & V_153 , V_154 * sizeof( T_1 ) ) < 0 )
return - V_156 ;
if ( V_152 ) {
if ( V_153 . V_157 == 0 )
V_153 . V_158 = 0 ;
else if ( V_153 . V_157 < V_153 . V_159 )
V_153 . V_158 = ( T_1 ) ( ( double ) V_153 . V_158 * V_153 . V_159 / V_153 . V_157 + 0.5 ) ;
} else
V_153 . V_159 = V_153 . V_157 = 0 ;
V_14 -> V_148 -> V_141 [ V_141 ] = V_153 ;
return 0 ;
}
int F_54 ( struct V_13 * V_14 ,
int V_139 , int V_140 , bool V_152 )
{
T_2 V_154 = V_152 ? 3 : 1 ;
int V_141 , V_142 ;
struct V_149 * V_160 = & V_14 -> V_148 -> V_160 , V_153 ;
V_160 -> V_158 = V_160 -> V_159 = V_160 -> V_157 = 0 ;
for ( V_141 = 0 ; V_141 < V_139 ; V_141 ++ ) {
for ( V_142 = 0 ; V_142 < V_140 ; V_142 ++ ) {
if ( F_38 ( V_14 , V_141 , V_142 ) < 0 )
continue;
if ( F_53 ( F_38 ( V_14 , V_141 , V_142 ) ,
& V_153 , V_154 * sizeof( T_1 ) ) < 0 )
return - V_156 ;
V_160 -> V_158 += V_153 . V_158 ;
if ( V_152 ) {
V_160 -> V_159 += V_153 . V_159 ;
V_160 -> V_157 += V_153 . V_157 ;
}
}
}
V_14 -> V_148 -> V_161 = 0 ;
if ( V_152 ) {
if ( V_160 -> V_157 == 0 ) {
V_14 -> V_148 -> V_161 = - 1 ;
V_160 -> V_158 = 0 ;
return 0 ;
}
if ( V_160 -> V_157 < V_160 -> V_159 ) {
V_14 -> V_148 -> V_161 = 1 ;
V_160 -> V_158 = ( T_1 ) ( ( double ) V_160 -> V_158 * V_160 -> V_159 / V_160 -> V_157 + 0.5 ) ;
}
} else
V_160 -> V_159 = V_160 -> V_157 = 0 ;
return 0 ;
}
static int F_55 ( struct V_13 * V_14 , int V_141 , int V_142 )
{
struct V_13 * V_162 = V_14 -> V_162 ;
int V_23 ;
if ( ! V_162 )
return - 1 ;
F_56 ( ! V_162 -> V_23 ) ;
V_23 = F_38 ( V_162 , V_141 , V_142 ) ;
F_56 ( V_23 == - 1 ) ;
return V_23 ;
}
static int F_57 ( struct V_13 * V_14 , struct V_163 * V_164 ,
struct V_165 * V_166 )
{
int V_141 , V_142 ;
unsigned long V_167 = 0 ;
int V_168 = - 1 , V_77 ;
if ( V_14 -> V_23 == NULL &&
F_36 ( V_14 , V_164 -> V_169 , V_166 -> V_169 ) < 0 )
return - V_143 ;
if ( V_14 -> V_150 ) {
V_167 = V_170 ;
V_168 = V_14 -> V_150 -> V_23 ;
}
for ( V_141 = 0 ; V_141 < V_164 -> V_169 ; V_141 ++ ) {
for ( V_142 = 0 ; V_142 < V_166 -> V_169 ; V_142 ++ ) {
int V_171 ;
if ( ! V_14 -> V_150 )
V_168 = V_166 -> V_172 [ V_142 ] ;
V_171 = F_55 ( V_14 , V_141 , V_142 ) ;
F_38 ( V_14 , V_141 , V_142 ) = F_58 ( & V_14 -> V_16 ,
V_168 ,
V_164 -> V_172 [ V_141 ] ,
V_171 , V_167 ) ;
if ( F_38 ( V_14 , V_141 , V_142 ) < 0 ) {
V_77 = - V_156 ;
goto V_173;
}
}
}
return 0 ;
V_173:
do {
while ( -- V_142 >= 0 ) {
F_13 ( F_38 ( V_14 , V_141 , V_142 ) ) ;
F_38 ( V_14 , V_141 , V_142 ) = - 1 ;
}
V_142 = V_166 -> V_169 ;
} while ( -- V_141 >= 0 );
return V_77 ;
}
void F_59 ( struct V_13 * V_14 , int V_139 , int V_140 )
{
if ( V_14 -> V_23 == NULL )
return;
F_46 ( V_14 , V_139 , V_140 ) ;
F_44 ( V_14 ) ;
V_14 -> V_23 = NULL ;
}
int F_60 ( struct V_13 * V_14 , struct V_163 * V_164 ,
struct V_165 * V_166 )
{
if ( V_164 == NULL ) {
V_164 = & V_174 . V_172 ;
}
if ( V_166 == NULL )
V_166 = & V_175 . V_172 ;
return F_57 ( V_14 , V_164 , V_166 ) ;
}
int F_61 ( struct V_13 * V_14 ,
struct V_163 * V_164 )
{
return F_57 ( V_14 , V_164 , & V_175 . V_172 ) ;
}
int F_62 ( struct V_13 * V_14 ,
struct V_165 * V_166 )
{
return F_57 ( V_14 , & V_174 . V_172 , V_166 ) ;
}
static int F_63 ( const struct V_13 * V_14 ,
const union V_176 * V_177 ,
struct V_178 * V_179 )
{
T_1 type = V_14 -> V_16 . V_1 ;
const T_1 * V_180 = V_177 -> V_179 . V_180 ;
bool V_181 = V_14 -> V_182 ;
union V_183 V_184 ;
V_180 += ( ( V_177 -> V_185 . V_4 -
sizeof( V_177 -> V_185 ) ) / sizeof( T_1 ) ) - 1 ;
if ( type & V_39 ) {
V_184 . V_186 = * V_180 ;
if ( V_181 ) {
V_184 . V_186 = F_64 ( V_184 . V_186 ) ;
V_184 . V_187 [ 0 ] = F_65 ( V_184 . V_187 [ 0 ] ) ;
}
V_179 -> V_141 = V_184 . V_187 [ 0 ] ;
V_180 -- ;
}
if ( type & V_188 ) {
V_179 -> V_189 = * V_180 ;
V_180 -- ;
}
if ( type & V_190 ) {
V_179 -> V_44 = * V_180 ;
V_180 -- ;
}
if ( type & V_38 ) {
V_179 -> time = * V_180 ;
V_180 -- ;
}
if ( type & V_102 ) {
V_184 . V_186 = * V_180 ;
if ( V_181 ) {
V_184 . V_186 = F_64 ( V_184 . V_186 ) ;
V_184 . V_187 [ 0 ] = F_65 ( V_184 . V_187 [ 0 ] ) ;
V_184 . V_187 [ 1 ] = F_65 ( V_184 . V_187 [ 1 ] ) ;
}
V_179 -> V_168 = V_184 . V_187 [ 0 ] ;
V_179 -> V_191 = V_184 . V_187 [ 1 ] ;
}
return 0 ;
}
static bool F_66 ( const union V_176 * V_177 ,
const void * V_192 , T_1 V_4 )
{
const void * V_193 = V_177 ;
if ( V_192 + V_4 > V_193 + V_177 -> V_185 . V_4 )
return true ;
return false ;
}
int F_67 ( struct V_13 * V_14 , union V_176 * V_177 ,
struct V_178 * V_194 )
{
T_1 type = V_14 -> V_16 . V_1 ;
T_1 V_195 = V_14 -> V_16 . V_120 ;
bool V_181 = V_14 -> V_182 ;
const T_1 * V_180 ;
union V_183 V_184 ;
memset ( V_194 , 0 , sizeof( * V_194 ) ) ;
V_194 -> V_141 = V_194 -> V_168 = V_194 -> V_191 = - 1 ;
V_194 -> V_189 = V_194 -> V_44 = V_194 -> time = - 1ULL ;
V_194 -> V_126 = 1 ;
if ( V_177 -> V_185 . type != V_196 ) {
if ( ! V_14 -> V_16 . V_93 )
return 0 ;
return F_63 ( V_14 , V_177 , V_194 ) ;
}
V_180 = V_177 -> V_179 . V_180 ;
if ( V_14 -> V_19 + sizeof( V_177 -> V_185 ) > V_177 -> V_185 . V_4 )
return - V_197 ;
if ( type & V_101 ) {
V_194 -> V_198 = V_177 -> V_198 . V_198 ;
V_180 ++ ;
}
if ( type & V_102 ) {
V_184 . V_186 = * V_180 ;
if ( V_181 ) {
V_184 . V_186 = F_64 ( V_184 . V_186 ) ;
V_184 . V_187 [ 0 ] = F_65 ( V_184 . V_187 [ 0 ] ) ;
V_184 . V_187 [ 1 ] = F_65 ( V_184 . V_187 [ 1 ] ) ;
}
V_194 -> V_168 = V_184 . V_187 [ 0 ] ;
V_194 -> V_191 = V_184 . V_187 [ 1 ] ;
V_180 ++ ;
}
if ( type & V_38 ) {
V_194 -> time = * V_180 ;
V_180 ++ ;
}
V_194 -> V_64 = 0 ;
if ( type & V_113 ) {
V_194 -> V_64 = * V_180 ;
V_180 ++ ;
}
V_194 -> V_44 = - 1ULL ;
if ( type & V_190 ) {
V_194 -> V_44 = * V_180 ;
V_180 ++ ;
}
if ( type & V_188 ) {
V_194 -> V_189 = * V_180 ;
V_180 ++ ;
}
if ( type & V_39 ) {
V_184 . V_186 = * V_180 ;
if ( V_181 ) {
V_184 . V_186 = F_64 ( V_184 . V_186 ) ;
V_184 . V_187 [ 0 ] = F_65 ( V_184 . V_187 [ 0 ] ) ;
}
V_194 -> V_141 = V_184 . V_187 [ 0 ] ;
V_180 ++ ;
}
if ( type & V_40 ) {
V_194 -> V_126 = * V_180 ;
V_180 ++ ;
}
if ( type & V_199 ) {
fprintf ( V_200 , L_23 ) ;
return - 1 ;
}
if ( type & V_116 ) {
if ( F_66 ( V_177 , V_180 , sizeof( V_194 -> V_201 -> V_169 ) ) )
return - V_197 ;
V_194 -> V_201 = (struct V_202 * ) V_180 ;
if ( F_66 ( V_177 , V_180 , V_194 -> V_201 -> V_169 ) )
return - V_197 ;
V_180 += 1 + V_194 -> V_201 -> V_169 ;
}
if ( type & V_37 ) {
const T_1 * V_203 ;
V_184 . V_186 = * V_180 ;
if ( F_68 ( V_181 ,
L_24 ) ) {
V_184 . V_186 = F_64 ( V_184 . V_186 ) ;
V_184 . V_187 [ 0 ] = F_65 ( V_184 . V_187 [ 0 ] ) ;
V_184 . V_187 [ 1 ] = F_65 ( V_184 . V_187 [ 1 ] ) ;
}
if ( F_66 ( V_177 , V_180 , sizeof( V_204 ) ) )
return - V_197 ;
V_194 -> V_205 = V_184 . V_187 [ 0 ] ;
V_203 = ( void * ) V_180 + sizeof( V_204 ) ;
if ( F_66 ( V_177 , V_203 , V_194 -> V_205 ) )
return - V_197 ;
V_194 -> V_206 = ( void * ) V_203 ;
V_180 = ( void * ) V_180 + V_194 -> V_205 + sizeof( V_204 ) ;
}
if ( type & V_133 ) {
T_1 V_207 ;
V_194 -> V_132 = (struct V_132 * ) V_180 ;
V_180 ++ ;
V_207 = V_194 -> V_132 -> V_169 * sizeof( struct V_208 ) ;
V_207 /= sizeof( T_1 ) ;
V_180 += V_207 ;
}
if ( type & V_118 ) {
T_1 V_209 = * V_180 ++ ;
if ( V_209 ) {
V_194 -> V_210 . V_211 = ( T_1 * ) V_180 ;
V_180 += F_69 ( V_195 ) ;
}
}
if ( type & V_119 ) {
T_1 V_4 = * V_180 ++ ;
V_194 -> V_212 . V_192 = ( ( char * ) ( V_180 - 1 )
- ( char * ) V_177 ) ;
if ( ! V_4 ) {
V_194 -> V_212 . V_4 = 0 ;
} else {
V_194 -> V_212 . V_194 = ( char * ) V_180 ;
V_180 += V_4 / sizeof( * V_180 ) ;
V_194 -> V_212 . V_4 = * V_180 ;
}
}
return 0 ;
}
int F_70 ( union V_176 * V_177 , T_1 type ,
const struct V_178 * V_179 ,
bool V_181 )
{
T_1 * V_180 ;
union V_183 V_184 ;
V_180 = V_177 -> V_179 . V_180 ;
if ( type & V_101 ) {
V_177 -> V_198 . V_198 = V_179 -> V_198 ;
V_180 ++ ;
}
if ( type & V_102 ) {
V_184 . V_187 [ 0 ] = V_179 -> V_168 ;
V_184 . V_187 [ 1 ] = V_179 -> V_191 ;
if ( V_181 ) {
V_184 . V_187 [ 0 ] = F_65 ( V_184 . V_187 [ 0 ] ) ;
V_184 . V_187 [ 1 ] = F_65 ( V_184 . V_187 [ 1 ] ) ;
V_184 . V_186 = F_64 ( V_184 . V_186 ) ;
}
* V_180 = V_184 . V_186 ;
V_180 ++ ;
}
if ( type & V_38 ) {
* V_180 = V_179 -> time ;
V_180 ++ ;
}
if ( type & V_113 ) {
* V_180 = V_179 -> V_64 ;
V_180 ++ ;
}
if ( type & V_190 ) {
* V_180 = V_179 -> V_44 ;
V_180 ++ ;
}
if ( type & V_188 ) {
* V_180 = V_179 -> V_189 ;
V_180 ++ ;
}
if ( type & V_39 ) {
V_184 . V_187 [ 0 ] = V_179 -> V_141 ;
if ( V_181 ) {
V_184 . V_187 [ 0 ] = F_65 ( V_184 . V_187 [ 0 ] ) ;
V_184 . V_186 = F_64 ( V_184 . V_186 ) ;
}
* V_180 = V_184 . V_186 ;
V_180 ++ ;
}
if ( type & V_40 ) {
* V_180 = V_179 -> V_126 ;
V_180 ++ ;
}
return 0 ;
}
struct V_213 * F_71 ( struct V_13 * V_14 , const char * V_22 )
{
return F_72 ( V_14 -> V_42 , V_22 ) ;
}
void * F_73 ( struct V_13 * V_14 , struct V_178 * V_179 ,
const char * V_22 )
{
struct V_213 * V_214 = F_71 ( V_14 , V_22 ) ;
int V_192 ;
if ( ! V_214 )
return NULL ;
V_192 = V_214 -> V_192 ;
if ( V_214 -> V_167 & V_215 ) {
V_192 = * ( int * ) ( V_179 -> V_206 + V_214 -> V_192 ) ;
V_192 &= 0xffff ;
}
return V_179 -> V_206 + V_192 ;
}
T_1 F_74 ( struct V_13 * V_14 , struct V_178 * V_179 ,
const char * V_22 )
{
struct V_213 * V_214 = F_71 ( V_14 , V_22 ) ;
void * V_216 ;
T_1 V_217 ;
if ( ! V_214 )
return 0 ;
V_216 = V_179 -> V_206 + V_214 -> V_192 ;
switch ( V_214 -> V_4 ) {
case 1 :
return * ( T_5 * ) V_216 ;
case 2 :
V_217 = * ( V_218 * ) V_216 ;
break;
case 4 :
V_217 = * ( V_204 * ) V_216 ;
break;
case 8 :
V_217 = * ( T_1 * ) V_216 ;
break;
default:
return 0 ;
}
if ( ! V_14 -> V_182 )
return V_217 ;
switch ( V_214 -> V_4 ) {
case 2 :
return F_75 ( V_217 ) ;
case 4 :
return F_65 ( V_217 ) ;
case 8 :
return F_64 ( V_217 ) ;
default:
return 0 ;
}
return 0 ;
}
