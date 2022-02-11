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
static T_1 int F_4 ( const T_2 V_3 )
{
extern void V_4 ( void ) ;
if ( F_5 ( V_3 ) ) {
int V_5 = 0 ;
#define F_6 ( T_3 ) \
if (size <=x) \
return i; \
else \
i++;
#include <linux/kmalloc_sizes.h>
#undef F_6
V_4 () ;
} else
V_4 () ;
return 0 ;
}
static void F_7 ( struct V_6 * V_7 )
{
F_8 ( & V_7 -> V_8 ) ;
F_8 ( & V_7 -> V_9 ) ;
F_8 ( & V_7 -> V_10 ) ;
V_7 -> V_11 = NULL ;
V_7 -> V_12 = NULL ;
V_7 -> V_13 = 0 ;
F_9 ( & V_7 -> V_14 ) ;
V_7 -> V_15 = 0 ;
V_7 -> V_16 = 0 ;
}
static int F_10 ( struct V_17 * V_18 )
{
return V_18 -> F_10 ;
}
static unsigned long long * F_11 ( struct V_17 * V_18 , void * V_1 )
{
F_12 ( ! ( V_18 -> V_19 & V_20 ) ) ;
return ( unsigned long long * ) ( V_1 + F_10 ( V_18 ) -
sizeof( unsigned long long ) ) ;
}
static unsigned long long * F_13 ( struct V_17 * V_18 , void * V_1 )
{
F_12 ( ! ( V_18 -> V_19 & V_20 ) ) ;
if ( V_18 -> V_19 & V_21 )
return ( unsigned long long * ) ( V_1 + V_18 -> V_3 -
sizeof( unsigned long long ) -
V_22 ) ;
return ( unsigned long long * ) ( V_1 + V_18 -> V_3 -
sizeof( unsigned long long ) ) ;
}
static void * * F_14 ( struct V_17 * V_18 , void * V_1 )
{
F_12 ( ! ( V_18 -> V_19 & V_21 ) ) ;
return ( void * * ) ( V_1 + V_18 -> V_3 - V_23 ) ;
}
static inline struct V_17 * F_15 ( const void * V_24 )
{
struct V_25 * V_25 = F_16 ( V_24 ) ;
return V_25 -> V_26 ;
}
static inline struct V_27 * F_17 ( const void * V_24 )
{
struct V_25 * V_25 = F_16 ( V_24 ) ;
F_18 ( ! F_19 ( V_25 ) ) ;
return V_25 -> V_28 ;
}
static inline void * F_20 ( struct V_17 * V_29 , struct V_27 * V_27 ,
unsigned int V_30 )
{
return V_27 -> V_31 + V_29 -> V_3 * V_30 ;
}
static inline unsigned int F_21 ( const struct V_17 * V_29 ,
const struct V_27 * V_27 , void * V_24 )
{
T_4 V_32 = ( V_24 - V_27 -> V_31 ) ;
return F_22 ( V_32 , V_29 -> V_33 ) ;
}
static void F_23 ( struct V_17 * V_18 ,
struct V_34 * V_35 , struct V_34 * V_36 ,
int V_37 )
{
struct V_38 * * V_39 ;
struct V_6 * V_40 ;
int V_41 ;
V_40 = V_18 -> V_42 [ V_37 ] ;
if ( ! V_40 )
return;
F_24 ( & V_40 -> V_14 , V_35 ) ;
V_39 = V_40 -> V_12 ;
if ( ! V_39 || ( unsigned long ) V_39 == V_43 )
return;
F_25 (r) {
if ( V_39 [ V_41 ] )
F_24 ( & V_39 [ V_41 ] -> V_44 , V_36 ) ;
}
}
static void F_26 ( struct V_17 * V_18 , int V_45 )
{
F_23 ( V_18 , & V_46 , & V_47 , V_45 ) ;
}
static void F_27 ( struct V_17 * V_18 )
{
int V_45 ;
F_28 (node)
F_26 ( V_18 , V_45 ) ;
}
static void F_29 ( int V_37 )
{
struct V_48 * V_49 = V_50 ;
if ( V_51 < V_52 )
return;
for ( V_49 = V_50 ; V_49 -> V_53 != V_54 ; V_49 ++ ) {
struct V_6 * V_40 ;
V_40 = V_49 -> V_55 -> V_42 [ V_37 ] ;
if ( ! V_40 || F_30 ( V_49 -> V_55 ) )
continue;
F_23 ( V_49 -> V_55 , & V_56 ,
& V_57 , V_37 ) ;
}
}
static void F_31 ( struct V_17 * V_18 , int V_37 )
{
struct V_6 * V_40 ;
V_40 = V_18 -> V_42 [ V_37 ] ;
if ( ! V_40 )
return;
F_23 ( V_18 , & V_56 ,
& V_57 , V_37 ) ;
}
static inline void F_32 ( struct V_17 * V_18 )
{
int V_45 ;
F_18 ( F_30 ( V_18 ) ) ;
F_25 (node)
F_31 ( V_18 , V_45 ) ;
}
static inline void F_33 ( void )
{
int V_45 ;
F_25 (node)
F_29 ( V_45 ) ;
}
static void F_29 ( int V_37 )
{
}
static inline void F_33 ( void )
{
}
static inline void F_32 ( struct V_17 * V_18 )
{
}
static inline void F_31 ( struct V_17 * V_18 , int V_45 )
{
}
static void F_26 ( struct V_17 * V_18 , int V_45 )
{
}
static void F_27 ( struct V_17 * V_18 )
{
}
static inline struct V_38 * F_34 ( struct V_17 * V_18 )
{
return V_18 -> V_58 [ F_35 () ] ;
}
static inline struct V_17 * F_36 ( T_2 V_3 ,
T_5 V_59 )
{
struct V_48 * V_60 = V_50 ;
#if V_61
F_12 ( V_50 [ V_62 ] . V_55 == NULL ) ;
#endif
if ( ! V_3 )
return V_63 ;
while ( V_3 > V_60 -> V_53 )
V_60 ++ ;
#ifdef F_37
if ( F_38 ( V_59 & V_64 ) )
return V_60 -> V_65 ;
#endif
return V_60 -> V_55 ;
}
static struct V_17 * F_39 ( T_2 V_3 , T_5 V_59 )
{
return F_36 ( V_3 , V_59 ) ;
}
static T_2 F_40 ( T_2 V_66 , T_2 V_67 )
{
return F_41 ( sizeof( struct V_27 ) + V_66 * sizeof( V_68 ) , V_67 ) ;
}
static void F_42 ( unsigned long V_69 , T_2 V_70 ,
T_2 V_67 , int V_19 , T_2 * V_71 ,
unsigned int * V_72 )
{
int V_66 ;
T_2 V_73 ;
T_2 V_74 = V_75 << V_69 ;
if ( V_19 & V_76 ) {
V_73 = 0 ;
V_66 = V_74 / V_70 ;
if ( V_66 > V_77 )
V_66 = V_77 ;
} else {
V_66 = ( V_74 - sizeof( struct V_27 ) ) /
( V_70 + sizeof( V_68 ) ) ;
if ( F_40 ( V_66 , V_67 ) + V_66 * V_70
> V_74 )
V_66 -- ;
if ( V_66 > V_77 )
V_66 = V_77 ;
V_73 = F_40 ( V_66 , V_67 ) ;
}
* V_72 = V_66 ;
* V_71 = V_74 - V_66 * V_70 - V_73 ;
}
static void F_43 ( const char * V_78 , struct V_17 * V_18 ,
char * V_79 )
{
F_44 ( V_80 L_1 ,
V_78 , V_18 -> V_81 , V_79 ) ;
F_45 () ;
F_46 ( V_82 ) ;
}
static int T_6 F_47 ( char * V_49 )
{
V_83 = 0 ;
return 1 ;
}
static int T_6 F_48 ( char * V_84 )
{
F_49 ( & V_84 , & V_85 ) ;
V_85 = V_85 < 0 ? 0 :
F_50 ( V_85 , V_86 - 1 ) ;
V_87 = true ;
return 1 ;
}
static void F_51 ( int V_88 )
{
int V_45 ;
V_45 = F_52 ( F_53 ( V_88 ) , V_89 ) ;
if ( V_45 == V_90 )
V_45 = F_54 ( V_89 ) ;
F_55 ( V_91 , V_88 ) = V_45 ;
}
static void F_56 ( void )
{
int V_45 = F_57 ( V_91 ) ;
V_45 = F_52 ( V_45 , V_89 ) ;
if ( F_38 ( V_45 >= V_90 ) )
V_45 = F_54 ( V_89 ) ;
F_58 ( V_91 , V_45 ) ;
}
static void T_7 F_59 ( int V_88 )
{
struct V_92 * V_93 = & F_55 ( V_94 , V_88 ) ;
if ( F_60 () && V_93 -> V_95 . V_96 == NULL ) {
F_51 ( V_88 ) ;
F_61 ( V_93 , V_97 ) ;
F_62 ( V_88 , V_93 ,
F_63 ( V_98 , V_88 ) ) ;
}
}
static struct V_38 * F_64 ( int V_45 , int V_99 ,
int V_100 , T_5 V_101 )
{
int V_102 = sizeof( void * ) * V_99 + sizeof( struct V_38 ) ;
struct V_38 * V_103 = NULL ;
V_103 = F_65 ( V_102 , V_101 , V_45 ) ;
F_66 ( V_103 ) ;
if ( V_103 ) {
V_103 -> V_104 = 0 ;
V_103 -> V_105 = V_99 ;
V_103 -> V_100 = V_100 ;
V_103 -> V_106 = 0 ;
F_9 ( & V_103 -> V_44 ) ;
}
return V_103 ;
}
static inline bool F_67 ( struct V_27 * V_107 )
{
struct V_25 * V_25 = F_68 ( V_107 -> V_31 ) ;
return F_69 ( V_25 ) ;
}
static void F_70 ( struct V_17 * V_18 ,
struct V_38 * V_108 )
{
struct V_6 * V_40 = V_18 -> V_42 [ F_71 () ] ;
struct V_27 * V_107 ;
unsigned long V_19 ;
if ( ! V_109 )
return;
F_72 ( & V_40 -> V_14 , V_19 ) ;
F_73 (slabp, &l3->slabs_full, list)
if ( F_67 ( V_107 ) )
goto V_110;
F_73 (slabp, &l3->slabs_partial, list)
if ( F_67 ( V_107 ) )
goto V_110;
F_73 (slabp, &l3->slabs_free, list)
if ( F_67 ( V_107 ) )
goto V_110;
V_109 = false ;
V_110:
F_74 ( & V_40 -> V_14 , V_19 ) ;
}
static void * F_75 ( struct V_17 * V_18 , struct V_38 * V_108 ,
T_5 V_19 , bool V_111 )
{
int V_5 ;
void * V_1 = V_108 -> V_112 [ -- V_108 -> V_104 ] ;
if ( F_38 ( F_1 ( V_1 ) ) ) {
struct V_6 * V_40 ;
if ( F_76 ( V_19 ) ) {
F_3 ( & V_1 ) ;
return V_1 ;
}
for ( V_5 = 0 ; V_5 < V_108 -> V_104 ; V_5 ++ ) {
if ( ! F_1 ( V_108 -> V_112 [ V_5 ] ) ) {
V_1 = V_108 -> V_112 [ V_5 ] ;
V_108 -> V_112 [ V_5 ] = V_108 -> V_112 [ V_108 -> V_104 ] ;
V_108 -> V_112 [ V_108 -> V_104 ] = V_1 ;
return V_1 ;
}
}
V_40 = V_18 -> V_42 [ F_71 () ] ;
if ( ! F_77 ( & V_40 -> V_10 ) && V_111 ) {
struct V_27 * V_107 = F_17 ( V_1 ) ;
F_78 ( F_16 ( V_107 -> V_31 ) ) ;
F_3 ( & V_1 ) ;
F_70 ( V_18 , V_108 ) ;
return V_1 ;
}
V_108 -> V_104 ++ ;
V_1 = NULL ;
}
return V_1 ;
}
static inline void * F_79 ( struct V_17 * V_18 ,
struct V_38 * V_108 , T_5 V_19 , bool V_111 )
{
void * V_1 ;
if ( F_38 ( F_80 () ) )
V_1 = F_75 ( V_18 , V_108 , V_19 , V_111 ) ;
else
V_1 = V_108 -> V_112 [ -- V_108 -> V_104 ] ;
return V_1 ;
}
static void * F_81 ( struct V_17 * V_18 , struct V_38 * V_108 ,
void * V_1 )
{
if ( F_38 ( V_109 ) ) {
struct V_25 * V_25 = F_16 ( V_1 ) ;
if ( F_69 ( V_25 ) )
F_2 ( & V_1 ) ;
}
return V_1 ;
}
static inline void F_82 ( struct V_17 * V_18 , struct V_38 * V_108 ,
void * V_1 )
{
if ( F_38 ( F_80 () ) )
V_1 = F_81 ( V_18 , V_108 , V_1 ) ;
V_108 -> V_112 [ V_108 -> V_104 ++ ] = V_1 ;
}
static int F_83 ( struct V_38 * V_113 ,
struct V_38 * V_114 , unsigned int V_115 )
{
int V_116 = F_84 ( V_114 -> V_104 , V_115 , V_113 -> V_105 - V_113 -> V_104 ) ;
if ( ! V_116 )
return 0 ;
memcpy ( V_113 -> V_112 + V_113 -> V_104 , V_114 -> V_112 + V_114 -> V_104 - V_116 ,
sizeof( void * ) * V_116 ) ;
V_114 -> V_104 -= V_116 ;
V_113 -> V_104 += V_116 ;
return V_116 ;
}
static inline struct V_38 * * F_85 ( int V_45 , int V_105 , T_5 V_101 )
{
return (struct V_38 * * ) V_43 ;
}
static inline void F_86 ( struct V_38 * * V_117 )
{
}
static inline int F_87 ( struct V_17 * V_18 , void * V_1 )
{
return 0 ;
}
static inline void * F_88 ( struct V_17 * V_18 ,
T_5 V_19 )
{
return NULL ;
}
static inline void * F_89 ( struct V_17 * V_18 ,
T_5 V_19 , int V_118 )
{
return NULL ;
}
static struct V_38 * * F_85 ( int V_45 , int V_105 , T_5 V_101 )
{
struct V_38 * * V_117 ;
int V_102 = sizeof( void * ) * V_119 ;
int V_5 ;
if ( V_105 > 1 )
V_105 = 12 ;
V_117 = F_90 ( V_102 , V_101 , V_45 ) ;
if ( V_117 ) {
F_25 (i) {
if ( V_5 == V_45 || ! F_91 ( V_5 ) )
continue;
V_117 [ V_5 ] = F_64 ( V_45 , V_105 , 0xbaadf00d , V_101 ) ;
if ( ! V_117 [ V_5 ] ) {
for ( V_5 -- ; V_5 >= 0 ; V_5 -- )
F_92 ( V_117 [ V_5 ] ) ;
F_92 ( V_117 ) ;
return NULL ;
}
}
}
return V_117 ;
}
static void F_86 ( struct V_38 * * V_117 )
{
int V_5 ;
if ( ! V_117 )
return;
F_25 (i)
F_92 ( V_117 [ V_5 ] ) ;
F_92 ( V_117 ) ;
}
static void F_93 ( struct V_17 * V_18 ,
struct V_38 * V_108 , int V_45 )
{
struct V_6 * V_120 = V_18 -> V_42 [ V_45 ] ;
if ( V_108 -> V_104 ) {
F_94 ( & V_120 -> V_14 ) ;
if ( V_120 -> V_11 )
F_83 ( V_120 -> V_11 , V_108 , V_108 -> V_105 ) ;
F_95 ( V_18 , V_108 -> V_112 , V_108 -> V_104 , V_45 ) ;
V_108 -> V_104 = 0 ;
F_96 ( & V_120 -> V_14 ) ;
}
}
static void F_97 ( struct V_17 * V_18 , struct V_6 * V_40 )
{
int V_45 = F_57 ( V_91 ) ;
if ( V_40 -> V_12 ) {
struct V_38 * V_108 = V_40 -> V_12 [ V_45 ] ;
if ( V_108 && V_108 -> V_104 && F_98 ( & V_108 -> V_44 ) ) {
F_93 ( V_18 , V_108 , V_45 ) ;
F_99 ( & V_108 -> V_44 ) ;
}
}
}
static void F_100 ( struct V_17 * V_18 ,
struct V_38 * * V_12 )
{
int V_5 = 0 ;
struct V_38 * V_108 ;
unsigned long V_19 ;
F_28 (i) {
V_108 = V_12 [ V_5 ] ;
if ( V_108 ) {
F_72 ( & V_108 -> V_44 , V_19 ) ;
F_93 ( V_18 , V_108 , V_5 ) ;
F_74 ( & V_108 -> V_44 , V_19 ) ;
}
}
}
static inline int F_87 ( struct V_17 * V_18 , void * V_1 )
{
struct V_27 * V_107 = F_17 ( V_1 ) ;
int V_118 = V_107 -> V_118 ;
struct V_6 * V_40 ;
struct V_38 * V_12 = NULL ;
int V_45 ;
V_45 = F_71 () ;
if ( F_101 ( V_107 -> V_118 == V_45 ) )
return 0 ;
V_40 = V_18 -> V_42 [ V_45 ] ;
F_102 ( V_18 ) ;
if ( V_40 -> V_12 && V_40 -> V_12 [ V_118 ] ) {
V_12 = V_40 -> V_12 [ V_118 ] ;
F_94 ( & V_12 -> V_44 ) ;
if ( F_38 ( V_12 -> V_104 == V_12 -> V_105 ) ) {
F_103 ( V_18 ) ;
F_93 ( V_18 , V_12 , V_118 ) ;
}
F_82 ( V_18 , V_12 , V_1 ) ;
F_96 ( & V_12 -> V_44 ) ;
} else {
F_94 ( & ( V_18 -> V_42 [ V_118 ] ) -> V_14 ) ;
F_95 ( V_18 , & V_1 , 1 , V_118 ) ;
F_96 ( & ( V_18 -> V_42 [ V_118 ] ) -> V_14 ) ;
}
return 1 ;
}
static int F_104 ( int V_45 )
{
struct V_17 * V_18 ;
struct V_6 * V_40 ;
const int V_102 = sizeof( struct V_6 ) ;
F_73 (cachep, &slab_caches, list) {
if ( ! V_18 -> V_42 [ V_45 ] ) {
V_40 = F_65 ( V_102 , V_121 , V_45 ) ;
if ( ! V_40 )
return - V_122 ;
F_7 ( V_40 ) ;
V_40 -> V_123 = V_124 + V_125 +
( ( unsigned long ) V_18 ) % V_125 ;
V_18 -> V_42 [ V_45 ] = V_40 ;
}
F_105 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
V_18 -> V_42 [ V_45 ] -> V_126 =
( 1 + F_106 ( V_45 ) ) *
V_18 -> V_100 + V_18 -> V_72 ;
F_99 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
}
return 0 ;
}
static void T_7 F_107 ( long V_88 )
{
struct V_17 * V_18 ;
struct V_6 * V_40 = NULL ;
int V_45 = F_53 ( V_88 ) ;
const struct V_127 * V_128 = F_108 ( V_45 ) ;
F_73 (cachep, &slab_caches, list) {
struct V_38 * V_103 ;
struct V_38 * V_11 ;
struct V_38 * * V_12 ;
V_103 = V_18 -> V_58 [ V_88 ] ;
V_18 -> V_58 [ V_88 ] = NULL ;
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
goto V_129;
F_105 ( & V_40 -> V_14 ) ;
V_40 -> V_126 -= V_18 -> V_100 ;
if ( V_103 )
F_95 ( V_18 , V_103 -> V_112 , V_103 -> V_104 , V_45 ) ;
if ( ! F_109 ( V_128 ) ) {
F_99 ( & V_40 -> V_14 ) ;
goto V_129;
}
V_11 = V_40 -> V_11 ;
if ( V_11 ) {
F_95 ( V_18 , V_11 -> V_112 ,
V_11 -> V_104 , V_45 ) ;
V_40 -> V_11 = NULL ;
}
V_12 = V_40 -> V_12 ;
V_40 -> V_12 = NULL ;
F_99 ( & V_40 -> V_14 ) ;
F_92 ( V_11 ) ;
if ( V_12 ) {
F_100 ( V_18 , V_12 ) ;
F_86 ( V_12 ) ;
}
V_129:
F_92 ( V_103 ) ;
}
F_73 (cachep, &slab_caches, list) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_110 ( V_18 , V_40 , V_40 -> V_15 ) ;
}
}
static int T_7 F_111 ( long V_88 )
{
struct V_17 * V_18 ;
struct V_6 * V_40 = NULL ;
int V_45 = F_53 ( V_88 ) ;
int V_130 ;
V_130 = F_104 ( V_45 ) ;
if ( V_130 < 0 )
goto V_131;
F_73 (cachep, &slab_caches, list) {
struct V_38 * V_103 ;
struct V_38 * V_11 = NULL ;
struct V_38 * * V_12 = NULL ;
V_103 = F_64 ( V_45 , V_18 -> V_105 ,
V_18 -> V_100 , V_121 ) ;
if ( ! V_103 )
goto V_131;
if ( V_18 -> V_11 ) {
V_11 = F_64 ( V_45 ,
V_18 -> V_11 * V_18 -> V_100 ,
0xbaadf00d , V_121 ) ;
if ( ! V_11 ) {
F_92 ( V_103 ) ;
goto V_131;
}
}
if ( V_83 ) {
V_12 = F_85 ( V_45 , V_18 -> V_105 , V_121 ) ;
if ( ! V_12 ) {
F_92 ( V_11 ) ;
F_92 ( V_103 ) ;
goto V_131;
}
}
V_18 -> V_58 [ V_88 ] = V_103 ;
V_40 = V_18 -> V_42 [ V_45 ] ;
F_12 ( ! V_40 ) ;
F_105 ( & V_40 -> V_14 ) ;
if ( ! V_40 -> V_11 ) {
V_40 -> V_11 = V_11 ;
V_11 = NULL ;
}
#ifdef F_112
if ( ! V_40 -> V_12 ) {
V_40 -> V_12 = V_12 ;
V_12 = NULL ;
}
#endif
F_99 ( & V_40 -> V_14 ) ;
F_92 ( V_11 ) ;
F_86 ( V_12 ) ;
if ( V_18 -> V_19 & V_132 )
F_26 ( V_18 , V_45 ) ;
else if ( ! F_30 ( V_18 ) &&
! ( V_18 -> V_19 & V_133 ) )
F_31 ( V_18 , V_45 ) ;
}
F_29 ( V_45 ) ;
return 0 ;
V_131:
F_107 ( V_88 ) ;
return - V_122 ;
}
static int T_7 F_113 ( struct V_134 * V_135 ,
unsigned long V_136 , void * V_137 )
{
long V_88 = ( long ) V_137 ;
int V_130 = 0 ;
switch ( V_136 ) {
case V_138 :
case V_139 :
F_114 ( & V_140 ) ;
V_130 = F_111 ( V_88 ) ;
F_115 ( & V_140 ) ;
break;
case V_141 :
case V_142 :
F_59 ( V_88 ) ;
break;
#ifdef F_116
case V_143 :
case V_144 :
F_117 ( & F_55 ( V_94 , V_88 ) ) ;
F_55 ( V_94 , V_88 ) . V_95 . V_96 = NULL ;
break;
case V_145 :
case V_146 :
F_59 ( V_88 ) ;
break;
case V_147 :
case V_148 :
#endif
case V_149 :
case V_150 :
F_114 ( & V_140 ) ;
F_107 ( V_88 ) ;
F_115 ( & V_140 ) ;
break;
}
return F_118 ( V_130 ) ;
}
static int T_8 F_119 ( int V_45 )
{
struct V_17 * V_18 ;
int V_151 = 0 ;
F_73 (cachep, &slab_caches, list) {
struct V_6 * V_40 ;
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_110 ( V_18 , V_40 , V_40 -> V_15 ) ;
if ( ! F_77 ( & V_40 -> V_8 ) ||
! F_77 ( & V_40 -> V_9 ) ) {
V_151 = - V_152 ;
break;
}
}
return V_151 ;
}
static int T_8 F_120 ( struct V_134 * V_153 ,
unsigned long V_136 , void * V_154 )
{
struct V_155 * V_156 = V_154 ;
int V_151 = 0 ;
int V_157 ;
V_157 = V_156 -> V_158 ;
if ( V_157 < 0 )
goto V_110;
switch ( V_136 ) {
case V_159 :
F_114 ( & V_140 ) ;
V_151 = F_104 ( V_157 ) ;
F_115 ( & V_140 ) ;
break;
case V_160 :
F_114 ( & V_140 ) ;
V_151 = F_119 ( V_157 ) ;
F_115 ( & V_140 ) ;
break;
case V_161 :
case V_162 :
case V_163 :
case V_164 :
break;
}
V_110:
return F_118 ( V_151 ) ;
}
static void T_6 F_121 ( struct V_17 * V_18 , struct V_6 * V_165 ,
int V_118 )
{
struct V_6 * V_166 ;
V_166 = F_65 ( sizeof( struct V_6 ) , V_167 , V_118 ) ;
F_12 ( ! V_166 ) ;
memcpy ( V_166 , V_165 , sizeof( struct V_6 ) ) ;
F_9 ( & V_166 -> V_14 ) ;
F_122 ( V_18 , V_166 , V_118 ) ;
V_18 -> V_42 [ V_118 ] = V_166 ;
}
static void T_6 F_123 ( struct V_17 * V_18 , int V_168 )
{
int V_45 ;
F_28 (node) {
V_18 -> V_42 [ V_45 ] = & V_169 [ V_168 + V_45 ] ;
V_18 -> V_42 [ V_45 ] -> V_123 = V_124 +
V_125 +
( ( unsigned long ) V_18 ) % V_125 ;
}
}
static void F_124 ( struct V_17 * V_18 )
{
V_18 -> V_42 = (struct V_6 * * ) & V_18 -> V_58 [ V_170 ] ;
}
void T_6 F_125 ( void )
{
struct V_48 * V_171 ;
struct V_172 * V_173 ;
int V_5 ;
V_17 = & V_174 ;
F_124 ( V_17 ) ;
if ( F_126 () == 1 )
V_83 = 0 ;
for ( V_5 = 0 ; V_5 < V_175 ; V_5 ++ )
F_7 ( & V_169 [ V_5 ] ) ;
F_123 ( V_17 , V_176 ) ;
if ( ! V_87 && V_177 > ( 32 << 20 ) >> V_178 )
V_85 = V_179 ;
F_127 ( V_17 , L_2 ,
F_128 ( struct V_17 , V_58 [ V_170 ] ) +
V_119 * sizeof( struct V_6 * ) ,
V_180 ) ;
F_129 ( & V_17 -> V_165 , & V_181 ) ;
V_171 = V_50 ;
V_173 = V_172 ;
V_171 [ V_62 ] . V_55 = F_130 ( V_173 [ V_62 ] . V_81 ,
V_171 [ V_62 ] . V_53 , V_182 ) ;
if ( V_62 != V_183 )
V_171 [ V_183 ] . V_55 =
F_130 ( V_173 [ V_183 ] . V_81 ,
V_171 [ V_183 ] . V_53 , V_182 ) ;
V_184 = 0 ;
while ( V_171 -> V_53 != V_54 ) {
if ( ! V_171 -> V_55 )
V_171 -> V_55 = F_130 ( V_173 -> V_81 ,
V_171 -> V_53 , V_182 ) ;
#ifdef F_37
V_171 -> V_65 = F_130 (
V_173 -> V_185 , V_171 -> V_53 ,
V_186 | V_182 ) ;
#endif
V_171 ++ ;
V_173 ++ ;
}
{
struct V_38 * V_166 ;
V_166 = F_131 ( sizeof( struct V_187 ) , V_167 ) ;
memcpy ( V_166 , F_34 ( V_17 ) ,
sizeof( struct V_187 ) ) ;
F_9 ( & V_166 -> V_44 ) ;
V_17 -> V_58 [ F_35 () ] = V_166 ;
V_166 = F_131 ( sizeof( struct V_187 ) , V_167 ) ;
F_12 ( F_34 ( V_50 [ V_62 ] . V_55 )
!= & V_188 . V_29 ) ;
memcpy ( V_166 , F_34 ( V_50 [ V_62 ] . V_55 ) ,
sizeof( struct V_187 ) ) ;
F_9 ( & V_166 -> V_44 ) ;
V_50 [ V_62 ] . V_55 -> V_58 [ F_35 () ] =
V_166 ;
}
{
int V_157 ;
F_28 (nid) {
F_121 ( V_17 , & V_169 [ V_176 + V_157 ] , V_157 ) ;
F_121 ( V_50 [ V_62 ] . V_55 ,
& V_169 [ V_189 + V_157 ] , V_157 ) ;
if ( V_62 != V_183 ) {
F_121 ( V_50 [ V_183 ] . V_55 ,
& V_169 [ V_190 + V_157 ] , V_157 ) ;
}
}
}
V_51 = V_52 ;
}
void T_6 F_132 ( void )
{
struct V_17 * V_18 ;
V_51 = V_52 ;
F_114 ( & V_140 ) ;
F_73 (cachep, &slab_caches, list)
if ( F_133 ( V_18 , V_167 ) )
F_134 () ;
F_115 ( & V_140 ) ;
F_33 () ;
V_51 = V_191 ;
F_135 ( & V_192 ) ;
#ifdef F_112
F_136 ( F_120 , V_193 ) ;
#endif
}
static int T_6 F_137 ( void )
{
int V_88 ;
F_138 (cpu)
F_59 ( V_88 ) ;
V_51 = V_191 ;
return 0 ;
}
static T_9 void
F_139 ( struct V_17 * V_18 , T_5 V_59 , int V_118 )
{
struct V_6 * V_40 ;
struct V_27 * V_107 ;
unsigned long V_19 ;
int V_45 ;
F_44 ( V_194
L_3 ,
V_118 , V_59 ) ;
F_44 ( V_194 L_4 ,
V_18 -> V_81 , V_18 -> V_3 , V_18 -> V_69 ) ;
F_28 (node) {
unsigned long V_195 = 0 , V_196 = 0 , V_15 = 0 ;
unsigned long V_197 = 0 , V_198 = 0 ;
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_72 ( & V_40 -> V_14 , V_19 ) ;
F_73 (slabp, &l3->slabs_full, list) {
V_195 += V_18 -> V_72 ;
V_197 ++ ;
}
F_73 (slabp, &l3->slabs_partial, list) {
V_195 += V_107 -> V_199 ;
V_197 ++ ;
}
F_73 (slabp, &l3->slabs_free, list)
V_198 ++ ;
V_15 += V_40 -> V_15 ;
F_74 ( & V_40 -> V_14 , V_19 ) ;
V_198 += V_197 ;
V_196 = V_198 * V_18 -> V_72 ;
F_44 ( V_194
L_5 ,
V_45 , V_197 , V_198 , V_195 , V_196 ,
V_15 ) ;
}
}
static void * F_140 ( struct V_17 * V_18 , T_5 V_19 , int V_118 )
{
struct V_25 * V_25 ;
int V_200 ;
int V_5 ;
#ifndef F_141
V_19 |= V_201 ;
#endif
V_19 |= V_18 -> V_202 ;
if ( V_18 -> V_19 & V_203 )
V_19 |= V_204 ;
V_25 = F_142 ( V_118 , V_19 | V_205 , V_18 -> V_69 ) ;
if ( ! V_25 ) {
if ( ! ( V_19 & V_206 ) && F_143 () )
F_139 ( V_18 , V_19 , V_118 ) ;
return NULL ;
}
if ( F_38 ( V_25 -> V_207 ) )
V_109 = true ;
V_200 = ( 1 << V_18 -> V_69 ) ;
if ( V_18 -> V_19 & V_203 )
F_144 ( F_145 ( V_25 ) ,
V_208 , V_200 ) ;
else
F_144 ( F_145 ( V_25 ) ,
V_209 , V_200 ) ;
for ( V_5 = 0 ; V_5 < V_200 ; V_5 ++ ) {
F_146 ( V_25 + V_5 ) ;
if ( V_25 -> V_207 )
F_147 ( V_25 + V_5 ) ;
}
F_148 ( V_18 , V_18 -> V_69 ) ;
if ( V_210 && ! ( V_18 -> V_19 & V_211 ) ) {
F_149 ( V_25 , V_18 -> V_69 , V_19 , V_118 ) ;
if ( V_18 -> V_212 )
F_150 ( V_25 , V_200 ) ;
else
F_151 ( V_25 , V_200 ) ;
}
return F_152 ( V_25 ) ;
}
static void F_153 ( struct V_17 * V_18 , void * V_213 )
{
unsigned long V_5 = ( 1 << V_18 -> V_69 ) ;
struct V_25 * V_25 = F_68 ( V_213 ) ;
const unsigned long V_214 = V_5 ;
F_154 ( V_25 , V_18 -> V_69 ) ;
if ( V_18 -> V_19 & V_203 )
F_155 ( F_145 ( V_25 ) ,
V_208 , V_214 ) ;
else
F_155 ( F_145 ( V_25 ) ,
V_209 , V_214 ) ;
while ( V_5 -- ) {
F_12 ( ! F_19 ( V_25 ) ) ;
F_156 ( V_25 ) ;
F_157 ( V_25 ) ;
V_25 ++ ;
}
F_158 ( V_18 , V_18 -> V_69 ) ;
if ( V_215 -> V_216 )
V_215 -> V_216 -> V_217 += V_214 ;
F_159 ( ( unsigned long ) V_213 , V_18 -> V_69 ) ;
}
static void F_160 ( struct V_218 * V_219 )
{
struct V_220 * V_220 = (struct V_220 * ) V_219 ;
struct V_17 * V_18 = V_220 -> V_18 ;
F_153 ( V_18 , V_220 -> V_213 ) ;
if ( F_30 ( V_18 ) )
F_161 ( V_18 -> V_221 , V_220 ) ;
}
static void F_162 ( struct V_17 * V_18 , unsigned long * V_213 ,
unsigned long V_222 )
{
int V_3 = V_18 -> V_223 ;
V_213 = ( unsigned long * ) & ( ( char * ) V_213 ) [ F_10 ( V_18 ) ] ;
if ( V_3 < 5 * sizeof( unsigned long ) )
return;
* V_213 ++ = 0x12345678 ;
* V_213 ++ = V_222 ;
* V_213 ++ = F_35 () ;
V_3 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_224 = & V_222 ;
unsigned long V_225 ;
while ( ! F_163 ( V_224 ) ) {
V_225 = * V_224 ++ ;
if ( F_164 ( V_225 ) ) {
* V_213 ++ = V_225 ;
V_3 -= sizeof( unsigned long ) ;
if ( V_3 <= sizeof( unsigned long ) )
break;
}
}
}
* V_213 ++ = 0x87654321 ;
}
static void F_165 ( struct V_17 * V_18 , void * V_213 , unsigned char V_226 )
{
int V_3 = V_18 -> V_223 ;
V_213 = & ( ( char * ) V_213 ) [ F_10 ( V_18 ) ] ;
memset ( V_213 , V_226 , V_3 ) ;
* ( unsigned char * ) ( V_213 + V_3 - 1 ) = V_227 ;
}
static void F_166 ( char * V_228 , int V_32 , int V_105 )
{
int V_5 ;
unsigned char error = 0 ;
int V_229 = 0 ;
F_44 ( V_80 L_6 , V_32 ) ;
for ( V_5 = 0 ; V_5 < V_105 ; V_5 ++ ) {
if ( V_228 [ V_32 + V_5 ] != V_230 ) {
error = V_228 [ V_32 + V_5 ] ;
V_229 ++ ;
}
}
F_167 ( V_231 , L_7 , 0 , 16 , 1 ,
& V_228 [ V_32 ] , V_105 , 1 ) ;
if ( V_229 == 1 ) {
error ^= V_230 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_44 ( V_80 L_8
L_9 ) ;
#ifdef F_168
F_44 ( V_80 L_10
L_11 ) ;
#else
F_44 ( V_80 L_12 ) ;
#endif
}
}
}
static void F_169 ( struct V_17 * V_18 , void * V_1 , int V_232 )
{
int V_5 , V_3 ;
char * V_233 ;
if ( V_18 -> V_19 & V_20 ) {
F_44 ( V_80 L_13 ,
* F_11 ( V_18 , V_1 ) ,
* F_13 ( V_18 , V_1 ) ) ;
}
if ( V_18 -> V_19 & V_21 ) {
F_44 ( V_80 L_14 ,
* F_14 ( V_18 , V_1 ) ) ;
F_170 ( L_15 ,
( unsigned long ) * F_14 ( V_18 , V_1 ) ) ;
F_44 ( L_16 ) ;
}
V_233 = ( char * ) V_1 + F_10 ( V_18 ) ;
V_3 = V_18 -> V_223 ;
for ( V_5 = 0 ; V_5 < V_3 && V_232 ; V_5 += 16 , V_232 -- ) {
int V_105 ;
V_105 = 16 ;
if ( V_5 + V_105 > V_3 )
V_105 = V_3 - V_5 ;
F_166 ( V_233 , V_5 , V_105 ) ;
}
}
static void F_171 ( struct V_17 * V_18 , void * V_1 )
{
char * V_233 ;
int V_3 , V_5 ;
int V_232 = 0 ;
V_233 = ( char * ) V_1 + F_10 ( V_18 ) ;
V_3 = V_18 -> V_223 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
char exp = V_230 ;
if ( V_5 == V_3 - 1 )
exp = V_227 ;
if ( V_233 [ V_5 ] != exp ) {
int V_105 ;
if ( V_232 == 0 ) {
F_44 ( V_80
L_17 ,
F_172 () , V_18 -> V_81 , V_233 , V_3 ) ;
F_169 ( V_18 , V_1 , 0 ) ;
}
V_5 = ( V_5 / 16 ) * 16 ;
V_105 = 16 ;
if ( V_5 + V_105 > V_3 )
V_105 = V_3 - V_5 ;
F_166 ( V_233 , V_5 , V_105 ) ;
V_5 += 16 ;
V_232 ++ ;
if ( V_232 > 5 )
break;
}
}
if ( V_232 != 0 ) {
struct V_27 * V_107 = F_17 ( V_1 ) ;
unsigned int V_234 ;
V_234 = F_21 ( V_18 , V_107 , V_1 ) ;
if ( V_234 ) {
V_1 = F_20 ( V_18 , V_107 , V_234 - 1 ) ;
V_233 = ( char * ) V_1 + F_10 ( V_18 ) ;
F_44 ( V_80 L_18 ,
V_233 , V_3 ) ;
F_169 ( V_18 , V_1 , 2 ) ;
}
if ( V_234 + 1 < V_18 -> V_72 ) {
V_1 = F_20 ( V_18 , V_107 , V_234 + 1 ) ;
V_233 = ( char * ) V_1 + F_10 ( V_18 ) ;
F_44 ( V_80 L_19 ,
V_233 , V_3 ) ;
F_169 ( V_18 , V_1 , 2 ) ;
}
}
}
static void F_173 ( struct V_17 * V_18 , struct V_27 * V_107 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_72 ; V_5 ++ ) {
void * V_1 = F_20 ( V_18 , V_107 , V_5 ) ;
if ( V_18 -> V_19 & V_235 ) {
#ifdef F_174
if ( V_18 -> V_3 % V_75 == 0 &&
F_30 ( V_18 ) )
F_175 ( F_68 ( V_1 ) ,
V_18 -> V_3 / V_75 , 1 ) ;
else
F_171 ( V_18 , V_1 ) ;
#else
F_171 ( V_18 , V_1 ) ;
#endif
}
if ( V_18 -> V_19 & V_20 ) {
if ( * F_11 ( V_18 , V_1 ) != V_236 )
F_176 ( V_18 , L_20
L_21 ) ;
if ( * F_13 ( V_18 , V_1 ) != V_236 )
F_176 ( V_18 , L_22
L_21 ) ;
}
}
}
static void F_173 ( struct V_17 * V_18 , struct V_27 * V_107 )
{
}
static void F_177 ( struct V_17 * V_18 , struct V_27 * V_107 )
{
void * V_213 = V_107 -> V_31 - V_107 -> V_237 ;
F_173 ( V_18 , V_107 ) ;
if ( F_38 ( V_18 -> V_19 & V_133 ) ) {
struct V_220 * V_220 ;
V_220 = (struct V_220 * ) V_107 ;
V_220 -> V_18 = V_18 ;
V_220 -> V_213 = V_213 ;
F_178 ( & V_220 -> V_219 , F_160 ) ;
} else {
F_153 ( V_18 , V_213 ) ;
if ( F_30 ( V_18 ) )
F_161 ( V_18 -> V_221 , V_107 ) ;
}
}
static T_2 F_179 ( struct V_17 * V_18 ,
T_2 V_3 , T_2 V_67 , unsigned long V_19 )
{
unsigned long V_238 ;
T_2 V_71 = 0 ;
int V_69 ;
for ( V_69 = 0 ; V_69 <= V_239 ; V_69 ++ ) {
unsigned int V_72 ;
T_2 V_240 ;
F_42 ( V_69 , V_3 , V_67 , V_19 , & V_240 , & V_72 ) ;
if ( ! V_72 )
continue;
if ( V_19 & V_76 ) {
V_238 = V_3 - sizeof( struct V_27 ) ;
V_238 /= sizeof( V_68 ) ;
if ( V_72 > V_238 )
break;
}
V_18 -> V_72 = V_72 ;
V_18 -> V_69 = V_69 ;
V_71 = V_240 ;
if ( V_19 & V_203 )
break;
if ( V_69 >= V_85 )
break;
if ( V_71 * 8 <= ( V_75 << V_69 ) )
break;
}
return V_71 ;
}
static int T_10 F_180 ( struct V_17 * V_18 , T_5 V_101 )
{
if ( V_51 >= V_191 )
return F_133 ( V_18 , V_101 ) ;
if ( V_51 == V_241 ) {
V_18 -> V_58 [ F_35 () ] = & V_188 . V_29 ;
V_51 = V_242 ;
} else if ( V_51 == V_242 ) {
V_18 -> V_58 [ F_35 () ] = & V_188 . V_29 ;
F_123 ( V_18 , V_189 ) ;
if ( V_62 == V_183 )
V_51 = V_243 ;
else
V_51 = V_244 ;
} else {
V_18 -> V_58 [ F_35 () ] =
F_131 ( sizeof( struct V_187 ) , V_101 ) ;
if ( V_51 == V_244 ) {
F_123 ( V_18 , V_190 ) ;
V_51 = V_243 ;
} else {
int V_45 ;
F_28 (node) {
V_18 -> V_42 [ V_45 ] =
F_65 ( sizeof( struct V_6 ) ,
V_101 , V_45 ) ;
F_12 ( ! V_18 -> V_42 [ V_45 ] ) ;
F_7 ( V_18 -> V_42 [ V_45 ] ) ;
}
}
}
V_18 -> V_42 [ F_71 () ] -> V_123 =
V_124 + V_125 +
( ( unsigned long ) V_18 ) % V_125 ;
F_34 ( V_18 ) -> V_104 = 0 ;
F_34 ( V_18 ) -> V_105 = V_245 ;
F_34 ( V_18 ) -> V_100 = 1 ;
F_34 ( V_18 ) -> V_106 = 0 ;
V_18 -> V_100 = 1 ;
V_18 -> V_105 = V_245 ;
return 0 ;
}
int
F_181 ( struct V_17 * V_18 , unsigned long V_19 )
{
T_2 V_71 , V_74 , V_246 ;
T_5 V_101 ;
int V_130 ;
T_2 V_3 = V_18 -> V_3 ;
#if V_61
#if V_247
if ( V_3 < 4096 || F_182 ( V_3 - 1 ) == F_182 ( V_3 - 1 + V_22 +
2 * sizeof( unsigned long long ) ) )
V_19 |= V_20 | V_21 ;
if ( ! ( V_19 & V_133 ) )
V_19 |= V_235 ;
#endif
if ( V_19 & V_133 )
F_12 ( V_19 & V_235 ) ;
#endif
if ( V_3 & ( V_23 - 1 ) ) {
V_3 += ( V_23 - 1 ) ;
V_3 &= ~ ( V_23 - 1 ) ;
}
if ( V_19 & V_21 )
V_246 = V_23 ;
if ( V_19 & V_20 ) {
V_246 = V_22 ;
V_3 += V_22 - 1 ;
V_3 &= ~ ( V_22 - 1 ) ;
}
if ( V_246 < V_18 -> V_67 ) {
V_246 = V_18 -> V_67 ;
}
if ( V_246 > F_183 (unsigned long long) )
V_19 &= ~ ( V_20 | V_21 ) ;
V_18 -> V_67 = V_246 ;
if ( F_184 () )
V_101 = V_121 ;
else
V_101 = V_167 ;
F_124 ( V_18 ) ;
#if V_61
if ( V_19 & V_20 ) {
V_18 -> F_10 += sizeof( unsigned long long ) ;
V_3 += 2 * sizeof( unsigned long long ) ;
}
if ( V_19 & V_21 ) {
if ( V_19 & V_20 )
V_3 += V_22 ;
else
V_3 += V_23 ;
}
#if V_247 && F_185 ( F_174 )
if ( V_3 >= V_50 [ V_183 + 1 ] . V_53
&& V_18 -> V_223 > F_186 ()
&& F_41 ( V_3 , V_18 -> V_67 ) < V_75 ) {
V_18 -> F_10 += V_75 - F_41 ( V_3 , V_18 -> V_67 ) ;
V_3 = V_75 ;
}
#endif
#endif
if ( ( V_3 >= ( V_75 >> 3 ) ) && ! V_184 &&
! ( V_19 & V_248 ) )
V_19 |= V_76 ;
V_3 = F_41 ( V_3 , V_18 -> V_67 ) ;
V_71 = F_179 ( V_18 , V_3 , V_18 -> V_67 , V_19 ) ;
if ( ! V_18 -> V_72 )
return - V_249 ;
V_74 = F_41 ( V_18 -> V_72 * sizeof( V_68 )
+ sizeof( struct V_27 ) , V_18 -> V_67 ) ;
if ( V_19 & V_76 && V_71 >= V_74 ) {
V_19 &= ~ V_76 ;
V_71 -= V_74 ;
}
if ( V_19 & V_76 ) {
V_74 =
V_18 -> V_72 * sizeof( V_68 ) + sizeof( struct V_27 ) ;
#ifdef F_187
if ( V_3 % V_75 == 0 && V_19 & V_235 )
V_19 &= ~ ( V_20 | V_21 ) ;
#endif
}
V_18 -> V_250 = F_186 () ;
if ( V_18 -> V_250 < V_18 -> V_67 )
V_18 -> V_250 = V_18 -> V_67 ;
V_18 -> V_251 = V_71 / V_18 -> V_250 ;
V_18 -> V_74 = V_74 ;
V_18 -> V_19 = V_19 ;
V_18 -> V_202 = 0 ;
if ( V_252 && ( V_19 & V_186 ) )
V_18 -> V_202 |= V_64 ;
V_18 -> V_3 = V_3 ;
V_18 -> V_33 = F_188 ( V_3 ) ;
if ( V_19 & V_76 ) {
V_18 -> V_221 = F_39 ( V_74 , 0u ) ;
F_12 ( F_189 ( V_18 -> V_221 ) ) ;
}
V_130 = F_180 ( V_18 , V_101 ) ;
if ( V_130 ) {
F_190 ( V_18 ) ;
return V_130 ;
}
if ( V_19 & V_132 ) {
F_191 ( V_19 & V_133 ) ;
F_27 ( V_18 ) ;
} else if ( ! F_30 ( V_18 ) && ! ( V_19 & V_133 ) )
F_32 ( V_18 ) ;
return 0 ;
}
static void F_192 ( void )
{
F_12 ( ! F_193 () ) ;
}
static void F_194 ( void )
{
F_12 ( F_193 () ) ;
}
static void F_195 ( struct V_17 * V_18 )
{
#ifdef F_196
F_192 () ;
F_197 ( & V_18 -> V_42 [ F_71 () ] -> V_14 ) ;
#endif
}
static void F_198 ( struct V_17 * V_18 , int V_45 )
{
#ifdef F_196
F_192 () ;
F_197 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
#endif
}
static void F_199 ( void * V_154 )
{
struct V_17 * V_18 = V_154 ;
struct V_38 * V_108 ;
int V_45 = F_71 () ;
F_192 () ;
V_108 = F_34 ( V_18 ) ;
F_94 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
F_95 ( V_18 , V_108 -> V_112 , V_108 -> V_104 , V_45 ) ;
F_96 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
V_108 -> V_104 = 0 ;
}
static void F_200 ( struct V_17 * V_18 )
{
struct V_6 * V_40 ;
int V_45 ;
F_201 ( F_199 , V_18 , 1 ) ;
F_194 () ;
F_28 (node) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( V_40 && V_40 -> V_12 )
F_100 ( V_18 , V_40 -> V_12 ) ;
}
F_28 (node) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( V_40 )
F_202 ( V_18 , V_40 , V_40 -> V_11 , 1 , V_45 ) ;
}
}
static int F_110 ( struct V_17 * V_29 ,
struct V_6 * V_40 , int V_253 )
{
struct V_254 * V_255 ;
int V_214 ;
struct V_27 * V_107 ;
V_214 = 0 ;
while ( V_214 < V_253 && ! F_77 ( & V_40 -> V_10 ) ) {
F_105 ( & V_40 -> V_14 ) ;
V_255 = V_40 -> V_10 . V_256 ;
if ( V_255 == & V_40 -> V_10 ) {
F_99 ( & V_40 -> V_14 ) ;
goto V_110;
}
V_107 = F_203 ( V_255 , struct V_27 , V_165 ) ;
#if V_61
F_12 ( V_107 -> V_199 ) ;
#endif
F_204 ( & V_107 -> V_165 ) ;
V_40 -> V_15 -= V_29 -> V_72 ;
F_99 ( & V_40 -> V_14 ) ;
F_177 ( V_29 , V_107 ) ;
V_214 ++ ;
}
V_110:
return V_214 ;
}
static int F_205 ( struct V_17 * V_18 )
{
int V_151 = 0 , V_5 = 0 ;
struct V_6 * V_40 ;
F_200 ( V_18 ) ;
F_194 () ;
F_28 (i) {
V_40 = V_18 -> V_42 [ V_5 ] ;
if ( ! V_40 )
continue;
F_110 ( V_18 , V_40 , V_40 -> V_15 ) ;
V_151 += ! F_77 ( & V_40 -> V_8 ) ||
! F_77 ( & V_40 -> V_9 ) ;
}
return ( V_151 ? 1 : 0 ) ;
}
int F_206 ( struct V_17 * V_18 )
{
int V_151 ;
F_12 ( ! V_18 || F_207 () ) ;
F_208 () ;
F_114 ( & V_140 ) ;
V_151 = F_205 ( V_18 ) ;
F_115 ( & V_140 ) ;
F_209 () ;
return V_151 ;
}
int F_190 ( struct V_17 * V_18 )
{
int V_5 ;
struct V_6 * V_40 ;
int V_257 = F_205 ( V_18 ) ;
if ( V_257 )
return V_257 ;
F_138 (i)
F_92 ( V_18 -> V_58 [ V_5 ] ) ;
F_28 (i) {
V_40 = V_18 -> V_42 [ V_5 ] ;
if ( V_40 ) {
F_92 ( V_40 -> V_11 ) ;
F_86 ( V_40 -> V_12 ) ;
F_92 ( V_40 ) ;
}
}
return 0 ;
}
static struct V_27 * F_210 ( struct V_17 * V_18 , void * V_1 ,
int V_250 , T_5 V_258 ,
int V_118 )
{
struct V_27 * V_107 ;
if ( F_30 ( V_18 ) ) {
V_107 = F_211 ( V_18 -> V_221 ,
V_258 , V_118 ) ;
F_212 ( & V_107 -> V_165 , sizeof( struct V_254 ) ,
V_258 ) ;
if ( ! V_107 )
return NULL ;
} else {
V_107 = V_1 + V_250 ;
V_250 += V_18 -> V_74 ;
}
V_107 -> V_199 = 0 ;
V_107 -> V_237 = V_250 ;
V_107 -> V_31 = V_1 + V_250 ;
V_107 -> V_118 = V_118 ;
V_107 -> free = 0 ;
return V_107 ;
}
static inline V_68 * F_213 ( struct V_27 * V_107 )
{
return ( V_68 * ) ( V_107 + 1 ) ;
}
static void F_214 ( struct V_17 * V_18 ,
struct V_27 * V_107 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_72 ; V_5 ++ ) {
void * V_1 = F_20 ( V_18 , V_107 , V_5 ) ;
#if V_61
if ( V_18 -> V_19 & V_235 )
F_165 ( V_18 , V_1 , V_230 ) ;
if ( V_18 -> V_19 & V_21 )
* F_14 ( V_18 , V_1 ) = NULL ;
if ( V_18 -> V_19 & V_20 ) {
* F_11 ( V_18 , V_1 ) = V_236 ;
* F_13 ( V_18 , V_1 ) = V_236 ;
}
if ( V_18 -> V_212 && ! ( V_18 -> V_19 & V_235 ) )
V_18 -> V_212 ( V_1 + F_10 ( V_18 ) ) ;
if ( V_18 -> V_19 & V_20 ) {
if ( * F_13 ( V_18 , V_1 ) != V_236 )
F_176 ( V_18 , L_23
L_24 ) ;
if ( * F_11 ( V_18 , V_1 ) != V_236 )
F_176 ( V_18 , L_23
L_25 ) ;
}
if ( ( V_18 -> V_3 % V_75 ) == 0 &&
F_30 ( V_18 ) && V_18 -> V_19 & V_235 )
F_175 ( F_68 ( V_1 ) ,
V_18 -> V_3 / V_75 , 0 ) ;
#else
if ( V_18 -> V_212 )
V_18 -> V_212 ( V_1 ) ;
#endif
F_213 ( V_107 ) [ V_5 ] = V_5 + 1 ;
}
F_213 ( V_107 ) [ V_5 - 1 ] = V_259 ;
}
static void F_215 ( struct V_17 * V_18 , T_5 V_19 )
{
if ( V_252 ) {
if ( V_19 & V_64 )
F_12 ( ! ( V_18 -> V_202 & V_64 ) ) ;
else
F_12 ( V_18 -> V_202 & V_64 ) ;
}
}
static void * F_216 ( struct V_17 * V_18 , struct V_27 * V_107 ,
int V_118 )
{
void * V_1 = F_20 ( V_18 , V_107 , V_107 -> free ) ;
V_68 V_260 ;
V_107 -> V_199 ++ ;
V_260 = F_213 ( V_107 ) [ V_107 -> free ] ;
#if V_61
F_213 ( V_107 ) [ V_107 -> free ] = V_261 ;
F_217 ( V_107 -> V_118 != V_118 ) ;
#endif
V_107 -> free = V_260 ;
return V_1 ;
}
static void F_218 ( struct V_17 * V_18 , struct V_27 * V_107 ,
void * V_1 , int V_118 )
{
unsigned int V_234 = F_21 ( V_18 , V_107 , V_1 ) ;
#if V_61
F_217 ( V_107 -> V_118 != V_118 ) ;
if ( F_213 ( V_107 ) [ V_234 ] + 1 <= V_77 + 1 ) {
F_44 ( V_80 L_26
L_27 , V_18 -> V_81 , V_1 ) ;
F_134 () ;
}
#endif
F_213 ( V_107 ) [ V_234 ] = V_107 -> free ;
V_107 -> free = V_234 ;
V_107 -> V_199 -- ;
}
static void F_219 ( struct V_17 * V_29 , struct V_27 * V_27 ,
void * V_213 )
{
int V_200 ;
struct V_25 * V_25 ;
V_25 = F_68 ( V_213 ) ;
V_200 = 1 ;
if ( F_101 ( ! F_220 ( V_25 ) ) )
V_200 <<= V_29 -> V_69 ;
do {
V_25 -> V_26 = V_29 ;
V_25 -> V_28 = V_27 ;
V_25 ++ ;
} while ( -- V_200 );
}
static int F_221 ( struct V_17 * V_18 ,
T_5 V_19 , int V_118 , void * V_1 )
{
struct V_27 * V_107 ;
T_2 V_32 ;
T_5 V_258 ;
struct V_6 * V_40 ;
F_12 ( V_19 & V_262 ) ;
V_258 = V_19 & ( V_263 | V_264 ) ;
F_192 () ;
V_40 = V_18 -> V_42 [ V_118 ] ;
F_94 ( & V_40 -> V_14 ) ;
V_32 = V_40 -> V_13 ;
V_40 -> V_13 ++ ;
if ( V_40 -> V_13 >= V_18 -> V_251 )
V_40 -> V_13 = 0 ;
F_96 ( & V_40 -> V_14 ) ;
V_32 *= V_18 -> V_250 ;
if ( V_258 & V_265 )
F_222 () ;
F_215 ( V_18 , V_19 ) ;
if ( ! V_1 )
V_1 = F_140 ( V_18 , V_258 , V_118 ) ;
if ( ! V_1 )
goto V_266;
V_107 = F_210 ( V_18 , V_1 , V_32 ,
V_258 & ~ V_263 , V_118 ) ;
if ( ! V_107 )
goto V_267;
F_219 ( V_18 , V_107 , V_1 ) ;
F_214 ( V_18 , V_107 ) ;
if ( V_258 & V_265 )
F_223 () ;
F_192 () ;
F_94 ( & V_40 -> V_14 ) ;
F_224 ( & V_107 -> V_165 , & ( V_40 -> V_10 ) ) ;
F_225 ( V_18 ) ;
V_40 -> V_15 += V_18 -> V_72 ;
F_96 ( & V_40 -> V_14 ) ;
return 1 ;
V_267:
F_153 ( V_18 , V_1 ) ;
V_266:
if ( V_258 & V_265 )
F_223 () ;
return 0 ;
}
static void F_226 ( const void * V_1 )
{
if ( ! F_227 ( V_1 ) ) {
F_44 ( V_80 L_28 ,
( unsigned long ) V_1 ) ;
F_134 () ;
}
}
static inline void F_228 ( struct V_17 * V_29 , void * V_24 )
{
unsigned long long V_268 , V_269 ;
V_268 = * F_11 ( V_29 , V_24 ) ;
V_269 = * F_13 ( V_29 , V_24 ) ;
if ( V_268 == V_270 && V_269 == V_270 )
return;
if ( V_268 == V_236 && V_269 == V_236 )
F_176 ( V_29 , L_29 ) ;
else
F_176 ( V_29 , L_30 ) ;
F_44 ( V_80 L_31 ,
V_24 , V_268 , V_269 ) ;
}
static void * F_229 ( struct V_17 * V_18 , void * V_1 ,
unsigned long V_222 )
{
struct V_25 * V_25 ;
unsigned int V_234 ;
struct V_27 * V_107 ;
F_12 ( F_15 ( V_1 ) != V_18 ) ;
V_1 -= F_10 ( V_18 ) ;
F_226 ( V_1 ) ;
V_25 = F_16 ( V_1 ) ;
V_107 = V_25 -> V_28 ;
if ( V_18 -> V_19 & V_20 ) {
F_228 ( V_18 , V_1 ) ;
* F_11 ( V_18 , V_1 ) = V_236 ;
* F_13 ( V_18 , V_1 ) = V_236 ;
}
if ( V_18 -> V_19 & V_21 )
* F_14 ( V_18 , V_1 ) = ( void * ) V_222 ;
V_234 = F_21 ( V_18 , V_107 , V_1 ) ;
F_12 ( V_234 >= V_18 -> V_72 ) ;
F_12 ( V_1 != F_20 ( V_18 , V_107 , V_234 ) ) ;
#ifdef F_230
F_213 ( V_107 ) [ V_234 ] = V_261 ;
#endif
if ( V_18 -> V_19 & V_235 ) {
#ifdef F_174
if ( ( V_18 -> V_3 % V_75 ) == 0 && F_30 ( V_18 ) ) {
F_162 ( V_18 , V_1 , V_222 ) ;
F_175 ( F_68 ( V_1 ) ,
V_18 -> V_3 / V_75 , 0 ) ;
} else {
F_165 ( V_18 , V_1 , V_230 ) ;
}
#else
F_165 ( V_18 , V_1 , V_230 ) ;
#endif
}
return V_1 ;
}
static void F_231 ( struct V_17 * V_18 , struct V_27 * V_107 )
{
V_68 V_5 ;
int V_99 = 0 ;
for ( V_5 = V_107 -> free ; V_5 != V_259 ; V_5 = F_213 ( V_107 ) [ V_5 ] ) {
V_99 ++ ;
if ( V_99 > V_18 -> V_72 || V_5 >= V_18 -> V_72 )
goto V_131;
}
if ( V_99 != V_18 -> V_72 - V_107 -> V_199 ) {
V_131:
F_44 ( V_80 L_32
L_33 ,
V_18 -> V_81 , V_18 -> V_72 , V_107 , V_107 -> V_199 ,
F_172 () ) ;
F_167 ( V_80 , L_7 , V_271 , 16 , 1 , V_107 ,
sizeof( * V_107 ) + V_18 -> V_72 * sizeof( V_68 ) ,
1 ) ;
F_134 () ;
}
}
static void * F_232 ( struct V_17 * V_18 , T_5 V_19 ,
bool V_111 )
{
int V_100 ;
struct V_6 * V_40 ;
struct V_38 * V_108 ;
int V_45 ;
F_192 () ;
V_45 = F_71 () ;
if ( F_38 ( V_111 ) )
goto V_272;
V_273:
V_108 = F_34 ( V_18 ) ;
V_100 = V_108 -> V_100 ;
if ( ! V_108 -> V_106 && V_100 > V_274 ) {
V_100 = V_274 ;
}
V_40 = V_18 -> V_42 [ V_45 ] ;
F_12 ( V_108 -> V_104 > 0 || ! V_40 ) ;
F_94 ( & V_40 -> V_14 ) ;
if ( V_40 -> V_11 && F_83 ( V_108 , V_40 -> V_11 , V_100 ) ) {
V_40 -> V_11 -> V_106 = 1 ;
goto V_275;
}
while ( V_100 > 0 ) {
struct V_254 * V_112 ;
struct V_27 * V_107 ;
V_112 = V_40 -> V_9 . V_260 ;
if ( V_112 == & V_40 -> V_9 ) {
V_40 -> V_16 = 1 ;
V_112 = V_40 -> V_10 . V_260 ;
if ( V_112 == & V_40 -> V_10 )
goto V_276;
}
V_107 = F_203 ( V_112 , struct V_27 , V_165 ) ;
F_231 ( V_18 , V_107 ) ;
F_195 ( V_18 ) ;
F_12 ( V_107 -> V_199 >= V_18 -> V_72 ) ;
while ( V_107 -> V_199 < V_18 -> V_72 && V_100 -- ) {
F_233 ( V_18 ) ;
F_234 ( V_18 ) ;
F_235 ( V_18 ) ;
F_82 ( V_18 , V_108 , F_216 ( V_18 , V_107 ,
V_45 ) ) ;
}
F_231 ( V_18 , V_107 ) ;
F_204 ( & V_107 -> V_165 ) ;
if ( V_107 -> free == V_259 )
F_129 ( & V_107 -> V_165 , & V_40 -> V_8 ) ;
else
F_129 ( & V_107 -> V_165 , & V_40 -> V_9 ) ;
}
V_276:
V_40 -> V_15 -= V_108 -> V_104 ;
V_275:
F_96 ( & V_40 -> V_14 ) ;
if ( F_38 ( ! V_108 -> V_104 ) ) {
int T_3 ;
V_272:
T_3 = F_221 ( V_18 , V_19 | V_277 , V_45 , NULL ) ;
V_108 = F_34 ( V_18 ) ;
V_45 = F_71 () ;
if ( ! T_3 && ( V_108 -> V_104 == 0 || V_111 ) )
return NULL ;
if ( ! V_108 -> V_104 )
goto V_273;
}
V_108 -> V_106 = 1 ;
return F_79 ( V_18 , V_108 , V_19 , V_111 ) ;
}
static inline void F_236 ( struct V_17 * V_18 ,
T_5 V_19 )
{
F_237 ( V_19 & V_265 ) ;
#if V_61
F_215 ( V_18 , V_19 ) ;
#endif
}
static void * F_238 ( struct V_17 * V_18 ,
T_5 V_19 , void * V_1 , unsigned long V_222 )
{
if ( ! V_1 )
return V_1 ;
if ( V_18 -> V_19 & V_235 ) {
#ifdef F_174
if ( ( V_18 -> V_3 % V_75 ) == 0 && F_30 ( V_18 ) )
F_175 ( F_68 ( V_1 ) ,
V_18 -> V_3 / V_75 , 1 ) ;
else
F_171 ( V_18 , V_1 ) ;
#else
F_171 ( V_18 , V_1 ) ;
#endif
F_165 ( V_18 , V_1 , V_278 ) ;
}
if ( V_18 -> V_19 & V_21 )
* F_14 ( V_18 , V_1 ) = ( void * ) V_222 ;
if ( V_18 -> V_19 & V_20 ) {
if ( * F_11 ( V_18 , V_1 ) != V_236 ||
* F_13 ( V_18 , V_1 ) != V_236 ) {
F_176 ( V_18 , L_34
L_35 ) ;
F_44 ( V_80
L_36 ,
V_1 , * F_11 ( V_18 , V_1 ) ,
* F_13 ( V_18 , V_1 ) ) ;
}
* F_11 ( V_18 , V_1 ) = V_270 ;
* F_13 ( V_18 , V_1 ) = V_270 ;
}
#ifdef F_230
{
struct V_27 * V_107 ;
unsigned V_234 ;
V_107 = F_16 ( V_1 ) -> V_28 ;
V_234 = ( unsigned ) ( V_1 - V_107 -> V_31 ) / V_18 -> V_3 ;
F_213 ( V_107 ) [ V_234 ] = V_279 ;
}
#endif
V_1 += F_10 ( V_18 ) ;
if ( V_18 -> V_212 && V_18 -> V_19 & V_235 )
V_18 -> V_212 ( V_1 ) ;
if ( V_280 &&
( ( unsigned long ) V_1 & ( V_280 - 1 ) ) ) {
F_44 ( V_80 L_37 ,
V_1 , ( int ) V_280 ) ;
}
return V_1 ;
}
static bool F_239 ( struct V_17 * V_18 , T_5 V_19 )
{
if ( V_18 == V_17 )
return false ;
return F_240 ( V_18 -> V_223 , V_19 , V_18 -> V_19 ) ;
}
static inline void * F_241 ( struct V_17 * V_18 , T_5 V_19 )
{
void * V_1 ;
struct V_38 * V_108 ;
bool V_111 = false ;
F_192 () ;
V_108 = F_34 ( V_18 ) ;
if ( F_101 ( V_108 -> V_104 ) ) {
V_108 -> V_106 = 1 ;
V_1 = F_79 ( V_18 , V_108 , V_19 , false ) ;
if ( V_1 ) {
F_242 ( V_18 ) ;
goto V_110;
}
V_111 = true ;
}
F_243 ( V_18 ) ;
V_1 = F_232 ( V_18 , V_19 , V_111 ) ;
V_108 = F_34 ( V_18 ) ;
V_110:
if ( V_1 )
F_244 ( & V_108 -> V_112 [ V_108 -> V_104 ] ) ;
return V_1 ;
}
static void * F_88 ( struct V_17 * V_18 , T_5 V_19 )
{
int V_281 , V_282 ;
if ( F_207 () || ( V_19 & V_283 ) )
return NULL ;
V_281 = V_282 = F_71 () ;
if ( F_245 () && ( V_18 -> V_19 & V_284 ) )
V_281 = F_246 () ;
else if ( V_215 -> V_285 )
V_281 = F_247 () ;
if ( V_281 != V_282 )
return F_89 ( V_18 , V_19 , V_281 ) ;
return NULL ;
}
static void * F_248 ( struct V_17 * V_29 , T_5 V_19 )
{
struct V_286 * V_286 ;
T_5 V_258 ;
struct V_287 * V_288 ;
struct V_289 * V_289 ;
enum V_290 V_291 = F_249 ( V_19 ) ;
void * V_24 = NULL ;
int V_157 ;
unsigned int V_292 ;
if ( V_19 & V_283 )
return NULL ;
V_258 = V_19 & ( V_263 | V_264 ) ;
V_293:
V_292 = F_250 () ;
V_286 = F_251 ( F_247 () , V_19 ) ;
V_273:
F_252 (zone, z, zonelist, high_zoneidx) {
V_157 = F_253 ( V_289 ) ;
if ( F_254 ( V_289 , V_19 ) &&
V_29 -> V_42 [ V_157 ] &&
V_29 -> V_42 [ V_157 ] -> V_15 ) {
V_24 = F_89 ( V_29 ,
V_19 | V_277 , V_157 ) ;
if ( V_24 )
break;
}
}
if ( ! V_24 ) {
if ( V_258 & V_265 )
F_222 () ;
F_215 ( V_29 , V_19 ) ;
V_24 = F_140 ( V_29 , V_258 , F_71 () ) ;
if ( V_258 & V_265 )
F_223 () ;
if ( V_24 ) {
V_157 = F_255 ( F_68 ( V_24 ) ) ;
if ( F_221 ( V_29 , V_19 , V_157 , V_24 ) ) {
V_24 = F_89 ( V_29 ,
V_19 | V_277 , V_157 ) ;
if ( ! V_24 )
goto V_273;
} else {
V_24 = NULL ;
}
}
}
if ( F_38 ( ! F_256 ( V_292 ) && ! V_24 ) )
goto V_293;
return V_24 ;
}
static void * F_89 ( struct V_17 * V_18 , T_5 V_19 ,
int V_118 )
{
struct V_254 * V_112 ;
struct V_27 * V_107 ;
struct V_6 * V_40 ;
void * V_24 ;
int T_3 ;
V_40 = V_18 -> V_42 [ V_118 ] ;
F_12 ( ! V_40 ) ;
V_273:
F_192 () ;
F_94 ( & V_40 -> V_14 ) ;
V_112 = V_40 -> V_9 . V_260 ;
if ( V_112 == & V_40 -> V_9 ) {
V_40 -> V_16 = 1 ;
V_112 = V_40 -> V_10 . V_260 ;
if ( V_112 == & V_40 -> V_10 )
goto V_276;
}
V_107 = F_203 ( V_112 , struct V_27 , V_165 ) ;
F_198 ( V_18 , V_118 ) ;
F_231 ( V_18 , V_107 ) ;
F_257 ( V_18 ) ;
F_234 ( V_18 ) ;
F_235 ( V_18 ) ;
F_12 ( V_107 -> V_199 == V_18 -> V_72 ) ;
V_24 = F_216 ( V_18 , V_107 , V_118 ) ;
F_231 ( V_18 , V_107 ) ;
V_40 -> V_15 -- ;
F_204 ( & V_107 -> V_165 ) ;
if ( V_107 -> free == V_259 )
F_129 ( & V_107 -> V_165 , & V_40 -> V_8 ) ;
else
F_129 ( & V_107 -> V_165 , & V_40 -> V_9 ) ;
F_96 ( & V_40 -> V_14 ) ;
goto V_294;
V_276:
F_96 ( & V_40 -> V_14 ) ;
T_3 = F_221 ( V_18 , V_19 | V_277 , V_118 , NULL ) ;
if ( T_3 )
goto V_273;
return F_248 ( V_18 , V_19 ) ;
V_294:
return V_24 ;
}
static T_1 void *
F_258 ( struct V_17 * V_18 , T_5 V_19 , int V_118 ,
unsigned long V_222 )
{
unsigned long V_295 ;
void * V_166 ;
int F_247 = F_71 () ;
V_19 &= V_296 ;
F_259 ( V_19 ) ;
if ( F_239 ( V_18 , V_19 ) )
return NULL ;
V_18 = F_260 ( V_18 , V_19 ) ;
F_236 ( V_18 , V_19 ) ;
F_261 ( V_295 ) ;
if ( V_118 == V_297 )
V_118 = F_247 ;
if ( F_38 ( ! V_18 -> V_42 [ V_118 ] ) ) {
V_166 = F_248 ( V_18 , V_19 ) ;
goto V_110;
}
if ( V_118 == F_247 ) {
V_166 = F_241 ( V_18 , V_19 ) ;
if ( V_166 )
goto V_110;
}
V_166 = F_89 ( V_18 , V_19 , V_118 ) ;
V_110:
F_262 ( V_295 ) ;
V_166 = F_238 ( V_18 , V_19 , V_166 , V_222 ) ;
F_263 ( V_166 , V_18 -> V_223 , 1 , V_18 -> V_19 ,
V_19 ) ;
if ( F_101 ( V_166 ) )
F_264 ( V_18 , V_19 , V_166 , V_18 -> V_223 ) ;
if ( F_38 ( ( V_19 & V_298 ) && V_166 ) )
memset ( V_166 , 0 , V_18 -> V_223 ) ;
return V_166 ;
}
static T_1 void *
F_265 ( struct V_17 * V_29 , T_5 V_19 )
{
void * V_1 ;
if ( F_38 ( V_215 -> V_19 & ( V_299 | V_300 ) ) ) {
V_1 = F_88 ( V_29 , V_19 ) ;
if ( V_1 )
goto V_110;
}
V_1 = F_241 ( V_29 , V_19 ) ;
if ( ! V_1 )
V_1 = F_89 ( V_29 , V_19 , F_71 () ) ;
V_110:
return V_1 ;
}
static T_1 void *
F_265 ( struct V_17 * V_18 , T_5 V_19 )
{
return F_241 ( V_18 , V_19 ) ;
}
static T_1 void *
F_266 ( struct V_17 * V_18 , T_5 V_19 , unsigned long V_222 )
{
unsigned long V_295 ;
void * V_1 ;
V_19 &= V_296 ;
F_259 ( V_19 ) ;
if ( F_239 ( V_18 , V_19 ) )
return NULL ;
V_18 = F_260 ( V_18 , V_19 ) ;
F_236 ( V_18 , V_19 ) ;
F_261 ( V_295 ) ;
V_1 = F_265 ( V_18 , V_19 ) ;
F_262 ( V_295 ) ;
V_1 = F_238 ( V_18 , V_19 , V_1 , V_222 ) ;
F_263 ( V_1 , V_18 -> V_223 , 1 , V_18 -> V_19 ,
V_19 ) ;
F_267 ( V_1 ) ;
if ( F_101 ( V_1 ) )
F_264 ( V_18 , V_19 , V_1 , V_18 -> V_223 ) ;
if ( F_38 ( ( V_19 & V_298 ) && V_1 ) )
memset ( V_1 , 0 , V_18 -> V_223 ) ;
return V_1 ;
}
static void F_95 ( struct V_17 * V_18 , void * * V_301 , int V_302 ,
int V_45 )
{
int V_5 ;
struct V_6 * V_40 ;
for ( V_5 = 0 ; V_5 < V_302 ; V_5 ++ ) {
void * V_1 ;
struct V_27 * V_107 ;
F_3 ( & V_301 [ V_5 ] ) ;
V_1 = V_301 [ V_5 ] ;
V_107 = F_17 ( V_1 ) ;
V_40 = V_18 -> V_42 [ V_45 ] ;
F_204 ( & V_107 -> V_165 ) ;
F_198 ( V_18 , V_45 ) ;
F_231 ( V_18 , V_107 ) ;
F_218 ( V_18 , V_107 , V_1 , V_45 ) ;
F_268 ( V_18 ) ;
V_40 -> V_15 ++ ;
F_231 ( V_18 , V_107 ) ;
if ( V_107 -> V_199 == 0 ) {
if ( V_40 -> V_15 > V_40 -> V_126 ) {
V_40 -> V_15 -= V_18 -> V_72 ;
F_177 ( V_18 , V_107 ) ;
} else {
F_129 ( & V_107 -> V_165 , & V_40 -> V_10 ) ;
}
} else {
F_224 ( & V_107 -> V_165 , & V_40 -> V_9 ) ;
}
}
}
static void F_269 ( struct V_17 * V_18 , struct V_38 * V_108 )
{
int V_100 ;
struct V_6 * V_40 ;
int V_45 = F_71 () ;
V_100 = V_108 -> V_100 ;
#if V_61
F_12 ( ! V_100 || V_100 > V_108 -> V_104 ) ;
#endif
F_192 () ;
V_40 = V_18 -> V_42 [ V_45 ] ;
F_94 ( & V_40 -> V_14 ) ;
if ( V_40 -> V_11 ) {
struct V_38 * V_303 = V_40 -> V_11 ;
int V_115 = V_303 -> V_105 - V_303 -> V_104 ;
if ( V_115 ) {
if ( V_100 > V_115 )
V_100 = V_115 ;
memcpy ( & ( V_303 -> V_112 [ V_303 -> V_104 ] ) ,
V_108 -> V_112 , sizeof( void * ) * V_100 ) ;
V_303 -> V_104 += V_100 ;
goto V_304;
}
}
F_95 ( V_18 , V_108 -> V_112 , V_100 , V_45 ) ;
V_304:
#if V_305
{
int V_5 = 0 ;
struct V_254 * V_255 ;
V_255 = V_40 -> V_10 . V_260 ;
while ( V_255 != & ( V_40 -> V_10 ) ) {
struct V_27 * V_107 ;
V_107 = F_203 ( V_255 , struct V_27 , V_165 ) ;
F_12 ( V_107 -> V_199 ) ;
V_5 ++ ;
V_255 = V_255 -> V_260 ;
}
F_270 ( V_18 , V_5 ) ;
}
#endif
F_96 ( & V_40 -> V_14 ) ;
V_108 -> V_104 -= V_100 ;
memmove ( V_108 -> V_112 , & ( V_108 -> V_112 [ V_100 ] ) , sizeof( void * ) * V_108 -> V_104 ) ;
}
static inline void F_271 ( struct V_17 * V_18 , void * V_1 ,
unsigned long V_222 )
{
struct V_38 * V_108 = F_34 ( V_18 ) ;
F_192 () ;
F_272 ( V_1 , V_18 -> V_19 ) ;
V_1 = F_229 ( V_18 , V_1 , V_222 ) ;
F_273 ( V_18 , V_1 , V_18 -> V_223 ) ;
if ( V_306 > 1 && F_87 ( V_18 , V_1 ) )
return;
if ( F_101 ( V_108 -> V_104 < V_108 -> V_105 ) ) {
F_274 ( V_18 ) ;
} else {
F_275 ( V_18 ) ;
F_269 ( V_18 , V_108 ) ;
}
F_82 ( V_18 , V_108 , V_1 ) ;
}
void * F_276 ( struct V_17 * V_18 , T_5 V_19 )
{
void * V_151 = F_266 ( V_18 , V_19 , V_307 ) ;
F_277 ( V_307 , V_151 ,
V_18 -> V_223 , V_18 -> V_3 , V_19 ) ;
return V_151 ;
}
void *
F_278 ( struct V_17 * V_18 , T_5 V_19 , T_2 V_3 )
{
void * V_151 ;
V_151 = F_266 ( V_18 , V_19 , V_307 ) ;
F_279 ( V_307 , V_151 ,
V_3 , V_18 -> V_3 , V_19 ) ;
return V_151 ;
}
void * F_211 ( struct V_17 * V_18 , T_5 V_19 , int V_118 )
{
void * V_151 = F_258 ( V_18 , V_19 , V_118 , V_307 ) ;
F_280 ( V_307 , V_151 ,
V_18 -> V_223 , V_18 -> V_3 ,
V_19 , V_118 ) ;
return V_151 ;
}
void * F_281 ( struct V_17 * V_18 ,
T_5 V_19 ,
int V_118 ,
T_2 V_3 )
{
void * V_151 ;
V_151 = F_258 ( V_18 , V_19 , V_118 , V_307 ) ;
F_282 ( V_307 , V_151 ,
V_3 , V_18 -> V_3 ,
V_19 , V_118 ) ;
return V_151 ;
}
static T_1 void *
F_283 ( T_2 V_3 , T_5 V_19 , int V_45 , unsigned long V_222 )
{
struct V_17 * V_18 ;
V_18 = F_39 ( V_3 , V_19 ) ;
if ( F_38 ( F_189 ( V_18 ) ) )
return V_18 ;
return F_281 ( V_18 , V_19 , V_45 , V_3 ) ;
}
void * F_284 ( T_2 V_3 , T_5 V_19 , int V_45 )
{
return F_283 ( V_3 , V_19 , V_45 , V_307 ) ;
}
void * F_285 ( T_2 V_3 , T_5 V_19 ,
int V_45 , unsigned long V_222 )
{
return F_283 ( V_3 , V_19 , V_45 , V_222 ) ;
}
void * F_284 ( T_2 V_3 , T_5 V_19 , int V_45 )
{
return F_283 ( V_3 , V_19 , V_45 , 0 ) ;
}
static T_1 void * F_286 ( T_2 V_3 , T_5 V_19 ,
unsigned long V_222 )
{
struct V_17 * V_18 ;
void * V_151 ;
V_18 = F_36 ( V_3 , V_19 ) ;
if ( F_38 ( F_189 ( V_18 ) ) )
return V_18 ;
V_151 = F_266 ( V_18 , V_19 , V_222 ) ;
F_279 ( V_222 , V_151 ,
V_3 , V_18 -> V_3 , V_19 ) ;
return V_151 ;
}
void * F_287 ( T_2 V_3 , T_5 V_19 )
{
return F_286 ( V_3 , V_19 , V_307 ) ;
}
void * F_288 ( T_2 V_3 , T_5 V_19 , unsigned long V_222 )
{
return F_286 ( V_3 , V_19 , V_222 ) ;
}
void * F_287 ( T_2 V_3 , T_5 V_19 )
{
return F_286 ( V_3 , V_19 , 0 ) ;
}
void F_161 ( struct V_17 * V_18 , void * V_1 )
{
unsigned long V_19 ;
V_18 = F_289 ( V_18 , V_1 ) ;
if ( ! V_18 )
return;
F_261 ( V_19 ) ;
F_290 ( V_1 , V_18 -> V_223 ) ;
if ( ! ( V_18 -> V_19 & V_132 ) )
F_291 ( V_1 , V_18 -> V_223 ) ;
F_271 ( V_18 , V_1 , V_307 ) ;
F_262 ( V_19 ) ;
F_292 ( V_307 , V_1 ) ;
}
void F_92 ( const void * V_1 )
{
struct V_17 * V_308 ;
unsigned long V_19 ;
F_293 ( V_307 , V_1 ) ;
if ( F_38 ( F_189 ( V_1 ) ) )
return;
F_261 ( V_19 ) ;
F_226 ( V_1 ) ;
V_308 = F_15 ( V_1 ) ;
F_290 ( V_1 , V_308 -> V_223 ) ;
F_291 ( V_1 , V_308 -> V_223 ) ;
F_271 ( V_308 , ( void * ) V_1 , V_307 ) ;
F_262 ( V_19 ) ;
}
static int F_294 ( struct V_17 * V_18 , T_5 V_101 )
{
int V_45 ;
struct V_6 * V_40 ;
struct V_38 * V_309 ;
struct V_38 * * V_310 = NULL ;
F_28 (node) {
if ( V_83 ) {
V_310 = F_85 ( V_45 , V_18 -> V_105 , V_101 ) ;
if ( ! V_310 )
goto V_311;
}
V_309 = NULL ;
if ( V_18 -> V_11 ) {
V_309 = F_64 ( V_45 ,
V_18 -> V_11 * V_18 -> V_100 ,
0xbaadf00d , V_101 ) ;
if ( ! V_309 ) {
F_86 ( V_310 ) ;
goto V_311;
}
}
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( V_40 ) {
struct V_38 * V_11 = V_40 -> V_11 ;
F_105 ( & V_40 -> V_14 ) ;
if ( V_11 )
F_95 ( V_18 , V_11 -> V_112 ,
V_11 -> V_104 , V_45 ) ;
V_40 -> V_11 = V_309 ;
if ( ! V_40 -> V_12 ) {
V_40 -> V_12 = V_310 ;
V_310 = NULL ;
}
V_40 -> V_126 = ( 1 + F_106 ( V_45 ) ) *
V_18 -> V_100 + V_18 -> V_72 ;
F_99 ( & V_40 -> V_14 ) ;
F_92 ( V_11 ) ;
F_86 ( V_310 ) ;
continue;
}
V_40 = F_65 ( sizeof( struct V_6 ) , V_101 , V_45 ) ;
if ( ! V_40 ) {
F_86 ( V_310 ) ;
F_92 ( V_309 ) ;
goto V_311;
}
F_7 ( V_40 ) ;
V_40 -> V_123 = V_124 + V_125 +
( ( unsigned long ) V_18 ) % V_125 ;
V_40 -> V_11 = V_309 ;
V_40 -> V_12 = V_310 ;
V_40 -> V_126 = ( 1 + F_106 ( V_45 ) ) *
V_18 -> V_100 + V_18 -> V_72 ;
V_18 -> V_42 [ V_45 ] = V_40 ;
}
return 0 ;
V_311:
if ( ! V_18 -> V_165 . V_260 ) {
V_45 -- ;
while ( V_45 >= 0 ) {
if ( V_18 -> V_42 [ V_45 ] ) {
V_40 = V_18 -> V_42 [ V_45 ] ;
F_92 ( V_40 -> V_11 ) ;
F_86 ( V_40 -> V_12 ) ;
F_92 ( V_40 ) ;
V_18 -> V_42 [ V_45 ] = NULL ;
}
V_45 -- ;
}
}
return - V_122 ;
}
static void F_295 ( void * V_312 )
{
struct V_313 * V_314 = V_312 ;
struct V_38 * V_315 ;
F_192 () ;
V_315 = F_34 ( V_314 -> V_18 ) ;
V_314 -> V_18 -> V_58 [ F_35 () ] = V_314 -> V_314 [ F_35 () ] ;
V_314 -> V_314 [ F_35 () ] = V_315 ;
}
static int F_296 ( struct V_17 * V_18 , int V_105 ,
int V_100 , int V_11 , T_5 V_101 )
{
struct V_313 * V_314 ;
int V_5 ;
V_314 = F_297 ( sizeof( * V_314 ) + V_170 * sizeof( struct V_38 * ) ,
V_101 ) ;
if ( ! V_314 )
return - V_122 ;
F_138 (i) {
V_314 -> V_314 [ V_5 ] = F_64 ( F_53 ( V_5 ) , V_105 ,
V_100 , V_101 ) ;
if ( ! V_314 -> V_314 [ V_5 ] ) {
for ( V_5 -- ; V_5 >= 0 ; V_5 -- )
F_92 ( V_314 -> V_314 [ V_5 ] ) ;
F_92 ( V_314 ) ;
return - V_122 ;
}
}
V_314 -> V_18 = V_18 ;
F_201 ( F_295 , ( void * ) V_314 , 1 ) ;
F_194 () ;
V_18 -> V_100 = V_100 ;
V_18 -> V_105 = V_105 ;
V_18 -> V_11 = V_11 ;
F_138 (i) {
struct V_38 * V_316 = V_314 -> V_314 [ V_5 ] ;
if ( ! V_316 )
continue;
F_105 ( & V_18 -> V_42 [ F_53 ( V_5 ) ] -> V_14 ) ;
F_95 ( V_18 , V_316 -> V_112 , V_316 -> V_104 , F_53 ( V_5 ) ) ;
F_99 ( & V_18 -> V_42 [ F_53 ( V_5 ) ] -> V_14 ) ;
F_92 ( V_316 ) ;
}
F_92 ( V_314 ) ;
return F_294 ( V_18 , V_101 ) ;
}
static int F_298 ( struct V_17 * V_18 , int V_105 ,
int V_100 , int V_11 , T_5 V_101 )
{
int V_151 ;
struct V_17 * V_308 = NULL ;
int V_5 = 0 ;
V_151 = F_296 ( V_18 , V_105 , V_100 , V_11 , V_101 ) ;
if ( V_51 < V_191 )
return V_151 ;
if ( ( V_151 < 0 ) || ! F_299 ( V_18 ) )
return V_151 ;
F_18 ( ! F_300 ( & V_140 ) ) ;
F_301 (i) {
V_308 = F_302 ( V_18 , V_5 ) ;
if ( V_308 )
F_296 ( V_308 , V_105 , V_100 , V_11 , V_101 ) ;
}
return V_151 ;
}
static int F_133 ( struct V_17 * V_18 , T_5 V_101 )
{
int V_130 ;
int V_105 = 0 ;
int V_11 = 0 ;
int V_100 = 0 ;
if ( ! F_299 ( V_18 ) ) {
struct V_17 * V_317 = F_303 ( V_18 ) ;
V_105 = V_317 -> V_105 ;
V_11 = V_317 -> V_11 ;
V_100 = V_317 -> V_100 ;
}
if ( V_105 && V_11 && V_100 )
goto V_318;
if ( V_18 -> V_3 > 131072 )
V_105 = 1 ;
else if ( V_18 -> V_3 > V_75 )
V_105 = 8 ;
else if ( V_18 -> V_3 > 1024 )
V_105 = 24 ;
else if ( V_18 -> V_3 > 256 )
V_105 = 54 ;
else
V_105 = 120 ;
V_11 = 0 ;
if ( V_18 -> V_3 <= V_75 && F_304 () > 1 )
V_11 = 8 ;
#if V_61
if ( V_105 > 32 )
V_105 = 32 ;
#endif
V_100 = ( V_105 + 1 ) / 2 ;
V_318:
V_130 = F_298 ( V_18 , V_105 , V_100 , V_11 , V_101 ) ;
if ( V_130 )
F_44 ( V_80 L_38 ,
V_18 -> V_81 , - V_130 ) ;
return V_130 ;
}
static void F_202 ( struct V_17 * V_18 , struct V_6 * V_40 ,
struct V_38 * V_108 , int V_319 , int V_45 )
{
int V_253 ;
if ( ! V_108 || ! V_108 -> V_104 )
return;
if ( V_108 -> V_106 && ! V_319 ) {
V_108 -> V_106 = 0 ;
} else {
F_105 ( & V_40 -> V_14 ) ;
if ( V_108 -> V_104 ) {
V_253 = V_319 ? V_108 -> V_104 : ( V_108 -> V_105 + 4 ) / 5 ;
if ( V_253 > V_108 -> V_104 )
V_253 = ( V_108 -> V_104 + 1 ) / 2 ;
F_95 ( V_18 , V_108 -> V_112 , V_253 , V_45 ) ;
V_108 -> V_104 -= V_253 ;
memmove ( V_108 -> V_112 , & ( V_108 -> V_112 [ V_253 ] ) ,
sizeof( void * ) * V_108 -> V_104 ) ;
}
F_99 ( & V_40 -> V_14 ) ;
}
}
static void V_97 ( struct V_320 * V_321 )
{
struct V_17 * V_322 ;
struct V_6 * V_40 ;
int V_45 = F_71 () ;
struct V_92 * V_95 = F_305 ( V_321 ) ;
if ( ! F_306 ( & V_140 ) )
goto V_110;
F_73 (searchp, &slab_caches, list) {
F_194 () ;
V_40 = V_322 -> V_42 [ V_45 ] ;
F_97 ( V_322 , V_40 ) ;
F_202 ( V_322 , V_40 , F_34 ( V_322 ) , 0 , V_45 ) ;
if ( F_307 ( V_40 -> V_123 , V_124 ) )
goto V_260;
V_40 -> V_123 = V_124 + V_125 ;
F_202 ( V_322 , V_40 , V_40 -> V_11 , 0 , V_45 ) ;
if ( V_40 -> V_16 )
V_40 -> V_16 = 0 ;
else {
int V_323 ;
V_323 = F_110 ( V_322 , V_40 , ( V_40 -> V_126 +
5 * V_322 -> V_72 - 1 ) / ( 5 * V_322 -> V_72 ) ) ;
F_308 ( V_322 , V_323 ) ;
}
V_260:
F_309 () ;
}
F_194 () ;
F_115 ( & V_140 ) ;
F_56 () ;
V_110:
F_310 ( V_95 , F_311 ( V_324 ) ) ;
}
void F_312 ( struct V_17 * V_18 , struct V_325 * V_326 )
{
struct V_27 * V_107 ;
unsigned long V_195 ;
unsigned long V_196 ;
unsigned long V_197 = 0 ;
unsigned long V_198 , V_15 = 0 , V_327 = 0 ;
const char * V_81 ;
char * error = NULL ;
int V_45 ;
struct V_6 * V_40 ;
V_195 = 0 ;
V_198 = 0 ;
F_28 (node) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_194 () ;
F_105 ( & V_40 -> V_14 ) ;
F_73 (slabp, &l3->slabs_full, list) {
if ( V_107 -> V_199 != V_18 -> V_72 && ! error )
error = L_39 ;
V_195 += V_18 -> V_72 ;
V_197 ++ ;
}
F_73 (slabp, &l3->slabs_partial, list) {
if ( V_107 -> V_199 == V_18 -> V_72 && ! error )
error = L_40 ;
if ( ! V_107 -> V_199 && ! error )
error = L_41 ;
V_195 += V_107 -> V_199 ;
V_197 ++ ;
}
F_73 (slabp, &l3->slabs_free, list) {
if ( V_107 -> V_199 && ! error )
error = L_42 ;
V_198 ++ ;
}
V_15 += V_40 -> V_15 ;
if ( V_40 -> V_11 )
V_327 += V_40 -> V_11 -> V_104 ;
F_99 ( & V_40 -> V_14 ) ;
}
V_198 += V_197 ;
V_196 = V_198 * V_18 -> V_72 ;
if ( V_196 - V_195 != V_15 && ! error )
error = L_43 ;
V_81 = V_18 -> V_81 ;
if ( error )
F_44 ( V_80 L_44 , V_81 , error ) ;
V_326 -> V_195 = V_195 ;
V_326 -> V_196 = V_196 ;
V_326 -> V_197 = V_197 ;
V_326 -> V_198 = V_198 ;
V_326 -> V_327 = V_327 ;
V_326 -> V_105 = V_18 -> V_105 ;
V_326 -> V_100 = V_18 -> V_100 ;
V_326 -> V_11 = V_18 -> V_11 ;
V_326 -> V_328 = V_18 -> V_72 ;
V_326 -> V_329 = V_18 -> V_69 ;
}
void F_313 ( struct V_330 * V_331 , struct V_17 * V_18 )
{
#if V_305
{
unsigned long V_332 = V_18 -> V_333 ;
unsigned long V_334 = V_18 -> V_335 ;
unsigned long V_336 = V_18 -> V_336 ;
unsigned long V_337 = V_18 -> V_337 ;
unsigned long V_338 = V_18 -> V_338 ;
unsigned long V_339 = V_18 -> V_339 ;
unsigned long V_340 = V_18 -> V_340 ;
unsigned long V_341 = V_18 -> V_341 ;
unsigned long V_342 = V_18 -> V_343 ;
F_314 ( V_331 , L_45
L_46 ,
V_334 , V_332 , V_336 ,
V_337 , V_338 , V_339 , V_340 ,
V_341 , V_342 ) ;
}
{
unsigned long V_344 = F_315 ( & V_18 -> V_344 ) ;
unsigned long V_345 = F_315 ( & V_18 -> V_345 ) ;
unsigned long V_346 = F_315 ( & V_18 -> V_346 ) ;
unsigned long V_347 = F_315 ( & V_18 -> V_347 ) ;
F_314 ( V_331 , L_47 ,
V_344 , V_345 , V_346 , V_347 ) ;
}
#endif
}
T_11 F_316 ( struct V_348 * V_348 , const char T_12 * V_349 ,
T_2 V_350 , T_13 * V_351 )
{
char V_352 [ V_353 + 1 ] , * V_354 ;
int V_105 , V_100 , V_11 , V_355 ;
struct V_17 * V_18 ;
if ( V_350 > V_353 )
return - V_356 ;
if ( F_317 ( & V_352 , V_349 , V_350 ) )
return - V_357 ;
V_352 [ V_353 ] = '\0' ;
V_354 = strchr ( V_352 , ' ' ) ;
if ( ! V_354 )
return - V_356 ;
* V_354 = '\0' ;
V_354 ++ ;
if ( sscanf ( V_354 , L_48 , & V_105 , & V_100 , & V_11 ) != 3 )
return - V_356 ;
F_114 ( & V_140 ) ;
V_355 = - V_356 ;
F_73 (cachep, &slab_caches, list) {
if ( ! strcmp ( V_18 -> V_81 , V_352 ) ) {
if ( V_105 < 1 || V_100 < 1 ||
V_100 > V_105 || V_11 < 0 ) {
V_355 = 0 ;
} else {
V_355 = F_298 ( V_18 , V_105 ,
V_100 , V_11 ,
V_121 ) ;
}
break;
}
}
F_115 ( & V_140 ) ;
if ( V_355 >= 0 )
V_355 = V_350 ;
return V_355 ;
}
static void * F_318 ( struct V_330 * V_331 , T_13 * V_358 )
{
F_114 ( & V_140 ) ;
return F_319 ( & V_181 , * V_358 ) ;
}
static inline int F_320 ( unsigned long * V_359 , unsigned long V_360 )
{
unsigned long * V_255 ;
int V_361 ;
if ( ! V_360 )
return 1 ;
V_361 = V_359 [ 1 ] ;
V_255 = V_359 + 2 ;
while ( V_361 ) {
int V_5 = V_361 / 2 ;
unsigned long * V_37 = V_255 + 2 * V_5 ;
if ( * V_37 == V_360 ) {
V_37 [ 1 ] ++ ;
return 1 ;
}
if ( * V_37 > V_360 ) {
V_361 = V_5 ;
} else {
V_255 = V_37 + 2 ;
V_361 -= V_5 + 1 ;
}
}
if ( ++ V_359 [ 1 ] == V_359 [ 0 ] )
return 0 ;
memmove ( V_255 + 2 , V_255 , V_359 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_255 - ( void * ) V_359 ) ) ;
V_255 [ 0 ] = V_360 ;
V_255 [ 1 ] = 1 ;
return 1 ;
}
static void F_321 ( unsigned long * V_359 , struct V_17 * V_308 , struct V_27 * V_49 )
{
void * V_255 ;
int V_5 ;
if ( V_359 [ 0 ] == V_359 [ 1 ] )
return;
for ( V_5 = 0 , V_255 = V_49 -> V_31 ; V_5 < V_308 -> V_72 ; V_5 ++ , V_255 += V_308 -> V_3 ) {
if ( F_213 ( V_49 ) [ V_5 ] != V_279 )
continue;
if ( ! F_320 ( V_359 , ( unsigned long ) * F_14 ( V_308 , V_255 ) ) )
return;
}
}
static void F_322 ( struct V_330 * V_331 , unsigned long V_362 )
{
#ifdef F_323
unsigned long V_32 , V_3 ;
char V_363 [ V_364 ] , V_81 [ V_365 ] ;
if ( F_324 ( V_362 , & V_3 , & V_32 , V_363 , V_81 ) == 0 ) {
F_314 ( V_331 , L_49 , V_81 , V_32 , V_3 ) ;
if ( V_363 [ 0 ] )
F_314 ( V_331 , L_50 , V_363 ) ;
return;
}
#endif
F_314 ( V_331 , L_51 , ( void * ) V_362 ) ;
}
static int F_325 ( struct V_330 * V_331 , void * V_255 )
{
struct V_17 * V_18 = F_203 ( V_255 , struct V_17 , V_165 ) ;
struct V_27 * V_107 ;
struct V_6 * V_40 ;
const char * V_81 ;
unsigned long * V_359 = V_331 -> V_366 ;
int V_45 ;
int V_5 ;
if ( ! ( V_18 -> V_19 & V_21 ) )
return 0 ;
if ( ! ( V_18 -> V_19 & V_20 ) )
return 0 ;
V_359 [ 1 ] = 0 ;
F_28 (node) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_194 () ;
F_105 ( & V_40 -> V_14 ) ;
F_73 (slabp, &l3->slabs_full, list)
F_321 ( V_359 , V_18 , V_107 ) ;
F_73 (slabp, &l3->slabs_partial, list)
F_321 ( V_359 , V_18 , V_107 ) ;
F_99 ( & V_40 -> V_14 ) ;
}
V_81 = V_18 -> V_81 ;
if ( V_359 [ 0 ] == V_359 [ 1 ] ) {
F_115 ( & V_140 ) ;
V_331 -> V_366 = F_297 ( V_359 [ 0 ] * 4 * sizeof( unsigned long ) , V_121 ) ;
if ( ! V_331 -> V_366 ) {
V_331 -> V_366 = V_359 ;
F_114 ( & V_140 ) ;
return - V_122 ;
}
* ( unsigned long * ) V_331 -> V_366 = V_359 [ 0 ] * 2 ;
F_92 ( V_359 ) ;
F_114 ( & V_140 ) ;
V_331 -> V_350 = V_331 -> V_3 ;
return 0 ;
}
for ( V_5 = 0 ; V_5 < V_359 [ 1 ] ; V_5 ++ ) {
F_314 ( V_331 , L_52 , V_81 , V_359 [ 2 * V_5 + 3 ] ) ;
F_322 ( V_331 , V_359 [ 2 * V_5 + 2 ] ) ;
F_326 ( V_331 , '\n' ) ;
}
return 0 ;
}
static void * F_327 ( struct V_330 * V_331 , void * V_255 , T_13 * V_358 )
{
return F_328 ( V_255 , & V_181 , V_358 ) ;
}
static void F_329 ( struct V_330 * V_331 , void * V_255 )
{
F_115 ( & V_140 ) ;
}
static int F_330 ( struct V_367 * V_367 , struct V_348 * V_348 )
{
unsigned long * V_359 = F_297 ( V_75 , V_121 ) ;
int V_151 = - V_122 ;
if ( V_359 ) {
V_151 = F_331 ( V_348 , & V_368 ) ;
if ( ! V_151 ) {
struct V_330 * V_331 = V_348 -> V_369 ;
* V_359 = V_75 / ( 2 * sizeof( unsigned long ) ) ;
V_331 -> V_366 = V_359 ;
V_359 = NULL ;
}
F_92 ( V_359 ) ;
}
return V_151 ;
}
static int T_6 F_332 ( void )
{
#ifdef F_230
F_333 ( L_53 , 0 , NULL , & V_370 ) ;
#endif
return 0 ;
}
T_2 F_334 ( const void * V_1 )
{
F_12 ( ! V_1 ) ;
if ( F_38 ( V_1 == V_63 ) )
return 0 ;
return F_15 ( V_1 ) -> V_223 ;
}
