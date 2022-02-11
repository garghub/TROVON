static inline bool F_1 ( void * V_1 )
{
return ( unsigned long ) V_1 & V_2 ;
}
static inline void F_2 ( void * * V_1 )
{
* V_1 = ( void * ) ( ( unsigned long ) * V_1 | V_2 ) ;
return;
}
static inline void F_3 ( void * * V_1 )
{
* V_1 = ( void * ) ( ( unsigned long ) * V_1 & ~ V_2 ) ;
}
static void F_4 ( struct V_3 * V_4 )
{
F_5 ( & V_4 -> V_5 ) ;
F_5 ( & V_4 -> V_6 ) ;
F_5 ( & V_4 -> V_7 ) ;
V_4 -> V_8 = NULL ;
V_4 -> V_9 = NULL ;
V_4 -> V_10 = 0 ;
F_6 ( & V_4 -> V_11 ) ;
V_4 -> V_12 = 0 ;
V_4 -> V_13 = 0 ;
}
static int F_7 ( struct V_14 * V_15 )
{
return V_15 -> F_7 ;
}
static unsigned long long * F_8 ( struct V_14 * V_15 , void * V_1 )
{
F_9 ( ! ( V_15 -> V_16 & V_17 ) ) ;
return ( unsigned long long * ) ( V_1 + F_7 ( V_15 ) -
sizeof( unsigned long long ) ) ;
}
static unsigned long long * F_10 ( struct V_14 * V_15 , void * V_1 )
{
F_9 ( ! ( V_15 -> V_16 & V_17 ) ) ;
if ( V_15 -> V_16 & V_18 )
return ( unsigned long long * ) ( V_1 + V_15 -> V_19 -
sizeof( unsigned long long ) -
V_20 ) ;
return ( unsigned long long * ) ( V_1 + V_15 -> V_19 -
sizeof( unsigned long long ) ) ;
}
static void * * F_11 ( struct V_14 * V_15 , void * V_1 )
{
F_9 ( ! ( V_15 -> V_16 & V_18 ) ) ;
return ( void * * ) ( V_1 + V_15 -> V_19 - V_21 ) ;
}
static void F_12 ( struct V_22 * V_22 , int V_23 , int V_24 )
{
int V_25 ;
char * V_26 ;
struct V_14 * V_15 = V_22 -> V_27 ;
V_25 = V_15 -> V_28 * sizeof( V_29 ) ;
V_26 = ( char * ) V_22 -> V_30 + V_25 ;
V_26 [ V_23 ] = V_24 ;
}
static inline unsigned int F_13 ( struct V_22 * V_22 , int V_23 )
{
int V_25 ;
char * V_26 ;
struct V_14 * V_15 = V_22 -> V_27 ;
V_25 = V_15 -> V_28 * sizeof( V_29 ) ;
V_26 = ( char * ) V_22 -> V_30 + V_25 ;
return V_26 [ V_23 ] ;
}
static inline void F_12 ( struct V_22 * V_22 , int V_23 , int V_24 ) {}
static inline struct V_14 * F_14 ( const void * V_31 )
{
struct V_22 * V_22 = F_15 ( V_31 ) ;
return V_22 -> V_27 ;
}
static inline void * F_16 ( struct V_14 * V_32 , struct V_22 * V_22 ,
unsigned int V_23 )
{
return V_22 -> V_33 + V_32 -> V_19 * V_23 ;
}
static inline unsigned int F_17 ( const struct V_14 * V_32 ,
const struct V_22 * V_22 , void * V_31 )
{
T_1 V_34 = ( V_31 - V_22 -> V_33 ) ;
return F_18 ( V_34 , V_32 -> V_35 ) ;
}
static inline struct V_36 * F_19 ( struct V_14 * V_15 )
{
return F_20 ( V_15 -> V_37 ) ;
}
static T_2 F_21 ( int V_38 , T_2 V_39 )
{
T_2 V_25 ;
V_25 = V_38 * sizeof( V_29 ) ;
if ( F_22 ( V_40 ) )
V_25 += V_38 * sizeof( char ) ;
if ( V_39 )
V_25 = F_23 ( V_25 , V_39 ) ;
return V_25 ;
}
static int F_24 ( T_2 V_41 , T_2 V_42 ,
T_2 V_43 , T_2 V_39 )
{
int V_38 ;
T_2 V_44 ;
T_2 V_25 ;
int V_45 = 0 ;
if ( F_22 ( V_40 ) )
V_45 = sizeof( char ) ;
V_38 = V_41 / ( V_42 + V_43 + V_45 ) ;
V_44 = V_41 - V_38 * V_42 ;
V_25 = F_21 ( V_38 , V_39 ) ;
if ( V_44 < V_25 )
V_38 -- ;
return V_38 ;
}
static void F_25 ( unsigned long V_46 , T_2 V_42 ,
T_2 V_39 , int V_16 , T_2 * V_47 ,
unsigned int * V_28 )
{
int V_38 ;
T_2 V_48 ;
T_2 V_41 = V_49 << V_46 ;
if ( V_16 & V_50 ) {
V_48 = 0 ;
V_38 = V_41 / V_42 ;
} else {
V_38 = F_24 ( V_41 , V_42 ,
sizeof( V_29 ) , V_39 ) ;
V_48 = F_21 ( V_38 , V_39 ) ;
}
* V_28 = V_38 ;
* V_47 = V_41 - V_38 * V_42 - V_48 ;
}
static void F_26 ( const char * V_51 , struct V_14 * V_15 ,
char * V_52 )
{
F_27 ( V_53 L_1 ,
V_51 , V_15 -> V_54 , V_52 ) ;
F_28 () ;
F_29 ( V_55 , V_56 ) ;
}
static int T_3 F_30 ( char * V_57 )
{
V_58 = 0 ;
return 1 ;
}
static int T_3 F_31 ( char * V_59 )
{
F_32 ( & V_59 , & V_60 ) ;
V_60 = V_60 < 0 ? 0 :
F_33 ( V_60 , V_61 - 1 ) ;
V_62 = true ;
return 1 ;
}
static void F_34 ( int V_63 )
{
int V_64 ;
V_64 = F_35 ( F_36 ( V_63 ) , V_65 ) ;
if ( V_64 == V_66 )
V_64 = F_37 ( V_65 ) ;
F_38 ( V_67 , V_63 ) = V_64 ;
}
static void F_39 ( void )
{
int V_64 = F_40 ( V_67 ) ;
V_64 = F_35 ( V_64 , V_65 ) ;
if ( F_41 ( V_64 >= V_66 ) )
V_64 = F_37 ( V_65 ) ;
F_42 ( V_67 , V_64 ) ;
}
static void F_43 ( int V_63 )
{
struct V_68 * V_69 = & F_38 ( V_70 , V_63 ) ;
if ( F_44 () && V_69 -> V_71 . V_72 == NULL ) {
F_34 ( V_63 ) ;
F_45 ( V_69 , V_73 ) ;
F_46 ( V_63 , V_69 ,
F_47 ( V_74 , V_63 ) ) ;
}
}
static void F_48 ( struct V_36 * V_75 , int V_76 , int V_77 )
{
F_49 ( V_75 ) ;
if ( V_75 ) {
V_75 -> V_78 = 0 ;
V_75 -> V_76 = V_76 ;
V_75 -> V_79 = V_77 ;
V_75 -> V_80 = 0 ;
}
}
static struct V_36 * F_50 ( int V_64 , int V_81 ,
int V_79 , T_4 V_82 )
{
T_2 V_83 = sizeof( void * ) * V_81 + sizeof( struct V_36 ) ;
struct V_36 * V_75 = NULL ;
V_75 = F_51 ( V_83 , V_82 , V_64 ) ;
F_48 ( V_75 , V_81 , V_79 ) ;
return V_75 ;
}
static inline bool F_52 ( struct V_22 * V_22 )
{
return F_53 ( V_22 ) ;
}
static void F_54 ( struct V_14 * V_15 ,
struct V_36 * V_75 )
{
struct V_3 * V_84 = F_55 ( V_15 , F_56 () ) ;
struct V_22 * V_22 ;
unsigned long V_16 ;
if ( ! V_85 )
return;
F_57 ( & V_84 -> V_11 , V_16 ) ;
F_58 (page, &n->slabs_full, lru)
if ( F_52 ( V_22 ) )
goto V_86;
F_58 (page, &n->slabs_partial, lru)
if ( F_52 ( V_22 ) )
goto V_86;
F_58 (page, &n->slabs_free, lru)
if ( F_52 ( V_22 ) )
goto V_86;
V_85 = false ;
V_86:
F_59 ( & V_84 -> V_11 , V_16 ) ;
}
static void * F_60 ( struct V_14 * V_15 , struct V_36 * V_75 ,
T_4 V_16 , bool V_87 )
{
int V_88 ;
void * V_1 = V_75 -> V_89 [ -- V_75 -> V_78 ] ;
if ( F_41 ( F_1 ( V_1 ) ) ) {
struct V_3 * V_84 ;
if ( F_61 ( V_16 ) ) {
F_3 ( & V_1 ) ;
return V_1 ;
}
for ( V_88 = 0 ; V_88 < V_75 -> V_78 ; V_88 ++ ) {
if ( ! F_1 ( V_75 -> V_89 [ V_88 ] ) ) {
V_1 = V_75 -> V_89 [ V_88 ] ;
V_75 -> V_89 [ V_88 ] = V_75 -> V_89 [ V_75 -> V_78 ] ;
V_75 -> V_89 [ V_75 -> V_78 ] = V_1 ;
return V_1 ;
}
}
V_84 = F_55 ( V_15 , F_56 () ) ;
if ( ! F_62 ( & V_84 -> V_7 ) && V_87 ) {
struct V_22 * V_22 = F_15 ( V_1 ) ;
F_63 ( V_22 ) ;
F_3 ( & V_1 ) ;
F_54 ( V_15 , V_75 ) ;
return V_1 ;
}
V_75 -> V_78 ++ ;
V_1 = NULL ;
}
return V_1 ;
}
static inline void * F_64 ( struct V_14 * V_15 ,
struct V_36 * V_75 , T_4 V_16 , bool V_87 )
{
void * V_1 ;
if ( F_41 ( F_65 () ) )
V_1 = F_60 ( V_15 , V_75 , V_16 , V_87 ) ;
else
V_1 = V_75 -> V_89 [ -- V_75 -> V_78 ] ;
return V_1 ;
}
static T_5 void * F_66 ( struct V_14 * V_15 ,
struct V_36 * V_75 , void * V_1 )
{
if ( F_41 ( V_85 ) ) {
struct V_22 * V_22 = F_15 ( V_1 ) ;
if ( F_53 ( V_22 ) )
F_2 ( & V_1 ) ;
}
return V_1 ;
}
static inline void F_67 ( struct V_14 * V_15 , struct V_36 * V_75 ,
void * V_1 )
{
if ( F_41 ( F_65 () ) )
V_1 = F_66 ( V_15 , V_75 , V_1 ) ;
V_75 -> V_89 [ V_75 -> V_78 ++ ] = V_1 ;
}
static int F_68 ( struct V_36 * V_90 ,
struct V_36 * V_91 , unsigned int V_92 )
{
int V_93 = F_69 ( V_91 -> V_78 , V_92 , V_90 -> V_76 - V_90 -> V_78 ) ;
if ( ! V_93 )
return 0 ;
memcpy ( V_90 -> V_89 + V_90 -> V_78 , V_91 -> V_89 + V_91 -> V_78 - V_93 ,
sizeof( void * ) * V_93 ) ;
V_91 -> V_78 -= V_93 ;
V_90 -> V_78 += V_93 ;
return V_93 ;
}
static inline struct V_94 * * F_70 ( int V_64 ,
int V_76 , T_4 V_82 )
{
return (struct V_94 * * ) V_95 ;
}
static inline void F_71 ( struct V_94 * * V_96 )
{
}
static inline int F_72 ( struct V_14 * V_15 , void * V_1 )
{
return 0 ;
}
static inline void * F_73 ( struct V_14 * V_15 ,
T_4 V_16 )
{
return NULL ;
}
static inline void * F_74 ( struct V_14 * V_15 ,
T_4 V_16 , int V_97 )
{
return NULL ;
}
static inline T_4 F_75 ( T_4 V_16 )
{
return V_16 ;
}
static struct V_94 * F_76 ( int V_64 , int V_81 ,
int V_77 , T_4 V_82 )
{
T_2 V_83 = sizeof( void * ) * V_81 + sizeof( struct V_94 ) ;
struct V_94 * V_98 = NULL ;
V_98 = F_51 ( V_83 , V_82 , V_64 ) ;
F_48 ( & V_98 -> V_75 , V_81 , V_77 ) ;
F_6 ( & V_98 -> V_99 ) ;
return V_98 ;
}
static struct V_94 * * F_70 ( int V_64 , int V_76 , T_4 V_82 )
{
struct V_94 * * V_100 ;
T_2 V_83 = sizeof( void * ) * V_101 ;
int V_88 ;
if ( V_76 > 1 )
V_76 = 12 ;
V_100 = F_77 ( V_83 , V_82 , V_64 ) ;
if ( ! V_100 )
return NULL ;
F_78 (i) {
if ( V_88 == V_64 || ! F_79 ( V_88 ) )
continue;
V_100 [ V_88 ] = F_76 ( V_64 , V_76 , 0xbaadf00d , V_82 ) ;
if ( ! V_100 [ V_88 ] ) {
for ( V_88 -- ; V_88 >= 0 ; V_88 -- )
F_80 ( V_100 [ V_88 ] ) ;
F_80 ( V_100 ) ;
return NULL ;
}
}
return V_100 ;
}
static void F_71 ( struct V_94 * * V_100 )
{
int V_88 ;
if ( ! V_100 )
return;
F_78 (i)
F_80 ( V_100 [ V_88 ] ) ;
F_80 ( V_100 ) ;
}
static void F_81 ( struct V_14 * V_15 ,
struct V_36 * V_75 , int V_64 ,
struct V_102 * V_103 )
{
struct V_3 * V_84 = F_55 ( V_15 , V_64 ) ;
if ( V_75 -> V_78 ) {
F_82 ( & V_84 -> V_11 ) ;
if ( V_84 -> V_8 )
F_68 ( V_84 -> V_8 , V_75 , V_75 -> V_76 ) ;
F_83 ( V_15 , V_75 -> V_89 , V_75 -> V_78 , V_64 , V_103 ) ;
V_75 -> V_78 = 0 ;
F_84 ( & V_84 -> V_11 ) ;
}
}
static void F_85 ( struct V_14 * V_15 , struct V_3 * V_84 )
{
int V_64 = F_40 ( V_67 ) ;
if ( V_84 -> V_9 ) {
struct V_94 * V_98 = V_84 -> V_9 [ V_64 ] ;
struct V_36 * V_75 ;
if ( V_98 ) {
V_75 = & V_98 -> V_75 ;
if ( V_75 -> V_78 && F_86 ( & V_98 -> V_99 ) ) {
F_87 ( V_103 ) ;
F_81 ( V_15 , V_75 , V_64 , & V_103 ) ;
F_88 ( & V_98 -> V_99 ) ;
F_89 ( V_15 , & V_103 ) ;
}
}
}
}
static void F_90 ( struct V_14 * V_15 ,
struct V_94 * * V_9 )
{
int V_88 = 0 ;
struct V_94 * V_98 ;
struct V_36 * V_75 ;
unsigned long V_16 ;
F_91 (i) {
V_98 = V_9 [ V_88 ] ;
if ( V_98 ) {
F_87 ( V_103 ) ;
V_75 = & V_98 -> V_75 ;
F_57 ( & V_98 -> V_99 , V_16 ) ;
F_81 ( V_15 , V_75 , V_88 , & V_103 ) ;
F_59 ( & V_98 -> V_99 , V_16 ) ;
F_89 ( V_15 , & V_103 ) ;
}
}
}
static int F_92 ( struct V_14 * V_15 , void * V_1 ,
int V_64 , int V_104 )
{
struct V_3 * V_84 ;
struct V_94 * V_9 = NULL ;
struct V_36 * V_75 ;
F_87 ( V_103 ) ;
V_84 = F_55 ( V_15 , V_64 ) ;
F_93 ( V_15 ) ;
if ( V_84 -> V_9 && V_84 -> V_9 [ V_104 ] ) {
V_9 = V_84 -> V_9 [ V_104 ] ;
V_75 = & V_9 -> V_75 ;
F_82 ( & V_9 -> V_99 ) ;
if ( F_41 ( V_75 -> V_78 == V_75 -> V_76 ) ) {
F_94 ( V_15 ) ;
F_81 ( V_15 , V_75 , V_104 , & V_103 ) ;
}
F_67 ( V_15 , V_75 , V_1 ) ;
F_84 ( & V_9 -> V_99 ) ;
F_89 ( V_15 , & V_103 ) ;
} else {
V_84 = F_55 ( V_15 , V_104 ) ;
F_82 ( & V_84 -> V_11 ) ;
F_83 ( V_15 , & V_1 , 1 , V_104 , & V_103 ) ;
F_84 ( & V_84 -> V_11 ) ;
F_89 ( V_15 , & V_103 ) ;
}
return 1 ;
}
static inline int F_72 ( struct V_14 * V_15 , void * V_1 )
{
int V_104 = F_95 ( F_96 ( V_1 ) ) ;
int V_64 = F_56 () ;
if ( F_97 ( V_64 == V_104 ) )
return 0 ;
return F_92 ( V_15 , V_1 , V_64 , V_104 ) ;
}
static inline T_4 F_75 ( T_4 V_16 )
{
return ( V_16 | V_105 | V_106 ) & ~ V_107 ;
}
static int F_98 ( int V_64 )
{
struct V_14 * V_15 ;
struct V_3 * V_84 ;
const T_2 V_83 = sizeof( struct V_3 ) ;
F_58 (cachep, &slab_caches, list) {
V_84 = F_55 ( V_15 , V_64 ) ;
if ( ! V_84 ) {
V_84 = F_51 ( V_83 , V_108 , V_64 ) ;
if ( ! V_84 )
return - V_109 ;
F_4 ( V_84 ) ;
V_84 -> V_110 = V_111 + V_112 +
( ( unsigned long ) V_15 ) % V_112 ;
V_15 -> V_64 [ V_64 ] = V_84 ;
}
F_99 ( & V_84 -> V_11 ) ;
V_84 -> V_113 =
( 1 + F_100 ( V_64 ) ) *
V_15 -> V_79 + V_15 -> V_28 ;
F_88 ( & V_84 -> V_11 ) ;
}
return 0 ;
}
static inline int F_101 ( struct V_14 * V_15 ,
struct V_3 * V_84 )
{
return ( V_84 -> V_12 + V_15 -> V_28 - 1 ) / V_15 -> V_28 ;
}
static void F_102 ( long V_63 )
{
struct V_14 * V_15 ;
struct V_3 * V_84 = NULL ;
int V_64 = F_36 ( V_63 ) ;
const struct V_114 * V_115 = F_103 ( V_64 ) ;
F_58 (cachep, &slab_caches, list) {
struct V_36 * V_116 ;
struct V_36 * V_8 ;
struct V_94 * * V_9 ;
F_87 ( V_103 ) ;
V_84 = F_55 ( V_15 , V_64 ) ;
if ( ! V_84 )
continue;
F_99 ( & V_84 -> V_11 ) ;
V_84 -> V_113 -= V_15 -> V_79 ;
V_116 = F_104 ( V_15 -> V_37 , V_63 ) ;
if ( V_116 ) {
F_83 ( V_15 , V_116 -> V_89 , V_116 -> V_78 , V_64 , & V_103 ) ;
V_116 -> V_78 = 0 ;
}
if ( ! F_105 ( V_115 ) ) {
F_88 ( & V_84 -> V_11 ) ;
goto V_117;
}
V_8 = V_84 -> V_8 ;
if ( V_8 ) {
F_83 ( V_15 , V_8 -> V_89 ,
V_8 -> V_78 , V_64 , & V_103 ) ;
V_84 -> V_8 = NULL ;
}
V_9 = V_84 -> V_9 ;
V_84 -> V_9 = NULL ;
F_88 ( & V_84 -> V_11 ) ;
F_80 ( V_8 ) ;
if ( V_9 ) {
F_90 ( V_15 , V_9 ) ;
F_71 ( V_9 ) ;
}
V_117:
F_89 ( V_15 , & V_103 ) ;
}
F_58 (cachep, &slab_caches, list) {
V_84 = F_55 ( V_15 , V_64 ) ;
if ( ! V_84 )
continue;
F_106 ( V_15 , V_84 , F_101 ( V_15 , V_84 ) ) ;
}
}
static int F_107 ( long V_63 )
{
struct V_14 * V_15 ;
struct V_3 * V_84 = NULL ;
int V_64 = F_36 ( V_63 ) ;
int V_118 ;
V_118 = F_98 ( V_64 ) ;
if ( V_118 < 0 )
goto V_119;
F_58 (cachep, &slab_caches, list) {
struct V_36 * V_8 = NULL ;
struct V_94 * * V_9 = NULL ;
if ( V_15 -> V_8 ) {
V_8 = F_50 ( V_64 ,
V_15 -> V_8 * V_15 -> V_79 ,
0xbaadf00d , V_108 ) ;
if ( ! V_8 )
goto V_119;
}
if ( V_58 ) {
V_9 = F_70 ( V_64 , V_15 -> V_76 , V_108 ) ;
if ( ! V_9 ) {
F_80 ( V_8 ) ;
goto V_119;
}
}
V_84 = F_55 ( V_15 , V_64 ) ;
F_9 ( ! V_84 ) ;
F_99 ( & V_84 -> V_11 ) ;
if ( ! V_84 -> V_8 ) {
V_84 -> V_8 = V_8 ;
V_8 = NULL ;
}
#ifdef F_108
if ( ! V_84 -> V_9 ) {
V_84 -> V_9 = V_9 ;
V_9 = NULL ;
}
#endif
F_88 ( & V_84 -> V_11 ) ;
F_80 ( V_8 ) ;
F_71 ( V_9 ) ;
}
return 0 ;
V_119:
F_102 ( V_63 ) ;
return - V_109 ;
}
static int F_109 ( struct V_120 * V_121 ,
unsigned long V_122 , void * V_123 )
{
long V_63 = ( long ) V_123 ;
int V_118 = 0 ;
switch ( V_122 ) {
case V_124 :
case V_125 :
F_110 ( & V_126 ) ;
V_118 = F_107 ( V_63 ) ;
F_111 ( & V_126 ) ;
break;
case V_127 :
case V_128 :
F_43 ( V_63 ) ;
break;
#ifdef F_112
case V_129 :
case V_130 :
F_113 ( & F_38 ( V_70 , V_63 ) ) ;
F_38 ( V_70 , V_63 ) . V_71 . V_72 = NULL ;
break;
case V_131 :
case V_132 :
F_43 ( V_63 ) ;
break;
case V_133 :
case V_134 :
#endif
case V_135 :
case V_136 :
F_110 ( & V_126 ) ;
F_102 ( V_63 ) ;
F_111 ( & V_126 ) ;
break;
}
return F_114 ( V_118 ) ;
}
static int T_6 F_115 ( int V_64 )
{
struct V_14 * V_15 ;
int V_137 = 0 ;
F_58 (cachep, &slab_caches, list) {
struct V_3 * V_84 ;
V_84 = F_55 ( V_15 , V_64 ) ;
if ( ! V_84 )
continue;
F_106 ( V_15 , V_84 , F_101 ( V_15 , V_84 ) ) ;
if ( ! F_62 ( & V_84 -> V_5 ) ||
! F_62 ( & V_84 -> V_6 ) ) {
V_137 = - V_138 ;
break;
}
}
return V_137 ;
}
static int T_6 F_116 ( struct V_120 * V_139 ,
unsigned long V_122 , void * V_140 )
{
struct V_141 * V_142 = V_140 ;
int V_137 = 0 ;
int V_143 ;
V_143 = V_142 -> V_144 ;
if ( V_143 < 0 )
goto V_86;
switch ( V_122 ) {
case V_145 :
F_110 ( & V_126 ) ;
V_137 = F_98 ( V_143 ) ;
F_111 ( & V_126 ) ;
break;
case V_146 :
F_110 ( & V_126 ) ;
V_137 = F_115 ( V_143 ) ;
F_111 ( & V_126 ) ;
break;
case V_147 :
case V_148 :
case V_149 :
case V_150 :
break;
}
V_86:
return F_114 ( V_137 ) ;
}
static void T_3 F_117 ( struct V_14 * V_15 , struct V_3 * V_103 ,
int V_97 )
{
struct V_3 * V_151 ;
V_151 = F_51 ( sizeof( struct V_3 ) , V_152 , V_97 ) ;
F_9 ( ! V_151 ) ;
memcpy ( V_151 , V_103 , sizeof( struct V_3 ) ) ;
F_6 ( & V_151 -> V_11 ) ;
F_118 ( V_15 , V_151 , V_97 ) ;
V_15 -> V_64 [ V_97 ] = V_151 ;
}
static void T_3 F_119 ( struct V_14 * V_15 , int V_153 )
{
int V_64 ;
F_91 (node) {
V_15 -> V_64 [ V_64 ] = & V_154 [ V_153 + V_64 ] ;
V_15 -> V_64 [ V_64 ] -> V_110 = V_111 +
V_112 +
( ( unsigned long ) V_15 ) % V_112 ;
}
}
void T_3 F_120 ( void )
{
int V_88 ;
F_121 ( sizeof( ( (struct V_22 * ) NULL ) -> V_155 ) <
sizeof( struct V_156 ) ) ;
V_14 = & V_157 ;
if ( F_122 () == 1 )
V_58 = 0 ;
for ( V_88 = 0 ; V_88 < V_158 ; V_88 ++ )
F_4 ( & V_154 [ V_88 ] ) ;
if ( ! V_62 && V_159 > ( 32 << 20 ) >> V_160 )
V_60 = V_161 ;
F_123 ( V_14 , L_2 ,
F_124 ( struct V_14 , V_64 ) +
V_101 * sizeof( struct V_3 * ) ,
V_162 ) ;
F_125 ( & V_14 -> V_103 , & V_163 ) ;
V_164 = V_165 ;
V_166 [ V_167 ] = F_126 ( L_3 ,
F_127 ( V_167 ) , V_168 ) ;
V_164 = V_169 ;
V_170 = 0 ;
{
int V_143 ;
F_91 (nid) {
F_117 ( V_14 , & V_154 [ V_171 + V_143 ] , V_143 ) ;
F_117 ( V_166 [ V_167 ] ,
& V_154 [ V_172 + V_143 ] , V_143 ) ;
}
}
F_128 ( V_168 ) ;
}
void T_3 F_129 ( void )
{
struct V_14 * V_15 ;
V_164 = V_173 ;
F_110 ( & V_126 ) ;
F_58 (cachep, &slab_caches, list)
if ( F_130 ( V_15 , V_152 ) )
F_131 () ;
F_111 ( & V_126 ) ;
V_164 = V_174 ;
F_132 ( & V_175 ) ;
#ifdef F_108
F_133 ( F_116 , V_176 ) ;
#endif
}
static int T_3 F_134 ( void )
{
int V_63 ;
F_135 (cpu)
F_43 ( V_63 ) ;
V_164 = V_174 ;
return 0 ;
}
static T_5 void
F_136 ( struct V_14 * V_15 , T_4 V_177 , int V_97 )
{
#if V_178
struct V_3 * V_84 ;
struct V_22 * V_22 ;
unsigned long V_16 ;
int V_64 ;
static F_137 ( V_179 , V_180 ,
V_181 ) ;
if ( ( V_177 & V_106 ) || ! F_138 ( & V_179 ) )
return;
F_27 ( V_182
L_4 ,
V_97 , V_177 ) ;
F_27 ( V_182 L_5 ,
V_15 -> V_54 , V_15 -> V_19 , V_15 -> V_46 ) ;
F_139 (cachep, node, n) {
unsigned long V_183 = 0 , V_184 = 0 , V_12 = 0 ;
unsigned long V_185 = 0 , V_186 = 0 ;
F_57 ( & V_84 -> V_11 , V_16 ) ;
F_58 (page, &n->slabs_full, lru) {
V_183 += V_15 -> V_28 ;
V_185 ++ ;
}
F_58 (page, &n->slabs_partial, lru) {
V_183 += V_22 -> V_187 ;
V_185 ++ ;
}
F_58 (page, &n->slabs_free, lru)
V_186 ++ ;
V_12 += V_84 -> V_12 ;
F_59 ( & V_84 -> V_11 , V_16 ) ;
V_186 += V_185 ;
V_184 = V_186 * V_15 -> V_28 ;
F_27 ( V_182
L_6 ,
V_64 , V_185 , V_186 , V_183 , V_184 ,
V_12 ) ;
}
#endif
}
static struct V_22 * F_140 ( struct V_14 * V_15 , T_4 V_16 ,
int V_97 )
{
struct V_22 * V_22 ;
int V_188 ;
V_16 |= V_15 -> V_189 ;
if ( V_15 -> V_16 & V_190 )
V_16 |= V_191 ;
if ( F_141 ( V_15 , V_16 , V_15 -> V_46 ) )
return NULL ;
V_22 = F_142 ( V_97 , V_16 | V_192 , V_15 -> V_46 ) ;
if ( ! V_22 ) {
F_143 ( V_15 , V_15 -> V_46 ) ;
F_136 ( V_15 , V_16 , V_97 ) ;
return NULL ;
}
if ( F_41 ( V_22 -> V_193 ) )
V_85 = true ;
V_188 = ( 1 << V_15 -> V_46 ) ;
if ( V_15 -> V_16 & V_190 )
F_144 ( F_145 ( V_22 ) ,
V_194 , V_188 ) ;
else
F_144 ( F_145 ( V_22 ) ,
V_195 , V_188 ) ;
F_146 ( V_22 ) ;
if ( V_22 -> V_193 )
F_147 ( V_22 ) ;
if ( V_196 && ! ( V_15 -> V_16 & V_197 ) ) {
F_148 ( V_22 , V_15 -> V_46 , V_16 , V_97 ) ;
if ( V_15 -> V_198 )
F_149 ( V_22 , V_188 ) ;
else
F_150 ( V_22 , V_188 ) ;
}
return V_22 ;
}
static void F_151 ( struct V_14 * V_15 , struct V_22 * V_22 )
{
const unsigned long V_199 = ( 1 << V_15 -> V_46 ) ;
F_152 ( V_22 , V_15 -> V_46 ) ;
if ( V_15 -> V_16 & V_190 )
F_153 ( F_145 ( V_22 ) ,
V_194 , V_199 ) ;
else
F_153 ( F_145 ( V_22 ) ,
V_195 , V_199 ) ;
F_9 ( ! F_154 ( V_22 ) ) ;
F_155 ( V_22 ) ;
F_156 ( V_22 ) ;
F_157 ( V_22 ) ;
V_22 -> V_200 = NULL ;
if ( V_201 -> V_202 )
V_201 -> V_202 -> V_203 += V_199 ;
F_158 ( V_22 , V_15 -> V_46 ) ;
F_143 ( V_15 , V_15 -> V_46 ) ;
}
static void F_159 ( struct V_156 * V_204 )
{
struct V_14 * V_15 ;
struct V_22 * V_22 ;
V_22 = F_160 ( V_204 , struct V_22 , V_156 ) ;
V_15 = V_22 -> V_27 ;
F_151 ( V_15 , V_22 ) ;
}
static void F_161 ( struct V_14 * V_15 , unsigned long * V_205 ,
unsigned long V_206 )
{
int V_19 = V_15 -> V_207 ;
V_205 = ( unsigned long * ) & ( ( char * ) V_205 ) [ F_7 ( V_15 ) ] ;
if ( V_19 < 5 * sizeof( unsigned long ) )
return;
* V_205 ++ = 0x12345678 ;
* V_205 ++ = V_206 ;
* V_205 ++ = F_162 () ;
V_19 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_208 = & V_206 ;
unsigned long V_209 ;
while ( ! F_163 ( V_208 ) ) {
V_209 = * V_208 ++ ;
if ( F_164 ( V_209 ) ) {
* V_205 ++ = V_209 ;
V_19 -= sizeof( unsigned long ) ;
if ( V_19 <= sizeof( unsigned long ) )
break;
}
}
}
* V_205 ++ = 0x87654321 ;
}
static void F_165 ( struct V_14 * V_15 , void * V_205 , unsigned char V_24 )
{
int V_19 = V_15 -> V_207 ;
V_205 = & ( ( char * ) V_205 ) [ F_7 ( V_15 ) ] ;
memset ( V_205 , V_24 , V_19 ) ;
* ( unsigned char * ) ( V_205 + V_19 - 1 ) = V_210 ;
}
static void F_166 ( char * V_211 , int V_34 , int V_76 )
{
int V_88 ;
unsigned char error = 0 ;
int V_212 = 0 ;
F_27 ( V_53 L_7 , V_34 ) ;
for ( V_88 = 0 ; V_88 < V_76 ; V_88 ++ ) {
if ( V_211 [ V_34 + V_88 ] != V_213 ) {
error = V_211 [ V_34 + V_88 ] ;
V_212 ++ ;
}
}
F_167 ( V_214 , L_8 , 0 , 16 , 1 ,
& V_211 [ V_34 ] , V_76 , 1 ) ;
if ( V_212 == 1 ) {
error ^= V_213 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_27 ( V_53 L_9
L_10 ) ;
#ifdef F_168
F_27 ( V_53 L_11
L_12 ) ;
#else
F_27 ( V_53 L_13 ) ;
#endif
}
}
}
static void F_169 ( struct V_14 * V_15 , void * V_1 , int V_215 )
{
int V_88 , V_19 ;
char * V_216 ;
if ( V_15 -> V_16 & V_17 ) {
F_27 ( V_53 L_14 ,
* F_8 ( V_15 , V_1 ) ,
* F_10 ( V_15 , V_1 ) ) ;
}
if ( V_15 -> V_16 & V_18 ) {
F_27 ( V_53 L_15 ,
* F_11 ( V_15 , V_1 ) ,
* F_11 ( V_15 , V_1 ) ) ;
}
V_216 = ( char * ) V_1 + F_7 ( V_15 ) ;
V_19 = V_15 -> V_207 ;
for ( V_88 = 0 ; V_88 < V_19 && V_215 ; V_88 += 16 , V_215 -- ) {
int V_76 ;
V_76 = 16 ;
if ( V_88 + V_76 > V_19 )
V_76 = V_19 - V_88 ;
F_166 ( V_216 , V_88 , V_76 ) ;
}
}
static void F_170 ( struct V_14 * V_15 , void * V_1 )
{
char * V_216 ;
int V_19 , V_88 ;
int V_215 = 0 ;
V_216 = ( char * ) V_1 + F_7 ( V_15 ) ;
V_19 = V_15 -> V_207 ;
for ( V_88 = 0 ; V_88 < V_19 ; V_88 ++ ) {
char exp = V_213 ;
if ( V_88 == V_19 - 1 )
exp = V_210 ;
if ( V_216 [ V_88 ] != exp ) {
int V_76 ;
if ( V_215 == 0 ) {
F_27 ( V_53
L_16 ,
F_171 () , V_15 -> V_54 , V_216 , V_19 ) ;
F_169 ( V_15 , V_1 , 0 ) ;
}
V_88 = ( V_88 / 16 ) * 16 ;
V_76 = 16 ;
if ( V_88 + V_76 > V_19 )
V_76 = V_19 - V_88 ;
F_166 ( V_216 , V_88 , V_76 ) ;
V_88 += 16 ;
V_215 ++ ;
if ( V_215 > 5 )
break;
}
}
if ( V_215 != 0 ) {
struct V_22 * V_22 = F_15 ( V_1 ) ;
unsigned int V_217 ;
V_217 = F_17 ( V_15 , V_22 , V_1 ) ;
if ( V_217 ) {
V_1 = F_16 ( V_15 , V_22 , V_217 - 1 ) ;
V_216 = ( char * ) V_1 + F_7 ( V_15 ) ;
F_27 ( V_53 L_17 ,
V_216 , V_19 ) ;
F_169 ( V_15 , V_1 , 2 ) ;
}
if ( V_217 + 1 < V_15 -> V_28 ) {
V_1 = F_16 ( V_15 , V_22 , V_217 + 1 ) ;
V_216 = ( char * ) V_1 + F_7 ( V_15 ) ;
F_27 ( V_53 L_18 ,
V_216 , V_19 ) ;
F_169 ( V_15 , V_1 , 2 ) ;
}
}
}
static void F_172 ( struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < V_15 -> V_28 ; V_88 ++ ) {
void * V_1 = F_16 ( V_15 , V_22 , V_88 ) ;
if ( V_15 -> V_16 & V_218 ) {
#ifdef F_173
if ( V_15 -> V_19 % V_49 == 0 &&
F_174 ( V_15 ) )
F_175 ( F_96 ( V_1 ) ,
V_15 -> V_19 / V_49 , 1 ) ;
else
F_170 ( V_15 , V_1 ) ;
#else
F_170 ( V_15 , V_1 ) ;
#endif
}
if ( V_15 -> V_16 & V_17 ) {
if ( * F_8 ( V_15 , V_1 ) != V_219 )
F_176 ( V_15 , L_19
L_20 ) ;
if ( * F_10 ( V_15 , V_1 ) != V_219 )
F_176 ( V_15 , L_21
L_20 ) ;
}
}
}
static void F_172 ( struct V_14 * V_15 ,
struct V_22 * V_22 )
{
}
static void F_177 ( struct V_14 * V_15 , struct V_22 * V_22 )
{
void * V_30 ;
V_30 = V_22 -> V_30 ;
F_172 ( V_15 , V_22 ) ;
if ( F_41 ( V_15 -> V_16 & V_220 ) ) {
struct V_156 * V_204 ;
V_204 = ( void * ) & V_22 -> V_156 ;
F_178 ( V_204 , F_159 ) ;
} else {
F_151 ( V_15 , V_22 ) ;
}
if ( F_174 ( V_15 ) )
F_179 ( V_15 -> V_221 , V_30 ) ;
}
static void F_89 ( struct V_14 * V_15 , struct V_102 * V_103 )
{
struct V_22 * V_22 , * V_84 ;
F_180 (page, n, list, lru) {
F_181 ( & V_22 -> V_155 ) ;
F_177 ( V_15 , V_22 ) ;
}
}
static T_2 F_182 ( struct V_14 * V_15 ,
T_2 V_19 , T_2 V_39 , unsigned long V_16 )
{
unsigned long V_222 ;
T_2 V_47 = 0 ;
int V_46 ;
for ( V_46 = 0 ; V_46 <= V_223 ; V_46 ++ ) {
unsigned int V_28 ;
T_2 V_224 ;
F_25 ( V_46 , V_19 , V_39 , V_16 , & V_224 , & V_28 ) ;
if ( ! V_28 )
continue;
if ( V_28 > V_225 )
break;
if ( V_16 & V_50 ) {
T_2 V_226 = sizeof( V_29 ) ;
if ( F_22 ( V_40 ) )
V_226 += sizeof( char ) ;
V_222 = V_19 ;
V_222 /= V_226 ;
if ( V_28 > V_222 )
break;
}
V_15 -> V_28 = V_28 ;
V_15 -> V_46 = V_46 ;
V_47 = V_224 ;
if ( V_16 & V_190 )
break;
if ( V_46 >= V_60 )
break;
if ( V_47 * 8 <= ( V_49 << V_46 ) )
break;
}
return V_47 ;
}
static struct V_36 T_7 * F_183 (
struct V_14 * V_15 , int V_81 , int V_79 )
{
int V_63 ;
T_2 V_19 ;
struct V_36 T_7 * V_37 ;
V_19 = sizeof( void * ) * V_81 + sizeof( struct V_36 ) ;
V_37 = F_184 ( V_19 , sizeof( void * ) ) ;
if ( ! V_37 )
return NULL ;
F_185 (cpu) {
F_48 ( F_104 ( V_37 , V_63 ) ,
V_81 , V_79 ) ;
}
return V_37 ;
}
static int T_8 F_186 ( struct V_14 * V_15 , T_4 V_82 )
{
if ( V_164 >= V_174 )
return F_130 ( V_15 , V_82 ) ;
V_15 -> V_37 = F_183 ( V_15 , 1 , 1 ) ;
if ( ! V_15 -> V_37 )
return 1 ;
if ( V_164 == V_227 ) {
F_119 ( V_14 , V_171 ) ;
} else if ( V_164 == V_165 ) {
F_119 ( V_15 , V_172 ) ;
} else {
int V_64 ;
F_91 (node) {
V_15 -> V_64 [ V_64 ] = F_51 (
sizeof( struct V_3 ) , V_82 , V_64 ) ;
F_9 ( ! V_15 -> V_64 [ V_64 ] ) ;
F_4 ( V_15 -> V_64 [ V_64 ] ) ;
}
}
V_15 -> V_64 [ F_56 () ] -> V_110 =
V_111 + V_112 +
( ( unsigned long ) V_15 ) % V_112 ;
F_19 ( V_15 ) -> V_78 = 0 ;
F_19 ( V_15 ) -> V_76 = V_228 ;
F_19 ( V_15 ) -> V_79 = 1 ;
F_19 ( V_15 ) -> V_80 = 0 ;
V_15 -> V_79 = 1 ;
V_15 -> V_76 = V_228 ;
return 0 ;
}
unsigned long F_187 ( unsigned long V_207 ,
unsigned long V_16 , const char * V_54 ,
void (* V_198)( void * ) )
{
return V_16 ;
}
struct V_14 *
F_188 ( const char * V_54 , T_2 V_19 , T_2 V_39 ,
unsigned long V_16 , void (* V_198)( void * ) )
{
struct V_14 * V_15 ;
V_15 = F_189 ( V_19 , V_39 , V_16 , V_54 , V_198 ) ;
if ( V_15 ) {
V_15 -> V_229 ++ ;
V_15 -> V_207 = F_190 ( int , V_15 -> V_207 , V_19 ) ;
}
return V_15 ;
}
int
F_191 ( struct V_14 * V_15 , unsigned long V_16 )
{
T_2 V_47 , V_25 ;
T_2 V_230 = V_21 ;
T_4 V_82 ;
int V_118 ;
T_2 V_19 = V_15 -> V_19 ;
#if V_178
#if V_231
if ( V_19 < 4096 || F_192 ( V_19 - 1 ) == F_192 ( V_19 - 1 + V_20 +
2 * sizeof( unsigned long long ) ) )
V_16 |= V_17 | V_18 ;
if ( ! ( V_16 & V_220 ) )
V_16 |= V_218 ;
#endif
if ( V_16 & V_220 )
F_9 ( V_16 & V_218 ) ;
#endif
if ( V_19 & ( V_21 - 1 ) ) {
V_19 += ( V_21 - 1 ) ;
V_19 &= ~ ( V_21 - 1 ) ;
}
if ( V_16 & V_17 ) {
V_230 = V_20 ;
V_19 += V_20 - 1 ;
V_19 &= ~ ( V_20 - 1 ) ;
}
if ( V_230 < V_15 -> V_39 ) {
V_230 = V_15 -> V_39 ;
}
if ( V_230 > F_193 (unsigned long long) )
V_16 &= ~ ( V_17 | V_18 ) ;
V_15 -> V_39 = V_230 ;
if ( F_194 () )
V_82 = V_108 ;
else
V_82 = V_152 ;
#if V_178
if ( V_16 & V_17 ) {
V_15 -> F_7 += sizeof( unsigned long long ) ;
V_19 += 2 * sizeof( unsigned long long ) ;
}
if ( V_16 & V_18 ) {
if ( V_16 & V_17 )
V_19 += V_20 ;
else
V_19 += V_21 ;
}
#if V_231 && F_195 ( F_173 )
if ( V_19 >= F_127 ( V_167 + 1 )
&& V_15 -> V_207 > F_196 ()
&& F_23 ( V_19 , V_15 -> V_39 ) < V_49 ) {
V_15 -> F_7 += V_49 - F_23 ( V_19 , V_15 -> V_39 ) ;
V_19 = V_49 ;
}
#endif
#endif
if ( ( V_19 >= ( V_49 >> 5 ) ) && ! V_170 &&
! ( V_16 & V_232 ) )
V_16 |= V_50 ;
V_19 = F_23 ( V_19 , V_15 -> V_39 ) ;
if ( V_233 && V_19 < V_234 )
V_19 = F_23 ( V_234 , V_15 -> V_39 ) ;
V_47 = F_182 ( V_15 , V_19 , V_15 -> V_39 , V_16 ) ;
if ( ! V_15 -> V_28 )
return - V_235 ;
V_25 = F_21 ( V_15 -> V_28 , V_15 -> V_39 ) ;
if ( V_16 & V_50 && V_47 >= V_25 ) {
V_16 &= ~ V_50 ;
V_47 -= V_25 ;
}
if ( V_16 & V_50 ) {
V_25 = F_21 ( V_15 -> V_28 , 0 ) ;
#ifdef F_197
if ( V_19 % V_49 == 0 && V_16 & V_218 )
V_16 &= ~ ( V_17 | V_18 ) ;
#endif
}
V_15 -> V_236 = F_196 () ;
if ( V_15 -> V_236 < V_15 -> V_39 )
V_15 -> V_236 = V_15 -> V_39 ;
V_15 -> V_237 = V_47 / V_15 -> V_236 ;
V_15 -> V_25 = V_25 ;
V_15 -> V_16 = V_16 ;
V_15 -> V_189 = V_238 ;
if ( V_239 && ( V_16 & V_240 ) )
V_15 -> V_189 |= V_241 ;
V_15 -> V_19 = V_19 ;
V_15 -> V_35 = F_198 ( V_19 ) ;
if ( V_16 & V_50 ) {
V_15 -> V_221 = F_199 ( V_25 , 0u ) ;
F_9 ( F_200 ( V_15 -> V_221 ) ) ;
}
V_118 = F_186 ( V_15 , V_82 ) ;
if ( V_118 ) {
F_201 ( V_15 ) ;
return V_118 ;
}
return 0 ;
}
static void F_202 ( void )
{
F_9 ( ! F_203 () ) ;
}
static void F_204 ( void )
{
F_9 ( F_203 () ) ;
}
static void F_205 ( struct V_14 * V_15 )
{
#ifdef F_206
F_202 () ;
F_207 ( & F_55 ( V_15 , F_56 () ) -> V_11 ) ;
#endif
}
static void F_208 ( struct V_14 * V_15 , int V_64 )
{
#ifdef F_206
F_202 () ;
F_207 ( & F_55 ( V_15 , V_64 ) -> V_11 ) ;
#endif
}
static void F_209 ( void * V_140 )
{
struct V_14 * V_15 = V_140 ;
struct V_36 * V_75 ;
int V_64 = F_56 () ;
struct V_3 * V_84 ;
F_87 ( V_103 ) ;
F_202 () ;
V_75 = F_19 ( V_15 ) ;
V_84 = F_55 ( V_15 , V_64 ) ;
F_82 ( & V_84 -> V_11 ) ;
F_83 ( V_15 , V_75 -> V_89 , V_75 -> V_78 , V_64 , & V_103 ) ;
F_84 ( & V_84 -> V_11 ) ;
F_89 ( V_15 , & V_103 ) ;
V_75 -> V_78 = 0 ;
}
static void F_210 ( struct V_14 * V_15 )
{
struct V_3 * V_84 ;
int V_64 ;
F_211 ( F_209 , V_15 , 1 ) ;
F_204 () ;
F_139 (cachep, node, n)
if ( V_84 -> V_9 )
F_90 ( V_15 , V_84 -> V_9 ) ;
F_139 (cachep, node, n)
F_212 ( V_15 , V_84 , V_84 -> V_8 , 1 , V_64 ) ;
}
static int F_106 ( struct V_14 * V_32 ,
struct V_3 * V_84 , int V_242 )
{
struct V_102 * V_243 ;
int V_199 ;
struct V_22 * V_22 ;
V_199 = 0 ;
while ( V_199 < V_242 && ! F_62 ( & V_84 -> V_7 ) ) {
F_99 ( & V_84 -> V_11 ) ;
V_243 = V_84 -> V_7 . V_244 ;
if ( V_243 == & V_84 -> V_7 ) {
F_88 ( & V_84 -> V_11 ) ;
goto V_86;
}
V_22 = F_213 ( V_243 , struct V_22 , V_155 ) ;
#if V_178
F_9 ( V_22 -> V_187 ) ;
#endif
F_181 ( & V_22 -> V_155 ) ;
V_84 -> V_12 -= V_32 -> V_28 ;
F_88 ( & V_84 -> V_11 ) ;
F_177 ( V_32 , V_22 ) ;
V_199 ++ ;
}
V_86:
return V_199 ;
}
int F_214 ( struct V_14 * V_15 , bool V_245 )
{
int V_137 = 0 ;
int V_64 ;
struct V_3 * V_84 ;
F_210 ( V_15 ) ;
F_204 () ;
F_139 (cachep, node, n) {
F_106 ( V_15 , V_84 , F_101 ( V_15 , V_84 ) ) ;
V_137 += ! F_62 ( & V_84 -> V_5 ) ||
! F_62 ( & V_84 -> V_6 ) ;
}
return ( V_137 ? 1 : 0 ) ;
}
int F_201 ( struct V_14 * V_15 )
{
int V_88 ;
struct V_3 * V_84 ;
int V_246 = F_214 ( V_15 , false ) ;
if ( V_246 )
return V_246 ;
F_215 ( V_15 -> V_37 ) ;
F_139 (cachep, i, n) {
F_80 ( V_84 -> V_8 ) ;
F_71 ( V_84 -> V_9 ) ;
F_80 ( V_84 ) ;
V_15 -> V_64 [ V_88 ] = NULL ;
}
return 0 ;
}
static void * F_216 ( struct V_14 * V_15 ,
struct V_22 * V_22 , int V_236 ,
T_4 V_247 , int V_97 )
{
void * V_30 ;
void * V_205 = F_217 ( V_22 ) ;
if ( F_174 ( V_15 ) ) {
V_30 = F_218 ( V_15 -> V_221 ,
V_247 , V_97 ) ;
if ( ! V_30 )
return NULL ;
} else {
V_30 = V_205 + V_236 ;
V_236 += V_15 -> V_25 ;
}
V_22 -> V_187 = 0 ;
V_22 -> V_33 = V_205 + V_236 ;
return V_30 ;
}
static inline V_29 F_219 ( struct V_22 * V_22 , unsigned int V_23 )
{
return ( ( V_29 * ) V_22 -> V_30 ) [ V_23 ] ;
}
static inline void F_220 ( struct V_22 * V_22 ,
unsigned int V_23 , V_29 V_24 )
{
( ( V_29 * ) ( V_22 -> V_30 ) ) [ V_23 ] = V_24 ;
}
static void F_221 ( struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < V_15 -> V_28 ; V_88 ++ ) {
void * V_1 = F_16 ( V_15 , V_22 , V_88 ) ;
#if V_178
if ( V_15 -> V_16 & V_218 )
F_165 ( V_15 , V_1 , V_213 ) ;
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = NULL ;
if ( V_15 -> V_16 & V_17 ) {
* F_8 ( V_15 , V_1 ) = V_219 ;
* F_10 ( V_15 , V_1 ) = V_219 ;
}
if ( V_15 -> V_198 && ! ( V_15 -> V_16 & V_218 ) )
V_15 -> V_198 ( V_1 + F_7 ( V_15 ) ) ;
if ( V_15 -> V_16 & V_17 ) {
if ( * F_10 ( V_15 , V_1 ) != V_219 )
F_176 ( V_15 , L_22
L_23 ) ;
if ( * F_8 ( V_15 , V_1 ) != V_219 )
F_176 ( V_15 , L_22
L_24 ) ;
}
if ( ( V_15 -> V_19 % V_49 ) == 0 &&
F_174 ( V_15 ) && V_15 -> V_16 & V_218 )
F_175 ( F_96 ( V_1 ) ,
V_15 -> V_19 / V_49 , 0 ) ;
#else
if ( V_15 -> V_198 )
V_15 -> V_198 ( V_1 ) ;
#endif
F_12 ( V_22 , V_88 , V_248 ) ;
F_220 ( V_22 , V_88 , V_88 ) ;
}
}
static void F_222 ( struct V_14 * V_15 , T_4 V_16 )
{
if ( V_239 ) {
if ( V_16 & V_241 )
F_9 ( ! ( V_15 -> V_189 & V_241 ) ) ;
else
F_9 ( V_15 -> V_189 & V_241 ) ;
}
}
static void * F_223 ( struct V_14 * V_15 , struct V_22 * V_22 ,
int V_97 )
{
void * V_1 ;
V_1 = F_16 ( V_15 , V_22 , F_219 ( V_22 , V_22 -> V_187 ) ) ;
V_22 -> V_187 ++ ;
#if V_178
F_224 ( F_95 ( F_96 ( V_1 ) ) != V_97 ) ;
#endif
return V_1 ;
}
static void F_225 ( struct V_14 * V_15 , struct V_22 * V_22 ,
void * V_1 , int V_97 )
{
unsigned int V_217 = F_17 ( V_15 , V_22 , V_1 ) ;
#if V_178
unsigned int V_88 ;
F_224 ( F_95 ( F_96 ( V_1 ) ) != V_97 ) ;
for ( V_88 = V_22 -> V_187 ; V_88 < V_15 -> V_28 ; V_88 ++ ) {
if ( F_219 ( V_22 , V_88 ) == V_217 ) {
F_27 ( V_53 L_25
L_26 , V_15 -> V_54 , V_1 ) ;
F_131 () ;
}
}
#endif
V_22 -> V_187 -- ;
F_220 ( V_22 , V_22 -> V_187 , V_217 ) ;
}
static void F_226 ( struct V_14 * V_32 , struct V_22 * V_22 ,
void * V_30 )
{
V_22 -> V_27 = V_32 ;
V_22 -> V_30 = V_30 ;
}
static int F_227 ( struct V_14 * V_15 ,
T_4 V_16 , int V_97 , struct V_22 * V_22 )
{
void * V_30 ;
T_2 V_34 ;
T_4 V_247 ;
struct V_3 * V_84 ;
if ( F_41 ( V_16 & V_249 ) ) {
F_228 ( L_27 , V_16 & V_249 ) ;
F_131 () ;
}
V_247 = V_16 & ( V_250 | V_251 ) ;
F_202 () ;
V_84 = F_55 ( V_15 , V_97 ) ;
F_82 ( & V_84 -> V_11 ) ;
V_34 = V_84 -> V_10 ;
V_84 -> V_10 ++ ;
if ( V_84 -> V_10 >= V_15 -> V_237 )
V_84 -> V_10 = 0 ;
F_84 ( & V_84 -> V_11 ) ;
V_34 *= V_15 -> V_236 ;
if ( V_247 & V_107 )
F_229 () ;
F_222 ( V_15 , V_16 ) ;
if ( ! V_22 )
V_22 = F_140 ( V_15 , V_247 , V_97 ) ;
if ( ! V_22 )
goto V_252;
V_30 = F_216 ( V_15 , V_22 , V_34 ,
V_247 & ~ V_250 , V_97 ) ;
if ( ! V_30 )
goto V_253;
F_226 ( V_15 , V_22 , V_30 ) ;
F_221 ( V_15 , V_22 ) ;
if ( V_247 & V_107 )
F_230 () ;
F_202 () ;
F_82 ( & V_84 -> V_11 ) ;
F_231 ( & V_22 -> V_155 , & ( V_84 -> V_7 ) ) ;
F_232 ( V_15 ) ;
V_84 -> V_12 += V_15 -> V_28 ;
F_84 ( & V_84 -> V_11 ) ;
return 1 ;
V_253:
F_151 ( V_15 , V_22 ) ;
V_252:
if ( V_247 & V_107 )
F_230 () ;
return 0 ;
}
static void F_233 ( const void * V_1 )
{
if ( ! F_234 ( V_1 ) ) {
F_27 ( V_53 L_28 ,
( unsigned long ) V_1 ) ;
F_131 () ;
}
}
static inline void F_235 ( struct V_14 * V_32 , void * V_31 )
{
unsigned long long V_254 , V_255 ;
V_254 = * F_8 ( V_32 , V_31 ) ;
V_255 = * F_10 ( V_32 , V_31 ) ;
if ( V_254 == V_256 && V_255 == V_256 )
return;
if ( V_254 == V_219 && V_255 == V_219 )
F_176 ( V_32 , L_29 ) ;
else
F_176 ( V_32 , L_30 ) ;
F_27 ( V_53 L_31 ,
V_31 , V_254 , V_255 ) ;
}
static void * F_236 ( struct V_14 * V_15 , void * V_1 ,
unsigned long V_206 )
{
unsigned int V_217 ;
struct V_22 * V_22 ;
F_9 ( F_14 ( V_1 ) != V_15 ) ;
V_1 -= F_7 ( V_15 ) ;
F_233 ( V_1 ) ;
V_22 = F_15 ( V_1 ) ;
if ( V_15 -> V_16 & V_17 ) {
F_235 ( V_15 , V_1 ) ;
* F_8 ( V_15 , V_1 ) = V_219 ;
* F_10 ( V_15 , V_1 ) = V_219 ;
}
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = ( void * ) V_206 ;
V_217 = F_17 ( V_15 , V_22 , V_1 ) ;
F_9 ( V_217 >= V_15 -> V_28 ) ;
F_9 ( V_1 != F_16 ( V_15 , V_22 , V_217 ) ) ;
F_12 ( V_22 , V_217 , V_248 ) ;
if ( V_15 -> V_16 & V_218 ) {
#ifdef F_173
if ( ( V_15 -> V_19 % V_49 ) == 0 && F_174 ( V_15 ) ) {
F_161 ( V_15 , V_1 , V_206 ) ;
F_175 ( F_96 ( V_1 ) ,
V_15 -> V_19 / V_49 , 0 ) ;
} else {
F_165 ( V_15 , V_1 , V_213 ) ;
}
#else
F_165 ( V_15 , V_1 , V_213 ) ;
#endif
}
return V_1 ;
}
static void * F_237 ( struct V_14 * V_15 , T_4 V_16 ,
bool V_87 )
{
int V_79 ;
struct V_3 * V_84 ;
struct V_36 * V_75 ;
int V_64 ;
F_202 () ;
V_64 = F_56 () ;
if ( F_41 ( V_87 ) )
goto V_257;
V_258:
V_75 = F_19 ( V_15 ) ;
V_79 = V_75 -> V_79 ;
if ( ! V_75 -> V_80 && V_79 > V_259 ) {
V_79 = V_259 ;
}
V_84 = F_55 ( V_15 , V_64 ) ;
F_9 ( V_75 -> V_78 > 0 || ! V_84 ) ;
F_82 ( & V_84 -> V_11 ) ;
if ( V_84 -> V_8 && F_68 ( V_75 , V_84 -> V_8 , V_79 ) ) {
V_84 -> V_8 -> V_80 = 1 ;
goto V_260;
}
while ( V_79 > 0 ) {
struct V_102 * V_89 ;
struct V_22 * V_22 ;
V_89 = V_84 -> V_6 . V_261 ;
if ( V_89 == & V_84 -> V_6 ) {
V_84 -> V_13 = 1 ;
V_89 = V_84 -> V_7 . V_261 ;
if ( V_89 == & V_84 -> V_7 )
goto V_262;
}
V_22 = F_213 ( V_89 , struct V_22 , V_155 ) ;
F_205 ( V_15 ) ;
F_9 ( V_22 -> V_187 >= V_15 -> V_28 ) ;
while ( V_22 -> V_187 < V_15 -> V_28 && V_79 -- ) {
F_238 ( V_15 ) ;
F_239 ( V_15 ) ;
F_240 ( V_15 ) ;
F_67 ( V_15 , V_75 , F_223 ( V_15 , V_22 ,
V_64 ) ) ;
}
F_181 ( & V_22 -> V_155 ) ;
if ( V_22 -> V_187 == V_15 -> V_28 )
F_125 ( & V_22 -> V_155 , & V_84 -> V_5 ) ;
else
F_125 ( & V_22 -> V_155 , & V_84 -> V_6 ) ;
}
V_262:
V_84 -> V_12 -= V_75 -> V_78 ;
V_260:
F_84 ( & V_84 -> V_11 ) ;
if ( F_41 ( ! V_75 -> V_78 ) ) {
int V_263 ;
V_257:
V_263 = F_227 ( V_15 , F_75 ( V_16 ) , V_64 , NULL ) ;
V_75 = F_19 ( V_15 ) ;
V_64 = F_56 () ;
if ( ! V_263 && ( V_75 -> V_78 == 0 || V_87 ) )
return NULL ;
if ( ! V_75 -> V_78 )
goto V_258;
}
V_75 -> V_80 = 1 ;
return F_64 ( V_15 , V_75 , V_16 , V_87 ) ;
}
static inline void F_241 ( struct V_14 * V_15 ,
T_4 V_16 )
{
F_242 ( V_16 & V_107 ) ;
#if V_178
F_222 ( V_15 , V_16 ) ;
#endif
}
static void * F_243 ( struct V_14 * V_15 ,
T_4 V_16 , void * V_1 , unsigned long V_206 )
{
struct V_22 * V_22 ;
if ( ! V_1 )
return V_1 ;
if ( V_15 -> V_16 & V_218 ) {
#ifdef F_173
if ( ( V_15 -> V_19 % V_49 ) == 0 && F_174 ( V_15 ) )
F_175 ( F_96 ( V_1 ) ,
V_15 -> V_19 / V_49 , 1 ) ;
else
F_170 ( V_15 , V_1 ) ;
#else
F_170 ( V_15 , V_1 ) ;
#endif
F_165 ( V_15 , V_1 , V_264 ) ;
}
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = ( void * ) V_206 ;
if ( V_15 -> V_16 & V_17 ) {
if ( * F_8 ( V_15 , V_1 ) != V_219 ||
* F_10 ( V_15 , V_1 ) != V_219 ) {
F_176 ( V_15 , L_32
L_33 ) ;
F_27 ( V_53
L_34 ,
V_1 , * F_8 ( V_15 , V_1 ) ,
* F_10 ( V_15 , V_1 ) ) ;
}
* F_8 ( V_15 , V_1 ) = V_256 ;
* F_10 ( V_15 , V_1 ) = V_256 ;
}
V_22 = F_15 ( V_1 ) ;
F_12 ( V_22 , F_17 ( V_15 , V_22 , V_1 ) , V_265 ) ;
V_1 += F_7 ( V_15 ) ;
if ( V_15 -> V_198 && V_15 -> V_16 & V_218 )
V_15 -> V_198 ( V_1 ) ;
if ( V_266 &&
( ( unsigned long ) V_1 & ( V_266 - 1 ) ) ) {
F_27 ( V_53 L_35 ,
V_1 , ( int ) V_266 ) ;
}
return V_1 ;
}
static bool F_244 ( struct V_14 * V_15 , T_4 V_16 )
{
if ( F_41 ( V_15 == V_14 ) )
return false ;
return F_245 ( V_15 -> V_207 , V_16 , V_15 -> V_16 ) ;
}
static inline void * F_246 ( struct V_14 * V_15 , T_4 V_16 )
{
void * V_1 ;
struct V_36 * V_75 ;
bool V_87 = false ;
F_202 () ;
V_75 = F_19 ( V_15 ) ;
if ( F_97 ( V_75 -> V_78 ) ) {
V_75 -> V_80 = 1 ;
V_1 = F_64 ( V_15 , V_75 , V_16 , false ) ;
if ( V_1 ) {
F_247 ( V_15 ) ;
goto V_86;
}
V_87 = true ;
}
F_248 ( V_15 ) ;
V_1 = F_237 ( V_15 , V_16 , V_87 ) ;
V_75 = F_19 ( V_15 ) ;
V_86:
if ( V_1 )
F_249 ( & V_75 -> V_89 [ V_75 -> V_78 ] ) ;
return V_1 ;
}
static void * F_73 ( struct V_14 * V_15 , T_4 V_16 )
{
int V_267 , V_268 ;
if ( F_250 () || ( V_16 & V_105 ) )
return NULL ;
V_267 = V_268 = F_56 () ;
if ( F_251 () && ( V_15 -> V_16 & V_269 ) )
V_267 = F_252 () ;
else if ( V_201 -> V_270 )
V_267 = F_253 () ;
if ( V_267 != V_268 )
return F_74 ( V_15 , V_16 , V_267 ) ;
return NULL ;
}
static void * F_254 ( struct V_14 * V_32 , T_4 V_16 )
{
struct V_271 * V_271 ;
T_4 V_247 ;
struct V_272 * V_273 ;
struct V_274 * V_274 ;
enum V_275 V_276 = F_255 ( V_16 ) ;
void * V_31 = NULL ;
int V_143 ;
unsigned int V_277 ;
if ( V_16 & V_105 )
return NULL ;
V_247 = V_16 & ( V_250 | V_251 ) ;
V_278:
V_277 = F_256 () ;
V_271 = F_257 ( F_253 () , V_16 ) ;
V_258:
F_258 (zone, z, zonelist, high_zoneidx) {
V_143 = F_259 ( V_274 ) ;
if ( F_260 ( V_274 , V_16 ) &&
F_55 ( V_32 , V_143 ) &&
F_55 ( V_32 , V_143 ) -> V_12 ) {
V_31 = F_74 ( V_32 ,
F_75 ( V_16 ) , V_143 ) ;
if ( V_31 )
break;
}
}
if ( ! V_31 ) {
struct V_22 * V_22 ;
if ( V_247 & V_107 )
F_229 () ;
F_222 ( V_32 , V_16 ) ;
V_22 = F_140 ( V_32 , V_247 , F_56 () ) ;
if ( V_247 & V_107 )
F_230 () ;
if ( V_22 ) {
V_143 = F_95 ( V_22 ) ;
if ( F_227 ( V_32 , V_16 , V_143 , V_22 ) ) {
V_31 = F_74 ( V_32 ,
F_75 ( V_16 ) , V_143 ) ;
if ( ! V_31 )
goto V_258;
} else {
V_31 = NULL ;
}
}
}
if ( F_41 ( ! V_31 && F_261 ( V_277 ) ) )
goto V_278;
return V_31 ;
}
static void * F_74 ( struct V_14 * V_15 , T_4 V_16 ,
int V_97 )
{
struct V_102 * V_89 ;
struct V_22 * V_22 ;
struct V_3 * V_84 ;
void * V_31 ;
int V_263 ;
F_262 ( V_97 < 0 || V_97 >= V_66 ) ;
V_84 = F_55 ( V_15 , V_97 ) ;
F_9 ( ! V_84 ) ;
V_258:
F_202 () ;
F_82 ( & V_84 -> V_11 ) ;
V_89 = V_84 -> V_6 . V_261 ;
if ( V_89 == & V_84 -> V_6 ) {
V_84 -> V_13 = 1 ;
V_89 = V_84 -> V_7 . V_261 ;
if ( V_89 == & V_84 -> V_7 )
goto V_262;
}
V_22 = F_213 ( V_89 , struct V_22 , V_155 ) ;
F_208 ( V_15 , V_97 ) ;
F_263 ( V_15 ) ;
F_239 ( V_15 ) ;
F_240 ( V_15 ) ;
F_9 ( V_22 -> V_187 == V_15 -> V_28 ) ;
V_31 = F_223 ( V_15 , V_22 , V_97 ) ;
V_84 -> V_12 -- ;
F_181 ( & V_22 -> V_155 ) ;
if ( V_22 -> V_187 == V_15 -> V_28 )
F_125 ( & V_22 -> V_155 , & V_84 -> V_5 ) ;
else
F_125 ( & V_22 -> V_155 , & V_84 -> V_6 ) ;
F_84 ( & V_84 -> V_11 ) ;
goto V_279;
V_262:
F_84 ( & V_84 -> V_11 ) ;
V_263 = F_227 ( V_15 , F_75 ( V_16 ) , V_97 , NULL ) ;
if ( V_263 )
goto V_258;
return F_254 ( V_15 , V_16 ) ;
V_279:
return V_31 ;
}
static T_9 void *
F_264 ( struct V_14 * V_15 , T_4 V_16 , int V_97 ,
unsigned long V_206 )
{
unsigned long V_280 ;
void * V_151 ;
int V_281 = F_56 () ;
V_16 &= V_282 ;
F_265 ( V_16 ) ;
if ( F_244 ( V_15 , V_16 ) )
return NULL ;
V_15 = F_266 ( V_15 , V_16 ) ;
F_241 ( V_15 , V_16 ) ;
F_267 ( V_280 ) ;
if ( V_97 == V_283 )
V_97 = V_281 ;
if ( F_41 ( ! F_55 ( V_15 , V_97 ) ) ) {
V_151 = F_254 ( V_15 , V_16 ) ;
goto V_86;
}
if ( V_97 == V_281 ) {
V_151 = F_246 ( V_15 , V_16 ) ;
if ( V_151 )
goto V_86;
}
V_151 = F_74 ( V_15 , V_16 , V_97 ) ;
V_86:
F_268 ( V_280 ) ;
V_151 = F_243 ( V_15 , V_16 , V_151 , V_206 ) ;
F_269 ( V_151 , V_15 -> V_207 , 1 , V_15 -> V_16 ,
V_16 ) ;
if ( F_97 ( V_151 ) ) {
F_270 ( V_15 , V_16 , V_151 , V_15 -> V_207 ) ;
if ( F_41 ( V_16 & V_284 ) )
memset ( V_151 , 0 , V_15 -> V_207 ) ;
}
F_271 ( V_15 ) ;
return V_151 ;
}
static T_9 void *
F_272 ( struct V_14 * V_32 , T_4 V_16 )
{
void * V_1 ;
if ( V_201 -> V_270 || F_251 () ) {
V_1 = F_73 ( V_32 , V_16 ) ;
if ( V_1 )
goto V_86;
}
V_1 = F_246 ( V_32 , V_16 ) ;
if ( ! V_1 )
V_1 = F_74 ( V_32 , V_16 , F_56 () ) ;
V_86:
return V_1 ;
}
static T_9 void *
F_272 ( struct V_14 * V_15 , T_4 V_16 )
{
return F_246 ( V_15 , V_16 ) ;
}
static T_9 void *
F_273 ( struct V_14 * V_15 , T_4 V_16 , unsigned long V_206 )
{
unsigned long V_280 ;
void * V_1 ;
V_16 &= V_282 ;
F_265 ( V_16 ) ;
if ( F_244 ( V_15 , V_16 ) )
return NULL ;
V_15 = F_266 ( V_15 , V_16 ) ;
F_241 ( V_15 , V_16 ) ;
F_267 ( V_280 ) ;
V_1 = F_272 ( V_15 , V_16 ) ;
F_268 ( V_280 ) ;
V_1 = F_243 ( V_15 , V_16 , V_1 , V_206 ) ;
F_269 ( V_1 , V_15 -> V_207 , 1 , V_15 -> V_16 ,
V_16 ) ;
F_274 ( V_1 ) ;
if ( F_97 ( V_1 ) ) {
F_270 ( V_15 , V_16 , V_1 , V_15 -> V_207 ) ;
if ( F_41 ( V_16 & V_284 ) )
memset ( V_1 , 0 , V_15 -> V_207 ) ;
}
F_271 ( V_15 ) ;
return V_1 ;
}
static void F_83 ( struct V_14 * V_15 , void * * V_285 ,
int V_286 , int V_64 , struct V_102 * V_103 )
{
int V_88 ;
struct V_3 * V_84 = F_55 ( V_15 , V_64 ) ;
for ( V_88 = 0 ; V_88 < V_286 ; V_88 ++ ) {
void * V_1 ;
struct V_22 * V_22 ;
F_3 ( & V_285 [ V_88 ] ) ;
V_1 = V_285 [ V_88 ] ;
V_22 = F_15 ( V_1 ) ;
F_181 ( & V_22 -> V_155 ) ;
F_208 ( V_15 , V_64 ) ;
F_225 ( V_15 , V_22 , V_1 , V_64 ) ;
F_275 ( V_15 ) ;
V_84 -> V_12 ++ ;
if ( V_22 -> V_187 == 0 ) {
if ( V_84 -> V_12 > V_84 -> V_113 ) {
V_84 -> V_12 -= V_15 -> V_28 ;
F_231 ( & V_22 -> V_155 , V_103 ) ;
} else {
F_125 ( & V_22 -> V_155 , & V_84 -> V_7 ) ;
}
} else {
F_231 ( & V_22 -> V_155 , & V_84 -> V_6 ) ;
}
}
}
static void F_276 ( struct V_14 * V_15 , struct V_36 * V_75 )
{
int V_79 ;
struct V_3 * V_84 ;
int V_64 = F_56 () ;
F_87 ( V_103 ) ;
V_79 = V_75 -> V_79 ;
#if V_178
F_9 ( ! V_79 || V_79 > V_75 -> V_78 ) ;
#endif
F_202 () ;
V_84 = F_55 ( V_15 , V_64 ) ;
F_82 ( & V_84 -> V_11 ) ;
if ( V_84 -> V_8 ) {
struct V_36 * V_287 = V_84 -> V_8 ;
int V_92 = V_287 -> V_76 - V_287 -> V_78 ;
if ( V_92 ) {
if ( V_79 > V_92 )
V_79 = V_92 ;
memcpy ( & ( V_287 -> V_89 [ V_287 -> V_78 ] ) ,
V_75 -> V_89 , sizeof( void * ) * V_79 ) ;
V_287 -> V_78 += V_79 ;
goto V_288;
}
}
F_83 ( V_15 , V_75 -> V_89 , V_79 , V_64 , & V_103 ) ;
V_288:
#if V_289
{
int V_88 = 0 ;
struct V_102 * V_243 ;
V_243 = V_84 -> V_7 . V_261 ;
while ( V_243 != & ( V_84 -> V_7 ) ) {
struct V_22 * V_22 ;
V_22 = F_213 ( V_243 , struct V_22 , V_155 ) ;
F_9 ( V_22 -> V_187 ) ;
V_88 ++ ;
V_243 = V_243 -> V_261 ;
}
F_277 ( V_15 , V_88 ) ;
}
#endif
F_84 ( & V_84 -> V_11 ) ;
F_89 ( V_15 , & V_103 ) ;
V_75 -> V_78 -= V_79 ;
memmove ( V_75 -> V_89 , & ( V_75 -> V_89 [ V_79 ] ) , sizeof( void * ) * V_75 -> V_78 ) ;
}
static inline void F_278 ( struct V_14 * V_15 , void * V_1 ,
unsigned long V_206 )
{
struct V_36 * V_75 = F_19 ( V_15 ) ;
F_202 () ;
F_279 ( V_1 , V_15 -> V_16 ) ;
V_1 = F_236 ( V_15 , V_1 , V_206 ) ;
F_280 ( V_15 , V_1 , V_15 -> V_207 ) ;
if ( V_290 > 1 && F_72 ( V_15 , V_1 ) )
return;
if ( V_75 -> V_78 < V_75 -> V_76 ) {
F_281 ( V_15 ) ;
} else {
F_282 ( V_15 ) ;
F_276 ( V_15 , V_75 ) ;
}
F_67 ( V_15 , V_75 , V_1 ) ;
}
void * F_283 ( struct V_14 * V_15 , T_4 V_16 )
{
void * V_137 = F_273 ( V_15 , V_16 , V_291 ) ;
F_284 ( V_291 , V_137 ,
V_15 -> V_207 , V_15 -> V_19 , V_16 ) ;
return V_137 ;
}
void *
F_285 ( struct V_14 * V_15 , T_4 V_16 , T_2 V_19 )
{
void * V_137 ;
V_137 = F_273 ( V_15 , V_16 , V_291 ) ;
F_286 ( V_291 , V_137 ,
V_19 , V_15 -> V_19 , V_16 ) ;
return V_137 ;
}
void * F_218 ( struct V_14 * V_15 , T_4 V_16 , int V_97 )
{
void * V_137 = F_264 ( V_15 , V_16 , V_97 , V_291 ) ;
F_287 ( V_291 , V_137 ,
V_15 -> V_207 , V_15 -> V_19 ,
V_16 , V_97 ) ;
return V_137 ;
}
void * F_288 ( struct V_14 * V_15 ,
T_4 V_16 ,
int V_97 ,
T_2 V_19 )
{
void * V_137 ;
V_137 = F_264 ( V_15 , V_16 , V_97 , V_291 ) ;
F_289 ( V_291 , V_137 ,
V_19 , V_15 -> V_19 ,
V_16 , V_97 ) ;
return V_137 ;
}
static T_9 void *
F_290 ( T_2 V_19 , T_4 V_16 , int V_64 , unsigned long V_206 )
{
struct V_14 * V_15 ;
V_15 = F_199 ( V_19 , V_16 ) ;
if ( F_41 ( F_200 ( V_15 ) ) )
return V_15 ;
return F_288 ( V_15 , V_16 , V_64 , V_19 ) ;
}
void * F_291 ( T_2 V_19 , T_4 V_16 , int V_64 )
{
return F_290 ( V_19 , V_16 , V_64 , V_291 ) ;
}
void * F_292 ( T_2 V_19 , T_4 V_16 ,
int V_64 , unsigned long V_206 )
{
return F_290 ( V_19 , V_16 , V_64 , V_206 ) ;
}
static T_9 void * F_293 ( T_2 V_19 , T_4 V_16 ,
unsigned long V_206 )
{
struct V_14 * V_15 ;
void * V_137 ;
V_15 = F_199 ( V_19 , V_16 ) ;
if ( F_41 ( F_200 ( V_15 ) ) )
return V_15 ;
V_137 = F_273 ( V_15 , V_16 , V_206 ) ;
F_286 ( V_206 , V_137 ,
V_19 , V_15 -> V_19 , V_16 ) ;
return V_137 ;
}
void * F_294 ( T_2 V_19 , T_4 V_16 )
{
return F_293 ( V_19 , V_16 , V_291 ) ;
}
void * F_295 ( T_2 V_19 , T_4 V_16 , unsigned long V_206 )
{
return F_293 ( V_19 , V_16 , V_206 ) ;
}
void F_179 ( struct V_14 * V_15 , void * V_1 )
{
unsigned long V_16 ;
V_15 = F_296 ( V_15 , V_1 ) ;
if ( ! V_15 )
return;
F_267 ( V_16 ) ;
F_297 ( V_1 , V_15 -> V_207 ) ;
if ( ! ( V_15 -> V_16 & V_292 ) )
F_298 ( V_1 , V_15 -> V_207 ) ;
F_278 ( V_15 , V_1 , V_291 ) ;
F_268 ( V_16 ) ;
F_299 ( V_291 , V_1 ) ;
}
void F_80 ( const void * V_1 )
{
struct V_14 * V_293 ;
unsigned long V_16 ;
F_300 ( V_291 , V_1 ) ;
if ( F_41 ( F_200 ( V_1 ) ) )
return;
F_267 ( V_16 ) ;
F_233 ( V_1 ) ;
V_293 = F_14 ( V_1 ) ;
F_297 ( V_1 , V_293 -> V_207 ) ;
F_298 ( V_1 , V_293 -> V_207 ) ;
F_278 ( V_293 , ( void * ) V_1 , V_291 ) ;
F_268 ( V_16 ) ;
}
static int F_301 ( struct V_14 * V_15 , T_4 V_82 )
{
int V_64 ;
struct V_3 * V_84 ;
struct V_36 * V_294 ;
struct V_94 * * V_295 = NULL ;
F_91 (node) {
if ( V_58 ) {
V_295 = F_70 ( V_64 , V_15 -> V_76 , V_82 ) ;
if ( ! V_295 )
goto V_296;
}
V_294 = NULL ;
if ( V_15 -> V_8 ) {
V_294 = F_50 ( V_64 ,
V_15 -> V_8 * V_15 -> V_79 ,
0xbaadf00d , V_82 ) ;
if ( ! V_294 ) {
F_71 ( V_295 ) ;
goto V_296;
}
}
V_84 = F_55 ( V_15 , V_64 ) ;
if ( V_84 ) {
struct V_36 * V_8 = V_84 -> V_8 ;
F_87 ( V_103 ) ;
F_99 ( & V_84 -> V_11 ) ;
if ( V_8 )
F_83 ( V_15 , V_8 -> V_89 ,
V_8 -> V_78 , V_64 , & V_103 ) ;
V_84 -> V_8 = V_294 ;
if ( ! V_84 -> V_9 ) {
V_84 -> V_9 = V_295 ;
V_295 = NULL ;
}
V_84 -> V_113 = ( 1 + F_100 ( V_64 ) ) *
V_15 -> V_79 + V_15 -> V_28 ;
F_88 ( & V_84 -> V_11 ) ;
F_89 ( V_15 , & V_103 ) ;
F_80 ( V_8 ) ;
F_71 ( V_295 ) ;
continue;
}
V_84 = F_51 ( sizeof( struct V_3 ) , V_82 , V_64 ) ;
if ( ! V_84 ) {
F_71 ( V_295 ) ;
F_80 ( V_294 ) ;
goto V_296;
}
F_4 ( V_84 ) ;
V_84 -> V_110 = V_111 + V_112 +
( ( unsigned long ) V_15 ) % V_112 ;
V_84 -> V_8 = V_294 ;
V_84 -> V_9 = V_295 ;
V_84 -> V_113 = ( 1 + F_100 ( V_64 ) ) *
V_15 -> V_79 + V_15 -> V_28 ;
V_15 -> V_64 [ V_64 ] = V_84 ;
}
return 0 ;
V_296:
if ( ! V_15 -> V_103 . V_261 ) {
V_64 -- ;
while ( V_64 >= 0 ) {
V_84 = F_55 ( V_15 , V_64 ) ;
if ( V_84 ) {
F_80 ( V_84 -> V_8 ) ;
F_71 ( V_84 -> V_9 ) ;
F_80 ( V_84 ) ;
V_15 -> V_64 [ V_64 ] = NULL ;
}
V_64 -- ;
}
}
return - V_109 ;
}
static int F_302 ( struct V_14 * V_15 , int V_76 ,
int V_79 , int V_8 , T_4 V_82 )
{
struct V_36 T_7 * V_37 , * V_244 ;
int V_63 ;
V_37 = F_183 ( V_15 , V_76 , V_79 ) ;
if ( ! V_37 )
return - V_109 ;
V_244 = V_15 -> V_37 ;
V_15 -> V_37 = V_37 ;
F_303 () ;
F_204 () ;
V_15 -> V_79 = V_79 ;
V_15 -> V_76 = V_76 ;
V_15 -> V_8 = V_8 ;
if ( ! V_244 )
goto V_297;
F_135 (cpu) {
F_87 ( V_103 ) ;
int V_64 ;
struct V_3 * V_84 ;
struct V_36 * V_75 = F_104 ( V_244 , V_63 ) ;
V_64 = F_36 ( V_63 ) ;
V_84 = F_55 ( V_15 , V_64 ) ;
F_99 ( & V_84 -> V_11 ) ;
F_83 ( V_15 , V_75 -> V_89 , V_75 -> V_78 , V_64 , & V_103 ) ;
F_88 ( & V_84 -> V_11 ) ;
F_89 ( V_15 , & V_103 ) ;
}
F_215 ( V_244 ) ;
V_297:
return F_301 ( V_15 , V_82 ) ;
}
static int F_304 ( struct V_14 * V_15 , int V_76 ,
int V_79 , int V_8 , T_4 V_82 )
{
int V_137 ;
struct V_14 * V_293 ;
V_137 = F_302 ( V_15 , V_76 , V_79 , V_8 , V_82 ) ;
if ( V_164 < V_174 )
return V_137 ;
if ( ( V_137 < 0 ) || ! F_305 ( V_15 ) )
return V_137 ;
F_306 ( & V_126 ) ;
F_307 (c, cachep) {
F_302 ( V_293 , V_76 , V_79 , V_8 , V_82 ) ;
}
return V_137 ;
}
static int F_130 ( struct V_14 * V_15 , T_4 V_82 )
{
int V_118 ;
int V_76 = 0 ;
int V_8 = 0 ;
int V_79 = 0 ;
if ( ! F_305 ( V_15 ) ) {
struct V_14 * V_298 = F_308 ( V_15 ) ;
V_76 = V_298 -> V_76 ;
V_8 = V_298 -> V_8 ;
V_79 = V_298 -> V_79 ;
}
if ( V_76 && V_8 && V_79 )
goto V_299;
if ( V_15 -> V_19 > 131072 )
V_76 = 1 ;
else if ( V_15 -> V_19 > V_49 )
V_76 = 8 ;
else if ( V_15 -> V_19 > 1024 )
V_76 = 24 ;
else if ( V_15 -> V_19 > 256 )
V_76 = 54 ;
else
V_76 = 120 ;
V_8 = 0 ;
if ( V_15 -> V_19 <= V_49 && F_309 () > 1 )
V_8 = 8 ;
#if V_178
if ( V_76 > 32 )
V_76 = 32 ;
#endif
V_79 = ( V_76 + 1 ) / 2 ;
V_299:
V_118 = F_304 ( V_15 , V_76 , V_79 , V_8 , V_82 ) ;
if ( V_118 )
F_27 ( V_53 L_36 ,
V_15 -> V_54 , - V_118 ) ;
return V_118 ;
}
static void F_212 ( struct V_14 * V_15 , struct V_3 * V_84 ,
struct V_36 * V_75 , int V_300 , int V_64 )
{
F_87 ( V_103 ) ;
int V_242 ;
if ( ! V_75 || ! V_75 -> V_78 )
return;
if ( V_75 -> V_80 && ! V_300 ) {
V_75 -> V_80 = 0 ;
} else {
F_99 ( & V_84 -> V_11 ) ;
if ( V_75 -> V_78 ) {
V_242 = V_300 ? V_75 -> V_78 : ( V_75 -> V_76 + 4 ) / 5 ;
if ( V_242 > V_75 -> V_78 )
V_242 = ( V_75 -> V_78 + 1 ) / 2 ;
F_83 ( V_15 , V_75 -> V_89 , V_242 , V_64 , & V_103 ) ;
V_75 -> V_78 -= V_242 ;
memmove ( V_75 -> V_89 , & ( V_75 -> V_89 [ V_242 ] ) ,
sizeof( void * ) * V_75 -> V_78 ) ;
}
F_88 ( & V_84 -> V_11 ) ;
F_89 ( V_15 , & V_103 ) ;
}
}
static void V_73 ( struct V_301 * V_302 )
{
struct V_14 * V_303 ;
struct V_3 * V_84 ;
int V_64 = F_56 () ;
struct V_68 * V_71 = F_310 ( V_302 ) ;
if ( ! F_311 ( & V_126 ) )
goto V_86;
F_58 (searchp, &slab_caches, list) {
F_204 () ;
V_84 = F_55 ( V_303 , V_64 ) ;
F_85 ( V_303 , V_84 ) ;
F_212 ( V_303 , V_84 , F_19 ( V_303 ) , 0 , V_64 ) ;
if ( F_312 ( V_84 -> V_110 , V_111 ) )
goto V_261;
V_84 -> V_110 = V_111 + V_112 ;
F_212 ( V_303 , V_84 , V_84 -> V_8 , 0 , V_64 ) ;
if ( V_84 -> V_13 )
V_84 -> V_13 = 0 ;
else {
int V_304 ;
V_304 = F_106 ( V_303 , V_84 , ( V_84 -> V_113 +
5 * V_303 -> V_28 - 1 ) / ( 5 * V_303 -> V_28 ) ) ;
F_313 ( V_303 , V_304 ) ;
}
V_261:
F_314 () ;
}
F_204 () ;
F_111 ( & V_126 ) ;
F_39 () ;
V_86:
F_315 ( V_71 , F_316 ( V_305 ) ) ;
}
void F_317 ( struct V_14 * V_15 , struct V_306 * V_307 )
{
struct V_22 * V_22 ;
unsigned long V_183 ;
unsigned long V_184 ;
unsigned long V_185 = 0 ;
unsigned long V_186 , V_12 = 0 , V_308 = 0 ;
const char * V_54 ;
char * error = NULL ;
int V_64 ;
struct V_3 * V_84 ;
V_183 = 0 ;
V_186 = 0 ;
F_139 (cachep, node, n) {
F_204 () ;
F_99 ( & V_84 -> V_11 ) ;
F_58 (page, &n->slabs_full, lru) {
if ( V_22 -> V_187 != V_15 -> V_28 && ! error )
error = L_37 ;
V_183 += V_15 -> V_28 ;
V_185 ++ ;
}
F_58 (page, &n->slabs_partial, lru) {
if ( V_22 -> V_187 == V_15 -> V_28 && ! error )
error = L_38 ;
if ( ! V_22 -> V_187 && ! error )
error = L_38 ;
V_183 += V_22 -> V_187 ;
V_185 ++ ;
}
F_58 (page, &n->slabs_free, lru) {
if ( V_22 -> V_187 && ! error )
error = L_39 ;
V_186 ++ ;
}
V_12 += V_84 -> V_12 ;
if ( V_84 -> V_8 )
V_308 += V_84 -> V_8 -> V_78 ;
F_88 ( & V_84 -> V_11 ) ;
}
V_186 += V_185 ;
V_184 = V_186 * V_15 -> V_28 ;
if ( V_184 - V_183 != V_12 && ! error )
error = L_40 ;
V_54 = V_15 -> V_54 ;
if ( error )
F_27 ( V_53 L_41 , V_54 , error ) ;
V_307 -> V_183 = V_183 ;
V_307 -> V_184 = V_184 ;
V_307 -> V_185 = V_185 ;
V_307 -> V_186 = V_186 ;
V_307 -> V_308 = V_308 ;
V_307 -> V_76 = V_15 -> V_76 ;
V_307 -> V_79 = V_15 -> V_79 ;
V_307 -> V_8 = V_15 -> V_8 ;
V_307 -> V_309 = V_15 -> V_28 ;
V_307 -> V_310 = V_15 -> V_46 ;
}
void F_318 ( struct V_311 * V_312 , struct V_14 * V_15 )
{
#if V_289
{
unsigned long V_313 = V_15 -> V_314 ;
unsigned long V_315 = V_15 -> V_316 ;
unsigned long V_317 = V_15 -> V_317 ;
unsigned long V_318 = V_15 -> V_318 ;
unsigned long V_319 = V_15 -> V_319 ;
unsigned long V_320 = V_15 -> V_320 ;
unsigned long V_321 = V_15 -> V_321 ;
unsigned long V_322 = V_15 -> V_322 ;
unsigned long V_323 = V_15 -> V_324 ;
F_319 ( V_312 , L_42
L_43 ,
V_315 , V_313 , V_317 ,
V_318 , V_319 , V_320 , V_321 ,
V_322 , V_323 ) ;
}
{
unsigned long V_325 = F_320 ( & V_15 -> V_325 ) ;
unsigned long V_326 = F_320 ( & V_15 -> V_326 ) ;
unsigned long V_327 = F_320 ( & V_15 -> V_327 ) ;
unsigned long V_328 = F_320 ( & V_15 -> V_328 ) ;
F_319 ( V_312 , L_44 ,
V_325 , V_326 , V_327 , V_328 ) ;
}
#endif
}
T_10 F_321 ( struct V_329 * V_329 , const char T_11 * V_330 ,
T_2 V_331 , T_12 * V_332 )
{
char V_333 [ V_334 + 1 ] , * V_335 ;
int V_76 , V_79 , V_8 , V_336 ;
struct V_14 * V_15 ;
if ( V_331 > V_334 )
return - V_337 ;
if ( F_322 ( & V_333 , V_330 , V_331 ) )
return - V_338 ;
V_333 [ V_334 ] = '\0' ;
V_335 = strchr ( V_333 , ' ' ) ;
if ( ! V_335 )
return - V_337 ;
* V_335 = '\0' ;
V_335 ++ ;
if ( sscanf ( V_335 , L_45 , & V_76 , & V_79 , & V_8 ) != 3 )
return - V_337 ;
F_110 ( & V_126 ) ;
V_336 = - V_337 ;
F_58 (cachep, &slab_caches, list) {
if ( ! strcmp ( V_15 -> V_54 , V_333 ) ) {
if ( V_76 < 1 || V_79 < 1 ||
V_79 > V_76 || V_8 < 0 ) {
V_336 = 0 ;
} else {
V_336 = F_304 ( V_15 , V_76 ,
V_79 , V_8 ,
V_108 ) ;
}
break;
}
}
F_111 ( & V_126 ) ;
if ( V_336 >= 0 )
V_336 = V_331 ;
return V_336 ;
}
static inline int F_323 ( unsigned long * V_84 , unsigned long V_339 )
{
unsigned long * V_243 ;
int V_340 ;
if ( ! V_339 )
return 1 ;
V_340 = V_84 [ 1 ] ;
V_243 = V_84 + 2 ;
while ( V_340 ) {
int V_88 = V_340 / 2 ;
unsigned long * V_341 = V_243 + 2 * V_88 ;
if ( * V_341 == V_339 ) {
V_341 [ 1 ] ++ ;
return 1 ;
}
if ( * V_341 > V_339 ) {
V_340 = V_88 ;
} else {
V_243 = V_341 + 2 ;
V_340 -= V_88 + 1 ;
}
}
if ( ++ V_84 [ 1 ] == V_84 [ 0 ] )
return 0 ;
memmove ( V_243 + 2 , V_243 , V_84 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_243 - ( void * ) V_84 ) ) ;
V_243 [ 0 ] = V_339 ;
V_243 [ 1 ] = 1 ;
return 1 ;
}
static void F_324 ( unsigned long * V_84 , struct V_14 * V_293 ,
struct V_22 * V_22 )
{
void * V_243 ;
int V_88 ;
if ( V_84 [ 0 ] == V_84 [ 1 ] )
return;
for ( V_88 = 0 , V_243 = V_22 -> V_33 ; V_88 < V_293 -> V_28 ; V_88 ++ , V_243 += V_293 -> V_19 ) {
if ( F_13 ( V_22 , V_88 ) != V_265 )
continue;
if ( ! F_323 ( V_84 , ( unsigned long ) * F_11 ( V_293 , V_243 ) ) )
return;
}
}
static void F_325 ( struct V_311 * V_312 , unsigned long V_342 )
{
#ifdef F_326
unsigned long V_34 , V_19 ;
char V_343 [ V_344 ] , V_54 [ V_345 ] ;
if ( F_327 ( V_342 , & V_19 , & V_34 , V_343 , V_54 ) == 0 ) {
F_319 ( V_312 , L_46 , V_54 , V_34 , V_19 ) ;
if ( V_343 [ 0 ] )
F_319 ( V_312 , L_47 , V_343 ) ;
return;
}
#endif
F_319 ( V_312 , L_48 , ( void * ) V_342 ) ;
}
static int F_328 ( struct V_311 * V_312 , void * V_243 )
{
struct V_14 * V_15 = F_213 ( V_243 , struct V_14 , V_103 ) ;
struct V_22 * V_22 ;
struct V_3 * V_84 ;
const char * V_54 ;
unsigned long * V_263 = V_312 -> V_346 ;
int V_64 ;
int V_88 ;
if ( ! ( V_15 -> V_16 & V_18 ) )
return 0 ;
if ( ! ( V_15 -> V_16 & V_17 ) )
return 0 ;
V_263 [ 1 ] = 0 ;
F_139 (cachep, node, n) {
F_204 () ;
F_99 ( & V_84 -> V_11 ) ;
F_58 (page, &n->slabs_full, lru)
F_324 ( V_263 , V_15 , V_22 ) ;
F_58 (page, &n->slabs_partial, lru)
F_324 ( V_263 , V_15 , V_22 ) ;
F_88 ( & V_84 -> V_11 ) ;
}
V_54 = V_15 -> V_54 ;
if ( V_263 [ 0 ] == V_263 [ 1 ] ) {
F_111 ( & V_126 ) ;
V_312 -> V_346 = F_329 ( V_263 [ 0 ] * 4 * sizeof( unsigned long ) , V_108 ) ;
if ( ! V_312 -> V_346 ) {
V_312 -> V_346 = V_263 ;
F_110 ( & V_126 ) ;
return - V_109 ;
}
* ( unsigned long * ) V_312 -> V_346 = V_263 [ 0 ] * 2 ;
F_80 ( V_263 ) ;
F_110 ( & V_126 ) ;
V_312 -> V_331 = V_312 -> V_19 ;
return 0 ;
}
for ( V_88 = 0 ; V_88 < V_263 [ 1 ] ; V_88 ++ ) {
F_319 ( V_312 , L_49 , V_54 , V_263 [ 2 * V_88 + 3 ] ) ;
F_325 ( V_312 , V_263 [ 2 * V_88 + 2 ] ) ;
F_330 ( V_312 , '\n' ) ;
}
return 0 ;
}
static int F_331 ( struct V_347 * V_347 , struct V_329 * V_329 )
{
unsigned long * V_84 ;
V_84 = F_332 ( V_329 , & V_348 , V_49 ) ;
if ( ! V_84 )
return - V_109 ;
* V_84 = V_49 / ( 2 * sizeof( unsigned long ) ) ;
return 0 ;
}
static int T_3 F_333 ( void )
{
#ifdef V_40
F_334 ( L_50 , 0 , NULL , & V_349 ) ;
#endif
return 0 ;
}
T_2 F_335 ( const void * V_1 )
{
F_9 ( ! V_1 ) ;
if ( F_41 ( V_1 == V_350 ) )
return 0 ;
return F_14 ( V_1 ) -> V_207 ;
}
