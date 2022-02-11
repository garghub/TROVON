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
static unsigned long F_5 ( struct V_1 * V_2 , T_1 V_5 )
{
return ( unsigned long ) F_6 ( V_2 -> V_3 ,
V_5 & ~ V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned long V_7 )
{
F_8 ( V_2 -> V_3 , ( void * ) V_7 ) ;
}
static void F_9 ( unsigned long V_7 , unsigned long V_8 )
{
F_10 ( * ( unsigned long * ) V_7 , V_8 ) ;
}
static void * F_11 ( const char * V_9 , T_1 V_5 ,
const struct V_10 * V_10 ,
struct V_11 * V_11 )
{
return F_12 ( V_9 ) ;
}
static void F_13 ( void * V_2 )
{
F_14 ( V_2 ) ;
}
static int F_15 ( void * V_2 , T_2 V_12 , T_1 V_5 ,
unsigned long * V_7 )
{
* V_7 = F_16 ( V_2 , V_12 , V_5 ) ;
return * V_7 ? 0 : - 1 ;
}
static void F_17 ( void * V_2 , unsigned long V_7 )
{
F_18 ( V_2 , V_7 ) ;
}
static int F_19 ( void * V_2 , unsigned int V_13 ,
unsigned int * V_14 )
{
return - V_15 ;
}
static void * F_20 ( void * V_2 , unsigned long V_7 ,
enum V_16 V_17 )
{
enum V_18 V_19 ;
switch ( V_17 ) {
case V_20 :
V_19 = V_21 ;
break;
case V_22 :
V_19 = V_23 ;
break;
case V_24 :
default:
V_19 = V_25 ;
break;
}
return F_21 ( V_2 , V_7 , V_19 ) ;
}
static void F_22 ( void * V_2 , unsigned long V_7 )
{
F_23 ( V_2 , V_7 ) ;
}
static T_3 F_24 ( void * V_2 )
{
return F_25 ( V_2 ) << V_26 ;
}
static unsigned int F_26 ( int V_12 , int V_27 )
{
return V_27 * V_28 / V_12 ;
}
static int F_27 ( struct V_29 * V_29 )
{
return F_28 ( V_29 ) ;
}
static int F_29 ( struct V_29 * V_29 )
{
return F_30 ( V_29 ) ;
}
static void F_31 ( struct V_29 * V_30 ,
unsigned int * V_31 ,
enum V_32 * V_33 )
{
unsigned long V_34 ;
F_32 ( ! F_27 ( V_30 ) , V_30 ) ;
V_34 = ( unsigned long ) V_30 -> V_35 ;
* V_33 = V_34 & V_36 ;
* V_31 = ( V_34 >> V_37 ) & V_38 ;
}
static void F_33 ( struct V_29 * V_30 ,
unsigned int V_31 ,
enum V_32 V_33 )
{
unsigned long V_34 ;
F_32 ( ! F_27 ( V_30 ) , V_30 ) ;
V_34 = ( ( V_31 & V_38 ) << V_37 ) |
( V_33 & V_36 ) ;
V_30 -> V_35 = (struct V_39 * ) V_34 ;
}
static int F_34 ( int V_12 )
{
int V_40 = 0 ;
if ( F_35 ( V_12 > V_41 ) )
V_40 = F_36 ( V_12 - V_41 ,
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
static void T_4 F_41 ( void )
{
if ( ! F_42 () ) {
F_43 ( L_2 ) ;
return;
}
V_51 = F_44 ( L_3 , NULL ) ;
if ( ! V_51 )
F_43 ( L_4 ) ;
}
static void T_5 F_45 ( void )
{
F_46 ( V_51 ) ;
}
static int F_47 ( struct V_52 * V_53 , void * V_54 )
{
int V_55 ;
struct V_1 * V_2 = V_53 -> V_56 ;
struct V_44 * V_45 ;
int V_57 ;
unsigned long V_58 , V_59 ;
unsigned long V_60 , V_61 , V_62 , V_63 ;
unsigned long V_64 = 0 , V_65 = 0 ;
unsigned long V_66 = 0 , V_67 = 0 , V_68 = 0 ;
unsigned long V_69 = 0 ;
F_48 ( V_53 , L_5 ,
L_6 , L_7 , L_8 , L_9 ,
L_10 , L_11 , L_12 ,
L_13 , L_14 ) ;
for ( V_55 = 0 ; V_55 < V_43 ; V_55 ++ ) {
V_45 = V_2 -> V_44 [ V_55 ] ;
if ( V_45 -> V_70 != V_55 )
continue;
F_49 ( & V_45 -> V_71 ) ;
V_58 = F_40 ( V_45 , V_72 ) ;
V_59 = F_40 ( V_45 , V_73 ) ;
V_60 = F_40 ( V_45 , V_74 ) ;
V_61 = F_40 ( V_45 , V_75 ) ;
V_63 = F_50 ( V_45 ) ;
F_51 ( & V_45 -> V_71 ) ;
V_57 = F_26 ( V_45 -> V_12 ,
V_45 -> V_27 ) ;
V_62 = V_60 / V_57 *
V_45 -> V_27 ;
F_48 ( V_53 , L_15
L_16 ,
V_55 , V_45 -> V_12 , V_58 , V_59 ,
V_60 , V_61 , V_62 ,
V_45 -> V_27 , V_63 ) ;
V_64 += V_58 ;
V_65 += V_59 ;
V_66 += V_60 ;
V_67 += V_61 ;
V_68 += V_62 ;
V_69 += V_63 ;
}
F_52 ( V_53 , L_17 ) ;
F_48 ( V_53 , L_18 ,
L_19 , L_20 , V_64 ,
V_65 , V_66 ,
V_67 , V_68 , L_20 , V_69 ) ;
return 0 ;
}
static int F_53 ( struct V_76 * V_76 , struct V_77 * V_77 )
{
return F_54 ( V_77 , F_47 , V_76 -> V_78 ) ;
}
static void F_55 ( struct V_1 * V_2 , const char * V_9 )
{
struct V_79 * V_80 ;
if ( ! V_51 ) {
F_43 ( L_21 , V_9 ) ;
return;
}
V_80 = F_44 ( V_9 , V_51 ) ;
if ( ! V_80 ) {
F_43 ( L_22 , V_9 ) ;
return;
}
V_2 -> V_81 = V_80 ;
V_80 = F_56 ( L_23 , V_82 | V_83 ,
V_2 -> V_81 , V_2 , & V_84 ) ;
if ( ! V_80 ) {
F_43 ( L_24 ,
V_9 , L_23 ) ;
F_46 ( V_2 -> V_81 ) ;
V_2 -> V_81 = NULL ;
}
}
static void F_57 ( struct V_1 * V_2 )
{
F_46 ( V_2 -> V_81 ) ;
}
static void T_4 F_41 ( void )
{
}
static void T_5 F_45 ( void )
{
}
static inline void F_55 ( struct V_1 * V_2 , const char * V_9 )
{
}
static inline void F_57 ( struct V_1 * V_2 )
{
}
static enum V_32 F_58 ( struct V_29 * V_30 )
{
int V_85 , V_86 ;
enum V_32 V_87 ;
F_32 ( ! F_27 ( V_30 ) , V_30 ) ;
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
static void F_59 ( struct V_44 * V_45 ,
enum V_32 V_33 ,
struct V_29 * V_30 )
{
struct V_29 * * V_94 ;
F_32 ( ! F_27 ( V_30 ) , V_30 ) ;
if ( V_33 >= V_95 )
return;
F_38 ( V_45 , V_33 == V_92 ?
V_73 : V_72 , 1 ) ;
V_94 = & V_45 -> V_96 [ V_33 ] ;
if ( ! * V_94 ) {
* V_94 = V_30 ;
return;
}
F_60 ( & V_30 -> V_97 , & ( * V_94 ) -> V_97 ) ;
if ( V_30 -> V_85 >= ( * V_94 ) -> V_85 )
* V_94 = V_30 ;
}
static void F_61 ( struct V_44 * V_45 ,
enum V_32 V_33 ,
struct V_29 * V_30 )
{
struct V_29 * * V_94 ;
F_32 ( ! F_27 ( V_30 ) , V_30 ) ;
if ( V_33 >= V_95 )
return;
V_94 = & V_45 -> V_96 [ V_33 ] ;
F_32 ( ! * V_94 , V_30 ) ;
if ( F_62 ( & ( * V_94 ) -> V_97 ) )
* V_94 = NULL ;
else if ( * V_94 == V_30 )
* V_94 = (struct V_29 * ) F_63 ( ( * V_94 ) -> V_97 . V_98 ,
struct V_29 , V_97 ) ;
F_64 ( & V_30 -> V_97 ) ;
F_39 ( V_45 , V_33 == V_92 ?
V_73 : V_72 , 1 ) ;
}
static enum V_32 F_65 ( struct V_44 * V_45 ,
struct V_29 * V_30 )
{
int V_31 ;
enum V_32 V_99 , V_100 ;
F_31 ( V_30 , & V_31 , & V_99 ) ;
V_100 = F_58 ( V_30 ) ;
if ( V_100 == V_99 )
goto V_101;
F_61 ( V_45 , V_99 , V_30 ) ;
F_59 ( V_45 , V_100 , V_30 ) ;
F_33 ( V_30 , V_31 , V_100 ) ;
V_101:
return V_100 ;
}
static int F_66 ( int V_102 )
{
int V_55 , V_103 = 0 ;
int V_104 = 1 ;
for ( V_55 = 1 ; V_55 <= V_105 ; V_55 ++ ) {
int V_106 ;
int V_107 , V_108 ;
V_106 = V_55 * V_28 ;
V_107 = V_106 % V_102 ;
V_108 = ( V_106 - V_107 ) * 100 / V_106 ;
if ( V_108 > V_103 ) {
V_103 = V_108 ;
V_104 = V_55 ;
}
}
return V_104 ;
}
static struct V_29 * F_67 ( struct V_29 * V_29 )
{
if ( F_27 ( V_29 ) )
return V_29 ;
else
return (struct V_29 * ) F_68 ( V_29 ) ;
}
static struct V_29 * F_69 ( struct V_29 * V_29 )
{
struct V_29 * V_98 ;
if ( F_29 ( V_29 ) )
V_98 = NULL ;
else if ( F_27 ( V_29 ) )
V_98 = (struct V_29 * ) F_68 ( V_29 ) ;
else
V_98 = F_63 ( V_29 -> V_97 . V_98 , struct V_29 , V_97 ) ;
return V_98 ;
}
static void * F_70 ( struct V_29 * V_29 , unsigned long V_109 )
{
unsigned long V_8 ;
if ( ! V_29 ) {
F_71 ( V_109 ) ;
return NULL ;
}
V_8 = F_72 ( V_29 ) << V_110 ;
V_8 |= ( ( V_109 ) & V_111 ) ;
V_8 <<= V_112 ;
return ( void * ) V_8 ;
}
static void F_73 ( unsigned long V_8 , struct V_29 * * V_29 ,
unsigned long * V_109 )
{
V_8 >>= V_112 ;
* V_29 = F_74 ( V_8 >> V_110 ) ;
* V_109 = ( V_8 & V_111 ) ;
}
static unsigned long F_75 ( unsigned long V_7 )
{
return * ( unsigned long * ) V_7 ;
}
static unsigned long F_76 ( struct V_44 * V_45 , struct V_29 * V_29 ,
void * V_8 )
{
if ( V_45 -> V_113 ) {
F_32 ( ! F_27 ( V_29 ) , V_29 ) ;
return F_68 ( V_29 ) ;
} else
return * ( unsigned long * ) V_8 ;
}
static unsigned long F_77 ( struct V_29 * V_29 ,
unsigned long V_109 , int V_102 )
{
unsigned long V_114 = 0 ;
if ( ! F_27 ( V_29 ) )
V_114 = V_29 -> V_70 ;
return V_114 + V_109 * V_102 ;
}
static inline int F_78 ( unsigned long V_7 )
{
unsigned long * V_115 = ( unsigned long * ) V_7 ;
return ! F_79 ( V_116 , V_115 ) ;
}
static void F_80 ( unsigned long V_7 )
{
while ( ! F_78 ( V_7 ) ) ;
}
static void F_81 ( unsigned long V_7 )
{
unsigned long * V_115 = ( unsigned long * ) V_7 ;
F_82 ( V_116 , V_115 ) ;
}
static void F_83 ( struct V_29 * V_29 )
{
F_84 ( V_117 , & V_29 -> V_118 ) ;
F_84 ( V_119 , & V_29 -> V_118 ) ;
F_85 ( V_29 , 0 ) ;
V_29 -> V_35 = NULL ;
V_29 -> V_120 = NULL ;
F_86 ( V_29 ) ;
}
static void F_87 ( struct V_29 * V_30 )
{
struct V_29 * V_121 , * V_122 , * V_123 ;
F_32 ( ! F_27 ( V_30 ) , V_30 ) ;
F_32 ( V_30 -> V_85 , V_30 ) ;
V_123 = (struct V_29 * ) F_68 ( V_30 ) ;
F_83 ( V_30 ) ;
F_88 ( V_30 ) ;
if ( ! V_123 )
return;
F_89 (nextp, tmp, &head_extra->lru, lru) {
F_90 ( & V_121 -> V_97 ) ;
F_83 ( V_121 ) ;
F_88 ( V_121 ) ;
}
F_83 ( V_123 ) ;
F_88 ( V_123 ) ;
}
static void F_91 ( struct V_44 * V_45 , struct V_29 * V_30 )
{
unsigned long V_114 = 0 ;
struct V_29 * V_29 = V_30 ;
F_32 ( ! F_27 ( V_30 ) , V_30 ) ;
while ( V_29 ) {
struct V_29 * V_124 ;
struct V_125 * V_126 ;
unsigned int V_55 = 1 ;
void * V_127 ;
if ( V_29 != V_30 )
V_29 -> V_70 = V_114 ;
V_127 = F_92 ( V_29 ) ;
V_126 = (struct V_125 * ) V_127 + V_114 / sizeof( * V_126 ) ;
while ( ( V_114 += V_45 -> V_12 ) < V_28 ) {
V_126 -> V_98 = F_70 ( V_29 , V_55 ++ ) ;
V_126 += V_45 -> V_12 / sizeof( * V_126 ) ;
}
V_124 = F_69 ( V_29 ) ;
V_126 -> V_98 = F_70 ( V_124 , 0 ) ;
F_93 ( V_127 ) ;
V_29 = V_124 ;
V_114 %= V_28 ;
}
}
static struct V_29 * F_94 ( struct V_44 * V_45 , T_1 V_118 )
{
int V_55 , error ;
struct V_29 * V_30 = NULL , * V_128 ( V_129 ) ;
error = - V_130 ;
for ( V_55 = 0 ; V_55 < V_45 -> V_27 ; V_55 ++ ) {
struct V_29 * V_29 ;
V_29 = F_95 ( V_118 ) ;
if ( ! V_29 )
goto V_131;
F_96 ( & V_29 -> V_97 ) ;
if ( V_55 == 0 ) {
F_97 ( V_29 ) ;
F_85 ( V_29 , 0 ) ;
V_30 = V_29 ;
V_30 -> V_85 = 0 ;
}
if ( V_55 == 1 )
F_85 ( V_30 , ( unsigned long ) V_29 ) ;
if ( V_55 >= 1 )
F_85 ( V_29 , ( unsigned long ) V_30 ) ;
if ( V_55 >= 2 )
F_98 ( & V_29 -> V_97 , & V_129 -> V_97 ) ;
if ( V_55 == V_45 -> V_27 - 1 )
F_99 ( V_29 ) ;
V_129 = V_29 ;
}
F_91 ( V_45 , V_30 ) ;
V_30 -> V_120 = F_70 ( V_30 , 0 ) ;
V_30 -> V_88 = V_45 -> V_27 * V_28 / V_45 -> V_12 ;
error = 0 ;
V_131:
if ( F_100 ( error ) && V_30 ) {
F_87 ( V_30 ) ;
V_30 = NULL ;
}
return V_30 ;
}
static struct V_29 * F_101 ( struct V_44 * V_45 )
{
int V_55 ;
struct V_29 * V_29 ;
for ( V_55 = 0 ; V_55 < V_95 ; V_55 ++ ) {
V_29 = V_45 -> V_96 [ V_55 ] ;
if ( V_29 )
break;
}
return V_29 ;
}
static inline int F_102 ( struct V_132 * V_133 )
{
if ( V_133 -> V_134 )
return 0 ;
V_133 -> V_134 = F_103 ( V_28 * 2 , NULL ) ;
if ( ! V_133 -> V_134 )
return - V_130 ;
return 0 ;
}
static inline void F_104 ( struct V_132 * V_133 )
{
if ( V_133 -> V_134 )
F_105 ( V_133 -> V_134 ) ;
V_133 -> V_134 = NULL ;
}
static inline void * F_106 ( struct V_132 * V_133 ,
struct V_29 * V_13 [ 2 ] , int V_114 , int V_12 )
{
F_107 ( F_108 ( V_133 -> V_134 , V_135 , V_13 ) ) ;
V_133 -> V_136 = V_133 -> V_134 -> V_137 ;
return V_133 -> V_136 + V_114 ;
}
static inline void F_109 ( struct V_132 * V_133 ,
struct V_29 * V_13 [ 2 ] , int V_114 , int V_12 )
{
unsigned long V_137 = ( unsigned long ) V_133 -> V_136 ;
F_110 ( V_137 , V_28 * 2 ) ;
}
static inline int F_102 ( struct V_132 * V_133 )
{
if ( V_133 -> V_138 )
return 0 ;
V_133 -> V_138 = F_111 ( V_139 , V_140 ) ;
if ( ! V_133 -> V_138 )
return - V_130 ;
return 0 ;
}
static inline void F_104 ( struct V_132 * V_133 )
{
F_112 ( V_133 -> V_138 ) ;
V_133 -> V_138 = NULL ;
}
static void * F_106 ( struct V_132 * V_133 ,
struct V_29 * V_13 [ 2 ] , int V_114 , int V_12 )
{
int V_141 [ 2 ] ;
void * V_137 ;
char * V_142 = V_133 -> V_138 ;
F_113 () ;
if ( V_133 -> V_143 == V_23 )
goto V_101;
V_141 [ 0 ] = V_28 - V_114 ;
V_141 [ 1 ] = V_12 - V_141 [ 0 ] ;
V_137 = F_92 ( V_13 [ 0 ] ) ;
memcpy ( V_142 , V_137 + V_114 , V_141 [ 0 ] ) ;
F_93 ( V_137 ) ;
V_137 = F_92 ( V_13 [ 1 ] ) ;
memcpy ( V_142 + V_141 [ 0 ] , V_137 , V_141 [ 1 ] ) ;
F_93 ( V_137 ) ;
V_101:
return V_133 -> V_138 ;
}
static void F_109 ( struct V_132 * V_133 ,
struct V_29 * V_13 [ 2 ] , int V_114 , int V_12 )
{
int V_141 [ 2 ] ;
void * V_137 ;
char * V_142 ;
if ( V_133 -> V_143 == V_21 )
goto V_101;
V_142 = V_133 -> V_138 ;
V_142 = V_142 + V_4 ;
V_12 -= V_4 ;
V_114 += V_4 ;
V_141 [ 0 ] = V_28 - V_114 ;
V_141 [ 1 ] = V_12 - V_141 [ 0 ] ;
V_137 = F_92 ( V_13 [ 0 ] ) ;
memcpy ( V_137 + V_114 , V_142 , V_141 [ 0 ] ) ;
F_93 ( V_137 ) ;
V_137 = F_92 ( V_13 [ 1 ] ) ;
memcpy ( V_137 , V_142 + V_141 [ 0 ] , V_141 [ 1 ] ) ;
F_93 ( V_137 ) ;
V_101:
F_114 () ;
}
static int F_115 ( struct V_144 * V_145 , unsigned long V_146 ,
void * V_147 )
{
int V_148 , V_149 = ( long ) V_147 ;
struct V_132 * V_133 ;
switch ( V_146 ) {
case V_150 :
V_133 = & F_116 ( V_151 , V_149 ) ;
V_148 = F_102 ( V_133 ) ;
if ( V_148 )
return F_117 ( V_148 ) ;
break;
case V_152 :
case V_153 :
V_133 = & F_116 ( V_151 , V_149 ) ;
F_104 ( V_133 ) ;
break;
}
return V_154 ;
}
static int F_118 ( void )
{
int V_149 , V_128 ( V_148 ) ;
F_119 () ;
F_120 ( & V_155 ) ;
F_121 (cpu) {
V_148 = F_115 ( NULL , V_150 , ( void * ) ( long ) V_149 ) ;
if ( F_122 ( V_148 ) )
break;
}
F_123 () ;
return F_122 ( V_148 ) ;
}
static void F_124 ( void )
{
int V_149 ;
F_119 () ;
F_121 (cpu)
F_115 ( NULL , V_152 , ( void * ) ( long ) V_149 ) ;
F_125 ( & V_155 ) ;
F_123 () ;
}
static void F_126 ( void )
{
int V_156 ;
V_156 = ( V_139 - V_41 ) / V_42 + 1 ;
if ( ( V_139 - V_41 ) % V_42 )
V_156 += 1 ;
V_43 = V_156 ;
}
static bool F_127 ( struct V_44 * V_157 , int V_12 , int V_27 )
{
if ( V_157 -> V_27 != V_27 )
return false ;
if ( F_26 ( V_157 -> V_12 , V_157 -> V_27 )
!= F_26 ( V_12 , V_27 ) )
return false ;
return true ;
}
static bool F_128 ( struct V_29 * V_30 )
{
F_32 ( ! F_27 ( V_30 ) , V_30 ) ;
return V_30 -> V_85 == V_30 -> V_88 ;
}
unsigned long F_25 ( struct V_1 * V_2 )
{
return F_129 ( & V_2 -> V_158 ) ;
}
void * F_21 ( struct V_1 * V_2 , unsigned long V_7 ,
enum V_18 V_17 )
{
struct V_29 * V_29 ;
unsigned long V_8 , V_109 , V_114 ;
unsigned int V_31 ;
enum V_32 V_87 ;
struct V_44 * V_45 ;
struct V_132 * V_133 ;
struct V_29 * V_13 [ 2 ] ;
void * V_148 ;
F_130 ( F_131 () ) ;
F_80 ( V_7 ) ;
V_8 = F_75 ( V_7 ) ;
F_73 ( V_8 , & V_29 , & V_109 ) ;
F_31 ( F_67 ( V_29 ) , & V_31 , & V_87 ) ;
V_45 = V_2 -> V_44 [ V_31 ] ;
V_114 = F_77 ( V_29 , V_109 , V_45 -> V_12 ) ;
V_133 = & F_132 ( V_151 ) ;
V_133 -> V_143 = V_17 ;
if ( V_114 + V_45 -> V_12 <= V_28 ) {
V_133 -> V_136 = F_92 ( V_29 ) ;
V_148 = V_133 -> V_136 + V_114 ;
goto V_101;
}
V_13 [ 0 ] = V_29 ;
V_13 [ 1 ] = F_69 ( V_29 ) ;
F_107 ( ! V_13 [ 1 ] ) ;
V_148 = F_106 ( V_133 , V_13 , V_114 , V_45 -> V_12 ) ;
V_101:
if ( ! V_45 -> V_113 )
V_148 += V_4 ;
return V_148 ;
}
void F_23 ( struct V_1 * V_2 , unsigned long V_7 )
{
struct V_29 * V_29 ;
unsigned long V_8 , V_109 , V_114 ;
unsigned int V_31 ;
enum V_32 V_87 ;
struct V_44 * V_45 ;
struct V_132 * V_133 ;
V_8 = F_75 ( V_7 ) ;
F_73 ( V_8 , & V_29 , & V_109 ) ;
F_31 ( F_67 ( V_29 ) , & V_31 , & V_87 ) ;
V_45 = V_2 -> V_44 [ V_31 ] ;
V_114 = F_77 ( V_29 , V_109 , V_45 -> V_12 ) ;
V_133 = F_133 ( & V_151 ) ;
if ( V_114 + V_45 -> V_12 <= V_28 )
F_93 ( V_133 -> V_136 ) ;
else {
struct V_29 * V_13 [ 2 ] ;
V_13 [ 0 ] = V_29 ;
V_13 [ 1 ] = F_69 ( V_29 ) ;
F_107 ( ! V_13 [ 1 ] ) ;
F_109 ( V_133 , V_13 , V_114 , V_45 -> V_12 ) ;
}
F_134 ( V_151 ) ;
F_81 ( V_7 ) ;
}
static unsigned long F_135 ( struct V_44 * V_45 ,
struct V_29 * V_30 , unsigned long V_7 )
{
unsigned long V_8 ;
struct V_125 * V_126 ;
struct V_29 * V_159 ;
unsigned long V_160 , V_161 ;
void * V_127 ;
V_7 |= V_162 ;
V_8 = ( unsigned long ) V_30 -> V_120 ;
F_73 ( V_8 , & V_159 , & V_160 ) ;
V_161 = F_77 ( V_159 , V_160 , V_45 -> V_12 ) ;
V_127 = F_92 ( V_159 ) ;
V_126 = (struct V_125 * ) V_127 + V_161 / sizeof( * V_126 ) ;
V_30 -> V_120 = V_126 -> V_98 ;
if ( ! V_45 -> V_113 )
V_126 -> V_7 = V_7 ;
else
F_85 ( V_30 , V_7 ) ;
F_93 ( V_127 ) ;
V_30 -> V_85 ++ ;
F_38 ( V_45 , V_75 , 1 ) ;
return V_8 ;
}
unsigned long F_16 ( struct V_1 * V_2 , T_2 V_12 , T_1 V_5 )
{
unsigned long V_7 , V_8 ;
struct V_44 * V_45 ;
struct V_29 * V_30 ;
if ( F_100 ( ! V_12 || V_12 > V_139 ) )
return 0 ;
V_7 = F_5 ( V_2 , V_5 ) ;
if ( ! V_7 )
return 0 ;
V_12 += V_4 ;
V_45 = V_2 -> V_44 [ F_34 ( V_12 ) ] ;
F_49 ( & V_45 -> V_71 ) ;
V_30 = F_101 ( V_45 ) ;
if ( ! V_30 ) {
F_51 ( & V_45 -> V_71 ) ;
V_30 = F_94 ( V_45 , V_5 ) ;
if ( F_100 ( ! V_30 ) ) {
F_7 ( V_2 , V_7 ) ;
return 0 ;
}
F_33 ( V_30 , V_45 -> V_70 , V_89 ) ;
F_136 ( V_45 -> V_27 ,
& V_2 -> V_158 ) ;
F_49 ( & V_45 -> V_71 ) ;
F_38 ( V_45 , V_74 , F_26 (
V_45 -> V_12 , V_45 -> V_27 ) ) ;
}
V_8 = F_135 ( V_45 , V_30 , V_7 ) ;
F_65 ( V_45 , V_30 ) ;
F_9 ( V_7 , V_8 ) ;
F_51 ( & V_45 -> V_71 ) ;
return V_7 ;
}
static void F_137 ( struct V_44 * V_45 , unsigned long V_8 )
{
struct V_125 * V_126 ;
struct V_29 * V_30 , * V_163 ;
unsigned long V_164 , V_165 ;
void * V_127 ;
V_8 &= ~ V_162 ;
F_73 ( V_8 , & V_163 , & V_164 ) ;
V_30 = F_67 ( V_163 ) ;
V_165 = F_77 ( V_163 , V_164 , V_45 -> V_12 ) ;
V_127 = F_92 ( V_163 ) ;
V_126 = (struct V_125 * ) ( V_127 + V_165 ) ;
V_126 -> V_98 = V_30 -> V_120 ;
if ( V_45 -> V_113 )
F_85 ( V_30 , 0 ) ;
F_93 ( V_127 ) ;
V_30 -> V_120 = ( void * ) V_8 ;
V_30 -> V_85 -- ;
F_39 ( V_45 , V_75 , 1 ) ;
}
void F_18 ( struct V_1 * V_2 , unsigned long V_7 )
{
struct V_29 * V_30 , * V_163 ;
unsigned long V_8 , V_164 ;
int V_31 ;
struct V_44 * V_45 ;
enum V_32 V_33 ;
if ( F_100 ( ! V_7 ) )
return;
F_80 ( V_7 ) ;
V_8 = F_75 ( V_7 ) ;
F_73 ( V_8 , & V_163 , & V_164 ) ;
V_30 = F_67 ( V_163 ) ;
F_31 ( V_30 , & V_31 , & V_33 ) ;
V_45 = V_2 -> V_44 [ V_31 ] ;
F_49 ( & V_45 -> V_71 ) ;
F_137 ( V_45 , V_8 ) ;
V_33 = F_65 ( V_45 , V_30 ) ;
if ( V_33 == V_89 ) {
F_39 ( V_45 , V_74 , F_26 (
V_45 -> V_12 , V_45 -> V_27 ) ) ;
F_138 ( V_45 -> V_27 ,
& V_2 -> V_158 ) ;
F_87 ( V_30 ) ;
}
F_51 ( & V_45 -> V_71 ) ;
F_81 ( V_7 ) ;
F_7 ( V_2 , V_7 ) ;
}
static void F_139 ( struct V_44 * V_45 , unsigned long V_166 ,
unsigned long V_167 )
{
struct V_29 * V_168 , * V_169 ;
unsigned long V_170 , V_171 ;
unsigned long V_172 , V_173 ;
void * V_174 , * V_175 ;
int V_176 , V_177 , V_12 ;
int V_178 = 0 ;
V_176 = V_177 = V_45 -> V_12 ;
F_73 ( V_167 , & V_168 , & V_170 ) ;
F_73 ( V_166 , & V_169 , & V_171 ) ;
V_172 = F_77 ( V_168 , V_170 , V_45 -> V_12 ) ;
V_173 = F_77 ( V_169 , V_171 , V_45 -> V_12 ) ;
if ( V_172 + V_45 -> V_12 > V_28 )
V_176 = V_28 - V_172 ;
if ( V_173 + V_45 -> V_12 > V_28 )
V_177 = V_28 - V_173 ;
V_174 = F_92 ( V_168 ) ;
V_175 = F_92 ( V_169 ) ;
while ( 1 ) {
V_12 = F_37 ( V_176 , V_177 ) ;
memcpy ( V_175 + V_173 , V_174 + V_172 , V_12 ) ;
V_178 += V_12 ;
if ( V_178 == V_45 -> V_12 )
break;
V_172 += V_12 ;
V_176 -= V_12 ;
V_173 += V_12 ;
V_177 -= V_12 ;
if ( V_172 >= V_28 ) {
F_93 ( V_175 ) ;
F_93 ( V_174 ) ;
V_168 = F_69 ( V_168 ) ;
V_174 = F_92 ( V_168 ) ;
V_175 = F_92 ( V_169 ) ;
V_176 = V_45 -> V_12 - V_178 ;
V_172 = 0 ;
}
if ( V_173 >= V_28 ) {
F_93 ( V_175 ) ;
V_169 = F_69 ( V_169 ) ;
V_175 = F_92 ( V_169 ) ;
V_177 = V_45 -> V_12 - V_178 ;
V_173 = 0 ;
}
}
F_93 ( V_175 ) ;
F_93 ( V_174 ) ;
}
static unsigned long F_140 ( struct V_44 * V_45 ,
struct V_29 * V_29 , int V_70 )
{
unsigned long V_94 ;
int V_179 = 0 ;
unsigned long V_7 = 0 ;
void * V_137 = F_92 ( V_29 ) ;
if ( ! F_27 ( V_29 ) )
V_179 = V_29 -> V_70 ;
V_179 += V_45 -> V_12 * V_70 ;
while ( V_179 < V_28 ) {
V_94 = F_76 ( V_45 , V_29 , V_137 + V_179 ) ;
if ( V_94 & V_162 ) {
V_7 = V_94 & ~ V_162 ;
if ( F_78 ( V_7 ) )
break;
V_7 = 0 ;
}
V_179 += V_45 -> V_12 ;
V_70 ++ ;
}
F_93 ( V_137 ) ;
return V_7 ;
}
static int F_141 ( struct V_1 * V_2 , struct V_44 * V_45 ,
struct V_180 * V_181 )
{
unsigned long V_182 , V_183 ;
unsigned long V_7 ;
struct V_29 * V_168 = V_181 -> V_168 ;
struct V_29 * V_169 = V_181 -> V_169 ;
unsigned long V_70 = V_181 -> V_70 ;
int V_148 = 0 ;
while ( 1 ) {
V_7 = F_140 ( V_45 , V_168 , V_70 ) ;
if ( ! V_7 ) {
V_168 = F_69 ( V_168 ) ;
if ( ! V_168 )
break;
V_70 = 0 ;
continue;
}
if ( F_128 ( V_169 ) ) {
F_81 ( V_7 ) ;
V_148 = - V_130 ;
break;
}
V_182 = F_75 ( V_7 ) ;
V_183 = F_135 ( V_45 , V_169 , V_7 ) ;
F_139 ( V_45 , V_183 , V_182 ) ;
V_70 ++ ;
V_183 |= F_142 ( V_116 ) ;
F_9 ( V_7 , V_183 ) ;
F_81 ( V_7 ) ;
F_137 ( V_45 , V_182 ) ;
}
V_181 -> V_168 = V_168 ;
V_181 -> V_70 = V_70 ;
return V_148 ;
}
static struct V_29 * F_143 ( struct V_44 * V_45 )
{
int V_55 ;
struct V_29 * V_29 ;
for ( V_55 = 0 ; V_55 < V_95 ; V_55 ++ ) {
V_29 = V_45 -> V_96 [ V_55 ] ;
if ( V_29 ) {
F_61 ( V_45 , V_55 , V_29 ) ;
break;
}
}
return V_29 ;
}
static enum V_32 F_144 ( struct V_1 * V_2 ,
struct V_44 * V_45 ,
struct V_29 * V_30 )
{
enum V_32 V_33 ;
V_33 = F_58 ( V_30 ) ;
F_59 ( V_45 , V_33 , V_30 ) ;
F_33 ( V_30 , V_45 -> V_70 , V_33 ) ;
if ( V_33 == V_89 ) {
F_39 ( V_45 , V_74 , F_26 (
V_45 -> V_12 , V_45 -> V_27 ) ) ;
F_138 ( V_45 -> V_27 ,
& V_2 -> V_158 ) ;
F_87 ( V_30 ) ;
}
return V_33 ;
}
static struct V_29 * F_145 ( struct V_44 * V_45 )
{
int V_55 ;
struct V_29 * V_29 = NULL ;
for ( V_55 = V_92 ; V_55 >= V_93 ; V_55 -- ) {
V_29 = V_45 -> V_96 [ V_55 ] ;
if ( ! V_29 )
continue;
F_61 ( V_45 , V_55 , V_29 ) ;
break;
}
return V_29 ;
}
static unsigned long F_50 ( struct V_44 * V_45 )
{
unsigned long V_184 ;
unsigned long V_60 = F_40 ( V_45 , V_74 ) ;
unsigned long V_61 = F_40 ( V_45 , V_75 ) ;
if ( V_60 <= V_61 )
return 0 ;
V_184 = V_60 - V_61 ;
V_184 /= F_26 ( V_45 -> V_12 ,
V_45 -> V_27 ) ;
return V_184 * V_45 -> V_27 ;
}
static void F_146 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_180 V_181 ;
struct V_29 * V_185 ;
struct V_29 * V_186 = NULL ;
F_49 ( & V_45 -> V_71 ) ;
while ( ( V_185 = F_145 ( V_45 ) ) ) {
if ( ! F_50 ( V_45 ) )
break;
V_181 . V_70 = 0 ;
V_181 . V_168 = V_185 ;
while ( ( V_186 = F_143 ( V_45 ) ) ) {
V_181 . V_169 = V_186 ;
if ( ! F_141 ( V_2 , V_45 , & V_181 ) )
break;
F_144 ( V_2 , V_45 , V_186 ) ;
}
if ( V_186 == NULL )
break;
F_144 ( V_2 , V_45 , V_186 ) ;
if ( F_144 ( V_2 , V_45 , V_185 ) == V_89 )
V_2 -> V_49 . V_187 += V_45 -> V_27 ;
F_51 ( & V_45 -> V_71 ) ;
F_147 () ;
F_49 ( & V_45 -> V_71 ) ;
}
if ( V_185 )
F_144 ( V_2 , V_45 , V_185 ) ;
F_51 ( & V_45 -> V_71 ) ;
}
unsigned long F_148 ( struct V_1 * V_2 )
{
int V_55 ;
struct V_44 * V_45 ;
for ( V_55 = V_43 - 1 ; V_55 >= 0 ; V_55 -- ) {
V_45 = V_2 -> V_44 [ V_55 ] ;
if ( ! V_45 )
continue;
if ( V_45 -> V_70 != V_55 )
continue;
F_146 ( V_2 , V_45 ) ;
}
return V_2 -> V_49 . V_187 ;
}
void F_149 ( struct V_1 * V_2 , struct F_149 * V_49 )
{
memcpy ( V_49 , & V_2 -> V_49 , sizeof( struct F_149 ) ) ;
}
static unsigned long F_150 ( struct V_188 * V_188 ,
struct V_189 * V_190 )
{
unsigned long V_191 ;
struct V_1 * V_2 = F_151 ( V_188 , struct V_1 ,
V_188 ) ;
V_191 = V_2 -> V_49 . V_187 ;
V_191 = F_148 ( V_2 ) - V_191 ;
return V_191 ? V_191 : V_192 ;
}
static unsigned long F_152 ( struct V_188 * V_188 ,
struct V_189 * V_190 )
{
int V_55 ;
struct V_44 * V_45 ;
unsigned long V_193 = 0 ;
struct V_1 * V_2 = F_151 ( V_188 , struct V_1 ,
V_188 ) ;
for ( V_55 = V_43 - 1 ; V_55 >= 0 ; V_55 -- ) {
V_45 = V_2 -> V_44 [ V_55 ] ;
if ( ! V_45 )
continue;
if ( V_45 -> V_70 != V_55 )
continue;
V_193 += F_50 ( V_45 ) ;
}
return V_193 ;
}
static void F_153 ( struct V_1 * V_2 )
{
if ( V_2 -> V_194 ) {
F_154 ( & V_2 -> V_188 ) ;
V_2 -> V_194 = false ;
}
}
static int F_155 ( struct V_1 * V_2 )
{
V_2 -> V_188 . V_195 = F_150 ;
V_2 -> V_188 . V_196 = F_152 ;
V_2 -> V_188 . V_197 = 0 ;
V_2 -> V_188 . V_198 = V_199 ;
return F_156 ( & V_2 -> V_188 ) ;
}
struct V_1 * F_12 ( const char * V_9 )
{
int V_55 ;
struct V_1 * V_2 ;
struct V_44 * V_200 = NULL ;
V_2 = F_157 ( sizeof( * V_2 ) , V_140 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_44 = F_158 ( V_43 , sizeof( struct V_44 * ) ,
V_140 ) ;
if ( ! V_2 -> V_44 ) {
F_112 ( V_2 ) ;
return NULL ;
}
V_2 -> V_9 = F_159 ( V_9 , V_140 ) ;
if ( ! V_2 -> V_9 )
goto V_201;
if ( F_1 ( V_2 ) )
goto V_201;
for ( V_55 = V_43 - 1 ; V_55 >= 0 ; V_55 -- ) {
int V_12 ;
int V_27 ;
struct V_44 * V_45 ;
V_12 = V_41 + V_55 * V_42 ;
if ( V_12 > V_139 )
V_12 = V_139 ;
V_27 = F_66 ( V_12 ) ;
if ( V_200 ) {
if ( F_127 ( V_200 , V_12 , V_27 ) ) {
V_2 -> V_44 [ V_55 ] = V_200 ;
continue;
}
}
V_45 = F_157 ( sizeof( struct V_44 ) , V_140 ) ;
if ( ! V_45 )
goto V_201;
V_45 -> V_12 = V_12 ;
V_45 -> V_70 = V_55 ;
V_45 -> V_27 = V_27 ;
if ( V_27 == 1 &&
F_26 ( V_12 , V_27 ) == 1 )
V_45 -> V_113 = true ;
F_160 ( & V_45 -> V_71 ) ;
V_2 -> V_44 [ V_55 ] = V_45 ;
V_200 = V_45 ;
}
F_55 ( V_2 , V_9 ) ;
if ( F_155 ( V_2 ) == 0 )
V_2 -> V_194 = true ;
return V_2 ;
V_201:
F_14 ( V_2 ) ;
return NULL ;
}
void F_14 ( struct V_1 * V_2 )
{
int V_55 ;
F_153 ( V_2 ) ;
F_57 ( V_2 ) ;
for ( V_55 = 0 ; V_55 < V_43 ; V_55 ++ ) {
int V_87 ;
struct V_44 * V_45 = V_2 -> V_44 [ V_55 ] ;
if ( ! V_45 )
continue;
if ( V_45 -> V_70 != V_55 )
continue;
for ( V_87 = 0 ; V_87 < V_95 ; V_87 ++ ) {
if ( V_45 -> V_96 [ V_87 ] ) {
F_161 ( L_25 ,
V_45 -> V_12 , V_87 ) ;
}
}
F_112 ( V_45 ) ;
}
F_3 ( V_2 ) ;
F_112 ( V_2 -> V_44 ) ;
F_112 ( V_2 -> V_9 ) ;
F_112 ( V_2 ) ;
}
static int T_4 F_162 ( void )
{
int V_148 = F_118 () ;
if ( V_148 )
goto V_202;
F_126 () ;
#ifdef F_163
F_164 ( & V_203 ) ;
#endif
F_41 () ;
return 0 ;
V_202:
F_124 () ;
return V_148 ;
}
static void T_5 F_165 ( void )
{
#ifdef F_163
F_166 ( & V_203 ) ;
#endif
F_124 () ;
F_45 () ;
}
