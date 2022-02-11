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
V_30 = F_15 ( V_29 , V_32 + V_4 , V_40 ) ;
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
if ( V_98 -> V_135 ) {
V_17 -> V_136 = 0 ;
V_17 -> V_137 = 1 ;
}
if ( V_98 -> V_138 ) {
F_7 ( V_14 , V_139 ) ;
V_17 -> V_140 = V_98 -> V_138 ;
}
V_17 -> V_141 = V_99 ;
V_17 -> V_142 = V_99 ;
if ( F_42 ( V_14 ) )
V_17 -> V_143 = 1 ;
if ( F_43 ( & V_98 -> V_129 ) && F_42 ( V_14 ) )
V_17 -> V_144 = 1 ;
}
int F_44 ( struct V_13 * V_14 , int V_145 , int V_146 )
{
int V_147 , V_148 ;
V_14 -> V_29 = F_45 ( V_145 , V_146 , sizeof( int ) ) ;
if ( V_14 -> V_29 ) {
for ( V_147 = 0 ; V_147 < V_145 ; V_147 ++ ) {
for ( V_148 = 0 ; V_148 < V_146 ; V_148 ++ ) {
F_46 ( V_14 , V_147 , V_148 ) = - 1 ;
}
}
}
return V_14 -> V_29 != NULL ? 0 : - V_149 ;
}
int F_47 ( struct V_13 * V_14 , int V_145 , int V_146 ,
const char * V_150 )
{
int V_147 , V_148 ;
for ( V_147 = 0 ; V_147 < V_145 ; V_147 ++ ) {
for ( V_148 = 0 ; V_148 < V_146 ; V_148 ++ ) {
int V_29 = F_46 ( V_14 , V_147 , V_148 ) ,
V_83 = F_48 ( V_29 , V_151 , V_150 ) ;
if ( V_83 )
return V_83 ;
}
}
return 0 ;
}
int F_49 ( struct V_13 * V_14 , int V_145 , int V_146 )
{
V_14 -> V_152 = F_45 ( V_145 , V_146 , sizeof( struct V_153 ) ) ;
if ( V_14 -> V_152 == NULL )
return - V_149 ;
V_14 -> V_50 = F_11 ( V_145 * V_146 * sizeof( T_1 ) ) ;
if ( V_14 -> V_50 == NULL ) {
F_50 ( V_14 -> V_152 ) ;
V_14 -> V_152 = NULL ;
return - V_149 ;
}
return 0 ;
}
int F_51 ( struct V_13 * V_14 , int V_145 )
{
V_14 -> V_154 = F_11 ( ( sizeof( * V_14 -> V_154 ) +
( V_145 * sizeof( struct V_155 ) ) ) ) ;
return V_14 -> V_154 != NULL ? 0 : - V_149 ;
}
void F_52 ( struct V_13 * V_14 )
{
F_50 ( V_14 -> V_29 ) ;
V_14 -> V_29 = NULL ;
}
void F_53 ( struct V_13 * V_14 )
{
F_50 ( V_14 -> V_152 ) ;
V_14 -> V_152 = NULL ;
free ( V_14 -> V_50 ) ;
V_14 -> V_50 = NULL ;
}
void F_54 ( struct V_13 * V_14 , int V_145 , int V_146 )
{
int V_147 , V_148 ;
for ( V_147 = 0 ; V_147 < V_145 ; V_147 ++ )
for ( V_148 = 0 ; V_148 < V_146 ; ++ V_148 ) {
F_17 ( F_46 ( V_14 , V_147 , V_148 ) ) ;
F_46 ( V_14 , V_147 , V_148 ) = - 1 ;
}
}
void F_55 ( struct V_13 * V_14 )
{
free ( V_14 -> V_154 ) ;
}
void F_56 ( struct V_13 * V_14 )
{
assert ( F_57 ( & V_14 -> V_25 ) ) ;
F_50 ( V_14 -> V_29 ) ;
F_50 ( V_14 -> V_152 ) ;
free ( V_14 -> V_50 ) ;
}
void F_58 ( struct V_13 * V_14 )
{
F_56 ( V_14 ) ;
F_59 ( V_14 -> V_156 ) ;
free ( V_14 -> V_94 ) ;
if ( V_14 -> V_48 )
F_60 ( V_14 -> V_48 ) ;
free ( V_14 -> V_28 ) ;
free ( V_14 ) ;
}
static inline void F_61 ( struct V_13 * V_14 ,
int V_147 ,
struct V_155 * V_157 )
{
struct V_155 V_158 ;
if ( ! V_14 -> V_159 )
return;
if ( V_147 == - 1 ) {
V_158 = V_14 -> V_159 -> V_160 ;
V_14 -> V_159 -> V_160 = * V_157 ;
} else {
V_158 = V_14 -> V_159 -> V_147 [ V_147 ] ;
V_14 -> V_159 -> V_147 [ V_147 ] = * V_157 ;
}
V_157 -> V_161 = V_157 -> V_161 - V_158 . V_161 ;
V_157 -> V_162 = V_157 -> V_162 - V_158 . V_162 ;
V_157 -> V_163 = V_157 -> V_163 - V_158 . V_163 ;
}
int F_62 ( struct V_13 * V_14 ,
int V_147 , int V_148 , bool V_164 )
{
struct V_155 V_157 ;
T_2 V_165 = V_164 ? 3 : 1 ;
if ( F_46 ( V_14 , V_147 , V_148 ) < 0 )
return - V_166 ;
if ( V_14 -> V_154 == NULL && F_51 ( V_14 , V_147 + 1 ) < 0 )
return - V_149 ;
if ( F_63 ( F_46 ( V_14 , V_147 , V_148 ) , & V_157 , V_165 * sizeof( T_1 ) ) < 0 )
return - V_167 ;
F_61 ( V_14 , V_147 , & V_157 ) ;
if ( V_164 ) {
if ( V_157 . V_163 == 0 )
V_157 . V_161 = 0 ;
else if ( V_157 . V_163 < V_157 . V_162 )
V_157 . V_161 = ( T_1 ) ( ( double ) V_157 . V_161 * V_157 . V_162 / V_157 . V_163 + 0.5 ) ;
} else
V_157 . V_162 = V_157 . V_163 = 0 ;
V_14 -> V_154 -> V_147 [ V_147 ] = V_157 ;
return 0 ;
}
int F_64 ( struct V_13 * V_14 ,
int V_145 , int V_146 , bool V_164 )
{
T_2 V_165 = V_164 ? 3 : 1 ;
int V_147 , V_148 ;
struct V_155 * V_160 = & V_14 -> V_154 -> V_160 , V_157 ;
V_160 -> V_161 = V_160 -> V_162 = V_160 -> V_163 = 0 ;
for ( V_147 = 0 ; V_147 < V_145 ; V_147 ++ ) {
for ( V_148 = 0 ; V_148 < V_146 ; V_148 ++ ) {
if ( F_46 ( V_14 , V_147 , V_148 ) < 0 )
continue;
if ( F_63 ( F_46 ( V_14 , V_147 , V_148 ) ,
& V_157 , V_165 * sizeof( T_1 ) ) < 0 )
return - V_167 ;
V_160 -> V_161 += V_157 . V_161 ;
if ( V_164 ) {
V_160 -> V_162 += V_157 . V_162 ;
V_160 -> V_163 += V_157 . V_163 ;
}
}
}
F_61 ( V_14 , - 1 , V_160 ) ;
V_14 -> V_154 -> V_168 = 0 ;
if ( V_164 ) {
if ( V_160 -> V_163 == 0 ) {
V_14 -> V_154 -> V_168 = - 1 ;
V_160 -> V_161 = 0 ;
return 0 ;
}
if ( V_160 -> V_163 < V_160 -> V_162 ) {
V_14 -> V_154 -> V_168 = 1 ;
V_160 -> V_161 = ( T_1 ) ( ( double ) V_160 -> V_161 * V_160 -> V_162 / V_160 -> V_163 + 0.5 ) ;
}
} else
V_160 -> V_162 = V_160 -> V_163 = 0 ;
return 0 ;
}
static int F_65 ( struct V_13 * V_14 , int V_147 , int V_148 )
{
struct V_13 * V_24 = V_14 -> V_24 ;
int V_29 ;
if ( F_42 ( V_14 ) )
return - 1 ;
F_66 ( ! V_24 -> V_29 ) ;
V_29 = F_46 ( V_24 , V_147 , V_148 ) ;
F_66 ( V_29 == - 1 ) ;
return V_29 ;
}
static int F_67 ( struct V_13 * V_14 , struct V_169 * V_170 ,
struct V_171 * V_172 )
{
int V_147 , V_148 ;
unsigned long V_173 = 0 ;
int V_174 = - 1 , V_83 ;
if ( V_14 -> V_29 == NULL &&
F_44 ( V_14 , V_170 -> V_175 , V_172 -> V_175 ) < 0 )
return - V_149 ;
if ( V_14 -> V_156 ) {
V_173 = V_176 ;
V_174 = V_14 -> V_156 -> V_29 ;
}
V_177:
if ( V_101 . V_65 )
V_14 -> V_17 . V_65 = V_14 -> V_17 . V_64 = 0 ;
V_178:
if ( V_101 . V_100 )
V_14 -> V_17 . V_100 = 0 ;
for ( V_147 = 0 ; V_147 < V_170 -> V_175 ; V_147 ++ ) {
for ( V_148 = 0 ; V_148 < V_172 -> V_175 ; V_148 ++ ) {
int V_179 ;
if ( ! V_14 -> V_156 )
V_174 = V_172 -> V_180 [ V_148 ] ;
V_179 = F_65 ( V_14 , V_147 , V_148 ) ;
F_46 ( V_14 , V_147 , V_148 ) = F_68 ( & V_14 -> V_17 ,
V_174 ,
V_170 -> V_180 [ V_147 ] ,
V_179 , V_173 ) ;
if ( F_46 ( V_14 , V_147 , V_148 ) < 0 ) {
V_83 = - V_167 ;
goto V_181;
}
}
}
return 0 ;
V_181:
if ( V_83 != - V_166 || V_147 > 0 || V_148 > 0 )
goto V_182;
if ( ! V_101 . V_65 &&
( V_14 -> V_17 . V_65 || V_14 -> V_17 . V_64 ) ) {
V_101 . V_65 = true ;
goto V_177;
} else if ( ! V_101 . V_100 ) {
V_101 . V_100 = true ;
goto V_178;
}
V_182:
do {
while ( -- V_148 >= 0 ) {
F_17 ( F_46 ( V_14 , V_147 , V_148 ) ) ;
F_46 ( V_14 , V_147 , V_148 ) = - 1 ;
}
V_148 = V_172 -> V_175 ;
} while ( -- V_147 >= 0 );
return V_83 ;
}
void F_69 ( struct V_13 * V_14 , int V_145 , int V_146 )
{
if ( V_14 -> V_29 == NULL )
return;
F_54 ( V_14 , V_145 , V_146 ) ;
F_52 ( V_14 ) ;
V_14 -> V_29 = NULL ;
}
int F_70 ( struct V_13 * V_14 , struct V_169 * V_170 ,
struct V_171 * V_172 )
{
if ( V_170 == NULL ) {
V_170 = & V_183 . V_180 ;
}
if ( V_172 == NULL )
V_172 = & V_184 . V_180 ;
return F_67 ( V_14 , V_170 , V_172 ) ;
}
int F_71 ( struct V_13 * V_14 ,
struct V_169 * V_170 )
{
return F_67 ( V_14 , V_170 , & V_184 . V_180 ) ;
}
int F_72 ( struct V_13 * V_14 ,
struct V_171 * V_172 )
{
return F_67 ( V_14 , & V_183 . V_180 , V_172 ) ;
}
static int F_73 ( const struct V_13 * V_14 ,
const union V_185 * V_186 ,
struct V_187 * V_188 )
{
T_1 type = V_14 -> V_17 . V_1 ;
const T_1 * V_189 = V_186 -> V_188 . V_189 ;
bool V_190 = V_14 -> V_191 ;
union V_192 V_193 ;
V_189 += ( ( V_186 -> V_194 . V_4 -
sizeof( V_186 -> V_194 ) ) / sizeof( T_1 ) ) - 1 ;
if ( type & V_45 ) {
V_193 . V_195 = * V_189 ;
if ( V_190 ) {
V_193 . V_195 = F_74 ( V_193 . V_195 ) ;
V_193 . V_196 [ 0 ] = F_75 ( V_193 . V_196 [ 0 ] ) ;
}
V_188 -> V_147 = V_193 . V_196 [ 0 ] ;
V_189 -- ;
}
if ( type & V_197 ) {
V_188 -> V_198 = * V_189 ;
V_189 -- ;
}
if ( type & V_199 ) {
V_188 -> V_50 = * V_189 ;
V_189 -- ;
}
if ( type & V_44 ) {
V_188 -> time = * V_189 ;
V_189 -- ;
}
if ( type & V_200 ) {
V_193 . V_195 = * V_189 ;
if ( V_190 ) {
V_193 . V_195 = F_74 ( V_193 . V_195 ) ;
V_193 . V_196 [ 0 ] = F_75 ( V_193 . V_196 [ 0 ] ) ;
V_193 . V_196 [ 1 ] = F_75 ( V_193 . V_196 [ 1 ] ) ;
}
V_188 -> V_174 = V_193 . V_196 [ 0 ] ;
V_188 -> V_201 = V_193 . V_196 [ 1 ] ;
}
return 0 ;
}
static bool F_76 ( const union V_185 * V_186 ,
const void * V_202 , T_1 V_4 )
{
const void * V_203 = V_186 ;
if ( V_202 + V_4 > V_203 + V_186 -> V_194 . V_4 )
return true ;
return false ;
}
int F_77 ( struct V_13 * V_14 , union V_185 * V_186 ,
struct V_187 * V_204 )
{
T_1 type = V_14 -> V_17 . V_1 ;
T_1 V_205 = V_14 -> V_17 . V_124 ;
bool V_190 = V_14 -> V_191 ;
const T_1 * V_189 ;
union V_192 V_193 ;
memset ( V_204 , 0 , sizeof( * V_204 ) ) ;
V_204 -> V_147 = V_204 -> V_174 = V_204 -> V_201 = - 1 ;
V_204 -> V_198 = V_204 -> V_50 = V_204 -> time = - 1ULL ;
V_204 -> V_131 = 1 ;
if ( V_186 -> V_194 . type != V_206 ) {
if ( ! V_14 -> V_17 . V_100 )
return 0 ;
return F_73 ( V_14 , V_186 , V_204 ) ;
}
V_189 = V_186 -> V_188 . V_189 ;
if ( V_14 -> V_18 + sizeof( V_186 -> V_194 ) > V_186 -> V_194 . V_4 )
return - V_207 ;
if ( type & V_208 ) {
V_204 -> V_209 = V_186 -> V_209 . V_209 ;
V_189 ++ ;
}
if ( type & V_200 ) {
V_193 . V_195 = * V_189 ;
if ( V_190 ) {
V_193 . V_195 = F_74 ( V_193 . V_195 ) ;
V_193 . V_196 [ 0 ] = F_75 ( V_193 . V_196 [ 0 ] ) ;
V_193 . V_196 [ 1 ] = F_75 ( V_193 . V_196 [ 1 ] ) ;
}
V_204 -> V_174 = V_193 . V_196 [ 0 ] ;
V_204 -> V_201 = V_193 . V_196 [ 1 ] ;
V_189 ++ ;
}
if ( type & V_44 ) {
V_204 -> time = * V_189 ;
V_189 ++ ;
}
V_204 -> V_70 = 0 ;
if ( type & V_210 ) {
V_204 -> V_70 = * V_189 ;
V_189 ++ ;
}
V_204 -> V_50 = - 1ULL ;
if ( type & V_199 ) {
V_204 -> V_50 = * V_189 ;
V_189 ++ ;
}
if ( type & V_197 ) {
V_204 -> V_198 = * V_189 ;
V_189 ++ ;
}
if ( type & V_45 ) {
V_193 . V_195 = * V_189 ;
if ( V_190 ) {
V_193 . V_195 = F_74 ( V_193 . V_195 ) ;
V_193 . V_196 [ 0 ] = F_75 ( V_193 . V_196 [ 0 ] ) ;
}
V_204 -> V_147 = V_193 . V_196 [ 0 ] ;
V_189 ++ ;
}
if ( type & V_46 ) {
V_204 -> V_131 = * V_189 ;
V_189 ++ ;
}
if ( type & V_211 ) {
fprintf ( V_212 , L_27 ) ;
return - 1 ;
}
if ( type & V_213 ) {
if ( F_76 ( V_186 , V_189 , sizeof( V_204 -> V_214 -> V_175 ) ) )
return - V_207 ;
V_204 -> V_214 = (struct V_215 * ) V_189 ;
if ( F_76 ( V_186 , V_189 , V_204 -> V_214 -> V_175 ) )
return - V_207 ;
V_189 += 1 + V_204 -> V_214 -> V_175 ;
}
if ( type & V_43 ) {
const T_1 * V_216 ;
V_193 . V_195 = * V_189 ;
if ( F_78 ( V_190 ,
L_28 ) ) {
V_193 . V_195 = F_74 ( V_193 . V_195 ) ;
V_193 . V_196 [ 0 ] = F_75 ( V_193 . V_196 [ 0 ] ) ;
V_193 . V_196 [ 1 ] = F_75 ( V_193 . V_196 [ 1 ] ) ;
}
if ( F_76 ( V_186 , V_189 , sizeof( V_217 ) ) )
return - V_207 ;
V_204 -> V_218 = V_193 . V_196 [ 0 ] ;
V_216 = ( void * ) V_189 + sizeof( V_217 ) ;
if ( F_76 ( V_186 , V_216 , V_204 -> V_218 ) )
return - V_207 ;
V_204 -> V_219 = ( void * ) V_216 ;
V_189 = ( void * ) V_189 + V_204 -> V_218 + sizeof( V_217 ) ;
}
if ( type & V_220 ) {
T_1 V_221 ;
V_204 -> V_138 = (struct V_138 * ) V_189 ;
V_189 ++ ;
V_221 = V_204 -> V_138 -> V_175 * sizeof( struct V_222 ) ;
V_221 /= sizeof( T_1 ) ;
V_189 += V_221 ;
}
if ( type & V_223 ) {
T_1 V_224 = * V_189 ++ ;
if ( V_224 ) {
V_204 -> V_225 . V_226 = ( T_1 * ) V_189 ;
V_189 += F_79 ( V_205 ) ;
}
}
if ( type & V_227 ) {
T_1 V_4 = * V_189 ++ ;
V_204 -> V_228 . V_202 = ( ( char * ) ( V_189 - 1 )
- ( char * ) V_186 ) ;
if ( ! V_4 ) {
V_204 -> V_228 . V_4 = 0 ;
} else {
V_204 -> V_228 . V_204 = ( char * ) V_189 ;
V_189 += V_4 / sizeof( * V_189 ) ;
V_204 -> V_228 . V_4 = * V_189 ;
}
}
return 0 ;
}
int F_80 ( union V_185 * V_186 , T_1 type ,
const struct V_187 * V_188 ,
bool V_190 )
{
T_1 * V_189 ;
union V_192 V_193 ;
V_189 = V_186 -> V_188 . V_189 ;
if ( type & V_208 ) {
V_186 -> V_209 . V_209 = V_188 -> V_209 ;
V_189 ++ ;
}
if ( type & V_200 ) {
V_193 . V_196 [ 0 ] = V_188 -> V_174 ;
V_193 . V_196 [ 1 ] = V_188 -> V_201 ;
if ( V_190 ) {
V_193 . V_196 [ 0 ] = F_75 ( V_193 . V_196 [ 0 ] ) ;
V_193 . V_196 [ 1 ] = F_75 ( V_193 . V_196 [ 1 ] ) ;
V_193 . V_195 = F_74 ( V_193 . V_195 ) ;
}
* V_189 = V_193 . V_195 ;
V_189 ++ ;
}
if ( type & V_44 ) {
* V_189 = V_188 -> time ;
V_189 ++ ;
}
if ( type & V_210 ) {
* V_189 = V_188 -> V_70 ;
V_189 ++ ;
}
if ( type & V_199 ) {
* V_189 = V_188 -> V_50 ;
V_189 ++ ;
}
if ( type & V_197 ) {
* V_189 = V_188 -> V_198 ;
V_189 ++ ;
}
if ( type & V_45 ) {
V_193 . V_196 [ 0 ] = V_188 -> V_147 ;
if ( V_190 ) {
V_193 . V_196 [ 0 ] = F_75 ( V_193 . V_196 [ 0 ] ) ;
V_193 . V_195 = F_74 ( V_193 . V_195 ) ;
}
* V_189 = V_193 . V_195 ;
V_189 ++ ;
}
if ( type & V_46 ) {
* V_189 = V_188 -> V_131 ;
V_189 ++ ;
}
return 0 ;
}
struct V_229 * F_81 ( struct V_13 * V_14 , const char * V_28 )
{
return F_82 ( V_14 -> V_48 , V_28 ) ;
}
void * F_83 ( struct V_13 * V_14 , struct V_187 * V_188 ,
const char * V_28 )
{
struct V_229 * V_230 = F_81 ( V_14 , V_28 ) ;
int V_202 ;
if ( ! V_230 )
return NULL ;
V_202 = V_230 -> V_202 ;
if ( V_230 -> V_173 & V_231 ) {
V_202 = * ( int * ) ( V_188 -> V_219 + V_230 -> V_202 ) ;
V_202 &= 0xffff ;
}
return V_188 -> V_219 + V_202 ;
}
T_1 F_84 ( struct V_13 * V_14 , struct V_187 * V_188 ,
const char * V_28 )
{
struct V_229 * V_230 = F_81 ( V_14 , V_28 ) ;
void * V_232 ;
T_1 V_233 ;
if ( ! V_230 )
return 0 ;
V_232 = V_188 -> V_219 + V_230 -> V_202 ;
switch ( V_230 -> V_4 ) {
case 1 :
return * ( T_5 * ) V_232 ;
case 2 :
V_233 = * ( V_234 * ) V_232 ;
break;
case 4 :
V_233 = * ( V_217 * ) V_232 ;
break;
case 8 :
V_233 = * ( T_1 * ) V_232 ;
break;
default:
return 0 ;
}
if ( ! V_14 -> V_191 )
return V_233 ;
switch ( V_230 -> V_4 ) {
case 2 :
return F_85 ( V_233 ) ;
case 4 :
return F_75 ( V_233 ) ;
case 8 :
return F_74 ( V_233 ) ;
default:
return 0 ;
}
return 0 ;
}
static int F_86 ( T_6 * V_235 , bool * V_236 , const char * V_237 , ... )
{
T_7 args ;
int V_88 = 0 ;
if ( ! * V_236 ) {
V_88 += fprintf ( V_235 , L_29 ) ;
} else {
V_88 += fprintf ( V_235 , L_9 ) ;
* V_236 = false ;
}
va_start ( args , V_237 ) ;
V_88 += vfprintf ( V_235 , V_237 , args ) ;
va_end ( args ) ;
return V_88 ;
}
static int F_87 ( T_6 * V_235 , bool * V_236 , const char * V_230 , T_1 V_233 )
{
if ( V_233 == 0 )
return 0 ;
return F_86 ( V_235 , V_236 , L_30 V_238 , V_230 , V_233 ) ;
}
static int F_88 ( T_6 * V_235 , const char * V_230 , T_1 V_233 ,
struct V_239 * V_240 , bool * V_236 )
{
int V_5 = 0 , V_241 = F_86 ( V_235 , V_236 , L_31 , V_230 ) ;
bool V_242 = true ;
do {
if ( V_233 & V_240 [ V_5 ] . V_16 ) {
V_241 += fprintf ( V_235 , L_32 , V_242 ? L_33 : L_34 , V_240 [ V_5 ] . V_28 ) ;
V_242 = false ;
}
} while ( V_240 [ ++ V_5 ] . V_28 != NULL );
return V_241 ;
}
static int F_89 ( T_6 * V_235 , bool * V_236 , T_1 V_233 )
{
#define F_90 ( V_30 ) { PERF_SAMPLE_##n, #n }
struct V_239 V_240 [] = {
F_90 ( V_104 ) , F_90 ( V_105 ) , F_90 ( TIME ) , F_90 ( V_117 ) ,
F_90 ( V_243 ) , F_90 ( V_120 ) , F_90 ( V_19 ) , F_90 ( V_130 ) ,
F_90 ( V_111 ) , F_90 ( V_244 ) , F_90 ( V_134 ) ,
F_90 ( V_139 ) , F_90 ( V_122 ) , F_90 ( V_123 ) ,
{ . V_28 = NULL , }
} ;
#undef F_90
return F_88 ( V_235 , L_35 , V_233 , V_240 , V_236 ) ;
}
static int F_91 ( T_6 * V_235 , bool * V_236 , T_1 V_233 )
{
#define F_90 ( V_30 ) { PERF_FORMAT_##n, #n }
struct V_239 V_240 [] = {
F_90 ( V_245 ) , F_90 ( V_246 ) ,
F_90 ( V_19 ) , F_90 ( V_247 ) ,
{ . V_28 = NULL , }
} ;
#undef F_90
return F_88 ( V_235 , L_36 , V_233 , V_240 , V_236 ) ;
}
int F_92 ( struct V_13 * V_14 ,
struct V_248 * V_249 , T_6 * V_235 )
{
bool V_236 = true ;
int V_241 = 0 ;
if ( V_249 -> V_250 ) {
struct V_13 * V_96 ;
if ( ! F_42 ( V_14 ) )
return 0 ;
if ( V_14 -> V_251 > 1 )
V_241 += fprintf ( V_235 , L_37 , V_14 -> V_94 ? : L_33 ) ;
V_241 += fprintf ( V_235 , L_6 , F_35 ( V_14 ) ) ;
F_39 (pos, evsel)
V_241 += fprintf ( V_235 , L_38 , F_35 ( V_96 ) ) ;
if ( V_14 -> V_251 > 1 )
V_241 += fprintf ( V_235 , L_39 ) ;
goto V_37;
}
V_241 += fprintf ( V_235 , L_6 , F_35 ( V_14 ) ) ;
if ( V_249 -> V_252 || V_249 -> V_110 ) {
V_241 += F_86 ( V_235 , & V_236 , L_40 V_238 ,
( T_1 ) V_14 -> V_17 . V_112 ) ;
}
if ( V_249 -> V_252 ) {
F_93 ( type ) ;
F_93 ( V_49 ) ;
F_93 ( V_253 ) ;
F_93 ( V_254 ) ;
F_93 ( V_4 ) ;
V_241 += F_89 ( V_235 , & V_236 , V_14 -> V_17 . V_1 ) ;
if ( V_14 -> V_17 . V_20 )
V_241 += F_91 ( V_235 , & V_236 , V_14 -> V_17 . V_20 ) ;
F_93 ( V_143 ) ;
F_93 ( V_102 ) ;
F_93 ( V_255 ) ;
F_93 ( V_256 ) ;
F_93 ( V_58 ) ;
F_93 ( V_57 ) ;
F_93 ( V_59 ) ;
F_93 ( V_257 ) ;
F_93 ( V_141 ) ;
F_93 ( V_142 ) ;
F_93 ( V_110 ) ;
F_93 ( V_115 ) ;
F_93 ( V_144 ) ;
F_93 ( V_258 ) ;
F_93 ( V_136 ) ;
F_93 ( V_63 ) ;
F_93 ( V_118 ) ;
F_93 ( V_100 ) ;
F_93 ( V_64 ) ;
F_93 ( V_65 ) ;
F_93 ( V_259 ) ;
F_93 ( V_137 ) ;
F_93 ( V_76 ) ;
F_93 ( V_140 ) ;
}
V_37:
fputc ( '\n' , V_235 ) ;
return ++ V_241 ;
}
bool F_94 ( struct V_13 * V_14 , int V_83 ,
char * V_260 , T_2 V_261 )
{
if ( ( V_83 == V_262 || V_83 == V_263 ) &&
V_14 -> V_17 . type == V_90 &&
V_14 -> V_17 . V_49 == V_264 ) {
F_23 ( V_260 , V_261 , L_6 ,
L_41 ) ;
V_14 -> V_17 . type = V_92 ;
V_14 -> V_17 . V_49 = V_265 ;
free ( V_14 -> V_28 ) ;
V_14 -> V_28 = NULL ;
return true ;
}
return false ;
}
int F_95 ( struct V_13 * V_14 ,
struct V_266 * V_129 ,
int V_83 , char * V_260 , T_2 V_4 )
{
switch ( V_83 ) {
case V_267 :
case V_268 :
return F_23 ( V_260 , V_4 , L_6 ,
L_42
L_43
L_44
L_45
L_46
L_47 ,
V_129 -> V_269 ? L_48 : L_33 ) ;
case V_262 :
return F_23 ( V_260 , V_4 , L_49 ,
F_35 ( V_14 ) ) ;
case V_270 :
return F_23 ( V_260 , V_4 , L_6 ,
L_50
L_51 ) ;
case V_271 :
if ( V_129 -> V_272 )
return F_23 ( V_260 , V_4 , L_6 ,
L_52 ) ;
break;
case V_273 :
if ( V_14 -> V_17 . V_63 )
return F_23 ( V_260 , V_4 , L_6 ,
L_53 ) ;
#if F_96 ( V_274 ) || F_96 ( V_275 )
if ( V_14 -> V_17 . type == V_90 )
return F_23 ( V_260 , V_4 , L_6 ,
L_54
L_55 ) ;
#endif
break;
default:
break;
}
return F_23 ( V_260 , V_4 ,
L_56
L_57
L_58 ,
V_83 , strerror ( V_83 ) , F_35 ( V_14 ) ) ;
}
