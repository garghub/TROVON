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
static inline struct V_25 * F_14 ( const void * V_22 )
{
struct V_23 * V_23 = F_13 ( V_22 ) ;
F_15 ( ! F_16 ( V_23 ) ) ;
return V_23 -> V_26 ;
}
static inline void * F_17 ( struct V_14 * V_27 , struct V_25 * V_25 ,
unsigned int V_28 )
{
return V_25 -> V_29 + V_27 -> V_19 * V_28 ;
}
static inline unsigned int F_18 ( const struct V_14 * V_27 ,
const struct V_25 * V_25 , void * V_22 )
{
T_1 V_30 = ( V_22 - V_25 -> V_29 ) ;
return F_19 ( V_30 , V_27 -> V_31 ) ;
}
static void F_20 ( struct V_14 * V_15 ,
struct V_32 * V_33 , struct V_32 * V_34 ,
int V_35 )
{
struct V_36 * * V_37 ;
struct V_3 * V_38 ;
int V_39 ;
V_38 = V_15 -> V_40 [ V_35 ] ;
if ( ! V_38 )
return;
F_21 ( & V_38 -> V_11 , V_33 ) ;
V_37 = V_38 -> V_9 ;
if ( ! V_37 || ( unsigned long ) V_37 == V_41 )
return;
F_22 (r) {
if ( V_37 [ V_39 ] )
F_21 ( & V_37 [ V_39 ] -> V_42 , V_34 ) ;
}
}
static void F_23 ( struct V_14 * V_15 , int V_40 )
{
F_20 ( V_15 , & V_43 , & V_44 , V_40 ) ;
}
static void F_24 ( struct V_14 * V_15 )
{
int V_40 ;
F_25 (node)
F_23 ( V_15 , V_40 ) ;
}
static void F_26 ( int V_35 )
{
int V_45 ;
if ( V_46 < V_47 )
return;
for ( V_45 = 1 ; V_45 <= V_48 ; V_45 ++ ) {
struct V_3 * V_38 ;
struct V_14 * V_27 = V_49 [ V_45 ] ;
if ( ! V_27 )
continue;
V_38 = V_27 -> V_40 [ V_35 ] ;
if ( ! V_38 || F_27 ( V_27 ) )
continue;
F_20 ( V_27 , & V_50 ,
& V_51 , V_35 ) ;
}
}
static void F_28 ( struct V_14 * V_15 , int V_35 )
{
if ( ! V_15 -> V_40 [ V_35 ] )
return;
F_20 ( V_15 , & V_50 ,
& V_51 , V_35 ) ;
}
static inline void F_29 ( struct V_14 * V_15 )
{
int V_40 ;
F_15 ( F_27 ( V_15 ) ) ;
F_22 (node)
F_28 ( V_15 , V_40 ) ;
}
static inline void F_30 ( void )
{
int V_40 ;
F_22 (node)
F_26 ( V_40 ) ;
}
static void F_26 ( int V_35 )
{
}
static inline void F_30 ( void )
{
}
static inline void F_29 ( struct V_14 * V_15 )
{
}
static inline void F_28 ( struct V_14 * V_15 , int V_40 )
{
}
static void F_23 ( struct V_14 * V_15 , int V_40 )
{
}
static void F_24 ( struct V_14 * V_15 )
{
}
static inline struct V_36 * F_31 ( struct V_14 * V_15 )
{
return V_15 -> V_52 [ F_32 () ] ;
}
static T_2 F_33 ( T_2 V_53 , T_2 V_54 )
{
return F_34 ( sizeof( struct V_25 ) + V_53 * sizeof( V_55 ) , V_54 ) ;
}
static void F_35 ( unsigned long V_56 , T_2 V_57 ,
T_2 V_54 , int V_16 , T_2 * V_58 ,
unsigned int * V_59 )
{
int V_53 ;
T_2 V_60 ;
T_2 V_61 = V_62 << V_56 ;
if ( V_16 & V_63 ) {
V_60 = 0 ;
V_53 = V_61 / V_57 ;
if ( V_53 > V_64 )
V_53 = V_64 ;
} else {
V_53 = ( V_61 - sizeof( struct V_25 ) ) /
( V_57 + sizeof( V_55 ) ) ;
if ( F_33 ( V_53 , V_54 ) + V_53 * V_57
> V_61 )
V_53 -- ;
if ( V_53 > V_64 )
V_53 = V_64 ;
V_60 = F_33 ( V_53 , V_54 ) ;
}
* V_59 = V_53 ;
* V_58 = V_61 - V_53 * V_57 - V_60 ;
}
static void F_36 ( const char * V_65 , struct V_14 * V_15 ,
char * V_66 )
{
F_37 ( V_67 L_1 ,
V_65 , V_15 -> V_68 , V_66 ) ;
F_38 () ;
F_39 ( V_69 , V_70 ) ;
}
static int T_3 F_40 ( char * V_71 )
{
V_72 = 0 ;
return 1 ;
}
static int T_3 F_41 ( char * V_73 )
{
F_42 ( & V_73 , & V_74 ) ;
V_74 = V_74 < 0 ? 0 :
F_43 ( V_74 , V_75 - 1 ) ;
V_76 = true ;
return 1 ;
}
static void F_44 ( int V_77 )
{
int V_40 ;
V_40 = F_45 ( F_46 ( V_77 ) , V_78 ) ;
if ( V_40 == V_79 )
V_40 = F_47 ( V_78 ) ;
F_48 ( V_80 , V_77 ) = V_40 ;
}
static void F_49 ( void )
{
int V_40 = F_50 ( V_80 ) ;
V_40 = F_45 ( V_40 , V_78 ) ;
if ( F_51 ( V_40 >= V_79 ) )
V_40 = F_47 ( V_78 ) ;
F_52 ( V_80 , V_40 ) ;
}
static void F_53 ( int V_77 )
{
struct V_81 * V_82 = & F_48 ( V_83 , V_77 ) ;
if ( F_54 () && V_82 -> V_84 . V_85 == NULL ) {
F_44 ( V_77 ) ;
F_55 ( V_82 , V_86 ) ;
F_56 ( V_77 , V_82 ,
F_57 ( V_87 , V_77 ) ) ;
}
}
static struct V_36 * F_58 ( int V_40 , int V_88 ,
int V_89 , T_4 V_90 )
{
int V_91 = sizeof( void * ) * V_88 + sizeof( struct V_36 ) ;
struct V_36 * V_92 = NULL ;
V_92 = F_59 ( V_91 , V_90 , V_40 ) ;
F_60 ( V_92 ) ;
if ( V_92 ) {
V_92 -> V_93 = 0 ;
V_92 -> V_94 = V_88 ;
V_92 -> V_89 = V_89 ;
V_92 -> V_95 = 0 ;
F_6 ( & V_92 -> V_42 ) ;
}
return V_92 ;
}
static inline bool F_61 ( struct V_25 * V_96 )
{
struct V_23 * V_23 = F_62 ( V_96 -> V_29 ) ;
return F_63 ( V_23 ) ;
}
static void F_64 ( struct V_14 * V_15 ,
struct V_36 * V_97 )
{
struct V_3 * V_38 = V_15 -> V_40 [ F_65 () ] ;
struct V_25 * V_96 ;
unsigned long V_16 ;
if ( ! V_98 )
return;
F_66 ( & V_38 -> V_11 , V_16 ) ;
F_67 (slabp, &n->slabs_full, list)
if ( F_61 ( V_96 ) )
goto V_99;
F_67 (slabp, &n->slabs_partial, list)
if ( F_61 ( V_96 ) )
goto V_99;
F_67 (slabp, &n->slabs_free, list)
if ( F_61 ( V_96 ) )
goto V_99;
V_98 = false ;
V_99:
F_68 ( & V_38 -> V_11 , V_16 ) ;
}
static void * F_69 ( struct V_14 * V_15 , struct V_36 * V_97 ,
T_4 V_16 , bool V_100 )
{
int V_45 ;
void * V_1 = V_97 -> V_101 [ -- V_97 -> V_93 ] ;
if ( F_51 ( F_1 ( V_1 ) ) ) {
struct V_3 * V_38 ;
if ( F_70 ( V_16 ) ) {
F_3 ( & V_1 ) ;
return V_1 ;
}
for ( V_45 = 0 ; V_45 < V_97 -> V_93 ; V_45 ++ ) {
if ( ! F_1 ( V_97 -> V_101 [ V_45 ] ) ) {
V_1 = V_97 -> V_101 [ V_45 ] ;
V_97 -> V_101 [ V_45 ] = V_97 -> V_101 [ V_97 -> V_93 ] ;
V_97 -> V_101 [ V_97 -> V_93 ] = V_1 ;
return V_1 ;
}
}
V_38 = V_15 -> V_40 [ F_65 () ] ;
if ( ! F_71 ( & V_38 -> V_7 ) && V_100 ) {
struct V_25 * V_96 = F_14 ( V_1 ) ;
F_72 ( F_13 ( V_96 -> V_29 ) ) ;
F_3 ( & V_1 ) ;
F_64 ( V_15 , V_97 ) ;
return V_1 ;
}
V_97 -> V_93 ++ ;
V_1 = NULL ;
}
return V_1 ;
}
static inline void * F_73 ( struct V_14 * V_15 ,
struct V_36 * V_97 , T_4 V_16 , bool V_100 )
{
void * V_1 ;
if ( F_51 ( F_74 () ) )
V_1 = F_69 ( V_15 , V_97 , V_16 , V_100 ) ;
else
V_1 = V_97 -> V_101 [ -- V_97 -> V_93 ] ;
return V_1 ;
}
static void * F_75 ( struct V_14 * V_15 , struct V_36 * V_97 ,
void * V_1 )
{
if ( F_51 ( V_98 ) ) {
struct V_23 * V_23 = F_13 ( V_1 ) ;
if ( F_63 ( V_23 ) )
F_2 ( & V_1 ) ;
}
return V_1 ;
}
static inline void F_76 ( struct V_14 * V_15 , struct V_36 * V_97 ,
void * V_1 )
{
if ( F_51 ( F_74 () ) )
V_1 = F_75 ( V_15 , V_97 , V_1 ) ;
V_97 -> V_101 [ V_97 -> V_93 ++ ] = V_1 ;
}
static int F_77 ( struct V_36 * V_102 ,
struct V_36 * V_103 , unsigned int V_104 )
{
int V_105 = F_78 ( V_103 -> V_93 , V_104 , V_102 -> V_94 - V_102 -> V_93 ) ;
if ( ! V_105 )
return 0 ;
memcpy ( V_102 -> V_101 + V_102 -> V_93 , V_103 -> V_101 + V_103 -> V_93 - V_105 ,
sizeof( void * ) * V_105 ) ;
V_103 -> V_93 -= V_105 ;
V_102 -> V_93 += V_105 ;
return V_105 ;
}
static inline struct V_36 * * F_79 ( int V_40 , int V_94 , T_4 V_90 )
{
return (struct V_36 * * ) V_41 ;
}
static inline void F_80 ( struct V_36 * * V_106 )
{
}
static inline int F_81 ( struct V_14 * V_15 , void * V_1 )
{
return 0 ;
}
static inline void * F_82 ( struct V_14 * V_15 ,
T_4 V_16 )
{
return NULL ;
}
static inline void * F_83 ( struct V_14 * V_15 ,
T_4 V_16 , int V_107 )
{
return NULL ;
}
static struct V_36 * * F_79 ( int V_40 , int V_94 , T_4 V_90 )
{
struct V_36 * * V_106 ;
int V_91 = sizeof( void * ) * V_108 ;
int V_45 ;
if ( V_94 > 1 )
V_94 = 12 ;
V_106 = F_84 ( V_91 , V_90 , V_40 ) ;
if ( V_106 ) {
F_22 (i) {
if ( V_45 == V_40 || ! F_85 ( V_45 ) )
continue;
V_106 [ V_45 ] = F_58 ( V_40 , V_94 , 0xbaadf00d , V_90 ) ;
if ( ! V_106 [ V_45 ] ) {
for ( V_45 -- ; V_45 >= 0 ; V_45 -- )
F_86 ( V_106 [ V_45 ] ) ;
F_86 ( V_106 ) ;
return NULL ;
}
}
}
return V_106 ;
}
static void F_80 ( struct V_36 * * V_106 )
{
int V_45 ;
if ( ! V_106 )
return;
F_22 (i)
F_86 ( V_106 [ V_45 ] ) ;
F_86 ( V_106 ) ;
}
static void F_87 ( struct V_14 * V_15 ,
struct V_36 * V_97 , int V_40 )
{
struct V_3 * V_38 = V_15 -> V_40 [ V_40 ] ;
if ( V_97 -> V_93 ) {
F_88 ( & V_38 -> V_11 ) ;
if ( V_38 -> V_8 )
F_77 ( V_38 -> V_8 , V_97 , V_97 -> V_94 ) ;
F_89 ( V_15 , V_97 -> V_101 , V_97 -> V_93 , V_40 ) ;
V_97 -> V_93 = 0 ;
F_90 ( & V_38 -> V_11 ) ;
}
}
static void F_91 ( struct V_14 * V_15 , struct V_3 * V_38 )
{
int V_40 = F_50 ( V_80 ) ;
if ( V_38 -> V_9 ) {
struct V_36 * V_97 = V_38 -> V_9 [ V_40 ] ;
if ( V_97 && V_97 -> V_93 && F_92 ( & V_97 -> V_42 ) ) {
F_87 ( V_15 , V_97 , V_40 ) ;
F_93 ( & V_97 -> V_42 ) ;
}
}
}
static void F_94 ( struct V_14 * V_15 ,
struct V_36 * * V_9 )
{
int V_45 = 0 ;
struct V_36 * V_97 ;
unsigned long V_16 ;
F_25 (i) {
V_97 = V_9 [ V_45 ] ;
if ( V_97 ) {
F_66 ( & V_97 -> V_42 , V_16 ) ;
F_87 ( V_15 , V_97 , V_45 ) ;
F_68 ( & V_97 -> V_42 , V_16 ) ;
}
}
}
static inline int F_81 ( struct V_14 * V_15 , void * V_1 )
{
struct V_25 * V_96 = F_14 ( V_1 ) ;
int V_107 = V_96 -> V_107 ;
struct V_3 * V_38 ;
struct V_36 * V_9 = NULL ;
int V_40 ;
V_40 = F_65 () ;
if ( F_95 ( V_96 -> V_107 == V_40 ) )
return 0 ;
V_38 = V_15 -> V_40 [ V_40 ] ;
F_96 ( V_15 ) ;
if ( V_38 -> V_9 && V_38 -> V_9 [ V_107 ] ) {
V_9 = V_38 -> V_9 [ V_107 ] ;
F_88 ( & V_9 -> V_42 ) ;
if ( F_51 ( V_9 -> V_93 == V_9 -> V_94 ) ) {
F_97 ( V_15 ) ;
F_87 ( V_15 , V_9 , V_107 ) ;
}
F_76 ( V_15 , V_9 , V_1 ) ;
F_90 ( & V_9 -> V_42 ) ;
} else {
F_88 ( & ( V_15 -> V_40 [ V_107 ] ) -> V_11 ) ;
F_89 ( V_15 , & V_1 , 1 , V_107 ) ;
F_90 ( & ( V_15 -> V_40 [ V_107 ] ) -> V_11 ) ;
}
return 1 ;
}
static int F_98 ( int V_40 )
{
struct V_14 * V_15 ;
struct V_3 * V_38 ;
const int V_91 = sizeof( struct V_3 ) ;
F_67 (cachep, &slab_caches, list) {
if ( ! V_15 -> V_40 [ V_40 ] ) {
V_38 = F_59 ( V_91 , V_109 , V_40 ) ;
if ( ! V_38 )
return - V_110 ;
F_4 ( V_38 ) ;
V_38 -> V_111 = V_112 + V_113 +
( ( unsigned long ) V_15 ) % V_113 ;
V_15 -> V_40 [ V_40 ] = V_38 ;
}
F_99 ( & V_15 -> V_40 [ V_40 ] -> V_11 ) ;
V_15 -> V_40 [ V_40 ] -> V_114 =
( 1 + F_100 ( V_40 ) ) *
V_15 -> V_89 + V_15 -> V_59 ;
F_93 ( & V_15 -> V_40 [ V_40 ] -> V_11 ) ;
}
return 0 ;
}
static inline int F_101 ( struct V_14 * V_15 ,
struct V_3 * V_38 )
{
return ( V_38 -> V_12 + V_15 -> V_59 - 1 ) / V_15 -> V_59 ;
}
static void F_102 ( long V_77 )
{
struct V_14 * V_15 ;
struct V_3 * V_38 = NULL ;
int V_40 = F_46 ( V_77 ) ;
const struct V_115 * V_116 = F_103 ( V_40 ) ;
F_67 (cachep, &slab_caches, list) {
struct V_36 * V_92 ;
struct V_36 * V_8 ;
struct V_36 * * V_9 ;
V_92 = V_15 -> V_52 [ V_77 ] ;
V_15 -> V_52 [ V_77 ] = NULL ;
V_38 = V_15 -> V_40 [ V_40 ] ;
if ( ! V_38 )
goto V_117;
F_99 ( & V_38 -> V_11 ) ;
V_38 -> V_114 -= V_15 -> V_89 ;
if ( V_92 )
F_89 ( V_15 , V_92 -> V_101 , V_92 -> V_93 , V_40 ) ;
if ( ! F_104 ( V_116 ) ) {
F_93 ( & V_38 -> V_11 ) ;
goto V_117;
}
V_8 = V_38 -> V_8 ;
if ( V_8 ) {
F_89 ( V_15 , V_8 -> V_101 ,
V_8 -> V_93 , V_40 ) ;
V_38 -> V_8 = NULL ;
}
V_9 = V_38 -> V_9 ;
V_38 -> V_9 = NULL ;
F_93 ( & V_38 -> V_11 ) ;
F_86 ( V_8 ) ;
if ( V_9 ) {
F_94 ( V_15 , V_9 ) ;
F_80 ( V_9 ) ;
}
V_117:
F_86 ( V_92 ) ;
}
F_67 (cachep, &slab_caches, list) {
V_38 = V_15 -> V_40 [ V_40 ] ;
if ( ! V_38 )
continue;
F_105 ( V_15 , V_38 , F_101 ( V_15 , V_38 ) ) ;
}
}
static int F_106 ( long V_77 )
{
struct V_14 * V_15 ;
struct V_3 * V_38 = NULL ;
int V_40 = F_46 ( V_77 ) ;
int V_118 ;
V_118 = F_98 ( V_40 ) ;
if ( V_118 < 0 )
goto V_119;
F_67 (cachep, &slab_caches, list) {
struct V_36 * V_92 ;
struct V_36 * V_8 = NULL ;
struct V_36 * * V_9 = NULL ;
V_92 = F_58 ( V_40 , V_15 -> V_94 ,
V_15 -> V_89 , V_109 ) ;
if ( ! V_92 )
goto V_119;
if ( V_15 -> V_8 ) {
V_8 = F_58 ( V_40 ,
V_15 -> V_8 * V_15 -> V_89 ,
0xbaadf00d , V_109 ) ;
if ( ! V_8 ) {
F_86 ( V_92 ) ;
goto V_119;
}
}
if ( V_72 ) {
V_9 = F_79 ( V_40 , V_15 -> V_94 , V_109 ) ;
if ( ! V_9 ) {
F_86 ( V_8 ) ;
F_86 ( V_92 ) ;
goto V_119;
}
}
V_15 -> V_52 [ V_77 ] = V_92 ;
V_38 = V_15 -> V_40 [ V_40 ] ;
F_9 ( ! V_38 ) ;
F_99 ( & V_38 -> V_11 ) ;
if ( ! V_38 -> V_8 ) {
V_38 -> V_8 = V_8 ;
V_8 = NULL ;
}
#ifdef F_107
if ( ! V_38 -> V_9 ) {
V_38 -> V_9 = V_9 ;
V_9 = NULL ;
}
#endif
F_93 ( & V_38 -> V_11 ) ;
F_86 ( V_8 ) ;
F_80 ( V_9 ) ;
if ( V_15 -> V_16 & V_120 )
F_23 ( V_15 , V_40 ) ;
else if ( ! F_27 ( V_15 ) &&
! ( V_15 -> V_16 & V_121 ) )
F_28 ( V_15 , V_40 ) ;
}
F_26 ( V_40 ) ;
return 0 ;
V_119:
F_102 ( V_77 ) ;
return - V_110 ;
}
static int F_108 ( struct V_122 * V_123 ,
unsigned long V_124 , void * V_125 )
{
long V_77 = ( long ) V_125 ;
int V_118 = 0 ;
switch ( V_124 ) {
case V_126 :
case V_127 :
F_109 ( & V_128 ) ;
V_118 = F_106 ( V_77 ) ;
F_110 ( & V_128 ) ;
break;
case V_129 :
case V_130 :
F_53 ( V_77 ) ;
break;
#ifdef F_111
case V_131 :
case V_132 :
F_112 ( & F_48 ( V_83 , V_77 ) ) ;
F_48 ( V_83 , V_77 ) . V_84 . V_85 = NULL ;
break;
case V_133 :
case V_134 :
F_53 ( V_77 ) ;
break;
case V_135 :
case V_136 :
#endif
case V_137 :
case V_138 :
F_109 ( & V_128 ) ;
F_102 ( V_77 ) ;
F_110 ( & V_128 ) ;
break;
}
return F_113 ( V_118 ) ;
}
static int T_5 F_114 ( int V_40 )
{
struct V_14 * V_15 ;
int V_139 = 0 ;
F_67 (cachep, &slab_caches, list) {
struct V_3 * V_38 ;
V_38 = V_15 -> V_40 [ V_40 ] ;
if ( ! V_38 )
continue;
F_105 ( V_15 , V_38 , F_101 ( V_15 , V_38 ) ) ;
if ( ! F_71 ( & V_38 -> V_5 ) ||
! F_71 ( & V_38 -> V_6 ) ) {
V_139 = - V_140 ;
break;
}
}
return V_139 ;
}
static int T_5 F_115 ( struct V_122 * V_141 ,
unsigned long V_124 , void * V_142 )
{
struct V_143 * V_144 = V_142 ;
int V_139 = 0 ;
int V_145 ;
V_145 = V_144 -> V_146 ;
if ( V_145 < 0 )
goto V_99;
switch ( V_124 ) {
case V_147 :
F_109 ( & V_128 ) ;
V_139 = F_98 ( V_145 ) ;
F_110 ( & V_128 ) ;
break;
case V_148 :
F_109 ( & V_128 ) ;
V_139 = F_114 ( V_145 ) ;
F_110 ( & V_128 ) ;
break;
case V_149 :
case V_150 :
case V_151 :
case V_152 :
break;
}
V_99:
return F_113 ( V_139 ) ;
}
static void T_3 F_116 ( struct V_14 * V_15 , struct V_3 * V_153 ,
int V_107 )
{
struct V_3 * V_154 ;
V_154 = F_59 ( sizeof( struct V_3 ) , V_155 , V_107 ) ;
F_9 ( ! V_154 ) ;
memcpy ( V_154 , V_153 , sizeof( struct V_3 ) ) ;
F_6 ( & V_154 -> V_11 ) ;
F_117 ( V_15 , V_154 , V_107 ) ;
V_15 -> V_40 [ V_107 ] = V_154 ;
}
static void T_3 F_118 ( struct V_14 * V_15 , int V_156 )
{
int V_40 ;
F_25 (node) {
V_15 -> V_40 [ V_40 ] = & V_157 [ V_156 + V_40 ] ;
V_15 -> V_40 [ V_40 ] -> V_111 = V_112 +
V_113 +
( ( unsigned long ) V_15 ) % V_113 ;
}
}
static void F_119 ( struct V_14 * V_15 )
{
V_15 -> V_40 = (struct V_3 * * ) & V_15 -> V_52 [ V_158 ] ;
}
void T_3 F_120 ( void )
{
int V_45 ;
V_14 = & V_159 ;
F_119 ( V_14 ) ;
if ( F_121 () == 1 )
V_72 = 0 ;
for ( V_45 = 0 ; V_45 < V_160 ; V_45 ++ )
F_4 ( & V_157 [ V_45 ] ) ;
F_118 ( V_14 , V_161 ) ;
if ( ! V_76 && V_162 > ( 32 << 20 ) >> V_163 )
V_74 = V_164 ;
F_122 ( V_14 , L_2 ,
F_123 ( struct V_14 , V_52 [ V_158 ] ) +
V_108 * sizeof( struct V_3 * ) ,
V_165 ) ;
F_124 ( & V_14 -> V_153 , & V_166 ) ;
V_49 [ V_167 ] = F_125 ( L_3 ,
F_126 ( V_167 ) , V_168 ) ;
if ( V_167 != V_169 )
V_49 [ V_169 ] =
F_125 ( L_4 ,
F_126 ( V_169 ) , V_168 ) ;
V_170 = 0 ;
{
struct V_36 * V_154 ;
V_154 = F_127 ( sizeof( struct V_171 ) , V_155 ) ;
memcpy ( V_154 , F_31 ( V_14 ) ,
sizeof( struct V_171 ) ) ;
F_6 ( & V_154 -> V_42 ) ;
V_14 -> V_52 [ F_32 () ] = V_154 ;
V_154 = F_127 ( sizeof( struct V_171 ) , V_155 ) ;
F_9 ( F_31 ( V_49 [ V_167 ] )
!= & V_172 . V_27 ) ;
memcpy ( V_154 , F_31 ( V_49 [ V_167 ] ) ,
sizeof( struct V_171 ) ) ;
F_6 ( & V_154 -> V_42 ) ;
V_49 [ V_167 ] -> V_52 [ F_32 () ] = V_154 ;
}
{
int V_145 ;
F_25 (nid) {
F_116 ( V_14 , & V_157 [ V_161 + V_145 ] , V_145 ) ;
F_116 ( V_49 [ V_167 ] ,
& V_157 [ V_173 + V_145 ] , V_145 ) ;
if ( V_167 != V_169 ) {
F_116 ( V_49 [ V_169 ] ,
& V_157 [ V_174 + V_145 ] , V_145 ) ;
}
}
}
F_128 ( V_168 ) ;
}
void T_3 F_129 ( void )
{
struct V_14 * V_15 ;
V_46 = V_47 ;
F_109 ( & V_128 ) ;
F_67 (cachep, &slab_caches, list)
if ( F_130 ( V_15 , V_155 ) )
F_131 () ;
F_110 ( & V_128 ) ;
F_30 () ;
V_46 = V_175 ;
F_132 ( & V_176 ) ;
#ifdef F_107
F_133 ( F_115 , V_177 ) ;
#endif
}
static int T_3 F_134 ( void )
{
int V_77 ;
F_135 (cpu)
F_53 ( V_77 ) ;
V_46 = V_175 ;
return 0 ;
}
static T_6 void
F_136 ( struct V_14 * V_15 , T_4 V_178 , int V_107 )
{
struct V_3 * V_38 ;
struct V_25 * V_96 ;
unsigned long V_16 ;
int V_40 ;
F_37 ( V_179
L_5 ,
V_107 , V_178 ) ;
F_37 ( V_179 L_6 ,
V_15 -> V_68 , V_15 -> V_19 , V_15 -> V_56 ) ;
F_25 (node) {
unsigned long V_180 = 0 , V_181 = 0 , V_12 = 0 ;
unsigned long V_182 = 0 , V_183 = 0 ;
V_38 = V_15 -> V_40 [ V_40 ] ;
if ( ! V_38 )
continue;
F_66 ( & V_38 -> V_11 , V_16 ) ;
F_67 (slabp, &n->slabs_full, list) {
V_180 += V_15 -> V_59 ;
V_182 ++ ;
}
F_67 (slabp, &n->slabs_partial, list) {
V_180 += V_96 -> V_184 ;
V_182 ++ ;
}
F_67 (slabp, &n->slabs_free, list)
V_183 ++ ;
V_12 += V_38 -> V_12 ;
F_68 ( & V_38 -> V_11 , V_16 ) ;
V_183 += V_182 ;
V_181 = V_183 * V_15 -> V_59 ;
F_37 ( V_179
L_7 ,
V_40 , V_182 , V_183 , V_180 , V_181 ,
V_12 ) ;
}
}
static void * F_137 ( struct V_14 * V_15 , T_4 V_16 , int V_107 )
{
struct V_23 * V_23 ;
int V_185 ;
int V_45 ;
#ifndef F_138
V_16 |= V_186 ;
#endif
V_16 |= V_15 -> V_187 ;
if ( V_15 -> V_16 & V_188 )
V_16 |= V_189 ;
V_23 = F_139 ( V_107 , V_16 | V_190 , V_15 -> V_56 ) ;
if ( ! V_23 ) {
if ( ! ( V_16 & V_191 ) && F_140 () )
F_136 ( V_15 , V_16 , V_107 ) ;
return NULL ;
}
if ( F_51 ( V_23 -> V_192 ) )
V_98 = true ;
V_185 = ( 1 << V_15 -> V_56 ) ;
if ( V_15 -> V_16 & V_188 )
F_141 ( F_142 ( V_23 ) ,
V_193 , V_185 ) ;
else
F_141 ( F_142 ( V_23 ) ,
V_194 , V_185 ) ;
for ( V_45 = 0 ; V_45 < V_185 ; V_45 ++ ) {
F_143 ( V_23 + V_45 ) ;
if ( V_23 -> V_192 )
F_144 ( V_23 + V_45 ) ;
}
F_145 ( V_15 , V_15 -> V_56 ) ;
if ( V_195 && ! ( V_15 -> V_16 & V_196 ) ) {
F_146 ( V_23 , V_15 -> V_56 , V_16 , V_107 ) ;
if ( V_15 -> V_197 )
F_147 ( V_23 , V_185 ) ;
else
F_148 ( V_23 , V_185 ) ;
}
return F_149 ( V_23 ) ;
}
static void F_150 ( struct V_14 * V_15 , void * V_198 )
{
unsigned long V_45 = ( 1 << V_15 -> V_56 ) ;
struct V_23 * V_23 = F_62 ( V_198 ) ;
const unsigned long V_199 = V_45 ;
F_151 ( V_23 , V_15 -> V_56 ) ;
if ( V_15 -> V_16 & V_188 )
F_152 ( F_142 ( V_23 ) ,
V_193 , V_199 ) ;
else
F_152 ( F_142 ( V_23 ) ,
V_194 , V_199 ) ;
while ( V_45 -- ) {
F_9 ( ! F_16 ( V_23 ) ) ;
F_153 ( V_23 ) ;
F_154 ( V_23 ) ;
V_23 ++ ;
}
F_155 ( V_15 , V_15 -> V_56 ) ;
if ( V_200 -> V_201 )
V_200 -> V_201 -> V_202 += V_199 ;
F_156 ( ( unsigned long ) V_198 , V_15 -> V_56 ) ;
}
static void F_157 ( struct V_203 * V_204 )
{
struct V_205 * V_205 = (struct V_205 * ) V_204 ;
struct V_14 * V_15 = V_205 -> V_15 ;
F_150 ( V_15 , V_205 -> V_198 ) ;
if ( F_27 ( V_15 ) )
F_158 ( V_15 -> V_206 , V_205 ) ;
}
static void F_159 ( struct V_14 * V_15 , unsigned long * V_198 ,
unsigned long V_207 )
{
int V_19 = V_15 -> V_208 ;
V_198 = ( unsigned long * ) & ( ( char * ) V_198 ) [ F_7 ( V_15 ) ] ;
if ( V_19 < 5 * sizeof( unsigned long ) )
return;
* V_198 ++ = 0x12345678 ;
* V_198 ++ = V_207 ;
* V_198 ++ = F_32 () ;
V_19 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_209 = & V_207 ;
unsigned long V_210 ;
while ( ! F_160 ( V_209 ) ) {
V_210 = * V_209 ++ ;
if ( F_161 ( V_210 ) ) {
* V_198 ++ = V_210 ;
V_19 -= sizeof( unsigned long ) ;
if ( V_19 <= sizeof( unsigned long ) )
break;
}
}
}
* V_198 ++ = 0x87654321 ;
}
static void F_162 ( struct V_14 * V_15 , void * V_198 , unsigned char V_211 )
{
int V_19 = V_15 -> V_208 ;
V_198 = & ( ( char * ) V_198 ) [ F_7 ( V_15 ) ] ;
memset ( V_198 , V_211 , V_19 ) ;
* ( unsigned char * ) ( V_198 + V_19 - 1 ) = V_212 ;
}
static void F_163 ( char * V_213 , int V_30 , int V_94 )
{
int V_45 ;
unsigned char error = 0 ;
int V_214 = 0 ;
F_37 ( V_67 L_8 , V_30 ) ;
for ( V_45 = 0 ; V_45 < V_94 ; V_45 ++ ) {
if ( V_213 [ V_30 + V_45 ] != V_215 ) {
error = V_213 [ V_30 + V_45 ] ;
V_214 ++ ;
}
}
F_164 ( V_216 , L_9 , 0 , 16 , 1 ,
& V_213 [ V_30 ] , V_94 , 1 ) ;
if ( V_214 == 1 ) {
error ^= V_215 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_37 ( V_67 L_10
L_11 ) ;
#ifdef F_165
F_37 ( V_67 L_12
L_13 ) ;
#else
F_37 ( V_67 L_14 ) ;
#endif
}
}
}
static void F_166 ( struct V_14 * V_15 , void * V_1 , int V_217 )
{
int V_45 , V_19 ;
char * V_218 ;
if ( V_15 -> V_16 & V_17 ) {
F_37 ( V_67 L_15 ,
* F_8 ( V_15 , V_1 ) ,
* F_10 ( V_15 , V_1 ) ) ;
}
if ( V_15 -> V_16 & V_18 ) {
F_37 ( V_67 L_16 ,
* F_11 ( V_15 , V_1 ) ,
* F_11 ( V_15 , V_1 ) ) ;
}
V_218 = ( char * ) V_1 + F_7 ( V_15 ) ;
V_19 = V_15 -> V_208 ;
for ( V_45 = 0 ; V_45 < V_19 && V_217 ; V_45 += 16 , V_217 -- ) {
int V_94 ;
V_94 = 16 ;
if ( V_45 + V_94 > V_19 )
V_94 = V_19 - V_45 ;
F_163 ( V_218 , V_45 , V_94 ) ;
}
}
static void F_167 ( struct V_14 * V_15 , void * V_1 )
{
char * V_218 ;
int V_19 , V_45 ;
int V_217 = 0 ;
V_218 = ( char * ) V_1 + F_7 ( V_15 ) ;
V_19 = V_15 -> V_208 ;
for ( V_45 = 0 ; V_45 < V_19 ; V_45 ++ ) {
char exp = V_215 ;
if ( V_45 == V_19 - 1 )
exp = V_212 ;
if ( V_218 [ V_45 ] != exp ) {
int V_94 ;
if ( V_217 == 0 ) {
F_37 ( V_67
L_17 ,
F_168 () , V_15 -> V_68 , V_218 , V_19 ) ;
F_166 ( V_15 , V_1 , 0 ) ;
}
V_45 = ( V_45 / 16 ) * 16 ;
V_94 = 16 ;
if ( V_45 + V_94 > V_19 )
V_94 = V_19 - V_45 ;
F_163 ( V_218 , V_45 , V_94 ) ;
V_45 += 16 ;
V_217 ++ ;
if ( V_217 > 5 )
break;
}
}
if ( V_217 != 0 ) {
struct V_25 * V_96 = F_14 ( V_1 ) ;
unsigned int V_219 ;
V_219 = F_18 ( V_15 , V_96 , V_1 ) ;
if ( V_219 ) {
V_1 = F_17 ( V_15 , V_96 , V_219 - 1 ) ;
V_218 = ( char * ) V_1 + F_7 ( V_15 ) ;
F_37 ( V_67 L_18 ,
V_218 , V_19 ) ;
F_166 ( V_15 , V_1 , 2 ) ;
}
if ( V_219 + 1 < V_15 -> V_59 ) {
V_1 = F_17 ( V_15 , V_96 , V_219 + 1 ) ;
V_218 = ( char * ) V_1 + F_7 ( V_15 ) ;
F_37 ( V_67 L_19 ,
V_218 , V_19 ) ;
F_166 ( V_15 , V_1 , 2 ) ;
}
}
}
static void F_169 ( struct V_14 * V_15 , struct V_25 * V_96 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_15 -> V_59 ; V_45 ++ ) {
void * V_1 = F_17 ( V_15 , V_96 , V_45 ) ;
if ( V_15 -> V_16 & V_220 ) {
#ifdef F_170
if ( V_15 -> V_19 % V_62 == 0 &&
F_27 ( V_15 ) )
F_171 ( F_62 ( V_1 ) ,
V_15 -> V_19 / V_62 , 1 ) ;
else
F_167 ( V_15 , V_1 ) ;
#else
F_167 ( V_15 , V_1 ) ;
#endif
}
if ( V_15 -> V_16 & V_17 ) {
if ( * F_8 ( V_15 , V_1 ) != V_221 )
F_172 ( V_15 , L_20
L_21 ) ;
if ( * F_10 ( V_15 , V_1 ) != V_221 )
F_172 ( V_15 , L_22
L_21 ) ;
}
}
}
static void F_169 ( struct V_14 * V_15 , struct V_25 * V_96 )
{
}
static void F_173 ( struct V_14 * V_15 , struct V_25 * V_96 )
{
void * V_198 = V_96 -> V_29 - V_96 -> V_222 ;
F_169 ( V_15 , V_96 ) ;
if ( F_51 ( V_15 -> V_16 & V_121 ) ) {
struct V_205 * V_205 ;
V_205 = (struct V_205 * ) V_96 ;
V_205 -> V_15 = V_15 ;
V_205 -> V_198 = V_198 ;
F_174 ( & V_205 -> V_204 , F_157 ) ;
} else {
F_150 ( V_15 , V_198 ) ;
if ( F_27 ( V_15 ) )
F_158 ( V_15 -> V_206 , V_96 ) ;
}
}
static T_2 F_175 ( struct V_14 * V_15 ,
T_2 V_19 , T_2 V_54 , unsigned long V_16 )
{
unsigned long V_223 ;
T_2 V_58 = 0 ;
int V_56 ;
for ( V_56 = 0 ; V_56 <= V_224 ; V_56 ++ ) {
unsigned int V_59 ;
T_2 V_225 ;
F_35 ( V_56 , V_19 , V_54 , V_16 , & V_225 , & V_59 ) ;
if ( ! V_59 )
continue;
if ( V_16 & V_63 ) {
V_223 = V_19 - sizeof( struct V_25 ) ;
V_223 /= sizeof( V_55 ) ;
if ( V_59 > V_223 )
break;
}
V_15 -> V_59 = V_59 ;
V_15 -> V_56 = V_56 ;
V_58 = V_225 ;
if ( V_16 & V_188 )
break;
if ( V_56 >= V_74 )
break;
if ( V_58 * 8 <= ( V_62 << V_56 ) )
break;
}
return V_58 ;
}
static int T_7 F_176 ( struct V_14 * V_15 , T_4 V_90 )
{
if ( V_46 >= V_175 )
return F_130 ( V_15 , V_90 ) ;
if ( V_46 == V_226 ) {
V_15 -> V_52 [ F_32 () ] = & V_172 . V_27 ;
V_46 = V_227 ;
} else if ( V_46 == V_227 ) {
V_15 -> V_52 [ F_32 () ] = & V_172 . V_27 ;
F_118 ( V_15 , V_173 ) ;
if ( V_167 == V_169 )
V_46 = V_228 ;
else
V_46 = V_229 ;
} else {
V_15 -> V_52 [ F_32 () ] =
F_127 ( sizeof( struct V_171 ) , V_90 ) ;
if ( V_46 == V_229 ) {
F_118 ( V_15 , V_174 ) ;
V_46 = V_228 ;
} else {
int V_40 ;
F_25 (node) {
V_15 -> V_40 [ V_40 ] =
F_59 ( sizeof( struct V_3 ) ,
V_90 , V_40 ) ;
F_9 ( ! V_15 -> V_40 [ V_40 ] ) ;
F_4 ( V_15 -> V_40 [ V_40 ] ) ;
}
}
}
V_15 -> V_40 [ F_65 () ] -> V_111 =
V_112 + V_113 +
( ( unsigned long ) V_15 ) % V_113 ;
F_31 ( V_15 ) -> V_93 = 0 ;
F_31 ( V_15 ) -> V_94 = V_230 ;
F_31 ( V_15 ) -> V_89 = 1 ;
F_31 ( V_15 ) -> V_95 = 0 ;
V_15 -> V_89 = 1 ;
V_15 -> V_94 = V_230 ;
return 0 ;
}
int
F_177 ( struct V_14 * V_15 , unsigned long V_16 )
{
T_2 V_58 , V_61 , V_231 ;
T_4 V_90 ;
int V_118 ;
T_2 V_19 = V_15 -> V_19 ;
#if V_232
#if V_233
if ( V_19 < 4096 || F_178 ( V_19 - 1 ) == F_178 ( V_19 - 1 + V_20 +
2 * sizeof( unsigned long long ) ) )
V_16 |= V_17 | V_18 ;
if ( ! ( V_16 & V_121 ) )
V_16 |= V_220 ;
#endif
if ( V_16 & V_121 )
F_9 ( V_16 & V_220 ) ;
#endif
if ( V_19 & ( V_21 - 1 ) ) {
V_19 += ( V_21 - 1 ) ;
V_19 &= ~ ( V_21 - 1 ) ;
}
if ( V_16 & V_18 )
V_231 = V_21 ;
if ( V_16 & V_17 ) {
V_231 = V_20 ;
V_19 += V_20 - 1 ;
V_19 &= ~ ( V_20 - 1 ) ;
}
if ( V_231 < V_15 -> V_54 ) {
V_231 = V_15 -> V_54 ;
}
if ( V_231 > F_179 (unsigned long long) )
V_16 &= ~ ( V_17 | V_18 ) ;
V_15 -> V_54 = V_231 ;
if ( F_180 () )
V_90 = V_109 ;
else
V_90 = V_155 ;
F_119 ( V_15 ) ;
#if V_232
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
#if V_233 && F_181 ( F_170 )
if ( V_19 >= F_126 ( V_169 + 1 )
&& V_15 -> V_208 > F_182 ()
&& F_34 ( V_19 , V_15 -> V_54 ) < V_62 ) {
V_15 -> F_7 += V_62 - F_34 ( V_19 , V_15 -> V_54 ) ;
V_19 = V_62 ;
}
#endif
#endif
if ( ( V_19 >= ( V_62 >> 3 ) ) && ! V_170 &&
! ( V_16 & V_234 ) )
V_16 |= V_63 ;
V_19 = F_34 ( V_19 , V_15 -> V_54 ) ;
V_58 = F_175 ( V_15 , V_19 , V_15 -> V_54 , V_16 ) ;
if ( ! V_15 -> V_59 )
return - V_235 ;
V_61 = F_34 ( V_15 -> V_59 * sizeof( V_55 )
+ sizeof( struct V_25 ) , V_15 -> V_54 ) ;
if ( V_16 & V_63 && V_58 >= V_61 ) {
V_16 &= ~ V_63 ;
V_58 -= V_61 ;
}
if ( V_16 & V_63 ) {
V_61 =
V_15 -> V_59 * sizeof( V_55 ) + sizeof( struct V_25 ) ;
#ifdef F_183
if ( V_19 % V_62 == 0 && V_16 & V_220 )
V_16 &= ~ ( V_17 | V_18 ) ;
#endif
}
V_15 -> V_236 = F_182 () ;
if ( V_15 -> V_236 < V_15 -> V_54 )
V_15 -> V_236 = V_15 -> V_54 ;
V_15 -> V_237 = V_58 / V_15 -> V_236 ;
V_15 -> V_61 = V_61 ;
V_15 -> V_16 = V_16 ;
V_15 -> V_187 = 0 ;
if ( V_238 && ( V_16 & V_239 ) )
V_15 -> V_187 |= V_240 ;
V_15 -> V_19 = V_19 ;
V_15 -> V_31 = F_184 ( V_19 ) ;
if ( V_16 & V_63 ) {
V_15 -> V_206 = F_185 ( V_61 , 0u ) ;
F_9 ( F_186 ( V_15 -> V_206 ) ) ;
}
V_118 = F_176 ( V_15 , V_90 ) ;
if ( V_118 ) {
F_187 ( V_15 ) ;
return V_118 ;
}
if ( V_16 & V_120 ) {
F_188 ( V_16 & V_121 ) ;
F_24 ( V_15 ) ;
} else if ( ! F_27 ( V_15 ) && ! ( V_16 & V_121 ) )
F_29 ( V_15 ) ;
return 0 ;
}
static void F_189 ( void )
{
F_9 ( ! F_190 () ) ;
}
static void F_191 ( void )
{
F_9 ( F_190 () ) ;
}
static void F_192 ( struct V_14 * V_15 )
{
#ifdef F_193
F_189 () ;
F_194 ( & V_15 -> V_40 [ F_65 () ] -> V_11 ) ;
#endif
}
static void F_195 ( struct V_14 * V_15 , int V_40 )
{
#ifdef F_193
F_189 () ;
F_194 ( & V_15 -> V_40 [ V_40 ] -> V_11 ) ;
#endif
}
static void F_196 ( void * V_142 )
{
struct V_14 * V_15 = V_142 ;
struct V_36 * V_97 ;
int V_40 = F_65 () ;
F_189 () ;
V_97 = F_31 ( V_15 ) ;
F_88 ( & V_15 -> V_40 [ V_40 ] -> V_11 ) ;
F_89 ( V_15 , V_97 -> V_101 , V_97 -> V_93 , V_40 ) ;
F_90 ( & V_15 -> V_40 [ V_40 ] -> V_11 ) ;
V_97 -> V_93 = 0 ;
}
static void F_197 ( struct V_14 * V_15 )
{
struct V_3 * V_38 ;
int V_40 ;
F_198 ( F_196 , V_15 , 1 ) ;
F_191 () ;
F_25 (node) {
V_38 = V_15 -> V_40 [ V_40 ] ;
if ( V_38 && V_38 -> V_9 )
F_94 ( V_15 , V_38 -> V_9 ) ;
}
F_25 (node) {
V_38 = V_15 -> V_40 [ V_40 ] ;
if ( V_38 )
F_199 ( V_15 , V_38 , V_38 -> V_8 , 1 , V_40 ) ;
}
}
static int F_105 ( struct V_14 * V_27 ,
struct V_3 * V_38 , int V_241 )
{
struct V_242 * V_243 ;
int V_199 ;
struct V_25 * V_96 ;
V_199 = 0 ;
while ( V_199 < V_241 && ! F_71 ( & V_38 -> V_7 ) ) {
F_99 ( & V_38 -> V_11 ) ;
V_243 = V_38 -> V_7 . V_244 ;
if ( V_243 == & V_38 -> V_7 ) {
F_93 ( & V_38 -> V_11 ) ;
goto V_99;
}
V_96 = F_200 ( V_243 , struct V_25 , V_153 ) ;
#if V_232
F_9 ( V_96 -> V_184 ) ;
#endif
F_201 ( & V_96 -> V_153 ) ;
V_38 -> V_12 -= V_27 -> V_59 ;
F_93 ( & V_38 -> V_11 ) ;
F_173 ( V_27 , V_96 ) ;
V_199 ++ ;
}
V_99:
return V_199 ;
}
static int F_202 ( struct V_14 * V_15 )
{
int V_139 = 0 , V_45 = 0 ;
struct V_3 * V_38 ;
F_197 ( V_15 ) ;
F_191 () ;
F_25 (i) {
V_38 = V_15 -> V_40 [ V_45 ] ;
if ( ! V_38 )
continue;
F_105 ( V_15 , V_38 , F_101 ( V_15 , V_38 ) ) ;
V_139 += ! F_71 ( & V_38 -> V_5 ) ||
! F_71 ( & V_38 -> V_6 ) ;
}
return ( V_139 ? 1 : 0 ) ;
}
int F_203 ( struct V_14 * V_15 )
{
int V_139 ;
F_9 ( ! V_15 || F_204 () ) ;
F_205 () ;
F_109 ( & V_128 ) ;
V_139 = F_202 ( V_15 ) ;
F_110 ( & V_128 ) ;
F_206 () ;
return V_139 ;
}
int F_187 ( struct V_14 * V_15 )
{
int V_45 ;
struct V_3 * V_38 ;
int V_245 = F_202 ( V_15 ) ;
if ( V_245 )
return V_245 ;
F_135 (i)
F_86 ( V_15 -> V_52 [ V_45 ] ) ;
F_25 (i) {
V_38 = V_15 -> V_40 [ V_45 ] ;
if ( V_38 ) {
F_86 ( V_38 -> V_8 ) ;
F_80 ( V_38 -> V_9 ) ;
F_86 ( V_38 ) ;
}
}
return 0 ;
}
static struct V_25 * F_207 ( struct V_14 * V_15 , void * V_1 ,
int V_236 , T_4 V_246 ,
int V_107 )
{
struct V_25 * V_96 ;
if ( F_27 ( V_15 ) ) {
V_96 = F_208 ( V_15 -> V_206 ,
V_246 , V_107 ) ;
F_209 ( & V_96 -> V_153 , sizeof( struct V_242 ) ,
V_246 ) ;
if ( ! V_96 )
return NULL ;
} else {
V_96 = V_1 + V_236 ;
V_236 += V_15 -> V_61 ;
}
V_96 -> V_184 = 0 ;
V_96 -> V_222 = V_236 ;
V_96 -> V_29 = V_1 + V_236 ;
V_96 -> V_107 = V_107 ;
V_96 -> free = 0 ;
return V_96 ;
}
static inline V_55 * F_210 ( struct V_25 * V_96 )
{
return ( V_55 * ) ( V_96 + 1 ) ;
}
static void F_211 ( struct V_14 * V_15 ,
struct V_25 * V_96 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_15 -> V_59 ; V_45 ++ ) {
void * V_1 = F_17 ( V_15 , V_96 , V_45 ) ;
#if V_232
if ( V_15 -> V_16 & V_220 )
F_162 ( V_15 , V_1 , V_215 ) ;
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = NULL ;
if ( V_15 -> V_16 & V_17 ) {
* F_8 ( V_15 , V_1 ) = V_221 ;
* F_10 ( V_15 , V_1 ) = V_221 ;
}
if ( V_15 -> V_197 && ! ( V_15 -> V_16 & V_220 ) )
V_15 -> V_197 ( V_1 + F_7 ( V_15 ) ) ;
if ( V_15 -> V_16 & V_17 ) {
if ( * F_10 ( V_15 , V_1 ) != V_221 )
F_172 ( V_15 , L_23
L_24 ) ;
if ( * F_8 ( V_15 , V_1 ) != V_221 )
F_172 ( V_15 , L_23
L_25 ) ;
}
if ( ( V_15 -> V_19 % V_62 ) == 0 &&
F_27 ( V_15 ) && V_15 -> V_16 & V_220 )
F_171 ( F_62 ( V_1 ) ,
V_15 -> V_19 / V_62 , 0 ) ;
#else
if ( V_15 -> V_197 )
V_15 -> V_197 ( V_1 ) ;
#endif
F_210 ( V_96 ) [ V_45 ] = V_45 + 1 ;
}
F_210 ( V_96 ) [ V_45 - 1 ] = V_247 ;
}
static void F_212 ( struct V_14 * V_15 , T_4 V_16 )
{
if ( V_238 ) {
if ( V_16 & V_240 )
F_9 ( ! ( V_15 -> V_187 & V_240 ) ) ;
else
F_9 ( V_15 -> V_187 & V_240 ) ;
}
}
static void * F_213 ( struct V_14 * V_15 , struct V_25 * V_96 ,
int V_107 )
{
void * V_1 = F_17 ( V_15 , V_96 , V_96 -> free ) ;
V_55 V_248 ;
V_96 -> V_184 ++ ;
V_248 = F_210 ( V_96 ) [ V_96 -> free ] ;
#if V_232
F_210 ( V_96 ) [ V_96 -> free ] = V_249 ;
F_214 ( V_96 -> V_107 != V_107 ) ;
#endif
V_96 -> free = V_248 ;
return V_1 ;
}
static void F_215 ( struct V_14 * V_15 , struct V_25 * V_96 ,
void * V_1 , int V_107 )
{
unsigned int V_219 = F_18 ( V_15 , V_96 , V_1 ) ;
#if V_232
F_214 ( V_96 -> V_107 != V_107 ) ;
if ( F_210 ( V_96 ) [ V_219 ] + 1 <= V_64 + 1 ) {
F_37 ( V_67 L_26
L_27 , V_15 -> V_68 , V_1 ) ;
F_131 () ;
}
#endif
F_210 ( V_96 ) [ V_219 ] = V_96 -> free ;
V_96 -> free = V_219 ;
V_96 -> V_184 -- ;
}
static void F_216 ( struct V_14 * V_27 , struct V_25 * V_25 ,
void * V_198 )
{
int V_185 ;
struct V_23 * V_23 ;
V_23 = F_62 ( V_198 ) ;
V_185 = 1 ;
if ( F_95 ( ! F_217 ( V_23 ) ) )
V_185 <<= V_27 -> V_56 ;
do {
V_23 -> V_24 = V_27 ;
V_23 -> V_26 = V_25 ;
V_23 ++ ;
} while ( -- V_185 );
}
static int F_218 ( struct V_14 * V_15 ,
T_4 V_16 , int V_107 , void * V_1 )
{
struct V_25 * V_96 ;
T_2 V_30 ;
T_4 V_246 ;
struct V_3 * V_38 ;
F_9 ( V_16 & V_250 ) ;
V_246 = V_16 & ( V_251 | V_252 ) ;
F_189 () ;
V_38 = V_15 -> V_40 [ V_107 ] ;
F_88 ( & V_38 -> V_11 ) ;
V_30 = V_38 -> V_10 ;
V_38 -> V_10 ++ ;
if ( V_38 -> V_10 >= V_15 -> V_237 )
V_38 -> V_10 = 0 ;
F_90 ( & V_38 -> V_11 ) ;
V_30 *= V_15 -> V_236 ;
if ( V_246 & V_253 )
F_219 () ;
F_212 ( V_15 , V_16 ) ;
if ( ! V_1 )
V_1 = F_137 ( V_15 , V_246 , V_107 ) ;
if ( ! V_1 )
goto V_254;
V_96 = F_207 ( V_15 , V_1 , V_30 ,
V_246 & ~ V_251 , V_107 ) ;
if ( ! V_96 )
goto V_255;
F_216 ( V_15 , V_96 , V_1 ) ;
F_211 ( V_15 , V_96 ) ;
if ( V_246 & V_253 )
F_220 () ;
F_189 () ;
F_88 ( & V_38 -> V_11 ) ;
F_221 ( & V_96 -> V_153 , & ( V_38 -> V_7 ) ) ;
F_222 ( V_15 ) ;
V_38 -> V_12 += V_15 -> V_59 ;
F_90 ( & V_38 -> V_11 ) ;
return 1 ;
V_255:
F_150 ( V_15 , V_1 ) ;
V_254:
if ( V_246 & V_253 )
F_220 () ;
return 0 ;
}
static void F_223 ( const void * V_1 )
{
if ( ! F_224 ( V_1 ) ) {
F_37 ( V_67 L_28 ,
( unsigned long ) V_1 ) ;
F_131 () ;
}
}
static inline void F_225 ( struct V_14 * V_27 , void * V_22 )
{
unsigned long long V_256 , V_257 ;
V_256 = * F_8 ( V_27 , V_22 ) ;
V_257 = * F_10 ( V_27 , V_22 ) ;
if ( V_256 == V_258 && V_257 == V_258 )
return;
if ( V_256 == V_221 && V_257 == V_221 )
F_172 ( V_27 , L_29 ) ;
else
F_172 ( V_27 , L_30 ) ;
F_37 ( V_67 L_31 ,
V_22 , V_256 , V_257 ) ;
}
static void * F_226 ( struct V_14 * V_15 , void * V_1 ,
unsigned long V_207 )
{
struct V_23 * V_23 ;
unsigned int V_219 ;
struct V_25 * V_96 ;
F_9 ( F_12 ( V_1 ) != V_15 ) ;
V_1 -= F_7 ( V_15 ) ;
F_223 ( V_1 ) ;
V_23 = F_13 ( V_1 ) ;
V_96 = V_23 -> V_26 ;
if ( V_15 -> V_16 & V_17 ) {
F_225 ( V_15 , V_1 ) ;
* F_8 ( V_15 , V_1 ) = V_221 ;
* F_10 ( V_15 , V_1 ) = V_221 ;
}
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = ( void * ) V_207 ;
V_219 = F_18 ( V_15 , V_96 , V_1 ) ;
F_9 ( V_219 >= V_15 -> V_59 ) ;
F_9 ( V_1 != F_17 ( V_15 , V_96 , V_219 ) ) ;
#ifdef F_227
F_210 ( V_96 ) [ V_219 ] = V_249 ;
#endif
if ( V_15 -> V_16 & V_220 ) {
#ifdef F_170
if ( ( V_15 -> V_19 % V_62 ) == 0 && F_27 ( V_15 ) ) {
F_159 ( V_15 , V_1 , V_207 ) ;
F_171 ( F_62 ( V_1 ) ,
V_15 -> V_19 / V_62 , 0 ) ;
} else {
F_162 ( V_15 , V_1 , V_215 ) ;
}
#else
F_162 ( V_15 , V_1 , V_215 ) ;
#endif
}
return V_1 ;
}
static void F_228 ( struct V_14 * V_15 , struct V_25 * V_96 )
{
V_55 V_45 ;
int V_88 = 0 ;
for ( V_45 = V_96 -> free ; V_45 != V_247 ; V_45 = F_210 ( V_96 ) [ V_45 ] ) {
V_88 ++ ;
if ( V_88 > V_15 -> V_59 || V_45 >= V_15 -> V_59 )
goto V_119;
}
if ( V_88 != V_15 -> V_59 - V_96 -> V_184 ) {
V_119:
F_37 ( V_67 L_32
L_33 ,
V_15 -> V_68 , V_15 -> V_59 , V_96 , V_96 -> V_184 ,
F_168 () ) ;
F_164 ( V_67 , L_9 , V_259 , 16 , 1 , V_96 ,
sizeof( * V_96 ) + V_15 -> V_59 * sizeof( V_55 ) ,
1 ) ;
F_131 () ;
}
}
static void * F_229 ( struct V_14 * V_15 , T_4 V_16 ,
bool V_100 )
{
int V_89 ;
struct V_3 * V_38 ;
struct V_36 * V_97 ;
int V_40 ;
F_189 () ;
V_40 = F_65 () ;
if ( F_51 ( V_100 ) )
goto V_260;
V_261:
V_97 = F_31 ( V_15 ) ;
V_89 = V_97 -> V_89 ;
if ( ! V_97 -> V_95 && V_89 > V_262 ) {
V_89 = V_262 ;
}
V_38 = V_15 -> V_40 [ V_40 ] ;
F_9 ( V_97 -> V_93 > 0 || ! V_38 ) ;
F_88 ( & V_38 -> V_11 ) ;
if ( V_38 -> V_8 && F_77 ( V_97 , V_38 -> V_8 , V_89 ) ) {
V_38 -> V_8 -> V_95 = 1 ;
goto V_263;
}
while ( V_89 > 0 ) {
struct V_242 * V_101 ;
struct V_25 * V_96 ;
V_101 = V_38 -> V_6 . V_248 ;
if ( V_101 == & V_38 -> V_6 ) {
V_38 -> V_13 = 1 ;
V_101 = V_38 -> V_7 . V_248 ;
if ( V_101 == & V_38 -> V_7 )
goto V_264;
}
V_96 = F_200 ( V_101 , struct V_25 , V_153 ) ;
F_228 ( V_15 , V_96 ) ;
F_192 ( V_15 ) ;
F_9 ( V_96 -> V_184 >= V_15 -> V_59 ) ;
while ( V_96 -> V_184 < V_15 -> V_59 && V_89 -- ) {
F_230 ( V_15 ) ;
F_231 ( V_15 ) ;
F_232 ( V_15 ) ;
F_76 ( V_15 , V_97 , F_213 ( V_15 , V_96 ,
V_40 ) ) ;
}
F_228 ( V_15 , V_96 ) ;
F_201 ( & V_96 -> V_153 ) ;
if ( V_96 -> free == V_247 )
F_124 ( & V_96 -> V_153 , & V_38 -> V_5 ) ;
else
F_124 ( & V_96 -> V_153 , & V_38 -> V_6 ) ;
}
V_264:
V_38 -> V_12 -= V_97 -> V_93 ;
V_263:
F_90 ( & V_38 -> V_11 ) ;
if ( F_51 ( ! V_97 -> V_93 ) ) {
int V_265 ;
V_260:
V_265 = F_218 ( V_15 , V_16 | V_266 , V_40 , NULL ) ;
V_97 = F_31 ( V_15 ) ;
V_40 = F_65 () ;
if ( ! V_265 && ( V_97 -> V_93 == 0 || V_100 ) )
return NULL ;
if ( ! V_97 -> V_93 )
goto V_261;
}
V_97 -> V_95 = 1 ;
return F_73 ( V_15 , V_97 , V_16 , V_100 ) ;
}
static inline void F_233 ( struct V_14 * V_15 ,
T_4 V_16 )
{
F_234 ( V_16 & V_253 ) ;
#if V_232
F_212 ( V_15 , V_16 ) ;
#endif
}
static void * F_235 ( struct V_14 * V_15 ,
T_4 V_16 , void * V_1 , unsigned long V_207 )
{
if ( ! V_1 )
return V_1 ;
if ( V_15 -> V_16 & V_220 ) {
#ifdef F_170
if ( ( V_15 -> V_19 % V_62 ) == 0 && F_27 ( V_15 ) )
F_171 ( F_62 ( V_1 ) ,
V_15 -> V_19 / V_62 , 1 ) ;
else
F_167 ( V_15 , V_1 ) ;
#else
F_167 ( V_15 , V_1 ) ;
#endif
F_162 ( V_15 , V_1 , V_267 ) ;
}
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = ( void * ) V_207 ;
if ( V_15 -> V_16 & V_17 ) {
if ( * F_8 ( V_15 , V_1 ) != V_221 ||
* F_10 ( V_15 , V_1 ) != V_221 ) {
F_172 ( V_15 , L_34
L_35 ) ;
F_37 ( V_67
L_36 ,
V_1 , * F_8 ( V_15 , V_1 ) ,
* F_10 ( V_15 , V_1 ) ) ;
}
* F_8 ( V_15 , V_1 ) = V_258 ;
* F_10 ( V_15 , V_1 ) = V_258 ;
}
#ifdef F_227
{
struct V_25 * V_96 ;
unsigned V_219 ;
V_96 = F_13 ( V_1 ) -> V_26 ;
V_219 = ( unsigned ) ( V_1 - V_96 -> V_29 ) / V_15 -> V_19 ;
F_210 ( V_96 ) [ V_219 ] = V_268 ;
}
#endif
V_1 += F_7 ( V_15 ) ;
if ( V_15 -> V_197 && V_15 -> V_16 & V_220 )
V_15 -> V_197 ( V_1 ) ;
if ( V_269 &&
( ( unsigned long ) V_1 & ( V_269 - 1 ) ) ) {
F_37 ( V_67 L_37 ,
V_1 , ( int ) V_269 ) ;
}
return V_1 ;
}
static bool F_236 ( struct V_14 * V_15 , T_4 V_16 )
{
if ( V_15 == V_14 )
return false ;
return F_237 ( V_15 -> V_208 , V_16 , V_15 -> V_16 ) ;
}
static inline void * F_238 ( struct V_14 * V_15 , T_4 V_16 )
{
void * V_1 ;
struct V_36 * V_97 ;
bool V_100 = false ;
F_189 () ;
V_97 = F_31 ( V_15 ) ;
if ( F_95 ( V_97 -> V_93 ) ) {
V_97 -> V_95 = 1 ;
V_1 = F_73 ( V_15 , V_97 , V_16 , false ) ;
if ( V_1 ) {
F_239 ( V_15 ) ;
goto V_99;
}
V_100 = true ;
}
F_240 ( V_15 ) ;
V_1 = F_229 ( V_15 , V_16 , V_100 ) ;
V_97 = F_31 ( V_15 ) ;
V_99:
if ( V_1 )
F_241 ( & V_97 -> V_101 [ V_97 -> V_93 ] ) ;
return V_1 ;
}
static void * F_82 ( struct V_14 * V_15 , T_4 V_16 )
{
int V_270 , V_271 ;
if ( F_204 () || ( V_16 & V_272 ) )
return NULL ;
V_270 = V_271 = F_65 () ;
if ( F_242 () && ( V_15 -> V_16 & V_273 ) )
V_270 = F_243 () ;
else if ( V_200 -> V_274 )
V_270 = F_244 () ;
if ( V_270 != V_271 )
return F_83 ( V_15 , V_16 , V_270 ) ;
return NULL ;
}
static void * F_245 ( struct V_14 * V_27 , T_4 V_16 )
{
struct V_275 * V_275 ;
T_4 V_246 ;
struct V_276 * V_277 ;
struct V_278 * V_278 ;
enum V_279 V_280 = F_246 ( V_16 ) ;
void * V_22 = NULL ;
int V_145 ;
unsigned int V_281 ;
if ( V_16 & V_272 )
return NULL ;
V_246 = V_16 & ( V_251 | V_252 ) ;
V_282:
V_281 = F_247 () ;
V_275 = F_248 ( F_244 () , V_16 ) ;
V_261:
F_249 (zone, z, zonelist, high_zoneidx) {
V_145 = F_250 ( V_278 ) ;
if ( F_251 ( V_278 , V_16 ) &&
V_27 -> V_40 [ V_145 ] &&
V_27 -> V_40 [ V_145 ] -> V_12 ) {
V_22 = F_83 ( V_27 ,
V_16 | V_266 , V_145 ) ;
if ( V_22 )
break;
}
}
if ( ! V_22 ) {
if ( V_246 & V_253 )
F_219 () ;
F_212 ( V_27 , V_16 ) ;
V_22 = F_137 ( V_27 , V_246 , F_65 () ) ;
if ( V_246 & V_253 )
F_220 () ;
if ( V_22 ) {
V_145 = F_252 ( F_62 ( V_22 ) ) ;
if ( F_218 ( V_27 , V_16 , V_145 , V_22 ) ) {
V_22 = F_83 ( V_27 ,
V_16 | V_266 , V_145 ) ;
if ( ! V_22 )
goto V_261;
} else {
V_22 = NULL ;
}
}
}
if ( F_51 ( ! F_253 ( V_281 ) && ! V_22 ) )
goto V_282;
return V_22 ;
}
static void * F_83 ( struct V_14 * V_15 , T_4 V_16 ,
int V_107 )
{
struct V_242 * V_101 ;
struct V_25 * V_96 ;
struct V_3 * V_38 ;
void * V_22 ;
int V_265 ;
F_15 ( V_107 > F_254 () ) ;
V_38 = V_15 -> V_40 [ V_107 ] ;
F_9 ( ! V_38 ) ;
V_261:
F_189 () ;
F_88 ( & V_38 -> V_11 ) ;
V_101 = V_38 -> V_6 . V_248 ;
if ( V_101 == & V_38 -> V_6 ) {
V_38 -> V_13 = 1 ;
V_101 = V_38 -> V_7 . V_248 ;
if ( V_101 == & V_38 -> V_7 )
goto V_264;
}
V_96 = F_200 ( V_101 , struct V_25 , V_153 ) ;
F_195 ( V_15 , V_107 ) ;
F_228 ( V_15 , V_96 ) ;
F_255 ( V_15 ) ;
F_231 ( V_15 ) ;
F_232 ( V_15 ) ;
F_9 ( V_96 -> V_184 == V_15 -> V_59 ) ;
V_22 = F_213 ( V_15 , V_96 , V_107 ) ;
F_228 ( V_15 , V_96 ) ;
V_38 -> V_12 -- ;
F_201 ( & V_96 -> V_153 ) ;
if ( V_96 -> free == V_247 )
F_124 ( & V_96 -> V_153 , & V_38 -> V_5 ) ;
else
F_124 ( & V_96 -> V_153 , & V_38 -> V_6 ) ;
F_90 ( & V_38 -> V_11 ) ;
goto V_283;
V_264:
F_90 ( & V_38 -> V_11 ) ;
V_265 = F_218 ( V_15 , V_16 | V_266 , V_107 , NULL ) ;
if ( V_265 )
goto V_261;
return F_245 ( V_15 , V_16 ) ;
V_283:
return V_22 ;
}
static T_8 void *
F_256 ( struct V_14 * V_15 , T_4 V_16 , int V_107 ,
unsigned long V_207 )
{
unsigned long V_284 ;
void * V_154 ;
int F_244 = F_65 () ;
V_16 &= V_285 ;
F_257 ( V_16 ) ;
if ( F_236 ( V_15 , V_16 ) )
return NULL ;
V_15 = F_258 ( V_15 , V_16 ) ;
F_233 ( V_15 , V_16 ) ;
F_259 ( V_284 ) ;
if ( V_107 == V_286 )
V_107 = F_244 ;
if ( F_51 ( ! V_15 -> V_40 [ V_107 ] ) ) {
V_154 = F_245 ( V_15 , V_16 ) ;
goto V_99;
}
if ( V_107 == F_244 ) {
V_154 = F_238 ( V_15 , V_16 ) ;
if ( V_154 )
goto V_99;
}
V_154 = F_83 ( V_15 , V_16 , V_107 ) ;
V_99:
F_260 ( V_284 ) ;
V_154 = F_235 ( V_15 , V_16 , V_154 , V_207 ) ;
F_261 ( V_154 , V_15 -> V_208 , 1 , V_15 -> V_16 ,
V_16 ) ;
if ( F_95 ( V_154 ) )
F_262 ( V_15 , V_16 , V_154 , V_15 -> V_208 ) ;
if ( F_51 ( ( V_16 & V_287 ) && V_154 ) )
memset ( V_154 , 0 , V_15 -> V_208 ) ;
return V_154 ;
}
static T_8 void *
F_263 ( struct V_14 * V_27 , T_4 V_16 )
{
void * V_1 ;
if ( F_51 ( V_200 -> V_16 & ( V_288 | V_289 ) ) ) {
V_1 = F_82 ( V_27 , V_16 ) ;
if ( V_1 )
goto V_99;
}
V_1 = F_238 ( V_27 , V_16 ) ;
if ( ! V_1 )
V_1 = F_83 ( V_27 , V_16 , F_65 () ) ;
V_99:
return V_1 ;
}
static T_8 void *
F_263 ( struct V_14 * V_15 , T_4 V_16 )
{
return F_238 ( V_15 , V_16 ) ;
}
static T_8 void *
F_264 ( struct V_14 * V_15 , T_4 V_16 , unsigned long V_207 )
{
unsigned long V_284 ;
void * V_1 ;
V_16 &= V_285 ;
F_257 ( V_16 ) ;
if ( F_236 ( V_15 , V_16 ) )
return NULL ;
V_15 = F_258 ( V_15 , V_16 ) ;
F_233 ( V_15 , V_16 ) ;
F_259 ( V_284 ) ;
V_1 = F_263 ( V_15 , V_16 ) ;
F_260 ( V_284 ) ;
V_1 = F_235 ( V_15 , V_16 , V_1 , V_207 ) ;
F_261 ( V_1 , V_15 -> V_208 , 1 , V_15 -> V_16 ,
V_16 ) ;
F_265 ( V_1 ) ;
if ( F_95 ( V_1 ) )
F_262 ( V_15 , V_16 , V_1 , V_15 -> V_208 ) ;
if ( F_51 ( ( V_16 & V_287 ) && V_1 ) )
memset ( V_1 , 0 , V_15 -> V_208 ) ;
return V_1 ;
}
static void F_89 ( struct V_14 * V_15 , void * * V_290 , int V_291 ,
int V_40 )
{
int V_45 ;
struct V_3 * V_38 ;
for ( V_45 = 0 ; V_45 < V_291 ; V_45 ++ ) {
void * V_1 ;
struct V_25 * V_96 ;
F_3 ( & V_290 [ V_45 ] ) ;
V_1 = V_290 [ V_45 ] ;
V_96 = F_14 ( V_1 ) ;
V_38 = V_15 -> V_40 [ V_40 ] ;
F_201 ( & V_96 -> V_153 ) ;
F_195 ( V_15 , V_40 ) ;
F_228 ( V_15 , V_96 ) ;
F_215 ( V_15 , V_96 , V_1 , V_40 ) ;
F_266 ( V_15 ) ;
V_38 -> V_12 ++ ;
F_228 ( V_15 , V_96 ) ;
if ( V_96 -> V_184 == 0 ) {
if ( V_38 -> V_12 > V_38 -> V_114 ) {
V_38 -> V_12 -= V_15 -> V_59 ;
F_173 ( V_15 , V_96 ) ;
} else {
F_124 ( & V_96 -> V_153 , & V_38 -> V_7 ) ;
}
} else {
F_221 ( & V_96 -> V_153 , & V_38 -> V_6 ) ;
}
}
}
static void F_267 ( struct V_14 * V_15 , struct V_36 * V_97 )
{
int V_89 ;
struct V_3 * V_38 ;
int V_40 = F_65 () ;
V_89 = V_97 -> V_89 ;
#if V_232
F_9 ( ! V_89 || V_89 > V_97 -> V_93 ) ;
#endif
F_189 () ;
V_38 = V_15 -> V_40 [ V_40 ] ;
F_88 ( & V_38 -> V_11 ) ;
if ( V_38 -> V_8 ) {
struct V_36 * V_292 = V_38 -> V_8 ;
int V_104 = V_292 -> V_94 - V_292 -> V_93 ;
if ( V_104 ) {
if ( V_89 > V_104 )
V_89 = V_104 ;
memcpy ( & ( V_292 -> V_101 [ V_292 -> V_93 ] ) ,
V_97 -> V_101 , sizeof( void * ) * V_89 ) ;
V_292 -> V_93 += V_89 ;
goto V_293;
}
}
F_89 ( V_15 , V_97 -> V_101 , V_89 , V_40 ) ;
V_293:
#if V_294
{
int V_45 = 0 ;
struct V_242 * V_243 ;
V_243 = V_38 -> V_7 . V_248 ;
while ( V_243 != & ( V_38 -> V_7 ) ) {
struct V_25 * V_96 ;
V_96 = F_200 ( V_243 , struct V_25 , V_153 ) ;
F_9 ( V_96 -> V_184 ) ;
V_45 ++ ;
V_243 = V_243 -> V_248 ;
}
F_268 ( V_15 , V_45 ) ;
}
#endif
F_90 ( & V_38 -> V_11 ) ;
V_97 -> V_93 -= V_89 ;
memmove ( V_97 -> V_101 , & ( V_97 -> V_101 [ V_89 ] ) , sizeof( void * ) * V_97 -> V_93 ) ;
}
static inline void F_269 ( struct V_14 * V_15 , void * V_1 ,
unsigned long V_207 )
{
struct V_36 * V_97 = F_31 ( V_15 ) ;
F_189 () ;
F_270 ( V_1 , V_15 -> V_16 ) ;
V_1 = F_226 ( V_15 , V_1 , V_207 ) ;
F_271 ( V_15 , V_1 , V_15 -> V_208 ) ;
if ( V_295 > 1 && F_81 ( V_15 , V_1 ) )
return;
if ( F_95 ( V_97 -> V_93 < V_97 -> V_94 ) ) {
F_272 ( V_15 ) ;
} else {
F_273 ( V_15 ) ;
F_267 ( V_15 , V_97 ) ;
}
F_76 ( V_15 , V_97 , V_1 ) ;
}
void * F_274 ( struct V_14 * V_15 , T_4 V_16 )
{
void * V_139 = F_264 ( V_15 , V_16 , V_296 ) ;
F_275 ( V_296 , V_139 ,
V_15 -> V_208 , V_15 -> V_19 , V_16 ) ;
return V_139 ;
}
void *
F_276 ( struct V_14 * V_15 , T_4 V_16 , T_2 V_19 )
{
void * V_139 ;
V_139 = F_264 ( V_15 , V_16 , V_296 ) ;
F_277 ( V_296 , V_139 ,
V_19 , V_15 -> V_19 , V_16 ) ;
return V_139 ;
}
void * F_208 ( struct V_14 * V_15 , T_4 V_16 , int V_107 )
{
void * V_139 = F_256 ( V_15 , V_16 , V_107 , V_296 ) ;
F_278 ( V_296 , V_139 ,
V_15 -> V_208 , V_15 -> V_19 ,
V_16 , V_107 ) ;
return V_139 ;
}
void * F_279 ( struct V_14 * V_15 ,
T_4 V_16 ,
int V_107 ,
T_2 V_19 )
{
void * V_139 ;
V_139 = F_256 ( V_15 , V_16 , V_107 , V_296 ) ;
F_280 ( V_296 , V_139 ,
V_19 , V_15 -> V_19 ,
V_16 , V_107 ) ;
return V_139 ;
}
static T_8 void *
F_281 ( T_2 V_19 , T_4 V_16 , int V_40 , unsigned long V_207 )
{
struct V_14 * V_15 ;
V_15 = F_185 ( V_19 , V_16 ) ;
if ( F_51 ( F_186 ( V_15 ) ) )
return V_15 ;
return F_279 ( V_15 , V_16 , V_40 , V_19 ) ;
}
void * F_282 ( T_2 V_19 , T_4 V_16 , int V_40 )
{
return F_281 ( V_19 , V_16 , V_40 , V_296 ) ;
}
void * F_283 ( T_2 V_19 , T_4 V_16 ,
int V_40 , unsigned long V_207 )
{
return F_281 ( V_19 , V_16 , V_40 , V_207 ) ;
}
void * F_282 ( T_2 V_19 , T_4 V_16 , int V_40 )
{
return F_281 ( V_19 , V_16 , V_40 , 0 ) ;
}
static T_8 void * F_284 ( T_2 V_19 , T_4 V_16 ,
unsigned long V_207 )
{
struct V_14 * V_15 ;
void * V_139 ;
V_15 = F_185 ( V_19 , V_16 ) ;
if ( F_51 ( F_186 ( V_15 ) ) )
return V_15 ;
V_139 = F_264 ( V_15 , V_16 , V_207 ) ;
F_277 ( V_207 , V_139 ,
V_19 , V_15 -> V_19 , V_16 ) ;
return V_139 ;
}
void * F_285 ( T_2 V_19 , T_4 V_16 )
{
return F_284 ( V_19 , V_16 , V_296 ) ;
}
void * F_286 ( T_2 V_19 , T_4 V_16 , unsigned long V_207 )
{
return F_284 ( V_19 , V_16 , V_207 ) ;
}
void * F_285 ( T_2 V_19 , T_4 V_16 )
{
return F_284 ( V_19 , V_16 , 0 ) ;
}
void F_158 ( struct V_14 * V_15 , void * V_1 )
{
unsigned long V_16 ;
V_15 = F_287 ( V_15 , V_1 ) ;
if ( ! V_15 )
return;
F_259 ( V_16 ) ;
F_288 ( V_1 , V_15 -> V_208 ) ;
if ( ! ( V_15 -> V_16 & V_120 ) )
F_289 ( V_1 , V_15 -> V_208 ) ;
F_269 ( V_15 , V_1 , V_296 ) ;
F_260 ( V_16 ) ;
F_290 ( V_296 , V_1 ) ;
}
void F_86 ( const void * V_1 )
{
struct V_14 * V_297 ;
unsigned long V_16 ;
F_291 ( V_296 , V_1 ) ;
if ( F_51 ( F_186 ( V_1 ) ) )
return;
F_259 ( V_16 ) ;
F_223 ( V_1 ) ;
V_297 = F_12 ( V_1 ) ;
F_288 ( V_1 , V_297 -> V_208 ) ;
F_289 ( V_1 , V_297 -> V_208 ) ;
F_269 ( V_297 , ( void * ) V_1 , V_296 ) ;
F_260 ( V_16 ) ;
}
static int F_292 ( struct V_14 * V_15 , T_4 V_90 )
{
int V_40 ;
struct V_3 * V_38 ;
struct V_36 * V_298 ;
struct V_36 * * V_299 = NULL ;
F_25 (node) {
if ( V_72 ) {
V_299 = F_79 ( V_40 , V_15 -> V_94 , V_90 ) ;
if ( ! V_299 )
goto V_300;
}
V_298 = NULL ;
if ( V_15 -> V_8 ) {
V_298 = F_58 ( V_40 ,
V_15 -> V_8 * V_15 -> V_89 ,
0xbaadf00d , V_90 ) ;
if ( ! V_298 ) {
F_80 ( V_299 ) ;
goto V_300;
}
}
V_38 = V_15 -> V_40 [ V_40 ] ;
if ( V_38 ) {
struct V_36 * V_8 = V_38 -> V_8 ;
F_99 ( & V_38 -> V_11 ) ;
if ( V_8 )
F_89 ( V_15 , V_8 -> V_101 ,
V_8 -> V_93 , V_40 ) ;
V_38 -> V_8 = V_298 ;
if ( ! V_38 -> V_9 ) {
V_38 -> V_9 = V_299 ;
V_299 = NULL ;
}
V_38 -> V_114 = ( 1 + F_100 ( V_40 ) ) *
V_15 -> V_89 + V_15 -> V_59 ;
F_93 ( & V_38 -> V_11 ) ;
F_86 ( V_8 ) ;
F_80 ( V_299 ) ;
continue;
}
V_38 = F_59 ( sizeof( struct V_3 ) , V_90 , V_40 ) ;
if ( ! V_38 ) {
F_80 ( V_299 ) ;
F_86 ( V_298 ) ;
goto V_300;
}
F_4 ( V_38 ) ;
V_38 -> V_111 = V_112 + V_113 +
( ( unsigned long ) V_15 ) % V_113 ;
V_38 -> V_8 = V_298 ;
V_38 -> V_9 = V_299 ;
V_38 -> V_114 = ( 1 + F_100 ( V_40 ) ) *
V_15 -> V_89 + V_15 -> V_59 ;
V_15 -> V_40 [ V_40 ] = V_38 ;
}
return 0 ;
V_300:
if ( ! V_15 -> V_153 . V_248 ) {
V_40 -- ;
while ( V_40 >= 0 ) {
if ( V_15 -> V_40 [ V_40 ] ) {
V_38 = V_15 -> V_40 [ V_40 ] ;
F_86 ( V_38 -> V_8 ) ;
F_80 ( V_38 -> V_9 ) ;
F_86 ( V_38 ) ;
V_15 -> V_40 [ V_40 ] = NULL ;
}
V_40 -- ;
}
}
return - V_110 ;
}
static void F_293 ( void * V_301 )
{
struct V_302 * V_303 = V_301 ;
struct V_36 * V_304 ;
F_189 () ;
V_304 = F_31 ( V_303 -> V_15 ) ;
V_303 -> V_15 -> V_52 [ F_32 () ] = V_303 -> V_303 [ F_32 () ] ;
V_303 -> V_303 [ F_32 () ] = V_304 ;
}
static int F_294 ( struct V_14 * V_15 , int V_94 ,
int V_89 , int V_8 , T_4 V_90 )
{
struct V_302 * V_303 ;
int V_45 ;
V_303 = F_295 ( sizeof( * V_303 ) + V_158 * sizeof( struct V_36 * ) ,
V_90 ) ;
if ( ! V_303 )
return - V_110 ;
F_135 (i) {
V_303 -> V_303 [ V_45 ] = F_58 ( F_46 ( V_45 ) , V_94 ,
V_89 , V_90 ) ;
if ( ! V_303 -> V_303 [ V_45 ] ) {
for ( V_45 -- ; V_45 >= 0 ; V_45 -- )
F_86 ( V_303 -> V_303 [ V_45 ] ) ;
F_86 ( V_303 ) ;
return - V_110 ;
}
}
V_303 -> V_15 = V_15 ;
F_198 ( F_293 , ( void * ) V_303 , 1 ) ;
F_191 () ;
V_15 -> V_89 = V_89 ;
V_15 -> V_94 = V_94 ;
V_15 -> V_8 = V_8 ;
F_135 (i) {
struct V_36 * V_305 = V_303 -> V_303 [ V_45 ] ;
if ( ! V_305 )
continue;
F_99 ( & V_15 -> V_40 [ F_46 ( V_45 ) ] -> V_11 ) ;
F_89 ( V_15 , V_305 -> V_101 , V_305 -> V_93 , F_46 ( V_45 ) ) ;
F_93 ( & V_15 -> V_40 [ F_46 ( V_45 ) ] -> V_11 ) ;
F_86 ( V_305 ) ;
}
F_86 ( V_303 ) ;
return F_292 ( V_15 , V_90 ) ;
}
static int F_296 ( struct V_14 * V_15 , int V_94 ,
int V_89 , int V_8 , T_4 V_90 )
{
int V_139 ;
struct V_14 * V_297 = NULL ;
int V_45 = 0 ;
V_139 = F_294 ( V_15 , V_94 , V_89 , V_8 , V_90 ) ;
if ( V_46 < V_175 )
return V_139 ;
if ( ( V_139 < 0 ) || ! F_297 ( V_15 ) )
return V_139 ;
F_15 ( ! F_298 ( & V_128 ) ) ;
F_299 (i) {
V_297 = F_300 ( V_15 , V_45 ) ;
if ( V_297 )
F_294 ( V_297 , V_94 , V_89 , V_8 , V_90 ) ;
}
return V_139 ;
}
static int F_130 ( struct V_14 * V_15 , T_4 V_90 )
{
int V_118 ;
int V_94 = 0 ;
int V_8 = 0 ;
int V_89 = 0 ;
if ( ! F_297 ( V_15 ) ) {
struct V_14 * V_306 = F_301 ( V_15 ) ;
V_94 = V_306 -> V_94 ;
V_8 = V_306 -> V_8 ;
V_89 = V_306 -> V_89 ;
}
if ( V_94 && V_8 && V_89 )
goto V_307;
if ( V_15 -> V_19 > 131072 )
V_94 = 1 ;
else if ( V_15 -> V_19 > V_62 )
V_94 = 8 ;
else if ( V_15 -> V_19 > 1024 )
V_94 = 24 ;
else if ( V_15 -> V_19 > 256 )
V_94 = 54 ;
else
V_94 = 120 ;
V_8 = 0 ;
if ( V_15 -> V_19 <= V_62 && F_302 () > 1 )
V_8 = 8 ;
#if V_232
if ( V_94 > 32 )
V_94 = 32 ;
#endif
V_89 = ( V_94 + 1 ) / 2 ;
V_307:
V_118 = F_296 ( V_15 , V_94 , V_89 , V_8 , V_90 ) ;
if ( V_118 )
F_37 ( V_67 L_38 ,
V_15 -> V_68 , - V_118 ) ;
return V_118 ;
}
static void F_199 ( struct V_14 * V_15 , struct V_3 * V_38 ,
struct V_36 * V_97 , int V_308 , int V_40 )
{
int V_241 ;
if ( ! V_97 || ! V_97 -> V_93 )
return;
if ( V_97 -> V_95 && ! V_308 ) {
V_97 -> V_95 = 0 ;
} else {
F_99 ( & V_38 -> V_11 ) ;
if ( V_97 -> V_93 ) {
V_241 = V_308 ? V_97 -> V_93 : ( V_97 -> V_94 + 4 ) / 5 ;
if ( V_241 > V_97 -> V_93 )
V_241 = ( V_97 -> V_93 + 1 ) / 2 ;
F_89 ( V_15 , V_97 -> V_101 , V_241 , V_40 ) ;
V_97 -> V_93 -= V_241 ;
memmove ( V_97 -> V_101 , & ( V_97 -> V_101 [ V_241 ] ) ,
sizeof( void * ) * V_97 -> V_93 ) ;
}
F_93 ( & V_38 -> V_11 ) ;
}
}
static void V_86 ( struct V_309 * V_310 )
{
struct V_14 * V_311 ;
struct V_3 * V_38 ;
int V_40 = F_65 () ;
struct V_81 * V_84 = F_303 ( V_310 ) ;
if ( ! F_304 ( & V_128 ) )
goto V_99;
F_67 (searchp, &slab_caches, list) {
F_191 () ;
V_38 = V_311 -> V_40 [ V_40 ] ;
F_91 ( V_311 , V_38 ) ;
F_199 ( V_311 , V_38 , F_31 ( V_311 ) , 0 , V_40 ) ;
if ( F_305 ( V_38 -> V_111 , V_112 ) )
goto V_248;
V_38 -> V_111 = V_112 + V_113 ;
F_199 ( V_311 , V_38 , V_38 -> V_8 , 0 , V_40 ) ;
if ( V_38 -> V_13 )
V_38 -> V_13 = 0 ;
else {
int V_312 ;
V_312 = F_105 ( V_311 , V_38 , ( V_38 -> V_114 +
5 * V_311 -> V_59 - 1 ) / ( 5 * V_311 -> V_59 ) ) ;
F_306 ( V_311 , V_312 ) ;
}
V_248:
F_307 () ;
}
F_191 () ;
F_110 ( & V_128 ) ;
F_49 () ;
V_99:
F_308 ( V_84 , F_309 ( V_313 ) ) ;
}
void F_310 ( struct V_14 * V_15 , struct V_314 * V_315 )
{
struct V_25 * V_96 ;
unsigned long V_180 ;
unsigned long V_181 ;
unsigned long V_182 = 0 ;
unsigned long V_183 , V_12 = 0 , V_316 = 0 ;
const char * V_68 ;
char * error = NULL ;
int V_40 ;
struct V_3 * V_38 ;
V_180 = 0 ;
V_183 = 0 ;
F_25 (node) {
V_38 = V_15 -> V_40 [ V_40 ] ;
if ( ! V_38 )
continue;
F_191 () ;
F_99 ( & V_38 -> V_11 ) ;
F_67 (slabp, &n->slabs_full, list) {
if ( V_96 -> V_184 != V_15 -> V_59 && ! error )
error = L_39 ;
V_180 += V_15 -> V_59 ;
V_182 ++ ;
}
F_67 (slabp, &n->slabs_partial, list) {
if ( V_96 -> V_184 == V_15 -> V_59 && ! error )
error = L_40 ;
if ( ! V_96 -> V_184 && ! error )
error = L_41 ;
V_180 += V_96 -> V_184 ;
V_182 ++ ;
}
F_67 (slabp, &n->slabs_free, list) {
if ( V_96 -> V_184 && ! error )
error = L_42 ;
V_183 ++ ;
}
V_12 += V_38 -> V_12 ;
if ( V_38 -> V_8 )
V_316 += V_38 -> V_8 -> V_93 ;
F_93 ( & V_38 -> V_11 ) ;
}
V_183 += V_182 ;
V_181 = V_183 * V_15 -> V_59 ;
if ( V_181 - V_180 != V_12 && ! error )
error = L_43 ;
V_68 = V_15 -> V_68 ;
if ( error )
F_37 ( V_67 L_44 , V_68 , error ) ;
V_315 -> V_180 = V_180 ;
V_315 -> V_181 = V_181 ;
V_315 -> V_182 = V_182 ;
V_315 -> V_183 = V_183 ;
V_315 -> V_316 = V_316 ;
V_315 -> V_94 = V_15 -> V_94 ;
V_315 -> V_89 = V_15 -> V_89 ;
V_315 -> V_8 = V_15 -> V_8 ;
V_315 -> V_317 = V_15 -> V_59 ;
V_315 -> V_318 = V_15 -> V_56 ;
}
void F_311 ( struct V_319 * V_320 , struct V_14 * V_15 )
{
#if V_294
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
F_312 ( V_320 , L_45
L_46 ,
V_323 , V_321 , V_325 ,
V_326 , V_327 , V_328 , V_329 ,
V_330 , V_331 ) ;
}
{
unsigned long V_333 = F_313 ( & V_15 -> V_333 ) ;
unsigned long V_334 = F_313 ( & V_15 -> V_334 ) ;
unsigned long V_335 = F_313 ( & V_15 -> V_335 ) ;
unsigned long V_336 = F_313 ( & V_15 -> V_336 ) ;
F_312 ( V_320 , L_47 ,
V_333 , V_334 , V_335 , V_336 ) ;
}
#endif
}
T_9 F_314 ( struct V_337 * V_337 , const char T_10 * V_338 ,
T_2 V_339 , T_11 * V_340 )
{
char V_341 [ V_342 + 1 ] , * V_343 ;
int V_94 , V_89 , V_8 , V_344 ;
struct V_14 * V_15 ;
if ( V_339 > V_342 )
return - V_345 ;
if ( F_315 ( & V_341 , V_338 , V_339 ) )
return - V_346 ;
V_341 [ V_342 ] = '\0' ;
V_343 = strchr ( V_341 , ' ' ) ;
if ( ! V_343 )
return - V_345 ;
* V_343 = '\0' ;
V_343 ++ ;
if ( sscanf ( V_343 , L_48 , & V_94 , & V_89 , & V_8 ) != 3 )
return - V_345 ;
F_109 ( & V_128 ) ;
V_344 = - V_345 ;
F_67 (cachep, &slab_caches, list) {
if ( ! strcmp ( V_15 -> V_68 , V_341 ) ) {
if ( V_94 < 1 || V_89 < 1 ||
V_89 > V_94 || V_8 < 0 ) {
V_344 = 0 ;
} else {
V_344 = F_296 ( V_15 , V_94 ,
V_89 , V_8 ,
V_109 ) ;
}
break;
}
}
F_110 ( & V_128 ) ;
if ( V_344 >= 0 )
V_344 = V_339 ;
return V_344 ;
}
static void * F_316 ( struct V_319 * V_320 , T_11 * V_347 )
{
F_109 ( & V_128 ) ;
return F_317 ( & V_166 , * V_347 ) ;
}
static inline int F_318 ( unsigned long * V_38 , unsigned long V_348 )
{
unsigned long * V_243 ;
int V_349 ;
if ( ! V_348 )
return 1 ;
V_349 = V_38 [ 1 ] ;
V_243 = V_38 + 2 ;
while ( V_349 ) {
int V_45 = V_349 / 2 ;
unsigned long * V_35 = V_243 + 2 * V_45 ;
if ( * V_35 == V_348 ) {
V_35 [ 1 ] ++ ;
return 1 ;
}
if ( * V_35 > V_348 ) {
V_349 = V_45 ;
} else {
V_243 = V_35 + 2 ;
V_349 -= V_45 + 1 ;
}
}
if ( ++ V_38 [ 1 ] == V_38 [ 0 ] )
return 0 ;
memmove ( V_243 + 2 , V_243 , V_38 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_243 - ( void * ) V_38 ) ) ;
V_243 [ 0 ] = V_348 ;
V_243 [ 1 ] = 1 ;
return 1 ;
}
static void F_319 ( unsigned long * V_38 , struct V_14 * V_297 , struct V_25 * V_71 )
{
void * V_243 ;
int V_45 ;
if ( V_38 [ 0 ] == V_38 [ 1 ] )
return;
for ( V_45 = 0 , V_243 = V_71 -> V_29 ; V_45 < V_297 -> V_59 ; V_45 ++ , V_243 += V_297 -> V_19 ) {
if ( F_210 ( V_71 ) [ V_45 ] != V_268 )
continue;
if ( ! F_318 ( V_38 , ( unsigned long ) * F_11 ( V_297 , V_243 ) ) )
return;
}
}
static void F_320 ( struct V_319 * V_320 , unsigned long V_350 )
{
#ifdef F_321
unsigned long V_30 , V_19 ;
char V_351 [ V_352 ] , V_68 [ V_353 ] ;
if ( F_322 ( V_350 , & V_19 , & V_30 , V_351 , V_68 ) == 0 ) {
F_312 ( V_320 , L_49 , V_68 , V_30 , V_19 ) ;
if ( V_351 [ 0 ] )
F_312 ( V_320 , L_50 , V_351 ) ;
return;
}
#endif
F_312 ( V_320 , L_51 , ( void * ) V_350 ) ;
}
static int F_323 ( struct V_319 * V_320 , void * V_243 )
{
struct V_14 * V_15 = F_200 ( V_243 , struct V_14 , V_153 ) ;
struct V_25 * V_96 ;
struct V_3 * V_38 ;
const char * V_68 ;
unsigned long * V_265 = V_320 -> V_354 ;
int V_40 ;
int V_45 ;
if ( ! ( V_15 -> V_16 & V_18 ) )
return 0 ;
if ( ! ( V_15 -> V_16 & V_17 ) )
return 0 ;
V_265 [ 1 ] = 0 ;
F_25 (node) {
V_38 = V_15 -> V_40 [ V_40 ] ;
if ( ! V_38 )
continue;
F_191 () ;
F_99 ( & V_38 -> V_11 ) ;
F_67 (slabp, &n->slabs_full, list)
F_319 ( V_265 , V_15 , V_96 ) ;
F_67 (slabp, &n->slabs_partial, list)
F_319 ( V_265 , V_15 , V_96 ) ;
F_93 ( & V_38 -> V_11 ) ;
}
V_68 = V_15 -> V_68 ;
if ( V_265 [ 0 ] == V_265 [ 1 ] ) {
F_110 ( & V_128 ) ;
V_320 -> V_354 = F_295 ( V_265 [ 0 ] * 4 * sizeof( unsigned long ) , V_109 ) ;
if ( ! V_320 -> V_354 ) {
V_320 -> V_354 = V_265 ;
F_109 ( & V_128 ) ;
return - V_110 ;
}
* ( unsigned long * ) V_320 -> V_354 = V_265 [ 0 ] * 2 ;
F_86 ( V_265 ) ;
F_109 ( & V_128 ) ;
V_320 -> V_339 = V_320 -> V_19 ;
return 0 ;
}
for ( V_45 = 0 ; V_45 < V_265 [ 1 ] ; V_45 ++ ) {
F_312 ( V_320 , L_52 , V_68 , V_265 [ 2 * V_45 + 3 ] ) ;
F_320 ( V_320 , V_265 [ 2 * V_45 + 2 ] ) ;
F_324 ( V_320 , '\n' ) ;
}
return 0 ;
}
static int F_325 ( struct V_355 * V_355 , struct V_337 * V_337 )
{
unsigned long * V_38 = F_295 ( V_62 , V_109 ) ;
int V_139 = - V_110 ;
if ( V_38 ) {
V_139 = F_326 ( V_337 , & V_356 ) ;
if ( ! V_139 ) {
struct V_319 * V_320 = V_337 -> V_357 ;
* V_38 = V_62 / ( 2 * sizeof( unsigned long ) ) ;
V_320 -> V_354 = V_38 ;
V_38 = NULL ;
}
F_86 ( V_38 ) ;
}
return V_139 ;
}
static int T_3 F_327 ( void )
{
#ifdef F_227
F_328 ( L_53 , 0 , NULL , & V_358 ) ;
#endif
return 0 ;
}
T_2 F_329 ( const void * V_1 )
{
F_9 ( ! V_1 ) ;
if ( F_51 ( V_1 == V_359 ) )
return 0 ;
return F_12 ( V_1 ) -> V_208 ;
}
