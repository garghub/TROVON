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
static int F_31 ( T_2 V_51 , T_2 V_52 ,
T_2 V_53 , T_2 V_54 )
{
int V_55 ;
T_2 V_56 ;
V_55 = V_51 / ( V_52 + V_53 ) ;
V_56 = V_51 - V_55 * V_52 ;
if ( V_56 < F_32 ( V_55 * V_53 , V_54 ) )
V_55 -- ;
return V_55 ;
}
static void F_33 ( unsigned long V_57 , T_2 V_52 ,
T_2 V_54 , int V_16 , T_2 * V_58 ,
unsigned int * V_59 )
{
int V_55 ;
T_2 V_60 ;
T_2 V_51 = V_61 << V_57 ;
if ( V_16 & V_62 ) {
V_60 = 0 ;
V_55 = V_51 / V_52 ;
} else {
V_55 = F_31 ( V_51 , V_52 ,
sizeof( V_63 ) , V_54 ) ;
V_60 = F_32 ( V_55 * sizeof( V_63 ) , V_54 ) ;
}
* V_59 = V_55 ;
* V_58 = V_51 - V_55 * V_52 - V_60 ;
}
static void F_34 ( const char * V_64 , struct V_14 * V_15 ,
char * V_65 )
{
F_35 ( V_66 L_1 ,
V_64 , V_15 -> V_67 , V_65 ) ;
F_36 () ;
F_37 ( V_68 , V_69 ) ;
}
static int T_3 F_38 ( char * V_70 )
{
V_71 = 0 ;
return 1 ;
}
static int T_3 F_39 ( char * V_72 )
{
F_40 ( & V_72 , & V_73 ) ;
V_73 = V_73 < 0 ? 0 :
F_41 ( V_73 , V_74 - 1 ) ;
V_75 = true ;
return 1 ;
}
static void F_42 ( int V_76 )
{
int V_38 ;
V_38 = F_43 ( F_44 ( V_76 ) , V_77 ) ;
if ( V_38 == V_78 )
V_38 = F_45 ( V_77 ) ;
F_46 ( V_79 , V_76 ) = V_38 ;
}
static void F_47 ( void )
{
int V_38 = F_48 ( V_79 ) ;
V_38 = F_43 ( V_38 , V_77 ) ;
if ( F_49 ( V_38 >= V_78 ) )
V_38 = F_45 ( V_77 ) ;
F_50 ( V_79 , V_38 ) ;
}
static void F_51 ( int V_76 )
{
struct V_80 * V_81 = & F_46 ( V_82 , V_76 ) ;
if ( F_52 () && V_81 -> V_83 . V_84 == NULL ) {
F_42 ( V_76 ) ;
F_53 ( V_81 , V_85 ) ;
F_54 ( V_76 , V_81 ,
F_55 ( V_86 , V_76 ) ) ;
}
}
static struct V_34 * F_56 ( int V_38 , int V_87 ,
int V_88 , T_4 V_89 )
{
int V_90 = sizeof( void * ) * V_87 + sizeof( struct V_34 ) ;
struct V_34 * V_91 = NULL ;
V_91 = F_57 ( V_90 , V_89 , V_38 ) ;
F_58 ( V_91 ) ;
if ( V_91 ) {
V_91 -> V_92 = 0 ;
V_91 -> V_93 = V_87 ;
V_91 -> V_88 = V_88 ;
V_91 -> V_94 = 0 ;
F_6 ( & V_91 -> V_40 ) ;
}
return V_91 ;
}
static inline bool F_59 ( struct V_23 * V_23 )
{
return F_60 ( V_23 ) ;
}
static void F_61 ( struct V_14 * V_15 ,
struct V_34 * V_95 )
{
struct V_3 * V_36 = V_15 -> V_38 [ F_62 () ] ;
struct V_23 * V_23 ;
unsigned long V_16 ;
if ( ! V_96 )
return;
F_63 ( & V_36 -> V_11 , V_16 ) ;
F_64 (page, &n->slabs_full, lru)
if ( F_59 ( V_23 ) )
goto V_97;
F_64 (page, &n->slabs_partial, lru)
if ( F_59 ( V_23 ) )
goto V_97;
F_64 (page, &n->slabs_free, lru)
if ( F_59 ( V_23 ) )
goto V_97;
V_96 = false ;
V_97:
F_65 ( & V_36 -> V_11 , V_16 ) ;
}
static void * F_66 ( struct V_14 * V_15 , struct V_34 * V_95 ,
T_4 V_16 , bool V_98 )
{
int V_43 ;
void * V_1 = V_95 -> V_99 [ -- V_95 -> V_92 ] ;
if ( F_49 ( F_1 ( V_1 ) ) ) {
struct V_3 * V_36 ;
if ( F_67 ( V_16 ) ) {
F_3 ( & V_1 ) ;
return V_1 ;
}
for ( V_43 = 0 ; V_43 < V_95 -> V_92 ; V_43 ++ ) {
if ( ! F_1 ( V_95 -> V_99 [ V_43 ] ) ) {
V_1 = V_95 -> V_99 [ V_43 ] ;
V_95 -> V_99 [ V_43 ] = V_95 -> V_99 [ V_95 -> V_92 ] ;
V_95 -> V_99 [ V_95 -> V_92 ] = V_1 ;
return V_1 ;
}
}
V_36 = V_15 -> V_38 [ F_62 () ] ;
if ( ! F_68 ( & V_36 -> V_7 ) && V_98 ) {
struct V_23 * V_23 = F_13 ( V_1 ) ;
F_69 ( V_23 ) ;
F_3 ( & V_1 ) ;
F_61 ( V_15 , V_95 ) ;
return V_1 ;
}
V_95 -> V_92 ++ ;
V_1 = NULL ;
}
return V_1 ;
}
static inline void * F_70 ( struct V_14 * V_15 ,
struct V_34 * V_95 , T_4 V_16 , bool V_98 )
{
void * V_1 ;
if ( F_49 ( F_71 () ) )
V_1 = F_66 ( V_15 , V_95 , V_16 , V_98 ) ;
else
V_1 = V_95 -> V_99 [ -- V_95 -> V_92 ] ;
return V_1 ;
}
static void * F_72 ( struct V_14 * V_15 , struct V_34 * V_95 ,
void * V_1 )
{
if ( F_49 ( V_96 ) ) {
struct V_23 * V_23 = F_13 ( V_1 ) ;
if ( F_60 ( V_23 ) )
F_2 ( & V_1 ) ;
}
return V_1 ;
}
static inline void F_73 ( struct V_14 * V_15 , struct V_34 * V_95 ,
void * V_1 )
{
if ( F_49 ( F_71 () ) )
V_1 = F_72 ( V_15 , V_95 , V_1 ) ;
V_95 -> V_99 [ V_95 -> V_92 ++ ] = V_1 ;
}
static int F_74 ( struct V_34 * V_100 ,
struct V_34 * V_101 , unsigned int V_102 )
{
int V_103 = F_75 ( V_101 -> V_92 , V_102 , V_100 -> V_93 - V_100 -> V_92 ) ;
if ( ! V_103 )
return 0 ;
memcpy ( V_100 -> V_99 + V_100 -> V_92 , V_101 -> V_99 + V_101 -> V_92 - V_103 ,
sizeof( void * ) * V_103 ) ;
V_101 -> V_92 -= V_103 ;
V_100 -> V_92 += V_103 ;
return V_103 ;
}
static inline struct V_34 * * F_76 ( int V_38 , int V_93 , T_4 V_89 )
{
return (struct V_34 * * ) V_39 ;
}
static inline void F_77 ( struct V_34 * * V_104 )
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
T_4 V_16 , int V_105 )
{
return NULL ;
}
static struct V_34 * * F_76 ( int V_38 , int V_93 , T_4 V_89 )
{
struct V_34 * * V_104 ;
int V_90 = sizeof( void * ) * V_106 ;
int V_43 ;
if ( V_93 > 1 )
V_93 = 12 ;
V_104 = F_81 ( V_90 , V_89 , V_38 ) ;
if ( V_104 ) {
F_19 (i) {
if ( V_43 == V_38 || ! F_82 ( V_43 ) )
continue;
V_104 [ V_43 ] = F_56 ( V_38 , V_93 , 0xbaadf00d , V_89 ) ;
if ( ! V_104 [ V_43 ] ) {
for ( V_43 -- ; V_43 >= 0 ; V_43 -- )
F_83 ( V_104 [ V_43 ] ) ;
F_83 ( V_104 ) ;
return NULL ;
}
}
}
return V_104 ;
}
static void F_77 ( struct V_34 * * V_104 )
{
int V_43 ;
if ( ! V_104 )
return;
F_19 (i)
F_83 ( V_104 [ V_43 ] ) ;
F_83 ( V_104 ) ;
}
static void F_84 ( struct V_14 * V_15 ,
struct V_34 * V_95 , int V_38 )
{
struct V_3 * V_36 = V_15 -> V_38 [ V_38 ] ;
if ( V_95 -> V_92 ) {
F_85 ( & V_36 -> V_11 ) ;
if ( V_36 -> V_8 )
F_74 ( V_36 -> V_8 , V_95 , V_95 -> V_93 ) ;
F_86 ( V_15 , V_95 -> V_99 , V_95 -> V_92 , V_38 ) ;
V_95 -> V_92 = 0 ;
F_87 ( & V_36 -> V_11 ) ;
}
}
static void F_88 ( struct V_14 * V_15 , struct V_3 * V_36 )
{
int V_38 = F_48 ( V_79 ) ;
if ( V_36 -> V_9 ) {
struct V_34 * V_95 = V_36 -> V_9 [ V_38 ] ;
if ( V_95 && V_95 -> V_92 && F_89 ( & V_95 -> V_40 ) ) {
F_84 ( V_15 , V_95 , V_38 ) ;
F_90 ( & V_95 -> V_40 ) ;
}
}
}
static void F_91 ( struct V_14 * V_15 ,
struct V_34 * * V_9 )
{
int V_43 = 0 ;
struct V_34 * V_95 ;
unsigned long V_16 ;
F_22 (i) {
V_95 = V_9 [ V_43 ] ;
if ( V_95 ) {
F_63 ( & V_95 -> V_40 , V_16 ) ;
F_84 ( V_15 , V_95 , V_43 ) ;
F_65 ( & V_95 -> V_40 , V_16 ) ;
}
}
}
static inline int F_78 ( struct V_14 * V_15 , void * V_1 )
{
int V_105 = F_92 ( F_93 ( V_1 ) ) ;
struct V_3 * V_36 ;
struct V_34 * V_9 = NULL ;
int V_38 ;
V_38 = F_62 () ;
if ( F_94 ( V_105 == V_38 ) )
return 0 ;
V_36 = V_15 -> V_38 [ V_38 ] ;
F_95 ( V_15 ) ;
if ( V_36 -> V_9 && V_36 -> V_9 [ V_105 ] ) {
V_9 = V_36 -> V_9 [ V_105 ] ;
F_85 ( & V_9 -> V_40 ) ;
if ( F_49 ( V_9 -> V_92 == V_9 -> V_93 ) ) {
F_96 ( V_15 ) ;
F_84 ( V_15 , V_9 , V_105 ) ;
}
F_73 ( V_15 , V_9 , V_1 ) ;
F_87 ( & V_9 -> V_40 ) ;
} else {
F_85 ( & ( V_15 -> V_38 [ V_105 ] ) -> V_11 ) ;
F_86 ( V_15 , & V_1 , 1 , V_105 ) ;
F_87 ( & ( V_15 -> V_38 [ V_105 ] ) -> V_11 ) ;
}
return 1 ;
}
static int F_97 ( int V_38 )
{
struct V_14 * V_15 ;
struct V_3 * V_36 ;
const int V_90 = sizeof( struct V_3 ) ;
F_64 (cachep, &slab_caches, list) {
if ( ! V_15 -> V_38 [ V_38 ] ) {
V_36 = F_57 ( V_90 , V_107 , V_38 ) ;
if ( ! V_36 )
return - V_108 ;
F_4 ( V_36 ) ;
V_36 -> V_109 = V_110 + V_111 +
( ( unsigned long ) V_15 ) % V_111 ;
V_15 -> V_38 [ V_38 ] = V_36 ;
}
F_98 ( & V_15 -> V_38 [ V_38 ] -> V_11 ) ;
V_15 -> V_38 [ V_38 ] -> V_112 =
( 1 + F_99 ( V_38 ) ) *
V_15 -> V_88 + V_15 -> V_59 ;
F_90 ( & V_15 -> V_38 [ V_38 ] -> V_11 ) ;
}
return 0 ;
}
static inline int F_100 ( struct V_14 * V_15 ,
struct V_3 * V_36 )
{
return ( V_36 -> V_12 + V_15 -> V_59 - 1 ) / V_15 -> V_59 ;
}
static void F_101 ( long V_76 )
{
struct V_14 * V_15 ;
struct V_3 * V_36 = NULL ;
int V_38 = F_44 ( V_76 ) ;
const struct V_113 * V_114 = F_102 ( V_38 ) ;
F_64 (cachep, &slab_caches, list) {
struct V_34 * V_91 ;
struct V_34 * V_8 ;
struct V_34 * * V_9 ;
V_91 = V_15 -> V_50 [ V_76 ] ;
V_15 -> V_50 [ V_76 ] = NULL ;
V_36 = V_15 -> V_38 [ V_38 ] ;
if ( ! V_36 )
goto V_115;
F_98 ( & V_36 -> V_11 ) ;
V_36 -> V_112 -= V_15 -> V_88 ;
if ( V_91 )
F_86 ( V_15 , V_91 -> V_99 , V_91 -> V_92 , V_38 ) ;
if ( ! F_103 ( V_114 ) ) {
F_90 ( & V_36 -> V_11 ) ;
goto V_115;
}
V_8 = V_36 -> V_8 ;
if ( V_8 ) {
F_86 ( V_15 , V_8 -> V_99 ,
V_8 -> V_92 , V_38 ) ;
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
V_115:
F_83 ( V_91 ) ;
}
F_64 (cachep, &slab_caches, list) {
V_36 = V_15 -> V_38 [ V_38 ] ;
if ( ! V_36 )
continue;
F_104 ( V_15 , V_36 , F_100 ( V_15 , V_36 ) ) ;
}
}
static int F_105 ( long V_76 )
{
struct V_14 * V_15 ;
struct V_3 * V_36 = NULL ;
int V_38 = F_44 ( V_76 ) ;
int V_116 ;
V_116 = F_97 ( V_38 ) ;
if ( V_116 < 0 )
goto V_117;
F_64 (cachep, &slab_caches, list) {
struct V_34 * V_91 ;
struct V_34 * V_8 = NULL ;
struct V_34 * * V_9 = NULL ;
V_91 = F_56 ( V_38 , V_15 -> V_93 ,
V_15 -> V_88 , V_107 ) ;
if ( ! V_91 )
goto V_117;
if ( V_15 -> V_8 ) {
V_8 = F_56 ( V_38 ,
V_15 -> V_8 * V_15 -> V_88 ,
0xbaadf00d , V_107 ) ;
if ( ! V_8 ) {
F_83 ( V_91 ) ;
goto V_117;
}
}
if ( V_71 ) {
V_9 = F_76 ( V_38 , V_15 -> V_93 , V_107 ) ;
if ( ! V_9 ) {
F_83 ( V_8 ) ;
F_83 ( V_91 ) ;
goto V_117;
}
}
V_15 -> V_50 [ V_76 ] = V_91 ;
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
if ( V_15 -> V_16 & V_118 )
F_20 ( V_15 , V_38 ) ;
else if ( ! F_24 ( V_15 ) &&
! ( V_15 -> V_16 & V_119 ) )
F_25 ( V_15 , V_38 ) ;
}
F_23 ( V_38 ) ;
return 0 ;
V_117:
F_101 ( V_76 ) ;
return - V_108 ;
}
static int F_107 ( struct V_120 * V_121 ,
unsigned long V_122 , void * V_123 )
{
long V_76 = ( long ) V_123 ;
int V_116 = 0 ;
switch ( V_122 ) {
case V_124 :
case V_125 :
F_108 ( & V_126 ) ;
V_116 = F_105 ( V_76 ) ;
F_109 ( & V_126 ) ;
break;
case V_127 :
case V_128 :
F_51 ( V_76 ) ;
break;
#ifdef F_110
case V_129 :
case V_130 :
F_111 ( & F_46 ( V_82 , V_76 ) ) ;
F_46 ( V_82 , V_76 ) . V_83 . V_84 = NULL ;
break;
case V_131 :
case V_132 :
F_51 ( V_76 ) ;
break;
case V_133 :
case V_134 :
#endif
case V_135 :
case V_136 :
F_108 ( & V_126 ) ;
F_101 ( V_76 ) ;
F_109 ( & V_126 ) ;
break;
}
return F_112 ( V_116 ) ;
}
static int T_5 F_113 ( int V_38 )
{
struct V_14 * V_15 ;
int V_137 = 0 ;
F_64 (cachep, &slab_caches, list) {
struct V_3 * V_36 ;
V_36 = V_15 -> V_38 [ V_38 ] ;
if ( ! V_36 )
continue;
F_104 ( V_15 , V_36 , F_100 ( V_15 , V_36 ) ) ;
if ( ! F_68 ( & V_36 -> V_5 ) ||
! F_68 ( & V_36 -> V_6 ) ) {
V_137 = - V_138 ;
break;
}
}
return V_137 ;
}
static int T_5 F_114 ( struct V_120 * V_139 ,
unsigned long V_122 , void * V_140 )
{
struct V_141 * V_142 = V_140 ;
int V_137 = 0 ;
int V_143 ;
V_143 = V_142 -> V_144 ;
if ( V_143 < 0 )
goto V_97;
switch ( V_122 ) {
case V_145 :
F_108 ( & V_126 ) ;
V_137 = F_97 ( V_143 ) ;
F_109 ( & V_126 ) ;
break;
case V_146 :
F_108 ( & V_126 ) ;
V_137 = F_113 ( V_143 ) ;
F_109 ( & V_126 ) ;
break;
case V_147 :
case V_148 :
case V_149 :
case V_150 :
break;
}
V_97:
return F_112 ( V_137 ) ;
}
static void T_3 F_115 ( struct V_14 * V_15 , struct V_3 * V_151 ,
int V_105 )
{
struct V_3 * V_152 ;
V_152 = F_57 ( sizeof( struct V_3 ) , V_153 , V_105 ) ;
F_9 ( ! V_152 ) ;
memcpy ( V_152 , V_151 , sizeof( struct V_3 ) ) ;
F_6 ( & V_152 -> V_11 ) ;
F_116 ( V_15 , V_152 , V_105 ) ;
V_15 -> V_38 [ V_105 ] = V_152 ;
}
static void T_3 F_117 ( struct V_14 * V_15 , int V_154 )
{
int V_38 ;
F_22 (node) {
V_15 -> V_38 [ V_38 ] = & V_155 [ V_154 + V_38 ] ;
V_15 -> V_38 [ V_38 ] -> V_109 = V_110 +
V_111 +
( ( unsigned long ) V_15 ) % V_111 ;
}
}
static void F_118 ( struct V_14 * V_15 )
{
V_15 -> V_38 = (struct V_3 * * ) & V_15 -> V_50 [ V_156 ] ;
}
void T_3 F_119 ( void )
{
int V_43 ;
F_120 ( sizeof( ( (struct V_23 * ) NULL ) -> V_157 ) <
sizeof( struct V_158 ) ) ;
V_14 = & V_159 ;
F_118 ( V_14 ) ;
if ( F_121 () == 1 )
V_71 = 0 ;
for ( V_43 = 0 ; V_43 < V_160 ; V_43 ++ )
F_4 ( & V_155 [ V_43 ] ) ;
F_117 ( V_14 , V_161 ) ;
if ( ! V_75 && V_162 > ( 32 << 20 ) >> V_163 )
V_73 = V_164 ;
F_122 ( V_14 , L_2 ,
F_123 ( struct V_14 , V_50 [ V_156 ] ) +
V_106 * sizeof( struct V_3 * ) ,
V_165 ) ;
F_124 ( & V_14 -> V_151 , & V_166 ) ;
V_47 [ V_167 ] = F_125 ( L_3 ,
F_126 ( V_167 ) , V_168 ) ;
if ( V_167 != V_169 )
V_47 [ V_169 ] =
F_125 ( L_4 ,
F_126 ( V_169 ) , V_168 ) ;
V_170 = 0 ;
{
struct V_34 * V_152 ;
V_152 = F_127 ( sizeof( struct V_171 ) , V_153 ) ;
memcpy ( V_152 , F_29 ( V_14 ) ,
sizeof( struct V_171 ) ) ;
F_6 ( & V_152 -> V_40 ) ;
V_14 -> V_50 [ F_30 () ] = V_152 ;
V_152 = F_127 ( sizeof( struct V_171 ) , V_153 ) ;
F_9 ( F_29 ( V_47 [ V_167 ] )
!= & V_172 . V_25 ) ;
memcpy ( V_152 , F_29 ( V_47 [ V_167 ] ) ,
sizeof( struct V_171 ) ) ;
F_6 ( & V_152 -> V_40 ) ;
V_47 [ V_167 ] -> V_50 [ F_30 () ] = V_152 ;
}
{
int V_143 ;
F_22 (nid) {
F_115 ( V_14 , & V_155 [ V_161 + V_143 ] , V_143 ) ;
F_115 ( V_47 [ V_167 ] ,
& V_155 [ V_173 + V_143 ] , V_143 ) ;
if ( V_167 != V_169 ) {
F_115 ( V_47 [ V_169 ] ,
& V_155 [ V_174 + V_143 ] , V_143 ) ;
}
}
}
F_128 ( V_168 ) ;
}
void T_3 F_129 ( void )
{
struct V_14 * V_15 ;
V_44 = V_45 ;
F_108 ( & V_126 ) ;
F_64 (cachep, &slab_caches, list)
if ( F_130 ( V_15 , V_153 ) )
F_131 () ;
F_109 ( & V_126 ) ;
F_28 () ;
V_44 = V_175 ;
F_132 ( & V_176 ) ;
#ifdef F_106
F_133 ( F_114 , V_177 ) ;
#endif
}
static int T_3 F_134 ( void )
{
int V_76 ;
F_135 (cpu)
F_51 ( V_76 ) ;
V_44 = V_175 ;
return 0 ;
}
static T_6 void
F_136 ( struct V_14 * V_15 , T_4 V_178 , int V_105 )
{
struct V_3 * V_36 ;
struct V_23 * V_23 ;
unsigned long V_16 ;
int V_38 ;
F_35 ( V_179
L_5 ,
V_105 , V_178 ) ;
F_35 ( V_179 L_6 ,
V_15 -> V_67 , V_15 -> V_19 , V_15 -> V_57 ) ;
F_22 (node) {
unsigned long V_180 = 0 , V_181 = 0 , V_12 = 0 ;
unsigned long V_182 = 0 , V_183 = 0 ;
V_36 = V_15 -> V_38 [ V_38 ] ;
if ( ! V_36 )
continue;
F_63 ( & V_36 -> V_11 , V_16 ) ;
F_64 (page, &n->slabs_full, lru) {
V_180 += V_15 -> V_59 ;
V_182 ++ ;
}
F_64 (page, &n->slabs_partial, lru) {
V_180 += V_23 -> V_184 ;
V_182 ++ ;
}
F_64 (page, &n->slabs_free, lru)
V_183 ++ ;
V_12 += V_36 -> V_12 ;
F_65 ( & V_36 -> V_11 , V_16 ) ;
V_183 += V_182 ;
V_181 = V_183 * V_15 -> V_59 ;
F_35 ( V_179
L_7 ,
V_38 , V_182 , V_183 , V_180 , V_181 ,
V_12 ) ;
}
}
static struct V_23 * F_137 ( struct V_14 * V_15 , T_4 V_16 ,
int V_105 )
{
struct V_23 * V_23 ;
int V_185 ;
V_16 |= V_15 -> V_186 ;
if ( V_15 -> V_16 & V_187 )
V_16 |= V_188 ;
V_23 = F_138 ( V_105 , V_16 | V_189 , V_15 -> V_57 ) ;
if ( ! V_23 ) {
if ( ! ( V_16 & V_190 ) && F_139 () )
F_136 ( V_15 , V_16 , V_105 ) ;
return NULL ;
}
if ( F_49 ( V_23 -> V_191 ) )
V_96 = true ;
V_185 = ( 1 << V_15 -> V_57 ) ;
if ( V_15 -> V_16 & V_187 )
F_140 ( F_141 ( V_23 ) ,
V_192 , V_185 ) ;
else
F_140 ( F_141 ( V_23 ) ,
V_193 , V_185 ) ;
F_142 ( V_23 ) ;
if ( V_23 -> V_191 )
F_143 ( V_23 ) ;
F_144 ( V_15 , V_15 -> V_57 ) ;
if ( V_194 && ! ( V_15 -> V_16 & V_195 ) ) {
F_145 ( V_23 , V_15 -> V_57 , V_16 , V_105 ) ;
if ( V_15 -> V_196 )
F_146 ( V_23 , V_185 ) ;
else
F_147 ( V_23 , V_185 ) ;
}
return V_23 ;
}
static void F_148 ( struct V_14 * V_15 , struct V_23 * V_23 )
{
const unsigned long V_197 = ( 1 << V_15 -> V_57 ) ;
F_149 ( V_23 , V_15 -> V_57 ) ;
if ( V_15 -> V_16 & V_187 )
F_150 ( F_141 ( V_23 ) ,
V_192 , V_197 ) ;
else
F_150 ( F_141 ( V_23 ) ,
V_193 , V_197 ) ;
F_9 ( ! F_151 ( V_23 ) ) ;
F_152 ( V_23 ) ;
F_153 ( V_23 ) ;
F_154 ( V_23 ) ;
V_23 -> V_198 = NULL ;
F_155 ( V_15 , V_15 -> V_57 ) ;
if ( V_199 -> V_200 )
V_199 -> V_200 -> V_201 += V_197 ;
F_156 ( V_23 , V_15 -> V_57 ) ;
}
static void F_157 ( struct V_158 * V_202 )
{
struct V_14 * V_15 ;
struct V_23 * V_23 ;
V_23 = F_158 ( V_202 , struct V_23 , V_158 ) ;
V_15 = V_23 -> V_24 ;
F_148 ( V_15 , V_23 ) ;
}
static void F_159 ( struct V_14 * V_15 , unsigned long * V_203 ,
unsigned long V_204 )
{
int V_19 = V_15 -> V_205 ;
V_203 = ( unsigned long * ) & ( ( char * ) V_203 ) [ F_7 ( V_15 ) ] ;
if ( V_19 < 5 * sizeof( unsigned long ) )
return;
* V_203 ++ = 0x12345678 ;
* V_203 ++ = V_204 ;
* V_203 ++ = F_30 () ;
V_19 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_206 = & V_204 ;
unsigned long V_207 ;
while ( ! F_160 ( V_206 ) ) {
V_207 = * V_206 ++ ;
if ( F_161 ( V_207 ) ) {
* V_203 ++ = V_207 ;
V_19 -= sizeof( unsigned long ) ;
if ( V_19 <= sizeof( unsigned long ) )
break;
}
}
}
* V_203 ++ = 0x87654321 ;
}
static void F_162 ( struct V_14 * V_15 , void * V_203 , unsigned char V_208 )
{
int V_19 = V_15 -> V_205 ;
V_203 = & ( ( char * ) V_203 ) [ F_7 ( V_15 ) ] ;
memset ( V_203 , V_208 , V_19 ) ;
* ( unsigned char * ) ( V_203 + V_19 - 1 ) = V_209 ;
}
static void F_163 ( char * V_210 , int V_28 , int V_93 )
{
int V_43 ;
unsigned char error = 0 ;
int V_211 = 0 ;
F_35 ( V_66 L_8 , V_28 ) ;
for ( V_43 = 0 ; V_43 < V_93 ; V_43 ++ ) {
if ( V_210 [ V_28 + V_43 ] != V_212 ) {
error = V_210 [ V_28 + V_43 ] ;
V_211 ++ ;
}
}
F_164 ( V_213 , L_9 , 0 , 16 , 1 ,
& V_210 [ V_28 ] , V_93 , 1 ) ;
if ( V_211 == 1 ) {
error ^= V_212 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_35 ( V_66 L_10
L_11 ) ;
#ifdef F_165
F_35 ( V_66 L_12
L_13 ) ;
#else
F_35 ( V_66 L_14 ) ;
#endif
}
}
}
static void F_166 ( struct V_14 * V_15 , void * V_1 , int V_214 )
{
int V_43 , V_19 ;
char * V_215 ;
if ( V_15 -> V_16 & V_17 ) {
F_35 ( V_66 L_15 ,
* F_8 ( V_15 , V_1 ) ,
* F_10 ( V_15 , V_1 ) ) ;
}
if ( V_15 -> V_16 & V_18 ) {
F_35 ( V_66 L_16 ,
* F_11 ( V_15 , V_1 ) ,
* F_11 ( V_15 , V_1 ) ) ;
}
V_215 = ( char * ) V_1 + F_7 ( V_15 ) ;
V_19 = V_15 -> V_205 ;
for ( V_43 = 0 ; V_43 < V_19 && V_214 ; V_43 += 16 , V_214 -- ) {
int V_93 ;
V_93 = 16 ;
if ( V_43 + V_93 > V_19 )
V_93 = V_19 - V_43 ;
F_163 ( V_215 , V_43 , V_93 ) ;
}
}
static void F_167 ( struct V_14 * V_15 , void * V_1 )
{
char * V_215 ;
int V_19 , V_43 ;
int V_214 = 0 ;
V_215 = ( char * ) V_1 + F_7 ( V_15 ) ;
V_19 = V_15 -> V_205 ;
for ( V_43 = 0 ; V_43 < V_19 ; V_43 ++ ) {
char exp = V_212 ;
if ( V_43 == V_19 - 1 )
exp = V_209 ;
if ( V_215 [ V_43 ] != exp ) {
int V_93 ;
if ( V_214 == 0 ) {
F_35 ( V_66
L_17 ,
F_168 () , V_15 -> V_67 , V_215 , V_19 ) ;
F_166 ( V_15 , V_1 , 0 ) ;
}
V_43 = ( V_43 / 16 ) * 16 ;
V_93 = 16 ;
if ( V_43 + V_93 > V_19 )
V_93 = V_19 - V_43 ;
F_163 ( V_215 , V_43 , V_93 ) ;
V_43 += 16 ;
V_214 ++ ;
if ( V_214 > 5 )
break;
}
}
if ( V_214 != 0 ) {
struct V_23 * V_23 = F_13 ( V_1 ) ;
unsigned int V_216 ;
V_216 = F_15 ( V_15 , V_23 , V_1 ) ;
if ( V_216 ) {
V_1 = F_14 ( V_15 , V_23 , V_216 - 1 ) ;
V_215 = ( char * ) V_1 + F_7 ( V_15 ) ;
F_35 ( V_66 L_18 ,
V_215 , V_19 ) ;
F_166 ( V_15 , V_1 , 2 ) ;
}
if ( V_216 + 1 < V_15 -> V_59 ) {
V_1 = F_14 ( V_15 , V_23 , V_216 + 1 ) ;
V_215 = ( char * ) V_1 + F_7 ( V_15 ) ;
F_35 ( V_66 L_19 ,
V_215 , V_19 ) ;
F_166 ( V_15 , V_1 , 2 ) ;
}
}
}
static void F_169 ( struct V_14 * V_15 ,
struct V_23 * V_23 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_15 -> V_59 ; V_43 ++ ) {
void * V_1 = F_14 ( V_15 , V_23 , V_43 ) ;
if ( V_15 -> V_16 & V_217 ) {
#ifdef F_170
if ( V_15 -> V_19 % V_61 == 0 &&
F_24 ( V_15 ) )
F_171 ( F_93 ( V_1 ) ,
V_15 -> V_19 / V_61 , 1 ) ;
else
F_167 ( V_15 , V_1 ) ;
#else
F_167 ( V_15 , V_1 ) ;
#endif
}
if ( V_15 -> V_16 & V_17 ) {
if ( * F_8 ( V_15 , V_1 ) != V_218 )
F_172 ( V_15 , L_20
L_21 ) ;
if ( * F_10 ( V_15 , V_1 ) != V_218 )
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
void * V_219 ;
V_219 = V_23 -> V_219 ;
F_169 ( V_15 , V_23 ) ;
if ( F_49 ( V_15 -> V_16 & V_119 ) ) {
struct V_158 * V_202 ;
V_202 = ( void * ) & V_23 -> V_158 ;
F_174 ( V_202 , F_157 ) ;
} else {
F_148 ( V_15 , V_23 ) ;
}
if ( F_24 ( V_15 ) )
F_175 ( V_15 -> V_220 , V_219 ) ;
}
static T_2 F_176 ( struct V_14 * V_15 ,
T_2 V_19 , T_2 V_54 , unsigned long V_16 )
{
unsigned long V_221 ;
T_2 V_58 = 0 ;
int V_57 ;
for ( V_57 = 0 ; V_57 <= V_222 ; V_57 ++ ) {
unsigned int V_59 ;
T_2 V_223 ;
F_33 ( V_57 , V_19 , V_54 , V_16 , & V_223 , & V_59 ) ;
if ( ! V_59 )
continue;
if ( V_59 > V_224 )
break;
if ( V_16 & V_62 ) {
V_221 = V_19 ;
V_221 /= sizeof( V_63 ) ;
if ( V_59 > V_221 )
break;
}
V_15 -> V_59 = V_59 ;
V_15 -> V_57 = V_57 ;
V_58 = V_223 ;
if ( V_16 & V_187 )
break;
if ( V_57 >= V_73 )
break;
if ( V_58 * 8 <= ( V_61 << V_57 ) )
break;
}
return V_58 ;
}
static int T_7 F_177 ( struct V_14 * V_15 , T_4 V_89 )
{
if ( V_44 >= V_175 )
return F_130 ( V_15 , V_89 ) ;
if ( V_44 == V_225 ) {
V_15 -> V_50 [ F_30 () ] = & V_172 . V_25 ;
V_44 = V_226 ;
} else if ( V_44 == V_226 ) {
V_15 -> V_50 [ F_30 () ] = & V_172 . V_25 ;
F_117 ( V_15 , V_173 ) ;
if ( V_167 == V_169 )
V_44 = V_227 ;
else
V_44 = V_228 ;
} else {
V_15 -> V_50 [ F_30 () ] =
F_127 ( sizeof( struct V_171 ) , V_89 ) ;
if ( V_44 == V_228 ) {
F_117 ( V_15 , V_174 ) ;
V_44 = V_227 ;
} else {
int V_38 ;
F_22 (node) {
V_15 -> V_38 [ V_38 ] =
F_57 ( sizeof( struct V_3 ) ,
V_89 , V_38 ) ;
F_9 ( ! V_15 -> V_38 [ V_38 ] ) ;
F_4 ( V_15 -> V_38 [ V_38 ] ) ;
}
}
}
V_15 -> V_38 [ F_62 () ] -> V_109 =
V_110 + V_111 +
( ( unsigned long ) V_15 ) % V_111 ;
F_29 ( V_15 ) -> V_92 = 0 ;
F_29 ( V_15 ) -> V_93 = V_229 ;
F_29 ( V_15 ) -> V_88 = 1 ;
F_29 ( V_15 ) -> V_94 = 0 ;
V_15 -> V_88 = 1 ;
V_15 -> V_93 = V_229 ;
return 0 ;
}
int
F_178 ( struct V_14 * V_15 , unsigned long V_16 )
{
T_2 V_58 , V_56 , V_230 ;
T_4 V_89 ;
int V_116 ;
T_2 V_19 = V_15 -> V_19 ;
#if V_231
#if V_232
if ( V_19 < 4096 || F_179 ( V_19 - 1 ) == F_179 ( V_19 - 1 + V_20 +
2 * sizeof( unsigned long long ) ) )
V_16 |= V_17 | V_18 ;
if ( ! ( V_16 & V_119 ) )
V_16 |= V_217 ;
#endif
if ( V_16 & V_119 )
F_9 ( V_16 & V_217 ) ;
#endif
if ( V_19 & ( V_21 - 1 ) ) {
V_19 += ( V_21 - 1 ) ;
V_19 &= ~ ( V_21 - 1 ) ;
}
if ( V_16 & V_18 )
V_230 = V_21 ;
if ( V_16 & V_17 ) {
V_230 = V_20 ;
V_19 += V_20 - 1 ;
V_19 &= ~ ( V_20 - 1 ) ;
}
if ( V_230 < V_15 -> V_54 ) {
V_230 = V_15 -> V_54 ;
}
if ( V_230 > F_180 (unsigned long long) )
V_16 &= ~ ( V_17 | V_18 ) ;
V_15 -> V_54 = V_230 ;
if ( F_181 () )
V_89 = V_107 ;
else
V_89 = V_153 ;
F_118 ( V_15 ) ;
#if V_231
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
#if V_232 && F_182 ( F_170 )
if ( V_19 >= F_126 ( V_169 + 1 )
&& V_15 -> V_205 > F_183 ()
&& F_32 ( V_19 , V_15 -> V_54 ) < V_61 ) {
V_15 -> F_7 += V_61 - F_32 ( V_19 , V_15 -> V_54 ) ;
V_19 = V_61 ;
}
#endif
#endif
if ( ( V_19 >= ( V_61 >> 5 ) ) && ! V_170 &&
! ( V_16 & V_233 ) )
V_16 |= V_62 ;
V_19 = F_32 ( V_19 , V_15 -> V_54 ) ;
if ( V_234 && V_19 < V_235 )
V_19 = F_32 ( V_235 , V_15 -> V_54 ) ;
V_58 = F_176 ( V_15 , V_19 , V_15 -> V_54 , V_16 ) ;
if ( ! V_15 -> V_59 )
return - V_236 ;
V_56 =
F_32 ( V_15 -> V_59 * sizeof( V_63 ) , V_15 -> V_54 ) ;
if ( V_16 & V_62 && V_58 >= V_56 ) {
V_16 &= ~ V_62 ;
V_58 -= V_56 ;
}
if ( V_16 & V_62 ) {
V_56 = V_15 -> V_59 * sizeof( V_63 ) ;
#ifdef F_184
if ( V_19 % V_61 == 0 && V_16 & V_217 )
V_16 &= ~ ( V_17 | V_18 ) ;
#endif
}
V_15 -> V_237 = F_183 () ;
if ( V_15 -> V_237 < V_15 -> V_54 )
V_15 -> V_237 = V_15 -> V_54 ;
V_15 -> V_238 = V_58 / V_15 -> V_237 ;
V_15 -> V_56 = V_56 ;
V_15 -> V_16 = V_16 ;
V_15 -> V_186 = V_239 ;
if ( V_240 && ( V_16 & V_241 ) )
V_15 -> V_186 |= V_242 ;
V_15 -> V_19 = V_19 ;
V_15 -> V_29 = F_185 ( V_19 ) ;
if ( V_16 & V_62 ) {
V_15 -> V_220 = F_186 ( V_56 , 0u ) ;
F_9 ( F_187 ( V_15 -> V_220 ) ) ;
}
V_116 = F_177 ( V_15 , V_89 ) ;
if ( V_116 ) {
F_188 ( V_15 ) ;
return V_116 ;
}
if ( V_16 & V_118 ) {
F_189 ( V_16 & V_119 ) ;
F_21 ( V_15 ) ;
} else if ( ! F_24 ( V_15 ) && ! ( V_16 & V_119 ) )
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
static void F_197 ( void * V_140 )
{
struct V_14 * V_15 = V_140 ;
struct V_34 * V_95 ;
int V_38 = F_62 () ;
F_190 () ;
V_95 = F_29 ( V_15 ) ;
F_85 ( & V_15 -> V_38 [ V_38 ] -> V_11 ) ;
F_86 ( V_15 , V_95 -> V_99 , V_95 -> V_92 , V_38 ) ;
F_87 ( & V_15 -> V_38 [ V_38 ] -> V_11 ) ;
V_95 -> V_92 = 0 ;
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
struct V_3 * V_36 , int V_243 )
{
struct V_244 * V_245 ;
int V_197 ;
struct V_23 * V_23 ;
V_197 = 0 ;
while ( V_197 < V_243 && ! F_68 ( & V_36 -> V_7 ) ) {
F_98 ( & V_36 -> V_11 ) ;
V_245 = V_36 -> V_7 . V_246 ;
if ( V_245 == & V_36 -> V_7 ) {
F_90 ( & V_36 -> V_11 ) ;
goto V_97;
}
V_23 = F_201 ( V_245 , struct V_23 , V_157 ) ;
#if V_231
F_9 ( V_23 -> V_184 ) ;
#endif
F_202 ( & V_23 -> V_157 ) ;
V_36 -> V_12 -= V_25 -> V_59 ;
F_90 ( & V_36 -> V_11 ) ;
F_173 ( V_25 , V_23 ) ;
V_197 ++ ;
}
V_97:
return V_197 ;
}
static int F_203 ( struct V_14 * V_15 )
{
int V_137 = 0 , V_43 = 0 ;
struct V_3 * V_36 ;
F_198 ( V_15 ) ;
F_192 () ;
F_22 (i) {
V_36 = V_15 -> V_38 [ V_43 ] ;
if ( ! V_36 )
continue;
F_104 ( V_15 , V_36 , F_100 ( V_15 , V_36 ) ) ;
V_137 += ! F_68 ( & V_36 -> V_5 ) ||
! F_68 ( & V_36 -> V_6 ) ;
}
return ( V_137 ? 1 : 0 ) ;
}
int F_204 ( struct V_14 * V_15 )
{
int V_137 ;
F_9 ( ! V_15 || F_205 () ) ;
F_206 () ;
F_108 ( & V_126 ) ;
V_137 = F_203 ( V_15 ) ;
F_109 ( & V_126 ) ;
F_207 () ;
return V_137 ;
}
int F_188 ( struct V_14 * V_15 )
{
int V_43 ;
struct V_3 * V_36 ;
int V_247 = F_203 ( V_15 ) ;
if ( V_247 )
return V_247 ;
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
struct V_23 * V_23 , int V_237 ,
T_4 V_248 , int V_105 )
{
void * V_219 ;
void * V_203 = F_209 ( V_23 ) ;
if ( F_24 ( V_15 ) ) {
V_219 = F_210 ( V_15 -> V_220 ,
V_248 , V_105 ) ;
if ( ! V_219 )
return NULL ;
} else {
V_219 = V_203 + V_237 ;
V_237 += V_15 -> V_56 ;
}
V_23 -> V_184 = 0 ;
V_23 -> V_27 = V_203 + V_237 ;
return V_219 ;
}
static inline V_63 F_211 ( struct V_23 * V_23 , unsigned int V_26 )
{
return ( ( V_63 * ) V_23 -> V_219 ) [ V_26 ] ;
}
static inline void F_212 ( struct V_23 * V_23 ,
unsigned int V_26 , V_63 V_208 )
{
( ( V_63 * ) ( V_23 -> V_219 ) ) [ V_26 ] = V_208 ;
}
static void F_213 ( struct V_14 * V_15 ,
struct V_23 * V_23 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_15 -> V_59 ; V_43 ++ ) {
void * V_1 = F_14 ( V_15 , V_23 , V_43 ) ;
#if V_231
if ( V_15 -> V_16 & V_217 )
F_162 ( V_15 , V_1 , V_212 ) ;
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = NULL ;
if ( V_15 -> V_16 & V_17 ) {
* F_8 ( V_15 , V_1 ) = V_218 ;
* F_10 ( V_15 , V_1 ) = V_218 ;
}
if ( V_15 -> V_196 && ! ( V_15 -> V_16 & V_217 ) )
V_15 -> V_196 ( V_1 + F_7 ( V_15 ) ) ;
if ( V_15 -> V_16 & V_17 ) {
if ( * F_10 ( V_15 , V_1 ) != V_218 )
F_172 ( V_15 , L_23
L_24 ) ;
if ( * F_8 ( V_15 , V_1 ) != V_218 )
F_172 ( V_15 , L_23
L_25 ) ;
}
if ( ( V_15 -> V_19 % V_61 ) == 0 &&
F_24 ( V_15 ) && V_15 -> V_16 & V_217 )
F_171 ( F_93 ( V_1 ) ,
V_15 -> V_19 / V_61 , 0 ) ;
#else
if ( V_15 -> V_196 )
V_15 -> V_196 ( V_1 ) ;
#endif
F_212 ( V_23 , V_43 , V_43 ) ;
}
}
static void F_214 ( struct V_14 * V_15 , T_4 V_16 )
{
if ( V_240 ) {
if ( V_16 & V_242 )
F_9 ( ! ( V_15 -> V_186 & V_242 ) ) ;
else
F_9 ( V_15 -> V_186 & V_242 ) ;
}
}
static void * F_215 ( struct V_14 * V_15 , struct V_23 * V_23 ,
int V_105 )
{
void * V_1 ;
V_1 = F_14 ( V_15 , V_23 , F_211 ( V_23 , V_23 -> V_184 ) ) ;
V_23 -> V_184 ++ ;
#if V_231
F_216 ( F_92 ( F_93 ( V_1 ) ) != V_105 ) ;
#endif
return V_1 ;
}
static void F_217 ( struct V_14 * V_15 , struct V_23 * V_23 ,
void * V_1 , int V_105 )
{
unsigned int V_216 = F_15 ( V_15 , V_23 , V_1 ) ;
#if V_231
unsigned int V_43 ;
F_216 ( F_92 ( F_93 ( V_1 ) ) != V_105 ) ;
for ( V_43 = V_23 -> V_184 ; V_43 < V_15 -> V_59 ; V_43 ++ ) {
if ( F_211 ( V_23 , V_43 ) == V_216 ) {
F_35 ( V_66 L_26
L_27 , V_15 -> V_67 , V_1 ) ;
F_131 () ;
}
}
#endif
V_23 -> V_184 -- ;
F_212 ( V_23 , V_23 -> V_184 , V_216 ) ;
}
static void F_218 ( struct V_14 * V_25 , struct V_23 * V_23 ,
void * V_219 )
{
V_23 -> V_24 = V_25 ;
V_23 -> V_219 = V_219 ;
}
static int F_219 ( struct V_14 * V_15 ,
T_4 V_16 , int V_105 , struct V_23 * V_23 )
{
void * V_219 ;
T_2 V_28 ;
T_4 V_248 ;
struct V_3 * V_36 ;
F_9 ( V_16 & V_249 ) ;
V_248 = V_16 & ( V_250 | V_251 ) ;
F_190 () ;
V_36 = V_15 -> V_38 [ V_105 ] ;
F_85 ( & V_36 -> V_11 ) ;
V_28 = V_36 -> V_10 ;
V_36 -> V_10 ++ ;
if ( V_36 -> V_10 >= V_15 -> V_238 )
V_36 -> V_10 = 0 ;
F_87 ( & V_36 -> V_11 ) ;
V_28 *= V_15 -> V_237 ;
if ( V_248 & V_252 )
F_220 () ;
F_214 ( V_15 , V_16 ) ;
if ( ! V_23 )
V_23 = F_137 ( V_15 , V_248 , V_105 ) ;
if ( ! V_23 )
goto V_253;
V_219 = F_208 ( V_15 , V_23 , V_28 ,
V_248 & ~ V_250 , V_105 ) ;
if ( ! V_219 )
goto V_254;
F_218 ( V_15 , V_23 , V_219 ) ;
F_213 ( V_15 , V_23 ) ;
if ( V_248 & V_252 )
F_221 () ;
F_190 () ;
F_85 ( & V_36 -> V_11 ) ;
F_222 ( & V_23 -> V_157 , & ( V_36 -> V_7 ) ) ;
F_223 ( V_15 ) ;
V_36 -> V_12 += V_15 -> V_59 ;
F_87 ( & V_36 -> V_11 ) ;
return 1 ;
V_254:
F_148 ( V_15 , V_23 ) ;
V_253:
if ( V_248 & V_252 )
F_221 () ;
return 0 ;
}
static void F_224 ( const void * V_1 )
{
if ( ! F_225 ( V_1 ) ) {
F_35 ( V_66 L_28 ,
( unsigned long ) V_1 ) ;
F_131 () ;
}
}
static inline void F_226 ( struct V_14 * V_25 , void * V_22 )
{
unsigned long long V_255 , V_256 ;
V_255 = * F_8 ( V_25 , V_22 ) ;
V_256 = * F_10 ( V_25 , V_22 ) ;
if ( V_255 == V_257 && V_256 == V_257 )
return;
if ( V_255 == V_218 && V_256 == V_218 )
F_172 ( V_25 , L_29 ) ;
else
F_172 ( V_25 , L_30 ) ;
F_35 ( V_66 L_31 ,
V_22 , V_255 , V_256 ) ;
}
static void * F_227 ( struct V_14 * V_15 , void * V_1 ,
unsigned long V_204 )
{
unsigned int V_216 ;
struct V_23 * V_23 ;
F_9 ( F_12 ( V_1 ) != V_15 ) ;
V_1 -= F_7 ( V_15 ) ;
F_224 ( V_1 ) ;
V_23 = F_13 ( V_1 ) ;
if ( V_15 -> V_16 & V_17 ) {
F_226 ( V_15 , V_1 ) ;
* F_8 ( V_15 , V_1 ) = V_218 ;
* F_10 ( V_15 , V_1 ) = V_218 ;
}
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = ( void * ) V_204 ;
V_216 = F_15 ( V_15 , V_23 , V_1 ) ;
F_9 ( V_216 >= V_15 -> V_59 ) ;
F_9 ( V_1 != F_14 ( V_15 , V_23 , V_216 ) ) ;
if ( V_15 -> V_16 & V_217 ) {
#ifdef F_170
if ( ( V_15 -> V_19 % V_61 ) == 0 && F_24 ( V_15 ) ) {
F_159 ( V_15 , V_1 , V_204 ) ;
F_171 ( F_93 ( V_1 ) ,
V_15 -> V_19 / V_61 , 0 ) ;
} else {
F_162 ( V_15 , V_1 , V_212 ) ;
}
#else
F_162 ( V_15 , V_1 , V_212 ) ;
#endif
}
return V_1 ;
}
static void * F_228 ( struct V_14 * V_15 , T_4 V_16 ,
bool V_98 )
{
int V_88 ;
struct V_3 * V_36 ;
struct V_34 * V_95 ;
int V_38 ;
F_190 () ;
V_38 = F_62 () ;
if ( F_49 ( V_98 ) )
goto V_258;
V_259:
V_95 = F_29 ( V_15 ) ;
V_88 = V_95 -> V_88 ;
if ( ! V_95 -> V_94 && V_88 > V_260 ) {
V_88 = V_260 ;
}
V_36 = V_15 -> V_38 [ V_38 ] ;
F_9 ( V_95 -> V_92 > 0 || ! V_36 ) ;
F_85 ( & V_36 -> V_11 ) ;
if ( V_36 -> V_8 && F_74 ( V_95 , V_36 -> V_8 , V_88 ) ) {
V_36 -> V_8 -> V_94 = 1 ;
goto V_261;
}
while ( V_88 > 0 ) {
struct V_244 * V_99 ;
struct V_23 * V_23 ;
V_99 = V_36 -> V_6 . V_262 ;
if ( V_99 == & V_36 -> V_6 ) {
V_36 -> V_13 = 1 ;
V_99 = V_36 -> V_7 . V_262 ;
if ( V_99 == & V_36 -> V_7 )
goto V_263;
}
V_23 = F_201 ( V_99 , struct V_23 , V_157 ) ;
F_193 ( V_15 ) ;
F_9 ( V_23 -> V_184 >= V_15 -> V_59 ) ;
while ( V_23 -> V_184 < V_15 -> V_59 && V_88 -- ) {
F_229 ( V_15 ) ;
F_230 ( V_15 ) ;
F_231 ( V_15 ) ;
F_73 ( V_15 , V_95 , F_215 ( V_15 , V_23 ,
V_38 ) ) ;
}
F_202 ( & V_23 -> V_157 ) ;
if ( V_23 -> V_184 == V_15 -> V_59 )
F_124 ( & V_23 -> V_157 , & V_36 -> V_5 ) ;
else
F_124 ( & V_23 -> V_157 , & V_36 -> V_6 ) ;
}
V_263:
V_36 -> V_12 -= V_95 -> V_92 ;
V_261:
F_87 ( & V_36 -> V_11 ) ;
if ( F_49 ( ! V_95 -> V_92 ) ) {
int V_264 ;
V_258:
V_264 = F_219 ( V_15 , V_16 | V_265 , V_38 , NULL ) ;
V_95 = F_29 ( V_15 ) ;
V_38 = F_62 () ;
if ( ! V_264 && ( V_95 -> V_92 == 0 || V_98 ) )
return NULL ;
if ( ! V_95 -> V_92 )
goto V_259;
}
V_95 -> V_94 = 1 ;
return F_70 ( V_15 , V_95 , V_16 , V_98 ) ;
}
static inline void F_232 ( struct V_14 * V_15 ,
T_4 V_16 )
{
F_233 ( V_16 & V_252 ) ;
#if V_231
F_214 ( V_15 , V_16 ) ;
#endif
}
static void * F_234 ( struct V_14 * V_15 ,
T_4 V_16 , void * V_1 , unsigned long V_204 )
{
if ( ! V_1 )
return V_1 ;
if ( V_15 -> V_16 & V_217 ) {
#ifdef F_170
if ( ( V_15 -> V_19 % V_61 ) == 0 && F_24 ( V_15 ) )
F_171 ( F_93 ( V_1 ) ,
V_15 -> V_19 / V_61 , 1 ) ;
else
F_167 ( V_15 , V_1 ) ;
#else
F_167 ( V_15 , V_1 ) ;
#endif
F_162 ( V_15 , V_1 , V_266 ) ;
}
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = ( void * ) V_204 ;
if ( V_15 -> V_16 & V_17 ) {
if ( * F_8 ( V_15 , V_1 ) != V_218 ||
* F_10 ( V_15 , V_1 ) != V_218 ) {
F_172 ( V_15 , L_32
L_33 ) ;
F_35 ( V_66
L_34 ,
V_1 , * F_8 ( V_15 , V_1 ) ,
* F_10 ( V_15 , V_1 ) ) ;
}
* F_8 ( V_15 , V_1 ) = V_257 ;
* F_10 ( V_15 , V_1 ) = V_257 ;
}
V_1 += F_7 ( V_15 ) ;
if ( V_15 -> V_196 && V_15 -> V_16 & V_217 )
V_15 -> V_196 ( V_1 ) ;
if ( V_267 &&
( ( unsigned long ) V_1 & ( V_267 - 1 ) ) ) {
F_35 ( V_66 L_35 ,
V_1 , ( int ) V_267 ) ;
}
return V_1 ;
}
static bool F_235 ( struct V_14 * V_15 , T_4 V_16 )
{
if ( V_15 == V_14 )
return false ;
return F_236 ( V_15 -> V_205 , V_16 , V_15 -> V_16 ) ;
}
static inline void * F_237 ( struct V_14 * V_15 , T_4 V_16 )
{
void * V_1 ;
struct V_34 * V_95 ;
bool V_98 = false ;
F_190 () ;
V_95 = F_29 ( V_15 ) ;
if ( F_94 ( V_95 -> V_92 ) ) {
V_95 -> V_94 = 1 ;
V_1 = F_70 ( V_15 , V_95 , V_16 , false ) ;
if ( V_1 ) {
F_238 ( V_15 ) ;
goto V_97;
}
V_98 = true ;
}
F_239 ( V_15 ) ;
V_1 = F_228 ( V_15 , V_16 , V_98 ) ;
V_95 = F_29 ( V_15 ) ;
V_97:
if ( V_1 )
F_240 ( & V_95 -> V_99 [ V_95 -> V_92 ] ) ;
return V_1 ;
}
static void * F_79 ( struct V_14 * V_15 , T_4 V_16 )
{
int V_268 , V_269 ;
if ( F_205 () || ( V_16 & V_270 ) )
return NULL ;
V_268 = V_269 = F_62 () ;
if ( F_241 () && ( V_15 -> V_16 & V_271 ) )
V_268 = F_242 () ;
else if ( V_199 -> V_272 )
V_268 = F_243 () ;
if ( V_268 != V_269 )
return F_80 ( V_15 , V_16 , V_268 ) ;
return NULL ;
}
static void * F_244 ( struct V_14 * V_25 , T_4 V_16 )
{
struct V_273 * V_273 ;
T_4 V_248 ;
struct V_274 * V_275 ;
struct V_276 * V_276 ;
enum V_277 V_278 = F_245 ( V_16 ) ;
void * V_22 = NULL ;
int V_143 ;
unsigned int V_279 ;
if ( V_16 & V_270 )
return NULL ;
V_248 = V_16 & ( V_250 | V_251 ) ;
V_280:
V_279 = F_246 () ;
V_273 = F_247 ( F_243 () , V_16 ) ;
V_259:
F_248 (zone, z, zonelist, high_zoneidx) {
V_143 = F_249 ( V_276 ) ;
if ( F_250 ( V_276 , V_16 ) &&
V_25 -> V_38 [ V_143 ] &&
V_25 -> V_38 [ V_143 ] -> V_12 ) {
V_22 = F_80 ( V_25 ,
V_16 | V_265 , V_143 ) ;
if ( V_22 )
break;
}
}
if ( ! V_22 ) {
struct V_23 * V_23 ;
if ( V_248 & V_252 )
F_220 () ;
F_214 ( V_25 , V_16 ) ;
V_23 = F_137 ( V_25 , V_248 , F_62 () ) ;
if ( V_248 & V_252 )
F_221 () ;
if ( V_23 ) {
V_143 = F_92 ( V_23 ) ;
if ( F_219 ( V_25 , V_16 , V_143 , V_23 ) ) {
V_22 = F_80 ( V_25 ,
V_16 | V_265 , V_143 ) ;
if ( ! V_22 )
goto V_259;
} else {
V_22 = NULL ;
}
}
}
if ( F_49 ( ! V_22 && F_251 ( V_279 ) ) )
goto V_280;
return V_22 ;
}
static void * F_80 ( struct V_14 * V_15 , T_4 V_16 ,
int V_105 )
{
struct V_244 * V_99 ;
struct V_23 * V_23 ;
struct V_3 * V_36 ;
void * V_22 ;
int V_264 ;
F_27 ( V_105 > F_252 () ) ;
V_36 = V_15 -> V_38 [ V_105 ] ;
F_9 ( ! V_36 ) ;
V_259:
F_190 () ;
F_85 ( & V_36 -> V_11 ) ;
V_99 = V_36 -> V_6 . V_262 ;
if ( V_99 == & V_36 -> V_6 ) {
V_36 -> V_13 = 1 ;
V_99 = V_36 -> V_7 . V_262 ;
if ( V_99 == & V_36 -> V_7 )
goto V_263;
}
V_23 = F_201 ( V_99 , struct V_23 , V_157 ) ;
F_196 ( V_15 , V_105 ) ;
F_253 ( V_15 ) ;
F_230 ( V_15 ) ;
F_231 ( V_15 ) ;
F_9 ( V_23 -> V_184 == V_15 -> V_59 ) ;
V_22 = F_215 ( V_15 , V_23 , V_105 ) ;
V_36 -> V_12 -- ;
F_202 ( & V_23 -> V_157 ) ;
if ( V_23 -> V_184 == V_15 -> V_59 )
F_124 ( & V_23 -> V_157 , & V_36 -> V_5 ) ;
else
F_124 ( & V_23 -> V_157 , & V_36 -> V_6 ) ;
F_87 ( & V_36 -> V_11 ) ;
goto V_281;
V_263:
F_87 ( & V_36 -> V_11 ) ;
V_264 = F_219 ( V_15 , V_16 | V_265 , V_105 , NULL ) ;
if ( V_264 )
goto V_259;
return F_244 ( V_15 , V_16 ) ;
V_281:
return V_22 ;
}
static T_8 void *
F_254 ( struct V_14 * V_15 , T_4 V_16 , int V_105 ,
unsigned long V_204 )
{
unsigned long V_282 ;
void * V_152 ;
int V_283 = F_62 () ;
V_16 &= V_284 ;
F_255 ( V_16 ) ;
if ( F_235 ( V_15 , V_16 ) )
return NULL ;
V_15 = F_256 ( V_15 , V_16 ) ;
F_232 ( V_15 , V_16 ) ;
F_257 ( V_282 ) ;
if ( V_105 == V_285 )
V_105 = V_283 ;
if ( F_49 ( ! V_15 -> V_38 [ V_105 ] ) ) {
V_152 = F_244 ( V_15 , V_16 ) ;
goto V_97;
}
if ( V_105 == V_283 ) {
V_152 = F_237 ( V_15 , V_16 ) ;
if ( V_152 )
goto V_97;
}
V_152 = F_80 ( V_15 , V_16 , V_105 ) ;
V_97:
F_258 ( V_282 ) ;
V_152 = F_234 ( V_15 , V_16 , V_152 , V_204 ) ;
F_259 ( V_152 , V_15 -> V_205 , 1 , V_15 -> V_16 ,
V_16 ) ;
if ( F_94 ( V_152 ) ) {
F_260 ( V_15 , V_16 , V_152 , V_15 -> V_205 ) ;
if ( F_49 ( V_16 & V_286 ) )
memset ( V_152 , 0 , V_15 -> V_205 ) ;
}
return V_152 ;
}
static T_8 void *
F_261 ( struct V_14 * V_25 , T_4 V_16 )
{
void * V_1 ;
if ( V_199 -> V_272 || F_49 ( V_199 -> V_16 & V_287 ) ) {
V_1 = F_79 ( V_25 , V_16 ) ;
if ( V_1 )
goto V_97;
}
V_1 = F_237 ( V_25 , V_16 ) ;
if ( ! V_1 )
V_1 = F_80 ( V_25 , V_16 , F_62 () ) ;
V_97:
return V_1 ;
}
static T_8 void *
F_261 ( struct V_14 * V_15 , T_4 V_16 )
{
return F_237 ( V_15 , V_16 ) ;
}
static T_8 void *
F_262 ( struct V_14 * V_15 , T_4 V_16 , unsigned long V_204 )
{
unsigned long V_282 ;
void * V_1 ;
V_16 &= V_284 ;
F_255 ( V_16 ) ;
if ( F_235 ( V_15 , V_16 ) )
return NULL ;
V_15 = F_256 ( V_15 , V_16 ) ;
F_232 ( V_15 , V_16 ) ;
F_257 ( V_282 ) ;
V_1 = F_261 ( V_15 , V_16 ) ;
F_258 ( V_282 ) ;
V_1 = F_234 ( V_15 , V_16 , V_1 , V_204 ) ;
F_259 ( V_1 , V_15 -> V_205 , 1 , V_15 -> V_16 ,
V_16 ) ;
F_263 ( V_1 ) ;
if ( F_94 ( V_1 ) ) {
F_260 ( V_15 , V_16 , V_1 , V_15 -> V_205 ) ;
if ( F_49 ( V_16 & V_286 ) )
memset ( V_1 , 0 , V_15 -> V_205 ) ;
}
return V_1 ;
}
static void F_86 ( struct V_14 * V_15 , void * * V_288 , int V_289 ,
int V_38 )
{
int V_43 ;
struct V_3 * V_36 ;
for ( V_43 = 0 ; V_43 < V_289 ; V_43 ++ ) {
void * V_1 ;
struct V_23 * V_23 ;
F_3 ( & V_288 [ V_43 ] ) ;
V_1 = V_288 [ V_43 ] ;
V_23 = F_13 ( V_1 ) ;
V_36 = V_15 -> V_38 [ V_38 ] ;
F_202 ( & V_23 -> V_157 ) ;
F_196 ( V_15 , V_38 ) ;
F_217 ( V_15 , V_23 , V_1 , V_38 ) ;
F_264 ( V_15 ) ;
V_36 -> V_12 ++ ;
if ( V_23 -> V_184 == 0 ) {
if ( V_36 -> V_12 > V_36 -> V_112 ) {
V_36 -> V_12 -= V_15 -> V_59 ;
F_173 ( V_15 , V_23 ) ;
} else {
F_124 ( & V_23 -> V_157 , & V_36 -> V_7 ) ;
}
} else {
F_222 ( & V_23 -> V_157 , & V_36 -> V_6 ) ;
}
}
}
static void F_265 ( struct V_14 * V_15 , struct V_34 * V_95 )
{
int V_88 ;
struct V_3 * V_36 ;
int V_38 = F_62 () ;
V_88 = V_95 -> V_88 ;
#if V_231
F_9 ( ! V_88 || V_88 > V_95 -> V_92 ) ;
#endif
F_190 () ;
V_36 = V_15 -> V_38 [ V_38 ] ;
F_85 ( & V_36 -> V_11 ) ;
if ( V_36 -> V_8 ) {
struct V_34 * V_290 = V_36 -> V_8 ;
int V_102 = V_290 -> V_93 - V_290 -> V_92 ;
if ( V_102 ) {
if ( V_88 > V_102 )
V_88 = V_102 ;
memcpy ( & ( V_290 -> V_99 [ V_290 -> V_92 ] ) ,
V_95 -> V_99 , sizeof( void * ) * V_88 ) ;
V_290 -> V_92 += V_88 ;
goto V_291;
}
}
F_86 ( V_15 , V_95 -> V_99 , V_88 , V_38 ) ;
V_291:
#if V_292
{
int V_43 = 0 ;
struct V_244 * V_245 ;
V_245 = V_36 -> V_7 . V_262 ;
while ( V_245 != & ( V_36 -> V_7 ) ) {
struct V_23 * V_23 ;
V_23 = F_201 ( V_245 , struct V_23 , V_157 ) ;
F_9 ( V_23 -> V_184 ) ;
V_43 ++ ;
V_245 = V_245 -> V_262 ;
}
F_266 ( V_15 , V_43 ) ;
}
#endif
F_87 ( & V_36 -> V_11 ) ;
V_95 -> V_92 -= V_88 ;
memmove ( V_95 -> V_99 , & ( V_95 -> V_99 [ V_88 ] ) , sizeof( void * ) * V_95 -> V_92 ) ;
}
static inline void F_267 ( struct V_14 * V_15 , void * V_1 ,
unsigned long V_204 )
{
struct V_34 * V_95 = F_29 ( V_15 ) ;
F_190 () ;
F_268 ( V_1 , V_15 -> V_16 ) ;
V_1 = F_227 ( V_15 , V_1 , V_204 ) ;
F_269 ( V_15 , V_1 , V_15 -> V_205 ) ;
if ( V_293 > 1 && F_78 ( V_15 , V_1 ) )
return;
if ( F_94 ( V_95 -> V_92 < V_95 -> V_93 ) ) {
F_270 ( V_15 ) ;
} else {
F_271 ( V_15 ) ;
F_265 ( V_15 , V_95 ) ;
}
F_73 ( V_15 , V_95 , V_1 ) ;
}
void * F_272 ( struct V_14 * V_15 , T_4 V_16 )
{
void * V_137 = F_262 ( V_15 , V_16 , V_294 ) ;
F_273 ( V_294 , V_137 ,
V_15 -> V_205 , V_15 -> V_19 , V_16 ) ;
return V_137 ;
}
void *
F_274 ( struct V_14 * V_15 , T_4 V_16 , T_2 V_19 )
{
void * V_137 ;
V_137 = F_262 ( V_15 , V_16 , V_294 ) ;
F_275 ( V_294 , V_137 ,
V_19 , V_15 -> V_19 , V_16 ) ;
return V_137 ;
}
void * F_210 ( struct V_14 * V_15 , T_4 V_16 , int V_105 )
{
void * V_137 = F_254 ( V_15 , V_16 , V_105 , V_294 ) ;
F_276 ( V_294 , V_137 ,
V_15 -> V_205 , V_15 -> V_19 ,
V_16 , V_105 ) ;
return V_137 ;
}
void * F_277 ( struct V_14 * V_15 ,
T_4 V_16 ,
int V_105 ,
T_2 V_19 )
{
void * V_137 ;
V_137 = F_254 ( V_15 , V_16 , V_105 , V_294 ) ;
F_278 ( V_294 , V_137 ,
V_19 , V_15 -> V_19 ,
V_16 , V_105 ) ;
return V_137 ;
}
static T_8 void *
F_279 ( T_2 V_19 , T_4 V_16 , int V_38 , unsigned long V_204 )
{
struct V_14 * V_15 ;
V_15 = F_186 ( V_19 , V_16 ) ;
if ( F_49 ( F_187 ( V_15 ) ) )
return V_15 ;
return F_277 ( V_15 , V_16 , V_38 , V_19 ) ;
}
void * F_280 ( T_2 V_19 , T_4 V_16 , int V_38 )
{
return F_279 ( V_19 , V_16 , V_38 , V_294 ) ;
}
void * F_281 ( T_2 V_19 , T_4 V_16 ,
int V_38 , unsigned long V_204 )
{
return F_279 ( V_19 , V_16 , V_38 , V_204 ) ;
}
void * F_280 ( T_2 V_19 , T_4 V_16 , int V_38 )
{
return F_279 ( V_19 , V_16 , V_38 , 0 ) ;
}
static T_8 void * F_282 ( T_2 V_19 , T_4 V_16 ,
unsigned long V_204 )
{
struct V_14 * V_15 ;
void * V_137 ;
V_15 = F_186 ( V_19 , V_16 ) ;
if ( F_49 ( F_187 ( V_15 ) ) )
return V_15 ;
V_137 = F_262 ( V_15 , V_16 , V_204 ) ;
F_275 ( V_204 , V_137 ,
V_19 , V_15 -> V_19 , V_16 ) ;
return V_137 ;
}
void * F_283 ( T_2 V_19 , T_4 V_16 )
{
return F_282 ( V_19 , V_16 , V_294 ) ;
}
void * F_284 ( T_2 V_19 , T_4 V_16 , unsigned long V_204 )
{
return F_282 ( V_19 , V_16 , V_204 ) ;
}
void * F_283 ( T_2 V_19 , T_4 V_16 )
{
return F_282 ( V_19 , V_16 , 0 ) ;
}
void F_175 ( struct V_14 * V_15 , void * V_1 )
{
unsigned long V_16 ;
V_15 = F_285 ( V_15 , V_1 ) ;
if ( ! V_15 )
return;
F_257 ( V_16 ) ;
F_286 ( V_1 , V_15 -> V_205 ) ;
if ( ! ( V_15 -> V_16 & V_118 ) )
F_287 ( V_1 , V_15 -> V_205 ) ;
F_267 ( V_15 , V_1 , V_294 ) ;
F_258 ( V_16 ) ;
F_288 ( V_294 , V_1 ) ;
}
void F_83 ( const void * V_1 )
{
struct V_14 * V_295 ;
unsigned long V_16 ;
F_289 ( V_294 , V_1 ) ;
if ( F_49 ( F_187 ( V_1 ) ) )
return;
F_257 ( V_16 ) ;
F_224 ( V_1 ) ;
V_295 = F_12 ( V_1 ) ;
F_286 ( V_1 , V_295 -> V_205 ) ;
F_287 ( V_1 , V_295 -> V_205 ) ;
F_267 ( V_295 , ( void * ) V_1 , V_294 ) ;
F_258 ( V_16 ) ;
}
static int F_290 ( struct V_14 * V_15 , T_4 V_89 )
{
int V_38 ;
struct V_3 * V_36 ;
struct V_34 * V_296 ;
struct V_34 * * V_297 = NULL ;
F_22 (node) {
if ( V_71 ) {
V_297 = F_76 ( V_38 , V_15 -> V_93 , V_89 ) ;
if ( ! V_297 )
goto V_298;
}
V_296 = NULL ;
if ( V_15 -> V_8 ) {
V_296 = F_56 ( V_38 ,
V_15 -> V_8 * V_15 -> V_88 ,
0xbaadf00d , V_89 ) ;
if ( ! V_296 ) {
F_77 ( V_297 ) ;
goto V_298;
}
}
V_36 = V_15 -> V_38 [ V_38 ] ;
if ( V_36 ) {
struct V_34 * V_8 = V_36 -> V_8 ;
F_98 ( & V_36 -> V_11 ) ;
if ( V_8 )
F_86 ( V_15 , V_8 -> V_99 ,
V_8 -> V_92 , V_38 ) ;
V_36 -> V_8 = V_296 ;
if ( ! V_36 -> V_9 ) {
V_36 -> V_9 = V_297 ;
V_297 = NULL ;
}
V_36 -> V_112 = ( 1 + F_99 ( V_38 ) ) *
V_15 -> V_88 + V_15 -> V_59 ;
F_90 ( & V_36 -> V_11 ) ;
F_83 ( V_8 ) ;
F_77 ( V_297 ) ;
continue;
}
V_36 = F_57 ( sizeof( struct V_3 ) , V_89 , V_38 ) ;
if ( ! V_36 ) {
F_77 ( V_297 ) ;
F_83 ( V_296 ) ;
goto V_298;
}
F_4 ( V_36 ) ;
V_36 -> V_109 = V_110 + V_111 +
( ( unsigned long ) V_15 ) % V_111 ;
V_36 -> V_8 = V_296 ;
V_36 -> V_9 = V_297 ;
V_36 -> V_112 = ( 1 + F_99 ( V_38 ) ) *
V_15 -> V_88 + V_15 -> V_59 ;
V_15 -> V_38 [ V_38 ] = V_36 ;
}
return 0 ;
V_298:
if ( ! V_15 -> V_151 . V_262 ) {
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
return - V_108 ;
}
static void F_291 ( void * V_299 )
{
struct V_300 * V_301 = V_299 ;
struct V_34 * V_302 ;
F_190 () ;
V_302 = F_29 ( V_301 -> V_15 ) ;
V_301 -> V_15 -> V_50 [ F_30 () ] = V_301 -> V_301 [ F_30 () ] ;
V_301 -> V_301 [ F_30 () ] = V_302 ;
}
static int F_292 ( struct V_14 * V_15 , int V_93 ,
int V_88 , int V_8 , T_4 V_89 )
{
struct V_300 * V_301 ;
int V_43 ;
V_301 = F_293 ( sizeof( * V_301 ) + V_156 * sizeof( struct V_34 * ) ,
V_89 ) ;
if ( ! V_301 )
return - V_108 ;
F_135 (i) {
V_301 -> V_301 [ V_43 ] = F_56 ( F_44 ( V_43 ) , V_93 ,
V_88 , V_89 ) ;
if ( ! V_301 -> V_301 [ V_43 ] ) {
for ( V_43 -- ; V_43 >= 0 ; V_43 -- )
F_83 ( V_301 -> V_301 [ V_43 ] ) ;
F_83 ( V_301 ) ;
return - V_108 ;
}
}
V_301 -> V_15 = V_15 ;
F_199 ( F_291 , ( void * ) V_301 , 1 ) ;
F_192 () ;
V_15 -> V_88 = V_88 ;
V_15 -> V_93 = V_93 ;
V_15 -> V_8 = V_8 ;
F_135 (i) {
struct V_34 * V_303 = V_301 -> V_301 [ V_43 ] ;
if ( ! V_303 )
continue;
F_98 ( & V_15 -> V_38 [ F_44 ( V_43 ) ] -> V_11 ) ;
F_86 ( V_15 , V_303 -> V_99 , V_303 -> V_92 , F_44 ( V_43 ) ) ;
F_90 ( & V_15 -> V_38 [ F_44 ( V_43 ) ] -> V_11 ) ;
F_83 ( V_303 ) ;
}
F_83 ( V_301 ) ;
return F_290 ( V_15 , V_89 ) ;
}
static int F_294 ( struct V_14 * V_15 , int V_93 ,
int V_88 , int V_8 , T_4 V_89 )
{
int V_137 ;
struct V_14 * V_295 = NULL ;
int V_43 = 0 ;
V_137 = F_292 ( V_15 , V_93 , V_88 , V_8 , V_89 ) ;
if ( V_44 < V_175 )
return V_137 ;
if ( ( V_137 < 0 ) || ! F_295 ( V_15 ) )
return V_137 ;
F_27 ( ! F_296 ( & V_126 ) ) ;
F_297 (i) {
V_295 = F_298 ( V_15 , V_43 ) ;
if ( V_295 )
F_292 ( V_295 , V_93 , V_88 , V_8 , V_89 ) ;
}
return V_137 ;
}
static int F_130 ( struct V_14 * V_15 , T_4 V_89 )
{
int V_116 ;
int V_93 = 0 ;
int V_8 = 0 ;
int V_88 = 0 ;
if ( ! F_295 ( V_15 ) ) {
struct V_14 * V_304 = F_299 ( V_15 ) ;
V_93 = V_304 -> V_93 ;
V_8 = V_304 -> V_8 ;
V_88 = V_304 -> V_88 ;
}
if ( V_93 && V_8 && V_88 )
goto V_305;
if ( V_15 -> V_19 > 131072 )
V_93 = 1 ;
else if ( V_15 -> V_19 > V_61 )
V_93 = 8 ;
else if ( V_15 -> V_19 > 1024 )
V_93 = 24 ;
else if ( V_15 -> V_19 > 256 )
V_93 = 54 ;
else
V_93 = 120 ;
V_8 = 0 ;
if ( V_15 -> V_19 <= V_61 && F_300 () > 1 )
V_8 = 8 ;
#if V_231
if ( V_93 > 32 )
V_93 = 32 ;
#endif
V_88 = ( V_93 + 1 ) / 2 ;
V_305:
V_116 = F_294 ( V_15 , V_93 , V_88 , V_8 , V_89 ) ;
if ( V_116 )
F_35 ( V_66 L_36 ,
V_15 -> V_67 , - V_116 ) ;
return V_116 ;
}
static void F_200 ( struct V_14 * V_15 , struct V_3 * V_36 ,
struct V_34 * V_95 , int V_306 , int V_38 )
{
int V_243 ;
if ( ! V_95 || ! V_95 -> V_92 )
return;
if ( V_95 -> V_94 && ! V_306 ) {
V_95 -> V_94 = 0 ;
} else {
F_98 ( & V_36 -> V_11 ) ;
if ( V_95 -> V_92 ) {
V_243 = V_306 ? V_95 -> V_92 : ( V_95 -> V_93 + 4 ) / 5 ;
if ( V_243 > V_95 -> V_92 )
V_243 = ( V_95 -> V_92 + 1 ) / 2 ;
F_86 ( V_15 , V_95 -> V_99 , V_243 , V_38 ) ;
V_95 -> V_92 -= V_243 ;
memmove ( V_95 -> V_99 , & ( V_95 -> V_99 [ V_243 ] ) ,
sizeof( void * ) * V_95 -> V_92 ) ;
}
F_90 ( & V_36 -> V_11 ) ;
}
}
static void V_85 ( struct V_307 * V_308 )
{
struct V_14 * V_309 ;
struct V_3 * V_36 ;
int V_38 = F_62 () ;
struct V_80 * V_83 = F_301 ( V_308 ) ;
if ( ! F_302 ( & V_126 ) )
goto V_97;
F_64 (searchp, &slab_caches, list) {
F_192 () ;
V_36 = V_309 -> V_38 [ V_38 ] ;
F_88 ( V_309 , V_36 ) ;
F_200 ( V_309 , V_36 , F_29 ( V_309 ) , 0 , V_38 ) ;
if ( F_303 ( V_36 -> V_109 , V_110 ) )
goto V_262;
V_36 -> V_109 = V_110 + V_111 ;
F_200 ( V_309 , V_36 , V_36 -> V_8 , 0 , V_38 ) ;
if ( V_36 -> V_13 )
V_36 -> V_13 = 0 ;
else {
int V_310 ;
V_310 = F_104 ( V_309 , V_36 , ( V_36 -> V_112 +
5 * V_309 -> V_59 - 1 ) / ( 5 * V_309 -> V_59 ) ) ;
F_304 ( V_309 , V_310 ) ;
}
V_262:
F_305 () ;
}
F_192 () ;
F_109 ( & V_126 ) ;
F_47 () ;
V_97:
F_306 ( V_83 , F_307 ( V_311 ) ) ;
}
void F_308 ( struct V_14 * V_15 , struct V_312 * V_313 )
{
struct V_23 * V_23 ;
unsigned long V_180 ;
unsigned long V_181 ;
unsigned long V_182 = 0 ;
unsigned long V_183 , V_12 = 0 , V_314 = 0 ;
const char * V_67 ;
char * error = NULL ;
int V_38 ;
struct V_3 * V_36 ;
V_180 = 0 ;
V_183 = 0 ;
F_22 (node) {
V_36 = V_15 -> V_38 [ V_38 ] ;
if ( ! V_36 )
continue;
F_192 () ;
F_98 ( & V_36 -> V_11 ) ;
F_64 (page, &n->slabs_full, lru) {
if ( V_23 -> V_184 != V_15 -> V_59 && ! error )
error = L_37 ;
V_180 += V_15 -> V_59 ;
V_182 ++ ;
}
F_64 (page, &n->slabs_partial, lru) {
if ( V_23 -> V_184 == V_15 -> V_59 && ! error )
error = L_38 ;
if ( ! V_23 -> V_184 && ! error )
error = L_38 ;
V_180 += V_23 -> V_184 ;
V_182 ++ ;
}
F_64 (page, &n->slabs_free, lru) {
if ( V_23 -> V_184 && ! error )
error = L_39 ;
V_183 ++ ;
}
V_12 += V_36 -> V_12 ;
if ( V_36 -> V_8 )
V_314 += V_36 -> V_8 -> V_92 ;
F_90 ( & V_36 -> V_11 ) ;
}
V_183 += V_182 ;
V_181 = V_183 * V_15 -> V_59 ;
if ( V_181 - V_180 != V_12 && ! error )
error = L_40 ;
V_67 = V_15 -> V_67 ;
if ( error )
F_35 ( V_66 L_41 , V_67 , error ) ;
V_313 -> V_180 = V_180 ;
V_313 -> V_181 = V_181 ;
V_313 -> V_182 = V_182 ;
V_313 -> V_183 = V_183 ;
V_313 -> V_314 = V_314 ;
V_313 -> V_93 = V_15 -> V_93 ;
V_313 -> V_88 = V_15 -> V_88 ;
V_313 -> V_8 = V_15 -> V_8 ;
V_313 -> V_315 = V_15 -> V_59 ;
V_313 -> V_316 = V_15 -> V_57 ;
}
void F_309 ( struct V_317 * V_318 , struct V_14 * V_15 )
{
#if V_292
{
unsigned long V_319 = V_15 -> V_320 ;
unsigned long V_321 = V_15 -> V_322 ;
unsigned long V_323 = V_15 -> V_323 ;
unsigned long V_324 = V_15 -> V_324 ;
unsigned long V_325 = V_15 -> V_325 ;
unsigned long V_326 = V_15 -> V_326 ;
unsigned long V_327 = V_15 -> V_327 ;
unsigned long V_328 = V_15 -> V_328 ;
unsigned long V_329 = V_15 -> V_330 ;
F_310 ( V_318 , L_42
L_43 ,
V_321 , V_319 , V_323 ,
V_324 , V_325 , V_326 , V_327 ,
V_328 , V_329 ) ;
}
{
unsigned long V_331 = F_311 ( & V_15 -> V_331 ) ;
unsigned long V_332 = F_311 ( & V_15 -> V_332 ) ;
unsigned long V_333 = F_311 ( & V_15 -> V_333 ) ;
unsigned long V_334 = F_311 ( & V_15 -> V_334 ) ;
F_310 ( V_318 , L_44 ,
V_331 , V_332 , V_333 , V_334 ) ;
}
#endif
}
T_9 F_312 ( struct V_335 * V_335 , const char T_10 * V_336 ,
T_2 V_337 , T_11 * V_338 )
{
char V_339 [ V_340 + 1 ] , * V_341 ;
int V_93 , V_88 , V_8 , V_342 ;
struct V_14 * V_15 ;
if ( V_337 > V_340 )
return - V_343 ;
if ( F_313 ( & V_339 , V_336 , V_337 ) )
return - V_344 ;
V_339 [ V_340 ] = '\0' ;
V_341 = strchr ( V_339 , ' ' ) ;
if ( ! V_341 )
return - V_343 ;
* V_341 = '\0' ;
V_341 ++ ;
if ( sscanf ( V_341 , L_45 , & V_93 , & V_88 , & V_8 ) != 3 )
return - V_343 ;
F_108 ( & V_126 ) ;
V_342 = - V_343 ;
F_64 (cachep, &slab_caches, list) {
if ( ! strcmp ( V_15 -> V_67 , V_339 ) ) {
if ( V_93 < 1 || V_88 < 1 ||
V_88 > V_93 || V_8 < 0 ) {
V_342 = 0 ;
} else {
V_342 = F_294 ( V_15 , V_93 ,
V_88 , V_8 ,
V_107 ) ;
}
break;
}
}
F_109 ( & V_126 ) ;
if ( V_342 >= 0 )
V_342 = V_337 ;
return V_342 ;
}
static void * F_314 ( struct V_317 * V_318 , T_11 * V_345 )
{
F_108 ( & V_126 ) ;
return F_315 ( & V_166 , * V_345 ) ;
}
static inline int F_316 ( unsigned long * V_36 , unsigned long V_346 )
{
unsigned long * V_245 ;
int V_347 ;
if ( ! V_346 )
return 1 ;
V_347 = V_36 [ 1 ] ;
V_245 = V_36 + 2 ;
while ( V_347 ) {
int V_43 = V_347 / 2 ;
unsigned long * V_33 = V_245 + 2 * V_43 ;
if ( * V_33 == V_346 ) {
V_33 [ 1 ] ++ ;
return 1 ;
}
if ( * V_33 > V_346 ) {
V_347 = V_43 ;
} else {
V_245 = V_33 + 2 ;
V_347 -= V_43 + 1 ;
}
}
if ( ++ V_36 [ 1 ] == V_36 [ 0 ] )
return 0 ;
memmove ( V_245 + 2 , V_245 , V_36 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_245 - ( void * ) V_36 ) ) ;
V_245 [ 0 ] = V_346 ;
V_245 [ 1 ] = 1 ;
return 1 ;
}
static void F_317 ( unsigned long * V_36 , struct V_14 * V_295 ,
struct V_23 * V_23 )
{
void * V_245 ;
int V_43 , V_348 ;
if ( V_36 [ 0 ] == V_36 [ 1 ] )
return;
for ( V_43 = 0 , V_245 = V_23 -> V_27 ; V_43 < V_295 -> V_59 ; V_43 ++ , V_245 += V_295 -> V_19 ) {
bool V_184 = true ;
for ( V_348 = V_23 -> V_184 ; V_348 < V_295 -> V_59 ; V_348 ++ ) {
if ( F_211 ( V_23 , V_348 ) == V_43 ) {
V_184 = false ;
break;
}
}
if ( ! V_184 )
continue;
if ( ! F_316 ( V_36 , ( unsigned long ) * F_11 ( V_295 , V_245 ) ) )
return;
}
}
static void F_318 ( struct V_317 * V_318 , unsigned long V_349 )
{
#ifdef F_319
unsigned long V_28 , V_19 ;
char V_350 [ V_351 ] , V_67 [ V_352 ] ;
if ( F_320 ( V_349 , & V_19 , & V_28 , V_350 , V_67 ) == 0 ) {
F_310 ( V_318 , L_46 , V_67 , V_28 , V_19 ) ;
if ( V_350 [ 0 ] )
F_310 ( V_318 , L_47 , V_350 ) ;
return;
}
#endif
F_310 ( V_318 , L_48 , ( void * ) V_349 ) ;
}
static int F_321 ( struct V_317 * V_318 , void * V_245 )
{
struct V_14 * V_15 = F_201 ( V_245 , struct V_14 , V_151 ) ;
struct V_23 * V_23 ;
struct V_3 * V_36 ;
const char * V_67 ;
unsigned long * V_264 = V_318 -> V_353 ;
int V_38 ;
int V_43 ;
if ( ! ( V_15 -> V_16 & V_18 ) )
return 0 ;
if ( ! ( V_15 -> V_16 & V_17 ) )
return 0 ;
V_264 [ 1 ] = 0 ;
F_22 (node) {
V_36 = V_15 -> V_38 [ V_38 ] ;
if ( ! V_36 )
continue;
F_192 () ;
F_98 ( & V_36 -> V_11 ) ;
F_64 (page, &n->slabs_full, lru)
F_317 ( V_264 , V_15 , V_23 ) ;
F_64 (page, &n->slabs_partial, lru)
F_317 ( V_264 , V_15 , V_23 ) ;
F_90 ( & V_36 -> V_11 ) ;
}
V_67 = V_15 -> V_67 ;
if ( V_264 [ 0 ] == V_264 [ 1 ] ) {
F_109 ( & V_126 ) ;
V_318 -> V_353 = F_293 ( V_264 [ 0 ] * 4 * sizeof( unsigned long ) , V_107 ) ;
if ( ! V_318 -> V_353 ) {
V_318 -> V_353 = V_264 ;
F_108 ( & V_126 ) ;
return - V_108 ;
}
* ( unsigned long * ) V_318 -> V_353 = V_264 [ 0 ] * 2 ;
F_83 ( V_264 ) ;
F_108 ( & V_126 ) ;
V_318 -> V_337 = V_318 -> V_19 ;
return 0 ;
}
for ( V_43 = 0 ; V_43 < V_264 [ 1 ] ; V_43 ++ ) {
F_310 ( V_318 , L_49 , V_67 , V_264 [ 2 * V_43 + 3 ] ) ;
F_318 ( V_318 , V_264 [ 2 * V_43 + 2 ] ) ;
F_322 ( V_318 , '\n' ) ;
}
return 0 ;
}
static int F_323 ( struct V_354 * V_354 , struct V_335 * V_335 )
{
unsigned long * V_36 = F_293 ( V_61 , V_107 ) ;
int V_137 = - V_108 ;
if ( V_36 ) {
V_137 = F_324 ( V_335 , & V_355 ) ;
if ( ! V_137 ) {
struct V_317 * V_318 = V_335 -> V_356 ;
* V_36 = V_61 / ( 2 * sizeof( unsigned long ) ) ;
V_318 -> V_353 = V_36 ;
V_36 = NULL ;
}
F_83 ( V_36 ) ;
}
return V_137 ;
}
static int T_3 F_325 ( void )
{
#ifdef F_326
F_327 ( L_50 , 0 , NULL , & V_357 ) ;
#endif
return 0 ;
}
T_2 F_328 ( const void * V_1 )
{
F_9 ( ! V_1 ) ;
if ( F_49 ( V_1 == V_358 ) )
return 0 ;
return F_12 ( V_1 ) -> V_205 ;
}
