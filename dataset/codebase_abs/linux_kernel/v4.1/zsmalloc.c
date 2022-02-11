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
static void * F_10 ( char * V_9 , T_1 V_10 , struct V_11 * V_11 )
{
return F_11 ( V_9 , V_10 ) ;
}
static void F_12 ( void * V_2 )
{
F_13 ( V_2 ) ;
}
static int F_14 ( void * V_2 , T_2 V_12 , T_1 V_10 ,
unsigned long * V_7 )
{
* V_7 = F_15 ( V_2 , V_12 ) ;
return * V_7 ? 0 : - 1 ;
}
static void F_16 ( void * V_2 , unsigned long V_7 )
{
F_17 ( V_2 , V_7 ) ;
}
static int F_18 ( void * V_2 , unsigned int V_13 ,
unsigned int * V_14 )
{
return - V_15 ;
}
static void * F_19 ( void * V_2 , unsigned long V_7 ,
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
return F_20 ( V_2 , V_7 , V_19 ) ;
}
static void F_21 ( void * V_2 , unsigned long V_7 )
{
F_22 ( V_2 , V_7 ) ;
}
static T_3 F_23 ( void * V_2 )
{
return F_24 ( V_2 ) << V_26 ;
}
static unsigned int F_25 ( int V_12 , int V_27 )
{
return V_27 * V_28 / V_12 ;
}
static int F_26 ( struct V_29 * V_29 )
{
return F_27 ( V_29 ) ;
}
static int F_28 ( struct V_29 * V_29 )
{
return F_29 ( V_29 ) ;
}
static void F_30 ( struct V_29 * V_29 , unsigned int * V_30 ,
enum V_31 * V_32 )
{
unsigned long V_33 ;
F_31 ( ! F_26 ( V_29 ) ) ;
V_33 = ( unsigned long ) V_29 -> V_34 ;
* V_32 = V_33 & V_35 ;
* V_30 = ( V_33 >> V_36 ) & V_37 ;
}
static void F_32 ( struct V_29 * V_29 , unsigned int V_30 ,
enum V_31 V_32 )
{
unsigned long V_33 ;
F_31 ( ! F_26 ( V_29 ) ) ;
V_33 = ( ( V_30 & V_37 ) << V_36 ) |
( V_32 & V_35 ) ;
V_29 -> V_34 = (struct V_38 * ) V_33 ;
}
static int F_33 ( int V_12 )
{
int V_39 = 0 ;
if ( F_34 ( V_12 > V_40 ) )
V_39 = F_35 ( V_12 - V_40 ,
V_41 ) ;
return F_36 ( V_42 - 1 , V_39 ) ;
}
static inline void F_37 ( struct V_43 * V_44 ,
enum V_45 type , unsigned long V_46 )
{
V_44 -> V_47 . V_48 [ type ] += V_46 ;
}
static inline void F_38 ( struct V_43 * V_44 ,
enum V_45 type , unsigned long V_46 )
{
V_44 -> V_47 . V_48 [ type ] -= V_46 ;
}
static inline unsigned long F_39 ( struct V_43 * V_44 ,
enum V_45 type )
{
return V_44 -> V_47 . V_48 [ type ] ;
}
static int T_4 F_40 ( void )
{
if ( ! F_41 () )
return - V_49 ;
V_50 = F_42 ( L_2 , NULL ) ;
if ( ! V_50 )
return - V_51 ;
return 0 ;
}
static void T_5 F_43 ( void )
{
F_44 ( V_50 ) ;
}
static int F_45 ( struct V_52 * V_53 , void * V_54 )
{
int V_55 ;
struct V_1 * V_2 = V_53 -> V_56 ;
struct V_43 * V_44 ;
int V_57 ;
unsigned long V_58 , V_59 ;
unsigned long V_60 , V_61 , V_62 ;
unsigned long V_63 = 0 , V_64 = 0 ;
unsigned long V_65 = 0 , V_66 = 0 , V_67 = 0 ;
F_46 ( V_53 , L_3 ,
L_4 , L_5 , L_6 , L_7 ,
L_8 , L_9 , L_10 ,
L_11 ) ;
for ( V_55 = 0 ; V_55 < V_42 ; V_55 ++ ) {
V_44 = V_2 -> V_43 [ V_55 ] ;
if ( V_44 -> V_68 != V_55 )
continue;
F_47 ( & V_44 -> V_69 ) ;
V_58 = F_39 ( V_44 , V_70 ) ;
V_59 = F_39 ( V_44 , V_71 ) ;
V_60 = F_39 ( V_44 , V_72 ) ;
V_61 = F_39 ( V_44 , V_73 ) ;
F_48 ( & V_44 -> V_69 ) ;
V_57 = F_25 ( V_44 -> V_12 ,
V_44 -> V_27 ) ;
V_62 = V_60 / V_57 *
V_44 -> V_27 ;
F_46 ( V_53 , L_12 ,
V_55 , V_44 -> V_12 , V_58 , V_59 ,
V_60 , V_61 , V_62 ,
V_44 -> V_27 ) ;
V_63 += V_58 ;
V_64 += V_59 ;
V_65 += V_60 ;
V_66 += V_61 ;
V_67 += V_62 ;
}
F_49 ( V_53 , L_13 ) ;
F_46 ( V_53 , L_14 ,
L_15 , L_16 , V_63 ,
V_64 , V_65 ,
V_66 , V_67 ) ;
return 0 ;
}
static int F_50 ( struct V_74 * V_74 , struct V_75 * V_75 )
{
return F_51 ( V_75 , F_45 , V_74 -> V_76 ) ;
}
static int F_52 ( char * V_9 , struct V_1 * V_2 )
{
struct V_77 * V_78 ;
if ( ! V_50 )
return - V_49 ;
V_78 = F_42 ( V_9 , V_50 ) ;
if ( ! V_78 ) {
F_53 ( L_17 , V_9 ) ;
return - V_51 ;
}
V_2 -> V_79 = V_78 ;
V_78 = F_54 ( L_18 , V_80 | V_81 ,
V_2 -> V_79 , V_2 , & V_82 ) ;
if ( ! V_78 ) {
F_53 ( L_19 ,
V_9 , L_18 ) ;
return - V_51 ;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
F_44 ( V_2 -> V_79 ) ;
}
static inline void F_37 ( struct V_43 * V_44 ,
enum V_45 type , unsigned long V_46 )
{
}
static inline void F_38 ( struct V_43 * V_44 ,
enum V_45 type , unsigned long V_46 )
{
}
static inline unsigned long F_39 ( struct V_43 * V_44 ,
enum V_45 type )
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
static enum V_31 F_56 ( struct V_29 * V_29 )
{
int V_83 , V_84 ;
enum V_31 V_85 ;
F_31 ( ! F_26 ( V_29 ) ) ;
V_83 = V_29 -> V_83 ;
V_84 = V_29 -> V_86 ;
if ( V_83 == 0 )
V_85 = V_87 ;
else if ( V_83 == V_84 )
V_85 = V_88 ;
else if ( V_83 <= 3 * V_84 / V_89 )
V_85 = V_90 ;
else
V_85 = V_91 ;
return V_85 ;
}
static void F_57 ( struct V_29 * V_29 , struct V_43 * V_44 ,
enum V_31 V_32 )
{
struct V_29 * * V_92 ;
F_31 ( ! F_26 ( V_29 ) ) ;
if ( V_32 >= V_93 )
return;
V_92 = & V_44 -> V_94 [ V_32 ] ;
if ( * V_92 )
F_58 ( & V_29 -> V_95 , & ( * V_92 ) -> V_95 ) ;
* V_92 = V_29 ;
F_37 ( V_44 , V_32 == V_90 ?
V_71 : V_70 , 1 ) ;
}
static void F_59 ( struct V_29 * V_29 , struct V_43 * V_44 ,
enum V_31 V_32 )
{
struct V_29 * * V_92 ;
F_31 ( ! F_26 ( V_29 ) ) ;
if ( V_32 >= V_93 )
return;
V_92 = & V_44 -> V_94 [ V_32 ] ;
F_31 ( ! * V_92 ) ;
if ( F_60 ( & ( * V_92 ) -> V_95 ) )
* V_92 = NULL ;
else if ( * V_92 == V_29 )
* V_92 = (struct V_29 * ) F_61 ( ( * V_92 ) -> V_95 . V_96 ,
struct V_29 , V_95 ) ;
F_62 ( & V_29 -> V_95 ) ;
F_38 ( V_44 , V_32 == V_90 ?
V_71 : V_70 , 1 ) ;
}
static enum V_31 F_63 ( struct V_43 * V_44 ,
struct V_29 * V_29 )
{
int V_30 ;
enum V_31 V_97 , V_98 ;
F_31 ( ! F_26 ( V_29 ) ) ;
F_30 ( V_29 , & V_30 , & V_97 ) ;
V_98 = F_56 ( V_29 ) ;
if ( V_98 == V_97 )
goto V_99;
F_59 ( V_29 , V_44 , V_97 ) ;
F_57 ( V_29 , V_44 , V_98 ) ;
F_32 ( V_29 , V_30 , V_98 ) ;
V_99:
return V_98 ;
}
static int F_64 ( int V_100 )
{
int V_55 , V_101 = 0 ;
int V_102 = 1 ;
for ( V_55 = 1 ; V_55 <= V_103 ; V_55 ++ ) {
int V_104 ;
int V_105 , V_106 ;
V_104 = V_55 * V_28 ;
V_105 = V_104 % V_100 ;
V_106 = ( V_104 - V_105 ) * 100 / V_104 ;
if ( V_106 > V_101 ) {
V_101 = V_106 ;
V_102 = V_55 ;
}
}
return V_102 ;
}
static struct V_29 * F_65 ( struct V_29 * V_29 )
{
if ( F_26 ( V_29 ) )
return V_29 ;
else
return V_29 -> V_107 ;
}
static struct V_29 * F_66 ( struct V_29 * V_29 )
{
struct V_29 * V_96 ;
if ( F_28 ( V_29 ) )
V_96 = NULL ;
else if ( F_26 ( V_29 ) )
V_96 = (struct V_29 * ) F_67 ( V_29 ) ;
else
V_96 = F_61 ( V_29 -> V_95 . V_96 , struct V_29 , V_95 ) ;
return V_96 ;
}
static void * F_68 ( struct V_29 * V_29 , unsigned long V_108 )
{
unsigned long V_8 ;
if ( ! V_29 ) {
F_31 ( V_108 ) ;
return NULL ;
}
V_8 = F_69 ( V_29 ) << V_109 ;
V_8 |= ( ( V_108 ) & V_110 ) ;
V_8 <<= V_111 ;
return ( void * ) V_8 ;
}
static void F_70 ( unsigned long V_8 , struct V_29 * * V_29 ,
unsigned long * V_108 )
{
V_8 >>= V_111 ;
* V_29 = F_71 ( V_8 >> V_109 ) ;
* V_108 = ( V_8 & V_110 ) ;
}
static unsigned long F_72 ( unsigned long V_7 )
{
return * ( unsigned long * ) V_7 ;
}
static unsigned long F_73 ( struct V_43 * V_44 , struct V_29 * V_29 ,
void * V_8 )
{
if ( V_44 -> V_112 ) {
F_74 ( ! F_26 ( V_29 ) ) ;
return * ( unsigned long * ) F_67 ( V_29 ) ;
} else
return * ( unsigned long * ) V_8 ;
}
static unsigned long F_75 ( struct V_29 * V_29 ,
unsigned long V_108 , int V_100 )
{
unsigned long V_113 = 0 ;
if ( ! F_26 ( V_29 ) )
V_113 = V_29 -> V_68 ;
return V_113 + V_108 * V_100 ;
}
static inline int F_76 ( unsigned long V_7 )
{
unsigned long * V_114 = ( unsigned long * ) V_7 ;
return ! F_77 ( V_115 , V_114 ) ;
}
static void F_78 ( unsigned long V_7 )
{
while ( ! F_76 ( V_7 ) ) ;
}
static void F_79 ( unsigned long V_7 )
{
unsigned long * V_114 = ( unsigned long * ) V_7 ;
F_80 ( V_115 , V_114 ) ;
}
static void F_81 ( struct V_29 * V_29 )
{
F_82 ( V_116 , & V_29 -> V_5 ) ;
F_82 ( V_117 , & V_29 -> V_5 ) ;
F_83 ( V_29 , 0 ) ;
V_29 -> V_34 = NULL ;
V_29 -> V_118 = NULL ;
F_84 ( V_29 ) ;
}
static void F_85 ( struct V_29 * V_107 )
{
struct V_29 * V_119 , * V_120 , * V_121 ;
F_31 ( ! F_26 ( V_107 ) ) ;
F_31 ( V_107 -> V_83 ) ;
V_121 = (struct V_29 * ) F_67 ( V_107 ) ;
F_81 ( V_107 ) ;
F_86 ( V_107 ) ;
if ( ! V_121 )
return;
F_87 (nextp, tmp, &head_extra->lru, lru) {
F_88 ( & V_119 -> V_95 ) ;
F_81 ( V_119 ) ;
F_86 ( V_119 ) ;
}
F_81 ( V_121 ) ;
F_86 ( V_121 ) ;
}
static void F_89 ( struct V_29 * V_107 , struct V_43 * V_44 )
{
unsigned long V_113 = 0 ;
struct V_29 * V_29 = V_107 ;
F_31 ( ! F_26 ( V_107 ) ) ;
while ( V_29 ) {
struct V_29 * V_122 ;
struct V_123 * V_124 ;
unsigned int V_55 = 1 ;
void * V_125 ;
if ( V_29 != V_107 )
V_29 -> V_68 = V_113 ;
V_125 = F_90 ( V_29 ) ;
V_124 = (struct V_123 * ) V_125 + V_113 / sizeof( * V_124 ) ;
while ( ( V_113 += V_44 -> V_12 ) < V_28 ) {
V_124 -> V_96 = F_68 ( V_29 , V_55 ++ ) ;
V_124 += V_44 -> V_12 / sizeof( * V_124 ) ;
}
V_122 = F_66 ( V_29 ) ;
V_124 -> V_96 = F_68 ( V_122 , 0 ) ;
F_91 ( V_125 ) ;
V_29 = V_122 ;
V_113 %= V_28 ;
}
}
static struct V_29 * F_92 ( struct V_43 * V_44 , T_1 V_5 )
{
int V_55 , error ;
struct V_29 * V_107 = NULL , * V_126 ( V_127 ) ;
error = - V_51 ;
for ( V_55 = 0 ; V_55 < V_44 -> V_27 ; V_55 ++ ) {
struct V_29 * V_29 ;
V_29 = F_93 ( V_5 ) ;
if ( ! V_29 )
goto V_128;
F_94 ( & V_29 -> V_95 ) ;
if ( V_55 == 0 ) {
F_95 ( V_29 ) ;
F_83 ( V_29 , 0 ) ;
V_107 = V_29 ;
V_107 -> V_83 = 0 ;
}
if ( V_55 == 1 )
F_83 ( V_107 , ( unsigned long ) V_29 ) ;
if ( V_55 >= 1 )
V_29 -> V_107 = V_107 ;
if ( V_55 >= 2 )
F_96 ( & V_29 -> V_95 , & V_127 -> V_95 ) ;
if ( V_55 == V_44 -> V_27 - 1 )
F_97 ( V_29 ) ;
V_127 = V_29 ;
}
F_89 ( V_107 , V_44 ) ;
V_107 -> V_118 = F_68 ( V_107 , 0 ) ;
V_107 -> V_86 = V_44 -> V_27 * V_28 / V_44 -> V_12 ;
error = 0 ;
V_128:
if ( F_98 ( error ) && V_107 ) {
F_85 ( V_107 ) ;
V_107 = NULL ;
}
return V_107 ;
}
static struct V_29 * F_99 ( struct V_43 * V_44 )
{
int V_55 ;
struct V_29 * V_29 ;
for ( V_55 = 0 ; V_55 < V_93 ; V_55 ++ ) {
V_29 = V_44 -> V_94 [ V_55 ] ;
if ( V_29 )
break;
}
return V_29 ;
}
static inline int F_100 ( struct V_129 * V_130 )
{
if ( V_130 -> V_131 )
return 0 ;
V_130 -> V_131 = F_101 ( V_28 * 2 , NULL ) ;
if ( ! V_130 -> V_131 )
return - V_51 ;
return 0 ;
}
static inline void F_102 ( struct V_129 * V_130 )
{
if ( V_130 -> V_131 )
F_103 ( V_130 -> V_131 ) ;
V_130 -> V_131 = NULL ;
}
static inline void * F_104 ( struct V_129 * V_130 ,
struct V_29 * V_13 [ 2 ] , int V_113 , int V_12 )
{
F_31 ( F_105 ( V_130 -> V_131 , V_132 , V_13 ) ) ;
V_130 -> V_133 = V_130 -> V_131 -> V_134 ;
return V_130 -> V_133 + V_113 ;
}
static inline void F_106 ( struct V_129 * V_130 ,
struct V_29 * V_13 [ 2 ] , int V_113 , int V_12 )
{
unsigned long V_134 = ( unsigned long ) V_130 -> V_133 ;
F_107 ( V_134 , V_28 * 2 ) ;
}
static inline int F_100 ( struct V_129 * V_130 )
{
if ( V_130 -> V_135 )
return 0 ;
V_130 -> V_135 = F_108 ( V_136 , V_137 ) ;
if ( ! V_130 -> V_135 )
return - V_51 ;
return 0 ;
}
static inline void F_102 ( struct V_129 * V_130 )
{
F_109 ( V_130 -> V_135 ) ;
V_130 -> V_135 = NULL ;
}
static void * F_104 ( struct V_129 * V_130 ,
struct V_29 * V_13 [ 2 ] , int V_113 , int V_12 )
{
int V_138 [ 2 ] ;
void * V_134 ;
char * V_139 = V_130 -> V_135 ;
F_110 () ;
if ( V_130 -> V_140 == V_23 )
goto V_99;
V_138 [ 0 ] = V_28 - V_113 ;
V_138 [ 1 ] = V_12 - V_138 [ 0 ] ;
V_134 = F_90 ( V_13 [ 0 ] ) ;
memcpy ( V_139 , V_134 + V_113 , V_138 [ 0 ] ) ;
F_91 ( V_134 ) ;
V_134 = F_90 ( V_13 [ 1 ] ) ;
memcpy ( V_139 + V_138 [ 0 ] , V_134 , V_138 [ 1 ] ) ;
F_91 ( V_134 ) ;
V_99:
return V_130 -> V_135 ;
}
static void F_106 ( struct V_129 * V_130 ,
struct V_29 * V_13 [ 2 ] , int V_113 , int V_12 )
{
int V_138 [ 2 ] ;
void * V_134 ;
char * V_139 ;
if ( V_130 -> V_140 == V_21 )
goto V_99;
V_139 = V_130 -> V_135 ;
if ( ! V_130 -> V_112 ) {
V_139 = V_139 + V_4 ;
V_12 -= V_4 ;
V_113 += V_4 ;
}
V_138 [ 0 ] = V_28 - V_113 ;
V_138 [ 1 ] = V_12 - V_138 [ 0 ] ;
V_134 = F_90 ( V_13 [ 0 ] ) ;
memcpy ( V_134 + V_113 , V_139 , V_138 [ 0 ] ) ;
F_91 ( V_134 ) ;
V_134 = F_90 ( V_13 [ 1 ] ) ;
memcpy ( V_134 , V_139 + V_138 [ 0 ] , V_138 [ 1 ] ) ;
F_91 ( V_134 ) ;
V_99:
F_111 () ;
}
static int F_112 ( struct V_141 * V_142 , unsigned long V_143 ,
void * V_144 )
{
int V_145 , V_146 = ( long ) V_144 ;
struct V_129 * V_130 ;
switch ( V_143 ) {
case V_147 :
V_130 = & F_113 ( V_148 , V_146 ) ;
V_145 = F_100 ( V_130 ) ;
if ( V_145 )
return F_114 ( V_145 ) ;
break;
case V_149 :
case V_150 :
V_130 = & F_113 ( V_148 , V_146 ) ;
F_102 ( V_130 ) ;
break;
}
return V_151 ;
}
static int F_115 ( void )
{
int V_146 , V_126 ( V_145 ) ;
F_116 () ;
F_117 ( & V_152 ) ;
F_118 (cpu) {
V_145 = F_112 ( NULL , V_147 , ( void * ) ( long ) V_146 ) ;
if ( F_119 ( V_145 ) )
break;
}
F_120 () ;
return F_119 ( V_145 ) ;
}
static void F_121 ( void )
{
int V_146 ;
F_116 () ;
F_118 (cpu)
F_112 ( NULL , V_149 , ( void * ) ( long ) V_146 ) ;
F_122 ( & V_152 ) ;
F_120 () ;
}
static void F_123 ( void )
{
int V_153 ;
V_153 = ( V_136 - V_40 ) / V_41 + 1 ;
if ( ( V_136 - V_40 ) % V_41 )
V_153 += 1 ;
V_42 = V_153 ;
}
static bool F_124 ( struct V_43 * V_154 , int V_12 , int V_27 )
{
if ( V_154 -> V_27 != V_27 )
return false ;
if ( F_25 ( V_154 -> V_12 , V_154 -> V_27 )
!= F_25 ( V_12 , V_27 ) )
return false ;
return true ;
}
static bool F_125 ( struct V_29 * V_29 )
{
F_31 ( ! F_26 ( V_29 ) ) ;
return V_29 -> V_83 == V_29 -> V_86 ;
}
unsigned long F_24 ( struct V_1 * V_2 )
{
return F_126 ( & V_2 -> V_155 ) ;
}
void * F_20 ( struct V_1 * V_2 , unsigned long V_7 ,
enum V_18 V_17 )
{
struct V_29 * V_29 ;
unsigned long V_8 , V_108 , V_113 ;
unsigned int V_30 ;
enum V_31 V_85 ;
struct V_43 * V_44 ;
struct V_129 * V_130 ;
struct V_29 * V_13 [ 2 ] ;
void * V_145 ;
F_31 ( ! V_7 ) ;
F_31 ( F_127 () ) ;
F_78 ( V_7 ) ;
V_8 = F_72 ( V_7 ) ;
F_70 ( V_8 , & V_29 , & V_108 ) ;
F_30 ( F_65 ( V_29 ) , & V_30 , & V_85 ) ;
V_44 = V_2 -> V_43 [ V_30 ] ;
V_113 = F_75 ( V_29 , V_108 , V_44 -> V_12 ) ;
V_130 = & F_128 ( V_148 ) ;
V_130 -> V_140 = V_17 ;
if ( V_113 + V_44 -> V_12 <= V_28 ) {
V_130 -> V_133 = F_90 ( V_29 ) ;
V_145 = V_130 -> V_133 + V_113 ;
goto V_99;
}
V_13 [ 0 ] = V_29 ;
V_13 [ 1 ] = F_66 ( V_29 ) ;
F_31 ( ! V_13 [ 1 ] ) ;
V_145 = F_104 ( V_130 , V_13 , V_113 , V_44 -> V_12 ) ;
V_99:
if ( ! V_44 -> V_112 )
V_145 += V_4 ;
return V_145 ;
}
void F_22 ( struct V_1 * V_2 , unsigned long V_7 )
{
struct V_29 * V_29 ;
unsigned long V_8 , V_108 , V_113 ;
unsigned int V_30 ;
enum V_31 V_85 ;
struct V_43 * V_44 ;
struct V_129 * V_130 ;
F_31 ( ! V_7 ) ;
V_8 = F_72 ( V_7 ) ;
F_70 ( V_8 , & V_29 , & V_108 ) ;
F_30 ( F_65 ( V_29 ) , & V_30 , & V_85 ) ;
V_44 = V_2 -> V_43 [ V_30 ] ;
V_113 = F_75 ( V_29 , V_108 , V_44 -> V_12 ) ;
V_130 = F_129 ( & V_148 ) ;
if ( V_113 + V_44 -> V_12 <= V_28 )
F_91 ( V_130 -> V_133 ) ;
else {
struct V_29 * V_13 [ 2 ] ;
V_13 [ 0 ] = V_29 ;
V_13 [ 1 ] = F_66 ( V_29 ) ;
F_31 ( ! V_13 [ 1 ] ) ;
F_106 ( V_130 , V_13 , V_113 , V_44 -> V_12 ) ;
}
F_130 ( V_148 ) ;
F_79 ( V_7 ) ;
}
static unsigned long F_131 ( struct V_29 * V_107 ,
struct V_43 * V_44 , unsigned long V_7 )
{
unsigned long V_8 ;
struct V_123 * V_124 ;
struct V_29 * V_156 ;
unsigned long V_157 , V_158 ;
void * V_125 ;
V_7 |= V_159 ;
V_8 = ( unsigned long ) V_107 -> V_118 ;
F_70 ( V_8 , & V_156 , & V_157 ) ;
V_158 = F_75 ( V_156 , V_157 , V_44 -> V_12 ) ;
V_125 = F_90 ( V_156 ) ;
V_124 = (struct V_123 * ) V_125 + V_158 / sizeof( * V_124 ) ;
V_107 -> V_118 = V_124 -> V_96 ;
if ( ! V_44 -> V_112 )
V_124 -> V_7 = V_7 ;
else
F_83 ( V_107 , V_7 ) ;
F_91 ( V_125 ) ;
V_107 -> V_83 ++ ;
F_37 ( V_44 , V_73 , 1 ) ;
return V_8 ;
}
unsigned long F_15 ( struct V_1 * V_2 , T_2 V_12 )
{
unsigned long V_7 , V_8 ;
struct V_43 * V_44 ;
struct V_29 * V_107 ;
if ( F_98 ( ! V_12 || V_12 > V_136 ) )
return 0 ;
V_7 = F_5 ( V_2 ) ;
if ( ! V_7 )
return 0 ;
V_12 += V_4 ;
V_44 = V_2 -> V_43 [ F_33 ( V_12 ) ] ;
F_47 ( & V_44 -> V_69 ) ;
V_107 = F_99 ( V_44 ) ;
if ( ! V_107 ) {
F_48 ( & V_44 -> V_69 ) ;
V_107 = F_92 ( V_44 , V_2 -> V_5 ) ;
if ( F_98 ( ! V_107 ) ) {
F_7 ( V_2 , V_7 ) ;
return 0 ;
}
F_32 ( V_107 , V_44 -> V_68 , V_87 ) ;
F_132 ( V_44 -> V_27 ,
& V_2 -> V_155 ) ;
F_47 ( & V_44 -> V_69 ) ;
F_37 ( V_44 , V_72 , F_25 (
V_44 -> V_12 , V_44 -> V_27 ) ) ;
}
V_8 = F_131 ( V_107 , V_44 , V_7 ) ;
F_63 ( V_44 , V_107 ) ;
F_9 ( V_7 , V_8 ) ;
F_48 ( & V_44 -> V_69 ) ;
return V_7 ;
}
static void F_133 ( struct V_1 * V_2 , struct V_43 * V_44 ,
unsigned long V_8 )
{
struct V_123 * V_124 ;
struct V_29 * V_107 , * V_160 ;
unsigned long V_161 , V_162 ;
void * V_125 ;
int V_30 ;
enum V_31 V_32 ;
F_31 ( ! V_8 ) ;
V_8 &= ~ V_159 ;
F_70 ( V_8 , & V_160 , & V_161 ) ;
V_107 = F_65 ( V_160 ) ;
F_30 ( V_107 , & V_30 , & V_32 ) ;
V_162 = F_75 ( V_160 , V_161 , V_44 -> V_12 ) ;
V_125 = F_90 ( V_160 ) ;
V_124 = (struct V_123 * ) ( V_125 + V_162 ) ;
V_124 -> V_96 = V_107 -> V_118 ;
if ( V_44 -> V_112 )
F_83 ( V_107 , 0 ) ;
F_91 ( V_125 ) ;
V_107 -> V_118 = ( void * ) V_8 ;
V_107 -> V_83 -- ;
F_38 ( V_44 , V_73 , 1 ) ;
}
void F_17 ( struct V_1 * V_2 , unsigned long V_7 )
{
struct V_29 * V_107 , * V_160 ;
unsigned long V_8 , V_161 ;
int V_30 ;
struct V_43 * V_44 ;
enum V_31 V_32 ;
if ( F_98 ( ! V_7 ) )
return;
F_78 ( V_7 ) ;
V_8 = F_72 ( V_7 ) ;
F_70 ( V_8 , & V_160 , & V_161 ) ;
V_107 = F_65 ( V_160 ) ;
F_30 ( V_107 , & V_30 , & V_32 ) ;
V_44 = V_2 -> V_43 [ V_30 ] ;
F_47 ( & V_44 -> V_69 ) ;
F_133 ( V_2 , V_44 , V_8 ) ;
V_32 = F_63 ( V_44 , V_107 ) ;
if ( V_32 == V_87 ) {
F_38 ( V_44 , V_72 , F_25 (
V_44 -> V_12 , V_44 -> V_27 ) ) ;
F_134 ( V_44 -> V_27 ,
& V_2 -> V_155 ) ;
F_85 ( V_107 ) ;
}
F_48 ( & V_44 -> V_69 ) ;
F_79 ( V_7 ) ;
F_7 ( V_2 , V_7 ) ;
}
static void F_135 ( unsigned long V_163 , unsigned long V_164 ,
struct V_43 * V_44 )
{
struct V_29 * V_165 , * V_166 ;
unsigned long V_167 , V_168 ;
unsigned long V_169 , V_170 ;
void * V_171 , * V_172 ;
int V_173 , V_174 , V_12 ;
int V_175 = 0 ;
V_173 = V_174 = V_44 -> V_12 ;
F_70 ( V_163 , & V_165 , & V_167 ) ;
F_70 ( V_164 , & V_166 , & V_168 ) ;
V_169 = F_75 ( V_165 , V_167 , V_44 -> V_12 ) ;
V_170 = F_75 ( V_166 , V_168 , V_44 -> V_12 ) ;
if ( V_169 + V_44 -> V_12 > V_28 )
V_173 = V_28 - V_169 ;
if ( V_170 + V_44 -> V_12 > V_28 )
V_174 = V_28 - V_170 ;
V_171 = F_90 ( V_165 ) ;
V_172 = F_90 ( V_166 ) ;
while ( 1 ) {
V_12 = F_36 ( V_173 , V_174 ) ;
memcpy ( V_172 + V_170 , V_171 + V_169 , V_12 ) ;
V_175 += V_12 ;
if ( V_175 == V_44 -> V_12 )
break;
V_169 += V_12 ;
V_173 -= V_12 ;
V_170 += V_12 ;
V_174 -= V_12 ;
if ( V_169 >= V_28 ) {
F_91 ( V_172 ) ;
F_91 ( V_171 ) ;
V_165 = F_66 ( V_165 ) ;
F_31 ( ! V_165 ) ;
V_171 = F_90 ( V_165 ) ;
V_172 = F_90 ( V_166 ) ;
V_173 = V_44 -> V_12 - V_175 ;
V_169 = 0 ;
}
if ( V_170 >= V_28 ) {
F_91 ( V_172 ) ;
V_166 = F_66 ( V_166 ) ;
F_31 ( ! V_166 ) ;
V_172 = F_90 ( V_166 ) ;
V_174 = V_44 -> V_12 - V_175 ;
V_170 = 0 ;
}
}
F_91 ( V_172 ) ;
F_91 ( V_171 ) ;
}
static unsigned long F_136 ( struct V_29 * V_29 , int V_68 ,
struct V_43 * V_44 )
{
unsigned long V_92 ;
int V_176 = 0 ;
unsigned long V_7 = 0 ;
void * V_134 = F_90 ( V_29 ) ;
if ( ! F_26 ( V_29 ) )
V_176 = V_29 -> V_68 ;
V_176 += V_44 -> V_12 * V_68 ;
while ( V_176 < V_28 ) {
V_92 = F_73 ( V_44 , V_29 , V_134 + V_176 ) ;
if ( V_92 & V_159 ) {
V_7 = V_92 & ~ V_159 ;
if ( F_76 ( V_7 ) )
break;
V_7 = 0 ;
}
V_176 += V_44 -> V_12 ;
V_68 ++ ;
}
F_91 ( V_134 ) ;
return V_7 ;
}
static int F_137 ( struct V_1 * V_2 , struct V_43 * V_44 ,
struct V_177 * V_178 )
{
unsigned long V_179 , V_180 ;
unsigned long V_7 ;
struct V_29 * V_165 = V_178 -> V_165 ;
struct V_29 * V_166 = V_178 -> V_166 ;
unsigned long V_68 = V_178 -> V_68 ;
int V_181 = 0 ;
int V_145 = 0 ;
while ( 1 ) {
V_7 = F_136 ( V_165 , V_68 , V_44 ) ;
if ( ! V_7 ) {
V_165 = F_66 ( V_165 ) ;
if ( ! V_165 )
break;
V_68 = 0 ;
continue;
}
if ( F_125 ( V_166 ) ) {
F_79 ( V_7 ) ;
V_145 = - V_51 ;
break;
}
V_179 = F_72 ( V_7 ) ;
V_180 = F_131 ( V_166 , V_44 , V_7 ) ;
F_135 ( V_179 , V_180 , V_44 ) ;
V_68 ++ ;
F_9 ( V_7 , V_180 ) ;
F_79 ( V_7 ) ;
F_133 ( V_2 , V_44 , V_179 ) ;
V_181 ++ ;
}
V_178 -> V_165 = V_165 ;
V_178 -> V_68 = V_68 ;
V_178 -> V_181 = V_181 ;
return V_145 ;
}
static struct V_29 * F_138 ( struct V_43 * V_44 )
{
int V_55 ;
struct V_29 * V_29 ;
for ( V_55 = 0 ; V_55 < V_93 ; V_55 ++ ) {
V_29 = V_44 -> V_94 [ V_55 ] ;
if ( V_29 ) {
F_59 ( V_29 , V_44 , V_55 ) ;
break;
}
}
return V_29 ;
}
static void F_139 ( struct V_1 * V_2 , struct V_43 * V_44 ,
struct V_29 * V_107 )
{
enum V_31 V_32 ;
F_31 ( ! F_26 ( V_107 ) ) ;
V_32 = F_56 ( V_107 ) ;
F_57 ( V_107 , V_44 , V_32 ) ;
F_32 ( V_107 , V_44 -> V_68 , V_32 ) ;
if ( V_32 == V_87 ) {
F_38 ( V_44 , V_72 , F_25 (
V_44 -> V_12 , V_44 -> V_27 ) ) ;
F_134 ( V_44 -> V_27 ,
& V_2 -> V_155 ) ;
F_85 ( V_107 ) ;
}
}
static struct V_29 * F_140 ( struct V_43 * V_44 )
{
struct V_29 * V_29 ;
V_29 = V_44 -> V_94 [ V_90 ] ;
if ( V_29 )
F_59 ( V_29 , V_44 , V_90 ) ;
return V_29 ;
}
static unsigned long F_141 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
int V_182 ;
struct V_177 V_178 ;
struct V_29 * V_183 ;
struct V_29 * V_184 = NULL ;
unsigned long V_185 = 0 ;
F_47 ( & V_44 -> V_69 ) ;
while ( ( V_183 = F_140 ( V_44 ) ) ) {
F_31 ( ! F_26 ( V_183 ) ) ;
V_182 = V_183 -> V_83 ;
V_178 . V_68 = 0 ;
V_178 . V_165 = V_183 ;
while ( ( V_184 = F_138 ( V_44 ) ) ) {
V_178 . V_166 = V_184 ;
if ( ! F_137 ( V_2 , V_44 , & V_178 ) )
break;
F_139 ( V_2 , V_44 , V_184 ) ;
V_185 += V_178 . V_181 ;
V_182 -= V_178 . V_181 ;
}
if ( V_184 == NULL )
break;
F_139 ( V_2 , V_44 , V_184 ) ;
F_139 ( V_2 , V_44 , V_183 ) ;
F_48 ( & V_44 -> V_69 ) ;
V_185 += V_178 . V_181 ;
F_142 () ;
F_47 ( & V_44 -> V_69 ) ;
}
if ( V_183 )
F_139 ( V_2 , V_44 , V_183 ) ;
F_48 ( & V_44 -> V_69 ) ;
return V_185 ;
}
unsigned long F_143 ( struct V_1 * V_2 )
{
int V_55 ;
unsigned long V_181 = 0 ;
struct V_43 * V_44 ;
for ( V_55 = V_42 - 1 ; V_55 >= 0 ; V_55 -- ) {
V_44 = V_2 -> V_43 [ V_55 ] ;
if ( ! V_44 )
continue;
if ( V_44 -> V_68 != V_55 )
continue;
V_181 += F_141 ( V_2 , V_44 ) ;
}
return V_181 ;
}
struct V_1 * F_11 ( char * V_9 , T_1 V_5 )
{
int V_55 ;
struct V_1 * V_2 ;
struct V_43 * V_186 = NULL ;
V_2 = F_144 ( sizeof( * V_2 ) , V_137 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_43 = F_145 ( V_42 , sizeof( struct V_43 * ) ,
V_137 ) ;
if ( ! V_2 -> V_43 ) {
F_109 ( V_2 ) ;
return NULL ;
}
V_2 -> V_9 = F_146 ( V_9 , V_137 ) ;
if ( ! V_2 -> V_9 )
goto V_187;
if ( F_1 ( V_2 ) )
goto V_187;
for ( V_55 = V_42 - 1 ; V_55 >= 0 ; V_55 -- ) {
int V_12 ;
int V_27 ;
struct V_43 * V_44 ;
V_12 = V_40 + V_55 * V_41 ;
if ( V_12 > V_136 )
V_12 = V_136 ;
V_27 = F_64 ( V_12 ) ;
if ( V_186 ) {
if ( F_124 ( V_186 , V_12 , V_27 ) ) {
V_2 -> V_43 [ V_55 ] = V_186 ;
continue;
}
}
V_44 = F_144 ( sizeof( struct V_43 ) , V_137 ) ;
if ( ! V_44 )
goto V_187;
V_44 -> V_12 = V_12 ;
V_44 -> V_68 = V_55 ;
V_44 -> V_27 = V_27 ;
if ( V_27 == 1 &&
F_25 ( V_12 , V_27 ) == 1 )
V_44 -> V_112 = true ;
F_147 ( & V_44 -> V_69 ) ;
V_2 -> V_43 [ V_55 ] = V_44 ;
V_186 = V_44 ;
}
V_2 -> V_5 = V_5 ;
if ( F_52 ( V_9 , V_2 ) )
goto V_187;
return V_2 ;
V_187:
F_13 ( V_2 ) ;
return NULL ;
}
void F_13 ( struct V_1 * V_2 )
{
int V_55 ;
F_55 ( V_2 ) ;
for ( V_55 = 0 ; V_55 < V_42 ; V_55 ++ ) {
int V_85 ;
struct V_43 * V_44 = V_2 -> V_43 [ V_55 ] ;
if ( ! V_44 )
continue;
if ( V_44 -> V_68 != V_55 )
continue;
for ( V_85 = 0 ; V_85 < V_93 ; V_85 ++ ) {
if ( V_44 -> V_94 [ V_85 ] ) {
F_148 ( L_20 ,
V_44 -> V_12 , V_85 ) ;
}
}
F_109 ( V_44 ) ;
}
F_3 ( V_2 ) ;
F_109 ( V_2 -> V_43 ) ;
F_109 ( V_2 -> V_9 ) ;
F_109 ( V_2 ) ;
}
static int T_4 F_149 ( void )
{
int V_145 = F_115 () ;
if ( V_145 )
goto V_188;
F_123 () ;
#ifdef F_150
F_151 ( & V_189 ) ;
#endif
V_145 = F_40 () ;
if ( V_145 ) {
F_152 ( L_21 ) ;
goto V_190;
}
return 0 ;
V_190:
#ifdef F_150
F_153 ( & V_189 ) ;
#endif
V_188:
F_121 () ;
return V_145 ;
}
static void T_5 F_154 ( void )
{
#ifdef F_150
F_153 ( & V_189 ) ;
#endif
F_121 () ;
F_43 () ;
}
