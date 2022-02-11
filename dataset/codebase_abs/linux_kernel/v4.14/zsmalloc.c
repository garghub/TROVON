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
static T_4 int F_45 ( struct V_1 * V_1 )
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
return F_62 ( int , V_48 - 1 , V_45 ) ;
}
static inline void F_63 ( struct V_49 * V_44 ,
int type , unsigned long V_50 )
{
V_44 -> V_51 . V_52 [ type ] += V_50 ;
}
static inline void F_64 ( struct V_49 * V_44 ,
int type , unsigned long V_50 )
{
V_44 -> V_51 . V_52 [ type ] -= V_50 ;
}
static inline unsigned long F_65 ( struct V_49 * V_44 ,
int type )
{
return V_44 -> V_51 . V_52 [ type ] ;
}
static void T_5 F_66 ( void )
{
if ( ! F_67 () ) {
F_68 ( L_3 ) ;
return;
}
V_53 = F_69 ( L_4 , NULL ) ;
if ( ! V_53 )
F_68 ( L_5 ) ;
}
static void T_6 F_70 ( void )
{
F_71 ( V_53 ) ;
}
static int F_72 ( struct V_54 * V_55 , void * V_56 )
{
int V_57 ;
struct V_2 * V_3 = V_55 -> V_58 ;
struct V_49 * V_44 ;
int V_59 ;
unsigned long V_60 , V_61 ;
unsigned long V_62 , V_63 , V_64 , V_65 ;
unsigned long V_66 = 0 , V_67 = 0 ;
unsigned long V_68 = 0 , V_69 = 0 , V_70 = 0 ;
unsigned long V_71 = 0 ;
F_73 ( V_55 , L_6 ,
L_7 , L_8 , L_9 , L_10 ,
L_11 , L_12 , L_13 ,
L_14 , L_15 ) ;
for ( V_57 = 0 ; V_57 < V_48 ; V_57 ++ ) {
V_44 = V_3 -> V_49 [ V_57 ] ;
if ( V_44 -> V_72 != V_57 )
continue;
F_74 ( & V_44 -> V_73 ) ;
V_60 = F_65 ( V_44 , V_74 ) ;
V_61 = F_65 ( V_44 , V_75 ) ;
V_62 = F_65 ( V_44 , V_76 ) ;
V_63 = F_65 ( V_44 , V_77 ) ;
V_65 = F_75 ( V_44 ) ;
F_76 ( & V_44 -> V_73 ) ;
V_59 = V_44 -> V_59 ;
V_64 = V_62 / V_59 *
V_44 -> V_78 ;
F_73 ( V_55 , L_16
L_17 ,
V_57 , V_44 -> V_17 , V_60 , V_61 ,
V_62 , V_63 , V_64 ,
V_44 -> V_78 , V_65 ) ;
V_66 += V_60 ;
V_67 += V_61 ;
V_68 += V_62 ;
V_69 += V_63 ;
V_70 += V_64 ;
V_71 += V_65 ;
}
F_77 ( V_55 , L_18 ) ;
F_73 ( V_55 , L_19 ,
L_20 , L_21 , V_66 ,
V_67 , V_68 ,
V_69 , V_70 , L_21 , V_71 ) ;
return 0 ;
}
static int F_78 ( struct V_79 * V_79 , struct V_80 * V_80 )
{
return F_79 ( V_80 , F_72 , V_79 -> V_81 ) ;
}
static void F_80 ( struct V_2 * V_3 , const char * V_14 )
{
struct V_82 * V_83 ;
if ( ! V_53 ) {
F_68 ( L_22 , V_14 ) ;
return;
}
V_83 = F_69 ( V_14 , V_53 ) ;
if ( ! V_83 ) {
F_68 ( L_23 , V_14 ) ;
return;
}
V_3 -> V_84 = V_83 ;
V_83 = F_81 ( L_24 , V_85 | V_86 ,
V_3 -> V_84 , V_3 , & V_87 ) ;
if ( ! V_83 ) {
F_68 ( L_25 ,
V_14 , L_24 ) ;
F_71 ( V_3 -> V_84 ) ;
V_3 -> V_84 = NULL ;
}
}
static void F_82 ( struct V_2 * V_3 )
{
F_71 ( V_3 -> V_84 ) ;
}
static void T_5 F_66 ( void )
{
}
static void T_6 F_70 ( void )
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
int V_33 , V_59 ;
enum V_40 V_88 ;
V_33 = F_47 ( V_4 ) ;
V_59 = V_44 -> V_59 ;
if ( V_33 == 0 )
V_88 = V_89 ;
else if ( V_33 == V_59 )
V_88 = V_90 ;
else if ( V_33 <= 3 * V_59 / V_91 )
V_88 = V_92 ;
else
V_88 = V_93 ;
return V_88 ;
}
static void F_84 ( struct V_49 * V_44 ,
struct V_4 * V_4 ,
enum V_40 V_41 )
{
struct V_4 * V_94 ;
F_63 ( V_44 , V_41 , 1 ) ;
V_94 = F_85 ( & V_44 -> V_95 [ V_41 ] ,
struct V_4 , V_96 ) ;
if ( V_94 ) {
if ( F_47 ( V_4 ) < F_47 ( V_94 ) ) {
F_86 ( & V_4 -> V_96 , & V_94 -> V_96 ) ;
return;
}
}
F_86 ( & V_4 -> V_96 , & V_44 -> V_95 [ V_41 ] ) ;
}
static void F_87 ( struct V_49 * V_44 ,
struct V_4 * V_4 ,
enum V_40 V_41 )
{
F_88 ( F_89 ( & V_44 -> V_95 [ V_41 ] ) ) ;
F_88 ( F_44 ( V_4 ) ) ;
F_90 ( & V_4 -> V_96 ) ;
F_64 ( V_44 , V_41 , 1 ) ;
}
static enum V_40 F_91 ( struct V_49 * V_44 ,
struct V_4 * V_4 )
{
int V_39 ;
enum V_40 V_97 , V_98 ;
F_56 ( V_4 , & V_39 , & V_97 ) ;
V_98 = F_83 ( V_44 , V_4 ) ;
if ( V_98 == V_97 )
goto V_99;
if ( ! F_44 ( V_4 ) ) {
F_87 ( V_44 , V_4 , V_97 ) ;
F_84 ( V_44 , V_4 , V_98 ) ;
}
F_58 ( V_4 , V_39 , V_98 ) ;
V_99:
return V_98 ;
}
static int F_92 ( int V_100 )
{
int V_57 , V_101 = 0 ;
int V_102 = 1 ;
for ( V_57 = 1 ; V_57 <= V_103 ; V_57 ++ ) {
int V_104 ;
int V_105 , V_106 ;
V_104 = V_57 * V_107 ;
V_105 = V_104 % V_100 ;
V_106 = ( V_104 - V_105 ) * 100 / V_104 ;
if ( V_106 > V_101 ) {
V_101 = V_106 ;
V_102 = V_57 ;
}
}
return V_102 ;
}
static struct V_4 * F_93 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = (struct V_4 * ) V_1 -> V_58 ;
F_57 ( V_4 -> V_42 != V_43 ) ;
return V_4 ;
}
static struct V_1 * F_94 ( struct V_1 * V_1 )
{
if ( F_95 ( F_5 ( V_1 ) ) )
return NULL ;
return V_1 -> V_108 ;
}
static void F_96 ( unsigned long V_13 , struct V_1 * * V_1 ,
unsigned int * V_109 )
{
V_13 >>= V_110 ;
* V_1 = F_97 ( V_13 >> V_111 ) ;
* V_109 = ( V_13 & V_112 ) ;
}
static unsigned long F_98 ( struct V_1 * V_1 , unsigned int V_109 )
{
unsigned long V_13 ;
V_13 = F_99 ( V_1 ) << V_111 ;
V_13 |= V_109 & V_112 ;
V_13 <<= V_110 ;
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
return V_1 -> V_72 ;
} else
return * ( unsigned long * ) V_13 ;
}
static inline int F_102 ( unsigned long V_11 )
{
return F_103 ( V_113 , ( unsigned long * ) V_11 ) ;
}
static inline int F_104 ( unsigned long V_11 )
{
return F_105 ( V_113 , ( unsigned long * ) V_11 ) ;
}
static void F_106 ( unsigned long V_11 )
{
F_107 ( V_113 , ( unsigned long * ) V_11 ) ;
}
static void F_108 ( unsigned long V_11 )
{
F_109 ( V_113 , ( unsigned long * ) V_11 ) ;
}
static void F_110 ( struct V_1 * V_1 )
{
F_111 ( V_1 ) ;
F_112 ( V_1 ) ;
F_113 ( V_1 , 0 ) ;
F_114 ( V_1 ) ;
F_3 ( V_1 ) ;
V_1 -> V_108 = NULL ;
}
void F_115 ( struct V_4 * V_4 )
{
struct V_1 * V_1 = F_50 ( V_4 ) ;
do {
F_116 ( V_1 ) ;
} while ( ( V_1 = F_94 ( V_1 ) ) != NULL );
}
int F_117 ( struct V_4 * V_4 )
{
struct V_1 * V_114 , * V_115 ;
for ( V_114 = F_50 ( V_4 ) ; V_114 != NULL ; V_114 =
F_94 ( V_114 ) ) {
if ( ! F_118 ( V_114 ) ) {
V_115 = V_114 ;
goto V_116;
}
}
return 1 ;
V_116:
for ( V_114 = F_50 ( V_4 ) ; V_114 != V_115 ; V_114 =
F_94 ( V_114 ) )
F_119 ( V_114 ) ;
return 0 ;
}
static void F_120 ( struct V_2 * V_3 , struct V_49 * V_44 ,
struct V_4 * V_4 )
{
struct V_1 * V_1 , * V_117 ;
enum V_40 V_88 ;
unsigned int V_39 ;
F_56 ( V_4 , & V_39 , & V_88 ) ;
F_121 ( & V_44 -> V_73 ) ;
F_88 ( F_47 ( V_4 ) ) ;
F_88 ( V_88 != V_89 ) ;
V_117 = V_1 = F_50 ( V_4 ) ;
do {
F_51 ( ! F_122 ( V_1 ) , V_1 ) ;
V_117 = F_94 ( V_1 ) ;
F_110 ( V_1 ) ;
F_119 ( V_1 ) ;
F_123 ( V_1 , V_118 ) ;
F_124 ( V_1 ) ;
V_1 = V_117 ;
} while ( V_1 != NULL );
F_26 ( V_3 , V_4 ) ;
F_64 ( V_44 , V_76 , V_44 -> V_59 ) ;
F_125 ( V_44 -> V_78 ,
& V_3 -> V_119 ) ;
}
static void F_126 ( struct V_2 * V_3 , struct V_49 * V_44 ,
struct V_4 * V_4 )
{
F_88 ( F_47 ( V_4 ) ) ;
F_88 ( F_89 ( & V_4 -> V_96 ) ) ;
if ( ! F_117 ( V_4 ) ) {
F_14 ( V_3 ) ;
return;
}
F_87 ( V_44 , V_4 , V_89 ) ;
F_120 ( V_3 , V_44 , V_4 ) ;
}
static void F_127 ( struct V_49 * V_44 , struct V_4 * V_4 )
{
unsigned int V_38 = 1 ;
unsigned long V_120 = 0 ;
struct V_1 * V_1 = F_50 ( V_4 ) ;
while ( V_1 ) {
struct V_1 * V_121 ;
struct V_122 * V_123 ;
void * V_124 ;
F_53 ( V_1 , V_120 ) ;
V_124 = F_128 ( V_1 ) ;
V_123 = (struct V_122 * ) V_124 + V_120 / sizeof( * V_123 ) ;
while ( ( V_120 += V_44 -> V_17 ) < V_107 ) {
V_123 -> V_117 = V_38 ++ << V_110 ;
V_123 += V_44 -> V_17 / sizeof( * V_123 ) ;
}
V_121 = F_94 ( V_1 ) ;
if ( V_121 ) {
V_123 -> V_117 = V_38 ++ << V_110 ;
} else {
V_123 -> V_117 = - 1 << V_110 ;
}
F_129 ( V_124 ) ;
V_1 = V_121 ;
V_120 %= V_107 ;
}
F_55 ( V_4 , 0 ) ;
}
static void F_130 ( struct V_49 * V_44 , struct V_4 * V_4 ,
struct V_1 * V_18 [] )
{
int V_57 ;
struct V_1 * V_1 ;
struct V_1 * V_125 = NULL ;
int V_126 = V_44 -> V_78 ;
for ( V_57 = 0 ; V_57 < V_126 ; V_57 ++ ) {
V_1 = V_18 [ V_57 ] ;
F_113 ( V_1 , ( unsigned long ) V_4 ) ;
V_1 -> V_108 = NULL ;
if ( V_57 == 0 ) {
V_4 -> V_35 = V_1 ;
F_131 ( V_1 ) ;
if ( F_95 ( V_44 -> V_59 == 1 &&
V_44 -> V_78 == 1 ) )
F_1 ( V_1 ) ;
} else {
V_125 -> V_108 = V_1 ;
}
V_125 = V_1 ;
}
}
static struct V_4 * F_132 ( struct V_2 * V_3 ,
struct V_49 * V_44 ,
T_1 V_8 )
{
int V_57 ;
struct V_1 * V_18 [ V_103 ] ;
struct V_4 * V_4 = F_25 ( V_3 , V_8 ) ;
if ( ! V_4 )
return NULL ;
memset ( V_4 , 0 , sizeof( struct V_4 ) ) ;
V_4 -> V_42 = V_43 ;
F_11 ( V_4 ) ;
for ( V_57 = 0 ; V_57 < V_44 -> V_78 ; V_57 ++ ) {
struct V_1 * V_1 ;
V_1 = F_133 ( V_8 ) ;
if ( ! V_1 ) {
while ( -- V_57 >= 0 ) {
F_123 ( V_18 [ V_57 ] , V_118 ) ;
F_134 ( V_18 [ V_57 ] ) ;
}
F_26 ( V_3 , V_4 ) ;
return NULL ;
}
F_135 ( V_1 , V_118 ) ;
V_18 [ V_57 ] = V_1 ;
}
F_130 ( V_44 , V_4 , V_18 ) ;
F_127 ( V_44 , V_4 ) ;
return V_4 ;
}
static struct V_4 * F_136 ( struct V_49 * V_44 )
{
int V_57 ;
struct V_4 * V_4 ;
for ( V_57 = V_93 ; V_57 >= V_89 ; V_57 -- ) {
V_4 = F_85 ( & V_44 -> V_95 [ V_57 ] ,
struct V_4 , V_96 ) ;
if ( V_4 )
break;
}
return V_4 ;
}
static inline int F_137 ( struct V_127 * V_128 )
{
if ( V_128 -> V_129 )
return 0 ;
V_128 -> V_129 = F_138 ( V_107 * 2 , NULL ) ;
if ( ! V_128 -> V_129 )
return - V_130 ;
return 0 ;
}
static inline void F_139 ( struct V_127 * V_128 )
{
if ( V_128 -> V_129 )
F_140 ( V_128 -> V_129 ) ;
V_128 -> V_129 = NULL ;
}
static inline void * F_141 ( struct V_127 * V_128 ,
struct V_1 * V_18 [ 2 ] , int V_120 , int V_17 )
{
F_57 ( F_142 ( V_128 -> V_129 , V_131 , V_18 ) ) ;
V_128 -> V_132 = V_128 -> V_129 -> V_133 ;
return V_128 -> V_132 + V_120 ;
}
static inline void F_143 ( struct V_127 * V_128 ,
struct V_1 * V_18 [ 2 ] , int V_120 , int V_17 )
{
unsigned long V_133 = ( unsigned long ) V_128 -> V_132 ;
F_144 ( V_133 , V_107 * 2 ) ;
}
static inline int F_137 ( struct V_127 * V_128 )
{
if ( V_128 -> V_134 )
return 0 ;
V_128 -> V_134 = F_145 ( V_135 , V_136 ) ;
if ( ! V_128 -> V_134 )
return - V_130 ;
return 0 ;
}
static inline void F_139 ( struct V_127 * V_128 )
{
F_146 ( V_128 -> V_134 ) ;
V_128 -> V_134 = NULL ;
}
static void * F_141 ( struct V_127 * V_128 ,
struct V_1 * V_18 [ 2 ] , int V_120 , int V_17 )
{
int V_137 [ 2 ] ;
void * V_133 ;
char * V_138 = V_128 -> V_134 ;
F_147 () ;
if ( V_128 -> V_139 == V_28 )
goto V_99;
V_137 [ 0 ] = V_107 - V_120 ;
V_137 [ 1 ] = V_17 - V_137 [ 0 ] ;
V_133 = F_128 ( V_18 [ 0 ] ) ;
memcpy ( V_138 , V_133 + V_120 , V_137 [ 0 ] ) ;
F_129 ( V_133 ) ;
V_133 = F_128 ( V_18 [ 1 ] ) ;
memcpy ( V_138 + V_137 [ 0 ] , V_133 , V_137 [ 1 ] ) ;
F_129 ( V_133 ) ;
V_99:
return V_128 -> V_134 ;
}
static void F_143 ( struct V_127 * V_128 ,
struct V_1 * V_18 [ 2 ] , int V_120 , int V_17 )
{
int V_137 [ 2 ] ;
void * V_133 ;
char * V_138 ;
if ( V_128 -> V_139 == V_26 )
goto V_99;
V_138 = V_128 -> V_134 ;
V_138 = V_138 + V_6 ;
V_17 -= V_6 ;
V_120 += V_6 ;
V_137 [ 0 ] = V_107 - V_120 ;
V_137 [ 1 ] = V_17 - V_137 [ 0 ] ;
V_133 = F_128 ( V_18 [ 0 ] ) ;
memcpy ( V_133 + V_120 , V_138 , V_137 [ 0 ] ) ;
F_129 ( V_133 ) ;
V_133 = F_128 ( V_18 [ 1 ] ) ;
memcpy ( V_133 , V_138 + V_137 [ 0 ] , V_137 [ 1 ] ) ;
F_129 ( V_133 ) ;
V_99:
F_148 () ;
}
static int F_149 ( unsigned int V_140 )
{
struct V_127 * V_128 ;
V_128 = & F_150 ( V_141 , V_140 ) ;
return F_137 ( V_128 ) ;
}
static int F_151 ( unsigned int V_140 )
{
struct V_127 * V_128 ;
V_128 = & F_150 ( V_141 , V_140 ) ;
F_139 ( V_128 ) ;
return 0 ;
}
static bool F_152 ( struct V_49 * V_142 , int V_78 ,
int V_59 )
{
if ( V_142 -> V_78 == V_78 &&
V_142 -> V_59 == V_59 )
return true ;
return false ;
}
static bool F_153 ( struct V_49 * V_44 , struct V_4 * V_4 )
{
return F_47 ( V_4 ) == V_44 -> V_59 ;
}
unsigned long F_43 ( struct V_2 * V_3 )
{
return F_154 ( & V_3 -> V_119 ) ;
}
void * F_39 ( struct V_2 * V_3 , unsigned long V_11 ,
enum V_23 V_22 )
{
struct V_4 * V_4 ;
struct V_1 * V_1 ;
unsigned long V_13 , V_120 ;
unsigned int V_109 ;
unsigned int V_39 ;
enum V_40 V_88 ;
struct V_49 * V_44 ;
struct V_127 * V_128 ;
struct V_1 * V_18 [ 2 ] ;
void * V_143 ;
F_155 ( F_156 () ) ;
F_106 ( V_11 ) ;
V_13 = F_100 ( V_11 ) ;
F_96 ( V_13 , & V_1 , & V_109 ) ;
V_4 = F_93 ( V_1 ) ;
F_12 ( V_4 ) ;
F_56 ( V_4 , & V_39 , & V_88 ) ;
V_44 = V_3 -> V_49 [ V_39 ] ;
V_120 = ( V_44 -> V_17 * V_109 ) & ~ V_144 ;
V_128 = & F_157 ( V_141 ) ;
V_128 -> V_139 = V_22 ;
if ( V_120 + V_44 -> V_17 <= V_107 ) {
V_128 -> V_132 = F_128 ( V_1 ) ;
V_143 = V_128 -> V_132 + V_120 ;
goto V_99;
}
V_18 [ 0 ] = V_1 ;
V_18 [ 1 ] = F_94 ( V_1 ) ;
F_57 ( ! V_18 [ 1 ] ) ;
V_143 = F_141 ( V_128 , V_18 , V_120 , V_44 -> V_17 ) ;
V_99:
if ( F_60 ( ! F_5 ( V_1 ) ) )
V_143 += V_6 ;
return V_143 ;
}
void F_41 ( struct V_2 * V_3 , unsigned long V_11 )
{
struct V_4 * V_4 ;
struct V_1 * V_1 ;
unsigned long V_13 , V_120 ;
unsigned int V_109 ;
unsigned int V_39 ;
enum V_40 V_88 ;
struct V_49 * V_44 ;
struct V_127 * V_128 ;
V_13 = F_100 ( V_11 ) ;
F_96 ( V_13 , & V_1 , & V_109 ) ;
V_4 = F_93 ( V_1 ) ;
F_56 ( V_4 , & V_39 , & V_88 ) ;
V_44 = V_3 -> V_49 [ V_39 ] ;
V_120 = ( V_44 -> V_17 * V_109 ) & ~ V_144 ;
V_128 = F_158 ( & V_141 ) ;
if ( V_120 + V_44 -> V_17 <= V_107 )
F_129 ( V_128 -> V_132 ) ;
else {
struct V_1 * V_18 [ 2 ] ;
V_18 [ 0 ] = V_1 ;
V_18 [ 1 ] = F_94 ( V_1 ) ;
F_57 ( ! V_18 [ 1 ] ) ;
F_143 ( V_128 , V_18 , V_120 , V_44 -> V_17 ) ;
}
F_159 ( V_141 ) ;
F_13 ( V_4 ) ;
F_108 ( V_11 ) ;
}
static unsigned long F_160 ( struct V_49 * V_44 ,
struct V_4 * V_4 , unsigned long V_11 )
{
int V_57 , V_145 , V_37 ;
unsigned long V_13 ;
struct V_122 * V_123 ;
struct V_1 * V_146 ;
unsigned long V_147 ;
void * V_124 ;
V_11 |= V_148 ;
V_13 = F_54 ( V_4 ) ;
V_37 = V_13 * V_44 -> V_17 ;
V_145 = V_37 >> V_31 ;
V_147 = V_37 & ~ V_144 ;
V_146 = F_50 ( V_4 ) ;
for ( V_57 = 0 ; V_57 < V_145 ; V_57 ++ )
V_146 = F_94 ( V_146 ) ;
V_124 = F_128 ( V_146 ) ;
V_123 = (struct V_122 * ) V_124 + V_147 / sizeof( * V_123 ) ;
F_55 ( V_4 , V_123 -> V_117 >> V_110 ) ;
if ( F_60 ( ! F_5 ( V_146 ) ) )
V_123 -> V_11 = V_11 ;
else
V_4 -> V_35 -> V_72 = V_11 ;
F_129 ( V_124 ) ;
F_49 ( V_4 , 1 ) ;
F_63 ( V_44 , V_77 , 1 ) ;
V_13 = F_98 ( V_146 , V_13 ) ;
return V_13 ;
}
unsigned long F_34 ( struct V_2 * V_3 , T_2 V_17 , T_1 V_8 )
{
unsigned long V_11 , V_13 ;
struct V_49 * V_44 ;
enum V_40 V_98 ;
struct V_4 * V_4 ;
if ( F_95 ( ! V_17 || V_17 > V_135 ) )
return 0 ;
V_11 = F_21 ( V_3 , V_8 ) ;
if ( ! V_11 )
return 0 ;
V_17 += V_6 ;
V_44 = V_3 -> V_49 [ F_59 ( V_17 ) ] ;
F_74 ( & V_44 -> V_73 ) ;
V_4 = F_136 ( V_44 ) ;
if ( F_60 ( V_4 ) ) {
V_13 = F_160 ( V_44 , V_4 , V_11 ) ;
F_91 ( V_44 , V_4 ) ;
F_27 ( V_11 , V_13 ) ;
F_76 ( & V_44 -> V_73 ) ;
return V_11 ;
}
F_76 ( & V_44 -> V_73 ) ;
V_4 = F_132 ( V_3 , V_44 , V_8 ) ;
if ( ! V_4 ) {
F_23 ( V_3 , V_11 ) ;
return 0 ;
}
F_74 ( & V_44 -> V_73 ) ;
V_13 = F_160 ( V_44 , V_4 , V_11 ) ;
V_98 = F_83 ( V_44 , V_4 ) ;
F_84 ( V_44 , V_4 , V_98 ) ;
F_58 ( V_4 , V_44 -> V_72 , V_98 ) ;
F_27 ( V_11 , V_13 ) ;
F_161 ( V_44 -> V_78 ,
& V_3 -> V_119 ) ;
F_63 ( V_44 , V_76 , V_44 -> V_59 ) ;
F_16 ( V_3 , V_4 ) ;
F_76 ( & V_44 -> V_73 ) ;
return V_11 ;
}
static void F_162 ( struct V_49 * V_44 , unsigned long V_13 )
{
struct V_122 * V_123 ;
struct V_4 * V_4 ;
struct V_1 * V_149 ;
unsigned long V_150 ;
unsigned int V_151 ;
void * V_124 ;
V_13 &= ~ V_148 ;
F_96 ( V_13 , & V_149 , & V_151 ) ;
V_150 = ( V_44 -> V_17 * V_151 ) & ~ V_144 ;
V_4 = F_93 ( V_149 ) ;
V_124 = F_128 ( V_149 ) ;
V_123 = (struct V_122 * ) ( V_124 + V_150 ) ;
V_123 -> V_117 = F_54 ( V_4 ) << V_110 ;
F_129 ( V_124 ) ;
F_55 ( V_4 , V_151 ) ;
F_49 ( V_4 , - 1 ) ;
F_64 ( V_44 , V_77 , 1 ) ;
}
void F_36 ( struct V_2 * V_3 , unsigned long V_11 )
{
struct V_4 * V_4 ;
struct V_1 * V_149 ;
unsigned long V_13 ;
unsigned int V_151 ;
int V_39 ;
struct V_49 * V_44 ;
enum V_40 V_41 ;
bool V_32 ;
if ( F_95 ( ! V_11 ) )
return;
F_106 ( V_11 ) ;
V_13 = F_100 ( V_11 ) ;
F_96 ( V_13 , & V_149 , & V_151 ) ;
V_4 = F_93 ( V_149 ) ;
F_12 ( V_4 ) ;
F_56 ( V_4 , & V_39 , & V_41 ) ;
V_44 = V_3 -> V_49 [ V_39 ] ;
F_74 ( & V_44 -> V_73 ) ;
F_162 ( V_44 , V_13 ) ;
V_41 = F_91 ( V_44 , V_4 ) ;
if ( V_41 != V_89 ) {
F_13 ( V_4 ) ;
goto V_99;
}
V_32 = F_44 ( V_4 ) ;
F_13 ( V_4 ) ;
if ( F_60 ( ! V_32 ) )
F_126 ( V_3 , V_44 , V_4 ) ;
V_99:
F_76 ( & V_44 -> V_73 ) ;
F_108 ( V_11 ) ;
F_23 ( V_3 , V_11 ) ;
}
static void F_163 ( struct V_49 * V_44 , unsigned long V_152 ,
unsigned long V_153 )
{
struct V_1 * V_154 , * V_155 ;
unsigned int V_156 , V_157 ;
unsigned long V_158 , V_159 ;
void * V_160 , * V_161 ;
int V_162 , V_163 , V_17 ;
int V_164 = 0 ;
V_162 = V_163 = V_44 -> V_17 ;
F_96 ( V_153 , & V_154 , & V_156 ) ;
F_96 ( V_152 , & V_155 , & V_157 ) ;
V_158 = ( V_44 -> V_17 * V_156 ) & ~ V_144 ;
V_159 = ( V_44 -> V_17 * V_157 ) & ~ V_144 ;
if ( V_158 + V_44 -> V_17 > V_107 )
V_162 = V_107 - V_158 ;
if ( V_159 + V_44 -> V_17 > V_107 )
V_163 = V_107 - V_159 ;
V_160 = F_128 ( V_154 ) ;
V_161 = F_128 ( V_155 ) ;
while ( 1 ) {
V_17 = F_164 ( V_162 , V_163 ) ;
memcpy ( V_161 + V_159 , V_160 + V_158 , V_17 ) ;
V_164 += V_17 ;
if ( V_164 == V_44 -> V_17 )
break;
V_158 += V_17 ;
V_162 -= V_17 ;
V_159 += V_17 ;
V_163 -= V_17 ;
if ( V_158 >= V_107 ) {
F_129 ( V_161 ) ;
F_129 ( V_160 ) ;
V_154 = F_94 ( V_154 ) ;
V_160 = F_128 ( V_154 ) ;
V_161 = F_128 ( V_155 ) ;
V_162 = V_44 -> V_17 - V_164 ;
V_158 = 0 ;
}
if ( V_159 >= V_107 ) {
F_129 ( V_161 ) ;
V_155 = F_94 ( V_155 ) ;
V_161 = F_128 ( V_155 ) ;
V_163 = V_44 -> V_17 - V_164 ;
V_159 = 0 ;
}
}
F_129 ( V_161 ) ;
F_129 ( V_160 ) ;
}
static unsigned long F_165 ( struct V_49 * V_44 ,
struct V_1 * V_1 , int * V_109 )
{
unsigned long V_94 ;
int V_37 = 0 ;
int V_72 = * V_109 ;
unsigned long V_11 = 0 ;
void * V_133 = F_128 ( V_1 ) ;
V_37 = F_52 ( V_1 ) ;
V_37 += V_44 -> V_17 * V_72 ;
while ( V_37 < V_107 ) {
V_94 = F_101 ( V_1 , V_133 + V_37 ) ;
if ( V_94 & V_148 ) {
V_11 = V_94 & ~ V_148 ;
if ( F_104 ( V_11 ) )
break;
V_11 = 0 ;
}
V_37 += V_44 -> V_17 ;
V_72 ++ ;
}
F_129 ( V_133 ) ;
* V_109 = V_72 ;
return V_11 ;
}
static int F_166 ( struct V_2 * V_3 , struct V_49 * V_44 ,
struct V_165 * V_166 )
{
unsigned long V_167 , V_168 ;
unsigned long V_11 ;
struct V_1 * V_154 = V_166 -> V_154 ;
struct V_1 * V_155 = V_166 -> V_155 ;
int V_109 = V_166 -> V_109 ;
int V_143 = 0 ;
while ( 1 ) {
V_11 = F_165 ( V_44 , V_154 , & V_109 ) ;
if ( ! V_11 ) {
V_154 = F_94 ( V_154 ) ;
if ( ! V_154 )
break;
V_109 = 0 ;
continue;
}
if ( F_153 ( V_44 , F_93 ( V_155 ) ) ) {
F_108 ( V_11 ) ;
V_143 = - V_130 ;
break;
}
V_167 = F_100 ( V_11 ) ;
V_168 = F_160 ( V_44 , F_93 ( V_155 ) , V_11 ) ;
F_163 ( V_44 , V_168 , V_167 ) ;
V_109 ++ ;
V_168 |= F_167 ( V_113 ) ;
F_27 ( V_11 , V_168 ) ;
F_108 ( V_11 ) ;
F_162 ( V_44 , V_167 ) ;
}
V_166 -> V_154 = V_154 ;
V_166 -> V_109 = V_109 ;
return V_143 ;
}
static struct V_4 * F_168 ( struct V_49 * V_44 , bool V_169 )
{
int V_57 ;
struct V_4 * V_4 ;
enum V_40 V_88 [ 2 ] = { V_92 , V_93 } ;
if ( ! V_169 ) {
V_88 [ 0 ] = V_93 ;
V_88 [ 1 ] = V_92 ;
}
for ( V_57 = 0 ; V_57 < 2 ; V_57 ++ ) {
V_4 = F_85 ( & V_44 -> V_95 [ V_88 [ V_57 ] ] ,
struct V_4 , V_96 ) ;
if ( V_4 ) {
F_88 ( F_44 ( V_4 ) ) ;
F_87 ( V_44 , V_4 , V_88 [ V_57 ] ) ;
return V_4 ;
}
}
return V_4 ;
}
static enum V_40 F_169 ( struct V_49 * V_44 ,
struct V_4 * V_4 )
{
enum V_40 V_41 ;
F_88 ( F_44 ( V_4 ) ) ;
V_41 = F_83 ( V_44 , V_4 ) ;
F_84 ( V_44 , V_4 , V_41 ) ;
F_58 ( V_4 , V_44 -> V_72 , V_41 ) ;
return V_41 ;
}
static struct V_82 * F_170 ( struct V_170 * V_171 ,
int V_12 , const char * V_172 , void * V_173 )
{
static const struct V_174 V_175 = {
. V_176 = V_177 ,
} ;
return F_171 ( V_171 , L_26 , NULL , & V_175 , V_178 ) ;
}
static int F_7 ( void )
{
int V_143 = 0 ;
V_179 = F_172 ( & V_180 ) ;
if ( F_173 ( V_179 ) )
V_143 = F_174 ( V_179 ) ;
return V_143 ;
}
static void F_8 ( void )
{
F_175 ( V_179 ) ;
}
static void F_11 ( struct V_4 * V_4 )
{
F_176 ( & V_4 -> V_73 ) ;
}
static void F_12 ( struct V_4 * V_4 )
{
F_177 ( & V_4 -> V_73 ) ;
}
static void F_13 ( struct V_4 * V_4 )
{
F_178 ( & V_4 -> V_73 ) ;
}
static void F_179 ( struct V_4 * V_4 )
{
F_180 ( & V_4 -> V_73 ) ;
}
static void F_181 ( struct V_4 * V_4 )
{
F_182 ( & V_4 -> V_73 ) ;
}
static void F_183 ( struct V_4 * V_4 )
{
V_4 -> V_32 ++ ;
}
static void F_184 ( struct V_4 * V_4 )
{
V_4 -> V_32 -- ;
}
static void F_185 ( struct V_49 * V_44 , struct V_4 * V_4 ,
struct V_1 * V_181 , struct V_1 * V_182 )
{
struct V_1 * V_1 ;
struct V_1 * V_18 [ V_103 ] = { NULL , } ;
int V_45 = 0 ;
V_1 = F_50 ( V_4 ) ;
do {
if ( V_1 == V_182 )
V_18 [ V_45 ] = V_181 ;
else
V_18 [ V_45 ] = V_1 ;
V_45 ++ ;
} while ( ( V_1 = F_94 ( V_1 ) ) != NULL );
F_130 ( V_44 , V_4 , V_18 ) ;
F_53 ( V_181 , F_52 ( V_182 ) ) ;
if ( F_95 ( F_5 ( V_182 ) ) )
V_181 -> V_72 = V_182 -> V_72 ;
F_186 ( V_181 , F_187 ( V_182 ) ) ;
}
bool F_188 ( struct V_1 * V_1 , T_7 V_183 )
{
struct V_2 * V_3 ;
struct V_49 * V_44 ;
int V_39 ;
enum V_40 V_41 ;
struct V_4 * V_4 ;
struct V_184 * V_185 ;
F_51 ( ! F_189 ( V_1 ) , V_1 ) ;
F_51 ( F_190 ( V_1 ) , V_1 ) ;
V_4 = F_93 ( V_1 ) ;
F_56 ( V_4 , & V_39 , & V_41 ) ;
V_185 = F_187 ( V_1 ) ;
V_3 = V_185 -> V_186 ;
V_44 = V_3 -> V_49 [ V_39 ] ;
F_74 ( & V_44 -> V_73 ) ;
if ( F_47 ( V_4 ) == 0 ) {
F_76 ( & V_44 -> V_73 ) ;
return false ;
}
if ( F_89 ( & V_4 -> V_96 ) && ! F_44 ( V_4 ) ) {
F_76 ( & V_44 -> V_73 ) ;
return false ;
}
if ( ! F_89 ( & V_4 -> V_96 ) && ! F_44 ( V_4 ) ) {
F_56 ( V_4 , & V_39 , & V_41 ) ;
F_87 ( V_44 , V_4 , V_41 ) ;
}
F_183 ( V_4 ) ;
F_76 ( & V_44 -> V_73 ) ;
return true ;
}
int F_191 ( struct V_184 * V_185 , struct V_1 * V_181 ,
struct V_1 * V_1 , enum V_187 V_183 )
{
struct V_2 * V_3 ;
struct V_49 * V_44 ;
int V_39 ;
enum V_40 V_41 ;
struct V_4 * V_4 ;
struct V_1 * V_188 ;
void * V_160 , * V_161 , * V_133 ;
int V_37 , V_189 ;
unsigned long V_11 , V_94 ;
unsigned long V_190 , V_191 ;
unsigned int V_109 ;
int V_143 = - V_192 ;
if ( V_183 == V_193 )
return - V_20 ;
F_51 ( ! F_189 ( V_1 ) , V_1 ) ;
F_51 ( ! F_190 ( V_1 ) , V_1 ) ;
V_4 = F_93 ( V_1 ) ;
F_179 ( V_4 ) ;
F_56 ( V_4 , & V_39 , & V_41 ) ;
V_3 = V_185 -> V_186 ;
V_44 = V_3 -> V_49 [ V_39 ] ;
V_37 = F_52 ( V_1 ) ;
F_74 ( & V_44 -> V_73 ) ;
if ( ! F_47 ( V_4 ) ) {
V_37 = V_107 ;
}
V_189 = V_37 ;
V_160 = F_128 ( V_1 ) ;
while ( V_189 < V_107 ) {
V_94 = F_101 ( V_1 , V_160 + V_189 ) ;
if ( V_94 & V_148 ) {
V_11 = V_94 & ~ V_148 ;
if ( ! F_104 ( V_11 ) )
goto V_194;
}
V_189 += V_44 -> V_17 ;
}
V_161 = F_128 ( V_181 ) ;
memcpy ( V_161 , V_160 , V_107 ) ;
F_129 ( V_161 ) ;
for ( V_133 = V_160 + V_37 ; V_133 < V_160 + V_189 ;
V_133 += V_44 -> V_17 ) {
V_94 = F_101 ( V_1 , V_133 ) ;
if ( V_94 & V_148 ) {
V_11 = V_94 & ~ V_148 ;
if ( ! F_102 ( V_11 ) )
F_192 () ;
V_190 = F_100 ( V_11 ) ;
F_96 ( V_190 , & V_188 , & V_109 ) ;
V_191 = ( unsigned long ) F_98 ( V_181 ,
V_109 ) ;
V_191 |= F_167 ( V_113 ) ;
F_27 ( V_11 , V_191 ) ;
}
}
F_185 ( V_44 , V_4 , V_181 , V_1 ) ;
F_193 ( V_181 ) ;
F_184 ( V_4 ) ;
if ( ! F_44 ( V_4 ) )
F_169 ( V_44 , V_4 ) ;
F_110 ( V_1 ) ;
F_124 ( V_1 ) ;
V_1 = V_181 ;
V_143 = V_195 ;
V_194:
for ( V_133 = V_160 + V_37 ; V_133 < V_160 + V_189 ;
V_133 += V_44 -> V_17 ) {
V_94 = F_101 ( V_1 , V_133 ) ;
if ( V_94 & V_148 ) {
V_11 = V_94 & ~ V_148 ;
if ( ! F_102 ( V_11 ) )
F_192 () ;
F_108 ( V_11 ) ;
}
}
F_129 ( V_160 ) ;
F_76 ( & V_44 -> V_73 ) ;
F_181 ( V_4 ) ;
return V_143 ;
}
void F_194 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
struct V_49 * V_44 ;
int V_39 ;
enum V_40 V_88 ;
struct V_184 * V_185 ;
struct V_4 * V_4 ;
F_51 ( ! F_189 ( V_1 ) , V_1 ) ;
F_51 ( ! F_190 ( V_1 ) , V_1 ) ;
V_4 = F_93 ( V_1 ) ;
F_56 ( V_4 , & V_39 , & V_88 ) ;
V_185 = F_187 ( V_1 ) ;
V_3 = V_185 -> V_186 ;
V_44 = V_3 -> V_49 [ V_39 ] ;
F_74 ( & V_44 -> V_73 ) ;
F_184 ( V_4 ) ;
if ( ! F_44 ( V_4 ) ) {
V_88 = F_169 ( V_44 , V_4 ) ;
if ( V_88 == V_89 )
F_195 ( & V_3 -> V_196 ) ;
}
F_76 ( & V_44 -> V_73 ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
V_3 -> V_79 = F_196 ( V_179 -> V_197 ) ;
if ( F_173 ( V_3 -> V_79 ) ) {
V_3 -> V_79 = NULL ;
return 1 ;
}
V_3 -> V_79 -> V_198 -> V_186 = V_3 ;
V_3 -> V_79 -> V_198 -> V_199 = & V_200 ;
return 0 ;
}
static void F_10 ( struct V_2 * V_3 )
{
F_197 ( & V_3 -> V_196 ) ;
F_198 ( V_3 -> V_79 ) ;
}
static void F_199 ( struct V_201 * V_202 )
{
int V_57 ;
struct V_49 * V_44 ;
unsigned int V_39 ;
enum V_40 V_41 ;
struct V_4 * V_4 , * V_203 ;
F_200 ( V_204 ) ;
struct V_2 * V_3 = F_201 ( V_202 , struct V_2 ,
V_196 ) ;
for ( V_57 = 0 ; V_57 < V_48 ; V_57 ++ ) {
V_44 = V_3 -> V_49 [ V_57 ] ;
if ( V_44 -> V_72 != V_57 )
continue;
F_74 ( & V_44 -> V_73 ) ;
F_202 ( & V_44 -> V_95 [ V_89 ] , & V_204 ) ;
F_76 ( & V_44 -> V_73 ) ;
}
F_203 (zspage, tmp, &free_pages, list) {
F_204 ( & V_4 -> V_96 ) ;
F_115 ( V_4 ) ;
F_56 ( V_4 , & V_39 , & V_41 ) ;
F_88 ( V_41 != V_89 ) ;
V_44 = V_3 -> V_49 [ V_39 ] ;
F_74 ( & V_44 -> V_73 ) ;
F_120 ( V_3 , V_3 -> V_49 [ V_39 ] , V_4 ) ;
F_76 ( & V_44 -> V_73 ) ;
}
}
static void F_14 ( struct V_2 * V_3 )
{
F_195 ( & V_3 -> V_196 ) ;
}
static void F_15 ( struct V_2 * V_3 )
{
F_205 ( & V_3 -> V_196 , F_199 ) ;
}
static void F_16 ( struct V_2 * V_3 , struct V_4 * V_4 )
{
struct V_1 * V_1 = F_50 ( V_4 ) ;
do {
F_206 ( ! F_118 ( V_1 ) ) ;
F_186 ( V_1 , V_3 -> V_79 -> V_198 ) ;
F_119 ( V_1 ) ;
} while ( ( V_1 = F_94 ( V_1 ) ) != NULL );
}
static unsigned long F_75 ( struct V_49 * V_44 )
{
unsigned long V_205 ;
unsigned long V_62 = F_65 ( V_44 , V_76 ) ;
unsigned long V_63 = F_65 ( V_44 , V_77 ) ;
if ( V_62 <= V_63 )
return 0 ;
V_205 = V_62 - V_63 ;
V_205 /= V_44 -> V_59 ;
return V_205 * V_44 -> V_78 ;
}
static void F_207 ( struct V_2 * V_3 , struct V_49 * V_44 )
{
struct V_165 V_166 ;
struct V_4 * V_206 ;
struct V_4 * V_207 = NULL ;
F_74 ( & V_44 -> V_73 ) ;
while ( ( V_206 = F_168 ( V_44 , true ) ) ) {
if ( ! F_75 ( V_44 ) )
break;
V_166 . V_109 = 0 ;
V_166 . V_154 = F_50 ( V_206 ) ;
while ( ( V_207 = F_168 ( V_44 , false ) ) ) {
V_166 . V_155 = F_50 ( V_207 ) ;
if ( ! F_166 ( V_3 , V_44 , & V_166 ) )
break;
F_169 ( V_44 , V_207 ) ;
}
if ( V_207 == NULL )
break;
F_169 ( V_44 , V_207 ) ;
if ( F_169 ( V_44 , V_206 ) == V_89 ) {
F_126 ( V_3 , V_44 , V_206 ) ;
V_3 -> V_51 . V_208 += V_44 -> V_78 ;
}
F_76 ( & V_44 -> V_73 ) ;
F_208 () ;
F_74 ( & V_44 -> V_73 ) ;
}
if ( V_206 )
F_169 ( V_44 , V_206 ) ;
F_76 ( & V_44 -> V_73 ) ;
}
unsigned long F_209 ( struct V_2 * V_3 )
{
int V_57 ;
struct V_49 * V_44 ;
for ( V_57 = V_48 - 1 ; V_57 >= 0 ; V_57 -- ) {
V_44 = V_3 -> V_49 [ V_57 ] ;
if ( ! V_44 )
continue;
if ( V_44 -> V_72 != V_57 )
continue;
F_207 ( V_3 , V_44 ) ;
}
return V_3 -> V_51 . V_208 ;
}
void F_210 ( struct V_2 * V_3 , struct F_210 * V_51 )
{
memcpy ( V_51 , & V_3 -> V_51 , sizeof( struct F_210 ) ) ;
}
static unsigned long F_211 ( struct V_209 * V_209 ,
struct V_210 * V_211 )
{
unsigned long V_212 ;
struct V_2 * V_3 = F_201 ( V_209 , struct V_2 ,
V_209 ) ;
V_212 = V_3 -> V_51 . V_208 ;
V_212 = F_209 ( V_3 ) - V_212 ;
return V_212 ? V_212 : V_213 ;
}
static unsigned long F_212 ( struct V_209 * V_209 ,
struct V_210 * V_211 )
{
int V_57 ;
struct V_49 * V_44 ;
unsigned long V_214 = 0 ;
struct V_2 * V_3 = F_201 ( V_209 , struct V_2 ,
V_209 ) ;
for ( V_57 = V_48 - 1 ; V_57 >= 0 ; V_57 -- ) {
V_44 = V_3 -> V_49 [ V_57 ] ;
if ( ! V_44 )
continue;
if ( V_44 -> V_72 != V_57 )
continue;
V_214 += F_75 ( V_44 ) ;
}
return V_214 ;
}
static void F_213 ( struct V_2 * V_3 )
{
if ( V_3 -> V_215 ) {
F_214 ( & V_3 -> V_209 ) ;
V_3 -> V_215 = false ;
}
}
static int F_215 ( struct V_2 * V_3 )
{
V_3 -> V_209 . V_216 = F_211 ;
V_3 -> V_209 . V_217 = F_212 ;
V_3 -> V_209 . V_218 = 0 ;
V_3 -> V_209 . V_219 = V_220 ;
return F_216 ( & V_3 -> V_209 ) ;
}
struct V_2 * F_30 ( const char * V_14 )
{
int V_57 ;
struct V_2 * V_3 ;
struct V_49 * V_221 = NULL ;
V_3 = F_217 ( sizeof( * V_3 ) , V_136 ) ;
if ( ! V_3 )
return NULL ;
F_15 ( V_3 ) ;
V_3 -> V_14 = F_218 ( V_14 , V_136 ) ;
if ( ! V_3 -> V_14 )
goto V_222;
if ( F_17 ( V_3 ) )
goto V_222;
for ( V_57 = V_48 - 1 ; V_57 >= 0 ; V_57 -- ) {
int V_17 ;
int V_78 ;
int V_59 ;
struct V_49 * V_44 ;
int V_41 = 0 ;
V_17 = V_46 + V_57 * V_47 ;
if ( V_17 > V_135 )
V_17 = V_135 ;
V_78 = F_92 ( V_17 ) ;
V_59 = V_78 * V_107 / V_17 ;
if ( V_221 ) {
if ( F_152 ( V_221 , V_78 , V_59 ) ) {
V_3 -> V_49 [ V_57 ] = V_221 ;
continue;
}
}
V_44 = F_217 ( sizeof( struct V_49 ) , V_136 ) ;
if ( ! V_44 )
goto V_222;
V_44 -> V_17 = V_17 ;
V_44 -> V_72 = V_57 ;
V_44 -> V_78 = V_78 ;
V_44 -> V_59 = V_59 ;
F_219 ( & V_44 -> V_73 ) ;
V_3 -> V_49 [ V_57 ] = V_44 ;
for ( V_41 = V_89 ; V_41 < V_223 ;
V_41 ++ )
F_220 ( & V_44 -> V_95 [ V_41 ] ) ;
V_221 = V_44 ;
}
F_80 ( V_3 , V_14 ) ;
if ( F_9 ( V_3 ) )
goto V_222;
if ( F_215 ( V_3 ) == 0 )
V_3 -> V_215 = true ;
return V_3 ;
V_222:
F_32 ( V_3 ) ;
return NULL ;
}
void F_32 ( struct V_2 * V_3 )
{
int V_57 ;
F_213 ( V_3 ) ;
F_10 ( V_3 ) ;
F_82 ( V_3 ) ;
for ( V_57 = 0 ; V_57 < V_48 ; V_57 ++ ) {
int V_88 ;
struct V_49 * V_44 = V_3 -> V_49 [ V_57 ] ;
if ( ! V_44 )
continue;
if ( V_44 -> V_72 != V_57 )
continue;
for ( V_88 = V_89 ; V_88 < V_223 ; V_88 ++ ) {
if ( ! F_89 ( & V_44 -> V_95 [ V_88 ] ) ) {
F_221 ( L_27 ,
V_44 -> V_17 , V_88 ) ;
}
}
F_146 ( V_44 ) ;
}
F_20 ( V_3 ) ;
F_146 ( V_3 -> V_14 ) ;
F_146 ( V_3 ) ;
}
static int T_5 F_222 ( void )
{
int V_143 ;
V_143 = F_7 () ;
if ( V_143 )
goto V_99;
V_143 = F_223 ( V_224 , L_28 ,
F_149 , F_151 ) ;
if ( V_143 )
goto V_225;
#ifdef F_224
F_225 ( & V_226 ) ;
#endif
F_66 () ;
return 0 ;
V_225:
F_8 () ;
V_99:
return V_143 ;
}
static void T_6 F_226 ( void )
{
#ifdef F_224
F_227 ( & V_226 ) ;
#endif
F_8 () ;
F_228 ( V_224 ) ;
F_70 () ;
}
