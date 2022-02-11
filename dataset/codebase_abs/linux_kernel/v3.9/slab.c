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
F_46 ( V_82 , V_83 ) ;
}
static int T_6 F_47 ( char * V_49 )
{
V_84 = 0 ;
return 1 ;
}
static int T_6 F_48 ( char * V_85 )
{
F_49 ( & V_85 , & V_86 ) ;
V_86 = V_86 < 0 ? 0 :
F_50 ( V_86 , V_87 - 1 ) ;
V_88 = true ;
return 1 ;
}
static void F_51 ( int V_89 )
{
int V_45 ;
V_45 = F_52 ( F_53 ( V_89 ) , V_90 ) ;
if ( V_45 == V_91 )
V_45 = F_54 ( V_90 ) ;
F_55 ( V_92 , V_89 ) = V_45 ;
}
static void F_56 ( void )
{
int V_45 = F_57 ( V_92 ) ;
V_45 = F_52 ( V_45 , V_90 ) ;
if ( F_38 ( V_45 >= V_91 ) )
V_45 = F_54 ( V_90 ) ;
F_58 ( V_92 , V_45 ) ;
}
static void T_7 F_59 ( int V_89 )
{
struct V_93 * V_94 = & F_55 ( V_95 , V_89 ) ;
if ( F_60 () && V_94 -> V_96 . V_97 == NULL ) {
F_51 ( V_89 ) ;
F_61 ( V_94 , V_98 ) ;
F_62 ( V_89 , V_94 ,
F_63 ( V_99 , V_89 ) ) ;
}
}
static struct V_38 * F_64 ( int V_45 , int V_100 ,
int V_101 , T_5 V_102 )
{
int V_103 = sizeof( void * ) * V_100 + sizeof( struct V_38 ) ;
struct V_38 * V_104 = NULL ;
V_104 = F_65 ( V_103 , V_102 , V_45 ) ;
F_66 ( V_104 ) ;
if ( V_104 ) {
V_104 -> V_105 = 0 ;
V_104 -> V_106 = V_100 ;
V_104 -> V_101 = V_101 ;
V_104 -> V_107 = 0 ;
F_9 ( & V_104 -> V_44 ) ;
}
return V_104 ;
}
static inline bool F_67 ( struct V_27 * V_108 )
{
struct V_25 * V_25 = F_68 ( V_108 -> V_31 ) ;
return F_69 ( V_25 ) ;
}
static void F_70 ( struct V_17 * V_18 ,
struct V_38 * V_109 )
{
struct V_6 * V_40 = V_18 -> V_42 [ F_71 () ] ;
struct V_27 * V_108 ;
unsigned long V_19 ;
if ( ! V_110 )
return;
F_72 ( & V_40 -> V_14 , V_19 ) ;
F_73 (slabp, &l3->slabs_full, list)
if ( F_67 ( V_108 ) )
goto V_111;
F_73 (slabp, &l3->slabs_partial, list)
if ( F_67 ( V_108 ) )
goto V_111;
F_73 (slabp, &l3->slabs_free, list)
if ( F_67 ( V_108 ) )
goto V_111;
V_110 = false ;
V_111:
F_74 ( & V_40 -> V_14 , V_19 ) ;
}
static void * F_75 ( struct V_17 * V_18 , struct V_38 * V_109 ,
T_5 V_19 , bool V_112 )
{
int V_5 ;
void * V_1 = V_109 -> V_113 [ -- V_109 -> V_105 ] ;
if ( F_38 ( F_1 ( V_1 ) ) ) {
struct V_6 * V_40 ;
if ( F_76 ( V_19 ) ) {
F_3 ( & V_1 ) ;
return V_1 ;
}
for ( V_5 = 0 ; V_5 < V_109 -> V_105 ; V_5 ++ ) {
if ( ! F_1 ( V_109 -> V_113 [ V_5 ] ) ) {
V_1 = V_109 -> V_113 [ V_5 ] ;
V_109 -> V_113 [ V_5 ] = V_109 -> V_113 [ V_109 -> V_105 ] ;
V_109 -> V_113 [ V_109 -> V_105 ] = V_1 ;
return V_1 ;
}
}
V_40 = V_18 -> V_42 [ F_71 () ] ;
if ( ! F_77 ( & V_40 -> V_10 ) && V_112 ) {
struct V_27 * V_108 = F_17 ( V_1 ) ;
F_78 ( F_16 ( V_108 -> V_31 ) ) ;
F_3 ( & V_1 ) ;
F_70 ( V_18 , V_109 ) ;
return V_1 ;
}
V_109 -> V_105 ++ ;
V_1 = NULL ;
}
return V_1 ;
}
static inline void * F_79 ( struct V_17 * V_18 ,
struct V_38 * V_109 , T_5 V_19 , bool V_112 )
{
void * V_1 ;
if ( F_38 ( F_80 () ) )
V_1 = F_75 ( V_18 , V_109 , V_19 , V_112 ) ;
else
V_1 = V_109 -> V_113 [ -- V_109 -> V_105 ] ;
return V_1 ;
}
static void * F_81 ( struct V_17 * V_18 , struct V_38 * V_109 ,
void * V_1 )
{
if ( F_38 ( V_110 ) ) {
struct V_25 * V_25 = F_16 ( V_1 ) ;
if ( F_69 ( V_25 ) )
F_2 ( & V_1 ) ;
}
return V_1 ;
}
static inline void F_82 ( struct V_17 * V_18 , struct V_38 * V_109 ,
void * V_1 )
{
if ( F_38 ( F_80 () ) )
V_1 = F_81 ( V_18 , V_109 , V_1 ) ;
V_109 -> V_113 [ V_109 -> V_105 ++ ] = V_1 ;
}
static int F_83 ( struct V_38 * V_114 ,
struct V_38 * V_115 , unsigned int V_116 )
{
int V_117 = F_84 ( V_115 -> V_105 , V_116 , V_114 -> V_106 - V_114 -> V_105 ) ;
if ( ! V_117 )
return 0 ;
memcpy ( V_114 -> V_113 + V_114 -> V_105 , V_115 -> V_113 + V_115 -> V_105 - V_117 ,
sizeof( void * ) * V_117 ) ;
V_115 -> V_105 -= V_117 ;
V_114 -> V_105 += V_117 ;
return V_117 ;
}
static inline struct V_38 * * F_85 ( int V_45 , int V_106 , T_5 V_102 )
{
return (struct V_38 * * ) V_43 ;
}
static inline void F_86 ( struct V_38 * * V_118 )
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
T_5 V_19 , int V_119 )
{
return NULL ;
}
static struct V_38 * * F_85 ( int V_45 , int V_106 , T_5 V_102 )
{
struct V_38 * * V_118 ;
int V_103 = sizeof( void * ) * V_120 ;
int V_5 ;
if ( V_106 > 1 )
V_106 = 12 ;
V_118 = F_90 ( V_103 , V_102 , V_45 ) ;
if ( V_118 ) {
F_25 (i) {
if ( V_5 == V_45 || ! F_91 ( V_5 ) )
continue;
V_118 [ V_5 ] = F_64 ( V_45 , V_106 , 0xbaadf00d , V_102 ) ;
if ( ! V_118 [ V_5 ] ) {
for ( V_5 -- ; V_5 >= 0 ; V_5 -- )
F_92 ( V_118 [ V_5 ] ) ;
F_92 ( V_118 ) ;
return NULL ;
}
}
}
return V_118 ;
}
static void F_86 ( struct V_38 * * V_118 )
{
int V_5 ;
if ( ! V_118 )
return;
F_25 (i)
F_92 ( V_118 [ V_5 ] ) ;
F_92 ( V_118 ) ;
}
static void F_93 ( struct V_17 * V_18 ,
struct V_38 * V_109 , int V_45 )
{
struct V_6 * V_121 = V_18 -> V_42 [ V_45 ] ;
if ( V_109 -> V_105 ) {
F_94 ( & V_121 -> V_14 ) ;
if ( V_121 -> V_11 )
F_83 ( V_121 -> V_11 , V_109 , V_109 -> V_106 ) ;
F_95 ( V_18 , V_109 -> V_113 , V_109 -> V_105 , V_45 ) ;
V_109 -> V_105 = 0 ;
F_96 ( & V_121 -> V_14 ) ;
}
}
static void F_97 ( struct V_17 * V_18 , struct V_6 * V_40 )
{
int V_45 = F_57 ( V_92 ) ;
if ( V_40 -> V_12 ) {
struct V_38 * V_109 = V_40 -> V_12 [ V_45 ] ;
if ( V_109 && V_109 -> V_105 && F_98 ( & V_109 -> V_44 ) ) {
F_93 ( V_18 , V_109 , V_45 ) ;
F_99 ( & V_109 -> V_44 ) ;
}
}
}
static void F_100 ( struct V_17 * V_18 ,
struct V_38 * * V_12 )
{
int V_5 = 0 ;
struct V_38 * V_109 ;
unsigned long V_19 ;
F_28 (i) {
V_109 = V_12 [ V_5 ] ;
if ( V_109 ) {
F_72 ( & V_109 -> V_44 , V_19 ) ;
F_93 ( V_18 , V_109 , V_5 ) ;
F_74 ( & V_109 -> V_44 , V_19 ) ;
}
}
}
static inline int F_87 ( struct V_17 * V_18 , void * V_1 )
{
struct V_27 * V_108 = F_17 ( V_1 ) ;
int V_119 = V_108 -> V_119 ;
struct V_6 * V_40 ;
struct V_38 * V_12 = NULL ;
int V_45 ;
V_45 = F_71 () ;
if ( F_101 ( V_108 -> V_119 == V_45 ) )
return 0 ;
V_40 = V_18 -> V_42 [ V_45 ] ;
F_102 ( V_18 ) ;
if ( V_40 -> V_12 && V_40 -> V_12 [ V_119 ] ) {
V_12 = V_40 -> V_12 [ V_119 ] ;
F_94 ( & V_12 -> V_44 ) ;
if ( F_38 ( V_12 -> V_105 == V_12 -> V_106 ) ) {
F_103 ( V_18 ) ;
F_93 ( V_18 , V_12 , V_119 ) ;
}
F_82 ( V_18 , V_12 , V_1 ) ;
F_96 ( & V_12 -> V_44 ) ;
} else {
F_94 ( & ( V_18 -> V_42 [ V_119 ] ) -> V_14 ) ;
F_95 ( V_18 , & V_1 , 1 , V_119 ) ;
F_96 ( & ( V_18 -> V_42 [ V_119 ] ) -> V_14 ) ;
}
return 1 ;
}
static int F_104 ( int V_45 )
{
struct V_17 * V_18 ;
struct V_6 * V_40 ;
const int V_103 = sizeof( struct V_6 ) ;
F_73 (cachep, &slab_caches, list) {
if ( ! V_18 -> V_42 [ V_45 ] ) {
V_40 = F_65 ( V_103 , V_122 , V_45 ) ;
if ( ! V_40 )
return - V_123 ;
F_7 ( V_40 ) ;
V_40 -> V_124 = V_125 + V_126 +
( ( unsigned long ) V_18 ) % V_126 ;
V_18 -> V_42 [ V_45 ] = V_40 ;
}
F_105 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
V_18 -> V_42 [ V_45 ] -> V_127 =
( 1 + F_106 ( V_45 ) ) *
V_18 -> V_101 + V_18 -> V_72 ;
F_99 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
}
return 0 ;
}
static void T_7 F_107 ( long V_89 )
{
struct V_17 * V_18 ;
struct V_6 * V_40 = NULL ;
int V_45 = F_53 ( V_89 ) ;
const struct V_128 * V_129 = F_108 ( V_45 ) ;
F_73 (cachep, &slab_caches, list) {
struct V_38 * V_104 ;
struct V_38 * V_11 ;
struct V_38 * * V_12 ;
V_104 = V_18 -> V_58 [ V_89 ] ;
V_18 -> V_58 [ V_89 ] = NULL ;
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
goto V_130;
F_105 ( & V_40 -> V_14 ) ;
V_40 -> V_127 -= V_18 -> V_101 ;
if ( V_104 )
F_95 ( V_18 , V_104 -> V_113 , V_104 -> V_105 , V_45 ) ;
if ( ! F_109 ( V_129 ) ) {
F_99 ( & V_40 -> V_14 ) ;
goto V_130;
}
V_11 = V_40 -> V_11 ;
if ( V_11 ) {
F_95 ( V_18 , V_11 -> V_113 ,
V_11 -> V_105 , V_45 ) ;
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
V_130:
F_92 ( V_104 ) ;
}
F_73 (cachep, &slab_caches, list) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_110 ( V_18 , V_40 , V_40 -> V_15 ) ;
}
}
static int T_7 F_111 ( long V_89 )
{
struct V_17 * V_18 ;
struct V_6 * V_40 = NULL ;
int V_45 = F_53 ( V_89 ) ;
int V_131 ;
V_131 = F_104 ( V_45 ) ;
if ( V_131 < 0 )
goto V_132;
F_73 (cachep, &slab_caches, list) {
struct V_38 * V_104 ;
struct V_38 * V_11 = NULL ;
struct V_38 * * V_12 = NULL ;
V_104 = F_64 ( V_45 , V_18 -> V_106 ,
V_18 -> V_101 , V_122 ) ;
if ( ! V_104 )
goto V_132;
if ( V_18 -> V_11 ) {
V_11 = F_64 ( V_45 ,
V_18 -> V_11 * V_18 -> V_101 ,
0xbaadf00d , V_122 ) ;
if ( ! V_11 ) {
F_92 ( V_104 ) ;
goto V_132;
}
}
if ( V_84 ) {
V_12 = F_85 ( V_45 , V_18 -> V_106 , V_122 ) ;
if ( ! V_12 ) {
F_92 ( V_11 ) ;
F_92 ( V_104 ) ;
goto V_132;
}
}
V_18 -> V_58 [ V_89 ] = V_104 ;
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
if ( V_18 -> V_19 & V_133 )
F_26 ( V_18 , V_45 ) ;
else if ( ! F_30 ( V_18 ) &&
! ( V_18 -> V_19 & V_134 ) )
F_31 ( V_18 , V_45 ) ;
}
F_29 ( V_45 ) ;
return 0 ;
V_132:
F_107 ( V_89 ) ;
return - V_123 ;
}
static int T_7 F_113 ( struct V_135 * V_136 ,
unsigned long V_137 , void * V_138 )
{
long V_89 = ( long ) V_138 ;
int V_131 = 0 ;
switch ( V_137 ) {
case V_139 :
case V_140 :
F_114 ( & V_141 ) ;
V_131 = F_111 ( V_89 ) ;
F_115 ( & V_141 ) ;
break;
case V_142 :
case V_143 :
F_59 ( V_89 ) ;
break;
#ifdef F_116
case V_144 :
case V_145 :
F_117 ( & F_55 ( V_95 , V_89 ) ) ;
F_55 ( V_95 , V_89 ) . V_96 . V_97 = NULL ;
break;
case V_146 :
case V_147 :
F_59 ( V_89 ) ;
break;
case V_148 :
case V_149 :
#endif
case V_150 :
case V_151 :
F_114 ( & V_141 ) ;
F_107 ( V_89 ) ;
F_115 ( & V_141 ) ;
break;
}
return F_118 ( V_131 ) ;
}
static int T_8 F_119 ( int V_45 )
{
struct V_17 * V_18 ;
int V_152 = 0 ;
F_73 (cachep, &slab_caches, list) {
struct V_6 * V_40 ;
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_110 ( V_18 , V_40 , V_40 -> V_15 ) ;
if ( ! F_77 ( & V_40 -> V_8 ) ||
! F_77 ( & V_40 -> V_9 ) ) {
V_152 = - V_153 ;
break;
}
}
return V_152 ;
}
static int T_8 F_120 ( struct V_135 * V_154 ,
unsigned long V_137 , void * V_155 )
{
struct V_156 * V_157 = V_155 ;
int V_152 = 0 ;
int V_158 ;
V_158 = V_157 -> V_159 ;
if ( V_158 < 0 )
goto V_111;
switch ( V_137 ) {
case V_160 :
F_114 ( & V_141 ) ;
V_152 = F_104 ( V_158 ) ;
F_115 ( & V_141 ) ;
break;
case V_161 :
F_114 ( & V_141 ) ;
V_152 = F_119 ( V_158 ) ;
F_115 ( & V_141 ) ;
break;
case V_162 :
case V_163 :
case V_164 :
case V_165 :
break;
}
V_111:
return F_118 ( V_152 ) ;
}
static void T_6 F_121 ( struct V_17 * V_18 , struct V_6 * V_166 ,
int V_119 )
{
struct V_6 * V_167 ;
V_167 = F_65 ( sizeof( struct V_6 ) , V_168 , V_119 ) ;
F_12 ( ! V_167 ) ;
memcpy ( V_167 , V_166 , sizeof( struct V_6 ) ) ;
F_9 ( & V_167 -> V_14 ) ;
F_122 ( V_18 , V_167 , V_119 ) ;
V_18 -> V_42 [ V_119 ] = V_167 ;
}
static void T_6 F_123 ( struct V_17 * V_18 , int V_169 )
{
int V_45 ;
F_28 (node) {
V_18 -> V_42 [ V_45 ] = & V_170 [ V_169 + V_45 ] ;
V_18 -> V_42 [ V_45 ] -> V_124 = V_125 +
V_126 +
( ( unsigned long ) V_18 ) % V_126 ;
}
}
static void F_124 ( struct V_17 * V_18 )
{
V_18 -> V_42 = (struct V_6 * * ) & V_18 -> V_58 [ V_171 ] ;
}
void T_6 F_125 ( void )
{
struct V_48 * V_172 ;
struct V_173 * V_174 ;
int V_5 ;
V_17 = & V_175 ;
F_124 ( V_17 ) ;
if ( F_126 () == 1 )
V_84 = 0 ;
for ( V_5 = 0 ; V_5 < V_176 ; V_5 ++ )
F_7 ( & V_170 [ V_5 ] ) ;
F_123 ( V_17 , V_177 ) ;
if ( ! V_88 && V_178 > ( 32 << 20 ) >> V_179 )
V_86 = V_180 ;
F_127 ( V_17 , L_2 ,
F_128 ( struct V_17 , V_58 [ V_171 ] ) +
V_120 * sizeof( struct V_6 * ) ,
V_181 ) ;
F_129 ( & V_17 -> V_166 , & V_182 ) ;
V_172 = V_50 ;
V_174 = V_173 ;
V_172 [ V_62 ] . V_55 = F_130 ( V_174 [ V_62 ] . V_81 ,
V_172 [ V_62 ] . V_53 , V_183 ) ;
if ( V_62 != V_184 )
V_172 [ V_184 ] . V_55 =
F_130 ( V_174 [ V_184 ] . V_81 ,
V_172 [ V_184 ] . V_53 , V_183 ) ;
V_185 = 0 ;
while ( V_172 -> V_53 != V_54 ) {
if ( ! V_172 -> V_55 )
V_172 -> V_55 = F_130 ( V_174 -> V_81 ,
V_172 -> V_53 , V_183 ) ;
#ifdef F_37
V_172 -> V_65 = F_130 (
V_174 -> V_186 , V_172 -> V_53 ,
V_187 | V_183 ) ;
#endif
V_172 ++ ;
V_174 ++ ;
}
{
struct V_38 * V_167 ;
V_167 = F_131 ( sizeof( struct V_188 ) , V_168 ) ;
memcpy ( V_167 , F_34 ( V_17 ) ,
sizeof( struct V_188 ) ) ;
F_9 ( & V_167 -> V_44 ) ;
V_17 -> V_58 [ F_35 () ] = V_167 ;
V_167 = F_131 ( sizeof( struct V_188 ) , V_168 ) ;
F_12 ( F_34 ( V_50 [ V_62 ] . V_55 )
!= & V_189 . V_29 ) ;
memcpy ( V_167 , F_34 ( V_50 [ V_62 ] . V_55 ) ,
sizeof( struct V_188 ) ) ;
F_9 ( & V_167 -> V_44 ) ;
V_50 [ V_62 ] . V_55 -> V_58 [ F_35 () ] =
V_167 ;
}
{
int V_158 ;
F_28 (nid) {
F_121 ( V_17 , & V_170 [ V_177 + V_158 ] , V_158 ) ;
F_121 ( V_50 [ V_62 ] . V_55 ,
& V_170 [ V_190 + V_158 ] , V_158 ) ;
if ( V_62 != V_184 ) {
F_121 ( V_50 [ V_184 ] . V_55 ,
& V_170 [ V_191 + V_158 ] , V_158 ) ;
}
}
}
V_51 = V_52 ;
}
void T_6 F_132 ( void )
{
struct V_17 * V_18 ;
V_51 = V_52 ;
F_114 ( & V_141 ) ;
F_73 (cachep, &slab_caches, list)
if ( F_133 ( V_18 , V_168 ) )
F_134 () ;
F_115 ( & V_141 ) ;
F_33 () ;
V_51 = V_192 ;
F_135 ( & V_193 ) ;
#ifdef F_112
F_136 ( F_120 , V_194 ) ;
#endif
}
static int T_6 F_137 ( void )
{
int V_89 ;
F_138 (cpu)
F_59 ( V_89 ) ;
V_51 = V_192 ;
return 0 ;
}
static T_9 void
F_139 ( struct V_17 * V_18 , T_5 V_59 , int V_119 )
{
struct V_6 * V_40 ;
struct V_27 * V_108 ;
unsigned long V_19 ;
int V_45 ;
F_44 ( V_195
L_3 ,
V_119 , V_59 ) ;
F_44 ( V_195 L_4 ,
V_18 -> V_81 , V_18 -> V_3 , V_18 -> V_69 ) ;
F_28 (node) {
unsigned long V_196 = 0 , V_197 = 0 , V_15 = 0 ;
unsigned long V_198 = 0 , V_199 = 0 ;
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_72 ( & V_40 -> V_14 , V_19 ) ;
F_73 (slabp, &l3->slabs_full, list) {
V_196 += V_18 -> V_72 ;
V_198 ++ ;
}
F_73 (slabp, &l3->slabs_partial, list) {
V_196 += V_108 -> V_200 ;
V_198 ++ ;
}
F_73 (slabp, &l3->slabs_free, list)
V_199 ++ ;
V_15 += V_40 -> V_15 ;
F_74 ( & V_40 -> V_14 , V_19 ) ;
V_199 += V_198 ;
V_197 = V_199 * V_18 -> V_72 ;
F_44 ( V_195
L_5 ,
V_45 , V_198 , V_199 , V_196 , V_197 ,
V_15 ) ;
}
}
static void * F_140 ( struct V_17 * V_18 , T_5 V_19 , int V_119 )
{
struct V_25 * V_25 ;
int V_201 ;
int V_5 ;
#ifndef F_141
V_19 |= V_202 ;
#endif
V_19 |= V_18 -> V_203 ;
if ( V_18 -> V_19 & V_204 )
V_19 |= V_205 ;
V_25 = F_142 ( V_119 , V_19 | V_206 , V_18 -> V_69 ) ;
if ( ! V_25 ) {
if ( ! ( V_19 & V_207 ) && F_143 () )
F_139 ( V_18 , V_19 , V_119 ) ;
return NULL ;
}
if ( F_38 ( V_25 -> V_208 ) )
V_110 = true ;
V_201 = ( 1 << V_18 -> V_69 ) ;
if ( V_18 -> V_19 & V_204 )
F_144 ( F_145 ( V_25 ) ,
V_209 , V_201 ) ;
else
F_144 ( F_145 ( V_25 ) ,
V_210 , V_201 ) ;
for ( V_5 = 0 ; V_5 < V_201 ; V_5 ++ ) {
F_146 ( V_25 + V_5 ) ;
if ( V_25 -> V_208 )
F_147 ( V_25 + V_5 ) ;
}
F_148 ( V_18 , V_18 -> V_69 ) ;
if ( V_211 && ! ( V_18 -> V_19 & V_212 ) ) {
F_149 ( V_25 , V_18 -> V_69 , V_19 , V_119 ) ;
if ( V_18 -> V_213 )
F_150 ( V_25 , V_201 ) ;
else
F_151 ( V_25 , V_201 ) ;
}
return F_152 ( V_25 ) ;
}
static void F_153 ( struct V_17 * V_18 , void * V_214 )
{
unsigned long V_5 = ( 1 << V_18 -> V_69 ) ;
struct V_25 * V_25 = F_68 ( V_214 ) ;
const unsigned long V_215 = V_5 ;
F_154 ( V_25 , V_18 -> V_69 ) ;
if ( V_18 -> V_19 & V_204 )
F_155 ( F_145 ( V_25 ) ,
V_209 , V_215 ) ;
else
F_155 ( F_145 ( V_25 ) ,
V_210 , V_215 ) ;
while ( V_5 -- ) {
F_12 ( ! F_19 ( V_25 ) ) ;
F_156 ( V_25 ) ;
F_157 ( V_25 ) ;
V_25 ++ ;
}
F_158 ( V_18 , V_18 -> V_69 ) ;
if ( V_216 -> V_217 )
V_216 -> V_217 -> V_218 += V_215 ;
F_159 ( ( unsigned long ) V_214 , V_18 -> V_69 ) ;
}
static void F_160 ( struct V_219 * V_220 )
{
struct V_221 * V_221 = (struct V_221 * ) V_220 ;
struct V_17 * V_18 = V_221 -> V_18 ;
F_153 ( V_18 , V_221 -> V_214 ) ;
if ( F_30 ( V_18 ) )
F_161 ( V_18 -> V_222 , V_221 ) ;
}
static void F_162 ( struct V_17 * V_18 , unsigned long * V_214 ,
unsigned long V_223 )
{
int V_3 = V_18 -> V_224 ;
V_214 = ( unsigned long * ) & ( ( char * ) V_214 ) [ F_10 ( V_18 ) ] ;
if ( V_3 < 5 * sizeof( unsigned long ) )
return;
* V_214 ++ = 0x12345678 ;
* V_214 ++ = V_223 ;
* V_214 ++ = F_35 () ;
V_3 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_225 = & V_223 ;
unsigned long V_226 ;
while ( ! F_163 ( V_225 ) ) {
V_226 = * V_225 ++ ;
if ( F_164 ( V_226 ) ) {
* V_214 ++ = V_226 ;
V_3 -= sizeof( unsigned long ) ;
if ( V_3 <= sizeof( unsigned long ) )
break;
}
}
}
* V_214 ++ = 0x87654321 ;
}
static void F_165 ( struct V_17 * V_18 , void * V_214 , unsigned char V_227 )
{
int V_3 = V_18 -> V_224 ;
V_214 = & ( ( char * ) V_214 ) [ F_10 ( V_18 ) ] ;
memset ( V_214 , V_227 , V_3 ) ;
* ( unsigned char * ) ( V_214 + V_3 - 1 ) = V_228 ;
}
static void F_166 ( char * V_229 , int V_32 , int V_106 )
{
int V_5 ;
unsigned char error = 0 ;
int V_230 = 0 ;
F_44 ( V_80 L_6 , V_32 ) ;
for ( V_5 = 0 ; V_5 < V_106 ; V_5 ++ ) {
if ( V_229 [ V_32 + V_5 ] != V_231 ) {
error = V_229 [ V_32 + V_5 ] ;
V_230 ++ ;
}
}
F_167 ( V_232 , L_7 , 0 , 16 , 1 ,
& V_229 [ V_32 ] , V_106 , 1 ) ;
if ( V_230 == 1 ) {
error ^= V_231 ;
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
static void F_169 ( struct V_17 * V_18 , void * V_1 , int V_233 )
{
int V_5 , V_3 ;
char * V_234 ;
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
V_234 = ( char * ) V_1 + F_10 ( V_18 ) ;
V_3 = V_18 -> V_224 ;
for ( V_5 = 0 ; V_5 < V_3 && V_233 ; V_5 += 16 , V_233 -- ) {
int V_106 ;
V_106 = 16 ;
if ( V_5 + V_106 > V_3 )
V_106 = V_3 - V_5 ;
F_166 ( V_234 , V_5 , V_106 ) ;
}
}
static void F_171 ( struct V_17 * V_18 , void * V_1 )
{
char * V_234 ;
int V_3 , V_5 ;
int V_233 = 0 ;
V_234 = ( char * ) V_1 + F_10 ( V_18 ) ;
V_3 = V_18 -> V_224 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
char exp = V_231 ;
if ( V_5 == V_3 - 1 )
exp = V_228 ;
if ( V_234 [ V_5 ] != exp ) {
int V_106 ;
if ( V_233 == 0 ) {
F_44 ( V_80
L_17 ,
F_172 () , V_18 -> V_81 , V_234 , V_3 ) ;
F_169 ( V_18 , V_1 , 0 ) ;
}
V_5 = ( V_5 / 16 ) * 16 ;
V_106 = 16 ;
if ( V_5 + V_106 > V_3 )
V_106 = V_3 - V_5 ;
F_166 ( V_234 , V_5 , V_106 ) ;
V_5 += 16 ;
V_233 ++ ;
if ( V_233 > 5 )
break;
}
}
if ( V_233 != 0 ) {
struct V_27 * V_108 = F_17 ( V_1 ) ;
unsigned int V_235 ;
V_235 = F_21 ( V_18 , V_108 , V_1 ) ;
if ( V_235 ) {
V_1 = F_20 ( V_18 , V_108 , V_235 - 1 ) ;
V_234 = ( char * ) V_1 + F_10 ( V_18 ) ;
F_44 ( V_80 L_18 ,
V_234 , V_3 ) ;
F_169 ( V_18 , V_1 , 2 ) ;
}
if ( V_235 + 1 < V_18 -> V_72 ) {
V_1 = F_20 ( V_18 , V_108 , V_235 + 1 ) ;
V_234 = ( char * ) V_1 + F_10 ( V_18 ) ;
F_44 ( V_80 L_19 ,
V_234 , V_3 ) ;
F_169 ( V_18 , V_1 , 2 ) ;
}
}
}
static void F_173 ( struct V_17 * V_18 , struct V_27 * V_108 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_72 ; V_5 ++ ) {
void * V_1 = F_20 ( V_18 , V_108 , V_5 ) ;
if ( V_18 -> V_19 & V_236 ) {
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
if ( * F_11 ( V_18 , V_1 ) != V_237 )
F_176 ( V_18 , L_20
L_21 ) ;
if ( * F_13 ( V_18 , V_1 ) != V_237 )
F_176 ( V_18 , L_22
L_21 ) ;
}
}
}
static void F_173 ( struct V_17 * V_18 , struct V_27 * V_108 )
{
}
static void F_177 ( struct V_17 * V_18 , struct V_27 * V_108 )
{
void * V_214 = V_108 -> V_31 - V_108 -> V_238 ;
F_173 ( V_18 , V_108 ) ;
if ( F_38 ( V_18 -> V_19 & V_134 ) ) {
struct V_221 * V_221 ;
V_221 = (struct V_221 * ) V_108 ;
V_221 -> V_18 = V_18 ;
V_221 -> V_214 = V_214 ;
F_178 ( & V_221 -> V_220 , F_160 ) ;
} else {
F_153 ( V_18 , V_214 ) ;
if ( F_30 ( V_18 ) )
F_161 ( V_18 -> V_222 , V_108 ) ;
}
}
static T_2 F_179 ( struct V_17 * V_18 ,
T_2 V_3 , T_2 V_67 , unsigned long V_19 )
{
unsigned long V_239 ;
T_2 V_71 = 0 ;
int V_69 ;
for ( V_69 = 0 ; V_69 <= V_240 ; V_69 ++ ) {
unsigned int V_72 ;
T_2 V_241 ;
F_42 ( V_69 , V_3 , V_67 , V_19 , & V_241 , & V_72 ) ;
if ( ! V_72 )
continue;
if ( V_19 & V_76 ) {
V_239 = V_3 - sizeof( struct V_27 ) ;
V_239 /= sizeof( V_68 ) ;
if ( V_72 > V_239 )
break;
}
V_18 -> V_72 = V_72 ;
V_18 -> V_69 = V_69 ;
V_71 = V_241 ;
if ( V_19 & V_204 )
break;
if ( V_69 >= V_86 )
break;
if ( V_71 * 8 <= ( V_75 << V_69 ) )
break;
}
return V_71 ;
}
static int T_10 F_180 ( struct V_17 * V_18 , T_5 V_102 )
{
if ( V_51 >= V_192 )
return F_133 ( V_18 , V_102 ) ;
if ( V_51 == V_242 ) {
V_18 -> V_58 [ F_35 () ] = & V_189 . V_29 ;
V_51 = V_243 ;
} else if ( V_51 == V_243 ) {
V_18 -> V_58 [ F_35 () ] = & V_189 . V_29 ;
F_123 ( V_18 , V_190 ) ;
if ( V_62 == V_184 )
V_51 = V_244 ;
else
V_51 = V_245 ;
} else {
V_18 -> V_58 [ F_35 () ] =
F_131 ( sizeof( struct V_188 ) , V_102 ) ;
if ( V_51 == V_245 ) {
F_123 ( V_18 , V_191 ) ;
V_51 = V_244 ;
} else {
int V_45 ;
F_28 (node) {
V_18 -> V_42 [ V_45 ] =
F_65 ( sizeof( struct V_6 ) ,
V_102 , V_45 ) ;
F_12 ( ! V_18 -> V_42 [ V_45 ] ) ;
F_7 ( V_18 -> V_42 [ V_45 ] ) ;
}
}
}
V_18 -> V_42 [ F_71 () ] -> V_124 =
V_125 + V_126 +
( ( unsigned long ) V_18 ) % V_126 ;
F_34 ( V_18 ) -> V_105 = 0 ;
F_34 ( V_18 ) -> V_106 = V_246 ;
F_34 ( V_18 ) -> V_101 = 1 ;
F_34 ( V_18 ) -> V_107 = 0 ;
V_18 -> V_101 = 1 ;
V_18 -> V_106 = V_246 ;
return 0 ;
}
int
F_181 ( struct V_17 * V_18 , unsigned long V_19 )
{
T_2 V_71 , V_74 , V_247 ;
T_5 V_102 ;
int V_131 ;
T_2 V_3 = V_18 -> V_3 ;
#if V_61
#if V_248
if ( V_3 < 4096 || F_182 ( V_3 - 1 ) == F_182 ( V_3 - 1 + V_22 +
2 * sizeof( unsigned long long ) ) )
V_19 |= V_20 | V_21 ;
if ( ! ( V_19 & V_134 ) )
V_19 |= V_236 ;
#endif
if ( V_19 & V_134 )
F_12 ( V_19 & V_236 ) ;
#endif
if ( V_3 & ( V_23 - 1 ) ) {
V_3 += ( V_23 - 1 ) ;
V_3 &= ~ ( V_23 - 1 ) ;
}
if ( V_19 & V_21 )
V_247 = V_23 ;
if ( V_19 & V_20 ) {
V_247 = V_22 ;
V_3 += V_22 - 1 ;
V_3 &= ~ ( V_22 - 1 ) ;
}
if ( V_247 < V_18 -> V_67 ) {
V_247 = V_18 -> V_67 ;
}
if ( V_247 > F_183 (unsigned long long) )
V_19 &= ~ ( V_20 | V_21 ) ;
V_18 -> V_67 = V_247 ;
if ( F_184 () )
V_102 = V_122 ;
else
V_102 = V_168 ;
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
#if V_248 && F_185 ( F_174 )
if ( V_3 >= V_50 [ V_184 + 1 ] . V_53
&& V_18 -> V_224 > F_186 ()
&& F_41 ( V_3 , V_18 -> V_67 ) < V_75 ) {
V_18 -> F_10 += V_75 - F_41 ( V_3 , V_18 -> V_67 ) ;
V_3 = V_75 ;
}
#endif
#endif
if ( ( V_3 >= ( V_75 >> 3 ) ) && ! V_185 &&
! ( V_19 & V_249 ) )
V_19 |= V_76 ;
V_3 = F_41 ( V_3 , V_18 -> V_67 ) ;
V_71 = F_179 ( V_18 , V_3 , V_18 -> V_67 , V_19 ) ;
if ( ! V_18 -> V_72 )
return - V_250 ;
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
if ( V_3 % V_75 == 0 && V_19 & V_236 )
V_19 &= ~ ( V_20 | V_21 ) ;
#endif
}
V_18 -> V_251 = F_186 () ;
if ( V_18 -> V_251 < V_18 -> V_67 )
V_18 -> V_251 = V_18 -> V_67 ;
V_18 -> V_252 = V_71 / V_18 -> V_251 ;
V_18 -> V_74 = V_74 ;
V_18 -> V_19 = V_19 ;
V_18 -> V_203 = 0 ;
if ( V_253 && ( V_19 & V_187 ) )
V_18 -> V_203 |= V_64 ;
V_18 -> V_3 = V_3 ;
V_18 -> V_33 = F_188 ( V_3 ) ;
if ( V_19 & V_76 ) {
V_18 -> V_222 = F_39 ( V_74 , 0u ) ;
F_12 ( F_189 ( V_18 -> V_222 ) ) ;
}
V_131 = F_180 ( V_18 , V_102 ) ;
if ( V_131 ) {
F_190 ( V_18 ) ;
return V_131 ;
}
if ( V_19 & V_133 ) {
F_191 ( V_19 & V_134 ) ;
F_27 ( V_18 ) ;
} else if ( ! F_30 ( V_18 ) && ! ( V_19 & V_134 ) )
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
static void F_199 ( void * V_155 )
{
struct V_17 * V_18 = V_155 ;
struct V_38 * V_109 ;
int V_45 = F_71 () ;
F_192 () ;
V_109 = F_34 ( V_18 ) ;
F_94 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
F_95 ( V_18 , V_109 -> V_113 , V_109 -> V_105 , V_45 ) ;
F_96 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
V_109 -> V_105 = 0 ;
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
struct V_6 * V_40 , int V_254 )
{
struct V_255 * V_256 ;
int V_215 ;
struct V_27 * V_108 ;
V_215 = 0 ;
while ( V_215 < V_254 && ! F_77 ( & V_40 -> V_10 ) ) {
F_105 ( & V_40 -> V_14 ) ;
V_256 = V_40 -> V_10 . V_257 ;
if ( V_256 == & V_40 -> V_10 ) {
F_99 ( & V_40 -> V_14 ) ;
goto V_111;
}
V_108 = F_203 ( V_256 , struct V_27 , V_166 ) ;
#if V_61
F_12 ( V_108 -> V_200 ) ;
#endif
F_204 ( & V_108 -> V_166 ) ;
V_40 -> V_15 -= V_29 -> V_72 ;
F_99 ( & V_40 -> V_14 ) ;
F_177 ( V_29 , V_108 ) ;
V_215 ++ ;
}
V_111:
return V_215 ;
}
static int F_205 ( struct V_17 * V_18 )
{
int V_152 = 0 , V_5 = 0 ;
struct V_6 * V_40 ;
F_200 ( V_18 ) ;
F_194 () ;
F_28 (i) {
V_40 = V_18 -> V_42 [ V_5 ] ;
if ( ! V_40 )
continue;
F_110 ( V_18 , V_40 , V_40 -> V_15 ) ;
V_152 += ! F_77 ( & V_40 -> V_8 ) ||
! F_77 ( & V_40 -> V_9 ) ;
}
return ( V_152 ? 1 : 0 ) ;
}
int F_206 ( struct V_17 * V_18 )
{
int V_152 ;
F_12 ( ! V_18 || F_207 () ) ;
F_208 () ;
F_114 ( & V_141 ) ;
V_152 = F_205 ( V_18 ) ;
F_115 ( & V_141 ) ;
F_209 () ;
return V_152 ;
}
int F_190 ( struct V_17 * V_18 )
{
int V_5 ;
struct V_6 * V_40 ;
int V_258 = F_205 ( V_18 ) ;
if ( V_258 )
return V_258 ;
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
int V_251 , T_5 V_259 ,
int V_119 )
{
struct V_27 * V_108 ;
if ( F_30 ( V_18 ) ) {
V_108 = F_211 ( V_18 -> V_222 ,
V_259 , V_119 ) ;
F_212 ( & V_108 -> V_166 , sizeof( struct V_255 ) ,
V_259 ) ;
if ( ! V_108 )
return NULL ;
} else {
V_108 = V_1 + V_251 ;
V_251 += V_18 -> V_74 ;
}
V_108 -> V_200 = 0 ;
V_108 -> V_238 = V_251 ;
V_108 -> V_31 = V_1 + V_251 ;
V_108 -> V_119 = V_119 ;
V_108 -> free = 0 ;
return V_108 ;
}
static inline V_68 * F_213 ( struct V_27 * V_108 )
{
return ( V_68 * ) ( V_108 + 1 ) ;
}
static void F_214 ( struct V_17 * V_18 ,
struct V_27 * V_108 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_72 ; V_5 ++ ) {
void * V_1 = F_20 ( V_18 , V_108 , V_5 ) ;
#if V_61
if ( V_18 -> V_19 & V_236 )
F_165 ( V_18 , V_1 , V_231 ) ;
if ( V_18 -> V_19 & V_21 )
* F_14 ( V_18 , V_1 ) = NULL ;
if ( V_18 -> V_19 & V_20 ) {
* F_11 ( V_18 , V_1 ) = V_237 ;
* F_13 ( V_18 , V_1 ) = V_237 ;
}
if ( V_18 -> V_213 && ! ( V_18 -> V_19 & V_236 ) )
V_18 -> V_213 ( V_1 + F_10 ( V_18 ) ) ;
if ( V_18 -> V_19 & V_20 ) {
if ( * F_13 ( V_18 , V_1 ) != V_237 )
F_176 ( V_18 , L_23
L_24 ) ;
if ( * F_11 ( V_18 , V_1 ) != V_237 )
F_176 ( V_18 , L_23
L_25 ) ;
}
if ( ( V_18 -> V_3 % V_75 ) == 0 &&
F_30 ( V_18 ) && V_18 -> V_19 & V_236 )
F_175 ( F_68 ( V_1 ) ,
V_18 -> V_3 / V_75 , 0 ) ;
#else
if ( V_18 -> V_213 )
V_18 -> V_213 ( V_1 ) ;
#endif
F_213 ( V_108 ) [ V_5 ] = V_5 + 1 ;
}
F_213 ( V_108 ) [ V_5 - 1 ] = V_260 ;
}
static void F_215 ( struct V_17 * V_18 , T_5 V_19 )
{
if ( V_253 ) {
if ( V_19 & V_64 )
F_12 ( ! ( V_18 -> V_203 & V_64 ) ) ;
else
F_12 ( V_18 -> V_203 & V_64 ) ;
}
}
static void * F_216 ( struct V_17 * V_18 , struct V_27 * V_108 ,
int V_119 )
{
void * V_1 = F_20 ( V_18 , V_108 , V_108 -> free ) ;
V_68 V_261 ;
V_108 -> V_200 ++ ;
V_261 = F_213 ( V_108 ) [ V_108 -> free ] ;
#if V_61
F_213 ( V_108 ) [ V_108 -> free ] = V_262 ;
F_217 ( V_108 -> V_119 != V_119 ) ;
#endif
V_108 -> free = V_261 ;
return V_1 ;
}
static void F_218 ( struct V_17 * V_18 , struct V_27 * V_108 ,
void * V_1 , int V_119 )
{
unsigned int V_235 = F_21 ( V_18 , V_108 , V_1 ) ;
#if V_61
F_217 ( V_108 -> V_119 != V_119 ) ;
if ( F_213 ( V_108 ) [ V_235 ] + 1 <= V_77 + 1 ) {
F_44 ( V_80 L_26
L_27 , V_18 -> V_81 , V_1 ) ;
F_134 () ;
}
#endif
F_213 ( V_108 ) [ V_235 ] = V_108 -> free ;
V_108 -> free = V_235 ;
V_108 -> V_200 -- ;
}
static void F_219 ( struct V_17 * V_29 , struct V_27 * V_27 ,
void * V_214 )
{
int V_201 ;
struct V_25 * V_25 ;
V_25 = F_68 ( V_214 ) ;
V_201 = 1 ;
if ( F_101 ( ! F_220 ( V_25 ) ) )
V_201 <<= V_29 -> V_69 ;
do {
V_25 -> V_26 = V_29 ;
V_25 -> V_28 = V_27 ;
V_25 ++ ;
} while ( -- V_201 );
}
static int F_221 ( struct V_17 * V_18 ,
T_5 V_19 , int V_119 , void * V_1 )
{
struct V_27 * V_108 ;
T_2 V_32 ;
T_5 V_259 ;
struct V_6 * V_40 ;
F_12 ( V_19 & V_263 ) ;
V_259 = V_19 & ( V_264 | V_265 ) ;
F_192 () ;
V_40 = V_18 -> V_42 [ V_119 ] ;
F_94 ( & V_40 -> V_14 ) ;
V_32 = V_40 -> V_13 ;
V_40 -> V_13 ++ ;
if ( V_40 -> V_13 >= V_18 -> V_252 )
V_40 -> V_13 = 0 ;
F_96 ( & V_40 -> V_14 ) ;
V_32 *= V_18 -> V_251 ;
if ( V_259 & V_266 )
F_222 () ;
F_215 ( V_18 , V_19 ) ;
if ( ! V_1 )
V_1 = F_140 ( V_18 , V_259 , V_119 ) ;
if ( ! V_1 )
goto V_267;
V_108 = F_210 ( V_18 , V_1 , V_32 ,
V_259 & ~ V_264 , V_119 ) ;
if ( ! V_108 )
goto V_268;
F_219 ( V_18 , V_108 , V_1 ) ;
F_214 ( V_18 , V_108 ) ;
if ( V_259 & V_266 )
F_223 () ;
F_192 () ;
F_94 ( & V_40 -> V_14 ) ;
F_224 ( & V_108 -> V_166 , & ( V_40 -> V_10 ) ) ;
F_225 ( V_18 ) ;
V_40 -> V_15 += V_18 -> V_72 ;
F_96 ( & V_40 -> V_14 ) ;
return 1 ;
V_268:
F_153 ( V_18 , V_1 ) ;
V_267:
if ( V_259 & V_266 )
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
unsigned long long V_269 , V_270 ;
V_269 = * F_11 ( V_29 , V_24 ) ;
V_270 = * F_13 ( V_29 , V_24 ) ;
if ( V_269 == V_271 && V_270 == V_271 )
return;
if ( V_269 == V_237 && V_270 == V_237 )
F_176 ( V_29 , L_29 ) ;
else
F_176 ( V_29 , L_30 ) ;
F_44 ( V_80 L_31 ,
V_24 , V_269 , V_270 ) ;
}
static void * F_229 ( struct V_17 * V_18 , void * V_1 ,
unsigned long V_223 )
{
struct V_25 * V_25 ;
unsigned int V_235 ;
struct V_27 * V_108 ;
F_12 ( F_15 ( V_1 ) != V_18 ) ;
V_1 -= F_10 ( V_18 ) ;
F_226 ( V_1 ) ;
V_25 = F_16 ( V_1 ) ;
V_108 = V_25 -> V_28 ;
if ( V_18 -> V_19 & V_20 ) {
F_228 ( V_18 , V_1 ) ;
* F_11 ( V_18 , V_1 ) = V_237 ;
* F_13 ( V_18 , V_1 ) = V_237 ;
}
if ( V_18 -> V_19 & V_21 )
* F_14 ( V_18 , V_1 ) = ( void * ) V_223 ;
V_235 = F_21 ( V_18 , V_108 , V_1 ) ;
F_12 ( V_235 >= V_18 -> V_72 ) ;
F_12 ( V_1 != F_20 ( V_18 , V_108 , V_235 ) ) ;
#ifdef F_230
F_213 ( V_108 ) [ V_235 ] = V_262 ;
#endif
if ( V_18 -> V_19 & V_236 ) {
#ifdef F_174
if ( ( V_18 -> V_3 % V_75 ) == 0 && F_30 ( V_18 ) ) {
F_162 ( V_18 , V_1 , V_223 ) ;
F_175 ( F_68 ( V_1 ) ,
V_18 -> V_3 / V_75 , 0 ) ;
} else {
F_165 ( V_18 , V_1 , V_231 ) ;
}
#else
F_165 ( V_18 , V_1 , V_231 ) ;
#endif
}
return V_1 ;
}
static void F_231 ( struct V_17 * V_18 , struct V_27 * V_108 )
{
V_68 V_5 ;
int V_100 = 0 ;
for ( V_5 = V_108 -> free ; V_5 != V_260 ; V_5 = F_213 ( V_108 ) [ V_5 ] ) {
V_100 ++ ;
if ( V_100 > V_18 -> V_72 || V_5 >= V_18 -> V_72 )
goto V_132;
}
if ( V_100 != V_18 -> V_72 - V_108 -> V_200 ) {
V_132:
F_44 ( V_80 L_32
L_33 ,
V_18 -> V_81 , V_18 -> V_72 , V_108 , V_108 -> V_200 ,
F_172 () ) ;
F_167 ( V_80 , L_7 , V_272 , 16 , 1 , V_108 ,
sizeof( * V_108 ) + V_18 -> V_72 * sizeof( V_68 ) ,
1 ) ;
F_134 () ;
}
}
static void * F_232 ( struct V_17 * V_18 , T_5 V_19 ,
bool V_112 )
{
int V_101 ;
struct V_6 * V_40 ;
struct V_38 * V_109 ;
int V_45 ;
F_192 () ;
V_45 = F_71 () ;
if ( F_38 ( V_112 ) )
goto V_273;
V_274:
V_109 = F_34 ( V_18 ) ;
V_101 = V_109 -> V_101 ;
if ( ! V_109 -> V_107 && V_101 > V_275 ) {
V_101 = V_275 ;
}
V_40 = V_18 -> V_42 [ V_45 ] ;
F_12 ( V_109 -> V_105 > 0 || ! V_40 ) ;
F_94 ( & V_40 -> V_14 ) ;
if ( V_40 -> V_11 && F_83 ( V_109 , V_40 -> V_11 , V_101 ) ) {
V_40 -> V_11 -> V_107 = 1 ;
goto V_276;
}
while ( V_101 > 0 ) {
struct V_255 * V_113 ;
struct V_27 * V_108 ;
V_113 = V_40 -> V_9 . V_261 ;
if ( V_113 == & V_40 -> V_9 ) {
V_40 -> V_16 = 1 ;
V_113 = V_40 -> V_10 . V_261 ;
if ( V_113 == & V_40 -> V_10 )
goto V_277;
}
V_108 = F_203 ( V_113 , struct V_27 , V_166 ) ;
F_231 ( V_18 , V_108 ) ;
F_195 ( V_18 ) ;
F_12 ( V_108 -> V_200 >= V_18 -> V_72 ) ;
while ( V_108 -> V_200 < V_18 -> V_72 && V_101 -- ) {
F_233 ( V_18 ) ;
F_234 ( V_18 ) ;
F_235 ( V_18 ) ;
F_82 ( V_18 , V_109 , F_216 ( V_18 , V_108 ,
V_45 ) ) ;
}
F_231 ( V_18 , V_108 ) ;
F_204 ( & V_108 -> V_166 ) ;
if ( V_108 -> free == V_260 )
F_129 ( & V_108 -> V_166 , & V_40 -> V_8 ) ;
else
F_129 ( & V_108 -> V_166 , & V_40 -> V_9 ) ;
}
V_277:
V_40 -> V_15 -= V_109 -> V_105 ;
V_276:
F_96 ( & V_40 -> V_14 ) ;
if ( F_38 ( ! V_109 -> V_105 ) ) {
int T_3 ;
V_273:
T_3 = F_221 ( V_18 , V_19 | V_278 , V_45 , NULL ) ;
V_109 = F_34 ( V_18 ) ;
V_45 = F_71 () ;
if ( ! T_3 && ( V_109 -> V_105 == 0 || V_112 ) )
return NULL ;
if ( ! V_109 -> V_105 )
goto V_274;
}
V_109 -> V_107 = 1 ;
return F_79 ( V_18 , V_109 , V_19 , V_112 ) ;
}
static inline void F_236 ( struct V_17 * V_18 ,
T_5 V_19 )
{
F_237 ( V_19 & V_266 ) ;
#if V_61
F_215 ( V_18 , V_19 ) ;
#endif
}
static void * F_238 ( struct V_17 * V_18 ,
T_5 V_19 , void * V_1 , unsigned long V_223 )
{
if ( ! V_1 )
return V_1 ;
if ( V_18 -> V_19 & V_236 ) {
#ifdef F_174
if ( ( V_18 -> V_3 % V_75 ) == 0 && F_30 ( V_18 ) )
F_175 ( F_68 ( V_1 ) ,
V_18 -> V_3 / V_75 , 1 ) ;
else
F_171 ( V_18 , V_1 ) ;
#else
F_171 ( V_18 , V_1 ) ;
#endif
F_165 ( V_18 , V_1 , V_279 ) ;
}
if ( V_18 -> V_19 & V_21 )
* F_14 ( V_18 , V_1 ) = ( void * ) V_223 ;
if ( V_18 -> V_19 & V_20 ) {
if ( * F_11 ( V_18 , V_1 ) != V_237 ||
* F_13 ( V_18 , V_1 ) != V_237 ) {
F_176 ( V_18 , L_34
L_35 ) ;
F_44 ( V_80
L_36 ,
V_1 , * F_11 ( V_18 , V_1 ) ,
* F_13 ( V_18 , V_1 ) ) ;
}
* F_11 ( V_18 , V_1 ) = V_271 ;
* F_13 ( V_18 , V_1 ) = V_271 ;
}
#ifdef F_230
{
struct V_27 * V_108 ;
unsigned V_235 ;
V_108 = F_16 ( V_1 ) -> V_28 ;
V_235 = ( unsigned ) ( V_1 - V_108 -> V_31 ) / V_18 -> V_3 ;
F_213 ( V_108 ) [ V_235 ] = V_280 ;
}
#endif
V_1 += F_10 ( V_18 ) ;
if ( V_18 -> V_213 && V_18 -> V_19 & V_236 )
V_18 -> V_213 ( V_1 ) ;
if ( V_281 &&
( ( unsigned long ) V_1 & ( V_281 - 1 ) ) ) {
F_44 ( V_80 L_37 ,
V_1 , ( int ) V_281 ) ;
}
return V_1 ;
}
static bool F_239 ( struct V_17 * V_18 , T_5 V_19 )
{
if ( V_18 == V_17 )
return false ;
return F_240 ( V_18 -> V_224 , V_19 , V_18 -> V_19 ) ;
}
static inline void * F_241 ( struct V_17 * V_18 , T_5 V_19 )
{
void * V_1 ;
struct V_38 * V_109 ;
bool V_112 = false ;
F_192 () ;
V_109 = F_34 ( V_18 ) ;
if ( F_101 ( V_109 -> V_105 ) ) {
V_109 -> V_107 = 1 ;
V_1 = F_79 ( V_18 , V_109 , V_19 , false ) ;
if ( V_1 ) {
F_242 ( V_18 ) ;
goto V_111;
}
V_112 = true ;
}
F_243 ( V_18 ) ;
V_1 = F_232 ( V_18 , V_19 , V_112 ) ;
V_109 = F_34 ( V_18 ) ;
V_111:
if ( V_1 )
F_244 ( & V_109 -> V_113 [ V_109 -> V_105 ] ) ;
return V_1 ;
}
static void * F_88 ( struct V_17 * V_18 , T_5 V_19 )
{
int V_282 , V_283 ;
if ( F_207 () || ( V_19 & V_284 ) )
return NULL ;
V_282 = V_283 = F_71 () ;
if ( F_245 () && ( V_18 -> V_19 & V_285 ) )
V_282 = F_246 () ;
else if ( V_216 -> V_286 )
V_282 = F_247 () ;
if ( V_282 != V_283 )
return F_89 ( V_18 , V_19 , V_282 ) ;
return NULL ;
}
static void * F_248 ( struct V_17 * V_29 , T_5 V_19 )
{
struct V_287 * V_287 ;
T_5 V_259 ;
struct V_288 * V_289 ;
struct V_290 * V_290 ;
enum V_291 V_292 = F_249 ( V_19 ) ;
void * V_24 = NULL ;
int V_158 ;
unsigned int V_293 ;
if ( V_19 & V_284 )
return NULL ;
V_259 = V_19 & ( V_264 | V_265 ) ;
V_294:
V_293 = F_250 () ;
V_287 = F_251 ( F_247 () , V_19 ) ;
V_274:
F_252 (zone, z, zonelist, high_zoneidx) {
V_158 = F_253 ( V_290 ) ;
if ( F_254 ( V_290 , V_19 ) &&
V_29 -> V_42 [ V_158 ] &&
V_29 -> V_42 [ V_158 ] -> V_15 ) {
V_24 = F_89 ( V_29 ,
V_19 | V_278 , V_158 ) ;
if ( V_24 )
break;
}
}
if ( ! V_24 ) {
if ( V_259 & V_266 )
F_222 () ;
F_215 ( V_29 , V_19 ) ;
V_24 = F_140 ( V_29 , V_259 , F_71 () ) ;
if ( V_259 & V_266 )
F_223 () ;
if ( V_24 ) {
V_158 = F_255 ( F_68 ( V_24 ) ) ;
if ( F_221 ( V_29 , V_19 , V_158 , V_24 ) ) {
V_24 = F_89 ( V_29 ,
V_19 | V_278 , V_158 ) ;
if ( ! V_24 )
goto V_274;
} else {
V_24 = NULL ;
}
}
}
if ( F_38 ( ! F_256 ( V_293 ) && ! V_24 ) )
goto V_294;
return V_24 ;
}
static void * F_89 ( struct V_17 * V_18 , T_5 V_19 ,
int V_119 )
{
struct V_255 * V_113 ;
struct V_27 * V_108 ;
struct V_6 * V_40 ;
void * V_24 ;
int T_3 ;
V_40 = V_18 -> V_42 [ V_119 ] ;
F_12 ( ! V_40 ) ;
V_274:
F_192 () ;
F_94 ( & V_40 -> V_14 ) ;
V_113 = V_40 -> V_9 . V_261 ;
if ( V_113 == & V_40 -> V_9 ) {
V_40 -> V_16 = 1 ;
V_113 = V_40 -> V_10 . V_261 ;
if ( V_113 == & V_40 -> V_10 )
goto V_277;
}
V_108 = F_203 ( V_113 , struct V_27 , V_166 ) ;
F_198 ( V_18 , V_119 ) ;
F_231 ( V_18 , V_108 ) ;
F_257 ( V_18 ) ;
F_234 ( V_18 ) ;
F_235 ( V_18 ) ;
F_12 ( V_108 -> V_200 == V_18 -> V_72 ) ;
V_24 = F_216 ( V_18 , V_108 , V_119 ) ;
F_231 ( V_18 , V_108 ) ;
V_40 -> V_15 -- ;
F_204 ( & V_108 -> V_166 ) ;
if ( V_108 -> free == V_260 )
F_129 ( & V_108 -> V_166 , & V_40 -> V_8 ) ;
else
F_129 ( & V_108 -> V_166 , & V_40 -> V_9 ) ;
F_96 ( & V_40 -> V_14 ) ;
goto V_295;
V_277:
F_96 ( & V_40 -> V_14 ) ;
T_3 = F_221 ( V_18 , V_19 | V_278 , V_119 , NULL ) ;
if ( T_3 )
goto V_274;
return F_248 ( V_18 , V_19 ) ;
V_295:
return V_24 ;
}
static T_1 void *
F_258 ( struct V_17 * V_18 , T_5 V_19 , int V_119 ,
unsigned long V_223 )
{
unsigned long V_296 ;
void * V_167 ;
int F_247 = F_71 () ;
V_19 &= V_297 ;
F_259 ( V_19 ) ;
if ( F_239 ( V_18 , V_19 ) )
return NULL ;
V_18 = F_260 ( V_18 , V_19 ) ;
F_236 ( V_18 , V_19 ) ;
F_261 ( V_296 ) ;
if ( V_119 == V_298 )
V_119 = F_247 ;
if ( F_38 ( ! V_18 -> V_42 [ V_119 ] ) ) {
V_167 = F_248 ( V_18 , V_19 ) ;
goto V_111;
}
if ( V_119 == F_247 ) {
V_167 = F_241 ( V_18 , V_19 ) ;
if ( V_167 )
goto V_111;
}
V_167 = F_89 ( V_18 , V_19 , V_119 ) ;
V_111:
F_262 ( V_296 ) ;
V_167 = F_238 ( V_18 , V_19 , V_167 , V_223 ) ;
F_263 ( V_167 , V_18 -> V_224 , 1 , V_18 -> V_19 ,
V_19 ) ;
if ( F_101 ( V_167 ) )
F_264 ( V_18 , V_19 , V_167 , V_18 -> V_224 ) ;
if ( F_38 ( ( V_19 & V_299 ) && V_167 ) )
memset ( V_167 , 0 , V_18 -> V_224 ) ;
return V_167 ;
}
static T_1 void *
F_265 ( struct V_17 * V_29 , T_5 V_19 )
{
void * V_1 ;
if ( F_38 ( V_216 -> V_19 & ( V_300 | V_301 ) ) ) {
V_1 = F_88 ( V_29 , V_19 ) ;
if ( V_1 )
goto V_111;
}
V_1 = F_241 ( V_29 , V_19 ) ;
if ( ! V_1 )
V_1 = F_89 ( V_29 , V_19 , F_71 () ) ;
V_111:
return V_1 ;
}
static T_1 void *
F_265 ( struct V_17 * V_18 , T_5 V_19 )
{
return F_241 ( V_18 , V_19 ) ;
}
static T_1 void *
F_266 ( struct V_17 * V_18 , T_5 V_19 , unsigned long V_223 )
{
unsigned long V_296 ;
void * V_1 ;
V_19 &= V_297 ;
F_259 ( V_19 ) ;
if ( F_239 ( V_18 , V_19 ) )
return NULL ;
V_18 = F_260 ( V_18 , V_19 ) ;
F_236 ( V_18 , V_19 ) ;
F_261 ( V_296 ) ;
V_1 = F_265 ( V_18 , V_19 ) ;
F_262 ( V_296 ) ;
V_1 = F_238 ( V_18 , V_19 , V_1 , V_223 ) ;
F_263 ( V_1 , V_18 -> V_224 , 1 , V_18 -> V_19 ,
V_19 ) ;
F_267 ( V_1 ) ;
if ( F_101 ( V_1 ) )
F_264 ( V_18 , V_19 , V_1 , V_18 -> V_224 ) ;
if ( F_38 ( ( V_19 & V_299 ) && V_1 ) )
memset ( V_1 , 0 , V_18 -> V_224 ) ;
return V_1 ;
}
static void F_95 ( struct V_17 * V_18 , void * * V_302 , int V_303 ,
int V_45 )
{
int V_5 ;
struct V_6 * V_40 ;
for ( V_5 = 0 ; V_5 < V_303 ; V_5 ++ ) {
void * V_1 ;
struct V_27 * V_108 ;
F_3 ( & V_302 [ V_5 ] ) ;
V_1 = V_302 [ V_5 ] ;
V_108 = F_17 ( V_1 ) ;
V_40 = V_18 -> V_42 [ V_45 ] ;
F_204 ( & V_108 -> V_166 ) ;
F_198 ( V_18 , V_45 ) ;
F_231 ( V_18 , V_108 ) ;
F_218 ( V_18 , V_108 , V_1 , V_45 ) ;
F_268 ( V_18 ) ;
V_40 -> V_15 ++ ;
F_231 ( V_18 , V_108 ) ;
if ( V_108 -> V_200 == 0 ) {
if ( V_40 -> V_15 > V_40 -> V_127 ) {
V_40 -> V_15 -= V_18 -> V_72 ;
F_177 ( V_18 , V_108 ) ;
} else {
F_129 ( & V_108 -> V_166 , & V_40 -> V_10 ) ;
}
} else {
F_224 ( & V_108 -> V_166 , & V_40 -> V_9 ) ;
}
}
}
static void F_269 ( struct V_17 * V_18 , struct V_38 * V_109 )
{
int V_101 ;
struct V_6 * V_40 ;
int V_45 = F_71 () ;
V_101 = V_109 -> V_101 ;
#if V_61
F_12 ( ! V_101 || V_101 > V_109 -> V_105 ) ;
#endif
F_192 () ;
V_40 = V_18 -> V_42 [ V_45 ] ;
F_94 ( & V_40 -> V_14 ) ;
if ( V_40 -> V_11 ) {
struct V_38 * V_304 = V_40 -> V_11 ;
int V_116 = V_304 -> V_106 - V_304 -> V_105 ;
if ( V_116 ) {
if ( V_101 > V_116 )
V_101 = V_116 ;
memcpy ( & ( V_304 -> V_113 [ V_304 -> V_105 ] ) ,
V_109 -> V_113 , sizeof( void * ) * V_101 ) ;
V_304 -> V_105 += V_101 ;
goto V_305;
}
}
F_95 ( V_18 , V_109 -> V_113 , V_101 , V_45 ) ;
V_305:
#if V_306
{
int V_5 = 0 ;
struct V_255 * V_256 ;
V_256 = V_40 -> V_10 . V_261 ;
while ( V_256 != & ( V_40 -> V_10 ) ) {
struct V_27 * V_108 ;
V_108 = F_203 ( V_256 , struct V_27 , V_166 ) ;
F_12 ( V_108 -> V_200 ) ;
V_5 ++ ;
V_256 = V_256 -> V_261 ;
}
F_270 ( V_18 , V_5 ) ;
}
#endif
F_96 ( & V_40 -> V_14 ) ;
V_109 -> V_105 -= V_101 ;
memmove ( V_109 -> V_113 , & ( V_109 -> V_113 [ V_101 ] ) , sizeof( void * ) * V_109 -> V_105 ) ;
}
static inline void F_271 ( struct V_17 * V_18 , void * V_1 ,
unsigned long V_223 )
{
struct V_38 * V_109 = F_34 ( V_18 ) ;
F_192 () ;
F_272 ( V_1 , V_18 -> V_19 ) ;
V_1 = F_229 ( V_18 , V_1 , V_223 ) ;
F_273 ( V_18 , V_1 , V_18 -> V_224 ) ;
if ( V_307 > 1 && F_87 ( V_18 , V_1 ) )
return;
if ( F_101 ( V_109 -> V_105 < V_109 -> V_106 ) ) {
F_274 ( V_18 ) ;
} else {
F_275 ( V_18 ) ;
F_269 ( V_18 , V_109 ) ;
}
F_82 ( V_18 , V_109 , V_1 ) ;
}
void * F_276 ( struct V_17 * V_18 , T_5 V_19 )
{
void * V_152 = F_266 ( V_18 , V_19 , V_308 ) ;
F_277 ( V_308 , V_152 ,
V_18 -> V_224 , V_18 -> V_3 , V_19 ) ;
return V_152 ;
}
void *
F_278 ( struct V_17 * V_18 , T_5 V_19 , T_2 V_3 )
{
void * V_152 ;
V_152 = F_266 ( V_18 , V_19 , V_308 ) ;
F_279 ( V_308 , V_152 ,
V_3 , V_18 -> V_3 , V_19 ) ;
return V_152 ;
}
void * F_211 ( struct V_17 * V_18 , T_5 V_19 , int V_119 )
{
void * V_152 = F_258 ( V_18 , V_19 , V_119 , V_308 ) ;
F_280 ( V_308 , V_152 ,
V_18 -> V_224 , V_18 -> V_3 ,
V_19 , V_119 ) ;
return V_152 ;
}
void * F_281 ( struct V_17 * V_18 ,
T_5 V_19 ,
int V_119 ,
T_2 V_3 )
{
void * V_152 ;
V_152 = F_258 ( V_18 , V_19 , V_119 , V_308 ) ;
F_282 ( V_308 , V_152 ,
V_3 , V_18 -> V_3 ,
V_19 , V_119 ) ;
return V_152 ;
}
static T_1 void *
F_283 ( T_2 V_3 , T_5 V_19 , int V_45 , unsigned long V_223 )
{
struct V_17 * V_18 ;
V_18 = F_39 ( V_3 , V_19 ) ;
if ( F_38 ( F_189 ( V_18 ) ) )
return V_18 ;
return F_281 ( V_18 , V_19 , V_45 , V_3 ) ;
}
void * F_284 ( T_2 V_3 , T_5 V_19 , int V_45 )
{
return F_283 ( V_3 , V_19 , V_45 , V_308 ) ;
}
void * F_285 ( T_2 V_3 , T_5 V_19 ,
int V_45 , unsigned long V_223 )
{
return F_283 ( V_3 , V_19 , V_45 , V_223 ) ;
}
void * F_284 ( T_2 V_3 , T_5 V_19 , int V_45 )
{
return F_283 ( V_3 , V_19 , V_45 , 0 ) ;
}
static T_1 void * F_286 ( T_2 V_3 , T_5 V_19 ,
unsigned long V_223 )
{
struct V_17 * V_18 ;
void * V_152 ;
V_18 = F_36 ( V_3 , V_19 ) ;
if ( F_38 ( F_189 ( V_18 ) ) )
return V_18 ;
V_152 = F_266 ( V_18 , V_19 , V_223 ) ;
F_279 ( V_223 , V_152 ,
V_3 , V_18 -> V_3 , V_19 ) ;
return V_152 ;
}
void * F_287 ( T_2 V_3 , T_5 V_19 )
{
return F_286 ( V_3 , V_19 , V_308 ) ;
}
void * F_288 ( T_2 V_3 , T_5 V_19 , unsigned long V_223 )
{
return F_286 ( V_3 , V_19 , V_223 ) ;
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
F_290 ( V_1 , V_18 -> V_224 ) ;
if ( ! ( V_18 -> V_19 & V_133 ) )
F_291 ( V_1 , V_18 -> V_224 ) ;
F_271 ( V_18 , V_1 , V_308 ) ;
F_262 ( V_19 ) ;
F_292 ( V_308 , V_1 ) ;
}
void F_92 ( const void * V_1 )
{
struct V_17 * V_309 ;
unsigned long V_19 ;
F_293 ( V_308 , V_1 ) ;
if ( F_38 ( F_189 ( V_1 ) ) )
return;
F_261 ( V_19 ) ;
F_226 ( V_1 ) ;
V_309 = F_15 ( V_1 ) ;
F_290 ( V_1 , V_309 -> V_224 ) ;
F_291 ( V_1 , V_309 -> V_224 ) ;
F_271 ( V_309 , ( void * ) V_1 , V_308 ) ;
F_262 ( V_19 ) ;
}
static int F_294 ( struct V_17 * V_18 , T_5 V_102 )
{
int V_45 ;
struct V_6 * V_40 ;
struct V_38 * V_310 ;
struct V_38 * * V_311 = NULL ;
F_28 (node) {
if ( V_84 ) {
V_311 = F_85 ( V_45 , V_18 -> V_106 , V_102 ) ;
if ( ! V_311 )
goto V_312;
}
V_310 = NULL ;
if ( V_18 -> V_11 ) {
V_310 = F_64 ( V_45 ,
V_18 -> V_11 * V_18 -> V_101 ,
0xbaadf00d , V_102 ) ;
if ( ! V_310 ) {
F_86 ( V_311 ) ;
goto V_312;
}
}
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( V_40 ) {
struct V_38 * V_11 = V_40 -> V_11 ;
F_105 ( & V_40 -> V_14 ) ;
if ( V_11 )
F_95 ( V_18 , V_11 -> V_113 ,
V_11 -> V_105 , V_45 ) ;
V_40 -> V_11 = V_310 ;
if ( ! V_40 -> V_12 ) {
V_40 -> V_12 = V_311 ;
V_311 = NULL ;
}
V_40 -> V_127 = ( 1 + F_106 ( V_45 ) ) *
V_18 -> V_101 + V_18 -> V_72 ;
F_99 ( & V_40 -> V_14 ) ;
F_92 ( V_11 ) ;
F_86 ( V_311 ) ;
continue;
}
V_40 = F_65 ( sizeof( struct V_6 ) , V_102 , V_45 ) ;
if ( ! V_40 ) {
F_86 ( V_311 ) ;
F_92 ( V_310 ) ;
goto V_312;
}
F_7 ( V_40 ) ;
V_40 -> V_124 = V_125 + V_126 +
( ( unsigned long ) V_18 ) % V_126 ;
V_40 -> V_11 = V_310 ;
V_40 -> V_12 = V_311 ;
V_40 -> V_127 = ( 1 + F_106 ( V_45 ) ) *
V_18 -> V_101 + V_18 -> V_72 ;
V_18 -> V_42 [ V_45 ] = V_40 ;
}
return 0 ;
V_312:
if ( ! V_18 -> V_166 . V_261 ) {
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
return - V_123 ;
}
static void F_295 ( void * V_313 )
{
struct V_314 * V_315 = V_313 ;
struct V_38 * V_316 ;
F_192 () ;
V_316 = F_34 ( V_315 -> V_18 ) ;
V_315 -> V_18 -> V_58 [ F_35 () ] = V_315 -> V_315 [ F_35 () ] ;
V_315 -> V_315 [ F_35 () ] = V_316 ;
}
static int F_296 ( struct V_17 * V_18 , int V_106 ,
int V_101 , int V_11 , T_5 V_102 )
{
struct V_314 * V_315 ;
int V_5 ;
V_315 = F_297 ( sizeof( * V_315 ) + V_171 * sizeof( struct V_38 * ) ,
V_102 ) ;
if ( ! V_315 )
return - V_123 ;
F_138 (i) {
V_315 -> V_315 [ V_5 ] = F_64 ( F_53 ( V_5 ) , V_106 ,
V_101 , V_102 ) ;
if ( ! V_315 -> V_315 [ V_5 ] ) {
for ( V_5 -- ; V_5 >= 0 ; V_5 -- )
F_92 ( V_315 -> V_315 [ V_5 ] ) ;
F_92 ( V_315 ) ;
return - V_123 ;
}
}
V_315 -> V_18 = V_18 ;
F_201 ( F_295 , ( void * ) V_315 , 1 ) ;
F_194 () ;
V_18 -> V_101 = V_101 ;
V_18 -> V_106 = V_106 ;
V_18 -> V_11 = V_11 ;
F_138 (i) {
struct V_38 * V_317 = V_315 -> V_315 [ V_5 ] ;
if ( ! V_317 )
continue;
F_105 ( & V_18 -> V_42 [ F_53 ( V_5 ) ] -> V_14 ) ;
F_95 ( V_18 , V_317 -> V_113 , V_317 -> V_105 , F_53 ( V_5 ) ) ;
F_99 ( & V_18 -> V_42 [ F_53 ( V_5 ) ] -> V_14 ) ;
F_92 ( V_317 ) ;
}
F_92 ( V_315 ) ;
return F_294 ( V_18 , V_102 ) ;
}
static int F_298 ( struct V_17 * V_18 , int V_106 ,
int V_101 , int V_11 , T_5 V_102 )
{
int V_152 ;
struct V_17 * V_309 = NULL ;
int V_5 = 0 ;
V_152 = F_296 ( V_18 , V_106 , V_101 , V_11 , V_102 ) ;
if ( V_51 < V_192 )
return V_152 ;
if ( ( V_152 < 0 ) || ! F_299 ( V_18 ) )
return V_152 ;
F_18 ( ! F_300 ( & V_141 ) ) ;
F_301 (i) {
V_309 = F_302 ( V_18 , V_5 ) ;
if ( V_309 )
F_296 ( V_309 , V_106 , V_101 , V_11 , V_102 ) ;
}
return V_152 ;
}
static int F_133 ( struct V_17 * V_18 , T_5 V_102 )
{
int V_131 ;
int V_106 = 0 ;
int V_11 = 0 ;
int V_101 = 0 ;
if ( ! F_299 ( V_18 ) ) {
struct V_17 * V_318 = F_303 ( V_18 ) ;
V_106 = V_318 -> V_106 ;
V_11 = V_318 -> V_11 ;
V_101 = V_318 -> V_101 ;
}
if ( V_106 && V_11 && V_101 )
goto V_319;
if ( V_18 -> V_3 > 131072 )
V_106 = 1 ;
else if ( V_18 -> V_3 > V_75 )
V_106 = 8 ;
else if ( V_18 -> V_3 > 1024 )
V_106 = 24 ;
else if ( V_18 -> V_3 > 256 )
V_106 = 54 ;
else
V_106 = 120 ;
V_11 = 0 ;
if ( V_18 -> V_3 <= V_75 && F_304 () > 1 )
V_11 = 8 ;
#if V_61
if ( V_106 > 32 )
V_106 = 32 ;
#endif
V_101 = ( V_106 + 1 ) / 2 ;
V_319:
V_131 = F_298 ( V_18 , V_106 , V_101 , V_11 , V_102 ) ;
if ( V_131 )
F_44 ( V_80 L_38 ,
V_18 -> V_81 , - V_131 ) ;
return V_131 ;
}
static void F_202 ( struct V_17 * V_18 , struct V_6 * V_40 ,
struct V_38 * V_109 , int V_320 , int V_45 )
{
int V_254 ;
if ( ! V_109 || ! V_109 -> V_105 )
return;
if ( V_109 -> V_107 && ! V_320 ) {
V_109 -> V_107 = 0 ;
} else {
F_105 ( & V_40 -> V_14 ) ;
if ( V_109 -> V_105 ) {
V_254 = V_320 ? V_109 -> V_105 : ( V_109 -> V_106 + 4 ) / 5 ;
if ( V_254 > V_109 -> V_105 )
V_254 = ( V_109 -> V_105 + 1 ) / 2 ;
F_95 ( V_18 , V_109 -> V_113 , V_254 , V_45 ) ;
V_109 -> V_105 -= V_254 ;
memmove ( V_109 -> V_113 , & ( V_109 -> V_113 [ V_254 ] ) ,
sizeof( void * ) * V_109 -> V_105 ) ;
}
F_99 ( & V_40 -> V_14 ) ;
}
}
static void V_98 ( struct V_321 * V_322 )
{
struct V_17 * V_323 ;
struct V_6 * V_40 ;
int V_45 = F_71 () ;
struct V_93 * V_96 = F_305 ( V_322 ) ;
if ( ! F_306 ( & V_141 ) )
goto V_111;
F_73 (searchp, &slab_caches, list) {
F_194 () ;
V_40 = V_323 -> V_42 [ V_45 ] ;
F_97 ( V_323 , V_40 ) ;
F_202 ( V_323 , V_40 , F_34 ( V_323 ) , 0 , V_45 ) ;
if ( F_307 ( V_40 -> V_124 , V_125 ) )
goto V_261;
V_40 -> V_124 = V_125 + V_126 ;
F_202 ( V_323 , V_40 , V_40 -> V_11 , 0 , V_45 ) ;
if ( V_40 -> V_16 )
V_40 -> V_16 = 0 ;
else {
int V_324 ;
V_324 = F_110 ( V_323 , V_40 , ( V_40 -> V_127 +
5 * V_323 -> V_72 - 1 ) / ( 5 * V_323 -> V_72 ) ) ;
F_308 ( V_323 , V_324 ) ;
}
V_261:
F_309 () ;
}
F_194 () ;
F_115 ( & V_141 ) ;
F_56 () ;
V_111:
F_310 ( V_96 , F_311 ( V_325 ) ) ;
}
void F_312 ( struct V_17 * V_18 , struct V_326 * V_327 )
{
struct V_27 * V_108 ;
unsigned long V_196 ;
unsigned long V_197 ;
unsigned long V_198 = 0 ;
unsigned long V_199 , V_15 = 0 , V_328 = 0 ;
const char * V_81 ;
char * error = NULL ;
int V_45 ;
struct V_6 * V_40 ;
V_196 = 0 ;
V_199 = 0 ;
F_28 (node) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_194 () ;
F_105 ( & V_40 -> V_14 ) ;
F_73 (slabp, &l3->slabs_full, list) {
if ( V_108 -> V_200 != V_18 -> V_72 && ! error )
error = L_39 ;
V_196 += V_18 -> V_72 ;
V_198 ++ ;
}
F_73 (slabp, &l3->slabs_partial, list) {
if ( V_108 -> V_200 == V_18 -> V_72 && ! error )
error = L_40 ;
if ( ! V_108 -> V_200 && ! error )
error = L_41 ;
V_196 += V_108 -> V_200 ;
V_198 ++ ;
}
F_73 (slabp, &l3->slabs_free, list) {
if ( V_108 -> V_200 && ! error )
error = L_42 ;
V_199 ++ ;
}
V_15 += V_40 -> V_15 ;
if ( V_40 -> V_11 )
V_328 += V_40 -> V_11 -> V_105 ;
F_99 ( & V_40 -> V_14 ) ;
}
V_199 += V_198 ;
V_197 = V_199 * V_18 -> V_72 ;
if ( V_197 - V_196 != V_15 && ! error )
error = L_43 ;
V_81 = V_18 -> V_81 ;
if ( error )
F_44 ( V_80 L_44 , V_81 , error ) ;
V_327 -> V_196 = V_196 ;
V_327 -> V_197 = V_197 ;
V_327 -> V_198 = V_198 ;
V_327 -> V_199 = V_199 ;
V_327 -> V_328 = V_328 ;
V_327 -> V_106 = V_18 -> V_106 ;
V_327 -> V_101 = V_18 -> V_101 ;
V_327 -> V_11 = V_18 -> V_11 ;
V_327 -> V_329 = V_18 -> V_72 ;
V_327 -> V_330 = V_18 -> V_69 ;
}
void F_313 ( struct V_331 * V_332 , struct V_17 * V_18 )
{
#if V_306
{
unsigned long V_333 = V_18 -> V_334 ;
unsigned long V_335 = V_18 -> V_336 ;
unsigned long V_337 = V_18 -> V_337 ;
unsigned long V_338 = V_18 -> V_338 ;
unsigned long V_339 = V_18 -> V_339 ;
unsigned long V_340 = V_18 -> V_340 ;
unsigned long V_341 = V_18 -> V_341 ;
unsigned long V_342 = V_18 -> V_342 ;
unsigned long V_343 = V_18 -> V_344 ;
F_314 ( V_332 , L_45
L_46 ,
V_335 , V_333 , V_337 ,
V_338 , V_339 , V_340 , V_341 ,
V_342 , V_343 ) ;
}
{
unsigned long V_345 = F_315 ( & V_18 -> V_345 ) ;
unsigned long V_346 = F_315 ( & V_18 -> V_346 ) ;
unsigned long V_347 = F_315 ( & V_18 -> V_347 ) ;
unsigned long V_348 = F_315 ( & V_18 -> V_348 ) ;
F_314 ( V_332 , L_47 ,
V_345 , V_346 , V_347 , V_348 ) ;
}
#endif
}
T_11 F_316 ( struct V_349 * V_349 , const char T_12 * V_350 ,
T_2 V_351 , T_13 * V_352 )
{
char V_353 [ V_354 + 1 ] , * V_355 ;
int V_106 , V_101 , V_11 , V_356 ;
struct V_17 * V_18 ;
if ( V_351 > V_354 )
return - V_357 ;
if ( F_317 ( & V_353 , V_350 , V_351 ) )
return - V_358 ;
V_353 [ V_354 ] = '\0' ;
V_355 = strchr ( V_353 , ' ' ) ;
if ( ! V_355 )
return - V_357 ;
* V_355 = '\0' ;
V_355 ++ ;
if ( sscanf ( V_355 , L_48 , & V_106 , & V_101 , & V_11 ) != 3 )
return - V_357 ;
F_114 ( & V_141 ) ;
V_356 = - V_357 ;
F_73 (cachep, &slab_caches, list) {
if ( ! strcmp ( V_18 -> V_81 , V_353 ) ) {
if ( V_106 < 1 || V_101 < 1 ||
V_101 > V_106 || V_11 < 0 ) {
V_356 = 0 ;
} else {
V_356 = F_298 ( V_18 , V_106 ,
V_101 , V_11 ,
V_122 ) ;
}
break;
}
}
F_115 ( & V_141 ) ;
if ( V_356 >= 0 )
V_356 = V_351 ;
return V_356 ;
}
static void * F_318 ( struct V_331 * V_332 , T_13 * V_359 )
{
F_114 ( & V_141 ) ;
return F_319 ( & V_182 , * V_359 ) ;
}
static inline int F_320 ( unsigned long * V_360 , unsigned long V_361 )
{
unsigned long * V_256 ;
int V_362 ;
if ( ! V_361 )
return 1 ;
V_362 = V_360 [ 1 ] ;
V_256 = V_360 + 2 ;
while ( V_362 ) {
int V_5 = V_362 / 2 ;
unsigned long * V_37 = V_256 + 2 * V_5 ;
if ( * V_37 == V_361 ) {
V_37 [ 1 ] ++ ;
return 1 ;
}
if ( * V_37 > V_361 ) {
V_362 = V_5 ;
} else {
V_256 = V_37 + 2 ;
V_362 -= V_5 + 1 ;
}
}
if ( ++ V_360 [ 1 ] == V_360 [ 0 ] )
return 0 ;
memmove ( V_256 + 2 , V_256 , V_360 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_256 - ( void * ) V_360 ) ) ;
V_256 [ 0 ] = V_361 ;
V_256 [ 1 ] = 1 ;
return 1 ;
}
static void F_321 ( unsigned long * V_360 , struct V_17 * V_309 , struct V_27 * V_49 )
{
void * V_256 ;
int V_5 ;
if ( V_360 [ 0 ] == V_360 [ 1 ] )
return;
for ( V_5 = 0 , V_256 = V_49 -> V_31 ; V_5 < V_309 -> V_72 ; V_5 ++ , V_256 += V_309 -> V_3 ) {
if ( F_213 ( V_49 ) [ V_5 ] != V_280 )
continue;
if ( ! F_320 ( V_360 , ( unsigned long ) * F_14 ( V_309 , V_256 ) ) )
return;
}
}
static void F_322 ( struct V_331 * V_332 , unsigned long V_363 )
{
#ifdef F_323
unsigned long V_32 , V_3 ;
char V_364 [ V_365 ] , V_81 [ V_366 ] ;
if ( F_324 ( V_363 , & V_3 , & V_32 , V_364 , V_81 ) == 0 ) {
F_314 ( V_332 , L_49 , V_81 , V_32 , V_3 ) ;
if ( V_364 [ 0 ] )
F_314 ( V_332 , L_50 , V_364 ) ;
return;
}
#endif
F_314 ( V_332 , L_51 , ( void * ) V_363 ) ;
}
static int F_325 ( struct V_331 * V_332 , void * V_256 )
{
struct V_17 * V_18 = F_203 ( V_256 , struct V_17 , V_166 ) ;
struct V_27 * V_108 ;
struct V_6 * V_40 ;
const char * V_81 ;
unsigned long * V_360 = V_332 -> V_367 ;
int V_45 ;
int V_5 ;
if ( ! ( V_18 -> V_19 & V_21 ) )
return 0 ;
if ( ! ( V_18 -> V_19 & V_20 ) )
return 0 ;
V_360 [ 1 ] = 0 ;
F_28 (node) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_194 () ;
F_105 ( & V_40 -> V_14 ) ;
F_73 (slabp, &l3->slabs_full, list)
F_321 ( V_360 , V_18 , V_108 ) ;
F_73 (slabp, &l3->slabs_partial, list)
F_321 ( V_360 , V_18 , V_108 ) ;
F_99 ( & V_40 -> V_14 ) ;
}
V_81 = V_18 -> V_81 ;
if ( V_360 [ 0 ] == V_360 [ 1 ] ) {
F_115 ( & V_141 ) ;
V_332 -> V_367 = F_297 ( V_360 [ 0 ] * 4 * sizeof( unsigned long ) , V_122 ) ;
if ( ! V_332 -> V_367 ) {
V_332 -> V_367 = V_360 ;
F_114 ( & V_141 ) ;
return - V_123 ;
}
* ( unsigned long * ) V_332 -> V_367 = V_360 [ 0 ] * 2 ;
F_92 ( V_360 ) ;
F_114 ( & V_141 ) ;
V_332 -> V_351 = V_332 -> V_3 ;
return 0 ;
}
for ( V_5 = 0 ; V_5 < V_360 [ 1 ] ; V_5 ++ ) {
F_314 ( V_332 , L_52 , V_81 , V_360 [ 2 * V_5 + 3 ] ) ;
F_322 ( V_332 , V_360 [ 2 * V_5 + 2 ] ) ;
F_326 ( V_332 , '\n' ) ;
}
return 0 ;
}
static void * F_327 ( struct V_331 * V_332 , void * V_256 , T_13 * V_359 )
{
return F_328 ( V_256 , & V_182 , V_359 ) ;
}
static void F_329 ( struct V_331 * V_332 , void * V_256 )
{
F_115 ( & V_141 ) ;
}
static int F_330 ( struct V_368 * V_368 , struct V_349 * V_349 )
{
unsigned long * V_360 = F_297 ( V_75 , V_122 ) ;
int V_152 = - V_123 ;
if ( V_360 ) {
V_152 = F_331 ( V_349 , & V_369 ) ;
if ( ! V_152 ) {
struct V_331 * V_332 = V_349 -> V_370 ;
* V_360 = V_75 / ( 2 * sizeof( unsigned long ) ) ;
V_332 -> V_367 = V_360 ;
V_360 = NULL ;
}
F_92 ( V_360 ) ;
}
return V_152 ;
}
static int T_6 F_332 ( void )
{
#ifdef F_230
F_333 ( L_53 , 0 , NULL , & V_371 ) ;
#endif
return 0 ;
}
T_2 F_334 ( const void * V_1 )
{
F_12 ( ! V_1 ) ;
if ( F_38 ( V_1 == V_63 ) )
return 0 ;
return F_15 ( V_1 ) -> V_224 ;
}
