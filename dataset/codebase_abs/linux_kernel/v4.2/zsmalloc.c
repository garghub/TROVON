static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( L_1 , V_4 ,
0 , 0 , NULL ) ;
return V_2 -> V_3 ? 0 : 1 ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
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
static void * F_10 ( char * V_9 , T_1 V_10 , struct V_11 * V_11 ,
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
V_45 -> V_48 . V_49 [ type ] += V_47 ;
}
static inline void F_38 ( struct V_44 * V_45 ,
enum V_46 type , unsigned long V_47 )
{
V_45 -> V_48 . V_49 [ type ] -= V_47 ;
}
static inline unsigned long F_39 ( struct V_44 * V_45 ,
enum V_46 type )
{
return V_45 -> V_48 . V_49 [ type ] ;
}
static int T_4 F_40 ( void )
{
if ( ! F_41 () )
return - V_50 ;
V_51 = F_42 ( L_2 , NULL ) ;
if ( ! V_51 )
return - V_52 ;
return 0 ;
}
static void T_5 F_43 ( void )
{
F_44 ( V_51 ) ;
}
static int F_45 ( struct V_53 * V_54 , void * V_55 )
{
int V_56 ;
struct V_1 * V_2 = V_54 -> V_57 ;
struct V_44 * V_45 ;
int V_58 ;
unsigned long V_59 , V_60 ;
unsigned long V_61 , V_62 , V_63 ;
unsigned long V_64 = 0 , V_65 = 0 ;
unsigned long V_66 = 0 , V_67 = 0 , V_68 = 0 ;
F_46 ( V_54 , L_3 ,
L_4 , L_5 , L_6 , L_7 ,
L_8 , L_9 , L_10 ,
L_11 ) ;
for ( V_56 = 0 ; V_56 < V_43 ; V_56 ++ ) {
V_45 = V_2 -> V_44 [ V_56 ] ;
if ( V_45 -> V_69 != V_56 )
continue;
F_47 ( & V_45 -> V_70 ) ;
V_59 = F_39 ( V_45 , V_71 ) ;
V_60 = F_39 ( V_45 , V_72 ) ;
V_61 = F_39 ( V_45 , V_73 ) ;
V_62 = F_39 ( V_45 , V_74 ) ;
F_48 ( & V_45 -> V_70 ) ;
V_58 = F_25 ( V_45 -> V_13 ,
V_45 -> V_28 ) ;
V_63 = V_61 / V_58 *
V_45 -> V_28 ;
F_46 ( V_54 , L_12 ,
V_56 , V_45 -> V_13 , V_59 , V_60 ,
V_61 , V_62 , V_63 ,
V_45 -> V_28 ) ;
V_64 += V_59 ;
V_65 += V_60 ;
V_66 += V_61 ;
V_67 += V_62 ;
V_68 += V_63 ;
}
F_49 ( V_54 , L_13 ) ;
F_46 ( V_54 , L_14 ,
L_15 , L_16 , V_64 ,
V_65 , V_66 ,
V_67 , V_68 ) ;
return 0 ;
}
static int F_50 ( struct V_75 * V_75 , struct V_76 * V_76 )
{
return F_51 ( V_76 , F_45 , V_75 -> V_77 ) ;
}
static int F_52 ( char * V_9 , struct V_1 * V_2 )
{
struct V_78 * V_79 ;
if ( ! V_51 )
return - V_50 ;
V_79 = F_42 ( V_9 , V_51 ) ;
if ( ! V_79 ) {
F_53 ( L_17 , V_9 ) ;
return - V_52 ;
}
V_2 -> V_80 = V_79 ;
V_79 = F_54 ( L_18 , V_81 | V_82 ,
V_2 -> V_80 , V_2 , & V_83 ) ;
if ( ! V_79 ) {
F_53 ( L_19 ,
V_9 , L_18 ) ;
return - V_52 ;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_44 ( V_2 -> V_80 ) ;
}
static inline void F_37 ( struct V_44 * V_45 ,
enum V_46 type , unsigned long V_47 )
{
}
static inline void F_38 ( struct V_44 * V_45 ,
enum V_46 type , unsigned long V_47 )
{
}
static inline unsigned long F_39 ( struct V_44 * V_45 ,
enum V_46 type )
{
return 0 ;
}
static int T_4 F_40 ( void )
{
return 0 ;
}
static void T_5 F_43 ( void )
{
}
static inline int F_52 ( char * V_9 , struct V_1 * V_2 )
{
return 0 ;
}
static inline void F_55 ( struct V_1 * V_2 )
{
}
static enum V_32 F_56 ( struct V_30 * V_30 )
{
int V_84 , V_85 ;
enum V_32 V_86 ;
F_31 ( ! F_26 ( V_30 ) ) ;
V_84 = V_30 -> V_84 ;
V_85 = V_30 -> V_87 ;
if ( V_84 == 0 )
V_86 = V_88 ;
else if ( V_84 == V_85 )
V_86 = V_89 ;
else if ( V_84 <= 3 * V_85 / V_90 )
V_86 = V_91 ;
else
V_86 = V_92 ;
return V_86 ;
}
static void F_57 ( struct V_30 * V_30 , struct V_44 * V_45 ,
enum V_32 V_33 )
{
struct V_30 * * V_93 ;
F_31 ( ! F_26 ( V_30 ) ) ;
if ( V_33 >= V_94 )
return;
V_93 = & V_45 -> V_95 [ V_33 ] ;
if ( * V_93 )
F_58 ( & V_30 -> V_96 , & ( * V_93 ) -> V_96 ) ;
* V_93 = V_30 ;
F_37 ( V_45 , V_33 == V_91 ?
V_72 : V_71 , 1 ) ;
}
static void F_59 ( struct V_30 * V_30 , struct V_44 * V_45 ,
enum V_32 V_33 )
{
struct V_30 * * V_93 ;
F_31 ( ! F_26 ( V_30 ) ) ;
if ( V_33 >= V_94 )
return;
V_93 = & V_45 -> V_95 [ V_33 ] ;
F_31 ( ! * V_93 ) ;
if ( F_60 ( & ( * V_93 ) -> V_96 ) )
* V_93 = NULL ;
else if ( * V_93 == V_30 )
* V_93 = (struct V_30 * ) F_61 ( ( * V_93 ) -> V_96 . V_97 ,
struct V_30 , V_96 ) ;
F_62 ( & V_30 -> V_96 ) ;
F_38 ( V_45 , V_33 == V_91 ?
V_72 : V_71 , 1 ) ;
}
static enum V_32 F_63 ( struct V_44 * V_45 ,
struct V_30 * V_30 )
{
int V_31 ;
enum V_32 V_98 , V_99 ;
F_31 ( ! F_26 ( V_30 ) ) ;
F_30 ( V_30 , & V_31 , & V_98 ) ;
V_99 = F_56 ( V_30 ) ;
if ( V_99 == V_98 )
goto V_100;
F_59 ( V_30 , V_45 , V_98 ) ;
F_57 ( V_30 , V_45 , V_99 ) ;
F_32 ( V_30 , V_31 , V_99 ) ;
V_100:
return V_99 ;
}
static int F_64 ( int V_101 )
{
int V_56 , V_102 = 0 ;
int V_103 = 1 ;
for ( V_56 = 1 ; V_56 <= V_104 ; V_56 ++ ) {
int V_105 ;
int V_106 , V_107 ;
V_105 = V_56 * V_29 ;
V_106 = V_105 % V_101 ;
V_107 = ( V_105 - V_106 ) * 100 / V_105 ;
if ( V_107 > V_102 ) {
V_102 = V_107 ;
V_103 = V_56 ;
}
}
return V_103 ;
}
static struct V_30 * F_65 ( struct V_30 * V_30 )
{
if ( F_26 ( V_30 ) )
return V_30 ;
else
return V_30 -> V_108 ;
}
static struct V_30 * F_66 ( struct V_30 * V_30 )
{
struct V_30 * V_97 ;
if ( F_28 ( V_30 ) )
V_97 = NULL ;
else if ( F_26 ( V_30 ) )
V_97 = (struct V_30 * ) F_67 ( V_30 ) ;
else
V_97 = F_61 ( V_30 -> V_96 . V_97 , struct V_30 , V_96 ) ;
return V_97 ;
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
return * ( unsigned long * ) F_67 ( V_30 ) ;
} else
return * ( unsigned long * ) V_8 ;
}
static unsigned long F_75 ( struct V_30 * V_30 ,
unsigned long V_109 , int V_101 )
{
unsigned long V_114 = 0 ;
if ( ! F_26 ( V_30 ) )
V_114 = V_30 -> V_69 ;
return V_114 + V_109 * V_101 ;
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
static void F_85 ( struct V_30 * V_108 )
{
struct V_30 * V_120 , * V_121 , * V_122 ;
F_31 ( ! F_26 ( V_108 ) ) ;
F_31 ( V_108 -> V_84 ) ;
V_122 = (struct V_30 * ) F_67 ( V_108 ) ;
F_81 ( V_108 ) ;
F_86 ( V_108 ) ;
if ( ! V_122 )
return;
F_87 (nextp, tmp, &head_extra->lru, lru) {
F_88 ( & V_120 -> V_96 ) ;
F_81 ( V_120 ) ;
F_86 ( V_120 ) ;
}
F_81 ( V_122 ) ;
F_86 ( V_122 ) ;
}
static void F_89 ( struct V_30 * V_108 , struct V_44 * V_45 )
{
unsigned long V_114 = 0 ;
struct V_30 * V_30 = V_108 ;
F_31 ( ! F_26 ( V_108 ) ) ;
while ( V_30 ) {
struct V_30 * V_123 ;
struct V_124 * V_125 ;
unsigned int V_56 = 1 ;
void * V_126 ;
if ( V_30 != V_108 )
V_30 -> V_69 = V_114 ;
V_126 = F_90 ( V_30 ) ;
V_125 = (struct V_124 * ) V_126 + V_114 / sizeof( * V_125 ) ;
while ( ( V_114 += V_45 -> V_13 ) < V_29 ) {
V_125 -> V_97 = F_68 ( V_30 , V_56 ++ ) ;
V_125 += V_45 -> V_13 / sizeof( * V_125 ) ;
}
V_123 = F_66 ( V_30 ) ;
V_125 -> V_97 = F_68 ( V_123 , 0 ) ;
F_91 ( V_126 ) ;
V_30 = V_123 ;
V_114 %= V_29 ;
}
}
static struct V_30 * F_92 ( struct V_44 * V_45 , T_1 V_5 )
{
int V_56 , error ;
struct V_30 * V_108 = NULL , * V_127 ( V_128 ) ;
error = - V_52 ;
for ( V_56 = 0 ; V_56 < V_45 -> V_28 ; V_56 ++ ) {
struct V_30 * V_30 ;
V_30 = F_93 ( V_5 ) ;
if ( ! V_30 )
goto V_129;
F_94 ( & V_30 -> V_96 ) ;
if ( V_56 == 0 ) {
F_95 ( V_30 ) ;
F_83 ( V_30 , 0 ) ;
V_108 = V_30 ;
V_108 -> V_84 = 0 ;
}
if ( V_56 == 1 )
F_83 ( V_108 , ( unsigned long ) V_30 ) ;
if ( V_56 >= 1 )
V_30 -> V_108 = V_108 ;
if ( V_56 >= 2 )
F_96 ( & V_30 -> V_96 , & V_128 -> V_96 ) ;
if ( V_56 == V_45 -> V_28 - 1 )
F_97 ( V_30 ) ;
V_128 = V_30 ;
}
F_89 ( V_108 , V_45 ) ;
V_108 -> V_119 = F_68 ( V_108 , 0 ) ;
V_108 -> V_87 = V_45 -> V_28 * V_29 / V_45 -> V_13 ;
error = 0 ;
V_129:
if ( F_98 ( error ) && V_108 ) {
F_85 ( V_108 ) ;
V_108 = NULL ;
}
return V_108 ;
}
static struct V_30 * F_99 ( struct V_44 * V_45 )
{
int V_56 ;
struct V_30 * V_30 ;
for ( V_56 = 0 ; V_56 < V_94 ; V_56 ++ ) {
V_30 = V_45 -> V_95 [ V_56 ] ;
if ( V_30 )
break;
}
return V_30 ;
}
static inline int F_100 ( struct V_130 * V_131 )
{
if ( V_131 -> V_132 )
return 0 ;
V_131 -> V_132 = F_101 ( V_29 * 2 , NULL ) ;
if ( ! V_131 -> V_132 )
return - V_52 ;
return 0 ;
}
static inline void F_102 ( struct V_130 * V_131 )
{
if ( V_131 -> V_132 )
F_103 ( V_131 -> V_132 ) ;
V_131 -> V_132 = NULL ;
}
static inline void * F_104 ( struct V_130 * V_131 ,
struct V_30 * V_14 [ 2 ] , int V_114 , int V_13 )
{
F_31 ( F_105 ( V_131 -> V_132 , V_133 , V_14 ) ) ;
V_131 -> V_134 = V_131 -> V_132 -> V_135 ;
return V_131 -> V_134 + V_114 ;
}
static inline void F_106 ( struct V_130 * V_131 ,
struct V_30 * V_14 [ 2 ] , int V_114 , int V_13 )
{
unsigned long V_135 = ( unsigned long ) V_131 -> V_134 ;
F_107 ( V_135 , V_29 * 2 ) ;
}
static inline int F_100 ( struct V_130 * V_131 )
{
if ( V_131 -> V_136 )
return 0 ;
V_131 -> V_136 = F_108 ( V_137 , V_138 ) ;
if ( ! V_131 -> V_136 )
return - V_52 ;
return 0 ;
}
static inline void F_102 ( struct V_130 * V_131 )
{
F_109 ( V_131 -> V_136 ) ;
V_131 -> V_136 = NULL ;
}
static void * F_104 ( struct V_130 * V_131 ,
struct V_30 * V_14 [ 2 ] , int V_114 , int V_13 )
{
int V_139 [ 2 ] ;
void * V_135 ;
char * V_140 = V_131 -> V_136 ;
F_110 () ;
if ( V_131 -> V_141 == V_24 )
goto V_100;
V_139 [ 0 ] = V_29 - V_114 ;
V_139 [ 1 ] = V_13 - V_139 [ 0 ] ;
V_135 = F_90 ( V_14 [ 0 ] ) ;
memcpy ( V_140 , V_135 + V_114 , V_139 [ 0 ] ) ;
F_91 ( V_135 ) ;
V_135 = F_90 ( V_14 [ 1 ] ) ;
memcpy ( V_140 + V_139 [ 0 ] , V_135 , V_139 [ 1 ] ) ;
F_91 ( V_135 ) ;
V_100:
return V_131 -> V_136 ;
}
static void F_106 ( struct V_130 * V_131 ,
struct V_30 * V_14 [ 2 ] , int V_114 , int V_13 )
{
int V_139 [ 2 ] ;
void * V_135 ;
char * V_140 ;
if ( V_131 -> V_141 == V_22 )
goto V_100;
V_140 = V_131 -> V_136 ;
if ( ! V_131 -> V_113 ) {
V_140 = V_140 + V_4 ;
V_13 -= V_4 ;
V_114 += V_4 ;
}
V_139 [ 0 ] = V_29 - V_114 ;
V_139 [ 1 ] = V_13 - V_139 [ 0 ] ;
V_135 = F_90 ( V_14 [ 0 ] ) ;
memcpy ( V_135 + V_114 , V_140 , V_139 [ 0 ] ) ;
F_91 ( V_135 ) ;
V_135 = F_90 ( V_14 [ 1 ] ) ;
memcpy ( V_135 , V_140 + V_139 [ 0 ] , V_139 [ 1 ] ) ;
F_91 ( V_135 ) ;
V_100:
F_111 () ;
}
static int F_112 ( struct V_142 * V_143 , unsigned long V_144 ,
void * V_145 )
{
int V_146 , V_147 = ( long ) V_145 ;
struct V_130 * V_131 ;
switch ( V_144 ) {
case V_148 :
V_131 = & F_113 ( V_149 , V_147 ) ;
V_146 = F_100 ( V_131 ) ;
if ( V_146 )
return F_114 ( V_146 ) ;
break;
case V_150 :
case V_151 :
V_131 = & F_113 ( V_149 , V_147 ) ;
F_102 ( V_131 ) ;
break;
}
return V_152 ;
}
static int F_115 ( void )
{
int V_147 , V_127 ( V_146 ) ;
F_116 () ;
F_117 ( & V_153 ) ;
F_118 (cpu) {
V_146 = F_112 ( NULL , V_148 , ( void * ) ( long ) V_147 ) ;
if ( F_119 ( V_146 ) )
break;
}
F_120 () ;
return F_119 ( V_146 ) ;
}
static void F_121 ( void )
{
int V_147 ;
F_116 () ;
F_118 (cpu)
F_112 ( NULL , V_150 , ( void * ) ( long ) V_147 ) ;
F_122 ( & V_153 ) ;
F_120 () ;
}
static void F_123 ( void )
{
int V_154 ;
V_154 = ( V_137 - V_41 ) / V_42 + 1 ;
if ( ( V_137 - V_41 ) % V_42 )
V_154 += 1 ;
V_43 = V_154 ;
}
static bool F_124 ( struct V_44 * V_155 , int V_13 , int V_28 )
{
if ( V_155 -> V_28 != V_28 )
return false ;
if ( F_25 ( V_155 -> V_13 , V_155 -> V_28 )
!= F_25 ( V_13 , V_28 ) )
return false ;
return true ;
}
static bool F_125 ( struct V_30 * V_30 )
{
F_31 ( ! F_26 ( V_30 ) ) ;
return V_30 -> V_84 == V_30 -> V_87 ;
}
unsigned long F_24 ( struct V_1 * V_2 )
{
return F_126 ( & V_2 -> V_156 ) ;
}
void * F_20 ( struct V_1 * V_2 , unsigned long V_7 ,
enum V_19 V_18 )
{
struct V_30 * V_30 ;
unsigned long V_8 , V_109 , V_114 ;
unsigned int V_31 ;
enum V_32 V_86 ;
struct V_44 * V_45 ;
struct V_130 * V_131 ;
struct V_30 * V_14 [ 2 ] ;
void * V_146 ;
F_31 ( ! V_7 ) ;
F_31 ( F_127 () ) ;
F_78 ( V_7 ) ;
V_8 = F_72 ( V_7 ) ;
F_70 ( V_8 , & V_30 , & V_109 ) ;
F_30 ( F_65 ( V_30 ) , & V_31 , & V_86 ) ;
V_45 = V_2 -> V_44 [ V_31 ] ;
V_114 = F_75 ( V_30 , V_109 , V_45 -> V_13 ) ;
V_131 = & F_128 ( V_149 ) ;
V_131 -> V_141 = V_18 ;
if ( V_114 + V_45 -> V_13 <= V_29 ) {
V_131 -> V_134 = F_90 ( V_30 ) ;
V_146 = V_131 -> V_134 + V_114 ;
goto V_100;
}
V_14 [ 0 ] = V_30 ;
V_14 [ 1 ] = F_66 ( V_30 ) ;
F_31 ( ! V_14 [ 1 ] ) ;
V_146 = F_104 ( V_131 , V_14 , V_114 , V_45 -> V_13 ) ;
V_100:
if ( ! V_45 -> V_113 )
V_146 += V_4 ;
return V_146 ;
}
void F_22 ( struct V_1 * V_2 , unsigned long V_7 )
{
struct V_30 * V_30 ;
unsigned long V_8 , V_109 , V_114 ;
unsigned int V_31 ;
enum V_32 V_86 ;
struct V_44 * V_45 ;
struct V_130 * V_131 ;
F_31 ( ! V_7 ) ;
V_8 = F_72 ( V_7 ) ;
F_70 ( V_8 , & V_30 , & V_109 ) ;
F_30 ( F_65 ( V_30 ) , & V_31 , & V_86 ) ;
V_45 = V_2 -> V_44 [ V_31 ] ;
V_114 = F_75 ( V_30 , V_109 , V_45 -> V_13 ) ;
V_131 = F_129 ( & V_149 ) ;
if ( V_114 + V_45 -> V_13 <= V_29 )
F_91 ( V_131 -> V_134 ) ;
else {
struct V_30 * V_14 [ 2 ] ;
V_14 [ 0 ] = V_30 ;
V_14 [ 1 ] = F_66 ( V_30 ) ;
F_31 ( ! V_14 [ 1 ] ) ;
F_106 ( V_131 , V_14 , V_114 , V_45 -> V_13 ) ;
}
F_130 ( V_149 ) ;
F_79 ( V_7 ) ;
}
static unsigned long F_131 ( struct V_30 * V_108 ,
struct V_44 * V_45 , unsigned long V_7 )
{
unsigned long V_8 ;
struct V_124 * V_125 ;
struct V_30 * V_157 ;
unsigned long V_158 , V_159 ;
void * V_126 ;
V_7 |= V_160 ;
V_8 = ( unsigned long ) V_108 -> V_119 ;
F_70 ( V_8 , & V_157 , & V_158 ) ;
V_159 = F_75 ( V_157 , V_158 , V_45 -> V_13 ) ;
V_126 = F_90 ( V_157 ) ;
V_125 = (struct V_124 * ) V_126 + V_159 / sizeof( * V_125 ) ;
V_108 -> V_119 = V_125 -> V_97 ;
if ( ! V_45 -> V_113 )
V_125 -> V_7 = V_7 ;
else
F_83 ( V_108 , V_7 ) ;
F_91 ( V_126 ) ;
V_108 -> V_84 ++ ;
F_37 ( V_45 , V_74 , 1 ) ;
return V_8 ;
}
unsigned long F_15 ( struct V_1 * V_2 , T_2 V_13 )
{
unsigned long V_7 , V_8 ;
struct V_44 * V_45 ;
struct V_30 * V_108 ;
if ( F_98 ( ! V_13 || V_13 > V_137 ) )
return 0 ;
V_7 = F_5 ( V_2 ) ;
if ( ! V_7 )
return 0 ;
V_13 += V_4 ;
V_45 = V_2 -> V_44 [ F_33 ( V_13 ) ] ;
F_47 ( & V_45 -> V_70 ) ;
V_108 = F_99 ( V_45 ) ;
if ( ! V_108 ) {
F_48 ( & V_45 -> V_70 ) ;
V_108 = F_92 ( V_45 , V_2 -> V_5 ) ;
if ( F_98 ( ! V_108 ) ) {
F_7 ( V_2 , V_7 ) ;
return 0 ;
}
F_32 ( V_108 , V_45 -> V_69 , V_88 ) ;
F_132 ( V_45 -> V_28 ,
& V_2 -> V_156 ) ;
F_47 ( & V_45 -> V_70 ) ;
F_37 ( V_45 , V_73 , F_25 (
V_45 -> V_13 , V_45 -> V_28 ) ) ;
}
V_8 = F_131 ( V_108 , V_45 , V_7 ) ;
F_63 ( V_45 , V_108 ) ;
F_9 ( V_7 , V_8 ) ;
F_48 ( & V_45 -> V_70 ) ;
return V_7 ;
}
static void F_133 ( struct V_1 * V_2 , struct V_44 * V_45 ,
unsigned long V_8 )
{
struct V_124 * V_125 ;
struct V_30 * V_108 , * V_161 ;
unsigned long V_162 , V_163 ;
void * V_126 ;
int V_31 ;
enum V_32 V_33 ;
F_31 ( ! V_8 ) ;
V_8 &= ~ V_160 ;
F_70 ( V_8 , & V_161 , & V_162 ) ;
V_108 = F_65 ( V_161 ) ;
F_30 ( V_108 , & V_31 , & V_33 ) ;
V_163 = F_75 ( V_161 , V_162 , V_45 -> V_13 ) ;
V_126 = F_90 ( V_161 ) ;
V_125 = (struct V_124 * ) ( V_126 + V_163 ) ;
V_125 -> V_97 = V_108 -> V_119 ;
if ( V_45 -> V_113 )
F_83 ( V_108 , 0 ) ;
F_91 ( V_126 ) ;
V_108 -> V_119 = ( void * ) V_8 ;
V_108 -> V_84 -- ;
F_38 ( V_45 , V_74 , 1 ) ;
}
void F_17 ( struct V_1 * V_2 , unsigned long V_7 )
{
struct V_30 * V_108 , * V_161 ;
unsigned long V_8 , V_162 ;
int V_31 ;
struct V_44 * V_45 ;
enum V_32 V_33 ;
if ( F_98 ( ! V_7 ) )
return;
F_78 ( V_7 ) ;
V_8 = F_72 ( V_7 ) ;
F_70 ( V_8 , & V_161 , & V_162 ) ;
V_108 = F_65 ( V_161 ) ;
F_30 ( V_108 , & V_31 , & V_33 ) ;
V_45 = V_2 -> V_44 [ V_31 ] ;
F_47 ( & V_45 -> V_70 ) ;
F_133 ( V_2 , V_45 , V_8 ) ;
V_33 = F_63 ( V_45 , V_108 ) ;
if ( V_33 == V_88 ) {
F_38 ( V_45 , V_73 , F_25 (
V_45 -> V_13 , V_45 -> V_28 ) ) ;
F_134 ( V_45 -> V_28 ,
& V_2 -> V_156 ) ;
F_85 ( V_108 ) ;
}
F_48 ( & V_45 -> V_70 ) ;
F_79 ( V_7 ) ;
F_7 ( V_2 , V_7 ) ;
}
static void F_135 ( unsigned long V_164 , unsigned long V_165 ,
struct V_44 * V_45 )
{
struct V_30 * V_166 , * V_167 ;
unsigned long V_168 , V_169 ;
unsigned long V_170 , V_171 ;
void * V_172 , * V_173 ;
int V_174 , V_175 , V_13 ;
int V_176 = 0 ;
V_174 = V_175 = V_45 -> V_13 ;
F_70 ( V_164 , & V_166 , & V_168 ) ;
F_70 ( V_165 , & V_167 , & V_169 ) ;
V_170 = F_75 ( V_166 , V_168 , V_45 -> V_13 ) ;
V_171 = F_75 ( V_167 , V_169 , V_45 -> V_13 ) ;
if ( V_170 + V_45 -> V_13 > V_29 )
V_174 = V_29 - V_170 ;
if ( V_171 + V_45 -> V_13 > V_29 )
V_175 = V_29 - V_171 ;
V_172 = F_90 ( V_166 ) ;
V_173 = F_90 ( V_167 ) ;
while ( 1 ) {
V_13 = F_36 ( V_174 , V_175 ) ;
memcpy ( V_173 + V_171 , V_172 + V_170 , V_13 ) ;
V_176 += V_13 ;
if ( V_176 == V_45 -> V_13 )
break;
V_170 += V_13 ;
V_174 -= V_13 ;
V_171 += V_13 ;
V_175 -= V_13 ;
if ( V_170 >= V_29 ) {
F_91 ( V_173 ) ;
F_91 ( V_172 ) ;
V_166 = F_66 ( V_166 ) ;
F_31 ( ! V_166 ) ;
V_172 = F_90 ( V_166 ) ;
V_173 = F_90 ( V_167 ) ;
V_174 = V_45 -> V_13 - V_176 ;
V_170 = 0 ;
}
if ( V_171 >= V_29 ) {
F_91 ( V_173 ) ;
V_167 = F_66 ( V_167 ) ;
F_31 ( ! V_167 ) ;
V_173 = F_90 ( V_167 ) ;
V_175 = V_45 -> V_13 - V_176 ;
V_171 = 0 ;
}
}
F_91 ( V_173 ) ;
F_91 ( V_172 ) ;
}
static unsigned long F_136 ( struct V_30 * V_30 , int V_69 ,
struct V_44 * V_45 )
{
unsigned long V_93 ;
int V_177 = 0 ;
unsigned long V_7 = 0 ;
void * V_135 = F_90 ( V_30 ) ;
if ( ! F_26 ( V_30 ) )
V_177 = V_30 -> V_69 ;
V_177 += V_45 -> V_13 * V_69 ;
while ( V_177 < V_29 ) {
V_93 = F_73 ( V_45 , V_30 , V_135 + V_177 ) ;
if ( V_93 & V_160 ) {
V_7 = V_93 & ~ V_160 ;
if ( F_76 ( V_7 ) )
break;
V_7 = 0 ;
}
V_177 += V_45 -> V_13 ;
V_69 ++ ;
}
F_91 ( V_135 ) ;
return V_7 ;
}
static int F_137 ( struct V_1 * V_2 , struct V_44 * V_45 ,
struct V_178 * V_179 )
{
unsigned long V_180 , V_181 ;
unsigned long V_7 ;
struct V_30 * V_166 = V_179 -> V_166 ;
struct V_30 * V_167 = V_179 -> V_167 ;
unsigned long V_69 = V_179 -> V_69 ;
int V_182 = 0 ;
int V_146 = 0 ;
while ( 1 ) {
V_7 = F_136 ( V_166 , V_69 , V_45 ) ;
if ( ! V_7 ) {
V_166 = F_66 ( V_166 ) ;
if ( ! V_166 )
break;
V_69 = 0 ;
continue;
}
if ( F_125 ( V_167 ) ) {
F_79 ( V_7 ) ;
V_146 = - V_52 ;
break;
}
V_180 = F_72 ( V_7 ) ;
V_181 = F_131 ( V_167 , V_45 , V_7 ) ;
F_135 ( V_180 , V_181 , V_45 ) ;
V_69 ++ ;
F_9 ( V_7 , V_181 ) ;
F_79 ( V_7 ) ;
F_133 ( V_2 , V_45 , V_180 ) ;
V_182 ++ ;
}
V_179 -> V_166 = V_166 ;
V_179 -> V_69 = V_69 ;
V_179 -> V_182 = V_182 ;
return V_146 ;
}
static struct V_30 * F_138 ( struct V_44 * V_45 )
{
int V_56 ;
struct V_30 * V_30 ;
for ( V_56 = 0 ; V_56 < V_94 ; V_56 ++ ) {
V_30 = V_45 -> V_95 [ V_56 ] ;
if ( V_30 ) {
F_59 ( V_30 , V_45 , V_56 ) ;
break;
}
}
return V_30 ;
}
static void F_139 ( struct V_1 * V_2 , struct V_44 * V_45 ,
struct V_30 * V_108 )
{
enum V_32 V_33 ;
F_31 ( ! F_26 ( V_108 ) ) ;
V_33 = F_56 ( V_108 ) ;
F_57 ( V_108 , V_45 , V_33 ) ;
F_32 ( V_108 , V_45 -> V_69 , V_33 ) ;
if ( V_33 == V_88 ) {
F_38 ( V_45 , V_73 , F_25 (
V_45 -> V_13 , V_45 -> V_28 ) ) ;
F_134 ( V_45 -> V_28 ,
& V_2 -> V_156 ) ;
F_85 ( V_108 ) ;
}
}
static struct V_30 * F_140 ( struct V_44 * V_45 )
{
struct V_30 * V_30 ;
V_30 = V_45 -> V_95 [ V_91 ] ;
if ( V_30 )
F_59 ( V_30 , V_45 , V_91 ) ;
return V_30 ;
}
static unsigned long F_141 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
int V_183 ;
struct V_178 V_179 ;
struct V_30 * V_184 ;
struct V_30 * V_185 = NULL ;
unsigned long V_186 = 0 ;
F_47 ( & V_45 -> V_70 ) ;
while ( ( V_184 = F_140 ( V_45 ) ) ) {
F_31 ( ! F_26 ( V_184 ) ) ;
V_183 = V_184 -> V_84 ;
V_179 . V_69 = 0 ;
V_179 . V_166 = V_184 ;
while ( ( V_185 = F_138 ( V_45 ) ) ) {
V_179 . V_167 = V_185 ;
if ( ! F_137 ( V_2 , V_45 , & V_179 ) )
break;
F_139 ( V_2 , V_45 , V_185 ) ;
V_186 += V_179 . V_182 ;
V_183 -= V_179 . V_182 ;
}
if ( V_185 == NULL )
break;
F_139 ( V_2 , V_45 , V_185 ) ;
F_139 ( V_2 , V_45 , V_184 ) ;
F_48 ( & V_45 -> V_70 ) ;
V_186 += V_179 . V_182 ;
F_142 () ;
F_47 ( & V_45 -> V_70 ) ;
}
if ( V_184 )
F_139 ( V_2 , V_45 , V_184 ) ;
F_48 ( & V_45 -> V_70 ) ;
return V_186 ;
}
unsigned long F_143 ( struct V_1 * V_2 )
{
int V_56 ;
unsigned long V_182 = 0 ;
struct V_44 * V_45 ;
for ( V_56 = V_43 - 1 ; V_56 >= 0 ; V_56 -- ) {
V_45 = V_2 -> V_44 [ V_56 ] ;
if ( ! V_45 )
continue;
if ( V_45 -> V_69 != V_56 )
continue;
V_182 += F_141 ( V_2 , V_45 ) ;
}
return V_182 ;
}
struct V_1 * F_11 ( char * V_9 , T_1 V_5 )
{
int V_56 ;
struct V_1 * V_2 ;
struct V_44 * V_187 = NULL ;
V_2 = F_144 ( sizeof( * V_2 ) , V_138 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_44 = F_145 ( V_43 , sizeof( struct V_44 * ) ,
V_138 ) ;
if ( ! V_2 -> V_44 ) {
F_109 ( V_2 ) ;
return NULL ;
}
V_2 -> V_9 = F_146 ( V_9 , V_138 ) ;
if ( ! V_2 -> V_9 )
goto V_188;
if ( F_1 ( V_2 ) )
goto V_188;
for ( V_56 = V_43 - 1 ; V_56 >= 0 ; V_56 -- ) {
int V_13 ;
int V_28 ;
struct V_44 * V_45 ;
V_13 = V_41 + V_56 * V_42 ;
if ( V_13 > V_137 )
V_13 = V_137 ;
V_28 = F_64 ( V_13 ) ;
if ( V_187 ) {
if ( F_124 ( V_187 , V_13 , V_28 ) ) {
V_2 -> V_44 [ V_56 ] = V_187 ;
continue;
}
}
V_45 = F_144 ( sizeof( struct V_44 ) , V_138 ) ;
if ( ! V_45 )
goto V_188;
V_45 -> V_13 = V_13 ;
V_45 -> V_69 = V_56 ;
V_45 -> V_28 = V_28 ;
if ( V_28 == 1 &&
F_25 ( V_13 , V_28 ) == 1 )
V_45 -> V_113 = true ;
F_147 ( & V_45 -> V_70 ) ;
V_2 -> V_44 [ V_56 ] = V_45 ;
V_187 = V_45 ;
}
V_2 -> V_5 = V_5 ;
if ( F_52 ( V_9 , V_2 ) )
goto V_188;
return V_2 ;
V_188:
F_13 ( V_2 ) ;
return NULL ;
}
void F_13 ( struct V_1 * V_2 )
{
int V_56 ;
F_55 ( V_2 ) ;
for ( V_56 = 0 ; V_56 < V_43 ; V_56 ++ ) {
int V_86 ;
struct V_44 * V_45 = V_2 -> V_44 [ V_56 ] ;
if ( ! V_45 )
continue;
if ( V_45 -> V_69 != V_56 )
continue;
for ( V_86 = 0 ; V_86 < V_94 ; V_86 ++ ) {
if ( V_45 -> V_95 [ V_86 ] ) {
F_148 ( L_20 ,
V_45 -> V_13 , V_86 ) ;
}
}
F_109 ( V_45 ) ;
}
F_3 ( V_2 ) ;
F_109 ( V_2 -> V_44 ) ;
F_109 ( V_2 -> V_9 ) ;
F_109 ( V_2 ) ;
}
static int T_4 F_149 ( void )
{
int V_146 = F_115 () ;
if ( V_146 )
goto V_189;
F_123 () ;
#ifdef F_150
F_151 ( & V_190 ) ;
#endif
V_146 = F_40 () ;
if ( V_146 ) {
F_152 ( L_21 ) ;
goto V_191;
}
return 0 ;
V_191:
#ifdef F_150
F_153 ( & V_190 ) ;
#endif
V_189:
F_121 () ;
return V_146 ;
}
static void T_5 F_154 ( void )
{
#ifdef F_150
F_153 ( & V_190 ) ;
#endif
F_121 () ;
F_43 () ;
}
