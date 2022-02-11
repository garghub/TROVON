int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
if ( V_3 < 1 )
return - V_7 ;
V_5 = F_2 ( V_3 , sizeof( * V_5 ) , V_8 ) ;
if ( ! V_5 )
return - V_9 ;
V_2 -> V_10 = V_5 ;
V_2 -> V_11 = V_3 ;
for ( V_6 = 0 ; V_6 < V_3 ; ++ V_6 ) {
V_5 = & V_2 -> V_10 [ V_6 ] ;
V_5 -> V_12 = V_2 ;
V_5 -> V_13 = V_14 ;
F_3 ( & V_5 -> V_15 ) ;
V_5 -> V_16 = - 1 ;
}
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_6 ;
struct V_4 * V_5 ;
if ( V_2 -> V_10 ) {
for ( V_6 = 0 ; V_6 < V_2 -> V_11 ; V_6 ++ ) {
V_5 = & V_2 -> V_10 [ V_6 ] ;
F_5 ( V_5 ) ;
if ( V_5 -> V_17 ) {
F_6 ( V_2 , V_5 , 0 ) ;
F_7 ( V_5 -> V_17 ) ;
}
}
F_7 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
V_2 -> V_11 = 0 ;
}
F_7 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
V_2 -> V_19 = NULL ;
V_2 -> V_20 = NULL ;
V_2 -> V_21 = NULL ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 = 0 ;
V_2 -> V_24 = NULL ;
V_2 -> V_25 = NULL ;
V_2 -> V_26 = NULL ;
V_2 -> V_27 = NULL ;
F_8 ( V_2 , NULL ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_28 = 0 ;
if ( V_2 -> V_19 )
V_2 -> V_19 -> V_29 ( V_2 ) ;
else
F_10 ( V_2 -> V_30 ,
L_1 ) ;
F_4 ( V_2 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_28 )
return;
F_9 ( V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_31 = F_13 ( V_2 ) ;
F_14 ( V_2 -> V_19 -> V_32 ) ;
if ( V_31 < 0 ) {
F_9 ( V_2 ) ;
return V_31 ;
}
if ( ! V_2 -> V_20 ) {
F_10 ( V_2 -> V_30 , L_2 ) ;
V_2 -> V_20 = L_3 ;
}
F_15 () ;
V_2 -> V_28 = 1 ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_35 * V_36 ;
int V_31 ;
if ( V_2 -> V_28 )
return - V_37 ;
for ( V_36 = V_38 ; V_36 ; V_36 = V_36 -> V_39 ) {
if ( ! F_17 ( V_36 -> V_32 ) )
continue;
if ( V_36 -> V_40 ) {
V_2 -> V_21 = F_18 ( V_36 , V_34 -> V_20 ) ;
if ( V_2 -> V_21 )
break;
} else if ( strcmp ( V_36 -> V_41 , V_34 -> V_20 ) == 0 )
break;
F_14 ( V_36 -> V_32 ) ;
}
if ( V_36 == NULL ) {
for ( V_36 = V_38 ; V_36 ; V_36 = V_36 -> V_39 ) {
if ( ! F_17 ( V_36 -> V_32 ) )
continue;
F_19 ( V_36 ) ;
F_14 ( V_36 -> V_32 ) ;
}
return - V_42 ;
}
if ( V_36 -> V_43 == NULL ) {
F_10 ( V_2 -> V_30 ,
L_4 ,
V_36 -> V_41 ) ;
F_14 ( V_36 -> V_32 ) ;
return - V_44 ;
}
V_2 -> V_19 = V_36 ;
V_31 = V_36 -> V_43 ( V_2 , V_34 ) ;
if ( V_31 < 0 ) {
F_14 ( V_2 -> V_19 -> V_32 ) ;
F_9 ( V_2 ) ;
return V_31 ;
}
return F_12 ( V_2 ) ;
}
int F_20 ( struct V_35 * V_19 )
{
V_19 -> V_39 = V_38 ;
V_38 = V_19 ;
return 0 ;
}
int F_21 ( struct V_35 * V_19 )
{
struct V_35 * V_45 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_46 ; V_6 ++ ) {
struct V_47 * V_48 =
F_22 ( V_6 ) ;
struct V_1 * V_2 ;
if ( V_48 == NULL )
continue;
V_2 = V_48 -> V_12 ;
F_23 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_28 && V_2 -> V_19 == V_19 ) {
if ( V_2 -> V_50 )
F_10 ( V_2 -> V_30 ,
L_5 ,
V_2 -> V_50 ) ;
F_11 ( V_2 ) ;
}
F_24 ( & V_2 -> V_49 ) ;
}
if ( V_38 == V_19 ) {
V_38 = V_19 -> V_39 ;
return 0 ;
}
for ( V_45 = V_38 ; V_45 -> V_39 ; V_45 = V_45 -> V_39 ) {
if ( V_45 -> V_39 == V_19 ) {
V_45 -> V_39 = V_19 -> V_39 ;
return 0 ;
}
}
return - V_7 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_6 ;
struct V_4 * V_5 ;
struct V_51 * V_17 = NULL ;
int V_31 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_11 ; V_6 ++ ) {
V_5 = & V_2 -> V_10 [ V_6 ] ;
if ( V_5 -> type == V_52 )
continue;
if ( V_5 -> V_53 == 0 )
V_5 -> V_53 = 1 ;
if ( V_5 -> V_54 ) {
unsigned int V_55 ;
F_25 ( ( V_5 -> V_56 & ( V_57 |
V_58 ) ) == 0 ) ;
F_25 ( ! V_5 -> V_59 ) ;
V_17 =
F_26 ( sizeof( struct V_51 ) , V_8 ) ;
if ( V_17 == NULL ) {
F_10 ( V_2 -> V_30 ,
L_6 ) ;
return - V_9 ;
}
F_27 ( & V_17 -> V_60 ) ;
V_17 -> V_61 = V_5 ;
V_5 -> V_17 = V_17 ;
V_17 -> V_62 =
V_63 * 1024 ;
V_55 = V_64 * 1024 ;
if ( V_55 > V_17 -> V_62 )
V_55 = V_17 -> V_62 ;
V_17 -> V_65 = NULL ;
V_17 -> V_66 = 0 ;
if ( F_6 ( V_2 , V_5 , V_55 ) < 0 ) {
F_10 ( V_2 -> V_30 ,
L_7 ) ;
return - V_9 ;
}
if ( V_5 -> V_67 ) {
V_31 = V_5 -> V_67 ( V_2 , V_5 , V_55 ) ;
if ( V_31 < 0 )
return V_31 ;
}
F_28 ( V_2 , V_5 ) ;
}
if ( ! V_5 -> V_68 && ! V_5 -> V_69 )
V_5 -> V_68 = & V_70 ;
if ( ! V_5 -> V_71 && V_5 -> V_72 )
V_5 -> V_71 = V_73 ;
if ( ! V_5 -> V_74 && V_5 -> V_72 )
V_5 -> V_74 = V_73 ;
if ( ! V_5 -> V_71 )
V_5 -> V_71 = V_75 ;
if ( ! V_5 -> V_74 )
V_5 -> V_74 = V_75 ;
if ( ! V_5 -> V_72 )
V_5 -> V_72 = V_75 ;
if ( ! V_5 -> V_76 )
V_5 -> V_76 = V_75 ;
if ( ! V_5 -> V_77 )
V_5 -> V_77 = V_78 ;
}
return 0 ;
}
static void * F_18 ( struct V_35 * V_36 , const char * V_79 )
{
char * * V_80 = ( char * * ) V_36 -> V_20 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_36 -> V_40 ; V_6 ++ ) {
if ( strcmp ( * V_80 , V_79 ) == 0 )
return V_80 ;
V_80 = ( void * ) V_80 + V_36 -> V_81 ;
}
return NULL ;
}
static void F_19 ( struct V_35 * V_36 )
{
unsigned int V_6 ;
const char * const * V_80 ;
F_29 ( L_8 ,
V_36 -> V_41 ) ;
V_80 = V_36 -> V_20 ;
for ( V_6 = 0 ; V_6 < V_36 -> V_40 ; V_6 ++ ) {
F_29 ( L_9 , * V_80 ) ;
V_80 = ( const char * * ) ( ( char * ) V_80 + V_36 -> V_81 ) ;
}
if ( V_36 -> V_40 == 0 )
F_29 ( L_9 , V_36 -> V_41 ) ;
}
static int V_78 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
return - V_7 ;
}
int V_75 ( struct V_1 * V_2 , struct V_4 * V_5 ,
struct V_82 * V_83 , unsigned int * V_84 )
{
return - V_7 ;
}
static int V_73 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
struct V_82 * V_83 , unsigned int * V_84 )
{
struct V_82 V_85 ;
int V_31 ;
static const unsigned V_86 = 32 ;
unsigned V_87 = F_30 ( V_83 -> V_88 ) ;
const unsigned V_89 =
( V_87 < V_86 ) ? 0 : V_87 ;
unsigned int V_90 [ 2 ] ;
memset ( V_90 , 0 , sizeof( V_90 ) ) ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . V_83 = V_91 ;
V_85 . V_88 = V_89 ;
V_85 . V_92 = 2 ;
V_85 . V_93 = V_83 -> V_93 ;
if ( V_83 -> V_83 == V_94 ) {
if ( ! ( V_5 -> V_56 & V_95 ) )
return - V_7 ;
V_90 [ 0 ] = 1 << ( V_87 - V_89 ) ;
V_90 [ 1 ] = V_84 [ 0 ] ? ( 1 << ( V_87 - V_89 ) )
: 0 ;
}
V_31 = V_5 -> V_72 ( V_2 , V_5 , & V_85 , V_90 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( V_83 -> V_83 == V_96 )
V_84 [ 0 ] = ( V_90 [ 1 ] >> ( V_87 - V_89 ) ) & 1 ;
return 1 ;
}
int F_6 ( struct V_1 * V_2 , struct V_4 * V_5 ,
unsigned long V_97 )
{
struct V_51 * V_17 = V_5 -> V_17 ;
V_97 = ( V_97 + V_98 - 1 ) & V_99 ;
if ( V_17 -> V_65 && V_17 -> V_66 == V_97 )
return 0 ;
if ( V_17 -> V_65 ) {
F_31 ( V_17 -> V_65 ) ;
V_17 -> V_65 = NULL ;
V_17 -> V_66 = 0 ;
}
if ( V_17 -> V_100 ) {
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_17 -> V_101 ; ++ V_6 ) {
if ( V_17 -> V_100 [ V_6 ] . V_102 ) {
F_32 ( V_103 ,
& ( F_33 ( V_17 -> V_100 [ V_6 ] .
V_102 ) -> V_104 ) ) ;
if ( V_5 -> V_13 != V_14 ) {
F_34 ( V_2 -> V_105 ,
V_98 ,
V_17 ->
V_100
[ V_6 ] . V_102 ,
V_17 ->
V_100
[ V_6 ] . V_106 ) ;
} else {
F_35 ( ( unsigned long )
V_17 -> V_100 [ V_6 ] .
V_102 ) ;
}
}
}
F_36 ( V_17 -> V_100 ) ;
V_17 -> V_100 = NULL ;
V_17 -> V_101 = 0 ;
}
if ( V_97 ) {
unsigned V_6 = 0 ;
unsigned V_107 = V_97 >> V_108 ;
struct V_109 * * V_110 = NULL ;
V_17 -> V_100 =
F_37 ( sizeof( struct V_111 ) * V_107 ) ;
if ( V_17 -> V_100 )
V_110 = F_38 ( sizeof( struct V_109 * ) * V_107 ) ;
if ( V_110 ) {
for ( V_6 = 0 ; V_6 < V_107 ; V_6 ++ ) {
if ( V_5 -> V_13 != V_14 ) {
V_17 -> V_100 [ V_6 ] . V_102 =
F_39 ( V_2 -> V_105 ,
V_98 ,
& V_17 ->
V_100
[ V_6 ] . V_106 ,
V_8 |
V_112 ) ;
} else {
V_17 -> V_100 [ V_6 ] . V_102 =
( void * )
F_40 ( V_8 ) ;
}
if ( V_17 -> V_100 [ V_6 ] . V_102 == NULL )
break;
F_41 ( V_103 ,
& ( F_33 ( V_17 -> V_100 [ V_6 ] .
V_102 ) -> V_104 ) ) ;
V_110 [ V_6 ] = F_33 ( V_17 -> V_100 [ V_6 ] .
V_102 ) ;
}
}
if ( V_6 == V_107 ) {
V_17 -> V_65 =
#ifdef F_42
F_43 ( V_110 , V_107 , V_113 , F_42 ) ;
#else
F_43 ( V_110 , V_107 , V_113 , V_114 ) ;
#endif
}
F_36 ( V_110 ) ;
if ( V_17 -> V_65 == NULL ) {
if ( V_17 -> V_100 ) {
for ( V_6 = 0 ; V_6 < V_107 ; V_6 ++ ) {
if ( V_17 -> V_100 [ V_6 ] . V_102 ==
NULL ) {
break;
}
F_32 ( V_103 ,
& ( F_33 ( V_17 ->
V_100 [ V_6 ] .
V_102 ) -> V_104 ) ) ;
if ( V_5 -> V_13 != V_14 ) {
F_34 ( V_2 -> V_105 ,
V_98 ,
V_17 ->
V_100
[ V_6 ] . V_102 ,
V_17 ->
V_100
[ V_6 ] . V_106 ) ;
} else {
F_35 ( ( unsigned long )
V_17 -> V_100
[ V_6 ] . V_102 ) ;
}
}
F_36 ( V_17 -> V_100 ) ;
V_17 -> V_100 = NULL ;
}
return - V_9 ;
}
V_17 -> V_101 = V_107 ;
}
V_17 -> V_66 = V_97 ;
return 0 ;
}
static unsigned int F_44 ( struct V_51 * V_17 ,
unsigned int V_115 )
{
struct V_4 * V_5 = V_17 -> V_61 ;
unsigned int V_116 = 0 ;
const unsigned V_117 = F_45 ( V_5 ) ;
if ( V_5 -> V_118 == NULL || ( V_17 -> V_119 . V_104 & V_120 ) ) {
V_17 -> V_121 += V_115 ;
F_25 ( ( int ) ( V_17 -> V_121 - V_17 -> V_122 ) > 0 ) ;
return V_115 ;
}
V_115 -= V_115 % V_117 ;
while ( V_116 < V_115 ) {
int V_123 ;
V_123 = V_115 - V_116 ;
if ( V_123 < 0 ) {
F_10 ( V_5 -> V_12 -> V_30 ,
L_10 ,
__FILE__ , V_124 ) ;
break;
}
if ( ( int ) ( V_17 -> V_125 + V_123 -
V_17 -> V_66 ) > 0 )
V_123 = V_17 -> V_66 - V_17 -> V_125 ;
V_5 -> V_118 ( V_5 -> V_12 , V_5 , V_17 -> V_65 + V_17 -> V_125 ,
V_123 , V_17 -> V_126 ) ;
F_15 () ;
V_17 -> V_126 += V_123 / V_117 ;
V_17 -> V_126 %= V_17 -> V_119 . V_127 ;
V_17 -> V_121 += V_123 ;
V_17 -> V_125 += V_123 ;
V_17 -> V_125 %= V_17 -> V_66 ;
V_116 += V_123 ;
}
F_25 ( ( int ) ( V_17 -> V_121 - V_17 -> V_122 ) > 0 ) ;
return V_116 ;
}
unsigned int F_46 ( struct V_51 * V_17 )
{
unsigned int V_128 ;
unsigned int V_129 ;
if ( V_17 == NULL )
return 0 ;
V_128 = V_17 -> V_130 + V_17 -> V_66 ;
V_129 = V_128 - V_17 -> V_131 ;
V_129 -= V_129 % F_45 ( V_17 -> V_61 ) ;
F_47 () ;
return V_129 ;
}
unsigned int F_48 ( struct V_51 * V_17 ,
unsigned int V_129 )
{
unsigned int V_128 = V_17 -> V_130 + V_17 -> V_66 ;
if ( ( int ) ( V_17 -> V_131 + V_129 - V_128 ) > 0 )
V_129 = V_128 - V_17 -> V_131 ;
V_17 -> V_131 += V_129 ;
F_47 () ;
return V_129 ;
}
unsigned int F_49 ( struct V_51 * V_17 ,
unsigned int V_129 )
{
unsigned int V_128 = V_17 -> V_130 + V_17 -> V_66 ;
if ( ( int ) ( V_17 -> V_131 + V_129 - V_128 ) > 0 )
V_129 = 0 ;
V_17 -> V_131 += V_129 ;
F_47 () ;
return V_129 ;
}
unsigned F_50 ( struct V_51 * V_17 , unsigned int V_129 )
{
if ( ( int ) ( V_17 -> V_122 + V_129 -
V_17 -> V_131 ) > 0 ) {
F_51 ( V_17 -> V_61 -> V_12 -> V_30 ,
L_11 ) ;
V_129 = V_17 -> V_131 - V_17 -> V_122 ;
}
V_17 -> V_122 += V_129 ;
V_17 -> V_132 += V_129 ;
F_44 ( V_17 , V_17 -> V_122 - V_17 -> V_121 ) ;
if ( V_17 -> V_132 >= V_17 -> V_66 )
V_17 -> V_132 %= V_17 -> V_66 ;
return V_129 ;
}
unsigned F_52 ( struct V_51 * V_17 , unsigned V_129 )
{
if ( ( int ) ( V_17 -> V_133 + V_129 - V_17 -> V_121 ) >
0 ) {
V_129 = V_17 -> V_121 - V_17 -> V_133 ;
}
V_17 -> V_133 += V_129 ;
F_53 () ;
return V_129 ;
}
unsigned F_54 ( struct V_51 * V_17 , unsigned int V_129 )
{
F_47 () ;
if ( ( int ) ( V_17 -> V_130 + V_129 -
V_17 -> V_133 ) > 0 ) {
F_51 ( V_17 -> V_61 -> V_12 -> V_30 ,
L_12 ) ;
V_129 = V_17 -> V_133 - V_17 -> V_130 ;
}
V_17 -> V_130 += V_129 ;
V_17 -> V_134 += V_129 ;
V_17 -> V_134 %= V_17 -> V_66 ;
return V_129 ;
}
void F_55 ( struct V_51 * V_17 , unsigned int V_81 ,
const void * V_84 , unsigned int V_115 )
{
unsigned int V_135 = V_17 -> V_132 + V_81 ;
if ( V_135 >= V_17 -> V_66 )
V_135 %= V_17 -> V_66 ;
while ( V_115 ) {
unsigned int V_123 ;
if ( V_135 + V_115 > V_17 -> V_66 )
V_123 = V_17 -> V_66 - V_135 ;
else
V_123 = V_115 ;
memcpy ( V_17 -> V_65 + V_135 , V_84 , V_123 ) ;
V_84 += V_123 ;
V_115 -= V_123 ;
V_135 = 0 ;
}
}
void F_56 ( struct V_51 * V_17 , unsigned int V_81 ,
void * V_136 , unsigned int V_129 )
{
void * V_137 ;
unsigned int V_138 = V_17 -> V_134 + V_81 ;
if ( V_138 >= V_17 -> V_66 )
V_138 %= V_17 -> V_66 ;
while ( V_129 ) {
unsigned int V_123 ;
V_137 = V_17 -> V_65 + V_138 ;
if ( V_129 >= V_17 -> V_66 - V_138 )
V_123 = V_17 -> V_66 - V_138 ;
else
V_123 = V_129 ;
memcpy ( V_136 , V_137 , V_123 ) ;
V_129 -= V_123 ;
V_136 += V_123 ;
V_138 = 0 ;
}
}
unsigned int F_57 ( struct V_51 * V_17 )
{
unsigned V_115 ;
if ( V_17 == NULL )
return 0 ;
V_115 = V_17 -> V_121 - V_17 -> V_130 ;
F_53 () ;
return V_115 ;
}
int F_58 ( struct V_51 * V_17 , short * V_139 )
{
unsigned int V_92 = F_57 ( V_17 ) ;
if ( V_92 < sizeof( short ) )
return 0 ;
F_52 ( V_17 , sizeof( short ) ) ;
* V_139 = * ( short * ) ( V_17 -> V_65 + V_17 -> V_134 ) ;
F_54 ( V_17 , sizeof( short ) ) ;
return 1 ;
}
int F_59 ( struct V_51 * V_17 , short V_139 )
{
unsigned int V_92 = F_49 ( V_17 , sizeof( short ) ) ;
if ( V_92 < sizeof( short ) ) {
V_17 -> V_140 |= V_141 ;
return 0 ;
}
* ( short * ) ( V_17 -> V_65 + V_17 -> V_132 ) = V_139 ;
F_50 ( V_17 , sizeof( short ) ) ;
return 1 ;
}
void F_60 ( struct V_51 * V_17 )
{
V_17 -> V_131 = 0 ;
V_17 -> V_122 = 0 ;
V_17 -> V_133 = 0 ;
V_17 -> V_130 = 0 ;
V_17 -> V_132 = 0 ;
V_17 -> V_134 = 0 ;
V_17 -> V_142 = 0 ;
V_17 -> V_143 = 0 ;
V_17 -> V_126 = 0 ;
V_17 -> V_121 = 0 ;
V_17 -> V_125 = 0 ;
V_17 -> V_140 = 0 ;
}
int F_61 ( struct V_12 * V_144 ,
struct V_35 * V_19 , unsigned long V_145 )
{
int V_16 ;
struct V_47 * V_48 ;
struct V_1 * V_146 ;
int V_31 ;
if ( ! V_147 )
return 0 ;
if ( ! V_19 -> V_148 ) {
F_10 ( V_144 ,
L_13 ,
V_19 -> V_41 ) ;
return - V_7 ;
}
V_16 = F_62 ( V_144 ) ;
if ( V_16 < 0 )
return V_16 ;
V_48 = F_22 ( V_16 ) ;
V_146 = V_48 -> V_12 ;
F_23 ( & V_146 -> V_49 ) ;
if ( V_146 -> V_28 )
V_31 = - V_37 ;
else if ( ! F_17 ( V_19 -> V_32 ) )
V_31 = - V_42 ;
else {
F_8 ( V_146 , V_144 ) ;
V_146 -> V_19 = V_19 ;
V_31 = V_19 -> V_148 ( V_146 , V_145 ) ;
if ( V_31 < 0 ) {
F_14 ( V_19 -> V_32 ) ;
F_9 ( V_146 ) ;
} else {
V_31 = F_12 ( V_146 ) ;
}
}
F_24 ( & V_146 -> V_49 ) ;
if ( V_31 < 0 )
F_63 ( V_16 ) ;
return V_31 ;
}
void F_64 ( struct V_12 * V_144 )
{
int V_16 ;
if ( V_144 == NULL )
return;
V_16 = F_65 ( V_144 ) ;
if ( V_16 < 0 )
return;
F_25 ( V_16 >= V_46 ) ;
F_63 ( V_16 ) ;
}
int F_66 ( struct V_149 * V_150 , const char * V_151 )
{
int V_152 ;
V_152 = F_67 ( V_150 ) ;
if ( V_152 < 0 )
return V_152 ;
V_152 = F_68 ( V_150 , V_151 ) ;
if ( V_152 < 0 )
F_69 ( V_150 ) ;
return V_152 ;
}
void F_70 ( struct V_149 * V_150 )
{
F_71 ( V_150 ) ;
F_69 ( V_150 ) ;
}
int F_72 ( struct V_35 * V_35 ,
struct V_153 * V_153 )
{
int V_31 ;
V_31 = F_20 ( V_35 ) ;
if ( V_31 < 0 )
return V_31 ;
if ( ! V_153 -> V_79 )
V_153 -> V_79 = V_35 -> V_41 ;
V_31 = F_73 ( V_153 ) ;
if ( V_31 < 0 ) {
F_21 ( V_35 ) ;
return V_31 ;
}
return 0 ;
}
void F_74 ( struct V_35 * V_35 ,
struct V_153 * V_153 )
{
F_75 ( V_153 ) ;
F_21 ( V_35 ) ;
}
int F_76 ( struct V_35 * V_35 ,
struct V_154 * V_154 )
{
int V_31 ;
V_31 = F_20 ( V_35 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_77 ( V_154 ) ;
if ( V_31 < 0 ) {
F_21 ( V_35 ) ;
return V_31 ;
}
return 0 ;
}
void F_78 ( struct V_35 * V_35 ,
struct V_154 * V_154 )
{
F_79 ( V_154 ) ;
F_21 ( V_35 ) ;
}
