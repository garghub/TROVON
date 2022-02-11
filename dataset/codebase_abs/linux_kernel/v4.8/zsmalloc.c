static void F_1 ( struct V_1 * V_1 )
{
F_2 ( V_1 ) ;
}
static void F_3 ( struct V_1 * V_1 )
{
F_4 ( V_1 ) ;
}
static int F_5 ( struct V_1 * V_1 )
{
return F_6 ( V_1 ) ;
}
static int F_7 ( void ) { return 0 ; }
static void F_8 ( void ) {}
static int F_9 ( struct V_2 * V_3 ) { return 0 ; }
static void F_10 ( struct V_2 * V_3 ) {}
static void F_11 ( struct V_4 * V_4 ) {}
static void F_12 ( struct V_4 * V_4 ) {}
static void F_13 ( struct V_4 * V_4 ) {}
static void F_14 ( struct V_2 * V_3 ) {}
static void F_15 ( struct V_2 * V_3 ) {}
static void F_16 ( struct V_2 * V_3 , struct V_4 * V_4 ) {}
static int F_17 ( struct V_2 * V_3 )
{
V_3 -> V_5 = F_18 ( L_1 , V_6 ,
0 , 0 , NULL ) ;
if ( ! V_3 -> V_5 )
return 1 ;
V_3 -> V_7 = F_18 ( L_2 , sizeof( struct V_4 ) ,
0 , 0 , NULL ) ;
if ( ! V_3 -> V_7 ) {
F_19 ( V_3 -> V_5 ) ;
V_3 -> V_5 = NULL ;
return 1 ;
}
return 0 ;
}
static void F_20 ( struct V_2 * V_3 )
{
F_19 ( V_3 -> V_5 ) ;
F_19 ( V_3 -> V_7 ) ;
}
static unsigned long F_21 ( struct V_2 * V_3 , T_1 V_8 )
{
return ( unsigned long ) F_22 ( V_3 -> V_5 ,
V_8 & ~ ( V_9 | V_10 ) ) ;
}
static void F_23 ( struct V_2 * V_3 , unsigned long V_11 )
{
F_24 ( V_3 -> V_5 , ( void * ) V_11 ) ;
}
static struct V_4 * F_25 ( struct V_2 * V_3 , T_1 V_12 )
{
return F_22 ( V_3 -> V_7 ,
V_12 & ~ ( V_9 | V_10 ) ) ;
}
static void F_26 ( struct V_2 * V_3 , struct V_4 * V_4 )
{
F_24 ( V_3 -> V_7 , V_4 ) ;
}
static void F_27 ( unsigned long V_11 , unsigned long V_13 )
{
F_28 ( * ( unsigned long * ) V_11 , V_13 ) ;
}
static void * F_29 ( const char * V_14 , T_1 V_8 ,
const struct V_15 * V_15 ,
struct V_16 * V_16 )
{
return F_30 ( V_14 ) ;
}
static void F_31 ( void * V_3 )
{
F_32 ( V_3 ) ;
}
static int F_33 ( void * V_3 , T_2 V_17 , T_1 V_8 ,
unsigned long * V_11 )
{
* V_11 = F_34 ( V_3 , V_17 , V_8 ) ;
return * V_11 ? 0 : - 1 ;
}
static void F_35 ( void * V_3 , unsigned long V_11 )
{
F_36 ( V_3 , V_11 ) ;
}
static int F_37 ( void * V_3 , unsigned int V_18 ,
unsigned int * V_19 )
{
return - V_20 ;
}
static void * F_38 ( void * V_3 , unsigned long V_11 ,
enum V_21 V_22 )
{
enum V_23 V_24 ;
switch ( V_22 ) {
case V_25 :
V_24 = V_26 ;
break;
case V_27 :
V_24 = V_28 ;
break;
case V_29 :
default:
V_24 = V_30 ;
break;
}
return F_39 ( V_3 , V_11 , V_24 ) ;
}
static void F_40 ( void * V_3 , unsigned long V_11 )
{
F_41 ( V_3 , V_11 ) ;
}
static T_3 F_42 ( void * V_3 )
{
return F_43 ( V_3 ) << V_31 ;
}
static bool F_44 ( struct V_4 * V_4 )
{
return V_4 -> V_32 ;
}
static int F_45 ( struct V_1 * V_1 )
{
return F_46 ( V_1 ) ;
}
static inline int F_47 ( struct V_4 * V_4 )
{
return V_4 -> V_33 ;
}
static inline void F_48 ( struct V_4 * V_4 , int V_34 )
{
V_4 -> V_33 = V_34 ;
}
static inline void F_49 ( struct V_4 * V_4 , int V_34 )
{
V_4 -> V_33 += V_34 ;
}
static inline struct V_1 * F_50 ( struct V_4 * V_4 )
{
struct V_1 * V_35 = V_4 -> V_35 ;
F_51 ( ! F_45 ( V_35 ) , V_35 ) ;
return V_35 ;
}
static inline int F_52 ( struct V_1 * V_1 )
{
return V_1 -> V_36 ;
}
static inline void F_53 ( struct V_1 * V_1 , int V_37 )
{
V_1 -> V_36 = V_37 ;
}
static inline unsigned int F_54 ( struct V_4 * V_4 )
{
return V_4 -> V_38 ;
}
static inline void F_55 ( struct V_4 * V_4 , unsigned int V_13 )
{
V_4 -> V_38 = V_13 ;
}
static void F_56 ( struct V_4 * V_4 ,
unsigned int * V_39 ,
enum V_40 * V_41 )
{
F_57 ( V_4 -> V_42 != V_43 ) ;
* V_41 = V_4 -> V_41 ;
* V_39 = V_4 -> V_44 ;
}
static void F_58 ( struct V_4 * V_4 ,
unsigned int V_39 ,
enum V_40 V_41 )
{
V_4 -> V_44 = V_39 ;
V_4 -> V_41 = V_41 ;
}
static int F_59 ( int V_17 )
{
int V_45 = 0 ;
if ( F_60 ( V_17 > V_46 ) )
V_45 = F_61 ( V_17 - V_46 ,
V_47 ) ;
return F_62 ( V_48 - 1 , V_45 ) ;
}
static inline void F_63 ( struct V_49 * V_44 ,
enum V_50 type , unsigned long V_51 )
{
V_44 -> V_52 . V_53 [ type ] += V_51 ;
}
static inline void F_64 ( struct V_49 * V_44 ,
enum V_50 type , unsigned long V_51 )
{
V_44 -> V_52 . V_53 [ type ] -= V_51 ;
}
static inline unsigned long F_65 ( struct V_49 * V_44 ,
enum V_50 type )
{
return V_44 -> V_52 . V_53 [ type ] ;
}
static void T_4 F_66 ( void )
{
if ( ! F_67 () ) {
F_68 ( L_3 ) ;
return;
}
V_54 = F_69 ( L_4 , NULL ) ;
if ( ! V_54 )
F_68 ( L_5 ) ;
}
static void T_5 F_70 ( void )
{
F_71 ( V_54 ) ;
}
static int F_72 ( struct V_55 * V_56 , void * V_57 )
{
int V_58 ;
struct V_2 * V_3 = V_56 -> V_59 ;
struct V_49 * V_44 ;
int V_60 ;
unsigned long V_61 , V_62 ;
unsigned long V_63 , V_64 , V_65 , V_66 ;
unsigned long V_67 = 0 , V_68 = 0 ;
unsigned long V_69 = 0 , V_70 = 0 , V_71 = 0 ;
unsigned long V_72 = 0 ;
F_73 ( V_56 , L_6 ,
L_7 , L_8 , L_9 , L_10 ,
L_11 , L_12 , L_13 ,
L_14 , L_15 ) ;
for ( V_58 = 0 ; V_58 < V_48 ; V_58 ++ ) {
V_44 = V_3 -> V_49 [ V_58 ] ;
if ( V_44 -> V_73 != V_58 )
continue;
F_74 ( & V_44 -> V_74 ) ;
V_61 = F_65 ( V_44 , V_75 ) ;
V_62 = F_65 ( V_44 , V_76 ) ;
V_63 = F_65 ( V_44 , V_77 ) ;
V_64 = F_65 ( V_44 , V_78 ) ;
V_66 = F_75 ( V_44 ) ;
F_76 ( & V_44 -> V_74 ) ;
V_60 = V_44 -> V_60 ;
V_65 = V_63 / V_60 *
V_44 -> V_79 ;
F_73 ( V_56 , L_16
L_17 ,
V_58 , V_44 -> V_17 , V_61 , V_62 ,
V_63 , V_64 , V_65 ,
V_44 -> V_79 , V_66 ) ;
V_67 += V_61 ;
V_68 += V_62 ;
V_69 += V_63 ;
V_70 += V_64 ;
V_71 += V_65 ;
V_72 += V_66 ;
}
F_77 ( V_56 , L_18 ) ;
F_73 ( V_56 , L_19 ,
L_20 , L_21 , V_67 ,
V_68 , V_69 ,
V_70 , V_71 , L_21 , V_72 ) ;
return 0 ;
}
static int F_78 ( struct V_80 * V_80 , struct V_81 * V_81 )
{
return F_79 ( V_81 , F_72 , V_80 -> V_82 ) ;
}
static void F_80 ( struct V_2 * V_3 , const char * V_14 )
{
struct V_83 * V_84 ;
if ( ! V_54 ) {
F_68 ( L_22 , V_14 ) ;
return;
}
V_84 = F_69 ( V_14 , V_54 ) ;
if ( ! V_84 ) {
F_68 ( L_23 , V_14 ) ;
return;
}
V_3 -> V_85 = V_84 ;
V_84 = F_81 ( L_24 , V_86 | V_87 ,
V_3 -> V_85 , V_3 , & V_88 ) ;
if ( ! V_84 ) {
F_68 ( L_25 ,
V_14 , L_24 ) ;
F_71 ( V_3 -> V_85 ) ;
V_3 -> V_85 = NULL ;
}
}
static void F_82 ( struct V_2 * V_3 )
{
F_71 ( V_3 -> V_85 ) ;
}
static void T_4 F_66 ( void )
{
}
static void T_5 F_70 ( void )
{
}
static inline void F_80 ( struct V_2 * V_3 , const char * V_14 )
{
}
static inline void F_82 ( struct V_2 * V_3 )
{
}
static enum V_40 F_83 ( struct V_49 * V_44 ,
struct V_4 * V_4 )
{
int V_33 , V_60 ;
enum V_40 V_89 ;
V_33 = F_47 ( V_4 ) ;
V_60 = V_44 -> V_60 ;
if ( V_33 == 0 )
V_89 = V_90 ;
else if ( V_33 == V_60 )
V_89 = V_91 ;
else if ( V_33 <= 3 * V_60 / V_92 )
V_89 = V_93 ;
else
V_89 = V_94 ;
return V_89 ;
}
static void F_84 ( struct V_49 * V_44 ,
struct V_4 * V_4 ,
enum V_40 V_41 )
{
struct V_4 * V_95 ;
F_63 ( V_44 , V_41 , 1 ) ;
V_95 = F_85 ( & V_44 -> V_96 [ V_41 ] ,
struct V_4 , V_97 ) ;
if ( V_95 ) {
if ( F_47 ( V_4 ) < F_47 ( V_95 ) ) {
F_86 ( & V_4 -> V_97 , & V_95 -> V_97 ) ;
return;
}
}
F_86 ( & V_4 -> V_97 , & V_44 -> V_96 [ V_41 ] ) ;
}
static void F_87 ( struct V_49 * V_44 ,
struct V_4 * V_4 ,
enum V_40 V_41 )
{
F_88 ( F_89 ( & V_44 -> V_96 [ V_41 ] ) ) ;
F_88 ( F_44 ( V_4 ) ) ;
F_90 ( & V_4 -> V_97 ) ;
F_64 ( V_44 , V_41 , 1 ) ;
}
static enum V_40 F_91 ( struct V_49 * V_44 ,
struct V_4 * V_4 )
{
int V_39 ;
enum V_40 V_98 , V_99 ;
F_56 ( V_4 , & V_39 , & V_98 ) ;
V_99 = F_83 ( V_44 , V_4 ) ;
if ( V_99 == V_98 )
goto V_100;
if ( ! F_44 ( V_4 ) ) {
F_87 ( V_44 , V_4 , V_98 ) ;
F_84 ( V_44 , V_4 , V_99 ) ;
}
F_58 ( V_4 , V_39 , V_99 ) ;
V_100:
return V_99 ;
}
static int F_92 ( int V_101 )
{
int V_58 , V_102 = 0 ;
int V_103 = 1 ;
for ( V_58 = 1 ; V_58 <= V_104 ; V_58 ++ ) {
int V_105 ;
int V_106 , V_107 ;
V_105 = V_58 * V_108 ;
V_106 = V_105 % V_101 ;
V_107 = ( V_105 - V_106 ) * 100 / V_105 ;
if ( V_107 > V_102 ) {
V_102 = V_107 ;
V_103 = V_58 ;
}
}
return V_103 ;
}
static struct V_4 * F_93 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = (struct V_4 * ) V_1 -> V_59 ;
F_57 ( V_4 -> V_42 != V_43 ) ;
return V_4 ;
}
static struct V_1 * F_94 ( struct V_1 * V_1 )
{
if ( F_95 ( F_5 ( V_1 ) ) )
return NULL ;
return V_1 -> V_109 ;
}
static void F_96 ( unsigned long V_13 , struct V_1 * * V_1 ,
unsigned int * V_110 )
{
V_13 >>= V_111 ;
* V_1 = F_97 ( V_13 >> V_112 ) ;
* V_110 = ( V_13 & V_113 ) ;
}
static unsigned long F_98 ( struct V_1 * V_1 , unsigned int V_110 )
{
unsigned long V_13 ;
V_13 = F_99 ( V_1 ) << V_112 ;
V_13 |= V_110 & V_113 ;
V_13 <<= V_111 ;
return V_13 ;
}
static unsigned long F_100 ( unsigned long V_11 )
{
return * ( unsigned long * ) V_11 ;
}
static unsigned long F_101 ( struct V_1 * V_1 , void * V_13 )
{
if ( F_95 ( F_5 ( V_1 ) ) ) {
F_51 ( ! F_45 ( V_1 ) , V_1 ) ;
return V_1 -> V_73 ;
} else
return * ( unsigned long * ) V_13 ;
}
static inline int F_102 ( unsigned long V_11 )
{
return F_103 ( V_114 , ( unsigned long * ) V_11 ) ;
}
static inline int F_104 ( unsigned long V_11 )
{
return F_105 ( V_114 , ( unsigned long * ) V_11 ) ;
}
static void F_106 ( unsigned long V_11 )
{
F_107 ( V_114 , ( unsigned long * ) V_11 ) ;
}
static void F_108 ( unsigned long V_11 )
{
F_109 ( V_114 , ( unsigned long * ) V_11 ) ;
}
static void F_110 ( struct V_1 * V_1 )
{
F_111 ( V_1 ) ;
F_112 ( V_1 ) ;
F_113 ( V_1 ) ;
F_114 ( V_1 , 0 ) ;
F_115 ( V_1 ) ;
F_3 ( V_1 ) ;
V_1 -> V_109 = NULL ;
}
void F_116 ( struct V_4 * V_4 )
{
struct V_1 * V_1 = F_50 ( V_4 ) ;
do {
F_117 ( V_1 ) ;
} while ( ( V_1 = F_94 ( V_1 ) ) != NULL );
}
int F_118 ( struct V_4 * V_4 )
{
struct V_1 * V_115 , * V_116 ;
for ( V_115 = F_50 ( V_4 ) ; V_115 != NULL ; V_115 =
F_94 ( V_115 ) ) {
if ( ! F_119 ( V_115 ) ) {
V_116 = V_115 ;
goto V_117;
}
}
return 1 ;
V_117:
for ( V_115 = F_50 ( V_4 ) ; V_115 != V_116 ; V_115 =
F_94 ( V_115 ) )
F_120 ( V_115 ) ;
return 0 ;
}
static void F_121 ( struct V_2 * V_3 , struct V_49 * V_44 ,
struct V_4 * V_4 )
{
struct V_1 * V_1 , * V_118 ;
enum V_40 V_89 ;
unsigned int V_39 ;
F_56 ( V_4 , & V_39 , & V_89 ) ;
F_122 ( & V_44 -> V_74 ) ;
F_88 ( F_47 ( V_4 ) ) ;
F_88 ( V_89 != V_90 ) ;
V_118 = V_1 = F_50 ( V_4 ) ;
do {
F_51 ( ! F_123 ( V_1 ) , V_1 ) ;
V_118 = F_94 ( V_1 ) ;
F_110 ( V_1 ) ;
F_120 ( V_1 ) ;
F_124 ( V_1 , V_119 ) ;
F_125 ( V_1 ) ;
V_1 = V_118 ;
} while ( V_1 != NULL );
F_26 ( V_3 , V_4 ) ;
F_64 ( V_44 , V_77 , V_44 -> V_60 ) ;
F_126 ( V_44 -> V_79 ,
& V_3 -> V_120 ) ;
}
static void F_127 ( struct V_2 * V_3 , struct V_49 * V_44 ,
struct V_4 * V_4 )
{
F_88 ( F_47 ( V_4 ) ) ;
F_88 ( F_89 ( & V_4 -> V_97 ) ) ;
if ( ! F_118 ( V_4 ) ) {
F_14 ( V_3 ) ;
return;
}
F_87 ( V_44 , V_4 , V_90 ) ;
F_121 ( V_3 , V_44 , V_4 ) ;
}
static void F_128 ( struct V_49 * V_44 , struct V_4 * V_4 )
{
unsigned int V_38 = 1 ;
unsigned long V_121 = 0 ;
struct V_1 * V_1 = F_50 ( V_4 ) ;
while ( V_1 ) {
struct V_1 * V_122 ;
struct V_123 * V_124 ;
void * V_125 ;
F_53 ( V_1 , V_121 ) ;
V_125 = F_129 ( V_1 ) ;
V_124 = (struct V_123 * ) V_125 + V_121 / sizeof( * V_124 ) ;
while ( ( V_121 += V_44 -> V_17 ) < V_108 ) {
V_124 -> V_118 = V_38 ++ << V_111 ;
V_124 += V_44 -> V_17 / sizeof( * V_124 ) ;
}
V_122 = F_94 ( V_1 ) ;
if ( V_122 ) {
V_124 -> V_118 = V_38 ++ << V_111 ;
} else {
V_124 -> V_118 = - 1 << V_111 ;
}
F_130 ( V_125 ) ;
V_1 = V_122 ;
V_121 %= V_108 ;
}
F_55 ( V_4 , 0 ) ;
}
static void F_131 ( struct V_49 * V_44 , struct V_4 * V_4 ,
struct V_1 * V_18 [] )
{
int V_58 ;
struct V_1 * V_1 ;
struct V_1 * V_126 = NULL ;
int V_127 = V_44 -> V_79 ;
for ( V_58 = 0 ; V_58 < V_127 ; V_58 ++ ) {
V_1 = V_18 [ V_58 ] ;
F_114 ( V_1 , ( unsigned long ) V_4 ) ;
V_1 -> V_109 = NULL ;
if ( V_58 == 0 ) {
V_4 -> V_35 = V_1 ;
F_132 ( V_1 ) ;
if ( F_95 ( V_44 -> V_60 == 1 &&
V_44 -> V_79 == 1 ) )
F_1 ( V_1 ) ;
} else {
V_126 -> V_109 = V_1 ;
}
if ( V_58 == V_127 - 1 )
F_133 ( V_1 ) ;
V_126 = V_1 ;
}
}
static struct V_4 * F_134 ( struct V_2 * V_3 ,
struct V_49 * V_44 ,
T_1 V_8 )
{
int V_58 ;
struct V_1 * V_18 [ V_104 ] ;
struct V_4 * V_4 = F_25 ( V_3 , V_8 ) ;
if ( ! V_4 )
return NULL ;
memset ( V_4 , 0 , sizeof( struct V_4 ) ) ;
V_4 -> V_42 = V_43 ;
F_11 ( V_4 ) ;
for ( V_58 = 0 ; V_58 < V_44 -> V_79 ; V_58 ++ ) {
struct V_1 * V_1 ;
V_1 = F_135 ( V_8 ) ;
if ( ! V_1 ) {
while ( -- V_58 >= 0 ) {
F_124 ( V_18 [ V_58 ] , V_119 ) ;
F_136 ( V_18 [ V_58 ] ) ;
}
F_26 ( V_3 , V_4 ) ;
return NULL ;
}
F_137 ( V_1 , V_119 ) ;
V_18 [ V_58 ] = V_1 ;
}
F_131 ( V_44 , V_4 , V_18 ) ;
F_128 ( V_44 , V_4 ) ;
return V_4 ;
}
static struct V_4 * F_138 ( struct V_49 * V_44 )
{
int V_58 ;
struct V_4 * V_4 ;
for ( V_58 = V_94 ; V_58 >= V_90 ; V_58 -- ) {
V_4 = F_85 ( & V_44 -> V_96 [ V_58 ] ,
struct V_4 , V_97 ) ;
if ( V_4 )
break;
}
return V_4 ;
}
static inline int F_139 ( struct V_128 * V_129 )
{
if ( V_129 -> V_130 )
return 0 ;
V_129 -> V_130 = F_140 ( V_108 * 2 , NULL ) ;
if ( ! V_129 -> V_130 )
return - V_131 ;
return 0 ;
}
static inline void F_141 ( struct V_128 * V_129 )
{
if ( V_129 -> V_130 )
F_142 ( V_129 -> V_130 ) ;
V_129 -> V_130 = NULL ;
}
static inline void * F_143 ( struct V_128 * V_129 ,
struct V_1 * V_18 [ 2 ] , int V_121 , int V_17 )
{
F_57 ( F_144 ( V_129 -> V_130 , V_132 , V_18 ) ) ;
V_129 -> V_133 = V_129 -> V_130 -> V_134 ;
return V_129 -> V_133 + V_121 ;
}
static inline void F_145 ( struct V_128 * V_129 ,
struct V_1 * V_18 [ 2 ] , int V_121 , int V_17 )
{
unsigned long V_134 = ( unsigned long ) V_129 -> V_133 ;
F_146 ( V_134 , V_108 * 2 ) ;
}
static inline int F_139 ( struct V_128 * V_129 )
{
if ( V_129 -> V_135 )
return 0 ;
V_129 -> V_135 = F_147 ( V_136 , V_137 ) ;
if ( ! V_129 -> V_135 )
return - V_131 ;
return 0 ;
}
static inline void F_141 ( struct V_128 * V_129 )
{
F_148 ( V_129 -> V_135 ) ;
V_129 -> V_135 = NULL ;
}
static void * F_143 ( struct V_128 * V_129 ,
struct V_1 * V_18 [ 2 ] , int V_121 , int V_17 )
{
int V_138 [ 2 ] ;
void * V_134 ;
char * V_139 = V_129 -> V_135 ;
F_149 () ;
if ( V_129 -> V_140 == V_28 )
goto V_100;
V_138 [ 0 ] = V_108 - V_121 ;
V_138 [ 1 ] = V_17 - V_138 [ 0 ] ;
V_134 = F_129 ( V_18 [ 0 ] ) ;
memcpy ( V_139 , V_134 + V_121 , V_138 [ 0 ] ) ;
F_130 ( V_134 ) ;
V_134 = F_129 ( V_18 [ 1 ] ) ;
memcpy ( V_139 + V_138 [ 0 ] , V_134 , V_138 [ 1 ] ) ;
F_130 ( V_134 ) ;
V_100:
return V_129 -> V_135 ;
}
static void F_145 ( struct V_128 * V_129 ,
struct V_1 * V_18 [ 2 ] , int V_121 , int V_17 )
{
int V_138 [ 2 ] ;
void * V_134 ;
char * V_139 ;
if ( V_129 -> V_140 == V_26 )
goto V_100;
V_139 = V_129 -> V_135 ;
V_139 = V_139 + V_6 ;
V_17 -= V_6 ;
V_121 += V_6 ;
V_138 [ 0 ] = V_108 - V_121 ;
V_138 [ 1 ] = V_17 - V_138 [ 0 ] ;
V_134 = F_129 ( V_18 [ 0 ] ) ;
memcpy ( V_134 + V_121 , V_139 , V_138 [ 0 ] ) ;
F_130 ( V_134 ) ;
V_134 = F_129 ( V_18 [ 1 ] ) ;
memcpy ( V_134 , V_139 + V_138 [ 0 ] , V_138 [ 1 ] ) ;
F_130 ( V_134 ) ;
V_100:
F_150 () ;
}
static int F_151 ( struct V_141 * V_142 , unsigned long V_143 ,
void * V_144 )
{
int V_145 , V_146 = ( long ) V_144 ;
struct V_128 * V_129 ;
switch ( V_143 ) {
case V_147 :
V_129 = & F_152 ( V_148 , V_146 ) ;
V_145 = F_139 ( V_129 ) ;
if ( V_145 )
return F_153 ( V_145 ) ;
break;
case V_149 :
case V_150 :
V_129 = & F_152 ( V_148 , V_146 ) ;
F_141 ( V_129 ) ;
break;
}
return V_151 ;
}
static int F_154 ( void )
{
int V_146 , V_152 ( V_145 ) ;
F_155 () ;
F_156 ( & V_153 ) ;
F_157 (cpu) {
V_145 = F_151 ( NULL , V_147 , ( void * ) ( long ) V_146 ) ;
if ( F_158 ( V_145 ) )
break;
}
F_159 () ;
return F_158 ( V_145 ) ;
}
static void F_160 ( void )
{
int V_146 ;
F_155 () ;
F_157 (cpu)
F_151 ( NULL , V_149 , ( void * ) ( long ) V_146 ) ;
F_161 ( & V_153 ) ;
F_159 () ;
}
static void T_4 F_162 ( void )
{
int V_154 ;
V_154 = ( V_136 - V_46 ) / V_47 + 1 ;
if ( ( V_136 - V_46 ) % V_47 )
V_154 += 1 ;
V_48 = V_154 ;
}
static bool F_163 ( struct V_49 * V_155 , int V_79 ,
int V_60 )
{
if ( V_155 -> V_79 == V_79 &&
V_155 -> V_60 == V_60 )
return true ;
return false ;
}
static bool F_164 ( struct V_49 * V_44 , struct V_4 * V_4 )
{
return F_47 ( V_4 ) == V_44 -> V_60 ;
}
unsigned long F_43 ( struct V_2 * V_3 )
{
return F_165 ( & V_3 -> V_120 ) ;
}
void * F_39 ( struct V_2 * V_3 , unsigned long V_11 ,
enum V_23 V_22 )
{
struct V_4 * V_4 ;
struct V_1 * V_1 ;
unsigned long V_13 , V_121 ;
unsigned int V_110 ;
unsigned int V_39 ;
enum V_40 V_89 ;
struct V_49 * V_44 ;
struct V_128 * V_129 ;
struct V_1 * V_18 [ 2 ] ;
void * V_145 ;
F_166 ( F_167 () ) ;
F_106 ( V_11 ) ;
V_13 = F_100 ( V_11 ) ;
F_96 ( V_13 , & V_1 , & V_110 ) ;
V_4 = F_93 ( V_1 ) ;
F_12 ( V_4 ) ;
F_56 ( V_4 , & V_39 , & V_89 ) ;
V_44 = V_3 -> V_49 [ V_39 ] ;
V_121 = ( V_44 -> V_17 * V_110 ) & ~ V_156 ;
V_129 = & F_168 ( V_148 ) ;
V_129 -> V_140 = V_22 ;
if ( V_121 + V_44 -> V_17 <= V_108 ) {
V_129 -> V_133 = F_129 ( V_1 ) ;
V_145 = V_129 -> V_133 + V_121 ;
goto V_100;
}
V_18 [ 0 ] = V_1 ;
V_18 [ 1 ] = F_94 ( V_1 ) ;
F_57 ( ! V_18 [ 1 ] ) ;
V_145 = F_143 ( V_129 , V_18 , V_121 , V_44 -> V_17 ) ;
V_100:
if ( F_60 ( ! F_5 ( V_1 ) ) )
V_145 += V_6 ;
return V_145 ;
}
void F_41 ( struct V_2 * V_3 , unsigned long V_11 )
{
struct V_4 * V_4 ;
struct V_1 * V_1 ;
unsigned long V_13 , V_121 ;
unsigned int V_110 ;
unsigned int V_39 ;
enum V_40 V_89 ;
struct V_49 * V_44 ;
struct V_128 * V_129 ;
V_13 = F_100 ( V_11 ) ;
F_96 ( V_13 , & V_1 , & V_110 ) ;
V_4 = F_93 ( V_1 ) ;
F_56 ( V_4 , & V_39 , & V_89 ) ;
V_44 = V_3 -> V_49 [ V_39 ] ;
V_121 = ( V_44 -> V_17 * V_110 ) & ~ V_156 ;
V_129 = F_169 ( & V_148 ) ;
if ( V_121 + V_44 -> V_17 <= V_108 )
F_130 ( V_129 -> V_133 ) ;
else {
struct V_1 * V_18 [ 2 ] ;
V_18 [ 0 ] = V_1 ;
V_18 [ 1 ] = F_94 ( V_1 ) ;
F_57 ( ! V_18 [ 1 ] ) ;
F_145 ( V_129 , V_18 , V_121 , V_44 -> V_17 ) ;
}
F_170 ( V_148 ) ;
F_13 ( V_4 ) ;
F_108 ( V_11 ) ;
}
static unsigned long F_171 ( struct V_49 * V_44 ,
struct V_4 * V_4 , unsigned long V_11 )
{
int V_58 , V_157 , V_37 ;
unsigned long V_13 ;
struct V_123 * V_124 ;
struct V_1 * V_158 ;
unsigned long V_159 ;
void * V_125 ;
V_11 |= V_160 ;
V_13 = F_54 ( V_4 ) ;
V_37 = V_13 * V_44 -> V_17 ;
V_157 = V_37 >> V_31 ;
V_159 = V_37 & ~ V_156 ;
V_158 = F_50 ( V_4 ) ;
for ( V_58 = 0 ; V_58 < V_157 ; V_58 ++ )
V_158 = F_94 ( V_158 ) ;
V_125 = F_129 ( V_158 ) ;
V_124 = (struct V_123 * ) V_125 + V_159 / sizeof( * V_124 ) ;
F_55 ( V_4 , V_124 -> V_118 >> V_111 ) ;
if ( F_60 ( ! F_5 ( V_158 ) ) )
V_124 -> V_11 = V_11 ;
else
V_4 -> V_35 -> V_73 = V_11 ;
F_130 ( V_125 ) ;
F_49 ( V_4 , 1 ) ;
F_63 ( V_44 , V_78 , 1 ) ;
V_13 = F_98 ( V_158 , V_13 ) ;
return V_13 ;
}
unsigned long F_34 ( struct V_2 * V_3 , T_2 V_17 , T_1 V_8 )
{
unsigned long V_11 , V_13 ;
struct V_49 * V_44 ;
enum V_40 V_99 ;
struct V_4 * V_4 ;
if ( F_95 ( ! V_17 || V_17 > V_136 ) )
return 0 ;
V_11 = F_21 ( V_3 , V_8 ) ;
if ( ! V_11 )
return 0 ;
V_17 += V_6 ;
V_44 = V_3 -> V_49 [ F_59 ( V_17 ) ] ;
F_74 ( & V_44 -> V_74 ) ;
V_4 = F_138 ( V_44 ) ;
if ( F_60 ( V_4 ) ) {
V_13 = F_171 ( V_44 , V_4 , V_11 ) ;
F_91 ( V_44 , V_4 ) ;
F_27 ( V_11 , V_13 ) ;
F_76 ( & V_44 -> V_74 ) ;
return V_11 ;
}
F_76 ( & V_44 -> V_74 ) ;
V_4 = F_134 ( V_3 , V_44 , V_8 ) ;
if ( ! V_4 ) {
F_23 ( V_3 , V_11 ) ;
return 0 ;
}
F_74 ( & V_44 -> V_74 ) ;
V_13 = F_171 ( V_44 , V_4 , V_11 ) ;
V_99 = F_83 ( V_44 , V_4 ) ;
F_84 ( V_44 , V_4 , V_99 ) ;
F_58 ( V_4 , V_44 -> V_73 , V_99 ) ;
F_27 ( V_11 , V_13 ) ;
F_172 ( V_44 -> V_79 ,
& V_3 -> V_120 ) ;
F_63 ( V_44 , V_77 , V_44 -> V_60 ) ;
F_16 ( V_3 , V_4 ) ;
F_76 ( & V_44 -> V_74 ) ;
return V_11 ;
}
static void F_173 ( struct V_49 * V_44 , unsigned long V_13 )
{
struct V_123 * V_124 ;
struct V_4 * V_4 ;
struct V_1 * V_161 ;
unsigned long V_162 ;
unsigned int V_163 ;
void * V_125 ;
V_13 &= ~ V_160 ;
F_96 ( V_13 , & V_161 , & V_163 ) ;
V_162 = ( V_44 -> V_17 * V_163 ) & ~ V_156 ;
V_4 = F_93 ( V_161 ) ;
V_125 = F_129 ( V_161 ) ;
V_124 = (struct V_123 * ) ( V_125 + V_162 ) ;
V_124 -> V_118 = F_54 ( V_4 ) << V_111 ;
F_130 ( V_125 ) ;
F_55 ( V_4 , V_163 ) ;
F_49 ( V_4 , - 1 ) ;
F_64 ( V_44 , V_78 , 1 ) ;
}
void F_36 ( struct V_2 * V_3 , unsigned long V_11 )
{
struct V_4 * V_4 ;
struct V_1 * V_161 ;
unsigned long V_13 ;
unsigned int V_163 ;
int V_39 ;
struct V_49 * V_44 ;
enum V_40 V_41 ;
bool V_32 ;
if ( F_95 ( ! V_11 ) )
return;
F_106 ( V_11 ) ;
V_13 = F_100 ( V_11 ) ;
F_96 ( V_13 , & V_161 , & V_163 ) ;
V_4 = F_93 ( V_161 ) ;
F_12 ( V_4 ) ;
F_56 ( V_4 , & V_39 , & V_41 ) ;
V_44 = V_3 -> V_49 [ V_39 ] ;
F_74 ( & V_44 -> V_74 ) ;
F_173 ( V_44 , V_13 ) ;
V_41 = F_91 ( V_44 , V_4 ) ;
if ( V_41 != V_90 ) {
F_13 ( V_4 ) ;
goto V_100;
}
V_32 = F_44 ( V_4 ) ;
F_13 ( V_4 ) ;
if ( F_60 ( ! V_32 ) )
F_127 ( V_3 , V_44 , V_4 ) ;
V_100:
F_76 ( & V_44 -> V_74 ) ;
F_108 ( V_11 ) ;
F_23 ( V_3 , V_11 ) ;
}
static void F_174 ( struct V_49 * V_44 , unsigned long V_164 ,
unsigned long V_165 )
{
struct V_1 * V_166 , * V_167 ;
unsigned int V_168 , V_169 ;
unsigned long V_170 , V_171 ;
void * V_172 , * V_173 ;
int V_174 , V_175 , V_17 ;
int V_176 = 0 ;
V_174 = V_175 = V_44 -> V_17 ;
F_96 ( V_165 , & V_166 , & V_168 ) ;
F_96 ( V_164 , & V_167 , & V_169 ) ;
V_170 = ( V_44 -> V_17 * V_168 ) & ~ V_156 ;
V_171 = ( V_44 -> V_17 * V_169 ) & ~ V_156 ;
if ( V_170 + V_44 -> V_17 > V_108 )
V_174 = V_108 - V_170 ;
if ( V_171 + V_44 -> V_17 > V_108 )
V_175 = V_108 - V_171 ;
V_172 = F_129 ( V_166 ) ;
V_173 = F_129 ( V_167 ) ;
while ( 1 ) {
V_17 = F_62 ( V_174 , V_175 ) ;
memcpy ( V_173 + V_171 , V_172 + V_170 , V_17 ) ;
V_176 += V_17 ;
if ( V_176 == V_44 -> V_17 )
break;
V_170 += V_17 ;
V_174 -= V_17 ;
V_171 += V_17 ;
V_175 -= V_17 ;
if ( V_170 >= V_108 ) {
F_130 ( V_173 ) ;
F_130 ( V_172 ) ;
V_166 = F_94 ( V_166 ) ;
V_172 = F_129 ( V_166 ) ;
V_173 = F_129 ( V_167 ) ;
V_174 = V_44 -> V_17 - V_176 ;
V_170 = 0 ;
}
if ( V_171 >= V_108 ) {
F_130 ( V_173 ) ;
V_167 = F_94 ( V_167 ) ;
V_173 = F_129 ( V_167 ) ;
V_175 = V_44 -> V_17 - V_176 ;
V_171 = 0 ;
}
}
F_130 ( V_173 ) ;
F_130 ( V_172 ) ;
}
static unsigned long F_175 ( struct V_49 * V_44 ,
struct V_1 * V_1 , int * V_110 )
{
unsigned long V_95 ;
int V_37 = 0 ;
int V_73 = * V_110 ;
unsigned long V_11 = 0 ;
void * V_134 = F_129 ( V_1 ) ;
V_37 = F_52 ( V_1 ) ;
V_37 += V_44 -> V_17 * V_73 ;
while ( V_37 < V_108 ) {
V_95 = F_101 ( V_1 , V_134 + V_37 ) ;
if ( V_95 & V_160 ) {
V_11 = V_95 & ~ V_160 ;
if ( F_104 ( V_11 ) )
break;
V_11 = 0 ;
}
V_37 += V_44 -> V_17 ;
V_73 ++ ;
}
F_130 ( V_134 ) ;
* V_110 = V_73 ;
return V_11 ;
}
static int F_176 ( struct V_2 * V_3 , struct V_49 * V_44 ,
struct V_177 * V_178 )
{
unsigned long V_179 , V_180 ;
unsigned long V_11 ;
struct V_1 * V_166 = V_178 -> V_166 ;
struct V_1 * V_167 = V_178 -> V_167 ;
int V_110 = V_178 -> V_110 ;
int V_145 = 0 ;
while ( 1 ) {
V_11 = F_175 ( V_44 , V_166 , & V_110 ) ;
if ( ! V_11 ) {
V_166 = F_94 ( V_166 ) ;
if ( ! V_166 )
break;
V_110 = 0 ;
continue;
}
if ( F_164 ( V_44 , F_93 ( V_167 ) ) ) {
F_108 ( V_11 ) ;
V_145 = - V_131 ;
break;
}
V_179 = F_100 ( V_11 ) ;
V_180 = F_171 ( V_44 , F_93 ( V_167 ) , V_11 ) ;
F_174 ( V_44 , V_180 , V_179 ) ;
V_110 ++ ;
V_180 |= F_177 ( V_114 ) ;
F_27 ( V_11 , V_180 ) ;
F_108 ( V_11 ) ;
F_173 ( V_44 , V_179 ) ;
}
V_178 -> V_166 = V_166 ;
V_178 -> V_110 = V_110 ;
return V_145 ;
}
static struct V_4 * F_178 ( struct V_49 * V_44 , bool V_181 )
{
int V_58 ;
struct V_4 * V_4 ;
enum V_40 V_89 [ 2 ] = { V_93 , V_94 } ;
if ( ! V_181 ) {
V_89 [ 0 ] = V_94 ;
V_89 [ 1 ] = V_93 ;
}
for ( V_58 = 0 ; V_58 < 2 ; V_58 ++ ) {
V_4 = F_85 ( & V_44 -> V_96 [ V_89 [ V_58 ] ] ,
struct V_4 , V_97 ) ;
if ( V_4 ) {
F_88 ( F_44 ( V_4 ) ) ;
F_87 ( V_44 , V_4 , V_89 [ V_58 ] ) ;
return V_4 ;
}
}
return V_4 ;
}
static enum V_40 F_179 ( struct V_49 * V_44 ,
struct V_4 * V_4 )
{
enum V_40 V_41 ;
F_88 ( F_44 ( V_4 ) ) ;
V_41 = F_83 ( V_44 , V_4 ) ;
F_84 ( V_44 , V_4 , V_41 ) ;
F_58 ( V_4 , V_44 -> V_73 , V_41 ) ;
return V_41 ;
}
static struct V_83 * F_180 ( struct V_182 * V_183 ,
int V_12 , const char * V_184 , void * V_185 )
{
static const struct V_186 V_187 = {
. V_188 = V_189 ,
} ;
return F_181 ( V_183 , L_26 , NULL , & V_187 , V_190 ) ;
}
static int F_7 ( void )
{
int V_145 = 0 ;
V_191 = F_182 ( & V_192 ) ;
if ( F_183 ( V_191 ) )
V_145 = F_184 ( V_191 ) ;
return V_145 ;
}
static void F_8 ( void )
{
F_185 ( V_191 ) ;
}
static void F_11 ( struct V_4 * V_4 )
{
F_186 ( & V_4 -> V_74 ) ;
}
static void F_12 ( struct V_4 * V_4 )
{
F_187 ( & V_4 -> V_74 ) ;
}
static void F_13 ( struct V_4 * V_4 )
{
F_188 ( & V_4 -> V_74 ) ;
}
static void F_189 ( struct V_4 * V_4 )
{
F_190 ( & V_4 -> V_74 ) ;
}
static void F_191 ( struct V_4 * V_4 )
{
F_192 ( & V_4 -> V_74 ) ;
}
static void F_193 ( struct V_4 * V_4 )
{
V_4 -> V_32 ++ ;
}
static void F_194 ( struct V_4 * V_4 )
{
V_4 -> V_32 -- ;
}
static void F_195 ( struct V_49 * V_44 , struct V_4 * V_4 ,
struct V_1 * V_193 , struct V_1 * V_194 )
{
struct V_1 * V_1 ;
struct V_1 * V_18 [ V_104 ] = { NULL , } ;
int V_45 = 0 ;
V_1 = F_50 ( V_4 ) ;
do {
if ( V_1 == V_194 )
V_18 [ V_45 ] = V_193 ;
else
V_18 [ V_45 ] = V_1 ;
V_45 ++ ;
} while ( ( V_1 = F_94 ( V_1 ) ) != NULL );
F_131 ( V_44 , V_4 , V_18 ) ;
F_53 ( V_193 , F_52 ( V_194 ) ) ;
if ( F_95 ( F_5 ( V_194 ) ) )
V_193 -> V_73 = V_194 -> V_73 ;
F_196 ( V_193 , F_197 ( V_194 ) ) ;
}
bool F_198 ( struct V_1 * V_1 , T_6 V_195 )
{
struct V_2 * V_3 ;
struct V_49 * V_44 ;
int V_39 ;
enum V_40 V_41 ;
struct V_4 * V_4 ;
struct V_196 * V_197 ;
F_51 ( ! F_199 ( V_1 ) , V_1 ) ;
F_51 ( F_200 ( V_1 ) , V_1 ) ;
V_4 = F_93 ( V_1 ) ;
F_56 ( V_4 , & V_39 , & V_41 ) ;
V_197 = F_197 ( V_1 ) ;
V_3 = V_197 -> V_198 ;
V_44 = V_3 -> V_49 [ V_39 ] ;
F_74 ( & V_44 -> V_74 ) ;
if ( F_47 ( V_4 ) == 0 ) {
F_76 ( & V_44 -> V_74 ) ;
return false ;
}
if ( F_89 ( & V_4 -> V_97 ) && ! F_44 ( V_4 ) ) {
F_76 ( & V_44 -> V_74 ) ;
return false ;
}
if ( ! F_89 ( & V_4 -> V_97 ) && ! F_44 ( V_4 ) ) {
F_56 ( V_4 , & V_39 , & V_41 ) ;
F_87 ( V_44 , V_4 , V_41 ) ;
}
F_193 ( V_4 ) ;
F_76 ( & V_44 -> V_74 ) ;
return true ;
}
int F_201 ( struct V_196 * V_197 , struct V_1 * V_193 ,
struct V_1 * V_1 , enum V_199 V_195 )
{
struct V_2 * V_3 ;
struct V_49 * V_44 ;
int V_39 ;
enum V_40 V_41 ;
struct V_4 * V_4 ;
struct V_1 * V_200 ;
void * V_172 , * V_173 , * V_134 ;
int V_37 , V_201 ;
unsigned long V_11 , V_95 ;
unsigned long V_202 , V_203 ;
unsigned int V_110 ;
int V_145 = - V_204 ;
F_51 ( ! F_199 ( V_1 ) , V_1 ) ;
F_51 ( ! F_200 ( V_1 ) , V_1 ) ;
V_4 = F_93 ( V_1 ) ;
F_189 ( V_4 ) ;
F_56 ( V_4 , & V_39 , & V_41 ) ;
V_3 = V_197 -> V_198 ;
V_44 = V_3 -> V_49 [ V_39 ] ;
V_37 = F_52 ( V_1 ) ;
F_74 ( & V_44 -> V_74 ) ;
if ( ! F_47 ( V_4 ) ) {
V_145 = - V_205 ;
goto V_206;
}
V_201 = V_37 ;
V_172 = F_129 ( V_1 ) ;
while ( V_201 < V_108 ) {
V_95 = F_101 ( V_1 , V_172 + V_201 ) ;
if ( V_95 & V_160 ) {
V_11 = V_95 & ~ V_160 ;
if ( ! F_104 ( V_11 ) )
goto V_207;
}
V_201 += V_44 -> V_17 ;
}
V_173 = F_129 ( V_193 ) ;
memcpy ( V_173 , V_172 , V_108 ) ;
F_130 ( V_173 ) ;
for ( V_134 = V_172 + V_37 ; V_134 < V_172 + V_201 ;
V_134 += V_44 -> V_17 ) {
V_95 = F_101 ( V_1 , V_134 ) ;
if ( V_95 & V_160 ) {
V_11 = V_95 & ~ V_160 ;
if ( ! F_102 ( V_11 ) )
F_202 () ;
V_202 = F_100 ( V_11 ) ;
F_96 ( V_202 , & V_200 , & V_110 ) ;
V_203 = ( unsigned long ) F_98 ( V_193 ,
V_110 ) ;
V_203 |= F_177 ( V_114 ) ;
F_27 ( V_11 , V_203 ) ;
}
}
F_195 ( V_44 , V_4 , V_193 , V_1 ) ;
F_203 ( V_193 ) ;
F_194 ( V_4 ) ;
if ( ! F_44 ( V_4 ) )
F_179 ( V_44 , V_4 ) ;
F_110 ( V_1 ) ;
F_125 ( V_1 ) ;
V_1 = V_193 ;
V_145 = V_208 ;
V_207:
for ( V_134 = V_172 + V_37 ; V_134 < V_172 + V_201 ;
V_134 += V_44 -> V_17 ) {
V_95 = F_101 ( V_1 , V_134 ) ;
if ( V_95 & V_160 ) {
V_11 = V_95 & ~ V_160 ;
if ( ! F_102 ( V_11 ) )
F_202 () ;
F_108 ( V_11 ) ;
}
}
F_130 ( V_172 ) ;
V_206:
F_76 ( & V_44 -> V_74 ) ;
F_191 ( V_4 ) ;
return V_145 ;
}
void F_204 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
struct V_49 * V_44 ;
int V_39 ;
enum V_40 V_89 ;
struct V_196 * V_197 ;
struct V_4 * V_4 ;
F_51 ( ! F_199 ( V_1 ) , V_1 ) ;
F_51 ( ! F_200 ( V_1 ) , V_1 ) ;
V_4 = F_93 ( V_1 ) ;
F_56 ( V_4 , & V_39 , & V_89 ) ;
V_197 = F_197 ( V_1 ) ;
V_3 = V_197 -> V_198 ;
V_44 = V_3 -> V_49 [ V_39 ] ;
F_74 ( & V_44 -> V_74 ) ;
F_194 ( V_4 ) ;
if ( ! F_44 ( V_4 ) ) {
V_89 = F_179 ( V_44 , V_4 ) ;
if ( V_89 == V_90 )
F_205 ( & V_3 -> V_209 ) ;
}
F_76 ( & V_44 -> V_74 ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
V_3 -> V_80 = F_206 ( V_191 -> V_210 ) ;
if ( F_183 ( V_3 -> V_80 ) ) {
V_3 -> V_80 = NULL ;
return 1 ;
}
V_3 -> V_80 -> V_211 -> V_198 = V_3 ;
V_3 -> V_80 -> V_211 -> V_212 = & V_213 ;
return 0 ;
}
static void F_10 ( struct V_2 * V_3 )
{
F_207 ( & V_3 -> V_209 ) ;
F_208 ( V_3 -> V_80 ) ;
}
static void F_209 ( struct V_214 * V_215 )
{
int V_58 ;
struct V_49 * V_44 ;
unsigned int V_39 ;
enum V_40 V_41 ;
struct V_4 * V_4 , * V_216 ;
F_210 ( V_217 ) ;
struct V_2 * V_3 = F_211 ( V_215 , struct V_2 ,
V_209 ) ;
for ( V_58 = 0 ; V_58 < V_48 ; V_58 ++ ) {
V_44 = V_3 -> V_49 [ V_58 ] ;
if ( V_44 -> V_73 != V_58 )
continue;
F_74 ( & V_44 -> V_74 ) ;
F_212 ( & V_44 -> V_96 [ V_90 ] , & V_217 ) ;
F_76 ( & V_44 -> V_74 ) ;
}
F_213 (zspage, tmp, &free_pages, list) {
F_214 ( & V_4 -> V_97 ) ;
F_116 ( V_4 ) ;
F_56 ( V_4 , & V_39 , & V_41 ) ;
F_88 ( V_41 != V_90 ) ;
V_44 = V_3 -> V_49 [ V_39 ] ;
F_74 ( & V_44 -> V_74 ) ;
F_121 ( V_3 , V_3 -> V_49 [ V_39 ] , V_4 ) ;
F_76 ( & V_44 -> V_74 ) ;
}
}
static void F_14 ( struct V_2 * V_3 )
{
F_205 ( & V_3 -> V_209 ) ;
}
static void F_15 ( struct V_2 * V_3 )
{
F_215 ( & V_3 -> V_209 , F_209 ) ;
}
static void F_16 ( struct V_2 * V_3 , struct V_4 * V_4 )
{
struct V_1 * V_1 = F_50 ( V_4 ) ;
do {
F_216 ( ! F_119 ( V_1 ) ) ;
F_196 ( V_1 , V_3 -> V_80 -> V_211 ) ;
F_120 ( V_1 ) ;
} while ( ( V_1 = F_94 ( V_1 ) ) != NULL );
}
static unsigned long F_75 ( struct V_49 * V_44 )
{
unsigned long V_218 ;
unsigned long V_63 = F_65 ( V_44 , V_77 ) ;
unsigned long V_64 = F_65 ( V_44 , V_78 ) ;
if ( V_63 <= V_64 )
return 0 ;
V_218 = V_63 - V_64 ;
V_218 /= V_44 -> V_60 ;
return V_218 * V_44 -> V_79 ;
}
static void F_217 ( struct V_2 * V_3 , struct V_49 * V_44 )
{
struct V_177 V_178 ;
struct V_4 * V_219 ;
struct V_4 * V_220 = NULL ;
F_74 ( & V_44 -> V_74 ) ;
while ( ( V_219 = F_178 ( V_44 , true ) ) ) {
if ( ! F_75 ( V_44 ) )
break;
V_178 . V_110 = 0 ;
V_178 . V_166 = F_50 ( V_219 ) ;
while ( ( V_220 = F_178 ( V_44 , false ) ) ) {
V_178 . V_167 = F_50 ( V_220 ) ;
if ( ! F_176 ( V_3 , V_44 , & V_178 ) )
break;
F_179 ( V_44 , V_220 ) ;
}
if ( V_220 == NULL )
break;
F_179 ( V_44 , V_220 ) ;
if ( F_179 ( V_44 , V_219 ) == V_90 ) {
F_127 ( V_3 , V_44 , V_219 ) ;
V_3 -> V_52 . V_221 += V_44 -> V_79 ;
}
F_76 ( & V_44 -> V_74 ) ;
F_218 () ;
F_74 ( & V_44 -> V_74 ) ;
}
if ( V_219 )
F_179 ( V_44 , V_219 ) ;
F_76 ( & V_44 -> V_74 ) ;
}
unsigned long F_219 ( struct V_2 * V_3 )
{
int V_58 ;
struct V_49 * V_44 ;
for ( V_58 = V_48 - 1 ; V_58 >= 0 ; V_58 -- ) {
V_44 = V_3 -> V_49 [ V_58 ] ;
if ( ! V_44 )
continue;
if ( V_44 -> V_73 != V_58 )
continue;
F_217 ( V_3 , V_44 ) ;
}
return V_3 -> V_52 . V_221 ;
}
void F_220 ( struct V_2 * V_3 , struct F_220 * V_52 )
{
memcpy ( V_52 , & V_3 -> V_52 , sizeof( struct F_220 ) ) ;
}
static unsigned long F_221 ( struct V_222 * V_222 ,
struct V_223 * V_224 )
{
unsigned long V_225 ;
struct V_2 * V_3 = F_211 ( V_222 , struct V_2 ,
V_222 ) ;
V_225 = V_3 -> V_52 . V_221 ;
V_225 = F_219 ( V_3 ) - V_225 ;
return V_225 ? V_225 : V_226 ;
}
static unsigned long F_222 ( struct V_222 * V_222 ,
struct V_223 * V_224 )
{
int V_58 ;
struct V_49 * V_44 ;
unsigned long V_227 = 0 ;
struct V_2 * V_3 = F_211 ( V_222 , struct V_2 ,
V_222 ) ;
for ( V_58 = V_48 - 1 ; V_58 >= 0 ; V_58 -- ) {
V_44 = V_3 -> V_49 [ V_58 ] ;
if ( ! V_44 )
continue;
if ( V_44 -> V_73 != V_58 )
continue;
V_227 += F_75 ( V_44 ) ;
}
return V_227 ;
}
static void F_223 ( struct V_2 * V_3 )
{
if ( V_3 -> V_228 ) {
F_224 ( & V_3 -> V_222 ) ;
V_3 -> V_228 = false ;
}
}
static int F_225 ( struct V_2 * V_3 )
{
V_3 -> V_222 . V_229 = F_221 ;
V_3 -> V_222 . V_230 = F_222 ;
V_3 -> V_222 . V_231 = 0 ;
V_3 -> V_222 . V_232 = V_233 ;
return F_226 ( & V_3 -> V_222 ) ;
}
struct V_2 * F_30 ( const char * V_14 )
{
int V_58 ;
struct V_2 * V_3 ;
struct V_49 * V_234 = NULL ;
V_3 = F_227 ( sizeof( * V_3 ) , V_137 ) ;
if ( ! V_3 )
return NULL ;
F_15 ( V_3 ) ;
V_3 -> V_49 = F_228 ( V_48 , sizeof( struct V_49 * ) ,
V_137 ) ;
if ( ! V_3 -> V_49 ) {
F_148 ( V_3 ) ;
return NULL ;
}
V_3 -> V_14 = F_229 ( V_14 , V_137 ) ;
if ( ! V_3 -> V_14 )
goto V_235;
if ( F_17 ( V_3 ) )
goto V_235;
for ( V_58 = V_48 - 1 ; V_58 >= 0 ; V_58 -- ) {
int V_17 ;
int V_79 ;
int V_60 ;
struct V_49 * V_44 ;
int V_41 = 0 ;
V_17 = V_46 + V_58 * V_47 ;
if ( V_17 > V_136 )
V_17 = V_136 ;
V_79 = F_92 ( V_17 ) ;
V_60 = V_79 * V_108 / V_17 ;
if ( V_234 ) {
if ( F_163 ( V_234 , V_79 , V_60 ) ) {
V_3 -> V_49 [ V_58 ] = V_234 ;
continue;
}
}
V_44 = F_227 ( sizeof( struct V_49 ) , V_137 ) ;
if ( ! V_44 )
goto V_235;
V_44 -> V_17 = V_17 ;
V_44 -> V_73 = V_58 ;
V_44 -> V_79 = V_79 ;
V_44 -> V_60 = V_60 ;
F_230 ( & V_44 -> V_74 ) ;
V_3 -> V_49 [ V_58 ] = V_44 ;
for ( V_41 = V_90 ; V_41 < V_236 ;
V_41 ++ )
F_231 ( & V_44 -> V_96 [ V_41 ] ) ;
V_234 = V_44 ;
}
F_80 ( V_3 , V_14 ) ;
if ( F_9 ( V_3 ) )
goto V_235;
if ( F_225 ( V_3 ) == 0 )
V_3 -> V_228 = true ;
return V_3 ;
V_235:
F_32 ( V_3 ) ;
return NULL ;
}
void F_32 ( struct V_2 * V_3 )
{
int V_58 ;
F_223 ( V_3 ) ;
F_10 ( V_3 ) ;
F_82 ( V_3 ) ;
for ( V_58 = 0 ; V_58 < V_48 ; V_58 ++ ) {
int V_89 ;
struct V_49 * V_44 = V_3 -> V_49 [ V_58 ] ;
if ( ! V_44 )
continue;
if ( V_44 -> V_73 != V_58 )
continue;
for ( V_89 = V_90 ; V_89 < V_236 ; V_89 ++ ) {
if ( ! F_89 ( & V_44 -> V_96 [ V_89 ] ) ) {
F_232 ( L_27 ,
V_44 -> V_17 , V_89 ) ;
}
}
F_148 ( V_44 ) ;
}
F_20 ( V_3 ) ;
F_148 ( V_3 -> V_49 ) ;
F_148 ( V_3 -> V_14 ) ;
F_148 ( V_3 ) ;
}
static int T_4 F_233 ( void )
{
int V_145 ;
V_145 = F_7 () ;
if ( V_145 )
goto V_100;
V_145 = F_154 () ;
if ( V_145 )
goto V_237;
F_162 () ;
#ifdef F_234
F_235 ( & V_238 ) ;
#endif
F_66 () ;
return 0 ;
V_237:
F_160 () ;
F_8 () ;
V_100:
return V_145 ;
}
static void T_5 F_236 ( void )
{
#ifdef F_234
F_237 ( & V_238 ) ;
#endif
F_8 () ;
F_160 () ;
F_70 () ;
}
