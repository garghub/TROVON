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
enum V_15 V_16 )
{
if ( ! ( V_14 -> V_17 . V_1 & V_16 ) ) {
V_14 -> V_17 . V_1 |= V_16 ;
V_14 -> V_18 += sizeof( T_1 ) ;
}
}
void F_5 ( struct V_13 * V_14 ,
enum V_15 V_16 )
{
if ( V_14 -> V_17 . V_1 & V_16 ) {
V_14 -> V_17 . V_1 &= ~ V_16 ;
V_14 -> V_18 -= sizeof( T_1 ) ;
}
}
void F_6 ( struct V_13 * V_14 )
{
F_7 ( V_14 , V_19 ) ;
V_14 -> V_17 . V_20 |= V_21 ;
}
void F_8 ( struct V_13 * V_14 ,
struct V_22 * V_17 , int V_23 )
{
V_14 -> V_23 = V_23 ;
V_14 -> V_17 = * V_17 ;
V_14 -> V_24 = V_14 ;
F_9 ( & V_14 -> V_25 ) ;
F_2 ( & V_14 -> V_6 ) ;
V_14 -> V_18 = F_1 ( V_17 -> V_1 ) ;
}
struct V_13 * F_10 ( struct V_22 * V_17 , int V_23 )
{
struct V_13 * V_14 = F_11 ( sizeof( * V_14 ) ) ;
if ( V_14 != NULL )
F_8 ( V_14 , V_17 , V_23 ) ;
return V_14 ;
}
struct V_26 * F_12 ( const char * V_27 , const char * V_28 )
{
int V_29 , V_30 ;
char * V_31 ;
void * V_32 = NULL , * V_33 ;
T_2 V_4 = 0 , V_34 = 0 ;
struct V_26 * V_35 = NULL ;
if ( F_13 ( & V_31 , L_1 , V_36 , V_27 , V_28 ) < 0 )
goto V_37;
V_29 = F_14 ( V_31 , V_38 ) ;
if ( V_29 < 0 )
goto V_39;
do {
if ( V_4 == V_34 ) {
V_34 += V_40 ;
V_33 = realloc ( V_32 , V_34 ) ;
if ( V_33 == NULL )
goto V_41;
V_32 = V_33 ;
}
V_30 = F_15 ( V_29 , V_32 + V_4 , V_34 - V_4 ) ;
if ( V_30 < 0 )
goto V_41;
V_4 += V_30 ;
} while ( V_30 > 0 );
F_16 ( & V_35 , V_32 , V_4 , V_27 ) ;
V_41:
free ( V_32 ) ;
F_17 ( V_29 ) ;
V_39:
free ( V_31 ) ;
V_37:
return V_35 ;
}
struct V_13 * F_18 ( const char * V_27 , const char * V_28 , int V_23 )
{
struct V_13 * V_14 = F_11 ( sizeof( * V_14 ) ) ;
if ( V_14 != NULL ) {
struct V_22 V_17 = {
. type = V_42 ,
. V_1 = ( V_43 | V_44 |
V_45 | V_46 ) ,
} ;
if ( F_13 ( & V_14 -> V_28 , L_2 , V_27 , V_28 ) < 0 )
goto V_47;
V_14 -> V_48 = F_12 ( V_27 , V_28 ) ;
if ( V_14 -> V_48 == NULL )
goto V_47;
F_19 ( & V_17 ) ;
V_17 . V_49 = V_14 -> V_48 -> V_50 ;
V_17 . V_51 = 1 ;
F_8 ( V_14 , & V_17 , V_23 ) ;
}
return V_14 ;
V_47:
free ( V_14 -> V_28 ) ;
free ( V_14 ) ;
return NULL ;
}
static const char * F_20 ( T_1 V_49 )
{
if ( V_49 < V_52 && V_53 [ V_49 ] )
return V_53 [ V_49 ] ;
return L_3 ;
}
static int F_21 ( struct V_13 * V_14 , char * V_32 , T_2 V_4 )
{
int V_54 = 0 , V_55 = 0 ;
struct V_22 * V_17 = & V_14 -> V_17 ;
bool V_56 = false ;
#define F_22 ( T_3 , T_4 ) do { \
if (!attr->exclude_##context) { \
if (!colon) colon = ++r; \
r += scnprintf(bf + r, size - r, "%c", mod); \
} } while(0)
if ( V_17 -> V_57 || V_17 -> V_58 || V_17 -> V_59 ) {
F_22 ( V_60 , 'k' ) ;
F_22 ( V_61 , 'u' ) ;
F_22 ( V_62 , 'h' ) ;
V_56 = true ;
}
if ( V_17 -> V_63 ) {
if ( ! V_54 )
V_54 = ++ V_55 ;
V_55 += F_23 ( V_32 + V_55 , V_4 - V_55 , L_4 , V_17 -> V_63 , L_5 ) ;
V_56 = true ;
}
if ( V_17 -> V_64 || V_17 -> V_65 == V_56 ) {
F_22 ( V_66 , 'H' ) ;
F_22 ( V_67 , 'G' ) ;
}
#undef F_22
if ( V_54 )
V_32 [ V_54 - 1 ] = ':' ;
return V_55 ;
}
static int F_24 ( struct V_13 * V_14 , char * V_32 , T_2 V_4 )
{
int V_55 = F_23 ( V_32 , V_4 , L_6 , F_20 ( V_14 -> V_17 . V_49 ) ) ;
return V_55 + F_21 ( V_14 , V_32 + V_55 , V_4 - V_55 ) ;
}
static const char * F_25 ( T_1 V_49 )
{
if ( V_49 < V_68 && V_69 [ V_49 ] )
return V_69 [ V_49 ] ;
return L_7 ;
}
static int F_26 ( struct V_13 * V_14 , char * V_32 , T_2 V_4 )
{
int V_55 = F_23 ( V_32 , V_4 , L_6 , F_25 ( V_14 -> V_17 . V_49 ) ) ;
return V_55 + F_21 ( V_14 , V_32 + V_55 , V_4 - V_55 ) ;
}
static int F_27 ( char * V_32 , T_2 V_4 , T_1 V_70 , T_1 type )
{
int V_55 ;
V_55 = F_23 ( V_32 , V_4 , L_8 V_71 L_9 , V_70 ) ;
if ( type & V_72 )
V_55 += F_23 ( V_32 + V_55 , V_4 - V_55 , L_10 ) ;
if ( type & V_73 )
V_55 += F_23 ( V_32 + V_55 , V_4 - V_55 , L_11 ) ;
if ( type & V_74 )
V_55 += F_23 ( V_32 + V_55 , V_4 - V_55 , L_12 ) ;
return V_55 ;
}
static int F_28 ( struct V_13 * V_14 , char * V_32 , T_2 V_4 )
{
struct V_22 * V_17 = & V_14 -> V_17 ;
int V_55 = F_27 ( V_32 , V_4 , V_17 -> V_75 , V_17 -> V_76 ) ;
return V_55 + F_21 ( V_14 , V_32 + V_55 , V_4 - V_55 ) ;
}
bool F_29 ( T_5 type , T_5 V_77 )
{
if ( V_78 [ type ] & F_30 ( V_77 ) )
return true ;
else
return false ;
}
int F_31 ( T_5 type , T_5 V_77 , T_5 V_79 ,
char * V_32 , T_2 V_4 )
{
if ( V_79 ) {
return F_23 ( V_32 , V_4 , L_13 , V_80 [ type ] [ 0 ] ,
V_81 [ V_77 ] [ 0 ] ,
V_82 [ V_79 ] [ 0 ] ) ;
}
return F_23 ( V_32 , V_4 , L_14 , V_80 [ type ] [ 0 ] ,
V_81 [ V_77 ] [ 1 ] ) ;
}
static int F_32 ( T_1 V_49 , char * V_32 , T_2 V_4 )
{
T_5 V_77 , V_79 , type = ( V_49 >> 0 ) & 0xff ;
const char * V_83 = L_15 ;
if ( type > V_84 )
goto V_85;
V_77 = ( V_49 >> 8 ) & 0xff ;
V_83 = L_16 ;
if ( V_77 > V_86 )
goto V_85;
V_79 = ( V_49 >> 16 ) & 0xff ;
V_83 = L_17 ;
if ( V_79 > V_87 )
goto V_85;
V_83 = L_18 ;
if ( ! F_29 ( type , V_77 ) )
goto V_85;
return F_31 ( type , V_77 , V_79 , V_32 , V_4 ) ;
V_85:
return F_23 ( V_32 , V_4 , L_6 , V_83 ) ;
}
static int F_33 ( struct V_13 * V_14 , char * V_32 , T_2 V_4 )
{
int V_88 = F_32 ( V_14 -> V_17 . V_49 , V_32 , V_4 ) ;
return V_88 + F_21 ( V_14 , V_32 + V_88 , V_4 - V_88 ) ;
}
static int F_34 ( struct V_13 * V_14 , char * V_32 , T_2 V_4 )
{
int V_88 = F_23 ( V_32 , V_4 , L_19 V_71 , V_14 -> V_17 . V_49 ) ;
return V_88 + F_21 ( V_14 , V_32 + V_88 , V_4 - V_88 ) ;
}
const char * F_35 ( struct V_13 * V_14 )
{
char V_32 [ 128 ] ;
if ( V_14 -> V_28 )
return V_14 -> V_28 ;
switch ( V_14 -> V_17 . type ) {
case V_89 :
F_34 ( V_14 , V_32 , sizeof( V_32 ) ) ;
break;
case V_90 :
F_24 ( V_14 , V_32 , sizeof( V_32 ) ) ;
break;
case V_91 :
F_33 ( V_14 , V_32 , sizeof( V_32 ) ) ;
break;
case V_92 :
F_26 ( V_14 , V_32 , sizeof( V_32 ) ) ;
break;
case V_42 :
F_23 ( V_32 , sizeof( V_32 ) , L_6 , L_20 ) ;
break;
case V_93 :
F_28 ( V_14 , V_32 , sizeof( V_32 ) ) ;
break;
default:
F_23 ( V_32 , sizeof( V_32 ) , L_21 ,
V_14 -> V_17 . type ) ;
break;
}
V_14 -> V_28 = F_36 ( V_32 ) ;
return V_14 -> V_28 ? : L_22 ;
}
const char * F_37 ( struct V_13 * V_14 )
{
return V_14 -> V_94 ? : L_23 ;
}
int F_38 ( struct V_13 * V_14 , char * V_95 , T_2 V_4 )
{
int V_88 ;
struct V_13 * V_96 ;
const char * V_94 = F_37 ( V_14 ) ;
V_88 = F_23 ( V_95 , V_4 , L_6 , V_94 ) ;
V_88 += F_23 ( V_95 + V_88 , V_4 - V_88 , L_24 ,
F_35 ( V_14 ) ) ;
F_39 (pos, evsel)
V_88 += F_23 ( V_95 + V_88 , V_4 - V_88 , L_25 ,
F_35 ( V_96 ) ) ;
V_88 += F_23 ( V_95 + V_88 , V_4 - V_88 , L_26 ) ;
return V_88 ;
}
void F_40 ( struct V_13 * V_14 ,
struct V_97 * V_98 )
{
struct V_22 * V_17 = & V_14 -> V_17 ;
int V_99 = ! V_14 -> V_23 ;
V_17 -> V_100 = V_101 . V_100 ? 0 : 1 ;
V_17 -> V_102 = ! V_98 -> V_103 ;
F_7 ( V_14 , V_104 ) ;
F_7 ( V_14 , V_105 ) ;
if ( ! V_17 -> V_51 || ( V_98 -> V_106 != V_107 &&
V_98 -> V_108 != V_109 ) ) {
if ( V_98 -> V_110 ) {
F_7 ( V_14 , V_111 ) ;
V_17 -> V_110 = 1 ;
V_17 -> V_112 = V_98 -> V_110 ;
} else {
V_17 -> V_51 = V_98 -> V_113 ;
}
}
if ( V_98 -> V_114 )
V_17 -> V_112 = 0 ;
if ( V_98 -> V_115 )
V_17 -> V_115 = 1 ;
if ( V_98 -> V_116 ) {
F_7 ( V_14 , V_117 ) ;
V_17 -> V_118 = V_99 ;
}
if ( V_98 -> V_119 ) {
F_7 ( V_14 , V_120 ) ;
if ( V_98 -> V_119 == V_121 ) {
F_7 ( V_14 , V_122 ) ;
F_7 ( V_14 , V_123 ) ;
V_17 -> V_124 = V_125 ;
V_17 -> V_126 = V_98 -> V_127 ;
V_17 -> V_128 = 1 ;
}
}
if ( F_41 ( & V_98 -> V_129 ) )
F_7 ( V_14 , V_130 ) ;
if ( V_98 -> V_131 )
F_7 ( V_14 , V_111 ) ;
if ( ! V_101 . V_100 &&
( V_98 -> V_132 || ! V_98 -> V_103 ||
F_41 ( & V_98 -> V_129 ) ) )
F_7 ( V_14 , TIME ) ;
if ( V_98 -> V_133 ) {
F_7 ( V_14 , TIME ) ;
F_7 ( V_14 , V_134 ) ;
F_7 ( V_14 , V_130 ) ;
}
if ( V_98 -> V_116 )
V_17 -> V_1 |= V_135 ;
if ( V_98 -> V_136 ) {
V_17 -> V_137 = 0 ;
V_17 -> V_138 = 1 ;
}
if ( V_98 -> V_139 ) {
F_7 ( V_14 , V_140 ) ;
V_17 -> V_141 = V_98 -> V_139 ;
}
if ( V_98 -> V_142 )
V_17 -> V_1 |= V_143 ;
V_17 -> V_144 = V_99 ;
V_17 -> V_145 = V_99 ;
if ( F_42 ( V_14 ) )
V_17 -> V_146 = 1 ;
if ( F_43 ( & V_98 -> V_129 ) && F_42 ( V_14 ) )
V_17 -> V_147 = 1 ;
}
int F_44 ( struct V_13 * V_14 , int V_148 , int V_149 )
{
int V_150 , V_151 ;
V_14 -> V_29 = F_45 ( V_148 , V_149 , sizeof( int ) ) ;
if ( V_14 -> V_29 ) {
for ( V_150 = 0 ; V_150 < V_148 ; V_150 ++ ) {
for ( V_151 = 0 ; V_151 < V_149 ; V_151 ++ ) {
F_46 ( V_14 , V_150 , V_151 ) = - 1 ;
}
}
}
return V_14 -> V_29 != NULL ? 0 : - V_152 ;
}
int F_47 ( struct V_13 * V_14 , int V_148 , int V_149 ,
const char * V_153 )
{
int V_150 , V_151 ;
for ( V_150 = 0 ; V_150 < V_148 ; V_150 ++ ) {
for ( V_151 = 0 ; V_151 < V_149 ; V_151 ++ ) {
int V_29 = F_46 ( V_14 , V_150 , V_151 ) ,
V_83 = F_48 ( V_29 , V_154 , V_153 ) ;
if ( V_83 )
return V_83 ;
}
}
return 0 ;
}
int F_49 ( struct V_13 * V_14 , int V_148 , int V_149 )
{
V_14 -> V_155 = F_45 ( V_148 , V_149 , sizeof( struct V_156 ) ) ;
if ( V_14 -> V_155 == NULL )
return - V_152 ;
V_14 -> V_50 = F_11 ( V_148 * V_149 * sizeof( T_1 ) ) ;
if ( V_14 -> V_50 == NULL ) {
F_50 ( V_14 -> V_155 ) ;
V_14 -> V_155 = NULL ;
return - V_152 ;
}
return 0 ;
}
void F_51 ( struct V_13 * V_14 , int V_148 )
{
memset ( V_14 -> V_157 , 0 , ( sizeof( * V_14 -> V_157 ) +
( V_148 * sizeof( struct V_158 ) ) ) ) ;
}
int F_52 ( struct V_13 * V_14 , int V_148 )
{
V_14 -> V_157 = F_11 ( ( sizeof( * V_14 -> V_157 ) +
( V_148 * sizeof( struct V_158 ) ) ) ) ;
return V_14 -> V_157 != NULL ? 0 : - V_152 ;
}
void F_53 ( struct V_13 * V_14 )
{
F_50 ( V_14 -> V_29 ) ;
V_14 -> V_29 = NULL ;
}
void F_54 ( struct V_13 * V_14 )
{
F_50 ( V_14 -> V_155 ) ;
V_14 -> V_155 = NULL ;
free ( V_14 -> V_50 ) ;
V_14 -> V_50 = NULL ;
}
void F_55 ( struct V_13 * V_14 , int V_148 , int V_149 )
{
int V_150 , V_151 ;
for ( V_150 = 0 ; V_150 < V_148 ; V_150 ++ )
for ( V_151 = 0 ; V_151 < V_149 ; ++ V_151 ) {
F_17 ( F_46 ( V_14 , V_150 , V_151 ) ) ;
F_46 ( V_14 , V_150 , V_151 ) = - 1 ;
}
}
void F_56 ( struct V_13 * V_14 )
{
free ( V_14 -> V_157 ) ;
}
void F_57 ( struct V_13 * V_14 )
{
assert ( F_58 ( & V_14 -> V_25 ) ) ;
F_53 ( V_14 ) ;
F_54 ( V_14 ) ;
}
void F_59 ( struct V_13 * V_14 )
{
F_57 ( V_14 ) ;
F_60 ( V_14 -> V_159 ) ;
free ( V_14 -> V_94 ) ;
if ( V_14 -> V_48 )
F_61 ( V_14 -> V_48 ) ;
free ( V_14 -> V_28 ) ;
free ( V_14 ) ;
}
static inline void F_62 ( struct V_13 * V_14 ,
int V_150 ,
struct V_158 * V_160 )
{
struct V_158 V_161 ;
if ( ! V_14 -> V_162 )
return;
if ( V_150 == - 1 ) {
V_161 = V_14 -> V_162 -> V_163 ;
V_14 -> V_162 -> V_163 = * V_160 ;
} else {
V_161 = V_14 -> V_162 -> V_150 [ V_150 ] ;
V_14 -> V_162 -> V_150 [ V_150 ] = * V_160 ;
}
V_160 -> V_164 = V_160 -> V_164 - V_161 . V_164 ;
V_160 -> V_165 = V_160 -> V_165 - V_161 . V_165 ;
V_160 -> V_166 = V_160 -> V_166 - V_161 . V_166 ;
}
int F_63 ( struct V_13 * V_14 ,
int V_150 , int V_151 , bool V_167 )
{
struct V_158 V_160 ;
T_2 V_168 = V_167 ? 3 : 1 ;
if ( F_46 ( V_14 , V_150 , V_151 ) < 0 )
return - V_169 ;
if ( V_14 -> V_157 == NULL && F_52 ( V_14 , V_150 + 1 ) < 0 )
return - V_152 ;
if ( F_64 ( F_46 ( V_14 , V_150 , V_151 ) , & V_160 , V_168 * sizeof( T_1 ) ) < 0 )
return - V_170 ;
F_62 ( V_14 , V_150 , & V_160 ) ;
if ( V_167 ) {
if ( V_160 . V_166 == 0 )
V_160 . V_164 = 0 ;
else if ( V_160 . V_166 < V_160 . V_165 )
V_160 . V_164 = ( T_1 ) ( ( double ) V_160 . V_164 * V_160 . V_165 / V_160 . V_166 + 0.5 ) ;
} else
V_160 . V_165 = V_160 . V_166 = 0 ;
V_14 -> V_157 -> V_150 [ V_150 ] = V_160 ;
return 0 ;
}
int F_65 ( struct V_13 * V_14 ,
int V_148 , int V_149 , bool V_167 )
{
T_2 V_168 = V_167 ? 3 : 1 ;
int V_150 , V_151 ;
struct V_158 * V_163 = & V_14 -> V_157 -> V_163 , V_160 ;
V_163 -> V_164 = V_163 -> V_165 = V_163 -> V_166 = 0 ;
for ( V_150 = 0 ; V_150 < V_148 ; V_150 ++ ) {
for ( V_151 = 0 ; V_151 < V_149 ; V_151 ++ ) {
if ( F_46 ( V_14 , V_150 , V_151 ) < 0 )
continue;
if ( F_64 ( F_46 ( V_14 , V_150 , V_151 ) ,
& V_160 , V_168 * sizeof( T_1 ) ) < 0 )
return - V_170 ;
V_163 -> V_164 += V_160 . V_164 ;
if ( V_167 ) {
V_163 -> V_165 += V_160 . V_165 ;
V_163 -> V_166 += V_160 . V_166 ;
}
}
}
F_62 ( V_14 , - 1 , V_163 ) ;
V_14 -> V_157 -> V_171 = 0 ;
if ( V_167 ) {
if ( V_163 -> V_166 == 0 ) {
V_14 -> V_157 -> V_171 = - 1 ;
V_163 -> V_164 = 0 ;
return 0 ;
}
if ( V_163 -> V_166 < V_163 -> V_165 ) {
V_14 -> V_157 -> V_171 = 1 ;
V_163 -> V_164 = ( T_1 ) ( ( double ) V_163 -> V_164 * V_163 -> V_165 / V_163 -> V_166 + 0.5 ) ;
}
} else
V_163 -> V_165 = V_163 -> V_166 = 0 ;
return 0 ;
}
static int F_66 ( struct V_13 * V_14 , int V_150 , int V_151 )
{
struct V_13 * V_24 = V_14 -> V_24 ;
int V_29 ;
if ( F_42 ( V_14 ) )
return - 1 ;
F_67 ( ! V_24 -> V_29 ) ;
V_29 = F_46 ( V_24 , V_150 , V_151 ) ;
F_67 ( V_29 == - 1 ) ;
return V_29 ;
}
static int F_68 ( struct V_13 * V_14 , struct V_172 * V_173 ,
struct V_174 * V_175 )
{
int V_150 , V_151 ;
unsigned long V_176 = 0 ;
int V_177 = - 1 , V_83 ;
if ( V_14 -> V_29 == NULL &&
F_44 ( V_14 , V_173 -> V_178 , V_175 -> V_178 ) < 0 )
return - V_152 ;
if ( V_14 -> V_159 ) {
V_176 = V_179 ;
V_177 = V_14 -> V_159 -> V_29 ;
}
V_180:
if ( V_101 . V_65 )
V_14 -> V_17 . V_65 = V_14 -> V_17 . V_64 = 0 ;
V_181:
if ( V_101 . V_100 )
V_14 -> V_17 . V_100 = 0 ;
for ( V_150 = 0 ; V_150 < V_173 -> V_178 ; V_150 ++ ) {
for ( V_151 = 0 ; V_151 < V_175 -> V_178 ; V_151 ++ ) {
int V_182 ;
if ( ! V_14 -> V_159 )
V_177 = V_175 -> V_183 [ V_151 ] ;
V_182 = F_66 ( V_14 , V_150 , V_151 ) ;
F_46 ( V_14 , V_150 , V_151 ) = F_69 ( & V_14 -> V_17 ,
V_177 ,
V_173 -> V_183 [ V_150 ] ,
V_182 , V_176 ) ;
if ( F_46 ( V_14 , V_150 , V_151 ) < 0 ) {
V_83 = - V_170 ;
goto V_184;
}
}
}
return 0 ;
V_184:
if ( V_83 != - V_169 || V_150 > 0 || V_151 > 0 )
goto V_185;
if ( ! V_101 . V_65 &&
( V_14 -> V_17 . V_65 || V_14 -> V_17 . V_64 ) ) {
V_101 . V_65 = true ;
goto V_180;
} else if ( ! V_101 . V_100 ) {
V_101 . V_100 = true ;
goto V_181;
}
V_185:
do {
while ( -- V_151 >= 0 ) {
F_17 ( F_46 ( V_14 , V_150 , V_151 ) ) ;
F_46 ( V_14 , V_150 , V_151 ) = - 1 ;
}
V_151 = V_175 -> V_178 ;
} while ( -- V_150 >= 0 );
return V_83 ;
}
void F_70 ( struct V_13 * V_14 , int V_148 , int V_149 )
{
if ( V_14 -> V_29 == NULL )
return;
F_55 ( V_14 , V_148 , V_149 ) ;
F_53 ( V_14 ) ;
V_14 -> V_29 = NULL ;
}
int F_71 ( struct V_13 * V_14 , struct V_172 * V_173 ,
struct V_174 * V_175 )
{
if ( V_173 == NULL ) {
V_173 = & V_186 . V_183 ;
}
if ( V_175 == NULL )
V_175 = & V_187 . V_183 ;
return F_68 ( V_14 , V_173 , V_175 ) ;
}
int F_72 ( struct V_13 * V_14 ,
struct V_172 * V_173 )
{
return F_68 ( V_14 , V_173 , & V_187 . V_183 ) ;
}
int F_73 ( struct V_13 * V_14 ,
struct V_174 * V_175 )
{
return F_68 ( V_14 , & V_186 . V_183 , V_175 ) ;
}
static int F_74 ( const struct V_13 * V_14 ,
const union V_188 * V_189 ,
struct V_190 * V_191 )
{
T_1 type = V_14 -> V_17 . V_1 ;
const T_1 * V_192 = V_189 -> V_191 . V_192 ;
bool V_193 = V_14 -> V_194 ;
union V_195 V_196 ;
V_192 += ( ( V_189 -> V_197 . V_4 -
sizeof( V_189 -> V_197 ) ) / sizeof( T_1 ) ) - 1 ;
if ( type & V_45 ) {
V_196 . V_198 = * V_192 ;
if ( V_193 ) {
V_196 . V_198 = F_75 ( V_196 . V_198 ) ;
V_196 . V_199 [ 0 ] = F_76 ( V_196 . V_199 [ 0 ] ) ;
}
V_191 -> V_150 = V_196 . V_199 [ 0 ] ;
V_192 -- ;
}
if ( type & V_200 ) {
V_191 -> V_201 = * V_192 ;
V_192 -- ;
}
if ( type & V_202 ) {
V_191 -> V_50 = * V_192 ;
V_192 -- ;
}
if ( type & V_44 ) {
V_191 -> time = * V_192 ;
V_192 -- ;
}
if ( type & V_203 ) {
V_196 . V_198 = * V_192 ;
if ( V_193 ) {
V_196 . V_198 = F_75 ( V_196 . V_198 ) ;
V_196 . V_199 [ 0 ] = F_76 ( V_196 . V_199 [ 0 ] ) ;
V_196 . V_199 [ 1 ] = F_76 ( V_196 . V_199 [ 1 ] ) ;
}
V_191 -> V_177 = V_196 . V_199 [ 0 ] ;
V_191 -> V_204 = V_196 . V_199 [ 1 ] ;
}
return 0 ;
}
static bool F_77 ( const union V_188 * V_189 ,
const void * V_205 , T_1 V_4 )
{
const void * V_206 = V_189 ;
if ( V_205 + V_4 > V_206 + V_189 -> V_197 . V_4 )
return true ;
return false ;
}
int F_78 ( struct V_13 * V_14 , union V_188 * V_189 ,
struct V_190 * V_207 )
{
T_1 type = V_14 -> V_17 . V_1 ;
T_1 V_208 = V_14 -> V_17 . V_124 ;
bool V_193 = V_14 -> V_194 ;
const T_1 * V_192 ;
union V_195 V_196 ;
memset ( V_207 , 0 , sizeof( * V_207 ) ) ;
V_207 -> V_150 = V_207 -> V_177 = V_207 -> V_204 = - 1 ;
V_207 -> V_201 = V_207 -> V_50 = V_207 -> time = - 1ULL ;
V_207 -> V_131 = 1 ;
V_207 -> V_209 = 0 ;
if ( V_189 -> V_197 . type != V_210 ) {
if ( ! V_14 -> V_17 . V_100 )
return 0 ;
return F_74 ( V_14 , V_189 , V_207 ) ;
}
V_192 = V_189 -> V_191 . V_192 ;
if ( V_14 -> V_18 + sizeof( V_189 -> V_197 ) > V_189 -> V_197 . V_4 )
return - V_211 ;
if ( type & V_212 ) {
V_207 -> V_213 = V_189 -> V_213 . V_213 ;
V_192 ++ ;
}
if ( type & V_203 ) {
V_196 . V_198 = * V_192 ;
if ( V_193 ) {
V_196 . V_198 = F_75 ( V_196 . V_198 ) ;
V_196 . V_199 [ 0 ] = F_76 ( V_196 . V_199 [ 0 ] ) ;
V_196 . V_199 [ 1 ] = F_76 ( V_196 . V_199 [ 1 ] ) ;
}
V_207 -> V_177 = V_196 . V_199 [ 0 ] ;
V_207 -> V_204 = V_196 . V_199 [ 1 ] ;
V_192 ++ ;
}
if ( type & V_44 ) {
V_207 -> time = * V_192 ;
V_192 ++ ;
}
V_207 -> V_70 = 0 ;
if ( type & V_214 ) {
V_207 -> V_70 = * V_192 ;
V_192 ++ ;
}
V_207 -> V_50 = - 1ULL ;
if ( type & V_202 ) {
V_207 -> V_50 = * V_192 ;
V_192 ++ ;
}
if ( type & V_200 ) {
V_207 -> V_201 = * V_192 ;
V_192 ++ ;
}
if ( type & V_45 ) {
V_196 . V_198 = * V_192 ;
if ( V_193 ) {
V_196 . V_198 = F_75 ( V_196 . V_198 ) ;
V_196 . V_199 [ 0 ] = F_76 ( V_196 . V_199 [ 0 ] ) ;
}
V_207 -> V_150 = V_196 . V_199 [ 0 ] ;
V_192 ++ ;
}
if ( type & V_46 ) {
V_207 -> V_131 = * V_192 ;
V_192 ++ ;
}
if ( type & V_215 ) {
fprintf ( V_216 , L_27 ) ;
return - 1 ;
}
if ( type & V_217 ) {
if ( F_77 ( V_189 , V_192 , sizeof( V_207 -> V_218 -> V_178 ) ) )
return - V_211 ;
V_207 -> V_218 = (struct V_219 * ) V_192 ;
if ( F_77 ( V_189 , V_192 , V_207 -> V_218 -> V_178 ) )
return - V_211 ;
V_192 += 1 + V_207 -> V_218 -> V_178 ;
}
if ( type & V_43 ) {
const T_1 * V_220 ;
V_196 . V_198 = * V_192 ;
if ( F_79 ( V_193 ,
L_28 ) ) {
V_196 . V_198 = F_75 ( V_196 . V_198 ) ;
V_196 . V_199 [ 0 ] = F_76 ( V_196 . V_199 [ 0 ] ) ;
V_196 . V_199 [ 1 ] = F_76 ( V_196 . V_199 [ 1 ] ) ;
}
if ( F_77 ( V_189 , V_192 , sizeof( V_221 ) ) )
return - V_211 ;
V_207 -> V_222 = V_196 . V_199 [ 0 ] ;
V_220 = ( void * ) V_192 + sizeof( V_221 ) ;
if ( F_77 ( V_189 , V_220 , V_207 -> V_222 ) )
return - V_211 ;
V_207 -> V_223 = ( void * ) V_220 ;
V_192 = ( void * ) V_192 + V_207 -> V_222 + sizeof( V_221 ) ;
}
if ( type & V_224 ) {
T_1 V_225 ;
V_207 -> V_139 = (struct V_139 * ) V_192 ;
V_192 ++ ;
V_225 = V_207 -> V_139 -> V_178 * sizeof( struct V_226 ) ;
V_225 /= sizeof( T_1 ) ;
V_192 += V_225 ;
}
if ( type & V_227 ) {
T_1 V_228 = * V_192 ++ ;
if ( V_228 ) {
V_207 -> V_229 . V_230 = ( T_1 * ) V_192 ;
V_192 += F_80 ( V_208 ) ;
}
}
if ( type & V_231 ) {
T_1 V_4 = * V_192 ++ ;
V_207 -> V_232 . V_205 = ( ( char * ) ( V_192 - 1 )
- ( char * ) V_189 ) ;
if ( ! V_4 ) {
V_207 -> V_232 . V_4 = 0 ;
} else {
V_207 -> V_232 . V_207 = ( char * ) V_192 ;
V_192 += V_4 / sizeof( * V_192 ) ;
V_207 -> V_232 . V_4 = * V_192 ++ ;
}
}
V_207 -> V_209 = 0 ;
if ( type & V_143 ) {
V_207 -> V_209 = * V_192 ;
V_192 ++ ;
}
V_207 -> V_233 = V_234 ;
if ( type & V_135 ) {
V_207 -> V_233 = * V_192 ;
V_192 ++ ;
}
return 0 ;
}
int F_81 ( union V_188 * V_189 , T_1 type ,
const struct V_190 * V_191 ,
bool V_193 )
{
T_1 * V_192 ;
union V_195 V_196 ;
V_192 = V_189 -> V_191 . V_192 ;
if ( type & V_212 ) {
V_189 -> V_213 . V_213 = V_191 -> V_213 ;
V_192 ++ ;
}
if ( type & V_203 ) {
V_196 . V_199 [ 0 ] = V_191 -> V_177 ;
V_196 . V_199 [ 1 ] = V_191 -> V_204 ;
if ( V_193 ) {
V_196 . V_199 [ 0 ] = F_76 ( V_196 . V_199 [ 0 ] ) ;
V_196 . V_199 [ 1 ] = F_76 ( V_196 . V_199 [ 1 ] ) ;
V_196 . V_198 = F_75 ( V_196 . V_198 ) ;
}
* V_192 = V_196 . V_198 ;
V_192 ++ ;
}
if ( type & V_44 ) {
* V_192 = V_191 -> time ;
V_192 ++ ;
}
if ( type & V_214 ) {
* V_192 = V_191 -> V_70 ;
V_192 ++ ;
}
if ( type & V_202 ) {
* V_192 = V_191 -> V_50 ;
V_192 ++ ;
}
if ( type & V_200 ) {
* V_192 = V_191 -> V_201 ;
V_192 ++ ;
}
if ( type & V_45 ) {
V_196 . V_199 [ 0 ] = V_191 -> V_150 ;
if ( V_193 ) {
V_196 . V_199 [ 0 ] = F_76 ( V_196 . V_199 [ 0 ] ) ;
V_196 . V_198 = F_75 ( V_196 . V_198 ) ;
}
* V_192 = V_196 . V_198 ;
V_192 ++ ;
}
if ( type & V_46 ) {
* V_192 = V_191 -> V_131 ;
V_192 ++ ;
}
return 0 ;
}
struct V_235 * F_82 ( struct V_13 * V_14 , const char * V_28 )
{
return F_83 ( V_14 -> V_48 , V_28 ) ;
}
void * F_84 ( struct V_13 * V_14 , struct V_190 * V_191 ,
const char * V_28 )
{
struct V_235 * V_236 = F_82 ( V_14 , V_28 ) ;
int V_205 ;
if ( ! V_236 )
return NULL ;
V_205 = V_236 -> V_205 ;
if ( V_236 -> V_176 & V_237 ) {
V_205 = * ( int * ) ( V_191 -> V_223 + V_236 -> V_205 ) ;
V_205 &= 0xffff ;
}
return V_191 -> V_223 + V_205 ;
}
T_1 F_85 ( struct V_13 * V_14 , struct V_190 * V_191 ,
const char * V_28 )
{
struct V_235 * V_236 = F_82 ( V_14 , V_28 ) ;
void * V_238 ;
T_1 V_239 ;
if ( ! V_236 )
return 0 ;
V_238 = V_191 -> V_223 + V_236 -> V_205 ;
switch ( V_236 -> V_4 ) {
case 1 :
return * ( T_5 * ) V_238 ;
case 2 :
V_239 = * ( V_240 * ) V_238 ;
break;
case 4 :
V_239 = * ( V_221 * ) V_238 ;
break;
case 8 :
V_239 = * ( T_1 * ) V_238 ;
break;
default:
return 0 ;
}
if ( ! V_14 -> V_194 )
return V_239 ;
switch ( V_236 -> V_4 ) {
case 2 :
return F_86 ( V_239 ) ;
case 4 :
return F_76 ( V_239 ) ;
case 8 :
return F_75 ( V_239 ) ;
default:
return 0 ;
}
return 0 ;
}
static int F_87 ( T_6 * V_241 , bool * V_242 , const char * V_243 , ... )
{
T_7 args ;
int V_88 = 0 ;
if ( ! * V_242 ) {
V_88 += fprintf ( V_241 , L_29 ) ;
} else {
V_88 += fprintf ( V_241 , L_9 ) ;
* V_242 = false ;
}
va_start ( args , V_243 ) ;
V_88 += vfprintf ( V_241 , V_243 , args ) ;
va_end ( args ) ;
return V_88 ;
}
static int F_88 ( T_6 * V_241 , bool * V_242 , const char * V_236 , T_1 V_239 )
{
if ( V_239 == 0 )
return 0 ;
return F_87 ( V_241 , V_242 , L_30 V_244 , V_236 , V_239 ) ;
}
static int F_89 ( T_6 * V_241 , const char * V_236 , T_1 V_239 ,
struct V_245 * V_246 , bool * V_242 )
{
int V_5 = 0 , V_247 = F_87 ( V_241 , V_242 , L_31 , V_236 ) ;
bool V_248 = true ;
do {
if ( V_239 & V_246 [ V_5 ] . V_16 ) {
V_247 += fprintf ( V_241 , L_32 , V_248 ? L_33 : L_34 , V_246 [ V_5 ] . V_28 ) ;
V_248 = false ;
}
} while ( V_246 [ ++ V_5 ] . V_28 != NULL );
return V_247 ;
}
static int F_90 ( T_6 * V_241 , bool * V_242 , T_1 V_239 )
{
#define F_91 ( V_30 ) { PERF_SAMPLE_##n, #n }
struct V_245 V_246 [] = {
F_91 ( V_104 ) , F_91 ( V_105 ) , F_91 ( TIME ) , F_91 ( V_117 ) ,
F_91 ( V_249 ) , F_91 ( V_120 ) , F_91 ( V_19 ) , F_91 ( V_130 ) ,
F_91 ( V_111 ) , F_91 ( V_250 ) , F_91 ( V_134 ) ,
F_91 ( V_140 ) , F_91 ( V_122 ) , F_91 ( V_123 ) ,
{ . V_28 = NULL , }
} ;
#undef F_91
return F_89 ( V_241 , L_35 , V_239 , V_246 , V_242 ) ;
}
static int F_92 ( T_6 * V_241 , bool * V_242 , T_1 V_239 )
{
#define F_91 ( V_30 ) { PERF_FORMAT_##n, #n }
struct V_245 V_246 [] = {
F_91 ( V_251 ) , F_91 ( V_252 ) ,
F_91 ( V_19 ) , F_91 ( V_253 ) ,
{ . V_28 = NULL , }
} ;
#undef F_91
return F_89 ( V_241 , L_36 , V_239 , V_246 , V_242 ) ;
}
int F_93 ( struct V_13 * V_14 ,
struct V_254 * V_255 , T_6 * V_241 )
{
bool V_242 = true ;
int V_247 = 0 ;
if ( V_255 -> V_256 ) {
struct V_13 * V_96 ;
if ( ! F_42 ( V_14 ) )
return 0 ;
if ( V_14 -> V_257 > 1 )
V_247 += fprintf ( V_241 , L_37 , V_14 -> V_94 ? : L_33 ) ;
V_247 += fprintf ( V_241 , L_6 , F_35 ( V_14 ) ) ;
F_39 (pos, evsel)
V_247 += fprintf ( V_241 , L_38 , F_35 ( V_96 ) ) ;
if ( V_14 -> V_257 > 1 )
V_247 += fprintf ( V_241 , L_39 ) ;
goto V_37;
}
V_247 += fprintf ( V_241 , L_6 , F_35 ( V_14 ) ) ;
if ( V_255 -> V_258 || V_255 -> V_110 ) {
V_247 += F_87 ( V_241 , & V_242 , L_40 V_244 ,
( T_1 ) V_14 -> V_17 . V_112 ) ;
}
if ( V_255 -> V_258 ) {
F_94 ( type ) ;
F_94 ( V_49 ) ;
F_94 ( V_259 ) ;
F_94 ( V_260 ) ;
F_94 ( V_4 ) ;
V_247 += F_90 ( V_241 , & V_242 , V_14 -> V_17 . V_1 ) ;
if ( V_14 -> V_17 . V_20 )
V_247 += F_92 ( V_241 , & V_242 , V_14 -> V_17 . V_20 ) ;
F_94 ( V_146 ) ;
F_94 ( V_102 ) ;
F_94 ( V_261 ) ;
F_94 ( V_262 ) ;
F_94 ( V_58 ) ;
F_94 ( V_57 ) ;
F_94 ( V_59 ) ;
F_94 ( V_263 ) ;
F_94 ( V_144 ) ;
F_94 ( V_145 ) ;
F_94 ( V_110 ) ;
F_94 ( V_115 ) ;
F_94 ( V_147 ) ;
F_94 ( V_264 ) ;
F_94 ( V_137 ) ;
F_94 ( V_63 ) ;
F_94 ( V_118 ) ;
F_94 ( V_100 ) ;
F_94 ( V_64 ) ;
F_94 ( V_65 ) ;
F_94 ( V_265 ) ;
F_94 ( V_138 ) ;
F_94 ( V_76 ) ;
F_94 ( V_141 ) ;
}
V_37:
fputc ( '\n' , V_241 ) ;
return ++ V_247 ;
}
bool F_95 ( struct V_13 * V_14 , int V_83 ,
char * V_266 , T_2 V_267 )
{
if ( ( V_83 == V_268 || V_83 == V_269 ) &&
V_14 -> V_17 . type == V_90 &&
V_14 -> V_17 . V_49 == V_270 ) {
F_23 ( V_266 , V_267 , L_6 ,
L_41 ) ;
V_14 -> V_17 . type = V_92 ;
V_14 -> V_17 . V_49 = V_271 ;
free ( V_14 -> V_28 ) ;
V_14 -> V_28 = NULL ;
return true ;
}
return false ;
}
int F_96 ( struct V_13 * V_14 ,
struct V_272 * V_129 ,
int V_83 , char * V_266 , T_2 V_4 )
{
switch ( V_83 ) {
case V_273 :
case V_274 :
return F_23 ( V_266 , V_4 ,
L_42
L_43
L_44
L_45
L_46
L_47 ,
V_129 -> V_275 ? L_48 : L_33 ) ;
case V_268 :
return F_23 ( V_266 , V_4 , L_49 ,
F_35 ( V_14 ) ) ;
case V_276 :
return F_23 ( V_266 , V_4 , L_6 ,
L_50
L_51 ) ;
case V_277 :
if ( V_129 -> V_278 )
return F_23 ( V_266 , V_4 , L_6 ,
L_52 ) ;
break;
case V_279 :
if ( V_14 -> V_17 . V_63 )
return F_23 ( V_266 , V_4 , L_6 ,
L_53 ) ;
#if F_97 ( V_280 ) || F_97 ( V_281 )
if ( V_14 -> V_17 . type == V_90 )
return F_23 ( V_266 , V_4 , L_6 ,
L_54
L_55 ) ;
#endif
break;
default:
break;
}
return F_23 ( V_266 , V_4 ,
L_56
L_57
L_58 ,
V_83 , strerror ( V_83 ) , F_35 ( V_14 ) ) ;
}
