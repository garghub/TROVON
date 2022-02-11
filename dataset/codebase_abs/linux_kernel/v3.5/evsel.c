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
}
struct V_13 * F_6 ( struct V_15 * V_16 , int V_17 )
{
struct V_13 * V_14 = F_7 ( sizeof( * V_14 ) ) ;
if ( V_14 != NULL )
F_4 ( V_14 , V_16 , V_17 ) ;
return V_14 ;
}
const char * F_8 ( T_1 V_19 )
{
if ( V_19 < V_20 && V_21 [ V_19 ] )
return V_21 [ V_19 ] ;
return L_1 ;
}
static int F_9 ( struct V_13 * V_14 , char * V_22 , T_2 V_4 )
{
int V_23 = 0 ;
struct V_15 * V_16 = & V_14 -> V_16 ;
int V_24 = F_10 ( V_22 , V_4 , L_2 , F_8 ( V_16 -> V_19 ) ) ;
bool V_25 = false ;
#define F_11 ( T_3 , T_4 ) do { \
if (!attr->exclude_##context) { \
if (!colon) colon = r++; \
r += scnprintf(bf + r, size - r, "%c", mod); \
} } while(0)
if ( V_16 -> V_26 || V_16 -> V_27 || V_16 -> V_28 ) {
F_11 ( V_29 , 'k' ) ;
F_11 ( V_30 , 'u' ) ;
F_11 ( V_31 , 'h' ) ;
V_25 = true ;
}
if ( V_16 -> V_32 ) {
if ( ! V_23 )
V_23 = V_24 ++ ;
V_24 += F_10 ( V_22 + V_24 , V_4 - V_24 , L_3 , V_16 -> V_32 , L_4 ) ;
V_25 = true ;
}
if ( V_16 -> V_33 || V_16 -> V_34 == V_25 ) {
F_11 ( V_35 , 'H' ) ;
F_11 ( V_36 , 'G' ) ;
}
#undef F_11
if ( V_23 )
V_22 [ V_23 ] = ':' ;
return V_24 ;
}
int F_12 ( struct V_13 * V_14 , char * V_22 , T_2 V_4 )
{
int V_37 ;
switch ( V_14 -> V_16 . type ) {
case V_38 :
V_37 = F_10 ( V_22 , V_4 , L_5 V_39 , V_14 -> V_16 . V_19 ) ;
break;
case V_40 :
V_37 = F_9 ( V_14 , V_22 , V_4 ) ;
break;
default:
return 0 ;
}
return V_37 ;
}
void F_13 ( struct V_13 * V_14 , struct V_41 * V_42 ,
struct V_13 * V_43 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
int V_44 = ! V_14 -> V_17 ;
V_16 -> V_45 = 1 ;
V_16 -> V_46 = V_42 -> V_47 ? 0 : 1 ;
V_16 -> V_48 = ! V_42 -> V_49 ;
V_16 -> V_50 = V_51 |
V_52 |
V_53 ;
V_16 -> V_1 |= V_54 | V_55 ;
if ( ! V_16 -> V_56 || ( V_42 -> V_57 != V_58 &&
V_42 -> V_59 != V_60 ) ) {
if ( V_42 -> V_61 ) {
V_16 -> V_1 |= V_62 ;
V_16 -> V_61 = 1 ;
V_16 -> V_63 = V_42 -> V_61 ;
} else {
V_16 -> V_56 = V_42 -> V_64 ;
}
}
if ( V_42 -> V_65 )
V_16 -> V_63 = 0 ;
if ( V_42 -> V_66 )
V_16 -> V_66 = 1 ;
if ( V_42 -> V_67 ) {
V_16 -> V_1 |= V_68 ;
V_16 -> V_69 = V_44 ;
}
if ( V_42 -> V_70 )
V_16 -> V_1 |= V_71 ;
if ( F_14 ( & V_42 -> V_72 ) )
V_16 -> V_1 |= V_73 ;
if ( V_42 -> V_74 )
V_16 -> V_1 |= V_62 ;
if ( ! V_42 -> V_47 &&
( V_42 -> V_75 || ! V_42 -> V_49 ||
F_14 ( & V_42 -> V_72 ) ) )
V_16 -> V_1 |= V_76 ;
if ( V_42 -> V_77 ) {
V_16 -> V_1 |= V_76 ;
V_16 -> V_1 |= V_78 ;
V_16 -> V_1 |= V_73 ;
}
if ( V_42 -> V_79 ) {
V_16 -> V_80 = 0 ;
V_16 -> V_81 = 1 ;
}
if ( V_42 -> V_82 ) {
V_16 -> V_1 |= V_83 ;
V_16 -> V_84 = V_42 -> V_82 ;
}
V_16 -> V_85 = V_44 ;
V_16 -> V_86 = V_44 ;
if ( F_15 ( & V_42 -> V_72 ) &&
( ! V_42 -> V_87 || V_14 == V_43 ) ) {
V_16 -> V_88 = 1 ;
}
}
int F_16 ( struct V_13 * V_14 , int V_89 , int V_90 )
{
int V_91 , V_92 ;
V_14 -> V_93 = F_17 ( V_89 , V_90 , sizeof( int ) ) ;
if ( V_14 -> V_93 ) {
for ( V_91 = 0 ; V_91 < V_89 ; V_91 ++ ) {
for ( V_92 = 0 ; V_92 < V_90 ; V_92 ++ ) {
F_18 ( V_14 , V_91 , V_92 ) = - 1 ;
}
}
}
return V_14 -> V_93 != NULL ? 0 : - V_94 ;
}
int F_19 ( struct V_13 * V_14 , int V_89 , int V_90 )
{
V_14 -> V_95 = F_17 ( V_89 , V_90 , sizeof( struct V_96 ) ) ;
if ( V_14 -> V_95 == NULL )
return - V_94 ;
V_14 -> V_97 = F_7 ( V_89 * V_90 * sizeof( T_1 ) ) ;
if ( V_14 -> V_97 == NULL ) {
F_20 ( V_14 -> V_95 ) ;
V_14 -> V_95 = NULL ;
return - V_94 ;
}
return 0 ;
}
int F_21 ( struct V_13 * V_14 , int V_89 )
{
V_14 -> V_98 = F_7 ( ( sizeof( * V_14 -> V_98 ) +
( V_89 * sizeof( struct V_99 ) ) ) ) ;
return V_14 -> V_98 != NULL ? 0 : - V_94 ;
}
void F_22 ( struct V_13 * V_14 )
{
F_20 ( V_14 -> V_93 ) ;
V_14 -> V_93 = NULL ;
}
void F_23 ( struct V_13 * V_14 )
{
F_20 ( V_14 -> V_95 ) ;
V_14 -> V_95 = NULL ;
free ( V_14 -> V_97 ) ;
V_14 -> V_97 = NULL ;
}
void F_24 ( struct V_13 * V_14 , int V_89 , int V_90 )
{
int V_91 , V_92 ;
for ( V_91 = 0 ; V_91 < V_89 ; V_91 ++ )
for ( V_92 = 0 ; V_92 < V_90 ; ++ V_92 ) {
F_25 ( F_18 ( V_14 , V_91 , V_92 ) ) ;
F_18 ( V_14 , V_91 , V_92 ) = - 1 ;
}
}
void F_26 ( struct V_13 * V_14 )
{
assert ( F_27 ( & V_14 -> V_18 ) ) ;
F_20 ( V_14 -> V_93 ) ;
F_20 ( V_14 -> V_95 ) ;
free ( V_14 -> V_97 ) ;
}
void F_28 ( struct V_13 * V_14 )
{
F_26 ( V_14 ) ;
F_29 ( V_14 -> V_100 ) ;
free ( V_14 -> V_101 ) ;
free ( V_14 ) ;
}
int F_30 ( struct V_13 * V_14 ,
int V_91 , int V_92 , bool V_102 )
{
struct V_99 V_103 ;
T_2 V_104 = V_102 ? 3 : 1 ;
if ( F_18 ( V_14 , V_91 , V_92 ) < 0 )
return - V_105 ;
if ( V_14 -> V_98 == NULL && F_21 ( V_14 , V_91 + 1 ) < 0 )
return - V_94 ;
if ( F_31 ( F_18 ( V_14 , V_91 , V_92 ) , & V_103 , V_104 * sizeof( T_1 ) ) < 0 )
return - V_106 ;
if ( V_102 ) {
if ( V_103 . V_107 == 0 )
V_103 . V_108 = 0 ;
else if ( V_103 . V_107 < V_103 . V_109 )
V_103 . V_108 = ( T_1 ) ( ( double ) V_103 . V_108 * V_103 . V_109 / V_103 . V_107 + 0.5 ) ;
} else
V_103 . V_109 = V_103 . V_107 = 0 ;
V_14 -> V_98 -> V_91 [ V_91 ] = V_103 ;
return 0 ;
}
int F_32 ( struct V_13 * V_14 ,
int V_89 , int V_90 , bool V_102 )
{
T_2 V_104 = V_102 ? 3 : 1 ;
int V_91 , V_92 ;
struct V_99 * V_110 = & V_14 -> V_98 -> V_110 , V_103 ;
V_110 -> V_108 = V_110 -> V_109 = V_110 -> V_107 = 0 ;
for ( V_91 = 0 ; V_91 < V_89 ; V_91 ++ ) {
for ( V_92 = 0 ; V_92 < V_90 ; V_92 ++ ) {
if ( F_18 ( V_14 , V_91 , V_92 ) < 0 )
continue;
if ( F_31 ( F_18 ( V_14 , V_91 , V_92 ) ,
& V_103 , V_104 * sizeof( T_1 ) ) < 0 )
return - V_106 ;
V_110 -> V_108 += V_103 . V_108 ;
if ( V_102 ) {
V_110 -> V_109 += V_103 . V_109 ;
V_110 -> V_107 += V_103 . V_107 ;
}
}
}
V_14 -> V_98 -> V_111 = 0 ;
if ( V_102 ) {
if ( V_110 -> V_107 == 0 ) {
V_14 -> V_98 -> V_111 = - 1 ;
V_110 -> V_108 = 0 ;
return 0 ;
}
if ( V_110 -> V_107 < V_110 -> V_109 ) {
V_14 -> V_98 -> V_111 = 1 ;
V_110 -> V_108 = ( T_1 ) ( ( double ) V_110 -> V_108 * V_110 -> V_109 / V_110 -> V_107 + 0.5 ) ;
}
} else
V_110 -> V_109 = V_110 -> V_107 = 0 ;
return 0 ;
}
static int F_33 ( struct V_13 * V_14 , struct V_112 * V_113 ,
struct V_114 * V_115 , bool V_87 ,
struct V_116 * V_117 )
{
int V_91 , V_92 ;
unsigned long V_118 = 0 ;
int V_119 = - 1 , V_120 ;
if ( V_14 -> V_93 == NULL &&
F_16 ( V_14 , V_113 -> V_121 , V_115 -> V_121 ) < 0 )
return - V_94 ;
if ( V_14 -> V_100 ) {
V_118 = V_122 ;
V_119 = V_14 -> V_100 -> V_93 ;
}
for ( V_91 = 0 ; V_91 < V_113 -> V_121 ; V_91 ++ ) {
int V_123 = V_117 ? F_34 ( V_117 , V_91 ) : - 1 ;
for ( V_92 = 0 ; V_92 < V_115 -> V_121 ; V_92 ++ ) {
if ( ! V_14 -> V_100 )
V_119 = V_115 -> V_124 [ V_92 ] ;
F_18 ( V_14 , V_91 , V_92 ) = F_35 ( & V_14 -> V_16 ,
V_119 ,
V_113 -> V_124 [ V_91 ] ,
V_123 , V_118 ) ;
if ( F_18 ( V_14 , V_91 , V_92 ) < 0 ) {
V_120 = - V_106 ;
goto V_125;
}
if ( V_87 && V_123 == - 1 )
V_123 = F_18 ( V_14 , V_91 , V_92 ) ;
}
}
return 0 ;
V_125:
do {
while ( -- V_92 >= 0 ) {
F_25 ( F_18 ( V_14 , V_91 , V_92 ) ) ;
F_18 ( V_14 , V_91 , V_92 ) = - 1 ;
}
V_92 = V_115 -> V_121 ;
} while ( -- V_91 >= 0 );
return V_120 ;
}
void F_36 ( struct V_13 * V_14 , int V_89 , int V_90 )
{
if ( V_14 -> V_93 == NULL )
return;
F_24 ( V_14 , V_89 , V_90 ) ;
F_22 ( V_14 ) ;
V_14 -> V_93 = NULL ;
}
int F_37 ( struct V_13 * V_14 , struct V_112 * V_113 ,
struct V_114 * V_115 , bool V_87 ,
struct V_116 * V_123 )
{
if ( V_113 == NULL ) {
V_113 = & V_126 . V_124 ;
}
if ( V_115 == NULL )
V_115 = & V_127 . V_124 ;
return F_33 ( V_14 , V_113 , V_115 , V_87 , V_123 ) ;
}
int F_38 ( struct V_13 * V_14 ,
struct V_112 * V_113 , bool V_87 ,
struct V_116 * V_123 )
{
return F_33 ( V_14 , V_113 , & V_127 . V_124 , V_87 ,
V_123 ) ;
}
int F_39 ( struct V_13 * V_14 ,
struct V_114 * V_115 , bool V_87 ,
struct V_116 * V_123 )
{
return F_33 ( V_14 , & V_126 . V_124 , V_115 , V_87 ,
V_123 ) ;
}
static int F_40 ( const union V_128 * V_129 , T_1 type ,
struct V_130 * V_131 ,
bool V_132 )
{
const T_1 * V_133 = V_129 -> V_131 . V_133 ;
union V_134 V_135 ;
V_133 += ( ( V_129 -> V_136 . V_4 -
sizeof( V_129 -> V_136 ) ) / sizeof( T_1 ) ) - 1 ;
if ( type & V_73 ) {
V_135 . V_137 = * V_133 ;
if ( V_132 ) {
V_135 . V_137 = F_41 ( V_135 . V_137 ) ;
V_135 . V_138 [ 0 ] = F_42 ( V_135 . V_138 [ 0 ] ) ;
}
V_131 -> V_91 = V_135 . V_138 [ 0 ] ;
V_133 -- ;
}
if ( type & V_139 ) {
V_131 -> V_140 = * V_133 ;
V_133 -- ;
}
if ( type & V_141 ) {
V_131 -> V_97 = * V_133 ;
V_133 -- ;
}
if ( type & V_76 ) {
V_131 -> time = * V_133 ;
V_133 -- ;
}
if ( type & V_55 ) {
V_135 . V_137 = * V_133 ;
if ( V_132 ) {
V_135 . V_137 = F_41 ( V_135 . V_137 ) ;
V_135 . V_138 [ 0 ] = F_42 ( V_135 . V_138 [ 0 ] ) ;
V_135 . V_138 [ 1 ] = F_42 ( V_135 . V_138 [ 1 ] ) ;
}
V_131 -> V_119 = V_135 . V_138 [ 0 ] ;
V_131 -> V_142 = V_135 . V_138 [ 1 ] ;
}
return 0 ;
}
static bool F_43 ( const union V_128 * V_129 ,
const void * V_143 , T_1 V_4 )
{
const void * V_144 = V_129 ;
if ( V_143 + V_4 > V_144 + V_129 -> V_136 . V_4 )
return true ;
return false ;
}
int F_44 ( const union V_128 * V_129 , T_1 type ,
int V_145 , bool V_46 ,
struct V_130 * V_146 , bool V_132 )
{
const T_1 * V_133 ;
union V_134 V_135 ;
memset ( V_146 , 0 , sizeof( * V_146 ) ) ;
V_146 -> V_91 = V_146 -> V_119 = V_146 -> V_142 = - 1 ;
V_146 -> V_140 = V_146 -> V_97 = V_146 -> time = - 1ULL ;
V_146 -> V_74 = 1 ;
if ( V_129 -> V_136 . type != V_147 ) {
if ( ! V_46 )
return 0 ;
return F_40 ( V_129 , type , V_146 , V_132 ) ;
}
V_133 = V_129 -> V_131 . V_133 ;
if ( V_145 + sizeof( V_129 -> V_136 ) > V_129 -> V_136 . V_4 )
return - V_148 ;
if ( type & V_54 ) {
V_146 -> V_149 = V_129 -> V_149 . V_149 ;
V_133 ++ ;
}
if ( type & V_55 ) {
V_135 . V_137 = * V_133 ;
if ( V_132 ) {
V_135 . V_137 = F_41 ( V_135 . V_137 ) ;
V_135 . V_138 [ 0 ] = F_42 ( V_135 . V_138 [ 0 ] ) ;
V_135 . V_138 [ 1 ] = F_42 ( V_135 . V_138 [ 1 ] ) ;
}
V_146 -> V_119 = V_135 . V_138 [ 0 ] ;
V_146 -> V_142 = V_135 . V_138 [ 1 ] ;
V_133 ++ ;
}
if ( type & V_76 ) {
V_146 -> time = * V_133 ;
V_133 ++ ;
}
V_146 -> V_150 = 0 ;
if ( type & V_68 ) {
V_146 -> V_150 = * V_133 ;
V_133 ++ ;
}
V_146 -> V_97 = - 1ULL ;
if ( type & V_141 ) {
V_146 -> V_97 = * V_133 ;
V_133 ++ ;
}
if ( type & V_139 ) {
V_146 -> V_140 = * V_133 ;
V_133 ++ ;
}
if ( type & V_73 ) {
V_135 . V_137 = * V_133 ;
if ( V_132 ) {
V_135 . V_137 = F_41 ( V_135 . V_137 ) ;
V_135 . V_138 [ 0 ] = F_42 ( V_135 . V_138 [ 0 ] ) ;
}
V_146 -> V_91 = V_135 . V_138 [ 0 ] ;
V_133 ++ ;
}
if ( type & V_62 ) {
V_146 -> V_74 = * V_133 ;
V_133 ++ ;
}
if ( type & V_151 ) {
fprintf ( V_152 , L_6 ) ;
return - 1 ;
}
if ( type & V_71 ) {
if ( F_43 ( V_129 , V_133 , sizeof( V_146 -> V_153 -> V_121 ) ) )
return - V_148 ;
V_146 -> V_153 = (struct V_154 * ) V_133 ;
if ( F_43 ( V_129 , V_133 , V_146 -> V_153 -> V_121 ) )
return - V_148 ;
V_133 += 1 + V_146 -> V_153 -> V_121 ;
}
if ( type & V_78 ) {
const T_1 * V_155 ;
V_135 . V_137 = * V_133 ;
if ( F_45 ( V_132 ,
L_7 ) ) {
V_135 . V_137 = F_41 ( V_135 . V_137 ) ;
V_135 . V_138 [ 0 ] = F_42 ( V_135 . V_138 [ 0 ] ) ;
V_135 . V_138 [ 1 ] = F_42 ( V_135 . V_138 [ 1 ] ) ;
}
if ( F_43 ( V_129 , V_133 , sizeof( V_156 ) ) )
return - V_148 ;
V_146 -> V_157 = V_135 . V_138 [ 0 ] ;
V_155 = ( void * ) V_133 + sizeof( V_156 ) ;
if ( F_43 ( V_129 , V_155 , V_146 -> V_157 ) )
return - V_148 ;
V_146 -> V_158 = ( void * ) V_155 ;
V_133 = ( void * ) V_133 + V_146 -> V_157 + sizeof( V_156 ) ;
}
if ( type & V_83 ) {
T_1 V_159 ;
V_146 -> V_82 = (struct V_82 * ) V_133 ;
V_133 ++ ;
V_159 = V_146 -> V_82 -> V_121 * sizeof( struct V_160 ) ;
V_159 /= sizeof( T_1 ) ;
V_133 += V_159 ;
}
return 0 ;
}
int F_46 ( union V_128 * V_129 , T_1 type ,
const struct V_130 * V_131 ,
bool V_132 )
{
T_1 * V_133 ;
union V_134 V_135 ;
V_133 = V_129 -> V_131 . V_133 ;
if ( type & V_54 ) {
V_129 -> V_149 . V_149 = V_131 -> V_149 ;
V_133 ++ ;
}
if ( type & V_55 ) {
V_135 . V_138 [ 0 ] = V_131 -> V_119 ;
V_135 . V_138 [ 1 ] = V_131 -> V_142 ;
if ( V_132 ) {
V_135 . V_138 [ 0 ] = F_42 ( V_135 . V_138 [ 0 ] ) ;
V_135 . V_138 [ 1 ] = F_42 ( V_135 . V_138 [ 1 ] ) ;
V_135 . V_137 = F_41 ( V_135 . V_137 ) ;
}
* V_133 = V_135 . V_137 ;
V_133 ++ ;
}
if ( type & V_76 ) {
* V_133 = V_131 -> time ;
V_133 ++ ;
}
if ( type & V_68 ) {
* V_133 = V_131 -> V_150 ;
V_133 ++ ;
}
if ( type & V_141 ) {
* V_133 = V_131 -> V_97 ;
V_133 ++ ;
}
if ( type & V_139 ) {
* V_133 = V_131 -> V_140 ;
V_133 ++ ;
}
if ( type & V_73 ) {
V_135 . V_138 [ 0 ] = V_131 -> V_91 ;
if ( V_132 ) {
V_135 . V_138 [ 0 ] = F_42 ( V_135 . V_138 [ 0 ] ) ;
V_135 . V_137 = F_41 ( V_135 . V_137 ) ;
}
* V_133 = V_135 . V_137 ;
V_133 ++ ;
}
if ( type & V_62 ) {
* V_133 = V_131 -> V_74 ;
V_133 ++ ;
}
return 0 ;
}
