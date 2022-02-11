static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_2 ( & V_2 -> V_4 ) ;
F_2 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = NULL ;
V_2 -> V_7 = NULL ;
V_2 -> V_8 = 0 ;
F_3 ( & V_2 -> V_9 ) ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = 0 ;
}
static int F_4 ( struct V_13 * V_14 )
{
return V_14 -> F_4 ;
}
static unsigned long long * F_5 ( struct V_13 * V_14 , void * V_15 )
{
F_6 ( ! ( V_14 -> V_16 & V_17 ) ) ;
return ( unsigned long long * ) ( V_15 + F_4 ( V_14 ) -
sizeof( unsigned long long ) ) ;
}
static unsigned long long * F_7 ( struct V_13 * V_14 , void * V_15 )
{
F_6 ( ! ( V_14 -> V_16 & V_17 ) ) ;
if ( V_14 -> V_16 & V_18 )
return ( unsigned long long * ) ( V_15 + V_14 -> V_19 -
sizeof( unsigned long long ) -
V_20 ) ;
return ( unsigned long long * ) ( V_15 + V_14 -> V_19 -
sizeof( unsigned long long ) ) ;
}
static void * * F_8 ( struct V_13 * V_14 , void * V_15 )
{
F_6 ( ! ( V_14 -> V_16 & V_18 ) ) ;
return ( void * * ) ( V_15 + V_14 -> V_19 - V_21 ) ;
}
static inline bool F_9 ( struct V_13 * V_14 )
{
return F_10 ( & V_14 -> V_22 ) == 1 ;
}
static inline void F_11 ( struct V_13 * V_14 )
{
F_12 ( & V_14 -> V_22 , 1 ) ;
}
static inline void F_13 ( struct V_13 * V_14 )
{
if ( F_9 ( V_14 ) )
F_12 ( & V_14 -> V_22 , 0 ) ;
}
static inline void F_13 ( struct V_13 * V_14 ) {}
static inline struct V_13 * F_14 ( const void * V_23 )
{
struct V_24 * V_24 = F_15 ( V_23 ) ;
return V_24 -> V_25 ;
}
static inline void * F_16 ( struct V_13 * V_26 , struct V_24 * V_24 ,
unsigned int V_27 )
{
return V_24 -> V_28 + V_26 -> V_19 * V_27 ;
}
static inline unsigned int F_17 ( const struct V_13 * V_26 ,
const struct V_24 * V_24 , void * V_23 )
{
T_1 V_29 = ( V_23 - V_24 -> V_28 ) ;
return F_18 ( V_29 , V_26 -> V_30 ) ;
}
static inline struct V_31 * F_19 ( struct V_13 * V_14 )
{
return F_20 ( V_14 -> V_32 ) ;
}
static unsigned int F_21 ( unsigned long V_33 , T_2 V_34 ,
unsigned long V_16 , T_2 * V_35 )
{
unsigned int V_36 ;
T_2 V_37 = V_38 << V_33 ;
if ( V_16 & ( V_39 | V_40 ) ) {
V_36 = V_37 / V_34 ;
* V_35 = V_37 % V_34 ;
} else {
V_36 = V_37 / ( V_34 + sizeof( V_41 ) ) ;
* V_35 = V_37 %
( V_34 + sizeof( V_41 ) ) ;
}
return V_36 ;
}
static void F_22 ( const char * V_42 , struct V_13 * V_14 ,
char * V_43 )
{
F_23 ( L_1 ,
V_42 , V_14 -> V_44 , V_43 ) ;
F_24 () ;
F_25 ( V_45 , V_46 ) ;
}
static int T_3 F_26 ( char * V_47 )
{
V_48 = 0 ;
return 1 ;
}
static int T_3 F_27 ( char * V_49 )
{
F_28 ( & V_49 , & V_50 ) ;
V_50 = V_50 < 0 ? 0 :
F_29 ( V_50 , V_51 - 1 ) ;
V_52 = true ;
return 1 ;
}
static void F_30 ( int V_53 )
{
F_31 ( V_54 , V_53 ) = F_32 ( F_33 ( V_53 ) ,
V_55 ) ;
}
static void F_34 ( void )
{
int V_56 = F_35 ( V_54 ) ;
V_56 = F_32 ( V_56 , V_55 ) ;
F_36 ( V_54 , V_56 ) ;
}
static void F_37 ( int V_53 )
{
struct V_57 * V_58 = & F_31 ( V_59 , V_53 ) ;
if ( F_38 () && V_58 -> V_60 . V_61 == NULL ) {
F_30 ( V_53 ) ;
F_39 ( V_58 , V_62 ) ;
F_40 ( V_53 , V_58 ,
F_41 ( V_63 , V_53 ) ) ;
}
}
static void F_42 ( struct V_31 * V_64 , int V_65 , int V_66 )
{
F_43 ( V_64 ) ;
if ( V_64 ) {
V_64 -> V_67 = 0 ;
V_64 -> V_65 = V_65 ;
V_64 -> V_68 = V_66 ;
V_64 -> V_69 = 0 ;
}
}
static struct V_31 * F_44 ( int V_56 , int V_70 ,
int V_68 , T_4 V_71 )
{
T_2 V_72 = sizeof( void * ) * V_70 + sizeof( struct V_31 ) ;
struct V_31 * V_64 = NULL ;
V_64 = F_45 ( V_72 , V_71 , V_56 ) ;
F_42 ( V_64 , V_70 , V_68 ) ;
return V_64 ;
}
static T_5 void F_46 ( struct V_13 * V_14 ,
struct V_24 * V_24 , void * V_15 )
{
struct V_1 * V_73 ;
int V_74 ;
F_47 ( V_75 ) ;
V_74 = F_48 ( V_24 ) ;
V_73 = F_49 ( V_14 , V_74 ) ;
F_50 ( & V_73 -> V_9 ) ;
F_51 ( V_14 , & V_15 , 1 , V_74 , & V_75 ) ;
F_52 ( & V_73 -> V_9 ) ;
F_53 ( V_14 , & V_75 ) ;
}
static int F_54 ( struct V_31 * V_76 ,
struct V_31 * V_77 , unsigned int V_78 )
{
int V_79 = F_55 ( V_77 -> V_67 , V_78 , V_76 -> V_65 - V_76 -> V_67 ) ;
if ( ! V_79 )
return 0 ;
memcpy ( V_76 -> V_80 + V_76 -> V_67 , V_77 -> V_80 + V_77 -> V_67 - V_79 ,
sizeof( void * ) * V_79 ) ;
V_77 -> V_67 -= V_79 ;
V_76 -> V_67 += V_79 ;
return V_79 ;
}
static inline struct V_81 * * F_56 ( int V_56 ,
int V_65 , T_4 V_71 )
{
return NULL ;
}
static inline void F_57 ( struct V_81 * * V_82 )
{
}
static inline int F_58 ( struct V_13 * V_14 , void * V_15 )
{
return 0 ;
}
static inline void * F_59 ( struct V_13 * V_14 ,
T_4 V_16 )
{
return NULL ;
}
static inline void * F_60 ( struct V_13 * V_14 ,
T_4 V_16 , int V_83 )
{
return NULL ;
}
static inline T_4 F_61 ( T_4 V_16 )
{
return V_16 & ~ V_84 ;
}
static struct V_81 * F_62 ( int V_56 , int V_70 ,
int V_66 , T_4 V_71 )
{
T_2 V_72 = sizeof( void * ) * V_70 + sizeof( struct V_81 ) ;
struct V_81 * V_85 = NULL ;
V_85 = F_45 ( V_72 , V_71 , V_56 ) ;
F_42 ( & V_85 -> V_64 , V_70 , V_66 ) ;
F_3 ( & V_85 -> V_86 ) ;
return V_85 ;
}
static struct V_81 * * F_56 ( int V_56 , int V_65 , T_4 V_71 )
{
struct V_81 * * V_87 ;
T_2 V_72 = sizeof( void * ) * V_88 ;
int V_89 ;
if ( V_65 > 1 )
V_65 = 12 ;
V_87 = F_63 ( V_72 , V_71 , V_56 ) ;
if ( ! V_87 )
return NULL ;
F_64 (i) {
if ( V_89 == V_56 || ! F_65 ( V_89 ) )
continue;
V_87 [ V_89 ] = F_62 ( V_56 , V_65 , 0xbaadf00d , V_71 ) ;
if ( ! V_87 [ V_89 ] ) {
for ( V_89 -- ; V_89 >= 0 ; V_89 -- )
F_66 ( V_87 [ V_89 ] ) ;
F_66 ( V_87 ) ;
return NULL ;
}
}
return V_87 ;
}
static void F_57 ( struct V_81 * * V_87 )
{
int V_89 ;
if ( ! V_87 )
return;
F_64 (i)
F_66 ( V_87 [ V_89 ] ) ;
F_66 ( V_87 ) ;
}
static void F_67 ( struct V_13 * V_14 ,
struct V_31 * V_64 , int V_56 ,
struct V_90 * V_75 )
{
struct V_1 * V_73 = F_49 ( V_14 , V_56 ) ;
if ( V_64 -> V_67 ) {
F_50 ( & V_73 -> V_9 ) ;
if ( V_73 -> V_6 )
F_54 ( V_73 -> V_6 , V_64 , V_64 -> V_65 ) ;
F_51 ( V_14 , V_64 -> V_80 , V_64 -> V_67 , V_56 , V_75 ) ;
V_64 -> V_67 = 0 ;
F_52 ( & V_73 -> V_9 ) ;
}
}
static void F_68 ( struct V_13 * V_14 , struct V_1 * V_73 )
{
int V_56 = F_35 ( V_54 ) ;
if ( V_73 -> V_7 ) {
struct V_81 * V_85 = V_73 -> V_7 [ V_56 ] ;
struct V_31 * V_64 ;
if ( V_85 ) {
V_64 = & V_85 -> V_64 ;
if ( V_64 -> V_67 && F_69 ( & V_85 -> V_86 ) ) {
F_47 ( V_75 ) ;
F_67 ( V_14 , V_64 , V_56 , & V_75 ) ;
F_70 ( & V_85 -> V_86 ) ;
F_53 ( V_14 , & V_75 ) ;
}
}
}
}
static void F_71 ( struct V_13 * V_14 ,
struct V_81 * * V_7 )
{
int V_89 = 0 ;
struct V_81 * V_85 ;
struct V_31 * V_64 ;
unsigned long V_16 ;
F_72 (i) {
V_85 = V_7 [ V_89 ] ;
if ( V_85 ) {
F_47 ( V_75 ) ;
V_64 = & V_85 -> V_64 ;
F_73 ( & V_85 -> V_86 , V_16 ) ;
F_67 ( V_14 , V_64 , V_89 , & V_75 ) ;
F_74 ( & V_85 -> V_86 , V_16 ) ;
F_53 ( V_14 , & V_75 ) ;
}
}
}
static int F_75 ( struct V_13 * V_14 , void * V_15 ,
int V_56 , int V_74 )
{
struct V_1 * V_73 ;
struct V_81 * V_7 = NULL ;
struct V_31 * V_64 ;
F_47 ( V_75 ) ;
V_73 = F_49 ( V_14 , V_56 ) ;
F_76 ( V_14 ) ;
if ( V_73 -> V_7 && V_73 -> V_7 [ V_74 ] ) {
V_7 = V_73 -> V_7 [ V_74 ] ;
V_64 = & V_7 -> V_64 ;
F_50 ( & V_7 -> V_86 ) ;
if ( F_77 ( V_64 -> V_67 == V_64 -> V_65 ) ) {
F_78 ( V_14 ) ;
F_67 ( V_14 , V_64 , V_74 , & V_75 ) ;
}
V_64 -> V_80 [ V_64 -> V_67 ++ ] = V_15 ;
F_52 ( & V_7 -> V_86 ) ;
F_53 ( V_14 , & V_75 ) ;
} else {
V_73 = F_49 ( V_14 , V_74 ) ;
F_50 ( & V_73 -> V_9 ) ;
F_51 ( V_14 , & V_15 , 1 , V_74 , & V_75 ) ;
F_52 ( & V_73 -> V_9 ) ;
F_53 ( V_14 , & V_75 ) ;
}
return 1 ;
}
static inline int F_58 ( struct V_13 * V_14 , void * V_15 )
{
int V_74 = F_48 ( F_79 ( V_15 ) ) ;
int V_56 = F_80 () ;
if ( F_81 ( V_56 == V_74 ) )
return 0 ;
return F_75 ( V_14 , V_15 , V_56 , V_74 ) ;
}
static inline T_4 F_61 ( T_4 V_16 )
{
return ( V_16 | V_91 | V_92 ) & ~ ( V_93 | V_84 ) ;
}
static int F_82 ( struct V_13 * V_14 , int V_56 , T_4 V_71 )
{
struct V_1 * V_73 ;
V_73 = F_49 ( V_14 , V_56 ) ;
if ( V_73 ) {
F_83 ( & V_73 -> V_9 ) ;
V_73 -> V_94 = ( 1 + F_84 ( V_56 ) ) * V_14 -> V_68 +
V_14 -> V_36 ;
F_70 ( & V_73 -> V_9 ) ;
return 0 ;
}
V_73 = F_45 ( sizeof( struct V_1 ) , V_71 , V_56 ) ;
if ( ! V_73 )
return - V_95 ;
F_1 ( V_73 ) ;
V_73 -> V_96 = V_97 + V_98 +
( ( unsigned long ) V_14 ) % V_98 ;
V_73 -> V_94 =
( 1 + F_84 ( V_56 ) ) * V_14 -> V_68 + V_14 -> V_36 ;
V_14 -> V_56 [ V_56 ] = V_73 ;
return 0 ;
}
static int F_85 ( int V_56 )
{
int V_99 ;
struct V_13 * V_14 ;
F_86 (cachep, &slab_caches, list) {
V_99 = F_82 ( V_14 , V_56 , V_100 ) ;
if ( V_99 )
return V_99 ;
}
return 0 ;
}
static int F_87 ( struct V_13 * V_14 ,
int V_56 , T_4 V_71 , bool V_101 )
{
int V_99 = - V_95 ;
struct V_1 * V_73 ;
struct V_31 * V_102 = NULL ;
struct V_31 * V_103 = NULL ;
struct V_81 * * V_104 = NULL ;
F_47 ( V_75 ) ;
if ( V_48 ) {
V_104 = F_56 ( V_56 , V_14 -> V_65 , V_71 ) ;
if ( ! V_104 )
goto V_105;
}
if ( V_14 -> V_6 ) {
V_103 = F_44 ( V_56 ,
V_14 -> V_6 * V_14 -> V_68 , 0xbaadf00d , V_71 ) ;
if ( ! V_103 )
goto V_105;
}
V_99 = F_82 ( V_14 , V_56 , V_71 ) ;
if ( V_99 )
goto V_105;
V_73 = F_49 ( V_14 , V_56 ) ;
F_83 ( & V_73 -> V_9 ) ;
if ( V_73 -> V_6 && V_101 ) {
F_51 ( V_14 , V_73 -> V_6 -> V_80 ,
V_73 -> V_6 -> V_67 , V_56 , & V_75 ) ;
V_73 -> V_6 -> V_67 = 0 ;
}
if ( ! V_73 -> V_6 || V_101 ) {
V_102 = V_73 -> V_6 ;
V_73 -> V_6 = V_103 ;
V_103 = NULL ;
}
if ( ! V_73 -> V_7 ) {
V_73 -> V_7 = V_104 ;
V_104 = NULL ;
}
F_70 ( & V_73 -> V_9 ) ;
F_53 ( V_14 , & V_75 ) ;
if ( V_102 && V_101 )
F_88 () ;
V_105:
F_66 ( V_102 ) ;
F_66 ( V_103 ) ;
F_57 ( V_104 ) ;
return V_99 ;
}
static void F_89 ( long V_53 )
{
struct V_13 * V_14 ;
struct V_1 * V_73 = NULL ;
int V_56 = F_33 ( V_53 ) ;
const struct V_106 * V_107 = F_90 ( V_56 ) ;
F_86 (cachep, &slab_caches, list) {
struct V_31 * V_108 ;
struct V_31 * V_6 ;
struct V_81 * * V_7 ;
F_47 ( V_75 ) ;
V_73 = F_49 ( V_14 , V_56 ) ;
if ( ! V_73 )
continue;
F_83 ( & V_73 -> V_9 ) ;
V_73 -> V_94 -= V_14 -> V_68 ;
V_108 = F_91 ( V_14 -> V_32 , V_53 ) ;
if ( V_108 ) {
F_51 ( V_14 , V_108 -> V_80 , V_108 -> V_67 , V_56 , & V_75 ) ;
V_108 -> V_67 = 0 ;
}
if ( ! F_92 ( V_107 ) ) {
F_70 ( & V_73 -> V_9 ) ;
goto V_109;
}
V_6 = V_73 -> V_6 ;
if ( V_6 ) {
F_51 ( V_14 , V_6 -> V_80 ,
V_6 -> V_67 , V_56 , & V_75 ) ;
V_73 -> V_6 = NULL ;
}
V_7 = V_73 -> V_7 ;
V_73 -> V_7 = NULL ;
F_70 ( & V_73 -> V_9 ) ;
F_66 ( V_6 ) ;
if ( V_7 ) {
F_71 ( V_14 , V_7 ) ;
F_57 ( V_7 ) ;
}
V_109:
F_53 ( V_14 , & V_75 ) ;
}
F_86 (cachep, &slab_caches, list) {
V_73 = F_49 ( V_14 , V_56 ) ;
if ( ! V_73 )
continue;
F_93 ( V_14 , V_73 , V_110 ) ;
}
}
static int F_94 ( long V_53 )
{
struct V_13 * V_14 ;
int V_56 = F_33 ( V_53 ) ;
int V_111 ;
V_111 = F_85 ( V_56 ) ;
if ( V_111 < 0 )
goto V_112;
F_86 (cachep, &slab_caches, list) {
V_111 = F_87 ( V_14 , V_56 , V_100 , false ) ;
if ( V_111 )
goto V_112;
}
return 0 ;
V_112:
F_89 ( V_53 ) ;
return - V_95 ;
}
int F_95 ( unsigned int V_53 )
{
int V_111 ;
F_96 ( & V_113 ) ;
V_111 = F_94 ( V_53 ) ;
F_97 ( & V_113 ) ;
return V_111 ;
}
int F_98 ( unsigned int V_53 )
{
F_96 ( & V_113 ) ;
F_89 ( V_53 ) ;
F_97 ( & V_113 ) ;
return 0 ;
}
static int F_99 ( unsigned int V_53 )
{
F_37 ( V_53 ) ;
return 0 ;
}
static int F_100 ( unsigned int V_53 )
{
F_101 ( & F_31 ( V_59 , V_53 ) ) ;
F_31 ( V_59 , V_53 ) . V_60 . V_61 = NULL ;
return 0 ;
}
static int T_6 F_102 ( int V_56 )
{
struct V_13 * V_14 ;
int V_99 = 0 ;
F_86 (cachep, &slab_caches, list) {
struct V_1 * V_73 ;
V_73 = F_49 ( V_14 , V_56 ) ;
if ( ! V_73 )
continue;
F_93 ( V_14 , V_73 , V_110 ) ;
if ( ! F_103 ( & V_73 -> V_3 ) ||
! F_103 ( & V_73 -> V_4 ) ) {
V_99 = - V_114 ;
break;
}
}
return V_99 ;
}
static int T_6 F_104 ( struct V_115 * V_116 ,
unsigned long V_117 , void * V_118 )
{
struct V_119 * V_120 = V_118 ;
int V_99 = 0 ;
int V_121 ;
V_121 = V_120 -> V_122 ;
if ( V_121 < 0 )
goto V_123;
switch ( V_117 ) {
case V_124 :
F_96 ( & V_113 ) ;
V_99 = F_85 ( V_121 ) ;
F_97 ( & V_113 ) ;
break;
case V_125 :
F_96 ( & V_113 ) ;
V_99 = F_102 ( V_121 ) ;
F_97 ( & V_113 ) ;
break;
case V_126 :
case V_127 :
case V_128 :
case V_129 :
break;
}
V_123:
return F_105 ( V_99 ) ;
}
static void T_3 F_106 ( struct V_13 * V_14 , struct V_1 * V_75 ,
int V_83 )
{
struct V_1 * V_130 ;
V_130 = F_45 ( sizeof( struct V_1 ) , V_131 , V_83 ) ;
F_6 ( ! V_130 ) ;
memcpy ( V_130 , V_75 , sizeof( struct V_1 ) ) ;
F_3 ( & V_130 -> V_9 ) ;
F_107 ( V_14 , V_130 , V_83 ) ;
V_14 -> V_56 [ V_83 ] = V_130 ;
}
static void T_3 F_108 ( struct V_13 * V_14 , int V_132 )
{
int V_56 ;
F_72 (node) {
V_14 -> V_56 [ V_56 ] = & V_133 [ V_132 + V_56 ] ;
V_14 -> V_56 [ V_56 ] -> V_96 = V_97 +
V_98 +
( ( unsigned long ) V_14 ) % V_98 ;
}
}
void T_3 F_109 ( void )
{
int V_89 ;
F_110 ( sizeof( ( (struct V_24 * ) NULL ) -> V_134 ) <
sizeof( struct V_135 ) ) ;
V_13 = & V_136 ;
if ( ! F_111 ( V_137 ) || F_112 () == 1 )
V_48 = 0 ;
for ( V_89 = 0 ; V_89 < V_138 ; V_89 ++ )
F_1 ( & V_133 [ V_89 ] ) ;
if ( ! V_52 && V_139 > ( 32 << 20 ) >> V_140 )
V_50 = V_141 ;
F_113 ( V_13 , L_2 ,
F_114 ( struct V_13 , V_56 ) +
V_88 * sizeof( struct V_1 * ) ,
V_142 ) ;
F_115 ( & V_13 -> V_75 , & V_143 ) ;
V_144 = V_145 ;
V_146 [ V_147 ] = F_116 ( L_3 ,
F_117 ( V_147 ) , V_148 ) ;
V_144 = V_149 ;
F_118 () ;
V_150 = 0 ;
{
int V_121 ;
F_72 (nid) {
F_106 ( V_13 , & V_133 [ V_151 + V_121 ] , V_121 ) ;
F_106 ( V_146 [ V_147 ] ,
& V_133 [ V_152 + V_121 ] , V_121 ) ;
}
}
F_119 ( V_148 ) ;
}
void T_3 F_120 ( void )
{
struct V_13 * V_14 ;
V_144 = V_153 ;
F_96 ( & V_113 ) ;
F_86 (cachep, &slab_caches, list)
if ( F_121 ( V_14 , V_131 ) )
F_122 () ;
F_97 ( & V_113 ) ;
V_144 = V_154 ;
#ifdef V_137
F_123 ( F_104 , V_155 ) ;
#endif
}
static int T_3 F_124 ( void )
{
int V_99 ;
V_99 = F_125 ( V_156 , L_4 ,
F_99 , F_100 ) ;
F_126 ( V_99 < 0 ) ;
V_144 = V_154 ;
return 0 ;
}
static T_5 void
F_127 ( struct V_13 * V_14 , T_4 V_157 , int V_83 )
{
#if V_158
struct V_1 * V_73 ;
struct V_24 * V_24 ;
unsigned long V_16 ;
int V_56 ;
static F_128 ( V_159 , V_160 ,
V_161 ) ;
if ( ( V_157 & V_92 ) || ! F_129 ( & V_159 ) )
return;
F_130 ( L_5 ,
V_83 , V_157 , & V_157 ) ;
F_130 ( L_6 ,
V_14 -> V_44 , V_14 -> V_19 , V_14 -> V_33 ) ;
F_131 (cachep, node, n) {
unsigned long V_162 = 0 , V_163 = 0 , V_10 = 0 ;
unsigned long V_164 = 0 , V_12 = 0 ;
unsigned long V_165 = 0 , V_166 = 0 ;
unsigned long V_167 ;
F_73 ( & V_73 -> V_9 , V_16 ) ;
V_12 = V_73 -> V_12 ;
F_86 (page, &n->slabs_partial, lru) {
V_162 += V_24 -> V_168 ;
V_165 ++ ;
}
F_86 (page, &n->slabs_free, lru)
V_166 ++ ;
V_10 += V_73 -> V_10 ;
F_74 ( & V_73 -> V_9 , V_16 ) ;
V_163 = V_12 * V_14 -> V_36 ;
V_164 = V_12 - V_166 ;
V_167 = V_12 -
( V_165 + V_166 ) ;
V_162 += ( V_167 * V_14 -> V_36 ) ;
F_130 ( L_7 ,
V_56 , V_164 , V_12 , V_162 , V_163 ,
V_10 ) ;
}
#endif
}
static struct V_24 * F_132 ( struct V_13 * V_14 , T_4 V_16 ,
int V_83 )
{
struct V_24 * V_24 ;
int V_169 ;
V_16 |= V_14 -> V_170 ;
if ( V_14 -> V_16 & V_171 )
V_16 |= V_172 ;
V_24 = F_133 ( V_83 , V_16 | V_173 , V_14 -> V_33 ) ;
if ( ! V_24 ) {
F_127 ( V_14 , V_16 , V_83 ) ;
return NULL ;
}
if ( F_134 ( V_24 , V_16 , V_14 -> V_33 , V_14 ) ) {
F_135 ( V_24 , V_14 -> V_33 ) ;
return NULL ;
}
V_169 = ( 1 << V_14 -> V_33 ) ;
if ( V_14 -> V_16 & V_171 )
F_136 ( F_137 ( V_24 ) ,
V_174 , V_169 ) ;
else
F_136 ( F_137 ( V_24 ) ,
V_175 , V_169 ) ;
F_138 ( V_24 ) ;
if ( F_139 () && F_140 ( V_24 ) )
F_141 ( V_24 ) ;
if ( V_176 && ! ( V_14 -> V_16 & V_177 ) ) {
F_142 ( V_24 , V_14 -> V_33 , V_16 , V_83 ) ;
if ( V_14 -> V_178 )
F_143 ( V_24 , V_169 ) ;
else
F_144 ( V_24 , V_169 ) ;
}
return V_24 ;
}
static void F_145 ( struct V_13 * V_14 , struct V_24 * V_24 )
{
int V_179 = V_14 -> V_33 ;
unsigned long V_180 = ( 1 << V_179 ) ;
F_146 ( V_24 , V_179 ) ;
if ( V_14 -> V_16 & V_171 )
F_147 ( F_137 ( V_24 ) ,
V_174 , V_180 ) ;
else
F_147 ( F_137 ( V_24 ) ,
V_175 , V_180 ) ;
F_6 ( ! F_148 ( V_24 ) ) ;
F_149 ( V_24 ) ;
F_150 ( V_24 ) ;
F_151 ( V_24 ) ;
V_24 -> V_181 = NULL ;
if ( V_182 -> V_183 )
V_182 -> V_183 -> V_184 += V_180 ;
F_152 ( V_24 , V_179 , V_14 ) ;
F_135 ( V_24 , V_179 ) ;
}
static void F_153 ( struct V_135 * V_185 )
{
struct V_13 * V_14 ;
struct V_24 * V_24 ;
V_24 = F_154 ( V_185 , struct V_24 , V_135 ) ;
V_14 = V_24 -> V_25 ;
F_145 ( V_14 , V_24 ) ;
}
static bool F_155 ( struct V_13 * V_14 )
{
if ( F_156 () && F_157 ( V_14 ) &&
( V_14 -> V_19 % V_38 ) == 0 )
return true ;
return false ;
}
static void F_158 ( struct V_13 * V_14 , unsigned long * V_186 ,
unsigned long V_187 )
{
int V_19 = V_14 -> V_188 ;
V_186 = ( unsigned long * ) & ( ( char * ) V_186 ) [ F_4 ( V_14 ) ] ;
if ( V_19 < 5 * sizeof( unsigned long ) )
return;
* V_186 ++ = 0x12345678 ;
* V_186 ++ = V_187 ;
* V_186 ++ = F_159 () ;
V_19 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_189 = & V_187 ;
unsigned long V_190 ;
while ( ! F_160 ( V_189 ) ) {
V_190 = * V_189 ++ ;
if ( F_161 ( V_190 ) ) {
* V_186 ++ = V_190 ;
V_19 -= sizeof( unsigned long ) ;
if ( V_19 <= sizeof( unsigned long ) )
break;
}
}
}
* V_186 ++ = 0x87654321 ;
}
static void F_162 ( struct V_13 * V_14 , void * V_15 ,
int V_191 , unsigned long V_187 )
{
if ( ! F_155 ( V_14 ) )
return;
if ( V_187 )
F_158 ( V_14 , V_15 , V_187 ) ;
F_163 ( F_79 ( V_15 ) , V_14 -> V_19 / V_38 , V_191 ) ;
}
static inline void F_162 ( struct V_13 * V_14 , void * V_15 ,
int V_191 , unsigned long V_187 ) {}
static void F_164 ( struct V_13 * V_14 , void * V_186 , unsigned char V_192 )
{
int V_19 = V_14 -> V_188 ;
V_186 = & ( ( char * ) V_186 ) [ F_4 ( V_14 ) ] ;
memset ( V_186 , V_192 , V_19 ) ;
* ( unsigned char * ) ( V_186 + V_19 - 1 ) = V_193 ;
}
static void F_165 ( char * V_194 , int V_29 , int V_65 )
{
int V_89 ;
unsigned char error = 0 ;
int V_195 = 0 ;
F_23 ( L_8 , V_29 ) ;
for ( V_89 = 0 ; V_89 < V_65 ; V_89 ++ ) {
if ( V_194 [ V_29 + V_89 ] != V_196 ) {
error = V_194 [ V_29 + V_89 ] ;
V_195 ++ ;
}
}
F_166 ( V_197 , L_9 , 0 , 16 , 1 ,
& V_194 [ V_29 ] , V_65 , 1 ) ;
if ( V_195 == 1 ) {
error ^= V_196 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_23 ( L_10 ) ;
#ifdef F_167
F_23 ( L_11 ) ;
#else
F_23 ( L_12 ) ;
#endif
}
}
}
static void F_168 ( struct V_13 * V_14 , void * V_15 , int V_198 )
{
int V_89 , V_19 ;
char * V_199 ;
if ( V_14 -> V_16 & V_17 ) {
F_23 ( L_13 ,
* F_5 ( V_14 , V_15 ) ,
* F_7 ( V_14 , V_15 ) ) ;
}
if ( V_14 -> V_16 & V_18 ) {
F_23 ( L_14 ,
* F_8 ( V_14 , V_15 ) ,
* F_8 ( V_14 , V_15 ) ) ;
}
V_199 = ( char * ) V_15 + F_4 ( V_14 ) ;
V_19 = V_14 -> V_188 ;
for ( V_89 = 0 ; V_89 < V_19 && V_198 ; V_89 += 16 , V_198 -- ) {
int V_65 ;
V_65 = 16 ;
if ( V_89 + V_65 > V_19 )
V_65 = V_19 - V_89 ;
F_165 ( V_199 , V_89 , V_65 ) ;
}
}
static void F_169 ( struct V_13 * V_14 , void * V_15 )
{
char * V_199 ;
int V_19 , V_89 ;
int V_198 = 0 ;
if ( F_155 ( V_14 ) )
return;
V_199 = ( char * ) V_15 + F_4 ( V_14 ) ;
V_19 = V_14 -> V_188 ;
for ( V_89 = 0 ; V_89 < V_19 ; V_89 ++ ) {
char exp = V_196 ;
if ( V_89 == V_19 - 1 )
exp = V_193 ;
if ( V_199 [ V_89 ] != exp ) {
int V_65 ;
if ( V_198 == 0 ) {
F_23 ( L_15 ,
F_170 () , V_14 -> V_44 ,
V_199 , V_19 ) ;
F_168 ( V_14 , V_15 , 0 ) ;
}
V_89 = ( V_89 / 16 ) * 16 ;
V_65 = 16 ;
if ( V_89 + V_65 > V_19 )
V_65 = V_19 - V_89 ;
F_165 ( V_199 , V_89 , V_65 ) ;
V_89 += 16 ;
V_198 ++ ;
if ( V_198 > 5 )
break;
}
}
if ( V_198 != 0 ) {
struct V_24 * V_24 = F_15 ( V_15 ) ;
unsigned int V_200 ;
V_200 = F_17 ( V_14 , V_24 , V_15 ) ;
if ( V_200 ) {
V_15 = F_16 ( V_14 , V_24 , V_200 - 1 ) ;
V_199 = ( char * ) V_15 + F_4 ( V_14 ) ;
F_23 ( L_16 , V_199 , V_19 ) ;
F_168 ( V_14 , V_15 , 2 ) ;
}
if ( V_200 + 1 < V_14 -> V_36 ) {
V_15 = F_16 ( V_14 , V_24 , V_200 + 1 ) ;
V_199 = ( char * ) V_15 + F_4 ( V_14 ) ;
F_23 ( L_17 , V_199 , V_19 ) ;
F_168 ( V_14 , V_15 , 2 ) ;
}
}
}
static void F_171 ( struct V_13 * V_14 ,
struct V_24 * V_24 )
{
int V_89 ;
if ( F_172 ( V_14 ) && V_14 -> V_16 & V_201 ) {
F_164 ( V_14 , V_24 -> V_202 - F_4 ( V_14 ) ,
V_196 ) ;
}
for ( V_89 = 0 ; V_89 < V_14 -> V_36 ; V_89 ++ ) {
void * V_15 = F_16 ( V_14 , V_24 , V_89 ) ;
if ( V_14 -> V_16 & V_201 ) {
F_169 ( V_14 , V_15 ) ;
F_162 ( V_14 , V_15 , 1 , 0 ) ;
}
if ( V_14 -> V_16 & V_17 ) {
if ( * F_5 ( V_14 , V_15 ) != V_203 )
F_173 ( V_14 , L_18 ) ;
if ( * F_7 ( V_14 , V_15 ) != V_203 )
F_173 ( V_14 , L_19 ) ;
}
}
}
static void F_171 ( struct V_13 * V_14 ,
struct V_24 * V_24 )
{
}
static void F_174 ( struct V_13 * V_14 , struct V_24 * V_24 )
{
void * V_202 ;
V_202 = V_24 -> V_202 ;
F_171 ( V_14 , V_24 ) ;
if ( F_77 ( V_14 -> V_16 & V_204 ) )
F_175 ( & V_24 -> V_135 , F_153 ) ;
else
F_145 ( V_14 , V_24 ) ;
if ( F_157 ( V_14 ) )
F_176 ( V_14 -> V_205 , V_202 ) ;
}
static void F_53 ( struct V_13 * V_14 , struct V_90 * V_75 )
{
struct V_24 * V_24 , * V_73 ;
F_177 (page, n, list, lru) {
F_178 ( & V_24 -> V_134 ) ;
F_174 ( V_14 , V_24 ) ;
}
}
static T_2 F_179 ( struct V_13 * V_14 ,
T_2 V_19 , unsigned long V_16 )
{
T_2 V_35 = 0 ;
int V_33 ;
for ( V_33 = 0 ; V_33 <= V_206 ; V_33 ++ ) {
unsigned int V_36 ;
T_2 V_207 ;
V_36 = F_21 ( V_33 , V_19 , V_16 , & V_207 ) ;
if ( ! V_36 )
continue;
if ( V_36 > V_208 )
break;
if ( V_16 & V_40 ) {
struct V_13 * V_205 ;
T_2 V_209 ;
V_209 = V_36 * sizeof( V_41 ) ;
V_205 = F_180 ( V_209 , 0u ) ;
if ( ! V_205 )
continue;
if ( F_157 ( V_205 ) )
continue;
if ( V_205 -> V_19 > V_14 -> V_19 / 2 )
continue;
}
V_14 -> V_36 = V_36 ;
V_14 -> V_33 = V_33 ;
V_35 = V_207 ;
if ( V_16 & V_171 )
break;
if ( V_33 >= V_50 )
break;
if ( V_35 * 8 <= ( V_38 << V_33 ) )
break;
}
return V_35 ;
}
static struct V_31 T_7 * F_181 (
struct V_13 * V_14 , int V_70 , int V_68 )
{
int V_53 ;
T_2 V_19 ;
struct V_31 T_7 * V_32 ;
V_19 = sizeof( void * ) * V_70 + sizeof( struct V_31 ) ;
V_32 = F_182 ( V_19 , sizeof( void * ) ) ;
if ( ! V_32 )
return NULL ;
F_183 (cpu) {
F_42 ( F_91 ( V_32 , V_53 ) ,
V_70 , V_68 ) ;
}
return V_32 ;
}
static int T_8 F_184 ( struct V_13 * V_14 , T_4 V_71 )
{
if ( V_144 >= V_154 )
return F_121 ( V_14 , V_71 ) ;
V_14 -> V_32 = F_181 ( V_14 , 1 , 1 ) ;
if ( ! V_14 -> V_32 )
return 1 ;
if ( V_144 == V_210 ) {
F_108 ( V_13 , V_151 ) ;
} else if ( V_144 == V_145 ) {
F_108 ( V_14 , V_152 ) ;
} else {
int V_56 ;
F_72 (node) {
V_14 -> V_56 [ V_56 ] = F_45 (
sizeof( struct V_1 ) , V_71 , V_56 ) ;
F_6 ( ! V_14 -> V_56 [ V_56 ] ) ;
F_1 ( V_14 -> V_56 [ V_56 ] ) ;
}
}
V_14 -> V_56 [ F_80 () ] -> V_96 =
V_97 + V_98 +
( ( unsigned long ) V_14 ) % V_98 ;
F_19 ( V_14 ) -> V_67 = 0 ;
F_19 ( V_14 ) -> V_65 = V_211 ;
F_19 ( V_14 ) -> V_68 = 1 ;
F_19 ( V_14 ) -> V_69 = 0 ;
V_14 -> V_68 = 1 ;
V_14 -> V_65 = V_211 ;
return 0 ;
}
unsigned long F_185 ( unsigned long V_188 ,
unsigned long V_16 , const char * V_44 ,
void (* V_178)( void * ) )
{
return V_16 ;
}
struct V_13 *
F_186 ( const char * V_44 , T_2 V_19 , T_2 V_212 ,
unsigned long V_16 , void (* V_178)( void * ) )
{
struct V_13 * V_14 ;
V_14 = F_187 ( V_19 , V_212 , V_16 , V_44 , V_178 ) ;
if ( V_14 ) {
V_14 -> V_213 ++ ;
V_14 -> V_188 = F_188 ( int , V_14 -> V_188 , V_19 ) ;
}
return V_14 ;
}
static bool F_189 ( struct V_13 * V_14 ,
T_2 V_19 , unsigned long V_16 )
{
T_2 V_214 ;
V_14 -> V_36 = 0 ;
if ( V_14 -> V_178 || V_16 & V_204 )
return false ;
V_214 = F_179 ( V_14 , V_19 ,
V_16 | V_39 ) ;
if ( ! V_14 -> V_36 )
return false ;
if ( V_14 -> V_36 * sizeof( V_41 ) > V_14 -> V_188 )
return false ;
V_14 -> V_215 = V_214 / V_14 -> V_216 ;
return true ;
}
static bool F_190 ( struct V_13 * V_14 ,
T_2 V_19 , unsigned long V_16 )
{
T_2 V_214 ;
V_14 -> V_36 = 0 ;
if ( V_16 & V_217 )
return false ;
V_214 = F_179 ( V_14 , V_19 , V_16 | V_40 ) ;
if ( ! V_14 -> V_36 )
return false ;
if ( V_214 >= V_14 -> V_36 * sizeof( V_41 ) )
return false ;
V_14 -> V_215 = V_214 / V_14 -> V_216 ;
return true ;
}
static bool F_191 ( struct V_13 * V_14 ,
T_2 V_19 , unsigned long V_16 )
{
T_2 V_214 ;
V_14 -> V_36 = 0 ;
V_214 = F_179 ( V_14 , V_19 , V_16 ) ;
if ( ! V_14 -> V_36 )
return false ;
V_14 -> V_215 = V_214 / V_14 -> V_216 ;
return true ;
}
int
F_192 ( struct V_13 * V_14 , unsigned long V_16 )
{
T_2 V_218 = V_21 ;
T_4 V_71 ;
int V_111 ;
T_2 V_19 = V_14 -> V_19 ;
#if V_158
#if V_219
if ( V_19 < 4096 || F_193 ( V_19 - 1 ) == F_193 ( V_19 - 1 + V_20 +
2 * sizeof( unsigned long long ) ) )
V_16 |= V_17 | V_18 ;
if ( ! ( V_16 & V_204 ) )
V_16 |= V_201 ;
#endif
#endif
if ( V_19 & ( V_21 - 1 ) ) {
V_19 += ( V_21 - 1 ) ;
V_19 &= ~ ( V_21 - 1 ) ;
}
if ( V_16 & V_17 ) {
V_218 = V_20 ;
V_19 += V_20 - 1 ;
V_19 &= ~ ( V_20 - 1 ) ;
}
if ( V_218 < V_14 -> V_212 ) {
V_218 = V_14 -> V_212 ;
}
if ( V_218 > F_194 (unsigned long long) )
V_16 &= ~ ( V_17 | V_18 ) ;
V_14 -> V_212 = V_218 ;
V_14 -> V_216 = F_195 () ;
if ( V_14 -> V_216 < V_14 -> V_212 )
V_14 -> V_216 = V_14 -> V_212 ;
if ( F_196 () )
V_71 = V_100 ;
else
V_71 = V_131 ;
#if V_158
if ( V_16 & V_17 ) {
V_14 -> F_4 += sizeof( unsigned long long ) ;
V_19 += 2 * sizeof( unsigned long long ) ;
}
if ( V_16 & V_18 ) {
if ( V_16 & V_17 )
V_19 += V_20 ;
else
V_19 += V_21 ;
}
#endif
F_197 ( V_14 , & V_19 , & V_16 ) ;
V_19 = F_198 ( V_19 , V_14 -> V_212 ) ;
if ( V_220 && V_19 < V_221 )
V_19 = F_198 ( V_221 , V_14 -> V_212 ) ;
#if V_158
if ( F_156 () && ( V_16 & V_201 ) &&
V_19 >= 256 && V_14 -> V_188 > F_195 () ) {
if ( V_19 < V_38 || V_19 % V_38 == 0 ) {
T_2 V_222 = F_198 ( V_19 , V_38 ) ;
if ( F_190 ( V_14 , V_222 , V_16 ) ) {
V_16 |= V_40 ;
V_14 -> F_4 += V_222 - V_19 ;
V_19 = V_222 ;
goto V_223;
}
}
}
#endif
if ( F_189 ( V_14 , V_19 , V_16 ) ) {
V_16 |= V_39 ;
goto V_223;
}
if ( F_190 ( V_14 , V_19 , V_16 ) ) {
V_16 |= V_40 ;
goto V_223;
}
if ( F_191 ( V_14 , V_19 , V_16 ) )
goto V_223;
return - V_224 ;
V_223:
V_14 -> V_209 = V_14 -> V_36 * sizeof( V_41 ) ;
V_14 -> V_16 = V_16 ;
V_14 -> V_170 = V_225 ;
if ( V_16 & V_226 )
V_14 -> V_170 |= V_227 ;
V_14 -> V_19 = V_19 ;
V_14 -> V_30 = F_199 ( V_19 ) ;
#if V_158
if ( F_111 ( V_228 ) &&
( V_14 -> V_16 & V_201 ) &&
F_155 ( V_14 ) )
V_14 -> V_16 &= ~ ( V_17 | V_18 ) ;
#endif
if ( F_157 ( V_14 ) ) {
V_14 -> V_205 =
F_180 ( V_14 -> V_209 , 0u ) ;
}
V_111 = F_184 ( V_14 , V_71 ) ;
if ( V_111 ) {
F_200 ( V_14 ) ;
return V_111 ;
}
return 0 ;
}
static void F_201 ( void )
{
F_6 ( ! F_202 () ) ;
}
static void F_203 ( void )
{
F_6 ( F_202 () ) ;
}
static void F_204 ( void )
{
F_6 ( ! F_205 ( & V_113 ) ) ;
}
static void F_206 ( struct V_13 * V_14 )
{
#ifdef F_207
F_201 () ;
F_208 ( & F_49 ( V_14 , F_80 () ) -> V_9 ) ;
#endif
}
static void F_209 ( struct V_13 * V_14 , int V_56 )
{
#ifdef F_207
F_201 () ;
F_208 ( & F_49 ( V_14 , V_56 ) -> V_9 ) ;
#endif
}
static void F_210 ( struct V_13 * V_14 , struct V_31 * V_64 ,
int V_56 , bool V_229 , struct V_90 * V_75 )
{
int V_230 ;
if ( ! V_64 || ! V_64 -> V_67 )
return;
V_230 = V_229 ? V_64 -> V_67 : ( V_64 -> V_65 + 4 ) / 5 ;
if ( V_230 > V_64 -> V_67 )
V_230 = ( V_64 -> V_67 + 1 ) / 2 ;
F_51 ( V_14 , V_64 -> V_80 , V_230 , V_56 , V_75 ) ;
V_64 -> V_67 -= V_230 ;
memmove ( V_64 -> V_80 , & ( V_64 -> V_80 [ V_230 ] ) , sizeof( void * ) * V_64 -> V_67 ) ;
}
static void F_211 ( void * V_118 )
{
struct V_13 * V_14 = V_118 ;
struct V_31 * V_64 ;
int V_56 = F_80 () ;
struct V_1 * V_73 ;
F_47 ( V_75 ) ;
F_201 () ;
V_64 = F_19 ( V_14 ) ;
V_73 = F_49 ( V_14 , V_56 ) ;
F_50 ( & V_73 -> V_9 ) ;
F_51 ( V_14 , V_64 -> V_80 , V_64 -> V_67 , V_56 , & V_75 ) ;
F_52 ( & V_73 -> V_9 ) ;
F_53 ( V_14 , & V_75 ) ;
V_64 -> V_67 = 0 ;
}
static void F_212 ( struct V_13 * V_14 )
{
struct V_1 * V_73 ;
int V_56 ;
F_47 ( V_75 ) ;
F_213 ( F_211 , V_14 , 1 ) ;
F_203 () ;
F_131 (cachep, node, n)
if ( V_73 -> V_7 )
F_71 ( V_14 , V_73 -> V_7 ) ;
F_131 (cachep, node, n) {
F_83 ( & V_73 -> V_9 ) ;
F_210 ( V_14 , V_73 -> V_6 , V_56 , true , & V_75 ) ;
F_70 ( & V_73 -> V_9 ) ;
F_53 ( V_14 , & V_75 ) ;
}
}
static int F_93 ( struct V_13 * V_26 ,
struct V_1 * V_73 , int V_230 )
{
struct V_90 * V_231 ;
int V_180 ;
struct V_24 * V_24 ;
V_180 = 0 ;
while ( V_180 < V_230 && ! F_103 ( & V_73 -> V_5 ) ) {
F_83 ( & V_73 -> V_9 ) ;
V_231 = V_73 -> V_5 . V_232 ;
if ( V_231 == & V_73 -> V_5 ) {
F_70 ( & V_73 -> V_9 ) ;
goto V_123;
}
V_24 = F_214 ( V_231 , struct V_24 , V_134 ) ;
F_178 ( & V_24 -> V_134 ) ;
V_73 -> V_12 -- ;
V_73 -> V_10 -= V_26 -> V_36 ;
F_70 ( & V_73 -> V_9 ) ;
F_174 ( V_26 , V_24 ) ;
V_180 ++ ;
}
V_123:
return V_180 ;
}
int F_215 ( struct V_13 * V_14 , bool V_233 )
{
int V_99 = 0 ;
int V_56 ;
struct V_1 * V_73 ;
F_212 ( V_14 ) ;
F_203 () ;
F_131 (cachep, node, n) {
F_93 ( V_14 , V_73 , V_110 ) ;
V_99 += ! F_103 ( & V_73 -> V_3 ) ||
! F_103 ( & V_73 -> V_4 ) ;
}
return ( V_99 ? 1 : 0 ) ;
}
int F_216 ( struct V_13 * V_14 )
{
return F_215 ( V_14 , false ) ;
}
void F_200 ( struct V_13 * V_14 )
{
int V_89 ;
struct V_1 * V_73 ;
F_217 ( V_14 ) ;
F_218 ( V_14 -> V_32 ) ;
F_131 (cachep, i, n) {
F_66 ( V_73 -> V_6 ) ;
F_57 ( V_73 -> V_7 ) ;
F_66 ( V_73 ) ;
V_14 -> V_56 [ V_89 ] = NULL ;
}
}
static void * F_219 ( struct V_13 * V_14 ,
struct V_24 * V_24 , int V_216 ,
T_4 V_234 , int V_83 )
{
void * V_202 ;
void * V_186 = F_220 ( V_24 ) ;
V_24 -> V_28 = V_186 + V_216 ;
V_24 -> V_168 = 0 ;
if ( F_172 ( V_14 ) )
V_202 = NULL ;
else if ( F_157 ( V_14 ) ) {
V_202 = F_221 ( V_14 -> V_205 ,
V_234 , V_83 ) ;
if ( ! V_202 )
return NULL ;
} else {
V_202 = V_186 + ( V_38 << V_14 -> V_33 ) -
V_14 -> V_209 ;
}
return V_202 ;
}
static inline V_41 F_222 ( struct V_24 * V_24 , unsigned int V_27 )
{
return ( ( V_41 * ) V_24 -> V_202 ) [ V_27 ] ;
}
static inline void F_223 ( struct V_24 * V_24 ,
unsigned int V_27 , V_41 V_192 )
{
( ( V_41 * ) ( V_24 -> V_202 ) ) [ V_27 ] = V_192 ;
}
static void F_224 ( struct V_13 * V_14 , struct V_24 * V_24 )
{
#if V_158
int V_89 ;
for ( V_89 = 0 ; V_89 < V_14 -> V_36 ; V_89 ++ ) {
void * V_15 = F_16 ( V_14 , V_24 , V_89 ) ;
if ( V_14 -> V_16 & V_18 )
* F_8 ( V_14 , V_15 ) = NULL ;
if ( V_14 -> V_16 & V_17 ) {
* F_5 ( V_14 , V_15 ) = V_203 ;
* F_7 ( V_14 , V_15 ) = V_203 ;
}
if ( V_14 -> V_178 && ! ( V_14 -> V_16 & V_201 ) ) {
F_225 ( V_14 ,
V_15 + F_4 ( V_14 ) ) ;
V_14 -> V_178 ( V_15 + F_4 ( V_14 ) ) ;
F_226 (
V_14 , V_15 + F_4 ( V_14 ) ) ;
}
if ( V_14 -> V_16 & V_17 ) {
if ( * F_7 ( V_14 , V_15 ) != V_203 )
F_173 ( V_14 , L_20 ) ;
if ( * F_5 ( V_14 , V_15 ) != V_203 )
F_173 ( V_14 , L_21 ) ;
}
if ( V_14 -> V_16 & V_201 ) {
F_164 ( V_14 , V_15 , V_196 ) ;
F_162 ( V_14 , V_15 , 0 , 0 ) ;
}
}
#endif
}
static bool F_227 ( union V_235 * V_236 ,
struct V_13 * V_14 ,
unsigned int V_237 )
{
bool V_99 ;
unsigned int rand ;
rand = F_228 () ;
if ( ! V_14 -> V_238 ) {
F_229 ( & V_236 -> V_239 , rand ) ;
V_99 = false ;
} else {
V_236 -> V_75 = V_14 -> V_238 ;
V_236 -> V_237 = V_237 ;
V_236 -> V_240 = 0 ;
V_236 -> rand = rand ;
V_99 = true ;
}
return V_99 ;
}
static V_41 F_230 ( union V_235 * V_236 )
{
return ( V_236 -> V_75 [ V_236 -> V_240 ++ ] + V_236 -> rand ) % V_236 -> V_237 ;
}
static void F_231 ( struct V_24 * V_24 , unsigned int V_241 , unsigned int V_242 )
{
F_232 ( ( ( V_41 * ) V_24 -> V_202 ) [ V_241 ] ,
( ( V_41 * ) V_24 -> V_202 ) [ V_242 ] ) ;
}
static bool F_233 ( struct V_13 * V_14 , struct V_24 * V_24 )
{
unsigned int V_243 = 0 , V_89 , rand , V_237 = V_14 -> V_36 ;
union V_235 V_236 ;
bool V_244 ;
if ( V_237 < 2 )
return false ;
V_244 = F_227 ( & V_236 , V_14 , V_237 ) ;
if ( F_172 ( V_14 ) ) {
if ( ! V_244 )
V_243 = V_237 - 1 ;
else
V_243 = F_230 ( & V_236 ) ;
V_24 -> V_202 = F_16 ( V_14 , V_24 , V_243 ) +
F_4 ( V_14 ) ;
V_237 -- ;
}
if ( ! V_244 ) {
for ( V_89 = 0 ; V_89 < V_237 ; V_89 ++ )
F_223 ( V_24 , V_89 , V_89 ) ;
for ( V_89 = V_237 - 1 ; V_89 > 0 ; V_89 -- ) {
rand = F_234 ( & V_236 . V_239 ) ;
rand %= ( V_89 + 1 ) ;
F_231 ( V_24 , V_89 , rand ) ;
}
} else {
for ( V_89 = 0 ; V_89 < V_237 ; V_89 ++ )
F_223 ( V_24 , V_89 , F_230 ( & V_236 ) ) ;
}
if ( F_172 ( V_14 ) )
F_223 ( V_24 , V_14 -> V_36 - 1 , V_243 ) ;
return true ;
}
static inline bool F_233 ( struct V_13 * V_14 ,
struct V_24 * V_24 )
{
return false ;
}
static void F_235 ( struct V_13 * V_14 ,
struct V_24 * V_24 )
{
int V_89 ;
void * V_15 ;
bool V_245 ;
F_224 ( V_14 , V_24 ) ;
V_245 = F_233 ( V_14 , V_24 ) ;
if ( ! V_245 && F_172 ( V_14 ) ) {
V_24 -> V_202 = F_16 ( V_14 , V_24 , V_14 -> V_36 - 1 ) +
F_4 ( V_14 ) ;
}
for ( V_89 = 0 ; V_89 < V_14 -> V_36 ; V_89 ++ ) {
V_15 = F_16 ( V_14 , V_24 , V_89 ) ;
F_236 ( V_14 , V_15 ) ;
if ( V_158 == 0 && V_14 -> V_178 ) {
F_225 ( V_14 , V_15 ) ;
V_14 -> V_178 ( V_15 ) ;
F_226 ( V_14 , V_15 ) ;
}
if ( ! V_245 )
F_223 ( V_24 , V_89 , V_89 ) ;
}
}
static void * F_237 ( struct V_13 * V_14 , struct V_24 * V_24 )
{
void * V_15 ;
V_15 = F_16 ( V_14 , V_24 , F_222 ( V_24 , V_24 -> V_168 ) ) ;
V_24 -> V_168 ++ ;
#if V_158
if ( V_14 -> V_16 & V_18 )
F_13 ( V_14 ) ;
#endif
return V_15 ;
}
static void F_238 ( struct V_13 * V_14 ,
struct V_24 * V_24 , void * V_15 )
{
unsigned int V_200 = F_17 ( V_14 , V_24 , V_15 ) ;
#if V_158
unsigned int V_89 ;
for ( V_89 = V_24 -> V_168 ; V_89 < V_14 -> V_36 ; V_89 ++ ) {
if ( F_222 ( V_24 , V_89 ) == V_200 ) {
F_23 ( L_22 ,
V_14 -> V_44 , V_15 ) ;
F_122 () ;
}
}
#endif
V_24 -> V_168 -- ;
if ( ! V_24 -> V_202 )
V_24 -> V_202 = V_15 + F_4 ( V_14 ) ;
F_223 ( V_24 , V_24 -> V_168 , V_200 ) ;
}
static void F_239 ( struct V_13 * V_26 , struct V_24 * V_24 ,
void * V_202 )
{
V_24 -> V_25 = V_26 ;
V_24 -> V_202 = V_202 ;
}
static struct V_24 * F_240 ( struct V_13 * V_14 ,
T_4 V_16 , int V_83 )
{
void * V_202 ;
T_2 V_29 ;
T_4 V_234 ;
int V_74 ;
struct V_1 * V_73 ;
struct V_24 * V_24 ;
if ( F_77 ( V_16 & V_246 ) ) {
T_4 V_247 = V_16 & V_246 ;
V_16 &= ~ V_246 ;
F_130 ( L_23 ,
V_247 , & V_247 , V_16 , & V_16 ) ;
F_24 () ;
}
V_234 = V_16 & ( V_248 | V_249 ) ;
F_201 () ;
if ( F_241 ( V_234 ) )
F_242 () ;
V_24 = F_132 ( V_14 , V_234 , V_83 ) ;
if ( ! V_24 )
goto V_250;
V_74 = F_48 ( V_24 ) ;
V_73 = F_49 ( V_14 , V_74 ) ;
V_73 -> V_8 ++ ;
if ( V_73 -> V_8 >= V_14 -> V_215 )
V_73 -> V_8 = 0 ;
V_29 = V_73 -> V_8 ;
if ( V_29 >= V_14 -> V_215 )
V_29 = 0 ;
V_29 *= V_14 -> V_216 ;
V_202 = F_219 ( V_14 , V_24 , V_29 ,
V_234 & ~ V_248 , V_74 ) ;
if ( F_157 ( V_14 ) && ! V_202 )
goto V_251;
F_239 ( V_14 , V_24 , V_202 ) ;
F_243 ( V_24 ) ;
F_235 ( V_14 , V_24 ) ;
if ( F_241 ( V_234 ) )
F_244 () ;
return V_24 ;
V_251:
F_145 ( V_14 , V_24 ) ;
V_250:
if ( F_241 ( V_234 ) )
F_244 () ;
return NULL ;
}
static void F_245 ( struct V_13 * V_14 , struct V_24 * V_24 )
{
struct V_1 * V_73 ;
void * V_75 = NULL ;
F_201 () ;
if ( ! V_24 )
return;
F_2 ( & V_24 -> V_134 ) ;
V_73 = F_49 ( V_14 , F_48 ( V_24 ) ) ;
F_50 ( & V_73 -> V_9 ) ;
if ( ! V_24 -> V_168 )
F_246 ( & V_24 -> V_134 , & ( V_73 -> V_5 ) ) ;
else
F_247 ( V_14 , V_73 , V_24 , & V_75 ) ;
V_73 -> V_12 ++ ;
F_248 ( V_14 ) ;
V_73 -> V_10 += V_14 -> V_36 - V_24 -> V_168 ;
F_52 ( & V_73 -> V_9 ) ;
F_249 ( V_14 , & V_75 ) ;
}
static void F_250 ( const void * V_15 )
{
if ( ! F_251 ( V_15 ) ) {
F_23 ( L_24 ,
( unsigned long ) V_15 ) ;
F_122 () ;
}
}
static inline void F_252 ( struct V_13 * V_26 , void * V_23 )
{
unsigned long long V_252 , V_253 ;
V_252 = * F_5 ( V_26 , V_23 ) ;
V_253 = * F_7 ( V_26 , V_23 ) ;
if ( V_252 == V_254 && V_253 == V_254 )
return;
if ( V_252 == V_203 && V_253 == V_203 )
F_173 ( V_26 , L_25 ) ;
else
F_173 ( V_26 , L_26 ) ;
F_23 ( L_27 ,
V_23 , V_252 , V_253 ) ;
}
static void * F_253 ( struct V_13 * V_14 , void * V_15 ,
unsigned long V_187 )
{
unsigned int V_200 ;
struct V_24 * V_24 ;
F_6 ( F_14 ( V_15 ) != V_14 ) ;
V_15 -= F_4 ( V_14 ) ;
F_250 ( V_15 ) ;
V_24 = F_15 ( V_15 ) ;
if ( V_14 -> V_16 & V_17 ) {
F_252 ( V_14 , V_15 ) ;
* F_5 ( V_14 , V_15 ) = V_203 ;
* F_7 ( V_14 , V_15 ) = V_203 ;
}
if ( V_14 -> V_16 & V_18 ) {
F_13 ( V_14 ) ;
* F_8 ( V_14 , V_15 ) = ( void * ) V_187 ;
}
V_200 = F_17 ( V_14 , V_24 , V_15 ) ;
F_6 ( V_200 >= V_14 -> V_36 ) ;
F_6 ( V_15 != F_16 ( V_14 , V_24 , V_200 ) ) ;
if ( V_14 -> V_16 & V_201 ) {
F_164 ( V_14 , V_15 , V_196 ) ;
F_162 ( V_14 , V_15 , 0 , V_187 ) ;
}
return V_15 ;
}
static inline void F_249 ( struct V_13 * V_14 ,
void * * V_75 )
{
#if V_158
void * V_255 = * V_75 ;
void * V_15 ;
while ( V_255 ) {
V_15 = V_255 - F_4 ( V_14 ) ;
V_255 = * ( void * * ) V_255 ;
F_164 ( V_14 , V_15 , V_196 ) ;
}
#endif
}
static inline void F_247 ( struct V_13 * V_14 ,
struct V_1 * V_73 , struct V_24 * V_24 ,
void * * V_75 )
{
F_178 ( & V_24 -> V_134 ) ;
if ( V_24 -> V_168 == V_14 -> V_36 ) {
F_115 ( & V_24 -> V_134 , & V_73 -> V_3 ) ;
if ( F_172 ( V_14 ) ) {
#if V_158
if ( V_14 -> V_16 & V_201 ) {
void * * V_15 = V_24 -> V_202 ;
* V_15 = * V_75 ;
* V_75 = V_15 ;
}
#endif
V_24 -> V_202 = NULL ;
}
} else
F_115 ( & V_24 -> V_134 , & V_73 -> V_4 ) ;
}
struct V_24 * F_254 ( struct V_1 * V_73 , bool V_256 )
{
struct V_24 * V_24 ;
V_24 = F_255 ( & V_73 -> V_4 ,
struct V_24 , V_134 ) ;
if ( ! V_24 ) {
V_73 -> V_11 = 1 ;
V_24 = F_255 ( & V_73 -> V_5 ,
struct V_24 , V_134 ) ;
}
if ( F_139 () )
return F_256 ( V_73 , V_24 , V_256 ) ;
return V_24 ;
}
static T_5 void * F_257 ( struct V_13 * V_14 ,
struct V_1 * V_73 , T_4 V_16 )
{
struct V_24 * V_24 ;
void * V_23 ;
void * V_75 = NULL ;
if ( ! F_258 ( V_16 ) )
return NULL ;
F_50 ( & V_73 -> V_9 ) ;
V_24 = F_254 ( V_73 , true ) ;
if ( ! V_24 ) {
F_52 ( & V_73 -> V_9 ) ;
return NULL ;
}
V_23 = F_237 ( V_14 , V_24 ) ;
V_73 -> V_10 -- ;
F_247 ( V_14 , V_73 , V_24 , & V_75 ) ;
F_52 ( & V_73 -> V_9 ) ;
F_249 ( V_14 , & V_75 ) ;
return V_23 ;
}
static T_9 int F_259 ( struct V_13 * V_14 ,
struct V_31 * V_64 , struct V_24 * V_24 , int V_68 )
{
F_6 ( V_24 -> V_168 >= V_14 -> V_36 ) ;
while ( V_24 -> V_168 < V_14 -> V_36 && V_68 -- ) {
F_260 ( V_14 ) ;
F_261 ( V_14 ) ;
F_262 ( V_14 ) ;
V_64 -> V_80 [ V_64 -> V_67 ++ ] = F_237 ( V_14 , V_24 ) ;
}
return V_68 ;
}
static void * F_263 ( struct V_13 * V_14 , T_4 V_16 )
{
int V_68 ;
struct V_1 * V_73 ;
struct V_31 * V_64 , * V_6 ;
int V_56 ;
void * V_75 = NULL ;
struct V_24 * V_24 ;
F_201 () ;
V_56 = F_80 () ;
V_64 = F_19 ( V_14 ) ;
V_68 = V_64 -> V_68 ;
if ( ! V_64 -> V_69 && V_68 > V_257 ) {
V_68 = V_257 ;
}
V_73 = F_49 ( V_14 , V_56 ) ;
F_6 ( V_64 -> V_67 > 0 || ! V_73 ) ;
V_6 = F_264 ( V_73 -> V_6 ) ;
if ( ! V_73 -> V_10 && ( ! V_6 || ! V_6 -> V_67 ) )
goto V_258;
F_50 ( & V_73 -> V_9 ) ;
V_6 = F_264 ( V_73 -> V_6 ) ;
if ( V_6 && F_54 ( V_64 , V_6 , V_68 ) ) {
V_6 -> V_69 = 1 ;
goto V_259;
}
while ( V_68 > 0 ) {
V_24 = F_254 ( V_73 , false ) ;
if ( ! V_24 )
goto V_260;
F_206 ( V_14 ) ;
V_68 = F_259 ( V_14 , V_64 , V_24 , V_68 ) ;
F_247 ( V_14 , V_73 , V_24 , & V_75 ) ;
}
V_260:
V_73 -> V_10 -= V_64 -> V_67 ;
V_259:
F_52 ( & V_73 -> V_9 ) ;
F_249 ( V_14 , & V_75 ) ;
V_258:
if ( F_77 ( ! V_64 -> V_67 ) ) {
if ( F_139 () ) {
void * V_23 = F_257 ( V_14 , V_73 , V_16 ) ;
if ( V_23 )
return V_23 ;
}
V_24 = F_240 ( V_14 , F_61 ( V_16 ) , V_56 ) ;
V_64 = F_19 ( V_14 ) ;
if ( ! V_64 -> V_67 && V_24 )
F_259 ( V_14 , V_64 , V_24 , V_68 ) ;
F_245 ( V_14 , V_24 ) ;
if ( ! V_64 -> V_67 )
return NULL ;
}
V_64 -> V_69 = 1 ;
return V_64 -> V_80 [ -- V_64 -> V_67 ] ;
}
static inline void F_265 ( struct V_13 * V_14 ,
T_4 V_16 )
{
F_266 ( F_241 ( V_16 ) ) ;
}
static void * F_267 ( struct V_13 * V_14 ,
T_4 V_16 , void * V_15 , unsigned long V_187 )
{
if ( ! V_15 )
return V_15 ;
if ( V_14 -> V_16 & V_201 ) {
F_169 ( V_14 , V_15 ) ;
F_162 ( V_14 , V_15 , 1 , 0 ) ;
F_164 ( V_14 , V_15 , V_261 ) ;
}
if ( V_14 -> V_16 & V_18 )
* F_8 ( V_14 , V_15 ) = ( void * ) V_187 ;
if ( V_14 -> V_16 & V_17 ) {
if ( * F_5 ( V_14 , V_15 ) != V_203 ||
* F_7 ( V_14 , V_15 ) != V_203 ) {
F_173 ( V_14 , L_28 ) ;
F_23 ( L_27 ,
V_15 , * F_5 ( V_14 , V_15 ) ,
* F_7 ( V_14 , V_15 ) ) ;
}
* F_5 ( V_14 , V_15 ) = V_254 ;
* F_7 ( V_14 , V_15 ) = V_254 ;
}
V_15 += F_4 ( V_14 ) ;
if ( V_14 -> V_178 && V_14 -> V_16 & V_201 )
V_14 -> V_178 ( V_15 ) ;
if ( V_262 &&
( ( unsigned long ) V_15 & ( V_262 - 1 ) ) ) {
F_23 ( L_29 ,
V_15 , ( int ) V_262 ) ;
}
return V_15 ;
}
static inline void * F_268 ( struct V_13 * V_14 , T_4 V_16 )
{
void * V_15 ;
struct V_31 * V_64 ;
F_201 () ;
V_64 = F_19 ( V_14 ) ;
if ( F_81 ( V_64 -> V_67 ) ) {
V_64 -> V_69 = 1 ;
V_15 = V_64 -> V_80 [ -- V_64 -> V_67 ] ;
F_269 ( V_14 ) ;
goto V_123;
}
F_270 ( V_14 ) ;
V_15 = F_263 ( V_14 , V_16 ) ;
V_64 = F_19 ( V_14 ) ;
V_123:
if ( V_15 )
F_271 ( & V_64 -> V_80 [ V_64 -> V_67 ] ) ;
return V_15 ;
}
static void * F_59 ( struct V_13 * V_14 , T_4 V_16 )
{
int V_263 , V_264 ;
if ( F_272 () || ( V_16 & V_91 ) )
return NULL ;
V_263 = V_264 = F_80 () ;
if ( F_273 () && ( V_14 -> V_16 & V_265 ) )
V_263 = F_274 () ;
else if ( V_182 -> V_266 )
V_263 = F_275 () ;
if ( V_263 != V_264 )
return F_60 ( V_14 , V_16 , V_263 ) ;
return NULL ;
}
static void * F_276 ( struct V_13 * V_26 , T_4 V_16 )
{
struct V_267 * V_267 ;
struct V_268 * V_269 ;
struct V_270 * V_270 ;
enum V_271 V_272 = F_277 ( V_16 ) ;
void * V_23 = NULL ;
struct V_24 * V_24 ;
int V_121 ;
unsigned int V_273 ;
if ( V_16 & V_91 )
return NULL ;
V_274:
V_273 = F_278 () ;
V_267 = F_279 ( F_275 () , V_16 ) ;
V_275:
F_280 (zone, z, zonelist, high_zoneidx) {
V_121 = F_281 ( V_270 ) ;
if ( F_282 ( V_270 , V_16 ) &&
F_49 ( V_26 , V_121 ) &&
F_49 ( V_26 , V_121 ) -> V_10 ) {
V_23 = F_60 ( V_26 ,
F_61 ( V_16 ) , V_121 ) ;
if ( V_23 )
break;
}
}
if ( ! V_23 ) {
V_24 = F_240 ( V_26 , V_16 , F_80 () ) ;
F_245 ( V_26 , V_24 ) ;
if ( V_24 ) {
V_121 = F_48 ( V_24 ) ;
V_23 = F_60 ( V_26 ,
F_61 ( V_16 ) , V_121 ) ;
if ( ! V_23 )
goto V_275;
}
}
if ( F_77 ( ! V_23 && F_283 ( V_273 ) ) )
goto V_274;
return V_23 ;
}
static void * F_60 ( struct V_13 * V_14 , T_4 V_16 ,
int V_83 )
{
struct V_24 * V_24 ;
struct V_1 * V_73 ;
void * V_23 = NULL ;
void * V_75 = NULL ;
F_284 ( V_83 < 0 || V_83 >= V_276 ) ;
V_73 = F_49 ( V_14 , V_83 ) ;
F_6 ( ! V_73 ) ;
F_201 () ;
F_50 ( & V_73 -> V_9 ) ;
V_24 = F_254 ( V_73 , false ) ;
if ( ! V_24 )
goto V_260;
F_209 ( V_14 , V_83 ) ;
F_285 ( V_14 ) ;
F_261 ( V_14 ) ;
F_262 ( V_14 ) ;
F_6 ( V_24 -> V_168 == V_14 -> V_36 ) ;
V_23 = F_237 ( V_14 , V_24 ) ;
V_73 -> V_10 -- ;
F_247 ( V_14 , V_73 , V_24 , & V_75 ) ;
F_52 ( & V_73 -> V_9 ) ;
F_249 ( V_14 , & V_75 ) ;
return V_23 ;
V_260:
F_52 ( & V_73 -> V_9 ) ;
V_24 = F_240 ( V_14 , F_61 ( V_16 ) , V_83 ) ;
if ( V_24 ) {
V_23 = F_237 ( V_14 , V_24 ) ;
}
F_245 ( V_14 , V_24 ) ;
return V_23 ? V_23 : F_276 ( V_14 , V_16 ) ;
}
static T_9 void *
F_286 ( struct V_13 * V_14 , T_4 V_16 , int V_83 ,
unsigned long V_187 )
{
unsigned long V_277 ;
void * V_130 ;
int V_278 = F_80 () ;
V_16 &= V_279 ;
V_14 = F_287 ( V_14 , V_16 ) ;
if ( F_77 ( ! V_14 ) )
return NULL ;
F_265 ( V_14 , V_16 ) ;
F_288 ( V_277 ) ;
if ( V_83 == V_280 )
V_83 = V_278 ;
if ( F_77 ( ! F_49 ( V_14 , V_83 ) ) ) {
V_130 = F_276 ( V_14 , V_16 ) ;
goto V_123;
}
if ( V_83 == V_278 ) {
V_130 = F_268 ( V_14 , V_16 ) ;
if ( V_130 )
goto V_123;
}
V_130 = F_60 ( V_14 , V_16 , V_83 ) ;
V_123:
F_289 ( V_277 ) ;
V_130 = F_267 ( V_14 , V_16 , V_130 , V_187 ) ;
if ( F_77 ( V_16 & V_281 ) && V_130 )
memset ( V_130 , 0 , V_14 -> V_188 ) ;
F_290 ( V_14 , V_16 , 1 , & V_130 ) ;
return V_130 ;
}
static T_9 void *
F_291 ( struct V_13 * V_26 , T_4 V_16 )
{
void * V_15 ;
if ( V_182 -> V_266 || F_273 () ) {
V_15 = F_59 ( V_26 , V_16 ) ;
if ( V_15 )
goto V_123;
}
V_15 = F_268 ( V_26 , V_16 ) ;
if ( ! V_15 )
V_15 = F_60 ( V_26 , V_16 , F_80 () ) ;
V_123:
return V_15 ;
}
static T_9 void *
F_291 ( struct V_13 * V_14 , T_4 V_16 )
{
return F_268 ( V_14 , V_16 ) ;
}
static T_9 void *
F_292 ( struct V_13 * V_14 , T_4 V_16 , unsigned long V_187 )
{
unsigned long V_277 ;
void * V_15 ;
V_16 &= V_279 ;
V_14 = F_287 ( V_14 , V_16 ) ;
if ( F_77 ( ! V_14 ) )
return NULL ;
F_265 ( V_14 , V_16 ) ;
F_288 ( V_277 ) ;
V_15 = F_291 ( V_14 , V_16 ) ;
F_289 ( V_277 ) ;
V_15 = F_267 ( V_14 , V_16 , V_15 , V_187 ) ;
F_293 ( V_15 ) ;
if ( F_77 ( V_16 & V_281 ) && V_15 )
memset ( V_15 , 0 , V_14 -> V_188 ) ;
F_290 ( V_14 , V_16 , 1 , & V_15 ) ;
return V_15 ;
}
static void F_51 ( struct V_13 * V_14 , void * * V_282 ,
int V_283 , int V_56 , struct V_90 * V_75 )
{
int V_89 ;
struct V_1 * V_73 = F_49 ( V_14 , V_56 ) ;
struct V_24 * V_24 ;
V_73 -> V_10 += V_283 ;
for ( V_89 = 0 ; V_89 < V_283 ; V_89 ++ ) {
void * V_15 ;
struct V_24 * V_24 ;
V_15 = V_282 [ V_89 ] ;
V_24 = F_15 ( V_15 ) ;
F_178 ( & V_24 -> V_134 ) ;
F_209 ( V_14 , V_56 ) ;
F_238 ( V_14 , V_24 , V_15 ) ;
F_294 ( V_14 ) ;
if ( V_24 -> V_168 == 0 )
F_115 ( & V_24 -> V_134 , & V_73 -> V_5 ) ;
else {
F_246 ( & V_24 -> V_134 , & V_73 -> V_4 ) ;
}
}
while ( V_73 -> V_10 > V_73 -> V_94 && ! F_103 ( & V_73 -> V_5 ) ) {
V_73 -> V_10 -= V_14 -> V_36 ;
V_24 = F_295 ( & V_73 -> V_5 , struct V_24 , V_134 ) ;
F_296 ( & V_24 -> V_134 , V_75 ) ;
V_73 -> V_12 -- ;
}
}
static void F_297 ( struct V_13 * V_14 , struct V_31 * V_64 )
{
int V_68 ;
struct V_1 * V_73 ;
int V_56 = F_80 () ;
F_47 ( V_75 ) ;
V_68 = V_64 -> V_68 ;
F_201 () ;
V_73 = F_49 ( V_14 , V_56 ) ;
F_50 ( & V_73 -> V_9 ) ;
if ( V_73 -> V_6 ) {
struct V_31 * V_284 = V_73 -> V_6 ;
int V_78 = V_284 -> V_65 - V_284 -> V_67 ;
if ( V_78 ) {
if ( V_68 > V_78 )
V_68 = V_78 ;
memcpy ( & ( V_284 -> V_80 [ V_284 -> V_67 ] ) ,
V_64 -> V_80 , sizeof( void * ) * V_68 ) ;
V_284 -> V_67 += V_68 ;
goto V_285;
}
}
F_51 ( V_14 , V_64 -> V_80 , V_68 , V_56 , & V_75 ) ;
V_285:
#if V_286
{
int V_89 = 0 ;
struct V_24 * V_24 ;
F_86 (page, &n->slabs_free, lru) {
F_6 ( V_24 -> V_168 ) ;
V_89 ++ ;
}
F_298 ( V_14 , V_89 ) ;
}
#endif
F_52 ( & V_73 -> V_9 ) ;
F_53 ( V_14 , & V_75 ) ;
V_64 -> V_67 -= V_68 ;
memmove ( V_64 -> V_80 , & ( V_64 -> V_80 [ V_68 ] ) , sizeof( void * ) * V_64 -> V_67 ) ;
}
static inline void F_299 ( struct V_13 * V_14 , void * V_15 ,
unsigned long V_187 )
{
if ( F_300 ( V_14 , V_15 ) )
return;
F_301 ( V_14 , V_15 , V_187 ) ;
}
void F_301 ( struct V_13 * V_14 , void * V_15 ,
unsigned long V_187 )
{
struct V_31 * V_64 = F_19 ( V_14 ) ;
F_201 () ;
F_302 ( V_15 , V_14 -> V_16 ) ;
V_15 = F_253 ( V_14 , V_15 , V_187 ) ;
F_303 ( V_14 , V_15 , V_14 -> V_188 ) ;
if ( V_287 > 1 && F_58 ( V_14 , V_15 ) )
return;
if ( V_64 -> V_67 < V_64 -> V_65 ) {
F_304 ( V_14 ) ;
} else {
F_305 ( V_14 ) ;
F_297 ( V_14 , V_64 ) ;
}
if ( F_139 () ) {
struct V_24 * V_24 = F_15 ( V_15 ) ;
if ( F_77 ( F_306 ( V_24 ) ) ) {
F_46 ( V_14 , V_24 , V_15 ) ;
return;
}
}
V_64 -> V_80 [ V_64 -> V_67 ++ ] = V_15 ;
}
void * F_307 ( struct V_13 * V_14 , T_4 V_16 )
{
void * V_99 = F_292 ( V_14 , V_16 , V_288 ) ;
F_308 ( V_14 , V_99 , V_16 ) ;
F_309 ( V_288 , V_99 ,
V_14 -> V_188 , V_14 -> V_19 , V_16 ) ;
return V_99 ;
}
static T_9 void
F_310 ( struct V_13 * V_47 , T_4 V_16 ,
T_2 V_19 , void * * V_231 , unsigned long V_187 )
{
T_2 V_89 ;
for ( V_89 = 0 ; V_89 < V_19 ; V_89 ++ )
V_231 [ V_89 ] = F_267 ( V_47 , V_16 , V_231 [ V_89 ] , V_187 ) ;
}
int F_311 ( struct V_13 * V_47 , T_4 V_16 , T_2 V_19 ,
void * * V_231 )
{
T_2 V_89 ;
V_47 = F_287 ( V_47 , V_16 ) ;
if ( ! V_47 )
return 0 ;
F_265 ( V_47 , V_16 ) ;
F_244 () ;
for ( V_89 = 0 ; V_89 < V_19 ; V_89 ++ ) {
void * V_15 = F_291 ( V_47 , V_16 ) ;
if ( F_77 ( ! V_15 ) )
goto error;
V_231 [ V_89 ] = V_15 ;
}
F_242 () ;
F_310 ( V_47 , V_16 , V_19 , V_231 , V_288 ) ;
if ( F_77 ( V_16 & V_281 ) )
for ( V_89 = 0 ; V_89 < V_19 ; V_89 ++ )
memset ( V_231 [ V_89 ] , 0 , V_47 -> V_188 ) ;
F_290 ( V_47 , V_16 , V_19 , V_231 ) ;
return V_19 ;
error:
F_242 () ;
F_310 ( V_47 , V_16 , V_89 , V_231 , V_288 ) ;
F_290 ( V_47 , V_16 , V_89 , V_231 ) ;
F_312 ( V_47 , V_89 , V_231 ) ;
return 0 ;
}
void *
F_313 ( struct V_13 * V_14 , T_4 V_16 , T_2 V_19 )
{
void * V_99 ;
V_99 = F_292 ( V_14 , V_16 , V_288 ) ;
F_314 ( V_14 , V_99 , V_19 , V_16 ) ;
F_315 ( V_288 , V_99 ,
V_19 , V_14 -> V_19 , V_16 ) ;
return V_99 ;
}
void * F_221 ( struct V_13 * V_14 , T_4 V_16 , int V_83 )
{
void * V_99 = F_286 ( V_14 , V_16 , V_83 , V_288 ) ;
F_308 ( V_14 , V_99 , V_16 ) ;
F_316 ( V_288 , V_99 ,
V_14 -> V_188 , V_14 -> V_19 ,
V_16 , V_83 ) ;
return V_99 ;
}
void * F_317 ( struct V_13 * V_14 ,
T_4 V_16 ,
int V_83 ,
T_2 V_19 )
{
void * V_99 ;
V_99 = F_286 ( V_14 , V_16 , V_83 , V_288 ) ;
F_314 ( V_14 , V_99 , V_19 , V_16 ) ;
F_318 ( V_288 , V_99 ,
V_19 , V_14 -> V_19 ,
V_16 , V_83 ) ;
return V_99 ;
}
static T_9 void *
F_319 ( T_2 V_19 , T_4 V_16 , int V_56 , unsigned long V_187 )
{
struct V_13 * V_14 ;
void * V_99 ;
V_14 = F_180 ( V_19 , V_16 ) ;
if ( F_77 ( F_320 ( V_14 ) ) )
return V_14 ;
V_99 = F_317 ( V_14 , V_16 , V_56 , V_19 ) ;
F_314 ( V_14 , V_99 , V_19 , V_16 ) ;
return V_99 ;
}
void * F_321 ( T_2 V_19 , T_4 V_16 , int V_56 )
{
return F_319 ( V_19 , V_16 , V_56 , V_288 ) ;
}
void * F_322 ( T_2 V_19 , T_4 V_16 ,
int V_56 , unsigned long V_187 )
{
return F_319 ( V_19 , V_16 , V_56 , V_187 ) ;
}
static T_9 void * F_323 ( T_2 V_19 , T_4 V_16 ,
unsigned long V_187 )
{
struct V_13 * V_14 ;
void * V_99 ;
V_14 = F_180 ( V_19 , V_16 ) ;
if ( F_77 ( F_320 ( V_14 ) ) )
return V_14 ;
V_99 = F_292 ( V_14 , V_16 , V_187 ) ;
F_314 ( V_14 , V_99 , V_19 , V_16 ) ;
F_315 ( V_187 , V_99 ,
V_19 , V_14 -> V_19 , V_16 ) ;
return V_99 ;
}
void * F_324 ( T_2 V_19 , T_4 V_16 )
{
return F_323 ( V_19 , V_16 , V_288 ) ;
}
void * F_325 ( T_2 V_19 , T_4 V_16 , unsigned long V_187 )
{
return F_323 ( V_19 , V_16 , V_187 ) ;
}
void F_176 ( struct V_13 * V_14 , void * V_15 )
{
unsigned long V_16 ;
V_14 = F_326 ( V_14 , V_15 ) ;
if ( ! V_14 )
return;
F_288 ( V_16 ) ;
F_327 ( V_15 , V_14 -> V_188 ) ;
if ( ! ( V_14 -> V_16 & V_289 ) )
F_328 ( V_15 , V_14 -> V_188 ) ;
F_299 ( V_14 , V_15 , V_288 ) ;
F_289 ( V_16 ) ;
F_329 ( V_288 , V_15 ) ;
}
void F_330 ( struct V_13 * V_290 , T_2 V_19 , void * * V_231 )
{
struct V_13 * V_47 ;
T_2 V_89 ;
F_244 () ;
for ( V_89 = 0 ; V_89 < V_19 ; V_89 ++ ) {
void * V_15 = V_231 [ V_89 ] ;
if ( ! V_290 )
V_47 = F_14 ( V_15 ) ;
else
V_47 = F_326 ( V_290 , V_15 ) ;
F_327 ( V_15 , V_47 -> V_188 ) ;
if ( ! ( V_47 -> V_16 & V_289 ) )
F_328 ( V_15 , V_47 -> V_188 ) ;
F_299 ( V_47 , V_15 , V_288 ) ;
}
F_242 () ;
}
void F_66 ( const void * V_15 )
{
struct V_13 * V_291 ;
unsigned long V_16 ;
F_331 ( V_288 , V_15 ) ;
if ( F_77 ( F_320 ( V_15 ) ) )
return;
F_288 ( V_16 ) ;
F_250 ( V_15 ) ;
V_291 = F_14 ( V_15 ) ;
F_327 ( V_15 , V_291 -> V_188 ) ;
F_328 ( V_15 , V_291 -> V_188 ) ;
F_299 ( V_291 , ( void * ) V_15 , V_288 ) ;
F_289 ( V_16 ) ;
}
static int F_332 ( struct V_13 * V_14 , T_4 V_71 )
{
int V_99 ;
int V_56 ;
struct V_1 * V_73 ;
F_72 (node) {
V_99 = F_87 ( V_14 , V_56 , V_71 , true ) ;
if ( V_99 )
goto V_105;
}
return 0 ;
V_105:
if ( ! V_14 -> V_75 . V_255 ) {
V_56 -- ;
while ( V_56 >= 0 ) {
V_73 = F_49 ( V_14 , V_56 ) ;
if ( V_73 ) {
F_66 ( V_73 -> V_6 ) ;
F_57 ( V_73 -> V_7 ) ;
F_66 ( V_73 ) ;
V_14 -> V_56 [ V_56 ] = NULL ;
}
V_56 -- ;
}
}
return - V_95 ;
}
static int F_333 ( struct V_13 * V_14 , int V_65 ,
int V_68 , int V_6 , T_4 V_71 )
{
struct V_31 T_7 * V_32 , * V_232 ;
int V_53 ;
V_32 = F_181 ( V_14 , V_65 , V_68 ) ;
if ( ! V_32 )
return - V_95 ;
V_232 = V_14 -> V_32 ;
V_14 -> V_32 = V_32 ;
F_334 () ;
F_203 () ;
V_14 -> V_68 = V_68 ;
V_14 -> V_65 = V_65 ;
V_14 -> V_6 = V_6 ;
if ( ! V_232 )
goto V_292;
F_335 (cpu) {
F_47 ( V_75 ) ;
int V_56 ;
struct V_1 * V_73 ;
struct V_31 * V_64 = F_91 ( V_232 , V_53 ) ;
V_56 = F_33 ( V_53 ) ;
V_73 = F_49 ( V_14 , V_56 ) ;
F_83 ( & V_73 -> V_9 ) ;
F_51 ( V_14 , V_64 -> V_80 , V_64 -> V_67 , V_56 , & V_75 ) ;
F_70 ( & V_73 -> V_9 ) ;
F_53 ( V_14 , & V_75 ) ;
}
F_218 ( V_232 ) ;
V_292:
return F_332 ( V_14 , V_71 ) ;
}
static int F_336 ( struct V_13 * V_14 , int V_65 ,
int V_68 , int V_6 , T_4 V_71 )
{
int V_99 ;
struct V_13 * V_291 ;
V_99 = F_333 ( V_14 , V_65 , V_68 , V_6 , V_71 ) ;
if ( V_144 < V_154 )
return V_99 ;
if ( ( V_99 < 0 ) || ! F_337 ( V_14 ) )
return V_99 ;
F_338 ( & V_113 ) ;
F_339 (c, cachep) {
F_333 ( V_291 , V_65 , V_68 , V_6 , V_71 ) ;
}
return V_99 ;
}
static int F_121 ( struct V_13 * V_14 , T_4 V_71 )
{
int V_111 ;
int V_65 = 0 ;
int V_6 = 0 ;
int V_68 = 0 ;
V_111 = F_340 ( V_14 , V_14 -> V_36 , V_71 ) ;
if ( V_111 )
goto V_293;
if ( ! F_337 ( V_14 ) ) {
struct V_13 * V_294 = F_341 ( V_14 ) ;
V_65 = V_294 -> V_65 ;
V_6 = V_294 -> V_6 ;
V_68 = V_294 -> V_68 ;
}
if ( V_65 && V_6 && V_68 )
goto V_295;
if ( V_14 -> V_19 > 131072 )
V_65 = 1 ;
else if ( V_14 -> V_19 > V_38 )
V_65 = 8 ;
else if ( V_14 -> V_19 > 1024 )
V_65 = 24 ;
else if ( V_14 -> V_19 > 256 )
V_65 = 54 ;
else
V_65 = 120 ;
V_6 = 0 ;
if ( V_14 -> V_19 <= V_38 && F_342 () > 1 )
V_6 = 8 ;
#if V_158
if ( V_65 > 32 )
V_65 = 32 ;
#endif
V_68 = ( V_65 + 1 ) / 2 ;
V_295:
V_111 = F_336 ( V_14 , V_65 , V_68 , V_6 , V_71 ) ;
V_293:
if ( V_111 )
F_23 ( L_30 ,
V_14 -> V_44 , - V_111 ) ;
return V_111 ;
}
static void F_343 ( struct V_13 * V_14 , struct V_1 * V_73 ,
struct V_31 * V_64 , int V_56 )
{
F_47 ( V_75 ) ;
F_204 () ;
if ( ! V_64 || ! V_64 -> V_67 )
return;
if ( V_64 -> V_69 ) {
V_64 -> V_69 = 0 ;
return;
}
F_83 ( & V_73 -> V_9 ) ;
F_210 ( V_14 , V_64 , V_56 , false , & V_75 ) ;
F_70 ( & V_73 -> V_9 ) ;
F_53 ( V_14 , & V_75 ) ;
}
static void V_62 ( struct V_296 * V_297 )
{
struct V_13 * V_298 ;
struct V_1 * V_73 ;
int V_56 = F_80 () ;
struct V_57 * V_60 = F_344 ( V_297 ) ;
if ( ! F_345 ( & V_113 ) )
goto V_123;
F_86 (searchp, &slab_caches, list) {
F_203 () ;
V_73 = F_49 ( V_298 , V_56 ) ;
F_68 ( V_298 , V_73 ) ;
F_343 ( V_298 , V_73 , F_19 ( V_298 ) , V_56 ) ;
if ( F_346 ( V_73 -> V_96 , V_97 ) )
goto V_255;
V_73 -> V_96 = V_97 + V_98 ;
F_343 ( V_298 , V_73 , V_73 -> V_6 , V_56 ) ;
if ( V_73 -> V_11 )
V_73 -> V_11 = 0 ;
else {
int V_299 ;
V_299 = F_93 ( V_298 , V_73 , ( V_73 -> V_94 +
5 * V_298 -> V_36 - 1 ) / ( 5 * V_298 -> V_36 ) ) ;
F_347 ( V_298 , V_299 ) ;
}
V_255:
F_348 () ;
}
F_203 () ;
F_97 ( & V_113 ) ;
F_34 () ;
V_123:
F_349 ( V_60 , F_350 ( V_300 ) ) ;
}
void F_351 ( struct V_13 * V_14 , struct V_301 * V_302 )
{
struct V_24 * V_24 ;
unsigned long V_162 ;
unsigned long V_163 ;
unsigned long V_164 = 0 ;
unsigned long V_12 , V_10 = 0 , V_303 = 0 ;
unsigned long V_165 = 0 , V_166 = 0 ;
unsigned long V_167 = 0 ;
const char * V_44 ;
char * error = NULL ;
int V_56 ;
struct V_1 * V_73 ;
V_162 = 0 ;
V_12 = 0 ;
F_131 (cachep, node, n) {
F_203 () ;
F_83 ( & V_73 -> V_9 ) ;
V_12 += V_73 -> V_12 ;
F_86 (page, &n->slabs_partial, lru) {
if ( V_24 -> V_168 == V_14 -> V_36 && ! error )
error = L_31 ;
if ( ! V_24 -> V_168 && ! error )
error = L_31 ;
V_162 += V_24 -> V_168 ;
V_165 ++ ;
}
F_86 (page, &n->slabs_free, lru) {
if ( V_24 -> V_168 && ! error )
error = L_32 ;
V_166 ++ ;
}
V_10 += V_73 -> V_10 ;
if ( V_73 -> V_6 )
V_303 += V_73 -> V_6 -> V_67 ;
F_70 ( & V_73 -> V_9 ) ;
}
V_163 = V_12 * V_14 -> V_36 ;
V_164 = V_12 - V_166 ;
V_167 = V_12 - ( V_165 + V_166 ) ;
V_162 += ( V_167 * V_14 -> V_36 ) ;
if ( V_163 - V_162 != V_10 && ! error )
error = L_33 ;
V_44 = V_14 -> V_44 ;
if ( error )
F_23 ( L_34 , V_44 , error ) ;
V_302 -> V_162 = V_162 ;
V_302 -> V_163 = V_163 ;
V_302 -> V_164 = V_164 ;
V_302 -> V_12 = V_12 ;
V_302 -> V_303 = V_303 ;
V_302 -> V_65 = V_14 -> V_65 ;
V_302 -> V_68 = V_14 -> V_68 ;
V_302 -> V_6 = V_14 -> V_6 ;
V_302 -> V_304 = V_14 -> V_36 ;
V_302 -> V_305 = V_14 -> V_33 ;
}
void F_352 ( struct V_306 * V_307 , struct V_13 * V_14 )
{
#if V_286
{
unsigned long V_308 = V_14 -> V_309 ;
unsigned long V_310 = V_14 -> V_311 ;
unsigned long V_312 = V_14 -> V_312 ;
unsigned long V_313 = V_14 -> V_313 ;
unsigned long V_314 = V_14 -> V_314 ;
unsigned long V_315 = V_14 -> V_315 ;
unsigned long V_316 = V_14 -> V_316 ;
unsigned long V_317 = V_14 -> V_317 ;
unsigned long V_318 = V_14 -> V_319 ;
F_353 ( V_307 , L_35 ,
V_310 , V_308 , V_312 ,
V_313 , V_314 , V_315 , V_316 ,
V_317 , V_318 ) ;
}
{
unsigned long V_320 = F_10 ( & V_14 -> V_320 ) ;
unsigned long V_321 = F_10 ( & V_14 -> V_321 ) ;
unsigned long V_322 = F_10 ( & V_14 -> V_322 ) ;
unsigned long V_323 = F_10 ( & V_14 -> V_323 ) ;
F_353 ( V_307 , L_36 ,
V_320 , V_321 , V_322 , V_323 ) ;
}
#endif
}
T_10 F_354 ( struct V_324 * V_324 , const char T_11 * V_325 ,
T_2 V_237 , T_12 * V_326 )
{
char V_327 [ V_328 + 1 ] , * V_329 ;
int V_65 , V_68 , V_6 , V_330 ;
struct V_13 * V_14 ;
if ( V_237 > V_328 )
return - V_331 ;
if ( F_355 ( & V_327 , V_325 , V_237 ) )
return - V_332 ;
V_327 [ V_328 ] = '\0' ;
V_329 = strchr ( V_327 , ' ' ) ;
if ( ! V_329 )
return - V_331 ;
* V_329 = '\0' ;
V_329 ++ ;
if ( sscanf ( V_329 , L_37 , & V_65 , & V_68 , & V_6 ) != 3 )
return - V_331 ;
F_96 ( & V_113 ) ;
V_330 = - V_331 ;
F_86 (cachep, &slab_caches, list) {
if ( ! strcmp ( V_14 -> V_44 , V_327 ) ) {
if ( V_65 < 1 || V_68 < 1 ||
V_68 > V_65 || V_6 < 0 ) {
V_330 = 0 ;
} else {
V_330 = F_336 ( V_14 , V_65 ,
V_68 , V_6 ,
V_100 ) ;
}
break;
}
}
F_97 ( & V_113 ) ;
if ( V_330 >= 0 )
V_330 = V_237 ;
return V_330 ;
}
static inline int F_356 ( unsigned long * V_73 , unsigned long V_333 )
{
unsigned long * V_231 ;
int V_334 ;
if ( ! V_333 )
return 1 ;
V_334 = V_73 [ 1 ] ;
V_231 = V_73 + 2 ;
while ( V_334 ) {
int V_89 = V_334 / 2 ;
unsigned long * V_335 = V_231 + 2 * V_89 ;
if ( * V_335 == V_333 ) {
V_335 [ 1 ] ++ ;
return 1 ;
}
if ( * V_335 > V_333 ) {
V_334 = V_89 ;
} else {
V_231 = V_335 + 2 ;
V_334 -= V_89 + 1 ;
}
}
if ( ++ V_73 [ 1 ] == V_73 [ 0 ] )
return 0 ;
memmove ( V_231 + 2 , V_231 , V_73 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_231 - ( void * ) V_73 ) ) ;
V_231 [ 0 ] = V_333 ;
V_231 [ 1 ] = 1 ;
return 1 ;
}
static void F_357 ( unsigned long * V_73 , struct V_13 * V_291 ,
struct V_24 * V_24 )
{
void * V_231 ;
int V_89 , V_336 ;
unsigned long V_333 ;
if ( V_73 [ 0 ] == V_73 [ 1 ] )
return;
for ( V_89 = 0 , V_231 = V_24 -> V_28 ; V_89 < V_291 -> V_36 ; V_89 ++ , V_231 += V_291 -> V_19 ) {
bool V_168 = true ;
for ( V_336 = V_24 -> V_168 ; V_336 < V_291 -> V_36 ; V_336 ++ ) {
if ( F_222 ( V_24 , V_336 ) == V_89 ) {
V_168 = false ;
break;
}
}
if ( ! V_168 )
continue;
if ( F_358 ( & V_333 , F_8 ( V_291 , V_231 ) , sizeof( V_333 ) ) )
continue;
if ( ! F_356 ( V_73 , V_333 ) )
return;
}
}
static void F_359 ( struct V_306 * V_307 , unsigned long V_337 )
{
#ifdef F_360
unsigned long V_29 , V_19 ;
char V_338 [ V_339 ] , V_44 [ V_340 ] ;
if ( F_361 ( V_337 , & V_19 , & V_29 , V_338 , V_44 ) == 0 ) {
F_353 ( V_307 , L_38 , V_44 , V_29 , V_19 ) ;
if ( V_338 [ 0 ] )
F_353 ( V_307 , L_39 , V_338 ) ;
return;
}
#endif
F_353 ( V_307 , L_40 , ( void * ) V_337 ) ;
}
static int F_362 ( struct V_306 * V_307 , void * V_231 )
{
struct V_13 * V_14 = F_214 ( V_231 , struct V_13 , V_75 ) ;
struct V_24 * V_24 ;
struct V_1 * V_73 ;
const char * V_44 ;
unsigned long * V_341 = V_307 -> V_342 ;
int V_56 ;
int V_89 ;
if ( ! ( V_14 -> V_16 & V_18 ) )
return 0 ;
if ( ! ( V_14 -> V_16 & V_17 ) )
return 0 ;
do {
F_11 ( V_14 ) ;
F_212 ( V_14 ) ;
V_341 [ 1 ] = 0 ;
F_131 (cachep, node, n) {
F_203 () ;
F_83 ( & V_73 -> V_9 ) ;
F_86 (page, &n->slabs_full, lru)
F_357 ( V_341 , V_14 , V_24 ) ;
F_86 (page, &n->slabs_partial, lru)
F_357 ( V_341 , V_14 , V_24 ) ;
F_70 ( & V_73 -> V_9 ) ;
}
} while ( ! F_9 ( V_14 ) );
V_44 = V_14 -> V_44 ;
if ( V_341 [ 0 ] == V_341 [ 1 ] ) {
F_97 ( & V_113 ) ;
V_307 -> V_342 = F_363 ( V_341 [ 0 ] * 4 * sizeof( unsigned long ) , V_100 ) ;
if ( ! V_307 -> V_342 ) {
V_307 -> V_342 = V_341 ;
F_96 ( & V_113 ) ;
return - V_95 ;
}
* ( unsigned long * ) V_307 -> V_342 = V_341 [ 0 ] * 2 ;
F_66 ( V_341 ) ;
F_96 ( & V_113 ) ;
V_307 -> V_237 = V_307 -> V_19 ;
return 0 ;
}
for ( V_89 = 0 ; V_89 < V_341 [ 1 ] ; V_89 ++ ) {
F_353 ( V_307 , L_41 , V_44 , V_341 [ 2 * V_89 + 3 ] ) ;
F_359 ( V_307 , V_341 [ 2 * V_89 + 2 ] ) ;
F_364 ( V_307 , '\n' ) ;
}
return 0 ;
}
static int F_365 ( struct V_343 * V_343 , struct V_324 * V_324 )
{
unsigned long * V_73 ;
V_73 = F_366 ( V_324 , & V_344 , V_38 ) ;
if ( ! V_73 )
return - V_95 ;
* V_73 = V_38 / ( 2 * sizeof( unsigned long ) ) ;
return 0 ;
}
static int T_3 F_367 ( void )
{
#ifdef F_368
F_369 ( L_42 , 0 , NULL , & V_345 ) ;
#endif
return 0 ;
}
const char * F_370 ( const void * V_130 , unsigned long V_73 ,
struct V_24 * V_24 )
{
struct V_13 * V_14 ;
unsigned int V_200 ;
unsigned long V_29 ;
V_14 = V_24 -> V_25 ;
V_200 = F_17 ( V_14 , V_24 , ( void * ) V_130 ) ;
F_6 ( V_200 >= V_14 -> V_36 ) ;
V_29 = V_130 - F_16 ( V_14 , V_24 , V_200 ) - F_4 ( V_14 ) ;
if ( V_29 <= V_14 -> V_188 && V_73 <= V_14 -> V_188 - V_29 )
return NULL ;
return V_14 -> V_44 ;
}
T_2 F_371 ( const void * V_15 )
{
T_2 V_19 ;
F_6 ( ! V_15 ) ;
if ( F_77 ( V_15 == V_346 ) )
return 0 ;
V_19 = F_14 ( V_15 ) -> V_188 ;
F_372 ( V_15 , V_19 ) ;
return V_19 ;
}
