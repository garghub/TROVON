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
void F_8 ( struct V_13 * V_14 , struct V_19 * V_20 ,
struct V_13 * V_21 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
int V_22 = ! V_14 -> V_17 ;
V_16 -> V_23 = V_20 -> V_24 ? 0 : 1 ;
V_16 -> V_25 = ! V_20 -> V_26 ;
V_16 -> V_27 = V_28 |
V_29 |
V_30 ;
V_16 -> V_1 |= V_31 | V_32 ;
if ( ! V_16 -> V_33 || ( V_20 -> V_34 != V_35 &&
V_20 -> V_36 != V_37 ) ) {
if ( V_20 -> V_38 ) {
V_16 -> V_1 |= V_39 ;
V_16 -> V_38 = 1 ;
V_16 -> V_40 = V_20 -> V_38 ;
} else {
V_16 -> V_33 = V_20 -> V_41 ;
}
}
if ( V_20 -> V_42 )
V_16 -> V_40 = 0 ;
if ( V_20 -> V_43 )
V_16 -> V_43 = 1 ;
if ( V_20 -> V_44 ) {
V_16 -> V_1 |= V_45 ;
V_16 -> V_46 = V_22 ;
}
if ( V_20 -> V_47 )
V_16 -> V_1 |= V_48 ;
if ( V_20 -> V_49 )
V_16 -> V_1 |= V_50 ;
if ( V_20 -> V_51 )
V_16 -> V_1 |= V_39 ;
if ( ! V_20 -> V_24 &&
( V_20 -> V_52 || V_20 -> V_49 ||
! V_20 -> V_26 || V_20 -> V_53 ) )
V_16 -> V_1 |= V_54 ;
if ( V_20 -> V_55 ) {
V_16 -> V_1 |= V_54 ;
V_16 -> V_1 |= V_56 ;
V_16 -> V_1 |= V_50 ;
}
if ( V_20 -> V_57 ) {
V_16 -> V_58 = 0 ;
V_16 -> V_59 = 1 ;
}
if ( V_20 -> V_60 ) {
V_16 -> V_1 |= V_61 ;
V_16 -> V_62 = V_20 -> V_60 ;
}
V_16 -> V_63 = V_22 ;
V_16 -> V_64 = V_22 ;
if ( ! V_20 -> V_65 && ! V_20 -> V_66 && ! V_20 -> V_49 &&
( ! V_20 -> V_67 || V_14 == V_21 ) ) {
V_16 -> V_68 = 1 ;
V_16 -> V_69 = 1 ;
}
}
int F_9 ( struct V_13 * V_14 , int V_70 , int V_71 )
{
int V_72 , V_73 ;
V_14 -> V_74 = F_10 ( V_70 , V_71 , sizeof( int ) ) ;
if ( V_14 -> V_74 ) {
for ( V_72 = 0 ; V_72 < V_70 ; V_72 ++ ) {
for ( V_73 = 0 ; V_73 < V_71 ; V_73 ++ ) {
F_11 ( V_14 , V_72 , V_73 ) = - 1 ;
}
}
}
return V_14 -> V_74 != NULL ? 0 : - V_75 ;
}
int F_12 ( struct V_13 * V_14 , int V_70 , int V_71 )
{
V_14 -> V_76 = F_10 ( V_70 , V_71 , sizeof( struct V_77 ) ) ;
if ( V_14 -> V_76 == NULL )
return - V_75 ;
V_14 -> V_78 = F_7 ( V_70 * V_71 * sizeof( T_1 ) ) ;
if ( V_14 -> V_78 == NULL ) {
F_13 ( V_14 -> V_76 ) ;
V_14 -> V_76 = NULL ;
return - V_75 ;
}
return 0 ;
}
int F_14 ( struct V_13 * V_14 , int V_70 )
{
V_14 -> V_79 = F_7 ( ( sizeof( * V_14 -> V_79 ) +
( V_70 * sizeof( struct V_80 ) ) ) ) ;
return V_14 -> V_79 != NULL ? 0 : - V_75 ;
}
void F_15 ( struct V_13 * V_14 )
{
F_13 ( V_14 -> V_74 ) ;
V_14 -> V_74 = NULL ;
}
void F_16 ( struct V_13 * V_14 )
{
F_13 ( V_14 -> V_76 ) ;
V_14 -> V_76 = NULL ;
free ( V_14 -> V_78 ) ;
V_14 -> V_78 = NULL ;
}
void F_17 ( struct V_13 * V_14 , int V_70 , int V_71 )
{
int V_72 , V_73 ;
for ( V_72 = 0 ; V_72 < V_70 ; V_72 ++ )
for ( V_73 = 0 ; V_73 < V_71 ; ++ V_73 ) {
F_18 ( F_11 ( V_14 , V_72 , V_73 ) ) ;
F_11 ( V_14 , V_72 , V_73 ) = - 1 ;
}
}
void F_19 ( struct V_13 * V_14 )
{
assert ( F_20 ( & V_14 -> V_18 ) ) ;
F_13 ( V_14 -> V_74 ) ;
F_13 ( V_14 -> V_76 ) ;
free ( V_14 -> V_78 ) ;
}
void F_21 ( struct V_13 * V_14 )
{
F_19 ( V_14 ) ;
F_22 ( V_14 -> V_81 ) ;
free ( V_14 -> V_82 ) ;
free ( V_14 ) ;
}
int F_23 ( struct V_13 * V_14 ,
int V_72 , int V_73 , bool V_83 )
{
struct V_80 V_84 ;
T_2 V_85 = V_83 ? 3 : 1 ;
if ( F_11 ( V_14 , V_72 , V_73 ) < 0 )
return - V_86 ;
if ( V_14 -> V_79 == NULL && F_14 ( V_14 , V_72 + 1 ) < 0 )
return - V_75 ;
if ( F_24 ( F_11 ( V_14 , V_72 , V_73 ) , & V_84 , V_85 * sizeof( T_1 ) ) < 0 )
return - V_87 ;
if ( V_83 ) {
if ( V_84 . V_88 == 0 )
V_84 . V_89 = 0 ;
else if ( V_84 . V_88 < V_84 . V_90 )
V_84 . V_89 = ( T_1 ) ( ( double ) V_84 . V_89 * V_84 . V_90 / V_84 . V_88 + 0.5 ) ;
} else
V_84 . V_90 = V_84 . V_88 = 0 ;
V_14 -> V_79 -> V_72 [ V_72 ] = V_84 ;
return 0 ;
}
int F_25 ( struct V_13 * V_14 ,
int V_70 , int V_71 , bool V_83 )
{
T_2 V_85 = V_83 ? 3 : 1 ;
int V_72 , V_73 ;
struct V_80 * V_91 = & V_14 -> V_79 -> V_91 , V_84 ;
V_91 -> V_89 = V_91 -> V_90 = V_91 -> V_88 = 0 ;
for ( V_72 = 0 ; V_72 < V_70 ; V_72 ++ ) {
for ( V_73 = 0 ; V_73 < V_71 ; V_73 ++ ) {
if ( F_11 ( V_14 , V_72 , V_73 ) < 0 )
continue;
if ( F_24 ( F_11 ( V_14 , V_72 , V_73 ) ,
& V_84 , V_85 * sizeof( T_1 ) ) < 0 )
return - V_87 ;
V_91 -> V_89 += V_84 . V_89 ;
if ( V_83 ) {
V_91 -> V_90 += V_84 . V_90 ;
V_91 -> V_88 += V_84 . V_88 ;
}
}
}
V_14 -> V_79 -> V_92 = 0 ;
if ( V_83 ) {
if ( V_91 -> V_88 == 0 ) {
V_14 -> V_79 -> V_92 = - 1 ;
V_91 -> V_89 = 0 ;
return 0 ;
}
if ( V_91 -> V_88 < V_91 -> V_90 ) {
V_14 -> V_79 -> V_92 = 1 ;
V_91 -> V_89 = ( T_1 ) ( ( double ) V_91 -> V_89 * V_91 -> V_90 / V_91 -> V_88 + 0.5 ) ;
}
} else
V_91 -> V_90 = V_91 -> V_88 = 0 ;
return 0 ;
}
static int F_26 ( struct V_13 * V_14 , struct V_93 * V_94 ,
struct V_95 * V_96 , bool V_67 ,
struct V_97 * V_98 )
{
int V_72 , V_73 ;
unsigned long V_99 = 0 ;
int V_100 = - 1 , V_101 ;
if ( V_14 -> V_74 == NULL &&
F_9 ( V_14 , V_94 -> V_102 , V_96 -> V_102 ) < 0 )
return - V_75 ;
if ( V_14 -> V_81 ) {
V_99 = V_103 ;
V_100 = V_14 -> V_81 -> V_74 ;
}
for ( V_72 = 0 ; V_72 < V_94 -> V_102 ; V_72 ++ ) {
int V_104 = V_98 ? F_27 ( V_98 , V_72 ) : - 1 ;
for ( V_73 = 0 ; V_73 < V_96 -> V_102 ; V_73 ++ ) {
if ( ! V_14 -> V_81 )
V_100 = V_96 -> V_105 [ V_73 ] ;
F_11 ( V_14 , V_72 , V_73 ) = F_28 ( & V_14 -> V_16 ,
V_100 ,
V_94 -> V_105 [ V_72 ] ,
V_104 , V_99 ) ;
if ( F_11 ( V_14 , V_72 , V_73 ) < 0 ) {
V_101 = - V_87 ;
goto V_106;
}
if ( V_67 && V_104 == - 1 )
V_104 = F_11 ( V_14 , V_72 , V_73 ) ;
}
}
return 0 ;
V_106:
do {
while ( -- V_73 >= 0 ) {
F_18 ( F_11 ( V_14 , V_72 , V_73 ) ) ;
F_11 ( V_14 , V_72 , V_73 ) = - 1 ;
}
V_73 = V_96 -> V_102 ;
} while ( -- V_72 >= 0 );
return V_101 ;
}
void F_29 ( struct V_13 * V_14 , int V_70 , int V_71 )
{
if ( V_14 -> V_74 == NULL )
return;
F_17 ( V_14 , V_70 , V_71 ) ;
F_15 ( V_14 ) ;
V_14 -> V_74 = NULL ;
}
int F_30 ( struct V_13 * V_14 , struct V_93 * V_94 ,
struct V_95 * V_96 , bool V_67 ,
struct V_97 * V_104 )
{
if ( V_94 == NULL ) {
V_94 = & V_107 . V_105 ;
}
if ( V_96 == NULL )
V_96 = & V_108 . V_105 ;
return F_26 ( V_14 , V_94 , V_96 , V_67 , V_104 ) ;
}
int F_31 ( struct V_13 * V_14 ,
struct V_93 * V_94 , bool V_67 ,
struct V_97 * V_104 )
{
return F_26 ( V_14 , V_94 , & V_108 . V_105 , V_67 ,
V_104 ) ;
}
int F_32 ( struct V_13 * V_14 ,
struct V_95 * V_96 , bool V_67 ,
struct V_97 * V_104 )
{
return F_26 ( V_14 , & V_107 . V_105 , V_96 , V_67 ,
V_104 ) ;
}
static int F_33 ( const union V_109 * V_110 , T_1 type ,
struct V_111 * V_112 )
{
const T_1 * V_113 = V_110 -> V_112 . V_113 ;
V_113 += ( ( V_110 -> V_114 . V_4 -
sizeof( V_110 -> V_114 ) ) / sizeof( T_1 ) ) - 1 ;
if ( type & V_50 ) {
T_3 * V_115 = ( T_3 * ) V_113 ;
V_112 -> V_72 = * V_115 ;
V_113 -- ;
}
if ( type & V_116 ) {
V_112 -> V_117 = * V_113 ;
V_113 -- ;
}
if ( type & V_118 ) {
V_112 -> V_78 = * V_113 ;
V_113 -- ;
}
if ( type & V_54 ) {
V_112 -> time = * V_113 ;
V_113 -- ;
}
if ( type & V_32 ) {
T_3 * V_115 = ( T_3 * ) V_113 ;
V_112 -> V_100 = V_115 [ 0 ] ;
V_112 -> V_119 = V_115 [ 1 ] ;
}
return 0 ;
}
static bool F_34 ( const union V_109 * V_110 ,
const void * V_120 , T_1 V_4 )
{
const void * V_121 = V_110 ;
if ( V_120 + V_4 > V_121 + V_110 -> V_114 . V_4 )
return true ;
return false ;
}
int F_35 ( const union V_109 * V_110 , T_1 type ,
int V_122 , bool V_23 ,
struct V_111 * V_123 , bool V_124 )
{
const T_1 * V_113 ;
union {
T_1 V_125 ;
T_3 V_126 [ 2 ] ;
} V_127 ;
memset ( V_123 , 0 , sizeof( * V_123 ) ) ;
V_123 -> V_72 = V_123 -> V_100 = V_123 -> V_119 = - 1 ;
V_123 -> V_117 = V_123 -> V_78 = V_123 -> time = - 1ULL ;
V_123 -> V_51 = 1 ;
if ( V_110 -> V_114 . type != V_128 ) {
if ( ! V_23 )
return 0 ;
return F_33 ( V_110 , type , V_123 ) ;
}
V_113 = V_110 -> V_112 . V_113 ;
if ( V_122 + sizeof( V_110 -> V_114 ) > V_110 -> V_114 . V_4 )
return - V_129 ;
if ( type & V_31 ) {
V_123 -> V_130 = V_110 -> V_130 . V_130 ;
V_113 ++ ;
}
if ( type & V_32 ) {
V_127 . V_125 = * V_113 ;
if ( V_124 ) {
V_127 . V_125 = F_36 ( V_127 . V_125 ) ;
V_127 . V_126 [ 0 ] = F_37 ( V_127 . V_126 [ 0 ] ) ;
V_127 . V_126 [ 1 ] = F_37 ( V_127 . V_126 [ 1 ] ) ;
}
V_123 -> V_100 = V_127 . V_126 [ 0 ] ;
V_123 -> V_119 = V_127 . V_126 [ 1 ] ;
V_113 ++ ;
}
if ( type & V_54 ) {
V_123 -> time = * V_113 ;
V_113 ++ ;
}
V_123 -> V_131 = 0 ;
if ( type & V_45 ) {
V_123 -> V_131 = * V_113 ;
V_113 ++ ;
}
V_123 -> V_78 = - 1ULL ;
if ( type & V_118 ) {
V_123 -> V_78 = * V_113 ;
V_113 ++ ;
}
if ( type & V_116 ) {
V_123 -> V_117 = * V_113 ;
V_113 ++ ;
}
if ( type & V_50 ) {
V_127 . V_125 = * V_113 ;
if ( V_124 ) {
V_127 . V_125 = F_36 ( V_127 . V_125 ) ;
V_127 . V_126 [ 0 ] = F_37 ( V_127 . V_126 [ 0 ] ) ;
}
V_123 -> V_72 = V_127 . V_126 [ 0 ] ;
V_113 ++ ;
}
if ( type & V_39 ) {
V_123 -> V_51 = * V_113 ;
V_113 ++ ;
}
if ( type & V_132 ) {
fprintf ( V_133 , L_1 ) ;
return - 1 ;
}
if ( type & V_48 ) {
if ( F_34 ( V_110 , V_113 , sizeof( V_123 -> V_134 -> V_102 ) ) )
return - V_129 ;
V_123 -> V_134 = (struct V_135 * ) V_113 ;
if ( F_34 ( V_110 , V_113 , V_123 -> V_134 -> V_102 ) )
return - V_129 ;
V_113 += 1 + V_123 -> V_134 -> V_102 ;
}
if ( type & V_56 ) {
const T_1 * V_136 ;
V_127 . V_125 = * V_113 ;
if ( F_38 ( V_124 ,
L_2 ) ) {
V_127 . V_125 = F_36 ( V_127 . V_125 ) ;
V_127 . V_126 [ 0 ] = F_37 ( V_127 . V_126 [ 0 ] ) ;
V_127 . V_126 [ 1 ] = F_37 ( V_127 . V_126 [ 1 ] ) ;
}
if ( F_34 ( V_110 , V_113 , sizeof( T_3 ) ) )
return - V_129 ;
V_123 -> V_137 = V_127 . V_126 [ 0 ] ;
V_136 = ( void * ) V_113 + sizeof( T_3 ) ;
if ( F_34 ( V_110 , V_136 , V_123 -> V_137 ) )
return - V_129 ;
V_123 -> V_138 = ( void * ) V_136 ;
V_113 = ( void * ) V_113 + V_123 -> V_137 + sizeof( T_3 ) ;
}
if ( type & V_61 ) {
T_1 V_139 ;
V_123 -> V_60 = (struct V_60 * ) V_113 ;
V_113 ++ ;
V_139 = V_123 -> V_60 -> V_102 * sizeof( struct V_140 ) ;
V_139 /= sizeof( T_1 ) ;
V_113 += V_139 ;
}
return 0 ;
}
int F_39 ( union V_109 * V_110 , T_1 type ,
const struct V_111 * V_112 ,
bool V_124 )
{
T_1 * V_113 ;
union {
T_1 V_125 ;
T_3 V_126 [ 2 ] ;
} V_127 ;
V_113 = V_110 -> V_112 . V_113 ;
if ( type & V_31 ) {
V_110 -> V_130 . V_130 = V_112 -> V_130 ;
V_113 ++ ;
}
if ( type & V_32 ) {
V_127 . V_126 [ 0 ] = V_112 -> V_100 ;
V_127 . V_126 [ 1 ] = V_112 -> V_119 ;
if ( V_124 ) {
V_127 . V_126 [ 0 ] = F_37 ( V_127 . V_126 [ 0 ] ) ;
V_127 . V_126 [ 1 ] = F_37 ( V_127 . V_126 [ 1 ] ) ;
V_127 . V_125 = F_36 ( V_127 . V_125 ) ;
}
* V_113 = V_127 . V_125 ;
V_113 ++ ;
}
if ( type & V_54 ) {
* V_113 = V_112 -> time ;
V_113 ++ ;
}
if ( type & V_45 ) {
* V_113 = V_112 -> V_131 ;
V_113 ++ ;
}
if ( type & V_118 ) {
* V_113 = V_112 -> V_78 ;
V_113 ++ ;
}
if ( type & V_116 ) {
* V_113 = V_112 -> V_117 ;
V_113 ++ ;
}
if ( type & V_50 ) {
V_127 . V_126 [ 0 ] = V_112 -> V_72 ;
if ( V_124 ) {
V_127 . V_126 [ 0 ] = F_37 ( V_127 . V_126 [ 0 ] ) ;
V_127 . V_125 = F_36 ( V_127 . V_125 ) ;
}
* V_113 = V_127 . V_125 ;
V_113 ++ ;
}
if ( type & V_39 ) {
* V_113 = V_112 -> V_51 ;
V_113 ++ ;
}
return 0 ;
}
