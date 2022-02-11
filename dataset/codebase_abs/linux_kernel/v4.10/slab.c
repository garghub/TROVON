static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_2 ( & V_2 -> V_4 ) ;
F_2 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = 0 ;
V_2 -> V_8 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_10 = 0 ;
F_3 ( & V_2 -> V_11 ) ;
V_2 -> V_12 = 0 ;
V_2 -> V_13 = 0 ;
}
static int F_4 ( struct V_14 * V_15 )
{
return V_15 -> F_4 ;
}
static unsigned long long * F_5 ( struct V_14 * V_15 , void * V_16 )
{
F_6 ( ! ( V_15 -> V_17 & V_18 ) ) ;
return ( unsigned long long * ) ( V_16 + F_4 ( V_15 ) -
sizeof( unsigned long long ) ) ;
}
static unsigned long long * F_7 ( struct V_14 * V_15 , void * V_16 )
{
F_6 ( ! ( V_15 -> V_17 & V_18 ) ) ;
if ( V_15 -> V_17 & V_19 )
return ( unsigned long long * ) ( V_16 + V_15 -> V_20 -
sizeof( unsigned long long ) -
V_21 ) ;
return ( unsigned long long * ) ( V_16 + V_15 -> V_20 -
sizeof( unsigned long long ) ) ;
}
static void * * F_8 ( struct V_14 * V_15 , void * V_16 )
{
F_6 ( ! ( V_15 -> V_17 & V_19 ) ) ;
return ( void * * ) ( V_16 + V_15 -> V_20 - V_22 ) ;
}
static inline bool F_9 ( struct V_14 * V_15 )
{
return F_10 ( & V_15 -> V_23 ) == 1 ;
}
static inline void F_11 ( struct V_14 * V_15 )
{
F_12 ( & V_15 -> V_23 , 1 ) ;
}
static inline void F_13 ( struct V_14 * V_15 )
{
if ( F_9 ( V_15 ) )
F_12 ( & V_15 -> V_23 , 0 ) ;
}
static inline void F_13 ( struct V_14 * V_15 ) {}
static inline struct V_14 * F_14 ( const void * V_24 )
{
struct V_25 * V_25 = F_15 ( V_24 ) ;
return V_25 -> V_26 ;
}
static inline void * F_16 ( struct V_14 * V_27 , struct V_25 * V_25 ,
unsigned int V_28 )
{
return V_25 -> V_29 + V_27 -> V_20 * V_28 ;
}
static inline unsigned int F_17 ( const struct V_14 * V_27 ,
const struct V_25 * V_25 , void * V_24 )
{
T_1 V_30 = ( V_24 - V_25 -> V_29 ) ;
return F_18 ( V_30 , V_27 -> V_31 ) ;
}
static inline struct V_32 * F_19 ( struct V_14 * V_15 )
{
return F_20 ( V_15 -> V_33 ) ;
}
static unsigned int F_21 ( unsigned long V_34 , T_2 V_35 ,
unsigned long V_17 , T_2 * V_36 )
{
unsigned int V_37 ;
T_2 V_38 = V_39 << V_34 ;
if ( V_17 & ( V_40 | V_41 ) ) {
V_37 = V_38 / V_35 ;
* V_36 = V_38 % V_35 ;
} else {
V_37 = V_38 / ( V_35 + sizeof( V_42 ) ) ;
* V_36 = V_38 %
( V_35 + sizeof( V_42 ) ) ;
}
return V_37 ;
}
static void F_22 ( const char * V_43 , struct V_14 * V_15 ,
char * V_44 )
{
F_23 ( L_1 ,
V_43 , V_15 -> V_45 , V_44 ) ;
F_24 () ;
F_25 ( V_46 , V_47 ) ;
}
static int T_3 F_26 ( char * V_48 )
{
V_49 = 0 ;
return 1 ;
}
static int T_3 F_27 ( char * V_50 )
{
F_28 ( & V_50 , & V_51 ) ;
V_51 = V_51 < 0 ? 0 :
F_29 ( V_51 , V_52 - 1 ) ;
V_53 = true ;
return 1 ;
}
static void F_30 ( int V_54 )
{
F_31 ( V_55 , V_54 ) = F_32 ( F_33 ( V_54 ) ,
V_56 ) ;
}
static void F_34 ( void )
{
int V_57 = F_35 ( V_55 ) ;
V_57 = F_32 ( V_57 , V_56 ) ;
F_36 ( V_55 , V_57 ) ;
}
static void F_37 ( int V_54 )
{
struct V_58 * V_59 = & F_31 ( V_60 , V_54 ) ;
if ( V_59 -> V_61 . V_62 == NULL ) {
F_30 ( V_54 ) ;
F_38 ( V_59 , V_63 ) ;
F_39 ( V_54 , V_59 ,
F_40 ( V_64 , V_54 ) ) ;
}
}
static void F_41 ( struct V_32 * V_65 , int V_66 , int V_67 )
{
F_42 ( V_65 ) ;
if ( V_65 ) {
V_65 -> V_68 = 0 ;
V_65 -> V_66 = V_66 ;
V_65 -> V_69 = V_67 ;
V_65 -> V_70 = 0 ;
}
}
static struct V_32 * F_43 ( int V_57 , int V_71 ,
int V_69 , T_4 V_72 )
{
T_2 V_73 = sizeof( void * ) * V_71 + sizeof( struct V_32 ) ;
struct V_32 * V_65 = NULL ;
V_65 = F_44 ( V_73 , V_72 , V_57 ) ;
F_41 ( V_65 , V_71 , V_69 ) ;
return V_65 ;
}
static T_5 void F_45 ( struct V_14 * V_15 ,
struct V_25 * V_25 , void * V_16 )
{
struct V_1 * V_74 ;
int V_75 ;
F_46 ( V_76 ) ;
V_75 = F_47 ( V_25 ) ;
V_74 = F_48 ( V_15 , V_75 ) ;
F_49 ( & V_74 -> V_11 ) ;
F_50 ( V_15 , & V_16 , 1 , V_75 , & V_76 ) ;
F_51 ( & V_74 -> V_11 ) ;
F_52 ( V_15 , & V_76 ) ;
}
static int F_53 ( struct V_32 * V_77 ,
struct V_32 * V_78 , unsigned int V_79 )
{
int V_80 = F_54 ( V_78 -> V_68 , V_79 , V_77 -> V_66 - V_77 -> V_68 ) ;
if ( ! V_80 )
return 0 ;
memcpy ( V_77 -> V_81 + V_77 -> V_68 , V_78 -> V_81 + V_78 -> V_68 - V_80 ,
sizeof( void * ) * V_80 ) ;
V_78 -> V_68 -= V_80 ;
V_77 -> V_68 += V_80 ;
return V_80 ;
}
static inline struct V_82 * * F_55 ( int V_57 ,
int V_66 , T_4 V_72 )
{
return NULL ;
}
static inline void F_56 ( struct V_82 * * V_83 )
{
}
static inline int F_57 ( struct V_14 * V_15 , void * V_16 )
{
return 0 ;
}
static inline void * F_58 ( struct V_14 * V_15 ,
T_4 V_17 )
{
return NULL ;
}
static inline void * F_59 ( struct V_14 * V_15 ,
T_4 V_17 , int V_84 )
{
return NULL ;
}
static inline T_4 F_60 ( T_4 V_17 )
{
return V_17 & ~ V_85 ;
}
static struct V_82 * F_61 ( int V_57 , int V_71 ,
int V_67 , T_4 V_72 )
{
T_2 V_73 = sizeof( void * ) * V_71 + sizeof( struct V_82 ) ;
struct V_82 * V_86 = NULL ;
V_86 = F_44 ( V_73 , V_72 , V_57 ) ;
F_41 ( & V_86 -> V_65 , V_71 , V_67 ) ;
F_3 ( & V_86 -> V_87 ) ;
return V_86 ;
}
static struct V_82 * * F_55 ( int V_57 , int V_66 , T_4 V_72 )
{
struct V_82 * * V_88 ;
T_2 V_73 = sizeof( void * ) * V_89 ;
int V_90 ;
if ( V_66 > 1 )
V_66 = 12 ;
V_88 = F_62 ( V_73 , V_72 , V_57 ) ;
if ( ! V_88 )
return NULL ;
F_63 (i) {
if ( V_90 == V_57 || ! F_64 ( V_90 ) )
continue;
V_88 [ V_90 ] = F_61 ( V_57 , V_66 , 0xbaadf00d , V_72 ) ;
if ( ! V_88 [ V_90 ] ) {
for ( V_90 -- ; V_90 >= 0 ; V_90 -- )
F_65 ( V_88 [ V_90 ] ) ;
F_65 ( V_88 ) ;
return NULL ;
}
}
return V_88 ;
}
static void F_56 ( struct V_82 * * V_88 )
{
int V_90 ;
if ( ! V_88 )
return;
F_63 (i)
F_65 ( V_88 [ V_90 ] ) ;
F_65 ( V_88 ) ;
}
static void F_66 ( struct V_14 * V_15 ,
struct V_32 * V_65 , int V_57 ,
struct V_91 * V_76 )
{
struct V_1 * V_74 = F_48 ( V_15 , V_57 ) ;
if ( V_65 -> V_68 ) {
F_49 ( & V_74 -> V_11 ) ;
if ( V_74 -> V_8 )
F_53 ( V_74 -> V_8 , V_65 , V_65 -> V_66 ) ;
F_50 ( V_15 , V_65 -> V_81 , V_65 -> V_68 , V_57 , V_76 ) ;
V_65 -> V_68 = 0 ;
F_51 ( & V_74 -> V_11 ) ;
}
}
static void F_67 ( struct V_14 * V_15 , struct V_1 * V_74 )
{
int V_57 = F_35 ( V_55 ) ;
if ( V_74 -> V_9 ) {
struct V_82 * V_86 = V_74 -> V_9 [ V_57 ] ;
struct V_32 * V_65 ;
if ( V_86 ) {
V_65 = & V_86 -> V_65 ;
if ( V_65 -> V_68 && F_68 ( & V_86 -> V_87 ) ) {
F_46 ( V_76 ) ;
F_66 ( V_15 , V_65 , V_57 , & V_76 ) ;
F_69 ( & V_86 -> V_87 ) ;
F_52 ( V_15 , & V_76 ) ;
}
}
}
}
static void F_70 ( struct V_14 * V_15 ,
struct V_82 * * V_9 )
{
int V_90 = 0 ;
struct V_82 * V_86 ;
struct V_32 * V_65 ;
unsigned long V_17 ;
F_71 (i) {
V_86 = V_9 [ V_90 ] ;
if ( V_86 ) {
F_46 ( V_76 ) ;
V_65 = & V_86 -> V_65 ;
F_72 ( & V_86 -> V_87 , V_17 ) ;
F_66 ( V_15 , V_65 , V_90 , & V_76 ) ;
F_73 ( & V_86 -> V_87 , V_17 ) ;
F_52 ( V_15 , & V_76 ) ;
}
}
}
static int F_74 ( struct V_14 * V_15 , void * V_16 ,
int V_57 , int V_75 )
{
struct V_1 * V_74 ;
struct V_82 * V_9 = NULL ;
struct V_32 * V_65 ;
F_46 ( V_76 ) ;
V_74 = F_48 ( V_15 , V_57 ) ;
F_75 ( V_15 ) ;
if ( V_74 -> V_9 && V_74 -> V_9 [ V_75 ] ) {
V_9 = V_74 -> V_9 [ V_75 ] ;
V_65 = & V_9 -> V_65 ;
F_49 ( & V_9 -> V_87 ) ;
if ( F_76 ( V_65 -> V_68 == V_65 -> V_66 ) ) {
F_77 ( V_15 ) ;
F_66 ( V_15 , V_65 , V_75 , & V_76 ) ;
}
V_65 -> V_81 [ V_65 -> V_68 ++ ] = V_16 ;
F_51 ( & V_9 -> V_87 ) ;
F_52 ( V_15 , & V_76 ) ;
} else {
V_74 = F_48 ( V_15 , V_75 ) ;
F_49 ( & V_74 -> V_11 ) ;
F_50 ( V_15 , & V_16 , 1 , V_75 , & V_76 ) ;
F_51 ( & V_74 -> V_11 ) ;
F_52 ( V_15 , & V_76 ) ;
}
return 1 ;
}
static inline int F_57 ( struct V_14 * V_15 , void * V_16 )
{
int V_75 = F_47 ( F_78 ( V_16 ) ) ;
int V_57 = F_79 () ;
if ( F_80 ( V_57 == V_75 ) )
return 0 ;
return F_74 ( V_15 , V_16 , V_57 , V_75 ) ;
}
static inline T_4 F_60 ( T_4 V_17 )
{
return ( V_17 | V_92 | V_93 ) & ~ ( V_94 | V_85 ) ;
}
static int F_81 ( struct V_14 * V_15 , int V_57 , T_4 V_72 )
{
struct V_1 * V_74 ;
V_74 = F_48 ( V_15 , V_57 ) ;
if ( V_74 ) {
F_82 ( & V_74 -> V_11 ) ;
V_74 -> V_95 = ( 1 + F_83 ( V_57 ) ) * V_15 -> V_69 +
V_15 -> V_37 ;
F_69 ( & V_74 -> V_11 ) ;
return 0 ;
}
V_74 = F_44 ( sizeof( struct V_1 ) , V_72 , V_57 ) ;
if ( ! V_74 )
return - V_96 ;
F_1 ( V_74 ) ;
V_74 -> V_97 = V_98 + V_99 +
( ( unsigned long ) V_15 ) % V_99 ;
V_74 -> V_95 =
( 1 + F_83 ( V_57 ) ) * V_15 -> V_69 + V_15 -> V_37 ;
V_15 -> V_57 [ V_57 ] = V_74 ;
return 0 ;
}
static int F_84 ( int V_57 )
{
int V_100 ;
struct V_14 * V_15 ;
F_85 (cachep, &slab_caches, list) {
V_100 = F_81 ( V_15 , V_57 , V_101 ) ;
if ( V_100 )
return V_100 ;
}
return 0 ;
}
static int F_86 ( struct V_14 * V_15 ,
int V_57 , T_4 V_72 , bool V_102 )
{
int V_100 = - V_96 ;
struct V_1 * V_74 ;
struct V_32 * V_103 = NULL ;
struct V_32 * V_104 = NULL ;
struct V_82 * * V_105 = NULL ;
F_46 ( V_76 ) ;
if ( V_49 ) {
V_105 = F_55 ( V_57 , V_15 -> V_66 , V_72 ) ;
if ( ! V_105 )
goto V_106;
}
if ( V_15 -> V_8 ) {
V_104 = F_43 ( V_57 ,
V_15 -> V_8 * V_15 -> V_69 , 0xbaadf00d , V_72 ) ;
if ( ! V_104 )
goto V_106;
}
V_100 = F_81 ( V_15 , V_57 , V_72 ) ;
if ( V_100 )
goto V_106;
V_74 = F_48 ( V_15 , V_57 ) ;
F_82 ( & V_74 -> V_11 ) ;
if ( V_74 -> V_8 && V_102 ) {
F_50 ( V_15 , V_74 -> V_8 -> V_81 ,
V_74 -> V_8 -> V_68 , V_57 , & V_76 ) ;
V_74 -> V_8 -> V_68 = 0 ;
}
if ( ! V_74 -> V_8 || V_102 ) {
V_103 = V_74 -> V_8 ;
V_74 -> V_8 = V_104 ;
V_104 = NULL ;
}
if ( ! V_74 -> V_9 ) {
V_74 -> V_9 = V_105 ;
V_105 = NULL ;
}
F_69 ( & V_74 -> V_11 ) ;
F_52 ( V_15 , & V_76 ) ;
if ( V_103 && V_102 )
F_87 () ;
V_106:
F_65 ( V_103 ) ;
F_65 ( V_104 ) ;
F_56 ( V_105 ) ;
return V_100 ;
}
static void F_88 ( long V_54 )
{
struct V_14 * V_15 ;
struct V_1 * V_74 = NULL ;
int V_57 = F_33 ( V_54 ) ;
const struct V_107 * V_108 = F_89 ( V_57 ) ;
F_85 (cachep, &slab_caches, list) {
struct V_32 * V_109 ;
struct V_32 * V_8 ;
struct V_82 * * V_9 ;
F_46 ( V_76 ) ;
V_74 = F_48 ( V_15 , V_57 ) ;
if ( ! V_74 )
continue;
F_82 ( & V_74 -> V_11 ) ;
V_74 -> V_95 -= V_15 -> V_69 ;
V_109 = F_90 ( V_15 -> V_33 , V_54 ) ;
if ( V_109 ) {
F_50 ( V_15 , V_109 -> V_81 , V_109 -> V_68 , V_57 , & V_76 ) ;
V_109 -> V_68 = 0 ;
}
if ( ! F_91 ( V_108 ) ) {
F_69 ( & V_74 -> V_11 ) ;
goto V_110;
}
V_8 = V_74 -> V_8 ;
if ( V_8 ) {
F_50 ( V_15 , V_8 -> V_81 ,
V_8 -> V_68 , V_57 , & V_76 ) ;
V_74 -> V_8 = NULL ;
}
V_9 = V_74 -> V_9 ;
V_74 -> V_9 = NULL ;
F_69 ( & V_74 -> V_11 ) ;
F_65 ( V_8 ) ;
if ( V_9 ) {
F_70 ( V_15 , V_9 ) ;
F_56 ( V_9 ) ;
}
V_110:
F_52 ( V_15 , & V_76 ) ;
}
F_85 (cachep, &slab_caches, list) {
V_74 = F_48 ( V_15 , V_57 ) ;
if ( ! V_74 )
continue;
F_92 ( V_15 , V_74 , V_111 ) ;
}
}
static int F_93 ( long V_54 )
{
struct V_14 * V_15 ;
int V_57 = F_33 ( V_54 ) ;
int V_112 ;
V_112 = F_84 ( V_57 ) ;
if ( V_112 < 0 )
goto V_113;
F_85 (cachep, &slab_caches, list) {
V_112 = F_86 ( V_15 , V_57 , V_101 , false ) ;
if ( V_112 )
goto V_113;
}
return 0 ;
V_113:
F_88 ( V_54 ) ;
return - V_96 ;
}
int F_94 ( unsigned int V_54 )
{
int V_112 ;
F_95 ( & V_114 ) ;
V_112 = F_93 ( V_54 ) ;
F_96 ( & V_114 ) ;
return V_112 ;
}
int F_97 ( unsigned int V_54 )
{
F_95 ( & V_114 ) ;
F_88 ( V_54 ) ;
F_96 ( & V_114 ) ;
return 0 ;
}
static int F_98 ( unsigned int V_54 )
{
F_37 ( V_54 ) ;
return 0 ;
}
static int F_99 ( unsigned int V_54 )
{
F_100 ( & F_31 ( V_60 , V_54 ) ) ;
F_31 ( V_60 , V_54 ) . V_61 . V_62 = NULL ;
return 0 ;
}
static int T_6 F_101 ( int V_57 )
{
struct V_14 * V_15 ;
int V_100 = 0 ;
F_85 (cachep, &slab_caches, list) {
struct V_1 * V_74 ;
V_74 = F_48 ( V_15 , V_57 ) ;
if ( ! V_74 )
continue;
F_92 ( V_15 , V_74 , V_111 ) ;
if ( ! F_102 ( & V_74 -> V_3 ) ||
! F_102 ( & V_74 -> V_4 ) ) {
V_100 = - V_115 ;
break;
}
}
return V_100 ;
}
static int T_6 F_103 ( struct V_116 * V_117 ,
unsigned long V_118 , void * V_119 )
{
struct V_120 * V_121 = V_119 ;
int V_100 = 0 ;
int V_122 ;
V_122 = V_121 -> V_123 ;
if ( V_122 < 0 )
goto V_124;
switch ( V_118 ) {
case V_125 :
F_95 ( & V_114 ) ;
V_100 = F_84 ( V_122 ) ;
F_96 ( & V_114 ) ;
break;
case V_126 :
F_95 ( & V_114 ) ;
V_100 = F_101 ( V_122 ) ;
F_96 ( & V_114 ) ;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
break;
}
V_124:
return F_104 ( V_100 ) ;
}
static void T_3 F_105 ( struct V_14 * V_15 , struct V_1 * V_76 ,
int V_84 )
{
struct V_1 * V_131 ;
V_131 = F_44 ( sizeof( struct V_1 ) , V_132 , V_84 ) ;
F_6 ( ! V_131 ) ;
memcpy ( V_131 , V_76 , sizeof( struct V_1 ) ) ;
F_3 ( & V_131 -> V_11 ) ;
F_106 ( V_15 , V_131 , V_84 ) ;
V_15 -> V_57 [ V_84 ] = V_131 ;
}
static void T_3 F_107 ( struct V_14 * V_15 , int V_133 )
{
int V_57 ;
F_71 (node) {
V_15 -> V_57 [ V_57 ] = & V_134 [ V_133 + V_57 ] ;
V_15 -> V_57 [ V_57 ] -> V_97 = V_98 +
V_99 +
( ( unsigned long ) V_15 ) % V_99 ;
}
}
void T_3 F_108 ( void )
{
int V_90 ;
F_109 ( sizeof( ( (struct V_25 * ) NULL ) -> V_135 ) <
sizeof( struct V_136 ) ) ;
V_14 = & V_137 ;
if ( ! F_110 ( V_138 ) || F_111 () == 1 )
V_49 = 0 ;
for ( V_90 = 0 ; V_90 < V_139 ; V_90 ++ )
F_1 ( & V_134 [ V_90 ] ) ;
if ( ! V_53 && V_140 > ( 32 << 20 ) >> V_141 )
V_51 = V_142 ;
F_112 ( V_14 , L_2 ,
F_113 ( struct V_14 , V_57 ) +
V_89 * sizeof( struct V_1 * ) ,
V_143 ) ;
F_114 ( & V_14 -> V_76 , & V_144 ) ;
V_145 = V_146 ;
V_147 [ V_148 ] = F_115 ( L_3 ,
F_116 ( V_148 ) , V_149 ) ;
V_145 = V_150 ;
F_117 () ;
V_151 = 0 ;
{
int V_122 ;
F_71 (nid) {
F_105 ( V_14 , & V_134 [ V_152 + V_122 ] , V_122 ) ;
F_105 ( V_147 [ V_148 ] ,
& V_134 [ V_153 + V_122 ] , V_122 ) ;
}
}
F_118 ( V_149 ) ;
}
void T_3 F_119 ( void )
{
struct V_14 * V_15 ;
V_145 = V_154 ;
F_95 ( & V_114 ) ;
F_85 (cachep, &slab_caches, list)
if ( F_120 ( V_15 , V_132 ) )
F_121 () ;
F_96 ( & V_114 ) ;
V_145 = V_155 ;
#ifdef V_138
F_122 ( F_103 , V_156 ) ;
#endif
}
static int T_3 F_123 ( void )
{
int V_100 ;
V_100 = F_124 ( V_157 , L_4 ,
F_98 , F_99 ) ;
F_125 ( V_100 < 0 ) ;
V_145 = V_155 ;
return 0 ;
}
static T_5 void
F_126 ( struct V_14 * V_15 , T_4 V_158 , int V_84 )
{
#if V_159
struct V_1 * V_74 ;
unsigned long V_17 ;
int V_57 ;
static F_127 ( V_160 , V_161 ,
V_162 ) ;
if ( ( V_158 & V_93 ) || ! F_128 ( & V_160 ) )
return;
F_129 ( L_5 ,
V_84 , V_158 , & V_158 ) ;
F_129 ( L_6 ,
V_15 -> V_45 , V_15 -> V_20 , V_15 -> V_34 ) ;
F_130 (cachep, node, n) {
unsigned long V_6 , V_7 , V_163 ;
F_72 ( & V_74 -> V_11 , V_17 ) ;
V_6 = V_74 -> V_6 ;
V_7 = V_74 -> V_7 ;
V_163 = V_74 -> V_12 ;
F_73 ( & V_74 -> V_11 , V_17 ) ;
F_129 ( L_7 ,
V_57 , V_6 - V_7 , V_6 ,
( V_6 * V_15 -> V_37 ) - V_163 ,
V_6 * V_15 -> V_37 ) ;
}
#endif
}
static struct V_25 * F_131 ( struct V_14 * V_15 , T_4 V_17 ,
int V_84 )
{
struct V_25 * V_25 ;
int V_164 ;
V_17 |= V_15 -> V_165 ;
if ( V_15 -> V_17 & V_166 )
V_17 |= V_167 ;
V_25 = F_132 ( V_84 , V_17 | V_168 , V_15 -> V_34 ) ;
if ( ! V_25 ) {
F_126 ( V_15 , V_17 , V_84 ) ;
return NULL ;
}
if ( F_133 ( V_25 , V_17 , V_15 -> V_34 , V_15 ) ) {
F_134 ( V_25 , V_15 -> V_34 ) ;
return NULL ;
}
V_164 = ( 1 << V_15 -> V_34 ) ;
if ( V_15 -> V_17 & V_166 )
F_135 ( F_136 ( V_25 ) ,
V_169 , V_164 ) ;
else
F_135 ( F_136 ( V_25 ) ,
V_170 , V_164 ) ;
F_137 ( V_25 ) ;
if ( F_138 () && F_139 ( V_25 ) )
F_140 ( V_25 ) ;
if ( V_171 && ! ( V_15 -> V_17 & V_172 ) ) {
F_141 ( V_25 , V_15 -> V_34 , V_17 , V_84 ) ;
if ( V_15 -> V_173 )
F_142 ( V_25 , V_164 ) ;
else
F_143 ( V_25 , V_164 ) ;
}
return V_25 ;
}
static void F_144 ( struct V_14 * V_15 , struct V_25 * V_25 )
{
int V_174 = V_15 -> V_34 ;
unsigned long V_175 = ( 1 << V_174 ) ;
F_145 ( V_25 , V_174 ) ;
if ( V_15 -> V_17 & V_166 )
F_146 ( F_136 ( V_25 ) ,
V_169 , V_175 ) ;
else
F_146 ( F_136 ( V_25 ) ,
V_170 , V_175 ) ;
F_6 ( ! F_147 ( V_25 ) ) ;
F_148 ( V_25 ) ;
F_149 ( V_25 ) ;
F_150 ( V_25 ) ;
V_25 -> V_176 = NULL ;
if ( V_177 -> V_178 )
V_177 -> V_178 -> V_179 += V_175 ;
F_151 ( V_25 , V_174 , V_15 ) ;
F_134 ( V_25 , V_174 ) ;
}
static void F_152 ( struct V_136 * V_180 )
{
struct V_14 * V_15 ;
struct V_25 * V_25 ;
V_25 = F_153 ( V_180 , struct V_25 , V_136 ) ;
V_15 = V_25 -> V_26 ;
F_144 ( V_15 , V_25 ) ;
}
static bool F_154 ( struct V_14 * V_15 )
{
if ( F_155 () && F_156 ( V_15 ) &&
( V_15 -> V_20 % V_39 ) == 0 )
return true ;
return false ;
}
static void F_157 ( struct V_14 * V_15 , unsigned long * V_181 ,
unsigned long V_182 )
{
int V_20 = V_15 -> V_183 ;
V_181 = ( unsigned long * ) & ( ( char * ) V_181 ) [ F_4 ( V_15 ) ] ;
if ( V_20 < 5 * sizeof( unsigned long ) )
return;
* V_181 ++ = 0x12345678 ;
* V_181 ++ = V_182 ;
* V_181 ++ = F_158 () ;
V_20 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_184 = & V_182 ;
unsigned long V_185 ;
while ( ! F_159 ( V_184 ) ) {
V_185 = * V_184 ++ ;
if ( F_160 ( V_185 ) ) {
* V_181 ++ = V_185 ;
V_20 -= sizeof( unsigned long ) ;
if ( V_20 <= sizeof( unsigned long ) )
break;
}
}
}
* V_181 ++ = 0x87654321 ;
}
static void F_161 ( struct V_14 * V_15 , void * V_16 ,
int V_186 , unsigned long V_182 )
{
if ( ! F_154 ( V_15 ) )
return;
if ( V_182 )
F_157 ( V_15 , V_16 , V_182 ) ;
F_162 ( F_78 ( V_16 ) , V_15 -> V_20 / V_39 , V_186 ) ;
}
static inline void F_161 ( struct V_14 * V_15 , void * V_16 ,
int V_186 , unsigned long V_182 ) {}
static void F_163 ( struct V_14 * V_15 , void * V_181 , unsigned char V_187 )
{
int V_20 = V_15 -> V_183 ;
V_181 = & ( ( char * ) V_181 ) [ F_4 ( V_15 ) ] ;
memset ( V_181 , V_187 , V_20 ) ;
* ( unsigned char * ) ( V_181 + V_20 - 1 ) = V_188 ;
}
static void F_164 ( char * V_189 , int V_30 , int V_66 )
{
int V_90 ;
unsigned char error = 0 ;
int V_190 = 0 ;
F_23 ( L_8 , V_30 ) ;
for ( V_90 = 0 ; V_90 < V_66 ; V_90 ++ ) {
if ( V_189 [ V_30 + V_90 ] != V_191 ) {
error = V_189 [ V_30 + V_90 ] ;
V_190 ++ ;
}
}
F_165 ( V_192 , L_9 , 0 , 16 , 1 ,
& V_189 [ V_30 ] , V_66 , 1 ) ;
if ( V_190 == 1 ) {
error ^= V_191 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_23 ( L_10 ) ;
#ifdef F_166
F_23 ( L_11 ) ;
#else
F_23 ( L_12 ) ;
#endif
}
}
}
static void F_167 ( struct V_14 * V_15 , void * V_16 , int V_193 )
{
int V_90 , V_20 ;
char * V_194 ;
if ( V_15 -> V_17 & V_18 ) {
F_23 ( L_13 ,
* F_5 ( V_15 , V_16 ) ,
* F_7 ( V_15 , V_16 ) ) ;
}
if ( V_15 -> V_17 & V_19 ) {
F_23 ( L_14 ,
* F_8 ( V_15 , V_16 ) ,
* F_8 ( V_15 , V_16 ) ) ;
}
V_194 = ( char * ) V_16 + F_4 ( V_15 ) ;
V_20 = V_15 -> V_183 ;
for ( V_90 = 0 ; V_90 < V_20 && V_193 ; V_90 += 16 , V_193 -- ) {
int V_66 ;
V_66 = 16 ;
if ( V_90 + V_66 > V_20 )
V_66 = V_20 - V_90 ;
F_164 ( V_194 , V_90 , V_66 ) ;
}
}
static void F_168 ( struct V_14 * V_15 , void * V_16 )
{
char * V_194 ;
int V_20 , V_90 ;
int V_193 = 0 ;
if ( F_154 ( V_15 ) )
return;
V_194 = ( char * ) V_16 + F_4 ( V_15 ) ;
V_20 = V_15 -> V_183 ;
for ( V_90 = 0 ; V_90 < V_20 ; V_90 ++ ) {
char exp = V_191 ;
if ( V_90 == V_20 - 1 )
exp = V_188 ;
if ( V_194 [ V_90 ] != exp ) {
int V_66 ;
if ( V_193 == 0 ) {
F_23 ( L_15 ,
F_169 () , V_15 -> V_45 ,
V_194 , V_20 ) ;
F_167 ( V_15 , V_16 , 0 ) ;
}
V_90 = ( V_90 / 16 ) * 16 ;
V_66 = 16 ;
if ( V_90 + V_66 > V_20 )
V_66 = V_20 - V_90 ;
F_164 ( V_194 , V_90 , V_66 ) ;
V_90 += 16 ;
V_193 ++ ;
if ( V_193 > 5 )
break;
}
}
if ( V_193 != 0 ) {
struct V_25 * V_25 = F_15 ( V_16 ) ;
unsigned int V_195 ;
V_195 = F_17 ( V_15 , V_25 , V_16 ) ;
if ( V_195 ) {
V_16 = F_16 ( V_15 , V_25 , V_195 - 1 ) ;
V_194 = ( char * ) V_16 + F_4 ( V_15 ) ;
F_23 ( L_16 , V_194 , V_20 ) ;
F_167 ( V_15 , V_16 , 2 ) ;
}
if ( V_195 + 1 < V_15 -> V_37 ) {
V_16 = F_16 ( V_15 , V_25 , V_195 + 1 ) ;
V_194 = ( char * ) V_16 + F_4 ( V_15 ) ;
F_23 ( L_17 , V_194 , V_20 ) ;
F_167 ( V_15 , V_16 , 2 ) ;
}
}
}
static void F_170 ( struct V_14 * V_15 ,
struct V_25 * V_25 )
{
int V_90 ;
if ( F_171 ( V_15 ) && V_15 -> V_17 & V_196 ) {
F_163 ( V_15 , V_25 -> V_197 - F_4 ( V_15 ) ,
V_191 ) ;
}
for ( V_90 = 0 ; V_90 < V_15 -> V_37 ; V_90 ++ ) {
void * V_16 = F_16 ( V_15 , V_25 , V_90 ) ;
if ( V_15 -> V_17 & V_196 ) {
F_168 ( V_15 , V_16 ) ;
F_161 ( V_15 , V_16 , 1 , 0 ) ;
}
if ( V_15 -> V_17 & V_18 ) {
if ( * F_5 ( V_15 , V_16 ) != V_198 )
F_172 ( V_15 , L_18 ) ;
if ( * F_7 ( V_15 , V_16 ) != V_198 )
F_172 ( V_15 , L_19 ) ;
}
}
}
static void F_170 ( struct V_14 * V_15 ,
struct V_25 * V_25 )
{
}
static void F_173 ( struct V_14 * V_15 , struct V_25 * V_25 )
{
void * V_197 ;
V_197 = V_25 -> V_197 ;
F_170 ( V_15 , V_25 ) ;
if ( F_76 ( V_15 -> V_17 & V_199 ) )
F_174 ( & V_25 -> V_136 , F_152 ) ;
else
F_144 ( V_15 , V_25 ) ;
if ( F_156 ( V_15 ) )
F_175 ( V_15 -> V_200 , V_197 ) ;
}
static void F_52 ( struct V_14 * V_15 , struct V_91 * V_76 )
{
struct V_25 * V_25 , * V_74 ;
F_176 (page, n, list, lru) {
F_177 ( & V_25 -> V_135 ) ;
F_173 ( V_15 , V_25 ) ;
}
}
static T_2 F_178 ( struct V_14 * V_15 ,
T_2 V_20 , unsigned long V_17 )
{
T_2 V_36 = 0 ;
int V_34 ;
for ( V_34 = 0 ; V_34 <= V_201 ; V_34 ++ ) {
unsigned int V_37 ;
T_2 V_202 ;
V_37 = F_21 ( V_34 , V_20 , V_17 , & V_202 ) ;
if ( ! V_37 )
continue;
if ( V_37 > V_203 )
break;
if ( V_17 & V_41 ) {
struct V_14 * V_200 ;
T_2 V_204 ;
V_204 = V_37 * sizeof( V_42 ) ;
V_200 = F_179 ( V_204 , 0u ) ;
if ( ! V_200 )
continue;
if ( F_156 ( V_200 ) )
continue;
if ( V_200 -> V_20 > V_15 -> V_20 / 2 )
continue;
}
V_15 -> V_37 = V_37 ;
V_15 -> V_34 = V_34 ;
V_36 = V_202 ;
if ( V_17 & V_166 )
break;
if ( V_34 >= V_51 )
break;
if ( V_36 * 8 <= ( V_39 << V_34 ) )
break;
}
return V_36 ;
}
static struct V_32 T_7 * F_180 (
struct V_14 * V_15 , int V_71 , int V_69 )
{
int V_54 ;
T_2 V_20 ;
struct V_32 T_7 * V_33 ;
V_20 = sizeof( void * ) * V_71 + sizeof( struct V_32 ) ;
V_33 = F_181 ( V_20 , sizeof( void * ) ) ;
if ( ! V_33 )
return NULL ;
F_182 (cpu) {
F_41 ( F_90 ( V_33 , V_54 ) ,
V_71 , V_69 ) ;
}
return V_33 ;
}
static int T_8 F_183 ( struct V_14 * V_15 , T_4 V_72 )
{
if ( V_145 >= V_155 )
return F_120 ( V_15 , V_72 ) ;
V_15 -> V_33 = F_180 ( V_15 , 1 , 1 ) ;
if ( ! V_15 -> V_33 )
return 1 ;
if ( V_145 == V_205 ) {
F_107 ( V_14 , V_152 ) ;
} else if ( V_145 == V_146 ) {
F_107 ( V_15 , V_153 ) ;
} else {
int V_57 ;
F_71 (node) {
V_15 -> V_57 [ V_57 ] = F_44 (
sizeof( struct V_1 ) , V_72 , V_57 ) ;
F_6 ( ! V_15 -> V_57 [ V_57 ] ) ;
F_1 ( V_15 -> V_57 [ V_57 ] ) ;
}
}
V_15 -> V_57 [ F_79 () ] -> V_97 =
V_98 + V_99 +
( ( unsigned long ) V_15 ) % V_99 ;
F_19 ( V_15 ) -> V_68 = 0 ;
F_19 ( V_15 ) -> V_66 = V_206 ;
F_19 ( V_15 ) -> V_69 = 1 ;
F_19 ( V_15 ) -> V_70 = 0 ;
V_15 -> V_69 = 1 ;
V_15 -> V_66 = V_206 ;
return 0 ;
}
unsigned long F_184 ( unsigned long V_183 ,
unsigned long V_17 , const char * V_45 ,
void (* V_173)( void * ) )
{
return V_17 ;
}
struct V_14 *
F_185 ( const char * V_45 , T_2 V_20 , T_2 V_207 ,
unsigned long V_17 , void (* V_173)( void * ) )
{
struct V_14 * V_15 ;
V_15 = F_186 ( V_20 , V_207 , V_17 , V_45 , V_173 ) ;
if ( V_15 ) {
V_15 -> V_208 ++ ;
V_15 -> V_183 = F_187 ( int , V_15 -> V_183 , V_20 ) ;
}
return V_15 ;
}
static bool F_188 ( struct V_14 * V_15 ,
T_2 V_20 , unsigned long V_17 )
{
T_2 V_209 ;
V_15 -> V_37 = 0 ;
if ( V_15 -> V_173 || V_17 & V_199 )
return false ;
V_209 = F_178 ( V_15 , V_20 ,
V_17 | V_40 ) ;
if ( ! V_15 -> V_37 )
return false ;
if ( V_15 -> V_37 * sizeof( V_42 ) > V_15 -> V_183 )
return false ;
V_15 -> V_210 = V_209 / V_15 -> V_211 ;
return true ;
}
static bool F_189 ( struct V_14 * V_15 ,
T_2 V_20 , unsigned long V_17 )
{
T_2 V_209 ;
V_15 -> V_37 = 0 ;
if ( V_17 & V_212 )
return false ;
V_209 = F_178 ( V_15 , V_20 , V_17 | V_41 ) ;
if ( ! V_15 -> V_37 )
return false ;
if ( V_209 >= V_15 -> V_37 * sizeof( V_42 ) )
return false ;
V_15 -> V_210 = V_209 / V_15 -> V_211 ;
return true ;
}
static bool F_190 ( struct V_14 * V_15 ,
T_2 V_20 , unsigned long V_17 )
{
T_2 V_209 ;
V_15 -> V_37 = 0 ;
V_209 = F_178 ( V_15 , V_20 , V_17 ) ;
if ( ! V_15 -> V_37 )
return false ;
V_15 -> V_210 = V_209 / V_15 -> V_211 ;
return true ;
}
int
F_191 ( struct V_14 * V_15 , unsigned long V_17 )
{
T_2 V_213 = V_22 ;
T_4 V_72 ;
int V_112 ;
T_2 V_20 = V_15 -> V_20 ;
#if V_159
#if V_214
if ( V_20 < 4096 || F_192 ( V_20 - 1 ) == F_192 ( V_20 - 1 + V_21 +
2 * sizeof( unsigned long long ) ) )
V_17 |= V_18 | V_19 ;
if ( ! ( V_17 & V_199 ) )
V_17 |= V_196 ;
#endif
#endif
if ( V_20 & ( V_22 - 1 ) ) {
V_20 += ( V_22 - 1 ) ;
V_20 &= ~ ( V_22 - 1 ) ;
}
if ( V_17 & V_18 ) {
V_213 = V_21 ;
V_20 += V_21 - 1 ;
V_20 &= ~ ( V_21 - 1 ) ;
}
if ( V_213 < V_15 -> V_207 ) {
V_213 = V_15 -> V_207 ;
}
if ( V_213 > F_193 (unsigned long long) )
V_17 &= ~ ( V_18 | V_19 ) ;
V_15 -> V_207 = V_213 ;
V_15 -> V_211 = F_194 () ;
if ( V_15 -> V_211 < V_15 -> V_207 )
V_15 -> V_211 = V_15 -> V_207 ;
if ( F_195 () )
V_72 = V_101 ;
else
V_72 = V_132 ;
#if V_159
if ( V_17 & V_18 ) {
V_15 -> F_4 += sizeof( unsigned long long ) ;
V_20 += 2 * sizeof( unsigned long long ) ;
}
if ( V_17 & V_19 ) {
if ( V_17 & V_18 )
V_20 += V_21 ;
else
V_20 += V_22 ;
}
#endif
F_196 ( V_15 , & V_20 , & V_17 ) ;
V_20 = F_197 ( V_20 , V_15 -> V_207 ) ;
if ( V_215 && V_20 < V_216 )
V_20 = F_197 ( V_216 , V_15 -> V_207 ) ;
#if V_159
if ( F_155 () && ( V_17 & V_196 ) &&
V_20 >= 256 && V_15 -> V_183 > F_194 () ) {
if ( V_20 < V_39 || V_20 % V_39 == 0 ) {
T_2 V_217 = F_197 ( V_20 , V_39 ) ;
if ( F_189 ( V_15 , V_217 , V_17 ) ) {
V_17 |= V_41 ;
V_15 -> F_4 += V_217 - V_20 ;
V_20 = V_217 ;
goto V_218;
}
}
}
#endif
if ( F_188 ( V_15 , V_20 , V_17 ) ) {
V_17 |= V_40 ;
goto V_218;
}
if ( F_189 ( V_15 , V_20 , V_17 ) ) {
V_17 |= V_41 ;
goto V_218;
}
if ( F_190 ( V_15 , V_20 , V_17 ) )
goto V_218;
return - V_219 ;
V_218:
V_15 -> V_204 = V_15 -> V_37 * sizeof( V_42 ) ;
V_15 -> V_17 = V_17 ;
V_15 -> V_165 = V_220 ;
if ( V_17 & V_221 )
V_15 -> V_165 |= V_222 ;
V_15 -> V_20 = V_20 ;
V_15 -> V_31 = F_198 ( V_20 ) ;
#if V_159
if ( F_110 ( V_223 ) &&
( V_15 -> V_17 & V_196 ) &&
F_154 ( V_15 ) )
V_15 -> V_17 &= ~ ( V_18 | V_19 ) ;
#endif
if ( F_156 ( V_15 ) ) {
V_15 -> V_200 =
F_179 ( V_15 -> V_204 , 0u ) ;
}
V_112 = F_183 ( V_15 , V_72 ) ;
if ( V_112 ) {
F_199 ( V_15 ) ;
return V_112 ;
}
return 0 ;
}
static void F_200 ( void )
{
F_6 ( ! F_201 () ) ;
}
static void F_202 ( void )
{
F_6 ( F_201 () ) ;
}
static void F_203 ( void )
{
F_6 ( ! F_204 ( & V_114 ) ) ;
}
static void F_205 ( struct V_14 * V_15 )
{
#ifdef F_206
F_200 () ;
F_207 ( & F_48 ( V_15 , F_79 () ) -> V_11 ) ;
#endif
}
static void F_208 ( struct V_14 * V_15 , int V_57 )
{
#ifdef F_206
F_200 () ;
F_207 ( & F_48 ( V_15 , V_57 ) -> V_11 ) ;
#endif
}
static void F_209 ( struct V_14 * V_15 , struct V_32 * V_65 ,
int V_57 , bool V_224 , struct V_91 * V_76 )
{
int V_225 ;
if ( ! V_65 || ! V_65 -> V_68 )
return;
V_225 = V_224 ? V_65 -> V_68 : ( V_65 -> V_66 + 4 ) / 5 ;
if ( V_225 > V_65 -> V_68 )
V_225 = ( V_65 -> V_68 + 1 ) / 2 ;
F_50 ( V_15 , V_65 -> V_81 , V_225 , V_57 , V_76 ) ;
V_65 -> V_68 -= V_225 ;
memmove ( V_65 -> V_81 , & ( V_65 -> V_81 [ V_225 ] ) , sizeof( void * ) * V_65 -> V_68 ) ;
}
static void F_210 ( void * V_119 )
{
struct V_14 * V_15 = V_119 ;
struct V_32 * V_65 ;
int V_57 = F_79 () ;
struct V_1 * V_74 ;
F_46 ( V_76 ) ;
F_200 () ;
V_65 = F_19 ( V_15 ) ;
V_74 = F_48 ( V_15 , V_57 ) ;
F_49 ( & V_74 -> V_11 ) ;
F_50 ( V_15 , V_65 -> V_81 , V_65 -> V_68 , V_57 , & V_76 ) ;
F_51 ( & V_74 -> V_11 ) ;
F_52 ( V_15 , & V_76 ) ;
V_65 -> V_68 = 0 ;
}
static void F_211 ( struct V_14 * V_15 )
{
struct V_1 * V_74 ;
int V_57 ;
F_46 ( V_76 ) ;
F_212 ( F_210 , V_15 , 1 ) ;
F_202 () ;
F_130 (cachep, node, n)
if ( V_74 -> V_9 )
F_70 ( V_15 , V_74 -> V_9 ) ;
F_130 (cachep, node, n) {
F_82 ( & V_74 -> V_11 ) ;
F_209 ( V_15 , V_74 -> V_8 , V_57 , true , & V_76 ) ;
F_69 ( & V_74 -> V_11 ) ;
F_52 ( V_15 , & V_76 ) ;
}
}
static int F_92 ( struct V_14 * V_27 ,
struct V_1 * V_74 , int V_225 )
{
struct V_91 * V_226 ;
int V_175 ;
struct V_25 * V_25 ;
V_175 = 0 ;
while ( V_175 < V_225 && ! F_102 ( & V_74 -> V_5 ) ) {
F_82 ( & V_74 -> V_11 ) ;
V_226 = V_74 -> V_5 . V_227 ;
if ( V_226 == & V_74 -> V_5 ) {
F_69 ( & V_74 -> V_11 ) ;
goto V_124;
}
V_25 = F_213 ( V_226 , struct V_25 , V_135 ) ;
F_177 ( & V_25 -> V_135 ) ;
V_74 -> V_7 -- ;
V_74 -> V_6 -- ;
V_74 -> V_12 -= V_27 -> V_37 ;
F_69 ( & V_74 -> V_11 ) ;
F_173 ( V_27 , V_25 ) ;
V_175 ++ ;
}
V_124:
return V_175 ;
}
int F_214 ( struct V_14 * V_15 )
{
int V_100 = 0 ;
int V_57 ;
struct V_1 * V_74 ;
F_211 ( V_15 ) ;
F_202 () ;
F_130 (cachep, node, n) {
F_92 ( V_15 , V_74 , V_111 ) ;
V_100 += ! F_102 ( & V_74 -> V_3 ) ||
! F_102 ( & V_74 -> V_4 ) ;
}
return ( V_100 ? 1 : 0 ) ;
}
int F_215 ( struct V_14 * V_15 )
{
return F_214 ( V_15 ) ;
}
void F_199 ( struct V_14 * V_15 )
{
int V_90 ;
struct V_1 * V_74 ;
F_216 ( V_15 ) ;
F_217 ( V_15 -> V_33 ) ;
F_130 (cachep, i, n) {
F_65 ( V_74 -> V_8 ) ;
F_56 ( V_74 -> V_9 ) ;
F_65 ( V_74 ) ;
V_15 -> V_57 [ V_90 ] = NULL ;
}
}
static void * F_218 ( struct V_14 * V_15 ,
struct V_25 * V_25 , int V_211 ,
T_4 V_228 , int V_84 )
{
void * V_197 ;
void * V_181 = F_219 ( V_25 ) ;
V_25 -> V_29 = V_181 + V_211 ;
V_25 -> V_229 = 0 ;
if ( F_171 ( V_15 ) )
V_197 = NULL ;
else if ( F_156 ( V_15 ) ) {
V_197 = F_220 ( V_15 -> V_200 ,
V_228 , V_84 ) ;
if ( ! V_197 )
return NULL ;
} else {
V_197 = V_181 + ( V_39 << V_15 -> V_34 ) -
V_15 -> V_204 ;
}
return V_197 ;
}
static inline V_42 F_221 ( struct V_25 * V_25 , unsigned int V_28 )
{
return ( ( V_42 * ) V_25 -> V_197 ) [ V_28 ] ;
}
static inline void F_222 ( struct V_25 * V_25 ,
unsigned int V_28 , V_42 V_187 )
{
( ( V_42 * ) ( V_25 -> V_197 ) ) [ V_28 ] = V_187 ;
}
static void F_223 ( struct V_14 * V_15 , struct V_25 * V_25 )
{
#if V_159
int V_90 ;
for ( V_90 = 0 ; V_90 < V_15 -> V_37 ; V_90 ++ ) {
void * V_16 = F_16 ( V_15 , V_25 , V_90 ) ;
if ( V_15 -> V_17 & V_19 )
* F_8 ( V_15 , V_16 ) = NULL ;
if ( V_15 -> V_17 & V_18 ) {
* F_5 ( V_15 , V_16 ) = V_198 ;
* F_7 ( V_15 , V_16 ) = V_198 ;
}
if ( V_15 -> V_173 && ! ( V_15 -> V_17 & V_196 ) ) {
F_224 ( V_15 ,
V_16 + F_4 ( V_15 ) ) ;
V_15 -> V_173 ( V_16 + F_4 ( V_15 ) ) ;
F_225 (
V_15 , V_16 + F_4 ( V_15 ) ) ;
}
if ( V_15 -> V_17 & V_18 ) {
if ( * F_7 ( V_15 , V_16 ) != V_198 )
F_172 ( V_15 , L_20 ) ;
if ( * F_5 ( V_15 , V_16 ) != V_198 )
F_172 ( V_15 , L_21 ) ;
}
if ( V_15 -> V_17 & V_196 ) {
F_163 ( V_15 , V_16 , V_191 ) ;
F_161 ( V_15 , V_16 , 0 , 0 ) ;
}
}
#endif
}
static bool F_226 ( union V_230 * V_231 ,
struct V_14 * V_15 ,
unsigned int V_232 )
{
bool V_100 ;
unsigned int rand ;
rand = F_227 () ;
if ( ! V_15 -> V_233 ) {
F_228 ( & V_231 -> V_234 , rand ) ;
V_100 = false ;
} else {
V_231 -> V_76 = V_15 -> V_233 ;
V_231 -> V_232 = V_232 ;
V_231 -> V_235 = rand % V_232 ;
V_100 = true ;
}
return V_100 ;
}
static V_42 F_229 ( union V_230 * V_231 )
{
if ( V_231 -> V_235 >= V_231 -> V_232 )
V_231 -> V_235 = 0 ;
return V_231 -> V_76 [ V_231 -> V_235 ++ ] ;
}
static void F_230 ( struct V_25 * V_25 , unsigned int V_236 , unsigned int V_237 )
{
F_231 ( ( ( V_42 * ) V_25 -> V_197 ) [ V_236 ] ,
( ( V_42 * ) V_25 -> V_197 ) [ V_237 ] ) ;
}
static bool F_232 ( struct V_14 * V_15 , struct V_25 * V_25 )
{
unsigned int V_238 = 0 , V_90 , rand , V_232 = V_15 -> V_37 ;
union V_230 V_231 ;
bool V_239 ;
if ( V_232 < 2 )
return false ;
V_239 = F_226 ( & V_231 , V_15 , V_232 ) ;
if ( F_171 ( V_15 ) ) {
if ( ! V_239 )
V_238 = V_232 - 1 ;
else
V_238 = F_229 ( & V_231 ) ;
V_25 -> V_197 = F_16 ( V_15 , V_25 , V_238 ) +
F_4 ( V_15 ) ;
V_232 -- ;
}
if ( ! V_239 ) {
for ( V_90 = 0 ; V_90 < V_232 ; V_90 ++ )
F_222 ( V_25 , V_90 , V_90 ) ;
for ( V_90 = V_232 - 1 ; V_90 > 0 ; V_90 -- ) {
rand = F_233 ( & V_231 . V_234 ) ;
rand %= ( V_90 + 1 ) ;
F_230 ( V_25 , V_90 , rand ) ;
}
} else {
for ( V_90 = 0 ; V_90 < V_232 ; V_90 ++ )
F_222 ( V_25 , V_90 , F_229 ( & V_231 ) ) ;
}
if ( F_171 ( V_15 ) )
F_222 ( V_25 , V_15 -> V_37 - 1 , V_238 ) ;
return true ;
}
static inline bool F_232 ( struct V_14 * V_15 ,
struct V_25 * V_25 )
{
return false ;
}
static void F_234 ( struct V_14 * V_15 ,
struct V_25 * V_25 )
{
int V_90 ;
void * V_16 ;
bool V_240 ;
F_223 ( V_15 , V_25 ) ;
V_240 = F_232 ( V_15 , V_25 ) ;
if ( ! V_240 && F_171 ( V_15 ) ) {
V_25 -> V_197 = F_16 ( V_15 , V_25 , V_15 -> V_37 - 1 ) +
F_4 ( V_15 ) ;
}
for ( V_90 = 0 ; V_90 < V_15 -> V_37 ; V_90 ++ ) {
V_16 = F_16 ( V_15 , V_25 , V_90 ) ;
F_235 ( V_15 , V_16 ) ;
if ( V_159 == 0 && V_15 -> V_173 ) {
F_224 ( V_15 , V_16 ) ;
V_15 -> V_173 ( V_16 ) ;
F_225 ( V_15 , V_16 ) ;
}
if ( ! V_240 )
F_222 ( V_25 , V_90 , V_90 ) ;
}
}
static void * F_236 ( struct V_14 * V_15 , struct V_25 * V_25 )
{
void * V_16 ;
V_16 = F_16 ( V_15 , V_25 , F_221 ( V_25 , V_25 -> V_229 ) ) ;
V_25 -> V_229 ++ ;
#if V_159
if ( V_15 -> V_17 & V_19 )
F_13 ( V_15 ) ;
#endif
return V_16 ;
}
static void F_237 ( struct V_14 * V_15 ,
struct V_25 * V_25 , void * V_16 )
{
unsigned int V_195 = F_17 ( V_15 , V_25 , V_16 ) ;
#if V_159
unsigned int V_90 ;
for ( V_90 = V_25 -> V_229 ; V_90 < V_15 -> V_37 ; V_90 ++ ) {
if ( F_221 ( V_25 , V_90 ) == V_195 ) {
F_23 ( L_22 ,
V_15 -> V_45 , V_16 ) ;
F_121 () ;
}
}
#endif
V_25 -> V_229 -- ;
if ( ! V_25 -> V_197 )
V_25 -> V_197 = V_16 + F_4 ( V_15 ) ;
F_222 ( V_25 , V_25 -> V_229 , V_195 ) ;
}
static void F_238 ( struct V_14 * V_27 , struct V_25 * V_25 ,
void * V_197 )
{
V_25 -> V_26 = V_27 ;
V_25 -> V_197 = V_197 ;
}
static struct V_25 * F_239 ( struct V_14 * V_15 ,
T_4 V_17 , int V_84 )
{
void * V_197 ;
T_2 V_30 ;
T_4 V_228 ;
int V_75 ;
struct V_1 * V_74 ;
struct V_25 * V_25 ;
if ( F_76 ( V_17 & V_241 ) ) {
T_4 V_242 = V_17 & V_241 ;
V_17 &= ~ V_241 ;
F_129 ( L_23 ,
V_242 , & V_242 , V_17 , & V_17 ) ;
F_24 () ;
}
V_228 = V_17 & ( V_243 | V_244 ) ;
F_200 () ;
if ( F_240 ( V_228 ) )
F_241 () ;
V_25 = F_131 ( V_15 , V_228 , V_84 ) ;
if ( ! V_25 )
goto V_245;
V_75 = F_47 ( V_25 ) ;
V_74 = F_48 ( V_15 , V_75 ) ;
V_74 -> V_10 ++ ;
if ( V_74 -> V_10 >= V_15 -> V_210 )
V_74 -> V_10 = 0 ;
V_30 = V_74 -> V_10 ;
if ( V_30 >= V_15 -> V_210 )
V_30 = 0 ;
V_30 *= V_15 -> V_211 ;
V_197 = F_218 ( V_15 , V_25 , V_30 ,
V_228 & ~ V_243 , V_75 ) ;
if ( F_156 ( V_15 ) && ! V_197 )
goto V_246;
F_238 ( V_15 , V_25 , V_197 ) ;
F_242 ( V_25 ) ;
F_234 ( V_15 , V_25 ) ;
if ( F_240 ( V_228 ) )
F_243 () ;
return V_25 ;
V_246:
F_144 ( V_15 , V_25 ) ;
V_245:
if ( F_240 ( V_228 ) )
F_243 () ;
return NULL ;
}
static void F_244 ( struct V_14 * V_15 , struct V_25 * V_25 )
{
struct V_1 * V_74 ;
void * V_76 = NULL ;
F_200 () ;
if ( ! V_25 )
return;
F_2 ( & V_25 -> V_135 ) ;
V_74 = F_48 ( V_15 , F_47 ( V_25 ) ) ;
F_49 ( & V_74 -> V_11 ) ;
V_74 -> V_6 ++ ;
if ( ! V_25 -> V_229 ) {
F_245 ( & V_25 -> V_135 , & ( V_74 -> V_5 ) ) ;
V_74 -> V_7 ++ ;
} else
F_246 ( V_15 , V_74 , V_25 , & V_76 ) ;
F_247 ( V_15 ) ;
V_74 -> V_12 += V_15 -> V_37 - V_25 -> V_229 ;
F_51 ( & V_74 -> V_11 ) ;
F_248 ( V_15 , & V_76 ) ;
}
static void F_249 ( const void * V_16 )
{
if ( ! F_250 ( V_16 ) ) {
F_23 ( L_24 ,
( unsigned long ) V_16 ) ;
F_121 () ;
}
}
static inline void F_251 ( struct V_14 * V_27 , void * V_24 )
{
unsigned long long V_247 , V_248 ;
V_247 = * F_5 ( V_27 , V_24 ) ;
V_248 = * F_7 ( V_27 , V_24 ) ;
if ( V_247 == V_249 && V_248 == V_249 )
return;
if ( V_247 == V_198 && V_248 == V_198 )
F_172 ( V_27 , L_25 ) ;
else
F_172 ( V_27 , L_26 ) ;
F_23 ( L_27 ,
V_24 , V_247 , V_248 ) ;
}
static void * F_252 ( struct V_14 * V_15 , void * V_16 ,
unsigned long V_182 )
{
unsigned int V_195 ;
struct V_25 * V_25 ;
F_6 ( F_14 ( V_16 ) != V_15 ) ;
V_16 -= F_4 ( V_15 ) ;
F_249 ( V_16 ) ;
V_25 = F_15 ( V_16 ) ;
if ( V_15 -> V_17 & V_18 ) {
F_251 ( V_15 , V_16 ) ;
* F_5 ( V_15 , V_16 ) = V_198 ;
* F_7 ( V_15 , V_16 ) = V_198 ;
}
if ( V_15 -> V_17 & V_19 ) {
F_13 ( V_15 ) ;
* F_8 ( V_15 , V_16 ) = ( void * ) V_182 ;
}
V_195 = F_17 ( V_15 , V_25 , V_16 ) ;
F_6 ( V_195 >= V_15 -> V_37 ) ;
F_6 ( V_16 != F_16 ( V_15 , V_25 , V_195 ) ) ;
if ( V_15 -> V_17 & V_196 ) {
F_163 ( V_15 , V_16 , V_191 ) ;
F_161 ( V_15 , V_16 , 0 , V_182 ) ;
}
return V_16 ;
}
static inline void F_248 ( struct V_14 * V_15 ,
void * * V_76 )
{
#if V_159
void * V_250 = * V_76 ;
void * V_16 ;
while ( V_250 ) {
V_16 = V_250 - F_4 ( V_15 ) ;
V_250 = * ( void * * ) V_250 ;
F_163 ( V_15 , V_16 , V_191 ) ;
}
#endif
}
static inline void F_246 ( struct V_14 * V_15 ,
struct V_1 * V_74 , struct V_25 * V_25 ,
void * * V_76 )
{
F_177 ( & V_25 -> V_135 ) ;
if ( V_25 -> V_229 == V_15 -> V_37 ) {
F_114 ( & V_25 -> V_135 , & V_74 -> V_3 ) ;
if ( F_171 ( V_15 ) ) {
#if V_159
if ( V_15 -> V_17 & V_196 ) {
void * * V_16 = V_25 -> V_197 ;
* V_16 = * V_76 ;
* V_76 = V_16 ;
}
#endif
V_25 -> V_197 = NULL ;
}
} else
F_114 ( & V_25 -> V_135 , & V_74 -> V_4 ) ;
}
struct V_25 * F_253 ( struct V_1 * V_74 , bool V_251 )
{
struct V_25 * V_25 ;
F_207 ( & V_74 -> V_11 ) ;
V_25 = F_254 ( & V_74 -> V_4 , struct V_25 , V_135 ) ;
if ( ! V_25 ) {
V_74 -> V_13 = 1 ;
V_25 = F_254 ( & V_74 -> V_5 , struct V_25 ,
V_135 ) ;
if ( V_25 )
V_74 -> V_7 -- ;
}
if ( F_138 () )
V_25 = F_255 ( V_74 , V_25 , V_251 ) ;
return V_25 ;
}
static T_5 void * F_256 ( struct V_14 * V_15 ,
struct V_1 * V_74 , T_4 V_17 )
{
struct V_25 * V_25 ;
void * V_24 ;
void * V_76 = NULL ;
if ( ! F_257 ( V_17 ) )
return NULL ;
F_49 ( & V_74 -> V_11 ) ;
V_25 = F_253 ( V_74 , true ) ;
if ( ! V_25 ) {
F_51 ( & V_74 -> V_11 ) ;
return NULL ;
}
V_24 = F_236 ( V_15 , V_25 ) ;
V_74 -> V_12 -- ;
F_246 ( V_15 , V_74 , V_25 , & V_76 ) ;
F_51 ( & V_74 -> V_11 ) ;
F_248 ( V_15 , & V_76 ) ;
return V_24 ;
}
static T_9 int F_258 ( struct V_14 * V_15 ,
struct V_32 * V_65 , struct V_25 * V_25 , int V_69 )
{
F_6 ( V_25 -> V_229 >= V_15 -> V_37 ) ;
while ( V_25 -> V_229 < V_15 -> V_37 && V_69 -- ) {
F_259 ( V_15 ) ;
F_260 ( V_15 ) ;
F_261 ( V_15 ) ;
V_65 -> V_81 [ V_65 -> V_68 ++ ] = F_236 ( V_15 , V_25 ) ;
}
return V_69 ;
}
static void * F_262 ( struct V_14 * V_15 , T_4 V_17 )
{
int V_69 ;
struct V_1 * V_74 ;
struct V_32 * V_65 , * V_8 ;
int V_57 ;
void * V_76 = NULL ;
struct V_25 * V_25 ;
F_200 () ;
V_57 = F_79 () ;
V_65 = F_19 ( V_15 ) ;
V_69 = V_65 -> V_69 ;
if ( ! V_65 -> V_70 && V_69 > V_252 ) {
V_69 = V_252 ;
}
V_74 = F_48 ( V_15 , V_57 ) ;
F_6 ( V_65 -> V_68 > 0 || ! V_74 ) ;
V_8 = F_263 ( V_74 -> V_8 ) ;
if ( ! V_74 -> V_12 && ( ! V_8 || ! V_8 -> V_68 ) )
goto V_253;
F_49 ( & V_74 -> V_11 ) ;
V_8 = F_263 ( V_74 -> V_8 ) ;
if ( V_8 && F_53 ( V_65 , V_8 , V_69 ) ) {
V_8 -> V_70 = 1 ;
goto V_254;
}
while ( V_69 > 0 ) {
V_25 = F_253 ( V_74 , false ) ;
if ( ! V_25 )
goto V_255;
F_205 ( V_15 ) ;
V_69 = F_258 ( V_15 , V_65 , V_25 , V_69 ) ;
F_246 ( V_15 , V_74 , V_25 , & V_76 ) ;
}
V_255:
V_74 -> V_12 -= V_65 -> V_68 ;
V_254:
F_51 ( & V_74 -> V_11 ) ;
F_248 ( V_15 , & V_76 ) ;
V_253:
if ( F_76 ( ! V_65 -> V_68 ) ) {
if ( F_138 () ) {
void * V_24 = F_256 ( V_15 , V_74 , V_17 ) ;
if ( V_24 )
return V_24 ;
}
V_25 = F_239 ( V_15 , F_60 ( V_17 ) , V_57 ) ;
V_65 = F_19 ( V_15 ) ;
if ( ! V_65 -> V_68 && V_25 )
F_258 ( V_15 , V_65 , V_25 , V_69 ) ;
F_244 ( V_15 , V_25 ) ;
if ( ! V_65 -> V_68 )
return NULL ;
}
V_65 -> V_70 = 1 ;
return V_65 -> V_81 [ -- V_65 -> V_68 ] ;
}
static inline void F_264 ( struct V_14 * V_15 ,
T_4 V_17 )
{
F_265 ( F_240 ( V_17 ) ) ;
}
static void * F_266 ( struct V_14 * V_15 ,
T_4 V_17 , void * V_16 , unsigned long V_182 )
{
if ( ! V_16 )
return V_16 ;
if ( V_15 -> V_17 & V_196 ) {
F_168 ( V_15 , V_16 ) ;
F_161 ( V_15 , V_16 , 1 , 0 ) ;
F_163 ( V_15 , V_16 , V_256 ) ;
}
if ( V_15 -> V_17 & V_19 )
* F_8 ( V_15 , V_16 ) = ( void * ) V_182 ;
if ( V_15 -> V_17 & V_18 ) {
if ( * F_5 ( V_15 , V_16 ) != V_198 ||
* F_7 ( V_15 , V_16 ) != V_198 ) {
F_172 ( V_15 , L_28 ) ;
F_23 ( L_27 ,
V_16 , * F_5 ( V_15 , V_16 ) ,
* F_7 ( V_15 , V_16 ) ) ;
}
* F_5 ( V_15 , V_16 ) = V_249 ;
* F_7 ( V_15 , V_16 ) = V_249 ;
}
V_16 += F_4 ( V_15 ) ;
if ( V_15 -> V_173 && V_15 -> V_17 & V_196 )
V_15 -> V_173 ( V_16 ) ;
if ( V_257 &&
( ( unsigned long ) V_16 & ( V_257 - 1 ) ) ) {
F_23 ( L_29 ,
V_16 , ( int ) V_257 ) ;
}
return V_16 ;
}
static inline void * F_267 ( struct V_14 * V_15 , T_4 V_17 )
{
void * V_16 ;
struct V_32 * V_65 ;
F_200 () ;
V_65 = F_19 ( V_15 ) ;
if ( F_80 ( V_65 -> V_68 ) ) {
V_65 -> V_70 = 1 ;
V_16 = V_65 -> V_81 [ -- V_65 -> V_68 ] ;
F_268 ( V_15 ) ;
goto V_124;
}
F_269 ( V_15 ) ;
V_16 = F_262 ( V_15 , V_17 ) ;
V_65 = F_19 ( V_15 ) ;
V_124:
if ( V_16 )
F_270 ( & V_65 -> V_81 [ V_65 -> V_68 ] ) ;
return V_16 ;
}
static void * F_58 ( struct V_14 * V_15 , T_4 V_17 )
{
int V_258 , V_259 ;
if ( F_271 () || ( V_17 & V_92 ) )
return NULL ;
V_258 = V_259 = F_79 () ;
if ( F_272 () && ( V_15 -> V_17 & V_260 ) )
V_258 = F_273 () ;
else if ( V_177 -> V_261 )
V_258 = F_274 () ;
if ( V_258 != V_259 )
return F_59 ( V_15 , V_17 , V_258 ) ;
return NULL ;
}
static void * F_275 ( struct V_14 * V_27 , T_4 V_17 )
{
struct V_262 * V_262 ;
struct V_263 * V_264 ;
struct V_265 * V_265 ;
enum V_266 V_267 = F_276 ( V_17 ) ;
void * V_24 = NULL ;
struct V_25 * V_25 ;
int V_122 ;
unsigned int V_268 ;
if ( V_17 & V_92 )
return NULL ;
V_269:
V_268 = F_277 () ;
V_262 = F_278 ( F_274 () , V_17 ) ;
V_270:
F_279 (zone, z, zonelist, high_zoneidx) {
V_122 = F_280 ( V_265 ) ;
if ( F_281 ( V_265 , V_17 ) &&
F_48 ( V_27 , V_122 ) &&
F_48 ( V_27 , V_122 ) -> V_12 ) {
V_24 = F_59 ( V_27 ,
F_60 ( V_17 ) , V_122 ) ;
if ( V_24 )
break;
}
}
if ( ! V_24 ) {
V_25 = F_239 ( V_27 , V_17 , F_79 () ) ;
F_244 ( V_27 , V_25 ) ;
if ( V_25 ) {
V_122 = F_47 ( V_25 ) ;
V_24 = F_59 ( V_27 ,
F_60 ( V_17 ) , V_122 ) ;
if ( ! V_24 )
goto V_270;
}
}
if ( F_76 ( ! V_24 && F_282 ( V_268 ) ) )
goto V_269;
return V_24 ;
}
static void * F_59 ( struct V_14 * V_15 , T_4 V_17 ,
int V_84 )
{
struct V_25 * V_25 ;
struct V_1 * V_74 ;
void * V_24 = NULL ;
void * V_76 = NULL ;
F_283 ( V_84 < 0 || V_84 >= V_271 ) ;
V_74 = F_48 ( V_15 , V_84 ) ;
F_6 ( ! V_74 ) ;
F_200 () ;
F_49 ( & V_74 -> V_11 ) ;
V_25 = F_253 ( V_74 , false ) ;
if ( ! V_25 )
goto V_255;
F_208 ( V_15 , V_84 ) ;
F_284 ( V_15 ) ;
F_260 ( V_15 ) ;
F_261 ( V_15 ) ;
F_6 ( V_25 -> V_229 == V_15 -> V_37 ) ;
V_24 = F_236 ( V_15 , V_25 ) ;
V_74 -> V_12 -- ;
F_246 ( V_15 , V_74 , V_25 , & V_76 ) ;
F_51 ( & V_74 -> V_11 ) ;
F_248 ( V_15 , & V_76 ) ;
return V_24 ;
V_255:
F_51 ( & V_74 -> V_11 ) ;
V_25 = F_239 ( V_15 , F_60 ( V_17 ) , V_84 ) ;
if ( V_25 ) {
V_24 = F_236 ( V_15 , V_25 ) ;
}
F_244 ( V_15 , V_25 ) ;
return V_24 ? V_24 : F_275 ( V_15 , V_17 ) ;
}
static T_9 void *
F_285 ( struct V_14 * V_15 , T_4 V_17 , int V_84 ,
unsigned long V_182 )
{
unsigned long V_272 ;
void * V_131 ;
int V_273 = F_79 () ;
V_17 &= V_274 ;
V_15 = F_286 ( V_15 , V_17 ) ;
if ( F_76 ( ! V_15 ) )
return NULL ;
F_264 ( V_15 , V_17 ) ;
F_287 ( V_272 ) ;
if ( V_84 == V_275 )
V_84 = V_273 ;
if ( F_76 ( ! F_48 ( V_15 , V_84 ) ) ) {
V_131 = F_275 ( V_15 , V_17 ) ;
goto V_124;
}
if ( V_84 == V_273 ) {
V_131 = F_267 ( V_15 , V_17 ) ;
if ( V_131 )
goto V_124;
}
V_131 = F_59 ( V_15 , V_17 , V_84 ) ;
V_124:
F_288 ( V_272 ) ;
V_131 = F_266 ( V_15 , V_17 , V_131 , V_182 ) ;
if ( F_76 ( V_17 & V_276 ) && V_131 )
memset ( V_131 , 0 , V_15 -> V_183 ) ;
F_289 ( V_15 , V_17 , 1 , & V_131 ) ;
return V_131 ;
}
static T_9 void *
F_290 ( struct V_14 * V_27 , T_4 V_17 )
{
void * V_16 ;
if ( V_177 -> V_261 || F_272 () ) {
V_16 = F_58 ( V_27 , V_17 ) ;
if ( V_16 )
goto V_124;
}
V_16 = F_267 ( V_27 , V_17 ) ;
if ( ! V_16 )
V_16 = F_59 ( V_27 , V_17 , F_79 () ) ;
V_124:
return V_16 ;
}
static T_9 void *
F_290 ( struct V_14 * V_15 , T_4 V_17 )
{
return F_267 ( V_15 , V_17 ) ;
}
static T_9 void *
F_291 ( struct V_14 * V_15 , T_4 V_17 , unsigned long V_182 )
{
unsigned long V_272 ;
void * V_16 ;
V_17 &= V_274 ;
V_15 = F_286 ( V_15 , V_17 ) ;
if ( F_76 ( ! V_15 ) )
return NULL ;
F_264 ( V_15 , V_17 ) ;
F_287 ( V_272 ) ;
V_16 = F_290 ( V_15 , V_17 ) ;
F_288 ( V_272 ) ;
V_16 = F_266 ( V_15 , V_17 , V_16 , V_182 ) ;
F_292 ( V_16 ) ;
if ( F_76 ( V_17 & V_276 ) && V_16 )
memset ( V_16 , 0 , V_15 -> V_183 ) ;
F_289 ( V_15 , V_17 , 1 , & V_16 ) ;
return V_16 ;
}
static void F_50 ( struct V_14 * V_15 , void * * V_277 ,
int V_278 , int V_57 , struct V_91 * V_76 )
{
int V_90 ;
struct V_1 * V_74 = F_48 ( V_15 , V_57 ) ;
struct V_25 * V_25 ;
V_74 -> V_12 += V_278 ;
for ( V_90 = 0 ; V_90 < V_278 ; V_90 ++ ) {
void * V_16 ;
struct V_25 * V_25 ;
V_16 = V_277 [ V_90 ] ;
V_25 = F_15 ( V_16 ) ;
F_177 ( & V_25 -> V_135 ) ;
F_208 ( V_15 , V_57 ) ;
F_237 ( V_15 , V_25 , V_16 ) ;
F_293 ( V_15 ) ;
if ( V_25 -> V_229 == 0 ) {
F_114 ( & V_25 -> V_135 , & V_74 -> V_5 ) ;
V_74 -> V_7 ++ ;
} else {
F_245 ( & V_25 -> V_135 , & V_74 -> V_4 ) ;
}
}
while ( V_74 -> V_12 > V_74 -> V_95 && ! F_102 ( & V_74 -> V_5 ) ) {
V_74 -> V_12 -= V_15 -> V_37 ;
V_25 = F_294 ( & V_74 -> V_5 , struct V_25 , V_135 ) ;
F_295 ( & V_25 -> V_135 , V_76 ) ;
V_74 -> V_7 -- ;
V_74 -> V_6 -- ;
}
}
static void F_296 ( struct V_14 * V_15 , struct V_32 * V_65 )
{
int V_69 ;
struct V_1 * V_74 ;
int V_57 = F_79 () ;
F_46 ( V_76 ) ;
V_69 = V_65 -> V_69 ;
F_200 () ;
V_74 = F_48 ( V_15 , V_57 ) ;
F_49 ( & V_74 -> V_11 ) ;
if ( V_74 -> V_8 ) {
struct V_32 * V_279 = V_74 -> V_8 ;
int V_79 = V_279 -> V_66 - V_279 -> V_68 ;
if ( V_79 ) {
if ( V_69 > V_79 )
V_69 = V_79 ;
memcpy ( & ( V_279 -> V_81 [ V_279 -> V_68 ] ) ,
V_65 -> V_81 , sizeof( void * ) * V_69 ) ;
V_279 -> V_68 += V_69 ;
goto V_280;
}
}
F_50 ( V_15 , V_65 -> V_81 , V_69 , V_57 , & V_76 ) ;
V_280:
#if V_281
{
int V_90 = 0 ;
struct V_25 * V_25 ;
F_85 (page, &n->slabs_free, lru) {
F_6 ( V_25 -> V_229 ) ;
V_90 ++ ;
}
F_297 ( V_15 , V_90 ) ;
}
#endif
F_51 ( & V_74 -> V_11 ) ;
F_52 ( V_15 , & V_76 ) ;
V_65 -> V_68 -= V_69 ;
memmove ( V_65 -> V_81 , & ( V_65 -> V_81 [ V_69 ] ) , sizeof( void * ) * V_65 -> V_68 ) ;
}
static inline void F_298 ( struct V_14 * V_15 , void * V_16 ,
unsigned long V_182 )
{
if ( F_299 ( V_15 , V_16 ) )
return;
F_300 ( V_15 , V_16 , V_182 ) ;
}
void F_300 ( struct V_14 * V_15 , void * V_16 ,
unsigned long V_182 )
{
struct V_32 * V_65 = F_19 ( V_15 ) ;
F_200 () ;
F_301 ( V_16 , V_15 -> V_17 ) ;
V_16 = F_252 ( V_15 , V_16 , V_182 ) ;
F_302 ( V_15 , V_16 , V_15 -> V_183 ) ;
if ( V_282 > 1 && F_57 ( V_15 , V_16 ) )
return;
if ( V_65 -> V_68 < V_65 -> V_66 ) {
F_303 ( V_15 ) ;
} else {
F_304 ( V_15 ) ;
F_296 ( V_15 , V_65 ) ;
}
if ( F_138 () ) {
struct V_25 * V_25 = F_15 ( V_16 ) ;
if ( F_76 ( F_305 ( V_25 ) ) ) {
F_45 ( V_15 , V_25 , V_16 ) ;
return;
}
}
V_65 -> V_81 [ V_65 -> V_68 ++ ] = V_16 ;
}
void * F_306 ( struct V_14 * V_15 , T_4 V_17 )
{
void * V_100 = F_291 ( V_15 , V_17 , V_283 ) ;
F_307 ( V_15 , V_100 , V_17 ) ;
F_308 ( V_283 , V_100 ,
V_15 -> V_183 , V_15 -> V_20 , V_17 ) ;
return V_100 ;
}
static T_9 void
F_309 ( struct V_14 * V_48 , T_4 V_17 ,
T_2 V_20 , void * * V_226 , unsigned long V_182 )
{
T_2 V_90 ;
for ( V_90 = 0 ; V_90 < V_20 ; V_90 ++ )
V_226 [ V_90 ] = F_266 ( V_48 , V_17 , V_226 [ V_90 ] , V_182 ) ;
}
int F_310 ( struct V_14 * V_48 , T_4 V_17 , T_2 V_20 ,
void * * V_226 )
{
T_2 V_90 ;
V_48 = F_286 ( V_48 , V_17 ) ;
if ( ! V_48 )
return 0 ;
F_264 ( V_48 , V_17 ) ;
F_243 () ;
for ( V_90 = 0 ; V_90 < V_20 ; V_90 ++ ) {
void * V_16 = F_290 ( V_48 , V_17 ) ;
if ( F_76 ( ! V_16 ) )
goto error;
V_226 [ V_90 ] = V_16 ;
}
F_241 () ;
F_309 ( V_48 , V_17 , V_20 , V_226 , V_283 ) ;
if ( F_76 ( V_17 & V_276 ) )
for ( V_90 = 0 ; V_90 < V_20 ; V_90 ++ )
memset ( V_226 [ V_90 ] , 0 , V_48 -> V_183 ) ;
F_289 ( V_48 , V_17 , V_20 , V_226 ) ;
return V_20 ;
error:
F_241 () ;
F_309 ( V_48 , V_17 , V_90 , V_226 , V_283 ) ;
F_289 ( V_48 , V_17 , V_90 , V_226 ) ;
F_311 ( V_48 , V_90 , V_226 ) ;
return 0 ;
}
void *
F_312 ( struct V_14 * V_15 , T_4 V_17 , T_2 V_20 )
{
void * V_100 ;
V_100 = F_291 ( V_15 , V_17 , V_283 ) ;
F_313 ( V_15 , V_100 , V_20 , V_17 ) ;
F_314 ( V_283 , V_100 ,
V_20 , V_15 -> V_20 , V_17 ) ;
return V_100 ;
}
void * F_220 ( struct V_14 * V_15 , T_4 V_17 , int V_84 )
{
void * V_100 = F_285 ( V_15 , V_17 , V_84 , V_283 ) ;
F_307 ( V_15 , V_100 , V_17 ) ;
F_315 ( V_283 , V_100 ,
V_15 -> V_183 , V_15 -> V_20 ,
V_17 , V_84 ) ;
return V_100 ;
}
void * F_316 ( struct V_14 * V_15 ,
T_4 V_17 ,
int V_84 ,
T_2 V_20 )
{
void * V_100 ;
V_100 = F_285 ( V_15 , V_17 , V_84 , V_283 ) ;
F_313 ( V_15 , V_100 , V_20 , V_17 ) ;
F_317 ( V_283 , V_100 ,
V_20 , V_15 -> V_20 ,
V_17 , V_84 ) ;
return V_100 ;
}
static T_9 void *
F_318 ( T_2 V_20 , T_4 V_17 , int V_57 , unsigned long V_182 )
{
struct V_14 * V_15 ;
void * V_100 ;
V_15 = F_179 ( V_20 , V_17 ) ;
if ( F_76 ( F_319 ( V_15 ) ) )
return V_15 ;
V_100 = F_316 ( V_15 , V_17 , V_57 , V_20 ) ;
F_313 ( V_15 , V_100 , V_20 , V_17 ) ;
return V_100 ;
}
void * F_320 ( T_2 V_20 , T_4 V_17 , int V_57 )
{
return F_318 ( V_20 , V_17 , V_57 , V_283 ) ;
}
void * F_321 ( T_2 V_20 , T_4 V_17 ,
int V_57 , unsigned long V_182 )
{
return F_318 ( V_20 , V_17 , V_57 , V_182 ) ;
}
static T_9 void * F_322 ( T_2 V_20 , T_4 V_17 ,
unsigned long V_182 )
{
struct V_14 * V_15 ;
void * V_100 ;
V_15 = F_179 ( V_20 , V_17 ) ;
if ( F_76 ( F_319 ( V_15 ) ) )
return V_15 ;
V_100 = F_291 ( V_15 , V_17 , V_182 ) ;
F_313 ( V_15 , V_100 , V_20 , V_17 ) ;
F_314 ( V_182 , V_100 ,
V_20 , V_15 -> V_20 , V_17 ) ;
return V_100 ;
}
void * F_323 ( T_2 V_20 , T_4 V_17 )
{
return F_322 ( V_20 , V_17 , V_283 ) ;
}
void * F_324 ( T_2 V_20 , T_4 V_17 , unsigned long V_182 )
{
return F_322 ( V_20 , V_17 , V_182 ) ;
}
void F_175 ( struct V_14 * V_15 , void * V_16 )
{
unsigned long V_17 ;
V_15 = F_325 ( V_15 , V_16 ) ;
if ( ! V_15 )
return;
F_287 ( V_17 ) ;
F_326 ( V_16 , V_15 -> V_183 ) ;
if ( ! ( V_15 -> V_17 & V_284 ) )
F_327 ( V_16 , V_15 -> V_183 ) ;
F_298 ( V_15 , V_16 , V_283 ) ;
F_288 ( V_17 ) ;
F_328 ( V_283 , V_16 ) ;
}
void F_329 ( struct V_14 * V_285 , T_2 V_20 , void * * V_226 )
{
struct V_14 * V_48 ;
T_2 V_90 ;
F_243 () ;
for ( V_90 = 0 ; V_90 < V_20 ; V_90 ++ ) {
void * V_16 = V_226 [ V_90 ] ;
if ( ! V_285 )
V_48 = F_14 ( V_16 ) ;
else
V_48 = F_325 ( V_285 , V_16 ) ;
F_326 ( V_16 , V_48 -> V_183 ) ;
if ( ! ( V_48 -> V_17 & V_284 ) )
F_327 ( V_16 , V_48 -> V_183 ) ;
F_298 ( V_48 , V_16 , V_283 ) ;
}
F_241 () ;
}
void F_65 ( const void * V_16 )
{
struct V_14 * V_286 ;
unsigned long V_17 ;
F_330 ( V_283 , V_16 ) ;
if ( F_76 ( F_319 ( V_16 ) ) )
return;
F_287 ( V_17 ) ;
F_249 ( V_16 ) ;
V_286 = F_14 ( V_16 ) ;
F_326 ( V_16 , V_286 -> V_183 ) ;
F_327 ( V_16 , V_286 -> V_183 ) ;
F_298 ( V_286 , ( void * ) V_16 , V_283 ) ;
F_288 ( V_17 ) ;
}
static int F_331 ( struct V_14 * V_15 , T_4 V_72 )
{
int V_100 ;
int V_57 ;
struct V_1 * V_74 ;
F_71 (node) {
V_100 = F_86 ( V_15 , V_57 , V_72 , true ) ;
if ( V_100 )
goto V_106;
}
return 0 ;
V_106:
if ( ! V_15 -> V_76 . V_250 ) {
V_57 -- ;
while ( V_57 >= 0 ) {
V_74 = F_48 ( V_15 , V_57 ) ;
if ( V_74 ) {
F_65 ( V_74 -> V_8 ) ;
F_56 ( V_74 -> V_9 ) ;
F_65 ( V_74 ) ;
V_15 -> V_57 [ V_57 ] = NULL ;
}
V_57 -- ;
}
}
return - V_96 ;
}
static int F_332 ( struct V_14 * V_15 , int V_66 ,
int V_69 , int V_8 , T_4 V_72 )
{
struct V_32 T_7 * V_33 , * V_227 ;
int V_54 ;
V_33 = F_180 ( V_15 , V_66 , V_69 ) ;
if ( ! V_33 )
return - V_96 ;
V_227 = V_15 -> V_33 ;
V_15 -> V_33 = V_33 ;
F_333 () ;
F_202 () ;
V_15 -> V_69 = V_69 ;
V_15 -> V_66 = V_66 ;
V_15 -> V_8 = V_8 ;
if ( ! V_227 )
goto V_287;
F_334 (cpu) {
F_46 ( V_76 ) ;
int V_57 ;
struct V_1 * V_74 ;
struct V_32 * V_65 = F_90 ( V_227 , V_54 ) ;
V_57 = F_33 ( V_54 ) ;
V_74 = F_48 ( V_15 , V_57 ) ;
F_82 ( & V_74 -> V_11 ) ;
F_50 ( V_15 , V_65 -> V_81 , V_65 -> V_68 , V_57 , & V_76 ) ;
F_69 ( & V_74 -> V_11 ) ;
F_52 ( V_15 , & V_76 ) ;
}
F_217 ( V_227 ) ;
V_287:
return F_331 ( V_15 , V_72 ) ;
}
static int F_335 ( struct V_14 * V_15 , int V_66 ,
int V_69 , int V_8 , T_4 V_72 )
{
int V_100 ;
struct V_14 * V_286 ;
V_100 = F_332 ( V_15 , V_66 , V_69 , V_8 , V_72 ) ;
if ( V_145 < V_155 )
return V_100 ;
if ( ( V_100 < 0 ) || ! F_336 ( V_15 ) )
return V_100 ;
F_337 ( & V_114 ) ;
F_338 (c, cachep) {
F_332 ( V_286 , V_66 , V_69 , V_8 , V_72 ) ;
}
return V_100 ;
}
static int F_120 ( struct V_14 * V_15 , T_4 V_72 )
{
int V_112 ;
int V_66 = 0 ;
int V_8 = 0 ;
int V_69 = 0 ;
V_112 = F_339 ( V_15 , V_15 -> V_37 , V_72 ) ;
if ( V_112 )
goto V_288;
if ( ! F_336 ( V_15 ) ) {
struct V_14 * V_289 = F_340 ( V_15 ) ;
V_66 = V_289 -> V_66 ;
V_8 = V_289 -> V_8 ;
V_69 = V_289 -> V_69 ;
}
if ( V_66 && V_8 && V_69 )
goto V_290;
if ( V_15 -> V_20 > 131072 )
V_66 = 1 ;
else if ( V_15 -> V_20 > V_39 )
V_66 = 8 ;
else if ( V_15 -> V_20 > 1024 )
V_66 = 24 ;
else if ( V_15 -> V_20 > 256 )
V_66 = 54 ;
else
V_66 = 120 ;
V_8 = 0 ;
if ( V_15 -> V_20 <= V_39 && F_341 () > 1 )
V_8 = 8 ;
#if V_159
if ( V_66 > 32 )
V_66 = 32 ;
#endif
V_69 = ( V_66 + 1 ) / 2 ;
V_290:
V_112 = F_335 ( V_15 , V_66 , V_69 , V_8 , V_72 ) ;
V_288:
if ( V_112 )
F_23 ( L_30 ,
V_15 -> V_45 , - V_112 ) ;
return V_112 ;
}
static void F_342 ( struct V_14 * V_15 , struct V_1 * V_74 ,
struct V_32 * V_65 , int V_57 )
{
F_46 ( V_76 ) ;
F_203 () ;
if ( ! V_65 || ! V_65 -> V_68 )
return;
if ( V_65 -> V_70 ) {
V_65 -> V_70 = 0 ;
return;
}
F_82 ( & V_74 -> V_11 ) ;
F_209 ( V_15 , V_65 , V_57 , false , & V_76 ) ;
F_69 ( & V_74 -> V_11 ) ;
F_52 ( V_15 , & V_76 ) ;
}
static void V_63 ( struct V_291 * V_292 )
{
struct V_14 * V_293 ;
struct V_1 * V_74 ;
int V_57 = F_79 () ;
struct V_58 * V_61 = F_343 ( V_292 ) ;
if ( ! F_344 ( & V_114 ) )
goto V_124;
F_85 (searchp, &slab_caches, list) {
F_202 () ;
V_74 = F_48 ( V_293 , V_57 ) ;
F_67 ( V_293 , V_74 ) ;
F_342 ( V_293 , V_74 , F_19 ( V_293 ) , V_57 ) ;
if ( F_345 ( V_74 -> V_97 , V_98 ) )
goto V_250;
V_74 -> V_97 = V_98 + V_99 ;
F_342 ( V_293 , V_74 , V_74 -> V_8 , V_57 ) ;
if ( V_74 -> V_13 )
V_74 -> V_13 = 0 ;
else {
int V_294 ;
V_294 = F_92 ( V_293 , V_74 , ( V_74 -> V_95 +
5 * V_293 -> V_37 - 1 ) / ( 5 * V_293 -> V_37 ) ) ;
F_346 ( V_293 , V_294 ) ;
}
V_250:
F_347 () ;
}
F_202 () ;
F_96 ( & V_114 ) ;
F_34 () ;
V_124:
F_348 ( V_61 , F_349 ( V_295 ) ) ;
}
void F_350 ( struct V_14 * V_15 , struct V_296 * V_297 )
{
unsigned long V_298 , V_299 , V_300 ;
unsigned long V_6 = 0 , V_163 = 0 , V_301 = 0 ;
unsigned long V_7 = 0 ;
int V_57 ;
struct V_1 * V_74 ;
F_130 (cachep, node, n) {
F_202 () ;
F_82 ( & V_74 -> V_11 ) ;
V_6 += V_74 -> V_6 ;
V_7 += V_74 -> V_7 ;
V_163 += V_74 -> V_12 ;
if ( V_74 -> V_8 )
V_301 += V_74 -> V_8 -> V_68 ;
F_69 ( & V_74 -> V_11 ) ;
}
V_299 = V_6 * V_15 -> V_37 ;
V_300 = V_6 - V_7 ;
V_298 = V_299 - V_163 ;
V_297 -> V_298 = V_298 ;
V_297 -> V_299 = V_299 ;
V_297 -> V_300 = V_300 ;
V_297 -> V_302 = V_6 ;
V_297 -> V_301 = V_301 ;
V_297 -> V_66 = V_15 -> V_66 ;
V_297 -> V_69 = V_15 -> V_69 ;
V_297 -> V_8 = V_15 -> V_8 ;
V_297 -> V_303 = V_15 -> V_37 ;
V_297 -> V_304 = V_15 -> V_34 ;
}
void F_351 ( struct V_305 * V_306 , struct V_14 * V_15 )
{
#if V_281
{
unsigned long V_307 = V_15 -> V_308 ;
unsigned long V_309 = V_15 -> V_310 ;
unsigned long V_311 = V_15 -> V_311 ;
unsigned long V_312 = V_15 -> V_312 ;
unsigned long V_313 = V_15 -> V_313 ;
unsigned long V_314 = V_15 -> V_314 ;
unsigned long V_315 = V_15 -> V_315 ;
unsigned long V_316 = V_15 -> V_316 ;
unsigned long V_317 = V_15 -> V_318 ;
F_352 ( V_306 , L_31 ,
V_309 , V_307 , V_311 ,
V_312 , V_313 , V_314 , V_315 ,
V_316 , V_317 ) ;
}
{
unsigned long V_319 = F_10 ( & V_15 -> V_319 ) ;
unsigned long V_320 = F_10 ( & V_15 -> V_320 ) ;
unsigned long V_321 = F_10 ( & V_15 -> V_321 ) ;
unsigned long V_322 = F_10 ( & V_15 -> V_322 ) ;
F_352 ( V_306 , L_32 ,
V_319 , V_320 , V_321 , V_322 ) ;
}
#endif
}
T_10 F_353 ( struct V_323 * V_323 , const char T_11 * V_324 ,
T_2 V_232 , T_12 * V_325 )
{
char V_326 [ V_327 + 1 ] , * V_328 ;
int V_66 , V_69 , V_8 , V_329 ;
struct V_14 * V_15 ;
if ( V_232 > V_327 )
return - V_330 ;
if ( F_354 ( & V_326 , V_324 , V_232 ) )
return - V_331 ;
V_326 [ V_327 ] = '\0' ;
V_328 = strchr ( V_326 , ' ' ) ;
if ( ! V_328 )
return - V_330 ;
* V_328 = '\0' ;
V_328 ++ ;
if ( sscanf ( V_328 , L_33 , & V_66 , & V_69 , & V_8 ) != 3 )
return - V_330 ;
F_95 ( & V_114 ) ;
V_329 = - V_330 ;
F_85 (cachep, &slab_caches, list) {
if ( ! strcmp ( V_15 -> V_45 , V_326 ) ) {
if ( V_66 < 1 || V_69 < 1 ||
V_69 > V_66 || V_8 < 0 ) {
V_329 = 0 ;
} else {
V_329 = F_335 ( V_15 , V_66 ,
V_69 , V_8 ,
V_101 ) ;
}
break;
}
}
F_96 ( & V_114 ) ;
if ( V_329 >= 0 )
V_329 = V_232 ;
return V_329 ;
}
static inline int F_355 ( unsigned long * V_74 , unsigned long V_332 )
{
unsigned long * V_226 ;
int V_333 ;
if ( ! V_332 )
return 1 ;
V_333 = V_74 [ 1 ] ;
V_226 = V_74 + 2 ;
while ( V_333 ) {
int V_90 = V_333 / 2 ;
unsigned long * V_334 = V_226 + 2 * V_90 ;
if ( * V_334 == V_332 ) {
V_334 [ 1 ] ++ ;
return 1 ;
}
if ( * V_334 > V_332 ) {
V_333 = V_90 ;
} else {
V_226 = V_334 + 2 ;
V_333 -= V_90 + 1 ;
}
}
if ( ++ V_74 [ 1 ] == V_74 [ 0 ] )
return 0 ;
memmove ( V_226 + 2 , V_226 , V_74 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_226 - ( void * ) V_74 ) ) ;
V_226 [ 0 ] = V_332 ;
V_226 [ 1 ] = 1 ;
return 1 ;
}
static void F_356 ( unsigned long * V_74 , struct V_14 * V_286 ,
struct V_25 * V_25 )
{
void * V_226 ;
int V_90 , V_335 ;
unsigned long V_332 ;
if ( V_74 [ 0 ] == V_74 [ 1 ] )
return;
for ( V_90 = 0 , V_226 = V_25 -> V_29 ; V_90 < V_286 -> V_37 ; V_90 ++ , V_226 += V_286 -> V_20 ) {
bool V_229 = true ;
for ( V_335 = V_25 -> V_229 ; V_335 < V_286 -> V_37 ; V_335 ++ ) {
if ( F_221 ( V_25 , V_335 ) == V_90 ) {
V_229 = false ;
break;
}
}
if ( ! V_229 )
continue;
if ( F_357 ( & V_332 , F_8 ( V_286 , V_226 ) , sizeof( V_332 ) ) )
continue;
if ( ! F_355 ( V_74 , V_332 ) )
return;
}
}
static void F_358 ( struct V_305 * V_306 , unsigned long V_336 )
{
#ifdef F_359
unsigned long V_30 , V_20 ;
char V_337 [ V_338 ] , V_45 [ V_339 ] ;
if ( F_360 ( V_336 , & V_20 , & V_30 , V_337 , V_45 ) == 0 ) {
F_352 ( V_306 , L_34 , V_45 , V_30 , V_20 ) ;
if ( V_337 [ 0 ] )
F_352 ( V_306 , L_35 , V_337 ) ;
return;
}
#endif
F_352 ( V_306 , L_36 , ( void * ) V_336 ) ;
}
static int F_361 ( struct V_305 * V_306 , void * V_226 )
{
struct V_14 * V_15 = F_213 ( V_226 , struct V_14 , V_76 ) ;
struct V_25 * V_25 ;
struct V_1 * V_74 ;
const char * V_45 ;
unsigned long * V_340 = V_306 -> V_341 ;
int V_57 ;
int V_90 ;
if ( ! ( V_15 -> V_17 & V_19 ) )
return 0 ;
if ( ! ( V_15 -> V_17 & V_18 ) )
return 0 ;
do {
F_11 ( V_15 ) ;
F_211 ( V_15 ) ;
V_340 [ 1 ] = 0 ;
F_130 (cachep, node, n) {
F_202 () ;
F_82 ( & V_74 -> V_11 ) ;
F_85 (page, &n->slabs_full, lru)
F_356 ( V_340 , V_15 , V_25 ) ;
F_85 (page, &n->slabs_partial, lru)
F_356 ( V_340 , V_15 , V_25 ) ;
F_69 ( & V_74 -> V_11 ) ;
}
} while ( ! F_9 ( V_15 ) );
V_45 = V_15 -> V_45 ;
if ( V_340 [ 0 ] == V_340 [ 1 ] ) {
F_96 ( & V_114 ) ;
V_306 -> V_341 = F_362 ( V_340 [ 0 ] * 4 * sizeof( unsigned long ) , V_101 ) ;
if ( ! V_306 -> V_341 ) {
V_306 -> V_341 = V_340 ;
F_95 ( & V_114 ) ;
return - V_96 ;
}
* ( unsigned long * ) V_306 -> V_341 = V_340 [ 0 ] * 2 ;
F_65 ( V_340 ) ;
F_95 ( & V_114 ) ;
V_306 -> V_232 = V_306 -> V_20 ;
return 0 ;
}
for ( V_90 = 0 ; V_90 < V_340 [ 1 ] ; V_90 ++ ) {
F_352 ( V_306 , L_37 , V_45 , V_340 [ 2 * V_90 + 3 ] ) ;
F_358 ( V_306 , V_340 [ 2 * V_90 + 2 ] ) ;
F_363 ( V_306 , '\n' ) ;
}
return 0 ;
}
static int F_364 ( struct V_342 * V_342 , struct V_323 * V_323 )
{
unsigned long * V_74 ;
V_74 = F_365 ( V_323 , & V_343 , V_39 ) ;
if ( ! V_74 )
return - V_96 ;
* V_74 = V_39 / ( 2 * sizeof( unsigned long ) ) ;
return 0 ;
}
static int T_3 F_366 ( void )
{
#ifdef F_367
F_368 ( L_38 , 0 , NULL , & V_344 ) ;
#endif
return 0 ;
}
const char * F_369 ( const void * V_131 , unsigned long V_74 ,
struct V_25 * V_25 )
{
struct V_14 * V_15 ;
unsigned int V_195 ;
unsigned long V_30 ;
V_15 = V_25 -> V_26 ;
V_195 = F_17 ( V_15 , V_25 , ( void * ) V_131 ) ;
F_6 ( V_195 >= V_15 -> V_37 ) ;
V_30 = V_131 - F_16 ( V_15 , V_25 , V_195 ) - F_4 ( V_15 ) ;
if ( V_30 <= V_15 -> V_183 && V_74 <= V_15 -> V_183 - V_30 )
return NULL ;
return V_15 -> V_45 ;
}
T_2 F_370 ( const void * V_16 )
{
T_2 V_20 ;
F_6 ( ! V_16 ) ;
if ( F_76 ( V_16 == V_345 ) )
return 0 ;
V_20 = F_14 ( V_16 ) -> V_183 ;
F_371 ( V_16 , V_20 ) ;
return V_20 ;
}
