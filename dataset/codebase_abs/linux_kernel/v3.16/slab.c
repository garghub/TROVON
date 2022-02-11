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
static void F_19 ( struct V_14 * V_15 ,
struct V_36 * V_37 , struct V_36 * V_38 ,
int V_39 )
{
struct V_40 * * V_41 ;
struct V_3 * V_42 ;
int V_43 ;
V_42 = V_15 -> V_44 [ V_39 ] ;
if ( ! V_42 )
return;
F_20 ( & V_42 -> V_11 , V_37 ) ;
V_41 = V_42 -> V_9 ;
if ( ! V_41 || ( unsigned long ) V_41 == V_45 )
return;
F_21 (r) {
if ( V_41 [ V_43 ] )
F_20 ( & V_41 [ V_43 ] -> V_46 , V_38 ) ;
}
}
static void F_22 ( struct V_14 * V_15 , int V_44 )
{
F_19 ( V_15 , & V_47 , & V_48 , V_44 ) ;
}
static void F_23 ( struct V_14 * V_15 )
{
int V_44 ;
F_24 (node)
F_22 ( V_15 , V_44 ) ;
}
static void F_25 ( int V_39 )
{
int V_49 ;
if ( V_50 < V_51 )
return;
for ( V_49 = 1 ; V_49 <= V_52 ; V_49 ++ ) {
struct V_3 * V_42 ;
struct V_14 * V_32 = V_53 [ V_49 ] ;
if ( ! V_32 )
continue;
V_42 = V_32 -> V_44 [ V_39 ] ;
if ( ! V_42 || F_26 ( V_32 ) )
continue;
F_19 ( V_32 , & V_54 ,
& V_55 , V_39 ) ;
}
}
static void F_27 ( struct V_14 * V_15 , int V_39 )
{
if ( ! V_15 -> V_44 [ V_39 ] )
return;
F_19 ( V_15 , & V_54 ,
& V_55 , V_39 ) ;
}
static inline void F_28 ( struct V_14 * V_15 )
{
int V_44 ;
F_29 ( F_26 ( V_15 ) ) ;
F_21 (node)
F_27 ( V_15 , V_44 ) ;
}
static inline void F_30 ( void )
{
int V_44 ;
F_21 (node)
F_25 ( V_44 ) ;
}
static void F_25 ( int V_39 )
{
}
static inline void F_30 ( void )
{
}
static inline void F_28 ( struct V_14 * V_15 )
{
}
static inline void F_27 ( struct V_14 * V_15 , int V_44 )
{
}
static void F_22 ( struct V_14 * V_15 , int V_44 )
{
}
static void F_23 ( struct V_14 * V_15 )
{
}
static inline struct V_40 * F_31 ( struct V_14 * V_15 )
{
return V_15 -> V_56 [ F_32 () ] ;
}
static T_2 F_33 ( int V_57 , T_2 V_58 )
{
T_2 V_25 ;
V_25 = V_57 * sizeof( V_29 ) ;
if ( F_34 ( V_59 ) )
V_25 += V_57 * sizeof( char ) ;
if ( V_58 )
V_25 = F_35 ( V_25 , V_58 ) ;
return V_25 ;
}
static int F_36 ( T_2 V_60 , T_2 V_61 ,
T_2 V_62 , T_2 V_58 )
{
int V_57 ;
T_2 V_63 ;
T_2 V_25 ;
int V_64 = 0 ;
if ( F_34 ( V_59 ) )
V_64 = sizeof( char ) ;
V_57 = V_60 / ( V_61 + V_62 + V_64 ) ;
V_63 = V_60 - V_57 * V_61 ;
V_25 = F_33 ( V_57 , V_58 ) ;
if ( V_63 < V_25 )
V_57 -- ;
return V_57 ;
}
static void F_37 ( unsigned long V_65 , T_2 V_61 ,
T_2 V_58 , int V_16 , T_2 * V_66 ,
unsigned int * V_28 )
{
int V_57 ;
T_2 V_67 ;
T_2 V_60 = V_68 << V_65 ;
if ( V_16 & V_69 ) {
V_67 = 0 ;
V_57 = V_60 / V_61 ;
} else {
V_57 = F_36 ( V_60 , V_61 ,
sizeof( V_29 ) , V_58 ) ;
V_67 = F_33 ( V_57 , V_58 ) ;
}
* V_28 = V_57 ;
* V_66 = V_60 - V_57 * V_61 - V_67 ;
}
static void F_38 ( const char * V_70 , struct V_14 * V_15 ,
char * V_71 )
{
F_39 ( V_72 L_1 ,
V_70 , V_15 -> V_73 , V_71 ) ;
F_40 () ;
F_41 ( V_74 , V_75 ) ;
}
static int T_3 F_42 ( char * V_76 )
{
V_77 = 0 ;
return 1 ;
}
static int T_3 F_43 ( char * V_78 )
{
F_44 ( & V_78 , & V_79 ) ;
V_79 = V_79 < 0 ? 0 :
F_45 ( V_79 , V_80 - 1 ) ;
V_81 = true ;
return 1 ;
}
static void F_46 ( int V_82 )
{
int V_44 ;
V_44 = F_47 ( F_48 ( V_82 ) , V_83 ) ;
if ( V_44 == V_84 )
V_44 = F_49 ( V_83 ) ;
F_50 ( V_85 , V_82 ) = V_44 ;
}
static void F_51 ( void )
{
int V_44 = F_52 ( V_85 ) ;
V_44 = F_47 ( V_44 , V_83 ) ;
if ( F_53 ( V_44 >= V_84 ) )
V_44 = F_49 ( V_83 ) ;
F_54 ( V_85 , V_44 ) ;
}
static void F_55 ( int V_82 )
{
struct V_86 * V_87 = & F_50 ( V_88 , V_82 ) ;
if ( F_56 () && V_87 -> V_89 . V_90 == NULL ) {
F_46 ( V_82 ) ;
F_57 ( V_87 , V_91 ) ;
F_58 ( V_82 , V_87 ,
F_59 ( V_92 , V_82 ) ) ;
}
}
static struct V_40 * F_60 ( int V_44 , int V_93 ,
int V_94 , T_4 V_95 )
{
int V_96 = sizeof( void * ) * V_93 + sizeof( struct V_40 ) ;
struct V_40 * V_97 = NULL ;
V_97 = F_61 ( V_96 , V_95 , V_44 ) ;
F_62 ( V_97 ) ;
if ( V_97 ) {
V_97 -> V_98 = 0 ;
V_97 -> V_99 = V_93 ;
V_97 -> V_94 = V_94 ;
V_97 -> V_100 = 0 ;
F_6 ( & V_97 -> V_46 ) ;
}
return V_97 ;
}
static inline bool F_63 ( struct V_22 * V_22 )
{
return F_64 ( V_22 ) ;
}
static void F_65 ( struct V_14 * V_15 ,
struct V_40 * V_101 )
{
struct V_3 * V_42 = V_15 -> V_44 [ F_66 () ] ;
struct V_22 * V_22 ;
unsigned long V_16 ;
if ( ! V_102 )
return;
F_67 ( & V_42 -> V_11 , V_16 ) ;
F_68 (page, &n->slabs_full, lru)
if ( F_63 ( V_22 ) )
goto V_103;
F_68 (page, &n->slabs_partial, lru)
if ( F_63 ( V_22 ) )
goto V_103;
F_68 (page, &n->slabs_free, lru)
if ( F_63 ( V_22 ) )
goto V_103;
V_102 = false ;
V_103:
F_69 ( & V_42 -> V_11 , V_16 ) ;
}
static void * F_70 ( struct V_14 * V_15 , struct V_40 * V_101 ,
T_4 V_16 , bool V_104 )
{
int V_49 ;
void * V_1 = V_101 -> V_105 [ -- V_101 -> V_98 ] ;
if ( F_53 ( F_1 ( V_1 ) ) ) {
struct V_3 * V_42 ;
if ( F_71 ( V_16 ) ) {
F_3 ( & V_1 ) ;
return V_1 ;
}
for ( V_49 = 0 ; V_49 < V_101 -> V_98 ; V_49 ++ ) {
if ( ! F_1 ( V_101 -> V_105 [ V_49 ] ) ) {
V_1 = V_101 -> V_105 [ V_49 ] ;
V_101 -> V_105 [ V_49 ] = V_101 -> V_105 [ V_101 -> V_98 ] ;
V_101 -> V_105 [ V_101 -> V_98 ] = V_1 ;
return V_1 ;
}
}
V_42 = V_15 -> V_44 [ F_66 () ] ;
if ( ! F_72 ( & V_42 -> V_7 ) && V_104 ) {
struct V_22 * V_22 = F_15 ( V_1 ) ;
F_73 ( V_22 ) ;
F_3 ( & V_1 ) ;
F_65 ( V_15 , V_101 ) ;
return V_1 ;
}
V_101 -> V_98 ++ ;
V_1 = NULL ;
}
return V_1 ;
}
static inline void * F_74 ( struct V_14 * V_15 ,
struct V_40 * V_101 , T_4 V_16 , bool V_104 )
{
void * V_1 ;
if ( F_53 ( F_75 () ) )
V_1 = F_70 ( V_15 , V_101 , V_16 , V_104 ) ;
else
V_1 = V_101 -> V_105 [ -- V_101 -> V_98 ] ;
return V_1 ;
}
static void * F_76 ( struct V_14 * V_15 , struct V_40 * V_101 ,
void * V_1 )
{
if ( F_53 ( V_102 ) ) {
struct V_22 * V_22 = F_15 ( V_1 ) ;
if ( F_64 ( V_22 ) )
F_2 ( & V_1 ) ;
}
return V_1 ;
}
static inline void F_77 ( struct V_14 * V_15 , struct V_40 * V_101 ,
void * V_1 )
{
if ( F_53 ( F_75 () ) )
V_1 = F_76 ( V_15 , V_101 , V_1 ) ;
V_101 -> V_105 [ V_101 -> V_98 ++ ] = V_1 ;
}
static int F_78 ( struct V_40 * V_106 ,
struct V_40 * V_107 , unsigned int V_108 )
{
int V_109 = F_79 ( V_107 -> V_98 , V_108 , V_106 -> V_99 - V_106 -> V_98 ) ;
if ( ! V_109 )
return 0 ;
memcpy ( V_106 -> V_105 + V_106 -> V_98 , V_107 -> V_105 + V_107 -> V_98 - V_109 ,
sizeof( void * ) * V_109 ) ;
V_107 -> V_98 -= V_109 ;
V_106 -> V_98 += V_109 ;
return V_109 ;
}
static inline struct V_40 * * F_80 ( int V_44 , int V_99 , T_4 V_95 )
{
return (struct V_40 * * ) V_45 ;
}
static inline void F_81 ( struct V_40 * * V_110 )
{
}
static inline int F_82 ( struct V_14 * V_15 , void * V_1 )
{
return 0 ;
}
static inline void * F_83 ( struct V_14 * V_15 ,
T_4 V_16 )
{
return NULL ;
}
static inline void * F_84 ( struct V_14 * V_15 ,
T_4 V_16 , int V_111 )
{
return NULL ;
}
static struct V_40 * * F_80 ( int V_44 , int V_99 , T_4 V_95 )
{
struct V_40 * * V_110 ;
int V_96 = sizeof( void * ) * V_112 ;
int V_49 ;
if ( V_99 > 1 )
V_99 = 12 ;
V_110 = F_85 ( V_96 , V_95 , V_44 ) ;
if ( V_110 ) {
F_21 (i) {
if ( V_49 == V_44 || ! F_86 ( V_49 ) )
continue;
V_110 [ V_49 ] = F_60 ( V_44 , V_99 , 0xbaadf00d , V_95 ) ;
if ( ! V_110 [ V_49 ] ) {
for ( V_49 -- ; V_49 >= 0 ; V_49 -- )
F_87 ( V_110 [ V_49 ] ) ;
F_87 ( V_110 ) ;
return NULL ;
}
}
}
return V_110 ;
}
static void F_81 ( struct V_40 * * V_110 )
{
int V_49 ;
if ( ! V_110 )
return;
F_21 (i)
F_87 ( V_110 [ V_49 ] ) ;
F_87 ( V_110 ) ;
}
static void F_88 ( struct V_14 * V_15 ,
struct V_40 * V_101 , int V_44 )
{
struct V_3 * V_42 = V_15 -> V_44 [ V_44 ] ;
if ( V_101 -> V_98 ) {
F_89 ( & V_42 -> V_11 ) ;
if ( V_42 -> V_8 )
F_78 ( V_42 -> V_8 , V_101 , V_101 -> V_99 ) ;
F_90 ( V_15 , V_101 -> V_105 , V_101 -> V_98 , V_44 ) ;
V_101 -> V_98 = 0 ;
F_91 ( & V_42 -> V_11 ) ;
}
}
static void F_92 ( struct V_14 * V_15 , struct V_3 * V_42 )
{
int V_44 = F_52 ( V_85 ) ;
if ( V_42 -> V_9 ) {
struct V_40 * V_101 = V_42 -> V_9 [ V_44 ] ;
if ( V_101 && V_101 -> V_98 && F_93 ( & V_101 -> V_46 ) ) {
F_88 ( V_15 , V_101 , V_44 ) ;
F_94 ( & V_101 -> V_46 ) ;
}
}
}
static void F_95 ( struct V_14 * V_15 ,
struct V_40 * * V_9 )
{
int V_49 = 0 ;
struct V_40 * V_101 ;
unsigned long V_16 ;
F_24 (i) {
V_101 = V_9 [ V_49 ] ;
if ( V_101 ) {
F_67 ( & V_101 -> V_46 , V_16 ) ;
F_88 ( V_15 , V_101 , V_49 ) ;
F_69 ( & V_101 -> V_46 , V_16 ) ;
}
}
}
static inline int F_82 ( struct V_14 * V_15 , void * V_1 )
{
int V_111 = F_96 ( F_97 ( V_1 ) ) ;
struct V_3 * V_42 ;
struct V_40 * V_9 = NULL ;
int V_44 ;
V_44 = F_66 () ;
if ( F_98 ( V_111 == V_44 ) )
return 0 ;
V_42 = V_15 -> V_44 [ V_44 ] ;
F_99 ( V_15 ) ;
if ( V_42 -> V_9 && V_42 -> V_9 [ V_111 ] ) {
V_9 = V_42 -> V_9 [ V_111 ] ;
F_89 ( & V_9 -> V_46 ) ;
if ( F_53 ( V_9 -> V_98 == V_9 -> V_99 ) ) {
F_100 ( V_15 ) ;
F_88 ( V_15 , V_9 , V_111 ) ;
}
F_77 ( V_15 , V_9 , V_1 ) ;
F_91 ( & V_9 -> V_46 ) ;
} else {
F_89 ( & ( V_15 -> V_44 [ V_111 ] ) -> V_11 ) ;
F_90 ( V_15 , & V_1 , 1 , V_111 ) ;
F_91 ( & ( V_15 -> V_44 [ V_111 ] ) -> V_11 ) ;
}
return 1 ;
}
static int F_101 ( int V_44 )
{
struct V_14 * V_15 ;
struct V_3 * V_42 ;
const int V_96 = sizeof( struct V_3 ) ;
F_68 (cachep, &slab_caches, list) {
if ( ! V_15 -> V_44 [ V_44 ] ) {
V_42 = F_61 ( V_96 , V_113 , V_44 ) ;
if ( ! V_42 )
return - V_114 ;
F_4 ( V_42 ) ;
V_42 -> V_115 = V_116 + V_117 +
( ( unsigned long ) V_15 ) % V_117 ;
V_15 -> V_44 [ V_44 ] = V_42 ;
}
F_102 ( & V_15 -> V_44 [ V_44 ] -> V_11 ) ;
V_15 -> V_44 [ V_44 ] -> V_118 =
( 1 + F_103 ( V_44 ) ) *
V_15 -> V_94 + V_15 -> V_28 ;
F_94 ( & V_15 -> V_44 [ V_44 ] -> V_11 ) ;
}
return 0 ;
}
static inline int F_104 ( struct V_14 * V_15 ,
struct V_3 * V_42 )
{
return ( V_42 -> V_12 + V_15 -> V_28 - 1 ) / V_15 -> V_28 ;
}
static void F_105 ( long V_82 )
{
struct V_14 * V_15 ;
struct V_3 * V_42 = NULL ;
int V_44 = F_48 ( V_82 ) ;
const struct V_119 * V_120 = F_106 ( V_44 ) ;
F_68 (cachep, &slab_caches, list) {
struct V_40 * V_97 ;
struct V_40 * V_8 ;
struct V_40 * * V_9 ;
V_97 = V_15 -> V_56 [ V_82 ] ;
V_15 -> V_56 [ V_82 ] = NULL ;
V_42 = V_15 -> V_44 [ V_44 ] ;
if ( ! V_42 )
goto V_121;
F_102 ( & V_42 -> V_11 ) ;
V_42 -> V_118 -= V_15 -> V_94 ;
if ( V_97 )
F_90 ( V_15 , V_97 -> V_105 , V_97 -> V_98 , V_44 ) ;
if ( ! F_107 ( V_120 ) ) {
F_94 ( & V_42 -> V_11 ) ;
goto V_121;
}
V_8 = V_42 -> V_8 ;
if ( V_8 ) {
F_90 ( V_15 , V_8 -> V_105 ,
V_8 -> V_98 , V_44 ) ;
V_42 -> V_8 = NULL ;
}
V_9 = V_42 -> V_9 ;
V_42 -> V_9 = NULL ;
F_94 ( & V_42 -> V_11 ) ;
F_87 ( V_8 ) ;
if ( V_9 ) {
F_95 ( V_15 , V_9 ) ;
F_81 ( V_9 ) ;
}
V_121:
F_87 ( V_97 ) ;
}
F_68 (cachep, &slab_caches, list) {
V_42 = V_15 -> V_44 [ V_44 ] ;
if ( ! V_42 )
continue;
F_108 ( V_15 , V_42 , F_104 ( V_15 , V_42 ) ) ;
}
}
static int F_109 ( long V_82 )
{
struct V_14 * V_15 ;
struct V_3 * V_42 = NULL ;
int V_44 = F_48 ( V_82 ) ;
int V_122 ;
V_122 = F_101 ( V_44 ) ;
if ( V_122 < 0 )
goto V_123;
F_68 (cachep, &slab_caches, list) {
struct V_40 * V_97 ;
struct V_40 * V_8 = NULL ;
struct V_40 * * V_9 = NULL ;
V_97 = F_60 ( V_44 , V_15 -> V_99 ,
V_15 -> V_94 , V_113 ) ;
if ( ! V_97 )
goto V_123;
if ( V_15 -> V_8 ) {
V_8 = F_60 ( V_44 ,
V_15 -> V_8 * V_15 -> V_94 ,
0xbaadf00d , V_113 ) ;
if ( ! V_8 ) {
F_87 ( V_97 ) ;
goto V_123;
}
}
if ( V_77 ) {
V_9 = F_80 ( V_44 , V_15 -> V_99 , V_113 ) ;
if ( ! V_9 ) {
F_87 ( V_8 ) ;
F_87 ( V_97 ) ;
goto V_123;
}
}
V_15 -> V_56 [ V_82 ] = V_97 ;
V_42 = V_15 -> V_44 [ V_44 ] ;
F_9 ( ! V_42 ) ;
F_102 ( & V_42 -> V_11 ) ;
if ( ! V_42 -> V_8 ) {
V_42 -> V_8 = V_8 ;
V_8 = NULL ;
}
#ifdef F_110
if ( ! V_42 -> V_9 ) {
V_42 -> V_9 = V_9 ;
V_9 = NULL ;
}
#endif
F_94 ( & V_42 -> V_11 ) ;
F_87 ( V_8 ) ;
F_81 ( V_9 ) ;
if ( V_15 -> V_16 & V_124 )
F_22 ( V_15 , V_44 ) ;
else if ( ! F_26 ( V_15 ) &&
! ( V_15 -> V_16 & V_125 ) )
F_27 ( V_15 , V_44 ) ;
}
F_25 ( V_44 ) ;
return 0 ;
V_123:
F_105 ( V_82 ) ;
return - V_114 ;
}
static int F_111 ( struct V_126 * V_127 ,
unsigned long V_128 , void * V_129 )
{
long V_82 = ( long ) V_129 ;
int V_122 = 0 ;
switch ( V_128 ) {
case V_130 :
case V_131 :
F_112 ( & V_132 ) ;
V_122 = F_109 ( V_82 ) ;
F_113 ( & V_132 ) ;
break;
case V_133 :
case V_134 :
F_55 ( V_82 ) ;
break;
#ifdef F_114
case V_135 :
case V_136 :
F_115 ( & F_50 ( V_88 , V_82 ) ) ;
F_50 ( V_88 , V_82 ) . V_89 . V_90 = NULL ;
break;
case V_137 :
case V_138 :
F_55 ( V_82 ) ;
break;
case V_139 :
case V_140 :
#endif
case V_141 :
case V_142 :
F_112 ( & V_132 ) ;
F_105 ( V_82 ) ;
F_113 ( & V_132 ) ;
break;
}
return F_116 ( V_122 ) ;
}
static int T_5 F_117 ( int V_44 )
{
struct V_14 * V_15 ;
int V_143 = 0 ;
F_68 (cachep, &slab_caches, list) {
struct V_3 * V_42 ;
V_42 = V_15 -> V_44 [ V_44 ] ;
if ( ! V_42 )
continue;
F_108 ( V_15 , V_42 , F_104 ( V_15 , V_42 ) ) ;
if ( ! F_72 ( & V_42 -> V_5 ) ||
! F_72 ( & V_42 -> V_6 ) ) {
V_143 = - V_144 ;
break;
}
}
return V_143 ;
}
static int T_5 F_118 ( struct V_126 * V_145 ,
unsigned long V_128 , void * V_146 )
{
struct V_147 * V_148 = V_146 ;
int V_143 = 0 ;
int V_149 ;
V_149 = V_148 -> V_150 ;
if ( V_149 < 0 )
goto V_103;
switch ( V_128 ) {
case V_151 :
F_112 ( & V_132 ) ;
V_143 = F_101 ( V_149 ) ;
F_113 ( & V_132 ) ;
break;
case V_152 :
F_112 ( & V_132 ) ;
V_143 = F_117 ( V_149 ) ;
F_113 ( & V_132 ) ;
break;
case V_153 :
case V_154 :
case V_155 :
case V_156 :
break;
}
V_103:
return F_116 ( V_143 ) ;
}
static void T_3 F_119 ( struct V_14 * V_15 , struct V_3 * V_157 ,
int V_111 )
{
struct V_3 * V_158 ;
V_158 = F_61 ( sizeof( struct V_3 ) , V_159 , V_111 ) ;
F_9 ( ! V_158 ) ;
memcpy ( V_158 , V_157 , sizeof( struct V_3 ) ) ;
F_6 ( & V_158 -> V_11 ) ;
F_120 ( V_15 , V_158 , V_111 ) ;
V_15 -> V_44 [ V_111 ] = V_158 ;
}
static void T_3 F_121 ( struct V_14 * V_15 , int V_160 )
{
int V_44 ;
F_24 (node) {
V_15 -> V_44 [ V_44 ] = & V_161 [ V_160 + V_44 ] ;
V_15 -> V_44 [ V_44 ] -> V_115 = V_116 +
V_117 +
( ( unsigned long ) V_15 ) % V_117 ;
}
}
static void F_122 ( struct V_14 * V_15 )
{
V_15 -> V_44 = (struct V_3 * * ) & V_15 -> V_56 [ V_162 ] ;
}
void T_3 F_123 ( void )
{
int V_49 ;
F_124 ( sizeof( ( (struct V_22 * ) NULL ) -> V_163 ) <
sizeof( struct V_164 ) ) ;
V_14 = & V_165 ;
F_122 ( V_14 ) ;
if ( F_125 () == 1 )
V_77 = 0 ;
for ( V_49 = 0 ; V_49 < V_166 ; V_49 ++ )
F_4 ( & V_161 [ V_49 ] ) ;
F_121 ( V_14 , V_167 ) ;
if ( ! V_81 && V_168 > ( 32 << 20 ) >> V_169 )
V_79 = V_170 ;
F_126 ( V_14 , L_2 ,
F_127 ( struct V_14 , V_56 [ V_162 ] ) +
V_112 * sizeof( struct V_3 * ) ,
V_171 ) ;
F_128 ( & V_14 -> V_157 , & V_172 ) ;
V_53 [ V_173 ] = F_129 ( L_3 ,
F_130 ( V_173 ) , V_174 ) ;
if ( V_173 != V_175 )
V_53 [ V_175 ] =
F_129 ( L_4 ,
F_130 ( V_175 ) , V_174 ) ;
V_176 = 0 ;
{
struct V_40 * V_158 ;
V_158 = F_131 ( sizeof( struct V_177 ) , V_159 ) ;
memcpy ( V_158 , F_31 ( V_14 ) ,
sizeof( struct V_177 ) ) ;
F_6 ( & V_158 -> V_46 ) ;
V_14 -> V_56 [ F_32 () ] = V_158 ;
V_158 = F_131 ( sizeof( struct V_177 ) , V_159 ) ;
F_9 ( F_31 ( V_53 [ V_173 ] )
!= & V_178 . V_32 ) ;
memcpy ( V_158 , F_31 ( V_53 [ V_173 ] ) ,
sizeof( struct V_177 ) ) ;
F_6 ( & V_158 -> V_46 ) ;
V_53 [ V_173 ] -> V_56 [ F_32 () ] = V_158 ;
}
{
int V_149 ;
F_24 (nid) {
F_119 ( V_14 , & V_161 [ V_167 + V_149 ] , V_149 ) ;
F_119 ( V_53 [ V_173 ] ,
& V_161 [ V_179 + V_149 ] , V_149 ) ;
if ( V_173 != V_175 ) {
F_119 ( V_53 [ V_175 ] ,
& V_161 [ V_180 + V_149 ] , V_149 ) ;
}
}
}
F_132 ( V_174 ) ;
}
void T_3 F_133 ( void )
{
struct V_14 * V_15 ;
V_50 = V_51 ;
F_112 ( & V_132 ) ;
F_68 (cachep, &slab_caches, list)
if ( F_134 ( V_15 , V_159 ) )
F_135 () ;
F_113 ( & V_132 ) ;
F_30 () ;
V_50 = V_181 ;
F_136 ( & V_182 ) ;
#ifdef F_110
F_137 ( F_118 , V_183 ) ;
#endif
}
static int T_3 F_138 ( void )
{
int V_82 ;
F_139 (cpu)
F_55 ( V_82 ) ;
V_50 = V_181 ;
return 0 ;
}
static T_6 void
F_140 ( struct V_14 * V_15 , T_4 V_184 , int V_111 )
{
#if V_185
struct V_3 * V_42 ;
struct V_22 * V_22 ;
unsigned long V_16 ;
int V_44 ;
static F_141 ( V_186 , V_187 ,
V_188 ) ;
if ( ( V_184 & V_189 ) || ! F_142 ( & V_186 ) )
return;
F_39 ( V_190
L_5 ,
V_111 , V_184 ) ;
F_39 ( V_190 L_6 ,
V_15 -> V_73 , V_15 -> V_19 , V_15 -> V_65 ) ;
F_24 (node) {
unsigned long V_191 = 0 , V_192 = 0 , V_12 = 0 ;
unsigned long V_193 = 0 , V_194 = 0 ;
V_42 = V_15 -> V_44 [ V_44 ] ;
if ( ! V_42 )
continue;
F_67 ( & V_42 -> V_11 , V_16 ) ;
F_68 (page, &n->slabs_full, lru) {
V_191 += V_15 -> V_28 ;
V_193 ++ ;
}
F_68 (page, &n->slabs_partial, lru) {
V_191 += V_22 -> V_195 ;
V_193 ++ ;
}
F_68 (page, &n->slabs_free, lru)
V_194 ++ ;
V_12 += V_42 -> V_12 ;
F_69 ( & V_42 -> V_11 , V_16 ) ;
V_194 += V_193 ;
V_192 = V_194 * V_15 -> V_28 ;
F_39 ( V_190
L_7 ,
V_44 , V_193 , V_194 , V_191 , V_192 ,
V_12 ) ;
}
#endif
}
static struct V_22 * F_143 ( struct V_14 * V_15 , T_4 V_16 ,
int V_111 )
{
struct V_22 * V_22 ;
int V_196 ;
V_16 |= V_15 -> V_197 ;
if ( V_15 -> V_16 & V_198 )
V_16 |= V_199 ;
if ( F_144 ( V_15 , V_16 , V_15 -> V_65 ) )
return NULL ;
V_22 = F_145 ( V_111 , V_16 | V_200 , V_15 -> V_65 ) ;
if ( ! V_22 ) {
F_146 ( V_15 , V_15 -> V_65 ) ;
F_140 ( V_15 , V_16 , V_111 ) ;
return NULL ;
}
if ( F_53 ( V_22 -> V_201 ) )
V_102 = true ;
V_196 = ( 1 << V_15 -> V_65 ) ;
if ( V_15 -> V_16 & V_198 )
F_147 ( F_148 ( V_22 ) ,
V_202 , V_196 ) ;
else
F_147 ( F_148 ( V_22 ) ,
V_203 , V_196 ) ;
F_149 ( V_22 ) ;
if ( V_22 -> V_201 )
F_150 ( V_22 ) ;
if ( V_204 && ! ( V_15 -> V_16 & V_205 ) ) {
F_151 ( V_22 , V_15 -> V_65 , V_16 , V_111 ) ;
if ( V_15 -> V_206 )
F_152 ( V_22 , V_196 ) ;
else
F_153 ( V_22 , V_196 ) ;
}
return V_22 ;
}
static void F_154 ( struct V_14 * V_15 , struct V_22 * V_22 )
{
const unsigned long V_207 = ( 1 << V_15 -> V_65 ) ;
F_155 ( V_22 , V_15 -> V_65 ) ;
if ( V_15 -> V_16 & V_198 )
F_156 ( F_148 ( V_22 ) ,
V_202 , V_207 ) ;
else
F_156 ( F_148 ( V_22 ) ,
V_203 , V_207 ) ;
F_9 ( ! F_157 ( V_22 ) ) ;
F_158 ( V_22 ) ;
F_159 ( V_22 ) ;
F_160 ( V_22 ) ;
V_22 -> V_208 = NULL ;
if ( V_209 -> V_210 )
V_209 -> V_210 -> V_211 += V_207 ;
F_161 ( V_22 , V_15 -> V_65 ) ;
F_146 ( V_15 , V_15 -> V_65 ) ;
}
static void F_162 ( struct V_164 * V_212 )
{
struct V_14 * V_15 ;
struct V_22 * V_22 ;
V_22 = F_163 ( V_212 , struct V_22 , V_164 ) ;
V_15 = V_22 -> V_27 ;
F_154 ( V_15 , V_22 ) ;
}
static void F_164 ( struct V_14 * V_15 , unsigned long * V_213 ,
unsigned long V_214 )
{
int V_19 = V_15 -> V_215 ;
V_213 = ( unsigned long * ) & ( ( char * ) V_213 ) [ F_7 ( V_15 ) ] ;
if ( V_19 < 5 * sizeof( unsigned long ) )
return;
* V_213 ++ = 0x12345678 ;
* V_213 ++ = V_214 ;
* V_213 ++ = F_32 () ;
V_19 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_216 = & V_214 ;
unsigned long V_217 ;
while ( ! F_165 ( V_216 ) ) {
V_217 = * V_216 ++ ;
if ( F_166 ( V_217 ) ) {
* V_213 ++ = V_217 ;
V_19 -= sizeof( unsigned long ) ;
if ( V_19 <= sizeof( unsigned long ) )
break;
}
}
}
* V_213 ++ = 0x87654321 ;
}
static void F_167 ( struct V_14 * V_15 , void * V_213 , unsigned char V_24 )
{
int V_19 = V_15 -> V_215 ;
V_213 = & ( ( char * ) V_213 ) [ F_7 ( V_15 ) ] ;
memset ( V_213 , V_24 , V_19 ) ;
* ( unsigned char * ) ( V_213 + V_19 - 1 ) = V_218 ;
}
static void F_168 ( char * V_219 , int V_34 , int V_99 )
{
int V_49 ;
unsigned char error = 0 ;
int V_220 = 0 ;
F_39 ( V_72 L_8 , V_34 ) ;
for ( V_49 = 0 ; V_49 < V_99 ; V_49 ++ ) {
if ( V_219 [ V_34 + V_49 ] != V_221 ) {
error = V_219 [ V_34 + V_49 ] ;
V_220 ++ ;
}
}
F_169 ( V_222 , L_9 , 0 , 16 , 1 ,
& V_219 [ V_34 ] , V_99 , 1 ) ;
if ( V_220 == 1 ) {
error ^= V_221 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_39 ( V_72 L_10
L_11 ) ;
#ifdef F_170
F_39 ( V_72 L_12
L_13 ) ;
#else
F_39 ( V_72 L_14 ) ;
#endif
}
}
}
static void F_171 ( struct V_14 * V_15 , void * V_1 , int V_223 )
{
int V_49 , V_19 ;
char * V_224 ;
if ( V_15 -> V_16 & V_17 ) {
F_39 ( V_72 L_15 ,
* F_8 ( V_15 , V_1 ) ,
* F_10 ( V_15 , V_1 ) ) ;
}
if ( V_15 -> V_16 & V_18 ) {
F_39 ( V_72 L_16 ,
* F_11 ( V_15 , V_1 ) ,
* F_11 ( V_15 , V_1 ) ) ;
}
V_224 = ( char * ) V_1 + F_7 ( V_15 ) ;
V_19 = V_15 -> V_215 ;
for ( V_49 = 0 ; V_49 < V_19 && V_223 ; V_49 += 16 , V_223 -- ) {
int V_99 ;
V_99 = 16 ;
if ( V_49 + V_99 > V_19 )
V_99 = V_19 - V_49 ;
F_168 ( V_224 , V_49 , V_99 ) ;
}
}
static void F_172 ( struct V_14 * V_15 , void * V_1 )
{
char * V_224 ;
int V_19 , V_49 ;
int V_223 = 0 ;
V_224 = ( char * ) V_1 + F_7 ( V_15 ) ;
V_19 = V_15 -> V_215 ;
for ( V_49 = 0 ; V_49 < V_19 ; V_49 ++ ) {
char exp = V_221 ;
if ( V_49 == V_19 - 1 )
exp = V_218 ;
if ( V_224 [ V_49 ] != exp ) {
int V_99 ;
if ( V_223 == 0 ) {
F_39 ( V_72
L_17 ,
F_173 () , V_15 -> V_73 , V_224 , V_19 ) ;
F_171 ( V_15 , V_1 , 0 ) ;
}
V_49 = ( V_49 / 16 ) * 16 ;
V_99 = 16 ;
if ( V_49 + V_99 > V_19 )
V_99 = V_19 - V_49 ;
F_168 ( V_224 , V_49 , V_99 ) ;
V_49 += 16 ;
V_223 ++ ;
if ( V_223 > 5 )
break;
}
}
if ( V_223 != 0 ) {
struct V_22 * V_22 = F_15 ( V_1 ) ;
unsigned int V_225 ;
V_225 = F_17 ( V_15 , V_22 , V_1 ) ;
if ( V_225 ) {
V_1 = F_16 ( V_15 , V_22 , V_225 - 1 ) ;
V_224 = ( char * ) V_1 + F_7 ( V_15 ) ;
F_39 ( V_72 L_18 ,
V_224 , V_19 ) ;
F_171 ( V_15 , V_1 , 2 ) ;
}
if ( V_225 + 1 < V_15 -> V_28 ) {
V_1 = F_16 ( V_15 , V_22 , V_225 + 1 ) ;
V_224 = ( char * ) V_1 + F_7 ( V_15 ) ;
F_39 ( V_72 L_19 ,
V_224 , V_19 ) ;
F_171 ( V_15 , V_1 , 2 ) ;
}
}
}
static void F_174 ( struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_15 -> V_28 ; V_49 ++ ) {
void * V_1 = F_16 ( V_15 , V_22 , V_49 ) ;
if ( V_15 -> V_16 & V_226 ) {
#ifdef F_175
if ( V_15 -> V_19 % V_68 == 0 &&
F_26 ( V_15 ) )
F_176 ( F_97 ( V_1 ) ,
V_15 -> V_19 / V_68 , 1 ) ;
else
F_172 ( V_15 , V_1 ) ;
#else
F_172 ( V_15 , V_1 ) ;
#endif
}
if ( V_15 -> V_16 & V_17 ) {
if ( * F_8 ( V_15 , V_1 ) != V_227 )
F_177 ( V_15 , L_20
L_21 ) ;
if ( * F_10 ( V_15 , V_1 ) != V_227 )
F_177 ( V_15 , L_22
L_21 ) ;
}
}
}
static void F_174 ( struct V_14 * V_15 ,
struct V_22 * V_22 )
{
}
static void F_178 ( struct V_14 * V_15 , struct V_22 * V_22 )
{
void * V_30 ;
V_30 = V_22 -> V_30 ;
F_174 ( V_15 , V_22 ) ;
if ( F_53 ( V_15 -> V_16 & V_125 ) ) {
struct V_164 * V_212 ;
V_212 = ( void * ) & V_22 -> V_164 ;
F_179 ( V_212 , F_162 ) ;
} else {
F_154 ( V_15 , V_22 ) ;
}
if ( F_26 ( V_15 ) )
F_180 ( V_15 -> V_228 , V_30 ) ;
}
static T_2 F_181 ( struct V_14 * V_15 ,
T_2 V_19 , T_2 V_58 , unsigned long V_16 )
{
unsigned long V_229 ;
T_2 V_66 = 0 ;
int V_65 ;
for ( V_65 = 0 ; V_65 <= V_230 ; V_65 ++ ) {
unsigned int V_28 ;
T_2 V_231 ;
F_37 ( V_65 , V_19 , V_58 , V_16 , & V_231 , & V_28 ) ;
if ( ! V_28 )
continue;
if ( V_28 > V_232 )
break;
if ( V_16 & V_69 ) {
T_2 V_233 = sizeof( V_29 ) ;
if ( F_34 ( V_59 ) )
V_233 += sizeof( char ) ;
V_229 = V_19 ;
V_229 /= V_233 ;
if ( V_28 > V_229 )
break;
}
V_15 -> V_28 = V_28 ;
V_15 -> V_65 = V_65 ;
V_66 = V_231 ;
if ( V_16 & V_198 )
break;
if ( V_65 >= V_79 )
break;
if ( V_66 * 8 <= ( V_68 << V_65 ) )
break;
}
return V_66 ;
}
static int T_7 F_182 ( struct V_14 * V_15 , T_4 V_95 )
{
if ( V_50 >= V_181 )
return F_134 ( V_15 , V_95 ) ;
if ( V_50 == V_234 ) {
V_15 -> V_56 [ F_32 () ] = & V_178 . V_32 ;
V_50 = V_235 ;
} else if ( V_50 == V_235 ) {
V_15 -> V_56 [ F_32 () ] = & V_178 . V_32 ;
F_121 ( V_15 , V_179 ) ;
if ( V_173 == V_175 )
V_50 = V_236 ;
else
V_50 = V_237 ;
} else {
V_15 -> V_56 [ F_32 () ] =
F_131 ( sizeof( struct V_177 ) , V_95 ) ;
if ( V_50 == V_237 ) {
F_121 ( V_15 , V_180 ) ;
V_50 = V_236 ;
} else {
int V_44 ;
F_24 (node) {
V_15 -> V_44 [ V_44 ] =
F_61 ( sizeof( struct V_3 ) ,
V_95 , V_44 ) ;
F_9 ( ! V_15 -> V_44 [ V_44 ] ) ;
F_4 ( V_15 -> V_44 [ V_44 ] ) ;
}
}
}
V_15 -> V_44 [ F_66 () ] -> V_115 =
V_116 + V_117 +
( ( unsigned long ) V_15 ) % V_117 ;
F_31 ( V_15 ) -> V_98 = 0 ;
F_31 ( V_15 ) -> V_99 = V_238 ;
F_31 ( V_15 ) -> V_94 = 1 ;
F_31 ( V_15 ) -> V_100 = 0 ;
V_15 -> V_94 = 1 ;
V_15 -> V_99 = V_238 ;
return 0 ;
}
int
F_183 ( struct V_14 * V_15 , unsigned long V_16 )
{
T_2 V_66 , V_25 , V_239 ;
T_4 V_95 ;
int V_122 ;
T_2 V_19 = V_15 -> V_19 ;
#if V_185
#if V_240
if ( V_19 < 4096 || F_184 ( V_19 - 1 ) == F_184 ( V_19 - 1 + V_20 +
2 * sizeof( unsigned long long ) ) )
V_16 |= V_17 | V_18 ;
if ( ! ( V_16 & V_125 ) )
V_16 |= V_226 ;
#endif
if ( V_16 & V_125 )
F_9 ( V_16 & V_226 ) ;
#endif
if ( V_19 & ( V_21 - 1 ) ) {
V_19 += ( V_21 - 1 ) ;
V_19 &= ~ ( V_21 - 1 ) ;
}
if ( V_16 & V_18 )
V_239 = V_21 ;
if ( V_16 & V_17 ) {
V_239 = V_20 ;
V_19 += V_20 - 1 ;
V_19 &= ~ ( V_20 - 1 ) ;
}
if ( V_239 < V_15 -> V_58 ) {
V_239 = V_15 -> V_58 ;
}
if ( V_239 > F_185 (unsigned long long) )
V_16 &= ~ ( V_17 | V_18 ) ;
V_15 -> V_58 = V_239 ;
if ( F_186 () )
V_95 = V_113 ;
else
V_95 = V_159 ;
F_122 ( V_15 ) ;
#if V_185
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
#if V_240 && F_187 ( F_175 )
if ( V_19 >= F_130 ( V_175 + 1 )
&& V_15 -> V_215 > F_188 ()
&& F_35 ( V_19 , V_15 -> V_58 ) < V_68 ) {
V_15 -> F_7 += V_68 - F_35 ( V_19 , V_15 -> V_58 ) ;
V_19 = V_68 ;
}
#endif
#endif
if ( ( V_19 >= ( V_68 >> 5 ) ) && ! V_176 &&
! ( V_16 & V_241 ) )
V_16 |= V_69 ;
V_19 = F_35 ( V_19 , V_15 -> V_58 ) ;
if ( V_242 && V_19 < V_243 )
V_19 = F_35 ( V_243 , V_15 -> V_58 ) ;
V_66 = F_181 ( V_15 , V_19 , V_15 -> V_58 , V_16 ) ;
if ( ! V_15 -> V_28 )
return - V_244 ;
V_25 = F_33 ( V_15 -> V_28 , V_15 -> V_58 ) ;
if ( V_16 & V_69 && V_66 >= V_25 ) {
V_16 &= ~ V_69 ;
V_66 -= V_25 ;
}
if ( V_16 & V_69 ) {
V_25 = F_33 ( V_15 -> V_28 , 0 ) ;
#ifdef F_189
if ( V_19 % V_68 == 0 && V_16 & V_226 )
V_16 &= ~ ( V_17 | V_18 ) ;
#endif
}
V_15 -> V_245 = F_188 () ;
if ( V_15 -> V_245 < V_15 -> V_58 )
V_15 -> V_245 = V_15 -> V_58 ;
V_15 -> V_246 = V_66 / V_15 -> V_245 ;
V_15 -> V_25 = V_25 ;
V_15 -> V_16 = V_16 ;
V_15 -> V_197 = V_247 ;
if ( V_248 && ( V_16 & V_249 ) )
V_15 -> V_197 |= V_250 ;
V_15 -> V_19 = V_19 ;
V_15 -> V_35 = F_190 ( V_19 ) ;
if ( V_16 & V_69 ) {
V_15 -> V_228 = F_191 ( V_25 , 0u ) ;
F_9 ( F_192 ( V_15 -> V_228 ) ) ;
}
V_122 = F_182 ( V_15 , V_95 ) ;
if ( V_122 ) {
F_193 ( V_15 ) ;
return V_122 ;
}
if ( V_16 & V_124 ) {
F_194 ( V_16 & V_125 ) ;
F_23 ( V_15 ) ;
} else if ( ! F_26 ( V_15 ) && ! ( V_16 & V_125 ) )
F_28 ( V_15 ) ;
return 0 ;
}
static void F_195 ( void )
{
F_9 ( ! F_196 () ) ;
}
static void F_197 ( void )
{
F_9 ( F_196 () ) ;
}
static void F_198 ( struct V_14 * V_15 )
{
#ifdef F_199
F_195 () ;
F_200 ( & V_15 -> V_44 [ F_66 () ] -> V_11 ) ;
#endif
}
static void F_201 ( struct V_14 * V_15 , int V_44 )
{
#ifdef F_199
F_195 () ;
F_200 ( & V_15 -> V_44 [ V_44 ] -> V_11 ) ;
#endif
}
static void F_202 ( void * V_146 )
{
struct V_14 * V_15 = V_146 ;
struct V_40 * V_101 ;
int V_44 = F_66 () ;
F_195 () ;
V_101 = F_31 ( V_15 ) ;
F_89 ( & V_15 -> V_44 [ V_44 ] -> V_11 ) ;
F_90 ( V_15 , V_101 -> V_105 , V_101 -> V_98 , V_44 ) ;
F_91 ( & V_15 -> V_44 [ V_44 ] -> V_11 ) ;
V_101 -> V_98 = 0 ;
}
static void F_203 ( struct V_14 * V_15 )
{
struct V_3 * V_42 ;
int V_44 ;
F_204 ( F_202 , V_15 , 1 ) ;
F_197 () ;
F_24 (node) {
V_42 = V_15 -> V_44 [ V_44 ] ;
if ( V_42 && V_42 -> V_9 )
F_95 ( V_15 , V_42 -> V_9 ) ;
}
F_24 (node) {
V_42 = V_15 -> V_44 [ V_44 ] ;
if ( V_42 )
F_205 ( V_15 , V_42 , V_42 -> V_8 , 1 , V_44 ) ;
}
}
static int F_108 ( struct V_14 * V_32 ,
struct V_3 * V_42 , int V_251 )
{
struct V_252 * V_253 ;
int V_207 ;
struct V_22 * V_22 ;
V_207 = 0 ;
while ( V_207 < V_251 && ! F_72 ( & V_42 -> V_7 ) ) {
F_102 ( & V_42 -> V_11 ) ;
V_253 = V_42 -> V_7 . V_254 ;
if ( V_253 == & V_42 -> V_7 ) {
F_94 ( & V_42 -> V_11 ) ;
goto V_103;
}
V_22 = F_206 ( V_253 , struct V_22 , V_163 ) ;
#if V_185
F_9 ( V_22 -> V_195 ) ;
#endif
F_207 ( & V_22 -> V_163 ) ;
V_42 -> V_12 -= V_32 -> V_28 ;
F_94 ( & V_42 -> V_11 ) ;
F_178 ( V_32 , V_22 ) ;
V_207 ++ ;
}
V_103:
return V_207 ;
}
int F_208 ( struct V_14 * V_15 )
{
int V_143 = 0 , V_49 = 0 ;
struct V_3 * V_42 ;
F_203 ( V_15 ) ;
F_197 () ;
F_24 (i) {
V_42 = V_15 -> V_44 [ V_49 ] ;
if ( ! V_42 )
continue;
F_108 ( V_15 , V_42 , F_104 ( V_15 , V_42 ) ) ;
V_143 += ! F_72 ( & V_42 -> V_5 ) ||
! F_72 ( & V_42 -> V_6 ) ;
}
return ( V_143 ? 1 : 0 ) ;
}
int F_193 ( struct V_14 * V_15 )
{
int V_49 ;
struct V_3 * V_42 ;
int V_255 = F_208 ( V_15 ) ;
if ( V_255 )
return V_255 ;
F_139 (i)
F_87 ( V_15 -> V_56 [ V_49 ] ) ;
F_24 (i) {
V_42 = V_15 -> V_44 [ V_49 ] ;
if ( V_42 ) {
F_87 ( V_42 -> V_8 ) ;
F_81 ( V_42 -> V_9 ) ;
F_87 ( V_42 ) ;
}
}
return 0 ;
}
static void * F_209 ( struct V_14 * V_15 ,
struct V_22 * V_22 , int V_245 ,
T_4 V_256 , int V_111 )
{
void * V_30 ;
void * V_213 = F_210 ( V_22 ) ;
if ( F_26 ( V_15 ) ) {
V_30 = F_211 ( V_15 -> V_228 ,
V_256 , V_111 ) ;
if ( ! V_30 )
return NULL ;
} else {
V_30 = V_213 + V_245 ;
V_245 += V_15 -> V_25 ;
}
V_22 -> V_195 = 0 ;
V_22 -> V_33 = V_213 + V_245 ;
return V_30 ;
}
static inline V_29 F_212 ( struct V_22 * V_22 , unsigned int V_23 )
{
return ( ( V_29 * ) V_22 -> V_30 ) [ V_23 ] ;
}
static inline void F_213 ( struct V_22 * V_22 ,
unsigned int V_23 , V_29 V_24 )
{
( ( V_29 * ) ( V_22 -> V_30 ) ) [ V_23 ] = V_24 ;
}
static void F_214 ( struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_49 ;
for ( V_49 = 0 ; V_49 < V_15 -> V_28 ; V_49 ++ ) {
void * V_1 = F_16 ( V_15 , V_22 , V_49 ) ;
#if V_185
if ( V_15 -> V_16 & V_226 )
F_167 ( V_15 , V_1 , V_221 ) ;
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = NULL ;
if ( V_15 -> V_16 & V_17 ) {
* F_8 ( V_15 , V_1 ) = V_227 ;
* F_10 ( V_15 , V_1 ) = V_227 ;
}
if ( V_15 -> V_206 && ! ( V_15 -> V_16 & V_226 ) )
V_15 -> V_206 ( V_1 + F_7 ( V_15 ) ) ;
if ( V_15 -> V_16 & V_17 ) {
if ( * F_10 ( V_15 , V_1 ) != V_227 )
F_177 ( V_15 , L_23
L_24 ) ;
if ( * F_8 ( V_15 , V_1 ) != V_227 )
F_177 ( V_15 , L_23
L_25 ) ;
}
if ( ( V_15 -> V_19 % V_68 ) == 0 &&
F_26 ( V_15 ) && V_15 -> V_16 & V_226 )
F_176 ( F_97 ( V_1 ) ,
V_15 -> V_19 / V_68 , 0 ) ;
#else
if ( V_15 -> V_206 )
V_15 -> V_206 ( V_1 ) ;
#endif
F_12 ( V_22 , V_49 , V_257 ) ;
F_213 ( V_22 , V_49 , V_49 ) ;
}
}
static void F_215 ( struct V_14 * V_15 , T_4 V_16 )
{
if ( V_248 ) {
if ( V_16 & V_250 )
F_9 ( ! ( V_15 -> V_197 & V_250 ) ) ;
else
F_9 ( V_15 -> V_197 & V_250 ) ;
}
}
static void * F_216 ( struct V_14 * V_15 , struct V_22 * V_22 ,
int V_111 )
{
void * V_1 ;
V_1 = F_16 ( V_15 , V_22 , F_212 ( V_22 , V_22 -> V_195 ) ) ;
V_22 -> V_195 ++ ;
#if V_185
F_217 ( F_96 ( F_97 ( V_1 ) ) != V_111 ) ;
#endif
return V_1 ;
}
static void F_218 ( struct V_14 * V_15 , struct V_22 * V_22 ,
void * V_1 , int V_111 )
{
unsigned int V_225 = F_17 ( V_15 , V_22 , V_1 ) ;
#if V_185
unsigned int V_49 ;
F_217 ( F_96 ( F_97 ( V_1 ) ) != V_111 ) ;
for ( V_49 = V_22 -> V_195 ; V_49 < V_15 -> V_28 ; V_49 ++ ) {
if ( F_212 ( V_22 , V_49 ) == V_225 ) {
F_39 ( V_72 L_26
L_27 , V_15 -> V_73 , V_1 ) ;
F_135 () ;
}
}
#endif
V_22 -> V_195 -- ;
F_213 ( V_22 , V_22 -> V_195 , V_225 ) ;
}
static void F_219 ( struct V_14 * V_32 , struct V_22 * V_22 ,
void * V_30 )
{
V_22 -> V_27 = V_32 ;
V_22 -> V_30 = V_30 ;
}
static int F_220 ( struct V_14 * V_15 ,
T_4 V_16 , int V_111 , struct V_22 * V_22 )
{
void * V_30 ;
T_2 V_34 ;
T_4 V_256 ;
struct V_3 * V_42 ;
F_9 ( V_16 & V_258 ) ;
V_256 = V_16 & ( V_259 | V_260 ) ;
F_195 () ;
V_42 = V_15 -> V_44 [ V_111 ] ;
F_89 ( & V_42 -> V_11 ) ;
V_34 = V_42 -> V_10 ;
V_42 -> V_10 ++ ;
if ( V_42 -> V_10 >= V_15 -> V_246 )
V_42 -> V_10 = 0 ;
F_91 ( & V_42 -> V_11 ) ;
V_34 *= V_15 -> V_245 ;
if ( V_256 & V_261 )
F_221 () ;
F_215 ( V_15 , V_16 ) ;
if ( ! V_22 )
V_22 = F_143 ( V_15 , V_256 , V_111 ) ;
if ( ! V_22 )
goto V_262;
V_30 = F_209 ( V_15 , V_22 , V_34 ,
V_256 & ~ V_259 , V_111 ) ;
if ( ! V_30 )
goto V_263;
F_219 ( V_15 , V_22 , V_30 ) ;
F_214 ( V_15 , V_22 ) ;
if ( V_256 & V_261 )
F_222 () ;
F_195 () ;
F_89 ( & V_42 -> V_11 ) ;
F_223 ( & V_22 -> V_163 , & ( V_42 -> V_7 ) ) ;
F_224 ( V_15 ) ;
V_42 -> V_12 += V_15 -> V_28 ;
F_91 ( & V_42 -> V_11 ) ;
return 1 ;
V_263:
F_154 ( V_15 , V_22 ) ;
V_262:
if ( V_256 & V_261 )
F_222 () ;
return 0 ;
}
static void F_225 ( const void * V_1 )
{
if ( ! F_226 ( V_1 ) ) {
F_39 ( V_72 L_28 ,
( unsigned long ) V_1 ) ;
F_135 () ;
}
}
static inline void F_227 ( struct V_14 * V_32 , void * V_31 )
{
unsigned long long V_264 , V_265 ;
V_264 = * F_8 ( V_32 , V_31 ) ;
V_265 = * F_10 ( V_32 , V_31 ) ;
if ( V_264 == V_266 && V_265 == V_266 )
return;
if ( V_264 == V_227 && V_265 == V_227 )
F_177 ( V_32 , L_29 ) ;
else
F_177 ( V_32 , L_30 ) ;
F_39 ( V_72 L_31 ,
V_31 , V_264 , V_265 ) ;
}
static void * F_228 ( struct V_14 * V_15 , void * V_1 ,
unsigned long V_214 )
{
unsigned int V_225 ;
struct V_22 * V_22 ;
F_9 ( F_14 ( V_1 ) != V_15 ) ;
V_1 -= F_7 ( V_15 ) ;
F_225 ( V_1 ) ;
V_22 = F_15 ( V_1 ) ;
if ( V_15 -> V_16 & V_17 ) {
F_227 ( V_15 , V_1 ) ;
* F_8 ( V_15 , V_1 ) = V_227 ;
* F_10 ( V_15 , V_1 ) = V_227 ;
}
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = ( void * ) V_214 ;
V_225 = F_17 ( V_15 , V_22 , V_1 ) ;
F_9 ( V_225 >= V_15 -> V_28 ) ;
F_9 ( V_1 != F_16 ( V_15 , V_22 , V_225 ) ) ;
F_12 ( V_22 , V_225 , V_257 ) ;
if ( V_15 -> V_16 & V_226 ) {
#ifdef F_175
if ( ( V_15 -> V_19 % V_68 ) == 0 && F_26 ( V_15 ) ) {
F_164 ( V_15 , V_1 , V_214 ) ;
F_176 ( F_97 ( V_1 ) ,
V_15 -> V_19 / V_68 , 0 ) ;
} else {
F_167 ( V_15 , V_1 , V_221 ) ;
}
#else
F_167 ( V_15 , V_1 , V_221 ) ;
#endif
}
return V_1 ;
}
static void * F_229 ( struct V_14 * V_15 , T_4 V_16 ,
bool V_104 )
{
int V_94 ;
struct V_3 * V_42 ;
struct V_40 * V_101 ;
int V_44 ;
F_195 () ;
V_44 = F_66 () ;
if ( F_53 ( V_104 ) )
goto V_267;
V_268:
V_101 = F_31 ( V_15 ) ;
V_94 = V_101 -> V_94 ;
if ( ! V_101 -> V_100 && V_94 > V_269 ) {
V_94 = V_269 ;
}
V_42 = V_15 -> V_44 [ V_44 ] ;
F_9 ( V_101 -> V_98 > 0 || ! V_42 ) ;
F_89 ( & V_42 -> V_11 ) ;
if ( V_42 -> V_8 && F_78 ( V_101 , V_42 -> V_8 , V_94 ) ) {
V_42 -> V_8 -> V_100 = 1 ;
goto V_270;
}
while ( V_94 > 0 ) {
struct V_252 * V_105 ;
struct V_22 * V_22 ;
V_105 = V_42 -> V_6 . V_271 ;
if ( V_105 == & V_42 -> V_6 ) {
V_42 -> V_13 = 1 ;
V_105 = V_42 -> V_7 . V_271 ;
if ( V_105 == & V_42 -> V_7 )
goto V_272;
}
V_22 = F_206 ( V_105 , struct V_22 , V_163 ) ;
F_198 ( V_15 ) ;
F_9 ( V_22 -> V_195 >= V_15 -> V_28 ) ;
while ( V_22 -> V_195 < V_15 -> V_28 && V_94 -- ) {
F_230 ( V_15 ) ;
F_231 ( V_15 ) ;
F_232 ( V_15 ) ;
F_77 ( V_15 , V_101 , F_216 ( V_15 , V_22 ,
V_44 ) ) ;
}
F_207 ( & V_22 -> V_163 ) ;
if ( V_22 -> V_195 == V_15 -> V_28 )
F_128 ( & V_22 -> V_163 , & V_42 -> V_5 ) ;
else
F_128 ( & V_22 -> V_163 , & V_42 -> V_6 ) ;
}
V_272:
V_42 -> V_12 -= V_101 -> V_98 ;
V_270:
F_91 ( & V_42 -> V_11 ) ;
if ( F_53 ( ! V_101 -> V_98 ) ) {
int V_273 ;
V_267:
V_273 = F_220 ( V_15 , V_16 | V_274 , V_44 , NULL ) ;
V_101 = F_31 ( V_15 ) ;
V_44 = F_66 () ;
if ( ! V_273 && ( V_101 -> V_98 == 0 || V_104 ) )
return NULL ;
if ( ! V_101 -> V_98 )
goto V_268;
}
V_101 -> V_100 = 1 ;
return F_74 ( V_15 , V_101 , V_16 , V_104 ) ;
}
static inline void F_233 ( struct V_14 * V_15 ,
T_4 V_16 )
{
F_234 ( V_16 & V_261 ) ;
#if V_185
F_215 ( V_15 , V_16 ) ;
#endif
}
static void * F_235 ( struct V_14 * V_15 ,
T_4 V_16 , void * V_1 , unsigned long V_214 )
{
struct V_22 * V_22 ;
if ( ! V_1 )
return V_1 ;
if ( V_15 -> V_16 & V_226 ) {
#ifdef F_175
if ( ( V_15 -> V_19 % V_68 ) == 0 && F_26 ( V_15 ) )
F_176 ( F_97 ( V_1 ) ,
V_15 -> V_19 / V_68 , 1 ) ;
else
F_172 ( V_15 , V_1 ) ;
#else
F_172 ( V_15 , V_1 ) ;
#endif
F_167 ( V_15 , V_1 , V_275 ) ;
}
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = ( void * ) V_214 ;
if ( V_15 -> V_16 & V_17 ) {
if ( * F_8 ( V_15 , V_1 ) != V_227 ||
* F_10 ( V_15 , V_1 ) != V_227 ) {
F_177 ( V_15 , L_32
L_33 ) ;
F_39 ( V_72
L_34 ,
V_1 , * F_8 ( V_15 , V_1 ) ,
* F_10 ( V_15 , V_1 ) ) ;
}
* F_8 ( V_15 , V_1 ) = V_266 ;
* F_10 ( V_15 , V_1 ) = V_266 ;
}
V_22 = F_15 ( V_1 ) ;
F_12 ( V_22 , F_17 ( V_15 , V_22 , V_1 ) , V_276 ) ;
V_1 += F_7 ( V_15 ) ;
if ( V_15 -> V_206 && V_15 -> V_16 & V_226 )
V_15 -> V_206 ( V_1 ) ;
if ( V_277 &&
( ( unsigned long ) V_1 & ( V_277 - 1 ) ) ) {
F_39 ( V_72 L_35 ,
V_1 , ( int ) V_277 ) ;
}
return V_1 ;
}
static bool F_236 ( struct V_14 * V_15 , T_4 V_16 )
{
if ( V_15 == V_14 )
return false ;
return F_237 ( V_15 -> V_215 , V_16 , V_15 -> V_16 ) ;
}
static inline void * F_238 ( struct V_14 * V_15 , T_4 V_16 )
{
void * V_1 ;
struct V_40 * V_101 ;
bool V_104 = false ;
F_195 () ;
V_101 = F_31 ( V_15 ) ;
if ( F_98 ( V_101 -> V_98 ) ) {
V_101 -> V_100 = 1 ;
V_1 = F_74 ( V_15 , V_101 , V_16 , false ) ;
if ( V_1 ) {
F_239 ( V_15 ) ;
goto V_103;
}
V_104 = true ;
}
F_240 ( V_15 ) ;
V_1 = F_229 ( V_15 , V_16 , V_104 ) ;
V_101 = F_31 ( V_15 ) ;
V_103:
if ( V_1 )
F_241 ( & V_101 -> V_105 [ V_101 -> V_98 ] ) ;
return V_1 ;
}
static void * F_83 ( struct V_14 * V_15 , T_4 V_16 )
{
int V_278 , V_279 ;
if ( F_242 () || ( V_16 & V_280 ) )
return NULL ;
V_278 = V_279 = F_66 () ;
if ( F_243 () && ( V_15 -> V_16 & V_281 ) )
V_278 = F_244 () ;
else if ( V_209 -> V_282 )
V_278 = F_245 () ;
if ( V_278 != V_279 )
return F_84 ( V_15 , V_16 , V_278 ) ;
return NULL ;
}
static void * F_246 ( struct V_14 * V_32 , T_4 V_16 )
{
struct V_283 * V_283 ;
T_4 V_256 ;
struct V_284 * V_285 ;
struct V_286 * V_286 ;
enum V_287 V_288 = F_247 ( V_16 ) ;
void * V_31 = NULL ;
int V_149 ;
unsigned int V_289 ;
if ( V_16 & V_280 )
return NULL ;
V_256 = V_16 & ( V_259 | V_260 ) ;
V_290:
V_289 = F_248 () ;
V_283 = F_249 ( F_245 () , V_16 ) ;
V_268:
F_250 (zone, z, zonelist, high_zoneidx) {
V_149 = F_251 ( V_286 ) ;
if ( F_252 ( V_286 , V_16 ) &&
V_32 -> V_44 [ V_149 ] &&
V_32 -> V_44 [ V_149 ] -> V_12 ) {
V_31 = F_84 ( V_32 ,
V_16 | V_274 , V_149 ) ;
if ( V_31 )
break;
}
}
if ( ! V_31 ) {
struct V_22 * V_22 ;
if ( V_256 & V_261 )
F_221 () ;
F_215 ( V_32 , V_16 ) ;
V_22 = F_143 ( V_32 , V_256 , F_66 () ) ;
if ( V_256 & V_261 )
F_222 () ;
if ( V_22 ) {
V_149 = F_96 ( V_22 ) ;
if ( F_220 ( V_32 , V_16 , V_149 , V_22 ) ) {
V_31 = F_84 ( V_32 ,
V_16 | V_274 , V_149 ) ;
if ( ! V_31 )
goto V_268;
} else {
V_31 = NULL ;
}
}
}
if ( F_53 ( ! V_31 && F_253 ( V_289 ) ) )
goto V_290;
return V_31 ;
}
static void * F_84 ( struct V_14 * V_15 , T_4 V_16 ,
int V_111 )
{
struct V_252 * V_105 ;
struct V_22 * V_22 ;
struct V_3 * V_42 ;
void * V_31 ;
int V_273 ;
F_29 ( V_111 > F_254 () ) ;
V_42 = V_15 -> V_44 [ V_111 ] ;
F_9 ( ! V_42 ) ;
V_268:
F_195 () ;
F_89 ( & V_42 -> V_11 ) ;
V_105 = V_42 -> V_6 . V_271 ;
if ( V_105 == & V_42 -> V_6 ) {
V_42 -> V_13 = 1 ;
V_105 = V_42 -> V_7 . V_271 ;
if ( V_105 == & V_42 -> V_7 )
goto V_272;
}
V_22 = F_206 ( V_105 , struct V_22 , V_163 ) ;
F_201 ( V_15 , V_111 ) ;
F_255 ( V_15 ) ;
F_231 ( V_15 ) ;
F_232 ( V_15 ) ;
F_9 ( V_22 -> V_195 == V_15 -> V_28 ) ;
V_31 = F_216 ( V_15 , V_22 , V_111 ) ;
V_42 -> V_12 -- ;
F_207 ( & V_22 -> V_163 ) ;
if ( V_22 -> V_195 == V_15 -> V_28 )
F_128 ( & V_22 -> V_163 , & V_42 -> V_5 ) ;
else
F_128 ( & V_22 -> V_163 , & V_42 -> V_6 ) ;
F_91 ( & V_42 -> V_11 ) ;
goto V_291;
V_272:
F_91 ( & V_42 -> V_11 ) ;
V_273 = F_220 ( V_15 , V_16 | V_274 , V_111 , NULL ) ;
if ( V_273 )
goto V_268;
return F_246 ( V_15 , V_16 ) ;
V_291:
return V_31 ;
}
static T_8 void *
F_256 ( struct V_14 * V_15 , T_4 V_16 , int V_111 ,
unsigned long V_214 )
{
unsigned long V_292 ;
void * V_158 ;
int V_293 = F_66 () ;
V_16 &= V_294 ;
F_257 ( V_16 ) ;
if ( F_236 ( V_15 , V_16 ) )
return NULL ;
V_15 = F_258 ( V_15 , V_16 ) ;
F_233 ( V_15 , V_16 ) ;
F_259 ( V_292 ) ;
if ( V_111 == V_295 )
V_111 = V_293 ;
if ( F_53 ( ! V_15 -> V_44 [ V_111 ] ) ) {
V_158 = F_246 ( V_15 , V_16 ) ;
goto V_103;
}
if ( V_111 == V_293 ) {
V_158 = F_238 ( V_15 , V_16 ) ;
if ( V_158 )
goto V_103;
}
V_158 = F_84 ( V_15 , V_16 , V_111 ) ;
V_103:
F_260 ( V_292 ) ;
V_158 = F_235 ( V_15 , V_16 , V_158 , V_214 ) ;
F_261 ( V_158 , V_15 -> V_215 , 1 , V_15 -> V_16 ,
V_16 ) ;
if ( F_98 ( V_158 ) ) {
F_262 ( V_15 , V_16 , V_158 , V_15 -> V_215 ) ;
if ( F_53 ( V_16 & V_296 ) )
memset ( V_158 , 0 , V_15 -> V_215 ) ;
}
return V_158 ;
}
static T_8 void *
F_263 ( struct V_14 * V_32 , T_4 V_16 )
{
void * V_1 ;
if ( V_209 -> V_282 || F_53 ( V_209 -> V_16 & V_297 ) ) {
V_1 = F_83 ( V_32 , V_16 ) ;
if ( V_1 )
goto V_103;
}
V_1 = F_238 ( V_32 , V_16 ) ;
if ( ! V_1 )
V_1 = F_84 ( V_32 , V_16 , F_66 () ) ;
V_103:
return V_1 ;
}
static T_8 void *
F_263 ( struct V_14 * V_15 , T_4 V_16 )
{
return F_238 ( V_15 , V_16 ) ;
}
static T_8 void *
F_264 ( struct V_14 * V_15 , T_4 V_16 , unsigned long V_214 )
{
unsigned long V_292 ;
void * V_1 ;
V_16 &= V_294 ;
F_257 ( V_16 ) ;
if ( F_236 ( V_15 , V_16 ) )
return NULL ;
V_15 = F_258 ( V_15 , V_16 ) ;
F_233 ( V_15 , V_16 ) ;
F_259 ( V_292 ) ;
V_1 = F_263 ( V_15 , V_16 ) ;
F_260 ( V_292 ) ;
V_1 = F_235 ( V_15 , V_16 , V_1 , V_214 ) ;
F_261 ( V_1 , V_15 -> V_215 , 1 , V_15 -> V_16 ,
V_16 ) ;
F_265 ( V_1 ) ;
if ( F_98 ( V_1 ) ) {
F_262 ( V_15 , V_16 , V_1 , V_15 -> V_215 ) ;
if ( F_53 ( V_16 & V_296 ) )
memset ( V_1 , 0 , V_15 -> V_215 ) ;
}
return V_1 ;
}
static void F_90 ( struct V_14 * V_15 , void * * V_298 , int V_299 ,
int V_44 )
{
int V_49 ;
struct V_3 * V_42 ;
for ( V_49 = 0 ; V_49 < V_299 ; V_49 ++ ) {
void * V_1 ;
struct V_22 * V_22 ;
F_3 ( & V_298 [ V_49 ] ) ;
V_1 = V_298 [ V_49 ] ;
V_22 = F_15 ( V_1 ) ;
V_42 = V_15 -> V_44 [ V_44 ] ;
F_207 ( & V_22 -> V_163 ) ;
F_201 ( V_15 , V_44 ) ;
F_218 ( V_15 , V_22 , V_1 , V_44 ) ;
F_266 ( V_15 ) ;
V_42 -> V_12 ++ ;
if ( V_22 -> V_195 == 0 ) {
if ( V_42 -> V_12 > V_42 -> V_118 ) {
V_42 -> V_12 -= V_15 -> V_28 ;
F_178 ( V_15 , V_22 ) ;
} else {
F_128 ( & V_22 -> V_163 , & V_42 -> V_7 ) ;
}
} else {
F_223 ( & V_22 -> V_163 , & V_42 -> V_6 ) ;
}
}
}
static void F_267 ( struct V_14 * V_15 , struct V_40 * V_101 )
{
int V_94 ;
struct V_3 * V_42 ;
int V_44 = F_66 () ;
V_94 = V_101 -> V_94 ;
#if V_185
F_9 ( ! V_94 || V_94 > V_101 -> V_98 ) ;
#endif
F_195 () ;
V_42 = V_15 -> V_44 [ V_44 ] ;
F_89 ( & V_42 -> V_11 ) ;
if ( V_42 -> V_8 ) {
struct V_40 * V_300 = V_42 -> V_8 ;
int V_108 = V_300 -> V_99 - V_300 -> V_98 ;
if ( V_108 ) {
if ( V_94 > V_108 )
V_94 = V_108 ;
memcpy ( & ( V_300 -> V_105 [ V_300 -> V_98 ] ) ,
V_101 -> V_105 , sizeof( void * ) * V_94 ) ;
V_300 -> V_98 += V_94 ;
goto V_301;
}
}
F_90 ( V_15 , V_101 -> V_105 , V_94 , V_44 ) ;
V_301:
#if V_302
{
int V_49 = 0 ;
struct V_252 * V_253 ;
V_253 = V_42 -> V_7 . V_271 ;
while ( V_253 != & ( V_42 -> V_7 ) ) {
struct V_22 * V_22 ;
V_22 = F_206 ( V_253 , struct V_22 , V_163 ) ;
F_9 ( V_22 -> V_195 ) ;
V_49 ++ ;
V_253 = V_253 -> V_271 ;
}
F_268 ( V_15 , V_49 ) ;
}
#endif
F_91 ( & V_42 -> V_11 ) ;
V_101 -> V_98 -= V_94 ;
memmove ( V_101 -> V_105 , & ( V_101 -> V_105 [ V_94 ] ) , sizeof( void * ) * V_101 -> V_98 ) ;
}
static inline void F_269 ( struct V_14 * V_15 , void * V_1 ,
unsigned long V_214 )
{
struct V_40 * V_101 = F_31 ( V_15 ) ;
F_195 () ;
F_270 ( V_1 , V_15 -> V_16 ) ;
V_1 = F_228 ( V_15 , V_1 , V_214 ) ;
F_271 ( V_15 , V_1 , V_15 -> V_215 ) ;
if ( V_303 > 1 && F_82 ( V_15 , V_1 ) )
return;
if ( F_98 ( V_101 -> V_98 < V_101 -> V_99 ) ) {
F_272 ( V_15 ) ;
} else {
F_273 ( V_15 ) ;
F_267 ( V_15 , V_101 ) ;
}
F_77 ( V_15 , V_101 , V_1 ) ;
}
void * F_274 ( struct V_14 * V_15 , T_4 V_16 )
{
void * V_143 = F_264 ( V_15 , V_16 , V_304 ) ;
F_275 ( V_304 , V_143 ,
V_15 -> V_215 , V_15 -> V_19 , V_16 ) ;
return V_143 ;
}
void *
F_276 ( struct V_14 * V_15 , T_4 V_16 , T_2 V_19 )
{
void * V_143 ;
V_143 = F_264 ( V_15 , V_16 , V_304 ) ;
F_277 ( V_304 , V_143 ,
V_19 , V_15 -> V_19 , V_16 ) ;
return V_143 ;
}
void * F_211 ( struct V_14 * V_15 , T_4 V_16 , int V_111 )
{
void * V_143 = F_256 ( V_15 , V_16 , V_111 , V_304 ) ;
F_278 ( V_304 , V_143 ,
V_15 -> V_215 , V_15 -> V_19 ,
V_16 , V_111 ) ;
return V_143 ;
}
void * F_279 ( struct V_14 * V_15 ,
T_4 V_16 ,
int V_111 ,
T_2 V_19 )
{
void * V_143 ;
V_143 = F_256 ( V_15 , V_16 , V_111 , V_304 ) ;
F_280 ( V_304 , V_143 ,
V_19 , V_15 -> V_19 ,
V_16 , V_111 ) ;
return V_143 ;
}
static T_8 void *
F_281 ( T_2 V_19 , T_4 V_16 , int V_44 , unsigned long V_214 )
{
struct V_14 * V_15 ;
V_15 = F_191 ( V_19 , V_16 ) ;
if ( F_53 ( F_192 ( V_15 ) ) )
return V_15 ;
return F_279 ( V_15 , V_16 , V_44 , V_19 ) ;
}
void * F_282 ( T_2 V_19 , T_4 V_16 , int V_44 )
{
return F_281 ( V_19 , V_16 , V_44 , V_304 ) ;
}
void * F_283 ( T_2 V_19 , T_4 V_16 ,
int V_44 , unsigned long V_214 )
{
return F_281 ( V_19 , V_16 , V_44 , V_214 ) ;
}
void * F_282 ( T_2 V_19 , T_4 V_16 , int V_44 )
{
return F_281 ( V_19 , V_16 , V_44 , 0 ) ;
}
static T_8 void * F_284 ( T_2 V_19 , T_4 V_16 ,
unsigned long V_214 )
{
struct V_14 * V_15 ;
void * V_143 ;
V_15 = F_191 ( V_19 , V_16 ) ;
if ( F_53 ( F_192 ( V_15 ) ) )
return V_15 ;
V_143 = F_264 ( V_15 , V_16 , V_214 ) ;
F_277 ( V_214 , V_143 ,
V_19 , V_15 -> V_19 , V_16 ) ;
return V_143 ;
}
void * F_285 ( T_2 V_19 , T_4 V_16 )
{
return F_284 ( V_19 , V_16 , V_304 ) ;
}
void * F_286 ( T_2 V_19 , T_4 V_16 , unsigned long V_214 )
{
return F_284 ( V_19 , V_16 , V_214 ) ;
}
void * F_285 ( T_2 V_19 , T_4 V_16 )
{
return F_284 ( V_19 , V_16 , 0 ) ;
}
void F_180 ( struct V_14 * V_15 , void * V_1 )
{
unsigned long V_16 ;
V_15 = F_287 ( V_15 , V_1 ) ;
if ( ! V_15 )
return;
F_259 ( V_16 ) ;
F_288 ( V_1 , V_15 -> V_215 ) ;
if ( ! ( V_15 -> V_16 & V_124 ) )
F_289 ( V_1 , V_15 -> V_215 ) ;
F_269 ( V_15 , V_1 , V_304 ) ;
F_260 ( V_16 ) ;
F_290 ( V_304 , V_1 ) ;
}
void F_87 ( const void * V_1 )
{
struct V_14 * V_305 ;
unsigned long V_16 ;
F_291 ( V_304 , V_1 ) ;
if ( F_53 ( F_192 ( V_1 ) ) )
return;
F_259 ( V_16 ) ;
F_225 ( V_1 ) ;
V_305 = F_14 ( V_1 ) ;
F_288 ( V_1 , V_305 -> V_215 ) ;
F_289 ( V_1 , V_305 -> V_215 ) ;
F_269 ( V_305 , ( void * ) V_1 , V_304 ) ;
F_260 ( V_16 ) ;
}
static int F_292 ( struct V_14 * V_15 , T_4 V_95 )
{
int V_44 ;
struct V_3 * V_42 ;
struct V_40 * V_306 ;
struct V_40 * * V_307 = NULL ;
F_24 (node) {
if ( V_77 ) {
V_307 = F_80 ( V_44 , V_15 -> V_99 , V_95 ) ;
if ( ! V_307 )
goto V_308;
}
V_306 = NULL ;
if ( V_15 -> V_8 ) {
V_306 = F_60 ( V_44 ,
V_15 -> V_8 * V_15 -> V_94 ,
0xbaadf00d , V_95 ) ;
if ( ! V_306 ) {
F_81 ( V_307 ) ;
goto V_308;
}
}
V_42 = V_15 -> V_44 [ V_44 ] ;
if ( V_42 ) {
struct V_40 * V_8 = V_42 -> V_8 ;
F_102 ( & V_42 -> V_11 ) ;
if ( V_8 )
F_90 ( V_15 , V_8 -> V_105 ,
V_8 -> V_98 , V_44 ) ;
V_42 -> V_8 = V_306 ;
if ( ! V_42 -> V_9 ) {
V_42 -> V_9 = V_307 ;
V_307 = NULL ;
}
V_42 -> V_118 = ( 1 + F_103 ( V_44 ) ) *
V_15 -> V_94 + V_15 -> V_28 ;
F_94 ( & V_42 -> V_11 ) ;
F_87 ( V_8 ) ;
F_81 ( V_307 ) ;
continue;
}
V_42 = F_61 ( sizeof( struct V_3 ) , V_95 , V_44 ) ;
if ( ! V_42 ) {
F_81 ( V_307 ) ;
F_87 ( V_306 ) ;
goto V_308;
}
F_4 ( V_42 ) ;
V_42 -> V_115 = V_116 + V_117 +
( ( unsigned long ) V_15 ) % V_117 ;
V_42 -> V_8 = V_306 ;
V_42 -> V_9 = V_307 ;
V_42 -> V_118 = ( 1 + F_103 ( V_44 ) ) *
V_15 -> V_94 + V_15 -> V_28 ;
V_15 -> V_44 [ V_44 ] = V_42 ;
}
return 0 ;
V_308:
if ( ! V_15 -> V_157 . V_271 ) {
V_44 -- ;
while ( V_44 >= 0 ) {
if ( V_15 -> V_44 [ V_44 ] ) {
V_42 = V_15 -> V_44 [ V_44 ] ;
F_87 ( V_42 -> V_8 ) ;
F_81 ( V_42 -> V_9 ) ;
F_87 ( V_42 ) ;
V_15 -> V_44 [ V_44 ] = NULL ;
}
V_44 -- ;
}
}
return - V_114 ;
}
static void F_293 ( void * V_309 )
{
struct V_310 * V_311 = V_309 ;
struct V_40 * V_312 ;
F_195 () ;
V_312 = F_31 ( V_311 -> V_15 ) ;
V_311 -> V_15 -> V_56 [ F_32 () ] = V_311 -> V_311 [ F_32 () ] ;
V_311 -> V_311 [ F_32 () ] = V_312 ;
}
static int F_294 ( struct V_14 * V_15 , int V_99 ,
int V_94 , int V_8 , T_4 V_95 )
{
struct V_310 * V_311 ;
int V_49 ;
V_311 = F_295 ( sizeof( * V_311 ) + V_162 * sizeof( struct V_40 * ) ,
V_95 ) ;
if ( ! V_311 )
return - V_114 ;
F_139 (i) {
V_311 -> V_311 [ V_49 ] = F_60 ( F_48 ( V_49 ) , V_99 ,
V_94 , V_95 ) ;
if ( ! V_311 -> V_311 [ V_49 ] ) {
for ( V_49 -- ; V_49 >= 0 ; V_49 -- )
F_87 ( V_311 -> V_311 [ V_49 ] ) ;
F_87 ( V_311 ) ;
return - V_114 ;
}
}
V_311 -> V_15 = V_15 ;
F_204 ( F_293 , ( void * ) V_311 , 1 ) ;
F_197 () ;
V_15 -> V_94 = V_94 ;
V_15 -> V_99 = V_99 ;
V_15 -> V_8 = V_8 ;
F_139 (i) {
struct V_40 * V_313 = V_311 -> V_311 [ V_49 ] ;
if ( ! V_313 )
continue;
F_102 ( & V_15 -> V_44 [ F_48 ( V_49 ) ] -> V_11 ) ;
F_90 ( V_15 , V_313 -> V_105 , V_313 -> V_98 , F_48 ( V_49 ) ) ;
F_94 ( & V_15 -> V_44 [ F_48 ( V_49 ) ] -> V_11 ) ;
F_87 ( V_313 ) ;
}
F_87 ( V_311 ) ;
return F_292 ( V_15 , V_95 ) ;
}
static int F_296 ( struct V_14 * V_15 , int V_99 ,
int V_94 , int V_8 , T_4 V_95 )
{
int V_143 ;
struct V_14 * V_305 = NULL ;
int V_49 = 0 ;
V_143 = F_294 ( V_15 , V_99 , V_94 , V_8 , V_95 ) ;
if ( V_50 < V_181 )
return V_143 ;
if ( ( V_143 < 0 ) || ! F_297 ( V_15 ) )
return V_143 ;
F_29 ( ! F_298 ( & V_132 ) ) ;
F_299 (i) {
V_305 = F_300 ( V_15 , V_49 ) ;
if ( V_305 )
F_294 ( V_305 , V_99 , V_94 , V_8 , V_95 ) ;
}
return V_143 ;
}
static int F_134 ( struct V_14 * V_15 , T_4 V_95 )
{
int V_122 ;
int V_99 = 0 ;
int V_8 = 0 ;
int V_94 = 0 ;
if ( ! F_297 ( V_15 ) ) {
struct V_14 * V_314 = F_301 ( V_15 ) ;
V_99 = V_314 -> V_99 ;
V_8 = V_314 -> V_8 ;
V_94 = V_314 -> V_94 ;
}
if ( V_99 && V_8 && V_94 )
goto V_315;
if ( V_15 -> V_19 > 131072 )
V_99 = 1 ;
else if ( V_15 -> V_19 > V_68 )
V_99 = 8 ;
else if ( V_15 -> V_19 > 1024 )
V_99 = 24 ;
else if ( V_15 -> V_19 > 256 )
V_99 = 54 ;
else
V_99 = 120 ;
V_8 = 0 ;
if ( V_15 -> V_19 <= V_68 && F_302 () > 1 )
V_8 = 8 ;
#if V_185
if ( V_99 > 32 )
V_99 = 32 ;
#endif
V_94 = ( V_99 + 1 ) / 2 ;
V_315:
V_122 = F_296 ( V_15 , V_99 , V_94 , V_8 , V_95 ) ;
if ( V_122 )
F_39 ( V_72 L_36 ,
V_15 -> V_73 , - V_122 ) ;
return V_122 ;
}
static void F_205 ( struct V_14 * V_15 , struct V_3 * V_42 ,
struct V_40 * V_101 , int V_316 , int V_44 )
{
int V_251 ;
if ( ! V_101 || ! V_101 -> V_98 )
return;
if ( V_101 -> V_100 && ! V_316 ) {
V_101 -> V_100 = 0 ;
} else {
F_102 ( & V_42 -> V_11 ) ;
if ( V_101 -> V_98 ) {
V_251 = V_316 ? V_101 -> V_98 : ( V_101 -> V_99 + 4 ) / 5 ;
if ( V_251 > V_101 -> V_98 )
V_251 = ( V_101 -> V_98 + 1 ) / 2 ;
F_90 ( V_15 , V_101 -> V_105 , V_251 , V_44 ) ;
V_101 -> V_98 -= V_251 ;
memmove ( V_101 -> V_105 , & ( V_101 -> V_105 [ V_251 ] ) ,
sizeof( void * ) * V_101 -> V_98 ) ;
}
F_94 ( & V_42 -> V_11 ) ;
}
}
static void V_91 ( struct V_317 * V_318 )
{
struct V_14 * V_319 ;
struct V_3 * V_42 ;
int V_44 = F_66 () ;
struct V_86 * V_89 = F_303 ( V_318 ) ;
if ( ! F_304 ( & V_132 ) )
goto V_103;
F_68 (searchp, &slab_caches, list) {
F_197 () ;
V_42 = V_319 -> V_44 [ V_44 ] ;
F_92 ( V_319 , V_42 ) ;
F_205 ( V_319 , V_42 , F_31 ( V_319 ) , 0 , V_44 ) ;
if ( F_305 ( V_42 -> V_115 , V_116 ) )
goto V_271;
V_42 -> V_115 = V_116 + V_117 ;
F_205 ( V_319 , V_42 , V_42 -> V_8 , 0 , V_44 ) ;
if ( V_42 -> V_13 )
V_42 -> V_13 = 0 ;
else {
int V_320 ;
V_320 = F_108 ( V_319 , V_42 , ( V_42 -> V_118 +
5 * V_319 -> V_28 - 1 ) / ( 5 * V_319 -> V_28 ) ) ;
F_306 ( V_319 , V_320 ) ;
}
V_271:
F_307 () ;
}
F_197 () ;
F_113 ( & V_132 ) ;
F_51 () ;
V_103:
F_308 ( V_89 , F_309 ( V_321 ) ) ;
}
void F_310 ( struct V_14 * V_15 , struct V_322 * V_323 )
{
struct V_22 * V_22 ;
unsigned long V_191 ;
unsigned long V_192 ;
unsigned long V_193 = 0 ;
unsigned long V_194 , V_12 = 0 , V_324 = 0 ;
const char * V_73 ;
char * error = NULL ;
int V_44 ;
struct V_3 * V_42 ;
V_191 = 0 ;
V_194 = 0 ;
F_24 (node) {
V_42 = V_15 -> V_44 [ V_44 ] ;
if ( ! V_42 )
continue;
F_197 () ;
F_102 ( & V_42 -> V_11 ) ;
F_68 (page, &n->slabs_full, lru) {
if ( V_22 -> V_195 != V_15 -> V_28 && ! error )
error = L_37 ;
V_191 += V_15 -> V_28 ;
V_193 ++ ;
}
F_68 (page, &n->slabs_partial, lru) {
if ( V_22 -> V_195 == V_15 -> V_28 && ! error )
error = L_38 ;
if ( ! V_22 -> V_195 && ! error )
error = L_38 ;
V_191 += V_22 -> V_195 ;
V_193 ++ ;
}
F_68 (page, &n->slabs_free, lru) {
if ( V_22 -> V_195 && ! error )
error = L_39 ;
V_194 ++ ;
}
V_12 += V_42 -> V_12 ;
if ( V_42 -> V_8 )
V_324 += V_42 -> V_8 -> V_98 ;
F_94 ( & V_42 -> V_11 ) ;
}
V_194 += V_193 ;
V_192 = V_194 * V_15 -> V_28 ;
if ( V_192 - V_191 != V_12 && ! error )
error = L_40 ;
V_73 = V_15 -> V_73 ;
if ( error )
F_39 ( V_72 L_41 , V_73 , error ) ;
V_323 -> V_191 = V_191 ;
V_323 -> V_192 = V_192 ;
V_323 -> V_193 = V_193 ;
V_323 -> V_194 = V_194 ;
V_323 -> V_324 = V_324 ;
V_323 -> V_99 = V_15 -> V_99 ;
V_323 -> V_94 = V_15 -> V_94 ;
V_323 -> V_8 = V_15 -> V_8 ;
V_323 -> V_325 = V_15 -> V_28 ;
V_323 -> V_326 = V_15 -> V_65 ;
}
void F_311 ( struct V_327 * V_328 , struct V_14 * V_15 )
{
#if V_302
{
unsigned long V_329 = V_15 -> V_330 ;
unsigned long V_331 = V_15 -> V_332 ;
unsigned long V_333 = V_15 -> V_333 ;
unsigned long V_334 = V_15 -> V_334 ;
unsigned long V_335 = V_15 -> V_335 ;
unsigned long V_336 = V_15 -> V_336 ;
unsigned long V_337 = V_15 -> V_337 ;
unsigned long V_338 = V_15 -> V_338 ;
unsigned long V_339 = V_15 -> V_340 ;
F_312 ( V_328 , L_42
L_43 ,
V_331 , V_329 , V_333 ,
V_334 , V_335 , V_336 , V_337 ,
V_338 , V_339 ) ;
}
{
unsigned long V_341 = F_313 ( & V_15 -> V_341 ) ;
unsigned long V_342 = F_313 ( & V_15 -> V_342 ) ;
unsigned long V_343 = F_313 ( & V_15 -> V_343 ) ;
unsigned long V_344 = F_313 ( & V_15 -> V_344 ) ;
F_312 ( V_328 , L_44 ,
V_341 , V_342 , V_343 , V_344 ) ;
}
#endif
}
T_9 F_314 ( struct V_345 * V_345 , const char T_10 * V_346 ,
T_2 V_347 , T_11 * V_348 )
{
char V_349 [ V_350 + 1 ] , * V_351 ;
int V_99 , V_94 , V_8 , V_352 ;
struct V_14 * V_15 ;
if ( V_347 > V_350 )
return - V_353 ;
if ( F_315 ( & V_349 , V_346 , V_347 ) )
return - V_354 ;
V_349 [ V_350 ] = '\0' ;
V_351 = strchr ( V_349 , ' ' ) ;
if ( ! V_351 )
return - V_353 ;
* V_351 = '\0' ;
V_351 ++ ;
if ( sscanf ( V_351 , L_45 , & V_99 , & V_94 , & V_8 ) != 3 )
return - V_353 ;
F_112 ( & V_132 ) ;
V_352 = - V_353 ;
F_68 (cachep, &slab_caches, list) {
if ( ! strcmp ( V_15 -> V_73 , V_349 ) ) {
if ( V_99 < 1 || V_94 < 1 ||
V_94 > V_99 || V_8 < 0 ) {
V_352 = 0 ;
} else {
V_352 = F_296 ( V_15 , V_99 ,
V_94 , V_8 ,
V_113 ) ;
}
break;
}
}
F_113 ( & V_132 ) ;
if ( V_352 >= 0 )
V_352 = V_347 ;
return V_352 ;
}
static void * F_316 ( struct V_327 * V_328 , T_11 * V_355 )
{
F_112 ( & V_132 ) ;
return F_317 ( & V_172 , * V_355 ) ;
}
static inline int F_318 ( unsigned long * V_42 , unsigned long V_356 )
{
unsigned long * V_253 ;
int V_357 ;
if ( ! V_356 )
return 1 ;
V_357 = V_42 [ 1 ] ;
V_253 = V_42 + 2 ;
while ( V_357 ) {
int V_49 = V_357 / 2 ;
unsigned long * V_39 = V_253 + 2 * V_49 ;
if ( * V_39 == V_356 ) {
V_39 [ 1 ] ++ ;
return 1 ;
}
if ( * V_39 > V_356 ) {
V_357 = V_49 ;
} else {
V_253 = V_39 + 2 ;
V_357 -= V_49 + 1 ;
}
}
if ( ++ V_42 [ 1 ] == V_42 [ 0 ] )
return 0 ;
memmove ( V_253 + 2 , V_253 , V_42 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_253 - ( void * ) V_42 ) ) ;
V_253 [ 0 ] = V_356 ;
V_253 [ 1 ] = 1 ;
return 1 ;
}
static void F_319 ( unsigned long * V_42 , struct V_14 * V_305 ,
struct V_22 * V_22 )
{
void * V_253 ;
int V_49 ;
if ( V_42 [ 0 ] == V_42 [ 1 ] )
return;
for ( V_49 = 0 , V_253 = V_22 -> V_33 ; V_49 < V_305 -> V_28 ; V_49 ++ , V_253 += V_305 -> V_19 ) {
if ( F_13 ( V_22 , V_49 ) != V_276 )
continue;
if ( ! F_318 ( V_42 , ( unsigned long ) * F_11 ( V_305 , V_253 ) ) )
return;
}
}
static void F_320 ( struct V_327 * V_328 , unsigned long V_358 )
{
#ifdef F_321
unsigned long V_34 , V_19 ;
char V_359 [ V_360 ] , V_73 [ V_361 ] ;
if ( F_322 ( V_358 , & V_19 , & V_34 , V_359 , V_73 ) == 0 ) {
F_312 ( V_328 , L_46 , V_73 , V_34 , V_19 ) ;
if ( V_359 [ 0 ] )
F_312 ( V_328 , L_47 , V_359 ) ;
return;
}
#endif
F_312 ( V_328 , L_48 , ( void * ) V_358 ) ;
}
static int F_323 ( struct V_327 * V_328 , void * V_253 )
{
struct V_14 * V_15 = F_206 ( V_253 , struct V_14 , V_157 ) ;
struct V_22 * V_22 ;
struct V_3 * V_42 ;
const char * V_73 ;
unsigned long * V_273 = V_328 -> V_362 ;
int V_44 ;
int V_49 ;
if ( ! ( V_15 -> V_16 & V_18 ) )
return 0 ;
if ( ! ( V_15 -> V_16 & V_17 ) )
return 0 ;
V_273 [ 1 ] = 0 ;
F_24 (node) {
V_42 = V_15 -> V_44 [ V_44 ] ;
if ( ! V_42 )
continue;
F_197 () ;
F_102 ( & V_42 -> V_11 ) ;
F_68 (page, &n->slabs_full, lru)
F_319 ( V_273 , V_15 , V_22 ) ;
F_68 (page, &n->slabs_partial, lru)
F_319 ( V_273 , V_15 , V_22 ) ;
F_94 ( & V_42 -> V_11 ) ;
}
V_73 = V_15 -> V_73 ;
if ( V_273 [ 0 ] == V_273 [ 1 ] ) {
F_113 ( & V_132 ) ;
V_328 -> V_362 = F_295 ( V_273 [ 0 ] * 4 * sizeof( unsigned long ) , V_113 ) ;
if ( ! V_328 -> V_362 ) {
V_328 -> V_362 = V_273 ;
F_112 ( & V_132 ) ;
return - V_114 ;
}
* ( unsigned long * ) V_328 -> V_362 = V_273 [ 0 ] * 2 ;
F_87 ( V_273 ) ;
F_112 ( & V_132 ) ;
V_328 -> V_347 = V_328 -> V_19 ;
return 0 ;
}
for ( V_49 = 0 ; V_49 < V_273 [ 1 ] ; V_49 ++ ) {
F_312 ( V_328 , L_49 , V_73 , V_273 [ 2 * V_49 + 3 ] ) ;
F_320 ( V_328 , V_273 [ 2 * V_49 + 2 ] ) ;
F_324 ( V_328 , '\n' ) ;
}
return 0 ;
}
static int F_325 ( struct V_363 * V_363 , struct V_345 * V_345 )
{
unsigned long * V_42 = F_295 ( V_68 , V_113 ) ;
int V_143 = - V_114 ;
if ( V_42 ) {
V_143 = F_326 ( V_345 , & V_364 ) ;
if ( ! V_143 ) {
struct V_327 * V_328 = V_345 -> V_365 ;
* V_42 = V_68 / ( 2 * sizeof( unsigned long ) ) ;
V_328 -> V_362 = V_42 ;
V_42 = NULL ;
}
F_87 ( V_42 ) ;
}
return V_143 ;
}
static int T_3 F_327 ( void )
{
#ifdef V_59
F_328 ( L_50 , 0 , NULL , & V_366 ) ;
#endif
return 0 ;
}
T_2 F_329 ( const void * V_1 )
{
F_9 ( ! V_1 ) ;
if ( F_53 ( V_1 == V_367 ) )
return 0 ;
return F_14 ( V_1 ) -> V_215 ;
}
