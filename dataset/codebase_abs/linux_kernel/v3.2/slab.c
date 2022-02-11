static T_1 int F_1 ( const T_2 V_1 )
{
extern void V_2 ( void ) ;
if ( F_2 ( V_1 ) ) {
int V_3 = 0 ;
#define F_3 ( T_3 ) \
if (size <=x) \
return i; \
else \
i++;
#include <linux/kmalloc_sizes.h>
#undef F_3
V_2 () ;
} else
V_2 () ;
return 0 ;
}
static void F_4 ( struct V_4 * V_5 )
{
F_5 ( & V_5 -> V_6 ) ;
F_5 ( & V_5 -> V_7 ) ;
F_5 ( & V_5 -> V_8 ) ;
V_5 -> V_9 = NULL ;
V_5 -> V_10 = NULL ;
V_5 -> V_11 = 0 ;
F_6 ( & V_5 -> V_12 ) ;
V_5 -> V_13 = 0 ;
V_5 -> V_14 = 0 ;
}
static int F_7 ( struct V_15 * V_16 )
{
return V_16 -> F_7 ;
}
static int F_8 ( struct V_15 * V_16 )
{
return V_16 -> F_8 ;
}
static unsigned long long * F_9 ( struct V_15 * V_16 , void * V_17 )
{
F_10 ( ! ( V_16 -> V_18 & V_19 ) ) ;
return ( unsigned long long * ) ( V_17 + F_7 ( V_16 ) -
sizeof( unsigned long long ) ) ;
}
static unsigned long long * F_11 ( struct V_15 * V_16 , void * V_17 )
{
F_10 ( ! ( V_16 -> V_18 & V_19 ) ) ;
if ( V_16 -> V_18 & V_20 )
return ( unsigned long long * ) ( V_17 + V_16 -> V_21 -
sizeof( unsigned long long ) -
V_22 ) ;
return ( unsigned long long * ) ( V_17 + V_16 -> V_21 -
sizeof( unsigned long long ) ) ;
}
static void * * F_12 ( struct V_15 * V_16 , void * V_17 )
{
F_10 ( ! ( V_16 -> V_18 & V_20 ) ) ;
return ( void * * ) ( V_17 + V_16 -> V_21 - V_23 ) ;
}
T_2 F_13 ( struct V_15 * V_16 )
{
return V_16 -> V_21 ;
}
static inline void F_14 ( struct V_24 * V_24 , struct V_15 * V_25 )
{
V_24 -> V_26 . V_27 = (struct V_28 * ) V_25 ;
}
static inline struct V_15 * F_15 ( struct V_24 * V_24 )
{
V_24 = F_16 ( V_24 ) ;
F_10 ( ! F_17 ( V_24 ) ) ;
return (struct V_15 * ) V_24 -> V_26 . V_27 ;
}
static inline void F_18 ( struct V_24 * V_24 , struct V_29 * V_29 )
{
V_24 -> V_26 . V_30 = (struct V_28 * ) V_29 ;
}
static inline struct V_29 * F_19 ( struct V_24 * V_24 )
{
F_10 ( ! F_17 ( V_24 ) ) ;
return (struct V_29 * ) V_24 -> V_26 . V_30 ;
}
static inline struct V_15 * F_20 ( const void * V_31 )
{
struct V_24 * V_24 = F_21 ( V_31 ) ;
return F_15 ( V_24 ) ;
}
static inline struct V_29 * F_22 ( const void * V_31 )
{
struct V_24 * V_24 = F_21 ( V_31 ) ;
return F_19 ( V_24 ) ;
}
static inline void * F_23 ( struct V_15 * V_25 , struct V_29 * V_29 ,
unsigned int V_32 )
{
return V_29 -> V_33 + V_25 -> V_21 * V_32 ;
}
static inline unsigned int F_24 ( const struct V_15 * V_25 ,
const struct V_29 * V_29 , void * V_31 )
{
T_4 V_34 = ( V_31 - V_29 -> V_33 ) ;
return F_25 ( V_34 , V_25 -> V_35 ) ;
}
int F_26 ( void )
{
return V_36 >= V_37 ;
}
static void F_27 ( struct V_15 * V_16 ,
struct V_38 * V_39 , struct V_38 * V_40 ,
int V_41 )
{
struct V_42 * * V_43 ;
struct V_4 * V_44 ;
int V_45 ;
V_44 = V_16 -> V_46 [ V_41 ] ;
if ( ! V_44 )
return;
F_28 ( & V_44 -> V_12 , V_39 ) ;
V_43 = V_44 -> V_10 ;
if ( ! V_43 || ( unsigned long ) V_43 == V_47 )
return;
F_29 (r) {
if ( V_43 [ V_45 ] )
F_28 ( & V_43 [ V_45 ] -> V_48 , V_40 ) ;
}
}
static void F_30 ( struct V_15 * V_16 , int V_49 )
{
F_27 ( V_16 , & V_50 , & V_51 , V_49 ) ;
}
static void F_31 ( struct V_15 * V_16 )
{
int V_49 ;
F_32 (node)
F_30 ( V_16 , V_49 ) ;
}
static void F_33 ( int V_41 )
{
struct V_52 * V_53 = V_54 ;
if ( V_36 < V_55 )
return;
for ( V_53 = V_54 ; V_53 -> V_56 != V_57 ; V_53 ++ ) {
struct V_4 * V_44 ;
V_44 = V_53 -> V_58 -> V_46 [ V_41 ] ;
if ( ! V_44 || F_34 ( V_53 -> V_58 ) )
continue;
F_27 ( V_53 -> V_58 , & V_59 ,
& V_60 , V_41 ) ;
}
}
static inline void F_35 ( void )
{
int V_49 ;
F_29 (node)
F_33 ( V_49 ) ;
}
static void F_33 ( int V_41 )
{
}
static inline void F_35 ( void )
{
}
static void F_30 ( struct V_15 * V_16 , int V_49 )
{
}
static void F_31 ( struct V_15 * V_16 )
{
}
static inline struct V_42 * F_36 ( struct V_15 * V_16 )
{
return V_16 -> V_61 [ F_37 () ] ;
}
static inline struct V_15 * F_38 ( T_2 V_1 ,
T_5 V_62 )
{
struct V_52 * V_63 = V_54 ;
#if V_64
F_10 ( V_54 [ V_65 ] . V_58 == NULL ) ;
#endif
if ( ! V_1 )
return V_66 ;
while ( V_1 > V_63 -> V_56 )
V_63 ++ ;
#ifdef F_39
if ( F_40 ( V_62 & V_67 ) )
return V_63 -> V_68 ;
#endif
return V_63 -> V_58 ;
}
static struct V_15 * F_41 ( T_2 V_1 , T_5 V_62 )
{
return F_38 ( V_1 , V_62 ) ;
}
static T_2 F_42 ( T_2 V_69 , T_2 V_70 )
{
return F_43 ( sizeof( struct V_29 ) + V_69 * sizeof( V_71 ) , V_70 ) ;
}
static void F_44 ( unsigned long V_72 , T_2 V_21 ,
T_2 V_70 , int V_18 , T_2 * V_73 ,
unsigned int * V_74 )
{
int V_69 ;
T_2 V_75 ;
T_2 V_76 = V_77 << V_72 ;
if ( V_18 & V_78 ) {
V_75 = 0 ;
V_69 = V_76 / V_21 ;
if ( V_69 > V_79 )
V_69 = V_79 ;
} else {
V_69 = ( V_76 - sizeof( struct V_29 ) ) /
( V_21 + sizeof( V_71 ) ) ;
if ( F_42 ( V_69 , V_70 ) + V_69 * V_21
> V_76 )
V_69 -- ;
if ( V_69 > V_79 )
V_69 = V_79 ;
V_75 = F_42 ( V_69 , V_70 ) ;
}
* V_74 = V_69 ;
* V_73 = V_76 - V_69 * V_21 - V_75 ;
}
static void F_45 ( const char * V_80 , struct V_15 * V_16 ,
char * V_81 )
{
F_46 ( V_82 L_1 ,
V_80 , V_16 -> V_83 , V_81 ) ;
F_47 () ;
}
static int T_6 F_48 ( char * V_53 )
{
V_84 = 0 ;
return 1 ;
}
static void F_49 ( int V_85 )
{
int V_49 ;
V_49 = F_50 ( F_51 ( V_85 ) , V_86 ) ;
if ( V_49 == V_87 )
V_49 = F_52 ( V_86 ) ;
F_53 ( V_88 , V_85 ) = V_49 ;
}
static void F_54 ( void )
{
int V_49 = F_55 ( V_88 ) ;
V_49 = F_50 ( V_49 , V_86 ) ;
if ( F_40 ( V_49 >= V_87 ) )
V_49 = F_52 ( V_86 ) ;
F_56 ( V_88 , V_49 ) ;
}
static void T_7 F_57 ( int V_85 )
{
struct V_89 * V_90 = & F_53 ( V_91 , V_85 ) ;
if ( F_58 () && V_90 -> V_92 . V_93 == NULL ) {
F_49 ( V_85 ) ;
F_59 ( V_90 , V_94 ) ;
F_60 ( V_85 , V_90 ,
F_61 ( V_95 , V_85 ) ) ;
}
}
static struct V_42 * F_62 ( int V_49 , int V_96 ,
int V_97 , T_5 V_98 )
{
int V_99 = sizeof( void * ) * V_96 + sizeof( struct V_42 ) ;
struct V_42 * V_100 = NULL ;
V_100 = F_63 ( V_99 , V_98 , V_49 ) ;
F_64 ( V_100 ) ;
if ( V_100 ) {
V_100 -> V_101 = 0 ;
V_100 -> V_102 = V_96 ;
V_100 -> V_97 = V_97 ;
V_100 -> V_103 = 0 ;
F_6 ( & V_100 -> V_48 ) ;
}
return V_100 ;
}
static int F_65 ( struct V_42 * V_104 ,
struct V_42 * V_105 , unsigned int V_106 )
{
int V_107 = F_66 ( V_105 -> V_101 , V_106 , V_104 -> V_102 - V_104 -> V_101 ) ;
if ( ! V_107 )
return 0 ;
memcpy ( V_104 -> V_108 + V_104 -> V_101 , V_105 -> V_108 + V_105 -> V_101 - V_107 ,
sizeof( void * ) * V_107 ) ;
V_105 -> V_101 -= V_107 ;
V_104 -> V_101 += V_107 ;
return V_107 ;
}
static inline struct V_42 * * F_67 ( int V_49 , int V_102 , T_5 V_98 )
{
return (struct V_42 * * ) V_47 ;
}
static inline void F_68 ( struct V_42 * * V_109 )
{
}
static inline int F_69 ( struct V_15 * V_16 , void * V_17 )
{
return 0 ;
}
static inline void * F_70 ( struct V_15 * V_16 ,
T_5 V_18 )
{
return NULL ;
}
static inline void * F_71 ( struct V_15 * V_16 ,
T_5 V_18 , int V_110 )
{
return NULL ;
}
static struct V_42 * * F_67 ( int V_49 , int V_102 , T_5 V_98 )
{
struct V_42 * * V_109 ;
int V_99 = sizeof( void * ) * V_111 ;
int V_3 ;
if ( V_102 > 1 )
V_102 = 12 ;
V_109 = F_72 ( V_99 , V_98 , V_49 ) ;
if ( V_109 ) {
F_29 (i) {
if ( V_3 == V_49 || ! F_73 ( V_3 ) )
continue;
V_109 [ V_3 ] = F_62 ( V_49 , V_102 , 0xbaadf00d , V_98 ) ;
if ( ! V_109 [ V_3 ] ) {
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_74 ( V_109 [ V_3 ] ) ;
F_74 ( V_109 ) ;
return NULL ;
}
}
}
return V_109 ;
}
static void F_68 ( struct V_42 * * V_109 )
{
int V_3 ;
if ( ! V_109 )
return;
F_29 (i)
F_74 ( V_109 [ V_3 ] ) ;
F_74 ( V_109 ) ;
}
static void F_75 ( struct V_15 * V_16 ,
struct V_42 * V_112 , int V_49 )
{
struct V_4 * V_113 = V_16 -> V_46 [ V_49 ] ;
if ( V_112 -> V_101 ) {
F_76 ( & V_113 -> V_12 ) ;
if ( V_113 -> V_9 )
F_65 ( V_113 -> V_9 , V_112 , V_112 -> V_102 ) ;
F_77 ( V_16 , V_112 -> V_108 , V_112 -> V_101 , V_49 ) ;
V_112 -> V_101 = 0 ;
F_78 ( & V_113 -> V_12 ) ;
}
}
static void F_79 ( struct V_15 * V_16 , struct V_4 * V_44 )
{
int V_49 = F_55 ( V_88 ) ;
if ( V_44 -> V_10 ) {
struct V_42 * V_112 = V_44 -> V_10 [ V_49 ] ;
if ( V_112 && V_112 -> V_101 && F_80 ( & V_112 -> V_48 ) ) {
F_75 ( V_16 , V_112 , V_49 ) ;
F_81 ( & V_112 -> V_48 ) ;
}
}
}
static void F_82 ( struct V_15 * V_16 ,
struct V_42 * * V_10 )
{
int V_3 = 0 ;
struct V_42 * V_112 ;
unsigned long V_18 ;
F_32 (i) {
V_112 = V_10 [ V_3 ] ;
if ( V_112 ) {
F_83 ( & V_112 -> V_48 , V_18 ) ;
F_75 ( V_16 , V_112 , V_3 ) ;
F_84 ( & V_112 -> V_48 , V_18 ) ;
}
}
}
static inline int F_69 ( struct V_15 * V_16 , void * V_17 )
{
struct V_29 * V_114 = F_22 ( V_17 ) ;
int V_110 = V_114 -> V_110 ;
struct V_4 * V_44 ;
struct V_42 * V_10 = NULL ;
int V_49 ;
V_49 = F_85 () ;
if ( F_86 ( V_114 -> V_110 == V_49 ) )
return 0 ;
V_44 = V_16 -> V_46 [ V_49 ] ;
F_87 ( V_16 ) ;
if ( V_44 -> V_10 && V_44 -> V_10 [ V_110 ] ) {
V_10 = V_44 -> V_10 [ V_110 ] ;
F_76 ( & V_10 -> V_48 ) ;
if ( F_40 ( V_10 -> V_101 == V_10 -> V_102 ) ) {
F_88 ( V_16 ) ;
F_75 ( V_16 , V_10 , V_110 ) ;
}
V_10 -> V_108 [ V_10 -> V_101 ++ ] = V_17 ;
F_78 ( & V_10 -> V_48 ) ;
} else {
F_76 ( & ( V_16 -> V_46 [ V_110 ] ) -> V_12 ) ;
F_77 ( V_16 , & V_17 , 1 , V_110 ) ;
F_78 ( & ( V_16 -> V_46 [ V_110 ] ) -> V_12 ) ;
}
return 1 ;
}
static int F_89 ( int V_49 )
{
struct V_15 * V_16 ;
struct V_4 * V_44 ;
const int V_99 = sizeof( struct V_4 ) ;
F_90 (cachep, &cache_chain, next) {
if ( ! V_16 -> V_46 [ V_49 ] ) {
V_44 = F_63 ( V_99 , V_115 , V_49 ) ;
if ( ! V_44 )
return - V_116 ;
F_4 ( V_44 ) ;
V_44 -> V_117 = V_118 + V_119 +
( ( unsigned long ) V_16 ) % V_119 ;
V_16 -> V_46 [ V_49 ] = V_44 ;
}
F_91 ( & V_16 -> V_46 [ V_49 ] -> V_12 ) ;
V_16 -> V_46 [ V_49 ] -> V_120 =
( 1 + F_92 ( V_49 ) ) *
V_16 -> V_97 + V_16 -> V_74 ;
F_81 ( & V_16 -> V_46 [ V_49 ] -> V_12 ) ;
}
return 0 ;
}
static void T_7 F_93 ( long V_85 )
{
struct V_15 * V_16 ;
struct V_4 * V_44 = NULL ;
int V_49 = F_51 ( V_85 ) ;
const struct V_121 * V_122 = F_94 ( V_49 ) ;
F_90 (cachep, &cache_chain, next) {
struct V_42 * V_100 ;
struct V_42 * V_9 ;
struct V_42 * * V_10 ;
V_100 = V_16 -> V_61 [ V_85 ] ;
V_16 -> V_61 [ V_85 ] = NULL ;
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( ! V_44 )
goto V_123;
F_91 ( & V_44 -> V_12 ) ;
V_44 -> V_120 -= V_16 -> V_97 ;
if ( V_100 )
F_77 ( V_16 , V_100 -> V_108 , V_100 -> V_101 , V_49 ) ;
if ( ! F_95 ( V_122 ) ) {
F_81 ( & V_44 -> V_12 ) ;
goto V_123;
}
V_9 = V_44 -> V_9 ;
if ( V_9 ) {
F_77 ( V_16 , V_9 -> V_108 ,
V_9 -> V_101 , V_49 ) ;
V_44 -> V_9 = NULL ;
}
V_10 = V_44 -> V_10 ;
V_44 -> V_10 = NULL ;
F_81 ( & V_44 -> V_12 ) ;
F_74 ( V_9 ) ;
if ( V_10 ) {
F_82 ( V_16 , V_10 ) ;
F_68 ( V_10 ) ;
}
V_123:
F_74 ( V_100 ) ;
}
F_90 (cachep, &cache_chain, next) {
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( ! V_44 )
continue;
F_96 ( V_16 , V_44 , V_44 -> V_13 ) ;
}
}
static int T_7 F_97 ( long V_85 )
{
struct V_15 * V_16 ;
struct V_4 * V_44 = NULL ;
int V_49 = F_51 ( V_85 ) ;
int V_124 ;
V_124 = F_89 ( V_49 ) ;
if ( V_124 < 0 )
goto V_125;
F_90 (cachep, &cache_chain, next) {
struct V_42 * V_100 ;
struct V_42 * V_9 = NULL ;
struct V_42 * * V_10 = NULL ;
V_100 = F_62 ( V_49 , V_16 -> V_102 ,
V_16 -> V_97 , V_115 ) ;
if ( ! V_100 )
goto V_125;
if ( V_16 -> V_9 ) {
V_9 = F_62 ( V_49 ,
V_16 -> V_9 * V_16 -> V_97 ,
0xbaadf00d , V_115 ) ;
if ( ! V_9 ) {
F_74 ( V_100 ) ;
goto V_125;
}
}
if ( V_84 ) {
V_10 = F_67 ( V_49 , V_16 -> V_102 , V_115 ) ;
if ( ! V_10 ) {
F_74 ( V_9 ) ;
F_74 ( V_100 ) ;
goto V_125;
}
}
V_16 -> V_61 [ V_85 ] = V_100 ;
V_44 = V_16 -> V_46 [ V_49 ] ;
F_10 ( ! V_44 ) ;
F_91 ( & V_44 -> V_12 ) ;
if ( ! V_44 -> V_9 ) {
V_44 -> V_9 = V_9 ;
V_9 = NULL ;
}
#ifdef F_98
if ( ! V_44 -> V_10 ) {
V_44 -> V_10 = V_10 ;
V_10 = NULL ;
}
#endif
F_81 ( & V_44 -> V_12 ) ;
F_74 ( V_9 ) ;
F_68 ( V_10 ) ;
if ( V_16 -> V_18 & V_126 )
F_30 ( V_16 , V_49 ) ;
}
F_33 ( V_49 ) ;
return 0 ;
V_125:
F_93 ( V_85 ) ;
return - V_116 ;
}
static int T_7 F_99 ( struct V_127 * V_128 ,
unsigned long V_129 , void * V_130 )
{
long V_85 = ( long ) V_130 ;
int V_124 = 0 ;
switch ( V_129 ) {
case V_131 :
case V_132 :
F_100 ( & V_133 ) ;
V_124 = F_97 ( V_85 ) ;
F_101 ( & V_133 ) ;
break;
case V_134 :
case V_135 :
F_57 ( V_85 ) ;
break;
#ifdef F_102
case V_136 :
case V_137 :
F_103 ( & F_53 ( V_91 , V_85 ) ) ;
F_53 ( V_91 , V_85 ) . V_92 . V_93 = NULL ;
break;
case V_138 :
case V_139 :
F_57 ( V_85 ) ;
break;
case V_140 :
case V_141 :
#endif
case V_142 :
case V_143 :
F_100 ( & V_133 ) ;
F_93 ( V_85 ) ;
F_101 ( & V_133 ) ;
break;
}
return F_104 ( V_124 ) ;
}
static int T_8 F_105 ( int V_49 )
{
struct V_15 * V_16 ;
int V_144 = 0 ;
F_90 (cachep, &cache_chain, next) {
struct V_4 * V_44 ;
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( ! V_44 )
continue;
F_96 ( V_16 , V_44 , V_44 -> V_13 ) ;
if ( ! F_106 ( & V_44 -> V_6 ) ||
! F_106 ( & V_44 -> V_7 ) ) {
V_144 = - V_145 ;
break;
}
}
return V_144 ;
}
static int T_8 F_107 ( struct V_127 * V_146 ,
unsigned long V_129 , void * V_147 )
{
struct V_148 * V_149 = V_147 ;
int V_144 = 0 ;
int V_150 ;
V_150 = V_149 -> V_151 ;
if ( V_150 < 0 )
goto V_152;
switch ( V_129 ) {
case V_153 :
F_100 ( & V_133 ) ;
V_144 = F_89 ( V_150 ) ;
F_101 ( & V_133 ) ;
break;
case V_154 :
F_100 ( & V_133 ) ;
V_144 = F_105 ( V_150 ) ;
F_101 ( & V_133 ) ;
break;
case V_155 :
case V_156 :
case V_157 :
case V_158 :
break;
}
V_152:
return F_104 ( V_144 ) ;
}
static void T_6 F_108 ( struct V_15 * V_16 , struct V_4 * V_159 ,
int V_110 )
{
struct V_4 * V_160 ;
V_160 = F_63 ( sizeof( struct V_4 ) , V_161 , V_110 ) ;
F_10 ( ! V_160 ) ;
memcpy ( V_160 , V_159 , sizeof( struct V_4 ) ) ;
F_6 ( & V_160 -> V_12 ) ;
F_109 ( V_16 , V_160 , V_110 ) ;
V_16 -> V_46 [ V_110 ] = V_160 ;
}
static void T_6 F_110 ( struct V_15 * V_16 , int V_162 )
{
int V_49 ;
F_32 (node) {
V_16 -> V_46 [ V_49 ] = & V_163 [ V_162 + V_49 ] ;
V_16 -> V_46 [ V_49 ] -> V_117 = V_118 +
V_119 +
( ( unsigned long ) V_16 ) % V_119 ;
}
}
void T_6 F_111 ( void )
{
T_2 V_73 ;
struct V_52 * V_164 ;
struct V_165 * V_166 ;
int V_3 ;
int V_167 ;
int V_49 ;
if ( F_112 () == 1 )
V_84 = 0 ;
for ( V_3 = 0 ; V_3 < V_168 ; V_3 ++ ) {
F_4 ( & V_163 [ V_3 ] ) ;
if ( V_3 < V_87 )
V_169 . V_46 [ V_3 ] = NULL ;
}
F_110 ( & V_169 , V_170 ) ;
if ( V_171 > ( 32 << 20 ) >> V_172 )
V_173 = V_174 ;
V_49 = F_85 () ;
F_5 ( & V_175 ) ;
F_113 ( & V_169 . V_27 , & V_175 ) ;
V_169 . V_176 = F_114 () ;
V_169 . V_61 [ F_37 () ] = & V_177 . V_25 ;
V_169 . V_46 [ V_49 ] = & V_163 [ V_170 + V_49 ] ;
V_169 . V_21 = F_115 ( struct V_15 , V_61 [ V_178 ] ) +
V_111 * sizeof( struct V_4 * ) ;
#if V_64
V_169 . F_8 = V_169 . V_21 ;
#endif
V_169 . V_21 = F_43 ( V_169 . V_21 ,
F_114 () ) ;
V_169 . V_35 =
F_116 ( V_169 . V_21 ) ;
for ( V_167 = 0 ; V_167 < V_179 ; V_167 ++ ) {
F_44 ( V_167 , V_169 . V_21 ,
F_114 () , 0 , & V_73 , & V_169 . V_74 ) ;
if ( V_169 . V_74 )
break;
}
F_10 ( ! V_169 . V_74 ) ;
V_169 . V_72 = V_167 ;
V_169 . V_180 = V_73 / V_169 . V_176 ;
V_169 . V_76 = F_43 ( V_169 . V_74 * sizeof( V_71 ) +
sizeof( struct V_29 ) , F_114 () ) ;
V_164 = V_54 ;
V_166 = V_165 ;
V_164 [ V_65 ] . V_58 = F_117 ( V_166 [ V_65 ] . V_83 ,
V_164 [ V_65 ] . V_56 ,
V_181 ,
V_182 | V_183 ,
NULL ) ;
if ( V_65 != V_184 ) {
V_164 [ V_184 ] . V_58 =
F_117 ( V_166 [ V_184 ] . V_83 ,
V_164 [ V_184 ] . V_56 ,
V_181 ,
V_182 | V_183 ,
NULL ) ;
}
V_185 = 0 ;
while ( V_164 -> V_56 != V_57 ) {
if ( ! V_164 -> V_58 ) {
V_164 -> V_58 = F_117 ( V_166 -> V_83 ,
V_164 -> V_56 ,
V_181 ,
V_182 | V_183 ,
NULL ) ;
}
#ifdef F_39
V_164 -> V_68 = F_117 (
V_166 -> V_186 ,
V_164 -> V_56 ,
V_181 ,
V_182 | V_187 |
V_183 ,
NULL ) ;
#endif
V_164 ++ ;
V_166 ++ ;
}
{
struct V_42 * V_160 ;
V_160 = F_118 ( sizeof( struct V_188 ) , V_161 ) ;
F_10 ( F_36 ( & V_169 ) != & V_177 . V_25 ) ;
memcpy ( V_160 , F_36 ( & V_169 ) ,
sizeof( struct V_188 ) ) ;
F_6 ( & V_160 -> V_48 ) ;
V_169 . V_61 [ F_37 () ] = V_160 ;
V_160 = F_118 ( sizeof( struct V_188 ) , V_161 ) ;
F_10 ( F_36 ( V_54 [ V_65 ] . V_58 )
!= & V_189 . V_25 ) ;
memcpy ( V_160 , F_36 ( V_54 [ V_65 ] . V_58 ) ,
sizeof( struct V_188 ) ) ;
F_6 ( & V_160 -> V_48 ) ;
V_54 [ V_65 ] . V_58 -> V_61 [ F_37 () ] =
V_160 ;
}
{
int V_150 ;
F_32 (nid) {
F_108 ( & V_169 , & V_163 [ V_170 + V_150 ] , V_150 ) ;
F_108 ( V_54 [ V_65 ] . V_58 ,
& V_163 [ V_190 + V_150 ] , V_150 ) ;
if ( V_65 != V_184 ) {
F_108 ( V_54 [ V_184 ] . V_58 ,
& V_163 [ V_191 + V_150 ] , V_150 ) ;
}
}
}
V_36 = V_37 ;
}
void T_6 F_119 ( void )
{
struct V_15 * V_16 ;
V_36 = V_55 ;
F_35 () ;
F_100 ( & V_133 ) ;
F_90 (cachep, &cache_chain, next)
if ( F_120 ( V_16 , V_161 ) )
F_121 () ;
F_101 ( & V_133 ) ;
V_36 = V_192 ;
F_122 ( & V_193 ) ;
#ifdef F_98
F_123 ( F_107 , V_194 ) ;
#endif
}
static int T_6 F_124 ( void )
{
int V_85 ;
F_125 (cpu)
F_57 ( V_85 ) ;
return 0 ;
}
static void * F_126 ( struct V_15 * V_16 , T_5 V_18 , int V_110 )
{
struct V_24 * V_24 ;
int V_195 ;
int V_3 ;
#ifndef F_127
V_18 |= V_196 ;
#endif
V_18 |= V_16 -> V_62 ;
if ( V_16 -> V_18 & V_197 )
V_18 |= V_198 ;
V_24 = F_128 ( V_110 , V_18 | V_199 , V_16 -> V_72 ) ;
if ( ! V_24 )
return NULL ;
V_195 = ( 1 << V_16 -> V_72 ) ;
if ( V_16 -> V_18 & V_197 )
F_129 ( F_130 ( V_24 ) ,
V_200 , V_195 ) ;
else
F_129 ( F_130 ( V_24 ) ,
V_201 , V_195 ) ;
for ( V_3 = 0 ; V_3 < V_195 ; V_3 ++ )
F_131 ( V_24 + V_3 ) ;
if ( V_202 && ! ( V_16 -> V_18 & V_203 ) ) {
F_132 ( V_24 , V_16 -> V_72 , V_18 , V_110 ) ;
if ( V_16 -> V_204 )
F_133 ( V_24 , V_195 ) ;
else
F_134 ( V_24 , V_195 ) ;
}
return F_135 ( V_24 ) ;
}
static void F_136 ( struct V_15 * V_16 , void * V_205 )
{
unsigned long V_3 = ( 1 << V_16 -> V_72 ) ;
struct V_24 * V_24 = F_137 ( V_205 ) ;
const unsigned long V_206 = V_3 ;
F_138 ( V_24 , V_16 -> V_72 ) ;
if ( V_16 -> V_18 & V_197 )
F_139 ( F_130 ( V_24 ) ,
V_200 , V_206 ) ;
else
F_139 ( F_130 ( V_24 ) ,
V_201 , V_206 ) ;
while ( V_3 -- ) {
F_10 ( ! F_17 ( V_24 ) ) ;
F_140 ( V_24 ) ;
V_24 ++ ;
}
if ( V_207 -> V_208 )
V_207 -> V_208 -> V_209 += V_206 ;
F_141 ( ( unsigned long ) V_205 , V_16 -> V_72 ) ;
}
static void F_142 ( struct V_210 * V_211 )
{
struct V_212 * V_212 = (struct V_212 * ) V_211 ;
struct V_15 * V_16 = V_212 -> V_16 ;
F_136 ( V_16 , V_212 -> V_205 ) ;
if ( F_34 ( V_16 ) )
F_143 ( V_16 -> V_213 , V_212 ) ;
}
static void F_144 ( struct V_15 * V_16 , unsigned long * V_205 ,
unsigned long V_214 )
{
int V_1 = F_8 ( V_16 ) ;
V_205 = ( unsigned long * ) & ( ( char * ) V_205 ) [ F_7 ( V_16 ) ] ;
if ( V_1 < 5 * sizeof( unsigned long ) )
return;
* V_205 ++ = 0x12345678 ;
* V_205 ++ = V_214 ;
* V_205 ++ = F_37 () ;
V_1 -= 3 * sizeof( unsigned long ) ;
{
unsigned long * V_215 = & V_214 ;
unsigned long V_216 ;
while ( ! F_145 ( V_215 ) ) {
V_216 = * V_215 ++ ;
if ( F_146 ( V_216 ) ) {
* V_205 ++ = V_216 ;
V_1 -= sizeof( unsigned long ) ;
if ( V_1 <= sizeof( unsigned long ) )
break;
}
}
}
* V_205 ++ = 0x87654321 ;
}
static void F_147 ( struct V_15 * V_16 , void * V_205 , unsigned char V_217 )
{
int V_1 = F_8 ( V_16 ) ;
V_205 = & ( ( char * ) V_205 ) [ F_7 ( V_16 ) ] ;
memset ( V_205 , V_217 , V_1 ) ;
* ( unsigned char * ) ( V_205 + V_1 - 1 ) = V_218 ;
}
static void F_148 ( char * V_219 , int V_34 , int V_102 )
{
int V_3 ;
unsigned char error = 0 ;
int V_220 = 0 ;
F_46 ( V_82 L_2 , V_34 ) ;
for ( V_3 = 0 ; V_3 < V_102 ; V_3 ++ ) {
if ( V_219 [ V_34 + V_3 ] != V_221 ) {
error = V_219 [ V_34 + V_3 ] ;
V_220 ++ ;
}
}
F_149 ( V_222 , L_3 , 0 , 16 , 1 ,
& V_219 [ V_34 ] , V_102 , 1 ) ;
if ( V_220 == 1 ) {
error ^= V_221 ;
if ( ! ( error & ( error - 1 ) ) ) {
F_46 ( V_82 L_4
L_5 ) ;
#ifdef F_150
F_46 ( V_82 L_6
L_7 ) ;
#else
F_46 ( V_82 L_8 ) ;
#endif
}
}
}
static void F_151 ( struct V_15 * V_16 , void * V_17 , int V_223 )
{
int V_3 , V_1 ;
char * V_224 ;
if ( V_16 -> V_18 & V_19 ) {
F_46 ( V_82 L_9 ,
* F_9 ( V_16 , V_17 ) ,
* F_11 ( V_16 , V_17 ) ) ;
}
if ( V_16 -> V_18 & V_20 ) {
F_46 ( V_82 L_10 ,
* F_12 ( V_16 , V_17 ) ) ;
F_152 ( L_11 ,
( unsigned long ) * F_12 ( V_16 , V_17 ) ) ;
F_46 ( L_12 ) ;
}
V_224 = ( char * ) V_17 + F_7 ( V_16 ) ;
V_1 = F_8 ( V_16 ) ;
for ( V_3 = 0 ; V_3 < V_1 && V_223 ; V_3 += 16 , V_223 -- ) {
int V_102 ;
V_102 = 16 ;
if ( V_3 + V_102 > V_1 )
V_102 = V_1 - V_3 ;
F_148 ( V_224 , V_3 , V_102 ) ;
}
}
static void F_153 ( struct V_15 * V_16 , void * V_17 )
{
char * V_224 ;
int V_1 , V_3 ;
int V_223 = 0 ;
V_224 = ( char * ) V_17 + F_7 ( V_16 ) ;
V_1 = F_8 ( V_16 ) ;
for ( V_3 = 0 ; V_3 < V_1 ; V_3 ++ ) {
char exp = V_221 ;
if ( V_3 == V_1 - 1 )
exp = V_218 ;
if ( V_224 [ V_3 ] != exp ) {
int V_102 ;
if ( V_223 == 0 ) {
F_46 ( V_82
L_13 ,
V_16 -> V_83 , V_224 , V_1 ) ;
F_151 ( V_16 , V_17 , 0 ) ;
}
V_3 = ( V_3 / 16 ) * 16 ;
V_102 = 16 ;
if ( V_3 + V_102 > V_1 )
V_102 = V_1 - V_3 ;
F_148 ( V_224 , V_3 , V_102 ) ;
V_3 += 16 ;
V_223 ++ ;
if ( V_223 > 5 )
break;
}
}
if ( V_223 != 0 ) {
struct V_29 * V_114 = F_22 ( V_17 ) ;
unsigned int V_225 ;
V_225 = F_24 ( V_16 , V_114 , V_17 ) ;
if ( V_225 ) {
V_17 = F_23 ( V_16 , V_114 , V_225 - 1 ) ;
V_224 = ( char * ) V_17 + F_7 ( V_16 ) ;
F_46 ( V_82 L_14 ,
V_224 , V_1 ) ;
F_151 ( V_16 , V_17 , 2 ) ;
}
if ( V_225 + 1 < V_16 -> V_74 ) {
V_17 = F_23 ( V_16 , V_114 , V_225 + 1 ) ;
V_224 = ( char * ) V_17 + F_7 ( V_16 ) ;
F_46 ( V_82 L_15 ,
V_224 , V_1 ) ;
F_151 ( V_16 , V_17 , 2 ) ;
}
}
}
static void F_154 ( struct V_15 * V_16 , struct V_29 * V_114 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_74 ; V_3 ++ ) {
void * V_17 = F_23 ( V_16 , V_114 , V_3 ) ;
if ( V_16 -> V_18 & V_226 ) {
#ifdef F_155
if ( V_16 -> V_21 % V_77 == 0 &&
F_34 ( V_16 ) )
F_156 ( F_137 ( V_17 ) ,
V_16 -> V_21 / V_77 , 1 ) ;
else
F_153 ( V_16 , V_17 ) ;
#else
F_153 ( V_16 , V_17 ) ;
#endif
}
if ( V_16 -> V_18 & V_19 ) {
if ( * F_9 ( V_16 , V_17 ) != V_227 )
F_157 ( V_16 , L_16
L_17 ) ;
if ( * F_11 ( V_16 , V_17 ) != V_227 )
F_157 ( V_16 , L_18
L_17 ) ;
}
}
}
static void F_154 ( struct V_15 * V_16 , struct V_29 * V_114 )
{
}
static void F_158 ( struct V_15 * V_16 , struct V_29 * V_114 )
{
void * V_205 = V_114 -> V_33 - V_114 -> V_228 ;
F_154 ( V_16 , V_114 ) ;
if ( F_40 ( V_16 -> V_18 & V_229 ) ) {
struct V_212 * V_212 ;
V_212 = (struct V_212 * ) V_114 ;
V_212 -> V_16 = V_16 ;
V_212 -> V_205 = V_205 ;
F_159 ( & V_212 -> V_211 , F_142 ) ;
} else {
F_136 ( V_16 , V_205 ) ;
if ( F_34 ( V_16 ) )
F_143 ( V_16 -> V_213 , V_114 ) ;
}
}
static void F_160 ( struct V_15 * V_16 )
{
int V_3 ;
struct V_4 * V_44 ;
F_125 (i)
F_74 ( V_16 -> V_61 [ V_3 ] ) ;
F_32 (i) {
V_44 = V_16 -> V_46 [ V_3 ] ;
if ( V_44 ) {
F_74 ( V_44 -> V_9 ) ;
F_68 ( V_44 -> V_10 ) ;
F_74 ( V_44 ) ;
}
}
F_143 ( & V_169 , V_16 ) ;
}
static T_2 F_161 ( struct V_15 * V_16 ,
T_2 V_1 , T_2 V_70 , unsigned long V_18 )
{
unsigned long V_230 ;
T_2 V_73 = 0 ;
int V_72 ;
for ( V_72 = 0 ; V_72 <= V_231 ; V_72 ++ ) {
unsigned int V_74 ;
T_2 V_232 ;
F_44 ( V_72 , V_1 , V_70 , V_18 , & V_232 , & V_74 ) ;
if ( ! V_74 )
continue;
if ( V_18 & V_78 ) {
V_230 = V_1 - sizeof( struct V_29 ) ;
V_230 /= sizeof( V_71 ) ;
if ( V_74 > V_230 )
break;
}
V_16 -> V_74 = V_74 ;
V_16 -> V_72 = V_72 ;
V_73 = V_232 ;
if ( V_18 & V_197 )
break;
if ( V_72 >= V_173 )
break;
if ( V_73 * 8 <= ( V_77 << V_72 ) )
break;
}
return V_73 ;
}
static int T_9 F_162 ( struct V_15 * V_16 , T_5 V_98 )
{
if ( V_36 == V_192 )
return F_120 ( V_16 , V_98 ) ;
if ( V_36 == V_233 ) {
V_16 -> V_61 [ F_37 () ] = & V_189 . V_25 ;
F_110 ( V_16 , V_190 ) ;
if ( V_65 == V_184 )
V_36 = V_234 ;
else
V_36 = V_235 ;
} else {
V_16 -> V_61 [ F_37 () ] =
F_118 ( sizeof( struct V_188 ) , V_98 ) ;
if ( V_36 == V_235 ) {
F_110 ( V_16 , V_191 ) ;
V_36 = V_234 ;
} else {
int V_49 ;
F_32 (node) {
V_16 -> V_46 [ V_49 ] =
F_63 ( sizeof( struct V_4 ) ,
V_98 , V_49 ) ;
F_10 ( ! V_16 -> V_46 [ V_49 ] ) ;
F_4 ( V_16 -> V_46 [ V_49 ] ) ;
}
}
}
V_16 -> V_46 [ F_85 () ] -> V_117 =
V_118 + V_119 +
( ( unsigned long ) V_16 ) % V_119 ;
F_36 ( V_16 ) -> V_101 = 0 ;
F_36 ( V_16 ) -> V_102 = V_236 ;
F_36 ( V_16 ) -> V_97 = 1 ;
F_36 ( V_16 ) -> V_103 = 0 ;
V_16 -> V_97 = 1 ;
V_16 -> V_102 = V_236 ;
return 0 ;
}
struct V_15 *
F_117 ( const char * V_83 , T_2 V_1 , T_2 V_70 ,
unsigned long V_18 , void (* V_204)( void * ) )
{
T_2 V_73 , V_76 , V_237 ;
struct V_15 * V_16 = NULL , * V_238 ;
T_5 V_98 ;
if ( ! V_83 || F_163 () || ( V_1 < V_23 ) ||
V_1 > V_239 ) {
F_46 ( V_82 L_19 , V_240 ,
V_83 ) ;
F_121 () ;
}
if ( F_26 () ) {
F_164 () ;
F_100 ( & V_133 ) ;
}
F_90 (pc, &cache_chain, next) {
char V_241 ;
int V_242 ;
V_242 = F_165 ( V_238 -> V_83 , V_241 ) ;
if ( V_242 ) {
F_46 ( V_82
L_20 ,
V_238 -> V_21 ) ;
continue;
}
if ( ! strcmp ( V_238 -> V_83 , V_83 ) ) {
F_46 ( V_82
L_21 , V_83 ) ;
F_47 () ;
goto V_243;
}
}
#if V_64
F_166 ( strchr ( V_83 , ' ' ) ) ;
#if V_244
if ( V_1 < 4096 || F_167 ( V_1 - 1 ) == F_167 ( V_1 - 1 + V_22 +
2 * sizeof( unsigned long long ) ) )
V_18 |= V_19 | V_20 ;
if ( ! ( V_18 & V_229 ) )
V_18 |= V_226 ;
#endif
if ( V_18 & V_229 )
F_10 ( V_18 & V_226 ) ;
#endif
F_10 ( V_18 & ~ V_245 ) ;
if ( V_1 & ( V_23 - 1 ) ) {
V_1 += ( V_23 - 1 ) ;
V_1 &= ~ ( V_23 - 1 ) ;
}
if ( V_18 & V_246 ) {
V_237 = F_114 () ;
while ( V_1 <= V_237 / 2 )
V_237 /= 2 ;
} else {
V_237 = V_23 ;
}
if ( V_18 & V_20 )
V_237 = V_23 ;
if ( V_18 & V_19 ) {
V_237 = V_22 ;
V_1 += V_22 - 1 ;
V_1 &= ~ ( V_22 - 1 ) ;
}
if ( V_237 < V_247 ) {
V_237 = V_247 ;
}
if ( V_237 < V_70 ) {
V_237 = V_70 ;
}
if ( V_237 > F_168 (unsigned long long) )
V_18 &= ~ ( V_19 | V_20 ) ;
V_70 = V_237 ;
if ( F_26 () )
V_98 = V_115 ;
else
V_98 = V_161 ;
V_16 = F_169 ( & V_169 , V_98 ) ;
if ( ! V_16 )
goto V_243;
V_16 -> V_46 = (struct V_4 * * ) & V_16 -> V_61 [ V_178 ] ;
#if V_64
V_16 -> F_8 = V_1 ;
if ( V_18 & V_19 ) {
V_16 -> F_7 += sizeof( unsigned long long ) ;
V_1 += 2 * sizeof( unsigned long long ) ;
}
if ( V_18 & V_20 ) {
if ( V_18 & V_19 )
V_1 += V_22 ;
else
V_1 += V_23 ;
}
#if V_244 && F_170 ( F_155 )
if ( V_1 >= V_54 [ V_184 + 1 ] . V_56
&& V_16 -> F_8 > F_114 () && F_43 ( V_1 , V_70 ) < V_77 ) {
V_16 -> F_7 += V_77 - F_43 ( V_1 , V_70 ) ;
V_1 = V_77 ;
}
#endif
#endif
if ( ( V_1 >= ( V_77 >> 3 ) ) && ! V_185 &&
! ( V_18 & V_248 ) )
V_18 |= V_78 ;
V_1 = F_43 ( V_1 , V_70 ) ;
V_73 = F_161 ( V_16 , V_1 , V_70 , V_18 ) ;
if ( ! V_16 -> V_74 ) {
F_46 ( V_82
L_22 , V_83 ) ;
F_143 ( & V_169 , V_16 ) ;
V_16 = NULL ;
goto V_243;
}
V_76 = F_43 ( V_16 -> V_74 * sizeof( V_71 )
+ sizeof( struct V_29 ) , V_70 ) ;
if ( V_18 & V_78 && V_73 >= V_76 ) {
V_18 &= ~ V_78 ;
V_73 -= V_76 ;
}
if ( V_18 & V_78 ) {
V_76 =
V_16 -> V_74 * sizeof( V_71 ) + sizeof( struct V_29 ) ;
#ifdef F_171
if ( V_1 % V_77 == 0 && V_18 & V_226 )
V_18 &= ~ ( V_19 | V_20 ) ;
#endif
}
V_16 -> V_176 = F_114 () ;
if ( V_16 -> V_176 < V_70 )
V_16 -> V_176 = V_70 ;
V_16 -> V_180 = V_73 / V_16 -> V_176 ;
V_16 -> V_76 = V_76 ;
V_16 -> V_18 = V_18 ;
V_16 -> V_62 = 0 ;
if ( V_249 && ( V_18 & V_187 ) )
V_16 -> V_62 |= V_67 ;
V_16 -> V_21 = V_1 ;
V_16 -> V_35 = F_116 ( V_1 ) ;
if ( V_18 & V_78 ) {
V_16 -> V_213 = F_41 ( V_76 , 0u ) ;
F_10 ( F_172 ( V_16 -> V_213 ) ) ;
}
V_16 -> V_204 = V_204 ;
V_16 -> V_83 = V_83 ;
if ( F_162 ( V_16 , V_98 ) ) {
F_160 ( V_16 ) ;
V_16 = NULL ;
goto V_243;
}
if ( V_18 & V_126 ) {
F_173 ( V_18 & V_229 ) ;
F_31 ( V_16 ) ;
}
F_113 ( & V_16 -> V_27 , & V_175 ) ;
V_243:
if ( ! V_16 && ( V_18 & V_183 ) )
F_174 ( L_23 ,
V_83 ) ;
if ( F_26 () ) {
F_101 ( & V_133 ) ;
F_175 () ;
}
return V_16 ;
}
static void F_176 ( void )
{
F_10 ( ! F_177 () ) ;
}
static void F_178 ( void )
{
F_10 ( F_177 () ) ;
}
static void F_179 ( struct V_15 * V_16 )
{
#ifdef F_180
F_176 () ;
F_181 ( & V_16 -> V_46 [ F_85 () ] -> V_12 ) ;
#endif
}
static void F_182 ( struct V_15 * V_16 , int V_49 )
{
#ifdef F_180
F_176 () ;
F_181 ( & V_16 -> V_46 [ V_49 ] -> V_12 ) ;
#endif
}
static void F_183 ( void * V_147 )
{
struct V_15 * V_16 = V_147 ;
struct V_42 * V_112 ;
int V_49 = F_85 () ;
F_176 () ;
V_112 = F_36 ( V_16 ) ;
F_76 ( & V_16 -> V_46 [ V_49 ] -> V_12 ) ;
F_77 ( V_16 , V_112 -> V_108 , V_112 -> V_101 , V_49 ) ;
F_78 ( & V_16 -> V_46 [ V_49 ] -> V_12 ) ;
V_112 -> V_101 = 0 ;
}
static void F_184 ( struct V_15 * V_16 )
{
struct V_4 * V_44 ;
int V_49 ;
F_185 ( F_183 , V_16 , 1 ) ;
F_178 () ;
F_32 (node) {
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( V_44 && V_44 -> V_10 )
F_82 ( V_16 , V_44 -> V_10 ) ;
}
F_32 (node) {
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( V_44 )
F_186 ( V_16 , V_44 , V_44 -> V_9 , 1 , V_49 ) ;
}
}
static int F_96 ( struct V_15 * V_25 ,
struct V_4 * V_44 , int V_250 )
{
struct V_28 * V_251 ;
int V_206 ;
struct V_29 * V_114 ;
V_206 = 0 ;
while ( V_206 < V_250 && ! F_106 ( & V_44 -> V_8 ) ) {
F_91 ( & V_44 -> V_12 ) ;
V_251 = V_44 -> V_8 . V_30 ;
if ( V_251 == & V_44 -> V_8 ) {
F_81 ( & V_44 -> V_12 ) ;
goto V_152;
}
V_114 = F_187 ( V_251 , struct V_29 , V_159 ) ;
#if V_64
F_10 ( V_114 -> V_252 ) ;
#endif
F_188 ( & V_114 -> V_159 ) ;
V_44 -> V_13 -= V_25 -> V_74 ;
F_81 ( & V_44 -> V_12 ) ;
F_158 ( V_25 , V_114 ) ;
V_206 ++ ;
}
V_152:
return V_206 ;
}
static int F_189 ( struct V_15 * V_16 )
{
int V_144 = 0 , V_3 = 0 ;
struct V_4 * V_44 ;
F_184 ( V_16 ) ;
F_178 () ;
F_32 (i) {
V_44 = V_16 -> V_46 [ V_3 ] ;
if ( ! V_44 )
continue;
F_96 ( V_16 , V_44 , V_44 -> V_13 ) ;
V_144 += ! F_106 ( & V_44 -> V_6 ) ||
! F_106 ( & V_44 -> V_7 ) ;
}
return ( V_144 ? 1 : 0 ) ;
}
int F_190 ( struct V_15 * V_16 )
{
int V_144 ;
F_10 ( ! V_16 || F_163 () ) ;
F_164 () ;
F_100 ( & V_133 ) ;
V_144 = F_189 ( V_16 ) ;
F_101 ( & V_133 ) ;
F_175 () ;
return V_144 ;
}
void F_191 ( struct V_15 * V_16 )
{
F_10 ( ! V_16 || F_163 () ) ;
F_164 () ;
F_100 ( & V_133 ) ;
F_188 ( & V_16 -> V_27 ) ;
if ( F_189 ( V_16 ) ) {
F_157 ( V_16 , L_24 ) ;
F_113 ( & V_16 -> V_27 , & V_175 ) ;
F_101 ( & V_133 ) ;
F_175 () ;
return;
}
if ( F_40 ( V_16 -> V_18 & V_229 ) )
F_192 () ;
F_160 ( V_16 ) ;
F_101 ( & V_133 ) ;
F_175 () ;
}
static struct V_29 * F_193 ( struct V_15 * V_16 , void * V_17 ,
int V_176 , T_5 V_253 ,
int V_110 )
{
struct V_29 * V_114 ;
if ( F_34 ( V_16 ) ) {
V_114 = F_194 ( V_16 -> V_213 ,
V_253 , V_110 ) ;
F_195 ( & V_114 -> V_159 , sizeof( struct V_28 ) ,
V_253 ) ;
if ( ! V_114 )
return NULL ;
} else {
V_114 = V_17 + V_176 ;
V_176 += V_16 -> V_76 ;
}
V_114 -> V_252 = 0 ;
V_114 -> V_228 = V_176 ;
V_114 -> V_33 = V_17 + V_176 ;
V_114 -> V_110 = V_110 ;
V_114 -> free = 0 ;
return V_114 ;
}
static inline V_71 * F_196 ( struct V_29 * V_114 )
{
return ( V_71 * ) ( V_114 + 1 ) ;
}
static void F_197 ( struct V_15 * V_16 ,
struct V_29 * V_114 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_74 ; V_3 ++ ) {
void * V_17 = F_23 ( V_16 , V_114 , V_3 ) ;
#if V_64
if ( V_16 -> V_18 & V_226 )
F_147 ( V_16 , V_17 , V_221 ) ;
if ( V_16 -> V_18 & V_20 )
* F_12 ( V_16 , V_17 ) = NULL ;
if ( V_16 -> V_18 & V_19 ) {
* F_9 ( V_16 , V_17 ) = V_227 ;
* F_11 ( V_16 , V_17 ) = V_227 ;
}
if ( V_16 -> V_204 && ! ( V_16 -> V_18 & V_226 ) )
V_16 -> V_204 ( V_17 + F_7 ( V_16 ) ) ;
if ( V_16 -> V_18 & V_19 ) {
if ( * F_11 ( V_16 , V_17 ) != V_227 )
F_157 ( V_16 , L_25
L_26 ) ;
if ( * F_9 ( V_16 , V_17 ) != V_227 )
F_157 ( V_16 , L_25
L_27 ) ;
}
if ( ( V_16 -> V_21 % V_77 ) == 0 &&
F_34 ( V_16 ) && V_16 -> V_18 & V_226 )
F_156 ( F_137 ( V_17 ) ,
V_16 -> V_21 / V_77 , 0 ) ;
#else
if ( V_16 -> V_204 )
V_16 -> V_204 ( V_17 ) ;
#endif
F_196 ( V_114 ) [ V_3 ] = V_3 + 1 ;
}
F_196 ( V_114 ) [ V_3 - 1 ] = V_254 ;
}
static void F_198 ( struct V_15 * V_16 , T_5 V_18 )
{
if ( V_249 ) {
if ( V_18 & V_67 )
F_10 ( ! ( V_16 -> V_62 & V_67 ) ) ;
else
F_10 ( V_16 -> V_62 & V_67 ) ;
}
}
static void * F_199 ( struct V_15 * V_16 , struct V_29 * V_114 ,
int V_110 )
{
void * V_17 = F_23 ( V_16 , V_114 , V_114 -> free ) ;
V_71 V_27 ;
V_114 -> V_252 ++ ;
V_27 = F_196 ( V_114 ) [ V_114 -> free ] ;
#if V_64
F_196 ( V_114 ) [ V_114 -> free ] = V_255 ;
F_166 ( V_114 -> V_110 != V_110 ) ;
#endif
V_114 -> free = V_27 ;
return V_17 ;
}
static void F_200 ( struct V_15 * V_16 , struct V_29 * V_114 ,
void * V_17 , int V_110 )
{
unsigned int V_225 = F_24 ( V_16 , V_114 , V_17 ) ;
#if V_64
F_166 ( V_114 -> V_110 != V_110 ) ;
if ( F_196 ( V_114 ) [ V_225 ] + 1 <= V_79 + 1 ) {
F_46 ( V_82 L_28
L_29 , V_16 -> V_83 , V_17 ) ;
F_121 () ;
}
#endif
F_196 ( V_114 ) [ V_225 ] = V_114 -> free ;
V_114 -> free = V_225 ;
V_114 -> V_252 -- ;
}
static void F_201 ( struct V_15 * V_25 , struct V_29 * V_29 ,
void * V_205 )
{
int V_195 ;
struct V_24 * V_24 ;
V_24 = F_137 ( V_205 ) ;
V_195 = 1 ;
if ( F_86 ( ! F_202 ( V_24 ) ) )
V_195 <<= V_25 -> V_72 ;
do {
F_14 ( V_24 , V_25 ) ;
F_18 ( V_24 , V_29 ) ;
V_24 ++ ;
} while ( -- V_195 );
}
static int F_203 ( struct V_15 * V_16 ,
T_5 V_18 , int V_110 , void * V_17 )
{
struct V_29 * V_114 ;
T_2 V_34 ;
T_5 V_253 ;
struct V_4 * V_44 ;
F_10 ( V_18 & V_256 ) ;
V_253 = V_18 & ( V_257 | V_258 ) ;
F_176 () ;
V_44 = V_16 -> V_46 [ V_110 ] ;
F_76 ( & V_44 -> V_12 ) ;
V_34 = V_44 -> V_11 ;
V_44 -> V_11 ++ ;
if ( V_44 -> V_11 >= V_16 -> V_180 )
V_44 -> V_11 = 0 ;
F_78 ( & V_44 -> V_12 ) ;
V_34 *= V_16 -> V_176 ;
if ( V_253 & V_259 )
F_204 () ;
F_198 ( V_16 , V_18 ) ;
if ( ! V_17 )
V_17 = F_126 ( V_16 , V_253 , V_110 ) ;
if ( ! V_17 )
goto V_260;
V_114 = F_193 ( V_16 , V_17 , V_34 ,
V_253 & ~ V_257 , V_110 ) ;
if ( ! V_114 )
goto V_261;
F_201 ( V_16 , V_114 , V_17 ) ;
F_197 ( V_16 , V_114 ) ;
if ( V_253 & V_259 )
F_205 () ;
F_176 () ;
F_76 ( & V_44 -> V_12 ) ;
F_206 ( & V_114 -> V_159 , & ( V_44 -> V_8 ) ) ;
F_207 ( V_16 ) ;
V_44 -> V_13 += V_16 -> V_74 ;
F_78 ( & V_44 -> V_12 ) ;
return 1 ;
V_261:
F_136 ( V_16 , V_17 ) ;
V_260:
if ( V_253 & V_259 )
F_205 () ;
return 0 ;
}
static void F_208 ( const void * V_17 )
{
if ( ! F_209 ( V_17 ) ) {
F_46 ( V_82 L_30 ,
( unsigned long ) V_17 ) ;
F_121 () ;
}
}
static inline void F_210 ( struct V_15 * V_25 , void * V_31 )
{
unsigned long long V_262 , V_263 ;
V_262 = * F_9 ( V_25 , V_31 ) ;
V_263 = * F_11 ( V_25 , V_31 ) ;
if ( V_262 == V_264 && V_263 == V_264 )
return;
if ( V_262 == V_227 && V_263 == V_227 )
F_157 ( V_25 , L_31 ) ;
else
F_157 ( V_25 , L_32 ) ;
F_46 ( V_82 L_33 ,
V_31 , V_262 , V_263 ) ;
}
static void * F_211 ( struct V_15 * V_16 , void * V_17 ,
void * V_214 )
{
struct V_24 * V_24 ;
unsigned int V_225 ;
struct V_29 * V_114 ;
F_10 ( F_20 ( V_17 ) != V_16 ) ;
V_17 -= F_7 ( V_16 ) ;
F_208 ( V_17 ) ;
V_24 = F_21 ( V_17 ) ;
V_114 = F_19 ( V_24 ) ;
if ( V_16 -> V_18 & V_19 ) {
F_210 ( V_16 , V_17 ) ;
* F_9 ( V_16 , V_17 ) = V_227 ;
* F_11 ( V_16 , V_17 ) = V_227 ;
}
if ( V_16 -> V_18 & V_20 )
* F_12 ( V_16 , V_17 ) = V_214 ;
V_225 = F_24 ( V_16 , V_114 , V_17 ) ;
F_10 ( V_225 >= V_16 -> V_74 ) ;
F_10 ( V_17 != F_23 ( V_16 , V_114 , V_225 ) ) ;
#ifdef F_212
F_196 ( V_114 ) [ V_225 ] = V_255 ;
#endif
if ( V_16 -> V_18 & V_226 ) {
#ifdef F_155
if ( ( V_16 -> V_21 % V_77 ) == 0 && F_34 ( V_16 ) ) {
F_144 ( V_16 , V_17 , ( unsigned long ) V_214 ) ;
F_156 ( F_137 ( V_17 ) ,
V_16 -> V_21 / V_77 , 0 ) ;
} else {
F_147 ( V_16 , V_17 , V_221 ) ;
}
#else
F_147 ( V_16 , V_17 , V_221 ) ;
#endif
}
return V_17 ;
}
static void F_213 ( struct V_15 * V_16 , struct V_29 * V_114 )
{
V_71 V_3 ;
int V_96 = 0 ;
for ( V_3 = V_114 -> free ; V_3 != V_254 ; V_3 = F_196 ( V_114 ) [ V_3 ] ) {
V_96 ++ ;
if ( V_96 > V_16 -> V_74 || V_3 >= V_16 -> V_74 )
goto V_125;
}
if ( V_96 != V_16 -> V_74 - V_114 -> V_252 ) {
V_125:
F_46 ( V_82 L_34
L_35 ,
V_16 -> V_83 , V_16 -> V_74 , V_114 , V_114 -> V_252 ) ;
F_149 ( V_82 , L_3 , V_265 , 16 , 1 , V_114 ,
sizeof( * V_114 ) + V_16 -> V_74 * sizeof( V_71 ) ,
1 ) ;
F_121 () ;
}
}
static void * F_214 ( struct V_15 * V_16 , T_5 V_18 )
{
int V_97 ;
struct V_4 * V_44 ;
struct V_42 * V_112 ;
int V_49 ;
V_266:
F_176 () ;
V_49 = F_85 () ;
V_112 = F_36 ( V_16 ) ;
V_97 = V_112 -> V_97 ;
if ( ! V_112 -> V_103 && V_97 > V_267 ) {
V_97 = V_267 ;
}
V_44 = V_16 -> V_46 [ V_49 ] ;
F_10 ( V_112 -> V_101 > 0 || ! V_44 ) ;
F_76 ( & V_44 -> V_12 ) ;
if ( V_44 -> V_9 && F_65 ( V_112 , V_44 -> V_9 , V_97 ) ) {
V_44 -> V_9 -> V_103 = 1 ;
goto V_268;
}
while ( V_97 > 0 ) {
struct V_28 * V_108 ;
struct V_29 * V_114 ;
V_108 = V_44 -> V_7 . V_27 ;
if ( V_108 == & V_44 -> V_7 ) {
V_44 -> V_14 = 1 ;
V_108 = V_44 -> V_8 . V_27 ;
if ( V_108 == & V_44 -> V_8 )
goto V_269;
}
V_114 = F_187 ( V_108 , struct V_29 , V_159 ) ;
F_213 ( V_16 , V_114 ) ;
F_179 ( V_16 ) ;
F_10 ( V_114 -> V_252 >= V_16 -> V_74 ) ;
while ( V_114 -> V_252 < V_16 -> V_74 && V_97 -- ) {
F_215 ( V_16 ) ;
F_216 ( V_16 ) ;
F_217 ( V_16 ) ;
V_112 -> V_108 [ V_112 -> V_101 ++ ] = F_199 ( V_16 , V_114 ,
V_49 ) ;
}
F_213 ( V_16 , V_114 ) ;
F_188 ( & V_114 -> V_159 ) ;
if ( V_114 -> free == V_254 )
F_113 ( & V_114 -> V_159 , & V_44 -> V_6 ) ;
else
F_113 ( & V_114 -> V_159 , & V_44 -> V_7 ) ;
}
V_269:
V_44 -> V_13 -= V_112 -> V_101 ;
V_268:
F_78 ( & V_44 -> V_12 ) ;
if ( F_40 ( ! V_112 -> V_101 ) ) {
int T_3 ;
T_3 = F_203 ( V_16 , V_18 | V_270 , V_49 , NULL ) ;
V_112 = F_36 ( V_16 ) ;
if ( ! T_3 && V_112 -> V_101 == 0 )
return NULL ;
if ( ! V_112 -> V_101 )
goto V_266;
}
V_112 -> V_103 = 1 ;
return V_112 -> V_108 [ -- V_112 -> V_101 ] ;
}
static inline void F_218 ( struct V_15 * V_16 ,
T_5 V_18 )
{
F_219 ( V_18 & V_259 ) ;
#if V_64
F_198 ( V_16 , V_18 ) ;
#endif
}
static void * F_220 ( struct V_15 * V_16 ,
T_5 V_18 , void * V_17 , void * V_214 )
{
if ( ! V_17 )
return V_17 ;
if ( V_16 -> V_18 & V_226 ) {
#ifdef F_155
if ( ( V_16 -> V_21 % V_77 ) == 0 && F_34 ( V_16 ) )
F_156 ( F_137 ( V_17 ) ,
V_16 -> V_21 / V_77 , 1 ) ;
else
F_153 ( V_16 , V_17 ) ;
#else
F_153 ( V_16 , V_17 ) ;
#endif
F_147 ( V_16 , V_17 , V_271 ) ;
}
if ( V_16 -> V_18 & V_20 )
* F_12 ( V_16 , V_17 ) = V_214 ;
if ( V_16 -> V_18 & V_19 ) {
if ( * F_9 ( V_16 , V_17 ) != V_227 ||
* F_11 ( V_16 , V_17 ) != V_227 ) {
F_157 ( V_16 , L_36
L_37 ) ;
F_46 ( V_82
L_38 ,
V_17 , * F_9 ( V_16 , V_17 ) ,
* F_11 ( V_16 , V_17 ) ) ;
}
* F_9 ( V_16 , V_17 ) = V_264 ;
* F_11 ( V_16 , V_17 ) = V_264 ;
}
#ifdef F_212
{
struct V_29 * V_114 ;
unsigned V_225 ;
V_114 = F_19 ( F_21 ( V_17 ) ) ;
V_225 = ( unsigned ) ( V_17 - V_114 -> V_33 ) / V_16 -> V_21 ;
F_196 ( V_114 ) [ V_225 ] = V_272 ;
}
#endif
V_17 += F_7 ( V_16 ) ;
if ( V_16 -> V_204 && V_16 -> V_18 & V_226 )
V_16 -> V_204 ( V_17 ) ;
if ( V_247 &&
( ( unsigned long ) V_17 & ( V_247 - 1 ) ) ) {
F_46 ( V_82 L_39 ,
V_17 , ( int ) V_247 ) ;
}
return V_17 ;
}
static bool F_221 ( struct V_15 * V_16 , T_5 V_18 )
{
if ( V_16 == & V_169 )
return false ;
return F_222 ( F_8 ( V_16 ) , V_18 , V_16 -> V_18 ) ;
}
static inline void * F_223 ( struct V_15 * V_16 , T_5 V_18 )
{
void * V_17 ;
struct V_42 * V_112 ;
F_176 () ;
V_112 = F_36 ( V_16 ) ;
if ( F_86 ( V_112 -> V_101 ) ) {
F_224 ( V_16 ) ;
V_112 -> V_103 = 1 ;
V_17 = V_112 -> V_108 [ -- V_112 -> V_101 ] ;
} else {
F_225 ( V_16 ) ;
V_17 = F_214 ( V_16 , V_18 ) ;
V_112 = F_36 ( V_16 ) ;
}
if ( V_17 )
F_226 ( & V_112 -> V_108 [ V_112 -> V_101 ] ) ;
return V_17 ;
}
static void * F_70 ( struct V_15 * V_16 , T_5 V_18 )
{
int V_273 , V_274 ;
if ( F_163 () || ( V_18 & V_275 ) )
return NULL ;
V_273 = V_274 = F_85 () ;
F_227 () ;
if ( F_228 () && ( V_16 -> V_18 & V_276 ) )
V_273 = F_229 () ;
else if ( V_207 -> V_277 )
V_273 = F_230 ( V_207 -> V_277 ) ;
F_231 () ;
if ( V_273 != V_274 )
return F_71 ( V_16 , V_18 , V_273 ) ;
return NULL ;
}
static void * F_232 ( struct V_15 * V_25 , T_5 V_18 )
{
struct V_278 * V_278 ;
T_5 V_253 ;
struct V_279 * V_280 ;
struct V_281 * V_281 ;
enum V_282 V_283 = F_233 ( V_18 ) ;
void * V_31 = NULL ;
int V_150 ;
if ( V_18 & V_275 )
return NULL ;
F_227 () ;
V_278 = F_234 ( F_230 ( V_207 -> V_277 ) , V_18 ) ;
V_253 = V_18 & ( V_257 | V_258 ) ;
V_266:
F_235 (zone, z, zonelist, high_zoneidx) {
V_150 = F_236 ( V_281 ) ;
if ( F_237 ( V_281 , V_18 ) &&
V_25 -> V_46 [ V_150 ] &&
V_25 -> V_46 [ V_150 ] -> V_13 ) {
V_31 = F_71 ( V_25 ,
V_18 | V_270 , V_150 ) ;
if ( V_31 )
break;
}
}
if ( ! V_31 ) {
if ( V_253 & V_259 )
F_204 () ;
F_198 ( V_25 , V_18 ) ;
V_31 = F_126 ( V_25 , V_253 , F_85 () ) ;
if ( V_253 & V_259 )
F_205 () ;
if ( V_31 ) {
V_150 = F_238 ( F_137 ( V_31 ) ) ;
if ( F_203 ( V_25 , V_18 , V_150 , V_31 ) ) {
V_31 = F_71 ( V_25 ,
V_18 | V_270 , V_150 ) ;
if ( ! V_31 )
goto V_266;
} else {
V_31 = NULL ;
}
}
}
F_231 () ;
return V_31 ;
}
static void * F_71 ( struct V_15 * V_16 , T_5 V_18 ,
int V_110 )
{
struct V_28 * V_108 ;
struct V_29 * V_114 ;
struct V_4 * V_44 ;
void * V_31 ;
int T_3 ;
V_44 = V_16 -> V_46 [ V_110 ] ;
F_10 ( ! V_44 ) ;
V_266:
F_176 () ;
F_76 ( & V_44 -> V_12 ) ;
V_108 = V_44 -> V_7 . V_27 ;
if ( V_108 == & V_44 -> V_7 ) {
V_44 -> V_14 = 1 ;
V_108 = V_44 -> V_8 . V_27 ;
if ( V_108 == & V_44 -> V_8 )
goto V_269;
}
V_114 = F_187 ( V_108 , struct V_29 , V_159 ) ;
F_182 ( V_16 , V_110 ) ;
F_213 ( V_16 , V_114 ) ;
F_239 ( V_16 ) ;
F_216 ( V_16 ) ;
F_217 ( V_16 ) ;
F_10 ( V_114 -> V_252 == V_16 -> V_74 ) ;
V_31 = F_199 ( V_16 , V_114 , V_110 ) ;
F_213 ( V_16 , V_114 ) ;
V_44 -> V_13 -- ;
F_188 ( & V_114 -> V_159 ) ;
if ( V_114 -> free == V_254 )
F_113 ( & V_114 -> V_159 , & V_44 -> V_6 ) ;
else
F_113 ( & V_114 -> V_159 , & V_44 -> V_7 ) ;
F_78 ( & V_44 -> V_12 ) ;
goto V_284;
V_269:
F_78 ( & V_44 -> V_12 ) ;
T_3 = F_203 ( V_16 , V_18 | V_270 , V_110 , NULL ) ;
if ( T_3 )
goto V_266;
return F_232 ( V_16 , V_18 ) ;
V_284:
return V_31 ;
}
static T_1 void *
F_240 ( struct V_15 * V_16 , T_5 V_18 , int V_110 ,
void * V_214 )
{
unsigned long V_285 ;
void * V_160 ;
int F_230 = F_85 () ;
V_18 &= V_286 ;
F_241 ( V_18 ) ;
if ( F_221 ( V_16 , V_18 ) )
return NULL ;
F_218 ( V_16 , V_18 ) ;
F_242 ( V_285 ) ;
if ( V_110 == V_287 )
V_110 = F_230 ;
if ( F_40 ( ! V_16 -> V_46 [ V_110 ] ) ) {
V_160 = F_232 ( V_16 , V_18 ) ;
goto V_152;
}
if ( V_110 == F_230 ) {
V_160 = F_223 ( V_16 , V_18 ) ;
if ( V_160 )
goto V_152;
}
V_160 = F_71 ( V_16 , V_18 , V_110 ) ;
V_152:
F_243 ( V_285 ) ;
V_160 = F_220 ( V_16 , V_18 , V_160 , V_214 ) ;
F_244 ( V_160 , F_8 ( V_16 ) , 1 , V_16 -> V_18 ,
V_18 ) ;
if ( F_86 ( V_160 ) )
F_245 ( V_16 , V_18 , V_160 , F_8 ( V_16 ) ) ;
if ( F_40 ( ( V_18 & V_288 ) && V_160 ) )
memset ( V_160 , 0 , F_8 ( V_16 ) ) ;
return V_160 ;
}
static T_1 void *
F_246 ( struct V_15 * V_25 , T_5 V_18 )
{
void * V_17 ;
if ( F_40 ( V_207 -> V_18 & ( V_289 | V_290 ) ) ) {
V_17 = F_70 ( V_25 , V_18 ) ;
if ( V_17 )
goto V_152;
}
V_17 = F_223 ( V_25 , V_18 ) ;
if ( ! V_17 )
V_17 = F_71 ( V_25 , V_18 , F_85 () ) ;
V_152:
return V_17 ;
}
static T_1 void *
F_246 ( struct V_15 * V_16 , T_5 V_18 )
{
return F_223 ( V_16 , V_18 ) ;
}
static T_1 void *
F_247 ( struct V_15 * V_16 , T_5 V_18 , void * V_214 )
{
unsigned long V_285 ;
void * V_17 ;
V_18 &= V_286 ;
F_241 ( V_18 ) ;
if ( F_221 ( V_16 , V_18 ) )
return NULL ;
F_218 ( V_16 , V_18 ) ;
F_242 ( V_285 ) ;
V_17 = F_246 ( V_16 , V_18 ) ;
F_243 ( V_285 ) ;
V_17 = F_220 ( V_16 , V_18 , V_17 , V_214 ) ;
F_244 ( V_17 , F_8 ( V_16 ) , 1 , V_16 -> V_18 ,
V_18 ) ;
F_248 ( V_17 ) ;
if ( F_86 ( V_17 ) )
F_245 ( V_16 , V_18 , V_17 , F_8 ( V_16 ) ) ;
if ( F_40 ( ( V_18 & V_288 ) && V_17 ) )
memset ( V_17 , 0 , F_8 ( V_16 ) ) ;
return V_17 ;
}
static void F_77 ( struct V_15 * V_16 , void * * V_291 , int V_292 ,
int V_49 )
{
int V_3 ;
struct V_4 * V_44 ;
for ( V_3 = 0 ; V_3 < V_292 ; V_3 ++ ) {
void * V_17 = V_291 [ V_3 ] ;
struct V_29 * V_114 ;
V_114 = F_22 ( V_17 ) ;
V_44 = V_16 -> V_46 [ V_49 ] ;
F_188 ( & V_114 -> V_159 ) ;
F_182 ( V_16 , V_49 ) ;
F_213 ( V_16 , V_114 ) ;
F_200 ( V_16 , V_114 , V_17 , V_49 ) ;
F_249 ( V_16 ) ;
V_44 -> V_13 ++ ;
F_213 ( V_16 , V_114 ) ;
if ( V_114 -> V_252 == 0 ) {
if ( V_44 -> V_13 > V_44 -> V_120 ) {
V_44 -> V_13 -= V_16 -> V_74 ;
F_158 ( V_16 , V_114 ) ;
} else {
F_113 ( & V_114 -> V_159 , & V_44 -> V_8 ) ;
}
} else {
F_206 ( & V_114 -> V_159 , & V_44 -> V_7 ) ;
}
}
}
static void F_250 ( struct V_15 * V_16 , struct V_42 * V_112 )
{
int V_97 ;
struct V_4 * V_44 ;
int V_49 = F_85 () ;
V_97 = V_112 -> V_97 ;
#if V_64
F_10 ( ! V_97 || V_97 > V_112 -> V_101 ) ;
#endif
F_176 () ;
V_44 = V_16 -> V_46 [ V_49 ] ;
F_76 ( & V_44 -> V_12 ) ;
if ( V_44 -> V_9 ) {
struct V_42 * V_293 = V_44 -> V_9 ;
int V_106 = V_293 -> V_102 - V_293 -> V_101 ;
if ( V_106 ) {
if ( V_97 > V_106 )
V_97 = V_106 ;
memcpy ( & ( V_293 -> V_108 [ V_293 -> V_101 ] ) ,
V_112 -> V_108 , sizeof( void * ) * V_97 ) ;
V_293 -> V_101 += V_97 ;
goto V_294;
}
}
F_77 ( V_16 , V_112 -> V_108 , V_97 , V_49 ) ;
V_294:
#if V_295
{
int V_3 = 0 ;
struct V_28 * V_251 ;
V_251 = V_44 -> V_8 . V_27 ;
while ( V_251 != & ( V_44 -> V_8 ) ) {
struct V_29 * V_114 ;
V_114 = F_187 ( V_251 , struct V_29 , V_159 ) ;
F_10 ( V_114 -> V_252 ) ;
V_3 ++ ;
V_251 = V_251 -> V_27 ;
}
F_251 ( V_16 , V_3 ) ;
}
#endif
F_78 ( & V_44 -> V_12 ) ;
V_112 -> V_101 -= V_97 ;
memmove ( V_112 -> V_108 , & ( V_112 -> V_108 [ V_97 ] ) , sizeof( void * ) * V_112 -> V_101 ) ;
}
static inline void F_252 ( struct V_15 * V_16 , void * V_17 ,
void * V_214 )
{
struct V_42 * V_112 = F_36 ( V_16 ) ;
F_176 () ;
F_253 ( V_17 , V_16 -> V_18 ) ;
V_17 = F_211 ( V_16 , V_17 , V_214 ) ;
F_254 ( V_16 , V_17 , F_8 ( V_16 ) ) ;
if ( V_296 > 1 && F_69 ( V_16 , V_17 ) )
return;
if ( F_86 ( V_112 -> V_101 < V_112 -> V_102 ) ) {
F_255 ( V_16 ) ;
V_112 -> V_108 [ V_112 -> V_101 ++ ] = V_17 ;
return;
} else {
F_256 ( V_16 ) ;
F_250 ( V_16 , V_112 ) ;
V_112 -> V_108 [ V_112 -> V_101 ++ ] = V_17 ;
}
}
void * F_257 ( struct V_15 * V_16 , T_5 V_18 )
{
void * V_144 = F_247 ( V_16 , V_18 , F_258 ( 0 ) ) ;
F_259 ( V_297 , V_144 ,
F_8 ( V_16 ) , V_16 -> V_21 , V_18 ) ;
return V_144 ;
}
void *
F_260 ( T_2 V_1 , struct V_15 * V_16 , T_5 V_18 )
{
void * V_144 ;
V_144 = F_247 ( V_16 , V_18 , F_258 ( 0 ) ) ;
F_261 ( V_297 , V_144 ,
V_1 , F_13 ( V_16 ) , V_18 ) ;
return V_144 ;
}
void * F_194 ( struct V_15 * V_16 , T_5 V_18 , int V_110 )
{
void * V_144 = F_240 ( V_16 , V_18 , V_110 ,
F_258 ( 0 ) ) ;
F_262 ( V_297 , V_144 ,
F_8 ( V_16 ) , V_16 -> V_21 ,
V_18 , V_110 ) ;
return V_144 ;
}
void * F_263 ( T_2 V_1 ,
struct V_15 * V_16 ,
T_5 V_18 ,
int V_110 )
{
void * V_144 ;
V_144 = F_240 ( V_16 , V_18 , V_110 ,
F_258 ( 0 ) ) ;
F_264 ( V_297 , V_144 ,
V_1 , F_13 ( V_16 ) ,
V_18 , V_110 ) ;
return V_144 ;
}
static T_1 void *
F_265 ( T_2 V_1 , T_5 V_18 , int V_49 , void * V_214 )
{
struct V_15 * V_16 ;
V_16 = F_41 ( V_1 , V_18 ) ;
if ( F_40 ( F_172 ( V_16 ) ) )
return V_16 ;
return F_263 ( V_1 , V_16 , V_18 , V_49 ) ;
}
void * F_266 ( T_2 V_1 , T_5 V_18 , int V_49 )
{
return F_265 ( V_1 , V_18 , V_49 ,
F_258 ( 0 ) ) ;
}
void * F_267 ( T_2 V_1 , T_5 V_18 ,
int V_49 , unsigned long V_214 )
{
return F_265 ( V_1 , V_18 , V_49 , ( void * ) V_214 ) ;
}
void * F_266 ( T_2 V_1 , T_5 V_18 , int V_49 )
{
return F_265 ( V_1 , V_18 , V_49 , NULL ) ;
}
static T_1 void * F_268 ( T_2 V_1 , T_5 V_18 ,
void * V_214 )
{
struct V_15 * V_16 ;
void * V_144 ;
V_16 = F_38 ( V_1 , V_18 ) ;
if ( F_40 ( F_172 ( V_16 ) ) )
return V_16 ;
V_144 = F_247 ( V_16 , V_18 , V_214 ) ;
F_261 ( ( unsigned long ) V_214 , V_144 ,
V_1 , V_16 -> V_21 , V_18 ) ;
return V_144 ;
}
void * F_269 ( T_2 V_1 , T_5 V_18 )
{
return F_268 ( V_1 , V_18 , F_258 ( 0 ) ) ;
}
void * F_270 ( T_2 V_1 , T_5 V_18 , unsigned long V_214 )
{
return F_268 ( V_1 , V_18 , ( void * ) V_214 ) ;
}
void * F_269 ( T_2 V_1 , T_5 V_18 )
{
return F_268 ( V_1 , V_18 , NULL ) ;
}
void F_143 ( struct V_15 * V_16 , void * V_17 )
{
unsigned long V_18 ;
F_242 ( V_18 ) ;
F_271 ( V_17 , F_8 ( V_16 ) ) ;
if ( ! ( V_16 -> V_18 & V_126 ) )
F_272 ( V_17 , F_8 ( V_16 ) ) ;
F_252 ( V_16 , V_17 , F_258 ( 0 ) ) ;
F_243 ( V_18 ) ;
F_273 ( V_297 , V_17 ) ;
}
void F_74 ( const void * V_17 )
{
struct V_15 * V_298 ;
unsigned long V_18 ;
F_274 ( V_297 , V_17 ) ;
if ( F_40 ( F_172 ( V_17 ) ) )
return;
F_242 ( V_18 ) ;
F_208 ( V_17 ) ;
V_298 = F_20 ( V_17 ) ;
F_271 ( V_17 , F_8 ( V_298 ) ) ;
F_272 ( V_17 , F_8 ( V_298 ) ) ;
F_252 ( V_298 , ( void * ) V_17 , F_258 ( 0 ) ) ;
F_243 ( V_18 ) ;
}
unsigned int F_275 ( struct V_15 * V_16 )
{
return F_8 ( V_16 ) ;
}
static int F_276 ( struct V_15 * V_16 , T_5 V_98 )
{
int V_49 ;
struct V_4 * V_44 ;
struct V_42 * V_299 ;
struct V_42 * * V_300 = NULL ;
F_32 (node) {
if ( V_84 ) {
V_300 = F_67 ( V_49 , V_16 -> V_102 , V_98 ) ;
if ( ! V_300 )
goto V_301;
}
V_299 = NULL ;
if ( V_16 -> V_9 ) {
V_299 = F_62 ( V_49 ,
V_16 -> V_9 * V_16 -> V_97 ,
0xbaadf00d , V_98 ) ;
if ( ! V_299 ) {
F_68 ( V_300 ) ;
goto V_301;
}
}
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( V_44 ) {
struct V_42 * V_9 = V_44 -> V_9 ;
F_91 ( & V_44 -> V_12 ) ;
if ( V_9 )
F_77 ( V_16 , V_9 -> V_108 ,
V_9 -> V_101 , V_49 ) ;
V_44 -> V_9 = V_299 ;
if ( ! V_44 -> V_10 ) {
V_44 -> V_10 = V_300 ;
V_300 = NULL ;
}
V_44 -> V_120 = ( 1 + F_92 ( V_49 ) ) *
V_16 -> V_97 + V_16 -> V_74 ;
F_81 ( & V_44 -> V_12 ) ;
F_74 ( V_9 ) ;
F_68 ( V_300 ) ;
continue;
}
V_44 = F_63 ( sizeof( struct V_4 ) , V_98 , V_49 ) ;
if ( ! V_44 ) {
F_68 ( V_300 ) ;
F_74 ( V_299 ) ;
goto V_301;
}
F_4 ( V_44 ) ;
V_44 -> V_117 = V_118 + V_119 +
( ( unsigned long ) V_16 ) % V_119 ;
V_44 -> V_9 = V_299 ;
V_44 -> V_10 = V_300 ;
V_44 -> V_120 = ( 1 + F_92 ( V_49 ) ) *
V_16 -> V_97 + V_16 -> V_74 ;
V_16 -> V_46 [ V_49 ] = V_44 ;
}
return 0 ;
V_301:
if ( ! V_16 -> V_27 . V_27 ) {
V_49 -- ;
while ( V_49 >= 0 ) {
if ( V_16 -> V_46 [ V_49 ] ) {
V_44 = V_16 -> V_46 [ V_49 ] ;
F_74 ( V_44 -> V_9 ) ;
F_68 ( V_44 -> V_10 ) ;
F_74 ( V_44 ) ;
V_16 -> V_46 [ V_49 ] = NULL ;
}
V_49 -- ;
}
}
return - V_116 ;
}
static void F_277 ( void * V_302 )
{
struct V_303 * V_304 = V_302 ;
struct V_42 * V_305 ;
F_176 () ;
V_305 = F_36 ( V_304 -> V_16 ) ;
V_304 -> V_16 -> V_61 [ F_37 () ] = V_304 -> V_304 [ F_37 () ] ;
V_304 -> V_304 [ F_37 () ] = V_305 ;
}
static int F_278 ( struct V_15 * V_16 , int V_102 ,
int V_97 , int V_9 , T_5 V_98 )
{
struct V_303 * V_304 ;
int V_3 ;
V_304 = F_279 ( sizeof( * V_304 ) + V_178 * sizeof( struct V_42 * ) ,
V_98 ) ;
if ( ! V_304 )
return - V_116 ;
F_125 (i) {
V_304 -> V_304 [ V_3 ] = F_62 ( F_51 ( V_3 ) , V_102 ,
V_97 , V_98 ) ;
if ( ! V_304 -> V_304 [ V_3 ] ) {
for ( V_3 -- ; V_3 >= 0 ; V_3 -- )
F_74 ( V_304 -> V_304 [ V_3 ] ) ;
F_74 ( V_304 ) ;
return - V_116 ;
}
}
V_304 -> V_16 = V_16 ;
F_185 ( F_277 , ( void * ) V_304 , 1 ) ;
F_178 () ;
V_16 -> V_97 = V_97 ;
V_16 -> V_102 = V_102 ;
V_16 -> V_9 = V_9 ;
F_125 (i) {
struct V_42 * V_306 = V_304 -> V_304 [ V_3 ] ;
if ( ! V_306 )
continue;
F_91 ( & V_16 -> V_46 [ F_51 ( V_3 ) ] -> V_12 ) ;
F_77 ( V_16 , V_306 -> V_108 , V_306 -> V_101 , F_51 ( V_3 ) ) ;
F_81 ( & V_16 -> V_46 [ F_51 ( V_3 ) ] -> V_12 ) ;
F_74 ( V_306 ) ;
}
F_74 ( V_304 ) ;
return F_276 ( V_16 , V_98 ) ;
}
static int F_120 ( struct V_15 * V_16 , T_5 V_98 )
{
int V_124 ;
int V_102 , V_9 ;
if ( V_16 -> V_21 > 131072 )
V_102 = 1 ;
else if ( V_16 -> V_21 > V_77 )
V_102 = 8 ;
else if ( V_16 -> V_21 > 1024 )
V_102 = 24 ;
else if ( V_16 -> V_21 > 256 )
V_102 = 54 ;
else
V_102 = 120 ;
V_9 = 0 ;
if ( V_16 -> V_21 <= V_77 && F_280 () > 1 )
V_9 = 8 ;
#if V_64
if ( V_102 > 32 )
V_102 = 32 ;
#endif
V_124 = F_278 ( V_16 , V_102 , ( V_102 + 1 ) / 2 , V_9 , V_98 ) ;
if ( V_124 )
F_46 ( V_82 L_40 ,
V_16 -> V_83 , - V_124 ) ;
return V_124 ;
}
static void F_186 ( struct V_15 * V_16 , struct V_4 * V_44 ,
struct V_42 * V_112 , int V_307 , int V_49 )
{
int V_250 ;
if ( ! V_112 || ! V_112 -> V_101 )
return;
if ( V_112 -> V_103 && ! V_307 ) {
V_112 -> V_103 = 0 ;
} else {
F_91 ( & V_44 -> V_12 ) ;
if ( V_112 -> V_101 ) {
V_250 = V_307 ? V_112 -> V_101 : ( V_112 -> V_102 + 4 ) / 5 ;
if ( V_250 > V_112 -> V_101 )
V_250 = ( V_112 -> V_101 + 1 ) / 2 ;
F_77 ( V_16 , V_112 -> V_108 , V_250 , V_49 ) ;
V_112 -> V_101 -= V_250 ;
memmove ( V_112 -> V_108 , & ( V_112 -> V_108 [ V_250 ] ) ,
sizeof( void * ) * V_112 -> V_101 ) ;
}
F_81 ( & V_44 -> V_12 ) ;
}
}
static void V_94 ( struct V_308 * V_309 )
{
struct V_15 * V_310 ;
struct V_4 * V_44 ;
int V_49 = F_85 () ;
struct V_89 * V_92 = F_281 ( V_309 ) ;
if ( ! F_282 ( & V_133 ) )
goto V_152;
F_90 (searchp, &cache_chain, next) {
F_178 () ;
V_44 = V_310 -> V_46 [ V_49 ] ;
F_79 ( V_310 , V_44 ) ;
F_186 ( V_310 , V_44 , F_36 ( V_310 ) , 0 , V_49 ) ;
if ( F_283 ( V_44 -> V_117 , V_118 ) )
goto V_27;
V_44 -> V_117 = V_118 + V_119 ;
F_186 ( V_310 , V_44 , V_44 -> V_9 , 0 , V_49 ) ;
if ( V_44 -> V_14 )
V_44 -> V_14 = 0 ;
else {
int V_311 ;
V_311 = F_96 ( V_310 , V_44 , ( V_44 -> V_120 +
5 * V_310 -> V_74 - 1 ) / ( 5 * V_310 -> V_74 ) ) ;
F_284 ( V_310 , V_311 ) ;
}
V_27:
F_285 () ;
}
F_178 () ;
F_101 ( & V_133 ) ;
F_54 () ;
V_152:
F_286 ( V_92 , F_287 ( V_312 ) ) ;
}
static void F_288 ( struct V_313 * V_314 )
{
#if V_295
F_289 ( V_314 , L_41 ) ;
#else
F_289 ( V_314 , L_42 ) ;
#endif
F_289 ( V_314 , L_43
L_44 ) ;
F_289 ( V_314 , L_45 ) ;
F_289 ( V_314 , L_46 ) ;
#if V_295
F_289 ( V_314 , L_47
L_48 ) ;
F_289 ( V_314 , L_49 ) ;
#endif
F_290 ( V_314 , '\n' ) ;
}
static void * F_291 ( struct V_313 * V_314 , T_10 * V_315 )
{
T_10 V_316 = * V_315 ;
F_100 ( & V_133 ) ;
if ( ! V_316 )
F_288 ( V_314 ) ;
return F_292 ( & V_175 , * V_315 ) ;
}
static void * F_293 ( struct V_313 * V_314 , void * V_251 , T_10 * V_315 )
{
return F_294 ( V_251 , & V_175 , V_315 ) ;
}
static void F_295 ( struct V_313 * V_314 , void * V_251 )
{
F_101 ( & V_133 ) ;
}
static int F_296 ( struct V_313 * V_314 , void * V_251 )
{
struct V_15 * V_16 = F_187 ( V_251 , struct V_15 , V_27 ) ;
struct V_29 * V_114 ;
unsigned long V_317 ;
unsigned long V_318 ;
unsigned long V_319 = 0 ;
unsigned long V_320 , V_13 = 0 , V_321 = 0 ;
const char * V_83 ;
char * error = NULL ;
int V_49 ;
struct V_4 * V_44 ;
V_317 = 0 ;
V_320 = 0 ;
F_32 (node) {
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( ! V_44 )
continue;
F_178 () ;
F_91 ( & V_44 -> V_12 ) ;
F_90 (slabp, &l3->slabs_full, list) {
if ( V_114 -> V_252 != V_16 -> V_74 && ! error )
error = L_50 ;
V_317 += V_16 -> V_74 ;
V_319 ++ ;
}
F_90 (slabp, &l3->slabs_partial, list) {
if ( V_114 -> V_252 == V_16 -> V_74 && ! error )
error = L_51 ;
if ( ! V_114 -> V_252 && ! error )
error = L_52 ;
V_317 += V_114 -> V_252 ;
V_319 ++ ;
}
F_90 (slabp, &l3->slabs_free, list) {
if ( V_114 -> V_252 && ! error )
error = L_53 ;
V_320 ++ ;
}
V_13 += V_44 -> V_13 ;
if ( V_44 -> V_9 )
V_321 += V_44 -> V_9 -> V_101 ;
F_81 ( & V_44 -> V_12 ) ;
}
V_320 += V_319 ;
V_318 = V_320 * V_16 -> V_74 ;
if ( V_318 - V_317 != V_13 && ! error )
error = L_54 ;
V_83 = V_16 -> V_83 ;
if ( error )
F_46 ( V_82 L_55 , V_83 , error ) ;
F_297 ( V_314 , L_56 ,
V_83 , V_317 , V_318 , V_16 -> V_21 ,
V_16 -> V_74 , ( 1 << V_16 -> V_72 ) ) ;
F_297 ( V_314 , L_57 ,
V_16 -> V_102 , V_16 -> V_97 , V_16 -> V_9 ) ;
F_297 ( V_314 , L_58 ,
V_319 , V_320 , V_321 ) ;
#if V_295
{
unsigned long V_322 = V_16 -> V_323 ;
unsigned long V_324 = V_16 -> V_325 ;
unsigned long V_326 = V_16 -> V_326 ;
unsigned long V_327 = V_16 -> V_327 ;
unsigned long V_328 = V_16 -> V_328 ;
unsigned long V_329 = V_16 -> V_329 ;
unsigned long V_330 = V_16 -> V_330 ;
unsigned long V_331 = V_16 -> V_331 ;
unsigned long V_332 = V_16 -> V_333 ;
F_297 ( V_314 , L_59
L_60 ,
V_324 , V_322 , V_326 ,
V_327 , V_328 , V_329 , V_330 ,
V_331 , V_332 ) ;
}
{
unsigned long V_334 = F_298 ( & V_16 -> V_334 ) ;
unsigned long V_335 = F_298 ( & V_16 -> V_335 ) ;
unsigned long V_336 = F_298 ( & V_16 -> V_336 ) ;
unsigned long V_337 = F_298 ( & V_16 -> V_337 ) ;
F_297 ( V_314 , L_61 ,
V_334 , V_335 , V_336 , V_337 ) ;
}
#endif
F_290 ( V_314 , '\n' ) ;
return 0 ;
}
static T_11 F_299 ( struct V_338 * V_338 , const char T_12 * V_339 ,
T_2 V_340 , T_10 * V_341 )
{
char V_342 [ V_343 + 1 ] , * V_241 ;
int V_102 , V_97 , V_9 , V_242 ;
struct V_15 * V_16 ;
if ( V_340 > V_343 )
return - V_344 ;
if ( F_300 ( & V_342 , V_339 , V_340 ) )
return - V_345 ;
V_342 [ V_343 ] = '\0' ;
V_241 = strchr ( V_342 , ' ' ) ;
if ( ! V_241 )
return - V_344 ;
* V_241 = '\0' ;
V_241 ++ ;
if ( sscanf ( V_241 , L_62 , & V_102 , & V_97 , & V_9 ) != 3 )
return - V_344 ;
F_100 ( & V_133 ) ;
V_242 = - V_344 ;
F_90 (cachep, &cache_chain, next) {
if ( ! strcmp ( V_16 -> V_83 , V_342 ) ) {
if ( V_102 < 1 || V_97 < 1 ||
V_97 > V_102 || V_9 < 0 ) {
V_242 = 0 ;
} else {
V_242 = F_278 ( V_16 , V_102 ,
V_97 , V_9 ,
V_115 ) ;
}
break;
}
}
F_101 ( & V_133 ) ;
if ( V_242 >= 0 )
V_242 = V_340 ;
return V_242 ;
}
static int F_301 ( struct V_346 * V_346 , struct V_338 * V_338 )
{
return F_302 ( V_338 , & V_347 ) ;
}
static void * F_303 ( struct V_313 * V_314 , T_10 * V_315 )
{
F_100 ( & V_133 ) ;
return F_292 ( & V_175 , * V_315 ) ;
}
static inline int F_304 ( unsigned long * V_316 , unsigned long V_348 )
{
unsigned long * V_251 ;
int V_349 ;
if ( ! V_348 )
return 1 ;
V_349 = V_316 [ 1 ] ;
V_251 = V_316 + 2 ;
while ( V_349 ) {
int V_3 = V_349 / 2 ;
unsigned long * V_41 = V_251 + 2 * V_3 ;
if ( * V_41 == V_348 ) {
V_41 [ 1 ] ++ ;
return 1 ;
}
if ( * V_41 > V_348 ) {
V_349 = V_3 ;
} else {
V_251 = V_41 + 2 ;
V_349 -= V_3 + 1 ;
}
}
if ( ++ V_316 [ 1 ] == V_316 [ 0 ] )
return 0 ;
memmove ( V_251 + 2 , V_251 , V_316 [ 1 ] * 2 * sizeof( unsigned long ) - ( ( void * ) V_251 - ( void * ) V_316 ) ) ;
V_251 [ 0 ] = V_348 ;
V_251 [ 1 ] = 1 ;
return 1 ;
}
static void F_305 ( unsigned long * V_316 , struct V_15 * V_298 , struct V_29 * V_53 )
{
void * V_251 ;
int V_3 ;
if ( V_316 [ 0 ] == V_316 [ 1 ] )
return;
for ( V_3 = 0 , V_251 = V_53 -> V_33 ; V_3 < V_298 -> V_74 ; V_3 ++ , V_251 += V_298 -> V_21 ) {
if ( F_196 ( V_53 ) [ V_3 ] != V_272 )
continue;
if ( ! F_304 ( V_316 , ( unsigned long ) * F_12 ( V_298 , V_251 ) ) )
return;
}
}
static void F_306 ( struct V_313 * V_314 , unsigned long V_350 )
{
#ifdef F_307
unsigned long V_34 , V_1 ;
char V_351 [ V_352 ] , V_83 [ V_353 ] ;
if ( F_308 ( V_350 , & V_1 , & V_34 , V_351 , V_83 ) == 0 ) {
F_297 ( V_314 , L_63 , V_83 , V_34 , V_1 ) ;
if ( V_351 [ 0 ] )
F_297 ( V_314 , L_64 , V_351 ) ;
return;
}
#endif
F_297 ( V_314 , L_65 , ( void * ) V_350 ) ;
}
static int F_309 ( struct V_313 * V_314 , void * V_251 )
{
struct V_15 * V_16 = F_187 ( V_251 , struct V_15 , V_27 ) ;
struct V_29 * V_114 ;
struct V_4 * V_44 ;
const char * V_83 ;
unsigned long * V_316 = V_314 -> V_354 ;
int V_49 ;
int V_3 ;
if ( ! ( V_16 -> V_18 & V_20 ) )
return 0 ;
if ( ! ( V_16 -> V_18 & V_19 ) )
return 0 ;
V_316 [ 1 ] = 0 ;
F_32 (node) {
V_44 = V_16 -> V_46 [ V_49 ] ;
if ( ! V_44 )
continue;
F_178 () ;
F_91 ( & V_44 -> V_12 ) ;
F_90 (slabp, &l3->slabs_full, list)
F_305 ( V_316 , V_16 , V_114 ) ;
F_90 (slabp, &l3->slabs_partial, list)
F_305 ( V_316 , V_16 , V_114 ) ;
F_81 ( & V_44 -> V_12 ) ;
}
V_83 = V_16 -> V_83 ;
if ( V_316 [ 0 ] == V_316 [ 1 ] ) {
F_101 ( & V_133 ) ;
V_314 -> V_354 = F_279 ( V_316 [ 0 ] * 4 * sizeof( unsigned long ) , V_115 ) ;
if ( ! V_314 -> V_354 ) {
V_314 -> V_354 = V_316 ;
F_100 ( & V_133 ) ;
return - V_116 ;
}
* ( unsigned long * ) V_314 -> V_354 = V_316 [ 0 ] * 2 ;
F_74 ( V_316 ) ;
F_100 ( & V_133 ) ;
V_314 -> V_340 = V_314 -> V_1 ;
return 0 ;
}
for ( V_3 = 0 ; V_3 < V_316 [ 1 ] ; V_3 ++ ) {
F_297 ( V_314 , L_66 , V_83 , V_316 [ 2 * V_3 + 3 ] ) ;
F_306 ( V_314 , V_316 [ 2 * V_3 + 2 ] ) ;
F_290 ( V_314 , '\n' ) ;
}
return 0 ;
}
static int F_310 ( struct V_346 * V_346 , struct V_338 * V_338 )
{
unsigned long * V_316 = F_279 ( V_77 , V_115 ) ;
int V_144 = - V_116 ;
if ( V_316 ) {
V_144 = F_302 ( V_338 , & V_355 ) ;
if ( ! V_144 ) {
struct V_313 * V_314 = V_338 -> V_356 ;
* V_316 = V_77 / ( 2 * sizeof( unsigned long ) ) ;
V_314 -> V_354 = V_316 ;
V_316 = NULL ;
}
F_74 ( V_316 ) ;
}
return V_144 ;
}
static int T_6 F_311 ( void )
{
F_312 ( L_67 , V_357 | V_358 , NULL , & V_359 ) ;
#ifdef F_212
F_312 ( L_68 , 0 , NULL , & V_360 ) ;
#endif
return 0 ;
}
T_2 F_313 ( const void * V_17 )
{
F_10 ( ! V_17 ) ;
if ( F_40 ( V_17 == V_66 ) )
return 0 ;
return F_8 ( F_20 ( V_17 ) ) ;
}
