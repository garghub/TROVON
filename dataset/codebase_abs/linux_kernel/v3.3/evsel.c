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
static void F_2 ( struct V_6 * V_6 )
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
void F_8 ( struct V_13 * V_14 , struct V_19 * V_20 )
{
struct V_15 * V_16 = & V_14 -> V_16 ;
int V_21 = ! V_14 -> V_17 ;
V_16 -> V_22 = V_20 -> V_23 ? 1 : 0 ;
V_16 -> V_24 = ! V_20 -> V_25 ;
V_16 -> V_26 = V_27 |
V_28 |
V_29 ;
V_16 -> V_1 |= V_30 | V_31 ;
if ( ! V_16 -> V_32 || ( V_20 -> V_33 != V_34 &&
V_20 -> V_35 != V_36 ) ) {
if ( V_20 -> V_37 ) {
V_16 -> V_1 |= V_38 ;
V_16 -> V_37 = 1 ;
V_16 -> V_39 = V_20 -> V_37 ;
} else {
V_16 -> V_32 = V_20 -> V_40 ;
}
}
if ( V_20 -> V_41 )
V_16 -> V_39 = 0 ;
if ( V_20 -> V_42 )
V_16 -> V_42 = 1 ;
if ( V_20 -> V_43 ) {
V_16 -> V_1 |= V_44 ;
V_16 -> V_45 = V_21 ;
}
if ( V_20 -> V_46 )
V_16 -> V_1 |= V_47 ;
if ( V_20 -> V_48 )
V_16 -> V_1 |= V_49 ;
if ( V_20 -> V_50 )
V_16 -> V_1 |= V_38 ;
if ( V_20 -> V_23 &&
( V_20 -> V_51 || V_20 -> V_48 ||
! V_20 -> V_25 || V_20 -> V_52 ) )
V_16 -> V_1 |= V_53 ;
if ( V_20 -> V_54 ) {
V_16 -> V_1 |= V_53 ;
V_16 -> V_1 |= V_55 ;
V_16 -> V_1 |= V_49 ;
}
if ( V_20 -> V_56 ) {
V_16 -> V_57 = 0 ;
V_16 -> V_58 = 1 ;
}
V_16 -> V_59 = V_21 ;
V_16 -> V_60 = V_21 ;
if ( V_20 -> V_61 == - 1 && V_20 -> V_62 == - 1 && ! V_20 -> V_48 ) {
V_16 -> V_63 = 1 ;
V_16 -> V_64 = 1 ;
}
}
int F_9 ( struct V_13 * V_14 , int V_65 , int V_66 )
{
int V_67 , V_68 ;
V_14 -> V_69 = F_10 ( V_65 , V_66 , sizeof( int ) ) ;
if ( V_14 -> V_69 ) {
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ ) {
for ( V_68 = 0 ; V_68 < V_66 ; V_68 ++ ) {
F_11 ( V_14 , V_67 , V_68 ) = - 1 ;
}
}
}
return V_14 -> V_69 != NULL ? 0 : - V_70 ;
}
int F_12 ( struct V_13 * V_14 , int V_65 , int V_66 )
{
V_14 -> V_71 = F_10 ( V_65 , V_66 , sizeof( struct V_72 ) ) ;
if ( V_14 -> V_71 == NULL )
return - V_70 ;
V_14 -> V_73 = F_7 ( V_65 * V_66 * sizeof( T_1 ) ) ;
if ( V_14 -> V_73 == NULL ) {
F_13 ( V_14 -> V_71 ) ;
V_14 -> V_71 = NULL ;
return - V_70 ;
}
return 0 ;
}
int F_14 ( struct V_13 * V_14 , int V_65 )
{
V_14 -> V_74 = F_7 ( ( sizeof( * V_14 -> V_74 ) +
( V_65 * sizeof( struct V_75 ) ) ) ) ;
return V_14 -> V_74 != NULL ? 0 : - V_70 ;
}
void F_15 ( struct V_13 * V_14 )
{
F_13 ( V_14 -> V_69 ) ;
V_14 -> V_69 = NULL ;
}
void F_16 ( struct V_13 * V_14 )
{
F_13 ( V_14 -> V_71 ) ;
V_14 -> V_71 = NULL ;
free ( V_14 -> V_73 ) ;
V_14 -> V_73 = NULL ;
}
void F_17 ( struct V_13 * V_14 , int V_65 , int V_66 )
{
int V_67 , V_68 ;
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ )
for ( V_68 = 0 ; V_68 < V_66 ; ++ V_68 ) {
F_18 ( F_11 ( V_14 , V_67 , V_68 ) ) ;
F_11 ( V_14 , V_67 , V_68 ) = - 1 ;
}
}
void F_19 ( struct V_13 * V_14 )
{
assert ( F_20 ( & V_14 -> V_18 ) ) ;
F_13 ( V_14 -> V_69 ) ;
F_13 ( V_14 -> V_71 ) ;
free ( V_14 -> V_73 ) ;
}
void F_21 ( struct V_13 * V_14 )
{
F_19 ( V_14 ) ;
F_22 ( V_14 -> V_76 ) ;
free ( V_14 -> V_77 ) ;
free ( V_14 ) ;
}
int F_23 ( struct V_13 * V_14 ,
int V_67 , int V_68 , bool V_78 )
{
struct V_75 V_79 ;
T_2 V_80 = V_78 ? 3 : 1 ;
if ( F_11 ( V_14 , V_67 , V_68 ) < 0 )
return - V_81 ;
if ( V_14 -> V_74 == NULL && F_14 ( V_14 , V_67 + 1 ) < 0 )
return - V_70 ;
if ( F_24 ( F_11 ( V_14 , V_67 , V_68 ) , & V_79 , V_80 * sizeof( T_1 ) ) < 0 )
return - V_82 ;
if ( V_78 ) {
if ( V_79 . V_83 == 0 )
V_79 . V_84 = 0 ;
else if ( V_79 . V_83 < V_79 . V_85 )
V_79 . V_84 = ( T_1 ) ( ( double ) V_79 . V_84 * V_79 . V_85 / V_79 . V_83 + 0.5 ) ;
} else
V_79 . V_85 = V_79 . V_83 = 0 ;
V_14 -> V_74 -> V_67 [ V_67 ] = V_79 ;
return 0 ;
}
int F_25 ( struct V_13 * V_14 ,
int V_65 , int V_66 , bool V_78 )
{
T_2 V_80 = V_78 ? 3 : 1 ;
int V_67 , V_68 ;
struct V_75 * V_86 = & V_14 -> V_74 -> V_86 , V_79 ;
V_86 -> V_84 = V_86 -> V_85 = V_86 -> V_83 = 0 ;
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ ) {
for ( V_68 = 0 ; V_68 < V_66 ; V_68 ++ ) {
if ( F_11 ( V_14 , V_67 , V_68 ) < 0 )
continue;
if ( F_24 ( F_11 ( V_14 , V_67 , V_68 ) ,
& V_79 , V_80 * sizeof( T_1 ) ) < 0 )
return - V_82 ;
V_86 -> V_84 += V_79 . V_84 ;
if ( V_78 ) {
V_86 -> V_85 += V_79 . V_85 ;
V_86 -> V_83 += V_79 . V_83 ;
}
}
}
V_14 -> V_74 -> V_87 = 0 ;
if ( V_78 ) {
if ( V_86 -> V_83 == 0 ) {
V_14 -> V_74 -> V_87 = - 1 ;
V_86 -> V_84 = 0 ;
return 0 ;
}
if ( V_86 -> V_83 < V_86 -> V_85 ) {
V_14 -> V_74 -> V_87 = 1 ;
V_86 -> V_84 = ( T_1 ) ( ( double ) V_86 -> V_84 * V_86 -> V_85 / V_86 -> V_83 + 0.5 ) ;
}
} else
V_86 -> V_85 = V_86 -> V_83 = 0 ;
return 0 ;
}
static int F_26 ( struct V_13 * V_14 , struct V_88 * V_89 ,
struct V_90 * V_91 , bool V_92 ,
struct V_93 * V_94 )
{
int V_67 , V_68 ;
unsigned long V_95 = 0 ;
int V_96 = - 1 , V_97 ;
if ( V_14 -> V_69 == NULL &&
F_9 ( V_14 , V_89 -> V_98 , V_91 -> V_98 ) < 0 )
return - V_70 ;
if ( V_14 -> V_76 ) {
V_95 = V_99 ;
V_96 = V_14 -> V_76 -> V_69 ;
}
for ( V_67 = 0 ; V_67 < V_89 -> V_98 ; V_67 ++ ) {
int V_100 = V_94 ? F_27 ( V_94 , V_67 ) : - 1 ;
for ( V_68 = 0 ; V_68 < V_91 -> V_98 ; V_68 ++ ) {
if ( ! V_14 -> V_76 )
V_96 = V_91 -> V_101 [ V_68 ] ;
F_11 ( V_14 , V_67 , V_68 ) = F_28 ( & V_14 -> V_16 ,
V_96 ,
V_89 -> V_101 [ V_67 ] ,
V_100 , V_95 ) ;
if ( F_11 ( V_14 , V_67 , V_68 ) < 0 ) {
V_97 = - V_82 ;
goto V_102;
}
if ( V_92 && V_100 == - 1 )
V_100 = F_11 ( V_14 , V_67 , V_68 ) ;
}
}
return 0 ;
V_102:
do {
while ( -- V_68 >= 0 ) {
F_18 ( F_11 ( V_14 , V_67 , V_68 ) ) ;
F_11 ( V_14 , V_67 , V_68 ) = - 1 ;
}
V_68 = V_91 -> V_98 ;
} while ( -- V_67 >= 0 );
return V_97 ;
}
void F_29 ( struct V_13 * V_14 , int V_65 , int V_66 )
{
if ( V_14 -> V_69 == NULL )
return;
F_17 ( V_14 , V_65 , V_66 ) ;
F_15 ( V_14 ) ;
V_14 -> V_69 = NULL ;
}
int F_30 ( struct V_13 * V_14 , struct V_88 * V_89 ,
struct V_90 * V_91 , bool V_92 ,
struct V_93 * V_100 )
{
if ( V_89 == NULL ) {
V_89 = & V_103 . V_101 ;
}
if ( V_91 == NULL )
V_91 = & V_104 . V_101 ;
return F_26 ( V_14 , V_89 , V_91 , V_92 , V_100 ) ;
}
int F_31 ( struct V_13 * V_14 ,
struct V_88 * V_89 , bool V_92 ,
struct V_93 * V_100 )
{
return F_26 ( V_14 , V_89 , & V_104 . V_101 , V_92 ,
V_100 ) ;
}
int F_32 ( struct V_13 * V_14 ,
struct V_90 * V_91 , bool V_92 ,
struct V_93 * V_100 )
{
return F_26 ( V_14 , & V_103 . V_101 , V_91 , V_92 ,
V_100 ) ;
}
static int F_33 ( const union V_105 * V_106 , T_1 type ,
struct V_107 * V_108 )
{
const T_1 * V_109 = V_106 -> V_108 . V_109 ;
V_109 += ( ( V_106 -> V_110 . V_4 -
sizeof( V_106 -> V_110 ) ) / sizeof( T_1 ) ) - 1 ;
if ( type & V_49 ) {
T_3 * V_111 = ( T_3 * ) V_109 ;
V_108 -> V_67 = * V_111 ;
V_109 -- ;
}
if ( type & V_112 ) {
V_108 -> V_113 = * V_109 ;
V_109 -- ;
}
if ( type & V_114 ) {
V_108 -> V_73 = * V_109 ;
V_109 -- ;
}
if ( type & V_53 ) {
V_108 -> time = * V_109 ;
V_109 -- ;
}
if ( type & V_31 ) {
T_3 * V_111 = ( T_3 * ) V_109 ;
V_108 -> V_96 = V_111 [ 0 ] ;
V_108 -> V_115 = V_111 [ 1 ] ;
}
return 0 ;
}
static bool F_34 ( const union V_105 * V_106 ,
const void * V_116 , T_1 V_4 )
{
const void * V_117 = V_106 ;
if ( V_116 + V_4 > V_117 + V_106 -> V_110 . V_4 )
return true ;
return false ;
}
int F_35 ( const union V_105 * V_106 , T_1 type ,
int V_118 , bool V_22 ,
struct V_107 * V_119 , bool V_120 )
{
const T_1 * V_109 ;
union {
T_1 V_121 ;
T_3 V_122 [ 2 ] ;
} V_123 ;
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
V_119 -> V_67 = V_119 -> V_96 = V_119 -> V_115 = - 1 ;
V_119 -> V_113 = V_119 -> V_73 = V_119 -> time = - 1ULL ;
V_119 -> V_50 = 1 ;
if ( V_106 -> V_110 . type != V_124 ) {
if ( ! V_22 )
return 0 ;
return F_33 ( V_106 , type , V_119 ) ;
}
V_109 = V_106 -> V_108 . V_109 ;
if ( V_118 + sizeof( V_106 -> V_110 ) > V_106 -> V_110 . V_4 )
return - V_125 ;
if ( type & V_30 ) {
V_119 -> V_126 = V_106 -> V_126 . V_126 ;
V_109 ++ ;
}
if ( type & V_31 ) {
V_123 . V_121 = * V_109 ;
if ( V_120 ) {
V_123 . V_121 = F_36 ( V_123 . V_121 ) ;
V_123 . V_122 [ 0 ] = F_37 ( V_123 . V_122 [ 0 ] ) ;
V_123 . V_122 [ 1 ] = F_37 ( V_123 . V_122 [ 1 ] ) ;
}
V_119 -> V_96 = V_123 . V_122 [ 0 ] ;
V_119 -> V_115 = V_123 . V_122 [ 1 ] ;
V_109 ++ ;
}
if ( type & V_53 ) {
V_119 -> time = * V_109 ;
V_109 ++ ;
}
V_119 -> V_127 = 0 ;
if ( type & V_44 ) {
V_119 -> V_127 = * V_109 ;
V_109 ++ ;
}
V_119 -> V_73 = - 1ULL ;
if ( type & V_114 ) {
V_119 -> V_73 = * V_109 ;
V_109 ++ ;
}
if ( type & V_112 ) {
V_119 -> V_113 = * V_109 ;
V_109 ++ ;
}
if ( type & V_49 ) {
V_123 . V_121 = * V_109 ;
if ( V_120 ) {
V_123 . V_121 = F_36 ( V_123 . V_121 ) ;
V_123 . V_122 [ 0 ] = F_37 ( V_123 . V_122 [ 0 ] ) ;
}
V_119 -> V_67 = V_123 . V_122 [ 0 ] ;
V_109 ++ ;
}
if ( type & V_38 ) {
V_119 -> V_50 = * V_109 ;
V_109 ++ ;
}
if ( type & V_128 ) {
fprintf ( V_129 , L_1 ) ;
return - 1 ;
}
if ( type & V_47 ) {
if ( F_34 ( V_106 , V_109 , sizeof( V_119 -> V_130 -> V_98 ) ) )
return - V_125 ;
V_119 -> V_130 = (struct V_131 * ) V_109 ;
if ( F_34 ( V_106 , V_109 , V_119 -> V_130 -> V_98 ) )
return - V_125 ;
V_109 += 1 + V_119 -> V_130 -> V_98 ;
}
if ( type & V_55 ) {
const T_1 * V_132 ;
V_123 . V_121 = * V_109 ;
if ( F_38 ( V_120 ,
L_2 ) ) {
V_123 . V_121 = F_36 ( V_123 . V_121 ) ;
V_123 . V_122 [ 0 ] = F_37 ( V_123 . V_122 [ 0 ] ) ;
V_123 . V_122 [ 1 ] = F_37 ( V_123 . V_122 [ 1 ] ) ;
}
if ( F_34 ( V_106 , V_109 , sizeof( T_3 ) ) )
return - V_125 ;
V_119 -> V_133 = V_123 . V_122 [ 0 ] ;
V_132 = ( void * ) V_109 + sizeof( T_3 ) ;
if ( F_34 ( V_106 , V_132 , V_119 -> V_133 ) )
return - V_125 ;
V_119 -> V_134 = ( void * ) V_132 ;
}
return 0 ;
}
int F_39 ( union V_105 * V_106 , T_1 type ,
const struct V_107 * V_108 ,
bool V_120 )
{
T_1 * V_109 ;
union {
T_1 V_121 ;
T_3 V_122 [ 2 ] ;
} V_123 ;
V_109 = V_106 -> V_108 . V_109 ;
if ( type & V_30 ) {
V_106 -> V_126 . V_126 = V_108 -> V_126 ;
V_109 ++ ;
}
if ( type & V_31 ) {
V_123 . V_122 [ 0 ] = V_108 -> V_96 ;
V_123 . V_122 [ 1 ] = V_108 -> V_115 ;
if ( V_120 ) {
V_123 . V_122 [ 0 ] = F_37 ( V_123 . V_122 [ 0 ] ) ;
V_123 . V_122 [ 1 ] = F_37 ( V_123 . V_122 [ 1 ] ) ;
V_123 . V_121 = F_36 ( V_123 . V_121 ) ;
}
* V_109 = V_123 . V_121 ;
V_109 ++ ;
}
if ( type & V_53 ) {
* V_109 = V_108 -> time ;
V_109 ++ ;
}
if ( type & V_44 ) {
* V_109 = V_108 -> V_127 ;
V_109 ++ ;
}
if ( type & V_114 ) {
* V_109 = V_108 -> V_73 ;
V_109 ++ ;
}
if ( type & V_112 ) {
* V_109 = V_108 -> V_113 ;
V_109 ++ ;
}
if ( type & V_49 ) {
V_123 . V_122 [ 0 ] = V_108 -> V_67 ;
if ( V_120 ) {
V_123 . V_122 [ 0 ] = F_37 ( V_123 . V_122 [ 0 ] ) ;
V_123 . V_121 = F_36 ( V_123 . V_121 ) ;
}
* V_109 = V_123 . V_121 ;
V_109 ++ ;
}
if ( type & V_38 ) {
* V_109 = V_108 -> V_50 ;
V_109 ++ ;
}
return 0 ;
}
