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
return V_15 -> V_37 [ F_20 () ] ;
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
static void * F_66 ( struct V_14 * V_15 , struct V_36 * V_75 ,
void * V_1 )
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
static struct V_94 * F_75 ( int V_64 , int V_81 ,
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
V_100 = F_76 ( V_83 , V_82 , V_64 ) ;
if ( ! V_100 )
return NULL ;
F_77 (i) {
if ( V_88 == V_64 || ! F_78 ( V_88 ) )
continue;
V_100 [ V_88 ] = F_75 ( V_64 , V_76 , 0xbaadf00d , V_82 ) ;
if ( ! V_100 [ V_88 ] ) {
for ( V_88 -- ; V_88 >= 0 ; V_88 -- )
F_79 ( V_100 [ V_88 ] ) ;
F_79 ( V_100 ) ;
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
F_77 (i)
F_79 ( V_100 [ V_88 ] ) ;
F_79 ( V_100 ) ;
}
static void F_80 ( struct V_14 * V_15 ,
struct V_36 * V_75 , int V_64 ,
struct V_102 * V_103 )
{
struct V_3 * V_84 = F_55 ( V_15 , V_64 ) ;
if ( V_75 -> V_78 ) {
F_81 ( & V_84 -> V_11 ) ;
if ( V_84 -> V_8 )
F_68 ( V_84 -> V_8 , V_75 , V_75 -> V_76 ) ;
F_82 ( V_15 , V_75 -> V_89 , V_75 -> V_78 , V_64 , V_103 ) ;
V_75 -> V_78 = 0 ;
F_83 ( & V_84 -> V_11 ) ;
}
}
static void F_84 ( struct V_14 * V_15 , struct V_3 * V_84 )
{
int V_64 = F_40 ( V_67 ) ;
if ( V_84 -> V_9 ) {
struct V_94 * V_98 = V_84 -> V_9 [ V_64 ] ;
struct V_36 * V_75 ;
if ( V_98 ) {
V_75 = & V_98 -> V_75 ;
if ( V_75 -> V_78 && F_85 ( & V_98 -> V_99 ) ) {
F_86 ( V_103 ) ;
F_80 ( V_15 , V_75 , V_64 , & V_103 ) ;
F_87 ( & V_98 -> V_99 ) ;
F_88 ( V_15 , & V_103 ) ;
}
}
}
}
static void F_89 ( struct V_14 * V_15 ,
struct V_94 * * V_9 )
{
int V_88 = 0 ;
struct V_94 * V_98 ;
struct V_36 * V_75 ;
unsigned long V_16 ;
F_90 (i) {
V_98 = V_9 [ V_88 ] ;
if ( V_98 ) {
F_86 ( V_103 ) ;
V_75 = & V_98 -> V_75 ;
F_57 ( & V_98 -> V_99 , V_16 ) ;
F_80 ( V_15 , V_75 , V_88 , & V_103 ) ;
F_59 ( & V_98 -> V_99 , V_16 ) ;
F_88 ( V_15 , & V_103 ) ;
}
}
}
static inline int F_72 ( struct V_14 * V_15 , void * V_1 )
{
int V_97 = F_91 ( F_92 ( V_1 ) ) ;
struct V_3 * V_84 ;
struct V_94 * V_9 = NULL ;
struct V_36 * V_75 ;
int V_64 ;
F_86 ( V_103 ) ;
V_64 = F_56 () ;
if ( F_93 ( V_97 == V_64 ) )
return 0 ;
V_84 = F_55 ( V_15 , V_64 ) ;
F_94 ( V_15 ) ;
if ( V_84 -> V_9 && V_84 -> V_9 [ V_97 ] ) {
V_9 = V_84 -> V_9 [ V_97 ] ;
V_75 = & V_9 -> V_75 ;
F_81 ( & V_9 -> V_99 ) ;
if ( F_41 ( V_75 -> V_78 == V_75 -> V_76 ) ) {
F_95 ( V_15 ) ;
F_80 ( V_15 , V_75 , V_97 , & V_103 ) ;
}
F_67 ( V_15 , V_75 , V_1 ) ;
F_83 ( & V_9 -> V_99 ) ;
F_88 ( V_15 , & V_103 ) ;
} else {
V_84 = F_55 ( V_15 , V_97 ) ;
F_81 ( & V_84 -> V_11 ) ;
F_82 ( V_15 , & V_1 , 1 , V_97 , & V_103 ) ;
F_83 ( & V_84 -> V_11 ) ;
F_88 ( V_15 , & V_103 ) ;
}
return 1 ;
}
static int F_96 ( int V_64 )
{
struct V_14 * V_15 ;
struct V_3 * V_84 ;
const T_2 V_83 = sizeof( struct V_3 ) ;
F_58 (cachep, &slab_caches, list) {
V_84 = F_55 ( V_15 , V_64 ) ;
if ( ! V_84 ) {
V_84 = F_51 ( V_83 , V_104 , V_64 ) ;
if ( ! V_84 )
return - V_105 ;
F_4 ( V_84 ) ;
V_84 -> V_106 = V_107 + V_108 +
( ( unsigned long ) V_15 ) % V_108 ;
V_15 -> V_64 [ V_64 ] = V_84 ;
}
F_97 ( & V_84 -> V_11 ) ;
V_84 -> V_109 =
( 1 + F_98 ( V_64 ) ) *
V_15 -> V_79 + V_15 -> V_28 ;
F_87 ( & V_84 -> V_11 ) ;
}
return 0 ;
}
static inline int F_99 ( struct V_14 * V_15 ,
struct V_3 * V_84 )
{
return ( V_84 -> V_12 + V_15 -> V_28 - 1 ) / V_15 -> V_28 ;
}
static void F_100 ( long V_63 )
{
struct V_14 * V_15 ;
struct V_3 * V_84 = NULL ;
int V_64 = F_36 ( V_63 ) ;
const struct V_110 * V_111 = F_101 ( V_64 ) ;
F_58 (cachep, &slab_caches, list) {
struct V_36 * V_112 ;
struct V_36 * V_8 ;
struct V_94 * * V_9 ;
F_86 ( V_103 ) ;
V_112 = V_15 -> V_37 [ V_63 ] ;
V_15 -> V_37 [ V_63 ] = NULL ;
V_84 = F_55 ( V_15 , V_64 ) ;
if ( ! V_84 )
goto V_113;
F_97 ( & V_84 -> V_11 ) ;
V_84 -> V_109 -= V_15 -> V_79 ;
if ( V_112 )
F_82 ( V_15 , V_112 -> V_89 , V_112 -> V_78 , V_64 , & V_103 ) ;
if ( ! F_102 ( V_111 ) ) {
F_87 ( & V_84 -> V_11 ) ;
goto V_113;
}
V_8 = V_84 -> V_8 ;
if ( V_8 ) {
F_82 ( V_15 , V_8 -> V_89 ,
V_8 -> V_78 , V_64 , & V_103 ) ;
V_84 -> V_8 = NULL ;
}
V_9 = V_84 -> V_9 ;
V_84 -> V_9 = NULL ;
F_87 ( & V_84 -> V_11 ) ;
F_79 ( V_8 ) ;
if ( V_9 ) {
F_89 ( V_15 , V_9 ) ;
F_71 ( V_9 ) ;
}
V_113:
F_88 ( V_15 , & V_103 ) ;
F_79 ( V_112 ) ;
}
F_58 (cachep, &slab_caches, list) {
V_84 = F_55 ( V_15 , V_64 ) ;
if ( ! V_84 )
continue;
F_103 ( V_15 , V_84 , F_99 ( V_15 , V_84 ) ) ;
}
}
static int F_104 ( long V_63 )
{
struct V_14 * V_15 ;
struct V_3 * V_84 = NULL ;
int V_64 = F_36 ( V_63 ) ;
int V_114 ;
V_114 = F_96 ( V_64 ) ;
if ( V_114 < 0 )
goto V_115;
F_58 (cachep, &slab_caches, list) {
struct V_36 * V_112 ;
struct V_36 * V_8 = NULL ;
struct V_94 * * V_9 = NULL ;
V_112 = F_50 ( V_64 , V_15 -> V_76 ,
V_15 -> V_79 , V_104 ) ;
if ( ! V_112 )
goto V_115;
if ( V_15 -> V_8 ) {
V_8 = F_50 ( V_64 ,
V_15 -> V_8 * V_15 -> V_79 ,
0xbaadf00d , V_104 ) ;
if ( ! V_8 ) {
F_79 ( V_112 ) ;
goto V_115;
}
}
if ( V_58 ) {
V_9 = F_70 ( V_64 , V_15 -> V_76 , V_104 ) ;
if ( ! V_9 ) {
F_79 ( V_8 ) ;
F_79 ( V_112 ) ;
goto V_115;
}
}
V_15 -> V_37 [ V_63 ] = V_112 ;
V_84 = F_55 ( V_15 , V_64 ) ;
F_9 ( ! V_84 ) ;
F_97 ( & V_84 -> V_11 ) ;
if ( ! V_84 -> V_8 ) {
V_84 -> V_8 = V_8 ;
V_8 = NULL ;
}
#ifdef F_105
if ( ! V_84 -> V_9 ) {
V_84 -> V_9 = V_9 ;
V_9 = NULL ;
}
#endif
F_87 ( & V_84 -> V_11 ) ;
F_79 ( V_8 ) ;
F_71 ( V_9 ) ;
}
return 0 ;
V_115:
F_100 ( V_63 ) ;
return - V_105 ;
}
static int F_106 ( struct V_116 * V_117 ,
unsigned long V_118 , void * V_119 )
{
long V_63 = ( long ) V_119 ;
int V_114 = 0 ;
switch ( V_118 ) {
case V_120 :
case V_121 :
F_107 ( & V_122 ) ;
V_114 = F_104 ( V_63 ) ;
F_108 ( & V_122 ) ;
break;
case V_123 :
case V_124 :
F_43 ( V_63 ) ;
break;
#ifdef F_109
case V_125 :
case V_126 :
F_110 ( & F_38 ( V_70 , V_63 ) ) ;
F_38 ( V_70 , V_63 ) . V_71 . V_72 = NULL ;
break;
case V_127 :
case V_128 :
F_43 ( V_63 ) ;
break;
case V_129 :
case V_130 :
#endif
case V_131 :
case V_132 :
F_107 ( & V_122 ) ;
F_100 ( V_63 ) ;
F_108 ( & V_122 ) ;
break;
}
return F_111 ( V_114 ) ;
}
static int T_5 F_112 ( int V_64 )
{
struct V_14 * V_15 ;
int V_133 = 0 ;
F_58 (cachep, &slab_caches, list) {
struct V_3 * V_84 ;
V_84 = F_55 ( V_15 , V_64 ) ;
if ( ! V_84 )
continue;
F_103 ( V_15 , V_84 , F_99 ( V_15 , V_84 ) ) ;
if ( ! F_62 ( & V_84 -> V_5 ) ||
! F_62 ( & V_84 -> V_6 ) ) {
V_133 = - V_134 ;
break;
}
}
return V_133 ;
}
static int T_5 F_113 ( struct V_116 * V_135 ,
unsigned long V_118 , void * V_136 )
{
struct V_137 * V_138 = V_136 ;
int V_133 = 0 ;
int V_139 ;
V_139 = V_138 -> V_140 ;
if ( V_139 < 0 )
goto V_86;
switch ( V_118 ) {
case V_141 :
F_107 ( & V_122 ) ;
V_133 = F_96 ( V_139 ) ;
F_108 ( & V_122 ) ;
break;
case V_142 :
F_107 ( & V_122 ) ;
V_133 = F_112 ( V_139 ) ;
F_108 ( & V_122 ) ;
break;
case V_143 :
case V_144 :
case V_145 :
case V_146 :
break;
}
V_86:
return F_111 ( V_133 ) ;
}
static void T_3 F_114 ( struct V_14 * V_15 , struct V_3 * V_103 ,
int V_97 )
{
struct V_3 * V_147 ;
V_147 = F_51 ( sizeof( struct V_3 ) , V_148 , V_97 ) ;
F_9 ( ! V_147 ) ;
memcpy ( V_147 , V_103 , sizeof( struct V_3 ) ) ;
F_6 ( & V_147 -> V_11 ) ;
F_115 ( V_15 , V_147 , V_97 ) ;
V_15 -> V_64 [ V_97 ] = V_147 ;
}
static void T_3 F_116 ( struct V_14 * V_15 , int V_149 )
{
int V_64 ;
F_90 (node) {
V_15 -> V_64 [ V_64 ] = & V_150 [ V_149 + V_64 ] ;
V_15 -> V_64 [ V_64 ] -> V_106 = V_107 +
V_108 +
( ( unsigned long ) V_15 ) % V_108 ;
}
}
static void F_117 ( struct V_14 * V_15 )
{
V_15 -> V_64 = (struct V_3 * * ) & V_15 -> V_37 [ V_151 ] ;
}
void T_3 F_118 ( void )
{
int V_88 ;
F_119 ( sizeof( ( (struct V_22 * ) NULL ) -> V_152 ) <
sizeof( struct V_153 ) ) ;
V_14 = & V_154 ;
F_117 ( V_14 ) ;
if ( F_120 () == 1 )
V_58 = 0 ;
for ( V_88 = 0 ; V_88 < V_155 ; V_88 ++ )
F_4 ( & V_150 [ V_88 ] ) ;
F_116 ( V_14 , V_156 ) ;
if ( ! V_62 && V_157 > ( 32 << 20 ) >> V_158 )
V_60 = V_159 ;
F_121 ( V_14 , L_2 ,
F_122 ( struct V_14 , V_37 [ V_151 ] ) +
V_101 * sizeof( struct V_3 * ) ,
V_160 ) ;
F_123 ( & V_14 -> V_103 , & V_161 ) ;
V_162 [ V_163 ] = F_124 ( L_3 ,
F_125 ( V_163 ) , V_164 ) ;
if ( V_163 != V_165 )
V_162 [ V_165 ] =
F_124 ( L_4 ,
F_125 ( V_165 ) , V_164 ) ;
V_166 = 0 ;
{
struct V_36 * V_147 ;
V_147 = F_126 ( sizeof( struct V_167 ) , V_148 ) ;
memcpy ( V_147 , F_19 ( V_14 ) ,
sizeof( struct V_167 ) ) ;
V_14 -> V_37 [ F_20 () ] = V_147 ;
V_147 = F_126 ( sizeof( struct V_167 ) , V_148 ) ;
F_9 ( F_19 ( V_162 [ V_163 ] )
!= & V_168 . V_32 ) ;
memcpy ( V_147 , F_19 ( V_162 [ V_163 ] ) ,
sizeof( struct V_167 ) ) ;
V_162 [ V_163 ] -> V_37 [ F_20 () ] = V_147 ;
}
{
int V_139 ;
F_90 (nid) {
F_114 ( V_14 , & V_150 [ V_156 + V_139 ] , V_139 ) ;
F_114 ( V_162 [ V_163 ] ,
& V_150 [ V_169 + V_139 ] , V_139 ) ;
if ( V_163 != V_165 ) {
F_114 ( V_162 [ V_165 ] ,
& V_150 [ V_170 + V_139 ] , V_139 ) ;
}
}
}
F_127 ( V_164 ) ;
}
void T_3 F_128 ( void )
{
struct V_14 * V_15 ;
V_171 = V_172 ;
F_107 ( & V_122 ) ;
F_58 (cachep, &slab_caches, list)
if ( F_129 ( V_15 , V_148 ) )
F_130 () ;
F_108 ( & V_122 ) ;
V_171 = V_173 ;
F_131 ( & V_174 ) ;
#ifdef F_105
F_132 ( F_113 , V_175 ) ;
#endif
}
static int T_3 F_133 ( void )
{
int V_63 ;
F_134 (cpu)
F_43 ( V_63 ) ;
V_171 = V_173 ;
return 0 ;
}
static T_6 void
F_135 ( struct V_14 * V_15 , T_4 V_176 , int V_97 )
{
#if V_177
struct V_3 * V_84 ;
struct V_22 * V_22 ;
unsigned long V_16 ;
int V_64 ;
static F_136 ( V_178 , V_179 ,
V_180 ) ;
if ( ( V_176 & V_181 ) || ! F_137 ( & V_178 ) )
return;
F_27 ( V_182
L_5 ,
V_97 , V_176 ) ;
F_27 ( V_182 L_6 ,
V_15 -> V_54 , V_15 -> V_19 , V_15 -> V_46 ) ;
F_138 (cachep, node, n) {
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
L_7 ,
V_64 , V_185 , V_186 , V_183 , V_184 ,
V_12 ) ;
}
#endif
}
static struct V_22 * F_139 ( struct V_14 * V_15 , T_4 V_16 ,
int V_97 )
{
struct V_22 * V_22 ;
int V_188 ;
V_16 |= V_15 -> V_189 ;
if ( V_15 -> V_16 & V_190 )
V_16 |= V_191 ;
if ( F_140 ( V_15 , V_16 , V_15 -> V_46 ) )
return NULL ;
V_22 = F_141 ( V_97 , V_16 | V_192 , V_15 -> V_46 ) ;
if ( ! V_22 ) {
F_142 ( V_15 , V_15 -> V_46 ) ;
F_135 ( V_15 , V_16 , V_97 ) ;
return NULL ;
}
if ( F_41 ( V_22 -> V_193 ) )
V_85 = true ;
V_188 = ( 1 << V_15 -> V_46 ) ;
if ( V_15 -> V_16 & V_190 )
F_143 ( F_144 ( V_22 ) ,
V_194 , V_188 ) ;
else
F_143 ( F_144 ( V_22 ) ,
V_195 , V_188 ) ;
F_145 ( V_22 ) ;
if ( V_22 -> V_193 )
F_146 ( V_22 ) ;
if ( V_196 && ! ( V_15 -> V_16 & V_197 ) ) {
F_147 ( V_22 , V_15 -> V_46 , V_16 , V_97 ) ;
if ( V_15 -> V_198 )
F_148 ( V_22 , V_188 ) ;
else
F_149 ( V_22 , V_188 ) ;
}
return V_22 ;
}
static void F_150 ( struct V_14 * V_15 , struct V_22 * V_22 )
{
const unsigned long V_199 = ( 1 << V_15 -> V_46 ) ;
F_151 ( V_22 , V_15 -> V_46 ) ;
if ( V_15 -> V_16 & V_190 )
F_152 ( F_144 ( V_22 ) ,
V_194 , V_199 ) ;
else
F_152 ( F_144 ( V_22 ) ,
V_195 , V_199 ) ;
F_9 ( ! F_153 ( V_22 ) ) ;
F_154 ( V_22 ) ;
F_155 ( V_22 ) ;
F_156 ( V_22 ) ;
V_22 -> V_200 = NULL ;
if ( V_201 -> V_202 )
V_201 -> V_202 -> V_203 += V_199 ;
F_157 ( V_22 , V_15 -> V_46 ) ;
F_142 ( V_15 , V_15 -> V_46 ) ;
}
static void F_158 ( struct V_153 * V_204 )
{
struct V_14 * V_15 ;
struct V_22 * V_22 ;
V_22 = F_159 ( V_204 , struct V_22 , V_153 ) ;
V_15 = V_22 -> V_27 ;
F_150 ( V_15 , V_22 ) ;
}
static void F_160 ( struct V_14 * V_15 , unsigned long * V_205 ,
unsigned long V_206 )
{
int V_19 = V_15 -> V_207 ;
V_205 = ( unsigned long * ) & ( ( char * ) V_205 ) [ F_7 ( V_15 ) ] ;
if ( V_19 < 5 * sizeof( unsigned long ) )
return;
* V_205 ++ = 0x12345678 ;
* V_205 ++ = V_206 ;
* V_205 ++ = F_20 () ;
V_19 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_208 = & V_206 ;
unsigned long V_209 ;
while ( ! F_161 ( V_208 ) ) {
V_209 = * V_208 ++ ;
if ( F_162 ( V_209 ) ) {
* V_205 ++ = V_209 ;
V_19 -= sizeof( unsigned long ) ;
if ( V_19 <= sizeof( unsigned long ) )
break;
}
}
}
* V_205 ++ = 0x87654321 ;
}
static void F_163 ( struct V_14 * V_15 , void * V_205 , unsigned char V_24 )
{
int V_19 = V_15 -> V_207 ;
V_205 = & ( ( char * ) V_205 ) [ F_7 ( V_15 ) ] ;
memset ( V_205 , V_24 , V_19 ) ;
* ( unsigned char * ) ( V_205 + V_19 - 1 ) = V_210 ;
}
static void F_164 ( char * V_211 , int V_34 , int V_76 )
{
int V_88 ;
unsigned char error = 0 ;
int V_212 = 0 ;
F_27 ( V_53 L_8 , V_34 ) ;
for ( V_88 = 0 ; V_88 < V_76 ; V_88 ++ ) {
if ( V_211 [ V_34 + V_88 ] != V_213 ) {
error = V_211 [ V_34 + V_88 ] ;
V_212 ++ ;
}
}
F_165 ( V_214 , L_9 , 0 , 16 , 1 ,
& V_211 [ V_34 ] , V_76 , 1 ) ;
if ( V_212 == 1 ) {
error ^= V_213 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_27 ( V_53 L_10
L_11 ) ;
#ifdef F_166
F_27 ( V_53 L_12
L_13 ) ;
#else
F_27 ( V_53 L_14 ) ;
#endif
}
}
}
static void F_167 ( struct V_14 * V_15 , void * V_1 , int V_215 )
{
int V_88 , V_19 ;
char * V_216 ;
if ( V_15 -> V_16 & V_17 ) {
F_27 ( V_53 L_15 ,
* F_8 ( V_15 , V_1 ) ,
* F_10 ( V_15 , V_1 ) ) ;
}
if ( V_15 -> V_16 & V_18 ) {
F_27 ( V_53 L_16 ,
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
F_164 ( V_216 , V_88 , V_76 ) ;
}
}
static void F_168 ( struct V_14 * V_15 , void * V_1 )
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
L_17 ,
F_169 () , V_15 -> V_54 , V_216 , V_19 ) ;
F_167 ( V_15 , V_1 , 0 ) ;
}
V_88 = ( V_88 / 16 ) * 16 ;
V_76 = 16 ;
if ( V_88 + V_76 > V_19 )
V_76 = V_19 - V_88 ;
F_164 ( V_216 , V_88 , V_76 ) ;
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
F_27 ( V_53 L_18 ,
V_216 , V_19 ) ;
F_167 ( V_15 , V_1 , 2 ) ;
}
if ( V_217 + 1 < V_15 -> V_28 ) {
V_1 = F_16 ( V_15 , V_22 , V_217 + 1 ) ;
V_216 = ( char * ) V_1 + F_7 ( V_15 ) ;
F_27 ( V_53 L_19 ,
V_216 , V_19 ) ;
F_167 ( V_15 , V_1 , 2 ) ;
}
}
}
static void F_170 ( struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < V_15 -> V_28 ; V_88 ++ ) {
void * V_1 = F_16 ( V_15 , V_22 , V_88 ) ;
if ( V_15 -> V_16 & V_218 ) {
#ifdef F_171
if ( V_15 -> V_19 % V_49 == 0 &&
F_172 ( V_15 ) )
F_173 ( F_92 ( V_1 ) ,
V_15 -> V_19 / V_49 , 1 ) ;
else
F_168 ( V_15 , V_1 ) ;
#else
F_168 ( V_15 , V_1 ) ;
#endif
}
if ( V_15 -> V_16 & V_17 ) {
if ( * F_8 ( V_15 , V_1 ) != V_219 )
F_174 ( V_15 , L_20
L_21 ) ;
if ( * F_10 ( V_15 , V_1 ) != V_219 )
F_174 ( V_15 , L_22
L_21 ) ;
}
}
}
static void F_170 ( struct V_14 * V_15 ,
struct V_22 * V_22 )
{
}
static void F_175 ( struct V_14 * V_15 , struct V_22 * V_22 )
{
void * V_30 ;
V_30 = V_22 -> V_30 ;
F_170 ( V_15 , V_22 ) ;
if ( F_41 ( V_15 -> V_16 & V_220 ) ) {
struct V_153 * V_204 ;
V_204 = ( void * ) & V_22 -> V_153 ;
F_176 ( V_204 , F_158 ) ;
} else {
F_150 ( V_15 , V_22 ) ;
}
if ( F_172 ( V_15 ) )
F_177 ( V_15 -> V_221 , V_30 ) ;
}
static void F_88 ( struct V_14 * V_15 , struct V_102 * V_103 )
{
struct V_22 * V_22 , * V_84 ;
F_178 (page, n, list, lru) {
F_179 ( & V_22 -> V_152 ) ;
F_175 ( V_15 , V_22 ) ;
}
}
static T_2 F_180 ( struct V_14 * V_15 ,
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
static int T_7 F_181 ( struct V_14 * V_15 , T_4 V_82 )
{
if ( V_171 >= V_173 )
return F_129 ( V_15 , V_82 ) ;
if ( V_171 == V_227 ) {
V_15 -> V_37 [ F_20 () ] = & V_168 . V_32 ;
V_171 = V_228 ;
} else if ( V_171 == V_228 ) {
V_15 -> V_37 [ F_20 () ] = & V_168 . V_32 ;
F_116 ( V_15 , V_169 ) ;
if ( V_163 == V_165 )
V_171 = V_229 ;
else
V_171 = V_230 ;
} else {
V_15 -> V_37 [ F_20 () ] =
F_126 ( sizeof( struct V_167 ) , V_82 ) ;
if ( V_171 == V_230 ) {
F_116 ( V_15 , V_170 ) ;
V_171 = V_229 ;
} else {
int V_64 ;
F_90 (node) {
V_15 -> V_64 [ V_64 ] =
F_51 ( sizeof( struct V_3 ) ,
V_82 , V_64 ) ;
F_9 ( ! V_15 -> V_64 [ V_64 ] ) ;
F_4 ( V_15 -> V_64 [ V_64 ] ) ;
}
}
}
V_15 -> V_64 [ F_56 () ] -> V_106 =
V_107 + V_108 +
( ( unsigned long ) V_15 ) % V_108 ;
F_19 ( V_15 ) -> V_78 = 0 ;
F_19 ( V_15 ) -> V_76 = V_231 ;
F_19 ( V_15 ) -> V_79 = 1 ;
F_19 ( V_15 ) -> V_80 = 0 ;
V_15 -> V_79 = 1 ;
V_15 -> V_76 = V_231 ;
return 0 ;
}
int
F_182 ( struct V_14 * V_15 , unsigned long V_16 )
{
T_2 V_47 , V_25 ;
T_2 V_232 = V_21 ;
T_4 V_82 ;
int V_114 ;
T_2 V_19 = V_15 -> V_19 ;
#if V_177
#if V_233
if ( V_19 < 4096 || F_183 ( V_19 - 1 ) == F_183 ( V_19 - 1 + V_20 +
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
V_232 = V_20 ;
V_19 += V_20 - 1 ;
V_19 &= ~ ( V_20 - 1 ) ;
}
if ( V_232 < V_15 -> V_39 ) {
V_232 = V_15 -> V_39 ;
}
if ( V_232 > F_184 (unsigned long long) )
V_16 &= ~ ( V_17 | V_18 ) ;
V_15 -> V_39 = V_232 ;
if ( F_185 () )
V_82 = V_104 ;
else
V_82 = V_148 ;
F_117 ( V_15 ) ;
#if V_177
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
#if V_233 && F_186 ( F_171 )
if ( V_19 >= F_125 ( V_165 + 1 )
&& V_15 -> V_207 > F_187 ()
&& F_23 ( V_19 , V_15 -> V_39 ) < V_49 ) {
V_15 -> F_7 += V_49 - F_23 ( V_19 , V_15 -> V_39 ) ;
V_19 = V_49 ;
}
#endif
#endif
if ( ( V_19 >= ( V_49 >> 5 ) ) && ! V_166 &&
! ( V_16 & V_234 ) )
V_16 |= V_50 ;
V_19 = F_23 ( V_19 , V_15 -> V_39 ) ;
if ( V_235 && V_19 < V_236 )
V_19 = F_23 ( V_236 , V_15 -> V_39 ) ;
V_47 = F_180 ( V_15 , V_19 , V_15 -> V_39 , V_16 ) ;
if ( ! V_15 -> V_28 )
return - V_237 ;
V_25 = F_21 ( V_15 -> V_28 , V_15 -> V_39 ) ;
if ( V_16 & V_50 && V_47 >= V_25 ) {
V_16 &= ~ V_50 ;
V_47 -= V_25 ;
}
if ( V_16 & V_50 ) {
V_25 = F_21 ( V_15 -> V_28 , 0 ) ;
#ifdef F_188
if ( V_19 % V_49 == 0 && V_16 & V_218 )
V_16 &= ~ ( V_17 | V_18 ) ;
#endif
}
V_15 -> V_238 = F_187 () ;
if ( V_15 -> V_238 < V_15 -> V_39 )
V_15 -> V_238 = V_15 -> V_39 ;
V_15 -> V_239 = V_47 / V_15 -> V_238 ;
V_15 -> V_25 = V_25 ;
V_15 -> V_16 = V_16 ;
V_15 -> V_189 = V_240 ;
if ( V_241 && ( V_16 & V_242 ) )
V_15 -> V_189 |= V_243 ;
V_15 -> V_19 = V_19 ;
V_15 -> V_35 = F_189 ( V_19 ) ;
if ( V_16 & V_50 ) {
V_15 -> V_221 = F_190 ( V_25 , 0u ) ;
F_9 ( F_191 ( V_15 -> V_221 ) ) ;
}
V_114 = F_181 ( V_15 , V_82 ) ;
if ( V_114 ) {
F_192 ( V_15 ) ;
return V_114 ;
}
return 0 ;
}
static void F_193 ( void )
{
F_9 ( ! F_194 () ) ;
}
static void F_195 ( void )
{
F_9 ( F_194 () ) ;
}
static void F_196 ( struct V_14 * V_15 )
{
#ifdef F_197
F_193 () ;
F_198 ( & F_55 ( V_15 , F_56 () ) -> V_11 ) ;
#endif
}
static void F_199 ( struct V_14 * V_15 , int V_64 )
{
#ifdef F_197
F_193 () ;
F_198 ( & F_55 ( V_15 , V_64 ) -> V_11 ) ;
#endif
}
static void F_200 ( void * V_136 )
{
struct V_14 * V_15 = V_136 ;
struct V_36 * V_75 ;
int V_64 = F_56 () ;
struct V_3 * V_84 ;
F_86 ( V_103 ) ;
F_193 () ;
V_75 = F_19 ( V_15 ) ;
V_84 = F_55 ( V_15 , V_64 ) ;
F_81 ( & V_84 -> V_11 ) ;
F_82 ( V_15 , V_75 -> V_89 , V_75 -> V_78 , V_64 , & V_103 ) ;
F_83 ( & V_84 -> V_11 ) ;
F_88 ( V_15 , & V_103 ) ;
V_75 -> V_78 = 0 ;
}
static void F_201 ( struct V_14 * V_15 )
{
struct V_3 * V_84 ;
int V_64 ;
F_202 ( F_200 , V_15 , 1 ) ;
F_195 () ;
F_138 (cachep, node, n)
if ( V_84 -> V_9 )
F_89 ( V_15 , V_84 -> V_9 ) ;
F_138 (cachep, node, n)
F_203 ( V_15 , V_84 , V_84 -> V_8 , 1 , V_64 ) ;
}
static int F_103 ( struct V_14 * V_32 ,
struct V_3 * V_84 , int V_244 )
{
struct V_102 * V_245 ;
int V_199 ;
struct V_22 * V_22 ;
V_199 = 0 ;
while ( V_199 < V_244 && ! F_62 ( & V_84 -> V_7 ) ) {
F_97 ( & V_84 -> V_11 ) ;
V_245 = V_84 -> V_7 . V_246 ;
if ( V_245 == & V_84 -> V_7 ) {
F_87 ( & V_84 -> V_11 ) ;
goto V_86;
}
V_22 = F_204 ( V_245 , struct V_22 , V_152 ) ;
#if V_177
F_9 ( V_22 -> V_187 ) ;
#endif
F_179 ( & V_22 -> V_152 ) ;
V_84 -> V_12 -= V_32 -> V_28 ;
F_87 ( & V_84 -> V_11 ) ;
F_175 ( V_32 , V_22 ) ;
V_199 ++ ;
}
V_86:
return V_199 ;
}
int F_205 ( struct V_14 * V_15 )
{
int V_133 = 0 ;
int V_64 ;
struct V_3 * V_84 ;
F_201 ( V_15 ) ;
F_195 () ;
F_138 (cachep, node, n) {
F_103 ( V_15 , V_84 , F_99 ( V_15 , V_84 ) ) ;
V_133 += ! F_62 ( & V_84 -> V_5 ) ||
! F_62 ( & V_84 -> V_6 ) ;
}
return ( V_133 ? 1 : 0 ) ;
}
int F_192 ( struct V_14 * V_15 )
{
int V_88 ;
struct V_3 * V_84 ;
int V_247 = F_205 ( V_15 ) ;
if ( V_247 )
return V_247 ;
F_134 (i)
F_79 ( V_15 -> V_37 [ V_88 ] ) ;
F_138 (cachep, i, n) {
F_79 ( V_84 -> V_8 ) ;
F_71 ( V_84 -> V_9 ) ;
F_79 ( V_84 ) ;
V_15 -> V_64 [ V_88 ] = NULL ;
}
return 0 ;
}
static void * F_206 ( struct V_14 * V_15 ,
struct V_22 * V_22 , int V_238 ,
T_4 V_248 , int V_97 )
{
void * V_30 ;
void * V_205 = F_207 ( V_22 ) ;
if ( F_172 ( V_15 ) ) {
V_30 = F_208 ( V_15 -> V_221 ,
V_248 , V_97 ) ;
if ( ! V_30 )
return NULL ;
} else {
V_30 = V_205 + V_238 ;
V_238 += V_15 -> V_25 ;
}
V_22 -> V_187 = 0 ;
V_22 -> V_33 = V_205 + V_238 ;
return V_30 ;
}
static inline V_29 F_209 ( struct V_22 * V_22 , unsigned int V_23 )
{
return ( ( V_29 * ) V_22 -> V_30 ) [ V_23 ] ;
}
static inline void F_210 ( struct V_22 * V_22 ,
unsigned int V_23 , V_29 V_24 )
{
( ( V_29 * ) ( V_22 -> V_30 ) ) [ V_23 ] = V_24 ;
}
static void F_211 ( struct V_14 * V_15 ,
struct V_22 * V_22 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < V_15 -> V_28 ; V_88 ++ ) {
void * V_1 = F_16 ( V_15 , V_22 , V_88 ) ;
#if V_177
if ( V_15 -> V_16 & V_218 )
F_163 ( V_15 , V_1 , V_213 ) ;
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
F_174 ( V_15 , L_23
L_24 ) ;
if ( * F_8 ( V_15 , V_1 ) != V_219 )
F_174 ( V_15 , L_23
L_25 ) ;
}
if ( ( V_15 -> V_19 % V_49 ) == 0 &&
F_172 ( V_15 ) && V_15 -> V_16 & V_218 )
F_173 ( F_92 ( V_1 ) ,
V_15 -> V_19 / V_49 , 0 ) ;
#else
if ( V_15 -> V_198 )
V_15 -> V_198 ( V_1 ) ;
#endif
F_12 ( V_22 , V_88 , V_249 ) ;
F_210 ( V_22 , V_88 , V_88 ) ;
}
}
static void F_212 ( struct V_14 * V_15 , T_4 V_16 )
{
if ( V_241 ) {
if ( V_16 & V_243 )
F_9 ( ! ( V_15 -> V_189 & V_243 ) ) ;
else
F_9 ( V_15 -> V_189 & V_243 ) ;
}
}
static void * F_213 ( struct V_14 * V_15 , struct V_22 * V_22 ,
int V_97 )
{
void * V_1 ;
V_1 = F_16 ( V_15 , V_22 , F_209 ( V_22 , V_22 -> V_187 ) ) ;
V_22 -> V_187 ++ ;
#if V_177
F_214 ( F_91 ( F_92 ( V_1 ) ) != V_97 ) ;
#endif
return V_1 ;
}
static void F_215 ( struct V_14 * V_15 , struct V_22 * V_22 ,
void * V_1 , int V_97 )
{
unsigned int V_217 = F_17 ( V_15 , V_22 , V_1 ) ;
#if V_177
unsigned int V_88 ;
F_214 ( F_91 ( F_92 ( V_1 ) ) != V_97 ) ;
for ( V_88 = V_22 -> V_187 ; V_88 < V_15 -> V_28 ; V_88 ++ ) {
if ( F_209 ( V_22 , V_88 ) == V_217 ) {
F_27 ( V_53 L_26
L_27 , V_15 -> V_54 , V_1 ) ;
F_130 () ;
}
}
#endif
V_22 -> V_187 -- ;
F_210 ( V_22 , V_22 -> V_187 , V_217 ) ;
}
static void F_216 ( struct V_14 * V_32 , struct V_22 * V_22 ,
void * V_30 )
{
V_22 -> V_27 = V_32 ;
V_22 -> V_30 = V_30 ;
}
static int F_217 ( struct V_14 * V_15 ,
T_4 V_16 , int V_97 , struct V_22 * V_22 )
{
void * V_30 ;
T_2 V_34 ;
T_4 V_248 ;
struct V_3 * V_84 ;
F_9 ( V_16 & V_250 ) ;
V_248 = V_16 & ( V_251 | V_252 ) ;
F_193 () ;
V_84 = F_55 ( V_15 , V_97 ) ;
F_81 ( & V_84 -> V_11 ) ;
V_34 = V_84 -> V_10 ;
V_84 -> V_10 ++ ;
if ( V_84 -> V_10 >= V_15 -> V_239 )
V_84 -> V_10 = 0 ;
F_83 ( & V_84 -> V_11 ) ;
V_34 *= V_15 -> V_238 ;
if ( V_248 & V_253 )
F_218 () ;
F_212 ( V_15 , V_16 ) ;
if ( ! V_22 )
V_22 = F_139 ( V_15 , V_248 , V_97 ) ;
if ( ! V_22 )
goto V_254;
V_30 = F_206 ( V_15 , V_22 , V_34 ,
V_248 & ~ V_251 , V_97 ) ;
if ( ! V_30 )
goto V_255;
F_216 ( V_15 , V_22 , V_30 ) ;
F_211 ( V_15 , V_22 ) ;
if ( V_248 & V_253 )
F_219 () ;
F_193 () ;
F_81 ( & V_84 -> V_11 ) ;
F_220 ( & V_22 -> V_152 , & ( V_84 -> V_7 ) ) ;
F_221 ( V_15 ) ;
V_84 -> V_12 += V_15 -> V_28 ;
F_83 ( & V_84 -> V_11 ) ;
return 1 ;
V_255:
F_150 ( V_15 , V_22 ) ;
V_254:
if ( V_248 & V_253 )
F_219 () ;
return 0 ;
}
static void F_222 ( const void * V_1 )
{
if ( ! F_223 ( V_1 ) ) {
F_27 ( V_53 L_28 ,
( unsigned long ) V_1 ) ;
F_130 () ;
}
}
static inline void F_224 ( struct V_14 * V_32 , void * V_31 )
{
unsigned long long V_256 , V_257 ;
V_256 = * F_8 ( V_32 , V_31 ) ;
V_257 = * F_10 ( V_32 , V_31 ) ;
if ( V_256 == V_258 && V_257 == V_258 )
return;
if ( V_256 == V_219 && V_257 == V_219 )
F_174 ( V_32 , L_29 ) ;
else
F_174 ( V_32 , L_30 ) ;
F_27 ( V_53 L_31 ,
V_31 , V_256 , V_257 ) ;
}
static void * F_225 ( struct V_14 * V_15 , void * V_1 ,
unsigned long V_206 )
{
unsigned int V_217 ;
struct V_22 * V_22 ;
F_9 ( F_14 ( V_1 ) != V_15 ) ;
V_1 -= F_7 ( V_15 ) ;
F_222 ( V_1 ) ;
V_22 = F_15 ( V_1 ) ;
if ( V_15 -> V_16 & V_17 ) {
F_224 ( V_15 , V_1 ) ;
* F_8 ( V_15 , V_1 ) = V_219 ;
* F_10 ( V_15 , V_1 ) = V_219 ;
}
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = ( void * ) V_206 ;
V_217 = F_17 ( V_15 , V_22 , V_1 ) ;
F_9 ( V_217 >= V_15 -> V_28 ) ;
F_9 ( V_1 != F_16 ( V_15 , V_22 , V_217 ) ) ;
F_12 ( V_22 , V_217 , V_249 ) ;
if ( V_15 -> V_16 & V_218 ) {
#ifdef F_171
if ( ( V_15 -> V_19 % V_49 ) == 0 && F_172 ( V_15 ) ) {
F_160 ( V_15 , V_1 , V_206 ) ;
F_173 ( F_92 ( V_1 ) ,
V_15 -> V_19 / V_49 , 0 ) ;
} else {
F_163 ( V_15 , V_1 , V_213 ) ;
}
#else
F_163 ( V_15 , V_1 , V_213 ) ;
#endif
}
return V_1 ;
}
static void * F_226 ( struct V_14 * V_15 , T_4 V_16 ,
bool V_87 )
{
int V_79 ;
struct V_3 * V_84 ;
struct V_36 * V_75 ;
int V_64 ;
F_193 () ;
V_64 = F_56 () ;
if ( F_41 ( V_87 ) )
goto V_259;
V_260:
V_75 = F_19 ( V_15 ) ;
V_79 = V_75 -> V_79 ;
if ( ! V_75 -> V_80 && V_79 > V_261 ) {
V_79 = V_261 ;
}
V_84 = F_55 ( V_15 , V_64 ) ;
F_9 ( V_75 -> V_78 > 0 || ! V_84 ) ;
F_81 ( & V_84 -> V_11 ) ;
if ( V_84 -> V_8 && F_68 ( V_75 , V_84 -> V_8 , V_79 ) ) {
V_84 -> V_8 -> V_80 = 1 ;
goto V_262;
}
while ( V_79 > 0 ) {
struct V_102 * V_89 ;
struct V_22 * V_22 ;
V_89 = V_84 -> V_6 . V_263 ;
if ( V_89 == & V_84 -> V_6 ) {
V_84 -> V_13 = 1 ;
V_89 = V_84 -> V_7 . V_263 ;
if ( V_89 == & V_84 -> V_7 )
goto V_264;
}
V_22 = F_204 ( V_89 , struct V_22 , V_152 ) ;
F_196 ( V_15 ) ;
F_9 ( V_22 -> V_187 >= V_15 -> V_28 ) ;
while ( V_22 -> V_187 < V_15 -> V_28 && V_79 -- ) {
F_227 ( V_15 ) ;
F_228 ( V_15 ) ;
F_229 ( V_15 ) ;
F_67 ( V_15 , V_75 , F_213 ( V_15 , V_22 ,
V_64 ) ) ;
}
F_179 ( & V_22 -> V_152 ) ;
if ( V_22 -> V_187 == V_15 -> V_28 )
F_123 ( & V_22 -> V_152 , & V_84 -> V_5 ) ;
else
F_123 ( & V_22 -> V_152 , & V_84 -> V_6 ) ;
}
V_264:
V_84 -> V_12 -= V_75 -> V_78 ;
V_262:
F_83 ( & V_84 -> V_11 ) ;
if ( F_41 ( ! V_75 -> V_78 ) ) {
int V_265 ;
V_259:
V_265 = F_217 ( V_15 , V_16 | V_266 , V_64 , NULL ) ;
V_75 = F_19 ( V_15 ) ;
V_64 = F_56 () ;
if ( ! V_265 && ( V_75 -> V_78 == 0 || V_87 ) )
return NULL ;
if ( ! V_75 -> V_78 )
goto V_260;
}
V_75 -> V_80 = 1 ;
return F_64 ( V_15 , V_75 , V_16 , V_87 ) ;
}
static inline void F_230 ( struct V_14 * V_15 ,
T_4 V_16 )
{
F_231 ( V_16 & V_253 ) ;
#if V_177
F_212 ( V_15 , V_16 ) ;
#endif
}
static void * F_232 ( struct V_14 * V_15 ,
T_4 V_16 , void * V_1 , unsigned long V_206 )
{
struct V_22 * V_22 ;
if ( ! V_1 )
return V_1 ;
if ( V_15 -> V_16 & V_218 ) {
#ifdef F_171
if ( ( V_15 -> V_19 % V_49 ) == 0 && F_172 ( V_15 ) )
F_173 ( F_92 ( V_1 ) ,
V_15 -> V_19 / V_49 , 1 ) ;
else
F_168 ( V_15 , V_1 ) ;
#else
F_168 ( V_15 , V_1 ) ;
#endif
F_163 ( V_15 , V_1 , V_267 ) ;
}
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = ( void * ) V_206 ;
if ( V_15 -> V_16 & V_17 ) {
if ( * F_8 ( V_15 , V_1 ) != V_219 ||
* F_10 ( V_15 , V_1 ) != V_219 ) {
F_174 ( V_15 , L_32
L_33 ) ;
F_27 ( V_53
L_34 ,
V_1 , * F_8 ( V_15 , V_1 ) ,
* F_10 ( V_15 , V_1 ) ) ;
}
* F_8 ( V_15 , V_1 ) = V_258 ;
* F_10 ( V_15 , V_1 ) = V_258 ;
}
V_22 = F_15 ( V_1 ) ;
F_12 ( V_22 , F_17 ( V_15 , V_22 , V_1 ) , V_268 ) ;
V_1 += F_7 ( V_15 ) ;
if ( V_15 -> V_198 && V_15 -> V_16 & V_218 )
V_15 -> V_198 ( V_1 ) ;
if ( V_269 &&
( ( unsigned long ) V_1 & ( V_269 - 1 ) ) ) {
F_27 ( V_53 L_35 ,
V_1 , ( int ) V_269 ) ;
}
return V_1 ;
}
static bool F_233 ( struct V_14 * V_15 , T_4 V_16 )
{
if ( F_41 ( V_15 == V_14 ) )
return false ;
return F_234 ( V_15 -> V_207 , V_16 , V_15 -> V_16 ) ;
}
static inline void * F_235 ( struct V_14 * V_15 , T_4 V_16 )
{
void * V_1 ;
struct V_36 * V_75 ;
bool V_87 = false ;
F_193 () ;
V_75 = F_19 ( V_15 ) ;
if ( F_93 ( V_75 -> V_78 ) ) {
V_75 -> V_80 = 1 ;
V_1 = F_64 ( V_15 , V_75 , V_16 , false ) ;
if ( V_1 ) {
F_236 ( V_15 ) ;
goto V_86;
}
V_87 = true ;
}
F_237 ( V_15 ) ;
V_1 = F_226 ( V_15 , V_16 , V_87 ) ;
V_75 = F_19 ( V_15 ) ;
V_86:
if ( V_1 )
F_238 ( & V_75 -> V_89 [ V_75 -> V_78 ] ) ;
return V_1 ;
}
static void * F_73 ( struct V_14 * V_15 , T_4 V_16 )
{
int V_270 , V_271 ;
if ( F_239 () || ( V_16 & V_272 ) )
return NULL ;
V_270 = V_271 = F_56 () ;
if ( F_240 () && ( V_15 -> V_16 & V_273 ) )
V_270 = F_241 () ;
else if ( V_201 -> V_274 )
V_270 = F_242 () ;
if ( V_270 != V_271 )
return F_74 ( V_15 , V_16 , V_270 ) ;
return NULL ;
}
static void * F_243 ( struct V_14 * V_32 , T_4 V_16 )
{
struct V_275 * V_275 ;
T_4 V_248 ;
struct V_276 * V_277 ;
struct V_278 * V_278 ;
enum V_279 V_280 = F_244 ( V_16 ) ;
void * V_31 = NULL ;
int V_139 ;
unsigned int V_281 ;
if ( V_16 & V_272 )
return NULL ;
V_248 = V_16 & ( V_251 | V_252 ) ;
V_282:
V_281 = F_245 () ;
V_275 = F_246 ( F_242 () , V_16 ) ;
V_260:
F_247 (zone, z, zonelist, high_zoneidx) {
V_139 = F_248 ( V_278 ) ;
if ( F_249 ( V_278 , V_16 ) &&
F_55 ( V_32 , V_139 ) &&
F_55 ( V_32 , V_139 ) -> V_12 ) {
V_31 = F_74 ( V_32 ,
V_16 | V_266 , V_139 ) ;
if ( V_31 )
break;
}
}
if ( ! V_31 ) {
struct V_22 * V_22 ;
if ( V_248 & V_253 )
F_218 () ;
F_212 ( V_32 , V_16 ) ;
V_22 = F_139 ( V_32 , V_248 , F_56 () ) ;
if ( V_248 & V_253 )
F_219 () ;
if ( V_22 ) {
V_139 = F_91 ( V_22 ) ;
if ( F_217 ( V_32 , V_16 , V_139 , V_22 ) ) {
V_31 = F_74 ( V_32 ,
V_16 | V_266 , V_139 ) ;
if ( ! V_31 )
goto V_260;
} else {
V_31 = NULL ;
}
}
}
if ( F_41 ( ! V_31 && F_250 ( V_281 ) ) )
goto V_282;
return V_31 ;
}
static void * F_74 ( struct V_14 * V_15 , T_4 V_16 ,
int V_97 )
{
struct V_102 * V_89 ;
struct V_22 * V_22 ;
struct V_3 * V_84 ;
void * V_31 ;
int V_265 ;
F_251 ( V_97 > F_252 () ) ;
V_84 = F_55 ( V_15 , V_97 ) ;
F_9 ( ! V_84 ) ;
V_260:
F_193 () ;
F_81 ( & V_84 -> V_11 ) ;
V_89 = V_84 -> V_6 . V_263 ;
if ( V_89 == & V_84 -> V_6 ) {
V_84 -> V_13 = 1 ;
V_89 = V_84 -> V_7 . V_263 ;
if ( V_89 == & V_84 -> V_7 )
goto V_264;
}
V_22 = F_204 ( V_89 , struct V_22 , V_152 ) ;
F_199 ( V_15 , V_97 ) ;
F_253 ( V_15 ) ;
F_228 ( V_15 ) ;
F_229 ( V_15 ) ;
F_9 ( V_22 -> V_187 == V_15 -> V_28 ) ;
V_31 = F_213 ( V_15 , V_22 , V_97 ) ;
V_84 -> V_12 -- ;
F_179 ( & V_22 -> V_152 ) ;
if ( V_22 -> V_187 == V_15 -> V_28 )
F_123 ( & V_22 -> V_152 , & V_84 -> V_5 ) ;
else
F_123 ( & V_22 -> V_152 , & V_84 -> V_6 ) ;
F_83 ( & V_84 -> V_11 ) ;
goto V_283;
V_264:
F_83 ( & V_84 -> V_11 ) ;
V_265 = F_217 ( V_15 , V_16 | V_266 , V_97 , NULL ) ;
if ( V_265 )
goto V_260;
return F_243 ( V_15 , V_16 ) ;
V_283:
return V_31 ;
}
static T_8 void *
F_254 ( struct V_14 * V_15 , T_4 V_16 , int V_97 ,
unsigned long V_206 )
{
unsigned long V_284 ;
void * V_147 ;
int V_285 = F_56 () ;
V_16 &= V_286 ;
F_255 ( V_16 ) ;
if ( F_233 ( V_15 , V_16 ) )
return NULL ;
V_15 = F_256 ( V_15 , V_16 ) ;
F_230 ( V_15 , V_16 ) ;
F_257 ( V_284 ) ;
if ( V_97 == V_287 )
V_97 = V_285 ;
if ( F_41 ( ! F_55 ( V_15 , V_97 ) ) ) {
V_147 = F_243 ( V_15 , V_16 ) ;
goto V_86;
}
if ( V_97 == V_285 ) {
V_147 = F_235 ( V_15 , V_16 ) ;
if ( V_147 )
goto V_86;
}
V_147 = F_74 ( V_15 , V_16 , V_97 ) ;
V_86:
F_258 ( V_284 ) ;
V_147 = F_232 ( V_15 , V_16 , V_147 , V_206 ) ;
F_259 ( V_147 , V_15 -> V_207 , 1 , V_15 -> V_16 ,
V_16 ) ;
if ( F_93 ( V_147 ) ) {
F_260 ( V_15 , V_16 , V_147 , V_15 -> V_207 ) ;
if ( F_41 ( V_16 & V_288 ) )
memset ( V_147 , 0 , V_15 -> V_207 ) ;
}
return V_147 ;
}
static T_8 void *
F_261 ( struct V_14 * V_32 , T_4 V_16 )
{
void * V_1 ;
if ( V_201 -> V_274 || F_240 () ) {
V_1 = F_73 ( V_32 , V_16 ) ;
if ( V_1 )
goto V_86;
}
V_1 = F_235 ( V_32 , V_16 ) ;
if ( ! V_1 )
V_1 = F_74 ( V_32 , V_16 , F_56 () ) ;
V_86:
return V_1 ;
}
static T_8 void *
F_261 ( struct V_14 * V_15 , T_4 V_16 )
{
return F_235 ( V_15 , V_16 ) ;
}
static T_8 void *
F_262 ( struct V_14 * V_15 , T_4 V_16 , unsigned long V_206 )
{
unsigned long V_284 ;
void * V_1 ;
V_16 &= V_286 ;
F_255 ( V_16 ) ;
if ( F_233 ( V_15 , V_16 ) )
return NULL ;
V_15 = F_256 ( V_15 , V_16 ) ;
F_230 ( V_15 , V_16 ) ;
F_257 ( V_284 ) ;
V_1 = F_261 ( V_15 , V_16 ) ;
F_258 ( V_284 ) ;
V_1 = F_232 ( V_15 , V_16 , V_1 , V_206 ) ;
F_259 ( V_1 , V_15 -> V_207 , 1 , V_15 -> V_16 ,
V_16 ) ;
F_263 ( V_1 ) ;
if ( F_93 ( V_1 ) ) {
F_260 ( V_15 , V_16 , V_1 , V_15 -> V_207 ) ;
if ( F_41 ( V_16 & V_288 ) )
memset ( V_1 , 0 , V_15 -> V_207 ) ;
}
return V_1 ;
}
static void F_82 ( struct V_14 * V_15 , void * * V_289 ,
int V_290 , int V_64 , struct V_102 * V_103 )
{
int V_88 ;
struct V_3 * V_84 = F_55 ( V_15 , V_64 ) ;
for ( V_88 = 0 ; V_88 < V_290 ; V_88 ++ ) {
void * V_1 ;
struct V_22 * V_22 ;
F_3 ( & V_289 [ V_88 ] ) ;
V_1 = V_289 [ V_88 ] ;
V_22 = F_15 ( V_1 ) ;
F_179 ( & V_22 -> V_152 ) ;
F_199 ( V_15 , V_64 ) ;
F_215 ( V_15 , V_22 , V_1 , V_64 ) ;
F_264 ( V_15 ) ;
V_84 -> V_12 ++ ;
if ( V_22 -> V_187 == 0 ) {
if ( V_84 -> V_12 > V_84 -> V_109 ) {
V_84 -> V_12 -= V_15 -> V_28 ;
F_220 ( & V_22 -> V_152 , V_103 ) ;
} else {
F_123 ( & V_22 -> V_152 , & V_84 -> V_7 ) ;
}
} else {
F_220 ( & V_22 -> V_152 , & V_84 -> V_6 ) ;
}
}
}
static void F_265 ( struct V_14 * V_15 , struct V_36 * V_75 )
{
int V_79 ;
struct V_3 * V_84 ;
int V_64 = F_56 () ;
F_86 ( V_103 ) ;
V_79 = V_75 -> V_79 ;
#if V_177
F_9 ( ! V_79 || V_79 > V_75 -> V_78 ) ;
#endif
F_193 () ;
V_84 = F_55 ( V_15 , V_64 ) ;
F_81 ( & V_84 -> V_11 ) ;
if ( V_84 -> V_8 ) {
struct V_36 * V_291 = V_84 -> V_8 ;
int V_92 = V_291 -> V_76 - V_291 -> V_78 ;
if ( V_92 ) {
if ( V_79 > V_92 )
V_79 = V_92 ;
memcpy ( & ( V_291 -> V_89 [ V_291 -> V_78 ] ) ,
V_75 -> V_89 , sizeof( void * ) * V_79 ) ;
V_291 -> V_78 += V_79 ;
goto V_292;
}
}
F_82 ( V_15 , V_75 -> V_89 , V_79 , V_64 , & V_103 ) ;
V_292:
#if V_293
{
int V_88 = 0 ;
struct V_102 * V_245 ;
V_245 = V_84 -> V_7 . V_263 ;
while ( V_245 != & ( V_84 -> V_7 ) ) {
struct V_22 * V_22 ;
V_22 = F_204 ( V_245 , struct V_22 , V_152 ) ;
F_9 ( V_22 -> V_187 ) ;
V_88 ++ ;
V_245 = V_245 -> V_263 ;
}
F_266 ( V_15 , V_88 ) ;
}
#endif
F_83 ( & V_84 -> V_11 ) ;
F_88 ( V_15 , & V_103 ) ;
V_75 -> V_78 -= V_79 ;
memmove ( V_75 -> V_89 , & ( V_75 -> V_89 [ V_79 ] ) , sizeof( void * ) * V_75 -> V_78 ) ;
}
static inline void F_267 ( struct V_14 * V_15 , void * V_1 ,
unsigned long V_206 )
{
struct V_36 * V_75 = F_19 ( V_15 ) ;
F_193 () ;
F_268 ( V_1 , V_15 -> V_16 ) ;
V_1 = F_225 ( V_15 , V_1 , V_206 ) ;
F_269 ( V_15 , V_1 , V_15 -> V_207 ) ;
if ( V_294 > 1 && F_72 ( V_15 , V_1 ) )
return;
if ( F_93 ( V_75 -> V_78 < V_75 -> V_76 ) ) {
F_270 ( V_15 ) ;
} else {
F_271 ( V_15 ) ;
F_265 ( V_15 , V_75 ) ;
}
F_67 ( V_15 , V_75 , V_1 ) ;
}
void * F_272 ( struct V_14 * V_15 , T_4 V_16 )
{
void * V_133 = F_262 ( V_15 , V_16 , V_295 ) ;
F_273 ( V_295 , V_133 ,
V_15 -> V_207 , V_15 -> V_19 , V_16 ) ;
return V_133 ;
}
void *
F_274 ( struct V_14 * V_15 , T_4 V_16 , T_2 V_19 )
{
void * V_133 ;
V_133 = F_262 ( V_15 , V_16 , V_295 ) ;
F_275 ( V_295 , V_133 ,
V_19 , V_15 -> V_19 , V_16 ) ;
return V_133 ;
}
void * F_208 ( struct V_14 * V_15 , T_4 V_16 , int V_97 )
{
void * V_133 = F_254 ( V_15 , V_16 , V_97 , V_295 ) ;
F_276 ( V_295 , V_133 ,
V_15 -> V_207 , V_15 -> V_19 ,
V_16 , V_97 ) ;
return V_133 ;
}
void * F_277 ( struct V_14 * V_15 ,
T_4 V_16 ,
int V_97 ,
T_2 V_19 )
{
void * V_133 ;
V_133 = F_254 ( V_15 , V_16 , V_97 , V_295 ) ;
F_278 ( V_295 , V_133 ,
V_19 , V_15 -> V_19 ,
V_16 , V_97 ) ;
return V_133 ;
}
static T_8 void *
F_279 ( T_2 V_19 , T_4 V_16 , int V_64 , unsigned long V_206 )
{
struct V_14 * V_15 ;
V_15 = F_190 ( V_19 , V_16 ) ;
if ( F_41 ( F_191 ( V_15 ) ) )
return V_15 ;
return F_277 ( V_15 , V_16 , V_64 , V_19 ) ;
}
void * F_280 ( T_2 V_19 , T_4 V_16 , int V_64 )
{
return F_279 ( V_19 , V_16 , V_64 , V_295 ) ;
}
void * F_281 ( T_2 V_19 , T_4 V_16 ,
int V_64 , unsigned long V_206 )
{
return F_279 ( V_19 , V_16 , V_64 , V_206 ) ;
}
void * F_280 ( T_2 V_19 , T_4 V_16 , int V_64 )
{
return F_279 ( V_19 , V_16 , V_64 , 0 ) ;
}
static T_8 void * F_282 ( T_2 V_19 , T_4 V_16 ,
unsigned long V_206 )
{
struct V_14 * V_15 ;
void * V_133 ;
V_15 = F_190 ( V_19 , V_16 ) ;
if ( F_41 ( F_191 ( V_15 ) ) )
return V_15 ;
V_133 = F_262 ( V_15 , V_16 , V_206 ) ;
F_275 ( V_206 , V_133 ,
V_19 , V_15 -> V_19 , V_16 ) ;
return V_133 ;
}
void * F_283 ( T_2 V_19 , T_4 V_16 )
{
return F_282 ( V_19 , V_16 , V_295 ) ;
}
void * F_284 ( T_2 V_19 , T_4 V_16 , unsigned long V_206 )
{
return F_282 ( V_19 , V_16 , V_206 ) ;
}
void * F_283 ( T_2 V_19 , T_4 V_16 )
{
return F_282 ( V_19 , V_16 , 0 ) ;
}
void F_177 ( struct V_14 * V_15 , void * V_1 )
{
unsigned long V_16 ;
V_15 = F_285 ( V_15 , V_1 ) ;
if ( ! V_15 )
return;
F_257 ( V_16 ) ;
F_286 ( V_1 , V_15 -> V_207 ) ;
if ( ! ( V_15 -> V_16 & V_296 ) )
F_287 ( V_1 , V_15 -> V_207 ) ;
F_267 ( V_15 , V_1 , V_295 ) ;
F_258 ( V_16 ) ;
F_288 ( V_295 , V_1 ) ;
}
void F_79 ( const void * V_1 )
{
struct V_14 * V_297 ;
unsigned long V_16 ;
F_289 ( V_295 , V_1 ) ;
if ( F_41 ( F_191 ( V_1 ) ) )
return;
F_257 ( V_16 ) ;
F_222 ( V_1 ) ;
V_297 = F_14 ( V_1 ) ;
F_286 ( V_1 , V_297 -> V_207 ) ;
F_287 ( V_1 , V_297 -> V_207 ) ;
F_267 ( V_297 , ( void * ) V_1 , V_295 ) ;
F_258 ( V_16 ) ;
}
static int F_290 ( struct V_14 * V_15 , T_4 V_82 )
{
int V_64 ;
struct V_3 * V_84 ;
struct V_36 * V_298 ;
struct V_94 * * V_299 = NULL ;
F_90 (node) {
if ( V_58 ) {
V_299 = F_70 ( V_64 , V_15 -> V_76 , V_82 ) ;
if ( ! V_299 )
goto V_300;
}
V_298 = NULL ;
if ( V_15 -> V_8 ) {
V_298 = F_50 ( V_64 ,
V_15 -> V_8 * V_15 -> V_79 ,
0xbaadf00d , V_82 ) ;
if ( ! V_298 ) {
F_71 ( V_299 ) ;
goto V_300;
}
}
V_84 = F_55 ( V_15 , V_64 ) ;
if ( V_84 ) {
struct V_36 * V_8 = V_84 -> V_8 ;
F_86 ( V_103 ) ;
F_97 ( & V_84 -> V_11 ) ;
if ( V_8 )
F_82 ( V_15 , V_8 -> V_89 ,
V_8 -> V_78 , V_64 , & V_103 ) ;
V_84 -> V_8 = V_298 ;
if ( ! V_84 -> V_9 ) {
V_84 -> V_9 = V_299 ;
V_299 = NULL ;
}
V_84 -> V_109 = ( 1 + F_98 ( V_64 ) ) *
V_15 -> V_79 + V_15 -> V_28 ;
F_87 ( & V_84 -> V_11 ) ;
F_88 ( V_15 , & V_103 ) ;
F_79 ( V_8 ) ;
F_71 ( V_299 ) ;
continue;
}
V_84 = F_51 ( sizeof( struct V_3 ) , V_82 , V_64 ) ;
if ( ! V_84 ) {
F_71 ( V_299 ) ;
F_79 ( V_298 ) ;
goto V_300;
}
F_4 ( V_84 ) ;
V_84 -> V_106 = V_107 + V_108 +
( ( unsigned long ) V_15 ) % V_108 ;
V_84 -> V_8 = V_298 ;
V_84 -> V_9 = V_299 ;
V_84 -> V_109 = ( 1 + F_98 ( V_64 ) ) *
V_15 -> V_79 + V_15 -> V_28 ;
V_15 -> V_64 [ V_64 ] = V_84 ;
}
return 0 ;
V_300:
if ( ! V_15 -> V_103 . V_263 ) {
V_64 -- ;
while ( V_64 >= 0 ) {
V_84 = F_55 ( V_15 , V_64 ) ;
if ( V_84 ) {
F_79 ( V_84 -> V_8 ) ;
F_71 ( V_84 -> V_9 ) ;
F_79 ( V_84 ) ;
V_15 -> V_64 [ V_64 ] = NULL ;
}
V_64 -- ;
}
}
return - V_105 ;
}
static void F_291 ( void * V_301 )
{
struct V_302 * V_303 = V_301 ;
struct V_36 * V_304 ;
F_193 () ;
V_304 = F_19 ( V_303 -> V_15 ) ;
V_303 -> V_15 -> V_37 [ F_20 () ] = V_303 -> V_303 [ F_20 () ] ;
V_303 -> V_303 [ F_20 () ] = V_304 ;
}
static int F_292 ( struct V_14 * V_15 , int V_76 ,
int V_79 , int V_8 , T_4 V_82 )
{
struct V_302 * V_303 ;
int V_88 ;
V_303 = F_293 ( sizeof( * V_303 ) + V_151 * sizeof( struct V_36 * ) ,
V_82 ) ;
if ( ! V_303 )
return - V_105 ;
F_134 (i) {
V_303 -> V_303 [ V_88 ] = F_50 ( F_36 ( V_88 ) , V_76 ,
V_79 , V_82 ) ;
if ( ! V_303 -> V_303 [ V_88 ] ) {
for ( V_88 -- ; V_88 >= 0 ; V_88 -- )
F_79 ( V_303 -> V_303 [ V_88 ] ) ;
F_79 ( V_303 ) ;
return - V_105 ;
}
}
V_303 -> V_15 = V_15 ;
F_202 ( F_291 , ( void * ) V_303 , 1 ) ;
F_195 () ;
V_15 -> V_79 = V_79 ;
V_15 -> V_76 = V_76 ;
V_15 -> V_8 = V_8 ;
F_134 (i) {
F_86 ( V_103 ) ;
struct V_36 * V_305 = V_303 -> V_303 [ V_88 ] ;
int V_64 ;
struct V_3 * V_84 ;
if ( ! V_305 )
continue;
V_64 = F_36 ( V_88 ) ;
V_84 = F_55 ( V_15 , V_64 ) ;
F_97 ( & V_84 -> V_11 ) ;
F_82 ( V_15 , V_305 -> V_89 , V_305 -> V_78 , V_64 , & V_103 ) ;
F_87 ( & V_84 -> V_11 ) ;
F_88 ( V_15 , & V_103 ) ;
F_79 ( V_305 ) ;
}
F_79 ( V_303 ) ;
return F_290 ( V_15 , V_82 ) ;
}
static int F_294 ( struct V_14 * V_15 , int V_76 ,
int V_79 , int V_8 , T_4 V_82 )
{
int V_133 ;
struct V_14 * V_297 = NULL ;
int V_88 = 0 ;
V_133 = F_292 ( V_15 , V_76 , V_79 , V_8 , V_82 ) ;
if ( V_171 < V_173 )
return V_133 ;
if ( ( V_133 < 0 ) || ! F_295 ( V_15 ) )
return V_133 ;
F_251 ( ! F_296 ( & V_122 ) ) ;
F_297 (i) {
V_297 = F_298 ( V_15 , V_88 ) ;
if ( V_297 )
F_292 ( V_297 , V_76 , V_79 , V_8 , V_82 ) ;
}
return V_133 ;
}
static int F_129 ( struct V_14 * V_15 , T_4 V_82 )
{
int V_114 ;
int V_76 = 0 ;
int V_8 = 0 ;
int V_79 = 0 ;
if ( ! F_295 ( V_15 ) ) {
struct V_14 * V_306 = F_299 ( V_15 ) ;
V_76 = V_306 -> V_76 ;
V_8 = V_306 -> V_8 ;
V_79 = V_306 -> V_79 ;
}
if ( V_76 && V_8 && V_79 )
goto V_307;
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
if ( V_15 -> V_19 <= V_49 && F_300 () > 1 )
V_8 = 8 ;
#if V_177
if ( V_76 > 32 )
V_76 = 32 ;
#endif
V_79 = ( V_76 + 1 ) / 2 ;
V_307:
V_114 = F_294 ( V_15 , V_76 , V_79 , V_8 , V_82 ) ;
if ( V_114 )
F_27 ( V_53 L_36 ,
V_15 -> V_54 , - V_114 ) ;
return V_114 ;
}
static void F_203 ( struct V_14 * V_15 , struct V_3 * V_84 ,
struct V_36 * V_75 , int V_308 , int V_64 )
{
F_86 ( V_103 ) ;
int V_244 ;
if ( ! V_75 || ! V_75 -> V_78 )
return;
if ( V_75 -> V_80 && ! V_308 ) {
V_75 -> V_80 = 0 ;
} else {
F_97 ( & V_84 -> V_11 ) ;
if ( V_75 -> V_78 ) {
V_244 = V_308 ? V_75 -> V_78 : ( V_75 -> V_76 + 4 ) / 5 ;
if ( V_244 > V_75 -> V_78 )
V_244 = ( V_75 -> V_78 + 1 ) / 2 ;
F_82 ( V_15 , V_75 -> V_89 , V_244 , V_64 , & V_103 ) ;
V_75 -> V_78 -= V_244 ;
memmove ( V_75 -> V_89 , & ( V_75 -> V_89 [ V_244 ] ) ,
sizeof( void * ) * V_75 -> V_78 ) ;
}
F_87 ( & V_84 -> V_11 ) ;
F_88 ( V_15 , & V_103 ) ;
}
}
static void V_73 ( struct V_309 * V_310 )
{
struct V_14 * V_311 ;
struct V_3 * V_84 ;
int V_64 = F_56 () ;
struct V_68 * V_71 = F_301 ( V_310 ) ;
if ( ! F_302 ( & V_122 ) )
goto V_86;
F_58 (searchp, &slab_caches, list) {
F_195 () ;
V_84 = F_55 ( V_311 , V_64 ) ;
F_84 ( V_311 , V_84 ) ;
F_203 ( V_311 , V_84 , F_19 ( V_311 ) , 0 , V_64 ) ;
if ( F_303 ( V_84 -> V_106 , V_107 ) )
goto V_263;
V_84 -> V_106 = V_107 + V_108 ;
F_203 ( V_311 , V_84 , V_84 -> V_8 , 0 , V_64 ) ;
if ( V_84 -> V_13 )
V_84 -> V_13 = 0 ;
else {
int V_312 ;
V_312 = F_103 ( V_311 , V_84 , ( V_84 -> V_109 +
5 * V_311 -> V_28 - 1 ) / ( 5 * V_311 -> V_28 ) ) ;
F_304 ( V_311 , V_312 ) ;
}
V_263:
F_305 () ;
}
F_195 () ;
F_108 ( & V_122 ) ;
F_39 () ;
V_86:
F_306 ( V_71 , F_307 ( V_313 ) ) ;
}
void F_308 ( struct V_14 * V_15 , struct V_314 * V_315 )
{
struct V_22 * V_22 ;
unsigned long V_183 ;
unsigned long V_184 ;
unsigned long V_185 = 0 ;
unsigned long V_186 , V_12 = 0 , V_316 = 0 ;
const char * V_54 ;
char * error = NULL ;
int V_64 ;
struct V_3 * V_84 ;
V_183 = 0 ;
V_186 = 0 ;
F_138 (cachep, node, n) {
F_195 () ;
F_97 ( & V_84 -> V_11 ) ;
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
V_316 += V_84 -> V_8 -> V_78 ;
F_87 ( & V_84 -> V_11 ) ;
}
V_186 += V_185 ;
V_184 = V_186 * V_15 -> V_28 ;
if ( V_184 - V_183 != V_12 && ! error )
error = L_40 ;
V_54 = V_15 -> V_54 ;
if ( error )
F_27 ( V_53 L_41 , V_54 , error ) ;
V_315 -> V_183 = V_183 ;
V_315 -> V_184 = V_184 ;
V_315 -> V_185 = V_185 ;
V_315 -> V_186 = V_186 ;
V_315 -> V_316 = V_316 ;
V_315 -> V_76 = V_15 -> V_76 ;
V_315 -> V_79 = V_15 -> V_79 ;
V_315 -> V_8 = V_15 -> V_8 ;
V_315 -> V_317 = V_15 -> V_28 ;
V_315 -> V_318 = V_15 -> V_46 ;
}
void F_309 ( struct V_319 * V_320 , struct V_14 * V_15 )
{
#if V_293
{
unsigned long V_321 = V_15 -> V_322 ;
unsigned long V_323 = V_15 -> V_324 ;
unsigned long V_325 = V_15 -> V_325 ;
unsigned long V_326 = V_15 -> V_326 ;
unsigned long V_327 = V_15 -> V_327 ;
unsigned long V_328 = V_15 -> V_328 ;
unsigned long V_329 = V_15 -> V_329 ;
unsigned long V_330 = V_15 -> V_330 ;
unsigned long V_331 = V_15 -> V_332 ;
F_310 ( V_320 , L_42
L_43 ,
V_323 , V_321 , V_325 ,
V_326 , V_327 , V_328 , V_329 ,
V_330 , V_331 ) ;
}
{
unsigned long V_333 = F_311 ( & V_15 -> V_333 ) ;
unsigned long V_334 = F_311 ( & V_15 -> V_334 ) ;
unsigned long V_335 = F_311 ( & V_15 -> V_335 ) ;
unsigned long V_336 = F_311 ( & V_15 -> V_336 ) ;
F_310 ( V_320 , L_44 ,
V_333 , V_334 , V_335 , V_336 ) ;
}
#endif
}
T_9 F_312 ( struct V_337 * V_337 , const char T_10 * V_338 ,
T_2 V_339 , T_11 * V_340 )
{
char V_341 [ V_342 + 1 ] , * V_343 ;
int V_76 , V_79 , V_8 , V_344 ;
struct V_14 * V_15 ;
if ( V_339 > V_342 )
return - V_345 ;
if ( F_313 ( & V_341 , V_338 , V_339 ) )
return - V_346 ;
V_341 [ V_342 ] = '\0' ;
V_343 = strchr ( V_341 , ' ' ) ;
if ( ! V_343 )
return - V_345 ;
* V_343 = '\0' ;
V_343 ++ ;
if ( sscanf ( V_343 , L_45 , & V_76 , & V_79 , & V_8 ) != 3 )
return - V_345 ;
F_107 ( & V_122 ) ;
V_344 = - V_345 ;
F_58 (cachep, &slab_caches, list) {
if ( ! strcmp ( V_15 -> V_54 , V_341 ) ) {
if ( V_76 < 1 || V_79 < 1 ||
V_79 > V_76 || V_8 < 0 ) {
V_344 = 0 ;
} else {
V_344 = F_294 ( V_15 , V_76 ,
V_79 , V_8 ,
V_104 ) ;
}
break;
}
}
F_108 ( & V_122 ) ;
if ( V_344 >= 0 )
V_344 = V_339 ;
return V_344 ;
}
static void * F_314 ( struct V_319 * V_320 , T_11 * V_347 )
{
F_107 ( & V_122 ) ;
return F_315 ( & V_161 , * V_347 ) ;
}
static inline int F_316 ( unsigned long * V_84 , unsigned long V_348 )
{
unsigned long * V_245 ;
int V_349 ;
if ( ! V_348 )
return 1 ;
V_349 = V_84 [ 1 ] ;
V_245 = V_84 + 2 ;
while ( V_349 ) {
int V_88 = V_349 / 2 ;
unsigned long * V_350 = V_245 + 2 * V_88 ;
if ( * V_350 == V_348 ) {
V_350 [ 1 ] ++ ;
return 1 ;
}
if ( * V_350 > V_348 ) {
V_349 = V_88 ;
} else {
V_245 = V_350 + 2 ;
V_349 -= V_88 + 1 ;
}
}
if ( ++ V_84 [ 1 ] == V_84 [ 0 ] )
return 0 ;
memmove ( V_245 + 2 , V_245 , V_84 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_245 - ( void * ) V_84 ) ) ;
V_245 [ 0 ] = V_348 ;
V_245 [ 1 ] = 1 ;
return 1 ;
}
static void F_317 ( unsigned long * V_84 , struct V_14 * V_297 ,
struct V_22 * V_22 )
{
void * V_245 ;
int V_88 ;
if ( V_84 [ 0 ] == V_84 [ 1 ] )
return;
for ( V_88 = 0 , V_245 = V_22 -> V_33 ; V_88 < V_297 -> V_28 ; V_88 ++ , V_245 += V_297 -> V_19 ) {
if ( F_13 ( V_22 , V_88 ) != V_268 )
continue;
if ( ! F_316 ( V_84 , ( unsigned long ) * F_11 ( V_297 , V_245 ) ) )
return;
}
}
static void F_318 ( struct V_319 * V_320 , unsigned long V_351 )
{
#ifdef F_319
unsigned long V_34 , V_19 ;
char V_352 [ V_353 ] , V_54 [ V_354 ] ;
if ( F_320 ( V_351 , & V_19 , & V_34 , V_352 , V_54 ) == 0 ) {
F_310 ( V_320 , L_46 , V_54 , V_34 , V_19 ) ;
if ( V_352 [ 0 ] )
F_310 ( V_320 , L_47 , V_352 ) ;
return;
}
#endif
F_310 ( V_320 , L_48 , ( void * ) V_351 ) ;
}
static int F_321 ( struct V_319 * V_320 , void * V_245 )
{
struct V_14 * V_15 = F_204 ( V_245 , struct V_14 , V_103 ) ;
struct V_22 * V_22 ;
struct V_3 * V_84 ;
const char * V_54 ;
unsigned long * V_265 = V_320 -> V_355 ;
int V_64 ;
int V_88 ;
if ( ! ( V_15 -> V_16 & V_18 ) )
return 0 ;
if ( ! ( V_15 -> V_16 & V_17 ) )
return 0 ;
V_265 [ 1 ] = 0 ;
F_138 (cachep, node, n) {
F_195 () ;
F_97 ( & V_84 -> V_11 ) ;
F_58 (page, &n->slabs_full, lru)
F_317 ( V_265 , V_15 , V_22 ) ;
F_58 (page, &n->slabs_partial, lru)
F_317 ( V_265 , V_15 , V_22 ) ;
F_87 ( & V_84 -> V_11 ) ;
}
V_54 = V_15 -> V_54 ;
if ( V_265 [ 0 ] == V_265 [ 1 ] ) {
F_108 ( & V_122 ) ;
V_320 -> V_355 = F_293 ( V_265 [ 0 ] * 4 * sizeof( unsigned long ) , V_104 ) ;
if ( ! V_320 -> V_355 ) {
V_320 -> V_355 = V_265 ;
F_107 ( & V_122 ) ;
return - V_105 ;
}
* ( unsigned long * ) V_320 -> V_355 = V_265 [ 0 ] * 2 ;
F_79 ( V_265 ) ;
F_107 ( & V_122 ) ;
V_320 -> V_339 = V_320 -> V_19 ;
return 0 ;
}
for ( V_88 = 0 ; V_88 < V_265 [ 1 ] ; V_88 ++ ) {
F_310 ( V_320 , L_49 , V_54 , V_265 [ 2 * V_88 + 3 ] ) ;
F_318 ( V_320 , V_265 [ 2 * V_88 + 2 ] ) ;
F_322 ( V_320 , '\n' ) ;
}
return 0 ;
}
static int F_323 ( struct V_356 * V_356 , struct V_337 * V_337 )
{
unsigned long * V_84 = F_293 ( V_49 , V_104 ) ;
int V_133 = - V_105 ;
if ( V_84 ) {
V_133 = F_324 ( V_337 , & V_357 ) ;
if ( ! V_133 ) {
struct V_319 * V_320 = V_337 -> V_358 ;
* V_84 = V_49 / ( 2 * sizeof( unsigned long ) ) ;
V_320 -> V_355 = V_84 ;
V_84 = NULL ;
}
F_79 ( V_84 ) ;
}
return V_133 ;
}
static int T_3 F_325 ( void )
{
#ifdef V_40
F_326 ( L_50 , 0 , NULL , & V_359 ) ;
#endif
return 0 ;
}
T_2 F_327 ( const void * V_1 )
{
F_9 ( ! V_1 ) ;
if ( F_41 ( V_1 == V_360 ) )
return 0 ;
return F_14 ( V_1 ) -> V_207 ;
}
