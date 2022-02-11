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
T_2 F_15 ( struct V_17 * V_18 )
{
return V_18 -> V_3 ;
}
static inline struct V_17 * F_16 ( struct V_24 * V_24 )
{
V_24 = F_17 ( V_24 ) ;
F_12 ( ! F_18 ( V_24 ) ) ;
return V_24 -> V_25 ;
}
static inline struct V_17 * F_19 ( const void * V_26 )
{
struct V_24 * V_24 = F_20 ( V_26 ) ;
return V_24 -> V_25 ;
}
static inline struct V_27 * F_21 ( const void * V_26 )
{
struct V_24 * V_24 = F_20 ( V_26 ) ;
F_22 ( ! F_18 ( V_24 ) ) ;
return V_24 -> V_28 ;
}
static inline void * F_23 ( struct V_17 * V_29 , struct V_27 * V_27 ,
unsigned int V_30 )
{
return V_27 -> V_31 + V_29 -> V_3 * V_30 ;
}
static inline unsigned int F_24 ( const struct V_17 * V_29 ,
const struct V_27 * V_27 , void * V_26 )
{
T_4 V_32 = ( V_26 - V_27 -> V_31 ) ;
return F_25 ( V_32 , V_29 -> V_33 ) ;
}
static void F_26 ( struct V_17 * V_18 ,
struct V_34 * V_35 , struct V_34 * V_36 ,
int V_37 )
{
struct V_38 * * V_39 ;
struct V_6 * V_40 ;
int V_41 ;
V_40 = V_18 -> V_42 [ V_37 ] ;
if ( ! V_40 )
return;
F_27 ( & V_40 -> V_14 , V_35 ) ;
V_39 = V_40 -> V_12 ;
if ( ! V_39 || ( unsigned long ) V_39 == V_43 )
return;
F_28 (r) {
if ( V_39 [ V_41 ] )
F_27 ( & V_39 [ V_41 ] -> V_44 , V_36 ) ;
}
}
static void F_29 ( struct V_17 * V_18 , int V_45 )
{
F_26 ( V_18 , & V_46 , & V_47 , V_45 ) ;
}
static void F_30 ( struct V_17 * V_18 )
{
int V_45 ;
F_31 (node)
F_29 ( V_18 , V_45 ) ;
}
static void F_32 ( int V_37 )
{
struct V_48 * V_49 = V_50 ;
if ( V_51 < V_52 )
return;
for ( V_49 = V_50 ; V_49 -> V_53 != V_54 ; V_49 ++ ) {
struct V_6 * V_40 ;
V_40 = V_49 -> V_55 -> V_42 [ V_37 ] ;
if ( ! V_40 || F_33 ( V_49 -> V_55 ) )
continue;
F_26 ( V_49 -> V_55 , & V_56 ,
& V_57 , V_37 ) ;
}
}
static inline void F_34 ( void )
{
int V_45 ;
F_28 (node)
F_32 ( V_45 ) ;
}
static void F_32 ( int V_37 )
{
}
static inline void F_34 ( void )
{
}
static void F_29 ( struct V_17 * V_18 , int V_45 )
{
}
static void F_30 ( struct V_17 * V_18 )
{
}
static inline struct V_38 * F_35 ( struct V_17 * V_18 )
{
return V_18 -> V_58 [ F_36 () ] ;
}
static inline struct V_17 * F_37 ( T_2 V_3 ,
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
#ifdef F_38
if ( F_39 ( V_59 & V_64 ) )
return V_60 -> V_65 ;
#endif
return V_60 -> V_55 ;
}
static struct V_17 * F_40 ( T_2 V_3 , T_5 V_59 )
{
return F_37 ( V_3 , V_59 ) ;
}
static T_2 F_41 ( T_2 V_66 , T_2 V_67 )
{
return F_42 ( sizeof( struct V_27 ) + V_66 * sizeof( V_68 ) , V_67 ) ;
}
static void F_43 ( unsigned long V_69 , T_2 V_70 ,
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
if ( F_41 ( V_66 , V_67 ) + V_66 * V_70
> V_74 )
V_66 -- ;
if ( V_66 > V_77 )
V_66 = V_77 ;
V_73 = F_41 ( V_66 , V_67 ) ;
}
* V_72 = V_66 ;
* V_71 = V_74 - V_66 * V_70 - V_73 ;
}
static void F_44 ( const char * V_78 , struct V_17 * V_18 ,
char * V_79 )
{
F_45 ( V_80 L_1 ,
V_78 , V_18 -> V_81 , V_79 ) ;
F_46 () ;
}
static int T_6 F_47 ( char * V_49 )
{
V_82 = 0 ;
return 1 ;
}
static int T_6 F_48 ( char * V_83 )
{
F_49 ( & V_83 , & V_84 ) ;
V_84 = V_84 < 0 ? 0 :
F_50 ( V_84 , V_85 - 1 ) ;
V_86 = true ;
return 1 ;
}
static void F_51 ( int V_87 )
{
int V_45 ;
V_45 = F_52 ( F_53 ( V_87 ) , V_88 ) ;
if ( V_45 == V_89 )
V_45 = F_54 ( V_88 ) ;
F_55 ( V_90 , V_87 ) = V_45 ;
}
static void F_56 ( void )
{
int V_45 = F_57 ( V_90 ) ;
V_45 = F_52 ( V_45 , V_88 ) ;
if ( F_39 ( V_45 >= V_89 ) )
V_45 = F_54 ( V_88 ) ;
F_58 ( V_90 , V_45 ) ;
}
static void T_7 F_59 ( int V_87 )
{
struct V_91 * V_92 = & F_55 ( V_93 , V_87 ) ;
if ( F_60 () && V_92 -> V_94 . V_95 == NULL ) {
F_51 ( V_87 ) ;
F_61 ( V_92 , V_96 ) ;
F_62 ( V_87 , V_92 ,
F_63 ( V_97 , V_87 ) ) ;
}
}
static struct V_38 * F_64 ( int V_45 , int V_98 ,
int V_99 , T_5 V_100 )
{
int V_101 = sizeof( void * ) * V_98 + sizeof( struct V_38 ) ;
struct V_38 * V_102 = NULL ;
V_102 = F_65 ( V_101 , V_100 , V_45 ) ;
F_66 ( V_102 ) ;
if ( V_102 ) {
V_102 -> V_103 = 0 ;
V_102 -> V_104 = V_98 ;
V_102 -> V_99 = V_99 ;
V_102 -> V_105 = 0 ;
F_9 ( & V_102 -> V_44 ) ;
}
return V_102 ;
}
static inline bool F_67 ( struct V_27 * V_106 )
{
struct V_24 * V_24 = F_68 ( V_106 -> V_31 ) ;
return F_69 ( V_24 ) ;
}
static void F_70 ( struct V_17 * V_18 ,
struct V_38 * V_107 )
{
struct V_6 * V_40 = V_18 -> V_42 [ F_71 () ] ;
struct V_27 * V_106 ;
unsigned long V_19 ;
if ( ! V_108 )
return;
F_72 ( & V_40 -> V_14 , V_19 ) ;
F_73 (slabp, &l3->slabs_full, list)
if ( F_67 ( V_106 ) )
goto V_109;
F_73 (slabp, &l3->slabs_partial, list)
if ( F_67 ( V_106 ) )
goto V_109;
F_73 (slabp, &l3->slabs_free, list)
if ( F_67 ( V_106 ) )
goto V_109;
V_108 = false ;
V_109:
F_74 ( & V_40 -> V_14 , V_19 ) ;
}
static void * F_75 ( struct V_17 * V_18 , struct V_38 * V_107 ,
T_5 V_19 , bool V_110 )
{
int V_5 ;
void * V_1 = V_107 -> V_111 [ -- V_107 -> V_103 ] ;
if ( F_39 ( F_1 ( V_1 ) ) ) {
struct V_6 * V_40 ;
if ( F_76 ( V_19 ) ) {
F_3 ( & V_1 ) ;
return V_1 ;
}
for ( V_5 = 0 ; V_5 < V_107 -> V_103 ; V_5 ++ ) {
if ( ! F_1 ( V_107 -> V_111 [ V_5 ] ) ) {
V_1 = V_107 -> V_111 [ V_5 ] ;
V_107 -> V_111 [ V_5 ] = V_107 -> V_111 [ V_107 -> V_103 ] ;
V_107 -> V_111 [ V_107 -> V_103 ] = V_1 ;
return V_1 ;
}
}
V_40 = V_18 -> V_42 [ F_71 () ] ;
if ( ! F_77 ( & V_40 -> V_10 ) && V_110 ) {
struct V_27 * V_106 = F_21 ( V_1 ) ;
F_78 ( F_20 ( V_106 -> V_31 ) ) ;
F_3 ( & V_1 ) ;
F_70 ( V_18 , V_107 ) ;
return V_1 ;
}
V_107 -> V_103 ++ ;
V_1 = NULL ;
}
return V_1 ;
}
static inline void * F_79 ( struct V_17 * V_18 ,
struct V_38 * V_107 , T_5 V_19 , bool V_110 )
{
void * V_1 ;
if ( F_39 ( F_80 () ) )
V_1 = F_75 ( V_18 , V_107 , V_19 , V_110 ) ;
else
V_1 = V_107 -> V_111 [ -- V_107 -> V_103 ] ;
return V_1 ;
}
static void * F_81 ( struct V_17 * V_18 , struct V_38 * V_107 ,
void * V_1 )
{
if ( F_39 ( V_108 ) ) {
struct V_24 * V_24 = F_20 ( V_1 ) ;
if ( F_69 ( V_24 ) )
F_2 ( & V_1 ) ;
}
return V_1 ;
}
static inline void F_82 ( struct V_17 * V_18 , struct V_38 * V_107 ,
void * V_1 )
{
if ( F_39 ( F_80 () ) )
V_1 = F_81 ( V_18 , V_107 , V_1 ) ;
V_107 -> V_111 [ V_107 -> V_103 ++ ] = V_1 ;
}
static int F_83 ( struct V_38 * V_112 ,
struct V_38 * V_113 , unsigned int V_114 )
{
int V_115 = F_84 ( V_113 -> V_103 , V_114 , V_112 -> V_104 - V_112 -> V_103 ) ;
if ( ! V_115 )
return 0 ;
memcpy ( V_112 -> V_111 + V_112 -> V_103 , V_113 -> V_111 + V_113 -> V_103 - V_115 ,
sizeof( void * ) * V_115 ) ;
V_113 -> V_103 -= V_115 ;
V_112 -> V_103 += V_115 ;
return V_115 ;
}
static inline struct V_38 * * F_85 ( int V_45 , int V_104 , T_5 V_100 )
{
return (struct V_38 * * ) V_43 ;
}
static inline void F_86 ( struct V_38 * * V_116 )
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
T_5 V_19 , int V_117 )
{
return NULL ;
}
static struct V_38 * * F_85 ( int V_45 , int V_104 , T_5 V_100 )
{
struct V_38 * * V_116 ;
int V_101 = sizeof( void * ) * V_118 ;
int V_5 ;
if ( V_104 > 1 )
V_104 = 12 ;
V_116 = F_90 ( V_101 , V_100 , V_45 ) ;
if ( V_116 ) {
F_28 (i) {
if ( V_5 == V_45 || ! F_91 ( V_5 ) )
continue;
V_116 [ V_5 ] = F_64 ( V_45 , V_104 , 0xbaadf00d , V_100 ) ;
if ( ! V_116 [ V_5 ] ) {
for ( V_5 -- ; V_5 >= 0 ; V_5 -- )
F_92 ( V_116 [ V_5 ] ) ;
F_92 ( V_116 ) ;
return NULL ;
}
}
}
return V_116 ;
}
static void F_86 ( struct V_38 * * V_116 )
{
int V_5 ;
if ( ! V_116 )
return;
F_28 (i)
F_92 ( V_116 [ V_5 ] ) ;
F_92 ( V_116 ) ;
}
static void F_93 ( struct V_17 * V_18 ,
struct V_38 * V_107 , int V_45 )
{
struct V_6 * V_119 = V_18 -> V_42 [ V_45 ] ;
if ( V_107 -> V_103 ) {
F_94 ( & V_119 -> V_14 ) ;
if ( V_119 -> V_11 )
F_83 ( V_119 -> V_11 , V_107 , V_107 -> V_104 ) ;
F_95 ( V_18 , V_107 -> V_111 , V_107 -> V_103 , V_45 ) ;
V_107 -> V_103 = 0 ;
F_96 ( & V_119 -> V_14 ) ;
}
}
static void F_97 ( struct V_17 * V_18 , struct V_6 * V_40 )
{
int V_45 = F_57 ( V_90 ) ;
if ( V_40 -> V_12 ) {
struct V_38 * V_107 = V_40 -> V_12 [ V_45 ] ;
if ( V_107 && V_107 -> V_103 && F_98 ( & V_107 -> V_44 ) ) {
F_93 ( V_18 , V_107 , V_45 ) ;
F_99 ( & V_107 -> V_44 ) ;
}
}
}
static void F_100 ( struct V_17 * V_18 ,
struct V_38 * * V_12 )
{
int V_5 = 0 ;
struct V_38 * V_107 ;
unsigned long V_19 ;
F_31 (i) {
V_107 = V_12 [ V_5 ] ;
if ( V_107 ) {
F_72 ( & V_107 -> V_44 , V_19 ) ;
F_93 ( V_18 , V_107 , V_5 ) ;
F_74 ( & V_107 -> V_44 , V_19 ) ;
}
}
}
static inline int F_87 ( struct V_17 * V_18 , void * V_1 )
{
struct V_27 * V_106 = F_21 ( V_1 ) ;
int V_117 = V_106 -> V_117 ;
struct V_6 * V_40 ;
struct V_38 * V_12 = NULL ;
int V_45 ;
V_45 = F_71 () ;
if ( F_101 ( V_106 -> V_117 == V_45 ) )
return 0 ;
V_40 = V_18 -> V_42 [ V_45 ] ;
F_102 ( V_18 ) ;
if ( V_40 -> V_12 && V_40 -> V_12 [ V_117 ] ) {
V_12 = V_40 -> V_12 [ V_117 ] ;
F_94 ( & V_12 -> V_44 ) ;
if ( F_39 ( V_12 -> V_103 == V_12 -> V_104 ) ) {
F_103 ( V_18 ) ;
F_93 ( V_18 , V_12 , V_117 ) ;
}
F_82 ( V_18 , V_12 , V_1 ) ;
F_96 ( & V_12 -> V_44 ) ;
} else {
F_94 ( & ( V_18 -> V_42 [ V_117 ] ) -> V_14 ) ;
F_95 ( V_18 , & V_1 , 1 , V_117 ) ;
F_96 ( & ( V_18 -> V_42 [ V_117 ] ) -> V_14 ) ;
}
return 1 ;
}
static int F_104 ( int V_45 )
{
struct V_17 * V_18 ;
struct V_6 * V_40 ;
const int V_101 = sizeof( struct V_6 ) ;
F_73 (cachep, &slab_caches, list) {
if ( ! V_18 -> V_42 [ V_45 ] ) {
V_40 = F_65 ( V_101 , V_120 , V_45 ) ;
if ( ! V_40 )
return - V_121 ;
F_7 ( V_40 ) ;
V_40 -> V_122 = V_123 + V_124 +
( ( unsigned long ) V_18 ) % V_124 ;
V_18 -> V_42 [ V_45 ] = V_40 ;
}
F_105 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
V_18 -> V_42 [ V_45 ] -> V_125 =
( 1 + F_106 ( V_45 ) ) *
V_18 -> V_99 + V_18 -> V_72 ;
F_99 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
}
return 0 ;
}
static void T_7 F_107 ( long V_87 )
{
struct V_17 * V_18 ;
struct V_6 * V_40 = NULL ;
int V_45 = F_53 ( V_87 ) ;
const struct V_126 * V_127 = F_108 ( V_45 ) ;
F_73 (cachep, &slab_caches, list) {
struct V_38 * V_102 ;
struct V_38 * V_11 ;
struct V_38 * * V_12 ;
V_102 = V_18 -> V_58 [ V_87 ] ;
V_18 -> V_58 [ V_87 ] = NULL ;
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
goto V_128;
F_105 ( & V_40 -> V_14 ) ;
V_40 -> V_125 -= V_18 -> V_99 ;
if ( V_102 )
F_95 ( V_18 , V_102 -> V_111 , V_102 -> V_103 , V_45 ) ;
if ( ! F_109 ( V_127 ) ) {
F_99 ( & V_40 -> V_14 ) ;
goto V_128;
}
V_11 = V_40 -> V_11 ;
if ( V_11 ) {
F_95 ( V_18 , V_11 -> V_111 ,
V_11 -> V_103 , V_45 ) ;
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
V_128:
F_92 ( V_102 ) ;
}
F_73 (cachep, &slab_caches, list) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_110 ( V_18 , V_40 , V_40 -> V_15 ) ;
}
}
static int T_7 F_111 ( long V_87 )
{
struct V_17 * V_18 ;
struct V_6 * V_40 = NULL ;
int V_45 = F_53 ( V_87 ) ;
int V_129 ;
V_129 = F_104 ( V_45 ) ;
if ( V_129 < 0 )
goto V_130;
F_73 (cachep, &slab_caches, list) {
struct V_38 * V_102 ;
struct V_38 * V_11 = NULL ;
struct V_38 * * V_12 = NULL ;
V_102 = F_64 ( V_45 , V_18 -> V_104 ,
V_18 -> V_99 , V_120 ) ;
if ( ! V_102 )
goto V_130;
if ( V_18 -> V_11 ) {
V_11 = F_64 ( V_45 ,
V_18 -> V_11 * V_18 -> V_99 ,
0xbaadf00d , V_120 ) ;
if ( ! V_11 ) {
F_92 ( V_102 ) ;
goto V_130;
}
}
if ( V_82 ) {
V_12 = F_85 ( V_45 , V_18 -> V_104 , V_120 ) ;
if ( ! V_12 ) {
F_92 ( V_11 ) ;
F_92 ( V_102 ) ;
goto V_130;
}
}
V_18 -> V_58 [ V_87 ] = V_102 ;
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
if ( V_18 -> V_19 & V_131 )
F_29 ( V_18 , V_45 ) ;
}
F_32 ( V_45 ) ;
return 0 ;
V_130:
F_107 ( V_87 ) ;
return - V_121 ;
}
static int T_7 F_113 ( struct V_132 * V_133 ,
unsigned long V_134 , void * V_135 )
{
long V_87 = ( long ) V_135 ;
int V_129 = 0 ;
switch ( V_134 ) {
case V_136 :
case V_137 :
F_114 ( & V_138 ) ;
V_129 = F_111 ( V_87 ) ;
F_115 ( & V_138 ) ;
break;
case V_139 :
case V_140 :
F_59 ( V_87 ) ;
break;
#ifdef F_116
case V_141 :
case V_142 :
F_117 ( & F_55 ( V_93 , V_87 ) ) ;
F_55 ( V_93 , V_87 ) . V_94 . V_95 = NULL ;
break;
case V_143 :
case V_144 :
F_59 ( V_87 ) ;
break;
case V_145 :
case V_146 :
#endif
case V_147 :
case V_148 :
F_114 ( & V_138 ) ;
F_107 ( V_87 ) ;
F_115 ( & V_138 ) ;
break;
}
return F_118 ( V_129 ) ;
}
static int T_8 F_119 ( int V_45 )
{
struct V_17 * V_18 ;
int V_149 = 0 ;
F_73 (cachep, &slab_caches, list) {
struct V_6 * V_40 ;
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_110 ( V_18 , V_40 , V_40 -> V_15 ) ;
if ( ! F_77 ( & V_40 -> V_8 ) ||
! F_77 ( & V_40 -> V_9 ) ) {
V_149 = - V_150 ;
break;
}
}
return V_149 ;
}
static int T_8 F_120 ( struct V_132 * V_151 ,
unsigned long V_134 , void * V_152 )
{
struct V_153 * V_154 = V_152 ;
int V_149 = 0 ;
int V_155 ;
V_155 = V_154 -> V_156 ;
if ( V_155 < 0 )
goto V_109;
switch ( V_134 ) {
case V_157 :
F_114 ( & V_138 ) ;
V_149 = F_104 ( V_155 ) ;
F_115 ( & V_138 ) ;
break;
case V_158 :
F_114 ( & V_138 ) ;
V_149 = F_119 ( V_155 ) ;
F_115 ( & V_138 ) ;
break;
case V_159 :
case V_160 :
case V_161 :
case V_162 :
break;
}
V_109:
return F_118 ( V_149 ) ;
}
static void T_6 F_121 ( struct V_17 * V_18 , struct V_6 * V_163 ,
int V_117 )
{
struct V_6 * V_164 ;
V_164 = F_65 ( sizeof( struct V_6 ) , V_165 , V_117 ) ;
F_12 ( ! V_164 ) ;
memcpy ( V_164 , V_163 , sizeof( struct V_6 ) ) ;
F_9 ( & V_164 -> V_14 ) ;
F_122 ( V_18 , V_164 , V_117 ) ;
V_18 -> V_42 [ V_117 ] = V_164 ;
}
static void T_6 F_123 ( struct V_17 * V_18 , int V_166 )
{
int V_45 ;
F_31 (node) {
V_18 -> V_42 [ V_45 ] = & V_167 [ V_166 + V_45 ] ;
V_18 -> V_42 [ V_45 ] -> V_122 = V_123 +
V_124 +
( ( unsigned long ) V_18 ) % V_124 ;
}
}
void T_6 F_124 ( void )
{
T_2 V_71 ;
struct V_48 * V_168 ;
struct V_169 * V_170 ;
int V_5 ;
int V_171 ;
int V_45 ;
if ( F_125 () == 1 )
V_82 = 0 ;
for ( V_5 = 0 ; V_5 < V_172 ; V_5 ++ ) {
F_7 ( & V_167 [ V_5 ] ) ;
if ( V_5 < V_89 )
V_173 . V_42 [ V_5 ] = NULL ;
}
F_123 ( & V_173 , V_174 ) ;
if ( ! V_86 && V_175 > ( 32 << 20 ) >> V_176 )
V_84 = V_177 ;
V_45 = F_71 () ;
F_8 ( & V_178 ) ;
F_126 ( & V_173 . V_163 , & V_178 ) ;
V_173 . V_179 = F_127 () ;
V_173 . V_58 [ F_36 () ] = & V_180 . V_29 ;
V_173 . V_42 [ V_45 ] = & V_167 [ V_174 + V_45 ] ;
V_173 . V_3 = F_128 ( struct V_17 , V_58 [ V_181 ] ) +
V_118 * sizeof( struct V_6 * ) ;
V_173 . V_182 = V_173 . V_3 ;
V_173 . V_3 = F_42 ( V_173 . V_3 ,
F_127 () ) ;
V_173 . V_33 =
F_129 ( V_173 . V_3 ) ;
for ( V_171 = 0 ; V_171 < V_85 ; V_171 ++ ) {
F_43 ( V_171 , V_173 . V_3 ,
F_127 () , 0 , & V_71 , & V_173 . V_72 ) ;
if ( V_173 . V_72 )
break;
}
F_12 ( ! V_173 . V_72 ) ;
V_173 . V_69 = V_171 ;
V_173 . V_183 = V_71 / V_173 . V_179 ;
V_173 . V_74 = F_42 ( V_173 . V_72 * sizeof( V_68 ) +
sizeof( struct V_27 ) , F_127 () ) ;
V_168 = V_50 ;
V_170 = V_169 ;
V_168 [ V_62 ] . V_55 = F_130 ( V_170 [ V_62 ] . V_81 ,
V_168 [ V_62 ] . V_53 ,
V_184 ,
V_185 | V_186 ,
NULL ) ;
if ( V_62 != V_187 ) {
V_168 [ V_187 ] . V_55 =
F_130 ( V_170 [ V_187 ] . V_81 ,
V_168 [ V_187 ] . V_53 ,
V_184 ,
V_185 | V_186 ,
NULL ) ;
}
V_188 = 0 ;
while ( V_168 -> V_53 != V_54 ) {
if ( ! V_168 -> V_55 ) {
V_168 -> V_55 = F_130 ( V_170 -> V_81 ,
V_168 -> V_53 ,
V_184 ,
V_185 | V_186 ,
NULL ) ;
}
#ifdef F_38
V_168 -> V_65 = F_130 (
V_170 -> V_189 ,
V_168 -> V_53 ,
V_184 ,
V_185 | V_190 |
V_186 ,
NULL ) ;
#endif
V_168 ++ ;
V_170 ++ ;
}
{
struct V_38 * V_164 ;
V_164 = F_131 ( sizeof( struct V_191 ) , V_165 ) ;
F_12 ( F_35 ( & V_173 ) != & V_180 . V_29 ) ;
memcpy ( V_164 , F_35 ( & V_173 ) ,
sizeof( struct V_191 ) ) ;
F_9 ( & V_164 -> V_44 ) ;
V_173 . V_58 [ F_36 () ] = V_164 ;
V_164 = F_131 ( sizeof( struct V_191 ) , V_165 ) ;
F_12 ( F_35 ( V_50 [ V_62 ] . V_55 )
!= & V_192 . V_29 ) ;
memcpy ( V_164 , F_35 ( V_50 [ V_62 ] . V_55 ) ,
sizeof( struct V_191 ) ) ;
F_9 ( & V_164 -> V_44 ) ;
V_50 [ V_62 ] . V_55 -> V_58 [ F_36 () ] =
V_164 ;
}
{
int V_155 ;
F_31 (nid) {
F_121 ( & V_173 , & V_167 [ V_174 + V_155 ] , V_155 ) ;
F_121 ( V_50 [ V_62 ] . V_55 ,
& V_167 [ V_193 + V_155 ] , V_155 ) ;
if ( V_62 != V_187 ) {
F_121 ( V_50 [ V_187 ] . V_55 ,
& V_167 [ V_194 + V_155 ] , V_155 ) ;
}
}
}
V_51 = V_52 ;
}
void T_6 F_132 ( void )
{
struct V_17 * V_18 ;
V_51 = V_52 ;
F_34 () ;
F_114 ( & V_138 ) ;
F_73 (cachep, &slab_caches, list)
if ( F_133 ( V_18 , V_165 ) )
F_134 () ;
F_115 ( & V_138 ) ;
V_51 = V_195 ;
F_135 ( & V_196 ) ;
#ifdef F_112
F_136 ( F_120 , V_197 ) ;
#endif
}
static int T_6 F_137 ( void )
{
int V_87 ;
F_138 (cpu)
F_59 ( V_87 ) ;
V_51 = V_195 ;
return 0 ;
}
static T_9 void
F_139 ( struct V_17 * V_18 , T_5 V_59 , int V_117 )
{
struct V_6 * V_40 ;
struct V_27 * V_106 ;
unsigned long V_19 ;
int V_45 ;
F_45 ( V_198
L_2 ,
V_117 , V_59 ) ;
F_45 ( V_198 L_3 ,
V_18 -> V_81 , V_18 -> V_3 , V_18 -> V_69 ) ;
F_31 (node) {
unsigned long V_199 = 0 , V_200 = 0 , V_15 = 0 ;
unsigned long V_201 = 0 , V_202 = 0 ;
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_72 ( & V_40 -> V_14 , V_19 ) ;
F_73 (slabp, &l3->slabs_full, list) {
V_199 += V_18 -> V_72 ;
V_201 ++ ;
}
F_73 (slabp, &l3->slabs_partial, list) {
V_199 += V_106 -> V_203 ;
V_201 ++ ;
}
F_73 (slabp, &l3->slabs_free, list)
V_202 ++ ;
V_15 += V_40 -> V_15 ;
F_74 ( & V_40 -> V_14 , V_19 ) ;
V_202 += V_201 ;
V_200 = V_202 * V_18 -> V_72 ;
F_45 ( V_198
L_4 ,
V_45 , V_201 , V_202 , V_199 , V_200 ,
V_15 ) ;
}
}
static void * F_140 ( struct V_17 * V_18 , T_5 V_19 , int V_117 )
{
struct V_24 * V_24 ;
int V_204 ;
int V_5 ;
#ifndef F_141
V_19 |= V_205 ;
#endif
V_19 |= V_18 -> V_206 ;
if ( V_18 -> V_19 & V_207 )
V_19 |= V_208 ;
V_24 = F_142 ( V_117 , V_19 | V_209 , V_18 -> V_69 ) ;
if ( ! V_24 ) {
if ( ! ( V_19 & V_210 ) && F_143 () )
F_139 ( V_18 , V_19 , V_117 ) ;
return NULL ;
}
if ( F_39 ( V_24 -> V_211 ) )
V_108 = true ;
V_204 = ( 1 << V_18 -> V_69 ) ;
if ( V_18 -> V_19 & V_207 )
F_144 ( F_145 ( V_24 ) ,
V_212 , V_204 ) ;
else
F_144 ( F_145 ( V_24 ) ,
V_213 , V_204 ) ;
for ( V_5 = 0 ; V_5 < V_204 ; V_5 ++ ) {
F_146 ( V_24 + V_5 ) ;
if ( V_24 -> V_211 )
F_147 ( V_24 + V_5 ) ;
}
if ( V_214 && ! ( V_18 -> V_19 & V_215 ) ) {
F_148 ( V_24 , V_18 -> V_69 , V_19 , V_117 ) ;
if ( V_18 -> V_216 )
F_149 ( V_24 , V_204 ) ;
else
F_150 ( V_24 , V_204 ) ;
}
return F_151 ( V_24 ) ;
}
static void F_152 ( struct V_17 * V_18 , void * V_217 )
{
unsigned long V_5 = ( 1 << V_18 -> V_69 ) ;
struct V_24 * V_24 = F_68 ( V_217 ) ;
const unsigned long V_218 = V_5 ;
F_153 ( V_24 , V_18 -> V_69 ) ;
if ( V_18 -> V_19 & V_207 )
F_154 ( F_145 ( V_24 ) ,
V_212 , V_218 ) ;
else
F_154 ( F_145 ( V_24 ) ,
V_213 , V_218 ) ;
while ( V_5 -- ) {
F_12 ( ! F_18 ( V_24 ) ) ;
F_155 ( V_24 ) ;
F_156 ( V_24 ) ;
V_24 ++ ;
}
if ( V_219 -> V_220 )
V_219 -> V_220 -> V_221 += V_218 ;
F_157 ( ( unsigned long ) V_217 , V_18 -> V_69 ) ;
}
static void F_158 ( struct V_222 * V_223 )
{
struct V_224 * V_224 = (struct V_224 * ) V_223 ;
struct V_17 * V_18 = V_224 -> V_18 ;
F_152 ( V_18 , V_224 -> V_217 ) ;
if ( F_33 ( V_18 ) )
F_159 ( V_18 -> V_225 , V_224 ) ;
}
static void F_160 ( struct V_17 * V_18 , unsigned long * V_217 ,
unsigned long V_226 )
{
int V_3 = V_18 -> V_182 ;
V_217 = ( unsigned long * ) & ( ( char * ) V_217 ) [ F_10 ( V_18 ) ] ;
if ( V_3 < 5 * sizeof( unsigned long ) )
return;
* V_217 ++ = 0x12345678 ;
* V_217 ++ = V_226 ;
* V_217 ++ = F_36 () ;
V_3 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_227 = & V_226 ;
unsigned long V_228 ;
while ( ! F_161 ( V_227 ) ) {
V_228 = * V_227 ++ ;
if ( F_162 ( V_228 ) ) {
* V_217 ++ = V_228 ;
V_3 -= sizeof( unsigned long ) ;
if ( V_3 <= sizeof( unsigned long ) )
break;
}
}
}
* V_217 ++ = 0x87654321 ;
}
static void F_163 ( struct V_17 * V_18 , void * V_217 , unsigned char V_229 )
{
int V_3 = V_18 -> V_182 ;
V_217 = & ( ( char * ) V_217 ) [ F_10 ( V_18 ) ] ;
memset ( V_217 , V_229 , V_3 ) ;
* ( unsigned char * ) ( V_217 + V_3 - 1 ) = V_230 ;
}
static void F_164 ( char * V_231 , int V_32 , int V_104 )
{
int V_5 ;
unsigned char error = 0 ;
int V_232 = 0 ;
F_45 ( V_80 L_5 , V_32 ) ;
for ( V_5 = 0 ; V_5 < V_104 ; V_5 ++ ) {
if ( V_231 [ V_32 + V_5 ] != V_233 ) {
error = V_231 [ V_32 + V_5 ] ;
V_232 ++ ;
}
}
F_165 ( V_234 , L_6 , 0 , 16 , 1 ,
& V_231 [ V_32 ] , V_104 , 1 ) ;
if ( V_232 == 1 ) {
error ^= V_233 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_45 ( V_80 L_7
L_8 ) ;
#ifdef F_166
F_45 ( V_80 L_9
L_10 ) ;
#else
F_45 ( V_80 L_11 ) ;
#endif
}
}
}
static void F_167 ( struct V_17 * V_18 , void * V_1 , int V_235 )
{
int V_5 , V_3 ;
char * V_236 ;
if ( V_18 -> V_19 & V_20 ) {
F_45 ( V_80 L_12 ,
* F_11 ( V_18 , V_1 ) ,
* F_13 ( V_18 , V_1 ) ) ;
}
if ( V_18 -> V_19 & V_21 ) {
F_45 ( V_80 L_13 ,
* F_14 ( V_18 , V_1 ) ) ;
F_168 ( L_14 ,
( unsigned long ) * F_14 ( V_18 , V_1 ) ) ;
F_45 ( L_15 ) ;
}
V_236 = ( char * ) V_1 + F_10 ( V_18 ) ;
V_3 = V_18 -> V_182 ;
for ( V_5 = 0 ; V_5 < V_3 && V_235 ; V_5 += 16 , V_235 -- ) {
int V_104 ;
V_104 = 16 ;
if ( V_5 + V_104 > V_3 )
V_104 = V_3 - V_5 ;
F_164 ( V_236 , V_5 , V_104 ) ;
}
}
static void F_169 ( struct V_17 * V_18 , void * V_1 )
{
char * V_236 ;
int V_3 , V_5 ;
int V_235 = 0 ;
V_236 = ( char * ) V_1 + F_10 ( V_18 ) ;
V_3 = V_18 -> V_182 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
char exp = V_233 ;
if ( V_5 == V_3 - 1 )
exp = V_230 ;
if ( V_236 [ V_5 ] != exp ) {
int V_104 ;
if ( V_235 == 0 ) {
F_45 ( V_80
L_16 ,
F_170 () , V_18 -> V_81 , V_236 , V_3 ) ;
F_167 ( V_18 , V_1 , 0 ) ;
}
V_5 = ( V_5 / 16 ) * 16 ;
V_104 = 16 ;
if ( V_5 + V_104 > V_3 )
V_104 = V_3 - V_5 ;
F_164 ( V_236 , V_5 , V_104 ) ;
V_5 += 16 ;
V_235 ++ ;
if ( V_235 > 5 )
break;
}
}
if ( V_235 != 0 ) {
struct V_27 * V_106 = F_21 ( V_1 ) ;
unsigned int V_237 ;
V_237 = F_24 ( V_18 , V_106 , V_1 ) ;
if ( V_237 ) {
V_1 = F_23 ( V_18 , V_106 , V_237 - 1 ) ;
V_236 = ( char * ) V_1 + F_10 ( V_18 ) ;
F_45 ( V_80 L_17 ,
V_236 , V_3 ) ;
F_167 ( V_18 , V_1 , 2 ) ;
}
if ( V_237 + 1 < V_18 -> V_72 ) {
V_1 = F_23 ( V_18 , V_106 , V_237 + 1 ) ;
V_236 = ( char * ) V_1 + F_10 ( V_18 ) ;
F_45 ( V_80 L_18 ,
V_236 , V_3 ) ;
F_167 ( V_18 , V_1 , 2 ) ;
}
}
}
static void F_171 ( struct V_17 * V_18 , struct V_27 * V_106 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_72 ; V_5 ++ ) {
void * V_1 = F_23 ( V_18 , V_106 , V_5 ) ;
if ( V_18 -> V_19 & V_238 ) {
#ifdef F_172
if ( V_18 -> V_3 % V_75 == 0 &&
F_33 ( V_18 ) )
F_173 ( F_68 ( V_1 ) ,
V_18 -> V_3 / V_75 , 1 ) ;
else
F_169 ( V_18 , V_1 ) ;
#else
F_169 ( V_18 , V_1 ) ;
#endif
}
if ( V_18 -> V_19 & V_20 ) {
if ( * F_11 ( V_18 , V_1 ) != V_239 )
F_174 ( V_18 , L_19
L_20 ) ;
if ( * F_13 ( V_18 , V_1 ) != V_239 )
F_174 ( V_18 , L_21
L_20 ) ;
}
}
}
static void F_171 ( struct V_17 * V_18 , struct V_27 * V_106 )
{
}
static void F_175 ( struct V_17 * V_18 , struct V_27 * V_106 )
{
void * V_217 = V_106 -> V_31 - V_106 -> V_240 ;
F_171 ( V_18 , V_106 ) ;
if ( F_39 ( V_18 -> V_19 & V_241 ) ) {
struct V_224 * V_224 ;
V_224 = (struct V_224 * ) V_106 ;
V_224 -> V_18 = V_18 ;
V_224 -> V_217 = V_217 ;
F_176 ( & V_224 -> V_223 , F_158 ) ;
} else {
F_152 ( V_18 , V_217 ) ;
if ( F_33 ( V_18 ) )
F_159 ( V_18 -> V_225 , V_106 ) ;
}
}
static void F_177 ( struct V_17 * V_18 )
{
int V_5 ;
struct V_6 * V_40 ;
F_138 (i)
F_92 ( V_18 -> V_58 [ V_5 ] ) ;
F_31 (i) {
V_40 = V_18 -> V_42 [ V_5 ] ;
if ( V_40 ) {
F_92 ( V_40 -> V_11 ) ;
F_86 ( V_40 -> V_12 ) ;
F_92 ( V_40 ) ;
}
}
F_159 ( & V_173 , V_18 ) ;
}
static T_2 F_178 ( struct V_17 * V_18 ,
T_2 V_3 , T_2 V_67 , unsigned long V_19 )
{
unsigned long V_242 ;
T_2 V_71 = 0 ;
int V_69 ;
for ( V_69 = 0 ; V_69 <= V_243 ; V_69 ++ ) {
unsigned int V_72 ;
T_2 V_244 ;
F_43 ( V_69 , V_3 , V_67 , V_19 , & V_244 , & V_72 ) ;
if ( ! V_72 )
continue;
if ( V_19 & V_76 ) {
V_242 = V_3 - sizeof( struct V_27 ) ;
V_242 /= sizeof( V_68 ) ;
if ( V_72 > V_242 )
break;
}
V_18 -> V_72 = V_72 ;
V_18 -> V_69 = V_69 ;
V_71 = V_244 ;
if ( V_19 & V_207 )
break;
if ( V_69 >= V_84 )
break;
if ( V_71 * 8 <= ( V_75 << V_69 ) )
break;
}
return V_71 ;
}
static int T_10 F_179 ( struct V_17 * V_18 , T_5 V_100 )
{
if ( V_51 >= V_195 )
return F_133 ( V_18 , V_100 ) ;
if ( V_51 == V_245 ) {
V_18 -> V_58 [ F_36 () ] = & V_192 . V_29 ;
F_123 ( V_18 , V_193 ) ;
if ( V_62 == V_187 )
V_51 = V_246 ;
else
V_51 = V_247 ;
} else {
V_18 -> V_58 [ F_36 () ] =
F_131 ( sizeof( struct V_191 ) , V_100 ) ;
if ( V_51 == V_247 ) {
F_123 ( V_18 , V_194 ) ;
V_51 = V_246 ;
} else {
int V_45 ;
F_31 (node) {
V_18 -> V_42 [ V_45 ] =
F_65 ( sizeof( struct V_6 ) ,
V_100 , V_45 ) ;
F_12 ( ! V_18 -> V_42 [ V_45 ] ) ;
F_7 ( V_18 -> V_42 [ V_45 ] ) ;
}
}
}
V_18 -> V_42 [ F_71 () ] -> V_122 =
V_123 + V_124 +
( ( unsigned long ) V_18 ) % V_124 ;
F_35 ( V_18 ) -> V_103 = 0 ;
F_35 ( V_18 ) -> V_104 = V_248 ;
F_35 ( V_18 ) -> V_99 = 1 ;
F_35 ( V_18 ) -> V_105 = 0 ;
V_18 -> V_99 = 1 ;
V_18 -> V_104 = V_248 ;
return 0 ;
}
struct V_17 *
F_130 ( const char * V_81 , T_2 V_3 , T_2 V_67 ,
unsigned long V_19 , void (* V_216)( void * ) )
{
T_2 V_71 , V_74 , V_249 ;
struct V_17 * V_18 = NULL ;
T_5 V_100 ;
#if V_61
#if V_250
if ( V_3 < 4096 || F_180 ( V_3 - 1 ) == F_180 ( V_3 - 1 + V_22 +
2 * sizeof( unsigned long long ) ) )
V_19 |= V_20 | V_21 ;
if ( ! ( V_19 & V_241 ) )
V_19 |= V_238 ;
#endif
if ( V_19 & V_241 )
F_12 ( V_19 & V_238 ) ;
#endif
F_12 ( V_19 & ~ V_251 ) ;
if ( V_3 & ( V_23 - 1 ) ) {
V_3 += ( V_23 - 1 ) ;
V_3 &= ~ ( V_23 - 1 ) ;
}
if ( V_19 & V_252 ) {
V_249 = F_127 () ;
while ( V_3 <= V_249 / 2 )
V_249 /= 2 ;
} else {
V_249 = V_23 ;
}
if ( V_19 & V_21 )
V_249 = V_23 ;
if ( V_19 & V_20 ) {
V_249 = V_22 ;
V_3 += V_22 - 1 ;
V_3 &= ~ ( V_22 - 1 ) ;
}
if ( V_249 < V_253 ) {
V_249 = V_253 ;
}
if ( V_249 < V_67 ) {
V_249 = V_67 ;
}
if ( V_249 > F_181 (unsigned long long) )
V_19 &= ~ ( V_20 | V_21 ) ;
V_67 = V_249 ;
if ( F_182 () )
V_100 = V_120 ;
else
V_100 = V_165 ;
V_18 = F_183 ( & V_173 , V_100 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_42 = (struct V_6 * * ) & V_18 -> V_58 [ V_181 ] ;
V_18 -> V_182 = V_3 ;
V_18 -> V_67 = V_67 ;
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
#if V_250 && F_184 ( F_172 )
if ( V_3 >= V_50 [ V_187 + 1 ] . V_53
&& V_18 -> V_182 > F_127 () && F_42 ( V_3 , V_67 ) < V_75 ) {
V_18 -> F_10 += V_75 - F_42 ( V_3 , V_67 ) ;
V_3 = V_75 ;
}
#endif
#endif
if ( ( V_3 >= ( V_75 >> 3 ) ) && ! V_188 &&
! ( V_19 & V_254 ) )
V_19 |= V_76 ;
V_3 = F_42 ( V_3 , V_67 ) ;
V_71 = F_178 ( V_18 , V_3 , V_67 , V_19 ) ;
if ( ! V_18 -> V_72 ) {
F_45 ( V_80
L_22 , V_81 ) ;
F_159 ( & V_173 , V_18 ) ;
return NULL ;
}
V_74 = F_42 ( V_18 -> V_72 * sizeof( V_68 )
+ sizeof( struct V_27 ) , V_67 ) ;
if ( V_19 & V_76 && V_71 >= V_74 ) {
V_19 &= ~ V_76 ;
V_71 -= V_74 ;
}
if ( V_19 & V_76 ) {
V_74 =
V_18 -> V_72 * sizeof( V_68 ) + sizeof( struct V_27 ) ;
#ifdef F_185
if ( V_3 % V_75 == 0 && V_19 & V_238 )
V_19 &= ~ ( V_20 | V_21 ) ;
#endif
}
V_18 -> V_179 = F_127 () ;
if ( V_18 -> V_179 < V_67 )
V_18 -> V_179 = V_67 ;
V_18 -> V_183 = V_71 / V_18 -> V_179 ;
V_18 -> V_74 = V_74 ;
V_18 -> V_19 = V_19 ;
V_18 -> V_206 = 0 ;
if ( V_255 && ( V_19 & V_190 ) )
V_18 -> V_206 |= V_64 ;
V_18 -> V_3 = V_3 ;
V_18 -> V_33 = F_129 ( V_3 ) ;
if ( V_19 & V_76 ) {
V_18 -> V_225 = F_40 ( V_74 , 0u ) ;
F_12 ( F_186 ( V_18 -> V_225 ) ) ;
}
V_18 -> V_216 = V_216 ;
V_18 -> V_81 = V_81 ;
if ( F_179 ( V_18 , V_100 ) ) {
F_177 ( V_18 ) ;
return NULL ;
}
if ( V_19 & V_131 ) {
F_187 ( V_19 & V_241 ) ;
F_30 ( V_18 ) ;
}
F_126 ( & V_18 -> V_163 , & V_178 ) ;
return V_18 ;
}
static void F_188 ( void )
{
F_12 ( ! F_189 () ) ;
}
static void F_190 ( void )
{
F_12 ( F_189 () ) ;
}
static void F_191 ( struct V_17 * V_18 )
{
#ifdef F_192
F_188 () ;
F_193 ( & V_18 -> V_42 [ F_71 () ] -> V_14 ) ;
#endif
}
static void F_194 ( struct V_17 * V_18 , int V_45 )
{
#ifdef F_192
F_188 () ;
F_193 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
#endif
}
static void F_195 ( void * V_152 )
{
struct V_17 * V_18 = V_152 ;
struct V_38 * V_107 ;
int V_45 = F_71 () ;
F_188 () ;
V_107 = F_35 ( V_18 ) ;
F_94 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
F_95 ( V_18 , V_107 -> V_111 , V_107 -> V_103 , V_45 ) ;
F_96 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
V_107 -> V_103 = 0 ;
}
static void F_196 ( struct V_17 * V_18 )
{
struct V_6 * V_40 ;
int V_45 ;
F_197 ( F_195 , V_18 , 1 ) ;
F_190 () ;
F_31 (node) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( V_40 && V_40 -> V_12 )
F_100 ( V_18 , V_40 -> V_12 ) ;
}
F_31 (node) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( V_40 )
F_198 ( V_18 , V_40 , V_40 -> V_11 , 1 , V_45 ) ;
}
}
static int F_110 ( struct V_17 * V_29 ,
struct V_6 * V_40 , int V_256 )
{
struct V_257 * V_258 ;
int V_218 ;
struct V_27 * V_106 ;
V_218 = 0 ;
while ( V_218 < V_256 && ! F_77 ( & V_40 -> V_10 ) ) {
F_105 ( & V_40 -> V_14 ) ;
V_258 = V_40 -> V_10 . V_259 ;
if ( V_258 == & V_40 -> V_10 ) {
F_99 ( & V_40 -> V_14 ) ;
goto V_109;
}
V_106 = F_199 ( V_258 , struct V_27 , V_163 ) ;
#if V_61
F_12 ( V_106 -> V_203 ) ;
#endif
F_200 ( & V_106 -> V_163 ) ;
V_40 -> V_15 -= V_29 -> V_72 ;
F_99 ( & V_40 -> V_14 ) ;
F_175 ( V_29 , V_106 ) ;
V_218 ++ ;
}
V_109:
return V_218 ;
}
static int F_201 ( struct V_17 * V_18 )
{
int V_149 = 0 , V_5 = 0 ;
struct V_6 * V_40 ;
F_196 ( V_18 ) ;
F_190 () ;
F_31 (i) {
V_40 = V_18 -> V_42 [ V_5 ] ;
if ( ! V_40 )
continue;
F_110 ( V_18 , V_40 , V_40 -> V_15 ) ;
V_149 += ! F_77 ( & V_40 -> V_8 ) ||
! F_77 ( & V_40 -> V_9 ) ;
}
return ( V_149 ? 1 : 0 ) ;
}
int F_202 ( struct V_17 * V_18 )
{
int V_149 ;
F_12 ( ! V_18 || F_203 () ) ;
F_204 () ;
F_114 ( & V_138 ) ;
V_149 = F_201 ( V_18 ) ;
F_115 ( & V_138 ) ;
F_205 () ;
return V_149 ;
}
void F_206 ( struct V_17 * V_18 )
{
F_12 ( ! V_18 || F_203 () ) ;
F_204 () ;
F_114 ( & V_138 ) ;
F_200 ( & V_18 -> V_163 ) ;
if ( F_201 ( V_18 ) ) {
F_174 ( V_18 , L_23 ) ;
F_126 ( & V_18 -> V_163 , & V_178 ) ;
F_115 ( & V_138 ) ;
F_205 () ;
return;
}
if ( F_39 ( V_18 -> V_19 & V_241 ) )
F_207 () ;
F_177 ( V_18 ) ;
F_115 ( & V_138 ) ;
F_205 () ;
}
static struct V_27 * F_208 ( struct V_17 * V_18 , void * V_1 ,
int V_179 , T_5 V_260 ,
int V_117 )
{
struct V_27 * V_106 ;
if ( F_33 ( V_18 ) ) {
V_106 = F_209 ( V_18 -> V_225 ,
V_260 , V_117 ) ;
F_210 ( & V_106 -> V_163 , sizeof( struct V_257 ) ,
V_260 ) ;
if ( ! V_106 )
return NULL ;
} else {
V_106 = V_1 + V_179 ;
V_179 += V_18 -> V_74 ;
}
V_106 -> V_203 = 0 ;
V_106 -> V_240 = V_179 ;
V_106 -> V_31 = V_1 + V_179 ;
V_106 -> V_117 = V_117 ;
V_106 -> free = 0 ;
return V_106 ;
}
static inline V_68 * F_211 ( struct V_27 * V_106 )
{
return ( V_68 * ) ( V_106 + 1 ) ;
}
static void F_212 ( struct V_17 * V_18 ,
struct V_27 * V_106 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_72 ; V_5 ++ ) {
void * V_1 = F_23 ( V_18 , V_106 , V_5 ) ;
#if V_61
if ( V_18 -> V_19 & V_238 )
F_163 ( V_18 , V_1 , V_233 ) ;
if ( V_18 -> V_19 & V_21 )
* F_14 ( V_18 , V_1 ) = NULL ;
if ( V_18 -> V_19 & V_20 ) {
* F_11 ( V_18 , V_1 ) = V_239 ;
* F_13 ( V_18 , V_1 ) = V_239 ;
}
if ( V_18 -> V_216 && ! ( V_18 -> V_19 & V_238 ) )
V_18 -> V_216 ( V_1 + F_10 ( V_18 ) ) ;
if ( V_18 -> V_19 & V_20 ) {
if ( * F_13 ( V_18 , V_1 ) != V_239 )
F_174 ( V_18 , L_24
L_25 ) ;
if ( * F_11 ( V_18 , V_1 ) != V_239 )
F_174 ( V_18 , L_24
L_26 ) ;
}
if ( ( V_18 -> V_3 % V_75 ) == 0 &&
F_33 ( V_18 ) && V_18 -> V_19 & V_238 )
F_173 ( F_68 ( V_1 ) ,
V_18 -> V_3 / V_75 , 0 ) ;
#else
if ( V_18 -> V_216 )
V_18 -> V_216 ( V_1 ) ;
#endif
F_211 ( V_106 ) [ V_5 ] = V_5 + 1 ;
}
F_211 ( V_106 ) [ V_5 - 1 ] = V_261 ;
}
static void F_213 ( struct V_17 * V_18 , T_5 V_19 )
{
if ( V_255 ) {
if ( V_19 & V_64 )
F_12 ( ! ( V_18 -> V_206 & V_64 ) ) ;
else
F_12 ( V_18 -> V_206 & V_64 ) ;
}
}
static void * F_214 ( struct V_17 * V_18 , struct V_27 * V_106 ,
int V_117 )
{
void * V_1 = F_23 ( V_18 , V_106 , V_106 -> free ) ;
V_68 V_262 ;
V_106 -> V_203 ++ ;
V_262 = F_211 ( V_106 ) [ V_106 -> free ] ;
#if V_61
F_211 ( V_106 ) [ V_106 -> free ] = V_263 ;
F_215 ( V_106 -> V_117 != V_117 ) ;
#endif
V_106 -> free = V_262 ;
return V_1 ;
}
static void F_216 ( struct V_17 * V_18 , struct V_27 * V_106 ,
void * V_1 , int V_117 )
{
unsigned int V_237 = F_24 ( V_18 , V_106 , V_1 ) ;
#if V_61
F_215 ( V_106 -> V_117 != V_117 ) ;
if ( F_211 ( V_106 ) [ V_237 ] + 1 <= V_77 + 1 ) {
F_45 ( V_80 L_27
L_28 , V_18 -> V_81 , V_1 ) ;
F_134 () ;
}
#endif
F_211 ( V_106 ) [ V_237 ] = V_106 -> free ;
V_106 -> free = V_237 ;
V_106 -> V_203 -- ;
}
static void F_217 ( struct V_17 * V_29 , struct V_27 * V_27 ,
void * V_217 )
{
int V_204 ;
struct V_24 * V_24 ;
V_24 = F_68 ( V_217 ) ;
V_204 = 1 ;
if ( F_101 ( ! F_218 ( V_24 ) ) )
V_204 <<= V_29 -> V_69 ;
do {
V_24 -> V_25 = V_29 ;
V_24 -> V_28 = V_27 ;
V_24 ++ ;
} while ( -- V_204 );
}
static int F_219 ( struct V_17 * V_18 ,
T_5 V_19 , int V_117 , void * V_1 )
{
struct V_27 * V_106 ;
T_2 V_32 ;
T_5 V_260 ;
struct V_6 * V_40 ;
F_12 ( V_19 & V_264 ) ;
V_260 = V_19 & ( V_265 | V_266 ) ;
F_188 () ;
V_40 = V_18 -> V_42 [ V_117 ] ;
F_94 ( & V_40 -> V_14 ) ;
V_32 = V_40 -> V_13 ;
V_40 -> V_13 ++ ;
if ( V_40 -> V_13 >= V_18 -> V_183 )
V_40 -> V_13 = 0 ;
F_96 ( & V_40 -> V_14 ) ;
V_32 *= V_18 -> V_179 ;
if ( V_260 & V_267 )
F_220 () ;
F_213 ( V_18 , V_19 ) ;
if ( ! V_1 )
V_1 = F_140 ( V_18 , V_260 , V_117 ) ;
if ( ! V_1 )
goto V_268;
V_106 = F_208 ( V_18 , V_1 , V_32 ,
V_260 & ~ V_265 , V_117 ) ;
if ( ! V_106 )
goto V_269;
F_217 ( V_18 , V_106 , V_1 ) ;
F_212 ( V_18 , V_106 ) ;
if ( V_260 & V_267 )
F_221 () ;
F_188 () ;
F_94 ( & V_40 -> V_14 ) ;
F_222 ( & V_106 -> V_163 , & ( V_40 -> V_10 ) ) ;
F_223 ( V_18 ) ;
V_40 -> V_15 += V_18 -> V_72 ;
F_96 ( & V_40 -> V_14 ) ;
return 1 ;
V_269:
F_152 ( V_18 , V_1 ) ;
V_268:
if ( V_260 & V_267 )
F_221 () ;
return 0 ;
}
static void F_224 ( const void * V_1 )
{
if ( ! F_225 ( V_1 ) ) {
F_45 ( V_80 L_29 ,
( unsigned long ) V_1 ) ;
F_134 () ;
}
}
static inline void F_226 ( struct V_17 * V_29 , void * V_26 )
{
unsigned long long V_270 , V_271 ;
V_270 = * F_11 ( V_29 , V_26 ) ;
V_271 = * F_13 ( V_29 , V_26 ) ;
if ( V_270 == V_272 && V_271 == V_272 )
return;
if ( V_270 == V_239 && V_271 == V_239 )
F_174 ( V_29 , L_30 ) ;
else
F_174 ( V_29 , L_31 ) ;
F_45 ( V_80 L_32 ,
V_26 , V_270 , V_271 ) ;
}
static void * F_227 ( struct V_17 * V_18 , void * V_1 ,
void * V_226 )
{
struct V_24 * V_24 ;
unsigned int V_237 ;
struct V_27 * V_106 ;
F_12 ( F_19 ( V_1 ) != V_18 ) ;
V_1 -= F_10 ( V_18 ) ;
F_224 ( V_1 ) ;
V_24 = F_20 ( V_1 ) ;
V_106 = V_24 -> V_28 ;
if ( V_18 -> V_19 & V_20 ) {
F_226 ( V_18 , V_1 ) ;
* F_11 ( V_18 , V_1 ) = V_239 ;
* F_13 ( V_18 , V_1 ) = V_239 ;
}
if ( V_18 -> V_19 & V_21 )
* F_14 ( V_18 , V_1 ) = V_226 ;
V_237 = F_24 ( V_18 , V_106 , V_1 ) ;
F_12 ( V_237 >= V_18 -> V_72 ) ;
F_12 ( V_1 != F_23 ( V_18 , V_106 , V_237 ) ) ;
#ifdef F_228
F_211 ( V_106 ) [ V_237 ] = V_263 ;
#endif
if ( V_18 -> V_19 & V_238 ) {
#ifdef F_172
if ( ( V_18 -> V_3 % V_75 ) == 0 && F_33 ( V_18 ) ) {
F_160 ( V_18 , V_1 , ( unsigned long ) V_226 ) ;
F_173 ( F_68 ( V_1 ) ,
V_18 -> V_3 / V_75 , 0 ) ;
} else {
F_163 ( V_18 , V_1 , V_233 ) ;
}
#else
F_163 ( V_18 , V_1 , V_233 ) ;
#endif
}
return V_1 ;
}
static void F_229 ( struct V_17 * V_18 , struct V_27 * V_106 )
{
V_68 V_5 ;
int V_98 = 0 ;
for ( V_5 = V_106 -> free ; V_5 != V_261 ; V_5 = F_211 ( V_106 ) [ V_5 ] ) {
V_98 ++ ;
if ( V_98 > V_18 -> V_72 || V_5 >= V_18 -> V_72 )
goto V_130;
}
if ( V_98 != V_18 -> V_72 - V_106 -> V_203 ) {
V_130:
F_45 ( V_80 L_33
L_34 ,
V_18 -> V_81 , V_18 -> V_72 , V_106 , V_106 -> V_203 ,
F_170 () ) ;
F_165 ( V_80 , L_6 , V_273 , 16 , 1 , V_106 ,
sizeof( * V_106 ) + V_18 -> V_72 * sizeof( V_68 ) ,
1 ) ;
F_134 () ;
}
}
static void * F_230 ( struct V_17 * V_18 , T_5 V_19 ,
bool V_110 )
{
int V_99 ;
struct V_6 * V_40 ;
struct V_38 * V_107 ;
int V_45 ;
F_188 () ;
V_45 = F_71 () ;
if ( F_39 ( V_110 ) )
goto V_274;
V_275:
V_107 = F_35 ( V_18 ) ;
V_99 = V_107 -> V_99 ;
if ( ! V_107 -> V_105 && V_99 > V_276 ) {
V_99 = V_276 ;
}
V_40 = V_18 -> V_42 [ V_45 ] ;
F_12 ( V_107 -> V_103 > 0 || ! V_40 ) ;
F_94 ( & V_40 -> V_14 ) ;
if ( V_40 -> V_11 && F_83 ( V_107 , V_40 -> V_11 , V_99 ) ) {
V_40 -> V_11 -> V_105 = 1 ;
goto V_277;
}
while ( V_99 > 0 ) {
struct V_257 * V_111 ;
struct V_27 * V_106 ;
V_111 = V_40 -> V_9 . V_262 ;
if ( V_111 == & V_40 -> V_9 ) {
V_40 -> V_16 = 1 ;
V_111 = V_40 -> V_10 . V_262 ;
if ( V_111 == & V_40 -> V_10 )
goto V_278;
}
V_106 = F_199 ( V_111 , struct V_27 , V_163 ) ;
F_229 ( V_18 , V_106 ) ;
F_191 ( V_18 ) ;
F_12 ( V_106 -> V_203 >= V_18 -> V_72 ) ;
while ( V_106 -> V_203 < V_18 -> V_72 && V_99 -- ) {
F_231 ( V_18 ) ;
F_232 ( V_18 ) ;
F_233 ( V_18 ) ;
F_82 ( V_18 , V_107 , F_214 ( V_18 , V_106 ,
V_45 ) ) ;
}
F_229 ( V_18 , V_106 ) ;
F_200 ( & V_106 -> V_163 ) ;
if ( V_106 -> free == V_261 )
F_126 ( & V_106 -> V_163 , & V_40 -> V_8 ) ;
else
F_126 ( & V_106 -> V_163 , & V_40 -> V_9 ) ;
}
V_278:
V_40 -> V_15 -= V_107 -> V_103 ;
V_277:
F_96 ( & V_40 -> V_14 ) ;
if ( F_39 ( ! V_107 -> V_103 ) ) {
int T_3 ;
V_274:
T_3 = F_219 ( V_18 , V_19 | V_279 , V_45 , NULL ) ;
V_107 = F_35 ( V_18 ) ;
V_45 = F_71 () ;
if ( ! T_3 && ( V_107 -> V_103 == 0 || V_110 ) )
return NULL ;
if ( ! V_107 -> V_103 )
goto V_275;
}
V_107 -> V_105 = 1 ;
return F_79 ( V_18 , V_107 , V_19 , V_110 ) ;
}
static inline void F_234 ( struct V_17 * V_18 ,
T_5 V_19 )
{
F_235 ( V_19 & V_267 ) ;
#if V_61
F_213 ( V_18 , V_19 ) ;
#endif
}
static void * F_236 ( struct V_17 * V_18 ,
T_5 V_19 , void * V_1 , void * V_226 )
{
if ( ! V_1 )
return V_1 ;
if ( V_18 -> V_19 & V_238 ) {
#ifdef F_172
if ( ( V_18 -> V_3 % V_75 ) == 0 && F_33 ( V_18 ) )
F_173 ( F_68 ( V_1 ) ,
V_18 -> V_3 / V_75 , 1 ) ;
else
F_169 ( V_18 , V_1 ) ;
#else
F_169 ( V_18 , V_1 ) ;
#endif
F_163 ( V_18 , V_1 , V_280 ) ;
}
if ( V_18 -> V_19 & V_21 )
* F_14 ( V_18 , V_1 ) = V_226 ;
if ( V_18 -> V_19 & V_20 ) {
if ( * F_11 ( V_18 , V_1 ) != V_239 ||
* F_13 ( V_18 , V_1 ) != V_239 ) {
F_174 ( V_18 , L_35
L_36 ) ;
F_45 ( V_80
L_37 ,
V_1 , * F_11 ( V_18 , V_1 ) ,
* F_13 ( V_18 , V_1 ) ) ;
}
* F_11 ( V_18 , V_1 ) = V_272 ;
* F_13 ( V_18 , V_1 ) = V_272 ;
}
#ifdef F_228
{
struct V_27 * V_106 ;
unsigned V_237 ;
V_106 = F_20 ( V_1 ) -> V_28 ;
V_237 = ( unsigned ) ( V_1 - V_106 -> V_31 ) / V_18 -> V_3 ;
F_211 ( V_106 ) [ V_237 ] = V_281 ;
}
#endif
V_1 += F_10 ( V_18 ) ;
if ( V_18 -> V_216 && V_18 -> V_19 & V_238 )
V_18 -> V_216 ( V_1 ) ;
if ( V_253 &&
( ( unsigned long ) V_1 & ( V_253 - 1 ) ) ) {
F_45 ( V_80 L_38 ,
V_1 , ( int ) V_253 ) ;
}
return V_1 ;
}
static bool F_237 ( struct V_17 * V_18 , T_5 V_19 )
{
if ( V_18 == & V_173 )
return false ;
return F_238 ( V_18 -> V_182 , V_19 , V_18 -> V_19 ) ;
}
static inline void * F_239 ( struct V_17 * V_18 , T_5 V_19 )
{
void * V_1 ;
struct V_38 * V_107 ;
bool V_110 = false ;
F_188 () ;
V_107 = F_35 ( V_18 ) ;
if ( F_101 ( V_107 -> V_103 ) ) {
V_107 -> V_105 = 1 ;
V_1 = F_79 ( V_18 , V_107 , V_19 , false ) ;
if ( V_1 ) {
F_240 ( V_18 ) ;
goto V_109;
}
V_110 = true ;
}
F_241 ( V_18 ) ;
V_1 = F_230 ( V_18 , V_19 , V_110 ) ;
V_107 = F_35 ( V_18 ) ;
V_109:
if ( V_1 )
F_242 ( & V_107 -> V_111 [ V_107 -> V_103 ] ) ;
return V_1 ;
}
static void * F_88 ( struct V_17 * V_18 , T_5 V_19 )
{
int V_282 , V_283 ;
if ( F_203 () || ( V_19 & V_284 ) )
return NULL ;
V_282 = V_283 = F_71 () ;
if ( F_243 () && ( V_18 -> V_19 & V_285 ) )
V_282 = F_244 () ;
else if ( V_219 -> V_286 )
V_282 = F_245 () ;
if ( V_282 != V_283 )
return F_89 ( V_18 , V_19 , V_282 ) ;
return NULL ;
}
static void * F_246 ( struct V_17 * V_29 , T_5 V_19 )
{
struct V_287 * V_287 ;
T_5 V_260 ;
struct V_288 * V_289 ;
struct V_290 * V_290 ;
enum V_291 V_292 = F_247 ( V_19 ) ;
void * V_26 = NULL ;
int V_155 ;
unsigned int V_293 ;
if ( V_19 & V_284 )
return NULL ;
V_260 = V_19 & ( V_265 | V_266 ) ;
V_294:
V_293 = F_248 () ;
V_287 = F_249 ( F_245 () , V_19 ) ;
V_275:
F_250 (zone, z, zonelist, high_zoneidx) {
V_155 = F_251 ( V_290 ) ;
if ( F_252 ( V_290 , V_19 ) &&
V_29 -> V_42 [ V_155 ] &&
V_29 -> V_42 [ V_155 ] -> V_15 ) {
V_26 = F_89 ( V_29 ,
V_19 | V_279 , V_155 ) ;
if ( V_26 )
break;
}
}
if ( ! V_26 ) {
if ( V_260 & V_267 )
F_220 () ;
F_213 ( V_29 , V_19 ) ;
V_26 = F_140 ( V_29 , V_260 , F_71 () ) ;
if ( V_260 & V_267 )
F_221 () ;
if ( V_26 ) {
V_155 = F_253 ( F_68 ( V_26 ) ) ;
if ( F_219 ( V_29 , V_19 , V_155 , V_26 ) ) {
V_26 = F_89 ( V_29 ,
V_19 | V_279 , V_155 ) ;
if ( ! V_26 )
goto V_275;
} else {
V_26 = NULL ;
}
}
}
if ( F_39 ( ! F_254 ( V_293 ) && ! V_26 ) )
goto V_294;
return V_26 ;
}
static void * F_89 ( struct V_17 * V_18 , T_5 V_19 ,
int V_117 )
{
struct V_257 * V_111 ;
struct V_27 * V_106 ;
struct V_6 * V_40 ;
void * V_26 ;
int T_3 ;
V_40 = V_18 -> V_42 [ V_117 ] ;
F_12 ( ! V_40 ) ;
V_275:
F_188 () ;
F_94 ( & V_40 -> V_14 ) ;
V_111 = V_40 -> V_9 . V_262 ;
if ( V_111 == & V_40 -> V_9 ) {
V_40 -> V_16 = 1 ;
V_111 = V_40 -> V_10 . V_262 ;
if ( V_111 == & V_40 -> V_10 )
goto V_278;
}
V_106 = F_199 ( V_111 , struct V_27 , V_163 ) ;
F_194 ( V_18 , V_117 ) ;
F_229 ( V_18 , V_106 ) ;
F_255 ( V_18 ) ;
F_232 ( V_18 ) ;
F_233 ( V_18 ) ;
F_12 ( V_106 -> V_203 == V_18 -> V_72 ) ;
V_26 = F_214 ( V_18 , V_106 , V_117 ) ;
F_229 ( V_18 , V_106 ) ;
V_40 -> V_15 -- ;
F_200 ( & V_106 -> V_163 ) ;
if ( V_106 -> free == V_261 )
F_126 ( & V_106 -> V_163 , & V_40 -> V_8 ) ;
else
F_126 ( & V_106 -> V_163 , & V_40 -> V_9 ) ;
F_96 ( & V_40 -> V_14 ) ;
goto V_295;
V_278:
F_96 ( & V_40 -> V_14 ) ;
T_3 = F_219 ( V_18 , V_19 | V_279 , V_117 , NULL ) ;
if ( T_3 )
goto V_275;
return F_246 ( V_18 , V_19 ) ;
V_295:
return V_26 ;
}
static T_1 void *
F_256 ( struct V_17 * V_18 , T_5 V_19 , int V_117 ,
void * V_226 )
{
unsigned long V_296 ;
void * V_164 ;
int F_245 = F_71 () ;
V_19 &= V_297 ;
F_257 ( V_19 ) ;
if ( F_237 ( V_18 , V_19 ) )
return NULL ;
F_234 ( V_18 , V_19 ) ;
F_258 ( V_296 ) ;
if ( V_117 == V_298 )
V_117 = F_245 ;
if ( F_39 ( ! V_18 -> V_42 [ V_117 ] ) ) {
V_164 = F_246 ( V_18 , V_19 ) ;
goto V_109;
}
if ( V_117 == F_245 ) {
V_164 = F_239 ( V_18 , V_19 ) ;
if ( V_164 )
goto V_109;
}
V_164 = F_89 ( V_18 , V_19 , V_117 ) ;
V_109:
F_259 ( V_296 ) ;
V_164 = F_236 ( V_18 , V_19 , V_164 , V_226 ) ;
F_260 ( V_164 , V_18 -> V_182 , 1 , V_18 -> V_19 ,
V_19 ) ;
if ( F_101 ( V_164 ) )
F_261 ( V_18 , V_19 , V_164 , V_18 -> V_182 ) ;
if ( F_39 ( ( V_19 & V_299 ) && V_164 ) )
memset ( V_164 , 0 , V_18 -> V_182 ) ;
return V_164 ;
}
static T_1 void *
F_262 ( struct V_17 * V_29 , T_5 V_19 )
{
void * V_1 ;
if ( F_39 ( V_219 -> V_19 & ( V_300 | V_301 ) ) ) {
V_1 = F_88 ( V_29 , V_19 ) ;
if ( V_1 )
goto V_109;
}
V_1 = F_239 ( V_29 , V_19 ) ;
if ( ! V_1 )
V_1 = F_89 ( V_29 , V_19 , F_71 () ) ;
V_109:
return V_1 ;
}
static T_1 void *
F_262 ( struct V_17 * V_18 , T_5 V_19 )
{
return F_239 ( V_18 , V_19 ) ;
}
static T_1 void *
F_263 ( struct V_17 * V_18 , T_5 V_19 , void * V_226 )
{
unsigned long V_296 ;
void * V_1 ;
V_19 &= V_297 ;
F_257 ( V_19 ) ;
if ( F_237 ( V_18 , V_19 ) )
return NULL ;
F_234 ( V_18 , V_19 ) ;
F_258 ( V_296 ) ;
V_1 = F_262 ( V_18 , V_19 ) ;
F_259 ( V_296 ) ;
V_1 = F_236 ( V_18 , V_19 , V_1 , V_226 ) ;
F_260 ( V_1 , V_18 -> V_182 , 1 , V_18 -> V_19 ,
V_19 ) ;
F_264 ( V_1 ) ;
if ( F_101 ( V_1 ) )
F_261 ( V_18 , V_19 , V_1 , V_18 -> V_182 ) ;
if ( F_39 ( ( V_19 & V_299 ) && V_1 ) )
memset ( V_1 , 0 , V_18 -> V_182 ) ;
return V_1 ;
}
static void F_95 ( struct V_17 * V_18 , void * * V_302 , int V_303 ,
int V_45 )
{
int V_5 ;
struct V_6 * V_40 ;
for ( V_5 = 0 ; V_5 < V_303 ; V_5 ++ ) {
void * V_1 ;
struct V_27 * V_106 ;
F_3 ( & V_302 [ V_5 ] ) ;
V_1 = V_302 [ V_5 ] ;
V_106 = F_21 ( V_1 ) ;
V_40 = V_18 -> V_42 [ V_45 ] ;
F_200 ( & V_106 -> V_163 ) ;
F_194 ( V_18 , V_45 ) ;
F_229 ( V_18 , V_106 ) ;
F_216 ( V_18 , V_106 , V_1 , V_45 ) ;
F_265 ( V_18 ) ;
V_40 -> V_15 ++ ;
F_229 ( V_18 , V_106 ) ;
if ( V_106 -> V_203 == 0 ) {
if ( V_40 -> V_15 > V_40 -> V_125 ) {
V_40 -> V_15 -= V_18 -> V_72 ;
F_175 ( V_18 , V_106 ) ;
} else {
F_126 ( & V_106 -> V_163 , & V_40 -> V_10 ) ;
}
} else {
F_222 ( & V_106 -> V_163 , & V_40 -> V_9 ) ;
}
}
}
static void F_266 ( struct V_17 * V_18 , struct V_38 * V_107 )
{
int V_99 ;
struct V_6 * V_40 ;
int V_45 = F_71 () ;
V_99 = V_107 -> V_99 ;
#if V_61
F_12 ( ! V_99 || V_99 > V_107 -> V_103 ) ;
#endif
F_188 () ;
V_40 = V_18 -> V_42 [ V_45 ] ;
F_94 ( & V_40 -> V_14 ) ;
if ( V_40 -> V_11 ) {
struct V_38 * V_304 = V_40 -> V_11 ;
int V_114 = V_304 -> V_104 - V_304 -> V_103 ;
if ( V_114 ) {
if ( V_99 > V_114 )
V_99 = V_114 ;
memcpy ( & ( V_304 -> V_111 [ V_304 -> V_103 ] ) ,
V_107 -> V_111 , sizeof( void * ) * V_99 ) ;
V_304 -> V_103 += V_99 ;
goto V_305;
}
}
F_95 ( V_18 , V_107 -> V_111 , V_99 , V_45 ) ;
V_305:
#if V_306
{
int V_5 = 0 ;
struct V_257 * V_258 ;
V_258 = V_40 -> V_10 . V_262 ;
while ( V_258 != & ( V_40 -> V_10 ) ) {
struct V_27 * V_106 ;
V_106 = F_199 ( V_258 , struct V_27 , V_163 ) ;
F_12 ( V_106 -> V_203 ) ;
V_5 ++ ;
V_258 = V_258 -> V_262 ;
}
F_267 ( V_18 , V_5 ) ;
}
#endif
F_96 ( & V_40 -> V_14 ) ;
V_107 -> V_103 -= V_99 ;
memmove ( V_107 -> V_111 , & ( V_107 -> V_111 [ V_99 ] ) , sizeof( void * ) * V_107 -> V_103 ) ;
}
static inline void F_268 ( struct V_17 * V_18 , void * V_1 ,
void * V_226 )
{
struct V_38 * V_107 = F_35 ( V_18 ) ;
F_188 () ;
F_269 ( V_1 , V_18 -> V_19 ) ;
V_1 = F_227 ( V_18 , V_1 , V_226 ) ;
F_270 ( V_18 , V_1 , V_18 -> V_182 ) ;
if ( V_307 > 1 && F_87 ( V_18 , V_1 ) )
return;
if ( F_101 ( V_107 -> V_103 < V_107 -> V_104 ) ) {
F_271 ( V_18 ) ;
} else {
F_272 ( V_18 ) ;
F_266 ( V_18 , V_107 ) ;
}
F_82 ( V_18 , V_107 , V_1 ) ;
}
void * F_273 ( struct V_17 * V_18 , T_5 V_19 )
{
void * V_149 = F_263 ( V_18 , V_19 , F_274 ( 0 ) ) ;
F_275 ( V_308 , V_149 ,
V_18 -> V_182 , V_18 -> V_3 , V_19 ) ;
return V_149 ;
}
void *
F_276 ( T_2 V_3 , struct V_17 * V_18 , T_5 V_19 )
{
void * V_149 ;
V_149 = F_263 ( V_18 , V_19 , F_274 ( 0 ) ) ;
F_277 ( V_308 , V_149 ,
V_3 , F_15 ( V_18 ) , V_19 ) ;
return V_149 ;
}
void * F_209 ( struct V_17 * V_18 , T_5 V_19 , int V_117 )
{
void * V_149 = F_256 ( V_18 , V_19 , V_117 ,
F_274 ( 0 ) ) ;
F_278 ( V_308 , V_149 ,
V_18 -> V_182 , V_18 -> V_3 ,
V_19 , V_117 ) ;
return V_149 ;
}
void * F_279 ( T_2 V_3 ,
struct V_17 * V_18 ,
T_5 V_19 ,
int V_117 )
{
void * V_149 ;
V_149 = F_256 ( V_18 , V_19 , V_117 ,
F_274 ( 0 ) ) ;
F_280 ( V_308 , V_149 ,
V_3 , F_15 ( V_18 ) ,
V_19 , V_117 ) ;
return V_149 ;
}
static T_1 void *
F_281 ( T_2 V_3 , T_5 V_19 , int V_45 , void * V_226 )
{
struct V_17 * V_18 ;
V_18 = F_40 ( V_3 , V_19 ) ;
if ( F_39 ( F_186 ( V_18 ) ) )
return V_18 ;
return F_279 ( V_3 , V_18 , V_19 , V_45 ) ;
}
void * F_282 ( T_2 V_3 , T_5 V_19 , int V_45 )
{
return F_281 ( V_3 , V_19 , V_45 ,
F_274 ( 0 ) ) ;
}
void * F_283 ( T_2 V_3 , T_5 V_19 ,
int V_45 , unsigned long V_226 )
{
return F_281 ( V_3 , V_19 , V_45 , ( void * ) V_226 ) ;
}
void * F_282 ( T_2 V_3 , T_5 V_19 , int V_45 )
{
return F_281 ( V_3 , V_19 , V_45 , NULL ) ;
}
static T_1 void * F_284 ( T_2 V_3 , T_5 V_19 ,
void * V_226 )
{
struct V_17 * V_18 ;
void * V_149 ;
V_18 = F_37 ( V_3 , V_19 ) ;
if ( F_39 ( F_186 ( V_18 ) ) )
return V_18 ;
V_149 = F_263 ( V_18 , V_19 , V_226 ) ;
F_277 ( ( unsigned long ) V_226 , V_149 ,
V_3 , V_18 -> V_3 , V_19 ) ;
return V_149 ;
}
void * F_285 ( T_2 V_3 , T_5 V_19 )
{
return F_284 ( V_3 , V_19 , F_274 ( 0 ) ) ;
}
void * F_286 ( T_2 V_3 , T_5 V_19 , unsigned long V_226 )
{
return F_284 ( V_3 , V_19 , ( void * ) V_226 ) ;
}
void * F_285 ( T_2 V_3 , T_5 V_19 )
{
return F_284 ( V_3 , V_19 , NULL ) ;
}
void F_159 ( struct V_17 * V_18 , void * V_1 )
{
unsigned long V_19 ;
F_258 ( V_19 ) ;
F_287 ( V_1 , V_18 -> V_182 ) ;
if ( ! ( V_18 -> V_19 & V_131 ) )
F_288 ( V_1 , V_18 -> V_182 ) ;
F_268 ( V_18 , V_1 , F_274 ( 0 ) ) ;
F_259 ( V_19 ) ;
F_289 ( V_308 , V_1 ) ;
}
void F_92 ( const void * V_1 )
{
struct V_17 * V_309 ;
unsigned long V_19 ;
F_290 ( V_308 , V_1 ) ;
if ( F_39 ( F_186 ( V_1 ) ) )
return;
F_258 ( V_19 ) ;
F_224 ( V_1 ) ;
V_309 = F_19 ( V_1 ) ;
F_287 ( V_1 , V_309 -> V_182 ) ;
F_288 ( V_1 , V_309 -> V_182 ) ;
F_268 ( V_309 , ( void * ) V_1 , F_274 ( 0 ) ) ;
F_259 ( V_19 ) ;
}
unsigned int F_291 ( struct V_17 * V_18 )
{
return V_18 -> V_182 ;
}
static int F_292 ( struct V_17 * V_18 , T_5 V_100 )
{
int V_45 ;
struct V_6 * V_40 ;
struct V_38 * V_310 ;
struct V_38 * * V_311 = NULL ;
F_31 (node) {
if ( V_82 ) {
V_311 = F_85 ( V_45 , V_18 -> V_104 , V_100 ) ;
if ( ! V_311 )
goto V_312;
}
V_310 = NULL ;
if ( V_18 -> V_11 ) {
V_310 = F_64 ( V_45 ,
V_18 -> V_11 * V_18 -> V_99 ,
0xbaadf00d , V_100 ) ;
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
F_95 ( V_18 , V_11 -> V_111 ,
V_11 -> V_103 , V_45 ) ;
V_40 -> V_11 = V_310 ;
if ( ! V_40 -> V_12 ) {
V_40 -> V_12 = V_311 ;
V_311 = NULL ;
}
V_40 -> V_125 = ( 1 + F_106 ( V_45 ) ) *
V_18 -> V_99 + V_18 -> V_72 ;
F_99 ( & V_40 -> V_14 ) ;
F_92 ( V_11 ) ;
F_86 ( V_311 ) ;
continue;
}
V_40 = F_65 ( sizeof( struct V_6 ) , V_100 , V_45 ) ;
if ( ! V_40 ) {
F_86 ( V_311 ) ;
F_92 ( V_310 ) ;
goto V_312;
}
F_7 ( V_40 ) ;
V_40 -> V_122 = V_123 + V_124 +
( ( unsigned long ) V_18 ) % V_124 ;
V_40 -> V_11 = V_310 ;
V_40 -> V_12 = V_311 ;
V_40 -> V_125 = ( 1 + F_106 ( V_45 ) ) *
V_18 -> V_99 + V_18 -> V_72 ;
V_18 -> V_42 [ V_45 ] = V_40 ;
}
return 0 ;
V_312:
if ( ! V_18 -> V_163 . V_262 ) {
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
return - V_121 ;
}
static void F_293 ( void * V_313 )
{
struct V_314 * V_315 = V_313 ;
struct V_38 * V_316 ;
F_188 () ;
V_316 = F_35 ( V_315 -> V_18 ) ;
V_315 -> V_18 -> V_58 [ F_36 () ] = V_315 -> V_315 [ F_36 () ] ;
V_315 -> V_315 [ F_36 () ] = V_316 ;
}
static int F_294 ( struct V_17 * V_18 , int V_104 ,
int V_99 , int V_11 , T_5 V_100 )
{
struct V_314 * V_315 ;
int V_5 ;
V_315 = F_295 ( sizeof( * V_315 ) + V_181 * sizeof( struct V_38 * ) ,
V_100 ) ;
if ( ! V_315 )
return - V_121 ;
F_138 (i) {
V_315 -> V_315 [ V_5 ] = F_64 ( F_53 ( V_5 ) , V_104 ,
V_99 , V_100 ) ;
if ( ! V_315 -> V_315 [ V_5 ] ) {
for ( V_5 -- ; V_5 >= 0 ; V_5 -- )
F_92 ( V_315 -> V_315 [ V_5 ] ) ;
F_92 ( V_315 ) ;
return - V_121 ;
}
}
V_315 -> V_18 = V_18 ;
F_197 ( F_293 , ( void * ) V_315 , 1 ) ;
F_190 () ;
V_18 -> V_99 = V_99 ;
V_18 -> V_104 = V_104 ;
V_18 -> V_11 = V_11 ;
F_138 (i) {
struct V_38 * V_317 = V_315 -> V_315 [ V_5 ] ;
if ( ! V_317 )
continue;
F_105 ( & V_18 -> V_42 [ F_53 ( V_5 ) ] -> V_14 ) ;
F_95 ( V_18 , V_317 -> V_111 , V_317 -> V_103 , F_53 ( V_5 ) ) ;
F_99 ( & V_18 -> V_42 [ F_53 ( V_5 ) ] -> V_14 ) ;
F_92 ( V_317 ) ;
}
F_92 ( V_315 ) ;
return F_292 ( V_18 , V_100 ) ;
}
static int F_133 ( struct V_17 * V_18 , T_5 V_100 )
{
int V_129 ;
int V_104 , V_11 ;
if ( V_18 -> V_3 > 131072 )
V_104 = 1 ;
else if ( V_18 -> V_3 > V_75 )
V_104 = 8 ;
else if ( V_18 -> V_3 > 1024 )
V_104 = 24 ;
else if ( V_18 -> V_3 > 256 )
V_104 = 54 ;
else
V_104 = 120 ;
V_11 = 0 ;
if ( V_18 -> V_3 <= V_75 && F_296 () > 1 )
V_11 = 8 ;
#if V_61
if ( V_104 > 32 )
V_104 = 32 ;
#endif
V_129 = F_294 ( V_18 , V_104 , ( V_104 + 1 ) / 2 , V_11 , V_100 ) ;
if ( V_129 )
F_45 ( V_80 L_39 ,
V_18 -> V_81 , - V_129 ) ;
return V_129 ;
}
static void F_198 ( struct V_17 * V_18 , struct V_6 * V_40 ,
struct V_38 * V_107 , int V_318 , int V_45 )
{
int V_256 ;
if ( ! V_107 || ! V_107 -> V_103 )
return;
if ( V_107 -> V_105 && ! V_318 ) {
V_107 -> V_105 = 0 ;
} else {
F_105 ( & V_40 -> V_14 ) ;
if ( V_107 -> V_103 ) {
V_256 = V_318 ? V_107 -> V_103 : ( V_107 -> V_104 + 4 ) / 5 ;
if ( V_256 > V_107 -> V_103 )
V_256 = ( V_107 -> V_103 + 1 ) / 2 ;
F_95 ( V_18 , V_107 -> V_111 , V_256 , V_45 ) ;
V_107 -> V_103 -= V_256 ;
memmove ( V_107 -> V_111 , & ( V_107 -> V_111 [ V_256 ] ) ,
sizeof( void * ) * V_107 -> V_103 ) ;
}
F_99 ( & V_40 -> V_14 ) ;
}
}
static void V_96 ( struct V_319 * V_320 )
{
struct V_17 * V_321 ;
struct V_6 * V_40 ;
int V_45 = F_71 () ;
struct V_91 * V_94 = F_297 ( V_320 ) ;
if ( ! F_298 ( & V_138 ) )
goto V_109;
F_73 (searchp, &slab_caches, list) {
F_190 () ;
V_40 = V_321 -> V_42 [ V_45 ] ;
F_97 ( V_321 , V_40 ) ;
F_198 ( V_321 , V_40 , F_35 ( V_321 ) , 0 , V_45 ) ;
if ( F_299 ( V_40 -> V_122 , V_123 ) )
goto V_262;
V_40 -> V_122 = V_123 + V_124 ;
F_198 ( V_321 , V_40 , V_40 -> V_11 , 0 , V_45 ) ;
if ( V_40 -> V_16 )
V_40 -> V_16 = 0 ;
else {
int V_322 ;
V_322 = F_110 ( V_321 , V_40 , ( V_40 -> V_125 +
5 * V_321 -> V_72 - 1 ) / ( 5 * V_321 -> V_72 ) ) ;
F_300 ( V_321 , V_322 ) ;
}
V_262:
F_301 () ;
}
F_190 () ;
F_115 ( & V_138 ) ;
F_56 () ;
V_109:
F_302 ( V_94 , F_303 ( V_323 ) ) ;
}
static void F_304 ( struct V_324 * V_325 )
{
#if V_306
F_305 ( V_325 , L_40 ) ;
#else
F_305 ( V_325 , L_41 ) ;
#endif
F_305 ( V_325 , L_42
L_43 ) ;
F_305 ( V_325 , L_44 ) ;
F_305 ( V_325 , L_45 ) ;
#if V_306
F_305 ( V_325 , L_46
L_47 ) ;
F_305 ( V_325 , L_48 ) ;
#endif
F_306 ( V_325 , '\n' ) ;
}
static void * F_307 ( struct V_324 * V_325 , T_11 * V_326 )
{
T_11 V_327 = * V_326 ;
F_114 ( & V_138 ) ;
if ( ! V_327 )
F_304 ( V_325 ) ;
return F_308 ( & V_178 , * V_326 ) ;
}
static void * F_309 ( struct V_324 * V_325 , void * V_258 , T_11 * V_326 )
{
return F_310 ( V_258 , & V_178 , V_326 ) ;
}
static void F_311 ( struct V_324 * V_325 , void * V_258 )
{
F_115 ( & V_138 ) ;
}
static int F_312 ( struct V_324 * V_325 , void * V_258 )
{
struct V_17 * V_18 = F_199 ( V_258 , struct V_17 , V_163 ) ;
struct V_27 * V_106 ;
unsigned long V_199 ;
unsigned long V_200 ;
unsigned long V_201 = 0 ;
unsigned long V_202 , V_15 = 0 , V_328 = 0 ;
const char * V_81 ;
char * error = NULL ;
int V_45 ;
struct V_6 * V_40 ;
V_199 = 0 ;
V_202 = 0 ;
F_31 (node) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_190 () ;
F_105 ( & V_40 -> V_14 ) ;
F_73 (slabp, &l3->slabs_full, list) {
if ( V_106 -> V_203 != V_18 -> V_72 && ! error )
error = L_49 ;
V_199 += V_18 -> V_72 ;
V_201 ++ ;
}
F_73 (slabp, &l3->slabs_partial, list) {
if ( V_106 -> V_203 == V_18 -> V_72 && ! error )
error = L_50 ;
if ( ! V_106 -> V_203 && ! error )
error = L_51 ;
V_199 += V_106 -> V_203 ;
V_201 ++ ;
}
F_73 (slabp, &l3->slabs_free, list) {
if ( V_106 -> V_203 && ! error )
error = L_52 ;
V_202 ++ ;
}
V_15 += V_40 -> V_15 ;
if ( V_40 -> V_11 )
V_328 += V_40 -> V_11 -> V_103 ;
F_99 ( & V_40 -> V_14 ) ;
}
V_202 += V_201 ;
V_200 = V_202 * V_18 -> V_72 ;
if ( V_200 - V_199 != V_15 && ! error )
error = L_53 ;
V_81 = V_18 -> V_81 ;
if ( error )
F_45 ( V_80 L_54 , V_81 , error ) ;
F_313 ( V_325 , L_55 ,
V_81 , V_199 , V_200 , V_18 -> V_3 ,
V_18 -> V_72 , ( 1 << V_18 -> V_69 ) ) ;
F_313 ( V_325 , L_56 ,
V_18 -> V_104 , V_18 -> V_99 , V_18 -> V_11 ) ;
F_313 ( V_325 , L_57 ,
V_201 , V_202 , V_328 ) ;
#if V_306
{
unsigned long V_329 = V_18 -> V_330 ;
unsigned long V_331 = V_18 -> V_332 ;
unsigned long V_333 = V_18 -> V_333 ;
unsigned long V_334 = V_18 -> V_334 ;
unsigned long V_335 = V_18 -> V_335 ;
unsigned long V_336 = V_18 -> V_336 ;
unsigned long V_337 = V_18 -> V_337 ;
unsigned long V_338 = V_18 -> V_338 ;
unsigned long V_339 = V_18 -> V_340 ;
F_313 ( V_325 , L_58
L_59 ,
V_331 , V_329 , V_333 ,
V_334 , V_335 , V_336 , V_337 ,
V_338 , V_339 ) ;
}
{
unsigned long V_341 = F_314 ( & V_18 -> V_341 ) ;
unsigned long V_342 = F_314 ( & V_18 -> V_342 ) ;
unsigned long V_343 = F_314 ( & V_18 -> V_343 ) ;
unsigned long V_344 = F_314 ( & V_18 -> V_344 ) ;
F_313 ( V_325 , L_60 ,
V_341 , V_342 , V_343 , V_344 ) ;
}
#endif
F_306 ( V_325 , '\n' ) ;
return 0 ;
}
static T_12 F_315 ( struct V_345 * V_345 , const char T_13 * V_346 ,
T_2 V_347 , T_11 * V_348 )
{
char V_349 [ V_350 + 1 ] , * V_351 ;
int V_104 , V_99 , V_11 , V_352 ;
struct V_17 * V_18 ;
if ( V_347 > V_350 )
return - V_353 ;
if ( F_316 ( & V_349 , V_346 , V_347 ) )
return - V_354 ;
V_349 [ V_350 ] = '\0' ;
V_351 = strchr ( V_349 , ' ' ) ;
if ( ! V_351 )
return - V_353 ;
* V_351 = '\0' ;
V_351 ++ ;
if ( sscanf ( V_351 , L_61 , & V_104 , & V_99 , & V_11 ) != 3 )
return - V_353 ;
F_114 ( & V_138 ) ;
V_352 = - V_353 ;
F_73 (cachep, &slab_caches, list) {
if ( ! strcmp ( V_18 -> V_81 , V_349 ) ) {
if ( V_104 < 1 || V_99 < 1 ||
V_99 > V_104 || V_11 < 0 ) {
V_352 = 0 ;
} else {
V_352 = F_294 ( V_18 , V_104 ,
V_99 , V_11 ,
V_120 ) ;
}
break;
}
}
F_115 ( & V_138 ) ;
if ( V_352 >= 0 )
V_352 = V_347 ;
return V_352 ;
}
static int F_317 ( struct V_355 * V_355 , struct V_345 * V_345 )
{
return F_318 ( V_345 , & V_356 ) ;
}
static void * F_319 ( struct V_324 * V_325 , T_11 * V_326 )
{
F_114 ( & V_138 ) ;
return F_308 ( & V_178 , * V_326 ) ;
}
static inline int F_320 ( unsigned long * V_327 , unsigned long V_357 )
{
unsigned long * V_258 ;
int V_358 ;
if ( ! V_357 )
return 1 ;
V_358 = V_327 [ 1 ] ;
V_258 = V_327 + 2 ;
while ( V_358 ) {
int V_5 = V_358 / 2 ;
unsigned long * V_37 = V_258 + 2 * V_5 ;
if ( * V_37 == V_357 ) {
V_37 [ 1 ] ++ ;
return 1 ;
}
if ( * V_37 > V_357 ) {
V_358 = V_5 ;
} else {
V_258 = V_37 + 2 ;
V_358 -= V_5 + 1 ;
}
}
if ( ++ V_327 [ 1 ] == V_327 [ 0 ] )
return 0 ;
memmove ( V_258 + 2 , V_258 , V_327 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_258 - ( void * ) V_327 ) ) ;
V_258 [ 0 ] = V_357 ;
V_258 [ 1 ] = 1 ;
return 1 ;
}
static void F_321 ( unsigned long * V_327 , struct V_17 * V_309 , struct V_27 * V_49 )
{
void * V_258 ;
int V_5 ;
if ( V_327 [ 0 ] == V_327 [ 1 ] )
return;
for ( V_5 = 0 , V_258 = V_49 -> V_31 ; V_5 < V_309 -> V_72 ; V_5 ++ , V_258 += V_309 -> V_3 ) {
if ( F_211 ( V_49 ) [ V_5 ] != V_281 )
continue;
if ( ! F_320 ( V_327 , ( unsigned long ) * F_14 ( V_309 , V_258 ) ) )
return;
}
}
static void F_322 ( struct V_324 * V_325 , unsigned long V_359 )
{
#ifdef F_323
unsigned long V_32 , V_3 ;
char V_360 [ V_361 ] , V_81 [ V_362 ] ;
if ( F_324 ( V_359 , & V_3 , & V_32 , V_360 , V_81 ) == 0 ) {
F_313 ( V_325 , L_62 , V_81 , V_32 , V_3 ) ;
if ( V_360 [ 0 ] )
F_313 ( V_325 , L_63 , V_360 ) ;
return;
}
#endif
F_313 ( V_325 , L_64 , ( void * ) V_359 ) ;
}
static int F_325 ( struct V_324 * V_325 , void * V_258 )
{
struct V_17 * V_18 = F_199 ( V_258 , struct V_17 , V_163 ) ;
struct V_27 * V_106 ;
struct V_6 * V_40 ;
const char * V_81 ;
unsigned long * V_327 = V_325 -> V_363 ;
int V_45 ;
int V_5 ;
if ( ! ( V_18 -> V_19 & V_21 ) )
return 0 ;
if ( ! ( V_18 -> V_19 & V_20 ) )
return 0 ;
V_327 [ 1 ] = 0 ;
F_31 (node) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_190 () ;
F_105 ( & V_40 -> V_14 ) ;
F_73 (slabp, &l3->slabs_full, list)
F_321 ( V_327 , V_18 , V_106 ) ;
F_73 (slabp, &l3->slabs_partial, list)
F_321 ( V_327 , V_18 , V_106 ) ;
F_99 ( & V_40 -> V_14 ) ;
}
V_81 = V_18 -> V_81 ;
if ( V_327 [ 0 ] == V_327 [ 1 ] ) {
F_115 ( & V_138 ) ;
V_325 -> V_363 = F_295 ( V_327 [ 0 ] * 4 * sizeof( unsigned long ) , V_120 ) ;
if ( ! V_325 -> V_363 ) {
V_325 -> V_363 = V_327 ;
F_114 ( & V_138 ) ;
return - V_121 ;
}
* ( unsigned long * ) V_325 -> V_363 = V_327 [ 0 ] * 2 ;
F_92 ( V_327 ) ;
F_114 ( & V_138 ) ;
V_325 -> V_347 = V_325 -> V_3 ;
return 0 ;
}
for ( V_5 = 0 ; V_5 < V_327 [ 1 ] ; V_5 ++ ) {
F_313 ( V_325 , L_65 , V_81 , V_327 [ 2 * V_5 + 3 ] ) ;
F_322 ( V_325 , V_327 [ 2 * V_5 + 2 ] ) ;
F_306 ( V_325 , '\n' ) ;
}
return 0 ;
}
static int F_326 ( struct V_355 * V_355 , struct V_345 * V_345 )
{
unsigned long * V_327 = F_295 ( V_75 , V_120 ) ;
int V_149 = - V_121 ;
if ( V_327 ) {
V_149 = F_318 ( V_345 , & V_364 ) ;
if ( ! V_149 ) {
struct V_324 * V_325 = V_345 -> V_365 ;
* V_327 = V_75 / ( 2 * sizeof( unsigned long ) ) ;
V_325 -> V_363 = V_327 ;
V_327 = NULL ;
}
F_92 ( V_327 ) ;
}
return V_149 ;
}
static int T_6 F_327 ( void )
{
F_328 ( L_66 , V_366 | V_367 , NULL , & V_368 ) ;
#ifdef F_228
F_328 ( L_67 , 0 , NULL , & V_369 ) ;
#endif
return 0 ;
}
T_2 F_329 ( const void * V_1 )
{
F_12 ( ! V_1 ) ;
if ( F_39 ( V_1 == V_63 ) )
return 0 ;
return F_19 ( V_1 ) -> V_182 ;
}
