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
for ( V_45 = 1 ; V_45 < V_48 + V_49 ; V_45 ++ ) {
struct V_3 * V_38 ;
struct V_14 * V_27 = V_50 [ V_45 ] ;
if ( ! V_27 )
continue;
V_38 = V_27 -> V_40 [ V_35 ] ;
if ( ! V_38 || F_27 ( V_27 ) )
continue;
F_20 ( V_27 , & V_51 ,
& V_52 , V_35 ) ;
}
}
static void F_28 ( struct V_14 * V_15 , int V_35 )
{
if ( ! V_15 -> V_40 [ V_35 ] )
return;
F_20 ( V_15 , & V_51 ,
& V_52 , V_35 ) ;
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
return V_15 -> V_53 [ F_32 () ] ;
}
static T_2 F_33 ( T_2 V_54 , T_2 V_55 )
{
return F_34 ( sizeof( struct V_25 ) + V_54 * sizeof( V_56 ) , V_55 ) ;
}
static void F_35 ( unsigned long V_57 , T_2 V_58 ,
T_2 V_55 , int V_16 , T_2 * V_59 ,
unsigned int * V_60 )
{
int V_54 ;
T_2 V_61 ;
T_2 V_62 = V_63 << V_57 ;
if ( V_16 & V_64 ) {
V_61 = 0 ;
V_54 = V_62 / V_58 ;
if ( V_54 > V_65 )
V_54 = V_65 ;
} else {
V_54 = ( V_62 - sizeof( struct V_25 ) ) /
( V_58 + sizeof( V_56 ) ) ;
if ( F_33 ( V_54 , V_55 ) + V_54 * V_58
> V_62 )
V_54 -- ;
if ( V_54 > V_65 )
V_54 = V_65 ;
V_61 = F_33 ( V_54 , V_55 ) ;
}
* V_60 = V_54 ;
* V_59 = V_62 - V_54 * V_58 - V_61 ;
}
static void F_36 ( const char * V_66 , struct V_14 * V_15 ,
char * V_67 )
{
F_37 ( V_68 L_1 ,
V_66 , V_15 -> V_69 , V_67 ) ;
F_38 () ;
F_39 ( V_70 , V_71 ) ;
}
static int T_3 F_40 ( char * V_72 )
{
V_73 = 0 ;
return 1 ;
}
static int T_3 F_41 ( char * V_74 )
{
F_42 ( & V_74 , & V_75 ) ;
V_75 = V_75 < 0 ? 0 :
F_43 ( V_75 , V_49 - 1 ) ;
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
static void T_4 F_53 ( int V_77 )
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
int V_89 , T_5 V_90 )
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
T_5 V_16 , bool V_100 )
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
struct V_36 * V_97 , T_5 V_16 , bool V_100 )
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
static inline struct V_36 * * F_79 ( int V_40 , int V_94 , T_5 V_90 )
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
T_5 V_16 )
{
return NULL ;
}
static inline void * F_83 ( struct V_14 * V_15 ,
T_5 V_16 , int V_107 )
{
return NULL ;
}
static struct V_36 * * F_79 ( int V_40 , int V_94 , T_5 V_90 )
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
V_15 -> V_89 + V_15 -> V_60 ;
F_93 ( & V_15 -> V_40 [ V_40 ] -> V_11 ) ;
}
return 0 ;
}
static void T_4 F_101 ( long V_77 )
{
struct V_14 * V_15 ;
struct V_3 * V_38 = NULL ;
int V_40 = F_46 ( V_77 ) ;
const struct V_115 * V_116 = F_102 ( V_40 ) ;
F_67 (cachep, &slab_caches, list) {
struct V_36 * V_92 ;
struct V_36 * V_8 ;
struct V_36 * * V_9 ;
V_92 = V_15 -> V_53 [ V_77 ] ;
V_15 -> V_53 [ V_77 ] = NULL ;
V_38 = V_15 -> V_40 [ V_40 ] ;
if ( ! V_38 )
goto V_117;
F_99 ( & V_38 -> V_11 ) ;
V_38 -> V_114 -= V_15 -> V_89 ;
if ( V_92 )
F_89 ( V_15 , V_92 -> V_101 , V_92 -> V_93 , V_40 ) ;
if ( ! F_103 ( V_116 ) ) {
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
F_104 ( V_15 , V_38 , V_38 -> V_12 ) ;
}
}
static int T_4 F_105 ( long V_77 )
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
if ( V_73 ) {
V_9 = F_79 ( V_40 , V_15 -> V_94 , V_109 ) ;
if ( ! V_9 ) {
F_86 ( V_8 ) ;
F_86 ( V_92 ) ;
goto V_119;
}
}
V_15 -> V_53 [ V_77 ] = V_92 ;
V_38 = V_15 -> V_40 [ V_40 ] ;
F_9 ( ! V_38 ) ;
F_99 ( & V_38 -> V_11 ) ;
if ( ! V_38 -> V_8 ) {
V_38 -> V_8 = V_8 ;
V_8 = NULL ;
}
#ifdef F_106
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
F_101 ( V_77 ) ;
return - V_110 ;
}
static int T_4 F_107 ( struct V_122 * V_123 ,
unsigned long V_124 , void * V_125 )
{
long V_77 = ( long ) V_125 ;
int V_118 = 0 ;
switch ( V_124 ) {
case V_126 :
case V_127 :
F_108 ( & V_128 ) ;
V_118 = F_105 ( V_77 ) ;
F_109 ( & V_128 ) ;
break;
case V_129 :
case V_130 :
F_53 ( V_77 ) ;
break;
#ifdef F_110
case V_131 :
case V_132 :
F_111 ( & F_48 ( V_83 , V_77 ) ) ;
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
F_108 ( & V_128 ) ;
F_101 ( V_77 ) ;
F_109 ( & V_128 ) ;
break;
}
return F_112 ( V_118 ) ;
}
static int T_6 F_113 ( int V_40 )
{
struct V_14 * V_15 ;
int V_139 = 0 ;
F_67 (cachep, &slab_caches, list) {
struct V_3 * V_38 ;
V_38 = V_15 -> V_40 [ V_40 ] ;
if ( ! V_38 )
continue;
F_104 ( V_15 , V_38 , V_38 -> V_12 ) ;
if ( ! F_71 ( & V_38 -> V_5 ) ||
! F_71 ( & V_38 -> V_6 ) ) {
V_139 = - V_140 ;
break;
}
}
return V_139 ;
}
static int T_6 F_114 ( struct V_122 * V_141 ,
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
F_108 ( & V_128 ) ;
V_139 = F_98 ( V_145 ) ;
F_109 ( & V_128 ) ;
break;
case V_148 :
F_108 ( & V_128 ) ;
V_139 = F_113 ( V_145 ) ;
F_109 ( & V_128 ) ;
break;
case V_149 :
case V_150 :
case V_151 :
case V_152 :
break;
}
V_99:
return F_112 ( V_139 ) ;
}
static void T_3 F_115 ( struct V_14 * V_15 , struct V_3 * V_153 ,
int V_107 )
{
struct V_3 * V_154 ;
V_154 = F_59 ( sizeof( struct V_3 ) , V_155 , V_107 ) ;
F_9 ( ! V_154 ) ;
memcpy ( V_154 , V_153 , sizeof( struct V_3 ) ) ;
F_6 ( & V_154 -> V_11 ) ;
F_116 ( V_15 , V_154 , V_107 ) ;
V_15 -> V_40 [ V_107 ] = V_154 ;
}
static void T_3 F_117 ( struct V_14 * V_15 , int V_156 )
{
int V_40 ;
F_25 (node) {
V_15 -> V_40 [ V_40 ] = & V_157 [ V_156 + V_40 ] ;
V_15 -> V_40 [ V_40 ] -> V_111 = V_112 +
V_113 +
( ( unsigned long ) V_15 ) % V_113 ;
}
}
static void F_118 ( struct V_14 * V_15 )
{
V_15 -> V_40 = (struct V_3 * * ) & V_15 -> V_53 [ V_158 ] ;
}
void T_3 F_119 ( void )
{
int V_45 ;
V_14 = & V_159 ;
F_118 ( V_14 ) ;
if ( F_120 () == 1 )
V_73 = 0 ;
for ( V_45 = 0 ; V_45 < V_160 ; V_45 ++ )
F_4 ( & V_157 [ V_45 ] ) ;
F_117 ( V_14 , V_161 ) ;
if ( ! V_76 && V_162 > ( 32 << 20 ) >> V_48 )
V_75 = V_163 ;
F_121 ( V_14 , L_2 ,
F_122 ( struct V_14 , V_53 [ V_158 ] ) +
V_108 * sizeof( struct V_3 * ) ,
V_164 ) ;
F_123 ( & V_14 -> V_153 , & V_165 ) ;
V_50 [ V_166 ] = F_124 ( L_3 ,
F_125 ( V_166 ) , V_167 ) ;
if ( V_166 != V_168 )
V_50 [ V_168 ] =
F_124 ( L_4 ,
F_125 ( V_168 ) , V_167 ) ;
V_169 = 0 ;
{
struct V_36 * V_154 ;
V_154 = F_126 ( sizeof( struct V_170 ) , V_155 ) ;
memcpy ( V_154 , F_31 ( V_14 ) ,
sizeof( struct V_170 ) ) ;
F_6 ( & V_154 -> V_42 ) ;
V_14 -> V_53 [ F_32 () ] = V_154 ;
V_154 = F_126 ( sizeof( struct V_170 ) , V_155 ) ;
F_9 ( F_31 ( V_50 [ V_166 ] )
!= & V_171 . V_27 ) ;
memcpy ( V_154 , F_31 ( V_50 [ V_166 ] ) ,
sizeof( struct V_170 ) ) ;
F_6 ( & V_154 -> V_42 ) ;
V_50 [ V_166 ] -> V_53 [ F_32 () ] = V_154 ;
}
{
int V_145 ;
F_25 (nid) {
F_115 ( V_14 , & V_157 [ V_161 + V_145 ] , V_145 ) ;
F_115 ( V_50 [ V_166 ] ,
& V_157 [ V_172 + V_145 ] , V_145 ) ;
if ( V_166 != V_168 ) {
F_115 ( V_50 [ V_168 ] ,
& V_157 [ V_173 + V_145 ] , V_145 ) ;
}
}
}
F_127 ( V_167 ) ;
}
void T_3 F_128 ( void )
{
struct V_14 * V_15 ;
V_46 = V_47 ;
F_108 ( & V_128 ) ;
F_67 (cachep, &slab_caches, list)
if ( F_129 ( V_15 , V_155 ) )
F_130 () ;
F_109 ( & V_128 ) ;
F_30 () ;
V_46 = V_174 ;
F_131 ( & V_175 ) ;
#ifdef F_106
F_132 ( F_114 , V_176 ) ;
#endif
}
static int T_3 F_133 ( void )
{
int V_77 ;
F_134 (cpu)
F_53 ( V_77 ) ;
V_46 = V_174 ;
return 0 ;
}
static T_7 void
F_135 ( struct V_14 * V_15 , T_5 V_177 , int V_107 )
{
struct V_3 * V_38 ;
struct V_25 * V_96 ;
unsigned long V_16 ;
int V_40 ;
F_37 ( V_178
L_5 ,
V_107 , V_177 ) ;
F_37 ( V_178 L_6 ,
V_15 -> V_69 , V_15 -> V_19 , V_15 -> V_57 ) ;
F_25 (node) {
unsigned long V_179 = 0 , V_180 = 0 , V_12 = 0 ;
unsigned long V_181 = 0 , V_182 = 0 ;
V_38 = V_15 -> V_40 [ V_40 ] ;
if ( ! V_38 )
continue;
F_66 ( & V_38 -> V_11 , V_16 ) ;
F_67 (slabp, &n->slabs_full, list) {
V_179 += V_15 -> V_60 ;
V_181 ++ ;
}
F_67 (slabp, &n->slabs_partial, list) {
V_179 += V_96 -> V_183 ;
V_181 ++ ;
}
F_67 (slabp, &n->slabs_free, list)
V_182 ++ ;
V_12 += V_38 -> V_12 ;
F_68 ( & V_38 -> V_11 , V_16 ) ;
V_182 += V_181 ;
V_180 = V_182 * V_15 -> V_60 ;
F_37 ( V_178
L_7 ,
V_40 , V_181 , V_182 , V_179 , V_180 ,
V_12 ) ;
}
}
static void * F_136 ( struct V_14 * V_15 , T_5 V_16 , int V_107 )
{
struct V_23 * V_23 ;
int V_184 ;
int V_45 ;
#ifndef F_137
V_16 |= V_185 ;
#endif
V_16 |= V_15 -> V_186 ;
if ( V_15 -> V_16 & V_187 )
V_16 |= V_188 ;
V_23 = F_138 ( V_107 , V_16 | V_189 , V_15 -> V_57 ) ;
if ( ! V_23 ) {
if ( ! ( V_16 & V_190 ) && F_139 () )
F_135 ( V_15 , V_16 , V_107 ) ;
return NULL ;
}
if ( F_51 ( V_23 -> V_191 ) )
V_98 = true ;
V_184 = ( 1 << V_15 -> V_57 ) ;
if ( V_15 -> V_16 & V_187 )
F_140 ( F_141 ( V_23 ) ,
V_192 , V_184 ) ;
else
F_140 ( F_141 ( V_23 ) ,
V_193 , V_184 ) ;
for ( V_45 = 0 ; V_45 < V_184 ; V_45 ++ ) {
F_142 ( V_23 + V_45 ) ;
if ( V_23 -> V_191 )
F_143 ( V_23 + V_45 ) ;
}
F_144 ( V_15 , V_15 -> V_57 ) ;
if ( V_194 && ! ( V_15 -> V_16 & V_195 ) ) {
F_145 ( V_23 , V_15 -> V_57 , V_16 , V_107 ) ;
if ( V_15 -> V_196 )
F_146 ( V_23 , V_184 ) ;
else
F_147 ( V_23 , V_184 ) ;
}
return F_148 ( V_23 ) ;
}
static void F_149 ( struct V_14 * V_15 , void * V_197 )
{
unsigned long V_45 = ( 1 << V_15 -> V_57 ) ;
struct V_23 * V_23 = F_62 ( V_197 ) ;
const unsigned long V_198 = V_45 ;
F_150 ( V_23 , V_15 -> V_57 ) ;
if ( V_15 -> V_16 & V_187 )
F_151 ( F_141 ( V_23 ) ,
V_192 , V_198 ) ;
else
F_151 ( F_141 ( V_23 ) ,
V_193 , V_198 ) ;
while ( V_45 -- ) {
F_9 ( ! F_16 ( V_23 ) ) ;
F_152 ( V_23 ) ;
F_153 ( V_23 ) ;
V_23 ++ ;
}
F_154 ( V_15 , V_15 -> V_57 ) ;
if ( V_199 -> V_200 )
V_199 -> V_200 -> V_201 += V_198 ;
F_155 ( ( unsigned long ) V_197 , V_15 -> V_57 ) ;
}
static void F_156 ( struct V_202 * V_203 )
{
struct V_204 * V_204 = (struct V_204 * ) V_203 ;
struct V_14 * V_15 = V_204 -> V_15 ;
F_149 ( V_15 , V_204 -> V_197 ) ;
if ( F_27 ( V_15 ) )
F_157 ( V_15 -> V_205 , V_204 ) ;
}
static void F_158 ( struct V_14 * V_15 , unsigned long * V_197 ,
unsigned long V_206 )
{
int V_19 = V_15 -> V_207 ;
V_197 = ( unsigned long * ) & ( ( char * ) V_197 ) [ F_7 ( V_15 ) ] ;
if ( V_19 < 5 * sizeof( unsigned long ) )
return;
* V_197 ++ = 0x12345678 ;
* V_197 ++ = V_206 ;
* V_197 ++ = F_32 () ;
V_19 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_208 = & V_206 ;
unsigned long V_209 ;
while ( ! F_159 ( V_208 ) ) {
V_209 = * V_208 ++ ;
if ( F_160 ( V_209 ) ) {
* V_197 ++ = V_209 ;
V_19 -= sizeof( unsigned long ) ;
if ( V_19 <= sizeof( unsigned long ) )
break;
}
}
}
* V_197 ++ = 0x87654321 ;
}
static void F_161 ( struct V_14 * V_15 , void * V_197 , unsigned char V_210 )
{
int V_19 = V_15 -> V_207 ;
V_197 = & ( ( char * ) V_197 ) [ F_7 ( V_15 ) ] ;
memset ( V_197 , V_210 , V_19 ) ;
* ( unsigned char * ) ( V_197 + V_19 - 1 ) = V_211 ;
}
static void F_162 ( char * V_212 , int V_30 , int V_94 )
{
int V_45 ;
unsigned char error = 0 ;
int V_213 = 0 ;
F_37 ( V_68 L_8 , V_30 ) ;
for ( V_45 = 0 ; V_45 < V_94 ; V_45 ++ ) {
if ( V_212 [ V_30 + V_45 ] != V_214 ) {
error = V_212 [ V_30 + V_45 ] ;
V_213 ++ ;
}
}
F_163 ( V_215 , L_9 , 0 , 16 , 1 ,
& V_212 [ V_30 ] , V_94 , 1 ) ;
if ( V_213 == 1 ) {
error ^= V_214 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_37 ( V_68 L_10
L_11 ) ;
#ifdef F_164
F_37 ( V_68 L_12
L_13 ) ;
#else
F_37 ( V_68 L_14 ) ;
#endif
}
}
}
static void F_165 ( struct V_14 * V_15 , void * V_1 , int V_216 )
{
int V_45 , V_19 ;
char * V_217 ;
if ( V_15 -> V_16 & V_17 ) {
F_37 ( V_68 L_15 ,
* F_8 ( V_15 , V_1 ) ,
* F_10 ( V_15 , V_1 ) ) ;
}
if ( V_15 -> V_16 & V_18 ) {
F_37 ( V_68 L_16 ,
* F_11 ( V_15 , V_1 ) ,
* F_11 ( V_15 , V_1 ) ) ;
}
V_217 = ( char * ) V_1 + F_7 ( V_15 ) ;
V_19 = V_15 -> V_207 ;
for ( V_45 = 0 ; V_45 < V_19 && V_216 ; V_45 += 16 , V_216 -- ) {
int V_94 ;
V_94 = 16 ;
if ( V_45 + V_94 > V_19 )
V_94 = V_19 - V_45 ;
F_162 ( V_217 , V_45 , V_94 ) ;
}
}
static void F_166 ( struct V_14 * V_15 , void * V_1 )
{
char * V_217 ;
int V_19 , V_45 ;
int V_216 = 0 ;
V_217 = ( char * ) V_1 + F_7 ( V_15 ) ;
V_19 = V_15 -> V_207 ;
for ( V_45 = 0 ; V_45 < V_19 ; V_45 ++ ) {
char exp = V_214 ;
if ( V_45 == V_19 - 1 )
exp = V_211 ;
if ( V_217 [ V_45 ] != exp ) {
int V_94 ;
if ( V_216 == 0 ) {
F_37 ( V_68
L_17 ,
F_167 () , V_15 -> V_69 , V_217 , V_19 ) ;
F_165 ( V_15 , V_1 , 0 ) ;
}
V_45 = ( V_45 / 16 ) * 16 ;
V_94 = 16 ;
if ( V_45 + V_94 > V_19 )
V_94 = V_19 - V_45 ;
F_162 ( V_217 , V_45 , V_94 ) ;
V_45 += 16 ;
V_216 ++ ;
if ( V_216 > 5 )
break;
}
}
if ( V_216 != 0 ) {
struct V_25 * V_96 = F_14 ( V_1 ) ;
unsigned int V_218 ;
V_218 = F_18 ( V_15 , V_96 , V_1 ) ;
if ( V_218 ) {
V_1 = F_17 ( V_15 , V_96 , V_218 - 1 ) ;
V_217 = ( char * ) V_1 + F_7 ( V_15 ) ;
F_37 ( V_68 L_18 ,
V_217 , V_19 ) ;
F_165 ( V_15 , V_1 , 2 ) ;
}
if ( V_218 + 1 < V_15 -> V_60 ) {
V_1 = F_17 ( V_15 , V_96 , V_218 + 1 ) ;
V_217 = ( char * ) V_1 + F_7 ( V_15 ) ;
F_37 ( V_68 L_19 ,
V_217 , V_19 ) ;
F_165 ( V_15 , V_1 , 2 ) ;
}
}
}
static void F_168 ( struct V_14 * V_15 , struct V_25 * V_96 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_15 -> V_60 ; V_45 ++ ) {
void * V_1 = F_17 ( V_15 , V_96 , V_45 ) ;
if ( V_15 -> V_16 & V_219 ) {
#ifdef F_169
if ( V_15 -> V_19 % V_63 == 0 &&
F_27 ( V_15 ) )
F_170 ( F_62 ( V_1 ) ,
V_15 -> V_19 / V_63 , 1 ) ;
else
F_166 ( V_15 , V_1 ) ;
#else
F_166 ( V_15 , V_1 ) ;
#endif
}
if ( V_15 -> V_16 & V_17 ) {
if ( * F_8 ( V_15 , V_1 ) != V_220 )
F_171 ( V_15 , L_20
L_21 ) ;
if ( * F_10 ( V_15 , V_1 ) != V_220 )
F_171 ( V_15 , L_22
L_21 ) ;
}
}
}
static void F_168 ( struct V_14 * V_15 , struct V_25 * V_96 )
{
}
static void F_172 ( struct V_14 * V_15 , struct V_25 * V_96 )
{
void * V_197 = V_96 -> V_29 - V_96 -> V_221 ;
F_168 ( V_15 , V_96 ) ;
if ( F_51 ( V_15 -> V_16 & V_121 ) ) {
struct V_204 * V_204 ;
V_204 = (struct V_204 * ) V_96 ;
V_204 -> V_15 = V_15 ;
V_204 -> V_197 = V_197 ;
F_173 ( & V_204 -> V_203 , F_156 ) ;
} else {
F_149 ( V_15 , V_197 ) ;
if ( F_27 ( V_15 ) )
F_157 ( V_15 -> V_205 , V_96 ) ;
}
}
static T_2 F_174 ( struct V_14 * V_15 ,
T_2 V_19 , T_2 V_55 , unsigned long V_16 )
{
unsigned long V_222 ;
T_2 V_59 = 0 ;
int V_57 ;
for ( V_57 = 0 ; V_57 <= V_223 ; V_57 ++ ) {
unsigned int V_60 ;
T_2 V_224 ;
F_35 ( V_57 , V_19 , V_55 , V_16 , & V_224 , & V_60 ) ;
if ( ! V_60 )
continue;
if ( V_16 & V_64 ) {
V_222 = V_19 - sizeof( struct V_25 ) ;
V_222 /= sizeof( V_56 ) ;
if ( V_60 > V_222 )
break;
}
V_15 -> V_60 = V_60 ;
V_15 -> V_57 = V_57 ;
V_59 = V_224 ;
if ( V_16 & V_187 )
break;
if ( V_57 >= V_75 )
break;
if ( V_59 * 8 <= ( V_63 << V_57 ) )
break;
}
return V_59 ;
}
static int T_8 F_175 ( struct V_14 * V_15 , T_5 V_90 )
{
if ( V_46 >= V_174 )
return F_129 ( V_15 , V_90 ) ;
if ( V_46 == V_225 ) {
V_15 -> V_53 [ F_32 () ] = & V_171 . V_27 ;
V_46 = V_226 ;
} else if ( V_46 == V_226 ) {
V_15 -> V_53 [ F_32 () ] = & V_171 . V_27 ;
F_117 ( V_15 , V_172 ) ;
if ( V_166 == V_168 )
V_46 = V_227 ;
else
V_46 = V_228 ;
} else {
V_15 -> V_53 [ F_32 () ] =
F_126 ( sizeof( struct V_170 ) , V_90 ) ;
if ( V_46 == V_228 ) {
F_117 ( V_15 , V_173 ) ;
V_46 = V_227 ;
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
F_31 ( V_15 ) -> V_94 = V_229 ;
F_31 ( V_15 ) -> V_89 = 1 ;
F_31 ( V_15 ) -> V_95 = 0 ;
V_15 -> V_89 = 1 ;
V_15 -> V_94 = V_229 ;
return 0 ;
}
int
F_176 ( struct V_14 * V_15 , unsigned long V_16 )
{
T_2 V_59 , V_62 , V_230 ;
T_5 V_90 ;
int V_118 ;
T_2 V_19 = V_15 -> V_19 ;
#if V_231
#if V_232
if ( V_19 < 4096 || F_177 ( V_19 - 1 ) == F_177 ( V_19 - 1 + V_20 +
2 * sizeof( unsigned long long ) ) )
V_16 |= V_17 | V_18 ;
if ( ! ( V_16 & V_121 ) )
V_16 |= V_219 ;
#endif
if ( V_16 & V_121 )
F_9 ( V_16 & V_219 ) ;
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
if ( V_230 < V_15 -> V_55 ) {
V_230 = V_15 -> V_55 ;
}
if ( V_230 > F_178 (unsigned long long) )
V_16 &= ~ ( V_17 | V_18 ) ;
V_15 -> V_55 = V_230 ;
if ( F_179 () )
V_90 = V_109 ;
else
V_90 = V_155 ;
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
#if V_232 && F_180 ( F_169 )
if ( V_19 >= F_125 ( V_168 + 1 )
&& V_15 -> V_207 > F_181 ()
&& F_34 ( V_19 , V_15 -> V_55 ) < V_63 ) {
V_15 -> F_7 += V_63 - F_34 ( V_19 , V_15 -> V_55 ) ;
V_19 = V_63 ;
}
#endif
#endif
if ( ( V_19 >= ( V_63 >> 3 ) ) && ! V_169 &&
! ( V_16 & V_233 ) )
V_16 |= V_64 ;
V_19 = F_34 ( V_19 , V_15 -> V_55 ) ;
V_59 = F_174 ( V_15 , V_19 , V_15 -> V_55 , V_16 ) ;
if ( ! V_15 -> V_60 )
return - V_234 ;
V_62 = F_34 ( V_15 -> V_60 * sizeof( V_56 )
+ sizeof( struct V_25 ) , V_15 -> V_55 ) ;
if ( V_16 & V_64 && V_59 >= V_62 ) {
V_16 &= ~ V_64 ;
V_59 -= V_62 ;
}
if ( V_16 & V_64 ) {
V_62 =
V_15 -> V_60 * sizeof( V_56 ) + sizeof( struct V_25 ) ;
#ifdef F_182
if ( V_19 % V_63 == 0 && V_16 & V_219 )
V_16 &= ~ ( V_17 | V_18 ) ;
#endif
}
V_15 -> V_235 = F_181 () ;
if ( V_15 -> V_235 < V_15 -> V_55 )
V_15 -> V_235 = V_15 -> V_55 ;
V_15 -> V_236 = V_59 / V_15 -> V_235 ;
V_15 -> V_62 = V_62 ;
V_15 -> V_16 = V_16 ;
V_15 -> V_186 = 0 ;
if ( V_237 && ( V_16 & V_238 ) )
V_15 -> V_186 |= V_239 ;
V_15 -> V_19 = V_19 ;
V_15 -> V_31 = F_183 ( V_19 ) ;
if ( V_16 & V_64 ) {
V_15 -> V_205 = F_184 ( V_62 , 0u ) ;
F_9 ( F_185 ( V_15 -> V_205 ) ) ;
}
V_118 = F_175 ( V_15 , V_90 ) ;
if ( V_118 ) {
F_186 ( V_15 ) ;
return V_118 ;
}
if ( V_16 & V_120 ) {
F_187 ( V_16 & V_121 ) ;
F_24 ( V_15 ) ;
} else if ( ! F_27 ( V_15 ) && ! ( V_16 & V_121 ) )
F_29 ( V_15 ) ;
return 0 ;
}
static void F_188 ( void )
{
F_9 ( ! F_189 () ) ;
}
static void F_190 ( void )
{
F_9 ( F_189 () ) ;
}
static void F_191 ( struct V_14 * V_15 )
{
#ifdef F_192
F_188 () ;
F_193 ( & V_15 -> V_40 [ F_65 () ] -> V_11 ) ;
#endif
}
static void F_194 ( struct V_14 * V_15 , int V_40 )
{
#ifdef F_192
F_188 () ;
F_193 ( & V_15 -> V_40 [ V_40 ] -> V_11 ) ;
#endif
}
static void F_195 ( void * V_142 )
{
struct V_14 * V_15 = V_142 ;
struct V_36 * V_97 ;
int V_40 = F_65 () ;
F_188 () ;
V_97 = F_31 ( V_15 ) ;
F_88 ( & V_15 -> V_40 [ V_40 ] -> V_11 ) ;
F_89 ( V_15 , V_97 -> V_101 , V_97 -> V_93 , V_40 ) ;
F_90 ( & V_15 -> V_40 [ V_40 ] -> V_11 ) ;
V_97 -> V_93 = 0 ;
}
static void F_196 ( struct V_14 * V_15 )
{
struct V_3 * V_38 ;
int V_40 ;
F_197 ( F_195 , V_15 , 1 ) ;
F_190 () ;
F_25 (node) {
V_38 = V_15 -> V_40 [ V_40 ] ;
if ( V_38 && V_38 -> V_9 )
F_94 ( V_15 , V_38 -> V_9 ) ;
}
F_25 (node) {
V_38 = V_15 -> V_40 [ V_40 ] ;
if ( V_38 )
F_198 ( V_15 , V_38 , V_38 -> V_8 , 1 , V_40 ) ;
}
}
static int F_104 ( struct V_14 * V_27 ,
struct V_3 * V_38 , int V_240 )
{
struct V_241 * V_242 ;
int V_198 ;
struct V_25 * V_96 ;
V_198 = 0 ;
while ( V_198 < V_240 && ! F_71 ( & V_38 -> V_7 ) ) {
F_99 ( & V_38 -> V_11 ) ;
V_242 = V_38 -> V_7 . V_243 ;
if ( V_242 == & V_38 -> V_7 ) {
F_93 ( & V_38 -> V_11 ) ;
goto V_99;
}
V_96 = F_199 ( V_242 , struct V_25 , V_153 ) ;
#if V_231
F_9 ( V_96 -> V_183 ) ;
#endif
F_200 ( & V_96 -> V_153 ) ;
V_38 -> V_12 -= V_27 -> V_60 ;
F_93 ( & V_38 -> V_11 ) ;
F_172 ( V_27 , V_96 ) ;
V_198 ++ ;
}
V_99:
return V_198 ;
}
static int F_201 ( struct V_14 * V_15 )
{
int V_139 = 0 , V_45 = 0 ;
struct V_3 * V_38 ;
F_196 ( V_15 ) ;
F_190 () ;
F_25 (i) {
V_38 = V_15 -> V_40 [ V_45 ] ;
if ( ! V_38 )
continue;
F_104 ( V_15 , V_38 , V_38 -> V_12 ) ;
V_139 += ! F_71 ( & V_38 -> V_5 ) ||
! F_71 ( & V_38 -> V_6 ) ;
}
return ( V_139 ? 1 : 0 ) ;
}
int F_202 ( struct V_14 * V_15 )
{
int V_139 ;
F_9 ( ! V_15 || F_203 () ) ;
F_204 () ;
F_108 ( & V_128 ) ;
V_139 = F_201 ( V_15 ) ;
F_109 ( & V_128 ) ;
F_205 () ;
return V_139 ;
}
int F_186 ( struct V_14 * V_15 )
{
int V_45 ;
struct V_3 * V_38 ;
int V_244 = F_201 ( V_15 ) ;
if ( V_244 )
return V_244 ;
F_134 (i)
F_86 ( V_15 -> V_53 [ V_45 ] ) ;
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
static struct V_25 * F_206 ( struct V_14 * V_15 , void * V_1 ,
int V_235 , T_5 V_245 ,
int V_107 )
{
struct V_25 * V_96 ;
if ( F_27 ( V_15 ) ) {
V_96 = F_207 ( V_15 -> V_205 ,
V_245 , V_107 ) ;
F_208 ( & V_96 -> V_153 , sizeof( struct V_241 ) ,
V_245 ) ;
if ( ! V_96 )
return NULL ;
} else {
V_96 = V_1 + V_235 ;
V_235 += V_15 -> V_62 ;
}
V_96 -> V_183 = 0 ;
V_96 -> V_221 = V_235 ;
V_96 -> V_29 = V_1 + V_235 ;
V_96 -> V_107 = V_107 ;
V_96 -> free = 0 ;
return V_96 ;
}
static inline V_56 * F_209 ( struct V_25 * V_96 )
{
return ( V_56 * ) ( V_96 + 1 ) ;
}
static void F_210 ( struct V_14 * V_15 ,
struct V_25 * V_96 )
{
int V_45 ;
for ( V_45 = 0 ; V_45 < V_15 -> V_60 ; V_45 ++ ) {
void * V_1 = F_17 ( V_15 , V_96 , V_45 ) ;
#if V_231
if ( V_15 -> V_16 & V_219 )
F_161 ( V_15 , V_1 , V_214 ) ;
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = NULL ;
if ( V_15 -> V_16 & V_17 ) {
* F_8 ( V_15 , V_1 ) = V_220 ;
* F_10 ( V_15 , V_1 ) = V_220 ;
}
if ( V_15 -> V_196 && ! ( V_15 -> V_16 & V_219 ) )
V_15 -> V_196 ( V_1 + F_7 ( V_15 ) ) ;
if ( V_15 -> V_16 & V_17 ) {
if ( * F_10 ( V_15 , V_1 ) != V_220 )
F_171 ( V_15 , L_23
L_24 ) ;
if ( * F_8 ( V_15 , V_1 ) != V_220 )
F_171 ( V_15 , L_23
L_25 ) ;
}
if ( ( V_15 -> V_19 % V_63 ) == 0 &&
F_27 ( V_15 ) && V_15 -> V_16 & V_219 )
F_170 ( F_62 ( V_1 ) ,
V_15 -> V_19 / V_63 , 0 ) ;
#else
if ( V_15 -> V_196 )
V_15 -> V_196 ( V_1 ) ;
#endif
F_209 ( V_96 ) [ V_45 ] = V_45 + 1 ;
}
F_209 ( V_96 ) [ V_45 - 1 ] = V_246 ;
}
static void F_211 ( struct V_14 * V_15 , T_5 V_16 )
{
if ( V_237 ) {
if ( V_16 & V_239 )
F_9 ( ! ( V_15 -> V_186 & V_239 ) ) ;
else
F_9 ( V_15 -> V_186 & V_239 ) ;
}
}
static void * F_212 ( struct V_14 * V_15 , struct V_25 * V_96 ,
int V_107 )
{
void * V_1 = F_17 ( V_15 , V_96 , V_96 -> free ) ;
V_56 V_247 ;
V_96 -> V_183 ++ ;
V_247 = F_209 ( V_96 ) [ V_96 -> free ] ;
#if V_231
F_209 ( V_96 ) [ V_96 -> free ] = V_248 ;
F_213 ( V_96 -> V_107 != V_107 ) ;
#endif
V_96 -> free = V_247 ;
return V_1 ;
}
static void F_214 ( struct V_14 * V_15 , struct V_25 * V_96 ,
void * V_1 , int V_107 )
{
unsigned int V_218 = F_18 ( V_15 , V_96 , V_1 ) ;
#if V_231
F_213 ( V_96 -> V_107 != V_107 ) ;
if ( F_209 ( V_96 ) [ V_218 ] + 1 <= V_65 + 1 ) {
F_37 ( V_68 L_26
L_27 , V_15 -> V_69 , V_1 ) ;
F_130 () ;
}
#endif
F_209 ( V_96 ) [ V_218 ] = V_96 -> free ;
V_96 -> free = V_218 ;
V_96 -> V_183 -- ;
}
static void F_215 ( struct V_14 * V_27 , struct V_25 * V_25 ,
void * V_197 )
{
int V_184 ;
struct V_23 * V_23 ;
V_23 = F_62 ( V_197 ) ;
V_184 = 1 ;
if ( F_95 ( ! F_216 ( V_23 ) ) )
V_184 <<= V_27 -> V_57 ;
do {
V_23 -> V_24 = V_27 ;
V_23 -> V_26 = V_25 ;
V_23 ++ ;
} while ( -- V_184 );
}
static int F_217 ( struct V_14 * V_15 ,
T_5 V_16 , int V_107 , void * V_1 )
{
struct V_25 * V_96 ;
T_2 V_30 ;
T_5 V_245 ;
struct V_3 * V_38 ;
F_9 ( V_16 & V_249 ) ;
V_245 = V_16 & ( V_250 | V_251 ) ;
F_188 () ;
V_38 = V_15 -> V_40 [ V_107 ] ;
F_88 ( & V_38 -> V_11 ) ;
V_30 = V_38 -> V_10 ;
V_38 -> V_10 ++ ;
if ( V_38 -> V_10 >= V_15 -> V_236 )
V_38 -> V_10 = 0 ;
F_90 ( & V_38 -> V_11 ) ;
V_30 *= V_15 -> V_235 ;
if ( V_245 & V_252 )
F_218 () ;
F_211 ( V_15 , V_16 ) ;
if ( ! V_1 )
V_1 = F_136 ( V_15 , V_245 , V_107 ) ;
if ( ! V_1 )
goto V_253;
V_96 = F_206 ( V_15 , V_1 , V_30 ,
V_245 & ~ V_250 , V_107 ) ;
if ( ! V_96 )
goto V_254;
F_215 ( V_15 , V_96 , V_1 ) ;
F_210 ( V_15 , V_96 ) ;
if ( V_245 & V_252 )
F_219 () ;
F_188 () ;
F_88 ( & V_38 -> V_11 ) ;
F_220 ( & V_96 -> V_153 , & ( V_38 -> V_7 ) ) ;
F_221 ( V_15 ) ;
V_38 -> V_12 += V_15 -> V_60 ;
F_90 ( & V_38 -> V_11 ) ;
return 1 ;
V_254:
F_149 ( V_15 , V_1 ) ;
V_253:
if ( V_245 & V_252 )
F_219 () ;
return 0 ;
}
static void F_222 ( const void * V_1 )
{
if ( ! F_223 ( V_1 ) ) {
F_37 ( V_68 L_28 ,
( unsigned long ) V_1 ) ;
F_130 () ;
}
}
static inline void F_224 ( struct V_14 * V_27 , void * V_22 )
{
unsigned long long V_255 , V_256 ;
V_255 = * F_8 ( V_27 , V_22 ) ;
V_256 = * F_10 ( V_27 , V_22 ) ;
if ( V_255 == V_257 && V_256 == V_257 )
return;
if ( V_255 == V_220 && V_256 == V_220 )
F_171 ( V_27 , L_29 ) ;
else
F_171 ( V_27 , L_30 ) ;
F_37 ( V_68 L_31 ,
V_22 , V_255 , V_256 ) ;
}
static void * F_225 ( struct V_14 * V_15 , void * V_1 ,
unsigned long V_206 )
{
struct V_23 * V_23 ;
unsigned int V_218 ;
struct V_25 * V_96 ;
F_9 ( F_12 ( V_1 ) != V_15 ) ;
V_1 -= F_7 ( V_15 ) ;
F_222 ( V_1 ) ;
V_23 = F_13 ( V_1 ) ;
V_96 = V_23 -> V_26 ;
if ( V_15 -> V_16 & V_17 ) {
F_224 ( V_15 , V_1 ) ;
* F_8 ( V_15 , V_1 ) = V_220 ;
* F_10 ( V_15 , V_1 ) = V_220 ;
}
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = ( void * ) V_206 ;
V_218 = F_18 ( V_15 , V_96 , V_1 ) ;
F_9 ( V_218 >= V_15 -> V_60 ) ;
F_9 ( V_1 != F_17 ( V_15 , V_96 , V_218 ) ) ;
#ifdef F_226
F_209 ( V_96 ) [ V_218 ] = V_248 ;
#endif
if ( V_15 -> V_16 & V_219 ) {
#ifdef F_169
if ( ( V_15 -> V_19 % V_63 ) == 0 && F_27 ( V_15 ) ) {
F_158 ( V_15 , V_1 , V_206 ) ;
F_170 ( F_62 ( V_1 ) ,
V_15 -> V_19 / V_63 , 0 ) ;
} else {
F_161 ( V_15 , V_1 , V_214 ) ;
}
#else
F_161 ( V_15 , V_1 , V_214 ) ;
#endif
}
return V_1 ;
}
static void F_227 ( struct V_14 * V_15 , struct V_25 * V_96 )
{
V_56 V_45 ;
int V_88 = 0 ;
for ( V_45 = V_96 -> free ; V_45 != V_246 ; V_45 = F_209 ( V_96 ) [ V_45 ] ) {
V_88 ++ ;
if ( V_88 > V_15 -> V_60 || V_45 >= V_15 -> V_60 )
goto V_119;
}
if ( V_88 != V_15 -> V_60 - V_96 -> V_183 ) {
V_119:
F_37 ( V_68 L_32
L_33 ,
V_15 -> V_69 , V_15 -> V_60 , V_96 , V_96 -> V_183 ,
F_167 () ) ;
F_163 ( V_68 , L_9 , V_258 , 16 , 1 , V_96 ,
sizeof( * V_96 ) + V_15 -> V_60 * sizeof( V_56 ) ,
1 ) ;
F_130 () ;
}
}
static void * F_228 ( struct V_14 * V_15 , T_5 V_16 ,
bool V_100 )
{
int V_89 ;
struct V_3 * V_38 ;
struct V_36 * V_97 ;
int V_40 ;
F_188 () ;
V_40 = F_65 () ;
if ( F_51 ( V_100 ) )
goto V_259;
V_260:
V_97 = F_31 ( V_15 ) ;
V_89 = V_97 -> V_89 ;
if ( ! V_97 -> V_95 && V_89 > V_261 ) {
V_89 = V_261 ;
}
V_38 = V_15 -> V_40 [ V_40 ] ;
F_9 ( V_97 -> V_93 > 0 || ! V_38 ) ;
F_88 ( & V_38 -> V_11 ) ;
if ( V_38 -> V_8 && F_77 ( V_97 , V_38 -> V_8 , V_89 ) ) {
V_38 -> V_8 -> V_95 = 1 ;
goto V_262;
}
while ( V_89 > 0 ) {
struct V_241 * V_101 ;
struct V_25 * V_96 ;
V_101 = V_38 -> V_6 . V_247 ;
if ( V_101 == & V_38 -> V_6 ) {
V_38 -> V_13 = 1 ;
V_101 = V_38 -> V_7 . V_247 ;
if ( V_101 == & V_38 -> V_7 )
goto V_263;
}
V_96 = F_199 ( V_101 , struct V_25 , V_153 ) ;
F_227 ( V_15 , V_96 ) ;
F_191 ( V_15 ) ;
F_9 ( V_96 -> V_183 >= V_15 -> V_60 ) ;
while ( V_96 -> V_183 < V_15 -> V_60 && V_89 -- ) {
F_229 ( V_15 ) ;
F_230 ( V_15 ) ;
F_231 ( V_15 ) ;
F_76 ( V_15 , V_97 , F_212 ( V_15 , V_96 ,
V_40 ) ) ;
}
F_227 ( V_15 , V_96 ) ;
F_200 ( & V_96 -> V_153 ) ;
if ( V_96 -> free == V_246 )
F_123 ( & V_96 -> V_153 , & V_38 -> V_5 ) ;
else
F_123 ( & V_96 -> V_153 , & V_38 -> V_6 ) ;
}
V_263:
V_38 -> V_12 -= V_97 -> V_93 ;
V_262:
F_90 ( & V_38 -> V_11 ) ;
if ( F_51 ( ! V_97 -> V_93 ) ) {
int V_264 ;
V_259:
V_264 = F_217 ( V_15 , V_16 | V_265 , V_40 , NULL ) ;
V_97 = F_31 ( V_15 ) ;
V_40 = F_65 () ;
if ( ! V_264 && ( V_97 -> V_93 == 0 || V_100 ) )
return NULL ;
if ( ! V_97 -> V_93 )
goto V_260;
}
V_97 -> V_95 = 1 ;
return F_73 ( V_15 , V_97 , V_16 , V_100 ) ;
}
static inline void F_232 ( struct V_14 * V_15 ,
T_5 V_16 )
{
F_233 ( V_16 & V_252 ) ;
#if V_231
F_211 ( V_15 , V_16 ) ;
#endif
}
static void * F_234 ( struct V_14 * V_15 ,
T_5 V_16 , void * V_1 , unsigned long V_206 )
{
if ( ! V_1 )
return V_1 ;
if ( V_15 -> V_16 & V_219 ) {
#ifdef F_169
if ( ( V_15 -> V_19 % V_63 ) == 0 && F_27 ( V_15 ) )
F_170 ( F_62 ( V_1 ) ,
V_15 -> V_19 / V_63 , 1 ) ;
else
F_166 ( V_15 , V_1 ) ;
#else
F_166 ( V_15 , V_1 ) ;
#endif
F_161 ( V_15 , V_1 , V_266 ) ;
}
if ( V_15 -> V_16 & V_18 )
* F_11 ( V_15 , V_1 ) = ( void * ) V_206 ;
if ( V_15 -> V_16 & V_17 ) {
if ( * F_8 ( V_15 , V_1 ) != V_220 ||
* F_10 ( V_15 , V_1 ) != V_220 ) {
F_171 ( V_15 , L_34
L_35 ) ;
F_37 ( V_68
L_36 ,
V_1 , * F_8 ( V_15 , V_1 ) ,
* F_10 ( V_15 , V_1 ) ) ;
}
* F_8 ( V_15 , V_1 ) = V_257 ;
* F_10 ( V_15 , V_1 ) = V_257 ;
}
#ifdef F_226
{
struct V_25 * V_96 ;
unsigned V_218 ;
V_96 = F_13 ( V_1 ) -> V_26 ;
V_218 = ( unsigned ) ( V_1 - V_96 -> V_29 ) / V_15 -> V_19 ;
F_209 ( V_96 ) [ V_218 ] = V_267 ;
}
#endif
V_1 += F_7 ( V_15 ) ;
if ( V_15 -> V_196 && V_15 -> V_16 & V_219 )
V_15 -> V_196 ( V_1 ) ;
if ( V_268 &&
( ( unsigned long ) V_1 & ( V_268 - 1 ) ) ) {
F_37 ( V_68 L_37 ,
V_1 , ( int ) V_268 ) ;
}
return V_1 ;
}
static bool F_235 ( struct V_14 * V_15 , T_5 V_16 )
{
if ( V_15 == V_14 )
return false ;
return F_236 ( V_15 -> V_207 , V_16 , V_15 -> V_16 ) ;
}
static inline void * F_237 ( struct V_14 * V_15 , T_5 V_16 )
{
void * V_1 ;
struct V_36 * V_97 ;
bool V_100 = false ;
F_188 () ;
V_97 = F_31 ( V_15 ) ;
if ( F_95 ( V_97 -> V_93 ) ) {
V_97 -> V_95 = 1 ;
V_1 = F_73 ( V_15 , V_97 , V_16 , false ) ;
if ( V_1 ) {
F_238 ( V_15 ) ;
goto V_99;
}
V_100 = true ;
}
F_239 ( V_15 ) ;
V_1 = F_228 ( V_15 , V_16 , V_100 ) ;
V_97 = F_31 ( V_15 ) ;
V_99:
if ( V_1 )
F_240 ( & V_97 -> V_101 [ V_97 -> V_93 ] ) ;
return V_1 ;
}
static void * F_82 ( struct V_14 * V_15 , T_5 V_16 )
{
int V_269 , V_270 ;
if ( F_203 () || ( V_16 & V_271 ) )
return NULL ;
V_269 = V_270 = F_65 () ;
if ( F_241 () && ( V_15 -> V_16 & V_272 ) )
V_269 = F_242 () ;
else if ( V_199 -> V_273 )
V_269 = F_243 () ;
if ( V_269 != V_270 )
return F_83 ( V_15 , V_16 , V_269 ) ;
return NULL ;
}
static void * F_244 ( struct V_14 * V_27 , T_5 V_16 )
{
struct V_274 * V_274 ;
T_5 V_245 ;
struct V_275 * V_276 ;
struct V_277 * V_277 ;
enum V_278 V_279 = F_245 ( V_16 ) ;
void * V_22 = NULL ;
int V_145 ;
unsigned int V_280 ;
if ( V_16 & V_271 )
return NULL ;
V_245 = V_16 & ( V_250 | V_251 ) ;
V_281:
V_280 = F_246 () ;
V_274 = F_247 ( F_243 () , V_16 ) ;
V_260:
F_248 (zone, z, zonelist, high_zoneidx) {
V_145 = F_249 ( V_277 ) ;
if ( F_250 ( V_277 , V_16 ) &&
V_27 -> V_40 [ V_145 ] &&
V_27 -> V_40 [ V_145 ] -> V_12 ) {
V_22 = F_83 ( V_27 ,
V_16 | V_265 , V_145 ) ;
if ( V_22 )
break;
}
}
if ( ! V_22 ) {
if ( V_245 & V_252 )
F_218 () ;
F_211 ( V_27 , V_16 ) ;
V_22 = F_136 ( V_27 , V_245 , F_65 () ) ;
if ( V_245 & V_252 )
F_219 () ;
if ( V_22 ) {
V_145 = F_251 ( F_62 ( V_22 ) ) ;
if ( F_217 ( V_27 , V_16 , V_145 , V_22 ) ) {
V_22 = F_83 ( V_27 ,
V_16 | V_265 , V_145 ) ;
if ( ! V_22 )
goto V_260;
} else {
V_22 = NULL ;
}
}
}
if ( F_51 ( ! F_252 ( V_280 ) && ! V_22 ) )
goto V_281;
return V_22 ;
}
static void * F_83 ( struct V_14 * V_15 , T_5 V_16 ,
int V_107 )
{
struct V_241 * V_101 ;
struct V_25 * V_96 ;
struct V_3 * V_38 ;
void * V_22 ;
int V_264 ;
F_15 ( V_107 > F_253 () ) ;
V_38 = V_15 -> V_40 [ V_107 ] ;
F_9 ( ! V_38 ) ;
V_260:
F_188 () ;
F_88 ( & V_38 -> V_11 ) ;
V_101 = V_38 -> V_6 . V_247 ;
if ( V_101 == & V_38 -> V_6 ) {
V_38 -> V_13 = 1 ;
V_101 = V_38 -> V_7 . V_247 ;
if ( V_101 == & V_38 -> V_7 )
goto V_263;
}
V_96 = F_199 ( V_101 , struct V_25 , V_153 ) ;
F_194 ( V_15 , V_107 ) ;
F_227 ( V_15 , V_96 ) ;
F_254 ( V_15 ) ;
F_230 ( V_15 ) ;
F_231 ( V_15 ) ;
F_9 ( V_96 -> V_183 == V_15 -> V_60 ) ;
V_22 = F_212 ( V_15 , V_96 , V_107 ) ;
F_227 ( V_15 , V_96 ) ;
V_38 -> V_12 -- ;
F_200 ( & V_96 -> V_153 ) ;
if ( V_96 -> free == V_246 )
F_123 ( & V_96 -> V_153 , & V_38 -> V_5 ) ;
else
F_123 ( & V_96 -> V_153 , & V_38 -> V_6 ) ;
F_90 ( & V_38 -> V_11 ) ;
goto V_282;
V_263:
F_90 ( & V_38 -> V_11 ) ;
V_264 = F_217 ( V_15 , V_16 | V_265 , V_107 , NULL ) ;
if ( V_264 )
goto V_260;
return F_244 ( V_15 , V_16 ) ;
V_282:
return V_22 ;
}
static T_9 void *
F_255 ( struct V_14 * V_15 , T_5 V_16 , int V_107 ,
unsigned long V_206 )
{
unsigned long V_283 ;
void * V_154 ;
int F_243 = F_65 () ;
V_16 &= V_284 ;
F_256 ( V_16 ) ;
if ( F_235 ( V_15 , V_16 ) )
return NULL ;
V_15 = F_257 ( V_15 , V_16 ) ;
F_232 ( V_15 , V_16 ) ;
F_258 ( V_283 ) ;
if ( V_107 == V_285 )
V_107 = F_243 ;
if ( F_51 ( ! V_15 -> V_40 [ V_107 ] ) ) {
V_154 = F_244 ( V_15 , V_16 ) ;
goto V_99;
}
if ( V_107 == F_243 ) {
V_154 = F_237 ( V_15 , V_16 ) ;
if ( V_154 )
goto V_99;
}
V_154 = F_83 ( V_15 , V_16 , V_107 ) ;
V_99:
F_259 ( V_283 ) ;
V_154 = F_234 ( V_15 , V_16 , V_154 , V_206 ) ;
F_260 ( V_154 , V_15 -> V_207 , 1 , V_15 -> V_16 ,
V_16 ) ;
if ( F_95 ( V_154 ) )
F_261 ( V_15 , V_16 , V_154 , V_15 -> V_207 ) ;
if ( F_51 ( ( V_16 & V_286 ) && V_154 ) )
memset ( V_154 , 0 , V_15 -> V_207 ) ;
return V_154 ;
}
static T_9 void *
F_262 ( struct V_14 * V_27 , T_5 V_16 )
{
void * V_1 ;
if ( F_51 ( V_199 -> V_16 & ( V_287 | V_288 ) ) ) {
V_1 = F_82 ( V_27 , V_16 ) ;
if ( V_1 )
goto V_99;
}
V_1 = F_237 ( V_27 , V_16 ) ;
if ( ! V_1 )
V_1 = F_83 ( V_27 , V_16 , F_65 () ) ;
V_99:
return V_1 ;
}
static T_9 void *
F_262 ( struct V_14 * V_15 , T_5 V_16 )
{
return F_237 ( V_15 , V_16 ) ;
}
static T_9 void *
F_263 ( struct V_14 * V_15 , T_5 V_16 , unsigned long V_206 )
{
unsigned long V_283 ;
void * V_1 ;
V_16 &= V_284 ;
F_256 ( V_16 ) ;
if ( F_235 ( V_15 , V_16 ) )
return NULL ;
V_15 = F_257 ( V_15 , V_16 ) ;
F_232 ( V_15 , V_16 ) ;
F_258 ( V_283 ) ;
V_1 = F_262 ( V_15 , V_16 ) ;
F_259 ( V_283 ) ;
V_1 = F_234 ( V_15 , V_16 , V_1 , V_206 ) ;
F_260 ( V_1 , V_15 -> V_207 , 1 , V_15 -> V_16 ,
V_16 ) ;
F_264 ( V_1 ) ;
if ( F_95 ( V_1 ) )
F_261 ( V_15 , V_16 , V_1 , V_15 -> V_207 ) ;
if ( F_51 ( ( V_16 & V_286 ) && V_1 ) )
memset ( V_1 , 0 , V_15 -> V_207 ) ;
return V_1 ;
}
static void F_89 ( struct V_14 * V_15 , void * * V_289 , int V_290 ,
int V_40 )
{
int V_45 ;
struct V_3 * V_38 ;
for ( V_45 = 0 ; V_45 < V_290 ; V_45 ++ ) {
void * V_1 ;
struct V_25 * V_96 ;
F_3 ( & V_289 [ V_45 ] ) ;
V_1 = V_289 [ V_45 ] ;
V_96 = F_14 ( V_1 ) ;
V_38 = V_15 -> V_40 [ V_40 ] ;
F_200 ( & V_96 -> V_153 ) ;
F_194 ( V_15 , V_40 ) ;
F_227 ( V_15 , V_96 ) ;
F_214 ( V_15 , V_96 , V_1 , V_40 ) ;
F_265 ( V_15 ) ;
V_38 -> V_12 ++ ;
F_227 ( V_15 , V_96 ) ;
if ( V_96 -> V_183 == 0 ) {
if ( V_38 -> V_12 > V_38 -> V_114 ) {
V_38 -> V_12 -= V_15 -> V_60 ;
F_172 ( V_15 , V_96 ) ;
} else {
F_123 ( & V_96 -> V_153 , & V_38 -> V_7 ) ;
}
} else {
F_220 ( & V_96 -> V_153 , & V_38 -> V_6 ) ;
}
}
}
static void F_266 ( struct V_14 * V_15 , struct V_36 * V_97 )
{
int V_89 ;
struct V_3 * V_38 ;
int V_40 = F_65 () ;
V_89 = V_97 -> V_89 ;
#if V_231
F_9 ( ! V_89 || V_89 > V_97 -> V_93 ) ;
#endif
F_188 () ;
V_38 = V_15 -> V_40 [ V_40 ] ;
F_88 ( & V_38 -> V_11 ) ;
if ( V_38 -> V_8 ) {
struct V_36 * V_291 = V_38 -> V_8 ;
int V_104 = V_291 -> V_94 - V_291 -> V_93 ;
if ( V_104 ) {
if ( V_89 > V_104 )
V_89 = V_104 ;
memcpy ( & ( V_291 -> V_101 [ V_291 -> V_93 ] ) ,
V_97 -> V_101 , sizeof( void * ) * V_89 ) ;
V_291 -> V_93 += V_89 ;
goto V_292;
}
}
F_89 ( V_15 , V_97 -> V_101 , V_89 , V_40 ) ;
V_292:
#if V_293
{
int V_45 = 0 ;
struct V_241 * V_242 ;
V_242 = V_38 -> V_7 . V_247 ;
while ( V_242 != & ( V_38 -> V_7 ) ) {
struct V_25 * V_96 ;
V_96 = F_199 ( V_242 , struct V_25 , V_153 ) ;
F_9 ( V_96 -> V_183 ) ;
V_45 ++ ;
V_242 = V_242 -> V_247 ;
}
F_267 ( V_15 , V_45 ) ;
}
#endif
F_90 ( & V_38 -> V_11 ) ;
V_97 -> V_93 -= V_89 ;
memmove ( V_97 -> V_101 , & ( V_97 -> V_101 [ V_89 ] ) , sizeof( void * ) * V_97 -> V_93 ) ;
}
static inline void F_268 ( struct V_14 * V_15 , void * V_1 ,
unsigned long V_206 )
{
struct V_36 * V_97 = F_31 ( V_15 ) ;
F_188 () ;
F_269 ( V_1 , V_15 -> V_16 ) ;
V_1 = F_225 ( V_15 , V_1 , V_206 ) ;
F_270 ( V_15 , V_1 , V_15 -> V_207 ) ;
if ( V_294 > 1 && F_81 ( V_15 , V_1 ) )
return;
if ( F_95 ( V_97 -> V_93 < V_97 -> V_94 ) ) {
F_271 ( V_15 ) ;
} else {
F_272 ( V_15 ) ;
F_266 ( V_15 , V_97 ) ;
}
F_76 ( V_15 , V_97 , V_1 ) ;
}
void * F_273 ( struct V_14 * V_15 , T_5 V_16 )
{
void * V_139 = F_263 ( V_15 , V_16 , V_295 ) ;
F_274 ( V_295 , V_139 ,
V_15 -> V_207 , V_15 -> V_19 , V_16 ) ;
return V_139 ;
}
void *
F_275 ( struct V_14 * V_15 , T_5 V_16 , T_2 V_19 )
{
void * V_139 ;
V_139 = F_263 ( V_15 , V_16 , V_295 ) ;
F_276 ( V_295 , V_139 ,
V_19 , V_15 -> V_19 , V_16 ) ;
return V_139 ;
}
void * F_207 ( struct V_14 * V_15 , T_5 V_16 , int V_107 )
{
void * V_139 = F_255 ( V_15 , V_16 , V_107 , V_295 ) ;
F_277 ( V_295 , V_139 ,
V_15 -> V_207 , V_15 -> V_19 ,
V_16 , V_107 ) ;
return V_139 ;
}
void * F_278 ( struct V_14 * V_15 ,
T_5 V_16 ,
int V_107 ,
T_2 V_19 )
{
void * V_139 ;
V_139 = F_255 ( V_15 , V_16 , V_107 , V_295 ) ;
F_279 ( V_295 , V_139 ,
V_19 , V_15 -> V_19 ,
V_16 , V_107 ) ;
return V_139 ;
}
static T_9 void *
F_280 ( T_2 V_19 , T_5 V_16 , int V_40 , unsigned long V_206 )
{
struct V_14 * V_15 ;
V_15 = F_184 ( V_19 , V_16 ) ;
if ( F_51 ( F_185 ( V_15 ) ) )
return V_15 ;
return F_278 ( V_15 , V_16 , V_40 , V_19 ) ;
}
void * F_281 ( T_2 V_19 , T_5 V_16 , int V_40 )
{
return F_280 ( V_19 , V_16 , V_40 , V_295 ) ;
}
void * F_282 ( T_2 V_19 , T_5 V_16 ,
int V_40 , unsigned long V_206 )
{
return F_280 ( V_19 , V_16 , V_40 , V_206 ) ;
}
void * F_281 ( T_2 V_19 , T_5 V_16 , int V_40 )
{
return F_280 ( V_19 , V_16 , V_40 , 0 ) ;
}
static T_9 void * F_283 ( T_2 V_19 , T_5 V_16 ,
unsigned long V_206 )
{
struct V_14 * V_15 ;
void * V_139 ;
V_15 = F_184 ( V_19 , V_16 ) ;
if ( F_51 ( F_185 ( V_15 ) ) )
return V_15 ;
V_139 = F_263 ( V_15 , V_16 , V_206 ) ;
F_276 ( V_206 , V_139 ,
V_19 , V_15 -> V_19 , V_16 ) ;
return V_139 ;
}
void * F_284 ( T_2 V_19 , T_5 V_16 )
{
return F_283 ( V_19 , V_16 , V_295 ) ;
}
void * F_285 ( T_2 V_19 , T_5 V_16 , unsigned long V_206 )
{
return F_283 ( V_19 , V_16 , V_206 ) ;
}
void * F_284 ( T_2 V_19 , T_5 V_16 )
{
return F_283 ( V_19 , V_16 , 0 ) ;
}
void F_157 ( struct V_14 * V_15 , void * V_1 )
{
unsigned long V_16 ;
V_15 = F_286 ( V_15 , V_1 ) ;
if ( ! V_15 )
return;
F_258 ( V_16 ) ;
F_287 ( V_1 , V_15 -> V_207 ) ;
if ( ! ( V_15 -> V_16 & V_120 ) )
F_288 ( V_1 , V_15 -> V_207 ) ;
F_268 ( V_15 , V_1 , V_295 ) ;
F_259 ( V_16 ) ;
F_289 ( V_295 , V_1 ) ;
}
void F_86 ( const void * V_1 )
{
struct V_14 * V_296 ;
unsigned long V_16 ;
F_290 ( V_295 , V_1 ) ;
if ( F_51 ( F_185 ( V_1 ) ) )
return;
F_258 ( V_16 ) ;
F_222 ( V_1 ) ;
V_296 = F_12 ( V_1 ) ;
F_287 ( V_1 , V_296 -> V_207 ) ;
F_288 ( V_1 , V_296 -> V_207 ) ;
F_268 ( V_296 , ( void * ) V_1 , V_295 ) ;
F_259 ( V_16 ) ;
}
static int F_291 ( struct V_14 * V_15 , T_5 V_90 )
{
int V_40 ;
struct V_3 * V_38 ;
struct V_36 * V_297 ;
struct V_36 * * V_298 = NULL ;
F_25 (node) {
if ( V_73 ) {
V_298 = F_79 ( V_40 , V_15 -> V_94 , V_90 ) ;
if ( ! V_298 )
goto V_299;
}
V_297 = NULL ;
if ( V_15 -> V_8 ) {
V_297 = F_58 ( V_40 ,
V_15 -> V_8 * V_15 -> V_89 ,
0xbaadf00d , V_90 ) ;
if ( ! V_297 ) {
F_80 ( V_298 ) ;
goto V_299;
}
}
V_38 = V_15 -> V_40 [ V_40 ] ;
if ( V_38 ) {
struct V_36 * V_8 = V_38 -> V_8 ;
F_99 ( & V_38 -> V_11 ) ;
if ( V_8 )
F_89 ( V_15 , V_8 -> V_101 ,
V_8 -> V_93 , V_40 ) ;
V_38 -> V_8 = V_297 ;
if ( ! V_38 -> V_9 ) {
V_38 -> V_9 = V_298 ;
V_298 = NULL ;
}
V_38 -> V_114 = ( 1 + F_100 ( V_40 ) ) *
V_15 -> V_89 + V_15 -> V_60 ;
F_93 ( & V_38 -> V_11 ) ;
F_86 ( V_8 ) ;
F_80 ( V_298 ) ;
continue;
}
V_38 = F_59 ( sizeof( struct V_3 ) , V_90 , V_40 ) ;
if ( ! V_38 ) {
F_80 ( V_298 ) ;
F_86 ( V_297 ) ;
goto V_299;
}
F_4 ( V_38 ) ;
V_38 -> V_111 = V_112 + V_113 +
( ( unsigned long ) V_15 ) % V_113 ;
V_38 -> V_8 = V_297 ;
V_38 -> V_9 = V_298 ;
V_38 -> V_114 = ( 1 + F_100 ( V_40 ) ) *
V_15 -> V_89 + V_15 -> V_60 ;
V_15 -> V_40 [ V_40 ] = V_38 ;
}
return 0 ;
V_299:
if ( ! V_15 -> V_153 . V_247 ) {
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
static void F_292 ( void * V_300 )
{
struct V_301 * V_302 = V_300 ;
struct V_36 * V_303 ;
F_188 () ;
V_303 = F_31 ( V_302 -> V_15 ) ;
V_302 -> V_15 -> V_53 [ F_32 () ] = V_302 -> V_302 [ F_32 () ] ;
V_302 -> V_302 [ F_32 () ] = V_303 ;
}
static int F_293 ( struct V_14 * V_15 , int V_94 ,
int V_89 , int V_8 , T_5 V_90 )
{
struct V_301 * V_302 ;
int V_45 ;
V_302 = F_294 ( sizeof( * V_302 ) + V_158 * sizeof( struct V_36 * ) ,
V_90 ) ;
if ( ! V_302 )
return - V_110 ;
F_134 (i) {
V_302 -> V_302 [ V_45 ] = F_58 ( F_46 ( V_45 ) , V_94 ,
V_89 , V_90 ) ;
if ( ! V_302 -> V_302 [ V_45 ] ) {
for ( V_45 -- ; V_45 >= 0 ; V_45 -- )
F_86 ( V_302 -> V_302 [ V_45 ] ) ;
F_86 ( V_302 ) ;
return - V_110 ;
}
}
V_302 -> V_15 = V_15 ;
F_197 ( F_292 , ( void * ) V_302 , 1 ) ;
F_190 () ;
V_15 -> V_89 = V_89 ;
V_15 -> V_94 = V_94 ;
V_15 -> V_8 = V_8 ;
F_134 (i) {
struct V_36 * V_304 = V_302 -> V_302 [ V_45 ] ;
if ( ! V_304 )
continue;
F_99 ( & V_15 -> V_40 [ F_46 ( V_45 ) ] -> V_11 ) ;
F_89 ( V_15 , V_304 -> V_101 , V_304 -> V_93 , F_46 ( V_45 ) ) ;
F_93 ( & V_15 -> V_40 [ F_46 ( V_45 ) ] -> V_11 ) ;
F_86 ( V_304 ) ;
}
F_86 ( V_302 ) ;
return F_291 ( V_15 , V_90 ) ;
}
static int F_295 ( struct V_14 * V_15 , int V_94 ,
int V_89 , int V_8 , T_5 V_90 )
{
int V_139 ;
struct V_14 * V_296 = NULL ;
int V_45 = 0 ;
V_139 = F_293 ( V_15 , V_94 , V_89 , V_8 , V_90 ) ;
if ( V_46 < V_174 )
return V_139 ;
if ( ( V_139 < 0 ) || ! F_296 ( V_15 ) )
return V_139 ;
F_15 ( ! F_297 ( & V_128 ) ) ;
F_298 (i) {
V_296 = F_299 ( V_15 , V_45 ) ;
if ( V_296 )
F_293 ( V_296 , V_94 , V_89 , V_8 , V_90 ) ;
}
return V_139 ;
}
static int F_129 ( struct V_14 * V_15 , T_5 V_90 )
{
int V_118 ;
int V_94 = 0 ;
int V_8 = 0 ;
int V_89 = 0 ;
if ( ! F_296 ( V_15 ) ) {
struct V_14 * V_305 = F_300 ( V_15 ) ;
V_94 = V_305 -> V_94 ;
V_8 = V_305 -> V_8 ;
V_89 = V_305 -> V_89 ;
}
if ( V_94 && V_8 && V_89 )
goto V_306;
if ( V_15 -> V_19 > 131072 )
V_94 = 1 ;
else if ( V_15 -> V_19 > V_63 )
V_94 = 8 ;
else if ( V_15 -> V_19 > 1024 )
V_94 = 24 ;
else if ( V_15 -> V_19 > 256 )
V_94 = 54 ;
else
V_94 = 120 ;
V_8 = 0 ;
if ( V_15 -> V_19 <= V_63 && F_301 () > 1 )
V_8 = 8 ;
#if V_231
if ( V_94 > 32 )
V_94 = 32 ;
#endif
V_89 = ( V_94 + 1 ) / 2 ;
V_306:
V_118 = F_295 ( V_15 , V_94 , V_89 , V_8 , V_90 ) ;
if ( V_118 )
F_37 ( V_68 L_38 ,
V_15 -> V_69 , - V_118 ) ;
return V_118 ;
}
static void F_198 ( struct V_14 * V_15 , struct V_3 * V_38 ,
struct V_36 * V_97 , int V_307 , int V_40 )
{
int V_240 ;
if ( ! V_97 || ! V_97 -> V_93 )
return;
if ( V_97 -> V_95 && ! V_307 ) {
V_97 -> V_95 = 0 ;
} else {
F_99 ( & V_38 -> V_11 ) ;
if ( V_97 -> V_93 ) {
V_240 = V_307 ? V_97 -> V_93 : ( V_97 -> V_94 + 4 ) / 5 ;
if ( V_240 > V_97 -> V_93 )
V_240 = ( V_97 -> V_93 + 1 ) / 2 ;
F_89 ( V_15 , V_97 -> V_101 , V_240 , V_40 ) ;
V_97 -> V_93 -= V_240 ;
memmove ( V_97 -> V_101 , & ( V_97 -> V_101 [ V_240 ] ) ,
sizeof( void * ) * V_97 -> V_93 ) ;
}
F_93 ( & V_38 -> V_11 ) ;
}
}
static void V_86 ( struct V_308 * V_309 )
{
struct V_14 * V_310 ;
struct V_3 * V_38 ;
int V_40 = F_65 () ;
struct V_81 * V_84 = F_302 ( V_309 ) ;
if ( ! F_303 ( & V_128 ) )
goto V_99;
F_67 (searchp, &slab_caches, list) {
F_190 () ;
V_38 = V_310 -> V_40 [ V_40 ] ;
F_91 ( V_310 , V_38 ) ;
F_198 ( V_310 , V_38 , F_31 ( V_310 ) , 0 , V_40 ) ;
if ( F_304 ( V_38 -> V_111 , V_112 ) )
goto V_247;
V_38 -> V_111 = V_112 + V_113 ;
F_198 ( V_310 , V_38 , V_38 -> V_8 , 0 , V_40 ) ;
if ( V_38 -> V_13 )
V_38 -> V_13 = 0 ;
else {
int V_311 ;
V_311 = F_104 ( V_310 , V_38 , ( V_38 -> V_114 +
5 * V_310 -> V_60 - 1 ) / ( 5 * V_310 -> V_60 ) ) ;
F_305 ( V_310 , V_311 ) ;
}
V_247:
F_306 () ;
}
F_190 () ;
F_109 ( & V_128 ) ;
F_49 () ;
V_99:
F_307 ( V_84 , F_308 ( V_312 ) ) ;
}
void F_309 ( struct V_14 * V_15 , struct V_313 * V_314 )
{
struct V_25 * V_96 ;
unsigned long V_179 ;
unsigned long V_180 ;
unsigned long V_181 = 0 ;
unsigned long V_182 , V_12 = 0 , V_315 = 0 ;
const char * V_69 ;
char * error = NULL ;
int V_40 ;
struct V_3 * V_38 ;
V_179 = 0 ;
V_182 = 0 ;
F_25 (node) {
V_38 = V_15 -> V_40 [ V_40 ] ;
if ( ! V_38 )
continue;
F_190 () ;
F_99 ( & V_38 -> V_11 ) ;
F_67 (slabp, &n->slabs_full, list) {
if ( V_96 -> V_183 != V_15 -> V_60 && ! error )
error = L_39 ;
V_179 += V_15 -> V_60 ;
V_181 ++ ;
}
F_67 (slabp, &n->slabs_partial, list) {
if ( V_96 -> V_183 == V_15 -> V_60 && ! error )
error = L_40 ;
if ( ! V_96 -> V_183 && ! error )
error = L_41 ;
V_179 += V_96 -> V_183 ;
V_181 ++ ;
}
F_67 (slabp, &n->slabs_free, list) {
if ( V_96 -> V_183 && ! error )
error = L_42 ;
V_182 ++ ;
}
V_12 += V_38 -> V_12 ;
if ( V_38 -> V_8 )
V_315 += V_38 -> V_8 -> V_93 ;
F_93 ( & V_38 -> V_11 ) ;
}
V_182 += V_181 ;
V_180 = V_182 * V_15 -> V_60 ;
if ( V_180 - V_179 != V_12 && ! error )
error = L_43 ;
V_69 = V_15 -> V_69 ;
if ( error )
F_37 ( V_68 L_44 , V_69 , error ) ;
V_314 -> V_179 = V_179 ;
V_314 -> V_180 = V_180 ;
V_314 -> V_181 = V_181 ;
V_314 -> V_182 = V_182 ;
V_314 -> V_315 = V_315 ;
V_314 -> V_94 = V_15 -> V_94 ;
V_314 -> V_89 = V_15 -> V_89 ;
V_314 -> V_8 = V_15 -> V_8 ;
V_314 -> V_316 = V_15 -> V_60 ;
V_314 -> V_317 = V_15 -> V_57 ;
}
void F_310 ( struct V_318 * V_319 , struct V_14 * V_15 )
{
#if V_293
{
unsigned long V_320 = V_15 -> V_321 ;
unsigned long V_322 = V_15 -> V_323 ;
unsigned long V_324 = V_15 -> V_324 ;
unsigned long V_325 = V_15 -> V_325 ;
unsigned long V_326 = V_15 -> V_326 ;
unsigned long V_327 = V_15 -> V_327 ;
unsigned long V_328 = V_15 -> V_328 ;
unsigned long V_329 = V_15 -> V_329 ;
unsigned long V_330 = V_15 -> V_331 ;
F_311 ( V_319 , L_45
L_46 ,
V_322 , V_320 , V_324 ,
V_325 , V_326 , V_327 , V_328 ,
V_329 , V_330 ) ;
}
{
unsigned long V_332 = F_312 ( & V_15 -> V_332 ) ;
unsigned long V_333 = F_312 ( & V_15 -> V_333 ) ;
unsigned long V_334 = F_312 ( & V_15 -> V_334 ) ;
unsigned long V_335 = F_312 ( & V_15 -> V_335 ) ;
F_311 ( V_319 , L_47 ,
V_332 , V_333 , V_334 , V_335 ) ;
}
#endif
}
T_10 F_313 ( struct V_336 * V_336 , const char T_11 * V_337 ,
T_2 V_338 , T_12 * V_339 )
{
char V_340 [ V_341 + 1 ] , * V_342 ;
int V_94 , V_89 , V_8 , V_343 ;
struct V_14 * V_15 ;
if ( V_338 > V_341 )
return - V_344 ;
if ( F_314 ( & V_340 , V_337 , V_338 ) )
return - V_345 ;
V_340 [ V_341 ] = '\0' ;
V_342 = strchr ( V_340 , ' ' ) ;
if ( ! V_342 )
return - V_344 ;
* V_342 = '\0' ;
V_342 ++ ;
if ( sscanf ( V_342 , L_48 , & V_94 , & V_89 , & V_8 ) != 3 )
return - V_344 ;
F_108 ( & V_128 ) ;
V_343 = - V_344 ;
F_67 (cachep, &slab_caches, list) {
if ( ! strcmp ( V_15 -> V_69 , V_340 ) ) {
if ( V_94 < 1 || V_89 < 1 ||
V_89 > V_94 || V_8 < 0 ) {
V_343 = 0 ;
} else {
V_343 = F_295 ( V_15 , V_94 ,
V_89 , V_8 ,
V_109 ) ;
}
break;
}
}
F_109 ( & V_128 ) ;
if ( V_343 >= 0 )
V_343 = V_338 ;
return V_343 ;
}
static void * F_315 ( struct V_318 * V_319 , T_12 * V_346 )
{
F_108 ( & V_128 ) ;
return F_316 ( & V_165 , * V_346 ) ;
}
static inline int F_317 ( unsigned long * V_38 , unsigned long V_347 )
{
unsigned long * V_242 ;
int V_348 ;
if ( ! V_347 )
return 1 ;
V_348 = V_38 [ 1 ] ;
V_242 = V_38 + 2 ;
while ( V_348 ) {
int V_45 = V_348 / 2 ;
unsigned long * V_35 = V_242 + 2 * V_45 ;
if ( * V_35 == V_347 ) {
V_35 [ 1 ] ++ ;
return 1 ;
}
if ( * V_35 > V_347 ) {
V_348 = V_45 ;
} else {
V_242 = V_35 + 2 ;
V_348 -= V_45 + 1 ;
}
}
if ( ++ V_38 [ 1 ] == V_38 [ 0 ] )
return 0 ;
memmove ( V_242 + 2 , V_242 , V_38 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_242 - ( void * ) V_38 ) ) ;
V_242 [ 0 ] = V_347 ;
V_242 [ 1 ] = 1 ;
return 1 ;
}
static void F_318 ( unsigned long * V_38 , struct V_14 * V_296 , struct V_25 * V_72 )
{
void * V_242 ;
int V_45 ;
if ( V_38 [ 0 ] == V_38 [ 1 ] )
return;
for ( V_45 = 0 , V_242 = V_72 -> V_29 ; V_45 < V_296 -> V_60 ; V_45 ++ , V_242 += V_296 -> V_19 ) {
if ( F_209 ( V_72 ) [ V_45 ] != V_267 )
continue;
if ( ! F_317 ( V_38 , ( unsigned long ) * F_11 ( V_296 , V_242 ) ) )
return;
}
}
static void F_319 ( struct V_318 * V_319 , unsigned long V_349 )
{
#ifdef F_320
unsigned long V_30 , V_19 ;
char V_350 [ V_351 ] , V_69 [ V_352 ] ;
if ( F_321 ( V_349 , & V_19 , & V_30 , V_350 , V_69 ) == 0 ) {
F_311 ( V_319 , L_49 , V_69 , V_30 , V_19 ) ;
if ( V_350 [ 0 ] )
F_311 ( V_319 , L_50 , V_350 ) ;
return;
}
#endif
F_311 ( V_319 , L_51 , ( void * ) V_349 ) ;
}
static int F_322 ( struct V_318 * V_319 , void * V_242 )
{
struct V_14 * V_15 = F_199 ( V_242 , struct V_14 , V_153 ) ;
struct V_25 * V_96 ;
struct V_3 * V_38 ;
const char * V_69 ;
unsigned long * V_264 = V_319 -> V_353 ;
int V_40 ;
int V_45 ;
if ( ! ( V_15 -> V_16 & V_18 ) )
return 0 ;
if ( ! ( V_15 -> V_16 & V_17 ) )
return 0 ;
V_264 [ 1 ] = 0 ;
F_25 (node) {
V_38 = V_15 -> V_40 [ V_40 ] ;
if ( ! V_38 )
continue;
F_190 () ;
F_99 ( & V_38 -> V_11 ) ;
F_67 (slabp, &n->slabs_full, list)
F_318 ( V_264 , V_15 , V_96 ) ;
F_67 (slabp, &n->slabs_partial, list)
F_318 ( V_264 , V_15 , V_96 ) ;
F_93 ( & V_38 -> V_11 ) ;
}
V_69 = V_15 -> V_69 ;
if ( V_264 [ 0 ] == V_264 [ 1 ] ) {
F_109 ( & V_128 ) ;
V_319 -> V_353 = F_294 ( V_264 [ 0 ] * 4 * sizeof( unsigned long ) , V_109 ) ;
if ( ! V_319 -> V_353 ) {
V_319 -> V_353 = V_264 ;
F_108 ( & V_128 ) ;
return - V_110 ;
}
* ( unsigned long * ) V_319 -> V_353 = V_264 [ 0 ] * 2 ;
F_86 ( V_264 ) ;
F_108 ( & V_128 ) ;
V_319 -> V_338 = V_319 -> V_19 ;
return 0 ;
}
for ( V_45 = 0 ; V_45 < V_264 [ 1 ] ; V_45 ++ ) {
F_311 ( V_319 , L_52 , V_69 , V_264 [ 2 * V_45 + 3 ] ) ;
F_319 ( V_319 , V_264 [ 2 * V_45 + 2 ] ) ;
F_323 ( V_319 , '\n' ) ;
}
return 0 ;
}
static void * F_324 ( struct V_318 * V_319 , void * V_242 , T_12 * V_346 )
{
return F_325 ( V_242 , & V_165 , V_346 ) ;
}
static void F_326 ( struct V_318 * V_319 , void * V_242 )
{
F_109 ( & V_128 ) ;
}
static int F_327 ( struct V_354 * V_354 , struct V_336 * V_336 )
{
unsigned long * V_38 = F_294 ( V_63 , V_109 ) ;
int V_139 = - V_110 ;
if ( V_38 ) {
V_139 = F_328 ( V_336 , & V_355 ) ;
if ( ! V_139 ) {
struct V_318 * V_319 = V_336 -> V_356 ;
* V_38 = V_63 / ( 2 * sizeof( unsigned long ) ) ;
V_319 -> V_353 = V_38 ;
V_38 = NULL ;
}
F_86 ( V_38 ) ;
}
return V_139 ;
}
static int T_3 F_329 ( void )
{
#ifdef F_226
F_330 ( L_53 , 0 , NULL , & V_357 ) ;
#endif
return 0 ;
}
T_2 F_331 ( const void * V_1 )
{
F_9 ( ! V_1 ) ;
if ( F_51 ( V_1 == V_358 ) )
return 0 ;
return F_12 ( V_1 ) -> V_207 ;
}
