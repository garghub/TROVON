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
static inline void F_31 ( void )
{
int V_45 ;
F_25 (node)
F_29 ( V_45 ) ;
}
static void F_29 ( int V_37 )
{
}
static inline void F_31 ( void )
{
}
static void F_26 ( struct V_17 * V_18 , int V_45 )
{
}
static void F_27 ( struct V_17 * V_18 )
{
}
static inline struct V_38 * F_32 ( struct V_17 * V_18 )
{
return V_18 -> V_58 [ F_33 () ] ;
}
static inline struct V_17 * F_34 ( T_2 V_3 ,
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
#ifdef F_35
if ( F_36 ( V_59 & V_64 ) )
return V_60 -> V_65 ;
#endif
return V_60 -> V_55 ;
}
static struct V_17 * F_37 ( T_2 V_3 , T_5 V_59 )
{
return F_34 ( V_3 , V_59 ) ;
}
static T_2 F_38 ( T_2 V_66 , T_2 V_67 )
{
return F_39 ( sizeof( struct V_27 ) + V_66 * sizeof( V_68 ) , V_67 ) ;
}
static void F_40 ( unsigned long V_69 , T_2 V_70 ,
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
if ( F_38 ( V_66 , V_67 ) + V_66 * V_70
> V_74 )
V_66 -- ;
if ( V_66 > V_77 )
V_66 = V_77 ;
V_73 = F_38 ( V_66 , V_67 ) ;
}
* V_72 = V_66 ;
* V_71 = V_74 - V_66 * V_70 - V_73 ;
}
static void F_41 ( const char * V_78 , struct V_17 * V_18 ,
char * V_79 )
{
F_42 ( V_80 L_1 ,
V_78 , V_18 -> V_81 , V_79 ) ;
F_43 () ;
F_44 ( V_82 ) ;
}
static int T_6 F_45 ( char * V_49 )
{
V_83 = 0 ;
return 1 ;
}
static int T_6 F_46 ( char * V_84 )
{
F_47 ( & V_84 , & V_85 ) ;
V_85 = V_85 < 0 ? 0 :
F_48 ( V_85 , V_86 - 1 ) ;
V_87 = true ;
return 1 ;
}
static void F_49 ( int V_88 )
{
int V_45 ;
V_45 = F_50 ( F_51 ( V_88 ) , V_89 ) ;
if ( V_45 == V_90 )
V_45 = F_52 ( V_89 ) ;
F_53 ( V_91 , V_88 ) = V_45 ;
}
static void F_54 ( void )
{
int V_45 = F_55 ( V_91 ) ;
V_45 = F_50 ( V_45 , V_89 ) ;
if ( F_36 ( V_45 >= V_90 ) )
V_45 = F_52 ( V_89 ) ;
F_56 ( V_91 , V_45 ) ;
}
static void T_7 F_57 ( int V_88 )
{
struct V_92 * V_93 = & F_53 ( V_94 , V_88 ) ;
if ( F_58 () && V_93 -> V_95 . V_96 == NULL ) {
F_49 ( V_88 ) ;
F_59 ( V_93 , V_97 ) ;
F_60 ( V_88 , V_93 ,
F_61 ( V_98 , V_88 ) ) ;
}
}
static struct V_38 * F_62 ( int V_45 , int V_99 ,
int V_100 , T_5 V_101 )
{
int V_102 = sizeof( void * ) * V_99 + sizeof( struct V_38 ) ;
struct V_38 * V_103 = NULL ;
V_103 = F_63 ( V_102 , V_101 , V_45 ) ;
F_64 ( V_103 ) ;
if ( V_103 ) {
V_103 -> V_104 = 0 ;
V_103 -> V_105 = V_99 ;
V_103 -> V_100 = V_100 ;
V_103 -> V_106 = 0 ;
F_9 ( & V_103 -> V_44 ) ;
}
return V_103 ;
}
static inline bool F_65 ( struct V_27 * V_107 )
{
struct V_25 * V_25 = F_66 ( V_107 -> V_31 ) ;
return F_67 ( V_25 ) ;
}
static void F_68 ( struct V_17 * V_18 ,
struct V_38 * V_108 )
{
struct V_6 * V_40 = V_18 -> V_42 [ F_69 () ] ;
struct V_27 * V_107 ;
unsigned long V_19 ;
if ( ! V_109 )
return;
F_70 ( & V_40 -> V_14 , V_19 ) ;
F_71 (slabp, &l3->slabs_full, list)
if ( F_65 ( V_107 ) )
goto V_110;
F_71 (slabp, &l3->slabs_partial, list)
if ( F_65 ( V_107 ) )
goto V_110;
F_71 (slabp, &l3->slabs_free, list)
if ( F_65 ( V_107 ) )
goto V_110;
V_109 = false ;
V_110:
F_72 ( & V_40 -> V_14 , V_19 ) ;
}
static void * F_73 ( struct V_17 * V_18 , struct V_38 * V_108 ,
T_5 V_19 , bool V_111 )
{
int V_5 ;
void * V_1 = V_108 -> V_112 [ -- V_108 -> V_104 ] ;
if ( F_36 ( F_1 ( V_1 ) ) ) {
struct V_6 * V_40 ;
if ( F_74 ( V_19 ) ) {
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
V_40 = V_18 -> V_42 [ F_69 () ] ;
if ( ! F_75 ( & V_40 -> V_10 ) && V_111 ) {
struct V_27 * V_107 = F_17 ( V_1 ) ;
F_76 ( F_16 ( V_107 -> V_31 ) ) ;
F_3 ( & V_1 ) ;
F_68 ( V_18 , V_108 ) ;
return V_1 ;
}
V_108 -> V_104 ++ ;
V_1 = NULL ;
}
return V_1 ;
}
static inline void * F_77 ( struct V_17 * V_18 ,
struct V_38 * V_108 , T_5 V_19 , bool V_111 )
{
void * V_1 ;
if ( F_36 ( F_78 () ) )
V_1 = F_73 ( V_18 , V_108 , V_19 , V_111 ) ;
else
V_1 = V_108 -> V_112 [ -- V_108 -> V_104 ] ;
return V_1 ;
}
static void * F_79 ( struct V_17 * V_18 , struct V_38 * V_108 ,
void * V_1 )
{
if ( F_36 ( V_109 ) ) {
struct V_25 * V_25 = F_16 ( V_1 ) ;
if ( F_67 ( V_25 ) )
F_2 ( & V_1 ) ;
}
return V_1 ;
}
static inline void F_80 ( struct V_17 * V_18 , struct V_38 * V_108 ,
void * V_1 )
{
if ( F_36 ( F_78 () ) )
V_1 = F_79 ( V_18 , V_108 , V_1 ) ;
V_108 -> V_112 [ V_108 -> V_104 ++ ] = V_1 ;
}
static int F_81 ( struct V_38 * V_113 ,
struct V_38 * V_114 , unsigned int V_115 )
{
int V_116 = F_82 ( V_114 -> V_104 , V_115 , V_113 -> V_105 - V_113 -> V_104 ) ;
if ( ! V_116 )
return 0 ;
memcpy ( V_113 -> V_112 + V_113 -> V_104 , V_114 -> V_112 + V_114 -> V_104 - V_116 ,
sizeof( void * ) * V_116 ) ;
V_114 -> V_104 -= V_116 ;
V_113 -> V_104 += V_116 ;
return V_116 ;
}
static inline struct V_38 * * F_83 ( int V_45 , int V_105 , T_5 V_101 )
{
return (struct V_38 * * ) V_43 ;
}
static inline void F_84 ( struct V_38 * * V_117 )
{
}
static inline int F_85 ( struct V_17 * V_18 , void * V_1 )
{
return 0 ;
}
static inline void * F_86 ( struct V_17 * V_18 ,
T_5 V_19 )
{
return NULL ;
}
static inline void * F_87 ( struct V_17 * V_18 ,
T_5 V_19 , int V_118 )
{
return NULL ;
}
static struct V_38 * * F_83 ( int V_45 , int V_105 , T_5 V_101 )
{
struct V_38 * * V_117 ;
int V_102 = sizeof( void * ) * V_119 ;
int V_5 ;
if ( V_105 > 1 )
V_105 = 12 ;
V_117 = F_88 ( V_102 , V_101 , V_45 ) ;
if ( V_117 ) {
F_25 (i) {
if ( V_5 == V_45 || ! F_89 ( V_5 ) )
continue;
V_117 [ V_5 ] = F_62 ( V_45 , V_105 , 0xbaadf00d , V_101 ) ;
if ( ! V_117 [ V_5 ] ) {
for ( V_5 -- ; V_5 >= 0 ; V_5 -- )
F_90 ( V_117 [ V_5 ] ) ;
F_90 ( V_117 ) ;
return NULL ;
}
}
}
return V_117 ;
}
static void F_84 ( struct V_38 * * V_117 )
{
int V_5 ;
if ( ! V_117 )
return;
F_25 (i)
F_90 ( V_117 [ V_5 ] ) ;
F_90 ( V_117 ) ;
}
static void F_91 ( struct V_17 * V_18 ,
struct V_38 * V_108 , int V_45 )
{
struct V_6 * V_120 = V_18 -> V_42 [ V_45 ] ;
if ( V_108 -> V_104 ) {
F_92 ( & V_120 -> V_14 ) ;
if ( V_120 -> V_11 )
F_81 ( V_120 -> V_11 , V_108 , V_108 -> V_105 ) ;
F_93 ( V_18 , V_108 -> V_112 , V_108 -> V_104 , V_45 ) ;
V_108 -> V_104 = 0 ;
F_94 ( & V_120 -> V_14 ) ;
}
}
static void F_95 ( struct V_17 * V_18 , struct V_6 * V_40 )
{
int V_45 = F_55 ( V_91 ) ;
if ( V_40 -> V_12 ) {
struct V_38 * V_108 = V_40 -> V_12 [ V_45 ] ;
if ( V_108 && V_108 -> V_104 && F_96 ( & V_108 -> V_44 ) ) {
F_91 ( V_18 , V_108 , V_45 ) ;
F_97 ( & V_108 -> V_44 ) ;
}
}
}
static void F_98 ( struct V_17 * V_18 ,
struct V_38 * * V_12 )
{
int V_5 = 0 ;
struct V_38 * V_108 ;
unsigned long V_19 ;
F_28 (i) {
V_108 = V_12 [ V_5 ] ;
if ( V_108 ) {
F_70 ( & V_108 -> V_44 , V_19 ) ;
F_91 ( V_18 , V_108 , V_5 ) ;
F_72 ( & V_108 -> V_44 , V_19 ) ;
}
}
}
static inline int F_85 ( struct V_17 * V_18 , void * V_1 )
{
struct V_27 * V_107 = F_17 ( V_1 ) ;
int V_118 = V_107 -> V_118 ;
struct V_6 * V_40 ;
struct V_38 * V_12 = NULL ;
int V_45 ;
V_45 = F_69 () ;
if ( F_99 ( V_107 -> V_118 == V_45 ) )
return 0 ;
V_40 = V_18 -> V_42 [ V_45 ] ;
F_100 ( V_18 ) ;
if ( V_40 -> V_12 && V_40 -> V_12 [ V_118 ] ) {
V_12 = V_40 -> V_12 [ V_118 ] ;
F_92 ( & V_12 -> V_44 ) ;
if ( F_36 ( V_12 -> V_104 == V_12 -> V_105 ) ) {
F_101 ( V_18 ) ;
F_91 ( V_18 , V_12 , V_118 ) ;
}
F_80 ( V_18 , V_12 , V_1 ) ;
F_94 ( & V_12 -> V_44 ) ;
} else {
F_92 ( & ( V_18 -> V_42 [ V_118 ] ) -> V_14 ) ;
F_93 ( V_18 , & V_1 , 1 , V_118 ) ;
F_94 ( & ( V_18 -> V_42 [ V_118 ] ) -> V_14 ) ;
}
return 1 ;
}
static int F_102 ( int V_45 )
{
struct V_17 * V_18 ;
struct V_6 * V_40 ;
const int V_102 = sizeof( struct V_6 ) ;
F_71 (cachep, &slab_caches, list) {
if ( ! V_18 -> V_42 [ V_45 ] ) {
V_40 = F_63 ( V_102 , V_121 , V_45 ) ;
if ( ! V_40 )
return - V_122 ;
F_7 ( V_40 ) ;
V_40 -> V_123 = V_124 + V_125 +
( ( unsigned long ) V_18 ) % V_125 ;
V_18 -> V_42 [ V_45 ] = V_40 ;
}
F_103 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
V_18 -> V_42 [ V_45 ] -> V_126 =
( 1 + F_104 ( V_45 ) ) *
V_18 -> V_100 + V_18 -> V_72 ;
F_97 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
}
return 0 ;
}
static void T_7 F_105 ( long V_88 )
{
struct V_17 * V_18 ;
struct V_6 * V_40 = NULL ;
int V_45 = F_51 ( V_88 ) ;
const struct V_127 * V_128 = F_106 ( V_45 ) ;
F_71 (cachep, &slab_caches, list) {
struct V_38 * V_103 ;
struct V_38 * V_11 ;
struct V_38 * * V_12 ;
V_103 = V_18 -> V_58 [ V_88 ] ;
V_18 -> V_58 [ V_88 ] = NULL ;
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
goto V_129;
F_103 ( & V_40 -> V_14 ) ;
V_40 -> V_126 -= V_18 -> V_100 ;
if ( V_103 )
F_93 ( V_18 , V_103 -> V_112 , V_103 -> V_104 , V_45 ) ;
if ( ! F_107 ( V_128 ) ) {
F_97 ( & V_40 -> V_14 ) ;
goto V_129;
}
V_11 = V_40 -> V_11 ;
if ( V_11 ) {
F_93 ( V_18 , V_11 -> V_112 ,
V_11 -> V_104 , V_45 ) ;
V_40 -> V_11 = NULL ;
}
V_12 = V_40 -> V_12 ;
V_40 -> V_12 = NULL ;
F_97 ( & V_40 -> V_14 ) ;
F_90 ( V_11 ) ;
if ( V_12 ) {
F_98 ( V_18 , V_12 ) ;
F_84 ( V_12 ) ;
}
V_129:
F_90 ( V_103 ) ;
}
F_71 (cachep, &slab_caches, list) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_108 ( V_18 , V_40 , V_40 -> V_15 ) ;
}
}
static int T_7 F_109 ( long V_88 )
{
struct V_17 * V_18 ;
struct V_6 * V_40 = NULL ;
int V_45 = F_51 ( V_88 ) ;
int V_130 ;
V_130 = F_102 ( V_45 ) ;
if ( V_130 < 0 )
goto V_131;
F_71 (cachep, &slab_caches, list) {
struct V_38 * V_103 ;
struct V_38 * V_11 = NULL ;
struct V_38 * * V_12 = NULL ;
V_103 = F_62 ( V_45 , V_18 -> V_105 ,
V_18 -> V_100 , V_121 ) ;
if ( ! V_103 )
goto V_131;
if ( V_18 -> V_11 ) {
V_11 = F_62 ( V_45 ,
V_18 -> V_11 * V_18 -> V_100 ,
0xbaadf00d , V_121 ) ;
if ( ! V_11 ) {
F_90 ( V_103 ) ;
goto V_131;
}
}
if ( V_83 ) {
V_12 = F_83 ( V_45 , V_18 -> V_105 , V_121 ) ;
if ( ! V_12 ) {
F_90 ( V_11 ) ;
F_90 ( V_103 ) ;
goto V_131;
}
}
V_18 -> V_58 [ V_88 ] = V_103 ;
V_40 = V_18 -> V_42 [ V_45 ] ;
F_12 ( ! V_40 ) ;
F_103 ( & V_40 -> V_14 ) ;
if ( ! V_40 -> V_11 ) {
V_40 -> V_11 = V_11 ;
V_11 = NULL ;
}
#ifdef F_110
if ( ! V_40 -> V_12 ) {
V_40 -> V_12 = V_12 ;
V_12 = NULL ;
}
#endif
F_97 ( & V_40 -> V_14 ) ;
F_90 ( V_11 ) ;
F_84 ( V_12 ) ;
if ( V_18 -> V_19 & V_132 )
F_26 ( V_18 , V_45 ) ;
}
F_29 ( V_45 ) ;
return 0 ;
V_131:
F_105 ( V_88 ) ;
return - V_122 ;
}
static int T_7 F_111 ( struct V_133 * V_134 ,
unsigned long V_135 , void * V_136 )
{
long V_88 = ( long ) V_136 ;
int V_130 = 0 ;
switch ( V_135 ) {
case V_137 :
case V_138 :
F_112 ( & V_139 ) ;
V_130 = F_109 ( V_88 ) ;
F_113 ( & V_139 ) ;
break;
case V_140 :
case V_141 :
F_57 ( V_88 ) ;
break;
#ifdef F_114
case V_142 :
case V_143 :
F_115 ( & F_53 ( V_94 , V_88 ) ) ;
F_53 ( V_94 , V_88 ) . V_95 . V_96 = NULL ;
break;
case V_144 :
case V_145 :
F_57 ( V_88 ) ;
break;
case V_146 :
case V_147 :
#endif
case V_148 :
case V_149 :
F_112 ( & V_139 ) ;
F_105 ( V_88 ) ;
F_113 ( & V_139 ) ;
break;
}
return F_116 ( V_130 ) ;
}
static int T_8 F_117 ( int V_45 )
{
struct V_17 * V_18 ;
int V_150 = 0 ;
F_71 (cachep, &slab_caches, list) {
struct V_6 * V_40 ;
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_108 ( V_18 , V_40 , V_40 -> V_15 ) ;
if ( ! F_75 ( & V_40 -> V_8 ) ||
! F_75 ( & V_40 -> V_9 ) ) {
V_150 = - V_151 ;
break;
}
}
return V_150 ;
}
static int T_8 F_118 ( struct V_133 * V_152 ,
unsigned long V_135 , void * V_153 )
{
struct V_154 * V_155 = V_153 ;
int V_150 = 0 ;
int V_156 ;
V_156 = V_155 -> V_157 ;
if ( V_156 < 0 )
goto V_110;
switch ( V_135 ) {
case V_158 :
F_112 ( & V_139 ) ;
V_150 = F_102 ( V_156 ) ;
F_113 ( & V_139 ) ;
break;
case V_159 :
F_112 ( & V_139 ) ;
V_150 = F_117 ( V_156 ) ;
F_113 ( & V_139 ) ;
break;
case V_160 :
case V_161 :
case V_162 :
case V_163 :
break;
}
V_110:
return F_116 ( V_150 ) ;
}
static void T_6 F_119 ( struct V_17 * V_18 , struct V_6 * V_164 ,
int V_118 )
{
struct V_6 * V_165 ;
V_165 = F_63 ( sizeof( struct V_6 ) , V_166 , V_118 ) ;
F_12 ( ! V_165 ) ;
memcpy ( V_165 , V_164 , sizeof( struct V_6 ) ) ;
F_9 ( & V_165 -> V_14 ) ;
F_120 ( V_18 , V_165 , V_118 ) ;
V_18 -> V_42 [ V_118 ] = V_165 ;
}
static void T_6 F_121 ( struct V_17 * V_18 , int V_167 )
{
int V_45 ;
F_28 (node) {
V_18 -> V_42 [ V_45 ] = & V_168 [ V_167 + V_45 ] ;
V_18 -> V_42 [ V_45 ] -> V_123 = V_124 +
V_125 +
( ( unsigned long ) V_18 ) % V_125 ;
}
}
void T_6 F_122 ( void )
{
T_2 V_71 ;
struct V_48 * V_169 ;
struct V_170 * V_171 ;
int V_5 ;
int V_172 ;
int V_45 ;
V_17 = & V_173 ;
if ( F_123 () == 1 )
V_83 = 0 ;
for ( V_5 = 0 ; V_5 < V_174 ; V_5 ++ ) {
F_7 ( & V_168 [ V_5 ] ) ;
if ( V_5 < V_90 )
V_17 -> V_42 [ V_5 ] = NULL ;
}
F_121 ( V_17 , V_175 ) ;
if ( ! V_87 && V_176 > ( 32 << 20 ) >> V_177 )
V_85 = V_178 ;
V_45 = F_69 () ;
F_8 ( & V_179 ) ;
F_124 ( & V_17 -> V_164 , & V_179 ) ;
V_17 -> V_180 = F_125 () ;
V_17 -> V_58 [ F_33 () ] = & V_181 . V_29 ;
V_17 -> V_42 [ V_45 ] = & V_168 [ V_175 + V_45 ] ;
V_17 -> V_3 = F_126 ( struct V_17 , V_58 [ V_182 ] ) +
V_119 * sizeof( struct V_6 * ) ;
V_17 -> V_183 = V_17 -> V_3 ;
V_17 -> V_3 = F_39 ( V_17 -> V_183 ,
F_125 () ) ;
V_17 -> V_33 =
F_127 ( V_17 -> V_3 ) ;
for ( V_172 = 0 ; V_172 < V_86 ; V_172 ++ ) {
F_40 ( V_172 , V_17 -> V_3 ,
F_125 () , 0 , & V_71 , & V_17 -> V_72 ) ;
if ( V_17 -> V_72 )
break;
}
F_12 ( ! V_17 -> V_72 ) ;
V_17 -> V_69 = V_172 ;
V_17 -> V_184 = V_71 / V_17 -> V_180 ;
V_17 -> V_74 = F_39 ( V_17 -> V_72 * sizeof( V_68 ) +
sizeof( struct V_27 ) , F_125 () ) ;
V_169 = V_50 ;
V_171 = V_170 ;
V_169 [ V_62 ] . V_55 = F_128 ( V_17 , V_166 ) ;
V_169 [ V_62 ] . V_55 -> V_81 = V_171 [ V_62 ] . V_81 ;
V_169 [ V_62 ] . V_55 -> V_3 = V_169 [ V_62 ] . V_53 ;
V_169 [ V_62 ] . V_55 -> V_183 = V_169 [ V_62 ] . V_53 ;
V_169 [ V_62 ] . V_55 -> V_67 = V_185 ;
F_129 ( V_169 [ V_62 ] . V_55 , V_186 | V_187 ) ;
F_124 ( & V_169 [ V_62 ] . V_55 -> V_164 , & V_179 ) ;
if ( V_62 != V_188 ) {
V_169 [ V_188 ] . V_55 = F_128 ( V_17 , V_166 ) ;
V_169 [ V_188 ] . V_55 -> V_81 = V_171 [ V_188 ] . V_81 ;
V_169 [ V_188 ] . V_55 -> V_3 = V_169 [ V_188 ] . V_53 ;
V_169 [ V_188 ] . V_55 -> V_183 = V_169 [ V_188 ] . V_53 ;
V_169 [ V_188 ] . V_55 -> V_67 = V_185 ;
F_129 ( V_169 [ V_188 ] . V_55 , V_186 | V_187 ) ;
F_124 ( & V_169 [ V_188 ] . V_55 -> V_164 , & V_179 ) ;
}
V_189 = 0 ;
while ( V_169 -> V_53 != V_54 ) {
if ( ! V_169 -> V_55 ) {
V_169 -> V_55 = F_128 ( V_17 , V_166 ) ;
V_169 -> V_55 -> V_81 = V_171 -> V_81 ;
V_169 -> V_55 -> V_3 = V_169 -> V_53 ;
V_169 -> V_55 -> V_183 = V_169 -> V_53 ;
V_169 -> V_55 -> V_67 = V_185 ;
F_129 ( V_169 -> V_55 , V_186 | V_187 ) ;
F_124 ( & V_169 -> V_55 -> V_164 , & V_179 ) ;
}
#ifdef F_35
V_169 -> V_65 = F_128 ( V_17 , V_166 ) ;
V_169 -> V_65 -> V_81 = V_171 -> V_190 ;
V_169 -> V_65 -> V_3 = V_169 -> V_53 ;
V_169 -> V_65 -> V_183 = V_169 -> V_53 ;
V_169 -> V_65 -> V_67 = V_185 ;
F_129 ( V_169 -> V_65 ,
V_186 | V_191 | V_187 ) ;
F_124 ( & V_169 -> V_65 -> V_164 , & V_179 ) ;
#endif
V_169 ++ ;
V_171 ++ ;
}
{
struct V_38 * V_165 ;
V_165 = F_130 ( sizeof( struct V_192 ) , V_166 ) ;
F_12 ( F_32 ( V_17 ) != & V_181 . V_29 ) ;
memcpy ( V_165 , F_32 ( V_17 ) ,
sizeof( struct V_192 ) ) ;
F_9 ( & V_165 -> V_44 ) ;
V_17 -> V_58 [ F_33 () ] = V_165 ;
V_165 = F_130 ( sizeof( struct V_192 ) , V_166 ) ;
F_12 ( F_32 ( V_50 [ V_62 ] . V_55 )
!= & V_193 . V_29 ) ;
memcpy ( V_165 , F_32 ( V_50 [ V_62 ] . V_55 ) ,
sizeof( struct V_192 ) ) ;
F_9 ( & V_165 -> V_44 ) ;
V_50 [ V_62 ] . V_55 -> V_58 [ F_33 () ] =
V_165 ;
}
{
int V_156 ;
F_28 (nid) {
F_119 ( V_17 , & V_168 [ V_175 + V_156 ] , V_156 ) ;
F_119 ( V_50 [ V_62 ] . V_55 ,
& V_168 [ V_194 + V_156 ] , V_156 ) ;
if ( V_62 != V_188 ) {
F_119 ( V_50 [ V_188 ] . V_55 ,
& V_168 [ V_195 + V_156 ] , V_156 ) ;
}
}
}
V_51 = V_52 ;
}
void T_6 F_131 ( void )
{
struct V_17 * V_18 ;
V_51 = V_52 ;
F_112 ( & V_139 ) ;
F_71 (cachep, &slab_caches, list)
if ( F_132 ( V_18 , V_166 ) )
F_133 () ;
F_113 ( & V_139 ) ;
F_31 () ;
V_51 = V_196 ;
F_134 ( & V_197 ) ;
#ifdef F_110
F_135 ( F_118 , V_198 ) ;
#endif
}
static int T_6 F_136 ( void )
{
int V_88 ;
F_137 (cpu)
F_57 ( V_88 ) ;
V_51 = V_196 ;
return 0 ;
}
static T_9 void
F_138 ( struct V_17 * V_18 , T_5 V_59 , int V_118 )
{
struct V_6 * V_40 ;
struct V_27 * V_107 ;
unsigned long V_19 ;
int V_45 ;
F_42 ( V_199
L_2 ,
V_118 , V_59 ) ;
F_42 ( V_199 L_3 ,
V_18 -> V_81 , V_18 -> V_3 , V_18 -> V_69 ) ;
F_28 (node) {
unsigned long V_200 = 0 , V_201 = 0 , V_15 = 0 ;
unsigned long V_202 = 0 , V_203 = 0 ;
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_70 ( & V_40 -> V_14 , V_19 ) ;
F_71 (slabp, &l3->slabs_full, list) {
V_200 += V_18 -> V_72 ;
V_202 ++ ;
}
F_71 (slabp, &l3->slabs_partial, list) {
V_200 += V_107 -> V_204 ;
V_202 ++ ;
}
F_71 (slabp, &l3->slabs_free, list)
V_203 ++ ;
V_15 += V_40 -> V_15 ;
F_72 ( & V_40 -> V_14 , V_19 ) ;
V_203 += V_202 ;
V_201 = V_203 * V_18 -> V_72 ;
F_42 ( V_199
L_4 ,
V_45 , V_202 , V_203 , V_200 , V_201 ,
V_15 ) ;
}
}
static void * F_139 ( struct V_17 * V_18 , T_5 V_19 , int V_118 )
{
struct V_25 * V_25 ;
int V_205 ;
int V_5 ;
#ifndef F_140
V_19 |= V_206 ;
#endif
V_19 |= V_18 -> V_207 ;
if ( V_18 -> V_19 & V_208 )
V_19 |= V_209 ;
V_25 = F_141 ( V_118 , V_19 | V_210 , V_18 -> V_69 ) ;
if ( ! V_25 ) {
if ( ! ( V_19 & V_211 ) && F_142 () )
F_138 ( V_18 , V_19 , V_118 ) ;
return NULL ;
}
if ( F_36 ( V_25 -> V_212 ) )
V_109 = true ;
V_205 = ( 1 << V_18 -> V_69 ) ;
if ( V_18 -> V_19 & V_208 )
F_143 ( F_144 ( V_25 ) ,
V_213 , V_205 ) ;
else
F_143 ( F_144 ( V_25 ) ,
V_214 , V_205 ) ;
for ( V_5 = 0 ; V_5 < V_205 ; V_5 ++ ) {
F_145 ( V_25 + V_5 ) ;
if ( V_25 -> V_212 )
F_146 ( V_25 + V_5 ) ;
}
if ( V_215 && ! ( V_18 -> V_19 & V_216 ) ) {
F_147 ( V_25 , V_18 -> V_69 , V_19 , V_118 ) ;
if ( V_18 -> V_217 )
F_148 ( V_25 , V_205 ) ;
else
F_149 ( V_25 , V_205 ) ;
}
return F_150 ( V_25 ) ;
}
static void F_151 ( struct V_17 * V_18 , void * V_218 )
{
unsigned long V_5 = ( 1 << V_18 -> V_69 ) ;
struct V_25 * V_25 = F_66 ( V_218 ) ;
const unsigned long V_219 = V_5 ;
F_152 ( V_25 , V_18 -> V_69 ) ;
if ( V_18 -> V_19 & V_208 )
F_153 ( F_144 ( V_25 ) ,
V_213 , V_219 ) ;
else
F_153 ( F_144 ( V_25 ) ,
V_214 , V_219 ) ;
while ( V_5 -- ) {
F_12 ( ! F_19 ( V_25 ) ) ;
F_154 ( V_25 ) ;
F_155 ( V_25 ) ;
V_25 ++ ;
}
if ( V_220 -> V_221 )
V_220 -> V_221 -> V_222 += V_219 ;
F_156 ( ( unsigned long ) V_218 , V_18 -> V_69 ) ;
}
static void F_157 ( struct V_223 * V_224 )
{
struct V_225 * V_225 = (struct V_225 * ) V_224 ;
struct V_17 * V_18 = V_225 -> V_18 ;
F_151 ( V_18 , V_225 -> V_218 ) ;
if ( F_30 ( V_18 ) )
F_158 ( V_18 -> V_226 , V_225 ) ;
}
static void F_159 ( struct V_17 * V_18 , unsigned long * V_218 ,
unsigned long V_227 )
{
int V_3 = V_18 -> V_183 ;
V_218 = ( unsigned long * ) & ( ( char * ) V_218 ) [ F_10 ( V_18 ) ] ;
if ( V_3 < 5 * sizeof( unsigned long ) )
return;
* V_218 ++ = 0x12345678 ;
* V_218 ++ = V_227 ;
* V_218 ++ = F_33 () ;
V_3 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_228 = & V_227 ;
unsigned long V_229 ;
while ( ! F_160 ( V_228 ) ) {
V_229 = * V_228 ++ ;
if ( F_161 ( V_229 ) ) {
* V_218 ++ = V_229 ;
V_3 -= sizeof( unsigned long ) ;
if ( V_3 <= sizeof( unsigned long ) )
break;
}
}
}
* V_218 ++ = 0x87654321 ;
}
static void F_162 ( struct V_17 * V_18 , void * V_218 , unsigned char V_230 )
{
int V_3 = V_18 -> V_183 ;
V_218 = & ( ( char * ) V_218 ) [ F_10 ( V_18 ) ] ;
memset ( V_218 , V_230 , V_3 ) ;
* ( unsigned char * ) ( V_218 + V_3 - 1 ) = V_231 ;
}
static void F_163 ( char * V_232 , int V_32 , int V_105 )
{
int V_5 ;
unsigned char error = 0 ;
int V_233 = 0 ;
F_42 ( V_80 L_5 , V_32 ) ;
for ( V_5 = 0 ; V_5 < V_105 ; V_5 ++ ) {
if ( V_232 [ V_32 + V_5 ] != V_234 ) {
error = V_232 [ V_32 + V_5 ] ;
V_233 ++ ;
}
}
F_164 ( V_235 , L_6 , 0 , 16 , 1 ,
& V_232 [ V_32 ] , V_105 , 1 ) ;
if ( V_233 == 1 ) {
error ^= V_234 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_42 ( V_80 L_7
L_8 ) ;
#ifdef F_165
F_42 ( V_80 L_9
L_10 ) ;
#else
F_42 ( V_80 L_11 ) ;
#endif
}
}
}
static void F_166 ( struct V_17 * V_18 , void * V_1 , int V_236 )
{
int V_5 , V_3 ;
char * V_237 ;
if ( V_18 -> V_19 & V_20 ) {
F_42 ( V_80 L_12 ,
* F_11 ( V_18 , V_1 ) ,
* F_13 ( V_18 , V_1 ) ) ;
}
if ( V_18 -> V_19 & V_21 ) {
F_42 ( V_80 L_13 ,
* F_14 ( V_18 , V_1 ) ) ;
F_167 ( L_14 ,
( unsigned long ) * F_14 ( V_18 , V_1 ) ) ;
F_42 ( L_15 ) ;
}
V_237 = ( char * ) V_1 + F_10 ( V_18 ) ;
V_3 = V_18 -> V_183 ;
for ( V_5 = 0 ; V_5 < V_3 && V_236 ; V_5 += 16 , V_236 -- ) {
int V_105 ;
V_105 = 16 ;
if ( V_5 + V_105 > V_3 )
V_105 = V_3 - V_5 ;
F_163 ( V_237 , V_5 , V_105 ) ;
}
}
static void F_168 ( struct V_17 * V_18 , void * V_1 )
{
char * V_237 ;
int V_3 , V_5 ;
int V_236 = 0 ;
V_237 = ( char * ) V_1 + F_10 ( V_18 ) ;
V_3 = V_18 -> V_183 ;
for ( V_5 = 0 ; V_5 < V_3 ; V_5 ++ ) {
char exp = V_234 ;
if ( V_5 == V_3 - 1 )
exp = V_231 ;
if ( V_237 [ V_5 ] != exp ) {
int V_105 ;
if ( V_236 == 0 ) {
F_42 ( V_80
L_16 ,
F_169 () , V_18 -> V_81 , V_237 , V_3 ) ;
F_166 ( V_18 , V_1 , 0 ) ;
}
V_5 = ( V_5 / 16 ) * 16 ;
V_105 = 16 ;
if ( V_5 + V_105 > V_3 )
V_105 = V_3 - V_5 ;
F_163 ( V_237 , V_5 , V_105 ) ;
V_5 += 16 ;
V_236 ++ ;
if ( V_236 > 5 )
break;
}
}
if ( V_236 != 0 ) {
struct V_27 * V_107 = F_17 ( V_1 ) ;
unsigned int V_238 ;
V_238 = F_21 ( V_18 , V_107 , V_1 ) ;
if ( V_238 ) {
V_1 = F_20 ( V_18 , V_107 , V_238 - 1 ) ;
V_237 = ( char * ) V_1 + F_10 ( V_18 ) ;
F_42 ( V_80 L_17 ,
V_237 , V_3 ) ;
F_166 ( V_18 , V_1 , 2 ) ;
}
if ( V_238 + 1 < V_18 -> V_72 ) {
V_1 = F_20 ( V_18 , V_107 , V_238 + 1 ) ;
V_237 = ( char * ) V_1 + F_10 ( V_18 ) ;
F_42 ( V_80 L_18 ,
V_237 , V_3 ) ;
F_166 ( V_18 , V_1 , 2 ) ;
}
}
}
static void F_170 ( struct V_17 * V_18 , struct V_27 * V_107 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_72 ; V_5 ++ ) {
void * V_1 = F_20 ( V_18 , V_107 , V_5 ) ;
if ( V_18 -> V_19 & V_239 ) {
#ifdef F_171
if ( V_18 -> V_3 % V_75 == 0 &&
F_30 ( V_18 ) )
F_172 ( F_66 ( V_1 ) ,
V_18 -> V_3 / V_75 , 1 ) ;
else
F_168 ( V_18 , V_1 ) ;
#else
F_168 ( V_18 , V_1 ) ;
#endif
}
if ( V_18 -> V_19 & V_20 ) {
if ( * F_11 ( V_18 , V_1 ) != V_240 )
F_173 ( V_18 , L_19
L_20 ) ;
if ( * F_13 ( V_18 , V_1 ) != V_240 )
F_173 ( V_18 , L_21
L_20 ) ;
}
}
}
static void F_170 ( struct V_17 * V_18 , struct V_27 * V_107 )
{
}
static void F_174 ( struct V_17 * V_18 , struct V_27 * V_107 )
{
void * V_218 = V_107 -> V_31 - V_107 -> V_241 ;
F_170 ( V_18 , V_107 ) ;
if ( F_36 ( V_18 -> V_19 & V_242 ) ) {
struct V_225 * V_225 ;
V_225 = (struct V_225 * ) V_107 ;
V_225 -> V_18 = V_18 ;
V_225 -> V_218 = V_218 ;
F_175 ( & V_225 -> V_224 , F_157 ) ;
} else {
F_151 ( V_18 , V_218 ) ;
if ( F_30 ( V_18 ) )
F_158 ( V_18 -> V_226 , V_107 ) ;
}
}
static T_2 F_176 ( struct V_17 * V_18 ,
T_2 V_3 , T_2 V_67 , unsigned long V_19 )
{
unsigned long V_243 ;
T_2 V_71 = 0 ;
int V_69 ;
for ( V_69 = 0 ; V_69 <= V_244 ; V_69 ++ ) {
unsigned int V_72 ;
T_2 V_245 ;
F_40 ( V_69 , V_3 , V_67 , V_19 , & V_245 , & V_72 ) ;
if ( ! V_72 )
continue;
if ( V_19 & V_76 ) {
V_243 = V_3 - sizeof( struct V_27 ) ;
V_243 /= sizeof( V_68 ) ;
if ( V_72 > V_243 )
break;
}
V_18 -> V_72 = V_72 ;
V_18 -> V_69 = V_69 ;
V_71 = V_245 ;
if ( V_19 & V_208 )
break;
if ( V_69 >= V_85 )
break;
if ( V_71 * 8 <= ( V_75 << V_69 ) )
break;
}
return V_71 ;
}
static int T_10 F_177 ( struct V_17 * V_18 , T_5 V_101 )
{
if ( V_51 >= V_196 )
return F_132 ( V_18 , V_101 ) ;
if ( V_51 == V_246 ) {
V_18 -> V_58 [ F_33 () ] = & V_193 . V_29 ;
F_121 ( V_18 , V_194 ) ;
if ( V_62 == V_188 )
V_51 = V_247 ;
else
V_51 = V_248 ;
} else {
V_18 -> V_58 [ F_33 () ] =
F_130 ( sizeof( struct V_192 ) , V_101 ) ;
if ( V_51 == V_248 ) {
F_121 ( V_18 , V_195 ) ;
V_51 = V_247 ;
} else {
int V_45 ;
F_28 (node) {
V_18 -> V_42 [ V_45 ] =
F_63 ( sizeof( struct V_6 ) ,
V_101 , V_45 ) ;
F_12 ( ! V_18 -> V_42 [ V_45 ] ) ;
F_7 ( V_18 -> V_42 [ V_45 ] ) ;
}
}
}
V_18 -> V_42 [ F_69 () ] -> V_123 =
V_124 + V_125 +
( ( unsigned long ) V_18 ) % V_125 ;
F_32 ( V_18 ) -> V_104 = 0 ;
F_32 ( V_18 ) -> V_105 = V_249 ;
F_32 ( V_18 ) -> V_100 = 1 ;
F_32 ( V_18 ) -> V_106 = 0 ;
V_18 -> V_100 = 1 ;
V_18 -> V_105 = V_249 ;
return 0 ;
}
int
F_129 ( struct V_17 * V_18 , unsigned long V_19 )
{
T_2 V_71 , V_74 , V_250 ;
T_5 V_101 ;
int V_130 ;
T_2 V_3 = V_18 -> V_3 ;
#if V_61
#if V_251
if ( V_3 < 4096 || F_178 ( V_3 - 1 ) == F_178 ( V_3 - 1 + V_22 +
2 * sizeof( unsigned long long ) ) )
V_19 |= V_20 | V_21 ;
if ( ! ( V_19 & V_242 ) )
V_19 |= V_239 ;
#endif
if ( V_19 & V_242 )
F_12 ( V_19 & V_239 ) ;
#endif
F_12 ( V_19 & ~ V_252 ) ;
if ( V_3 & ( V_23 - 1 ) ) {
V_3 += ( V_23 - 1 ) ;
V_3 &= ~ ( V_23 - 1 ) ;
}
if ( V_19 & V_253 ) {
V_250 = F_125 () ;
while ( V_3 <= V_250 / 2 )
V_250 /= 2 ;
} else {
V_250 = V_23 ;
}
if ( V_19 & V_21 )
V_250 = V_23 ;
if ( V_19 & V_20 ) {
V_250 = V_22 ;
V_3 += V_22 - 1 ;
V_3 &= ~ ( V_22 - 1 ) ;
}
if ( V_250 < V_254 ) {
V_250 = V_254 ;
}
if ( V_250 < V_18 -> V_67 ) {
V_250 = V_18 -> V_67 ;
}
if ( V_250 > F_179 (unsigned long long) )
V_19 &= ~ ( V_20 | V_21 ) ;
V_18 -> V_67 = V_250 ;
if ( F_180 () )
V_101 = V_121 ;
else
V_101 = V_166 ;
V_18 -> V_42 = (struct V_6 * * ) & V_18 -> V_58 [ V_182 ] ;
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
#if V_251 && F_181 ( F_171 )
if ( V_3 >= V_50 [ V_188 + 1 ] . V_53
&& V_18 -> V_183 > F_125 ()
&& F_39 ( V_3 , V_18 -> V_67 ) < V_75 ) {
V_18 -> F_10 += V_75 - F_39 ( V_3 , V_18 -> V_67 ) ;
V_3 = V_75 ;
}
#endif
#endif
if ( ( V_3 >= ( V_75 >> 3 ) ) && ! V_189 &&
! ( V_19 & V_255 ) )
V_19 |= V_76 ;
V_3 = F_39 ( V_3 , V_18 -> V_67 ) ;
V_71 = F_176 ( V_18 , V_3 , V_18 -> V_67 , V_19 ) ;
if ( ! V_18 -> V_72 )
return - V_256 ;
V_74 = F_39 ( V_18 -> V_72 * sizeof( V_68 )
+ sizeof( struct V_27 ) , V_18 -> V_67 ) ;
if ( V_19 & V_76 && V_71 >= V_74 ) {
V_19 &= ~ V_76 ;
V_71 -= V_74 ;
}
if ( V_19 & V_76 ) {
V_74 =
V_18 -> V_72 * sizeof( V_68 ) + sizeof( struct V_27 ) ;
#ifdef F_182
if ( V_3 % V_75 == 0 && V_19 & V_239 )
V_19 &= ~ ( V_20 | V_21 ) ;
#endif
}
V_18 -> V_180 = F_125 () ;
if ( V_18 -> V_180 < V_18 -> V_67 )
V_18 -> V_180 = V_18 -> V_67 ;
V_18 -> V_184 = V_71 / V_18 -> V_180 ;
V_18 -> V_74 = V_74 ;
V_18 -> V_19 = V_19 ;
V_18 -> V_207 = 0 ;
if ( V_257 && ( V_19 & V_191 ) )
V_18 -> V_207 |= V_64 ;
V_18 -> V_3 = V_3 ;
V_18 -> V_33 = F_127 ( V_3 ) ;
if ( V_19 & V_76 ) {
V_18 -> V_226 = F_37 ( V_74 , 0u ) ;
F_12 ( F_183 ( V_18 -> V_226 ) ) ;
}
V_130 = F_177 ( V_18 , V_101 ) ;
if ( V_130 ) {
F_184 ( V_18 ) ;
return V_130 ;
}
if ( V_19 & V_132 ) {
F_185 ( V_19 & V_242 ) ;
F_27 ( V_18 ) ;
}
return 0 ;
}
static void F_186 ( void )
{
F_12 ( ! F_187 () ) ;
}
static void F_188 ( void )
{
F_12 ( F_187 () ) ;
}
static void F_189 ( struct V_17 * V_18 )
{
#ifdef F_190
F_186 () ;
F_191 ( & V_18 -> V_42 [ F_69 () ] -> V_14 ) ;
#endif
}
static void F_192 ( struct V_17 * V_18 , int V_45 )
{
#ifdef F_190
F_186 () ;
F_191 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
#endif
}
static void F_193 ( void * V_153 )
{
struct V_17 * V_18 = V_153 ;
struct V_38 * V_108 ;
int V_45 = F_69 () ;
F_186 () ;
V_108 = F_32 ( V_18 ) ;
F_92 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
F_93 ( V_18 , V_108 -> V_112 , V_108 -> V_104 , V_45 ) ;
F_94 ( & V_18 -> V_42 [ V_45 ] -> V_14 ) ;
V_108 -> V_104 = 0 ;
}
static void F_194 ( struct V_17 * V_18 )
{
struct V_6 * V_40 ;
int V_45 ;
F_195 ( F_193 , V_18 , 1 ) ;
F_188 () ;
F_28 (node) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( V_40 && V_40 -> V_12 )
F_98 ( V_18 , V_40 -> V_12 ) ;
}
F_28 (node) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( V_40 )
F_196 ( V_18 , V_40 , V_40 -> V_11 , 1 , V_45 ) ;
}
}
static int F_108 ( struct V_17 * V_29 ,
struct V_6 * V_40 , int V_258 )
{
struct V_259 * V_260 ;
int V_219 ;
struct V_27 * V_107 ;
V_219 = 0 ;
while ( V_219 < V_258 && ! F_75 ( & V_40 -> V_10 ) ) {
F_103 ( & V_40 -> V_14 ) ;
V_260 = V_40 -> V_10 . V_261 ;
if ( V_260 == & V_40 -> V_10 ) {
F_97 ( & V_40 -> V_14 ) ;
goto V_110;
}
V_107 = F_197 ( V_260 , struct V_27 , V_164 ) ;
#if V_61
F_12 ( V_107 -> V_204 ) ;
#endif
F_198 ( & V_107 -> V_164 ) ;
V_40 -> V_15 -= V_29 -> V_72 ;
F_97 ( & V_40 -> V_14 ) ;
F_174 ( V_29 , V_107 ) ;
V_219 ++ ;
}
V_110:
return V_219 ;
}
static int F_199 ( struct V_17 * V_18 )
{
int V_150 = 0 , V_5 = 0 ;
struct V_6 * V_40 ;
F_194 ( V_18 ) ;
F_188 () ;
F_28 (i) {
V_40 = V_18 -> V_42 [ V_5 ] ;
if ( ! V_40 )
continue;
F_108 ( V_18 , V_40 , V_40 -> V_15 ) ;
V_150 += ! F_75 ( & V_40 -> V_8 ) ||
! F_75 ( & V_40 -> V_9 ) ;
}
return ( V_150 ? 1 : 0 ) ;
}
int F_200 ( struct V_17 * V_18 )
{
int V_150 ;
F_12 ( ! V_18 || F_201 () ) ;
F_202 () ;
F_112 ( & V_139 ) ;
V_150 = F_199 ( V_18 ) ;
F_113 ( & V_139 ) ;
F_203 () ;
return V_150 ;
}
int F_184 ( struct V_17 * V_18 )
{
int V_5 ;
struct V_6 * V_40 ;
int V_262 = F_199 ( V_18 ) ;
if ( V_262 )
return V_262 ;
F_137 (i)
F_90 ( V_18 -> V_58 [ V_5 ] ) ;
F_28 (i) {
V_40 = V_18 -> V_42 [ V_5 ] ;
if ( V_40 ) {
F_90 ( V_40 -> V_11 ) ;
F_84 ( V_40 -> V_12 ) ;
F_90 ( V_40 ) ;
}
}
return 0 ;
}
static struct V_27 * F_204 ( struct V_17 * V_18 , void * V_1 ,
int V_180 , T_5 V_263 ,
int V_118 )
{
struct V_27 * V_107 ;
if ( F_30 ( V_18 ) ) {
V_107 = F_205 ( V_18 -> V_226 ,
V_263 , V_118 ) ;
F_206 ( & V_107 -> V_164 , sizeof( struct V_259 ) ,
V_263 ) ;
if ( ! V_107 )
return NULL ;
} else {
V_107 = V_1 + V_180 ;
V_180 += V_18 -> V_74 ;
}
V_107 -> V_204 = 0 ;
V_107 -> V_241 = V_180 ;
V_107 -> V_31 = V_1 + V_180 ;
V_107 -> V_118 = V_118 ;
V_107 -> free = 0 ;
return V_107 ;
}
static inline V_68 * F_207 ( struct V_27 * V_107 )
{
return ( V_68 * ) ( V_107 + 1 ) ;
}
static void F_208 ( struct V_17 * V_18 ,
struct V_27 * V_107 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_18 -> V_72 ; V_5 ++ ) {
void * V_1 = F_20 ( V_18 , V_107 , V_5 ) ;
#if V_61
if ( V_18 -> V_19 & V_239 )
F_162 ( V_18 , V_1 , V_234 ) ;
if ( V_18 -> V_19 & V_21 )
* F_14 ( V_18 , V_1 ) = NULL ;
if ( V_18 -> V_19 & V_20 ) {
* F_11 ( V_18 , V_1 ) = V_240 ;
* F_13 ( V_18 , V_1 ) = V_240 ;
}
if ( V_18 -> V_217 && ! ( V_18 -> V_19 & V_239 ) )
V_18 -> V_217 ( V_1 + F_10 ( V_18 ) ) ;
if ( V_18 -> V_19 & V_20 ) {
if ( * F_13 ( V_18 , V_1 ) != V_240 )
F_173 ( V_18 , L_22
L_23 ) ;
if ( * F_11 ( V_18 , V_1 ) != V_240 )
F_173 ( V_18 , L_22
L_24 ) ;
}
if ( ( V_18 -> V_3 % V_75 ) == 0 &&
F_30 ( V_18 ) && V_18 -> V_19 & V_239 )
F_172 ( F_66 ( V_1 ) ,
V_18 -> V_3 / V_75 , 0 ) ;
#else
if ( V_18 -> V_217 )
V_18 -> V_217 ( V_1 ) ;
#endif
F_207 ( V_107 ) [ V_5 ] = V_5 + 1 ;
}
F_207 ( V_107 ) [ V_5 - 1 ] = V_264 ;
}
static void F_209 ( struct V_17 * V_18 , T_5 V_19 )
{
if ( V_257 ) {
if ( V_19 & V_64 )
F_12 ( ! ( V_18 -> V_207 & V_64 ) ) ;
else
F_12 ( V_18 -> V_207 & V_64 ) ;
}
}
static void * F_210 ( struct V_17 * V_18 , struct V_27 * V_107 ,
int V_118 )
{
void * V_1 = F_20 ( V_18 , V_107 , V_107 -> free ) ;
V_68 V_265 ;
V_107 -> V_204 ++ ;
V_265 = F_207 ( V_107 ) [ V_107 -> free ] ;
#if V_61
F_207 ( V_107 ) [ V_107 -> free ] = V_266 ;
F_211 ( V_107 -> V_118 != V_118 ) ;
#endif
V_107 -> free = V_265 ;
return V_1 ;
}
static void F_212 ( struct V_17 * V_18 , struct V_27 * V_107 ,
void * V_1 , int V_118 )
{
unsigned int V_238 = F_21 ( V_18 , V_107 , V_1 ) ;
#if V_61
F_211 ( V_107 -> V_118 != V_118 ) ;
if ( F_207 ( V_107 ) [ V_238 ] + 1 <= V_77 + 1 ) {
F_42 ( V_80 L_25
L_26 , V_18 -> V_81 , V_1 ) ;
F_133 () ;
}
#endif
F_207 ( V_107 ) [ V_238 ] = V_107 -> free ;
V_107 -> free = V_238 ;
V_107 -> V_204 -- ;
}
static void F_213 ( struct V_17 * V_29 , struct V_27 * V_27 ,
void * V_218 )
{
int V_205 ;
struct V_25 * V_25 ;
V_25 = F_66 ( V_218 ) ;
V_205 = 1 ;
if ( F_99 ( ! F_214 ( V_25 ) ) )
V_205 <<= V_29 -> V_69 ;
do {
V_25 -> V_26 = V_29 ;
V_25 -> V_28 = V_27 ;
V_25 ++ ;
} while ( -- V_205 );
}
static int F_215 ( struct V_17 * V_18 ,
T_5 V_19 , int V_118 , void * V_1 )
{
struct V_27 * V_107 ;
T_2 V_32 ;
T_5 V_263 ;
struct V_6 * V_40 ;
F_12 ( V_19 & V_267 ) ;
V_263 = V_19 & ( V_268 | V_269 ) ;
F_186 () ;
V_40 = V_18 -> V_42 [ V_118 ] ;
F_92 ( & V_40 -> V_14 ) ;
V_32 = V_40 -> V_13 ;
V_40 -> V_13 ++ ;
if ( V_40 -> V_13 >= V_18 -> V_184 )
V_40 -> V_13 = 0 ;
F_94 ( & V_40 -> V_14 ) ;
V_32 *= V_18 -> V_180 ;
if ( V_263 & V_270 )
F_216 () ;
F_209 ( V_18 , V_19 ) ;
if ( ! V_1 )
V_1 = F_139 ( V_18 , V_263 , V_118 ) ;
if ( ! V_1 )
goto V_271;
V_107 = F_204 ( V_18 , V_1 , V_32 ,
V_263 & ~ V_268 , V_118 ) ;
if ( ! V_107 )
goto V_272;
F_213 ( V_18 , V_107 , V_1 ) ;
F_208 ( V_18 , V_107 ) ;
if ( V_263 & V_270 )
F_217 () ;
F_186 () ;
F_92 ( & V_40 -> V_14 ) ;
F_218 ( & V_107 -> V_164 , & ( V_40 -> V_10 ) ) ;
F_219 ( V_18 ) ;
V_40 -> V_15 += V_18 -> V_72 ;
F_94 ( & V_40 -> V_14 ) ;
return 1 ;
V_272:
F_151 ( V_18 , V_1 ) ;
V_271:
if ( V_263 & V_270 )
F_217 () ;
return 0 ;
}
static void F_220 ( const void * V_1 )
{
if ( ! F_221 ( V_1 ) ) {
F_42 ( V_80 L_27 ,
( unsigned long ) V_1 ) ;
F_133 () ;
}
}
static inline void F_222 ( struct V_17 * V_29 , void * V_24 )
{
unsigned long long V_273 , V_274 ;
V_273 = * F_11 ( V_29 , V_24 ) ;
V_274 = * F_13 ( V_29 , V_24 ) ;
if ( V_273 == V_275 && V_274 == V_275 )
return;
if ( V_273 == V_240 && V_274 == V_240 )
F_173 ( V_29 , L_28 ) ;
else
F_173 ( V_29 , L_29 ) ;
F_42 ( V_80 L_30 ,
V_24 , V_273 , V_274 ) ;
}
static void * F_223 ( struct V_17 * V_18 , void * V_1 ,
unsigned long V_227 )
{
struct V_25 * V_25 ;
unsigned int V_238 ;
struct V_27 * V_107 ;
F_12 ( F_15 ( V_1 ) != V_18 ) ;
V_1 -= F_10 ( V_18 ) ;
F_220 ( V_1 ) ;
V_25 = F_16 ( V_1 ) ;
V_107 = V_25 -> V_28 ;
if ( V_18 -> V_19 & V_20 ) {
F_222 ( V_18 , V_1 ) ;
* F_11 ( V_18 , V_1 ) = V_240 ;
* F_13 ( V_18 , V_1 ) = V_240 ;
}
if ( V_18 -> V_19 & V_21 )
* F_14 ( V_18 , V_1 ) = ( void * ) V_227 ;
V_238 = F_21 ( V_18 , V_107 , V_1 ) ;
F_12 ( V_238 >= V_18 -> V_72 ) ;
F_12 ( V_1 != F_20 ( V_18 , V_107 , V_238 ) ) ;
#ifdef F_224
F_207 ( V_107 ) [ V_238 ] = V_266 ;
#endif
if ( V_18 -> V_19 & V_239 ) {
#ifdef F_171
if ( ( V_18 -> V_3 % V_75 ) == 0 && F_30 ( V_18 ) ) {
F_159 ( V_18 , V_1 , V_227 ) ;
F_172 ( F_66 ( V_1 ) ,
V_18 -> V_3 / V_75 , 0 ) ;
} else {
F_162 ( V_18 , V_1 , V_234 ) ;
}
#else
F_162 ( V_18 , V_1 , V_234 ) ;
#endif
}
return V_1 ;
}
static void F_225 ( struct V_17 * V_18 , struct V_27 * V_107 )
{
V_68 V_5 ;
int V_99 = 0 ;
for ( V_5 = V_107 -> free ; V_5 != V_264 ; V_5 = F_207 ( V_107 ) [ V_5 ] ) {
V_99 ++ ;
if ( V_99 > V_18 -> V_72 || V_5 >= V_18 -> V_72 )
goto V_131;
}
if ( V_99 != V_18 -> V_72 - V_107 -> V_204 ) {
V_131:
F_42 ( V_80 L_31
L_32 ,
V_18 -> V_81 , V_18 -> V_72 , V_107 , V_107 -> V_204 ,
F_169 () ) ;
F_164 ( V_80 , L_6 , V_276 , 16 , 1 , V_107 ,
sizeof( * V_107 ) + V_18 -> V_72 * sizeof( V_68 ) ,
1 ) ;
F_133 () ;
}
}
static void * F_226 ( struct V_17 * V_18 , T_5 V_19 ,
bool V_111 )
{
int V_100 ;
struct V_6 * V_40 ;
struct V_38 * V_108 ;
int V_45 ;
F_186 () ;
V_45 = F_69 () ;
if ( F_36 ( V_111 ) )
goto V_277;
V_278:
V_108 = F_32 ( V_18 ) ;
V_100 = V_108 -> V_100 ;
if ( ! V_108 -> V_106 && V_100 > V_279 ) {
V_100 = V_279 ;
}
V_40 = V_18 -> V_42 [ V_45 ] ;
F_12 ( V_108 -> V_104 > 0 || ! V_40 ) ;
F_92 ( & V_40 -> V_14 ) ;
if ( V_40 -> V_11 && F_81 ( V_108 , V_40 -> V_11 , V_100 ) ) {
V_40 -> V_11 -> V_106 = 1 ;
goto V_280;
}
while ( V_100 > 0 ) {
struct V_259 * V_112 ;
struct V_27 * V_107 ;
V_112 = V_40 -> V_9 . V_265 ;
if ( V_112 == & V_40 -> V_9 ) {
V_40 -> V_16 = 1 ;
V_112 = V_40 -> V_10 . V_265 ;
if ( V_112 == & V_40 -> V_10 )
goto V_281;
}
V_107 = F_197 ( V_112 , struct V_27 , V_164 ) ;
F_225 ( V_18 , V_107 ) ;
F_189 ( V_18 ) ;
F_12 ( V_107 -> V_204 >= V_18 -> V_72 ) ;
while ( V_107 -> V_204 < V_18 -> V_72 && V_100 -- ) {
F_227 ( V_18 ) ;
F_228 ( V_18 ) ;
F_229 ( V_18 ) ;
F_80 ( V_18 , V_108 , F_210 ( V_18 , V_107 ,
V_45 ) ) ;
}
F_225 ( V_18 , V_107 ) ;
F_198 ( & V_107 -> V_164 ) ;
if ( V_107 -> free == V_264 )
F_124 ( & V_107 -> V_164 , & V_40 -> V_8 ) ;
else
F_124 ( & V_107 -> V_164 , & V_40 -> V_9 ) ;
}
V_281:
V_40 -> V_15 -= V_108 -> V_104 ;
V_280:
F_94 ( & V_40 -> V_14 ) ;
if ( F_36 ( ! V_108 -> V_104 ) ) {
int T_3 ;
V_277:
T_3 = F_215 ( V_18 , V_19 | V_282 , V_45 , NULL ) ;
V_108 = F_32 ( V_18 ) ;
V_45 = F_69 () ;
if ( ! T_3 && ( V_108 -> V_104 == 0 || V_111 ) )
return NULL ;
if ( ! V_108 -> V_104 )
goto V_278;
}
V_108 -> V_106 = 1 ;
return F_77 ( V_18 , V_108 , V_19 , V_111 ) ;
}
static inline void F_230 ( struct V_17 * V_18 ,
T_5 V_19 )
{
F_231 ( V_19 & V_270 ) ;
#if V_61
F_209 ( V_18 , V_19 ) ;
#endif
}
static void * F_232 ( struct V_17 * V_18 ,
T_5 V_19 , void * V_1 , unsigned long V_227 )
{
if ( ! V_1 )
return V_1 ;
if ( V_18 -> V_19 & V_239 ) {
#ifdef F_171
if ( ( V_18 -> V_3 % V_75 ) == 0 && F_30 ( V_18 ) )
F_172 ( F_66 ( V_1 ) ,
V_18 -> V_3 / V_75 , 1 ) ;
else
F_168 ( V_18 , V_1 ) ;
#else
F_168 ( V_18 , V_1 ) ;
#endif
F_162 ( V_18 , V_1 , V_283 ) ;
}
if ( V_18 -> V_19 & V_21 )
* F_14 ( V_18 , V_1 ) = ( void * ) V_227 ;
if ( V_18 -> V_19 & V_20 ) {
if ( * F_11 ( V_18 , V_1 ) != V_240 ||
* F_13 ( V_18 , V_1 ) != V_240 ) {
F_173 ( V_18 , L_33
L_34 ) ;
F_42 ( V_80
L_35 ,
V_1 , * F_11 ( V_18 , V_1 ) ,
* F_13 ( V_18 , V_1 ) ) ;
}
* F_11 ( V_18 , V_1 ) = V_275 ;
* F_13 ( V_18 , V_1 ) = V_275 ;
}
#ifdef F_224
{
struct V_27 * V_107 ;
unsigned V_238 ;
V_107 = F_16 ( V_1 ) -> V_28 ;
V_238 = ( unsigned ) ( V_1 - V_107 -> V_31 ) / V_18 -> V_3 ;
F_207 ( V_107 ) [ V_238 ] = V_284 ;
}
#endif
V_1 += F_10 ( V_18 ) ;
if ( V_18 -> V_217 && V_18 -> V_19 & V_239 )
V_18 -> V_217 ( V_1 ) ;
if ( V_254 &&
( ( unsigned long ) V_1 & ( V_254 - 1 ) ) ) {
F_42 ( V_80 L_36 ,
V_1 , ( int ) V_254 ) ;
}
return V_1 ;
}
static bool F_233 ( struct V_17 * V_18 , T_5 V_19 )
{
if ( V_18 == V_17 )
return false ;
return F_234 ( V_18 -> V_183 , V_19 , V_18 -> V_19 ) ;
}
static inline void * F_235 ( struct V_17 * V_18 , T_5 V_19 )
{
void * V_1 ;
struct V_38 * V_108 ;
bool V_111 = false ;
F_186 () ;
V_108 = F_32 ( V_18 ) ;
if ( F_99 ( V_108 -> V_104 ) ) {
V_108 -> V_106 = 1 ;
V_1 = F_77 ( V_18 , V_108 , V_19 , false ) ;
if ( V_1 ) {
F_236 ( V_18 ) ;
goto V_110;
}
V_111 = true ;
}
F_237 ( V_18 ) ;
V_1 = F_226 ( V_18 , V_19 , V_111 ) ;
V_108 = F_32 ( V_18 ) ;
V_110:
if ( V_1 )
F_238 ( & V_108 -> V_112 [ V_108 -> V_104 ] ) ;
return V_1 ;
}
static void * F_86 ( struct V_17 * V_18 , T_5 V_19 )
{
int V_285 , V_286 ;
if ( F_201 () || ( V_19 & V_287 ) )
return NULL ;
V_285 = V_286 = F_69 () ;
if ( F_239 () && ( V_18 -> V_19 & V_288 ) )
V_285 = F_240 () ;
else if ( V_220 -> V_289 )
V_285 = F_241 () ;
if ( V_285 != V_286 )
return F_87 ( V_18 , V_19 , V_285 ) ;
return NULL ;
}
static void * F_242 ( struct V_17 * V_29 , T_5 V_19 )
{
struct V_290 * V_290 ;
T_5 V_263 ;
struct V_291 * V_292 ;
struct V_293 * V_293 ;
enum V_294 V_295 = F_243 ( V_19 ) ;
void * V_24 = NULL ;
int V_156 ;
unsigned int V_296 ;
if ( V_19 & V_287 )
return NULL ;
V_263 = V_19 & ( V_268 | V_269 ) ;
V_297:
V_296 = F_244 () ;
V_290 = F_245 ( F_241 () , V_19 ) ;
V_278:
F_246 (zone, z, zonelist, high_zoneidx) {
V_156 = F_247 ( V_293 ) ;
if ( F_248 ( V_293 , V_19 ) &&
V_29 -> V_42 [ V_156 ] &&
V_29 -> V_42 [ V_156 ] -> V_15 ) {
V_24 = F_87 ( V_29 ,
V_19 | V_282 , V_156 ) ;
if ( V_24 )
break;
}
}
if ( ! V_24 ) {
if ( V_263 & V_270 )
F_216 () ;
F_209 ( V_29 , V_19 ) ;
V_24 = F_139 ( V_29 , V_263 , F_69 () ) ;
if ( V_263 & V_270 )
F_217 () ;
if ( V_24 ) {
V_156 = F_249 ( F_66 ( V_24 ) ) ;
if ( F_215 ( V_29 , V_19 , V_156 , V_24 ) ) {
V_24 = F_87 ( V_29 ,
V_19 | V_282 , V_156 ) ;
if ( ! V_24 )
goto V_278;
} else {
V_24 = NULL ;
}
}
}
if ( F_36 ( ! F_250 ( V_296 ) && ! V_24 ) )
goto V_297;
return V_24 ;
}
static void * F_87 ( struct V_17 * V_18 , T_5 V_19 ,
int V_118 )
{
struct V_259 * V_112 ;
struct V_27 * V_107 ;
struct V_6 * V_40 ;
void * V_24 ;
int T_3 ;
V_40 = V_18 -> V_42 [ V_118 ] ;
F_12 ( ! V_40 ) ;
V_278:
F_186 () ;
F_92 ( & V_40 -> V_14 ) ;
V_112 = V_40 -> V_9 . V_265 ;
if ( V_112 == & V_40 -> V_9 ) {
V_40 -> V_16 = 1 ;
V_112 = V_40 -> V_10 . V_265 ;
if ( V_112 == & V_40 -> V_10 )
goto V_281;
}
V_107 = F_197 ( V_112 , struct V_27 , V_164 ) ;
F_192 ( V_18 , V_118 ) ;
F_225 ( V_18 , V_107 ) ;
F_251 ( V_18 ) ;
F_228 ( V_18 ) ;
F_229 ( V_18 ) ;
F_12 ( V_107 -> V_204 == V_18 -> V_72 ) ;
V_24 = F_210 ( V_18 , V_107 , V_118 ) ;
F_225 ( V_18 , V_107 ) ;
V_40 -> V_15 -- ;
F_198 ( & V_107 -> V_164 ) ;
if ( V_107 -> free == V_264 )
F_124 ( & V_107 -> V_164 , & V_40 -> V_8 ) ;
else
F_124 ( & V_107 -> V_164 , & V_40 -> V_9 ) ;
F_94 ( & V_40 -> V_14 ) ;
goto V_298;
V_281:
F_94 ( & V_40 -> V_14 ) ;
T_3 = F_215 ( V_18 , V_19 | V_282 , V_118 , NULL ) ;
if ( T_3 )
goto V_278;
return F_242 ( V_18 , V_19 ) ;
V_298:
return V_24 ;
}
static T_1 void *
F_252 ( struct V_17 * V_18 , T_5 V_19 , int V_118 ,
unsigned long V_227 )
{
unsigned long V_299 ;
void * V_165 ;
int F_241 = F_69 () ;
V_19 &= V_300 ;
F_253 ( V_19 ) ;
if ( F_233 ( V_18 , V_19 ) )
return NULL ;
F_230 ( V_18 , V_19 ) ;
F_254 ( V_299 ) ;
if ( V_118 == V_301 )
V_118 = F_241 ;
if ( F_36 ( ! V_18 -> V_42 [ V_118 ] ) ) {
V_165 = F_242 ( V_18 , V_19 ) ;
goto V_110;
}
if ( V_118 == F_241 ) {
V_165 = F_235 ( V_18 , V_19 ) ;
if ( V_165 )
goto V_110;
}
V_165 = F_87 ( V_18 , V_19 , V_118 ) ;
V_110:
F_255 ( V_299 ) ;
V_165 = F_232 ( V_18 , V_19 , V_165 , V_227 ) ;
F_256 ( V_165 , V_18 -> V_183 , 1 , V_18 -> V_19 ,
V_19 ) ;
if ( F_99 ( V_165 ) )
F_257 ( V_18 , V_19 , V_165 , V_18 -> V_183 ) ;
if ( F_36 ( ( V_19 & V_302 ) && V_165 ) )
memset ( V_165 , 0 , V_18 -> V_183 ) ;
return V_165 ;
}
static T_1 void *
F_258 ( struct V_17 * V_29 , T_5 V_19 )
{
void * V_1 ;
if ( F_36 ( V_220 -> V_19 & ( V_303 | V_304 ) ) ) {
V_1 = F_86 ( V_29 , V_19 ) ;
if ( V_1 )
goto V_110;
}
V_1 = F_235 ( V_29 , V_19 ) ;
if ( ! V_1 )
V_1 = F_87 ( V_29 , V_19 , F_69 () ) ;
V_110:
return V_1 ;
}
static T_1 void *
F_258 ( struct V_17 * V_18 , T_5 V_19 )
{
return F_235 ( V_18 , V_19 ) ;
}
static T_1 void *
F_259 ( struct V_17 * V_18 , T_5 V_19 , unsigned long V_227 )
{
unsigned long V_299 ;
void * V_1 ;
V_19 &= V_300 ;
F_253 ( V_19 ) ;
if ( F_233 ( V_18 , V_19 ) )
return NULL ;
F_230 ( V_18 , V_19 ) ;
F_254 ( V_299 ) ;
V_1 = F_258 ( V_18 , V_19 ) ;
F_255 ( V_299 ) ;
V_1 = F_232 ( V_18 , V_19 , V_1 , V_227 ) ;
F_256 ( V_1 , V_18 -> V_183 , 1 , V_18 -> V_19 ,
V_19 ) ;
F_260 ( V_1 ) ;
if ( F_99 ( V_1 ) )
F_257 ( V_18 , V_19 , V_1 , V_18 -> V_183 ) ;
if ( F_36 ( ( V_19 & V_302 ) && V_1 ) )
memset ( V_1 , 0 , V_18 -> V_183 ) ;
return V_1 ;
}
static void F_93 ( struct V_17 * V_18 , void * * V_305 , int V_306 ,
int V_45 )
{
int V_5 ;
struct V_6 * V_40 ;
for ( V_5 = 0 ; V_5 < V_306 ; V_5 ++ ) {
void * V_1 ;
struct V_27 * V_107 ;
F_3 ( & V_305 [ V_5 ] ) ;
V_1 = V_305 [ V_5 ] ;
V_107 = F_17 ( V_1 ) ;
V_40 = V_18 -> V_42 [ V_45 ] ;
F_198 ( & V_107 -> V_164 ) ;
F_192 ( V_18 , V_45 ) ;
F_225 ( V_18 , V_107 ) ;
F_212 ( V_18 , V_107 , V_1 , V_45 ) ;
F_261 ( V_18 ) ;
V_40 -> V_15 ++ ;
F_225 ( V_18 , V_107 ) ;
if ( V_107 -> V_204 == 0 ) {
if ( V_40 -> V_15 > V_40 -> V_126 ) {
V_40 -> V_15 -= V_18 -> V_72 ;
F_174 ( V_18 , V_107 ) ;
} else {
F_124 ( & V_107 -> V_164 , & V_40 -> V_10 ) ;
}
} else {
F_218 ( & V_107 -> V_164 , & V_40 -> V_9 ) ;
}
}
}
static void F_262 ( struct V_17 * V_18 , struct V_38 * V_108 )
{
int V_100 ;
struct V_6 * V_40 ;
int V_45 = F_69 () ;
V_100 = V_108 -> V_100 ;
#if V_61
F_12 ( ! V_100 || V_100 > V_108 -> V_104 ) ;
#endif
F_186 () ;
V_40 = V_18 -> V_42 [ V_45 ] ;
F_92 ( & V_40 -> V_14 ) ;
if ( V_40 -> V_11 ) {
struct V_38 * V_307 = V_40 -> V_11 ;
int V_115 = V_307 -> V_105 - V_307 -> V_104 ;
if ( V_115 ) {
if ( V_100 > V_115 )
V_100 = V_115 ;
memcpy ( & ( V_307 -> V_112 [ V_307 -> V_104 ] ) ,
V_108 -> V_112 , sizeof( void * ) * V_100 ) ;
V_307 -> V_104 += V_100 ;
goto V_308;
}
}
F_93 ( V_18 , V_108 -> V_112 , V_100 , V_45 ) ;
V_308:
#if V_309
{
int V_5 = 0 ;
struct V_259 * V_260 ;
V_260 = V_40 -> V_10 . V_265 ;
while ( V_260 != & ( V_40 -> V_10 ) ) {
struct V_27 * V_107 ;
V_107 = F_197 ( V_260 , struct V_27 , V_164 ) ;
F_12 ( V_107 -> V_204 ) ;
V_5 ++ ;
V_260 = V_260 -> V_265 ;
}
F_263 ( V_18 , V_5 ) ;
}
#endif
F_94 ( & V_40 -> V_14 ) ;
V_108 -> V_104 -= V_100 ;
memmove ( V_108 -> V_112 , & ( V_108 -> V_112 [ V_100 ] ) , sizeof( void * ) * V_108 -> V_104 ) ;
}
static inline void F_264 ( struct V_17 * V_18 , void * V_1 ,
unsigned long V_227 )
{
struct V_38 * V_108 = F_32 ( V_18 ) ;
F_186 () ;
F_265 ( V_1 , V_18 -> V_19 ) ;
V_1 = F_223 ( V_18 , V_1 , V_227 ) ;
F_266 ( V_18 , V_1 , V_18 -> V_183 ) ;
if ( V_310 > 1 && F_85 ( V_18 , V_1 ) )
return;
if ( F_99 ( V_108 -> V_104 < V_108 -> V_105 ) ) {
F_267 ( V_18 ) ;
} else {
F_268 ( V_18 ) ;
F_262 ( V_18 , V_108 ) ;
}
F_80 ( V_18 , V_108 , V_1 ) ;
}
void * F_269 ( struct V_17 * V_18 , T_5 V_19 )
{
void * V_150 = F_259 ( V_18 , V_19 , V_311 ) ;
F_270 ( V_311 , V_150 ,
V_18 -> V_183 , V_18 -> V_3 , V_19 ) ;
return V_150 ;
}
void *
F_271 ( struct V_17 * V_18 , T_5 V_19 , T_2 V_3 )
{
void * V_150 ;
V_150 = F_259 ( V_18 , V_19 , V_311 ) ;
F_272 ( V_311 , V_150 ,
V_3 , V_18 -> V_3 , V_19 ) ;
return V_150 ;
}
void * F_205 ( struct V_17 * V_18 , T_5 V_19 , int V_118 )
{
void * V_150 = F_252 ( V_18 , V_19 , V_118 , V_311 ) ;
F_273 ( V_311 , V_150 ,
V_18 -> V_183 , V_18 -> V_3 ,
V_19 , V_118 ) ;
return V_150 ;
}
void * F_274 ( struct V_17 * V_18 ,
T_5 V_19 ,
int V_118 ,
T_2 V_3 )
{
void * V_150 ;
V_150 = F_252 ( V_18 , V_19 , V_118 , V_311 ) ;
F_275 ( V_311 , V_150 ,
V_3 , V_18 -> V_3 ,
V_19 , V_118 ) ;
return V_150 ;
}
static T_1 void *
F_276 ( T_2 V_3 , T_5 V_19 , int V_45 , unsigned long V_227 )
{
struct V_17 * V_18 ;
V_18 = F_37 ( V_3 , V_19 ) ;
if ( F_36 ( F_183 ( V_18 ) ) )
return V_18 ;
return F_274 ( V_18 , V_19 , V_45 , V_3 ) ;
}
void * F_277 ( T_2 V_3 , T_5 V_19 , int V_45 )
{
return F_276 ( V_3 , V_19 , V_45 , V_311 ) ;
}
void * F_278 ( T_2 V_3 , T_5 V_19 ,
int V_45 , unsigned long V_227 )
{
return F_276 ( V_3 , V_19 , V_45 , V_227 ) ;
}
void * F_277 ( T_2 V_3 , T_5 V_19 , int V_45 )
{
return F_276 ( V_3 , V_19 , V_45 , 0 ) ;
}
static T_1 void * F_279 ( T_2 V_3 , T_5 V_19 ,
unsigned long V_227 )
{
struct V_17 * V_18 ;
void * V_150 ;
V_18 = F_34 ( V_3 , V_19 ) ;
if ( F_36 ( F_183 ( V_18 ) ) )
return V_18 ;
V_150 = F_259 ( V_18 , V_19 , V_227 ) ;
F_272 ( V_227 , V_150 ,
V_3 , V_18 -> V_3 , V_19 ) ;
return V_150 ;
}
void * F_280 ( T_2 V_3 , T_5 V_19 )
{
return F_279 ( V_3 , V_19 , V_311 ) ;
}
void * F_281 ( T_2 V_3 , T_5 V_19 , unsigned long V_227 )
{
return F_279 ( V_3 , V_19 , V_227 ) ;
}
void * F_280 ( T_2 V_3 , T_5 V_19 )
{
return F_279 ( V_3 , V_19 , 0 ) ;
}
void F_158 ( struct V_17 * V_18 , void * V_1 )
{
unsigned long V_19 ;
F_254 ( V_19 ) ;
F_282 ( V_1 , V_18 -> V_183 ) ;
if ( ! ( V_18 -> V_19 & V_132 ) )
F_283 ( V_1 , V_18 -> V_183 ) ;
F_264 ( V_18 , V_1 , V_311 ) ;
F_255 ( V_19 ) ;
F_284 ( V_311 , V_1 ) ;
}
void F_90 ( const void * V_1 )
{
struct V_17 * V_312 ;
unsigned long V_19 ;
F_285 ( V_311 , V_1 ) ;
if ( F_36 ( F_183 ( V_1 ) ) )
return;
F_254 ( V_19 ) ;
F_220 ( V_1 ) ;
V_312 = F_15 ( V_1 ) ;
F_282 ( V_1 , V_312 -> V_183 ) ;
F_283 ( V_1 , V_312 -> V_183 ) ;
F_264 ( V_312 , ( void * ) V_1 , V_311 ) ;
F_255 ( V_19 ) ;
}
unsigned int F_286 ( struct V_17 * V_18 )
{
return V_18 -> V_183 ;
}
static int F_287 ( struct V_17 * V_18 , T_5 V_101 )
{
int V_45 ;
struct V_6 * V_40 ;
struct V_38 * V_313 ;
struct V_38 * * V_314 = NULL ;
F_28 (node) {
if ( V_83 ) {
V_314 = F_83 ( V_45 , V_18 -> V_105 , V_101 ) ;
if ( ! V_314 )
goto V_315;
}
V_313 = NULL ;
if ( V_18 -> V_11 ) {
V_313 = F_62 ( V_45 ,
V_18 -> V_11 * V_18 -> V_100 ,
0xbaadf00d , V_101 ) ;
if ( ! V_313 ) {
F_84 ( V_314 ) ;
goto V_315;
}
}
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( V_40 ) {
struct V_38 * V_11 = V_40 -> V_11 ;
F_103 ( & V_40 -> V_14 ) ;
if ( V_11 )
F_93 ( V_18 , V_11 -> V_112 ,
V_11 -> V_104 , V_45 ) ;
V_40 -> V_11 = V_313 ;
if ( ! V_40 -> V_12 ) {
V_40 -> V_12 = V_314 ;
V_314 = NULL ;
}
V_40 -> V_126 = ( 1 + F_104 ( V_45 ) ) *
V_18 -> V_100 + V_18 -> V_72 ;
F_97 ( & V_40 -> V_14 ) ;
F_90 ( V_11 ) ;
F_84 ( V_314 ) ;
continue;
}
V_40 = F_63 ( sizeof( struct V_6 ) , V_101 , V_45 ) ;
if ( ! V_40 ) {
F_84 ( V_314 ) ;
F_90 ( V_313 ) ;
goto V_315;
}
F_7 ( V_40 ) ;
V_40 -> V_123 = V_124 + V_125 +
( ( unsigned long ) V_18 ) % V_125 ;
V_40 -> V_11 = V_313 ;
V_40 -> V_12 = V_314 ;
V_40 -> V_126 = ( 1 + F_104 ( V_45 ) ) *
V_18 -> V_100 + V_18 -> V_72 ;
V_18 -> V_42 [ V_45 ] = V_40 ;
}
return 0 ;
V_315:
if ( ! V_18 -> V_164 . V_265 ) {
V_45 -- ;
while ( V_45 >= 0 ) {
if ( V_18 -> V_42 [ V_45 ] ) {
V_40 = V_18 -> V_42 [ V_45 ] ;
F_90 ( V_40 -> V_11 ) ;
F_84 ( V_40 -> V_12 ) ;
F_90 ( V_40 ) ;
V_18 -> V_42 [ V_45 ] = NULL ;
}
V_45 -- ;
}
}
return - V_122 ;
}
static void F_288 ( void * V_316 )
{
struct V_317 * V_318 = V_316 ;
struct V_38 * V_319 ;
F_186 () ;
V_319 = F_32 ( V_318 -> V_18 ) ;
V_318 -> V_18 -> V_58 [ F_33 () ] = V_318 -> V_318 [ F_33 () ] ;
V_318 -> V_318 [ F_33 () ] = V_319 ;
}
static int F_289 ( struct V_17 * V_18 , int V_105 ,
int V_100 , int V_11 , T_5 V_101 )
{
struct V_317 * V_318 ;
int V_5 ;
V_318 = F_290 ( sizeof( * V_318 ) + V_182 * sizeof( struct V_38 * ) ,
V_101 ) ;
if ( ! V_318 )
return - V_122 ;
F_137 (i) {
V_318 -> V_318 [ V_5 ] = F_62 ( F_51 ( V_5 ) , V_105 ,
V_100 , V_101 ) ;
if ( ! V_318 -> V_318 [ V_5 ] ) {
for ( V_5 -- ; V_5 >= 0 ; V_5 -- )
F_90 ( V_318 -> V_318 [ V_5 ] ) ;
F_90 ( V_318 ) ;
return - V_122 ;
}
}
V_318 -> V_18 = V_18 ;
F_195 ( F_288 , ( void * ) V_318 , 1 ) ;
F_188 () ;
V_18 -> V_100 = V_100 ;
V_18 -> V_105 = V_105 ;
V_18 -> V_11 = V_11 ;
F_137 (i) {
struct V_38 * V_320 = V_318 -> V_318 [ V_5 ] ;
if ( ! V_320 )
continue;
F_103 ( & V_18 -> V_42 [ F_51 ( V_5 ) ] -> V_14 ) ;
F_93 ( V_18 , V_320 -> V_112 , V_320 -> V_104 , F_51 ( V_5 ) ) ;
F_97 ( & V_18 -> V_42 [ F_51 ( V_5 ) ] -> V_14 ) ;
F_90 ( V_320 ) ;
}
F_90 ( V_318 ) ;
return F_287 ( V_18 , V_101 ) ;
}
static int F_132 ( struct V_17 * V_18 , T_5 V_101 )
{
int V_130 ;
int V_105 , V_11 ;
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
if ( V_18 -> V_3 <= V_75 && F_291 () > 1 )
V_11 = 8 ;
#if V_61
if ( V_105 > 32 )
V_105 = 32 ;
#endif
V_130 = F_289 ( V_18 , V_105 , ( V_105 + 1 ) / 2 , V_11 , V_101 ) ;
if ( V_130 )
F_42 ( V_80 L_37 ,
V_18 -> V_81 , - V_130 ) ;
return V_130 ;
}
static void F_196 ( struct V_17 * V_18 , struct V_6 * V_40 ,
struct V_38 * V_108 , int V_321 , int V_45 )
{
int V_258 ;
if ( ! V_108 || ! V_108 -> V_104 )
return;
if ( V_108 -> V_106 && ! V_321 ) {
V_108 -> V_106 = 0 ;
} else {
F_103 ( & V_40 -> V_14 ) ;
if ( V_108 -> V_104 ) {
V_258 = V_321 ? V_108 -> V_104 : ( V_108 -> V_105 + 4 ) / 5 ;
if ( V_258 > V_108 -> V_104 )
V_258 = ( V_108 -> V_104 + 1 ) / 2 ;
F_93 ( V_18 , V_108 -> V_112 , V_258 , V_45 ) ;
V_108 -> V_104 -= V_258 ;
memmove ( V_108 -> V_112 , & ( V_108 -> V_112 [ V_258 ] ) ,
sizeof( void * ) * V_108 -> V_104 ) ;
}
F_97 ( & V_40 -> V_14 ) ;
}
}
static void V_97 ( struct V_322 * V_323 )
{
struct V_17 * V_324 ;
struct V_6 * V_40 ;
int V_45 = F_69 () ;
struct V_92 * V_95 = F_292 ( V_323 ) ;
if ( ! F_293 ( & V_139 ) )
goto V_110;
F_71 (searchp, &slab_caches, list) {
F_188 () ;
V_40 = V_324 -> V_42 [ V_45 ] ;
F_95 ( V_324 , V_40 ) ;
F_196 ( V_324 , V_40 , F_32 ( V_324 ) , 0 , V_45 ) ;
if ( F_294 ( V_40 -> V_123 , V_124 ) )
goto V_265;
V_40 -> V_123 = V_124 + V_125 ;
F_196 ( V_324 , V_40 , V_40 -> V_11 , 0 , V_45 ) ;
if ( V_40 -> V_16 )
V_40 -> V_16 = 0 ;
else {
int V_325 ;
V_325 = F_108 ( V_324 , V_40 , ( V_40 -> V_126 +
5 * V_324 -> V_72 - 1 ) / ( 5 * V_324 -> V_72 ) ) ;
F_295 ( V_324 , V_325 ) ;
}
V_265:
F_296 () ;
}
F_188 () ;
F_113 ( & V_139 ) ;
F_54 () ;
V_110:
F_297 ( V_95 , F_298 ( V_326 ) ) ;
}
static void F_299 ( struct V_327 * V_328 )
{
#if V_309
F_300 ( V_328 , L_38 ) ;
#else
F_300 ( V_328 , L_39 ) ;
#endif
F_300 ( V_328 , L_40
L_41 ) ;
F_300 ( V_328 , L_42 ) ;
F_300 ( V_328 , L_43 ) ;
#if V_309
F_300 ( V_328 , L_44
L_45 ) ;
F_300 ( V_328 , L_46 ) ;
#endif
F_301 ( V_328 , '\n' ) ;
}
static void * F_302 ( struct V_327 * V_328 , T_11 * V_329 )
{
T_11 V_330 = * V_329 ;
F_112 ( & V_139 ) ;
if ( ! V_330 )
F_299 ( V_328 ) ;
return F_303 ( & V_179 , * V_329 ) ;
}
static void * F_304 ( struct V_327 * V_328 , void * V_260 , T_11 * V_329 )
{
return F_305 ( V_260 , & V_179 , V_329 ) ;
}
static void F_306 ( struct V_327 * V_328 , void * V_260 )
{
F_113 ( & V_139 ) ;
}
static int F_307 ( struct V_327 * V_328 , void * V_260 )
{
struct V_17 * V_18 = F_197 ( V_260 , struct V_17 , V_164 ) ;
struct V_27 * V_107 ;
unsigned long V_200 ;
unsigned long V_201 ;
unsigned long V_202 = 0 ;
unsigned long V_203 , V_15 = 0 , V_331 = 0 ;
const char * V_81 ;
char * error = NULL ;
int V_45 ;
struct V_6 * V_40 ;
V_200 = 0 ;
V_203 = 0 ;
F_28 (node) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_188 () ;
F_103 ( & V_40 -> V_14 ) ;
F_71 (slabp, &l3->slabs_full, list) {
if ( V_107 -> V_204 != V_18 -> V_72 && ! error )
error = L_47 ;
V_200 += V_18 -> V_72 ;
V_202 ++ ;
}
F_71 (slabp, &l3->slabs_partial, list) {
if ( V_107 -> V_204 == V_18 -> V_72 && ! error )
error = L_48 ;
if ( ! V_107 -> V_204 && ! error )
error = L_49 ;
V_200 += V_107 -> V_204 ;
V_202 ++ ;
}
F_71 (slabp, &l3->slabs_free, list) {
if ( V_107 -> V_204 && ! error )
error = L_50 ;
V_203 ++ ;
}
V_15 += V_40 -> V_15 ;
if ( V_40 -> V_11 )
V_331 += V_40 -> V_11 -> V_104 ;
F_97 ( & V_40 -> V_14 ) ;
}
V_203 += V_202 ;
V_201 = V_203 * V_18 -> V_72 ;
if ( V_201 - V_200 != V_15 && ! error )
error = L_51 ;
V_81 = V_18 -> V_81 ;
if ( error )
F_42 ( V_80 L_52 , V_81 , error ) ;
F_308 ( V_328 , L_53 ,
V_81 , V_200 , V_201 , V_18 -> V_3 ,
V_18 -> V_72 , ( 1 << V_18 -> V_69 ) ) ;
F_308 ( V_328 , L_54 ,
V_18 -> V_105 , V_18 -> V_100 , V_18 -> V_11 ) ;
F_308 ( V_328 , L_55 ,
V_202 , V_203 , V_331 ) ;
#if V_309
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
F_308 ( V_328 , L_56
L_57 ,
V_334 , V_332 , V_336 ,
V_337 , V_338 , V_339 , V_340 ,
V_341 , V_342 ) ;
}
{
unsigned long V_344 = F_309 ( & V_18 -> V_344 ) ;
unsigned long V_345 = F_309 ( & V_18 -> V_345 ) ;
unsigned long V_346 = F_309 ( & V_18 -> V_346 ) ;
unsigned long V_347 = F_309 ( & V_18 -> V_347 ) ;
F_308 ( V_328 , L_58 ,
V_344 , V_345 , V_346 , V_347 ) ;
}
#endif
F_301 ( V_328 , '\n' ) ;
return 0 ;
}
static T_12 F_310 ( struct V_348 * V_348 , const char T_13 * V_349 ,
T_2 V_350 , T_11 * V_351 )
{
char V_352 [ V_353 + 1 ] , * V_354 ;
int V_105 , V_100 , V_11 , V_355 ;
struct V_17 * V_18 ;
if ( V_350 > V_353 )
return - V_356 ;
if ( F_311 ( & V_352 , V_349 , V_350 ) )
return - V_357 ;
V_352 [ V_353 ] = '\0' ;
V_354 = strchr ( V_352 , ' ' ) ;
if ( ! V_354 )
return - V_356 ;
* V_354 = '\0' ;
V_354 ++ ;
if ( sscanf ( V_354 , L_59 , & V_105 , & V_100 , & V_11 ) != 3 )
return - V_356 ;
F_112 ( & V_139 ) ;
V_355 = - V_356 ;
F_71 (cachep, &slab_caches, list) {
if ( ! strcmp ( V_18 -> V_81 , V_352 ) ) {
if ( V_105 < 1 || V_100 < 1 ||
V_100 > V_105 || V_11 < 0 ) {
V_355 = 0 ;
} else {
V_355 = F_289 ( V_18 , V_105 ,
V_100 , V_11 ,
V_121 ) ;
}
break;
}
}
F_113 ( & V_139 ) ;
if ( V_355 >= 0 )
V_355 = V_350 ;
return V_355 ;
}
static int F_312 ( struct V_358 * V_358 , struct V_348 * V_348 )
{
return F_313 ( V_348 , & V_359 ) ;
}
static void * F_314 ( struct V_327 * V_328 , T_11 * V_329 )
{
F_112 ( & V_139 ) ;
return F_303 ( & V_179 , * V_329 ) ;
}
static inline int F_315 ( unsigned long * V_330 , unsigned long V_360 )
{
unsigned long * V_260 ;
int V_361 ;
if ( ! V_360 )
return 1 ;
V_361 = V_330 [ 1 ] ;
V_260 = V_330 + 2 ;
while ( V_361 ) {
int V_5 = V_361 / 2 ;
unsigned long * V_37 = V_260 + 2 * V_5 ;
if ( * V_37 == V_360 ) {
V_37 [ 1 ] ++ ;
return 1 ;
}
if ( * V_37 > V_360 ) {
V_361 = V_5 ;
} else {
V_260 = V_37 + 2 ;
V_361 -= V_5 + 1 ;
}
}
if ( ++ V_330 [ 1 ] == V_330 [ 0 ] )
return 0 ;
memmove ( V_260 + 2 , V_260 , V_330 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_260 - ( void * ) V_330 ) ) ;
V_260 [ 0 ] = V_360 ;
V_260 [ 1 ] = 1 ;
return 1 ;
}
static void F_316 ( unsigned long * V_330 , struct V_17 * V_312 , struct V_27 * V_49 )
{
void * V_260 ;
int V_5 ;
if ( V_330 [ 0 ] == V_330 [ 1 ] )
return;
for ( V_5 = 0 , V_260 = V_49 -> V_31 ; V_5 < V_312 -> V_72 ; V_5 ++ , V_260 += V_312 -> V_3 ) {
if ( F_207 ( V_49 ) [ V_5 ] != V_284 )
continue;
if ( ! F_315 ( V_330 , ( unsigned long ) * F_14 ( V_312 , V_260 ) ) )
return;
}
}
static void F_317 ( struct V_327 * V_328 , unsigned long V_362 )
{
#ifdef F_318
unsigned long V_32 , V_3 ;
char V_363 [ V_364 ] , V_81 [ V_365 ] ;
if ( F_319 ( V_362 , & V_3 , & V_32 , V_363 , V_81 ) == 0 ) {
F_308 ( V_328 , L_60 , V_81 , V_32 , V_3 ) ;
if ( V_363 [ 0 ] )
F_308 ( V_328 , L_61 , V_363 ) ;
return;
}
#endif
F_308 ( V_328 , L_62 , ( void * ) V_362 ) ;
}
static int F_320 ( struct V_327 * V_328 , void * V_260 )
{
struct V_17 * V_18 = F_197 ( V_260 , struct V_17 , V_164 ) ;
struct V_27 * V_107 ;
struct V_6 * V_40 ;
const char * V_81 ;
unsigned long * V_330 = V_328 -> V_366 ;
int V_45 ;
int V_5 ;
if ( ! ( V_18 -> V_19 & V_21 ) )
return 0 ;
if ( ! ( V_18 -> V_19 & V_20 ) )
return 0 ;
V_330 [ 1 ] = 0 ;
F_28 (node) {
V_40 = V_18 -> V_42 [ V_45 ] ;
if ( ! V_40 )
continue;
F_188 () ;
F_103 ( & V_40 -> V_14 ) ;
F_71 (slabp, &l3->slabs_full, list)
F_316 ( V_330 , V_18 , V_107 ) ;
F_71 (slabp, &l3->slabs_partial, list)
F_316 ( V_330 , V_18 , V_107 ) ;
F_97 ( & V_40 -> V_14 ) ;
}
V_81 = V_18 -> V_81 ;
if ( V_330 [ 0 ] == V_330 [ 1 ] ) {
F_113 ( & V_139 ) ;
V_328 -> V_366 = F_290 ( V_330 [ 0 ] * 4 * sizeof( unsigned long ) , V_121 ) ;
if ( ! V_328 -> V_366 ) {
V_328 -> V_366 = V_330 ;
F_112 ( & V_139 ) ;
return - V_122 ;
}
* ( unsigned long * ) V_328 -> V_366 = V_330 [ 0 ] * 2 ;
F_90 ( V_330 ) ;
F_112 ( & V_139 ) ;
V_328 -> V_350 = V_328 -> V_3 ;
return 0 ;
}
for ( V_5 = 0 ; V_5 < V_330 [ 1 ] ; V_5 ++ ) {
F_308 ( V_328 , L_63 , V_81 , V_330 [ 2 * V_5 + 3 ] ) ;
F_317 ( V_328 , V_330 [ 2 * V_5 + 2 ] ) ;
F_301 ( V_328 , '\n' ) ;
}
return 0 ;
}
static int F_321 ( struct V_358 * V_358 , struct V_348 * V_348 )
{
unsigned long * V_330 = F_290 ( V_75 , V_121 ) ;
int V_150 = - V_122 ;
if ( V_330 ) {
V_150 = F_313 ( V_348 , & V_367 ) ;
if ( ! V_150 ) {
struct V_327 * V_328 = V_348 -> V_368 ;
* V_330 = V_75 / ( 2 * sizeof( unsigned long ) ) ;
V_328 -> V_366 = V_330 ;
V_330 = NULL ;
}
F_90 ( V_330 ) ;
}
return V_150 ;
}
static int T_6 F_322 ( void )
{
F_323 ( L_64 , V_369 | V_370 , NULL , & V_371 ) ;
#ifdef F_224
F_323 ( L_65 , 0 , NULL , & V_372 ) ;
#endif
return 0 ;
}
T_2 F_324 ( const void * V_1 )
{
F_12 ( ! V_1 ) ;
if ( F_36 ( V_1 == V_63 ) )
return 0 ;
return F_15 ( V_1 ) -> V_183 ;
}
