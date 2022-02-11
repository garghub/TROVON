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
V_16 -> V_37 = L_1 ;
V_16 -> V_38 = 1.0 ;
F_13 ( & V_16 -> V_39 ) ;
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
struct V_15 * F_16 ( const char * V_40 , const char * V_41 , int V_6 )
{
struct V_15 * V_16 = F_15 ( sizeof( * V_16 ) ) ;
if ( V_16 != NULL ) {
struct V_35 V_18 = {
. type = V_42 ,
. V_1 = ( V_43 | V_11 |
V_13 | V_44 ) ,
} ;
if ( F_17 ( & V_16 -> V_41 , L_2 , V_40 , V_41 ) < 0 )
goto V_45;
V_16 -> V_46 = F_18 ( V_40 , V_41 ) ;
if ( V_16 -> V_46 == NULL )
goto V_45;
F_19 ( & V_18 ) ;
V_18 . V_47 = V_16 -> V_46 -> V_48 ;
V_18 . V_49 = 1 ;
F_12 ( V_16 , & V_18 , V_6 ) ;
}
return V_16 ;
V_45:
F_20 ( & V_16 -> V_41 ) ;
free ( V_16 ) ;
return NULL ;
}
static const char * F_21 ( T_1 V_47 )
{
if ( V_47 < V_50 && V_51 [ V_47 ] )
return V_51 [ V_47 ] ;
return L_3 ;
}
static int F_22 ( struct V_15 * V_16 , char * V_52 , T_2 V_4 )
{
int V_53 = 0 , V_54 = 0 ;
struct V_35 * V_18 = & V_16 -> V_18 ;
bool V_55 = false ;
#define F_23 ( T_3 , T_4 ) do { \
if (!attr->exclude_##context) { \
if (!colon) colon = ++r; \
r += scnprintf(bf + r, size - r, "%c", mod); \
} } while(0)
if ( V_18 -> V_56 || V_18 -> V_57 || V_18 -> V_58 ) {
F_23 ( V_59 , 'k' ) ;
F_23 ( V_60 , 'u' ) ;
F_23 ( V_61 , 'h' ) ;
V_55 = true ;
}
if ( V_18 -> V_62 ) {
if ( ! V_53 )
V_53 = ++ V_54 ;
V_54 += F_24 ( V_52 + V_54 , V_4 - V_54 , L_4 , V_18 -> V_62 , L_5 ) ;
V_55 = true ;
}
if ( V_18 -> V_63 || V_18 -> V_64 == V_55 ) {
F_23 ( V_65 , 'H' ) ;
F_23 ( V_66 , 'G' ) ;
}
#undef F_23
if ( V_53 )
V_52 [ V_53 - 1 ] = ':' ;
return V_54 ;
}
static int F_25 ( struct V_15 * V_16 , char * V_52 , T_2 V_4 )
{
int V_54 = F_24 ( V_52 , V_4 , L_6 , F_21 ( V_16 -> V_18 . V_47 ) ) ;
return V_54 + F_22 ( V_16 , V_52 + V_54 , V_4 - V_54 ) ;
}
static const char * F_26 ( T_1 V_47 )
{
if ( V_47 < V_67 && V_68 [ V_47 ] )
return V_68 [ V_47 ] ;
return L_7 ;
}
static int F_27 ( struct V_15 * V_16 , char * V_52 , T_2 V_4 )
{
int V_54 = F_24 ( V_52 , V_4 , L_6 , F_26 ( V_16 -> V_18 . V_47 ) ) ;
return V_54 + F_22 ( V_16 , V_52 + V_54 , V_4 - V_54 ) ;
}
static int F_28 ( char * V_52 , T_2 V_4 , T_1 V_69 , T_1 type )
{
int V_54 ;
V_54 = F_24 ( V_52 , V_4 , L_8 V_70 L_9 , V_69 ) ;
if ( type & V_71 )
V_54 += F_24 ( V_52 + V_54 , V_4 - V_54 , L_10 ) ;
if ( type & V_72 )
V_54 += F_24 ( V_52 + V_54 , V_4 - V_54 , L_11 ) ;
if ( type & V_73 )
V_54 += F_24 ( V_52 + V_54 , V_4 - V_54 , L_12 ) ;
return V_54 ;
}
static int F_29 ( struct V_15 * V_16 , char * V_52 , T_2 V_4 )
{
struct V_35 * V_18 = & V_16 -> V_18 ;
int V_54 = F_28 ( V_52 , V_4 , V_18 -> V_74 , V_18 -> V_75 ) ;
return V_54 + F_22 ( V_16 , V_52 + V_54 , V_4 - V_54 ) ;
}
bool F_30 ( T_5 type , T_5 V_76 )
{
if ( V_77 [ type ] & F_31 ( V_76 ) )
return true ;
else
return false ;
}
int F_32 ( T_5 type , T_5 V_76 , T_5 V_78 ,
char * V_52 , T_2 V_4 )
{
if ( V_78 ) {
return F_24 ( V_52 , V_4 , L_13 , V_79 [ type ] [ 0 ] ,
V_80 [ V_76 ] [ 0 ] ,
V_81 [ V_78 ] [ 0 ] ) ;
}
return F_24 ( V_52 , V_4 , L_14 , V_79 [ type ] [ 0 ] ,
V_80 [ V_76 ] [ 1 ] ) ;
}
static int F_33 ( T_1 V_47 , char * V_52 , T_2 V_4 )
{
T_5 V_76 , V_78 , type = ( V_47 >> 0 ) & 0xff ;
const char * V_82 = L_15 ;
if ( type > V_83 )
goto V_84;
V_76 = ( V_47 >> 8 ) & 0xff ;
V_82 = L_16 ;
if ( V_76 > V_85 )
goto V_84;
V_78 = ( V_47 >> 16 ) & 0xff ;
V_82 = L_17 ;
if ( V_78 > V_86 )
goto V_84;
V_82 = L_18 ;
if ( ! F_30 ( type , V_76 ) )
goto V_84;
return F_32 ( type , V_76 , V_78 , V_52 , V_4 ) ;
V_84:
return F_24 ( V_52 , V_4 , L_6 , V_82 ) ;
}
static int F_34 ( struct V_15 * V_16 , char * V_52 , T_2 V_4 )
{
int V_87 = F_33 ( V_16 -> V_18 . V_47 , V_52 , V_4 ) ;
return V_87 + F_22 ( V_16 , V_52 + V_87 , V_4 - V_87 ) ;
}
static int F_35 ( struct V_15 * V_16 , char * V_52 , T_2 V_4 )
{
int V_87 = F_24 ( V_52 , V_4 , L_19 V_70 , V_16 -> V_18 . V_47 ) ;
return V_87 + F_22 ( V_16 , V_52 + V_87 , V_4 - V_87 ) ;
}
const char * F_36 ( struct V_15 * V_16 )
{
char V_52 [ 128 ] ;
if ( V_16 -> V_41 )
return V_16 -> V_41 ;
switch ( V_16 -> V_18 . type ) {
case V_88 :
F_35 ( V_16 , V_52 , sizeof( V_52 ) ) ;
break;
case V_89 :
F_25 ( V_16 , V_52 , sizeof( V_52 ) ) ;
break;
case V_90 :
F_34 ( V_16 , V_52 , sizeof( V_52 ) ) ;
break;
case V_91 :
F_27 ( V_16 , V_52 , sizeof( V_52 ) ) ;
break;
case V_42 :
F_24 ( V_52 , sizeof( V_52 ) , L_6 , L_20 ) ;
break;
case V_92 :
F_29 ( V_16 , V_52 , sizeof( V_52 ) ) ;
break;
default:
F_24 ( V_52 , sizeof( V_52 ) , L_21 ,
V_16 -> V_18 . type ) ;
break;
}
V_16 -> V_41 = F_37 ( V_52 ) ;
return V_16 -> V_41 ? : L_22 ;
}
const char * F_38 ( struct V_15 * V_16 )
{
return V_16 -> V_93 ? : L_23 ;
}
int F_39 ( struct V_15 * V_16 , char * V_94 , T_2 V_4 )
{
int V_87 ;
struct V_15 * V_95 ;
const char * V_93 = F_38 ( V_16 ) ;
V_87 = F_24 ( V_94 , V_4 , L_6 , V_93 ) ;
V_87 += F_24 ( V_94 + V_87 , V_4 - V_87 , L_24 ,
F_36 ( V_16 ) ) ;
F_40 (pos, evsel)
V_87 += F_24 ( V_94 + V_87 , V_4 - V_87 , L_25 ,
F_36 ( V_95 ) ) ;
V_87 += F_24 ( V_94 + V_87 , V_4 - V_87 , L_26 ) ;
return V_87 ;
}
static void
F_41 ( struct V_15 * V_16 ,
struct V_96 * V_97 )
{
bool V_98 = F_42 ( V_16 ) ;
struct V_35 * V_18 = & V_16 -> V_18 ;
F_11 ( V_16 , V_99 ) ;
if ( V_97 -> V_100 == V_101 ) {
if ( ! V_98 ) {
F_11 ( V_16 , V_102 ) ;
F_11 ( V_16 , V_103 ) ;
V_18 -> V_104 = V_105 ;
V_18 -> V_106 = V_97 -> V_107 ;
V_18 -> V_108 = 1 ;
} else {
F_43 ( L_27
L_28 ) ;
}
}
if ( V_98 ) {
F_43 ( L_29 ) ;
V_18 -> V_108 = 1 ;
}
}
void F_44 ( struct V_15 * V_16 , struct V_96 * V_97 )
{
struct V_15 * V_36 = V_16 -> V_36 ;
struct V_35 * V_18 = & V_16 -> V_18 ;
int V_109 = ! V_16 -> V_6 ;
bool V_110 = V_97 -> V_111 . V_112 && ! V_97 -> V_111 . V_113 ;
V_18 -> V_114 = V_115 . V_114 ? 0 : 1 ;
V_18 -> V_116 = ! V_97 -> V_117 ;
F_11 ( V_16 , V_118 ) ;
F_11 ( V_16 , V_119 ) ;
if ( V_16 -> V_120 ) {
F_11 ( V_16 , V_121 ) ;
F_9 ( V_16 , false ) ;
if ( V_36 -> V_122 > 1 ) {
V_18 -> V_33 |= V_123 ;
V_18 -> V_116 = 0 ;
}
}
if ( ! V_18 -> V_49 || ( V_97 -> V_124 != V_125 ||
V_97 -> V_126 != V_127 ) ) {
if ( V_97 -> V_128 ) {
F_11 ( V_16 , V_129 ) ;
V_18 -> V_128 = 1 ;
V_18 -> V_130 = V_97 -> V_128 ;
} else {
V_18 -> V_49 = V_97 -> V_131 ;
}
}
if ( ( V_36 != V_16 ) && V_36 -> V_120 ) {
V_18 -> V_130 = 0 ;
V_18 -> V_49 = 0 ;
}
if ( V_97 -> V_132 )
V_18 -> V_130 = 0 ;
if ( V_97 -> V_133 )
V_18 -> V_133 = 1 ;
if ( V_97 -> V_134 ) {
F_11 ( V_16 , V_135 ) ;
V_18 -> V_136 = V_109 ;
}
if ( V_97 -> V_137 )
F_41 ( V_16 , V_97 ) ;
if ( F_45 ( & V_97 -> V_111 ) )
F_11 ( V_16 , V_138 ) ;
if ( V_97 -> V_139 )
F_11 ( V_16 , V_129 ) ;
if ( ! V_115 . V_114 &&
( V_97 -> V_140 || ! V_97 -> V_117 ||
F_45 ( & V_97 -> V_111 ) || V_110 ) )
F_11 ( V_16 , TIME ) ;
if ( V_97 -> V_141 ) {
F_11 ( V_16 , TIME ) ;
F_11 ( V_16 , V_142 ) ;
F_11 ( V_16 , V_138 ) ;
}
if ( V_97 -> V_134 )
F_11 ( V_16 , V_143 ) ;
if ( V_97 -> V_144 ) {
V_18 -> V_145 = 0 ;
V_18 -> V_146 = 1 ;
}
if ( V_97 -> V_147 ) {
F_11 ( V_16 , V_148 ) ;
V_18 -> V_149 = V_97 -> V_147 ;
}
if ( V_97 -> V_150 )
F_11 ( V_16 , V_151 ) ;
V_18 -> V_152 = V_109 ;
V_18 -> V_153 = V_109 && ! V_115 . V_153 ;
V_18 -> V_154 = V_109 ;
if ( V_97 -> V_155 )
F_11 ( V_16 , V_156 ) ;
if ( F_46 ( V_16 ) )
V_18 -> V_157 = 1 ;
if ( F_47 ( & V_97 -> V_111 ) && F_46 ( V_16 ) &&
! V_97 -> V_158 )
V_18 -> V_159 = 1 ;
}
int F_48 ( struct V_15 * V_16 , int V_160 , int V_161 )
{
int V_162 , V_163 ;
V_16 -> V_164 = F_49 ( V_160 , V_161 , sizeof( int ) ) ;
if ( V_16 -> V_164 ) {
for ( V_162 = 0 ; V_162 < V_160 ; V_162 ++ ) {
for ( V_163 = 0 ; V_163 < V_161 ; V_163 ++ ) {
F_50 ( V_16 , V_162 , V_163 ) = - 1 ;
}
}
}
return V_16 -> V_164 != NULL ? 0 : - V_165 ;
}
static int F_51 ( struct V_15 * V_16 , int V_160 , int V_161 ,
int V_166 , void * V_167 )
{
int V_162 , V_163 ;
for ( V_162 = 0 ; V_162 < V_160 ; V_162 ++ ) {
for ( V_163 = 0 ; V_163 < V_161 ; V_163 ++ ) {
int V_164 = F_50 ( V_16 , V_162 , V_163 ) ,
V_82 = F_52 ( V_164 , V_166 , V_167 ) ;
if ( V_82 )
return V_82 ;
}
}
return 0 ;
}
int F_53 ( struct V_15 * V_16 , int V_160 , int V_161 ,
const char * V_168 )
{
return F_51 ( V_16 , V_160 , V_161 ,
V_169 ,
( void * ) V_168 ) ;
}
int F_54 ( struct V_15 * V_16 , int V_160 , int V_161 )
{
return F_51 ( V_16 , V_160 , V_161 ,
V_170 ,
0 ) ;
}
int F_55 ( struct V_15 * V_16 , int V_160 , int V_161 )
{
V_16 -> V_171 = F_49 ( V_160 , V_161 , sizeof( struct V_172 ) ) ;
if ( V_16 -> V_171 == NULL )
return - V_165 ;
V_16 -> V_48 = F_15 ( V_160 * V_161 * sizeof( T_1 ) ) ;
if ( V_16 -> V_48 == NULL ) {
F_56 ( V_16 -> V_171 ) ;
V_16 -> V_171 = NULL ;
return - V_165 ;
}
return 0 ;
}
void F_57 ( struct V_15 * V_16 , int V_160 )
{
memset ( V_16 -> V_173 , 0 , ( sizeof( * V_16 -> V_173 ) +
( V_160 * sizeof( struct V_174 ) ) ) ) ;
}
int F_58 ( struct V_15 * V_16 , int V_160 )
{
V_16 -> V_173 = F_15 ( ( sizeof( * V_16 -> V_173 ) +
( V_160 * sizeof( struct V_174 ) ) ) ) ;
return V_16 -> V_173 != NULL ? 0 : - V_165 ;
}
void F_59 ( struct V_15 * V_16 )
{
F_56 ( V_16 -> V_164 ) ;
V_16 -> V_164 = NULL ;
}
void F_60 ( struct V_15 * V_16 )
{
F_56 ( V_16 -> V_171 ) ;
V_16 -> V_171 = NULL ;
F_20 ( & V_16 -> V_48 ) ;
}
void F_61 ( struct V_15 * V_16 , int V_160 , int V_161 )
{
int V_162 , V_163 ;
for ( V_162 = 0 ; V_162 < V_160 ; V_162 ++ )
for ( V_163 = 0 ; V_163 < V_161 ; ++ V_163 ) {
F_62 ( F_50 ( V_16 , V_162 , V_163 ) ) ;
F_50 ( V_16 , V_162 , V_163 ) = - 1 ;
}
}
void F_63 ( struct V_15 * V_16 )
{
F_20 ( & V_16 -> V_173 ) ;
}
void F_64 ( struct V_15 * V_16 )
{
assert ( F_65 ( & V_16 -> V_39 ) ) ;
F_59 ( V_16 ) ;
F_60 ( V_16 ) ;
}
void F_66 ( struct V_15 * V_16 )
{
F_64 ( V_16 ) ;
F_67 ( V_16 -> V_175 ) ;
F_20 ( & V_16 -> V_93 ) ;
if ( V_16 -> V_46 )
F_68 ( V_16 -> V_46 ) ;
F_20 ( & V_16 -> V_41 ) ;
free ( V_16 ) ;
}
static inline void F_69 ( struct V_15 * V_16 ,
int V_162 ,
struct V_174 * V_176 )
{
struct V_174 V_177 ;
if ( ! V_16 -> V_178 )
return;
if ( V_162 == - 1 ) {
V_177 = V_16 -> V_178 -> V_179 ;
V_16 -> V_178 -> V_179 = * V_176 ;
} else {
V_177 = V_16 -> V_178 -> V_162 [ V_162 ] ;
V_16 -> V_178 -> V_162 [ V_162 ] = * V_176 ;
}
V_176 -> V_180 = V_176 -> V_180 - V_177 . V_180 ;
V_176 -> V_181 = V_176 -> V_181 - V_177 . V_181 ;
V_176 -> V_182 = V_176 -> V_182 - V_177 . V_182 ;
}
int F_70 ( struct V_15 * V_16 ,
int V_162 , int V_163 , bool V_38 )
{
struct V_174 V_176 ;
T_2 V_183 = V_38 ? 3 : 1 ;
if ( F_50 ( V_16 , V_162 , V_163 ) < 0 )
return - V_184 ;
if ( V_16 -> V_173 == NULL && F_58 ( V_16 , V_162 + 1 ) < 0 )
return - V_165 ;
if ( F_71 ( F_50 ( V_16 , V_162 , V_163 ) , & V_176 , V_183 * sizeof( T_1 ) ) < 0 )
return - V_185 ;
F_69 ( V_16 , V_162 , & V_176 ) ;
if ( V_38 ) {
if ( V_176 . V_182 == 0 )
V_176 . V_180 = 0 ;
else if ( V_176 . V_182 < V_176 . V_181 )
V_176 . V_180 = ( T_1 ) ( ( double ) V_176 . V_180 * V_176 . V_181 / V_176 . V_182 + 0.5 ) ;
} else
V_176 . V_181 = V_176 . V_182 = 0 ;
V_16 -> V_173 -> V_162 [ V_162 ] = V_176 ;
return 0 ;
}
int F_72 ( struct V_15 * V_16 ,
int V_160 , int V_161 , bool V_38 )
{
T_2 V_183 = V_38 ? 3 : 1 ;
int V_162 , V_163 ;
struct V_174 * V_179 = & V_16 -> V_173 -> V_179 , V_176 ;
V_179 -> V_180 = V_179 -> V_181 = V_179 -> V_182 = 0 ;
for ( V_162 = 0 ; V_162 < V_160 ; V_162 ++ ) {
for ( V_163 = 0 ; V_163 < V_161 ; V_163 ++ ) {
if ( F_50 ( V_16 , V_162 , V_163 ) < 0 )
continue;
if ( F_71 ( F_50 ( V_16 , V_162 , V_163 ) ,
& V_176 , V_183 * sizeof( T_1 ) ) < 0 )
return - V_185 ;
V_179 -> V_180 += V_176 . V_180 ;
if ( V_38 ) {
V_179 -> V_181 += V_176 . V_181 ;
V_179 -> V_182 += V_176 . V_182 ;
}
}
}
F_69 ( V_16 , - 1 , V_179 ) ;
V_16 -> V_173 -> V_186 = 0 ;
if ( V_38 ) {
if ( V_179 -> V_182 == 0 ) {
V_16 -> V_173 -> V_186 = - 1 ;
V_179 -> V_180 = 0 ;
return 0 ;
}
if ( V_179 -> V_182 < V_179 -> V_181 ) {
V_16 -> V_173 -> V_186 = 1 ;
V_179 -> V_180 = ( T_1 ) ( ( double ) V_179 -> V_180 * V_179 -> V_181 / V_179 -> V_182 + 0.5 ) ;
}
} else
V_179 -> V_181 = V_179 -> V_182 = 0 ;
return 0 ;
}
static int F_73 ( struct V_15 * V_16 , int V_162 , int V_163 )
{
struct V_15 * V_36 = V_16 -> V_36 ;
int V_164 ;
if ( F_46 ( V_16 ) )
return - 1 ;
F_74 ( ! V_36 -> V_164 ) ;
V_164 = F_50 ( V_36 , V_162 , V_163 ) ;
F_74 ( V_164 == - 1 ) ;
return V_164 ;
}
static T_2 F_75 ( struct V_35 * V_18 , T_6 * V_187 )
{
T_2 V_87 = 0 ;
V_87 += fprintf ( V_187 , L_30 , V_188 ) ;
V_87 += fprintf ( V_187 , L_31 ) ;
V_87 += F_76 ( type ) ;
V_87 += F_76 ( V_4 ) ;
V_87 += F_77 ( V_47 ) ;
V_87 += F_78 ( V_49 ) ;
V_87 += F_78 ( V_130 ) ;
V_87 += F_77 ( V_1 ) ;
V_87 += F_77 ( V_33 ) ;
V_87 += F_79 ( V_157 , V_116 ) ;
V_87 += F_79 ( V_189 , V_190 ) ;
V_87 += F_79 ( V_57 , V_56 ) ;
V_87 += F_79 ( V_58 , V_191 ) ;
V_87 += F_79 ( V_152 , V_154 ) ;
V_87 += F_79 ( V_128 , V_133 ) ;
V_87 += F_79 ( V_159 , V_192 ) ;
V_87 += F_79 ( V_145 , V_62 ) ;
V_87 += F_79 ( V_136 , V_114 ) ;
V_87 += F_79 ( V_63 , V_64 ) ;
V_87 += F_80 ( L_32 , V_193 ,
L_33 , V_108 ) ;
V_87 += F_76 ( V_153 ) ;
V_87 += F_76 ( V_146 ) ;
V_87 += F_76 ( V_194 ) ;
V_87 += F_81 ( V_75 ) ;
V_87 += F_77 ( V_74 ) ;
V_87 += F_77 ( V_195 ) ;
V_87 += F_78 ( V_196 ) ;
V_87 += F_77 ( V_197 ) ;
V_87 += F_77 ( V_149 ) ;
V_87 += F_77 ( V_104 ) ;
V_87 += F_76 ( V_106 ) ;
V_87 += fprintf ( V_187 , L_30 , V_188 ) ;
return V_87 ;
}
static int F_82 ( struct V_15 * V_16 , struct V_198 * V_199 ,
struct V_200 * V_201 )
{
int V_162 , V_163 ;
unsigned long V_202 = 0 ;
int V_203 = - 1 , V_82 ;
enum { V_204 , V_205 , V_206 } V_207 = V_204 ;
if ( V_16 -> V_164 == NULL &&
F_48 ( V_16 , V_199 -> V_208 , V_201 -> V_208 ) < 0 )
return - V_165 ;
if ( V_16 -> V_175 ) {
V_202 = V_209 ;
V_203 = V_16 -> V_175 -> V_164 ;
}
V_210:
if ( V_115 . V_153 )
V_16 -> V_18 . V_153 = 0 ;
if ( V_115 . V_64 )
V_16 -> V_18 . V_64 = V_16 -> V_18 . V_63 = 0 ;
V_211:
if ( V_115 . V_114 )
V_16 -> V_18 . V_114 = 0 ;
if ( V_212 >= 2 )
F_75 ( & V_16 -> V_18 , V_213 ) ;
for ( V_162 = 0 ; V_162 < V_199 -> V_208 ; V_162 ++ ) {
for ( V_163 = 0 ; V_163 < V_201 -> V_208 ; V_163 ++ ) {
int V_214 ;
if ( ! V_16 -> V_175 )
V_203 = V_201 -> V_215 [ V_163 ] ;
V_214 = F_73 ( V_16 , V_162 , V_163 ) ;
V_216:
F_83 ( L_34 ,
V_203 , V_199 -> V_215 [ V_162 ] , V_214 , V_202 ) ;
F_50 ( V_16 , V_162 , V_163 ) = F_84 ( & V_16 -> V_18 ,
V_203 ,
V_199 -> V_215 [ V_162 ] ,
V_214 , V_202 ) ;
if ( F_50 ( V_16 , V_162 , V_163 ) < 0 ) {
V_82 = - V_185 ;
F_83 ( L_35 ,
V_82 ) ;
goto V_217;
}
V_207 = V_204 ;
}
}
return 0 ;
V_217:
if ( V_82 == - V_218 && V_207 < V_206 ) {
struct V_219 V_220 ;
int V_221 = V_185 ;
if ( F_85 ( V_222 , & V_220 ) == 0 ) {
if ( V_207 == V_204 )
V_220 . V_223 = V_220 . V_224 ;
else {
V_220 . V_223 = V_220 . V_224 + 1000 ;
V_220 . V_224 = V_220 . V_223 ;
}
if ( F_86 ( V_222 , & V_220 ) == 0 ) {
V_207 ++ ;
V_185 = V_221 ;
goto V_216;
}
}
V_185 = V_221 ;
}
if ( V_82 != - V_184 || V_162 > 0 || V_163 > 0 )
goto V_225;
if ( ! V_115 . V_153 && V_16 -> V_18 . V_153 ) {
V_115 . V_153 = true ;
goto V_210;
} else if ( ! V_115 . V_64 &&
( V_16 -> V_18 . V_64 || V_16 -> V_18 . V_63 ) ) {
V_115 . V_64 = true ;
goto V_210;
} else if ( ! V_115 . V_114 ) {
V_115 . V_114 = true ;
goto V_211;
}
V_225:
do {
while ( -- V_163 >= 0 ) {
F_62 ( F_50 ( V_16 , V_162 , V_163 ) ) ;
F_50 ( V_16 , V_162 , V_163 ) = - 1 ;
}
V_163 = V_201 -> V_208 ;
} while ( -- V_162 >= 0 );
return V_82 ;
}
void F_87 ( struct V_15 * V_16 , int V_160 , int V_161 )
{
if ( V_16 -> V_164 == NULL )
return;
F_61 ( V_16 , V_160 , V_161 ) ;
F_59 ( V_16 ) ;
}
int F_88 ( struct V_15 * V_16 , struct V_198 * V_199 ,
struct V_200 * V_201 )
{
if ( V_199 == NULL ) {
V_199 = & V_226 . V_215 ;
}
if ( V_201 == NULL )
V_201 = & V_227 . V_215 ;
return F_82 ( V_16 , V_199 , V_201 ) ;
}
int F_89 ( struct V_15 * V_16 ,
struct V_198 * V_199 )
{
return F_82 ( V_16 , V_199 , & V_227 . V_215 ) ;
}
int F_90 ( struct V_15 * V_16 ,
struct V_200 * V_201 )
{
return F_82 ( V_16 , & V_226 . V_215 , V_201 ) ;
}
static int F_91 ( const struct V_15 * V_16 ,
const union V_228 * V_229 ,
struct V_230 * V_231 )
{
T_1 type = V_16 -> V_18 . V_1 ;
const T_1 * V_232 = V_229 -> V_231 . V_232 ;
bool V_233 = V_16 -> V_234 ;
union V_235 V_236 ;
V_232 += ( ( V_229 -> V_237 . V_4 -
sizeof( V_229 -> V_237 ) ) / sizeof( T_1 ) ) - 1 ;
if ( type & V_7 ) {
V_231 -> V_48 = * V_232 ;
V_232 -- ;
}
if ( type & V_13 ) {
V_236 . V_238 = * V_232 ;
if ( V_233 ) {
V_236 . V_238 = F_92 ( V_236 . V_238 ) ;
V_236 . V_239 [ 0 ] = F_93 ( V_236 . V_239 [ 0 ] ) ;
}
V_231 -> V_162 = V_236 . V_239 [ 0 ] ;
V_232 -- ;
}
if ( type & V_14 ) {
V_231 -> V_240 = * V_232 ;
V_232 -- ;
}
if ( type & V_8 ) {
V_231 -> V_48 = * V_232 ;
V_232 -- ;
}
if ( type & V_11 ) {
V_231 -> time = * V_232 ;
V_232 -- ;
}
if ( type & V_10 ) {
V_236 . V_238 = * V_232 ;
if ( V_233 ) {
V_236 . V_238 = F_92 ( V_236 . V_238 ) ;
V_236 . V_239 [ 0 ] = F_93 ( V_236 . V_239 [ 0 ] ) ;
V_236 . V_239 [ 1 ] = F_93 ( V_236 . V_239 [ 1 ] ) ;
}
V_231 -> V_203 = V_236 . V_239 [ 0 ] ;
V_231 -> V_241 = V_236 . V_239 [ 1 ] ;
V_232 -- ;
}
return 0 ;
}
static inline bool F_94 ( const void * V_242 , T_7 V_243 , const void * V_244 ,
T_1 V_4 )
{
return V_4 > V_243 || V_244 + V_4 > V_242 ;
}
int F_95 ( struct V_15 * V_16 , union V_228 * V_229 ,
struct V_230 * V_245 )
{
T_1 type = V_16 -> V_18 . V_1 ;
bool V_233 = V_16 -> V_234 ;
const T_1 * V_232 ;
T_7 V_243 = V_229 -> V_237 . V_4 ;
const void * V_242 = ( void * ) V_229 + V_243 ;
T_1 V_246 ;
union V_235 V_236 ;
memset ( V_245 , 0 , sizeof( * V_245 ) ) ;
V_245 -> V_162 = V_245 -> V_203 = V_245 -> V_241 = - 1 ;
V_245 -> V_240 = V_245 -> V_48 = V_245 -> time = - 1ULL ;
V_245 -> V_139 = V_16 -> V_18 . V_49 ;
V_245 -> V_247 = 0 ;
if ( V_229 -> V_237 . type != V_248 ) {
if ( ! V_16 -> V_18 . V_114 )
return 0 ;
return F_91 ( V_16 , V_229 , V_245 ) ;
}
V_232 = V_229 -> V_231 . V_232 ;
if ( V_16 -> V_29 + sizeof( V_229 -> V_237 ) > V_229 -> V_237 . V_4 )
return - V_249 ;
V_245 -> V_48 = - 1ULL ;
if ( type & V_7 ) {
V_245 -> V_48 = * V_232 ;
V_232 ++ ;
}
if ( type & V_9 ) {
V_245 -> V_250 = * V_232 ;
V_232 ++ ;
}
if ( type & V_10 ) {
V_236 . V_238 = * V_232 ;
if ( V_233 ) {
V_236 . V_238 = F_92 ( V_236 . V_238 ) ;
V_236 . V_239 [ 0 ] = F_93 ( V_236 . V_239 [ 0 ] ) ;
V_236 . V_239 [ 1 ] = F_93 ( V_236 . V_239 [ 1 ] ) ;
}
V_245 -> V_203 = V_236 . V_239 [ 0 ] ;
V_245 -> V_241 = V_236 . V_239 [ 1 ] ;
V_232 ++ ;
}
if ( type & V_11 ) {
V_245 -> time = * V_232 ;
V_232 ++ ;
}
V_245 -> V_69 = 0 ;
if ( type & V_12 ) {
V_245 -> V_69 = * V_232 ;
V_232 ++ ;
}
if ( type & V_8 ) {
V_245 -> V_48 = * V_232 ;
V_232 ++ ;
}
if ( type & V_14 ) {
V_245 -> V_240 = * V_232 ;
V_232 ++ ;
}
if ( type & V_13 ) {
V_236 . V_238 = * V_232 ;
if ( V_233 ) {
V_236 . V_238 = F_92 ( V_236 . V_238 ) ;
V_236 . V_239 [ 0 ] = F_93 ( V_236 . V_239 [ 0 ] ) ;
}
V_245 -> V_162 = V_236 . V_239 [ 0 ] ;
V_232 ++ ;
}
if ( type & V_44 ) {
V_245 -> V_139 = * V_232 ;
V_232 ++ ;
}
if ( type & V_251 ) {
T_1 V_33 = V_16 -> V_18 . V_33 ;
F_96 ( V_232 ) ;
if ( V_33 & V_123 )
V_245 -> V_252 . V_253 . V_208 = * V_232 ;
else
V_245 -> V_252 . V_254 . V_255 = * V_232 ;
V_232 ++ ;
if ( V_33 & V_256 ) {
F_96 ( V_232 ) ;
V_245 -> V_252 . V_257 = * V_232 ;
V_232 ++ ;
}
if ( V_33 & V_258 ) {
F_96 ( V_232 ) ;
V_245 -> V_252 . V_259 = * V_232 ;
V_232 ++ ;
}
if ( V_33 & V_123 ) {
const T_1 V_260 = V_261 /
sizeof( struct V_262 ) ;
if ( V_245 -> V_252 . V_253 . V_208 > V_260 )
return - V_249 ;
V_246 = V_245 -> V_252 . V_253 . V_208 *
sizeof( struct V_262 ) ;
F_97 ( V_232 , V_246 , V_243 ) ;
V_245 -> V_252 . V_253 . V_263 =
(struct V_262 * ) V_232 ;
V_232 = ( void * ) V_232 + V_246 ;
} else {
F_96 ( V_232 ) ;
V_245 -> V_252 . V_254 . V_48 = * V_232 ;
V_232 ++ ;
}
}
if ( type & V_264 ) {
const T_1 V_265 = V_261 / sizeof( T_1 ) ;
F_96 ( V_232 ) ;
V_245 -> V_266 = (struct V_267 * ) V_232 ++ ;
if ( V_245 -> V_266 -> V_208 > V_265 )
return - V_249 ;
V_246 = V_245 -> V_266 -> V_208 * sizeof( T_1 ) ;
F_97 ( V_232 , V_246 , V_243 ) ;
V_232 = ( void * ) V_232 + V_246 ;
}
if ( type & V_43 ) {
F_96 ( V_232 ) ;
V_236 . V_238 = * V_232 ;
if ( F_98 ( V_233 ,
L_36 ) ) {
V_236 . V_238 = F_92 ( V_236 . V_238 ) ;
V_236 . V_239 [ 0 ] = F_93 ( V_236 . V_239 [ 0 ] ) ;
V_236 . V_239 [ 1 ] = F_93 ( V_236 . V_239 [ 1 ] ) ;
}
V_245 -> V_268 = V_236 . V_239 [ 0 ] ;
V_232 = ( void * ) V_232 + sizeof( V_269 ) ;
F_97 ( V_232 , V_245 -> V_268 , V_243 ) ;
V_245 -> V_270 = ( void * ) V_232 ;
V_232 = ( void * ) V_232 + V_245 -> V_268 ;
}
if ( type & V_271 ) {
const T_1 V_272 = V_261 /
sizeof( struct V_273 ) ;
F_96 ( V_232 ) ;
V_245 -> V_147 = (struct V_147 * ) V_232 ++ ;
if ( V_245 -> V_147 -> V_208 > V_272 )
return - V_249 ;
V_246 = V_245 -> V_147 -> V_208 * sizeof( struct V_273 ) ;
F_97 ( V_232 , V_246 , V_243 ) ;
V_232 = ( void * ) V_232 + V_246 ;
}
if ( type & V_274 ) {
F_96 ( V_232 ) ;
V_245 -> V_275 . V_276 = * V_232 ;
V_232 ++ ;
if ( V_245 -> V_275 . V_276 ) {
T_1 V_2 = V_16 -> V_18 . V_104 ;
V_246 = F_99 ( V_2 ) * sizeof( T_1 ) ;
F_97 ( V_232 , V_246 , V_243 ) ;
V_245 -> V_275 . V_2 = V_2 ;
V_245 -> V_275 . V_277 = ( T_1 * ) V_232 ;
V_232 = ( void * ) V_232 + V_246 ;
}
}
if ( type & V_278 ) {
F_96 ( V_232 ) ;
V_246 = * V_232 ++ ;
V_245 -> V_279 . V_244 = ( ( char * ) ( V_232 - 1 )
- ( char * ) V_229 ) ;
if ( ! V_246 ) {
V_245 -> V_279 . V_4 = 0 ;
} else {
F_97 ( V_232 , V_246 , V_243 ) ;
V_245 -> V_279 . V_245 = ( char * ) V_232 ;
V_232 = ( void * ) V_232 + V_246 ;
F_96 ( V_232 ) ;
V_245 -> V_279 . V_4 = * V_232 ++ ;
if ( F_98 ( V_245 -> V_279 . V_4 > V_246 ,
L_37 ) )
return - V_249 ;
}
}
V_245 -> V_247 = 0 ;
if ( type & V_280 ) {
F_96 ( V_232 ) ;
V_245 -> V_247 = * V_232 ;
V_232 ++ ;
}
V_245 -> V_281 = V_282 ;
if ( type & V_283 ) {
F_96 ( V_232 ) ;
V_245 -> V_281 = * V_232 ;
V_232 ++ ;
}
V_245 -> V_284 = 0 ;
if ( type & V_285 ) {
F_96 ( V_232 ) ;
V_245 -> V_284 = * V_232 ;
V_232 ++ ;
}
return 0 ;
}
T_2 F_100 ( const struct V_230 * V_231 , T_1 type ,
T_1 V_33 )
{
T_2 V_246 , V_78 = sizeof( struct V_286 ) ;
if ( type & V_7 )
V_78 += sizeof( T_1 ) ;
if ( type & V_9 )
V_78 += sizeof( T_1 ) ;
if ( type & V_10 )
V_78 += sizeof( T_1 ) ;
if ( type & V_11 )
V_78 += sizeof( T_1 ) ;
if ( type & V_12 )
V_78 += sizeof( T_1 ) ;
if ( type & V_8 )
V_78 += sizeof( T_1 ) ;
if ( type & V_14 )
V_78 += sizeof( T_1 ) ;
if ( type & V_13 )
V_78 += sizeof( T_1 ) ;
if ( type & V_44 )
V_78 += sizeof( T_1 ) ;
if ( type & V_251 ) {
V_78 += sizeof( T_1 ) ;
if ( V_33 & V_256 )
V_78 += sizeof( T_1 ) ;
if ( V_33 & V_258 )
V_78 += sizeof( T_1 ) ;
if ( V_33 & V_123 ) {
V_246 = V_231 -> V_252 . V_253 . V_208 *
sizeof( struct V_262 ) ;
V_78 += V_246 ;
} else {
V_78 += sizeof( T_1 ) ;
}
}
if ( type & V_264 ) {
V_246 = ( V_231 -> V_266 -> V_208 + 1 ) * sizeof( T_1 ) ;
V_78 += V_246 ;
}
if ( type & V_43 ) {
V_78 += sizeof( V_269 ) ;
V_78 += V_231 -> V_268 ;
}
if ( type & V_271 ) {
V_246 = V_231 -> V_147 -> V_208 * sizeof( struct V_273 ) ;
V_246 += sizeof( T_1 ) ;
V_78 += V_246 ;
}
if ( type & V_274 ) {
if ( V_231 -> V_275 . V_276 ) {
V_78 += sizeof( T_1 ) ;
V_246 = F_99 ( V_231 -> V_275 . V_2 ) * sizeof( T_1 ) ;
V_78 += V_246 ;
} else {
V_78 += sizeof( T_1 ) ;
}
}
if ( type & V_278 ) {
V_246 = V_231 -> V_279 . V_4 ;
V_78 += sizeof( T_1 ) ;
if ( V_246 ) {
V_78 += V_246 ;
V_78 += sizeof( T_1 ) ;
}
}
if ( type & V_280 )
V_78 += sizeof( T_1 ) ;
if ( type & V_283 )
V_78 += sizeof( T_1 ) ;
if ( type & V_285 )
V_78 += sizeof( T_1 ) ;
return V_78 ;
}
int F_101 ( union V_228 * V_229 , T_1 type ,
T_1 V_33 ,
const struct V_230 * V_231 ,
bool V_233 )
{
T_1 * V_232 ;
T_2 V_246 ;
union V_235 V_236 ;
V_232 = V_229 -> V_231 . V_232 ;
if ( type & V_7 ) {
* V_232 = V_231 -> V_48 ;
V_232 ++ ;
}
if ( type & V_9 ) {
* V_232 = V_231 -> V_250 ;
V_232 ++ ;
}
if ( type & V_10 ) {
V_236 . V_239 [ 0 ] = V_231 -> V_203 ;
V_236 . V_239 [ 1 ] = V_231 -> V_241 ;
if ( V_233 ) {
V_236 . V_239 [ 0 ] = F_93 ( V_236 . V_239 [ 0 ] ) ;
V_236 . V_239 [ 1 ] = F_93 ( V_236 . V_239 [ 1 ] ) ;
V_236 . V_238 = F_92 ( V_236 . V_238 ) ;
}
* V_232 = V_236 . V_238 ;
V_232 ++ ;
}
if ( type & V_11 ) {
* V_232 = V_231 -> time ;
V_232 ++ ;
}
if ( type & V_12 ) {
* V_232 = V_231 -> V_69 ;
V_232 ++ ;
}
if ( type & V_8 ) {
* V_232 = V_231 -> V_48 ;
V_232 ++ ;
}
if ( type & V_14 ) {
* V_232 = V_231 -> V_240 ;
V_232 ++ ;
}
if ( type & V_13 ) {
V_236 . V_239 [ 0 ] = V_231 -> V_162 ;
if ( V_233 ) {
V_236 . V_239 [ 0 ] = F_93 ( V_236 . V_239 [ 0 ] ) ;
V_236 . V_238 = F_92 ( V_236 . V_238 ) ;
}
* V_232 = V_236 . V_238 ;
V_232 ++ ;
}
if ( type & V_44 ) {
* V_232 = V_231 -> V_139 ;
V_232 ++ ;
}
if ( type & V_251 ) {
if ( V_33 & V_123 )
* V_232 = V_231 -> V_252 . V_253 . V_208 ;
else
* V_232 = V_231 -> V_252 . V_254 . V_255 ;
V_232 ++ ;
if ( V_33 & V_256 ) {
* V_232 = V_231 -> V_252 . V_257 ;
V_232 ++ ;
}
if ( V_33 & V_258 ) {
* V_232 = V_231 -> V_252 . V_259 ;
V_232 ++ ;
}
if ( V_33 & V_123 ) {
V_246 = V_231 -> V_252 . V_253 . V_208 *
sizeof( struct V_262 ) ;
memcpy ( V_232 , V_231 -> V_252 . V_253 . V_263 , V_246 ) ;
V_232 = ( void * ) V_232 + V_246 ;
} else {
* V_232 = V_231 -> V_252 . V_254 . V_48 ;
V_232 ++ ;
}
}
if ( type & V_264 ) {
V_246 = ( V_231 -> V_266 -> V_208 + 1 ) * sizeof( T_1 ) ;
memcpy ( V_232 , V_231 -> V_266 , V_246 ) ;
V_232 = ( void * ) V_232 + V_246 ;
}
if ( type & V_43 ) {
V_236 . V_239 [ 0 ] = V_231 -> V_268 ;
if ( F_98 ( V_233 ,
L_36 ) ) {
V_236 . V_239 [ 0 ] = F_93 ( V_236 . V_239 [ 0 ] ) ;
V_236 . V_239 [ 1 ] = F_93 ( V_236 . V_239 [ 1 ] ) ;
V_236 . V_238 = F_92 ( V_236 . V_238 ) ;
}
* V_232 = V_236 . V_238 ;
V_232 = ( void * ) V_232 + sizeof( V_269 ) ;
memcpy ( V_232 , V_231 -> V_270 , V_231 -> V_268 ) ;
V_232 = ( void * ) V_232 + V_231 -> V_268 ;
}
if ( type & V_271 ) {
V_246 = V_231 -> V_147 -> V_208 * sizeof( struct V_273 ) ;
V_246 += sizeof( T_1 ) ;
memcpy ( V_232 , V_231 -> V_147 , V_246 ) ;
V_232 = ( void * ) V_232 + V_246 ;
}
if ( type & V_274 ) {
if ( V_231 -> V_275 . V_276 ) {
* V_232 ++ = V_231 -> V_275 . V_276 ;
V_246 = F_99 ( V_231 -> V_275 . V_2 ) * sizeof( T_1 ) ;
memcpy ( V_232 , V_231 -> V_275 . V_277 , V_246 ) ;
V_232 = ( void * ) V_232 + V_246 ;
} else {
* V_232 ++ = 0 ;
}
}
if ( type & V_278 ) {
V_246 = V_231 -> V_279 . V_4 ;
* V_232 ++ = V_246 ;
if ( V_246 ) {
memcpy ( V_232 , V_231 -> V_279 . V_245 , V_246 ) ;
V_232 = ( void * ) V_232 + V_246 ;
* V_232 ++ = V_246 ;
}
}
if ( type & V_280 ) {
* V_232 = V_231 -> V_247 ;
V_232 ++ ;
}
if ( type & V_283 ) {
* V_232 = V_231 -> V_281 ;
V_232 ++ ;
}
if ( type & V_285 ) {
* V_232 = V_231 -> V_284 ;
V_232 ++ ;
}
return 0 ;
}
struct V_287 * F_102 ( struct V_15 * V_16 , const char * V_41 )
{
return F_103 ( V_16 -> V_46 , V_41 ) ;
}
void * F_104 ( struct V_15 * V_16 , struct V_230 * V_231 ,
const char * V_41 )
{
struct V_287 * V_288 = F_102 ( V_16 , V_41 ) ;
int V_244 ;
if ( ! V_288 )
return NULL ;
V_244 = V_288 -> V_244 ;
if ( V_288 -> V_202 & V_289 ) {
V_244 = * ( int * ) ( V_231 -> V_270 + V_288 -> V_244 ) ;
V_244 &= 0xffff ;
}
return V_231 -> V_270 + V_244 ;
}
T_1 F_105 ( struct V_15 * V_16 , struct V_230 * V_231 ,
const char * V_41 )
{
struct V_287 * V_288 = F_102 ( V_16 , V_41 ) ;
void * V_290 ;
T_1 V_255 ;
if ( ! V_288 )
return 0 ;
V_290 = V_231 -> V_270 + V_288 -> V_244 ;
switch ( V_288 -> V_4 ) {
case 1 :
return * ( T_5 * ) V_290 ;
case 2 :
V_255 = * ( T_7 * ) V_290 ;
break;
case 4 :
V_255 = * ( V_269 * ) V_290 ;
break;
case 8 :
V_255 = * ( T_1 * ) V_290 ;
break;
default:
return 0 ;
}
if ( ! V_16 -> V_234 )
return V_255 ;
switch ( V_288 -> V_4 ) {
case 2 :
return F_106 ( V_255 ) ;
case 4 :
return F_93 ( V_255 ) ;
case 8 :
return F_92 ( V_255 ) ;
default:
return 0 ;
}
return 0 ;
}
static int F_107 ( T_6 * V_187 , bool * V_291 , const char * V_292 , ... )
{
T_8 args ;
int V_87 = 0 ;
if ( ! * V_291 ) {
V_87 += fprintf ( V_187 , L_38 ) ;
} else {
V_87 += fprintf ( V_187 , L_9 ) ;
* V_291 = false ;
}
va_start ( args , V_292 ) ;
V_87 += vfprintf ( V_187 , V_292 , args ) ;
va_end ( args ) ;
return V_87 ;
}
static int F_108 ( T_6 * V_187 , bool * V_291 , const char * V_288 , T_1 V_255 )
{
if ( V_255 == 0 )
return 0 ;
return F_107 ( V_187 , V_291 , L_39 V_293 , V_288 , V_255 ) ;
}
static int F_109 ( T_6 * V_187 , const char * V_288 , T_1 V_255 ,
struct V_294 * V_295 , bool * V_291 )
{
int V_5 = 0 , V_296 = F_107 ( V_187 , V_291 , L_40 , V_288 ) ;
bool V_297 = true ;
do {
if ( V_255 & V_295 [ V_5 ] . V_28 ) {
V_296 += fprintf ( V_187 , L_41 , V_297 ? L_1 : L_42 , V_295 [ V_5 ] . V_41 ) ;
V_297 = false ;
}
} while ( V_295 [ ++ V_5 ] . V_41 != NULL );
return V_296 ;
}
static int F_110 ( T_6 * V_187 , bool * V_291 , T_1 V_255 )
{
#define F_111 ( T_9 ) { PERF_SAMPLE_##n, #n }
struct V_294 V_295 [] = {
F_111 ( V_118 ) , F_111 ( V_119 ) , F_111 ( TIME ) , F_111 ( V_135 ) ,
F_111 ( V_121 ) , F_111 ( V_99 ) , F_111 ( V_31 ) , F_111 ( V_138 ) ,
F_111 ( V_129 ) , F_111 ( V_298 ) , F_111 ( V_142 ) ,
F_111 ( V_148 ) , F_111 ( V_102 ) , F_111 ( V_103 ) ,
F_111 ( V_32 ) ,
{ . V_41 = NULL , }
} ;
#undef F_111
return F_109 ( V_187 , L_43 , V_255 , V_295 , V_291 ) ;
}
static int F_112 ( T_6 * V_187 , bool * V_291 , T_1 V_255 )
{
#define F_111 ( T_9 ) { PERF_FORMAT_##n, #n }
struct V_294 V_295 [] = {
F_111 ( V_299 ) , F_111 ( V_300 ) ,
F_111 ( V_31 ) , F_111 ( V_301 ) ,
{ . V_41 = NULL , }
} ;
#undef F_111
return F_109 ( V_187 , L_44 , V_255 , V_295 , V_291 ) ;
}
int F_113 ( struct V_15 * V_16 ,
struct V_302 * V_303 , T_6 * V_187 )
{
bool V_291 = true ;
int V_296 = 0 ;
if ( V_303 -> V_304 ) {
struct V_15 * V_95 ;
if ( ! F_46 ( V_16 ) )
return 0 ;
if ( V_16 -> V_122 > 1 )
V_296 += fprintf ( V_187 , L_45 , V_16 -> V_93 ? : L_1 ) ;
V_296 += fprintf ( V_187 , L_6 , F_36 ( V_16 ) ) ;
F_40 (pos, evsel)
V_296 += fprintf ( V_187 , L_46 , F_36 ( V_95 ) ) ;
if ( V_16 -> V_122 > 1 )
V_296 += fprintf ( V_187 , L_47 ) ;
goto V_305;
}
V_296 += fprintf ( V_187 , L_6 , F_36 ( V_16 ) ) ;
if ( V_303 -> V_212 || V_303 -> V_128 ) {
V_296 += F_107 ( V_187 , & V_291 , L_48 V_293 ,
( T_1 ) V_16 -> V_18 . V_130 ) ;
}
if ( V_303 -> V_212 ) {
F_114 ( type ) ;
F_114 ( V_47 ) ;
F_114 ( V_195 ) ;
F_114 ( V_197 ) ;
F_114 ( V_4 ) ;
V_296 += F_110 ( V_187 , & V_291 , V_16 -> V_18 . V_1 ) ;
if ( V_16 -> V_18 . V_33 )
V_296 += F_112 ( V_187 , & V_291 , V_16 -> V_18 . V_33 ) ;
F_114 ( V_157 ) ;
F_114 ( V_116 ) ;
F_114 ( V_189 ) ;
F_114 ( V_190 ) ;
F_114 ( V_57 ) ;
F_114 ( V_56 ) ;
F_114 ( V_58 ) ;
F_114 ( V_191 ) ;
F_114 ( V_152 ) ;
F_114 ( V_153 ) ;
F_114 ( V_154 ) ;
F_114 ( V_128 ) ;
F_114 ( V_133 ) ;
F_114 ( V_159 ) ;
F_114 ( V_192 ) ;
F_114 ( V_145 ) ;
F_114 ( V_62 ) ;
F_114 ( V_136 ) ;
F_114 ( V_114 ) ;
F_114 ( V_63 ) ;
F_114 ( V_64 ) ;
F_114 ( V_306 ) ;
F_114 ( V_146 ) ;
F_114 ( V_75 ) ;
F_114 ( V_149 ) ;
}
V_305:
fputc ( '\n' , V_187 ) ;
return ++ V_296 ;
}
bool F_115 ( struct V_15 * V_16 , int V_82 ,
char * V_307 , T_2 V_308 )
{
if ( ( V_82 == V_309 || V_82 == V_310 || V_82 == V_311 ) &&
V_16 -> V_18 . type == V_89 &&
V_16 -> V_18 . V_47 == V_312 ) {
F_24 ( V_307 , V_308 , L_6 ,
L_49 ) ;
V_16 -> V_18 . type = V_91 ;
V_16 -> V_18 . V_47 = V_313 ;
F_20 ( & V_16 -> V_41 ) ;
return true ;
}
return false ;
}
int F_116 ( struct V_15 * V_16 , struct V_111 * V_111 ,
int V_82 , char * V_307 , T_2 V_4 )
{
switch ( V_82 ) {
case V_314 :
case V_315 :
return F_24 ( V_307 , V_4 ,
L_50
L_51
L_52
L_53
L_54
L_55 ,
V_111 -> V_316 ? L_56 : L_1 ) ;
case V_309 :
return F_24 ( V_307 , V_4 , L_57 ,
F_36 ( V_16 ) ) ;
case V_218 :
return F_24 ( V_307 , V_4 , L_6 ,
L_58
L_59 ) ;
case V_311 :
if ( V_111 -> V_317 )
return F_24 ( V_307 , V_4 , L_6 ,
L_60 ) ;
break;
case V_318 :
if ( V_16 -> V_18 . V_62 )
return F_24 ( V_307 , V_4 , L_6 ,
L_61 ) ;
#if F_117 ( V_319 ) || F_117 ( V_320 )
if ( V_16 -> V_18 . type == V_89 )
return F_24 ( V_307 , V_4 , L_6 ,
L_62
L_63 ) ;
#endif
break;
default:
break;
}
return F_24 ( V_307 , V_4 ,
L_64
L_65
L_66 ,
V_82 , strerror ( V_82 ) , F_36 ( V_16 ) ) ;
}
