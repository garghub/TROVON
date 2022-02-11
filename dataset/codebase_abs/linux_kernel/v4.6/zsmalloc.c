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
F_10 ( * ( unsigned long * ) V_7 , V_8 ) ;
}
static void * F_11 ( const char * V_9 , T_1 V_10 ,
const struct V_11 * V_11 ,
struct V_12 * V_12 )
{
return F_12 ( V_9 , V_10 ) ;
}
static void F_13 ( void * V_2 )
{
F_14 ( V_2 ) ;
}
static int F_15 ( void * V_2 , T_2 V_13 , T_1 V_10 ,
unsigned long * V_7 )
{
* V_7 = F_16 ( V_2 , V_13 ) ;
return * V_7 ? 0 : - 1 ;
}
static void F_17 ( void * V_2 , unsigned long V_7 )
{
F_18 ( V_2 , V_7 ) ;
}
static int F_19 ( void * V_2 , unsigned int V_14 ,
unsigned int * V_15 )
{
return - V_16 ;
}
static void * F_20 ( void * V_2 , unsigned long V_7 ,
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
return F_21 ( V_2 , V_7 , V_20 ) ;
}
static void F_22 ( void * V_2 , unsigned long V_7 )
{
F_23 ( V_2 , V_7 ) ;
}
static T_3 F_24 ( void * V_2 )
{
return F_25 ( V_2 ) << V_27 ;
}
static unsigned int F_26 ( int V_13 , int V_28 )
{
return V_28 * V_29 / V_13 ;
}
static int F_27 ( struct V_30 * V_30 )
{
return F_28 ( V_30 ) ;
}
static int F_29 ( struct V_30 * V_30 )
{
return F_30 ( V_30 ) ;
}
static void F_31 ( struct V_30 * V_30 , unsigned int * V_31 ,
enum V_32 * V_33 )
{
unsigned long V_34 ;
F_32 ( ! F_27 ( V_30 ) ) ;
V_34 = ( unsigned long ) V_30 -> V_35 ;
* V_33 = V_34 & V_36 ;
* V_31 = ( V_34 >> V_37 ) & V_38 ;
}
static void F_33 ( struct V_30 * V_30 , unsigned int V_31 ,
enum V_32 V_33 )
{
unsigned long V_34 ;
F_32 ( ! F_27 ( V_30 ) ) ;
V_34 = ( ( V_31 & V_38 ) << V_37 ) |
( V_33 & V_36 ) ;
V_30 -> V_35 = (struct V_39 * ) V_34 ;
}
static int F_34 ( int V_13 )
{
int V_40 = 0 ;
if ( F_35 ( V_13 > V_41 ) )
V_40 = F_36 ( V_13 - V_41 ,
V_42 ) ;
return F_37 ( V_43 - 1 , V_40 ) ;
}
static inline void F_38 ( struct V_44 * V_45 ,
enum V_46 type , unsigned long V_47 )
{
if ( type < V_48 )
V_45 -> V_49 . V_50 [ type ] += V_47 ;
}
static inline void F_39 ( struct V_44 * V_45 ,
enum V_46 type , unsigned long V_47 )
{
if ( type < V_48 )
V_45 -> V_49 . V_50 [ type ] -= V_47 ;
}
static inline unsigned long F_40 ( struct V_44 * V_45 ,
enum V_46 type )
{
if ( type < V_48 )
return V_45 -> V_49 . V_50 [ type ] ;
return 0 ;
}
static int T_4 F_41 ( void )
{
if ( ! F_42 () )
return - V_51 ;
V_52 = F_43 ( L_2 , NULL ) ;
if ( ! V_52 )
return - V_53 ;
return 0 ;
}
static void T_5 F_44 ( void )
{
F_45 ( V_52 ) ;
}
static int F_46 ( struct V_54 * V_55 , void * V_56 )
{
int V_57 ;
struct V_1 * V_2 = V_55 -> V_58 ;
struct V_44 * V_45 ;
int V_59 ;
unsigned long V_60 , V_61 ;
unsigned long V_62 , V_63 , V_64 , V_65 ;
unsigned long V_66 = 0 , V_67 = 0 ;
unsigned long V_68 = 0 , V_69 = 0 , V_70 = 0 ;
unsigned long V_71 = 0 ;
F_47 ( V_55 , L_3 ,
L_4 , L_5 , L_6 , L_7 ,
L_8 , L_9 , L_10 ,
L_11 , L_12 ) ;
for ( V_57 = 0 ; V_57 < V_43 ; V_57 ++ ) {
V_45 = V_2 -> V_44 [ V_57 ] ;
if ( V_45 -> V_72 != V_57 )
continue;
F_48 ( & V_45 -> V_73 ) ;
V_60 = F_40 ( V_45 , V_74 ) ;
V_61 = F_40 ( V_45 , V_75 ) ;
V_62 = F_40 ( V_45 , V_76 ) ;
V_63 = F_40 ( V_45 , V_77 ) ;
V_65 = F_49 ( V_45 ) ;
F_50 ( & V_45 -> V_73 ) ;
V_59 = F_26 ( V_45 -> V_13 ,
V_45 -> V_28 ) ;
V_64 = V_62 / V_59 *
V_45 -> V_28 ;
F_47 ( V_55 , L_13
L_14 ,
V_57 , V_45 -> V_13 , V_60 , V_61 ,
V_62 , V_63 , V_64 ,
V_45 -> V_28 , V_65 ) ;
V_66 += V_60 ;
V_67 += V_61 ;
V_68 += V_62 ;
V_69 += V_63 ;
V_70 += V_64 ;
V_71 += V_65 ;
}
F_51 ( V_55 , L_15 ) ;
F_47 ( V_55 , L_16 ,
L_17 , L_18 , V_66 ,
V_67 , V_68 ,
V_69 , V_70 , L_18 , V_71 ) ;
return 0 ;
}
static int F_52 ( struct V_78 * V_78 , struct V_79 * V_79 )
{
return F_53 ( V_79 , F_46 , V_78 -> V_80 ) ;
}
static int F_54 ( const char * V_9 , struct V_1 * V_2 )
{
struct V_81 * V_82 ;
if ( ! V_52 )
return - V_51 ;
V_82 = F_43 ( V_9 , V_52 ) ;
if ( ! V_82 ) {
F_55 ( L_19 , V_9 ) ;
return - V_53 ;
}
V_2 -> V_83 = V_82 ;
V_82 = F_56 ( L_20 , V_84 | V_85 ,
V_2 -> V_83 , V_2 , & V_86 ) ;
if ( ! V_82 ) {
F_55 ( L_21 ,
V_9 , L_20 ) ;
return - V_53 ;
}
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_45 ( V_2 -> V_83 ) ;
}
static int T_4 F_41 ( void )
{
return 0 ;
}
static void T_5 F_44 ( void )
{
}
static inline int F_54 ( const char * V_9 , struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_57 ( struct V_1 * V_2 )
{
}
static enum V_32 F_58 ( struct V_30 * V_30 )
{
int V_87 , V_88 ;
enum V_32 V_89 ;
F_32 ( ! F_27 ( V_30 ) ) ;
V_87 = V_30 -> V_87 ;
V_88 = V_30 -> V_90 ;
if ( V_87 == 0 )
V_89 = V_91 ;
else if ( V_87 == V_88 )
V_89 = V_92 ;
else if ( V_87 <= 3 * V_88 / V_93 )
V_89 = V_94 ;
else
V_89 = V_95 ;
return V_89 ;
}
static void F_59 ( struct V_30 * V_30 , struct V_44 * V_45 ,
enum V_32 V_33 )
{
struct V_30 * * V_96 ;
F_32 ( ! F_27 ( V_30 ) ) ;
if ( V_33 >= V_97 )
return;
F_38 ( V_45 , V_33 == V_94 ?
V_75 : V_74 , 1 ) ;
V_96 = & V_45 -> V_98 [ V_33 ] ;
if ( ! * V_96 ) {
* V_96 = V_30 ;
return;
}
F_60 ( & V_30 -> V_99 , & ( * V_96 ) -> V_99 ) ;
if ( V_30 -> V_87 >= ( * V_96 ) -> V_87 )
* V_96 = V_30 ;
}
static void F_61 ( struct V_30 * V_30 , struct V_44 * V_45 ,
enum V_32 V_33 )
{
struct V_30 * * V_96 ;
F_32 ( ! F_27 ( V_30 ) ) ;
if ( V_33 >= V_97 )
return;
V_96 = & V_45 -> V_98 [ V_33 ] ;
F_32 ( ! * V_96 ) ;
if ( F_62 ( & ( * V_96 ) -> V_99 ) )
* V_96 = NULL ;
else if ( * V_96 == V_30 )
* V_96 = (struct V_30 * ) F_63 ( ( * V_96 ) -> V_99 . V_100 ,
struct V_30 , V_99 ) ;
F_64 ( & V_30 -> V_99 ) ;
F_39 ( V_45 , V_33 == V_94 ?
V_75 : V_74 , 1 ) ;
}
static enum V_32 F_65 ( struct V_44 * V_45 ,
struct V_30 * V_30 )
{
int V_31 ;
enum V_32 V_101 , V_102 ;
F_32 ( ! F_27 ( V_30 ) ) ;
F_31 ( V_30 , & V_31 , & V_101 ) ;
V_102 = F_58 ( V_30 ) ;
if ( V_102 == V_101 )
goto V_103;
F_61 ( V_30 , V_45 , V_101 ) ;
F_59 ( V_30 , V_45 , V_102 ) ;
F_33 ( V_30 , V_31 , V_102 ) ;
V_103:
return V_102 ;
}
static int F_66 ( int V_104 )
{
int V_57 , V_105 = 0 ;
int V_106 = 1 ;
for ( V_57 = 1 ; V_57 <= V_107 ; V_57 ++ ) {
int V_108 ;
int V_109 , V_110 ;
V_108 = V_57 * V_29 ;
V_109 = V_108 % V_104 ;
V_110 = ( V_108 - V_109 ) * 100 / V_108 ;
if ( V_110 > V_105 ) {
V_105 = V_110 ;
V_106 = V_57 ;
}
}
return V_106 ;
}
static struct V_30 * F_67 ( struct V_30 * V_30 )
{
if ( F_27 ( V_30 ) )
return V_30 ;
else
return (struct V_30 * ) F_68 ( V_30 ) ;
}
static struct V_30 * F_69 ( struct V_30 * V_30 )
{
struct V_30 * V_100 ;
if ( F_29 ( V_30 ) )
V_100 = NULL ;
else if ( F_27 ( V_30 ) )
V_100 = (struct V_30 * ) F_68 ( V_30 ) ;
else
V_100 = F_63 ( V_30 -> V_99 . V_100 , struct V_30 , V_99 ) ;
return V_100 ;
}
static void * F_70 ( struct V_30 * V_30 , unsigned long V_111 )
{
unsigned long V_8 ;
if ( ! V_30 ) {
F_32 ( V_111 ) ;
return NULL ;
}
V_8 = F_71 ( V_30 ) << V_112 ;
V_8 |= ( ( V_111 ) & V_113 ) ;
V_8 <<= V_114 ;
return ( void * ) V_8 ;
}
static void F_72 ( unsigned long V_8 , struct V_30 * * V_30 ,
unsigned long * V_111 )
{
V_8 >>= V_114 ;
* V_30 = F_73 ( V_8 >> V_112 ) ;
* V_111 = ( V_8 & V_113 ) ;
}
static unsigned long F_74 ( unsigned long V_7 )
{
return * ( unsigned long * ) V_7 ;
}
static unsigned long F_75 ( struct V_44 * V_45 , struct V_30 * V_30 ,
void * V_8 )
{
if ( V_45 -> V_115 ) {
F_76 ( ! F_27 ( V_30 ) ) ;
return F_68 ( V_30 ) ;
} else
return * ( unsigned long * ) V_8 ;
}
static unsigned long F_77 ( struct V_30 * V_30 ,
unsigned long V_111 , int V_104 )
{
unsigned long V_116 = 0 ;
if ( ! F_27 ( V_30 ) )
V_116 = V_30 -> V_72 ;
return V_116 + V_111 * V_104 ;
}
static inline int F_78 ( unsigned long V_7 )
{
unsigned long * V_117 = ( unsigned long * ) V_7 ;
return ! F_79 ( V_118 , V_117 ) ;
}
static void F_80 ( unsigned long V_7 )
{
while ( ! F_78 ( V_7 ) ) ;
}
static void F_81 ( unsigned long V_7 )
{
unsigned long * V_117 = ( unsigned long * ) V_7 ;
F_82 ( V_118 , V_117 ) ;
}
static void F_83 ( struct V_30 * V_30 )
{
F_84 ( V_119 , & V_30 -> V_5 ) ;
F_84 ( V_120 , & V_30 -> V_5 ) ;
F_85 ( V_30 , 0 ) ;
V_30 -> V_35 = NULL ;
V_30 -> V_121 = NULL ;
F_86 ( V_30 ) ;
}
static void F_87 ( struct V_30 * V_122 )
{
struct V_30 * V_123 , * V_124 , * V_125 ;
F_32 ( ! F_27 ( V_122 ) ) ;
F_32 ( V_122 -> V_87 ) ;
V_125 = (struct V_30 * ) F_68 ( V_122 ) ;
F_83 ( V_122 ) ;
F_88 ( V_122 ) ;
if ( ! V_125 )
return;
F_89 (nextp, tmp, &head_extra->lru, lru) {
F_90 ( & V_123 -> V_99 ) ;
F_83 ( V_123 ) ;
F_88 ( V_123 ) ;
}
F_83 ( V_125 ) ;
F_88 ( V_125 ) ;
}
static void F_91 ( struct V_30 * V_122 , struct V_44 * V_45 )
{
unsigned long V_116 = 0 ;
struct V_30 * V_30 = V_122 ;
F_32 ( ! F_27 ( V_122 ) ) ;
while ( V_30 ) {
struct V_30 * V_126 ;
struct V_127 * V_128 ;
unsigned int V_57 = 1 ;
void * V_129 ;
if ( V_30 != V_122 )
V_30 -> V_72 = V_116 ;
V_129 = F_92 ( V_30 ) ;
V_128 = (struct V_127 * ) V_129 + V_116 / sizeof( * V_128 ) ;
while ( ( V_116 += V_45 -> V_13 ) < V_29 ) {
V_128 -> V_100 = F_70 ( V_30 , V_57 ++ ) ;
V_128 += V_45 -> V_13 / sizeof( * V_128 ) ;
}
V_126 = F_69 ( V_30 ) ;
V_128 -> V_100 = F_70 ( V_126 , 0 ) ;
F_93 ( V_129 ) ;
V_30 = V_126 ;
V_116 %= V_29 ;
}
}
static struct V_30 * F_94 ( struct V_44 * V_45 , T_1 V_5 )
{
int V_57 , error ;
struct V_30 * V_122 = NULL , * V_130 ( V_131 ) ;
error = - V_53 ;
for ( V_57 = 0 ; V_57 < V_45 -> V_28 ; V_57 ++ ) {
struct V_30 * V_30 ;
V_30 = F_95 ( V_5 ) ;
if ( ! V_30 )
goto V_132;
F_96 ( & V_30 -> V_99 ) ;
if ( V_57 == 0 ) {
F_97 ( V_30 ) ;
F_85 ( V_30 , 0 ) ;
V_122 = V_30 ;
V_122 -> V_87 = 0 ;
}
if ( V_57 == 1 )
F_85 ( V_122 , ( unsigned long ) V_30 ) ;
if ( V_57 >= 1 )
F_85 ( V_30 , ( unsigned long ) V_122 ) ;
if ( V_57 >= 2 )
F_98 ( & V_30 -> V_99 , & V_131 -> V_99 ) ;
if ( V_57 == V_45 -> V_28 - 1 )
F_99 ( V_30 ) ;
V_131 = V_30 ;
}
F_91 ( V_122 , V_45 ) ;
V_122 -> V_121 = F_70 ( V_122 , 0 ) ;
V_122 -> V_90 = V_45 -> V_28 * V_29 / V_45 -> V_13 ;
error = 0 ;
V_132:
if ( F_100 ( error ) && V_122 ) {
F_87 ( V_122 ) ;
V_122 = NULL ;
}
return V_122 ;
}
static struct V_30 * F_101 ( struct V_44 * V_45 )
{
int V_57 ;
struct V_30 * V_30 ;
for ( V_57 = 0 ; V_57 < V_97 ; V_57 ++ ) {
V_30 = V_45 -> V_98 [ V_57 ] ;
if ( V_30 )
break;
}
return V_30 ;
}
static inline int F_102 ( struct V_133 * V_134 )
{
if ( V_134 -> V_135 )
return 0 ;
V_134 -> V_135 = F_103 ( V_29 * 2 , NULL ) ;
if ( ! V_134 -> V_135 )
return - V_53 ;
return 0 ;
}
static inline void F_104 ( struct V_133 * V_134 )
{
if ( V_134 -> V_135 )
F_105 ( V_134 -> V_135 ) ;
V_134 -> V_135 = NULL ;
}
static inline void * F_106 ( struct V_133 * V_134 ,
struct V_30 * V_14 [ 2 ] , int V_116 , int V_13 )
{
F_32 ( F_107 ( V_134 -> V_135 , V_136 , V_14 ) ) ;
V_134 -> V_137 = V_134 -> V_135 -> V_138 ;
return V_134 -> V_137 + V_116 ;
}
static inline void F_108 ( struct V_133 * V_134 ,
struct V_30 * V_14 [ 2 ] , int V_116 , int V_13 )
{
unsigned long V_138 = ( unsigned long ) V_134 -> V_137 ;
F_109 ( V_138 , V_29 * 2 ) ;
}
static inline int F_102 ( struct V_133 * V_134 )
{
if ( V_134 -> V_139 )
return 0 ;
V_134 -> V_139 = F_110 ( V_140 , V_141 ) ;
if ( ! V_134 -> V_139 )
return - V_53 ;
return 0 ;
}
static inline void F_104 ( struct V_133 * V_134 )
{
F_111 ( V_134 -> V_139 ) ;
V_134 -> V_139 = NULL ;
}
static void * F_106 ( struct V_133 * V_134 ,
struct V_30 * V_14 [ 2 ] , int V_116 , int V_13 )
{
int V_142 [ 2 ] ;
void * V_138 ;
char * V_143 = V_134 -> V_139 ;
F_112 () ;
if ( V_134 -> V_144 == V_24 )
goto V_103;
V_142 [ 0 ] = V_29 - V_116 ;
V_142 [ 1 ] = V_13 - V_142 [ 0 ] ;
V_138 = F_92 ( V_14 [ 0 ] ) ;
memcpy ( V_143 , V_138 + V_116 , V_142 [ 0 ] ) ;
F_93 ( V_138 ) ;
V_138 = F_92 ( V_14 [ 1 ] ) ;
memcpy ( V_143 + V_142 [ 0 ] , V_138 , V_142 [ 1 ] ) ;
F_93 ( V_138 ) ;
V_103:
return V_134 -> V_139 ;
}
static void F_108 ( struct V_133 * V_134 ,
struct V_30 * V_14 [ 2 ] , int V_116 , int V_13 )
{
int V_142 [ 2 ] ;
void * V_138 ;
char * V_143 ;
if ( V_134 -> V_144 == V_22 )
goto V_103;
V_143 = V_134 -> V_139 ;
V_143 = V_143 + V_4 ;
V_13 -= V_4 ;
V_116 += V_4 ;
V_142 [ 0 ] = V_29 - V_116 ;
V_142 [ 1 ] = V_13 - V_142 [ 0 ] ;
V_138 = F_92 ( V_14 [ 0 ] ) ;
memcpy ( V_138 + V_116 , V_143 , V_142 [ 0 ] ) ;
F_93 ( V_138 ) ;
V_138 = F_92 ( V_14 [ 1 ] ) ;
memcpy ( V_138 , V_143 + V_142 [ 0 ] , V_142 [ 1 ] ) ;
F_93 ( V_138 ) ;
V_103:
F_113 () ;
}
static int F_114 ( struct V_145 * V_146 , unsigned long V_147 ,
void * V_148 )
{
int V_149 , V_150 = ( long ) V_148 ;
struct V_133 * V_134 ;
switch ( V_147 ) {
case V_151 :
V_134 = & F_115 ( V_152 , V_150 ) ;
V_149 = F_102 ( V_134 ) ;
if ( V_149 )
return F_116 ( V_149 ) ;
break;
case V_153 :
case V_154 :
V_134 = & F_115 ( V_152 , V_150 ) ;
F_104 ( V_134 ) ;
break;
}
return V_155 ;
}
static int F_117 ( void )
{
int V_150 , V_130 ( V_149 ) ;
F_118 () ;
F_119 ( & V_156 ) ;
F_120 (cpu) {
V_149 = F_114 ( NULL , V_151 , ( void * ) ( long ) V_150 ) ;
if ( F_121 ( V_149 ) )
break;
}
F_122 () ;
return F_121 ( V_149 ) ;
}
static void F_123 ( void )
{
int V_150 ;
F_118 () ;
F_120 (cpu)
F_114 ( NULL , V_153 , ( void * ) ( long ) V_150 ) ;
F_124 ( & V_156 ) ;
F_122 () ;
}
static void F_125 ( void )
{
int V_157 ;
V_157 = ( V_140 - V_41 ) / V_42 + 1 ;
if ( ( V_140 - V_41 ) % V_42 )
V_157 += 1 ;
V_43 = V_157 ;
}
static bool F_126 ( struct V_44 * V_158 , int V_13 , int V_28 )
{
if ( V_158 -> V_28 != V_28 )
return false ;
if ( F_26 ( V_158 -> V_13 , V_158 -> V_28 )
!= F_26 ( V_13 , V_28 ) )
return false ;
return true ;
}
static bool F_127 ( struct V_30 * V_30 )
{
F_32 ( ! F_27 ( V_30 ) ) ;
return V_30 -> V_87 == V_30 -> V_90 ;
}
unsigned long F_25 ( struct V_1 * V_2 )
{
return F_128 ( & V_2 -> V_159 ) ;
}
void * F_21 ( struct V_1 * V_2 , unsigned long V_7 ,
enum V_19 V_18 )
{
struct V_30 * V_30 ;
unsigned long V_8 , V_111 , V_116 ;
unsigned int V_31 ;
enum V_32 V_89 ;
struct V_44 * V_45 ;
struct V_133 * V_134 ;
struct V_30 * V_14 [ 2 ] ;
void * V_149 ;
F_32 ( ! V_7 ) ;
F_32 ( F_129 () ) ;
F_80 ( V_7 ) ;
V_8 = F_74 ( V_7 ) ;
F_72 ( V_8 , & V_30 , & V_111 ) ;
F_31 ( F_67 ( V_30 ) , & V_31 , & V_89 ) ;
V_45 = V_2 -> V_44 [ V_31 ] ;
V_116 = F_77 ( V_30 , V_111 , V_45 -> V_13 ) ;
V_134 = & F_130 ( V_152 ) ;
V_134 -> V_144 = V_18 ;
if ( V_116 + V_45 -> V_13 <= V_29 ) {
V_134 -> V_137 = F_92 ( V_30 ) ;
V_149 = V_134 -> V_137 + V_116 ;
goto V_103;
}
V_14 [ 0 ] = V_30 ;
V_14 [ 1 ] = F_69 ( V_30 ) ;
F_32 ( ! V_14 [ 1 ] ) ;
V_149 = F_106 ( V_134 , V_14 , V_116 , V_45 -> V_13 ) ;
V_103:
if ( ! V_45 -> V_115 )
V_149 += V_4 ;
return V_149 ;
}
void F_23 ( struct V_1 * V_2 , unsigned long V_7 )
{
struct V_30 * V_30 ;
unsigned long V_8 , V_111 , V_116 ;
unsigned int V_31 ;
enum V_32 V_89 ;
struct V_44 * V_45 ;
struct V_133 * V_134 ;
F_32 ( ! V_7 ) ;
V_8 = F_74 ( V_7 ) ;
F_72 ( V_8 , & V_30 , & V_111 ) ;
F_31 ( F_67 ( V_30 ) , & V_31 , & V_89 ) ;
V_45 = V_2 -> V_44 [ V_31 ] ;
V_116 = F_77 ( V_30 , V_111 , V_45 -> V_13 ) ;
V_134 = F_131 ( & V_152 ) ;
if ( V_116 + V_45 -> V_13 <= V_29 )
F_93 ( V_134 -> V_137 ) ;
else {
struct V_30 * V_14 [ 2 ] ;
V_14 [ 0 ] = V_30 ;
V_14 [ 1 ] = F_69 ( V_30 ) ;
F_32 ( ! V_14 [ 1 ] ) ;
F_108 ( V_134 , V_14 , V_116 , V_45 -> V_13 ) ;
}
F_132 ( V_152 ) ;
F_81 ( V_7 ) ;
}
static unsigned long F_133 ( struct V_30 * V_122 ,
struct V_44 * V_45 , unsigned long V_7 )
{
unsigned long V_8 ;
struct V_127 * V_128 ;
struct V_30 * V_160 ;
unsigned long V_161 , V_162 ;
void * V_129 ;
V_7 |= V_163 ;
V_8 = ( unsigned long ) V_122 -> V_121 ;
F_72 ( V_8 , & V_160 , & V_161 ) ;
V_162 = F_77 ( V_160 , V_161 , V_45 -> V_13 ) ;
V_129 = F_92 ( V_160 ) ;
V_128 = (struct V_127 * ) V_129 + V_162 / sizeof( * V_128 ) ;
V_122 -> V_121 = V_128 -> V_100 ;
if ( ! V_45 -> V_115 )
V_128 -> V_7 = V_7 ;
else
F_85 ( V_122 , V_7 ) ;
F_93 ( V_129 ) ;
V_122 -> V_87 ++ ;
F_38 ( V_45 , V_77 , 1 ) ;
return V_8 ;
}
unsigned long F_16 ( struct V_1 * V_2 , T_2 V_13 )
{
unsigned long V_7 , V_8 ;
struct V_44 * V_45 ;
struct V_30 * V_122 ;
if ( F_100 ( ! V_13 || V_13 > V_140 ) )
return 0 ;
V_7 = F_5 ( V_2 ) ;
if ( ! V_7 )
return 0 ;
V_13 += V_4 ;
V_45 = V_2 -> V_44 [ F_34 ( V_13 ) ] ;
F_48 ( & V_45 -> V_73 ) ;
V_122 = F_101 ( V_45 ) ;
if ( ! V_122 ) {
F_50 ( & V_45 -> V_73 ) ;
V_122 = F_94 ( V_45 , V_2 -> V_5 ) ;
if ( F_100 ( ! V_122 ) ) {
F_7 ( V_2 , V_7 ) ;
return 0 ;
}
F_33 ( V_122 , V_45 -> V_72 , V_91 ) ;
F_134 ( V_45 -> V_28 ,
& V_2 -> V_159 ) ;
F_48 ( & V_45 -> V_73 ) ;
F_38 ( V_45 , V_76 , F_26 (
V_45 -> V_13 , V_45 -> V_28 ) ) ;
}
V_8 = F_133 ( V_122 , V_45 , V_7 ) ;
F_65 ( V_45 , V_122 ) ;
F_9 ( V_7 , V_8 ) ;
F_50 ( & V_45 -> V_73 ) ;
return V_7 ;
}
static void F_135 ( struct V_1 * V_2 , struct V_44 * V_45 ,
unsigned long V_8 )
{
struct V_127 * V_128 ;
struct V_30 * V_122 , * V_164 ;
unsigned long V_165 , V_166 ;
void * V_129 ;
F_32 ( ! V_8 ) ;
V_8 &= ~ V_163 ;
F_72 ( V_8 , & V_164 , & V_165 ) ;
V_122 = F_67 ( V_164 ) ;
V_166 = F_77 ( V_164 , V_165 , V_45 -> V_13 ) ;
V_129 = F_92 ( V_164 ) ;
V_128 = (struct V_127 * ) ( V_129 + V_166 ) ;
V_128 -> V_100 = V_122 -> V_121 ;
if ( V_45 -> V_115 )
F_85 ( V_122 , 0 ) ;
F_93 ( V_129 ) ;
V_122 -> V_121 = ( void * ) V_8 ;
V_122 -> V_87 -- ;
F_39 ( V_45 , V_77 , 1 ) ;
}
void F_18 ( struct V_1 * V_2 , unsigned long V_7 )
{
struct V_30 * V_122 , * V_164 ;
unsigned long V_8 , V_165 ;
int V_31 ;
struct V_44 * V_45 ;
enum V_32 V_33 ;
if ( F_100 ( ! V_7 ) )
return;
F_80 ( V_7 ) ;
V_8 = F_74 ( V_7 ) ;
F_72 ( V_8 , & V_164 , & V_165 ) ;
V_122 = F_67 ( V_164 ) ;
F_31 ( V_122 , & V_31 , & V_33 ) ;
V_45 = V_2 -> V_44 [ V_31 ] ;
F_48 ( & V_45 -> V_73 ) ;
F_135 ( V_2 , V_45 , V_8 ) ;
V_33 = F_65 ( V_45 , V_122 ) ;
if ( V_33 == V_91 ) {
F_39 ( V_45 , V_76 , F_26 (
V_45 -> V_13 , V_45 -> V_28 ) ) ;
F_136 ( V_45 -> V_28 ,
& V_2 -> V_159 ) ;
F_87 ( V_122 ) ;
}
F_50 ( & V_45 -> V_73 ) ;
F_81 ( V_7 ) ;
F_7 ( V_2 , V_7 ) ;
}
static void F_137 ( unsigned long V_167 , unsigned long V_168 ,
struct V_44 * V_45 )
{
struct V_30 * V_169 , * V_170 ;
unsigned long V_171 , V_172 ;
unsigned long V_173 , V_174 ;
void * V_175 , * V_176 ;
int V_177 , V_178 , V_13 ;
int V_179 = 0 ;
V_177 = V_178 = V_45 -> V_13 ;
F_72 ( V_168 , & V_169 , & V_171 ) ;
F_72 ( V_167 , & V_170 , & V_172 ) ;
V_173 = F_77 ( V_169 , V_171 , V_45 -> V_13 ) ;
V_174 = F_77 ( V_170 , V_172 , V_45 -> V_13 ) ;
if ( V_173 + V_45 -> V_13 > V_29 )
V_177 = V_29 - V_173 ;
if ( V_174 + V_45 -> V_13 > V_29 )
V_178 = V_29 - V_174 ;
V_175 = F_92 ( V_169 ) ;
V_176 = F_92 ( V_170 ) ;
while ( 1 ) {
V_13 = F_37 ( V_177 , V_178 ) ;
memcpy ( V_176 + V_174 , V_175 + V_173 , V_13 ) ;
V_179 += V_13 ;
if ( V_179 == V_45 -> V_13 )
break;
V_173 += V_13 ;
V_177 -= V_13 ;
V_174 += V_13 ;
V_178 -= V_13 ;
if ( V_173 >= V_29 ) {
F_93 ( V_176 ) ;
F_93 ( V_175 ) ;
V_169 = F_69 ( V_169 ) ;
F_32 ( ! V_169 ) ;
V_175 = F_92 ( V_169 ) ;
V_176 = F_92 ( V_170 ) ;
V_177 = V_45 -> V_13 - V_179 ;
V_173 = 0 ;
}
if ( V_174 >= V_29 ) {
F_93 ( V_176 ) ;
V_170 = F_69 ( V_170 ) ;
F_32 ( ! V_170 ) ;
V_176 = F_92 ( V_170 ) ;
V_178 = V_45 -> V_13 - V_179 ;
V_174 = 0 ;
}
}
F_93 ( V_176 ) ;
F_93 ( V_175 ) ;
}
static unsigned long F_138 ( struct V_30 * V_30 , int V_72 ,
struct V_44 * V_45 )
{
unsigned long V_96 ;
int V_180 = 0 ;
unsigned long V_7 = 0 ;
void * V_138 = F_92 ( V_30 ) ;
if ( ! F_27 ( V_30 ) )
V_180 = V_30 -> V_72 ;
V_180 += V_45 -> V_13 * V_72 ;
while ( V_180 < V_29 ) {
V_96 = F_75 ( V_45 , V_30 , V_138 + V_180 ) ;
if ( V_96 & V_163 ) {
V_7 = V_96 & ~ V_163 ;
if ( F_78 ( V_7 ) )
break;
V_7 = 0 ;
}
V_180 += V_45 -> V_13 ;
V_72 ++ ;
}
F_93 ( V_138 ) ;
return V_7 ;
}
static int F_139 ( struct V_1 * V_2 , struct V_44 * V_45 ,
struct V_181 * V_182 )
{
unsigned long V_183 , V_184 ;
unsigned long V_7 ;
struct V_30 * V_169 = V_182 -> V_169 ;
struct V_30 * V_170 = V_182 -> V_170 ;
unsigned long V_72 = V_182 -> V_72 ;
int V_149 = 0 ;
while ( 1 ) {
V_7 = F_138 ( V_169 , V_72 , V_45 ) ;
if ( ! V_7 ) {
V_169 = F_69 ( V_169 ) ;
if ( ! V_169 )
break;
V_72 = 0 ;
continue;
}
if ( F_127 ( V_170 ) ) {
F_81 ( V_7 ) ;
V_149 = - V_53 ;
break;
}
V_183 = F_74 ( V_7 ) ;
V_184 = F_133 ( V_170 , V_45 , V_7 ) ;
F_137 ( V_184 , V_183 , V_45 ) ;
V_72 ++ ;
V_184 |= F_140 ( V_118 ) ;
F_9 ( V_7 , V_184 ) ;
F_81 ( V_7 ) ;
F_135 ( V_2 , V_45 , V_183 ) ;
}
V_182 -> V_169 = V_169 ;
V_182 -> V_72 = V_72 ;
return V_149 ;
}
static struct V_30 * F_141 ( struct V_44 * V_45 )
{
int V_57 ;
struct V_30 * V_30 ;
for ( V_57 = 0 ; V_57 < V_97 ; V_57 ++ ) {
V_30 = V_45 -> V_98 [ V_57 ] ;
if ( V_30 ) {
F_61 ( V_30 , V_45 , V_57 ) ;
break;
}
}
return V_30 ;
}
static enum V_32 F_142 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
struct V_30 * V_122 )
{
enum V_32 V_33 ;
F_32 ( ! F_27 ( V_122 ) ) ;
V_33 = F_58 ( V_122 ) ;
F_59 ( V_122 , V_45 , V_33 ) ;
F_33 ( V_122 , V_45 -> V_72 , V_33 ) ;
if ( V_33 == V_91 ) {
F_39 ( V_45 , V_76 , F_26 (
V_45 -> V_13 , V_45 -> V_28 ) ) ;
F_136 ( V_45 -> V_28 ,
& V_2 -> V_159 ) ;
F_87 ( V_122 ) ;
}
return V_33 ;
}
static struct V_30 * F_143 ( struct V_44 * V_45 )
{
int V_57 ;
struct V_30 * V_30 = NULL ;
for ( V_57 = V_94 ; V_57 >= V_95 ; V_57 -- ) {
V_30 = V_45 -> V_98 [ V_57 ] ;
if ( ! V_30 )
continue;
F_61 ( V_30 , V_45 , V_57 ) ;
break;
}
return V_30 ;
}
static unsigned long F_49 ( struct V_44 * V_45 )
{
unsigned long V_185 ;
unsigned long V_62 = F_40 ( V_45 , V_76 ) ;
unsigned long V_63 = F_40 ( V_45 , V_77 ) ;
if ( V_62 <= V_63 )
return 0 ;
V_185 = V_62 - V_63 ;
V_185 /= F_26 ( V_45 -> V_13 ,
V_45 -> V_28 ) ;
return V_185 * V_45 -> V_28 ;
}
static void F_144 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_181 V_182 ;
struct V_30 * V_186 ;
struct V_30 * V_187 = NULL ;
F_48 ( & V_45 -> V_73 ) ;
while ( ( V_186 = F_143 ( V_45 ) ) ) {
F_32 ( ! F_27 ( V_186 ) ) ;
if ( ! F_49 ( V_45 ) )
break;
V_182 . V_72 = 0 ;
V_182 . V_169 = V_186 ;
while ( ( V_187 = F_141 ( V_45 ) ) ) {
V_182 . V_170 = V_187 ;
if ( ! F_139 ( V_2 , V_45 , & V_182 ) )
break;
F_142 ( V_2 , V_45 , V_187 ) ;
}
if ( V_187 == NULL )
break;
F_142 ( V_2 , V_45 , V_187 ) ;
if ( F_142 ( V_2 , V_45 , V_186 ) == V_91 )
V_2 -> V_49 . V_188 += V_45 -> V_28 ;
F_50 ( & V_45 -> V_73 ) ;
F_145 () ;
F_48 ( & V_45 -> V_73 ) ;
}
if ( V_186 )
F_142 ( V_2 , V_45 , V_186 ) ;
F_50 ( & V_45 -> V_73 ) ;
}
unsigned long F_146 ( struct V_1 * V_2 )
{
int V_57 ;
struct V_44 * V_45 ;
for ( V_57 = V_43 - 1 ; V_57 >= 0 ; V_57 -- ) {
V_45 = V_2 -> V_44 [ V_57 ] ;
if ( ! V_45 )
continue;
if ( V_45 -> V_72 != V_57 )
continue;
F_144 ( V_2 , V_45 ) ;
}
return V_2 -> V_49 . V_188 ;
}
void F_147 ( struct V_1 * V_2 , struct F_147 * V_49 )
{
memcpy ( V_49 , & V_2 -> V_49 , sizeof( struct F_147 ) ) ;
}
static unsigned long F_148 ( struct V_189 * V_189 ,
struct V_190 * V_191 )
{
unsigned long V_192 ;
struct V_1 * V_2 = F_149 ( V_189 , struct V_1 ,
V_189 ) ;
V_192 = V_2 -> V_49 . V_188 ;
V_192 = F_146 ( V_2 ) - V_192 ;
return V_192 ? V_192 : V_193 ;
}
static unsigned long F_150 ( struct V_189 * V_189 ,
struct V_190 * V_191 )
{
int V_57 ;
struct V_44 * V_45 ;
unsigned long V_194 = 0 ;
struct V_1 * V_2 = F_149 ( V_189 , struct V_1 ,
V_189 ) ;
for ( V_57 = V_43 - 1 ; V_57 >= 0 ; V_57 -- ) {
V_45 = V_2 -> V_44 [ V_57 ] ;
if ( ! V_45 )
continue;
if ( V_45 -> V_72 != V_57 )
continue;
V_194 += F_49 ( V_45 ) ;
}
return V_194 ;
}
static void F_151 ( struct V_1 * V_2 )
{
if ( V_2 -> V_195 ) {
F_152 ( & V_2 -> V_189 ) ;
V_2 -> V_195 = false ;
}
}
static int F_153 ( struct V_1 * V_2 )
{
V_2 -> V_189 . V_196 = F_148 ;
V_2 -> V_189 . V_197 = F_150 ;
V_2 -> V_189 . V_198 = 0 ;
V_2 -> V_189 . V_199 = V_200 ;
return F_154 ( & V_2 -> V_189 ) ;
}
struct V_1 * F_12 ( const char * V_9 , T_1 V_5 )
{
int V_57 ;
struct V_1 * V_2 ;
struct V_44 * V_201 = NULL ;
V_2 = F_155 ( sizeof( * V_2 ) , V_141 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_44 = F_156 ( V_43 , sizeof( struct V_44 * ) ,
V_141 ) ;
if ( ! V_2 -> V_44 ) {
F_111 ( V_2 ) ;
return NULL ;
}
V_2 -> V_9 = F_157 ( V_9 , V_141 ) ;
if ( ! V_2 -> V_9 )
goto V_202;
if ( F_1 ( V_2 ) )
goto V_202;
for ( V_57 = V_43 - 1 ; V_57 >= 0 ; V_57 -- ) {
int V_13 ;
int V_28 ;
struct V_44 * V_45 ;
V_13 = V_41 + V_57 * V_42 ;
if ( V_13 > V_140 )
V_13 = V_140 ;
V_28 = F_66 ( V_13 ) ;
if ( V_201 ) {
if ( F_126 ( V_201 , V_13 , V_28 ) ) {
V_2 -> V_44 [ V_57 ] = V_201 ;
continue;
}
}
V_45 = F_155 ( sizeof( struct V_44 ) , V_141 ) ;
if ( ! V_45 )
goto V_202;
V_45 -> V_13 = V_13 ;
V_45 -> V_72 = V_57 ;
V_45 -> V_28 = V_28 ;
if ( V_28 == 1 &&
F_26 ( V_13 , V_28 ) == 1 )
V_45 -> V_115 = true ;
F_158 ( & V_45 -> V_73 ) ;
V_2 -> V_44 [ V_57 ] = V_45 ;
V_201 = V_45 ;
}
V_2 -> V_5 = V_5 ;
if ( F_54 ( V_9 , V_2 ) )
goto V_202;
if ( F_153 ( V_2 ) == 0 )
V_2 -> V_195 = true ;
return V_2 ;
V_202:
F_14 ( V_2 ) ;
return NULL ;
}
void F_14 ( struct V_1 * V_2 )
{
int V_57 ;
F_151 ( V_2 ) ;
F_57 ( V_2 ) ;
for ( V_57 = 0 ; V_57 < V_43 ; V_57 ++ ) {
int V_89 ;
struct V_44 * V_45 = V_2 -> V_44 [ V_57 ] ;
if ( ! V_45 )
continue;
if ( V_45 -> V_72 != V_57 )
continue;
for ( V_89 = 0 ; V_89 < V_97 ; V_89 ++ ) {
if ( V_45 -> V_98 [ V_89 ] ) {
F_159 ( L_22 ,
V_45 -> V_13 , V_89 ) ;
}
}
F_111 ( V_45 ) ;
}
F_3 ( V_2 ) ;
F_111 ( V_2 -> V_44 ) ;
F_111 ( V_2 -> V_9 ) ;
F_111 ( V_2 ) ;
}
static int T_4 F_160 ( void )
{
int V_149 = F_117 () ;
if ( V_149 )
goto V_203;
F_125 () ;
#ifdef F_161
F_162 ( & V_204 ) ;
#endif
V_149 = F_41 () ;
if ( V_149 ) {
F_163 ( L_23 ) ;
goto V_205;
}
return 0 ;
V_205:
#ifdef F_161
F_164 ( & V_204 ) ;
#endif
V_203:
F_123 () ;
return V_149 ;
}
static void T_5 F_165 ( void )
{
#ifdef F_161
F_164 ( & V_204 ) ;
#endif
F_123 () ;
F_44 () ;
}
