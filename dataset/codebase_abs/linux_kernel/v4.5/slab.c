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
F_128 () ;
V_170 = 0 ;
{
int V_143 ;
F_91 (nid) {
F_117 ( V_14 , & V_154 [ V_171 + V_143 ] , V_143 ) ;
F_117 ( V_166 [ V_167 ] ,
& V_154 [ V_172 + V_143 ] , V_143 ) ;
}
}
F_129 ( V_168 ) ;
}
void T_3 F_130 ( void )
{
struct V_14 * V_15 ;
V_164 = V_173 ;
F_110 ( & V_126 ) ;
F_58 (cachep, &slab_caches, list)
if ( F_131 ( V_15 , V_152 ) )
F_132 () ;
F_111 ( & V_126 ) ;
V_164 = V_174 ;
F_133 ( & V_175 ) ;
#ifdef F_108
F_134 ( F_116 , V_176 ) ;
#endif
}
static int T_3 F_135 ( void )
{
int V_63 ;
F_136 (cpu)
F_43 ( V_63 ) ;
V_164 = V_174 ;
return 0 ;
}
static T_5 void
F_137 ( struct V_14 * V_15 , T_4 V_177 , int V_97 )
{
#if V_178
struct V_3 * V_84 ;
struct V_22 * V_22 ;
unsigned long V_16 ;
int V_64 ;
static F_138 ( V_179 , V_180 ,
V_181 ) ;
if ( ( V_177 & V_106 ) || ! F_139 ( & V_179 ) )
return;
F_27 ( V_182
L_4 ,
V_97 , V_177 ) ;
F_27 ( V_182 L_5 ,
V_15 -> V_54 , V_15 -> V_19 , V_15 -> V_46 ) ;
F_140 (cachep, node, n) {
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
static struct V_22 * F_141 ( struct V_14 * V_15 , T_4 V_16 ,
int V_97 )
{
struct V_22 * V_22 ;
int V_188 ;
V_16 |= V_15 -> V_189 ;
if ( V_15 -> V_16 & V_190 )
V_16 |= V_191 ;
V_22 = F_142 ( V_97 , V_16 | V_192 , V_15 -> V_46 ) ;
if ( ! V_22 ) {
F_137 ( V_15 , V_16 , V_97 ) ;
return NULL ;
}
if ( F_143 ( V_22 , V_16 , V_15 -> V_46 , V_15 ) ) {
F_144 ( V_22 , V_15 -> V_46 ) ;
return NULL ;
}
if ( F_145 ( V_22 ) )
V_85 = true ;
V_188 = ( 1 << V_15 -> V_46 ) ;
if ( V_15 -> V_16 & V_190 )
F_146 ( F_147 ( V_22 ) ,
V_193 , V_188 ) ;
else
F_146 ( F_147 ( V_22 ) ,
V_194 , V_188 ) ;
F_148 ( V_22 ) ;
if ( F_145 ( V_22 ) )
F_149 ( V_22 ) ;
if ( V_195 && ! ( V_15 -> V_16 & V_196 ) ) {
F_150 ( V_22 , V_15 -> V_46 , V_16 , V_97 ) ;
if ( V_15 -> V_197 )
F_151 ( V_22 , V_188 ) ;
else
F_152 ( V_22 , V_188 ) ;
}
return V_22 ;
}
static void F_153 ( struct V_14 * V_15 , struct V_22 * V_22 )
{
const unsigned long V_198 = ( 1 << V_15 -> V_46 ) ;
F_154 ( V_22 , V_15 -> V_46 ) ;
if ( V_15 -> V_16 & V_190 )
F_155 ( F_147 ( V_22 ) ,
V_193 , V_198 ) ;
else
F_155 ( F_147 ( V_22 ) ,
V_194 , V_198 ) ;
F_9 ( ! F_156 ( V_22 ) ) ;
F_157 ( V_22 ) ;
F_158 ( V_22 ) ;
F_159 ( V_22 ) ;
V_22 -> V_199 = NULL ;
if ( V_200 -> V_201 )
V_200 -> V_201 -> V_202 += V_198 ;
F_160 ( V_22 , V_15 -> V_46 ) ;
}
static void F_161 ( struct V_156 * V_203 )
{
struct V_14 * V_15 ;
struct V_22 * V_22 ;
V_22 = F_162 ( V_203 , struct V_22 , V_156 ) ;
V_15 = V_22 -> V_27 ;
F_153 ( V_15 , V_22 ) ;
}
static void F_163 ( struct V_14 * V_15 , unsigned long * V_204 ,
unsigned long V_205 )
{
int V_19 = V_15 -> V_206 ;
V_204 = ( unsigned long * ) & ( ( char * ) V_204 ) [ F_7 ( V_15 ) ] ;
if ( V_19 < 5 * sizeof( unsigned long ) )
return;
* V_204 ++ = 0x12345678 ;
* V_204 ++ = V_205 ;
* V_204 ++ = F_164 () ;
V_19 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_207 = & V_205 ;
unsigned long V_208 ;
while ( ! F_165 ( V_207 ) ) {
V_208 = * V_207 ++ ;
if ( F_166 ( V_208 ) ) {
* V_204 ++ = V_208 ;
V_19 -= sizeof( unsigned long ) ;
if ( V_19 <= sizeof( unsigned long ) )
break;
}
}
}
* V_204 ++ = 0x87654321 ;
}
static void F_167 ( struct V_14 * V_15 , void * V_204 , unsigned char V_24 )
{
int V_19 = V_15 -> V_206 ;
V_204 = & ( ( char * ) V_204 ) [ F_7 ( V_15 ) ] ;
memset ( V_204 , V_24 , V_19 ) ;
* ( unsigned char * ) ( V_204 + V_19 - 1 ) = V_209 ;
}
static void F_168 ( char * V_210 , int V_34 , int V_76 )
{
int V_88 ;
unsigned char error = 0 ;
int V_211 = 0 ;
F_27 ( V_53 L_7 , V_34 ) ;
for ( V_88 = 0 ; V_88 < V_76 ; V_88 ++ ) {
if ( V_210 [ V_34 + V_88 ] != V_212 ) {
error = V_210 [ V_34 + V_88 ] ;
V_211 ++ ;
}
}
F_169 ( V_213 , L_8 , 0 , 16 , 1 ,
& V_210 [ V_34 ] , V_76 , 1 ) ;
if ( V_211 == 1 ) {
error ^= V_212 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_27 ( V_53 L_9
L_10 ) ;
#ifdef F_170
F_27 ( V_53 L_11
L_12 ) ;
#else
F_27 ( V_53 L_13 ) ;
#endif
}
}
}
static void F_171 ( struct V_14 * V_15 , void * V_1 , int V_214 )
{
int V_88 , V_19 ;
char * V_215 ;
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
V_215 = ( char * ) V_1 + F_7 ( V_15 ) ;
V_19 = V_15 -> V_206 ;
for ( V_88 = 0 ; V_88 < V_19 && V_214 ; V_88 += 16 , V_214 -- ) {
int V_76 ;
V_76 = 16 ;
if ( V_88 + V_76 > V_19 )
V_76 = V_19 - V_88 ;
F_168 ( V_215 , V_88 , V_76 ) ;
}
}
static void F_172 ( struct V_14 * V_15 , void * V_1 )
{
char * V_215 ;
int V_19 , V_88 ;
int V_214 = 0 ;
V_215 = ( char * ) V_1 + F_7 ( V_15 ) ;
V_19 = V_15 -> V_206 ;
for ( V_88 = 0 ; V_88 < V_19 ; V_88 ++ ) {
char exp = V_212 ;
if ( V_88 == V_19 - 1 )
exp = V_209 ;
if ( V_215 [ V_88 ] != exp ) {
int V_76 ;
if ( V_214 == 0 ) {
F_27 ( V_53
L_16 ,
F_173 () , V_15 -> V_54 , V_215 , V_19 ) ;
F_171 ( V_15 , V_1 , 0 ) ;
}
V_88 = ( V_88 / 16 ) * 16 ;
V_76 = 16 ;
if ( V_88 + V_76 > V_19 )
V_76 = V_19 - V_88 ;
F_168 ( V_215 , V_88 , V_76 ) ;
V_88 += 16 ;
V_214 ++ ;
if ( V_214 > 5 )
break;
}
}
if ( V_214 != 0 ) {
struct V_22 * V_22 = F_15 ( V_1 ) ;
unsigned int V_216 ;
V_216 = F_17 ( V_15 , V_22 , V_1 ) ;
if ( V_216 ) {
V_1 = F_16 ( V_15 , V_22 , V_216 - 1 ) ;
V_215 = ( char * ) V_1 + F_7 ( V_15 ) ;
F_27 ( V_53 L_17 ,
V_215 , V_19 ) ;
F_171 ( V_15 , V_1 , 2 ) ;
}
if ( V_216 + 1 < V_15 -> V_28 ) {
V_1 = F_16 ( V_15 , V_22 , V_216 + 1 ) ;
V_215 = ( char * ) V_1 + F_7 ( V_15 ) ;
F_27 ( V_53 L_18 ,
V_215 , V_19 ) ;
F_171 ( V_15 , V_1 , 2 ) ;
}
}
}
static void F_174 ( struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < V_15 -> V_28 ; V_88 ++ ) {
void * V_1 = F_16 ( V_15 , V_22 , V_88 ) ;
if ( V_15 -> V_16 & V_217 ) {
#ifdef F_175
if ( V_15 -> V_19 % V_49 == 0 &&
F_176 ( V_15 ) )
F_177 ( F_96 ( V_1 ) ,
V_15 -> V_19 / V_49 , 1 ) ;
else
F_172 ( V_15 , V_1 ) ;
#else
F_172 ( V_15 , V_1 ) ;
#endif
}
if ( V_15 -> V_16 & V_17 ) {
if ( * F_8 ( V_15 , V_1 ) != V_218 )
F_178 ( V_15 , L_19
L_20 ) ;
if ( * F_10 ( V_15 , V_1 ) != V_218 )
F_178 ( V_15 , L_21
L_20 ) ;
}
}
}
static void F_174 ( struct V_14 * V_15 ,
struct V_22 * V_22 )
{
}
static void F_179 ( struct V_14 * V_15 , struct V_22 * V_22 )
{
void * V_30 ;
V_30 = V_22 -> V_30 ;
F_174 ( V_15 , V_22 ) ;
if ( F_41 ( V_15 -> V_16 & V_219 ) )
F_180 ( & V_22 -> V_156 , F_161 ) ;
else
F_153 ( V_15 , V_22 ) ;
if ( F_176 ( V_15 ) )
F_181 ( V_15 -> V_220 , V_30 ) ;
}
static void F_89 ( struct V_14 * V_15 , struct V_102 * V_103 )
{
struct V_22 * V_22 , * V_84 ;
F_182 (page, n, list, lru) {
F_183 ( & V_22 -> V_155 ) ;
F_179 ( V_15 , V_22 ) ;
}
}
static T_2 F_184 ( struct V_14 * V_15 ,
T_2 V_19 , T_2 V_39 , unsigned long V_16 )
{
unsigned long V_221 ;
T_2 V_47 = 0 ;
int V_46 ;
for ( V_46 = 0 ; V_46 <= V_222 ; V_46 ++ ) {
unsigned int V_28 ;
T_2 V_223 ;
F_25 ( V_46 , V_19 , V_39 , V_16 , & V_223 , & V_28 ) ;
if ( ! V_28 )
continue;
if ( V_28 > V_224 )
break;
if ( V_16 & V_50 ) {
T_2 V_225 = sizeof( V_29 ) ;
if ( F_22 ( V_40 ) )
V_225 += sizeof( char ) ;
V_221 = V_19 ;
V_221 /= V_225 ;
if ( V_28 > V_221 )
break;
}
V_15 -> V_28 = V_28 ;
V_15 -> V_46 = V_46 ;
V_47 = V_223 ;
if ( V_16 & V_190 )
break;
if ( V_46 >= V_60 )
break;
if ( V_47 * 8 <= ( V_49 << V_46 ) )
break;
}
return V_47 ;
}
static struct V_36 T_7 * F_185 (
struct V_14 * V_15 , int V_81 , int V_79 )
{
int V_63 ;
T_2 V_19 ;
struct V_36 T_7 * V_37 ;
V_19 = sizeof( void * ) * V_81 + sizeof( struct V_36 ) ;
V_37 = F_186 ( V_19 , sizeof( void * ) ) ;
if ( ! V_37 )
return NULL ;
F_187 (cpu) {
F_48 ( F_104 ( V_37 , V_63 ) ,
V_81 , V_79 ) ;
}
return V_37 ;
}
static int T_8 F_188 ( struct V_14 * V_15 , T_4 V_82 )
{
if ( V_164 >= V_174 )
return F_131 ( V_15 , V_82 ) ;
V_15 -> V_37 = F_185 ( V_15 , 1 , 1 ) ;
if ( ! V_15 -> V_37 )
return 1 ;
if ( V_164 == V_226 ) {
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
F_19 ( V_15 ) -> V_76 = V_227 ;
F_19 ( V_15 ) -> V_79 = 1 ;
F_19 ( V_15 ) -> V_80 = 0 ;
V_15 -> V_79 = 1 ;
V_15 -> V_76 = V_227 ;
return 0 ;
}
unsigned long F_189 ( unsigned long V_206 ,
unsigned long V_16 , const char * V_54 ,
void (* V_197)( void * ) )
{
return V_16 ;
}
struct V_14 *
F_190 ( const char * V_54 , T_2 V_19 , T_2 V_39 ,
unsigned long V_16 , void (* V_197)( void * ) )
{
struct V_14 * V_15 ;
V_15 = F_191 ( V_19 , V_39 , V_16 , V_54 , V_197 ) ;
if ( V_15 ) {
V_15 -> V_228 ++ ;
V_15 -> V_206 = F_192 ( int , V_15 -> V_206 , V_19 ) ;
}
return V_15 ;
}
int
F_193 ( struct V_14 * V_15 , unsigned long V_16 )
{
T_2 V_47 , V_25 ;
T_2 V_229 = V_21 ;
T_4 V_82 ;
int V_118 ;
T_2 V_19 = V_15 -> V_19 ;
#if V_178
#if V_230
if ( V_19 < 4096 || F_194 ( V_19 - 1 ) == F_194 ( V_19 - 1 + V_20 +
2 * sizeof( unsigned long long ) ) )
V_16 |= V_17 | V_18 ;
if ( ! ( V_16 & V_219 ) )
V_16 |= V_217 ;
#endif
if ( V_16 & V_219 )
F_9 ( V_16 & V_217 ) ;
#endif
if ( V_19 & ( V_21 - 1 ) ) {
V_19 += ( V_21 - 1 ) ;
V_19 &= ~ ( V_21 - 1 ) ;
}
if ( V_16 & V_17 ) {
V_229 = V_20 ;
V_19 += V_20 - 1 ;
V_19 &= ~ ( V_20 - 1 ) ;
}
if ( V_229 < V_15 -> V_39 ) {
V_229 = V_15 -> V_39 ;
}
if ( V_229 > F_195 (unsigned long long) )
V_16 &= ~ ( V_17 | V_18 ) ;
V_15 -> V_39 = V_229 ;
if ( F_196 () )
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
#if V_230 && F_197 ( F_175 )
if ( ! V_170 && V_19 >= F_127 ( V_167 ) &&
V_19 >= 256 && V_15 -> V_206 > F_198 () &&
F_23 ( V_19 , V_15 -> V_39 ) < V_49 ) {
V_15 -> F_7 += V_49 - F_23 ( V_19 , V_15 -> V_39 ) ;
V_19 = V_49 ;
}
#endif
#endif
if ( V_19 >= V_231 && ! V_170 &&
! ( V_16 & V_232 ) )
V_16 |= V_50 ;
V_19 = F_23 ( V_19 , V_15 -> V_39 ) ;
if ( V_233 && V_19 < V_234 )
V_19 = F_23 ( V_234 , V_15 -> V_39 ) ;
V_47 = F_184 ( V_15 , V_19 , V_15 -> V_39 , V_16 ) ;
if ( ! V_15 -> V_28 )
return - V_235 ;
V_25 = F_21 ( V_15 -> V_28 , V_15 -> V_39 ) ;
if ( V_16 & V_50 && V_47 >= V_25 ) {
V_16 &= ~ V_50 ;
V_47 -= V_25 ;
}
if ( V_16 & V_50 ) {
V_25 = F_21 ( V_15 -> V_28 , 0 ) ;
#ifdef F_199
if ( V_19 % V_49 == 0 && V_16 & V_217 )
V_16 &= ~ ( V_17 | V_18 ) ;
#endif
}
V_15 -> V_236 = F_198 () ;
if ( V_15 -> V_236 < V_15 -> V_39 )
V_15 -> V_236 = V_15 -> V_39 ;
V_15 -> V_237 = V_47 / V_15 -> V_236 ;
V_15 -> V_25 = V_25 ;
V_15 -> V_16 = V_16 ;
V_15 -> V_189 = V_238 ;
if ( V_239 && ( V_16 & V_240 ) )
V_15 -> V_189 |= V_241 ;
V_15 -> V_19 = V_19 ;
V_15 -> V_35 = F_200 ( V_19 ) ;
if ( V_16 & V_50 ) {
V_15 -> V_220 = F_201 ( V_25 , 0u ) ;
F_9 ( F_202 ( V_15 -> V_220 ) ) ;
}
V_118 = F_188 ( V_15 , V_82 ) ;
if ( V_118 ) {
F_203 ( V_15 ) ;
return V_118 ;
}
return 0 ;
}
static void F_204 ( void )
{
F_9 ( ! F_205 () ) ;
}
static void F_206 ( void )
{
F_9 ( F_205 () ) ;
}
static void F_207 ( struct V_14 * V_15 )
{
#ifdef F_208
F_204 () ;
F_209 ( & F_55 ( V_15 , F_56 () ) -> V_11 ) ;
#endif
}
static void F_210 ( struct V_14 * V_15 , int V_64 )
{
#ifdef F_208
F_204 () ;
F_209 ( & F_55 ( V_15 , V_64 ) -> V_11 ) ;
#endif
}
static void F_211 ( void * V_140 )
{
struct V_14 * V_15 = V_140 ;
struct V_36 * V_75 ;
int V_64 = F_56 () ;
struct V_3 * V_84 ;
F_87 ( V_103 ) ;
F_204 () ;
V_75 = F_19 ( V_15 ) ;
V_84 = F_55 ( V_15 , V_64 ) ;
F_82 ( & V_84 -> V_11 ) ;
F_83 ( V_15 , V_75 -> V_89 , V_75 -> V_78 , V_64 , & V_103 ) ;
F_84 ( & V_84 -> V_11 ) ;
F_89 ( V_15 , & V_103 ) ;
V_75 -> V_78 = 0 ;
}
static void F_212 ( struct V_14 * V_15 )
{
struct V_3 * V_84 ;
int V_64 ;
F_213 ( F_211 , V_15 , 1 ) ;
F_206 () ;
F_140 (cachep, node, n)
if ( V_84 -> V_9 )
F_90 ( V_15 , V_84 -> V_9 ) ;
F_140 (cachep, node, n)
F_214 ( V_15 , V_84 , V_84 -> V_8 , 1 , V_64 ) ;
}
static int F_106 ( struct V_14 * V_32 ,
struct V_3 * V_84 , int V_242 )
{
struct V_102 * V_243 ;
int V_198 ;
struct V_22 * V_22 ;
V_198 = 0 ;
while ( V_198 < V_242 && ! F_62 ( & V_84 -> V_7 ) ) {
F_99 ( & V_84 -> V_11 ) ;
V_243 = V_84 -> V_7 . V_244 ;
if ( V_243 == & V_84 -> V_7 ) {
F_88 ( & V_84 -> V_11 ) ;
goto V_86;
}
V_22 = F_215 ( V_243 , struct V_22 , V_155 ) ;
#if V_178
F_9 ( V_22 -> V_187 ) ;
#endif
F_183 ( & V_22 -> V_155 ) ;
V_84 -> V_12 -= V_32 -> V_28 ;
F_88 ( & V_84 -> V_11 ) ;
F_179 ( V_32 , V_22 ) ;
V_198 ++ ;
}
V_86:
return V_198 ;
}
int F_216 ( struct V_14 * V_15 , bool V_245 )
{
int V_137 = 0 ;
int V_64 ;
struct V_3 * V_84 ;
F_212 ( V_15 ) ;
F_206 () ;
F_140 (cachep, node, n) {
F_106 ( V_15 , V_84 , F_101 ( V_15 , V_84 ) ) ;
V_137 += ! F_62 ( & V_84 -> V_5 ) ||
! F_62 ( & V_84 -> V_6 ) ;
}
return ( V_137 ? 1 : 0 ) ;
}
int F_217 ( struct V_14 * V_15 )
{
return F_216 ( V_15 , false ) ;
}
void F_203 ( struct V_14 * V_15 )
{
int V_88 ;
struct V_3 * V_84 ;
F_218 ( V_15 -> V_37 ) ;
F_140 (cachep, i, n) {
F_80 ( V_84 -> V_8 ) ;
F_71 ( V_84 -> V_9 ) ;
F_80 ( V_84 ) ;
V_15 -> V_64 [ V_88 ] = NULL ;
}
}
static void * F_219 ( struct V_14 * V_15 ,
struct V_22 * V_22 , int V_236 ,
T_4 V_246 , int V_97 )
{
void * V_30 ;
void * V_204 = F_220 ( V_22 ) ;
if ( F_176 ( V_15 ) ) {
V_30 = F_221 ( V_15 -> V_220 ,
V_246 , V_97 ) ;
if ( ! V_30 )
return NULL ;
} else {
V_30 = V_204 + V_236 ;
V_236 += V_15 -> V_25 ;
}
V_22 -> V_187 = 0 ;
V_22 -> V_33 = V_204 + V_236 ;
return V_30 ;
}
static inline V_29 F_222 ( struct V_22 * V_22 , unsigned int V_23 )
{
return ( ( V_29 * ) V_22 -> V_30 ) [ V_23 ] ;
}
static inline void F_223 ( struct V_22 * V_22 ,
unsigned int V_23 , V_29 V_24 )
{
( ( V_29 * ) ( V_22 -> V_30 ) ) [ V_23 ] = V_24 ;
}
static void F_224 ( struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < V_15 -> V_28 ; V_88 ++ ) {
void * V_1 = F_16 ( V_15 , V_22 , V_88 ) ;
#if V_178
if ( V_15 -> V_16 & V_217 )
F_167 ( V_15 , V_1 , V_212 ) ;
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = NULL ;
if ( V_15 -> V_16 & V_17 ) {
* F_8 ( V_15 , V_1 ) = V_218 ;
* F_10 ( V_15 , V_1 ) = V_218 ;
}
if ( V_15 -> V_197 && ! ( V_15 -> V_16 & V_217 ) )
V_15 -> V_197 ( V_1 + F_7 ( V_15 ) ) ;
if ( V_15 -> V_16 & V_17 ) {
if ( * F_10 ( V_15 , V_1 ) != V_218 )
F_178 ( V_15 , L_22
L_23 ) ;
if ( * F_8 ( V_15 , V_1 ) != V_218 )
F_178 ( V_15 , L_22
L_24 ) ;
}
if ( ( V_15 -> V_19 % V_49 ) == 0 &&
F_176 ( V_15 ) && V_15 -> V_16 & V_217 )
F_177 ( F_96 ( V_1 ) ,
V_15 -> V_19 / V_49 , 0 ) ;
#else
if ( V_15 -> V_197 )
V_15 -> V_197 ( V_1 ) ;
#endif
F_12 ( V_22 , V_88 , V_247 ) ;
F_223 ( V_22 , V_88 , V_88 ) ;
}
}
static void F_225 ( struct V_14 * V_15 , T_4 V_16 )
{
if ( V_239 ) {
if ( V_16 & V_241 )
F_9 ( ! ( V_15 -> V_189 & V_241 ) ) ;
else
F_9 ( V_15 -> V_189 & V_241 ) ;
}
}
static void * F_226 ( struct V_14 * V_15 , struct V_22 * V_22 ,
int V_97 )
{
void * V_1 ;
V_1 = F_16 ( V_15 , V_22 , F_222 ( V_22 , V_22 -> V_187 ) ) ;
V_22 -> V_187 ++ ;
#if V_178
F_227 ( F_95 ( F_96 ( V_1 ) ) != V_97 ) ;
#endif
return V_1 ;
}
static void F_228 ( struct V_14 * V_15 , struct V_22 * V_22 ,
void * V_1 , int V_97 )
{
unsigned int V_216 = F_17 ( V_15 , V_22 , V_1 ) ;
#if V_178
unsigned int V_88 ;
F_227 ( F_95 ( F_96 ( V_1 ) ) != V_97 ) ;
for ( V_88 = V_22 -> V_187 ; V_88 < V_15 -> V_28 ; V_88 ++ ) {
if ( F_222 ( V_22 , V_88 ) == V_216 ) {
F_27 ( V_53 L_25
L_26 , V_15 -> V_54 , V_1 ) ;
F_132 () ;
}
}
#endif
V_22 -> V_187 -- ;
F_223 ( V_22 , V_22 -> V_187 , V_216 ) ;
}
static void F_229 ( struct V_14 * V_32 , struct V_22 * V_22 ,
void * V_30 )
{
V_22 -> V_27 = V_32 ;
V_22 -> V_30 = V_30 ;
}
static int F_230 ( struct V_14 * V_15 ,
T_4 V_16 , int V_97 , struct V_22 * V_22 )
{
void * V_30 ;
T_2 V_34 ;
T_4 V_246 ;
struct V_3 * V_84 ;
if ( F_41 ( V_16 & V_248 ) ) {
F_231 ( L_27 , V_16 & V_248 ) ;
F_132 () ;
}
V_246 = V_16 & ( V_249 | V_250 ) ;
F_204 () ;
V_84 = F_55 ( V_15 , V_97 ) ;
F_82 ( & V_84 -> V_11 ) ;
V_34 = V_84 -> V_10 ;
V_84 -> V_10 ++ ;
if ( V_84 -> V_10 >= V_15 -> V_237 )
V_84 -> V_10 = 0 ;
F_84 ( & V_84 -> V_11 ) ;
V_34 *= V_15 -> V_236 ;
if ( F_232 ( V_246 ) )
F_233 () ;
F_225 ( V_15 , V_16 ) ;
if ( ! V_22 )
V_22 = F_141 ( V_15 , V_246 , V_97 ) ;
if ( ! V_22 )
goto V_251;
V_30 = F_219 ( V_15 , V_22 , V_34 ,
V_246 & ~ V_249 , V_97 ) ;
if ( ! V_30 )
goto V_252;
F_229 ( V_15 , V_22 , V_30 ) ;
F_224 ( V_15 , V_22 ) ;
if ( F_232 ( V_246 ) )
F_234 () ;
F_204 () ;
F_82 ( & V_84 -> V_11 ) ;
F_235 ( & V_22 -> V_155 , & ( V_84 -> V_7 ) ) ;
F_236 ( V_15 ) ;
V_84 -> V_12 += V_15 -> V_28 ;
F_84 ( & V_84 -> V_11 ) ;
return 1 ;
V_252:
F_153 ( V_15 , V_22 ) ;
V_251:
if ( F_232 ( V_246 ) )
F_234 () ;
return 0 ;
}
static void F_237 ( const void * V_1 )
{
if ( ! F_238 ( V_1 ) ) {
F_27 ( V_53 L_28 ,
( unsigned long ) V_1 ) ;
F_132 () ;
}
}
static inline void F_239 ( struct V_14 * V_32 , void * V_31 )
{
unsigned long long V_253 , V_254 ;
V_253 = * F_8 ( V_32 , V_31 ) ;
V_254 = * F_10 ( V_32 , V_31 ) ;
if ( V_253 == V_255 && V_254 == V_255 )
return;
if ( V_253 == V_218 && V_254 == V_218 )
F_178 ( V_32 , L_29 ) ;
else
F_178 ( V_32 , L_30 ) ;
F_27 ( V_53 L_31 ,
V_31 , V_253 , V_254 ) ;
}
static void * F_240 ( struct V_14 * V_15 , void * V_1 ,
unsigned long V_205 )
{
unsigned int V_216 ;
struct V_22 * V_22 ;
F_9 ( F_14 ( V_1 ) != V_15 ) ;
V_1 -= F_7 ( V_15 ) ;
F_237 ( V_1 ) ;
V_22 = F_15 ( V_1 ) ;
if ( V_15 -> V_16 & V_17 ) {
F_239 ( V_15 , V_1 ) ;
* F_8 ( V_15 , V_1 ) = V_218 ;
* F_10 ( V_15 , V_1 ) = V_218 ;
}
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = ( void * ) V_205 ;
V_216 = F_17 ( V_15 , V_22 , V_1 ) ;
F_9 ( V_216 >= V_15 -> V_28 ) ;
F_9 ( V_1 != F_16 ( V_15 , V_22 , V_216 ) ) ;
F_12 ( V_22 , V_216 , V_247 ) ;
if ( V_15 -> V_16 & V_217 ) {
#ifdef F_175
if ( ( V_15 -> V_19 % V_49 ) == 0 && F_176 ( V_15 ) ) {
F_163 ( V_15 , V_1 , V_205 ) ;
F_177 ( F_96 ( V_1 ) ,
V_15 -> V_19 / V_49 , 0 ) ;
} else {
F_167 ( V_15 , V_1 , V_212 ) ;
}
#else
F_167 ( V_15 , V_1 , V_212 ) ;
#endif
}
return V_1 ;
}
static struct V_22 * F_241 ( struct V_3 * V_84 )
{
struct V_22 * V_22 ;
V_22 = F_242 ( & V_84 -> V_6 ,
struct V_22 , V_155 ) ;
if ( ! V_22 ) {
V_84 -> V_13 = 1 ;
V_22 = F_242 ( & V_84 -> V_7 ,
struct V_22 , V_155 ) ;
}
return V_22 ;
}
static void * F_243 ( struct V_14 * V_15 , T_4 V_16 ,
bool V_87 )
{
int V_79 ;
struct V_3 * V_84 ;
struct V_36 * V_75 ;
int V_64 ;
F_204 () ;
V_64 = F_56 () ;
if ( F_41 ( V_87 ) )
goto V_256;
V_257:
V_75 = F_19 ( V_15 ) ;
V_79 = V_75 -> V_79 ;
if ( ! V_75 -> V_80 && V_79 > V_258 ) {
V_79 = V_258 ;
}
V_84 = F_55 ( V_15 , V_64 ) ;
F_9 ( V_75 -> V_78 > 0 || ! V_84 ) ;
F_82 ( & V_84 -> V_11 ) ;
if ( V_84 -> V_8 && F_68 ( V_75 , V_84 -> V_8 , V_79 ) ) {
V_84 -> V_8 -> V_80 = 1 ;
goto V_259;
}
while ( V_79 > 0 ) {
struct V_22 * V_22 ;
V_22 = F_241 ( V_84 ) ;
if ( ! V_22 )
goto V_260;
F_207 ( V_15 ) ;
F_9 ( V_22 -> V_187 >= V_15 -> V_28 ) ;
while ( V_22 -> V_187 < V_15 -> V_28 && V_79 -- ) {
F_244 ( V_15 ) ;
F_245 ( V_15 ) ;
F_246 ( V_15 ) ;
F_67 ( V_15 , V_75 , F_226 ( V_15 , V_22 ,
V_64 ) ) ;
}
F_183 ( & V_22 -> V_155 ) ;
if ( V_22 -> V_187 == V_15 -> V_28 )
F_125 ( & V_22 -> V_155 , & V_84 -> V_5 ) ;
else
F_125 ( & V_22 -> V_155 , & V_84 -> V_6 ) ;
}
V_260:
V_84 -> V_12 -= V_75 -> V_78 ;
V_259:
F_84 ( & V_84 -> V_11 ) ;
if ( F_41 ( ! V_75 -> V_78 ) ) {
int V_261 ;
V_256:
V_261 = F_230 ( V_15 , F_75 ( V_16 ) , V_64 , NULL ) ;
V_75 = F_19 ( V_15 ) ;
V_64 = F_56 () ;
if ( ! V_261 && ( V_75 -> V_78 == 0 || V_87 ) )
return NULL ;
if ( ! V_75 -> V_78 )
goto V_257;
}
V_75 -> V_80 = 1 ;
return F_64 ( V_15 , V_75 , V_16 , V_87 ) ;
}
static inline void F_247 ( struct V_14 * V_15 ,
T_4 V_16 )
{
F_248 ( F_232 ( V_16 ) ) ;
#if V_178
F_225 ( V_15 , V_16 ) ;
#endif
}
static void * F_249 ( struct V_14 * V_15 ,
T_4 V_16 , void * V_1 , unsigned long V_205 )
{
struct V_22 * V_22 ;
if ( ! V_1 )
return V_1 ;
if ( V_15 -> V_16 & V_217 ) {
#ifdef F_175
if ( ( V_15 -> V_19 % V_49 ) == 0 && F_176 ( V_15 ) )
F_177 ( F_96 ( V_1 ) ,
V_15 -> V_19 / V_49 , 1 ) ;
else
F_172 ( V_15 , V_1 ) ;
#else
F_172 ( V_15 , V_1 ) ;
#endif
F_167 ( V_15 , V_1 , V_262 ) ;
}
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = ( void * ) V_205 ;
if ( V_15 -> V_16 & V_17 ) {
if ( * F_8 ( V_15 , V_1 ) != V_218 ||
* F_10 ( V_15 , V_1 ) != V_218 ) {
F_178 ( V_15 , L_32
L_33 ) ;
F_27 ( V_53
L_34 ,
V_1 , * F_8 ( V_15 , V_1 ) ,
* F_10 ( V_15 , V_1 ) ) ;
}
* F_8 ( V_15 , V_1 ) = V_255 ;
* F_10 ( V_15 , V_1 ) = V_255 ;
}
V_22 = F_15 ( V_1 ) ;
F_12 ( V_22 , F_17 ( V_15 , V_22 , V_1 ) , V_263 ) ;
V_1 += F_7 ( V_15 ) ;
if ( V_15 -> V_197 && V_15 -> V_16 & V_217 )
V_15 -> V_197 ( V_1 ) ;
if ( V_264 &&
( ( unsigned long ) V_1 & ( V_264 - 1 ) ) ) {
F_27 ( V_53 L_35 ,
V_1 , ( int ) V_264 ) ;
}
return V_1 ;
}
static bool F_250 ( struct V_14 * V_15 , T_4 V_16 )
{
if ( F_41 ( V_15 == V_14 ) )
return false ;
return F_251 ( V_15 -> V_206 , V_16 , V_15 -> V_16 ) ;
}
static inline void * F_252 ( struct V_14 * V_15 , T_4 V_16 )
{
void * V_1 ;
struct V_36 * V_75 ;
bool V_87 = false ;
F_204 () ;
V_75 = F_19 ( V_15 ) ;
if ( F_97 ( V_75 -> V_78 ) ) {
V_75 -> V_80 = 1 ;
V_1 = F_64 ( V_15 , V_75 , V_16 , false ) ;
if ( V_1 ) {
F_253 ( V_15 ) ;
goto V_86;
}
V_87 = true ;
}
F_254 ( V_15 ) ;
V_1 = F_243 ( V_15 , V_16 , V_87 ) ;
V_75 = F_19 ( V_15 ) ;
V_86:
if ( V_1 )
F_255 ( & V_75 -> V_89 [ V_75 -> V_78 ] ) ;
return V_1 ;
}
static void * F_73 ( struct V_14 * V_15 , T_4 V_16 )
{
int V_265 , V_266 ;
if ( F_256 () || ( V_16 & V_105 ) )
return NULL ;
V_265 = V_266 = F_56 () ;
if ( F_257 () && ( V_15 -> V_16 & V_267 ) )
V_265 = F_258 () ;
else if ( V_200 -> V_268 )
V_265 = F_259 () ;
if ( V_265 != V_266 )
return F_74 ( V_15 , V_16 , V_265 ) ;
return NULL ;
}
static void * F_260 ( struct V_14 * V_32 , T_4 V_16 )
{
struct V_269 * V_269 ;
T_4 V_246 ;
struct V_270 * V_271 ;
struct V_272 * V_272 ;
enum V_273 V_274 = F_261 ( V_16 ) ;
void * V_31 = NULL ;
int V_143 ;
unsigned int V_275 ;
if ( V_16 & V_105 )
return NULL ;
V_246 = V_16 & ( V_249 | V_250 ) ;
V_276:
V_275 = F_262 () ;
V_269 = F_263 ( F_259 () , V_16 ) ;
V_257:
F_264 (zone, z, zonelist, high_zoneidx) {
V_143 = F_265 ( V_272 ) ;
if ( F_266 ( V_272 , V_16 ) &&
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
if ( F_232 ( V_246 ) )
F_233 () ;
F_225 ( V_32 , V_16 ) ;
V_22 = F_141 ( V_32 , V_246 , F_56 () ) ;
if ( F_232 ( V_246 ) )
F_234 () ;
if ( V_22 ) {
V_143 = F_95 ( V_22 ) ;
if ( F_230 ( V_32 , V_16 , V_143 , V_22 ) ) {
V_31 = F_74 ( V_32 ,
F_75 ( V_16 ) , V_143 ) ;
if ( ! V_31 )
goto V_257;
} else {
V_31 = NULL ;
}
}
}
if ( F_41 ( ! V_31 && F_267 ( V_275 ) ) )
goto V_276;
return V_31 ;
}
static void * F_74 ( struct V_14 * V_15 , T_4 V_16 ,
int V_97 )
{
struct V_22 * V_22 ;
struct V_3 * V_84 ;
void * V_31 ;
int V_261 ;
F_268 ( V_97 < 0 || V_97 >= V_66 ) ;
V_84 = F_55 ( V_15 , V_97 ) ;
F_9 ( ! V_84 ) ;
V_257:
F_204 () ;
F_82 ( & V_84 -> V_11 ) ;
V_22 = F_241 ( V_84 ) ;
if ( ! V_22 )
goto V_260;
F_210 ( V_15 , V_97 ) ;
F_269 ( V_15 ) ;
F_245 ( V_15 ) ;
F_246 ( V_15 ) ;
F_9 ( V_22 -> V_187 == V_15 -> V_28 ) ;
V_31 = F_226 ( V_15 , V_22 , V_97 ) ;
V_84 -> V_12 -- ;
F_183 ( & V_22 -> V_155 ) ;
if ( V_22 -> V_187 == V_15 -> V_28 )
F_125 ( & V_22 -> V_155 , & V_84 -> V_5 ) ;
else
F_125 ( & V_22 -> V_155 , & V_84 -> V_6 ) ;
F_84 ( & V_84 -> V_11 ) ;
goto V_277;
V_260:
F_84 ( & V_84 -> V_11 ) ;
V_261 = F_230 ( V_15 , F_75 ( V_16 ) , V_97 , NULL ) ;
if ( V_261 )
goto V_257;
return F_260 ( V_15 , V_16 ) ;
V_277:
return V_31 ;
}
static T_9 void *
F_270 ( struct V_14 * V_15 , T_4 V_16 , int V_97 ,
unsigned long V_205 )
{
unsigned long V_278 ;
void * V_151 ;
int V_279 = F_56 () ;
V_16 &= V_280 ;
F_271 ( V_16 ) ;
if ( F_250 ( V_15 , V_16 ) )
return NULL ;
V_15 = F_272 ( V_15 , V_16 ) ;
F_247 ( V_15 , V_16 ) ;
F_273 ( V_278 ) ;
if ( V_97 == V_281 )
V_97 = V_279 ;
if ( F_41 ( ! F_55 ( V_15 , V_97 ) ) ) {
V_151 = F_260 ( V_15 , V_16 ) ;
goto V_86;
}
if ( V_97 == V_279 ) {
V_151 = F_252 ( V_15 , V_16 ) ;
if ( V_151 )
goto V_86;
}
V_151 = F_74 ( V_15 , V_16 , V_97 ) ;
V_86:
F_274 ( V_278 ) ;
V_151 = F_249 ( V_15 , V_16 , V_151 , V_205 ) ;
F_275 ( V_151 , V_15 -> V_206 , 1 , V_15 -> V_16 ,
V_16 ) ;
if ( F_97 ( V_151 ) ) {
F_276 ( V_15 , V_16 , V_151 , V_15 -> V_206 ) ;
if ( F_41 ( V_16 & V_282 ) )
memset ( V_151 , 0 , V_15 -> V_206 ) ;
}
F_277 ( V_15 ) ;
return V_151 ;
}
static T_9 void *
F_278 ( struct V_14 * V_32 , T_4 V_16 )
{
void * V_1 ;
if ( V_200 -> V_268 || F_257 () ) {
V_1 = F_73 ( V_32 , V_16 ) ;
if ( V_1 )
goto V_86;
}
V_1 = F_252 ( V_32 , V_16 ) ;
if ( ! V_1 )
V_1 = F_74 ( V_32 , V_16 , F_56 () ) ;
V_86:
return V_1 ;
}
static T_9 void *
F_278 ( struct V_14 * V_15 , T_4 V_16 )
{
return F_252 ( V_15 , V_16 ) ;
}
static T_9 void *
F_279 ( struct V_14 * V_15 , T_4 V_16 , unsigned long V_205 )
{
unsigned long V_278 ;
void * V_1 ;
V_16 &= V_280 ;
F_271 ( V_16 ) ;
if ( F_250 ( V_15 , V_16 ) )
return NULL ;
V_15 = F_272 ( V_15 , V_16 ) ;
F_247 ( V_15 , V_16 ) ;
F_273 ( V_278 ) ;
V_1 = F_278 ( V_15 , V_16 ) ;
F_274 ( V_278 ) ;
V_1 = F_249 ( V_15 , V_16 , V_1 , V_205 ) ;
F_275 ( V_1 , V_15 -> V_206 , 1 , V_15 -> V_16 ,
V_16 ) ;
F_280 ( V_1 ) ;
if ( F_97 ( V_1 ) ) {
F_276 ( V_15 , V_16 , V_1 , V_15 -> V_206 ) ;
if ( F_41 ( V_16 & V_282 ) )
memset ( V_1 , 0 , V_15 -> V_206 ) ;
}
F_277 ( V_15 ) ;
return V_1 ;
}
static void F_83 ( struct V_14 * V_15 , void * * V_283 ,
int V_284 , int V_64 , struct V_102 * V_103 )
{
int V_88 ;
struct V_3 * V_84 = F_55 ( V_15 , V_64 ) ;
for ( V_88 = 0 ; V_88 < V_284 ; V_88 ++ ) {
void * V_1 ;
struct V_22 * V_22 ;
F_3 ( & V_283 [ V_88 ] ) ;
V_1 = V_283 [ V_88 ] ;
V_22 = F_15 ( V_1 ) ;
F_183 ( & V_22 -> V_155 ) ;
F_210 ( V_15 , V_64 ) ;
F_228 ( V_15 , V_22 , V_1 , V_64 ) ;
F_281 ( V_15 ) ;
V_84 -> V_12 ++ ;
if ( V_22 -> V_187 == 0 ) {
if ( V_84 -> V_12 > V_84 -> V_113 ) {
V_84 -> V_12 -= V_15 -> V_28 ;
F_235 ( & V_22 -> V_155 , V_103 ) ;
} else {
F_125 ( & V_22 -> V_155 , & V_84 -> V_7 ) ;
}
} else {
F_235 ( & V_22 -> V_155 , & V_84 -> V_6 ) ;
}
}
}
static void F_282 ( struct V_14 * V_15 , struct V_36 * V_75 )
{
int V_79 ;
struct V_3 * V_84 ;
int V_64 = F_56 () ;
F_87 ( V_103 ) ;
V_79 = V_75 -> V_79 ;
#if V_178
F_9 ( ! V_79 || V_79 > V_75 -> V_78 ) ;
#endif
F_204 () ;
V_84 = F_55 ( V_15 , V_64 ) ;
F_82 ( & V_84 -> V_11 ) ;
if ( V_84 -> V_8 ) {
struct V_36 * V_285 = V_84 -> V_8 ;
int V_92 = V_285 -> V_76 - V_285 -> V_78 ;
if ( V_92 ) {
if ( V_79 > V_92 )
V_79 = V_92 ;
memcpy ( & ( V_285 -> V_89 [ V_285 -> V_78 ] ) ,
V_75 -> V_89 , sizeof( void * ) * V_79 ) ;
V_285 -> V_78 += V_79 ;
goto V_286;
}
}
F_83 ( V_15 , V_75 -> V_89 , V_79 , V_64 , & V_103 ) ;
V_286:
#if V_287
{
int V_88 = 0 ;
struct V_22 * V_22 ;
F_58 (page, &n->slabs_free, lru) {
F_9 ( V_22 -> V_187 ) ;
V_88 ++ ;
}
F_283 ( V_15 , V_88 ) ;
}
#endif
F_84 ( & V_84 -> V_11 ) ;
F_89 ( V_15 , & V_103 ) ;
V_75 -> V_78 -= V_79 ;
memmove ( V_75 -> V_89 , & ( V_75 -> V_89 [ V_79 ] ) , sizeof( void * ) * V_75 -> V_78 ) ;
}
static inline void F_284 ( struct V_14 * V_15 , void * V_1 ,
unsigned long V_205 )
{
struct V_36 * V_75 = F_19 ( V_15 ) ;
F_204 () ;
F_285 ( V_1 , V_15 -> V_16 ) ;
V_1 = F_240 ( V_15 , V_1 , V_205 ) ;
F_286 ( V_15 , V_1 , V_15 -> V_206 ) ;
if ( V_288 > 1 && F_72 ( V_15 , V_1 ) )
return;
if ( V_75 -> V_78 < V_75 -> V_76 ) {
F_287 ( V_15 ) ;
} else {
F_288 ( V_15 ) ;
F_282 ( V_15 , V_75 ) ;
}
F_67 ( V_15 , V_75 , V_1 ) ;
}
void * F_289 ( struct V_14 * V_15 , T_4 V_16 )
{
void * V_137 = F_279 ( V_15 , V_16 , V_289 ) ;
F_290 ( V_289 , V_137 ,
V_15 -> V_206 , V_15 -> V_19 , V_16 ) ;
return V_137 ;
}
void F_291 ( struct V_14 * V_57 , T_2 V_19 , void * * V_243 )
{
F_292 ( V_57 , V_19 , V_243 ) ;
}
int F_293 ( struct V_14 * V_57 , T_4 V_16 , T_2 V_19 ,
void * * V_243 )
{
return F_294 ( V_57 , V_16 , V_19 , V_243 ) ;
}
void *
F_295 ( struct V_14 * V_15 , T_4 V_16 , T_2 V_19 )
{
void * V_137 ;
V_137 = F_279 ( V_15 , V_16 , V_289 ) ;
F_296 ( V_289 , V_137 ,
V_19 , V_15 -> V_19 , V_16 ) ;
return V_137 ;
}
void * F_221 ( struct V_14 * V_15 , T_4 V_16 , int V_97 )
{
void * V_137 = F_270 ( V_15 , V_16 , V_97 , V_289 ) ;
F_297 ( V_289 , V_137 ,
V_15 -> V_206 , V_15 -> V_19 ,
V_16 , V_97 ) ;
return V_137 ;
}
void * F_298 ( struct V_14 * V_15 ,
T_4 V_16 ,
int V_97 ,
T_2 V_19 )
{
void * V_137 ;
V_137 = F_270 ( V_15 , V_16 , V_97 , V_289 ) ;
F_299 ( V_289 , V_137 ,
V_19 , V_15 -> V_19 ,
V_16 , V_97 ) ;
return V_137 ;
}
static T_9 void *
F_300 ( T_2 V_19 , T_4 V_16 , int V_64 , unsigned long V_205 )
{
struct V_14 * V_15 ;
V_15 = F_201 ( V_19 , V_16 ) ;
if ( F_41 ( F_202 ( V_15 ) ) )
return V_15 ;
return F_298 ( V_15 , V_16 , V_64 , V_19 ) ;
}
void * F_301 ( T_2 V_19 , T_4 V_16 , int V_64 )
{
return F_300 ( V_19 , V_16 , V_64 , V_289 ) ;
}
void * F_302 ( T_2 V_19 , T_4 V_16 ,
int V_64 , unsigned long V_205 )
{
return F_300 ( V_19 , V_16 , V_64 , V_205 ) ;
}
static T_9 void * F_303 ( T_2 V_19 , T_4 V_16 ,
unsigned long V_205 )
{
struct V_14 * V_15 ;
void * V_137 ;
V_15 = F_201 ( V_19 , V_16 ) ;
if ( F_41 ( F_202 ( V_15 ) ) )
return V_15 ;
V_137 = F_279 ( V_15 , V_16 , V_205 ) ;
F_296 ( V_205 , V_137 ,
V_19 , V_15 -> V_19 , V_16 ) ;
return V_137 ;
}
void * F_304 ( T_2 V_19 , T_4 V_16 )
{
return F_303 ( V_19 , V_16 , V_289 ) ;
}
void * F_305 ( T_2 V_19 , T_4 V_16 , unsigned long V_205 )
{
return F_303 ( V_19 , V_16 , V_205 ) ;
}
void F_181 ( struct V_14 * V_15 , void * V_1 )
{
unsigned long V_16 ;
V_15 = F_306 ( V_15 , V_1 ) ;
if ( ! V_15 )
return;
F_273 ( V_16 ) ;
F_307 ( V_1 , V_15 -> V_206 ) ;
if ( ! ( V_15 -> V_16 & V_290 ) )
F_308 ( V_1 , V_15 -> V_206 ) ;
F_284 ( V_15 , V_1 , V_289 ) ;
F_274 ( V_16 ) ;
F_309 ( V_289 , V_1 ) ;
}
void F_80 ( const void * V_1 )
{
struct V_14 * V_291 ;
unsigned long V_16 ;
F_310 ( V_289 , V_1 ) ;
if ( F_41 ( F_202 ( V_1 ) ) )
return;
F_273 ( V_16 ) ;
F_237 ( V_1 ) ;
V_291 = F_14 ( V_1 ) ;
F_307 ( V_1 , V_291 -> V_206 ) ;
F_308 ( V_1 , V_291 -> V_206 ) ;
F_284 ( V_291 , ( void * ) V_1 , V_289 ) ;
F_274 ( V_16 ) ;
}
static int F_311 ( struct V_14 * V_15 , T_4 V_82 )
{
int V_64 ;
struct V_3 * V_84 ;
struct V_36 * V_292 ;
struct V_94 * * V_293 = NULL ;
F_91 (node) {
if ( V_58 ) {
V_293 = F_70 ( V_64 , V_15 -> V_76 , V_82 ) ;
if ( ! V_293 )
goto V_294;
}
V_292 = NULL ;
if ( V_15 -> V_8 ) {
V_292 = F_50 ( V_64 ,
V_15 -> V_8 * V_15 -> V_79 ,
0xbaadf00d , V_82 ) ;
if ( ! V_292 ) {
F_71 ( V_293 ) ;
goto V_294;
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
V_84 -> V_8 = V_292 ;
if ( ! V_84 -> V_9 ) {
V_84 -> V_9 = V_293 ;
V_293 = NULL ;
}
V_84 -> V_113 = ( 1 + F_100 ( V_64 ) ) *
V_15 -> V_79 + V_15 -> V_28 ;
F_88 ( & V_84 -> V_11 ) ;
F_89 ( V_15 , & V_103 ) ;
F_80 ( V_8 ) ;
F_71 ( V_293 ) ;
continue;
}
V_84 = F_51 ( sizeof( struct V_3 ) , V_82 , V_64 ) ;
if ( ! V_84 ) {
F_71 ( V_293 ) ;
F_80 ( V_292 ) ;
goto V_294;
}
F_4 ( V_84 ) ;
V_84 -> V_110 = V_111 + V_112 +
( ( unsigned long ) V_15 ) % V_112 ;
V_84 -> V_8 = V_292 ;
V_84 -> V_9 = V_293 ;
V_84 -> V_113 = ( 1 + F_100 ( V_64 ) ) *
V_15 -> V_79 + V_15 -> V_28 ;
V_15 -> V_64 [ V_64 ] = V_84 ;
}
return 0 ;
V_294:
if ( ! V_15 -> V_103 . V_295 ) {
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
static int F_312 ( struct V_14 * V_15 , int V_76 ,
int V_79 , int V_8 , T_4 V_82 )
{
struct V_36 T_7 * V_37 , * V_244 ;
int V_63 ;
V_37 = F_185 ( V_15 , V_76 , V_79 ) ;
if ( ! V_37 )
return - V_109 ;
V_244 = V_15 -> V_37 ;
V_15 -> V_37 = V_37 ;
F_313 () ;
F_206 () ;
V_15 -> V_79 = V_79 ;
V_15 -> V_76 = V_76 ;
V_15 -> V_8 = V_8 ;
if ( ! V_244 )
goto V_296;
F_136 (cpu) {
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
F_218 ( V_244 ) ;
V_296:
return F_311 ( V_15 , V_82 ) ;
}
static int F_314 ( struct V_14 * V_15 , int V_76 ,
int V_79 , int V_8 , T_4 V_82 )
{
int V_137 ;
struct V_14 * V_291 ;
V_137 = F_312 ( V_15 , V_76 , V_79 , V_8 , V_82 ) ;
if ( V_164 < V_174 )
return V_137 ;
if ( ( V_137 < 0 ) || ! F_315 ( V_15 ) )
return V_137 ;
F_316 ( & V_126 ) ;
F_317 (c, cachep) {
F_312 ( V_291 , V_76 , V_79 , V_8 , V_82 ) ;
}
return V_137 ;
}
static int F_131 ( struct V_14 * V_15 , T_4 V_82 )
{
int V_118 ;
int V_76 = 0 ;
int V_8 = 0 ;
int V_79 = 0 ;
if ( ! F_315 ( V_15 ) ) {
struct V_14 * V_297 = F_318 ( V_15 ) ;
V_76 = V_297 -> V_76 ;
V_8 = V_297 -> V_8 ;
V_79 = V_297 -> V_79 ;
}
if ( V_76 && V_8 && V_79 )
goto V_298;
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
if ( V_15 -> V_19 <= V_49 && F_319 () > 1 )
V_8 = 8 ;
#if V_178
if ( V_76 > 32 )
V_76 = 32 ;
#endif
V_79 = ( V_76 + 1 ) / 2 ;
V_298:
V_118 = F_314 ( V_15 , V_76 , V_79 , V_8 , V_82 ) ;
if ( V_118 )
F_27 ( V_53 L_36 ,
V_15 -> V_54 , - V_118 ) ;
return V_118 ;
}
static void F_214 ( struct V_14 * V_15 , struct V_3 * V_84 ,
struct V_36 * V_75 , int V_299 , int V_64 )
{
F_87 ( V_103 ) ;
int V_242 ;
if ( ! V_75 || ! V_75 -> V_78 )
return;
if ( V_75 -> V_80 && ! V_299 ) {
V_75 -> V_80 = 0 ;
} else {
F_99 ( & V_84 -> V_11 ) ;
if ( V_75 -> V_78 ) {
V_242 = V_299 ? V_75 -> V_78 : ( V_75 -> V_76 + 4 ) / 5 ;
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
static void V_73 ( struct V_300 * V_301 )
{
struct V_14 * V_302 ;
struct V_3 * V_84 ;
int V_64 = F_56 () ;
struct V_68 * V_71 = F_320 ( V_301 ) ;
if ( ! F_321 ( & V_126 ) )
goto V_86;
F_58 (searchp, &slab_caches, list) {
F_206 () ;
V_84 = F_55 ( V_302 , V_64 ) ;
F_85 ( V_302 , V_84 ) ;
F_214 ( V_302 , V_84 , F_19 ( V_302 ) , 0 , V_64 ) ;
if ( F_322 ( V_84 -> V_110 , V_111 ) )
goto V_295;
V_84 -> V_110 = V_111 + V_112 ;
F_214 ( V_302 , V_84 , V_84 -> V_8 , 0 , V_64 ) ;
if ( V_84 -> V_13 )
V_84 -> V_13 = 0 ;
else {
int V_303 ;
V_303 = F_106 ( V_302 , V_84 , ( V_84 -> V_113 +
5 * V_302 -> V_28 - 1 ) / ( 5 * V_302 -> V_28 ) ) ;
F_323 ( V_302 , V_303 ) ;
}
V_295:
F_324 () ;
}
F_206 () ;
F_111 ( & V_126 ) ;
F_39 () ;
V_86:
F_325 ( V_71 , F_326 ( V_304 ) ) ;
}
void F_327 ( struct V_14 * V_15 , struct V_305 * V_306 )
{
struct V_22 * V_22 ;
unsigned long V_183 ;
unsigned long V_184 ;
unsigned long V_185 = 0 ;
unsigned long V_186 , V_12 = 0 , V_307 = 0 ;
const char * V_54 ;
char * error = NULL ;
int V_64 ;
struct V_3 * V_84 ;
V_183 = 0 ;
V_186 = 0 ;
F_140 (cachep, node, n) {
F_206 () ;
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
V_307 += V_84 -> V_8 -> V_78 ;
F_88 ( & V_84 -> V_11 ) ;
}
V_186 += V_185 ;
V_184 = V_186 * V_15 -> V_28 ;
if ( V_184 - V_183 != V_12 && ! error )
error = L_40 ;
V_54 = V_15 -> V_54 ;
if ( error )
F_27 ( V_53 L_41 , V_54 , error ) ;
V_306 -> V_183 = V_183 ;
V_306 -> V_184 = V_184 ;
V_306 -> V_185 = V_185 ;
V_306 -> V_186 = V_186 ;
V_306 -> V_307 = V_307 ;
V_306 -> V_76 = V_15 -> V_76 ;
V_306 -> V_79 = V_15 -> V_79 ;
V_306 -> V_8 = V_15 -> V_8 ;
V_306 -> V_308 = V_15 -> V_28 ;
V_306 -> V_309 = V_15 -> V_46 ;
}
void F_328 ( struct V_310 * V_311 , struct V_14 * V_15 )
{
#if V_287
{
unsigned long V_312 = V_15 -> V_313 ;
unsigned long V_314 = V_15 -> V_315 ;
unsigned long V_316 = V_15 -> V_316 ;
unsigned long V_317 = V_15 -> V_317 ;
unsigned long V_318 = V_15 -> V_318 ;
unsigned long V_319 = V_15 -> V_319 ;
unsigned long V_320 = V_15 -> V_320 ;
unsigned long V_321 = V_15 -> V_321 ;
unsigned long V_322 = V_15 -> V_323 ;
F_329 ( V_311 , L_42
L_43 ,
V_314 , V_312 , V_316 ,
V_317 , V_318 , V_319 , V_320 ,
V_321 , V_322 ) ;
}
{
unsigned long V_324 = F_330 ( & V_15 -> V_324 ) ;
unsigned long V_325 = F_330 ( & V_15 -> V_325 ) ;
unsigned long V_326 = F_330 ( & V_15 -> V_326 ) ;
unsigned long V_327 = F_330 ( & V_15 -> V_327 ) ;
F_329 ( V_311 , L_44 ,
V_324 , V_325 , V_326 , V_327 ) ;
}
#endif
}
T_10 F_331 ( struct V_328 * V_328 , const char T_11 * V_329 ,
T_2 V_330 , T_12 * V_331 )
{
char V_332 [ V_333 + 1 ] , * V_334 ;
int V_76 , V_79 , V_8 , V_335 ;
struct V_14 * V_15 ;
if ( V_330 > V_333 )
return - V_336 ;
if ( F_332 ( & V_332 , V_329 , V_330 ) )
return - V_337 ;
V_332 [ V_333 ] = '\0' ;
V_334 = strchr ( V_332 , ' ' ) ;
if ( ! V_334 )
return - V_336 ;
* V_334 = '\0' ;
V_334 ++ ;
if ( sscanf ( V_334 , L_45 , & V_76 , & V_79 , & V_8 ) != 3 )
return - V_336 ;
F_110 ( & V_126 ) ;
V_335 = - V_336 ;
F_58 (cachep, &slab_caches, list) {
if ( ! strcmp ( V_15 -> V_54 , V_332 ) ) {
if ( V_76 < 1 || V_79 < 1 ||
V_79 > V_76 || V_8 < 0 ) {
V_335 = 0 ;
} else {
V_335 = F_314 ( V_15 , V_76 ,
V_79 , V_8 ,
V_108 ) ;
}
break;
}
}
F_111 ( & V_126 ) ;
if ( V_335 >= 0 )
V_335 = V_330 ;
return V_335 ;
}
static inline int F_333 ( unsigned long * V_84 , unsigned long V_338 )
{
unsigned long * V_243 ;
int V_339 ;
if ( ! V_338 )
return 1 ;
V_339 = V_84 [ 1 ] ;
V_243 = V_84 + 2 ;
while ( V_339 ) {
int V_88 = V_339 / 2 ;
unsigned long * V_340 = V_243 + 2 * V_88 ;
if ( * V_340 == V_338 ) {
V_340 [ 1 ] ++ ;
return 1 ;
}
if ( * V_340 > V_338 ) {
V_339 = V_88 ;
} else {
V_243 = V_340 + 2 ;
V_339 -= V_88 + 1 ;
}
}
if ( ++ V_84 [ 1 ] == V_84 [ 0 ] )
return 0 ;
memmove ( V_243 + 2 , V_243 , V_84 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_243 - ( void * ) V_84 ) ) ;
V_243 [ 0 ] = V_338 ;
V_243 [ 1 ] = 1 ;
return 1 ;
}
static void F_334 ( unsigned long * V_84 , struct V_14 * V_291 ,
struct V_22 * V_22 )
{
void * V_243 ;
int V_88 ;
if ( V_84 [ 0 ] == V_84 [ 1 ] )
return;
for ( V_88 = 0 , V_243 = V_22 -> V_33 ; V_88 < V_291 -> V_28 ; V_88 ++ , V_243 += V_291 -> V_19 ) {
if ( F_13 ( V_22 , V_88 ) != V_263 )
continue;
if ( ! F_333 ( V_84 , ( unsigned long ) * F_11 ( V_291 , V_243 ) ) )
return;
}
}
static void F_335 ( struct V_310 * V_311 , unsigned long V_341 )
{
#ifdef F_336
unsigned long V_34 , V_19 ;
char V_342 [ V_343 ] , V_54 [ V_344 ] ;
if ( F_337 ( V_341 , & V_19 , & V_34 , V_342 , V_54 ) == 0 ) {
F_329 ( V_311 , L_46 , V_54 , V_34 , V_19 ) ;
if ( V_342 [ 0 ] )
F_329 ( V_311 , L_47 , V_342 ) ;
return;
}
#endif
F_329 ( V_311 , L_48 , ( void * ) V_341 ) ;
}
static int F_338 ( struct V_310 * V_311 , void * V_243 )
{
struct V_14 * V_15 = F_215 ( V_243 , struct V_14 , V_103 ) ;
struct V_22 * V_22 ;
struct V_3 * V_84 ;
const char * V_54 ;
unsigned long * V_261 = V_311 -> V_345 ;
int V_64 ;
int V_88 ;
if ( ! ( V_15 -> V_16 & V_18 ) )
return 0 ;
if ( ! ( V_15 -> V_16 & V_17 ) )
return 0 ;
V_261 [ 1 ] = 0 ;
F_140 (cachep, node, n) {
F_206 () ;
F_99 ( & V_84 -> V_11 ) ;
F_58 (page, &n->slabs_full, lru)
F_334 ( V_261 , V_15 , V_22 ) ;
F_58 (page, &n->slabs_partial, lru)
F_334 ( V_261 , V_15 , V_22 ) ;
F_88 ( & V_84 -> V_11 ) ;
}
V_54 = V_15 -> V_54 ;
if ( V_261 [ 0 ] == V_261 [ 1 ] ) {
F_111 ( & V_126 ) ;
V_311 -> V_345 = F_339 ( V_261 [ 0 ] * 4 * sizeof( unsigned long ) , V_108 ) ;
if ( ! V_311 -> V_345 ) {
V_311 -> V_345 = V_261 ;
F_110 ( & V_126 ) ;
return - V_109 ;
}
* ( unsigned long * ) V_311 -> V_345 = V_261 [ 0 ] * 2 ;
F_80 ( V_261 ) ;
F_110 ( & V_126 ) ;
V_311 -> V_330 = V_311 -> V_19 ;
return 0 ;
}
for ( V_88 = 0 ; V_88 < V_261 [ 1 ] ; V_88 ++ ) {
F_329 ( V_311 , L_49 , V_54 , V_261 [ 2 * V_88 + 3 ] ) ;
F_335 ( V_311 , V_261 [ 2 * V_88 + 2 ] ) ;
F_340 ( V_311 , '\n' ) ;
}
return 0 ;
}
static int F_341 ( struct V_346 * V_346 , struct V_328 * V_328 )
{
unsigned long * V_84 ;
V_84 = F_342 ( V_328 , & V_347 , V_49 ) ;
if ( ! V_84 )
return - V_109 ;
* V_84 = V_49 / ( 2 * sizeof( unsigned long ) ) ;
return 0 ;
}
static int T_3 F_343 ( void )
{
#ifdef V_40
F_344 ( L_50 , 0 , NULL , & V_348 ) ;
#endif
return 0 ;
}
T_2 F_345 ( const void * V_1 )
{
F_9 ( ! V_1 ) ;
if ( F_41 ( V_1 == V_349 ) )
return 0 ;
return F_14 ( V_1 ) -> V_206 ;
}
