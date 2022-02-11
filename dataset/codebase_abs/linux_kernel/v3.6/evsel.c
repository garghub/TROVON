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
static const char * F_8 ( T_1 V_20 )
{
if ( V_20 < V_21 && V_22 [ V_20 ] )
return V_22 [ V_20 ] ;
return L_1 ;
}
static int F_9 ( struct V_13 * V_14 , char * V_23 , T_2 V_4 )
{
int V_24 = 0 , V_25 = 0 ;
struct V_15 * V_16 = & V_14 -> V_16 ;
bool V_26 = false ;
#define F_10 ( T_3 , T_4 ) do { \
if (!attr->exclude_##context) { \
if (!colon) colon = ++r; \
r += scnprintf(bf + r, size - r, "%c", mod); \
} } while(0)
if ( V_16 -> V_27 || V_16 -> V_28 || V_16 -> V_29 ) {
F_10 ( V_30 , 'k' ) ;
F_10 ( V_31 , 'u' ) ;
F_10 ( V_32 , 'h' ) ;
V_26 = true ;
}
if ( V_16 -> V_33 ) {
if ( ! V_24 )
V_24 = ++ V_25 ;
V_25 += F_11 ( V_23 + V_25 , V_4 - V_25 , L_2 , V_16 -> V_33 , L_3 ) ;
V_26 = true ;
}
if ( V_16 -> V_34 || V_16 -> V_35 == V_26 ) {
F_10 ( V_36 , 'H' ) ;
F_10 ( V_37 , 'G' ) ;
}
#undef F_10
if ( V_24 )
V_23 [ V_24 - 1 ] = ':' ;
return V_25 ;
}
static int F_12 ( struct V_13 * V_14 , char * V_23 , T_2 V_4 )
{
int V_25 = F_11 ( V_23 , V_4 , L_4 , F_8 ( V_14 -> V_16 . V_20 ) ) ;
return V_25 + F_9 ( V_14 , V_23 + V_25 , V_4 - V_25 ) ;
}
static const char * F_13 ( T_1 V_20 )
{
if ( V_20 < V_38 && V_39 [ V_20 ] )
return V_39 [ V_20 ] ;
return L_5 ;
}
static int F_14 ( struct V_13 * V_14 , char * V_23 , T_2 V_4 )
{
int V_25 = F_11 ( V_23 , V_4 , L_4 , F_13 ( V_14 -> V_16 . V_20 ) ) ;
return V_25 + F_9 ( V_14 , V_23 + V_25 , V_4 - V_25 ) ;
}
static int F_15 ( char * V_23 , T_2 V_4 , T_1 V_40 , T_1 type )
{
int V_25 ;
V_25 = F_11 ( V_23 , V_4 , L_6 V_41 L_7 , V_40 ) ;
if ( type & V_42 )
V_25 += F_11 ( V_23 + V_25 , V_4 - V_25 , L_8 ) ;
if ( type & V_43 )
V_25 += F_11 ( V_23 + V_25 , V_4 - V_25 , L_9 ) ;
if ( type & V_44 )
V_25 += F_11 ( V_23 + V_25 , V_4 - V_25 , L_10 ) ;
return V_25 ;
}
static int F_16 ( struct V_13 * V_14 , char * V_23 , T_2 V_4 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
int V_25 = F_15 ( V_23 , V_4 , V_16 -> V_45 , V_16 -> V_46 ) ;
return V_25 + F_9 ( V_14 , V_23 + V_25 , V_4 - V_25 ) ;
}
bool F_17 ( T_5 type , T_5 V_47 )
{
if ( V_48 [ type ] & F_18 ( V_47 ) )
return true ;
else
return false ;
}
int F_19 ( T_5 type , T_5 V_47 , T_5 V_49 ,
char * V_23 , T_2 V_4 )
{
if ( V_49 ) {
return F_11 ( V_23 , V_4 , L_11 , V_50 [ type ] [ 0 ] ,
V_51 [ V_47 ] [ 0 ] ,
V_52 [ V_49 ] [ 0 ] ) ;
}
return F_11 ( V_23 , V_4 , L_12 , V_50 [ type ] [ 0 ] ,
V_51 [ V_47 ] [ 1 ] ) ;
}
static int F_20 ( T_1 V_20 , char * V_23 , T_2 V_4 )
{
T_5 V_47 , V_49 , type = ( V_20 >> 0 ) & 0xff ;
const char * V_53 = L_13 ;
if ( type > V_54 )
goto V_55;
V_47 = ( V_20 >> 8 ) & 0xff ;
V_53 = L_14 ;
if ( V_47 > V_56 )
goto V_55;
V_49 = ( V_20 >> 16 ) & 0xff ;
V_53 = L_15 ;
if ( V_49 > V_57 )
goto V_55;
V_53 = L_16 ;
if ( ! F_17 ( type , V_47 ) )
goto V_55;
return F_19 ( type , V_47 , V_49 , V_23 , V_4 ) ;
V_55:
return F_11 ( V_23 , V_4 , L_4 , V_53 ) ;
}
static int F_21 ( struct V_13 * V_14 , char * V_23 , T_2 V_4 )
{
int V_58 = F_20 ( V_14 -> V_16 . V_20 , V_23 , V_4 ) ;
return V_58 + F_9 ( V_14 , V_23 + V_58 , V_4 - V_58 ) ;
}
static int F_22 ( struct V_13 * V_14 , char * V_23 , T_2 V_4 )
{
int V_58 = F_11 ( V_23 , V_4 , L_17 V_41 , V_14 -> V_16 . V_20 ) ;
return V_58 + F_9 ( V_14 , V_23 + V_58 , V_4 - V_58 ) ;
}
const char * F_23 ( struct V_13 * V_14 )
{
char V_23 [ 128 ] ;
if ( V_14 -> V_59 )
return V_14 -> V_59 ;
switch ( V_14 -> V_16 . type ) {
case V_60 :
F_22 ( V_14 , V_23 , sizeof( V_23 ) ) ;
break;
case V_61 :
F_12 ( V_14 , V_23 , sizeof( V_23 ) ) ;
break;
case V_62 :
F_21 ( V_14 , V_23 , sizeof( V_23 ) ) ;
break;
case V_63 :
F_14 ( V_14 , V_23 , sizeof( V_23 ) ) ;
break;
case V_64 :
F_11 ( V_23 , sizeof( V_23 ) , L_4 , L_18 ) ;
break;
case V_65 :
F_16 ( V_14 , V_23 , sizeof( V_23 ) ) ;
break;
default:
F_11 ( V_23 , sizeof( V_23 ) , L_4 , L_19 ) ;
break;
}
V_14 -> V_59 = F_24 ( V_23 ) ;
return V_14 -> V_59 ? : L_20 ;
}
void F_25 ( struct V_13 * V_14 , struct V_66 * V_67 ,
struct V_13 * V_68 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
int V_69 = ! V_14 -> V_17 ;
V_16 -> V_70 = 1 ;
V_16 -> V_71 = V_67 -> V_72 ? 0 : 1 ;
V_16 -> V_73 = ! V_67 -> V_74 ;
V_16 -> V_75 = V_76 |
V_77 |
V_78 ;
V_16 -> V_1 |= V_79 | V_80 ;
if ( ! V_16 -> V_81 || ( V_67 -> V_82 != V_83 &&
V_67 -> V_84 != V_85 ) ) {
if ( V_67 -> V_86 ) {
V_16 -> V_1 |= V_87 ;
V_16 -> V_86 = 1 ;
V_16 -> V_88 = V_67 -> V_86 ;
} else {
V_16 -> V_81 = V_67 -> V_89 ;
}
}
if ( V_67 -> V_90 )
V_16 -> V_88 = 0 ;
if ( V_67 -> V_91 )
V_16 -> V_91 = 1 ;
if ( V_67 -> V_92 ) {
V_16 -> V_1 |= V_93 ;
V_16 -> V_94 = V_69 ;
}
if ( V_67 -> V_95 )
V_16 -> V_1 |= V_96 ;
if ( F_26 ( & V_67 -> V_97 ) )
V_16 -> V_1 |= V_98 ;
if ( V_67 -> V_99 )
V_16 -> V_1 |= V_87 ;
if ( ! V_67 -> V_72 &&
( V_67 -> V_100 || ! V_67 -> V_74 ||
F_26 ( & V_67 -> V_97 ) ) )
V_16 -> V_1 |= V_101 ;
if ( V_67 -> V_102 ) {
V_16 -> V_1 |= V_101 ;
V_16 -> V_1 |= V_103 ;
V_16 -> V_1 |= V_98 ;
}
if ( V_67 -> V_104 ) {
V_16 -> V_105 = 0 ;
V_16 -> V_106 = 1 ;
}
if ( V_67 -> V_107 ) {
V_16 -> V_1 |= V_108 ;
V_16 -> V_109 = V_67 -> V_107 ;
}
V_16 -> V_110 = V_69 ;
V_16 -> V_111 = V_69 ;
if ( F_27 ( & V_67 -> V_97 ) &&
( ! V_67 -> V_112 || V_14 == V_68 ) ) {
V_16 -> V_113 = 1 ;
}
}
int F_28 ( struct V_13 * V_14 , int V_114 , int V_115 )
{
int V_116 , V_117 ;
V_14 -> V_118 = F_29 ( V_114 , V_115 , sizeof( int ) ) ;
if ( V_14 -> V_118 ) {
for ( V_116 = 0 ; V_116 < V_114 ; V_116 ++ ) {
for ( V_117 = 0 ; V_117 < V_115 ; V_117 ++ ) {
F_30 ( V_14 , V_116 , V_117 ) = - 1 ;
}
}
}
return V_14 -> V_118 != NULL ? 0 : - V_119 ;
}
int F_31 ( struct V_13 * V_14 , int V_114 , int V_115 )
{
V_14 -> V_120 = F_29 ( V_114 , V_115 , sizeof( struct V_121 ) ) ;
if ( V_14 -> V_120 == NULL )
return - V_119 ;
V_14 -> V_122 = F_7 ( V_114 * V_115 * sizeof( T_1 ) ) ;
if ( V_14 -> V_122 == NULL ) {
F_32 ( V_14 -> V_120 ) ;
V_14 -> V_120 = NULL ;
return - V_119 ;
}
return 0 ;
}
int F_33 ( struct V_13 * V_14 , int V_114 )
{
V_14 -> V_123 = F_7 ( ( sizeof( * V_14 -> V_123 ) +
( V_114 * sizeof( struct V_124 ) ) ) ) ;
return V_14 -> V_123 != NULL ? 0 : - V_119 ;
}
void F_34 ( struct V_13 * V_14 )
{
F_32 ( V_14 -> V_118 ) ;
V_14 -> V_118 = NULL ;
}
void F_35 ( struct V_13 * V_14 )
{
F_32 ( V_14 -> V_120 ) ;
V_14 -> V_120 = NULL ;
free ( V_14 -> V_122 ) ;
V_14 -> V_122 = NULL ;
}
void F_36 ( struct V_13 * V_14 , int V_114 , int V_115 )
{
int V_116 , V_117 ;
for ( V_116 = 0 ; V_116 < V_114 ; V_116 ++ )
for ( V_117 = 0 ; V_117 < V_115 ; ++ V_117 ) {
F_37 ( F_30 ( V_14 , V_116 , V_117 ) ) ;
F_30 ( V_14 , V_116 , V_117 ) = - 1 ;
}
}
void F_38 ( struct V_13 * V_14 )
{
assert ( F_39 ( & V_14 -> V_18 ) ) ;
F_32 ( V_14 -> V_118 ) ;
F_32 ( V_14 -> V_120 ) ;
free ( V_14 -> V_122 ) ;
}
void F_40 ( struct V_13 * V_14 )
{
F_38 ( V_14 ) ;
F_41 ( V_14 -> V_125 ) ;
free ( V_14 -> V_59 ) ;
free ( V_14 ) ;
}
int F_42 ( struct V_13 * V_14 ,
int V_116 , int V_117 , bool V_126 )
{
struct V_124 V_127 ;
T_2 V_128 = V_126 ? 3 : 1 ;
if ( F_30 ( V_14 , V_116 , V_117 ) < 0 )
return - V_129 ;
if ( V_14 -> V_123 == NULL && F_33 ( V_14 , V_116 + 1 ) < 0 )
return - V_119 ;
if ( F_43 ( F_30 ( V_14 , V_116 , V_117 ) , & V_127 , V_128 * sizeof( T_1 ) ) < 0 )
return - V_130 ;
if ( V_126 ) {
if ( V_127 . V_131 == 0 )
V_127 . V_132 = 0 ;
else if ( V_127 . V_131 < V_127 . V_133 )
V_127 . V_132 = ( T_1 ) ( ( double ) V_127 . V_132 * V_127 . V_133 / V_127 . V_131 + 0.5 ) ;
} else
V_127 . V_133 = V_127 . V_131 = 0 ;
V_14 -> V_123 -> V_116 [ V_116 ] = V_127 ;
return 0 ;
}
int F_44 ( struct V_13 * V_14 ,
int V_114 , int V_115 , bool V_126 )
{
T_2 V_128 = V_126 ? 3 : 1 ;
int V_116 , V_117 ;
struct V_124 * V_134 = & V_14 -> V_123 -> V_134 , V_127 ;
V_134 -> V_132 = V_134 -> V_133 = V_134 -> V_131 = 0 ;
for ( V_116 = 0 ; V_116 < V_114 ; V_116 ++ ) {
for ( V_117 = 0 ; V_117 < V_115 ; V_117 ++ ) {
if ( F_30 ( V_14 , V_116 , V_117 ) < 0 )
continue;
if ( F_43 ( F_30 ( V_14 , V_116 , V_117 ) ,
& V_127 , V_128 * sizeof( T_1 ) ) < 0 )
return - V_130 ;
V_134 -> V_132 += V_127 . V_132 ;
if ( V_126 ) {
V_134 -> V_133 += V_127 . V_133 ;
V_134 -> V_131 += V_127 . V_131 ;
}
}
}
V_14 -> V_123 -> V_135 = 0 ;
if ( V_126 ) {
if ( V_134 -> V_131 == 0 ) {
V_14 -> V_123 -> V_135 = - 1 ;
V_134 -> V_132 = 0 ;
return 0 ;
}
if ( V_134 -> V_131 < V_134 -> V_133 ) {
V_14 -> V_123 -> V_135 = 1 ;
V_134 -> V_132 = ( T_1 ) ( ( double ) V_134 -> V_132 * V_134 -> V_133 / V_134 -> V_131 + 0.5 ) ;
}
} else
V_134 -> V_133 = V_134 -> V_131 = 0 ;
return 0 ;
}
static int F_45 ( struct V_13 * V_14 , struct V_136 * V_137 ,
struct V_138 * V_139 , bool V_112 ,
struct V_140 * V_141 )
{
int V_116 , V_117 ;
unsigned long V_142 = 0 ;
int V_143 = - 1 , V_53 ;
if ( V_14 -> V_118 == NULL &&
F_28 ( V_14 , V_137 -> V_144 , V_139 -> V_144 ) < 0 )
return - V_119 ;
if ( V_14 -> V_125 ) {
V_142 = V_145 ;
V_143 = V_14 -> V_125 -> V_118 ;
}
for ( V_116 = 0 ; V_116 < V_137 -> V_144 ; V_116 ++ ) {
int V_146 = V_141 ? F_46 ( V_141 , V_116 ) : - 1 ;
for ( V_117 = 0 ; V_117 < V_139 -> V_144 ; V_117 ++ ) {
if ( ! V_14 -> V_125 )
V_143 = V_139 -> V_147 [ V_117 ] ;
F_30 ( V_14 , V_116 , V_117 ) = F_47 ( & V_14 -> V_16 ,
V_143 ,
V_137 -> V_147 [ V_116 ] ,
V_146 , V_142 ) ;
if ( F_30 ( V_14 , V_116 , V_117 ) < 0 ) {
V_53 = - V_130 ;
goto V_148;
}
if ( V_112 && V_146 == - 1 )
V_146 = F_30 ( V_14 , V_116 , V_117 ) ;
}
}
return 0 ;
V_148:
do {
while ( -- V_117 >= 0 ) {
F_37 ( F_30 ( V_14 , V_116 , V_117 ) ) ;
F_30 ( V_14 , V_116 , V_117 ) = - 1 ;
}
V_117 = V_139 -> V_144 ;
} while ( -- V_116 >= 0 );
return V_53 ;
}
void F_48 ( struct V_13 * V_14 , int V_114 , int V_115 )
{
if ( V_14 -> V_118 == NULL )
return;
F_36 ( V_14 , V_114 , V_115 ) ;
F_34 ( V_14 ) ;
V_14 -> V_118 = NULL ;
}
int F_49 ( struct V_13 * V_14 , struct V_136 * V_137 ,
struct V_138 * V_139 , bool V_112 ,
struct V_140 * V_146 )
{
if ( V_137 == NULL ) {
V_137 = & V_149 . V_147 ;
}
if ( V_139 == NULL )
V_139 = & V_150 . V_147 ;
return F_45 ( V_14 , V_137 , V_139 , V_112 , V_146 ) ;
}
int F_50 ( struct V_13 * V_14 ,
struct V_136 * V_137 , bool V_112 ,
struct V_140 * V_146 )
{
return F_45 ( V_14 , V_137 , & V_150 . V_147 , V_112 ,
V_146 ) ;
}
int F_51 ( struct V_13 * V_14 ,
struct V_138 * V_139 , bool V_112 ,
struct V_140 * V_146 )
{
return F_45 ( V_14 , & V_149 . V_147 , V_139 , V_112 ,
V_146 ) ;
}
static int F_52 ( const union V_151 * V_152 , T_1 type ,
struct V_153 * V_154 ,
bool V_155 )
{
const T_1 * V_156 = V_152 -> V_154 . V_156 ;
union V_157 V_158 ;
V_156 += ( ( V_152 -> V_159 . V_4 -
sizeof( V_152 -> V_159 ) ) / sizeof( T_1 ) ) - 1 ;
if ( type & V_98 ) {
V_158 . V_160 = * V_156 ;
if ( V_155 ) {
V_158 . V_160 = F_53 ( V_158 . V_160 ) ;
V_158 . V_161 [ 0 ] = F_54 ( V_158 . V_161 [ 0 ] ) ;
}
V_154 -> V_116 = V_158 . V_161 [ 0 ] ;
V_156 -- ;
}
if ( type & V_162 ) {
V_154 -> V_163 = * V_156 ;
V_156 -- ;
}
if ( type & V_164 ) {
V_154 -> V_122 = * V_156 ;
V_156 -- ;
}
if ( type & V_101 ) {
V_154 -> time = * V_156 ;
V_156 -- ;
}
if ( type & V_80 ) {
V_158 . V_160 = * V_156 ;
if ( V_155 ) {
V_158 . V_160 = F_53 ( V_158 . V_160 ) ;
V_158 . V_161 [ 0 ] = F_54 ( V_158 . V_161 [ 0 ] ) ;
V_158 . V_161 [ 1 ] = F_54 ( V_158 . V_161 [ 1 ] ) ;
}
V_154 -> V_143 = V_158 . V_161 [ 0 ] ;
V_154 -> V_165 = V_158 . V_161 [ 1 ] ;
}
return 0 ;
}
static bool F_55 ( const union V_151 * V_152 ,
const void * V_166 , T_1 V_4 )
{
const void * V_167 = V_152 ;
if ( V_166 + V_4 > V_167 + V_152 -> V_159 . V_4 )
return true ;
return false ;
}
int F_56 ( struct V_13 * V_14 , union V_151 * V_152 ,
struct V_153 * V_168 , bool V_155 )
{
T_1 type = V_14 -> V_16 . V_1 ;
const T_1 * V_156 ;
union V_157 V_158 ;
memset ( V_168 , 0 , sizeof( * V_168 ) ) ;
V_168 -> V_116 = V_168 -> V_143 = V_168 -> V_165 = - 1 ;
V_168 -> V_163 = V_168 -> V_122 = V_168 -> time = - 1ULL ;
V_168 -> V_99 = 1 ;
if ( V_152 -> V_159 . type != V_169 ) {
if ( ! V_14 -> V_16 . V_71 )
return 0 ;
return F_52 ( V_152 , type , V_168 , V_155 ) ;
}
V_156 = V_152 -> V_154 . V_156 ;
if ( V_14 -> V_19 + sizeof( V_152 -> V_159 ) > V_152 -> V_159 . V_4 )
return - V_170 ;
if ( type & V_79 ) {
V_168 -> V_171 = V_152 -> V_171 . V_171 ;
V_156 ++ ;
}
if ( type & V_80 ) {
V_158 . V_160 = * V_156 ;
if ( V_155 ) {
V_158 . V_160 = F_53 ( V_158 . V_160 ) ;
V_158 . V_161 [ 0 ] = F_54 ( V_158 . V_161 [ 0 ] ) ;
V_158 . V_161 [ 1 ] = F_54 ( V_158 . V_161 [ 1 ] ) ;
}
V_168 -> V_143 = V_158 . V_161 [ 0 ] ;
V_168 -> V_165 = V_158 . V_161 [ 1 ] ;
V_156 ++ ;
}
if ( type & V_101 ) {
V_168 -> time = * V_156 ;
V_156 ++ ;
}
V_168 -> V_40 = 0 ;
if ( type & V_93 ) {
V_168 -> V_40 = * V_156 ;
V_156 ++ ;
}
V_168 -> V_122 = - 1ULL ;
if ( type & V_164 ) {
V_168 -> V_122 = * V_156 ;
V_156 ++ ;
}
if ( type & V_162 ) {
V_168 -> V_163 = * V_156 ;
V_156 ++ ;
}
if ( type & V_98 ) {
V_158 . V_160 = * V_156 ;
if ( V_155 ) {
V_158 . V_160 = F_53 ( V_158 . V_160 ) ;
V_158 . V_161 [ 0 ] = F_54 ( V_158 . V_161 [ 0 ] ) ;
}
V_168 -> V_116 = V_158 . V_161 [ 0 ] ;
V_156 ++ ;
}
if ( type & V_87 ) {
V_168 -> V_99 = * V_156 ;
V_156 ++ ;
}
if ( type & V_172 ) {
fprintf ( V_173 , L_21 ) ;
return - 1 ;
}
if ( type & V_96 ) {
if ( F_55 ( V_152 , V_156 , sizeof( V_168 -> V_174 -> V_144 ) ) )
return - V_170 ;
V_168 -> V_174 = (struct V_175 * ) V_156 ;
if ( F_55 ( V_152 , V_156 , V_168 -> V_174 -> V_144 ) )
return - V_170 ;
V_156 += 1 + V_168 -> V_174 -> V_144 ;
}
if ( type & V_103 ) {
const T_1 * V_176 ;
V_158 . V_160 = * V_156 ;
if ( F_57 ( V_155 ,
L_22 ) ) {
V_158 . V_160 = F_53 ( V_158 . V_160 ) ;
V_158 . V_161 [ 0 ] = F_54 ( V_158 . V_161 [ 0 ] ) ;
V_158 . V_161 [ 1 ] = F_54 ( V_158 . V_161 [ 1 ] ) ;
}
if ( F_55 ( V_152 , V_156 , sizeof( V_177 ) ) )
return - V_170 ;
V_168 -> V_178 = V_158 . V_161 [ 0 ] ;
V_176 = ( void * ) V_156 + sizeof( V_177 ) ;
if ( F_55 ( V_152 , V_176 , V_168 -> V_178 ) )
return - V_170 ;
V_168 -> V_179 = ( void * ) V_176 ;
V_156 = ( void * ) V_156 + V_168 -> V_178 + sizeof( V_177 ) ;
}
if ( type & V_108 ) {
T_1 V_180 ;
V_168 -> V_107 = (struct V_107 * ) V_156 ;
V_156 ++ ;
V_180 = V_168 -> V_107 -> V_144 * sizeof( struct V_181 ) ;
V_180 /= sizeof( T_1 ) ;
V_156 += V_180 ;
}
return 0 ;
}
int F_58 ( union V_151 * V_152 , T_1 type ,
const struct V_153 * V_154 ,
bool V_155 )
{
T_1 * V_156 ;
union V_157 V_158 ;
V_156 = V_152 -> V_154 . V_156 ;
if ( type & V_79 ) {
V_152 -> V_171 . V_171 = V_154 -> V_171 ;
V_156 ++ ;
}
if ( type & V_80 ) {
V_158 . V_161 [ 0 ] = V_154 -> V_143 ;
V_158 . V_161 [ 1 ] = V_154 -> V_165 ;
if ( V_155 ) {
V_158 . V_161 [ 0 ] = F_54 ( V_158 . V_161 [ 0 ] ) ;
V_158 . V_161 [ 1 ] = F_54 ( V_158 . V_161 [ 1 ] ) ;
V_158 . V_160 = F_53 ( V_158 . V_160 ) ;
}
* V_156 = V_158 . V_160 ;
V_156 ++ ;
}
if ( type & V_101 ) {
* V_156 = V_154 -> time ;
V_156 ++ ;
}
if ( type & V_93 ) {
* V_156 = V_154 -> V_40 ;
V_156 ++ ;
}
if ( type & V_164 ) {
* V_156 = V_154 -> V_122 ;
V_156 ++ ;
}
if ( type & V_162 ) {
* V_156 = V_154 -> V_163 ;
V_156 ++ ;
}
if ( type & V_98 ) {
V_158 . V_161 [ 0 ] = V_154 -> V_116 ;
if ( V_155 ) {
V_158 . V_161 [ 0 ] = F_54 ( V_158 . V_161 [ 0 ] ) ;
V_158 . V_160 = F_53 ( V_158 . V_160 ) ;
}
* V_156 = V_158 . V_160 ;
V_156 ++ ;
}
if ( type & V_87 ) {
* V_156 = V_154 -> V_99 ;
V_156 ++ ;
}
return 0 ;
}
