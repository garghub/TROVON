static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( L_1 , V_4 ,
0 , 0 , NULL ) ;
return V_2 -> V_3 ? 0 : 1 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 ) ;
}
static unsigned long F_5 ( struct V_1 * V_2 )
{
return ( unsigned long ) F_6 ( V_2 -> V_3 ,
V_2 -> V_5 & ~ V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned long V_7 )
{
F_8 ( V_2 -> V_3 , ( void * ) V_7 ) ;
}
static void F_9 ( unsigned long V_7 , unsigned long V_8 )
{
* ( unsigned long * ) V_7 = V_8 ;
}
static void * F_10 ( const char * V_9 , T_1 V_10 ,
const struct V_11 * V_11 ,
struct V_12 * V_12 )
{
return F_11 ( V_9 , V_10 ) ;
}
static void F_12 ( void * V_2 )
{
F_13 ( V_2 ) ;
}
static int F_14 ( void * V_2 , T_2 V_13 , T_1 V_10 ,
unsigned long * V_7 )
{
* V_7 = F_15 ( V_2 , V_13 ) ;
return * V_7 ? 0 : - 1 ;
}
static void F_16 ( void * V_2 , unsigned long V_7 )
{
F_17 ( V_2 , V_7 ) ;
}
static int F_18 ( void * V_2 , unsigned int V_14 ,
unsigned int * V_15 )
{
return - V_16 ;
}
static void * F_19 ( void * V_2 , unsigned long V_7 ,
enum V_17 V_18 )
{
enum V_19 V_20 ;
switch ( V_18 ) {
case V_21 :
V_20 = V_22 ;
break;
case V_23 :
V_20 = V_24 ;
break;
case V_25 :
default:
V_20 = V_26 ;
break;
}
return F_20 ( V_2 , V_7 , V_20 ) ;
}
static void F_21 ( void * V_2 , unsigned long V_7 )
{
F_22 ( V_2 , V_7 ) ;
}
static T_3 F_23 ( void * V_2 )
{
return F_24 ( V_2 ) << V_27 ;
}
static unsigned int F_25 ( int V_13 , int V_28 )
{
return V_28 * V_29 / V_13 ;
}
static int F_26 ( struct V_30 * V_30 )
{
return F_27 ( V_30 ) ;
}
static int F_28 ( struct V_30 * V_30 )
{
return F_29 ( V_30 ) ;
}
static void F_30 ( struct V_30 * V_30 , unsigned int * V_31 ,
enum V_32 * V_33 )
{
unsigned long V_34 ;
F_31 ( ! F_26 ( V_30 ) ) ;
V_34 = ( unsigned long ) V_30 -> V_35 ;
* V_33 = V_34 & V_36 ;
* V_31 = ( V_34 >> V_37 ) & V_38 ;
}
static void F_32 ( struct V_30 * V_30 , unsigned int V_31 ,
enum V_32 V_33 )
{
unsigned long V_34 ;
F_31 ( ! F_26 ( V_30 ) ) ;
V_34 = ( ( V_31 & V_38 ) << V_37 ) |
( V_33 & V_36 ) ;
V_30 -> V_35 = (struct V_39 * ) V_34 ;
}
static int F_33 ( int V_13 )
{
int V_40 = 0 ;
if ( F_34 ( V_13 > V_41 ) )
V_40 = F_35 ( V_13 - V_41 ,
V_42 ) ;
return F_36 ( V_43 - 1 , V_40 ) ;
}
static inline void F_37 ( struct V_44 * V_45 ,
enum V_46 type , unsigned long V_47 )
{
if ( type < V_48 )
V_45 -> V_49 . V_50 [ type ] += V_47 ;
}
static inline void F_38 ( struct V_44 * V_45 ,
enum V_46 type , unsigned long V_47 )
{
if ( type < V_48 )
V_45 -> V_49 . V_50 [ type ] -= V_47 ;
}
static inline unsigned long F_39 ( struct V_44 * V_45 ,
enum V_46 type )
{
if ( type < V_48 )
return V_45 -> V_49 . V_50 [ type ] ;
return 0 ;
}
static int T_4 F_40 ( void )
{
if ( ! F_41 () )
return - V_51 ;
V_52 = F_42 ( L_2 , NULL ) ;
if ( ! V_52 )
return - V_53 ;
return 0 ;
}
static void T_5 F_43 ( void )
{
F_44 ( V_52 ) ;
}
static int F_45 ( struct V_54 * V_55 , void * V_56 )
{
int V_57 ;
struct V_1 * V_2 = V_55 -> V_58 ;
struct V_44 * V_45 ;
int V_59 ;
unsigned long V_60 , V_61 ;
unsigned long V_62 , V_63 , V_64 ;
unsigned long V_65 = 0 , V_66 = 0 ;
unsigned long V_67 = 0 , V_68 = 0 , V_69 = 0 ;
F_46 ( V_55 , L_3 ,
L_4 , L_5 , L_6 , L_7 ,
L_8 , L_9 , L_10 ,
L_11 ) ;
for ( V_57 = 0 ; V_57 < V_43 ; V_57 ++ ) {
V_45 = V_2 -> V_44 [ V_57 ] ;
if ( V_45 -> V_70 != V_57 )
continue;
F_47 ( & V_45 -> V_71 ) ;
V_60 = F_39 ( V_45 , V_72 ) ;
V_61 = F_39 ( V_45 , V_73 ) ;
V_62 = F_39 ( V_45 , V_74 ) ;
V_63 = F_39 ( V_45 , V_75 ) ;
F_48 ( & V_45 -> V_71 ) ;
V_59 = F_25 ( V_45 -> V_13 ,
V_45 -> V_28 ) ;
V_64 = V_62 / V_59 *
V_45 -> V_28 ;
F_46 ( V_55 , L_12 ,
V_57 , V_45 -> V_13 , V_60 , V_61 ,
V_62 , V_63 , V_64 ,
V_45 -> V_28 ) ;
V_65 += V_60 ;
V_66 += V_61 ;
V_67 += V_62 ;
V_68 += V_63 ;
V_69 += V_64 ;
}
F_49 ( V_55 , L_13 ) ;
F_46 ( V_55 , L_14 ,
L_15 , L_16 , V_65 ,
V_66 , V_67 ,
V_68 , V_69 ) ;
return 0 ;
}
static int F_50 ( struct V_76 * V_76 , struct V_77 * V_77 )
{
return F_51 ( V_77 , F_45 , V_76 -> V_78 ) ;
}
static int F_52 ( const char * V_9 , struct V_1 * V_2 )
{
struct V_79 * V_80 ;
if ( ! V_52 )
return - V_51 ;
V_80 = F_42 ( V_9 , V_52 ) ;
if ( ! V_80 ) {
F_53 ( L_17 , V_9 ) ;
return - V_53 ;
}
V_2 -> V_81 = V_80 ;
V_80 = F_54 ( L_18 , V_82 | V_83 ,
V_2 -> V_81 , V_2 , & V_84 ) ;
if ( ! V_80 ) {
F_53 ( L_19 ,
V_9 , L_18 ) ;
return - V_53 ;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_44 ( V_2 -> V_81 ) ;
}
static int T_4 F_40 ( void )
{
return 0 ;
}
static void T_5 F_43 ( void )
{
}
static inline int F_52 ( const char * V_9 , struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_55 ( struct V_1 * V_2 )
{
}
static enum V_32 F_56 ( struct V_30 * V_30 )
{
int V_85 , V_86 ;
enum V_32 V_87 ;
F_31 ( ! F_26 ( V_30 ) ) ;
V_85 = V_30 -> V_85 ;
V_86 = V_30 -> V_88 ;
if ( V_85 == 0 )
V_87 = V_89 ;
else if ( V_85 == V_86 )
V_87 = V_90 ;
else if ( V_85 <= 3 * V_86 / V_91 )
V_87 = V_92 ;
else
V_87 = V_93 ;
return V_87 ;
}
static void F_57 ( struct V_30 * V_30 , struct V_44 * V_45 ,
enum V_32 V_33 )
{
struct V_30 * * V_94 ;
F_31 ( ! F_26 ( V_30 ) ) ;
if ( V_33 >= V_95 )
return;
F_37 ( V_45 , V_33 == V_92 ?
V_73 : V_72 , 1 ) ;
V_94 = & V_45 -> V_96 [ V_33 ] ;
if ( ! * V_94 ) {
* V_94 = V_30 ;
return;
}
F_58 ( & V_30 -> V_97 , & ( * V_94 ) -> V_97 ) ;
if ( V_30 -> V_85 >= ( * V_94 ) -> V_85 )
* V_94 = V_30 ;
}
static void F_59 ( struct V_30 * V_30 , struct V_44 * V_45 ,
enum V_32 V_33 )
{
struct V_30 * * V_94 ;
F_31 ( ! F_26 ( V_30 ) ) ;
if ( V_33 >= V_95 )
return;
V_94 = & V_45 -> V_96 [ V_33 ] ;
F_31 ( ! * V_94 ) ;
if ( F_60 ( & ( * V_94 ) -> V_97 ) )
* V_94 = NULL ;
else if ( * V_94 == V_30 )
* V_94 = (struct V_30 * ) F_61 ( ( * V_94 ) -> V_97 . V_98 ,
struct V_30 , V_97 ) ;
F_62 ( & V_30 -> V_97 ) ;
F_38 ( V_45 , V_33 == V_92 ?
V_73 : V_72 , 1 ) ;
}
static enum V_32 F_63 ( struct V_44 * V_45 ,
struct V_30 * V_30 )
{
int V_31 ;
enum V_32 V_99 , V_100 ;
F_31 ( ! F_26 ( V_30 ) ) ;
F_30 ( V_30 , & V_31 , & V_99 ) ;
V_100 = F_56 ( V_30 ) ;
if ( V_100 == V_99 )
goto V_101;
F_59 ( V_30 , V_45 , V_99 ) ;
F_57 ( V_30 , V_45 , V_100 ) ;
F_32 ( V_30 , V_31 , V_100 ) ;
V_101:
return V_100 ;
}
static int F_64 ( int V_102 )
{
int V_57 , V_103 = 0 ;
int V_104 = 1 ;
for ( V_57 = 1 ; V_57 <= V_105 ; V_57 ++ ) {
int V_106 ;
int V_107 , V_108 ;
V_106 = V_57 * V_29 ;
V_107 = V_106 % V_102 ;
V_108 = ( V_106 - V_107 ) * 100 / V_106 ;
if ( V_108 > V_103 ) {
V_103 = V_108 ;
V_104 = V_57 ;
}
}
return V_104 ;
}
static struct V_30 * F_65 ( struct V_30 * V_30 )
{
if ( F_26 ( V_30 ) )
return V_30 ;
else
return (struct V_30 * ) F_66 ( V_30 ) ;
}
static struct V_30 * F_67 ( struct V_30 * V_30 )
{
struct V_30 * V_98 ;
if ( F_28 ( V_30 ) )
V_98 = NULL ;
else if ( F_26 ( V_30 ) )
V_98 = (struct V_30 * ) F_66 ( V_30 ) ;
else
V_98 = F_61 ( V_30 -> V_97 . V_98 , struct V_30 , V_97 ) ;
return V_98 ;
}
static void * F_68 ( struct V_30 * V_30 , unsigned long V_109 )
{
unsigned long V_8 ;
if ( ! V_30 ) {
F_31 ( V_109 ) ;
return NULL ;
}
V_8 = F_69 ( V_30 ) << V_110 ;
V_8 |= ( ( V_109 ) & V_111 ) ;
V_8 <<= V_112 ;
return ( void * ) V_8 ;
}
static void F_70 ( unsigned long V_8 , struct V_30 * * V_30 ,
unsigned long * V_109 )
{
V_8 >>= V_112 ;
* V_30 = F_71 ( V_8 >> V_110 ) ;
* V_109 = ( V_8 & V_111 ) ;
}
static unsigned long F_72 ( unsigned long V_7 )
{
return * ( unsigned long * ) V_7 ;
}
static unsigned long F_73 ( struct V_44 * V_45 , struct V_30 * V_30 ,
void * V_8 )
{
if ( V_45 -> V_113 ) {
F_74 ( ! F_26 ( V_30 ) ) ;
return F_66 ( V_30 ) ;
} else
return * ( unsigned long * ) V_8 ;
}
static unsigned long F_75 ( struct V_30 * V_30 ,
unsigned long V_109 , int V_102 )
{
unsigned long V_114 = 0 ;
if ( ! F_26 ( V_30 ) )
V_114 = V_30 -> V_70 ;
return V_114 + V_109 * V_102 ;
}
static inline int F_76 ( unsigned long V_7 )
{
unsigned long * V_115 = ( unsigned long * ) V_7 ;
return ! F_77 ( V_116 , V_115 ) ;
}
static void F_78 ( unsigned long V_7 )
{
while ( ! F_76 ( V_7 ) ) ;
}
static void F_79 ( unsigned long V_7 )
{
unsigned long * V_115 = ( unsigned long * ) V_7 ;
F_80 ( V_116 , V_115 ) ;
}
static void F_81 ( struct V_30 * V_30 )
{
F_82 ( V_117 , & V_30 -> V_5 ) ;
F_82 ( V_118 , & V_30 -> V_5 ) ;
F_83 ( V_30 , 0 ) ;
V_30 -> V_35 = NULL ;
V_30 -> V_119 = NULL ;
F_84 ( V_30 ) ;
}
static void F_85 ( struct V_30 * V_120 )
{
struct V_30 * V_121 , * V_122 , * V_123 ;
F_31 ( ! F_26 ( V_120 ) ) ;
F_31 ( V_120 -> V_85 ) ;
V_123 = (struct V_30 * ) F_66 ( V_120 ) ;
F_81 ( V_120 ) ;
F_86 ( V_120 ) ;
if ( ! V_123 )
return;
F_87 (nextp, tmp, &head_extra->lru, lru) {
F_88 ( & V_121 -> V_97 ) ;
F_81 ( V_121 ) ;
F_86 ( V_121 ) ;
}
F_81 ( V_123 ) ;
F_86 ( V_123 ) ;
}
static void F_89 ( struct V_30 * V_120 , struct V_44 * V_45 )
{
unsigned long V_114 = 0 ;
struct V_30 * V_30 = V_120 ;
F_31 ( ! F_26 ( V_120 ) ) ;
while ( V_30 ) {
struct V_30 * V_124 ;
struct V_125 * V_126 ;
unsigned int V_57 = 1 ;
void * V_127 ;
if ( V_30 != V_120 )
V_30 -> V_70 = V_114 ;
V_127 = F_90 ( V_30 ) ;
V_126 = (struct V_125 * ) V_127 + V_114 / sizeof( * V_126 ) ;
while ( ( V_114 += V_45 -> V_13 ) < V_29 ) {
V_126 -> V_98 = F_68 ( V_30 , V_57 ++ ) ;
V_126 += V_45 -> V_13 / sizeof( * V_126 ) ;
}
V_124 = F_67 ( V_30 ) ;
V_126 -> V_98 = F_68 ( V_124 , 0 ) ;
F_91 ( V_127 ) ;
V_30 = V_124 ;
V_114 %= V_29 ;
}
}
static struct V_30 * F_92 ( struct V_44 * V_45 , T_1 V_5 )
{
int V_57 , error ;
struct V_30 * V_120 = NULL , * V_128 ( V_129 ) ;
error = - V_53 ;
for ( V_57 = 0 ; V_57 < V_45 -> V_28 ; V_57 ++ ) {
struct V_30 * V_30 ;
V_30 = F_93 ( V_5 ) ;
if ( ! V_30 )
goto V_130;
F_94 ( & V_30 -> V_97 ) ;
if ( V_57 == 0 ) {
F_95 ( V_30 ) ;
F_83 ( V_30 , 0 ) ;
V_120 = V_30 ;
V_120 -> V_85 = 0 ;
}
if ( V_57 == 1 )
F_83 ( V_120 , ( unsigned long ) V_30 ) ;
if ( V_57 >= 1 )
F_83 ( V_30 , ( unsigned long ) V_120 ) ;
if ( V_57 >= 2 )
F_96 ( & V_30 -> V_97 , & V_129 -> V_97 ) ;
if ( V_57 == V_45 -> V_28 - 1 )
F_97 ( V_30 ) ;
V_129 = V_30 ;
}
F_89 ( V_120 , V_45 ) ;
V_120 -> V_119 = F_68 ( V_120 , 0 ) ;
V_120 -> V_88 = V_45 -> V_28 * V_29 / V_45 -> V_13 ;
error = 0 ;
V_130:
if ( F_98 ( error ) && V_120 ) {
F_85 ( V_120 ) ;
V_120 = NULL ;
}
return V_120 ;
}
static struct V_30 * F_99 ( struct V_44 * V_45 )
{
int V_57 ;
struct V_30 * V_30 ;
for ( V_57 = 0 ; V_57 < V_95 ; V_57 ++ ) {
V_30 = V_45 -> V_96 [ V_57 ] ;
if ( V_30 )
break;
}
return V_30 ;
}
static inline int F_100 ( struct V_131 * V_132 )
{
if ( V_132 -> V_133 )
return 0 ;
V_132 -> V_133 = F_101 ( V_29 * 2 , NULL ) ;
if ( ! V_132 -> V_133 )
return - V_53 ;
return 0 ;
}
static inline void F_102 ( struct V_131 * V_132 )
{
if ( V_132 -> V_133 )
F_103 ( V_132 -> V_133 ) ;
V_132 -> V_133 = NULL ;
}
static inline void * F_104 ( struct V_131 * V_132 ,
struct V_30 * V_14 [ 2 ] , int V_114 , int V_13 )
{
F_31 ( F_105 ( V_132 -> V_133 , V_134 , V_14 ) ) ;
V_132 -> V_135 = V_132 -> V_133 -> V_136 ;
return V_132 -> V_135 + V_114 ;
}
static inline void F_106 ( struct V_131 * V_132 ,
struct V_30 * V_14 [ 2 ] , int V_114 , int V_13 )
{
unsigned long V_136 = ( unsigned long ) V_132 -> V_135 ;
F_107 ( V_136 , V_29 * 2 ) ;
}
static inline int F_100 ( struct V_131 * V_132 )
{
if ( V_132 -> V_137 )
return 0 ;
V_132 -> V_137 = F_108 ( V_138 , V_139 ) ;
if ( ! V_132 -> V_137 )
return - V_53 ;
return 0 ;
}
static inline void F_102 ( struct V_131 * V_132 )
{
F_109 ( V_132 -> V_137 ) ;
V_132 -> V_137 = NULL ;
}
static void * F_104 ( struct V_131 * V_132 ,
struct V_30 * V_14 [ 2 ] , int V_114 , int V_13 )
{
int V_140 [ 2 ] ;
void * V_136 ;
char * V_141 = V_132 -> V_137 ;
F_110 () ;
if ( V_132 -> V_142 == V_24 )
goto V_101;
V_140 [ 0 ] = V_29 - V_114 ;
V_140 [ 1 ] = V_13 - V_140 [ 0 ] ;
V_136 = F_90 ( V_14 [ 0 ] ) ;
memcpy ( V_141 , V_136 + V_114 , V_140 [ 0 ] ) ;
F_91 ( V_136 ) ;
V_136 = F_90 ( V_14 [ 1 ] ) ;
memcpy ( V_141 + V_140 [ 0 ] , V_136 , V_140 [ 1 ] ) ;
F_91 ( V_136 ) ;
V_101:
return V_132 -> V_137 ;
}
static void F_106 ( struct V_131 * V_132 ,
struct V_30 * V_14 [ 2 ] , int V_114 , int V_13 )
{
int V_140 [ 2 ] ;
void * V_136 ;
char * V_141 ;
if ( V_132 -> V_142 == V_22 )
goto V_101;
V_141 = V_132 -> V_137 ;
if ( ! V_132 -> V_113 ) {
V_141 = V_141 + V_4 ;
V_13 -= V_4 ;
V_114 += V_4 ;
}
V_140 [ 0 ] = V_29 - V_114 ;
V_140 [ 1 ] = V_13 - V_140 [ 0 ] ;
V_136 = F_90 ( V_14 [ 0 ] ) ;
memcpy ( V_136 + V_114 , V_141 , V_140 [ 0 ] ) ;
F_91 ( V_136 ) ;
V_136 = F_90 ( V_14 [ 1 ] ) ;
memcpy ( V_136 , V_141 + V_140 [ 0 ] , V_140 [ 1 ] ) ;
F_91 ( V_136 ) ;
V_101:
F_111 () ;
}
static int F_112 ( struct V_143 * V_144 , unsigned long V_145 ,
void * V_146 )
{
int V_147 , V_148 = ( long ) V_146 ;
struct V_131 * V_132 ;
switch ( V_145 ) {
case V_149 :
V_132 = & F_113 ( V_150 , V_148 ) ;
V_147 = F_100 ( V_132 ) ;
if ( V_147 )
return F_114 ( V_147 ) ;
break;
case V_151 :
case V_152 :
V_132 = & F_113 ( V_150 , V_148 ) ;
F_102 ( V_132 ) ;
break;
}
return V_153 ;
}
static int F_115 ( void )
{
int V_148 , V_128 ( V_147 ) ;
F_116 () ;
F_117 ( & V_154 ) ;
F_118 (cpu) {
V_147 = F_112 ( NULL , V_149 , ( void * ) ( long ) V_148 ) ;
if ( F_119 ( V_147 ) )
break;
}
F_120 () ;
return F_119 ( V_147 ) ;
}
static void F_121 ( void )
{
int V_148 ;
F_116 () ;
F_118 (cpu)
F_112 ( NULL , V_151 , ( void * ) ( long ) V_148 ) ;
F_122 ( & V_154 ) ;
F_120 () ;
}
static void F_123 ( void )
{
int V_155 ;
V_155 = ( V_138 - V_41 ) / V_42 + 1 ;
if ( ( V_138 - V_41 ) % V_42 )
V_155 += 1 ;
V_43 = V_155 ;
}
static bool F_124 ( struct V_44 * V_156 , int V_13 , int V_28 )
{
if ( V_156 -> V_28 != V_28 )
return false ;
if ( F_25 ( V_156 -> V_13 , V_156 -> V_28 )
!= F_25 ( V_13 , V_28 ) )
return false ;
return true ;
}
static bool F_125 ( struct V_30 * V_30 )
{
F_31 ( ! F_26 ( V_30 ) ) ;
return V_30 -> V_85 == V_30 -> V_88 ;
}
unsigned long F_24 ( struct V_1 * V_2 )
{
return F_126 ( & V_2 -> V_157 ) ;
}
void * F_20 ( struct V_1 * V_2 , unsigned long V_7 ,
enum V_19 V_18 )
{
struct V_30 * V_30 ;
unsigned long V_8 , V_109 , V_114 ;
unsigned int V_31 ;
enum V_32 V_87 ;
struct V_44 * V_45 ;
struct V_131 * V_132 ;
struct V_30 * V_14 [ 2 ] ;
void * V_147 ;
F_31 ( ! V_7 ) ;
F_31 ( F_127 () ) ;
F_78 ( V_7 ) ;
V_8 = F_72 ( V_7 ) ;
F_70 ( V_8 , & V_30 , & V_109 ) ;
F_30 ( F_65 ( V_30 ) , & V_31 , & V_87 ) ;
V_45 = V_2 -> V_44 [ V_31 ] ;
V_114 = F_75 ( V_30 , V_109 , V_45 -> V_13 ) ;
V_132 = & F_128 ( V_150 ) ;
V_132 -> V_142 = V_18 ;
if ( V_114 + V_45 -> V_13 <= V_29 ) {
V_132 -> V_135 = F_90 ( V_30 ) ;
V_147 = V_132 -> V_135 + V_114 ;
goto V_101;
}
V_14 [ 0 ] = V_30 ;
V_14 [ 1 ] = F_67 ( V_30 ) ;
F_31 ( ! V_14 [ 1 ] ) ;
V_147 = F_104 ( V_132 , V_14 , V_114 , V_45 -> V_13 ) ;
V_101:
if ( ! V_45 -> V_113 )
V_147 += V_4 ;
return V_147 ;
}
void F_22 ( struct V_1 * V_2 , unsigned long V_7 )
{
struct V_30 * V_30 ;
unsigned long V_8 , V_109 , V_114 ;
unsigned int V_31 ;
enum V_32 V_87 ;
struct V_44 * V_45 ;
struct V_131 * V_132 ;
F_31 ( ! V_7 ) ;
V_8 = F_72 ( V_7 ) ;
F_70 ( V_8 , & V_30 , & V_109 ) ;
F_30 ( F_65 ( V_30 ) , & V_31 , & V_87 ) ;
V_45 = V_2 -> V_44 [ V_31 ] ;
V_114 = F_75 ( V_30 , V_109 , V_45 -> V_13 ) ;
V_132 = F_129 ( & V_150 ) ;
if ( V_114 + V_45 -> V_13 <= V_29 )
F_91 ( V_132 -> V_135 ) ;
else {
struct V_30 * V_14 [ 2 ] ;
V_14 [ 0 ] = V_30 ;
V_14 [ 1 ] = F_67 ( V_30 ) ;
F_31 ( ! V_14 [ 1 ] ) ;
F_106 ( V_132 , V_14 , V_114 , V_45 -> V_13 ) ;
}
F_130 ( V_150 ) ;
F_79 ( V_7 ) ;
}
static unsigned long F_131 ( struct V_30 * V_120 ,
struct V_44 * V_45 , unsigned long V_7 )
{
unsigned long V_8 ;
struct V_125 * V_126 ;
struct V_30 * V_158 ;
unsigned long V_159 , V_160 ;
void * V_127 ;
V_7 |= V_161 ;
V_8 = ( unsigned long ) V_120 -> V_119 ;
F_70 ( V_8 , & V_158 , & V_159 ) ;
V_160 = F_75 ( V_158 , V_159 , V_45 -> V_13 ) ;
V_127 = F_90 ( V_158 ) ;
V_126 = (struct V_125 * ) V_127 + V_160 / sizeof( * V_126 ) ;
V_120 -> V_119 = V_126 -> V_98 ;
if ( ! V_45 -> V_113 )
V_126 -> V_7 = V_7 ;
else
F_83 ( V_120 , V_7 ) ;
F_91 ( V_127 ) ;
V_120 -> V_85 ++ ;
F_37 ( V_45 , V_75 , 1 ) ;
return V_8 ;
}
unsigned long F_15 ( struct V_1 * V_2 , T_2 V_13 )
{
unsigned long V_7 , V_8 ;
struct V_44 * V_45 ;
struct V_30 * V_120 ;
if ( F_98 ( ! V_13 || V_13 > V_138 ) )
return 0 ;
V_7 = F_5 ( V_2 ) ;
if ( ! V_7 )
return 0 ;
V_13 += V_4 ;
V_45 = V_2 -> V_44 [ F_33 ( V_13 ) ] ;
F_47 ( & V_45 -> V_71 ) ;
V_120 = F_99 ( V_45 ) ;
if ( ! V_120 ) {
F_48 ( & V_45 -> V_71 ) ;
V_120 = F_92 ( V_45 , V_2 -> V_5 ) ;
if ( F_98 ( ! V_120 ) ) {
F_7 ( V_2 , V_7 ) ;
return 0 ;
}
F_32 ( V_120 , V_45 -> V_70 , V_89 ) ;
F_132 ( V_45 -> V_28 ,
& V_2 -> V_157 ) ;
F_47 ( & V_45 -> V_71 ) ;
F_37 ( V_45 , V_74 , F_25 (
V_45 -> V_13 , V_45 -> V_28 ) ) ;
}
V_8 = F_131 ( V_120 , V_45 , V_7 ) ;
F_63 ( V_45 , V_120 ) ;
F_9 ( V_7 , V_8 ) ;
F_48 ( & V_45 -> V_71 ) ;
return V_7 ;
}
static void F_133 ( struct V_1 * V_2 , struct V_44 * V_45 ,
unsigned long V_8 )
{
struct V_125 * V_126 ;
struct V_30 * V_120 , * V_162 ;
unsigned long V_163 , V_164 ;
void * V_127 ;
F_31 ( ! V_8 ) ;
V_8 &= ~ V_161 ;
F_70 ( V_8 , & V_162 , & V_163 ) ;
V_120 = F_65 ( V_162 ) ;
V_164 = F_75 ( V_162 , V_163 , V_45 -> V_13 ) ;
V_127 = F_90 ( V_162 ) ;
V_126 = (struct V_125 * ) ( V_127 + V_164 ) ;
V_126 -> V_98 = V_120 -> V_119 ;
if ( V_45 -> V_113 )
F_83 ( V_120 , 0 ) ;
F_91 ( V_127 ) ;
V_120 -> V_119 = ( void * ) V_8 ;
V_120 -> V_85 -- ;
F_38 ( V_45 , V_75 , 1 ) ;
}
void F_17 ( struct V_1 * V_2 , unsigned long V_7 )
{
struct V_30 * V_120 , * V_162 ;
unsigned long V_8 , V_163 ;
int V_31 ;
struct V_44 * V_45 ;
enum V_32 V_33 ;
if ( F_98 ( ! V_7 ) )
return;
F_78 ( V_7 ) ;
V_8 = F_72 ( V_7 ) ;
F_70 ( V_8 , & V_162 , & V_163 ) ;
V_120 = F_65 ( V_162 ) ;
F_30 ( V_120 , & V_31 , & V_33 ) ;
V_45 = V_2 -> V_44 [ V_31 ] ;
F_47 ( & V_45 -> V_71 ) ;
F_133 ( V_2 , V_45 , V_8 ) ;
V_33 = F_63 ( V_45 , V_120 ) ;
if ( V_33 == V_89 ) {
F_38 ( V_45 , V_74 , F_25 (
V_45 -> V_13 , V_45 -> V_28 ) ) ;
F_134 ( V_45 -> V_28 ,
& V_2 -> V_157 ) ;
F_85 ( V_120 ) ;
}
F_48 ( & V_45 -> V_71 ) ;
F_79 ( V_7 ) ;
F_7 ( V_2 , V_7 ) ;
}
static void F_135 ( unsigned long V_165 , unsigned long V_166 ,
struct V_44 * V_45 )
{
struct V_30 * V_167 , * V_168 ;
unsigned long V_169 , V_170 ;
unsigned long V_171 , V_172 ;
void * V_173 , * V_174 ;
int V_175 , V_176 , V_13 ;
int V_177 = 0 ;
V_175 = V_176 = V_45 -> V_13 ;
F_70 ( V_166 , & V_167 , & V_169 ) ;
F_70 ( V_165 , & V_168 , & V_170 ) ;
V_171 = F_75 ( V_167 , V_169 , V_45 -> V_13 ) ;
V_172 = F_75 ( V_168 , V_170 , V_45 -> V_13 ) ;
if ( V_171 + V_45 -> V_13 > V_29 )
V_175 = V_29 - V_171 ;
if ( V_172 + V_45 -> V_13 > V_29 )
V_176 = V_29 - V_172 ;
V_173 = F_90 ( V_167 ) ;
V_174 = F_90 ( V_168 ) ;
while ( 1 ) {
V_13 = F_36 ( V_175 , V_176 ) ;
memcpy ( V_174 + V_172 , V_173 + V_171 , V_13 ) ;
V_177 += V_13 ;
if ( V_177 == V_45 -> V_13 )
break;
V_171 += V_13 ;
V_175 -= V_13 ;
V_172 += V_13 ;
V_176 -= V_13 ;
if ( V_171 >= V_29 ) {
F_91 ( V_174 ) ;
F_91 ( V_173 ) ;
V_167 = F_67 ( V_167 ) ;
F_31 ( ! V_167 ) ;
V_173 = F_90 ( V_167 ) ;
V_174 = F_90 ( V_168 ) ;
V_175 = V_45 -> V_13 - V_177 ;
V_171 = 0 ;
}
if ( V_172 >= V_29 ) {
F_91 ( V_174 ) ;
V_168 = F_67 ( V_168 ) ;
F_31 ( ! V_168 ) ;
V_174 = F_90 ( V_168 ) ;
V_176 = V_45 -> V_13 - V_177 ;
V_172 = 0 ;
}
}
F_91 ( V_174 ) ;
F_91 ( V_173 ) ;
}
static unsigned long F_136 ( struct V_30 * V_30 , int V_70 ,
struct V_44 * V_45 )
{
unsigned long V_94 ;
int V_178 = 0 ;
unsigned long V_7 = 0 ;
void * V_136 = F_90 ( V_30 ) ;
if ( ! F_26 ( V_30 ) )
V_178 = V_30 -> V_70 ;
V_178 += V_45 -> V_13 * V_70 ;
while ( V_178 < V_29 ) {
V_94 = F_73 ( V_45 , V_30 , V_136 + V_178 ) ;
if ( V_94 & V_161 ) {
V_7 = V_94 & ~ V_161 ;
if ( F_76 ( V_7 ) )
break;
V_7 = 0 ;
}
V_178 += V_45 -> V_13 ;
V_70 ++ ;
}
F_91 ( V_136 ) ;
return V_7 ;
}
static int F_137 ( struct V_1 * V_2 , struct V_44 * V_45 ,
struct V_179 * V_180 )
{
unsigned long V_181 , V_182 ;
unsigned long V_7 ;
struct V_30 * V_167 = V_180 -> V_167 ;
struct V_30 * V_168 = V_180 -> V_168 ;
unsigned long V_70 = V_180 -> V_70 ;
int V_147 = 0 ;
while ( 1 ) {
V_7 = F_136 ( V_167 , V_70 , V_45 ) ;
if ( ! V_7 ) {
V_167 = F_67 ( V_167 ) ;
if ( ! V_167 )
break;
V_70 = 0 ;
continue;
}
if ( F_125 ( V_168 ) ) {
F_79 ( V_7 ) ;
V_147 = - V_53 ;
break;
}
V_181 = F_72 ( V_7 ) ;
V_182 = F_131 ( V_168 , V_45 , V_7 ) ;
F_135 ( V_182 , V_181 , V_45 ) ;
V_70 ++ ;
F_9 ( V_7 , V_182 ) ;
F_79 ( V_7 ) ;
F_133 ( V_2 , V_45 , V_181 ) ;
}
V_180 -> V_167 = V_167 ;
V_180 -> V_70 = V_70 ;
return V_147 ;
}
static struct V_30 * F_138 ( struct V_44 * V_45 )
{
int V_57 ;
struct V_30 * V_30 ;
for ( V_57 = 0 ; V_57 < V_95 ; V_57 ++ ) {
V_30 = V_45 -> V_96 [ V_57 ] ;
if ( V_30 ) {
F_59 ( V_30 , V_45 , V_57 ) ;
break;
}
}
return V_30 ;
}
static enum V_32 F_139 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
struct V_30 * V_120 )
{
enum V_32 V_33 ;
F_31 ( ! F_26 ( V_120 ) ) ;
V_33 = F_56 ( V_120 ) ;
F_57 ( V_120 , V_45 , V_33 ) ;
F_32 ( V_120 , V_45 -> V_70 , V_33 ) ;
if ( V_33 == V_89 ) {
F_38 ( V_45 , V_74 , F_25 (
V_45 -> V_13 , V_45 -> V_28 ) ) ;
F_134 ( V_45 -> V_28 ,
& V_2 -> V_157 ) ;
F_85 ( V_120 ) ;
}
return V_33 ;
}
static struct V_30 * F_140 ( struct V_44 * V_45 )
{
int V_57 ;
struct V_30 * V_30 = NULL ;
for ( V_57 = V_92 ; V_57 >= V_93 ; V_57 -- ) {
V_30 = V_45 -> V_96 [ V_57 ] ;
if ( ! V_30 )
continue;
F_59 ( V_30 , V_45 , V_57 ) ;
break;
}
return V_30 ;
}
static unsigned long F_141 ( struct V_44 * V_45 )
{
unsigned long V_183 ;
V_183 = F_39 ( V_45 , V_74 ) -
F_39 ( V_45 , V_75 ) ;
V_183 /= F_25 ( V_45 -> V_13 ,
V_45 -> V_28 ) ;
return V_183 * V_45 -> V_28 ;
}
static void F_142 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_179 V_180 ;
struct V_30 * V_184 ;
struct V_30 * V_185 = NULL ;
F_47 ( & V_45 -> V_71 ) ;
while ( ( V_184 = F_140 ( V_45 ) ) ) {
F_31 ( ! F_26 ( V_184 ) ) ;
if ( ! F_141 ( V_45 ) )
break;
V_180 . V_70 = 0 ;
V_180 . V_167 = V_184 ;
while ( ( V_185 = F_138 ( V_45 ) ) ) {
V_180 . V_168 = V_185 ;
if ( ! F_137 ( V_2 , V_45 , & V_180 ) )
break;
F_139 ( V_2 , V_45 , V_185 ) ;
}
if ( V_185 == NULL )
break;
F_139 ( V_2 , V_45 , V_185 ) ;
if ( F_139 ( V_2 , V_45 , V_184 ) == V_89 )
V_2 -> V_49 . V_186 += V_45 -> V_28 ;
F_48 ( & V_45 -> V_71 ) ;
F_143 () ;
F_47 ( & V_45 -> V_71 ) ;
}
if ( V_184 )
F_139 ( V_2 , V_45 , V_184 ) ;
F_48 ( & V_45 -> V_71 ) ;
}
unsigned long F_144 ( struct V_1 * V_2 )
{
int V_57 ;
struct V_44 * V_45 ;
for ( V_57 = V_43 - 1 ; V_57 >= 0 ; V_57 -- ) {
V_45 = V_2 -> V_44 [ V_57 ] ;
if ( ! V_45 )
continue;
if ( V_45 -> V_70 != V_57 )
continue;
F_142 ( V_2 , V_45 ) ;
}
return V_2 -> V_49 . V_186 ;
}
void F_145 ( struct V_1 * V_2 , struct F_145 * V_49 )
{
memcpy ( V_49 , & V_2 -> V_49 , sizeof( struct F_145 ) ) ;
}
static unsigned long F_146 ( struct V_187 * V_187 ,
struct V_188 * V_189 )
{
unsigned long V_190 ;
struct V_1 * V_2 = F_147 ( V_187 , struct V_1 ,
V_187 ) ;
V_190 = V_2 -> V_49 . V_186 ;
V_190 = F_144 ( V_2 ) - V_190 ;
return V_190 ? V_190 : V_191 ;
}
static unsigned long F_148 ( struct V_187 * V_187 ,
struct V_188 * V_189 )
{
int V_57 ;
struct V_44 * V_45 ;
unsigned long V_192 = 0 ;
struct V_1 * V_2 = F_147 ( V_187 , struct V_1 ,
V_187 ) ;
for ( V_57 = V_43 - 1 ; V_57 >= 0 ; V_57 -- ) {
V_45 = V_2 -> V_44 [ V_57 ] ;
if ( ! V_45 )
continue;
if ( V_45 -> V_70 != V_57 )
continue;
V_192 += F_141 ( V_45 ) ;
}
return V_192 ;
}
static void F_149 ( struct V_1 * V_2 )
{
if ( V_2 -> V_193 ) {
F_150 ( & V_2 -> V_187 ) ;
V_2 -> V_193 = false ;
}
}
static int F_151 ( struct V_1 * V_2 )
{
V_2 -> V_187 . V_194 = F_146 ;
V_2 -> V_187 . V_195 = F_148 ;
V_2 -> V_187 . V_196 = 0 ;
V_2 -> V_187 . V_197 = V_198 ;
return F_152 ( & V_2 -> V_187 ) ;
}
struct V_1 * F_11 ( const char * V_9 , T_1 V_5 )
{
int V_57 ;
struct V_1 * V_2 ;
struct V_44 * V_199 = NULL ;
V_2 = F_153 ( sizeof( * V_2 ) , V_139 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_44 = F_154 ( V_43 , sizeof( struct V_44 * ) ,
V_139 ) ;
if ( ! V_2 -> V_44 ) {
F_109 ( V_2 ) ;
return NULL ;
}
V_2 -> V_9 = F_155 ( V_9 , V_139 ) ;
if ( ! V_2 -> V_9 )
goto V_200;
if ( F_1 ( V_2 ) )
goto V_200;
for ( V_57 = V_43 - 1 ; V_57 >= 0 ; V_57 -- ) {
int V_13 ;
int V_28 ;
struct V_44 * V_45 ;
V_13 = V_41 + V_57 * V_42 ;
if ( V_13 > V_138 )
V_13 = V_138 ;
V_28 = F_64 ( V_13 ) ;
if ( V_199 ) {
if ( F_124 ( V_199 , V_13 , V_28 ) ) {
V_2 -> V_44 [ V_57 ] = V_199 ;
continue;
}
}
V_45 = F_153 ( sizeof( struct V_44 ) , V_139 ) ;
if ( ! V_45 )
goto V_200;
V_45 -> V_13 = V_13 ;
V_45 -> V_70 = V_57 ;
V_45 -> V_28 = V_28 ;
if ( V_28 == 1 &&
F_25 ( V_13 , V_28 ) == 1 )
V_45 -> V_113 = true ;
F_156 ( & V_45 -> V_71 ) ;
V_2 -> V_44 [ V_57 ] = V_45 ;
V_199 = V_45 ;
}
V_2 -> V_5 = V_5 ;
if ( F_52 ( V_9 , V_2 ) )
goto V_200;
if ( F_151 ( V_2 ) == 0 )
V_2 -> V_193 = true ;
return V_2 ;
V_200:
F_13 ( V_2 ) ;
return NULL ;
}
void F_13 ( struct V_1 * V_2 )
{
int V_57 ;
F_149 ( V_2 ) ;
F_55 ( V_2 ) ;
for ( V_57 = 0 ; V_57 < V_43 ; V_57 ++ ) {
int V_87 ;
struct V_44 * V_45 = V_2 -> V_44 [ V_57 ] ;
if ( ! V_45 )
continue;
if ( V_45 -> V_70 != V_57 )
continue;
for ( V_87 = 0 ; V_87 < V_95 ; V_87 ++ ) {
if ( V_45 -> V_96 [ V_87 ] ) {
F_157 ( L_20 ,
V_45 -> V_13 , V_87 ) ;
}
}
F_109 ( V_45 ) ;
}
F_3 ( V_2 ) ;
F_109 ( V_2 -> V_44 ) ;
F_109 ( V_2 -> V_9 ) ;
F_109 ( V_2 ) ;
}
static int T_4 F_158 ( void )
{
int V_147 = F_115 () ;
if ( V_147 )
goto V_201;
F_123 () ;
#ifdef F_159
F_160 ( & V_202 ) ;
#endif
V_147 = F_40 () ;
if ( V_147 ) {
F_161 ( L_21 ) ;
goto V_203;
}
return 0 ;
V_203:
#ifdef F_159
F_162 ( & V_202 ) ;
#endif
V_201:
F_121 () ;
return V_147 ;
}
static void T_5 F_163 ( void )
{
#ifdef F_159
F_162 ( & V_202 ) ;
#endif
F_121 () ;
F_43 () ;
}
