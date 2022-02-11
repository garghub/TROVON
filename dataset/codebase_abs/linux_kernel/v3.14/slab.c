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
static inline struct V_14 * F_12 ( const void * V_22 )
{
struct V_23 * V_23 = F_13 ( V_22 ) ;
return V_23 -> V_24 ;
}
static inline void * F_14 ( struct V_14 * V_25 , struct V_23 * V_23 ,
unsigned int V_26 )
{
return V_23 -> V_27 + V_25 -> V_19 * V_26 ;
}
static inline unsigned int F_15 ( const struct V_14 * V_25 ,
const struct V_23 * V_23 , void * V_22 )
{
T_1 V_28 = ( V_22 - V_23 -> V_27 ) ;
return F_16 ( V_28 , V_25 -> V_29 ) ;
}
static void F_17 ( struct V_14 * V_15 ,
struct V_30 * V_31 , struct V_30 * V_32 ,
int V_33 )
{
struct V_34 * * V_35 ;
struct V_3 * V_36 ;
int V_37 ;
V_36 = V_15 -> V_38 [ V_33 ] ;
if ( ! V_36 )
return;
F_18 ( & V_36 -> V_11 , V_31 ) ;
V_35 = V_36 -> V_9 ;
if ( ! V_35 || ( unsigned long ) V_35 == V_39 )
return;
F_19 (r) {
if ( V_35 [ V_37 ] )
F_18 ( & V_35 [ V_37 ] -> V_40 , V_32 ) ;
}
}
static void F_20 ( struct V_14 * V_15 , int V_38 )
{
F_17 ( V_15 , & V_41 , & V_42 , V_38 ) ;
}
static void F_21 ( struct V_14 * V_15 )
{
int V_38 ;
F_22 (node)
F_20 ( V_15 , V_38 ) ;
}
static void F_23 ( int V_33 )
{
int V_43 ;
if ( V_44 < V_45 )
return;
for ( V_43 = 1 ; V_43 <= V_46 ; V_43 ++ ) {
struct V_3 * V_36 ;
struct V_14 * V_25 = V_47 [ V_43 ] ;
if ( ! V_25 )
continue;
V_36 = V_25 -> V_38 [ V_33 ] ;
if ( ! V_36 || F_24 ( V_25 ) )
continue;
F_17 ( V_25 , & V_48 ,
& V_49 , V_33 ) ;
}
}
static void F_25 ( struct V_14 * V_15 , int V_33 )
{
if ( ! V_15 -> V_38 [ V_33 ] )
return;
F_17 ( V_15 , & V_48 ,
& V_49 , V_33 ) ;
}
static inline void F_26 ( struct V_14 * V_15 )
{
int V_38 ;
F_27 ( F_24 ( V_15 ) ) ;
F_19 (node)
F_25 ( V_15 , V_38 ) ;
}
static inline void F_28 ( void )
{
int V_38 ;
F_19 (node)
F_23 ( V_38 ) ;
}
static void F_23 ( int V_33 )
{
}
static inline void F_28 ( void )
{
}
static inline void F_26 ( struct V_14 * V_15 )
{
}
static inline void F_25 ( struct V_14 * V_15 , int V_38 )
{
}
static void F_20 ( struct V_14 * V_15 , int V_38 )
{
}
static void F_21 ( struct V_14 * V_15 )
{
}
static inline struct V_34 * F_29 ( struct V_14 * V_15 )
{
return V_15 -> V_50 [ F_30 () ] ;
}
static T_2 F_31 ( T_2 V_51 , T_2 V_52 )
{
return F_32 ( V_51 * sizeof( unsigned int ) , V_52 ) ;
}
static void F_33 ( unsigned long V_53 , T_2 V_54 ,
T_2 V_52 , int V_16 , T_2 * V_55 ,
unsigned int * V_56 )
{
int V_51 ;
T_2 V_57 ;
T_2 V_58 = V_59 << V_53 ;
if ( V_16 & V_60 ) {
V_57 = 0 ;
V_51 = V_58 / V_54 ;
} else {
V_51 = ( V_58 ) / ( V_54 + sizeof( unsigned int ) ) ;
if ( F_31 ( V_51 , V_52 ) + V_51 * V_54
> V_58 )
V_51 -- ;
V_57 = F_31 ( V_51 , V_52 ) ;
}
* V_56 = V_51 ;
* V_55 = V_58 - V_51 * V_54 - V_57 ;
}
static void F_34 ( const char * V_61 , struct V_14 * V_15 ,
char * V_62 )
{
F_35 ( V_63 L_1 ,
V_61 , V_15 -> V_64 , V_62 ) ;
F_36 () ;
F_37 ( V_65 , V_66 ) ;
}
static int T_3 F_38 ( char * V_67 )
{
V_68 = 0 ;
return 1 ;
}
static int T_3 F_39 ( char * V_69 )
{
F_40 ( & V_69 , & V_70 ) ;
V_70 = V_70 < 0 ? 0 :
F_41 ( V_70 , V_71 - 1 ) ;
V_72 = true ;
return 1 ;
}
static void F_42 ( int V_73 )
{
int V_38 ;
V_38 = F_43 ( F_44 ( V_73 ) , V_74 ) ;
if ( V_38 == V_75 )
V_38 = F_45 ( V_74 ) ;
F_46 ( V_76 , V_73 ) = V_38 ;
}
static void F_47 ( void )
{
int V_38 = F_48 ( V_76 ) ;
V_38 = F_43 ( V_38 , V_74 ) ;
if ( F_49 ( V_38 >= V_75 ) )
V_38 = F_45 ( V_74 ) ;
F_50 ( V_76 , V_38 ) ;
}
static void F_51 ( int V_73 )
{
struct V_77 * V_78 = & F_46 ( V_79 , V_73 ) ;
if ( F_52 () && V_78 -> V_80 . V_81 == NULL ) {
F_42 ( V_73 ) ;
F_53 ( V_78 , V_82 ) ;
F_54 ( V_73 , V_78 ,
F_55 ( V_83 , V_73 ) ) ;
}
}
static struct V_34 * F_56 ( int V_38 , int V_84 ,
int V_85 , T_4 V_86 )
{
int V_87 = sizeof( void * ) * V_84 + sizeof( struct V_34 ) ;
struct V_34 * V_88 = NULL ;
V_88 = F_57 ( V_87 , V_86 , V_38 ) ;
F_58 ( V_88 ) ;
if ( V_88 ) {
V_88 -> V_89 = 0 ;
V_88 -> V_90 = V_84 ;
V_88 -> V_85 = V_85 ;
V_88 -> V_91 = 0 ;
F_6 ( & V_88 -> V_40 ) ;
}
return V_88 ;
}
static inline bool F_59 ( struct V_23 * V_23 )
{
return F_60 ( V_23 ) ;
}
static void F_61 ( struct V_14 * V_15 ,
struct V_34 * V_92 )
{
struct V_3 * V_36 = V_15 -> V_38 [ F_62 () ] ;
struct V_23 * V_23 ;
unsigned long V_16 ;
if ( ! V_93 )
return;
F_63 ( & V_36 -> V_11 , V_16 ) ;
F_64 (page, &n->slabs_full, lru)
if ( F_59 ( V_23 ) )
goto V_94;
F_64 (page, &n->slabs_partial, lru)
if ( F_59 ( V_23 ) )
goto V_94;
F_64 (page, &n->slabs_free, lru)
if ( F_59 ( V_23 ) )
goto V_94;
V_93 = false ;
V_94:
F_65 ( & V_36 -> V_11 , V_16 ) ;
}
static void * F_66 ( struct V_14 * V_15 , struct V_34 * V_92 ,
T_4 V_16 , bool V_95 )
{
int V_43 ;
void * V_1 = V_92 -> V_96 [ -- V_92 -> V_89 ] ;
if ( F_49 ( F_1 ( V_1 ) ) ) {
struct V_3 * V_36 ;
if ( F_67 ( V_16 ) ) {
F_3 ( & V_1 ) ;
return V_1 ;
}
for ( V_43 = 0 ; V_43 < V_92 -> V_89 ; V_43 ++ ) {
if ( ! F_1 ( V_92 -> V_96 [ V_43 ] ) ) {
V_1 = V_92 -> V_96 [ V_43 ] ;
V_92 -> V_96 [ V_43 ] = V_92 -> V_96 [ V_92 -> V_89 ] ;
V_92 -> V_96 [ V_92 -> V_89 ] = V_1 ;
return V_1 ;
}
}
V_36 = V_15 -> V_38 [ F_62 () ] ;
if ( ! F_68 ( & V_36 -> V_7 ) && V_95 ) {
struct V_23 * V_23 = F_13 ( V_1 ) ;
F_69 ( V_23 ) ;
F_3 ( & V_1 ) ;
F_61 ( V_15 , V_92 ) ;
return V_1 ;
}
V_92 -> V_89 ++ ;
V_1 = NULL ;
}
return V_1 ;
}
static inline void * F_70 ( struct V_14 * V_15 ,
struct V_34 * V_92 , T_4 V_16 , bool V_95 )
{
void * V_1 ;
if ( F_49 ( F_71 () ) )
V_1 = F_66 ( V_15 , V_92 , V_16 , V_95 ) ;
else
V_1 = V_92 -> V_96 [ -- V_92 -> V_89 ] ;
return V_1 ;
}
static void * F_72 ( struct V_14 * V_15 , struct V_34 * V_92 ,
void * V_1 )
{
if ( F_49 ( V_93 ) ) {
struct V_23 * V_23 = F_13 ( V_1 ) ;
if ( F_60 ( V_23 ) )
F_2 ( & V_1 ) ;
}
return V_1 ;
}
static inline void F_73 ( struct V_14 * V_15 , struct V_34 * V_92 ,
void * V_1 )
{
if ( F_49 ( F_71 () ) )
V_1 = F_72 ( V_15 , V_92 , V_1 ) ;
V_92 -> V_96 [ V_92 -> V_89 ++ ] = V_1 ;
}
static int F_74 ( struct V_34 * V_97 ,
struct V_34 * V_98 , unsigned int V_99 )
{
int V_100 = F_75 ( V_98 -> V_89 , V_99 , V_97 -> V_90 - V_97 -> V_89 ) ;
if ( ! V_100 )
return 0 ;
memcpy ( V_97 -> V_96 + V_97 -> V_89 , V_98 -> V_96 + V_98 -> V_89 - V_100 ,
sizeof( void * ) * V_100 ) ;
V_98 -> V_89 -= V_100 ;
V_97 -> V_89 += V_100 ;
return V_100 ;
}
static inline struct V_34 * * F_76 ( int V_38 , int V_90 , T_4 V_86 )
{
return (struct V_34 * * ) V_39 ;
}
static inline void F_77 ( struct V_34 * * V_101 )
{
}
static inline int F_78 ( struct V_14 * V_15 , void * V_1 )
{
return 0 ;
}
static inline void * F_79 ( struct V_14 * V_15 ,
T_4 V_16 )
{
return NULL ;
}
static inline void * F_80 ( struct V_14 * V_15 ,
T_4 V_16 , int V_102 )
{
return NULL ;
}
static struct V_34 * * F_76 ( int V_38 , int V_90 , T_4 V_86 )
{
struct V_34 * * V_101 ;
int V_87 = sizeof( void * ) * V_103 ;
int V_43 ;
if ( V_90 > 1 )
V_90 = 12 ;
V_101 = F_81 ( V_87 , V_86 , V_38 ) ;
if ( V_101 ) {
F_19 (i) {
if ( V_43 == V_38 || ! F_82 ( V_43 ) )
continue;
V_101 [ V_43 ] = F_56 ( V_38 , V_90 , 0xbaadf00d , V_86 ) ;
if ( ! V_101 [ V_43 ] ) {
for ( V_43 -- ; V_43 >= 0 ; V_43 -- )
F_83 ( V_101 [ V_43 ] ) ;
F_83 ( V_101 ) ;
return NULL ;
}
}
}
return V_101 ;
}
static void F_77 ( struct V_34 * * V_101 )
{
int V_43 ;
if ( ! V_101 )
return;
F_19 (i)
F_83 ( V_101 [ V_43 ] ) ;
F_83 ( V_101 ) ;
}
static void F_84 ( struct V_14 * V_15 ,
struct V_34 * V_92 , int V_38 )
{
struct V_3 * V_36 = V_15 -> V_38 [ V_38 ] ;
if ( V_92 -> V_89 ) {
F_85 ( & V_36 -> V_11 ) ;
if ( V_36 -> V_8 )
F_74 ( V_36 -> V_8 , V_92 , V_92 -> V_90 ) ;
F_86 ( V_15 , V_92 -> V_96 , V_92 -> V_89 , V_38 ) ;
V_92 -> V_89 = 0 ;
F_87 ( & V_36 -> V_11 ) ;
}
}
static void F_88 ( struct V_14 * V_15 , struct V_3 * V_36 )
{
int V_38 = F_48 ( V_76 ) ;
if ( V_36 -> V_9 ) {
struct V_34 * V_92 = V_36 -> V_9 [ V_38 ] ;
if ( V_92 && V_92 -> V_89 && F_89 ( & V_92 -> V_40 ) ) {
F_84 ( V_15 , V_92 , V_38 ) ;
F_90 ( & V_92 -> V_40 ) ;
}
}
}
static void F_91 ( struct V_14 * V_15 ,
struct V_34 * * V_9 )
{
int V_43 = 0 ;
struct V_34 * V_92 ;
unsigned long V_16 ;
F_22 (i) {
V_92 = V_9 [ V_43 ] ;
if ( V_92 ) {
F_63 ( & V_92 -> V_40 , V_16 ) ;
F_84 ( V_15 , V_92 , V_43 ) ;
F_65 ( & V_92 -> V_40 , V_16 ) ;
}
}
}
static inline int F_78 ( struct V_14 * V_15 , void * V_1 )
{
int V_102 = F_92 ( F_93 ( V_1 ) ) ;
struct V_3 * V_36 ;
struct V_34 * V_9 = NULL ;
int V_38 ;
V_38 = F_62 () ;
if ( F_94 ( V_102 == V_38 ) )
return 0 ;
V_36 = V_15 -> V_38 [ V_38 ] ;
F_95 ( V_15 ) ;
if ( V_36 -> V_9 && V_36 -> V_9 [ V_102 ] ) {
V_9 = V_36 -> V_9 [ V_102 ] ;
F_85 ( & V_9 -> V_40 ) ;
if ( F_49 ( V_9 -> V_89 == V_9 -> V_90 ) ) {
F_96 ( V_15 ) ;
F_84 ( V_15 , V_9 , V_102 ) ;
}
F_73 ( V_15 , V_9 , V_1 ) ;
F_87 ( & V_9 -> V_40 ) ;
} else {
F_85 ( & ( V_15 -> V_38 [ V_102 ] ) -> V_11 ) ;
F_86 ( V_15 , & V_1 , 1 , V_102 ) ;
F_87 ( & ( V_15 -> V_38 [ V_102 ] ) -> V_11 ) ;
}
return 1 ;
}
static int F_97 ( int V_38 )
{
struct V_14 * V_15 ;
struct V_3 * V_36 ;
const int V_87 = sizeof( struct V_3 ) ;
F_64 (cachep, &slab_caches, list) {
if ( ! V_15 -> V_38 [ V_38 ] ) {
V_36 = F_57 ( V_87 , V_104 , V_38 ) ;
if ( ! V_36 )
return - V_105 ;
F_4 ( V_36 ) ;
V_36 -> V_106 = V_107 + V_108 +
( ( unsigned long ) V_15 ) % V_108 ;
V_15 -> V_38 [ V_38 ] = V_36 ;
}
F_98 ( & V_15 -> V_38 [ V_38 ] -> V_11 ) ;
V_15 -> V_38 [ V_38 ] -> V_109 =
( 1 + F_99 ( V_38 ) ) *
V_15 -> V_85 + V_15 -> V_56 ;
F_90 ( & V_15 -> V_38 [ V_38 ] -> V_11 ) ;
}
return 0 ;
}
static inline int F_100 ( struct V_14 * V_15 ,
struct V_3 * V_36 )
{
return ( V_36 -> V_12 + V_15 -> V_56 - 1 ) / V_15 -> V_56 ;
}
static void F_101 ( long V_73 )
{
struct V_14 * V_15 ;
struct V_3 * V_36 = NULL ;
int V_38 = F_44 ( V_73 ) ;
const struct V_110 * V_111 = F_102 ( V_38 ) ;
F_64 (cachep, &slab_caches, list) {
struct V_34 * V_88 ;
struct V_34 * V_8 ;
struct V_34 * * V_9 ;
V_88 = V_15 -> V_50 [ V_73 ] ;
V_15 -> V_50 [ V_73 ] = NULL ;
V_36 = V_15 -> V_38 [ V_38 ] ;
if ( ! V_36 )
goto V_112;
F_98 ( & V_36 -> V_11 ) ;
V_36 -> V_109 -= V_15 -> V_85 ;
if ( V_88 )
F_86 ( V_15 , V_88 -> V_96 , V_88 -> V_89 , V_38 ) ;
if ( ! F_103 ( V_111 ) ) {
F_90 ( & V_36 -> V_11 ) ;
goto V_112;
}
V_8 = V_36 -> V_8 ;
if ( V_8 ) {
F_86 ( V_15 , V_8 -> V_96 ,
V_8 -> V_89 , V_38 ) ;
V_36 -> V_8 = NULL ;
}
V_9 = V_36 -> V_9 ;
V_36 -> V_9 = NULL ;
F_90 ( & V_36 -> V_11 ) ;
F_83 ( V_8 ) ;
if ( V_9 ) {
F_91 ( V_15 , V_9 ) ;
F_77 ( V_9 ) ;
}
V_112:
F_83 ( V_88 ) ;
}
F_64 (cachep, &slab_caches, list) {
V_36 = V_15 -> V_38 [ V_38 ] ;
if ( ! V_36 )
continue;
F_104 ( V_15 , V_36 , F_100 ( V_15 , V_36 ) ) ;
}
}
static int F_105 ( long V_73 )
{
struct V_14 * V_15 ;
struct V_3 * V_36 = NULL ;
int V_38 = F_44 ( V_73 ) ;
int V_113 ;
V_113 = F_97 ( V_38 ) ;
if ( V_113 < 0 )
goto V_114;
F_64 (cachep, &slab_caches, list) {
struct V_34 * V_88 ;
struct V_34 * V_8 = NULL ;
struct V_34 * * V_9 = NULL ;
V_88 = F_56 ( V_38 , V_15 -> V_90 ,
V_15 -> V_85 , V_104 ) ;
if ( ! V_88 )
goto V_114;
if ( V_15 -> V_8 ) {
V_8 = F_56 ( V_38 ,
V_15 -> V_8 * V_15 -> V_85 ,
0xbaadf00d , V_104 ) ;
if ( ! V_8 ) {
F_83 ( V_88 ) ;
goto V_114;
}
}
if ( V_68 ) {
V_9 = F_76 ( V_38 , V_15 -> V_90 , V_104 ) ;
if ( ! V_9 ) {
F_83 ( V_8 ) ;
F_83 ( V_88 ) ;
goto V_114;
}
}
V_15 -> V_50 [ V_73 ] = V_88 ;
V_36 = V_15 -> V_38 [ V_38 ] ;
F_9 ( ! V_36 ) ;
F_98 ( & V_36 -> V_11 ) ;
if ( ! V_36 -> V_8 ) {
V_36 -> V_8 = V_8 ;
V_8 = NULL ;
}
#ifdef F_106
if ( ! V_36 -> V_9 ) {
V_36 -> V_9 = V_9 ;
V_9 = NULL ;
}
#endif
F_90 ( & V_36 -> V_11 ) ;
F_83 ( V_8 ) ;
F_77 ( V_9 ) ;
if ( V_15 -> V_16 & V_115 )
F_20 ( V_15 , V_38 ) ;
else if ( ! F_24 ( V_15 ) &&
! ( V_15 -> V_16 & V_116 ) )
F_25 ( V_15 , V_38 ) ;
}
F_23 ( V_38 ) ;
return 0 ;
V_114:
F_101 ( V_73 ) ;
return - V_105 ;
}
static int F_107 ( struct V_117 * V_118 ,
unsigned long V_119 , void * V_120 )
{
long V_73 = ( long ) V_120 ;
int V_113 = 0 ;
switch ( V_119 ) {
case V_121 :
case V_122 :
F_108 ( & V_123 ) ;
V_113 = F_105 ( V_73 ) ;
F_109 ( & V_123 ) ;
break;
case V_124 :
case V_125 :
F_51 ( V_73 ) ;
break;
#ifdef F_110
case V_126 :
case V_127 :
F_111 ( & F_46 ( V_79 , V_73 ) ) ;
F_46 ( V_79 , V_73 ) . V_80 . V_81 = NULL ;
break;
case V_128 :
case V_129 :
F_51 ( V_73 ) ;
break;
case V_130 :
case V_131 :
#endif
case V_132 :
case V_133 :
F_108 ( & V_123 ) ;
F_101 ( V_73 ) ;
F_109 ( & V_123 ) ;
break;
}
return F_112 ( V_113 ) ;
}
static int T_5 F_113 ( int V_38 )
{
struct V_14 * V_15 ;
int V_134 = 0 ;
F_64 (cachep, &slab_caches, list) {
struct V_3 * V_36 ;
V_36 = V_15 -> V_38 [ V_38 ] ;
if ( ! V_36 )
continue;
F_104 ( V_15 , V_36 , F_100 ( V_15 , V_36 ) ) ;
if ( ! F_68 ( & V_36 -> V_5 ) ||
! F_68 ( & V_36 -> V_6 ) ) {
V_134 = - V_135 ;
break;
}
}
return V_134 ;
}
static int T_5 F_114 ( struct V_117 * V_136 ,
unsigned long V_119 , void * V_137 )
{
struct V_138 * V_139 = V_137 ;
int V_134 = 0 ;
int V_140 ;
V_140 = V_139 -> V_141 ;
if ( V_140 < 0 )
goto V_94;
switch ( V_119 ) {
case V_142 :
F_108 ( & V_123 ) ;
V_134 = F_97 ( V_140 ) ;
F_109 ( & V_123 ) ;
break;
case V_143 :
F_108 ( & V_123 ) ;
V_134 = F_113 ( V_140 ) ;
F_109 ( & V_123 ) ;
break;
case V_144 :
case V_145 :
case V_146 :
case V_147 :
break;
}
V_94:
return F_112 ( V_134 ) ;
}
static void T_3 F_115 ( struct V_14 * V_15 , struct V_3 * V_148 ,
int V_102 )
{
struct V_3 * V_149 ;
V_149 = F_57 ( sizeof( struct V_3 ) , V_150 , V_102 ) ;
F_9 ( ! V_149 ) ;
memcpy ( V_149 , V_148 , sizeof( struct V_3 ) ) ;
F_6 ( & V_149 -> V_11 ) ;
F_116 ( V_15 , V_149 , V_102 ) ;
V_15 -> V_38 [ V_102 ] = V_149 ;
}
static void T_3 F_117 ( struct V_14 * V_15 , int V_151 )
{
int V_38 ;
F_22 (node) {
V_15 -> V_38 [ V_38 ] = & V_152 [ V_151 + V_38 ] ;
V_15 -> V_38 [ V_38 ] -> V_106 = V_107 +
V_108 +
( ( unsigned long ) V_15 ) % V_108 ;
}
}
static void F_118 ( struct V_14 * V_15 )
{
V_15 -> V_38 = (struct V_3 * * ) & V_15 -> V_50 [ V_153 ] ;
}
void T_3 F_119 ( void )
{
int V_43 ;
F_120 ( sizeof( ( (struct V_23 * ) NULL ) -> V_154 ) <
sizeof( struct V_155 ) ) ;
V_14 = & V_156 ;
F_118 ( V_14 ) ;
if ( F_121 () == 1 )
V_68 = 0 ;
for ( V_43 = 0 ; V_43 < V_157 ; V_43 ++ )
F_4 ( & V_152 [ V_43 ] ) ;
F_117 ( V_14 , V_158 ) ;
if ( ! V_72 && V_159 > ( 32 << 20 ) >> V_160 )
V_70 = V_161 ;
F_122 ( V_14 , L_2 ,
F_123 ( struct V_14 , V_50 [ V_153 ] ) +
V_103 * sizeof( struct V_3 * ) ,
V_162 ) ;
F_124 ( & V_14 -> V_148 , & V_163 ) ;
V_47 [ V_164 ] = F_125 ( L_3 ,
F_126 ( V_164 ) , V_165 ) ;
if ( V_164 != V_166 )
V_47 [ V_166 ] =
F_125 ( L_4 ,
F_126 ( V_166 ) , V_165 ) ;
V_167 = 0 ;
{
struct V_34 * V_149 ;
V_149 = F_127 ( sizeof( struct V_168 ) , V_150 ) ;
memcpy ( V_149 , F_29 ( V_14 ) ,
sizeof( struct V_168 ) ) ;
F_6 ( & V_149 -> V_40 ) ;
V_14 -> V_50 [ F_30 () ] = V_149 ;
V_149 = F_127 ( sizeof( struct V_168 ) , V_150 ) ;
F_9 ( F_29 ( V_47 [ V_164 ] )
!= & V_169 . V_25 ) ;
memcpy ( V_149 , F_29 ( V_47 [ V_164 ] ) ,
sizeof( struct V_168 ) ) ;
F_6 ( & V_149 -> V_40 ) ;
V_47 [ V_164 ] -> V_50 [ F_30 () ] = V_149 ;
}
{
int V_140 ;
F_22 (nid) {
F_115 ( V_14 , & V_152 [ V_158 + V_140 ] , V_140 ) ;
F_115 ( V_47 [ V_164 ] ,
& V_152 [ V_170 + V_140 ] , V_140 ) ;
if ( V_164 != V_166 ) {
F_115 ( V_47 [ V_166 ] ,
& V_152 [ V_171 + V_140 ] , V_140 ) ;
}
}
}
F_128 ( V_165 ) ;
}
void T_3 F_129 ( void )
{
struct V_14 * V_15 ;
V_44 = V_45 ;
F_108 ( & V_123 ) ;
F_64 (cachep, &slab_caches, list)
if ( F_130 ( V_15 , V_150 ) )
F_131 () ;
F_109 ( & V_123 ) ;
F_28 () ;
V_44 = V_172 ;
F_132 ( & V_173 ) ;
#ifdef F_106
F_133 ( F_114 , V_174 ) ;
#endif
}
static int T_3 F_134 ( void )
{
int V_73 ;
F_135 (cpu)
F_51 ( V_73 ) ;
V_44 = V_172 ;
return 0 ;
}
static T_6 void
F_136 ( struct V_14 * V_15 , T_4 V_175 , int V_102 )
{
struct V_3 * V_36 ;
struct V_23 * V_23 ;
unsigned long V_16 ;
int V_38 ;
F_35 ( V_176
L_5 ,
V_102 , V_175 ) ;
F_35 ( V_176 L_6 ,
V_15 -> V_64 , V_15 -> V_19 , V_15 -> V_53 ) ;
F_22 (node) {
unsigned long V_177 = 0 , V_178 = 0 , V_12 = 0 ;
unsigned long V_179 = 0 , V_180 = 0 ;
V_36 = V_15 -> V_38 [ V_38 ] ;
if ( ! V_36 )
continue;
F_63 ( & V_36 -> V_11 , V_16 ) ;
F_64 (page, &n->slabs_full, lru) {
V_177 += V_15 -> V_56 ;
V_179 ++ ;
}
F_64 (page, &n->slabs_partial, lru) {
V_177 += V_23 -> V_181 ;
V_179 ++ ;
}
F_64 (page, &n->slabs_free, lru)
V_180 ++ ;
V_12 += V_36 -> V_12 ;
F_65 ( & V_36 -> V_11 , V_16 ) ;
V_180 += V_179 ;
V_178 = V_180 * V_15 -> V_56 ;
F_35 ( V_176
L_7 ,
V_38 , V_179 , V_180 , V_177 , V_178 ,
V_12 ) ;
}
}
static struct V_23 * F_137 ( struct V_14 * V_15 , T_4 V_16 ,
int V_102 )
{
struct V_23 * V_23 ;
int V_182 ;
V_16 |= V_15 -> V_183 ;
if ( V_15 -> V_16 & V_184 )
V_16 |= V_185 ;
V_23 = F_138 ( V_102 , V_16 | V_186 , V_15 -> V_53 ) ;
if ( ! V_23 ) {
if ( ! ( V_16 & V_187 ) && F_139 () )
F_136 ( V_15 , V_16 , V_102 ) ;
return NULL ;
}
if ( F_49 ( V_23 -> V_188 ) )
V_93 = true ;
V_182 = ( 1 << V_15 -> V_53 ) ;
if ( V_15 -> V_16 & V_184 )
F_140 ( F_141 ( V_23 ) ,
V_189 , V_182 ) ;
else
F_140 ( F_141 ( V_23 ) ,
V_190 , V_182 ) ;
F_142 ( V_23 ) ;
if ( V_23 -> V_188 )
F_143 ( V_23 ) ;
F_144 ( V_15 , V_15 -> V_53 ) ;
if ( V_191 && ! ( V_15 -> V_16 & V_192 ) ) {
F_145 ( V_23 , V_15 -> V_53 , V_16 , V_102 ) ;
if ( V_15 -> V_193 )
F_146 ( V_23 , V_182 ) ;
else
F_147 ( V_23 , V_182 ) ;
}
return V_23 ;
}
static void F_148 ( struct V_14 * V_15 , struct V_23 * V_23 )
{
const unsigned long V_194 = ( 1 << V_15 -> V_53 ) ;
F_149 ( V_23 , V_15 -> V_53 ) ;
if ( V_15 -> V_16 & V_184 )
F_150 ( F_141 ( V_23 ) ,
V_189 , V_194 ) ;
else
F_150 ( F_141 ( V_23 ) ,
V_190 , V_194 ) ;
F_9 ( ! F_151 ( V_23 ) ) ;
F_152 ( V_23 ) ;
F_153 ( V_23 ) ;
F_154 ( V_23 ) ;
V_23 -> V_195 = NULL ;
F_155 ( V_15 , V_15 -> V_53 ) ;
if ( V_196 -> V_197 )
V_196 -> V_197 -> V_198 += V_194 ;
F_156 ( V_23 , V_15 -> V_53 ) ;
}
static void F_157 ( struct V_155 * V_199 )
{
struct V_14 * V_15 ;
struct V_23 * V_23 ;
V_23 = F_158 ( V_199 , struct V_23 , V_155 ) ;
V_15 = V_23 -> V_24 ;
F_148 ( V_15 , V_23 ) ;
}
static void F_159 ( struct V_14 * V_15 , unsigned long * V_200 ,
unsigned long V_201 )
{
int V_19 = V_15 -> V_202 ;
V_200 = ( unsigned long * ) & ( ( char * ) V_200 ) [ F_7 ( V_15 ) ] ;
if ( V_19 < 5 * sizeof( unsigned long ) )
return;
* V_200 ++ = 0x12345678 ;
* V_200 ++ = V_201 ;
* V_200 ++ = F_30 () ;
V_19 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_203 = & V_201 ;
unsigned long V_204 ;
while ( ! F_160 ( V_203 ) ) {
V_204 = * V_203 ++ ;
if ( F_161 ( V_204 ) ) {
* V_200 ++ = V_204 ;
V_19 -= sizeof( unsigned long ) ;
if ( V_19 <= sizeof( unsigned long ) )
break;
}
}
}
* V_200 ++ = 0x87654321 ;
}
static void F_162 ( struct V_14 * V_15 , void * V_200 , unsigned char V_205 )
{
int V_19 = V_15 -> V_202 ;
V_200 = & ( ( char * ) V_200 ) [ F_7 ( V_15 ) ] ;
memset ( V_200 , V_205 , V_19 ) ;
* ( unsigned char * ) ( V_200 + V_19 - 1 ) = V_206 ;
}
static void F_163 ( char * V_207 , int V_28 , int V_90 )
{
int V_43 ;
unsigned char error = 0 ;
int V_208 = 0 ;
F_35 ( V_63 L_8 , V_28 ) ;
for ( V_43 = 0 ; V_43 < V_90 ; V_43 ++ ) {
if ( V_207 [ V_28 + V_43 ] != V_209 ) {
error = V_207 [ V_28 + V_43 ] ;
V_208 ++ ;
}
}
F_164 ( V_210 , L_9 , 0 , 16 , 1 ,
& V_207 [ V_28 ] , V_90 , 1 ) ;
if ( V_208 == 1 ) {
error ^= V_209 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_35 ( V_63 L_10
L_11 ) ;
#ifdef F_165
F_35 ( V_63 L_12
L_13 ) ;
#else
F_35 ( V_63 L_14 ) ;
#endif
}
}
}
static void F_166 ( struct V_14 * V_15 , void * V_1 , int V_211 )
{
int V_43 , V_19 ;
char * V_212 ;
if ( V_15 -> V_16 & V_17 ) {
F_35 ( V_63 L_15 ,
* F_8 ( V_15 , V_1 ) ,
* F_10 ( V_15 , V_1 ) ) ;
}
if ( V_15 -> V_16 & V_18 ) {
F_35 ( V_63 L_16 ,
* F_11 ( V_15 , V_1 ) ,
* F_11 ( V_15 , V_1 ) ) ;
}
V_212 = ( char * ) V_1 + F_7 ( V_15 ) ;
V_19 = V_15 -> V_202 ;
for ( V_43 = 0 ; V_43 < V_19 && V_211 ; V_43 += 16 , V_211 -- ) {
int V_90 ;
V_90 = 16 ;
if ( V_43 + V_90 > V_19 )
V_90 = V_19 - V_43 ;
F_163 ( V_212 , V_43 , V_90 ) ;
}
}
static void F_167 ( struct V_14 * V_15 , void * V_1 )
{
char * V_212 ;
int V_19 , V_43 ;
int V_211 = 0 ;
V_212 = ( char * ) V_1 + F_7 ( V_15 ) ;
V_19 = V_15 -> V_202 ;
for ( V_43 = 0 ; V_43 < V_19 ; V_43 ++ ) {
char exp = V_209 ;
if ( V_43 == V_19 - 1 )
exp = V_206 ;
if ( V_212 [ V_43 ] != exp ) {
int V_90 ;
if ( V_211 == 0 ) {
F_35 ( V_63
L_17 ,
F_168 () , V_15 -> V_64 , V_212 , V_19 ) ;
F_166 ( V_15 , V_1 , 0 ) ;
}
V_43 = ( V_43 / 16 ) * 16 ;
V_90 = 16 ;
if ( V_43 + V_90 > V_19 )
V_90 = V_19 - V_43 ;
F_163 ( V_212 , V_43 , V_90 ) ;
V_43 += 16 ;
V_211 ++ ;
if ( V_211 > 5 )
break;
}
}
if ( V_211 != 0 ) {
struct V_23 * V_23 = F_13 ( V_1 ) ;
unsigned int V_213 ;
V_213 = F_15 ( V_15 , V_23 , V_1 ) ;
if ( V_213 ) {
V_1 = F_14 ( V_15 , V_23 , V_213 - 1 ) ;
V_212 = ( char * ) V_1 + F_7 ( V_15 ) ;
F_35 ( V_63 L_18 ,
V_212 , V_19 ) ;
F_166 ( V_15 , V_1 , 2 ) ;
}
if ( V_213 + 1 < V_15 -> V_56 ) {
V_1 = F_14 ( V_15 , V_23 , V_213 + 1 ) ;
V_212 = ( char * ) V_1 + F_7 ( V_15 ) ;
F_35 ( V_63 L_19 ,
V_212 , V_19 ) ;
F_166 ( V_15 , V_1 , 2 ) ;
}
}
}
static void F_169 ( struct V_14 * V_15 ,
struct V_23 * V_23 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_15 -> V_56 ; V_43 ++ ) {
void * V_1 = F_14 ( V_15 , V_23 , V_43 ) ;
if ( V_15 -> V_16 & V_214 ) {
#ifdef F_170
if ( V_15 -> V_19 % V_59 == 0 &&
F_24 ( V_15 ) )
F_171 ( F_93 ( V_1 ) ,
V_15 -> V_19 / V_59 , 1 ) ;
else
F_167 ( V_15 , V_1 ) ;
#else
F_167 ( V_15 , V_1 ) ;
#endif
}
if ( V_15 -> V_16 & V_17 ) {
if ( * F_8 ( V_15 , V_1 ) != V_215 )
F_172 ( V_15 , L_20
L_21 ) ;
if ( * F_10 ( V_15 , V_1 ) != V_215 )
F_172 ( V_15 , L_22
L_21 ) ;
}
}
}
static void F_169 ( struct V_14 * V_15 ,
struct V_23 * V_23 )
{
}
static void F_173 ( struct V_14 * V_15 , struct V_23 * V_23 )
{
void * V_216 ;
V_216 = V_23 -> V_216 ;
F_169 ( V_15 , V_23 ) ;
if ( F_49 ( V_15 -> V_16 & V_116 ) ) {
struct V_155 * V_199 ;
V_199 = ( void * ) & V_23 -> V_155 ;
F_174 ( V_199 , F_157 ) ;
} else {
F_148 ( V_15 , V_23 ) ;
}
if ( F_24 ( V_15 ) )
F_175 ( V_15 -> V_217 , V_216 ) ;
}
static T_2 F_176 ( struct V_14 * V_15 ,
T_2 V_19 , T_2 V_52 , unsigned long V_16 )
{
unsigned long V_218 ;
T_2 V_55 = 0 ;
int V_53 ;
for ( V_53 = 0 ; V_53 <= V_219 ; V_53 ++ ) {
unsigned int V_56 ;
T_2 V_220 ;
F_33 ( V_53 , V_19 , V_52 , V_16 , & V_220 , & V_56 ) ;
if ( ! V_56 )
continue;
if ( V_16 & V_60 ) {
V_218 = V_19 ;
V_218 /= sizeof( unsigned int ) ;
if ( V_56 > V_218 )
break;
}
V_15 -> V_56 = V_56 ;
V_15 -> V_53 = V_53 ;
V_55 = V_220 ;
if ( V_16 & V_184 )
break;
if ( V_53 >= V_70 )
break;
if ( V_55 * 8 <= ( V_59 << V_53 ) )
break;
}
return V_55 ;
}
static int T_7 F_177 ( struct V_14 * V_15 , T_4 V_86 )
{
if ( V_44 >= V_172 )
return F_130 ( V_15 , V_86 ) ;
if ( V_44 == V_221 ) {
V_15 -> V_50 [ F_30 () ] = & V_169 . V_25 ;
V_44 = V_222 ;
} else if ( V_44 == V_222 ) {
V_15 -> V_50 [ F_30 () ] = & V_169 . V_25 ;
F_117 ( V_15 , V_170 ) ;
if ( V_164 == V_166 )
V_44 = V_223 ;
else
V_44 = V_224 ;
} else {
V_15 -> V_50 [ F_30 () ] =
F_127 ( sizeof( struct V_168 ) , V_86 ) ;
if ( V_44 == V_224 ) {
F_117 ( V_15 , V_171 ) ;
V_44 = V_223 ;
} else {
int V_38 ;
F_22 (node) {
V_15 -> V_38 [ V_38 ] =
F_57 ( sizeof( struct V_3 ) ,
V_86 , V_38 ) ;
F_9 ( ! V_15 -> V_38 [ V_38 ] ) ;
F_4 ( V_15 -> V_38 [ V_38 ] ) ;
}
}
}
V_15 -> V_38 [ F_62 () ] -> V_106 =
V_107 + V_108 +
( ( unsigned long ) V_15 ) % V_108 ;
F_29 ( V_15 ) -> V_89 = 0 ;
F_29 ( V_15 ) -> V_90 = V_225 ;
F_29 ( V_15 ) -> V_85 = 1 ;
F_29 ( V_15 ) -> V_91 = 0 ;
V_15 -> V_85 = 1 ;
V_15 -> V_90 = V_225 ;
return 0 ;
}
int
F_178 ( struct V_14 * V_15 , unsigned long V_16 )
{
T_2 V_55 , V_226 , V_227 ;
T_4 V_86 ;
int V_113 ;
T_2 V_19 = V_15 -> V_19 ;
#if V_228
#if V_229
if ( V_19 < 4096 || F_179 ( V_19 - 1 ) == F_179 ( V_19 - 1 + V_20 +
2 * sizeof( unsigned long long ) ) )
V_16 |= V_17 | V_18 ;
if ( ! ( V_16 & V_116 ) )
V_16 |= V_214 ;
#endif
if ( V_16 & V_116 )
F_9 ( V_16 & V_214 ) ;
#endif
if ( V_19 & ( V_21 - 1 ) ) {
V_19 += ( V_21 - 1 ) ;
V_19 &= ~ ( V_21 - 1 ) ;
}
if ( V_16 & V_18 )
V_227 = V_21 ;
if ( V_16 & V_17 ) {
V_227 = V_20 ;
V_19 += V_20 - 1 ;
V_19 &= ~ ( V_20 - 1 ) ;
}
if ( V_227 < V_15 -> V_52 ) {
V_227 = V_15 -> V_52 ;
}
if ( V_227 > F_180 (unsigned long long) )
V_16 &= ~ ( V_17 | V_18 ) ;
V_15 -> V_52 = V_227 ;
if ( F_181 () )
V_86 = V_104 ;
else
V_86 = V_150 ;
F_118 ( V_15 ) ;
#if V_228
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
#if V_229 && F_182 ( F_170 )
if ( V_19 >= F_126 ( V_166 + 1 )
&& V_15 -> V_202 > F_183 ()
&& F_32 ( V_19 , V_15 -> V_52 ) < V_59 ) {
V_15 -> F_7 += V_59 - F_32 ( V_19 , V_15 -> V_52 ) ;
V_19 = V_59 ;
}
#endif
#endif
if ( ( V_19 >= ( V_59 >> 3 ) ) && ! V_167 &&
! ( V_16 & V_230 ) )
V_16 |= V_60 ;
V_19 = F_32 ( V_19 , V_15 -> V_52 ) ;
V_55 = F_176 ( V_15 , V_19 , V_15 -> V_52 , V_16 ) ;
if ( ! V_15 -> V_56 )
return - V_231 ;
V_226 =
F_32 ( V_15 -> V_56 * sizeof( unsigned int ) , V_15 -> V_52 ) ;
if ( V_16 & V_60 && V_55 >= V_226 ) {
V_16 &= ~ V_60 ;
V_55 -= V_226 ;
}
if ( V_16 & V_60 ) {
V_226 = V_15 -> V_56 * sizeof( unsigned int ) ;
#ifdef F_184
if ( V_19 % V_59 == 0 && V_16 & V_214 )
V_16 &= ~ ( V_17 | V_18 ) ;
#endif
}
V_15 -> V_232 = F_183 () ;
if ( V_15 -> V_232 < V_15 -> V_52 )
V_15 -> V_232 = V_15 -> V_52 ;
V_15 -> V_233 = V_55 / V_15 -> V_232 ;
V_15 -> V_226 = V_226 ;
V_15 -> V_16 = V_16 ;
V_15 -> V_183 = V_234 ;
if ( V_235 && ( V_16 & V_236 ) )
V_15 -> V_183 |= V_237 ;
V_15 -> V_19 = V_19 ;
V_15 -> V_29 = F_185 ( V_19 ) ;
if ( V_16 & V_60 ) {
V_15 -> V_217 = F_186 ( V_226 , 0u ) ;
F_9 ( F_187 ( V_15 -> V_217 ) ) ;
}
V_113 = F_177 ( V_15 , V_86 ) ;
if ( V_113 ) {
F_188 ( V_15 ) ;
return V_113 ;
}
if ( V_16 & V_115 ) {
F_189 ( V_16 & V_116 ) ;
F_21 ( V_15 ) ;
} else if ( ! F_24 ( V_15 ) && ! ( V_16 & V_116 ) )
F_26 ( V_15 ) ;
return 0 ;
}
static void F_190 ( void )
{
F_9 ( ! F_191 () ) ;
}
static void F_192 ( void )
{
F_9 ( F_191 () ) ;
}
static void F_193 ( struct V_14 * V_15 )
{
#ifdef F_194
F_190 () ;
F_195 ( & V_15 -> V_38 [ F_62 () ] -> V_11 ) ;
#endif
}
static void F_196 ( struct V_14 * V_15 , int V_38 )
{
#ifdef F_194
F_190 () ;
F_195 ( & V_15 -> V_38 [ V_38 ] -> V_11 ) ;
#endif
}
static void F_197 ( void * V_137 )
{
struct V_14 * V_15 = V_137 ;
struct V_34 * V_92 ;
int V_38 = F_62 () ;
F_190 () ;
V_92 = F_29 ( V_15 ) ;
F_85 ( & V_15 -> V_38 [ V_38 ] -> V_11 ) ;
F_86 ( V_15 , V_92 -> V_96 , V_92 -> V_89 , V_38 ) ;
F_87 ( & V_15 -> V_38 [ V_38 ] -> V_11 ) ;
V_92 -> V_89 = 0 ;
}
static void F_198 ( struct V_14 * V_15 )
{
struct V_3 * V_36 ;
int V_38 ;
F_199 ( F_197 , V_15 , 1 ) ;
F_192 () ;
F_22 (node) {
V_36 = V_15 -> V_38 [ V_38 ] ;
if ( V_36 && V_36 -> V_9 )
F_91 ( V_15 , V_36 -> V_9 ) ;
}
F_22 (node) {
V_36 = V_15 -> V_38 [ V_38 ] ;
if ( V_36 )
F_200 ( V_15 , V_36 , V_36 -> V_8 , 1 , V_38 ) ;
}
}
static int F_104 ( struct V_14 * V_25 ,
struct V_3 * V_36 , int V_238 )
{
struct V_239 * V_240 ;
int V_194 ;
struct V_23 * V_23 ;
V_194 = 0 ;
while ( V_194 < V_238 && ! F_68 ( & V_36 -> V_7 ) ) {
F_98 ( & V_36 -> V_11 ) ;
V_240 = V_36 -> V_7 . V_241 ;
if ( V_240 == & V_36 -> V_7 ) {
F_90 ( & V_36 -> V_11 ) ;
goto V_94;
}
V_23 = F_201 ( V_240 , struct V_23 , V_154 ) ;
#if V_228
F_9 ( V_23 -> V_181 ) ;
#endif
F_202 ( & V_23 -> V_154 ) ;
V_36 -> V_12 -= V_25 -> V_56 ;
F_90 ( & V_36 -> V_11 ) ;
F_173 ( V_25 , V_23 ) ;
V_194 ++ ;
}
V_94:
return V_194 ;
}
static int F_203 ( struct V_14 * V_15 )
{
int V_134 = 0 , V_43 = 0 ;
struct V_3 * V_36 ;
F_198 ( V_15 ) ;
F_192 () ;
F_22 (i) {
V_36 = V_15 -> V_38 [ V_43 ] ;
if ( ! V_36 )
continue;
F_104 ( V_15 , V_36 , F_100 ( V_15 , V_36 ) ) ;
V_134 += ! F_68 ( & V_36 -> V_5 ) ||
! F_68 ( & V_36 -> V_6 ) ;
}
return ( V_134 ? 1 : 0 ) ;
}
int F_204 ( struct V_14 * V_15 )
{
int V_134 ;
F_9 ( ! V_15 || F_205 () ) ;
F_206 () ;
F_108 ( & V_123 ) ;
V_134 = F_203 ( V_15 ) ;
F_109 ( & V_123 ) ;
F_207 () ;
return V_134 ;
}
int F_188 ( struct V_14 * V_15 )
{
int V_43 ;
struct V_3 * V_36 ;
int V_242 = F_203 ( V_15 ) ;
if ( V_242 )
return V_242 ;
F_135 (i)
F_83 ( V_15 -> V_50 [ V_43 ] ) ;
F_22 (i) {
V_36 = V_15 -> V_38 [ V_43 ] ;
if ( V_36 ) {
F_83 ( V_36 -> V_8 ) ;
F_77 ( V_36 -> V_9 ) ;
F_83 ( V_36 ) ;
}
}
return 0 ;
}
static void * F_208 ( struct V_14 * V_15 ,
struct V_23 * V_23 , int V_232 ,
T_4 V_243 , int V_102 )
{
void * V_216 ;
void * V_200 = F_209 ( V_23 ) ;
if ( F_24 ( V_15 ) ) {
V_216 = F_210 ( V_15 -> V_217 ,
V_243 , V_102 ) ;
if ( ! V_216 )
return NULL ;
} else {
V_216 = V_200 + V_232 ;
V_232 += V_15 -> V_226 ;
}
V_23 -> V_181 = 0 ;
V_23 -> V_27 = V_200 + V_232 ;
return V_216 ;
}
static inline unsigned int * F_211 ( struct V_23 * V_23 )
{
return ( unsigned int * ) ( V_23 -> V_216 ) ;
}
static void F_212 ( struct V_14 * V_15 ,
struct V_23 * V_23 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_15 -> V_56 ; V_43 ++ ) {
void * V_1 = F_14 ( V_15 , V_23 , V_43 ) ;
#if V_228
if ( V_15 -> V_16 & V_214 )
F_162 ( V_15 , V_1 , V_209 ) ;
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = NULL ;
if ( V_15 -> V_16 & V_17 ) {
* F_8 ( V_15 , V_1 ) = V_215 ;
* F_10 ( V_15 , V_1 ) = V_215 ;
}
if ( V_15 -> V_193 && ! ( V_15 -> V_16 & V_214 ) )
V_15 -> V_193 ( V_1 + F_7 ( V_15 ) ) ;
if ( V_15 -> V_16 & V_17 ) {
if ( * F_10 ( V_15 , V_1 ) != V_215 )
F_172 ( V_15 , L_23
L_24 ) ;
if ( * F_8 ( V_15 , V_1 ) != V_215 )
F_172 ( V_15 , L_23
L_25 ) ;
}
if ( ( V_15 -> V_19 % V_59 ) == 0 &&
F_24 ( V_15 ) && V_15 -> V_16 & V_214 )
F_171 ( F_93 ( V_1 ) ,
V_15 -> V_19 / V_59 , 0 ) ;
#else
if ( V_15 -> V_193 )
V_15 -> V_193 ( V_1 ) ;
#endif
F_211 ( V_23 ) [ V_43 ] = V_43 ;
}
}
static void F_213 ( struct V_14 * V_15 , T_4 V_16 )
{
if ( V_235 ) {
if ( V_16 & V_237 )
F_9 ( ! ( V_15 -> V_183 & V_237 ) ) ;
else
F_9 ( V_15 -> V_183 & V_237 ) ;
}
}
static void * F_214 ( struct V_14 * V_15 , struct V_23 * V_23 ,
int V_102 )
{
void * V_1 ;
V_1 = F_14 ( V_15 , V_23 , F_211 ( V_23 ) [ V_23 -> V_181 ] ) ;
V_23 -> V_181 ++ ;
#if V_228
F_215 ( F_92 ( F_93 ( V_1 ) ) != V_102 ) ;
#endif
return V_1 ;
}
static void F_216 ( struct V_14 * V_15 , struct V_23 * V_23 ,
void * V_1 , int V_102 )
{
unsigned int V_213 = F_15 ( V_15 , V_23 , V_1 ) ;
#if V_228
unsigned int V_43 ;
F_215 ( F_92 ( F_93 ( V_1 ) ) != V_102 ) ;
for ( V_43 = V_23 -> V_181 ; V_43 < V_15 -> V_56 ; V_43 ++ ) {
if ( F_211 ( V_23 ) [ V_43 ] == V_213 ) {
F_35 ( V_63 L_26
L_27 , V_15 -> V_64 , V_1 ) ;
F_131 () ;
}
}
#endif
V_23 -> V_181 -- ;
F_211 ( V_23 ) [ V_23 -> V_181 ] = V_213 ;
}
static void F_217 ( struct V_14 * V_25 , struct V_23 * V_23 ,
void * V_216 )
{
V_23 -> V_24 = V_25 ;
V_23 -> V_216 = V_216 ;
}
static int F_218 ( struct V_14 * V_15 ,
T_4 V_16 , int V_102 , struct V_23 * V_23 )
{
void * V_216 ;
T_2 V_28 ;
T_4 V_243 ;
struct V_3 * V_36 ;
F_9 ( V_16 & V_244 ) ;
V_243 = V_16 & ( V_245 | V_246 ) ;
F_190 () ;
V_36 = V_15 -> V_38 [ V_102 ] ;
F_85 ( & V_36 -> V_11 ) ;
V_28 = V_36 -> V_10 ;
V_36 -> V_10 ++ ;
if ( V_36 -> V_10 >= V_15 -> V_233 )
V_36 -> V_10 = 0 ;
F_87 ( & V_36 -> V_11 ) ;
V_28 *= V_15 -> V_232 ;
if ( V_243 & V_247 )
F_219 () ;
F_213 ( V_15 , V_16 ) ;
if ( ! V_23 )
V_23 = F_137 ( V_15 , V_243 , V_102 ) ;
if ( ! V_23 )
goto V_248;
V_216 = F_208 ( V_15 , V_23 , V_28 ,
V_243 & ~ V_245 , V_102 ) ;
if ( ! V_216 )
goto V_249;
F_217 ( V_15 , V_23 , V_216 ) ;
F_212 ( V_15 , V_23 ) ;
if ( V_243 & V_247 )
F_220 () ;
F_190 () ;
F_85 ( & V_36 -> V_11 ) ;
F_221 ( & V_23 -> V_154 , & ( V_36 -> V_7 ) ) ;
F_222 ( V_15 ) ;
V_36 -> V_12 += V_15 -> V_56 ;
F_87 ( & V_36 -> V_11 ) ;
return 1 ;
V_249:
F_148 ( V_15 , V_23 ) ;
V_248:
if ( V_243 & V_247 )
F_220 () ;
return 0 ;
}
static void F_223 ( const void * V_1 )
{
if ( ! F_224 ( V_1 ) ) {
F_35 ( V_63 L_28 ,
( unsigned long ) V_1 ) ;
F_131 () ;
}
}
static inline void F_225 ( struct V_14 * V_25 , void * V_22 )
{
unsigned long long V_250 , V_251 ;
V_250 = * F_8 ( V_25 , V_22 ) ;
V_251 = * F_10 ( V_25 , V_22 ) ;
if ( V_250 == V_252 && V_251 == V_252 )
return;
if ( V_250 == V_215 && V_251 == V_215 )
F_172 ( V_25 , L_29 ) ;
else
F_172 ( V_25 , L_30 ) ;
F_35 ( V_63 L_31 ,
V_22 , V_250 , V_251 ) ;
}
static void * F_226 ( struct V_14 * V_15 , void * V_1 ,
unsigned long V_201 )
{
unsigned int V_213 ;
struct V_23 * V_23 ;
F_9 ( F_12 ( V_1 ) != V_15 ) ;
V_1 -= F_7 ( V_15 ) ;
F_223 ( V_1 ) ;
V_23 = F_13 ( V_1 ) ;
if ( V_15 -> V_16 & V_17 ) {
F_225 ( V_15 , V_1 ) ;
* F_8 ( V_15 , V_1 ) = V_215 ;
* F_10 ( V_15 , V_1 ) = V_215 ;
}
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = ( void * ) V_201 ;
V_213 = F_15 ( V_15 , V_23 , V_1 ) ;
F_9 ( V_213 >= V_15 -> V_56 ) ;
F_9 ( V_1 != F_14 ( V_15 , V_23 , V_213 ) ) ;
if ( V_15 -> V_16 & V_214 ) {
#ifdef F_170
if ( ( V_15 -> V_19 % V_59 ) == 0 && F_24 ( V_15 ) ) {
F_159 ( V_15 , V_1 , V_201 ) ;
F_171 ( F_93 ( V_1 ) ,
V_15 -> V_19 / V_59 , 0 ) ;
} else {
F_162 ( V_15 , V_1 , V_209 ) ;
}
#else
F_162 ( V_15 , V_1 , V_209 ) ;
#endif
}
return V_1 ;
}
static void * F_227 ( struct V_14 * V_15 , T_4 V_16 ,
bool V_95 )
{
int V_85 ;
struct V_3 * V_36 ;
struct V_34 * V_92 ;
int V_38 ;
F_190 () ;
V_38 = F_62 () ;
if ( F_49 ( V_95 ) )
goto V_253;
V_254:
V_92 = F_29 ( V_15 ) ;
V_85 = V_92 -> V_85 ;
if ( ! V_92 -> V_91 && V_85 > V_255 ) {
V_85 = V_255 ;
}
V_36 = V_15 -> V_38 [ V_38 ] ;
F_9 ( V_92 -> V_89 > 0 || ! V_36 ) ;
F_85 ( & V_36 -> V_11 ) ;
if ( V_36 -> V_8 && F_74 ( V_92 , V_36 -> V_8 , V_85 ) ) {
V_36 -> V_8 -> V_91 = 1 ;
goto V_256;
}
while ( V_85 > 0 ) {
struct V_239 * V_96 ;
struct V_23 * V_23 ;
V_96 = V_36 -> V_6 . V_257 ;
if ( V_96 == & V_36 -> V_6 ) {
V_36 -> V_13 = 1 ;
V_96 = V_36 -> V_7 . V_257 ;
if ( V_96 == & V_36 -> V_7 )
goto V_258;
}
V_23 = F_201 ( V_96 , struct V_23 , V_154 ) ;
F_193 ( V_15 ) ;
F_9 ( V_23 -> V_181 >= V_15 -> V_56 ) ;
while ( V_23 -> V_181 < V_15 -> V_56 && V_85 -- ) {
F_228 ( V_15 ) ;
F_229 ( V_15 ) ;
F_230 ( V_15 ) ;
F_73 ( V_15 , V_92 , F_214 ( V_15 , V_23 ,
V_38 ) ) ;
}
F_202 ( & V_23 -> V_154 ) ;
if ( V_23 -> V_181 == V_15 -> V_56 )
F_124 ( & V_23 -> V_148 , & V_36 -> V_5 ) ;
else
F_124 ( & V_23 -> V_148 , & V_36 -> V_6 ) ;
}
V_258:
V_36 -> V_12 -= V_92 -> V_89 ;
V_256:
F_87 ( & V_36 -> V_11 ) ;
if ( F_49 ( ! V_92 -> V_89 ) ) {
int V_259 ;
V_253:
V_259 = F_218 ( V_15 , V_16 | V_260 , V_38 , NULL ) ;
V_92 = F_29 ( V_15 ) ;
V_38 = F_62 () ;
if ( ! V_259 && ( V_92 -> V_89 == 0 || V_95 ) )
return NULL ;
if ( ! V_92 -> V_89 )
goto V_254;
}
V_92 -> V_91 = 1 ;
return F_70 ( V_15 , V_92 , V_16 , V_95 ) ;
}
static inline void F_231 ( struct V_14 * V_15 ,
T_4 V_16 )
{
F_232 ( V_16 & V_247 ) ;
#if V_228
F_213 ( V_15 , V_16 ) ;
#endif
}
static void * F_233 ( struct V_14 * V_15 ,
T_4 V_16 , void * V_1 , unsigned long V_201 )
{
if ( ! V_1 )
return V_1 ;
if ( V_15 -> V_16 & V_214 ) {
#ifdef F_170
if ( ( V_15 -> V_19 % V_59 ) == 0 && F_24 ( V_15 ) )
F_171 ( F_93 ( V_1 ) ,
V_15 -> V_19 / V_59 , 1 ) ;
else
F_167 ( V_15 , V_1 ) ;
#else
F_167 ( V_15 , V_1 ) ;
#endif
F_162 ( V_15 , V_1 , V_261 ) ;
}
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = ( void * ) V_201 ;
if ( V_15 -> V_16 & V_17 ) {
if ( * F_8 ( V_15 , V_1 ) != V_215 ||
* F_10 ( V_15 , V_1 ) != V_215 ) {
F_172 ( V_15 , L_32
L_33 ) ;
F_35 ( V_63
L_34 ,
V_1 , * F_8 ( V_15 , V_1 ) ,
* F_10 ( V_15 , V_1 ) ) ;
}
* F_8 ( V_15 , V_1 ) = V_252 ;
* F_10 ( V_15 , V_1 ) = V_252 ;
}
V_1 += F_7 ( V_15 ) ;
if ( V_15 -> V_193 && V_15 -> V_16 & V_214 )
V_15 -> V_193 ( V_1 ) ;
if ( V_262 &&
( ( unsigned long ) V_1 & ( V_262 - 1 ) ) ) {
F_35 ( V_63 L_35 ,
V_1 , ( int ) V_262 ) ;
}
return V_1 ;
}
static bool F_234 ( struct V_14 * V_15 , T_4 V_16 )
{
if ( V_15 == V_14 )
return false ;
return F_235 ( V_15 -> V_202 , V_16 , V_15 -> V_16 ) ;
}
static inline void * F_236 ( struct V_14 * V_15 , T_4 V_16 )
{
void * V_1 ;
struct V_34 * V_92 ;
bool V_95 = false ;
F_190 () ;
V_92 = F_29 ( V_15 ) ;
if ( F_94 ( V_92 -> V_89 ) ) {
V_92 -> V_91 = 1 ;
V_1 = F_70 ( V_15 , V_92 , V_16 , false ) ;
if ( V_1 ) {
F_237 ( V_15 ) ;
goto V_94;
}
V_95 = true ;
}
F_238 ( V_15 ) ;
V_1 = F_227 ( V_15 , V_16 , V_95 ) ;
V_92 = F_29 ( V_15 ) ;
V_94:
if ( V_1 )
F_239 ( & V_92 -> V_96 [ V_92 -> V_89 ] ) ;
return V_1 ;
}
static void * F_79 ( struct V_14 * V_15 , T_4 V_16 )
{
int V_263 , V_264 ;
if ( F_205 () || ( V_16 & V_265 ) )
return NULL ;
V_263 = V_264 = F_62 () ;
if ( F_240 () && ( V_15 -> V_16 & V_266 ) )
V_263 = F_241 () ;
else if ( V_196 -> V_267 )
V_263 = F_242 () ;
if ( V_263 != V_264 )
return F_80 ( V_15 , V_16 , V_263 ) ;
return NULL ;
}
static void * F_243 ( struct V_14 * V_25 , T_4 V_16 )
{
struct V_268 * V_268 ;
T_4 V_243 ;
struct V_269 * V_270 ;
struct V_271 * V_271 ;
enum V_272 V_273 = F_244 ( V_16 ) ;
void * V_22 = NULL ;
int V_140 ;
unsigned int V_274 ;
if ( V_16 & V_265 )
return NULL ;
V_243 = V_16 & ( V_245 | V_246 ) ;
V_275:
V_274 = F_245 () ;
V_268 = F_246 ( F_242 () , V_16 ) ;
V_254:
F_247 (zone, z, zonelist, high_zoneidx) {
V_140 = F_248 ( V_271 ) ;
if ( F_249 ( V_271 , V_16 ) &&
V_25 -> V_38 [ V_140 ] &&
V_25 -> V_38 [ V_140 ] -> V_12 ) {
V_22 = F_80 ( V_25 ,
V_16 | V_260 , V_140 ) ;
if ( V_22 )
break;
}
}
if ( ! V_22 ) {
struct V_23 * V_23 ;
if ( V_243 & V_247 )
F_219 () ;
F_213 ( V_25 , V_16 ) ;
V_23 = F_137 ( V_25 , V_243 , F_62 () ) ;
if ( V_243 & V_247 )
F_220 () ;
if ( V_23 ) {
V_140 = F_92 ( V_23 ) ;
if ( F_218 ( V_25 , V_16 , V_140 , V_23 ) ) {
V_22 = F_80 ( V_25 ,
V_16 | V_260 , V_140 ) ;
if ( ! V_22 )
goto V_254;
} else {
V_22 = NULL ;
}
}
}
if ( F_49 ( ! F_250 ( V_274 ) && ! V_22 ) )
goto V_275;
return V_22 ;
}
static void * F_80 ( struct V_14 * V_15 , T_4 V_16 ,
int V_102 )
{
struct V_239 * V_96 ;
struct V_23 * V_23 ;
struct V_3 * V_36 ;
void * V_22 ;
int V_259 ;
F_27 ( V_102 > F_251 () ) ;
V_36 = V_15 -> V_38 [ V_102 ] ;
F_9 ( ! V_36 ) ;
V_254:
F_190 () ;
F_85 ( & V_36 -> V_11 ) ;
V_96 = V_36 -> V_6 . V_257 ;
if ( V_96 == & V_36 -> V_6 ) {
V_36 -> V_13 = 1 ;
V_96 = V_36 -> V_7 . V_257 ;
if ( V_96 == & V_36 -> V_7 )
goto V_258;
}
V_23 = F_201 ( V_96 , struct V_23 , V_154 ) ;
F_196 ( V_15 , V_102 ) ;
F_252 ( V_15 ) ;
F_229 ( V_15 ) ;
F_230 ( V_15 ) ;
F_9 ( V_23 -> V_181 == V_15 -> V_56 ) ;
V_22 = F_214 ( V_15 , V_23 , V_102 ) ;
V_36 -> V_12 -- ;
F_202 ( & V_23 -> V_154 ) ;
if ( V_23 -> V_181 == V_15 -> V_56 )
F_124 ( & V_23 -> V_154 , & V_36 -> V_5 ) ;
else
F_124 ( & V_23 -> V_154 , & V_36 -> V_6 ) ;
F_87 ( & V_36 -> V_11 ) ;
goto V_276;
V_258:
F_87 ( & V_36 -> V_11 ) ;
V_259 = F_218 ( V_15 , V_16 | V_260 , V_102 , NULL ) ;
if ( V_259 )
goto V_254;
return F_243 ( V_15 , V_16 ) ;
V_276:
return V_22 ;
}
static T_8 void *
F_253 ( struct V_14 * V_15 , T_4 V_16 , int V_102 ,
unsigned long V_201 )
{
unsigned long V_277 ;
void * V_149 ;
int F_242 = F_62 () ;
V_16 &= V_278 ;
F_254 ( V_16 ) ;
if ( F_234 ( V_15 , V_16 ) )
return NULL ;
V_15 = F_255 ( V_15 , V_16 ) ;
F_231 ( V_15 , V_16 ) ;
F_256 ( V_277 ) ;
if ( V_102 == V_279 )
V_102 = F_242 ;
if ( F_49 ( ! V_15 -> V_38 [ V_102 ] ) ) {
V_149 = F_243 ( V_15 , V_16 ) ;
goto V_94;
}
if ( V_102 == F_242 ) {
V_149 = F_236 ( V_15 , V_16 ) ;
if ( V_149 )
goto V_94;
}
V_149 = F_80 ( V_15 , V_16 , V_102 ) ;
V_94:
F_257 ( V_277 ) ;
V_149 = F_233 ( V_15 , V_16 , V_149 , V_201 ) ;
F_258 ( V_149 , V_15 -> V_202 , 1 , V_15 -> V_16 ,
V_16 ) ;
if ( F_94 ( V_149 ) )
F_259 ( V_15 , V_16 , V_149 , V_15 -> V_202 ) ;
if ( F_49 ( ( V_16 & V_280 ) && V_149 ) )
memset ( V_149 , 0 , V_15 -> V_202 ) ;
return V_149 ;
}
static T_8 void *
F_260 ( struct V_14 * V_25 , T_4 V_16 )
{
void * V_1 ;
if ( F_49 ( V_196 -> V_16 & ( V_281 | V_282 ) ) ) {
V_1 = F_79 ( V_25 , V_16 ) ;
if ( V_1 )
goto V_94;
}
V_1 = F_236 ( V_25 , V_16 ) ;
if ( ! V_1 )
V_1 = F_80 ( V_25 , V_16 , F_62 () ) ;
V_94:
return V_1 ;
}
static T_8 void *
F_260 ( struct V_14 * V_15 , T_4 V_16 )
{
return F_236 ( V_15 , V_16 ) ;
}
static T_8 void *
F_261 ( struct V_14 * V_15 , T_4 V_16 , unsigned long V_201 )
{
unsigned long V_277 ;
void * V_1 ;
V_16 &= V_278 ;
F_254 ( V_16 ) ;
if ( F_234 ( V_15 , V_16 ) )
return NULL ;
V_15 = F_255 ( V_15 , V_16 ) ;
F_231 ( V_15 , V_16 ) ;
F_256 ( V_277 ) ;
V_1 = F_260 ( V_15 , V_16 ) ;
F_257 ( V_277 ) ;
V_1 = F_233 ( V_15 , V_16 , V_1 , V_201 ) ;
F_258 ( V_1 , V_15 -> V_202 , 1 , V_15 -> V_16 ,
V_16 ) ;
F_262 ( V_1 ) ;
if ( F_94 ( V_1 ) )
F_259 ( V_15 , V_16 , V_1 , V_15 -> V_202 ) ;
if ( F_49 ( ( V_16 & V_280 ) && V_1 ) )
memset ( V_1 , 0 , V_15 -> V_202 ) ;
return V_1 ;
}
static void F_86 ( struct V_14 * V_15 , void * * V_283 , int V_284 ,
int V_38 )
{
int V_43 ;
struct V_3 * V_36 ;
for ( V_43 = 0 ; V_43 < V_284 ; V_43 ++ ) {
void * V_1 ;
struct V_23 * V_23 ;
F_3 ( & V_283 [ V_43 ] ) ;
V_1 = V_283 [ V_43 ] ;
V_23 = F_13 ( V_1 ) ;
V_36 = V_15 -> V_38 [ V_38 ] ;
F_202 ( & V_23 -> V_154 ) ;
F_196 ( V_15 , V_38 ) ;
F_216 ( V_15 , V_23 , V_1 , V_38 ) ;
F_263 ( V_15 ) ;
V_36 -> V_12 ++ ;
if ( V_23 -> V_181 == 0 ) {
if ( V_36 -> V_12 > V_36 -> V_109 ) {
V_36 -> V_12 -= V_15 -> V_56 ;
F_173 ( V_15 , V_23 ) ;
} else {
F_124 ( & V_23 -> V_154 , & V_36 -> V_7 ) ;
}
} else {
F_221 ( & V_23 -> V_154 , & V_36 -> V_6 ) ;
}
}
}
static void F_264 ( struct V_14 * V_15 , struct V_34 * V_92 )
{
int V_85 ;
struct V_3 * V_36 ;
int V_38 = F_62 () ;
V_85 = V_92 -> V_85 ;
#if V_228
F_9 ( ! V_85 || V_85 > V_92 -> V_89 ) ;
#endif
F_190 () ;
V_36 = V_15 -> V_38 [ V_38 ] ;
F_85 ( & V_36 -> V_11 ) ;
if ( V_36 -> V_8 ) {
struct V_34 * V_285 = V_36 -> V_8 ;
int V_99 = V_285 -> V_90 - V_285 -> V_89 ;
if ( V_99 ) {
if ( V_85 > V_99 )
V_85 = V_99 ;
memcpy ( & ( V_285 -> V_96 [ V_285 -> V_89 ] ) ,
V_92 -> V_96 , sizeof( void * ) * V_85 ) ;
V_285 -> V_89 += V_85 ;
goto V_286;
}
}
F_86 ( V_15 , V_92 -> V_96 , V_85 , V_38 ) ;
V_286:
#if V_287
{
int V_43 = 0 ;
struct V_239 * V_240 ;
V_240 = V_36 -> V_7 . V_257 ;
while ( V_240 != & ( V_36 -> V_7 ) ) {
struct V_23 * V_23 ;
V_23 = F_201 ( V_240 , struct V_23 , V_154 ) ;
F_9 ( V_23 -> V_181 ) ;
V_43 ++ ;
V_240 = V_240 -> V_257 ;
}
F_265 ( V_15 , V_43 ) ;
}
#endif
F_87 ( & V_36 -> V_11 ) ;
V_92 -> V_89 -= V_85 ;
memmove ( V_92 -> V_96 , & ( V_92 -> V_96 [ V_85 ] ) , sizeof( void * ) * V_92 -> V_89 ) ;
}
static inline void F_266 ( struct V_14 * V_15 , void * V_1 ,
unsigned long V_201 )
{
struct V_34 * V_92 = F_29 ( V_15 ) ;
F_190 () ;
F_267 ( V_1 , V_15 -> V_16 ) ;
V_1 = F_226 ( V_15 , V_1 , V_201 ) ;
F_268 ( V_15 , V_1 , V_15 -> V_202 ) ;
if ( V_288 > 1 && F_78 ( V_15 , V_1 ) )
return;
if ( F_94 ( V_92 -> V_89 < V_92 -> V_90 ) ) {
F_269 ( V_15 ) ;
} else {
F_270 ( V_15 ) ;
F_264 ( V_15 , V_92 ) ;
}
F_73 ( V_15 , V_92 , V_1 ) ;
}
void * F_271 ( struct V_14 * V_15 , T_4 V_16 )
{
void * V_134 = F_261 ( V_15 , V_16 , V_289 ) ;
F_272 ( V_289 , V_134 ,
V_15 -> V_202 , V_15 -> V_19 , V_16 ) ;
return V_134 ;
}
void *
F_273 ( struct V_14 * V_15 , T_4 V_16 , T_2 V_19 )
{
void * V_134 ;
V_134 = F_261 ( V_15 , V_16 , V_289 ) ;
F_274 ( V_289 , V_134 ,
V_19 , V_15 -> V_19 , V_16 ) ;
return V_134 ;
}
void * F_210 ( struct V_14 * V_15 , T_4 V_16 , int V_102 )
{
void * V_134 = F_253 ( V_15 , V_16 , V_102 , V_289 ) ;
F_275 ( V_289 , V_134 ,
V_15 -> V_202 , V_15 -> V_19 ,
V_16 , V_102 ) ;
return V_134 ;
}
void * F_276 ( struct V_14 * V_15 ,
T_4 V_16 ,
int V_102 ,
T_2 V_19 )
{
void * V_134 ;
V_134 = F_253 ( V_15 , V_16 , V_102 , V_289 ) ;
F_277 ( V_289 , V_134 ,
V_19 , V_15 -> V_19 ,
V_16 , V_102 ) ;
return V_134 ;
}
static T_8 void *
F_278 ( T_2 V_19 , T_4 V_16 , int V_38 , unsigned long V_201 )
{
struct V_14 * V_15 ;
V_15 = F_186 ( V_19 , V_16 ) ;
if ( F_49 ( F_187 ( V_15 ) ) )
return V_15 ;
return F_276 ( V_15 , V_16 , V_38 , V_19 ) ;
}
void * F_279 ( T_2 V_19 , T_4 V_16 , int V_38 )
{
return F_278 ( V_19 , V_16 , V_38 , V_289 ) ;
}
void * F_280 ( T_2 V_19 , T_4 V_16 ,
int V_38 , unsigned long V_201 )
{
return F_278 ( V_19 , V_16 , V_38 , V_201 ) ;
}
void * F_279 ( T_2 V_19 , T_4 V_16 , int V_38 )
{
return F_278 ( V_19 , V_16 , V_38 , 0 ) ;
}
static T_8 void * F_281 ( T_2 V_19 , T_4 V_16 ,
unsigned long V_201 )
{
struct V_14 * V_15 ;
void * V_134 ;
V_15 = F_186 ( V_19 , V_16 ) ;
if ( F_49 ( F_187 ( V_15 ) ) )
return V_15 ;
V_134 = F_261 ( V_15 , V_16 , V_201 ) ;
F_274 ( V_201 , V_134 ,
V_19 , V_15 -> V_19 , V_16 ) ;
return V_134 ;
}
void * F_282 ( T_2 V_19 , T_4 V_16 )
{
return F_281 ( V_19 , V_16 , V_289 ) ;
}
void * F_283 ( T_2 V_19 , T_4 V_16 , unsigned long V_201 )
{
return F_281 ( V_19 , V_16 , V_201 ) ;
}
void * F_282 ( T_2 V_19 , T_4 V_16 )
{
return F_281 ( V_19 , V_16 , 0 ) ;
}
void F_175 ( struct V_14 * V_15 , void * V_1 )
{
unsigned long V_16 ;
V_15 = F_284 ( V_15 , V_1 ) ;
if ( ! V_15 )
return;
F_256 ( V_16 ) ;
F_285 ( V_1 , V_15 -> V_202 ) ;
if ( ! ( V_15 -> V_16 & V_115 ) )
F_286 ( V_1 , V_15 -> V_202 ) ;
F_266 ( V_15 , V_1 , V_289 ) ;
F_257 ( V_16 ) ;
F_287 ( V_289 , V_1 ) ;
}
void F_83 ( const void * V_1 )
{
struct V_14 * V_290 ;
unsigned long V_16 ;
F_288 ( V_289 , V_1 ) ;
if ( F_49 ( F_187 ( V_1 ) ) )
return;
F_256 ( V_16 ) ;
F_223 ( V_1 ) ;
V_290 = F_12 ( V_1 ) ;
F_285 ( V_1 , V_290 -> V_202 ) ;
F_286 ( V_1 , V_290 -> V_202 ) ;
F_266 ( V_290 , ( void * ) V_1 , V_289 ) ;
F_257 ( V_16 ) ;
}
static int F_289 ( struct V_14 * V_15 , T_4 V_86 )
{
int V_38 ;
struct V_3 * V_36 ;
struct V_34 * V_291 ;
struct V_34 * * V_292 = NULL ;
F_22 (node) {
if ( V_68 ) {
V_292 = F_76 ( V_38 , V_15 -> V_90 , V_86 ) ;
if ( ! V_292 )
goto V_293;
}
V_291 = NULL ;
if ( V_15 -> V_8 ) {
V_291 = F_56 ( V_38 ,
V_15 -> V_8 * V_15 -> V_85 ,
0xbaadf00d , V_86 ) ;
if ( ! V_291 ) {
F_77 ( V_292 ) ;
goto V_293;
}
}
V_36 = V_15 -> V_38 [ V_38 ] ;
if ( V_36 ) {
struct V_34 * V_8 = V_36 -> V_8 ;
F_98 ( & V_36 -> V_11 ) ;
if ( V_8 )
F_86 ( V_15 , V_8 -> V_96 ,
V_8 -> V_89 , V_38 ) ;
V_36 -> V_8 = V_291 ;
if ( ! V_36 -> V_9 ) {
V_36 -> V_9 = V_292 ;
V_292 = NULL ;
}
V_36 -> V_109 = ( 1 + F_99 ( V_38 ) ) *
V_15 -> V_85 + V_15 -> V_56 ;
F_90 ( & V_36 -> V_11 ) ;
F_83 ( V_8 ) ;
F_77 ( V_292 ) ;
continue;
}
V_36 = F_57 ( sizeof( struct V_3 ) , V_86 , V_38 ) ;
if ( ! V_36 ) {
F_77 ( V_292 ) ;
F_83 ( V_291 ) ;
goto V_293;
}
F_4 ( V_36 ) ;
V_36 -> V_106 = V_107 + V_108 +
( ( unsigned long ) V_15 ) % V_108 ;
V_36 -> V_8 = V_291 ;
V_36 -> V_9 = V_292 ;
V_36 -> V_109 = ( 1 + F_99 ( V_38 ) ) *
V_15 -> V_85 + V_15 -> V_56 ;
V_15 -> V_38 [ V_38 ] = V_36 ;
}
return 0 ;
V_293:
if ( ! V_15 -> V_148 . V_257 ) {
V_38 -- ;
while ( V_38 >= 0 ) {
if ( V_15 -> V_38 [ V_38 ] ) {
V_36 = V_15 -> V_38 [ V_38 ] ;
F_83 ( V_36 -> V_8 ) ;
F_77 ( V_36 -> V_9 ) ;
F_83 ( V_36 ) ;
V_15 -> V_38 [ V_38 ] = NULL ;
}
V_38 -- ;
}
}
return - V_105 ;
}
static void F_290 ( void * V_294 )
{
struct V_295 * V_296 = V_294 ;
struct V_34 * V_297 ;
F_190 () ;
V_297 = F_29 ( V_296 -> V_15 ) ;
V_296 -> V_15 -> V_50 [ F_30 () ] = V_296 -> V_296 [ F_30 () ] ;
V_296 -> V_296 [ F_30 () ] = V_297 ;
}
static int F_291 ( struct V_14 * V_15 , int V_90 ,
int V_85 , int V_8 , T_4 V_86 )
{
struct V_295 * V_296 ;
int V_43 ;
V_296 = F_292 ( sizeof( * V_296 ) + V_153 * sizeof( struct V_34 * ) ,
V_86 ) ;
if ( ! V_296 )
return - V_105 ;
F_135 (i) {
V_296 -> V_296 [ V_43 ] = F_56 ( F_44 ( V_43 ) , V_90 ,
V_85 , V_86 ) ;
if ( ! V_296 -> V_296 [ V_43 ] ) {
for ( V_43 -- ; V_43 >= 0 ; V_43 -- )
F_83 ( V_296 -> V_296 [ V_43 ] ) ;
F_83 ( V_296 ) ;
return - V_105 ;
}
}
V_296 -> V_15 = V_15 ;
F_199 ( F_290 , ( void * ) V_296 , 1 ) ;
F_192 () ;
V_15 -> V_85 = V_85 ;
V_15 -> V_90 = V_90 ;
V_15 -> V_8 = V_8 ;
F_135 (i) {
struct V_34 * V_298 = V_296 -> V_296 [ V_43 ] ;
if ( ! V_298 )
continue;
F_98 ( & V_15 -> V_38 [ F_44 ( V_43 ) ] -> V_11 ) ;
F_86 ( V_15 , V_298 -> V_96 , V_298 -> V_89 , F_44 ( V_43 ) ) ;
F_90 ( & V_15 -> V_38 [ F_44 ( V_43 ) ] -> V_11 ) ;
F_83 ( V_298 ) ;
}
F_83 ( V_296 ) ;
return F_289 ( V_15 , V_86 ) ;
}
static int F_293 ( struct V_14 * V_15 , int V_90 ,
int V_85 , int V_8 , T_4 V_86 )
{
int V_134 ;
struct V_14 * V_290 = NULL ;
int V_43 = 0 ;
V_134 = F_291 ( V_15 , V_90 , V_85 , V_8 , V_86 ) ;
if ( V_44 < V_172 )
return V_134 ;
if ( ( V_134 < 0 ) || ! F_294 ( V_15 ) )
return V_134 ;
F_27 ( ! F_295 ( & V_123 ) ) ;
F_296 (i) {
V_290 = F_297 ( V_15 , V_43 ) ;
if ( V_290 )
F_291 ( V_290 , V_90 , V_85 , V_8 , V_86 ) ;
}
return V_134 ;
}
static int F_130 ( struct V_14 * V_15 , T_4 V_86 )
{
int V_113 ;
int V_90 = 0 ;
int V_8 = 0 ;
int V_85 = 0 ;
if ( ! F_294 ( V_15 ) ) {
struct V_14 * V_299 = F_298 ( V_15 ) ;
V_90 = V_299 -> V_90 ;
V_8 = V_299 -> V_8 ;
V_85 = V_299 -> V_85 ;
}
if ( V_90 && V_8 && V_85 )
goto V_300;
if ( V_15 -> V_19 > 131072 )
V_90 = 1 ;
else if ( V_15 -> V_19 > V_59 )
V_90 = 8 ;
else if ( V_15 -> V_19 > 1024 )
V_90 = 24 ;
else if ( V_15 -> V_19 > 256 )
V_90 = 54 ;
else
V_90 = 120 ;
V_8 = 0 ;
if ( V_15 -> V_19 <= V_59 && F_299 () > 1 )
V_8 = 8 ;
#if V_228
if ( V_90 > 32 )
V_90 = 32 ;
#endif
V_85 = ( V_90 + 1 ) / 2 ;
V_300:
V_113 = F_293 ( V_15 , V_90 , V_85 , V_8 , V_86 ) ;
if ( V_113 )
F_35 ( V_63 L_36 ,
V_15 -> V_64 , - V_113 ) ;
return V_113 ;
}
static void F_200 ( struct V_14 * V_15 , struct V_3 * V_36 ,
struct V_34 * V_92 , int V_301 , int V_38 )
{
int V_238 ;
if ( ! V_92 || ! V_92 -> V_89 )
return;
if ( V_92 -> V_91 && ! V_301 ) {
V_92 -> V_91 = 0 ;
} else {
F_98 ( & V_36 -> V_11 ) ;
if ( V_92 -> V_89 ) {
V_238 = V_301 ? V_92 -> V_89 : ( V_92 -> V_90 + 4 ) / 5 ;
if ( V_238 > V_92 -> V_89 )
V_238 = ( V_92 -> V_89 + 1 ) / 2 ;
F_86 ( V_15 , V_92 -> V_96 , V_238 , V_38 ) ;
V_92 -> V_89 -= V_238 ;
memmove ( V_92 -> V_96 , & ( V_92 -> V_96 [ V_238 ] ) ,
sizeof( void * ) * V_92 -> V_89 ) ;
}
F_90 ( & V_36 -> V_11 ) ;
}
}
static void V_82 ( struct V_302 * V_303 )
{
struct V_14 * V_304 ;
struct V_3 * V_36 ;
int V_38 = F_62 () ;
struct V_77 * V_80 = F_300 ( V_303 ) ;
if ( ! F_301 ( & V_123 ) )
goto V_94;
F_64 (searchp, &slab_caches, list) {
F_192 () ;
V_36 = V_304 -> V_38 [ V_38 ] ;
F_88 ( V_304 , V_36 ) ;
F_200 ( V_304 , V_36 , F_29 ( V_304 ) , 0 , V_38 ) ;
if ( F_302 ( V_36 -> V_106 , V_107 ) )
goto V_257;
V_36 -> V_106 = V_107 + V_108 ;
F_200 ( V_304 , V_36 , V_36 -> V_8 , 0 , V_38 ) ;
if ( V_36 -> V_13 )
V_36 -> V_13 = 0 ;
else {
int V_305 ;
V_305 = F_104 ( V_304 , V_36 , ( V_36 -> V_109 +
5 * V_304 -> V_56 - 1 ) / ( 5 * V_304 -> V_56 ) ) ;
F_303 ( V_304 , V_305 ) ;
}
V_257:
F_304 () ;
}
F_192 () ;
F_109 ( & V_123 ) ;
F_47 () ;
V_94:
F_305 ( V_80 , F_306 ( V_306 ) ) ;
}
void F_307 ( struct V_14 * V_15 , struct V_307 * V_308 )
{
struct V_23 * V_23 ;
unsigned long V_177 ;
unsigned long V_178 ;
unsigned long V_179 = 0 ;
unsigned long V_180 , V_12 = 0 , V_309 = 0 ;
const char * V_64 ;
char * error = NULL ;
int V_38 ;
struct V_3 * V_36 ;
V_177 = 0 ;
V_180 = 0 ;
F_22 (node) {
V_36 = V_15 -> V_38 [ V_38 ] ;
if ( ! V_36 )
continue;
F_192 () ;
F_98 ( & V_36 -> V_11 ) ;
F_64 (page, &n->slabs_full, lru) {
if ( V_23 -> V_181 != V_15 -> V_56 && ! error )
error = L_37 ;
V_177 += V_15 -> V_56 ;
V_179 ++ ;
}
F_64 (page, &n->slabs_partial, lru) {
if ( V_23 -> V_181 == V_15 -> V_56 && ! error )
error = L_38 ;
if ( ! V_23 -> V_181 && ! error )
error = L_38 ;
V_177 += V_23 -> V_181 ;
V_179 ++ ;
}
F_64 (page, &n->slabs_free, lru) {
if ( V_23 -> V_181 && ! error )
error = L_39 ;
V_180 ++ ;
}
V_12 += V_36 -> V_12 ;
if ( V_36 -> V_8 )
V_309 += V_36 -> V_8 -> V_89 ;
F_90 ( & V_36 -> V_11 ) ;
}
V_180 += V_179 ;
V_178 = V_180 * V_15 -> V_56 ;
if ( V_178 - V_177 != V_12 && ! error )
error = L_40 ;
V_64 = V_15 -> V_64 ;
if ( error )
F_35 ( V_63 L_41 , V_64 , error ) ;
V_308 -> V_177 = V_177 ;
V_308 -> V_178 = V_178 ;
V_308 -> V_179 = V_179 ;
V_308 -> V_180 = V_180 ;
V_308 -> V_309 = V_309 ;
V_308 -> V_90 = V_15 -> V_90 ;
V_308 -> V_85 = V_15 -> V_85 ;
V_308 -> V_8 = V_15 -> V_8 ;
V_308 -> V_310 = V_15 -> V_56 ;
V_308 -> V_311 = V_15 -> V_53 ;
}
void F_308 ( struct V_312 * V_313 , struct V_14 * V_15 )
{
#if V_287
{
unsigned long V_314 = V_15 -> V_315 ;
unsigned long V_316 = V_15 -> V_317 ;
unsigned long V_318 = V_15 -> V_318 ;
unsigned long V_319 = V_15 -> V_319 ;
unsigned long V_320 = V_15 -> V_320 ;
unsigned long V_321 = V_15 -> V_321 ;
unsigned long V_322 = V_15 -> V_322 ;
unsigned long V_323 = V_15 -> V_323 ;
unsigned long V_324 = V_15 -> V_325 ;
F_309 ( V_313 , L_42
L_43 ,
V_316 , V_314 , V_318 ,
V_319 , V_320 , V_321 , V_322 ,
V_323 , V_324 ) ;
}
{
unsigned long V_326 = F_310 ( & V_15 -> V_326 ) ;
unsigned long V_327 = F_310 ( & V_15 -> V_327 ) ;
unsigned long V_328 = F_310 ( & V_15 -> V_328 ) ;
unsigned long V_329 = F_310 ( & V_15 -> V_329 ) ;
F_309 ( V_313 , L_44 ,
V_326 , V_327 , V_328 , V_329 ) ;
}
#endif
}
T_9 F_311 ( struct V_330 * V_330 , const char T_10 * V_331 ,
T_2 V_332 , T_11 * V_333 )
{
char V_334 [ V_335 + 1 ] , * V_336 ;
int V_90 , V_85 , V_8 , V_337 ;
struct V_14 * V_15 ;
if ( V_332 > V_335 )
return - V_338 ;
if ( F_312 ( & V_334 , V_331 , V_332 ) )
return - V_339 ;
V_334 [ V_335 ] = '\0' ;
V_336 = strchr ( V_334 , ' ' ) ;
if ( ! V_336 )
return - V_338 ;
* V_336 = '\0' ;
V_336 ++ ;
if ( sscanf ( V_336 , L_45 , & V_90 , & V_85 , & V_8 ) != 3 )
return - V_338 ;
F_108 ( & V_123 ) ;
V_337 = - V_338 ;
F_64 (cachep, &slab_caches, list) {
if ( ! strcmp ( V_15 -> V_64 , V_334 ) ) {
if ( V_90 < 1 || V_85 < 1 ||
V_85 > V_90 || V_8 < 0 ) {
V_337 = 0 ;
} else {
V_337 = F_293 ( V_15 , V_90 ,
V_85 , V_8 ,
V_104 ) ;
}
break;
}
}
F_109 ( & V_123 ) ;
if ( V_337 >= 0 )
V_337 = V_332 ;
return V_337 ;
}
static void * F_313 ( struct V_312 * V_313 , T_11 * V_340 )
{
F_108 ( & V_123 ) ;
return F_314 ( & V_163 , * V_340 ) ;
}
static inline int F_315 ( unsigned long * V_36 , unsigned long V_341 )
{
unsigned long * V_240 ;
int V_342 ;
if ( ! V_341 )
return 1 ;
V_342 = V_36 [ 1 ] ;
V_240 = V_36 + 2 ;
while ( V_342 ) {
int V_43 = V_342 / 2 ;
unsigned long * V_33 = V_240 + 2 * V_43 ;
if ( * V_33 == V_341 ) {
V_33 [ 1 ] ++ ;
return 1 ;
}
if ( * V_33 > V_341 ) {
V_342 = V_43 ;
} else {
V_240 = V_33 + 2 ;
V_342 -= V_43 + 1 ;
}
}
if ( ++ V_36 [ 1 ] == V_36 [ 0 ] )
return 0 ;
memmove ( V_240 + 2 , V_240 , V_36 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_240 - ( void * ) V_36 ) ) ;
V_240 [ 0 ] = V_341 ;
V_240 [ 1 ] = 1 ;
return 1 ;
}
static void F_316 ( unsigned long * V_36 , struct V_14 * V_290 ,
struct V_23 * V_23 )
{
void * V_240 ;
int V_43 , V_343 ;
if ( V_36 [ 0 ] == V_36 [ 1 ] )
return;
for ( V_43 = 0 , V_240 = V_23 -> V_27 ; V_43 < V_290 -> V_56 ; V_43 ++ , V_240 += V_290 -> V_19 ) {
bool V_181 = true ;
for ( V_343 = V_23 -> V_181 ; V_343 < V_290 -> V_56 ; V_343 ++ ) {
if ( F_211 ( V_23 ) [ V_343 ] == V_43 ) {
V_181 = false ;
break;
}
}
if ( ! V_181 )
continue;
if ( ! F_315 ( V_36 , ( unsigned long ) * F_11 ( V_290 , V_240 ) ) )
return;
}
}
static void F_317 ( struct V_312 * V_313 , unsigned long V_344 )
{
#ifdef F_318
unsigned long V_28 , V_19 ;
char V_345 [ V_346 ] , V_64 [ V_347 ] ;
if ( F_319 ( V_344 , & V_19 , & V_28 , V_345 , V_64 ) == 0 ) {
F_309 ( V_313 , L_46 , V_64 , V_28 , V_19 ) ;
if ( V_345 [ 0 ] )
F_309 ( V_313 , L_47 , V_345 ) ;
return;
}
#endif
F_309 ( V_313 , L_48 , ( void * ) V_344 ) ;
}
static int F_320 ( struct V_312 * V_313 , void * V_240 )
{
struct V_14 * V_15 = F_201 ( V_240 , struct V_14 , V_148 ) ;
struct V_23 * V_23 ;
struct V_3 * V_36 ;
const char * V_64 ;
unsigned long * V_259 = V_313 -> V_348 ;
int V_38 ;
int V_43 ;
if ( ! ( V_15 -> V_16 & V_18 ) )
return 0 ;
if ( ! ( V_15 -> V_16 & V_17 ) )
return 0 ;
V_259 [ 1 ] = 0 ;
F_22 (node) {
V_36 = V_15 -> V_38 [ V_38 ] ;
if ( ! V_36 )
continue;
F_192 () ;
F_98 ( & V_36 -> V_11 ) ;
F_64 (page, &n->slabs_full, lru)
F_316 ( V_259 , V_15 , V_23 ) ;
F_64 (page, &n->slabs_partial, lru)
F_316 ( V_259 , V_15 , V_23 ) ;
F_90 ( & V_36 -> V_11 ) ;
}
V_64 = V_15 -> V_64 ;
if ( V_259 [ 0 ] == V_259 [ 1 ] ) {
F_109 ( & V_123 ) ;
V_313 -> V_348 = F_292 ( V_259 [ 0 ] * 4 * sizeof( unsigned long ) , V_104 ) ;
if ( ! V_313 -> V_348 ) {
V_313 -> V_348 = V_259 ;
F_108 ( & V_123 ) ;
return - V_105 ;
}
* ( unsigned long * ) V_313 -> V_348 = V_259 [ 0 ] * 2 ;
F_83 ( V_259 ) ;
F_108 ( & V_123 ) ;
V_313 -> V_332 = V_313 -> V_19 ;
return 0 ;
}
for ( V_43 = 0 ; V_43 < V_259 [ 1 ] ; V_43 ++ ) {
F_309 ( V_313 , L_49 , V_64 , V_259 [ 2 * V_43 + 3 ] ) ;
F_317 ( V_313 , V_259 [ 2 * V_43 + 2 ] ) ;
F_321 ( V_313 , '\n' ) ;
}
return 0 ;
}
static int F_322 ( struct V_349 * V_349 , struct V_330 * V_330 )
{
unsigned long * V_36 = F_292 ( V_59 , V_104 ) ;
int V_134 = - V_105 ;
if ( V_36 ) {
V_134 = F_323 ( V_330 , & V_350 ) ;
if ( ! V_134 ) {
struct V_312 * V_313 = V_330 -> V_351 ;
* V_36 = V_59 / ( 2 * sizeof( unsigned long ) ) ;
V_313 -> V_348 = V_36 ;
V_36 = NULL ;
}
F_83 ( V_36 ) ;
}
return V_134 ;
}
static int T_3 F_324 ( void )
{
#ifdef F_325
F_326 ( L_50 , 0 , NULL , & V_352 ) ;
#endif
return 0 ;
}
T_2 F_327 ( const void * V_1 )
{
F_9 ( ! V_1 ) ;
if ( F_49 ( V_1 == V_353 ) )
return 0 ;
return F_12 ( V_1 ) -> V_202 ;
}
