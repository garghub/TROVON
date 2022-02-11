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
}
static int F_4 ( struct V_12 * V_13 )
{
return V_13 -> F_4 ;
}
static unsigned long long * F_5 ( struct V_12 * V_13 , void * V_14 )
{
F_6 ( ! ( V_13 -> V_15 & V_16 ) ) ;
return ( unsigned long long * ) ( V_14 + F_4 ( V_13 ) -
sizeof( unsigned long long ) ) ;
}
static unsigned long long * F_7 ( struct V_12 * V_13 , void * V_14 )
{
F_6 ( ! ( V_13 -> V_15 & V_16 ) ) ;
if ( V_13 -> V_15 & V_17 )
return ( unsigned long long * ) ( V_14 + V_13 -> V_18 -
sizeof( unsigned long long ) -
V_19 ) ;
return ( unsigned long long * ) ( V_14 + V_13 -> V_18 -
sizeof( unsigned long long ) ) ;
}
static void * * F_8 ( struct V_12 * V_13 , void * V_14 )
{
F_6 ( ! ( V_13 -> V_15 & V_17 ) ) ;
return ( void * * ) ( V_14 + V_13 -> V_18 - V_20 ) ;
}
static inline bool F_9 ( struct V_12 * V_13 )
{
return F_10 ( & V_13 -> V_21 ) == 1 ;
}
static inline void F_11 ( struct V_12 * V_13 )
{
F_12 ( & V_13 -> V_21 , 1 ) ;
}
static inline void F_13 ( struct V_12 * V_13 )
{
if ( F_9 ( V_13 ) )
F_12 ( & V_13 -> V_21 , 0 ) ;
}
static inline void F_13 ( struct V_12 * V_13 ) {}
static inline struct V_12 * F_14 ( const void * V_22 )
{
struct V_23 * V_23 = F_15 ( V_22 ) ;
return V_23 -> V_24 ;
}
static inline void * F_16 ( struct V_12 * V_25 , struct V_23 * V_23 ,
unsigned int V_26 )
{
return V_23 -> V_27 + V_25 -> V_18 * V_26 ;
}
static inline unsigned int F_17 ( const struct V_12 * V_25 ,
const struct V_23 * V_23 , void * V_22 )
{
T_1 V_28 = ( V_22 - V_23 -> V_27 ) ;
return F_18 ( V_28 , V_25 -> V_29 ) ;
}
static inline struct V_30 * F_19 ( struct V_12 * V_13 )
{
return F_20 ( V_13 -> V_31 ) ;
}
static unsigned int F_21 ( unsigned long V_32 , T_2 V_33 ,
unsigned long V_15 , T_2 * V_34 )
{
unsigned int V_35 ;
T_2 V_36 = V_37 << V_32 ;
if ( V_15 & ( V_38 | V_39 ) ) {
V_35 = V_36 / V_33 ;
* V_34 = V_36 % V_33 ;
} else {
V_35 = V_36 / ( V_33 + sizeof( V_40 ) ) ;
* V_34 = V_36 %
( V_33 + sizeof( V_40 ) ) ;
}
return V_35 ;
}
static void F_22 ( const char * V_41 , struct V_12 * V_13 ,
char * V_42 )
{
F_23 ( L_1 ,
V_41 , V_13 -> V_43 , V_42 ) ;
F_24 () ;
F_25 ( V_44 , V_45 ) ;
}
static int T_3 F_26 ( char * V_46 )
{
V_47 = 0 ;
return 1 ;
}
static int T_3 F_27 ( char * V_48 )
{
F_28 ( & V_48 , & V_49 ) ;
V_49 = V_49 < 0 ? 0 :
F_29 ( V_49 , V_50 - 1 ) ;
V_51 = true ;
return 1 ;
}
static void F_30 ( int V_52 )
{
F_31 ( V_53 , V_52 ) = F_32 ( F_33 ( V_52 ) ,
V_54 ) ;
}
static void F_34 ( void )
{
int V_55 = F_35 ( V_53 ) ;
V_55 = F_32 ( V_55 , V_54 ) ;
F_36 ( V_53 , V_55 ) ;
}
static void F_37 ( int V_52 )
{
struct V_56 * V_57 = & F_31 ( V_58 , V_52 ) ;
if ( F_38 () && V_57 -> V_59 . V_60 == NULL ) {
F_30 ( V_52 ) ;
F_39 ( V_57 , V_61 ) ;
F_40 ( V_52 , V_57 ,
F_41 ( V_62 , V_52 ) ) ;
}
}
static void F_42 ( struct V_30 * V_63 , int V_64 , int V_65 )
{
F_43 ( V_63 ) ;
if ( V_63 ) {
V_63 -> V_66 = 0 ;
V_63 -> V_64 = V_64 ;
V_63 -> V_67 = V_65 ;
V_63 -> V_68 = 0 ;
}
}
static struct V_30 * F_44 ( int V_55 , int V_69 ,
int V_67 , T_4 V_70 )
{
T_2 V_71 = sizeof( void * ) * V_69 + sizeof( struct V_30 ) ;
struct V_30 * V_63 = NULL ;
V_63 = F_45 ( V_71 , V_70 , V_55 ) ;
F_42 ( V_63 , V_69 , V_67 ) ;
return V_63 ;
}
static T_5 void F_46 ( struct V_12 * V_13 ,
struct V_23 * V_23 , void * V_14 )
{
struct V_1 * V_72 ;
int V_73 ;
F_47 ( V_74 ) ;
V_73 = F_48 ( V_23 ) ;
V_72 = F_49 ( V_13 , V_73 ) ;
F_50 ( & V_72 -> V_9 ) ;
F_51 ( V_13 , & V_14 , 1 , V_73 , & V_74 ) ;
F_52 ( & V_72 -> V_9 ) ;
F_53 ( V_13 , & V_74 ) ;
}
static int F_54 ( struct V_30 * V_75 ,
struct V_30 * V_76 , unsigned int V_77 )
{
int V_78 = F_55 ( V_76 -> V_66 , V_77 , V_75 -> V_64 - V_75 -> V_66 ) ;
if ( ! V_78 )
return 0 ;
memcpy ( V_75 -> V_79 + V_75 -> V_66 , V_76 -> V_79 + V_76 -> V_66 - V_78 ,
sizeof( void * ) * V_78 ) ;
V_76 -> V_66 -= V_78 ;
V_75 -> V_66 += V_78 ;
return V_78 ;
}
static inline struct V_80 * * F_56 ( int V_55 ,
int V_64 , T_4 V_70 )
{
return NULL ;
}
static inline void F_57 ( struct V_80 * * V_81 )
{
}
static inline int F_58 ( struct V_12 * V_13 , void * V_14 )
{
return 0 ;
}
static inline void * F_59 ( struct V_12 * V_13 ,
T_4 V_15 )
{
return NULL ;
}
static inline void * F_60 ( struct V_12 * V_13 ,
T_4 V_15 , int V_82 )
{
return NULL ;
}
static inline T_4 F_61 ( T_4 V_15 )
{
return V_15 & ~ V_83 ;
}
static struct V_80 * F_62 ( int V_55 , int V_69 ,
int V_65 , T_4 V_70 )
{
T_2 V_71 = sizeof( void * ) * V_69 + sizeof( struct V_80 ) ;
struct V_80 * V_84 = NULL ;
V_84 = F_45 ( V_71 , V_70 , V_55 ) ;
F_42 ( & V_84 -> V_63 , V_69 , V_65 ) ;
F_3 ( & V_84 -> V_85 ) ;
return V_84 ;
}
static struct V_80 * * F_56 ( int V_55 , int V_64 , T_4 V_70 )
{
struct V_80 * * V_86 ;
T_2 V_71 = sizeof( void * ) * V_87 ;
int V_88 ;
if ( V_64 > 1 )
V_64 = 12 ;
V_86 = F_63 ( V_71 , V_70 , V_55 ) ;
if ( ! V_86 )
return NULL ;
F_64 (i) {
if ( V_88 == V_55 || ! F_65 ( V_88 ) )
continue;
V_86 [ V_88 ] = F_62 ( V_55 , V_64 , 0xbaadf00d , V_70 ) ;
if ( ! V_86 [ V_88 ] ) {
for ( V_88 -- ; V_88 >= 0 ; V_88 -- )
F_66 ( V_86 [ V_88 ] ) ;
F_66 ( V_86 ) ;
return NULL ;
}
}
return V_86 ;
}
static void F_57 ( struct V_80 * * V_86 )
{
int V_88 ;
if ( ! V_86 )
return;
F_64 (i)
F_66 ( V_86 [ V_88 ] ) ;
F_66 ( V_86 ) ;
}
static void F_67 ( struct V_12 * V_13 ,
struct V_30 * V_63 , int V_55 ,
struct V_89 * V_74 )
{
struct V_1 * V_72 = F_49 ( V_13 , V_55 ) ;
if ( V_63 -> V_66 ) {
F_50 ( & V_72 -> V_9 ) ;
if ( V_72 -> V_6 )
F_54 ( V_72 -> V_6 , V_63 , V_63 -> V_64 ) ;
F_51 ( V_13 , V_63 -> V_79 , V_63 -> V_66 , V_55 , V_74 ) ;
V_63 -> V_66 = 0 ;
F_52 ( & V_72 -> V_9 ) ;
}
}
static void F_68 ( struct V_12 * V_13 , struct V_1 * V_72 )
{
int V_55 = F_35 ( V_53 ) ;
if ( V_72 -> V_7 ) {
struct V_80 * V_84 = V_72 -> V_7 [ V_55 ] ;
struct V_30 * V_63 ;
if ( V_84 ) {
V_63 = & V_84 -> V_63 ;
if ( V_63 -> V_66 && F_69 ( & V_84 -> V_85 ) ) {
F_47 ( V_74 ) ;
F_67 ( V_13 , V_63 , V_55 , & V_74 ) ;
F_70 ( & V_84 -> V_85 ) ;
F_53 ( V_13 , & V_74 ) ;
}
}
}
}
static void F_71 ( struct V_12 * V_13 ,
struct V_80 * * V_7 )
{
int V_88 = 0 ;
struct V_80 * V_84 ;
struct V_30 * V_63 ;
unsigned long V_15 ;
F_72 (i) {
V_84 = V_7 [ V_88 ] ;
if ( V_84 ) {
F_47 ( V_74 ) ;
V_63 = & V_84 -> V_63 ;
F_73 ( & V_84 -> V_85 , V_15 ) ;
F_67 ( V_13 , V_63 , V_88 , & V_74 ) ;
F_74 ( & V_84 -> V_85 , V_15 ) ;
F_53 ( V_13 , & V_74 ) ;
}
}
}
static int F_75 ( struct V_12 * V_13 , void * V_14 ,
int V_55 , int V_73 )
{
struct V_1 * V_72 ;
struct V_80 * V_7 = NULL ;
struct V_30 * V_63 ;
F_47 ( V_74 ) ;
V_72 = F_49 ( V_13 , V_55 ) ;
F_76 ( V_13 ) ;
if ( V_72 -> V_7 && V_72 -> V_7 [ V_73 ] ) {
V_7 = V_72 -> V_7 [ V_73 ] ;
V_63 = & V_7 -> V_63 ;
F_50 ( & V_7 -> V_85 ) ;
if ( F_77 ( V_63 -> V_66 == V_63 -> V_64 ) ) {
F_78 ( V_13 ) ;
F_67 ( V_13 , V_63 , V_73 , & V_74 ) ;
}
V_63 -> V_79 [ V_63 -> V_66 ++ ] = V_14 ;
F_52 ( & V_7 -> V_85 ) ;
F_53 ( V_13 , & V_74 ) ;
} else {
V_72 = F_49 ( V_13 , V_73 ) ;
F_50 ( & V_72 -> V_9 ) ;
F_51 ( V_13 , & V_14 , 1 , V_73 , & V_74 ) ;
F_52 ( & V_72 -> V_9 ) ;
F_53 ( V_13 , & V_74 ) ;
}
return 1 ;
}
static inline int F_58 ( struct V_12 * V_13 , void * V_14 )
{
int V_73 = F_48 ( F_79 ( V_14 ) ) ;
int V_55 = F_80 () ;
if ( F_81 ( V_55 == V_73 ) )
return 0 ;
return F_75 ( V_13 , V_14 , V_55 , V_73 ) ;
}
static inline T_4 F_61 ( T_4 V_15 )
{
return ( V_15 | V_90 | V_91 ) & ~ ( V_92 | V_83 ) ;
}
static int F_82 ( struct V_12 * V_13 , int V_55 , T_4 V_70 )
{
struct V_1 * V_72 ;
V_72 = F_49 ( V_13 , V_55 ) ;
if ( V_72 ) {
F_83 ( & V_72 -> V_9 ) ;
V_72 -> V_93 = ( 1 + F_84 ( V_55 ) ) * V_13 -> V_67 +
V_13 -> V_35 ;
F_70 ( & V_72 -> V_9 ) ;
return 0 ;
}
V_72 = F_45 ( sizeof( struct V_1 ) , V_70 , V_55 ) ;
if ( ! V_72 )
return - V_94 ;
F_1 ( V_72 ) ;
V_72 -> V_95 = V_96 + V_97 +
( ( unsigned long ) V_13 ) % V_97 ;
V_72 -> V_93 =
( 1 + F_84 ( V_55 ) ) * V_13 -> V_67 + V_13 -> V_35 ;
V_13 -> V_55 [ V_55 ] = V_72 ;
return 0 ;
}
static int F_85 ( int V_55 )
{
int V_98 ;
struct V_12 * V_13 ;
F_86 (cachep, &slab_caches, list) {
V_98 = F_82 ( V_13 , V_55 , V_99 ) ;
if ( V_98 )
return V_98 ;
}
return 0 ;
}
static int F_87 ( struct V_12 * V_13 ,
int V_55 , T_4 V_70 , bool V_100 )
{
int V_98 = - V_94 ;
struct V_1 * V_72 ;
struct V_30 * V_101 = NULL ;
struct V_30 * V_102 = NULL ;
struct V_80 * * V_103 = NULL ;
F_47 ( V_74 ) ;
if ( V_47 ) {
V_103 = F_56 ( V_55 , V_13 -> V_64 , V_70 ) ;
if ( ! V_103 )
goto V_104;
}
if ( V_13 -> V_6 ) {
V_102 = F_44 ( V_55 ,
V_13 -> V_6 * V_13 -> V_67 , 0xbaadf00d , V_70 ) ;
if ( ! V_102 )
goto V_104;
}
V_98 = F_82 ( V_13 , V_55 , V_70 ) ;
if ( V_98 )
goto V_104;
V_72 = F_49 ( V_13 , V_55 ) ;
F_83 ( & V_72 -> V_9 ) ;
if ( V_72 -> V_6 && V_100 ) {
F_51 ( V_13 , V_72 -> V_6 -> V_79 ,
V_72 -> V_6 -> V_66 , V_55 , & V_74 ) ;
V_72 -> V_6 -> V_66 = 0 ;
}
if ( ! V_72 -> V_6 || V_100 ) {
V_101 = V_72 -> V_6 ;
V_72 -> V_6 = V_102 ;
V_102 = NULL ;
}
if ( ! V_72 -> V_7 ) {
V_72 -> V_7 = V_103 ;
V_103 = NULL ;
}
F_70 ( & V_72 -> V_9 ) ;
F_53 ( V_13 , & V_74 ) ;
if ( V_100 )
F_88 () ;
V_104:
F_66 ( V_101 ) ;
F_66 ( V_102 ) ;
F_57 ( V_103 ) ;
return V_98 ;
}
static void F_89 ( long V_52 )
{
struct V_12 * V_13 ;
struct V_1 * V_72 = NULL ;
int V_55 = F_33 ( V_52 ) ;
const struct V_105 * V_106 = F_90 ( V_55 ) ;
F_86 (cachep, &slab_caches, list) {
struct V_30 * V_107 ;
struct V_30 * V_6 ;
struct V_80 * * V_7 ;
F_47 ( V_74 ) ;
V_72 = F_49 ( V_13 , V_55 ) ;
if ( ! V_72 )
continue;
F_83 ( & V_72 -> V_9 ) ;
V_72 -> V_93 -= V_13 -> V_67 ;
V_107 = F_91 ( V_13 -> V_31 , V_52 ) ;
if ( V_107 ) {
F_51 ( V_13 , V_107 -> V_79 , V_107 -> V_66 , V_55 , & V_74 ) ;
V_107 -> V_66 = 0 ;
}
if ( ! F_92 ( V_106 ) ) {
F_70 ( & V_72 -> V_9 ) ;
goto V_108;
}
V_6 = V_72 -> V_6 ;
if ( V_6 ) {
F_51 ( V_13 , V_6 -> V_79 ,
V_6 -> V_66 , V_55 , & V_74 ) ;
V_72 -> V_6 = NULL ;
}
V_7 = V_72 -> V_7 ;
V_72 -> V_7 = NULL ;
F_70 ( & V_72 -> V_9 ) ;
F_66 ( V_6 ) ;
if ( V_7 ) {
F_71 ( V_13 , V_7 ) ;
F_57 ( V_7 ) ;
}
V_108:
F_53 ( V_13 , & V_74 ) ;
}
F_86 (cachep, &slab_caches, list) {
V_72 = F_49 ( V_13 , V_55 ) ;
if ( ! V_72 )
continue;
F_93 ( V_13 , V_72 , V_109 ) ;
}
}
static int F_94 ( long V_52 )
{
struct V_12 * V_13 ;
int V_55 = F_33 ( V_52 ) ;
int V_110 ;
V_110 = F_85 ( V_55 ) ;
if ( V_110 < 0 )
goto V_111;
F_86 (cachep, &slab_caches, list) {
V_110 = F_87 ( V_13 , V_55 , V_99 , false ) ;
if ( V_110 )
goto V_111;
}
return 0 ;
V_111:
F_89 ( V_52 ) ;
return - V_94 ;
}
static int F_95 ( struct V_112 * V_113 ,
unsigned long V_114 , void * V_115 )
{
long V_52 = ( long ) V_115 ;
int V_110 = 0 ;
switch ( V_114 ) {
case V_116 :
case V_117 :
F_96 ( & V_118 ) ;
V_110 = F_94 ( V_52 ) ;
F_97 ( & V_118 ) ;
break;
case V_119 :
case V_120 :
F_37 ( V_52 ) ;
break;
#ifdef F_98
case V_121 :
case V_122 :
F_99 ( & F_31 ( V_58 , V_52 ) ) ;
F_31 ( V_58 , V_52 ) . V_59 . V_60 = NULL ;
break;
case V_123 :
case V_124 :
F_37 ( V_52 ) ;
break;
case V_125 :
case V_126 :
#endif
case V_127 :
case V_128 :
F_96 ( & V_118 ) ;
F_89 ( V_52 ) ;
F_97 ( & V_118 ) ;
break;
}
return F_100 ( V_110 ) ;
}
static int T_6 F_101 ( int V_55 )
{
struct V_12 * V_13 ;
int V_98 = 0 ;
F_86 (cachep, &slab_caches, list) {
struct V_1 * V_72 ;
V_72 = F_49 ( V_13 , V_55 ) ;
if ( ! V_72 )
continue;
F_93 ( V_13 , V_72 , V_109 ) ;
if ( ! F_102 ( & V_72 -> V_3 ) ||
! F_102 ( & V_72 -> V_4 ) ) {
V_98 = - V_129 ;
break;
}
}
return V_98 ;
}
static int T_6 F_103 ( struct V_112 * V_130 ,
unsigned long V_114 , void * V_131 )
{
struct V_132 * V_133 = V_131 ;
int V_98 = 0 ;
int V_134 ;
V_134 = V_133 -> V_135 ;
if ( V_134 < 0 )
goto V_136;
switch ( V_114 ) {
case V_137 :
F_96 ( & V_118 ) ;
V_98 = F_85 ( V_134 ) ;
F_97 ( & V_118 ) ;
break;
case V_138 :
F_96 ( & V_118 ) ;
V_98 = F_101 ( V_134 ) ;
F_97 ( & V_118 ) ;
break;
case V_139 :
case V_140 :
case V_141 :
case V_142 :
break;
}
V_136:
return F_100 ( V_98 ) ;
}
static void T_3 F_104 ( struct V_12 * V_13 , struct V_1 * V_74 ,
int V_82 )
{
struct V_1 * V_143 ;
V_143 = F_45 ( sizeof( struct V_1 ) , V_144 , V_82 ) ;
F_6 ( ! V_143 ) ;
memcpy ( V_143 , V_74 , sizeof( struct V_1 ) ) ;
F_3 ( & V_143 -> V_9 ) ;
F_105 ( V_13 , V_143 , V_82 ) ;
V_13 -> V_55 [ V_82 ] = V_143 ;
}
static void T_3 F_106 ( struct V_12 * V_13 , int V_145 )
{
int V_55 ;
F_72 (node) {
V_13 -> V_55 [ V_55 ] = & V_146 [ V_145 + V_55 ] ;
V_13 -> V_55 [ V_55 ] -> V_95 = V_96 +
V_97 +
( ( unsigned long ) V_13 ) % V_97 ;
}
}
static void F_107 ( struct V_147 * V_148 , V_40 * V_74 ,
T_2 V_149 )
{
T_2 V_88 ;
unsigned int rand ;
for ( V_88 = 0 ; V_88 < V_149 ; V_88 ++ )
V_74 [ V_88 ] = V_88 ;
for ( V_88 = V_149 - 1 ; V_88 > 0 ; V_88 -- ) {
rand = F_108 ( V_148 ) ;
rand %= ( V_88 + 1 ) ;
F_109 ( V_74 [ V_88 ] , V_74 [ rand ] ) ;
}
}
static int F_110 ( struct V_12 * V_13 , T_4 V_70 )
{
unsigned int V_150 , V_149 = V_13 -> V_35 ;
struct V_147 V_148 ;
if ( V_149 < 2 )
return 0 ;
V_13 -> V_151 = F_111 ( V_149 , sizeof( V_40 ) , V_70 ) ;
if ( ! V_13 -> V_151 )
return - V_94 ;
F_112 ( & V_150 , sizeof( V_150 ) ) ;
F_113 ( & V_148 , V_150 ) ;
F_107 ( & V_148 , V_13 -> V_151 , V_149 ) ;
return 0 ;
}
static void F_114 ( struct V_12 * V_13 )
{
F_66 ( V_13 -> V_151 ) ;
V_13 -> V_151 = NULL ;
}
static inline int F_110 ( struct V_12 * V_13 , T_4 V_70 )
{
return 0 ;
}
static inline void F_114 ( struct V_12 * V_13 ) { }
void T_3 F_115 ( void )
{
int V_88 ;
F_116 ( sizeof( ( (struct V_23 * ) NULL ) -> V_152 ) <
sizeof( struct V_153 ) ) ;
V_12 = & V_154 ;
if ( ! F_117 ( V_155 ) || F_118 () == 1 )
V_47 = 0 ;
for ( V_88 = 0 ; V_88 < V_156 ; V_88 ++ )
F_1 ( & V_146 [ V_88 ] ) ;
if ( ! V_51 && V_157 > ( 32 << 20 ) >> V_158 )
V_49 = V_159 ;
F_119 ( V_12 , L_2 ,
F_120 ( struct V_12 , V_55 ) +
V_87 * sizeof( struct V_1 * ) ,
V_160 ) ;
F_121 ( & V_12 -> V_74 , & V_161 ) ;
V_162 = V_163 ;
V_164 [ V_165 ] = F_122 ( L_3 ,
F_123 ( V_165 ) , V_166 ) ;
V_162 = V_167 ;
F_124 () ;
V_168 = 0 ;
{
int V_134 ;
F_72 (nid) {
F_104 ( V_12 , & V_146 [ V_169 + V_134 ] , V_134 ) ;
F_104 ( V_164 [ V_165 ] ,
& V_146 [ V_170 + V_134 ] , V_134 ) ;
}
}
F_125 ( V_166 ) ;
}
void T_3 F_126 ( void )
{
struct V_12 * V_13 ;
V_162 = V_171 ;
F_96 ( & V_118 ) ;
F_86 (cachep, &slab_caches, list)
if ( F_127 ( V_13 , V_144 ) )
F_128 () ;
F_97 ( & V_118 ) ;
V_162 = V_172 ;
F_129 ( & V_173 ) ;
#ifdef V_155
F_130 ( F_103 , V_174 ) ;
#endif
}
static int T_3 F_131 ( void )
{
int V_52 ;
F_132 (cpu)
F_37 ( V_52 ) ;
V_162 = V_172 ;
return 0 ;
}
static T_5 void
F_133 ( struct V_12 * V_13 , T_4 V_175 , int V_82 )
{
#if V_176
struct V_1 * V_72 ;
struct V_23 * V_23 ;
unsigned long V_15 ;
int V_55 ;
static F_134 ( V_177 , V_178 ,
V_179 ) ;
if ( ( V_175 & V_91 ) || ! F_135 ( & V_177 ) )
return;
F_136 ( L_4 ,
V_82 , V_175 , & V_175 ) ;
F_136 ( L_5 ,
V_13 -> V_43 , V_13 -> V_18 , V_13 -> V_32 ) ;
F_137 (cachep, node, n) {
unsigned long V_180 = 0 , V_181 = 0 , V_10 = 0 ;
unsigned long V_182 = 0 , V_183 = 0 ;
F_73 ( & V_72 -> V_9 , V_15 ) ;
F_86 (page, &n->slabs_full, lru) {
V_180 += V_13 -> V_35 ;
V_182 ++ ;
}
F_86 (page, &n->slabs_partial, lru) {
V_180 += V_23 -> V_184 ;
V_182 ++ ;
}
F_86 (page, &n->slabs_free, lru)
V_183 ++ ;
V_10 += V_72 -> V_10 ;
F_74 ( & V_72 -> V_9 , V_15 ) ;
V_183 += V_182 ;
V_181 = V_183 * V_13 -> V_35 ;
F_136 ( L_6 ,
V_55 , V_182 , V_183 , V_180 , V_181 ,
V_10 ) ;
}
#endif
}
static struct V_23 * F_138 ( struct V_12 * V_13 , T_4 V_15 ,
int V_82 )
{
struct V_23 * V_23 ;
int V_185 ;
V_15 |= V_13 -> V_186 ;
if ( V_13 -> V_15 & V_187 )
V_15 |= V_188 ;
V_23 = F_139 ( V_82 , V_15 | V_189 , V_13 -> V_32 ) ;
if ( ! V_23 ) {
F_133 ( V_13 , V_15 , V_82 ) ;
return NULL ;
}
if ( F_140 ( V_23 , V_15 , V_13 -> V_32 , V_13 ) ) {
F_141 ( V_23 , V_13 -> V_32 ) ;
return NULL ;
}
V_185 = ( 1 << V_13 -> V_32 ) ;
if ( V_13 -> V_15 & V_187 )
F_142 ( F_143 ( V_23 ) ,
V_190 , V_185 ) ;
else
F_142 ( F_143 ( V_23 ) ,
V_191 , V_185 ) ;
F_144 ( V_23 ) ;
if ( F_145 () && F_146 ( V_23 ) )
F_147 ( V_23 ) ;
if ( V_192 && ! ( V_13 -> V_15 & V_193 ) ) {
F_148 ( V_23 , V_13 -> V_32 , V_15 , V_82 ) ;
if ( V_13 -> V_194 )
F_149 ( V_23 , V_185 ) ;
else
F_150 ( V_23 , V_185 ) ;
}
return V_23 ;
}
static void F_151 ( struct V_12 * V_13 , struct V_23 * V_23 )
{
int V_195 = V_13 -> V_32 ;
unsigned long V_196 = ( 1 << V_195 ) ;
F_152 ( V_23 , V_195 ) ;
if ( V_13 -> V_15 & V_187 )
F_153 ( F_143 ( V_23 ) ,
V_190 , V_196 ) ;
else
F_153 ( F_143 ( V_23 ) ,
V_191 , V_196 ) ;
F_6 ( ! F_154 ( V_23 ) ) ;
F_155 ( V_23 ) ;
F_156 ( V_23 ) ;
F_157 ( V_23 ) ;
V_23 -> V_197 = NULL ;
if ( V_198 -> V_199 )
V_198 -> V_199 -> V_200 += V_196 ;
F_158 ( V_23 , V_195 , V_13 ) ;
F_141 ( V_23 , V_195 ) ;
}
static void F_159 ( struct V_153 * V_201 )
{
struct V_12 * V_13 ;
struct V_23 * V_23 ;
V_23 = F_160 ( V_201 , struct V_23 , V_153 ) ;
V_13 = V_23 -> V_24 ;
F_151 ( V_13 , V_23 ) ;
}
static bool F_161 ( struct V_12 * V_13 )
{
if ( F_162 () && F_163 ( V_13 ) &&
( V_13 -> V_18 % V_37 ) == 0 )
return true ;
return false ;
}
static void F_164 ( struct V_12 * V_13 , unsigned long * V_202 ,
unsigned long V_203 )
{
int V_18 = V_13 -> V_204 ;
V_202 = ( unsigned long * ) & ( ( char * ) V_202 ) [ F_4 ( V_13 ) ] ;
if ( V_18 < 5 * sizeof( unsigned long ) )
return;
* V_202 ++ = 0x12345678 ;
* V_202 ++ = V_203 ;
* V_202 ++ = F_165 () ;
V_18 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_205 = & V_203 ;
unsigned long V_206 ;
while ( ! F_166 ( V_205 ) ) {
V_206 = * V_205 ++ ;
if ( F_167 ( V_206 ) ) {
* V_202 ++ = V_206 ;
V_18 -= sizeof( unsigned long ) ;
if ( V_18 <= sizeof( unsigned long ) )
break;
}
}
}
* V_202 ++ = 0x87654321 ;
}
static void F_168 ( struct V_12 * V_13 , void * V_14 ,
int V_207 , unsigned long V_203 )
{
if ( ! F_161 ( V_13 ) )
return;
if ( V_203 )
F_164 ( V_13 , V_14 , V_203 ) ;
F_169 ( F_79 ( V_14 ) , V_13 -> V_18 / V_37 , V_207 ) ;
}
static inline void F_168 ( struct V_12 * V_13 , void * V_14 ,
int V_207 , unsigned long V_203 ) {}
static void F_170 ( struct V_12 * V_13 , void * V_202 , unsigned char V_208 )
{
int V_18 = V_13 -> V_204 ;
V_202 = & ( ( char * ) V_202 ) [ F_4 ( V_13 ) ] ;
memset ( V_202 , V_208 , V_18 ) ;
* ( unsigned char * ) ( V_202 + V_18 - 1 ) = V_209 ;
}
static void F_171 ( char * V_210 , int V_28 , int V_64 )
{
int V_88 ;
unsigned char error = 0 ;
int V_211 = 0 ;
F_23 ( L_7 , V_28 ) ;
for ( V_88 = 0 ; V_88 < V_64 ; V_88 ++ ) {
if ( V_210 [ V_28 + V_88 ] != V_212 ) {
error = V_210 [ V_28 + V_88 ] ;
V_211 ++ ;
}
}
F_172 ( V_213 , L_8 , 0 , 16 , 1 ,
& V_210 [ V_28 ] , V_64 , 1 ) ;
if ( V_211 == 1 ) {
error ^= V_212 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_23 ( L_9 ) ;
#ifdef F_173
F_23 ( L_10 ) ;
#else
F_23 ( L_11 ) ;
#endif
}
}
}
static void F_174 ( struct V_12 * V_13 , void * V_14 , int V_214 )
{
int V_88 , V_18 ;
char * V_215 ;
if ( V_13 -> V_15 & V_16 ) {
F_23 ( L_12 ,
* F_5 ( V_13 , V_14 ) ,
* F_7 ( V_13 , V_14 ) ) ;
}
if ( V_13 -> V_15 & V_17 ) {
F_23 ( L_13 ,
* F_8 ( V_13 , V_14 ) ,
* F_8 ( V_13 , V_14 ) ) ;
}
V_215 = ( char * ) V_14 + F_4 ( V_13 ) ;
V_18 = V_13 -> V_204 ;
for ( V_88 = 0 ; V_88 < V_18 && V_214 ; V_88 += 16 , V_214 -- ) {
int V_64 ;
V_64 = 16 ;
if ( V_88 + V_64 > V_18 )
V_64 = V_18 - V_88 ;
F_171 ( V_215 , V_88 , V_64 ) ;
}
}
static void F_175 ( struct V_12 * V_13 , void * V_14 )
{
char * V_215 ;
int V_18 , V_88 ;
int V_214 = 0 ;
if ( F_161 ( V_13 ) )
return;
V_215 = ( char * ) V_14 + F_4 ( V_13 ) ;
V_18 = V_13 -> V_204 ;
for ( V_88 = 0 ; V_88 < V_18 ; V_88 ++ ) {
char exp = V_212 ;
if ( V_88 == V_18 - 1 )
exp = V_209 ;
if ( V_215 [ V_88 ] != exp ) {
int V_64 ;
if ( V_214 == 0 ) {
F_23 ( L_14 ,
F_176 () , V_13 -> V_43 ,
V_215 , V_18 ) ;
F_174 ( V_13 , V_14 , 0 ) ;
}
V_88 = ( V_88 / 16 ) * 16 ;
V_64 = 16 ;
if ( V_88 + V_64 > V_18 )
V_64 = V_18 - V_88 ;
F_171 ( V_215 , V_88 , V_64 ) ;
V_88 += 16 ;
V_214 ++ ;
if ( V_214 > 5 )
break;
}
}
if ( V_214 != 0 ) {
struct V_23 * V_23 = F_15 ( V_14 ) ;
unsigned int V_216 ;
V_216 = F_17 ( V_13 , V_23 , V_14 ) ;
if ( V_216 ) {
V_14 = F_16 ( V_13 , V_23 , V_216 - 1 ) ;
V_215 = ( char * ) V_14 + F_4 ( V_13 ) ;
F_23 ( L_15 , V_215 , V_18 ) ;
F_174 ( V_13 , V_14 , 2 ) ;
}
if ( V_216 + 1 < V_13 -> V_35 ) {
V_14 = F_16 ( V_13 , V_23 , V_216 + 1 ) ;
V_215 = ( char * ) V_14 + F_4 ( V_13 ) ;
F_23 ( L_16 , V_215 , V_18 ) ;
F_174 ( V_13 , V_14 , 2 ) ;
}
}
}
static void F_177 ( struct V_12 * V_13 ,
struct V_23 * V_23 )
{
int V_88 ;
if ( F_178 ( V_13 ) && V_13 -> V_15 & V_217 ) {
F_170 ( V_13 , V_23 -> V_218 - F_4 ( V_13 ) ,
V_212 ) ;
}
for ( V_88 = 0 ; V_88 < V_13 -> V_35 ; V_88 ++ ) {
void * V_14 = F_16 ( V_13 , V_23 , V_88 ) ;
if ( V_13 -> V_15 & V_217 ) {
F_175 ( V_13 , V_14 ) ;
F_168 ( V_13 , V_14 , 1 , 0 ) ;
}
if ( V_13 -> V_15 & V_16 ) {
if ( * F_5 ( V_13 , V_14 ) != V_219 )
F_179 ( V_13 , L_17 ) ;
if ( * F_7 ( V_13 , V_14 ) != V_219 )
F_179 ( V_13 , L_18 ) ;
}
}
}
static void F_177 ( struct V_12 * V_13 ,
struct V_23 * V_23 )
{
}
static void F_180 ( struct V_12 * V_13 , struct V_23 * V_23 )
{
void * V_218 ;
V_218 = V_23 -> V_218 ;
F_177 ( V_13 , V_23 ) ;
if ( F_77 ( V_13 -> V_15 & V_220 ) )
F_181 ( & V_23 -> V_153 , F_159 ) ;
else
F_151 ( V_13 , V_23 ) ;
if ( F_163 ( V_13 ) )
F_182 ( V_13 -> V_221 , V_218 ) ;
}
static void F_53 ( struct V_12 * V_13 , struct V_89 * V_74 )
{
struct V_23 * V_23 , * V_72 ;
F_183 (page, n, list, lru) {
F_184 ( & V_23 -> V_152 ) ;
F_180 ( V_13 , V_23 ) ;
}
}
static T_2 F_185 ( struct V_12 * V_13 ,
T_2 V_18 , unsigned long V_15 )
{
T_2 V_34 = 0 ;
int V_32 ;
for ( V_32 = 0 ; V_32 <= V_222 ; V_32 ++ ) {
unsigned int V_35 ;
T_2 V_223 ;
V_35 = F_21 ( V_32 , V_18 , V_15 , & V_223 ) ;
if ( ! V_35 )
continue;
if ( V_35 > V_224 )
break;
if ( V_15 & V_39 ) {
struct V_12 * V_221 ;
T_2 V_225 ;
V_225 = V_35 * sizeof( V_40 ) ;
V_221 = F_186 ( V_225 , 0u ) ;
if ( ! V_221 )
continue;
if ( F_163 ( V_221 ) )
continue;
if ( V_221 -> V_18 > V_13 -> V_18 / 2 )
continue;
}
V_13 -> V_35 = V_35 ;
V_13 -> V_32 = V_32 ;
V_34 = V_223 ;
if ( V_15 & V_187 )
break;
if ( V_32 >= V_49 )
break;
if ( V_34 * 8 <= ( V_37 << V_32 ) )
break;
}
return V_34 ;
}
static struct V_30 T_7 * F_187 (
struct V_12 * V_13 , int V_69 , int V_67 )
{
int V_52 ;
T_2 V_18 ;
struct V_30 T_7 * V_31 ;
V_18 = sizeof( void * ) * V_69 + sizeof( struct V_30 ) ;
V_31 = F_188 ( V_18 , sizeof( void * ) ) ;
if ( ! V_31 )
return NULL ;
F_189 (cpu) {
F_42 ( F_91 ( V_31 , V_52 ) ,
V_69 , V_67 ) ;
}
return V_31 ;
}
static int T_8 F_190 ( struct V_12 * V_13 , T_4 V_70 )
{
if ( V_162 >= V_172 )
return F_127 ( V_13 , V_70 ) ;
V_13 -> V_31 = F_187 ( V_13 , 1 , 1 ) ;
if ( ! V_13 -> V_31 )
return 1 ;
if ( V_162 == V_226 ) {
F_106 ( V_12 , V_169 ) ;
} else if ( V_162 == V_163 ) {
F_106 ( V_13 , V_170 ) ;
} else {
int V_55 ;
F_72 (node) {
V_13 -> V_55 [ V_55 ] = F_45 (
sizeof( struct V_1 ) , V_70 , V_55 ) ;
F_6 ( ! V_13 -> V_55 [ V_55 ] ) ;
F_1 ( V_13 -> V_55 [ V_55 ] ) ;
}
}
V_13 -> V_55 [ F_80 () ] -> V_95 =
V_96 + V_97 +
( ( unsigned long ) V_13 ) % V_97 ;
F_19 ( V_13 ) -> V_66 = 0 ;
F_19 ( V_13 ) -> V_64 = V_227 ;
F_19 ( V_13 ) -> V_67 = 1 ;
F_19 ( V_13 ) -> V_68 = 0 ;
V_13 -> V_67 = 1 ;
V_13 -> V_64 = V_227 ;
return 0 ;
}
unsigned long F_191 ( unsigned long V_204 ,
unsigned long V_15 , const char * V_43 ,
void (* V_194)( void * ) )
{
return V_15 ;
}
struct V_12 *
F_192 ( const char * V_43 , T_2 V_18 , T_2 V_228 ,
unsigned long V_15 , void (* V_194)( void * ) )
{
struct V_12 * V_13 ;
V_13 = F_193 ( V_18 , V_228 , V_15 , V_43 , V_194 ) ;
if ( V_13 ) {
V_13 -> V_229 ++ ;
V_13 -> V_204 = F_194 ( int , V_13 -> V_204 , V_18 ) ;
}
return V_13 ;
}
static bool F_195 ( struct V_12 * V_13 ,
T_2 V_18 , unsigned long V_15 )
{
T_2 V_230 ;
V_13 -> V_35 = 0 ;
if ( V_13 -> V_194 || V_15 & V_220 )
return false ;
V_230 = F_185 ( V_13 , V_18 ,
V_15 | V_38 ) ;
if ( ! V_13 -> V_35 )
return false ;
if ( V_13 -> V_35 * sizeof( V_40 ) > V_13 -> V_204 )
return false ;
V_13 -> V_231 = V_230 / V_13 -> V_232 ;
return true ;
}
static bool F_196 ( struct V_12 * V_13 ,
T_2 V_18 , unsigned long V_15 )
{
T_2 V_230 ;
V_13 -> V_35 = 0 ;
if ( V_15 & V_233 )
return false ;
V_230 = F_185 ( V_13 , V_18 , V_15 | V_39 ) ;
if ( ! V_13 -> V_35 )
return false ;
if ( V_230 >= V_13 -> V_35 * sizeof( V_40 ) )
return false ;
V_13 -> V_231 = V_230 / V_13 -> V_232 ;
return true ;
}
static bool F_197 ( struct V_12 * V_13 ,
T_2 V_18 , unsigned long V_15 )
{
T_2 V_230 ;
V_13 -> V_35 = 0 ;
V_230 = F_185 ( V_13 , V_18 , V_15 ) ;
if ( ! V_13 -> V_35 )
return false ;
V_13 -> V_231 = V_230 / V_13 -> V_232 ;
return true ;
}
int
F_198 ( struct V_12 * V_13 , unsigned long V_15 )
{
T_2 V_234 = V_20 ;
T_4 V_70 ;
int V_110 ;
T_2 V_18 = V_13 -> V_18 ;
#if V_176
#if V_235
if ( V_18 < 4096 || F_199 ( V_18 - 1 ) == F_199 ( V_18 - 1 + V_19 +
2 * sizeof( unsigned long long ) ) )
V_15 |= V_16 | V_17 ;
if ( ! ( V_15 & V_220 ) )
V_15 |= V_217 ;
#endif
#endif
if ( V_18 & ( V_20 - 1 ) ) {
V_18 += ( V_20 - 1 ) ;
V_18 &= ~ ( V_20 - 1 ) ;
}
if ( V_15 & V_16 ) {
V_234 = V_19 ;
V_18 += V_19 - 1 ;
V_18 &= ~ ( V_19 - 1 ) ;
}
if ( V_234 < V_13 -> V_228 ) {
V_234 = V_13 -> V_228 ;
}
if ( V_234 > F_200 (unsigned long long) )
V_15 &= ~ ( V_16 | V_17 ) ;
V_13 -> V_228 = V_234 ;
V_13 -> V_232 = F_201 () ;
if ( V_13 -> V_232 < V_13 -> V_228 )
V_13 -> V_232 = V_13 -> V_228 ;
if ( F_202 () )
V_70 = V_99 ;
else
V_70 = V_144 ;
#if V_176
if ( V_15 & V_16 ) {
V_13 -> F_4 += sizeof( unsigned long long ) ;
V_18 += 2 * sizeof( unsigned long long ) ;
}
if ( V_15 & V_17 ) {
if ( V_15 & V_16 )
V_18 += V_19 ;
else
V_18 += V_20 ;
}
#endif
F_203 ( V_13 , & V_18 , & V_15 ) ;
V_18 = F_204 ( V_18 , V_13 -> V_228 ) ;
if ( V_236 && V_18 < V_237 )
V_18 = F_204 ( V_237 , V_13 -> V_228 ) ;
#if V_176
if ( F_162 () && ( V_15 & V_217 ) &&
V_18 >= 256 && V_13 -> V_204 > F_201 () ) {
if ( V_18 < V_37 || V_18 % V_37 == 0 ) {
T_2 V_238 = F_204 ( V_18 , V_37 ) ;
if ( F_196 ( V_13 , V_238 , V_15 ) ) {
V_15 |= V_39 ;
V_13 -> F_4 += V_238 - V_18 ;
V_18 = V_238 ;
goto V_239;
}
}
}
#endif
if ( F_195 ( V_13 , V_18 , V_15 ) ) {
V_15 |= V_38 ;
goto V_239;
}
if ( F_196 ( V_13 , V_18 , V_15 ) ) {
V_15 |= V_39 ;
goto V_239;
}
if ( F_197 ( V_13 , V_18 , V_15 ) )
goto V_239;
return - V_240 ;
V_239:
V_13 -> V_225 = V_13 -> V_35 * sizeof( V_40 ) ;
V_13 -> V_15 = V_15 ;
V_13 -> V_186 = V_241 ;
if ( V_15 & V_242 )
V_13 -> V_186 |= V_243 ;
V_13 -> V_18 = V_18 ;
V_13 -> V_29 = F_205 ( V_18 ) ;
#if V_176
if ( F_117 ( V_244 ) &&
( V_13 -> V_15 & V_217 ) &&
F_161 ( V_13 ) )
V_13 -> V_15 &= ~ ( V_16 | V_17 ) ;
#endif
if ( F_163 ( V_13 ) ) {
V_13 -> V_221 =
F_186 ( V_13 -> V_225 , 0u ) ;
}
V_110 = F_190 ( V_13 , V_70 ) ;
if ( V_110 ) {
F_206 ( V_13 ) ;
return V_110 ;
}
return 0 ;
}
static void F_207 ( void )
{
F_6 ( ! F_208 () ) ;
}
static void F_209 ( void )
{
F_6 ( F_208 () ) ;
}
static void F_210 ( void )
{
F_6 ( ! F_211 ( & V_118 ) ) ;
}
static void F_212 ( struct V_12 * V_13 )
{
#ifdef F_213
F_207 () ;
F_214 ( & F_49 ( V_13 , F_80 () ) -> V_9 ) ;
#endif
}
static void F_215 ( struct V_12 * V_13 , int V_55 )
{
#ifdef F_213
F_207 () ;
F_214 ( & F_49 ( V_13 , V_55 ) -> V_9 ) ;
#endif
}
static void F_216 ( struct V_12 * V_13 , struct V_30 * V_63 ,
int V_55 , bool V_245 , struct V_89 * V_74 )
{
int V_246 ;
if ( ! V_63 || ! V_63 -> V_66 )
return;
V_246 = V_245 ? V_63 -> V_66 : ( V_63 -> V_64 + 4 ) / 5 ;
if ( V_246 > V_63 -> V_66 )
V_246 = ( V_63 -> V_66 + 1 ) / 2 ;
F_51 ( V_13 , V_63 -> V_79 , V_246 , V_55 , V_74 ) ;
V_63 -> V_66 -= V_246 ;
memmove ( V_63 -> V_79 , & ( V_63 -> V_79 [ V_246 ] ) , sizeof( void * ) * V_63 -> V_66 ) ;
}
static void F_217 ( void * V_131 )
{
struct V_12 * V_13 = V_131 ;
struct V_30 * V_63 ;
int V_55 = F_80 () ;
struct V_1 * V_72 ;
F_47 ( V_74 ) ;
F_207 () ;
V_63 = F_19 ( V_13 ) ;
V_72 = F_49 ( V_13 , V_55 ) ;
F_50 ( & V_72 -> V_9 ) ;
F_51 ( V_13 , V_63 -> V_79 , V_63 -> V_66 , V_55 , & V_74 ) ;
F_52 ( & V_72 -> V_9 ) ;
F_53 ( V_13 , & V_74 ) ;
V_63 -> V_66 = 0 ;
}
static void F_218 ( struct V_12 * V_13 )
{
struct V_1 * V_72 ;
int V_55 ;
F_47 ( V_74 ) ;
F_219 ( F_217 , V_13 , 1 ) ;
F_209 () ;
F_137 (cachep, node, n)
if ( V_72 -> V_7 )
F_71 ( V_13 , V_72 -> V_7 ) ;
F_137 (cachep, node, n) {
F_83 ( & V_72 -> V_9 ) ;
F_216 ( V_13 , V_72 -> V_6 , V_55 , true , & V_74 ) ;
F_70 ( & V_72 -> V_9 ) ;
F_53 ( V_13 , & V_74 ) ;
}
}
static int F_93 ( struct V_12 * V_25 ,
struct V_1 * V_72 , int V_246 )
{
struct V_89 * V_247 ;
int V_196 ;
struct V_23 * V_23 ;
V_196 = 0 ;
while ( V_196 < V_246 && ! F_102 ( & V_72 -> V_5 ) ) {
F_83 ( & V_72 -> V_9 ) ;
V_247 = V_72 -> V_5 . V_248 ;
if ( V_247 == & V_72 -> V_5 ) {
F_70 ( & V_72 -> V_9 ) ;
goto V_136;
}
V_23 = F_220 ( V_247 , struct V_23 , V_152 ) ;
F_184 ( & V_23 -> V_152 ) ;
V_72 -> V_10 -= V_25 -> V_35 ;
F_70 ( & V_72 -> V_9 ) ;
F_180 ( V_25 , V_23 ) ;
V_196 ++ ;
}
V_136:
return V_196 ;
}
int F_221 ( struct V_12 * V_13 , bool V_249 )
{
int V_98 = 0 ;
int V_55 ;
struct V_1 * V_72 ;
F_218 ( V_13 ) ;
F_209 () ;
F_137 (cachep, node, n) {
F_93 ( V_13 , V_72 , V_109 ) ;
V_98 += ! F_102 ( & V_72 -> V_3 ) ||
! F_102 ( & V_72 -> V_4 ) ;
}
return ( V_98 ? 1 : 0 ) ;
}
int F_222 ( struct V_12 * V_13 )
{
return F_221 ( V_13 , false ) ;
}
void F_206 ( struct V_12 * V_13 )
{
int V_88 ;
struct V_1 * V_72 ;
F_114 ( V_13 ) ;
F_223 ( V_13 -> V_31 ) ;
F_137 (cachep, i, n) {
F_66 ( V_72 -> V_6 ) ;
F_57 ( V_72 -> V_7 ) ;
F_66 ( V_72 ) ;
V_13 -> V_55 [ V_88 ] = NULL ;
}
}
static void * F_224 ( struct V_12 * V_13 ,
struct V_23 * V_23 , int V_232 ,
T_4 V_250 , int V_82 )
{
void * V_218 ;
void * V_202 = F_225 ( V_23 ) ;
V_23 -> V_27 = V_202 + V_232 ;
V_23 -> V_184 = 0 ;
if ( F_178 ( V_13 ) )
V_218 = NULL ;
else if ( F_163 ( V_13 ) ) {
V_218 = F_226 ( V_13 -> V_221 ,
V_250 , V_82 ) ;
if ( ! V_218 )
return NULL ;
} else {
V_218 = V_202 + ( V_37 << V_13 -> V_32 ) -
V_13 -> V_225 ;
}
return V_218 ;
}
static inline V_40 F_227 ( struct V_23 * V_23 , unsigned int V_26 )
{
return ( ( V_40 * ) V_23 -> V_218 ) [ V_26 ] ;
}
static inline void F_228 ( struct V_23 * V_23 ,
unsigned int V_26 , V_40 V_208 )
{
( ( V_40 * ) ( V_23 -> V_218 ) ) [ V_26 ] = V_208 ;
}
static void F_229 ( struct V_12 * V_13 , struct V_23 * V_23 )
{
#if V_176
int V_88 ;
for ( V_88 = 0 ; V_88 < V_13 -> V_35 ; V_88 ++ ) {
void * V_14 = F_16 ( V_13 , V_23 , V_88 ) ;
if ( V_13 -> V_15 & V_17 )
* F_8 ( V_13 , V_14 ) = NULL ;
if ( V_13 -> V_15 & V_16 ) {
* F_5 ( V_13 , V_14 ) = V_219 ;
* F_7 ( V_13 , V_14 ) = V_219 ;
}
if ( V_13 -> V_194 && ! ( V_13 -> V_15 & V_217 ) ) {
F_230 ( V_13 ,
V_14 + F_4 ( V_13 ) ) ;
V_13 -> V_194 ( V_14 + F_4 ( V_13 ) ) ;
F_231 (
V_13 , V_14 + F_4 ( V_13 ) ) ;
}
if ( V_13 -> V_15 & V_16 ) {
if ( * F_7 ( V_13 , V_14 ) != V_219 )
F_179 ( V_13 , L_19 ) ;
if ( * F_5 ( V_13 , V_14 ) != V_219 )
F_179 ( V_13 , L_20 ) ;
}
if ( V_13 -> V_15 & V_217 ) {
F_170 ( V_13 , V_14 , V_212 ) ;
F_168 ( V_13 , V_14 , 0 , 0 ) ;
}
}
#endif
}
static bool F_232 ( union V_251 * V_148 ,
struct V_12 * V_13 ,
unsigned int V_149 )
{
bool V_98 ;
unsigned int rand ;
F_112 ( & rand , sizeof( rand ) ) ;
if ( ! V_13 -> V_151 ) {
F_113 ( & V_148 -> V_147 , rand ) ;
V_98 = false ;
} else {
V_148 -> V_74 = V_13 -> V_151 ;
V_148 -> V_149 = V_149 ;
V_148 -> V_252 = 0 ;
V_148 -> rand = rand ;
V_98 = true ;
}
return V_98 ;
}
static V_40 F_233 ( union V_251 * V_148 )
{
return ( V_148 -> V_74 [ V_148 -> V_252 ++ ] + V_148 -> rand ) % V_148 -> V_149 ;
}
static bool F_234 ( struct V_12 * V_13 , struct V_23 * V_23 )
{
unsigned int V_253 = 0 , V_88 , V_149 = V_13 -> V_35 ;
union V_251 V_148 ;
bool V_254 ;
if ( V_149 < 2 )
return false ;
V_254 = F_232 ( & V_148 , V_13 , V_149 ) ;
if ( F_178 ( V_13 ) ) {
if ( ! V_254 )
V_253 = V_149 - 1 ;
else
V_253 = F_233 ( & V_148 ) ;
V_23 -> V_218 = F_16 ( V_13 , V_23 , V_253 ) +
F_4 ( V_13 ) ;
V_149 -- ;
}
if ( ! V_254 ) {
F_107 ( & V_148 . V_147 , V_23 -> V_218 , V_149 ) ;
} else {
for ( V_88 = 0 ; V_88 < V_149 ; V_88 ++ )
F_228 ( V_23 , V_88 , F_233 ( & V_148 ) ) ;
}
if ( F_178 ( V_13 ) )
F_228 ( V_23 , V_13 -> V_35 - 1 , V_253 ) ;
return true ;
}
static inline bool F_234 ( struct V_12 * V_13 ,
struct V_23 * V_23 )
{
return false ;
}
static void F_235 ( struct V_12 * V_13 ,
struct V_23 * V_23 )
{
int V_88 ;
void * V_14 ;
bool V_255 ;
F_229 ( V_13 , V_23 ) ;
V_255 = F_234 ( V_13 , V_23 ) ;
if ( ! V_255 && F_178 ( V_13 ) ) {
V_23 -> V_218 = F_16 ( V_13 , V_23 , V_13 -> V_35 - 1 ) +
F_4 ( V_13 ) ;
}
for ( V_88 = 0 ; V_88 < V_13 -> V_35 ; V_88 ++ ) {
if ( V_176 == 0 && V_13 -> V_194 ) {
V_14 = F_16 ( V_13 , V_23 , V_88 ) ;
F_230 ( V_13 , V_14 ) ;
V_13 -> V_194 ( V_14 ) ;
F_231 ( V_13 , V_14 ) ;
}
if ( ! V_255 )
F_228 ( V_23 , V_88 , V_88 ) ;
}
}
static void * F_236 ( struct V_12 * V_13 , struct V_23 * V_23 )
{
void * V_14 ;
V_14 = F_16 ( V_13 , V_23 , F_227 ( V_23 , V_23 -> V_184 ) ) ;
V_23 -> V_184 ++ ;
#if V_176
if ( V_13 -> V_15 & V_17 )
F_13 ( V_13 ) ;
#endif
return V_14 ;
}
static void F_237 ( struct V_12 * V_13 ,
struct V_23 * V_23 , void * V_14 )
{
unsigned int V_216 = F_17 ( V_13 , V_23 , V_14 ) ;
#if V_176
unsigned int V_88 ;
for ( V_88 = V_23 -> V_184 ; V_88 < V_13 -> V_35 ; V_88 ++ ) {
if ( F_227 ( V_23 , V_88 ) == V_216 ) {
F_23 ( L_21 ,
V_13 -> V_43 , V_14 ) ;
F_128 () ;
}
}
#endif
V_23 -> V_184 -- ;
if ( ! V_23 -> V_218 )
V_23 -> V_218 = V_14 + F_4 ( V_13 ) ;
F_228 ( V_23 , V_23 -> V_184 , V_216 ) ;
}
static void F_238 ( struct V_12 * V_25 , struct V_23 * V_23 ,
void * V_218 )
{
V_23 -> V_24 = V_25 ;
V_23 -> V_218 = V_218 ;
}
static struct V_23 * F_239 ( struct V_12 * V_13 ,
T_4 V_15 , int V_82 )
{
void * V_218 ;
T_2 V_28 ;
T_4 V_250 ;
int V_73 ;
struct V_1 * V_72 ;
struct V_23 * V_23 ;
if ( F_77 ( V_15 & V_256 ) ) {
F_240 ( L_22 , V_15 & V_256 ) ;
F_128 () ;
}
V_250 = V_15 & ( V_257 | V_258 ) ;
F_207 () ;
if ( F_241 ( V_250 ) )
F_242 () ;
V_23 = F_138 ( V_13 , V_250 , V_82 ) ;
if ( ! V_23 )
goto V_259;
V_73 = F_48 ( V_23 ) ;
V_72 = F_49 ( V_13 , V_73 ) ;
V_72 -> V_8 ++ ;
if ( V_72 -> V_8 >= V_13 -> V_231 )
V_72 -> V_8 = 0 ;
V_28 = V_72 -> V_8 ;
if ( V_28 >= V_13 -> V_231 )
V_28 = 0 ;
V_28 *= V_13 -> V_232 ;
V_218 = F_224 ( V_13 , V_23 , V_28 ,
V_250 & ~ V_257 , V_73 ) ;
if ( F_163 ( V_13 ) && ! V_218 )
goto V_260;
F_238 ( V_13 , V_23 , V_218 ) ;
F_243 ( V_23 ) ;
F_235 ( V_13 , V_23 ) ;
if ( F_241 ( V_250 ) )
F_244 () ;
return V_23 ;
V_260:
F_151 ( V_13 , V_23 ) ;
V_259:
if ( F_241 ( V_250 ) )
F_244 () ;
return NULL ;
}
static void F_245 ( struct V_12 * V_13 , struct V_23 * V_23 )
{
struct V_1 * V_72 ;
void * V_74 = NULL ;
F_207 () ;
if ( ! V_23 )
return;
F_2 ( & V_23 -> V_152 ) ;
V_72 = F_49 ( V_13 , F_48 ( V_23 ) ) ;
F_50 ( & V_72 -> V_9 ) ;
if ( ! V_23 -> V_184 )
F_246 ( & V_23 -> V_152 , & ( V_72 -> V_5 ) ) ;
else
F_247 ( V_13 , V_72 , V_23 , & V_74 ) ;
F_248 ( V_13 ) ;
V_72 -> V_10 += V_13 -> V_35 - V_23 -> V_184 ;
F_52 ( & V_72 -> V_9 ) ;
F_249 ( V_13 , & V_74 ) ;
}
static void F_250 ( const void * V_14 )
{
if ( ! F_251 ( V_14 ) ) {
F_23 ( L_23 ,
( unsigned long ) V_14 ) ;
F_128 () ;
}
}
static inline void F_252 ( struct V_12 * V_25 , void * V_22 )
{
unsigned long long V_261 , V_262 ;
V_261 = * F_5 ( V_25 , V_22 ) ;
V_262 = * F_7 ( V_25 , V_22 ) ;
if ( V_261 == V_263 && V_262 == V_263 )
return;
if ( V_261 == V_219 && V_262 == V_219 )
F_179 ( V_25 , L_24 ) ;
else
F_179 ( V_25 , L_25 ) ;
F_23 ( L_26 ,
V_22 , V_261 , V_262 ) ;
}
static void * F_253 ( struct V_12 * V_13 , void * V_14 ,
unsigned long V_203 )
{
unsigned int V_216 ;
struct V_23 * V_23 ;
F_6 ( F_14 ( V_14 ) != V_13 ) ;
V_14 -= F_4 ( V_13 ) ;
F_250 ( V_14 ) ;
V_23 = F_15 ( V_14 ) ;
if ( V_13 -> V_15 & V_16 ) {
F_252 ( V_13 , V_14 ) ;
* F_5 ( V_13 , V_14 ) = V_219 ;
* F_7 ( V_13 , V_14 ) = V_219 ;
}
if ( V_13 -> V_15 & V_17 ) {
F_13 ( V_13 ) ;
* F_8 ( V_13 , V_14 ) = ( void * ) V_203 ;
}
V_216 = F_17 ( V_13 , V_23 , V_14 ) ;
F_6 ( V_216 >= V_13 -> V_35 ) ;
F_6 ( V_14 != F_16 ( V_13 , V_23 , V_216 ) ) ;
if ( V_13 -> V_15 & V_217 ) {
F_170 ( V_13 , V_14 , V_212 ) ;
F_168 ( V_13 , V_14 , 0 , V_203 ) ;
}
return V_14 ;
}
static inline void F_249 ( struct V_12 * V_13 ,
void * * V_74 )
{
#if V_176
void * V_264 = * V_74 ;
void * V_14 ;
while ( V_264 ) {
V_14 = V_264 - F_4 ( V_13 ) ;
V_264 = * ( void * * ) V_264 ;
F_170 ( V_13 , V_14 , V_212 ) ;
}
#endif
}
static inline void F_247 ( struct V_12 * V_13 ,
struct V_1 * V_72 , struct V_23 * V_23 ,
void * * V_74 )
{
F_184 ( & V_23 -> V_152 ) ;
if ( V_23 -> V_184 == V_13 -> V_35 ) {
F_121 ( & V_23 -> V_152 , & V_72 -> V_3 ) ;
if ( F_178 ( V_13 ) ) {
#if V_176
if ( V_13 -> V_15 & V_217 ) {
void * * V_14 = V_23 -> V_218 ;
* V_14 = * V_74 ;
* V_74 = V_14 ;
}
#endif
V_23 -> V_218 = NULL ;
}
} else
F_121 ( & V_23 -> V_152 , & V_72 -> V_4 ) ;
}
struct V_23 * F_254 ( struct V_1 * V_72 , bool V_265 )
{
struct V_23 * V_23 ;
V_23 = F_255 ( & V_72 -> V_4 ,
struct V_23 , V_152 ) ;
if ( ! V_23 ) {
V_72 -> V_11 = 1 ;
V_23 = F_255 ( & V_72 -> V_5 ,
struct V_23 , V_152 ) ;
}
if ( F_145 () )
return F_256 ( V_72 , V_23 , V_265 ) ;
return V_23 ;
}
static T_5 void * F_257 ( struct V_12 * V_13 ,
struct V_1 * V_72 , T_4 V_15 )
{
struct V_23 * V_23 ;
void * V_22 ;
void * V_74 = NULL ;
if ( ! F_258 ( V_15 ) )
return NULL ;
F_50 ( & V_72 -> V_9 ) ;
V_23 = F_254 ( V_72 , true ) ;
if ( ! V_23 ) {
F_52 ( & V_72 -> V_9 ) ;
return NULL ;
}
V_22 = F_236 ( V_13 , V_23 ) ;
V_72 -> V_10 -- ;
F_247 ( V_13 , V_72 , V_23 , & V_74 ) ;
F_52 ( & V_72 -> V_9 ) ;
F_249 ( V_13 , & V_74 ) ;
return V_22 ;
}
static T_9 int F_259 ( struct V_12 * V_13 ,
struct V_30 * V_63 , struct V_23 * V_23 , int V_67 )
{
F_6 ( V_23 -> V_184 >= V_13 -> V_35 ) ;
while ( V_23 -> V_184 < V_13 -> V_35 && V_67 -- ) {
F_260 ( V_13 ) ;
F_261 ( V_13 ) ;
F_262 ( V_13 ) ;
V_63 -> V_79 [ V_63 -> V_66 ++ ] = F_236 ( V_13 , V_23 ) ;
}
return V_67 ;
}
static void * F_263 ( struct V_12 * V_13 , T_4 V_15 )
{
int V_67 ;
struct V_1 * V_72 ;
struct V_30 * V_63 , * V_6 ;
int V_55 ;
void * V_74 = NULL ;
struct V_23 * V_23 ;
F_207 () ;
V_55 = F_80 () ;
V_63 = F_19 ( V_13 ) ;
V_67 = V_63 -> V_67 ;
if ( ! V_63 -> V_68 && V_67 > V_266 ) {
V_67 = V_266 ;
}
V_72 = F_49 ( V_13 , V_55 ) ;
F_6 ( V_63 -> V_66 > 0 || ! V_72 ) ;
V_6 = F_264 ( V_72 -> V_6 ) ;
if ( ! V_72 -> V_10 && ( ! V_6 || ! V_6 -> V_66 ) )
goto V_267;
F_50 ( & V_72 -> V_9 ) ;
V_6 = F_264 ( V_72 -> V_6 ) ;
if ( V_6 && F_54 ( V_63 , V_6 , V_67 ) ) {
V_6 -> V_68 = 1 ;
goto V_268;
}
while ( V_67 > 0 ) {
V_23 = F_254 ( V_72 , false ) ;
if ( ! V_23 )
goto V_269;
F_212 ( V_13 ) ;
V_67 = F_259 ( V_13 , V_63 , V_23 , V_67 ) ;
F_247 ( V_13 , V_72 , V_23 , & V_74 ) ;
}
V_269:
V_72 -> V_10 -= V_63 -> V_66 ;
V_268:
F_52 ( & V_72 -> V_9 ) ;
F_249 ( V_13 , & V_74 ) ;
V_267:
if ( F_77 ( ! V_63 -> V_66 ) ) {
if ( F_145 () ) {
void * V_22 = F_257 ( V_13 , V_72 , V_15 ) ;
if ( V_22 )
return V_22 ;
}
V_23 = F_239 ( V_13 , F_61 ( V_15 ) , V_55 ) ;
V_63 = F_19 ( V_13 ) ;
if ( ! V_63 -> V_66 && V_23 )
F_259 ( V_13 , V_63 , V_23 , V_67 ) ;
F_245 ( V_13 , V_23 ) ;
if ( ! V_63 -> V_66 )
return NULL ;
}
V_63 -> V_68 = 1 ;
return V_63 -> V_79 [ -- V_63 -> V_66 ] ;
}
static inline void F_265 ( struct V_12 * V_13 ,
T_4 V_15 )
{
F_266 ( F_241 ( V_15 ) ) ;
}
static void * F_267 ( struct V_12 * V_13 ,
T_4 V_15 , void * V_14 , unsigned long V_203 )
{
if ( ! V_14 )
return V_14 ;
if ( V_13 -> V_15 & V_217 ) {
F_175 ( V_13 , V_14 ) ;
F_168 ( V_13 , V_14 , 1 , 0 ) ;
F_170 ( V_13 , V_14 , V_270 ) ;
}
if ( V_13 -> V_15 & V_17 )
* F_8 ( V_13 , V_14 ) = ( void * ) V_203 ;
if ( V_13 -> V_15 & V_16 ) {
if ( * F_5 ( V_13 , V_14 ) != V_219 ||
* F_7 ( V_13 , V_14 ) != V_219 ) {
F_179 ( V_13 , L_27 ) ;
F_23 ( L_26 ,
V_14 , * F_5 ( V_13 , V_14 ) ,
* F_7 ( V_13 , V_14 ) ) ;
}
* F_5 ( V_13 , V_14 ) = V_263 ;
* F_7 ( V_13 , V_14 ) = V_263 ;
}
V_14 += F_4 ( V_13 ) ;
if ( V_13 -> V_194 && V_13 -> V_15 & V_217 )
V_13 -> V_194 ( V_14 ) ;
if ( V_271 &&
( ( unsigned long ) V_14 & ( V_271 - 1 ) ) ) {
F_23 ( L_28 ,
V_14 , ( int ) V_271 ) ;
}
return V_14 ;
}
static inline void * F_268 ( struct V_12 * V_13 , T_4 V_15 )
{
void * V_14 ;
struct V_30 * V_63 ;
F_207 () ;
V_63 = F_19 ( V_13 ) ;
if ( F_81 ( V_63 -> V_66 ) ) {
V_63 -> V_68 = 1 ;
V_14 = V_63 -> V_79 [ -- V_63 -> V_66 ] ;
F_269 ( V_13 ) ;
goto V_136;
}
F_270 ( V_13 ) ;
V_14 = F_263 ( V_13 , V_15 ) ;
V_63 = F_19 ( V_13 ) ;
V_136:
if ( V_14 )
F_271 ( & V_63 -> V_79 [ V_63 -> V_66 ] ) ;
return V_14 ;
}
static void * F_59 ( struct V_12 * V_13 , T_4 V_15 )
{
int V_272 , V_273 ;
if ( F_272 () || ( V_15 & V_90 ) )
return NULL ;
V_272 = V_273 = F_80 () ;
if ( F_273 () && ( V_13 -> V_15 & V_274 ) )
V_272 = F_274 () ;
else if ( V_198 -> V_275 )
V_272 = F_275 () ;
if ( V_272 != V_273 )
return F_60 ( V_13 , V_15 , V_272 ) ;
return NULL ;
}
static void * F_276 ( struct V_12 * V_25 , T_4 V_15 )
{
struct V_276 * V_276 ;
struct V_277 * V_278 ;
struct V_279 * V_279 ;
enum V_280 V_281 = F_277 ( V_15 ) ;
void * V_22 = NULL ;
struct V_23 * V_23 ;
int V_134 ;
unsigned int V_282 ;
if ( V_15 & V_90 )
return NULL ;
V_283:
V_282 = F_278 () ;
V_276 = F_279 ( F_275 () , V_15 ) ;
V_284:
F_280 (zone, z, zonelist, high_zoneidx) {
V_134 = F_281 ( V_279 ) ;
if ( F_282 ( V_279 , V_15 ) &&
F_49 ( V_25 , V_134 ) &&
F_49 ( V_25 , V_134 ) -> V_10 ) {
V_22 = F_60 ( V_25 ,
F_61 ( V_15 ) , V_134 ) ;
if ( V_22 )
break;
}
}
if ( ! V_22 ) {
V_23 = F_239 ( V_25 , V_15 , F_80 () ) ;
F_245 ( V_25 , V_23 ) ;
if ( V_23 ) {
V_134 = F_48 ( V_23 ) ;
V_22 = F_60 ( V_25 ,
F_61 ( V_15 ) , V_134 ) ;
if ( ! V_22 )
goto V_284;
}
}
if ( F_77 ( ! V_22 && F_283 ( V_282 ) ) )
goto V_283;
return V_22 ;
}
static void * F_60 ( struct V_12 * V_13 , T_4 V_15 ,
int V_82 )
{
struct V_23 * V_23 ;
struct V_1 * V_72 ;
void * V_22 = NULL ;
void * V_74 = NULL ;
F_284 ( V_82 < 0 || V_82 >= V_285 ) ;
V_72 = F_49 ( V_13 , V_82 ) ;
F_6 ( ! V_72 ) ;
F_207 () ;
F_50 ( & V_72 -> V_9 ) ;
V_23 = F_254 ( V_72 , false ) ;
if ( ! V_23 )
goto V_269;
F_215 ( V_13 , V_82 ) ;
F_285 ( V_13 ) ;
F_261 ( V_13 ) ;
F_262 ( V_13 ) ;
F_6 ( V_23 -> V_184 == V_13 -> V_35 ) ;
V_22 = F_236 ( V_13 , V_23 ) ;
V_72 -> V_10 -- ;
F_247 ( V_13 , V_72 , V_23 , & V_74 ) ;
F_52 ( & V_72 -> V_9 ) ;
F_249 ( V_13 , & V_74 ) ;
return V_22 ;
V_269:
F_52 ( & V_72 -> V_9 ) ;
V_23 = F_239 ( V_13 , F_61 ( V_15 ) , V_82 ) ;
if ( V_23 ) {
V_22 = F_236 ( V_13 , V_23 ) ;
}
F_245 ( V_13 , V_23 ) ;
return V_22 ? V_22 : F_276 ( V_13 , V_15 ) ;
}
static T_9 void *
F_286 ( struct V_12 * V_13 , T_4 V_15 , int V_82 ,
unsigned long V_203 )
{
unsigned long V_286 ;
void * V_143 ;
int V_287 = F_80 () ;
V_15 &= V_288 ;
V_13 = F_287 ( V_13 , V_15 ) ;
if ( F_77 ( ! V_13 ) )
return NULL ;
F_265 ( V_13 , V_15 ) ;
F_288 ( V_286 ) ;
if ( V_82 == V_289 )
V_82 = V_287 ;
if ( F_77 ( ! F_49 ( V_13 , V_82 ) ) ) {
V_143 = F_276 ( V_13 , V_15 ) ;
goto V_136;
}
if ( V_82 == V_287 ) {
V_143 = F_268 ( V_13 , V_15 ) ;
if ( V_143 )
goto V_136;
}
V_143 = F_60 ( V_13 , V_15 , V_82 ) ;
V_136:
F_289 ( V_286 ) ;
V_143 = F_267 ( V_13 , V_15 , V_143 , V_203 ) ;
if ( F_77 ( V_15 & V_290 ) && V_143 )
memset ( V_143 , 0 , V_13 -> V_204 ) ;
F_290 ( V_13 , V_15 , 1 , & V_143 ) ;
return V_143 ;
}
static T_9 void *
F_291 ( struct V_12 * V_25 , T_4 V_15 )
{
void * V_14 ;
if ( V_198 -> V_275 || F_273 () ) {
V_14 = F_59 ( V_25 , V_15 ) ;
if ( V_14 )
goto V_136;
}
V_14 = F_268 ( V_25 , V_15 ) ;
if ( ! V_14 )
V_14 = F_60 ( V_25 , V_15 , F_80 () ) ;
V_136:
return V_14 ;
}
static T_9 void *
F_291 ( struct V_12 * V_13 , T_4 V_15 )
{
return F_268 ( V_13 , V_15 ) ;
}
static T_9 void *
F_292 ( struct V_12 * V_13 , T_4 V_15 , unsigned long V_203 )
{
unsigned long V_286 ;
void * V_14 ;
V_15 &= V_288 ;
V_13 = F_287 ( V_13 , V_15 ) ;
if ( F_77 ( ! V_13 ) )
return NULL ;
F_265 ( V_13 , V_15 ) ;
F_288 ( V_286 ) ;
V_14 = F_291 ( V_13 , V_15 ) ;
F_289 ( V_286 ) ;
V_14 = F_267 ( V_13 , V_15 , V_14 , V_203 ) ;
F_293 ( V_14 ) ;
if ( F_77 ( V_15 & V_290 ) && V_14 )
memset ( V_14 , 0 , V_13 -> V_204 ) ;
F_290 ( V_13 , V_15 , 1 , & V_14 ) ;
return V_14 ;
}
static void F_51 ( struct V_12 * V_13 , void * * V_291 ,
int V_292 , int V_55 , struct V_89 * V_74 )
{
int V_88 ;
struct V_1 * V_72 = F_49 ( V_13 , V_55 ) ;
struct V_23 * V_23 ;
V_72 -> V_10 += V_292 ;
for ( V_88 = 0 ; V_88 < V_292 ; V_88 ++ ) {
void * V_14 ;
struct V_23 * V_23 ;
V_14 = V_291 [ V_88 ] ;
V_23 = F_15 ( V_14 ) ;
F_184 ( & V_23 -> V_152 ) ;
F_215 ( V_13 , V_55 ) ;
F_237 ( V_13 , V_23 , V_14 ) ;
F_294 ( V_13 ) ;
if ( V_23 -> V_184 == 0 )
F_121 ( & V_23 -> V_152 , & V_72 -> V_5 ) ;
else {
F_246 ( & V_23 -> V_152 , & V_72 -> V_4 ) ;
}
}
while ( V_72 -> V_10 > V_72 -> V_93 && ! F_102 ( & V_72 -> V_5 ) ) {
V_72 -> V_10 -= V_13 -> V_35 ;
V_23 = F_295 ( & V_72 -> V_5 , struct V_23 , V_152 ) ;
F_184 ( & V_23 -> V_152 ) ;
F_121 ( & V_23 -> V_152 , V_74 ) ;
}
}
static void F_296 ( struct V_12 * V_13 , struct V_30 * V_63 )
{
int V_67 ;
struct V_1 * V_72 ;
int V_55 = F_80 () ;
F_47 ( V_74 ) ;
V_67 = V_63 -> V_67 ;
F_207 () ;
V_72 = F_49 ( V_13 , V_55 ) ;
F_50 ( & V_72 -> V_9 ) ;
if ( V_72 -> V_6 ) {
struct V_30 * V_293 = V_72 -> V_6 ;
int V_77 = V_293 -> V_64 - V_293 -> V_66 ;
if ( V_77 ) {
if ( V_67 > V_77 )
V_67 = V_77 ;
memcpy ( & ( V_293 -> V_79 [ V_293 -> V_66 ] ) ,
V_63 -> V_79 , sizeof( void * ) * V_67 ) ;
V_293 -> V_66 += V_67 ;
goto V_294;
}
}
F_51 ( V_13 , V_63 -> V_79 , V_67 , V_55 , & V_74 ) ;
V_294:
#if V_295
{
int V_88 = 0 ;
struct V_23 * V_23 ;
F_86 (page, &n->slabs_free, lru) {
F_6 ( V_23 -> V_184 ) ;
V_88 ++ ;
}
F_297 ( V_13 , V_88 ) ;
}
#endif
F_52 ( & V_72 -> V_9 ) ;
F_53 ( V_13 , & V_74 ) ;
V_63 -> V_66 -= V_67 ;
memmove ( V_63 -> V_79 , & ( V_63 -> V_79 [ V_67 ] ) , sizeof( void * ) * V_63 -> V_66 ) ;
}
static inline void F_298 ( struct V_12 * V_13 , void * V_14 ,
unsigned long V_203 )
{
if ( F_299 ( V_13 , V_14 ) )
return;
F_300 ( V_13 , V_14 , V_203 ) ;
}
void F_300 ( struct V_12 * V_13 , void * V_14 ,
unsigned long V_203 )
{
struct V_30 * V_63 = F_19 ( V_13 ) ;
F_207 () ;
F_301 ( V_14 , V_13 -> V_15 ) ;
V_14 = F_253 ( V_13 , V_14 , V_203 ) ;
F_302 ( V_13 , V_14 , V_13 -> V_204 ) ;
if ( V_296 > 1 && F_58 ( V_13 , V_14 ) )
return;
if ( V_63 -> V_66 < V_63 -> V_64 ) {
F_303 ( V_13 ) ;
} else {
F_304 ( V_13 ) ;
F_296 ( V_13 , V_63 ) ;
}
if ( F_145 () ) {
struct V_23 * V_23 = F_15 ( V_14 ) ;
if ( F_77 ( F_305 ( V_23 ) ) ) {
F_46 ( V_13 , V_23 , V_14 ) ;
return;
}
}
V_63 -> V_79 [ V_63 -> V_66 ++ ] = V_14 ;
}
void * F_306 ( struct V_12 * V_13 , T_4 V_15 )
{
void * V_98 = F_292 ( V_13 , V_15 , V_297 ) ;
F_307 ( V_13 , V_98 , V_15 ) ;
F_308 ( V_297 , V_98 ,
V_13 -> V_204 , V_13 -> V_18 , V_15 ) ;
return V_98 ;
}
static T_9 void
F_309 ( struct V_12 * V_46 , T_4 V_15 ,
T_2 V_18 , void * * V_247 , unsigned long V_203 )
{
T_2 V_88 ;
for ( V_88 = 0 ; V_88 < V_18 ; V_88 ++ )
V_247 [ V_88 ] = F_267 ( V_46 , V_15 , V_247 [ V_88 ] , V_203 ) ;
}
int F_310 ( struct V_12 * V_46 , T_4 V_15 , T_2 V_18 ,
void * * V_247 )
{
T_2 V_88 ;
V_46 = F_287 ( V_46 , V_15 ) ;
if ( ! V_46 )
return 0 ;
F_265 ( V_46 , V_15 ) ;
F_244 () ;
for ( V_88 = 0 ; V_88 < V_18 ; V_88 ++ ) {
void * V_14 = F_291 ( V_46 , V_15 ) ;
if ( F_77 ( ! V_14 ) )
goto error;
V_247 [ V_88 ] = V_14 ;
}
F_242 () ;
F_309 ( V_46 , V_15 , V_18 , V_247 , V_297 ) ;
if ( F_77 ( V_15 & V_290 ) )
for ( V_88 = 0 ; V_88 < V_18 ; V_88 ++ )
memset ( V_247 [ V_88 ] , 0 , V_46 -> V_204 ) ;
F_290 ( V_46 , V_15 , V_18 , V_247 ) ;
return V_18 ;
error:
F_242 () ;
F_309 ( V_46 , V_15 , V_88 , V_247 , V_297 ) ;
F_290 ( V_46 , V_15 , V_88 , V_247 ) ;
F_311 ( V_46 , V_88 , V_247 ) ;
return 0 ;
}
void *
F_312 ( struct V_12 * V_13 , T_4 V_15 , T_2 V_18 )
{
void * V_98 ;
V_98 = F_292 ( V_13 , V_15 , V_297 ) ;
F_313 ( V_13 , V_98 , V_18 , V_15 ) ;
F_314 ( V_297 , V_98 ,
V_18 , V_13 -> V_18 , V_15 ) ;
return V_98 ;
}
void * F_226 ( struct V_12 * V_13 , T_4 V_15 , int V_82 )
{
void * V_98 = F_286 ( V_13 , V_15 , V_82 , V_297 ) ;
F_307 ( V_13 , V_98 , V_15 ) ;
F_315 ( V_297 , V_98 ,
V_13 -> V_204 , V_13 -> V_18 ,
V_15 , V_82 ) ;
return V_98 ;
}
void * F_316 ( struct V_12 * V_13 ,
T_4 V_15 ,
int V_82 ,
T_2 V_18 )
{
void * V_98 ;
V_98 = F_286 ( V_13 , V_15 , V_82 , V_297 ) ;
F_313 ( V_13 , V_98 , V_18 , V_15 ) ;
F_317 ( V_297 , V_98 ,
V_18 , V_13 -> V_18 ,
V_15 , V_82 ) ;
return V_98 ;
}
static T_9 void *
F_318 ( T_2 V_18 , T_4 V_15 , int V_55 , unsigned long V_203 )
{
struct V_12 * V_13 ;
void * V_98 ;
V_13 = F_186 ( V_18 , V_15 ) ;
if ( F_77 ( F_319 ( V_13 ) ) )
return V_13 ;
V_98 = F_316 ( V_13 , V_15 , V_55 , V_18 ) ;
F_313 ( V_13 , V_98 , V_18 , V_15 ) ;
return V_98 ;
}
void * F_320 ( T_2 V_18 , T_4 V_15 , int V_55 )
{
return F_318 ( V_18 , V_15 , V_55 , V_297 ) ;
}
void * F_321 ( T_2 V_18 , T_4 V_15 ,
int V_55 , unsigned long V_203 )
{
return F_318 ( V_18 , V_15 , V_55 , V_203 ) ;
}
static T_9 void * F_322 ( T_2 V_18 , T_4 V_15 ,
unsigned long V_203 )
{
struct V_12 * V_13 ;
void * V_98 ;
V_13 = F_186 ( V_18 , V_15 ) ;
if ( F_77 ( F_319 ( V_13 ) ) )
return V_13 ;
V_98 = F_292 ( V_13 , V_15 , V_203 ) ;
F_313 ( V_13 , V_98 , V_18 , V_15 ) ;
F_314 ( V_203 , V_98 ,
V_18 , V_13 -> V_18 , V_15 ) ;
return V_98 ;
}
void * F_323 ( T_2 V_18 , T_4 V_15 )
{
return F_322 ( V_18 , V_15 , V_297 ) ;
}
void * F_324 ( T_2 V_18 , T_4 V_15 , unsigned long V_203 )
{
return F_322 ( V_18 , V_15 , V_203 ) ;
}
void F_182 ( struct V_12 * V_13 , void * V_14 )
{
unsigned long V_15 ;
V_13 = F_325 ( V_13 , V_14 ) ;
if ( ! V_13 )
return;
F_288 ( V_15 ) ;
F_326 ( V_14 , V_13 -> V_204 ) ;
if ( ! ( V_13 -> V_15 & V_298 ) )
F_327 ( V_14 , V_13 -> V_204 ) ;
F_298 ( V_13 , V_14 , V_297 ) ;
F_289 ( V_15 ) ;
F_328 ( V_297 , V_14 ) ;
}
void F_329 ( struct V_12 * V_299 , T_2 V_18 , void * * V_247 )
{
struct V_12 * V_46 ;
T_2 V_88 ;
F_244 () ;
for ( V_88 = 0 ; V_88 < V_18 ; V_88 ++ ) {
void * V_14 = V_247 [ V_88 ] ;
if ( ! V_299 )
V_46 = F_14 ( V_14 ) ;
else
V_46 = F_325 ( V_299 , V_14 ) ;
F_326 ( V_14 , V_46 -> V_204 ) ;
if ( ! ( V_46 -> V_15 & V_298 ) )
F_327 ( V_14 , V_46 -> V_204 ) ;
F_298 ( V_46 , V_14 , V_297 ) ;
}
F_242 () ;
}
void F_66 ( const void * V_14 )
{
struct V_12 * V_300 ;
unsigned long V_15 ;
F_330 ( V_297 , V_14 ) ;
if ( F_77 ( F_319 ( V_14 ) ) )
return;
F_288 ( V_15 ) ;
F_250 ( V_14 ) ;
V_300 = F_14 ( V_14 ) ;
F_326 ( V_14 , V_300 -> V_204 ) ;
F_327 ( V_14 , V_300 -> V_204 ) ;
F_298 ( V_300 , ( void * ) V_14 , V_297 ) ;
F_289 ( V_15 ) ;
}
static int F_331 ( struct V_12 * V_13 , T_4 V_70 )
{
int V_98 ;
int V_55 ;
struct V_1 * V_72 ;
F_72 (node) {
V_98 = F_87 ( V_13 , V_55 , V_70 , true ) ;
if ( V_98 )
goto V_104;
}
return 0 ;
V_104:
if ( ! V_13 -> V_74 . V_264 ) {
V_55 -- ;
while ( V_55 >= 0 ) {
V_72 = F_49 ( V_13 , V_55 ) ;
if ( V_72 ) {
F_66 ( V_72 -> V_6 ) ;
F_57 ( V_72 -> V_7 ) ;
F_66 ( V_72 ) ;
V_13 -> V_55 [ V_55 ] = NULL ;
}
V_55 -- ;
}
}
return - V_94 ;
}
static int F_332 ( struct V_12 * V_13 , int V_64 ,
int V_67 , int V_6 , T_4 V_70 )
{
struct V_30 T_7 * V_31 , * V_248 ;
int V_52 ;
V_31 = F_187 ( V_13 , V_64 , V_67 ) ;
if ( ! V_31 )
return - V_94 ;
V_248 = V_13 -> V_31 ;
V_13 -> V_31 = V_31 ;
F_333 () ;
F_209 () ;
V_13 -> V_67 = V_67 ;
V_13 -> V_64 = V_64 ;
V_13 -> V_6 = V_6 ;
if ( ! V_248 )
goto V_301;
F_132 (cpu) {
F_47 ( V_74 ) ;
int V_55 ;
struct V_1 * V_72 ;
struct V_30 * V_63 = F_91 ( V_248 , V_52 ) ;
V_55 = F_33 ( V_52 ) ;
V_72 = F_49 ( V_13 , V_55 ) ;
F_83 ( & V_72 -> V_9 ) ;
F_51 ( V_13 , V_63 -> V_79 , V_63 -> V_66 , V_55 , & V_74 ) ;
F_70 ( & V_72 -> V_9 ) ;
F_53 ( V_13 , & V_74 ) ;
}
F_223 ( V_248 ) ;
V_301:
return F_331 ( V_13 , V_70 ) ;
}
static int F_334 ( struct V_12 * V_13 , int V_64 ,
int V_67 , int V_6 , T_4 V_70 )
{
int V_98 ;
struct V_12 * V_300 ;
V_98 = F_332 ( V_13 , V_64 , V_67 , V_6 , V_70 ) ;
if ( V_162 < V_172 )
return V_98 ;
if ( ( V_98 < 0 ) || ! F_335 ( V_13 ) )
return V_98 ;
F_336 ( & V_118 ) ;
F_337 (c, cachep) {
F_332 ( V_300 , V_64 , V_67 , V_6 , V_70 ) ;
}
return V_98 ;
}
static int F_127 ( struct V_12 * V_13 , T_4 V_70 )
{
int V_110 ;
int V_64 = 0 ;
int V_6 = 0 ;
int V_67 = 0 ;
V_110 = F_110 ( V_13 , V_70 ) ;
if ( V_110 )
goto V_302;
if ( ! F_335 ( V_13 ) ) {
struct V_12 * V_303 = F_338 ( V_13 ) ;
V_64 = V_303 -> V_64 ;
V_6 = V_303 -> V_6 ;
V_67 = V_303 -> V_67 ;
}
if ( V_64 && V_6 && V_67 )
goto V_304;
if ( V_13 -> V_18 > 131072 )
V_64 = 1 ;
else if ( V_13 -> V_18 > V_37 )
V_64 = 8 ;
else if ( V_13 -> V_18 > 1024 )
V_64 = 24 ;
else if ( V_13 -> V_18 > 256 )
V_64 = 54 ;
else
V_64 = 120 ;
V_6 = 0 ;
if ( V_13 -> V_18 <= V_37 && F_339 () > 1 )
V_6 = 8 ;
#if V_176
if ( V_64 > 32 )
V_64 = 32 ;
#endif
V_67 = ( V_64 + 1 ) / 2 ;
V_304:
V_110 = F_334 ( V_13 , V_64 , V_67 , V_6 , V_70 ) ;
V_302:
if ( V_110 )
F_23 ( L_29 ,
V_13 -> V_43 , - V_110 ) ;
return V_110 ;
}
static void F_340 ( struct V_12 * V_13 , struct V_1 * V_72 ,
struct V_30 * V_63 , int V_55 )
{
F_47 ( V_74 ) ;
F_210 () ;
if ( ! V_63 || ! V_63 -> V_66 )
return;
if ( V_63 -> V_68 ) {
V_63 -> V_68 = 0 ;
return;
}
F_83 ( & V_72 -> V_9 ) ;
F_216 ( V_13 , V_63 , V_55 , false , & V_74 ) ;
F_70 ( & V_72 -> V_9 ) ;
F_53 ( V_13 , & V_74 ) ;
}
static void V_61 ( struct V_305 * V_306 )
{
struct V_12 * V_307 ;
struct V_1 * V_72 ;
int V_55 = F_80 () ;
struct V_56 * V_59 = F_341 ( V_306 ) ;
if ( ! F_342 ( & V_118 ) )
goto V_136;
F_86 (searchp, &slab_caches, list) {
F_209 () ;
V_72 = F_49 ( V_307 , V_55 ) ;
F_68 ( V_307 , V_72 ) ;
F_340 ( V_307 , V_72 , F_19 ( V_307 ) , V_55 ) ;
if ( F_343 ( V_72 -> V_95 , V_96 ) )
goto V_264;
V_72 -> V_95 = V_96 + V_97 ;
F_340 ( V_307 , V_72 , V_72 -> V_6 , V_55 ) ;
if ( V_72 -> V_11 )
V_72 -> V_11 = 0 ;
else {
int V_308 ;
V_308 = F_93 ( V_307 , V_72 , ( V_72 -> V_93 +
5 * V_307 -> V_35 - 1 ) / ( 5 * V_307 -> V_35 ) ) ;
F_344 ( V_307 , V_308 ) ;
}
V_264:
F_345 () ;
}
F_209 () ;
F_97 ( & V_118 ) ;
F_34 () ;
V_136:
F_346 ( V_59 , F_347 ( V_309 ) ) ;
}
void F_348 ( struct V_12 * V_13 , struct V_310 * V_311 )
{
struct V_23 * V_23 ;
unsigned long V_180 ;
unsigned long V_181 ;
unsigned long V_182 = 0 ;
unsigned long V_183 , V_10 = 0 , V_312 = 0 ;
const char * V_43 ;
char * error = NULL ;
int V_55 ;
struct V_1 * V_72 ;
V_180 = 0 ;
V_183 = 0 ;
F_137 (cachep, node, n) {
F_209 () ;
F_83 ( & V_72 -> V_9 ) ;
F_86 (page, &n->slabs_full, lru) {
if ( V_23 -> V_184 != V_13 -> V_35 && ! error )
error = L_30 ;
V_180 += V_13 -> V_35 ;
V_182 ++ ;
}
F_86 (page, &n->slabs_partial, lru) {
if ( V_23 -> V_184 == V_13 -> V_35 && ! error )
error = L_31 ;
if ( ! V_23 -> V_184 && ! error )
error = L_31 ;
V_180 += V_23 -> V_184 ;
V_182 ++ ;
}
F_86 (page, &n->slabs_free, lru) {
if ( V_23 -> V_184 && ! error )
error = L_32 ;
V_183 ++ ;
}
V_10 += V_72 -> V_10 ;
if ( V_72 -> V_6 )
V_312 += V_72 -> V_6 -> V_66 ;
F_70 ( & V_72 -> V_9 ) ;
}
V_183 += V_182 ;
V_181 = V_183 * V_13 -> V_35 ;
if ( V_181 - V_180 != V_10 && ! error )
error = L_33 ;
V_43 = V_13 -> V_43 ;
if ( error )
F_23 ( L_34 , V_43 , error ) ;
V_311 -> V_180 = V_180 ;
V_311 -> V_181 = V_181 ;
V_311 -> V_182 = V_182 ;
V_311 -> V_183 = V_183 ;
V_311 -> V_312 = V_312 ;
V_311 -> V_64 = V_13 -> V_64 ;
V_311 -> V_67 = V_13 -> V_67 ;
V_311 -> V_6 = V_13 -> V_6 ;
V_311 -> V_313 = V_13 -> V_35 ;
V_311 -> V_314 = V_13 -> V_32 ;
}
void F_349 ( struct V_315 * V_316 , struct V_12 * V_13 )
{
#if V_295
{
unsigned long V_317 = V_13 -> V_318 ;
unsigned long V_319 = V_13 -> V_320 ;
unsigned long V_321 = V_13 -> V_321 ;
unsigned long V_322 = V_13 -> V_322 ;
unsigned long V_323 = V_13 -> V_323 ;
unsigned long V_324 = V_13 -> V_324 ;
unsigned long V_325 = V_13 -> V_325 ;
unsigned long V_326 = V_13 -> V_326 ;
unsigned long V_327 = V_13 -> V_328 ;
F_350 ( V_316 , L_35 ,
V_319 , V_317 , V_321 ,
V_322 , V_323 , V_324 , V_325 ,
V_326 , V_327 ) ;
}
{
unsigned long V_329 = F_10 ( & V_13 -> V_329 ) ;
unsigned long V_330 = F_10 ( & V_13 -> V_330 ) ;
unsigned long V_331 = F_10 ( & V_13 -> V_331 ) ;
unsigned long V_332 = F_10 ( & V_13 -> V_332 ) ;
F_350 ( V_316 , L_36 ,
V_329 , V_330 , V_331 , V_332 ) ;
}
#endif
}
T_10 F_351 ( struct V_333 * V_333 , const char T_11 * V_334 ,
T_2 V_149 , T_12 * V_335 )
{
char V_336 [ V_337 + 1 ] , * V_338 ;
int V_64 , V_67 , V_6 , V_339 ;
struct V_12 * V_13 ;
if ( V_149 > V_337 )
return - V_340 ;
if ( F_352 ( & V_336 , V_334 , V_149 ) )
return - V_341 ;
V_336 [ V_337 ] = '\0' ;
V_338 = strchr ( V_336 , ' ' ) ;
if ( ! V_338 )
return - V_340 ;
* V_338 = '\0' ;
V_338 ++ ;
if ( sscanf ( V_338 , L_37 , & V_64 , & V_67 , & V_6 ) != 3 )
return - V_340 ;
F_96 ( & V_118 ) ;
V_339 = - V_340 ;
F_86 (cachep, &slab_caches, list) {
if ( ! strcmp ( V_13 -> V_43 , V_336 ) ) {
if ( V_64 < 1 || V_67 < 1 ||
V_67 > V_64 || V_6 < 0 ) {
V_339 = 0 ;
} else {
V_339 = F_334 ( V_13 , V_64 ,
V_67 , V_6 ,
V_99 ) ;
}
break;
}
}
F_97 ( & V_118 ) ;
if ( V_339 >= 0 )
V_339 = V_149 ;
return V_339 ;
}
static inline int F_353 ( unsigned long * V_72 , unsigned long V_342 )
{
unsigned long * V_247 ;
int V_343 ;
if ( ! V_342 )
return 1 ;
V_343 = V_72 [ 1 ] ;
V_247 = V_72 + 2 ;
while ( V_343 ) {
int V_88 = V_343 / 2 ;
unsigned long * V_344 = V_247 + 2 * V_88 ;
if ( * V_344 == V_342 ) {
V_344 [ 1 ] ++ ;
return 1 ;
}
if ( * V_344 > V_342 ) {
V_343 = V_88 ;
} else {
V_247 = V_344 + 2 ;
V_343 -= V_88 + 1 ;
}
}
if ( ++ V_72 [ 1 ] == V_72 [ 0 ] )
return 0 ;
memmove ( V_247 + 2 , V_247 , V_72 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_247 - ( void * ) V_72 ) ) ;
V_247 [ 0 ] = V_342 ;
V_247 [ 1 ] = 1 ;
return 1 ;
}
static void F_354 ( unsigned long * V_72 , struct V_12 * V_300 ,
struct V_23 * V_23 )
{
void * V_247 ;
int V_88 , V_345 ;
unsigned long V_342 ;
if ( V_72 [ 0 ] == V_72 [ 1 ] )
return;
for ( V_88 = 0 , V_247 = V_23 -> V_27 ; V_88 < V_300 -> V_35 ; V_88 ++ , V_247 += V_300 -> V_18 ) {
bool V_184 = true ;
for ( V_345 = V_23 -> V_184 ; V_345 < V_300 -> V_35 ; V_345 ++ ) {
if ( F_227 ( V_23 , V_345 ) == V_88 ) {
V_184 = false ;
break;
}
}
if ( ! V_184 )
continue;
if ( F_355 ( & V_342 , F_8 ( V_300 , V_247 ) , sizeof( V_342 ) ) )
continue;
if ( ! F_353 ( V_72 , V_342 ) )
return;
}
}
static void F_356 ( struct V_315 * V_316 , unsigned long V_346 )
{
#ifdef F_357
unsigned long V_28 , V_18 ;
char V_347 [ V_348 ] , V_43 [ V_349 ] ;
if ( F_358 ( V_346 , & V_18 , & V_28 , V_347 , V_43 ) == 0 ) {
F_350 ( V_316 , L_38 , V_43 , V_28 , V_18 ) ;
if ( V_347 [ 0 ] )
F_350 ( V_316 , L_39 , V_347 ) ;
return;
}
#endif
F_350 ( V_316 , L_40 , ( void * ) V_346 ) ;
}
static int F_359 ( struct V_315 * V_316 , void * V_247 )
{
struct V_12 * V_13 = F_220 ( V_247 , struct V_12 , V_74 ) ;
struct V_23 * V_23 ;
struct V_1 * V_72 ;
const char * V_43 ;
unsigned long * V_350 = V_316 -> V_351 ;
int V_55 ;
int V_88 ;
if ( ! ( V_13 -> V_15 & V_17 ) )
return 0 ;
if ( ! ( V_13 -> V_15 & V_16 ) )
return 0 ;
do {
F_11 ( V_13 ) ;
F_218 ( V_13 ) ;
V_350 [ 1 ] = 0 ;
F_137 (cachep, node, n) {
F_209 () ;
F_83 ( & V_72 -> V_9 ) ;
F_86 (page, &n->slabs_full, lru)
F_354 ( V_350 , V_13 , V_23 ) ;
F_86 (page, &n->slabs_partial, lru)
F_354 ( V_350 , V_13 , V_23 ) ;
F_70 ( & V_72 -> V_9 ) ;
}
} while ( ! F_9 ( V_13 ) );
V_43 = V_13 -> V_43 ;
if ( V_350 [ 0 ] == V_350 [ 1 ] ) {
F_97 ( & V_118 ) ;
V_316 -> V_351 = F_360 ( V_350 [ 0 ] * 4 * sizeof( unsigned long ) , V_99 ) ;
if ( ! V_316 -> V_351 ) {
V_316 -> V_351 = V_350 ;
F_96 ( & V_118 ) ;
return - V_94 ;
}
* ( unsigned long * ) V_316 -> V_351 = V_350 [ 0 ] * 2 ;
F_66 ( V_350 ) ;
F_96 ( & V_118 ) ;
V_316 -> V_149 = V_316 -> V_18 ;
return 0 ;
}
for ( V_88 = 0 ; V_88 < V_350 [ 1 ] ; V_88 ++ ) {
F_350 ( V_316 , L_41 , V_43 , V_350 [ 2 * V_88 + 3 ] ) ;
F_356 ( V_316 , V_350 [ 2 * V_88 + 2 ] ) ;
F_361 ( V_316 , '\n' ) ;
}
return 0 ;
}
static int F_362 ( struct V_352 * V_352 , struct V_333 * V_333 )
{
unsigned long * V_72 ;
V_72 = F_363 ( V_333 , & V_353 , V_37 ) ;
if ( ! V_72 )
return - V_94 ;
* V_72 = V_37 / ( 2 * sizeof( unsigned long ) ) ;
return 0 ;
}
static int T_3 F_364 ( void )
{
#ifdef F_365
F_366 ( L_42 , 0 , NULL , & V_354 ) ;
#endif
return 0 ;
}
T_2 F_367 ( const void * V_14 )
{
T_2 V_18 ;
F_6 ( ! V_14 ) ;
if ( F_77 ( V_14 == V_355 ) )
return 0 ;
V_18 = F_14 ( V_14 ) -> V_204 ;
F_368 ( V_14 , V_18 ) ;
return V_18 ;
}
