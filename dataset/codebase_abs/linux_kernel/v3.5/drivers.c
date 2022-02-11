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
static int F_9 ( struct V_1 * V_2 )
{
int V_22 = F_10 ( V_2 ) ;
F_11 ( V_2 -> V_10 -> V_23 ) ;
if ( V_22 < 0 ) {
F_6 ( V_2 ) ;
return V_22 ;
}
if ( ! V_2 -> V_11 ) {
F_7 ( V_21 L_2 ,
V_2 -> V_11 ) ;
V_2 -> V_11 = L_3 ;
}
F_12 () ;
V_2 -> V_19 = 1 ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_26 * V_27 ;
int V_22 ;
if ( V_2 -> V_19 )
return - V_28 ;
for ( V_27 = V_29 ; V_27 ; V_27 = V_27 -> V_30 ) {
if ( ! F_14 ( V_27 -> V_23 ) ) {
F_7 ( V_31 L_4 ) ;
continue;
}
if ( V_27 -> V_32 ) {
V_2 -> V_12 = F_15 ( V_27 , V_25 -> V_11 ) ;
if ( V_2 -> V_12 )
break;
} else if ( strcmp ( V_27 -> V_33 , V_25 -> V_11 ) )
break;
F_11 ( V_27 -> V_23 ) ;
}
if ( V_27 == NULL ) {
for ( V_27 = V_29 ; V_27 ; V_27 = V_27 -> V_30 ) {
if ( ! F_14 ( V_27 -> V_23 ) ) {
F_7 ( V_31
L_5 ) ;
continue;
}
F_16 ( V_27 ) ;
F_11 ( V_27 -> V_23 ) ;
}
return - V_34 ;
}
V_2 -> V_10 = V_27 ;
V_22 = V_27 -> V_35 ( V_2 , V_25 ) ;
if ( V_22 < 0 ) {
F_11 ( V_2 -> V_10 -> V_23 ) ;
F_6 ( V_2 ) ;
return V_22 ;
}
return F_9 ( V_2 ) ;
}
int F_17 ( struct V_26 * V_10 )
{
V_10 -> V_30 = V_29 ;
V_29 = V_10 ;
return 0 ;
}
int F_18 ( struct V_26 * V_10 )
{
struct V_26 * V_36 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_37 ; V_3 ++ ) {
struct V_38 * V_39 =
F_19 ( V_3 ) ;
struct V_1 * V_2 ;
if ( V_39 == NULL )
continue;
V_2 = V_39 -> V_40 ;
F_20 ( & V_2 -> V_41 ) ;
if ( V_2 -> V_19 && V_2 -> V_10 == V_10 ) {
if ( V_2 -> V_42 )
F_7 ( V_21 L_6 ,
V_2 -> V_42 ) ;
F_8 ( V_2 ) ;
}
F_21 ( & V_2 -> V_41 ) ;
}
if ( V_29 == V_10 ) {
V_29 = V_10 -> V_30 ;
return 0 ;
}
for ( V_36 = V_29 ; V_36 -> V_30 ; V_36 = V_36 -> V_30 ) {
if ( V_36 -> V_30 == V_10 ) {
V_36 -> V_30 = V_10 -> V_30 ;
return 0 ;
}
}
return - V_43 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 ;
struct V_44 * V_8 = NULL ;
int V_22 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_7 ; V_3 ++ ) {
V_5 = V_2 -> V_6 + V_3 ;
if ( V_5 -> type == V_45 )
continue;
if ( V_5 -> V_46 == 0 )
V_5 -> V_46 = 1 ;
if ( V_5 -> V_47 ) {
unsigned int V_48 ;
F_22 ( ( V_5 -> V_49 & ( V_50 |
V_51 ) ) == 0 ) ;
F_22 ( ! V_5 -> V_52 ) ;
V_8 =
F_23 ( sizeof( struct V_44 ) , V_53 ) ;
if ( V_8 == NULL ) {
F_7 ( V_31
L_7 ) ;
return - V_54 ;
}
F_24 ( & V_8 -> V_55 ) ;
V_8 -> V_56 = V_5 ;
V_5 -> V_8 = V_8 ;
V_8 -> V_57 =
V_58 * 1024 ;
V_48 = V_59 * 1024 ;
if ( V_48 > V_8 -> V_57 )
V_48 = V_8 -> V_57 ;
V_8 -> V_60 = NULL ;
V_8 -> V_61 = 0 ;
if ( F_3 ( V_2 , V_5 , V_48 ) < 0 ) {
F_7 ( V_31 L_8 ) ;
return - V_54 ;
}
if ( V_5 -> V_62 ) {
V_22 = V_5 -> V_62 ( V_2 , V_5 , V_48 ) ;
if ( V_22 < 0 )
return V_22 ;
}
F_25 ( V_2 , V_5 ) ;
}
if ( ! V_5 -> V_63 && ! V_5 -> V_64 )
V_5 -> V_63 = & V_65 ;
if ( ! V_5 -> V_66 && V_5 -> V_67 )
V_5 -> V_66 = V_68 ;
if ( ! V_5 -> V_69 && V_5 -> V_67 )
V_5 -> V_69 = V_68 ;
if ( ! V_5 -> V_66 )
V_5 -> V_66 = V_70 ;
if ( ! V_5 -> V_69 )
V_5 -> V_69 = V_70 ;
if ( ! V_5 -> V_67 )
V_5 -> V_67 = V_70 ;
if ( ! V_5 -> V_71 )
V_5 -> V_71 = V_70 ;
if ( ! V_5 -> V_72 )
V_5 -> V_72 = V_73 ;
}
return 0 ;
}
static void * F_15 ( struct V_26 * V_27 , const char * V_74 )
{
unsigned V_3 ;
const char * const * V_75 = V_27 -> V_11 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_32 ; V_3 ++ ) {
if ( strcmp ( * V_75 , V_74 ) == 0 )
return ( void * ) V_75 ;
V_75 =
( const char * const * ) ( ( const char * ) V_75 +
V_27 -> V_76 ) ;
}
return NULL ;
}
static void F_16 ( struct V_26 * V_27 )
{
unsigned int V_3 ;
const char * const * V_75 ;
F_7 ( V_31 L_9 ,
V_27 -> V_33 ) ;
V_75 = V_27 -> V_11 ;
for ( V_3 = 0 ; V_3 < V_27 -> V_32 ; V_3 ++ ) {
F_7 ( V_31 L_10 , * V_75 ) ;
V_75 = ( const char * * ) ( ( char * ) V_75 + V_27 -> V_76 ) ;
}
if ( V_27 -> V_32 == 0 )
F_7 ( V_31 L_10 , V_27 -> V_33 ) ;
}
static int V_73 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
return - V_43 ;
}
int V_70 ( struct V_1 * V_2 , struct V_4 * V_5 ,
struct V_77 * V_78 , unsigned int * V_79 )
{
return - V_43 ;
}
static int V_68 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
struct V_77 * V_78 , unsigned int * V_79 )
{
struct V_77 V_80 ;
int V_22 ;
static const unsigned V_81 = 32 ;
unsigned V_82 = F_26 ( V_78 -> V_83 ) ;
const unsigned V_84 =
( V_82 < V_81 ) ? 0 : V_82 ;
unsigned int V_85 [ 2 ] ;
memset ( V_85 , 0 , sizeof( V_85 ) ) ;
memset ( & V_80 , 0 , sizeof( V_80 ) ) ;
V_80 . V_78 = V_86 ;
V_80 . V_83 = V_84 ;
V_80 . V_87 = 2 ;
V_80 . V_79 = V_85 ;
V_80 . V_88 = V_78 -> V_88 ;
if ( V_78 -> V_78 == V_89 ) {
if ( ! ( V_5 -> V_49 & V_90 ) )
return - V_43 ;
V_85 [ 0 ] = 1 << ( V_82 - V_84 ) ;
V_85 [ 1 ] = V_79 [ 0 ] ? ( 1 << ( V_82 - V_84 ) )
: 0 ;
}
V_22 = V_5 -> V_67 ( V_2 , V_5 , & V_80 , V_85 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_78 -> V_78 == V_91 )
V_79 [ 0 ] = ( V_85 [ 1 ] >> ( V_82 - V_84 ) ) & 1 ;
return 1 ;
}
static inline unsigned long F_27 ( T_1 * V_92 , unsigned long V_93 )
{
unsigned long V_22 = 0UL ;
T_2 * V_94 ;
T_3 * V_95 , V_96 ;
T_4 * V_97 ;
if ( ! F_28 ( * V_92 ) ) {
V_97 = F_29 ( V_92 , V_93 ) ;
V_94 = F_30 ( V_97 , V_93 ) ;
if ( ! F_31 ( * V_94 ) ) {
V_95 = F_32 ( V_94 , V_93 ) ;
V_96 = * V_95 ;
if ( F_33 ( V_96 ) ) {
V_22 = ( unsigned long )
F_34 ( F_35 ( V_96 ) ) ;
V_22 |= ( V_93 & ( V_98 - 1 ) ) ;
}
}
}
return V_22 ;
}
static inline unsigned long F_36 ( unsigned long V_93 )
{
unsigned long V_99 , V_100 ;
V_99 = V_93 ;
V_100 = F_27 ( F_37 ( V_99 ) , V_99 ) ;
return V_100 ;
}
int F_3 ( struct V_1 * V_2 , struct V_4 * V_5 ,
unsigned long V_101 )
{
struct V_44 * V_8 = V_5 -> V_8 ;
V_101 = ( V_101 + V_98 - 1 ) & V_102 ;
if ( V_8 -> V_60 && V_8 -> V_61 == V_101 )
return 0 ;
if ( V_8 -> V_60 ) {
F_38 ( V_8 -> V_60 ) ;
V_8 -> V_60 = NULL ;
V_8 -> V_61 = 0 ;
}
if ( V_8 -> V_103 ) {
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_8 -> V_104 ; ++ V_3 ) {
if ( V_8 -> V_103 [ V_3 ] . V_105 ) {
F_39 ( V_106 ,
& ( F_40 ( V_8 -> V_103 [ V_3 ] .
V_105 ) -> V_107 ) ) ;
if ( V_5 -> V_108 != V_109 ) {
F_41 ( V_2 -> V_110 ,
V_98 ,
V_8 ->
V_103
[ V_3 ] . V_105 ,
V_8 ->
V_103
[ V_3 ] . V_111 ) ;
} else {
F_42 ( ( unsigned long )
V_8 -> V_103 [ V_3 ] .
V_105 ) ;
}
}
}
F_43 ( V_8 -> V_103 ) ;
V_8 -> V_103 = NULL ;
V_8 -> V_104 = 0 ;
}
if ( V_101 ) {
unsigned V_3 = 0 ;
unsigned V_112 = V_101 >> V_113 ;
struct V_114 * * V_115 = NULL ;
V_8 -> V_103 =
F_44 ( sizeof( struct V_116 ) * V_112 ) ;
if ( V_8 -> V_103 )
V_115 = F_45 ( sizeof( struct V_114 * ) * V_112 ) ;
if ( V_115 ) {
for ( V_3 = 0 ; V_3 < V_112 ; V_3 ++ ) {
if ( V_5 -> V_108 != V_109 ) {
V_8 -> V_103 [ V_3 ] . V_105 =
F_46 ( V_2 -> V_110 ,
V_98 ,
& V_8 ->
V_103
[ V_3 ] . V_111 ,
V_53 |
V_117 ) ;
} else {
V_8 -> V_103 [ V_3 ] . V_105 =
( void * )
F_47 ( V_53 ) ;
}
if ( V_8 -> V_103 [ V_3 ] . V_105 == NULL )
break;
F_48 ( V_106 ,
& ( F_40 ( V_8 -> V_103 [ V_3 ] .
V_105 ) -> V_107 ) ) ;
V_115 [ V_3 ] = F_40 ( V_8 -> V_103 [ V_3 ] .
V_105 ) ;
}
}
if ( V_3 == V_112 ) {
V_8 -> V_60 =
#ifdef F_49
F_50 ( V_115 , V_112 , V_118 , F_49 ) ;
#else
F_50 ( V_115 , V_112 , V_118 , V_119 ) ;
#endif
}
F_43 ( V_115 ) ;
if ( V_8 -> V_60 == NULL ) {
if ( V_8 -> V_103 ) {
for ( V_3 = 0 ; V_3 < V_112 ; V_3 ++ ) {
if ( V_8 -> V_103 [ V_3 ] . V_105 ==
NULL ) {
break;
}
F_39 ( V_106 ,
& ( F_40 ( V_8 ->
V_103 [ V_3 ] .
V_105 ) -> V_107 ) ) ;
if ( V_5 -> V_108 != V_109 ) {
F_41 ( V_2 -> V_110 ,
V_98 ,
V_8 ->
V_103
[ V_3 ] . V_105 ,
V_8 ->
V_103
[ V_3 ] . V_111 ) ;
} else {
F_42 ( ( unsigned long )
V_8 -> V_103
[ V_3 ] . V_105 ) ;
}
}
F_43 ( V_8 -> V_103 ) ;
V_8 -> V_103 = NULL ;
}
return - V_54 ;
}
V_8 -> V_104 = V_112 ;
}
V_8 -> V_61 = V_101 ;
return 0 ;
}
static unsigned int F_51 ( struct V_44 * V_8 ,
unsigned int V_120 )
{
struct V_4 * V_5 = V_8 -> V_56 ;
unsigned int V_121 = 0 ;
const unsigned V_122 = F_52 ( V_5 ) ;
if ( V_5 -> V_123 == NULL || ( V_8 -> V_124 . V_107 & V_125 ) ) {
V_8 -> V_126 += V_120 ;
F_22 ( ( int ) ( V_8 -> V_126 - V_8 -> V_127 ) > 0 ) ;
return V_120 ;
}
V_120 -= V_120 % V_122 ;
while ( V_121 < V_120 ) {
int V_128 ;
V_128 = V_120 - V_121 ;
if ( V_128 < 0 ) {
F_7 ( V_21
L_11 ,
__FILE__ , V_129 ) ;
break;
}
if ( ( int ) ( V_8 -> V_130 + V_128 -
V_8 -> V_61 ) > 0 )
V_128 = V_8 -> V_61 - V_8 -> V_130 ;
V_5 -> V_123 ( V_5 -> V_40 , V_5 , V_8 -> V_60 + V_8 -> V_130 ,
V_128 , V_8 -> V_131 ) ;
F_12 () ;
V_8 -> V_131 += V_128 / V_122 ;
V_8 -> V_131 %= V_8 -> V_124 . V_132 ;
V_8 -> V_126 += V_128 ;
V_8 -> V_130 += V_128 ;
V_8 -> V_130 %= V_8 -> V_61 ;
V_121 += V_128 ;
}
F_22 ( ( int ) ( V_8 -> V_126 - V_8 -> V_127 ) > 0 ) ;
return V_121 ;
}
unsigned int F_53 ( struct V_44 * V_8 )
{
unsigned int V_133 ;
unsigned int V_134 ;
if ( V_8 == NULL )
return 0 ;
V_133 = V_8 -> V_135 + V_8 -> V_61 ;
V_134 = V_133 - V_8 -> V_136 ;
V_134 -= V_134 % F_52 ( V_8 -> V_56 ) ;
F_54 () ;
return V_134 ;
}
unsigned int F_55 ( struct V_44 * V_8 ,
unsigned int V_134 )
{
unsigned int V_133 = V_8 -> V_135 + V_8 -> V_61 ;
if ( ( int ) ( V_8 -> V_136 + V_134 - V_133 ) > 0 )
V_134 = V_133 - V_8 -> V_136 ;
V_8 -> V_136 += V_134 ;
F_54 () ;
return V_134 ;
}
unsigned int F_56 ( struct V_44 * V_8 ,
unsigned int V_134 )
{
unsigned int V_133 = V_8 -> V_135 + V_8 -> V_61 ;
if ( ( int ) ( V_8 -> V_136 + V_134 - V_133 ) > 0 )
V_134 = 0 ;
V_8 -> V_136 += V_134 ;
F_54 () ;
return V_134 ;
}
unsigned F_57 ( struct V_44 * V_8 , unsigned int V_134 )
{
if ( ( int ) ( V_8 -> V_127 + V_134 -
V_8 -> V_136 ) > 0 ) {
F_7 ( V_31 L_12 ) ;
V_134 = V_8 -> V_136 - V_8 -> V_127 ;
}
V_8 -> V_127 += V_134 ;
V_8 -> V_137 += V_134 ;
F_51 ( V_8 , V_8 -> V_127 - V_8 -> V_126 ) ;
if ( V_8 -> V_137 >= V_8 -> V_61 )
V_8 -> V_137 %= V_8 -> V_61 ;
return V_134 ;
}
unsigned F_58 ( struct V_44 * V_8 , unsigned V_134 )
{
if ( ( int ) ( V_8 -> V_138 + V_134 - V_8 -> V_126 ) >
0 ) {
V_134 = V_8 -> V_126 - V_8 -> V_138 ;
}
V_8 -> V_138 += V_134 ;
F_59 () ;
return V_134 ;
}
unsigned F_60 ( struct V_44 * V_8 , unsigned int V_134 )
{
F_54 () ;
if ( ( int ) ( V_8 -> V_135 + V_134 -
V_8 -> V_138 ) > 0 ) {
F_7 ( V_31
L_13 ) ;
V_134 = V_8 -> V_138 - V_8 -> V_135 ;
}
V_8 -> V_135 += V_134 ;
V_8 -> V_139 += V_134 ;
V_8 -> V_139 %= V_8 -> V_61 ;
return V_134 ;
}
void F_61 ( struct V_44 * V_8 , unsigned int V_76 ,
const void * V_79 , unsigned int V_120 )
{
unsigned int V_140 = V_8 -> V_137 + V_76 ;
if ( V_140 >= V_8 -> V_61 )
V_140 %= V_8 -> V_61 ;
while ( V_120 ) {
unsigned int V_128 ;
if ( V_140 + V_120 > V_8 -> V_61 )
V_128 = V_8 -> V_61 - V_140 ;
else
V_128 = V_120 ;
memcpy ( V_8 -> V_60 + V_140 , V_79 , V_128 ) ;
V_79 += V_128 ;
V_120 -= V_128 ;
V_140 = 0 ;
}
}
void F_62 ( struct V_44 * V_8 , unsigned int V_76 ,
void * V_141 , unsigned int V_134 )
{
void * V_142 ;
unsigned int V_143 = V_8 -> V_139 + V_76 ;
if ( V_143 >= V_8 -> V_61 )
V_143 %= V_8 -> V_61 ;
while ( V_134 ) {
unsigned int V_128 ;
V_142 = V_8 -> V_60 + V_143 ;
if ( V_134 >= V_8 -> V_61 - V_143 )
V_128 = V_8 -> V_61 - V_143 ;
else
V_128 = V_134 ;
memcpy ( V_141 , V_142 , V_128 ) ;
V_134 -= V_128 ;
V_141 += V_128 ;
V_143 = 0 ;
}
}
unsigned int F_63 ( struct V_44 * V_8 )
{
unsigned V_120 ;
if ( V_8 == NULL )
return 0 ;
V_120 = V_8 -> V_126 - V_8 -> V_135 ;
F_59 () ;
return V_120 ;
}
int F_64 ( struct V_44 * V_8 , short * V_144 )
{
unsigned int V_87 = F_63 ( V_8 ) ;
if ( V_87 < sizeof( short ) )
return 0 ;
F_58 ( V_8 , sizeof( short ) ) ;
* V_144 = * ( short * ) ( V_8 -> V_60 + V_8 -> V_139 ) ;
F_60 ( V_8 , sizeof( short ) ) ;
return 1 ;
}
int F_65 ( struct V_44 * V_8 , short V_144 )
{
unsigned int V_87 = F_56 ( V_8 , sizeof( short ) ) ;
if ( V_87 < sizeof( short ) ) {
V_8 -> V_145 |= V_146 ;
return 0 ;
}
* ( short * ) ( V_8 -> V_60 + V_8 -> V_137 ) = V_144 ;
F_57 ( V_8 , sizeof( short ) ) ;
return 1 ;
}
void F_66 ( struct V_44 * V_8 )
{
V_8 -> V_136 = 0 ;
V_8 -> V_127 = 0 ;
V_8 -> V_138 = 0 ;
V_8 -> V_135 = 0 ;
V_8 -> V_137 = 0 ;
V_8 -> V_139 = 0 ;
V_8 -> V_147 = 0 ;
V_8 -> V_148 = 0 ;
V_8 -> V_131 = 0 ;
V_8 -> V_126 = 0 ;
V_8 -> V_130 = 0 ;
V_8 -> V_145 = 0 ;
}
static int
F_67 ( struct V_40 * V_149 ,
struct V_26 * V_10 ,
int (* F_68) ( struct V_1 * ,
void * ) , void * V_150 )
{
int V_151 ;
struct V_38 * V_39 ;
struct V_1 * V_152 ;
int V_22 ;
if ( ! V_153 )
return 0 ;
V_151 = F_69 ( V_149 ) ;
if ( V_151 < 0 )
return V_151 ;
V_39 = F_19 ( V_151 ) ;
V_152 = V_39 -> V_40 ;
F_20 ( & V_152 -> V_41 ) ;
if ( V_152 -> V_19 )
V_22 = - V_28 ;
else if ( ! F_14 ( V_10 -> V_23 ) ) {
F_7 ( V_31 L_5 ) ;
V_22 = - V_34 ;
} else {
V_152 -> V_10 = V_10 ;
V_22 = (* F_68)( V_152 , V_150 ) ;
if ( V_22 < 0 ) {
F_11 ( V_10 -> V_23 ) ;
F_6 ( V_152 ) ;
} else {
V_22 = F_9 ( V_152 ) ;
}
}
F_21 ( & V_152 -> V_41 ) ;
if ( V_22 < 0 )
F_70 ( V_151 ) ;
return V_22 ;
}
static int F_71 ( struct V_1 * V_2 , void * V_150 )
{
struct V_24 * V_25 = V_150 ;
struct V_26 * V_27 = V_2 -> V_10 ;
if ( V_27 -> V_32 ) {
V_2 -> V_12 = F_15 ( V_27 , V_25 -> V_11 ) ;
if ( V_2 -> V_12 == NULL ) {
F_7 ( V_21
L_14
L_15 , V_25 -> V_11 ,
V_27 -> V_33 ) ;
F_16 ( V_27 ) ;
return - V_43 ;
}
}
return V_27 -> V_35 ( V_2 , V_25 ) ;
}
static int F_72 ( struct V_40 * V_149 ,
struct V_26 * V_10 , const int * V_154 ,
unsigned V_155 )
{
struct V_24 V_25 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
strncpy ( V_25 . V_11 , V_10 -> V_33 , V_156 ) ;
V_25 . V_11 [ V_156 - 1 ] = '\0' ;
F_22 ( V_155 > V_157 ) ;
memcpy ( V_25 . V_154 , V_154 , V_155 * sizeof( int ) ) ;
return F_67 ( V_149 , V_10 ,
F_71 , & V_25 ) ;
}
static void F_73 ( struct V_40 * V_149 )
{
int V_151 ;
if ( V_149 == NULL )
return;
V_151 = F_74 ( V_149 ) ;
if ( V_151 < 0 )
return;
F_22 ( V_151 >= V_37 ) ;
F_70 ( V_151 ) ;
}
static int F_75 ( struct V_158 * V_159 ,
struct V_26 * V_10 )
{
int V_154 [ 2 ] ;
V_154 [ 0 ] = V_159 -> V_160 -> V_161 ;
V_154 [ 1 ] = F_76 ( V_159 -> V_162 ) ;
return F_72 ( & V_159 -> V_2 , V_10 ,
V_154 , F_77 ( V_154 ) ) ;
}
static int F_78 ( struct V_1 * V_2 , void * V_159 )
{
return V_2 -> V_10 -> V_163 ( V_2 , V_159 ) ;
}
static int F_79 ( struct V_158 * V_159 ,
struct V_26 * V_10 )
{
return F_67 ( & V_159 -> V_2 , V_10 ,
F_78 , V_159 ) ;
}
int F_80 ( struct V_158 * V_159 , struct V_26 * V_10 )
{
if ( V_10 -> V_163 )
return F_79 ( V_159 , V_10 ) ;
else
return F_75 ( V_159 , V_10 ) ;
}
void F_81 ( struct V_158 * V_159 )
{
F_73 ( & V_159 -> V_2 ) ;
}
int F_82 ( struct V_26 * V_26 ,
struct V_164 * V_164 )
{
int V_22 ;
V_22 = F_17 ( V_26 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( ! V_164 -> V_74 )
V_164 -> V_74 = V_26 -> V_33 ;
V_22 = F_83 ( V_164 ) ;
if ( V_22 < 0 ) {
F_18 ( V_26 ) ;
return V_22 ;
}
return 0 ;
}
void F_84 ( struct V_26 * V_26 ,
struct V_164 * V_164 )
{
F_85 ( V_164 ) ;
F_18 ( V_26 ) ;
}
static int F_86 ( struct V_165 * V_166 ,
struct V_26 * V_10 )
{
return F_72 ( & V_166 -> V_2 , V_10 , NULL , 0 ) ;
}
static int F_87 ( struct V_1 * V_2 , void * V_166 )
{
return V_2 -> V_10 -> V_167 ( V_2 , V_166 ) ;
}
static int F_88 ( struct V_165 * V_166 ,
struct V_26 * V_10 )
{
return F_67 ( & V_166 -> V_2 , V_10 ,
F_87 , V_166 ) ;
}
int F_89 ( struct V_165 * V_166 ,
struct V_26 * V_10 )
{
F_22 ( V_166 == NULL ) ;
if ( V_10 -> V_167 )
return F_88 ( V_166 , V_10 ) ;
else
return F_86 ( V_166 , V_10 ) ;
}
void F_90 ( struct V_165 * V_166 )
{
F_22 ( V_166 == NULL ) ;
F_73 ( & V_166 -> V_2 ) ;
}
int F_91 ( struct V_26 * V_26 ,
struct V_168 * V_168 )
{
int V_22 ;
V_22 = F_17 ( V_26 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_92 ( V_168 ) ;
if ( V_22 < 0 ) {
F_18 ( V_26 ) ;
return V_22 ;
}
return 0 ;
}
void F_93 ( struct V_26 * V_26 ,
struct V_168 * V_168 )
{
F_94 ( V_168 ) ;
F_18 ( V_26 ) ;
}
