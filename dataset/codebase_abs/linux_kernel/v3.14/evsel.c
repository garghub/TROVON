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
void F_41 ( struct V_15 * V_16 , struct V_96 * V_97 )
{
struct V_15 * V_36 = V_16 -> V_36 ;
struct V_35 * V_18 = & V_16 -> V_18 ;
int V_98 = ! V_16 -> V_6 ;
bool V_99 = V_97 -> V_100 . V_101 && ! V_97 -> V_100 . V_102 ;
V_18 -> V_103 = V_104 . V_103 ? 0 : 1 ;
V_18 -> V_105 = ! V_97 -> V_106 ;
F_11 ( V_16 , V_107 ) ;
F_11 ( V_16 , V_108 ) ;
if ( V_16 -> V_109 ) {
F_11 ( V_16 , V_110 ) ;
F_9 ( V_16 , false ) ;
if ( V_36 -> V_111 > 1 ) {
V_18 -> V_33 |= V_112 ;
V_18 -> V_105 = 0 ;
}
}
if ( ! V_18 -> V_49 || ( V_97 -> V_113 != V_114 &&
V_97 -> V_115 != V_116 ) ) {
if ( V_97 -> V_117 ) {
F_11 ( V_16 , V_118 ) ;
V_18 -> V_117 = 1 ;
V_18 -> V_119 = V_97 -> V_117 ;
} else {
V_18 -> V_49 = V_97 -> V_120 ;
}
}
if ( ( V_36 != V_16 ) && V_36 -> V_109 ) {
V_18 -> V_119 = 0 ;
V_18 -> V_49 = 0 ;
}
if ( V_97 -> V_121 )
V_18 -> V_119 = 0 ;
if ( V_97 -> V_122 )
V_18 -> V_122 = 1 ;
if ( V_97 -> V_123 ) {
F_11 ( V_16 , V_124 ) ;
V_18 -> V_125 = V_98 ;
}
if ( V_97 -> V_126 ) {
F_11 ( V_16 , V_127 ) ;
if ( V_97 -> V_126 == V_128 ) {
F_11 ( V_16 , V_129 ) ;
F_11 ( V_16 , V_130 ) ;
V_18 -> V_131 = V_132 ;
V_18 -> V_133 = V_97 -> V_134 ;
V_18 -> V_135 = 1 ;
}
}
if ( F_42 ( & V_97 -> V_100 ) )
F_11 ( V_16 , V_136 ) ;
if ( V_97 -> V_137 )
F_11 ( V_16 , V_118 ) ;
if ( ! V_104 . V_103 &&
( V_97 -> V_138 || ! V_97 -> V_106 ||
F_42 ( & V_97 -> V_100 ) || V_99 ) )
F_11 ( V_16 , TIME ) ;
if ( V_97 -> V_139 ) {
F_11 ( V_16 , TIME ) ;
F_11 ( V_16 , V_140 ) ;
F_11 ( V_16 , V_136 ) ;
}
if ( V_97 -> V_123 )
F_11 ( V_16 , V_141 ) ;
if ( V_97 -> V_142 ) {
V_18 -> V_143 = 0 ;
V_18 -> V_144 = 1 ;
}
if ( V_97 -> V_145 ) {
F_11 ( V_16 , V_146 ) ;
V_18 -> V_147 = V_97 -> V_145 ;
}
if ( V_97 -> V_148 )
F_11 ( V_16 , V_149 ) ;
V_18 -> V_150 = V_98 ;
V_18 -> V_151 = V_98 ;
if ( V_97 -> V_152 )
F_11 ( V_16 , V_153 ) ;
if ( F_43 ( V_16 ) )
V_18 -> V_154 = 1 ;
if ( F_44 ( & V_97 -> V_100 ) && F_43 ( V_16 ) &&
! V_97 -> V_155 )
V_18 -> V_156 = 1 ;
}
int F_45 ( struct V_15 * V_16 , int V_157 , int V_158 )
{
int V_159 , V_160 ;
V_16 -> V_161 = F_46 ( V_157 , V_158 , sizeof( int ) ) ;
if ( V_16 -> V_161 ) {
for ( V_159 = 0 ; V_159 < V_157 ; V_159 ++ ) {
for ( V_160 = 0 ; V_160 < V_158 ; V_160 ++ ) {
F_47 ( V_16 , V_159 , V_160 ) = - 1 ;
}
}
}
return V_16 -> V_161 != NULL ? 0 : - V_162 ;
}
static int F_48 ( struct V_15 * V_16 , int V_157 , int V_158 ,
int V_163 , void * V_164 )
{
int V_159 , V_160 ;
for ( V_159 = 0 ; V_159 < V_157 ; V_159 ++ ) {
for ( V_160 = 0 ; V_160 < V_158 ; V_160 ++ ) {
int V_161 = F_47 ( V_16 , V_159 , V_160 ) ,
V_82 = F_49 ( V_161 , V_163 , V_164 ) ;
if ( V_82 )
return V_82 ;
}
}
return 0 ;
}
int F_50 ( struct V_15 * V_16 , int V_157 , int V_158 ,
const char * V_165 )
{
return F_48 ( V_16 , V_157 , V_158 ,
V_166 ,
( void * ) V_165 ) ;
}
int F_51 ( struct V_15 * V_16 , int V_157 , int V_158 )
{
return F_48 ( V_16 , V_157 , V_158 ,
V_167 ,
0 ) ;
}
int F_52 ( struct V_15 * V_16 , int V_157 , int V_158 )
{
V_16 -> V_168 = F_46 ( V_157 , V_158 , sizeof( struct V_169 ) ) ;
if ( V_16 -> V_168 == NULL )
return - V_162 ;
V_16 -> V_48 = F_15 ( V_157 * V_158 * sizeof( T_1 ) ) ;
if ( V_16 -> V_48 == NULL ) {
F_53 ( V_16 -> V_168 ) ;
V_16 -> V_168 = NULL ;
return - V_162 ;
}
return 0 ;
}
void F_54 ( struct V_15 * V_16 , int V_157 )
{
memset ( V_16 -> V_170 , 0 , ( sizeof( * V_16 -> V_170 ) +
( V_157 * sizeof( struct V_171 ) ) ) ) ;
}
int F_55 ( struct V_15 * V_16 , int V_157 )
{
V_16 -> V_170 = F_15 ( ( sizeof( * V_16 -> V_170 ) +
( V_157 * sizeof( struct V_171 ) ) ) ) ;
return V_16 -> V_170 != NULL ? 0 : - V_162 ;
}
void F_56 ( struct V_15 * V_16 )
{
F_53 ( V_16 -> V_161 ) ;
V_16 -> V_161 = NULL ;
}
void F_57 ( struct V_15 * V_16 )
{
F_53 ( V_16 -> V_168 ) ;
V_16 -> V_168 = NULL ;
F_20 ( & V_16 -> V_48 ) ;
}
void F_58 ( struct V_15 * V_16 , int V_157 , int V_158 )
{
int V_159 , V_160 ;
for ( V_159 = 0 ; V_159 < V_157 ; V_159 ++ )
for ( V_160 = 0 ; V_160 < V_158 ; ++ V_160 ) {
F_59 ( F_47 ( V_16 , V_159 , V_160 ) ) ;
F_47 ( V_16 , V_159 , V_160 ) = - 1 ;
}
}
void F_60 ( struct V_15 * V_16 )
{
F_20 ( & V_16 -> V_170 ) ;
}
void F_61 ( struct V_15 * V_16 )
{
assert ( F_62 ( & V_16 -> V_39 ) ) ;
F_56 ( V_16 ) ;
F_57 ( V_16 ) ;
}
void F_63 ( struct V_15 * V_16 )
{
F_61 ( V_16 ) ;
F_64 ( V_16 -> V_172 ) ;
F_20 ( & V_16 -> V_93 ) ;
if ( V_16 -> V_46 )
F_65 ( V_16 -> V_46 ) ;
F_20 ( & V_16 -> V_41 ) ;
free ( V_16 ) ;
}
static inline void F_66 ( struct V_15 * V_16 ,
int V_159 ,
struct V_171 * V_173 )
{
struct V_171 V_174 ;
if ( ! V_16 -> V_175 )
return;
if ( V_159 == - 1 ) {
V_174 = V_16 -> V_175 -> V_176 ;
V_16 -> V_175 -> V_176 = * V_173 ;
} else {
V_174 = V_16 -> V_175 -> V_159 [ V_159 ] ;
V_16 -> V_175 -> V_159 [ V_159 ] = * V_173 ;
}
V_173 -> V_177 = V_173 -> V_177 - V_174 . V_177 ;
V_173 -> V_178 = V_173 -> V_178 - V_174 . V_178 ;
V_173 -> V_179 = V_173 -> V_179 - V_174 . V_179 ;
}
int F_67 ( struct V_15 * V_16 ,
int V_159 , int V_160 , bool V_38 )
{
struct V_171 V_173 ;
T_2 V_180 = V_38 ? 3 : 1 ;
if ( F_47 ( V_16 , V_159 , V_160 ) < 0 )
return - V_181 ;
if ( V_16 -> V_170 == NULL && F_55 ( V_16 , V_159 + 1 ) < 0 )
return - V_162 ;
if ( F_68 ( F_47 ( V_16 , V_159 , V_160 ) , & V_173 , V_180 * sizeof( T_1 ) ) < 0 )
return - V_182 ;
F_66 ( V_16 , V_159 , & V_173 ) ;
if ( V_38 ) {
if ( V_173 . V_179 == 0 )
V_173 . V_177 = 0 ;
else if ( V_173 . V_179 < V_173 . V_178 )
V_173 . V_177 = ( T_1 ) ( ( double ) V_173 . V_177 * V_173 . V_178 / V_173 . V_179 + 0.5 ) ;
} else
V_173 . V_178 = V_173 . V_179 = 0 ;
V_16 -> V_170 -> V_159 [ V_159 ] = V_173 ;
return 0 ;
}
int F_69 ( struct V_15 * V_16 ,
int V_157 , int V_158 , bool V_38 )
{
T_2 V_180 = V_38 ? 3 : 1 ;
int V_159 , V_160 ;
struct V_171 * V_176 = & V_16 -> V_170 -> V_176 , V_173 ;
V_176 -> V_177 = V_176 -> V_178 = V_176 -> V_179 = 0 ;
for ( V_159 = 0 ; V_159 < V_157 ; V_159 ++ ) {
for ( V_160 = 0 ; V_160 < V_158 ; V_160 ++ ) {
if ( F_47 ( V_16 , V_159 , V_160 ) < 0 )
continue;
if ( F_68 ( F_47 ( V_16 , V_159 , V_160 ) ,
& V_173 , V_180 * sizeof( T_1 ) ) < 0 )
return - V_182 ;
V_176 -> V_177 += V_173 . V_177 ;
if ( V_38 ) {
V_176 -> V_178 += V_173 . V_178 ;
V_176 -> V_179 += V_173 . V_179 ;
}
}
}
F_66 ( V_16 , - 1 , V_176 ) ;
V_16 -> V_170 -> V_183 = 0 ;
if ( V_38 ) {
if ( V_176 -> V_179 == 0 ) {
V_16 -> V_170 -> V_183 = - 1 ;
V_176 -> V_177 = 0 ;
return 0 ;
}
if ( V_176 -> V_179 < V_176 -> V_178 ) {
V_16 -> V_170 -> V_183 = 1 ;
V_176 -> V_177 = ( T_1 ) ( ( double ) V_176 -> V_177 * V_176 -> V_178 / V_176 -> V_179 + 0.5 ) ;
}
} else
V_176 -> V_178 = V_176 -> V_179 = 0 ;
return 0 ;
}
static int F_70 ( struct V_15 * V_16 , int V_159 , int V_160 )
{
struct V_15 * V_36 = V_16 -> V_36 ;
int V_161 ;
if ( F_43 ( V_16 ) )
return - 1 ;
F_71 ( ! V_36 -> V_161 ) ;
V_161 = F_47 ( V_36 , V_159 , V_160 ) ;
F_71 ( V_161 == - 1 ) ;
return V_161 ;
}
static T_2 F_72 ( struct V_35 * V_18 , T_6 * V_184 )
{
T_2 V_87 = 0 ;
V_87 += fprintf ( V_184 , L_27 , V_185 ) ;
V_87 += fprintf ( V_184 , L_28 ) ;
V_87 += F_73 ( type ) ;
V_87 += F_73 ( V_4 ) ;
V_87 += F_74 ( V_47 ) ;
V_87 += F_75 ( V_49 ) ;
V_87 += F_75 ( V_119 ) ;
V_87 += F_74 ( V_1 ) ;
V_87 += F_74 ( V_33 ) ;
V_87 += F_76 ( V_154 , V_105 ) ;
V_87 += F_76 ( V_186 , V_187 ) ;
V_87 += F_76 ( V_57 , V_56 ) ;
V_87 += F_76 ( V_58 , V_188 ) ;
V_87 += F_76 ( V_150 , V_151 ) ;
V_87 += F_76 ( V_117 , V_122 ) ;
V_87 += F_76 ( V_156 , V_189 ) ;
V_87 += F_76 ( V_143 , V_62 ) ;
V_87 += F_76 ( V_125 , V_103 ) ;
V_87 += F_76 ( V_63 , V_64 ) ;
V_87 += F_77 ( L_29 , V_190 ,
L_30 , V_135 ) ;
V_87 += F_73 ( V_191 ) ;
V_87 += F_73 ( V_144 ) ;
V_87 += F_73 ( V_192 ) ;
V_87 += F_78 ( V_75 ) ;
V_87 += F_74 ( V_74 ) ;
V_87 += F_74 ( V_193 ) ;
V_87 += F_75 ( V_194 ) ;
V_87 += F_74 ( V_195 ) ;
V_87 += F_74 ( V_147 ) ;
V_87 += F_74 ( V_131 ) ;
V_87 += F_73 ( V_133 ) ;
V_87 += fprintf ( V_184 , L_27 , V_185 ) ;
return V_87 ;
}
static int F_79 ( struct V_15 * V_16 , struct V_196 * V_197 ,
struct V_198 * V_199 )
{
int V_159 , V_160 ;
unsigned long V_200 = 0 ;
int V_201 = - 1 , V_82 ;
enum { V_202 , V_203 , V_204 } V_205 = V_202 ;
if ( V_16 -> V_161 == NULL &&
F_45 ( V_16 , V_197 -> V_206 , V_199 -> V_206 ) < 0 )
return - V_162 ;
if ( V_16 -> V_172 ) {
V_200 = V_207 ;
V_201 = V_16 -> V_172 -> V_161 ;
}
V_208:
if ( V_104 . V_191 )
V_16 -> V_18 . V_191 = 0 ;
if ( V_104 . V_64 )
V_16 -> V_18 . V_64 = V_16 -> V_18 . V_63 = 0 ;
V_209:
if ( V_104 . V_103 )
V_16 -> V_18 . V_103 = 0 ;
if ( V_210 >= 2 )
F_72 ( & V_16 -> V_18 , V_211 ) ;
for ( V_159 = 0 ; V_159 < V_197 -> V_206 ; V_159 ++ ) {
for ( V_160 = 0 ; V_160 < V_199 -> V_206 ; V_160 ++ ) {
int V_212 ;
if ( ! V_16 -> V_172 )
V_201 = V_199 -> V_213 [ V_160 ] ;
V_212 = F_70 ( V_16 , V_159 , V_160 ) ;
V_214:
F_80 ( L_31 ,
V_201 , V_197 -> V_213 [ V_159 ] , V_212 , V_200 ) ;
F_47 ( V_16 , V_159 , V_160 ) = F_81 ( & V_16 -> V_18 ,
V_201 ,
V_197 -> V_213 [ V_159 ] ,
V_212 , V_200 ) ;
if ( F_47 ( V_16 , V_159 , V_160 ) < 0 ) {
V_82 = - V_182 ;
F_80 ( L_32 ,
V_82 ) ;
goto V_215;
}
V_205 = V_202 ;
}
}
return 0 ;
V_215:
if ( V_82 == - V_216 && V_205 < V_204 ) {
struct V_217 V_218 ;
int V_219 = V_182 ;
if ( F_82 ( V_220 , & V_218 ) == 0 ) {
if ( V_205 == V_202 )
V_218 . V_221 = V_218 . V_222 ;
else {
V_218 . V_221 = V_218 . V_222 + 1000 ;
V_218 . V_222 = V_218 . V_221 ;
}
if ( F_83 ( V_220 , & V_218 ) == 0 ) {
V_205 ++ ;
V_182 = V_219 ;
goto V_214;
}
}
V_182 = V_219 ;
}
if ( V_82 != - V_181 || V_159 > 0 || V_160 > 0 )
goto V_223;
if ( ! V_104 . V_191 && V_16 -> V_18 . V_191 ) {
V_104 . V_191 = true ;
goto V_208;
} else if ( ! V_104 . V_64 &&
( V_16 -> V_18 . V_64 || V_16 -> V_18 . V_63 ) ) {
V_104 . V_64 = true ;
goto V_208;
} else if ( ! V_104 . V_103 ) {
V_104 . V_103 = true ;
goto V_209;
}
V_223:
do {
while ( -- V_160 >= 0 ) {
F_59 ( F_47 ( V_16 , V_159 , V_160 ) ) ;
F_47 ( V_16 , V_159 , V_160 ) = - 1 ;
}
V_160 = V_199 -> V_206 ;
} while ( -- V_159 >= 0 );
return V_82 ;
}
void F_84 ( struct V_15 * V_16 , int V_157 , int V_158 )
{
if ( V_16 -> V_161 == NULL )
return;
F_58 ( V_16 , V_157 , V_158 ) ;
F_56 ( V_16 ) ;
}
int F_85 ( struct V_15 * V_16 , struct V_196 * V_197 ,
struct V_198 * V_199 )
{
if ( V_197 == NULL ) {
V_197 = & V_224 . V_213 ;
}
if ( V_199 == NULL )
V_199 = & V_225 . V_213 ;
return F_79 ( V_16 , V_197 , V_199 ) ;
}
int F_86 ( struct V_15 * V_16 ,
struct V_196 * V_197 )
{
return F_79 ( V_16 , V_197 , & V_225 . V_213 ) ;
}
int F_87 ( struct V_15 * V_16 ,
struct V_198 * V_199 )
{
return F_79 ( V_16 , & V_224 . V_213 , V_199 ) ;
}
static int F_88 ( const struct V_15 * V_16 ,
const union V_226 * V_227 ,
struct V_228 * V_229 )
{
T_1 type = V_16 -> V_18 . V_1 ;
const T_1 * V_230 = V_227 -> V_229 . V_230 ;
bool V_231 = V_16 -> V_232 ;
union V_233 V_234 ;
V_230 += ( ( V_227 -> V_235 . V_4 -
sizeof( V_227 -> V_235 ) ) / sizeof( T_1 ) ) - 1 ;
if ( type & V_7 ) {
V_229 -> V_48 = * V_230 ;
V_230 -- ;
}
if ( type & V_13 ) {
V_234 . V_236 = * V_230 ;
if ( V_231 ) {
V_234 . V_236 = F_89 ( V_234 . V_236 ) ;
V_234 . V_237 [ 0 ] = F_90 ( V_234 . V_237 [ 0 ] ) ;
}
V_229 -> V_159 = V_234 . V_237 [ 0 ] ;
V_230 -- ;
}
if ( type & V_14 ) {
V_229 -> V_238 = * V_230 ;
V_230 -- ;
}
if ( type & V_8 ) {
V_229 -> V_48 = * V_230 ;
V_230 -- ;
}
if ( type & V_11 ) {
V_229 -> time = * V_230 ;
V_230 -- ;
}
if ( type & V_10 ) {
V_234 . V_236 = * V_230 ;
if ( V_231 ) {
V_234 . V_236 = F_89 ( V_234 . V_236 ) ;
V_234 . V_237 [ 0 ] = F_90 ( V_234 . V_237 [ 0 ] ) ;
V_234 . V_237 [ 1 ] = F_90 ( V_234 . V_237 [ 1 ] ) ;
}
V_229 -> V_201 = V_234 . V_237 [ 0 ] ;
V_229 -> V_239 = V_234 . V_237 [ 1 ] ;
V_230 -- ;
}
return 0 ;
}
static inline bool F_91 ( const void * V_240 , T_7 V_241 , const void * V_242 ,
T_1 V_4 )
{
return V_4 > V_241 || V_242 + V_4 > V_240 ;
}
int F_92 ( struct V_15 * V_16 , union V_226 * V_227 ,
struct V_228 * V_243 )
{
T_1 type = V_16 -> V_18 . V_1 ;
bool V_231 = V_16 -> V_232 ;
const T_1 * V_230 ;
T_7 V_241 = V_227 -> V_235 . V_4 ;
const void * V_240 = ( void * ) V_227 + V_241 ;
T_1 V_244 ;
union V_233 V_234 ;
memset ( V_243 , 0 , sizeof( * V_243 ) ) ;
V_243 -> V_159 = V_243 -> V_201 = V_243 -> V_239 = - 1 ;
V_243 -> V_238 = V_243 -> V_48 = V_243 -> time = - 1ULL ;
V_243 -> V_137 = 1 ;
V_243 -> V_245 = 0 ;
if ( V_227 -> V_235 . type != V_246 ) {
if ( ! V_16 -> V_18 . V_103 )
return 0 ;
return F_88 ( V_16 , V_227 , V_243 ) ;
}
V_230 = V_227 -> V_229 . V_230 ;
if ( V_16 -> V_29 + sizeof( V_227 -> V_235 ) > V_227 -> V_235 . V_4 )
return - V_247 ;
V_243 -> V_48 = - 1ULL ;
if ( type & V_7 ) {
V_243 -> V_48 = * V_230 ;
V_230 ++ ;
}
if ( type & V_9 ) {
V_243 -> V_248 = * V_230 ;
V_230 ++ ;
}
if ( type & V_10 ) {
V_234 . V_236 = * V_230 ;
if ( V_231 ) {
V_234 . V_236 = F_89 ( V_234 . V_236 ) ;
V_234 . V_237 [ 0 ] = F_90 ( V_234 . V_237 [ 0 ] ) ;
V_234 . V_237 [ 1 ] = F_90 ( V_234 . V_237 [ 1 ] ) ;
}
V_243 -> V_201 = V_234 . V_237 [ 0 ] ;
V_243 -> V_239 = V_234 . V_237 [ 1 ] ;
V_230 ++ ;
}
if ( type & V_11 ) {
V_243 -> time = * V_230 ;
V_230 ++ ;
}
V_243 -> V_69 = 0 ;
if ( type & V_12 ) {
V_243 -> V_69 = * V_230 ;
V_230 ++ ;
}
if ( type & V_8 ) {
V_243 -> V_48 = * V_230 ;
V_230 ++ ;
}
if ( type & V_14 ) {
V_243 -> V_238 = * V_230 ;
V_230 ++ ;
}
if ( type & V_13 ) {
V_234 . V_236 = * V_230 ;
if ( V_231 ) {
V_234 . V_236 = F_89 ( V_234 . V_236 ) ;
V_234 . V_237 [ 0 ] = F_90 ( V_234 . V_237 [ 0 ] ) ;
}
V_243 -> V_159 = V_234 . V_237 [ 0 ] ;
V_230 ++ ;
}
if ( type & V_44 ) {
V_243 -> V_137 = * V_230 ;
V_230 ++ ;
}
if ( type & V_249 ) {
T_1 V_33 = V_16 -> V_18 . V_33 ;
F_93 ( V_230 ) ;
if ( V_33 & V_112 )
V_243 -> V_250 . V_251 . V_206 = * V_230 ;
else
V_243 -> V_250 . V_252 . V_253 = * V_230 ;
V_230 ++ ;
if ( V_33 & V_254 ) {
F_93 ( V_230 ) ;
V_243 -> V_250 . V_255 = * V_230 ;
V_230 ++ ;
}
if ( V_33 & V_256 ) {
F_93 ( V_230 ) ;
V_243 -> V_250 . V_257 = * V_230 ;
V_230 ++ ;
}
if ( V_33 & V_112 ) {
const T_1 V_258 = V_259 /
sizeof( struct V_260 ) ;
if ( V_243 -> V_250 . V_251 . V_206 > V_258 )
return - V_247 ;
V_244 = V_243 -> V_250 . V_251 . V_206 *
sizeof( struct V_260 ) ;
F_94 ( V_230 , V_244 , V_241 ) ;
V_243 -> V_250 . V_251 . V_261 =
(struct V_260 * ) V_230 ;
V_230 = ( void * ) V_230 + V_244 ;
} else {
F_93 ( V_230 ) ;
V_243 -> V_250 . V_252 . V_48 = * V_230 ;
V_230 ++ ;
}
}
if ( type & V_262 ) {
const T_1 V_263 = V_259 / sizeof( T_1 ) ;
F_93 ( V_230 ) ;
V_243 -> V_264 = (struct V_265 * ) V_230 ++ ;
if ( V_243 -> V_264 -> V_206 > V_263 )
return - V_247 ;
V_244 = V_243 -> V_264 -> V_206 * sizeof( T_1 ) ;
F_94 ( V_230 , V_244 , V_241 ) ;
V_230 = ( void * ) V_230 + V_244 ;
}
if ( type & V_43 ) {
F_93 ( V_230 ) ;
V_234 . V_236 = * V_230 ;
if ( F_95 ( V_231 ,
L_33 ) ) {
V_234 . V_236 = F_89 ( V_234 . V_236 ) ;
V_234 . V_237 [ 0 ] = F_90 ( V_234 . V_237 [ 0 ] ) ;
V_234 . V_237 [ 1 ] = F_90 ( V_234 . V_237 [ 1 ] ) ;
}
V_243 -> V_266 = V_234 . V_237 [ 0 ] ;
V_230 = ( void * ) V_230 + sizeof( V_267 ) ;
F_94 ( V_230 , V_243 -> V_266 , V_241 ) ;
V_243 -> V_268 = ( void * ) V_230 ;
V_230 = ( void * ) V_230 + V_243 -> V_266 ;
}
if ( type & V_269 ) {
const T_1 V_270 = V_259 /
sizeof( struct V_271 ) ;
F_93 ( V_230 ) ;
V_243 -> V_145 = (struct V_145 * ) V_230 ++ ;
if ( V_243 -> V_145 -> V_206 > V_270 )
return - V_247 ;
V_244 = V_243 -> V_145 -> V_206 * sizeof( struct V_271 ) ;
F_94 ( V_230 , V_244 , V_241 ) ;
V_230 = ( void * ) V_230 + V_244 ;
}
if ( type & V_272 ) {
F_93 ( V_230 ) ;
V_243 -> V_273 . V_274 = * V_230 ;
V_230 ++ ;
if ( V_243 -> V_273 . V_274 ) {
T_1 V_275 = V_16 -> V_18 . V_131 ;
V_244 = F_96 ( V_275 ) * sizeof( T_1 ) ;
F_94 ( V_230 , V_244 , V_241 ) ;
V_243 -> V_273 . V_276 = ( T_1 * ) V_230 ;
V_230 = ( void * ) V_230 + V_244 ;
}
}
if ( type & V_277 ) {
F_93 ( V_230 ) ;
V_244 = * V_230 ++ ;
V_243 -> V_278 . V_242 = ( ( char * ) ( V_230 - 1 )
- ( char * ) V_227 ) ;
if ( ! V_244 ) {
V_243 -> V_278 . V_4 = 0 ;
} else {
F_94 ( V_230 , V_244 , V_241 ) ;
V_243 -> V_278 . V_243 = ( char * ) V_230 ;
V_230 = ( void * ) V_230 + V_244 ;
F_93 ( V_230 ) ;
V_243 -> V_278 . V_4 = * V_230 ++ ;
if ( F_95 ( V_243 -> V_278 . V_4 > V_244 ,
L_34 ) )
return - V_247 ;
}
}
V_243 -> V_245 = 0 ;
if ( type & V_279 ) {
F_93 ( V_230 ) ;
V_243 -> V_245 = * V_230 ;
V_230 ++ ;
}
V_243 -> V_280 = V_281 ;
if ( type & V_282 ) {
F_93 ( V_230 ) ;
V_243 -> V_280 = * V_230 ;
V_230 ++ ;
}
V_243 -> V_283 = 0 ;
if ( type & V_284 ) {
F_93 ( V_230 ) ;
V_243 -> V_283 = * V_230 ;
V_230 ++ ;
}
return 0 ;
}
T_2 F_97 ( const struct V_228 * V_229 , T_1 type ,
T_1 V_131 , T_1 V_33 )
{
T_2 V_244 , V_78 = sizeof( struct V_285 ) ;
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
if ( type & V_249 ) {
V_78 += sizeof( T_1 ) ;
if ( V_33 & V_254 )
V_78 += sizeof( T_1 ) ;
if ( V_33 & V_256 )
V_78 += sizeof( T_1 ) ;
if ( V_33 & V_112 ) {
V_244 = V_229 -> V_250 . V_251 . V_206 *
sizeof( struct V_260 ) ;
V_78 += V_244 ;
} else {
V_78 += sizeof( T_1 ) ;
}
}
if ( type & V_262 ) {
V_244 = ( V_229 -> V_264 -> V_206 + 1 ) * sizeof( T_1 ) ;
V_78 += V_244 ;
}
if ( type & V_43 ) {
V_78 += sizeof( V_267 ) ;
V_78 += V_229 -> V_266 ;
}
if ( type & V_269 ) {
V_244 = V_229 -> V_145 -> V_206 * sizeof( struct V_271 ) ;
V_244 += sizeof( T_1 ) ;
V_78 += V_244 ;
}
if ( type & V_272 ) {
if ( V_229 -> V_273 . V_274 ) {
V_78 += sizeof( T_1 ) ;
V_244 = F_96 ( V_131 ) * sizeof( T_1 ) ;
V_78 += V_244 ;
} else {
V_78 += sizeof( T_1 ) ;
}
}
if ( type & V_277 ) {
V_244 = V_229 -> V_278 . V_4 ;
V_78 += sizeof( T_1 ) ;
if ( V_244 ) {
V_78 += V_244 ;
V_78 += sizeof( T_1 ) ;
}
}
if ( type & V_279 )
V_78 += sizeof( T_1 ) ;
if ( type & V_282 )
V_78 += sizeof( T_1 ) ;
if ( type & V_284 )
V_78 += sizeof( T_1 ) ;
return V_78 ;
}
int F_98 ( union V_226 * V_227 , T_1 type ,
T_1 V_131 , T_1 V_33 ,
const struct V_228 * V_229 ,
bool V_231 )
{
T_1 * V_230 ;
T_2 V_244 ;
union V_233 V_234 ;
V_230 = V_227 -> V_229 . V_230 ;
if ( type & V_7 ) {
* V_230 = V_229 -> V_48 ;
V_230 ++ ;
}
if ( type & V_9 ) {
* V_230 = V_229 -> V_248 ;
V_230 ++ ;
}
if ( type & V_10 ) {
V_234 . V_237 [ 0 ] = V_229 -> V_201 ;
V_234 . V_237 [ 1 ] = V_229 -> V_239 ;
if ( V_231 ) {
V_234 . V_237 [ 0 ] = F_90 ( V_234 . V_237 [ 0 ] ) ;
V_234 . V_237 [ 1 ] = F_90 ( V_234 . V_237 [ 1 ] ) ;
V_234 . V_236 = F_89 ( V_234 . V_236 ) ;
}
* V_230 = V_234 . V_236 ;
V_230 ++ ;
}
if ( type & V_11 ) {
* V_230 = V_229 -> time ;
V_230 ++ ;
}
if ( type & V_12 ) {
* V_230 = V_229 -> V_69 ;
V_230 ++ ;
}
if ( type & V_8 ) {
* V_230 = V_229 -> V_48 ;
V_230 ++ ;
}
if ( type & V_14 ) {
* V_230 = V_229 -> V_238 ;
V_230 ++ ;
}
if ( type & V_13 ) {
V_234 . V_237 [ 0 ] = V_229 -> V_159 ;
if ( V_231 ) {
V_234 . V_237 [ 0 ] = F_90 ( V_234 . V_237 [ 0 ] ) ;
V_234 . V_236 = F_89 ( V_234 . V_236 ) ;
}
* V_230 = V_234 . V_236 ;
V_230 ++ ;
}
if ( type & V_44 ) {
* V_230 = V_229 -> V_137 ;
V_230 ++ ;
}
if ( type & V_249 ) {
if ( V_33 & V_112 )
* V_230 = V_229 -> V_250 . V_251 . V_206 ;
else
* V_230 = V_229 -> V_250 . V_252 . V_253 ;
V_230 ++ ;
if ( V_33 & V_254 ) {
* V_230 = V_229 -> V_250 . V_255 ;
V_230 ++ ;
}
if ( V_33 & V_256 ) {
* V_230 = V_229 -> V_250 . V_257 ;
V_230 ++ ;
}
if ( V_33 & V_112 ) {
V_244 = V_229 -> V_250 . V_251 . V_206 *
sizeof( struct V_260 ) ;
memcpy ( V_230 , V_229 -> V_250 . V_251 . V_261 , V_244 ) ;
V_230 = ( void * ) V_230 + V_244 ;
} else {
* V_230 = V_229 -> V_250 . V_252 . V_48 ;
V_230 ++ ;
}
}
if ( type & V_262 ) {
V_244 = ( V_229 -> V_264 -> V_206 + 1 ) * sizeof( T_1 ) ;
memcpy ( V_230 , V_229 -> V_264 , V_244 ) ;
V_230 = ( void * ) V_230 + V_244 ;
}
if ( type & V_43 ) {
V_234 . V_237 [ 0 ] = V_229 -> V_266 ;
if ( F_95 ( V_231 ,
L_33 ) ) {
V_234 . V_237 [ 0 ] = F_90 ( V_234 . V_237 [ 0 ] ) ;
V_234 . V_237 [ 1 ] = F_90 ( V_234 . V_237 [ 1 ] ) ;
V_234 . V_236 = F_89 ( V_234 . V_236 ) ;
}
* V_230 = V_234 . V_236 ;
V_230 = ( void * ) V_230 + sizeof( V_267 ) ;
memcpy ( V_230 , V_229 -> V_268 , V_229 -> V_266 ) ;
V_230 = ( void * ) V_230 + V_229 -> V_266 ;
}
if ( type & V_269 ) {
V_244 = V_229 -> V_145 -> V_206 * sizeof( struct V_271 ) ;
V_244 += sizeof( T_1 ) ;
memcpy ( V_230 , V_229 -> V_145 , V_244 ) ;
V_230 = ( void * ) V_230 + V_244 ;
}
if ( type & V_272 ) {
if ( V_229 -> V_273 . V_274 ) {
* V_230 ++ = V_229 -> V_273 . V_274 ;
V_244 = F_96 ( V_131 ) * sizeof( T_1 ) ;
memcpy ( V_230 , V_229 -> V_273 . V_276 , V_244 ) ;
V_230 = ( void * ) V_230 + V_244 ;
} else {
* V_230 ++ = 0 ;
}
}
if ( type & V_277 ) {
V_244 = V_229 -> V_278 . V_4 ;
* V_230 ++ = V_244 ;
if ( V_244 ) {
memcpy ( V_230 , V_229 -> V_278 . V_243 , V_244 ) ;
V_230 = ( void * ) V_230 + V_244 ;
* V_230 ++ = V_244 ;
}
}
if ( type & V_279 ) {
* V_230 = V_229 -> V_245 ;
V_230 ++ ;
}
if ( type & V_282 ) {
* V_230 = V_229 -> V_280 ;
V_230 ++ ;
}
if ( type & V_284 ) {
* V_230 = V_229 -> V_283 ;
V_230 ++ ;
}
return 0 ;
}
struct V_286 * F_99 ( struct V_15 * V_16 , const char * V_41 )
{
return F_100 ( V_16 -> V_46 , V_41 ) ;
}
void * F_101 ( struct V_15 * V_16 , struct V_228 * V_229 ,
const char * V_41 )
{
struct V_286 * V_287 = F_99 ( V_16 , V_41 ) ;
int V_242 ;
if ( ! V_287 )
return NULL ;
V_242 = V_287 -> V_242 ;
if ( V_287 -> V_200 & V_288 ) {
V_242 = * ( int * ) ( V_229 -> V_268 + V_287 -> V_242 ) ;
V_242 &= 0xffff ;
}
return V_229 -> V_268 + V_242 ;
}
T_1 F_102 ( struct V_15 * V_16 , struct V_228 * V_229 ,
const char * V_41 )
{
struct V_286 * V_287 = F_99 ( V_16 , V_41 ) ;
void * V_289 ;
T_1 V_253 ;
if ( ! V_287 )
return 0 ;
V_289 = V_229 -> V_268 + V_287 -> V_242 ;
switch ( V_287 -> V_4 ) {
case 1 :
return * ( T_5 * ) V_289 ;
case 2 :
V_253 = * ( T_7 * ) V_289 ;
break;
case 4 :
V_253 = * ( V_267 * ) V_289 ;
break;
case 8 :
V_253 = * ( T_1 * ) V_289 ;
break;
default:
return 0 ;
}
if ( ! V_16 -> V_232 )
return V_253 ;
switch ( V_287 -> V_4 ) {
case 2 :
return F_103 ( V_253 ) ;
case 4 :
return F_90 ( V_253 ) ;
case 8 :
return F_89 ( V_253 ) ;
default:
return 0 ;
}
return 0 ;
}
static int F_104 ( T_6 * V_184 , bool * V_290 , const char * V_291 , ... )
{
T_8 args ;
int V_87 = 0 ;
if ( ! * V_290 ) {
V_87 += fprintf ( V_184 , L_35 ) ;
} else {
V_87 += fprintf ( V_184 , L_9 ) ;
* V_290 = false ;
}
va_start ( args , V_291 ) ;
V_87 += vfprintf ( V_184 , V_291 , args ) ;
va_end ( args ) ;
return V_87 ;
}
static int F_105 ( T_6 * V_184 , bool * V_290 , const char * V_287 , T_1 V_253 )
{
if ( V_253 == 0 )
return 0 ;
return F_104 ( V_184 , V_290 , L_36 V_292 , V_287 , V_253 ) ;
}
static int F_106 ( T_6 * V_184 , const char * V_287 , T_1 V_253 ,
struct V_293 * V_294 , bool * V_290 )
{
int V_5 = 0 , V_295 = F_104 ( V_184 , V_290 , L_37 , V_287 ) ;
bool V_296 = true ;
do {
if ( V_253 & V_294 [ V_5 ] . V_28 ) {
V_295 += fprintf ( V_184 , L_38 , V_296 ? L_1 : L_39 , V_294 [ V_5 ] . V_41 ) ;
V_296 = false ;
}
} while ( V_294 [ ++ V_5 ] . V_41 != NULL );
return V_295 ;
}
static int F_107 ( T_6 * V_184 , bool * V_290 , T_1 V_253 )
{
#define F_108 ( T_9 ) { PERF_SAMPLE_##n, #n }
struct V_293 V_294 [] = {
F_108 ( V_107 ) , F_108 ( V_108 ) , F_108 ( TIME ) , F_108 ( V_124 ) ,
F_108 ( V_110 ) , F_108 ( V_127 ) , F_108 ( V_31 ) , F_108 ( V_136 ) ,
F_108 ( V_118 ) , F_108 ( V_297 ) , F_108 ( V_140 ) ,
F_108 ( V_146 ) , F_108 ( V_129 ) , F_108 ( V_130 ) ,
F_108 ( V_32 ) ,
{ . V_41 = NULL , }
} ;
#undef F_108
return F_106 ( V_184 , L_40 , V_253 , V_294 , V_290 ) ;
}
static int F_109 ( T_6 * V_184 , bool * V_290 , T_1 V_253 )
{
#define F_108 ( T_9 ) { PERF_FORMAT_##n, #n }
struct V_293 V_294 [] = {
F_108 ( V_298 ) , F_108 ( V_299 ) ,
F_108 ( V_31 ) , F_108 ( V_300 ) ,
{ . V_41 = NULL , }
} ;
#undef F_108
return F_106 ( V_184 , L_41 , V_253 , V_294 , V_290 ) ;
}
int F_110 ( struct V_15 * V_16 ,
struct V_301 * V_302 , T_6 * V_184 )
{
bool V_290 = true ;
int V_295 = 0 ;
if ( V_302 -> V_303 ) {
struct V_15 * V_95 ;
if ( ! F_43 ( V_16 ) )
return 0 ;
if ( V_16 -> V_111 > 1 )
V_295 += fprintf ( V_184 , L_42 , V_16 -> V_93 ? : L_1 ) ;
V_295 += fprintf ( V_184 , L_6 , F_36 ( V_16 ) ) ;
F_40 (pos, evsel)
V_295 += fprintf ( V_184 , L_43 , F_36 ( V_95 ) ) ;
if ( V_16 -> V_111 > 1 )
V_295 += fprintf ( V_184 , L_44 ) ;
goto V_304;
}
V_295 += fprintf ( V_184 , L_6 , F_36 ( V_16 ) ) ;
if ( V_302 -> V_210 || V_302 -> V_117 ) {
V_295 += F_104 ( V_184 , & V_290 , L_45 V_292 ,
( T_1 ) V_16 -> V_18 . V_119 ) ;
}
if ( V_302 -> V_210 ) {
F_111 ( type ) ;
F_111 ( V_47 ) ;
F_111 ( V_193 ) ;
F_111 ( V_195 ) ;
F_111 ( V_4 ) ;
V_295 += F_107 ( V_184 , & V_290 , V_16 -> V_18 . V_1 ) ;
if ( V_16 -> V_18 . V_33 )
V_295 += F_109 ( V_184 , & V_290 , V_16 -> V_18 . V_33 ) ;
F_111 ( V_154 ) ;
F_111 ( V_105 ) ;
F_111 ( V_186 ) ;
F_111 ( V_187 ) ;
F_111 ( V_57 ) ;
F_111 ( V_56 ) ;
F_111 ( V_58 ) ;
F_111 ( V_188 ) ;
F_111 ( V_150 ) ;
F_111 ( V_191 ) ;
F_111 ( V_151 ) ;
F_111 ( V_117 ) ;
F_111 ( V_122 ) ;
F_111 ( V_156 ) ;
F_111 ( V_189 ) ;
F_111 ( V_143 ) ;
F_111 ( V_62 ) ;
F_111 ( V_125 ) ;
F_111 ( V_103 ) ;
F_111 ( V_63 ) ;
F_111 ( V_64 ) ;
F_111 ( V_305 ) ;
F_111 ( V_144 ) ;
F_111 ( V_75 ) ;
F_111 ( V_147 ) ;
}
V_304:
fputc ( '\n' , V_184 ) ;
return ++ V_295 ;
}
bool F_112 ( struct V_15 * V_16 , int V_82 ,
char * V_306 , T_2 V_307 )
{
if ( ( V_82 == V_308 || V_82 == V_309 || V_82 == V_310 ) &&
V_16 -> V_18 . type == V_89 &&
V_16 -> V_18 . V_47 == V_311 ) {
F_24 ( V_306 , V_307 , L_6 ,
L_46 ) ;
V_16 -> V_18 . type = V_91 ;
V_16 -> V_18 . V_47 = V_312 ;
F_20 ( & V_16 -> V_41 ) ;
return true ;
}
return false ;
}
int F_113 ( struct V_15 * V_16 , struct V_100 * V_100 ,
int V_82 , char * V_306 , T_2 V_4 )
{
switch ( V_82 ) {
case V_313 :
case V_314 :
return F_24 ( V_306 , V_4 ,
L_47
L_48
L_49
L_50
L_51
L_52 ,
V_100 -> V_315 ? L_53 : L_1 ) ;
case V_308 :
return F_24 ( V_306 , V_4 , L_54 ,
F_36 ( V_16 ) ) ;
case V_216 :
return F_24 ( V_306 , V_4 , L_6 ,
L_55
L_56 ) ;
case V_310 :
if ( V_100 -> V_316 )
return F_24 ( V_306 , V_4 , L_6 ,
L_57 ) ;
break;
case V_317 :
if ( V_16 -> V_18 . V_62 )
return F_24 ( V_306 , V_4 , L_6 ,
L_58 ) ;
#if F_114 ( V_318 ) || F_114 ( V_319 )
if ( V_16 -> V_18 . type == V_89 )
return F_24 ( V_306 , V_4 , L_6 ,
L_59
L_60 ) ;
#endif
break;
default:
break;
}
return F_24 ( V_306 , V_4 ,
L_61
L_62
L_63 ,
V_82 , strerror ( V_82 ) , F_36 ( V_16 ) ) ;
}
