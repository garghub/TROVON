static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 ;
if ( V_2 -> V_6 ) {
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; V_3 ++ ) {
V_5 = V_2 -> V_6 + V_3 ;
F_2 ( V_5 ) ;
if ( V_5 -> V_8 ) {
F_3 ( V_2 , V_5 , 0 ) ;
F_4 ( V_5 -> V_8 ) ;
}
}
F_4 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
V_2 -> V_7 = 0 ;
}
F_4 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
V_2 -> V_10 = NULL ;
V_2 -> V_11 = NULL ;
V_2 -> V_12 = NULL ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = NULL ;
V_2 -> V_16 = NULL ;
V_2 -> V_17 = NULL ;
V_2 -> V_18 = NULL ;
F_5 ( V_2 , NULL ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
V_2 -> V_19 = 0 ;
if ( V_2 -> V_10 )
V_2 -> V_10 -> V_20 ( V_2 ) ;
else
F_7 ( V_21
L_1 ) ;
F_1 ( V_2 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_19 )
return;
F_6 ( V_2 ) ;
}
int F_9 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_24 * V_25 ;
int V_26 ;
if ( V_2 -> V_19 )
return - V_27 ;
for ( V_25 = V_28 ; V_25 ; V_25 = V_25 -> V_29 ) {
if ( ! F_10 ( V_25 -> V_30 ) ) {
F_7 ( V_31 L_2 ) ;
continue;
}
if ( V_25 -> V_32 ) {
V_2 -> V_12 = F_11 ( V_25 , V_23 -> V_11 ) ;
if ( V_2 -> V_12 == NULL ) {
F_12 ( V_25 -> V_30 ) ;
continue;
}
} else {
if ( strcmp ( V_25 -> V_33 , V_23 -> V_11 ) ) {
F_12 ( V_25 -> V_30 ) ;
continue;
}
}
V_2 -> V_10 = V_25 ;
V_26 = V_25 -> V_34 ( V_2 , V_23 ) ;
if ( V_26 < 0 ) {
F_12 ( V_2 -> V_10 -> V_30 ) ;
F_6 ( V_2 ) ;
return V_26 ;
}
goto V_19;
}
for ( V_25 = V_28 ; V_25 ; V_25 = V_25 -> V_29 ) {
if ( ! F_10 ( V_25 -> V_30 ) ) {
F_7 ( V_31
L_3 ) ;
continue;
}
F_13 ( V_25 ) ;
F_12 ( V_25 -> V_30 ) ;
}
return - V_35 ;
V_19:
V_26 = F_14 ( V_2 ) ;
F_12 ( V_2 -> V_10 -> V_30 ) ;
if ( V_26 < 0 ) {
F_6 ( V_2 ) ;
return V_26 ;
}
if ( ! V_2 -> V_11 ) {
F_7 ( V_21 L_4 ,
V_2 -> V_11 ) ;
V_2 -> V_11 = L_5 ;
}
F_15 () ;
V_2 -> V_19 = 1 ;
return 0 ;
}
int F_16 ( struct V_24 * V_10 )
{
V_10 -> V_29 = V_28 ;
V_28 = V_10 ;
return 0 ;
}
int F_17 ( struct V_24 * V_10 )
{
struct V_24 * V_36 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_37 ; V_3 ++ ) {
struct V_38 * V_39 =
F_18 ( V_3 ) ;
struct V_1 * V_2 ;
if ( V_39 == NULL )
continue;
V_2 = V_39 -> V_40 ;
F_19 ( & V_2 -> V_41 ) ;
if ( V_2 -> V_19 && V_2 -> V_10 == V_10 ) {
if ( V_2 -> V_42 )
F_7 ( V_21 L_6 ,
V_2 -> V_42 ) ;
F_8 ( V_2 ) ;
}
F_20 ( & V_2 -> V_41 ) ;
}
if ( V_28 == V_10 ) {
V_28 = V_10 -> V_29 ;
return 0 ;
}
for ( V_36 = V_28 ; V_36 -> V_29 ; V_36 = V_36 -> V_29 ) {
if ( V_36 -> V_29 == V_10 ) {
V_36 -> V_29 = V_10 -> V_29 ;
return 0 ;
}
}
return - V_43 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 ;
struct V_44 * V_8 = NULL ;
int V_26 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; V_3 ++ ) {
V_5 = V_2 -> V_6 + V_3 ;
if ( V_5 -> type == V_45 )
continue;
if ( V_5 -> V_46 == 0 )
V_5 -> V_46 = 1 ;
if ( V_5 -> V_47 ) {
F_21 ( ( V_5 -> V_48 & ( V_49 |
V_50 ) ) == 0 ) ;
F_21 ( ! V_5 -> V_51 ) ;
V_8 =
F_22 ( sizeof( struct V_44 ) , V_52 ) ;
if ( V_8 == NULL ) {
F_7 ( V_31
L_7 ) ;
return - V_53 ;
}
F_23 ( & V_8 -> V_54 ) ;
V_8 -> V_55 = V_5 ;
V_5 -> V_8 = V_8 ;
#define F_24 (64*1024)
#define F_25 (64*1024)
V_8 -> V_56 = F_24 ;
V_8 -> V_57 = NULL ;
V_8 -> V_58 = 0 ;
if ( F_3 ( V_2 , V_5 , F_25 ) < 0 ) {
F_7 ( V_31 L_8 ) ;
return - V_53 ;
}
if ( V_5 -> V_59 ) {
V_26 = V_5 -> V_59 ( V_2 , V_5 , F_25 ) ;
if ( V_26 < 0 )
return V_26 ;
}
F_26 ( V_2 , V_5 ) ;
}
if ( ! V_5 -> V_60 && ! V_5 -> V_61 )
V_5 -> V_60 = & V_62 ;
if ( ! V_5 -> V_63 && V_5 -> V_64 )
V_5 -> V_63 = V_65 ;
if ( ! V_5 -> V_66 && V_5 -> V_64 )
V_5 -> V_66 = V_65 ;
if ( ! V_5 -> V_63 )
V_5 -> V_63 = V_67 ;
if ( ! V_5 -> V_66 )
V_5 -> V_66 = V_67 ;
if ( ! V_5 -> V_64 )
V_5 -> V_64 = V_67 ;
if ( ! V_5 -> V_68 )
V_5 -> V_68 = V_67 ;
if ( ! V_5 -> V_69 )
V_5 -> V_69 = V_70 ;
}
return 0 ;
}
static void * F_11 ( struct V_24 * V_25 , const char * V_71 )
{
unsigned V_3 ;
const char * const * V_72 = V_25 -> V_11 ;
for ( V_3 = 0 ; V_3 < V_25 -> V_32 ; V_3 ++ ) {
if ( strcmp ( * V_72 , V_71 ) == 0 )
return ( void * ) V_72 ;
V_72 =
( const char * const * ) ( ( const char * ) V_72 +
V_25 -> V_73 ) ;
}
return NULL ;
}
static void F_13 ( struct V_24 * V_25 )
{
unsigned int V_3 ;
const char * const * V_72 ;
F_7 ( V_31 L_9 ,
V_25 -> V_33 ) ;
V_72 = V_25 -> V_11 ;
for ( V_3 = 0 ; V_3 < V_25 -> V_32 ; V_3 ++ ) {
F_7 ( V_31 L_10 , * V_72 ) ;
V_72 = ( const char * * ) ( ( char * ) V_72 + V_25 -> V_73 ) ;
}
if ( V_25 -> V_32 == 0 )
F_7 ( V_31 L_10 , V_25 -> V_33 ) ;
}
static int V_70 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
return - V_43 ;
}
int V_67 ( struct V_1 * V_2 , struct V_4 * V_5 ,
struct V_74 * V_75 , unsigned int * V_76 )
{
return - V_43 ;
}
static int V_65 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
struct V_74 * V_75 , unsigned int * V_76 )
{
struct V_74 V_77 ;
int V_26 ;
static const unsigned V_78 = 32 ;
unsigned V_79 = F_27 ( V_75 -> V_80 ) ;
const unsigned V_81 =
( V_79 < V_78 ) ? 0 : V_79 ;
unsigned int V_82 [ 2 ] ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
memset ( & V_77 , 0 , sizeof( V_77 ) ) ;
V_77 . V_75 = V_83 ;
V_77 . V_80 = V_81 ;
V_77 . V_84 = 2 ;
V_77 . V_76 = V_82 ;
V_77 . V_85 = V_75 -> V_85 ;
if ( V_75 -> V_75 == V_86 ) {
if ( ! ( V_5 -> V_48 & V_87 ) )
return - V_43 ;
V_82 [ 0 ] = 1 << ( V_79 - V_81 ) ;
V_82 [ 1 ] = V_76 [ 0 ] ? ( 1 << ( V_79 - V_81 ) )
: 0 ;
}
V_26 = V_5 -> V_64 ( V_2 , V_5 , & V_77 , V_82 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_75 -> V_75 == V_88 )
V_76 [ 0 ] = ( V_82 [ 1 ] >> ( V_79 - V_81 ) ) & 1 ;
return 1 ;
}
static inline unsigned long F_28 ( T_1 * V_89 , unsigned long V_90 )
{
unsigned long V_26 = 0UL ;
T_2 * V_91 ;
T_3 * V_92 , V_93 ;
T_4 * V_94 ;
if ( ! F_29 ( * V_89 ) ) {
V_94 = F_30 ( V_89 , V_90 ) ;
V_91 = F_31 ( V_94 , V_90 ) ;
if ( ! F_32 ( * V_91 ) ) {
V_92 = F_33 ( V_91 , V_90 ) ;
V_93 = * V_92 ;
if ( F_34 ( V_93 ) ) {
V_26 = ( unsigned long )
F_35 ( F_36 ( V_93 ) ) ;
V_26 |= ( V_90 & ( V_95 - 1 ) ) ;
}
}
}
return V_26 ;
}
static inline unsigned long F_37 ( unsigned long V_90 )
{
unsigned long V_96 , V_97 ;
V_96 = V_90 ;
V_97 = F_28 ( F_38 ( V_96 ) , V_96 ) ;
return V_97 ;
}
int F_3 ( struct V_1 * V_2 , struct V_4 * V_5 ,
unsigned long V_98 )
{
struct V_44 * V_8 = V_5 -> V_8 ;
V_98 = ( V_98 + V_95 - 1 ) & V_99 ;
if ( V_8 -> V_57 && V_8 -> V_58 == V_98 )
return 0 ;
if ( V_8 -> V_57 ) {
F_39 ( V_8 -> V_57 ) ;
V_8 -> V_57 = NULL ;
V_8 -> V_58 = 0 ;
}
if ( V_8 -> V_100 ) {
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_8 -> V_101 ; ++ V_3 ) {
if ( V_8 -> V_100 [ V_3 ] . V_102 ) {
F_40 ( V_103 ,
& ( F_41 ( V_8 -> V_100 [ V_3 ] .
V_102 ) -> V_104 ) ) ;
if ( V_5 -> V_105 != V_106 ) {
F_42 ( V_2 -> V_107 ,
V_95 ,
V_8 ->
V_100
[ V_3 ] . V_102 ,
V_8 ->
V_100
[ V_3 ] . V_108 ) ;
} else {
F_43 ( ( unsigned long )
V_8 -> V_100 [ V_3 ] .
V_102 ) ;
}
}
}
F_44 ( V_8 -> V_100 ) ;
V_8 -> V_100 = NULL ;
V_8 -> V_101 = 0 ;
}
if ( V_98 ) {
unsigned V_3 = 0 ;
unsigned V_109 = V_98 >> V_110 ;
struct V_111 * * V_112 = NULL ;
V_8 -> V_100 =
F_45 ( sizeof( struct V_113 ) * V_109 ) ;
if ( V_8 -> V_100 )
V_112 = F_46 ( sizeof( struct V_111 * ) * V_109 ) ;
if ( V_112 ) {
for ( V_3 = 0 ; V_3 < V_109 ; V_3 ++ ) {
if ( V_5 -> V_105 != V_106 ) {
V_8 -> V_100 [ V_3 ] . V_102 =
F_47 ( V_2 -> V_107 ,
V_95 ,
& V_8 ->
V_100
[ V_3 ] . V_108 ,
V_52 |
V_114 ) ;
} else {
V_8 -> V_100 [ V_3 ] . V_102 =
( void * )
F_48 ( V_52 ) ;
}
if ( V_8 -> V_100 [ V_3 ] . V_102 == NULL )
break;
F_49 ( V_103 ,
& ( F_41 ( V_8 -> V_100 [ V_3 ] .
V_102 ) -> V_104 ) ) ;
V_112 [ V_3 ] = F_41 ( V_8 -> V_100 [ V_3 ] .
V_102 ) ;
}
}
if ( V_3 == V_109 ) {
V_8 -> V_57 =
F_50 ( V_112 , V_109 , V_115 , V_116 ) ;
}
F_44 ( V_112 ) ;
if ( V_8 -> V_57 == NULL ) {
if ( V_8 -> V_100 ) {
for ( V_3 = 0 ; V_3 < V_109 ; V_3 ++ ) {
if ( V_8 -> V_100 [ V_3 ] . V_102 ==
NULL ) {
break;
}
F_40 ( V_103 ,
& ( F_41 ( V_8 ->
V_100 [ V_3 ] .
V_102 ) -> V_104 ) ) ;
if ( V_5 -> V_105 != V_106 ) {
F_42 ( V_2 -> V_107 ,
V_95 ,
V_8 ->
V_100
[ V_3 ] . V_102 ,
V_8 ->
V_100
[ V_3 ] . V_108 ) ;
} else {
F_43 ( ( unsigned long )
V_8 -> V_100
[ V_3 ] . V_102 ) ;
}
}
F_44 ( V_8 -> V_100 ) ;
V_8 -> V_100 = NULL ;
}
return - V_53 ;
}
V_8 -> V_101 = V_109 ;
}
V_8 -> V_58 = V_98 ;
return 0 ;
}
static unsigned int F_51 ( struct V_44 * V_8 ,
unsigned int V_117 )
{
struct V_4 * V_5 = V_8 -> V_55 ;
unsigned int V_118 = 0 ;
const unsigned V_119 = F_52 ( V_5 ) ;
if ( V_5 -> V_120 == NULL || ( V_8 -> V_121 . V_104 & V_122 ) ) {
V_8 -> V_123 += V_117 ;
F_21 ( ( int ) ( V_8 -> V_123 - V_8 -> V_124 ) > 0 ) ;
return V_117 ;
}
V_117 -= V_117 % V_119 ;
while ( V_118 < V_117 ) {
int V_125 ;
V_125 = V_117 - V_118 ;
if ( V_125 < 0 ) {
F_7 ( V_21
L_11 ,
__FILE__ , V_126 ) ;
break;
}
if ( ( int ) ( V_8 -> V_127 + V_125 -
V_8 -> V_58 ) > 0 )
V_125 = V_8 -> V_58 - V_8 -> V_127 ;
V_5 -> V_120 ( V_5 -> V_40 , V_5 , V_8 -> V_57 + V_8 -> V_127 ,
V_125 , V_8 -> V_128 ) ;
F_15 () ;
V_8 -> V_128 += V_125 / V_119 ;
V_8 -> V_128 %= V_8 -> V_121 . V_129 ;
V_8 -> V_123 += V_125 ;
V_8 -> V_127 += V_125 ;
V_8 -> V_127 %= V_8 -> V_58 ;
V_118 += V_125 ;
}
F_21 ( ( int ) ( V_8 -> V_123 - V_8 -> V_124 ) > 0 ) ;
return V_118 ;
}
unsigned int F_53 ( struct V_44 * V_8 )
{
unsigned int V_130 ;
unsigned int V_131 ;
if ( V_8 == NULL )
return 0 ;
V_130 = V_8 -> V_132 + V_8 -> V_58 ;
V_131 = V_130 - V_8 -> V_133 ;
V_131 -= V_131 % F_52 ( V_8 -> V_55 ) ;
F_54 () ;
return V_131 ;
}
unsigned int F_55 ( struct V_44 * V_8 ,
unsigned int V_131 )
{
unsigned int V_130 = V_8 -> V_132 + V_8 -> V_58 ;
if ( ( int ) ( V_8 -> V_133 + V_131 - V_130 ) > 0 )
V_131 = V_130 - V_8 -> V_133 ;
V_8 -> V_133 += V_131 ;
F_54 () ;
return V_131 ;
}
unsigned int F_56 ( struct V_44 * V_8 ,
unsigned int V_131 )
{
unsigned int V_130 = V_8 -> V_132 + V_8 -> V_58 ;
if ( ( int ) ( V_8 -> V_133 + V_131 - V_130 ) > 0 )
V_131 = 0 ;
V_8 -> V_133 += V_131 ;
F_54 () ;
return V_131 ;
}
unsigned F_57 ( struct V_44 * V_8 , unsigned int V_131 )
{
if ( ( int ) ( V_8 -> V_124 + V_131 -
V_8 -> V_133 ) > 0 ) {
F_7 ( V_31 L_12 ) ;
V_131 = V_8 -> V_133 - V_8 -> V_124 ;
}
V_8 -> V_124 += V_131 ;
V_8 -> V_134 += V_131 ;
F_51 ( V_8 , V_8 -> V_124 - V_8 -> V_123 ) ;
if ( V_8 -> V_134 >= V_8 -> V_58 )
V_8 -> V_134 %= V_8 -> V_58 ;
return V_131 ;
}
unsigned F_58 ( struct V_44 * V_8 , unsigned V_131 )
{
if ( ( int ) ( V_8 -> V_135 + V_131 - V_8 -> V_123 ) >
0 ) {
V_131 = V_8 -> V_123 - V_8 -> V_135 ;
}
V_8 -> V_135 += V_131 ;
F_59 () ;
return V_131 ;
}
unsigned F_60 ( struct V_44 * V_8 , unsigned int V_131 )
{
F_54 () ;
if ( ( int ) ( V_8 -> V_132 + V_131 -
V_8 -> V_135 ) > 0 ) {
F_7 ( V_31
L_13 ) ;
V_131 = V_8 -> V_135 - V_8 -> V_132 ;
}
V_8 -> V_132 += V_131 ;
V_8 -> V_136 += V_131 ;
V_8 -> V_136 %= V_8 -> V_58 ;
return V_131 ;
}
void F_61 ( struct V_44 * V_8 , unsigned int V_73 ,
const void * V_76 , unsigned int V_117 )
{
unsigned int V_137 = V_8 -> V_134 + V_73 ;
if ( V_137 >= V_8 -> V_58 )
V_137 %= V_8 -> V_58 ;
while ( V_117 ) {
unsigned int V_125 ;
if ( V_137 + V_117 > V_8 -> V_58 )
V_125 = V_8 -> V_58 - V_137 ;
else
V_125 = V_117 ;
memcpy ( V_8 -> V_57 + V_137 , V_76 , V_125 ) ;
V_76 += V_125 ;
V_117 -= V_125 ;
V_137 = 0 ;
}
}
void F_62 ( struct V_44 * V_8 , unsigned int V_73 ,
void * V_138 , unsigned int V_131 )
{
void * V_139 ;
unsigned int V_140 = V_8 -> V_136 + V_73 ;
if ( V_140 >= V_8 -> V_58 )
V_140 %= V_8 -> V_58 ;
while ( V_131 ) {
unsigned int V_125 ;
V_139 = V_8 -> V_57 + V_140 ;
if ( V_131 >= V_8 -> V_58 - V_140 )
V_125 = V_8 -> V_58 - V_140 ;
else
V_125 = V_131 ;
memcpy ( V_138 , V_139 , V_125 ) ;
V_131 -= V_125 ;
V_138 += V_125 ;
V_140 = 0 ;
}
}
unsigned int F_63 ( struct V_44 * V_8 )
{
unsigned V_117 ;
if ( V_8 == NULL )
return 0 ;
V_117 = V_8 -> V_123 - V_8 -> V_132 ;
F_59 () ;
return V_117 ;
}
int F_64 ( struct V_44 * V_8 , short * V_141 )
{
unsigned int V_84 = F_63 ( V_8 ) ;
if ( V_84 < sizeof( short ) )
return 0 ;
F_58 ( V_8 , sizeof( short ) ) ;
* V_141 = * ( short * ) ( V_8 -> V_57 + V_8 -> V_136 ) ;
F_60 ( V_8 , sizeof( short ) ) ;
return 1 ;
}
int F_65 ( struct V_44 * V_8 , short V_141 )
{
unsigned int V_84 = F_56 ( V_8 , sizeof( short ) ) ;
if ( V_84 < sizeof( short ) ) {
V_8 -> V_142 |= V_143 ;
return 0 ;
}
* ( short * ) ( V_8 -> V_57 + V_8 -> V_134 ) = V_141 ;
F_57 ( V_8 , sizeof( short ) ) ;
return 1 ;
}
void F_66 ( struct V_44 * V_8 )
{
V_8 -> V_133 = 0 ;
V_8 -> V_124 = 0 ;
V_8 -> V_135 = 0 ;
V_8 -> V_132 = 0 ;
V_8 -> V_134 = 0 ;
V_8 -> V_136 = 0 ;
V_8 -> V_144 = 0 ;
V_8 -> V_145 = 0 ;
V_8 -> V_128 = 0 ;
V_8 -> V_123 = 0 ;
V_8 -> V_127 = 0 ;
V_8 -> V_142 = 0 ;
}
static int F_67 ( struct V_40 * V_146 ,
const char * V_11 , const int * V_147 ,
unsigned V_148 )
{
struct V_22 V_23 ;
int V_149 ;
struct V_38 * V_39 ;
int V_150 ;
unsigned * V_151 = NULL ;
if ( ! V_152 ) {
F_68 ( V_146 , NULL ) ;
return 0 ;
}
V_149 = F_69 ( V_146 ) ;
if ( V_149 < 0 )
return V_149 ;
V_151 = F_70 ( sizeof( unsigned ) , V_52 ) ;
if ( V_151 == NULL ) {
V_150 = - V_53 ;
goto V_153;
}
* V_151 = V_149 ;
F_68 ( V_146 , V_151 ) ;
V_39 = F_18 ( V_149 ) ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
strncpy ( V_23 . V_11 , V_11 , V_154 ) ;
V_23 . V_11 [ V_154 - 1 ] = '\0' ;
F_21 ( V_148 > V_155 ) ;
memcpy ( V_23 . V_147 , V_147 , V_148 * sizeof( int ) ) ;
F_19 ( & V_39 -> V_40 -> V_41 ) ;
V_150 = F_9 ( V_39 -> V_40 , & V_23 ) ;
F_20 ( & V_39 -> V_40 -> V_41 ) ;
V_153:
if ( V_150 < 0 ) {
F_4 ( V_151 ) ;
F_71 ( V_149 ) ;
}
return V_150 ;
}
static void F_72 ( struct V_40 * V_146 )
{
unsigned * V_149 = ( unsigned * ) F_73 ( V_146 ) ;
if ( V_149 == NULL )
return;
F_21 ( * V_149 >= V_37 ) ;
F_71 ( * V_149 ) ;
F_68 ( V_146 , NULL ) ;
F_4 ( V_149 ) ;
}
int F_74 ( struct V_156 * V_157 , const char * V_11 )
{
int V_147 [ 2 ] ;
V_147 [ 0 ] = V_157 -> V_158 -> V_159 ;
V_147 [ 1 ] = F_75 ( V_157 -> V_160 ) ;
return F_67 ( & V_157 -> V_2 , V_11 ,
V_147 , F_76 ( V_147 ) ) ;
}
void F_77 ( struct V_156 * V_157 )
{
F_72 ( & V_157 -> V_2 ) ;
}
int F_78 ( struct V_161 * V_162 , const char * V_11 )
{
F_21 ( V_162 == NULL ) ;
return F_67 ( & V_162 -> V_2 , V_11 , NULL , 0 ) ;
}
void F_79 ( struct V_161 * V_162 )
{
F_21 ( V_162 == NULL ) ;
F_72 ( & V_162 -> V_2 ) ;
}
